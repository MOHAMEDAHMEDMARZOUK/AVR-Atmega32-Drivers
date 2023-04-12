/*
 * Stepper_Private.h
 *
 *  Created on: Mar 28, 2023
 *      Author: hisha
 */

#ifndef HAL_STEPPER_STEPPER_PRIVATE_H_
#define HAL_STEPPER_STEPPER_PRIVATE_H_



typedef enum
{
	FullStep=4,
	HalfStep=8
}Stepper_StepType ;


typedef enum
{
	CW,
	CCW
}Stepper_Direction ;

typedef enum
{
	Stepper_GND,
	Stepper_VCC
}Stepper_connection ;



typedef enum
{
	StepperNoError,
	StepperInitError,
	StepperDirectionpinError,
	StepperDirectionTypeError,
	StepperTypeStepError,
	Stepper_ConnectionError
}StErrState;


typedef struct
{
	DIO_GroupNumber Stper_BlueGroup;
	DIO_GroupNumber Stper_PinkGroup;
	DIO_GroupNumber Stper_YellowGroup;
	DIO_GroupNumber Stper_OrangeGroup;

	DIO_PinNumber   Stper_Blue;
	DIO_PinNumber   Stper_Pink;
	DIO_PinNumber   Stper_Yellow;
	DIO_PinNumber   Stper_Orange;

	Stepper_StepType   TypesOfStpe ;
	Stepper_Direction  Direction_type ;
	Stepper_connection Stp_connect  ;

}Stepper_info ;


#endif /* HAL_STEPPER_STEPPER_PRIVATE_H_ */
