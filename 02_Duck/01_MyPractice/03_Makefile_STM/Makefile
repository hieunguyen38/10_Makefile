##########################################
# Check MODULE, -D.. #define ..
#ifeq($(MODULE),GPIO)
#	CCFLAGS = -DGPIO
#endif
############################################

GCC_DIR := C:/Toolchain/Arm_Toolchain
CC = $(GCC_DIR)/bin/arm-none-eabi-gcc
LD_FILE := Linker/stm_ls.ld

# MODULE := GPIO Sử dụng export cho tùy module

include ./User/make/config.mak

SRC_FILES += $(foreach SRC_DIRS,$(SRC_DIRS),$(wildcard $(SRC_DIRS)/*))

# CC Opt for INC_DIRS (-I để tìm các file.c trong nhiều inc)
INC_DIRS_OPT += $(foreach INC_DIRS,$(INC_DIRS),-I$(INC_DIRS))

# Object Files
OBJ_FILES := $(notdir $(SRC_FILES))
OBJ_FILES := $(subst .c,.o,$(OBJ_FILES))         
PATH_OJBS := $(foreach OBJ_FILES,$(OBJ_FILES),$(PATH_OUTPUT)/$(OBJ_FILES))


CHIP = cortex-m4

CCFLAGS = -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 -I$(INC_DIRS_OPT)
LDFLAGS = -nostdlib -T $(LD_FILE) -Wl,-Map=$(PATH_OUTPUT)/$(MODULE).map

vpath %.c $(SRC_DIRS)

build: $(PATH_OUTPUT)/$(MODULE).hex

%.o: %.c
	$(CC) $(CCFLAGS) -o $(PATH_OUTPUT)/$@ $^

$(PATH_OUTPUT)/$(MODULE).elf: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $(PATH_OJBS)
	
$(PATH_OUTPUT)/$(MODULE).hex: $(PATH_OUTPUT)/$(MODULE).elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$^" "$@"
	
run:
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -ME 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -p "$(PATH_OUTPUT)/$(MODULE).hex" 0x08000000
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -rst
	
clean:
	rm -rf $(PATH_OUTPUT)/*
	
print-%:
	@echo $($(subst print-,,$@))