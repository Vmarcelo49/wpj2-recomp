#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800783EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800783EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800783F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800783F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800783F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800783FC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80078400: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80078404: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80078408: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8007840C: lh          $t7, 0x14($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X14);
    // 0x80078410: nop

    // 0x80078414: bne         $t7, $at, L_80078424
    if (ctx->r15 != ctx->r1) {
        // 0x80078418: nop
    
            goto L_80078424;
    }
    // 0x80078418: nop

    // 0x8007841C: b           L_80078484
    // 0x80078420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078484;
    // 0x80078420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078424:
    // 0x80078424: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80078428: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007842C: lh          $a3, 0x14($t8)
    ctx->r7 = MEM_H(ctx->r24, 0X14);
    // 0x80078430: lw          $a2, 0xA0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XA0);
    // 0x80078434: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80078438: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x8007843C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80078440: addiu       $a1, $t8, 0x20
    ctx->r5 = ADD32(ctx->r24, 0X20);
    // 0x80078444: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80078448: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007844C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80078450: jal         0x80078628
    // 0x80078454: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80078628(rdram, ctx);
        goto after_0;
    // 0x80078454: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x80078458: bne         $v0, $zero, L_80078474
    if (ctx->r2 != 0) {
        // 0x8007845C: nop
    
            goto L_80078474;
    }
    // 0x8007845C: nop

    // 0x80078460: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80078464: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80078468: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x8007846C: b           L_80078484
    // 0x80078470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078484;
    // 0x80078470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078474:
    // 0x80078474: b           L_80078484
    // 0x80078478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078484;
    // 0x80078478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007847C: b           L_80078484
    // 0x80078480: nop

        goto L_80078484;
    // 0x80078480: nop

L_80078484:
    // 0x80078484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078488: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007848C: jr          $ra
    // 0x80078490: nop

    return;
    // 0x80078490: nop

;}
RECOMP_FUNC void func_80063118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006311C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063120: jal         0x80061488
    // 0x80063124: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063124: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x80063128: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006312C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80063130: b           L_80063140
    // 0x80063134: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063140;
    // 0x80063134: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063138: b           L_80063140
    // 0x8006313C: nop

        goto L_80063140;
    // 0x8006313C: nop

L_80063140:
    // 0x80063140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063148: jr          $ra
    // 0x8006314C: nop

    return;
    // 0x8006314C: nop

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
RECOMP_FUNC void func_80037344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037344: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80037348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003734C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80037350: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80037354: lw          $t6, 0x103C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X103C);
    // 0x80037358: nop

    // 0x8003735C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80037360: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80037364: lw          $t7, 0x7278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7278);
    // 0x80037368: nop

    // 0x8003736C: lhu         $t8, 0x1C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X1C);
    // 0x80037370: nop

    // 0x80037374: sh          $t8, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r24;
    // 0x80037378: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8003737C: nop

    // 0x80037380: lbu         $t0, 0x1A8($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1A8);
    // 0x80037384: nop

    // 0x80037388: sh          $t0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r8;
    // 0x8003738C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80037390: nop

    // 0x80037394: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80037398: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8003739C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800373A0: nop

    // 0x800373A4: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800373A8: nop

    // 0x800373AC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800373B0: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800373B4: nop

    // 0x800373B8: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800373BC: beq         $at, $zero, L_800373D0
    if (ctx->r1 == 0) {
        // 0x800373C0: nop
    
            goto L_800373D0;
    }
    // 0x800373C0: nop

    // 0x800373C4: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800373C8: b           L_800373D8
    // 0x800373CC: sh          $t5, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r13;
        goto L_800373D8;
    // 0x800373CC: sh          $t5, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r13;
L_800373D0:
    // 0x800373D0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800373D4: sh          $t6, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r14;
L_800373D8:
    // 0x800373D8: lh          $s0, 0x36($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X36);
    // 0x800373DC: nop

    // 0x800373E0: beq         $s0, $zero, L_80037408
    if (ctx->r16 == 0) {
        // 0x800373E4: nop
    
            goto L_80037408;
    }
    // 0x800373E4: nop

    // 0x800373E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800373EC: beq         $s0, $at, L_80037434
    if (ctx->r16 == ctx->r1) {
        // 0x800373F0: nop
    
            goto L_80037434;
    }
    // 0x800373F0: nop

    // 0x800373F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800373F8: beq         $s0, $at, L_80037494
    if (ctx->r16 == ctx->r1) {
        // 0x800373FC: nop
    
            goto L_80037494;
    }
    // 0x800373FC: nop

    // 0x80037400: b           L_800374F4
    // 0x80037404: nop

        goto L_800374F4;
    // 0x80037404: nop

L_80037408:
    // 0x80037408: lh          $t7, 0x34($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X34);
    // 0x8003740C: nop

    // 0x80037410: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80037414: beq         $at, $zero, L_8003742C
    if (ctx->r1 == 0) {
        // 0x80037418: nop
    
            goto L_8003742C;
    }
    // 0x80037418: nop

    // 0x8003741C: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x80037420: nop

    // 0x80037424: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80037428: sh          $t9, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r25;
L_8003742C:
    // 0x8003742C: b           L_800374F4
    // 0x80037430: nop

        goto L_800374F4;
    // 0x80037430: nop

L_80037434:
    // 0x80037434: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x80037438: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003743C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80037440: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80037444: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037448: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003744C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80037450: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80037454: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037458: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003745C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80037460: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80037464: bc1f        L_8003748C
    if (!c1cs) {
        // 0x80037468: nop
    
            goto L_8003748C;
    }
    // 0x80037468: nop

    // 0x8003746C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80037470: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037474: nop

    // 0x80037478: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8003747C: lh          $t1, 0x36($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X36);
    // 0x80037480: nop

    // 0x80037484: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80037488: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
L_8003748C:
    // 0x8003748C: b           L_800374F4
    // 0x80037490: nop

        goto L_800374F4;
    // 0x80037490: nop

L_80037494:
    // 0x80037494: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x80037498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003749C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800374A0: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800374A4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800374A8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800374AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800374B0: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800374B4: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800374B8: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x800374BC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800374C0: bc1f        L_800374EC
    if (!c1cs) {
        // 0x800374C4: nop
    
            goto L_800374EC;
    }
    // 0x800374C4: nop

    // 0x800374C8: jal         0x800B9000
    // 0x800374CC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x800374CC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
    // 0x800374D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800374D4: nop

    // 0x800374D8: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800374DC: lh          $t4, 0x36($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X36);
    // 0x800374E0: nop

    // 0x800374E4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800374E8: sh          $t5, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r13;
L_800374EC:
    // 0x800374EC: b           L_800374F4
    // 0x800374F0: nop

        goto L_800374F4;
    // 0x800374F0: nop

L_800374F4:
    // 0x800374F4: lh          $t6, 0x36($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X36);
    // 0x800374F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800374FC: nop

    // 0x80037500: sb          $t6, 0x1A8($t7)
    MEM_B(0X1A8, ctx->r15) = ctx->r14;
    // 0x80037504: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80037508: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8003750C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80037510: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x80037514: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80037518: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8003751C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037520: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037524: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80037528: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8003752C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037530: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80037534: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80037538: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8003753C: sh          $t2, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r10;
    // 0x80037540: jal         0x800C1850
    // 0x80037544: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_1;
    // 0x80037544: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80037548: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003754C: jal         0x8009A14C
    // 0x80037550: nop

    func_8009A14C(rdram, ctx);
        goto after_2;
    // 0x80037550: nop

    after_2:
    // 0x80037554: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80037558: jal         0x800997D8
    // 0x8003755C: nop

    func_800997D8(rdram, ctx);
        goto after_3;
    // 0x8003755C: nop

    after_3:
    // 0x80037560: b           L_80037568
    // 0x80037564: nop

        goto L_80037568;
    // 0x80037564: nop

L_80037568:
    // 0x80037568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003756C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037570: jr          $ra
    // 0x80037574: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80037574: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800688BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800688C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800688C4: jal         0x80061488
    // 0x800688C8: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800688C8: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    after_0:
    // 0x800688CC: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800688D0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800688D4: b           L_800688E4
    // 0x800688D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800688E4;
    // 0x800688D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800688DC: b           L_800688E4
    // 0x800688E0: nop

        goto L_800688E4;
    // 0x800688E0: nop

L_800688E4:
    // 0x800688E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800688E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800688EC: jr          $ra
    // 0x800688F0: nop

    return;
    // 0x800688F0: nop

;}
RECOMP_FUNC void func_80033614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033614: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80033618: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003361C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80033620: addiu       $t6, $t6, -0x4BA0
    ctx->r14 = ADD32(ctx->r14, -0X4BA0);
    // 0x80033624: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80033628: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8003362C: lw          $t7, -0x4780($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4780);
    // 0x80033630: nop

    // 0x80033634: bne         $t7, $zero, L_80033738
    if (ctx->r15 != 0) {
        // 0x80033638: nop
    
            goto L_80033738;
    }
    // 0x80033638: nop

    // 0x8003363C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80033640: lw          $t8, -0x4780($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4780);
    // 0x80033644: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033648: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003364C: sw          $t9, -0x4780($at)
    MEM_W(-0X4780, ctx->r1) = ctx->r25;
    // 0x80033650: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80033654:
    // 0x80033654: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80033658:
    // 0x80033658: jal         0x800C4240
    // 0x8003365C: nop

    guRandom(rdram, ctx);
        goto after_0;
    // 0x8003365C: nop

    after_0:
    // 0x80033660: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80033664: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80033668: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8003366C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80033670: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80033674: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80033678: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8003367C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80033680: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80033684: mfhi        $t0
    ctx->r8 = hi;
    // 0x80033688: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8003368C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80033690: sh          $t2, -0x4A88($at)
    MEM_H(-0X4A88, ctx->r1) = ctx->r10;
    // 0x80033694: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80033698: nop

    // 0x8003369C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800336A0: slti        $at, $t9, 0x40
    ctx->r1 = SIGNED(ctx->r25) < 0X40 ? 1 : 0;
    // 0x800336A4: bne         $at, $zero, L_80033658
    if (ctx->r1 != 0) {
        // 0x800336A8: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80033658;
    }
    // 0x800336A8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800336AC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800336B0: nop

    // 0x800336B4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800336B8: slti        $at, $t1, 0x20
    ctx->r1 = SIGNED(ctx->r9) < 0X20 ? 1 : 0;
    // 0x800336BC: bne         $at, $zero, L_80033654
    if (ctx->r1 != 0) {
        // 0x800336C0: sw          $t1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r9;
            goto L_80033654;
    }
    // 0x800336C0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800336C4: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800336C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800336CC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800336D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800336D4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800336D8: addiu       $t3, $t3, -0x4A88
    ctx->r11 = ADD32(ctx->r11, -0X4A88);
    // 0x800336DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800336E0: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x800336E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800336E8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800336EC: addiu       $a1, $zero, -0x80
    ctx->r5 = ADD32(0, -0X80);
    // 0x800336F0: addiu       $a2, $zero, -0x80
    ctx->r6 = ADD32(0, -0X80);
    // 0x800336F4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800336F8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800336FC: jal         0x8003276C
    // 0x80033700: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_8003276C(rdram, ctx);
        goto after_1;
    // 0x80033700: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80033704: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80033708: nop

    // 0x8003370C: lw          $t6, 0xC0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC0);
    // 0x80033710: nop

    // 0x80033714: ori         $t2, $t6, 0x800
    ctx->r10 = ctx->r14 | 0X800;
    // 0x80033718: sw          $t2, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r10;
    // 0x8003371C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80033720: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80033724: sh          $t7, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r15;
    // 0x80033728: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8003372C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80033730: jal         0x80032844
    // 0x80033734: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_80032844(rdram, ctx);
        goto after_2;
    // 0x80033734: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_2:
L_80033738:
    // 0x80033738: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8003373C: jal         0x8003288C
    // 0x80033740: nop

    func_8003288C(rdram, ctx);
        goto after_3;
    // 0x80033740: nop

    after_3:
    // 0x80033744: jal         0x800C1754
    // 0x80033748: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_4;
    // 0x80033748: nop

    after_4:
    // 0x8003374C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80033750: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80033754: jal         0x800C2304
    // 0x80033758: lui         $a2, 0xC220
    ctx->r6 = S32(0XC220 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_5;
    // 0x80033758: lui         $a2, 0xC220
    ctx->r6 = S32(0XC220 << 16);
    after_5:
    // 0x8003375C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80033760: jal         0x800A4638
    // 0x80033764: nop

    func_800A4638(rdram, ctx);
        goto after_6;
    // 0x80033764: nop

    after_6:
    // 0x80033768: jal         0x800C1A28
    // 0x8003376C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_7;
    // 0x8003376C: nop

    after_7:
    // 0x80033770: b           L_80033778
    // 0x80033774: nop

        goto L_80033778;
    // 0x80033774: nop

L_80033778:
    // 0x80033778: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003377C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80033780: jr          $ra
    // 0x80033784: nop

    return;
    // 0x80033784: nop

;}
RECOMP_FUNC void func_8000B2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B2DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000B2E0: bltz        $a1, L_8000B328
    if (SIGNED(ctx->r5) < 0) {
        // 0x8000B2E4: nop
    
            goto L_8000B328;
    }
    // 0x8000B2E4: nop

    // 0x8000B2E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8000B2EC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000B2F0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000B2F4: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x8000B2F8: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8000B2FC: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8000B300: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8000B304: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000B308: and         $t1, $t0, $t8
    ctx->r9 = ctx->r8 & ctx->r24;
    // 0x8000B30C: beq         $t1, $zero, L_8000B328
    if (ctx->r9 == 0) {
        // 0x8000B310: nop
    
            goto L_8000B328;
    }
    // 0x8000B310: nop

    // 0x8000B314: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000B318: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000B31C: sw          $t2, -0x5B20($at)
    MEM_W(-0X5B20, ctx->r1) = ctx->r10;
    // 0x8000B320: b           L_8000B338
    // 0x8000B324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000B338;
    // 0x8000B324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000B328:
    // 0x8000B328: b           L_8000B338
    // 0x8000B32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B338;
    // 0x8000B32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000B330: b           L_8000B338
    // 0x8000B334: nop

        goto L_8000B338;
    // 0x8000B334: nop

L_8000B338:
    // 0x8000B338: jr          $ra
    // 0x8000B33C: nop

    return;
    // 0x8000B33C: nop

;}
RECOMP_FUNC void func_8007559C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007559C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800755A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800755A4: nop

    // 0x800755A8: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800755AC: nop

    // 0x800755B0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800755B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800755B8: jr          $ra
    // 0x800755BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800755BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800755C0: jr          $ra
    // 0x800755C4: nop

    return;
    // 0x800755C4: nop

    // 0x800755C8: jr          $ra
    // 0x800755CC: nop

    return;
    // 0x800755CC: nop

;}
RECOMP_FUNC void func_8003547C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003547C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80035480: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80035484: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80035488: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003548C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80035490: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80035494: lw          $t6, 0x726C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X726C);
    // 0x80035498: nop

    // 0x8003549C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800354A0: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
    // 0x800354A4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800354A8: nop

    // 0x800354AC: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800354B0: nop

    // 0x800354B4: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x800354B8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800354BC: nop

    // 0x800354C0: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800354C4: nop

    // 0x800354C8: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800354CC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800354D0: nop

    // 0x800354D4: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800354D8: nop

    // 0x800354DC: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x800354E0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800354E4: nop

    // 0x800354E8: lbu         $t1, 0x1C8($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1C8);
    // 0x800354EC: nop

    // 0x800354F0: sh          $t1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r9;
    // 0x800354F4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800354F8: nop

    // 0x800354FC: lbu         $t3, 0x1C9($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1C9);
    // 0x80035500: nop

    // 0x80035504: sh          $t3, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r11;
    // 0x80035508: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8003550C: nop

    // 0x80035510: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80035514: nop

    // 0x80035518: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x8003551C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80035520: nop

    // 0x80035524: addiu       $t6, $t5, 0x28
    ctx->r14 = ADD32(ctx->r13, 0X28);
    // 0x80035528: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8003552C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80035530: nop

    // 0x80035534: addiu       $t8, $t7, 0x188
    ctx->r24 = ADD32(ctx->r15, 0X188);
    // 0x80035538: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8003553C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80035540: nop

    // 0x80035544: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80035548: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003554C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80035550: nop

    // 0x80035554: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80035558: nop

    // 0x8003555C: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80035560: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80035564: nop

    // 0x80035568: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8003556C: nop

    // 0x80035570: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x80035574: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80035578: nop

    // 0x8003557C: lwc1        $f4, 0x8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80035580: nop

    // 0x80035584: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x80035588: lhu         $t4, 0x88($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X88);
    // 0x8003558C: nop

    // 0x80035590: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80035594: beq         $at, $zero, L_80035B90
    if (ctx->r1 == 0) {
        // 0x80035598: nop
    
            goto L_80035B90;
    }
    // 0x80035598: nop

    // 0x8003559C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800355A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800355A4: addu        $at, $at, $t4
    gpr jr_addend_800355B0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800355A8: lw          $t4, -0x1660($at)
    ctx->r12 = ADD32(ctx->r1, -0X1660);
    // 0x800355AC: nop

    // 0x800355B0: jr          $t4
    // 0x800355B4: nop

    switch (jr_addend_800355B0 >> 2) {
        case 0: goto L_800355B8; break;
        case 1: goto L_8003579C; break;
        case 2: goto L_8003593C; break;
        case 3: goto L_80035974; break;
        case 4: goto L_8003597C; break;
        case 5: goto L_800359A4; break;
        case 6: goto L_800359B4; break;
        case 7: goto L_800359DC; break;
        default: switch_error(__func__, 0x800355B0, 0x800EE9A0);
    }
    // 0x800355B4: nop

