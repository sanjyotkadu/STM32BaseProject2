################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Drivers/ADC.c \
../Core/Src/Drivers/Dig.c \
../Core/Src/Drivers/PWM.c \
../Core/Src/Drivers/RC_Driver.c \
../Core/Src/Drivers/UART.c \
../Core/Src/Drivers/WDG.c 

OBJS += \
./Core/Src/Drivers/ADC.o \
./Core/Src/Drivers/Dig.o \
./Core/Src/Drivers/PWM.o \
./Core/Src/Drivers/RC_Driver.o \
./Core/Src/Drivers/UART.o \
./Core/Src/Drivers/WDG.o 

C_DEPS += \
./Core/Src/Drivers/ADC.d \
./Core/Src/Drivers/Dig.d \
./Core/Src/Drivers/PWM.d \
./Core/Src/Drivers/RC_Driver.d \
./Core/Src/Drivers/UART.d \
./Core/Src/Drivers/WDG.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Drivers/%.o Core/Src/Drivers/%.su Core/Src/Drivers/%.cyclo: ../Core/Src/Drivers/%.c Core/Src/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Drivers

clean-Core-2f-Src-2f-Drivers:
	-$(RM) ./Core/Src/Drivers/ADC.cyclo ./Core/Src/Drivers/ADC.d ./Core/Src/Drivers/ADC.o ./Core/Src/Drivers/ADC.su ./Core/Src/Drivers/Dig.cyclo ./Core/Src/Drivers/Dig.d ./Core/Src/Drivers/Dig.o ./Core/Src/Drivers/Dig.su ./Core/Src/Drivers/PWM.cyclo ./Core/Src/Drivers/PWM.d ./Core/Src/Drivers/PWM.o ./Core/Src/Drivers/PWM.su ./Core/Src/Drivers/RC_Driver.cyclo ./Core/Src/Drivers/RC_Driver.d ./Core/Src/Drivers/RC_Driver.o ./Core/Src/Drivers/RC_Driver.su ./Core/Src/Drivers/UART.cyclo ./Core/Src/Drivers/UART.d ./Core/Src/Drivers/UART.o ./Core/Src/Drivers/UART.su ./Core/Src/Drivers/WDG.cyclo ./Core/Src/Drivers/WDG.d ./Core/Src/Drivers/WDG.o ./Core/Src/Drivers/WDG.su

.PHONY: clean-Core-2f-Src-2f-Drivers

