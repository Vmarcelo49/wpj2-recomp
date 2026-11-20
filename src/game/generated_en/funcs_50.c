#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800D1D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1D88: nop

    // 0x800D1D8C: nop

;}
RECOMP_FUNC void alSaveParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1D90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1D94: beq         $a1, $at, L_800D1DB0
    if (ctx->r5 == ctx->r1) {
        // 0x800D1D98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D1DB0;
    }
    // 0x800D1D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D1D9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800D1DA0: beql        $a1, $at, L_800D1DBC
    if (ctx->r5 == ctx->r1) {
        // 0x800D1DA4: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800D1DBC;
    }
    goto skip_0;
    // 0x800D1DA4: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800D1DA8: jr          $ra
    // 0x800D1DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D1DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D1DB0:
    // 0x800D1DB0: jr          $ra
    // 0x800D1DB4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x800D1DB4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800D1DB8: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800D1DBC:
    // 0x800D1DBC: jr          $ra
    // 0x800D1DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D1DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alSavePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1DC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D1DC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D1DCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D1DD0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800D1DD4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800D1DD8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D1DDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800D1DE0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800D1DE4: jalr        $t9
    // 0x800D1DE8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D1DE8: nop

    after_0:
    // 0x800D1DEC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800D1DF0: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800D1DF4: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x800D1DF8: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800D1DFC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800D1E00: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800D1E04: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x800D1E08: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x800D1E0C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800D1E10: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800D1E14: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800D1E18: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800D1E1C: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800D1E20: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800D1E24: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800D1E28: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800D1E2C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800D1E30: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D1E34: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800D1E38: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800D1E3C: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800D1E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1E44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D1E48: jr          $ra
    // 0x800D1E4C: nop

    return;
    // 0x800D1E4C: nop

;}
RECOMP_FUNC void func_800D1FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1FC8: nop

    // 0x800D1FCC: nop

;}
RECOMP_FUNC void __setInstChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1FD0: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x800D1FD4: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x800D1FD8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800D1FDC: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x800D1FE0: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x800D1FE4: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x800D1FE8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800D1FEC: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x800D1FF0: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x800D1FF4: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x800D1FF8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800D1FFC: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x800D2000: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x800D2004: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800D2008: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800D200C: sb          $t4, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r12;
    // 0x800D2010: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x800D2014: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x800D2018: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800D201C: jr          $ra
    // 0x800D2020: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x800D2020: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void __resetPerfChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2024: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x800D2028: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x800D202C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x800D2030: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800D2034: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x800D2038: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x800D203C: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x800D2040: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800D2044: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800D2048: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x800D204C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x800D2050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D2058: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800D205C: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x800D2060: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x800D2064: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x800D2068: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800D206C: sb          $t3, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r11;
    // 0x800D2070: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800D2074: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800D2078: sb          $t6, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r14;
    // 0x800D207C: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x800D2080: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800D2084: sb          $zero, 0xB($t1)
    MEM_B(0XB, ctx->r9) = 0;
    // 0x800D2088: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x800D208C: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x800D2090: sh          $t0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r8;
    // 0x800D2094: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x800D2098: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x800D209C: jr          $ra
    // 0x800D20A0: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    return;
    // 0x800D20A0: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
;}
RECOMP_FUNC void __initFromBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D20A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D20A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D20AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D20B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D20B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D20B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D20BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D20C0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D20C4: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
L_800D20C8:
    // 0x800D20C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D20CC: beql        $s1, $zero, L_800D20C8
    if (ctx->r17 == 0) {
        // 0x800D20D0: lw          $s1, 0xC($v0)
        ctx->r17 = MEM_W(ctx->r2, 0XC);
            goto L_800D20C8;
    }
    goto skip_0;
    // 0x800D20D0: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x800D20D4: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x800D20D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D20DC: blez        $t6, L_800D2110
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D20E0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D2110;
    }
    // 0x800D20E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D20E4:
    // 0x800D20E4: jal         0x800D2024
    // 0x800D20E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x800D20E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800D20EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D20F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D20F4: jal         0x800D1FD0
    // 0x800D20F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    __setInstChanState(rdram, ctx);
        goto after_1;
    // 0x800D20F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800D20FC: lbu         $t7, 0x34($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X34);
    // 0x800D2100: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D2104: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D2108: bnel        $at, $zero, L_800D20E4
    if (ctx->r1 != 0) {
        // 0x800D210C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D20E4;
    }
    goto skip_1;
    // 0x800D210C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_800D2110:
    // 0x800D2110: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800D2114: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D2118: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800D211C: beql        $t9, $zero, L_800D2144
    if (ctx->r25 == 0) {
        // 0x800D2120: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2144;
    }
    goto skip_2;
    // 0x800D2120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800D2124: jal         0x800D2024
    // 0x800D2128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_2;
    // 0x800D2128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800D212C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D2130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D2134: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x800D2138: jal         0x800D1FD0
    // 0x800D213C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    __setInstChanState(rdram, ctx);
        goto after_3;
    // 0x800D213C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    after_3:
    // 0x800D2140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2144:
    // 0x800D2144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D2148: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D214C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D2150: jr          $ra
    // 0x800D2154: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D2154: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800D2158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2158: jr          $ra
    // 0x800D215C: nop

    return;
    // 0x800D215C: nop

;}
RECOMP_FUNC void __vsDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2160: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x800D2164: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800D2168: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x800D216C: bltz        $v1, L_800D217C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800D2170: nop

            goto L_800D217C;
    }
    // 0x800D2170: nop

    // 0x800D2174: jr          $ra
    // 0x800D2178: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D2178: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D217C:
    // 0x800D217C: jr          $ra
    // 0x800D2180: nop

    return;
    // 0x800D2180: nop

;}
RECOMP_FUNC void __vsVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2184: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x800D2188: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x800D218C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x800D2190: lbu         $t2, 0x31($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X31);
    // 0x800D2194: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2198: lw          $t1, 0x60($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X60);
    // 0x800D219C: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800D21A0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800D21A4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D21A8: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x800D21AC: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x800D21B0: mflo        $t8
    ctx->r24 = lo;
    // 0x800D21B4: nop

    // 0x800D21B8: nop

    // 0x800D21BC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D21C0: lh          $t9, 0x32($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X32);
    // 0x800D21C4: mflo        $v1
    ctx->r3 = lo;
    // 0x800D21C8: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x800D21CC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800D21D0: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D21D4: mflo        $t8
    ctx->r24 = lo;
    // 0x800D21D8: nop

    // 0x800D21DC: nop

    // 0x800D21E0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D21E4: mflo        $a2
    ctx->r6 = lo;
    // 0x800D21E8: sra         $t0, $a2, 14
    ctx->r8 = S32(SIGNED(ctx->r6) >> 14);
    // 0x800D21EC: nop

    // 0x800D21F0: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D21F4: mflo        $v1
    ctx->r3 = lo;
    // 0x800D21F8: srl         $t2, $v1, 15
    ctx->r10 = S32(U32(ctx->r3) >> 15);
    // 0x800D21FC: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x800D2200: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D2204: jr          $ra
    // 0x800D2208: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800D2208: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void __seqpReleaseVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D220C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D2210: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D2214: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D2218: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D221C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D2220: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D2224: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D2228: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D222C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D2230: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800D2234: lw          $s6, 0x10($a1)
    ctx->r22 = MEM_W(ctx->r5, 0X10);
    // 0x800D2238: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D223C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800D2240: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x800D2244: bnel        $t6, $zero, L_800D22B0
    if (ctx->r14 != 0) {
        // 0x800D2248: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_800D22B0;
    }
    goto skip_0;
    // 0x800D2248: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_0:
    // 0x800D224C: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x800D2250: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x800D2254: beql        $s0, $zero, L_800D22B0
    if (ctx->r16 == 0) {
        // 0x800D2258: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_800D22B0;
    }
    goto skip_1;
    // 0x800D2258: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_1:
L_800D225C:
    // 0x800D225C: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x800D2260: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D2264: bne         $s3, $t7, L_800D22A4
    if (ctx->r19 != ctx->r15) {
        // 0x800D2268: nop

            goto L_800D22A4;
    }
    // 0x800D2268: nop

    // 0x800D226C: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800D2270: bne         $s5, $t8, L_800D22A4
    if (ctx->r21 != ctx->r24) {
        // 0x800D2274: nop

            goto L_800D22A4;
    }
    // 0x800D2274: nop

    // 0x800D2278: beq         $s1, $zero, L_800D2290
    if (ctx->r17 == 0) {
        // 0x800D227C: addiu       $s2, $s4, 0x48
        ctx->r18 = ADD32(ctx->r20, 0X48);
            goto L_800D2290;
    }
    // 0x800D227C: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    // 0x800D2280: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800D2284: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x800D2288: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800D228C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_800D2290:
    // 0x800D2290: jal         0x800C7890
    // 0x800D2294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800D2294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D2298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D229C: jal         0x800C78C0
    // 0x800D22A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x800D22A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_800D22A4:
    // 0x800D22A4: bne         $s1, $zero, L_800D225C
    if (ctx->r17 != 0) {
        // 0x800D22A8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D225C;
    }
    // 0x800D22A8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D22AC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_800D22B0:
    // 0x800D22B0: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x800D22B4: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x800D22B8: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x800D22BC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800D22C0: lw          $t3, 0x1C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C);
    // 0x800D22C4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D22C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D22CC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800D22D0: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x800D22D4: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x800D22D8: jal         0x800D69C0
    // 0x800D22DC: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    alSynSetPriority(rdram, ctx);
        goto after_2;
    // 0x800D22DC: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    after_2:
    // 0x800D22E0: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x800D22E4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D22E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D22EC: jal         0x800D3DD0
    // 0x800D22F0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    alSynSetVol(rdram, ctx);
        goto after_3;
    // 0x800D22F0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x800D22F4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800D22F8: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x800D22FC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800D2300: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D2304: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800D2308: jal         0x800D3A2C
    // 0x800D230C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x800D230C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x800D2310: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D2314: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D2318: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D231C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D2320: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D2324: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D2328: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D232C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D2330: jr          $ra
    // 0x800D2334: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D2334: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void __voiceNeedsNoteKill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D233C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2340: lw          $a3, 0x50($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X50);
    // 0x800D2344: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D2348: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800D234C: beq         $a3, $zero, L_800D23CC
    if (ctx->r7 == 0) {
        // 0x800D2350: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800D23CC;
    }
    // 0x800D2350: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D2354: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800D2358:
    // 0x800D2358: lh          $t6, 0xC($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XC);
    // 0x800D235C: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x800D2360: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800D2364: bne         $a0, $t6, L_800D23C4
    if (ctx->r4 != ctx->r14) {
        // 0x800D2368: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_800D23C4;
    }
    // 0x800D2368: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x800D236C: lw          $t7, 0x10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X10);
    // 0x800D2370: bne         $a1, $t7, L_800D23C4
    if (ctx->r5 != ctx->r15) {
        // 0x800D2374: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800D23C4;
    }
    // 0x800D2374: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D2378: beq         $at, $zero, L_800D23BC
    if (ctx->r1 == 0) {
        // 0x800D237C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800D23BC;
    }
    // 0x800D237C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D2380: beql        $v0, $zero, L_800D2398
    if (ctx->r2 == 0) {
        // 0x800D2384: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800D2398;
    }
    goto skip_0;
    // 0x800D2384: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    skip_0:
    // 0x800D2388: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800D238C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800D2390: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800D2394: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
L_800D2398:
    // 0x800D2398: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    // 0x800D239C: jal         0x800C7890
    // 0x800D23A0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800D23A0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_0:
    // 0x800D23A4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800D23A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800D23AC: jal         0x800C78C0
    // 0x800D23B0: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800D23B0: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    after_1:
    // 0x800D23B4: b           L_800D23CC
    // 0x800D23B8: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
        goto L_800D23CC;
    // 0x800D23B8: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
L_800D23BC:
    // 0x800D23BC: b           L_800D23CC
    // 0x800D23C0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_800D23CC;
    // 0x800D23C0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800D23C4:
    // 0x800D23C4: bne         $v0, $zero, L_800D2358
    if (ctx->r2 != 0) {
        // 0x800D23C8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800D2358;
    }
    // 0x800D23C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800D23CC:
    // 0x800D23CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D23D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D23D4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D23D8: jr          $ra
    // 0x800D23DC: nop

    return;
    // 0x800D23DC: nop

;}
RECOMP_FUNC void __unmapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D23E0: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800D23E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D23E8: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
    // 0x800D23EC: beq         $v1, $zero, L_800D2448
    if (ctx->r3 == 0) {
        // 0x800D23F0: nop

            goto L_800D2448;
    }
    // 0x800D23F0: nop

L_800D23F4:
    // 0x800D23F4: bnel        $v1, $a2, L_800D243C
    if (ctx->r3 != ctx->r6) {
        // 0x800D23F8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800D243C;
    }
    goto skip_0;
    // 0x800D23F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x800D23FC: beql        $v0, $zero, L_800D2414
    if (ctx->r2 == 0) {
        // 0x800D2400: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_800D2414;
    }
    goto skip_1;
    // 0x800D2400: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800D2404: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D2408: b           L_800D2418
    // 0x800D240C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_800D2418;
    // 0x800D240C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D2410: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_800D2414:
    // 0x800D2414: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
L_800D2418:
    // 0x800D2418: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x800D241C: bnel        $v1, $t8, L_800D242C
    if (ctx->r3 != ctx->r24) {
        // 0x800D2420: lw          $t9, 0x6C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X6C);
            goto L_800D242C;
    }
    goto skip_2;
    // 0x800D2420: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    skip_2:
    // 0x800D2424: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
    // 0x800D2428: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
L_800D242C:
    // 0x800D242C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D2430: jr          $ra
    // 0x800D2434: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    return;
    // 0x800D2434: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x800D2438: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D243C:
    // 0x800D243C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800D2440: bne         $v1, $zero, L_800D23F4
    if (ctx->r3 != 0) {
        // 0x800D2444: nop

            goto L_800D23F4;
    }
    // 0x800D2444: nop

