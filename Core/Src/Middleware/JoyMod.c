#include "Middleware/JoyMod.h"
#include "Middleware/midConf.h"
#include "Drivers/RC_Driver.h"

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
    }
    else if ((adcValue >= CF_ADC_NEGATIVE_RANGE_MIN) &&
             (adcValue <= CF_ADC_NEGATIVE_RANGE_MAX))
    {
        pJoyInfo->joystickDir = JOY_DIR_NEGATIVE;
        zoneMin = CF_ADC_NEGATIVE_RANGE_MIN;
        zoneMax = CF_ADC_NEGATIVE_RANGE_MAX;
    }
    else
    {
        pJoyInfo->joystickDir = JOY_DIR_NEUTRAL;
        pJoyInfo->JoystickVal = 0U;
        return 0U;
    }

    /* Scaling */
    scaledVal = ((uint32_t)(adcValue - zoneMin) *
                 CF_MAX_JOY_VALUE +
                 ((zoneMax - zoneMin) / 2U))
                / (zoneMax - zoneMin);

    pJoyInfo->JoystickVal = (uint16_t)scaledVal;

    return 0U;
}
