/*
 * drivConf.h
 *
 *  Created on: Feb 9, 2026
 *      Author: zamee
 */

#ifndef INC_DRIVERS_DRIVCONF_H_
#define INC_DRIVERS_DRIVCONF_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

/* ================= ADC CONFIG ================= */
#define ADC_JOY_Y_CHANNEL        (uint32_t)ADC_CHANNEL_0

/* ================= PWM CONFIG ================= */
#define PWM_MAX_DUTY             (uint16_t)1000U
#define PWM_MOTOR_CHANNEL        (uint32_t)TIM_CHANNEL_1

/* ================= GPIO CONFIG ================= */
#define MOTOR_DIR_PORT           GPIOA
#define MOTOR_DIR_PIN_1          GPIO_PIN_5
#define MOTOR_DIR_PIN_2          GPIO_PIN_6

/* ================= UART CONFIG ================= */
#define DEBUG_UART_INSTANCE      USART2
#define UART_TX_TIMEOUT_MS       (uint32_t)100U

/* ================= WATCHDOG CONFIG ================= */
#define WDG_RELOAD_VALUE         (uint32_t)4095U

#endif /* INC_DRIVERS_DRIVCONF_H_ */