L_800D2448:
    // 0x800D2448: jr          $ra
    // 0x800D244C: nop

    return;
    // 0x800D244C: nop

;}
RECOMP_FUNC void __postNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2450: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D2454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2458: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800D245C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D2460: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D2464: bne         $t6, $at, L_800D251C
    if (ctx->r14 != ctx->r1) {
        // 0x800D2468: lw          $a2, 0x18($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X18);
            goto L_800D251C;
    }
    // 0x800D2468: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x800D246C: beq         $a2, $zero, L_800D251C
    if (ctx->r6 == 0) {
        // 0x800D2470: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800D251C;
    }
    // 0x800D2470: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D2474: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800D2478: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D247C: jal         0x800D6810
    // 0x800D2480: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    __alSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x800D2480: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D2484: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800D2488: beq         $v0, $zero, L_800D251C
    if (ctx->r2 == 0) {
        // 0x800D248C: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_800D251C;
    }
    // 0x800D248C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D2490: lw          $t7, 0x84($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X84);
    // 0x800D2494: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D2498: beql        $t7, $zero, L_800D24FC
    if (ctx->r15 == 0) {
        // 0x800D249C: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_800D24FC;
    }
    goto skip_0;
    // 0x800D249C: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_0:
    // 0x800D24A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D24A4: jal         0x800D63D8
    // 0x800D24A8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    alSeqGetTicks(rdram, ctx);
        goto after_1;
    // 0x800D24A8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x800D24AC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D24B0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800D24B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800D24B8: lw          $t0, 0x80($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X80);
    // 0x800D24BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800D24C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D24C4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800D24C8: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D24CC: bnel        $at, $zero, L_800D24FC
    if (ctx->r1 != 0) {
        // 0x800D24D0: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_800D24FC;
    }
    goto skip_1;
    // 0x800D24D0: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_1:
    // 0x800D24D4: lw          $a1, 0x7C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X7C);
    // 0x800D24D8: jal         0x800D63BC
    // 0x800D24DC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    alSeqSetLoc(rdram, ctx);
        goto after_2;
    // 0x800D24DC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x800D24E0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D24E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D24E8: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x800D24EC: beq         $v0, $at, L_800D24F8
    if (ctx->r2 == ctx->r1) {
        // 0x800D24F0: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800D24F8;
    }
    // 0x800D24F0: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800D24F4: sw          $t2, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r10;
L_800D24F8:
    // 0x800D24F8: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
L_800D24FC:
    // 0x800D24FC: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    // 0x800D2500: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800D2504: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x800D2508: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800D250C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2510: mflo        $a2
    ctx->r6 = lo;
    // 0x800D2514: jal         0x800D3A2C
    // 0x800D2518: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x800D2518: nop

    after_3:
L_800D251C:
    // 0x800D251C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800D2524: jr          $ra
    // 0x800D2528: nop

    return;
    // 0x800D2528: nop

;}
RECOMP_FUNC void func_800D252C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D252C: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x800D2530: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800D2534: bne         $t6, $at, L_800D259C
    if (ctx->r14 != ctx->r1) {
        // 0x800D2538: nop

            goto L_800D259C;
    }
    // 0x800D2538: nop

    // 0x800D253C: lbu         $t7, 0x9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9);
    // 0x800D2540: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800D2544: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800D2548: bne         $t7, $at, L_800D259C
    if (ctx->r15 != ctx->r1) {
        // 0x800D254C: nop

            goto L_800D259C;
    }
    // 0x800D254C: nop

    // 0x800D2550: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x800D2554: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x800D2558: lw          $a2, 0x18($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X18);
    // 0x800D255C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800D2560: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x800D2564: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D2568: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800D256C: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800D2570: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800D2574: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800D2578: beq         $a2, $zero, L_800D2598
    if (ctx->r6 == 0) {
        // 0x800D257C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800D2598;
    }
    // 0x800D257C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D2580: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800D2584: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D2588: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D258C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800D2590: jr          $ra
    // 0x800D2594: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    return;
    // 0x800D2594: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
L_800D2598:
    // 0x800D2598: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
L_800D259C:
    // 0x800D259C: jr          $ra
    // 0x800D25A0: nop

    return;
    // 0x800D25A0: nop

;}
RECOMP_FUNC void __vsPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D25A4: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x800D25A8: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x800D25AC: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x800D25B0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800D25B4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800D25B8: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x800D25BC: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x800D25C0: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x800D25C4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800D25C8: bgtzl       $v1, L_800D25D8
    if (SIGNED(ctx->r3) > 0) {
        // 0x800D25CC: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800D25D8;
    }
    goto skip_0;
    // 0x800D25CC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_0:
    // 0x800D25D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D25D4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800D25D8:
    // 0x800D25D8: bne         $at, $zero, L_800D25E4
    if (ctx->r1 != 0) {
        // 0x800D25DC: nop

            goto L_800D25E4;
    }
    // 0x800D25DC: nop

    // 0x800D25E0: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_800D25E4:
    // 0x800D25E4: jr          $ra
    // 0x800D25E8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x800D25E8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void __lookupVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D25EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D25F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800D25F4: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800D25F8: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x800D25FC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800D2600: beq         $v1, $zero, L_800D2654
    if (ctx->r3 == 0) {
        // 0x800D2604: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800D2654;
    }
    // 0x800D2604: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D2608: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800D260C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800D2610: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D2614: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
L_800D2618:
    // 0x800D2618: bnel        $v0, $t8, L_800D264C
    if (ctx->r2 != ctx->r24) {
        // 0x800D261C: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800D264C;
    }
    goto skip_0;
    // 0x800D261C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800D2620: lbu         $t9, 0x31($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X31);
    // 0x800D2624: bnel        $a2, $t9, L_800D264C
    if (ctx->r6 != ctx->r25) {
        // 0x800D2628: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800D264C;
    }
    goto skip_1;
    // 0x800D2628: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800D262C: lbu         $a0, 0x35($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X35);
    // 0x800D2630: beql        $a1, $a0, L_800D264C
    if (ctx->r5 == ctx->r4) {
        // 0x800D2634: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800D264C;
    }
    goto skip_2;
    // 0x800D2634: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x800D2638: beql        $a3, $a0, L_800D264C
    if (ctx->r7 == ctx->r4) {
        // 0x800D263C: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800D264C;
    }
    goto skip_3;
    // 0x800D263C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800D2640: jr          $ra
    // 0x800D2644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D2644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D2648: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800D264C:
    // 0x800D264C: bnel        $v1, $zero, L_800D2618
    if (ctx->r3 != 0) {
        // 0x800D2650: lbu         $t8, 0x32($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X32);
            goto L_800D2618;
    }
    goto skip_4;
    // 0x800D2650: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
    skip_4:
L_800D2654:
    // 0x800D2654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D2658: jr          $ra
    // 0x800D265C: nop

    return;
    // 0x800D265C: nop

;}
RECOMP_FUNC void __mapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2660: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D2664: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800D2668: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800D266C: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x800D2670: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D2674: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x800D2678: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x800D267C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800D2680: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800D2684: beq         $v1, $zero, L_800D26C8
    if (ctx->r3 == 0) {
        // 0x800D2688: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800D26C8;
    }
    // 0x800D2688: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800D268C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800D2690: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x800D2694: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800D2698: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x800D269C: bnel        $t0, $zero, L_800D26B0
    if (ctx->r8 != 0) {
        // 0x800D26A0: lw          $t1, 0x68($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X68);
            goto L_800D26B0;
    }
    goto skip_0;
    // 0x800D26A0: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    skip_0:
    // 0x800D26A4: b           L_800D26B4
    // 0x800D26A8: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
        goto L_800D26B4;
    // 0x800D26A8: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
    // 0x800D26AC: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
L_800D26B0:
    // 0x800D26B0: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
L_800D26B4:
    // 0x800D26B4: sw          $v1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r3;
    // 0x800D26B8: sb          $a3, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r7;
    // 0x800D26BC: sb          $a1, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r5;
    // 0x800D26C0: sb          $a2, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r6;
    // 0x800D26C4: sw          $v1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r3;
L_800D26C8:
    // 0x800D26C8: jr          $ra
    // 0x800D26CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D26CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void __lookupSoundQuick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D26D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D26D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800D26D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800D26DC: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x800D26E0: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x800D26E4: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800D26E8: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x800D26EC: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800D26F0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D26F4: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x800D26F8: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x800D26FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D2700: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x800D2704: blez        $t0, L_800D27C0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800D2708: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_800D27C0;
    }
    // 0x800D2708: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_800D270C:
    // 0x800D270C: bgez        $a1, L_800D271C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800D2710: sra         $t5, $a1, 1
        ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800D271C;
    }
    // 0x800D2710: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800D2714: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800D2718: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800D271C:
    // 0x800D271C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800D2720: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800D2724: lw          $a3, 0xC($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC);
    // 0x800D2728: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800D272C: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x800D2730: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x800D2734: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800D2738: bnel        $at, $zero, L_800D2780
    if (ctx->r1 != 0) {
        // 0x800D273C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D2780;
    }
    goto skip_0;
    // 0x800D273C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_0:
    // 0x800D2740: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x800D2744: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D2748: bnel        $at, $zero, L_800D2780
    if (ctx->r1 != 0) {
        // 0x800D274C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D2780;
    }
    goto skip_1;
    // 0x800D274C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_1:
    // 0x800D2750: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800D2754: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800D2758: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D275C: bnel        $at, $zero, L_800D2780
    if (ctx->r1 != 0) {
        // 0x800D2760: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D2780;
    }
    goto skip_2;
    // 0x800D2760: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_2:
    // 0x800D2764: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x800D2768: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D276C: bnel        $at, $zero, L_800D2780
    if (ctx->r1 != 0) {
        // 0x800D2770: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D2780;
    }
    goto skip_3;
    // 0x800D2770: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x800D2774: jr          $ra
    // 0x800D2778: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800D2778: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800D277C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_800D2780:
    // 0x800D2780: bne         $at, $zero, L_800D27A8
    if (ctx->r1 != 0) {
        // 0x800D2784: nop

            goto L_800D27A8;
    }
    // 0x800D2784: nop

    // 0x800D2788: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800D278C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800D2790: beql        $at, $zero, L_800D27B4
    if (ctx->r1 == 0) {
        // 0x800D2794: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_800D27B4;
    }
    goto skip_4;
    // 0x800D2794: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x800D2798: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x800D279C: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D27A0: bnel        $at, $zero, L_800D27B4
    if (ctx->r1 != 0) {
        // 0x800D27A4: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_800D27B4;
    }
    goto skip_5;
    // 0x800D27A4: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_5:
L_800D27A8:
    // 0x800D27A8: b           L_800D27B4
    // 0x800D27AC: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_800D27B4;
    // 0x800D27AC: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x800D27B0: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_800D27B4:
    // 0x800D27B4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D27B8: beql        $at, $zero, L_800D270C
    if (ctx->r1 == 0) {
        // 0x800D27BC: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_800D270C;
    }
    goto skip_6;
    // 0x800D27BC: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    skip_6:
L_800D27C0:
    // 0x800D27C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D27C4: jr          $ra
    // 0x800D27C8: nop

    return;
    // 0x800D27C8: nop

;}
RECOMP_FUNC void func_800D27CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D27CC: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800D27D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D27D4: lbu         $s6, 0x8($a0)
    ctx->r22 = MEM_BU(ctx->r4, 0X8);
    // 0x800D27D8: lbu         $s3, 0x9($a0)
    ctx->r19 = MEM_BU(ctx->r4, 0X9);
    // 0x800D27DC: lbu         $s4, 0xA($a0)
    ctx->r20 = MEM_BU(ctx->r4, 0XA);
    // 0x800D27E0: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x800D27E4: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x800D27E8: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x800D27EC: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x800D27F0: beq         $at, $zero, L_800D2FD4
    if (ctx->r1 == 0) {
        // 0x800D27F4: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_800D2FD4;
    }
    // 0x800D27F4: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x800D27F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D27FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D2800: addu        $at, $at, $t7
    gpr jr_addend_800D2808 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D2804: lw          $t7, 0x370($at)
    ctx->r15 = ADD32(ctx->r1, 0X370);
    // 0x800D2808: jr          $t7
    // 0x800D280C: nop

    switch (jr_addend_800D2808 >> 2) {
        case 0: goto L_800D2B64; break;
        case 1: goto L_800D2FD4; break;
        case 2: goto L_800D2FD4; break;
        case 3: goto L_800D2FD4; break;
        case 4: goto L_800D2FD4; break;
        case 5: goto L_800D2FD4; break;
        case 6: goto L_800D2FD4; break;
        case 7: goto L_800D2FD4; break;
        case 8: goto L_800D2FD4; break;
        case 9: goto L_800D2FD4; break;
        case 10: goto L_800D2FD4; break;
        case 11: goto L_800D2FD4; break;
        case 12: goto L_800D2FD4; break;
        case 13: goto L_800D2FD4; break;
        case 14: goto L_800D2FD4; break;
        case 15: goto L_800D2FD4; break;
        case 16: goto L_800D2810; break;
        case 17: goto L_800D2FD4; break;
        case 18: goto L_800D2FD4; break;
        case 19: goto L_800D2FD4; break;
        case 20: goto L_800D2FD4; break;
        case 21: goto L_800D2FD4; break;
        case 22: goto L_800D2FD4; break;
        case 23: goto L_800D2FD4; break;
        case 24: goto L_800D2FD4; break;
        case 25: goto L_800D2FD4; break;
        case 26: goto L_800D2FD4; break;
        case 27: goto L_800D2FD4; break;
        case 28: goto L_800D2FD4; break;
        case 29: goto L_800D2FD4; break;
        case 30: goto L_800D2FD4; break;
        case 31: goto L_800D2FD4; break;
        case 32: goto L_800D2BBC; break;
        case 33: goto L_800D2FD4; break;
        case 34: goto L_800D2FD4; break;
        case 35: goto L_800D2FD4; break;
        case 36: goto L_800D2FD4; break;
        case 37: goto L_800D2FD4; break;
        case 38: goto L_800D2FD4; break;
        case 39: goto L_800D2FD4; break;
        case 40: goto L_800D2FD4; break;
        case 41: goto L_800D2FD4; break;
        case 42: goto L_800D2FD4; break;
        case 43: goto L_800D2FD4; break;
        case 44: goto L_800D2FD4; break;
        case 45: goto L_800D2FD4; break;
        case 46: goto L_800D2FD4; break;
        case 47: goto L_800D2FD4; break;
        case 48: goto L_800D2C9C; break;
        case 49: goto L_800D2FD4; break;
        case 50: goto L_800D2FD4; break;
        case 51: goto L_800D2FD4; break;
        case 52: goto L_800D2FD4; break;
        case 53: goto L_800D2FD4; break;
        case 54: goto L_800D2FD4; break;
        case 55: goto L_800D2FD4; break;
        case 56: goto L_800D2FD4; break;
        case 57: goto L_800D2FD4; break;
        case 58: goto L_800D2FD4; break;
        case 59: goto L_800D2FD4; break;
        case 60: goto L_800D2FD4; break;
        case 61: goto L_800D2FD4; break;
        case 62: goto L_800D2FD4; break;
        case 63: goto L_800D2FD4; break;
        case 64: goto L_800D2F08; break;
        case 65: goto L_800D2FD4; break;
        case 66: goto L_800D2FD4; break;
        case 67: goto L_800D2FD4; break;
        case 68: goto L_800D2FD4; break;
        case 69: goto L_800D2FD4; break;
        case 70: goto L_800D2FD4; break;
        case 71: goto L_800D2FD4; break;
        case 72: goto L_800D2FD4; break;
        case 73: goto L_800D2FD4; break;
        case 74: goto L_800D2FD4; break;
        case 75: goto L_800D2FD4; break;
        case 76: goto L_800D2FD4; break;
        case 77: goto L_800D2FD4; break;
        case 78: goto L_800D2FD4; break;
        case 79: goto L_800D2FD4; break;
        case 80: goto L_800D2C24; break;
        case 81: goto L_800D2FD4; break;
        case 82: goto L_800D2FD4; break;
        case 83: goto L_800D2FD4; break;
        case 84: goto L_800D2FD4; break;
        case 85: goto L_800D2FD4; break;
        case 86: goto L_800D2FD4; break;
        case 87: goto L_800D2FD4; break;
        case 88: goto L_800D2FD4; break;
        case 89: goto L_800D2FD4; break;
        case 90: goto L_800D2FD4; break;
        case 91: goto L_800D2FD4; break;
        case 92: goto L_800D2FD4; break;
        case 93: goto L_800D2FD4; break;
        case 94: goto L_800D2FD4; break;
        case 95: goto L_800D2FD4; break;
        case 96: goto L_800D2F3C; break;
        default: switch_error(__func__, 0x800D2808, 0x800F0370);
    }
    // 0x800D280C: nop

