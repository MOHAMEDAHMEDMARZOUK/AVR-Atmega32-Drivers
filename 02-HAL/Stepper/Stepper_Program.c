/*
 * Stepper_Program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: hisha
 */

#include <util/delay.h>
#include "Stepper_Interface.h"

StErrState  Stepper_StErrStateInit(Stepper_info * Motor1)
{
	u8 Res ;
	u8 flag = 0 ;
	Res = DIO_ErrStateSetPinDirection(Motor1 ->Stper_BlueGroup  , Motor1 ->Stper_Blue , DIO_Output );
	if (Res != NoError) { flag = 1 ; }
	Res = DIO_ErrStateSetPinDirection(Motor1 ->Stper_PinkGroup  , Motor1 ->Stper_Pink , DIO_Output );
	if (Res != NoError) { flag = 1 ; }
	Res = DIO_ErrStateSetPinDirection(Motor1 ->Stper_YellowGroup, Motor1 ->Stper_Yellow , DIO_Output );
	if (Res != NoError) { flag = 1 ; }
	Res = DIO_ErrStateSetPinDirection(Motor1 ->Stper_OrangeGroup, Motor1 ->Stper_Orange , DIO_Output );
	if (Res != NoError) { flag = 1 ; }

	if (flag == 1 )
	{
		return StepperInitError ;
	}

	return StepperNoError ;
}



StErrState  Stepper_StErrStateControlMotorRotate(Stepper_info * Motor1 , u16 Copy_Degree)
{
	u16 Local_NumberofSteps ;
	u16 Local_NumberofIterations ;
	u16 Local_counter ;
	if (Motor1 -> Stp_connect == Stepper_VCC)
	{
		if(Motor1->Direction_type == CW)
		{

			if(Motor1->TypesOfStpe  == FullStep )
			{
				Local_NumberofSteps = ( Copy_Degree / DegreeforfullStep ) +1 ;
				Local_NumberofIterations = Local_NumberofSteps / FullStep ;

				for( Local_counter = 0 ; Local_counter < Local_NumberofIterations ; Local_counter++ )
				{
					Stepper_void_VCC_CWFullSteps(Motor1);
				}

			}
			else if(Motor1->TypesOfStpe  == HalfStep )
			{
				Local_NumberofSteps = ( Copy_Degree / DegreeforfullStep ) +1 ;
				Local_NumberofIterations = Local_NumberofSteps / HalfStep ;

				for( Local_counter = 0 ; Local_counter < Local_NumberofIterations ; Local_counter++ )
				{
					Stepper_void_VCC_CWHalfSteps(Motor1);

				}

			}
			else
			{
				return StepperTypeStepError ;
			}


		}
		else if (Motor1->Direction_type == CCW)
		{
			if(Motor1->TypesOfStpe  == FullStep )
			{
				Local_NumberofSteps = ( Copy_Degree / DegreeforfullStep ) +1 ;
				Local_NumberofIterations = Local_NumberofSteps / FullStep ;
				for( Local_counter = 0 ; Local_counter < Local_NumberofIterations ; Local_counter++ )
				{
					Stepper_void_VCC_CCWFullSteps(Motor1);
				}

			}
			else if(Motor1->TypesOfStpe  == HalfStep )
			{
				Local_NumberofSteps = ( Copy_Degree / DegreeforfullStep ) +1 ;
				Local_NumberofIterations = Local_NumberofSteps / HalfStep ;

				for( Local_counter = 0 ; Local_counter < Local_NumberofIterations ; Local_counter++ )
				{
					Stepper_void_VCC_CCWHalfSteps(Motor1);
				}


			}
			else
			{
				return StepperTypeStepError ;
			}

		}

		else
		{
			return StepperDirectionTypeError ;
		}


	}
	else if (Motor1 -> Stp_connect == Stepper_GND)
	{
		if(Motor1->Direction_type == CW)
		{
			if(Motor1->TypesOfStpe  == FullStep )
			{
				Local_NumberofSteps = ( Copy_Degree / DegreeforfullStep ) +1 ;
				Local_NumberofIterations = Local_NumberofSteps / FullStep ;

				for( Local_counter = 0 ; Local_counter < Local_NumberofIterations ; Local_counter++ )
				{
					Stepper_void_GND_CWFullSteps(Motor1);
				}

			}
			else if(Motor1->TypesOfStpe  == HalfStep )
			{
				Local_NumberofSteps = ( Copy_Degree / DegreeforfullStep ) +1 ;
				Local_NumberofIterations = Local_NumberofSteps / HalfStep ;

				for( Local_counter = 0 ; Local_counter < Local_NumberofIterations ; Local_counter++ )
				{
					Stepper_void_GND_CWHalfSteps(Motor1);
				}

			}
			else
			{
				return StepperTypeStepError ;
			}



		}
		else if (Motor1->Direction_type == CCW)
		{
			if(Motor1->TypesOfStpe  == FullStep )
			{
				Local_NumberofSteps = ( Copy_Degree / DegreeforfullStep ) +1 ;
				Local_NumberofIterations = Local_NumberofSteps / FullStep ;

				for( Local_counter = 0 ; Local_counter < Local_NumberofIterations ; Local_counter++ )
				{
					Stepper_void_GND_CCWFullSteps(Motor1);
				}

			}
			else if(Motor1->TypesOfStpe  == HalfStep )
			{
				Local_NumberofSteps = ( Copy_Degree / DegreeforfullStep ) +1 ;
				Local_NumberofIterations = Local_NumberofSteps / HalfStep ;

				for( Local_counter = 0 ; Local_counter < Local_NumberofIterations ; Local_counter++ )
				{
					Stepper_void_GND_CCWHalfSteps(Motor1);
				}

			}
			else
			{
				return StepperTypeStepError ;
			}

		}

		else
		{
			return StepperDirectionTypeError ;
		}

	}
	else
	{
		return Stepper_ConnectionError ;
	}

	return StepperNoError ;
}


