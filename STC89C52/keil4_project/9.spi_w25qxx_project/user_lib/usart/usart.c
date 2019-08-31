/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : usart.c                         *
 **************************************************/
#include "sys.h"
#include "usart.h"

void usart_init()
{											  
	SCON = 0x50;
	TMOD = 0x20;
	PCON = 0x80;
	
	TH1 = 0xFA;
	TL1 = 0xFA;
	
	TR1 = 1 ;
	ES = 1;
	EA = 1;
	TI = 1;
}

void Usart_Enable(char enable)
{
	if(enable == TRUE) 
	{
		usart_init();
	}
}