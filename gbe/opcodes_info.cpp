#include "base.h"
#include "gb.h"
#include "opcodes_info.h"

OpcodesInfo::InfoPrimary OpcodesInfo::primary[256] =
{
    // 0x00
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NOP"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC BC"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC B"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "DEC B"; } },
    { 2, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD B, " + Int2Hex(_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 3, 20, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD (" + Int2Hex(_gb.GetMmu().ReadU16(_pc)) + "), SP"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "DEC BC"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC C"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "DEC C"; } },
    { 2, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD C, " + Int2Hex(_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0x10
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 3, 12, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD DE, " + Int2Hex(_gb.GetMmu().ReadU16(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC DE"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "DEC D"; } },
    { 2, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD D, " + Int2Hex(_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "RLA"; } },
    { 2, 12, OpcodesInfo::JumpI8, [](GB &_gb, u16 _pc) { return "JR :" + Int2Hex(_pc + 1 + (i8)_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD A, (DE)"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC E"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "DEC E"; } },
    { 2, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD E, " + Int2Hex(_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0x20
    { 2, 8,  OpcodesInfo::JumpCondI8, [](GB &_gb, u16 _pc) { return "JR NZ, :" + Int2Hex(_pc + 1 + (i8)_gb.GetMmu().ReadU8(_pc)); } },
    { 3, 12, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD HL, " + Int2Hex(_gb.GetMmu().ReadU16(_pc)); } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD (HL+), A"; } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC HL"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC H"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 2, 8,  OpcodesInfo::JumpCondI8, [](GB &_gb, u16 _pc) { return "JR Z, :" + Int2Hex(_pc + 1 + (i8)_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 2, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD L, " + Int2Hex(_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0x30
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 3, 12, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD SP, " + Int2Hex(_gb.GetMmu().ReadU16(_pc)); } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD (HL-), A"; } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC SP"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "INC A"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "DEC A"; } },
    { 2, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD A, " + Int2Hex(_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0x40
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD B, D"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD C, A"; } },

    // 0x50
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD D, A"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0x60
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD H, E"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD H, (HL)"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD H, A"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD L, (HL)"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0x70
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD (HL), E"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD (HL), A"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD A, B"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD A, E"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD A, H"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD A, L"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0x80
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "ADD A, E"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "ADD A, (HL)"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "ADC A, B"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "ADC A, C"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0x90
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "SUB B"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "SBC A, C"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "SBC A, A"; } },

    // 0xA0
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "AND L"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "XOR A"; } },

    // 0xB0
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "CP C"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "CP E"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "CP (HL)"; } },
    { 1, 0, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0xC0
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 12, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "POP BC"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 3, 16, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "JP " + Int2Hex(_gb.GetMmu().ReadU16(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 16, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "PUSH BC"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 16, OpcodesInfo::Ret,  [](GB &_gb, u16 _pc) { return "RET"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 4,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "CB"; } },
    { 3, 12, OpcodesInfo::CallCond, [](GB &_gb, u16 _pc) { return "CALL Z, " + Int2Hex(_gb.GetMmu().ReadU16(_pc)); } },
    { 3, 14,  OpcodesInfo::Call, [](GB &_gb, u16 _pc) { return "CALL " + Int2Hex(_gb.GetMmu().ReadU16(_pc)); } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "ADC A, " + Int2Hex(_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0xD0
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 16, OpcodesInfo::Ret,  [](GB &_gb, u16 _pc) { return "RETI"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0xE0
    { 2, 12, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD (FF00 + " + Int2Hex(_gb.GetMmu().ReadU8(_pc)) + "), A"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD (FF00 + C), A"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 3, 16, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD (" + Int2Hex(_gb.GetMmu().ReadU16(_pc)) + "), A"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },

    // 0xF0
    { 2, 12, OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "LD A, (FF00 + " + Int2Hex(_gb.GetMmu().ReadU8(_pc)) + ")"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } },
    { 2, 8,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "CP " + Int2Hex(_gb.GetMmu().ReadU8(_pc)); } },
    { 1, 0,  OpcodesInfo::None, [](GB &_gb, u16 _pc) { return "NO IMPLEMENTED"; } }
};

