/*
 * KEYPAD_interface.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Arabtech
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_
#include "KEYPAD_private.h"

#include "KEYPAD_configuration.h"

u8   KEYPAD_ErrStateReadkeyPad(u8  KEYPAD_Arr[][4] );

void  KEYPAD_voidinitkeyPad(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
