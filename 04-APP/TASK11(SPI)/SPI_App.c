#include "../Bit_Math.h"
#include "../Types.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "SPI_App.h"



void MCAL_SPI_Setup(void)
{
	MCAL_DIO_SetPinDirection(DIO_PortB, DIO_Pin4, DIO_Input);
	MCAL_DIO_SetPinDirection(DIO_PortB, DIO_Pin5, DIO_Input);
	MCAL_DIO_SetPinDirection(DIO_PortB, DIO_Pin6, DIO_Output);
	MCAL_DIO_SetPinDirection(DIO_PortB, DIO_Pin7, DIO_Input);
}
void MCAL_SPI_Init(void)
{

	//enable slave
	//enable spi

	CLR_Bit(SPCR, 7);
	SET_Bit(SPCR, 6);
	SET_Bit(SPCR, 5);
	CLR_Bit(SPCR, 4);
	SET_Bit(SPCR, 3);
	SET_Bit(SPCR, 2);
	CLR_Bit(SPCR, 1);
	SET_Bit(SPCR, 0);

	CLR_Bit(SPSR, 0);
}

u8 MCAL_SPI_Send_Receive(u8 data)
{
	SPDR = data;
	while (!GET_Bit(SPSR, 7));
	return SPDR;
}
