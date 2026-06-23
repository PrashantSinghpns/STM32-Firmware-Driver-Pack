# I2C Driver

This document explains the I2C driver used in the STM32-Firmware-Driver-Pack project.

The I2C driver provides reusable APIs for communicating with I2C-based sensors, memory devices, displays, and other peripherals.

---

## Purpose

I2C stands for Inter-Integrated Circuit.

I2C is a two-wire serial communication protocol commonly used for short-distance communication between microcontrollers and peripheral devices.

I2C uses:

- SDA: Serial Data Line
- SCL: Serial Clock Line

---

## Driver Files

```text
User_Drivers/
├── i2c_driver.c
└── i2c_driver.h
Features

The I2C driver supports:

I2C master transmit
I2C master receive
Register write
Register read
Blocking mode communication
Timeout handling
Basic status return
API List
I2C_Driver_MasterTransmit()

Transmits data to an I2C slave device.

I2C_DriverStatus_t I2C_Driver_MasterTransmit(I2C_HandleTypeDef *hi2c,
                                             uint16_t device_address,
                                             uint8_t *data,
                                             uint16_t size,
                                             uint32_t timeout);

Example:

uint8_t data = 0x01;

I2C_Driver_MasterTransmit(&hi2c1,
                          DEVICE_ADDRESS << 1,
                          &data,
                          1,
                          1000);
I2C_Driver_MasterReceive()

Receives data from an I2C slave device.

I2C_DriverStatus_t I2C_Driver_MasterReceive(I2C_HandleTypeDef *hi2c,
                                            uint16_t device_address,
                                            uint8_t *data,
                                            uint16_t size,
                                            uint32_t timeout);

Example:

uint8_t rx_data;

I2C_Driver_MasterReceive(&hi2c1,
                         DEVICE_ADDRESS << 1,
                         &rx_data,
                         1,
                         1000);
I2C_Driver_WriteRegister()

Writes data to a specific register of an I2C device.

I2C_DriverStatus_t I2C_Driver_WriteRegister(I2C_HandleTypeDef *hi2c,
                                            uint16_t device_address,
                                            uint16_t register_address,
                                            uint8_t *data,
                                            uint16_t size,
                                            uint32_t timeout);

Example:

uint8_t config_value = 0x01;

I2C_Driver_WriteRegister(&hi2c1,
                         SENSOR_ADDRESS << 1,
                         CONFIG_REGISTER,
                         &config_value,
                         1,
                         1000);
I2C_Driver_ReadRegister()

Reads data from a specific register of an I2C device.

I2C_DriverStatus_t I2C_Driver_ReadRegister(I2C_HandleTypeDef *hi2c,
                                           uint16_t device_address,
                                           uint16_t register_address,
                                           uint8_t *data,
                                           uint16_t size,
                                           uint32_t timeout);

Example:

uint8_t sensor_id;

I2C_Driver_ReadRegister(&hi2c1,
                        SENSOR_ADDRESS << 1,
                        WHO_AM_I_REGISTER,
                        &sensor_id,
                        1,
                        1000);
Sensor Register Read Example
#include "stm32f4xx_hal.h"
#include "i2c_driver.h"

extern I2C_HandleTypeDef hi2c1;

#define SENSOR_ADDRESS       0x68
#define WHO_AM_I_REGISTER    0x75

int main(void)
{
    uint8_t sensor_id = 0;

    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_I2C1_Init();

    I2C_Driver_ReadRegister(&hi2c1,
                            SENSOR_ADDRESS << 1,
                            WHO_AM_I_REGISTER,
                            &sensor_id,
                            1,
                            1000);

    while (1)
    {
    }
}
Notes
I2C requires pull-up resistors on SDA and SCL lines.
Common I2C speeds are 100 kHz and 400 kHz.
STM32 HAL commonly expects the 7-bit I2C address shifted left by 1 bit.
Use HAL_I2C_IsDeviceReady() when checking whether a device is connected.
For advanced use, interrupt-based or DMA-based I2C can be added later.