L_800D2810:
    // 0x800D2810: beql        $s4, $zero, L_800D2B68
    if (ctx->r20 == 0) {
        // 0x800D2814: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D2B68;
    }
    goto skip_0;
    // 0x800D2814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x800D2818: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x800D281C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D2820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2824: bne         $t8, $at, L_800D2FD4
    if (ctx->r24 != ctx->r1) {
        // 0x800D2828: andi        $a1, $s3, 0xFF
        ctx->r5 = ctx->r19 & 0XFF;
            goto L_800D2FD4;
    }
    // 0x800D2828: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800D282C: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800D2830: jal         0x800D26D0
    // 0x800D2834: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    __lookupSoundQuick(rdram, ctx);
        goto after_0;
    // 0x800D2834: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    after_0:
    // 0x800D2838: beq         $v0, $zero, L_800D2FD4
    if (ctx->r2 == 0) {
        // 0x800D283C: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800D2FD4;
    }
    // 0x800D283C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800D2840: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800D2844: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800D2848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D284C: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800D2850: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x800D2854: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800D2858: sb          $zero, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = 0;
    // 0x800D285C: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800D2860: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800D2864: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800D2868: jal         0x800D2660
    // 0x800D286C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    __mapVoice(rdram, ctx);
        goto after_1;
    // 0x800D286C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    after_1:
    // 0x800D2870: beq         $v0, $zero, L_800D2FD4
    if (ctx->r2 == 0) {
        // 0x800D2874: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D2FD4;
    }
    // 0x800D2874: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D2878: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D287C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800D2880: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D2884: jal         0x800D3FE8
    // 0x800D2888: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    alSynAllocVoice(rdram, ctx);
        goto after_2;
    // 0x800D2888: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    after_2:
    // 0x800D288C: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x800D2890: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x800D2894: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x800D2898: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800D289C: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x800D28A0: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x800D28A4: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x800D28A8: bnel        $at, $zero, L_800D28BC
    if (ctx->r1 != 0) {
        // 0x800D28AC: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_800D28BC;
    }
    goto skip_1;
    // 0x800D28AC: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
    // 0x800D28B0: b           L_800D28BC
    // 0x800D28B4: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800D28BC;
    // 0x800D28B4: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x800D28B8: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800D28BC:
    // 0x800D28BC: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x800D28C0: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800D28C4: lb          $t6, 0x5($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5);
    // 0x800D28C8: subu        $t8, $s3, $t7
    ctx->r24 = SUB32(ctx->r19, ctx->r15);
    // 0x800D28CC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800D28D0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800D28D4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800D28D8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800D28DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D28E0: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x800D28E4: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800D28E8: jal         0x800CADC0
    // 0x800D28EC: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x800D28EC: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x800D28F0: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800D28F4: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800D28F8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800D28FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D2900: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x800D2904: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x800D2908: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800D290C: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x800D2910: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800D2914: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x800D2918: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800D291C: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x800D2920: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x800D2924: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x800D2928: lw          $s2, 0x0($t7)
    ctx->r18 = MEM_W(ctx->r15, 0X0);
    // 0x800D292C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x800D2930: lbu         $a2, 0x4($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X4);
    // 0x800D2934: beql        $a2, $zero, L_800D29A0
    if (ctx->r6 == 0) {
        // 0x800D2938: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800D29A0;
    }
    goto skip_2;
    // 0x800D2938: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x800D293C: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x800D2940: beql        $v0, $zero, L_800D29A0
    if (ctx->r2 == 0) {
        // 0x800D2944: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800D29A0;
    }
    goto skip_3;
    // 0x800D2944: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
    // 0x800D2948: lbu         $t9, 0x6($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X6);
    // 0x800D294C: lbu         $a3, 0x5($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X5);
    // 0x800D2950: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800D2954: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D2958: lbu         $t6, 0x7($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X7);
    // 0x800D295C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800D2960: jalr        $v0
    // 0x800D2964: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800D2964: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x800D2968: beq         $v0, $zero, L_800D299C
    if (ctx->r2 == 0) {
        // 0x800D296C: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_800D299C;
    }
    // 0x800D296C: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800D2970: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800D2974: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x800D2978: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x800D297C: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    // 0x800D2980: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800D2984: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D2988: jal         0x800D3A2C
    // 0x800D298C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x800D298C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_5:
    // 0x800D2990: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800D2994: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x800D2998: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800D299C:
    // 0x800D299C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_800D29A0:
    // 0x800D29A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D29A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D29A8: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800D29AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800D29B0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800D29B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D29B8: nop

    // 0x800D29BC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800D29C0: beql        $t7, $zero, L_800D2A10
    if (ctx->r15 == 0) {
        // 0x800D29C4: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_800D2A10;
    }
    goto skip_4;
    // 0x800D29C4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x800D29C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D29CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D29D0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800D29D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D29D8: nop

    // 0x800D29DC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800D29E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D29E4: nop

    // 0x800D29E8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800D29EC: bne         $t7, $zero, L_800D2A04
    if (ctx->r15 != 0) {
        // 0x800D29F0: nop

            goto L_800D2A04;
    }
    // 0x800D29F0: nop

    // 0x800D29F4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800D29F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D29FC: b           L_800D2A1C
    // 0x800D2A00: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800D2A1C;
    // 0x800D2A00: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800D2A04:
    // 0x800D2A04: b           L_800D2A1C
    // 0x800D2A08: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800D2A1C;
    // 0x800D2A08: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D2A0C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_800D2A10:
    // 0x800D2A10: nop

    // 0x800D2A14: bltz        $t7, L_800D2A04
    if (SIGNED(ctx->r15) < 0) {
        // 0x800D2A18: nop

            goto L_800D2A04;
    }
    // 0x800D2A18: nop

L_800D2A1C:
    // 0x800D2A1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2A20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D2A24: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x800D2A28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800D2A2C: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x800D2A30: lbu         $a2, 0x8($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X8);
    // 0x800D2A34: addiu       $s5, $s1, 0x48
    ctx->r21 = ADD32(ctx->r17, 0X48);
    // 0x800D2A38: beql        $a2, $zero, L_800D2AA8
    if (ctx->r6 == 0) {
        // 0x800D2A3C: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_800D2AA8;
    }
    goto skip_5;
    // 0x800D2A3C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_5:
    // 0x800D2A40: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x800D2A44: beql        $v0, $zero, L_800D2AA8
    if (ctx->r2 == 0) {
        // 0x800D2A48: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_800D2AA8;
    }
    goto skip_6;
    // 0x800D2A48: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_6:
    // 0x800D2A4C: lbu         $t9, 0xA($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XA);
    // 0x800D2A50: lbu         $a3, 0x9($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X9);
    // 0x800D2A54: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800D2A58: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D2A5C: lbu         $t6, 0xB($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0XB);
    // 0x800D2A60: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800D2A64: jalr        $v0
    // 0x800D2A68: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800D2A68: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x800D2A6C: beq         $v0, $zero, L_800D2AA4
    if (ctx->r2 == 0) {
        // 0x800D2A70: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_800D2AA4;
    }
    // 0x800D2A70: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x800D2A74: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800D2A78: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x800D2A7C: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x800D2A80: sb          $s6, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r22;
    // 0x800D2A84: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2A88: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800D2A8C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D2A90: jal         0x800D3A2C
    // 0x800D2A94: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x800D2A94: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_7:
    // 0x800D2A98: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800D2A9C: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x800D2AA0: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800D2AA4:
    // 0x800D2AA4: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
