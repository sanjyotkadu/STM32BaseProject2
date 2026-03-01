/*
 * commTask.h
 *
 *  Created on: Feb 10, 2026
 *      Author: zamee
 */

#ifndef INC_APP_COMMTASK_H_
#define INC_APP_COMMTASK_H_

#include <stdint.h>

void CommTask(void *pvParameters);
uint8_t CommTask_IsAlive(void);

#endif /* INC_APP_COMMTASK_H_ */
