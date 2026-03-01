################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Middleware/DCMotCntrMod.c \
../Core/Src/Middleware/JoyMod.c 

OBJS += \
./Core/Src/Middleware/DCMotCntrMod.o \
./Core/Src/Middleware/JoyMod.o 

C_DEPS += \
./Core/Src/Middleware/DCMotCntrMod.d \
./Core/Src/Middleware/JoyMod.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Middleware/%.o Core/Src/Middleware/%.su Core/Src/Middleware/%.cyclo: ../Core/Src/Middleware/%.c Core/Src/Middleware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Middleware

clean-Core-2f-Src-2f-Middleware:
	-$(RM) ./Core/Src/Middleware/DCMotCntrMod.cyclo ./Core/Src/Middleware/DCMotCntrMod.d ./Core/Src/Middleware/DCMotCntrMod.o ./Core/Src/Middleware/DCMotCntrMod.su ./Core/Src/Middleware/JoyMod.cyclo ./Core/Src/Middleware/JoyMod.d ./Core/Src/Middleware/JoyMod.o ./Core/Src/Middleware/JoyMod.su

.PHONY: clean-Core-2f-Src-2f-Middleware

