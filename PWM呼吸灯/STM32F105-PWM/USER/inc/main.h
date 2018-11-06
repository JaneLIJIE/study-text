#ifndef __MAIN_H
#define __MAIN_H
#include <stm32f10x.h>

#include "gpio.h"
#include "timer.h"
#include "rcc_config.h"

void delay(void);

extern u8 flag_500ms;
extern u8 flag_300ms;
#define  LED1_ON()    GPIO_ResetBits(GPIOF,GPIO_Pin_6)
#define  LED1_OFF()    GPIO_SetBits(GPIOF,GPIO_Pin_6)

#endif
