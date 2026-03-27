CC = riscv64-unknown-elf-gcc
LINKER_DIR = linker/
SRC = test.c
ENTRY_OBJ = $(LINKER_DIR)/_start.o
LINKER =  $(LINKER_DIR)/riscv.ld
OUT = res
TEMPS = temps

RISC32_FLAGS = -march=rv32i -mabi=ilp32 -save-temps
COMPR_FLAGS = -ffreestanding -nostdlib -ffunction-sections \
			  -fdata-sections -fno-asynchronous-unwind-tables -fno-unwind-tables
LDFLAGS = -T $(LINKER) -Wl,--gc-sections
# LDFLAGS = ""



all: $(OUT)

$(OUT):
	mkdir -p temps
	cd temps
	$(CC) $(RISC32_FLAGS) $(COMPR_FLAGS) $(LDFLAGS) $(SRC) $(ENTRY_OBJ) -o $(TEMPS)/$(OUT)
	mv $(TEMPS)/$(OUT) ./

clean:
	rm res

.PHONY: all clean