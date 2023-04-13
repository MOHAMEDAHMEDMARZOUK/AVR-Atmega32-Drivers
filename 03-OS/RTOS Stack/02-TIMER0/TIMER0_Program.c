
/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK		    **************/
/********************		Layer: RTOS_Stack	    **************/
/********************		SWC: RTOS_GIE			**************/
/********************		Version: 1.00			**************/
/********************		Date: 13-4-2023			**************/
/*****************************************************************/
/*****************************************************************/
#include "TIMER0_Interface.h"
#include "TIMER0_Configuration.h"
#include "../../4-Common/STD_TYPES.h"
void (*TIMER0_CallBack[2]) (void) = { Null } ;


void  TIMER0_voidTIMER0Init(void)
{
	//Set_Bit(SREG_REG , 7 );  // GIE


	switch(RTOS_Timer_Mode)
	{

	case RTOS_CTC_Mode :
		Set_Bit(TIMSK , TIMSK_OutputCompare_PIE );    //ENable  PIE
		TCCR0 = RTOS_Timer_PreScal ;
		Clr_Bit(TCCR0 ,TCCR0_MODE_B1);
		Set_Bit(TCCR0 ,TCCR0_MODE_B2);
		//Set_Bit(TCCR0 ,TCCR0_CTC_EN);
		break ;


	default :
		break ;
	}

	OCR0 = RTOS_CTC_NEWValue ;
}


/*
 * FUN RETURN Counter Value
 * you PUT The New CTC Value in The configuration
 * WE  PUT The New CTC Value in The REG Like OCR0 = CTC_NEWValue
 * you should put PRELOAD Value in REG Like :: TCNT0 = PRELOAD  in main & in ISR
 * */

void  TIMER0_voidCTC_SETNEWOVERFLOW_S(f64 Desired , u32 *counter  )
{
	f64 Tick_Time  ,SWcounter ;
	OCR0 = RTOS_CTC_NEWValue ;

	switch(RTOS_CTCs_Mode)
	{
	case RTOS_OC0_disconnected :
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
		break ;


	default :
		break ;

	}


	Tick_Time = (f64)RTOS_PreScal_Value /  (F_CPU) ;
	SWcounter = Desired / (RTOS_CTC_NEWValue *  Tick_Time ) ;
	*counter = SWcounter  ;

}



void TIMER0_voidSetCallBack(void (*ISR_Function) (void))
{
	if(ISR_Function!=Null)
	{
	 if ( RTOS_Timer_Mode == RTOS_Normal_Mode )  { TIMER0_CallBack[0]=ISR_Function;}
	 else                              { TIMER0_CallBack[1]=ISR_Function;}
	}
}



/* ISR --> CTC Implementation */

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{

	if( TIMER0_CallBack[1] != Null ){ TIMER0_CallBack[1](); }

}



