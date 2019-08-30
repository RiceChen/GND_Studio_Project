#ifndef __IWDG_H
#define __IWDG_H

#include "stm32f10x.h"

void wwdg_enable(char enable);
unsigned char wwdg_get_flag(void);
void wwdg_set_flag(unsigned char flag);

#endif
