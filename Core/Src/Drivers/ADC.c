#include "Drivers/ADC.h"
#include "Drivers/drivConf.h"
#include "stm32f4xx_hal.h"

/* ADC handle from CubeMX */
extern ADC_HandleTypeDef hadc1;

void ADC_Init(void)
{
    /* ADC configured by CubeMX */
    (void)HAL_ADC_Start(&hadc1);
}

uint16_t ADC_GetValue(uint32_t channel)
{
    uint16_t adcValue = 0U;
    HAL_StatusTypeDef status;
    ADC_ChannelConfTypeDef sConfig;

    sConfig.Channel = channel;
    sConfig.Rank = 1U;
    sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;

    status = HAL_ADC_ConfigChannel(&hadc1, &sConfig);
    if (status == HAL_OK)
    {
        status = HAL_ADC_Start(&hadc1);
        if (status == HAL_OK)
        {
            status = HAL_ADC_PollForConversion(&hadc1, 10U);
            if (status == HAL_OK)
            {
                adcValue = (uint16_t)HAL_ADC_GetValue(&hadc1);
            }
            else
            {
                /* Conversion timeout */
            }
        }
    }

    (void)HAL_ADC_Stop(&hadc1);

    return adcValue;
}
