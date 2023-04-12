/*
 * DIO_Private.h
 *
 *  Created on: Mar 23, 2023
 *      Author: 2022
 */

#ifndef MCAL_DIO_PRIVATE_H_
#define MCAL_DIO_PRIVATE_H_

typedef enum error
{
	NoError,
	GroupError,
	PinNumberError,
	DirectionError,
	DirectionRangError,
	AddressError,
	ValueRangError

}ErrState;

// NAME OF Group (A,B,C,D)

typedef enum
{
	DIO_GroupA,
	DIO_GroupB,
	DIO_GroupC,
	DIO_GroupD
}DIO_GroupNumber;

//NUM OF PIN (0 ~ 7 )

typedef enum
{
Pin0,
Pin1,
Pin2,
Pin3,
Pin4,
Pin5,
Pin6,
Pin7
}DIO_PinNumber;

//State OF DDR ( I/P = 0 ,, O/P = 1 )

typedef enum
{
	DIO_Input,
	DIO_Output
}DIO_DirectionState ;

//State OF PORT ( LOW = 0 ,, HIGH = 1 )

typedef enum
{
	DIO_Low,
	DIO_High
}DIO_ValueState ;

#endif /* 1_MCAL_1_DIO_DIO_PRIVATE_H_ */
