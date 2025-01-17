/*
 * MeasurementStruct.h
 *
 *  Created on: 02.04.2017
 *      Author: Krzysztof
 */

#ifndef MEASUREMENTSTRUCT_H_
#define MEASUREMENTSTRUCT_H_

#include "stm32f3xx_hal.h"
#include "main.h"

#define FINGER_JOINT_COUNT 3
#define FINGER_COUNT 5
#define FLEX_SENSOR_COUNT 10
#define TENSION_SENSOR_COUNT 5
#define ACCELEROMETER_AXIS_COUNT 3
#define RPY_COUNT 3
#define SENSOR_COUNT (FLEX_SENSOR_COUNT+TENSION_SENSOR_COUNT+ACCELEROMETER_AXIS_COUNT)


typedef struct s_measurements
{
	uint16_t FlexSensor[FLEX_SENSOR_COUNT];
	uint16_t TensionSensor[TENSION_SENSOR_COUNT];
	int16_t Accelerometer[ACCELEROMETER_AXIS_COUNT];
} s_measurements;

typedef struct s_AggregatedMeasurements
{
	float FlexSensor[FLEX_SENSOR_COUNT];
	uint8_t TensionSensor[TENSION_SENSOR_COUNT];
	float Accelerometer[ACCELEROMETER_AXIS_COUNT];
	float RPYangles[RPY_COUNT];
} s_AggregatedMeasurements;

typedef struct s_JointAngles
{
	float Joint[FINGER_JOINT_COUNT];
} s_JointAngles;

#endif /* MEASUREMENTSTRUCT_H_ */
