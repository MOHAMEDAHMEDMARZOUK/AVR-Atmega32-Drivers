/*
 * DIO_Interface.h
 *
 *  Created on: Mar 23, 2023
 *      Author: 2022
 */

#ifndef MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_INTERFACE_H_

#include "../../4-Common/STD_TYPES.h"
#include "DIO_Private.h"

#define Null (void *)0x00

ErrState  DIO_ErrStateSetPinDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState);
ErrState  DIO_ErrStateSetPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_ValueState Copy_ValueState);
ErrState  DIO_ErrStateReadPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,u8 *Result);


ErrState  DIO_ErrStateSetGroupDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_DirectionState Copy_DirectionState);
ErrState  DIO_ErrStateSetGroupValue(DIO_GroupNumber Copy_GroupNumber ,DIO_ValueState Copy_ValueState);
ErrState  DIO_ErrStateReadGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 *Result);




#endif /* 1_MCAL_1_DIO_DIO_INTERFACE_H_ */

