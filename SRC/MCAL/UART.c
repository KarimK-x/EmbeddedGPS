/**
 * @file    UART.c
 * @brief   UART driver source file for TM4C123GH6PM microcontroller.
 *
 * Implements UART read and write functionality for multiple UART modules.
 * Handles FIFO status checking before read/write operations.
 *
 * @author
 * Karim Mohamed and Rawan Mohamed
*/
#include "../../INCLUDE/MCAL/UART.h"
#include "../../INCLUDE/LIB/tm4c123gh6pm.h"

void UART_Init(UART_Module Unum, u32 baudrate)
{
    f64 uartClk = (F_CPU / (16 * baudrate));
    u32 FBRD = ((uartClk - (u32)uartClk) * 64 + 0.5);
    switch (Unum)
    {
    case UART0:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
        while (!(SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R0));

        UART0_CTL_R &= ~UART_CTL_UARTEN;
        UART0_IBRD_R =(u32)uartClk; //312
        UART0_FBRD_R = FBRD;
        UART0_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTA_AFSEL_R |= GPIO_PA_U0;
				GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & ~(GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX)) | (GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX);
				//GPIO_PORTA_PCTL_R  = (GPIO_PORTA_PCTL_R&~0XFF) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);

        GPIO_PORTA_DEN_R |= GPIO_PA_U0;
        GPIO_PORTA_AMSEL_R &= ~GPIO_PA_U0;
        break;

    case UART1B:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R1;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
        while (!(SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R1));

        UART1_CTL_R &= ~UART_CTL_UARTEN;
        UART1_IBRD_R = (u32)uartClk;
        UART1_FBRD_R = FBRD;
        UART1_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART1_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTB_AFSEL_R |= GPIO_PB_U1;
        GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & ~(GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX)) | (GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX);
        GPIO_PORTB_DEN_R |= GPIO_PB_U1;
        GPIO_PORTB_AMSEL_R &= ~GPIO_PB_U1;

        break;

    case UART1C:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R1;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
        while (!(SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R2));

        UART1_CTL_R &= ~UART_CTL_UARTEN;
        UART1_IBRD_R = (u32)uartClk;
        UART1_FBRD_R = FBRD;
        UART1_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART1_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTC_AFSEL_R |= GPIO_PC_U1;
        GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & ~(GPIO_PCTL_PC4_U1RX | GPIO_PCTL_PC5_U1TX)) | (GPIO_PCTL_PC4_U1RX | GPIO_PCTL_PC5_U1TX);
        GPIO_PORTC_DEN_R |= GPIO_PC_U1;
        GPIO_PORTC_AMSEL_R &= ~GPIO_PC_U1;

        break;

    case UART2:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
        while ((SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R3)==0){};
            
				
				// 3. Unlock PD7 (needed for alternate function)
    GPIO_PORTD_LOCK_R = 0x4C4F434B;  // Unlock GPIO commit register
    GPIO_PORTD_CR_R |= 0x80;         // Allow changes to PD7

        UART2_CTL_R &= ~UART_CTL_UARTEN;
        UART2_IBRD_R = 312;//(u32)uartClk;
        UART2_FBRD_R = 32;//FBRD;
        UART2_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART2_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTD_AFSEL_R |= GPIO_PD_U2;
        GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & ~(GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX)) | (GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX);
        GPIO_PORTD_DEN_R |= GPIO_PD_U2;
        GPIO_PORTD_AMSEL_R &= ~GPIO_PD_U2;

        break;

    case UART3:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R3;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
        while (!(SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R2))
            ;

        UART3_CTL_R &= ~UART_CTL_UARTEN;
        UART3_IBRD_R = (u32)uartClk;
        UART3_FBRD_R = FBRD;
        UART3_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART3_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTC_AFSEL_R |= GPIO_PC_U3;
        GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & ~(GPIO_PCTL_PC6_U3RX | GPIO_PCTL_PC7_U3TX)) | (GPIO_PCTL_PC6_U3RX | GPIO_PCTL_PC7_U3TX);

        GPIO_PORTC_DEN_R |= GPIO_PC_U3;
        GPIO_PORTC_AMSEL_R &= ~GPIO_PC_U3;

        break;

    case UART4:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R4;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
        while (!(SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R2))
            ;

        UART4_CTL_R &= ~UART_CTL_UARTEN;
        UART4_IBRD_R = (u32)uartClk;
        UART4_FBRD_R = FBRD;
        UART4_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART4_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTC_AFSEL_R |= GPIO_PC_U4;
        GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & ~(GPIO_PCTL_PC4_U4RX | GPIO_PCTL_PC5_U4TX)) | (GPIO_PCTL_PC4_U4RX | GPIO_PCTL_PC5_U4TX);
        GPIO_PORTC_DEN_R |= GPIO_PC_U4;
        GPIO_PORTC_AMSEL_R &= ~GPIO_PC_U4;

        break;

    case UART5:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R5;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        while (!(SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R4))
            ;

        UART5_CTL_R &= ~UART_CTL_UARTEN;
        UART5_IBRD_R = (u32)uartClk;
        UART5_FBRD_R = FBRD;
        UART5_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART5_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTE_AFSEL_R |= GPIO_PE_U5;
        GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & ~(GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX)) | (GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX);
        GPIO_PORTE_DEN_R |= GPIO_PE_U5;
        GPIO_PORTE_AMSEL_R &= ~GPIO_PE_U5;

        break;

    case UART6:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R6;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
        while (!(SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R3))
            ;

        UART6_CTL_R &= ~UART_CTL_UARTEN;
        UART6_IBRD_R = (u32)uartClk;
        UART6_FBRD_R = FBRD;
        UART6_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART6_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTD_AFSEL_R |= GPIO_PD_U6;
        GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & ~(GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX)) | (GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX);
        GPIO_PORTD_DEN_R |= GPIO_PD_U6;
        GPIO_PORTD_AMSEL_R &= ~GPIO_PD_U6;

        break;

    case UART7:
        SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R7;
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        while (!(SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R4))
            ;

        UART7_CTL_R &= ~UART_CTL_UARTEN;
        UART7_IBRD_R = (u32)uartClk;
        UART7_FBRD_R = FBRD;
        UART7_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);
        UART7_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

        GPIO_PORTE_AFSEL_R |= GPIO_PE_U7;
        GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & ~(GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX)) | (GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX);
        GPIO_PORTE_DEN_R |= GPIO_PE_U7;
        GPIO_PORTE_AMSEL_R &= ~GPIO_PE_U7;

        break;

    default:
        break;
    }
}

