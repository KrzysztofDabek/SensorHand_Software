/*
 * DataProcessing.c
 *
 *  Created on: 29.04.2017
 *      Author: Krzysztof
 */

#include "math.h"
#include "adc.h"
#include "dma.h"
#include "MeasurementStruct.h"
#include "Measurements.h"
#include "DataProcessing.h"

void AggregateMeasurementsToVoltage()
{
	for(uint8_t i=0; i<FLEX_SENSOR_COUNT;++i)
		g_VoltageMeasurements.FlexSensor[i]=
				(float)SUPPLY_VOLTAGE * g_Measurements.FlexSensor[i] / 4095;//(float)pow(2,hadc2.Init.Resolution);
	for(uint8_t i=0; i<TENSION_SENSOR_COUNT; ++i)
		g_VoltageMeasurements.TensionSensor[i]=
				(float)SUPPLY_VOLTAGE * g_Measurements.TensionSensor[i] / 4095;//(float)pow(2,hadc2.Init.Resolution);
	for(uint8_t i=0; i<ACCELEROMETER_AXIS_COUNT; ++i)
		;/*g_VoltageMeasurements.Accelerometer[i]=
				(float) g_Measurements.Accelerometer[i]* LSM303_ACC_RESOLUTION) / (float)INT16_MAX;*/
}
