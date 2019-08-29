#ifndef __dht11_H
#define __dht11_H

#include "stm32f10x.h"

void dht11_enable(char enable);

unsigned char dht11_read_data(void);

typedef struct
{
	unsigned char humi_int;		//湿度整数
	unsigned char humi_deci;	//湿度小数
	unsigned char temp_int;		//温度整数
	unsigned char temp_deci;	//温度小数
	unsigned char check_sum;
		                 
}dht11_data_t;

unsigned char dht11_humi_int(void);
unsigned char dht11_humi_deci(void);
unsigned char dht11_temp_int(void);
unsigned char dht11_temp_deci(void);

#endif
