/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
#include "1-MCAL/3-ADC/ADC_Interface.h"
#include "2-HAL/Led/Led_Interface.h"

#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>


#define PORTA_ITI    (*(volatile u8*)0x3B)
#define PORTC_ITI    (*(volatile u8*)0x35)
void funcx(void);
u16 RES ;

int main()
{

	ADC_voidInit();
	DIO_ErrStateSetGroupDirection(DIO_GroupA , 0X00 );
	DIO_ErrStateSetGroupDirection(DIO_GroupC , 0XFF );



	while(1)
	{

		//ADC_u8StartConversionsynch(1 ,&RES );
		//DIO_ErrStateSetGroupValue(DIO_GroupC , RES ) ;
		ADC_u8StartConversionAsynch(5 ,&RES ,funcx );
	}


	return 0 ;

}

void funcx(void)
{
	PORTC_ITI=RES;
}

