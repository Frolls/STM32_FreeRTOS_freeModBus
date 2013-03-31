################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source_Files/croutine.c \
../Source_Files/heap_1.c \
../Source_Files/list.c \
../Source_Files/port.c \
../Source_Files/queue.c \
../Source_Files/tasks.c \
../Source_Files/timers.c 

OBJS += \
./Source_Files/croutine.o \
./Source_Files/heap_1.o \
./Source_Files/list.o \
./Source_Files/port.o \
./Source_Files/queue.o \
./Source_Files/tasks.o \
./Source_Files/timers.o 

C_DEPS += \
./Source_Files/croutine.d \
./Source_Files/heap_1.d \
./Source_Files/list.d \
./Source_Files/port.d \
./Source_Files/queue.d \
./Source_Files/tasks.d \
./Source_Files/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Source_Files/%.o: ../Source_Files/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -I"/home/frolls/ARM/stm32vld_template/CMSIS" -I"/home/frolls/ARM/stm32vld_template/StdPeripheralDriver/inc" -I"/home/frolls/ARM/stm32vld_template/Header_Files" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


