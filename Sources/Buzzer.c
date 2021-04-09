/*
 * Buzzer.c
 *
 *  Created on: Mar 4, 2021
 *      Author: 黄又又
 */
#include "derivative.h"
#include "Types.h"
#include "Buzzer.h"


void Buzzer_init()
{
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
	SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;	
	//PORT Init
	PORTC_PCR8 = 0x0300;  //复用选项3，设置为TPM0_CH4
	//PWM Init
	TPM0_SC = (0x0008|0x0007);   //设置PWM时钟     40M/128
	TPM0_C4SC = (0x0020|0x0008); //设置PEM模式	
	TPM0_CNT = 0;
	TPM0_MOD = 0x00;
	TPM0_C4V = 0x00;
	
}

void Buzzer_set(uint32 frequency, uint16 volume)
{
	if(frequency == 0|| volume == 0)
	{
		TPM0_C4V = 0x00;
		return;
	}
	//TPM2_CNT = 0;
	

	TPM0_MOD = (unsigned short)(163828 / frequency);
	unsigned short tmp2=(unsigned short)(16);
	TPM0_C4V = (unsigned short)(163828 / 2 / frequency);
	unsigned short tmp3=(unsigned short)(16);
}
