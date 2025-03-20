#include "memory.h"

static byte memory[MEMORY_SIZE];

byte memGet(address toGet)
{
    return memory[toGet];
}

void memSet(address toSet, byte newMem)
{
    int repeats;
    int divisor;
    if (toSet >= INTERNAL_RAM_LOWER && toSet <= INTERNAL_RAM_UPPER) {
        repeats = NUM_INTERNAL_RAM_MIRRORS;
        divisor = INTERNAL_RAM_JUMP;
        toSet %= divisor + INTERNAL_RAM_LOWER;
    } else if (toSet >= PPU_REGISTERS_LOWER && toSet <= PPU_REGISTERS_UPPER) {
        repeats = NUM_PPU_REGISTERS_MIRRORS;
        divisor = PPU_REGISTERS_JUMP;
        toSet %= divisor + PPU_REGISTERS_LOWER;
    } else {
        repeats = 0x0001;
        divisor = toSet + 1;
    }
    
    for (int i = 0; i < repeats; i++) {
        memory[toSet + divisor * i] = newMem;
    }
}
