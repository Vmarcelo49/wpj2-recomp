/*
 * WPJ2 Recomp - Thread Shim
 * Provides _recomp functions for thread operations
 * Signatures match N64Recomp-generated expectations: void return, (rdram, ctx) only
 * Note: In recomp mode, PTR(OSThread) = int32_t, so we pass 0 (null thread)
 */

#include "shims.h"
#include "ultramodern/ultra64.h"

// osYieldThread_recomp - yields current thread
void osYieldThread_recomp(uint8_t* rdram, recomp_context* ctx) {
    osYieldThread(rdram);
}

// osStopThread_recomp - stops a thread
// In recomp mode: void osStopThread(RDRAM_ARG PTR(OSThread) t) -> void osStopThread(uint8_t* rdram, int32_t t)
void osStopThread_recomp(uint8_t* rdram, recomp_context* ctx) {
    osStopThread(rdram, 0);
}

// osDestroyThread_recomp - destroys a thread
// In recomp mode: void osDestroyThread(RDRAM_ARG PTR(OSThread) t) -> void osDestroyThread(uint8_t* rdram, int32_t t)
void osDestroyThread_recomp(uint8_t* rdram, recomp_context* ctx) {
    osDestroyThread(rdram, 0);
}

// osCreateMutex_recomp
void osCreateMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osLockMutex_recomp
void osLockMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osUnlockMutex_recomp
void osUnlockMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}
