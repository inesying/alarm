/*
 * Timer.h
 *
 *  Created on: Mar 5, 2021
 *      Author: ª∆”÷”÷
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Types.h"

void Timer_init(uint16 duration);
int8 Timer_set(uint16 frequency,void(*handler)());
void Timer_unset(int8 timerId);
void Timer_disable();
uint32 Timer_getSystemTime();
void SysTick_Handler(void);

#endif /* TIMER_H_ */
