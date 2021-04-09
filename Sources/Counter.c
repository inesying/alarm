/*
 * Counter.c
 *
 *  Created on: Mar 6, 2021
 *      Author: »ÆÓÖÓÖ
 */

#include "Counter.h"
int counter = 0;
int counter2 = 0;

void updateCounter()
{
	counter++;
	counter %= 60;
}

void updateCounter2()
{
	counter2++;
}
int getcounter2(){
	return counter2;
}
