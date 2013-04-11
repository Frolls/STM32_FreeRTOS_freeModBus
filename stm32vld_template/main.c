/*
 * main.c
 *
 *  Created on: 12.03.2013
 *      Author: Frolls
 */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
//#include "queue.h"
//#include "timers.h"

// Modbus
//#include "mb.h"
//#include "mbport.h"

/* STM32 Library includes. */
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_usart.h>
#include <stm32f10x_exti.h>
#include <misc.h>

#include "timer6.h"
#include "ds1821.h"
#include "rtc.h"

#include "smallLEDPanel.h"


#define LED_PORT GPIOC
#define LED_GREEN GPIO_Pin_9
#define LED_BLUE GPIO_Pin_8

#define One_Wire_Pin 			GPIOC, GPIO_Pin_7

#define smallLEDPanel_CLK 		GPIO_Pin_10
#define smallLEDPanel_SDI 		GPIO_Pin_11
#define smallLEDPanel_LE 		GPIO_Pin_12

#define BAUDRATE 115200

volatile uint16_t counter = 0;

unsigned char error_handle (unsigned char err);

void SetupClock()
{
	RCC_DeInit ();                    /* RCC system reset(for debug purpose)*/
	RCC_HSEConfig (RCC_HSE_ON);       /* Enable HSE                         */

	/* Wait till HSE is ready                                               */
	while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);

	RCC_HCLKConfig   (RCC_SYSCLK_Div1);   /* HCLK   = SYSCLK                */
	RCC_PCLK2Config  (RCC_HCLK_Div1);     /* PCLK2  = HCLK                  */
	RCC_PCLK1Config  (RCC_HCLK_Div1);     /* PCLK1  = HCLK1                */
	//RCC_ADCCLKConfig (RCC_PCLK2_Div4);    /* ADCCLK = PCLK2/4               */

	/* PLLCLK = 8MHz * 6 = 48 MHz                                           */
	RCC_PLLConfig (RCC_PLLSource_PREDIV1, RCC_PLLMul_6);

	RCC_PLLCmd (ENABLE);                  /* Enable PLL                     */

	/* Wait till PLL is ready                                               */
	while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

	/* Select PLL as system clock source                                    */
	RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);

	/* Wait till PLL is used as system clock source                         */
	while (RCC_GetSYSCLKSource() != 0x08);
}

void LEDsInit()
{
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
   GPIO_InitTypeDef GPIO_InitStructure;
   /* Ñâåòîäèîäû íà PC8, PC9          */
   GPIO_InitStructure.GPIO_Pin   = LED_GREEN | LED_BLUE;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
   GPIO_Init(LED_PORT, &GPIO_InitStructure);
}

void BtnInit()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
}

/*******************************************************************************
* Function Name  : USART_GPIO_Configuration
* Description    : Configures the different GPIO ports.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART_GPIO_Configuration(void)
{
  /* Enable GPIOA clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  GPIO_InitTypeDef GPIO_InitStructure;

  /* Configure USART1 Tx (PA.09) as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure USART1 Rx (PA.10) as input floating */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*******************************************************************************
* Function Name  : USART_Configuration
* Description    : Configures the USART1.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART_Configuration(void)
{
  /* Enable USART1 */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

  USART_InitTypeDef USART_InitStructure;

/* USART1 configuration ------------------------------------------------------*/
  /* USART1 configured as follow:
        - BaudRate = 115200 baud
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
        - USART Clock disabled
        - USART CPOL: Clock is active low
        - USART CPHA: Data is captured on the middle
        - USART LastBit: The clock pulse of the last data bit is not output to
                         the SCLK pin
  */
  USART_InitStructure.USART_BaudRate = BAUDRATE;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART1, &USART_InitStructure);

  /* Enable USART1 */
  USART_Cmd(USART1, ENABLE);

  uart_print_string(USART1, "\n===== UART1 инициализирован =====",1);
}

void EXTI_Configuration(void)
{
  EXTI_InitTypeDef EXTI_InitStructure;
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
}

void NVIC_Configuration_USART1(void)
{
	//configure NVIC
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Place the vector table into FLASH */
	//NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	//select NVIC channel to configure
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	//set priority to lowest
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = configLIBRARY_LOWEST_INTERRUPT_PRIORITY;
	//set subpriority to lowest
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = configLIBRARY_LOWEST_INTERRUPT_PRIORITY;
	//enable IRQ channel
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	//update NVIC registers
	NVIC_Init(&NVIC_InitStructure);

	//disable Transmit Data Register empty interrupt
	USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
	//enable Receive Data register not empty interrupt
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);


}

