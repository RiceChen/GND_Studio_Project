/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : led.c                           *
 **************************************************/
#include "led.h"
#include "sys.h"

void led_init()
{
	GPIO_ResetBits(P22);
	GPIO_ResetBits(P24);
}

void led_enable(char enable)
{
	if(enable == TRUE)
	{
		led_init();
	}
}
