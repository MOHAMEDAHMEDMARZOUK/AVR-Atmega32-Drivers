/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>


#define Pressed       0
#define NOTPressed    1
#define num0 0x3F
#define num1 0x06
#define num2 0x5B
#define num3 0x4F
#define num4 0x66
#define num5 0x6D
#define num6 0x7D
#define num7 0x07
#define num8 0x7F
#define num9 0x6F

int main()
{
	u8 arr[10]={num0 ,num1 , num2 , num3,num4,num5,num6,num7,num8,num9} ;
	/* SET 2-SEVEN AS O/P DDRA (0,1,2) */
	DIO_ErrStateSetPinDirection(DIO_GroupD , Pin0 , DIO_Output );
	DIO_ErrStateSetPinDirection(DIO_GroupD , Pin1 , DIO_Output );


	/* SET SEVEN SEGMANT AS O/P DDRB ALL PINS  */
	DIO_ErrStateSetGroupDirection(DIO_GroupC , 0XFF ) ;

	u8 SW1 , SW2 ;
	DIO_ErrStateSetPinValue(DIO_GroupD , Pin0 , 1);

	while(1)
	{

		for(SW1 = 0 ; SW1 < 10 ; SW1++)
		{
			//DIO_ErrStateSetPinValue(DIO_GroupD , Pin0 , 0);
			//DIO_ErrStateSetPinValue(DIO_GroupD , Pin1 , 1);
			//DIO_ErrStateSetGroupValue(DIO_GroupC , arr[SW1] );
			// _delay_ms(100);
		//	 DIO_ErrStateSetPinValue(DIO_GroupD , Pin0 , 1);


		 for(SW2 = 0 ; SW2 < 10 ; SW2++)
		 {
			 if( SW1 == 9 )
			 {
				 DIO_ErrStateSetPinValue(DIO_GroupD , Pin0 , 0);
				 DIO_ErrStateSetPinValue(DIO_GroupD , Pin1 , 0);
				 DIO_ErrStateSetGroupValue(DIO_GroupC , arr[SW2] );

			 }
			 else{
			 DIO_ErrStateSetPinValue(DIO_GroupD , Pin0 , 0);
			 DIO_ErrStateSetPinValue(DIO_GroupD , Pin1 , 1);
			 DIO_ErrStateSetGroupValue(DIO_GroupC , arr[SW1] );
			 _delay_ms(100);
			 DIO_ErrStateSetPinValue(DIO_GroupD , Pin0 , 1);
			 DIO_ErrStateSetPinValue(DIO_GroupD , Pin1 , 0);
		     DIO_ErrStateSetGroupValue(DIO_GroupC , arr[SW2] );
		     _delay_ms(100);
			 }

		 }
		 }

		_delay_ms(5000);


	}

	return 0;
}


/*
			 DIO_ErrStateSetGroupValue(DIO_GroupC , 0x3F ); // 0
			  _delay_ms(1000);
			  DIO_ErrStateSetGroupValue(DIO_GroupC , 0x6  ); // 1
			  _delay_ms(1000);
			  DIO_ErrStateSetGroupValue(DIO_GroupC , 0X5B  ); // 2
			  _delay_ms(1000);
			  DIO_ErrStateSetGroupValue(DIO_GroupC , 0x4F ); // 3
			 _delay_ms(1000);
			 DIO_ErrStateSetGroupValue(DIO_GroupC , 0x66 ); // 4
			  _delay_ms(1000);
			 DIO_ErrStateSetGroupValue(DIO_GroupC , 0x6D ); // 5
			 _delay_ms(1000);
			 DIO_ErrStateSetGroupValue(DIO_GroupC , 0x7D ); // 6
		     _delay_ms(1000);
		     DIO_ErrStateSetGroupValue(DIO_GroupC , 0x7  ); // 7
		      _delay_ms(1000);
		     DIO_ErrStateSetGroupValue(DIO_GroupC , 0x7F ); // 8
		     */
