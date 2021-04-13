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
#include<sys/time.h>

#define UART_MAX_INTERVALTIME 5			//5*5ms


static ITULayer* lightLayer;


#define EXT_MAX_UART1_QUEUE_SIZE      8
#define MAX_UART1_OUTDATA_SIZE        64

static mqd_t extuart1InQueue = -1;
static mqd_t extuart1OutQueue = -1;
static bool extuartQuit;


#if defined(TEST_INTR_MODE)
static sem_t UartSemIntr;
#elif defined(TEST_DMA_MODE)
static sem_t UartSemDma;
#elif defined(TEST_FIFO_MODE)
static sem_t UartSemFifo;
#endif

const rs_ModuleUI ModuleUI_tmp[]=
{
	//rs_type   		rs_addr     rs_port		tmp_para1					tmp_para2				tmp_para3					tmp_para4	tmp_para5	tmp_txt_name
//---------------------------------------------------------继电器-------------------------------------------------------------------------------

	rs_relay,			0x01,		0x0001, 	"relayONOFFCheckBox1-1",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x01,		0x0002, 	"relayONOFFCheckBox1-2",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x01,		0x0003, 	"relayONOFFCheckBox1-3",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x01,		0x0004, 	"relayONOFFCheckBox1-4",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x01,		0x0005, 	"relayONOFFCheckBox1-5",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x01,		0x0006, 	"relayONOFFCheckBox1-6",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x01,		0x0007, 	"relayONOFFCheckBox1-7",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x01,		0x0008, 	"relayONOFFCheckBox1-8",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",

	rs_relay,			0x02,		0x0001, 	"relayONOFFCheckBox2-1",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x02,		0x0002, 	"relayONOFFCheckBox2-2",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x02,		0x0003, 	"relayONOFFCheckBox2-3",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x02,		0x0004, 	"relayONOFFCheckBox2-4",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x02,		0x0005, 	"relayONOFFCheckBox2-5",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x02,		0x0006, 	"relayONOFFCheckBox2-6",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x02,		0x0007, 	"relayONOFFCheckBox2-7",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x02,		0x0008, 	"relayONOFFCheckBox2-8",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",

	rs_relay,			0x03,		0x0001, 	"relayONOFFCheckBox3-1",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x03,		0x0002, 	"relayONOFFCheckBox3-2",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x03,		0x0003, 	"relayONOFFCheckBox3-3",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x03,		0x0004, 	"relayONOFFCheckBox3-4",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x03,		0x0005, 	"relayONOFFCheckBox3-5",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x03,		0x0006, 	"relayONOFFCheckBox3-6",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x03,		0x0007, 	"relayONOFFCheckBox3-7",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x03,		0x0008, 	"relayONOFFCheckBox3-8",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",

	rs_relay,			0x06,		0x0001, 	"relayONOFFCheckBox6-1",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x06,		0x0002, 	"relayONOFFCheckBox6-2",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x06,		0x0003, 	"relayONOFFCheckBox6-3",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x06,		0x0004, 	"relayONOFFCheckBox6-4",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x06,		0x0005, 	"relayONOFFCheckBox6-5",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x06,		0x0006, 	"relayONOFFCheckBox6-6",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x06,		0x0007, 	"relayONOFFCheckBox6-7",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x06,		0x0008, 	"relayONOFFCheckBox6-8",	"NULL", 				"NULL", 		"NULL", 	"NULL", 	"NULL",

	
	rs_relay,			0x07,		0x0001, 	"relayONOFFCheckBox7-1",	"windowOpen", 			"pushwindowCheckBox1", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x07,		0x0002, 	"relayONOFFCheckBox7-2",	"windowClose", 			"pushwindowCheckBox1", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x07,		0x0003, 	"relayONOFFCheckBox7-3",	"windowOpen", 			"pushwindowCheckBox2", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x07,		0x0004, 	"relayONOFFCheckBox7-4",	"windowClose", 			"pushwindowCheckBox2", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x07,		0x0005, 	"relayONOFFCheckBox7-5",	"windowOpen", 			"pushwindowCheckBox3", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x07,		0x0006, 	"relayONOFFCheckBox7-6",	"windowClose",			"pushwindowCheckBox3", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x07,		0x0007, 	"relayONOFFCheckBox7-7",	"windowOpen", 			"pushwindowCheckBox4", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x07,		0x0008, 	"relayONOFFCheckBox7-8",	"windowClose",			"pushwindowCheckBox4", 		"NULL", 	"NULL", 	"NULL",

	
	rs_relay,			0x08,		0x0001, 	"relayONOFFCheckBox8-1",	"windowOpen", 			"pushwindowCheckBox5", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x08,		0x0002, 	"relayONOFFCheckBox8-2",	"windowClose", 			"pushwindowCheckBox5", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x08,		0x0003, 	"relayONOFFCheckBox8-3",	"windowOpen", 			"pushwindowCheckBox6", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x08,		0x0004, 	"relayONOFFCheckBox8-4",	"windowClose", 			"pushwindowCheckBox6", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x08,		0x0005, 	"relayONOFFCheckBox8-5",	"windowOpen", 			"pushwindowCheckBox7", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x08,		0x0006, 	"relayONOFFCheckBox8-6",	"windowClose",			"pushwindowCheckBox7", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x08,		0x0007, 	"relayONOFFCheckBox8-7",	"NULL", 			"NULL", 		"NULL", 	"NULL", 	"NULL",
	rs_relay,			0x08,		0x0008, 	"relayONOFFCheckBox8-8",	"NULL",				"NULL", 		"NULL", 	"NULL", 	"NULL",
//-----------------------------------------------------------窗帘---------------------------------------------------------------------------------
	#if Rs_NewOldprotocol_Shift
	rs_panle,			0xFD,		0x0001, 	"windowOpenCheckBox1",	"NULL",			"pushwindowCheckBox3",		"NULL", 	"NULL", 	"NULL",
	rs_panle,			0xFD,		0x0002, 	"windowStopCheckBox1",	"NULL",			"NULL",		"NULL", 	"NULL", 	"NULL",
	rs_panle,			0xFD,		0x0003, 	"windowCloseCheckBox1",	"NULL",			"pushwindowCheckBox3",		"NULL", 	"NULL", 	"NULL",

	rs_panle,			0xFD,		0x0004, 	"windowOpenCheckBox2",	"NULL", 		"pushwindowCheckBox4", 	"NULL", 	"NULL", 	"NULL",
	rs_panle,			0xFD,		0x0005, 	"windowStopCheckBox2",	"NULL", 		"NULL", 	"NULL", 	"NULL", 	"NULL",
	rs_panle,			0xFD,		0x0006, 	"windowCloseCheckBox2", "NULL", 		"pushwindowCheckBox4", 	"NULL", 	"NULL", 	"NULL",
	#endif
	//----------------------------------------------------------调光------------------------------------------------------------------------------
	
	rs_dimmer, 			0x01,		0x6001, 	"dimmerONOFFCheckBox1-1", 	"dimmerTrackBar1-1", 	"dimmerProgressBar1-1", 	"NULL", 	"NULL", 	"dimmerSetTmpText1-1",
	rs_dimmer, 			0x01,		0x6002, 	"dimmerONOFFCheckBox1-2", 	"dimmerTrackBar1-2", 	"dimmerProgressBar1-2", 	"NULL", 	"NULL", 	"dimmerSetTmpText1-2",
	rs_dimmer, 			0x01,		0x6003, 	"dimmerONOFFCheckBox1-3", 	"dimmerTrackBar1-3", 	"dimmerProgressBar1-3", 	"NULL", 	"NULL", 	"dimmerSetTmpText1-3",
	rs_dimmer, 			0x01,		0x6004, 	"dimmerONOFFCheckBox1-4", 	"dimmerTrackBar1-4", 	"dimmerProgressBar1-4", 	"NULL", 	"NULL", 	"dimmerSetTmpText1-4",

	rs_dimmer,			0x02,		0x6001, 	"dimmerONOFFCheckBox2-1", 	"dimmerTrackBar2-1",	"dimmerProgressBar2-1",		"NULL", 	"NULL", 	"dimmerSetTmpText2-1",
	rs_dimmer,			0x02,		0x6002, 	"dimmerONOFFCheckBox2-2", 	"dimmerTrackBar2-2",	"dimmerProgressBar2-2",		"NULL", 	"NULL", 	"dimmerSetTmpText2-2",
	rs_dimmer,			0x02,		0x6003, 	"dimmerONOFFCheckBox2-3", 	"dimmerTrackBar2-3",	"dimmerProgressBar2-3",		"NULL", 	"NULL", 	"dimmerSetTmpText2-3",
	rs_dimmer,			0x02,		0x6004, 	"dimmerONOFFCheckBox2-4", 	"dimmerTrackBar2-4",	"dimmerProgressBar2-4",		"NULL", 	"NULL", 	"dimmerSetTmpText2-4",

	rs_dimmer,			0x03,		0x6001, 	"dimmerONOFFCheckBox3-1", 	"dimmerTrackBar3-1",	"dimmerProgressBar3-1",		"NULL", 	"NULL", 	"dimmerSetTmpText3-1",
	rs_dimmer,			0x03,		0x6002, 	"dimmerONOFFCheckBox3-2", 	"dimmerTrackBar3-2",	"dimmerProgressBar3-2",		"NULL", 	"NULL", 	"dimmerSetTmpText3-2",
	rs_dimmer,			0x03,		0x6003, 	"dimmerONOFFCheckBox3-3", 	"dimmerTrackBar3-3",	"dimmerProgressBar3-3",		"NULL", 	"NULL", 	"dimmerSetTmpText3-3",
	rs_dimmer,			0x03,		0x6004, 	"dimmerONOFFCheckBox3-4", 	"dimmerTrackBar3-4",	"dimmerProgressBar3-4",		"NULL", 	"NULL", 	"dimmerSetTmpText3-4",

	rs_dimmer,			0x04,		0x6001, 	"dimmerONOFFCheckBox4-1", 	"dimmerTrackBar4-1",	"dimmerProgressBar4-1",		"NULL", 	"NULL", 	"dimmerSetTmpText4-1",
	rs_dimmer,			0x04,		0x6002, 	"dimmerONOFFCheckBox4-2", 	"dimmerTrackBar4-2",	"dimmerProgressBar4-2",		"NULL", 	"NULL", 	"dimmerSetTmpText4-2",
	rs_dimmer,			0x04,		0x6003, 	"dimmerONOFFCheckBox4-3", 	"dimmerTrackBar4-3",	"dimmerProgressBar4-3",		"NULL", 	"NULL", 	"dimmerSetTmpText4-3",
	rs_dimmer,			0x04,		0x6004, 	"dimmerONOFFCheckBox4-4", 	"dimmerTrackBar4-4",	"dimmerProgressBar4-4",		"NULL", 	"NULL", 	"dimmerSetTmpText4-4",
	
	rs_dimmer,			0x05,		0x6001, 	"dimmerONOFFCheckBox5-1", 	"dimmerTrackBar5-1",	"dimmerProgressBar5-1",		"NULL", 	"NULL", 	"dimmerSetTmpText5-1",
	rs_dimmer,			0x05,		0x6002, 	"dimmerONOFFCheckBox5-2", 	"dimmerTrackBar5-2",	"dimmerProgressBar5-2",		"NULL", 	"NULL", 	"dimmerSetTmpText5-2",
	rs_dimmer,			0x05,		0x6003, 	"dimmerONOFFCheckBox5-3", 	"dimmerTrackBar5-3",	"dimmerProgressBar5-3",		"NULL", 	"NULL", 	"dimmerSetTmpText5-3",
	rs_dimmer,			0x05,		0x6004, 	"dimmerONOFFCheckBox5-4", 	"dimmerTrackBar5-4",	"dimmerProgressBar5-4",		"NULL", 	"NULL", 	"dimmerSetTmpText5-4",
	
	rs_dimmer,			0x06,		0x6001, 	"dimmerONOFFCheckBox6-1", 	"dimmerTrackBar6-1",	"dimmerProgressBar6-1",		"NULL", 	"NULL", 	"dimmerSetTmpText6-1",
	rs_dimmer,			0x06,		0x6002, 	"dimmerONOFFCheckBox6-2", 	"dimmerTrackBar6-2",	"dimmerProgressBar6-2",		"NULL", 	"NULL", 	"dimmerSetTmpText6-2",
	rs_dimmer,			0x06,		0x6003, 	"dimmerONOFFCheckBox6-3", 	"dimmerTrackBar6-3",	"dimmerProgressBar6-3",		"NULL", 	"NULL", 	"dimmerSetTmpText6-3",
	rs_dimmer,			0x06,		0x6004, 	"dimmerONOFFCheckBox6-4", 	"dimmerTrackBar6-4",	"dimmerProgressBar6-4",		"NULL", 	"NULL", 	"dimmerSetTmpText6-4",
	
	rs_dimmer,			0x07,		0x6001, 	"dimmerONOFFCheckBox7-1", 	"dimmerTrackBar7-1",	"dimmerProgressBar7-1",		"NULL", 	"NULL", 	"dimmerSetTmpText7-1",
	rs_dimmer,			0x07,		0x6002, 	"dimmerONOFFCheckBox7-2", 	"dimmerTrackBar7-2",	"dimmerProgressBar7-2",		"NULL", 	"NULL", 	"dimmerSetTmpText7-2",
	rs_dimmer,			0x07,		0x6003, 	"dimmerONOFFCheckBox7-3", 	"dimmerTrackBar7-3",	"dimmerProgressBar7-3",		"NULL", 	"NULL", 	"dimmerSetTmpText7-3",
	rs_dimmer,			0x07,		0x6004, 	"dimmerONOFFCheckBox7-4", 	"dimmerTrackBar7-4",	"dimmerProgressBar7-4",		"NULL", 	"NULL", 	"dimmerSetTmpText7-4",
	
	rs_dimmer,			0x08,		0x6001, 	"dimmerONOFFCheckBox8-1", 	"dimmerTrackBar8-1",	"dimmerProgressBar8-1",		"NULL", 	"NULL", 	"dimmerSetTmpText8-1",
	rs_dimmer,			0x08,		0x6002, 	"dimmerONOFFCheckBox8-2", 	"dimmerTrackBar8-2",	"dimmerProgressBar8-2",		"NULL", 	"NULL", 	"dimmerSetTmpText8-2",
	rs_dimmer,			0x08,		0x6003, 	"dimmerONOFFCheckBox8-3", 	"dimmerTrackBar8-3",	"dimmerProgressBar8-3",		"NULL", 	"NULL", 	"dimmerSetTmpText8-3",
	rs_dimmer,			0x08,		0x6004, 	"dimmerONOFFCheckBox8-4", 	"dimmerTrackBar8-4",	"dimmerProgressBar8-4",		"NULL", 	"NULL", 	"dimmerSetTmpText8-4",
	
	rs_dimmer,			0x09,		0x6001, 	"dimmerONOFFCheckBox9-1", 	"dimmerTrackBar9-1",	"dimmerProgressBar9-1",		"NULL", 	"NULL", 	"dimmerSetTmpText9-1",
	rs_dimmer,			0x09,		0x6002, 	"dimmerONOFFCheckBox9-2", 	"dimmerTrackBar9-2",	"dimmerProgressBar9-2",		"NULL", 	"NULL", 	"dimmerSetTmpText9-2",
	rs_dimmer,			0x09,		0x6003, 	"dimmerONOFFCheckBox9-3", 	"dimmerTrackBar9-3",	"dimmerProgressBar9-3",		"NULL", 	"NULL", 	"dimmerSetTmpText9-3",
	rs_dimmer,			0x09,		0x6004, 	"dimmerONOFFCheckBox9-4", 	"dimmerTrackBar9-4",	"dimmerProgressBar9-4",		"NULL", 	"NULL", 	"dimmerSetTmpText9-4",
	
	rs_dimmer,			0x0A,		0x6001, 	"dimmerONOFFCheckBox10-1", 	"dimmerTrackBar10-1",	"dimmerProgressBar10-1",		"NULL", 	"NULL", 	"dimmerSetTmpText10-1",
	rs_dimmer,			0x0A,		0x6002, 	"dimmerONOFFCheckBox10-2", 	"dimmerTrackBar10-2",	"dimmerProgressBar10-2",		"NULL", 	"NULL", 	"dimmerSetTmpText10-2",
	rs_dimmer,			0x0A,		0x6003, 	"dimmerONOFFCheckBox10-3", 	"dimmerTrackBar10-3",	"dimmerProgressBar10-3",		"NULL", 	"NULL", 	"dimmerSetTmpText10-3",
	rs_dimmer,			0x0A,		0x6004, 	"dimmerONOFFCheckBox10-4", 	"dimmerTrackBar10-4",	"dimmerProgressBar10-4",		"NULL", 	"NULL", 	"dimmerSetTmpText10-4",
	

	//------------------------------------------------------------------空调---------------------------------------------------------------------------------------------
	rs_air,				0x01,		0x0001,		"airONOFFCheckBox1",	"airWindCheckBox1",		"NULL",					"NULL",		"NULL",		"airONOFFText1",
	rs_air,				0x01,		0x0004,		"setTmpAddButton1",		"setTmpSubButton1",		"setTmpMeter1",			"setTmpCircleProgressBar1",		"NULL",		"airSetTmpText1",
	rs_air,				0x01,		0x0005,		"airLowRadioBox1",		"airMidRadioBox1",		"airHightRadioBox1",	"NULL",		"NULL",		"airWindText1",
	rs_air,				0x01,		0x0006,		"airCoolRadioBox1",		"airHeatRadioBox1",		"airWindRadioBox1",		"NULL",		"NULL",		"airSetModeText1",
	rs_air,				0x01,		0x0009,		"NULL",					"NULL",					"NULL",					"NULL",		"NULL",		"airFastTmpText1",

	rs_air,				0x02,		0x0001,		"airONOFFCheckBox2",	"airWindCheckBox2",		"NULL",					"NULL",		"NULL",		"airONOFFText2",
	rs_air,				0x02,		0x0004,		"setTmpAddButton2",		"setTmpSubButton2",		"setTmpMeter2",			"setTmpCircleProgressBar2",		"NULL",		"airSetTmpText2",
	rs_air,				0x02,		0x0005,		"airLowRadioBox2",		"airMidRadioBox2",		"airHightRadioBox2",	"NULL",		"NULL",		"airWindText2",
	rs_air,				0x02,		0x0006,		"airCoolRadioBox2",		"airHeatRadioBox2",		"airWindRadioBox2",		"NULL",		"NULL",		"airSetModeText2",
	rs_air,				0x02,		0x0009,		"NULL",					"NULL",					"NULL",					"NULL",		"NULL",		"airFastTmpText2",

	rs_air,				0x03,		0x0001,		"airONOFFCheckBox3",	"airWindCheckBox3",		"NULL",					"NULL",		"NULL",		"airONOFFText3",
	rs_air,				0x03,		0x0004,		"setTmpAddButton3",		"setTmpSubButton3",		"setTmpMeter3",			"setTmpCircleProgressBar3",		"NULL",		"airSetTmpText3",
	rs_air,				0x03,		0x0005,		"airLowRadioBox3",		"airMidRadioBox3",		"airHightRadioBox3",	"NULL",		"NULL",		"airWindText3",
	rs_air,				0x03,		0x0006,		"airCoolRadioBox3",		"airHeatRadioBox3",		"airWindRadioBox3",		"NULL",		"NULL",		"airSetModeText3",
	rs_air,				0x03,		0x0009,		"NULL",					"NULL",					"NULL",					"NULL",		"NULL",		"airFastTmpText3",
	
	
//--------------------------------------------------------------------地暖放下面-------------------------------------------------------------------------------------
	rs_floorheat,		0x01,		0x0001,		"airONOFFCheckBox9",	"NULL",					"NULL",			"NULL",		"NULL",		"airONOFFText9",
	
	rs_floorheat,		0x01,		0x0004,		"setTmpAddButton9",		"setTmpSubButton9",		"NULL",			"NULL",		"NULL",		"airSetTmpText9",	//地暖
	
};


