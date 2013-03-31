/*
 * CRC.h
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */

#ifndef CRC_H_
#define CRC_H_

unsigned char Crc8Dallas(unsigned char len, unsigned char *pData);
unsigned char Crc8(unsigned int len, unsigned char *pcBlock);


#endif /* CRC_H_ */
