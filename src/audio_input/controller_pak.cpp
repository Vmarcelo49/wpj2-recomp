/*
 * WPJ2 Recomp - Controller Pak (MPK) supplementary shims
 *
 * These functions are referenced by the WPJ2 recompilation but NOT implemented
 * by librecomp. They return PFS_ERR_NOPACK (1) so the game treats the Controller
 * Pak as absent. Real CPK save support would require implementing these properly,
 * but WPJ2's save system is wired through librecomp's existing pak.cpp for now.
 *
 * NOTE: Do not implement osPfsFileState_recomp, osPfsNumFiles_recomp,
 * osContReset_recomp, or osPiRawStartDma_recomp here — librecomp already
 * provides them and duplicating causes mold link errors.
 */

#include "recomp.h"
#include "shims.h"

// Stub: no Controller Pak present.
extern "C" void __osPfsSelectBank_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

extern "C" void __osContRamRead_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 1; // PFS_ERR_NOPACK
}

extern "C" void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 1; // PFS_ERR_NOPACK
}

extern "C" void osPfsInit_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 1; // PFS_ERR_NOPACK
}

extern "C" void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 1; // PFS_ERR_NOPACK
}

extern "C" void osPfsGetLabel_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 0;
}

extern "C" void osPfsSetLabel_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 0;
}

extern "C" void osCreateMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

extern "C" void osLockMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

extern "C" void osUnlockMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// Additional internal functions referenced by the recompilation but not
// implemented by librecomp. These are osInternal* helpers used by the
// game's libultra — stub them as no-ops so the game can boot.
extern "C" void __osViGetCurrentContext_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 0; // return null context
}

extern "C" void __osViSwapContext_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

extern "C" void __osTimerInterrupt_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

extern "C" void __osPfsRWInode_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 1; // PFS_ERR_NOPACK
}

extern "C" void __osContAddressCrc_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 0; // CRC result (stub)
}

extern "C" void __osContDataCrc_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 0; // CRC result (stub)
}
