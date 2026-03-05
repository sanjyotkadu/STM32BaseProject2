#include "App/SystemControls/RoverDcMotorControl.h"
#include "Middleware/DCMotCntrMod.h"
#include "Middleware/midConf.h"
#include <stdio.h>


void RoverDcMotor_Update(int16_t forward, int16_t turn)
{
    int16_t leftSpeed;
    int16_t rightSpeed;

    /* Deadband filtering */
    if (forward > -JOY_DEADBAND && forward < JOY_DEADBAND)
        forward = 0;

    if (turn > -JOY_DEADBAND && turn < JOY_DEADBAND)
        turn = 0;

    /* Differential mixing */
    leftSpeed  = forward + turn;
    rightSpeed = forward - turn;


    /* Clamp */
    if (leftSpeed > CF_MAX_JOY_VALUE)
        leftSpeed = CF_MAX_JOY_VALUE;
    if (leftSpeed < -CF_MAX_JOY_VALUE)
        leftSpeed = -CF_MAX_JOY_VALUE;

    if (rightSpeed > CF_MAX_JOY_VALUE)
        rightSpeed = CF_MAX_JOY_VALUE;
    if (rightSpeed < -CF_MAX_JOY_VALUE)
        rightSpeed = -CF_MAX_JOY_VALUE;

    DCMotor_Left_Run(leftSpeed);
    DCMotor_Right_Run(rightSpeed);
}
