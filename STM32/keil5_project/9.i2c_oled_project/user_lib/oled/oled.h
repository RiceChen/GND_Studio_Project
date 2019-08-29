#ifndef __OLED_H
#define __OLED_H 			   

#include "stm32f10x.h"
 
#define OLED_FILL_WHITE_DATA		0xff
#define OLED_FILL_BLACK_DATA		0x00

#define OLED_TEXT_SIZE_6X8			0
#define OLED_TEXT_SIZE_8X16			1

void oled_enable(char enable);
void oled_fill(unsigned char fill_data);
void oled_show_string(unsigned char x, unsigned char y, unsigned char *ch, unsigned char text_size);

#endif





