void UART_Write(UART_Module Unum, u8 data)
{
	// Wait until the FIFO isn't full then write the data to DATA register
	switch (Unum)
	{
		case UART0:
			while ((UART0_FR_R & UART_FR1_TXFF) == HIGH){};
			UART0_DR_R = data;
			break;

		case UART1B:
		case UART1C:
			while ((UART1_FR_R & UART_FR1_TXFF) == HIGH){};
			UART1_DR_R = data;
			break;

		case UART2:
			while ((UART2_FR_R & UART_FR1_TXFF) == HIGH){};
			UART2_DR_R = data;
			break;

		case UART3:
			while ((UART3_FR_R & UART_FR1_TXFF) == HIGH){};
			UART3_DR_R = data;
			break;

		case UART4:
			while ((UART4_FR_R & UART_FR1_TXFF) == HIGH){};
			UART4_DR_R = data;
			break;

		case UART5:
			while ((UART5_FR_R & UART_FR1_TXFF) == HIGH){};
			UART5_DR_R = data;
			break;

		case UART6:
			while ((UART6_FR_R & UART_FR1_TXFF) == HIGH){};
			UART6_DR_R = data;
			break;

		case UART7:
			while ((UART7_FR_R & UART_FR1_TXFF) == HIGH){};
			UART7_DR_R = data;
			break;
	}
}

