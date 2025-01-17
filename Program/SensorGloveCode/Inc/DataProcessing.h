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

typedef enum DeviceType_t{BluetoothDevice, UARTSerialDevice, USBDevice} DeviceType_t;

volatile DeviceType_t g_TransmissionDevice;
volatile s_AggregatedMeasurements g_AggregatedMeasurements;
volatile s_JointAngles g_Finger[FINGER_COUNT];

/*float* BaseFunction(int p_indicator, float* p_x);
float** GenerateD(float* p_x,int p_k);
float** Generate*/

void ApproximateFlexMeasurementsLinear();
void AggregateMeasurementsToVoltage();
void AggregateAccMeasurementsTo_mps2();
void ApproximateAccMeasurementsRPY();
void AggregateMeasurements();

void ProcessDataForOutput();

#endif /* DATAPROCESSING_H_ */
