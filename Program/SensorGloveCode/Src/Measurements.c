/*
 * Measurements.c
 *
 *  Created on: 29.04.2017
 *      Author: Krzysztof
 */

#include "adc.h"
#include "dma.h"

#include "MeasurementStruct.h"
#include "Measurements.h"

HAL_StatusTypeDef StartMeasurementsDMA()
{
	HAL_StatusTypeDef ADCStatus;
	ADCStatus=HAL_ADC_Start_DMA(&hadc2,(uint32_t*)g_Measurements.FlexSensor,FLEX_SENSOR_COUNT);
	if(ADCStatus != HAL_OK)
		return ADCStatus;
	ADCStatus=HAL_ADC_Start_DMA(&hadc3,(uint32_t*)g_Measurements.TensionSensor,TENSION_SENSOR_COUNT);
	return ADCStatus;
}

HAL_StatusTypeDef StopMeasurementsDMA()
{
	HAL_StatusTypeDef ADCStatus;
	ADCStatus=HAL_ADC_Stop_DMA(&hadc2);
	if(ADCStatus != HAL_OK)
		return ADCStatus;
	ADCStatus=HAL_ADC_Stop_DMA(&hadc3);
	return ADCStatus;
}