L_800355B8:
    // 0x800355B8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800355BC: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x800355C0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800355C4: lhu         $t7, 0x10F2($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X10F2);
    // 0x800355C8: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x800355CC: nop

    // 0x800355D0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800355D4: beq         $t8, $zero, L_80035794
    if (ctx->r24 == 0) {
        // 0x800355D8: nop
    
            goto L_80035794;
    }
    // 0x800355D8: nop

    // 0x800355DC: lh          $t9, 0x92($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X92);
    // 0x800355E0: nop

    // 0x800355E4: bne         $t9, $zero, L_80035794
    if (ctx->r25 != 0) {
        // 0x800355E8: nop
    
            goto L_80035794;
    }
    // 0x800355E8: nop

    // 0x800355EC: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x800355F0: lbu         $t0, -0x69F8($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X69F8);
    // 0x800355F4: nop

    // 0x800355F8: beq         $t0, $zero, L_80035794
    if (ctx->r8 == 0) {
        // 0x800355FC: nop
    
            goto L_80035794;
    }
    // 0x800355FC: nop

    // 0x80035600: jal         0x800B9000
    // 0x80035604: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x80035604: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_0:
    // 0x80035608: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003560C: nop

    // 0x80035610: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80035614: lhu         $t1, 0x8A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X8A);
    // 0x80035618: nop

    // 0x8003561C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80035620: sh          $t2, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r10;
    // 0x80035624: addiu       $t3, $zero, 0x1E6
    ctx->r11 = ADD32(0, 0X1E6);
    // 0x80035628: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x8003562C: jal         0x800C1850
    // 0x80035630: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_1;
    // 0x80035630: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80035634: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80035638: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x8003563C: nop

    // 0x80035640: lwc1        $f12, 0x0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80035644: lwc1        $f14, 0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80035648: lw          $a2, 0x8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X8);
    // 0x8003564C: jal         0x800C2304
    // 0x80035650: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_2;
    // 0x80035650: nop

    after_2:
    // 0x80035654: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80035658: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x8003565C: nop

    // 0x80035660: lwc1        $f8, 0x10($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X10);
    // 0x80035664: nop

    // 0x80035668: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8003566C: jal         0x800C25B8
    // 0x80035670: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x80035670: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    after_3:
    // 0x80035674: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80035678: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x8003567C: nop

    // 0x80035680: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80035684: nop

    // 0x80035688: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8003568C: jal         0x800C23E8
    // 0x80035690: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x80035690: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    after_4:
    // 0x80035694: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80035698: lw          $t7, -0x4CCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CCC);
    // 0x8003569C: addiu       $t8, $zero, -0x3
    ctx->r24 = ADD32(0, -0X3);
    // 0x800356A0: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800356A4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800356A8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800356AC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800356B0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800356B4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800356B8: jal         0x800C2304
    // 0x800356BC: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_5;
    // 0x800356BC: nop

    after_5:
    // 0x800356C0: jal         0x800B1844
    // 0x800356C4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800B1844(rdram, ctx);
        goto after_6;
    // 0x800356C4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x800356C8: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x800356CC: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800356D0: nop

    // 0x800356D4: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800356D8: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x800356DC: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800356E0: nop

    // 0x800356E4: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x800356E8: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800356EC: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800356F0: nop

    // 0x800356F4: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800356F8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800356FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80035700: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80035704: jal         0x800C2304
    // 0x80035708: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_7;
    // 0x80035708: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_7:
    // 0x8003570C: jal         0x800B1844
    // 0x80035710: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800B1844(rdram, ctx);
        goto after_8;
    // 0x80035710: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_8:
    // 0x80035714: jal         0x800C1850
    // 0x80035718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_9;
    // 0x80035718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8003571C: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80035720: jal         0x800C25B8
    // 0x80035724: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_10;
    // 0x80035724: nop

    after_10:
    // 0x80035728: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003572C: jal         0x800C23E8
    // 0x80035730: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_11;
    // 0x80035730: nop

    after_11:
    // 0x80035734: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80035738: lwc1        $f14, -0x1640($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1640);
    // 0x8003573C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80035740: jal         0x800C2304
    // 0x80035744: lui         $a2, 0xC020
    ctx->r6 = S32(0XC020 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_12;
    // 0x80035744: lui         $a2, 0xC020
    ctx->r6 = S32(0XC020 << 16);
    after_12:
    // 0x80035748: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8003574C: jal         0x800B1844
    // 0x80035750: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800B1844(rdram, ctx);
        goto after_13;
    // 0x80035750: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_13:
    // 0x80035754: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x80035758: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8003575C: nop

    // 0x80035760: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80035764: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x80035768: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8003576C: nop

    // 0x80035770: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x80035774: addiu       $t5, $sp, 0x48
    ctx->r13 = ADD32(ctx->r29, 0X48);
    // 0x80035778: lwc1        $f16, 0x8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8003577C: nop

    // 0x80035780: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    // 0x80035784: lhu         $t6, 0x88($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X88);
    // 0x80035788: nop

    // 0x8003578C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80035790: sh          $t8, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r24;
L_80035794:
    // 0x80035794: b           L_80035B90
    // 0x80035798: nop

        goto L_80035B90;
    // 0x80035798: nop

L_8003579C:
    // 0x8003579C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800357A0: nop

    // 0x800357A4: addiu       $t9, $t7, 0x1C
    ctx->r25 = ADD32(ctx->r15, 0X1C);
    // 0x800357A8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800357AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800357B0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800357B4: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800357B8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800357BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800357C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800357C4: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800357C8: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800357CC: bc1t        L_80035868
    if (c1cs) {
        // 0x800357D0: nop
    
            goto L_80035868;
    }
    // 0x800357D0: nop

    // 0x800357D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800357D8: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800357DC: lwc1        $f19, -0x1638($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1638);
    // 0x800357E0: lwc1        $f18, -0x1634($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1634);
    // 0x800357E4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800357E8: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x800357EC: nop

    // 0x800357F0: bc1t        L_80035868
    if (c1cs) {
        // 0x800357F4: nop
    
            goto L_80035868;
    }
    // 0x800357F4: nop

    // 0x800357F8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800357FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035800: nop

    // 0x80035804: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80035808: nop

    // 0x8003580C: bc1t        L_80035868
    if (c1cs) {
        // 0x80035810: nop
    
            goto L_80035868;
    }
    // 0x80035810: nop

    // 0x80035814: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80035818: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8003581C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80035820: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80035824: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80035828: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003582C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035830: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80035834: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80035838: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003583C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80035840: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80035844: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80035848: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003584C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80035850: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035854: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80035858: jal         0x80034CA0
    // 0x8003585C: nop

    func_80034CA0(rdram, ctx);
        goto after_14;
    // 0x8003585C: nop

    after_14:
    // 0x80035860: beq         $v0, $zero, L_8003588C
    if (ctx->r2 == 0) {
        // 0x80035864: nop
    
            goto L_8003588C;
    }
    // 0x80035864: nop

L_80035868:
    // 0x80035868: lhu         $t1, 0x8A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X8A);
    // 0x8003586C: nop

    // 0x80035870: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80035874: sh          $t2, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r10;
    // 0x80035878: addiu       $t3, $zero, 0x1E8
    ctx->r11 = ADD32(0, 0X1E8);
    // 0x8003587C: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x80035880: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80035884: b           L_80035934
    // 0x80035888: sh          $t4, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r12;
        goto L_80035934;
    // 0x80035888: sh          $t4, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r12;
L_8003588C:
    // 0x8003588C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80035890: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80035894: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80035898: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003589C: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800358A0: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800358A4: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800358A8: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x800358AC: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x800358B0: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800358B4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800358B8: nop

    // 0x800358BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800358C0: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800358C4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800358C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800358CC: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800358D0: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800358D4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800358D8: mul.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800358DC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800358E0: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x800358E4: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800358E8: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800358EC: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800358F0: nop

    // 0x800358F4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800358F8: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x800358FC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80035900: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80035904: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80035908: lwc1        $f18, 0x8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8003590C: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80035910: mul.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80035914: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80035918: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x8003591C: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x80035920: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80035924: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80035928: nop

    // 0x8003592C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80035930: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
L_80035934:
    // 0x80035934: b           L_80035B90
    // 0x80035938: nop

        goto L_80035B90;
    // 0x80035938: nop

L_8003593C:
    // 0x8003593C: jal         0x800220F4
    // 0x80035940: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800220F4(rdram, ctx);
        goto after_15;
    // 0x80035940: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_15:
    // 0x80035944: lhu         $t7, 0x8A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X8A);
    // 0x80035948: nop

    // 0x8003594C: ori         $t9, $t7, 0x1
    ctx->r25 = ctx->r15 | 0X1;
    // 0x80035950: sh          $t9, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r25;
    // 0x80035954: addiu       $t0, $zero, 0x1E7
    ctx->r8 = ADD32(0, 0X1E7);
    // 0x80035958: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8003595C: lhu         $t1, 0x88($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X88);
    // 0x80035960: nop

    // 0x80035964: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80035968: sh          $t2, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r10;
    // 0x8003596C: b           L_80035B90
    // 0x80035970: nop

        goto L_80035B90;
    // 0x80035970: nop

L_80035974:
    // 0x80035974: b           L_80035B90
    // 0x80035978: nop

        goto L_80035B90;
    // 0x80035978: nop

L_8003597C:
    // 0x8003597C: lhu         $t3, 0x8A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X8A);
    // 0x80035980: nop

    // 0x80035984: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80035988: sh          $t4, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r12;
    // 0x8003598C: addiu       $t5, $zero, 0x1E9
    ctx->r13 = ADD32(0, 0X1E9);
    // 0x80035990: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
    // 0x80035994: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80035998: sh          $t6, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r14;
    // 0x8003599C: b           L_80035B90
    // 0x800359A0: nop

        goto L_80035B90;
    // 0x800359A0: nop

L_800359A4:
    // 0x800359A4: jal         0x800220F4
    // 0x800359A8: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800220F4(rdram, ctx);
        goto after_16;
    // 0x800359A8: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_16:
    // 0x800359AC: b           L_80035B90
    // 0x800359B0: nop

        goto L_80035B90;
    // 0x800359B0: nop

L_800359B4:
    // 0x800359B4: lhu         $t8, 0x8A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X8A);
    // 0x800359B8: nop

    // 0x800359BC: ori         $t7, $t8, 0x1
    ctx->r15 = ctx->r24 | 0X1;
    // 0x800359C0: sh          $t7, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r15;
    // 0x800359C4: addiu       $t9, $zero, 0x1EA
    ctx->r25 = ADD32(0, 0X1EA);
    // 0x800359C8: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    // 0x800359CC: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800359D0: sh          $t0, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r8;
    // 0x800359D4: b           L_80035B90
    // 0x800359D8: nop

        goto L_80035B90;
    // 0x800359D8: nop

L_800359DC:
    // 0x800359DC: jal         0x800C1850
    // 0x800359E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_17;
    // 0x800359E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800359E4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800359E8: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x800359EC: nop

    // 0x800359F0: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800359F4: lwc1        $f14, 0x4($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800359F8: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x800359FC: jal         0x800C2304
    // 0x80035A00: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_18;
    // 0x80035A00: nop

    after_18:
    // 0x80035A04: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80035A08: lw          $t2, 0x7278($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7278);
    // 0x80035A0C: nop

    // 0x80035A10: lwc1        $f12, 0x10($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80035A14: jal         0x800C25B8
    // 0x80035A18: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_19;
    // 0x80035A18: nop

    after_19:
    // 0x80035A1C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80035A20: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x80035A24: nop

    // 0x80035A28: lwc1        $f12, 0xC($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80035A2C: jal         0x800C23E8
    // 0x80035A30: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_20;
    // 0x80035A30: nop

    after_20:
    // 0x80035A34: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80035A38: lw          $t4, -0x4CCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CCC);
    // 0x80035A3C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80035A40: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80035A44: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80035A48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80035A4C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035A50: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80035A54: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80035A58: jal         0x800C2304
    // 0x80035A5C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_21;
    // 0x80035A5C: nop

    after_21:
    // 0x80035A60: jal         0x800B1844
    // 0x80035A64: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800B1844(rdram, ctx);
        goto after_22;
    // 0x80035A64: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_22:
    // 0x80035A68: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80035A6C: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80035A70: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80035A74: nop

    // 0x80035A78: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80035A7C: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x80035A80: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x80035A84: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80035A88: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80035A8C: nop

    // 0x80035A90: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035A94: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x80035A98: addiu       $t7, $sp, 0x48
    ctx->r15 = ADD32(ctx->r29, 0X48);
    // 0x80035A9C: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80035AA0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80035AA4: nop

    // 0x80035AA8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80035AAC: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80035AB0: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80035AB4: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80035AB8: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80035ABC: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80035AC0: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80035AC4: nop

    // 0x80035AC8: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80035ACC: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80035AD0: jal         0x800C42A0
    // 0x80035AD4: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_23;
    // 0x80035AD4: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    after_23:
    // 0x80035AD8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80035ADC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80035AE0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80035AE4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80035AE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80035AEC: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80035AF0: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80035AF4: nop

    // 0x80035AF8: bc1f        L_80035B08
    if (!c1cs) {
        // 0x80035AFC: nop
    
            goto L_80035B08;
    }
    // 0x80035AFC: nop

    // 0x80035B00: b           L_80035B88
    // 0x80035B04: sh          $zero, 0x88($sp)
    MEM_H(0X88, ctx->r29) = 0;
        goto L_80035B88;
    // 0x80035B04: sh          $zero, 0x88($sp)
    MEM_H(0X88, ctx->r29) = 0;
L_80035B08:
    // 0x80035B08: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80035B0C: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x80035B10: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80035B14: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80035B18: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80035B1C: nop

    // 0x80035B20: div.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x80035B24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80035B28: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80035B2C: nop

    // 0x80035B30: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80035B34: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80035B38: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80035B3C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80035B40: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80035B44: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80035B48: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80035B4C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80035B50: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80035B54: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80035B58: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80035B5C: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80035B60: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80035B64: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80035B68: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80035B6C: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80035B70: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80035B74: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80035B78: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80035B7C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80035B80: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80035B84: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
L_80035B88:
    // 0x80035B88: b           L_80035B90
    // 0x80035B8C: nop

        goto L_80035B90;
    // 0x80035B8C: nop

L_80035B90:
    // 0x80035B90: lhu         $t9, 0x88($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X88);
    // 0x80035B94: nop

    // 0x80035B98: beq         $t9, $zero, L_80035C3C
    if (ctx->r25 == 0) {
        // 0x80035B9C: nop
    
            goto L_80035C3C;
    }
    // 0x80035B9C: nop

    // 0x80035BA0: lhu         $t0, 0x8A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X8A);
    // 0x80035BA4: nop

    // 0x80035BA8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80035BAC: beq         $t1, $zero, L_80035BE8
    if (ctx->r9 == 0) {
        // 0x80035BB0: nop
    
            goto L_80035BE8;
    }
    // 0x80035BB0: nop

    // 0x80035BB4: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80035BB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80035BBC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80035BC0: lui         $at, 0x69
    ctx->r1 = S32(0X69 << 16);
    // 0x80035BC4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80035BC8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80035BCC: or          $t2, $a2, $at
    ctx->r10 = ctx->r6 | ctx->r1;
    // 0x80035BD0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80035BD4: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    // 0x80035BD8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80035BDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80035BE0: jal         0x800B1F0C
    // 0x80035BE4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_24;
    // 0x80035BE4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_24:
L_80035BE8:
    // 0x80035BE8: jal         0x800C1850
    // 0x80035BEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_25;
    // 0x80035BEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x80035BF0: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80035BF4: lwc1        $f14, 0x7C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80035BF8: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80035BFC: jal         0x800C2304
    // 0x80035C00: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_26;
    // 0x80035C00: nop

    after_26:
    // 0x80035C04: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80035C08: jal         0x800997D8
    // 0x80035C0C: nop

    func_800997D8(rdram, ctx);
        goto after_27;
    // 0x80035C0C: nop

    after_27:
    // 0x80035C10: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80035C14: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80035C18: jal         0x800B26E0
    // 0x80035C1C: nop

    func_800B26E0(rdram, ctx);
        goto after_28;
    // 0x80035C1C: nop

    after_28:
    // 0x80035C20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80035C24: bne         $v0, $at, L_80035C3C
    if (ctx->r2 != ctx->r1) {
        // 0x80035C28: nop
    
            goto L_80035C3C;
    }
    // 0x80035C28: nop

    // 0x80035C2C: lhu         $t3, 0x88($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X88);
    // 0x80035C30: nop

    // 0x80035C34: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80035C38: sh          $t4, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r12;
L_80035C3C:
    // 0x80035C3C: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80035C40: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80035C44: nop

    // 0x80035C48: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80035C4C: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80035C50: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80035C54: nop

    // 0x80035C58: swc1        $f6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f6.u32l;
    // 0x80035C5C: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80035C60: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80035C64: nop

    // 0x80035C68: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80035C6C: lhu         $t7, 0x88($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X88);
    // 0x80035C70: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80035C74: nop

    // 0x80035C78: sb          $t7, 0x1C8($t9)
    MEM_B(0X1C8, ctx->r25) = ctx->r15;
    // 0x80035C7C: lhu         $t0, 0x86($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X86);
    // 0x80035C80: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80035C84: nop

    // 0x80035C88: sb          $t0, 0x1C9($t1)
    MEM_B(0X1C9, ctx->r9) = ctx->r8;
    // 0x80035C8C: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80035C90: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80035C94: nop

    // 0x80035C98: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x80035C9C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80035CA0: nop

    // 0x80035CA4: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x80035CA8: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80035CAC: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80035CB0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80035CB4: nop

    // 0x80035CB8: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x80035CBC: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80035CC0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80035CC4: nop

    // 0x80035CC8: swc1        $f8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f8.u32l;
    // 0x80035CCC: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80035CD0: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80035CD4: nop

    // 0x80035CD8: swc1        $f10, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f10.u32l;
    // 0x80035CDC: b           L_80035CE4
    // 0x80035CE0: nop

        goto L_80035CE4;
    // 0x80035CE0: nop

L_80035CE4:
    // 0x80035CE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80035CE8: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80035CEC: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80035CF0: jr          $ra
    // 0x80035CF4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80035CF4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8006765C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006765C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067660: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067664: nop

    // 0x80067668: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x8006766C: nop

    // 0x80067670: slti        $t7, $v0, 0x96
    ctx->r15 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067674: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067678: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006767C: beq         $v0, $zero, L_80067698
    if (ctx->r2 == 0) {
        // 0x80067680: nop
    
            goto L_80067698;
    }
    // 0x80067680: nop

    // 0x80067684: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067688: nop

    // 0x8006768C: slti        $t8, $v0, 0x96
    ctx->r24 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067690: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067694: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067698:
    // 0x80067698: jr          $ra
    // 0x8006769C: nop

    return;
    // 0x8006769C: nop

    // 0x800676A0: jr          $ra
    // 0x800676A4: nop

    return;
    // 0x800676A4: nop

    // 0x800676A8: jr          $ra
    // 0x800676AC: nop

    return;
    // 0x800676AC: nop

;}
RECOMP_FUNC void alSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D65B8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D65BC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800D65C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D65C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D65C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D65CC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800D65D0: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800D65D4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D65D8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800D65DC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D65E0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800D65E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D65E8: bne         $a2, $zero, L_800D6608
    if (ctx->r6 != 0) {
        // 0x800D65EC: sw          $s2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r18;
            goto L_800D6608;
    }
    // 0x800D65EC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D65F0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800D65F4: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x800D65F8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D65FC: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800D6600: b           L_800D66AC
    // 0x800D6604: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_800D66AC;
    // 0x800D6604: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_800D6608:
    // 0x800D6608: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D660C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D6610: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x800D6614: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800D6618: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x800D661C: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x800D6620: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    // 0x800D6624: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D6628: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800D662C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800D6630: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x800D6634: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800D6638: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x800D663C: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
