/*
 * Button.h
 *
 *  Created on: Mar 5, 2021
 *      Author: ??????
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#define KEY_UP 0
#define KEY_DOWN 1
#define KEY_LEFT 2
#define KEY_RIGHT 3
#define KEY_A 4
#define KEY_B 5
#define KEY_C 6
#define KEY_D 7

#define EVENT_KEY_UP 100
#define EVENT_KEY_DOWN 101

void Button_init();
void Button_onTimer();


#endif /* BUTTON_H_ */
