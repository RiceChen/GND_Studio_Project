/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : delay.h                         *
 **************************************************/
#ifndef _DELAY_H_
#define _DELAY_H_

#include <reg52.h>
#include <intrins.h>

void delay_ms(unsigned int xms);

void delay_us(unsigned int xus);

void delay_10us();

void delay_5us();

#endif