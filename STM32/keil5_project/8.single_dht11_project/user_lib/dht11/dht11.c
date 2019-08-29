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
	single_pin_output();
	single_reset_pin();
	delay_ms(18);
	single_set_pin();
	delay_us(30);
	single_pin_input();
	if(single_read_pin()==Bit_RESET)
	{
		while(single_read_pin()==Bit_RESET);
		while(single_read_pin()==Bit_SET);
		
		dht11_data.humi_int		= single_read_byte();
		dht11_data.humi_deci	= single_read_byte();
		dht11_data.temp_int		= single_read_byte();
		dht11_data.temp_deci	= single_read_byte();
		dht11_data.check_sum	= single_read_byte();
		single_pin_output();
		single_set_pin();
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
	
