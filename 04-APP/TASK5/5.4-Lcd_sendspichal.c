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
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>



void main()
{

	u8 customChar[] = {
			0x00,
			0x1B,
			0x15,
			0x11,
			0x0E,
			0x04,
			0x04,
			0x11
	};


	Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
	Lcd_VoidInit(&lcd1);

	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin0,DIO_Output);

	Lcd_VoidSendSpecialChar(customChar,&lcd1 , 0 , 6);


	while(1)
	{



	}

}




