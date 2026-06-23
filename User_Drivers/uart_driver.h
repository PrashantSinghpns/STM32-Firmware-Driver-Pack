#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/*
 * UART Driver
 * -----------
 * This file contains reusable UART APIs for STM32.
 * The driver is built on top of STM32 HAL.
 */

/* UART driver status */
typedef enum
{
    UART_DRIVER_OK = 0,
    UART_DRIVER_ERROR,
    UART_DRIVER_TIMEOUT
} UART_DriverStatus_t;

/* Function declarations */
UART_DriverStatus_t UART_Driver_Transmit(UART_HandleTypeDef *huart,
                                         uint8_t *data,
                                         uint16_t size,
                                         uint32_t timeout);

UART_DriverStatus_t UART_Driver_Receive(UART_HandleTypeDef *huart,
                                        uint8_t *data,
                                        uint16_t size,
                                        uint32_t timeout);

UART_DriverStatus_t UART_Driver_Print(UART_HandleTypeDef *huart,
                                      char *message);

#endif
