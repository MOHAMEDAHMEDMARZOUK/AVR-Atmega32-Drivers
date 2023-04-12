/*
 * WDT_Private.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_TIMER_WDT_WDT_PRIVATE_H_
#define MCAL_TIMER_WDT_WDT_PRIVATE_H_

#define WDTCR *((volatile u8*)0x41) //Address of the WDTCR Reg.
#define WDTCR_EN_B3      3             //pin 3 set to enable the WDT
#define WDTCR_DisEN_B4   4             //Pin 4 used with pin 3 to Disable the WDT Set the two pin


#define Enable_WDT       0b1000        //set pin 3 to enable the WDT
#define Disable_WDT      0b00011000    //set pin 3,4 to Disable WDT


typedef enum
{
	IDLE,
	BUSY
}WDT_State;

#endif /* MCAL_TIMER_WDT_WDT_PRIVATE_H_ */
