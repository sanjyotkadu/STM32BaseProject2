/*
 * Dig.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_DRIVERS_DIG_H_
#define INC_DRIVERS_DIG_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

typedef enum
{
    DIG_LOW = 0,
    DIG_HIGH
} DigState_t;

void Dig_Write(GPIO_TypeDef *port, uint16_t pin, DigState_t state);

#endif /* INC_DRIVERS_DIG_H_ */
