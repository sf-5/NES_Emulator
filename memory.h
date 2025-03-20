#include <stdbool.h>

#define MEMORY_SIZE  0x10000

#define NUM_INTERNAL_RAM_MIRRORS 0x0004
#define INTERNAL_RAM_LOWER 0x0000
#define INTERNAL_RAM_UPPER 0x1FFF
#define INTERNAL_RAM_JUMP 0x0800

#define NUM_PPU_REGISTERS_MIRRORS 0x0400
#define PPU_REGISTERS_LOWER 0x2000
#define PPU_REGISTERS_UPPER 0x3FFF
#define PPU_REGISTERS_JUMP 0x0008

typedef char byte;
typedef unsigned short address;

byte memGet(address toGet);

void memSet(address toSet, byte newMem);
