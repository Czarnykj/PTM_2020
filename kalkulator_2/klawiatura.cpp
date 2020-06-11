/*
 * klawiatura.cpp
 *
 *  Created on: 9 cze 2020
 *      Author: konrad
 */
#include "klawiatura.h"

namespace Klawiatura{

	void Init()
	{
		DDRC = 0xF0; //ustawia PC7-PC4 jako wyjscia PC3-PC0 jako wejscia
		PORTC = 0xFF; //ustawia PC7-PC4 jako 1, PC3-PC0 jako pull-up

	}

	char Scan()
	{
		unsigned char key;
		unsigned char keypad[4][4] = {	{'7','8','9','/'},
										{'4','5','6','*'},
										{'1','2','3','-'},
										{'C','0','=','+'}};

		for(int row = 4,key = 1; row < 8; row++)
		{
			cbi(PORTC,row);

			for(int col = 0; col < 4; col++,key++)
			{
				if(bit_is_clear(PINC,col))
				{
					sbi(PORTC,row);
					return keypad[row-4][col];
				}
			}

			sbi(PORTC,row);
		}
		return 0;
	}
}


