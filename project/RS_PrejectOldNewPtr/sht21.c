
#include <time.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "ite/ith.h"
#include "ite/itp.h"
#include "openrtos/FreeRTOS.h"
#include "openrtos/queue.h"

#include "ite/itu.h"
#include "ctrlboard.h"
#include <string.h>
#include "uart1.h"
#include <assert.h>
#include <mqueue.h>
#include <stdlib.h>
#include "scene.h"



#define 	IIC_CLK			28			//���Ŷ���
#define 	IIC_DAT			27

static ITULayer* airConditionLayer;
ITUScene   airScene;
ITUScene   theScene;


typedef unsigned char  uint8;
typedef unsigned char  uchar;
typedef unsigned int  uint;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ����ָ����                 //
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#define STATUS_REG_W 		0xE6   //
#define STATUS_REG_R 		0xE7   //
#define HOLD_MASTER_TEMP 	0xE3   //����ģʽ�¶Ȳ���
#define HOLD_MASTER_RH   	0xE5   //����ģʽʪ�Ȳ���
#define NO_MASTER_TEMP 		0xF3   //������ģʽ�¶Ȳ���
#define NO_MASTER_RH   		0xF5   //������ģʽʪ�Ȳ���
#define RESET_HTU21D  		0xFE   //��λָ��
  
#define ACK   		0
#define NACK  		1
 
#define HTU21D_ADDR_WRITE  	0x80//I2Cд��ַ
#define HTU21D_ADDR_READ   	0x81//I2C����ַ
 
#define GET_TEMP 	0
#define GET_RH   	1
//==================================================================================================
float HTU21D_humidity;
float HTU21D_temperature;
uint8 HTU21D_time;				//���������������ȡ���������������Σ�����Ϊϵͳ�в����ڸô�����


uint8	vErrSTH21Sta_Read;			//������
uint8	vErrSTH21Sta_NoDevice;		//������

float 	AtRH;				//ʪ��ֵ
float 	AtTEMP;				//�¶�ֵ

float 	AtRH_bak;				//ʪ��ֵ����
float 	AtTEMP_bak;				//�¶�ֵ����

//ITUScene   theScene;

////////////////////////////////////////////////////////////////////////////////////////////////////
//                ��������                       //
////////////////////////////////////////////////////////////////////////////////////////////////////
uchar read_HTU21D_bit( void);
char write_byte_toHTU21D( uchar value);
void start_HTU21D(void);
void communicate_reset(void);
char reset_HTU21D(void);
void HTU21D_measure(float *p_RH ,float *p_TEMP);



volatile int delay_cnt1 = 0;
static void delay(int count)
{
    int i;
    ithEnterCritical();
    for (i = 0; i<count; i++)
        delay_cnt1++;
    ithExitCritical();
}

static void delay_us(int cout)
{
    int i, j;
    //ithEnterCritical();
    for (i = 0; i < cout; i++)
    {
        for (j = 0; j < 25; j++)
        {
            delay_cnt1++;
        }
    }
    delay_cnt1 = 0;
    //ithExitCritical();
}

static void delay_ms(int cout)
{
    int i, j;
    //ithEnterCritical();
    for (i = 0; i < cout; i++)
    {
        for (j = 0; j < 25000; j++)
        {
            delay_cnt1++;
        }
    }
    delay_cnt1 = 0;
    //ithExitCritical();
}

//===============================================================================================
	
/***************************************************************************************************
���� HTU21D_init
���� ��ʼ������HTU21D������,sckΪ�������Ϊ1, dataΪ�������Ϊ1
���� ��
���� ��
***************************************************************************************************/
void HTU21D_init(void)
{
	ithGpioSet(IIC_CLK);
	ithGpioSet(IIC_DAT)	;
	reset_HTU21D();
	delay_ms(15);//��λ��15ms
}
 
/****************************************************
���� read_HTU21D_bit
���� ��ȡHTU21D������
���� ��
���� ���ŵ�ƽ:1--�ߵ�ƽ,0--�͵�ƽ
****************************************************/
uchar read_HTU21D_bit( void)
{
	//if(HTU21D_DAT_PIN&(1<<HTU21D_DAT_BIT))
	if(ithGpioGet(IIC_DAT))
   		return 1;
	else
        return 0;
}
 
/****************************************************
���� read_HTU21D_sck
���� ��ȡHTU21Dʱ����
���� ��
���� ���ŵ�ƽ:1--�ߵ�ƽ,0--�͵�ƽ
****************************************************/
uchar read_HTU21D_sck( void)
{
	//if(HTU21D_SCK_PIN&(1<<HTU21D_SCK_BIT))
	if(ithGpioGet(IIC_CLK))
   		return 1;
	else
        return 0;
}
 
/***************************************************
���� start_HTU21D
���� �������䡣SCL��SDAͬΪ�ߣ�SDA����ɵ�֮��SCL����ɵ�
���� ��
���� ��
*****************************************************/
void start_HTU21D(void)
{
	ithGpioSetOut(IIC_DAT);

    //׼��
	ithGpioSet(IIC_CLK);
    ithGpioSet(IIC_DAT)	;
    
    //��ʼ
    delay_us(10);
    ithGpioClear(IIC_DAT);
    delay_us(20);
	ithGpioClear(IIC_CLK);
}
 
