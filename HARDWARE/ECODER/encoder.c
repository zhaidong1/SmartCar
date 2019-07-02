#include "encoder.h"
#include "stm32f10x_exti.h"
#include "taskConfig.h"
/**************************************************************************
�������ܣ���TIM2��ʼ��Ϊ�������ӿ�ģʽ
��ڲ�������
����  ֵ����
**************************************************************************/
void Encoder_Init_TIM3(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;  
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//ʹ�ܶ�ʱ��3��ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//ʹ��PB�˿�ʱ��
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	//�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
  GPIO_Init(GPIOA, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOB
  
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // Ԥ��Ƶ�� 
  TIM_TimeBaseStructure.TIM_Period = ENCODER_TIM_PERIOD; //�趨�������Զ���װֵ
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//ѡ��ʱ�ӷ�Ƶ������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM���ϼ���  
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
  TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//ʹ�ñ�����ģʽ3
  TIM_ICStructInit(&TIM_ICInitStructure);
  TIM_ICInitStructure.TIM_ICFilter = 10;
  TIM_ICInit(TIM3, &TIM_ICInitStructure);
  TIM_ClearFlag(TIM3, TIM_FLAG_Update);//���TIM�ĸ��±�־λ
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
  //Reset counter
  TIM_SetCounter(TIM3,0);
  TIM_Cmd(TIM3, ENABLE); 
}



/**************************************************************************
�������ܣ��ⲿ�жϲɼ�������
��ڲ�������
����  ֵ����
**************************************************************************/
void Encoder_Init_TIM_Exit0(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��PA�˿�ʱ��
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	            //�˿�����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //��������
		GPIO_Init(GPIOA, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOB 
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;//�½��ش���
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	  
   // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  													
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/**************************************************************************
�������ܣ��ⲿ�жϲɼ�������
��ڲ�������
����  ֵ����
**************************************************************************/
void Encoder_Init_TIM_Exit1(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��PA�˿�ʱ��
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	            //�˿�����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //��������
		GPIO_Init(GPIOA, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOB 
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line1;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;//�½��ش���
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	  
   // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  													
    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}


/**************************************************************************
�������ܣ���λʱ���ȡ����������
��ڲ�������ʱ��
����  ֵ���ٶ�ֵ
**************************************************************************/
int Read_Encoder(u8 TIMX)
{
    int Encoder_TIM;    
   switch(TIMX)
	 {
	   case 2:  Encoder_TIM=(short)movebase.ecoder.Encoder_A_EXTI;  movebase.ecoder.Encoder_A_EXTI=0; break;	
		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0;break;	
		 case 4:  Encoder_TIM= (short)TIM4 -> CNT;  TIM4 -> CNT=0;break;	
		 default:  Encoder_TIM=0;
	 }
		return Encoder_TIM;
}
 
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET) 
	{	
		TIM_ClearITPendingBit(TIM3,TIM_FLAG_Update);			
		
		TIM_ClearFlag(TIM3, TIM_FLAG_Update); 
	}		 	
}


/**************************************************************************
�������ܣ�EXTI�жϷ�����  ͨ���ⲿ�ж�ʵ�ֱ���������
��ڲ�������
����  ֵ����
**************************************************************************/
void EXTI1_IRQHandler(void)
{			
		EXTI->PR=1<<1;  //���LINE�ϵ��жϱ�־λ
	if(PAin(1)==1)
	{
	if(PAin(0)==0)  movebase.ecoder.Encoder_A_EXTI++;   
	else            movebase.ecoder.Encoder_A_EXTI--;
	}
	else
	{
	if(PAin(0)==0)  movebase.ecoder.Encoder_A_EXTI--;
	else            movebase.ecoder.Encoder_A_EXTI++;
	}		
}
void EXTI0_IRQHandler(void)  //
{
		EXTI->PR=1<<0;  //���LINE�ϵ��жϱ�־λ
		if(PAin(0)==0)
	{
	if(PAin(1)==0)   movebase.ecoder.Encoder_A_EXTI++;
	else             movebase.ecoder.Encoder_A_EXTI--;
	}
	else
	{
	if(PAin(1)==0)  movebase.ecoder.Encoder_A_EXTI--;
	else             movebase.ecoder.Encoder_A_EXTI++;
	}		
}
void Ecoder_Init(Ecoder* ecoder)
{
	Encoder_Init_TIM3();
	Encoder_Init_TIM_Exit0();
	Encoder_Init_TIM_Exit1();
	ecoder->Encoder_A_EXTI = 0;
	ecoder->Encoder_Left = 0;
	ecoder->Encoder_Right = 0;
}

void Ecoder_Loop()
{
	movebase.ecoder.Encoder_Left = -Read_Encoder(2); 
	movebase.ecoder.Encoder_Right = -Read_Encoder(3);  
}
