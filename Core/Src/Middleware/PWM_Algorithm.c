
#include "Middleware/PWM_Algorithm.h"
#include "Middleware/midConf.h"
#include <math.h>

uint16_t PWM_Parabola(uint16_t speed)
{
    float normalized = (float)speed / CF_MAX_JOY_VALUE;

    float curved = powf(normalized, CURVE_K);

    float pwm = curved * MOTOR_PWM_MAX;

    if (pwm > MOTOR_PWM_MAX)
        pwm = MOTOR_PWM_MAX;

    return (uint16_t)pwm;
}
