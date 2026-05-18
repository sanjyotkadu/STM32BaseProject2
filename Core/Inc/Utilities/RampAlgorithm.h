/*
 * PWM_Algorithm.h
 *
 *  Created on: Mar 5, 2026
 *      Author: zamee
 */

#ifndef INC_UTILITIES_RAMPALGORITHM_H_
#define INC_UTILITIES_RAMPALGORITHM_H_
#include <stdint.h>


#define CURVE_K          1.8f   // Change this to tune feel

uint16_t PWM_Parabola(uint16_t speed);

#endif /* INC_UTILITIES_RAMPALGORITHM_H_ */
