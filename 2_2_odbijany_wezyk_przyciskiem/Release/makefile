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
odbijany_wezyk_przyciskiem.lss \

FLASH_IMAGE += \
odbijany_wezyk_przyciskiem.hex \

EEPROM_IMAGE += \
odbijany_wezyk_przyciskiem.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: odbijany_wezyk_przyciskiem.elf secondary-outputs

# Tool invocations
odbijany_wezyk_przyciskiem.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,odbijany_wezyk_przyciskiem.map,--cref -mrelax -Wl,--gc-sections -mmcu=atmega32 -o "odbijany_wezyk_przyciskiem.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

odbijany_wezyk_przyciskiem.lss: odbijany_wezyk_przyciskiem.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S odbijany_wezyk_przyciskiem.elf  >"odbijany_wezyk_przyciskiem.lss"
	@echo 'Finished building: $@'
	@echo ' '

odbijany_wezyk_przyciskiem.hex: odbijany_wezyk_przyciskiem.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex odbijany_wezyk_przyciskiem.elf  "odbijany_wezyk_przyciskiem.hex"
	@echo 'Finished building: $@'
	@echo ' '

odbijany_wezyk_przyciskiem.eep: odbijany_wezyk_przyciskiem.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex odbijany_wezyk_przyciskiem.elf  "odbijany_wezyk_przyciskiem.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: odbijany_wezyk_przyciskiem.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 odbijany_wezyk_przyciskiem.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) odbijany_wezyk_przyciskiem.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
