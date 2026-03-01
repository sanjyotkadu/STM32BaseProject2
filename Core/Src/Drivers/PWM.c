#include "Drivers/PWM.h"
#include "Drivers/drivConf.h"
#include "stm32f4xx_hal.h"

/* TIM handle from CubeMX */
extern TIM_HandleTypeDef htim1;

void PWM_Init(void)
{
    (void)HAL_TIM_PWM_Start(&htim1, LEFT_MOTOR_PWM_CHANNEL);
    (void)HAL_TIM_PWM_Start(&htim1, RIGHT_MOTOR_PWM_CHANNEL);
}

void Pwm_SetDuty(TIM_HandleTypeDef *htim,
                 uint32_t channel,
                 uint16_t duty)
{
    __HAL_TIM_SET_COMPARE(htim, channel, duty);
}
