/*
 * WPJ2 Recomp - Controller Pak (MPK) Shim
 * Provides _recomp implementations for Controller Pak internal functions
 * Signatures match N64Recomp-generated expectations: void return, (rdram, ctx) only
 */

#include "shims.h"  // Includes ultra64.h with OSIoMesgHdr typedef

// __osPfsSelectBank - internal function for Controller Pak banking
void __osPfsSelectBank_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// __osContRamRead - reads Controller Pak RAM
void __osContRamRead_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// __osContRamWrite - writes Controller Pak RAM
void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osContReset_recomp
void osContReset_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osPfsIsPlug_recomp
void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osPfsInit_recomp
void osPfsInit_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osPfsFileState_recomp
void osPfsFileState_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osPfsGetLabel_recomp
void osPfsGetLabel_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osPfsSetLabel_recomp
void osPfsSetLabel_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osPfsNumFiles_recomp
void osPfsNumFiles_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}

// osPiRawStartDma_recomp
void osPiRawStartDma_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}
