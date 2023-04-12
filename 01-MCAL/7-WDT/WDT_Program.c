/*
 * WDT_Program.c
 *
 *  Created on: Apr 6, 2023
 *      Author: Arabtech
 */

#include "WDT_Config.h"
#include "WDT_Interface.h"
#include "WDT_Private.h"
#include "../../4-Common/Bit_Math.h"


//#include "../../DIO/DIO_Interface.h"

u8 WDTState;

#if WDTState==IDLE

void  WDT_voidWDTEnable(u8 copyu8prescaler)
{
	/*Enable the WDT*/
	WDTCR=Disable_WDT;
	WDTCR=0;

	WDTCR=(Enable_WDT|copyu8prescaler);
}

void  WDT_voidWDTDisable(void)
{
	/*Disable the WDT*/
	WDTCR=Disable_WDT;
	WDTCR=0;
}

void WDT_voidRefresh (void)
{
	asm("WDR");  //assembly instruction to refresh the WDT
}

#endif
