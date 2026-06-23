```c
#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/*
 * SPI Driver
 * ----------
 * This file contains reusable SPI APIs for STM32.
 * The driver is built on top of STM32 HAL.
 */

/* SPI driver status */
typedef enum
{
    SPI_DRIVER_OK = 0,
    SPI_DRIVER_ERROR,
    SPI_DRIVER_TIMEOUT
} SPI_DriverStatus_t;

/* Function declarations */
SPI_DriverStatus_t SPI_Driver_Transmit(SPI_HandleTypeDef *hspi,
                                       uint8_t *data,
                                       uint16_t size,
                                       uint32_t timeout);

SPI_DriverStatus_t SPI_Driver_Receive(SPI_HandleTypeDef *hspi,
                                      uint8_t *data,
                                      uint16_t size,
                                      uint32_t timeout);

SPI_DriverStatus_t SPI_Driver_TransmitReceive(SPI_HandleTypeDef *hspi,
                                              uint8_t *tx_data,
                                              uint8_t *rx_data,
                                              uint16_t size,
                                              uint32_t timeout);

void SPI_Driver_CS_Low(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

void SPI_Driver_CS_High(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif
```

---
