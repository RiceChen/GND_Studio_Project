#include "led.h"
#include "delay.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	delay_enable(TRUE);
	led_enable(TRUE);
	
	for(;;)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
		delay_ms(1000);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
		delay_ms(1000);
	}
}
