#include "gpio_driver.h"

/*
 * Function: GPIO_Driver_Init
 * --------------------------
 * Initializes a GPIO pin using STM32 HAL.
 *
 * Parameters:
 * GPIOx    : GPIO port, example GPIOA, GPIOB, GPIOC
 * GPIO_Pin : GPIO pin, example GPIO_PIN_5
 * mode     : input, output, analog, or interrupt mode
 * pull     : no pull, pull-up, or pull-down
 * speed    : output speed
 */
void GPIO_Driver_Init(GPIO_TypeDef *GPIOx,
                      uint16_t GPIO_Pin,
                      GPIO_DriverMode_t mode,
                      GPIO_DriverPull_t pull,
                      GPIO_DriverSpeed_t speed)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = GPIO_Pin;

    /* Configure GPIO mode */
    switch (mode)
    {
        case GPIO_DRIVER_MODE_INPUT:
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
            break;

        case GPIO_DRIVER_MODE_OUTPUT:
            GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
            break;

        case GPIO_DRIVER_MODE_ANALOG:
            GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
            break;

        case GPIO_DRIVER_MODE_INTERRUPT_RISING:
            GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
            break;

        case GPIO_DRIVER_MODE_INTERRUPT_FALLING:
            GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
            break;

        case GPIO_DRIVER_MODE_INTERRUPT_RISING_FALLING:
            GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
            break;

        default:
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
            break;
    }

    /* Configure pull-up / pull-down */
    switch (pull)
    {
        case GPIO_DRIVER_NOPULL:
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            break;

        case GPIO_DRIVER_PULLUP:
            GPIO_InitStruct.Pull = GPIO_PULLUP;
            break;

        case GPIO_DRIVER_PULLDOWN:
            GPIO_InitStruct.Pull = GPIO_PULLDOWN;
            break;

        default:
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            break;
    }

    /* Configure GPIO speed */
    switch (speed)
    {
        case GPIO_DRIVER_SPEED_LOW:
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
            break;

        case GPIO_DRIVER_SPEED_MEDIUM:
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
            break;

        case GPIO_DRIVER_SPEED_HIGH:
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
            break;

        case GPIO_DRIVER_SPEED_VERY_HIGH:
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
            break;

        default:
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
            break;
    }

    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

/*
 * Function: GPIO_Driver_WritePin
 * ------------------------------
 * Writes HIGH or LOW to a GPIO output pin.
 */
void GPIO_Driver_WritePin(GPIO_TypeDef *GPIOx,
                          uint16_t GPIO_Pin,
                          GPIO_PinState state)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, state);
}

/*
 * Function: GPIO_Driver_ReadPin
 * -----------------------------
 * Reads the current state of a GPIO input pin.
 */
GPIO_PinState GPIO_Driver_ReadPin(GPIO_TypeDef *GPIOx,
                                  uint16_t GPIO_Pin)
{
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

/*
 * Function: GPIO_Driver_TogglePin
 * -------------------------------
 * Toggles the state of a GPIO output pin.
 */
void GPIO_Driver_TogglePin(GPIO_TypeDef *GPIOx,
                           uint16_t GPIO_Pin)
{
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}