L_800D2AA8:
    // 0x800D2AA8: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D2AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2AB0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800D2AB4: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x800D2AB8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D2ABC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D2AC0: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x800D2AC4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800D2AC8: lbu         $s2, 0xA($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0XA);
    // 0x800D2ACC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D2AD0: nop

    // 0x800D2AD4: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D2AD8: jal         0x800D25A4
    // 0x800D2ADC: nop

    __vsPan(rdram, ctx);
        goto after_8;
    // 0x800D2ADC: nop

    after_8:
    // 0x800D2AE0: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x800D2AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2AE8: jal         0x800D2184
    // 0x800D2AEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __vsVol(rdram, ctx);
        goto after_9;
    // 0x800D2AEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x800D2AF0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800D2AF4: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2AF8: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x800D2AFC: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x800D2B00: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800D2B04: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800D2B08: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800D2B0C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800D2B10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800D2B14: jal         0x800D4130
    // 0x800D2B18: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    alSynStartVoiceParams(rdram, ctx);
        goto after_10;
    // 0x800D2B18: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
    // 0x800D2B1C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800D2B20: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800D2B24: sh          $t9, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r25;
    // 0x800D2B28: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x800D2B2C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800D2B30: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2B34: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800D2B38: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x800D2B3C: sb          $t7, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r15;
    // 0x800D2B40: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800D2B44: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800D2B48: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x800D2B4C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800D2B50: lw          $s3, 0x0($t8)
    ctx->r19 = MEM_W(ctx->r24, 0X0);
    // 0x800D2B54: jal         0x800D3A2C
    // 0x800D2B58: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_11;
    // 0x800D2B58: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_11:
    // 0x800D2B5C: b           L_800D2FD8
    // 0x800D2B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2B64:
    // 0x800D2B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D2B68:
    // 0x800D2B68: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800D2B6C: jal         0x800D25EC
    // 0x800D2B70: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_12;
    // 0x800D2B70: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_12:
    // 0x800D2B74: beq         $v0, $zero, L_800D2FD4
    if (ctx->r2 == 0) {
        // 0x800D2B78: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D2FD4;
    }
    // 0x800D2B78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D2B7C: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x800D2B80: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800D2B84: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800D2B88: bne         $s6, $t7, L_800D2B98
    if (ctx->r22 != ctx->r15) {
        // 0x800D2B8C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D2B98;
    }
    // 0x800D2B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2B90: b           L_800D2FD4
    // 0x800D2B94: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_800D2FD4;
    // 0x800D2B94: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_800D2B98:
    // 0x800D2B98: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800D2B9C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800D2BA0: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800D2BA4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800D2BA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2BAC: jal         0x800D220C
    // 0x800D2BB0: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    __seqpReleaseVoice(rdram, ctx);
        goto after_13;
    // 0x800D2BB0: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_13:
    // 0x800D2BB4: b           L_800D2FD8
    // 0x800D2BB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2BB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2BBC:
    // 0x800D2BBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2BC0: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800D2BC4: jal         0x800D25EC
    // 0x800D2BC8: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_14;
    // 0x800D2BC8: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_14:
    // 0x800D2BCC: beq         $v0, $zero, L_800D2FD4
    if (ctx->r2 == 0) {
        // 0x800D2BD0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D2FD4;
    }
    // 0x800D2BD0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D2BD4: sb          $s4, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r20;
    // 0x800D2BD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2BDC: jal         0x800D2184
    // 0x800D2BE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __vsVol(rdram, ctx);
        goto after_15;
    // 0x800D2BE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x800D2BE4: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800D2BE8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800D2BEC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D2BF0: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D2BF4: subu        $a0, $t9, $v1
    ctx->r4 = SUB32(ctx->r25, ctx->r3);
    // 0x800D2BF8: bltz        $a0, L_800D2C08
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D2BFC: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_800D2C08;
    }
    // 0x800D2BFC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800D2C00: b           L_800D2C0C
    // 0x800D2C04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D2C0C;
    // 0x800D2C04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D2C08:
    // 0x800D2C08: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D2C0C:
    // 0x800D2C0C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2C10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2C14: jal         0x800D3DD0
    // 0x800D2C18: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_16;
    // 0x800D2C18: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_16:
    // 0x800D2C1C: b           L_800D2FD8
    // 0x800D2C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2C24:
    // 0x800D2C24: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2C28: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2C2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_7;
    // 0x800D2C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x800D2C30: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2C34: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800D2C38:
    // 0x800D2C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2C3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D2C40: bnel        $s2, $t6, L_800D2C8C
    if (ctx->r18 != ctx->r14) {
        // 0x800D2C44: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2C8C;
    }
    goto skip_8;
    // 0x800D2C44: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x800D2C48: jal         0x800D2184
    // 0x800D2C4C: sb          $s3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r19;
    __vsVol(rdram, ctx);
        goto after_17;
    // 0x800D2C4C: sb          $s3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r19;
    after_17:
    // 0x800D2C50: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800D2C54: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D2C58: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D2C5C: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D2C60: subu        $a0, $t7, $v1
    ctx->r4 = SUB32(ctx->r15, ctx->r3);
    // 0x800D2C64: bltz        $a0, L_800D2C74
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D2C68: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800D2C74;
    }
    // 0x800D2C68: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800D2C6C: b           L_800D2C78
    // 0x800D2C70: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D2C78;
    // 0x800D2C70: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D2C74:
    // 0x800D2C74: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D2C78:
    // 0x800D2C78: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2C7C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2C80: jal         0x800D3DD0
    // 0x800D2C84: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_18;
    // 0x800D2C84: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
    // 0x800D2C88: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2C8C:
    // 0x800D2C8C: bnel        $s0, $zero, L_800D2C38
    if (ctx->r16 != 0) {
        // 0x800D2C90: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2C38;
    }
    goto skip_9;
    // 0x800D2C90: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_9:
    // 0x800D2C94: b           L_800D2FD8
    // 0x800D2C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2C9C:
    // 0x800D2C9C: slti        $at, $s3, 0x41
    ctx->r1 = SIGNED(ctx->r19) < 0X41 ? 1 : 0;
    // 0x800D2CA0: bne         $at, $zero, L_800D2CC4
    if (ctx->r1 != 0) {
        // 0x800D2CA4: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_800D2CC4;
    }
    // 0x800D2CA4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800D2CA8: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800D2CAC: beq         $v0, $at, L_800D2EB8
    if (ctx->r2 == ctx->r1) {
        // 0x800D2CB0: addiu       $at, $zero, 0x5D
        ctx->r1 = ADD32(0, 0X5D);
            goto L_800D2EB8;
    }
    // 0x800D2CB0: addiu       $at, $zero, 0x5D
    ctx->r1 = ADD32(0, 0X5D);
    // 0x800D2CB4: beql        $v0, $at, L_800D2FD8
    if (ctx->r2 == ctx->r1) {
        // 0x800D2CB8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_10;
    // 0x800D2CB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x800D2CBC: b           L_800D2FD8
    // 0x800D2CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2CC4:
    // 0x800D2CC4: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x800D2CC8: bne         $at, $zero, L_800D2CE4
    if (ctx->r1 != 0) {
        // 0x800D2CCC: addiu       $t9, $v0, -0x7
        ctx->r25 = ADD32(ctx->r2, -0X7);
            goto L_800D2CE4;
    }
    // 0x800D2CCC: addiu       $t9, $v0, -0x7
    ctx->r25 = ADD32(ctx->r2, -0X7);
    // 0x800D2CD0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800D2CD4: beql        $v0, $at, L_800D2E0C
    if (ctx->r2 == ctx->r1) {
        // 0x800D2CD8: lw          $t7, 0x60($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X60);
            goto L_800D2E0C;
    }
    goto skip_11;
    // 0x800D2CD8: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    skip_11:
    // 0x800D2CDC: b           L_800D2FD8
    // 0x800D2CE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2CE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2CE4:
    // 0x800D2CE4: sltiu       $at, $t9, 0x15
    ctx->r1 = ctx->r25 < 0X15 ? 1 : 0;
    // 0x800D2CE8: beq         $at, $zero, L_800D2FD4
    if (ctx->r1 == 0) {
        // 0x800D2CEC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800D2FD4;
    }
    // 0x800D2CEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D2CF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D2CF4: addu        $at, $at, $t9
    gpr jr_addend_800D2CFC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D2CF8: lw          $t9, 0x4F4($at)
    ctx->r25 = ADD32(ctx->r1, 0X4F4);
    // 0x800D2CFC: jr          $t9
    // 0x800D2D00: nop

    switch (jr_addend_800D2CFC >> 2) {
        case 0: goto L_800D2D60; break;
        case 1: goto L_800D2FD4; break;
        case 2: goto L_800D2FD4; break;
        case 3: goto L_800D2D04; break;
        case 4: goto L_800D2FD4; break;
        case 5: goto L_800D2FD4; break;
        case 6: goto L_800D2FD4; break;
        case 7: goto L_800D2FD4; break;
        case 8: goto L_800D2FD4; break;
        case 9: goto L_800D2DF4; break;
        case 10: goto L_800D2FD4; break;
        case 11: goto L_800D2FD4; break;
        case 12: goto L_800D2FD4; break;
        case 13: goto L_800D2FD4; break;
        case 14: goto L_800D2FD4; break;
        case 15: goto L_800D2FD4; break;
        case 16: goto L_800D2FD4; break;
        case 17: goto L_800D2FD4; break;
        case 18: goto L_800D2FD4; break;
        case 19: goto L_800D2FD4; break;
        case 20: goto L_800D2FD4; break;
        default: switch_error(__func__, 0x800D2CFC, 0x800F04F4);
    }
    // 0x800D2D00: nop

L_800D2D04:
    // 0x800D2D04: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x800D2D08: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x800D2D0C: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800D2D10: sb          $s4, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r20;
    // 0x800D2D14: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2D18: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2D1C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_12;
    // 0x800D2D1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x800D2D20: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2D24: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800D2D28:
    // 0x800D2D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2D2C: bnel        $s2, $t9, L_800D2D50
    if (ctx->r18 != ctx->r25) {
        // 0x800D2D30: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2D50;
    }
    goto skip_13;
    // 0x800D2D30: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x800D2D34: jal         0x800D25A4
    // 0x800D2D38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __vsPan(rdram, ctx);
        goto after_19;
    // 0x800D2D38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_19:
    // 0x800D2D3C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2D40: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2D44: jal         0x800D4220
    // 0x800D2D48: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_20;
    // 0x800D2D48: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_20:
    // 0x800D2D4C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2D50:
    // 0x800D2D50: bnel        $s0, $zero, L_800D2D28
    if (ctx->r16 != 0) {
        // 0x800D2D54: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2D28;
    }
    goto skip_14;
    // 0x800D2D54: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_14:
    // 0x800D2D58: b           L_800D2FD8
    // 0x800D2D5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2D5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2D60:
    // 0x800D2D60: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x800D2D64: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x800D2D68: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800D2D6C: sb          $s4, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r20;
    // 0x800D2D70: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2D74: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2D78: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_15;
    // 0x800D2D78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x800D2D7C: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2D80: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800D2D84: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800D2D88:
    // 0x800D2D88: bnel        $s2, $t9, L_800D2DE4
    if (ctx->r18 != ctx->r25) {
        // 0x800D2D8C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2DE4;
    }
    goto skip_16;
    // 0x800D2D8C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_16:
    // 0x800D2D90: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x800D2D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2D98: beql        $s3, $t6, L_800D2DE4
    if (ctx->r19 == ctx->r14) {
        // 0x800D2D9C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2DE4;
    }
    goto skip_17;
    // 0x800D2D9C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x800D2DA0: jal         0x800D2184
    // 0x800D2DA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __vsVol(rdram, ctx);
        goto after_21;
    // 0x800D2DA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_21:
    // 0x800D2DA8: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800D2DAC: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D2DB0: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D2DB4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D2DB8: subu        $a0, $t7, $v1
    ctx->r4 = SUB32(ctx->r15, ctx->r3);
    // 0x800D2DBC: bltz        $a0, L_800D2DCC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D2DC0: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800D2DCC;
    }
    // 0x800D2DC0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800D2DC4: b           L_800D2DD0
    // 0x800D2DC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D2DD0;
    // 0x800D2DC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D2DCC:
    // 0x800D2DCC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D2DD0:
    // 0x800D2DD0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2DD4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2DD8: jal         0x800D3DD0
    // 0x800D2DDC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_22;
    // 0x800D2DDC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_22:
    // 0x800D2DE0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2DE4:
    // 0x800D2DE4: bnel        $s0, $zero, L_800D2D88
    if (ctx->r16 != 0) {
        // 0x800D2DE8: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2D88;
    }
    goto skip_18;
    // 0x800D2DE8: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_18:
    // 0x800D2DEC: b           L_800D2FD8
    // 0x800D2DF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2DF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2DF4:
    // 0x800D2DF4: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800D2DF8: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800D2DFC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800D2E00: b           L_800D2FD4
    // 0x800D2E04: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
        goto L_800D2FD4;
    // 0x800D2E04: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
    // 0x800D2E08: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
L_800D2E0C:
    // 0x800D2E0C: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x800D2E10: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800D2E14: sb          $s4, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r20;
    // 0x800D2E18: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2E1C: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2E20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_19;
    // 0x800D2E20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x800D2E24: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2E28: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800D2E2C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800D2E30: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800D2E34: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800D2E38: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800D2E3C: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_800D2E40:
    // 0x800D2E40: bnel        $s2, $t8, L_800D2EA8
    if (ctx->r18 != ctx->r24) {
        // 0x800D2E44: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EA8;
    }
    goto skip_20;
    // 0x800D2E44: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x800D2E48: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800D2E4C: slti        $at, $s4, 0x40
    ctx->r1 = SIGNED(ctx->r20) < 0X40 ? 1 : 0;
    // 0x800D2E50: beql        $s3, $v0, L_800D2EA8
    if (ctx->r19 == ctx->r2) {
        // 0x800D2E54: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EA8;
    }
    goto skip_21;
    // 0x800D2E54: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x800D2E58: bne         $at, $zero, L_800D2E70
    if (ctx->r1 != 0) {
        // 0x800D2E5C: nop

            goto L_800D2E70;
    }
    // 0x800D2E5C: nop

    // 0x800D2E60: bnel        $v0, $zero, L_800D2EA8
    if (ctx->r2 != 0) {
        // 0x800D2E64: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EA8;
    }
    goto skip_22;
    // 0x800D2E64: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
    // 0x800D2E68: b           L_800D2EA4
    // 0x800D2E6C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800D2EA4;
    // 0x800D2E6C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_800D2E70:
    // 0x800D2E70: bne         $s6, $v0, L_800D2E80
    if (ctx->r22 != ctx->r2) {
        // 0x800D2E74: nop

            goto L_800D2E80;
    }
    // 0x800D2E74: nop

    // 0x800D2E78: b           L_800D2EA4
    // 0x800D2E7C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_800D2EA4;
    // 0x800D2E7C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800D2E80:
    // 0x800D2E80: bnel        $s7, $v0, L_800D2EA8
    if (ctx->r23 != ctx->r2) {
        // 0x800D2E84: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EA8;
    }
    goto skip_23;
    // 0x800D2E84: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
    // 0x800D2E88: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800D2E8C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800D2E90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2E94: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800D2E98: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2E9C: jal         0x800D220C
    // 0x800D2EA0: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    __seqpReleaseVoice(rdram, ctx);
        goto after_23;
    // 0x800D2EA0: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    after_23:
L_800D2EA4:
    // 0x800D2EA4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2EA8:
    // 0x800D2EA8: bnel        $s0, $zero, L_800D2E40
    if (ctx->r16 != 0) {
        // 0x800D2EAC: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2E40;
    }
    goto skip_24;
    // 0x800D2EAC: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x800D2EB0: b           L_800D2FD8
    // 0x800D2EB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2EB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2EB8:
    // 0x800D2EB8: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x800D2EBC: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x800D2EC0: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800D2EC4: sb          $s4, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r20;
    // 0x800D2EC8: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2ECC: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2ED0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_25;
    // 0x800D2ED0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
    // 0x800D2ED4: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2ED8: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800D2EDC:
    // 0x800D2EDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2EE0: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800D2EE4: bnel        $s2, $t9, L_800D2EF8
    if (ctx->r18 != ctx->r25) {
        // 0x800D2EE8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EF8;
    }
    goto skip_26;
    // 0x800D2EE8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x800D2EEC: jal         0x800D42B0
    // 0x800D2EF0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    alSynSetFXMix(rdram, ctx);
        goto after_24;
    // 0x800D2EF0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_24:
    // 0x800D2EF4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2EF8:
    // 0x800D2EF8: bnel        $s0, $zero, L_800D2EDC
    if (ctx->r16 != 0) {
        // 0x800D2EFC: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2EDC;
    }
    goto skip_27;
    // 0x800D2EFC: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x800D2F00: b           L_800D2FD8
    // 0x800D2F04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2F04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2F08:
    // 0x800D2F08: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800D2F0C: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x800D2F10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2F14: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800D2F18: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800D2F1C: addu        $t7, $v0, $t8
    ctx->r15 = ADD32(ctx->r2, ctx->r24);
    // 0x800D2F20: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D2F24: beql        $at, $zero, L_800D2FD8
    if (ctx->r1 == 0) {
        // 0x800D2F28: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_28;
    // 0x800D2F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x800D2F2C: jal         0x800D1FD0
    // 0x800D2F30: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    __setInstChanState(rdram, ctx);
        goto after_25;
    // 0x800D2F30: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    after_25:
    // 0x800D2F34: b           L_800D2FD8
    // 0x800D2F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2F3C:
    // 0x800D2F3C: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800D2F40: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800D2F44: sll         $t7, $s4, 7
    ctx->r15 = S32(ctx->r20 << 7);
    // 0x800D2F48: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800D2F4C: lh          $t8, 0x4($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X4);
    // 0x800D2F50: addu        $t9, $t7, $s3
    ctx->r25 = ADD32(ctx->r15, ctx->r19);
    // 0x800D2F54: addiu       $t6, $t9, -0x2000
    ctx->r14 = ADD32(ctx->r25, -0X2000);
    // 0x800D2F58: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2F5C: mflo        $a0
    ctx->r4 = lo;
    // 0x800D2F60: bgez        $a0, L_800D2F70
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D2F64: sra         $t7, $a0, 13
        ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
            goto L_800D2F70;
    }
    // 0x800D2F64: sra         $t7, $a0, 13
    ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
    // 0x800D2F68: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x800D2F6C: sra         $t7, $at, 13
    ctx->r15 = S32(SIGNED(ctx->r1) >> 13);
