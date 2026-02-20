/*
 * ADC.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_DRIVERS_ADC_H_
#define INC_DRIVERS_ADC_H_

#include <stdint.h>

#include <stdint.h>

void ADC_Init(void);
uint16_t ADC_GetValue(uint32_t channel);


#endif /* INC_DRIVERS_ADC_H_ */
