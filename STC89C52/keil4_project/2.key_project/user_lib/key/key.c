#include "key.h"
#include "sys.h"

void key_init()
{
	GPIO_ResetBits(P33);					 		
}

void key_enable(char enable)
{
	if(enable == TRUE)
	{
		key_init();
	}
}