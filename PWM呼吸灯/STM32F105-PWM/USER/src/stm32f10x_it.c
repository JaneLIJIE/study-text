#include <stm32f10x.h>
#include "stm32f10x_it.h"

u8 RevData=0;

void NMI_Handler(void)
{
	
  
}


void HardFault_Handler(void)
{
 
}


void MemManage_Handler(void)
{

}


void BusFault_Handler(void)
{
 
}


void UsageFault_Handler(void)
{
  
}


void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

/*
void PendSV_Handler(void)
{
}
*/

void SysTick_Handler(void)
{
	  
}


/*===============��λ����PE0�ⲿ�ж�==================*/
void EXTI0_IRQHandler(void)
{

}


/*===================����1DMA====================*/
void DMA1_Channel5_IRQHandler(void)  
{

}


/*=================����2�����ж�===================*/
void USART1_IRQHandler(void)
{
	  if(USART_GetITStatus(USART1,USART_IT_RXNE)!=0)
	{
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
		RevData=USART_ReceiveData(USART1);
	}
}


/******************����ʱ��->��ʱ********************/
/******************����ʱ��->��ʱ********************/


/***************����X1**********************/
void TIM4_IRQHandler(void)
{
	

	
	
	
}

/*****************����x2*****************************/

void TIM5_IRQHandler(void)
{

}


/**************����x3******************/
void TIM3_IRQHandler (void)
{

	
	
	
}


void EXTI15_10_IRQHandler(void)
{

}

void ADC1_2_IRQHandler(void)
{
	
}

void DMA1_Channel3_IRQHandler(void )  
{     	
 
}

void DMA1_Channel2_IRQHandler(void )  
{     	
  
}

void USB_LP_CAN1_RX0_IRQHandler(void)  
{     	

 
}


