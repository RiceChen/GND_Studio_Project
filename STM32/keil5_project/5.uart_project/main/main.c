#include "delay.h"
#include "usart.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_enable(TRUE);
	uart1_enable(115200, TRUE);
	
	for(;;)
	{
		printf("GND studio!!!\r\n");
		delay_ms(1000);
	}
}
