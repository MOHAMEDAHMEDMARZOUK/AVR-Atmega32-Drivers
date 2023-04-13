/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK		    **************/
/********************		Layer: RTOS_Stack	    **************/
/********************		SWC: RTOS  			    **************/
/********************		Version: 1.00			**************/
/********************		Date: 13-4-2023			**************/
/*****************************************************************/
/*****************************************************************/


#include "../../4-Common/STD_TYPES.h"
#include "../02-TIMER0/TIMER0_Interface.h"
#include "../03-GIE/RTOS_GIE_Interface.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"

#define NUll  ((void *)0x00)

Task_t SystemTasks[TASK_NUM] = {{NUll}};

void RTOS_voidStart(void)
{
	TIMER0_voidSetCallBack(&voidSchedular);
	RTOS_GIE_ENABLE();
	TIMER0_voidTIMER0Init();
}

void RTOS_voidCreateTask(u8 copy_u8priority , u16 copy_u16preiodicity , void(*copy_pvTaskFunc)(void))
{
	SystemTasks[copy_u8priority].preiodicity = copy_u16preiodicity ;
	SystemTasks[copy_u8priority].TaskFunc    = copy_pvTaskFunc     ;
}

static void voidSchedular(void)
{

	static u16 loclal_u16tickcounter=0;
	u8 loclal_u8Taskcounter;

	loclal_u16tickcounter++;
	/*loop on all tasks to check their periodicity*/
	for(loclal_u8Taskcounter=0 ; loclal_u8Taskcounter<TASK_NUM ; loclal_u8Taskcounter++)
	{

		/*check the task suspended or not*/
		if(loclal_u16tickcounter % SystemTasks[loclal_u8Taskcounter].preiodicity == 0)
		{
			/*invoke the task function*/
			if(SystemTasks[loclal_u8Taskcounter].TaskFunc!= Null)
			{
				SystemTasks[loclal_u8Taskcounter].TaskFunc();
			}
			else
			{
				/*Do nothing*/
			}
		}
	}

}

