/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : single.h                        *
 *                 P1^6 | Data                     *
 **************************************************/
#ifndef _SINGLE_H_
#define _SINGLE_H_

#include <reg52.h>

void single_enable(char enable);

unsigned char single_read_byte(void);

void single_set_pin(void);

void single_reset_pin(void);

unsigned char single_read_pin(void);

#endif