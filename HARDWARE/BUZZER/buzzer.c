#include "buzzer.h"
#include "delay.h"


/**************************************************************************
函数功能：LED IO初始化
入口参数：无
返回  值：无 
**************************************************************************/
void BUZZER_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能PB,PE端口时钟 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	    		 	 //LED1-->PE.5 端口配置, 推挽输出
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOA,GPIO_Pin_8); 									 //PE.5 输出高 
}


void BUZZER_loop(void)
{
	BUZZER0 = ~BUZZER0;
}
