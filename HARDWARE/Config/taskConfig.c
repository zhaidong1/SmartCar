#include "taskConfig.h"

/*
*外部定义task区域，在此处定义全局变量在main中引用
*/
TaskHandle_t StartTask_Handler;
TaskHandle_t LED0Task_Handler;
TaskHandle_t BUZZERTask_Handler;
TaskHandle_t STEERTask_Handler;

void system_config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4	 	 
	delay_init();	
	LED_Init();	      //LED 初始化函数
	BUZZER_Init();
	STEER_Init();
}

//开始任务任务函数
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           						//进入临界区	
	//动态创建函数
    xTaskCreate((TaskFunction_t )led0_task,     //指向任务函数
                (const char*    )"led0_task",   //任务函数名称
                (uint16_t       )LED0_STK_SIZE, //申请堆栈大小
                (void*          )NULL,					//传递给任务函数参数
                (UBaseType_t    )LED0_TASK_PRIO,//优先级
                (TaskHandle_t*  )&LED0Task_Handler); //任务句柄，创建成功的标识，存返回创建成功的标志
								
    xTaskCreate((TaskFunction_t )buzzer_task,     
                (const char*    )"buzzer_task",   
                (uint16_t       )BUZZER_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )BUZZER_TASK_PRIO,
                (TaskHandle_t*  )&BUZZERTask_Handler);      

    xTaskCreate((TaskFunction_t )steer_task,     
                (const char*    )"steer_task",   
                (uint16_t       )STEER_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )STEER_TASK_PRIO,
                (TaskHandle_t*  )&STEERTask_Handler);     
								
    vTaskDelete(StartTask_Handler); 					 //删除当前任务，因为开始任务的任务是创建其他任务所以创建完成就删除。
    taskEXIT_CRITICAL();            					 //退出临界区
}

void led0_task(void *pvParameters)
{
    while(1)
    {
			LED_loop();
			vTaskDelay(500);                         //系统的相对延时，也就是从LED_loop开始，之后延时500ms，而绝对延时是整个while循环是500ms
    }
}   

//BUZZER任务函数
void buzzer_task(void *pvParameters)
{
    while(1)
    {
			//BUZZER_loop();
			vTaskDelay(500);
    }
}

//STEER任务函数
void steer_task(void *pvParameters)
{
    while(1)
    {
			//STEER_loop();
			uint16_t a = 0;
			a = 20000 * 0.025;     //在正方向最右侧
			TIM_SetCompare4(TIM1,a);	
			vTaskDelay(500);
			a = 20000 * 0.075;     //在正方向最右侧
			TIM_SetCompare4(TIM1,a);	
			vTaskDelay(500);
			a = 20000 * 0.125;
			TIM_SetCompare4(TIM1,a);	
			vTaskDelay(500);
    }
}

