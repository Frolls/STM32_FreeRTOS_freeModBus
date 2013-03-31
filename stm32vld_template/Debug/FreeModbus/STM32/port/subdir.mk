################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeModbus/STM32/port/portevent.c \
../FreeModbus/STM32/port/portserial.c \
../FreeModbus/STM32/port/porttimer.c 

OBJS += \
./FreeModbus/STM32/port/portevent.o \
./FreeModbus/STM32/port/portserial.o \
./FreeModbus/STM32/port/porttimer.o 

C_DEPS += \
./FreeModbus/STM32/port/portevent.d \
./FreeModbus/STM32/port/portserial.d \
./FreeModbus/STM32/port/porttimer.d 


# Each subdirectory must supply rules for building sources it contributes
FreeModbus/STM32/port/%.o: ../FreeModbus/STM32/port/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/CMSIS" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/Work/Headers" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/StdPeripheralDriver/inc" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeRTOS/Headers" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/modbus/include" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/modbus/rtu" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/STM32/port" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


