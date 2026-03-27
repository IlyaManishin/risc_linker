CC = riscv64-unknown-elf-gcc
LINKER_DIR = linker/
SRC = test.c
ENTRY_SCRIPT = $(LINKER_DIR)/start.c
LINKER =  $(LINKER_DIR)/riscv.ld
OUT = res
TEMPS = temps

RISC32_FLAGS = -march=rv32i -mabi=ilp32 -save-temps
COMPR_FLAGS = -ffreestanding -nostdlib -ffunction-sections \
			  -fdata-sections -fno-asynchronous-unwind-tables -fno-unwind-tables
LDFLAGS = -T $(LINKER) -Wl,--gc-sections


all: $(OUT) move_temps

$(OUT):
	mkdir -p temps
	cd temps
	$(CC) $(RISC32_FLAGS) $(COMPR_FLAGS) $(LDFLAGS) $(SRC) $(ENTRY_SCRIPT) -o $(TEMPS)/$(OUT)
	mv $(TEMPS)/$(OUT) ./

clean:
	rm res
	rm -rf temps/*

move_temps:
	mkdir -p $(TEMPS)/i_files $(TEMPS)/o_files $(TEMPS)/s_files
	mv $(TEMPS)/*.i $(TEMPS)/i_files 2>/dev/null || true
	mv $(TEMPS)/*.o $(TEMPS)/o_files 2>/dev/null || true
	mv $(TEMPS)/*.s $(TEMPS)/s_files 2>/dev/null || true

.PHONY: all clean