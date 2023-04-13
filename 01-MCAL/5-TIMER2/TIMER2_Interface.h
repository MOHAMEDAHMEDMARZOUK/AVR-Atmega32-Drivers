/*
 * EXTL_Interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Marzok
 */

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


#include "TIMER2_Private.h"
#include "TIMER2_Register.h"
#include "TIMER2_Configuration.h"
#include "../../4-Common/BIT_MATH.h"
#include "../1-DIO/DIO_Interface.h"

void  TIMER2_voidTIMER2Init(void);

void  TIMER2_voidNormal_SETPRELOAD_S(f64 Desired , u32 *counter , u32 *Pre );

void  TIMER2_voidCTC_SETNEWOVERFLOW_S(f64 Desired , u32 *counter  );

void  TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(u8 OCR_Value );

void  TIMER2_voidPhasePWM_SETNEWOVERFLOW_S(u8 OCR_Value );

void TIMER2_voidSetCallBack(void (*ISR_Function) (void));


#endif /* TIMER2_INTERFACE_H_ */
