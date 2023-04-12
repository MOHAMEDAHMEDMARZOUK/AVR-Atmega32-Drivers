/*
 * TIMER1_Config.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_TIMER_TIMER1_TIMER1_CONFIG_H_
#define MCAL_TIMER_TIMER1_TIMER1_CONFIG_H_

/*select the prescaler*/
#define Timer1_PreScal  prescaler1_256
/*
 * options :
 *
 *  No_clocksource1,
	No_prescaler1,
	prescaler1_8,
	prescaler1_64,
	prescaler1_256,
	prescaler1_1024,
	Ex_Falling_edge_T1,
	Ex_Risiing_edge_T1

	*/


/*select the prescaler value*/
#define PreScal_Value1  256
/* options :

	prescaler = 8,
	prescaler = 64,
	prescaler = 256,
	prescaler = 1024,

	*/


/*select the chanel*/
#define Channel   Channel_A
/*
 * options:
 *   Channel_A
     Channel_B
 * */


/*select normal or ctc mode */
#define NONPWM_Mode1 OC1_disconnected
/* options :
 *
	OC1_disconnected,
	Toggle_OC1,
	Clear_OC1,
	Set_OC1
	*/



/*FPWM Modes */
#define FPWMMode1 non_Inverting1
/* options :
 * OC1_FPWMdisconnected,
	Reserved1,
	non_Inverting1,
	Inverting1
*/


/*PhPWM Modes */
#define PhPWMMode1 Ph_Inverting
/* options :
    OC1_PhPWMdisconnected,
	Ph_Reserved1,
	Ph_non_Inverting1,
	Ph_Inverting1

	*/










#endif /* MCAL_TIMER_TIMER1_TIMER1_CONFIG_H_ */
