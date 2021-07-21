/*
 * Main.c
 *
 *  Created on: Nov 6, 2020
 *      Author: MRM
 */

#include "LCD_4bitMode.h"
#include "ADC_interrupt.h"
#include "Button_Timer.h"


int main(void)
{

	char flag=0;

	LCD_Init();
	ADC_interrup_init();
	button_Init();
	LCD_displayString("ADC Value: ");


	while(1)
	{
		ADC_interrup_readChannel(0);
		LCD_goToRowColumn(1, 12);
		LCD_displayString("    ");
		LCD_goToRowColumn(1, 12);
		LCD_integerToString(g_ADC_result);


		timet0_inti(g_ADC_result/4);

		if(bit_is_clear(PIND,PD3) && flag == 0)
		{
			_delay_ms(30);
			if(bit_is_clear(PIND,PD3) && flag == 0)
			{
				PORTB |= (1<<PB0);
				PORTB &= (~(1<<PB1));
			}


		}

		else if(bit_is_set(PIND,PD3))
		{
			_delay_ms(30);

			if(bit_is_set(PIND,PD3))
			{
				if(flag == 0 )
				{
					PORTB |= (1<<PB1);
					PORTB &= (~(1<<PB0));
					flag = 1;
				}
				else
				{
					flag=0;
				}
			}
		}



	}
}
