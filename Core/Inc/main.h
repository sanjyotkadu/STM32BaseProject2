/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define JOY_Y_ADC_Pin GPIO_PIN_0
#define JOY_Y_ADC_GPIO_Port GPIOA
#define JOY_X_ADC_Pin GPIO_PIN_1
#define JOY_X_ADC_GPIO_Port GPIOA
#define LEFT_MOTOR_IN1_Pin GPIO_PIN_4
#define LEFT_MOTOR_IN1_GPIO_Port GPIOA
#define LEFT_MOTOR_IN2_Pin GPIO_PIN_5
#define LEFT_MOTOR_IN2_GPIO_Port GPIOA
#define RIGHT_MOTOR_IN1_Pin GPIO_PIN_6
#define RIGHT_MOTOR_IN1_GPIO_Port GPIOA
#define RIGHT_MOTOR_IN2_Pin GPIO_PIN_7
#define RIGHT_MOTOR_IN2_GPIO_Port GPIOA
#define LEFT_MOTOR_PWM_Pin GPIO_PIN_8
#define LEFT_MOTOR_PWM_GPIO_Port GPIOA
#define RIGHT_MOTOR_PWM_Pin GPIO_PIN_9
#define RIGHT_MOTOR_PWM_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
