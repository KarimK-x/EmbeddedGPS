/**
 * @file    uart_driver.h
 * @brief   UART driver interface for TM4C123GH6PM microcontroller.
 *
 * This header provides function prototypes and definitions to initialize and
 * communicate with the UART modules available on the Tiva C series microcontroller.
 * It supports multiple UART modules and abstracts hardware details for ease of use.
 *
 * @ Karim Mohamed and Rawan Mohamed
 * @ version 1.0
 */
#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include "tm4c123gh6pm.h"
#include "std_types.h"

 /**
  * @enum UART_Module
  * @brief Enumeration for UART module selection.
  *
  * Provides symbolic names for supported UART modules.
  * - UART1B and UART1C refer to UART1 with different GPIO pin mappings.
  */
typedef enum
{
    UART0,  /**< UART0 (PA0 - RX, PA1 - TX) */
    UART1B, /**< UART1 on Port B (PB0 - RX, PB1 - TX) */
    UART1C, /**< UART1 on Port C (PC4 - RX, PC5 - TX) */
    UART2,  /**< UART2 (PD6 - RX, PD7 - TX) */
    UART3,  /**< UART3 (PC6 - RX, PC7 - TX) */
    UART4,  /**< UART4 (PC4 - RX, PC5 - TX) */
    UART5,  /**< UART5 (PE4 - RX, PE5 - TX) */
    UART6,  /**< UART6 (PD4 - RX, PD5 - TX) */
    UART7   /**< UART7 (PE0 - RX, PE1 - TX) */
} UART_Module;

/**
 * @brief Initialize the selected UART module with a given baud rate.
 *
 * Configures UART control registers and associated GPIO pins.
 *
 * @param Unum     UART module to initialize (e.g., UART0, UART1B, ...).
 * @param baudrate Desired baud rate for communication (e.g., 9600, 115200).
 */
void UART_Init(UART_Module Unum, u32 baudrate);

/**
 * @brief Transmit a single byte of data over the selected UART module.
 *
 * Waits for the transmit FIFO to be ready and sends the data.
 *
 * @param Unum UART module to use for transmission.
 * @param data 8-bit data to be transmitted.
 */
void UART_Write(UART_Module Unum, u8 data);

/**
 * @brief Receive a single byte of data from the selected UART module.
 *
 * Waits for the receive FIFO to contain data and returns it.
 *
 * @param Unum UART module to use for reception.
 * @return u8  Received 8-bit data.
 */
u8 UART_Read(UART_Module Unum);

void Get_Command(u8* input);

/* UART Flag Register (FR) bit definitions */
#define UART_FR_TXFF 0x20 /**< Transmit FIFO full */
#define UART_FR_RXEF 0x10 /**< Receive FIFO empty */

/* UART Data Register mask */
#define UART_DR_DATA_MUSK 0xFF /**< Mask to extract 8-bit data from UART_DR_R */

/* Logic level definitions */
#define HIGH 1
#define LOW 0

#endif /* UART_DRIVER_H */
