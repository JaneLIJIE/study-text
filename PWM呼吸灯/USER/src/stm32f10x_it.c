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


/*===============限位开关PE0外部中断==================*/
void EXTI0_IRQHandler(void)
{

}


/*===================串口1DMA====================*/
void DMA1_Channel5_IRQHandler(void)  
{

}


/*=================串口2接收中断===================*/
void USART1_IRQHandler(void)
{
	  if(USART_GetITStatus(USART1,USART_IT_RXNE)!=0)
	{
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
		RevData=USART_ReceiveData(USART1);
	}
}


/******************基本时钟->定时********************/
/******************基本时钟->定时********************/


/***************码盘X1**********************/
void TIM4_IRQHandler(void)
{
	

	
	
	
}

/*****************码盘x2*****************************/

void TIM5_IRQHandler(void)
{

}


/**************码盘x3******************/
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


