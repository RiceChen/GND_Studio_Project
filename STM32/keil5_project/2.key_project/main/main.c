#include "delay.h"
#include "led.h"
#include "key.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	delay_enable(TRUE);
	led_enable(TRUE);
	key_enable(TRUE);	
	for(;;)
	{
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
		{
			delay_ms(10);
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
			{
				GPIO_SetBits(GPIOA, GPIO_Pin_2);
			}
		}
		else
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		}
		
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
		{
			delay_ms(10);
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
			{
				GPIO_SetBits(GPIOA, GPIO_Pin_4);
			}
		}
		else
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		}
	}
}
