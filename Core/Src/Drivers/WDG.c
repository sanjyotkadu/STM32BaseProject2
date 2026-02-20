#include "Drivers/WDG.h"
#include "stm32f4xx_hal.h"

/* Watchdog handle from CubeMX */
extern IWDG_HandleTypeDef hiwdg;

void WDG_Init(void)
{

}

void WDG_Refresh(void)
{
    (void)HAL_IWDG_Refresh(&hiwdg);
}
