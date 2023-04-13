/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "2-HAL/Led/Led_Interface.h"
#include "2-HAL/SevSeg/SevSeg_Interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>


 SevSeg_info L1 = {SSD_COMMON_CATHODE , DIO_GroupC  };
Led_info L2 = {DIO_GroupA ,Pin1 , Source_Connection };
Led_info L3 = {DIO_GroupA ,Pin0 , Source_Connection };

int main()
{

	while(1)
	{

		SevSeg_SevErrStateSetNumber(7 ,&L1 ) ;
		_delay_ms(1000);

		SevSeg_SevErrStateDisplayRange(&L1 , 3 , 8 );
		_delay_ms(1000);

		SevSeg_SevErrStateDisplayMax(&L1);
		_delay_ms(1000);


	Led_LedErrStateTurnOn(&L3);
		_delay_ms(100);
		Led_LedErrStateTurnOff(&L3);
		_delay_ms(100);
		Led_LedErrStateTurnOn(&L2);
		_delay_ms(100);
		Led_LedErrStateTurnOff(&L2);
		_delay_ms(100);


	}

	return 0;
}


