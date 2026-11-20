#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006DE58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DE5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DE60: jal         0x80061348
    // 0x8006DE64: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DE64: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006DE68: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DE6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DE70: beq         $v0, $zero, L_8006DE88
    if (ctx->r2 == 0) {
        // 0x8006DE74: nop

            goto L_8006DE88;
    }
    // 0x8006DE74: nop

    // 0x8006DE78: jal         0x80061348
    // 0x8006DE7C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DE7C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006DE80: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DE84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DE88:
    // 0x8006DE88: b           L_8006DE98
    // 0x8006DE8C: nop

        goto L_8006DE98;
    // 0x8006DE8C: nop

    // 0x8006DE90: b           L_8006DE98
    // 0x8006DE94: nop

        goto L_8006DE98;
    // 0x8006DE94: nop

L_8006DE98:
    // 0x8006DE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DE9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DEA0: jr          $ra
    // 0x8006DEA4: nop

    return;
    // 0x8006DEA4: nop

;}
RECOMP_FUNC void func_8006DEA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DEA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DEAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DEB0: jal         0x80061348
    // 0x8006DEB4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DEB4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006DEB8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DEBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DEC0: beq         $v0, $zero, L_8006DED8
    if (ctx->r2 == 0) {
        // 0x8006DEC4: nop

            goto L_8006DED8;
    }
    // 0x8006DEC4: nop

    // 0x8006DEC8: jal         0x80061348
    // 0x8006DECC: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DECC: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x8006DED0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DED4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DED8:
    // 0x8006DED8: b           L_8006DEE8
    // 0x8006DEDC: nop

        goto L_8006DEE8;
    // 0x8006DEDC: nop

    // 0x8006DEE0: b           L_8006DEE8
    // 0x8006DEE4: nop

        goto L_8006DEE8;
    // 0x8006DEE4: nop

L_8006DEE8:
    // 0x8006DEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DEEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DEF0: jr          $ra
    // 0x8006DEF4: nop

    return;
    // 0x8006DEF4: nop

;}
RECOMP_FUNC void func_8006DEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DEF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DF00: jal         0x80061348
    // 0x8006DF04: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DF04: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006DF08: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DF0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DF10: beq         $v0, $zero, L_8006DF28
    if (ctx->r2 == 0) {
        // 0x8006DF14: nop

            goto L_8006DF28;
    }
    // 0x8006DF14: nop

    // 0x8006DF18: jal         0x80061348
    // 0x8006DF1C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DF1C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x8006DF20: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DF24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DF28:
    // 0x8006DF28: b           L_8006DF38
    // 0x8006DF2C: nop

        goto L_8006DF38;
    // 0x8006DF2C: nop

    // 0x8006DF30: b           L_8006DF38
    // 0x8006DF34: nop

        goto L_8006DF38;
    // 0x8006DF34: nop

L_8006DF38:
    // 0x8006DF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DF3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DF40: jr          $ra
    // 0x8006DF44: nop

    return;
    // 0x8006DF44: nop

;}
RECOMP_FUNC void func_8006DF48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DF48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DF50: jal         0x80061348
    // 0x8006DF54: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DF54: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x8006DF58: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DF5C: b           L_8006DF6C
    // 0x8006DF60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006DF6C;
    // 0x8006DF60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DF64: b           L_8006DF6C
    // 0x8006DF68: nop

        goto L_8006DF6C;
    // 0x8006DF68: nop

L_8006DF6C:
    // 0x8006DF6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DF70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DF74: jr          $ra
    // 0x8006DF78: nop

    return;
    // 0x8006DF78: nop

;}
RECOMP_FUNC void func_8006DF7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DF7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DF80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DF84: jal         0x80061348
    // 0x8006DF88: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DF88: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x8006DF8C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DF90: b           L_8006DFA0
    // 0x8006DF94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006DFA0;
    // 0x8006DF94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DF98: b           L_8006DFA0
    // 0x8006DF9C: nop

        goto L_8006DFA0;
    // 0x8006DF9C: nop

L_8006DFA0:
    // 0x8006DFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DFA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DFA8: jr          $ra
    // 0x8006DFAC: nop

    return;
    // 0x8006DFAC: nop

;}
RECOMP_FUNC void func_8006DFB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DFB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DFB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DFB8: jal         0x80061348
    // 0x8006DFBC: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DFBC: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x8006DFC0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DFC4: b           L_8006DFD4
    // 0x8006DFC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006DFD4;
    // 0x8006DFC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DFCC: b           L_8006DFD4
    // 0x8006DFD0: nop

        goto L_8006DFD4;
    // 0x8006DFD0: nop

L_8006DFD4:
    // 0x8006DFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DFD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DFDC: jr          $ra
    // 0x8006DFE0: nop

    return;
    // 0x8006DFE0: nop

;}
RECOMP_FUNC void func_8006DFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DFE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DFE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DFEC: jal         0x80061348
    // 0x8006DFF0: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DFF0: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_0:
    // 0x8006DFF4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DFF8: b           L_8006E008
    // 0x8006DFFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E008;
    // 0x8006DFFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E000: b           L_8006E008
    // 0x8006E004: nop

        goto L_8006E008;
    // 0x8006E004: nop

L_8006E008:
    // 0x8006E008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E00C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E010: jr          $ra
    // 0x8006E014: nop

    return;
    // 0x8006E014: nop

;}
RECOMP_FUNC void func_8006E018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E020: jal         0x80061348
    // 0x8006E024: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E024: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_0:
    // 0x8006E028: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E02C: b           L_8006E03C
    // 0x8006E030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E03C;
    // 0x8006E030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E034: b           L_8006E03C
    // 0x8006E038: nop

        goto L_8006E03C;
    // 0x8006E038: nop

L_8006E03C:
    // 0x8006E03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E044: jr          $ra
    // 0x8006E048: nop

    return;
    // 0x8006E048: nop

;}
RECOMP_FUNC void func_8006E04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E04C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E054: jal         0x80061348
    // 0x8006E058: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E058: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x8006E05C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E060: b           L_8006E070
    // 0x8006E064: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E070;
    // 0x8006E064: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E068: b           L_8006E070
    // 0x8006E06C: nop

        goto L_8006E070;
    // 0x8006E06C: nop

L_8006E070:
    // 0x8006E070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E078: jr          $ra
    // 0x8006E07C: nop

    return;
    // 0x8006E07C: nop

;}
RECOMP_FUNC void func_8006E080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E088: jal         0x80061348
    // 0x8006E08C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E08C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006E090: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E094: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E098: beq         $v0, $zero, L_8006E0B0
    if (ctx->r2 == 0) {
        // 0x8006E09C: nop

            goto L_8006E0B0;
    }
    // 0x8006E09C: nop

    // 0x8006E0A0: jal         0x80061348
    // 0x8006E0A4: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E0A4: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    after_1:
    // 0x8006E0A8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E0AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E0B0:
    // 0x8006E0B0: b           L_8006E0C0
    // 0x8006E0B4: nop

        goto L_8006E0C0;
    // 0x8006E0B4: nop

    // 0x8006E0B8: b           L_8006E0C0
    // 0x8006E0BC: nop

        goto L_8006E0C0;
    // 0x8006E0BC: nop

L_8006E0C0:
    // 0x8006E0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E0C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E0C8: jr          $ra
    // 0x8006E0CC: nop

    return;
    // 0x8006E0CC: nop

