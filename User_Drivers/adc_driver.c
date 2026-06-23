
#include "adc_driver.h"
/*
 * Function: ADC_Driver_Start
 * --------------------------
 * Starts ADC conversion.
 */
ADC_DriverStatus_t ADC_Driver_Start(ADC_HandleTypeDef *hadc)
{
    if (HAL_ADC_Start(hadc) == HAL_OK)
    {
        return ADC_DRIVER_OK;
    }

    return ADC_DRIVER_ERROR;
}

/*
 * Function: ADC_Driver_Stop
 * -------------------------
 * Stops ADC conversion.
 */
ADC_DriverStatus_t ADC_Driver_Stop(ADC_HandleTypeDef *hadc)
{
    if (HAL_ADC_Stop(hadc) == HAL_OK)
    {
        return ADC_DRIVER_OK;
    }

    return ADC_DRIVER_ERROR;
}

/*
 * Function: ADC_Driver_ReadPolling
 * --------------------------------
 * Starts ADC, waits for conversion, reads ADC value, and stops ADC.
 *
 * Parameters:
 * hadc      : ADC handle, example &hadc1
 * adc_value : pointer to store ADC result
 * timeout   : timeout duration in milliseconds
 */
ADC_DriverStatus_t ADC_Driver_ReadPolling(ADC_HandleTypeDef *hadc,
                                          uint32_t *adc_value,
                                          uint32_t timeout)
{
    HAL_StatusTypeDef status;

    if (HAL_ADC_Start(hadc) != HAL_OK)
    {
        return ADC_DRIVER_ERROR;
    }

    status = HAL_ADC_PollForConversion(hadc, timeout);

    if (status == HAL_OK)
    {
        *adc_value = HAL_ADC_GetValue(hadc);
        HAL_ADC_Stop(hadc);
        return ADC_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        HAL_ADC_Stop(hadc);
        return ADC_DRIVER_TIMEOUT;
    }

    HAL_ADC_Stop(hadc);
    return ADC_DRIVER_ERROR;
}

/*
 * Function: ADC_Driver_ConvertToVoltage
 * -------------------------------------
 * Converts raw ADC value into voltage.
 *
 * Formula:
 * voltage = (adc_value / adc_max_value) * reference_voltage
 *
 * Example:
 * 12-bit ADC max value = 4095
 * reference voltage = 3.3V
 */
float ADC_Driver_ConvertToVoltage(uint32_t adc_value,
                                  float reference_voltage,
                                  uint32_t adc_resolution)
{
    uint32_t adc_max_value;

    adc_max_value = (1U << adc_resolution) - 1U;

    return ((float)adc_value / (float)adc_max_value) * reference_voltage;
}
