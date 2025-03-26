#include "Bus.h"

CPU::CPU()
{
    using a = CPU;
    lookup =
    {
        { "BRK", &a::BRK, &a::IMM, 7 },{ "ORA", &a::ORA, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "ORA", &a::ORA, &a::ZP0, 3 },{ "ASL", &a::ASL, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PHP", &a::PHP, &a::IMP, 3 },{ "ORA", &a::ORA, &a::IMM, 2 },{ "ASL", &a::ASL, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ABS, 4 },{ "ASL", &a::ASL, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
        { "BPL", &a::BPL, &a::REL, 2 },{ "ORA", &a::ORA, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ZPX, 4 },{ "ASL", &a::ASL, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLC", &a::CLC, &a::IMP, 2 },{ "ORA", &a::ORA, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ABX, 4 },{ "ASL", &a::ASL, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
        { "JSR", &a::JSR, &a::ABS, 6 },{ "AND", &a::AND, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "BIT", &a::BIT, &a::ZP0, 3 },{ "AND", &a::AND, &a::ZP0, 3 },{ "ROL", &a::ROL, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PLP", &a::PLP, &a::IMP, 4 },{ "AND", &a::AND, &a::IMM, 2 },{ "ROL", &a::ROL, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "BIT", &a::BIT, &a::ABS, 4 },{ "AND", &a::AND, &a::ABS, 4 },{ "ROL", &a::ROL, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
        { "BMI", &a::BMI, &a::REL, 2 },{ "AND", &a::AND, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "AND", &a::AND, &a::ZPX, 4 },{ "ROL", &a::ROL, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SEC", &a::SEC, &a::IMP, 2 },{ "AND", &a::AND, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "AND", &a::AND, &a::ABX, 4 },{ "ROL", &a::ROL, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
        { "RTI", &a::RTI, &a::IMP, 6 },{ "EOR", &a::EOR, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "EOR", &a::EOR, &a::ZP0, 3 },{ "LSR", &a::LSR, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PHA", &a::PHA, &a::IMP, 3 },{ "EOR", &a::EOR, &a::IMM, 2 },{ "LSR", &a::LSR, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "JMP", &a::JMP, &a::ABS, 3 },{ "EOR", &a::EOR, &a::ABS, 4 },{ "LSR", &a::LSR, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
        { "BVC", &a::BVC, &a::REL, 2 },{ "EOR", &a::EOR, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "EOR", &a::EOR, &a::ZPX, 4 },{ "LSR", &a::LSR, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLI", &a::CLI, &a::IMP, 2 },{ "EOR", &a::EOR, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "EOR", &a::EOR, &a::ABX, 4 },{ "LSR", &a::LSR, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
        { "RTS", &a::RTS, &a::IMP, 6 },{ "ADC", &a::ADC, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "ADC", &a::ADC, &a::ZP0, 3 },{ "ROR", &a::ROR, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PLA", &a::PLA, &a::IMP, 4 },{ "ADC", &a::ADC, &a::IMM, 2 },{ "ROR", &a::ROR, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "JMP", &a::JMP, &a::IND, 5 },{ "ADC", &a::ADC, &a::ABS, 4 },{ "ROR", &a::ROR, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
        { "BVS", &a::BVS, &a::REL, 2 },{ "ADC", &a::ADC, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "ADC", &a::ADC, &a::ZPX, 4 },{ "ROR", &a::ROR, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SEI", &a::SEI, &a::IMP, 2 },{ "ADC", &a::ADC, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "ADC", &a::ADC, &a::ABX, 4 },{ "ROR", &a::ROR, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
        { "???", &a::NOP, &a::IMP, 2 },{ "STA", &a::STA, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "STY", &a::STY, &a::ZP0, 3 },{ "STA", &a::STA, &a::ZP0, 3 },{ "STX", &a::STX, &a::ZP0, 3 },{ "???", &a::XXX, &a::IMP, 3 },{ "DEY", &a::DEY, &a::IMP, 2 },{ "???", &a::NOP, &a::IMP, 2 },{ "TXA", &a::TXA, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "STY", &a::STY, &a::ABS, 4 },{ "STA", &a::STA, &a::ABS, 4 },{ "STX", &a::STX, &a::ABS, 4 },{ "???", &a::XXX, &a::IMP, 4 },
        { "BCC", &a::BCC, &a::REL, 2 },{ "STA", &a::STA, &a::IZY, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "STY", &a::STY, &a::ZPX, 4 },{ "STA", &a::STA, &a::ZPX, 4 },{ "STX", &a::STX, &a::ZPY, 4 },{ "???", &a::XXX, &a::IMP, 4 },{ "TYA", &a::TYA, &a::IMP, 2 },{ "STA", &a::STA, &a::ABY, 5 },{ "TXS", &a::TXS, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 5 },{ "???", &a::NOP, &a::IMP, 5 },{ "STA", &a::STA, &a::ABX, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "???", &a::XXX, &a::IMP, 5 },
        { "LDY", &a::LDY, &a::IMM, 2 },{ "LDA", &a::LDA, &a::IZX, 6 },{ "LDX", &a::LDX, &a::IMM, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "LDY", &a::LDY, &a::ZP0, 3 },{ "LDA", &a::LDA, &a::ZP0, 3 },{ "LDX", &a::LDX, &a::ZP0, 3 },{ "???", &a::XXX, &a::IMP, 3 },{ "TAY", &a::TAY, &a::IMP, 2 },{ "LDA", &a::LDA, &a::IMM, 2 },{ "TAX", &a::TAX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "LDY", &a::LDY, &a::ABS, 4 },{ "LDA", &a::LDA, &a::ABS, 4 },{ "LDX", &a::LDX, &a::ABS, 4 },{ "???", &a::XXX, &a::IMP, 4 },
        { "BCS", &a::BCS, &a::REL, 2 },{ "LDA", &a::LDA, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 5 },{ "LDY", &a::LDY, &a::ZPX, 4 },{ "LDA", &a::LDA, &a::ZPX, 4 },{ "LDX", &a::LDX, &a::ZPY, 4 },{ "???", &a::XXX, &a::IMP, 4 },{ "CLV", &a::CLV, &a::IMP, 2 },{ "LDA", &a::LDA, &a::ABY, 4 },{ "TSX", &a::TSX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 4 },{ "LDY", &a::LDY, &a::ABX, 4 },{ "LDA", &a::LDA, &a::ABX, 4 },{ "LDX", &a::LDX, &a::ABY, 4 },{ "???", &a::XXX, &a::IMP, 4 },
        { "CPY", &a::CPY, &a::IMM, 2 },{ "CMP", &a::CMP, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "CPY", &a::CPY, &a::ZP0, 3 },{ "CMP", &a::CMP, &a::ZP0, 3 },{ "DEC", &a::DEC, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "INY", &a::INY, &a::IMP, 2 },{ "CMP", &a::CMP, &a::IMM, 2 },{ "DEX", &a::DEX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "CPY", &a::CPY, &a::ABS, 4 },{ "CMP", &a::CMP, &a::ABS, 4 },{ "DEC", &a::DEC, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
        { "BNE", &a::BNE, &a::REL, 2 },{ "CMP", &a::CMP, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "CMP", &a::CMP, &a::ZPX, 4 },{ "DEC", &a::DEC, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLD", &a::CLD, &a::IMP, 2 },{ "CMP", &a::CMP, &a::ABY, 4 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "CMP", &a::CMP, &a::ABX, 4 },{ "DEC", &a::DEC, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
        { "CPX", &a::CPX, &a::IMM, 2 },{ "SBC", &a::SBC, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "CPX", &a::CPX, &a::ZP0, 3 },{ "SBC", &a::SBC, &a::ZP0, 3 },{ "INC", &a::INC, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "INX", &a::INX, &a::IMP, 2 },{ "SBC", &a::SBC, &a::IMM, 2 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::SBC, &a::IMP, 2 },{ "CPX", &a::CPX, &a::ABS, 4 },{ "SBC", &a::SBC, &a::ABS, 4 },{ "INC", &a::INC, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
        { "BEQ", &a::BEQ, &a::REL, 2 },{ "SBC", &a::SBC, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "SBC", &a::SBC, &a::ZPX, 4 },{ "INC", &a::INC, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SED", &a::SED, &a::IMP, 2 },{ "SBC", &a::SBC, &a::ABY, 4 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "SBC", &a::SBC, &a::ABX, 4 },{ "INC", &a::INC, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
    };
}

uint8_t CPU::read(uint16_t address)
{
    return bus->read(address);
}

void CPU::write(uint16_t address, uint8_t data)
{
    bus->write(address, data);
}

void CPU::clock()
{
    if (cycles == 0)
    {
        opcode = read(program_counter);
        
        program_counter++;

        cycles = lookup[opcode].cycles;
        uint8_t additional_cycle_1 = (this->*lookup[opcode].address_mode)();
        uint8_t additional_cycle_2 = (this->*lookup[opcode].operation)();

        cycles += (additional_cycle_1 & additional_cycle_2);
    }
    
    cycles--;
}

uint8_t CPU::GetFlag(flag f)
{
    if ((status & f) > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void CPU::SetFlag(flag f, bool v) {
    if (v) {
        status |= f;
    }
    else {
        status &= ~f;
    }
}

/***** ADDRESSING MODES *****/

/**
 * Implied - no data in the instruction, but might
 * operate on the accumulator.
 */
uint8_t CPU::IMP()
{
    fetched = accumulator;
    return 0;
}

/**
 * Immediate - data is part of the instruction, the
 * next byte.
 */
uint8_t CPU::IMM()
{
    addr_abs = program_counter++;
    return 0;
}

/**
 * Zero page addressing - byte of data is in page
 * zero.
 */
uint8_t CPU::ZP0()
{
    addr_abs = read(program_counter);
    program_counter++;
    addr_abs &= 0x00FF;
    return 0;
}

/**
 * Zero page addressing with X register offset -
 * the address given with the instruction + the
 * contents of the X register.
 */
uint8_t CPU::ZPX()
{
    addr_abs = read(program_counter) + x;
    program_counter++;
    addr_abs &= 0x00FF;
    return 0;
}

/**
 * Zero page addressing with Y register offset -
 * the address given with the instruction + the
 * contents of the Y register.
 */
uint8_t CPU::ZPY()
{
    addr_abs = read(program_counter) + y;
    program_counter++;
    addr_abs &= 0x00FF;
    return 0;
}

/**
 * Gets full address from two bytes.
 */
uint8_t CPU::ABS()
{
    uint16_t low_byte = read(program_counter);
    program_counter++;
    uint16_t high_byte = read(program_counter);
    program_counter++;

    addr_abs = (high_byte << 8) | low_byte;

    return 0;
}

/**
 * Absolute address with X register offset.
 */
uint8_t CPU::ABX()
{
    uint16_t low_byte = read(program_counter);
    program_counter++;
    uint16_t high_byte = read(program_counter);
    program_counter++;

    addr_abs = (high_byte << 8) | low_byte;
    addr_abs += x;

    if ((addr_abs & 0xFF00) != (high_byte << 8)) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * Absolute address with Y register offset.
 */
uint8_t CPU::ABY()
{
    uint16_t low_byte = read(program_counter);
    program_counter++;
    uint16_t high_byte = read(program_counter);
    program_counter++;

    addr_abs = (high_byte << 8) | low_byte;
    addr_abs += y;

    if ((addr_abs & 0xFF00) != (high_byte << 8)) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * Indirect address.
 */
uint8_t CPU::IND()
{
    uint16_t low_byte = read(program_counter);
    program_counter++;
    uint16_t high_byte = read(program_counter);
    program_counter++;

    uint16_t pointer = (high_byte << 8) | low_byte;

    if (low_byte == 0x00FF) {
        low_byte = read(pointer);
        high_byte = read(pointer & 0xFF00);

        addr_abs = (high_byte << 8) | low_byte;
    }
    else {
        low_byte = read(pointer);
        high_byte = read(pointer + 1);

        addr_abs = (high_byte << 8) | low_byte;
    }

    return 0;
}

/**
 * Indirect addressing of the zero page with
 * X offset.
 */
uint8_t CPU::IZX()
{
    uint16_t pointer = read(program_counter) + (uint16_t)x;
    program_counter++;

    uint16_t low_byte = read(pointer & 0x00FF);
    uint16_t high_byte = read((pointer + 1) & 0x00FF);

    addr_abs = (high_byte << 8) | low_byte;

    return 0;
}

/**
 * Indirect addressing of the zero page with
 * Y offset.
 */
uint8_t CPU::IZY()
{
    uint16_t pointer = read(program_counter);
    program_counter++;

    uint16_t low_byte = read(pointer & 0x00FF);
    uint16_t high_byte = read((pointer + 1) & 0x00FF);

    addr_abs = (high_byte << 8) | low_byte;
    addr_abs += y;

    if ((addr_abs & 0xFF00) != (high_byte << 8)) {
        return 1;
    }
    else {
        return 0;
    }

    return 0;
}

/**
 * Relative addressing mode for branching
 * instructions.
 */

uint8_t CPU::REL()
{
    addr_rel = read(program_counter);
    program_counter++;

    if (addr_rel & 0x80) {
        addr_rel |= 0xFF00;
    }

    return 0;
}

/***** INSTRUCTIONS *****/

uint8_t CPU::fetch()
{
    if (!(lookup[opcode].address_mode == &CPU::IMP)) {
        fetched = read(addr_abs);
    }

    return fetched;
}

/**
 * And the accumulator and the fetched value.
 */
uint8_t CPU::AND()
{
    fetch();

    accumulator = accumulator & fetched;

    SetFlag(Z, accumulator == 0x00);
    SetFlag(N, accumulator & 0x80);

    return 1;
}

/**
 * Branch if the carry bit is set.
 */
uint8_t CPU::BCS()
{
    if (GetFlag(C) == 1) {
        cycles++;
        addr_abs = program_counter + addr_rel;

        if ((addr_abs & 0xFF00) != (program_counter & 0xFF00)) {
            cycles++;
        }

        program_counter = addr_abs;
    }

    return 0;
}

/**
 * Branch is the carry bit is clear.
 */
uint8_t CPU::BCC()
{
    if (GetFlag(C) == 0) {
        cycles++;
        addr_abs = program_counter + addr_rel;

        if ((addr_abs & 0xFF00) != (program_counter & 0xFF00)) {
            cycles++;
        }

        program_counter = addr_abs;
    }

    return 0;
}

/**
 * Branch is the zero flag is set.
 */
uint8_t CPU::BEQ()
{
    if (GetFlag(Z) == 1) {
        cycles++;
        addr_abs = program_counter + addr_rel;

        if ((addr_abs & 0xFF00) != (program_counter & 0xFF00)) {
            cycles++;
        }

        program_counter = addr_abs;
    }

    return 0;
}

/**
 * Branch is the negative flag is set.
 */
uint8_t CPU::BMI()
{
    if (GetFlag(N) == 1) {
        cycles++;
        addr_abs = program_counter + addr_rel;

        if ((addr_abs & 0xFF00) != (program_counter & 0xFF00)) {
            cycles++;
        }

        program_counter = addr_abs;
    }

    return 0;
}

/**
 * Branch is the zero flag is clear.
 */
uint8_t CPU::BNE()
{
    if (GetFlag(Z) == 0) {
        cycles++;
        addr_abs = program_counter + addr_rel;

        if ((addr_abs & 0xFF00) != (program_counter & 0xFF00)) {
            cycles++;
        }

        program_counter = addr_abs;
    }

    return 0;
}

/**
 * Branch is the negative flag is clear.
 */
uint8_t CPU::BPL()
{
    if (GetFlag(N) == 0) {
        cycles++;
        addr_abs = program_counter + addr_rel;

        if ((addr_abs & 0xFF00) != (program_counter & 0xFF00)) {
            cycles++;
        }

        program_counter = addr_abs;
    }

    return 0;
}

/**
 * Branch is the overflow flag is clear.
 */
uint8_t CPU::BVC()
{
    if (GetFlag(V) == 0) {
        cycles++;
        addr_abs = program_counter + addr_rel;

        if ((addr_abs & 0xFF00) != (program_counter & 0xFF00)) {
            cycles++;
        }

        program_counter = addr_abs;
    }

    return 0;
}

/**
 * Branch is the overflow flag is set.
 */
uint8_t CPU::BVS()
{
    if (GetFlag(V) == 1) {
        cycles++;
        addr_abs = program_counter + addr_rel;

        if ((addr_abs & 0xFF00) != (program_counter & 0xFF00)) {
            cycles++;
        }

        program_counter = addr_abs;
    }

    return 0;
}

/**
 * Clears the carry flag.
 */
uint8_t CPU::CLC()
{
    SetFlag(C, false);
    return 0;
}

/**
 * Clears the decimal flag.
 */
uint8_t CPU::CLD()
{
    SetFlag(D, false);
    return 0;
}

/**
 * Clears the interrupt disable flag.
 */
uint8_t CPU::CLI()
{
    SetFlag(I, false);
    return 0;
}

/**
 * Clears the overflow bit.
 */
uint8_t CPU::CLV()
{
    SetFlag(V, false);
    return 0;
}

/**
 * Add the value of the fetched data and the carry
 * bit to the accumulator. Set the necessary flags.
 */
uint8_t CPU::ADC()
{
    fetch();
    uint16_t temp = (uint16_t)accumulator + (uint16_t)fetched + (uint16_t)GetFlag(C);
    SetFlag(C, temp > 255);
    SetFlag(Z, (temp & 0x00FF) == 0);
    SetFlag(N, temp & 0x80);
    SetFlag(V, (~((uint16_t)accumulator ^ (uint16_t)fetched) & ((uint16_t)accumulator ^ (uint16_t)temp)) & 0x0080);
    accumulator = temp & 0x00FF;
    return 1;
}

/**
 * Subtract the value of the fetched data and the
 * opposite of the carry bit from the accumulator.
 * Set the necessary flags.
 */
uint8_t CPU::SBC()
{
    fetch();

    uint16_t value = ((uint16_t)fetched) ^ 0x00FF;

    uint16_t temp = (uint16_t)accumulator + (uint16_t)fetched + (uint16_t)GetFlag(C);
    SetFlag(C, temp > 255);
    SetFlag(Z, (temp & 0x00FF) == 0);
    SetFlag(N, temp & 0x80);
    SetFlag(V, (~((uint16_t)accumulator ^ (uint16_t)fetched) & ((uint16_t)accumulator ^ (uint16_t)temp)) & 0x0080);
    accumulator = temp & 0x00FF;
    return 1;
}

/**
 * Pushes the accumulator to the stack.
 */
uint8_t CPU::PHA()
{
    write(0x0100 + stack_pointer, accumulator);
    stack_pointer--;
    return 0;
}

/**
 * Set the accumulator to data pulled from the stack.
 */
uint8_t CPU::PLA()
{
    stack_pointer++;
    accumulator = read(0x0100 + stack_pointer);
    SetFlag(Z, accumulator == 0x00);
    SetFlag(N, accumulator & 0x80);
    return 0;
}

/**
 * Resets all values to known states and sets program
 * counter to address found at 0xFFFC.
 */
void CPU::reset()
{
    accumulator = 0x00;
    x = 0x00;
    y = 0x00;
    stack_pointer = 0xFD;
    status = 0x00 | U;

    addr_abs = 0xFFFC;

    uint16_t low_byte = read(addr_abs);
    uint16_t high_byte = read(addr_abs + 1);

    program_counter = (high_byte << 8) | low_byte;

    addr_rel = 0x0000;
    addr_abs = 0x0000;
    fetched = 0x00;

    cycles = 8;
}

/**
 * Interrupts program without destroying status,
 * sends to known address at 0xFFFE.
 */
void CPU::interrupt_request()
{
    if (GetFlag(I) == 0) {
        write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
        stack_pointer--;

        write(0x0100 + stack_pointer, program_counter & 0x00FF);
        stack_pointer--;

        SetFlag(B, 0);
        SetFlag(U, 1);
        SetFlag(I, 1);
        write(0x0100 + stack_pointer, status);
        stack_pointer--;

        addr_abs = 0xFFFE;

        uint16_t low_byte = read(addr_abs);
        uint16_t high_byte = read(addr_abs + 1);

        program_counter = (high_byte << 8) | low_byte;

        cycles = 7;
    }
}

/**
 * Interrupts program without destroying status,
 * sends to known address at 0xFFFA. Cannot be overriden.
 */
void CPU::nonmaskable_interrupt_request()
{
    write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
    stack_pointer--;

    write(0x0100 + stack_pointer, program_counter & 0x00FF);
    stack_pointer--;

    SetFlag(B, 0);
    SetFlag(U, 1);
    SetFlag(I, 1);
    write(0x0100 + stack_pointer, status);
    stack_pointer--;

    addr_abs = 0xFFFA;

    uint16_t low_byte = read(addr_abs);
    uint16_t high_byte = read(addr_abs + 1);

    program_counter = (high_byte << 8) | low_byte;

    cycles = 8;
}

/**
 * Restore state after an interrupt.
 */
uint8_t CPU::RTI()
{
    stack_pointer++;
    status = read(0x0100 + stack_pointer);
    status &= ~B;
    status &= ~U;

    stack_pointer++;
    program_counter = (uint16_t)read(0x0100 + stack_pointer);
    stack_pointer++;
    program_counter |= (uint16_t)read(0x0100 + stack_pointer) << 8;

    return 0;
}

/**
 * Shifts the bits of a memory value one position to the left.
 * May affect the carry flag.
 */
uint8_t CPU::ASL()
{
    fetch();
    uint16_t temp = ((uint16_t)fetched) << 1;

    SetFlag(C, temp > 0x00FF);
    SetFlag(Z, (temp & 0x00FF) == 0x00);
    SetFlag(N, temp & 0x80);

    if (lookup[opcode].address_mode == &CPU::IMP) {
        accumulator = temp & 0x00FF;
    }
    else {
        write(addr_abs, temp & 0x00FF);
    }

    return 0;
}

/**
 * Sets flags based on the accumulator and fetched data.
 */
uint8_t CPU::BIT()
{
    fetch();

    SetFlag(Z, (accumulator & fetched) == 0x00);
    SetFlag(N, fetched & (1 << 7));
    SetFlag(V, fetched & (1 << 6));

    return 0;
}

/**
 * Triggers an interrupt request.
 */
uint8_t CPU::BRK()
{
    write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
    stack_pointer--;

    write(0x0100 + stack_pointer, program_counter & 0x00FF);
    stack_pointer--;

    SetFlag(B, 1);
    SetFlag(U, 1);
    write(0x0100 + stack_pointer, status);
    stack_pointer--;
    SetFlag(B, 0);

    addr_abs = 0xFFFE;

    uint16_t low_byte = read(addr_abs);
    uint16_t high_byte = read(addr_abs + 1);
    SetFlag(I, 1);
    program_counter = (high_byte << 8) | low_byte;

    return 0;
}

/**
 * Compares the accumulator to a memory vale, setting
 * the appropriate flags.
 */
uint8_t CPU::CMP()
{
    fetch();

    uint16_t temp = (uint16_t)accumulator - (uint16_t)fetched;

    SetFlag(C, accumulator >= fetched);
    SetFlag(Z, (temp & 0x00FF) == 0x00);
    SetFlag(N, temp & 0x0080);

    return 0;
}

/**
 * Compares the X register to a memory vale, setting
 * the appropriate flags.
 */
uint8_t CPU::CPX()
{
    fetch();

    uint16_t temp = (uint16_t)x - (uint16_t)fetched;

    SetFlag(C, x >= fetched);
    SetFlag(Z, (temp & 0x00FF) == 0x00);
    SetFlag(N, temp & 0x0080);

    return 0;
}

/**
 * Compares the Y register to a memory vale, setting
 * the appropriate flags.
 */
uint8_t CPU::CPY()
{
    fetch();

    uint16_t temp = (uint16_t)y - (uint16_t)fetched;

    SetFlag(C, y >= fetched);
    SetFlag(Z, (temp & 0x00FF) == 0x00);
    SetFlag(N, temp & 0x0080);

    return 0;
}

/**
 * Decrements a memory location by one.
 */
uint8_t CPU::DEC()
{
    fetch();
    fetched--;

    SetFlag(Z, fetched == 0x00);
    SetFlag(N, fetched & 0x80);

    write(addr_abs, fetched);

    return 0;
}

/**
 * Decrements the X register by one.
 */
uint8_t CPU::DEX()
{
    x--;

    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);

    return 0;
}

/**
 * Decrements the Y register by one.
 */
uint8_t CPU::DEY()
{
    y--;

    SetFlag(Z, y == 0x00);
    SetFlag(N, y & 0x80);

    return 0;
}

/**
 * Exclusive-ORs a memory value and the accumulator.
 */
uint8_t CPU::EOR()
{
    fetch();
    accumulator ^= fetched;

    SetFlag(Z, fetched == 0x00);
    SetFlag(N, fetched & 0x80);

    return 0;
}

/**
 * Adds one to a memory location.
 */
uint8_t CPU::INC()
{
    fetch();
    fetched++;

    SetFlag(Z, fetched == 0x00);
    SetFlag(N, fetched & 0x80);

    write(addr_abs, fetched);

    return 0;
}

/**
 * Increments the X register by one.
 */
uint8_t CPU::INX()
{
    x++;

    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);

    return 0;
}

/**
 * Increments the Y register by one.
 */
uint8_t CPU::INY()
{
    y++;

    SetFlag(Z, y == 0x00);
    SetFlag(N, y & 0x80);

    return 0;
}

/**
 * Sets the program counter to a new value.
 */
uint8_t CPU::JMP()
{
    program_counter = addr_abs;

    return 0;
}

/**
 * Pushes the current program counter to the
 * stack, then jumps to a new address.
 */
uint8_t CPU::JSR()
{
    program_counter--;

    write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
    stack_pointer--;

    write(0x0100 + stack_pointer, program_counter & 0x00FF);
    stack_pointer--;

    program_counter = addr_abs;

    return 0;
}

/**
 * Loads a memory value to the accumulator.
 */
uint8_t CPU::LDA()
{
    fetch();

    accumulator = fetched;

    SetFlag(Z, accumulator == 0x00);
    SetFlag(N, accumulator & 0x80);

    return 1;
}

/**
 * Loads a memory value to the X register.
 */
uint8_t CPU::LDX()
{
    fetch();

    x = fetched;

    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);

    return 1;
}

/**
 * Loads a memory value to the Y register.
 */
uint8_t CPU::LDY()
{
    fetch();

    y = fetched;

    SetFlag(Z, y == 0x00);
    SetFlag(N, y & 0x80);

    return 1;
}

/**
 * Shifts the bits of a memory value or
 * the accumulator one to the right.
 */
uint8_t CPU::LSR()
{
    fetch();
    uint16_t temp = ((uint16_t)fetched) >> 1;

    SetFlag(C, temp > 0x00FF);
    SetFlag(Z, (temp & 0x00FF) == 0x00);
    SetFlag(N, temp & 0x80);

    if (lookup[opcode].address_mode == &CPU::IMP) {
        accumulator = temp & 0x00FF;
    }
    else {
        write(addr_abs, temp & 0x00FF);
    }

    return 0;
}

/**
 * No effect, wastes CPU cycles.
 */
uint8_t CPU::NOP()
{
    return 0;
}

/**
 * Bitwise or with the memory and accumulator.
 */
uint8_t CPU::ORA()
{
    fetch();

    accumulator |= fetched;
    SetFlag(Z, accumulator == 0x00);
    SetFlag(N, accumulator & 0x80);

    return 1;
}

/**
 * Pushes the status flags to the stack.
 */
uint8_t CPU::PHP()
{
    write(0x0100 + stack_pointer, status | B | U);
    SetFlag(B, 0);
    stack_pointer--;
    return 0;
}

/**
 * Pulls the status flags from the stack.
 */
uint8_t CPU::PLP()
{
    stack_pointer++;
    status = read(0x0100 + stack_pointer);
    return 0;
}

/**
 * Sets the carry flag.
 */
uint8_t CPU::SEC()
{
    SetFlag(C, 1);

    return 0;
}

/**
 * Sets the decimal flag.
 */
uint8_t CPU::SED()
{
    SetFlag(D, 1);

    return 0;
}

/**
 * Sets the interrupt disable flag.
 */
uint8_t CPU::SEI()
{
    SetFlag(I, 1);

    return 0;
}

/**
 * Stores the accumulator in memory.
 */
uint8_t CPU::STA()
{
    write(addr_abs, accumulator);

    return 0;
}

/**
 * Stores the X register in memory.
 */
uint8_t CPU::STX()
{
    write(addr_abs, x);

    return 0;
}

/**
 * Stores the Y register in memory.
 */
uint8_t CPU::STY()
{
    write(addr_abs, y);

    return 0;
}

/**
 * Copies the accumulator to the X register.
 */
uint8_t CPU::TAX()
{
    x = accumulator;

    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);

    return 0;
}

/**
 * Copies the accumulator to the Y register.
 */
uint8_t CPU::TAY()
{
    y = accumulator;
    SetFlag(Z, y == 0x00);
    SetFlag(N, y & 0x80);

    return 0;
}

/**
 * Copies the stack pointer to the X register.
 */
uint8_t CPU::TSX()
{
    x = stack_pointer;

    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);

    return 0;
}

/**
 * Copies the X register to the accumulator.
 */
uint8_t CPU::TXA()
{
    accumulator = x;

    SetFlag(Z, accumulator == 0x00);
    SetFlag(N, accumulator & 0x80);

    return 0;
}

/**
 * Copies the X register to the stack pointer.
 */
uint8_t CPU::TXS()
{
    stack_pointer = x;

    return 0;
}

/**
 * Copies the Y register to the accumulator.
 */
uint8_t CPU::TYA()
{
    accumulator = y;

    SetFlag(Z, accumulator == 0x00);
    SetFlag(N, accumulator & 0x80);

    return 0;
}

/**
 * Rotates a memory value of the accumulator left.
 */
uint8_t CPU::ROL()
{
    fetch();

    uint16_t temp = (((uint16_t)fetched) << 1) | GetFlag(C);

    SetFlag(C, temp & 0xFF00);
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);

    if (lookup[opcode].address_mode == &CPU::IMP) {
        accumulator = temp & 0x00FF;
    }
    else {
        write(addr_abs, temp & 0x00FF);
    }

    return 0;
}

/**
 * Rotates a memory value of the accumulator right.
 */
uint8_t CPU::ROR()
{
    fetch();

    uint16_t temp = ((uint16_t)fetched) | ((uint16_t)GetFlag(C) << 8);

    SetFlag(C, temp & 0x0001);
    temp = temp >> 1;
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);

    if (lookup[opcode].address_mode == &CPU::IMP) {
        accumulator = temp & 0x00FF;
    }
    else {
        write(addr_abs, temp & 0x00FF);
    }

    return 0;
}

/**
 * Pulls an address from the stack into the program
 * counter and increments it.
 */
uint8_t CPU::RTS()
{
    stack_pointer++;
    program_counter = (uint16_t)read(0x0100 + stack_pointer);
    stack_pointer++;
    program_counter |= (uint16_t)read(0x0100 + stack_pointer) << 8;

    program_counter++;

    return 0;
}

/**
 * Captures illegal opcodes.
 */
uint8_t CPU::XXX()
{
    return 0;
}