const rs_uitype relay[]=
{
	//rs_type   	 rs_addr    rs_port    ui_name        				ui_type
	rs_panle,			02,		0x6007,		"goHomeCheckBox",		 	  0x08,// 1

	rs_panle,			02,		0x6002,		"outHomeCheckBox",		 	  0x08,// 2

	rs_panle,			02,		0x6003,		"eatModeCheckBox",		 	  0x08,// 3

	rs_panle,			02,		0x6004,		"lookCheckBox",		 	 	  0x08,// 4

	rs_panle,		  0xFD,		0x7001,		"curtainOpenButton1",		  0x08,// 1窗帘开
	rs_panle,		  0xFD,		0x7002,		"curtainTopButton1",		  0x08,// 1窗帘停
	rs_panle,		  0xFD,		0x7003,		"curtainCloseButton1",		  0x08,// 1窗帘关

	rs_panle,		  0xFD,		0x7004,		"curtainOpenButton2",		  0x08,// 1窗帘开
	rs_panle,		  0xFD,		0x7005,		"curtainTopButton2",		  0x08,// 1窗帘停
	rs_panle,		  0xFD,		0x7006,		"curtainCloseButton2",		  0x08,// 1窗帘关

	rs_panle,		  0xFD,		0x7007,		"curtainOpenButton3",		  0x08,// 1窗帘开
	rs_panle,		  0xFD,		0x7008,		"curtainTopButton3",		  0x08,// 1窗帘停
	rs_panle,		  0xFD,		0x7009,		"curtainCloseButton3",		  0x08,// 1窗帘关

	rs_panle,		  0xFD,		0x700A,		"curtainOpenButton4",		  0x08,// 1窗帘开
	rs_panle,		  0xFD,		0x700B,		"curtainTopButton4",		  0x08,// 1窗帘停
	rs_panle,		  0xFD,		0x700C,		"curtainCloseButton4",		  0x08,// 1窗帘关

	rs_panle,		  0xFD,		0x7031,		"pcurtainOpenButton1",		  0x08,// 1窗帘开 推窗
	rs_panle,		  0xFD,		0x7032,		"pcurtainTopButton1",		  0x08,// 1窗帘停
	rs_panle,		  0xFD,		0x7033,		"pcurtainCloseButton1",		  0x08,// 1窗帘关

	rs_panle,		  0xFD,		0x7034,		"pcurtainOpenButton2",		  0x08,// 1窗帘开 推窗
	rs_panle,		  0xFD,		0x7035,		"pcurtainTopButton2",		  0x08,// 1窗帘停
	rs_panle,		  0xFD,		0x7036,		"pcurtainCloseButton2",		  0x08,// 1窗帘关

	rs_panle,		  0xFD,		0x7037,		"pcurtainOpenButton3",		  0x08,// 1窗帘开 推窗
	rs_panle,		  0xFD,		0x7038,		"pcurtainTopButton3",		  0x08,// 1窗帘停
	rs_panle,		  0xFD,		0x7039,		"pcurtainCloseButton3",		  0x08,// 1窗帘关

	rs_relay,			01,		0x6001,		"lightCheckBox1",		 	  0x08,// 5
	rs_relay,			01,		0x6002,		"lightCheckBox2",		 	  0x08,// 5
	rs_relay,			01,		0x6003,		"lightCheckBox3",		 	  0x08,// 5
	rs_relay,			01,		0x6004,		"lightCheckBox4",		 	  0x08,// 5
	rs_relay,			01,		0x6005,		"lightCheckBox5",		 	  0x08,// 5
	rs_relay,			01,		0x6006,		"lightCheckBox6",		 	  0x08,// 5
	rs_relay,			01,		0x6007,		"lightCheckBox7",		 	  0x08,// 5
	rs_relay,			01,		0x6008,		"lightCheckBox8",		 	  0x08,// 5
	
	rs_relay,			01,		0x6009,		"lightCheckBox9",		 	  0x08,// 5
	rs_relay,			01,		0x600A,		"lightCheckBox10",		 	  0x08,// 5
	rs_relay,			01,		0x600B,		"lightCheckBox11",		 	  0x08,// 5
	rs_relay,			01,		0x600C,		"lightCheckBox12",		 	  0x08,// 5
	rs_relay,			01,		0x600D,		"lightCheckBox13",		 	  0x08,// 5
	rs_relay,			01,		0x600E,		"lightCheckBox14",		 	  0x08,// 5
	rs_relay,			01,		0x600F,		"lightCheckBox15",		 	  0x08,// 5
	rs_relay,			01,		0x6010,		"lightCheckBox16",		 	  0x08,// 5

	rs_dimmer,			01,		0x6001,		"lightTrackBar1",		 	  0x08,// 5

	rs_dimmer,			01,		0x6002,		"lightTrackBar2",		 	  0x08,// 6

	rs_dimmer,			01,		0x6003,		"lightTrackBar3",		 	  0x08,// 7

	rs_dimmer,			01,		0x6004,		"lightTrackBar4",		 	  0x08,// 8

	rs_dimmer,			02,		0x6001,		"lightTrackBar5",		 	  0x08,// 9
	
};


