/*
 * EXTL_Interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_EXTRNAL_INTERRUPT_EXTI_INTERFACE_H_
#define MCAL_EXTRNAL_INTERRUPT_EXTI_INTERFACE_H_
#include "EXTI_Private.h"
#include "EXTI_Configuration.h"
#include "EXTI_Register.h"
#include "../../4-Common/Bit_Math.h"
#include "../../4-Common/Definition.h"



ErrstateEXTI  EXTI_ErrstateEXTIInit(EXTI_info* info);

/*Enable and Disable GIE Global Interrupt  */

void EXTI_voidEnable_GIE_Interrupt(void);
void EXTI_voidDisable_GIE_Interrupt(void);


/*Enable and Disable PIE Global Interrupt  */

void EXTI_voidDisable_PIE_Interrupt(EXTI_info* info);
void EXTI_voidEnable_PIE_Interrupt(EXTI_info* info);


void EXTI_voidClearFlag (EXTI_info* info);
u8 EXTI_u8GetFlag(EXTI_info* info);

void EXTI_voidSetCallBack(void (*ISR_Function) (void), EXTI_info* info);

#endif /* MCAL_EXTRNAL_INTERRUPT_EXTI_INTERFACE_H_ */
