#include "i2c_driver.h"

/*
 * Function: I2C_Driver_MasterTransmit
 * -----------------------------------
 * Transmits data to an I2C slave device in blocking mode.
 */
I2C_DriverStatus_t I2C_Driver_MasterTransmit(I2C_HandleTypeDef *hi2c,
                                             uint16_t device_address,
                                             uint8_t *data,
                                             uint16_t size,
                                             uint32_t timeout)
{
    HAL_StatusTypeDef status;

    status = HAL_I2C_Master_Transmit(hi2c,
                                     device_address,
                                     data,
                                     size,
                                     timeout);

    if (status == HAL_OK)
    {
        return I2C_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        return I2C_DRIVER_TIMEOUT;
    }

    return I2C_DRIVER_ERROR;
}

/*
 * Function: I2C_Driver_MasterReceive
 * ----------------------------------
 * Receives data from an I2C slave device in blocking mode.
 */
I2C_DriverStatus_t I2C_Driver_MasterReceive(I2C_HandleTypeDef *hi2c,
                                            uint16_t device_address,
                                            uint8_t *data,
                                            uint16_t size,
                                            uint32_t timeout)
{
    HAL_StatusTypeDef status;

    status = HAL_I2C_Master_Receive(hi2c,
                                    device_address,
                                    data,
                                    size,
                                    timeout);

    if (status == HAL_OK)
    {
        return I2C_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        return I2C_DRIVER_TIMEOUT;
    }

    return I2C_DRIVER_ERROR;
}

/*
 * Function: I2C_Driver_WriteRegister
 * ----------------------------------
 * Writes data to a specific register of an I2C device.
 *
 * Note:
 * For 7-bit I2C device addresses, STM32 HAL usually expects
 * the address shifted left by 1 bit before passing it.
 * Example: 0x68 becomes 0x68 << 1
 */
I2C_DriverStatus_t I2C_Driver_WriteRegister(I2C_HandleTypeDef *hi2c,
                                            uint16_t device_address,
                                            uint16_t register_address,
                                            uint8_t *data,
                                            uint16_t size,
                                            uint32_t timeout)
{
    HAL_StatusTypeDef status;

    status = HAL_I2C_Mem_Write(hi2c,
                               device_address,
                               register_address,
                               I2C_MEMADD_SIZE_8BIT,
                               data,
                               size,
                               timeout);

    if (status == HAL_OK)
    {
        return I2C_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        return I2C_DRIVER_TIMEOUT;
    }

    return I2C_DRIVER_ERROR;
}

/*
 * Function: I2C_Driver_ReadRegister
 * ---------------------------------
 * Reads data from a specific register of an I2C device.
 *
 * Note:
 * For 7-bit I2C device addresses, STM32 HAL usually expects
 * the address shifted left by 1 bit before passing it.
 * Example: 0x68 becomes 0x68 << 1
 */
I2C_DriverStatus_t I2C_Driver_ReadRegister(I2C_HandleTypeDef *hi2c,
                                           uint16_t device_address,
                                           uint16_t register_address,
                                           uint8_t *data,
                                           uint16_t size,
                                           uint32_t timeout)
{
    HAL_StatusTypeDef status;

    status = HAL_I2C_Mem_Read(hi2c,
                              device_address,
                              register_address,
                              I2C_MEMADD_SIZE_8BIT,
                              data,
                              size,
                              timeout);

    if (status == HAL_OK)
    {
        return I2C_DRIVER_OK;
    }
    else if (status == HAL_TIMEOUT)
    {
        return I2C_DRIVER_TIMEOUT;
    }

    return I2C_DRIVER_ERROR;
}