#if defined(TEST_INTR_MODE)
static void UartCallback(void* arg1, uint32_t arg2)
{
	uint8_t getstr1[256];
	uint8_t sendtr1[8] = {0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
	int len = 0;
	static int totalcount =0;	

#if 1  // Turn on  ITP_IOCTL_REG_UART_CB  flag , should using these codes.
	sem_post(&UartSemIntr);
#else  // Turn on ITP_IOCTL_REG_UART_DEFER_CB flag , should using these codes.

#endif
}
#endif

#if defined(TEST_DMA_MODE) || defined(TEST_FIFO_MODE)
void timer_isr(void* data)
{
    uint32_t timer = (uint32_t)data;

    ithTimerClearIntr(timer);
#if defined(TEST_DMA_MODE)
	sem_post(&UartSemDma);
#elif defined(TEST_FIFO_MODE)
	sem_post(&UartSemFifo);
#endif
}

static void UartIntrHandler(unsigned int pin, void *arg)
{
	ITHTimer timer = (ITHTimer)arg;
	//ithPrintf("timer=%d\n", timer);
	ithGpioClearIntr(pin);
	ithTimerCtrlDisable(timer, ITH_TIMER_EN);	
	ithTimerSetTimeout(timer, 1000);//us
	ithTimerCtrlEnable(timer, ITH_TIMER_EN);	
}

/*
static void UartIntrHandler2(void * arg)
{
	ITHUartPort port = (ITHUartPort)arg;
	ithUartClearIntr(port);
	ithPrintf("-- uart handle2 --\n");
}*/

void InitUartIntr(ITHUartPort port)
{
	ithEnterCritical();
#if 1
    ithGpioClearIntr(TEST_GPIO_RX);
    ithGpioSetIn(TEST_GPIO_RX);
    ithGpioRegisterIntrHandler(TEST_GPIO_RX, UartIntrHandler, ITH_TIMER5);
	
    ithGpioCtrlDisable(TEST_GPIO_RX, ITH_GPIO_INTR_LEVELTRIGGER);   /* use edge trigger mode */
    ithGpioCtrlEnable(TEST_GPIO_RX, ITH_GPIO_INTR_BOTHEDGE); /* both edge */    
    ithIntrEnableIrq(ITH_INTR_GPIO);
    ithGpioEnableIntr(TEST_GPIO_RX);
#else
	//printf("port = 0x%x\n", port);
	ithIntrDisableIrq(ITH_INTR_UART2);
    ithUartClearIntr(ITH_UART2);
    ithIntrClearIrq(ITH_INTR_UART2);

    ithIntrSetTriggerModeIrq(ITH_INTR_UART2, ITH_INTR_LEVEL);
    ithIntrRegisterHandlerIrq(ITH_INTR_UART2, UartIntrHandler2, (void *)ITH_UART2);
    ithUartEnableIntr(ITH_UART2, ITH_UART_RX_READY);

    /* Enable the interrupts. */
    ithIntrEnableIrq(ITH_INTR_UART2);
#endif
    ithExitCritical();
}

void InitTimer(ITHTimer timer, ITHIntr intr)
{
	ithTimerReset(timer);
	
	// Initialize Timer IRQ
	ithIntrDisableIrq(intr);
	ithIntrClearIrq(intr);

	// register Timer Handler to IRQ
	ithIntrRegisterHandlerIrq(intr, timer_isr, (void*)timer);

	// set Timer IRQ to edge trigger
	ithIntrSetTriggerModeIrq(intr, ITH_INTR_EDGE);

	// set Timer IRQ to detect rising edge
	ithIntrSetTriggerLevelIrq(intr, ITH_INTR_HIGH_RISING);

	// Enable Timer IRQ
	ithIntrEnableIrq(intr);
}
#endif



/* 向环形buffer中写入数据，1个字节 */
uint8 rb_putbyte(r_fifo *rb, uint8	dat)
{
	rb->buf[rb->write_index]	= dat;
	printf(" write_data[%d] = %02X\n",rb->write_index,rb->buf[rb->write_index]);
	//如果后半段空闲空间足够容纳，则直接拷贝即可
	if ((rb->buffer_size - rb->write_index)	> 1){
		rb->write_index	+= 1; //写指针后移相应的长度
	}
	else {
		//先塞满后半段，注意大小不是length，而是后半段的长度
		rb->write_index	= 0;
	}
	return true;
}

//*******************************************************************************************************
/* 从环形buffer中读出数据，1个字节 */
uint8 rb_getbyte(r_fifo* rb, uint8	*dat)
{
	if(rb->read_index == rb->write_index)	return	false;

	*dat = rb->buf[rb->read_index];
//	printf(" read_data[%d] = %02X\n",rb->read_index,rb->buf[rb->read_index]);
	//如果后半段数据足够，则直接取用
	if ((rb->buffer_size - rb->read_index) > 1) {
		rb->read_index += 1; //读指针后移相应的长度
	}
	else {
		rb->read_index = 0;//length - rb->buffer_size + rb->read_index;
	}
	return true;
}

//环形缓冲区初始化
void init_ringbuff(void)
{
	rb.read_index = 0;
	rb.write_index = 0;
	rb.buffer_size = sizeof(mybuff);
	memset(mybuff,0,sizeof(mybuff));
	rb.buf = mybuff;
}

void Uart0Protocol_Receive_FIFO_Reset(void)
{
//	s_Uart0FIFO.vRecLen	= 0;
//	s_Uart0FIFO.vReadPoint = 0;
//	s_Uart0FIFO.vWritePoint	= 0;

	Uart0Protocol.vMode	= recModeClear;
	Uart0Protocol.vPoint = 0;
	Uart0Protocol.vTimerout	= 0;
}
static uint8_t ByteToBcd2(uint8_t Value)
{
  uint8_t bcdhigh = 0;

  while (Value >= 10)
  {
    bcdhigh++;
    Value -= 10;
  }
  return  ((uint8_t)(bcdhigh << 4) | Value);
}

static uint8_t Bcd2ToByte(uint8_t Value)
{
  uint8_t tmp = 0;
  tmp = ((uint8_t)(Value & (uint8_t)0xF0) >> (uint8_t)0x4) * 10;
  return (tmp + (Value & (uint8_t)0x0F));
}


void Get_LocalTime(void)
{
	struct timeval tv;
    struct tm *tm, mytime;

    gettimeofday(&tv, NULL);	//获取当前时间，时间精度可达微妙
    tm = localtime(&tv.tv_sec);	//获取系统时间，时间精度为秒，把秒转化为年月日时分秒

    memcpy(&mytime, tm, sizeof (struct tm));


	mytime.tm_mday = Bcd2ToByte(ri_clock.tm_mday);
	if(ri_clock.tm_mon>=1)
    mytime.tm_mon =  Bcd2ToByte(ri_clock.tm_mon)-1;			//实际月份减去1获得的值
    mytime.tm_year = Bcd2ToByte(ri_clock.tm_year)+100;		//实际年份减去1900获得的值
	
    mytime.tm_hour = ri_clock.tm_hour;
    mytime.tm_min =  ri_clock.tm_min;
    mytime.tm_sec = 0;

    tv.tv_sec = mktime(&mytime);	//将年月日时分秒转换为秒
    tv.tv_usec = 0;

	printf("time set sucess====================== %d\n",tv.tv_sec);

    settimeofday(&tv, NULL);	//设置当前时间

}

uint8 CheckSum_XOR(uint8 *p,int len)
{
	uint8 res=0x00;

	for(; len>0; len--,p++)
		res	^= *p;

	return res;
}

extern int ExternalSend(ExternalEvent* ev);
extern int ExternalReceive(ExternalEvent* ev);
extern void ituCheckBoxSetChecked(ITUCheckBox* checkbox, bool checked);

bool uart_chk_send_task(void)			//发送数据条件判断
{
	if(s_uart.send_Relaycmd_flag == true)	return true;
	if(s_uart.send_Aircmd_flag == true)		return true;

											return false;
}

void uart_send_handler(void)
{
	if(s_uart.uart_receive_flag == true)	return;

	if(s_uart.tx_interval < UART_MAX_INTERVALTIME){
		++s_uart.tx_interval ;
		return;
	}

	if(uart_chk_send_task() == false)	return;
	s_uart.tx_interval = 0;
	
	
	if(s_uart.send_Relaycmd_flag == true)
	{
		s_uart.send_Relaycmd_flag = false;
		Uart1_Tx_relay();
	}
	else if(s_uart.send_Aircmd_flag == true)
	{
		s_uart.send_Aircmd_flag = false;
		Uart1_Tx_Air1_relay();
	}
}

void *uart_dataprocess(void)
{
	//上电同步处理
	init_SYN_flag = true;
	init_SYN_cnt = 0;
	while(1)
	{	
		if(s_uart.uart_receive_flag == true)
		{
			if(++s_uart.rx_outtime > 10)
			{
				s_uart.rx_outtime = 0;
				s_uart.uart_receive_flag = false;

				//init_ringbuff();
			}
		}
//		Uart0FIFO_getbyte_Looper();//从缓冲区拿出一字节处理
		uart_send_handler();

		usleep(1000*10);	
	}

}

#if !Rs_NewOldprotocol_Shift

void rx_rsOldProtocolRelay_process(uint8 *dat, uint8 *len)
{
	uint8 i,j,n,ch;
	ITUCheckBox* checkbox;
	for(i=0;i<(*len);i++){
		CH4094[i] = dat[i];
		printf("recevie CH4094[%d] %02X\n",i,CH4094[i]);
	}
	
	for(i=0;i<Relay_MAX;i++)
	{
		if(CH4094[i] != CH4094_bak[i])
		{
			ch = CH4094[i]^CH4094_bak[i];
			
			for(j=0;j<8;j++)
			{
				if(!(ch & (1<<j))) continue;
				for(n =0;n < (sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));n++)
				{
					if(ModuleUI_tmp[n].m_type != rs_relay) continue;
					if(((ModuleUI_tmp[n].m_addr + 1)*8 + ModuleUI_tmp[n].port&0xFF) == (i*8+j+1))
					{
						checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[n].ui_name_Para1);
						
						if(CH4094[i] & (1<<j))
						{
							CH4094_bak[i] |= (1<<j);
							if(checkbox != NULL)
							ituCheckBoxSetChecked(checkbox, true);

							if(strcmp("windowOpen" ,ModuleUI_tmp[n].ui_name_Para2) == 0){
								checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[n].ui_name_Para3);
								if(checkbox != NULL){
									if((CH4094[i] & (1<<(j+1))) == 0)
									ituCheckBoxSetChecked(checkbox, true);
									
								}
								
							}
							else if(strcmp("windowClose" ,ModuleUI_tmp[n].ui_name_Para2) == 0){
								checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[n].ui_name_Para3);
								if(checkbox != NULL){
									if((CH4094[i] & (1<<(j-1))) == 0)
										ituCheckBoxSetChecked(checkbox, false);

								}
								
								
							}
						}
						else
						{
							CH4094_bak[i] &= ~(1<<j);
							if(checkbox != NULL)
							ituCheckBoxSetChecked(checkbox, false);
						}
				
					}
				}
			}
		}
	}
}
void rx_rsOldDimmerData_process(uint8 *dat,uint8 *len)
{
	//AA 61 1A 05 00 02 02 01 46 00 00 02 03 01 3C 00 00 02 04 01 3C 00 00 03 01 01 3C 00 00 01 0D
	uint8 i,j,n,ch;
	EXT_Dimmer_Type	*pEXT;
	
	if(dat[0] == 0x05){
		pEXT = (EXT_Dimmer_Type*)&dat[2];
		n =	(*len)-2;	//根据长度计算出收到多少路调光。模块回传是4路数据。
		for(;n>0;n--){
			if((pEXT->vModuleAddr>0) &&	(pEXT->vModuleAddr<=Dimmer_Module_MAX)){
				for(i =0;i < (sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++)
				{
					if(ModuleUI_tmp[i].m_type != rs_dimmer) continue;
					if(((ModuleUI_tmp[i].m_addr - 1)*4 + ModuleUI_tmp[i].port&0xFF) == ((pEXT->vModuleAddr - 1)*4 + pEXT->vModuleLoop))
					{
						ITUCheckBox* checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para1);//开关
						ITUProgressBar* trackbar = (ITUProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para2);//开关
						ITUProgressBar* progressbox = (ITUProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para3);//开关
						if(checkbox == NULL) continue;
						if(trackbar == NULL) continue;
						if(progressbox == NULL) continue;
						
						if(pEXT->vEventCmd != 0){
							ituCheckBoxSetChecked(checkbox, true);
						}
						else{
							ituCheckBoxSetChecked(checkbox, false);
						}

						if(ituCheckBoxIsChecked(checkbox)){
							ituTrackBarSetValue(trackbar, pEXT->vLightValue);
							ituProgressBarSetValue(progressbox, pEXT->vLightValue);
						}
						else{
							ituTrackBarSetValue(trackbar, 0);
							ituProgressBarSetValue(progressbox, 0);
						}
				
					}
				}
				pEXT++;	//指向下一路调光
			}
		}
	}
}

