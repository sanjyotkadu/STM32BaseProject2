#include "Tasks/commTask.h"
#include "Drivers/UART.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks/appConf.h"

static volatile uint8_t commTaskAliveFlag = 0U;

void CommTask(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        /* Placeholder for communication logic */

        commTaskAliveFlag = 1U;
        vTaskDelay(pdMS_TO_TICKS(COMM_TASK_PERIOD_MS));
    }
}

uint8_t CommTask_IsAlive(void)
{
    return commTaskAliveFlag;
}
