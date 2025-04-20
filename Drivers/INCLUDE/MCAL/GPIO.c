#include "GPIO.h"

void PortA_Init()
{
     SetBit(SYSCTL_RCGCGPIO_R,0);
	while(GetBit(SYSCTL_PRGPIO_R,0)==0);
	GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
     GPIO_PORTA_CR_R |= 0xFF;
	GPIO_PORTA_AFSEL_R &= ~ 0xFF;  
	GPIO_PORTA_PCTL_R  =0x0;
	GPIO_PORTA_DEN_R |= 0xFF;
	GPIO_PORTA_AMSEL_R &= ~ 0xFF;
}
void PortB_Init()
{
     SetBit(SYSCTL_RCGCGPIO_R,1);
    while(GetBit(SYSCTL_PRGPIO_R,1)==0);
     GPIO_PORTB_LOCK_R =GPIO_LOCK_KEY;
     GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_AFSEL_R &= ~ 0xFF;  
	GPIO_PORTB_PCTL_R = 0x0 ;   
	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_AMSEL_R &= ~ 0xFF;
}
void PortC_Init()
{
     SetBit(SYSCTL_RCGCGPIO_R,2);
    while(GetBit(SYSCTL_PRGPIO_R,2)==0);
     GPIO_PORTC_CR_R |= 0xFF;
	GPIO_PORTC_AFSEL_R &= ~ 0xFF;  
	GPIO_PORTC_PCTL_R =0x0; 
	GPIO_PORTC_DEN_R |= 0xFF;
	GPIO_PORTC_AMSEL_R &= ~ 0xFF;
	
}

void GPIO_voidSetPinDirection(u8 port,u8 pin, u8 direction)
{
    if(direction == PIN_INPUT)
    {
        switch(port)
        {
            case PORTA_ID:
                 ClrBit(GPIO_PORTA_DIR_R,pin);
                 break;
            case PORTB_ID:
                 ClrBit(GPIO_PORTB_DIR_R,pin);
                 break;
            case PORTC_ID:
                 ClrBit(GPIO_PORTC_DIR_R,pin);
                 break;     
            case PORTD_ID:
                 ClrBit(GPIO_PORTD_DIR_R,pin);
                 break;
            case PORTE_ID:
                 ClrBit(GPIO_PORTE_DIR_R,pin);
                 break;
            case PORTF_ID:
                 ClrBit(GPIO_PORTF_DIR_R,pin);
                 break;                   
        }    
    }
    else if(direction == PIN_OUTPUT)
    {
        switch(port)
        {
            case PORTA_ID:
                 SetBit(GPIO_PORTA_DIR_R,pin);
                 break;
            case PORTB_ID:
                 SetBit(GPIO_PORTB_DIR_R,pin);
                 break;
            case PORTC_ID:
                 SetBit(GPIO_PORTC_DIR_R,pin);
                 break;     
            case PORTD_ID:
                 SetBit(GPIO_PORTD_DIR_R,pin);
                 break;
            case PORTE_ID:
                 SetBit(GPIO_PORTE_DIR_R,pin);
                 break;
            case PORTF_ID:
                 SetBit(GPIO_PORTF_DIR_R,pin);
                 break;                
        }
    }
}
void GPIO_voidSetPinValue(u8 port,u8 pin, u8 value)
{
    if(value == PIN_LOW)
    {
        switch(port)
        {
            case PORTA_ID:
                 ClrBit(GPIO_PORTA_DATA_R,pin);
                 break;
            case PORTB_ID:
                 ClrBit(GPIO_PORTB_DATA_R,pin);
                 break;
            case PORTC_ID:
                 ClrBit(GPIO_PORTC_DATA_R,pin);
                 break;     
            case PORTD_ID:
                 ClrBit(GPIO_PORTD_DATA_R,pin);
                 break;
            case PORTE_ID:
                 ClrBit(GPIO_PORTE_DATA_R,pin);
                 break;
            case PORTF_ID:
                 ClrBit(GPIO_PORTF_DATA_R,pin);
                 break;
        }
    }
    else if(value == PIN_HIGH)
    {
        switch(port)
        {
            case PORTA_ID:
                 SetBit(GPIO_PORTA_DATA_R,pin);
                 break;
            case PORTB_ID:
                 SetBit(GPIO_PORTB_DATA_R,pin);
                 break;
            case PORTC_ID:
                 SetBit(GPIO_PORTC_DATA_R,pin);
                 break;     
            case PORTD_ID:
                 SetBit(GPIO_PORTD_DATA_R,pin);
                 break;
            case PORTE_ID:
                 SetBit(GPIO_PORTE_DATA_R,pin);
                 break;
            case PORTF_ID:
                 SetBit(GPIO_PORTF_DATA_R,pin);
                 break;
        }
    }
}
u8 GPIO_u8GetPinValue(u8 port,u8 pin)
{
    switch(port)
        {
            case PORTA_ID:
                 return GetBit(GPIO_PORTA_DATA_R,pin);
                 break;
            case PORTB_ID:
                 return GetBit(GPIO_PORTB_DATA_R,pin);
                 break;
            case PORTC_ID:
                 return GetBit(GPIO_PORTC_DATA_R,pin);
                 break;     
            case PORTD_ID:
                 return GetBit(GPIO_PORTD_DATA_R,pin);
                 break;
            case PORTE_ID:
                 return GetBit(GPIO_PORTE_DATA_R,pin);
                 break;
            case PORTF_ID:
                 return GetBit(GPIO_PORTF_DATA_R,pin);
                 break;
            default:
                 return 0;     
        }
}
void GPIO_VoidTogglePin(u8 port,u8 pin)
{
    switch(port)
        {
            case PORTA_ID:
                 TogBit(GPIO_PORTA_DATA_R,pin);
                 break;
            case PORTB_ID:
                 TogBit(GPIO_PORTB_DATA_R,pin);
                 break;
            case PORTC_ID:
                 TogBit(GPIO_PORTC_DATA_R,pin);
                 break;     
            case PORTD_ID:
                 TogBit(GPIO_PORTD_DATA_R,pin);
                 break;
            case PORTE_ID:
                 TogBit(GPIO_PORTE_DATA_R,pin);
                 break;
            case PORTF_ID:
                 TogBit(GPIO_PORTF_DATA_R,pin);
                 break;
        }
}
