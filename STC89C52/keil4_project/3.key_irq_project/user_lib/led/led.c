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

}

void led_enable(char enable)
{
	if(enable == TRUE)
	{
		led_init();
	}
}
