/*
 * Measurements.h
 *
 *  Created on: 29.04.2017
 *      Author: Krzysztof
 */

#ifndef MEASUREMENTS_H_
#define MEASUREMENTS_H_

#include "stm32f3xx_hal.h"
#include "main.h"

volatile s_measurements g_Measurements;

HAL_StatusTypeDef StartMeasurementsDMA();
HAL_StatusTypeDef StopMeasurementsDMA();

#endif /* MEASUREMENTS_H_ */
