#define PORTA_ITI    (*(volatile u8*)0x3B)
#define SREG_REG	*((volatile u8 *)0x5F)	/* Status Register */
#define TIMSK	*((volatile u8 *)0x59)
#define TCNT0	*((volatile u8 *)0x52)
#define TCCR0	*((volatile u8 *)0x53)


int main()
{
	Set_Bit(SREG_REG , 7 );  // GIE
	Set_Bit(TIMSK , 0 );    //  PIE

	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin0 , 1 );

	Set_Bit(TCCR0, 1 ); // per scler
	// or TCCR0 = 2 ;

/*	Set_Bit(TCNT0, 4 ); // pre lod = 48
	Set_Bit(TCNT0, 5 ); */
// or TCNT0 = 48 ;
	TCNT0 = 192 ;

	while(1)
	{



	}

return 0 ;

}


void __vector_11 (void)  __attribute__((signal));
void __vector_11 (void)
{
	static u16 x ;
	x ++ ;

	if ( x == 3907 )
	{
		/*Set_Bit(TCNT0, 4 ); // pre lod = 48
		Set_Bit(TCNT0, 5 );*/
		TCNT0 = 192 ;
		TOG_BIT(PORTA_ITI , Pin0 );
		x = 0 ;
	}

}

int main()
{

	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin1 , 1 );
	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin0 , 1 );

	Set_Bit(SREG_REG , 7 );  // GIE
	Set_Bit(TIMSK , 1 );    //  PIE
	TCCR0 = 2 ;
	Clr_Bit(TCCR0 ,6);
	Set_Bit(TCCR0 ,7);
	OCR0 = 250  ;

	while(1)
	{



	}

	return 0 ;

}


void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void)
{
	static u16 y ;
	y ++ ;

	if ( y == 20 )
	{
		OCR0 = 250  ;
		TOG_BIT(PORTA_ITI , Pin1 );
		y = 0 ;
	}

}



//////////////////////////////////////////////////////////////////
/***************************  CTC CODE  ***************************/

#define PORTA_ITI    (*(volatile u8*)0x3B)
u32 coun , load , count2;

int main()
{

	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin1 , 1 );
	TIMER0_voidTIMER0Init();

	/* Enable CTC mode*/

	TIMER0_u16CTC_SETNEWOVERFLOW_MS( 1 , &count2 );
	Clr_Bit(TCCR0 ,4);
	Clr_Bit(TCCR0 ,5);



	while(1)
		{

		}


	return 0 ;

}


void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void)
{
	static u32 y ;
	y ++ ;

	if ( y == count2 )
	{
		TOG_BIT(PORTA_ITI , Pin1 );
		y = 0 ;
	}


}


//////////// with call back 

void funcx (void) ;
#define PORTA_ITI    (*(volatile u8*)0x3B)
u32 coun , load , count2;

int main()
{

	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin1 , 1 );
	TIMER0_voidTIMER0Init();
	/* Enable CTC mode*/

	TIMER0_voidCTC_SETNEWOVERFLOW_S( .05 , &count2 );
	TIMER0_voidSetCallBack(funcx) ;



	while(1)
	{

	}


	return 0 ;

}


void funcx (void)
{
	static u32 y ;
	y ++ ;

	if ( y == count2 )
	{
		TOG_BIT(PORTA_ITI , Pin1 );
		y = 0 ;
	}


}





////////////////////////////////////////////////////////////////////////////
////*****************************SW PWM *******************//////

#define PORTA_ITI    (*(volatile u8*)0x3B)
u32 coun , load , ee;

int main()
{

	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin1 , 1 );
	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin0 , 1 );
	Set_Bit(PORTA_ITI , Pin1 );


	TIMER0_voidTIMER0Init();

	/* Enable Normal mode */

	//TIMER0_u16Normal_SETPRELOAD_MS( 2 , &coun , &load );
	//TCNT0 = load  ;

	/* Enable CTC mode*/

	TIMER0_u16CTC_SETNEWOVERFLOW_MS( .0005 , &ee );
	OCR0 = 125  ;

	while(1)
	{



	}

	return 0 ;

}

/*
void __vector_11 (void)  __attribute__((signal));
void __vector_11 (void)
{
	static u16 x ;
	x ++ ;

	if ( x == coun )
	{
		TCNT0 = load  ;
		TOG_BIT(PORTA_ITI , Pin0 );
		x = 0 ;
	}

}
*/
void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void)
{
	static u16 y ;
	y ++ ;


	if ( y == 10 )
		{
			TOG_BIT(PORTA_ITI , Pin1 );
		}

	if ( y == (20) )
	{
		TOG_BIT(PORTA_ITI , Pin1 );
		y = 0 ;
	}

}


////////////////////////////////////////////////////////////////////////////
////*****************************fast PWM *******************//////

#define PORTA_ITI    (*(volatile u8*)0x3B)
u32 coun , load , count2;

int main()
{

	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin1 , 1 );
	TIMER0_voidTIMER0Init();

	/* Enable CTC mode*/
	// TIMER0_u16CTC_SETNEWOVERFLOW_MS( 2 , &count2 );

	/* Enable FPWM mode*/



	while(1)
	{
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_MS(0);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_MS(50);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_MS(100);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_MS(150);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_MS(200);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_MS(250);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_MS(255);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_MS(100);
		_delay_ms(500);

	}


	return 0 ;

}


void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void)
{
	/*static u32 y ;
	y ++ ;

	if ( y == count2 )
	{
		TOG_BIT(PORTA_ITI , Pin1 );
		y = 0 ;
	}
	 */

}



////////////////////////////////////////////// FAST PWM WITH CALLBACK

void funcx (void) ;
#define PORTA_ITI    (*(volatile u8*)0x3B)
u32 coun , load , count2;

int main()
{

	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin1 , 1 );
	TIMER0_voidTIMER0Init();
	/* Enable CTC mode*/
	TIMER0_voidSetCallBack(funcx) ;



	while(1)
	{
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(0);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(50);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(100);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(150);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(200);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(250);
		_delay_ms(500);
		TIMER0_voidFASTPWM_SETNEWOVERFLOW_S(255);
		_delay_ms(500);

	}


	return 0 ;

}


void funcx (void)
{

}




///////////////////////////////////////////////////////////////////////////////////////
/******************       FAST PWM TIMER 2            *********************/
#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
#include "1-MCAL/4-TIMER0/TIMER0_Interface.h"
#include "1-MCAL/6-TIMER2/TIMER2_Interface.h"
#include "2-HAL/Led/Led_Interface.h"

#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>

void funcx (void) ;
#define PORTA_ITI    (*(volatile u8*)0x3B)
u32 coun , load , count2;

int main()
{

	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin1 , 1 );
	TIMER2_voidTIMER2Init();
	/* Enable CTC mode*/
	TIMER2_voidSetCallBack(funcx) ;



	while(1)
	{
		TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(0);
		_delay_ms(500);
		TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(50);
		_delay_ms(500);
		TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(100);
		_delay_ms(500);
		TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(150);
		_delay_ms(500);
		TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(200);
		_delay_ms(500);
		TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(250);
		_delay_ms(500);
		TIMER2_voidFASTPWM_SETNEWOVERFLOW_S(255);
		_delay_ms(500);

	}


	return 0 ;

}




void funcx (void)
{

}
