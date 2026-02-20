#include "Drivers/RC_Driver.h"
#include "Drivers/ADC.h"
#include "Drivers/drivConf.h"

uint16_t RC_GetJoyYRaw(void)
{
    return ADC_GetValue(ADC_JOY_Y_CHANNEL);
}
