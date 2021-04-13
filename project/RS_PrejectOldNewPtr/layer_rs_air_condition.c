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
#include "ite/itu.h"


char stri[20];


bool AirOnEnter(ITUWidget* widget, char* param)
{
	int i;
	
	//保留
 	return true;
}


bool AirWindTrackBarOnChanged(ITUWidget* widget, char* param)
{

	uint8 value,i;
	printf("%s: %s\n", __FUNCTION__, param);
	
	value = atoi(param);
	
//	for(i=0;i<sizeof(relay)/8;i++)
//	{
//		memset(stri,0,16);
//		itoa(relay[i*4 +2],stri,16);
//		
//		if(strcmp(widget->name ,stri) == 0)
//		{
//			s_newpro.vType 	 = 	relay[i*4+0]>>8;
//			s_newpro.vAddr 	 = 	relay[i*4+0]&0xFF;
//			s_newpro.vPort_H =  relay[i*4+1]>>8;
//			s_newpro.vPort_L =  relay[i*4+1];
//			s_newpro.vData_H =  0x00;
//
//			s_newpro.vData_L = value;
//
//			send_dimmer_relay_flag = true;
//			send_dimmer_delay_cnt = 0;
//				
//			break;
//		}
//
//	}
	
	return true;
}

bool AirTempMeterOnChanged(ITUWidget* widget, char* param)
{

	uint8 i;
	
	printf("%s: %s\n", __FUNCTION__, param);
	
	value1 = atoi(param)*10;

	if(value1_bak != value1)	//在这加判断是因为接收到串口设置温度数据后会进这里导致一直发数据
	{
		value1_bak = value1;
	}
	else{
		return;
	}
	printf("value1 = %d\n",value1);
	printf("value1_bak = %d\n",value1_bak);
//	for(i=0;i<sizeof(relay)/8;i++)
//	{
//		memset(stri,0,16);
//		itoa(relay[i*4 +2],stri,16);
//		
//		if(strcmp(widget->name ,stri) == 0)
//		{
//			s_newpro.vType 	 = 	relay[i*4+0]>>8;
//			s_newpro.vAddr 	 = 	relay[i*4+0]&0xFF;
//			s_newpro.vPort_H =  relay[i*4+1]>>8;
//			s_newpro.vPort_L =  relay[i*4+1];
//			s_newpro.vData_H =  value1>>8;
//
//			s_newpro.vData_L = value1;
//		
//				send_dimmer_relay_flag = true;
//				send_dimmer_delay_cnt = 0;
//				
//				printf("air setTemp  change!\n");
//			break;
//		}
//
//	}
	
	return true;
}

bool AirModeMeterOnChanged(ITUWidget* widget, char* param)
{

	uint8 value,i;
	uint8 dest[20];
	printf("%s: %s\n", __FUNCTION__, param);
	
	value = atoi(param);				//将字符串转换为整形数
	
//	for(i=0;i<sizeof(relay)/8;i++)
//	{
//		memset(stri,0,16);
//		memset(dest,0,16);
//		
//		itoa(relay[i*4 +2],stri,16);	//将整形转换为字符串
//		strncpy(dest,widget->name,4);	//在字符串中截取指定长度的字符来处理
//		
//		if(strcmp(dest ,stri) == 0)		//比较两个字符串是否相同
//		{
//			s_newpro.vType 	 = 	relay[i*4+0]>>8;
//			s_newpro.vAddr 	 = 	relay[i*4+0]&0xFF;
//			s_newpro.vPort_H =  relay[i*4+1]>>8;
//			s_newpro.vPort_L =  relay[i*4+1];
//			s_newpro.vData_H =  0x00;
//
//			s_newpro.vData_L = 0x01<<value;
//
//			Uart1_Tx_relay();
//			//send_dimmer_relay_flag = true;
//			//send_dimmer_delay_cnt = 0;
//				
//			break;
//		}
//
//	}

	return true;
}


bool ButtonAirOpwerButtonOnPress(ITUWidget* widget, char* param)
{
    // TODO: IMPLEMENT
    printf("%s: %s\n", __FUNCTION__, param);
    return true;
}

