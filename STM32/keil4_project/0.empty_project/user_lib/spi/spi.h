#ifndef __IIC_H
#define __IIC_H 			   

#include "stm32f10x.h"

void spi_enable(unsigned char BaudRatePrescaler, char enable);
unsigned char spi_read_write_byte(unsigned char data);

#endif





