void rx_rsOldProtocolAir_process(uint8 *dat,uint8 *len)
{
	uint8 i,j,n,ch;
	unsigned char ptr[40];
	if((*len)/3 > AIR_MAXLEN) return;
	if((*len)%3 !=0) return;//过滤空调面板发数据

	for(j=0;j<(*len)/3;j++){
		sys_air.air[j].fasttemprature = dat[j*3 + 0];
		sys_air.air[j].setTemprature  = dat[j*3 + 1];
		sys_air.air[j].wind 		  = dat[j*3 + 2]&0x03;
		sys_air.air[j].season 		  = ((dat[j*3 + 2]&0x80)>>7);
	}

	
	for(n=0;n<AIR_MAXLEN;n++){
		for(i =0;i < (sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++){//开关
			if((ModuleUI_tmp[i].m_type == rs_air) && ((n+1)==ModuleUI_tmp[i].m_addr) && (ModuleUI_tmp[i].port&0xFF == 0x01)){
				ITUCheckBox* checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para1);//开关
				ITUCheckBox* checkbox1 = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para2);//风速图标

				if(checkbox == NULL) continue;
				if(checkbox1 == NULL) continue;

				if(sys_air.air[n].wind ){
					ituCheckBoxSetChecked(checkbox, true);
					ituCheckBoxSetChecked(checkbox1, true);
				}
				else{
					ituCheckBoxSetChecked(checkbox, false);
					ituCheckBoxSetChecked(checkbox1, false);

					
				printf(" guan kongtiao \n");
				ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i+2].ui_name_Para1);
				if(radiobox != NULL)
				ituRadioBoxSetChecked(radiobox, false);
				radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i+2].ui_name_Para2);
				if(radiobox != NULL)
				ituRadioBoxSetChecked(radiobox, false);
				radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i+2].ui_name_Para3);
				if(radiobox != NULL)
				ituRadioBoxSetChecked(radiobox, false);
				}
					
				break;	
			}
		}
		
		if(sys_air.air[n].fasttemprature != sys_air.air_bak[n].fasttemprature){//室温
			sys_air.air_bak[n].fasttemprature = sys_air.air[n].fasttemprature;

			for(i =0;i < (sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++){
				if((ModuleUI_tmp[i].m_type == rs_air) && ((n+1)==ModuleUI_tmp[i].m_addr) && (ModuleUI_tmp[i].port&0xFF == 0x09)){
					ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_txt);
					if(text != NULL){
						memset(ptr,0,sizeof(ptr));
						sprintf(ptr,"当前室温%d°C",sys_air.air_bak[n].fasttemprature);
						ituTextSetString(text, ptr);
						break;
					}
						
				}
			}
		}

		if(sys_air.air[n].setTemprature != sys_air.air_bak[n].setTemprature){//设温
			sys_air.air_bak[n].setTemprature = sys_air.air[n].setTemprature;

			for(i =0;i < (sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++){
				if((ModuleUI_tmp[i].m_type == rs_air) && ((n+1)==ModuleUI_tmp[i].m_addr) && (ModuleUI_tmp[i].port&0xFF == 0x04)){
					
					ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_txt);
					ITUMeter* meter = (ITUMeter*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para3);
					ITUCircleProgressBar* bar = (ITUCircleProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para4);
					if(text != NULL){
						
						memset(ptr,0,sizeof(ptr));
						sprintf(ptr,"%d",sys_air.air_bak[n].setTemprature);
					
						ituTextSetString(text, ptr);

						if(meter != NULL){
							if(sys_air.air_bak[n].setTemprature >=16)
							ituMeterSetValue(meter, sys_air.air_bak[n].setTemprature - 16);
						}

						if(bar != NULL){
							if(sys_air.air_bak[n].setTemprature >=16)
							ituCircleProgressBarSetValue(bar, sys_air.air_bak[n].setTemprature - 16);
						}
						break;
					}
						
				}
			}
		}

		if(sys_air.air[n].wind != sys_air.air_bak[n].wind){//风速
			sys_air.air_bak[n].wind = sys_air.air[n].wind;
			
			printf("wind： %02X\n",sys_air.air_bak[n].wind);
			for(i =0;i < (sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++){
				if((ModuleUI_tmp[i].m_type == rs_air) && ((n+1)==ModuleUI_tmp[i].m_addr) && (ModuleUI_tmp[i].port&0xFF == 0x05)){
					if(sys_air.air[n].wind== 1)
					{
						ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para1);
						if(radiobox != NULL)
						ituRadioBoxSetChecked(radiobox, true);
					}
					else if(sys_air.air[n].wind == 2)
					{
						ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para2);
						if(radiobox != NULL)
						ituRadioBoxSetChecked(radiobox, true);
					}
					else if(sys_air.air[n].wind == 3)
					{
						ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para3);
						if(radiobox != NULL)
						ituRadioBoxSetChecked(radiobox, true);
					}
					else if(sys_air.air[n].wind >3)
					{
						ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_Para3);
						if(radiobox != NULL)
						ituRadioBoxSetChecked(radiobox, true);
					}
					else
					{
						;
					}
					break;
					
					
					
				}
			}
		}
	}

}


