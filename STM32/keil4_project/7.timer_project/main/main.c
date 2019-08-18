#include "led.h"
#include "delay.h"
#include "timer.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	delay_enable(TRUE);
	led_enable(TRUE);
	timer_enable(4999, 7199, TRUE);
	
	for(;;)
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
	}
}

//定时器3中断服务程序
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //清除TIMx更新中断标志 
		GPIO_SetBits(GPIOA, GPIO_Pin_4|GPIO_Pin_2);
		delay_ms(100);
	}
}
