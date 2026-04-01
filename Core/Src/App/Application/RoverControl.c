#include "App/Application/RoverControl.h"
#include "App/SystemControls/RoverDcMotorControl.h"


void Rover_Run(controlCmd_t *cmd)
{
    /* Send movement command to SystemControls */
	RoverDcMotor_Update(cmd->forward, cmd->turn);


}
