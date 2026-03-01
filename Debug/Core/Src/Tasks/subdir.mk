################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Tasks/appTask.c \
../Core/Src/Tasks/commTask.c \
../Core/Src/Tasks/watchdogTask.c 

OBJS += \
./Core/Src/Tasks/appTask.o \
./Core/Src/Tasks/commTask.o \
./Core/Src/Tasks/watchdogTask.o 

C_DEPS += \
./Core/Src/Tasks/appTask.d \
./Core/Src/Tasks/commTask.d \
./Core/Src/Tasks/watchdogTask.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Tasks/%.o Core/Src/Tasks/%.su Core/Src/Tasks/%.cyclo: ../Core/Src/Tasks/%.c Core/Src/Tasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Tasks

clean-Core-2f-Src-2f-Tasks:
	-$(RM) ./Core/Src/Tasks/appTask.cyclo ./Core/Src/Tasks/appTask.d ./Core/Src/Tasks/appTask.o ./Core/Src/Tasks/appTask.su ./Core/Src/Tasks/commTask.cyclo ./Core/Src/Tasks/commTask.d ./Core/Src/Tasks/commTask.o ./Core/Src/Tasks/commTask.su ./Core/Src/Tasks/watchdogTask.cyclo ./Core/Src/Tasks/watchdogTask.d ./Core/Src/Tasks/watchdogTask.o ./Core/Src/Tasks/watchdogTask.su

.PHONY: clean-Core-2f-Src-2f-Tasks