bool AirSetButtonOnPress(ITUWidget* widget, char* param)
{
	unsigned char value,tmp;
	unsigned char ptr[20];
	int i;
    printf("%s: %s\n", __FUNCTION__, param);
	value = atoi(param);
#if !Rs_NewOldprotocol_Shift	
	for(i = 0;i<(sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++)
		{
			if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para1) == 0)
			{
				switch(ModuleUI_tmp[i].port)
				{
					case 0x0001:	//开关
					{
						ITUCheckBox* checkbox = (ITUCheckBox*)widget;

						sys_air.id = ModuleUI_tmp[i].m_addr;
						
						if (ituCheckBoxIsChecked(checkbox))
						{
							sys_air.air[sys_air.id -1].wind = sys_air.air[sys_air.id -1].wind_bak;
						}
						else
						{
							sys_air.air[sys_air.id -1].wind_bak = sys_air.air[sys_air.id -1].wind;
							sys_air.air[sys_air.id -1].wind = 0;
						}
	
						s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0004:	//设置温度
					{
						sys_air.id = ModuleUI_tmp[i].m_addr;
						ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_txt);
						memset(ptr,0,sizeof(ptr));
			
						tmp = (atoi(ituTextGetString(text))>=16)? (atoi(ituTextGetString(text)) - 16):0;
						if(++tmp > 16) tmp = 16;

						tmp += 16;
						sprintf(ptr,"%d",tmp);
						ituTextSetString(text, ptr);
	
						sys_air.air[sys_air.id -1].setTemprature = tmp;
						
	
						s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0005:	//风速 - 要在UI物件中写入参数一便传给处理函数获得value
					{
						sys_air.id = ModuleUI_tmp[i].m_addr;
						tmp = value;
						if(tmp ==  sys_air.air_bak[sys_air.id -1].wind ) continue;
						sys_air.air[sys_air.id -1].wind = tmp;
						
						s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0006:	//模式 - 要在UI物件中写入参数一便传给处理函数获得value
					{
						sys_air.id = ModuleUI_tmp[i].m_addr;
						tmp = value -1 ;
						if(tmp ==  sys_air.air_bak[sys_air.id -1].season ) continue;
						if(value == 1){ //夏天
							sys_air.air[sys_air.id -1].season = 0;
						}
						else if(value == 2){//冬天
							sys_air.air[sys_air.id -1].season = 1;
						}
							
						s_uart.send_Aircmd_flag = true;
					}
						break;
					default:
						break;
				}
				break;
			}
			else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para2) == 0)
			{
				switch(ModuleUI_tmp[i].port)
				{
					case 0x0001:	//开关
					{
						ITUCheckBox* checkbox = (ITUCheckBox*)widget;

						sys_air.id = ModuleUI_tmp[i].m_addr;
						
						if (ituCheckBoxIsChecked(checkbox))
						{
							sys_air.air[sys_air.id -1].wind = sys_air.air[sys_air.id -1].wind_bak;
						}
						else
						{
							sys_air.air[sys_air.id -1].wind_bak = sys_air.air[sys_air.id -1].wind;
							sys_air.air[sys_air.id -1].wind = 0;
						}
	
						s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0004:	//设置温度
					{
						sys_air.id = ModuleUI_tmp[i].m_addr;
						ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_txt);
						memset(ptr,0,sizeof(ptr));
			
						tmp = (atoi(ituTextGetString(text))>=16)? (atoi(ituTextGetString(text)) - 16):0;
						if(tmp > 0) tmp -=1;

						tmp += 16;
						sprintf(ptr,"%d",tmp);
						ituTextSetString(text, ptr);
	
						sys_air.air[sys_air.id -1].setTemprature = tmp;
						
						s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0005:	//风速 - 要在UI物件中写入参数一便传给处理函数获得value
					{
						sys_air.id = ModuleUI_tmp[i].m_addr;
						tmp = value;
						if(tmp ==  sys_air.air_bak[sys_air.id -1].wind ) continue;
						sys_air.air[sys_air.id -1].wind = tmp;
						
						s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0006:	//模式 - 要在UI物件中写入参数一便传给处理函数获得value
					{
						sys_air.id = ModuleUI_tmp[i].m_addr;
						if(value <= 0) continue;
						tmp = value -1;
						if(tmp ==  sys_air.air_bak[sys_air.id -1].season ) continue;
						if(value == 1){ //夏天
							sys_air.air[sys_air.id -1].season = 0;
						}
						else if(value == 2){//冬天
							sys_air.air[sys_air.id -1].season = 1;
						}
							
						s_uart.send_Aircmd_flag = true;
					}
						break;
					default:
						break;
				}
				break;
			}
			else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para3) == 0)
			{
				switch(ModuleUI_tmp[i].port)
				{
					case 0x0001:	//开关
					{
						ITUCheckBox* checkbox = (ITUCheckBox*)widget;

						sys_air.id = ModuleUI_tmp[i].m_addr;
						
						if (ituCheckBoxIsChecked(checkbox))
						{
							sys_air.air[sys_air.id -1].wind = sys_air.air[sys_air.id -1].wind_bak;
						}
						else
						{
							sys_air.air[sys_air.id -1].wind_bak = sys_air.air[sys_air.id -1].wind;
							sys_air.air[sys_air.id -1].wind = 0;
						}
	
						s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0004:	//设置温度
					{
						sys_air.id = ModuleUI_tmp[i].m_addr;
						
						 printf("%s: %s\n", ModuleUI_tmp[i].ui_name_Para3, param);
						tmp = value;
						tmp += 16;
						if(tmp ==  sys_air.air_bak[sys_air.id -1].setTemprature ) continue;
						sys_air.air[sys_air.id -1].setTemprature = tmp;
						
						send_air_temp_flag = true;
						send_air_temp_cnt  = 0;
						//s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0005:	//风速 - 要在UI物件中写入参数一便传给处理函数获得value
					{
						sys_air.id = ModuleUI_tmp[i].m_addr;
						tmp = value;
						if(tmp ==  sys_air.air_bak[sys_air.id -1].wind ) continue;
						sys_air.air[sys_air.id -1].wind = tmp;
						
	
						s_uart.send_Aircmd_flag = true;
					}
						break;
					case 0x0006:	//模式 - 要在UI物件中写入参数一便传给处理函数获得value
					{
						value = atoi(param);
						if(value == 1){ //夏天
							sys_air.air[sys_air.id -1].season = 0;
						}
						else if(value == 2){//冬天
							sys_air.air[sys_air.id -1].season = 1;
						}
						sys_air.id = ModuleUI_tmp[i].m_addr;	
	
						s_uart.send_Aircmd_flag = true;
					}
						break;
					default:
						break;
				}
				break;
			}
			else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para4) == 0)
			{
				break;
			}
			else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para5) == 0)
			{
				break;
			}
	
		}
