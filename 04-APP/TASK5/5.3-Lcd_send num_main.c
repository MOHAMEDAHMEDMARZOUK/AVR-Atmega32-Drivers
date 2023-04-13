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

	/********c0  c1   c2  c3 ****/
	//u8 KEYPAD_Arr[4][4]={{'7','8','9','/'}   /R0/
		//			    ,{'4','5','6',''}   /*R1/
		//			    ,{'1','2','3','-'}   /R2/
			//		    ,{'N','0','=','+'}}; /R3/
	//KEYPAD_voidinitkeyPad();

	Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
	Lcd_VoidInit(&lcd1);


    u32 number=34535598 ;
    Lcd_VoidSendNumber(number,&lcd1);
    //Lcd_VoidSendChar('5',&lcd1);
	while(1)
	{


	}

}





#define PORTA_ITI    (*(volatile u8*)0x3B)
#define PORTC_ITI    (*(volatile u8*)0x35)
void funcx(void);

u16 M_volt ;
u16 Temp ;
u32 number ;

int main()
{

	ADC_voidInit();
		DIO_ErrStateSetGroupDirection(DIO_GroupA , 0X00 );
		//DIO_ErrStateSetGroupDirection(DIO_GroupC , 0XFF );
		Lcd_Info lcd1={DIO_GroupD,DIO_GroupD,DIO_GroupD,Pin2,Pin1,Pin0,DIO_GroupC};
		Lcd_VoidInit(&lcd1);



		while(1)
		{
			ADC_u8StartConversionsynch(0 , &M_volt );

			M_volt = ((u32)M_volt * 5000ul) / 256ul ;
			Temp  = M_volt / 10;
			Lcd_VoidSendString("temp is = ",&lcd1) ;
			Lcd_VoidSendNumber(M_volt,&lcd1);
			Lcd_VoidSendChar('c',&lcd1);

			//ADC_u8StartConversionsynch(1 ,&RES );
			//DIO_ErrStateSetGroupValue(DIO_GroupC , RES ) ;
			//ADC_u8StartConversionAsynch(5 ,&RES ,funcx );
			_delay_ms(5000);
			Lcd_VoidSendCommand(0b00000001 ,&lcd1);
		}


		return 0 ;


}

void funcx(void)
{

}

