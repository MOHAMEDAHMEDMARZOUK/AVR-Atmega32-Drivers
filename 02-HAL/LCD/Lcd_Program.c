/*
 * Lcd_Program.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Mohamed Marzok
 */

#include <util/delay.h>
#include "../../1-MCAL/1-DIO/DIO_Interface.h"
#include "Lcd_Interface.h"

u8 counter = 0 ;

void Lcd_VoidSendCommand(u8 Copy_Command, Lcd_Info * Lcd)
{
	/*RS->LOW*/
	DIO_ErrStateSetPinValue(Lcd -> RS_Group ,Lcd -> RS_Pin , DIO_Low);
	/*RW-> LOW*/
	DIO_ErrStateSetPinValue(Lcd -> RW_Group ,Lcd -> RW_Pin , DIO_Low);
	/*Group = COmmand */
	DIO_ErrStateSetGroupValue(Lcd -> Data_Group , Copy_Command );

	/*Enable*/
	DIO_ErrStateSetPinValue(Lcd -> E_Group ,Lcd -> E_Pin , DIO_High);
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd -> E_Group ,Lcd -> E_Pin , DIO_Low);
	_delay_ms(1);
}

void Lcd_VoidSendChar(u8 Copy_Char, Lcd_Info * Lcd)
{

	if(counter<=17)
	{
		/*RS->High*/
		DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_High);
		/*RW-> LOW*/
		DIO_ErrStateSetPinValue(Lcd -> RW_Group ,Lcd -> RW_Pin , DIO_Low);
		/*Group = COmmand */
		DIO_ErrStateSetGroupValue(Lcd->Data_Group , Copy_Char) ;
		/*Enable*/
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_High) ;
		_delay_ms(1);
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_Low) ;
		_delay_ms(1);
		counter++;
		if(counter==16)
		{
			Lcd_VoidSendCommand((LCD_SetAddressDDRAM + LCD_SecondLine),Lcd);
		}
	}
	else if(counter>16)
	{
		/*RS->High*/
		DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_High);
		/*RW-> LOW*/
		DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_Low) ;
		/*Group = COmmand */
		DIO_ErrStateSetGroupValue(Lcd->Data_Group , Copy_Char) ;
		/*Enable*/
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_High) ;
		_delay_ms(1);
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_Low) ;
		_delay_ms(1);
		counter++;
	}
	if(counter==32)
	{
		counter=0;
		Lcd_VoidSendCommand((LCD_SetAddressDDRAM + LCD_FirstLine),Lcd);
	}
}


void Lcd_VoidInit(Lcd_Info * Lcd)
{
	/*Set Directions*/
	DIO_ErrStateSetPinDirection(Lcd->RS_Group,Lcd->RS_Pin,DIO_Output);
	DIO_ErrStateSetPinDirection(Lcd->RW_Group,Lcd->RW_Pin,DIO_Output);
	DIO_ErrStateSetPinDirection(Lcd->E_Group,Lcd->E_Pin,DIO_Output);
	DIO_ErrStateSetGroupDirection(Lcd->Data_Group,0xFF);
	/*Wait More than 30 ms */
	_delay_ms(40);
	/*Sent Function Set*/
	Lcd_VoidSendCommand(default_Function_Set , Lcd) ;
	/*wait more than 39us*/
	_delay_ms(1);
	/*Sent Displayon/off*/
	Lcd_VoidSendCommand(default_Displayon_off , Lcd) ;
	/*wait more than 39us*/
	_delay_ms(1);
	/*Sent Clear*/
	Lcd_VoidSendCommand(LCD_ClearDisplay , Lcd) ;
	/*wait more than 39us*/
	_delay_ms(2);

}


void Lcd_VoidSendString(u8 *Address_String ,Lcd_Info * Lcd)
{
	/*Counter For Loop */
	u8 Local_Counter = 0 ;
	/*Loop*/
	while (Address_String[Local_Counter]!='\0')
	{
		/*Send Char */
		Lcd_VoidSendChar(Address_String[Local_Counter],Lcd) ;
		/*Increment Counter */
		Local_Counter++;
	}
}


void Lcd_VoidGoXY(Lcd_Info * Lcd ,u8 Copy_XLocation ,u8 Copy_YLocation )
{
	u8 Local_Address = 0 ;
	if (Copy_XLocation == 0)
	{
		Local_Address = Copy_YLocation ;
	}
	else if (Copy_XLocation == 1)
	{
		Local_Address = Copy_YLocation + LCD_SecondLine ;
	}
	else
	{

	}
	Lcd_VoidSendCommand((LCD_SetAddressDDRAM + Local_Address),Lcd);
}

void Lcd_VoidSendNumber(u32 Number, Lcd_Info * Lcd)
{
	if(Number==0)
	{
		Lcd_VoidSendChar('0',Lcd);
	}
	else
	{
		u8 counter =0;
		u8 counter2 =0;
		u8 arr[10];
		static u8 local_counter;
		s8 local_counter2;
		while(Number!=0)
		{
			counter++;

			for(local_counter=counter2 ; local_counter<counter ; local_counter++)
			{
				arr[local_counter]=(Number%10) ;
			}

			Number=Number/10;
			counter2++;

		}
		for(local_counter2=counter2-1 ; local_counter2>=0 ; local_counter2--)
		{
			Lcd_VoidSendChar(arr[local_counter2]+48,Lcd);
		}
	}
}

void Lcd_VoidSendSpecialChar(u8 *Special_Arr,Lcd_Info * Lcd ,u8 Copy_XLocation ,u8 Copy_YLocation)
{
	 u8 Local_counter = 0 ;
	/*go from DDRAM to CGRAM*/
	Lcd_VoidSendCommand(LCD_SetAddressCGRAM,Lcd);
	/*write in CGRAM*/
	for( Local_counter=0 ; Local_counter < Size_CGRAM ; Local_counter++)
	{
		Lcd_VoidSendChar(Special_Arr[Local_counter],Lcd);

	}

	/*go from CGRAM to DDRAM*/

	Lcd_VoidSendCommand(0x80,Lcd);
	Lcd_VoidGoXY(Lcd,Copy_XLocation,Copy_YLocation);
	//Lcd_VoidSendChar(0,Lcd);


	/*send the character*/
	 for( Local_counter=0 ; Local_counter < (sizeof(Special_Arr) / sizeof(Special_Arr[0])) -1 ; Local_counter++)
	{

		Lcd_VoidSendChar(Local_counter,Lcd);
		_delay_ms(100);    //size_Special_Array

	}

}
