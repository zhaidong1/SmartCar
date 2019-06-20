#include "taskConfig.h"

/*
*�ⲿ����task�����ڴ˴�����ȫ�ֱ�����main������
*/
TaskHandle_t StartTask_Handler;
TaskHandle_t LED0Task_Handler;
TaskHandle_t BUZZERTask_Handler;
TaskHandle_t STEERTask_Handler;

void system_config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4	 	 
	delay_init();	
	LED_Init();	      //LED ��ʼ������
	BUZZER_Init();
	STEER_Init();
}

//��ʼ����������
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           						//�����ٽ���	
	//��̬��������
    xTaskCreate((TaskFunction_t )led0_task,     //ָ��������
                (const char*    )"led0_task",   //����������
                (uint16_t       )LED0_STK_SIZE, //�����ջ��С
                (void*          )NULL,					//���ݸ�����������
                (UBaseType_t    )LED0_TASK_PRIO,//���ȼ�
                (TaskHandle_t*  )&LED0Task_Handler); //�������������ɹ��ı�ʶ���淵�ش����ɹ��ı�־
								
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
								
    vTaskDelete(StartTask_Handler); 					 //ɾ����ǰ������Ϊ��ʼ����������Ǵ��������������Դ�����ɾ�ɾ����
    taskEXIT_CRITICAL();            					 //�˳��ٽ���
}

void led0_task(void *pvParameters)
{
    while(1)
    {
			LED_loop();
			vTaskDelay(500);                         //ϵͳ�������ʱ��Ҳ���Ǵ�LED_loop��ʼ��֮����ʱ500ms����������ʱ������whileѭ����500ms
    }
}   

//BUZZER������
void buzzer_task(void *pvParameters)
{
    while(1)
    {
			//BUZZER_loop();
			vTaskDelay(500);
    }
}

//STEER������
void steer_task(void *pvParameters)
{
    while(1)
    {
			//STEER_loop();
			uint16_t a = 0;
			a = 20000 * 0.025;     //�����������Ҳ�
			TIM_SetCompare4(TIM1,a);	
			vTaskDelay(500);
			a = 20000 * 0.075;     //�����������Ҳ�
			TIM_SetCompare4(TIM1,a);	
			vTaskDelay(500);
			a = 20000 * 0.125;
			TIM_SetCompare4(TIM1,a);	
			vTaskDelay(500);
    }
}