;}
RECOMP_FUNC void func_8006E0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E0D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E0D8: jal         0x80061348
    // 0x8006E0DC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E0DC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006E0E0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E0E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E0E8: beq         $v0, $zero, L_8006E100
    if (ctx->r2 == 0) {
        // 0x8006E0EC: nop

            goto L_8006E100;
    }
    // 0x8006E0EC: nop

    // 0x8006E0F0: jal         0x80061348
    // 0x8006E0F4: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E0F4: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    after_1:
    // 0x8006E0F8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E0FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E100:
    // 0x8006E100: b           L_8006E110
    // 0x8006E104: nop

        goto L_8006E110;
    // 0x8006E104: nop

    // 0x8006E108: b           L_8006E110
    // 0x8006E10C: nop

        goto L_8006E110;
    // 0x8006E10C: nop

L_8006E110:
    // 0x8006E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E118: jr          $ra
    // 0x8006E11C: nop

    return;
    // 0x8006E11C: nop

;}
RECOMP_FUNC void func_8006E120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E128: jal         0x80061348
    // 0x8006E12C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E12C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006E130: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E134: b           L_8006E144
    // 0x8006E138: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E144;
    // 0x8006E138: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E13C: b           L_8006E144
    // 0x8006E140: nop

        goto L_8006E144;
    // 0x8006E140: nop

L_8006E144:
    // 0x8006E144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E14C: jr          $ra
    // 0x8006E150: nop

    return;
    // 0x8006E150: nop

;}
RECOMP_FUNC void func_8006E154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E15C: jal         0x80061348
    // 0x8006E160: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E160: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006E164: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E168: b           L_8006E178
    // 0x8006E16C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E178;
    // 0x8006E16C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E170: b           L_8006E178
    // 0x8006E174: nop

        goto L_8006E178;
    // 0x8006E174: nop

L_8006E178:
    // 0x8006E178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E17C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E180: jr          $ra
    // 0x8006E184: nop

    return;
    // 0x8006E184: nop

;}
RECOMP_FUNC void func_8006E188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E18C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E190: jal         0x80061348
    // 0x8006E194: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E194: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006E198: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E19C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E1A0: beq         $v0, $zero, L_8006E1D8
    if (ctx->r2 == 0) {
        // 0x8006E1A4: nop

            goto L_8006E1D8;
    }
    // 0x8006E1A4: nop

    // 0x8006E1A8: jal         0x80061348
    // 0x8006E1AC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E1AC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006E1B0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E1B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006E1B8: beq         $v0, $zero, L_8006E1D8
    if (ctx->r2 == 0) {
        // 0x8006E1BC: nop

            goto L_8006E1D8;
    }
    // 0x8006E1BC: nop

    // 0x8006E1C0: jal         0x80061348
    // 0x8006E1C4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006E1C4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_2:
    // 0x8006E1C8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E1CC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006E1D0: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E1D4: nop

            goto L_8006E518;
    }
    // 0x8006E1D4: nop

L_8006E1D8:
    // 0x8006E1D8: jal         0x80061348
    // 0x8006E1DC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006E1DC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_3:
    // 0x8006E1E0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E1E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006E1E8: beq         $v0, $zero, L_8006E220
    if (ctx->r2 == 0) {
        // 0x8006E1EC: nop

            goto L_8006E220;
    }
    // 0x8006E1EC: nop

    // 0x8006E1F0: jal         0x80061348
    // 0x8006E1F4: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006E1F4: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_4:
    // 0x8006E1F8: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E1FC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006E200: beq         $v0, $zero, L_8006E220
    if (ctx->r2 == 0) {
        // 0x8006E204: nop

            goto L_8006E220;
    }
    // 0x8006E204: nop

    // 0x8006E208: jal         0x80061348
    // 0x8006E20C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006E20C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_5:
    // 0x8006E210: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E214: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E218: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E21C: nop

            goto L_8006E518;
    }
    // 0x8006E21C: nop

L_8006E220:
    // 0x8006E220: jal         0x80061348
    // 0x8006E224: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006E224: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_6:
    // 0x8006E228: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E22C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006E230: beq         $v0, $zero, L_8006E268
    if (ctx->r2 == 0) {
        // 0x8006E234: nop

            goto L_8006E268;
    }
    // 0x8006E234: nop

    // 0x8006E238: jal         0x80061348
    // 0x8006E23C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006E23C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_7:
    // 0x8006E240: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E244: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006E248: beq         $v0, $zero, L_8006E268
    if (ctx->r2 == 0) {
        // 0x8006E24C: nop

            goto L_8006E268;
    }
    // 0x8006E24C: nop

    // 0x8006E250: jal         0x80061348
    // 0x8006E254: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006E254: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_8:
    // 0x8006E258: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E25C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006E260: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E264: nop

            goto L_8006E518;
    }
    // 0x8006E264: nop

L_8006E268:
    // 0x8006E268: jal         0x80061348
    // 0x8006E26C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006E26C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_9:
    // 0x8006E270: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E274: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006E278: beq         $v0, $zero, L_8006E2B0
    if (ctx->r2 == 0) {
        // 0x8006E27C: nop

            goto L_8006E2B0;
    }
    // 0x8006E27C: nop

    // 0x8006E280: jal         0x80061348
    // 0x8006E284: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006E284: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_10:
    // 0x8006E288: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E28C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E290: beq         $v0, $zero, L_8006E2B0
    if (ctx->r2 == 0) {
        // 0x8006E294: nop

            goto L_8006E2B0;
    }
    // 0x8006E294: nop

    // 0x8006E298: jal         0x80061348
    // 0x8006E29C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006E29C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_11:
    // 0x8006E2A0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E2A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006E2A8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E2AC: nop

            goto L_8006E518;
    }
    // 0x8006E2AC: nop

L_8006E2B0:
    // 0x8006E2B0: jal         0x80061348
    // 0x8006E2B4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006E2B4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_12:
    // 0x8006E2B8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E2BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006E2C0: beq         $v0, $zero, L_8006E2E0
    if (ctx->r2 == 0) {
        // 0x8006E2C4: nop

            goto L_8006E2E0;
    }
    // 0x8006E2C4: nop

    // 0x8006E2C8: jal         0x80061348
    // 0x8006E2CC: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006E2CC: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_13:
    // 0x8006E2D0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E2D4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006E2D8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E2DC: nop

            goto L_8006E518;
    }
    // 0x8006E2DC: nop

L_8006E2E0:
    // 0x8006E2E0: jal         0x80061348
    // 0x8006E2E4: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006E2E4: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_14:
    // 0x8006E2E8: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E2EC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006E2F0: beq         $v0, $zero, L_8006E310
    if (ctx->r2 == 0) {
        // 0x8006E2F4: nop

            goto L_8006E310;
    }
    // 0x8006E2F4: nop

    // 0x8006E2F8: jal         0x80061348
    // 0x8006E2FC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006E2FC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_15:
    // 0x8006E300: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E304: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E308: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E30C: nop

            goto L_8006E518;
    }
    // 0x8006E30C: nop

L_8006E310:
    // 0x8006E310: jal         0x80061348
    // 0x8006E314: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006E314: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_16:
    // 0x8006E318: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E31C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006E320: beq         $v0, $zero, L_8006E340
    if (ctx->r2 == 0) {
        // 0x8006E324: nop

            goto L_8006E340;
    }
    // 0x8006E324: nop

    // 0x8006E328: jal         0x80061348
    // 0x8006E32C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006E32C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_17:
    // 0x8006E330: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E334: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006E338: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E33C: nop

            goto L_8006E518;
    }
    // 0x8006E33C: nop

L_8006E340:
    // 0x8006E340: jal         0x80061348
    // 0x8006E344: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006E344: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_18:
    // 0x8006E348: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E34C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006E350: beq         $v0, $zero, L_8006E370
    if (ctx->r2 == 0) {
        // 0x8006E354: nop

            goto L_8006E370;
    }
    // 0x8006E354: nop

    // 0x8006E358: jal         0x80061348
    // 0x8006E35C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006E35C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_19:
    // 0x8006E360: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E364: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006E368: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E36C: nop

            goto L_8006E518;
    }
    // 0x8006E36C: nop

