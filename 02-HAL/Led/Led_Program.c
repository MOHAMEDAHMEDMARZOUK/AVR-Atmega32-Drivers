/*
 * Led_Program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#include "../../4-Common/Definition.h"
#include "../../1-MCAL/1-DIO/DIO_Interface.h"
#include "../../1-MCAL/1-DIO/DIO_Register.h"
#include "Led_Interface.h"

LedErrState	Led_LedErrStateTurnOn(Led_info *Led)
{
	if(Led->ConnectionType==Source_Connection)
	{
		DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_Output);
		DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_High);
	}
	else if (Led->ConnectionType==Sink_Connection)
	{
		DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_Output);
		DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_Low);
	}
	else
	{
		return LED_ConnectionTypeError ;
	}
	return LED_NO_Error ;


}


LedErrState	Led_LedErrStateTurnOff(Led_info *Led)
{
	if(Led->ConnectionType==Sink_Connection)
		{
			DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_Output);
			DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_High);
		}
		else if (Led->ConnectionType== Source_Connection )
		{
			DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_Output);
			DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_Low);
		}
		else
		{
			return LED_ConnectionTypeError ;
		}
		return LED_NO_Error ;

}












/*if (Led != Null)
	{
		if( Led -> ConnectionType == Source_Connection )
		{
			switch (Led -> Led_Group )
			{

			case DIO_GroupA :
				switch (Led -> Led_Pin )
				{
				case Pin0 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin0 ,DIO_High); break ;
				case Pin1 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin1 ,DIO_High); break ;
				case Pin2 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin2 ,DIO_High); break ;
				case Pin3 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin3 ,DIO_High); break ;
				case Pin4 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin4 ,DIO_High); break ;
				case Pin5 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin5 ,DIO_High); break ;
				case Pin6 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin6 ,DIO_High); break ;
				case Pin7 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin7 ,DIO_High); break ;
				default   : return LED_Pin_Number_Error ;                       break ;
				}
				break ;
		case DIO_GroupB :
			switch (Led -> Led_Pin )
			{
			case Pin0 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin0 ,DIO_High); break ;
			case Pin1 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin1 ,DIO_High); break ;
			case Pin2 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin2 ,DIO_High); break ;
			case Pin3 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin3 ,DIO_High); break ;
			case Pin4 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin4 ,DIO_High); break ;
			case Pin5 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin5 ,DIO_High); break ;
			case Pin6 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin6 ,DIO_High); break ;
			case Pin7 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin7 ,DIO_High); break ;
			default   : return LED_Pin_Number_Error ;                       break ;
			}
			break ;
		case DIO_GroupC :
			switch (Led -> Led_Pin )
			{
			case Pin0 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin0 ,DIO_High); break ;
			case Pin1 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin1 ,DIO_High); break ;
			case Pin2 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin2 ,DIO_High); break ;
			case Pin3 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin3 ,DIO_High); break ;
			case Pin4 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin4 ,DIO_High); break ;
			case Pin5 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin5 ,DIO_High); break ;
			case Pin6 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin6 ,DIO_High); break ;
			case Pin7 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin7 ,DIO_High); break ;
			default   : return LED_Pin_Number_Error ;                       break ;
			}
			break ;
		case DIO_GroupD :
			switch (Led -> Led_Pin )
			{
			case Pin0 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin0 ,DIO_High); break ;
			case Pin1 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin1 ,DIO_High); break ;
			case Pin2 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin2 ,DIO_High); break ;
			case Pin3 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin3 ,DIO_High); break ;
			case Pin4 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin4 ,DIO_High); break ;
			case Pin5 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin5 ,DIO_High); break ;
			case Pin6 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin6 ,DIO_High); break ;
			case Pin7 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin7 ,DIO_High); break ;
			default   : return LED_Pin_Number_Error ;                       break ;
			}
			break ;
		default   : return LED_Group_error ;  break ;
			}

		}

		else if( Led -> ConnectionType == Sink_Connection )
		{
			switch (Led -> Led_Group )
			{

			case DIO_GroupA :
				switch (Led -> Led_Pin )
				{
				case Pin0 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin0 ,DIO_Low); break ;
				case Pin1 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin1 ,DIO_Low); break ;
				case Pin2 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin2 ,DIO_Low); break ;
				case Pin3 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin3 ,DIO_Low); break ;
				case Pin4 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin4 ,DIO_Low); break ;
				case Pin5 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin5 ,DIO_Low); break ;
				case Pin6 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin6 ,DIO_Low); break ;
				case Pin7 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin7 ,DIO_Low); break ;
				default   : return LED_Pin_Number_Error ;                       break ;
				}
				break ;
		case DIO_GroupB :
			switch (Led -> Led_Pin )
			{
			case Pin0 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin0 ,DIO_Low); break ;
			case Pin1 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin1 ,DIO_Low); break ;
			case Pin2 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin2 ,DIO_Low); break ;
			case Pin3 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin3 ,DIO_Low); break ;
			case Pin4 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin4 ,DIO_Low); break ;
			case Pin5 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin5 ,DIO_Low); break ;
			case Pin6 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin6 ,DIO_Low); break ;
			case Pin7 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin7 ,DIO_Low); break ;
			default   : return LED_Pin_Number_Error ;                       break ;
			}
			break ;
		case DIO_GroupC :
			switch (Led -> Led_Pin )
			{
			case Pin0 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin0 ,DIO_Low); break ;
			case Pin1 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin1 ,DIO_Low); break ;
			case Pin2 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin2 ,DIO_Low); break ;
			case Pin3 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin3 ,DIO_Low); break ;
			case Pin4 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin4 ,DIO_Low); break ;
			case Pin5 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin5 ,DIO_Low); break ;
			case Pin6 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin6 ,DIO_Low); break ;
			case Pin7 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin7 ,DIO_Low); break ;
			default   : return LED_Pin_Number_Error ;                       break ;
			}
			break ;
		case DIO_GroupD :
			switch (Led -> Led_Pin )
			{
			case Pin0 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin0 ,DIO_Low); break ;
			case Pin1 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin1 ,DIO_Low); break ;
			case Pin2 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin2 ,DIO_Low); break ;
			case Pin3 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin3 ,DIO_Low); break ;
			case Pin4 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin4 ,DIO_Low); break ;
			case Pin5 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin5 ,DIO_Low); break ;
			case Pin6 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin6 ,DIO_Low); break ;
			case Pin7 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin7 ,DIO_Low); break ;
			default   : return LED_Pin_Number_Error ;                       break ;
			}
			break ;

		default   : return LED_Group_error ;  break ;
			}
		}

		else { return LED_ConnectionTypeError ; }

	}

	else { return LED_AddressError ; }

	return  LED_NO_Error ;
 * */



