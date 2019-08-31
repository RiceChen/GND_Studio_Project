#include <reg52.h>
#include "sys.h"
#include "delay.h"
#include "spi.h"
#include "w25qxx.h"
#include "usart.h"

const unsigned char write_buffer[]={"GND studio"};
#define BUFFER_SIZE	sizeof(write_buffer)

int main(void)
{
	unsigned char read_buffer[BUFFER_SIZE];
	Usart_Enable(TRUE);
	spi_enable(TRUE);
	if(w25qxx_read_id() != W25Q16)
	{
		printf("error: no check w25q16\r\n");
	}
	w25qxx_write((unsigned char *)write_buffer, 1024, BUFFER_SIZE);
	delay_ms(100);
	w25qxx_read(read_buffer, 1024, BUFFER_SIZE);
	printf("read buffer: %s\r\n", read_buffer);
	while(1);
}
