/*
 * EXTL_Configuration.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Marzok
 */

#ifndef TIMER0_CONFIGURATION_H_
#define TIMER0_CONFIGURATION_H_


#define Timer_Mode  CTC_Mode
/*
 * options :
 * 1- Normal_Mode
 * 2- CTC_Mode
 * 3- FASTPWM_Mode
 * 4- PWM_PhaseCorrect
 *
 */


#define Timer_PreScal  Prescaler_8
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

#define PreScal_Value  8

/* options :

	pre scaler = 8,
	pre scaler = 64,
	pre scaler = 256,
	pre scaler = 1024,

	*/


/*CTC OCR Value*/
#define CTC_NEWValue  250

/*CTC MODES*/
#define CTCs_Mode OC0_disconnected
/* options :
 *
	OC0_disconnected,
	Toggle_OC0,
	Clear_OC0,
	Set_OC0
	*/

/*FPWM Modes */

#define FPWM_Mode nin_Inverting

/* options :
 * OC0_FPWMdisconnected,
	Reserved,
	nin_Inverting,
	Inverting
*/

#define PhPWM_Mode Ph_Inverting

/* options :
    OC0_PhPWMdisconnected,
	Ph_Reserved,
	Ph_nin_Inverting,
	Ph_Inverting

	*/

#endif /* TIMER0_CONFIGURATION_H_ */
