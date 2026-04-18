Here is the English translation of your README, keeping the technical tone and structure intact.

---

# RISC-V Linker & Build Environment

A minimalist framework for building **Bare-metal** C applications for the **RV32I** architecture. This project is designed to generate separate memory images for **imem** (instructions) and **dmem** (data), which can be directly loaded into simulators or FPGA systems.

## Features
* **Memory Splitting:** Automatic generation of separate binaries for IMEM and DMEM.
* **GP Optimization:** Pre-configured linker script with `__global_pointer$` support to optimize access to small data.
* **Zero Dependency:** No standard libraries required (`-nostdlib`), making it ideal for custom cores.

## Project Structure
* `linker/riscv.ld` — Linker script defining memory layout (IMEM: 0x40000000, DMEM: 0x80000000).
* `linker/start.s` — Minimal startup code (initializes `sp`, `gp`, and jumps to `main`).
* `Makefile` — Automated compilation pipeline and post-processing via `objcopy`.

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
Standard build tools typically output a single unified ELF or binary file. This project automates the routine of extracting specific sections for systems with separate instruction and data memories, a common requirement for custom RISC-V cores on FPGAs.