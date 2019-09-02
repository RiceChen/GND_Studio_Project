/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : iwdg.c                          *
 **************************************************/
#include "sys.h"
#include "iwdg.h"

sfr WDT_CONTR = 0xE1;

void iwdg_init()
{
	 WDT_CONTR = 0x35;
}

void iwdg_enable(char enable)
{
	if(enable == TRUE)
	{
		iwdg_init();
	}
	else
		WDT_CONTR &= 0xEF;	
}

void iwdg_feed(void)
{   
 	WDT_CONTR = 0x35;										   
}
