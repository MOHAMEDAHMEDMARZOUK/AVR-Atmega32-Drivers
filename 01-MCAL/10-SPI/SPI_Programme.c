/*
 * UART_Programme.c
 *
 *  Created on: Apr 7, 2023
 *      Author: 2022
 */

#include "SPI_interface.h"
#include "SPI_Private.h"
#include "../../4-Common/BIT_MATH.h"
#include "../../1-MCAL/1-DIO/DIO_Interface.h"

void SPI_voidInit_Master(void)
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

void SPI_voidInit_Slave(void)
{

	Clr_Bit(SPCR,7);
	Set_Bit(SPCR,6);
	Set_Bit(SPCR,5);
	Clr_Bit(SPCR,4);
	Set_Bit(SPCR,3);
	Set_Bit(SPCR,2);
	Clr_Bit(SPCR,1);
	Set_Bit(SPCR,0);
}

u8 SPI_u8SendRecieve_Slave(u8 Data)
{
	SPDR=Data;
	while(Get_Bit(SPSR,7)==0);
	return SPDR ;
}

u8 SPI_voidRead_Write_Master(u8  copy_u8_result)
{
	DIO_ErrStateSetPinValue(DIO_GroupB,Pin4,DIO_Low);
	SPDR_REG = copy_u8_result ;  // WIRTE on slave
	while(Get_Bit(SPSR_REG , 7 ) == 0 )  ;
	DIO_ErrStateSetPinValue(DIO_GroupB,Pin4,DIO_High);
	return SPDR_REG ;           // Read from slave
}

