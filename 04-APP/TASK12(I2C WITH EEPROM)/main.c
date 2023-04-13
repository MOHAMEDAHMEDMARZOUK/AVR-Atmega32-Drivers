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
#include"1-MCAL/TWI/TWI_interface.h"
#include "2-HAL/EEPROM/EEPROM_interface.h"
#include "1-MCAL/UART/UART_interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>


void main(void)
{


	TWI_voidInitMaster(0);
	EEPROM_voidSendDataByte(0,0XFF);
	DIO_ErrStateSetGroupDirection(DIO_GroupB,0XFF);
	u8 res = 0 ;
	_delay_ms(10);



		res = EEPROM_u8ReadDataByte( 0 );

		DIO_ErrStateSetGroupValue(DIO_GroupB,res);

			_delay_ms(1000);

	while(1)
	{

	}



}
