#include "timer.h"
#include "main.h"

void TIM3_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);   // second error IO not used
	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = 20000-1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 

	
	// third error should not config PWM
//	//��ʼ��TIM3 Channel3 PWMģʽ	 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
//	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2

//	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
//	
//	TIM_SetCompare3(TIM3,0);
//	
//	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx		




  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���

  TIM_ClearFlag(TIM3,TIM_FLAG_Update);   // forty error TIM3 TO TIM6            
  TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);  // fifty error did not config 
	
	
	TIM_Cmd(TIM3, ENABLE);   //ALSO
}

u8 count=0;
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
	  count ++;
		if(count==50)
		{
		  flag_1000ms++;
			count = 0;

		}
		
		if(flag_1000ms==254)
		{
			flag_1000ms=3;
		}
	}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update); 		//���TIMx�����жϱ�־ 
}
