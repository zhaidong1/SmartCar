#include "taskConfig.h"

/*
*外部定义task区域，在此处定义全局变量在main中引用
*/
moveBase movebase;
TaskHandle_t StartTask_Handler;
TaskHandle_t LogicalTask_Handler;
TaskHandle_t SerialTask_Handler;
TaskHandle_t ExceptionTask_Handler;

/*
*
*业务逻辑处理区
*/
void LogicalTask_Init(void)
{
	LED_Init();	      //LED 初始化函数
//	BUZZER_Init();
//	STEER_Init();
//	MOTOR_Init();
//	Ecoder_Init(&movebase.ecoder);
//	OLED_Init();	
//	PMU_Init(&movebase.pmu);
//	PS2_Init(&movebase.PS2);
	USART1_Init(115200);
}
void Logical_task(void *pvParameters)
{
    while(1)
    {
			LED_loop();
//			BUZZER_loop();
//			STEER_loop();
//			Ecoder_Loop();
//			MOTOR_loop();
//			PMU_Loop(&movebase.pmu);
//			PS2_loop(&movebase.PS2);
			myprintfUSART1("PS:%d,%d,%d\r\n",movebase.PS2.LX_AD,movebase.PS2.LY_AD,movebase.PS2.key);
			//myprintfUSART1("Vol:%d\r\n",movebase.pmu.Voltage);
			vTaskDelay(50);
    }
} 
/*
*协议处理区
*/
void SerialTask_Init(void)
{
	
}
void Serial_task(void *pvParameters)
{
    while(1)
    {
			//STEER_loop();
			vTaskDelay(500);
    }
}
/*
*异常处理区
*/
void ExceptionTask_Init(void)
{
	
}

//BUZZER任务函数
void Exception_task(void *pvParameters)
{
    while(1)
    {
			vTaskDelay(500);
    }
}

void system_config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4	 	 
	delay_init();	
	LogicalTask_Init();
	SerialTask_Init();
	ExceptionTask_Init();
}

//开始任务任务函数
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           						//进入临界区	
	//动态创建函数
    xTaskCreate((TaskFunction_t )Logical_task,     //指向任务函数
                (const char*    )"Logical_task",   //任务函数名称
                (uint16_t       )LOGICAL_STK_SIZE, //申请堆栈大小
                (void*          )NULL,						 //传递给任务函数参数
                (UBaseType_t    )LOGICAL_TASK_PRIO,//优先级
                (TaskHandle_t*  )&LogicalTask_Handler); //任务句柄，创建成功的标识，存返回创建成功的标志
								
//    xTaskCreate((TaskFunction_t )Serial_task,     
//                (const char*    )"Serial_task",   
//                (uint16_t       )SERIAL_STK_SIZE, 
//                (void*          )NULL,
//                (UBaseType_t    )SERIAL_TASK_PRIO,
//                (TaskHandle_t*  )&SerialTask_Handler);      

//    xTaskCreate((TaskFunction_t )Exception_task,     
//                (const char*    )"Exception_task",   
//                (uint16_t       )EXCEPTION_STK_SIZE, 
//                (void*          )NULL,
//                (UBaseType_t    )EXCEPTION_TASK_PRIO,
//                (TaskHandle_t*  )&ExceptionTask_Handler);     
								
    vTaskDelete(StartTask_Handler); 					 //删除当前任务，因为开始任务的任务是创建其他任务所以创建完成就删除。
    taskEXIT_CRITICAL();            					 //退出临界区
}



