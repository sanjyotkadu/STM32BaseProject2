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

//static int16_t currentLeft = 0;
//static int16_t currentRight = 0;
//
//void RoverDcMotor_Update(int16_t forward, int16_t turn)
//{
//    int32_t leftSpeed = forward;
//    int32_t rightSpeed = forward;
//
//    /* Deadband filtering */
//    if (forward > -JOY_DEADBAND && forward < JOY_DEADBAND)
//        forward = 0;
//
//    if (turn > -JOY_DEADBAND && turn < JOY_DEADBAND)
//        turn = 0;
//
//    /* Turning logic (UNCHANGED) */
//    if (turn > 0)
//    {
//        rightSpeed = (forward * (1000 - turn)) / 1000;
//    }
//    else if (turn < 0)
//    {
//        leftSpeed = (forward * (1000 + turn)) / 1000;
//    }
//
//    /* Clamp */
//    if (leftSpeed > 1000) leftSpeed = 1000;
//    if (leftSpeed < -1000) leftSpeed = -1000;
//
//    if (rightSpeed > 1000) rightSpeed = 1000;
//    if (rightSpeed < -1000) rightSpeed = -1000;
//
//    /* If joystick neutral → gradual stop */
//    if (forward == 0 && turn == 0)
//    {
//        int16_t step = 1;
//
//        if (currentLeft > step) currentLeft -= step;
//        else if (currentLeft < -step) currentLeft += step;
//        else currentLeft = 0;
//
//        if (currentRight > step) currentRight -= step;
//        else if (currentRight < -step) currentRight += step;
//        else currentRight = 0;
//    }
//    else
//    {
//        /* normal movement */
//        currentLeft = leftSpeed;
//        currentRight = rightSpeed;
//    }
//
//    DCMotor_Left_Run(currentLeft);
//    DCMotor_Right_Run(currentRight);
//}

void RoverDcMotor_Update(int16_t forward, int16_t turn)
{
    // 1. Initial speed for both is the "throttle" (forward)
    int32_t leftSpeed = forward;
    int32_t rightSpeed = forward;

    /* Deadband filtering */
    if (forward > -JOY_DEADBAND && forward < JOY_DEADBAND) forward = 0;
    if (turn > -JOY_DEADBAND && turn < JOY_DEADBAND) turn = 0;

    if (forward >= 0)
    {
        /* Forward motion */
        if (turn > 0)
            rightSpeed = (forward * (1000 - turn)) / 1000;
        else if (turn < 0)
            leftSpeed = (forward * (1000 + turn)) / 1000;
    }
    else
    {
        /* Reverse motion */
        if (turn > 0)
            leftSpeed = (forward * (1000 - turn)) / 1000;
        else if (turn < 0)
            rightSpeed = (forward * (1000 + turn)) / 1000;
    }

    /* 3. Clamp (Safety check for 1000) */
    if (leftSpeed > 1000) leftSpeed = 1000;
    if (leftSpeed < -1000) leftSpeed = -1000;
    if (rightSpeed > 1000) rightSpeed = 1000;
    if (rightSpeed < -1000) rightSpeed = -1000;



    DCMotor_Left_Run((int16_t)leftSpeed);
    DCMotor_Right_Run((int16_t)rightSpeed);
}