L_8006E370:
    // 0x8006E370: jal         0x80061348
    // 0x8006E374: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006E374: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_20:
    // 0x8006E378: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E37C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E380: beq         $v0, $zero, L_8006E3A0
    if (ctx->r2 == 0) {
        // 0x8006E384: nop

            goto L_8006E3A0;
    }
    // 0x8006E384: nop

    // 0x8006E388: jal         0x80061348
    // 0x8006E38C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006E38C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_21:
    // 0x8006E390: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E394: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006E398: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E39C: nop

            goto L_8006E518;
    }
    // 0x8006E39C: nop

L_8006E3A0:
    // 0x8006E3A0: jal         0x80061348
    // 0x8006E3A4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006E3A4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_22:
    // 0x8006E3A8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E3AC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006E3B0: beq         $v0, $zero, L_8006E3D0
    if (ctx->r2 == 0) {
        // 0x8006E3B4: nop

            goto L_8006E3D0;
    }
    // 0x8006E3B4: nop

    // 0x8006E3B8: jal         0x80061348
    // 0x8006E3BC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006E3BC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_23:
    // 0x8006E3C0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E3C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006E3C8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E3CC: nop

            goto L_8006E518;
    }
    // 0x8006E3CC: nop

L_8006E3D0:
    // 0x8006E3D0: jal         0x80061348
    // 0x8006E3D4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_24;
    // 0x8006E3D4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_24:
    // 0x8006E3D8: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E3DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006E3E0: beq         $v0, $zero, L_8006E400
    if (ctx->r2 == 0) {
        // 0x8006E3E4: nop

            goto L_8006E400;
    }
    // 0x8006E3E4: nop

    // 0x8006E3E8: jal         0x80061348
    // 0x8006E3EC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_25;
    // 0x8006E3EC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_25:
    // 0x8006E3F0: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E3F4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E3F8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E3FC: nop

            goto L_8006E518;
    }
    // 0x8006E3FC: nop

L_8006E400:
    // 0x8006E400: jal         0x80061348
    // 0x8006E404: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_26;
    // 0x8006E404: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_26:
    // 0x8006E408: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E40C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006E410: beq         $v0, $zero, L_8006E430
    if (ctx->r2 == 0) {
        // 0x8006E414: nop

            goto L_8006E430;
    }
    // 0x8006E414: nop

    // 0x8006E418: jal         0x80061348
    // 0x8006E41C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_27;
    // 0x8006E41C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_27:
    // 0x8006E420: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E424: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006E428: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E42C: nop

            goto L_8006E518;
    }
    // 0x8006E42C: nop

L_8006E430:
    // 0x8006E430: jal         0x80061348
    // 0x8006E434: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_28;
    // 0x8006E434: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_28:
    // 0x8006E438: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E43C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006E440: beq         $v0, $zero, L_8006E460
    if (ctx->r2 == 0) {
        // 0x8006E444: nop

            goto L_8006E460;
    }
    // 0x8006E444: nop

    // 0x8006E448: jal         0x80061348
    // 0x8006E44C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_29;
    // 0x8006E44C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_29:
    // 0x8006E450: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E454: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006E458: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E45C: nop

            goto L_8006E518;
    }
    // 0x8006E45C: nop

L_8006E460:
    // 0x8006E460: jal         0x80061348
    // 0x8006E464: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_30;
    // 0x8006E464: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_30:
    // 0x8006E468: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E46C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E470: beq         $v0, $zero, L_8006E490
    if (ctx->r2 == 0) {
        // 0x8006E474: nop

            goto L_8006E490;
    }
    // 0x8006E474: nop

    // 0x8006E478: jal         0x80061348
    // 0x8006E47C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_31;
    // 0x8006E47C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_31:
    // 0x8006E480: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E484: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006E488: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E48C: nop

            goto L_8006E518;
    }
    // 0x8006E48C: nop

L_8006E490:
    // 0x8006E490: jal         0x80061348
    // 0x8006E494: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_32;
    // 0x8006E494: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_32:
    // 0x8006E498: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E49C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006E4A0: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E4A4: nop

            goto L_8006E518;
    }
    // 0x8006E4A4: nop

    // 0x8006E4A8: jal         0x80061348
    // 0x8006E4AC: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_33;
    // 0x8006E4AC: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_33:
    // 0x8006E4B0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E4B4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006E4B8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E4BC: nop

            goto L_8006E518;
    }
    // 0x8006E4BC: nop

    // 0x8006E4C0: jal         0x80061348
    // 0x8006E4C4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_34;
    // 0x8006E4C4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_34:
    // 0x8006E4C8: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E4CC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006E4D0: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E4D4: nop

            goto L_8006E518;
    }
    // 0x8006E4D4: nop

    // 0x8006E4D8: jal         0x80061348
    // 0x8006E4DC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_35;
    // 0x8006E4DC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_35:
    // 0x8006E4E0: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E4E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E4E8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E4EC: nop

            goto L_8006E518;
    }
    // 0x8006E4EC: nop

    // 0x8006E4F0: jal         0x80061348
    // 0x8006E4F4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_36;
    // 0x8006E4F4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_36:
    // 0x8006E4F8: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E4FC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006E500: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E504: nop

            goto L_8006E518;
    }
    // 0x8006E504: nop

    // 0x8006E508: jal         0x80061348
    // 0x8006E50C: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_37;
    // 0x8006E50C: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_37:
    // 0x8006E510: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E514: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_8006E518:
    // 0x8006E518: b           L_8006E528
    // 0x8006E51C: nop

        goto L_8006E528;
    // 0x8006E51C: nop

    // 0x8006E520: b           L_8006E528
    // 0x8006E524: nop

        goto L_8006E528;
    // 0x8006E524: nop

L_8006E528:
    // 0x8006E528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E52C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E530: jr          $ra
    // 0x8006E534: nop

    return;
    // 0x8006E534: nop

;}
RECOMP_FUNC void func_8006E538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E53C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E540: jal         0x80061348
    // 0x8006E544: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E544: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E548: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E54C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E550: beq         $v0, $zero, L_8006E568
    if (ctx->r2 == 0) {
        // 0x8006E554: nop

            goto L_8006E568;
    }
    // 0x8006E554: nop

    // 0x8006E558: jal         0x80061348
    // 0x8006E55C: addiu       $a0, $zero, 0x12B
    ctx->r4 = ADD32(0, 0X12B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E55C: addiu       $a0, $zero, 0x12B
    ctx->r4 = ADD32(0, 0X12B);
    after_1:
    // 0x8006E560: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E564: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E568:
    // 0x8006E568: b           L_8006E578
    // 0x8006E56C: nop

        goto L_8006E578;
    // 0x8006E56C: nop

    // 0x8006E570: b           L_8006E578
    // 0x8006E574: nop

        goto L_8006E578;
    // 0x8006E574: nop

L_8006E578:
    // 0x8006E578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E57C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E580: jr          $ra
    // 0x8006E584: nop

    return;
    // 0x8006E584: nop

;}
RECOMP_FUNC void func_8006E588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E58C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E590: jal         0x80061348
    // 0x8006E594: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E594: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E598: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E59C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E5A0: beq         $v0, $zero, L_8006E5B8
    if (ctx->r2 == 0) {
        // 0x8006E5A4: nop

            goto L_8006E5B8;
    }
    // 0x8006E5A4: nop

    // 0x8006E5A8: jal         0x80061348
    // 0x8006E5AC: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E5AC: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    after_1:
    // 0x8006E5B0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E5B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E5B8:
    // 0x8006E5B8: b           L_8006E5C8
    // 0x8006E5BC: nop

        goto L_8006E5C8;
    // 0x8006E5BC: nop

    // 0x8006E5C0: b           L_8006E5C8
    // 0x8006E5C4: nop

        goto L_8006E5C8;
    // 0x8006E5C4: nop

