#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/*
 * I2C Driver
 * ----------
 * This file contains reusable I2C APIs for STM32.
 * The driver is built on top of STM32 HAL.
 */

/* I2C driver status */
typedef enum
{
    I2C_DRIVER_OK = 0,
    I2C_DRIVER_ERROR,
    I2C_DRIVER_TIMEOUT
} I2C_DriverStatus_t;

/* Function declarations */
I2C_DriverStatus_t I2C_Driver_MasterTransmit(I2C_HandleTypeDef *hi2c,
                                             uint16_t device_address,
                                             uint8_t *data,
                                             uint16_t size,
                                             uint32_t timeout);

I2C_DriverStatus_t I2C_Driver_MasterReceive(I2C_HandleTypeDef *hi2c,
                                            uint16_t device_address,
                                            uint8_t *data,
                                            uint16_t size,
                                            uint32_t timeout);

I2C_DriverStatus_t I2C_Driver_WriteRegister(I2C_HandleTypeDef *hi2c,
                                            uint16_t device_address,
                                            uint16_t register_address,
                                            uint8_t *data,
                                            uint16_t size,
                                            uint32_t timeout);

I2C_DriverStatus_t I2C_Driver_ReadRegister(I2C_HandleTypeDef *hi2c,
                                           uint16_t device_address,
                                           uint16_t register_address,
                                           uint8_t *data,
                                           uint16_t size,
                                           uint32_t timeout);

#endif
