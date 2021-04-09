/*
 * Button.c
 *
 *  Created on: Mar 5, 2021
 *      Author: 黄又又
 */

#include "derivative.h"
#include "Button.h"
#include "Timer.h"
#include "Types.h"
#include "AppFramework.h"
#include "BIT.h"



uint8 keyStatus[8];

void Button_init(){
	SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
	SIM_SCGC5|=SIM_SCGC5_PORTA_MASK;
	//设置GPIO，上升沿，no pull enable，passive filter enable
	PORTC_PCR6=PORT_PCR_MUX(0x1)+PORT_PCR_IRQC(0x0A)+PORT_PCR_PE_MASK+PORT_PCR_PE_MASK;
	PORTC_PCR7=PORT_PCR_MUX(0x1)+PORT_PCR_IRQC(0x0A)+PORT_PCR_PE_MASK+PORT_PCR_PE_MASK;
	PORTC_PCR8=PORT_PCR_MUX(0x1)+PORT_PCR_IRQC(0x0A)+PORT_PCR_PE_MASK+PORT_PCR_PE_MASK;
	PORTC_PCR9=PORT_PCR_MUX(0x1)+PORT_PCR_IRQC(0x0A)+PORT_PCR_PE_MASK+PORT_PCR_PE_MASK;
	
	PORTA_PCR5=PORT_PCR_MUX(0x1)+PORT_PCR_IRQC(0x0A)+PORT_PCR_PE_MASK+PORT_PCR_PE_MASK;
	PORTA_PCR12=PORT_PCR_MUX(0x1)+PORT_PCR_IRQC(0x0A)+PORT_PCR_PE_MASK+PORT_PCR_PE_MASK;
	PORTA_PCR13=PORT_PCR_MUX(0x1)+PORT_PCR_IRQC(0x0A)+PORT_PCR_PE_MASK+PORT_PCR_PE_MASK;
	PORTA_PCR19=PORT_PCR_MUX(0x1)+PORT_PCR_IRQC(0x0A)+PORT_PCR_PE_MASK+PORT_PCR_PE_MASK;
	
	Timer_set(5,Button_onTimer);
	unsigned int i;
	for(i=0;i<8;i++){
		keyStatus[i]=0;
	}
}

void Button_onTimer(){
	if((GPIOC_PDIR&BIT9)!=BIT9){
		if(keyStatus[KEY_UP]==0){
			//srand(rand()&(Timer_getSystemTime()+17771));
			App_sendMessage(EVENT_KEY_DOWN,KEY_UP);
		}
		keyStatus[KEY_UP]=1;
	}
	else{
		keyStatus[KEY_UP]=0;
	}
	if((GPIOC_PDIR&BIT8)!=BIT8)
		{
			if(keyStatus[KEY_LEFT] == 0)
			{
				//srand(rand()&(Timer_getSystemTime()+41991));
				App_sendMessage(EVENT_KEY_DOWN, KEY_LEFT);
			}
			keyStatus[KEY_LEFT] = 1;
		}
		else
		{
			keyStatus[KEY_LEFT] = 0;
		}
		
		if((GPIOC_PDIR&BIT7)!=BIT7)
		{
			if(keyStatus[KEY_DOWN] == 0)
			{
				//srand(rand()&(Timer_getSystemTime()+17991));
				App_sendMessage(EVENT_KEY_DOWN, KEY_DOWN);
			}
			keyStatus[KEY_DOWN] = 1;
		}
		else
		{
			keyStatus[KEY_DOWN] = 0;
		}
		
		if((GPIOC_PDIR&BIT6)!=BIT6)
		{
			if(keyStatus[KEY_RIGHT] == 0)
			{
				//srand(rand()&(Timer_getSystemTime()+14891));
				App_sendMessage(EVENT_KEY_DOWN, KEY_RIGHT);
			}
			keyStatus[KEY_RIGHT] = 1;
		}
		else
		{
			keyStatus[KEY_RIGHT] = 0;
		}
		
		if((GPIOA_PDIR&BIT5)!=BIT5)
		{
			if(keyStatus[KEY_A] == 0)
			{
				//srand(rand()&(Timer_getSystemTime()+17291));
				App_sendMessage(EVENT_KEY_DOWN, KEY_A);
			}
			keyStatus[KEY_A] = 1;
		}
		else
		{
			keyStatus[KEY_A] = 0;
		}
		
		if((GPIOA_PDIR&BIT12)!=BIT12)
		{
			if(keyStatus[KEY_B] == 0)
			{
				//srand(rand()&(Timer_getSystemTime()+60991));
				App_sendMessage(EVENT_KEY_DOWN, KEY_B);
			}
			keyStatus[KEY_B] = 1;
		}
		else
		{
			keyStatus[KEY_B] = 0;
		}
		
		if((GPIOA_PDIR&BIT13)!=BIT13)
		{
			if(keyStatus[KEY_C] == 0)
			{
				//srand(rand()&(Timer_getSystemTime()+33413));
				App_sendMessage(EVENT_KEY_DOWN, KEY_C);
			}
			keyStatus[KEY_C] = 1;
		}
		else
		{
			keyStatus[KEY_C] = 0;
		}
		
	    if((GPIOA_PDIR&BIT19)!=BIT19)
		{
			if(keyStatus[KEY_D] == 0)
			{
				//srand(rand()&(Timer_getSystemTime()+17991));
				App_sendMessage(EVENT_KEY_DOWN, KEY_D);
			}
			keyStatus[KEY_D] = 1;
		}
		else
		{
			keyStatus[KEY_D] = 0;
		}
}
