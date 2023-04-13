/*
 * UART_interface.h
 *
 *  Created on: Apr 7, 2023
 *      Author: 2022
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#include "../../4-Common/STD_TYPES.h"

void SPI_voidInit_Master(void);
void SPI_voidInit_Slave(void);

u8 SPI_u8SendRecieve_Slave(u8 Data);

u8 SPI_voidRead_Write_Master(u8  copy_u8_result);


#endif /* 1_MCAL_UART_UART_INTERFACE_H_ */
