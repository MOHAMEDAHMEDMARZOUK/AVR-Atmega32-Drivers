/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
//#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
//#include "1-MCAL/4-TIMER0/TIMER0_Interface.h"
//#include "1-MCAL/6-TIMER1/TIMER1_interface.h"
//#include "1-MCAL/WDT/WDT_Interface.h"
#include "1-MCAL/UART/UART_interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>

#define PORTD_ITI    (*(volatile u8*)0x32)

void main(void)
{

    UART_voidInit();
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin2,DIO_Output);
	u8 res = 0 ;


	while(1)
	{
		UART_voidRead(&res) ;

		if(res == 'o')
		{
			DIO_ErrStateSetPinValue(DIO_GroupD,Pin2,1);
			UART_voidWrite(' ');
			UART_voidWrite('m');
			UART_voidWrite('o');
			UART_voidWrite('h');
			UART_voidWrite('a');
			UART_voidWrite('m');
			UART_voidWrite('e');
			UART_voidWrite('d');
			UART_voidWrite(' ');

		}

		if(res == 'f')
		{
			DIO_ErrStateSetPinValue(DIO_GroupD,Pin2,0);
			UART_voidWrite(' ');
			UART_voidWrite('z');
			UART_voidWrite('o');
			UART_voidWrite('k');
			UART_voidWrite('a');
			UART_voidWrite('a');
			UART_voidWrite('a');
			UART_voidWrite(' ');

		}



	}



}
