/*
 * UART.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_DRIVERS_UART_H_
#define INC_DRIVERS_UART_H_

#include <stdint.h>

void UART_Init(void);
void UART_Send(const uint8_t *data, uint16_t length);

#endif /* INC_DRIVERS_UART_H_ */
