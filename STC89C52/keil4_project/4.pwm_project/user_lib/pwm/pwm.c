/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : pwm.c                           *
 **************************************************/
#include "sys.h"
#include "pwm.h"

unsigned char High_H, High_L, Low_H, Low_L, flag = 1;

void pwm_init()
{
	TMOD = 0x01;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void pwm_enable(char enable)
{
	if(enable == TRUE)
	{
		pwm_init();
	}
	else
	{
		EA = 0;
		TR0 = 0;
	}			
}

void pwm_config(unsigned char duty)
{
	if(duty > 100)
		duty = 100;
	else if (duty < 0 )
		duty = 0;

	High_H = (65535-duty)/256;
	High_L = (65535-duty)%256;
	Low_H  = (65535-(100-duty))/256;
	Low_L  = (65535-(100-duty))%256;	
}

void Timer0_pwm() interrupt 1
{
	if(flag)
	{
		TH0 = High_H;
		TH0 = High_L;
		GPIO_ResetBits(pwm);
		flag = 0;
	}
	else
	{
		TH0 = Low_H;
		TH0 = Low_L;
		GPIO_SetBits(pwm);
		flag = 1;	
	}
}