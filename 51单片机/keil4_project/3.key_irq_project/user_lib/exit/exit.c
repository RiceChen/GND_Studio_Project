/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : exit.c                          *
 **************************************************/
#include "exit.h"
#include "delay.h"
#include "sys.h"

void exit_init()
{
	EA = 1;	
	IT1 = 1;
	EX1 = 1;	
}

void exit_enable(char enable)
{
	if(enable == TRUE)
	{
		exit_init();
	}
	else
		EA = 0;
}

void exit1() interrupt 2
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(P33) == 0)
	{
		GPIO_SetBits(P12);
		delay_ms(100);
		GPIO_ResetBits(P12);
	}
}