#else

void rx_rsTimeData_process(uint8 *dat,uint16 i)
{
	uint16	vRecFuncPort;

	vRecFuncPort = (dat[i*6+2] <<8) + dat[i*6+3];

	
	if(((dat[i*6+0] <<8) + dat[i*6+1]) == 0xFA01)	
	{
		switch(vRecFuncPort)
		{
			if(AllowReceiveTimeData_flag == false)
			{
				if(clock_cnt == 0){
					case 0x0001:
					ri_clock.tm_year = dat[i*6+5];
					clock_cnt = 1;
					break;
				}
				else if(clock_cnt == 1){
					case 0x0002:
					ri_clock.tm_mon = dat[i*6+5];
					clock_cnt = 2;
					break;
				}
				else if(clock_cnt == 2){
					case 0x0003:
					ri_clock.tm_mday = dat[i*6+5];
					clock_cnt = 3;
					break;
				}
				else if(clock_cnt == 3){
					case 0x0005:
					ri_clock.tm_hour = dat[i*6+5];
					clock_cnt = 4;
				
					break;
				}
				else if(clock_cnt == 4){
					case 0x0006:
					ri_clock.tm_min = dat[i*6+5];
					
					//发送完整一包时间数据后才更新屏时间,因为屏控需要完整的年月日时分来转换为秒
					Get_LocalTime();
					clock_cnt = 0;
					AllowReceiveTimeData_flag = true;
					printf("============================\n");
					break;
				}
			}
			else
			{//1分钟接收一次主机下发的时间，保证时间同步
				switch(vRecFuncPort)
				{
					case 0x0005:
						ri_clock.tm_hour = dat[i*6+5];
						break;
					case 0x0006:
						ri_clock.tm_min = dat[i*6+5];
						
						//发送完整一包时间数据后才更新屏时间,因为屏控需要完整的年月日时分来转换为秒
						Get_LocalTime();
						clock_cnt = 0;
						AllowReceiveTimeData_flag = true;
						printf("============================\n");
						break;
					default:
						break;

				}
			}
		}		
	}
}



