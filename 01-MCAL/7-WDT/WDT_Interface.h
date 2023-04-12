/*
 * WDT_Interface.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_TIMER_WDT_WDT_INTERFACE_H_
#define MCAL_TIMER_WDT_WDT_INTERFACE_H_
#include "../../4-Common/STD_TYPES.h"

void  WDT_voidWDTEnable(u8 copyu8prescaler);
void  WDT_voidWDTDisable(void);
void WDT_voidRefresh (void);

#define WDT_16_3_MS  0
#define WDT_32_5_MS  1
#define WDT_65_MS    2
#define WDT_130_MS   3
#define WDT_260_MS   4
#define WDT_520_3MS  5
#define WDT_1000_3MS 6
#define WDT_2100_MS  7

#endif /* MCAL_TIMER_WDT_WDT_INTERFACE_H_ */
