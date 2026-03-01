/*
 * DCMotCntrMod.h
 *
 *  Created on: Feb 25, 2026
 *      Author: zamee
 */

#ifndef INC_MIDDLEWARE_DCMOTCNTRMOD_H_
#define INC_MIDDLEWARE_DCMOTCNTRMOD_H_

#include <stdint.h>

/**
 * @brief Run left motor with signed speed
 *
 * @param speed  Signed speed (-100 to +100)
 */
void DCMotor_Left_Run(int16_t speed);

/**
 * @brief Run right motor with signed speed
 *
 * @param speed  Signed speed (-100 to +100)
 */
void DCMotor_Right_Run(int16_t speed);

#endif /* INC_MIDDLEWARE_DCMOTCNTRMOD_H_ */
