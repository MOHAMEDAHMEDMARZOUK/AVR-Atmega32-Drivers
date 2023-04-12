/*
  * EXTL_Program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: marzok
 */

#include "TIMER0_Interface.h"


void (*TIMER0_CallBack[2]) (void) = { Null } ;


void  TIMER0_voidTIMER0Init(void)
{
	Set_Bit(SREG_REG , 7 );  // GIE


	switch(Timer_Mode)
	{
	case Normal_Mode :

		Set_Bit(TIMSK , TIMSK_OverFlow_PIE );    //ENable  PIE
		TCCR0 = Timer_PreScal ;
		Clr_Bit(TCCR0 ,TCCR0_MODE_B1);
		Clr_Bit(TCCR0 ,TCCR0_MODE_B2);
		break ;

	case CTC_Mode :
		Set_Bit(TIMSK , TIMSK_OutputCompare_PIE );    //ENable  PIE
		TCCR0 = Timer_PreScal ;
		Clr_Bit(TCCR0 ,TCCR0_MODE_B1);
		Set_Bit(TCCR0 ,TCCR0_MODE_B2);
		//Set_Bit(TCCR0 ,TCCR0_CTC_EN);
		break ;

	case FASTPWM_Mode :
		//Set_Bit(TIMSK , TIMSK_OutputCompare_PIE );    //ENable  PIE
		TCCR0 = Timer_PreScal ;
		Set_Bit(TCCR0 ,TCCR0_MODE_B1);
		Set_Bit(TCCR0 ,TCCR0_MODE_B2);
		break ;

	case PWM_PhaseCorrect :
		//Set_Bit(TIMSK , TIMSK_OutputCompare_PIE );    //ENable  PIE
		TCCR0 = Timer_PreScal ;
		Set_Bit(TCCR0 ,TCCR0_MODE_B1);
		Clr_Bit(TCCR0 ,TCCR0_MODE_B2);
		break ;

	default :
		break ;

	}
}

/*
 * FUN RETURN PRELOAD Value and Counter Value
 * you should put PRELOAD Value in REG Like :: TCNT0 = PRELOAD  in main & in ISR
 * */

void  TIMER0_voidNormal_SETPRELOAD_S(f64 Desired , u32 *counter , u32 *Pre )
{
	f64 Tick_Time  ,SWcounter ,Preload;

	Tick_Time = (f64)PreScal_Value /  (F_CPU) ;
	SWcounter = Desired / (256 *  Tick_Time ) ;

	*counter = SWcounter + 1 ;

	*Pre = SWcounter ;
	Preload = SWcounter - *Pre ;

	Preload = (Preload * 256 );

	Preload = 256 - Preload ;

	*Pre = Preload ;

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
	OCR0 = CTC_NEWValue ;

	switch(CTCs_Mode)
	{
	case OC0_disconnected :
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
		break ;

	case Toggle_OC0 :
		DIO_ErrStateSetPinDirection(DIO_GroupB , Pin3 , DIO_Output );
		Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);

		break ;

	case Clear_OC0 :
		DIO_ErrStateSetPinDirection(DIO_GroupB , Pin3 , DIO_Output );
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
		break ;

	case Set_OC0 :
		DIO_ErrStateSetPinDirection(DIO_GroupB , Pin3 , DIO_Output );
		Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
		break ;

	default :
		break ;

	}


	Tick_Time = (f64)PreScal_Value /  (F_CPU) ;
	SWcounter = Desired / (CTC_NEWValue *  Tick_Time ) ;
	*counter = SWcounter  ;

}


void  TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(u8 OCR_Value )
{
	OCR0 = OCR_Value ;
	DIO_ErrStateSetPinDirection(DIO_GroupB , Pin3 , DIO_Output );
	switch(FPWM_Mode)
	{
	case OC0_FPWMdisconnected :
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
		break ;

	case Reserved :
		Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);

		break ;

	case nin_Inverting :
		Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
		break ;

	case Inverting :
		Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
		Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
		break ;

	default :
		break ;

	}
}

void  TIMER0_voidPhasePWM_SETNEWOVERFLOW_S(u8 OCR_Value )
{
	OCR0 = OCR_Value ;
		DIO_ErrStateSetPinDirection(DIO_GroupB , Pin3 , DIO_Output );
		switch(PhPWM_Mode)
		{
		case OC0_PhPWMdisconnected :
			Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
			Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
			break ;

		case Ph_Reserved :
			Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
			Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);

			break ;

		case Ph_nin_Inverting :
			Clr_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
			Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
			break ;

		case Ph_Inverting :
			Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B1);
			Set_Bit(TCCR0 ,TCCR0_CTC_MODE_B2);
			break ;

		default :
			break ;

		}
}


void TIMER0_voidSetCallBack(void (*ISR_Function) (void))
{
	if(ISR_Function!=Null)
	{
	 if ( Timer_Mode == Normal_Mode )  { TIMER0_CallBack[0]=ISR_Function;}
	 else                              { TIMER0_CallBack[1]=ISR_Function;}
	}
}



/* ISR --> Implementation */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{

	if( TIMER0_CallBack[0] != Null ){ TIMER0_CallBack[0](); }

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{

	if( TIMER0_CallBack[1] != Null ){ TIMER0_CallBack[1](); }

}



