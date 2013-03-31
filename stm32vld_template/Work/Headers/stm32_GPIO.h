/*
 * stm32_GPIO.h
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */

#ifndef STM32_GPIO_H_
#define STM32_GPIO_H_

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void PIN_ON(GPIO_TypeDef * GPIOx,u16 PINx);
void PIN_OFF(GPIO_TypeDef * GPIOx,u16 PINx);
u8 PIN_SYG(GPIO_TypeDef * GPIOx, u16 PINx);
void PIN_IN (GPIO_TypeDef * GPIOx,u16 PINx);
void PIN_OUT_PP (GPIO_TypeDef * GPIOx,u16 PINx);
void PIN_OUT_OD (GPIO_TypeDef * GPIOx,u16 PINx);
void PIN_INV(GPIO_TypeDef * GPIOx, u16 PINx);

#endif /* STM32_GPIO_H_ */
