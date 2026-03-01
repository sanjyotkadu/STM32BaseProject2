#include "Middleware/DCMotCntrMod.h"
#include "Drivers/PWM.h"
#include "Drivers/drivConf.h"
#include "Middleware/midConf.h"
#include "Drivers/Dig.h"

static void Motor_Run(GPIO_TypeDef *in1Port,
                      uint16_t in1Pin,
                      GPIO_TypeDef *in2Port,
                      uint16_t in2Pin,
                      TIM_HandleTypeDef *htim,
                      uint32_t channel,
                      int16_t speed)
{
    uint16_t duty;

    if (speed > 0)
    {
        Dig_Write(in1Port, in1Pin, DIG_HIGH);
        Dig_Write(in2Port, in2Pin, DIG_LOW);
        duty = (speed * MOTOR_PWM_MAX) / CF_MAX_JOY_VALUE;
    }
    else if (speed < 0)
    {
        Dig_Write(in1Port, in1Pin, DIG_LOW);
        Dig_Write(in2Port, in2Pin, DIG_HIGH);
        duty = ((-speed) * MOTOR_PWM_MAX) / CF_MAX_JOY_VALUE;
    }
    else
    {
        Dig_Write(in1Port, in1Pin, DIG_LOW);
        Dig_Write(in2Port, in2Pin, DIG_LOW);
        duty = 0;
    }

    Pwm_SetDuty(htim, channel, duty);
}

void DCMotor_Left_Run(int16_t speed)
{
    Motor_Run(LEFT_MOTOR_IN1_PORT,
              LEFT_MOTOR_IN1_PIN,
              LEFT_MOTOR_IN2_PORT,
              LEFT_MOTOR_IN2_PIN,
              LEFT_MOTOR_PWM_TIMER,
              LEFT_MOTOR_PWM_CHANNEL,
              speed);
}

void DCMotor_Right_Run(int16_t speed)
{
    Motor_Run(RIGHT_MOTOR_IN1_PORT,
              RIGHT_MOTOR_IN1_PIN,
              RIGHT_MOTOR_IN2_PORT,
              RIGHT_MOTOR_IN2_PIN,
              RIGHT_MOTOR_PWM_TIMER,
              RIGHT_MOTOR_PWM_CHANNEL,
              speed);
}
