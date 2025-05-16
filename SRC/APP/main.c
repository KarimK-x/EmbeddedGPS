#include "../../INCLUDE/MCAL/GPIO.h"
#include "../../INCLUDE/MCAL/UART.h"
#include "../../INCLUDE/MCAL/systick.h"
#include "../../INCLUDE/HAL/LCD.h"
#include "../../INCLUDE/HAL/GPS.h"
#include "../../INCLUDE/LIB/std_types.h"
#include "stdio.h"
#include "stdint.h"
extern double lon;
extern double lat;
double minDist = 10;
double min_dist;



void LED_VoidIntializeLed(u8 port,u8 pin, u8 direction)
{
	GPIO_voidSetPinDirection(port,pin,direction);
}
void LED_VoidOnLed(u8 port,u8 pin,u8 value)
{
	GPIO_voidSetPinValue(port,pin,value);
}

double threshold = 7;

char locations[10][9] = {"Hall A", "Hall C", "Luban", "Credit","Gold Gym", "Gate3", "Fountain", "Gate2", "Mosque", "Library"};
double lonn[10] ={3116.83508,3116.83970,31.27932183,3116.70529,3116.72545,3116.66735,3116.70691,3116.65159,3116.81689,3116.80426};
double latt[10] ={3003.85206,3003.82247,30.06337517,3003.82004,3003.86346,3003.83762,3003.93784,3003.88490,3003.87938,3003.91185};


u8 indx;
double latdest;
double londest;
u8 nearest_index(){
		GPS_read();
		min_dist = 99999999;
		indx = 0;
		
		for(u8 i = 0; i<10; ++i){
			 londest = 2;//(locations[1]).lon;
			 latdest = 2;//(locations[1]).lat;
			double distance = 0;
			distance = GPS_getDistance( latt[i] , lonn[i], lat,lon,false); 
			if(distance<min_dist){
				min_dist = distance;
				indx = i;
			}
		}
		minDist = min_dist;
		return indx;
	}

u8 n = '0';

	
int main()
{ 
	PortA_Init();
	PortB_Init();
	PortD_Init();
	PortE_Init();
	PortF_Init();
	Systick_voidInit();
	UART_Init(UART2,9600);
	UART_Init(UART0,9600);
	LCD_voidInit();
	
	LED_VoidIntializeLed(PORTF_ID,PIN_2, PIN_OUTPUT);
	LED_VoidIntializeLed(PORTF_ID,PIN_1, PIN_OUTPUT);
	LED_VoidIntializeLed(PORTF_ID,PIN_3, PIN_OUTPUT);
	
	LCD_voidClearScreen();
	
	u8 flag = '1';
	
	while(1)
	{
		u8 nearest = nearest_index();
		
		
		 
		
		if(minDist<threshold){
	//		
			if(flag=='1'){
				LCD_voidClearScreen();
				LCD_voidSendString("Congrats ;)");
				LCD_voidMoveCursor(1,0);
				LCD_voidSendString(locations[nearest]);
				flag='0';
	//		////buzzer on				
			}
			 n = '3';
			while(n>='0'){
				GPIO_voidSetPinValue(PORTF_ID,PIN_1,PIN_HIGH);
				Systick_voidDelayms(300);
				GPIO_voidSetPinValue(PORTF_ID,PIN_1,PIN_LOW);
				GPIO_voidSetPinValue(PORTF_ID,PIN_2,PIN_HIGH);
				Systick_voidDelayms(300);
				GPIO_voidSetPinValue(PORTF_ID,PIN_2,PIN_LOW);
				GPIO_voidSetPinValue(PORTF_ID,PIN_3,PIN_HIGH);
				Systick_voidDelayms(300);
				GPIO_voidSetPinValue(PORTF_ID,PIN_3,PIN_LOW);
				n--;
		}
			continue;
			
		}
		else{
			flag='1';
		}
		
		
		LCD_voidSendString(locations[nearest]);
		LCD_voidMoveCursor(1,0);
		////
		u8 *str10;
		LCD_voidDoubleToStr(minDist,2, str10);
		LCD_voidSendString(str10);
		
		
		
		Systick_voidDelayms(500);
		LCD_voidClearScreen();
	}	
}

