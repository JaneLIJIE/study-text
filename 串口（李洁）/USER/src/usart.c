#include <stm32f10x.h>
#include "usart.h"
#include "stdio.h"                  //注意包含库函！！！！
#include "stdarg.h"                 //注意包含库函！！！！

void usart1(void)
{
	GPIO_InitTypeDef   gpio1;
	USART_InitTypeDef usart1;
	NVIC_InitTypeDef  nvic;
	
/* 配置第一步开时钟	*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
/*开启时钟成功*/	

/*第二步配置所要运用到的引脚*/	
	gpio1.GPIO_Pin=GPIO_Pin_9;
	gpio1.GPIO_Mode= GPIO_Mode_AF_PP;     
	gpio1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&gpio1);
//用做通信不是普通IO要AF（复用）	
	gpio1.GPIO_Pin=GPIO_Pin_10;
	gpio1.GPIO_Mode= GPIO_Mode_IN_FLOATING;
	gpio1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&gpio1);
/*引脚配置完成*/

/*第三步根据通信的硬件配置通信功能*/
	usart1.USART_BaudRate=115200;
	usart1.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	usart1.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
	usart1.USART_Parity=USART_Parity_No;
	usart1.USART_StopBits=USART_StopBits_1;	
	usart1.USART_WordLength=USART_WordLength_8b;	
	USART_Init(USART1,&usart1);//向寄存器写入配置参数
/*配置USART完成*/	

/*****************使能也不要忘*********************/
	USART_Cmd(USART1,ENABLE);//使能外设
/*************************************/	

/*第四步开启要用到的中断服务配置*/	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	nvic.NVIC_IRQChannel=USART1_IRQn;
	nvic.NVIC_IRQChannelCmd=ENABLE;
	nvic.NVIC_IRQChannelPreemptionPriority=0x00;
	nvic.NVIC_IRQChannelSubPriority=0x00;
	NVIC_Init(&nvic);
/*配置完成*/	

/*还要使能配置，顺便要清除相关的标志位*/
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_ClearFlag(USART1,USART_FLAG_TC|USART_FLAG_TXE|USART_FLAG_RXNE);
/*完成了中断的配置*/

}

void usart3(void)
{
	GPIO_InitTypeDef   gpio3;
	USART_InitTypeDef usart3;
	NVIC_InitTypeDef  nvic;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	
	gpio3.GPIO_Pin=GPIO_Pin_10;
	gpio3.GPIO_Mode= GPIO_Mode_AF_PP;
	gpio3.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&gpio3);
	
	
	gpio3.GPIO_Pin=GPIO_Pin_11;
	gpio3.GPIO_Mode= GPIO_Mode_IN_FLOATING;
	gpio3.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&gpio3);
		
	usart3.USART_BaudRate=115200;
	usart3.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	usart3.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
	usart3.USART_Parity=USART_Parity_No;
	usart3.USART_StopBits=USART_StopBits_1;	
	usart3.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART3,&usart3);//向寄存器写入配置参数
	
	USART_Cmd(USART3,ENABLE);//使能外设
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	nvic.NVIC_IRQChannel=USART3_IRQn;
	nvic.NVIC_IRQChannelCmd=ENABLE;
	nvic.NVIC_IRQChannelPreemptionPriority=0x01;
	nvic.NVIC_IRQChannelSubPriority=0x00;
	NVIC_Init(&nvic);
	
	USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
	USART_ClearFlag(USART3,USART_FLAG_TC|USART_FLAG_TXE|USART_FLAG_RXNE);
}

u8 RevData1=0;
u8 RevData3=0;
/*=================串口1接收中断===================*/
void USART1_IRQHandler(void)
{
	 if(USART_GetITStatus(USART1,USART_IT_RXNE)!=0)
	 {
			USART_ClearITPendingBit(USART1,USART_IT_RXNE);
			RevData1=USART_ReceiveData(USART1);
	 }
}

/*=================串口3接收中断===================*/
void USART3_IRQHandler(void)
{
	 if(USART_GetITStatus(USART3,USART_IT_RXNE)!=0)
	{
		USART_ClearITPendingBit(USART3,USART_IT_RXNE);
		RevData3=USART_ReceiveData(USART3);
	}
}


char usartbuf[100];
/**************重新定义输出函数（printf指向串口）************/

int fputc (int str, FILE *f)
{
	USART_ClearFlag(USART1,USART_FLAG_TC);//去掉第一个数据不能发送
	USART_SendData(USART1,(uint8_t)str);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) 
		;
  return str;
}

/********************发送数据定义****************************/
void USART_SendString(USART_TypeDef* USARTX,char *s)
{
	while(*s)
	{
		USART_ClearFlag(USARTX,USART_FLAG_TC);//去掉第一个数据不能发送
		USART_SendData(USARTX,*s++);
		while(USART_GetFlagStatus(USARTX,USART_FLAG_TXE)==RESET);//判断是否发送完成
	}
}
/*********************printf函数****************/
void USART_Printf(USART_TypeDef* USARTX,char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	vsprintf((char *)usartbuf,fmt,ap);
	va_end(ap);
	
	USART_SendString(USARTX,usartbuf);
}

