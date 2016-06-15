#pragma once
#ifndef _INSTRUCTIONS_VIEWER_H
#define _INSTRUCTIONS_VIEWER_H

#include "cpu_listener.h"
#include "rom_walker.h"

class MMU;
class CPU;

class InstructionsViewer : public ICpuListener
{
public:

     InstructionsViewer(const MMU &_mmu, CPU &_cpu);
    ~InstructionsViewer();

	void Render();

    // ICpuListener
    void OnStep(int _numCycles);

private:

    struct InstructionLine
    {
        InstructionLine(int _a, int _nb, string& _ac)
        {
            addr = _a;
            numBytes = _nb;
            asmCode = _ac;
        }

        int addr;
        int numBytes;
        string asmCode;
    };

    const MMU               &mMmu;
    CPU                     &mCpu;
    ROMWalker               mROMWalker;
    vector<InstructionLine> mInstructionLines;
    int                     mSelectedLineIdx {-1};
    int                     mActiveLineIdx {0};
    int                     mPrevActiveLineIdx {0};
    int                     mAddrDigitCount;
    int                    *mPCLineInfo {nullptr};

	void CalculateInstructionLines ();
    void ToggleBreakpoint          (u16 _addr);
    void ProcessCb                 (u8 _opcode, u16 _addr);
};

#endif
