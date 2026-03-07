#include "App/Application/RoverApp.h"
#include "Middleware/JoyMod.h"
#include "Middleware/DCMotCntrMod.h"

void Rover_App_Run(void)
{
    joyStickInfo_t joyForward;
    joyStickInfo_t joyTurn;

    Joystick_Get(&joyForward, &joyTurn);

    Rover_Run(&joyForward, &joyTurn);

}
