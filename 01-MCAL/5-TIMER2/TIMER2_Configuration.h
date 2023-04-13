/*
 * EXTL_Configuration.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Marzok
 */

#ifndef TIMER2_CONFIGURATION_H_
#define TIMER2_CONFIGURATION_H_


#define Timer_Mode2  FASTPWM_Mode2
/*
 * options :
 * 1- Normal_Mode2
 * 2- CTC_Mode2
 * 3- FASTPWM_Mode2
 * 4- PWM_PhaseCorrect2
 *
 */


#define Timer_PreScal2  No_prescaler2
/*
 * options :
 *
 *  No_clocksource2,
	No_prescaler2,
	prescaler2_8,
	prescaler2_32,
	prescaler2_64,
	prescaler2_128,
	prescaler2_256,
	prescaler2_1024

	*/

#define PreScal_Value2  8

/* options :

	pre scaler = 8,
	pre scaler = 32,
	pre scaler = 64,
	pre scaler = 128,
	pre scaler = 256,
	pre scaler = 1024,

	*/


/*CTC OCR Value*/
#define CTC_NEWValue2  250

/*CTC MODES*/
#define CTCs_Mode2 OC2_disconnected
/* options :
 *
	OC2_disconnected,
	Toggle_OC2,
	Clear_OC2,
	Set_OC2
	*/

/*FPWM Modes */

#define FPWM_Mode2 Inverting2

/* options :
 * OC2_FPWMdisconnected,
	Reserved2,
	nin_Inverting2,
	Inverting2
*/

#define PhPWM_Mode2 Ph_Inverting2

/* options :
    OC2_PhPWMdisconnected,
	Ph_Reserved2,
	Ph_nin_Inverting2,
	Ph_Inverting2

	*/

#endif /* TIMER2_CONFIGURATION_H_ */
