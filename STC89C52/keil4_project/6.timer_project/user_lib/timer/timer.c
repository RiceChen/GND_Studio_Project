/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : timer.c                         *
 **************************************************/
#include "timer.h"
#include "delay.h"
#include "sys.h"

unsigned char flag, i = 20;

void timer_init()
{
  	TMOD = 0x01;
	ET0 = 1;
	EA = 1;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TF0 = 0;
	TR0 = 1;		
}

void timer_enable(char enable)
{
	if(enable == TRUE)
	{
		timer_init();
	}
}

void timer()interrupt 1
{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	i--;
	if(i == 0)
	{
		i = 20;
		GPIO_SetBits(P12);
		delay_ms(100);
	}
	TR0 = 1;
}

