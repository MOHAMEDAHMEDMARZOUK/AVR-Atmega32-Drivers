/*
 * EXTL_Interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Marzok
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


#include "TIMER0_Private.h"
#include "TIMER0_Register.h"
#include "TIMER0_Configuration.h"
#include "../../4-Common/BIT_MATH.h"
#include "../1-DIO/DIO_Interface.h"

void  TIMER0_voidTIMER0Init(void);

void  TIMER0_voidNormal_SETPRELOAD_S(f64 Desired , u32 *counter , u32 *Pre );

void  TIMER0_voidCTC_SETNEWOVERFLOW_S(f64 Desired , u32 *counter  );

void  TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(u8 OCR_Value );

void  TIMER0_voidPhasePWM_SETNEWOVERFLOW_S(u8 OCR_Value );

void TIMER0_voidSetCallBack(void (*ISR_Function) (void));



#endif /* TIMER0_INTERFACE_H_ */
