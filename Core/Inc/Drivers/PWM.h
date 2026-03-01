/*
 * PWM.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_DRIVERS_PWM_H_
#define INC_DRIVERS_PWM_H_

#include <stdint.h>
#include "main.h"

typedef enum
{
    PWM_LEFT,
    PWM_RIGHT
} pwmChannel_t;

void PWM_Init(void);

void Pwm_SetDuty(TIM_HandleTypeDef *htim,
                 uint32_t channel,
                 uint16_t duty);

#endif /* INC_DRIVERS_PWM_H_ */
