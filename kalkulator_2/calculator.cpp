/*
 * calculator.cpp
 *
 *  Created on: 10 cze 2020
 *      Author: konrad
 */

#include "calculator.h"

uint8_t result = 0;
char input[MAX_INPUT]; 						  	//array stores input 		   | tablica przechowujaca wprowadzenie
char operators[MAX_NUMBER_OF_OPERATORS]; 	  	//array stores operators	   | tablica przechowujaca operatory arytmetyczne
uint8_t operations[MAX_NUMBER_OF_OPERATIONS]; 	//array stores done operations | tablica przechowujaca przeprowadzone operacje

uint8_t operatorsCounter = 0;					//how many operators 		   | licznik operatorow arytmetycznych
uint8_t operationsCounter = 0;					//how many operations		   | licnik operacji arytmetycznych
uint8_t inputCounter = 0;						//how many input			   | licznik wprowadzonych znakow

bool isOperator(char tmp)
{
	if(tmp == '=' || tmp == '-' || tmp == 'C' || tmp == '+' || tmp == '/' || tmp == '*')
		return true;
	else
		return false;
}

void getData()
{
	char tmpKey = 0;

	tmpKey = Klawiatura::Scan();

	while(tmpKey != '=')
	{
		if(tmpKey == 'C')
			{
				reset();
				tmpKey = 0;
				continue;
			}
		if(tmpKey != 0)
		{
			input[inputCounter] = tmpKey;
			LCD_HD44780::writeData(input[inputCounter]);
			inputCounter++;
			_delay_ms(300); //delay to delete micro switch debounce | delay do opoznienia drgania stykow
		}
		tmpKey = Klawiatura::Scan();
	}
	input[inputCounter] = '=';
	LCD_HD44780::writeData(input[inputCounter]);
	inputCounter++;
}

void analise()
{
	char tmpTab[MAX_INPUT] = {0};
	uint8_t tmpIndex = 0;

	for(int i = 0; i < inputCounter;i++)
	{
		if(!isOperator(input[i]))
		{
			tmpTab[tmpIndex] = input[i];
			tmpIndex++;
		}
		else
		{
			operators[operatorsCounter] = input[i];
			operatorsCounter++;
			operations[operationsCounter] = atoi(tmpTab);
			for(int j = 0; j <= tmpIndex; j++)	//clear tmpTab | wyczyszcza tymczasowa tablice
				tmpTab[j] = 0;
			operationsCounter++;
			tmpIndex = 0;
		}
	}
}

void calculate()
{
	char arithmeticOperator = operators[0];
	switch(arithmeticOperator)
	{
	case '+':
		result = operations[0];
		result += operations[1];
		break;
	case '-':
		result = operations[0];
		result -= operations[1];
		break;
	case '*':
		result = operations[0];
		result *= operations[1];
		break;
	case '/':
		result = operations[0];
		result /= operations[1];
		break;
	default:
		break;
	}
}

void display()
{
	LCD_HD44780::showNumber(result);
}

void reset()
{
	_delay_ms(1000);
	LCD_HD44780::clear();
	LCD_HD44780::writeText("czyszczenie...");
	_delay_ms(500);


	for(int i = 0; i < MAX_INPUT;i++)
		input[i] = 0;
	for(int i = 0; i < MAX_NUMBER_OF_OPERATORS;i++)
		operators[i] = 0;
	for(int i = 0; i < MAX_NUMBER_OF_OPERATIONS;i++)
		operations[i] = 0;

	inputCounter = 0;
	operatorsCounter = 0;
	operationsCounter = 0;
	result = 0;
	LCD_HD44780::clear();
}

