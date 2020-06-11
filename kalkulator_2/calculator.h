/*
 * calculator.h
 *
 *  Created on: 10 cze 2020
 *      Author: konrad
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <stdlib.h>
#include "klawiatura.h"
#include "LCD_HD44780.h"
#include "math.h"

#define MAX_INPUT 16
#define MAX_NUMBER_OF_OPERATORS 12	//including =
#define MAX_NUMBER_OF_OPERATIONS MAX_NUMBER_OF_OPERATORS-1 //excluding =

void getData();
void analise();
void calculate();
void display();
void reset();

#endif /* CALCULATOR_H_ */
