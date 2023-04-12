/*
 * UART_Programme.c
 *
 *  Created on: Apr 7, 2023
 *      Author: 2022
 */

#include "UART_interface.h"
#include "UART_Private.h"
#include "../../4-Common/BIT_MATH.h"
#include "../../1-MCAL/1-DIO/DIO_Interface.h"


void UART_voidInit(void)
{
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin0,DIO_Input);
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin1,DIO_Output);
	UCSRB = UCSRB_Value ;
	UCSRC = UCSRC_Value ;
	UBRRL = UBRRL_Value ;
	UBRRH = UBRRH_Value ;
}


void UART_voidRead (u16 *copy_u16_result)
{

	while ( Get_Bit(UCSRA , UCSRA_Receive_Complete ) == 0 )  ;
	Set_Bit(UCSRA , UCSRA_Receive_Complete );
	*copy_u16_result = UDR ;

}

void UART_voidWrite(u16  copy_u16_result)
{
	while( Get_Bit(UCSRA , UCSRA_Data_RegEmpty ) == 0 ) ;  //wait till the UDR is ready to have a value
	Set_Bit(UCSRA , UCSRA_Data_RegEmpty );                // Clear flag

	UDR = copy_u16_result   ;

	while( Get_Bit(UCSRA , UCSRA_Transmit_Complete ) == 0 ) ;  //wait till transmit is complete
	Set_Bit(UCSRA , UCSRA_Transmit_Complete );                // Clear flag
}
