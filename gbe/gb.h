#pragma once
#ifndef _GB_H
#define _GB_H

#include "mmu.h"
#include "cpu.h"
#include "gpu.h"

class GB
{
public:

    GB() : mCpu(mMmu), mGpu(mCpu, mMmu) {}

    void        PowerUp    (const string& _cartridge, const string& _bootRom);
    const MMU&  GetMmu     () const { return mMmu; }
    CPU&        GetCpu     () { return mCpu; }
    GPU&        GetGpu     () { return mGpu; }

private:
	MMU mMmu;
    CPU mCpu;
    GPU mGpu;
};

#endif
