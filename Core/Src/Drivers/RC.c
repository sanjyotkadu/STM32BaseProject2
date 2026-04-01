#include <stdint.h>
#include "Drivers/RC.h"
#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim2;


static uint32_t riseTime[2] = {0};

static uint16_t pulseWidth[2] = {1500,1500};

static uint8_t isRising[2] = {1,1};  // track edge


void RC_Init(void)
{
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1); // Turn
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2); // Forward
}



void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    uint8_t ch;

    if (htim->Instance != TIM2)
        return;

    if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
        ch = 0;
    else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
        ch = 1;
    else
        return;

    uint32_t channel = (ch == 0) ? TIM_CHANNEL_1 : TIM_CHANNEL_2;

    if (isRising[ch])
    {
        /* Rising edge */
        riseTime[ch] = HAL_TIM_ReadCapturedValue(htim, channel);

        __HAL_TIM_SET_CAPTUREPOLARITY(htim, channel, TIM_INPUTCHANNELPOLARITY_FALLING);
        isRising[ch] = 0;
    }
    else
    {
        /* Falling edge */
        uint32_t fallTime = HAL_TIM_ReadCapturedValue(htim, channel);

        if (fallTime >= riseTime[ch])
            pulseWidth[ch] = fallTime - riseTime[ch];
        else
            pulseWidth[ch] = (0xFFFF - riseTime[ch]) + fallTime;

        __HAL_TIM_SET_CAPTUREPOLARITY(htim, channel, TIM_INPUTCHANNELPOLARITY_RISING);
        isRising[ch] = 1;
    }
}

uint16_t RC_GetPulse(uint8_t ch)
{
    return pulseWidth[ch]; // 0 = turn, 1 = forward
}
