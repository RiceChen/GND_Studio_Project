/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : single.c                        *
 *                 P1^6 | Data                     *
 **************************************************/
#include "sys.h"
#include "single.h"
#include "delay.h"

void single_enable(char enable)
{
	if(enable == TRUE)
	{
		P16 = 1;
	}
}

void single_set_pin(void)
{
	P16 = 1;
}

void single_reset_pin(void)
{
	P16 = 0;
}

unsigned char single_read_pin(void)
{
	return P16;
}

unsigned char single_read_byte(void)
{
	/* unsigned char i, value=0;
  	for(i=0;i<8;i++)
   	{          
      	while(Data == 0);
		delay_10us();
		delay_10us();
		delay_10us();
		delay_10us();
		value<<=1;
		if(Data == 1)     
        	value=value|0x01;
     	while(Data == 1);    
    }  
    return value; */
	unsigned char i, value=0;
	for(i=0;i<8;i++)    
	{
		while(single_read_pin() == Bit_RESET);
		delay_10us();
		delay_10us();
		delay_10us();
		delay_10us();
		if(single_read_pin() == Bit_SET)
		{
			while(single_read_pin() == Bit_SET);
			value|=(unsigned char)(0x01<<(7-i));
		}
		else
		{			   
			value&=(unsigned char)~(0x01<<(7-i));
		}
	}
	return value;
}
