################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeModbus/mb.c 

OBJS += \
./FreeModbus/mb.o 

C_DEPS += \
./FreeModbus/mb.d 


# Each subdirectory must supply rules for building sources it contributes
FreeModbus/%.o: ../FreeModbus/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -I"/home/frolls/ARM/stm32vld_template/FreeModbus/STM32/port" -I"/home/frolls/ARM/stm32vld_template/CMSIS" -I"/home/frolls/ARM/stm32vld_template/StdPeripheralDriver/inc" -I"/home/frolls/ARM/stm32vld_template/FreeModbus" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/functions" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/include" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/rtu" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/STM32" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


