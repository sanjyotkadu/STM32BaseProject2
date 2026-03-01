#include "App/SystemControls/RoverDcMotorControl.h"
#include "Middleware/DCMotCntrMod.h"


void RoverDcMotor_Update(int16_t forward, int16_t turn)
{
    int16_t leftSpeed = 0;
    int16_t rightSpeed = 0;

    if (forward != 0)
    {
        /* Move straight */
        leftSpeed  = forward;
        rightSpeed = forward;
    }
    else if (turn > 0)
    {
        /* TURN RIGHT: Left forward, Right backward */
        leftSpeed  = turn;
        rightSpeed = -turn;
    }
    else if (turn < 0)
    {
        /* TURN LEFT: Right forward, Left backward */
        leftSpeed  = turn;
        rightSpeed = -turn;
    }
    else
    {
        leftSpeed = 0;
        rightSpeed = 0;
    }

    DCMotor_Left_Run(leftSpeed);
    DCMotor_Right_Run(rightSpeed);
}
