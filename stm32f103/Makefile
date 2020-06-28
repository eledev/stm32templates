
TARGET = main

#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
AR = $(PREFIX)ar
SZ = $(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
GDB = $(PREFIX)gdb
SF = st-flash
DEBUG = 1

# C defines
C_DEFS =  \
-DSTM32F10X_MD \
-DUSE_STDPERIPH_DRIVER \
-DUSE_FULL_ASSERT


# cpu
CPU = -mcpu=cortex-m3

# mcu
MCU = $(CPU) -mthumb 

CFLAGS = $(CPU) $(MCU) -O0 $(C_DEFS) -Wall -fdata-sections -ffunction-sections
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" 
# -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F103C8Tx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys
LIBDIR =

LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections



######################################
# source
######################################
# C sources
C_SOURCES =  \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_adc.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_bkp.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_can.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_cec.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_crc.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_dac.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_dbgmcu.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_dma.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_flash.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_fsmc.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_i2c.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_iwdg.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_pwr.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_rtc.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_sdio.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_spi.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_tim.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c \
src/STM32F10x_StdPeriph_Driver/src/stm32f10x_wwdg.c \
src/STM32F10x_StdPeriph_Driver/src/misc.c \
src/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c \
src/stm32f10x_it.c \
src/$(TARGET).c 



# ASM sources
ASM_SOURCES =  \
src/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s



SRC_DIR = \
src/CMSIS/CM3/CoreSupport \
src/CMSIS/CM3/DeviceSupport/ST/STM32F10x \
src/STM32F10x_StdPeriph_Driver/src \






# C includes
C_INCLUDES =  \
-Isrc/STM32F10x_StdPeriph_Driver/inc \
-Isrc/CMSIS/CM3/CoreSupport \
-Isrc/CMSIS/CM3/DeviceSupport/ST/STM32F10x \
-Isrc/src





# Build path
BUILD_DIR = build

vpath %.c $(sort $(dir $(C_SOURCES)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

	
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))

all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) $(C_INCLUDES) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@
	


$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@


#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)
	
	
#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)


###########################################################
# chip program via st-link
###########################################################
install:
	$(SF) --reset write $(BUILD_DIR)/$(TARGET).bin 0x8000000


#############################################################
# chip reset via st-link
#############################################################
reset:
	$(SF) reset


###########################################################
# chip program via black magic probe
###########################################################
installgdb:
	$(GDB) -ex "target extended-remote /dev/ttyACM0" -ex "mon swdp_scan" -ex "att 1" -ex "load $(BUILD_DIR)/$(TARGET).elf" -ex "detach" -ex "quit"
  

############################################################
# chip erase program via black magic probe
############################################################
erasegdb:
	$(GDB) -ex "target extended-remote /dev/ttyACM0"   -ex "mon swdp_scan"  -ex "att 1" -ex "mon erase_mass" -ex "detach" -ex "quit"

