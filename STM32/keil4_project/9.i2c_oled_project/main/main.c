#include "delay.h"
#include "iic.h"
#include "oled.h"

int main(void)
{	
	delay_enable(TRUE);
	iic_enable(400000, TRUE);
	oled_enable(TRUE);
	for(;;)
	{
		oled_fill(OLED_FILL_WHITE_DATA);
		oled_show_string(24,3,"GNG studio",OLED_TEXT_SIZE_8X16);
		while(1);
	}
}
