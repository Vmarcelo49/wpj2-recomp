/*
 * WPJ2 Recomp - Shim Declarations
 * Provides _recomp function declarations for N64Recomp-generated code
 * Signatures MUST match exactly what N64Recomp generates (void return, rdram + ctx only)
 */

#ifndef WPJ2_SHIMS_H
#define WPJ2_SHIMS_H

#include "recomp.h"

// C compatibility typedefs for N64ModernRuntime's C++ headers
// MUST come BEFORE ultra64.h so typedefs are available when ultra64.h uses them
typedef struct OSIoMesgHdr OSIoMesgHdr;
typedef struct OSIoMesg OSIoMesg;

#include "ultramodern/ultra64.h"

#ifdef __cplusplus
extern "C" {
#endif

// Controller Pak (MPK) internal functions
void __osPfsSelectBank_recomp(uint8_t* rdram, recomp_context* ctx);
void __osContRamRead_recomp(uint8_t* rdram, recomp_context* ctx);
void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx);

// Controller Pak functions with _recomp suffix - match generated signatures exactly
void osContReset_recomp(uint8_t* rdram, recomp_context* ctx);
void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx);
void osPfsInit_recomp(uint8_t* rdram, recomp_context* ctx);
void osPfsFileState_recomp(uint8_t* rdram, recomp_context* ctx);
void osPfsGetLabel_recomp(uint8_t* rdram, recomp_context* ctx);
void osPfsSetLabel_recomp(uint8_t* rdram, recomp_context* ctx);
void osPfsNumFiles_recomp(uint8_t* rdram, recomp_context* ctx);

// Thread functions with _recomp suffix
void osYieldThread_recomp(uint8_t* rdram, recomp_context* ctx);
void osStopThread_recomp(uint8_t* rdram, recomp_context* ctx);
void osDestroyThread_recomp(uint8_t* rdram, recomp_context* ctx);

// PI functions
void osPiRawStartDma_recomp(uint8_t* rdram, recomp_context* ctx);

// Mutex functions
void osCreateMutex_recomp(uint8_t* rdram, recomp_context* ctx);
void osLockMutex_recomp(uint8_t* rdram, recomp_context* ctx);
void osUnlockMutex_recomp(uint8_t* rdram, recomp_context* ctx);

// SP (RSP) task functions
void osSpTaskLoad_recomp(uint8_t* rdram, recomp_context* ctx);
void osSpTaskStartGo_recomp(uint8_t* rdram, recomp_context* ctx);
void osSpTaskYield_recomp(uint8_t* rdram, recomp_context* ctx);
void osSpTaskYielded_recomp(uint8_t* rdram, recomp_context* ctx);

// VI (Video Interface) functions
void osViBlack_recomp(uint8_t* rdram, recomp_context* ctx);
void osViSetMode_recomp(uint8_t* rdram, recomp_context* ctx);
void osViSetSpecialFeatures_recomp(uint8_t* rdram, recomp_context* ctx);
void osViSwapBuffer_recomp(uint8_t* rdram, recomp_context* ctx);
void osViSetEvent_recomp(uint8_t* rdram, recomp_context* ctx);
void osViGetCurrentFramebuffer_recomp(uint8_t* rdram, recomp_context* ctx);
void osViGetNextFramebuffer_recomp(uint8_t* rdram, recomp_context* ctx);

// Cache/Writeback functions
void osWritebackDCacheAll_recomp(uint8_t* rdram, recomp_context* ctx);
void osWritebackDCache_recomp(uint8_t* rdram, recomp_context* ctx);

// Memory conversion
void osVirtualToPhysical_recomp(uint8_t* rdram, recomp_context* ctx);

#ifdef __cplusplus
}
#endif

#endif // WPJ2_SHIMS_H
