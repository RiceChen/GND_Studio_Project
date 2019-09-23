/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : dht11.h                         *
 **************************************************/
#include "sys.h"
#include "dht11.h"
#include "single.h"
#include "delay.h"

dht11_data_t dht11_data;

void dht11_enable(char enable)
{
	single_enable(enable);
}

unsigned char dht11_read_data(void)
{
	P16 = 0;
	delay_ms(20);
	P16 = 1;
	delay_10us();
	delay_10us();
	delay_10us();
	if(P16==Bit_RESET)
	{
		while(P16==Bit_RESET);
		delay_10us();
		delay_10us();
		delay_10us();
		delay_10us();
		delay_10us();
		delay_10us();
		delay_10us();
		delay_10us();
		dht11_data.humi_int		= single_read_byte();
		dht11_data.humi_deci	= single_read_byte();
		dht11_data.temp_int		= single_read_byte();
		dht11_data.temp_deci	= single_read_byte();
		dht11_data.check_sum	= single_read_byte();
		P16 = 1;
		if(dht11_data.check_sum == dht11_data.humi_int + dht11_data.humi_deci + dht11_data.temp_int+ dht11_data.temp_deci)
			return TRUE;
		else
			return FALSE;
	}
	
	return FALSE;
}

unsigned char dht11_humi_int(void)
{
	return dht11_data.humi_int;
}

unsigned char dht11_humi_deci(void)
{
	return dht11_data.humi_deci;
}

unsigned char dht11_temp_int(void)
{
	return dht11_data.temp_int;
}

unsigned char dht11_temp_deci(void)
{
	return dht11_data.temp_deci;
}
	