L_800D2F70:
    // 0x800D2F70: jal         0x800CADC0
    // 0x800D2F74: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_26;
    // 0x800D2F74: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_26:
    // 0x800D2F78: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800D2F7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800D2F80: addu        $t8, $t9, $fp
    ctx->r24 = ADD32(ctx->r25, ctx->r30);
    // 0x800D2F84: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x800D2F88: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2F8C: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2F90: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_29;
    // 0x800D2F90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
    // 0x800D2F94: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2F98: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800D2F9C:
    // 0x800D2F9C: bnel        $s2, $t6, L_800D2FCC
    if (ctx->r18 != ctx->r14) {
        // 0x800D2FA0: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2FCC;
    }
    goto skip_30;
    // 0x800D2FA0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_30:
    // 0x800D2FA4: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D2FA8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D2FAC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2FB0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800D2FB4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2FB8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D2FBC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800D2FC0: jal         0x800D3E70
    // 0x800D2FC4: nop

    alSynSetPitch(rdram, ctx);
        goto after_27;
    // 0x800D2FC4: nop

    after_27:
    // 0x800D2FC8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2FCC:
    // 0x800D2FCC: bnel        $s0, $zero, L_800D2F9C
    if (ctx->r16 != 0) {
        // 0x800D2FD0: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2F9C;
    }
    goto skip_31;
    // 0x800D2FD0: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_31:
L_800D2FD4:
    // 0x800D2FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2FD8:
    // 0x800D2FD8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x800D2FDC: jr          $ra
    // 0x800D2FE0: nop

    return;
    // 0x800D2FE0: nop

    // 0x800D2FE4: jr          $ra
    // 0x800D2FE8: nop

    return;
    // 0x800D2FE8: nop

    // 0x800D2FEC: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800D2FF0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D2FF4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D2FF8: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x800D2FFC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D3000: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D3004: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D3008: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D300C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D3010: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D3014: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D3018: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D301C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D3020: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D3024: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800D3028: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_800D302C:
    // 0x800D302C: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x800D3030: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800D3034: beq         $at, $zero, L_800D35BC
    if (ctx->r1 == 0) {
        // 0x800D3038: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800D35BC;
    }
    // 0x800D3038: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D303C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D3040: addu        $at, $at, $t7
    gpr jr_addend_800D3048 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D3044: lw          $t7, 0x548($at)
    ctx->r15 = ADD32(ctx->r1, 0X548);
    // 0x800D3048: jr          $t7
    // 0x800D304C: nop

    switch (jr_addend_800D3048 >> 2) {
        case 0: goto L_800D3050; break;
        case 1: goto L_800D35BC; break;
        case 2: goto L_800D3364; break;
        case 3: goto L_800D35BC; break;
        case 4: goto L_800D35BC; break;
        case 5: goto L_800D311C; break;
        case 6: goto L_800D3168; break;
        case 7: goto L_800D3384; break;
        case 8: goto L_800D35BC; break;
        case 9: goto L_800D30FC; break;
        case 10: goto L_800D34BC; break;
        case 11: goto L_800D3524; break;
        case 12: goto L_800D3540; break;
        case 13: goto L_800D355C; break;
        case 14: goto L_800D35AC; break;
        case 15: goto L_800D3398; break;
        case 16: goto L_800D33BC; break;
        case 17: goto L_800D342C; break;
        case 18: goto L_800D35BC; break;
        case 19: goto L_800D35BC; break;
        case 20: goto L_800D35BC; break;
        case 21: goto L_800D35BC; break;
        case 22: goto L_800D31CC; break;
        case 23: goto L_800D32DC; break;
        default: switch_error(__func__, 0x800D3048, 0x800F0548);
    }
    // 0x800D304C: nop

L_800D3050:
    // 0x800D3050: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x800D3054: beql        $a0, $zero, L_800D35C0
    if (ctx->r4 == 0) {
        // 0x800D3058: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D35C0;
    }
    goto skip_32;
    // 0x800D3058: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_32:
    // 0x800D305C: jal         0x800D6434
    // 0x800D3060: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    alSeqNextEvent(rdram, ctx);
        goto after_28;
    // 0x800D3060: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_28:
    // 0x800D3064: lh          $v0, 0x88($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X88);
    // 0x800D3068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D306C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800D3070: beq         $v0, $at, L_800D3098
    if (ctx->r2 == ctx->r1) {
        // 0x800D3074: addiu       $a0, $sp, 0x88
        ctx->r4 = ADD32(ctx->r29, 0X88);
            goto L_800D3098;
    }
    // 0x800D3074: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800D3078: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D307C: beq         $v0, $at, L_800D30BC
    if (ctx->r2 == ctx->r1) {
        // 0x800D3080: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800D30BC;
    }
    // 0x800D3080: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D3084: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D3088: beq         $v0, $at, L_800D30D4
    if (ctx->r2 == ctx->r1) {
        // 0x800D308C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_800D30D4;
    }
    // 0x800D308C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800D3090: b           L_800D35C0
    // 0x800D3094: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3094: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3098:
    // 0x800D3098: sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // 0x800D309C: jal         0x800D27CC
    // 0x800D30A0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_800D27CC(rdram, ctx);
        goto after_29;
    // 0x800D30A0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_29:
    // 0x800D30A4: lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD0);
    // 0x800D30A8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800D30AC: jal         0x800D2450
    // 0x800D30B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __postNextSeqEvent(rdram, ctx);
        goto after_30;
    // 0x800D30B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x800D30B4: b           L_800D35C0
    // 0x800D30B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D30B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D30BC:
    // 0x800D30BC: jal         0x800D252C
    // 0x800D30C0: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_800D252C(rdram, ctx);
        goto after_31;
    // 0x800D30C0: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_31:
    // 0x800D30C4: jal         0x800D2450
    // 0x800D30C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __postNextSeqEvent(rdram, ctx);
        goto after_32;
    // 0x800D30C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_32:
    // 0x800D30CC: b           L_800D35C0
    // 0x800D30D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D30D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D30D4:
    // 0x800D30D4: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    // 0x800D30D8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800D30DC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800D30E0: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x800D30E4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800D30E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D30EC: jal         0x800D3A2C
    // 0x800D30F0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    alEvtqPostEvent(rdram, ctx);
        goto after_33;
    // 0x800D30F0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_33:
    // 0x800D30F4: b           L_800D35C0
    // 0x800D30F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D30F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D30FC:
    // 0x800D30FC: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x800D3100: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x800D3104: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x800D3108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D310C: jal         0x800D3A2C
    // 0x800D3110: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    alEvtqPostEvent(rdram, ctx);
        goto after_34;
    // 0x800D3110: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_34:
    // 0x800D3114: b           L_800D35C0
    // 0x800D3118: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3118: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D311C:
    // 0x800D311C: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800D3120: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D3124: jal         0x800D3CA0
    // 0x800D3128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_35;
    // 0x800D3128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_35:
    // 0x800D312C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D3130: jal         0x800D3D20
    // 0x800D3134: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_36;
    // 0x800D3134: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_36:
    // 0x800D3138: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800D313C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D3140: lbu         $t7, 0x37($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X37);
    // 0x800D3144: beql        $t7, $zero, L_800D3158
    if (ctx->r15 == 0) {
        // 0x800D3148: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D3158;
    }
    goto skip_33;
    // 0x800D3148: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_33:
    // 0x800D314C: jal         0x800D3610
    // 0x800D3150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_37;
    // 0x800D3150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_37:
    // 0x800D3154: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D3158:
    // 0x800D3158: jal         0x800D23E0
    // 0x800D315C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_38;
    // 0x800D315C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_38:
    // 0x800D3160: b           L_800D35C0
    // 0x800D3164: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3164: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3168:
    // 0x800D3168: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800D316C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D3170: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800D3174: lbu         $t8, 0x34($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X34);
    // 0x800D3178: bnel        $t8, $zero, L_800D3188
    if (ctx->r24 != 0) {
        // 0x800D317C: lbu         $t6, 0x44($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X44);
            goto L_800D3188;
    }
    goto skip_34;
    // 0x800D317C: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    skip_34:
    // 0x800D3180: sb          $t9, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r25;
    // 0x800D3184: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
L_800D3188:
    // 0x800D3188: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    // 0x800D318C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3190: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    // 0x800D3194: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    // 0x800D3198: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D319C: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x800D31A0: jal         0x800D2184
    // 0x800D31A4: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    __vsVol(rdram, ctx);
        goto after_39;
    // 0x800D31A4: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    after_39:
    // 0x800D31A8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D31AC: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D31B0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800D31B4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D31B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D31BC: jal         0x800D3DD0
    // 0x800D31C0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    alSynSetVol(rdram, ctx);
        goto after_40;
    // 0x800D31C0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_40:
    // 0x800D31C4: b           L_800D35C0
    // 0x800D31C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D31C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D31CC:
    // 0x800D31CC: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800D31D0: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800D31D4: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800D31D8: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800D31DC: jalr        $t9
    // 0x800D31E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_41;
    // 0x800D31E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_41:
    // 0x800D31E4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800D31E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D31EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D31F0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800D31F4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D31F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800D31FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800D3200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3204: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D3208: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D320C: nop

    // 0x800D3210: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800D3214: beql        $t7, $zero, L_800D3264
    if (ctx->r15 == 0) {
        // 0x800D3218: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_800D3264;
    }
    goto skip_35;
    // 0x800D3218: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_35:
    // 0x800D321C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D3220: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D3224: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D3228: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D322C: nop

    // 0x800D3230: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800D3234: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D3238: nop

    // 0x800D323C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800D3240: bne         $t7, $zero, L_800D3258
    if (ctx->r15 != 0) {
        // 0x800D3244: nop

            goto L_800D3258;
    }
    // 0x800D3244: nop

    // 0x800D3248: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800D324C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D3250: b           L_800D3270
    // 0x800D3254: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800D3270;
    // 0x800D3254: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800D3258:
    // 0x800D3258: b           L_800D3270
    // 0x800D325C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800D3270;
    // 0x800D325C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D3260: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_800D3264:
    // 0x800D3264: nop

    // 0x800D3268: bltz        $t7, L_800D3258
    if (SIGNED(ctx->r15) < 0) {
        // 0x800D326C: nop

            goto L_800D3258;
    }
    // 0x800D326C: nop

L_800D3270:
    // 0x800D3270: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800D3274: jal         0x800D2184
    // 0x800D3278: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    __vsVol(rdram, ctx);
        goto after_42;
    // 0x800D3278: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    after_42:
    // 0x800D327C: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x800D3280: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x800D3284: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D3288: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D328C: subu        $a0, $t9, $v1
    ctx->r4 = SUB32(ctx->r25, ctx->r3);
    // 0x800D3290: bltz        $a0, L_800D32A0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D3294: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800D32A0;
    }
    // 0x800D3294: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800D3298: b           L_800D32A4
    // 0x800D329C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D32A4;
    // 0x800D329C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D32A0:
    // 0x800D32A0: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D32A4:
    // 0x800D32A4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D32A8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800D32AC: jal         0x800D3DD0
    // 0x800D32B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_43;
    // 0x800D32B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_43:
    // 0x800D32B4: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x800D32B8: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x800D32BC: sw          $s1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r17;
    // 0x800D32C0: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
    // 0x800D32C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D32C8: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x800D32CC: jal         0x800D3A2C
    // 0x800D32D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_44;
    // 0x800D32D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_44:
    // 0x800D32D4: b           L_800D35C0
    // 0x800D32D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D32D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D32DC:
    // 0x800D32DC: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800D32E0: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800D32E4: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800D32E8: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x800D32EC: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800D32F0: jalr        $t9
    // 0x800D32F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_45;
    // 0x800D32F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_45:
    // 0x800D32F8: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800D32FC: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800D3300: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x800D3304: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x800D3308: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800D330C: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800D3310: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D3314: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800D3318: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800D331C: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800D3320: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D3324: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800D3328: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800D332C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800D3330: jal         0x800D3E70
    // 0x800D3334: nop

    alSynSetPitch(rdram, ctx);
        goto after_46;
    // 0x800D3334: nop

    after_46:
    // 0x800D3338: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x800D333C: sh          $t9, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r25;
    // 0x800D3340: sw          $s1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r17;
    // 0x800D3344: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
    // 0x800D3348: sb          $s0, 0xC8($sp)
    MEM_B(0XC8, ctx->r29) = ctx->r16;
    // 0x800D334C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D3350: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x800D3354: jal         0x800D3A2C
    // 0x800D3358: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_47;
    // 0x800D3358: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_47:
    // 0x800D335C: b           L_800D35C0
    // 0x800D3360: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3360: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3364:
    // 0x800D3364: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800D3368: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800D336C: sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // 0x800D3370: jal         0x800D27CC
    // 0x800D3374: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_800D27CC(rdram, ctx);
        goto after_48;
    // 0x800D3374: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_48:
    // 0x800D3378: lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD0);
    // 0x800D337C: b           L_800D35BC
    // 0x800D3380: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_800D35BC;
    // 0x800D3380: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_800D3384:
    // 0x800D3384: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D3388: jal         0x800D252C
    // 0x800D338C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800D252C(rdram, ctx);
        goto after_49;
    // 0x800D338C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_49:
    // 0x800D3390: b           L_800D35C0
    // 0x800D3394: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3394: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3398:
    // 0x800D3398: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x800D339C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D33A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D33A4: beq         $t7, $at, L_800D35BC
    if (ctx->r15 == ctx->r1) {
        // 0x800D33A8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D35BC;
    }
    // 0x800D33A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D33AC: jal         0x800D2450
    // 0x800D33B0: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    __postNextSeqEvent(rdram, ctx);
        goto after_50;
    // 0x800D33B0: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    after_50:
    // 0x800D33B4: b           L_800D35C0
    // 0x800D33B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D33B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D33BC:
    // 0x800D33BC: lw          $t6, 0x2C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X2C);
    // 0x800D33C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D33C4: bnel        $t6, $at, L_800D35C0
    if (ctx->r14 != ctx->r1) {
        // 0x800D33C8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D35C0;
    }
    goto skip_36;
    // 0x800D33C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_36:
    // 0x800D33CC: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800D33D0: beq         $s1, $zero, L_800D3420
    if (ctx->r17 == 0) {
        // 0x800D33D4: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800D3420;
    }
    // 0x800D33D4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800D33D8:
    // 0x800D33D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D33DC: jal         0x800D3CA0
    // 0x800D33E0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    alSynStopVoice(rdram, ctx);
        goto after_51;
    // 0x800D33E0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_51:
    // 0x800D33E4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D33E8: jal         0x800D3D20
    // 0x800D33EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_52;
    // 0x800D33EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_52:
    // 0x800D33F0: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x800D33F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D33F8: beql        $t9, $zero, L_800D340C
    if (ctx->r25 == 0) {
        // 0x800D33FC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D340C;
    }
    goto skip_37;
    // 0x800D33FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_37:
    // 0x800D3400: jal         0x800D3610
    // 0x800D3404: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_53;
    // 0x800D3404: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_53:
    // 0x800D3408: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D340C:
    // 0x800D340C: jal         0x800D23E0
    // 0x800D3410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_54;
    // 0x800D3410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_54:
    // 0x800D3414: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800D3418: bnel        $s1, $zero, L_800D33D8
    if (ctx->r17 != 0) {
        // 0x800D341C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800D33D8;
    }
    goto skip_38;
    // 0x800D341C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_38:
