#include "delay.h"
#include "pwm.h"

int main(void)
{	
	unsigned int pwm = 0;
	char dirction = 1;
	delay_enable(TRUE);
	pwm_enable(899, 0, TRUE);

	for(;;)
	{
		if(dirction == 1)
			pwm++;
		else
			pwm--;
		
		if(pwm > 300) 
			dirction = 0;
		if(pwm <= 0)
			dirction = 1;
		TIM_SetCompare3(TIM2, pwm);
		delay_ms(10);
	}
}
