#include "main.h"

void delay()
{
	u16 i,j=1000;
	for(i=0;i<10;i++)
		while(j--);
}

u8 flag_500ms=0;
u8 flag_300ms=0;

int main()
{
	u8 count=0;
	RCC_Configuration();
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	GPIO_Config();
  TIM3_Init();
	TIM2_Init();
	//TIM1_Init();
	while(1)
	{	
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==1)
		{
			for(count=0;count<20;count++)
			{
				TIM_SetCompare3(TIM3,count*1000);
				TIM_SetCompare3(TIM2,20000);
				delay();
			}
			for(count=20;count>0;count--)
			{
				TIM_SetCompare3(TIM3,count*1000);  
				TIM_SetCompare3(TIM2,20000);
				delay();
			}
		}
		else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
		{
			for(count=0;count<20;count++)
			{
				TIM_SetCompare3(TIM3,count*1000);
				TIM_SetCompare3(TIM2,count*1000);
				delay();
			}	
		
			for(count=20;count>0;count--)
			{
				TIM_SetCompare3(TIM3,count*1000); 
				TIM_SetCompare3(TIM2,count*1000);
				delay();
			}
		}
	}		
}
 	
 

