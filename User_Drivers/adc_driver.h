#ifndef ADC_DRIVER_H
#define ADC_DRIVER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/*
 * ADC Driver
 * ----------
 * This file contains reusable ADC APIs for STM32.
 * The driver is built on top of STM32 HAL.
 */

/* ADC driver status */
typedef enum
{
    ADC_DRIVER_OK = 0,
    ADC_DRIVER_ERROR,
    ADC_DRIVER_TIMEOUT
} ADC_DriverStatus_t;

/* Function declarations */
ADC_DriverStatus_t ADC_Driver_Start(ADC_HandleTypeDef *hadc);

ADC_DriverStatus_t ADC_Driver_Stop(ADC_HandleTypeDef *hadc);

ADC_DriverStatus_t ADC_Driver_ReadPolling(ADC_HandleTypeDef *hadc,
                                          uint32_t *adc_value,
                                          uint32_t timeout);

float ADC_Driver_ConvertToVoltage(uint32_t adc_value,
                                  float reference_voltage,
                                  uint32_t adc_resolution);

#endif
