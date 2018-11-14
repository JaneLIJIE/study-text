#include "main.h"

void GPIO_Config(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
		
   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2; //ÂÌµÆPB0£¬ºìµÆPB1
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;		//¿ªÂ©Êä³ö
	 GPIO_Init(GPIOA, &GPIO_InitStruct);			
	 GPIO_SetBits(GPIOA,GPIO_Pin_2);
	
	
   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0; //ÂÌµÆPB0£¬ºìµÆPB1
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;		//¿ªÂ©Êä³ö
	 GPIO_Init(GPIOB, &GPIO_InitStruct);			
	 GPIO_SetBits(GPIOB,GPIO_Pin_0);
}

