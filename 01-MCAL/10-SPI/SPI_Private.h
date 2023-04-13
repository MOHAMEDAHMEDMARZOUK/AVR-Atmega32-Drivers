/*
 * UART_Private.h
 *
 *  Created on: Apr 7, 2023
 *      Author: 2022
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define SPCR    *((volatile u8*)0x2D)
#define SPSR    *((volatile u8*)0x2E)
#define SPDR    *((volatile u8*)0x2F)

#define SPDR_REG     (*(volatile u8*)0x2F)
#define SPSR_REG     (*(volatile u8*)0x2E)
#define SPCR_REG     (*(volatile u8*)0x2D)

#define SPCR_Value  0b011011;








#endif /* 1_MCAL_UART_UART_PRIVATE_H_ */