L_800D6640:
    // 0x800D6640: lh          $s5, 0x1A($s0)
    ctx->r21 = MEM_H(ctx->r16, 0X1A);
    // 0x800D6644: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800D6648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D664C: jal         0x800D6434
    // 0x800D6650: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alSeqNextEvent(rdram, ctx);
        goto after_0;
    // 0x800D6650: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800D6654: lh          $t1, 0x50($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X50);
    // 0x800D6658: bnel        $t1, $s3, L_800D6674
    if (ctx->r9 != ctx->r19) {
        // 0x800D665C: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_800D6674;
    }
    goto skip_0;
    // 0x800D665C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800D6660: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
    // 0x800D6664: lh          $s5, 0x1A($s0)
    ctx->r21 = MEM_H(ctx->r16, 0X1A);
    // 0x800D6668: b           L_800D6680
    // 0x800D666C: lw          $s6, 0xC($s0)
    ctx->r22 = MEM_W(ctx->r16, 0XC);
        goto L_800D6680;
    // 0x800D666C: lw          $s6, 0xC($s0)
    ctx->r22 = MEM_W(ctx->r16, 0XC);
    // 0x800D6670: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_800D6674:
    // 0x800D6674: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800D6678: bnel        $at, $zero, L_800D6640
    if (ctx->r1 != 0) {
        // 0x800D667C: lw          $s4, 0x8($s0)
        ctx->r20 = MEM_W(ctx->r16, 0X8);
            goto L_800D6640;
    }
    goto skip_1;
    // 0x800D667C: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_800D6680:
    // 0x800D6680: sw          $s4, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r20;
    // 0x800D6684: sh          $s5, 0xC($s7)
    MEM_H(0XC, ctx->r23) = ctx->r21;
    // 0x800D6688: sw          $s6, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r22;
    // 0x800D668C: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x800D6690: sw          $t2, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r10;
    // 0x800D6694: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800D6698: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x800D669C: lh          $t4, 0x3E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3E);
    // 0x800D66A0: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x800D66A4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800D66A8: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
L_800D66AC:
    // 0x800D66AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D66B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D66B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D66B8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D66BC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D66C0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800D66C4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800D66C8: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800D66CC: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800D66D0: jr          $ra
    // 0x800D66D4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D66D4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800B9CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9CEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9CF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B9CF8:
    // 0x800B9CF8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9CFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9D00: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B9D04: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B9D08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9D0C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B9D10: sw          $zero, -0x1A64($at)
    MEM_W(-0X1A64, ctx->r1) = 0;
    // 0x800B9D14: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9D18: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B9D1C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B9D20: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B9D24: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B9D28: sll         $t2, $t8, 3
    ctx->r10 = S32(ctx->r24 << 3);
    // 0x800B9D2C: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x800B9D30: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B9D34: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B9D38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B9D3C: addiu       $t0, $t0, -0x1988
    ctx->r8 = ADD32(ctx->r8, -0X1988);
    // 0x800B9D40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9D44: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800B9D48: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B9D4C: sw          $t1, -0x1A68($at)
    MEM_W(-0X1A68, ctx->r1) = ctx->r9;
    // 0x800B9D50: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9D54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9D58: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B9D5C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800B9D60: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B9D64: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B9D68: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B9D6C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B9D70: sw          $t3, -0x1988($at)
    MEM_W(-0X1988, ctx->r1) = ctx->r11;
    // 0x800B9D74: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9D78: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9D7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B9D80: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B9D84: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9D88: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B9D8C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9D90: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B9D94: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B9D98: sh          $t5, -0x1970($at)
    MEM_H(-0X1970, ctx->r1) = ctx->r13;
    // 0x800B9D9C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9DA0: nop

    // 0x800B9DA4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B9DA8: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800B9DAC: bne         $at, $zero, L_800B9CF8
    if (ctx->r1 != 0) {
        // 0x800B9DB0: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800B9CF8;
    }
    // 0x800B9DB0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B9DB4: jal         0x800B99D4
    // 0x800B9DB8: nop

    AudioDriver_InitSoundDeallocRequests(rdram, ctx);
        goto after_0;
    // 0x800B9DB8: nop

    after_0:
    // 0x800B9DBC: b           L_800B9DC4
    // 0x800B9DC0: nop

        goto L_800B9DC4;
    // 0x800B9DC0: nop

L_800B9DC4:
    // 0x800B9DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9DCC: jr          $ra
    // 0x800B9DD0: nop

    return;
    // 0x800B9DD0: nop

;}
RECOMP_FUNC void func_8006D734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D73C: jal         0x8005F064
    // 0x8006D740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8006D744: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D748: b           L_8006D758
    // 0x8006D74C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D758;
    // 0x8006D74C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D750: b           L_8006D758
    // 0x8006D754: nop

        goto L_8006D758;
    // 0x8006D754: nop

L_8006D758:
    // 0x8006D758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D75C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D760: jr          $ra
    // 0x8006D764: nop

    return;
    // 0x8006D764: nop

;}
RECOMP_FUNC void func_8000DA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DA44: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000DA48: blez        $a1, L_8000DAFC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000DA4C: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_8000DAFC;
    }
    // 0x8000DA4C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8000DA50:
    // 0x8000DA50: lwc1        $f4, 0x1EC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x8000DA54: lwc1        $f6, 0x1E8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x8000DA58: nop

    // 0x8000DA5C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8000DA60: nop

    // 0x8000DA64: bc1f        L_8000DA74
    if (!c1cs) {
        // 0x8000DA68: nop
    
            goto L_8000DA74;
    }
    // 0x8000DA68: nop

    // 0x8000DA6C: b           L_8000DB0C
    // 0x8000DA70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000DB0C;
    // 0x8000DA70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000DA74:
    // 0x8000DA74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000DA78: lwc1        $f8, 0x1E8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x8000DA7C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000DA80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000DA84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000DA88: nop

    // 0x8000DA8C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000DA90: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8000DA94: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000DA98: bgez        $t7, L_8000DAAC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000DA9C: andi        $t8, $t7, 0x7F
        ctx->r24 = ctx->r15 & 0X7F;
            goto L_8000DAAC;
    }
    // 0x8000DA9C: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x8000DAA0: beq         $t8, $zero, L_8000DAAC
    if (ctx->r24 == 0) {
        // 0x8000DAA4: nop
    
            goto L_8000DAAC;
    }
    // 0x8000DAA4: nop

    // 0x8000DAA8: addiu       $t8, $t8, -0x80
    ctx->r24 = ADD32(ctx->r24, -0X80);
L_8000DAAC:
    // 0x8000DAAC: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8000DAB0: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000DAB4: lw          $t9, 0x210($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X210);
    // 0x8000DAB8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000DABC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000DAC0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000DAC4: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8000DAC8: sh          $t3, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r11;
    // 0x8000DACC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000DAD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000DAD4: lwc1        $f16, 0x1E8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x8000DAD8: nop

    // 0x8000DADC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000DAE0: swc1        $f4, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f4.u32l;
    // 0x8000DAE4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8000DAE8: nop

    // 0x8000DAEC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000DAF0: slt         $at, $t5, $a1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000DAF4: bne         $at, $zero, L_8000DA50
    if (ctx->r1 != 0) {
        // 0x8000DAF8: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_8000DA50;
    }
    // 0x8000DAF8: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
L_8000DAFC:
    // 0x8000DAFC: b           L_8000DB0C
    // 0x8000DB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DB0C;
    // 0x8000DB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DB04: b           L_8000DB0C
    // 0x8000DB08: nop

        goto L_8000DB0C;
    // 0x8000DB08: nop

L_8000DB0C:
    // 0x8000DB0C: jr          $ra
    // 0x8000DB10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000DB10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80084F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084F60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084F64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80084F68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084F6C: jal         0x8008B4EC
    // 0x80084F70: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80084F70: nop

    after_0:
    // 0x80084F74: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80084F78: nop

    // 0x80084F7C: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x80084F80: nop

    // 0x80084F84: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80084F88: beq         $t8, $zero, L_80084FF0
    if (ctx->r24 == 0) {
        // 0x80084F8C: nop
    
            goto L_80084FF0;
    }
    // 0x80084F8C: nop

    // 0x80084F90: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x80084F94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084F98: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x80084F9C: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80084FA0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084FA4: sw          $t0, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r8;
    // 0x80084FA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084FAC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80084FB0: jal         0x8008B2FC
    // 0x80084FB4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_1;
    // 0x80084FB4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_1:
    // 0x80084FB8: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80084FBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084FC0: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x80084FC4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80084FC8: lw          $t2, 0x6BA0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6BA0);
    // 0x80084FCC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084FD0: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x80084FD4: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x80084FD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084FDC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80084FE0: jal         0x8008B2FC
    // 0x80084FE4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_2;
    // 0x80084FE4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // 0x80084FE8: b           L_800851B4
    // 0x80084FEC: nop

        goto L_800851B4;
    // 0x80084FEC: nop

L_80084FF0:
    // 0x80084FF0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80084FF4: lhu         $t4, 0x7A10($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X7A10);
    // 0x80084FF8: nop

    // 0x80084FFC: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80085000: bne         $t5, $zero, L_80085068
    if (ctx->r13 != 0) {
        // 0x80085004: nop
    
            goto L_80085068;
    }
    // 0x80085004: nop

    // 0x80085008: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x8008500C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085010: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x80085014: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80085018: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008501C: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x80085020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085024: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80085028: jal         0x8008B2FC
    // 0x8008502C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_3;
    // 0x8008502C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_3:
    // 0x80085030: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x80085034: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085038: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x8008503C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80085040: lw          $t9, 0x6BA0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6BA0);
    // 0x80085044: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085048: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x8008504C: sw          $t0, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r8;
    // 0x80085050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085054: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80085058: jal         0x8008B2FC
    // 0x8008505C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_4;
    // 0x8008505C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_4:
    // 0x80085060: b           L_800851B4
    // 0x80085064: nop

        goto L_800851B4;
    // 0x80085064: nop

L_80085068:
    // 0x80085068: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008506C: lhu         $t1, 0x7A10($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X7A10);
    // 0x80085070: nop

    // 0x80085074: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x80085078: beq         $t2, $zero, L_800850E0
    if (ctx->r10 == 0) {
        // 0x8008507C: nop
    
            goto L_800850E0;
    }
    // 0x8008507C: nop

    // 0x80085080: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x80085084: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085088: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x8008508C: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80085090: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085094: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x80085098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008509C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x800850A0: jal         0x8008B2FC
    // 0x800850A4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_5;
    // 0x800850A4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_5:
    // 0x800850A8: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x800850AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850B0: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x800850B4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800850B8: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x800850BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850C0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800850C4: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x800850C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800850CC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x800850D0: jal         0x8008B2FC
    // 0x800850D4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_6;
    // 0x800850D4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_6:
    // 0x800850D8: b           L_800851B4
    // 0x800850DC: nop

        goto L_800851B4;
    // 0x800850DC: nop

