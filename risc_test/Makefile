RISC32_FLAGS = -march=rv32i -mabi=ilp32 -save-temps
COMPR_FLAGS = -ffreestanding -nostdlib -ffunction-sections -fdata-sections -fno-asynchronous-unwind-tables -fno-unwind-tables
# LDFLAGS = -nostdlib -T minimal.ld -Wl,--gc-sections


CC = riscv64-linux-gnu-gcc
SRC = test.c
OUT = out.bin

all: $(OUT)

$(OUT):
	mkdir temps
	cd temps
	$(CC) $(RISC32_FLAGS) ${COMPR_FLAGS} $(SRC) -o res
	mv res ../
	cd ..

clean:
	rm -f 

.PHONY: all clean