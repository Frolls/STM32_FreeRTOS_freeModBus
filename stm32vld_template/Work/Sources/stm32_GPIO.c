/*
 * stm32_GPIO.c
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */

#include "stm32_GPIO.h"
#include "stm32f10x_gpio.h"

void PIN_ON(GPIO_TypeDef * GPIOx,u16 PINx)
{
	GPIOx->BSRR=PINx;
	//GPIOx->ODR=GPIOx->IDR|(PINx);
}

void PIN_OFF(GPIO_TypeDef * GPIOx,u16 PINx)
{
	GPIOx->BRR=PINx;
	//GPIOx->ODR=GPIOx->IDR&(~(PINx));
}

u8 PIN_SYG(GPIO_TypeDef * GPIOx, u16 PINx)
{
	if((GPIOx->IDR&PINx)!=0)
	{return 1;}
	else
	{return 0;}
}

void PIN_IN (GPIO_TypeDef * GPIOx,u16 PINx)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin=PINx;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void PIN_OUT_PP (GPIO_TypeDef * GPIOx,u16 PINx)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin=PINx;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void PIN_OUT_OD (GPIO_TypeDef * GPIOx,u16 PINx)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin=PINx;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_OD;
	GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void PIN_INV(GPIO_TypeDef * GPIOx, u16 PINx)
{
	if(PIN_SYG(GPIOx, PINx)!=0)
	{PIN_OFF(GPIOx, PINx);}
	else
	{PIN_ON(GPIOx, PINx);}
}
