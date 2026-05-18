################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Utilities/RampAlgorithm.c 

OBJS += \
./Core/Src/Utilities/RampAlgorithm.o 

C_DEPS += \
./Core/Src/Utilities/RampAlgorithm.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Utilities/%.o Core/Src/Utilities/%.su Core/Src/Utilities/%.cyclo: ../Core/Src/Utilities/%.c Core/Src/Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Utilities

clean-Core-2f-Src-2f-Utilities:
	-$(RM) ./Core/Src/Utilities/RampAlgorithm.cyclo ./Core/Src/Utilities/RampAlgorithm.d ./Core/Src/Utilities/RampAlgorithm.o ./Core/Src/Utilities/RampAlgorithm.su

.PHONY: clean-Core-2f-Src-2f-Utilities

