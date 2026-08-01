/*
 * WPJ2 Recomp - ultra64.h shim
 * Based on N64ModernRuntime's ultra64.h, adapted for recompiled code
 */

#ifndef WPJ2_ULTRA64_H
#define WPJ2_ULTRA64_H

#include "macros.h"
#include "ultramodern/ultra64.h"  // Use N64ModernRuntime's ultra64.h as base

// WPJ2-specific overrides/additions
#ifdef __cplusplus
extern "C" {
#endif

// Additional WPJ2-specific functions that may be referenced
// These will be implemented in shim source files

// Controller Pak (MPK) functions - WPJ2 uses Controller Pak, not EEPROM
s32 osPfsInitPak(void* mq, u8* id, s32* result);
s32 osPfsReadWriteFile(void* pfs, s32 file_no, u8* buffer, s32 mode);
s32 osPfsFindFile(void* pfs, u16 company_code, u16 game_code, u8* file_name, u8* ext_name, s32* file_no);
s32 osPfsAllocateFile(void* pfs, s32 file_no, u16 company_code, u16 game_code, u8* file_name, u8* ext_name, s32 file_size);
s32 osPfsDeleteFile(void* pfs, s32 file_no);
s32 osPfsFreeBlocks(void* pfs, u8* bytes_not_used);
s32 osPfsCheckStatus(void* pfs);
s32 osPfsRepairId(void* pfs);

// RSP task functions (may have recompiled versions)
s32 osSpTaskStart(void* task);
s32 osSpTaskYield(void);
void osSpTaskLoad(void* task);

// Audio functions (aspMain is recompiled via RSPRecomp)
void alInit(void* globals, void* seqp);
void alAudioFrame(void* globals);

// Thread functions
void osCreateThread(void* t, s32 id, void* entry, void* arg, void* sp, s32 pri);
void osStartThread(void* t);
void osStopThread(void* t);
void osDestroyThread(void* t);
void osYieldThread(void);

// Memory functions
void* osVirtualToPhysical(void* vaddr);
void osWritebackDCache(void* addr, s32 nbytes);
void osInvalDCache(void* addr, s32 nbytes);
void osWritebackDCacheAll(void);
void osInvalDCacheAll(void);
void osWritebackICache(void* addr, s32 nbytes);

// VI functions
void osViSetMode(void* mode);
void osViSetSpecialFeatures(u32 features);
void osViBlack(u8 active);
void osViSwapBuffer(void* frameBufPtr);
void* osViGetNextFramebuffer(void);
void* osViGetCurrentFramebuffer(void);

// PI functions
s32 osPiStartDma(void* iomesg, s32 direction, u32 devAddr, void* vAddr, u32 nbytes, void* mq);
s32 osPiReadIo(u32 devAddr, u32* data);
s32 osPiWriteIo(u32 devAddr, u32 data);

// SI functions
s32 osContInit(void* mq, u8* bitpattern, void* status);
s32 osContStartReadData(void* mq);
void osContGetReadData(void* pad);

// Timer functions
s32 osSetTimer(void* timer, u64 countdown, u64 interval, void* mq, void* msg);
s32 osStopTimer(void* timer);

// SP functions
s32 osSpTaskStart(void* task);
s32 osSpTaskYield(void);
void osSpTaskLoad(void* task);

#ifdef __cplusplus
}
#endif

#endif // WPJ2_ULTRA64_H
