#include "Drivers/PWM.h"
#include "Drivers/drivConf.h"
#include "stm32f4xx_hal.h"

/* TIM handle from CubeMX */
extern TIM_HandleTypeDef htim1;

void PWM_Init(void)
{
    (void)HAL_TIM_PWM_Start(&htim1, PWM_MOTOR_CHANNEL);
}

void PWM_SetDuty(uint16_t duty)
{
    uint16_t safeDuty = duty;

    if (safeDuty > PWM_MAX_DUTY)
    {
        safeDuty = PWM_MAX_DUTY;
    }

    __HAL_TIM_SET_COMPARE(&htim1, PWM_MOTOR_CHANNEL, safeDuty);
}
