/*
 * EXTI_Register.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Marzok
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

#define TIMSK	*((volatile u8 *)0x59)
#define TCNT0	*((volatile u8 *)0x52)
#define TCCR0	*((volatile u8 *)0x53)
#define OCR0 	*((volatile u8 *)0x5C)

#define SREG_REG	*((volatile u8 *)0x5F)	/* Status Register */


#endif /* TIMER0_REGISTER_H_ */
