```c
#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f4xx_hal.h"

/*
 * GPIO Driver
 * -----------
 * This file contains reusable GPIO APIs for STM32.
 * The driver is built on top of STM32 HAL.
 */

/* GPIO pin mode options */
typedef enum
{
    GPIO_DRIVER_MODE_INPUT = 0,
    GPIO_DRIVER_MODE_OUTPUT,
    GPIO_DRIVER_MODE_ANALOG,
    GPIO_DRIVER_MODE_INTERRUPT_RISING,
    GPIO_DRIVER_MODE_INTERRUPT_FALLING,
    GPIO_DRIVER_MODE_INTERRUPT_RISING_FALLING
} GPIO_DriverMode_t;

/* GPIO pull-up / pull-down options */
typedef enum
{
    GPIO_DRIVER_NOPULL = 0,
    GPIO_DRIVER_PULLUP,
    GPIO_DRIVER_PULLDOWN
} GPIO_DriverPull_t;

/* GPIO output speed options */
typedef enum
{
    GPIO_DRIVER_SPEED_LOW = 0,
    GPIO_DRIVER_SPEED_MEDIUM,
    GPIO_DRIVER_SPEED_HIGH,
    GPIO_DRIVER_SPEED_VERY_HIGH
} GPIO_DriverSpeed_t;

/* Function declarations */
void GPIO_Driver_Init(GPIO_TypeDef *GPIOx,
                      uint16_t GPIO_Pin,
                      GPIO_DriverMode_t mode,
                      GPIO_DriverPull_t pull,
                      GPIO_DriverSpeed_t speed);

void GPIO_Driver_WritePin(GPIO_TypeDef *GPIOx,
                          uint16_t GPIO_Pin,
                          GPIO_PinState state);

GPIO_PinState GPIO_Driver_ReadPin(GPIO_TypeDef *GPIOx,
                                  uint16_t GPIO_Pin);

void GPIO_Driver_TogglePin(GPIO_TypeDef *GPIOx,
                           uint16_t GPIO_Pin);

#endif
```

--
