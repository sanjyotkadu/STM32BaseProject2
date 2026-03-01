#include "Middleware/JoyMod.h"
#include "Middleware/midConf.h"
#include "Drivers/drivConf.h"
#include "Drivers/ADC.h"
#include <stddef.h>

retVal_t getJoyInfoFromADC(uint8_t adcResolution,
                           uint16_t adcValue,
                           joyStickInfo_t * pJoyInfo)
{
    uint32_t scaledVal;
    uint32_t zoneMin;
    uint32_t zoneMax;

    if (pJoyInfo == NULL)
    {
        return 1U;
    }

    /* Clamp ADC value */
    if (adcValue < CF_MIN_ADC_VALUE)
    {
        adcValue = CF_MIN_ADC_VALUE;
    }
    else if (adcValue > CF_MAX_ADC_VALUE)
    {
        adcValue = CF_MAX_ADC_VALUE;
    }

    /* Direction detection */
    if ((adcValue >= CF_ADC_POSITIVE_RANGE_MIN) &&
        (adcValue <= CF_ADC_POSITIVE_RANGE_MAX))
    {
        pJoyInfo->joystickDir = JOY_DIR_POSITIVE;
        zoneMin = CF_ADC_POSITIVE_RANGE_MIN;
        zoneMax = CF_ADC_POSITIVE_RANGE_MAX;

        /* Normal scaling */
        scaledVal = ((uint32_t)(adcValue - zoneMin) *
                     CF_MAX_JOY_VALUE +
                     ((zoneMax - zoneMin) / 2U))
                    / (zoneMax - zoneMin);
    }
    else if ((adcValue >= CF_ADC_NEGATIVE_RANGE_MIN) &&
             (adcValue <= CF_ADC_NEGATIVE_RANGE_MAX))
    {
        pJoyInfo->joystickDir = JOY_DIR_NEGATIVE;
        zoneMin = CF_ADC_NEGATIVE_RANGE_MIN;
        zoneMax = CF_ADC_NEGATIVE_RANGE_MAX;

        /* Reverse scaling */
        scaledVal = ((uint32_t)(zoneMax - adcValue) *
                     CF_MAX_JOY_VALUE +
                     ((zoneMax - zoneMin) / 2U))
                    / (zoneMax - zoneMin);
    }

    /* Neutral Zone */
    else if ((adcValue >= CF_ADC_NEUTRAL_RANGE_MIN) &&
             (adcValue <= CF_ADC_NEUTRAL_RANGE_MAX))
    {
        pJoyInfo->joystickDir = JOY_DIR_NEUTRAL;
        pJoyInfo->JoystickVal = 0U;
        return 0U;
    }

    /* Out-of-range safety */
    else
    {
        pJoyInfo->joystickDir = JOY_DIR_NEUTRAL;
        pJoyInfo->JoystickVal = 0U;
        return 0U;
    }


    pJoyInfo->JoystickVal = (uint16_t)scaledVal;

    return 0U;
}


void Joystick_Get(joyStickInfo_t *joyForward,
                  joyStickInfo_t *joyTurn)
{
    uint16_t adcForward;
    uint16_t adcTurn;

    /* Read ADC internally */
    adcForward = ADC_GetValue(JOY_Y_ADC_CHANNEL);
    adcTurn    = ADC_GetValue(JOY_X_ADC_CHANNEL);

    /* Convert to scaled joystick values */
    getJoyInfoFromADC(12U, adcForward, joyForward);
    getJoyInfoFromADC(12U, adcTurn, joyTurn);
}
