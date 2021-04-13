
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



#define 	IIC_CLK			28			//引脚定义
#define 	IIC_DAT			27

static ITULayer* airConditionLayer;
ITUScene   airScene;
ITUScene   theScene;


typedef unsigned char  uint8;
typedef unsigned char  uchar;
typedef unsigned int  uint;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  定义指令字                 //
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#define STATUS_REG_W 		0xE6   //
#define STATUS_REG_R 		0xE7   //
#define HOLD_MASTER_TEMP 	0xE3   //主机模式温度测量
#define HOLD_MASTER_RH   	0xE5   //主机模式湿度测量
#define NO_MASTER_TEMP 		0xF3   //非主机模式温度测量
#define NO_MASTER_RH   		0xF5   //非主机模式湿度测量
#define RESET_HTU21D  		0xFE   //软复位指令
  
#define ACK   		0
#define NACK  		1
 
#define HTU21D_ADDR_WRITE  	0x80//I2C写地址
#define HTU21D_ADDR_READ   	0x81//I2C读地址
 
#define GET_TEMP 	0
#define GET_RH   	1
//==================================================================================================
float HTU21D_humidity;
float HTU21D_temperature;
uint8 HTU21D_time;				//测量次数，如果读取错误，连续错误数次，则认为系统中不存在该传感器


uint8	vErrSTH21Sta_Read;			//读出错
uint8	vErrSTH21Sta_NoDevice;		//无器件

float 	AtRH;				//湿度值
float 	AtTEMP;				//温度值

float 	AtRH_bak;				//湿度值备份
float 	AtTEMP_bak;				//温度值备份

//ITUScene   theScene;

////////////////////////////////////////////////////////////////////////////////////////////////////
//                函数声明                       //
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
函数 HTU21D_init
功能 初始化连接HTU21D的引脚,sck为输出并置为1, data为输出并置为1
参数 无
返回 无
***************************************************************************************************/
void HTU21D_init(void)
{
	ithGpioSet(IIC_CLK);
	ithGpioSet(IIC_DAT)	;
	reset_HTU21D();
	delay_ms(15);//软复位需15ms
}
 
/****************************************************
函数 read_HTU21D_bit
功能 读取HTU21D数据线
参数 无
返回 引脚电平:1--高电平,0--低电平
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
函数 read_HTU21D_sck
功能 读取HTU21D时钟线
参数 无
返回 引脚电平:1--高电平,0--低电平
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
函数 start_HTU21D
功能 启动传输。SCL、SDA同为高，SDA跳变成低之后，SCL跳变成低
参数 无
返回 无
*****************************************************/
void start_HTU21D(void)
{
	ithGpioSetOut(IIC_DAT);

    //准备
	ithGpioSet(IIC_CLK);
    ithGpioSet(IIC_DAT)	;
    
    //开始
    delay_us(10);
    ithGpioClear(IIC_DAT);
    delay_us(20);
	ithGpioClear(IIC_CLK);
}
 
/***************************************************
函数 stop_HTU21D
功能 停止传输。SCL、SDA同为低，SCL跳变成高之后，SDA跳变成高
参数 无
返回 无
*****************************************************/
void stop_HTU21D(void)
{
	ithGpioSetOut(IIC_DAT);
    //准备
	ithGpioClear(IIC_CLK);
    ithGpioClear(IIC_DAT);
	//开始
    delay_us(10);
	ithGpioSet(IIC_CLK);
	delay_us(10);
	ithGpioSet(IIC_DAT)	;
}
 
/*****************************************************************
函数 write_byte_toHTU21D
功能 向HTU21D写入1字节数据
参数 value--写入值
返回 0--写入正确,1--写入错误
*****************************************************************/
char write_byte_toHTU21D( uchar value)
{
    uchar i;
	uchar vError;
	uchar data;
	vError=0;
	data=value;
	ithGpioSetOut(IIC_DAT);		//GPIO切为输出
	ithGpioSet(IIC_DAT);
	ithGpioClear(IIC_CLK);
	for(i=0;i<8;i++)
	{
   		//设置DATA
		if(data&0x80)		//先传输高位
		{
				ithGpioSet(IIC_DAT)	;//传输位为1
		}
		else
		{
				ithGpioClear(IIC_DAT);//传输位为0
		}
		delay_us(20);
    //发出时钟
		ithGpioSet(IIC_CLK);
		delay_us(10);
		ithGpioClear(IIC_CLK);
		//下一位
		data=data<<1;
	}
    //释放数据线,检查应答信号
    ithGpioSetIn(IIC_DAT);	//GPIO切为输入
    ithGpioSet(IIC_CLK);
    delay_us(10);
    vError=read_HTU21D_bit();
    ithGpioClear(IIC_CLK);
	return vError;
}
 
