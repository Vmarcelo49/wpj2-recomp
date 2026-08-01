#ifndef WPJ2_OS_H
#define WPJ2_OS_H

#include "macros.h"

// Include N64ModernRuntime's ultra64.h which has all the proper RDRAM_ARG macros
#include "ultramodern/ultra64.h"

// Additional WPJ2-specific functions not in N64ModernRuntime
// These need RDRAM_ARG macros for recompilation mode

#ifdef __cplusplus
extern "C" {
#endif

// Controller Pak (MPK) - WPJ2 uses Controller Pak, NOT EEPROM
void __osPfsSelectBank_recomp(RDRAM_ARG u8 bank);
void __osContRamRead_recomp(RDRAM_ARG void* data, s32 addr, s32 nbytes);
void __osContRamWrite_recomp(RDRAM_ARG void* data, s32 addr, s32 nbytes);
s32 osContReset_recomp(RDRAM_ARG void* status);
s32 osPfsIsPlug_recomp(RDRAM_ARG void* pfs);
s32 osPfsInit_recomp(RDRAM_ARG void* pfs, s32* result);
s32 osPfsFileState_recomp(RDRAM_ARG s32 file_no, void* buffer);
s32 osPfsGetLabel_recomp(RDRAM_ARG void* label);
s32 osPfsSetLabel_recomp(RDRAM_ARG void* label);

// Additional thread functions
void osYieldThread_recomp(RDRAM_ARG1);
void osStopThread_recomp(RDRAM_ARG void* t);
void osDestroyThread_recomp(RDRAM_ARG void* t);

// Mutex/Condition variable functions (if used)
void osCreateMutex_recomp(RDRAM_ARG void* mutex);
void osLockMutex_recomp(RDRAM_ARG void* mutex);
void osUnlockMutex_recomp(RDRAM_ARG void* mutex);

#ifdef __cplusplus
}
#endif

#endif // WPJ2_OS_H
