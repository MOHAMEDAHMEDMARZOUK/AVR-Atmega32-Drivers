/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK		    **************/
/********************		Layer: RTOS_Stack	    **************/
/********************		SWC: RTOS_GIE			**************/
/********************		Version: 1.00			**************/
/********************		Date: 13-4-2023			**************/
/*****************************************************************/
/*****************************************************************/
#include "RTOS_GIE_Register.h"
#include "RTOS_GIE_Interface.h"
#include "../../4-Common/BIT_MATH.h"
//#include "../../4-Common/STD_TYPES.h""
#include"../../1-MCAL/1-DIO/DIO_Interface.h"




void RTOS_GIE_ENABLE(void)
{
	SET_BIT(SREG,7);
}
void RTOS_GIE_DISABLE(void)
{
	CLR_BIT(SREG,7);
}
