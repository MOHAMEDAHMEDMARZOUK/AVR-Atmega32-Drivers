/*
 * TIMER_Private.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_TIMER_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER_TIMER1_TIMER1_PRIVATE_H_

/* Status Register for Global Interrupt Enable */
#define SREG_REG	*((volatile u8 *)0x5F)	//Address of the status Reg.
#define GIE_EN_B7    7                      // bit 7 in SREG_REG used to enable the global interrupt

/*Control Register 1A*/
#define TCCR1A *((volatile u8 *)0x4F)       //Address of the TCCR1A Reg.
#define TCCR1A_COM1B0    4                  /* this pins use to chooce the compare output mode as normal or (non-inverting mode)or (inverting mode)  */
#define TCCR1A_COM1B1    5
#define TCCR1A_COM1A0    6
#define TCCR1A_COM1A1    7
#define TCCR1A_Mode_B0   0                  //this two pins used with another two pin in TCCRB to chooce the mode of operation
#define TCCR1A_Mode_B1   1

/*Control Register 1B*/
#define TCCR1B *((volatile u8 *)0x4E)       //Address of the TCCR1B Reg.
#define TCCR1B_Mode_B3   3                  //this two pins used with another two pin in TCCRA to chooce the mode of operation
#define TCCR1B_Mode_B4   4

typedef enum                                //this enum used to create the three pins of prescaler in TCCRB
{
	No_clocksource1,
	No_prescaler1,
	prescaler1_8,
	prescaler1_64,
	prescaler1_256,
	prescaler1_1024,
	Ex_Falling_edge_T1,     //POTRB BIN 1
	Ex_Risiing_edge_T1      //POTRB BIN 1

}Timer1_PreScaler;

/*Preload  Register*/
#define TCNT1    *((volatile u16 *)0x4C)      //TCNT1 REG used to get the preload value if used normal mode and casting by u16 to read low and high reg

#define OCR1A    *((volatile u16 *)0x4A)      //OCR1A REG used to get the compare match value  and casting by u16 to read low and high reg

#define OCR1B    *((volatile u16 *)0x48)      //OCR1B REG used to get the compare match value  and casting by u16 to read low and high reg

#define ICR1    *((volatile u16 *)0x46)       //ICR1 REG used to get the New value of overflow  and casting by u16 to read low and high reg

#define TIMSK    *((volatile u8 *)0x59)       //PIE REG
#define TIMSK_Over_INT_B2      2              //pin to enable the over flow interrupt
#define TIMSK_Compare_INT_B2   3              //pin to enable the compare match interrupt

typedef enum
{
	Channel_A,
	Channel_B
}Channel_Modes;

typedef enum
{
	OC1_disconnected,
	Toggle_COM_OC1,
	Clear_COM_OC1,
	Set_COM_OC1

}NON_PWM_Modes1;

typedef enum
{
	OC1_FPWMdisconnected,
	Reserved1,
	non_Inverting1,
	Inverting1

}FPWM_Modes1;

typedef enum
{
	OC1_PhPWMdisconnected,
	Ph_Reserved1,
	Ph_non_Inverting1,
	Ph_Inverting1

}PhPWM_Modes1;






#endif /* MCAL_TIMER_TIMER1_TIMER1_PRIVATE_H_ */
