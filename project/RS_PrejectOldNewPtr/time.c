#include <sys/ioctl.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "ite/itp.h"
#include "ite/ith.h"
#include <pthread.h>
#include "openrtos/FreeRTOS.h"
#include "openrtos/task.h"

#include "uart1.h"

static int clk = 0;
static int cnt = 0;

unsigned int PalGetClock1(void)
{
    return xTaskGetTickCount();
}

unsigned long PalGetDuration1(unsigned int clock)
{
    return (xTaskGetTickCount() - clock) / portTICK_PERIOD_MS;
}

void* TestFunc_timeout(void* arg)
{
    /* Basic test*/
    int status;
    int i = 0;
    int j = 0;
    int us = 0;
    int clock = 0;

    //for (us=10000; us<=10000000; us*=10)
    for(;;)
    {
        // Interrupt test
       
        //for(i=ITH_TIMER1; i<=ITH_TIMER8; i++)
        i=6;
        {
            us = 100*1000;
            ithTimerReset(i);
            ithTimerClearIntr(i);
            ithTimerSetTimeout(i, us);
            clk = PalGetClock();
            ithTimerEnable(i);

            clock = PalGetClock1();

            while(1)
            {
                status = ithTimerGetIntrState();
                if(status & 0x7<<(i*4))
                {
                   // printf("[TIMER%d] intr gap time = %d ms status = 0x%08x \n",i+1, PalGetDuration1(clock), status);
                    //clock = PalGetClock();
					if(send_dimmer_relay_flag == true)
					{
						if(send_dimmer_delay_cnt < 10)
						{
							if(++send_dimmer_delay_cnt >=5)
							{
							 	send_dimmer_delay_cnt = 11;
								#if Rs_NewOldprotocol_Shift
								Uart1_Tx_relay();
								#else
								Uart1_Tx_Dimmer();
								#endif
								send_dimmer_relay_flag = false;
							}
						}
					}

					if(send_air_temp_flag == true)
					{
						if(send_air_temp_cnt < 10)
						{
							if(++send_air_temp_cnt >=5)
							{
							 	send_air_temp_cnt = 11;
								#if Rs_NewOldprotocol_Shift
								Uart1_Tx_relay();
								#else
								Uart1_Tx_Air1_relay();
								#endif
								send_air_temp_flag = false;
							}
						}
					}

					if(init_SYN_flag == true){	//上电同步处理
						if( ++init_SYN_cnt > 30){
							init_SYN_cnt = 0;
							init_SYN_flag = false;
							tx_Oldrelay_value = 0x00;
							s_uart.send_Relaycmd_flag = true;
						}
						
					}
					
                    break;

                }
                //clock = PalGetClock();

                usleep(200);
            }

           // printf("Timer%d leaving\n", i+1);
            ithTimerCtrlDisable(i, ITH_TIMER_EN);
            ithTimerReset(i);
            ithTimerClearIntr(i);

        }
    }
    printf("**********end***************\n");
}


void Init_Time_hander(void)
{
	pthread_t task;
   

	pthread_create(&task, NULL, TestFunc_timeout, NULL);
}

