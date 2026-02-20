#include "App/appTask.h"
#include "Middleware/JoyMod.h"
#include "Middleware/DCMotCntrMod.h"
#include "FreeRTOS.h"
#include "task.h"
#include "App/appConf.h"

static volatile uint8_t appTaskAliveFlag = 0U;

void AppTask(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        JoyScaledVal_t joy = Joy_GetScaledValue();
        DCMotor_Run(joy.y);

        appTaskAliveFlag = 1U;
        vTaskDelay(pdMS_TO_TICKS(APP_TASK_PERIOD_MS));
    }
}

void AppTask_Alive(void)
{
    appTaskAliveFlag = 0U;
}

uint8_t AppTask_IsAlive(void)
{
    return appTaskAliveFlag;
}
