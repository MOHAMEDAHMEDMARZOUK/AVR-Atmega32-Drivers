/*****************************************************************/
/*****************************************************************/
/********************		Author: MARZOK	        **************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 3-4-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*SELECT REF Voltage*/
#define VREF_Select AVCC

/*options :
 * AREF,
	AVCC,
	ADC_Reserved,
	Internal_AREF
 * */

/*Activate Left or Right adjust result*/
#define ADLAR_Type   ADLAR_Left_Adjust

/*options :
    ADLAR_Right_Adjust,       // For Read 10 Bit
	ADLAR_Left_Adjust        // For Read 8 Bit

*/


#define ADC_PreScal  prescaler_128
/*
 * options :
 *
 *  prescaler_2,
 *  prescaler_2,
 *  prescaler_4,
 *  prescaler_8,
 *  prescaler_16,
 *  prescaler_32,
	prescaler_64,
	prescaler_128

	*/



#endif
