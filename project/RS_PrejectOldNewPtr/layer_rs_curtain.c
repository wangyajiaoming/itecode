#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "scene.h"
#include "ctrlboard.h"

#include "ite/itp.h"
#include <mqueue.h>
#include "uart1.h"

#include "SDL/SDL.h"

bool CheckCurtainButtonOnPress(ITUWidget* widget, char* param)
{
	ITUButton* btn = (ITUButton*)widget;
//	printf("%s: %s\n", __FUNCTION__, param);
	//int value = atoi(param);
	int i;
	printf("%s\n",widget->name);
	for(i=0;i<sizeof(relay)/sizeof(relay[0]);i++)
	{
		if(strcmp(widget->name ,relay[i].ui_name) == 0)
		{
			s_newpro.vType 	 = 	relay[i].m_type;
			s_newpro.vAddr 	 = 	relay[i].m_addr;
			s_newpro.vPort_H =  relay[i].port>>8;
			s_newpro.vPort_L =  relay[i].port;
			s_newpro.vData_H =  0x00;
			s_newpro.vData_L =  0x01;

//			Uart1_Tx_relay();
			s_uart.send_Relaycmd_flag = true;

			break;
		}

	}
	return true;
}




/* widgets:
curtainLayer
Background20
Button6
Button5
Button4
Button2
Button3
Button1
Button21
*/

