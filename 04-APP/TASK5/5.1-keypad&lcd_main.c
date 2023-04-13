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



int  main()
{


	//KEYPAD_voidinitkeyPad();


	u8 KEYPAD_Arr[4][4]={{'7','8','9','/'}   /*R0*/
	,{'4','5','6','*'}   /*R1*/
	,{'1','2','3','-'}   /*R2*/
	,{'N','0','=','+'}}; /*R3*/


	KEYPAD_voidinitkeyPad();
	Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
	Lcd_VoidInit(&lcd1);
	u8 result ;

	//_delay_ms(1000);



	while(1)
	{

		result = KEYPAD_ErrStateReadkeyPad(KEYPAD_Arr  );
		if( result != Null)
		{
		Lcd_VoidSendChar(result,&lcd1);
		//_delay_ms(1000);
		}
	}

	return 0 ;
}






