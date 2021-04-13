

#ifndef _UART1_H
#define _UART1_H

#include "ctrlboard.h"
#include "ite/itp.h"
#include "ite/ith.h"

#include "openrtos/FreeRTOS.h"
#include "openrtos/queue.h"

#include "ite/itu.h"

#include <semaphore.h>


typedef unsigned char uint8;
typedef unsigned char u8;
typedef unsigned short int uint16;
//typedef extern  Ext_uart1;

#define Rs_NewOldprotocol_Shift		1    //=1��Э��      =0��Э��

#define UartCommandLen 9
#define protocol_MaxLen 200
#define UI_WEDGET_MAXLEN	200
#define UI_AIR_MAXLEN		100
#define UI_Module_MAXLEN		200

#define AIR_MAXLEN				3


#define WEDGET_LEN_MAX		100	

//#define UI_NAME_MAXLEN		40

uint8  send_tempOrdehu_flag;				//�����¶Ⱥ�ʪ�ȱ�־
uint8  send_dimmer_relay_flag;				//���͵��⻬������ֵ��־

uint8 init_SYN_flag;
uint8 init_SYN_cnt;


#define RS485_EN_GPIO		30				//485ͨ��ʹ������

ITUScene   theScene;

uint8 	send_dimmer_delay_cnt;				//���͵�����ʱ

uint8  send_air_temp_flag;				//���͵��⻬������ֵ��־
uint8  send_air_temp_cnt;


static ITUText *fastTempText = 0;

uint16 value1,value1_bak;

uint8 tx_Oldrelay_value;

#if 1
#ifdef CFG_DBG_UART0
#undef CFG_UART0_INTR
#undef CFG_UART0_DMA
#undef CFG_UART0_FIFO
#undef CFG_UART0_ENABLE
#endif

#ifdef CFG_DBG_UART1
#undef CFG_UART1_INTR
#undef CFG_UART1_DMA
#undef CFG_UART1_FIFO
#undef CFG_UART1_ENABLE
#endif

#if defined(CFG_UART0_INTR) || defined(CFG_UART1_INTR)\
	|| defined(CFG_UART2_INTR) || defined(CFG_UART3_INTR)\
	|| defined(CFG_UART4_INTR) || defined(CFG_UART5_INTR)
#define TEST_INTR_MODE
#endif

#if defined(CFG_UART0_DMA) || defined(CFG_UART1_DMA)\
	|| defined(CFG_UART2_DMA) || defined(CFG_UART3_DMA)\
	|| defined(CFG_UART4_DMA) || defined(CFG_UART5_DMA)
#define TEST_DMA_MODE
#endif

#if defined(CFG_UART0_FIFO) || defined(CFG_UART1_FIFO)\
	|| defined(CFG_UART2_FIFO) || defined(CFG_UART3_FIFO)\
	|| defined(CFG_UART4_FIFO) || defined(CFG_UART5_FIFO)
#define TEST_FIFO_MODE
#endif


#if defined(CFG_UART1_ENABLE)
#define UART1_PORT       ITP_DEVICE_UART1
#define UART1_DEVICE     itpDeviceUart1
#define UART1_BAUDRATE   CFG_UART1_BAUDRATE
#define UART1_GPIO_RX    CFG_GPIO_UART1_RX

#endif

#else

#endif


#define FrameStartByte       	0xAA
#define FrameStopByte			0x0D

#define FrameCmd				0x22
#define FrameLen				0x06


#define Relay_MAX				20
#define Air_MAX					3
#define Dimmer_Module_MAX		10



char sendbuf[10];

uint8  CH4094[Relay_MAX];
uint8  CH4094_bak[Relay_MAX];


unsigned char AllowReceiveTimeData_flag;	//������������·���ʱ������

static ITUCheckBox* lightReadingCheckBox;
static ITUCheckBox* lightNightCheckBox;

