#include "led.h"
#include "delay.h"


/**************************************************************************
�������ܣ�LED IO��ʼ��
��ڲ�������
����  ֵ���� 
**************************************************************************/
void LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//ʹ��PB,PE�˿�ʱ�� 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	    		 	//LED1-->PE.5 �˿�����, �������
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		//�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);	  				    //������� ��IO���ٶ�Ϊ50MHz
 GPIO_SetBits(GPIOA,GPIO_Pin_4); 									    //PE.5 ����� 
}

void LED_loop(void)
{
	 LED0=~LED0;
}
