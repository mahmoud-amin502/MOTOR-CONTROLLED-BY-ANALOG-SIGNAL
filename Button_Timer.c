 /******************************************************************************
 *
 * Module: button and timer
 *
 * File Name: Button_timer.c
 *
 * Description: source file for the button and timer0
 *
 * Author: Mahmoud Amin
 *
 *******************************************************************************/


#include "Button_Timer.h"


void timet0_inti(uint16 comp_data)
{

	TCCR0 = (1<<CS01) | (1<<WGM00) | (1<<WGM01) | (1<<COM01);
	TCNT0 = 0;
	OCR0 = comp_data;
	SET_BIT(DDRB,PB3);
}



void button_Init()
{
	SET_BIT(DDRB,PB0);
	SET_BIT(DDRB,PB1);
	CLEAR_BIT(DDRD,PD3);   // setting the PD3 bin an input pin
}

