#include "led.h"
#include "sys.h"

void led_init()
{
	P22 = 0;
	P24 = 0;
}

void led_enable(char enable)
{
	if(enable == TRUE)
	{
		led_init();
	}
}
