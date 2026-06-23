File: User_Drivers/uart_driver.c
#include "uart_driver.h"
#include <string.h>

/*
 * Function: UART_Driver_Transmit
 * ------------------------------
 * Transmits data using UART in blocking mode.
 *
 * Parameters:
 * huart   : UART handle, example &huart2
 * data    : pointer to data buffer
 * size    : number of bytes to transmit
 * timeout : timeout duration in milliseconds
 */
UART_DriverStatus_t UART_Driver_Transmit(UART_HandleTypeDef *huart,
                                         uint8_t *data,
                                         uint16_t size,
                                         uint32_t timeout)
{
    if (HAL_UART_Transmit(huart, data, size, timeout) == HAL_OK)
    {
        return UART_DRIVER_OK;
    }

    return UART_DRIVER_ERROR;
}

/*
 * Function: UART_Driver_Receive
 * -----------------------------
 * Receives data using UART in blocking mode.
 *
 * Parameters:
 * huart   : UART handle, example &huart2
 * data    : pointer to receive buffer
 * size    : number of bytes to receive
 * timeout : timeout duration in milliseconds
 */
UART_DriverStatus_t UART_Driver_Receive(UART_HandleTypeDef *huart,
                                        uint8_t *data,
                                        uint16_t size,
                                        uint32_t timeout)
{
    HAL_StatusTypeDef status;

    status = HAL_UART_Receive(huart, data, size, timeout);

    if (status == HAL_OK)
    {
        return UART_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        return UART_DRIVER_TIMEOUT;
    }

    return UART_DRIVER_ERROR;
}

/*
 * Function: UART_Driver_Print
 * ---------------------------
 * Sends a null-terminated string using UART.
 *
 * Parameters:
 * huart   : UART handle, example &huart2
 * message : string to transmit
 */
UART_DriverStatus_t UART_Driver_Print(UART_HandleTypeDef *huart,
                                      char *message)
{
    return UART_Driver_Transmit(huart,
                                (uint8_t *)message,
                                strlen(message),
                                HAL_MAX_DELAY);
}
