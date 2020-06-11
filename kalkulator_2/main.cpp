#include "GLOBAL.h"
#include "LCD_HD44780.h"
#include "klawiatura.h"
#include "calculator.h"

int main(void)
{
	LCD_HD44780::init();
	Klawiatura::Init();

	LCD_HD44780::writeText("hello");
	_delay_ms(1000);
	LCD_HD44780::clear();

	while(1)
	{
		getData();
		analise();
		calculate();
		display();
	}
}