typedef enum GET_UART_COMMAND_STATE_TAG
{
    GET_HEADER,
	GET_CMD,
    GET_LENGTH,
    GET_PAYLOAD,
    GET_CHECKSUM,
} GET_UART_COMMAND_STATE;

static sem_t UartSem;

static sem_t Uart_Tx_Sem;

typedef struct _tag_RingBuf
{
	unsigned int read_index;
	unsigned int write_index;
	unsigned int buffer_size;
	
	uint8 *buf;

}r_fifo;

r_fifo rb;
uint8 mybuff[1024];
uint8 uart1_rvbuf[1024];

typedef  struct uart_st
{
	unsigned char send_Relaycmd_flag;
	unsigned char send_Aircmd_flag;
	
	
	unsigned char  uart_receive_flag;
	unsigned char  uart_send_flag;

	unsigned int   tx_interval;
	unsigned int   tx_outtime;
	unsigned int   rx_outtime;
}uart_st;

uart_st s_uart;

typedef struct _tag_newprotocol
{
	uint8 vCmd;
	uint8 vLen;
	uint8 vAddr;
	uint8 vType;
	uint8 vPort_L;
	uint8 vPort_H;
	uint8 vData_L;
	uint8 vData_H;
}newpro;

newpro s_newpro;

typedef struct _tag_clock {
	int tm_sec; /* �� �C ȡֵ����Ϊ[0,59] */
	int tm_min; /* �� - ȡֵ����Ϊ[0,59] */
	int tm_hour; /* ʱ - ȡֵ����Ϊ[0,23] */
	int tm_mday; /* һ�����е����� - ȡֵ����Ϊ[1,31] */
	int tm_mon; /* �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11] */
	int tm_year; /* ��ݣ���ֵ����ʵ����ݼ�ȥ1900 */
}my_clock;

my_clock  ri_clock;

uint8 clock_cnt;

typedef	struct _tag_protocol
{
	uint8	vMode;						//ȡFIFO���ݣ����ж��Ƿ����Э��Ĳ��衣
									//������ϣ��������д��vPacket������
	uint8	vPoint;
	uint8	vPacket[protocol_MaxLen];	//��FIFO������ȡ���ݣ���ɷ���Э���֡����
	uint8	vTimerout;					//�ӽ��յ�֡ͷ��ʼ���涨ʱ����Ҫ�������ݣ�
									//�������״̬���½���֡ͷ��
	uint8	vSendPack[protocol_MaxLen];	//���ڷ������ݻ�����
}_ts_protocol;

_ts_protocol Uart0Protocol;

typedef struct rs_uiprotocol	//ui����˳���ݽṹ��Ӧ
{
	uint8 m_type;
	uint8 m_addr;
	uint16 port;
	char * ui_name;
	char  ui_type;
}rs_uitype;

const rs_uitype relay[UI_WEDGET_MAXLEN];

typedef struct rs_NewAir_st
{
	uint8 oNOFF;
	uint8 vwind;
	uint8 setTemprature;
	uint8 setTemprature_bak;
}_rs_NewAir;

_rs_NewAir rs_NewAir[AIR_MAXLEN];


#if !Rs_NewOldprotocol_Shift

typedef struct rs_air_st
{
	uint8 setTemprature;
	uint8 fasttemprature;
	uint8 wind;
	uint8 wind_bak;
	uint8 season;
	
	
}rs_air_;

typedef struct rs_uart_air_st
{
	uint8 id;
	rs_air_ air[AIR_MAXLEN];
	rs_air_ air_bak[AIR_MAXLEN];
}rs_uart_air;

rs_uart_air sys_air;

typedef struct rs_uart_dimmer_st
{
	uint8 id;
	uint8 cmd;
	uint8 value;
}rs_uart_dimmer;
	
rs_uart_dimmer s_uart_dim;

#endif

typedef struct rs_uiModule_st
{
	uint8 m_type;
	uint8 m_addr;
	uint16 port;
	char * ui_name_Para1;
	char * ui_name_Para2;
	char * ui_name_Para3;
	char * ui_name_Para4;
	char * ui_name_Para5;
	char * ui_name_txt;
}rs_ModuleUI;

