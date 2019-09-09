#include "delay.h"
#include "led.h"
#include "key.h"
#include "exit.h"
#include "wdg.h"

int main(void)
{	
	delay_enable(TRUE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	led_enable(TRUE);
	key_enable(TRUE);
	delay_ms(500);   	 //让人看得到灭
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	IWDG_Init(4,625);    //与分频数为64,重载值为625,溢出时间为1s
	for(;;)
	{
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
		{
			delay_ms(10);
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
			{
				IWDG_Feed();
			}
		}
		delay_ms(10);
	}
}

