#include "timer.h"
#include "main.h"

void TIM3_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);   // second error IO not used
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = 20000-1; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 

	
	// third error should not config PWM
//	//初始化TIM3 Channel3 PWM模式	 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //输出极性:TIM输出比较极性高
//	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC2

//	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
//	
//	TIM_SetCompare3(TIM3,0);
//	
//	TIM_Cmd(TIM3, ENABLE);  //使能TIMx		




  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器

  TIM_ClearFlag(TIM3,TIM_FLAG_Update);   // forty error TIM3 TO TIM6            
  TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);  // fifty error did not config 
	
	
	TIM_Cmd(TIM3, ENABLE);   //ALSO
}

u8 count=0;
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
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
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update); 		//清除TIMx更新中断标志 
}
