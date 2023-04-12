/*
 * Stepper_Interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: hisha
 */

#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_

#include "../../1-MCAL/1-DIO/DIO_Interface.h"

#include "Stepper_Private.h"
#include "Stepper_Config.h"

/*Select the Direction for Pin*/
StErrState  Stepper_StErrStateInit(Stepper_info * Motor1);

StErrState  Stepper_StErrStateControlMotorRotate(Stepper_info * Motor1 , u16 Copy_Degree);

static void  Stepper_void_VCC_CWFullSteps (Stepper_info * Motor1);
static void  Stepper_void_GND_CWFullSteps (Stepper_info * Motor1);


static void  Stepper_void_VCC_CWHalfSteps (Stepper_info * Motor1);
static void  Stepper_void_GND_CWHalfSteps (Stepper_info * Motor1);



static void  Stepper_void_VCC_CCWFullSteps(Stepper_info * Motor1);
static void  Stepper_void_GND_CCWFullSteps(Stepper_info * Motor1);


static void  Stepper_void_VCC_CCWHalfSteps(Stepper_info * Motor1);
static void  Stepper_void_GND_CCWHalfSteps(Stepper_info * Motor1);

#endif /* HAL_STEPPER_STEPPER_INTERFACE_H_ */
