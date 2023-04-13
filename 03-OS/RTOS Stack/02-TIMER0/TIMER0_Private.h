
/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK		    **************/
/********************		Layer: RTOS_Stack	    **************/
/********************		SWC: TIMER0				**************/
/********************		Version: 1.00			**************/
/********************		Date: 13-4-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

typedef enum
{
	RTOS_Normal_Mode,
	RTOS_CTC_Mode


}RTOS_Timer_Modes;

typedef enum
{
	RTOS_OC0_disconnected

}RTOS_CTC_Modes;





typedef enum
{
	RTOS_No_clocksource,
	RTOS_No_prescaler,
	RTOS_Prescaler_8,
	RTOS_Prescaler_64,
	RTOS_prescaler_256,
	RTOS_prescaler_1024,

}RTOS_Timer_PreScaler;

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
