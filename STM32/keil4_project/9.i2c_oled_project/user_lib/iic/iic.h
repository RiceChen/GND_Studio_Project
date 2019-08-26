#ifndef __IIC_H
#define __IIC_H 			   

#include "stm32f10x.h"

void iic_enable(unsigned int speed, char enable);
void iic_write_byte(unsigned char slave_addr, unsigned char reg_addr, unsigned char *data, unsigned char size);
void iic_read_byte(unsigned char slave_addr, unsigned char reg_addr, unsigned char *data, unsigned char size);

#endif





























