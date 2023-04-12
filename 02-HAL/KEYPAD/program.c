/*
 * program.c
 *
 *  Created on: Mar 26, 2023
 *      Author: Arabtech
 */
#include "KEYPAD_interface.h"
#include "util/delay.h"
/*********************c0  c1   c2  c3 ***********/


u8 Arr_Row[8] = {pin1_Row , pin2_Row , pin3_Row , pin4_Row ,  Group1_Row , Group2_Row , Group3_Row  , Group4_Row};
u8 Arr_Coloum[8] = {pin1_Coloum , pin2_Coloum , pin3_Coloum , pin4_Coloum ,  Group1_Coloum , Group2_Coloum , Group3_Coloum  , Group4_Coloum};


void  KEYPAD_voidinitkeyPad(void)
{

	DIO_ErrStateSetPinDirection( Group1_Row , pin1_Row , DIO_Output );
	DIO_ErrStateSetPinDirection( Group2_Row , pin2_Row , DIO_Output );
	DIO_ErrStateSetPinDirection( Group3_Row , pin3_Row , DIO_Output );
	DIO_ErrStateSetPinDirection( Group3_Row , pin4_Row , DIO_Output );

	DIO_ErrStateSetPinValue    ( Group1_Row , pin1_Row , DIO_Output );
	DIO_ErrStateSetPinValue    ( Group2_Row , pin2_Row , DIO_Output );
	DIO_ErrStateSetPinValue    ( Group3_Row , pin3_Row , DIO_Output );
	DIO_ErrStateSetPinValue    ( Group3_Row , pin4_Row , DIO_Output );

	DIO_ErrStateSetPinDirection( Group1_Coloum , pin1_Coloum  , DIO_Input );
	DIO_ErrStateSetPinDirection( Group2_Coloum , pin2_Coloum  , DIO_Input );
	DIO_ErrStateSetPinDirection( Group3_Coloum , pin3_Coloum  , DIO_Input );
	DIO_ErrStateSetPinDirection( Group3_Coloum , pin4_Coloum  , DIO_Input );

	DIO_ErrStateSetPinValue    ( Group1_Coloum , pin1_Coloum , DIO_Output );
	DIO_ErrStateSetPinValue    ( Group2_Coloum , pin2_Coloum , DIO_Output );
	DIO_ErrStateSetPinValue    ( Group3_Coloum , pin3_Coloum , DIO_Output );
	DIO_ErrStateSetPinValue    ( Group3_Coloum , pin4_Coloum , DIO_Output );

}



u8   KEYPAD_ErrStateReadkeyPad(u8 KEYPAD_Arr[][Coloum] )
{
	u8 result ;
	u8 row=0;
	u8 flag =0;
	u8 coloum=0;
	u8 y = 0;

	_delay_ms(200);
	for(row=0 ; row<4 ; row++)
	{
		//DIO_ErrStateSetPinValue(DIO_GroupC,row+4,DIO_Low);//row+4 because the row start by pin 4 to 7
		DIO_ErrStateSetPinValue(Arr_Row[row+4],Arr_Row[row],DIO_Low);
		for(coloum=0 ; coloum<4 ; coloum++)
		{
			//DIO_ErrStateReadPinValue(DIO_GroupC,coloum,&result);
			DIO_ErrStateReadPinValue(Arr_Coloum[coloum+4],Arr_Coloum[coloum],&result);

			if(result == Button_Pressed )
			{
				y = KEYPAD_Arr[row][coloum];
				flag=1;
				break ;
			}

		}
		//DIO_ErrStateSetPinValue(DIO_GroupC,row+4,DIO_High);
		DIO_ErrStateSetPinValue(Arr_Row[row+4],Arr_Row[row],DIO_High);

		if(flag==1)
		{
			break;
		}
	}
	return y ;
}

