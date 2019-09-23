/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : oled.c                          *
 **************************************************/
#include "sys.h"
#include "word_lib.h"
#include "oled.h"
#include "delay.h"
#include "iic.h"


static void oled_write_data(unsigned char IIC_Data)
{
	IIC_Start();
	IIC_Write_Byte(0x78);
	IIC_Write_Byte(0x40);			//write data
	IIC_Write_Byte(IIC_Data);
	IIC_Stop();
}

static void oled_write_command(unsigned char IIC_Command)
{
	
	IIC_Start();
	IIC_Write_Byte(0x78);            //Slave address,SA0=0
	IIC_Write_Byte(0x00);			//write command
	IIC_Write_Byte(IIC_Command);
	IIC_Stop();
}

static void oled_set_pos(unsigned char x, unsigned char y) 
{ 
	oled_write_command(0xb0+y);
	oled_write_command(((x&0xf0)>>4)|0x10);
	oled_write_command((x&0x0f)|0x01);
} 

void oled_fill(unsigned char bmp_dat) 
{
	unsigned char y,x;
	for(y=0;y<8;y++)
	{
		oled_write_command(0xb0+y);
		oled_write_command(0x01);
		oled_write_command(0x10);
		for(x=0;x<128;x++)
			oled_write_data(bmp_dat);
			
	}
}

void oled_cls(void)
{
	unsigned char y,x;
	for(y=0;y<8;y++)
	{
		oled_write_command(0xb0+y);
		oled_write_command(0x01);
		oled_write_command(0x10);
		for(x=0;x<128;x++)
			oled_write_data(0);
	}
}

void oled_init()
{
	delay_ms(400);//初始化之前的延时很重要！
	oled_write_command(0xae);//--turn off oled panel
	oled_write_command(0x00);//---set low column address
	oled_write_command(0x10);//---set high column address
	oled_write_command(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	oled_write_command(0x81);//--set contrast control register
	oled_write_command(0xff); // Set SEG Output Current Brightness
	oled_write_command(0xa1);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	oled_write_command(0xc8);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	oled_write_command(0xa6);//--set normal display
	oled_write_command(0xa8);//--set multiplex ratio(1 to 64)
	oled_write_command(0x3f);//--1/64 duty
	oled_write_command(0xd3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	oled_write_command(0x00);//-not offset
	oled_write_command(0xd5);//--set display clock divide ratio/oscillator frequency
	oled_write_command(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	oled_write_command(0xd9);//--set pre-charge period
	oled_write_command(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	oled_write_command(0xda);//--set com pins hardware configuration
	oled_write_command(0x12);
	oled_write_command(0xdb);//--set vcomh
	oled_write_command(0x40);//Set VCOM Deselect Level
	oled_write_command(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
	oled_write_command(0x02);//
	oled_write_command(0x8d);//--set Charge Pump enable/disable
	oled_write_command(0x14);//--set(0x10) disable
	oled_write_command(0xa4);// Disable Entire Display On (0xa4/0xa5)
	oled_write_command(0xa6);// Disable Inverse Display On (0xa6/a7) 
	oled_write_command(0xaf);//--turn on oled panel
} 

void oled_enable(char enable)
{
	if(enable == TRUE)
	{
		oled_init();
	}
}

void oled_show_string(unsigned char x, y,unsigned char *ch, unsigned char text_size)
{
	unsigned char c=0,i=0,j=0;
	switch(text_size)
	{
		case OLED_TEXT_SIZE_6X8:
		{
			while(ch[j] != '\0') {
				c = ch[j] - 32;
				if(x > 126) {
					x = 0;
					y++;
				}
				oled_set_pos(x,y);
				for(i=0;i<6;i++) {
					oled_write_data(F6x8[c][i]);
				}
				x += 6;
				j++;
			}
		}
		break;
		case OLED_TEXT_SIZE_8X16:
		{
			while (ch[j]!='\0')
			{
				c =ch[j]-32;
				if(x>120){x=0;y++;}
					oled_set_pos(x,y);
				for(i=0;i<8;i++)
					oled_write_data(F8X16[c*16+i]);
				oled_set_pos(x,y+1);
				for(i=0;i<8;i++)
					oled_write_data(F8X16[c*16+i+8]);
				x+=8;
				j++;
			}
		}
		break;
	}	
}


