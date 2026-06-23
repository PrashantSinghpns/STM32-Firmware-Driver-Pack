# SPI Driver

This document explains the SPI driver used in the STM32-Firmware-Driver-Pack project.

The SPI driver provides reusable APIs for communicating with SPI-based devices such as displays, flash memory, sensors, external ADCs, and wireless modules.

---

## Purpose

SPI stands for Serial Peripheral Interface.

SPI is a synchronous serial communication protocol commonly used for high-speed communication between a microcontroller and external devices.

SPI commonly uses four lines:

- MOSI: Master Out Slave In
- MISO: Master In Slave Out
- SCK: Serial Clock
- CS/SS: Chip Select or Slave Select

---

## Driver Files

```text
User_Drivers/
├── spi_driver.c
└── spi_driver.h
Features

The SPI driver supports:

SPI transmit
SPI receive
SPI transmit and receive
Blocking mode communication
Timeout handling
Basic status return
Manual chip select control
API List
SPI_Driver_Transmit()

Transmits bytes over SPI.

SPI_DriverStatus_t SPI_Driver_Transmit(SPI_HandleTypeDef *hspi,
                                       uint8_t *data,
                                       uint16_t size,
                                       uint32_t timeout);

Example:

uint8_t tx_data[] = {0x9F};

SPI_Driver_Transmit(&hspi1,
                    tx_data,
                    1,
                    1000);
SPI_Driver_Receive()

Receives bytes over SPI.

SPI_DriverStatus_t SPI_Driver_Receive(SPI_HandleTypeDef *hspi,
                                      uint8_t *data,
                                      uint16_t size,
                                      uint32_t timeout);

Example:

uint8_t rx_data[3];

SPI_Driver_Receive(&hspi1,
                   rx_data,
                   3,
                   1000);
SPI_Driver_TransmitReceive()

Transmits and receives bytes at the same time.

SPI_DriverStatus_t SPI_Driver_TransmitReceive(SPI_HandleTypeDef *hspi,
                                              uint8_t *tx_data,
                                              uint8_t *rx_data,
                                              uint16_t size,
                                              uint32_t timeout);

Example:

uint8_t tx_data[2] = {0x80, 0x00};
uint8_t rx_data[2] = {0};

SPI_Driver_TransmitReceive(&hspi1,
                           tx_data,
                           rx_data,
                           2,
                           1000);
SPI_Driver_CS_Low()

Selects the SPI slave device.

void SPI_Driver_CS_Low(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

Example:

SPI_Driver_CS_Low(GPIOA, GPIO_PIN_4);
SPI_Driver_CS_High()

Deselects the SPI slave device.

void SPI_Driver_CS_High(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

Example:

SPI_Driver_CS_High(GPIOA, GPIO_PIN_4);
SPI Device Read Example
#include "stm32f4xx_hal.h"
#include "spi_driver.h"

extern SPI_HandleTypeDef hspi1;

#define SPI_CS_PORT    GPIOA
#define SPI_CS_PIN     GPIO_PIN_4

int main(void)
{
    uint8_t tx_data[2] = {0x9F, 0x00};
    uint8_t rx_data[2] = {0};

    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_SPI1_Init();

    SPI_Driver_CS_Low(SPI_CS_PORT, SPI_CS_PIN);

    SPI_Driver_TransmitReceive(&hspi1,
                               tx_data,
                               rx_data,
                               2,
                               1000);

    SPI_Driver_CS_High(SPI_CS_PORT, SPI_CS_PIN);

    while (1)
    {
    }
}
Notes
SPI is commonly full-duplex.
The master generates the clock signal.
Chip select is usually active LOW.
Each SPI slave device should have its own chip select pin.
SPI mode depends on clock polarity and clock phase.
For simple drivers, chip select can be controlled manually using GPIO.
For advanced use, interrupt-based or DMA-based SPI can be added later.
