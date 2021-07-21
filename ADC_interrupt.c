 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: ADC_interrupt.c
 *
 * Description: Source file for the ADC driver using the interrupt method
 *
 * Author: Mahmoud Amin
 *
 *******************************************************************************/


#include "ADC_interrupt.h"


extern volatile uint16 g_ADC_result;  //using the key word extern to import the global variable we use to store the ADC output value

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/



ISR(ADC_vect)
{
	g_ADC_result = ADC;
}



void ADC_interrup_init()
{
	SET_BIT(SREG,7);        //enabling the global interrupt bit
	ADMUX = 0x00;           // this makes ADMUX register initial value zero and also choose the reference voltage to be AVREF
	SET_BIT(ADCSRA,ADEN);   //enabling the ADC module
	SET_BIT(ADCSRA,ADPS0);  // setting both ADPS0 & ADPS1 bit allows us choose prescaler 8 to achieve the suitable frequency for ADC module
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADIE);   //enabling the ADC module interrupt bit
}


void ADC_interrup_readChannel(uint8 ch_num)
{
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
}
