/*
 * JoyMod.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_MIDDLEWARE_JOYMOD_H_
#define INC_MIDDLEWARE_JOYMOD_H_

#include <stdint.h>

/* ================= CONFIGURATION SECTION ================= */

/* ADC ranges*/
#define CF_ADC_POSITIVE_RANGE_MIN     10U
#define CF_ADC_POSITIVE_RANGE_MAX     2030U

#define CF_ADC_NEUTRAL_RANGE_MIN      2031U
#define CF_ADC_NEUTRAL_RANGE_MAX      2060U

#define CF_ADC_NEGATIVE_RANGE_MIN     2061U
#define CF_ADC_NEGATIVE_RANGE_MAX     4000U

#define CF_MIN_ADC_VALUE              0U
#define CF_MAX_ADC_VALUE              4095U

#define CF_MIN_JOY_VALUE              0U
#define CF_MAX_JOY_VALUE              100U

/* ================= TYPE DEFINITIONS ================= */

typedef enum
{
    JOY_DIR_POSITIVE = 0,
    JOY_DIR_NEUTRAL,
    JOY_DIR_NEGATIVE
} JoyDirection_t;

typedef struct
{
    JoyDirection_t joystickDir;
    uint16_t JoystickVal;     /* 0–100 */
} joyStickInfo_t;

typedef uint8_t retVal_t;

/* ================= API ================= */

retVal_t getJoyInfoFromADC(uint8_t adcResolution,
                           uint16_t adcValue,
                           joyStickInfo_t * pJoyInfo);

#endif /* INC_MIDDLEWARE_JOYMOD_H_ */
