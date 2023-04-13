/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "2-HAL/Led/Led_Interface.h"
#include "2-HAL/Switch/Switch_Interface.h"
#include "2-HAL/SevSeg/SevSeg_Interface.h"
#include "2-HAL/LCD/Lcd_Interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>





int main()
{
	Lcd_Info L1 = { DIO_GroupB , DIO_GroupB , DIO_GroupB , Pin2  , Pin1 ,Pin0 ,DIO_GroupA };
	Lcd_VoidInit(&L1);
	Led_info LED={DIO_GroupA,Pin0,Source_Connection};
	Led_info LED1={DIO_GroupA,Pin1,Source_Connection};
	Switch_Info SW={DIO_GroupB,Pin0,InternalPullUp};
	SwitchState state;

	while(1)
	{

	SW_SwitchErrStateGetState(&SW ,&state);
	if(state==PressedPullUp)
	{Led_LedErrStateTurnOn(&LED)  ;
	_delay_ms(500);
	Led_LedErrStateTurnOff(&LED)  ;
	_delay_ms(500);
	Led_LedErrStateTurnOn(&LED1)  ;
	_delay_ms(500);
	Led_LedErrStateTurnOff(&LED1)  ;
	_delay_ms(500);
	Led_LedErrStateTurnOn(&LED)  ;
	_delay_ms(500);
	Led_LedErrStateTurnOff(&LED)  ;
	_delay_ms(500);
	Led_LedErrStateTurnOn(&LED1)  ;
	_delay_ms(1000);
	Led_LedErrStateTurnOff(&LED1)  ;}
	}

	return 0;
}