/*if (Led != Null)
		{
			if( Led -> ConnectionType == Sink_Connection )
			{
				switch (Led -> Led_Group )
				{

				case DIO_GroupA :
					switch (Led -> Led_Pin )
					{
					case Pin0 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin0 ,DIO_High); break ;
					case Pin1 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin1 ,DIO_High); break ;
					case Pin2 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin2 ,DIO_High); break ;
					case Pin3 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin3 ,DIO_High); break ;
					case Pin4 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin4 ,DIO_High); break ;
					case Pin5 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin5 ,DIO_High); break ;
					case Pin6 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin6 ,DIO_High); break ;
					case Pin7 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin7 ,DIO_High); break ;
					default   : return LED_Pin_Number_Error ;                       break ;
					}
					break ;
			case DIO_GroupB :
				switch (Led -> Led_Pin )
				{
				case Pin0 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin0 ,DIO_High); break ;
				case Pin1 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin1 ,DIO_High); break ;
				case Pin2 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin2 ,DIO_High); break ;
				case Pin3 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin3 ,DIO_High); break ;
				case Pin4 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin4 ,DIO_High); break ;
				case Pin5 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin5 ,DIO_High); break ;
				case Pin6 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin6 ,DIO_High); break ;
				case Pin7 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin7 ,DIO_High); break ;
				default   : return LED_Pin_Number_Error ;                       break ;
				}
				break ;
			case DIO_GroupC :
				switch (Led -> Led_Pin )
				{
				case Pin0 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin0 ,DIO_High); break ;
				case Pin1 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin1 ,DIO_High); break ;
				case Pin2 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin2 ,DIO_High); break ;
				case Pin3 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin3 ,DIO_High); break ;
				case Pin4 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin4 ,DIO_High); break ;
				case Pin5 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin5 ,DIO_High); break ;
				case Pin6 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin6 ,DIO_High); break ;
				case Pin7 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin7 ,DIO_High); break ;
				default   : return LED_Pin_Number_Error ;                       break ;
				}
				break ;
			case DIO_GroupD :
				switch (Led -> Led_Pin )
				{
				case Pin0 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin0 ,DIO_High); break ;
				case Pin1 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin1 ,DIO_High); break ;
				case Pin2 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin2 ,DIO_High); break ;
				case Pin3 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin3 ,DIO_High); break ;
				case Pin4 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin4 ,DIO_High); break ;
				case Pin5 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin5 ,DIO_High); break ;
				case Pin6 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin6 ,DIO_High); break ;
				case Pin7 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin7 ,DIO_High); break ;
				default   : return LED_Pin_Number_Error ;                       break ;
				}
				break ;
			default   : return LED_Group_error ;  break ;
				}

			}

			else if( Led -> ConnectionType == Source_Connection  )
			{
				switch (Led -> Led_Group )
				{

				case DIO_GroupA :
					switch (Led -> Led_Pin )
					{
					case Pin0 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin0 ,DIO_Low); break ;
					case Pin1 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin1 ,DIO_Low); break ;
					case Pin2 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin2 ,DIO_Low); break ;
					case Pin3 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin3 ,DIO_Low); break ;
					case Pin4 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin4 ,DIO_Low); break ;
					case Pin5 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin5 ,DIO_Low); break ;
					case Pin6 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin6 ,DIO_Low); break ;
					case Pin7 : DIO_ErrStateSetPinValue(PORTA_ITI ,Pin7 ,DIO_Low); break ;
					default   : return LED_Pin_Number_Error ;                       break ;
					}
					break ;
			case DIO_GroupB :
				switch (Led -> Led_Pin )
				{
				case Pin0 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin0 ,DIO_Low); break ;
				case Pin1 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin1 ,DIO_Low); break ;
				case Pin2 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin2 ,DIO_Low); break ;
				case Pin3 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin3 ,DIO_Low); break ;
				case Pin4 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin4 ,DIO_Low); break ;
				case Pin5 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin5 ,DIO_Low); break ;
				case Pin6 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin6 ,DIO_Low); break ;
				case Pin7 : DIO_ErrStateSetPinValue(PORTB_ITI ,Pin7 ,DIO_Low); break ;
				default   : return LED_Pin_Number_Error ;                       break ;
				}
				break ;
			case DIO_GroupC :
				switch (Led -> Led_Pin )
				{
				case Pin0 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin0 ,DIO_Low); break ;
				case Pin1 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin1 ,DIO_Low); break ;
				case Pin2 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin2 ,DIO_Low); break ;
				case Pin3 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin3 ,DIO_Low); break ;
				case Pin4 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin4 ,DIO_Low); break ;
				case Pin5 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin5 ,DIO_Low); break ;
				case Pin6 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin6 ,DIO_Low); break ;
				case Pin7 : DIO_ErrStateSetPinValue(PORTC_ITI ,Pin7 ,DIO_Low); break ;
				default   : return LED_Pin_Number_Error ;                       break ;
				}
				break ;
			case DIO_GroupD :
				switch (Led -> Led_Pin )
				{
				case Pin0 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin0 ,DIO_Low); break ;
				case Pin1 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin1 ,DIO_Low); break ;
				case Pin2 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin2 ,DIO_Low); break ;
				case Pin3 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin3 ,DIO_Low); break ;
				case Pin4 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin4 ,DIO_Low); break ;
				case Pin5 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin5 ,DIO_Low); break ;
				case Pin6 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin6 ,DIO_Low); break ;
				case Pin7 : DIO_ErrStateSetPinValue(PORTD_ITI ,Pin7 ,DIO_Low); break ;
				default   : return LED_Pin_Number_Error ;                       break ;
				}
				break ;

			default   : return LED_Group_error ;  break ;
				}
			}

			else { return LED_ConnectionTypeError ; }

		}

		else { return LED_AddressError ; }

		return  LED_NO_Error ;*/
