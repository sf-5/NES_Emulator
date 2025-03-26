#include "CPU.h"

#define RAM_MAX 0x10000

class Bus
{
public:
    Bus();

    CPU cpu;

    uint8_t ram[RAM_MAX];

    void write(uint16_t address, uint8_t data);
    uint8_t read(uint16_t address);
};
