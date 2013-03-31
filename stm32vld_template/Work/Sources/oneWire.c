/*
 * oneWire.c
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */

#include "oneWire.h"

unsigned int One_Wire_Reset(GPIO_TypeDef * GPIOx, u16 PINx)
{
	unsigned int tmp;
	PIN_IN(GPIOx, PINx);
	if ((PIN_SYG(GPIOx, PINx))==0)	return One_Wire_Bus_Low_Error;
	PIN_OUT_PP(GPIOx, PINx);
	PIN_OFF(GPIOx, PINx);
	delay_us(Time_Reset_Low);
	PIN_ON(GPIOx, PINx);
	PIN_IN(GPIOx, PINx);
	delay_us(Time_Pulse_Delay_High);
	if ((PIN_SYG(GPIOx, PINx))==0) tmp=One_Wire_Success;
		else tmp=One_Wire_Error_No_Echo;
	delay_us(Time_After_Reset);
	return tmp;
}

void One_Wire_Write_Byte(unsigned char Byte,GPIO_TypeDef * GPIOx, u16 PINx)
{
	unsigned char cnt;
	for (cnt=0;cnt!=8;cnt++) One_Wire_Write_Bit(Byte&(1<<cnt),GPIOx, PINx);
}

void One_Wire_Write_Bit (unsigned char Bit,GPIO_TypeDef * GPIOx, u16 PINx)
{
	PIN_OUT_PP(GPIOx, PINx);
	PIN_OFF(GPIOx, PINx);
	if (Bit==0)
	{
		delay_us(Time_Pulse_Delay_High);
		PIN_ON(GPIOx, PINx);
		delay_us(Time_Pulse_Delay_Low);
	}
	else
	{
		delay_us(Time_Pulse_Delay_Low);
		PIN_ON(GPIOx, PINx);
		delay_us(Time_Pulse_Delay_High);
	}
	PIN_IN(GPIOx, PINx);
}

unsigned char One_Wire_Read_Byte(GPIO_TypeDef * GPIOx, u16 PINx)
{
	unsigned char tmp=0;
	unsigned char cnt;
	for (cnt=0;cnt!=8;cnt++)
		if (One_Wire_Read_Bit(GPIOx, PINx)!=0)	tmp|=(1<<cnt);
	delay_us(Time_Pulse_Delay_High);
	return tmp;
}

unsigned char One_Wire_Read_Bit (GPIO_TypeDef * GPIOx, u16 PINx)
{
		unsigned char tmp;
	 	PIN_OUT_PP(GPIOx, PINx);
		PIN_OFF(GPIOx, PINx);
		delay_us(Time_Hold_Down);
		PIN_IN(GPIOx, PINx);
		delay_us(Time_Pulse_Delay_Low);
		if ((PIN_SYG(GPIOx, PINx))!=0)	tmp = 1;
			else tmp = 0;
		delay_us(Time_Pulse_Delay_High);
		return tmp;
}
