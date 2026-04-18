# RISC-V Linker & Build Environment

A minimalist framework for building **Bare-metal** C applications for the **RV32I** architecture. This project is designed to generate separate memory images for **imem** (instructions) and **dmem** (data), which can be directly loaded into simulators or FPGA systems.

## Features
* **Memory Splitting:** Automatic generation of separate binaries for IMEM and DMEM.
* **GP Optimization:** Pre-configured linker script with `__global_pointer$` support to optimize access to small data.
* **Zero Dependency:** No standard libraries required (`-nostdlib`), making it ideal for custom cores.

## Requirements
Ensure you have the **bare-metal** version gcc installed:
* **`riscv64-unknown-elf-gcc`** (or `riscv32-unknown-elf-gcc`)

## Project Structure
* `linker/riscv.ld` — Linker script defining memory layout (IMEM: 0x40000000, DMEM: 0x80000000).
* `linker/start.s` — Minimal startup code for CPU initialization.
* `Makefile` — Automated compilation pipeline and post-processing via `objcopy`.

## Startup Sequence (`start.s`)
The `start.s` file serves as the entry point (`_start`) and performs critical hardware initialization before jumping to C code:
1. **Stack Pointer Setup:** Initializes the `sp` register.
2. **Global Pointer Setup:** Loads the `gp` register with `__global_pointer$`.
3. **BSS Zeroing:** Iterates through the memory range from `__BSS_START__` to `__BSS_END__` and clears it with zeroes.
4. **Jump to Main:** Transfers control to the C `main()` function.

## Usage

### Build
Place your C source file in the project root and run:
```bash
make SRC=test.c
```

### Output (in the `result/` directory)
* `imem.bin` — Pure machine code (`.text` section).
* `dmem.bin` — Combined data (`.rodata`, `.data`, `.sdata`, `.bss` sections).
* `res` — ELF file for debugging purposes.

## Memory Configuration
You can modify memory sizes or base addresses in the `linker/riscv.ld` file:
* **IMEM:** `ORIGIN = 0x40000000, LENGTH = 32K`
* **DMEM:** `ORIGIN = 0x80000000, LENGTH = 16K`

## Clean
```bash
make clean
```

---

### Why is this needed?
Standard build tools typically output a single unified ELF or binary file. This project automates the routine of extracting specific sections for systems with separate instruction and data memories (Harvard architecture), a common requirement for custom RISC-V cores on FPGAs.