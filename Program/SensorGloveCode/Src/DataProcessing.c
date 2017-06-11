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
#include "Accelerometer.h"
#include "DataProcessing.h"

void AggregateMeasurementsToVoltage()
{
	for (uint8_t i = 0; i < FLEX_SENSOR_COUNT; ++i)
		g_AggregatedMeasurements.FlexSensor[i] = (float) SUPPLY_VOLTAGE
				* g_Measurements.FlexSensor[i] / ADC_RESOLUTION; //(float)pow(2,hadc2.Init.Resolution);
	float nocnik = g_AggregatedMeasurements.FlexSensor[4];
	g_AggregatedMeasurements.FlexSensor[4] = g_AggregatedMeasurements.FlexSensor[5];
	g_AggregatedMeasurements.FlexSensor[5] = nocnik;
	/*for (uint8_t i = 0; i < TENSION_SENSOR_COUNT; ++i)
		g_AggregatedMeasurements.TensionSensor[i] = (float) SUPPLY_VOLTAGE
				* g_Measurements.TensionSensor[i] / ADC_RESOLUTION; //(float)pow(2,hadc2.Init.Resolution);*/
}

void AggregateTensionMeasurementsToColourCode()
{
	for (uint8_t i = 0; i < TENSION_SENSOR_COUNT; ++i)
			g_AggregatedMeasurements.TensionSensor[i] = 255 - g_Measurements.TensionSensor[i] * 255 / 4095;
	uint8_t nocnik = g_AggregatedMeasurements.TensionSensor[1];
	//Usunac po zamianie kanalow
	g_AggregatedMeasurements.TensionSensor[1] = g_AggregatedMeasurements.TensionSensor[2];
	g_AggregatedMeasurements.TensionSensor[2] = nocnik;
}

void AggregateAccMeasurementsTo_mps2()
{
	for (uint8_t i = 0; i < ACCELEROMETER_AXIS_COUNT; ++i)
		g_AggregatedMeasurements.Accelerometer[i] =
				(float) g_Measurements.Accelerometer[i]
						* LSM303_ACC_RESOLUTION_MPS2 / (float) INT16_MAX;
}

void AggregateMeasurements()
{
	AggregateMeasurementsToVoltage();
	AggregateTensionMeasurementsToColourCode();
	AggregateAccMeasurementsTo_mps2();
}

void ProcessDataForOutput()
{

}
