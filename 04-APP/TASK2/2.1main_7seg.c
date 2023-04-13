/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "../1-MCAL/1-DIO/DIO_Interface.h"
#include "../4-Common/BIT_MATH.h"
#include "../4-Common/STD_TYPES.h"
#include <util/delay.h>


#define Pressed       0
#define NOTPressed    1

int main()
{
	/* SET SWITCHES AS I/P DDRA (0,1,2) */
	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin0 , DIO_Input );
	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin1 , DIO_Input );
	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin2 , DIO_Input );

	/* SET SWITCHES AS I/P ENABLR PULL UP */
	DIO_ErrStateSetPinValue(DIO_GroupA , Pin0 , DIO_High );
	DIO_ErrStateSetPinValue(DIO_GroupA , Pin1 , DIO_High );
	DIO_ErrStateSetPinValue(DIO_GroupA , Pin2 , DIO_High );

	/* SET SEVEN SEGMANT AS O/P DDRB ALL PINS  */
	DIO_ErrStateSetGroupDirection(DIO_GroupB , 0XFF ) ;

	u8 SW1 , SW2 , SW3 ;

	while(1)
	{
	 DIO_ErrStateReadPinValue(DIO_GroupA ,Pin0 ,&SW1);
	 DIO_ErrStateReadPinValue(DIO_GroupA ,Pin1 ,&SW2);


	 if (SW1 == Pressed )
	 	{
		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x3F ); // 0
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x6  ); // 1
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x5B ); // 2
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x4F ); // 3
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x66 ); // 4
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x6D ); // 5
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x7D ); // 6
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x7  ); // 7
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x7F ); // 8
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x6F ); // 9
		  _delay_ms(1000);
		  DIO_ErrStateReadPinValue(DIO_GroupA ,Pin2 ,&SW3);
		  if (SW3 == Pressed ) { break; }

		  DIO_ErrStateSetGroupValue(DIO_GroupB , 0x3F ); // 0

	 	}

	 else if (SW2 == Pressed )
	 	{
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x6F ); // 9
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x7F ); // 8
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x7  ); // 7
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x7D ); // 6
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x6D ); // 5
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x66 ); // 4
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x4F ); // 3
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x5B ); // 2
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x6  ); // 1
		 _delay_ms(1000);
		 DIO_ErrStateSetGroupValue(DIO_GroupB , 0x3F ); // 0
		 _delay_ms(1000);


	 	}



	}

	return 0;
}



