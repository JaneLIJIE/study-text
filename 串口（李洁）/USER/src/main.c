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
	/*����һ	
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
			
			
	/*�����
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
			
			
			
	/*������
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
//1��A�巢�ͣ�B����ճɹ���LED1����1s;����B����A�巢��A����ܳɹ���LED2����1s������ѭ����
//2��A��B��0x00,B��LED1����1s��������
//3��A��B������Ƕȣ�B��������ݺ���ƶ��ת�ǣ��Դ�����

