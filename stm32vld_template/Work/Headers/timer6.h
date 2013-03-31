/*
 * timer6.h
 *
 *  Created on: 21.03.2013
 *      Author: frolls
 */

#ifndef TIMER6_H_
#define TIMER6_H_

#include <stm32f10x_rcc.h>
#include <stm32f10x_tim.h>
#include "FreeRTOS.h"
#include "misc.h"

#define SYS_CLK SystemCoreClock    /* in this example we use SPEED_HIGH = 24 MHz */
#define PRESCALER_TIM_FREQUENCY 1000000 /*Значения предделителя для формирование микросекндной задержки */



void TIM6Init();
void NVIC_Configuration_TIM6(void);
void TIM6_DAC_IRQHandler();

void delay_us(uint16_t uSecs);
void delay_ms(uint16_t mSecs);



#endif /* TIMER6_H_ */
