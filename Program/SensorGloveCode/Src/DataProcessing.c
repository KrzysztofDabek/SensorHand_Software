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

uint16_t g_ThumbMinReadings[3] = {2500,1850,1850};
uint16_t g_ThumbMaxReadings[3] = {2130,2500,2500};
float g_ThumbMinAngles[3] = {0.0,0.0,0.0};
float g_ThumbMaxAngles[3] = {90.0,45.0,70.0};

uint16_t g_IndexMinReadings[3] = {1920,1800,1800};
uint16_t g_IndexMaxReadings[3] = {2760,3200,3200};
float g_IndexMinAngles[3] = {0.0,0.0,0.0};
float g_IndexMaxAngles[3] = {85.0,130.0,55.0};

uint16_t g_MiddleMinReadings[3] = {1920,1650,1650};
uint16_t g_MiddleMaxReadings[3] = {2650,2880,2880};
float g_MiddleMinAngles[3] = {0.0,0.0,0.0};
float g_MiddleMaxAngles[3] = {90.0,120.0,70.0};

uint16_t g_RingMinReadings[3] = {1750,1560,1560};
uint16_t g_RingMaxReadings[3] = {2300,2300,2300};
float g_RingMinAngles[3] = {0.0,0.0,0.0};
float g_RingMaxAngles[3] = {80.0,100.0,85.0};

uint16_t g_PinkyMinReadings[3] = {1520,1440,1440};
uint16_t g_PinkyMaxReadings[3] = {2580,2930,2930};
float g_PinkyMinAngles[3] = {0.0,0.0,0.0};
float g_PinkyMaxAngles[3] = {90.0,90.0,90.0};

float UnfilteredValue;
float LowPassFilterBeta;

