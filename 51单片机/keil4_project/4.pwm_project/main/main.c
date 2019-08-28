/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/12                       *
 *         Last  : 2019/7/12                       *
 *         Notes : Ä£ÄâPWM---ºôÎüµÆ                *
 **************************************************/
#include "sys.h"
#include "delay.h"
#include "pwm.h"

void main()
{
	pwm_enable(TRUE);
	while(1)
	{
		unsigned char i;
		for(i = 100; i > 0; i-=10)
		{
			pwm_config(i);
			delay_ms(100);
		}
		for(i = 0; i < 100; i+=10)
		{
			pwm_config(i);
			delay_ms(100);
		}
	}
}