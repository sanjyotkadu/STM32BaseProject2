/*
 * PWM.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_DRIVERS_PWM_H_
#define INC_DRIVERS_PWM_H_

#include <stdint.h>

void PWM_Init(void);
void PWM_SetDuty(uint16_t duty);

#endif /* INC_DRIVERS_PWM_H_ */
