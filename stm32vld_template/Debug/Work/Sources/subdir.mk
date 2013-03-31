################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Work/Sources/CRC.c \
../Work/Sources/ds1821.c \
../Work/Sources/ds1822.c \
../Work/Sources/oneWire.c \
../Work/Sources/serial.c \
../Work/Sources/stm32_GPIO.c \
../Work/Sources/timer6.c 

OBJS += \
./Work/Sources/CRC.o \
./Work/Sources/ds1821.o \
./Work/Sources/ds1822.o \
./Work/Sources/oneWire.o \
./Work/Sources/serial.o \
./Work/Sources/stm32_GPIO.o \
./Work/Sources/timer6.o 

C_DEPS += \
./Work/Sources/CRC.d \
./Work/Sources/ds1821.d \
./Work/Sources/ds1822.d \
./Work/Sources/oneWire.d \
./Work/Sources/serial.d \
./Work/Sources/stm32_GPIO.d \
./Work/Sources/timer6.d 


# Each subdirectory must supply rules for building sources it contributes
Work/Sources/%.o: ../Work/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/CMSIS" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/Work/Headers" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/StdPeripheralDriver/inc" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeRTOS/Headers" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


