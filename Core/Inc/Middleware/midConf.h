/*
 * midConf.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_MIDDLEWARE_MIDCONF_H_
#define INC_MIDDLEWARE_MIDCONF_H_

#include <stdint.h>

/* ================= JOYSTICK CONFIG ================= */
#define JOY_ADC_MIN            (uint16_t)0U
#define JOY_ADC_MAX            (uint16_t)4095U
#define JOY_ADC_CENTER         (uint16_t)2048U
#define JOY_DEAD_ZONE          (uint16_t)50U

#define JOY_OUTPUT_MAX         (int16_t)100

/* ================= MOTOR CONFIG ==================== */
#define MOTOR_PWM_MAX          (uint16_t)1000U

#endif /* INC_MIDDLEWARE_MIDCONF_H_ */
