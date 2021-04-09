/*
 * Led.c
 *
 *  Created on: Mar 7, 2021
 *      Author: ������
 */
#include "Led.h"
#include "derivative.h"

static void timerHandler();

void Led_init(){
	SIM_SCGC5=SIM_SCGC5|((1<<10)+(1<<11)); //ͨ���߼�������1������ʹ��PORTCʱ�� 
	PORTB_PCR16=0x0100;
	PORTB_PCR17=0x0100;
	PORTB_PCR18=0x0100;
	PORTB_PCR19=0x0100;
	PORTC_PCR0=0x0100;
	PORTC_PCR2=0x0100;//����PTC0ΪGPIO 
	PORTC_PCR3=0x0100;
	PORTC_PCR4=0x0100;
	PORTC_PCR5=0x0100;//����PTC4ΪGPIO 
	GPIOB_PDDR|=0x0f0000;
	GPIOC_PDDR =0x003d;//����PTC0��PTC4Ϊ��� 
}

void delay(){
	unsigned int i,j; 
	for(i=0;i<5000;i++){
		for(j=0;j<100;j++)
			asm("nop"); 
	   } 
}

void Led_play(){
	unsigned int i;
	for(i=0;i<3;++i) 
	  { 
		  GPIOB_PDOR=0x090000;
		  GPIOC_PDOR=0x0008; //���PTC0��PTC4Ϊ1��С�Ƶ���   
		  delay(); 
		  GPIOB_PDOR=0x020000;
		  GPIOC_PDOR=0x0011; //���PTC0��PTC4Ϊ1��С�Ƶ���  
		  delay(); 
		  GPIOB_PDOR=0x040000;
		  GPIOC_PDOR=0x0024; //���PTC0��PTC4Ϊ1��С�Ƶ���
		  delay(); 	  	    
		  //GPIOC_PDOR = ~ GPIOC_PDOR; 
	         //GPIOB_PDOR = ~ GPIOB_PDOR; 
	         // ~Ϊ�߼�ȡ����Ҳ����GPIOC_PTOR�Ĵ�����ת�˿� 
	  }
	Led_stop();
	
}

void Led_stop(){
	GPIOC_PDOR &= ~ GPIOC_PDOR; 
    GPIOB_PDOR &= ~ GPIOB_PDOR; 
    OLED_Init();
    OLEDFB_init();
   
}



