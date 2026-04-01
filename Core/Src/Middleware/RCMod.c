#include "Middleware/RCMod.h"
#include "Middleware/midConf.h"

static int16_t scaleRC(uint16_t pulse)
{
    int16_t val = (int16_t)pulse - RC_MID;

    val = (val * 1000) / 500;

    if (val > 1000) val = 1000;
    if (val < -1000) val = -1000;

    return val;
}


void RC_Get(controlCmd_t *cmd)
{
    uint16_t pulseF = RC_GetPulse(1);
    uint16_t pulseT = RC_GetPulse(0);

    cmd->forward = scaleRC(pulseF);
    cmd->turn    = scaleRC(pulseT);

}
