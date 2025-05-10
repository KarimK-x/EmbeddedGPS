#include "GPIO.h"
#include "tm4c123gh6pm.h"

unsigned seg1,seg2,seg3;
unsigned char seven_segmentArray[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //from 0:9
unsigned char counter=0;


 void setSevenSegment (unsigned char indexOfSevenSegArray){// from 0:9
 //GPIO_PORTB_setPort (~seven_segmentArray[ indexOfSevenSegArray]);
 GPIO_voidSetPortValue(PORTB_ID,(~seven_segmentArray[ indexOfSevenSegArray]));

 }

 void SplitDistance(double distance){
	 
 int d = (int)distance;

 seg1 = d % 10;   // most right seg
 d /= 10;        //521
 seg2 = d % 10;
 d /= 10;
 seg3 = d % 10;
 d /= 10;
 }

	 

	 
 void show(int digit, char value){ //digit ===> GND value ==> value of each 7-seg
 //GPIO_PORTB_DATA_R = 0x00; // Turns off LEDs
 GPIO_voidSetPortValue(PORTB_ID, 0X00)
 GPIO_PORTE_DATA_R = digit; // Selects segment to turn on PE1,PE2,PE3
 setSevenSegment ( value);
 }
 void SysTick_Handler(){
	 
 if(counter==0){
 show(0, seg3);
 counter++;
 }
 if(counter==1){
 show(4, seg2);
 counter++;
 }
 if(counter==2){
 show(2, seg1);
 counter++;
 }
 }