L_8006E5C8:
    // 0x8006E5C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E5CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E5D0: jr          $ra
    // 0x8006E5D4: nop

    return;
    // 0x8006E5D4: nop

;}
RECOMP_FUNC void func_8006E5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E5D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E5E0: jal         0x80061348
    // 0x8006E5E4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E5E4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E5E8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E5EC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E5F0: beq         $v0, $zero, L_8006E608
    if (ctx->r2 == 0) {
        // 0x8006E5F4: nop

            goto L_8006E608;
    }
    // 0x8006E5F4: nop

    // 0x8006E5F8: jal         0x80061348
    // 0x8006E5FC: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E5FC: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    after_1:
    // 0x8006E600: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E604: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E608:
    // 0x8006E608: b           L_8006E618
    // 0x8006E60C: nop

        goto L_8006E618;
    // 0x8006E60C: nop

    // 0x8006E610: b           L_8006E618
    // 0x8006E614: nop

        goto L_8006E618;
    // 0x8006E614: nop

L_8006E618:
    // 0x8006E618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E620: jr          $ra
    // 0x8006E624: nop

    return;
    // 0x8006E624: nop

;}
RECOMP_FUNC void func_8006E628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E62C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E630: jal         0x80061348
    // 0x8006E634: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E634: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E638: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E63C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E640: beq         $v0, $zero, L_8006E658
    if (ctx->r2 == 0) {
        // 0x8006E644: nop

            goto L_8006E658;
    }
    // 0x8006E644: nop

    // 0x8006E648: jal         0x80061348
    // 0x8006E64C: addiu       $a0, $zero, 0x14A
    ctx->r4 = ADD32(0, 0X14A);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E64C: addiu       $a0, $zero, 0x14A
    ctx->r4 = ADD32(0, 0X14A);
    after_1:
    // 0x8006E650: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E654: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E658:
    // 0x8006E658: b           L_8006E668
    // 0x8006E65C: nop

        goto L_8006E668;
    // 0x8006E65C: nop

    // 0x8006E660: b           L_8006E668
    // 0x8006E664: nop

        goto L_8006E668;
    // 0x8006E664: nop

L_8006E668:
    // 0x8006E668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E670: jr          $ra
    // 0x8006E674: nop

    return;
    // 0x8006E674: nop

;}
RECOMP_FUNC void func_8006E678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E680: jal         0x80061348
    // 0x8006E684: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E684: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E688: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E68C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E690: beq         $v0, $zero, L_8006E6A8
    if (ctx->r2 == 0) {
        // 0x8006E694: nop

            goto L_8006E6A8;
    }
    // 0x8006E694: nop

    // 0x8006E698: jal         0x80061348
    // 0x8006E69C: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E69C: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_1:
    // 0x8006E6A0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E6A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E6A8:
    // 0x8006E6A8: b           L_8006E6B8
    // 0x8006E6AC: nop

        goto L_8006E6B8;
    // 0x8006E6AC: nop

    // 0x8006E6B0: b           L_8006E6B8
    // 0x8006E6B4: nop

        goto L_8006E6B8;
    // 0x8006E6B4: nop

L_8006E6B8:
    // 0x8006E6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E6BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E6C0: jr          $ra
    // 0x8006E6C4: nop

    return;
    // 0x8006E6C4: nop

;}
RECOMP_FUNC void func_8006E6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E6C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E6CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E6D0: jal         0x80061348
    // 0x8006E6D4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E6D4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E6D8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E6DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E6E0: beq         $v0, $zero, L_8006E6FC
    if (ctx->r2 == 0) {
        // 0x8006E6E4: nop

            goto L_8006E6FC;
    }
    // 0x8006E6E4: nop

    // 0x8006E6E8: jal         0x80061348
    // 0x8006E6EC: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E6EC: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_1:
    // 0x8006E6F0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006E6F4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006E6F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E6FC:
    // 0x8006E6FC: b           L_8006E70C
    // 0x8006E700: nop

        goto L_8006E70C;
    // 0x8006E700: nop

    // 0x8006E704: b           L_8006E70C
    // 0x8006E708: nop

        goto L_8006E70C;
    // 0x8006E708: nop

L_8006E70C:
    // 0x8006E70C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E714: jr          $ra
    // 0x8006E718: nop

    return;
    // 0x8006E718: nop

;}
RECOMP_FUNC void func_8006E71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E71C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E724: jal         0x80061348
    // 0x8006E728: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E728: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E72C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E730: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E734: beq         $v0, $zero, L_8006E74C
    if (ctx->r2 == 0) {
        // 0x8006E738: nop

            goto L_8006E74C;
    }
    // 0x8006E738: nop

    // 0x8006E73C: jal         0x80061348
    // 0x8006E740: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E740: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    after_1:
    // 0x8006E744: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E748: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E74C:
    // 0x8006E74C: b           L_8006E75C
    // 0x8006E750: nop

        goto L_8006E75C;
    // 0x8006E750: nop

    // 0x8006E754: b           L_8006E75C
    // 0x8006E758: nop

        goto L_8006E75C;
    // 0x8006E758: nop

L_8006E75C:
    // 0x8006E75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E764: jr          $ra
    // 0x8006E768: nop

    return;
    // 0x8006E768: nop

;}
RECOMP_FUNC void func_8006E76C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E76C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E774: jal         0x80061348
    // 0x8006E778: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E778: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E77C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E780: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E784: beq         $v0, $zero, L_8006E79C
    if (ctx->r2 == 0) {
        // 0x8006E788: nop

            goto L_8006E79C;
    }
    // 0x8006E788: nop

    // 0x8006E78C: jal         0x80061348
    // 0x8006E790: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E790: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    after_1:
    // 0x8006E794: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E798: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E79C:
    // 0x8006E79C: b           L_8006E7AC
    // 0x8006E7A0: nop

        goto L_8006E7AC;
    // 0x8006E7A0: nop

    // 0x8006E7A4: b           L_8006E7AC
    // 0x8006E7A8: nop

        goto L_8006E7AC;
    // 0x8006E7A8: nop

L_8006E7AC:
    // 0x8006E7AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E7B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E7B4: jr          $ra
    // 0x8006E7B8: nop

    return;
    // 0x8006E7B8: nop

;}
RECOMP_FUNC void func_8006E7BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E7BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E7C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E7C4: jal         0x80061348
    // 0x8006E7C8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E7C8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E7CC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E7D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E7D4: beq         $v0, $zero, L_8006E7EC
    if (ctx->r2 == 0) {
        // 0x8006E7D8: nop

            goto L_8006E7EC;
    }
    // 0x8006E7D8: nop

    // 0x8006E7DC: jal         0x80061348
    // 0x8006E7E0: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E7E0: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    after_1:
    // 0x8006E7E4: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E7E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E7EC:
    // 0x8006E7EC: b           L_8006E7FC
    // 0x8006E7F0: nop

        goto L_8006E7FC;
    // 0x8006E7F0: nop

    // 0x8006E7F4: b           L_8006E7FC
    // 0x8006E7F8: nop

        goto L_8006E7FC;
    // 0x8006E7F8: nop

L_8006E7FC:
    // 0x8006E7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E804: jr          $ra
    // 0x8006E808: nop

    return;
    // 0x8006E808: nop

