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

void WyswietlCzas();

char liczby[] = {0xff-(G+DP),B+C,A+B+G+D+E,A+B+G+C+D,F+G+B+C,A+F+G+C+D,0xff-(B+DP),A+B+C,0xff-DP,0xff-(E+D+DP)};
char wyswietlacze[] = {128,64,32,16};
uint16_t sekundy = 0, minuty = 0;

void timerInit()
{
	TCCR1A = (0<<WGM13) | (1 << WGM12) | (0 << WGM11) | (0 << WGM10);
	TCCR1B = (1 << CS12); //preskaler 256
	OCR1A = 31250; //zapisanie wartosci odpowiadajacej 1sek
	TIMSK = (1 << OCIE1A); //uruchomienie przerwania OCIE1A
}

int main()
{
	DDRD = 0xff;   //ustawia wszystkie porty D do pracy jako wyjscie
	DDRA = 0xff;   //ustawia wszystkie porty A do pracy jako wyjscie
	PORTD = ~0;

	timerInit();
	sei();

	while(1)
	{
		WyswietlCzas();
	}
}

ISR(TIMER1_COMPA_vect)
{
	sekundy++;
	if(sekundy == 60)
	{
		sekundy = 0;
		minuty ++;
	}
}

void WyswietlCzas()
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
