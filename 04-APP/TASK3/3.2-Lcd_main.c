/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "2-HAL/Led/Led_Interface.h"
#include "2-HAL/SevSeg/SevSeg_Interface.h"
#include "2-HAL/LCD/Lcd_Interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>





int main()
{
	Lcd_Info L1 = { DIO_GroupB , DIO_GroupB , DIO_GroupB , Pin2  , Pin1 ,Pin0 ,DIO_GroupA };
	Lcd_VoidInit(&L1);

	while(1)
	{

		Lcd_VoidSendChar('M',&L1);
		_delay_ms(100);

		Lcd_VoidGoXY(&L1,line0,Coloum1);
		Lcd_VoidSendChar('r' ,&L1);
		_delay_ms(100);

		Lcd_VoidGoXY(&L1,line0,Coloum2);
		Lcd_VoidSendChar(':' ,&L1);
		_delay_ms(100);

		Lcd_VoidGoXY(&L1,line1,Coloum3);
		Lcd_VoidSendString("Marzoook_1999",&L1);
		_delay_ms(100);

	}

	return 0;
}


