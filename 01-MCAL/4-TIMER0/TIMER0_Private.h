/*
 * EXTL_Private.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Marzok
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

typedef enum
{
	Normal_Mode,
	CTC_Mode ,
	FASTPWM_Mode,
	PWM_PhaseCorrect

}Timer_Modes;

typedef enum
{
	OC0_disconnected,
	Toggle_OC0,
	Clear_OC0,
	Set_OC0

}CTC_Modes;

typedef enum
{
	OC0_FPWMdisconnected,
	Reserved,
	nin_Inverting,
	Inverting

}FPWM_Modes;

typedef enum
{
	OC0_PhPWMdisconnected,
	Ph_Reserved,
	Ph_nin_Inverting,
	Ph_Inverting

}PhPWM_Modes;



typedef enum
{
	No_clocksource,
	No_prescaler,
	Prescaler_8,
	prescaler_64,
	prescaler_256,
	prescaler_1024,
	Ex_Falling_edge_TO,     //POTRB BIN 0
	Ex_Risiing_edge_TO      //POTRB BIN 0

}Timer_PreScaler;

#define F_CPU 8000000



#define TCCR0_CTC_EN       7

#define TCCR0_MODE_B1      6  //MODE (NORMAL / CTC /F_PWM / PH_PWM )
#define TCCR0_MODE_B2      3  //MODE (NORMAL / CTC /F_PWM / PH_PWM )

#define TCCR0_CTC_MODE_B1   4
#define TCCR0_CTC_MODE_B2   5

#define TCCR0_F_PWM_MODE_B1  4
#define TCCR0_F_PWM_MODE_B2  5

#define TCCR0_PH_PWM_MODE_B1  4
#define TCCR0_PH_PWM_MODE_B2  5

#define TCCR0_PreScaler_B1  0
#define TCCR0_PreScaler_B2  1
#define TCCR0_PreScaler_B3  2

#define TIMSK_OverFlow_PIE  0        //  ENABLE OverFlow INTERRUPT BY 1

#define TIMSK_OutputCompare_PIE  1  //  ENABLE OutputCompare INTERRUPT BY 1


#endif /* TIMER0_PRIVATE_H_ */