void rx_rsPlaneData_process(uint8 *dat,uint16 i)
{
	uint16	vRecFuncPort;
	uint16	j,k;
	ITUCheckBox* checkbox;
	char *widgetname;
	char str[100];

	vRecFuncPort = (dat[i*6+2] <<8) + dat[i*6+3];

	printf("vRecFuncPort = %d \n",vRecFuncPort);
	
	for(j =0;j < (sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));j++)
	{
		if((dat[i*6+0] == ModuleUI_tmp[j].m_type) && (dat[i*6+1] == ModuleUI_tmp[j].m_addr))
		{
			if(ModuleUI_tmp[j].m_addr > 100)  //面板地址大于100就退出
			{
				//面板地址大于100的地址功能暂不添加
				if(vRecFuncPort == ModuleUI_tmp[j].port){
					if(ModuleUI_tmp[j].m_type == rs_panle){

						checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para1);

						if(checkbox == NULL) return;

					}
				}
				
				break;
			}
			
			if(vRecFuncPort == ModuleUI_tmp[j].port)		//收到单个按键开关
			{
				switch(ModuleUI_tmp[j].m_type)
				{
					case rs_panle:				//面板数据
					case rs_relay:				//继电器数据
						{
							checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para1);
							
							if(checkbox == NULL) return;
							
							if(dat[i*6+5] == 1)
							{
								ituCheckBoxSetChecked(checkbox, true);
							}
							else
							{
								ituCheckBoxSetChecked(checkbox, false);
							}
						}
						break;
					
					case rs_dimmer:				//调光数据
							{
								ITUCheckBox* checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para1);//开关
								ITUProgressBar* trackbar = (ITUProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para2);//滑杆
								ITUProgressBar* progressbox = (ITUProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para3);//滑杆进度条

								if(checkbox == NULL) return;
								if(trackbar == NULL) return;
								if(progressbox == NULL) return;

								if((int)dat[i*6+4] != 0){
									ituCheckBoxSetChecked(checkbox, true);
								}
								else{
									ituCheckBoxSetChecked(checkbox, false);
								}

								if(ituCheckBoxIsChecked(checkbox)){
									ituTrackBarSetValue(trackbar, (int)dat[i*6+5]);
									ituProgressBarSetValue(progressbox,(int)dat[i*6+5]);
								}
								else{
									ituTrackBarSetValue(trackbar, 0);
									ituProgressBarSetValue(progressbox, 0);
								}

							}
							break;
					default :
						break;
				}
			}
			else if(vRecFuncPort == 0x6FFF) 		//收到全开全关
			{
				for(k=0;k<sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]);k++)
				{
					if((dat[i*6+0] == ModuleUI_tmp[k].m_type) && (dat[i*6+1] == ModuleUI_tmp[k].m_addr))
					{
						switch(ModuleUI_tmp[k].m_type)
						{
							case rs_panle:
							case rs_relay:
								{
									checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[k].ui_name_Para1);

									if(checkbox == NULL) continue;
							
									if(dat[i*6+5] == 1)
									{
										ituCheckBoxSetChecked(checkbox, true);
									}
									else
									{
										ituCheckBoxSetChecked(checkbox, false);
									}
								}
								break;
					
							case rs_dimmer:
								{
									ITUCheckBox* checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[k].ui_name_Para1);//开关
										ITUProgressBar* trackbar = (ITUProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[k].ui_name_Para2);//滑杆
										ITUProgressBar* progressbox = (ITUProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[k].ui_name_Para3);//滑杆进度条

										if(checkbox == NULL) continue;
										if(trackbar == NULL) continue;
										if(progressbox == NULL) continue;

										if((int)dat[i*6+4] != 0){
											ituCheckBoxSetChecked(checkbox, true);
										}
										else{
											ituCheckBoxSetChecked(checkbox, false);
										}

										if(ituCheckBoxIsChecked(checkbox)){
											ituTrackBarSetValue(trackbar, (int)dat[i*6+5]);
											ituProgressBarSetValue(progressbox,(int)dat[i*6+5]);
										}
										else{
											ituTrackBarSetValue(trackbar, 0);
											ituProgressBarSetValue(progressbox, 0);
										}
								}
								break;
							default :
								break;
						}
					}
				}

				break;
			}

		}
	}
	
}

void rx_rsAirData_process(uint8 *dat,uint16 i)
{
	uint16 j;
	uint16	vRecFuncPort;
	uint16	vTmpData;
	unsigned char ptr[20];
	
	for(j=0;j<(sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));j++)
	{
		vRecFuncPort = (dat[i*6+2] <<8) + dat[i*6+3];
		
		if((dat[i*6+0] == ModuleUI_tmp[j].m_type) && (dat[i*6+1] == ModuleUI_tmp[j].m_addr) && (vRecFuncPort == ModuleUI_tmp[j].port))
		{
			
			if(vRecFuncPort == ModuleUI_tmp[j].port)
			{
				if(ModuleUI_tmp[j].m_type == rs_air)
				{
					switch(vRecFuncPort)
					{
						case 0x0001:	//开关
						{
							ITUCheckBox* checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para1);
							ITUCheckBox* checkbox1 = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para2);//风速图标

							if(checkbox == NULL) return;
							if(checkbox1 == NULL) return;
							
							
							if(dat[i*6+5] == 1)
							{
								ituCheckBoxSetChecked(checkbox, true);
								ituCheckBoxSetChecked(checkbox1, true);

								rs_NewAir[ModuleUI_tmp[j].m_addr -1].oNOFF = true;

								printf("vwind = %d \n",rs_NewAir[ModuleUI_tmp[j].m_addr -1].vwind);

								switch(rs_NewAir[ModuleUI_tmp[j].m_addr -1].vwind){

									case 1:
										{
											ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j +2].ui_name_Para1);

											if(radiobox == NULL) return;
											ituRadioBoxSetChecked(radiobox, true);
										}

										break;
									case 2:
										{
											ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j +2].ui_name_Para2);

											if(radiobox == NULL) return;
											ituRadioBoxSetChecked(radiobox, true);
										}

										break;
									case 3:
										{
											ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j +2].ui_name_Para3);

											if(radiobox == NULL) return;
											ituRadioBoxSetChecked(radiobox, true);

										}

										break;
									default:
										{
											ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j +2].ui_name_Para1);

											if(radiobox == NULL) return;
											ituRadioBoxSetChecked(radiobox, true);

										}

									break;


								}
								
							}
							else
							{
								ituCheckBoxSetChecked(checkbox, false);
								ituCheckBoxSetChecked(checkbox1, false);

								rs_NewAir[ModuleUI_tmp[j].m_addr -1].oNOFF = false;

								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j +2].ui_name_Para3);
								printf("close wind \n");

								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, false);
							}
						}
							break;
						case 0x0005:	//风速
						{

							if((dat[i*6+5] & 0x03) != 0x00) 
							{
								printf("oNOFF = %d \n",rs_NewAir[ModuleUI_tmp[j].m_addr -1].oNOFF);
								if(rs_NewAir[ModuleUI_tmp[j].m_addr -1].oNOFF == false){
									
									rs_NewAir[ModuleUI_tmp[j].m_addr -1].oNOFF = true;
									
									ITUCheckBox* checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j-2].ui_name_Para1);
									ITUCheckBox* checkbox1 = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j-2].ui_name_Para2);//风速图标

									if(checkbox == NULL) return;
									if(checkbox1 == NULL) return;

									ituCheckBoxSetChecked(checkbox, true);
									ituCheckBoxSetChecked(checkbox1, true);
								}
							}

							rs_NewAir[ModuleUI_tmp[j].m_addr -1].vwind = dat[i*6+5] & 0x03;
							if((dat[i*6+5] & 0x03) == 1)
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para1);

								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, true);
								
							}
							else if((dat[i*6+5] & 0x03) == 2)
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para2);
								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, true);
							}
							else if((dat[i*6+5] & 0x03) == 3)
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para3);

								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, true);
							}
							else if((dat[i*6+5] & 0x03) == 0)
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para3);

								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, false);
							
							}
							else
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para3);

								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, true);
							}
						}
							break;
						case 0x0006:	//模式
						{
							if(dat[i*6+5] == 0x04)
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para1);

								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, true);
							}
							else if(dat[i*6+5] == 0x02)
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para2);
								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, true);
								
							}
							else if(dat[i*6+5] == 0x08)
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para2);
								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, true);
							}
							else
							{
								ITURadioBox* radiobox = (ITURadioBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para2);
								if(radiobox == NULL) return;
								ituRadioBoxSetChecked(radiobox, true);
							}
						}
							break;
						case 0x0004:	//设置温度
						{
							
							vTmpData = dat[i*6+4] <<8;
							vTmpData |= dat[i*6+5];
							vTmpData = (vTmpData/10);


							ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_txt);
							ITUMeter* meter = (ITUMeter*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para3);
							ITUCircleProgressBar* bar = (ITUCircleProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para4);

							if(text == NULL) return;
							if(meter == NULL) return;
							if(bar == NULL) return;
							
							if(text != NULL){
								
								memset(ptr,0,sizeof(ptr));
								sprintf(ptr,"%d",vTmpData);
							
								ituTextSetString(text, ptr);

								if(meter != NULL){
									if(vTmpData >=16)
									ituMeterSetValue(meter, vTmpData - 16);
								}

								if(bar != NULL){
									if(vTmpData >=16)
									ituCircleProgressBarSetValue(bar, vTmpData - 16);
								}
								break;
							}
						}
							break;
						case 0x0002:	//实际温度
							{
								vTmpData = dat[i*6+4] <<8;
								vTmpData |= dat[i*6+5];
								vTmpData = (vTmpData/10);

								ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_txt);
								
								if(text != NULL){
									memset(ptr,0,sizeof(ptr));
									sprintf(ptr,"当前室温%d°C",vTmpData);
									ituTextSetString(text, ptr);
									break;
								}
									
							}
							break;
						default:

							break;
					}
					
				}
				else if(ModuleUI_tmp[j].m_type == rs_floorheat)
				{
					switch(vRecFuncPort)
					{
						case 0x0001:	//开关
						{
							ITUCheckBox* checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para1);
							if(dat[i*6+5] == 1)
							{
								ituCheckBoxSetChecked(checkbox, true);
							}
							else
							{
								ituCheckBoxSetChecked(checkbox, false);
							}
						}
							break;
						case 0x0004:	//设置温度
						{
							vTmpData = dat[i*6+4] <<8;
							vTmpData |= dat[i*6+5];
							vTmpData = (vTmpData/10);


							ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_txt);
							ITUMeter* meter = (ITUMeter*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para3);
							ITUCircleProgressBar* bar = (ITUCircleProgressBar*)ituSceneFindWidget(&theScene, ModuleUI_tmp[j].ui_name_Para4);
							if(text != NULL){
								
								memset(ptr,0,sizeof(ptr));
								sprintf(ptr,"%d",vTmpData);
							
								ituTextSetString(text, ptr);

								if(meter != NULL){
									if(vTmpData >=16)
									ituMeterSetValue(meter, vTmpData - 16);
								}

								if(bar != NULL){
									if(vTmpData >=16)
									ituCircleProgressBarSetValue(bar, vTmpData - 16);
								}
						}
							break;
						default:
							break;
					}
				}
				break;
			}
			
			}
		}
	}
}

