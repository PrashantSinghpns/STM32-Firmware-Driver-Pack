# STM32-Firmware-Driver-Pack

A modular STM32 firmware driver pack built in Embedded C for learning, experimentation, and reusable firmware development.

This project contains clean driver modules, example applications, documentation, and testing notes for commonly used STM32 peripherals such as GPIO, UART, I2C, SPI, ADC, and DMA.

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
* STM32 HAL-based firmware development

---

## Features

* GPIO driver for digital input/output control
* UART driver for serial communication and logging
* I2C driver for sensor communication
* SPI driver for external device communication
* ADC driver for analog signal reading
* ADC + DMA example for efficient data transfer
* Example applications for each module
* Testing and debugging documentation

---

## Repository Structure

```text
STM32-Firmware-Driver-Pack/
├── README.md
├── docs/
│   ├── architecture.md
│   ├── gpio_driver.md
│   ├── uart_driver.md
│   ├── i2c_driver.md
│   ├── spi_driver.md
│   ├── adc_driver.md
│   └── debugging_notes.md
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
│   └── adc_driver.h
├── Examples/
│   ├── 01_gpio_led_blink/
│   ├── 02_uart_logging/
│   ├── 03_i2c_sensor_read/
│   ├── 04_spi_device_read/
│   ├── 05_adc_polling_read/
│   └── 06_adc_dma_read/
└── Tests/
    └── test_plan.md
```

---

## Driver Modules

| Module    | Description                                                      |
| --------- | ---------------------------------------------------------------- |
| GPIO      | Digital input, output, pin read, pin write, and toggle           |
| UART      | Serial transmit, receive, and debug logging                      |
| I2C       | Sensor/device register read and write                            |
| SPI       | SPI transmit, receive, transmit/receive, and chip select control |
| ADC       | Analog input reading and voltage conversion                      |
| ADC + DMA | Continuous ADC buffer reading using DMA                          |

---

## Example Applications

| Example             | Description                            |
| ------------------- | -------------------------------------- |
| 01_gpio_led_blink   | Blink LED using GPIO driver            |
| 02_uart_logging     | Print debug logs using UART            |
| 03_i2c_sensor_read  | Read sensor register using I2C         |
| 04_spi_device_read  | Communicate with SPI device            |
| 05_adc_polling_read | Read analog input using ADC polling    |
| 06_adc_dma_read     | Read ADC values continuously using DMA |

---

## Tools Used

* STM32CubeIDE
* STM32 HAL
* CMSIS
* Embedded C
* GCC ARM Toolchain
* Git and GitHub
* Serial terminal for UART debugging

---

## Documentation

| Document           | Purpose                         |
| ------------------ | ------------------------------- |
| architecture.md    | Explains firmware architecture  |
| gpio_driver.md     | Explains GPIO driver            |
| uart_driver.md     | Explains UART driver            |
| i2c_driver.md      | Explains I2C driver             |
| spi_driver.md      | Explains SPI driver             |
| adc_driver.md      | Explains ADC driver             |
| debugging_notes.md | Contains common debugging steps |
| test_plan.md       | Contains driver test checklist  |

---

## Development Status

| Module    | Driver        | Docs | Example |
| --------- | ------------- | ---- | ------- |
| GPIO      | Done          | Done | Done    |
| UART      | Done          | Done | Done    |
| I2C       | Done          | Done | Done    |
| SPI       | Done          | Done | Done    |
| ADC       | Done          | Done | Done    |
| ADC + DMA | Example-based | Done | Done    |

---

## Notes

This project uses STM32 HAL as the lower-level hardware abstraction layer. The custom user drivers are written as reusable wrapper modules to simplify application-level firmware development.

The project structure is inspired by STM32Cube firmware organization, where drivers, examples, and documentation are separated into clear folders. STM32CubeF4 includes reusable software components for STM32F4 development, and STM32Cube examples commonly separate shared libraries and example projects.

---

## License

This project is released under the MIT License.

---

## Disclaimer

This is an educational and portfolio firmware project. It is not an official STMicroelectronics project.
