/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
//#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
//#include "1-MCAL/4-TIMER0/TIMER0_Interface.h"
//#include "1-MCAL/6-TIMER1/TIMER1_interface.h"
//#include "1-MCAL/WDT/WDT_Interface.h"
#include "1-MCAL/UART/UART_interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>

#define PORTD_ITI    (*(volatile u8*)0x32)

#define SPDR_REG     (*(volatile u8*)0x2F)
#define SPSR_REG     (*(volatile u8*)0x2E)
#define SPCR_REG     (*(volatile u8*)0x2D)

void SPI_voidInit(void);
u8 SPI_voidRead_Write(u8  copy_u8_result);

void main(void)
{

	SPI_voidInit();
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin2,DIO_Output);
	u8 res = 0 ;


	while(1)
	{

		res = SPI_voidRead_Write('m') ;
		if(res == 'i')
		{
			TOG_BIT(PORTD_ITI ,2 );
			_delay_ms(1000);
		}

		else
		{
			DIO_ErrStateSetPinValue(DIO_GroupD,Pin2,0);

		}



	}



}

void SPI_voidInit(void)
{
	/*  configure pins*/
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin4,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin5,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin6,DIO_Input);
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin7,DIO_Output);

	SET_BIT(SPCR_REG , 4);  //mster

	SET_BIT(SPCR_REG , 5);

	SET_BIT(SPCR_REG , 3);
	SET_BIT(SPCR_REG , 2);
	SET_BIT(SPCR_REG , 6);    //enble spi

	CLR_BIT(SPCR_REG , 1);  //pre 16
	SET_BIT(SPCR_REG , 0);


}

u8 SPI_voidRead_Write(u8  copy_u8_result)
{
	DIO_ErrStateSetPinValue(DIO_GroupB,Pin4,DIO_Low);
	SPDR_REG = copy_u8_result ;  // WIRTE on slave
	while(Get_Bit(SPSR_REG , 7 ) == 0 )  ;
	DIO_ErrStateSetPinValue(DIO_GroupB,Pin4,DIO_High);
	return SPDR_REG ;           // Read from slave
}

