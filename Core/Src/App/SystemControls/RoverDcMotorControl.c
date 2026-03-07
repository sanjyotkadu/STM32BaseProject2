#include "App/SystemControls/RoverDcMotorControl.h"
#include "Middleware/DCMotCntrMod.h"
#include "Middleware/midConf.h"
#include <stdio.h>


//void RoverDcMotor_Update(int16_t forward, int16_t turn)
//{
//    int16_t leftSpeed;
//    int16_t rightSpeed;
//
//    /* Deadband filtering */
//    if (forward > -JOY_DEADBAND && forward < JOY_DEADBAND)
//        forward = 0;
//
//    if (turn > -JOY_DEADBAND && turn < JOY_DEADBAND)
//        turn = 0;
//
//    /* Differential mixing */
//    leftSpeed  = forward + turn;
//    rightSpeed = forward - turn;
//
//
//    /* Clamp */
//    if (leftSpeed > CF_MAX_JOY_VALUE)
//        leftSpeed = CF_MAX_JOY_VALUE;
//    if (leftSpeed < -CF_MAX_JOY_VALUE)
//        leftSpeed = -CF_MAX_JOY_VALUE;
//
//    if (rightSpeed > CF_MAX_JOY_VALUE)
//        rightSpeed = CF_MAX_JOY_VALUE;
//    if (rightSpeed < -CF_MAX_JOY_VALUE)
//        rightSpeed = -CF_MAX_JOY_VALUE;
//
//    DCMotor_Left_Run(leftSpeed);
//    DCMotor_Right_Run(rightSpeed);
//}

void RoverDcMotor_Update(int16_t forward, int16_t turn)
{
    // 1. Initial speed for both is the "throttle" (forward)
    int32_t leftSpeed = forward;
    int32_t rightSpeed = forward;

    /* Deadband filtering */
    if (forward > -JOY_DEADBAND && forward < JOY_DEADBAND) forward = 0;
    if (turn > -JOY_DEADBAND && turn < JOY_DEADBAND) turn = 0;

    /* 2. Scaling Logic: Use int32 to prevent overflow during multiplication */
    if (turn > 0) {
        // Turning RIGHT: Slow down the Right Motor
        // (1000 - turn) creates a multiplier from 1.0 down to 0.0
        rightSpeed = (forward * (1000 - turn)) / 1000;
    	//rightSpeed = (forward * (1000 - (turn * 0.3))) / 1000;
    }
    else if (turn < 0) {
        // Turning LEFT: Slow down the Left Motor
        // Use + because turn is already negative (e.g., 1000 + (-500) = 500)
        leftSpeed = (forward * (1000 + turn)) / 1000;
    	//rightSpeed = (forward * (1000 + (turn * 0.3))) / 1000;
    }

    /* 3. Clamp (Safety check for 1000) */
    if (leftSpeed > 1000) leftSpeed = 1000;
    if (leftSpeed < -1000) leftSpeed = -1000;
    if (rightSpeed > 1000) rightSpeed = 1000;
    if (rightSpeed < -1000) rightSpeed = -1000;

    DCMotor_Left_Run((int16_t)leftSpeed);
    DCMotor_Right_Run((int16_t)rightSpeed);
}
