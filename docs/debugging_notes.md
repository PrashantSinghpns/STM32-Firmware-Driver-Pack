# Debugging Notes

This document contains common debugging steps for the STM32-Firmware-Driver-Pack project.

Debugging is an important part of embedded firmware development because most issues come from configuration, wiring, clock setup, pin mapping, or missing source/include files.

---

## Common Build Issues

### Header file not found

Example error:

```text
fatal error: gpio_driver.h: No such file or directory
```

Possible reasons:

* `User_Drivers/` folder is not added to include path
* File name is misspelled
* Header file is not inside the correct folder

Fix:

* Add `User_Drivers/` to project include paths
* Check file name and folder path
* Clean and rebuild the project

---

### Undefined reference error

Example error:

```text
undefined reference to GPIO_Driver_TogglePin
```

Possible reasons:

* `.c` file is not added to the project build
* Function name mismatch between `.h` and `.c`
* Source file is excluded from build

Fix:

* Make sure the driver `.c` file is inside the project
* Check function spelling
* Right click file and ensure it is not excluded from build

---

## GPIO Debugging

Common issues:

* LED not blinking
* Button not reading correctly
* Pin always HIGH or LOW

Check:

* GPIO clock is enabled
* Correct GPIO port is selected
* Correct GPIO pin is selected
* Pin mode is correct
* Pull-up or pull-down setting is correct
* External wiring is correct

Example:

```c
__HAL_RCC_GPIOA_CLK_ENABLE();
```

---

## UART Debugging

Common issues:

* No serial output
* Garbage characters on terminal
* UART transmit not working

Check:

* Correct COM port is selected
* Baud rate is same in STM32 and terminal
* TX/RX pins are configured correctly
* UART peripheral is initialized
* USB cable supports data transfer
* Ground is common if using external USB-to-UART converter

Common UART setting:

```text
Baud Rate: 115200
Data Bits: 8
Parity: None
Stop Bits: 1
Flow Control: None
```

---

## I2C Debugging

Common issues:

* Sensor not responding
* Received value is 0x00 or 0xFF
* I2C timeout error

Check:

* SDA and SCL wiring
* Pull-up resistors on SDA and SCL
* Correct I2C address
* Address is shifted left by 1 when using STM32 HAL
* Sensor power voltage is correct
* Common ground is connected
* Correct register address is used

Example:

```c
#define SENSOR_ADDRESS  0x68

I2C_Driver_ReadRegister(&hi2c1,
                        SENSOR_ADDRESS << 1,
                        WHO_AM_I_REGISTER,
                        &sensor_id,
                        1,
                        1000);
```

---

## SPI Debugging

Common issues:

* No response from SPI device
* Response always 0x00
* Response always 0xFF
* Wrong data received

Check:

* MOSI, MISO, SCK, and CS wiring
* Correct SPI mode
* Correct clock polarity and phase
* Correct chip select pin
* Chip select is pulled LOW before transfer
* Chip select is pulled HIGH after transfer
* SPI speed is not too high
* Device datasheet command is correct

Example:

```c
SPI_Driver_CS_Low(GPIOA, GPIO_PIN_4);

SPI_Driver_TransmitReceive(&hspi1,
                           tx_data,
                           rx_data,
                           4,
                           1000);

SPI_Driver_CS_High(GPIOA, GPIO_PIN_4);
```

---

## ADC Debugging

Common issues:

* ADC value always 0
* ADC value always 4095
* ADC value is unstable

Check:

* ADC pin is configured in analog mode
* Correct ADC channel is selected
* ADC initialization function is called
* Input voltage is within allowed range
* Sensor ground and STM32 ground are common
* Analog input is not floating

For 12-bit ADC:

```text
Minimum value = 0
Maximum value = 4095
```

Voltage formula:

```text
Voltage = (ADC_Value / 4095) × 3.3
```

---

## ADC DMA Debugging

Common issues:

* ADC buffer not updating
* DMA error
* Only first value updates

Check:

* DMA is enabled for ADC
* DMA mode is circular
* `MX_DMA_Init()` is called before `MX_ADC1_Init()`
* ADC is configured for DMA
* Buffer size is correct
* Buffer data type matches DMA configuration

Example:

```c
HAL_ADC_Start_DMA(&hadc1,
                  adc_buffer,
                  ADC_BUFFER_SIZE);
```

---

## Debugging Tools

Useful debugging tools:

* STM32CubeIDE debugger
* Watch window
* Live expressions
* Breakpoints
* UART serial logs
* Logic analyzer
* Oscilloscope
* Multimeter

---

## General Debugging Checklist

Before assuming the code is wrong, check:

* Board is powered
* Correct board is selected
* Correct programmer/debugger is selected
* Firmware is flashed successfully
* Peripheral clock is enabled
* GPIO pin mapping is correct
* Initialization function is called
* Driver `.c` file is added
* Driver `.h` file path is included
* Wires are connected properly
* Common ground is connected
* Datasheet values are checked

---

## Summary

Most STM32 firmware issues happen because of missing clock enable, wrong pin configuration, missing include path, incorrect peripheral initialization, or wiring mistakes.

Debugging should be done step by step:

```text
Build check → Flash check → Peripheral init check → Pin check → Runtime variable check → Hardware signal check
```
