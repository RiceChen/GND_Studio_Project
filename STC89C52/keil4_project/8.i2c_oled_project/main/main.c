#include <reg52.h>
#include "sys.h"
#include "delay.h"
#include "iic.h"
#include "oled.h"

int main(void)
{	
	IIC_Enable(TRUE);
	oled_enable(TRUE);
	for(;;)
	{
		oled_fill(0x00);
		oled_show_string(24,3,"GND Studio",OLED_TEXT_SIZE_8X16);
		while(1);
	}
}
