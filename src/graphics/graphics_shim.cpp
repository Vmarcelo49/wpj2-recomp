/*
 * WPJ2 Recomp - Graphics/VI/SP Shim
 * Provides _recomp implementations for graphics, video, and SP functions
 * Signatures match N64Recomp-generated expectations: void return, (rdram, ctx) only
 *
 * Phase 3 shim layer: minimal stubs that get linker working.
 * Proper RT64/ultramodern integration comes in Phase 4-5 once the
 * per-component wiring (rsp_callbacks, renderer_callbacks, etc.) is set up.
 */

#include "shims.h"
#include "ultramodern/ultra64.h"

// SP (RSP) task functions - stubs; full impl in Phase 4 via rsp_callbacks
void osSpTaskLoad_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

void osSpTaskStartGo_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

void osSpTaskYield_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

void osSpTaskYielded_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// VI (Video Interface) functions - read args, return via ctx->r2
// In recomp mode: void osViBlack(RDRAM_ARG uint8_t active)
void osViBlack_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// In recomp mode: void osViSetMode(RDRAM_ARG PTR(OSViMode) mode)
void osViSetMode_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// In recomp mode: void osViSetSpecialFeatures(uint32_t func)
void osViSetSpecialFeatures_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// In recomp mode: void osViSwapBuffer(RDRAM_ARG PTR(void) frameBufPtr)
void osViSwapBuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// In recomp mode: void osViSetEvent(RDRAM_ARG PTR(OSMesgQueue) mq, OSMesg msg, u32 count)
void osViSetEvent_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// In recomp mode: PTR(void) osViGetCurrentFramebuffer(RDRAM_ARG1)
// Return value goes in ctx->r2 (v0 register)
void osViGetCurrentFramebuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 0;
}

// In recomp mode: PTR(void) osViGetNextFramebuffer(RDRAM_ARG1)
void osViGetNextFramebuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    ctx->r2 = 0;
}

// Cache/Writeback functions - stubs; real impl needs target-specific flush
void osWritebackDCacheAll_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

void osWritebackDCache_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// Memory conversion - identity for now (RDRAM at 0x80000000)
void osVirtualToPhysical_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    // In recomp mode: u32 osVirtualToPhysical(RDRAM_ARG PTR(void) addr)
    // Strip the recomp-mode KSEG0 base (0xFFFFFFFF80000000) and return RDRAM physical addr
    PTR(void) addr = (PTR(void))ctx->r4;
    ctx->r2 = (uint32_t)addr;
}
