################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include StdPeripheralDriver/src/subdir.mk
-include FreeRTOS/Sources/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
stm32vld_template.hex \

SECONDARY_LIST += \
stm32vld_template.lst \

SECONDARY_SIZE += \
stm32vld_template.siz \


# All Target
all: stm32vld_template.elf secondary-outputs

# Tool invocations
stm32vld_template.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linux GCC C Linker'
	arm-elf-gcc -T"/home/frolls/ARM/stm32vld_template/stm32f100rb.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,stm32vld_template.map -mcpu=cortex-m4 -mthumb -o "stm32vld_template.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

stm32vld_template.hex: stm32vld_template.elf
	@echo 'Invoking: ARM Linux GNU Create Flash Image'
	arm-elf-objcopy -O elf32-littlearm stm32vld_template.elf  "stm32vld_template.hex"
	@echo 'Finished building: $@'
	@echo ' '

stm32vld_template.lst: stm32vld_template.elf
	@echo 'Invoking: ARM Linux GNU Create Listing'
	arm-elf-objdump -h -S stm32vld_template.elf > "stm32vld_template.lst"
	@echo 'Finished building: $@'
	@echo ' '

stm32vld_template.siz: stm32vld_template.elf
	@echo 'Invoking: ARM Linux GNU Print Size'
	arm-elf-size  --format=berkeley stm32vld_template.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) stm32vld_template.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