void uart_rxToUiData_process(uint8 *dat, uint8 *len)
{
	uint16 i;

	for(i=0;i<(*len)/6;i++)
	{
		//--------------------------------------------------------------------------------------
		switch(dat[i*6+0])
		{
			case 0xFA:	//时间
				rx_rsTimeData_process(dat,i);
				break;
			case 0x02:	//面板		注意：此处用到的物件类型为checkbox
			case 0x04:	//继电器
			case 0x06:	//调光		调光部分要看物件类型 有些不能在这处理
				rx_rsPlaneData_process(dat,i);
				break;
			case 0x07:	//空调
			case 0x0A:	//地暖
				rx_rsAirData_process(dat,i);
				break;
			default :
				break;
		}

	}
	
}


#endif

void usart0_receivePacket_Handler(u8 *p)
{
	uint8 i;

	uint8 *cmd	= (u8*)(p+1);	//命令
	uint8 *len	= (u8*)(p+2);	//有效数据长度
	uint8 *dat	= (u8*)(p+3);	//数据开始地址
	
	printf("recevie CMD %02X\n",*cmd);
	switch(*cmd)	// 得到命令
	{
		#if Rs_NewOldprotocol_Shift
		case 0x23:
			
			uart_rxToUiData_process(dat,len);
			
		//	evin.type = EXTERNAL_TEST2;
		//	evin.arg1 = 1;
		//	evin.arg2 = 2;
		//	strcpy(evin.buf1, "test");
		//	mq_send(extuart1InQueue, (const char*)&evin, sizeof (ExternalEvent), 0);
			break;
		#else
		case 0xF4:
			rx_rsOldProtocolRelay_process(dat,len);
			break;
		case 0x61:
			rx_rsOldDimmerData_process(dat,len);
			break;
		case 0xF2:
			rx_rsOldProtocolAir_process(dat,len);
			break;
		#endif
		default :
			break;
	}

}


void Uart1Protocol_getbyte_Handle(uint8 getbyte)
{

	if(Uart0Protocol.vPoint	>= protocol_MaxLen)
	{
		Uart0Protocol.vMode	= recModeClear;
		Uart0Protocol.vPoint = 0x00;		//重新接收数据
		Uart0Protocol_Receive_FIFO_Reset();	//出错溢出复位
		return;
	}
	
	//--------------------------------------------------------------------------
	switch(Uart0Protocol.vMode)
	{
		case recModeClear://处于空闲状态下，接收帧头0xAA
			Uart0Protocol.vPoint= 0x00;
			if(getbyte == FrameStartByte)
			{
				memset(&Uart0Protocol.vPacket,0,sizeof(Uart0Protocol.vPacket));//数据打包时最好先清零
				//s_Uart0TCB.vTx_Interval	= 0x00;
				
				Uart0Protocol.vPacket[Uart0Protocol.vPoint++] =	getbyte;
				Uart0Protocol.vMode++;
			}
			break;
		//----------------------------------------------------------------------
		case recMode1:	//CMD
			if(getbyte != FrameStartByte)	//如果再次接收到AA则过滤掉
			{
				Uart0Protocol.vPacket[Uart0Protocol.vPoint++] =	getbyte;
				Uart0Protocol.vMode++;
			}
			
			break;
		//----------------------------------------------------------------------
		case recMode2:	//LEN
			Uart0Protocol.vPacket[Uart0Protocol.vPoint++] =	getbyte;
			Uart0Protocol.vMode++;
			break;
		//----------------------------------------------------------------------
		case recMode3: //DATA，根据LEN判断是否接收完所有数据
			Uart0Protocol.vPacket[Uart0Protocol.vPoint++] =	getbyte;
			if(Uart0Protocol.vPoint	>= (Uart0Protocol.vPacket[0x02]+3))
				Uart0Protocol.vMode++;
			break;
		//----------------------------------------------------------------------
		case recMode4: //VC，根据接收的这个数据并进行帧的XOR校验
			Uart0Protocol.vPacket[Uart0Protocol.vPoint++] =	getbyte;
			if(CheckSum_XOR(&Uart0Protocol.vPacket[1],Uart0Protocol.vPacket[2]+2) ==	getbyte)
				Uart0Protocol.vMode++;
			else
				Uart0Protocol.vMode	= recModeClear;
			break;
		//----------------------------------------------------------------------
		case recMode5: //0D，帧尾数据。XOR校验过了之后还要判断是否有结束符。
			Uart0Protocol.vPacket[Uart0Protocol.vPoint++] =	getbyte;
			if(getbyte == FrameStopByte)
			{	//处理正确数据
				printf("recevie data sucess!\n");
				usart0_receivePacket_Handler(&Uart0Protocol.vPacket[0]);
			}
			
			Uart0Protocol.vPoint = 0;
			Uart0Protocol.vMode	= recModeClear;
			break;
		
		//----------------------------------------------------------------------
		default:
			Uart0Protocol.vMode	= recModeClear;
			break;
		//----------------------------------------------------------------------
	}
	Uart0Protocol.vTimerout	= 0;
	//--------------------------------------------------------------------------
}

//从循环缓冲中拿出一个字节处理
void Uart0FIFO_getbyte_Looper(void)
{
	//20171208
	uint8 dat;

	while(rb.read_index !=	rb.write_index){

		//while(rb_getbyte(&rb,&dat)==true) 
		{
			rb_getbyte(&rb,&dat);
			Uart1Protocol_getbyte_Handle(dat);
		}
	}
}

extern int ExternalReceive(ExternalEvent* ev);

#if Rs_NewOldprotocol_Shift
void Uart1_Tx_relay(void)
{
	
	sendbuf[0] = FrameStartByte;
	sendbuf[1] = FrameCmd;
	sendbuf[2] = FrameLen;
	sendbuf[3] = s_newpro.vType;
	sendbuf[4] = s_newpro.vAddr;
	sendbuf[5] = s_newpro.vPort_H;
	sendbuf[6] = s_newpro.vPort_L;
	sendbuf[7] = s_newpro.vData_H;
	sendbuf[8] = s_newpro.vData_L;
	sendbuf[9] = CheckSum_XOR(&sendbuf[1],sendbuf[2] +2);
	sendbuf[10] = 0x0D;

	write(ITP_DEVICE_UART1, sendbuf, 11);

	ithGpioClear(RS485_EN_GPIO);	//使能RS485发送
	SDL_Delay(10);					//ms延时
	ithGpioSet(RS485_EN_GPIO);		//使能RS485接收

	Uart0Protocol.vMode	= recModeClear;
	Uart0Protocol.vPoint = 0x00;		//重新接收数据
}

void Uart1_Tx_Air_relay(void)
{
	
	sendbuf[0] = FrameStartByte;
	sendbuf[1] = FrameCmd;
	sendbuf[2] = FrameLen;
	sendbuf[3] = 0x02;
	sendbuf[4] = 0x01;
	sendbuf[5] = 0x60;
	sendbuf[6] = 0x01;
	sendbuf[7] = 0x00;
	sendbuf[8] = 0x01;
	sendbuf[9] = CheckSum_XOR(&sendbuf[1],sendbuf[2] +2);
	sendbuf[10] = 0x0D;

	write(ITP_DEVICE_UART1, sendbuf, 11);

	ithGpioClear(RS485_EN_GPIO);	//使能RS485发送
	SDL_Delay(10);					//ms延时
	ithGpioSet(RS485_EN_GPIO);		//使能RS485接收
}

void Uart1_Tx_Air1_relay(void)
{
	
	sendbuf[0] = FrameStartByte;
	sendbuf[1] = FrameCmd;
	sendbuf[2] = FrameLen;
	sendbuf[3] = 0x02;
	sendbuf[4] = 0x01;
	sendbuf[5] = 0x60;
	sendbuf[6] = 0x01;
	sendbuf[7] = 0x00;
	sendbuf[8] = 0x00;
	sendbuf[9] = CheckSum_XOR(&sendbuf[1],sendbuf[2] +2);
	sendbuf[10] = 0x0D;

	write(ITP_DEVICE_UART1, sendbuf, 11);

	ithGpioClear(RS485_EN_GPIO);	//使能RS485发送
	SDL_Delay(10);					//ms延时
	ithGpioSet(RS485_EN_GPIO);		//使能RS485接收
}
#else
void Uart1_Tx_relay(void)
{
	
	sendbuf[0] = FrameStartByte;
	sendbuf[1] = 0xF4;
	sendbuf[2] = 0x01;
	sendbuf[3] = tx_Oldrelay_value;

	sendbuf[4] = CheckSum_XOR(&sendbuf[1],sendbuf[2] +2);
	sendbuf[5] = 0x0D;

	write(ITP_DEVICE_UART1, sendbuf, 6);

	ithGpioClear(RS485_EN_GPIO);	//使能RS485发送
	SDL_Delay(10);					//ms延时
	ithGpioSet(RS485_EN_GPIO);		//使能RS485接收

	Uart0Protocol.vMode	= recModeClear;
	Uart0Protocol.vPoint = 0x00;		//重新接收数据
}


