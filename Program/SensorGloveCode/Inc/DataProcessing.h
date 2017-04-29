/*
 * DataProcessing.h
 *
 *  Created on: 29.04.2017
 *      Author: Krzysztof
 */

#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_

#include "stm32f3xx_hal.h"
#include "main.h"

#define SUPPLY_VOLTAGE 3.3 //V

volatile s_AggregatedMeasurements g_VoltageMeasurements;

void AggregateMeasurementsToVoltage();

#endif /* DATAPROCESSING_H_ */
