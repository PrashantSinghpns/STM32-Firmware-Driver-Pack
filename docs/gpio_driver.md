# GPIO Driver

This document explains the GPIO driver used in the STM32-Firmware-Driver-Pack project.

The GPIO driver provides reusable APIs for configuring and controlling STM32 GPIO pins.

---

## Purpose

GPIO stands for General Purpose Input/Output.

GPIO pins are used to connect external components such as:

- LEDs
- Buttons
- Sensors
- Relays
- Buzzers
- External interrupt sources

---

## Driver Files

```text
User_Drivers/
├── gpio_driver.c
└── gpio_driver.h
Features

The GPIO driver supports:

GPIO input mode
GPIO output mode
GPIO analog mode
GPIO external interrupt mode
Pull-up configuration
Pull-down configuration
Pin write
Pin read
Pin toggle
API List
GPIO_Driver_Init()

Initializes a GPIO pin.

void GPIO_Driver_Init(GPIO_TypeDef *GPIOx,
                      uint16_t GPIO_Pin,
                      GPIO_DriverMode_t mode,
                      GPIO_DriverPull_t pull,
                      GPIO_DriverSpeed_t speed);

Example:

GPIO_Driver_Init(GPIOA,
                 GPIO_PIN_5,
                 GPIO_DRIVER_MODE_OUTPUT,
                 GPIO_DRIVER_NOPULL,
                 GPIO_DRIVER_SPEED_LOW);
GPIO_Driver_WritePin()

Writes HIGH or LOW to a GPIO output pin.

void GPIO_Driver_WritePin(GPIO_TypeDef *GPIOx,
                          uint16_t GPIO_Pin,
                          GPIO_PinState state);

Example:

GPIO_Driver_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
GPIO_Driver_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
GPIO_Driver_ReadPin()

Reads the state of a GPIO input pin.

GPIO_PinState GPIO_Driver_ReadPin(GPIO_TypeDef *GPIOx,
                                  uint16_t GPIO_Pin);

Example:

GPIO_PinState button_state;
button_state = GPIO_Driver_ReadPin(GPIOC, GPIO_PIN_13);
GPIO_Driver_TogglePin()

Toggles a GPIO output pin.

void GPIO_Driver_TogglePin(GPIO_TypeDef *GPIOx,
                           uint16_t GPIO_Pin);

Example:

GPIO_Driver_TogglePin(GPIOA, GPIO_PIN_5);
LED Blink Example
#include "gpio_driver.h"

int main(void)
{
    HAL_Init();

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_Driver_Init(GPIOA,
                     GPIO_PIN_5,
                     GPIO_DRIVER_MODE_OUTPUT,
                     GPIO_DRIVER_NOPULL,
                     GPIO_DRIVER_SPEED_LOW);

    while (1)
    {
        GPIO_Driver_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(500);
    }
}
Notes
GPIO clock must be enabled before using the GPIO pin.
Keep GPIO configuration separate from application logic.
Use meaningful names for ports and pins.
Avoid writing repeated HAL GPIO code everywhere in the application.
For interrupts, keep ISR code short and handle main logic outside the ISR.
