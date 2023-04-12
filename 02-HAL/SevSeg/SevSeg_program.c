/*
 * SevSeg_program.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#include "SevSeg_Interface.h"
#include <util/delay.h>


u8 SevSeg_Arr[SevSeg_ArrSize]=
{	SevSegCA_0 , SevSegCA_1 , SevSegCA_2 , SevSegCA_3 , SevSegCA_4 , SevSegCA_5 , SevSegCA_6 , SevSegCA_7 , SevSegCA_8 , SevSegCA_9 };

SevErrState    SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1)
{
	if( SevenSegment1 != Null )
	{
		if (SevenSegment1-> SevSeg_Type == SSD_COMMON_CATHODE)
		{
			DIO_ErrStateSetGroupDirection( SevenSegment1-> SevSeg_Group , 0XFF);
			DIO_ErrStateSetGroupValue(SevenSegment1-> SevSeg_Group , SevSeg_Arr[Copy_Number]  );
		}
		
		else if (SevenSegment1-> SevSeg_Type == SSD_COMMON_CATHODE)
		{
			DIO_ErrStateSetGroupDirection( SevenSegment1-> SevSeg_Group , 0XFF);
			DIO_ErrStateSetGroupValue(SevenSegment1-> SevSeg_Group , ~SevSeg_Arr[Copy_Number] );
		}
		
		else {return COMMONSevError ; }
	}
	else 
	{
		return AddressSevError ;
	}

	return NoSevError ;
}

SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End )
{
	for( u8 i = Copy_start ; i <= Copy_End ; i++ )
	{
		SevSeg_SevErrStateSetNumber ( i , SevenSegment1 );
		_delay_ms(1000);
	}

	return NoSevError ;
}

SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1)
{
	for( u8 i = 0 ; i <= 10 ; i++ )
	{
		SevSeg_SevErrStateSetNumber ( i , SevenSegment1 );
		_delay_ms(1000);
	}

	return NoSevError ;
}
