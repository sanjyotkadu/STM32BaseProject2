#include "Middleware/Input_Select.h"
#include "Middleware/JoyMod.h"
#include "Middleware/RCMod.h"
#include "Middleware/midConf.h"

void Input_Get(controlCmd_t *cmd)
{
#if INPUT_SOURCE == INPUT_JOYSTICK
    Joystick_Get(cmd);
#elif INPUT_SOURCE == INPUT_RC
    RC_Get(cmd);
#endif
}
