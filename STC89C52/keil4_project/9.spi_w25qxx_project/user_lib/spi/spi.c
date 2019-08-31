/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : spi.c                           *
 **************************************************/
#include "sys.h"
#include "spi.h"

void SPI_Init()
{
	GPIO_SetBits(P03);
	GPIO_SetBits(P00);
	GPIO_ResetBits(P02); 
}

void spi_enable(char enable)
{
	if(enable == TRUE)
	{
		SPI_Init();
	}
}

unsigned char spi_read_write_byte(unsigned char value)
{
    unsigned char i=0, temp=0;
    GPIO_ResetBits(P02);
    if(GPIO_ReadInputDataBit(P01) == 1)
		temp|=0x80;
    for(i=0;i<8;i++)
    {
        P00=value&(0x80>>i);
        GPIO_SetBits(P02);
        GPIO_ResetBits(P02);
        if(i<7)
			if(GPIO_ReadInputDataBit(P01) == 1)
				temp|=0x80>>(i+1);
    }
    return temp;
}
