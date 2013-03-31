/*
 * ds1821.h
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */

#ifndef DS1821_H_
#define DS1821_H_

#include "stm32_GPIO.h"
#include "oneWire.h"

#define DS1821_READ_TEMPERATURE			0xAA
#define DS1821_START_CONVERT_T			0xEE
#define DS1821_STOP_CONVERT_T			0x22

#define DS1821_WRITE_TH					0x01
#define DS1821_WRITE_TL					0x02

#define DS1821_READ_TH					0xA1
#define DS1821_READ_TL					0xA2

#define DS1821_WRITE_STATUS				0x0C
#define DS1821_READ_STATUS				0xAC

#define DS1821_READ_COUNTER				0xA0
#define DS1821_LOAD_COUNTER				0x41

unsigned char DS1821_Start_Conversion (GPIO_TypeDef * GPIOx, unsigned long PINx);
unsigned char DS1821_Stop_Conversion(GPIO_TypeDef * GPIOx, unsigned long PINx);
unsigned char DS1821_Read_Temp(unsigned int * temperature, GPIO_TypeDef * GPIOx, unsigned long PINx);

unsigned char DS1821_Load_Counter(GPIO_TypeDef * GPIOx, unsigned long PINx);
unsigned char DS1821_Read_Counter(unsigned int * counter, GPIO_TypeDef * GPIOx, unsigned long PINx);

unsigned char DS1821_Write_Status(GPIO_TypeDef * GPIOx, unsigned long PINx);
unsigned char DS1821_Read_Status(unsigned int * status, GPIO_TypeDef * GPIOx, unsigned long PINx);


#endif /* DS1821_H_ */
