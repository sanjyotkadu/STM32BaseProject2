################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/App/appTask.c \
../Core/Src/App/commTask.c \
../Core/Src/App/watchdogTask.c 

OBJS += \
./Core/Src/App/appTask.o \
./Core/Src/App/commTask.o \
./Core/Src/App/watchdogTask.o 

C_DEPS += \
./Core/Src/App/appTask.d \
./Core/Src/App/commTask.d \
./Core/Src/App/watchdogTask.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/App/%.o Core/Src/App/%.su Core/Src/App/%.cyclo: ../Core/Src/App/%.c Core/Src/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-App

clean-Core-2f-Src-2f-App:
	-$(RM) ./Core/Src/App/appTask.cyclo ./Core/Src/App/appTask.d ./Core/Src/App/appTask.o ./Core/Src/App/appTask.su ./Core/Src/App/commTask.cyclo ./Core/Src/App/commTask.d ./Core/Src/App/commTask.o ./Core/Src/App/commTask.su ./Core/Src/App/watchdogTask.cyclo ./Core/Src/App/watchdogTask.d ./Core/Src/App/watchdogTask.o ./Core/Src/App/watchdogTask.su

.PHONY: clean-Core-2f-Src-2f-App

