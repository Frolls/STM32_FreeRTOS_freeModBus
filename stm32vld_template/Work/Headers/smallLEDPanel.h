/*
 * smallLEDPanel.h
 *
 *  Created on: 08.04.2013
 *      Author: frolls
 */

#ifndef SMALLLEDPANEL_H_
#define SMALLLEDPANEL_H_

#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

// пускай будут на одном порту
void smallLEDPanel_Init(void);//GPIO_TypeDef * GPIOx, u16 PIN_CLK, u16 PIN_SDI, u16 PIN_LE);

void smallLEDPanel_Inc(void);

#endif /* SMALLLEDPANEL_H_ */
