#include "GLOBAL.h"
#include "LCD_HD44780.h"


void ADC_init()
{
	ADMUX = (0 << REFS1) | (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (0 << MUX0); //AVCC ORAZ USTAWIENIE ADC0
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); //ustawienie preskalera na 128
}

uint16_t ADC_10bit()
{
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));

	return ADC;
}
int main()
{
	DDRB = 0xff; //ustawienie wszystkich bitow portu B jako wyjcie

	ADC_init();
	LCD_HD44780::init();

	while(1)
	{
		LCD_HD44780::showNumber(ADC_10bit());
		_delay_ms(200);
	}
}
