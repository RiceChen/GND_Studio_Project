#include "iwdg.h"

//时间计算(大概):Tout=((4*2^prer)*rlr)/40 (ms).
void iwdg_init(unsigned char prer, unsigned int rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(prer);
	IWDG_SetReload(rlr);
	IWDG_ReloadCounter();
	IWDG_Enable();		
}

void iwdg_enable(unsigned char prer, unsigned int rlr, char enable)
{
	if(enable == TRUE)
	{
		iwdg_init(prer, rlr);
	}
}

void iwdg_feed(void)
{   
 	IWDG_ReloadCounter();//reload										   
}
