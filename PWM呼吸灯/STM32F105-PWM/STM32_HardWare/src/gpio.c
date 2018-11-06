#include "main.h"

void GPIO_Config(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		
   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0; //¬Ãµ∆PB0£¨∫Ïµ∆PB1
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;		//…œ¿≠ ‰»Î
	 GPIO_Init(GPIOB, &GPIO_InitStruct);	
			
}

