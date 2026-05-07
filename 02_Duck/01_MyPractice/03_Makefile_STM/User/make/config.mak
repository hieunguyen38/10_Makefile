PATH_OUTPUT := ./Output

# Include Files
INC_DIRS += User/inc             \
			Driver/$(MODULE)/inc \
			Driver/UART/inc 
    
INC_FILES += $(foreach INC_DIRS,$(INC_DIRS),$(wildcard $(INC_DIRS)/*))

# Sourc Files
SRC_DIRS += User/src             \
			Driver/$(MODULE)/src \
			Startup