static void  Stepper_void_VCC_CWFullSteps (Stepper_info * Motor1)
{
	/*the Blue is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);

}

static void  Stepper_void_GND_CWFullSteps (Stepper_info * Motor1)
{
	/*the Blue is High and all pin is Low */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Pink is High and all pin is Low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Yellow is High and all pin is Low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Orange is High and all pin is Low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);

}


static void  Stepper_void_VCC_CWHalfSteps (Stepper_info * Motor1)
{
	/*the Blue is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);

	/*the Blue & Pink is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Pink & Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Yellow & Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Orange & Blue is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);


}

static void  Stepper_void_GND_CWHalfSteps (Stepper_info * Motor1)
{
    /*the Blue is high  and all pin is low */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);

	/*the Blue & Pink is high  and all pin is low */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Pink is high  and all pin is low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Pink & Yellow is high  and all pin is low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Yellow is high  and all pin is low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(2);
	/*the Yellow & Orange is high  and all pin is low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Orange is high  and all pin is low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
	/*the Orange & Blue is high  and all pin is low*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	_delay_ms(2);
}



static void  Stepper_void_VCC_CCWFullSteps(Stepper_info * Motor1)
{
	/*the Blue is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Orange is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Yellow is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Pink is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
}

static void  Stepper_void_GND_CCWFullSteps(Stepper_info * Motor1)
{
	/*the Blue is high  and all pin is Low */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Orange is high  and all pin is Low */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Yellow is high  and all pin is Low */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Pink is high  and all pin is Low */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
}



static void  Stepper_void_VCC_CCWHalfSteps(Stepper_info * Motor1)
{
	/*the Blue is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);

	/*the Blue & Orange is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Orange & Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Yellow & Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Pink & Blue is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
}

static void  Stepper_void_GND_CCWHalfSteps(Stepper_info * Motor1)
{
	 /*the Blue is low  and all pin is High */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);

	/*the Blue & Pink is low  and all pin is High */
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Pink is low  and all pin is High*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Pink & Yellow is low  and all pin is High*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Yellow is low  and all pin is High*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_Low);
	_delay_ms(2);
	/*the Yellow & Orange is low  and all pin is High*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Orange is low  and all pin is High*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
	/*the Orange & Blue is low  and all pin is High*/
	DIO_ErrStateSetPinValue(Motor1->Stper_BlueGroup,Motor1->Stper_Blue    , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_OrangeGroup,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_YellowGroup,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_PinkGroup,Motor1->Stper_Pink    , DIO_High);
	_delay_ms(2);
}

