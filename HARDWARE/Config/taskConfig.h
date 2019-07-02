#ifndef __TASKCONFIG_H
#define __TASKCONFIG_H	 

#include "sys.h"
#include "led.h"
#include "buzzer.h"
#include "FreeRTOS.h"
#include "task.h"
#include "delay.h"
#include "steer.h"
#include "motor.h"
#include "encoder.h"
#include "oled.h"
#include "pmu.h"
#include "Ps2.h"
#include "show.h"

typedef struct MoveBase_ALL{
	Ecoder ecoder;
	PMU pmu;
	PS2_para PS2;
	//uint8_t OLED_GRAM[128][8];	 
}moveBase;

extern moveBase movebase;
void system_config(void);



//任务优先级
#define START_TASK_PRIO		1
//任务堆栈大小	
#define START_STK_SIZE 		128 //实际分配的是128 * 4个字节
//任务句柄
extern TaskHandle_t StartTask_Handler;
//任务函数
void start_task(void *pvParameters);


//任务优先级
#define LOGICAL_TASK_PRIO		2
//任务堆栈大小	(128 * 8)
#define LOGICAL_STK_SIZE 		50
//任务句柄
extern TaskHandle_t LOGICALTask_Handler;
//任务函数
void Logical_task(void *pvParameters);


//任务优先级
#define SERIAL_TASK_PRIO	3
//任务堆栈大小	
#define SERIAL_STK_SIZE 	50  
//任务句柄
extern TaskHandle_t SerialTask_Handler;
//任务函数
void buzzer_task(void *pvParameters);			   


//任务优先级
#define EXCEPTION_TASK_PRIO		4
//任务堆栈大小	
#define EXCEPTION_STK_SIZE 		50  
//任务句柄
extern TaskHandle_t EXCEPTIONTask_Handler;
//任务函数
void Exception_task(void *pvParameters);		
		
#endif
