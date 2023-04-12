/*
 * DIO_Program.c
 *
 *  Created on: Mar 23, 2023
 *      Author: 2022
 */


#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "../../4-Common/BIT_MATH.h"
#include "../../4-Common/STD_TYPES.h"



ErrState  DIO_ErrStateSetPinDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState)
{
	if(Copy_PinNumber<=Pin7 && Copy_PinNumber>=Pin0)
	{
		/*Input-> write Zero DDR (CLR) */
		if (Copy_DirectionState == DIO_Input )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : Clr_Bit(DDRA_ITI , Copy_PinNumber ) ;break ;
			/*Group B*/
			case DIO_GroupB: Clr_Bit(DDRB_ITI , Copy_PinNumber ) ;break ;
			/*Group C*/
			case DIO_GroupC : Clr_Bit(DDRC_ITI , Copy_PinNumber ) ;break ;
			/*Group D*/
			case DIO_GroupD : Clr_Bit(DDRD_ITI , Copy_PinNumber ) ;break ;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		/*Output -> write DDR = one */
		else if (Copy_DirectionState == DIO_Output )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : Set_Bit(DDRA_ITI,Copy_PinNumber);break;
			/*Group B*/
			case DIO_GroupB : Set_Bit(DDRB_ITI,Copy_PinNumber);break;
			/*Group C*/
			case DIO_GroupC : Set_Bit(DDRC_ITI,Copy_PinNumber);break;
			/*Group D*/
			case DIO_GroupD : Set_Bit(DDRD_ITI,Copy_PinNumber);break;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		else
		{
			return DirectionError ;
		}

		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}
}


ErrState  DIO_ErrStateSetPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_ValueState Copy_ValueState)
{
	if(Copy_PinNumber<=Pin7 && Copy_PinNumber>=Pin0)
	{
		/*Low-> write Zero Port (CLR) */
		if (Copy_ValueState == DIO_Low )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : Clr_Bit(PORTA_ITI , Copy_PinNumber ) ;break ;
			/*Group B*/
			case DIO_GroupB: Clr_Bit(PORTB_ITI , Copy_PinNumber ) ;break ;
			/*Group C*/
			case DIO_GroupC : Clr_Bit(PORTC_ITI , Copy_PinNumber ) ;break ;
			/*Group D*/
			case DIO_GroupD : Clr_Bit(PORTD_ITI , Copy_PinNumber ) ;break ;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		/*High -> write port = one */
		else if (Copy_ValueState == DIO_High )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : Set_Bit(PORTA_ITI,Copy_PinNumber);break;
			/*Group B*/
			case DIO_GroupB : Set_Bit(PORTB_ITI,Copy_PinNumber);break;
			/*Group C*/
			case DIO_GroupC : Set_Bit(PORTC_ITI,Copy_PinNumber);break;
			/*Group D*/
			case DIO_GroupD : Set_Bit(PORTD_ITI,Copy_PinNumber);break;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		else
		{
			return DirectionError ;
		}

		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}

}


ErrState  DIO_ErrStateReadPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber ,u8 *Result)
{
	/*check on pin range from 0 to 7 */
	if (Copy_PinNumber>= Pin0 && Copy_PinNumber <=Pin7)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: *Result=Get_Bit(PINA_ITI,Copy_PinNumber); break ;
		case DIO_GroupB: *Result=Get_Bit(PINB_ITI,Copy_PinNumber); break ;
		case DIO_GroupC: *Result=Get_Bit(PINC_ITI,Copy_PinNumber); break ;
		case DIO_GroupD: *Result=Get_Bit(PIND_ITI,Copy_PinNumber); break ;
		default:
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}

}




//

ErrState  DIO_ErrStateSetGroupDirection(DIO_GroupNumber Copy_GroupNumber ,u8 Copy_DirectionState)
{
	if (Copy_DirectionState <= 0xff && Copy_DirectionState>=0x00)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: DDRA_ITI =  Copy_DirectionState ;break ;
		case DIO_GroupB: DDRB_ITI =  Copy_DirectionState ;break ;
		case DIO_GroupC: DDRC_ITI =  Copy_DirectionState ;break ;
		case DIO_GroupD: DDRD_ITI =  Copy_DirectionState ;break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return DirectionRangError;
	}
}

ErrState  DIO_ErrStateSetGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 Copy_ValueState)
{
	if (Copy_ValueState <= 0xff && Copy_ValueState>=0x00)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: PORTA_ITI =  Copy_ValueState ;break ;
		case DIO_GroupB: PORTB_ITI =  Copy_ValueState ;break ;
		case DIO_GroupC: PORTC_ITI =  Copy_ValueState ;break ;
		case DIO_GroupD: PORTD_ITI =  Copy_ValueState ;break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return ValueRangError;
	}

}

ErrState  DIO_ErrStateReadGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 *Result)
{
	if(Result!=Null)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: *Result = PINA_ITI ; break ;
		case DIO_GroupB: *Result = PINB_ITI ; break ;
		case DIO_GroupC: *Result = PINC_ITI ; break ;
		case DIO_GroupD: *Result = PIND_ITI ; break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return AddressError;
	}

}


