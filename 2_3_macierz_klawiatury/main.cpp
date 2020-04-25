#include "GLOBAL.h"

unsigned char getKey()
{
	unsigned char key;

	for(int row = 4,key = 1; row < 8; row++)
	{
		cbi(PORTC,row);

		for(int col = 0; col < 4; col++,key++)
		{
			if(bit_is_clear(PINC,col))
			{
				sbi(PORTC,row);
				return key;
			}
		}

		sbi(PORTC,row);
	}
	return 0;
}

int main()
{
	cbi(DDRC,PC0); //ustawia port PC0 jako wejscie
	cbi(DDRC,PC1); //ustawia port PC1 jako wejscie
	cbi(DDRC,PC2); //ustawia port PC2 jako wejscie
	cbi(DDRC,PC3); //ustawia port PC3 jako wejscie

	sbi(PORTC,PC0); //ustawia port PC0 jako wejscie +5V pull-up
	sbi(PORTC,PC1); //ustawia port PC1 jako wejscie +5V pull-up
	sbi(PORTC,PC2); //ustawia port PC2 jako wejscie +5V pull-up
	sbi(PORTC,PC3); //ustawia port PC3 jako wejscie +5V pull-up

	sbi(DDRC,PC4); //ustawia port PC4 jako wyjscie
	sbi(DDRC,PC5); //ustawia port PC5 jako wyjscie
	sbi(DDRC,PC6); //ustawia port PC6 jako wyjscie
	sbi(DDRC,PC7); //ustawia port PC7 jako wyjscie

	sbi(PORTC,PC4); //ustawia wysokie napiecie na porcie PC4 na stale
	sbi(PORTC,PC5); //ustawia wysokie napiecie na porcie PC5 na stale
	sbi(PORTC,PC6); //ustawia wysokie napiecie na porcie PC6 na stale
	sbi(PORTC,PC7); //ustawia wysokie napiecie na porcie PC7 na stale

	DDRD = 0xff;   //ustawia wszystkie porty B do pracy jako wyjscie



	while(1)
	{
		unsigned char key;
		if(key = getKey())
			PORTD = key;
		else
			PORTD = 0;
//		getKey();
	}
}
