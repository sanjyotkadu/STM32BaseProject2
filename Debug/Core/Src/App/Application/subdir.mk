################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/App/Application/RoverControl.c 

OBJS += \
./Core/Src/App/Application/RoverControl.o 

C_DEPS += \
./Core/Src/App/Application/RoverControl.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/App/Application/%.o Core/Src/App/Application/%.su Core/Src/App/Application/%.cyclo: ../Core/Src/App/Application/%.c Core/Src/App/Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-App-2f-Application

clean-Core-2f-Src-2f-App-2f-Application:
	-$(RM) ./Core/Src/App/Application/RoverControl.cyclo ./Core/Src/App/Application/RoverControl.d ./Core/Src/App/Application/RoverControl.o ./Core/Src/App/Application/RoverControl.su

.PHONY: clean-Core-2f-Src-2f-App-2f-Application

