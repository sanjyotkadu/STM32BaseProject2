#include "Drivers/Dig.h"

void Dig_Write(GPIO_TypeDef *port, uint16_t pin, DigState_t state)
{
    GPIO_PinState pinState;

    if (state == DIG_HIGH)
    {
        pinState = GPIO_PIN_SET;
    }
    else
    {
        pinState = GPIO_PIN_RESET;
    }

    HAL_GPIO_WritePin(port, pin, pinState);
}
