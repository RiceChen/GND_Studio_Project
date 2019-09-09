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
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	delay_ms(1000);	  
	WWDG_Init(0X7F,0X5F,WWDG_Prescaler_8);//������ֵΪ7f,���ڼĴ���Ϊ5f,��Ƶ��Ϊ8	   
	for(;;)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
}

