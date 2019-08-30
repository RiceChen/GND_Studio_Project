#include "led.h"
#include "wwdg.h"
#include "delay.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	delay_enable(TRUE);
	led_enable(TRUE);
	wwdg_enable(TRUE);
	
	for(;;)
	{
		if(wwdg_get_flag() == TRUE)
		{
			wwdg_set_flag(FALSE);
			GPIO_SetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
			delay_ms(200);
			GPIO_ResetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
			delay_ms(200);
		}
		else
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
			delay_ms(200);
		}
	}
}
