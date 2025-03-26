import wget

opcode_list = [
    "0a",  # ASL (accumulator)
    "0d",  # ORA (absolute)
    "0e",  # ASL (absolute)
    "10",  # BPL
    "11",  # ORA (indirect),Y
    "15",  # ORA (zeropage,X)
    "16",  # ASL (zeropage,X)
    "18",  # CLC
    "19",  # ORA (absolute),Y
    "1d",  # ORA (absolute,X)
    "1e",  # ASL (absolute,X)
    "20",  # JSR
    "21",  # AND (indirect,X)
    "24",  # BIT (zeropage)
    "25",  # AND (zeropage)
    "26",  # ROL (zeropage)
    "28",  # PLP
    "29",  # AND (immediate)
    "2a",  # ROL (accumulator)
    "2c",  # BIT (absolute)
    "2d",  # AND (absolute)
    "2e",  # ROL (absolute)
    "30",  # BMI
    "31",  # AND (indirect),Y
    "35",  # AND (zeropage,X)
    "36",  # ROL (zeropage,X)
    "38",  # SEC
    "39",  # AND (absolute),Y
    "3d",  # AND (absolute,X)
    "3e",  # ROL (absolute,X)
    "40",  # RTI
    "41",  # EOR (indirect,X)
    "45",  # EOR (zeropage)
    "46",  # LSR (zeropage)
    "48",  # PHA
    "49",  # EOR (immediate)
    "4a",  # LSR (accumulator)
    "4c",  # JMP (absolute)
    "4d",  # EOR (absolute)
    "4e",  # LSR (absolute)
    "50",  # BVC
    "51",  # EOR (indirect),Y
    "55",  # EOR (zeropage,X)
    "56",  # LSR (zeropage,X)
    "58",  # CLI
    "59",  # EOR (absolute),Y
    "5d",  # EOR (absolute,X)
    "5e",  # LSR (absolute,X)
    "60",  # RTS
    "61",  # ADC (indirect,X)
    "65",  # ADC (zeropage)
    "66",  # ROR (zeropage)
    "68",  # PLA
    "69",  # ADC (immediate)
    "6a",  # ROR (accumulator)
    "6c",  # JMP (indirect)
    "6d",  # ADC (absolute)
    "6e",  # ROR (absolute)
    "70",  # BVS
    "71",  # ADC (indirect),Y
    "75",  # ADC (zeropage,X)
    "76",  # ROR (zeropage,X)
    "78",  # SEI
    "79",  # ADC (absolute),Y
    "7d",  # ADC (absolute,X)
    "7e",  # ROR (absolute,X)
    "80",  # NOP (immediate)
    "81",  # STA (indirect,X)
    "84",  # STY (zeropage)
    "85",  # STA (zeropage)
    "86",  # STX (zeropage)
    "88",  # DEY
    "8a",  # TXA
    "8c",  # STY (absolute)
    "8d",  # STA (absolute)
    "8e",  # STX (absolute)
    "90",  # BCC
    "91",  # STA (indirect),Y
    "94",  # STY (zeropage,X)
    "95",  # STA (zeropage,X)
    "96",  # STX (zeropage,Y)
    "98",  # TYA
    "99",  # STA (absolute),Y
    "9a",  # TXS
    "9d",  # STA (absolute,X)
    "a0",  # LDY (immediate)
    "a1",  # LDA (indirect,X)
    "a2",  # LDX (immediate)
    "a4",  # LDY (zeropage)
    "a5",  # LDA (zeropage)
    "a6",  # LDX (zeropage)
    "a8",  # TAY
    "a9",  # LDA (immediate)
    "aa",  # TAX
    "ac",  # LDY (absolute)
    "ad",  # LDA (absolute)
    "ae",  # LDX (absolute)
    "b0",  # BCS
    "b1",  # LDA (indirect),Y
    "b4",  # LDY (zeropage,X)
    "b5",  # LDA (zeropage,X)
    "b6",  # LDX (zeropage,Y)
    "b8",  # CLV
    "b9",  # LDA (absolute),Y
    "ba",  # TSX
    "bd",  # LDA (absolute,X)
    "be",  # LDX (absolute,Y)
    "c0",  # CPY (immediate)
    "c1",  # CMP (indirect,X)
    "c4",  # CPY (zeropage)
    "c5",  # CMP (zeropage)
    "c6",  # DEC (zeropage)
    "c8",  # INY
    "c9",  # CMP (immediate)
    "ca",  # DEX
    "cc",  # CPY (absolute)
    "cd",  # CMP (absolute)
    "ce",  # DEC (absolute)
    "d0",  # BNE
    "d1",  # CMP (indirect),Y
    "d5",  # CMP (zeropage,X)
    "d6",  # DEC (zeropage,X)
    "d8",  # CLD
    "d9",  # CMP (absolute),Y
    "dd",  # CMP (absolute,X)
    "de",  # DEC (absolute,X)
    "e0",  # CPX (immediate)
    "e1",  # SBC (indirect,X)
    "e4",  # CPX (zeropage)
    "e5",  # SBC (zeropage)
    "e6",  # INC (zeropage)
    "e8",  # INX
    "e9",  # SBC (immediate)
    "ea",  # NOP
    "ec",  # CPX (absolute)
    "ed",  # SBC (absolute)
    "ee",  # INC (absolute)
    "f0",  # BEQ
    "f1",  # SBC (indirect),Y
    "f5",  # SBC (zeropage,X)
    "f6",  # INC (zeropage,X)
    "f8",  # SED
    "f9",  # SBC (absolute),Y
    "fd",  # SBC (absolute,X)
    "fe",  # INC (absolute,X)
]

for code in opcode_list:
    url = f'https://raw.githubusercontent.com/SingleStepTests/ProcessorTests/refs/heads/main/nes6502/v1/{code}.json'
    wget.download(url)

