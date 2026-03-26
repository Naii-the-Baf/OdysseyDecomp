#include "Library/Memory/Util.h"

#include <heap/seadHeapMgr.h>

namespace al {
void copyMemoryFast(u32* dest, const u32* src, u32 size) {
    for (s32 i = size >> 4; i--;) {
        u32 a = *src++;
        u32 b = *src++;
        u32 c = *src++;
        u32 d = *src++;
        *dest++ = a;
        *dest++ = b;
        *dest++ = c;
        *dest++ = d;
    }
}

void copyMemory(void* dest, const void* src, u32 size) {
    u64 srcAlign = uintptr_t(src) & 3;
    u64 destAlign = uintptr_t(dest) & 3;
    if ((uintptr_t(size) & 15) == 0 && srcAlign == destAlign) {
        copyMemoryFast((u32*)dest, (u32*)src, size);
        return;
    }

    if (size < 16 || srcAlign != destAlign) {
        s32 sizeMod4 = size & 3;
        bool* destTyped = (bool*)dest;
        const bool* srcTyped = (bool*)src;
        for (s32 i = sizeMod4; i--;) {
            u32 a = *srcTyped++;
            u32 b = *srcTyped++;
            u32 c = *srcTyped++;
            u32 d = *srcTyped++;
            *destTyped++ = a;
            *destTyped++ = b;
            *destTyped++ = c;
            *destTyped++ = d;
        }

        for (s32 i = size - sizeMod4; i--;) {
            *destTyped++ = *srcTyped++;
        }
        return;
    }

    if ((uintptr_t(src) & 3) != 0 && (4 - srcAlign & 0xFF) != 0) {

    }
}

bool tryCompressByZlib(u8*, u32*, const u8*, u32) {
    return false;
}

bool tryDecompressByZlib(u8*, u32*, const u8*, u32) {
    return false;
}

sead::Heap* getCurrentHeap() {
    return sead::HeapMgr::instance()->getCurrentHeap();
}
}
