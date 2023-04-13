/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: 2022
 */


#include "1-MCAL/1-DIO/DIO_Interface.h"
//#include "1-MCAL/2-EXTRNAL_INTERRUPT/EXTI_Interface.h"
//#include "1-MCAL/4-TIMER0/TIMER0_Interface.h"
//#include "1-MCAL/6-TIMER1/TIMER1_interface.h"
#include "2-HAL/Led/Led_Interface.h"

#include "4-Common/BIT_MATH.h"
#include "4-Common/STD_TYPES.h"
#include "5-RTOS Stack/01-RTOS/RTOS_interface.h"
#include <util/delay.h>

#define PORTA_ITI    (*(volatile u8*)0x3B)

void LED1 (void);
void LED2 (void);
void LED3 (void);

int main(void)
{

	DIO_ErrStateSetGroupDirection(DIO_GroupA , 0XFF);
	DIO_ErrStateSetGroupValue(DIO_GroupA , 0X00);
	RTOS_voidCreateTask(0 , 1000 , LED1);
	RTOS_voidCreateTask(1 , 3000 , LED2);
	RTOS_voidCreateTask(2 , 5000 , LED3);

	RTOS_voidStart();

	while(1)
	{

	}


return 0 ;
}


void LED1 (void)
{
	TOG_BIT(PORTA_ITI , 0 ) ;

}

void LED2 (void)
{
	TOG_BIT(PORTA_ITI , 1 ) ;
}

void LED3 (void)
{
	TOG_BIT(PORTA_ITI , 2 ) ;
}
