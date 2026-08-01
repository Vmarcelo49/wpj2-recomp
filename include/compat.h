/*
 * WPJ2 Recomp - C Compatibility Layer
 * Adds missing typedefs for C compatibility with N64ModernRuntime's C++ headers
 * MUST be included BEFORE ultra64.h
 */

#ifndef WPJ2_COMPAT_H
#define WPJ2_COMPAT_H

// OSIoMesgHdr is defined as "struct OSIoMesgHdr" without typedef in ultra64.h
// In C, we need the typedef to use it without "struct" keyword
typedef struct OSIoMesgHdr OSIoMesgHdr;
typedef struct OSIoMesg OSIoMesg;

#endif // WPJ2_COMPAT_H
