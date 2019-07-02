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



//�������ȼ�
#define START_TASK_PRIO		1
//�����ջ��С	
#define START_STK_SIZE 		128 //ʵ�ʷ������128 * 4���ֽ�
//������
extern TaskHandle_t StartTask_Handler;
//������
void start_task(void *pvParameters);


//�������ȼ�
#define LOGICAL_TASK_PRIO		2
//�����ջ��С	(128 * 8)
#define LOGICAL_STK_SIZE 		50
//������
extern TaskHandle_t LOGICALTask_Handler;
//������
void Logical_task(void *pvParameters);


//�������ȼ�
#define SERIAL_TASK_PRIO	3
//�����ջ��С	
#define SERIAL_STK_SIZE 	50  
//������
extern TaskHandle_t SerialTask_Handler;
//������
void buzzer_task(void *pvParameters);			   


//�������ȼ�
#define EXCEPTION_TASK_PRIO		4
//�����ջ��С	
#define EXCEPTION_STK_SIZE 		50  
//������
extern TaskHandle_t EXCEPTIONTask_Handler;
//������
void Exception_task(void *pvParameters);		
		
#endif
