/*


 * SevSeg_Private.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVSEG_SEVSEG_PRIVATE_H_
#define HAL_SEVSEG_SEVSEG_PRIVATE_H_


#include "../../4-Common/STD_TYPES.h"

#define SevSeg_ArrSize  10
/*Cathod -> Led On if write One*/
#define SevSegCA_0      0x3F
#define SevSegCA_1      0x06
#define SevSegCA_2      0x5B
#define SevSegCA_3      0x4F
#define SevSegCA_4      0x66
#define SevSegCA_5      0x6D
#define SevSegCA_6      0x7D
#define SevSegCA_7      0x07
#define SevSegCA_8      0x7F
#define SevSegCA_9      0x6F


/*Anode -> Led On if write Zero*/
#define SevSegAN_0      0xC0
#define SevSegAN_1      0xF9
#define SevSegAN_2      0xA4
#define SevSegAN_3      0xB0
#define SevSegAN_4      0x99
#define SevSegAN_5      0x6D
#define SevSegAN_6      0x92
#define SevSegAN_7      0xF8
#define SevSegAN_8      0x80
#define SevSegAN_9      0x90


typedef enum
{
	NoSevError,
	AddressSevError ,
	COMMONSevError ,

}SevErrState;


typedef struct
{
	u8 SevSeg_Type       ;
	u8 SevSeg_Group      ;
	u8 SevSeg_EnablePort ;
	u8 SevSeg_EnablePin  ;
}SevSeg_info;

/*u8 SevSeg_Arr[SevSeg_ArrSize]=
{		SevSegCA_0 ,
		SevSegCA_1 ,
		SevSegCA_2 ,
		SevSegCA_3 ,
		SevSegCA_4 ,
		SevSegCA_5 ,
		SevSegCA_6 ,
		SevSegCA_7 ,
		SevSegCA_8 ,
		SevSegCA_9 ,
};
*/


#endif /* HAL_SEVSEG_SEVSEG_PRIVATE_H_ */
