/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : dht11.h                         *
 **************************************************/
#ifndef _DHT11_H_
#define _DHT11_H_

#include <reg52.h>

void dht11_enable(char enable);

unsigned char dht11_read_data(void);

typedef struct
{
	unsigned char humi_int;	
	unsigned char humi_deci;
	unsigned char temp_int;	
	unsigned char temp_deci;
	unsigned char check_sum;
		                 
}dht11_data_t;

unsigned char dht11_humi_int(void);
unsigned char dht11_humi_deci(void);
unsigned char dht11_temp_int(void);
unsigned char dht11_temp_deci(void);

#endif