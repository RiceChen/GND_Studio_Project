#include "wwdg.h"

unsigned char wwdg_flag = FALSE;
unsigned char wwdg_sount = 0x7f;

// Fwwdg=PCLK1/(4096*2^fprer). 
void wwdg_init(unsigned char time_value, unsigned char window_value, unsigned int fprer)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	wwdg_sount = time_value & wwdg_sount;
  
	WWDG_SetPrescaler(fprer);
	WWDG_SetWindowValue(window_value);
	WWDG_Enable(wwdg_sount);                
	WWDG_ClearFlag();
	
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
	
	WWDG_EnableIT();
}

void wwdg_enable(char enable)
{
	if(enable == TRUE)
	{
		wwdg_init(0x7f, 0x5f, WWDG_Prescaler_8);
	}
}

void WWDG_IRQHandler(void)
{
	WWDG_SetCounter(wwdg_sount);
	WWDG_ClearFlag();
	wwdg_flag = TRUE;
}

unsigned char wwdg_get_flag(void)
{
	return wwdg_flag;
}

void wwdg_set_flag(unsigned char flag)
{
	wwdg_flag = flag;
}
