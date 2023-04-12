/*
 * SevSeg_Interface.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVSEG_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_SEVSEG_INTERFACE_H_

#include  "SevSeg_Private.h"
#include "../../1-MCAL/1-DIO/DIO_Interface.h"
#include "../../4-Common/Definition.h"
#include "../../4-Common/STD_TYPES.h"

#define SSD_COMMON_CATHODE  0
#define SSD_COMMON_ANODE    1

SevErrState    SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1);

SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End );

SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1);


#endif /* HAL_SEVSEG_SEVSEG_INTERFACE_H_ */
