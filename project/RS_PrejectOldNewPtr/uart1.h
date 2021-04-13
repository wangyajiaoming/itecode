

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

#define Rs_NewOldprotocol_Shift		1    //=1新协议      =0旧协议

#define UartCommandLen 9
#define protocol_MaxLen 200
#define UI_WEDGET_MAXLEN	200
#define UI_AIR_MAXLEN		100
#define UI_Module_MAXLEN		200

#define AIR_MAXLEN				3


#define WEDGET_LEN_MAX		100	

//#define UI_NAME_MAXLEN		40

uint8  send_tempOrdehu_flag;				//发送温度和湿度标志
uint8  send_dimmer_relay_flag;				//发送调光滑杆亮度值标志

uint8 init_SYN_flag;
uint8 init_SYN_cnt;


#define RS485_EN_GPIO		30				//485通信使能引脚

ITUScene   theScene;

uint8 	send_dimmer_delay_cnt;				//发送调光延时

uint8  send_air_temp_flag;				//发送调光滑杆亮度值标志
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


unsigned char AllowReceiveTimeData_flag;	//允许接收主机下发的时分数据

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
	int tm_sec; /* 秒 – 取值区间为[0,59] */
	int tm_min; /* 分 - 取值区间为[0,59] */
	int tm_hour; /* 时 - 取值区间为[0,23] */
	int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] */
	int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
	int tm_year; /* 年份，其值等于实际年份减去1900 */
}my_clock;

my_clock  ri_clock;

uint8 clock_cnt;

typedef	struct _tag_protocol
{
	uint8	vMode;						//取FIFO数据，并判断是否符合协议的步骤。
									//如果符合，则把数据写到vPacket缓冲区
	uint8	vPoint;
	uint8	vPacket[protocol_MaxLen];	//从FIFO队列中取数据，组成符合协议的帧缓冲
	uint8	vTimerout;					//从接收到帧头开始，规定时间内要收完数据，
									//否则清掉状态重新接收帧头。
	uint8	vSendPack[protocol_MaxLen];	//串口发送数据缓冲区
}_ts_protocol;

_ts_protocol Uart0Protocol;

typedef struct rs_uiprotocol	//ui与日顺数据结构对应
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
	uint8 vModuleAddr;		//妯″潡涓婄殑鎷斿彿鍦板潃
	uint8 vModuleLoop;		//妯″潡涓婄殑鍥炶矾锛岃寖鍥?1锝?4
	uint8 vEventCmd;		//涓婅皟銆佷笅璋冦?佸惊鐜皟銆佸紑鍏崇瓑浜嬩欢
	uint8 vLightValue;		//0锝?100 涓绘満鏄寜鐧惧垎姣斿鐞嗘暟鎹?傛ā鍧楁寜200绾ф墽琛屻??
	uint8 vAdjustSpeed;		//鍙互鐢ㄦ潵璋冩暣閫熷害锛屽姛鑳藉悓RGBW涓?鏍枫??
	uint8 vKeepDat;			//鎵╁睍鐢?
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

}recModeType;	//根据串口环形缓冲区接收的数据，对比协议，一步一步执行。


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


typedef enum		//继电器模块地址
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

typedef enum			//调光模块地址
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

typedef enum			//调光模块地址
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

typedef enum			//模块端口号
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
