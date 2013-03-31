################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/core_cm3.c \
../CMSIS/system_stm32f10x.c 

S_UPPER_SRCS += \
../CMSIS/startup_stm32f10x_md_vl.S 

OBJS += \
./CMSIS/core_cm3.o \
./CMSIS/startup_stm32f10x_md_vl.o \
./CMSIS/system_stm32f10x.o 

C_DEPS += \
./CMSIS/core_cm3.d \
./CMSIS/system_stm32f10x.d 

S_UPPER_DEPS += \
./CMSIS/startup_stm32f10x_md_vl.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/%.o: ../CMSIS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/CMSIS" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/Work/Headers" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/StdPeripheralDriver/inc" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeRTOS/Headers" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/%.o: ../CMSIS/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC Assembler'
	arm-none-eabi-gcc -x assembler-with-cpp -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


