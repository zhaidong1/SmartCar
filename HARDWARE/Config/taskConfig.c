#include "taskConfig.h"

/*
*�ⲿ����task�����ڴ˴�����ȫ�ֱ�����main������
*/
moveBase movebase;
TaskHandle_t StartTask_Handler;
TaskHandle_t LogicalTask_Handler;
TaskHandle_t SerialTask_Handler;
TaskHandle_t ExceptionTask_Handler;

/*
*
*ҵ���߼�������
*/
void LogicalTask_Init(void)
{
	LED_Init();	      //LED ��ʼ������
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
*Э�鴦����
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
*�쳣������
*/
void ExceptionTask_Init(void)
{
	
}

//BUZZER������
void Exception_task(void *pvParameters)
{
    while(1)
    {
			vTaskDelay(500);
    }
}

void system_config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4	 	 
	delay_init();	
	LogicalTask_Init();
	SerialTask_Init();
	ExceptionTask_Init();
}

//��ʼ����������
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           						//�����ٽ���	
	//��̬��������
    xTaskCreate((TaskFunction_t )Logical_task,     //ָ��������
                (const char*    )"Logical_task",   //����������
                (uint16_t       )LOGICAL_STK_SIZE, //�����ջ��С
                (void*          )NULL,						 //���ݸ�����������
                (UBaseType_t    )LOGICAL_TASK_PRIO,//���ȼ�
                (TaskHandle_t*  )&LogicalTask_Handler); //�������������ɹ��ı�ʶ���淵�ش����ɹ��ı�־
								
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
								
    vTaskDelete(StartTask_Handler); 					 //ɾ����ǰ������Ϊ��ʼ����������Ǵ��������������Դ�����ɾ�ɾ����
    taskEXIT_CRITICAL();            					 //�˳��ٽ���
}