void ApproximateFlexMeasurementsLinear()
{
	//Thumb
	UnfilteredValue =  g_Measurements.FlexSensor[0] *
			(g_ThumbMinAngles[0]-g_ThumbMaxAngles[0]) / (g_ThumbMinReadings[0]-g_ThumbMaxReadings[0]) + g_ThumbMinAngles[0] -
			(g_ThumbMinAngles[0]-g_ThumbMaxAngles[0]) / (g_ThumbMinReadings[0]-g_ThumbMaxReadings[0]) * g_ThumbMinReadings[0];
	g_Finger[0].Joint[0] = g_Finger[0].Joint[0] - (LowPassFilterBeta*(g_Finger[0].Joint[0] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[1] *
				(g_ThumbMinAngles[1]-g_ThumbMaxAngles[1]) / (g_ThumbMinReadings[1]-g_ThumbMaxReadings[1]) + g_ThumbMinAngles[1] -
				(g_ThumbMinAngles[1]-g_ThumbMaxAngles[1]) / (g_ThumbMinReadings[1]-g_ThumbMaxReadings[1]) * g_ThumbMinReadings[1];
	g_Finger[0].Joint[1] = g_Finger[0].Joint[1] - (LowPassFilterBeta*(g_Finger[0].Joint[1] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[1] *
				(g_ThumbMinAngles[2]-g_ThumbMaxAngles[2]) / (g_ThumbMinReadings[2]-g_ThumbMaxReadings[2]) + g_ThumbMinAngles[2] -
				(g_ThumbMinAngles[2]-g_ThumbMaxAngles[2]) / (g_ThumbMinReadings[2]-g_ThumbMaxReadings[2]) * g_ThumbMinReadings[2];
	g_Finger[0].Joint[2] = g_Finger[0].Joint[2] - (LowPassFilterBeta*(g_Finger[0].Joint[2] - UnfilteredValue));

	//index
	UnfilteredValue =  g_Measurements.FlexSensor[2] *
			(g_IndexMinAngles[0]-g_IndexMaxAngles[0]) / (g_IndexMinReadings[0]-g_IndexMaxReadings[0]) + g_IndexMinAngles[0] -
			(g_IndexMinAngles[0]-g_IndexMaxAngles[0]) / (g_IndexMinReadings[0]-g_IndexMaxReadings[0]) * g_IndexMinReadings[0];
	g_Finger[1].Joint[0] = g_Finger[1].Joint[0] - (LowPassFilterBeta*(g_Finger[1].Joint[0] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[3] *
				(g_IndexMinAngles[1]-g_IndexMaxAngles[1]) / (g_IndexMinReadings[1]-g_IndexMaxReadings[1]) + g_IndexMinAngles[1] -
				(g_IndexMinAngles[1]-g_IndexMaxAngles[1]) / (g_IndexMinReadings[1]-g_IndexMaxReadings[1]) * g_IndexMinReadings[1];
	g_Finger[1].Joint[1] = g_Finger[1].Joint[1] - (LowPassFilterBeta*(g_Finger[1].Joint[1] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[3] *
				(g_IndexMinAngles[2]-g_IndexMaxAngles[2]) / (g_IndexMinReadings[2]-g_IndexMaxReadings[2]) + g_IndexMinAngles[2] -
				(g_IndexMinAngles[2]-g_IndexMaxAngles[2]) / (g_IndexMinReadings[2]-g_IndexMaxReadings[2]) * g_IndexMinReadings[2];
	g_Finger[1].Joint[2] = g_Finger[1].Joint[2] - (LowPassFilterBeta*(g_Finger[1].Joint[2] - UnfilteredValue));

	//middle
	UnfilteredValue =  g_Measurements.FlexSensor[4] *
			(g_MiddleMinAngles[0]-g_MiddleMaxAngles[0]) / (g_MiddleMinReadings[0]-g_MiddleMaxReadings[0]) + g_MiddleMinAngles[0] -
			(g_MiddleMinAngles[0]-g_MiddleMaxAngles[0]) / (g_MiddleMinReadings[0]-g_MiddleMaxReadings[0]) * g_MiddleMinReadings[0];
	g_Finger[2].Joint[0] = g_Finger[2].Joint[0] - (LowPassFilterBeta*(g_Finger[2].Joint[0] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[5] *
				(g_MiddleMinAngles[1]-g_MiddleMaxAngles[1]) / (g_MiddleMinReadings[1]-g_MiddleMaxReadings[1]) + g_MiddleMinAngles[1] -
				(g_MiddleMinAngles[1]-g_MiddleMaxAngles[1]) / (g_MiddleMinReadings[1]-g_MiddleMaxReadings[1]) * g_MiddleMinReadings[1];
	g_Finger[2].Joint[1] = g_Finger[2].Joint[1] - (LowPassFilterBeta*(g_Finger[2].Joint[1] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[5] *
				(g_MiddleMinAngles[2]-g_MiddleMaxAngles[2]) / (g_MiddleMinReadings[2]-g_MiddleMaxReadings[2]) + g_MiddleMinAngles[2] -
				(g_MiddleMinAngles[2]-g_MiddleMaxAngles[2]) / (g_MiddleMinReadings[2]-g_MiddleMaxReadings[2]) * g_MiddleMinReadings[2];
	g_Finger[2].Joint[2] = g_Finger[2].Joint[2] - (LowPassFilterBeta*(g_Finger[2].Joint[2] - UnfilteredValue));

	//ring
	UnfilteredValue =  g_Measurements.FlexSensor[6] *
			(g_RingMinAngles[0]-g_RingMaxAngles[0]) / (g_RingMinReadings[0]-g_RingMaxReadings[0]) + g_RingMinAngles[0] -
			(g_RingMinAngles[0]-g_RingMaxAngles[0]) / (g_RingMinReadings[0]-g_RingMaxReadings[0]) * g_RingMinReadings[0];
	g_Finger[3].Joint[0] = g_Finger[3].Joint[0] - (LowPassFilterBeta*(g_Finger[3].Joint[0] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[7] *
				(g_RingMinAngles[1]-g_RingMaxAngles[1]) / (g_RingMinReadings[1]-g_RingMaxReadings[1]) + g_RingMinAngles[1] -
				(g_RingMinAngles[1]-g_RingMaxAngles[1]) / (g_RingMinReadings[1]-g_RingMaxReadings[1]) * g_RingMinReadings[1];
	g_Finger[3].Joint[1] = g_Finger[3].Joint[1] - (LowPassFilterBeta*(g_Finger[3].Joint[1] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[7] *
				(g_RingMinAngles[2]-g_RingMaxAngles[2]) / (g_RingMinReadings[2]-g_RingMaxReadings[2]) + g_RingMinAngles[2] -
				(g_RingMinAngles[2]-g_RingMaxAngles[2]) / (g_RingMinReadings[2]-g_RingMaxReadings[2]) * g_RingMinReadings[2];
	g_Finger[3].Joint[2] = g_Finger[3].Joint[2] - (LowPassFilterBeta*(g_Finger[3].Joint[2] - UnfilteredValue));

	//Pinky
	UnfilteredValue =  g_Measurements.FlexSensor[8] *
			(g_PinkyMinAngles[0]-g_PinkyMaxAngles[0]) / (g_PinkyMinReadings[0]-g_PinkyMaxReadings[0]) + g_PinkyMinAngles[0] -
			(g_PinkyMinAngles[0]-g_PinkyMaxAngles[0]) / (g_PinkyMinReadings[0]-g_PinkyMaxReadings[0]) * g_PinkyMinReadings[0];
	g_Finger[4].Joint[0] = g_Finger[4].Joint[0] - (LowPassFilterBeta*(g_Finger[4].Joint[0] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[9] *
				(g_PinkyMinAngles[1]-g_PinkyMaxAngles[1]) / (g_PinkyMinReadings[1]-g_PinkyMaxReadings[1]) + g_PinkyMinAngles[1] -
				(g_PinkyMinAngles[1]-g_PinkyMaxAngles[1]) / (g_PinkyMinReadings[1]-g_PinkyMaxReadings[1]) * g_PinkyMinReadings[1];
	g_Finger[4].Joint[1] = g_Finger[4].Joint[1] - (LowPassFilterBeta*(g_Finger[4].Joint[1] - UnfilteredValue));

	UnfilteredValue =  g_Measurements.FlexSensor[9] *
				(g_PinkyMinAngles[2]-g_PinkyMaxAngles[2]) / (g_PinkyMinReadings[2]-g_PinkyMaxReadings[2]) + g_PinkyMinAngles[2] -
				(g_PinkyMinAngles[2]-g_PinkyMaxAngles[2]) / (g_PinkyMinReadings[2]-g_PinkyMaxReadings[2]) * g_PinkyMinReadings[2];
	g_Finger[4].Joint[2] = g_Finger[4].Joint[2] - (LowPassFilterBeta*(g_Finger[4].Joint[2] - UnfilteredValue));
}

void AggregateMeasurementsToVoltage()
{
	for (uint8_t i = 0; i < FLEX_SENSOR_COUNT; ++i)
	{
		 UnfilteredValue = (float) SUPPLY_VOLTAGE
				* g_Measurements.FlexSensor[i] / ADC_RESOLUTION;
		 g_AggregatedMeasurements.FlexSensor[i] = g_AggregatedMeasurements.FlexSensor[i] -
				 (LowPassFilterBeta*(g_AggregatedMeasurements.FlexSensor[i] - UnfilteredValue));
	}
	/*for (uint8_t i = 0; i < TENSION_SENSOR_COUNT; ++i)
		g_AggregatedMeasurements.TensionSensor[i] = (float) SUPPLY_VOLTAGE
				* g_Measurements.TensionSensor[i] / ADC_RESOLUTION; //(float)pow(2,hadc2.Init.Resolution);*/
}

void AggregateTensionMeasurementsToColourCode()
{
	for (uint8_t i = 0; i < TENSION_SENSOR_COUNT; ++i)
	{
			UnfilteredValue = 255 - g_Measurements.TensionSensor[i] * 255 / 4095;
			g_AggregatedMeasurements.TensionSensor[i] = g_AggregatedMeasurements.TensionSensor[i] -
					 (LowPassFilterBeta*(g_AggregatedMeasurements.TensionSensor[i] - UnfilteredValue));
	}
}

void AggregateAccMeasurementsTo_mps2()
{
	for (uint8_t i = 0; i < ACCELEROMETER_AXIS_COUNT; ++i)
	{
		UnfilteredValue =
				(float) g_Measurements.Accelerometer[i]
						* LSM303_ACC_RESOLUTION_MPS2 / (float) INT16_MAX;
		g_AggregatedMeasurements.Accelerometer[i] = g_AggregatedMeasurements.Accelerometer[i] -
				 (LowPassFilterBeta*(g_AggregatedMeasurements.Accelerometer[i] - UnfilteredValue));
	}
}

void ApproximateAccMeasurementsRPY()
{
	UnfilteredValue = 0.0;//atan(g_Measurements.Accelerometer[1]/g_Measurements.Accelerometer[2]);
	g_AggregatedMeasurements.RPYangles[0] = g_AggregatedMeasurements.RPYangles[0] -
			 (LowPassFilterBeta*(g_AggregatedMeasurements.RPYangles[0] - UnfilteredValue));

	if(g_Measurements.Accelerometer[2] > 0)
		UnfilteredValue = -(M_PI/2 + atan(-g_Measurements.Accelerometer[0]/
			sqrt( pow(g_Measurements.Accelerometer[1],2)+pow(g_Measurements.Accelerometer[2],2))));
	else
		UnfilteredValue = M_PI/2 + atan(-g_Measurements.Accelerometer[0]/
			sqrt( pow(g_Measurements.Accelerometer[1],2)+pow(g_Measurements.Accelerometer[2],2)));
	g_AggregatedMeasurements.RPYangles[1] = g_AggregatedMeasurements.RPYangles[1] -
			 (LowPassFilterBeta*(g_AggregatedMeasurements.RPYangles[1] - UnfilteredValue));

	g_AggregatedMeasurements.RPYangles[2] = 0.0;
	g_AggregatedMeasurements.RPYangles[2] = g_AggregatedMeasurements.RPYangles[2] -
			 (LowPassFilterBeta*(g_AggregatedMeasurements.RPYangles[2] - UnfilteredValue));
}

void AggregateMeasurements()
{

	switch (g_TransmissionDevice)
	{
	case BluetoothDevice:
		LowPassFilterBeta = 0.1;
		break;
	case UARTSerialDevice:
		LowPassFilterBeta = 0.04;
		break;
	case USBDevice:
		LowPassFilterBeta = 0.02;
		break;
	}
	AggregateMeasurementsToVoltage();
	ApproximateFlexMeasurementsLinear();
	AggregateTensionMeasurementsToColourCode();
	AggregateAccMeasurementsTo_mps2();
	ApproximateAccMeasurementsRPY();
}
