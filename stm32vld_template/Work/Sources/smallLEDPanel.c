/*
 * smallLEDPanel.c
 *
 *  Created on: 08.04.2013
 *      Author: frolls
 */
#include "smallLEDPanel.h"

void smallLEDPanel_Init(void)//GPIO_TypeDef * GPIOx, u16 PIN_CLK, u16 PIN_SDI, u16 PIN_LE)
{
	PIN_OUT_PP(smallLEDPanel_Port, smallLEDPanel_CLK);
	PIN_OUT_PP(smallLEDPanel_Port, smallLEDPanel_SDI);
	PIN_OUT_PP(smallLEDPanel_Port, smallLEDPanel_LE);
	//GPIO_InitTypeDef GPIO_InitStructure;
	//GPIO_InitStructure.GPIO_Pin   = PIN_CLK ;//| PIN_SDI;// | PIN_LE;
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	//GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	//GPIO_Init(GPIOx, &GPIO_InitStructure);
}

void smallLEDPanel_All_On(void)
{
	volatile unsigned char i;
		PIN_OFF(smallLEDPanel_Port, smallLEDPanel_LE);

		PIN_ON(smallLEDPanel_Port, smallLEDPanel_SDI);
		for (i=0; i<16; i++)
		{
			PIN_OFF(smallLEDPanel_Port, smallLEDPanel_CLK);
			PIN_ON(smallLEDPanel_Port, smallLEDPanel_CLK);
		}
		PIN_ON(smallLEDPanel_Port, smallLEDPanel_LE);
}

void smallLEDPanel_Clear(void)
{
	volatile unsigned char i;
	PIN_OFF(smallLEDPanel_Port, smallLEDPanel_LE);

	PIN_OFF(smallLEDPanel_Port, smallLEDPanel_SDI);
	for (i=0; i<16; i++)
	{
		PIN_OFF(smallLEDPanel_Port, smallLEDPanel_CLK);
		PIN_ON(smallLEDPanel_Port, smallLEDPanel_CLK);
	}
	PIN_ON(smallLEDPanel_Port, smallLEDPanel_LE);
}

void smallLEDPanel_Set(unsigned short val)
{
	volatile unsigned char i;

	PIN_OFF(smallLEDPanel_Port, smallLEDPanel_LE);

	for (i=0; i<16; i++)
	{
		if ((val >> (15-i)) & 1)
			PIN_ON(smallLEDPanel_Port, smallLEDPanel_SDI);
		else
			PIN_OFF(smallLEDPanel_Port, smallLEDPanel_SDI);

		PIN_OFF(smallLEDPanel_Port, smallLEDPanel_CLK);
		PIN_ON(smallLEDPanel_Port, smallLEDPanel_CLK);
	}

	PIN_ON(smallLEDPanel_Port, smallLEDPanel_LE);
}

void smallLEDPanel_Inc(unsigned short incVal)
{
	volatile unsigned char i;
	PIN_OFF(smallLEDPanel_Port, smallLEDPanel_LE);

	for (i=0; i < incVal; i++)
	{
		PIN_OFF(smallLEDPanel_Port, smallLEDPanel_CLK);
		PIN_ON(smallLEDPanel_Port, smallLEDPanel_CLK);
	}
	PIN_ON(smallLEDPanel_Port, smallLEDPanel_LE);
}
