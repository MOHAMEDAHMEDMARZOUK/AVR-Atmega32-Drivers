/*
 * TIMER1_Program.c
 *
 *  Created on: Apr 5, 2023
 *      Author: Arabtech
 */

#include "../../4-Common/Bit_Math.h"
#include "../../4-Common/STD_types.h"
#include "TIMER1_Private.h"
#include "TIMER1_interface.h"
#include "TIMER1_Config.h"
#include "../1-DIO/DIO_Interface.h"

void  TIMER1_voidTIMER1Init(void)
{
	/*enable global interrupt*/
	Set_Bit(SREG_REG,GIE_EN_B7);

	/*initialize FPWM use ICR1*/
	Clr_Bit(TCCR1A,TCCR1A_Mode_B0);
	Set_Bit(TCCR1A,TCCR1A_Mode_B1);
	Set_Bit(TCCR1B,TCCR1B_Mode_B3);
	Set_Bit(TCCR1B,TCCR1B_Mode_B4);

	/*select channelA FPWM*/
	Clr_Bit(TCCR1A,TCCR1A_COM1A0);
	Set_Bit(TCCR1A,TCCR1A_COM1A1);

	/*Clear the Prescaler bits in TCCR1B register*/
	TCCR1B &= 0b11111000;
	/*Set the required Prescaler into the TCCR1B bits*/
	TCCR1B |= prescaler1_8;

}

void TIMER1_voidTIMER1Set_ICR1(u32 copyu8value)
{
	ICR1=copyu8value;
}

void TIMER1_voidTIMER1COMPA_OCR1A(u32 copyu8value)
{
	OCR1A=copyu8value ;
}
