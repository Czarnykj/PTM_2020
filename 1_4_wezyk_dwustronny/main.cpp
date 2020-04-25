#include "GLOBAL.h"


int main()
{
	DDRD=0xFF;

	while(1)
	{
		PORTD = 0;

		for(int i = 0; i < 8; i++)
		{
			PORTD = 1 << i;
			_delay_ms(250);
		}
		for(int i = 7; i >= 0; i--)
		{
			PORTD = 1 << i;
			_delay_ms(250);
		}
	}
}
