#ifndef  _INFRARED_
#define	 _INFRARED_

#define  INFRARED_GPIO	29			//红外感应引脚
	
#define CharLedOn_TIME   20			//感应背光开时间	20/2=10S

#define BRIGHT_OFF_DARK		1		//屏亮度变暗或关闭       	=1变暗  	=0关闭

#define BRIGHT_VALUE_MIN	0			//屏亮度值 只能取0-9
#define BRIGHT_VALUE_MAX	8			//屏亮度值 只能取0-9

#define P_FMSCtrl_status	

typedef unsigned char  uchar;
typedef unsigned int   uint;

typedef struct _tag_Induction
{
	uchar vTx_CharLed_Status;
	uchar bLock_LEDShift_flag;
	uchar vCharLed_Status;
	uchar bStatus_flag;
	unsigned char  vCharLed_DelayOff_cnt;
}s_Induction;

s_Induction s_InductionTCB;



#endif  /*_INFRARED_*/
