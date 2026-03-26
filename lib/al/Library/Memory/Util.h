#pragma once

#include <basis/seadTypes.h>

namespace sead {
class Heap;
}

namespace al {
void copyMemoryFast(u32* dest, const u32* src, u32 size);
void copyMemory(void* dest, const void* src, u32 size);
bool tryCompressByZlib(u8*, u32*, const u8*, u32);
bool tryDecompressByZlib(u8*, u32*, const u8*, u32);
sead::Heap* getCurrentHeap();
}
