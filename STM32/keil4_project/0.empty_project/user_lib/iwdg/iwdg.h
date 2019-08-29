#ifndef __IWDG_H
#define __IWDG_H

#include "stm32f10x.h"

void iwdg_enable(unsigned char prer, unsigned int rlr, char enable);
void iwdg_feed(void);

#endif
