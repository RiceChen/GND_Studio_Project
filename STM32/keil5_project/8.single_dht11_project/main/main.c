#include "delay.h"
#include "usart.h"
#include "dht11.h"

int main(void)
{	
	delay_enable(TRUE);
	uart1_enable(115200, TRUE);
	dht11_enable(TRUE);
	for(;;)
	{
		if(dht11_read_data() == TRUE)
		{
			printf("湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",dht11_humi_int(),dht11_humi_deci(),dht11_temp_int(),dht11_temp_deci());
		}
		else
		{
			printf("read error\r\n");
		}
		delay_ms(1000);
	}
}
