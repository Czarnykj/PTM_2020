#include "GLOBAL.h"

void wezyk();
void wezyk_od_scianek();

void przycisnieciePrzycisku()
{
	while(bit_is_set(PINC,0))
	{
		wezyk();
	}
	while(bit_is_clear(PINC,0))
	{
		wezyk_od_scianek();
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

void wezyk()
{
	for(int i = 0; i <8;i++)
	{
		PORTD = 1 << i;
		_delay_ms(200);
		if(bit_is_clear(PINC,0))
			break;
	}
}

void wezyk_od_scianek()
{
	for(int i = 0; i < 8;i++){
		PORTD = 1 << i;
		_delay_ms(250);
		if(bit_is_set(PINC,0))
			break;
	}

	for(int i = 7; i >= 0;i--){
		PORTD = 1 << i;
		_delay_ms(250);
		if(bit_is_set(PINC,0))
					break;
	}
}
