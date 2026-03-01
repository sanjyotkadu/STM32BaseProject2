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
#include "main.h"

extern TIM_HandleTypeDef htim1;

/* ================= ADC CONFIG ================= */
#define JOY_Y_ADC_CHANNEL        ADC_CHANNEL_0   // PA0
#define JOY_X_ADC_CHANNEL        ADC_CHANNEL_1   // PA1

/* ================= LEFT MOTOR ================= */

#define LEFT_MOTOR_PWM_TIMER        (&htim1)
#define LEFT_MOTOR_PWM_CHANNEL      TIM_CHANNEL_1

#define LEFT_MOTOR_IN1_PORT         GPIOA
#define LEFT_MOTOR_IN1_PIN          GPIO_PIN_4

#define LEFT_MOTOR_IN2_PORT         GPIOA
#define LEFT_MOTOR_IN2_PIN          GPIO_PIN_5


/* ================= RIGHT MOTOR ================= */

#define RIGHT_MOTOR_PWM_TIMER       (&htim1)
#define RIGHT_MOTOR_PWM_CHANNEL     TIM_CHANNEL_2

#define RIGHT_MOTOR_IN1_PORT        GPIOA
#define RIGHT_MOTOR_IN1_PIN         GPIO_PIN_6

#define RIGHT_MOTOR_IN2_PORT        GPIOA
#define RIGHT_MOTOR_IN2_PIN         GPIO_PIN_7
/* ================= UART CONFIG ================= */
#define DEBUG_UART_INSTANCE      USART2
#define UART_TX_TIMEOUT_MS       (uint32_t)100U

/* ================= WATCHDOG CONFIG ================= */
#define WDG_RELOAD_VALUE         (uint32_t)4095U

#endif /* INC_DRIVERS_DRIVCONF_H_ */
