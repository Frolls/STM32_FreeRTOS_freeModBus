/*
 * oneWire.h
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */

#ifndef ONEWIRE_H_
#define ONEWIRE_H_

#include "timer6.h"
#include "stm32_GPIO.h"

#define Time_Pulse_Delay_Low	10
#define Time_Pulse_Delay_High	60
#define Time_Reset_Low			480
#define Time_After_Reset		350
#define Time_Hold_Down			2

#define One_Wire_Read_ROM		0x33
#define One_Wire_Skip_ROM		0xCC
#define One_Wire_Search_ROM		0xF0
#define One_Wire_Match_ROM		0x55

#define One_Wire_Success		0x00
#define One_Wire_Error_No_Echo	0x01
#define One_Wire_Bus_Low_Error	0x02
#define One_Wire_Device_Busy	0x03
#define One_Wire_CRC_Error		0x04

unsigned int One_Wire_Reset(GPIO_TypeDef * GPIOx, u16 PINx);
void One_Wire_Write_Byte(unsigned char Byte,GPIO_TypeDef * GPIOx, u16 PINx);
unsigned char One_Wire_Read_Byte(GPIO_TypeDef * GPIOx, u16 PINx);
unsigned char One_Wire_Read_Bit (GPIO_TypeDef * GPIOx, u16 PINx);
void One_Wire_Write_Bit (unsigned char Bit,GPIO_TypeDef * GPIOx, u16 PINx);

#endif /* ONEWIRE_H_ */
