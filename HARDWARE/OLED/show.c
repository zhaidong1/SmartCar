#include "show.h"
#include "oled.h"
//#include "common.h"
//#include "ps2.h"
extern int Encoder_Left,Encoder_Right;             //���ұ��������������
extern char menu;
extern u32 Motor_Pwm;
/**************************************************************************
�������ܣ�OLED��ʾ
��ڲ�������
����  ֵ����
**************************************************************************/
void oled_show(void)
{           
		                      OLED_ShowString(20,00,"Robot System");    //����������	
			                    OLED_ShowString(00,12,"MODE:");    //����ģʽ
//	  if(menu==2)   				OLED_ShowString(40,12,"Select Mode");    //PS2����ģʽ
//	  if(menu==0)           OLED_ShowString(40,12,"PS2 Control");    //PS2����ģʽ
//	  if(menu==1)           OLED_ShowString(40,12,"APP Control");    //APP����ģʽ
//	                        OLED_ShowString(0,24,"SPEED:");    //�ٶȵ�λ
//	  if(Motor_Pwm==600)    OLED_ShowString(45,24," S ");  
//	  if(Motor_Pwm==800)    OLED_ShowString(45,24," M ");  
//		if(Motor_Pwm==1000)   OLED_ShowString(45,24," H ");  
//		                      OLED_ShowString(00,36,"EncoLEFT");    //����������
//		if( Encoder_Left<0)		OLED_ShowString(80,36,"-"),
//		                      OLED_ShowNumber(95,36,-Encoder_Left,5,12);
//		else                 	OLED_ShowString(80,36,"+"),
//		                      OLED_ShowNumber(95,36, Encoder_Left,5,12);

//		                      OLED_ShowString(00,48,"EncoRIGHT");
//		if(Encoder_Right<0)	  OLED_ShowString(80,48,"-"),
//		                      OLED_ShowNumber(95,48,-Encoder_Right,5,12);
//		else               		OLED_ShowString(80,48,"+"),
//		                      OLED_ShowNumber(95,48,Encoder_Right,5,12);	


		//=============ˢ��=======================//
		OLED_Refresh_Gram();	
	}