L_800850E0:
    // 0x800850E0: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x800850E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850E8: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x800850EC: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x800850F0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850F4: sw          $t9, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r25;
    // 0x800850F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800850FC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80085100: jal         0x8008B2FC
    // 0x80085104: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_7;
    // 0x80085104: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_7:
    // 0x80085108: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8008510C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085110: sw          $t0, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r8;
    // 0x80085114: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80085118: lw          $t1, 0x6BA0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6BA0);
    // 0x8008511C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085120: addiu       $t2, $t1, 0x20
    ctx->r10 = ADD32(ctx->r9, 0X20);
    // 0x80085124: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x80085128: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008512C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80085130: jal         0x8008B2FC
    // 0x80085134: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_8;
    // 0x80085134: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_8:
    // 0x80085138: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8008513C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085140: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x80085144: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80085148: lw          $t4, 0x6BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA0);
    // 0x8008514C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085150: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x80085154: sw          $t5, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r13;
    // 0x80085158: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008515C: addiu       $a0, $a0, -0xAD0
    ctx->r4 = ADD32(ctx->r4, -0XAD0);
    // 0x80085160: jal         0x8008ECE4
    // 0x80085164: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x80085164: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_9:
    // 0x80085168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008516C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80085170: jal         0x8008B2FC
    // 0x80085174: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_10;
    // 0x80085174: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_10:
    // 0x80085178: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8008517C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085180: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x80085184: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80085188: lw          $t7, 0x6BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA0);
    // 0x8008518C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085190: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80085194: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x80085198: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008519C: lh          $a1, 0x7A12($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7A12);
    // 0x800851A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800851A4: jal         0x8008ECE4
    // 0x800851A8: addiu       $a0, $a0, -0xACC
    ctx->r4 = ADD32(ctx->r4, -0XACC);
    func_8008ECE4(rdram, ctx);
        goto after_11;
    // 0x800851A8: addiu       $a0, $a0, -0xACC
    ctx->r4 = ADD32(ctx->r4, -0XACC);
    after_11:
    // 0x800851AC: b           L_800851B4
    // 0x800851B0: nop

        goto L_800851B4;
    // 0x800851B0: nop

L_800851B4:
    // 0x800851B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800851B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800851BC: jr          $ra
    // 0x800851C0: nop

    return;
    // 0x800851C0: nop

;}
RECOMP_FUNC void func_80063B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B84: jal         0x8005F064
    // 0x80063B88: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063B88: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063B8C: b           L_80063B9C
    // 0x80063B90: nop

        goto L_80063B9C;
    // 0x80063B90: nop

    // 0x80063B94: b           L_80063B9C
    // 0x80063B98: nop

        goto L_80063B9C;
    // 0x80063B98: nop

L_80063B9C:
    // 0x80063B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063BA4: jr          $ra
    // 0x80063BA8: nop

    return;
    // 0x80063BA8: nop

;}
RECOMP_FUNC void func_80010734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010734: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001073C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80010740: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80010744: nop

    // 0x80010748: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001074C: nop

    // 0x80010750: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80010754: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80010758: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001075C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80010760: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80010764: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80010768: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001076C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80010770: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80010774: nop

    // 0x80010778: lwc1        $f16, 0x4C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4C);
    // 0x8001077C: nop

    // 0x80010780: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80010784: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80010788: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001078C: swc1        $f6, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->f6.u32l;
    // 0x80010790: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80010794: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80010798: lwc1        $f8, 0x4C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8001079C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800107A0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800107A4: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x800107A8: nop

    // 0x800107AC: bc1f        L_800108A0
    if (!c1cs) {
        // 0x800107B0: nop
    
            goto L_800108A0;
    }
    // 0x800107B0: nop

L_800107B4:
    // 0x800107B4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800107B8: nop

    // 0x800107BC: lhu         $t1, 0x52($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X52);
    // 0x800107C0: addiu       $a0, $t0, 0xC
    ctx->r4 = ADD32(ctx->r8, 0XC);
    // 0x800107C4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800107C8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800107CC: lhu         $a2, 0x54($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X54);
    // 0x800107D0: jal         0x800B3DBC
    // 0x800107D4: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    func_800B3DBC(rdram, ctx);
        goto after_0;
    // 0x800107D4: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    after_0:
    // 0x800107D8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800107DC: nop

    // 0x800107E0: lhu         $t5, 0x50($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X50);
    // 0x800107E4: lwc1        $f10, 0x4C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4C);
    // 0x800107E8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800107EC: bgez        $t5, L_80010804
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800107F0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80010804;
    }
    // 0x800107F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800107F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800107F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800107FC: nop

    // 0x80010800: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80010804:
    // 0x80010804: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80010808: swc1        $f16, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f16.u32l;
    // 0x8001080C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80010810: nop

    // 0x80010814: lhu         $t7, 0x52($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X52);
    // 0x80010818: nop

    // 0x8001081C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80010820: sh          $t8, 0x52($t6)
    MEM_H(0X52, ctx->r14) = ctx->r24;
    // 0x80010824: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80010828: nop

    // 0x8001082C: lhu         $t1, 0x52($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X52);
    // 0x80010830: nop

    // 0x80010834: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80010838: beq         $at, $zero, L_80010870
    if (ctx->r1 == 0) {
        // 0x8001083C: nop
    
            goto L_80010870;
    }
    // 0x8001083C: nop

    // 0x80010840: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80010844: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80010848: lhu         $t2, 0x52($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X52);
    // 0x8001084C: nop

    // 0x80010850: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80010854: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x80010858: lhu         $t4, 0x54($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X54);
    // 0x8001085C: nop

    // 0x80010860: beq         $t4, $at, L_80010870
    if (ctx->r12 == ctx->r1) {
        // 0x80010864: nop
    
            goto L_80010870;
    }
    // 0x80010864: nop

    // 0x80010868: b           L_8001087C
    // 0x8001086C: nop

        goto L_8001087C;
    // 0x8001086C: nop

L_80010870:
    // 0x80010870: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80010874: nop

    // 0x80010878: sh          $zero, 0x52($t7)
    MEM_H(0X52, ctx->r15) = 0;
L_8001087C:
    // 0x8001087C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80010880: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80010884: lwc1        $f18, 0x4C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4C);
    // 0x80010888: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001088C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80010890: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80010894: nop

    // 0x80010898: bc1t        L_800107B4
    if (c1cs) {
        // 0x8001089C: nop
    
            goto L_800107B4;
    }
    // 0x8001089C: nop

L_800108A0:
    // 0x800108A0: b           L_800108A8
    // 0x800108A4: nop

        goto L_800108A8;
    // 0x800108A4: nop

L_800108A8:
    // 0x800108A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800108AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800108B0: jr          $ra
    // 0x800108B4: nop

    return;
    // 0x800108B4: nop

;}
RECOMP_FUNC void func_800491A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800491A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800491A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800491A8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800491AC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800491B0: addiu       $a1, $a1, 0xFF8
    ctx->r5 = ADD32(ctx->r5, 0XFF8);
    // 0x800491B4: addiu       $a0, $a0, -0x2898
    ctx->r4 = ADD32(ctx->r4, -0X2898);
    // 0x800491B8: jal         0x800C0640
    // 0x800491BC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    Thread_CreateSimple(rdram, ctx);
        goto after_0;
    // 0x800491BC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_0:
    // 0x800491C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800491C4: sb          $v0, 0xFF8($at)
    MEM_B(0XFF8, ctx->r1) = ctx->r2;
    // 0x800491C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800491CC: lbu         $a0, 0xFF8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XFF8);
    // 0x800491D0: jal         0x800C0988
    // 0x800491D4: nop

    func_800C0988(rdram, ctx);
        goto after_1;
    // 0x800491D4: nop

    after_1:
    // 0x800491D8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800491DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800491E0: sw          $t6, 0xFFC($at)
    MEM_W(0XFFC, ctx->r1) = ctx->r14;
    // 0x800491E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800491E8: lbu         $a0, 0xFF8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XFF8);
    // 0x800491EC: jal         0x800C0E04
    // 0x800491F0: nop

    Thread_GetPtr(rdram, ctx);
        goto after_2;
    // 0x800491F0: nop

    after_2:
    // 0x800491F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800491F8: sw          $v0, 0x1010($at)
    MEM_W(0X1010, ctx->r1) = ctx->r2;
    // 0x800491FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80049200: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049204: sb          $t7, 0x1018($at)
    MEM_B(0X1018, ctx->r1) = ctx->r15;
    // 0x80049208: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004920C: lbu         $a0, 0xFF8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XFF8);
    // 0x80049210: jal         0x800C0C8C
    // 0x80049214: nop

    Thread_Start(rdram, ctx);
        goto after_3;
    // 0x80049214: nop

    after_3:
    // 0x80049218: b           L_80049220
    // 0x8004921C: nop

        goto L_80049220;
    // 0x8004921C: nop

L_80049220:
    // 0x80049220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049228: jr          $ra
    // 0x8004922C: nop

    return;
    // 0x8004922C: nop

;}
RECOMP_FUNC void AudioDriver_UpdateSeqID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB3D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB3D8: sw          $a0, -0x17C8($at)
    MEM_W(-0X17C8, ctx->r1) = ctx->r4;
    // 0x800BB3DC: jr          $ra
    // 0x800BB3E0: nop

    return;
    // 0x800BB3E0: nop

    // 0x800BB3E4: jr          $ra
    // 0x800BB3E8: nop

    return;
    // 0x800BB3E8: nop

;}
RECOMP_FUNC void Spi_CompressionTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF2E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BF2EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF2F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BF2F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BF2F8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BF2FC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BF300: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF304: sw          $t6, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r14;
    // 0x800BF308: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800BF30C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF310: jal         0x800BC6EC
    // 0x800BF314: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800BF314: nop

    after_0:
    // 0x800BF318: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF31C: sw          $v0, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r2;
    // 0x800BF320: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF324: lw          $t7, 0x43C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X43C);
    // 0x800BF328: nop

    // 0x800BF32C: bne         $t7, $zero, L_800BF33C
    if (ctx->r15 != 0) {
        // 0x800BF330: nop
    
            goto L_800BF33C;
    }
    // 0x800BF330: nop

    // 0x800BF334: b           L_800BF6B8
    // 0x800BF338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF6B8;
    // 0x800BF338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF33C:
    // 0x800BF33C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF340: jal         0x800BC6EC
    // 0x800BF344: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800BF344: nop

    after_1:
    // 0x800BF348: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF34C: sw          $v0, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r2;
    // 0x800BF350: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF354: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BF358: nop

    // 0x800BF35C: bne         $t8, $zero, L_800BF37C
    if (ctx->r24 != 0) {
        // 0x800BF360: nop
    
            goto L_800BF37C;
    }
    // 0x800BF360: nop

    // 0x800BF364: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF368: lw          $a0, 0x43C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X43C);
    // 0x800BF36C: jal         0x800BC980
    // 0x800BF370: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x800BF370: nop

    after_2:
    // 0x800BF374: b           L_800BF6B8
    // 0x800BF378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF6B8;
    // 0x800BF378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF37C:
    // 0x800BF37C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF380: jal         0x800BC6EC
    // 0x800BF384: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800BF384: nop

    after_3:
    // 0x800BF388: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF38C: sw          $v0, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r2;
    // 0x800BF390: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF394: lw          $t9, 0x44C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X44C);
    // 0x800BF398: nop

    // 0x800BF39C: bne         $t9, $zero, L_800BF3CC
    if (ctx->r25 != 0) {
        // 0x800BF3A0: nop
    
            goto L_800BF3CC;
    }
    // 0x800BF3A0: nop

    // 0x800BF3A4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF3A8: lw          $a0, 0x43C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X43C);
    // 0x800BF3AC: jal         0x800BC980
    // 0x800BF3B0: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x800BF3B0: nop

    after_4:
    // 0x800BF3B4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF3B8: lw          $a0, 0x444($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X444);
    // 0x800BF3BC: jal         0x800BC980
    // 0x800BF3C0: nop

    SysMem_Free(rdram, ctx);
        goto after_5;
    // 0x800BF3C0: nop

    after_5:
    // 0x800BF3C4: b           L_800BF6B8
    // 0x800BF3C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF6B8;
    // 0x800BF3C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF3CC:
    // 0x800BF3CC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BF3D0: lw          $t0, 0x434($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X434);
    // 0x800BF3D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF3D8: sw          $t0, 0x458($at)
    MEM_W(0X458, ctx->r1) = ctx->r8;
    // 0x800BF3DC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BF3E0: lw          $t1, 0x43C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X43C);
    // 0x800BF3E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF3E8: sw          $t1, 0x45C($at)
    MEM_W(0X45C, ctx->r1) = ctx->r9;
    // 0x800BF3EC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF3F0: lw          $t2, 0x444($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X444);
    // 0x800BF3F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF3F8: sw          $t2, 0x460($at)
    MEM_W(0X460, ctx->r1) = ctx->r10;
    // 0x800BF3FC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF400: lw          $t3, 0x44C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X44C);
    // 0x800BF404: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF408: sw          $t3, 0x464($at)
    MEM_W(0X464, ctx->r1) = ctx->r11;
    // 0x800BF40C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800BF410: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF414: jal         0x800BF6C8
    // 0x800BF418: nop

    Spi_Compress(rdram, ctx);
        goto after_6;
    // 0x800BF418: nop

    after_6:
    // 0x800BF41C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF420: addiu       $t5, $t5, 0x490
    ctx->r13 = ADD32(ctx->r13, 0X490);
    // 0x800BF424: addiu       $t4, $zero, 0x53
    ctx->r12 = ADD32(0, 0X53);
    // 0x800BF428: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x800BF42C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF430: addiu       $t7, $t7, 0x490
    ctx->r15 = ADD32(ctx->r15, 0X490);
    // 0x800BF434: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800BF438: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x800BF43C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF440: addiu       $t9, $t9, 0x490
    ctx->r25 = ADD32(ctx->r25, 0X490);
    // 0x800BF444: addiu       $t8, $zero, 0x49
    ctx->r24 = ADD32(0, 0X49);
    // 0x800BF448: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x800BF44C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800BF450: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BF454: bne         $t0, $at, L_800BF470
    if (ctx->r8 != ctx->r1) {
        // 0x800BF458: nop
    
            goto L_800BF470;
    }
    // 0x800BF458: nop

    // 0x800BF45C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF460: addiu       $t2, $t2, 0x490
    ctx->r10 = ADD32(ctx->r10, 0X490);
    // 0x800BF464: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800BF468: b           L_800BF480
    // 0x800BF46C: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
        goto L_800BF480;
    // 0x800BF46C: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
L_800BF470:
    // 0x800BF470: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF474: addiu       $t4, $t4, 0x490
    ctx->r12 = ADD32(ctx->r12, 0X490);
    // 0x800BF478: addiu       $t3, $zero, 0x31
    ctx->r11 = ADD32(0, 0X31);
    // 0x800BF47C: sb          $t3, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r11;
