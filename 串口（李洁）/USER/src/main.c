#include "main.h"

//void delay()
//{
//	u16 i,j=1000;
//	for(i=0;i<100;i++)
//		while(j--);
//}
u8 flag_1000ms=0;
extern u8 RevData1;
extern u8 RevData3;
int main()
{ //int count;
//	char ch;
//	u8 count=0;
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	RCC_Configuration();
	GPIO_Config();
//	OLED_Configuration();
	TIM3_Init();  // first error
	usart1();
	usart3();
	

	
	while(1)
	{
	/*任务一	
		  if(flag_1000ms%4 == 0) 
			{	
			  USART_SendData(USART1,1);
			  while(USART_GetFlagStatus(USART1,USART_FLAG_TC));
				if(RevData3 == 1)
			  {
					RevData3 = 0;
					GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				}
			}
      if(flag_1000ms%4==1)
			{	
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
			}
			
			if(flag_1000ms%4==2)
			{
				USART_SendData(USART3,1);
				if(RevData1 == 1)
				{
				 RevData1 = 0;
				 GPIO_ResetBits(GPIOA,GPIO_Pin_2);
				}
			}
			 if(flag_1000ms%4==3)
			{
				GPIO_SetBits(GPIOA,GPIO_Pin_2);
			}*/	
			
			
//		USART_SendData(USART3,0X00);
//	 // while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)==RESET);
//			
//		if(flag_1000ms%2==0)	
//		{
//			if(RevData1 == 0)	
//		 {
//		  GPIO_ResetBits(GPIOB,GPIO_Pin_0);
//			RevData1 = 1;
//	   }
//			
////    if(flag_1000ms%4==1)
////	  {
////		 GPIO_SetBits(GPIOB,GPIO_Pin_0);
////	  }	
//		  if(RevData1 == 1)
//		 {
//			GPIO_SetBits(GPIOB,GPIO_Pin_0);
//		 }
//		}	
			
			
	/*任务二
	USART_SendData(USART3,0X00);
	while(USART_GetFlagStatus(USART3,USART_FLAG_TC));
	
	if(RevData1 == 0)
		{ 
			RevData1 = 1;
			if(flag_1000ms%2==0)
			GPIO_ResetBits(GPIOB,GPIO_Pin_0);
			
			else if(flag_1000ms%2==1)
			GPIO_SetBits(GPIOB,GPIO_Pin_0);
		}	*/
		
		
		 if(flag_1000ms%2 == 0) 
			{	
			  USART_SendData(USART1,0x00);
			  while(USART_GetFlagStatus(USART1,USART_FLAG_TC));
				if(RevData3 == 0)
			  {
					RevData3 = 1;
					GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				}
			}
      if(flag_1000ms%2==1)
			{	
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
			}
			
			
			
	/*任务三
	USART_SendData(USART3,1100);
	while(USART_GetFlagStatus(USART3,USART_FLAG_TC));
	if(RevData1 == 1100)	
	{
		
	}		*/
			
}	
	
		
//		OLED_Print(0,0,"Module_mesage");
//		
//		sprintf(buff,"R_Time:%d",Runing_time);
//		OLED_Printf(0,2,(char *)buff);
//		if(flag_1000ms == 1)
//		{
//			Runing_time ++;
//			flag_1000ms = 0;
//		}
//		if(flag_500ms == 1)
//		{
//			GPIO_SetBits(GPIOB,GPIO_Pin_0);
//			flag_500ms = 0;
//			USART_SendData(USART1,0X01);
//			while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
//		}
//		if(flag_500ms == 1)
//		{
//			GPIO_SetBits(GPIOA,GPIO_Pin_2);	
//			flag_500ms = 0;
//			USART_SendData(USART3,0X02);
//			while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)==RESET);
//		}		
//		
//		if(RevData1 == 2)
//		{
//			if(flag_1000ms == 1)
//			{
//			  GPIO_ResetBits(GPIOB,GPIO_Pin_0);
//				flag_1000ms = 0;
//			}
//			RevData1 = 0;
//		}
//		
//		if(RevData3 == 1)
//		{
//			if(flag_1000ms == 1)
//			{
//			  GPIO_ResetBits(GPIOA,GPIO_Pin_2);
//				flag_1000ms = 0;
//			}

//      RevData3 = 0;			
//		}		
			
	
}
//1、A板发送，B板接收成功，LED1灯亮1s;而后，B板向A板发，A板接受成功，LED2灯亮1s。往复循环。
//2、A向B发0x00,B板LED1灯亮1s，往复；
//3、A向B发舵机角度，B板接受数据后控制舵机转角，以此类推

