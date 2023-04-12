/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK	        **************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 3-4-2023			**************/
/*****************************************************************/
/*****************************************************************/

#include "ADC_Interface.h"
#define Null  ((void *)0x00)
u8  ADC_BusyState = IDLE ;
void (*ADC_CallBack) (void) = { Null } ;

void ADC_voidInit(void)
{
	/*ADC GIE interrupt enable*/
	Set_Bit(SREG_REG , 7 );

	/*AVCC as reference voltage*/
	switch(VREF_Select)
	{
	case AREF :
		Clr_Bit(ADMUX ,ADMUX_REFS0);
		Clr_Bit(ADMUX ,ADMUX_REFS1);
		break ;

	case AVCC :
		Set_Bit(ADMUX ,ADMUX_REFS0);
		Clr_Bit(ADMUX ,ADMUX_REFS1);

		break ;

	case ADC_Reserved :
		Clr_Bit(ADMUX ,ADMUX_REFS0);
		Set_Bit(ADMUX ,ADMUX_REFS1);
		break ;

	case Internal_AREF :
		Set_Bit(ADMUX ,ADMUX_REFS0);
		Set_Bit(ADMUX ,ADMUX_REFS1);
		break ;

	default :
		break ;

	}

	/*Activate Left or Right adjust result*/
	switch(ADLAR_Type)
	{
	case ADLAR_Right_Adjust :   // For Read 10 Bit
		Clr_Bit(ADMUX ,ADMUX_ADLAR);
		break ;

	case ADLAR_Left_Adjust :    // For Read 8 Bit
		Set_Bit(ADMUX ,ADMUX_ADLAR);
		break ;

	default :
		break ;

	}

	/*Enable peripheral*/
	Set_Bit(ADCSRA,ADCSRA_ADEN);

	/*Clear the Prescaler bits in ADCSRA register*/
	ADCSRA &= 0b11111000;

	/*Set the required Prescaler into the ADCSRA bits*/
	ADCSRA |= ADC_PreScal;

}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Reading, void(*ISR_Function)(void))
{
	if (ADC_BusyState == IDLE)
	{
		ADC_BusyState = BUSY ;

		/*Clear the MUX bits in ADMUX register*/
		ADMUX &= 0b11100000;

		/*Set the required channel into the MUX bits*/
		ADMUX|= Copy_u8Channel;

		/*Initialize the callback  function globally*/
		ADC_CallBack = ISR_Function ;

		/*Start conversion*/
		Set_Bit(ADCSRA , ADCSRA_ADSC );

		/*ADC PIE interrupt enable*/
		Set_Bit(ADCSRA,ADCSRA_ADIE);

		if (Copy_pu16Reading != Null )
		{
			if ( ADLAR_Type == ADLAR_Right_Adjust)
			{
				*Copy_pu16Reading = ADCL | ( ADCH << 8 );

			}
			else if ( ADLAR_Type == ADLAR_Left_Adjust)
			{
				*Copy_pu16Reading = ADCH ;
			}
			else { return ADLAR_TypeError ; }
		}
		else { return ADC_AddError ; }
	}

	else { return ADC_BusyStateError ; }

	return ADC_NOError ;
}

u8 ADC_u8StartConversionsynch(u8 Copy_u8Channel, u16* Copy_pu16Reading)
{
	if (ADC_BusyState == IDLE)
	{
		ADC_BusyState = BUSY ;

		/*Clear the MUX bits in ADMUX register*/
		ADMUX &= 0b11100000;

		/*Set the required channel into the MUX bits*/
		ADMUX|= Copy_u8Channel;

		/*Start conversion*/
		Set_Bit(ADCSRA , ADCSRA_ADSC );


		while  (Get_Bit(ADCSRA,ADCSRA_ADIF)==1 && Copy_pu16Reading != Null  )
		{
			if ( ADLAR_Type == ADLAR_Right_Adjust)
			{
				*Copy_pu16Reading = ADCL | ( ADCH << 8 );

			}
			else if ( ADLAR_Type == ADLAR_Left_Adjust)
			{
				*Copy_pu16Reading = ADCH ;
			}
			else { return ADLAR_TypeError ; }
		}


		/* Loop is broken because flag is raised */
		/*clear the conversion complete flag*/
		Set_Bit(ADCSRA,ADCSRA_ADIF);

		/*ADC is finished, return it to IDLE*/
		ADC_BusyState = IDLE;

	}

	else { return ADC_BusyStateError ; }

	return ADC_NOError ;
}


void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{

	if( ADC_CallBack != Null ){

		/*Make ADC state be IDLE because it finished*/
		ADC_BusyState = IDLE;

		/*Invoke the callback notification function*/
		ADC_CallBack() ;

		/*Disable ADC PIE interrupt*/
		Clr_Bit(ADCSRA,ADCSRA_ADIE);

	}
}


