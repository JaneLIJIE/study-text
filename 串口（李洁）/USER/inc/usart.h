#ifndef _USART_H
#define _USART_H

#include <stm32f10x.h>
#include "stdio.h"           //ע������⺯����������
#include "stdarg.h"          //ע������⺯��������

void usart1(void);
void usart3(void);
int fputc (int str, FILE *f);
void USART_Printf(USART_TypeDef* USARTX,char *fmt,...);
void USART_SendString(USART_TypeDef* USARTX,char *s);

#endif




