################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Sources/croutine.c \
../FreeRTOS/Sources/heap_1.c \
../FreeRTOS/Sources/list.c \
../FreeRTOS/Sources/port.c \
../FreeRTOS/Sources/queue.c \
../FreeRTOS/Sources/tasks.c \
../FreeRTOS/Sources/timers.c 

OBJS += \
./FreeRTOS/Sources/croutine.o \
./FreeRTOS/Sources/heap_1.o \
./FreeRTOS/Sources/list.o \
./FreeRTOS/Sources/port.o \
./FreeRTOS/Sources/queue.o \
./FreeRTOS/Sources/tasks.o \
./FreeRTOS/Sources/timers.o 

C_DEPS += \
./FreeRTOS/Sources/croutine.d \
./FreeRTOS/Sources/heap_1.d \
./FreeRTOS/Sources/list.d \
./FreeRTOS/Sources/port.d \
./FreeRTOS/Sources/queue.d \
./FreeRTOS/Sources/tasks.d \
./FreeRTOS/Sources/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Sources/%.o: ../FreeRTOS/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/CMSIS" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/Work/Headers" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/StdPeripheralDriver/inc" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeRTOS/Headers" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/modbus/include" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/modbus/rtu" -I"/home/frolls/git/STM32_FreeRTOS_freeModBus/stm32vld_template/FreeModbus/STM32/port" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g -ggdb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