L_800BF480:
    // 0x800BF480: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF484: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BF488: lw          $t6, 0x464($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X464);
    // 0x800BF48C: lw          $t5, 0x44C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X44C);
    // 0x800BF490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF494: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800BF498: sw          $t7, 0x498($at)
    MEM_W(0X498, ctx->r1) = ctx->r15;
    // 0x800BF49C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF4A0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF4A4: lw          $t9, 0x45C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X45C);
    // 0x800BF4A8: lw          $t8, 0x43C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X43C);
    // 0x800BF4AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF4B0: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800BF4B4: sw          $t0, 0x49C($at)
    MEM_W(0X49C, ctx->r1) = ctx->r8;
    // 0x800BF4B8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BF4BC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF4C0: lw          $t2, 0x460($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X460);
    // 0x800BF4C4: lw          $t1, 0x444($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X444);
    // 0x800BF4C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF4CC: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800BF4D0: sw          $t3, 0x4A0($at)
    MEM_W(0X4A0, ctx->r1) = ctx->r11;
    // 0x800BF4D4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF4D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF4DC: sw          $t4, 0x494($at)
    MEM_W(0X494, ctx->r1) = ctx->r12;
    // 0x800BF4E0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF4E4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BF4E8: lw          $t6, 0x49C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X49C);
    // 0x800BF4EC: lw          $t5, 0x498($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X498);
    // 0x800BF4F0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF4F4: lw          $t8, 0x4A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4A0);
    // 0x800BF4F8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BF4FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800BF500: addiu       $t0, $t9, 0x14
    ctx->r8 = ADD32(ctx->r25, 0X14);
    // 0x800BF504: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BF508: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF50C: jal         0x800BC6EC
    // 0x800BF510: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x800BF510: nop

    after_7:
    // 0x800BF514: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BF518: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BF51C: nop

    // 0x800BF520: bne         $t1, $zero, L_800BF560
    if (ctx->r9 != 0) {
        // 0x800BF524: nop
    
            goto L_800BF560;
    }
    // 0x800BF524: nop

    // 0x800BF528: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF52C: lw          $a0, 0x45C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X45C);
    // 0x800BF530: jal         0x800BC980
    // 0x800BF534: nop

    SysMem_Free(rdram, ctx);
        goto after_8;
    // 0x800BF534: nop

    after_8:
    // 0x800BF538: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF53C: lw          $a0, 0x460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X460);
    // 0x800BF540: jal         0x800BC980
    // 0x800BF544: nop

    SysMem_Free(rdram, ctx);
        goto after_9;
    // 0x800BF544: nop

    after_9:
    // 0x800BF548: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF54C: lw          $a0, 0x464($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X464);
    // 0x800BF550: jal         0x800BC980
    // 0x800BF554: nop

    SysMem_Free(rdram, ctx);
        goto after_10;
    // 0x800BF554: nop

    after_10:
    // 0x800BF558: b           L_800BF6B8
    // 0x800BF55C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF6B8;
    // 0x800BF55C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF560:
    // 0x800BF560: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BF564: nop

    // 0x800BF568: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800BF56C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BF570: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800BF574: addiu       $a1, $a1, 0x490
    ctx->r5 = ADD32(ctx->r5, 0X490);
    // 0x800BF578: jal         0x800BCFCC
    // 0x800BF57C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    SysMem_Copy8(rdram, ctx);
        goto after_11;
    // 0x800BF57C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_11:
    // 0x800BF580: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800BF584: nop

    // 0x800BF588: addiu       $t4, $t3, 0x14
    ctx->r12 = ADD32(ctx->r11, 0X14);
    // 0x800BF58C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800BF590: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800BF594: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800BF598: lw          $a2, 0x498($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X498);
    // 0x800BF59C: lw          $a1, 0x464($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X464);
    // 0x800BF5A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BF5A4: jal         0x800BCFCC
    // 0x800BF5A8: nop

    SysMem_Copy8(rdram, ctx);
        goto after_12;
    // 0x800BF5A8: nop

    after_12:
    // 0x800BF5AC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BF5B0: lw          $t6, 0x498($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X498);
    // 0x800BF5B4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BF5B8: nop

    // 0x800BF5BC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BF5C0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800BF5C4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800BF5C8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800BF5CC: lw          $a2, 0x49C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X49C);
    // 0x800BF5D0: lw          $a1, 0x45C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X45C);
    // 0x800BF5D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BF5D8: jal         0x800BCFCC
    // 0x800BF5DC: nop

    SysMem_Copy8(rdram, ctx);
        goto after_13;
    // 0x800BF5DC: nop

    after_13:
    // 0x800BF5E0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF5E4: lw          $t9, 0x49C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X49C);
    // 0x800BF5E8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800BF5EC: nop

    // 0x800BF5F0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BF5F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800BF5F8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800BF5FC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800BF600: lw          $a2, 0x4A0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4A0);
    // 0x800BF604: lw          $a1, 0x460($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X460);
    // 0x800BF608: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BF60C: jal         0x800BCFCC
    // 0x800BF610: nop

    SysMem_Copy8(rdram, ctx);
        goto after_14;
    // 0x800BF610: nop

    after_14:
    // 0x800BF614: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BF618: nop

    // 0x800BF61C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800BF620: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF624: lw          $a0, 0x45C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X45C);
    // 0x800BF628: jal         0x800BC980
    // 0x800BF62C: nop

    SysMem_Free(rdram, ctx);
        goto after_15;
    // 0x800BF62C: nop

    after_15:
    // 0x800BF630: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF634: lw          $a0, 0x460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X460);
    // 0x800BF638: jal         0x800BC980
    // 0x800BF63C: nop

    SysMem_Free(rdram, ctx);
        goto after_16;
    // 0x800BF63C: nop

    after_16:
    // 0x800BF640: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800BF644: lw          $a0, 0x464($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X464);
    // 0x800BF648: jal         0x800BC980
    // 0x800BF64C: nop

    SysMem_Free(rdram, ctx);
        goto after_17;
    // 0x800BF64C: nop

    after_17:
    // 0x800BF650: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF654: jal         0x800BC6EC
    // 0x800BF658: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_18;
    // 0x800BF658: nop

    after_18:
    // 0x800BF65C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BF660: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BF664: nop

    // 0x800BF668: bne         $t2, $zero, L_800BF684
    if (ctx->r10 != 0) {
        // 0x800BF66C: nop
    
            goto L_800BF684;
    }
    // 0x800BF66C: nop

    // 0x800BF670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BF674: jal         0x800BC980
    // 0x800BF678: nop

    SysMem_Free(rdram, ctx);
        goto after_19;
    // 0x800BF678: nop

    after_19:
    // 0x800BF67C: b           L_800BF6B8
    // 0x800BF680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF6B8;
    // 0x800BF680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF684:
    // 0x800BF684: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800BF688: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800BF68C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF690: jal         0x800BCFCC
    // 0x800BF694: nop

    SysMem_Copy8(rdram, ctx);
        goto after_20;
    // 0x800BF694: nop

    after_20:
    // 0x800BF698: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BF69C: jal         0x800BC980
    // 0x800BF6A0: nop

    SysMem_Free(rdram, ctx);
        goto after_21;
    // 0x800BF6A0: nop

    after_21:
    // 0x800BF6A4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800BF6A8: b           L_800BF6B8
    // 0x800BF6AC: nop

        goto L_800BF6B8;
    // 0x800BF6AC: nop

    // 0x800BF6B0: b           L_800BF6B8
    // 0x800BF6B4: nop

        goto L_800BF6B8;
    // 0x800BF6B4: nop

L_800BF6B8:
    // 0x800BF6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF6BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BF6C0: jr          $ra
    // 0x800BF6C4: nop

    return;
    // 0x800BF6C4: nop

;}
RECOMP_FUNC void func_8000CFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CFE4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000CFE8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8000CFEC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8000CFF0:
    // 0x8000CFF0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8000CFF4: nop

    // 0x8000CFF8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000CFFC: nop

    // 0x8000D000: bne         $t7, $a1, L_8000D028
    if (ctx->r15 != ctx->r5) {
        // 0x8000D004: nop
    
            goto L_8000D028;
    }
    // 0x8000D004: nop

    // 0x8000D008: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8000D00C: nop

    // 0x8000D010: blez        $t8, L_8000D020
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8000D014: nop
    
            goto L_8000D020;
    }
    // 0x8000D014: nop

    // 0x8000D018: b           L_8000D0A0
    // 0x8000D01C: nop

        goto L_8000D0A0;
    // 0x8000D01C: nop

L_8000D020:
    // 0x8000D020: b           L_8000D0B4
    // 0x8000D024: nop

        goto L_8000D0B4;
    // 0x8000D024: nop

L_8000D028:
    // 0x8000D028: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8000D02C: ori         $at, $zero, 0xC002
    ctx->r1 = 0 | 0XC002;
    // 0x8000D030: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8000D034: nop

    // 0x8000D038: bne         $t0, $at, L_8000D058
    if (ctx->r8 != ctx->r1) {
        // 0x8000D03C: nop
    
            goto L_8000D058;
    }
    // 0x8000D03C: nop

    // 0x8000D040: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8000D044: nop

    // 0x8000D048: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000D04C: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8000D050: b           L_8000D0A0
    // 0x8000D054: nop

        goto L_8000D0A0;
    // 0x8000D054: nop

L_8000D058:
    // 0x8000D058: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x8000D05C: ori         $at, $zero, 0xC004
    ctx->r1 = 0 | 0XC004;
    // 0x8000D060: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000D064: nop

    // 0x8000D068: bne         $t4, $at, L_8000D0A0
    if (ctx->r12 != ctx->r1) {
        // 0x8000D06C: nop
    
            goto L_8000D0A0;
    }
    // 0x8000D06C: nop

    // 0x8000D070: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8000D074: nop

    // 0x8000D078: bgtz        $t5, L_8000D088
    if (SIGNED(ctx->r13) > 0) {
        // 0x8000D07C: nop
    
            goto L_8000D088;
    }
    // 0x8000D07C: nop

    // 0x8000D080: b           L_8000D0B4
    // 0x8000D084: nop

        goto L_8000D0B4;
    // 0x8000D084: nop

L_8000D088:
    // 0x8000D088: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8000D08C: nop

    // 0x8000D090: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000D094: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8000D098: b           L_8000D0A0
    // 0x8000D09C: nop

        goto L_8000D0A0;
    // 0x8000D09C: nop

L_8000D0A0:
    // 0x8000D0A0: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8000D0A4: nop

    // 0x8000D0A8: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000D0AC: b           L_8000CFF0
    // 0x8000D0B0: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
        goto L_8000CFF0;
    // 0x8000D0B0: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
L_8000D0B4:
    // 0x8000D0B4: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x8000D0B8: nop

    // 0x8000D0BC: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x8000D0C0: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x8000D0C4: b           L_8000D0CC
    // 0x8000D0C8: nop

        goto L_8000D0CC;
    // 0x8000D0C8: nop

L_8000D0CC:
    // 0x8000D0CC: jr          $ra
    // 0x8000D0D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000D0D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8000D0D4: nop

    // 0x8000D0D8: nop

    // 0x8000D0DC: nop

;}
RECOMP_FUNC void func_80087F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087F40: jal         0x8008A46C
    // 0x80087F44: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80087F44: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80087F48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087F4C: jal         0x800875E0
    // 0x80087F50: nop

    func_800875E0(rdram, ctx);
        goto after_1;
    // 0x80087F50: nop

    after_1:
    // 0x80087F54: b           L_80087F64
    // 0x80087F58: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80087F64;
    // 0x80087F58: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80087F5C: b           L_80087F64
    // 0x80087F60: nop

        goto L_80087F64;
    // 0x80087F60: nop

L_80087F64:
    // 0x80087F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087F6C: jr          $ra
    // 0x80087F70: nop

    return;
    // 0x80087F70: nop

;}
RECOMP_FUNC void func_80066B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066B54: jal         0x80061348
    // 0x80066B58: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066B58: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80066B5C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066B60: b           L_80066B70
    // 0x80066B64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066B70;
    // 0x80066B64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066B68: b           L_80066B70
    // 0x80066B6C: nop

        goto L_80066B70;
    // 0x80066B6C: nop

L_80066B70:
    // 0x80066B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066B78: jr          $ra
    // 0x80066B7C: nop

    return;
    // 0x80066B7C: nop

;}
RECOMP_FUNC void func_80073054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073058: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007305C: nop

    // 0x80073060: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073064: nop

    // 0x80073068: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007306C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073070: jr          $ra
    // 0x80073074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073078: jr          $ra
    // 0x8007307C: nop

    return;
    // 0x8007307C: nop

    // 0x80073080: jr          $ra
    // 0x80073084: nop

    return;
    // 0x80073084: nop

;}
RECOMP_FUNC void func_80067A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A90: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067A94: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067A98: nop

    // 0x80067A9C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80067AA0: nop

    // 0x80067AA4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067AA8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067AAC: jr          $ra
    // 0x80067AB0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067AB0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067AB4: jr          $ra
    // 0x80067AB8: nop

    return;
    // 0x80067AB8: nop

    // 0x80067ABC: jr          $ra
    // 0x80067AC0: nop

    return;
    // 0x80067AC0: nop

;}
RECOMP_FUNC void func_80073C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073C64: jal         0x80061348
    // 0x80073C68: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073C68: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073C6C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073C70: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073C74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073C78: beq         $v0, $zero, L_80073CCC
    if (ctx->r2 == 0) {
        // 0x80073C7C: nop
    
            goto L_80073CCC;
    }
    // 0x80073C7C: nop

    // 0x80073C80: jal         0x80061348
    // 0x80073C84: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073C84: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073C88: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073C8C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073C90: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073C94: beq         $v0, $zero, L_80073CCC
    if (ctx->r2 == 0) {
        // 0x80073C98: nop
    
            goto L_80073CCC;
    }
    // 0x80073C98: nop

    // 0x80073C9C: jal         0x80061348
    // 0x80073CA0: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073CA0: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073CA4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073CA8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073CAC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073CB0: beq         $v0, $zero, L_80073CCC
    if (ctx->r2 == 0) {
        // 0x80073CB4: nop
    
            goto L_80073CCC;
    }
    // 0x80073CB4: nop

    // 0x80073CB8: jal         0x80061348
    // 0x80073CBC: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073CBC: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073CC0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073CC4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073CC8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073CCC:
    // 0x80073CCC: b           L_80073CDC
    // 0x80073CD0: nop

        goto L_80073CDC;
    // 0x80073CD0: nop

    // 0x80073CD4: b           L_80073CDC
    // 0x80073CD8: nop

        goto L_80073CDC;
    // 0x80073CD8: nop

L_80073CDC:
    // 0x80073CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073CE4: jr          $ra
    // 0x80073CE8: nop

    return;
    // 0x80073CE8: nop

;}
RECOMP_FUNC void func_80077F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077F80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077F84: nop

    // 0x80077F88: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80077F8C: nop

    // 0x80077F90: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077F94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077F98: jr          $ra
    // 0x80077F9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077F9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077FA0: jr          $ra
    // 0x80077FA4: nop

    return;
    // 0x80077FA4: nop

    // 0x80077FA8: jr          $ra
    // 0x80077FAC: nop

    return;
    // 0x80077FAC: nop

;}
RECOMP_FUNC void func_80077B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077B34: jal         0x80061488
    // 0x80077B38: addiu       $a0, $zero, 0x56E
    ctx->r4 = ADD32(0, 0X56E);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077B38: addiu       $a0, $zero, 0x56E
    ctx->r4 = ADD32(0, 0X56E);
    after_0:
    // 0x80077B3C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80077B40: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077B44: b           L_80077B54
    // 0x80077B48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077B54;
    // 0x80077B48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077B4C: b           L_80077B54
    // 0x80077B50: nop

        goto L_80077B54;
    // 0x80077B50: nop

L_80077B54:
    // 0x80077B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077B5C: jr          $ra
    // 0x80077B60: nop

    return;
    // 0x80077B60: nop

;}
RECOMP_FUNC void func_800226F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800226F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800226F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800226FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80022700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022704: lwc1        $f4, 0xEF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x80022708: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002270C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022710: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80022714: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80022718: nop

    // 0x8002271C: bc1f        L_80022770
    if (!c1cs) {
        // 0x80022720: nop
    
            goto L_80022770;
    }
    // 0x80022720: nop

    // 0x80022724: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022728: lwc1        $f10, 0xEF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x8002272C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022730: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80022734: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80022738: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002273C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022740: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80022744: c.le.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d <= ctx->f6.d;
    // 0x80022748: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002274C: bc1f        L_80022770
    if (!c1cs) {
        // 0x80022750: swc1        $f18, 0xEF0($at)
        MEM_W(0XEF0, ctx->r1) = ctx->f18.u32l;
            goto L_80022770;
    }
    // 0x80022750: swc1        $f18, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f18.u32l;
    // 0x80022754: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022758: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002275C: swc1        $f8, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f8.u32l;
    // 0x80022760: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022764: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80022768: b           L_80022898
    // 0x8002276C: nop

        goto L_80022898;
    // 0x8002276C: nop

L_80022770:
    // 0x80022770: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80022774: lh          $t6, 0x66C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X66C);
    // 0x80022778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002277C: bne         $t6, $at, L_80022890
    if (ctx->r14 != ctx->r1) {
        // 0x80022780: nop
    
            goto L_80022890;
    }
    // 0x80022780: nop

    // 0x80022784: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80022788: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8002278C: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x80022790: nop

    // 0x80022794: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    // 0x80022798: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002279C: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x800227A0: lhu         $t9, 0x1E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1E);
    // 0x800227A4: nop

    // 0x800227A8: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800227AC: beq         $t1, $zero, L_80022818
    if (ctx->r9 == 0) {
        // 0x800227B0: nop
    
            goto L_80022818;
    }
    // 0x800227B0: nop

    // 0x800227B4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800227B8: lh          $t2, 0x6C0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X6C0);
    // 0x800227BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800227C0: beq         $t2, $at, L_80022818
    if (ctx->r10 == ctx->r1) {
        // 0x800227C4: nop
    
            goto L_80022818;
    }
    // 0x800227C4: nop

    // 0x800227C8: jal         0x80055FB8
    // 0x800227CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_0;
    // 0x800227CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800227D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800227D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800227D8: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x800227DC: lhu         $t4, 0x22($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X22);
    // 0x800227E0: nop

    // 0x800227E4: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800227E8: bgez        $t4, L_80022800
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800227EC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80022800;
    }
    // 0x800227EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800227F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800227F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800227F8: nop

    // 0x800227FC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80022800:
    // 0x80022800: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022804: swc1        $f16, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f16.u32l;
    // 0x80022808: jal         0x800B9000
    // 0x8002280C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8002280C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80022810: b           L_80022890
    // 0x80022814: nop

        goto L_80022890;
    // 0x80022814: nop