const rs_ModuleUI ModuleUI_tmp[UI_Module_MAXLEN];



typedef	struct _tag_EXT_Dimmer_Type
{
	uint8 vModuleAddr;		//模块上的拔号地址
	uint8 vModuleLoop;		//模块上的回路，范�?1�?4
	uint8 vEventCmd;		//上调、下调�?�循环调、开关等事件
	uint8 vLightValue;		//0�?100 主机是按百分比处理数据�?�模块按200级执行�??
	uint8 vAdjustSpeed;		//可以用来调整速度，功能同RGBW�?样�??
	uint8 vKeepDat;			//扩展�?
}EXT_Dimmer_Type;




typedef	enum
{
	recModeClear = 0x00,
	recMode1,
	recMode2,
	recMode3,
	recMode4,
	recMode5,
	recMode6,
	recMode7,
	recMode8,
	recMode9,

}recModeType;	//���ݴ��ڻ��λ��������յ����ݣ��Ա�Э�飬һ��һ��ִ�С�


typedef struct _tag_rs_protocol
{
	uint16 RiTypeaddr;
	uint16 ModuledPort;
	uint8* UiName;
	uint16 UiType;
	
}rs_protocol;


typedef enum
{
	rs_panle = 0x02,
	rs_relay = 0x04,
	rs_dimmer= 0x06,
	rs_air	 = 0x07,
	rs_floorheat = 0x0A,
}modeltype;


typedef enum		//�̵���ģ���ַ
{
//	extModlue00	= 0x00,
	extModlue01	= 0x15,
	extModlue02,
	extModlue03,
	extModlue04,
	extModlue05,
	extModlue06,
	extModlue07,
	extModlue08,
	extModlue09,
	extModlue10,
	extModlue11,
	extModlue12,
	extModlue13,
	extModlue14,
	extModlue15,
	extModlue16,
}Event_extModlue;

typedef enum			//����ģ���ַ
{
//	extModlue00	= 0x00,
	dimModlue01	= 0x01,
	dimModlue02,
	dimModlue03,
	dimModlue04,
	dimModlue05,
	dimModlue06,
	dimModlue07,
	dimModlue08,
	dimModlue09,
	dimModlue10,
	dimModlue11,
	dimModlue12,
	dimModlue13,
	dimModlue14,
	dimModlue15,
	dimModlue16,
}Event_dimModlue;

typedef enum			//����ģ���ַ
{
//	extModlue00	= 0x00,
	panelModlue01	= 0x01,
	panelModlue02,
	panelModlue03,
	panelModlue04,
	panelModlue05,
	panelModlue06,
	panelModlue07,
	panelModlue08,
	panelModlue09,
	panelModlue10,
	panelModlue11,
	panelModlue12,
	panelModlue13,
	panelModlue14,
	panelModlue15,
	panelModlue16,
}Event_panelModlue;

typedef enum			//ģ��˿ں�
{
	extKey01 = 0x01,
	extKey02,
	extKey03,
	extKey04,
	extKey05,
	extKey06,
	extKey07,
	extKey08,
	extKey09,
	extKey10,
	extKey11,
	extKey12,
	extKey13,
	extKey14,
	extKey15,
	extKey16,
}Event_extKey;	

extern void Uart1_Tx_Dimmer(void);
extern uint8 CheckSum_XOR(uint8 *p,int len);
extern void Uart1_Tx_relay(void);
extern void Uart1_Tx_Air_relay(void);
extern void Uart1_Tx_Air1_relay(void);



void Display_Temp_Dehu(uint8* name,uint8 mode );

void ExternalUart1ProcessInit(void);
int ExternalUart1Receive(ExternalEvent* ev);
int ExternalUart1Send(ExternalEvent* ev);
void ExternalUart1Exit(void);


#endif	/*_UART1_H*/
