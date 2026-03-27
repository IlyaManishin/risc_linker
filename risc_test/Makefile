LINKER_DIR = linker/
TEMPS_DIR = temps/
OUT_DIR = result/

START_SCRIPT = $(LINKER_DIR)/start.c
LINKER = $(LINKER_DIR)/riscv.ld

SRC = test.c
OUT = res  

CC = riscv64-unknown-elf-gcc
RISC32_FLAGS = -march=rv32i -mabi=ilp32 -save-temps
COMPR_FLAGS = -ffreestanding -nostdlib -ffunction-sections \
			  -fdata-sections -fno-asynchronous-unwind-tables -fno-unwind-tables
LDFLAGS = -T $(LINKER) -Wl,--gc-sections


all: $(OUT) move_temps

$(OUT):
	mkdir -p $(TEMPS_DIR)
	mkdir -p $(OUT_DIR)

	$(CC) $(RISC32_FLAGS) $(COMPR_FLAGS) $(LDFLAGS) $(SRC) $(START_SCRIPT) -o $(TEMPS_DIR)/$(OUT)
	mv $(TEMPS_DIR)/$(OUT) $(OUT_DIR)

clean:
	rm res
	rm -rf temps/*

move_temps:
	mkdir -p $(TEMPS_DIR)/i_files $(TEMPS_DIR)/o_files $(TEMPS_DIR)/s_files
	mv $(TEMPS_DIR)/*.i $(TEMPS_DIR)/i_files 2>/dev/null || true
	mv $(TEMPS_DIR)/*.o $(TEMPS_DIR)/o_files 2>/dev/null || true
	mv $(TEMPS_DIR)/*.s $(TEMPS_DIR)/s_files 2>/dev/null || true

.PHONY: all clean