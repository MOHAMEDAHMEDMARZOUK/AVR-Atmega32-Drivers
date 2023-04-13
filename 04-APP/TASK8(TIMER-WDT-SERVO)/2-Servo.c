/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
#include "2-HAL/Switch/Switch_Interface.h"
#include "1-MCAL/4-TIMER0/TIMER0_Interface.h"
#include "1-MCAL/6-TIMER1/TIMER1_interface.h"
#include "2-HAL/LCD/Lcd_Interface.h"
//#include "2-HAL/Led/Led_Interface.h"

#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>


void main(void)
{
	TIMER1_voidTIMER1Init();
	TIMER1_voidTIMER1Set_ICR1(20000);
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin5,DIO_Output);
	while(1)
	{
		/*5% duty cycle*/
		//TIMER1_voidTIMER1COMPA_OCR1A(1000);
		//_delay_ms(1000);

		/*7.5% duty cycle*/
		//TIMER1_voidTIMER1COMPA_OCR1A(1500);
		//_delay_ms(1000);

		/*10% duty cycle*/
		TIMER1_voidTIMER1COMPA_OCR1A(2000);
		//_delay_ms(1000);
		//for(u32 i=0 ;i<65000;i++)
		//{
		//	TIMER1_voidTIMER1COMPA_OCR1A(i);
		//	_delay_ms(100);
		//}
	}

}
for(u32 i=750;i<250;i++)
		{
		TIMER1_voidTIMER1COMPA_OCR1A(i);
		_delay_ms(100);
	}