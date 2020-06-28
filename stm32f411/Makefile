
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
-DSTM32F411xE \
-DUSE_STDPERIPH_DRIVER \
-DUSE_FULL_ASSERT


# cpu
CPU = -mcpu=cortex-m4
# fpu
FPU = -mfloat-abi=hard -mfpu=fpv4-sp-d16
# mcu
MCU = $(CPU) $(FPU) -mthumb



CFLAGS = $(MCU)  -O0 $(C_DEFS) -Wall -fdata-sections -ffunction-sections
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"
# -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F411RETx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys
LIBDIR =

LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections



######################################
# source
######################################
# C sources
C_SOURCES =  \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cec.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dfsdm.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma2d.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dsi.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash_ramfunc.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_lptim.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_ltdc.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_qspi.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sai.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spdifrx.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c \
src/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.c \
src/STM32F4xx_StdPeriph_Driver/src/misc.c \
src/CMSIS/system_stm32f4xx.c \
src/stm32f4xx_it.c \
src/$(TARGET).c \
src/init.c

# ASM sources
ASM_SOURCES =  \
src/CMSIS/startup_stm32f40_41xxx.s

# C includes
C_INCLUDES =  \
-Isrc/STM32F4xx_StdPeriph_Driver/inc \
-Isrc/CMSIS/ \
-Isrc/CMSIS/Include \
-Isrc

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
	$(GDB) -q -ex "target extended-remote /dev/ttyACM0" -ex "mon swdp_scan" -ex "att 1" -ex "load $(BUILD_DIR)/$(TARGET).elf" -ex "detach" -ex "quit"
  

############################################################
# chip erase via black magic probe
############################################################
erasegdb:
	$(GDB) -q -ex "target extended-remote /dev/ttyACM0"   -ex "mon swdp_scan"  -ex "att 1" -ex "mon erase_mass" -ex "detach" -ex "quit"
