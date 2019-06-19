#ifndef __TASKCONFIG_H
#define __TASKCONFIG_H	 

#include "sys.h"
#include "led.h"
#include "buzzer.h"
#include "FreeRTOS.h"
#include "task.h"
#include "delay.h"
void system_config(void);


//任务优先级
#define START_TASK_PRIO		1
//任务堆栈大小	
#define START_STK_SIZE 		128  //实际分配的是128 * 4个字节
//任务句柄
extern TaskHandle_t StartTask_Handler;
//任务函数
void start_task(void *pvParameters);



//任务优先级
#define LED0_TASK_PRIO		2
//任务堆栈大小	
#define LED0_STK_SIZE 		50  
//任务句柄
extern TaskHandle_t LED0Task_Handler;
//任务函数
void led0_task(void *pvParameters);



//任务优先级
#define BUZZER_TASK_PRIO		3
//任务堆栈大小	
#define BUZZER_STK_SIZE 		50  
//任务句柄
extern TaskHandle_t BUZZERTask_Handler;
//任务函数
void buzzer_task(void *pvParameters);			    
					
					
				
#endif
