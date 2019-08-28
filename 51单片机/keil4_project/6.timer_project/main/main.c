#include <reg52.h>
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "timer.h"

void main()
{
	led_enable(TRUE);
	timer_enable(TRUE);
	for(;;)
	{
		GPIO_ResetBits(P12);
	}
}