L_80022818:
    // 0x80022818: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002281C: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x80022820: lhu         $t5, 0x1E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X1E);
    // 0x80022824: nop

    // 0x80022828: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8002282C: beq         $t7, $zero, L_80022890
    if (ctx->r15 == 0) {
        // 0x80022830: nop
    
            goto L_80022890;
    }
    // 0x80022830: nop

    // 0x80022834: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80022838: lh          $t8, 0x6C0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X6C0);
    // 0x8002283C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022840: beq         $t8, $at, L_80022890
    if (ctx->r24 == ctx->r1) {
        // 0x80022844: nop
    
            goto L_80022890;
    }
    // 0x80022844: nop

    // 0x80022848: jal         0x80055FB8
    // 0x8002284C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_2;
    // 0x8002284C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80022850: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80022854: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022858: sh          $t9, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r25;
    // 0x8002285C: lhu         $t0, 0x22($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X22);
    // 0x80022860: nop

    // 0x80022864: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80022868: bgez        $t0, L_80022880
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8002286C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80022880;
    }
    // 0x8002286C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022870: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80022874: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022878: nop

    // 0x8002287C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80022880:
    // 0x80022880: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022884: swc1        $f6, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f6.u32l;
    // 0x80022888: jal         0x800B9000
    // 0x8002288C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8002288C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
L_80022890:
    // 0x80022890: b           L_80022898
    // 0x80022894: nop

        goto L_80022898;
    // 0x80022894: nop

L_80022898:
    // 0x80022898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002289C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800228A0: jr          $ra
    // 0x800228A4: nop

    return;
    // 0x800228A4: nop

;}
RECOMP_FUNC void func_80076650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076650: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076654: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076658: nop

    // 0x8007665C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076660: nop

    // 0x80076664: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076668: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007666C: jr          $ra
    // 0x80076670: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076670: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076674: jr          $ra
    // 0x80076678: nop

    return;
    // 0x80076678: nop

    // 0x8007667C: jr          $ra
    // 0x80076680: nop

    return;
    // 0x80076680: nop

;}
RECOMP_FUNC void func_8006CBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CBBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CBC0: jal         0x80061488
    // 0x8006CBC4: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006CBC4: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    after_0:
    // 0x8006CBC8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006CBCC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006CBD0: b           L_8006CBE0
    // 0x8006CBD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006CBE0;
    // 0x8006CBD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006CBD8: b           L_8006CBE0
    // 0x8006CBDC: nop

        goto L_8006CBE0;
    // 0x8006CBDC: nop

L_8006CBE0:
    // 0x8006CBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CBE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CBE8: jr          $ra
    // 0x8006CBEC: nop

    return;
    // 0x8006CBEC: nop

;}
RECOMP_FUNC void func_80066A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066A84: jal         0x80061348
    // 0x80066A88: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066A88: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x80066A8C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066A90: b           L_80066AA0
    // 0x80066A94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066AA0;
    // 0x80066A94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066A98: b           L_80066AA0
    // 0x80066A9C: nop

        goto L_80066AA0;
    // 0x80066A9C: nop

L_80066AA0:
    // 0x80066AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066AA8: jr          $ra
    // 0x80066AAC: nop

    return;
    // 0x80066AAC: nop

;}
RECOMP_FUNC void alCSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA280: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800CA284: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CA288: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA28C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CA290: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800CA294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA298: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CA29C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800CA2A0: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800CA2A4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800CA2A8: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800CA2AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_800CA2B0:
    // 0x800CA2B0: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800CA2B4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800CA2B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800CA2BC: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800CA2C0: lw          $t1, 0x4C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4C);
    // 0x800CA2C4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800CA2C8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800CA2CC: sw          $t1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r9;
    // 0x800CA2D0: lbu         $t2, 0x8C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8C);
    // 0x800CA2D4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800CA2D8: sb          $t2, 0x96($a3)
    MEM_B(0X96, ctx->r7) = ctx->r10;
    // 0x800CA2DC: lbu         $t3, 0x9A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X9A);
    // 0x800CA2E0: sb          $t3, 0xA6($a3)
    MEM_B(0XA6, ctx->r7) = ctx->r11;
    // 0x800CA2E4: lw          $t4, 0xA4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XA4);
    // 0x800CA2E8: sw          $t4, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r12;
    // 0x800CA2EC: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800CA2F0: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x800CA2F4: lw          $t6, 0x48($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X48);
    // 0x800CA2F8: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
    // 0x800CA2FC: lbu         $t7, 0x8B($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X8B);
    // 0x800CA300: sb          $t7, 0x97($a3)
    MEM_B(0X97, ctx->r7) = ctx->r15;
    // 0x800CA304: lbu         $t8, 0x9B($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X9B);
    // 0x800CA308: sb          $t8, 0xA7($a3)
    MEM_B(0XA7, ctx->r7) = ctx->r24;
    // 0x800CA30C: lw          $t9, 0xA8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA8);
    // 0x800CA310: bne         $v0, $a0, L_800CA2B0
    if (ctx->r2 != ctx->r4) {
        // 0x800CA314: sw          $t9, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->r25;
            goto L_800CA2B0;
    }
    // 0x800CA314: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x800CA318: jr          $ra
    // 0x800CA31C: nop

    return;
    // 0x800CA31C: nop

;}
RECOMP_FUNC void SysMem_HeapAllocMark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC918: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BC91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC920: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BC924: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BC928: jal         0x800BC6EC
    // 0x800BC92C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800BC92C: nop

    after_0:
    // 0x800BC930: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BC934: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC938: nop

    // 0x800BC93C: bne         $t6, $zero, L_800BC950
    if (ctx->r14 != 0) {
        // 0x800BC940: nop
    
            goto L_800BC950;
    }
    // 0x800BC940: nop

    // 0x800BC944: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC948: b           L_800BC970
    // 0x800BC94C: nop

        goto L_800BC970;
    // 0x800BC94C: nop

L_800BC950:
    // 0x800BC950: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC954: jal         0x800BCC8C
    // 0x800BC958: nop

    SysMem_MarkHeap(rdram, ctx);
        goto after_1;
    // 0x800BC958: nop

    after_1:
    // 0x800BC95C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC960: b           L_800BC970
    // 0x800BC964: nop

        goto L_800BC970;
    // 0x800BC964: nop

    // 0x800BC968: b           L_800BC970
    // 0x800BC96C: nop

        goto L_800BC970;
    // 0x800BC96C: nop

L_800BC970:
    // 0x800BC970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC974: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BC978: jr          $ra
    // 0x800BC97C: nop

    return;
    // 0x800BC97C: nop

;}
RECOMP_FUNC void Main_ContInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE7A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BE7A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE7A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BE7AC: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x800BE7B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE7B4: sh          $t6, 0xE68($at)
    MEM_H(0XE68, ctx->r1) = ctx->r14;
    // 0x800BE7B8: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x800BE7BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE7C0: sh          $t7, 0xE74($at)
    MEM_H(0XE74, ctx->r1) = ctx->r15;
    // 0x800BE7C4: addiu       $t8, $zero, 0x200
    ctx->r24 = ADD32(0, 0X200);
    // 0x800BE7C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE7CC: sh          $t8, 0xEC0($at)
    MEM_H(0XEC0, ctx->r1) = ctx->r24;
    // 0x800BE7D0: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x800BE7D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE7D8: sh          $t9, 0xEEC($at)
    MEM_H(0XEEC, ctx->r1) = ctx->r25;
    // 0x800BE7DC: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x800BE7E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE7E4: sh          $t0, 0xFF4($at)
    MEM_H(0XFF4, ctx->r1) = ctx->r8;
    // 0x800BE7E8: addiu       $t1, $zero, 0x4000
    ctx->r9 = ADD32(0, 0X4000);
    // 0x800BE7EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE7F0: sh          $t1, 0x101C($at)
    MEM_H(0X101C, ctx->r1) = ctx->r9;
    // 0x800BE7F4: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800BE7F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE7FC: sh          $t2, 0x1038($at)
    MEM_H(0X1038, ctx->r1) = ctx->r10;
    // 0x800BE800: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x800BE804: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE808: sh          $t3, 0x1042($at)
    MEM_H(0X1042, ctx->r1) = ctx->r11;
    // 0x800BE80C: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x800BE810: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE814: sh          $t4, 0x10F2($at)
    MEM_H(0X10F2, ctx->r1) = ctx->r12;
    // 0x800BE818: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x800BE81C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE820: sh          $t5, 0x11A4($at)
    MEM_H(0X11A4, ctx->r1) = ctx->r13;
    // 0x800BE824: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800BE828: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE82C: sh          $t6, 0x11AC($at)
    MEM_H(0X11AC, ctx->r1) = ctx->r14;
    // 0x800BE830: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800BE834: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE838: sh          $t7, 0x1258($at)
    MEM_H(0X1258, ctx->r1) = ctx->r15;
    // 0x800BE83C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800BE840: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE844: sh          $t8, 0x1260($at)
    MEM_H(0X1260, ctx->r1) = ctx->r24;
    // 0x800BE848: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BE84C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE850: sh          $t9, 0x126C($at)
    MEM_H(0X126C, ctx->r1) = ctx->r25;
    // 0x800BE854: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800BE858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BE85C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE860: swc1        $f4, 0xE50($at)
    MEM_W(0XE50, ctx->r1) = ctx->f4.u32l;
    // 0x800BE864: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800BE868: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE86C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE870: swc1        $f6, 0xE5C($at)
    MEM_W(0XE5C, ctx->r1) = ctx->f6.u32l;
    // 0x800BE874: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE878: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BE87C: addiu       $a1, $a1, 0x252C
    ctx->r5 = ADD32(ctx->r5, 0X252C);
    // 0x800BE880: addiu       $a0, $a0, 0x2500
    ctx->r4 = ADD32(ctx->r4, 0X2500);
    // 0x800BE884: jal         0x800C42B0
    // 0x800BE888: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800BE888: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800BE88C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BE890: addiu       $a1, $a1, 0x2500
    ctx->r5 = ADD32(ctx->r5, 0X2500);
    // 0x800BE894: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800BE898: jal         0x800C4720
    // 0x800BE89C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE89C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800BE8A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE8A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BE8A8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BE8AC: addiu       $a2, $a2, 0x2540
    ctx->r6 = ADD32(ctx->r6, 0X2540);
    // 0x800BE8B0: addiu       $a1, $a1, 0x127C
    ctx->r5 = ADD32(ctx->r5, 0X127C);
    // 0x800BE8B4: jal         0x800C51D0
    // 0x800BE8B8: addiu       $a0, $a0, 0x2500
    ctx->r4 = ADD32(ctx->r4, 0X2500);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x800BE8B8: addiu       $a0, $a0, 0x2500
    ctx->r4 = ADD32(ctx->r4, 0X2500);
    after_2:
    // 0x800BE8BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BE8C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BE8C4:
    // 0x800BE8C4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE8C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE8CC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BE8D0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BE8D4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800BE8D8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800BE8DC: sw          $zero, 0xDA8($at)
    MEM_W(0XDA8, ctx->r1) = 0;
    // 0x800BE8E0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE8E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE8E8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800BE8EC: lwc1        $f8, 0xE50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XE50);
    // 0x800BE8F0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800BE8F4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800BE8F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE8FC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800BE900: swc1        $f8, 0xDC0($at)
    MEM_W(0XDC0, ctx->r1) = ctx->f8.u32l;
    // 0x800BE904: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE908: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE90C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800BE910: lwc1        $f10, 0xE5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE5C);
    // 0x800BE914: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800BE918: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800BE91C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE920: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800BE924: swc1        $f10, 0xDC4($at)
    MEM_W(0XDC4, ctx->r1) = ctx->f10.u32l;
    // 0x800BE928: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE92C: nop

    // 0x800BE930: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BE934: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800BE938: bne         $at, $zero, L_800BE8C4
    if (ctx->r1 != 0) {
        // 0x800BE93C: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_800BE8C4;
    }
    // 0x800BE93C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800BE940: b           L_800BE950
    // 0x800BE944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BE950;
    // 0x800BE944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BE948: b           L_800BE950
    // 0x800BE94C: nop

        goto L_800BE950;
    // 0x800BE94C: nop

L_800BE950:
    // 0x800BE950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE954: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BE958: jr          $ra
    // 0x800BE95C: nop

    return;
    // 0x800BE95C: nop

;}
RECOMP_FUNC void func_8006FBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FBDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FBE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FBE4: jal         0x80061348
    // 0x8006FBE8: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FBE8: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FBEC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FBF0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FBF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FBF8: beq         $v0, $zero, L_8006FC4C
    if (ctx->r2 == 0) {
        // 0x8006FBFC: nop
    
            goto L_8006FC4C;
    }
    // 0x8006FBFC: nop

    // 0x8006FC00: jal         0x80061348
    // 0x8006FC04: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FC04: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FC08: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FC0C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FC10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FC14: beq         $v0, $zero, L_8006FC4C
    if (ctx->r2 == 0) {
        // 0x8006FC18: nop
    
            goto L_8006FC4C;
    }
    // 0x8006FC18: nop

    // 0x8006FC1C: jal         0x80061348
    // 0x8006FC20: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FC20: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FC24: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FC28: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FC2C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FC30: beq         $v0, $zero, L_8006FC4C
    if (ctx->r2 == 0) {
        // 0x8006FC34: nop
    
            goto L_8006FC4C;
    }
    // 0x8006FC34: nop

    // 0x8006FC38: jal         0x80061348
    // 0x8006FC3C: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FC3C: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FC40: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FC44: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FC48: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FC4C:
    // 0x8006FC4C: b           L_8006FC5C
    // 0x8006FC50: nop

        goto L_8006FC5C;
    // 0x8006FC50: nop

    // 0x8006FC54: b           L_8006FC5C
    // 0x8006FC58: nop

        goto L_8006FC5C;
    // 0x8006FC58: nop

L_8006FC5C:
    // 0x8006FC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FC60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FC64: jr          $ra
    // 0x8006FC68: nop

    return;
    // 0x8006FC68: nop

;}
RECOMP_FUNC void func_80067408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067408: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006740C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067410: nop

    // 0x80067414: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x80067418: nop

    // 0x8006741C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067420: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067424: jr          $ra
    // 0x80067428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006742C: jr          $ra
    // 0x80067430: nop

    return;
    // 0x80067430: nop

    // 0x80067434: jr          $ra
    // 0x80067438: nop

    return;
    // 0x80067438: nop

