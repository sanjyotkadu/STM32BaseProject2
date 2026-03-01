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
/* ADC ranges*/
//#define CF_ADC_POSITIVE_RANGE_MIN     10U
//#define CF_ADC_POSITIVE_RANGE_MAX     2030U

#define CF_ADC_POSITIVE_RANGE_MIN     2061U
#define CF_ADC_POSITIVE_RANGE_MAX     4095U

#define CF_ADC_NEUTRAL_RANGE_MIN      2031U
#define CF_ADC_NEUTRAL_RANGE_MAX      2060U

//#define CF_ADC_NEGATIVE_RANGE_MIN     2061U
//#define CF_ADC_NEGATIVE_RANGE_MAX     4000U

#define CF_ADC_NEGATIVE_RANGE_MIN     0U
#define CF_ADC_NEGATIVE_RANGE_MAX     2030U

#define CF_MIN_ADC_VALUE              0U
#define CF_MAX_ADC_VALUE              4095U

#define CF_MIN_JOY_VALUE              0U
#define CF_MAX_JOY_VALUE              100U

#define MOTOR_PWM_MAX        1000U

#endif /* INC_MIDDLEWARE_MIDCONF_H_ */
