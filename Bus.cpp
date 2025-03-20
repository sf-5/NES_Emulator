#include "Bus.h"
#include <iostream>

Bus::Bus()
{
    for (auto &i : ram) {
        i = 0x00;
    }

    cpu.ConnectBus(this);
}

void Bus::write(uint16_t address, uint8_t data)
{
    if (address >= 0 && address < RAM_MAX) {
        ram[address] = data;
    }
}

uint8_t Bus::read(uint16_t address)
{
    if (address >= 0 && address < RAM_MAX) {
        return ram[address];
    }

    return 0x00;
}