;}
RECOMP_FUNC void func_800868C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800868C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800868C8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800868CC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800868D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800868D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800868D8: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x800868DC: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x800868E0: lhu         $t9, 0x46($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X46);
    // 0x800868E4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800868E8: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x800868EC: beq         $t0, $zero, L_80086A48
    if (ctx->r8 == 0) {
        // 0x800868F0: nop
    
            goto L_80086A48;
    }
    // 0x800868F0: nop

    // 0x800868F4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800868F8: jal         0x8008A518
    // 0x800868FC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800868FC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80086900: beq         $v0, $zero, L_80086A48
    if (ctx->r2 == 0) {
        // 0x80086904: nop
    
            goto L_80086A48;
    }
    // 0x80086904: nop

    // 0x80086908: lhu         $t1, 0x34($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X34);
    // 0x8008690C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80086910: bne         $t1, $at, L_80086928
    if (ctx->r9 != ctx->r1) {
        // 0x80086914: nop
    
            goto L_80086928;
    }
    // 0x80086914: nop

    // 0x80086918: jal         0x8008CE48
    // 0x8008691C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x8008691C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80086920: b           L_80086A84
    // 0x80086924: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086A84;
    // 0x80086924: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80086928:
    // 0x80086928: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x8008692C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80086930: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086934: bne         $at, $zero, L_80086A48
    if (ctx->r1 != 0) {
        // 0x80086938: nop
    
            goto L_80086A48;
    }
    // 0x80086938: nop

    // 0x8008693C: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80086940: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086944: beq         $at, $zero, L_80086A48
    if (ctx->r1 == 0) {
        // 0x80086948: nop
    
            goto L_80086A48;
    }
    // 0x80086948: nop

    // 0x8008694C: lhu         $t3, 0x34($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X34);
    // 0x80086950: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086954: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80086958: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008695C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80086960: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80086964: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80086968: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008696C: addiu       $t6, $t6, 0x7AE8
    ctx->r14 = ADD32(ctx->r14, 0X7AE8);
    // 0x80086970: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80086974: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80086978: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8008697C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80086980: nop

    // 0x80086984: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x80086988: nop

    // 0x8008698C: andi        $t0, $t8, 0x8000
    ctx->r8 = ctx->r24 & 0X8000;
    // 0x80086990: beq         $t0, $zero, L_80086A34
    if (ctx->r8 == 0) {
        // 0x80086994: nop
    
            goto L_80086A34;
    }
    // 0x80086994: nop

    // 0x80086998: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8008699C: nop

    // 0x800869A0: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800869A4: nop

    // 0x800869A8: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800869AC: beq         $t3, $zero, L_80086A18
    if (ctx->r11 == 0) {
        // 0x800869B0: nop
    
            goto L_80086A18;
    }
    // 0x800869B0: nop

    // 0x800869B4: jal         0x8008CE48
    // 0x800869B8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x800869B8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x800869BC: lh          $t4, 0x3C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3C);
    // 0x800869C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800869C4: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x800869C8: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
    // 0x800869CC: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
    // 0x800869D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800869D4: jal         0x8008A368
    // 0x800869D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8008A368(rdram, ctx);
        goto after_3;
    // 0x800869D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x800869DC: lhu         $t5, 0x34($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X34);
    // 0x800869E0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800869E4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800869E8: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x800869EC: sh          $t6, 0xBE8($t7)
    MEM_H(0XBE8, ctx->r15) = ctx->r14;
    // 0x800869F0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800869F4: nop

    // 0x800869F8: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x800869FC: nop

    // 0x80086A00: ori         $t0, $t8, 0x200
    ctx->r8 = ctx->r24 | 0X200;
    // 0x80086A04: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x80086A08: b           L_80086A84
    // 0x80086A0C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80086A84;
    // 0x80086A0C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80086A10: b           L_80086A2C
    // 0x80086A14: nop

        goto L_80086A2C;
    // 0x80086A14: nop

L_80086A18:
    // 0x80086A18: jal         0x8008CE48
    // 0x80086A1C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x80086A1C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_4:
    // 0x80086A20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086A24: jal         0x8008A730
    // 0x80086A28: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_8008A730(rdram, ctx);
        goto after_5;
    // 0x80086A28: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_5:
L_80086A2C:
    // 0x80086A2C: b           L_80086A48
    // 0x80086A30: nop

        goto L_80086A48;
    // 0x80086A30: nop

L_80086A34:
    // 0x80086A34: jal         0x8008CE48
    // 0x80086A38: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80086A38: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_6:
    // 0x80086A3C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086A40: jal         0x8008A730
    // 0x80086A44: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_7;
    // 0x80086A44: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_7:
L_80086A48:
    // 0x80086A48: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80086A4C: lhu         $t2, 0x101C($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X101C);
    // 0x80086A50: lhu         $t1, 0x46($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X46);
    // 0x80086A54: nop

    // 0x80086A58: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80086A5C: beq         $t3, $zero, L_80086A74
    if (ctx->r11 == 0) {
        // 0x80086A60: nop
    
            goto L_80086A74;
    }
    // 0x80086A60: nop

    // 0x80086A64: jal         0x8008CE48
    // 0x80086A68: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80086A68: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_8:
    // 0x80086A6C: b           L_80086A84
    // 0x80086A70: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086A84;
    // 0x80086A70: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80086A74:
    // 0x80086A74: b           L_80086A84
    // 0x80086A78: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80086A84;
    // 0x80086A78: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80086A7C: b           L_80086A84
    // 0x80086A80: nop

        goto L_80086A84;
    // 0x80086A80: nop

L_80086A84:
    // 0x80086A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80086A88: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80086A8C: jr          $ra
    // 0x80086A90: nop

    return;
    // 0x80086A90: nop

;}
RECOMP_FUNC void func_80072EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072EF8: jal         0x8005F064
    // 0x80072EFC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80072EFC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x80072F00: b           L_80072F10
    // 0x80072F04: nop

        goto L_80072F10;
    // 0x80072F04: nop

    // 0x80072F08: b           L_80072F10
    // 0x80072F0C: nop

        goto L_80072F10;
    // 0x80072F0C: nop

L_80072F10:
    // 0x80072F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072F18: jr          $ra
    // 0x80072F1C: nop

    return;
    // 0x80072F1C: nop

;}
RECOMP_FUNC void func_80031718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031718: jr          $ra
    // 0x8003171C: nop

    return;
    // 0x8003171C: nop

    // 0x80031720: jr          $ra
    // 0x80031724: nop

    return;
    // 0x80031724: nop

;}
RECOMP_FUNC void func_8006F538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F538: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F53C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F540: nop

    // 0x8006F544: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F548: nop

    // 0x8006F54C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F550: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F554: jr          $ra
    // 0x8006F558: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F558: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F55C: jr          $ra
    // 0x8006F560: nop

    return;
    // 0x8006F560: nop

    // 0x8006F564: jr          $ra
    // 0x8006F568: nop

    return;
    // 0x8006F568: nop

;}
RECOMP_FUNC void func_80071FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071FF0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071FF4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071FF8: nop

    // 0x80071FFC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80072000: nop

    // 0x80072004: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80072008: jr          $ra
    // 0x8007200C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007200C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072010: jr          $ra
    // 0x80072014: nop

    return;
    // 0x80072014: nop

    // 0x80072018: jr          $ra
    // 0x8007201C: nop

    return;
    // 0x8007201C: nop

;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C42A0: jr          $ra
    // 0x800C42A4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x800C42A4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void func_80084244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084244: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008424C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80084250: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80084254: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80084258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008425C: lh          $t7, 0xC14($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC14);
    // 0x80084260: nop

    // 0x80084264: bne         $t7, $at, L_8008452C
    if (ctx->r15 != ctx->r1) {
        // 0x80084268: nop
    
            goto L_8008452C;
    }
    // 0x80084268: nop

    // 0x8008426C: jal         0x800AEFD4
    // 0x80084270: nop

    ContPak_GetReadFileResult(rdram, ctx);
        goto after_0;
    // 0x80084270: nop

    after_0:
    // 0x80084274: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80084278: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008427C: nop

    // 0x80084280: slti        $at, $t8, 0x1000
    ctx->r1 = SIGNED(ctx->r24) < 0X1000 ? 1 : 0;
    // 0x80084284: bne         $at, $zero, L_800842CC
    if (ctx->r1 != 0) {
        // 0x80084288: nop
    
            goto L_800842CC;
    }
    // 0x80084288: nop

    // 0x8008428C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80084290: lhu         $t9, 0x7A10($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7A10);
    // 0x80084294: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084298: ori         $t0, $t9, 0x4000
    ctx->r8 = ctx->r25 | 0X4000;
    // 0x8008429C: sh          $t0, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = ctx->r8;
    // 0x800842A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800842A4: nop

    // 0x800842A8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800842AC: nop

    // 0x800842B0: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x800842B4: beq         $t3, $zero, L_800842C4
    if (ctx->r11 == 0) {
        // 0x800842B8: nop
    
            goto L_800842C4;
    }
    // 0x800842B8: nop

    // 0x800842BC: b           L_800847DC
    // 0x800842C0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800847DC;
    // 0x800842C0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_800842C4:
    // 0x800842C4: b           L_800847DC
    // 0x800842C8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800847DC;
    // 0x800842C8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800842CC:
    // 0x800842CC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800842D0: nop

    // 0x800842D4: bne         $t4, $zero, L_80084518
    if (ctx->r12 != 0) {
        // 0x800842D8: nop
    
            goto L_80084518;
    }
    // 0x800842D8: nop

    // 0x800842DC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800842E0: nop

    // 0x800842E4: sh          $zero, 0xC14($t5)
    MEM_H(0XC14, ctx->r13) = 0;
    // 0x800842E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800842EC: nop

    // 0x800842F0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800842F4: nop

    // 0x800842F8: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x800842FC: bne         $t8, $zero, L_8008434C
    if (ctx->r24 != 0) {
        // 0x80084300: nop
    
            goto L_8008434C;
    }
    // 0x80084300: nop

    // 0x80084304: jal         0x800BC6EC
    // 0x80084308: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80084308: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    after_1:
    // 0x8008430C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084310: nop

    // 0x80084314: lh          $t0, 0xBFE($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XBFE);
    // 0x80084318: nop

    // 0x8008431C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80084320: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80084324: sw          $v0, 0xC04($t2)
    MEM_W(0XC04, ctx->r10) = ctx->r2;
    // 0x80084328: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8008432C: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    // 0x80084330: lh          $t4, 0xBFE($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XBFE);
    // 0x80084334: lw          $a1, 0xC10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC10);
    // 0x80084338: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008433C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80084340: lw          $a0, 0xC04($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC04);
    // 0x80084344: jal         0x800BCFCC
    // 0x80084348: nop

    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x80084348: nop

    after_2:
L_8008434C:
    // 0x8008434C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80084350: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80084354: lh          $t8, 0xBFE($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XBFE);
    // 0x80084358: addiu       $t9, $t9, 0x7AE8
    ctx->r25 = ADD32(ctx->r25, 0X7AE8);
    // 0x8008435C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80084360: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80084364: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80084368: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x8008436C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80084370: lw          $a1, 0xC10($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC10);
    // 0x80084374: jal         0x8008C558
    // 0x80084378: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    func_8008C558(rdram, ctx);
        goto after_3;
    // 0x80084378: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    after_3:
    // 0x8008437C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084380: nop

    // 0x80084384: lh          $t2, 0xBFE($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XBFE);
    // 0x80084388: nop

    // 0x8008438C: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80084390: sh          $t4, 0xBFE($t1)
    MEM_H(0XBFE, ctx->r9) = ctx->r12;
    // 0x80084394: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084398: nop

    // 0x8008439C: lh          $t6, 0xBFE($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBFE);
    // 0x800843A0: nop

    // 0x800843A4: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x800843A8: bne         $at, $zero, L_800844F0
    if (ctx->r1 != 0) {
        // 0x800843AC: nop
    
            goto L_800844F0;
    }
    // 0x800843AC: nop

    // 0x800843B0: jal         0x8008C280
    // 0x800843B4: nop

    func_8008C280(rdram, ctx);
        goto after_4;
    // 0x800843B4: nop

    after_4:
    // 0x800843B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800843BC: jal         0x8008C160
    // 0x800843C0: nop

    func_8008C160(rdram, ctx);
        goto after_5;
    // 0x800843C0: nop

    after_5:
    // 0x800843C4: bne         $v0, $zero, L_800843FC
    if (ctx->r2 != 0) {
        // 0x800843C8: nop
    
            goto L_800843FC;
    }
    // 0x800843C8: nop

    // 0x800843CC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800843D0: nop

    // 0x800843D4: bne         $t3, $zero, L_800843FC
    if (ctx->r11 != 0) {
        // 0x800843D8: nop
    
            goto L_800843FC;
    }
    // 0x800843D8: nop

    // 0x800843DC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800843E0: nop

    // 0x800843E4: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x800843E8: nop

    // 0x800843EC: ori         $t9, $t0, 0x200
    ctx->r25 = ctx->r8 | 0X200;
    // 0x800843F0: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
    // 0x800843F4: b           L_800847DC
    // 0x800843F8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800847DC;
    // 0x800843F8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800843FC:
    // 0x800843FC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80084400: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80084404: blez        $t7, L_800844AC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80084408: nop
    
            goto L_800844AC;
    }
    // 0x80084408: nop

L_8008440C:
    // 0x8008440C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80084410: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80084414: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80084418: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x8008441C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80084420: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80084424: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80084428: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x8008442C: lhu         $t1, 0x7AE8($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X7AE8);
    // 0x80084430: nop

    // 0x80084434: andi        $t5, $t1, 0x8000
    ctx->r13 = ctx->r9 & 0X8000;
    // 0x80084438: bne         $t5, $zero, L_80084484
    if (ctx->r13 != 0) {
        // 0x8008443C: nop
    
            goto L_80084484;
    }
    // 0x8008443C: nop

    // 0x80084440: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80084444: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80084448: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8008444C: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80084450: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80084454: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80084458: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8008445C: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80084460: addu        $t9, $t3, $t0
    ctx->r25 = ADD32(ctx->r11, ctx->r8);
    // 0x80084464: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x80084468: nop

    // 0x8008446C: ori         $t7, $t8, 0x8000
    ctx->r15 = ctx->r24 | 0X8000;
    // 0x80084470: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x80084474: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80084478: nop

    // 0x8008447C: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80084480: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
L_80084484:
    // 0x80084484: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80084488: nop

    // 0x8008448C: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x80084490: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80084494: beq         $at, $zero, L_800844AC
    if (ctx->r1 == 0) {
        // 0x80084498: sw          $t5, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r13;
            goto L_800844AC;
    }
    // 0x80084498: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8008449C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800844A0: nop

    // 0x800844A4: bgtz        $t6, L_8008440C
    if (SIGNED(ctx->r14) > 0) {
        // 0x800844A8: nop
    
            goto L_8008440C;
    }
    // 0x800844A8: nop

L_800844AC:
    // 0x800844AC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800844B0: nop

    // 0x800844B4: lhu         $t0, 0x0($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X0);
    // 0x800844B8: nop

    // 0x800844BC: andi        $t8, $t0, 0x8000
    ctx->r24 = ctx->r8 & 0X8000;
    // 0x800844C0: beq         $t8, $zero, L_800844E8
    if (ctx->r24 == 0) {
        // 0x800844C4: nop
    
            goto L_800844E8;
    }
    // 0x800844C4: nop

    // 0x800844C8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800844CC: nop

    // 0x800844D0: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800844D4: nop

    // 0x800844D8: ori         $t2, $t9, 0x200
    ctx->r10 = ctx->r25 | 0X200;
    // 0x800844DC: sh          $t2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r10;
    // 0x800844E0: b           L_800847DC
    // 0x800844E4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800847DC;
    // 0x800844E4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800844E8:
    // 0x800844E8: b           L_800847DC
    // 0x800844EC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_800847DC;
    // 0x800844EC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800844F0:
    // 0x800844F0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800844F4: nop

    // 0x800844F8: lh          $a1, 0xBFE($t4)
    ctx->r5 = MEM_H(ctx->r12, 0XBFE);
    // 0x800844FC: jal         0x8008C2E8
    // 0x80084500: addiu       $a0, $t4, 0xBEE
    ctx->r4 = ADD32(ctx->r12, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_6;
    // 0x80084500: addiu       $a0, $t4, 0xBEE
    ctx->r4 = ADD32(ctx->r12, 0XBEE);
    after_6:
    // 0x80084504: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80084508: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008450C: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80084510: jal         0x800AEA98
    // 0x80084514: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_7;
    // 0x80084514: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_7:
L_80084518:
    // 0x80084518: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8008451C: nop

    // 0x80084520: lh          $v0, 0x4($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X4);
    // 0x80084524: b           L_800847DC
    // 0x80084528: nop

        goto L_800847DC;
    // 0x80084528: nop

L_8008452C:
    // 0x8008452C: jal         0x800AEBF4
    // 0x80084530: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_8;
    // 0x80084530: nop

    after_8:
    // 0x80084534: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084538: nop

    // 0x8008453C: sw          $v0, 0xC00($t5)
    MEM_W(0XC00, ctx->r13) = ctx->r2;
    // 0x80084540: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80084544: addiu       $at, $zero, 0x1005
    ctx->r1 = ADD32(0, 0X1005);
    // 0x80084548: lw          $t3, 0xC00($t6)
    ctx->r11 = MEM_W(ctx->r14, 0XC00);
    // 0x8008454C: nop

    // 0x80084550: bne         $t3, $at, L_80084740
    if (ctx->r11 != ctx->r1) {
        // 0x80084554: nop
    
            goto L_80084740;
    }
    // 0x80084554: nop

    // 0x80084558: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008455C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80084560: lh          $t8, 0xBFE($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XBFE);
    // 0x80084564: addiu       $t2, $t2, 0x7AE8
    ctx->r10 = ADD32(ctx->r10, 0X7AE8);
    // 0x80084568: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008456C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80084570: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80084574: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80084578: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8008457C: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x80084580: lhu         $t4, 0x0($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X0);
    // 0x80084584: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80084588: and         $t1, $t4, $at
    ctx->r9 = ctx->r12 & ctx->r1;
    // 0x8008458C: sh          $t1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r9;
    // 0x80084590: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084594: nop

    // 0x80084598: lh          $t6, 0xBFE($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBFE);
    // 0x8008459C: nop

    // 0x800845A0: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x800845A4: sh          $t3, 0xBFE($t5)
    MEM_H(0XBFE, ctx->r13) = ctx->r11;
    // 0x800845A8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800845AC: nop

    // 0x800845B0: lh          $t8, 0xBFE($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XBFE);
    // 0x800845B4: nop

    // 0x800845B8: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800845BC: bne         $at, $zero, L_80084704
    if (ctx->r1 != 0) {
        // 0x800845C0: nop
    
            goto L_80084704;
    }
    // 0x800845C0: nop

    // 0x800845C4: jal         0x8008C280
    // 0x800845C8: nop

    func_8008C280(rdram, ctx);
        goto after_9;
    // 0x800845C8: nop

    after_9:
    // 0x800845CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800845D0: jal         0x8008C160
    // 0x800845D4: nop

    func_8008C160(rdram, ctx);
        goto after_10;
    // 0x800845D4: nop

    after_10:
    // 0x800845D8: bne         $v0, $zero, L_80084610
    if (ctx->r2 != 0) {
        // 0x800845DC: nop
    
            goto L_80084610;
    }
    // 0x800845DC: nop

    // 0x800845E0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800845E4: nop

    // 0x800845E8: bne         $t9, $zero, L_80084610
    if (ctx->r25 != 0) {
        // 0x800845EC: nop
    
            goto L_80084610;
    }
    // 0x800845EC: nop

    // 0x800845F0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800845F4: nop

    // 0x800845F8: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x800845FC: nop

    // 0x80084600: ori         $t1, $t4, 0x200
    ctx->r9 = ctx->r12 | 0X200;
    // 0x80084604: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80084608: b           L_800847DC
    // 0x8008460C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800847DC;
    // 0x8008460C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80084610:
    // 0x80084610: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80084614: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80084618: blez        $t7, L_800846C0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8008461C: nop
    
            goto L_800846C0;
    }
    // 0x8008461C: nop

