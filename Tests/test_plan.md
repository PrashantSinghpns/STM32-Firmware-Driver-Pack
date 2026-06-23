# Test Plan

This document defines the basic testing plan for the STM32-Firmware-Driver-Pack project.

Each driver module should be tested using a small example application before being considered complete.

---

## Test Environment

| Item        | Details                                         |
| ----------- | ----------------------------------------------- |
| IDE         | STM32CubeIDE                                    |
| Language    | Embedded C                                      |
| Framework   | STM32 HAL                                       |
| Debugger    | ST-Link                                         |
| Board       | STM32 Nucleo / STM32F4-based board              |
| Serial Tool | PuTTY / Tera Term / STM32CubeIDE Serial Monitor |

---

## Driver Test Checklist

| Module    | Test Case            | Expected Result                      | Status  |
| --------- | -------------------- | ------------------------------------ | ------- |
| GPIO      | LED blink            | LED toggles every 500 ms             | Pending |
| UART      | Print log message    | Message appears on serial terminal   | Pending |
| I2C       | Read sensor register | Correct register value is received   | Pending |
| SPI       | Read device ID       | SPI response buffer receives data    | Pending |
| ADC       | Read analog input    | ADC value changes with input voltage | Pending |
| ADC + DMA | Fill ADC buffer      | Buffer updates automatically         | Pending |

---

## GPIO Test

### Objective

Verify that GPIO output control works correctly.

### Steps

1. Configure LED pin as GPIO output.
2. Toggle the LED pin every 500 ms.
3. Flash the firmware.
4. Observe LED blinking.

### Expected Result

The LED should blink continuously.

---

## UART Test

### Objective

Verify UART logging output.

### Steps

1. Configure UART baud rate as 115200.
2. Open serial terminal.
3. Print startup message.
4. Print repeated log message every 1 second.

### Expected Result

The serial terminal should display log messages correctly.

---

## I2C Test

### Objective

Verify I2C register read communication.

### Steps

1. Connect an I2C sensor.
2. Configure I2C peripheral.
3. Read sensor ID or known register.
4. Check the received value.

### Expected Result

The received value should match the expected register value from the sensor datasheet.

---

## SPI Test

### Objective

Verify SPI transmit/receive communication.

### Steps

1. Connect SPI device.
2. Configure SPI mode according to device datasheet.
3. Pull chip select LOW.
4. Send command byte.
5. Read response buffer.
6. Pull chip select HIGH.

### Expected Result

The SPI receive buffer should contain valid response data.

---

## ADC Polling Test

### Objective

Verify ADC analog input reading using polling mode.

### Steps

1. Connect potentiometer output to ADC input pin.
2. Configure ADC channel.
3. Read ADC value using polling.
4. Rotate potentiometer.
5. Observe ADC value in debugger.

### Expected Result

ADC value should change from low to high as input voltage changes.

---

## ADC DMA Test

### Objective

Verify ADC data transfer using DMA.

### Steps

1. Enable ADC.
2. Enable DMA for ADC.
3. Set DMA mode to circular.
4. Start ADC DMA conversion.
5. Watch ADC buffer in debugger.

### Expected Result

ADC buffer should update automatically without continuous CPU polling.

---

## Common Build Checks

Before testing each module, verify:

* Project builds without errors
* Correct header file is included
* Source file is added to build
* Include path is configured
* Peripheral clock is enabled
* CubeIDE generated initialization function is called
* Correct GPIO pins are selected

---

## Common Debug Checks

During debugging, check:

* Variable values in Watch window
* Return status of driver functions
* Peripheral initialization
* Pin configuration
* Clock configuration
* UART terminal settings
* Sensor wiring
* Logic analyzer output if available

---

## Completion Criteria

A driver module is considered complete when:

* Driver source file is added
* Driver header file is added
* Documentation is added
* Example README is added
* Example builds successfully
* Expected test output is verified
* Troubleshooting notes are documented

---

## Current Status

| Module    | Driver             | Docs                | Example | Test Status           |
| --------- | ------------------ | ------------------- | ------- | --------------------- |
| GPIO      | Done               | Done                | Done    | Pending hardware test |
| UART      | Done               | Done                | Done    | Pending hardware test |
| I2C       | Done               | Done                | Done    | Pending hardware test |
| SPI       | Done               | Done                | Done    | Pending hardware test |
| ADC       | Done               | Done                | Done    | Pending hardware test |
| ADC + DMA | Basic example done | Included in example | Done    | Pending hardware test |
