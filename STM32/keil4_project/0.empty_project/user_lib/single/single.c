#include "single.h"
#include "delay.h"

void single_pin_output(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 
	GPIO_SetBits(GPIOB, GPIO_Pin_8);			
}

void single_pin_input(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 		
}

void single_enable(char enable)
{
	if(enable == TRUE)
	{
		single_pin_output();
	}
}

void single_set_pin(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
}

void single_reset_pin(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
}

unsigned char single_read_pin(void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8);
}

unsigned char single_read_byte(void)
{
	unsigned char i, value=0;
	for(i=0;i<8;i++)    
	{
		while(single_read_pin() == Bit_RESET);
		delay_us(40);
		if(single_read_pin() == Bit_SET)
		{
			while(single_read_pin() == Bit_SET);
			value|=(uint8_t)(0x01<<(7-i));
		}
		else
		{			   
			value&=(uint8_t)~(0x01<<(7-i));
		}
	}
	return value;
}
