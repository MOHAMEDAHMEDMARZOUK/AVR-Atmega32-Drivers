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
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>



typedef enum
{
	R0_C0 ,
	R0_C1 ,
	R0_C2 ,
	R0_C3 ,
	R1_C0 ,
	R1_C1 ,
	R1_C2 ,
	R1_C3 ,
	R2_C0 ,
	R2_C1 ,
	R2_C2 ,
	R2_C3 ,
	R3_C0 ,
	R3_C1 ,
	R3_C2 ,
	R3_C3 ,

}kay_values;

int main()
{
	DIO_ErrStateSetGroupDirection(DIO_GroupA ,0XFF);

	while(1)
	{
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin0 , DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin1 , DIO_High);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin2 , DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin3 , DIO_High);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin6 , DIO_High);
		_delay_ms(1000);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin6 , DIO_Low);

		DIO_ErrStateSetPinValue(DIO_GroupA , Pin1 , DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin0 , DIO_High);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin3 , DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin2 , DIO_High);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin7 , DIO_High);
		_delay_ms(1000);
		DIO_ErrStateSetPinValue(DIO_GroupA , Pin7 , DIO_Low);

	}

	return 0 ;
}

/*int main()
{
	 //FIRST 4 BIT I/P SECOND 4 BIT O/P 0XF0/
	 DIO_ErrStateSetGroupDirection(DIO_GroupC ,0XF0);

	 //FIRST 4 BIT I/P PULLUP SECOND 4 BIT O/P VCC 0XFF/
	 DIO_ErrStateSetGroupValue(DIO_GroupC ,0XFF);
	 u8 RES ;
	 u8 i , j;
	 u8 State = 0 ;



	 Lcd_Info L1 = { DIO_GroupB , DIO_GroupB , DIO_GroupB , Pin2  , Pin1 ,Pin0 ,DIO_GroupA };
	 	Lcd_VoidInit(&L1);

	 	while(1)
	 	{
	 		for (i=0 ; i < 4 ;i++ )
	 			 {
	 				 DIO_ErrStateSetPinValue(DIO_GroupC , i+4 , DIO_Low);
	 				 for (j=0 ; j < 4 ;j++ )
	 				 {
	 					 DIO_ErrStateReadPinValue(DIO_GroupC , j , &RES);
	 					 if(RES == PressedPullUp )
	 					 {
	 						 State = 1 ;
	 						 RES = 'k' ;
	 						 break ;
	 					 }
	 				 }
	 				 DIO_ErrStateSetPinValue(DIO_GroupC , j , DIO_High);
	 				 if (State == 1)
	 				 {
	 					 break ;
	 				 }
	 			 }

	 		Lcd_VoidSendChar('M',&L1);
	 		_delay_ms(100);

	 		Lcd_VoidGoXY(&L1,line0,Coloum1);
	 		Lcd_VoidSendChar('r' ,&L1);
	 		_delay_ms(100);

	 		Lcd_VoidGoXY(&L1,line0,Coloum2);
	 		Lcd_VoidSendChar(':' ,&L1);
	 		_delay_ms(100);

	 		Lcd_VoidGoXY(&L1,line0,Coloum3);
	 		Lcd_VoidSendChar(RES ,&L1);
	 		_delay_ms(100);

	 		Lcd_VoidGoXY(&L1,line1,Coloum3);
	 		Lcd_VoidSendString("Marzoook",&L1);
	 		_delay_ms(2000);

	 	}
	return 0;
}
 * */
