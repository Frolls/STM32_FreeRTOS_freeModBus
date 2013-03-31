/*
 * timer6.c
 *
 *  Created on: 21.03.2013
 *      Author: frolls
 */
#include "timer6.h"

void TIM6Init()
{
  /* Не забываем затактировать таймер */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
  /*
  NVIC_Configuration_TIM6();

  TIM_DeInit(TIM6);

  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);

  TIM_TimeBaseStructure.TIM_Prescaler = (SYS_CLK / PRESCALER_TIM_FREQUENCY) - 1;
  TIM_TimeBaseStructure.TIM_Period = 500;//UINT16_MAX;
  //TIM_SetCounter(TIM6, 1);

  //TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
  TIM_Cmd(TIM6, ENABLE);

  TIM_SelectOnePulseMode(TIM6, TIM_OPMode_Single);
  TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
  */

  //uart_print_string(USART1, "TIM6 initialized!", 1);
  //uart_print_string(USART1, "TIM_TimeBaseStructure.TIM_Prescaler: ", 0);
  //uart_print_value(USART1, TIM_TimeBaseStructure.TIM_Prescaler);
  //uart_print_string(USART1, "", 1);
}

void NVIC_Configuration_TIM6(void)
{
	//configure NVIC
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	//select NVIC channel to configure
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;
	//set priority to lowest
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//configLIBRARY_LOWEST_INTERRUPT_PRIORITY;
	//set subpriority to lowest
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 15;//configLIBRARY_LOWEST_INTERRUPT_PRIORITY;
	//enable IRQ channel
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	//update NVIC registers
	NVIC_Init(&NVIC_InitStructure);
}

volatile uint8_t delay_end = 0;

void TIM6_DAC_IRQHandler()
{
  /* Так как этот обработчик вызывается и для ЦАП, нужно проверять,
   * произошло ли прерывание по переполнению счётчика таймера TIM6.
   */
	if(TIM_GetITStatus(TIM6, TIM_FLAG_Update)!=RESET)
	  {
	   TIM_ClearITPendingBit(TIM6, TIM_FLAG_Update);
	   TIM_Cmd(TIM6, DISABLE);
	   TIM_SetCounter(TIM6, 0);
	   delay_end = 1;
	  }
}

void delay_ms(uint16_t delay)
{
	 TIM6->PSC = (SYS_CLK / PRESCALER_TIM_FREQUENCY)*1000 - 1;
	 TIM6->ARR = delay;
	 TIM6->EGR |= TIM_EGR_UG;
     TIM6->CR1 |= TIM_CR1_CEN|TIM_CR1_OPM;
     while ((TIM6->CR1 & TIM_CR1_CEN)!=0);
}

void delay_us(uint16_t delay)
{
	TIM6->PSC = (SYS_CLK / PRESCALER_TIM_FREQUENCY) - 1;
	TIM6->ARR = delay;
	TIM6->EGR |= TIM_EGR_UG;
	TIM6->CR1 |= TIM_CR1_CEN|TIM_CR1_OPM;
    while ((TIM6->CR1 & TIM_CR1_CEN)!=0);
}


/*
void delay_us(uint16_t us)
{
  delay_end=0;
  TIM_SetCounter(TIM6, us);
  TIM_ClearITPendingBit(TIM6, TIM_FLAG_Update);
  TIM_Cmd(TIM6, ENABLE);
  while(delay_end==0)
    continue;
  uart_print_string(USART1, "TIM6 int!", 1);
}
*/
/*
void delay_us(uint16_t uSecs) {
   volatile uint16_t start = TIM6->CNT;
   while ((uint16_t)(TIM6->CNT - start) < uSecs);
}
*/
/*
void delay_ms(uint16_t mSecs) {
	volatile uint16_t i;
   for (i = mSecs; i > 0; i--)
      delay_us(1000);
}
*/
