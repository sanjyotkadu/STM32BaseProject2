/*
 * JoyMod.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_MIDDLEWARE_JOYMOD_H_
#define INC_MIDDLEWARE_JOYMOD_H_

#include <stdint.h>

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

void Joystick_Get(joyStickInfo_t *joyForward,
                  joyStickInfo_t *joyTurn);


#endif /* INC_MIDDLEWARE_JOYMOD_H_ */
