#include "Tasks/appTask.h"
#include "Middleware/JoyMod.h"
#include "Middleware/DCMotCntrMod.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks/appConf.h"

static volatile uint8_t appTaskAliveFlag = 0U;

void AppTask(void *pvParameters)
{
    (void)pvParameters;

    joyStickInfo_t joyForward;
    joyStickInfo_t joyTurn;

    for (;;)
    {

        Joystick_Get(&joyForward, &joyTurn);

        Rover_Run(&joyForward, &joyTurn);

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
