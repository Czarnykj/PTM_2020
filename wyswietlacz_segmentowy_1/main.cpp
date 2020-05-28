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

	while(1)
	{
		PORTD = ~128;
		for(int i = 0;i < 10;i++)
		{
			PORTA = liczby[i];
			_delay_ms(500);
		}
	}
}
