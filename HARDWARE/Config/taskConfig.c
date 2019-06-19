#include "taskConfig.h"

/*
*�ⲿ����task�����ڴ˴�����ȫ�ֱ�����main������
*/
TaskHandle_t StartTask_Handler;
TaskHandle_t LED0Task_Handler;
TaskHandle_t BUZZERTask_Handler;

void system_config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4	 	 
	delay_init();	
	LED_Init();	      //LED ��ʼ������
	BUZZER_Init();
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
    vTaskDelete(StartTask_Handler); 					 //ɾ����ǰ������Ϊ��ʼ����������Ǵ��������������Դ�����ɾ�ɾ����
    taskEXIT_CRITICAL();            					 //�˳��ٽ���
}

void led0_task(void *pvParameters)
{
    while(1)
    {
			LED_loop();
			vTaskDelay(500);
    }
}   

//BUZZER������
void buzzer_task(void *pvParameters)
{
    while(1)
    {
			BUZZER_loop();
			vTaskDelay(500);
    }
}

