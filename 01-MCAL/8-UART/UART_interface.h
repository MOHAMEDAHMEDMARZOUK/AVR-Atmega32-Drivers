/*
 * UART_interface.h
 *
 *  Created on: Apr 7, 2023
 *      Author: 2022
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#include "../../4-Common/STD_TYPES.h"

void UART_voidInit(void);
void UART_voidRead (u16 *copy_u16_result);
void UART_voidWrite(u16  copy_u16_result);

#endif /* 1_MCAL_UART_UART_INTERFACE_H_ */
