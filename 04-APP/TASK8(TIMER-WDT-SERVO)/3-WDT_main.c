/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
//#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
#include "1-MCAL/4-TIMER0/TIMER0_Interface.h"
#include "1-MCAL/6-TIMER1/TIMER1_interface.h"
#include "1-MCAL/WDT/WDT_Interface.h"

#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>

#define PORTD_ITI    (*(volatile u8*)0x32)

void main(void)
{
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin0,DIO_Output);
	DIO_ErrStateSetPinValue(DIO_GroupD,Pin0,1);
	_delay_ms(1000);

	WDT_voidWDTEnable(WDT_1000_3MS);
	TOG_BIT(PORTD_ITI , Pin0);

	//WDT_voidWDTDisable();

	while(1)
	{
		//WDT_voidRefresh();
	}



}
