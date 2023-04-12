/*
 * EXTL_Program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: marzok
 */
#include "EXTI_Interface.h"

void (*EXTI_CallBack[3]) (void) = { Null } ;

ErrstateEXTI  EXTI_ErrstateEXTIInit(EXTI_info* info)
{
#ifdef info -> EXTI_INT
/************************************************************/
#if info->EXTI_INT==EXTI_INT0
#if info->EXTI_SENSE_MODE==Low_Level
	Clr_Bit(MCUCR_REG,EXTI_INT0_MCUCR_1_);
	Clr_Bit(MCUCR_REG,EXTI_INT0_MCUCR_2_);
#elif info->EXTI_SENSE_MODE==On_change
	Set_Bit(MCUCR_REG,EXTI_INT0_MCUCR_1_);
	Clr_Bit(MCUCR_REG,EXTI_INT0_MCUCR_2_);
#elif info->EXTI_SENSE_MODE==Falling_edge
	Clr_Bit(MCUCR_REG,EXTI_INT0_MCUCR_1_);
	Set_Bit(MCUCR_REG,EXTI_INT0_MCUCR_2_);
#elif info->EXTI_SENSE_MODE==Rising_edge
	Set_Bit(MCUCR_REG,EXTI_INT0_MCUCR_1_);
	Set_Bit(MCUCR_REG,EXTI_INT0_MCUCR_2_);
#else
	return EXTI_Trigger_Error ;
#endif

#elif info->EXTI_INT==EXTI_INT1
#if EXTI_info->EXTI_SENSE_MODE==Low_Level
	Clr_Bit(MCUCR_REG,EXTI_INT1_MCUCR_1_);
	Clr_Bit(MCUCR_REG,EXTI_INT1_MCUCR_2_);
#elif info->EXTI_SENSE_MODE==On_change
	Set_Bit(MCUCR_REG,EXTI_INT1_MCUCR_1_);
	Clr_Bit(MCUCR_REG,EXTI_INT1_MCUCR_2_);
#elif info->EXTI_SENSE_MODE==Falling_edge
	Clr_Bit(MCUCR_REG,EXTI_INT1_MCUCR_1_);
	Set_Bit(MCUCR_REG,EXTI_INT1_MCUCR_2_);
#elif info->EXTI_SENSE_MODE==Rising_edge
	Set_Bit(MCUCR_REG,EXTI_INT1_MCUCR_1_);
	Set_Bit(MCUCR_REG,EXTI_INT1_MCUCR_2_);
#else
	return EXTI_Trigger_Error ;
#endif

#elif info->EXTI_INT==EXTI_INT2
#if EXTI_info->EXTI_SENSE_MODE==Falling_edge
	Clr_Bit(MCUCSR_REG,EXTI_INT2_MCUCSR);
#elif info->EXTI_SENSE_MODE==Rising_edge
	Set_Bit(MCUCSR_REG,EXTI_INT2_MCUCSR);
#else
	return EXTI_Trigger_Error ;
#endif

#else
	return EXTI_INT_Error;
#endif
/*************************************************************/
#endif
/*********************************************************/
#ifndef info->EXTI_INT
	return EXTI_INT_Error;
#endif
/***********************************************************/
	return EXTI_No_Error;
}


/*Enable and Disable GIE Global Interrupt  */

void EXTI_voidEnable_GIE_Interrupt(void)
{
	Set_Bit(SREG_REG  , EXTI_GIE_SREG );
}

void EXTI_voidDisable_GIE_Interrupt(void)
{
	Clr_Bit(SREG_REG  , EXTI_GIE_SREG );
}


/*Enable and Disable PIE Global Interrupt  */

void EXTI_voidDisable_PIE_Interrupt(EXTI_info* info)
{
	Clr_Bit(GICR_REG,info->EXTI_INT);
}

void EXTI_voidEnable_PIE_Interrupt(EXTI_info* info)
{
	Set_Bit(GICR_REG,info->EXTI_INT);
}


void EXTI_voidClearFlag (EXTI_info* info)
{
	Clr_Bit(GIFR_REG,info->EXTI_INT);
}

u8 EXTI_u8GetFlag(EXTI_info* info)
{
	return Get_Bit(GIFR_REG,info->EXTI_INT);
}



void EXTI_voidSetCallBack(void (*ISR_Function) (void), EXTI_info* info)
{
	if(ISR_Function!=Null)
	{
		EXTI_CallBack[info->Number_of_INT]=ISR_Function;
	}
}



/* ISR --> Implementation */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if( EXTI_CallBack[0] != Null ){

		EXTI_CallBack[0]();
		Clr_Bit(GIFR_REG,EXTI_INT0);

	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{

	if( EXTI_CallBack[1] != Null ){

		EXTI_CallBack[1]();
		Clr_Bit(GIFR_REG,EXTI_INT1);

	}

}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{

	if( EXTI_CallBack[2] != Null ){

		EXTI_CallBack[2]() ;
		Clr_Bit(GIFR_REG,EXTI_INT2);
	}
}
