#ifndef  _INFRARED_
#define	 _INFRARED_

#define  INFRARED_GPIO	29			//�����Ӧ����
	
#define CharLedOn_TIME   20			//��Ӧ���⿪ʱ��	20/2=10S

#define BRIGHT_OFF_DARK		1		//�����ȱ䰵��ر�       	=1�䰵  	=0�ر�

#define BRIGHT_VALUE_MIN	0			//������ֵ ֻ��ȡ0-9
#define BRIGHT_VALUE_MAX	8			//������ֵ ֻ��ȡ0-9

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
