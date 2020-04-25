#include "GLOBAL.h"


int main()
{
	DDRD=0xFF;

	while(1)
	{
		PORTD = 0;

		for(int i = 0; i < 256; i++)
		{
			PORTD = i;
			_delay_ms(1);
		}
	}
}
