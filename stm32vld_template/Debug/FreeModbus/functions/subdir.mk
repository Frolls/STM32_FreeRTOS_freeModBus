################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeModbus/functions/mbfunccoils.c \
../FreeModbus/functions/mbfuncdiag.c \
../FreeModbus/functions/mbfuncdisc.c \
../FreeModbus/functions/mbfuncholding.c \
../FreeModbus/functions/mbfuncinput.c \
../FreeModbus/functions/mbfuncother.c \
../FreeModbus/functions/mbutils.c 

OBJS += \
./FreeModbus/functions/mbfunccoils.o \
./FreeModbus/functions/mbfuncdiag.o \
./FreeModbus/functions/mbfuncdisc.o \
./FreeModbus/functions/mbfuncholding.o \
./FreeModbus/functions/mbfuncinput.o \
./FreeModbus/functions/mbfuncother.o \
./FreeModbus/functions/mbutils.o 

C_DEPS += \
./FreeModbus/functions/mbfunccoils.d \
./FreeModbus/functions/mbfuncdiag.d \
./FreeModbus/functions/mbfuncdisc.d \
./FreeModbus/functions/mbfuncholding.d \
./FreeModbus/functions/mbfuncinput.d \
./FreeModbus/functions/mbfuncother.d \
./FreeModbus/functions/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
FreeModbus/functions/%.o: ../FreeModbus/functions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -I"/home/frolls/ARM/stm32vld_template/FreeModbus/STM32/port" -I"/home/frolls/ARM/stm32vld_template/CMSIS" -I"/home/frolls/ARM/stm32vld_template/StdPeripheralDriver/inc" -I"/home/frolls/ARM/stm32vld_template/FreeModbus" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/functions" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/include" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/rtu" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/STM32" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


