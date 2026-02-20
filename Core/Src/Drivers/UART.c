#include "Drivers/UART.h"
#include "Drivers/drivConf.h"
#include "stm32f4xx_hal.h"

/* UART handle from CubeMX */
extern UART_HandleTypeDef huart2;

void UART_Init(void)
{
    /* UART configured by CubeMX */
}

void UART_Send(const uint8_t *data, uint16_t length)
{
    if ((data != NULL) && (length > 0U))
    {
        (void)HAL_UART_Transmit(
            &huart2,
            (uint8_t *)data,
            length,
            UART_TX_TIMEOUT_MS);
    }
}
