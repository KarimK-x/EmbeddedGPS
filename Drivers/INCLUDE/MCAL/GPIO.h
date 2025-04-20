#ifndef GPIO_H_
#define GPIO_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"
#include "BitMath.h"


/*Define 6 PORTS */
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
#define PORTE_ID 4
#define PORTF_ID 5

/*Define 8 PINS */
#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7

/*Set pin direction 0 for input, 1 for output*/
#define PIN_INPUT   0
#define PIN_OUTPUT  1

/*Set pin value 0 for low, 1 for high*/
#define PIN_LOW  0
#define PIN_HIGH 1

/*Set port direction 0 for input, 0xFF for output*/
#define PORT_INPUT  0
#define PORT_OUTPUT 0xFF

/*Set port value 0 for low, 0xFF for high*/
#define PORT_LOW    0
#define PORT_HIGH 0xFF

#define GPIO_LOCK_KEY		0x4C4F434B

/*Functions to initialize the GPIO ports*/
void PortA_Init();
void PortB_Init();
void PortC_Init();
void PortD_Init();
void PortE_Init();
void PortF_Init();

/*GPIO control functions*/
void GPIO_voidSetPinDirection(u8 port,u8 pin, u8 direction);

void GPIO_voidSetPinValue(u8 port,u8 pin, u8 value);

u8 GPIO_u8GetPinValue(u8 port,u8 pin);

void GPIO_voidSetPortDirection(u8 port,u8 direction);

void GPIO_voidSetPortValue(u8 port,u8 value);

u8 GPIO_u8GetPortValue(u8 port);

void GPIO_VoidTogglePin(u8 port,u8 pin);


#endif /* GPIO_H_ */