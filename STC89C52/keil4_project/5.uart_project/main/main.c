#include <reg52.h>
#include "sys.h"
#include "delay.h"
#include "usart.h"

int main(void)
{	
	Usart_Enable(TRUE);
	for(;;)
	{
		printf("GND studio!!!\r\n");
		delay_ms(1000);
	}
}
