# Firmware Architecture

This document explains the architecture of the STM32-Firmware-Driver-Pack project.

The project is organized into separate layers so that low-level peripheral code, application logic, examples, and documentation remain clean and easy to maintain.

---

## Architecture Overview

The firmware is divided into the following layers:

```text
Application Layer
        |
User Driver Layer
        |
STM32 HAL / CMSIS Layer
        |
Microcontroller Hardware
```

---

## 1. Application Layer

The application layer contains the main firmware logic.

This layer uses driver APIs instead of directly accessing low-level hardware functions everywhere.

Example files:

```text
App/
├── app_main.c
├── sensor_app.c
└── logger_app.c
```

Responsibilities:

* Initialize application modules
* Call user driver APIs
* Manage sensor reading
* Manage logging
* Handle application-level logic

Example:

```c
void App_Main(void)
{
    Logger_Init();
    Sensor_App_Init();

    while (1)
    {
        Sensor_App_Update();
        Logger_Task();
    }
}
```

---

## 2. User Driver Layer

The user driver layer contains reusable firmware modules written for different peripherals.

Example folder:

```text
User_Drivers/
├── gpio_driver.c
├── gpio_driver.h
├── uart_driver.c
├── uart_driver.h
├── i2c_driver.c
├── i2c_driver.h
├── spi_driver.c
├── spi_driver.h
├── adc_driver.c
├── adc_driver.h
├── dma_driver.c
├── dma_driver.h
├── timer_driver.c
├── timer_driver.h
├── watchdog_driver.c
└── watchdog_driver.h
```

Responsibilities:

* Provide clean APIs for peripherals
* Hide repeated low-level configuration
* Keep application code simple
* Improve code reuse
* Make testing easier

Example:

```c
GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
UART_Print("System started\r\n");
```

---

## 3. STM32 HAL / CMSIS Layer

This layer contains STM32 hardware abstraction and device-specific support files.

Example folder:

```text
Drivers/
├── BSP/
├── CMSIS/
└── STM32_HAL/
```

Responsibilities:

* Provide startup files
* Provide device headers
* Provide HAL functions
* Provide CMSIS core support
* Connect firmware code to STM32 hardware registers

The user drivers call HAL/CMSIS functions internally when required.

---

## 4. Hardware Layer

The hardware layer represents the actual STM32 microcontroller peripherals.

Examples:

* GPIO ports
* UART peripheral
* I2C peripheral
* SPI peripheral
* ADC peripheral
* DMA controller
* Timers
* Watchdog timer
* NVIC interrupt controller

---

## Data Flow Example

Example: UART logging flow

```text
Application Code
      |
UART_Print()
      |
uart_driver.c
      |
STM32 HAL UART API
      |
USART Peripheral
      |
Serial Terminal
```

---

## Interrupt Flow Example

Example: Button interrupt flow

```text
Button Press
      |
GPIO External Interrupt
      |
ISR Callback
      |
Volatile Flag Set
      |
Application Handles Event
```

The ISR should remain short. Heavy processing should be done in the main loop or application task.

---

## Design Rules

This project follows these firmware design rules:

* Keep driver code separate from application code
* Keep APIs simple and reusable
* Avoid writing large logic inside interrupts
* Use meaningful file names
* Use clear function names
* Document each driver module
* Test each peripheral using a small example
* Keep hardware-specific code isolated
* Avoid unnecessary code duplication

---

## Planned Driver API Style

Each driver will generally follow this pattern:

```c
Driver_Init();
Driver_Read();
Driver_Write();
Driver_Start();
Driver_Stop();
Driver_Callback();
```

Example:

```c
GPIO_Init();
GPIO_WritePin();
GPIO_ReadPin();
GPIO_TogglePin();
```

---

## Error Handling Strategy

Drivers should return status values wherever possible.

Example:

```c
typedef enum
{
    DRIVER_OK = 0,
    DRIVER_ERROR,
    DRIVER_BUSY,
    DRIVER_TIMEOUT
} Driver_Status_t;
```

This makes the code easier to debug and safer to use.

---

## Testing Strategy

Each driver will have a small example project inside the `Examples/` folder.

Example:

```text
Examples/
├── 01_gpio_led_blink/
├── 02_uart_logging/
├── 03_i2c_sensor_read/
├── 04_spi_device_read/
├── 05_adc_dma_read/
├── 06_timer_pwm_output/
├── 07_interrupt_button/
└── 08_watchdog_reset/
```

Each example will include:

* Objective
* Hardware requirement
* Pin configuration
* Expected output
* Test steps
* Debugging notes

---

## Summary

The STM32-Firmware-Driver-Pack follows a layered firmware architecture.

The main idea is to keep low-level drivers, application logic, examples, and documentation separate so that the project remains clean, reusable, and easy to expand.