u8 UART_Read(UART_Module Unum)
{
	// Wait until the RX-FIFO isn't empty (recived the data)
	// then write the data to DATA register
	switch (Unum)
	{
		case UART0:
			while ((UART0_FR_R & UART_FR_RXFE) != LOW){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		case UART1B:
		case UART1C:
			while ((UART1_FR_R & UART_FR1_RXEF) != LOW){};
			return (u8)(UART1_DR_R & UART_DR_DATA_MUSK);

		case UART2:
			while ((UART2_FR_R & UART_FR1_RXEF) != LOW){};
			return (u8)(UART2_DR_R & UART_DR_DATA_MUSK);

		case UART3:
			while ((UART3_FR_R & UART_FR1_RXEF) != LOW){};
			return (u8)(UART3_DR_R & UART_DR_DATA_MUSK);

		case UART4:
			while ((UART4_FR_R & UART_FR1_RXEF) != LOW){};
			return (u8)(UART4_DR_R & UART_DR_DATA_MUSK);

		case UART5:
			while ((UART5_FR_R & UART_FR1_RXEF) != LOW){};
			return (u8)(UART5_DR_R & UART_DR_DATA_MUSK);

		case UART6:
			while ((UART6_FR_R & UART_FR1_RXEF) != LOW){};
			return (u8)(UART6_DR_R & UART_DR_DATA_MUSK);

		case UART7:
			while ((UART7_FR_R & UART_FR1_RXEF) != LOW){};
			return (u8)(UART7_DR_R & UART_DR_DATA_MUSK);

		default:
			return 0;
	}
}
//
//
//void UART_sendString(char * string,UART_Module  uart_num)
//{
//    while(*string)
//    {
//        UART_Write(*(string++), uart_num);
//    }
//}
//
//uint8_t UART_receiveString(char *ptr_string , UART_Module uart_num)
//{
//    char ch;
//    uint8_t len = 0;
//    while(1)
//    {
//        ch = UART_Read(uart_num);
//        //UART_sendByte(ch,uart_num);
//        if((ch=='\r') || (ch=='\n') || (ch==0)) // Read till enter key is pressed
//        {
//            if(len!=0)                          // Wait till atleast 1 char is received
//            {
//                ptr_string[len]=0;              // once enter key is pressed null terminate the string and break the loop
//                break;
//            }
//        }
//        else if((ch=='\b') && (len!=0))
//        {
//            len--;                              // If backspace is pressed then decrement the index to remove the old char
//        }
//        else
//        {
//            ptr_string[len]=ch;               //copy the char into string and increment the index
//            len++;
//        }
//    }
//    return len;
//}
//
//
//
void Get_Command(u8 *input, u8 Max_Size)
{
    u8 i;
    for (i = 0; i < Max_Size - 1; i++) // leave space for '\0'
    {
        u8 element = UART_Read(UART0);

        // Check for newline or carriage return
        if (element == '\r' || element == '\n') // user pressed Enter
        {
            break;
        }

        input[i] = element;
        UART_Write(UART0, element); // echo back
    }

    input[i] = '\0'; // Null-terminate string

    // Send newline to PuTTY
    UART_Write(UART0, '\r');
    UART_Write(UART0, '\n');
}


void UART2_INIT(void)
{
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
	
		while ((SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R3)==0){};

	// 3. Unlock PD7 (needed for alternate function)
    GPIO_PORTD_LOCK_R = 0x4C4F434B;  // Unlock GPIO commit register
    GPIO_PORTD_CR_R |= 0x80;         // Allow changes to PD7
	
		UART2_CTL_R &= ~ UART_CTL_UARTEN;
		UART2_IBRD_R = 312;
		UART2_FBRD_R = 32;
	
		UART2_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
		UART2_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		GPIO_PORTD_AFSEL_R |= 0XC0;
		GPIO_PORTD_PCTL_R  = (GPIO_PORTD_PCTL_R&~0XFF000000) |  (GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX);
		GPIO_PORTD_DEN_R   |= 0XC0;
}

void UART1_Init(void) {
    SYSCTL_RCGCUART_R |= 0x02;     // Enable UART1
    SYSCTL_RCGCGPIO_R |= 0x04;     // Enable clock for Port C
    while ((SYSCTL_PRGPIO_R & 0x04) == 0) {}

    GPIO_PORTC_AFSEL_R |= 0x30;    // Enable alternate function on PC4, PC5
    GPIO_PORTC_PCTL_R &= ~0x00FF0000;
    GPIO_PORTC_PCTL_R |= 0x00220000; // Configure PC4/PC5 as UART
    GPIO_PORTC_DEN_R |= 0x30;      // Enable digital on PC4, PC5
    GPIO_PORTC_AMSEL_R &= ~0x30;   // Disable analog

    UART1_CTL_R &= ~UART_CTL_UARTEN;      // Disable UART
    UART1_IBRD_R = 312;                   // Baud rate = 9600 (assuming 16MHz clock)
    UART1_FBRD_R = 32;
    UART1_LCRH_R = UART_LCRH_WLEN_8;      // 8-bit, no parity, 1 stop bit
    UART1_CTL_R |= UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN;
}


u8 UART0_Read(void){
		while ((UART0_FR_R & UART_FR_RXFE) == UART_FR_RXFE){};
		return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);
}