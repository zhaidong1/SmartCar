#ifndef __MOTOR_H
#define __MOTOR_H	 

#include "sys.h"

#define PWMA1   TIM4->CCR1  
#define PWMA2   TIM4->CCR2 

#define PWMB1   TIM4->CCR3  
#define PWMB2   TIM4->CCR4
#define MAX_SPEED 1000


void MOTOR_Init(void);//≥ı ºªØ
void MOTOR_loop(void);
void MOTOR_setLeftPwm(int PWM);
void MOTOR_setRightPwm(int PWM);
		 				    
#endif
