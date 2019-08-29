#include "delay.h"
#include "adc.h"
#include "usart.h"

int main(void)
{	
	float adc_value;
	delay_enable(TRUE);
	uart1_enable(115200, TRUE);
	adc_enable(TRUE);
	
	for(;;)
	{
		adc_value = adc_get(ADC_Channel_1)*(3.3/4096);
		printf("adc value: %f\r\n", adc_value);
		delay_ms(1000);
	}
}
