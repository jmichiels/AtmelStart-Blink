
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

ifdef SystemRoot
	SHELL = cmd.exe
	MK_DIR = mkdir
else
	ifeq ($(shell uname), Linux)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), CYGWIN)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW32)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW64)
		MK_DIR = mkdir -p
	endif
endif

# List the subdirectories for creating object files
SUB_DIRS +=  \
 \
hpl/usb \
usb/class/cdc/device \
sleep_manager \
usb/device \
hpl/dmac \
samd21a/armcc/Device/SAMD21/Source \
hal/src \
hpl/pm \
samd21a/armcc/Device/SAMD21/Source/ARM \
hpl/sysctrl \
hal/utils/src \
examples \
hpl/gclk \
hpl/nvmctrl \
hpl/core \
usb

# List the object files
OBJS +=  \
hal/src/hal_io.o \
usb/class/cdc/device/cdcdf_acm.o \
hpl/nvmctrl/hpl_nvmctrl.o \
hpl/usb/hpl_usb.o \
hal/src/hal_delay.o \
hpl/pm/hpl_pm.o \
hpl/core/hpl_init.o \
hal/utils/src/utils_list.o \
hpl/core/hpl_core_m0plus_base.o \
hal/utils/src/utils_assert.o \
usb_start.o \
hpl/sysctrl/hpl_sysctrl.o \
sleep_manager/sleep_manager.o \
usb/usb_protocol.o \
hpl/gclk/hpl_gclk.o \
hal/src/hal_flash.o \
hal/src/hal_init.o \
sleep_manager_main.o \
hal/src/hal_usb_device.o \
main.o \
samd21a/armcc/Device/SAMD21/Source/ARM/startup_SAMD21.o \
examples/driver_examples.o \
driver_init.o \
samd21a/armcc/Device/SAMD21/Source/system_samd21.o \
hal/src/hal_gpio.o \
hal/utils/src/utils_event.o \
hal/src/hal_sleep.o \
hpl/dmac/hpl_dmac.o \
atmel_start.o \
usb/device/usbdc.o \
hal/src/hal_atomic.o

OBJS_AS_ARGS +=  \
"hal/src/hal_io.o" \
"usb/class/cdc/device/cdcdf_acm.o" \
"hpl/nvmctrl/hpl_nvmctrl.o" \
"hpl/usb/hpl_usb.o" \
"hal/src/hal_delay.o" \
"hpl/pm/hpl_pm.o" \
"hpl/core/hpl_init.o" \
"hal/utils/src/utils_list.o" \
"hpl/core/hpl_core_m0plus_base.o" \
"hal/utils/src/utils_assert.o" \
"usb_start.o" \
"hpl/sysctrl/hpl_sysctrl.o" \
"sleep_manager/sleep_manager.o" \
"usb/usb_protocol.o" \
"hpl/gclk/hpl_gclk.o" \
"hal/src/hal_flash.o" \
"hal/src/hal_init.o" \
"sleep_manager_main.o" \
"hal/src/hal_usb_device.o" \
"main.o" \
"samd21a/armcc/Device/SAMD21/Source/ARM/startup_SAMD21.o" \
"examples/driver_examples.o" \
"driver_init.o" \
"samd21a/armcc/Device/SAMD21/Source/system_samd21.o" \
"hal/src/hal_gpio.o" \
"hal/utils/src/utils_event.o" \
"hal/src/hal_sleep.o" \
"hpl/dmac/hpl_dmac.o" \
"atmel_start.o" \
"usb/device/usbdc.o" \
"hal/src/hal_atomic.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"usb/usb_protocol.d" \
"hal/utils/src/utils_event.d" \
"hal/src/hal_io.d" \
"usb/class/cdc/device/cdcdf_acm.d" \
"samd21a/armcc/Device/SAMD21/Source/ARM/startup_SAMD21.d" \
"hpl/usb/hpl_usb.d" \
"samd21a/armcc/Device/SAMD21/Source/system_samd21.d" \
"hpl/nvmctrl/hpl_nvmctrl.d" \
"hpl/core/hpl_core_m0plus_base.d" \
"hal/utils/src/utils_list.d" \
"usb_start.d" \
"hal/utils/src/utils_assert.d" \
"hal/src/hal_delay.d" \
"hpl/core/hpl_init.d" \
"hpl/sysctrl/hpl_sysctrl.d" \
"hal/src/hal_flash.d" \
"hpl/gclk/hpl_gclk.d" \
"hal/src/hal_usb_device.d" \
"sleep_manager_main.d" \
"hal/src/hal_init.d" \
"sleep_manager/sleep_manager.d" \
"hpl/dmac/hpl_dmac.d" \
"driver_init.d" \
"main.d" \
"examples/driver_examples.d" \
"hal/src/hal_sleep.d" \
"hal/src/hal_gpio.d" \
"hal/src/hal_atomic.d" \
"usb/device/usbdc.d" \
"hpl/pm/hpl_pm.d" \
"atmel_start.d"

OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

vpath %.c ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARMCC Linker
	$(QUOTE)armlink$(QUOTE) --ro-base 0x00000000 --entry 0x00000000 --rw-base 0x20000000 --entry Reset_Handler --first __Vectors \
--strict --summary_stderr --info summarysizes --map --xref --callgraph --symbols \
--info sizes --info totals --info unused --info veneers --list $(OUTPUT_FILE_NAME).map \
-o $(OUTPUT_FILE_NAME).elf --cpu Cortex-M0+ \
$(OBJS_AS_ARGS)

	@echo Finished building target: $@

# Compiler target(s)




%.o: %.c
	@echo Building file: $<
	@echo ARMCC Compiler
	$(QUOTE)armcc$(QUOTE) --c99 -c -DDEBUG -O1 -g --apcs=interwork --split_sections --cpu Cortex-M0+ -D__SAMD21G18A__ \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/nvmctrl" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sysctrl" -I"../hpl/usb" -I"../hri" -I"../" -I"../config" -I"../sleep_manager" -I"../" -I"../config" -I"../usb" -I"../usb/class/cdc" -I"../usb/class/cdc/device" -I"../usb/device" -I"../" -I"../CMSIS/Include" -I"../samd21a/include"  \
--depend "$@"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo ARMCC Assembler
	$(QUOTE)armasm$(QUOTE) -g --apcs=interwork --cpu Cortex-M0+ --pd "D__SAMD21G18A__ SETA 1" \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/nvmctrl" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sysctrl" -I"../hpl/usb" -I"../hri" -I"../" -I"../config" -I"../sleep_manager" -I"../" -I"../config" -I"../usb" -I"../usb/class/cdc" -I"../usb/class/cdc/device" -I"../usb/device" -I"../" -I"../CMSIS/Include" -I"../samd21a/include"  \
--depend "$(@:%.o=%.d)" -o "$@" "$<"

	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARMCC Preprocessing Assembler
	$(QUOTE)armcc$(QUOTE) --c99 -c -DDEBUG -O1 -g --apcs=interwork --split_sections --cpu Cortex-M0+ -D__SAMD21G18A__ \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/nvmctrl" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sysctrl" -I"../hpl/usb" -I"../hri" -I"../" -I"../config" -I"../sleep_manager" -I"../" -I"../config" -I"../usb" -I"../usb/class/cdc" -I"../usb/class/cdc/device" -I"../usb/device" -I"../" -I"../CMSIS/Include" -I"../samd21a/include"  \
--depend "$@"  -o "$@" "$<"

	@echo Finished building: $<

# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).map $(OUTPUT_FILE_NAME).elf
