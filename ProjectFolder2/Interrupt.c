#include "Interrupt.h"

 void EdgeCounter_Init(void){
 SYSCTL_RCGCGPIO_R |= 0x00000020; // activate port F FallingEdges = 0;
 GPIO_PORTF_DIR_R &= ~0x10; 
GPIO_PORTF_DEN_R |= 0x10; //  
GPIO_PORTF_PUR_R |= 0x10; //  
	 
GPIO_PORTF_IS_R &= ~0x10; 	// edge sensitive
GPIO_PORTF_IBE_R &= ~0x10; 	// both edges on/off
GPIO_PORTF_IEV_R &= ~0x10; 	// negative edge/ positive edge
	 
GPIO_PORTF_ICR_R = 0x10; 		// clear the flag of pf4
GPIO_PORTF_IM_R |=0x10;			//
 
NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // priority 5 
NVIC_EN0_R = 0x40000000; // enableinterrupt 30 in NVIC 
EnableInterrupts();
 // Enable globalInterrupt flag (I)
 }
