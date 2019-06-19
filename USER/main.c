#include "stm32f10x.h"	    					
#include "delay.h"					
#include "led.h"
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"

int main(void)
{   
	system_config();
	xTaskCreate((TaskFunction_t )start_task,            //任务函数
							(const char*    )"start_task",          //任务名称
							(uint16_t       )START_STK_SIZE,        //任务堆栈大小
							(void*          )NULL,                  //传递给任务函数的参数
							(UBaseType_t    )START_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  )&StartTask_Handler);   //任务句柄              
	vTaskStartScheduler();                              //开启任务调度器
} 

