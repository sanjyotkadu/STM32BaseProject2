#include "App/Application/RoverControl.h"
#include "App/SystemControls/RoverDcMotorControl.h"

/* Convert joystick info to signed speed */
static int16_t Joy_ToSignedSpeed(const joyStickInfo_t *pJoy)
{
    if (pJoy->joystickDir == JOY_DIR_POSITIVE)
    {
        return (int16_t)pJoy->JoystickVal;
    }
    else if (pJoy->joystickDir == JOY_DIR_NEGATIVE)
    {
        return -(int16_t)pJoy->JoystickVal;
    }
    else
    {
        return 0;
    }
}

void Rover_Run(const joyStickInfo_t *joyForward,
               const joyStickInfo_t *joyTurn)
{
    int16_t forwardSpeed = Joy_ToSignedSpeed(joyForward);
    int16_t turnSpeed    = Joy_ToSignedSpeed(joyTurn);

    /* Send movement command to SystemControls */
    RoverDcMotor_Update(forwardSpeed, turnSpeed);
}
