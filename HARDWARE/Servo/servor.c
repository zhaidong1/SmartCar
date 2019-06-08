#include "servor.h"
//#include "usart.h"
#include "delay.h"
#include "common.h"
u8 count1;				 //ÿ����������8·����Ⱥ�ֵ����
extern unsigned int S_PWM;


void Servor_GPIO_Config(void)	
{
  GPIO_InitTypeDef GPIO_InitStructure;	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
}
/************************GPIO��ƽ��ת����1*****************************************/ 

void Flip_GPIO_One(void)
{
	switch(count1)								 //��20ms�Ķ���������ڷֳ�8�ݣ�ÿ2.5ms����һ�������ת
	{  											      //ÿ����ʱ������8·�����ת��3����ʱ������24·�����ת
		case 1: 
			 TIM2->ARR=S_PWM;				 //����һ�����������ֵ��ֵ����ʱ��2			
    	 GPIO_SetBits(GPIOA,GPIO_Pin_11);  //ͬʱ���߿��ƶ��1�����ŵĵ�
			 break;
		
		case 2:
   	    TIM2->ARR=20000-S_PWM; 		 //��2.5ms��ȥPWM����ֵ�����ݸ�ֵ��ʱ��2
				GPIO_ResetBits(GPIOA,GPIO_Pin_11);//ͬʱ���Ϳ��ƶ��1���ŵĵ�ƽ 
		    count1=0;
				break;							 //���ƶ��1��������ʣ��20ms-CPM[0]ʱ���ڽ�һֱ���ֵ͵�ƽ�����1����CPWMֵת��
		
		default:break;
	}	
}

/************************������ƺ���1*********************************************/
void Servo1(void)
{		
	count1++; 
	Flip_GPIO_One();						 //��תIO��ƽ

}


