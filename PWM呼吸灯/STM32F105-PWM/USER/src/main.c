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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	RCC_Configuration();
	GPIO_Config();
	TIM3_Init();
	while(1)
	{	
		for(count=0;count<20;count++)
		{
			TIM_SetCompare3(TIM3,count*1000);
			delay();
		}
		for(count=20;count>0;count--)
		{
			TIM_SetCompare3(TIM3,count*1000);
			delay();
		}
	}
}