/***************************************************
���� stop_HTU21D
���� ֹͣ���䡣SCL��SDAͬΪ�ͣ�SCL����ɸ�֮��SDA����ɸ�
���� ��
���� ��
*****************************************************/
void stop_HTU21D(void)
{
	ithGpioSetOut(IIC_DAT);
    //׼��
	ithGpioClear(IIC_CLK);
    ithGpioClear(IIC_DAT);
	//��ʼ
    delay_us(10);
	ithGpioSet(IIC_CLK);
	delay_us(10);
	ithGpioSet(IIC_DAT)	;
}
 
/*****************************************************************
���� write_byte_toHTU21D
���� ��HTU21Dд��1�ֽ�����
���� value--д��ֵ
���� 0--д����ȷ,1--д�����
*****************************************************************/
char write_byte_toHTU21D( uchar value)
{
    uchar i;
	uchar vError;
	uchar data;
	vError=0;
	data=value;
	ithGpioSetOut(IIC_DAT);		//GPIO��Ϊ���
	ithGpioSet(IIC_DAT);
	ithGpioClear(IIC_CLK);
	for(i=0;i<8;i++)
	{
   		//����DATA
		if(data&0x80)		//�ȴ����λ
		{
				ithGpioSet(IIC_DAT)	;//����λΪ1
		}
		else
		{
				ithGpioClear(IIC_DAT);//����λΪ0
		}
		delay_us(20);
    //����ʱ��
		ithGpioSet(IIC_CLK);
		delay_us(10);
		ithGpioClear(IIC_CLK);
		//��һλ
		data=data<<1;
	}
    //�ͷ�������,���Ӧ���ź�
    ithGpioSetIn(IIC_DAT);	//GPIO��Ϊ����
    ithGpioSet(IIC_CLK);
    delay_us(10);
    vError=read_HTU21D_bit();
    ithGpioClear(IIC_CLK);
	return vError;
}
 
/*************************************************
���� read_byte_formHTU21D
���� ��ȡһ�ֽ�����
���� ack--Ӧ�����
���� ��ȡ�ֽ�
***************************************************/
uchar read_byte_formHTU21D( uchar ack )
{
    uchar i;
    uchar data=0;
	//�ͷ�������
    ithGpioClear(IIC_CLK);
    ithGpioSetIn(IIC_DAT);	//	��Ϊ����
	for(i=0;i<8;i++)
	{
   		delay_us(20);
   		ithGpioSet(IIC_CLK);
		delay_us(10);
		if(read_HTU21D_bit())
		{
				data|=1<<(7-i);
		}
      ithGpioClear(IIC_CLK);  
  }
	ithGpioSetOut(IIC_DAT);	//��ҪmcuӦ�� ��Ϊ���
	delay_us(20);
  if(ack )
	{
   		ithGpioSet(IIC_DAT)	;
	}
  else
	{
		ithGpioClear(IIC_DAT);
	}
  	delay_us(20);
	ithGpioSet(IIC_CLK);
	delay_us(10);
	ithGpioClear(IIC_CLK);
	
    return data;
}
 
 
/***************************************************************************************************
����  reset_HTU21D
����  ��������λ
����  ��
����  0--��ȷ,1--����
****************************************************/
char reset_HTU21D(void)
{
    uchar vError=0;
    start_HTU21D();
	vError = write_byte_toHTU21D( HTU21D_ADDR_WRITE);//����I2C��ַ
	vError+=write_byte_toHTU21D( RESET_HTU21D);
	stop_HTU21D();
	return vError;
} 
/*============================================================  
 ���� check_crc_forHTU21D( uchar *data,uchar n )  
 ���� ����HTU21D������ݵ�CRCУ��ֵ 
 ���� *data--����У�������
      n--���ݵ��ֽ���
 ���� 1�ֽ�У��ֵ 
 *************************************************************/ 
#define POLYNOMIAL 0x131   //P(x)=x^8+x^5+x^4+1 = 100110001
 
uchar check_crc_forHTU21D( uchar *data,uchar n ) 
{  
    uchar crc = 0; 
    uchar i,j;  
    for (i=0;i<n;i++) 
    { 
        crc^=*(data+i);   
        for(j=8;j>0;j--)   
        { 
            if(crc&0x80) 
           	crc=(crc<<1)^POLYNOMIAL;     
			else 
   			crc=(crc<<1);   
		} 
	}  
	//printf("crc = %d\n",crc);
	return crc;
}    
 