L_80084620:
    // 0x80084620: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80084624: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80084628: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8008462C: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80084630: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80084634: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80084638: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8008463C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80084640: lhu         $t5, 0x7AE8($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7AE8);
    // 0x80084644: nop

    // 0x80084648: andi        $t0, $t5, 0x8000
    ctx->r8 = ctx->r13 & 0X8000;
    // 0x8008464C: bne         $t0, $zero, L_80084698
    if (ctx->r8 != 0) {
        // 0x80084650: nop
    
            goto L_80084698;
    }
    // 0x80084650: nop

    // 0x80084654: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80084658: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008465C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80084660: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80084664: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80084668: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008466C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80084670: addiu       $t4, $t4, 0x7AE8
    ctx->r12 = ADD32(ctx->r12, 0X7AE8);
    // 0x80084674: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x80084678: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8008467C: nop

    // 0x80084680: ori         $t7, $t2, 0x8000
    ctx->r15 = ctx->r10 | 0X8000;
    // 0x80084684: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x80084688: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008468C: nop

    // 0x80084690: addiu       $t3, $t6, -0x1
    ctx->r11 = ADD32(ctx->r14, -0X1);
    // 0x80084694: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_80084698:
    // 0x80084698: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8008469C: nop

    // 0x800846A0: addiu       $t0, $t5, 0x1
    ctx->r8 = ADD32(ctx->r13, 0X1);
    // 0x800846A4: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800846A8: beq         $at, $zero, L_800846C0
    if (ctx->r1 == 0) {
        // 0x800846AC: sw          $t0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r8;
            goto L_800846C0;
    }
    // 0x800846AC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800846B0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800846B4: nop

    // 0x800846B8: bgtz        $t8, L_80084620
    if (SIGNED(ctx->r24) > 0) {
        // 0x800846BC: nop
    
            goto L_80084620;
    }
    // 0x800846BC: nop

L_800846C0:
    // 0x800846C0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800846C4: nop

    // 0x800846C8: lhu         $t4, 0x0($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X0);
    // 0x800846CC: nop

    // 0x800846D0: andi        $t2, $t4, 0x8000
    ctx->r10 = ctx->r12 & 0X8000;
    // 0x800846D4: beq         $t2, $zero, L_800846FC
    if (ctx->r10 == 0) {
        // 0x800846D8: nop
    
            goto L_800846FC;
    }
    // 0x800846D8: nop

    // 0x800846DC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800846E0: nop

    // 0x800846E4: lhu         $t1, 0x0($t7)
    ctx->r9 = MEM_HU(ctx->r15, 0X0);
    // 0x800846E8: nop

    // 0x800846EC: ori         $t6, $t1, 0x200
    ctx->r14 = ctx->r9 | 0X200;
    // 0x800846F0: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x800846F4: b           L_800847DC
    // 0x800846F8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800847DC;
    // 0x800846F8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800846FC:
    // 0x800846FC: b           L_800847DC
    // 0x80084700: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_800847DC;
    // 0x80084700: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80084704:
    // 0x80084704: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084708: nop

    // 0x8008470C: lh          $a1, 0xBFE($t3)
    ctx->r5 = MEM_H(ctx->r11, 0XBFE);
    // 0x80084710: jal         0x8008C2E8
    // 0x80084714: addiu       $a0, $t3, 0xBEE
    ctx->r4 = ADD32(ctx->r11, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_11;
    // 0x80084714: addiu       $a0, $t3, 0xBEE
    ctx->r4 = ADD32(ctx->r11, 0XBEE);
    after_11:
    // 0x80084718: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008471C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084720: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80084724: jal         0x800AEA98
    // 0x80084728: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_12;
    // 0x80084728: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_12:
    // 0x8008472C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084730: nop

    // 0x80084734: lh          $v0, 0x4($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X4);
    // 0x80084738: b           L_800847DC
    // 0x8008473C: nop

        goto L_800847DC;
    // 0x8008473C: nop

L_80084740:
    // 0x80084740: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084744: nop

    // 0x80084748: lw          $t8, 0xC00($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC00);
    // 0x8008474C: nop

    // 0x80084750: slti        $at, $t8, 0x1000
    ctx->r1 = SIGNED(ctx->r24) < 0X1000 ? 1 : 0;
    // 0x80084754: bne         $at, $zero, L_80084778
    if (ctx->r1 != 0) {
        // 0x80084758: nop
    
            goto L_80084778;
    }
    // 0x80084758: nop

    // 0x8008475C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80084760: lhu         $t9, 0x7A10($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7A10);
    // 0x80084764: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084768: ori         $t4, $t9, 0x4000
    ctx->r12 = ctx->r25 | 0X4000;
    // 0x8008476C: sh          $t4, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = ctx->r12;
    // 0x80084770: b           L_800847DC
    // 0x80084774: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800847DC;
    // 0x80084774: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80084778:
    // 0x80084778: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008477C: nop

    // 0x80084780: lw          $t1, 0xC00($t2)
    ctx->r9 = MEM_W(ctx->r10, 0XC00);
    // 0x80084784: nop

    // 0x80084788: bltz        $t1, L_800847C0
    if (SIGNED(ctx->r9) < 0) {
        // 0x8008478C: nop
    
            goto L_800847C0;
    }
    // 0x8008478C: nop

    // 0x80084790: slti        $at, $t1, 0x1000
    ctx->r1 = SIGNED(ctx->r9) < 0X1000 ? 1 : 0;
    // 0x80084794: beq         $at, $zero, L_800847C0
    if (ctx->r1 == 0) {
        // 0x80084798: nop
    
            goto L_800847C0;
    }
    // 0x80084798: nop

    // 0x8008479C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800847A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800847A4: lw          $a0, 0xC00($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC00);
    // 0x800847A8: lw          $a3, 0xC10($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC10);
    // 0x800847AC: jal         0x800AEE6C
    // 0x800847B0: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileReadParams(rdram, ctx);
        goto after_13;
    // 0x800847B0: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_13:
    // 0x800847B4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800847B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800847BC: sh          $t7, 0xC14($t3)
    MEM_H(0XC14, ctx->r11) = ctx->r15;
L_800847C0:
    // 0x800847C0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800847C4: nop

    // 0x800847C8: lh          $v0, 0x4($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X4);
    // 0x800847CC: b           L_800847DC
    // 0x800847D0: nop

        goto L_800847DC;
    // 0x800847D0: nop

    // 0x800847D4: b           L_800847DC
    // 0x800847D8: nop

        goto L_800847DC;
    // 0x800847D8: nop

L_800847DC:
    // 0x800847DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800847E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800847E4: jr          $ra
    // 0x800847E8: nop

    return;
    // 0x800847E8: nop

;}
RECOMP_FUNC void AudioDriver_InitSoundPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9C74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B9C78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B9C7C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x800B9C80: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B9C84: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800B9C88: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800B9C8C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9C90: addiu       $t8, $t8, -0x3078
    ctx->r24 = ADD32(ctx->r24, -0X3078);
    // 0x800B9C94: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800B9C98: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9C9C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9CA0: addiu       $t9, $zero, 0x54
    ctx->r25 = ADD32(0, 0X54);
    // 0x800B9CA4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800B9CA8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9CAC: addiu       $a0, $a0, -0x2F8
    ctx->r4 = ADD32(ctx->r4, -0X2F8);
    // 0x800B9CB0: addiu       $a1, $zero, 0x159
    ctx->r5 = ADD32(0, 0X159);
    // 0x800B9CB4: jal         0x800C7950
    // 0x800B9CB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800B9CB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800B9CBC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9CC0: sw          $v0, -0x17B0($at)
    MEM_W(-0X17B0, ctx->r1) = ctx->r2;
    // 0x800B9CC4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9CC8: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9CCC: jal         0x800C9E14
    // 0x800B9CD0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    alSndpNew(rdram, ctx);
        goto after_1;
    // 0x800B9CD0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800B9CD4: b           L_800B9CDC
    // 0x800B9CD8: nop

        goto L_800B9CDC;
    // 0x800B9CD8: nop

L_800B9CDC:
    // 0x800B9CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9CE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B9CE4: jr          $ra
    // 0x800B9CE8: nop

    return;
    // 0x800B9CE8: nop

;}
RECOMP_FUNC void func_8005D150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D150: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D158: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005D15C: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D160: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D164: lui         $a2, 0x809E
    ctx->r6 = S32(0X809E << 16);
    // 0x8005D168: addiu       $a2, $a2, 0x55D8
    ctx->r6 = ADD32(ctx->r6, 0X55D8);
    // 0x8005D16C: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D170: jal         0x800BD1FC
    // 0x8005D174: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8005D174: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_0:
    // 0x8005D178: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D17C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005D180: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x8005D184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D188: jal         0x800BD218
    // 0x8005D18C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8005D18C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8005D190: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005D194: addiu       $t6, $t6, 0x5B0
    ctx->r14 = ADD32(ctx->r14, 0X5B0);
    // 0x8005D198: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8005D19C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D1A0: sw          $t7, 0x658($at)
    MEM_W(0X658, ctx->r1) = ctx->r15;
    // 0x8005D1A4: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D1A8: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D1AC: lui         $a2, 0x809E
    ctx->r6 = S32(0X809E << 16);
    // 0x8005D1B0: addiu       $a2, $a2, 0x55D4
    ctx->r6 = ADD32(ctx->r6, 0X55D4);
    // 0x8005D1B4: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D1B8: jal         0x800BD1FC
    // 0x8005D1BC: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8005D1BC: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_2:
    // 0x8005D1C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D1C4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005D1C8: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x8005D1CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D1D0: jal         0x800BD218
    // 0x8005D1D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8005D1D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8005D1D8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8005D1DC: addiu       $t8, $t8, 0x5B0
    ctx->r24 = ADD32(ctx->r24, 0X5B0);
    // 0x8005D1E0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005D1E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D1E8: sw          $t9, 0x660($at)
    MEM_W(0X660, ctx->r1) = ctx->r25;
    // 0x8005D1EC: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D1F0: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D1F4: lui         $a2, 0x809E
    ctx->r6 = S32(0X809E << 16);
    // 0x8005D1F8: addiu       $a2, $a2, 0x55DC
    ctx->r6 = ADD32(ctx->r6, 0X55DC);
    // 0x8005D1FC: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D200: jal         0x800BD1FC
    // 0x8005D204: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x8005D204: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_4:
    // 0x8005D208: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D20C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005D210: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x8005D214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D218: jal         0x800BD218
    // 0x8005D21C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x8005D21C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x8005D220: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8005D224:
    // 0x8005D224: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005D228: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8005D22C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8005D230: lbu         $t1, 0x5B0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X5B0);
    // 0x8005D234: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D238: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8005D23C: sb          $t1, 0x668($at)
    MEM_B(0X668, ctx->r1) = ctx->r9;
    // 0x8005D240: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005D244: nop

    // 0x8005D248: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005D24C: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8005D250: bne         $at, $zero, L_8005D224
    if (ctx->r1 != 0) {
        // 0x8005D254: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8005D224;
    }
    // 0x8005D254: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8005D258: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D25C: sw          $zero, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = 0;
    // 0x8005D260: jal         0x8005D394
    // 0x8005D264: nop

    func_8005D394(rdram, ctx);
        goto after_6;
    // 0x8005D264: nop

    after_6:
    // 0x8005D268: jal         0x8005D2B0
    // 0x8005D26C: nop

    func_8005D2B0(rdram, ctx);
        goto after_7;
    // 0x8005D26C: nop

    after_7:
    // 0x8005D270: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D274: sw          $v0, 0x648($at)
    MEM_W(0X648, ctx->r1) = ctx->r2;
    // 0x8005D278: jal         0x8005D6BC
    // 0x8005D27C: nop

    func_8005D6BC(rdram, ctx);
        goto after_8;
    // 0x8005D27C: nop

    after_8:
    // 0x8005D280: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D284: sw          $v0, 0x650($at)
    MEM_W(0X650, ctx->r1) = ctx->r2;
    // 0x8005D288: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D28C: sw          $zero, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = 0;
    // 0x8005D290: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D294: sw          $zero, 0xE64($at)
    MEM_W(0XE64, ctx->r1) = 0;
    // 0x8005D298: b           L_8005D2A0
    // 0x8005D29C: nop

        goto L_8005D2A0;
    // 0x8005D29C: nop

L_8005D2A0:
    // 0x8005D2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D2A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D2A8: jr          $ra
    // 0x8005D2AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005D2AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80067334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067334: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067338: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006733C: nop

    // 0x80067340: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80067344: nop

    // 0x80067348: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006734C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067350: jr          $ra
    // 0x80067354: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067354: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067358: jr          $ra
    // 0x8006735C: nop

    return;
    // 0x8006735C: nop

    // 0x80067360: jr          $ra
    // 0x80067364: nop

    return;
    // 0x80067364: nop

;}
RECOMP_FUNC void func_8006C8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C8E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C8EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C8F0: jal         0x8005F064
    // 0x8006C8F4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C8F4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_0:
    // 0x8006C8F8: b           L_8006C908
    // 0x8006C8FC: nop

        goto L_8006C908;
    // 0x8006C8FC: nop

    // 0x8006C900: b           L_8006C908
    // 0x8006C904: nop

        goto L_8006C908;
    // 0x8006C904: nop

L_8006C908:
    // 0x8006C908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C910: jr          $ra
    // 0x8006C914: nop

    return;
    // 0x8006C914: nop

;}
RECOMP_FUNC void func_80072D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072D50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072D54: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072D58: nop

    // 0x80072D5C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072D60: nop

    // 0x80072D64: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072D68: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072D6C: jr          $ra
    // 0x80072D70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072D70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072D74: jr          $ra
    // 0x80072D78: nop

    return;
    // 0x80072D78: nop

    // 0x80072D7C: jr          $ra
    // 0x80072D80: nop

    return;
    // 0x80072D80: nop

;}
