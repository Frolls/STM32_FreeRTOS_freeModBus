/*
 * ds1821.c
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */
#include "ds1821.h"

unsigned char DS1821_Start_Conversion (GPIO_TypeDef * GPIOx, unsigned long PINx)
{
	unsigned char cnt;
	cnt=One_Wire_Reset(GPIOx, PINx);
	if (cnt!=One_Wire_Success) return cnt;
	One_Wire_Write_Byte(DS1821_START_CONVERT_T,GPIOx, PINx);
	return One_Wire_Success;
}

unsigned char DS1821_Stop_Conversion(GPIO_TypeDef * GPIOx, unsigned long PINx)
{
	unsigned char cnt;
	cnt=One_Wire_Reset(GPIOx, PINx);
	if (cnt!=One_Wire_Success) return cnt;
	One_Wire_Write_Byte(DS1821_STOP_CONVERT_T,GPIOx, PINx);
	return One_Wire_Success;
}

unsigned char DS1821_Read_Temp(unsigned int * temperature, GPIO_TypeDef * GPIOx, unsigned long PINx)
{
	unsigned char tmp;
	tmp=One_Wire_Reset(GPIOx, PINx);
	if (tmp!=One_Wire_Success) return tmp;
	One_Wire_Write_Byte(DS1821_READ_TEMPERATURE, GPIOx, PINx);
	* temperature = One_Wire_Read_Byte(GPIOx, PINx);
	return One_Wire_Success;
}

unsigned char DS1821_Load_Counter (GPIO_TypeDef * GPIOx, unsigned long PINx)
{
	unsigned char cnt;
	cnt=One_Wire_Reset(GPIOx, PINx);
	if (cnt!=One_Wire_Success) return cnt;
	One_Wire_Write_Byte(DS1821_LOAD_COUNTER,GPIOx, PINx);
	return One_Wire_Success;
}

unsigned char DS1821_Read_Counter(unsigned int * counter, GPIO_TypeDef * GPIOx, unsigned long PINx)
{
	unsigned char tmp;
	tmp=One_Wire_Reset(GPIOx, PINx);
	if (tmp!=One_Wire_Success) return tmp;
	One_Wire_Write_Byte(DS1821_READ_COUNTER,GPIOx, PINx);
	* counter = One_Wire_Read_Byte(GPIOx, PINx);
	return One_Wire_Success;
}

unsigned char DS1821_Write_Status (GPIO_TypeDef * GPIOx, unsigned long PINx)
{
	unsigned char cnt;
	cnt=One_Wire_Reset(GPIOx, PINx);
	if (cnt!=One_Wire_Success) return cnt;
	One_Wire_Write_Byte(DS1821_WRITE_STATUS,GPIOx, PINx);
	return One_Wire_Success;
}

unsigned char DS1821_Read_Status(unsigned int * status, GPIO_TypeDef * GPIOx, unsigned long PINx)
{
	unsigned char tmp;
	tmp=One_Wire_Reset(GPIOx, PINx);
	if (tmp!=One_Wire_Success) return tmp;
	One_Wire_Write_Byte(DS1821_READ_STATUS,GPIOx, PINx);
	* status = One_Wire_Read_Byte(GPIOx, PINx);
	return One_Wire_Success;
}
