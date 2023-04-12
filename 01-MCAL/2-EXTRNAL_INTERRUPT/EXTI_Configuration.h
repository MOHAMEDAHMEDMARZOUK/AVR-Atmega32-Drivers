/*
 * EXTL_Configuration.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_EXTRNAL_INTERRUPT_EXTI_CONFIGURATION_H_
#define MCAL_EXTRNAL_INTERRUPT_EXTI_CONFIGURATION_H_
#include "EXTI_Private.h"

typedef struct
{
	EXTI_INT_Line  EXTI_INT ;
	Trigger_info   EXTI_SENSE_MODE;
	u8             Number_of_INT;
}EXTI_info;



#endif /* MCAL_EXTRNAL_INTERRUPT_EXTI_CONFIGURATION_H_ */
