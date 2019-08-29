#include "led.h"
#include "key.h"
#include "iwdg.h"
#include "delay.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	delay_enable(TRUE);
	iwdg_enable(4, 625, TRUE); //1s
	led_enable(TRUE);
	key_enable(TRUE);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
	delay_ms(200);
	GPIO_ResetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
	for(;;)
	{
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
		{
			delay_ms(10);
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
			{
				iwdg_feed();
			}
		}
	}
}
