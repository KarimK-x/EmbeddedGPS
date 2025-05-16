#include "../MCAL/GPIO.h"
#include "../MCAL/systick.h"
#ifndef LCD_H
#define LCD_H

/* LCD Ports and Pins */
#define LCD_CONTROL_PORT			PORTA_ID
#define LCD_DATA_PORT 				PORTB_ID

#define LCD_RS_PIN 	 					PIN_4
#define LCD_RW_PIN 	 					PIN_5
#define LCD_E_PIN  	 					PIN_6
					
#define LCD_D0_PIN   					PIN_0
#define LCD_D1_PIN   					PIN_1
#define LCD_D2_PIN   					PIN_2
#define LCD_D3_PIN   					PIN_3
#define LCD_D4_PIN   					PIN_4
#define LCD_D5_PIN   					PIN_5
#define LCD_D6_PIN   					PIN_6
#define LCD_D7_PIN   					PIN_7

/* Some Important Definitions */
#define LCD_CLEAR							0x01								// replace all characters with ASCII 'space'
#define	LCD_HOME							0x02								// return cursor to first position on first line
#define	LCD_SHIFT_R						0x1C 								// 6.5 in data sheet
#define	LCD_SHIFT_L						0x18 								
#define	LCD_FUNCTION_SET			0x38 								// two lines , 5*7 characters
#define	LCD_DISPLAY_0N				0x0F 								// display on & cursor blinks
#define	LCD_SHIFT_INC					0X06 								// shift cursor from left to right on read/write
					
/* LCD Functions Prototypes */					
void LCD_voidEnable();														// repeated at the end of all functions
void LCD_voidInit();															// LCD Initialization
					
void LCD_voidSendCommand(u8 comm);								// to send a command
void LCD_voidSendData(u8 data);										// to send a character to be displayed on the LCD

void LCD_voidSendString(const u8 *str);						// to send a string (sequence of characters) to be displayed on the LCD
void LCD_voidIntToStr(u32 num , u8 *str);					// to convert an integer to string to be displayed on the LCD

void LCD_voidMoveCursor(u8 row , u8 col);					// to move the cursor to a desired place

void LCD_voidClearScreen();												// to clear LCD screen, all characters are replaced with 'space'
void LCD_voidSendNumber(u32 num);
void LCD_voidDoubleToStr(double, u8, u8 *str);


#endif /* LCD_H */