#include "App/Application/RoverApp.h"
#include "Middleware/JoyMod.h"
#include "Middleware/DCMotCntrMod.h"
#include "Middleware/Input_Select.h"



void Rover_App_Run(void)
{
	controlCmd_t cmd;

	Input_Get(&cmd);

    Rover_Run(&cmd);

}
