#include "Tasks/appTask.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks/appConf.h"
#include "App/Application/RoverApp.h"


static volatile uint8_t appTaskAliveFlag = 0U;

void AppTask(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
    	Rover_App_Run();

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
