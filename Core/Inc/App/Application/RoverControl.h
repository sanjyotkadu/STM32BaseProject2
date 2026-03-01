/*
 * RoverControl.h
 *
 *  Created on: Feb 25, 2026
 *      Author: zamee
 */

#ifndef INC_APP_APPLICATION_ROVERCONTROL_H_
#define INC_APP_APPLICATION_ROVERCONTROL_H_

#include "Middleware/JoyMod.h"

void Rover_Run(const joyStickInfo_t *joyForward,
               const joyStickInfo_t *joyTurn);

#endif /* INC_APP_APPLICATION_ROVERCONTROL_H_ */
