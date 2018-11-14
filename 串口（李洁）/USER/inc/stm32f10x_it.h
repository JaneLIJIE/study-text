/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.h 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_IT_H
#define __STM32F10x_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
	 
typedef enum
{
	NMI=0,
	HARD_FAULT=1,
	MEM=2,
	BUS_FAULT=3,
	USAGE_FAULT=4,
	QUEUE_FAULT=5,
	MOTOR_STOP=6,
	GYRO_ERROR=7,
	HAND_RIGHT=8,
	HAND_LEFT=9,
	HAND_STOP=10,
	ARM_UP=11,
	ARM_DOWN=12,
	ARM_STOP=13,
	H_FORWARD=14,
	H_BACK=15,
	H_STOP=16,
	BIG_BANG=17,
	GRAB=18,
	PUSH_TEETER=19,
	HOLD_TEETER=20,
	SERIES_1=21,
	SERIES_2=22,
	SERIES_3=23,
	SERIES_4=24,
	SERIES_5=25,
	SERIES_6=26,
	SERIES_7=27
}hard_fault;	
	 
	 
#define ENCODER_OV_X1DIR    (TIM4->CR1&((u16)1<<4))
#define ENCODER_OV_X2DIR    (TIM5->CR1&((u16)1<<4))
#define ENCODER_OV_X3DIR    (TIM3->CR1&((u16)1<<4))
	 
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
//void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI9_5_IRQHandler(void);
void TIM5_IRQHandler(void);
void TIM3_IRQHandler(void);
//void USART2_IRQHandler(void);
void DMA1_Channel5_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_IT_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