void NVIC_Configuration_USER_BUTTON(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = configLIBRARY_LOWEST_INTERRUPT_PRIORITY;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = configLIBRARY_LOWEST_INTERRUPT_PRIORITY;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI0_IRQHandler(void)
{
        EXTI_ClearITPendingBit(EXTI_Line0);

        uart_print_string(USART1, "Тынц",1);
		{
			LED_PORT->ODR |= LED_GREEN;
			//vTaskDelay(10);
			delay_ms(10);
			LED_PORT->ODR ^= LED_GREEN;
		}
}

void vFreeRTOSInitAll()
{
	SetupClock();

	LEDsInit();
	smallLEDPanel_Init();//LED_PORT, smallLEDPanel_CLK, smallLEDPanel_SDI, smallLEDPanel_LE);

	BtnInit();

	EXTI_Configuration();

	USART_GPIO_Configuration();
	USART_Configuration();

	NVIC_Configuration_USER_BUTTON();
	NVIC_Configuration_USART1();

	TIM6Init();

	RTC_Config();

}

void vTaskLED(void *pvParameters)
{

        for (;;) {
        	//delay_ms(500);
        	LED_PORT->ODR ^= LED_BLUE;
            vTaskDelay(500);

        }
        vTaskDelete(NULL);

}

void USART1_IRQHandler(void)
{

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	    {
		   // перемырг
		   //LED_PORT->ODR |= LED_BLUE;
		   //USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		   uint16_t i = USART_ReceiveData(USART1);
		   UARTSend(&i, 1);
		   //LED_PORT->ODR ^= LED_BLUE;
		   //UARTSend(&i, 1);
          // UARTSend(" <-- data\r\n", 10);
        }
}

void vTaskUSART_TX(void *pvParameters)
{
	for (;;) {

		uart_print_string(USART1, "Сцуко, отладь меня..",1);
		// перемырг
		{
			LED_PORT->ODR |= LED_GREEN;
			vTaskDelay(10);
			LED_PORT->ODR ^= LED_GREEN;
		}
		vTaskDelay(1000);
	}

    vTaskDelete(NULL);
}

void vTaskDS1821(void *pvParameters)
{
	uart_print_string(USART1,"Температура:   ",0);
	for(;;)
	{
		///// 1-wire /////
			signed int t;

			//uart_print_string(USART1, "Сбрасываем..",1);

			//error_handle(One_Wire_Reset(One_Wire_Pin));

			//error_handle(DS1821_Write_Status(One_Wire_Pin));

			//error_handle(DS1821_Start_Conversion(One_Wire_Pin));
			DS1821_Start_Conversion(One_Wire_Pin);
			//delay_ms(750);

			//error_handle(DS1821_Stop_Conversion(One_Wire_Pin));
			//error_handle(DS1821_Read_Temp(&t, One_Wire_Pin));
			uart_print_string(USART1, "Температура:   ", 0);
			DS1821_Read_Temp(&t, One_Wire_Pin);
			uart_send_char(USART1, 8);
			uart_send_char(USART1, 8);
			uart_print_value(USART1, t);
			uart_print_string(USART1,";",0);
			LED_PORT->ODR |= LED_GREEN;
						//vTaskDelay(10);
			delay_ms(10);
			LED_PORT->ODR ^= LED_GREEN;
			uart_print_string(USART1, " Uptime: ", 0);
			uart_print_value(USART1, Time_GetHours(GetTime()));
			uart_print_string(USART1, ":", 0);
			uart_print_value(USART1, Time_GetMinutes(GetTime()));
			uart_print_string(USART1, ":", 0);
			uart_print_value(USART1, Time_GetSeconds(GetTime()));
			uart_print_string(USART1, "", 1);
			//////////////////
			vTaskDelay(1000);
	}
	vTaskDelete(NULL);
}



int main()
{
	vFreeRTOSInitAll();

	xTaskCreate( vTaskLED, ( signed char * ) "LED", configMINIMAL_STACK_SIZE, NULL, 2,
	                        ( xTaskHandle * ) NULL);
	//xTaskCreate(vTaskUSART_TX, (signed char*)"USART_TX", configMINIMAL_STACK_SIZE, NULL, 2,
      //      				( xTaskHandle * ) NULL);
	xTaskCreate( vTaskDS1821, ( signed char * ) "DS1821", configMINIMAL_STACK_SIZE, NULL, 2,
		                    ( xTaskHandle * ) NULL);
	vTaskStartScheduler();



	for(;;)
	{
//
	}
	return 0;
}

unsigned char error_handle (unsigned char err)
{
	switch (err)
		{
		 	case One_Wire_Success: 					uart_print_string(USART1, "Success! GoodLuck!",1); break;
		 	case One_Wire_Error_No_Echo: 			uart_print_string(USART1, "No echo from device!",1); break;
		 	case One_Wire_Bus_Low_Error: 			uart_print_string(USART1, "Pin LOW error!",1); break;
		 	case One_Wire_CRC_Error: 				uart_print_string(USART1, "CRC not match!",1); break;
		}
		if (err==One_Wire_Success) return 0; else return 1;//uart_print_string(USART1, "GoodLuck!",1);
}

void vApplicationMallocFailedHook( void )
{
	/* Called if a call to pvPortMalloc() fails because there is insufficient
	free memory available in the FreeRTOS heap.  pvPortMalloc() is called
	internally by FreeRTOS API functions that create tasks, queues, software
	timers, and semaphores.  The size of the FreeRTOS heap is set by the
	configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configconfigCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
volatile size_t xFreeStackSpace;

	/* This function is called on each cycle of the idle task.  In this case it
	does nothing useful, other than report the amout of FreeRTOS heap that
	remains unallocated. */
	xFreeStackSpace = xPortGetFreeHeapSize();

	if( xFreeStackSpace > 100 )
	{
		/* By now, the kernel has allocated everything it is going to, so
		if there is a lot of heap remaining unallocated then
		the value of configTOTAL_HEAP_SIZE in FreeRTOSConfig.h can be
		reduced accordingly. */
	}
}

/*******************************************************************************
* Function Name  : UARTSend
* Description    : Send a string to the UART.
* Input          : - pucBuffer: buffers to be printed.
*                : - ulCount  : buffer's length
* Output         : None
* Return         : None
*******************************************************************************/
void UARTSend(const unsigned char *pucBuffer, unsigned long ulCount)
{
    //
    // Loop while there are more characters to send.
    //
    while(ulCount--)
    {
        USART_SendData(USART1, (uint16_t) *pucBuffer++);
        /* Loop until the end of transmission */
        while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
        {
        }
    }
}
