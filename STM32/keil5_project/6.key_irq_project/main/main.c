#include "delay.h"
#include "led.h"
#include "key.h"
#include "exit.h"


int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	delay_enable(TRUE);
	led_enable(TRUE);
	key_enable(TRUE);
	exit_enable(TRUE);
	for(;;)
	{
		;
	}
}

//外部中断0服务程序 
void EXTI0_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
	{
		EXTI_ClearITPendingBit(EXTI_Line0);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		delay_ms(100);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
}
 
//外部中断1服务程序
void EXTI1_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		EXTI_ClearITPendingBit(EXTI_Line1);
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		delay_ms(100);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	}
}
