/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : iic.c                           *
 **************************************************/
#include "sys.h"
#include "iic.h"

void IIC_Start()
{
   GPIO_SetBits(P14);		
   GPIO_SetBits(P15);
   GPIO_ResetBits(P15);
   GPIO_ResetBits(P14);
}

void IIC_Stop()
{
   GPIO_ResetBits(P14);
   GPIO_ResetBits(P15);
   GPIO_SetBits(P14);
   GPIO_SetBits(P15);
}

void IIC_Enable(char enable)
{
	if(enable == TRUE)
	{
		IIC_Start();
	}
}

void IIC_Write_Byte(unsigned char IIC_Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(IIC_Byte & 0x80)
			GPIO_SetBits(P15);
		else
			GPIO_ResetBits(P15);
		GPIO_SetBits(P14);
		GPIO_ResetBits(P14);
		IIC_Byte<<=1;
	}
	GPIO_SetBits(P15);
	GPIO_SetBits(P14);
	GPIO_ResetBits(P14);
}
