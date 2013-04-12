/*
 * smallLEDPanel.h
 *
 *  Created on: 08.04.2013
 *      Author: frolls
 */

#ifndef SMALLLEDPANEL_H_
#define SMALLLEDPANEL_H_

#include "stm32_GPIO.h"

#define getbit(n,m) ((n>>m)&1)?1:0

#define smallLEDPanel_Port 		GPIOC
#define smallLEDPanel_CLK 		GPIO_Pin_10
#define smallLEDPanel_SDI 		GPIO_Pin_11
#define smallLEDPanel_LE 		GPIO_Pin_12

// пускай будут на одном порту
void smallLEDPanel_Init(void);//GPIO_TypeDef * GPIOx, u16 PIN_CLK, u16 PIN_SDI, u16 PIN_LE);

void smallLEDPanel_All_On(void);
void smallLEDPanel_Clear(void);

void smallLEDPanel_Set(unsigned short val);

void smallLEDPanel_Inc(unsigned short incVal);

#endif /* SMALLLEDPANEL_H_ */
