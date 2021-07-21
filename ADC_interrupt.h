 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: ADC_interrupt.h
 *
 * Description: Header file for the ADC driver using the interrupt method
 *
 * Author: Mahmoud Amin
 *
 *******************************************************************************/

#ifndef ADC_INTERRUPT_H_
#define ADC_INTERRUPT_H_

#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"

volatile uint16 g_ADC_result;  // a global value to store the value of the ADC output

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void ADC_interrup_init();

void ADC_interrup_readChannel(uint8 ch_num);





#endif /* ADC_INTERRUPT_H_ */
