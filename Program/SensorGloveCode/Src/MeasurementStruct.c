/*
 * MeasurementStruct.c
 *
 *  Created on: 02.04.2017
 *      Author: Krzysztof
 */
#include "usart.h"
#include "MeasurementStruct.h"

HAL_StatusTypeDef TransmitMeasurementsBluetooth(s_measurements p_Measurements)
{
	uint8_t i;
	uint8_t OutputData[2];
	uint16_t MessageSize;
	for(i=0;i<FLEX_SENSOR_COUNT;++i)
	{
		MessageSize=sprintf(OutputData,"%d ",p_Measurements.FlexSensor[i]);
		if(HAL_UART_Transmit_IT(&huart4,OutputData,MessageSize)==HAL_ERROR)
			return HAL_ERROR;
	}
	MessageSize=sprintf(OutputData,"\n\r");
	if(HAL_UART_Transmit_IT(&huart4,OutputData,MessageSize)==HAL_ERROR)
		return HAL_ERROR;
	for(i=0;i<TENSION_SENSOR_COUNT;++i)
	{
		MessageSize=sprintf(OutputData,"%d ",p_Measurements.TensionSensor[i]);
		if(HAL_UART_Transmit_IT(&huart4,OutputData,MessageSize)==HAL_ERROR)
			return HAL_ERROR;
	}
	MessageSize=sprintf(OutputData,"\n\r");
	if(HAL_UART_Transmit_IT(&huart4,OutputData,MessageSize)==HAL_ERROR)
		return HAL_ERROR;
	for(i=0;i<ACCELEROMETER_AXIS_COUNT;++i)
	{
		MessageSize=sprintf(OutputData,"%d ",p_Measurements.Accelerometer[i]);
		if(HAL_UART_Transmit_IT(&huart4,OutputData,MessageSize)==HAL_ERROR)
			return HAL_ERROR;
	}
	MessageSize=sprintf(OutputData,"\n\r");
	if(HAL_UART_Transmit_IT(&huart4,OutputData,MessageSize)==HAL_ERROR)
		return HAL_ERROR;
	return HAL_OK;
}
