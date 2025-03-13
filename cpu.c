#include "cpu.h"

static byte memory[MEMORY_SIZE] = {0};

byte getAddress(address toGet){
    return memory[toGet];
}