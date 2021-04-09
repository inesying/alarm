/*
 * Led.c
 *
 *  Created on: Mar 7, 2021
 *      Author: 黄又又
 */
#include "Led.h"
#include "derivative.h"

static void timerHandler();

void Led_init(){
	SIM_SCGC5=SIM_SCGC5|((1<<10)+(1<<11)); //通过逻辑”或”置1，单独使能PORTC时钟 
	PORTB_PCR16=0x0100;
	PORTB_PCR17=0x0100;
	PORTB_PCR18=0x0100;
	PORTB_PCR19=0x0100;
	PORTC_PCR0=0x0100;
	PORTC_PCR2=0x0100;//设置PTC0为GPIO 
	PORTC_PCR3=0x0100;
	PORTC_PCR4=0x0100;
	PORTC_PCR5=0x0100;//设置PTC4为GPIO 
	GPIOB_PDDR|=0x0f0000;
	GPIOC_PDDR =0x003d;//配置PTC0、PTC4为输出 
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
		  GPIOC_PDOR=0x0008; //输出PTC0、PTC4为1，小灯点亮   
		  delay(); 
		  GPIOB_PDOR=0x020000;
		  GPIOC_PDOR=0x0011; //输出PTC0、PTC4为1，小灯点亮  
		  delay(); 
		  GPIOB_PDOR=0x040000;
		  GPIOC_PDOR=0x0024; //输出PTC0、PTC4为1，小灯点亮
		  delay(); 	  	    
		  //GPIOC_PDOR = ~ GPIOC_PDOR; 
	         //GPIOB_PDOR = ~ GPIOB_PDOR; 
	         // ~为逻辑取反，也可用GPIOC_PTOR寄存器反转端口 
	  }
	Led_stop();
	
}

void Led_stop(){
	GPIOC_PDOR &= ~ GPIOC_PDOR; 
    GPIOB_PDOR &= ~ GPIOB_PDOR; 
    OLED_Init();
    OLEDFB_init();
   
}



