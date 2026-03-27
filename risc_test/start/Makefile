RISC32_FLAGS = -march=rv32i -mabi=ilp32 -save-temps
COMPR_FLAGS = -ffreestanding -nostdlib -ffunction-sections \
			  -fdata-sections -fno-asynchronous-unwind-tables -fno-unwind-tables
# LDFLAGS = -nostdlib -T minimal.ld -Wl,--gc-sections


CC = riscv64-unknown-elf-gcc
SRC = start.c
BASENAME = $(basename $(SRC))
OUT = $(BASENAME).o
TEMPS = temps

all: $(OUT)

$(OUT):
	mkdir -p temps
	cd temps
	$(CC) -c $(RISC32_FLAGS) $(COMPR_FLAGS) $(SRC) -o $(TEMPS)/$(OUT)
	mv $(TEMPS)/$(OUT) ./

clean:
	rm temps/*
	rm start.o

.PHONY: all clean