/*
 * Input_Select.h
 *
 *  Created on: Mar 26, 2026
 *      Author: zamee
 */

#ifndef INC_MIDDLEWARE_INPUT_SELECT_H_
#define INC_MIDDLEWARE_INPUT_SELECT_H_

#include <stdint.h>

typedef struct
{
    int16_t forward;
    int16_t turn;
} controlCmd_t;

void Input_Get(controlCmd_t *cmd);

#endif /* INC_MIDDLEWARE_INPUT_SELECT_H_ */
