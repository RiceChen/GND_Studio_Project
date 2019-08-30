#include <reg52.h>
#include "sys.h"
#include "delay.h"

void main()
{
	while(1)
	{
		GPIO_SetBits(P22);
		delay_ms(1000);
		GPIO_ResetBits(P22);
		delay_ms(1000);
	}
}