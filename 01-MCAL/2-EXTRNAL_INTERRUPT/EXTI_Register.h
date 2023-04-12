/*
 * EXTI_Register.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_EXTRNAL_INTERRUPT_EXTI_REGISTER_H_
#define MCAL_EXTRNAL_INTERRUPT_EXTI_REGISTER_H_

#define MCUCR_REG   *((volatile u8 *)0x55)
#define MCUCSR_REG  *((volatile u8 *)0x54)
#define GICR_REG    *((volatile u8 *)0x5B)
#define GIFR_REG    *((volatile u8 *)0x5A)
#define SREG_REG	*((volatile u8 *)0x5F)	/* Status Register */

#endif /* MCAL_EXTRNAL_INTERRUPT_EXTI_REGISTER_H_ */