;}
RECOMP_FUNC void func_8006E80C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E80C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E814: jal         0x80061348
    // 0x8006E818: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E818: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E81C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E820: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E824: beq         $v0, $zero, L_8006E83C
    if (ctx->r2 == 0) {
        // 0x8006E828: nop

            goto L_8006E83C;
    }
    // 0x8006E828: nop

    // 0x8006E82C: jal         0x80061348
    // 0x8006E830: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E830: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    after_1:
    // 0x8006E834: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E838: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E83C:
    // 0x8006E83C: b           L_8006E84C
    // 0x8006E840: nop

        goto L_8006E84C;
    // 0x8006E840: nop

    // 0x8006E844: b           L_8006E84C
    // 0x8006E848: nop

        goto L_8006E84C;
    // 0x8006E848: nop

L_8006E84C:
    // 0x8006E84C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E854: jr          $ra
    // 0x8006E858: nop

    return;
    // 0x8006E858: nop

;}
RECOMP_FUNC void func_8006E85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E85C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E864: jal         0x80061348
    // 0x8006E868: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E868: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E86C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E870: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E874: beq         $v0, $zero, L_8006E890
    if (ctx->r2 == 0) {
        // 0x8006E878: nop

            goto L_8006E890;
    }
    // 0x8006E878: nop

    // 0x8006E87C: jal         0x80061348
    // 0x8006E880: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E880: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    after_1:
    // 0x8006E884: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006E888: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006E88C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E890:
    // 0x8006E890: b           L_8006E8A0
    // 0x8006E894: nop

        goto L_8006E8A0;
    // 0x8006E894: nop

    // 0x8006E898: b           L_8006E8A0
    // 0x8006E89C: nop

        goto L_8006E8A0;
    // 0x8006E89C: nop

L_8006E8A0:
    // 0x8006E8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E8A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E8A8: jr          $ra
    // 0x8006E8AC: nop

    return;
    // 0x8006E8AC: nop

;}
RECOMP_FUNC void func_8006E8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E8B8: jal         0x80061348
    // 0x8006E8BC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E8BC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E8C0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006E8C4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006E8C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E8CC: beq         $v0, $zero, L_8006E8E4
    if (ctx->r2 == 0) {
        // 0x8006E8D0: nop

            goto L_8006E8E4;
    }
    // 0x8006E8D0: nop

    // 0x8006E8D4: jal         0x80061348
    // 0x8006E8D8: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E8D8: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_1:
    // 0x8006E8DC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E8E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E8E4:
    // 0x8006E8E4: b           L_8006E8F4
    // 0x8006E8E8: nop

        goto L_8006E8F4;
    // 0x8006E8E8: nop

    // 0x8006E8EC: b           L_8006E8F4
    // 0x8006E8F0: nop

        goto L_8006E8F4;
    // 0x8006E8F0: nop

L_8006E8F4:
    // 0x8006E8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E8F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E8FC: jr          $ra
    // 0x8006E900: nop

    return;
    // 0x8006E900: nop

;}
RECOMP_FUNC void func_8006E904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E90C: jal         0x80061348
    // 0x8006E910: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E910: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E914: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006E918: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006E91C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E920: beq         $v0, $zero, L_8006E938
    if (ctx->r2 == 0) {
        // 0x8006E924: nop

            goto L_8006E938;
    }
    // 0x8006E924: nop

    // 0x8006E928: jal         0x80061348
    // 0x8006E92C: addiu       $a0, $zero, 0x2C6
    ctx->r4 = ADD32(0, 0X2C6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E92C: addiu       $a0, $zero, 0x2C6
    ctx->r4 = ADD32(0, 0X2C6);
    after_1:
    // 0x8006E930: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E934: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E938:
    // 0x8006E938: b           L_8006E948
    // 0x8006E93C: nop

        goto L_8006E948;
    // 0x8006E93C: nop

    // 0x8006E940: b           L_8006E948
    // 0x8006E944: nop

        goto L_8006E948;
    // 0x8006E944: nop

L_8006E948:
    // 0x8006E948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E94C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E950: jr          $ra
    // 0x8006E954: nop

    return;
    // 0x8006E954: nop

;}
RECOMP_FUNC void func_8006E958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E960: jal         0x80061348
    // 0x8006E964: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E964: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E968: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006E96C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006E970: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E974: beq         $v0, $zero, L_8006E98C
    if (ctx->r2 == 0) {
        // 0x8006E978: nop

            goto L_8006E98C;
    }
    // 0x8006E978: nop

    // 0x8006E97C: jal         0x80061348
    // 0x8006E980: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E980: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    after_1:
    // 0x8006E984: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E988: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E98C:
    // 0x8006E98C: b           L_8006E99C
    // 0x8006E990: nop

        goto L_8006E99C;
    // 0x8006E990: nop

    // 0x8006E994: b           L_8006E99C
    // 0x8006E998: nop

        goto L_8006E99C;
    // 0x8006E998: nop

L_8006E99C:
    // 0x8006E99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E9A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E9A4: jr          $ra
    // 0x8006E9A8: nop

    return;
    // 0x8006E9A8: nop

;}
RECOMP_FUNC void func_8006E9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E9AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E9B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E9B4: jal         0x80061348
    // 0x8006E9B8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E9B8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E9BC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006E9C0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006E9C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E9C8: beq         $v0, $zero, L_8006E9E4
    if (ctx->r2 == 0) {
        // 0x8006E9CC: nop

            goto L_8006E9E4;
    }
    // 0x8006E9CC: nop

    // 0x8006E9D0: jal         0x80061348
    // 0x8006E9D4: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E9D4: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    after_1:
    // 0x8006E9D8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006E9DC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006E9E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E9E4:
    // 0x8006E9E4: b           L_8006E9F4
    // 0x8006E9E8: nop

        goto L_8006E9F4;
    // 0x8006E9E8: nop

    // 0x8006E9EC: b           L_8006E9F4
    // 0x8006E9F0: nop

        goto L_8006E9F4;
    // 0x8006E9F0: nop

L_8006E9F4:
    // 0x8006E9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E9F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E9FC: jr          $ra
    // 0x8006EA00: nop

    return;
    // 0x8006EA00: nop

;}
RECOMP_FUNC void func_8006EA04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EA04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EA08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EA0C: jal         0x80061348
    // 0x8006EA10: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EA10: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006EA14: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EA18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EA1C: beq         $v0, $zero, L_8006EA3C
    if (ctx->r2 == 0) {
        // 0x8006EA20: nop

            goto L_8006EA3C;
    }
    // 0x8006EA20: nop

    // 0x8006EA24: jal         0x80061348
    // 0x8006EA28: addiu       $a0, $zero, 0x12B
    ctx->r4 = ADD32(0, 0X12B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006EA28: addiu       $a0, $zero, 0x12B
    ctx->r4 = ADD32(0, 0X12B);
    after_1:
    // 0x8006EA2C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EA30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006EA34: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EA38: nop

            goto L_8006ECF0;
    }
    // 0x8006EA38: nop

L_8006EA3C:
    // 0x8006EA3C: jal         0x80061348
    // 0x8006EA40: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006EA40: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_2:
    // 0x8006EA44: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EA48: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006EA4C: beq         $v0, $zero, L_8006EA6C
    if (ctx->r2 == 0) {
        // 0x8006EA50: nop

            goto L_8006EA6C;
    }
    // 0x8006EA50: nop

    // 0x8006EA54: jal         0x80061348
    // 0x8006EA58: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006EA58: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    after_3:
    // 0x8006EA5C: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EA60: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006EA64: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EA68: nop

            goto L_8006ECF0;
    }
    // 0x8006EA68: nop

