# ADC Driver
This document explains the ADC driver used in the STM32-Firmware-Driver-Pack project.

The ADC driver provides reusable APIs for reading analog signals from sensors using STM32 ADC peripherals.

---

## Purpose

ADC stands for Analog-to-Digital Converter.

ADC is used to convert analog voltage into a digital value that can be processed by the microcontroller.

ADC is commonly used with:

- Potentiometers
- Temperature sensors
- Light sensors
- Pressure sensors
- Battery voltage monitoring
- Analog joysticks
- Current sensors

---

## Driver Files

```text
User_Drivers/
├── adc_driver.c
└── adc_driver.h
Features

The ADC driver supports:

ADC start
ADC stop
Single ADC reading in polling mode
Timeout handling
Raw ADC value reading
ADC value to voltage conversion
Basic status return
API List
ADC_Driver_Start()

Starts ADC conversion.

ADC_DriverStatus_t ADC_Driver_Start(ADC_HandleTypeDef *hadc);

Example:

ADC_Driver_Start(&hadc1);
ADC_Driver_Stop()

Stops ADC conversion.

ADC_DriverStatus_t ADC_Driver_Stop(ADC_HandleTypeDef *hadc);

Example:

ADC_Driver_Stop(&hadc1);
ADC_Driver_ReadPolling()

Starts ADC conversion, waits for conversion completion, reads ADC value, and stops ADC.

ADC_DriverStatus_t ADC_Driver_ReadPolling(ADC_HandleTypeDef *hadc,
                                          uint32_t *adc_value,
                                          uint32_t timeout);

Example:

uint32_t adc_value = 0;

ADC_Driver_ReadPolling(&hadc1,
                       &adc_value,
                       1000);
ADC_Driver_ConvertToVoltage()

Converts raw ADC value into voltage.

float ADC_Driver_ConvertToVoltage(uint32_t adc_value,
                                  float reference_voltage,
                                  uint32_t adc_resolution);

Example:

float voltage;

voltage = ADC_Driver_ConvertToVoltage(adc_value,
                                      3.3f,
                                      12);
ADC Polling Example
#include "stm32f4xx_hal.h"
#include "adc_driver.h"

extern ADC_HandleTypeDef hadc1;

int main(void)
{
    uint32_t adc_value = 0;
    float voltage = 0.0f;

    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_ADC1_Init();

    while (1)
    {
        ADC_Driver_ReadPolling(&hadc1,
                               &adc_value,
                               1000);

        voltage = ADC_Driver_ConvertToVoltage(adc_value,
                                              3.3f,
                                              12);

        HAL_Delay(500);
    }
}
Expected Output

There is no UART or LED output in this basic example.

Expected result:

adc_value changes according to analog input voltage
voltage shows calculated input voltage

You can check values using:

STM32CubeIDE debugger
Watch window
Live expression
UART logging
Voltage Conversion Formula

For a 12-bit ADC:

ADC maximum value = 4095
Reference voltage = 3.3V

Formula:

Voltage = (ADC_Value / 4095) × 3.3

Example:

ADC_Value = 2048
Voltage ≈ 1.65V
Notes
ADC pin must be configured in analog mode.
ADC reference voltage affects measurement accuracy.
For 12-bit ADC, digital output range is usually 0 to 4095.
Polling mode is simple but blocks CPU while waiting.
For continuous high-speed sampling, DMA is better.
ADC readings may fluctuate, so averaging/filtering can be added later.
