#ifndef __TASKCONFIG_H
#define __TASKCONFIG_H	 

#include "sys.h"
#include "led.h"
#include "buzzer.h"
#include "FreeRTOS.h"
#include "task.h"
#include "delay.h"
void system_config(void);


//�������ȼ�
#define START_TASK_PRIO		1
//�����ջ��С	
#define START_STK_SIZE 		128  //ʵ�ʷ������128 * 4���ֽ�
//������
extern TaskHandle_t StartTask_Handler;
//������
void start_task(void *pvParameters);



//�������ȼ�
#define LED0_TASK_PRIO		2
//�����ջ��С	
#define LED0_STK_SIZE 		50  
//������
extern TaskHandle_t LED0Task_Handler;
//������
void led0_task(void *pvParameters);



//�������ȼ�
#define BUZZER_TASK_PRIO		3
//�����ջ��С	
#define BUZZER_STK_SIZE 		50  
//������
extern TaskHandle_t BUZZERTask_Handler;
//������
void buzzer_task(void *pvParameters);			    
					
					
				
#endif
