#include "oled.h"
#include "iic.h"
#include "word_lib.h"
#include "delay.h"

#define OLED_ADDRESS						0x78

#define OLED_CMD_ADDRESS 				0x00
#define OLED_DATA_ADDRESS				0x40

static void oled_write_command(unsigned char cmd);
static void oled_write_data(unsigned char data);

static void oled_init()	 
{
	delay_ms(100);
	oled_write_command(0xAE);
	oled_write_command(0x20);
	oled_write_command(0x10);
	oled_write_command(0xb0);
	oled_write_command(0xc8);
	oled_write_command(0x00);
	oled_write_command(0x10);
	oled_write_command(0x40);
	oled_write_command(0x81);
	oled_write_command(0xff);
	oled_write_command(0xa1);
	oled_write_command(0xa6);
	oled_write_command(0xa8);
	oled_write_command(0x3F);
	oled_write_command(0xa4);
	oled_write_command(0xd3);
	oled_write_command(0x00);
	oled_write_command(0xd5);
	oled_write_command(0xf0);
	oled_write_command(0xd9);
	oled_write_command(0x22);
	oled_write_command(0xda);
	oled_write_command(0x12);
	oled_write_command(0xdb);
	oled_write_command(0x20);
	oled_write_command(0x8d);
	oled_write_command(0x14);
	oled_write_command(0xaf);
}

void oled_enable(char enable)
{
	if(enable == TRUE)
	{
		oled_init();
	}
}

static void oled_write_command(unsigned char cmd)
{
	unsigned char send_cmd[1];
	send_cmd[0] = cmd;
	iic_write_byte(OLED_ADDRESS, OLED_CMD_ADDRESS, send_cmd, 1);
}

static void oled_write_data(unsigned char data)
{
	unsigned char send_data[1];
	send_data[0] = data;
	iic_write_byte(OLED_ADDRESS, OLED_DATA_ADDRESS, send_data, 1);
}

void oled_fill(unsigned char fill_data)//È«ÆÁÌî³ä
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		oled_write_command(0xb0+m);
		oled_write_command(0x00);
		oled_write_command(0x10);
		for(n=0;n<128;n++)
		{
			oled_write_data(fill_data);
		}
	}
}

static void oled_set_pos(unsigned char x, unsigned char y)
{ 
	oled_write_command(0xb0+y);
	oled_write_command(((x&0xf0)>>4)|0x10);
	oled_write_command((x&0x0f)|0x01);
}

void oled_show_string(unsigned char x, unsigned char y, unsigned char *ch, unsigned char text_size)
{
	unsigned char c = 0,i = 0,j = 0;
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
		while(ch[j] != '\0') {
			c = ch[j] - 32;
			if(x > 120) {
				x = 0;
				y++;
			}
			oled_set_pos(x,y);
			for(i=0;i<8;i++) {
				oled_write_data(F8X16[c*16+i]);
			}
			oled_set_pos(x,y+1);
			for(i=0;i<8;i++) {
				oled_write_data(F8X16[c*16+i+8]);
			}
			x += 8;
			j++;
		}
	}
	break;
	}
}

