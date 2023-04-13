/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
#include "2-HAL/Led/Led_Interface.h"
#include "2-HAL/Switch/Switch_Interface.h"
#include "2-HAL/SevSeg/SevSeg_Interface.h"

#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>



void func (void);

Switch_Info SW = {DIO_GroupD,Pin3,InternalPullUp};
Led_info L11 = {DIO_GroupA ,Pin0 , Source_Connection };

void main()
{
	SevSeg_info L1 = {SSD_COMMON_CATHODE , DIO_GroupC  };


	EXTI_info st1 = { EXTI_INT1 , On_change , 1 };
	EXTI_ErrstateEXTIInit(&st1);
	EXTI_voidEnable_GIE_Interrupt();
	EXTI_voidEnable_PIE_Interrupt(&st1);

	EXTI_voidSetCallBack(func ,&st1 ) ;



	while(1)
	{

		SevSeg_SevErrStateDisplayMax(&L1);
		_delay_ms(1000);

	}


}



void func (void)
{


	u8 state;
	SW_SwitchErrStateGetState(&SW , &state ) ;

	if (state == 0 )
	{


		Led_LedErrStateTurnOn(&L11);
		_delay_ms(5000);
		Led_LedErrStateTurnOff(&L11);
		//_delay_ms(1000);

	}

}








/*
#include "1-MCAL/1-DIO/DIO_Interface.h"
#include "2-HAL/Led/Led_Interface.h"
#include "2-HAL/Switch/Switch_Interface.h"
#include "2-HAL/SevSeg/SevSeg_Interface.h"
#include "2-HAL/LCD/Lcd_Interface.h"
#include "2-HAL/KEYPAD/KEYPAD_Interface.h"
#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include <util/delay.h>



void main()
{

	u8 customChar[] = {
			0x00,
			0x1B,
			0x15,
			0x11,
			0x0E,
			0x04,
			0x04,
			0x11
	};


	Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
	Lcd_VoidInit(&lcd1);

	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin0,DIO_Output);

	Lcd_VoidSendSpecialChar(customChar,&lcd1 , 0 , 6);


	while(1)
	{



	}

}
 */