/***************************************************************************************************
���� get_data_asNOHOLD
���� ����������ģʽ��ʪ�Ȳ�������ȡ����,Ȼ�����crcУ��
���� *p_value--�������ݴ��λ��
mode--����ģʽ��0���¶Ȳ�����1��ʪ�Ȳ���
���� 0-�ɹ���1-ʧ��
***************************************************************/
char get_data_asNOHOLD( uint *p_value,uchar mode)
{
	uchar i;
	uchar vError=0;
	uchar delay;
	uint  idata;
	uchar data[2];
	uchar crcByte;
 
	start_HTU21D(); //��������
	if(!write_byte_toHTU21D( HTU21D_ADDR_WRITE))//����I2C��ַ,д
	{
		//printf("send addr sucess!\n");
		if( !mode )
		{ 
			vError+= write_byte_toHTU21D(NO_MASTER_TEMP);//�����¶�
			
			delay=50;//�¶Ȳ���ʱ��44ms,���50ms    SHT21��90ms
		}
		else
		{
			vError+= write_byte_toHTU21D(NO_MASTER_RH);//����ʪ��
			delay=7;//ʪ�Ȳ���ʱ��14ms,�������16msSHT21��30ms
		}

	}
    else
    {
   		stop_HTU21D();
        return 1;//����
    }
    //ÿ5ms�鿴һ�β����Ƿ����
    for( i=0;i<delay;i++)
    {
   		start_HTU21D();
		if(write_byte_toHTU21D( HTU21D_ADDR_READ ))//����I2C��ַ,��
		{
			//printf("send read addr sucess!\n");
			delay_ms(10);
		}
		else
		{
			//printf("text data sucess,please read data!\n");
			break;//�������̽������˳�
		}
    }
    if(i<delay)//���ת������
    {
		data[0] = read_byte_formHTU21D( ACK ); //����λ�ֽ�
		data[1] = read_byte_formHTU21D( ACK ); //����λ�ֽ�
		crcByte= read_byte_formHTU21D( NACK );  //��CRCУ����
		stop_HTU21D();
		//printf("data read shift sucess\n");
		//printf("data[0] = %d\n",data[0]);
		//printf("data[1] = %d\n",data[1]);
		//printf("crcByte = %d\n",crcByte);

		if(crcByte==check_crc_forHTU21D( data,2) )
		{
			idata = data[0];//
			idata= (idata<<8)+data[1];
			*p_value=idata&0xFFFC;//���������λ
		}
		else
        vError=1;
	}
    else
    {
   		stop_HTU21D();
        vError=1;
    }
    return vError;
} 
/***************************************************************************************************
���� calculate_value
���� ������ʪ��ֵ
���� *p_RH--���ʪ�ȴ��λ��
     *p_TEMP--�¶ȴ��λ��
���� ��
***************************************************************************************************/
 
void HTU21D_measure(float *p_RH ,float *p_TEMP)
{ 
	uint data_RH;
	uint data_TEMP;
	uchar vError=0,i;
	vError=get_data_asNOHOLD( &data_RH,GET_RH);
	vError+=get_data_asNOHOLD( &data_TEMP,GET_TEMP);
	//for(i=0;i<10;i++)
	{
	//	printf("vError = %d\n",vError);
	}
	if(!vError)
	{
		*p_RH = (float)data_RH*125/65536-6;//
		*p_TEMP = (float)data_TEMP*175.72/65536-46.85;
		//ʪ�Ȳ���
		if(*p_RH>100)	*p_RH = 100;
		if(*p_RH<0)		*p_RH = 0;
  
	//	osal_set_flag( HTU21D_YES_FLG);//��¼ϵͳ�д��ڵĴ���������Ӧ��ͷ�ļ��ж���
		HTU21D_time=0;   
		
		vErrSTH21Sta_Read=false;
		vErrSTH21Sta_NoDevice=false;

	}
	else
	{  
		vErrSTH21Sta_Read=true;
		if(++HTU21D_time>5)
		{
		//		osal_clear_flag( HTU21D_YES_FLG);
				vErrSTH21Sta_NoDevice=true;
		}
	}  
}
//**************************************************************************************************

void* HTU21D_Fun(void* arg)
{
	uint8 vTmp1,vTmp2;
	uchar buf[20];
	uchar *ptr;
	ithGpioSetOut(IIC_CLK);
	while(1)
	{
		//ithEnterCritical();
		
		HTU21D_measure(&AtRH,&AtTEMP);
		if(vErrSTH21Sta_Read==true)
		{
			if(vErrSTH21Sta_NoDevice==true)
			{
				AtRH_bak = 60;	//ʪ��60%
				AtTEMP_bak = 25;	//�¶�25��
			}
		}
		else
		{
			printf("Measure Sucess !\n");
			if(AtRH_bak != AtRH)
			{
				AtRH_bak = AtRH;
				printf("get AtRH_bak = %2f\n",AtRH_bak);
				send_tempOrdehu_flag = true;
			}

			if(AtTEMP_bak != AtTEMP)
			{
				AtTEMP_bak = AtTEMP;
				printf("get AtTEMP_bak = %2f\n",AtTEMP_bak);
				send_tempOrdehu_flag = true;
			}
	
		}
		
		//ithExitCritical();

		sleep(30);
	}
}


void HTU21D_Test_Init(void)
{

	pthread_t task;
	
	pthread_create(&task, NULL, HTU21D_Fun, NULL);
}

void ExternaAirDisplayInit(void)
{
    airConditionLayer = ituSceneFindWidget(&airScene, "airConditionLayer");
    assert(airConditionLayer);

}



