/*
 * appTask.h
 *
 *  Created on: Feb 10, 2026
 *      Author: zamee
 */

#ifndef INC_APP_APPTASK_H_
#define INC_APP_APPTASK_H_

#include <stdint.h>

void AppTask(void *pvParameters);
uint8_t AppTask_IsAlive(void);

#endif /* INC_APP_APPTASK_H_ */
