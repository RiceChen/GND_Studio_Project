/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : single.c                        *
 **************************************************/
#include "sys.h"
#include "single.h"
#include "delay.h"


void single_enable(char enable)
{
	if(enable == TRUE)
	{
		GPIO_SetBits(P16);
	}
}

void single_set_pin(void)
{
	GPIO_SetBits(P16);
}

void single_reset_pin(void)
{
	GPIO_ResetBits(P16);
}

unsigned char single_read_pin(void)
{
	return GPIO_ReadInputDataBit(P16);
}

unsigned char single_read_byte(void)
{
	unsigned char i, value=0;
  	for(i=0;i<8;i++)
   	{          
      	while(P16 == 0);
		delay_10us();
		delay_10us();
		delay_10us();
		delay_10us();
		value<<=1;
		if(P16 == 1)     
        	value=value|0x01;
     	while(P16 == 1);    
    }  
    return value;
}
