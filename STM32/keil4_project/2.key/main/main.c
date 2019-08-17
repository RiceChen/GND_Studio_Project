#include "delay.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	delay_enable(TRUE);
	
	for(;;)
	{
	}
}
