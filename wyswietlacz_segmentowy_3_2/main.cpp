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

void WyswietlLiczbe(uint16_t liczba);
void WyswietlLiczbeJednosci(uint16_t liczba);
void WyswietlLiczbeDziesiatek(uint16_t liczba);
void WyswietlLiczbeSetek(uint16_t liczba);
void WyswietlLiczbeTysiecy(uint16_t liczba);

char liczby[] = {0xff-(G+DP),B+C,A+B+G+D+E,A+B+G+C+D,F+G+B+C,A+F+G+C+D,0xff-(B+DP),A+B+C,0xff-DP,0xff-(E+D+DP)};
char wyswietlacze[] = {128,64,32,16};
uint16_t licznik = 0;

void timerInit()
{
	TCCR1A = (0<<WGM13) | (1 << WGM12) | (0 << WGM11) | (0 << WGM10); //ustawienie CTC na top OCR1A
	TCCR1B = (1 << CS12); //preskaler 1024
	OCR1A = 62500; //zapisanie wartosci odpowiadajacej 0,5sek
	TIMSK = (1 << OCIE1A); //uruchomienie przerwania OCIE1A
}

int main()
{
	DDRD = 0xff;   //ustawia wszystkie porty D do pracy jako wyjscie
	DDRA = 0xff;   //ustawia wszystkie porty A do pracy jako wyjscie
	PORTD = ~0;

	sei();


	while(1)
	{
		WyswietlLiczbe(licznik);
	}
}

ISR(TIMER1_COMPA_vect)
{
	licznik++;
	if(licznik == 10000)
		licznik = 0;
}

void WyswietlLiczbe(uint16_t liczba)
{
	WyswietlLiczbeJednosci(liczba);
	_delay_ms(DELAY_EKRAN);

	if(!(liczba/1000)%10 && !(liczba/100)%10 && !(liczba/10)%10)
	{
		_delay_ms(DELAY_EKRAN*3);
		return;
	}

	WyswietlLiczbeDziesiatek(liczba);
	_delay_ms(DELAY_EKRAN);


	if(!(liczba/1000)%10 && !(liczba/100)%10)
	{
		WyswietlLiczbeJednosci(liczba);
		_delay_ms(DELAY_EKRAN);
		WyswietlLiczbeDziesiatek(liczba);
		_delay_ms(DELAY_EKRAN);
		return;
	}

	WyswietlLiczbeSetek(liczba);
	_delay_ms(DELAY_EKRAN);

	if(!(liczba/1000)%10)
	{
		WyswietlLiczbeJednosci(liczba);
		_delay_ms(DELAY_EKRAN/3);
		WyswietlLiczbeDziesiatek(liczba);
		_delay_ms(DELAY_EKRAN/3);
		WyswietlLiczbeSetek(liczba);
		_delay_ms(DELAY_EKRAN/3);
		return;
	}

	WyswietlLiczbeTysiecy(liczba);
	_delay_ms(DELAY_EKRAN);
}

void WyswietlLiczbeJednosci(uint16_t liczba)
{
	liczba = (liczba)%10;
	PORTD = ~wyswietlacze[0];
	PORTA = liczby[liczba];
}

void WyswietlLiczbeDziesiatek(uint16_t liczba)
{
	liczba = (liczba/10)%10;
	PORTD = ~wyswietlacze[1];
	PORTA = liczby[liczba];
}

void WyswietlLiczbeSetek(uint16_t liczba)
{
	liczba = (liczba/100)%10;
	PORTD = ~wyswietlacze[2];
	PORTA = liczby[liczba];
}

void WyswietlLiczbeTysiecy(uint16_t liczba)
{
	liczba = (liczba/1000)%10;
	PORTD = ~wyswietlacze[3];
	PORTA = liczby[liczba];
}
