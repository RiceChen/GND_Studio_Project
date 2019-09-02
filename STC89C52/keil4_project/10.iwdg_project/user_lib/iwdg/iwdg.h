#ifndef _IWDG_H_
#define _IWDG_H_

#include <reg52.h>

void iwdg_enable(char enable);
void iwdg_feed(void);

#endif
