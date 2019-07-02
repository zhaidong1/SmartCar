#include "motor.h"
#include "delay.h"
#include <math.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"

void MOTOR_leftDirecton_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}	
void MOTOR_rightDirecton_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 
	 //���ø�����Ϊ�����������,���TIM3 CH3 CH4 PWM���岨��  
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_8|GPIO_Pin_9; //TIM3_CH3 //TIM3_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void MOTOR_speedInit(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 , ENABLE);
	
	TIM_TimeBaseStructure.TIM_Period = arr;							//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc;						//����������Ϊ TIMx ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 					//����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;					//�ظ��Ĵ����������Զ�����
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 				//�ڳ�ʼ�� TIMx

	
	TIM_ARRPreloadConfig(TIM4, ENABLE); //ʹ�� TIMx �� ARR �ϵ�Ԥװ�ؼĴ���
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //�������ģʽ ͨ��1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OutputNState=TIM_OutputNState_Disable;//ʹ�ܻ��������
	TIM_OCInitStructure.TIM_OCIdleState=TIM_OCIdleState_Reset; //���������״̬
	TIM_OCInitStructure.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//�����󻥲������״̬
	TIM_OCInitStructure.TIM_Pulse = 0; 							//���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
	TIM_OCInitStructure.TIM_OCNPolarity=TIM_OCNPolarity_High; //���û������������
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure); 			//�۳�ʼ������ TIMx	
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable); 	//CH1 Ԥװ��ʹ��
	
	TIM_OC2Init(TIM4, &TIM_OCInitStructure); 			//�۳�ʼ������ TIMx	
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable); 	//CH1 Ԥװ��ʹ��
	
	TIM_OC3Init(TIM4, &TIM_OCInitStructure); 			//�۳�ʼ������ TIMx	
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable); 	//CH1 Ԥװ��ʹ��
	
	TIM_OC4Init(TIM4, &TIM_OCInitStructure); 			//�۳�ʼ������ TIMx	
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable); 	//CH1 Ԥװ��ʹ��
	
	TIM_Cmd(TIM4, ENABLE); //��ʹ�� TIM2
	
	TIM_CtrlPWMOutputs(TIM4,ENABLE); //��MOE �����ʹ��
	TIM_SetAutoreload(TIM4, arr);
	TIM_SetCompare1(TIM4,0);
	TIM_SetCompare2(TIM4,0);
	TIM_SetCompare3(TIM4,0);
	TIM_SetCompare4(TIM4,0);
	return;
}
void MOTOR_Init(void)
{
	MOTOR_leftDirecton_Init();
	MOTOR_rightDirecton_Init();
	MOTOR_speedInit(7199,0);
}

/*
����500 ������˷�����ת
*/
void MOTOR_setLeftPwm(int PWM)
{
	if(PWM < 0){
		PWMA1=7200,PWMA2=7200+PWM;
//		TIM_SetCompare1(TIM4,1000);
//		TIM_SetCompare2(TIM4,1000 + PWM);
	}else{
		PWMA2=7200,PWMA1=7200-PWM;
//		TIM_SetCompare1(TIM4,1000 - PWM);
//		TIM_SetCompare2(TIM4,1000 );
	}
}
/*
����500�������������ת
*/
void MOTOR_setRightPwm(int PWM)
{
	if(PWM < 0){
		PWMB1=7200,PWMB2=7200+PWM;
//		TIM_SetCompare3(TIM4,1000);
//		TIM_SetCompare4(TIM4,1000 + PWM);
	}else{
		PWMB2=7200,PWMB1=7200-PWM;
//		TIM_SetCompare3(TIM4,1000 - PWM);
//		TIM_SetCompare4(TIM4,1000 );
	}
}

void MOTOR_setV(int Vmm)
{
	double v;
	int V;
	if(abs(Vmm) > MAX_SPEED){
		Vmm = 0;
	}
	v = (double)Vmm / 1200 * 7200;
	V = v;
	if(Vmm > 0){	
		MOTOR_setRightPwm(V);
		MOTOR_setLeftPwm(-V);
	}else if(Vmm < 0){
		MOTOR_setRightPwm(-V);
		MOTOR_setLeftPwm(V);
	}else{ 
		MOTOR_setRightPwm(0);
		MOTOR_setLeftPwm(0);
	}
}
void MOTOR_loop(void)
{
		MOTOR_setRightPwm(1000);	
		vTaskDelay(2);
		MOTOR_setLeftPwm(-1000);
		vTaskDelay(2);
	//MOTOR_setV(600);
}