#else
	for(i = 0;i<(sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++)
	{
		if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para1) == 0)
		{
			switch(ModuleUI_tmp[i].port)
			{
				case 0x0001:	//开关
				{
					ITUCheckBox* checkbox = (ITUCheckBox*)widget;
					
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
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

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0004:	//设置温度
				{
					ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_txt);
					memset(ptr,0,sizeof(ptr));
		
					tmp = atoi(ituTextGetString(text));
					if(++tmp > 32) tmp = 32;
					sprintf(ptr,"%d",tmp);
					ituTextSetString(text, ptr);

					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  (tmp*10)>>8;
					s_newpro.vData_L =  (tmp*10)&0xFF;

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0005:	//风速
				{
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  0x00;
					s_newpro.vData_L =  0x01;

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0006:	//模式
				{
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  0x00;
					s_newpro.vData_L =  0x04;

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				default:
					break;
			}
		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para2) == 0)
		{
			switch(ModuleUI_tmp[i].port)
			{
				case 0x0001:	//开关
				{
					ITUCheckBox* checkbox = (ITUCheckBox*)widget;
					
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
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

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0004:	//设置温度
				{
					ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_txt);
					memset(ptr,0,sizeof(ptr));
		
					tmp = atoi(ituTextGetString(text));
					if(--tmp < 16) tmp = 16;
					sprintf(ptr,"%d",tmp);
					ituTextSetString(text, ptr);

					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  (tmp*10)>>8;
					s_newpro.vData_L =  (tmp*10)&0xFF;

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0005:	//风速
				{
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  0x00;
					s_newpro.vData_L =  0x02;

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0006:	//模式
				{
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  0x00;
					s_newpro.vData_L =  0x02;

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				default:
					break;
			}
		
		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para3) == 0)
		{
			switch(ModuleUI_tmp[i].port)
			{
				case 0x0001:	//开关
				{
					ITUCheckBox* checkbox = (ITUCheckBox*)widget;
					
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
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

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0004:	//设置温度
				{
					
					tmp = value;
					tmp += 16;

					if(rs_NewAir[ModuleUI_tmp[i].m_addr -1].setTemprature_bak != tmp) {
						rs_NewAir[ModuleUI_tmp[i].m_addr -1].setTemprature_bak = tmp;
					}
					else 
						return true;

					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					s_newpro.vPort_H =  ModuleUI_tmp[i].port>>8;
					//s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  (tmp*10)>>8;
					s_newpro.vData_L =  (tmp*10)&0xFF;

					send_air_temp_flag = true;
					send_air_temp_cnt  = 0;
//					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0005:	//风速
				{
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  0x00;
					s_newpro.vData_L =  0x03;

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				case 0x0006:	//模式
				{
					s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
					s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
					//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
					s_newpro.vPort_H =  0x00;
					s_newpro.vPort_L =  ModuleUI_tmp[i].port;
					s_newpro.vData_H =  0x00;
					s_newpro.vData_L =  0x08;

					s_uart.send_Relaycmd_flag = true;
				}
					break;
				default:
					break;
			}
		
		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para4) == 0)
		{

		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para5) == 0)
		{

		}

	}
#endif
	 return true;
}


bool AirSetTmpButtonOnPress(ITUWidget* widget, char* param)
{
    // TODO: IMPLEMENT
    unsigned char value,tmp;
	unsigned char ptr[20];
	int i;
    printf("%s: %s\n", __FUNCTION__, param);

	value = atoi(param);				//将字符串转换为整形数
	for(i = 0;i<(sizeof(ModuleUI_tmp)/sizeof(ModuleUI_tmp[0]));i++)
	{
		ITUText* text = (ITUText*)ituSceneFindWidget(&theScene, ModuleUI_tmp[i].ui_name_txt);
		memset(ptr,0,sizeof(ptr));
		
		if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para1) == 0)
		{
			tmp = atoi(ituTextGetString(text));
			if(++tmp > 32) tmp = 32;
			sprintf(ptr,"%d",tmp);
			ituTextSetString(text, ptr);

			s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
			s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
			//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
			s_newpro.vPort_H =  0x00;
			s_newpro.vPort_L =  ModuleUI_tmp[i].port;
			s_newpro.vData_H =  (tmp*10)>>8;
			s_newpro.vData_L =  (tmp*10)&0xFF;

			s_uart.send_Relaycmd_flag = true;
		}
		else if(strcmp(widget->name ,ModuleUI_tmp[i].ui_name_Para2) == 0)
		{
			tmp = atoi(ituTextGetString(text));
			if(--tmp < 16) tmp = 16;
			sprintf(ptr,"%d",tmp);
			ituTextSetString(text, ptr);

			s_newpro.vType 	 = 	ModuleUI_tmp[i].m_type;
			s_newpro.vAddr 	 = 	ModuleUI_tmp[i].m_addr;
			//s_newpro.vPort_H =  ModuleUI_tmp[i*4+1]>>8;
			s_newpro.vPort_H =  0x00;
			s_newpro.vPort_L =  ModuleUI_tmp[i].port;
			s_newpro.vData_H =  (tmp*10)>>8;
			s_newpro.vData_L =  (tmp*10)&0xFF;
			
			s_uart.send_Relaycmd_flag = true;
		}

	}

	
    return true;
}



