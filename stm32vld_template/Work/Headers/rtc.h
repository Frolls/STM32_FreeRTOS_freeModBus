/*
 * rtc.h
 *
 *  Created on: 07.04.2013
 *      Author: frolls
 */

#ifndef RTC_H_
#define RTC_H_

#include <stm32f10x_rcc.h>
#include <stm32f10x_rtc.h>
#include <stm32f10x_pwr.h>

void RTC_Config(void);

uint32_t GetTime(void);

#endif /* RTC_H_ */
