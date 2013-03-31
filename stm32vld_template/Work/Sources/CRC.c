/*
 * CRC.c
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */
#include "CRC.h"

unsigned char Crc8Dallas(unsigned char len, unsigned char *pData)
{
 	unsigned char crc = 0;
 	unsigned char i;

 	while (len--)
 	{
 		crc ^= *pData++;
		for (i = 0; i < 8; i++)
 		crc = crc & 0x01 ? (crc >> 1) ^ 0x8C : crc >> 1;
 	}
	return crc;
 }

unsigned char Crc8(unsigned int len, unsigned char *pcBlock)
{
	unsigned char crc = 0xFF;
 	unsigned int i;

 	while (len--)
 	{
 		crc ^= *pcBlock++;
		for (i = 0; i < 8; i++)
 		crc = crc & 0x80 ? (crc << 1) ^ 0x31 : crc << 1;
 	}
 	return crc;
}


