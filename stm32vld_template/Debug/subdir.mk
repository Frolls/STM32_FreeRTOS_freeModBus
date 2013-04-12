################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

OBJS += \
./main.o 

C_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/CMSIS" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/Work/Headers" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/StdPeripheralDriver/inc" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeRTOS/Headers" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/modbus/include" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/modbus/rtu" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/STM32/port" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