L_8006EA6C:
    // 0x8006EA6C: jal         0x80061348
    // 0x8006EA70: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006EA70: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_4:
    // 0x8006EA74: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EA78: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006EA7C: beq         $v0, $zero, L_8006EA9C
    if (ctx->r2 == 0) {
        // 0x8006EA80: nop

            goto L_8006EA9C;
    }
    // 0x8006EA80: nop

    // 0x8006EA84: jal         0x80061348
    // 0x8006EA88: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006EA88: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    after_5:
    // 0x8006EA8C: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EA90: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006EA94: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EA98: nop

            goto L_8006ECF0;
    }
    // 0x8006EA98: nop

L_8006EA9C:
    // 0x8006EA9C: jal         0x80061348
    // 0x8006EAA0: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006EAA0: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_6:
    // 0x8006EAA4: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EAA8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006EAAC: beq         $v0, $zero, L_8006EACC
    if (ctx->r2 == 0) {
        // 0x8006EAB0: nop

            goto L_8006EACC;
    }
    // 0x8006EAB0: nop

    // 0x8006EAB4: jal         0x80061348
    // 0x8006EAB8: addiu       $a0, $zero, 0x14A
    ctx->r4 = ADD32(0, 0X14A);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006EAB8: addiu       $a0, $zero, 0x14A
    ctx->r4 = ADD32(0, 0X14A);
    after_7:
    // 0x8006EABC: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EAC0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006EAC4: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EAC8: nop

            goto L_8006ECF0;
    }
    // 0x8006EAC8: nop

L_8006EACC:
    // 0x8006EACC: jal         0x80061348
    // 0x8006EAD0: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006EAD0: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_8:
    // 0x8006EAD4: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EAD8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006EADC: beq         $v0, $zero, L_8006EAFC
    if (ctx->r2 == 0) {
        // 0x8006EAE0: nop

            goto L_8006EAFC;
    }
    // 0x8006EAE0: nop

    // 0x8006EAE4: jal         0x80061348
    // 0x8006EAE8: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006EAE8: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_9:
    // 0x8006EAEC: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EAF0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006EAF4: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EAF8: nop

            goto L_8006ECF0;
    }
    // 0x8006EAF8: nop

L_8006EAFC:
    // 0x8006EAFC: jal         0x80061348
    // 0x8006EB00: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006EB00: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_10:
    // 0x8006EB04: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EB08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EB0C: beq         $v0, $zero, L_8006EB30
    if (ctx->r2 == 0) {
        // 0x8006EB10: nop

            goto L_8006EB30;
    }
    // 0x8006EB10: nop

    // 0x8006EB14: jal         0x80061348
    // 0x8006EB18: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006EB18: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_11:
    // 0x8006EB1C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006EB20: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006EB24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006EB28: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EB2C: nop

            goto L_8006ECF0;
    }
    // 0x8006EB2C: nop

L_8006EB30:
    // 0x8006EB30: jal         0x80061348
    // 0x8006EB34: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006EB34: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_12:
    // 0x8006EB38: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EB3C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006EB40: beq         $v0, $zero, L_8006EB60
    if (ctx->r2 == 0) {
        // 0x8006EB44: nop

            goto L_8006EB60;
    }
    // 0x8006EB44: nop

    // 0x8006EB48: jal         0x80061348
    // 0x8006EB4C: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006EB4C: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    after_13:
    // 0x8006EB50: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EB54: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006EB58: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EB5C: nop

            goto L_8006ECF0;
    }
    // 0x8006EB5C: nop

L_8006EB60:
    // 0x8006EB60: jal         0x80061348
    // 0x8006EB64: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006EB64: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_14:
    // 0x8006EB68: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EB6C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006EB70: beq         $v0, $zero, L_8006EB90
    if (ctx->r2 == 0) {
        // 0x8006EB74: nop

            goto L_8006EB90;
    }
    // 0x8006EB74: nop

    // 0x8006EB78: jal         0x80061348
    // 0x8006EB7C: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006EB7C: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    after_15:
    // 0x8006EB80: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EB84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006EB88: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EB8C: nop

            goto L_8006ECF0;
    }
    // 0x8006EB8C: nop

L_8006EB90:
    // 0x8006EB90: jal         0x80061348
    // 0x8006EB94: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006EB94: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_16:
    // 0x8006EB98: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EB9C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006EBA0: beq         $v0, $zero, L_8006EBC0
    if (ctx->r2 == 0) {
        // 0x8006EBA4: nop

            goto L_8006EBC0;
    }
    // 0x8006EBA4: nop

    // 0x8006EBA8: jal         0x80061348
    // 0x8006EBAC: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006EBAC: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    after_17:
    // 0x8006EBB0: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EBB4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006EBB8: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EBBC: nop

            goto L_8006ECF0;
    }
    // 0x8006EBBC: nop

L_8006EBC0:
    // 0x8006EBC0: jal         0x80061348
    // 0x8006EBC4: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006EBC4: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_18:
    // 0x8006EBC8: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EBCC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006EBD0: beq         $v0, $zero, L_8006EBF0
    if (ctx->r2 == 0) {
        // 0x8006EBD4: nop

            goto L_8006EBF0;
    }
    // 0x8006EBD4: nop

    // 0x8006EBD8: jal         0x80061348
    // 0x8006EBDC: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006EBDC: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    after_19:
    // 0x8006EBE0: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EBE4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006EBE8: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EBEC: nop

            goto L_8006ECF0;
    }
    // 0x8006EBEC: nop

L_8006EBF0:
    // 0x8006EBF0: jal         0x80061348
    // 0x8006EBF4: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006EBF4: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_20:
    // 0x8006EBF8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EBFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EC00: beq         $v0, $zero, L_8006EC24
    if (ctx->r2 == 0) {
        // 0x8006EC04: nop

            goto L_8006EC24;
    }
    // 0x8006EC04: nop

    // 0x8006EC08: jal         0x80061348
    // 0x8006EC0C: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006EC0C: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    after_21:
    // 0x8006EC10: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006EC14: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006EC18: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006EC1C: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EC20: nop

            goto L_8006ECF0;
    }
    // 0x8006EC20: nop

L_8006EC24:
    // 0x8006EC24: jal         0x80061348
    // 0x8006EC28: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006EC28: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_22:
    // 0x8006EC2C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006EC30: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006EC34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006EC38: beq         $v0, $zero, L_8006EC58
    if (ctx->r2 == 0) {
        // 0x8006EC3C: nop

            goto L_8006EC58;
    }
    // 0x8006EC3C: nop

    // 0x8006EC40: jal         0x80061348
    // 0x8006EC44: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006EC44: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_23:
    // 0x8006EC48: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EC4C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006EC50: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EC54: nop

            goto L_8006ECF0;
    }
    // 0x8006EC54: nop

L_8006EC58:
    // 0x8006EC58: jal         0x80061348
    // 0x8006EC5C: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_24;
    // 0x8006EC5C: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_24:
    // 0x8006EC60: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006EC64: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006EC68: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006EC6C: beq         $v0, $zero, L_8006EC8C
    if (ctx->r2 == 0) {
        // 0x8006EC70: nop

            goto L_8006EC8C;
    }
    // 0x8006EC70: nop

    // 0x8006EC74: jal         0x80061348
    // 0x8006EC78: addiu       $a0, $zero, 0x2C6
    ctx->r4 = ADD32(0, 0X2C6);
    func_80061348(rdram, ctx);
        goto after_25;
    // 0x8006EC78: addiu       $a0, $zero, 0x2C6
    ctx->r4 = ADD32(0, 0X2C6);
    after_25:
    // 0x8006EC7C: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EC80: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006EC84: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006EC88: nop

            goto L_8006ECF0;
    }
    // 0x8006EC88: nop

