/*
 * EXTL_Program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: marzok
 */

#include "TIMER2_Interface.h"


void (*TIMER2_CallBack[2]) (void) = { Null } ;


void  TIMER2_voidTIMER2Init(void)
{
	Set_Bit(SREG_REG , 7 );  // GIE


	switch(Timer_Mode2)
	{
	case Normal_Mode2 :

		Set_Bit(TIMSK , TIMSK_OverFlow_PIE );    //ENable  PIE
		TCCR2 = Timer_PreScal2 ;
		Clr_Bit(TCCR2 ,TCCR2_MODE_B1);
		Clr_Bit(TCCR2 ,TCCR2_MODE_B2);
		break ;

	case CTC_Mode2 :
		Set_Bit(TIMSK , TIMSK_OutputCompare_PIE );    //ENable  PIE
		TCCR2 = Timer_PreScal2 ;
		Clr_Bit(TCCR2 ,TCCR2_MODE_B1);
		Set_Bit(TCCR2 ,TCCR2_MODE_B2);
		//Set_Bit(TCCR2 ,TCCR2_CTC_EN);
		break ;

	case FASTPWM_Mode2 :
		Set_Bit(TIMSK , TIMSK_OutputCompare_PIE );    //ENable  PIE
		TCCR2 = Timer_PreScal2 ;
		Set_Bit(TCCR2 ,TCCR2_MODE_B1);
		Set_Bit(TCCR2 ,TCCR2_MODE_B2);
		break ;

	case PWM_PhaseCorrect2 :
		Set_Bit(TIMSK , TIMSK_OutputCompare_PIE );    //ENable  PIE
		TCCR2 = Timer_PreScal2 ;
		Set_Bit(TCCR2 ,TCCR2_MODE_B1);
		Clr_Bit(TCCR2 ,TCCR2_MODE_B2);
		break ;

	default :
		break ;

	}
}

/*
 * FUN RETURN PRELOAD Value and Counter Value
 * you should put PRELOAD Value in REG Like :: TCNT0 = PRELOAD  in main & in ISR
 * */

void  TIMER2_voidNormal_SETPRELOAD_S(f64 Desired , u32 *counter , u32 *Pre )
{
	f64 Tick_Time  ,SWcounter ,Preload;

	Tick_Time = (f64)PreScal_Value2 /  (F_CPU) ;
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

void  TIMER2_voidCTC_SETNEWOVERFLOW_S(f64 Desired , u32 *counter  )
{
	f64 Tick_Time  ,SWcounter ;
	OCR2 = CTC_NEWValue2 ;

	switch(CTCs_Mode2)
	{
	case OC2_disconnected :
		Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
		Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
		break ;

	case Toggle_OC2 :
		DIO_ErrStateSetPinDirection(DIO_GroupD , Pin7 , DIO_Output );
		Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
		Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);

		break ;

	case Clear_OC2 :
		DIO_ErrStateSetPinDirection(DIO_GroupD , Pin7 , DIO_Output );
		Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
		Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
		break ;

	case Set_OC2 :
		DIO_ErrStateSetPinDirection(DIO_GroupD , Pin7 , DIO_Output );
		Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
		Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
		break ;

	default :
		break ;

	}


	Tick_Time = (f64)PreScal_Value2 /  (F_CPU) ;
	SWcounter = Desired / (CTC_NEWValue2 *  Tick_Time ) ;
	*counter = SWcounter  ;

}


void  TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(u8 OCR_Value )
{
	OCR2 = OCR_Value ;
	DIO_ErrStateSetPinDirection(DIO_GroupD , Pin7 , DIO_Output );
	switch(FPWM_Mode2)
	{
	case OC2_FPWMdisconnected :
		Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
		Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
		break ;

	case Reserved2 :
		Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
		Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);

		break ;

	case nin_Inverting2 :
		Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
		Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
		break ;

	case Inverting2 :
		Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
		Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
		break ;

	default :
		break ;

	}
}

void  TIMER2_voidPhasePWM_SETNEWOVERFLOW_S(u8 OCR_Value )
{
	OCR2 = OCR_Value ;
	DIO_ErrStateSetPinDirection(DIO_GroupD , Pin7 , DIO_Output );
		switch(PhPWM_Mode2)
		{
		case OC2_PhPWMdisconnected :
			Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
			Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
			break ;

		case Ph_Reserved2 :
			Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
			Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);

			break ;

		case Ph_nin_Inverting2 :
			Clr_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
			Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
			break ;

		case Ph_Inverting2 :
			Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B1);
			Set_Bit(TCCR2 ,TCCR2_CTC_MODE_B2);
			break ;

		default :
			break ;

		}
}


void TIMER2_voidSetCallBack(void (*ISR_Function) (void))
{
	if(ISR_Function!=Null)
	{
	 if ( Timer_Mode2 == Normal_Mode2 )  { TIMER2_CallBack[0]=ISR_Function;}
	 else                              { TIMER2_CallBack[1]=ISR_Function;}
	}
}



/* ISR --> Implementation */
void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{

	if( TIMER2_CallBack[0] != Null ){ TIMER2_CallBack[0](); }

}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{

	if( TIMER2_CallBack[1] != Null ){ TIMER2_CallBack[1](); }

}



