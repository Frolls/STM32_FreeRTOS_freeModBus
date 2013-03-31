/*
 * serial.c
 *
 *  Created on: 22.03.2013
 *      Author: frolls
 */
#include "serial.h"
void uart_send_char (USART_TypeDef * USARTx, char dat)
{
	while (!(USARTx->SR & USART_SR_TXE)) {}
  	USART_SendData(USARTx,dat);
}

void uart_print_string(USART_TypeDef * USARTx, char * string, char newline)
{
	while (*string != 0x00){ uart_send_char(USARTx, *string++);}
	if (newline !=0 ){
		uart_send_char(USARTx, '\n');
		//uart_send_char(USARTx, 13);
	}
}

void uart_print_value(USART_TypeDef * USARTx, long val)
{
	char buffer[10] = {0};
	char * head = buffer;
	char cnt=0;
	if (val!=0)
	{
		while( val )
		{
    		*head++ = (val % 10)["0123456789"];
    		val /= 10;
			cnt++;
		}
		while (cnt!=0){ cnt--; uart_send_char(USARTx, (buffer[cnt])); }
	}
	else
	{
		uart_send_char(USARTx, ('0'));
	}
}

void uart_print_hex_value(USART_TypeDef * USARTx, long val)
{
	char buffer[10] = {0};
	char * head = buffer;
	char cnt=0;
	uart_send_char(USARTx, ('0'));
	uart_send_char(USARTx, ('x'));
	if (val<=9)	uart_send_char(USARTx, ('0'));
	if (val!=0)
	{
		while( val )
		{
    		*head++ = (val & 0x0F)["0123456789ABCDEF"];
    		val=val>>4;
			cnt++;
		}
		while (cnt!=0){ cnt--; uart_send_char(USARTx, (buffer[cnt])); }
	}
	else
	{
		uart_send_char(USARTx, ('0'));
	}
	uart_send_char(USARTx, (' '));
}


