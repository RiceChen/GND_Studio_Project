/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : delay.c                         *
 **************************************************/
#include "sys.h"
#include "delay.h"

void delay_ms(unsigned int xms)
{
    unsigned char i;
    while(--xms)
    {
        for(i = 0; i < 110; i++);
    }
}

void delay_us(unsigned int xus)
{ 	
	unsigned char i;
	i = xus;
    while(--i);
}

void delay_10us() 
{ 
	unsigned char i;

	i = 2;
	while (--i);
}

void delay_5us()	
{
}

