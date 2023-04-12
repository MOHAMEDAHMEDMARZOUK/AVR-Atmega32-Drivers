/*********************************************************************/
/*********************************************************************/
/******** Author:    Marzouk       ***********************************/
/******** Component: TWI           ***********************************/
/******** Layer:     MCAL          ***********************************/
/******** Version:   1.0           ***********************************/
/*********************************************************************/
/*********************************************************************/

#include "../../4-Common/BIT_MATH.h"
#include "../../4-Common/STD_TYPES.h"

//#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"


/*Set master address to 0 if master will not be addressed*/
void TWI_voidInitMaster(u8 Copy_u8Address)
{
	/*Enable Acknowledge bit 6 */
	SET_BIT(TWCR,TWCR_TWEA);

	/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
	/*1- Set TWBR to 2*/
	TWBR = 2;

	/*2- Clear the prescaler bits (TWPS) Prescaler Value DIV BY 1*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/*Check if the master node will be addressed*/
	if(Copy_u8Address != 0)
	{
		/*Set the required address in the 7 MSB of TWAR*/
		TWAR =  (Copy_u8Address<<1);
	}

	/*Enable TWI I2C */
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidInitSlave(u8 Copy_u8Address)
{
	/*Enable Acknowledge bit 6 */
	SET_BIT(TWCR,TWCR_TWEA);

	/*Set the slave address*/
	TWAR = Copy_u8Address<<1;

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}


TWI_ErrStatus TWI_SendStartCondition(void)
{
	/*Send start condition*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status*/
	if((TWSR & 0xF8) != START_ACK )
	{
		return StartConditionErr;
	}

	return TWI_NoError;
}

TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	/*Send start condition*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status*/
	if((TWSR & 0xF8) != REP_START_ACK )
	{
		return RepeatedStartError;
	}

	return TWI_NoError;
}



TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	/*send the 7bit slave address to the bus*/
	TWDR = Copy_u8SlaveAddress <<1;

	/*set the write = 0  request in the LSB in the data register*/
	CLR_BIT(TWDR,0);

	/*Clear the start condition bit5*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status (TWSR) to see if SLA+W was Master transmit and ACK received*/
	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK )
	{
		return SlaveAddressWithWriteErr;
	}


	return TWI_NoError;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{

	/*send the 7bit slave address to the bus*/
	TWDR = Copy_u8SlaveAddress <<1;
	/*set the read = 1 request in the LSB in the data register*/
	SET_BIT(TWDR,0);

	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status (TWSR) to see if SLA+R Master transmit and ACK received*/
	if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK )
	{
		return SlaveAddressWithReadErr;
	}

	return TWI_NoError;
}



TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	/*Write the data byte on the bus*/
	TWDR = Copy_u8DataByte;

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status (TWSR) to see if SLDATA+W Master transmit and ACK received*/
	if((TWSR & 0xF8) !=  MSTR_WR_BYTE_ACK)
	{
		return  MasterWriteByteErr;
	}

	return TWI_NoError;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte)
{
	/*Clear the interrupt flag to allow the slave send the data*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status (TWSR) to see if SLDATA Master received and send ACK */
	if((TWSR & 0xF8) !=  MSTR_RD_BYTE_WITH_ACK)
	{
		return  MasterReadByteErr;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte = TWDR;
	}

	return TWI_NoError;
}


void TWI_SendStopCondition(void)
{
	/*Sent a stop condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

}
