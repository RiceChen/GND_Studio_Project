#include <reg52.h>
#include <stdio.h>
#include "sys.h"
#include "delay.h"
#include "dht11.h"
#include "usart.h"

unsigned char i=0;

void main()
{
	Usart_Enable(TRUE);
	dht11_enable(TRUE);
	
	for(;;)
	{
		printf("%d\n",(int)i);
		if(dht11_read_data() == TRUE)
		{
			printf("湿度为%d.%d ％RH ，温度为 %d.%d℃ \n", (int)dht11_humi_int(), (int)dht11_humi_deci(), (int)dht11_temp_int(), (int)dht11_temp_deci());
		}
		else
		{
			printf("read error\n");
		}
		delay_ms(5000);
		i++;
	}
}