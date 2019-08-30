#include "sys.h"
#include "delay.h"
#include "led.h"
#include "key.h"

int main(void)
{	
	led_enable(TRUE);
	key_enable(TRUE);	
	for(;;)
	{
		if(GPIO_ReadInputDataBit(P33) == 0)
		{
			delay_ms(10);
			if(GPIO_ReadInputDataBit(P33) == 0)
			{
				GPIO_SetBits(P22);
			}
		}
		else
		{
			GPIO_ResetBits(P22);
		}
		
		if(GPIO_ReadInputDataBit(P21) == 0)
		{
			delay_ms(10);
			if(GPIO_ReadInputDataBit(P21) == 0)
			{
				GPIO_SetBits(P24);
			}
		}
		else
		{
			GPIO_ResetBits(P24);
		}
	}
}
