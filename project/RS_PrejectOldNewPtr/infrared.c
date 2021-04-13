#include <sys/ioctl.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "ite/ite_usbex.h"
#include "config.h"
#include "ite/itp.h"
#include "ite/itu.h"
#include "itu_private.h"

#include <pthread.h>
#include "openrtos/FreeRTOS.h"
#include "openrtos/task.h"

#include "ctrlboard.h"

#include "infrared.h"

void infrared_measure(void)
{
	
	
	if(ithGpioGet(INFRARED_GPIO))
		{
			if(s_InductionTCB.bLock_LEDShift_flag == true)
			{
				s_InductionTCB.bLock_LEDShift_flag = false;

				//if(s_InductionTCB.vCharLed_Status == false)
				{
					#if BRIGHT_OFF_DARK
					 ScreenSetBrightness(BRIGHT_VALUE_MAX);		//brightness ,the range is 0-9
					#else
					ioctl(ITP_DEVICE_BACKLIGHT, ITP_IOCTL_ON, NULL);
					#endif
					
					s_InductionTCB.vCharLed_DelayOff_cnt=CharLedOn_TIME;//重置字灯延时关掉的时间
					
					s_InductionTCB.bStatus_flag=true;
					s_InductionTCB.vCharLed_Status=true;				//字灯渐亮

					printf("infrared hight level have person !\n");
					
				}
			}
		}
		else
		{
			if(s_InductionTCB.bLock_LEDShift_flag != true)
			{
				s_InductionTCB.bLock_LEDShift_flag = true;

				//if(s_InductionTCB.vCharLed_Status == false)
				{
					#if BRIGHT_OFF_DARK
					 ScreenSetBrightness(BRIGHT_VALUE_MAX);		//brightness ,the range is 0-9
					#else
					ioctl(ITP_DEVICE_BACKLIGHT, ITP_IOCTL_ON, NULL);
					#endif
					
					s_InductionTCB.vCharLed_DelayOff_cnt=CharLedOn_TIME;//重置字灯延时关掉的时间
					
					s_InductionTCB.bStatus_flag=true;
					s_InductionTCB.vCharLed_Status=true;				//字灯渐亮

					printf("infrared low level have person !\n");
				}
			}
		}

		
}

void* infrared_fun(void* arg)
{
	ithGpioSetIn(INFRARED_GPIO);
	s_InductionTCB.vCharLed_DelayOff_cnt=CharLedOn_TIME;
	
	while(1)
	{
		infrared_measure();

		//printf("test infrared finish!\n");

//		printf(" s_InductionTCB.vCharLed_DelayOff_cnt = %d \n",s_InductionTCB.vCharLed_DelayOff_cnt);
//		printf(" s_InductionTCB.vCharLed_Status = %d \n",s_InductionTCB.vCharLed_Status);
		if(s_InductionTCB.vCharLed_Status == true){
			if(--s_InductionTCB.vCharLed_DelayOff_cnt <= 0)
			{
				ithEnterCritical();
				s_InductionTCB.vCharLed_DelayOff_cnt = 0;
				s_InductionTCB.vCharLed_Status = false;
				printf("infrared time finish! screen will off\n");
				
				#if BRIGHT_OFF_DARK
				 ScreenSetBrightness(BRIGHT_VALUE_MIN);		//brightness ,the range is 0-9
				#else
				ioctl(ITP_DEVICE_BACKLIGHT, ITP_IOCTL_OFF, NULL);
				#endif
				ithExitCritical();
			}

		}
		usleep(500000);
	}

}

void infrared_init(void)
{
	pthread_t task;

	pthread_create(&task, NULL, infrared_fun, NULL);
}

