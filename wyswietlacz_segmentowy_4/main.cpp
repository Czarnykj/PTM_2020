#include "GLOBAL.h"

#define A 1
#define B 2
#define C 4
#define D 8
#define E 16
#define F 32
#define G 64
#define DP 128
#define DELAY_EKRAN 20

void WyswietlCzas(uint16_t,uint16_t);
void WyswietlLiczbe(uint16_t liczba);
void WyswietlLiczbeJednosci(uint16_t liczba);
void WyswietlLiczbeDziesiatek(uint16_t liczba);
void WyswietlLiczbeSetek(uint16_t liczba);
void WyswietlLiczbeTysiecy(uint16_t liczba);

char liczby[] = {0xff-(G+DP),B+C,A+B+G+D+E,A+B+G+C+D,F+G+B+C,A+F+G+C+D,0xff-(B+DP),A+B+C,0xff-DP,0xff-(E+D+DP)};
char wyswietlacze[] = {128,64,32,16};
uint16_t sekundy = 0, minuty = 0;

int main()
{
	DDRD = 0xff;   //ustawia wszystkie porty D do pracy jako wyjscie
	DDRA = 0xff;   //ustawia wszystkie porty A do pracy jako wyjscie
	PORTD = ~0;

	while(1)
	{
		for(int i = 0;i < 60; i++)
		{
				sekundy = i;
					for(int j = 0; j < 12; j++) //petla, ktora trwa 12*80ms = 960 ms
						WyswietlCzas(minuty,sekundy);
				_delay_ms(40); //dopelnienie do 1sek.
		}
		minuty++;

	}
}

void WyswietlCzas(uint16_t tmp_minuty, uint16_t tmp_sekundy)
{
	PORTD = ~wyswietlacze[0];
	PORTA = liczby[(sekundy)%10];
	_delay_ms(DELAY_EKRAN);
	PORTD = ~wyswietlacze[1];
	PORTA = liczby[(sekundy/10)%10];
	_delay_ms(DELAY_EKRAN);
	PORTD = ~wyswietlacze[2];
	PORTA = liczby[(minuty)%10];
	_delay_ms(DELAY_EKRAN);
	PORTD = ~wyswietlacze[3];
	PORTA = liczby[(minuty/10)%10];
	_delay_ms(DELAY_EKRAN);
}
