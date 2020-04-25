#include "GLOBAL.h"


int main()
{
	DDRD=0xFF;

	while(1)
	{
		PORTD = 64; //port B6
		_delay_ms(5);
		PORTD = 0; //wylaczenie wszystkich portow
		_delay_ms(5);
	}
}
