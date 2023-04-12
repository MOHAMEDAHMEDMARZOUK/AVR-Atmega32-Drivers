/*
 * TIMER_interface.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_

void  TIMER1_voidTIMER1Init(void);

void TIMER1_voidTIMER1Set_ICR1(u32 copyu8value);

void TIMER1_voidTIMER1COMPA_OCR1A(u32 copyu8value);

#endif /* MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_ */
