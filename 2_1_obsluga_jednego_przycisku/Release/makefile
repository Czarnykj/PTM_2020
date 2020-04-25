################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
obsluga_jednego_przycisku.lss \

FLASH_IMAGE += \
obsluga_jednego_przycisku.hex \

EEPROM_IMAGE += \
obsluga_jednego_przycisku.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: obsluga_jednego_przycisku.elf secondary-outputs

# Tool invocations
obsluga_jednego_przycisku.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,obsluga_jednego_przycisku.map,--cref -mrelax -Wl,--gc-sections -mmcu=atmega32 -o "obsluga_jednego_przycisku.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

obsluga_jednego_przycisku.lss: obsluga_jednego_przycisku.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S obsluga_jednego_przycisku.elf  >"obsluga_jednego_przycisku.lss"
	@echo 'Finished building: $@'
	@echo ' '

obsluga_jednego_przycisku.hex: obsluga_jednego_przycisku.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex obsluga_jednego_przycisku.elf  "obsluga_jednego_przycisku.hex"
	@echo 'Finished building: $@'
	@echo ' '

obsluga_jednego_przycisku.eep: obsluga_jednego_przycisku.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex obsluga_jednego_przycisku.elf  "obsluga_jednego_przycisku.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: obsluga_jednego_przycisku.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 obsluga_jednego_przycisku.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) obsluga_jednego_przycisku.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
