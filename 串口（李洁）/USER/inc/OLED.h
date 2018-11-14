#ifndef __OLED_H__
#define __OLED_H__

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void OLED_Configuration(void);  
void OLED_Print(unsigned char x, unsigned char y, char ch[]);
void OLED_Printf(unsigned char x,unsigned char y,const char *fmt,...);
void OLED_Clear(void);

#endif 
