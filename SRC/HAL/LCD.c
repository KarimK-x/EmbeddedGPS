#include "../../INCLUDE/HAL/LCD.h"

//u8* str;
void LCD_voidEnable()
{
	GPIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,PIN_HIGH);	 
	Systick_voidDelayms(50);
	GPIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,PIN_LOW);	 
}
void LCD_voidInit()
{
  GPIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_OUTPUT);
	GPIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_OUTPUT);
	GPIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_E_PIN,PIN_OUTPUT);
	GPIO_voidSetPortDirection(LCD_DATA_PORT,PORT_OUTPUT);
	Systick_voidDelayms(50);
	LCD_voidSendCommand(LCD_FUNCTION_SET);
	Systick_voidDelayms(50);
	LCD_voidSendCommand(LCD_DISPLAY_0N);
	Systick_voidDelayms(50);	
  LCD_voidSendCommand(LCD_CLEAR);
	Systick_voidDelayms(50);
	(LCD_SHIFT_INC);
	LCD_voidEnable();
	
}

void LCD_voidMoveCursor(u8 row , u8 col)
{
	u8 address;
	if(row<=1 && col<=15)
	{
		address=(row*0x40)+col;
		address=SetBit(address,LCD_D7_PIN);
		LCD_voidSendCommand(address);
	}
}

void LCD_voidSendString(const u8 *str)
{
	for(u8 i=0;str[i]!='\0';i++)
	{
		LCD_voidSendData(str[i]);
	}
}

void LCD_voidIntToStr(u32 num,u8 *str)
{
	u8 i = 0;
	if (num == 0) {
		str[i++] = '0';
		} else {
		u8 temp[50];
		u32 j = 0;
		while (num > 0) {
			temp[j++] = (num % 10) + '0';
			num /= 10;
		}
		
		for (u32 k = 0; k < j; k++) {
			str[k] = temp[j - k - 1];
		}
		i = j;
	}
	str[i] = '\0';
}

void LCD_voidSendData(u8 data)
{
	GPIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_HIGH);
	GPIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_LOW);
	GPIO_voidSetPortValue(LCD_DATA_PORT,data);
	LCD_voidEnable();
	Systick_voidDelayms(50);
}

void LCD_voidSendCommand(u8 comm)
{
	GPIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_LOW);
	GPIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_LOW);
	GPIO_voidSetPortValue(LCD_DATA_PORT,comm);
	LCD_voidEnable();	
}

void LCD_voidClearScreen()
{
	LCD_voidSendCommand(LCD_CLEAR);
}
//void LCD_voidSendNumber(u32 num){
//	u8*str;
//	LCD_voidIntToStr(num,str);
//	LCD_voidSendString(str);
//}
void LCD_voidDoubleToStr(double num, u8 decimal_places, u8 *str)
{
    u8 i = 0;
    
    // Handle negative numbers
    if (num < 0) {
        str[i++] = '-';
        num = -num;
    }
    
    // Extract integer part
    u32 integer_part = (u32)num;
    
    // Extract decimal part
    double decimal_part = num - integer_part;
    
    // Convert integer part first
    if (integer_part == 0) {
        str[i++] = '0';
    } else {
        u8 temp[50];
        u32 j = 0;
        while (integer_part > 0) {
            temp[j++] = (integer_part % 10) + '0';
            integer_part /= 10;
        }
        
        for (u32 k = 0; k < j; k++) {
            str[i++] = temp[j - k - 1];
        }
    }
    
    // Add decimal point
    if (decimal_places > 0) {
        str[i++] = '.';
        
        // Convert decimal part
        while (decimal_places > 0) {
            decimal_part *= 10;
            u8 digit = (u8)decimal_part;
            str[i++] = digit + '0';
            decimal_part -= digit;
            decimal_places--;
        }
    }
    
    str[i] = '\0';
}


