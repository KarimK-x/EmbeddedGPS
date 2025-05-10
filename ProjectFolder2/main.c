#include <stdint.h>
#include <stdio.h>
#include "GPIO.h"
#include "UART.h"
#include "std_types.h"
//#include "GPS.h"
#include "LCD.h"
#include "systick.h"

//extern char *sep_GPS[12];
//extern char GPS[80]; 
//extern double lon;
//extern double lat;

float lat1 = 48.8566, lon1 =  2.3522;
float lat2 = 51.5074, lon2 = 0.1278;

void LED_VoidIntializeLed(u8 port,u8 pin, u8 direction)
{
	GPIO_voidSetPinDirection(port,pin,direction);
}
void LED_VoidOnLed(u8 port,u8 pin,u8 value)
{
	GPIO_voidSetPinValue(port,pin,value);
}
//u32 *ayhaga[50];

int main()
{
	 PortA_Init();
	 PortB_Init();
	 //PortC_Init();
	 //PortD_Init();
	 //PortE_Init();
	 PortF_Init();
	
	Systick_voidInit();
	
		//UART0_INIT();
		//UART_Init(UART2,9600);
		//UART_Init(UART0,9600);
	
		
		LCD_voidInit();
	
		
		//UART_Init(UART2,9600);
	  //UART2_INIT();
		LED_VoidIntializeLed(PORTF_ID,PIN_2, PIN_OUTPUT);
		LED_VoidIntializeLed(PORTF_ID,PIN_1, PIN_OUTPUT);
		//
	
		//GPS_read();
	//	for(int i=0; i<10; ++i){
	//		for(int j = 0; j<2; ++j){
	//			UART_Write(UART0,sep_GPS[i][j]);
	//		  //Systick_voidDelayms(5);
	//		}
	//		UART_Write(UART0,'\r');
	//		UART_Write(UART0,'\n');
	//	}
				//printf("%.2f,%.2f,%.2f,%.2f\n", lat1, lon1, lat2, lon2);

    //float dist_m = GPS_getDistance(lat1, lon1, lat2, lon2, true);
    ////printf("Distance Paris ? London = %.2f metres\n", dist_m);
		//if((int)dist_m==334576){
		//	//UART_Write(UART0, 'C');
		//	GPIO_voidSetPinValue(PORTF_ID, PIN_2, PIN_HIGH);
		//}
		GPIO_voidSetPinValue(PORTF_ID, PIN_2, PIN_HIGH);

		//LCD_voidIntToStr(dist_m,ayhaga);
		
    LCD_voidSendString("KexLotfy");
		//UART_Write(UART0,sep_GPS[6][0]);
		//UART_Write(UART0,sep_GPS[2][0]);
		//UART_Write(UART0,sep_GPS[3][5]);
		//u8 arr[100];
		//u8 element;
		//element = UART_Read(UART2);
	while(1)
	{
		

		//GPIO_voidSetPinValue(PORTF_ID, PIN_1, PIN_HIGH);
		//for(int i = 0; arr[i] != '\0'; i++)
		//printf("%c", element);
		
		//element = UART_Read(UART2);	
		//UART_Write(UART0, element);
		//UART_Write(UART2,'K');
	  //element=UART_Read(UART2);
		//UART_Write(UART0,element);

		
		//UART_Write(UART0, 'h');
		//printf("sssdjshdsd");
		//Get_Command(arr, 80);
		//element = UART0_Read();
		//UART_Write(UART0, element);
		//if(element == 'r')
		//GPIO_voidSetPinValue(PORTF_ID, PIN_2, PIN_HIGH);
		//else if(element == 't')
		//GPIO_voidSetPinValue(PORTF_ID, PIN_2, PIN_LOW);		
	}
}
