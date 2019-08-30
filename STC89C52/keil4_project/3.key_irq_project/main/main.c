#include <reg52.h>
#include "sys.h"
#include "delay.h"
#include "key.h"
#include "led.h"
#include "exit.h"

void main()
{
	led_enable(TRUE);
	key_enable(TRUE);
	exit_enable(TRUE);
	for(;;)
	{
		;
	}
}