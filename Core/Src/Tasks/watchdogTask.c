#include "Tasks/watchdogTask.h"
#include "Drivers/WDG.h"
#include "Tasks/appTask.h"
#include "Tasks/commTask.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks/appConf.h"

void WatchdogTask(void *pvParameters)
{
    (void)pvParameters;


    for (;;)
    {
        if ((AppTask_IsAlive() != 0U) &&
            (CommTask_IsAlive() != 0U))
        {
            WDG_Refresh();
        }

        vTaskDelay(pdMS_TO_TICKS(WDG_TASK_PERIOD_MS));
    }
}
