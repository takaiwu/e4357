GCC_BIN = 
SRC = hw01.cpp
PROJECT = hw01
OBJECTS = ./hw01.o 
INCLUDE_PATHS = -I. -I./mbed -I./mbed/TARGET_LPC1768 -I./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM -I./mbed/TARGET_LPC1768/TARGET_NXP -I./mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X -I./mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X/TARGET_MBED_LPC1768 

############################################################################### 
CC      = $(GCC_BIN)arm-none-eabi-gcc
CPP     = $(GCC_BIN)arm-none-eabi-g++
OBJDUMP = $(GCC_BIN)arm-none-eabi-objdump
SIZE 	= $(GCC_BIN)arm-none-eabi-size

CPU = -mcpu=cortex-m3 -mthumb
LD_SYS_LIBS = -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys

all: 
	$(CPP) $(CPU) $(INCLUDE_PATHS) -c $(SRC) -o $(OBJECTS)
	$(OBJDUMP) -S hw01.o > dump.txt

clean:
	rm -f $(PROJECT).elf hw01.o dump.txt





