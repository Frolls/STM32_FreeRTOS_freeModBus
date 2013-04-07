/*
 * rtc.c
 *
 *  Created on: 07.04.2013
 *      Author: frolls
 */

#include <rtc.h>

void RTC_Config(void)
{
        //NVIC_InitTypeDef NVIC_InitStructure;

        /* Configure one bit for preemption priority */
        //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

        /* Enable the RTC Interrupt */
        //NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
        //NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
        //NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
        //NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        //NVIC_Init(&NVIC_InitStructure);

        RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

        PWR_BackupAccessCmd(ENABLE);
        RCC_LSEConfig(RCC_LSE_ON);
        while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET);
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
        RCC_RTCCLKCmd(ENABLE);

        RTC_WaitForSynchro();
        RTC_WaitForLastTask();
        //RTC_ITConfig(RTC_IT_SEC, ENABLE);
        RTC_WaitForLastTask();
        RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */
        RTC_WaitForLastTask();
}

uint32_t GetTime(void)
{
	/* Reset RTC Counter when Time is 23:59:59 */
	    if (RTC_GetCounter() == 0x0001517F)
	    {
	        RTC_SetCounter(0x0);
	        /* Wait until last write operation on RTC registers has finished */
	        RTC_WaitForLastTask();
	    }
	return RTC_GetCounter();
}

uint32_t Time_GetHours(uint32_t TimeVar)
{
    /* Compute  hours */
    return TimeVar / 3600;
}

uint32_t Time_GetMinutes(uint32_t TimeVar)
{
	return (TimeVar % 3600) / 60;
}

uint32_t Time_GetSeconds(uint32_t TimeVar)
{
	return (TimeVar % 3600) % 60;
}
