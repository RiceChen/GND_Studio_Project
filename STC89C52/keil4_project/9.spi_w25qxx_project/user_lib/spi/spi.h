/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : spi.h                           *
 **************************************************/
#ifndef _SPI_H_
#define _SPI_H_

#include <reg52.h>

void spi_enable(char enable);

unsigned char spi_read_write_byte(unsigned char value);

#endif