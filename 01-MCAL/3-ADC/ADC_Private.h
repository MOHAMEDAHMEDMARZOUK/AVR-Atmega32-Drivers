/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 3-4-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



typedef enum
{
	ADLAR_Right_Adjust,       // For Read 10 Bit
	ADLAR_Left_Adjust        // For Read 8 Bit

}ADC_ADLAR;

typedef enum
{
	AREF,
	AVCC,
	ADC_Reserved,
	Internal_AREF

}ADC_VREF_Select;

typedef enum
{
	prescaler_1,
	prescaler_2,
	prescaler_4,
	prescaler_8,
	prescaler_16,
	prescaler_32,
	prescaler_64,
	prescaler_128

}ADC_PreScal_Type;

typedef enum

{
	ADC_NOError,
	ADLAR_TypeError,
	ADC_BusyStateError,
	ADC_AddError

}ADC_Errorstate;

typedef enum
{
	IDLE,
	BUSY,

}ADC_BusyStates;


#endif
