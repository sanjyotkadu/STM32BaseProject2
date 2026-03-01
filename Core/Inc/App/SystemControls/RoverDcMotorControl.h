/*
 * RoverDcMotorControl.h
 *
 *  Created on: Feb 25, 2026
 *      Author: zamee
 */

#ifndef INC_APP_SYSTEMCONTROLS_ROVERDCMOTORCONTROL_H_
#define INC_APP_SYSTEMCONTROLS_ROVERDCMOTORCONTROL_H_

#include <stdint.h>

/**
 * @brief Update rover motor speeds based on movement commands.
 *
 * @param forward  Signed forward speed (-100 to +100)
 * @param turn     Signed turn speed (-100 to +100)
 */
void RoverDcMotor_Update(int16_t forward, int16_t turn);


#endif /* INC_APP_SYSTEMCONTROLS_ROVERDCMOTORCONTROL_H_ */