L_800D3420:
    // 0x800D3420: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
    // 0x800D3424: b           L_800D35BC
    // 0x800D3428: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_800D35BC;
    // 0x800D3428: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_800D342C:
    // 0x800D342C: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x800D3430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D3434: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D3438: bnel        $t7, $at, L_800D35C0
    if (ctx->r15 != ctx->r1) {
        // 0x800D343C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D35C0;
    }
    goto skip_39;
    // 0x800D343C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_39:
    // 0x800D3440: jal         0x800D3910
    // 0x800D3444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_55;
    // 0x800D3444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_55:
    // 0x800D3448: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D344C: jal         0x800D3910
    // 0x800D3450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_56;
    // 0x800D3450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_56:
    // 0x800D3454: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800D3458: beq         $s1, $zero, L_800D3490
    if (ctx->r17 == 0) {
        // 0x800D345C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800D3490;
    }
    // 0x800D345C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800D3460:
    // 0x800D3460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D3464: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D3468: jal         0x800D2338
    // 0x800D346C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __voiceNeedsNoteKill(rdram, ctx);
        goto after_57;
    // 0x800D346C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_57:
    // 0x800D3470: beq         $v0, $zero, L_800D3484
    if (ctx->r2 == 0) {
        // 0x800D3474: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D3484;
    }
    // 0x800D3474: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D3478: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D347C: jal         0x800D220C
    // 0x800D3480: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __seqpReleaseVoice(rdram, ctx);
        goto after_58;
    // 0x800D3480: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_58:
L_800D3484:
    // 0x800D3484: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800D3488: bnel        $s1, $zero, L_800D3460
    if (ctx->r17 != 0) {
        // 0x800D348C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800D3460;
    }
    goto skip_40;
    // 0x800D348C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_40:
L_800D3490:
    // 0x800D3490: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800D3494: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    // 0x800D3498: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800D349C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800D34A0: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x800D34A4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800D34A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D34AC: jal         0x800D3A2C
    // 0x800D34B0: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    alEvtqPostEvent(rdram, ctx);
        goto after_59;
    // 0x800D34B0: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_59:
    // 0x800D34B4: b           L_800D35C0
    // 0x800D34B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D34B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D34BC:
    // 0x800D34BC: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800D34C0: lh          $t9, 0x3C($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X3C);
    // 0x800D34C4: beq         $s1, $zero, L_800D35BC
    if (ctx->r17 == 0) {
        // 0x800D34C8: sh          $t9, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r25;
            goto L_800D35BC;
    }
    // 0x800D34C8: sh          $t9, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r25;
    // 0x800D34CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D34D0:
    // 0x800D34D0: jal         0x800D2184
    // 0x800D34D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_60;
    // 0x800D34D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_60:
    // 0x800D34D8: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x800D34DC: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x800D34E0: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D34E4: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D34E8: subu        $a0, $t8, $v1
    ctx->r4 = SUB32(ctx->r24, ctx->r3);
    // 0x800D34EC: bltz        $a0, L_800D34FC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D34F0: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_800D34FC;
    }
    // 0x800D34F0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800D34F4: b           L_800D3500
    // 0x800D34F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D3500;
    // 0x800D34F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D34FC:
    // 0x800D34FC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D3500:
    // 0x800D3500: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D3504: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800D3508: jal         0x800D3DD0
    // 0x800D350C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_61;
    // 0x800D350C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_61:
    // 0x800D3510: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800D3514: bnel        $s1, $zero, L_800D34D0
    if (ctx->r17 != 0) {
        // 0x800D3518: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D34D0;
    }
    goto skip_41;
    // 0x800D3518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_41:
    // 0x800D351C: b           L_800D35C0
    // 0x800D3520: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3520: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3524:
    // 0x800D3524: lw          $t6, 0x3C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X3C);
    // 0x800D3528: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x800D352C: lw          $t7, 0x44($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X44);
    // 0x800D3530: sw          $t6, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r14;
    // 0x800D3534: sw          $t9, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r25;
    // 0x800D3538: b           L_800D35BC
    // 0x800D353C: sw          $t7, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r15;
        goto L_800D35BC;
    // 0x800D353C: sw          $t7, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r15;
L_800D3540:
    // 0x800D3540: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x800D3544: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x800D3548: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x800D354C: sll         $t9, $s0, 4
    ctx->r25 = S32(ctx->r16 << 4);
    // 0x800D3550: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800D3554: b           L_800D35BC
    // 0x800D3558: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_800D35BC;
    // 0x800D3558: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_800D355C:
    // 0x800D355C: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x800D3560: addiu       $t7, $zero, 0x1E8
    ctx->r15 = ADD32(0, 0X1E8);
    // 0x800D3564: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D3568: beq         $a1, $zero, L_800D358C
    if (ctx->r5 == 0) {
        // 0x800D356C: sw          $a1, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r5;
            goto L_800D358C;
    }
    // 0x800D356C: sw          $a1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r5;
    // 0x800D3570: lwc1        $f6, 0x5A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A8);
    // 0x800D3574: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800D3578: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D357C: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D3580: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800D3584: b           L_800D3590
    // 0x800D3588: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
        goto L_800D3590;
    // 0x800D3588: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
L_800D358C:
    // 0x800D358C: sw          $t7, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r15;
L_800D3590:
    // 0x800D3590: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x800D3594: beql        $a1, $zero, L_800D35C0
    if (ctx->r5 == 0) {
        // 0x800D3598: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D35C0;
    }
    goto skip_42;
    // 0x800D3598: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_42:
    // 0x800D359C: jal         0x800D20A4
    // 0x800D35A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __initFromBank(rdram, ctx);
        goto after_62;
    // 0x800D35A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_62:
    // 0x800D35A4: b           L_800D35C0
    // 0x800D35A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D35A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D35AC:
    // 0x800D35AC: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x800D35B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D35B4: jal         0x800D20A4
    // 0x800D35B8: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_63;
    // 0x800D35B8: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_63:
L_800D35BC:
    // 0x800D35BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D35C0:
    // 0x800D35C0: jal         0x800D3B50
    // 0x800D35C4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    alEvtqNextEvent(rdram, ctx);
        goto after_64;
    // 0x800D35C4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_64:
    // 0x800D35C8: beq         $v0, $zero, L_800D302C
    if (ctx->r2 == 0) {
        // 0x800D35CC: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_800D302C;
    }
    // 0x800D35CC: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x800D35D0: lw          $t6, 0x1C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1C);
    // 0x800D35D4: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800D35D8: sw          $t9, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r25;
    // 0x800D35DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D35E0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D35E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D35E8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D35EC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D35F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D35F4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D35F8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D35FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D3600: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D3604: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D3608: jr          $ra
    // 0x800D360C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800D360C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void __seqpStopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3610: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D3614: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D3618: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800D361C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800D3620: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D3624: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800D3628: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D362C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D3630: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D3634: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D3638: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x800D363C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800D3640: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800D3644: beq         $s0, $zero, L_800D36E8
    if (ctx->r16 == 0) {
        // 0x800D3648: addiu       $s7, $zero, 0x17
        ctx->r23 = ADD32(0, 0X17);
            goto L_800D36E8;
    }
    // 0x800D3648: addiu       $s7, $zero, 0x17
    ctx->r23 = ADD32(0, 0X17);
    // 0x800D364C: addiu       $s6, $zero, 0x16
    ctx->r22 = ADD32(0, 0X16);
L_800D3650:
    // 0x800D3650: lh          $s3, 0xC($s0)
    ctx->r19 = MEM_H(ctx->r16, 0XC);
    // 0x800D3654: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D3658: beql        $s3, $s6, L_800D366C
    if (ctx->r19 == ctx->r22) {
        // 0x800D365C: lw          $t6, 0x10($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X10);
            goto L_800D366C;
    }
    goto skip_0;
    // 0x800D365C: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x800D3660: bne         $s3, $s7, L_800D36E0
    if (ctx->r19 != ctx->r23) {
        // 0x800D3664: nop

            goto L_800D36E0;
    }
    // 0x800D3664: nop

    // 0x800D3668: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
L_800D366C:
    // 0x800D366C: bne         $s2, $t6, L_800D36E0
    if (ctx->r18 != ctx->r14) {
        // 0x800D3670: nop

            goto L_800D36E0;
    }
    // 0x800D3670: nop

    // 0x800D3674: lw          $t9, 0x78($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X78);
    // 0x800D3678: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x800D367C: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    // 0x800D3680: jalr        $t9
    // 0x800D3684: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D3684: nop

    after_0:
    // 0x800D3688: jal         0x800C7890
    // 0x800D368C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800D368C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D3690: beq         $s1, $zero, L_800D36A8
    if (ctx->r17 == 0) {
        // 0x800D3694: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D36A8;
    }
    // 0x800D3694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3698: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800D369C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D36A0: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x800D36A4: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800D36A8:
    // 0x800D36A8: jal         0x800C78C0
    // 0x800D36AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800D36AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x800D36B0: bnel        $s3, $s6, L_800D36CC
    if (ctx->r19 != ctx->r22) {
        // 0x800D36B4: lbu         $t3, 0x37($s2)
        ctx->r11 = MEM_BU(ctx->r18, 0X37);
            goto L_800D36CC;
    }
    goto skip_1;
    // 0x800D36B4: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
    skip_1:
    // 0x800D36B8: lbu         $t1, 0x37($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X37);
    // 0x800D36BC: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x800D36C0: b           L_800D36D4
    // 0x800D36C4: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
        goto L_800D36D4;
    // 0x800D36C4: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
    // 0x800D36C8: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
L_800D36CC:
    // 0x800D36CC: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x800D36D0: sb          $t4, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r12;
L_800D36D4:
    // 0x800D36D4: lbu         $t5, 0x37($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X37);
    // 0x800D36D8: beql        $t5, $zero, L_800D36EC
    if (ctx->r13 == 0) {
        // 0x800D36DC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800D36EC;
    }
    goto skip_2;
    // 0x800D36DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
L_800D36E0:
    // 0x800D36E0: bne         $s1, $zero, L_800D3650
    if (ctx->r17 != 0) {
        // 0x800D36E4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D3650;
    }
    // 0x800D36E4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800D36E8:
    // 0x800D36E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800D36EC:
    // 0x800D36EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D36F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D36F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D36F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D36FC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800D3700: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800D3704: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3708: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800D370C: jr          $ra
    // 0x800D3710: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D3710: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void __initChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3714: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D3718: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D371C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D3720: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D3724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3728: lbu         $t6, 0x34($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X34);
    // 0x800D372C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D3730: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D3734: blez        $t6, L_800D376C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D3738: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800D376C;
    }
    // 0x800D3738: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D373C: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
L_800D3740:
    // 0x800D3740: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D3748: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800D374C: jal         0x800D2024
    // 0x800D3750: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x800D3750: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_0:
    // 0x800D3754: lbu         $t9, 0x34($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X34);
    // 0x800D3758: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D375C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800D3760: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D3764: bnel        $at, $zero, L_800D3740
    if (ctx->r1 != 0) {
        // 0x800D3768: lw          $t7, 0x60($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X60);
            goto L_800D3740;
    }
    goto skip_0;
    // 0x800D3768: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    skip_0:
L_800D376C:
    // 0x800D376C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D3770: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3774: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3778: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D377C: jr          $ra
    // 0x800D3780: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D3780: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alSeqpNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3784: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D3788: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D378C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D3790: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D3794: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x800D3798: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800D379C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800D37A0: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800D37A4: lw          $t6, -0x33E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33E0);
    // 0x800D37A8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800D37AC: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800D37B0: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800D37B4: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x800D37B8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800D37BC: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800D37C0: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800D37C4: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x800D37C8: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800D37CC: lbu         $t0, 0x9($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X9);
    // 0x800D37D0: addiu       $t1, $zero, 0x3E80
    ctx->r9 = ADD32(0, 0X3E80);
    // 0x800D37D4: sw          $t1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r9;
    // 0x800D37D8: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800D37DC: sb          $t0, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r8;
    // 0x800D37E0: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x800D37E4: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x800D37E8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800D37EC: sw          $t2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r10;
    // 0x800D37F0: lw          $t3, 0x14($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X14);
    // 0x800D37F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D37F8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800D37FC: sw          $t3, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r11;
    // 0x800D3800: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    // 0x800D3804: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x800D3808: sw          $zero, 0x80($a0)
    MEM_W(0X80, ctx->r4) = 0;
    // 0x800D380C: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x800D3810: sh          $t5, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r13;
    // 0x800D3814: sw          $t4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r12;
    // 0x800D3818: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800D381C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3820: sb          $t6, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r14;
    // 0x800D3824: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x800D3828: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800D382C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D3830: jal         0x800C7950
    // 0x800D3834: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800D3834: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D3838: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x800D383C: jal         0x800D3714
    // 0x800D3840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __initChanState(rdram, ctx);
        goto after_1;
    // 0x800D3840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D3844: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800D3848: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x800D384C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800D3850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D3854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3858: jal         0x800C7950
    // 0x800D385C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800D385C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800D3860: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800D3864: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800D3868: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D386C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3870: blez        $t9, L_800D38A0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D3874: addiu       $t2, $zero, 0x1C
        ctx->r10 = ADD32(0, 0X1C);
            goto L_800D38A0;
    }
    // 0x800D3874: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800D3878: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D387C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
