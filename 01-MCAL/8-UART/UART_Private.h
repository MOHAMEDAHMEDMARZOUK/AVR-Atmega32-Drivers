/*
 * UART_Private.h
 *
 *  Created on: Apr 7, 2023
 *      Author: 2022
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define UDR    *((volatile u8*)0x2C)
#define UCSRA  *((volatile u8*)0x2B)
#define UCSRB  *((volatile u8*)0x2A)
#define UCSRC  *((volatile u8*)0x40)
#define UBRRH  *((volatile u8*)0x40)
#define UBRRL  *((volatile u8*)0x29)

#define UCSRB_Value  0b00011000     /*  Bit 4: Receiver Enable , Bit 3: Transmitter Enable  */
                                    /*  Bit 2:1 – UCSZ1:0: Character Size */

#define UCSRC_Value  0b10000110     /*  Bit 7 – URSEL:Reg Select , Bit 6: USART Mode ASYN*/
                                    /*  Bit 5:4: Parity Mode Disable , Bit 3: Stop one Bit Select*/
                                    /*  Bit 2:1: Character Size 8 Bit*/

#define UBRRL_Value     51          /*  Baud Rate ( 9600 )*/
#define UBRRH_Value     0

#define UCSRA_Receive_Complete   7
#define UCSRA_Transmit_Complete  6
#define UCSRA_Data_RegEmpty      5

#endif /* 1_MCAL_UART_UART_PRIVATE_H_ */
