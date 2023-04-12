/***********************************************************************************
 * Author 	  : Mohamed Marzok													   *
 * Date   	  : 30/4/2022														   *
 * File name  : LCD_REGISTER.h											 		   *
 * Description: This File Contain The Address for LCD Address	                   *
 * Version    :  01																   *
 ***********************************************************************************/

#ifndef HAL_LCD_HEADER_LCD_REGISTER_H_
#define HAL_LCD_HEADER_LCD_REGISTER_H_


#define default_Function_Set  LCD_Set8Bit2Line5x8

#define default_Displayon_off  LCD_CursorON



#define LCD_FirstLine        0x00
#define LCD_SecondLine       0x40


/*Command Line */
/*Set CG RAM Address*/
#define  LCD_SetAddressCGRAM      0x40
/*Set DDRAM Address*/
#define  LCD_SetAddressDDRAM      0x80

#define size_Special_Array  8  //for font 5*8
#define Size_CGRAM  16


#endif /* HAL_LCD_HEADER_LCD_REGISTER_H_ */