L_800D3880:
    // 0x800D3880: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D3884: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800D3888: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x800D388C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800D3890: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800D3894: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D3898: bnel        $at, $zero, L_800D3880
    if (ctx->r1 != 0) {
        // 0x800D389C: lw          $t0, 0x6C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X6C);
            goto L_800D3880;
    }
    goto skip_0;
    // 0x800D389C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    skip_0:
L_800D38A0:
    // 0x800D38A0: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800D38A4: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800D38A8: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x800D38AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800D38B0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800D38B4: jal         0x800C7950
    // 0x800D38B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800D38B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800D38BC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800D38C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D38C4: jal         0x800D3BDC
    // 0x800D38C8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x800D38C8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x800D38CC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800D38D0: addiu       $t3, $t3, 0x2FEC
    ctx->r11 = ADD32(ctx->r11, 0X2FEC);
    // 0x800D38D4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800D38D8: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x800D38DC: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800D38E0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D38E4: lw          $a0, -0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33E0);
    // 0x800D38E8: jal         0x800D3C50
    // 0x800D38EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x800D38EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800D38F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D38F4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D38F8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D38FC: jr          $ra
    // 0x800D3900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800D3900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800D3904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3904: nop

    // 0x800D3908: nop

    // 0x800D390C: nop

;}
RECOMP_FUNC void alEvtqFlushType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3910: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D3914: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D3918: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x800D391C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D3920: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D3924: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D3928: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D392C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x800D3930: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D3934: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D3938: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800D393C: jal         0x800C41A0
    // 0x800D3940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D3944: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D3948: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800D394C: beq         $s0, $zero, L_800D3998
    if (ctx->r16 == 0) {
        // 0x800D3950: nop

            goto L_800D3998;
    }
    // 0x800D3950: nop

L_800D3954:
    // 0x800D3954: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x800D3958: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D395C: bne         $s3, $t7, L_800D3990
    if (ctx->r19 != ctx->r15) {
        // 0x800D3960: nop

            goto L_800D3990;
    }
    // 0x800D3960: nop

    // 0x800D3964: beq         $s1, $zero, L_800D397C
    if (ctx->r17 == 0) {
        // 0x800D3968: nop

            goto L_800D397C;
    }
    // 0x800D3968: nop

    // 0x800D396C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800D3970: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800D3974: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D3978: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800D397C:
    // 0x800D397C: jal         0x800C7890
    // 0x800D3980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800D3980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D3984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3988: jal         0x800C78C0
    // 0x800D398C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800D398C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800D3990:
    // 0x800D3990: bne         $s1, $zero, L_800D3954
    if (ctx->r17 != 0) {
        // 0x800D3994: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D3954;
    }
    // 0x800D3994: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800D3998:
    // 0x800D3998: jal         0x800C41A0
    // 0x800D399C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800D399C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800D39A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D39A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D39A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D39AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D39B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D39B4: jr          $ra
    // 0x800D39B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800D39B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void alEvtqFlush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D39BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D39C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D39C4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D39C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D39CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D39D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D39D4: jal         0x800C41A0
    // 0x800D39D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D39D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D39DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D39E0: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800D39E4: beq         $s0, $zero, L_800D3A0C
    if (ctx->r16 == 0) {
        // 0x800D39E8: nop

            goto L_800D3A0C;
    }
    // 0x800D39E8: nop

L_800D39EC:
    // 0x800D39EC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D39F0: jal         0x800C7890
    // 0x800D39F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800D39F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D39F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D39FC: jal         0x800C78C0
    // 0x800D3A00: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800D3A00: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800D3A04: bne         $s1, $zero, L_800D39EC
    if (ctx->r17 != 0) {
        // 0x800D3A08: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D39EC;
    }
    // 0x800D3A08: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800D3A0C:
    // 0x800D3A0C: jal         0x800C41A0
    // 0x800D3A10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800D3A10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800D3A14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D3A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3A1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3A20: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D3A24: jr          $ra
    // 0x800D3A28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D3A28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void alEvtqPostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3A2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D3A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3A34: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D3A38: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D3A3C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800D3A40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D3A44: jal         0x800C41A0
    // 0x800D3A48: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3A48: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D3A4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800D3A50: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D3A54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D3A58: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800D3A5C: bne         $t0, $zero, L_800D3A74
    if (ctx->r8 != 0) {
        // 0x800D3A60: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800D3A74;
    }
    // 0x800D3A60: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800D3A64: jal         0x800C41A0
    // 0x800D3A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D3A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D3A6C: b           L_800D3B44
    // 0x800D3A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3B44;
    // 0x800D3A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3A74:
    // 0x800D3A74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D3A78: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800D3A7C: jal         0x800C7890
    // 0x800D3A80: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800D3A80: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800D3A84: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3A88: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800D3A8C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800D3A90: jal         0x800D6320
    // 0x800D3A94: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alCopy(rdram, ctx);
        goto after_3;
    // 0x800D3A94: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800D3A98: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D3A9C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800D3AA0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D3AA4: bne         $a3, $at, L_800D3AB4
    if (ctx->r7 != ctx->r1) {
        // 0x800D3AA8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800D3AB4;
    }
    // 0x800D3AA8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3AAC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D3AB0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800D3AB4:
    // 0x800D3AB4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800D3AB8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D3ABC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D3AC0: beq         $v0, $at, L_800D3B38
    if (ctx->r2 == ctx->r1) {
        // 0x800D3AC4: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_800D3B38;
    }
    // 0x800D3AC4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_800D3AC8:
    // 0x800D3AC8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800D3ACC: bnel        $v0, $zero, L_800D3AFC
    if (ctx->r2 != 0) {
        // 0x800D3AD0: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800D3AFC;
    }
    goto skip_0;
    // 0x800D3AD0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800D3AD4: beql        $t8, $zero, L_800D3AE8
    if (ctx->r24 == 0) {
        // 0x800D3AD8: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_800D3AE8;
    }
    goto skip_1;
    // 0x800D3AD8: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x800D3ADC: b           L_800D3AE8
    // 0x800D3AE0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_800D3AE8;
    // 0x800D3AE0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x800D3AE4: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_800D3AE8:
    // 0x800D3AE8: jal         0x800C78C0
    // 0x800D3AEC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800D3AEC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x800D3AF0: b           L_800D3B38
    // 0x800D3AF4: nop

        goto L_800D3B38;
    // 0x800D3AF4: nop

    // 0x800D3AF8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800D3AFC:
    // 0x800D3AFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3B00: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D3B04: beql        $at, $zero, L_800D3B30
    if (ctx->r1 == 0) {
        // 0x800D3B08: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D3B30;
    }
    goto skip_2;
    // 0x800D3B08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x800D3B0C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x800D3B10: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800D3B14: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800D3B18: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x800D3B1C: jal         0x800C78C0
    // 0x800D3B20: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800D3B20: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    after_5:
    // 0x800D3B24: b           L_800D3B38
    // 0x800D3B28: nop

        goto L_800D3B38;
    // 0x800D3B28: nop

    // 0x800D3B2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D3B30:
    // 0x800D3B30: bne         $v0, $zero, L_800D3AC8
    if (ctx->r2 != 0) {
        // 0x800D3B34: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_800D3AC8;
    }
    // 0x800D3B34: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_800D3B38:
    // 0x800D3B38: jal         0x800C41A0
    // 0x800D3B3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800D3B3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x800D3B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3B44:
    // 0x800D3B44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D3B48: jr          $ra
    // 0x800D3B4C: nop

    return;
    // 0x800D3B4C: nop

;}
RECOMP_FUNC void alEvtqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3B50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D3B54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3B58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D3B5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3B60: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D3B64: jal         0x800C41A0
    // 0x800D3B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D3B6C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800D3B70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800D3B74: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800D3B78: lw          $s0, 0x8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8);
    // 0x800D3B7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D3B80: beql        $s0, $zero, L_800D3BB8
    if (ctx->r16 == 0) {
        // 0x800D3B84: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_800D3BB8;
    }
    goto skip_0;
    // 0x800D3B84: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x800D3B88: jal         0x800C7890
    // 0x800D3B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800D3B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D3B90: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x800D3B94: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800D3B98: jal         0x800D6320
    // 0x800D3B9C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    alCopy(rdram, ctx);
        goto after_2;
    // 0x800D3B9C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x800D3BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3BA4: jal         0x800C78C0
    // 0x800D3BA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800D3BA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800D3BAC: b           L_800D3BBC
    // 0x800D3BB0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
        goto L_800D3BBC;
    // 0x800D3BB0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800D3BB4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_800D3BB8:
    // 0x800D3BB8: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_800D3BBC:
    // 0x800D3BBC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D3BC0: jal         0x800C41A0
    // 0x800D3BC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x800D3BC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800D3BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3BCC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800D3BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3BD4: jr          $ra
    // 0x800D3BD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D3BD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alEvtqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3BDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D3BE0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D3BE4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D3BE8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D3BEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D3BF0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D3BF4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D3BF8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800D3BFC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800D3C00: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800D3C04: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800D3C08: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800D3C0C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D3C10: blez        $a2, L_800D3C34
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800D3C14: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800D3C34;
    }
    // 0x800D3C14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D3C18: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_800D3C1C:
    // 0x800D3C1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3C20: jal         0x800C78C0
    // 0x800D3C24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_0;
    // 0x800D3C24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800D3C28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D3C2C: bne         $s0, $s3, L_800D3C1C
    if (ctx->r16 != ctx->r19) {
        // 0x800D3C30: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_800D3C1C;
    }
    // 0x800D3C30: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_800D3C34:
    // 0x800D3C34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D3C38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D3C3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D3C40: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3C44: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D3C48: jr          $ra
    // 0x800D3C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D3C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alSynAddPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3C58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3C5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800D3C60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D3C64: jal         0x800C41A0
    // 0x800D3C68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3C68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D3C6C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800D3C70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3C74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D3C78: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x800D3C7C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x800D3C80: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D3C84: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D3C88: jal         0x800C41A0
    // 0x800D3C8C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D3C8C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x800D3C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3C98: jr          $ra
    // 0x800D3C9C: nop

    return;
    // 0x800D3C9C: nop

;}
RECOMP_FUNC void alSynStopVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3CA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D3CAC: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D3CB0: beql        $t6, $zero, L_800D3D0C
    if (ctx->r14 == 0) {
        // 0x800D3CB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3D0C;
    }
    goto skip_0;
    // 0x800D3CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3CB8: jal         0x800C7C00
    // 0x800D3CBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D3CBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D3CC0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3CC4: beq         $v0, $zero, L_800D3D08
    if (ctx->r2 == 0) {
        // 0x800D3CC8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D3D08;
    }
    // 0x800D3CC8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3CCC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D3CD0: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D3CD4: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800D3CD8: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D3CDC: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D3CE0: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D3CE4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D3CE8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D3CEC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D3CF0: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800D3CF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D3CF8: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800D3CFC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D3D00: jalr        $t9
    // 0x800D3D04: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D3D04: nop

    after_1:
L_800D3D08:
    // 0x800D3D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3D0C:
    // 0x800D3D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3D10: jr          $ra
    // 0x800D3D14: nop

    return;
    // 0x800D3D14: nop

;}
RECOMP_FUNC void func_800D3D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D18: nop

    // 0x800D3D1C: nop

;}
RECOMP_FUNC void alSynFreeVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3D28: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x800D3D2C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D3D30: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D3D34: beql        $a2, $zero, L_800D3DC4
    if (ctx->r6 == 0) {
        // 0x800D3D38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3DC4;
    }
    goto skip_0;
    // 0x800D3D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3D3C: lw          $t6, 0xD8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD8);
    // 0x800D3D40: beql        $t6, $zero, L_800D3DAC
    if (ctx->r14 == 0) {
        // 0x800D3D44: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800D3DAC;
    }
    goto skip_1;
    // 0x800D3D44: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    skip_1:
    // 0x800D3D48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D3D4C: jal         0x800C7C00
    // 0x800D3D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D3D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D3D54: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3D58: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800D3D5C: beq         $v0, $zero, L_800D3DC0
    if (ctx->r2 == 0) {
        // 0x800D3D60: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D3DC0;
    }
    // 0x800D3D60: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3D64: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x800D3D68: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800D3D6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D3D70: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x800D3D74: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800D3D78: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800D3D7C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D3D80: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800D3D84: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800D3D88: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800D3D8C: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800D3D90: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800D3D94: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D3D98: jalr        $t9
    // 0x800D3D9C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D3D9C: nop

    after_1:
    // 0x800D3DA0: b           L_800D3DBC
    // 0x800D3DA4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800D3DBC;
    // 0x800D3DA4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3DA8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800D3DAC:
    // 0x800D3DAC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800D3DB0: jal         0x800C7B50
    // 0x800D3DB4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _freePVoice(rdram, ctx);
        goto after_2;
    // 0x800D3DB4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800D3DB8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800D3DBC:
    // 0x800D3DBC: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_800D3DC0:
    // 0x800D3DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3DC4:
    // 0x800D3DC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3DC8: jr          $ra
    // 0x800D3DCC: nop

    return;
    // 0x800D3DCC: nop

