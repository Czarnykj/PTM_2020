#include "GLOBAL.h"

void przycisnieciePrzycisku()
{
	if(bit_is_set(PINC,PC0))
	{
		PORTD = 255;
	}
	if(bit_is_clear(PINC,PC0))
	{
		PORTD = 0;
	}
}

int main()
{
	cbi(DDRC,PC0); //ustawia port PC0 jako wejscie
	sbi(DDRC,PC4); //ustawia port PC4 jako wyjscie
	cbi(PORTC,PC0); //ustawia port PC0 jako wejscie wysokiej impedancji
	sbi(PORTC,PC4); //ustawia wysokie napiecie na porcie PC4 na stale
	DDRD = 0xff;   //ustawia wszystkie porty B do pracy jako wyjscie



	while(1)
	{
		przycisnieciePrzycisku();
	}
}
