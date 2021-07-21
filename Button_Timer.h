 /******************************************************************************
 *
 * Module: button and timer
 *
 * File Name: Button_timer.h
 *
 * Description: Header file for the button and timer0
 *
 * Author: Mahmoud Amin
 *
 *******************************************************************************/


#ifndef BUTTON_TIMER_H_
#define BUTTON_TIMER_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

void timet0_inti(uint16 comp_data);
void button_Init();

#endif /* BUTTON_TIMER_H_ */
