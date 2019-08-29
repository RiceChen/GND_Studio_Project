#ifndef __ADC_H
#define __ADC_H

#include "stm32f10x.h"

void adc_enable(char enable);
unsigned int adc_get(char ch);

#endif
