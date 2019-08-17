#include "key.h"

void key_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_0;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 		
}

void key_enable(char enable)
{
	if(enable == TRUE)
	{
		key_init();
	}
}