L_8006EC8C:
    // 0x8006EC8C: jal         0x80061348
    // 0x8006EC90: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_26;
    // 0x8006EC90: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_26:
    // 0x8006EC94: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006EC98: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006EC9C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006ECA0: beq         $v0, $zero, L_8006ECC0
    if (ctx->r2 == 0) {
        // 0x8006ECA4: nop

            goto L_8006ECC0;
    }
    // 0x8006ECA4: nop

    // 0x8006ECA8: jal         0x80061348
    // 0x8006ECAC: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    func_80061348(rdram, ctx);
        goto after_27;
    // 0x8006ECAC: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    after_27:
    // 0x8006ECB0: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006ECB4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006ECB8: bne         $v0, $zero, L_8006ECF0
    if (ctx->r2 != 0) {
        // 0x8006ECBC: nop

            goto L_8006ECF0;
    }
    // 0x8006ECBC: nop

L_8006ECC0:
    // 0x8006ECC0: jal         0x80061348
    // 0x8006ECC4: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_28;
    // 0x8006ECC4: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_28:
    // 0x8006ECC8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006ECCC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006ECD0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006ECD4: beq         $v0, $zero, L_8006ECF0
    if (ctx->r2 == 0) {
        // 0x8006ECD8: nop

            goto L_8006ECF0;
    }
    // 0x8006ECD8: nop

    // 0x8006ECDC: jal         0x80061348
    // 0x8006ECE0: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    func_80061348(rdram, ctx);
        goto after_29;
    // 0x8006ECE0: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    after_29:
    // 0x8006ECE4: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006ECE8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006ECEC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8006ECF0:
    // 0x8006ECF0: b           L_8006ED00
    // 0x8006ECF4: nop

        goto L_8006ED00;
    // 0x8006ECF4: nop

    // 0x8006ECF8: b           L_8006ED00
    // 0x8006ECFC: nop

        goto L_8006ED00;
    // 0x8006ECFC: nop

L_8006ED00:
    // 0x8006ED00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ED04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ED08: jr          $ra
    // 0x8006ED0C: nop

    return;
    // 0x8006ED0C: nop

;}
RECOMP_FUNC void func_8006ED10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ED14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED18: jal         0x80061348
    // 0x8006ED1C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006ED1C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_0:
    // 0x8006ED20: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006ED24: b           L_8006ED34
    // 0x8006ED28: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006ED34;
    // 0x8006ED28: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006ED2C: b           L_8006ED34
    // 0x8006ED30: nop

        goto L_8006ED34;
    // 0x8006ED30: nop

L_8006ED34:
    // 0x8006ED34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ED38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ED3C: jr          $ra
    // 0x8006ED40: nop

    return;
    // 0x8006ED40: nop

;}
RECOMP_FUNC void func_8006ED44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ED48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED4C: jal         0x80061348
    // 0x8006ED50: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006ED50: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    after_0:
    // 0x8006ED54: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006ED58: b           L_8006ED68
    // 0x8006ED5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006ED68;
    // 0x8006ED5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006ED60: b           L_8006ED68
    // 0x8006ED64: nop

        goto L_8006ED68;
    // 0x8006ED64: nop

L_8006ED68:
    // 0x8006ED68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ED6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ED70: jr          $ra
    // 0x8006ED74: nop

    return;
    // 0x8006ED74: nop

;}
RECOMP_FUNC void func_8006ED78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ED7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED80: jal         0x80061348
    // 0x8006ED84: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006ED84: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    after_0:
    // 0x8006ED88: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006ED8C: b           L_8006ED9C
    // 0x8006ED90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006ED9C;
    // 0x8006ED90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006ED94: b           L_8006ED9C
    // 0x8006ED98: nop

        goto L_8006ED9C;
    // 0x8006ED98: nop

L_8006ED9C:
    // 0x8006ED9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EDA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EDA4: jr          $ra
    // 0x8006EDA8: nop

    return;
    // 0x8006EDA8: nop

;}
RECOMP_FUNC void func_8006EDAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EDB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EDB4: jal         0x80061348
    // 0x8006EDB8: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EDB8: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    after_0:
    // 0x8006EDBC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EDC0: b           L_8006EDD0
    // 0x8006EDC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EDD0;
    // 0x8006EDC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EDC8: b           L_8006EDD0
    // 0x8006EDCC: nop

        goto L_8006EDD0;
    // 0x8006EDCC: nop

L_8006EDD0:
    // 0x8006EDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EDD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EDD8: jr          $ra
    // 0x8006EDDC: nop

    return;
    // 0x8006EDDC: nop

;}
RECOMP_FUNC void func_8006EDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EDE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EDE8: jal         0x80061348
    // 0x8006EDEC: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EDEC: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_0:
    // 0x8006EDF0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EDF4: b           L_8006EE04
    // 0x8006EDF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EE04;
    // 0x8006EDF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EDFC: b           L_8006EE04
    // 0x8006EE00: nop

        goto L_8006EE04;
    // 0x8006EE00: nop

L_8006EE04:
    // 0x8006EE04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EE08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EE0C: jr          $ra
    // 0x8006EE10: nop

    return;
    // 0x8006EE10: nop

;}
RECOMP_FUNC void func_8006EE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EE1C: jal         0x80061348
    // 0x8006EE20: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EE20: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_0:
    // 0x8006EE24: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006EE28: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006EE2C: b           L_8006EE3C
    // 0x8006EE30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EE3C;
    // 0x8006EE30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EE34: b           L_8006EE3C
    // 0x8006EE38: nop

        goto L_8006EE3C;
    // 0x8006EE38: nop

L_8006EE3C:
    // 0x8006EE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EE40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EE44: jr          $ra
    // 0x8006EE48: nop

    return;
    // 0x8006EE48: nop

;}
RECOMP_FUNC void func_8006EE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EE50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EE54: jal         0x80061348
    // 0x8006EE58: addiu       $a0, $zero, 0x14E
    ctx->r4 = ADD32(0, 0X14E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EE58: addiu       $a0, $zero, 0x14E
    ctx->r4 = ADD32(0, 0X14E);
    after_0:
    // 0x8006EE5C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EE60: b           L_8006EE70
    // 0x8006EE64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EE70;
    // 0x8006EE64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EE68: b           L_8006EE70
    // 0x8006EE6C: nop

        goto L_8006EE70;
    // 0x8006EE6C: nop

L_8006EE70:
    // 0x8006EE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EE74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EE78: jr          $ra
    // 0x8006EE7C: nop

    return;
    // 0x8006EE7C: nop

;}
RECOMP_FUNC void func_8006EE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EE84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EE88: jal         0x80061348
    // 0x8006EE8C: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EE8C: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    after_0:
    // 0x8006EE90: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EE94: b           L_8006EEA4
    // 0x8006EE98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EEA4;
    // 0x8006EE98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EE9C: b           L_8006EEA4
    // 0x8006EEA0: nop

        goto L_8006EEA4;
    // 0x8006EEA0: nop

L_8006EEA4:
    // 0x8006EEA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EEA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EEAC: jr          $ra
    // 0x8006EEB0: nop

    return;
    // 0x8006EEB0: nop

;}
RECOMP_FUNC void func_8006EEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EEB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EEBC: jal         0x80061348
    // 0x8006EEC0: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EEC0: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    after_0:
    // 0x8006EEC4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EEC8: b           L_8006EED8
    // 0x8006EECC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EED8;
    // 0x8006EECC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EED0: b           L_8006EED8
    // 0x8006EED4: nop

        goto L_8006EED8;
    // 0x8006EED4: nop

L_8006EED8:
    // 0x8006EED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EEDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EEE0: jr          $ra
    // 0x8006EEE4: nop

    return;
    // 0x8006EEE4: nop

