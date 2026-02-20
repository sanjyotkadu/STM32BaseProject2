#include "Middleware/DCMotCntrMod.h"
#include "Middleware/midConf.h"
#include "Drivers/PWM.h"
#include "Drivers/Dig.h"
#include "Drivers/drivConf.h"

void DCMotor_Run(int16_t speed)
{
    uint16_t duty;

    if (speed >= 0)
    {
        Dig_Write(MOTOR_DIR_PORT, MOTOR_DIR_PIN_1, DIG_HIGH);
        Dig_Write(GPIOA, MOTOR_DIR_PIN_2, DIG_LOW);  // IN2
        duty = (uint16_t)((speed * MOTOR_PWM_MAX) / JOY_OUTPUT_MAX);
    }
    else
    {
        Dig_Write(MOTOR_DIR_PORT, MOTOR_DIR_PIN_1, DIG_LOW);
        Dig_Write(GPIOA, MOTOR_DIR_PIN_2, DIG_HIGH);  // IN2
        duty = (uint16_t)(((-speed) * MOTOR_PWM_MAX) / JOY_OUTPUT_MAX);
    }

    PWM_SetDuty(duty);
}
