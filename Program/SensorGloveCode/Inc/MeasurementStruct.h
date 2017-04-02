/*
 * MeasurementStruct.h
 *
 *  Created on: 02.04.2017
 *      Author: Krzysztof
 */

#ifndef MEASUREMENTSTRUCT_H_
#define MEASUREMENTSTRUCT_H_

typedef struct measurements
{
	uint16_t FlexSensor[6];
	uint16_t TensionSensor[3];
	uint16_t Accelerometer[3];
} measurements;

#endif /* MEASUREMENTSTRUCT_H_ */
