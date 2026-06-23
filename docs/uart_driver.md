# UART Driver

This document explains the UART driver used in the STM32-Firmware-Driver-Pack project.

The UART driver provides reusable APIs for serial communication and debug logging.

---

## Purpose

UART stands for Universal Asynchronous Receiver/Transmitter.

UART is commonly used for:

- Debug logging
- Serial terminal communication
- GPS modules
- GSM modules
- Bluetooth modules
- Wi-Fi modules
- Microcontroller-to-microcontroller communication

---

## Driver Files

```text
User_Drivers/
├── uart_driver.c
└── uart_driver.h
Features

The UART driver supports:

UART transmit
UART receive
String printing
Blocking mode communication
Timeout handling
Basic status return
API List
UART_Driver_Transmit()

Transmits bytes over UART.

UART_DriverStatus_t UART_Driver_Transmit(UART_HandleTypeDef *huart,
                                         uint8_t *data,
                                         uint16_t size,
                                         uint32_t timeout);

Example:

uint8_t message[] = "Hello STM32\r\n";

UART_Driver_Transmit(&huart2,
                     message,
                     sizeof(message) - 1,
                     HAL_MAX_DELAY);
UART_Driver_Receive()

Receives bytes over UART.

UART_DriverStatus_t UART_Driver_Receive(UART_HandleTypeDef *huart,
                                        uint8_t *data,
                                        uint16_t size,
                                        uint32_t timeout);

Example:

uint8_t rx_data;

UART_Driver_Receive(&huart2,
                    &rx_data,
                    1,
                    1000);
UART_Driver_Print()

Prints a string over UART.

UART_DriverStatus_t UART_Driver_Print(UART_HandleTypeDef *huart,
                                      char *message);

Example:

UART_Driver_Print(&huart2, "System started\r\n");
UART Logging Example
#include "stm32f4xx_hal.h"
#include "uart_driver.h"

extern UART_HandleTypeDef huart2;

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_USART2_UART_Init();

    UART_Driver_Print(&huart2, "STM32 UART Logging Started\r\n");

    while (1)
    {
        UART_Driver_Print(&huart2, "System running...\r\n");
        HAL_Delay(1000);
    }
}
Expected Output

Open a serial terminal with the same baud rate configured in STM32CubeIDE.

Example baud rate:

115200

Expected serial output:

STM32 UART Logging Started
System running...
System running...
System running...
Notes
UART baud rate must match between STM32 and serial terminal.
Common baud rate: 115200.
TX and RX pins must be correctly configured.
HAL_UART_Transmit() is blocking in this basic driver.
For advanced use, interrupt-based UART or DMA-based UART can be added later.
