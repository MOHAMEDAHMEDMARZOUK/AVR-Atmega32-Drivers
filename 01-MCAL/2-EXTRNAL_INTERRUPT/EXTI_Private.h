/*
 * EXTL_Private.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Arabtech
 */

#ifndef MCAL_EXTRNAL_INTERRUPT_EXTI_PRIVATE_H_
#define MCAL_EXTRNAL_INTERRUPT_EXTI_PRIVATE_H_
#include "../1-DIO/DIO_Interface.h"


#define	INT1_GROUP  DIO_GroupD
#define	INT0_GROUP  DIO_GroupD
#define	INT2_GROUP  DIO_GroupB

#define	INT1_Pin    Pin3
#define	INT0_Pin    Pin2
#define	INT2_Pin    Pin2

typedef enum
{
	Low_Level,
	Rising_edge,
	Falling_edge,
	On_change
}Trigger_info;

#define EXTI_GIE_SREG	 7	/*Number of bit for enable and disable GIE Global Interrupt  */

typedef enum
{
	EXTI_INT1 =  7,    /*Number of bit for enable and disable PIE*/
	EXTI_INT0 =  6,   /*Number of bit for enable and disable PIE*/
	EXTI_INT2 =  5    /*Number of bit for enable and disable PIE*/
}EXTI_INT_Line;





#define EXTI_INT2_MCUCSR  6   /*select the bit trigger for INT2 rising-->bit=1 &falling---->bit=0 */

#define EXTI_INT0_MCUCR_1_   0     /*select the bit0 trigger for INT0*/
#define EXTI_INT0_MCUCR_2_   1     /*select the bit1 trigger for INT0*/
#define EXTI_INT1_MCUCR_1_   2     /*select the bit2 trigger for INT1*/
#define EXTI_INT1_MCUCR_2_   3     /*select the bit3 trigger for INT1*/



typedef enum
{
	EXTI_INT_Error,
	EXTI_No_Error,
	EXTI_Trigger_Error
}ErrstateEXTI;








#endif /* MCAL_EXTRNAL_INTERRUPT_EXTI_PRIVATE_H_ */