/*************************************************
函数 read_byte_formHTU21D
功能 读取一字节数据
参数 ack--应答参数
返回 读取字节
***************************************************/
uchar read_byte_formHTU21D( uchar ack )
{
    uchar i;
    uchar data=0;
	//释放数据线
    ithGpioClear(IIC_CLK);
    ithGpioSetIn(IIC_DAT);	//	切为输入
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
	ithGpioSetOut(IIC_DAT);	//需要mcu应答 切为输出
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
函数  reset_HTU21D
功能  传感器软复位
参数  无
返回  0--正确,1--错误
****************************************************/
char reset_HTU21D(void)
{
    uchar vError=0;
    start_HTU21D();
	vError = write_byte_toHTU21D( HTU21D_ADDR_WRITE);//发送I2C地址
	vError+=write_byte_toHTU21D( RESET_HTU21D);
	stop_HTU21D();
	return vError;
} 
/*============================================================  
 函数 check_crc_forHTU21D( uchar *data,uchar n )  
 功能 计算HTU21D输出数据的CRC校验值 
 参数 *data--参与校验的数据
      n--数据的字节数
 返回 1字节校验值 
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
函数 get_data_asNOHOLD
功能 启动非主机模式温湿度测量并提取数据,然后进行crc校验
参数 *p_value--测量数据存放位置
mode--测量模式：0，温度测量；1，湿度测量
返回 0-成功，1-失败
***************************************************************/
char get_data_asNOHOLD( uint *p_value,uchar mode)
{
	uchar i;
	uchar vError=0;
	uchar delay;
	uint  idata;
	uchar data[2];
	uchar crcByte;
 
	start_HTU21D(); //启动传输
	if(!write_byte_toHTU21D( HTU21D_ADDR_WRITE))//发送I2C地址,写
	{
		//printf("send addr sucess!\n");
		if( !mode )
		{ 
			vError+= write_byte_toHTU21D(NO_MASTER_TEMP);//测量温度
			
			delay=50;//温度测量时间44ms,最大50ms    SHT21是90ms
		}
		else
		{
			vError+= write_byte_toHTU21D(NO_MASTER_RH);//测量湿度
			delay=7;//湿度测量时间14ms,最大设置16msSHT21是30ms
		}

	}
    else
    {
   		stop_HTU21D();
        return 1;//错误
    }
    //每5ms查看一次测量是否结束
    for( i=0;i<delay;i++)
    {
   		start_HTU21D();
		if(write_byte_toHTU21D( HTU21D_ADDR_READ ))//发送I2C地址,读
		{
			//printf("send read addr sucess!\n");
			delay_ms(10);
		}
		else
		{
			//printf("text data sucess,please read data!\n");
			break;//测量过程结束即退出
		}
    }
    if(i<delay)//如果转换结束
    {
		data[0] = read_byte_formHTU21D( ACK ); //读高位字节
		data[1] = read_byte_formHTU21D( ACK ); //读低位字节
		crcByte= read_byte_formHTU21D( NACK );  //读CRC校验码
		stop_HTU21D();
		//printf("data read shift sucess\n");
		//printf("data[0] = %d\n",data[0]);
		//printf("data[1] = %d\n",data[1]);
		//printf("crcByte = %d\n",crcByte);

		if(crcByte==check_crc_forHTU21D( data,2) )
		{
			idata = data[0];//
			idata= (idata<<8)+data[1];
			*p_value=idata&0xFFFC;//屏蔽最后两位
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
函数 calculate_value
功能 计算温湿度值
参数 *p_RH--相对湿度存放位置
     *p_TEMP--温度存放位置
返回 无
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
		//湿度补偿
		if(*p_RH>100)	*p_RH = 100;
		if(*p_RH<0)		*p_RH = 0;
  
	//	osal_set_flag( HTU21D_YES_FLG);//记录系统中存在的传感器，在应用头文件中定义
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
				AtRH_bak = 60;	//湿度60%
				AtTEMP_bak = 25;	//温度25度
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



