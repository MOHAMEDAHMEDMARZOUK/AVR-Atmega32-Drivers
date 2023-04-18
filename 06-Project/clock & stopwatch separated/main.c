#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
#include "2-HAL/Switch/Switch_Interface.h"
#include "1-MCAL/4-TIMER0/TIMER0_Interface.h"
#include "1-MCAL/6-TIMER1/TIMER1_interface.h"
#include "2-HAL/LCD/Lcd_Interface.h"
//#include "2-HAL/Led/Led_Interface.h"

#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>



#define PORTA_ITI    ((volatile u8)0x3B)
#define PORTC_ITI    ((volatile u8)0x35)

u32 Number  ;
u32 global_counter=0 ;
void function(void);
void SWITCH(void);
void SWITCH2(void);


Switch_Info SW={DIO_GroupD,Pin2,InternalPullUp};
Switch_Info SW2={DIO_GroupD,Pin3,InternalPullUp};

int main()
{


	EXTI_info st1 = { EXTI_INT0 , On_change , 0 };
	EXTI_ErrstateEXTIInit(&st1);
	EXTI_voidEnable_GIE_Interrupt();
	EXTI_voidEnable_PIE_Interrupt(&st1);

	EXTI_voidSetCallBack(SWITCH ,&st1 ) ;

	EXTI_info st2 = { EXTI_INT1 , On_change , 1 };
	EXTI_ErrstateEXTIInit(&st2);
	EXTI_voidEnable_PIE_Interrupt(&st2);

	EXTI_voidSetCallBack(SWITCH2 ,&st2 ) ;


	while(1)
	{
	}


	return 0 ;


}



/* ISR SWITCH Implmentaion */
void SWITCH(void)
{
	u8 state;
	SW_SwitchErrStateGetState(&SW ,&state);
	if(state==PressedPullUp)
	{
		u8 minuit=0;
		u8 hour=0;

		Lcd_Info lcd1={DIO_GroupA , DIO_GroupA,DIO_GroupA ,Pin0,Pin1,Pin2,DIO_GroupB};
		Lcd_VoidInit(&lcd1);

		TIMER0_voidTIMER0Init();
		TIMER0_voidCTC_SETNEWOVERFLOW_S(1,&Number);
		TIMER0_voidSetCallBack(function);

		//////////////////////////////////////////

		Lcd_VoidGoXY(&lcd1,0,13);
		Lcd_VoidSendChar(':',&lcd1);
		Lcd_VoidGoXY(&lcd1,0,10);
		Lcd_VoidSendChar(':',&lcd1);
		Lcd_VoidGoXY(&lcd1,0,0);
		Lcd_VoidSendString("TIME IS: ",&lcd1);

		while (1)
		{
			Lcd_VoidGoXY(&lcd1,1,0);
			Lcd_VoidSendString("         ",&lcd1);
			Lcd_VoidGoXY(&lcd1,0,0);
			Lcd_VoidSendString("TIME IS: ",&lcd1);
			Lcd_VoidGoXY(&lcd1,0,14);
			Lcd_VoidSendNumber(global_counter,&lcd1);

			if(global_counter==60)
			{
				global_counter=0;
				minuit++;
				Lcd_VoidGoXY(&lcd1,0,11);
				Lcd_VoidSendNumber(minuit,&lcd1);

				if(minuit==60)
				{
					minuit=0;
					hour++;
					Lcd_VoidGoXY(&lcd1,0,8);
					Lcd_VoidSendNumber(hour,&lcd1);

					Lcd_VoidGoXY(&lcd1,0,11);
					Lcd_VoidSendChar(' ',&lcd1);
					Lcd_VoidGoXY(&lcd1,0,12);
					Lcd_VoidSendChar(' ',&lcd1);
				}
				Lcd_VoidGoXY(&lcd1,0,14);
				Lcd_VoidSendChar(' ',&lcd1);
				Lcd_VoidGoXY(&lcd1,0,15);
				Lcd_VoidSendChar(' ',&lcd1);


			}

		}
	}
}


/* ISR SWITCH2 Implmentaion */
void SWITCH2(void)
{
	u8 state;
	SW_SwitchErrStateGetState(&SW2 ,&state);
	if(state==PressedPullUp)
	{
		u8 minuit=0;
		u8 hour=0;
		Lcd_Info lcd1={DIO_GroupA , DIO_GroupA,DIO_GroupA ,Pin0,Pin1,Pin2,DIO_GroupB};
		Lcd_VoidInit(&lcd1);

		TIMER0_voidTIMER0Init();
		TIMER0_voidCTC_SETNEWOVERFLOW_S(1,&Number);
		TIMER0_voidSetCallBack(function);

		//////////////////////////////////////////

		Lcd_VoidGoXY(&lcd1,0,13);
		Lcd_VoidSendChar(':',&lcd1);
		Lcd_VoidGoXY(&lcd1,0,10);
		Lcd_VoidSendChar(':',&lcd1);
		Lcd_VoidGoXY(&lcd1,0,0);
		Lcd_VoidSendString("STOP WT: ",&lcd1);

		while (1)
		{
			Lcd_VoidGoXY(&lcd1,1,0);
			Lcd_VoidSendString("         ",&lcd1);
			Lcd_VoidGoXY(&lcd1,0,0);
			Lcd_VoidSendString("STOP WT: ",&lcd1);
			Lcd_VoidGoXY(&lcd1,0,14);
			Lcd_VoidSendNumber(global_counter,&lcd1);

			if(global_counter==60)
			{
				global_counter=0;
				minuit++;
				Lcd_VoidGoXY(&lcd1,0,11);
				Lcd_VoidSendNumber(minuit,&lcd1);

				if(minuit==60)
				{
					minuit=0;
					hour++;
					Lcd_VoidGoXY(&lcd1,0,8);
					Lcd_VoidSendNumber(hour,&lcd1);

					Lcd_VoidGoXY(&lcd1,0,11);
					Lcd_VoidSendChar(' ',&lcd1);
					Lcd_VoidGoXY(&lcd1,0,12);
					Lcd_VoidSendChar(' ',&lcd1);
				}
				Lcd_VoidGoXY(&lcd1,0,14);
				Lcd_VoidSendChar(' ',&lcd1);
				Lcd_VoidGoXY(&lcd1,0,15);
				Lcd_VoidSendChar(' ',&lcd1);
				//SW_SwitchErrStateGetState(&SW2 ,&state);
				//state = !state ;
			}

		}
	}
}

/* ISR Implmentaion */

void function(void)
{
	static u32 counter ;
	counter++;
	if(counter==Number)
	{
		global_counter++;
		counter=0;
	}

}