void Uart1_Tx_Air1_relay(void)
{
	
	sendbuf[0] = FrameStartByte;
	sendbuf[1] = 0xF2;
	sendbuf[2] = 0x04;
	
	sendbuf[3] = sys_air.id;
	sendbuf[4] = sys_air.air[sys_air.id -1].fasttemprature;
	sendbuf[5] = sys_air.air[sys_air.id -1].setTemprature;
	sendbuf[6] = sys_air.air[sys_air.id -1].wind;

	if(sys_air.air[sys_air.id -1].season == 1){
		sendbuf[6] |=0x80;
	}
	else{
		sendbuf[6] &=~0x80;
	}
	
	sendbuf[7] = CheckSum_XOR(&sendbuf[1],sendbuf[2] +2);
	sendbuf[8] = 0x0D;

	write(ITP_DEVICE_UART1, sendbuf, 9);

	ithGpioClear(RS485_EN_GPIO);	//使能RS485发送
	SDL_Delay(10);					//ms延时
	ithGpioSet(RS485_EN_GPIO);		//使能RS485接收
}

void Uart1_Tx_Dimmer(void)
{
	
	sendbuf[0] = FrameStartByte;
	sendbuf[1] = 0xF9;
	sendbuf[2] = 0x03;
	sendbuf[3] = s_uart_dim.id;
	sendbuf[4] = s_uart_dim.cmd;
	sendbuf[5] = s_uart_dim.value;

	sendbuf[6] = CheckSum_XOR(&sendbuf[1],sendbuf[2] +2);
	sendbuf[7] = 0x0D;

	write(ITP_DEVICE_UART1, sendbuf, 8);

	ithGpioClear(RS485_EN_GPIO);	//使能RS485发送
	SDL_Delay(10);					//ms延时
	ithGpioSet(RS485_EN_GPIO);		//使能RS485接收

	Uart0Protocol.vMode	= recModeClear;
	Uart0Protocol.vPoint = 0x00;		//重新接收数据
}

#endif

#if defined(TEST_INTR_MODE)
void* TestFuncUseINTR(void* arg)
{
    unsigned char getstr[1024];
    unsigned char sendtr[200];
	unsigned char rDat;
	
	
	int len = 0;
	
	printf("Start uart test!\n");

	sem_init(&UartSemIntr, 0, 0);

    itpRegisterDevice(UART1_PORT, &UART1_DEVICE);
	ioctl(UART1_PORT, ITP_IOCTL_INIT, NULL);
	ioctl(UART1_PORT, ITP_IOCTL_RESET, UART1_BAUDRATE);

	ioctl(UART1_PORT, ITP_IOCTL_REG_UART_CB, (void*)UartCallback);

	memset(getstr, 0, 1024);
	memset(sendtr, 0, 200);

	init_ringbuff();
	
	ithGpioSetOut(RS485_EN_GPIO);	
	ithGpioSet(RS485_EN_GPIO);		//使能RS485接收
    while(1)
    {
    
		sem_wait(&UartSemIntr);
   		ithEnterCritical();
        
		s_uart.uart_receive_flag = true;
		len = read(UART1_PORT, &rDat ,1);

		rb_putbyte(&rb,rDat);	//把接收的数据存入环形缓冲区
		s_uart.rx_outtime = 0;

		ithExitCritical();
		
	}
}

#elif defined(TEST_DMA_MODE)
void* TestFuncUseDMA(void* arg)
{
	int len = 0;
	int count = 0;
	char getstr[256];
	char sendtr[256];
	
	itpRegisterDevice(TEST_PORT, &TEST_DEVICE);
	ioctl(TEST_PORT, ITP_IOCTL_UART_SET_BOOT, false);
	ioctl(TEST_PORT, ITP_IOCTL_RESET, TEST_BAUDRATE);
	printf("Start uart DMA mode test!\n");
	InitTimer(ITH_TIMER5, ITH_INTR_TIMER5);
	InitUartIntr(TEST_PORT);
	memset(getstr, 0, 256);
	memset(sendtr, 0, 256);
	sem_init(&UartSemDma, 0, 0);
	while(1)
	{
		sem_wait(&UartSemDma);
		
		len = read(TEST_PORT, getstr+count, 256);
		//printf("len = %d\n", len);
		printf("len = %d, getstr = %s\n", len, getstr);
	    count += len;
	    if(count >= UartCommandLen)
	    {
		    printf("uart read: %s,count=%d\n",getstr,count);
		    count =0;
			sprintf(sendtr, "%s\n", getstr);
			write(TEST_PORT, sendtr, 256);
		    memset(getstr, 0, 256);
	    }
	}
}
#elif defined(TEST_FIFO_MODE)
void* TestFuncUseFIFO(void* arg)
{
	int len = 0;
	int count = 0;
	char getstr[256];
	char sendtr[256];

	itpRegisterDevice(TEST_PORT, &TEST_DEVICE);
	ioctl(TEST_PORT, ITP_IOCTL_RESET, TEST_BAUDRATE);
	printf("Start uart FIFO mode test!\n");
	InitTimer(ITH_TIMER5, ITH_INTR_TIMER5);
	InitUartIntr(TEST_PORT);
	memset(getstr, 0, 256);
	memset(sendtr, 0, 256);
	sem_init(&UartSemFifo, 0, 0);

	while (1)
	{
		sem_wait(&UartSemFifo);

		len = read(TEST_PORT, getstr + count, 256);
		//printf("len = %d\n", len);
		printf("len = %d, getstr = %s\n", len, getstr);
		count += len;
		if (count >= UartCommandLen)
		{
			printf("uart read: %s,count=%d\n", getstr, count);
			count = 0;
			sprintf(sendtr, "%s\n", getstr);
			write(TEST_PORT, sendtr, 256);
			memset(getstr, 0, 256);
		}
	}
}
#endif


extern  float 	AtRH_bak;				//湿度值备份
extern	float 	AtTEMP_bak;				//温度值备份

/*
 *  把探测到的温湿度数据在指定的物件上显示出来
 *	name 温湿度显示物件名称
 *	mode 温湿度显示模式 =0湿度  =1温度
 */
void Display_Temp_Dehu(uint8* name,uint8 mode )
{
	uint8 textbuf[40];
	uint8 textbuf1[40];
	if(mode ==1)
	{
		sprintf(textbuf,"%2.0f°C",AtTEMP_bak);
		sprintf(textbuf1,"室温%2.0f°C",AtTEMP_bak);
		//printf("温度 ：%s\n",textbuf);
		
		ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, name);
		ituTextSetString(text, textbuf1);

		ITUText* text1 = (ITUText*)ituSceneFindWidget(&theScene, "airFristTempText");
		ituTextSetString(text1, textbuf);
	}
	else if(mode == 0)
	{
		//sprintf(textbuf,"%2.0f%%RH",AtRH_bak);
		sprintf(textbuf,"%2.0f%%",AtRH_bak);
		//printf("湿度 ：%s\n",textbuf);
		
		ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, name);
		ituTextSetString(text, textbuf);
	}

}
void ExternalUart1ProcessInit(void)
{
    lightLayer = ituSceneFindWidget(&theScene, "lightLayer");
    assert(lightLayer);

	ITUCheckBox* checkbox = (ITUCheckBox*)ituSceneFindWidget(&theScene, "lightReadingCheckBox");

   // buttonCoverFlow = ituSceneFindWidget(&theScene, "buttonCoverFlow");
   // assert(buttonCoverFlow);
}

void ExternalUart1Init(void)
{
    struct mq_attr qattr;

    qattr.mq_flags = 0;
    qattr.mq_maxmsg = EXT_MAX_UART1_QUEUE_SIZE;
    qattr.mq_msgsize = sizeof(ExternalEvent);

    extuart1InQueue = mq_open("externaluart1_in", O_CREAT | O_NONBLOCK, 0644, &qattr);
    assert(extuart1InQueue != -1);

    extuart1OutQueue = mq_open("externaluart_out", O_CREAT | O_NONBLOCK, 0644, &qattr);
    assert(extuart1OutQueue != -1);

    extuartQuit = false;

}

void ExternalUart1Exit(void)
{
    extuartQuit = true;
    
}


int ExternalUart1Receive(ExternalEvent* ev)
{
    assert(ev);

    if (extuartQuit)
        return 0;

    if (mq_receive(extuart1InQueue, (char*)ev, sizeof(ExternalEvent), 0) > 0)
        return 1;

    return 0;
}

int ExternalUart1Send(ExternalEvent* ev)
{
    assert(ev);

    if (extuartQuit)
        return -1;
	
    return mq_send(extuart1OutQueue, (char*)ev, sizeof(ExternalEvent), 0);
}


