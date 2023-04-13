/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK		    **************/
/********************		Layer: RTOS_Stack	    **************/
/********************		SWC: RTOS  			    **************/
/********************		Version: 1.00			**************/
/********************		Date: 13-4-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart(void);

void RTOS_voidCreateTask(u8 copy_u8priority , u16 copy_u16preiodicity , void(*copy_pvTaskFunc)(void));

#endif