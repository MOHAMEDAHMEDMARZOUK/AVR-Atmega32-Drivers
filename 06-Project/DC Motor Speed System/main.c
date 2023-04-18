/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "1-MCAL/4-TIMER0/TIMER0_Interface.h"
#include "1-MCAL/6-TIMER1/TIMER1_interface.h"
#include "2-HAL/LCD/LCD_interface.h"
#include "2-HAL/KEYPAD/KEYPAD_interface.h"


#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>

#define PORTA_ITI    (*(volatile u8*)0x3B)



int main(void)
{
	TIMER0_voidTIMER0Init();

	u8 Keypad;
	KEYPAD_voidinitkeyPad();
	u8 Array[4][4]={{'7','8','9','7'},
			{'4','5','6','6'},
			{'1','2','3','5'},
			{'a','0','c','v'}};

	LCD_voidInit();
	LCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
	LCD_voidSendString("Enter Speed:");


	TIMER1_voidTIMER1Init();
	TIMER1_voidTIMER1Set_ICR1(65000);
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin5,DIO_Output);

	while(1)
	{



		Keypad=KEYPAD_ErrStateReadkeyPad(Array);
		if(Keypad != Null)
		{
			if (Keypad == 'a')
			{
				LCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_13);
				LCD_voidSendString("100%");
				TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(255);
			}
			else if (Keypad == '0')
			{
				LCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_13);
				LCD_voidSendString(" 0%");
				TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(0);

			}
			else if (Keypad == 'c')
			{
				LCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
				LCD_voidSendString("  thank you  :  ");
				TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(0);
			}
			else {

				LCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_13);
				LCD_voidSendData(Keypad);
				LCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_14);
				LCD_voidSendString("0%");
				u8 result =Keypad*25;
				TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(result);
			}

		}

	}


	return 0 ;
}





