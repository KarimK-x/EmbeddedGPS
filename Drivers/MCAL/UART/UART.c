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
#include "UART.h"

UART_Write(UART_Module Unum, u8 data)
{
	// Wait until the FIFO isn't full then write the data to DATA register
	switch (Unum)
	{
		case UART0:
			while (UART0_FR_R & UART_FR_TXFF == HIGH){};
			UART0_DR_R = data;
			break;

		case UART1B:
		case UART1C:
			while (UART1_FR_R & UART_FR_TXFF == HIGH){};
			UART1_DR_R = data;
			break;

		case UART2:
			while (UART2_FR_R & UART_FR_TXFF == HIGH){};
			UART2_DR_R = data;
			break;

		case UART3:
			while (UART3_FR_R & UART_FR_TXFF == HIGH){};
			UART3_DR_R = data;
			break;

		case UART4:
			while (UART4_FR_R & UART_FR_TXFF == HIGH){};
			UART4_DR_R = data;
			break;

		case UART5:
			while (UART5_FR_R & UART_FR_TXFF == HIGH){};
			UART5_DR_R = data;
			break;

		case UART6:
			while (UART6_FR_R & UART_FR_TXFF == HIGH){};
			UART6_DR_R = data;
			break;

		case UART7:
			while (UART7_FR_R & UART_FR_TXFF == HIGH){};
			UART7_DR_R = data;
			break;
	}
}

UART_Read(UART_Module Unum)
{
	// Wait until the RX-FIFO isn't empty (recived the data)
	// then write the data to DATA register
	switch (Unum)
	{
		case UART0:
			while ((UART0_FR_R & UART_FR_RXEF) == HIGH){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		case UART1B:
		case UART1C:
			while ((UART0_FR_R & UART_FR_RXEF) == HIGH){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		case UART2:
			while ((UART0_FR_R & UART_FR_RXEF) == HIGH){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		case UART3:
			while ((UART0_FR_R & UART_FR_RXEF) == HIGH){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		case UART4:
			while ((UART0_FR_R & UART_FR_RXEF) == HIGH){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		case UART5:
			while ((UART0_FR_R & UART_FR_RXEF) == HIGH){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		case UART6:
			while ((UART0_FR_R & UART_FR_RXEF) == HIGH){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		case UART7:
			while ((UART0_FR_R & UART_FR_RXEF) == HIGH){};
			return (u8)(UART0_DR_R & UART_DR_DATA_MUSK);

		default:
			return 0;
	}
}

Get_Command (u8 *input, u8 Max_Size)
{
	for(u8 i=0; i<Max_Size; i++)
	{
		u8 element = UART_READ(UART0);
		if(element == '\n') // if the user typed enter the command will end
			break;
		else	
			input[i] = element ;	// store the elements in char array 
		UART_Write(UART0, element); // sends the data back to the pc 
	}
}