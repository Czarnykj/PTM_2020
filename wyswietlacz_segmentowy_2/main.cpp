#include "GLOBAL.h"

#define A 1
#define B 2
#define C 4
#define D 8
#define E 16
#define F 32
#define G 64
#define DP 128

int main()
{
	DDRD = 0xff;   //ustawia wszystkie porty D do pracy jako wyjscie
	DDRA = 0xff;   //ustawia wszystkie porty A do pracy jako wyjscie

	char liczby[] = {0xff-(G+DP),B+C,A+B+G+D+E,A+B+G+C+D,F+G+B+C,A+F+G+C+D,0xff-(B+DP),A+B+C,0xff-DP,0xff-(E+D+DP)};
	char wyswietlacze[] = {128,64,32,16};

	while(1)
	{
		for(int wyswietlacz = 0; wyswietlacz < 4; wyswietlacz++)
		{
			PORTD = ~wyswietlacze[wyswietlacz];
			for(int i = 0;i < 10;i++)
			{
				PORTA = liczby[i];
				_delay_ms(250);
			}
		}
	}
}
