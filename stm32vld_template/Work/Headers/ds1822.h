/*
 * ds1822.h
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */

#ifndef DS1822_H_
#define DS1822_H_

#include "stm32_GPIO.h"
#include "oneWire.h"
#include "CRC.h"

#define DS1822_CONVERT_T_CMD				0x44
#define DS1822_WRITE_STRATCHPAD_CMD			0x4E
#define DS1822_READ_STRATCHPAD_CMD			0xBE
#define DS1822_COPY_STRATCHPAD_CMD			0x48
#define DS1822_RECALL_E_CMD					0xB8
#define DS1822_READ_POWER_SUPPLY_CMD		0xB4

#define DS1822_STRATCHPAD_SIZE				0x09
#define DS1822_SERIAL_NUM_SIZE				0x08

#define One_Wire_Device_Number_MAX			10	//maximum number of 1-wire devices on bus

unsigned char DS1822_Search_Rom_One_Device (GPIO_TypeDef * GPIOx, unsigned long PINx, unsigned char (*Serial_Num)[DS1822_SERIAL_NUM_SIZE]);
unsigned char DS1822_Start_Conversion_by_ROM (GPIO_TypeDef * GPIOx, unsigned long PINx, unsigned char (*Serial_Num)[DS1822_SERIAL_NUM_SIZE]);
unsigned char DS1822_Get_Conversion_Result_by_ROM_CRC (GPIO_TypeDef * GPIOx, unsigned long PINx, unsigned char (*Serial_Num)[DS1822_SERIAL_NUM_SIZE], unsigned int * temp_code);
unsigned char DS1822_Search_Rom (unsigned char * devices_found, GPIO_TypeDef * GPIOx, unsigned long PINx);
unsigned char DS1822_Search_Rom2 (GPIO_TypeDef * GPIOx, unsigned long PINx, unsigned char * devices_found, unsigned char (* SN_ROM)[One_Wire_Device_Number_MAX][DS1822_SERIAL_NUM_SIZE]);
unsigned char DS1822_Start_Conversion_Skip_Rom (GPIO_TypeDef * GPIOx, unsigned long PINx);
unsigned char DS1822_Read_Temp_NoCRC_Skip_Rom (unsigned int * temperatura, GPIO_TypeDef * GPIOx, unsigned long PINx);

#endif /* DS1822_H_ */
