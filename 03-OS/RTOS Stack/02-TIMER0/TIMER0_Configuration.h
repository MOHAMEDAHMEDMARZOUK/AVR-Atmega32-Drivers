
/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK		    **************/
/********************		Layer: RTOS_Stack	    **************/
/********************		SWC: TIMER0				**************/
/********************		Version: 1.00			**************/
/********************		Date: 13-4-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER0_CONFIGURATION_H_
#define TIMER0_CONFIGURATION_H_


#define RTOS_Timer_Mode  RTOS_CTC_Mode
/*
 * options :
 * 1- Normal_Mode
 * 2- CTC_Mode
 * 3- FASTPWM_Mode
 * 4- PWM_PhaseCorrect
 *
 */


#define RTOS_Timer_PreScal  RTOS_Prescaler_64
/*
 * options :
 *
 *  No_clocksource,
	No_prescaler,
	Prescaler_8,
	prescaler_64,
	prescaler_256,
	prescaler_1024,
	Ex_Falling_edge_TO,
	Ex_Risiing_edge_TO

	*/

#define RTOS_PreScal_Value  64

/* options :

	pre scaler = 8,
	pre scaler = 64,
	pre scaler = 256,
	pre scaler = 1024,

	*/


/*CTC OCR Value*/
#define RTOS_CTC_NEWValue  125

/*CTC MODES*/
#define RTOS_CTCs_Mode RTOS_OC0_disconnected
/* options :
 *
	OC0_disconnected,
	Toggle_OC0,
	Clear_OC0,
	Set_OC0
	*/



#endif /* TIMER0_CONFIGURATION_H_ */
