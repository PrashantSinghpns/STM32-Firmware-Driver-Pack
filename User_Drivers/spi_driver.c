#include "spi_driver.h"

/*
 * Function: SPI_Driver_Transmit
 * -----------------------------
 * Transmits data using SPI in blocking mode.
 */
SPI_DriverStatus_t SPI_Driver_Transmit(SPI_HandleTypeDef *hspi,
                                       uint8_t *data,
                                       uint16_t size,
                                       uint32_t timeout)
{
    HAL_StatusTypeDef status;

    status = HAL_SPI_Transmit(hspi, data, size, timeout);

    if (status == HAL_OK)
    {
        return SPI_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        return SPI_DRIVER_TIMEOUT;
    }

    return SPI_DRIVER_ERROR;
}

/*
 * Function: SPI_Driver_Receive
 * ----------------------------
 * Receives data using SPI in blocking mode.
 */
SPI_DriverStatus_t SPI_Driver_Receive(SPI_HandleTypeDef *hspi,
                                      uint8_t *data,
                                      uint16_t size,
                                      uint32_t timeout)
{
    HAL_StatusTypeDef status;

    status = HAL_SPI_Receive(hspi, data, size, timeout);

    if (status == HAL_OK)
    {
        return SPI_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        return SPI_DRIVER_TIMEOUT;
    }

    return SPI_DRIVER_ERROR;
}

/*
 * Function: SPI_Driver_TransmitReceive
 * ------------------------------------
 * Transmits and receives data at the same time using SPI.
 *
 * SPI is full-duplex, so transmit and receive can happen together.
 */
SPI_DriverStatus_t SPI_Driver_TransmitReceive(SPI_HandleTypeDef *hspi,
                                              uint8_t *tx_data,
                                              uint8_t *rx_data,
                                              uint16_t size,
                                              uint32_t timeout)
{
    HAL_StatusTypeDef status;

    status = HAL_SPI_TransmitReceive(hspi,
                                     tx_data,
                                     rx_data,
                                     size,
                                     timeout);

    if (status == HAL_OK)
    {
        return SPI_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        return SPI_DRIVER_TIMEOUT;
    }

    return SPI_DRIVER_ERROR;
}

/*
 * Function: SPI_Driver_CS_Low
 * ---------------------------
 * Pulls chip select pin LOW to select the SPI slave device.
 */
void SPI_Driver_CS_Low(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

/*
 * Function: SPI_Driver_CS_High
 * ----------------------------
 * Pulls chip select pin HIGH to deselect the SPI slave device.
 */
void SPI_Driver_CS_High(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
}
