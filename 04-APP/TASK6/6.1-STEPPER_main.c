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
#include "2-HAL/KEYPAD/KEYPAD_Interface.h"
#include "2-HAL/Stepper/Stepper_Interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>



void main()
{

	Stepper_info st1 = {DIO_GroupA , DIO_GroupA, DIO_GroupA, DIO_GroupA , Pin0 ,Pin1 , Pin2 , Pin3
			            , FullStep , CW , Stepper_VCC };

	Stepper_StErrStateInit(&st1);
	Stepper_StErrStateControlMotorRotate(&st1, 360 );


	while(1)
	{



	}

}




