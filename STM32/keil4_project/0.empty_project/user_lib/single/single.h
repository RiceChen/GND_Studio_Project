#ifndef __SINGLE_H
#define __SINGLE_H

#include "stm32f10x.h"

void single_pin_output(void);
void single_pin_input(void);

void single_enable(char enable);

unsigned char single_read_byte(void);

void single_set_pin(void);
void single_reset_pin(void);
unsigned char single_read_pin(void);

#endif
