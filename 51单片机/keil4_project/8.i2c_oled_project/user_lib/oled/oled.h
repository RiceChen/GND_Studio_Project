/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : oled.h                          *
 **************************************************/
#ifndef _OLED_H_
#define _OLED_H_

#include <reg52.h>

void oled_enable(char enable);

void oled_show_string(unsigned char x, y,unsigned char *ch, unsigned char text_size);

void oled_cls(void);

void oled_fill(unsigned char bmp_dat);

#endif