;}
RECOMP_FUNC void func_8006EEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EEE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EEF0: jal         0x80061348
    // 0x8006EEF4: addiu       $a0, $zero, 0x153
    ctx->r4 = ADD32(0, 0X153);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EEF4: addiu       $a0, $zero, 0x153
    ctx->r4 = ADD32(0, 0X153);
    after_0:
    // 0x8006EEF8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EEFC: b           L_8006EF0C
    // 0x8006EF00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EF0C;
    // 0x8006EF00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EF04: b           L_8006EF0C
    // 0x8006EF08: nop

        goto L_8006EF0C;
    // 0x8006EF08: nop

L_8006EF0C:
    // 0x8006EF0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EF14: jr          $ra
    // 0x8006EF18: nop

    return;
    // 0x8006EF18: nop

;}
RECOMP_FUNC void func_8006EF1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EF20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EF24: jal         0x80061348
    // 0x8006EF28: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EF28: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_0:
    // 0x8006EF2C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EF30: b           L_8006EF40
    // 0x8006EF34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EF40;
    // 0x8006EF34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EF38: b           L_8006EF40
    // 0x8006EF3C: nop

        goto L_8006EF40;
    // 0x8006EF3C: nop

L_8006EF40:
    // 0x8006EF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EF48: jr          $ra
    // 0x8006EF4C: nop

    return;
    // 0x8006EF4C: nop

;}
RECOMP_FUNC void func_8006EF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EF54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EF58: jal         0x80061348
    // 0x8006EF5C: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EF5C: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    after_0:
    // 0x8006EF60: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EF64: b           L_8006EF74
    // 0x8006EF68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EF74;
    // 0x8006EF68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EF6C: b           L_8006EF74
    // 0x8006EF70: nop

        goto L_8006EF74;
    // 0x8006EF70: nop

L_8006EF74:
    // 0x8006EF74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EF7C: jr          $ra
    // 0x8006EF80: nop

    return;
    // 0x8006EF80: nop

;}
RECOMP_FUNC void func_8006EF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EF88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EF8C: jal         0x80061348
    // 0x8006EF90: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EF90: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    after_0:
    // 0x8006EF94: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006EF98: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006EF9C: b           L_8006EFAC
    // 0x8006EFA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EFAC;
    // 0x8006EFA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EFA4: b           L_8006EFAC
    // 0x8006EFA8: nop

        goto L_8006EFAC;
    // 0x8006EFA8: nop

L_8006EFAC:
    // 0x8006EFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EFB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EFB4: jr          $ra
    // 0x8006EFB8: nop

    return;
    // 0x8006EFB8: nop

;}
RECOMP_FUNC void func_8006EFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EFC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EFC4: jal         0x80061348
    // 0x8006EFC8: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EFC8: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    after_0:
    // 0x8006EFCC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EFD0: b           L_8006EFE0
    // 0x8006EFD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EFE0;
    // 0x8006EFD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EFD8: b           L_8006EFE0
    // 0x8006EFDC: nop

        goto L_8006EFE0;
    // 0x8006EFDC: nop

L_8006EFE0:
    // 0x8006EFE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EFE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EFE8: jr          $ra
    // 0x8006EFEC: nop

    return;
    // 0x8006EFEC: nop

;}
RECOMP_FUNC void func_8006EFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EFF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EFF8: jal         0x80061348
    // 0x8006EFFC: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EFFC: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    after_0:
    // 0x8006F000: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F004: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F008: bne         $v0, $zero, L_8006F024
    if (ctx->r2 != 0) {
        // 0x8006F00C: nop

            goto L_8006F024;
    }
    // 0x8006F00C: nop

    // 0x8006F010: jal         0x80061348
    // 0x8006F014: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006F014: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    after_1:
    // 0x8006F018: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006F01C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006F020: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006F024:
    // 0x8006F024: b           L_8006F034
    // 0x8006F028: nop

        goto L_8006F034;
    // 0x8006F028: nop

    // 0x8006F02C: b           L_8006F034
    // 0x8006F030: nop

        goto L_8006F034;
    // 0x8006F030: nop

L_8006F034:
    // 0x8006F034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F03C: jr          $ra
    // 0x8006F040: nop

    return;
    // 0x8006F040: nop

;}
RECOMP_FUNC void func_8006F044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F04C: jal         0x80061348
    // 0x8006F050: addiu       $a0, $zero, 0x2B1
    ctx->r4 = ADD32(0, 0X2B1);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F050: addiu       $a0, $zero, 0x2B1
    ctx->r4 = ADD32(0, 0X2B1);
    after_0:
    // 0x8006F054: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F058: b           L_8006F068
    // 0x8006F05C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F068;
    // 0x8006F05C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F060: b           L_8006F068
    // 0x8006F064: nop

        goto L_8006F068;
    // 0x8006F064: nop

L_8006F068:
    // 0x8006F068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F06C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F070: jr          $ra
    // 0x8006F074: nop

    return;
    // 0x8006F074: nop

;}
RECOMP_FUNC void func_8006F078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F07C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F080: jal         0x80061348
    // 0x8006F084: addiu       $a0, $zero, 0x2B5
    ctx->r4 = ADD32(0, 0X2B5);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F084: addiu       $a0, $zero, 0x2B5
    ctx->r4 = ADD32(0, 0X2B5);
    after_0:
    // 0x8006F088: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F08C: b           L_8006F09C
    // 0x8006F090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F09C;
    // 0x8006F090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F094: b           L_8006F09C
    // 0x8006F098: nop

        goto L_8006F09C;
    // 0x8006F098: nop

L_8006F09C:
    // 0x8006F09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F0A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F0A4: jr          $ra
    // 0x8006F0A8: nop

    return;
    // 0x8006F0A8: nop

;}
RECOMP_FUNC void func_8006F0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F0AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F0B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F0B4: jal         0x80061348
    // 0x8006F0B8: addiu       $a0, $zero, 0x2B8
    ctx->r4 = ADD32(0, 0X2B8);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F0B8: addiu       $a0, $zero, 0x2B8
    ctx->r4 = ADD32(0, 0X2B8);
    after_0:
    // 0x8006F0BC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F0C0: b           L_8006F0D0
    // 0x8006F0C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F0D0;
    // 0x8006F0C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F0C8: b           L_8006F0D0
    // 0x8006F0CC: nop

        goto L_8006F0D0;
    // 0x8006F0CC: nop

L_8006F0D0:
    // 0x8006F0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F0D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F0D8: jr          $ra
    // 0x8006F0DC: nop

    return;
    // 0x8006F0DC: nop

;}
RECOMP_FUNC void func_8006F0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F0E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F0E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F0E8: jal         0x80061348
    // 0x8006F0EC: addiu       $a0, $zero, 0x2BB
    ctx->r4 = ADD32(0, 0X2BB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F0EC: addiu       $a0, $zero, 0x2BB
    ctx->r4 = ADD32(0, 0X2BB);
    after_0:
    // 0x8006F0F0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F0F4: b           L_8006F104
    // 0x8006F0F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F104;
    // 0x8006F0F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F0FC: b           L_8006F104
    // 0x8006F100: nop

        goto L_8006F104;
    // 0x8006F100: nop

L_8006F104:
    // 0x8006F104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F10C: jr          $ra
    // 0x8006F110: nop

    return;
    // 0x8006F110: nop

;}
RECOMP_FUNC void func_8006F114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F11C: jal         0x80061348
    // 0x8006F120: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F120: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    after_0:
    // 0x8006F124: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F128: b           L_8006F138
    // 0x8006F12C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F138;
    // 0x8006F12C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F130: b           L_8006F138
    // 0x8006F134: nop

        goto L_8006F138;
    // 0x8006F134: nop

L_8006F138:
    // 0x8006F138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F140: jr          $ra
    // 0x8006F144: nop

    return;
    // 0x8006F144: nop

;}
