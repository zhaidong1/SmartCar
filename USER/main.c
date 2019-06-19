#include "stm32f10x.h"	    					
#include "delay.h"					
#include "led.h"
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"

int main(void)
{   
	system_config();
	xTaskCreate((TaskFunction_t )start_task,            //������
							(const char*    )"start_task",          //��������
							(uint16_t       )START_STK_SIZE,        //�����ջ��С
							(void*          )NULL,                  //���ݸ��������Ĳ���
							(UBaseType_t    )START_TASK_PRIO,       //�������ȼ�
							(TaskHandle_t*  )&StartTask_Handler);   //������              
	vTaskStartScheduler();                              //�������������
} 

