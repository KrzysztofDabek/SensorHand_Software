/*
 * Accelerometer.c
 *
 *  Created on: 02.05.2017
 *      Author: Krzysztof
 */

#include <limits.h>

#include "i2c.h"
#include "Accelerometer.h"
#include "MeasurementStruct.h"
#include "Measurements.h"

HAL_StatusTypeDef StartAccelerometerMeasurements()
{
	HAL_StatusTypeDef I2C_Status;
	I2C_Status = HAL_I2C_Mem_Write(&hi2c1, LSM303_ACC_ADDRESS,
			LSM303_ACC_CTRL_REG1_A,
			ACC_MEMORY_ADD_SIZE, g_LSM303_Settings, ACC_START_MESSAGE_SIZE,
			I2C_TIMEOUT);
	return I2C_Status;
}

HAL_StatusTypeDef GetAccelerometerData()
 {
	uint8_t RawAccelerometerData[ACC_RAW_DATA_SIZE];
	HAL_StatusTypeDef I2C_Status;

	I2C_Status = HAL_I2C_Mem_Read(&hi2c1, LSM303_ACC_ADDRESS,
			LSM303_ACC_X_L_A_MULTI_READ,
			ACC_MEMORY_ADD_SIZE, RawAccelerometerData, ACC_RAW_DATA_SIZE,
			I2C_TIMEOUT);
	if(I2C_Status!= HAL_OK)
		return I2C_Status;

	g_Measurements.Accelerometer[0] = ((RawAccelerometerData[1] << 8) | RawAccelerometerData[0]);
	g_Measurements.Accelerometer[1] = ((RawAccelerometerData[3] << 8) | RawAccelerometerData[2]);
	g_Measurements.Accelerometer[2] = ((RawAccelerometerData[5] << 8) | RawAccelerometerData[4]);
	return I2C_Status;
}
