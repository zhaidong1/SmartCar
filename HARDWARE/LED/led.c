#include "led.h"
#include "delay.h"


/**************************************************************************
函数功能：LED IO初始化
入口参数：无
返回  值：无 
**************************************************************************/
void LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能PB,PE端口时钟 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	    		 	//LED1-->PE.5 端口配置, 推挽输出
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		//推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);	  				    //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOA,GPIO_Pin_4); 									    //PE.5 输出高 
}

void LED_loop(void)
{
	 LED0=~LED0;
}