;}
RECOMP_FUNC void alSynSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3DD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3DD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D3DDC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D3DE0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800D3DE4: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800D3DE8: beql        $t7, $zero, L_800D3E60
    if (ctx->r15 == 0) {
        // 0x800D3DEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3E60;
    }
    goto skip_0;
    // 0x800D3DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3DF0: jal         0x800C7C00
    // 0x800D3DF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D3DF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D3DF8: beq         $v0, $zero, L_800D3E5C
    if (ctx->r2 == 0) {
        // 0x800D3DFC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800D3E5C;
    }
    // 0x800D3DFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D3E00: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D3E04: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800D3E08: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800D3E0C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800D3E10: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x800D3E14: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x800D3E18: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800D3E1C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800D3E20: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800D3E24: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800D3E28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D3E2C: jal         0x800C7AF8
    // 0x800D3E30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _timeToSamples(rdram, ctx);
        goto after_1;
    // 0x800D3E30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800D3E34: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3E38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D3E3C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800D3E40: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D3E44: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800D3E48: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800D3E4C: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x800D3E50: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D3E54: jalr        $t9
    // 0x800D3E58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D3E58: nop

    after_2:
L_800D3E5C:
    // 0x800D3E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3E60:
    // 0x800D3E60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3E64: jr          $ra
    // 0x800D3E68: nop

    return;
    // 0x800D3E68: nop

;}
RECOMP_FUNC void func_800D3E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E6C: nop

;}
RECOMP_FUNC void alSynSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3E78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D3E7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D3E80: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D3E84: beql        $t6, $zero, L_800D3EE8
    if (ctx->r14 == 0) {
        // 0x800D3E88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3EE8;
    }
    goto skip_0;
    // 0x800D3E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3E8C: jal         0x800C7C00
    // 0x800D3E90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D3E90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D3E94: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3E98: beq         $v0, $zero, L_800D3EE4
    if (ctx->r2 == 0) {
        // 0x800D3E9C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D3EE4;
    }
    // 0x800D3E9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3EA0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D3EA4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D3EA8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800D3EAC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D3EB0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D3EB4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D3EB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D3EBC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D3EC0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D3EC4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D3EC8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D3ECC: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800D3ED0: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800D3ED4: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800D3ED8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D3EDC: jalr        $t9
    // 0x800D3EE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D3EE0: nop

    after_1:
L_800D3EE4:
    // 0x800D3EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3EE8:
    // 0x800D3EE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3EEC: jr          $ra
    // 0x800D3EF0: nop

    return;
    // 0x800D3EF0: nop

;}
RECOMP_FUNC void func_800D3EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3EF4: nop

    // 0x800D3EF8: nop

    // 0x800D3EFC: nop

;}
RECOMP_FUNC void _allocatePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3F00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D3F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3F08: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D3F0C: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800D3F10: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800D3F14: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D3F18: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D3F1C: beq         $a3, $zero, L_800D3F54
    if (ctx->r7 == 0) {
        // 0x800D3F20: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D3F54;
    }
    // 0x800D3F20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D3F24: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D3F28: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D3F2C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D3F30: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D3F34: jal         0x800C7890
    // 0x800D3F38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800D3F38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800D3F3C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D3F40: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D3F44: jal         0x800C78C0
    // 0x800D3F48: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800D3F48: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x800D3F4C: b           L_800D3FD4
    // 0x800D3F50: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800D3FD4;
    // 0x800D3F50: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800D3F54:
    // 0x800D3F54: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800D3F58: beq         $a3, $zero, L_800D3F8C
    if (ctx->r7 == 0) {
        // 0x800D3F5C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800D3F8C;
    }
    // 0x800D3F5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D3F60: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D3F64: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D3F68: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D3F6C: jal         0x800C7890
    // 0x800D3F70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800D3F70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800D3F74: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D3F78: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D3F7C: jal         0x800C78C0
    // 0x800D3F80: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800D3F80: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800D3F84: b           L_800D3FD4
    // 0x800D3F88: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800D3FD4;
    // 0x800D3F88: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800D3F8C:
    // 0x800D3F8C: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800D3F90: beql        $a3, $zero, L_800D3FD8
    if (ctx->r7 == 0) {
        // 0x800D3F94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3FD8;
    }
    goto skip_0;
    // 0x800D3F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3F98: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_800D3F9C:
    // 0x800D3F9C: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x800D3FA0: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D3FA4: bnel        $at, $zero, L_800D3FCC
    if (ctx->r1 != 0) {
        // 0x800D3FA8: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800D3FCC;
    }
    goto skip_1;
    // 0x800D3FA8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800D3FAC: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x800D3FB0: bnel        $t1, $zero, L_800D3FCC
    if (ctx->r9 != 0) {
        // 0x800D3FB4: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800D3FCC;
    }
    goto skip_2;
    // 0x800D3FB4: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x800D3FB8: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D3FBC: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800D3FC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D3FC4: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x800D3FC8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_800D3FCC:
    // 0x800D3FCC: bnel        $a3, $zero, L_800D3F9C
    if (ctx->r7 != 0) {
        // 0x800D3FD0: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_800D3F9C;
    }
    goto skip_3;
    // 0x800D3FD0: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_800D3FD4:
    // 0x800D3FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3FD8:
    // 0x800D3FD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D3FDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D3FE0: jr          $ra
    // 0x800D3FE4: nop

    return;
    // 0x800D3FE4: nop

;}
RECOMP_FUNC void alSynAllocVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3FE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D3FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3FF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3FF4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D3FF8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D3FFC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800D4000: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D4004: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x800D4008: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x800D400C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800D4010: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x800D4014: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800D4018: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x800D401C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800D4020: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x800D4024: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x800D4028: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800D402C: jal         0x800D3F00
    // 0x800D4030: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _allocatePVoice(rdram, ctx);
        goto after_0;
    // 0x800D4030: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800D4034: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4038: beql        $t9, $zero, L_800D4110
    if (ctx->r25 == 0) {
        // 0x800D403C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800D4110;
    }
    goto skip_0;
    // 0x800D403C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800D4040: beq         $v0, $zero, L_800D40F4
    if (ctx->r2 == 0) {
        // 0x800D4044: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_800D40F4;
    }
    // 0x800D4044: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x800D4048: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x800D404C: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x800D4050: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4054: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800D4058: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800D405C: jal         0x800C7C00
    // 0x800D4060: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_1;
    // 0x800D4060: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x800D4064: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800D4068: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D406C: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x800D4070: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800D4074: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800D4078: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800D407C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800D4080: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4084: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D4088: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D408C: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x800D4090: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x800D4094: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800D4098: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D409C: jalr        $t9
    // 0x800D40A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D40A0: nop

    after_2:
    // 0x800D40A4: jal         0x800C7C00
    // 0x800D40A8: nop

    __allocParam(rdram, ctx);
        goto after_3;
    // 0x800D40A8: nop

    after_3:
    // 0x800D40AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D40B0: beq         $v0, $zero, L_800D40FC
    if (ctx->r2 == 0) {
        // 0x800D40B4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D40FC;
    }
    // 0x800D40B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D40B8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800D40BC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800D40C0: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800D40C4: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800D40C8: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x800D40CC: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800D40D0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D40D4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D40D8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800D40DC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D40E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D40E4: jalr        $t9
    // 0x800D40E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800D40E8: nop

    after_4:
    // 0x800D40EC: b           L_800D4100
    // 0x800D40F0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_800D4100;
    // 0x800D40F0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800D40F4:
    // 0x800D40F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D40F8: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_800D40FC:
    // 0x800D40FC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800D4100:
    // 0x800D4100: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x800D4104: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4108: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800D410C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800D4110:
    // 0x800D4110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4118: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800D411C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800D4120: jr          $ra
    // 0x800D4124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D4124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800D4128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4128: nop

    // 0x800D412C: nop

;}
RECOMP_FUNC void alSynStartVoiceParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D4134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4138: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D413C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D4140: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800D4144: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D4148: beql        $t6, $zero, L_800D4208
    if (ctx->r14 == 0) {
        // 0x800D414C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D4208;
    }
    goto skip_0;
    // 0x800D414C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D4150: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D4154: jal         0x800C7C00
    // 0x800D4158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D4158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D415C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D4160: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800D4164: beq         $v0, $zero, L_800D4204
    if (ctx->r2 == 0) {
        // 0x800D4168: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D4204;
    }
    // 0x800D4168: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D416C: lbu         $v1, 0x3B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D4170: bgez        $v1, L_800D4184
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D4174: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800D4184;
    }
    // 0x800D4174: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D4178: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x800D417C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x800D4180: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800D4184:
    // 0x800D4184: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D4188: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800D418C: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x800D4190: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D4194: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D4198: sh          $t2, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r10;
    // 0x800D419C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D41A0: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x800D41A4: lh          $t3, 0x1A($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1A);
    // 0x800D41A8: sh          $t3, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r11;
    // 0x800D41AC: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x800D41B0: sb          $t4, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r12;
    // 0x800D41B4: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x800D41B8: sb          $v1, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r3;
    // 0x800D41BC: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x800D41C0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D41C4: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x800D41C8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D41CC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800D41D0: jal         0x800C7AF8
    // 0x800D41D4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    _timeToSamples(rdram, ctx);
        goto after_1;
    // 0x800D41D4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800D41D8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800D41DC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800D41E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D41E4: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x800D41E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D41EC: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x800D41F0: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x800D41F4: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x800D41F8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D41FC: jalr        $t9
    // 0x800D4200: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D4200: nop

    after_2:
L_800D4204:
    // 0x800D4204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4208:
    // 0x800D4208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D420C: jr          $ra
    // 0x800D4210: nop

    return;
    // 0x800D4210: nop

;}
RECOMP_FUNC void func_800D4214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4214: nop

    // 0x800D4218: nop

    // 0x800D421C: nop

;}
RECOMP_FUNC void alSynSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D422C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D4230: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D4234: beql        $t6, $zero, L_800D4298
    if (ctx->r14 == 0) {
        // 0x800D4238: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D4298;
    }
    goto skip_0;
    // 0x800D4238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D423C: jal         0x800C7C00
    // 0x800D4240: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D4240: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D4244: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4248: beq         $v0, $zero, L_800D4294
    if (ctx->r2 == 0) {
        // 0x800D424C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D4294;
    }
    // 0x800D424C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D4250: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D4254: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D4258: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800D425C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D4260: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D4264: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D4268: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D426C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D4270: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D4274: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x800D4278: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D427C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D4280: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800D4284: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800D4288: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D428C: jalr        $t9
    // 0x800D4290: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D4290: nop

    after_1:
L_800D4294:
    // 0x800D4294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4298:
    // 0x800D4298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D429C: jr          $ra
    // 0x800D42A0: nop

    return;
    // 0x800D42A0: nop

;}
RECOMP_FUNC void func_800D42A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D42A4: nop

    // 0x800D42A8: nop

    // 0x800D42AC: nop

;}
RECOMP_FUNC void alSynSetFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D42B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D42B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D42B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D42BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D42C0: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D42C4: beql        $t6, $zero, L_800D4338
    if (ctx->r14 == 0) {
        // 0x800D42C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D4338;
    }
    goto skip_0;
    // 0x800D42C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D42CC: jal         0x800C7C00
    // 0x800D42D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D42D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D42D4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D42D8: beq         $v0, $zero, L_800D4334
    if (ctx->r2 == 0) {
        // 0x800D42DC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D4334;
    }
    // 0x800D42DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D42E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D42E4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D42E8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800D42EC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D42F0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D42F4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D42F8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D42FC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D4300: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x800D4304: bgez        $v1, L_800D4314
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D4308: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_800D4314;
    }
    // 0x800D4308: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800D430C: b           L_800D4318
    // 0x800D4310: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_800D4318;
    // 0x800D4310: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_800D4314:
    // 0x800D4314: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800D4318:
    // 0x800D4318: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D431C: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800D4320: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D4324: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800D4328: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D432C: jalr        $t9
    // 0x800D4330: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D4330: nop

    after_1:
L_800D4334:
    // 0x800D4334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4338:
    // 0x800D4338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D433C: jr          $ra
    // 0x800D4340: nop

    return;
    // 0x800D4340: nop

;}
RECOMP_FUNC void func_800D4344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4344: nop

    // 0x800D4348: nop

    // 0x800D434C: nop

;}
RECOMP_FUNC void alSynStartVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D435C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D4360: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D4364: beql        $t6, $zero, L_800D43D0
    if (ctx->r14 == 0) {
        // 0x800D4368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D43D0;
    }
    goto skip_0;
    // 0x800D4368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D436C: jal         0x800C7C00
    // 0x800D4370: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D4370: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D4374: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4378: beq         $v0, $zero, L_800D43CC
    if (ctx->r2 == 0) {
        // 0x800D437C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D43CC;
    }
    // 0x800D437C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D4380: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D4384: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D4388: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x800D438C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D4390: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D4394: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D4398: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D439C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D43A0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D43A4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D43A8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D43AC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D43B0: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x800D43B4: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x800D43B8: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x800D43BC: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x800D43C0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D43C4: jalr        $t9
    // 0x800D43C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D43C8: nop

    after_1:
L_800D43CC:
    // 0x800D43CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D43D0:
    // 0x800D43D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D43D4: jr          $ra
    // 0x800D43D8: nop

    return;
    // 0x800D43D8: nop

;}
RECOMP_FUNC void func_800D43DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D43DC: nop

    // 0x800D43E0: nop

    // 0x800D43E4: nop

    // 0x800D43E8: nop

    // 0x800D43EC: nop

    // 0x800D43F0: nop

    // 0x800D43F4: nop

    // 0x800D43F8: nop

    // 0x800D43FC: nop

    // 0x800D4400: nop

    // 0x800D4404: nop

    // 0x800D4408: nop

    // 0x800D440C: nop

    // 0x800D4410: nop

    // 0x800D4414: nop

    // 0x800D4418: nop

    // 0x800D441C: nop

;}
RECOMP_FUNC void func_800D443C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D443C: nop

;}
RECOMP_FUNC void func_800D44EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D44EC: nop

;}
