/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK	        **************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 3-4-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Register.h"
#include "ADC_Private.h"

#include "ADC_Config.h"
#include "../../4-Common/BIT_MATH.h"
#include "../../4-Common/Definition.h"
#include "../../4-Common/STD_TYPES.h"


void ADC_voidInit(void);
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Reading, void(*ISR_Function)(void));
u8 ADC_u8StartConversionsynch(u8 Copy_u8Channel, u16* Copy_pu16Reading);

#endif
