/*
 * WPJ2 Recomp - Common Macros
 * Shim header for N64 SDK macro compatibility
 */

#ifndef WPJ2_MACROS_H
#define WPJ2_MACROS_H

#include <stdint.h>
#include <stddef.h>

// Basic types matching N64 SDK
typedef int8_t      s8;
typedef int16_t     s16;
typedef int32_t     s32;
typedef int64_t     s64;
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef float       f32;
typedef double      f64;

typedef volatile s8  vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef volatile u8  vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef int32_t     Bool;
typedef int32_t     s32;

// Pointer types - DO NOT redefine PTR/RDRAM_ARG here.
// The ultramodern/ultra64.h (included via shims.h) provides the correct
// recomp-mode definitions: PTR(x)=int32_t, RDRAM_ARG=uint8_t* rdram,
// Redefining them here in native mode silently breaks every recompiled
// function signature and the ultramodern API.

// Common constants
#define NULL 0
#define TRUE 1
#define FALSE 0

// Min/Max
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

// Alignment
#define ALIGN16(x) (((x) + 0xF) & ~0xF)
#define ALIGN8(x)  (((x) + 0x7) & ~0x7)
#define ALIGN4(x)  (((x) + 0x3) & ~0x3)

// Bit operations
#define SET_BIT(reg, bit)   ((reg) |= (1 << (bit)))
#define CLEAR_BIT(reg, bit) ((reg) &= ~(1 << (bit)))
#define TEST_BIT(reg, bit)  (((reg) >> (bit)) & 1)

// Endianness helpers (N64 is big-endian)
#define SWAP16(x) ((((x) & 0xFF) << 8) | (((x) >> 8) & 0xFF))
#define SWAP32(x) ((((x) & 0xFF) << 24) | (((x) & 0xFF00) << 8) | \
                   (((x) >> 8) & 0xFF00) | (((x) >> 24) & 0xFF))

// Section attributes for linker
#define SECTION(name) __attribute__((section(name)))
#define ALIGN(n) __attribute__((aligned(n)))

// Unused parameter suppression
#define UNUSED(x) (void)(x)

// Assert (compile-time)
#define STATIC_ASSERT(cond) _Static_assert(cond, #cond)

#endif // WPJ2_MACROS_H
