# STM32-Firmware-Driver-Pack

A modular STM32 firmware driver pack built in Embedded C for learning, experimentation, and reusable firmware development.

This project contains clean driver modules, example applications, documentation, and testing notes for commonly used STM32 peripherals such as GPIO, UART, I2C, SPI, ADC, DMA, Timers, PWM, Interrupts, and Watchdog.

---

## Project Overview

The goal of this project is to build a reusable firmware driver pack for STM32 microcontrollers using a clean and organized project structure.

The project focuses on:

* Modular firmware design
* Peripheral driver development
* Clean Embedded C APIs
* Hardware abstraction
* Example-based learning
* Debugging and testing documentation
* Industry-style firmware organization

The project structure is inspired by STM32Cube firmware package organization, but the user driver code and documentation are written independently.

---

## Features

* GPIO driver for digital input/output control
* UART driver for serial communication and logging
* I2C driver for sensor communication
* SPI driver for external device communication
* ADC driver for analog signal reading
* DMA example for efficient data transfer
* Timer and PWM driver examples
* External interrupt handling
* Button debounce logic
* Watchdog timer example
* Application-level firmware modules
* Documentation and testing notes

---

## Repository Structure

```text
STM32-Firmware-Driver-Pack/
│
├── README.md
│
├── docs/
│   ├── architecture.md
│   ├── gpio_driver.md
│   ├── uart_driver.md
│   ├── i2c_driver.md
│   ├── spi_driver.md
│   ├── adc_dma.md
│   ├── timer_pwm.md
│   ├── interrupts.md
│   ├── watchdog.md
│   └── debugging_notes.md
│
├── Core/
│   ├── Inc/
│   └── Src/
│
├── Drivers/
│   ├── BSP/
│   ├── CMSIS/
│   └── STM32_HAL/
│
├── App/
│   ├── app_main.c
│   ├── sensor_app.c
│   └── logger_app.c
│
├── User_Drivers/
│   ├── gpio_driver.c
│   ├── gpio_driver.h
│   ├── uart_driver.c
│   ├── uart_driver.h
│   ├── i2c_driver.c
│   ├── i2c_driver.h
│   ├── spi_driver.c
│   ├── spi_driver.h
│   ├── adc_driver.c
│   ├── adc_driver.h
│   ├── dma_driver.c
│   ├── dma_driver.h
│   ├── timer_driver.c
│   ├── timer_driver.h
│   ├── watchdog_driver.c
│   └── watchdog_driver.h
│
├── Examples/
│   ├── 01_gpio_led_blink/
│   ├── 02_uart_logging/
│   ├── 03_i2c_sensor_read/
│   ├── 04_spi_device_read/
│   ├── 05_adc_dma_read/
│   ├── 06_timer_pwm_output/
│   ├── 07_interrupt_button/
│   └── 08_watchdog_reset/
│
└── Tests/
    └── test_plan.md
```

---

## Driver Modules

### GPIO Driver

The GPIO driver provides APIs for configuring and controlling STM32 GPIO pins.

Planned functions:

* GPIO pin initialization
* Digital write
* Digital read
* Pin toggle
* Input mode configuration
* Output mode configuration
* Pull-up and pull-down configuration

Example:

```c
GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUTPUT);
GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
GPIO_TogglePin(LED_PORT, LED_PIN);
```

---

### UART Driver

The UART driver provides APIs for serial communication and debug logging.

Planned functions:

* UART initialization
* Transmit character
* Transmit string
* Receive data
* UART logging
* Interrupt-based receive
* Ring buffer support

Example:

```c
UART_Init(&huart2, 115200);
UART_Print("System started\r\n");
```

---

### I2C Driver

The I2C driver provides APIs for communicating with sensors and external I2C devices.

Planned functions:

* I2C initialization
* Register write
* Register read
* Multi-byte read
* Multi-byte write
* Error handling

Example:

```c
I2C_ReadRegister(I2C1, SENSOR_ADDR, TEMP_REG, &temperature);
```

---

### SPI Driver

The SPI driver provides APIs for communicating with SPI-based devices such as displays, flash memory, and sensors.

Planned functions:

* SPI initialization
* SPI transmit
* SPI receive
* SPI transmit/receive
* Chip select control

Example:

```c
SPI_TransmitReceive(SPI1, tx_buffer, rx_buffer, length);
```

---

### ADC Driver

The ADC driver provides APIs for reading analog signals from sensors.

Planned functions:

* ADC initialization
* Single channel read
* Multi-channel read
* ADC calibration
* ADC value conversion

Example:

```c
uint16_t adc_value = ADC_ReadChannel(ADC_CHANNEL_0);
```

---

### DMA Example

The DMA module demonstrates efficient data transfer without continuous CPU involvement.

Planned examples:

* ADC with DMA
* Circular buffer mode
* DMA transfer complete callback
* Buffer-based sensor data acquisition

Example:

```c
ADC_DMA_Start(adc_buffer, ADC_BUFFER_SIZE);
```

---

### Timer and PWM Driver

The Timer/PWM module demonstrates timer-based delay, periodic events, and PWM signal generation.

Planned functions:

* Timer initialization
* PWM start
* PWM stop
* Duty cycle update
* Timer interrupt callback

Example:

```c
PWM_Start(TIM3, PWM_CHANNEL_1);
PWM_SetDutyCycle(TIM3, PWM_CHANNEL_1, 50);
```

---

### Interrupt Handling

The interrupt examples demonstrate external interrupt handling using GPIO pins.

Planned concepts:

* External interrupt configuration
* ISR callback handling
* Volatile flags
* Button interrupt
* Software debounce

Example:

```c
volatile uint8_t button_pressed = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    button_pressed = 1;
}
```

---

### Watchdog Driver

The watchdog module demonstrates basic system safety and recovery concepts.

Planned functions:

* Watchdog initialization
* Watchdog refresh
* Fault simulation
* Reset behavior testing

Example:

```c
Watchdog_Init();
Watchdog_Refresh();
```

---

## Example Applications

| Example             | Description                                     |
| ------------------- | ----------------------------------------------- |
| 01_gpio_led_blink   | Blink an LED using GPIO output                  |
| 02_uart_logging     | Send debug logs using UART                      |
| 03_i2c_sensor_read  | Read sensor data using I2C                      |
| 04_spi_device_read  | Communicate with an SPI device                  |
| 05_adc_dma_read     | Read analog data using ADC and DMA              |
| 06_timer_pwm_output | Generate PWM signal using timer                 |
| 07_interrupt_button | Handle button press using external interrupt    |
| 08_watchdog_reset   | Demonstrate watchdog refresh and reset behavior |

---

## Tools Used

* STM32CubeIDE
* STM32 HAL
* CMSIS
* Embedded C
* GCC ARM Toolchain
* Git and GitHub
* Logic analyzer or serial terminal for debugging

---

## Documentation

The `docs/` folder contains notes for each driver module.

Planned documentation:

* Firmware architecture
* GPIO driver explanation
* UART driver explanation
* I2C driver explanation
* SPI driver explanation
* ADC and DMA notes
* Timer and PWM notes
* Interrupt handling notes
* Watchdog notes
* Debugging notes

---

## License

This project is released under the MIT License.

---

## Disclaimer

This project is created for educational firmware development and hands-on embedded systems practice. It is not an official STMicroelectronics project.
