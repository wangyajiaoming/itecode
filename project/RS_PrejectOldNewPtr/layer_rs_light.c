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



extern uint8 CheckSum_XOR(uint8 *p,int len);


extern int ExternalSend(ExternalEvent* ev);
extern int ExternalReceive(ExternalEvent* ev);

char stri[20];

#if Rs_NewOldprotocol_Shift
bool CheckLightCheckBoxOnPress(ITUWidget* widget, char* param)
{
	ITUCheckBox* checkbox = (ITUCheckBox*)widget;
	if(checkbox == NULL)	return true;
	printf("%s: %s\n", __FUNCTION__, param);
	//int value = atoi(param);
	int i;
	for(i = 0;i<(sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++){
		
		if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para1) == 0){
			s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
			s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
			//s_newpro.vPort_H =  relay[i*4+1]>>8;
			
			if(s_newpro.vType == rs_panle)		//面板
			{
				s_newpro.vPort_H =  0x00;
				s_newpro.vPort_L =  ModuleUI_tmp[i].port & 0xFF;

				s_newpro.vData_H =  0x00;
				s_newpro.vData_L = 0x01;	//按下
			}
			else if(s_newpro.vType == rs_relay)	//继电器
			{
				s_newpro.vPort_H =  ModuleUI_tmp[i].port>>8;
				s_newpro.vPort_L =  ModuleUI_tmp[i].port;
				
				s_newpro.vData_H =  0x00;

				if (ituCheckBoxIsChecked(checkbox))
				{
					s_newpro.vData_L = 0x01;
				}
				else
				{
					s_newpro.vData_L = 0x00;
				}
			}
		
			s_uart.send_Relaycmd_flag = true;
			
		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para2) == 0){

		}

	}

	return true;
}

bool DimLightTrackBarOnChanged(ITUWidget* widget, char* param)
{
	 SDL_Event   ev;
	uint8 value;
	int i;
	printf("%s: %s\n", __FUNCTION__, param);
    value = atoi(param);
	
	//SDL_Delay(250);		//延时一段时间不然发的太快
	
	for(i = 0;i<(sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++){
		if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para1) == 0){//开关

			ITUCheckBox* checkbox = (ITUCheckBox*)widget;
			
			s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
			s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
			s_newpro.vPort_H =	ModuleUI_tmp[i].port >> 8;
			s_newpro.vPort_L =	ModuleUI_tmp[i].port & 0xFF;
			if (ituCheckBoxIsChecked(checkbox)){
				s_newpro.vData_H =  0x01;
				s_newpro.vData_L =  0x00;	
			}
			else{
				s_newpro.vData_H =  0x00;
				s_newpro.vData_L =  0x00;
			}
				
//			send_dimmer_relay_flag = true;
//			send_dimmer_delay_cnt = 0;
			s_uart.send_Relaycmd_flag = true;
			break;
			
		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para2) == 0){//滑动

			s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
			s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
			s_newpro.vPort_H =	ModuleUI_tmp[i].port >> 8;
			s_newpro.vPort_L =	ModuleUI_tmp[i].port & 0xFF;
			s_newpro.vData_H =  0x06;
			if(value <= 100)
			s_newpro.vData_L =  value;
			else
			s_newpro.vData_L =  100;
			
			send_dimmer_relay_flag = true;
			send_dimmer_delay_cnt = 0;
			break;
		}

	}
	
	
	 return true;
}


#else

bool CheckLightCheckBoxOnPress(ITUWidget* widget, char* param)
{
	ITUCheckBox* checkbox = (ITUCheckBox*)widget;
	printf("%s: %s\n", __FUNCTION__, param);
	//int value = atoi(param);
	int i;
	for(i = 0;i<(sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++){
		if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para1) == 0){
			tx_Oldrelay_value = ((ModuleUI_tmp[i].m_addr + 1)*8 + ModuleUI_tmp[i].port&0xFF);

			if (ituCheckBoxIsChecked(checkbox))
			{
				tx_Oldrelay_value |= 0x80;
			}
			else
			{
				tx_Oldrelay_value &= ~0x80;
			}

			s_uart.send_Relaycmd_flag = true;
			
		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para2) == 0){

		}

	}

	return true;
}

bool DimLightTrackBarOnChanged(ITUWidget* widget, char* param)
{
	 SDL_Event   ev;
	uint8 value;
	int i;
	printf("%s: %s\n", __FUNCTION__, param);
    value = atoi(param);
	
	//SDL_Delay(250);		//延时一段时间不然发的太快
	
	for(i = 0;i<(sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++){
		if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para1) == 0){//开关
			s_uart_dim.id = ((ModuleUI_tmp[i].m_addr - 1)*4 + ModuleUI_tmp[i].port&0xFF);
			ITUCheckBox* checkbox = (ITUCheckBox*)widget;
			if (ituCheckBoxIsChecked(checkbox)){
				s_uart_dim.cmd = 0x01;
				s_uart_dim.value = 90;
			}
			else{
				s_uart_dim.cmd = 0x00;
				s_uart_dim.value = 90;
			}
				
			send_dimmer_relay_flag = true;
			send_dimmer_delay_cnt = 0;
			break;
			
		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para2) == 0){//滑动
			s_uart_dim.id = ((ModuleUI_tmp[i].m_addr - 1)*4 + ModuleUI_tmp[i].port&0xFF);
			if(value >  0){
				s_uart_dim.cmd = 0x06;
				s_uart_dim.value = value;
			}
			else{
				s_uart_dim.cmd = 0x00;
				s_uart_dim.value = value;
			}

			send_dimmer_relay_flag = true;
			send_dimmer_delay_cnt = 0;
			break;
		}

	}
	
	
	 return true;
}

#endif

bool LightControlOnEnter(ITUWidget* widget, char* param)
{
	if(!lightReadingCheckBox)
	{
		lightReadingCheckBox = (ITUCheckBox*)ituSceneFindWidget(&theScene, "lightReadingCheckBox");
        assert(lightReadingCheckBox);

	}

	return true;
}




