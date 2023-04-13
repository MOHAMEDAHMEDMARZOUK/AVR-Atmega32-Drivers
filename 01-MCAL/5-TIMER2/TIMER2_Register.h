/*
 * EXTI_Register.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Marzok
 */

#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_

#define TIMSK	*((volatile u8 *)0x59)
#define TCNT2	*((volatile u8 *)0x44)  //NORAML MODE
#define TCCR2	*((volatile u8 *)0x45)
#define OCR2 	*((volatile u8 *)0x43)  //CTC MODE

#define SREG_REG	*((volatile u8 *)0x5F)	/* Status Register */


#endif /* TIMER2_REGISTER_H_ */
