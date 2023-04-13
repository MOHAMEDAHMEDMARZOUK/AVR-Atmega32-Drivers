/*
 * EXTL_Private.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Marzok
 */

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

typedef enum
{
	Normal_Mode2,
	CTC_Mode2 ,
	FASTPWM_Mode2,
	PWM_PhaseCorrect2

}Timer_Modes2;

typedef enum
{
	OC2_disconnected,
	Toggle_OC2,
	Clear_OC2,
	Set_OC2

}CTC_Modes2;

typedef enum
{
	OC2_FPWMdisconnected,
	Reserved2,
	nin_Inverting2,
	Inverting2

}FPWM_Modes2;

typedef enum
{
	OC2_PhPWMdisconnected,
	Ph_Reserved2,
	Ph_nin_Inverting2,
	Ph_Inverting2

}PhPWM_Modes2;



typedef enum
{
	No_clocksource2,
	No_prescaler2,
	prescaler2_8,
	prescaler2_32,
	prescaler2_64,
	prescaler2_128,
	prescaler2_256,
	prescaler2_1024

}Timer_PreScaler2;

#define F_CPU 8000000



#define TCCR2_CTC_EN       7

#define TCCR2_MODE_B1      6  //MODE (NORMAL / CTC /F_PWM / PH_PWM )
#define TCCR2_MODE_B2      3  //MODE (NORMAL / CTC /F_PWM / PH_PWM )

#define TCCR2_CTC_MODE_B1   4
#define TCCR2_CTC_MODE_B2   5

#define TCCR2_F_PWM_MODE_B1  4
#define TCCR2_F_PWM_MODE_B2  5

#define TCCR2_PH_PWM_MODE_B1  4
#define TCCR2_PH_PWM_MODE_B2  5

#define TCCR2_PreScaler_B1  0
#define TCCR2_PreScaler_B2  1
#define TCCR2_PreScaler_B3  2

#define TIMSK_OverFlow_PIE  0        //  ENABLE OverFlow INTERRUPT BY 1

#define TIMSK_OutputCompare_PIE  1  //  ENABLE OutputCompare INTERRUPT BY 1


#endif /* TIMER0_PRIVATE_H_ */
