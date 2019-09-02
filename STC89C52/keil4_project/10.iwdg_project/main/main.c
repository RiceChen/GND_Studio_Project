/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/12                       *
 *         Last  : 2019/7/12                       *
 *         Notes : ø¥√≈π∑                          *
 **************************************************/
#include <reg52.h>
#include "sys.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "iwdg.h"

void main(void)
{	
	iwdg_enable(TRUE);
	led_enable(TRUE);
	key_enable(TRUE);

	
	GPIO_SetBits(P22);
	GPIO_SetBits(P24);
	delay_ms(500);
	GPIO_ResetBits(P22);
	GPIO_ResetBits(P24);
	
	
	for(;;)
	{
		if(GPIO_ReadInputDataBit(P33) == 0)
		{
			delay_ms(10);
			if(GPIO_ReadInputDataBit(P33) == 0)
			{
				iwdg_feed();
			}
		}
	}
}
