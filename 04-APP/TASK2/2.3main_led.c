/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "2-HAL/Led/Led_Interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>


Led_info L1 = {DIO_GroupA ,Pin0 , Source_Connection };
Led_info L2 = {DIO_GroupA ,Pin1 , Source_Connection };
Led_info L3 = {DIO_GroupA ,Pin2 , Sink_Connection };

int main()
{

	while(1)
	{
		Led_LedErrStateTurnOn(&L1);
		_delay_ms(100);
		Led_LedErrStateTurnOff(&L1);
		_delay_ms(100);
		Led_LedErrStateTurnOn(&L2);
		_delay_ms(100);
		Led_LedErrStateTurnOff(&L2);
		_delay_ms(100);


	}

	return 0;
}


