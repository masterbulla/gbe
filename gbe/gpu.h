#pragma once

#include "mmu_listener.h"

class MMU;

class GPU : public IMmuListener
{
public:

    static const u8 ScreenWidth = 160;
    static const u8 ScreenHeight = 144;

    // ..
         GPU                (MMU& _mmu);

    void OnMemoryWrittenU8  (u16 _virtAddr, u8 _value);
    void OnMemoryWrittenU16 (u16 _virtAddr, u16 _value);

    const u32* GetScreen    ();

private:
    u8  mPalette[4] {0};
    u32 mScreen[ScreenWidth * ScreenHeight] {0};
    bool mDirty {true};
};