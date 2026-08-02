#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8008D708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D708: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8008D70C: nop

    // 0x8008D710: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8008D714: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8008D718: jr          $ra
    // 0x8008D71C: nop

    return;
    // 0x8008D71C: nop

    // 0x8008D720: jr          $ra
    // 0x8008D724: nop

    return;
    // 0x8008D724: nop

;}
RECOMP_FUNC void func_800B32E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B32E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B32E8: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800B32EC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800B32F0: nop

    // 0x800B32F4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B32F8: lhu         $v0, 0xC($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0XC);
    // 0x800B32FC: jr          $ra
    // 0x800B3300: nop

    return;
    // 0x800B3300: nop

    // 0x800B3304: jr          $ra
    // 0x800B3308: nop

    return;
    // 0x800B3308: nop

    // 0x800B330C: jr          $ra
    // 0x800B3310: nop

    return;
    // 0x800B3310: nop

;}
RECOMP_FUNC void func_80071914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007191C: jal         0x80061348
    // 0x80071920: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071920: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071924: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071928: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007192C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071930: beq         $v0, $zero, L_80071984
    if (ctx->r2 == 0) {
        // 0x80071934: nop
    
            goto L_80071984;
    }
    // 0x80071934: nop

    // 0x80071938: jal         0x80061348
    // 0x8007193C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007193C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x80071940: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071944: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071948: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007194C: beq         $v0, $zero, L_80071984
    if (ctx->r2 == 0) {
        // 0x80071950: nop
    
            goto L_80071984;
    }
    // 0x80071950: nop

    // 0x80071954: jal         0x80061348
    // 0x80071958: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071958: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x8007195C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071960: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071964: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071968: beq         $v0, $zero, L_80071984
    if (ctx->r2 == 0) {
        // 0x8007196C: nop
    
            goto L_80071984;
    }
    // 0x8007196C: nop

    // 0x80071970: jal         0x80061348
    // 0x80071974: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071974: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x80071978: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007197C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80071980: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071984:
    // 0x80071984: b           L_80071994
    // 0x80071988: nop

        goto L_80071994;
    // 0x80071988: nop

    // 0x8007198C: b           L_80071994
    // 0x80071990: nop

        goto L_80071994;
    // 0x80071990: nop

L_80071994:
    // 0x80071994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007199C: jr          $ra
    // 0x800719A0: nop

    return;
    // 0x800719A0: nop

;}
RECOMP_FUNC void func_80067EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067EC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067EC4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067EC8: nop

    // 0x80067ECC: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067ED0: nop

    // 0x80067ED4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067ED8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067EDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067EE0: beq         $v0, $zero, L_80067EFC
    if (ctx->r2 == 0) {
        // 0x80067EE4: nop
    
            goto L_80067EFC;
    }
    // 0x80067EE4: nop

    // 0x80067EE8: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067EEC: nop

    // 0x80067EF0: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067EF4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067EF8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067EFC:
    // 0x80067EFC: jr          $ra
    // 0x80067F00: nop

    return;
    // 0x80067F00: nop

    // 0x80067F04: jr          $ra
    // 0x80067F08: nop

    return;
    // 0x80067F08: nop

    // 0x80067F0C: jr          $ra
    // 0x80067F10: nop

    return;
    // 0x80067F10: nop

;}
RECOMP_FUNC void func_8006F148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F150: jal         0x80061348
    // 0x8006F154: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F154: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    after_0:
    // 0x8006F158: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F15C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F160: b           L_8006F170
    // 0x8006F164: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F170;
    // 0x8006F164: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F168: b           L_8006F170
    // 0x8006F16C: nop

        goto L_8006F170;
    // 0x8006F16C: nop

L_8006F170:
    // 0x8006F170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F178: jr          $ra
    // 0x8006F17C: nop

    return;
    // 0x8006F17C: nop

;}
RECOMP_FUNC void func_8002A028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A028: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002A02C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8002A030:
    // 0x8002A030: lh          $t6, 0x6($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6);
    // 0x8002A034: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002A038: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002A03C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002A040: lh          $t8, 0x2590($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2590);
    // 0x8002A044: nop

    // 0x8002A048: bne         $t8, $zero, L_8002A058
    if (ctx->r24 != 0) {
        // 0x8002A04C: sh          $t8, 0x2($sp)
        MEM_H(0X2, ctx->r29) = ctx->r24;
            goto L_8002A058;
    }
    // 0x8002A04C: sh          $t8, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r24;
    // 0x8002A050: b           L_8002A0DC
    // 0x8002A054: nop

        goto L_8002A0DC;
    // 0x8002A054: nop

L_8002A058:
    // 0x8002A058: sh          $zero, 0x4($sp)
    MEM_H(0X4, ctx->r29) = 0;
L_8002A05C:
    // 0x8002A05C: lh          $t9, 0x4($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4);
    // 0x8002A060: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8002A064: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002A068: lbu         $t0, -0x6500($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6500);
    // 0x8002A06C: lh          $t1, 0x2($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2);
    // 0x8002A070: nop

    // 0x8002A074: bne         $t0, $t1, L_8002A084
    if (ctx->r8 != ctx->r9) {
        // 0x8002A078: nop
    
            goto L_8002A084;
    }
    // 0x8002A078: nop

    // 0x8002A07C: b           L_8002A0A4
    // 0x8002A080: nop

        goto L_8002A0A4;
    // 0x8002A080: nop

L_8002A084:
    // 0x8002A084: lh          $t2, 0x4($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4);
    // 0x8002A088: nop

    // 0x8002A08C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8002A090: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8002A094: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8002A098: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8002A09C: bne         $at, $zero, L_8002A05C
    if (ctx->r1 != 0) {
        // 0x8002A0A0: sh          $t3, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r11;
            goto L_8002A05C;
    }
    // 0x8002A0A0: sh          $t3, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r11;
L_8002A0A4:
    // 0x8002A0A4: lh          $t6, 0x4($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4);
    // 0x8002A0A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002A0AC: bne         $t6, $at, L_8002A0BC
    if (ctx->r14 != ctx->r1) {
        // 0x8002A0B0: nop
    
            goto L_8002A0BC;
    }
    // 0x8002A0B0: nop

    // 0x8002A0B4: b           L_8002A0DC
    // 0x8002A0B8: nop

        goto L_8002A0DC;
    // 0x8002A0B8: nop

L_8002A0BC:
    // 0x8002A0BC: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x8002A0C0: nop

    // 0x8002A0C4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002A0C8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002A0CC: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002A0D0: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x8002A0D4: bne         $at, $zero, L_8002A030
    if (ctx->r1 != 0) {
        // 0x8002A0D8: sh          $t8, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r24;
            goto L_8002A030;
    }
    // 0x8002A0D8: sh          $t8, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r24;
L_8002A0DC:
    // 0x8002A0DC: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
    // 0x8002A0E0: b           L_8002A0F0
    // 0x8002A0E4: nop

        goto L_8002A0F0;
    // 0x8002A0E4: nop

    // 0x8002A0E8: b           L_8002A0F0
    // 0x8002A0EC: nop

        goto L_8002A0F0;
    // 0x8002A0EC: nop

L_8002A0F0:
    // 0x8002A0F0: jr          $ra
    // 0x8002A0F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002A0F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006B988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B988: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B98C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B990: nop

    // 0x8006B994: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006B998: nop

    // 0x8006B99C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006B9A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B9A4: jr          $ra
    // 0x8006B9A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B9A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B9AC: jr          $ra
    // 0x8006B9B0: nop

    return;
    // 0x8006B9B0: nop

    // 0x8006B9B4: jr          $ra
    // 0x8006B9B8: nop

    return;
    // 0x8006B9B8: nop

;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAE10: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800CAE14: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800CAE18: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800CAE1C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800CAE20: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x800CAE24: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800CAE28: beq         $at, $zero, L_800CAE90
    if (ctx->r1 == 0) {
        // 0x800CAE2C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800CAE90;
    }
    // 0x800CAE2C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800CAE30: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800CAE34: bne         $at, $zero, L_800CAE88
    if (ctx->r1 != 0) {
        // 0x800CAE38: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800CAE88;
    }
    // 0x800CAE38: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800CAE3C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800CAE40: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800CAE44: addiu       $v1, $v1, 0x210
    ctx->r3 = ADD32(ctx->r3, 0X210);
    // 0x800CAE48: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800CAE4C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800CAE50: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800CAE54: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800CAE58: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800CAE5C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800CAE60: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800CAE64: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800CAE68: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800CAE6C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800CAE70: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800CAE74: nop

    // 0x800CAE78: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800CAE7C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800CAE80: jr          $ra
    // 0x800CAE84: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800CAE84: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800CAE88:
    // 0x800CAE88: jr          $ra
    // 0x800CAE8C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800CAE8C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800CAE90:
    // 0x800CAE90: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800CAE94: beq         $at, $zero, L_800CAFA8
    if (ctx->r1 == 0) {
        // 0x800CAE98: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_800CAFA8;
    }
    // 0x800CAE98: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800CAE9C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800CAEA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAEA4: ldc1        $f10, 0x238($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X238);
    // 0x800CAEA8: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800CAEAC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800CAEB0: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800CAEB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CAEB8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CAEBC: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800CAEC0: nop

    // 0x800CAEC4: bc1fl       L_800CAEF4
    if (!c1cs) {
        // 0x800CAEC8: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800CAEF4;
    }
    goto skip_0;
    // 0x800CAEC8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800CAECC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CAED0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CAED4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CAED8: nop

    // 0x800CAEDC: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x800CAEE0: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800CAEE4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800CAEE8: b           L_800CAF10
    // 0x800CAEEC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_800CAF10;
    // 0x800CAEEC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800CAEF0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800CAEF4:
    // 0x800CAEF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CAEF8: nop

    // 0x800CAEFC: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x800CAF00: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800CAF04: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800CAF08: nop

    // 0x800CAF0C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_800CAF10:
    // 0x800CAF10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAF14: ldc1        $f18, 0x240($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X240);
    // 0x800CAF18: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x800CAF1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAF20: ldc1        $f6, 0x248($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X248);
    // 0x800CAF24: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800CAF28: addiu       $v1, $v1, 0x210
    ctx->r3 = ADD32(ctx->r3, 0X210);
    // 0x800CAF2C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800CAF30: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800CAF34: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800CAF38: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800CAF3C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800CAF40: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800CAF44: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800CAF48: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800CAF4C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800CAF50: nop

    // 0x800CAF54: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800CAF58: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800CAF5C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800CAF60: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800CAF64: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800CAF68: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800CAF6C: bne         $t9, $zero, L_800CAF8C
    if (ctx->r25 != 0) {
        // 0x800CAF70: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800CAF8C;
    }
    // 0x800CAF70: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800CAF74: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800CAF78: nop

    // 0x800CAF7C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800CAF80: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800CAF84: jr          $ra
    // 0x800CAF88: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800CAF88: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800CAF8C:
    // 0x800CAF8C: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800CAF90: nop

    // 0x800CAF94: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800CAF98: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800CAF9C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800CAFA0: jr          $ra
    // 0x800CAFA4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800CAFA4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800CAFA8:
    // 0x800CAFA8: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800CAFAC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAFB0: bc1t        L_800CAFC4
    if (c1cs) {
        // 0x800CAFB4: nop
    
            goto L_800CAFC4;
    }
    // 0x800CAFB4: nop

    // 0x800CAFB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAFBC: jr          $ra
    // 0x800CAFC0: lwc1        $f0, 0x5B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B0);
    return;
    // 0x800CAFC0: lwc1        $f0, 0x5B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B0);
L_800CAFC4:
    // 0x800CAFC4: lwc1        $f0, 0x250($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X250);
    // 0x800CAFC8: jr          $ra
    // 0x800CAFCC: nop

    return;
    // 0x800CAFCC: nop

;}
RECOMP_FUNC void func_80070660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070668: jal         0x80061348
    // 0x8007066C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007066C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070670: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070674: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070678: beq         $v0, $zero, L_800706C8
    if (ctx->r2 == 0) {
        // 0x8007067C: nop
    
            goto L_800706C8;
    }
    // 0x8007067C: nop

    // 0x80070680: jal         0x80061348
    // 0x80070684: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070684: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070688: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007068C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070690: beq         $v0, $zero, L_800706C8
    if (ctx->r2 == 0) {
        // 0x80070694: nop
    
            goto L_800706C8;
    }
    // 0x80070694: nop

    // 0x80070698: jal         0x80061348
    // 0x8007069C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007069C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800706A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800706A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800706A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800706AC: beq         $v0, $zero, L_800706C8
    if (ctx->r2 == 0) {
        // 0x800706B0: nop
    
            goto L_800706C8;
    }
    // 0x800706B0: nop

    // 0x800706B4: jal         0x80061348
    // 0x800706B8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800706B8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800706BC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800706C0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800706C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800706C8:
    // 0x800706C8: b           L_800706D8
    // 0x800706CC: nop

        goto L_800706D8;
    // 0x800706CC: nop

    // 0x800706D0: b           L_800706D8
    // 0x800706D4: nop

        goto L_800706D8;
    // 0x800706D4: nop

L_800706D8:
    // 0x800706D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800706DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800706E0: jr          $ra
    // 0x800706E4: nop

    return;
    // 0x800706E4: nop

;}
RECOMP_FUNC void func_80076B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076B84: jal         0x80061488
    // 0x80076B88: addiu       $a0, $zero, 0x4F7
    ctx->r4 = ADD32(0, 0X4F7);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076B88: addiu       $a0, $zero, 0x4F7
    ctx->r4 = ADD32(0, 0X4F7);
    after_0:
    // 0x80076B8C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076B90: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076B94: b           L_80076BA4
    // 0x80076B98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076BA4;
    // 0x80076B98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076B9C: b           L_80076BA4
    // 0x80076BA0: nop

        goto L_80076BA4;
    // 0x80076BA0: nop

L_80076BA4:
    // 0x80076BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076BAC: jr          $ra
    // 0x80076BB0: nop

    return;
    // 0x80076BB0: nop

;}
RECOMP_FUNC void func_8006DCC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DCC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DCCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DCD0: jal         0x80061348
    // 0x8006DCD4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DCD4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x8006DCD8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DCDC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DCE0: beq         $v0, $zero, L_8006DCF8
    if (ctx->r2 == 0) {
        // 0x8006DCE4: nop
    
            goto L_8006DCF8;
    }
    // 0x8006DCE4: nop

    // 0x8006DCE8: jal         0x80061348
    // 0x8006DCEC: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DCEC: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_1:
    // 0x8006DCF0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DCF4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DCF8:
    // 0x8006DCF8: b           L_8006DD08
    // 0x8006DCFC: nop

        goto L_8006DD08;
    // 0x8006DCFC: nop

    // 0x8006DD00: b           L_8006DD08
    // 0x8006DD04: nop

        goto L_8006DD08;
    // 0x8006DD04: nop

L_8006DD08:
    // 0x8006DD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DD0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DD10: jr          $ra
    // 0x8006DD14: nop

    return;
    // 0x8006DD14: nop

;}
RECOMP_FUNC void func_80032844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032844: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80032848: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8003284C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80032850: nop

    // 0x80032854: swc1        $f4, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f4.u32l;
    // 0x80032858: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003285C: nop

    // 0x80032860: swc1        $f6, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f6.u32l;
    // 0x80032864: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80032868: nop

    // 0x8003286C: swc1        $f8, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->f8.u32l;
    // 0x80032870: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80032874: nop

    // 0x80032878: swc1        $f10, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f10.u32l;
    // 0x8003287C: b           L_80032884
    // 0x80032880: nop

        goto L_80032884;
    // 0x80032880: nop

L_80032884:
    // 0x80032884: jr          $ra
    // 0x80032888: nop

    return;
    // 0x80032888: nop

;}
RECOMP_FUNC void func_8006BA2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BA2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BA30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BA34: jal         0x80061488
    // 0x8006BA38: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006BA38: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    after_0:
    // 0x8006BA3C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006BA40: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006BA44: b           L_8006BA54
    // 0x8006BA48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006BA54;
    // 0x8006BA48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006BA4C: b           L_8006BA54
    // 0x8006BA50: nop

        goto L_8006BA54;
    // 0x8006BA50: nop

L_8006BA54:
    // 0x8006BA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BA58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BA5C: jr          $ra
    // 0x8006BA60: nop

    return;
    // 0x8006BA60: nop

;}
RECOMP_FUNC void func_8006FF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FF2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FF30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FF34: jal         0x80061348
    // 0x8006FF38: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FF38: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    after_0:
    // 0x8006FF3C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006FF40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FF44: bne         $v0, $zero, L_8006FF60
    if (ctx->r2 != 0) {
        // 0x8006FF48: nop
    
            goto L_8006FF60;
    }
    // 0x8006FF48: nop

    // 0x8006FF4C: jal         0x80061348
    // 0x8006FF50: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FF50: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x8006FF54: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FF58: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FF5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006FF60:
    // 0x8006FF60: b           L_8006FF70
    // 0x8006FF64: nop

        goto L_8006FF70;
    // 0x8006FF64: nop

    // 0x8006FF68: b           L_8006FF70
    // 0x8006FF6C: nop

        goto L_8006FF70;
    // 0x8006FF6C: nop

L_8006FF70:
    // 0x8006FF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FF78: jr          $ra
    // 0x8006FF7C: nop

    return;
    // 0x8006FF7C: nop

;}
RECOMP_FUNC void func_8008CA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CA00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CA04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CA08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008CA0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA10: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8008CA14: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x8008CA18: nop

    // 0x8008CA1C: bne         $t7, $at, L_8008CAAC
    if (ctx->r15 != ctx->r1) {
        // 0x8008CA20: nop
    
            goto L_8008CAAC;
    }
    // 0x8008CA20: nop

    // 0x8008CA24: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA28: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8008CA2C: sh          $t8, 0xBEC($t9)
    MEM_H(0XBEC, ctx->r25) = ctx->r24;
    // 0x8008CA30: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA34: nop

    // 0x8008CA38: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8008CA3C: nop

    // 0x8008CA40: andi        $t2, $t1, 0x800
    ctx->r10 = ctx->r9 & 0X800;
    // 0x8008CA44: beq         $t2, $zero, L_8008CA60
    if (ctx->r10 == 0) {
        // 0x8008CA48: nop
    
            goto L_8008CA60;
    }
    // 0x8008CA48: nop

    // 0x8008CA4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA50: jal         0x8008C6E0
    // 0x8008CA54: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8008C6E0(rdram, ctx);
        goto after_0;
    // 0x8008CA54: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_0:
    // 0x8008CA58: b           L_8008CBF8
    // 0x8008CA5C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_8008CBF8;
    // 0x8008CA5C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_8008CA60:
    // 0x8008CA60: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA64: nop

    // 0x8008CA68: lw          $a0, 0xC10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC10);
    // 0x8008CA6C: jal         0x8008C3D4
    // 0x8008CA70: nop

    func_8008C3D4(rdram, ctx);
        goto after_1;
    // 0x8008CA70: nop

    after_1:
    // 0x8008CA74: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA78: nop

    // 0x8008CA7C: lw          $a0, 0xC10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC10);
    // 0x8008CA80: jal         0x8008C4AC
    // 0x8008CA84: addiu       $a1, $t4, 0xE
    ctx->r5 = ADD32(ctx->r12, 0XE);
    func_8008C4AC(rdram, ctx);
        goto after_2;
    // 0x8008CA84: addiu       $a1, $t4, 0xE
    ctx->r5 = ADD32(ctx->r12, 0XE);
    after_2:
    // 0x8008CA88: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA8C: nop

    // 0x8008CA90: lw          $a0, 0xC10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC10);
    // 0x8008CA94: jal         0x8008C528
    // 0x8008CA98: addiu       $a1, $t5, 0xE
    ctx->r5 = ADD32(ctx->r13, 0XE);
    func_8008C528(rdram, ctx);
        goto after_3;
    // 0x8008CA98: addiu       $a1, $t5, 0xE
    ctx->r5 = ADD32(ctx->r13, 0XE);
    after_3:
    // 0x8008CA9C: b           L_8008CBF8
    // 0x8008CAA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8008CBF8;
    // 0x8008CAA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8008CAA4: b           L_8008CBF0
    // 0x8008CAA8: nop

        goto L_8008CBF0;
    // 0x8008CAA8: nop

L_8008CAAC:
    // 0x8008CAAC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008CAB0: nop

    // 0x8008CAB4: sh          $zero, 0xBEC($t6)
    MEM_H(0XBEC, ctx->r14) = 0;
    // 0x8008CAB8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008CABC: lh          $t7, 0x7A16($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7A16);
    // 0x8008CAC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008CAC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008CAC8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008CACC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008CAD0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008CAD4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008CAD8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8008CADC: addiu       $t9, $t9, 0x7AE8
    ctx->r25 = ADD32(ctx->r25, 0X7AE8);
    // 0x8008CAE0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8008CAE4: lhu         $t1, 0x10($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X10);
    // 0x8008CAE8: lhu         $t3, 0x1E($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X1E);
    // 0x8008CAEC: nop

    // 0x8008CAF0: bne         $t1, $t3, L_8008CB70
    if (ctx->r9 != ctx->r11) {
        // 0x8008CAF4: nop
    
            goto L_8008CB70;
    }
    // 0x8008CAF4: nop

    // 0x8008CAF8: lhu         $t4, 0x12($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X12);
    // 0x8008CAFC: lhu         $t5, 0x20($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X20);
    // 0x8008CB00: nop

    // 0x8008CB04: bne         $t4, $t5, L_8008CB70
    if (ctx->r12 != ctx->r13) {
        // 0x8008CB08: nop
    
            goto L_8008CB70;
    }
    // 0x8008CB08: nop

    // 0x8008CB0C: lhu         $t6, 0x14($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X14);
    // 0x8008CB10: lhu         $t7, 0x22($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X22);
    // 0x8008CB14: nop

    // 0x8008CB18: bne         $t6, $t7, L_8008CB70
    if (ctx->r14 != ctx->r15) {
        // 0x8008CB1C: nop
    
            goto L_8008CB70;
    }
    // 0x8008CB1C: nop

    // 0x8008CB20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008CB24: lh          $t9, 0x7A16($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7A16);
    // 0x8008CB28: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB2C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8008CB30: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x8008CB34: lw          $a0, 0xC04($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC04);
    // 0x8008CB38: jal         0x8008C634
    // 0x8008CB3C: addiu       $a1, $t8, 0xE
    ctx->r5 = ADD32(ctx->r24, 0XE);
    func_8008C634(rdram, ctx);
        goto after_4;
    // 0x8008CB3C: addiu       $a1, $t8, 0xE
    ctx->r5 = ADD32(ctx->r24, 0XE);
    after_4:
    // 0x8008CB40: beq         $v0, $zero, L_8008CB68
    if (ctx->r2 == 0) {
        // 0x8008CB44: nop
    
            goto L_8008CB68;
    }
    // 0x8008CB44: nop

    // 0x8008CB48: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB4C: nop

    // 0x8008CB50: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x8008CB54: nop

    // 0x8008CB58: ori         $t0, $t5, 0x4
    ctx->r8 = ctx->r13 | 0X4;
    // 0x8008CB5C: sh          $t0, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r8;
    // 0x8008CB60: b           L_8008CBF8
    // 0x8008CB64: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8008CBF8;
    // 0x8008CB64: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8008CB68:
    // 0x8008CB68: b           L_8008CBF8
    // 0x8008CB6C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_8008CBF8;
    // 0x8008CB6C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_8008CB70:
    // 0x8008CB70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008CB74: lh          $t6, 0x7A16($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7A16);
    // 0x8008CB78: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008CB80: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x8008CB84: lw          $t1, 0xC04($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC04);
    // 0x8008CB88: nop

    // 0x8008CB8C: bne         $t1, $zero, L_8008CBB0
    if (ctx->r9 != 0) {
        // 0x8008CB90: nop
    
            goto L_8008CBB0;
    }
    // 0x8008CB90: nop

    // 0x8008CB94: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB98: nop

    // 0x8008CB9C: lhu         $t8, 0x2($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X2);
    // 0x8008CBA0: nop

    // 0x8008CBA4: ori         $t5, $t8, 0x2
    ctx->r13 = ctx->r24 | 0X2;
    // 0x8008CBA8: b           L_8008CBE8
    // 0x8008CBAC: sh          $t5, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r13;
        goto L_8008CBE8;
    // 0x8008CBAC: sh          $t5, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r13;
L_8008CBB0:
    // 0x8008CBB0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008CBB4: lh          $t4, 0x7A16($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7A16);
    // 0x8008CBB8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008CBBC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8008CBC0: addu        $t2, $t0, $t6
    ctx->r10 = ADD32(ctx->r8, ctx->r14);
    // 0x8008CBC4: lw          $a1, 0xC04($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC04);
    // 0x8008CBC8: lw          $a0, 0xC10($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC10);
    // 0x8008CBCC: jal         0x800BCFCC
    // 0x8008CBD0: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x8008CBD0: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_5:
    // 0x8008CBD4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008CBD8: nop

    // 0x8008CBDC: lw          $a0, 0xC10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC10);
    // 0x8008CBE0: jal         0x8008C528
    // 0x8008CBE4: addiu       $a1, $t7, 0xE
    ctx->r5 = ADD32(ctx->r15, 0XE);
    func_8008C528(rdram, ctx);
        goto after_6;
    // 0x8008CBE4: addiu       $a1, $t7, 0xE
    ctx->r5 = ADD32(ctx->r15, 0XE);
    after_6:
L_8008CBE8:
    // 0x8008CBE8: b           L_8008CBF8
    // 0x8008CBEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8008CBF8;
    // 0x8008CBEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8008CBF0:
    // 0x8008CBF0: b           L_8008CBF8
    // 0x8008CBF4: nop

        goto L_8008CBF8;
    // 0x8008CBF4: nop

L_8008CBF8:
    // 0x8008CBF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CBFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CC00: jr          $ra
    // 0x8008CC04: nop

    return;
    // 0x8008CC04: nop

;}
RECOMP_FUNC void func_800B8F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B8F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8F74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B8F78: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800B8F7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8F80: sw          $t6, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r14;
    // 0x800B8F84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B8F88: jal         0x800BB3D4
    // 0x800B8F8C: nop

    AudioDriver_UpdateSeqID(rdram, ctx);
        goto after_0;
    // 0x800B8F8C: nop

    after_0:
    // 0x800B8F90: b           L_800B8F98
    // 0x800B8F94: nop

        goto L_800B8F98;
    // 0x800B8F94: nop

L_800B8F98:
    // 0x800B8F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B8FA0: jr          $ra
    // 0x800B8FA4: nop

    return;
    // 0x800B8FA4: nop

;}
RECOMP_FUNC void func_8002856C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002856C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80028570: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80028574: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80028578: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002857C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80028580: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80028584: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80028588: addiu       $t7, $t7, -0x4834
    ctx->r15 = ADD32(ctx->r15, -0X4834);
    // 0x8002858C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80028590: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80028594: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80028598: lbu         $at, 0x8($t7)
    ctx->r1 = MEM_BU(ctx->r15, 0X8);
    // 0x8002859C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800285A0: sb          $at, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r1;
    // 0x800285A4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800285A8: lh          $s0, 0x5A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X5A);
    // 0x800285AC: nop

    // 0x800285B0: beq         $s0, $zero, L_800285CC
    if (ctx->r16 == 0) {
        // 0x800285B4: nop
    
            goto L_800285CC;
    }
    // 0x800285B4: nop

    // 0x800285B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800285BC: beq         $s0, $at, L_8002863C
    if (ctx->r16 == ctx->r1) {
        // 0x800285C0: nop
    
            goto L_8002863C;
    }
    // 0x800285C0: nop

    // 0x800285C4: b           L_80028A00
    // 0x800285C8: nop

        goto L_80028A00;
    // 0x800285C8: nop

L_800285CC:
    // 0x800285CC: jal         0x80028468
    // 0x800285D0: nop

    func_80028468(rdram, ctx);
        goto after_0;
    // 0x800285D0: nop

    after_0:
    // 0x800285D4: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x800285D8: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x800285DC: nop

    // 0x800285E0: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x800285E4: lbu         $t1, 0x30($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X30);
    // 0x800285E8: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800285EC: sltu        $s0, $zero, $t1
    ctx->r16 = 0 < ctx->r9 ? 1 : 0;
    // 0x800285F0: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x800285F4: beq         $s0, $zero, L_8002862C
    if (ctx->r16 == 0) {
        // 0x800285F8: sh          $t1, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r9;
            goto L_8002862C;
    }
    // 0x800285F8: sh          $t1, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r9;
L_800285FC:
    // 0x800285FC: lh          $a0, 0x54($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X54);
    // 0x80028600: jal         0x80029C8C
    // 0x80028604: nop

    func_80029C8C(rdram, ctx);
        goto after_1;
    // 0x80028604: nop

    after_1:
    // 0x80028608: lh          $t3, 0x56($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X56);
    // 0x8002860C: nop

    // 0x80028610: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80028614: lbu         $t4, 0x30($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X30);
    // 0x80028618: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8002861C: sltu        $s0, $zero, $t4
    ctx->r16 = 0 < ctx->r12 ? 1 : 0;
    // 0x80028620: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
    // 0x80028624: bne         $s0, $zero, L_800285FC
    if (ctx->r16 != 0) {
        // 0x80028628: sh          $t4, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r12;
            goto L_800285FC;
    }
    // 0x80028628: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
L_8002862C:
    // 0x8002862C: jal         0x80029ED8
    // 0x80028630: nop

    func_80029ED8(rdram, ctx);
        goto after_2;
    // 0x80028630: nop

    after_2:
    // 0x80028634: b           L_80028A00
    // 0x80028638: nop

        goto L_80028A00;
    // 0x80028638: nop

L_8002863C:
    // 0x8002863C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028640: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
    // 0x80028644: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80028648: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x8002864C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80028650: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028654: sw          $zero, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = 0;
    // 0x80028658: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002865C: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
    // 0x80028660: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028664: sh          $zero, 0x1B48($at)
    MEM_H(0X1B48, ctx->r1) = 0;
    // 0x80028668: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002866C: nop

    // 0x80028670: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80028674: nop

    // 0x80028678: beq         $t7, $zero, L_800286E0
    if (ctx->r15 == 0) {
        // 0x8002867C: sw          $t7, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r15;
            goto L_800286E0;
    }
    // 0x8002867C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
L_80028680:
    // 0x80028680: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80028684: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80028688: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8002868C: lh          $t1, 0x2($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X2);
    // 0x80028690: nop

    // 0x80028694: bne         $t1, $t0, L_800286C8
    if (ctx->r9 != ctx->r8) {
        // 0x80028698: nop
    
            goto L_800286C8;
    }
    // 0x80028698: nop

    // 0x8002869C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800286A0: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x800286A4: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x800286A8: nop

    // 0x800286AC: bne         $t2, $t4, L_800286C8
    if (ctx->r10 != ctx->r12) {
        // 0x800286B0: nop
    
            goto L_800286C8;
    }
    // 0x800286B0: nop

    // 0x800286B4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800286B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800286BC: sw          $t3, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = ctx->r11;
    // 0x800286C0: b           L_800286E0
    // 0x800286C4: nop

        goto L_800286E0;
    // 0x800286C4: nop

L_800286C8:
    // 0x800286C8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800286CC: nop

    // 0x800286D0: lw          $t8, 0x18($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X18);
    // 0x800286D4: nop

    // 0x800286D8: bne         $t8, $zero, L_80028680
    if (ctx->r24 != 0) {
        // 0x800286DC: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_80028680;
    }
    // 0x800286DC: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_800286E0:
    // 0x800286E0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800286E4: lw          $t6, 0x306C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X306C);
    // 0x800286E8: nop

    // 0x800286EC: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800286F0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800286F4: nop

    // 0x800286F8: beq         $t7, $zero, L_80028780
    if (ctx->r15 == 0) {
        // 0x800286FC: nop
    
            goto L_80028780;
    }
    // 0x800286FC: nop

L_80028700:
    // 0x80028700: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80028704: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80028708: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8002870C: lh          $t0, 0x2($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2);
    // 0x80028710: nop

    // 0x80028714: bne         $t0, $t9, L_80028734
    if (ctx->r8 != ctx->r25) {
        // 0x80028718: nop
    
            goto L_80028734;
    }
    // 0x80028718: nop

    // 0x8002871C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80028720: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x80028724: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80028728: nop

    // 0x8002872C: beq         $t2, $t4, L_8002873C
    if (ctx->r10 == ctx->r12) {
        // 0x80028730: nop
    
            goto L_8002873C;
    }
    // 0x80028730: nop

L_80028734:
    // 0x80028734: b           L_80028780
    // 0x80028738: nop

        goto L_80028780;
    // 0x80028738: nop

L_8002873C:
    // 0x8002873C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80028740: nop

    // 0x80028744: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x80028748: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002874C: lh          $t5, 0x1B48($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X1B48);
    // 0x80028750: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028754: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80028758: sh          $t8, 0x1B48($at)
    MEM_H(0X1B48, ctx->r1) = ctx->r24;
    // 0x8002875C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80028760: nop

    // 0x80028764: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80028768: nop

    // 0x8002876C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80028770: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80028774: nop

    // 0x80028778: bne         $t0, $zero, L_80028700
    if (ctx->r8 != 0) {
        // 0x8002877C: nop
    
            goto L_80028700;
    }
    // 0x8002877C: nop

L_80028780:
    // 0x80028780: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80028784: addiu       $t9, $t9, 0x2578
    ctx->r25 = ADD32(ctx->r25, 0X2578);
    // 0x80028788: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8002878C: nop

    // 0x80028790: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80028794: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80028798: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002879C: nop

    // 0x800287A0: beq         $t2, $zero, L_80028844
    if (ctx->r10 == 0) {
        // 0x800287A4: nop
    
            goto L_80028844;
    }
    // 0x800287A4: nop

L_800287A8:
    // 0x800287A8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800287AC: nop

    // 0x800287B0: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x800287B4: nop

    // 0x800287B8: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x800287BC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800287C0: nop

    // 0x800287C4: lh          $t8, 0x2($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X2);
    // 0x800287C8: nop

    // 0x800287CC: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800287D0: bne         $at, $zero, L_80028828
    if (ctx->r1 != 0) {
        // 0x800287D4: nop
    
            goto L_80028828;
    }
    // 0x800287D4: nop

    // 0x800287D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800287DC: bne         $t8, $at, L_800287F4
    if (ctx->r24 != ctx->r1) {
        // 0x800287E0: nop
    
            goto L_800287F4;
    }
    // 0x800287E0: nop

    // 0x800287E4: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x800287E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800287EC: beq         $t6, $at, L_80028828
    if (ctx->r14 == ctx->r1) {
        // 0x800287F0: nop
    
            goto L_80028828;
    }
    // 0x800287F0: nop

L_800287F4:
    // 0x800287F4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800287F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800287FC: lh          $t0, 0x2($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X2);
    // 0x80028800: nop

    // 0x80028804: bne         $t0, $at, L_8002881C
    if (ctx->r8 != ctx->r1) {
        // 0x80028808: nop
    
            goto L_8002881C;
    }
    // 0x80028808: nop

    // 0x8002880C: lh          $t9, 0x4($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X4);
    // 0x80028810: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80028814: beq         $t9, $at, L_80028828
    if (ctx->r25 == ctx->r1) {
        // 0x80028818: nop
    
            goto L_80028828;
    }
    // 0x80028818: nop

L_8002881C:
    // 0x8002881C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80028820: jal         0x800299C4
    // 0x80028824: nop

    func_800299C4(rdram, ctx);
        goto after_3;
    // 0x80028824: nop

    after_3:
L_80028828:
    // 0x80028828: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8002882C: nop

    // 0x80028830: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80028834: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80028838: nop

    // 0x8002883C: bne         $t2, $zero, L_800287A8
    if (ctx->r10 != 0) {
        // 0x80028840: nop
    
            goto L_800287A8;
    }
    // 0x80028840: nop

L_80028844:
    // 0x80028844: jal         0x800BC6EC
    // 0x80028848: addiu       $a0, $zero, 0x6E0
    ctx->r4 = ADD32(0, 0X6E0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x80028848: addiu       $a0, $zero, 0x6E0
    ctx->r4 = ADD32(0, 0X6E0);
    after_4:
    // 0x8002884C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80028850: jal         0x800BC6EC
    // 0x80028854: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x80028854: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_5:
    // 0x80028858: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002885C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
L_80028860:
    // 0x80028860: lh          $t4, 0x56($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X56);
    // 0x80028864: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80028868: addiu       $t8, $t8, 0x24D8
    ctx->r24 = ADD32(ctx->r24, 0X24D8);
    // 0x8002886C: sll         $t3, $t4, 5
    ctx->r11 = S32(ctx->r12 << 5);
    // 0x80028870: addu        $t5, $t3, $t8
    ctx->r13 = ADD32(ctx->r11, ctx->r24);
    // 0x80028874: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80028878: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002887C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80028880: nop

    // 0x80028884: sw          $t6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r14;
    // 0x80028888: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8002888C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80028890: lw          $a0, 0x18($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18);
    // 0x80028894: sw          $t9, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r25;
    // 0x80028898: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8002889C: nop

    // 0x800288A0: lw          $a1, 0x1C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1C);
    // 0x800288A4: jal         0x800B1B04
    // 0x800288A8: nop

    func_800B1B04(rdram, ctx);
        goto after_6;
    // 0x800288A8: nop

    after_6:
    // 0x800288AC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800288B0: jal         0x80099E2C
    // 0x800288B4: nop

    func_80099E2C(rdram, ctx);
        goto after_7;
    // 0x800288B4: nop

    after_7:
    // 0x800288B8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800288BC: addiu       $t2, $zero, 0x148
    ctx->r10 = ADD32(0, 0X148);
    // 0x800288C0: sw          $t2, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r10;
    // 0x800288C4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800288C8: addiu       $t3, $zero, 0x46
    ctx->r11 = ADD32(0, 0X46);
    // 0x800288CC: sw          $t3, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r11;
    // 0x800288D0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800288D4: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800288D8: sh          $t5, 0xC4($t6)
    MEM_H(0XC4, ctx->r14) = ctx->r13;
    // 0x800288DC: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x800288E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800288E4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800288E8: sb          $zero, 0x1B0C($at)
    MEM_B(0X1B0C, ctx->r1) = 0;
    // 0x800288EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800288F0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800288F4: nop

    // 0x800288F8: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x800288FC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80028900: nop

    // 0x80028904: lwc1        $f20, 0x8($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80028908: nop

    // 0x8002890C: swc1        $f20, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f20.u32l;
    // 0x80028910: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80028914: nop

    // 0x80028918: swc1        $f20, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f20.u32l;
    // 0x8002891C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80028920: nop

    // 0x80028924: addiu       $t4, $t2, 0x160
    ctx->r12 = ADD32(ctx->r10, 0X160);
    // 0x80028928: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x8002892C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80028930: nop

    // 0x80028934: addiu       $t8, $t3, 0x40
    ctx->r24 = ADD32(ctx->r11, 0X40);
    // 0x80028938: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8002893C: lh          $t5, 0x56($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X56);
    // 0x80028940: nop

    // 0x80028944: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80028948: sll         $t0, $t6, 16
    ctx->r8 = S32(ctx->r14 << 16);
    // 0x8002894C: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80028950: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80028954: bne         $at, $zero, L_80028860
    if (ctx->r1 != 0) {
        // 0x80028958: sh          $t6, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r14;
            goto L_80028860;
    }
    // 0x80028958: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
    // 0x8002895C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80028960: lw          $t7, 0x306C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X306C);
    // 0x80028964: nop

    // 0x80028968: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8002896C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80028970: lh          $t1, 0x1B48($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1B48);
    // 0x80028974: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x80028978: blez        $t1, L_800289F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002897C: nop
    
            goto L_800289F8;
    }
    // 0x8002897C: nop

L_80028980:
    // 0x80028980: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80028984: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80028988: swc1        $f6, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->f6.u32l;
    // 0x8002898C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80028990: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80028994: swc1        $f8, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f8.u32l;
    // 0x80028998: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002899C: nop

    // 0x800289A0: lh          $a0, 0x0($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X0);
    // 0x800289A4: jal         0x8002BB9C
    // 0x800289A8: nop

    func_8002BB9C(rdram, ctx);
        goto after_8;
    // 0x800289A8: nop

    after_8:
    // 0x800289AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800289B0: swc1        $f0, -0x69E0($at)
    MEM_W(-0X69E0, ctx->r1) = ctx->f0.u32l;
    // 0x800289B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800289B8: jal         0x800296FC
    // 0x800289BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800296FC(rdram, ctx);
        goto after_9;
    // 0x800289BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800289C0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800289C4: nop

    // 0x800289C8: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x800289CC: nop

    // 0x800289D0: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x800289D4: lh          $t8, 0x56($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X56);
    // 0x800289D8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800289DC: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x800289E0: lh          $t9, 0x1B48($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X1B48);
    // 0x800289E4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800289E8: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800289EC: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800289F0: bne         $at, $zero, L_80028980
    if (ctx->r1 != 0) {
        // 0x800289F4: sh          $t5, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r13;
            goto L_80028980;
    }
    // 0x800289F4: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
L_800289F8:
    // 0x800289F8: b           L_80028A00
    // 0x800289FC: nop

        goto L_80028A00;
    // 0x800289FC: nop

L_80028A00:
    // 0x80028A00: b           L_80028A08
    // 0x80028A04: nop

        goto L_80028A08;
    // 0x80028A04: nop

L_80028A08:
    // 0x80028A08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80028A0C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80028A10: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80028A14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80028A18: jr          $ra
    // 0x80028A1C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80028A1C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80072868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072868: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007286C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072870: nop

    // 0x80072874: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072878: nop

    // 0x8007287C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072880: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072884: jr          $ra
    // 0x80072888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007288C: jr          $ra
    // 0x80072890: nop

    return;
    // 0x80072890: nop

    // 0x80072894: jr          $ra
    // 0x80072898: nop

    return;
    // 0x80072898: nop

;}
RECOMP_FUNC void func_80013AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013AFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80013B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013B04: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80013B08: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80013B0C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80013B10: jal         0x8000DA44
    // 0x80013B14: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80013B14: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80013B18: bgez        $v0, L_80013B28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013B1C: nop
    
            goto L_80013B28;
    }
    // 0x80013B1C: nop

    // 0x80013B20: b           L_80013C80
    // 0x80013B24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013C80;
    // 0x80013B24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013B28:
    // 0x80013B28: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80013B2C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80013B30: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x80013B34: nop

    // 0x80013B38: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80013B3C: bne         $at, $zero, L_80013B5C
    if (ctx->r1 != 0) {
        // 0x80013B40: nop
    
            goto L_80013B5C;
    }
    // 0x80013B40: nop

    // 0x80013B44: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80013B48: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80013B4C: beq         $at, $zero, L_80013B5C
    if (ctx->r1 == 0) {
        // 0x80013B50: nop
    
            goto L_80013B5C;
    }
    // 0x80013B50: nop

    // 0x80013B54: b           L_80013C80
    // 0x80013B58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013C80;
    // 0x80013B58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013B5C:
    // 0x80013B5C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80013B60: nop

    // 0x80013B64: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80013B68: nop

    // 0x80013B6C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80013B70: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80013B74: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x80013B78: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80013B7C: bne         $t1, $at, L_80013BD0
    if (ctx->r9 != ctx->r1) {
        // 0x80013B80: nop
    
            goto L_80013BD0;
    }
    // 0x80013B80: nop

    // 0x80013B84: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80013B88: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x80013B8C: lhu         $a2, 0x6($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X6);
    // 0x80013B90: addiu       $a0, $t2, 0xC
    ctx->r4 = ADD32(ctx->r10, 0XC);
    // 0x80013B94: jal         0x800B3DBC
    // 0x80013B98: addiu       $a1, $t2, 0x10
    ctx->r5 = ADD32(ctx->r10, 0X10);
    func_800B3DBC(rdram, ctx);
        goto after_1;
    // 0x80013B98: addiu       $a1, $t2, 0x10
    ctx->r5 = ADD32(ctx->r10, 0X10);
    after_1:
    // 0x80013B9C: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80013BA0: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80013BA4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80013BA8: nop

    // 0x80013BAC: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x80013BB0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80013BB4: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x80013BB8: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80013BBC: nop

    // 0x80013BC0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80013BC4: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x80013BC8: b           L_80013C80
    // 0x80013BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013C80;
    // 0x80013BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80013BD0:
    // 0x80013BD0: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80013BD4: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x80013BD8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80013BDC: nop

    // 0x80013BE0: sh          $t1, 0x50($t2)
    MEM_H(0X50, ctx->r10) = ctx->r9;
    // 0x80013BE4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80013BE8: nop

    // 0x80013BEC: lhu         $t4, 0x50($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X50);
    // 0x80013BF0: nop

    // 0x80013BF4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80013BF8: bgez        $t4, L_80013C10
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80013BFC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80013C10;
    }
    // 0x80013BFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013C00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013C04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80013C08: nop

    // 0x80013C0C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80013C10:
    // 0x80013C10: swc1        $f6, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->f6.u32l;
    // 0x80013C14: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80013C18: nop

    // 0x80013C1C: sh          $zero, 0x52($t5)
    MEM_H(0X52, ctx->r13) = 0;
    // 0x80013C20: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80013C24:
    // 0x80013C24: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80013C28: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80013C2C: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80013C30: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80013C34: lhu         $t9, 0x2A($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X2A);
    // 0x80013C38: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80013C3C: sh          $t9, 0x54($t0)
    MEM_H(0X54, ctx->r8) = ctx->r25;
    // 0x80013C40: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80013C44: nop

    // 0x80013C48: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80013C4C: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80013C50: bne         $at, $zero, L_80013C24
    if (ctx->r1 != 0) {
        // 0x80013C54: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_80013C24;
    }
    // 0x80013C54: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80013C58: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80013C5C: nop

    // 0x80013C60: lhu         $t3, 0x0($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X0);
    // 0x80013C64: nop

    // 0x80013C68: ori         $t5, $t3, 0x400
    ctx->r13 = ctx->r11 | 0X400;
    // 0x80013C6C: sh          $t5, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r13;
    // 0x80013C70: b           L_80013C80
    // 0x80013C74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013C80;
    // 0x80013C74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013C78: b           L_80013C80
    // 0x80013C7C: nop

        goto L_80013C80;
    // 0x80013C7C: nop

L_80013C80:
    // 0x80013C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013C84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80013C88: jr          $ra
    // 0x80013C8C: nop

    return;
    // 0x80013C8C: nop

;}
RECOMP_FUNC void func_8001C94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C94C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C954: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001C958: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001C95C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C960: nop

    // 0x8001C964: bltz        $t6, L_8001CB14
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001C968: nop
    
            goto L_8001CB14;
    }
    // 0x8001C968: nop

    // 0x8001C96C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C970: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C974: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C978: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001C97C: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001C980: nop

    // 0x8001C984: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C988: beq         $t0, $zero, L_8001C9A4
    if (ctx->r8 == 0) {
        // 0x8001C98C: nop
    
            goto L_8001C9A4;
    }
    // 0x8001C98C: nop

    // 0x8001C990: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001C994: lh          $t1, -0x7290($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7290);
    // 0x8001C998: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C99C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001C9A0: sh          $t2, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r10;
L_8001C9A4:
    // 0x8001C9A4: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C9A8: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C9AC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C9B0: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001C9B4: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001C9B8: nop

    // 0x8001C9BC: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C9C0: beq         $t6, $zero, L_8001C9DC
    if (ctx->r14 == 0) {
        // 0x8001C9C4: nop
    
            goto L_8001C9DC;
    }
    // 0x8001C9C4: nop

    // 0x8001C9C8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8001C9CC: lh          $t7, -0x7290($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7290);
    // 0x8001C9D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C9D4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001C9D8: sh          $t8, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r24;
L_8001C9DC:
    // 0x8001C9DC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001C9E0: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001C9E4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001C9E8: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001C9EC: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001C9F0: nop

    // 0x8001C9F4: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001C9F8: beq         $t2, $zero, L_8001CA14
    if (ctx->r10 == 0) {
        // 0x8001C9FC: nop
    
            goto L_8001CA14;
    }
    // 0x8001C9FC: nop

    // 0x8001CA00: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001CA04: lh          $t3, -0x7288($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X7288);
    // 0x8001CA08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CA0C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8001CA10: sh          $t4, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = ctx->r12;
L_8001CA14:
    // 0x8001CA14: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001CA18: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001CA1C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001CA20: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001CA24: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001CA28: nop

    // 0x8001CA2C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001CA30: beq         $t8, $zero, L_8001CA4C
    if (ctx->r24 == 0) {
        // 0x8001CA34: nop
    
            goto L_8001CA4C;
    }
    // 0x8001CA34: nop

    // 0x8001CA38: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001CA3C: lh          $t9, -0x7288($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X7288);
    // 0x8001CA40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CA44: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8001CA48: sh          $t0, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = ctx->r8;
L_8001CA4C:
    // 0x8001CA4C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001CA50: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001CA54: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001CA58: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001CA5C: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001CA60: nop

    // 0x8001CA64: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001CA68: beq         $t4, $zero, L_8001CA84
    if (ctx->r12 == 0) {
        // 0x8001CA6C: nop
    
            goto L_8001CA84;
    }
    // 0x8001CA6C: nop

    // 0x8001CA70: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001CA74: lh          $t5, -0x7280($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X7280);
    // 0x8001CA78: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CA7C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001CA80: sh          $t6, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = ctx->r14;
L_8001CA84:
    // 0x8001CA84: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CA88: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CA8C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CA90: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001CA94: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CA98: nop

    // 0x8001CA9C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CAA0: beq         $t0, $zero, L_8001CABC
    if (ctx->r8 == 0) {
        // 0x8001CAA4: nop
    
            goto L_8001CABC;
    }
    // 0x8001CAA4: nop

    // 0x8001CAA8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001CAAC: lh          $t1, -0x7280($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7280);
    // 0x8001CAB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CAB4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8001CAB8: sh          $t2, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = ctx->r10;
L_8001CABC:
    // 0x8001CABC: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001CAC0: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001CAC4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001CAC8: lhu         $t5, 0x1042($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1042);
    // 0x8001CACC: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8001CAD0: nop

    // 0x8001CAD4: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001CAD8: beq         $t6, $zero, L_8001CB14
    if (ctx->r14 == 0) {
        // 0x8001CADC: nop
    
            goto L_8001CB14;
    }
    // 0x8001CADC: nop

    // 0x8001CAE0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8001CAE4: lh          $t7, -0x7290($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7290);
    // 0x8001CAE8: nop

    // 0x8001CAEC: slti        $at, $t7, 0x1F4
    ctx->r1 = SIGNED(ctx->r15) < 0X1F4 ? 1 : 0;
    // 0x8001CAF0: beq         $at, $zero, L_8001CB08
    if (ctx->r1 == 0) {
        // 0x8001CAF4: nop
    
            goto L_8001CB08;
    }
    // 0x8001CAF4: nop

    // 0x8001CAF8: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x8001CAFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB00: b           L_8001CB14
    // 0x8001CB04: sh          $t8, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r24;
        goto L_8001CB14;
    // 0x8001CB04: sh          $t8, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r24;
L_8001CB08:
    // 0x8001CB08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001CB0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB10: sh          $t9, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r25;
L_8001CB14:
    // 0x8001CB14: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001CB18: lh          $t0, -0x7290($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X7290);
    // 0x8001CB1C: nop

    // 0x8001CB20: bgez        $t0, L_8001CB30
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001CB24: nop
    
            goto L_8001CB30;
    }
    // 0x8001CB24: nop

    // 0x8001CB28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB2C: sh          $zero, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = 0;
L_8001CB30:
    // 0x8001CB30: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001CB34: lh          $t1, -0x7288($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7288);
    // 0x8001CB38: nop

    // 0x8001CB3C: bgez        $t1, L_8001CB4C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001CB40: nop
    
            goto L_8001CB4C;
    }
    // 0x8001CB40: nop

    // 0x8001CB44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB48: sh          $zero, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = 0;
L_8001CB4C:
    // 0x8001CB4C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001CB50: lh          $t2, -0x7280($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X7280);
    // 0x8001CB54: nop

    // 0x8001CB58: bgez        $t2, L_8001CB68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8001CB5C: nop
    
            goto L_8001CB68;
    }
    // 0x8001CB5C: nop

    // 0x8001CB60: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB64: sh          $zero, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = 0;
L_8001CB68:
    // 0x8001CB68: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001CB6C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x8001CB70: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x8001CB74: lh          $a3, -0x7280($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X7280);
    // 0x8001CB78: lh          $a2, -0x7288($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X7288);
    // 0x8001CB7C: lh          $a1, -0x7290($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X7290);
    // 0x8001CB80: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CB84: jal         0x8008ECE4
    // 0x8001CB88: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CB88: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    after_0:
    // 0x8001CB8C: b           L_8001CB9C
    // 0x8001CB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CB9C;
    // 0x8001CB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CB94: b           L_8001CB9C
    // 0x8001CB98: nop

        goto L_8001CB9C;
    // 0x8001CB98: nop

L_8001CB9C:
    // 0x8001CB9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CBA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CBA4: jr          $ra
    // 0x8001CBA8: nop

    return;
    // 0x8001CBA8: nop

;}
RECOMP_FUNC void func_800635B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800635B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800635BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800635C0: nop

    // 0x800635C4: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x800635C8: nop

    // 0x800635CC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800635D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800635D4: jr          $ra
    // 0x800635D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800635D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800635DC: jr          $ra
    // 0x800635E0: nop

    return;
    // 0x800635E0: nop

    // 0x800635E4: jr          $ra
    // 0x800635E8: nop

    return;
    // 0x800635E8: nop

;}
RECOMP_FUNC void func_8006C570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C578: jal         0x8005F064
    // 0x8006C57C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C57C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_0:
    // 0x8006C580: b           L_8006C590
    // 0x8006C584: nop

        goto L_8006C590;
    // 0x8006C584: nop

    // 0x8006C588: b           L_8006C590
    // 0x8006C58C: nop

        goto L_8006C590;
    // 0x8006C58C: nop

L_8006C590:
    // 0x8006C590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C598: jr          $ra
    // 0x8006C59C: nop

    return;
    // 0x8006C59C: nop

;}
RECOMP_FUNC void func_80097408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097408: jr          $ra
    // 0x8009740C: addiu       $v0, $a0, 0x98
    ctx->r2 = ADD32(ctx->r4, 0X98);
    return;
    // 0x8009740C: addiu       $v0, $a0, 0x98
    ctx->r2 = ADD32(ctx->r4, 0X98);
    // 0x80097410: jr          $ra
    // 0x80097414: nop

    return;
    // 0x80097414: nop

    // 0x80097418: jr          $ra
    // 0x8009741C: nop

    return;
    // 0x8009741C: nop

;}
RECOMP_FUNC void Thread_Yield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0DE4: jal         0x800C4BF0
    // 0x800C0DE8: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C0DE8: nop

    after_0:
    // 0x800C0DEC: b           L_800C0DF4
    // 0x800C0DF0: nop

        goto L_800C0DF4;
    // 0x800C0DF0: nop

L_800C0DF4:
    // 0x800C0DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0DFC: jr          $ra
    // 0x800C0E00: nop

    return;
    // 0x800C0E00: nop

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
RECOMP_FUNC void func_8002EC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EC90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002EC94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EC98: jal         0x800C1754
    // 0x8002EC9C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8002EC9C: nop

    after_0:
    // 0x8002ECA0: jal         0x800A7160
    // 0x8002ECA4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800A7160(rdram, ctx);
        goto after_1;
    // 0x8002ECA4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x8002ECA8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002ECAC: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x8002ECB0: lwc1        $f12, 0xEB0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XEB0);
    // 0x8002ECB4: jal         0x800C2780
    // 0x8002ECB8: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8002ECB8: nop

    after_2:
    // 0x8002ECBC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002ECC0: addiu       $t7, $t7, 0x7340
    ctx->r15 = ADD32(ctx->r15, 0X7340);
    // 0x8002ECC4: lwc1        $f12, 0xEAC($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XEAC);
    // 0x8002ECC8: jal         0x800C25B8
    // 0x8002ECCC: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8002ECCC: nop

    after_3:
    // 0x8002ECD0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8002ECD4: addiu       $t8, $t8, 0x7340
    ctx->r24 = ADD32(ctx->r24, 0X7340);
    // 0x8002ECD8: lwc1        $f12, 0xEA8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XEA8);
    // 0x8002ECDC: jal         0x800C23E8
    // 0x8002ECE0: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8002ECE0: nop

    after_4:
    // 0x8002ECE4: jal         0x800A72BC
    // 0x8002ECE8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800A72BC(rdram, ctx);
        goto after_5;
    // 0x8002ECE8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x8002ECEC: jal         0x800C1A28
    // 0x8002ECF0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x8002ECF0: nop

    after_6:
    // 0x8002ECF4: jal         0x8002EAF0
    // 0x8002ECF8: nop

    func_8002EAF0(rdram, ctx);
        goto after_7;
    // 0x8002ECF8: nop

    after_7:
    // 0x8002ECFC: b           L_8002ED04
    // 0x8002ED00: nop

        goto L_8002ED04;
    // 0x8002ED00: nop

L_8002ED04:
    // 0x8002ED04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002ED08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002ED0C: jr          $ra
    // 0x8002ED10: nop

    return;
    // 0x8002ED10: nop

;}
RECOMP_FUNC void func_80066BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066BB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066BB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80066BBC: nop

    // 0x80066BC0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80066BC4: nop

    // 0x80066BC8: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80066BCC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066BD0: jr          $ra
    // 0x80066BD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80066BD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066BD8: jr          $ra
    // 0x80066BDC: nop

    return;
    // 0x80066BDC: nop

    // 0x80066BE0: jr          $ra
    // 0x80066BE4: nop

    return;
    // 0x80066BE4: nop

;}
RECOMP_FUNC void func_8000B260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B268: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000B26C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000B270: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8000B274: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x8000B278: nop

    // 0x8000B27C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8000B280: beq         $t7, $zero, L_8000B2B0
    if (ctx->r15 == 0) {
        // 0x8000B284: nop
    
            goto L_8000B2B0;
    }
    // 0x8000B284: nop

    // 0x8000B288: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x8000B28C: beq         $t8, $zero, L_8000B2B0
    if (ctx->r24 == 0) {
        // 0x8000B290: nop
    
            goto L_8000B2B0;
    }
    // 0x8000B290: nop

    // 0x8000B294: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B298: lw          $a1, 0x1638($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1638);
    // 0x8000B29C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000B2A0: jal         0x8008ECE4
    // 0x8000B2A4: addiu       $a0, $a0, -0x2D20
    ctx->r4 = ADD32(ctx->r4, -0X2D20);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8000B2A4: addiu       $a0, $a0, -0x2D20
    ctx->r4 = ADD32(ctx->r4, -0X2D20);
    after_0:
    // 0x8000B2A8: b           L_8000B2BC
    // 0x8000B2AC: nop

        goto L_8000B2BC;
    // 0x8000B2AC: nop

L_8000B2B0:
    // 0x8000B2B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000B2B4: jal         0x8008ECE4
    // 0x8000B2B8: addiu       $a0, $a0, -0x2D08
    ctx->r4 = ADD32(ctx->r4, -0X2D08);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8000B2B8: addiu       $a0, $a0, -0x2D08
    ctx->r4 = ADD32(ctx->r4, -0X2D08);
    after_1:
L_8000B2BC:
    // 0x8000B2BC: b           L_8000B2CC
    // 0x8000B2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B2CC;
    // 0x8000B2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000B2C4: b           L_8000B2CC
    // 0x8000B2C8: nop

        goto L_8000B2CC;
    // 0x8000B2C8: nop

L_8000B2CC:
    // 0x8000B2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B2D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B2D4: jr          $ra
    // 0x8000B2D8: nop

    return;
    // 0x8000B2D8: nop

;}
RECOMP_FUNC void func_8009A2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A2F4: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009A2F8: nop

    // 0x8009A2FC: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8009A300: sw          $t7, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r15;
    // 0x8009A304: lw          $t8, 0xC0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC0);
    // 0x8009A308: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8009A30C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8009A310: sw          $t9, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r25;
    // 0x8009A314: jr          $ra
    // 0x8009A318: nop

    return;
    // 0x8009A318: nop

    // 0x8009A31C: jr          $ra
    // 0x8009A320: nop

    return;
    // 0x8009A320: nop

;}
RECOMP_FUNC void Scheduler_HandleRdpMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097B0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80097B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097B14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097B18: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80097B1C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80097B20: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097B24: nop

    // 0x80097B28: lw          $t7, 0x298($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X298);
    // 0x80097B2C: nop

    // 0x80097B30: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80097B34: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097B38: nop

    // 0x80097B3C: sw          $zero, 0x298($t8)
    MEM_W(0X298, ctx->r24) = 0;
    // 0x80097B40: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097B44: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80097B48: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80097B4C: nop

    // 0x80097B50: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80097B54: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80097B58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097B5C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80097B60: jal         0x80097C5C
    // 0x80097B64: nop

    Scheduler_IsTaskComplete(rdram, ctx);
        goto after_0;
    // 0x80097B64: nop

    after_0:
    // 0x80097B68: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80097B6C: nop

    // 0x80097B70: lw          $t3, 0x294($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X294);
    // 0x80097B74: lw          $t6, 0x298($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X298);
    // 0x80097B78: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80097B7C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80097B80: sltiu       $t7, $t6, 0x1
    ctx->r15 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80097B84: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80097B88: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80097B8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097B90: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80097B94: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80097B98: jal         0x80097F78
    // 0x80097B9C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    Scheduler_ScheduleTask(rdram, ctx);
        goto after_1;
    // 0x80097B9C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80097BA0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80097BA4: nop

    // 0x80097BA8: beq         $v0, $t0, L_80097BC4
    if (ctx->r2 == ctx->r8) {
        // 0x80097BAC: nop
    
            goto L_80097BC4;
    }
    // 0x80097BAC: nop

    // 0x80097BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097BB4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80097BB8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80097BBC: jal         0x80097DDC
    // 0x80097BC0: nop

    Scheduler_ExecuteTask(rdram, ctx);
        goto after_2;
    // 0x80097BC0: nop

    after_2:
L_80097BC4:
    // 0x80097BC4: b           L_80097BCC
    // 0x80097BC8: nop

        goto L_80097BCC;
    // 0x80097BC8: nop

L_80097BCC:
    // 0x80097BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097BD4: jr          $ra
    // 0x80097BD8: nop

    return;
    // 0x80097BD8: nop

;}
RECOMP_FUNC void func_800A70D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A70D8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A70DC: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x800A70E0: bne         $at, $zero, L_800A70F0
    if (ctx->r1 != 0) {
        // 0x800A70E4: nop
    
            goto L_800A70F0;
    }
    // 0x800A70E4: nop

    // 0x800A70E8: b           L_800A7158
    // 0x800A70EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A7158;
    // 0x800A70EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A70F0:
    // 0x800A70F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A70F4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A70F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A70FC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A7100: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A7104: addiu       $t7, $t7, 0x7340
    ctx->r15 = ADD32(ctx->r15, 0X7340);
    // 0x800A7108: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800A710C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A7110: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800A7114: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A7118: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A711C: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800A7120: nop

    // 0x800A7124: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800A7128: bne         $t1, $zero, L_800A7138
    if (ctx->r9 != 0) {
        // 0x800A712C: nop
    
            goto L_800A7138;
    }
    // 0x800A712C: nop

    // 0x800A7130: b           L_800A7158
    // 0x800A7134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A7158;
    // 0x800A7134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A7138:
    // 0x800A7138: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A713C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7140: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800A7144: xor         $t4, $a1, $at
    ctx->r12 = ctx->r5 ^ ctx->r1;
    // 0x800A7148: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x800A714C: sw          $t5, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r13;
    // 0x800A7150: b           L_800A7158
    // 0x800A7154: nop

        goto L_800A7158;
    // 0x800A7154: nop

L_800A7158:
    // 0x800A7158: jr          $ra
    // 0x800A715C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A715C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800714D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800714D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800714DC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800714E0: nop

    // 0x800714E4: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800714E8: nop

    // 0x800714EC: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x800714F0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800714F4: jr          $ra
    // 0x800714F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800714F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800714FC: jr          $ra
    // 0x80071500: nop

    return;
    // 0x80071500: nop

    // 0x80071504: jr          $ra
    // 0x80071508: nop

    return;
    // 0x80071508: nop

;}
RECOMP_FUNC void func_80063FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063FAC: jal         0x8005F064
    // 0x80063FB0: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063FB0: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x80063FB4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063FB8: b           L_80063FC8
    // 0x80063FBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063FC8;
    // 0x80063FBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063FC0: b           L_80063FC8
    // 0x80063FC4: nop

        goto L_80063FC8;
    // 0x80063FC4: nop

L_80063FC8:
    // 0x80063FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063FCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063FD0: jr          $ra
    // 0x80063FD4: nop

    return;
    // 0x80063FD4: nop

;}
RECOMP_FUNC void func_80053580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053580: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80053584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053588: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005358C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80053590: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80053594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80053598: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005359C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800535A0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800535A4: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800535A8: nop

    // 0x800535AC: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800535B0: nop

    // 0x800535B4: bc1f        L_800535C8
    if (!c1cs) {
        // 0x800535B8: nop
    
            goto L_800535C8;
    }
    // 0x800535B8: nop

    // 0x800535BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800535C0: b           L_800535E4
    // 0x800535C4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
        goto L_800535E4;
    // 0x800535C4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
L_800535C8:
    // 0x800535C8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800535CC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800535D0: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800535D4: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800535D8: nop

    // 0x800535DC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800535E0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_800535E4:
    // 0x800535E4: jal         0x80061E14
    // 0x800535E8: nop

    func_80061E14(rdram, ctx);
        goto after_0;
    // 0x800535E8: nop

    after_0:
    // 0x800535EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800535F0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800535F4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800535F8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800535FC: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80053600: nop

    // 0x80053604: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80053608: nop

    // 0x8005360C: bc1f        L_8005361C
    if (!c1cs) {
        // 0x80053610: nop
    
            goto L_8005361C;
    }
    // 0x80053610: nop

    // 0x80053614: b           L_80054188
    // 0x80053618: nop

        goto L_80054188;
    // 0x80053618: nop

L_8005361C:
    // 0x8005361C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80053620: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80053624: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80053628: nop

    // 0x8005362C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80053630: nop

    // 0x80053634: bc1t        L_80053680
    if (c1cs) {
        // 0x80053638: nop
    
            goto L_80053680;
    }
    // 0x80053638: nop

    // 0x8005363C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80053640: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80053644: beq         $t9, $at, L_80053680
    if (ctx->r25 == ctx->r1) {
        // 0x80053648: nop
    
            goto L_80053680;
    }
    // 0x80053648: nop

    // 0x8005364C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80053650: beq         $t9, $at, L_80053680
    if (ctx->r25 == ctx->r1) {
        // 0x80053654: nop
    
            goto L_80053680;
    }
    // 0x80053654: nop

    // 0x80053658: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005365C: addiu       $at, $zero, 0x270F
    ctx->r1 = ADD32(0, 0X270F);
    // 0x80053660: beq         $t0, $at, L_80053680
    if (ctx->r8 == ctx->r1) {
        // 0x80053664: nop
    
            goto L_80053680;
    }
    // 0x80053664: nop

    // 0x80053668: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005366C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053670: jal         0x80052508
    // 0x80053674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_1;
    // 0x80053674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80053678: beq         $v0, $zero, L_800536D0
    if (ctx->r2 == 0) {
        // 0x8005367C: nop
    
            goto L_800536D0;
    }
    // 0x8005367C: nop

L_80053680:
    // 0x80053680: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x80053684: jal         0x80056E88
    // 0x80053688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_2;
    // 0x80053688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8005368C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80053690: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80053694: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80053698: lh          $t3, 0x4A($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4A);
    // 0x8005369C: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x800536A0: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x800536A4: beq         $t1, $t4, L_800536C8
    if (ctx->r9 == ctx->r12) {
        // 0x800536A8: nop
    
            goto L_800536C8;
    }
    // 0x800536A8: nop

    // 0x800536AC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800536B0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800536B4: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x800536B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800536BC: lh          $a1, 0x42($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X42);
    // 0x800536C0: jal         0x8004EF90
    // 0x800536C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_3;
    // 0x800536C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_800536C8:
    // 0x800536C8: b           L_80053748
    // 0x800536CC: nop

        goto L_80053748;
    // 0x800536CC: nop

L_800536D0:
    // 0x800536D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800536D4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800536D8: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x800536DC: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x800536E0: nop

    // 0x800536E4: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x800536E8: beq         $t8, $at, L_8005370C
    if (ctx->r24 == ctx->r1) {
        // 0x800536EC: nop
    
            goto L_8005370C;
    }
    // 0x800536EC: nop

    // 0x800536F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800536F4: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x800536F8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800536FC: lh          $a1, 0x42($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X42);
    // 0x80053700: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    // 0x80053704: jal         0x8004EF90
    // 0x80053708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_4;
    // 0x80053708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_8005370C:
    // 0x8005370C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80053710: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80053714: nop

    // 0x80053718: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8005371C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80053720: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x80053724: ori         $t5, $t3, 0x80
    ctx->r13 = ctx->r11 | 0X80;
    // 0x80053728: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8005372C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80053730: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80053734: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80053738: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005373C: lw          $t1, 0x258C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X258C);
    // 0x80053740: nop

    // 0x80053744: sw          $t1, 0x90($t6)
    MEM_W(0X90, ctx->r14) = ctx->r9;
L_80053748:
    // 0x80053748: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005374C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80053750: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80053754: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80053758: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005375C: bne         $t2, $zero, L_8005376C
    if (ctx->r10 != 0) {
        // 0x80053760: andi        $t3, $t9, 0x8
        ctx->r11 = ctx->r25 & 0X8;
            goto L_8005376C;
    }
    // 0x80053760: andi        $t3, $t9, 0x8
    ctx->r11 = ctx->r25 & 0X8;
    // 0x80053764: beq         $t3, $zero, L_80053AC4
    if (ctx->r11 == 0) {
        // 0x80053768: nop
    
            goto L_80053AC4;
    }
    // 0x80053768: nop

L_8005376C:
    // 0x8005376C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80053770: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80053774: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x80053778: lh          $t5, 0x4A($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4A);
    // 0x8005377C: nop

    // 0x80053780: andi        $t0, $t5, 0x1FFF
    ctx->r8 = ctx->r13 & 0X1FFF;
    // 0x80053784: beq         $t0, $at, L_80053920
    if (ctx->r8 == ctx->r1) {
        // 0x80053788: nop
    
            goto L_80053920;
    }
    // 0x80053788: nop

    // 0x8005378C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80053790: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80053794: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80053798: lwc1        $f16, 0xC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8005379C: nop

    // 0x800537A0: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800537A4: nop

    // 0x800537A8: bc1f        L_80053918
    if (!c1cs) {
        // 0x800537AC: nop
    
            goto L_80053918;
    }
    // 0x800537AC: nop

    // 0x800537B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800537B4: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x800537B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800537BC: beq         $t6, $at, L_80053918
    if (ctx->r14 == ctx->r1) {
        // 0x800537C0: nop
    
            goto L_80053918;
    }
    // 0x800537C0: nop

    // 0x800537C4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800537C8: beq         $t6, $at, L_80053918
    if (ctx->r14 == ctx->r1) {
        // 0x800537CC: nop
    
            goto L_80053918;
    }
    // 0x800537CC: nop

    // 0x800537D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800537D4: beq         $t6, $at, L_80053918
    if (ctx->r14 == ctx->r1) {
        // 0x800537D8: nop
    
            goto L_80053918;
    }
    // 0x800537D8: nop

    // 0x800537DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800537E0: beq         $t6, $at, L_80053918
    if (ctx->r14 == ctx->r1) {
        // 0x800537E4: nop
    
            goto L_80053918;
    }
    // 0x800537E4: nop

    // 0x800537E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800537EC: beq         $t6, $at, L_80053918
    if (ctx->r14 == ctx->r1) {
        // 0x800537F0: nop
    
            goto L_80053918;
    }
    // 0x800537F0: nop

    // 0x800537F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800537F8: beq         $t6, $at, L_80053918
    if (ctx->r14 == ctx->r1) {
        // 0x800537FC: nop
    
            goto L_80053918;
    }
    // 0x800537FC: nop

    // 0x80053800: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80053804: beq         $t6, $at, L_80053918
    if (ctx->r14 == ctx->r1) {
        // 0x80053808: nop
    
            goto L_80053918;
    }
    // 0x80053808: nop

    // 0x8005380C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053810: beq         $t6, $at, L_80053918
    if (ctx->r14 == ctx->r1) {
        // 0x80053814: nop
    
            goto L_80053918;
    }
    // 0x80053814: nop

    // 0x80053818: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005381C: lh          $t7, 0x6C0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6C0);
    // 0x80053820: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053824: beq         $t7, $at, L_80053918
    if (ctx->r15 == ctx->r1) {
        // 0x80053828: nop
    
            goto L_80053918;
    }
    // 0x80053828: nop

    // 0x8005382C: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x80053830: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80053834: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80053838: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x8005383C: bne         $t2, $zero, L_80053918
    if (ctx->r10 != 0) {
        // 0x80053840: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_80053918;
    }
    // 0x80053840: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x80053844: bne         $t3, $zero, L_80053918
    if (ctx->r11 != 0) {
        // 0x80053848: nop
    
            goto L_80053918;
    }
    // 0x80053848: nop

L_8005384C:
    // 0x8005384C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053850: jal         0x800499B0
    // 0x80053854: nop

    func_800499B0(rdram, ctx);
        goto after_5;
    // 0x80053854: nop

    after_5:
    // 0x80053858: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005385C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80053860: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80053864: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80053868: nop

    // 0x8005386C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80053870: nop

    // 0x80053874: bc1f        L_80053918
    if (!c1cs) {
        // 0x80053878: nop
    
            goto L_80053918;
    }
    // 0x80053878: nop

    // 0x8005387C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80053880: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x80053884: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053888: beq         $t5, $at, L_80053918
    if (ctx->r13 == ctx->r1) {
        // 0x8005388C: nop
    
            goto L_80053918;
    }
    // 0x8005388C: nop

    // 0x80053890: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053894: beq         $t5, $at, L_80053918
    if (ctx->r13 == ctx->r1) {
        // 0x80053898: nop
    
            goto L_80053918;
    }
    // 0x80053898: nop

    // 0x8005389C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800538A0: beq         $t5, $at, L_80053918
    if (ctx->r13 == ctx->r1) {
        // 0x800538A4: nop
    
            goto L_80053918;
    }
    // 0x800538A4: nop

    // 0x800538A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800538AC: beq         $t5, $at, L_80053918
    if (ctx->r13 == ctx->r1) {
        // 0x800538B0: nop
    
            goto L_80053918;
    }
    // 0x800538B0: nop

    // 0x800538B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800538B8: beq         $t5, $at, L_80053918
    if (ctx->r13 == ctx->r1) {
        // 0x800538BC: nop
    
            goto L_80053918;
    }
    // 0x800538BC: nop

    // 0x800538C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800538C4: beq         $t5, $at, L_80053918
    if (ctx->r13 == ctx->r1) {
        // 0x800538C8: nop
    
            goto L_80053918;
    }
    // 0x800538C8: nop

    // 0x800538CC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800538D0: beq         $t5, $at, L_80053918
    if (ctx->r13 == ctx->r1) {
        // 0x800538D4: nop
    
            goto L_80053918;
    }
    // 0x800538D4: nop

    // 0x800538D8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800538DC: beq         $t5, $at, L_80053918
    if (ctx->r13 == ctx->r1) {
        // 0x800538E0: nop
    
            goto L_80053918;
    }
    // 0x800538E0: nop

    // 0x800538E4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800538E8: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x800538EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800538F0: beq         $t0, $at, L_80053918
    if (ctx->r8 == ctx->r1) {
        // 0x800538F4: nop
    
            goto L_80053918;
    }
    // 0x800538F4: nop

    // 0x800538F8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800538FC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80053900: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80053904: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80053908: bne         $t8, $zero, L_80053918
    if (ctx->r24 != 0) {
        // 0x8005390C: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_80053918;
    }
    // 0x8005390C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80053910: beq         $t9, $zero, L_8005384C
    if (ctx->r25 == 0) {
        // 0x80053914: nop
    
            goto L_8005384C;
    }
    // 0x80053914: nop

L_80053918:
    // 0x80053918: b           L_80053ABC
    // 0x8005391C: nop

        goto L_80053ABC;
    // 0x8005391C: nop

L_80053920:
    // 0x80053920: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80053924: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80053928: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005392C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80053930: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80053934: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80053938: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8005393C: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80053940: nop

    // 0x80053944: bc1f        L_80053ABC
    if (!c1cs) {
        // 0x80053948: nop
    
            goto L_80053ABC;
    }
    // 0x80053948: nop

    // 0x8005394C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80053950: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x80053954: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053958: beq         $t2, $at, L_80053ABC
    if (ctx->r10 == ctx->r1) {
        // 0x8005395C: nop
    
            goto L_80053ABC;
    }
    // 0x8005395C: nop

    // 0x80053960: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053964: beq         $t2, $at, L_80053ABC
    if (ctx->r10 == ctx->r1) {
        // 0x80053968: nop
    
            goto L_80053ABC;
    }
    // 0x80053968: nop

    // 0x8005396C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053970: beq         $t2, $at, L_80053ABC
    if (ctx->r10 == ctx->r1) {
        // 0x80053974: nop
    
            goto L_80053ABC;
    }
    // 0x80053974: nop

    // 0x80053978: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005397C: beq         $t2, $at, L_80053ABC
    if (ctx->r10 == ctx->r1) {
        // 0x80053980: nop
    
            goto L_80053ABC;
    }
    // 0x80053980: nop

    // 0x80053984: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053988: beq         $t2, $at, L_80053ABC
    if (ctx->r10 == ctx->r1) {
        // 0x8005398C: nop
    
            goto L_80053ABC;
    }
    // 0x8005398C: nop

    // 0x80053990: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053994: beq         $t2, $at, L_80053ABC
    if (ctx->r10 == ctx->r1) {
        // 0x80053998: nop
    
            goto L_80053ABC;
    }
    // 0x80053998: nop

    // 0x8005399C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800539A0: beq         $t2, $at, L_80053ABC
    if (ctx->r10 == ctx->r1) {
        // 0x800539A4: nop
    
            goto L_80053ABC;
    }
    // 0x800539A4: nop

    // 0x800539A8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800539AC: beq         $t2, $at, L_80053ABC
    if (ctx->r10 == ctx->r1) {
        // 0x800539B0: nop
    
            goto L_80053ABC;
    }
    // 0x800539B0: nop

    // 0x800539B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800539B8: lh          $t3, 0x6C0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X6C0);
    // 0x800539BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800539C0: beq         $t3, $at, L_80053ABC
    if (ctx->r11 == ctx->r1) {
        // 0x800539C4: nop
    
            goto L_80053ABC;
    }
    // 0x800539C4: nop

    // 0x800539C8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x800539CC: lw          $t1, 0x4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4);
    // 0x800539D0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800539D4: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x800539D8: bne         $t4, $zero, L_80053ABC
    if (ctx->r12 != 0) {
        // 0x800539DC: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_80053ABC;
    }
    // 0x800539DC: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x800539E0: bne         $t5, $zero, L_80053ABC
    if (ctx->r13 != 0) {
        // 0x800539E4: nop
    
            goto L_80053ABC;
    }
    // 0x800539E4: nop

L_800539E8:
    // 0x800539E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800539EC: jal         0x800499B0
    // 0x800539F0: nop

    func_800499B0(rdram, ctx);
        goto after_6;
    // 0x800539F0: nop

    after_6:
    // 0x800539F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800539F8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800539FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80053A00: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80053A04: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80053A08: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80053A0C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80053A10: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80053A14: nop

    // 0x80053A18: bc1f        L_80053ABC
    if (!c1cs) {
        // 0x80053A1C: nop
    
            goto L_80053ABC;
    }
    // 0x80053A1C: nop

    // 0x80053A20: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80053A24: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80053A28: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053A2C: beq         $t7, $at, L_80053ABC
    if (ctx->r15 == ctx->r1) {
        // 0x80053A30: nop
    
            goto L_80053ABC;
    }
    // 0x80053A30: nop

    // 0x80053A34: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053A38: beq         $t7, $at, L_80053ABC
    if (ctx->r15 == ctx->r1) {
        // 0x80053A3C: nop
    
            goto L_80053ABC;
    }
    // 0x80053A3C: nop

    // 0x80053A40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053A44: beq         $t7, $at, L_80053ABC
    if (ctx->r15 == ctx->r1) {
        // 0x80053A48: nop
    
            goto L_80053ABC;
    }
    // 0x80053A48: nop

    // 0x80053A4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053A50: beq         $t7, $at, L_80053ABC
    if (ctx->r15 == ctx->r1) {
        // 0x80053A54: nop
    
            goto L_80053ABC;
    }
    // 0x80053A54: nop

    // 0x80053A58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053A5C: beq         $t7, $at, L_80053ABC
    if (ctx->r15 == ctx->r1) {
        // 0x80053A60: nop
    
            goto L_80053ABC;
    }
    // 0x80053A60: nop

    // 0x80053A64: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053A68: beq         $t7, $at, L_80053ABC
    if (ctx->r15 == ctx->r1) {
        // 0x80053A6C: nop
    
            goto L_80053ABC;
    }
    // 0x80053A6C: nop

    // 0x80053A70: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80053A74: beq         $t7, $at, L_80053ABC
    if (ctx->r15 == ctx->r1) {
        // 0x80053A78: nop
    
            goto L_80053ABC;
    }
    // 0x80053A78: nop

    // 0x80053A7C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053A80: beq         $t7, $at, L_80053ABC
    if (ctx->r15 == ctx->r1) {
        // 0x80053A84: nop
    
            goto L_80053ABC;
    }
    // 0x80053A84: nop

    // 0x80053A88: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80053A8C: lh          $t8, 0x6C0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X6C0);
    // 0x80053A90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053A94: beq         $t8, $at, L_80053ABC
    if (ctx->r24 == ctx->r1) {
        // 0x80053A98: nop
    
            goto L_80053ABC;
    }
    // 0x80053A98: nop

    // 0x80053A9C: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80053AA0: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80053AA4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80053AA8: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80053AAC: bne         $t0, $zero, L_80053ABC
    if (ctx->r8 != 0) {
        // 0x80053AB0: and         $t1, $t3, $at
        ctx->r9 = ctx->r11 & ctx->r1;
            goto L_80053ABC;
    }
    // 0x80053AB0: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x80053AB4: beq         $t1, $zero, L_800539E8
    if (ctx->r9 == 0) {
        // 0x80053AB8: nop
    
            goto L_800539E8;
    }
    // 0x80053AB8: nop

L_80053ABC:
    // 0x80053ABC: b           L_80053E14
    // 0x80053AC0: nop

        goto L_80053E14;
    // 0x80053AC0: nop

L_80053AC4:
    // 0x80053AC4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80053AC8: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80053ACC: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x80053AD0: lh          $t4, 0x4A($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X4A);
    // 0x80053AD4: nop

    // 0x80053AD8: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x80053ADC: beq         $t5, $at, L_80053C78
    if (ctx->r13 == ctx->r1) {
        // 0x80053AE0: nop
    
            goto L_80053C78;
    }
    // 0x80053AE0: nop

    // 0x80053AE4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80053AE8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80053AEC: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80053AF0: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80053AF4: nop

    // 0x80053AF8: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80053AFC: nop

    // 0x80053B00: bc1f        L_80053C70
    if (!c1cs) {
        // 0x80053B04: nop
    
            goto L_80053C70;
    }
    // 0x80053B04: nop

    // 0x80053B08: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80053B0C: lh          $t8, 0x10F0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X10F0);
    // 0x80053B10: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053B14: beq         $t8, $at, L_80053C70
    if (ctx->r24 == ctx->r1) {
        // 0x80053B18: nop
    
            goto L_80053C70;
    }
    // 0x80053B18: nop

    // 0x80053B1C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053B20: beq         $t8, $at, L_80053C70
    if (ctx->r24 == ctx->r1) {
        // 0x80053B24: nop
    
            goto L_80053C70;
    }
    // 0x80053B24: nop

    // 0x80053B28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053B2C: beq         $t8, $at, L_80053C70
    if (ctx->r24 == ctx->r1) {
        // 0x80053B30: nop
    
            goto L_80053C70;
    }
    // 0x80053B30: nop

    // 0x80053B34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053B38: beq         $t8, $at, L_80053C70
    if (ctx->r24 == ctx->r1) {
        // 0x80053B3C: nop
    
            goto L_80053C70;
    }
    // 0x80053B3C: nop

    // 0x80053B40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053B44: beq         $t8, $at, L_80053C70
    if (ctx->r24 == ctx->r1) {
        // 0x80053B48: nop
    
            goto L_80053C70;
    }
    // 0x80053B48: nop

    // 0x80053B4C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053B50: beq         $t8, $at, L_80053C70
    if (ctx->r24 == ctx->r1) {
        // 0x80053B54: nop
    
            goto L_80053C70;
    }
    // 0x80053B54: nop

    // 0x80053B58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80053B5C: beq         $t8, $at, L_80053C70
    if (ctx->r24 == ctx->r1) {
        // 0x80053B60: nop
    
            goto L_80053C70;
    }
    // 0x80053B60: nop

    // 0x80053B64: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053B68: beq         $t8, $at, L_80053C70
    if (ctx->r24 == ctx->r1) {
        // 0x80053B6C: nop
    
            goto L_80053C70;
    }
    // 0x80053B6C: nop

    // 0x80053B70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80053B74: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x80053B78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053B7C: beq         $t6, $at, L_80053C70
    if (ctx->r14 == ctx->r1) {
        // 0x80053B80: nop
    
            goto L_80053C70;
    }
    // 0x80053B80: nop

    // 0x80053B84: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x80053B88: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80053B8C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80053B90: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80053B94: bne         $t0, $zero, L_80053C70
    if (ctx->r8 != 0) {
        // 0x80053B98: and         $t1, $t3, $at
        ctx->r9 = ctx->r11 & ctx->r1;
            goto L_80053C70;
    }
    // 0x80053B98: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x80053B9C: bne         $t1, $zero, L_80053C70
    if (ctx->r9 != 0) {
        // 0x80053BA0: nop
    
            goto L_80053C70;
    }
    // 0x80053BA0: nop

L_80053BA4:
    // 0x80053BA4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053BA8: jal         0x800499B0
    // 0x80053BAC: nop

    func_800499B0(rdram, ctx);
        goto after_7;
    // 0x80053BAC: nop

    after_7:
    // 0x80053BB0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80053BB4: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80053BB8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80053BBC: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80053BC0: nop

    // 0x80053BC4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80053BC8: nop

    // 0x80053BCC: bc1f        L_80053C70
    if (!c1cs) {
        // 0x80053BD0: nop
    
            goto L_80053C70;
    }
    // 0x80053BD0: nop

    // 0x80053BD4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80053BD8: lh          $t4, 0x10F0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10F0);
    // 0x80053BDC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053BE0: beq         $t4, $at, L_80053C70
    if (ctx->r12 == ctx->r1) {
        // 0x80053BE4: nop
    
            goto L_80053C70;
    }
    // 0x80053BE4: nop

    // 0x80053BE8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053BEC: beq         $t4, $at, L_80053C70
    if (ctx->r12 == ctx->r1) {
        // 0x80053BF0: nop
    
            goto L_80053C70;
    }
    // 0x80053BF0: nop

    // 0x80053BF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053BF8: beq         $t4, $at, L_80053C70
    if (ctx->r12 == ctx->r1) {
        // 0x80053BFC: nop
    
            goto L_80053C70;
    }
    // 0x80053BFC: nop

    // 0x80053C00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053C04: beq         $t4, $at, L_80053C70
    if (ctx->r12 == ctx->r1) {
        // 0x80053C08: nop
    
            goto L_80053C70;
    }
    // 0x80053C08: nop

    // 0x80053C0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053C10: beq         $t4, $at, L_80053C70
    if (ctx->r12 == ctx->r1) {
        // 0x80053C14: nop
    
            goto L_80053C70;
    }
    // 0x80053C14: nop

    // 0x80053C18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053C1C: beq         $t4, $at, L_80053C70
    if (ctx->r12 == ctx->r1) {
        // 0x80053C20: nop
    
            goto L_80053C70;
    }
    // 0x80053C20: nop

    // 0x80053C24: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80053C28: beq         $t4, $at, L_80053C70
    if (ctx->r12 == ctx->r1) {
        // 0x80053C2C: nop
    
            goto L_80053C70;
    }
    // 0x80053C2C: nop

    // 0x80053C30: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053C34: beq         $t4, $at, L_80053C70
    if (ctx->r12 == ctx->r1) {
        // 0x80053C38: nop
    
            goto L_80053C70;
    }
    // 0x80053C38: nop

    // 0x80053C3C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80053C40: lh          $t5, 0x6C0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C0);
    // 0x80053C44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053C48: beq         $t5, $at, L_80053C70
    if (ctx->r13 == ctx->r1) {
        // 0x80053C4C: nop
    
            goto L_80053C70;
    }
    // 0x80053C4C: nop

    // 0x80053C50: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80053C54: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x80053C58: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80053C5C: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80053C60: bne         $t6, $zero, L_80053C70
    if (ctx->r14 != 0) {
        // 0x80053C64: and         $t7, $t9, $at
        ctx->r15 = ctx->r25 & ctx->r1;
            goto L_80053C70;
    }
    // 0x80053C64: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80053C68: beq         $t7, $zero, L_80053BA4
    if (ctx->r15 == 0) {
        // 0x80053C6C: nop
    
            goto L_80053BA4;
    }
    // 0x80053C6C: nop

L_80053C70:
    // 0x80053C70: b           L_80053E14
    // 0x80053C74: nop

        goto L_80053E14;
    // 0x80053C74: nop

L_80053C78:
    // 0x80053C78: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80053C7C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80053C80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80053C84: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80053C88: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80053C8C: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80053C90: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80053C94: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80053C98: nop

    // 0x80053C9C: bc1f        L_80053E14
    if (!c1cs) {
        // 0x80053CA0: nop
    
            goto L_80053E14;
    }
    // 0x80053CA0: nop

    // 0x80053CA4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80053CA8: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80053CAC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053CB0: beq         $t3, $at, L_80053E14
    if (ctx->r11 == ctx->r1) {
        // 0x80053CB4: nop
    
            goto L_80053E14;
    }
    // 0x80053CB4: nop

    // 0x80053CB8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053CBC: beq         $t3, $at, L_80053E14
    if (ctx->r11 == ctx->r1) {
        // 0x80053CC0: nop
    
            goto L_80053E14;
    }
    // 0x80053CC0: nop

    // 0x80053CC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053CC8: beq         $t3, $at, L_80053E14
    if (ctx->r11 == ctx->r1) {
        // 0x80053CCC: nop
    
            goto L_80053E14;
    }
    // 0x80053CCC: nop

    // 0x80053CD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053CD4: beq         $t3, $at, L_80053E14
    if (ctx->r11 == ctx->r1) {
        // 0x80053CD8: nop
    
            goto L_80053E14;
    }
    // 0x80053CD8: nop

    // 0x80053CDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053CE0: beq         $t3, $at, L_80053E14
    if (ctx->r11 == ctx->r1) {
        // 0x80053CE4: nop
    
            goto L_80053E14;
    }
    // 0x80053CE4: nop

    // 0x80053CE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053CEC: beq         $t3, $at, L_80053E14
    if (ctx->r11 == ctx->r1) {
        // 0x80053CF0: nop
    
            goto L_80053E14;
    }
    // 0x80053CF0: nop

    // 0x80053CF4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80053CF8: beq         $t3, $at, L_80053E14
    if (ctx->r11 == ctx->r1) {
        // 0x80053CFC: nop
    
            goto L_80053E14;
    }
    // 0x80053CFC: nop

    // 0x80053D00: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053D04: beq         $t3, $at, L_80053E14
    if (ctx->r11 == ctx->r1) {
        // 0x80053D08: nop
    
            goto L_80053E14;
    }
    // 0x80053D08: nop

    // 0x80053D0C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80053D10: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x80053D14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053D18: beq         $t0, $at, L_80053E14
    if (ctx->r8 == ctx->r1) {
        // 0x80053D1C: nop
    
            goto L_80053E14;
    }
    // 0x80053D1C: nop

    // 0x80053D20: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80053D24: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80053D28: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80053D2C: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80053D30: bne         $t8, $zero, L_80053E14
    if (ctx->r24 != 0) {
        // 0x80053D34: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_80053E14;
    }
    // 0x80053D34: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80053D38: bne         $t9, $zero, L_80053E14
    if (ctx->r25 != 0) {
        // 0x80053D3C: nop
    
            goto L_80053E14;
    }
    // 0x80053D3C: nop

L_80053D40:
    // 0x80053D40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053D44: jal         0x800499B0
    // 0x80053D48: nop

    func_800499B0(rdram, ctx);
        goto after_8;
    // 0x80053D48: nop

    after_8:
    // 0x80053D4C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80053D50: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80053D54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80053D58: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80053D5C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80053D60: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80053D64: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80053D68: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80053D6C: nop

    // 0x80053D70: bc1f        L_80053E14
    if (!c1cs) {
        // 0x80053D74: nop
    
            goto L_80053E14;
    }
    // 0x80053D74: nop

    // 0x80053D78: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80053D7C: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x80053D80: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053D84: beq         $t6, $at, L_80053E14
    if (ctx->r14 == ctx->r1) {
        // 0x80053D88: nop
    
            goto L_80053E14;
    }
    // 0x80053D88: nop

    // 0x80053D8C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053D90: beq         $t6, $at, L_80053E14
    if (ctx->r14 == ctx->r1) {
        // 0x80053D94: nop
    
            goto L_80053E14;
    }
    // 0x80053D94: nop

    // 0x80053D98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053D9C: beq         $t6, $at, L_80053E14
    if (ctx->r14 == ctx->r1) {
        // 0x80053DA0: nop
    
            goto L_80053E14;
    }
    // 0x80053DA0: nop

    // 0x80053DA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053DA8: beq         $t6, $at, L_80053E14
    if (ctx->r14 == ctx->r1) {
        // 0x80053DAC: nop
    
            goto L_80053E14;
    }
    // 0x80053DAC: nop

    // 0x80053DB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053DB4: beq         $t6, $at, L_80053E14
    if (ctx->r14 == ctx->r1) {
        // 0x80053DB8: nop
    
            goto L_80053E14;
    }
    // 0x80053DB8: nop

    // 0x80053DBC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053DC0: beq         $t6, $at, L_80053E14
    if (ctx->r14 == ctx->r1) {
        // 0x80053DC4: nop
    
            goto L_80053E14;
    }
    // 0x80053DC4: nop

    // 0x80053DC8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80053DCC: beq         $t6, $at, L_80053E14
    if (ctx->r14 == ctx->r1) {
        // 0x80053DD0: nop
    
            goto L_80053E14;
    }
    // 0x80053DD0: nop

    // 0x80053DD4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053DD8: beq         $t6, $at, L_80053E14
    if (ctx->r14 == ctx->r1) {
        // 0x80053DDC: nop
    
            goto L_80053E14;
    }
    // 0x80053DDC: nop

    // 0x80053DE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80053DE4: lh          $t7, 0x6C0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6C0);
    // 0x80053DE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053DEC: beq         $t7, $at, L_80053E14
    if (ctx->r15 == ctx->r1) {
        // 0x80053DF0: nop
    
            goto L_80053E14;
    }
    // 0x80053DF0: nop

    // 0x80053DF4: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80053DF8: lw          $t1, 0x4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4);
    // 0x80053DFC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80053E00: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80053E04: bne         $t2, $zero, L_80053E14
    if (ctx->r10 != 0) {
        // 0x80053E08: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80053E14;
    }
    // 0x80053E08: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80053E0C: beq         $t3, $zero, L_80053D40
    if (ctx->r11 == 0) {
        // 0x80053E10: nop
    
            goto L_80053D40;
    }
    // 0x80053E10: nop

L_80053E14:
    // 0x80053E14: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80053E18: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80053E1C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80053E20: lw          $t4, 0x258C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X258C);
    // 0x80053E24: nop

    // 0x80053E28: sw          $t4, 0x94($t5)
    MEM_W(0X94, ctx->r13) = ctx->r12;
    // 0x80053E2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80053E30: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80053E34: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80053E38: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80053E3C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80053E40: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80053E44: bne         $t0, $zero, L_80053E54
    if (ctx->r8 != 0) {
        // 0x80053E48: and         $t1, $t7, $at
        ctx->r9 = ctx->r15 & ctx->r1;
            goto L_80053E54;
    }
    // 0x80053E48: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x80053E4C: beq         $t1, $zero, L_80053E68
    if (ctx->r9 == 0) {
        // 0x80053E50: nop
    
            goto L_80053E68;
    }
    // 0x80053E50: nop

L_80053E54:
    // 0x80053E54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053E58: jal         0x800543B0
    // 0x80053E5C: nop

    func_800543B0(rdram, ctx);
        goto after_9;
    // 0x80053E5C: nop

    after_9:
    // 0x80053E60: b           L_80054188
    // 0x80053E64: nop

        goto L_80054188;
    // 0x80053E64: nop

L_80053E68:
    // 0x80053E68: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80053E6C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80053E70: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80053E74: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x80053E78: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80053E7C: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80053E80: bne         $t4, $zero, L_80053E90
    if (ctx->r12 != 0) {
        // 0x80053E84: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_80053E90;
    }
    // 0x80053E84: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80053E88: beq         $t5, $zero, L_80053ECC
    if (ctx->r13 == 0) {
        // 0x80053E8C: nop
    
            goto L_80053ECC;
    }
    // 0x80053E8C: nop

L_80053E90:
    // 0x80053E90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053E94: jal         0x800507AC
    // 0x80053E98: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    func_800507AC(rdram, ctx);
        goto after_10;
    // 0x80053E98: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    after_10:
    // 0x80053E9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053EA0: jal         0x800507AC
    // 0x80053EA4: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800507AC(rdram, ctx);
        goto after_11;
    // 0x80053EA4: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_11:
    // 0x80053EA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053EAC: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    // 0x80053EB0: jal         0x80052508
    // 0x80053EB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_12;
    // 0x80053EB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80053EB8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053EBC: jal         0x800543B0
    // 0x80053EC0: nop

    func_800543B0(rdram, ctx);
        goto after_13;
    // 0x80053EC0: nop

    after_13:
    // 0x80053EC4: b           L_80054188
    // 0x80053EC8: nop

        goto L_80054188;
    // 0x80053EC8: nop

L_80053ECC:
    // 0x80053ECC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80053ED0: lh          $t8, 0x10F0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X10F0);
    // 0x80053ED4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053ED8: beq         $t8, $at, L_80053F48
    if (ctx->r24 == ctx->r1) {
        // 0x80053EDC: nop
    
            goto L_80053F48;
    }
    // 0x80053EDC: nop

    // 0x80053EE0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053EE4: beq         $t8, $at, L_80053F48
    if (ctx->r24 == ctx->r1) {
        // 0x80053EE8: nop
    
            goto L_80053F48;
    }
    // 0x80053EE8: nop

    // 0x80053EEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053EF0: beq         $t8, $at, L_80053F48
    if (ctx->r24 == ctx->r1) {
        // 0x80053EF4: nop
    
            goto L_80053F48;
    }
    // 0x80053EF4: nop

    // 0x80053EF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053EFC: beq         $t8, $at, L_80053F48
    if (ctx->r24 == ctx->r1) {
        // 0x80053F00: nop
    
            goto L_80053F48;
    }
    // 0x80053F00: nop

    // 0x80053F04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053F08: beq         $t8, $at, L_80053F48
    if (ctx->r24 == ctx->r1) {
        // 0x80053F0C: nop
    
            goto L_80053F48;
    }
    // 0x80053F0C: nop

    // 0x80053F10: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053F14: beq         $t8, $at, L_80053F48
    if (ctx->r24 == ctx->r1) {
        // 0x80053F18: nop
    
            goto L_80053F48;
    }
    // 0x80053F18: nop

    // 0x80053F1C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80053F20: beq         $t8, $at, L_80053F48
    if (ctx->r24 == ctx->r1) {
        // 0x80053F24: nop
    
            goto L_80053F48;
    }
    // 0x80053F24: nop

    // 0x80053F28: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053F2C: beq         $t8, $at, L_80053F48
    if (ctx->r24 == ctx->r1) {
        // 0x80053F30: nop
    
            goto L_80053F48;
    }
    // 0x80053F30: nop

    // 0x80053F34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80053F38: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x80053F3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053F40: bne         $t6, $at, L_80053FBC
    if (ctx->r14 != ctx->r1) {
        // 0x80053F44: nop
    
            goto L_80053FBC;
    }
    // 0x80053F44: nop

L_80053F48:
    // 0x80053F48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80053F4C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80053F50: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x80053F54: lh          $t0, 0x4A($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X4A);
    // 0x80053F58: nop

    // 0x80053F5C: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x80053F60: bne         $t1, $at, L_80053F74
    if (ctx->r9 != ctx->r1) {
        // 0x80053F64: nop
    
            goto L_80053F74;
    }
    // 0x80053F64: nop

    // 0x80053F68: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053F6C: jal         0x8005092C
    // 0x80053F70: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8005092C(rdram, ctx);
        goto after_14;
    // 0x80053F70: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_14:
L_80053F74:
    // 0x80053F74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053F78: jal         0x800543B0
    // 0x80053F7C: nop

    func_800543B0(rdram, ctx);
        goto after_15;
    // 0x80053F7C: nop

    after_15:
    // 0x80053F80: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80053F84: jal         0x80056E88
    // 0x80053F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_16;
    // 0x80053F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80053F8C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80053F90: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80053F94: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80053F98: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80053F9C: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80053FA0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80053FA4: lh          $a1, 0x42($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X42);
    // 0x80053FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80053FAC: jal         0x8004EF90
    // 0x80053FB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_17;
    // 0x80053FB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80053FB4: b           L_80054180
    // 0x80053FB8: nop

        goto L_80054180;
    // 0x80053FB8: nop

L_80053FBC:
    // 0x80053FBC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80053FC0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80053FC4: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x80053FC8: lh          $t4, 0x4A($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4A);
    // 0x80053FCC: nop

    // 0x80053FD0: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x80053FD4: bne         $t5, $at, L_80054140
    if (ctx->r13 != ctx->r1) {
        // 0x80053FD8: nop
    
            goto L_80054140;
    }
    // 0x80053FD8: nop

    // 0x80053FDC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80053FE0: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80053FE4: beq         $t8, $at, L_800540FC
    if (ctx->r24 == ctx->r1) {
        // 0x80053FE8: nop
    
            goto L_800540FC;
    }
    // 0x80053FE8: nop

    // 0x80053FEC: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80053FF0: beq         $t8, $at, L_800540FC
    if (ctx->r24 == ctx->r1) {
        // 0x80053FF4: nop
    
            goto L_800540FC;
    }
    // 0x80053FF4: nop

    // 0x80053FF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80053FFC: jal         0x8005092C
    // 0x80054000: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8005092C(rdram, ctx);
        goto after_18;
    // 0x80054000: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_18:
    // 0x80054004: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80054008: jal         0x800543B0
    // 0x8005400C: nop

    func_800543B0(rdram, ctx);
        goto after_19;
    // 0x8005400C: nop

    after_19:
    // 0x80054010: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054014: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80054018: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005401C: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80054020: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80054024: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80054028: bne         $t2, $zero, L_80054048
    if (ctx->r10 != 0) {
        // 0x8005402C: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80054048;
    }
    // 0x8005402C: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80054030: bne         $t3, $zero, L_80054048
    if (ctx->r11 != 0) {
        // 0x80054034: nop
    
            goto L_80054048;
    }
    // 0x80054034: nop

    // 0x80054038: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005403C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80054040: jal         0x80053580
    // 0x80054044: addiu       $a2, $zero, 0x270F
    ctx->r6 = ADD32(0, 0X270F);
    func_80053580(rdram, ctx);
        goto after_20;
    // 0x80054044: addiu       $a2, $zero, 0x270F
    ctx->r6 = ADD32(0, 0X270F);
    after_20:
L_80054048:
    // 0x80054048: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005404C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80054050: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80054054: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x80054058: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x8005405C: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80054060: bne         $t8, $zero, L_800540EC
    if (ctx->r24 != 0) {
        // 0x80054064: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_800540EC;
    }
    // 0x80054064: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80054068: bne         $t9, $zero, L_800540EC
    if (ctx->r25 != 0) {
        // 0x8005406C: nop
    
            goto L_800540EC;
    }
    // 0x8005406C: nop

    // 0x80054070: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054074: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x80054078: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8005407C: beq         $t6, $at, L_800540EC
    if (ctx->r14 == ctx->r1) {
        // 0x80054080: nop
    
            goto L_800540EC;
    }
    // 0x80054080: nop

    // 0x80054084: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80054088: beq         $t6, $at, L_800540EC
    if (ctx->r14 == ctx->r1) {
        // 0x8005408C: nop
    
            goto L_800540EC;
    }
    // 0x8005408C: nop

    // 0x80054090: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80054094: beq         $t6, $at, L_800540EC
    if (ctx->r14 == ctx->r1) {
        // 0x80054098: nop
    
            goto L_800540EC;
    }
    // 0x80054098: nop

    // 0x8005409C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800540A0: beq         $t6, $at, L_800540EC
    if (ctx->r14 == ctx->r1) {
        // 0x800540A4: nop
    
            goto L_800540EC;
    }
    // 0x800540A4: nop

    // 0x800540A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800540AC: beq         $t6, $at, L_800540EC
    if (ctx->r14 == ctx->r1) {
        // 0x800540B0: nop
    
            goto L_800540EC;
    }
    // 0x800540B0: nop

    // 0x800540B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800540B8: beq         $t6, $at, L_800540EC
    if (ctx->r14 == ctx->r1) {
        // 0x800540BC: nop
    
            goto L_800540EC;
    }
    // 0x800540BC: nop

    // 0x800540C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800540C4: beq         $t6, $at, L_800540EC
    if (ctx->r14 == ctx->r1) {
        // 0x800540C8: nop
    
            goto L_800540EC;
    }
    // 0x800540C8: nop

    // 0x800540CC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800540D0: beq         $t6, $at, L_800540EC
    if (ctx->r14 == ctx->r1) {
        // 0x800540D4: nop
    
            goto L_800540EC;
    }
    // 0x800540D4: nop

    // 0x800540D8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800540DC: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x800540E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800540E4: bne         $t0, $at, L_800540F4
    if (ctx->r8 != ctx->r1) {
        // 0x800540E8: nop
    
            goto L_800540F4;
    }
    // 0x800540E8: nop

L_800540EC:
    // 0x800540EC: b           L_80054188
    // 0x800540F0: nop

        goto L_80054188;
    // 0x800540F0: nop

L_800540F4:
    // 0x800540F4: b           L_80054140
    // 0x800540F8: nop

        goto L_80054140;
    // 0x800540F8: nop

L_800540FC:
    // 0x800540FC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054100: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80054104: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80054108: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8005410C: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80054110: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x80054114: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x80054118: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8005411C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80054120: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80054124: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80054128: sw          $t7, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r15;
L_8005412C:
    // 0x8005412C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80054130: jal         0x800499B0
    // 0x80054134: nop

    func_800499B0(rdram, ctx);
        goto after_21;
    // 0x80054134: nop

    after_21:
    // 0x80054138: b           L_8005412C
    // 0x8005413C: nop

        goto L_8005412C;
    // 0x8005413C: nop

L_80054140:
    // 0x80054140: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054144: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80054148: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005414C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80054150: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80054154: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x80054158: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x8005415C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80054160: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x80054164: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80054168: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8005416C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80054170: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80054174: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80054178: nop

    // 0x8005417C: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
L_80054180:
    // 0x80054180: b           L_80054188
    // 0x80054184: nop

        goto L_80054188;
    // 0x80054184: nop

L_80054188:
    // 0x80054188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005418C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80054190: jr          $ra
    // 0x80054194: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80054194: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80004ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004AE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80004AE4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004AE8: swc1        $f4, -0x71C8($at)
    MEM_W(-0X71C8, ctx->r1) = ctx->f4.u32l;
    // 0x80004AEC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80004AF0: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80004AF4: nop

    // 0x80004AF8: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80004AFC: nop

    // 0x80004B00: bne         $t7, $zero, L_80004B10
    if (ctx->r15 != 0) {
        // 0x80004B04: sw          $t7, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r15;
            goto L_80004B10;
    }
    // 0x80004B04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80004B08: b           L_80004CCC
    // 0x80004B0C: nop

        goto L_80004CCC;
    // 0x80004B0C: nop

L_80004B10:
    // 0x80004B10: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004B14: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004B18: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80004B1C: nop

    // 0x80004B20: bne         $t9, $at, L_80004B40
    if (ctx->r25 != ctx->r1) {
        // 0x80004B24: nop
    
            goto L_80004B40;
    }
    // 0x80004B24: nop

    // 0x80004B28: lhu         $t0, 0x2($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X2);
    // 0x80004B2C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004B30: bne         $t0, $at, L_80004B40
    if (ctx->r8 != ctx->r1) {
        // 0x80004B34: nop
    
            goto L_80004B40;
    }
    // 0x80004B34: nop

    // 0x80004B38: b           L_80004CBC
    // 0x80004B3C: nop

        goto L_80004CBC;
    // 0x80004B3C: nop

L_80004B40:
    // 0x80004B40: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80004B44: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x80004B48: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004B4C: nop

    // 0x80004B50: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x80004B54: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80004B58: nop

    // 0x80004B5C: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80004B60: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80004B64: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80004B68: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x80004B6C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004B70: nop

    // 0x80004B74: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80004B78: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004B7C: nop

    // 0x80004B80: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x80004B84: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004B88: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80004B8C: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x80004B90: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004B94: nop

    // 0x80004B98: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x80004B9C: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80004BA0: nop

    // 0x80004BA4: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80004BA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80004BAC: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80004BB0: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x80004BB4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004BB8: nop

    // 0x80004BBC: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x80004BC0: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004BC4: nop

    // 0x80004BC8: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x80004BCC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004BD0: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80004BD4: addiu       $t3, $sp, 0xC
    ctx->r11 = ADD32(ctx->r29, 0XC);
    // 0x80004BD8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004BDC: nop

    // 0x80004BE0: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x80004BE4: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80004BE8: nop

    // 0x80004BEC: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80004BF0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80004BF4: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80004BF8: addiu       $t9, $sp, 0xC
    ctx->r25 = ADD32(ctx->r29, 0XC);
    // 0x80004BFC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004C00: nop

    // 0x80004C04: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80004C08: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004C0C: nop

    // 0x80004C10: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x80004C14: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004C18: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80004C1C: addiu       $t3, $sp, 0xC
    ctx->r11 = ADD32(ctx->r29, 0XC);
    // 0x80004C20: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004C24: nop

    // 0x80004C28: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x80004C2C: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80004C30: nop

    // 0x80004C34: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80004C38: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80004C3C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80004C40: addiu       $t9, $sp, 0xC
    ctx->r25 = ADD32(ctx->r29, 0XC);
    // 0x80004C44: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004C48: nop

    // 0x80004C4C: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x80004C50: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004C54: nop

    // 0x80004C58: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x80004C5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004C60: addiu       $t1, $sp, 0xC
    ctx->r9 = ADD32(ctx->r29, 0XC);
    // 0x80004C64: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004C68: addiu       $at, $zero, 0x300
    ctx->r1 = ADD32(0, 0X300);
    // 0x80004C6C: andi        $t3, $t2, 0x7F00
    ctx->r11 = ctx->r10 & 0X7F00;
    // 0x80004C70: beq         $t3, $at, L_80004C80
    if (ctx->r11 == ctx->r1) {
        // 0x80004C74: nop
    
            goto L_80004C80;
    }
    // 0x80004C74: nop

    // 0x80004C78: b           L_80004CB4
    // 0x80004C7C: nop

        goto L_80004CB4;
    // 0x80004C7C: nop

L_80004C80:
    // 0x80004C80: addiu       $t4, $sp, 0x4
    ctx->r12 = ADD32(ctx->r29, 0X4);
    // 0x80004C84: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x80004C88: lh          $t6, 0x2($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X2);
    // 0x80004C8C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80004C90: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80004C94: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80004C98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80004C9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80004CA0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004CA4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80004CA8: swc1        $f16, -0x71C8($at)
    MEM_W(-0X71C8, ctx->r1) = ctx->f16.u32l;
    // 0x80004CAC: b           L_80004CBC
    // 0x80004CB0: nop

        goto L_80004CBC;
    // 0x80004CB0: nop

L_80004CB4:
    // 0x80004CB4: b           L_80004B10
    // 0x80004CB8: nop

        goto L_80004B10;
    // 0x80004CB8: nop

L_80004CBC:
    // 0x80004CBC: b           L_80004CCC
    // 0x80004CC0: nop

        goto L_80004CCC;
    // 0x80004CC0: nop

    // 0x80004CC4: b           L_80004CCC
    // 0x80004CC8: nop

        goto L_80004CCC;
    // 0x80004CC8: nop

L_80004CCC:
    // 0x80004CCC: jr          $ra
    // 0x80004CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B3A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3A24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3A28: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B3A2C: lwc1        $f4, -0x688($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X688);
    // 0x800B3A30: nop

    // 0x800B3A34: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800B3A38: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800B3A3C: lui         $at, 0xC700
    ctx->r1 = S32(0XC700 << 16);
    // 0x800B3A40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B3A44: nop

    // 0x800B3A48: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800B3A4C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800B3A50: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800B3A54: nop

    // 0x800B3A58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B3A5C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800B3A60: nop

    // 0x800B3A64: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B3A68: nop

    // 0x800B3A6C: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x800B3A70: nop

    // 0x800B3A74: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800B3A78: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800B3A7C: nop

    // 0x800B3A80: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800B3A84: nop

    // 0x800B3A88: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800B3A8C: beq         $t2, $zero, L_800B3AB4
    if (ctx->r10 == 0) {
        // 0x800B3A90: nop
    
            goto L_800B3AB4;
    }
    // 0x800B3A90: nop

    // 0x800B3A94: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800B3A98: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800B3A9C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800B3AA0: nop

    // 0x800B3AA4: lbu         $t6, 0xF($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XF);
    // 0x800B3AA8: nop

    // 0x800B3AAC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800B3AB0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_800B3AB4:
    // 0x800B3AB4: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800B3AB8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800B3ABC: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800B3AC0: blez        $t9, L_800B3D74
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800B3AC4: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_800B3D74;
    }
    // 0x800B3AC4: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_800B3AC8:
    // 0x800B3AC8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800B3ACC: nop

    // 0x800B3AD0: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x800B3AD4: nop

    // 0x800B3AD8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800B3ADC: bne         $t2, $zero, L_800B3B7C
    if (ctx->r10 != 0) {
        // 0x800B3AE0: nop
    
            goto L_800B3B7C;
    }
    // 0x800B3AE0: nop

    // 0x800B3AE4: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800B3AE8: nop

    // 0x800B3AEC: lw          $t5, 0x104($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X104);
    // 0x800B3AF0: lwc1        $f16, 0xF4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x800B3AF4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B3AF8: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800B3AFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B3B00: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B3B04: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B3B08: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800B3B0C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800B3B10: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800B3B14: bc1f        L_800B3B28
    if (!c1cs) {
        // 0x800B3B18: nop
    
            goto L_800B3B28;
    }
    // 0x800B3B18: nop

    // 0x800B3B1C: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3B20: nop

    // 0x800B3B24: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
L_800B3B28:
    // 0x800B3B28: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800B3B2C: nop

    // 0x800B3B30: lw          $t6, 0x104($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X104);
    // 0x800B3B34: lh          $t7, 0x100($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X100);
    // 0x800B3B38: lwc1        $f18, 0xF4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XF4);
    // 0x800B3B3C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B3B40: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B3B44: lwc1        $f8, 0xCC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x800B3B48: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B3B4C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B3B50: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800B3B54: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B3B58: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800B3B5C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800B3B60: bc1f        L_800B3B74
    if (!c1cs) {
        // 0x800B3B64: nop
    
            goto L_800B3B74;
    }
    // 0x800B3B64: nop

    // 0x800B3B68: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3B6C: nop

    // 0x800B3B70: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
L_800B3B74:
    // 0x800B3B74: b           L_800B3C0C
    // 0x800B3B78: nop

        goto L_800B3C0C;
    // 0x800B3B78: nop

L_800B3B7C:
    // 0x800B3B7C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800B3B80: nop

    // 0x800B3B84: lw          $t0, 0x104($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X104);
    // 0x800B3B88: lwc1        $f6, 0xF4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XF4);
    // 0x800B3B8C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800B3B90: lwc1        $f16, 0xCC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800B3B94: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B3B98: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B3B9C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800B3BA0: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800B3BA4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800B3BA8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800B3BAC: bc1f        L_800B3BC0
    if (!c1cs) {
        // 0x800B3BB0: nop
    
            goto L_800B3BC0;
    }
    // 0x800B3BB0: nop

    // 0x800B3BB4: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3BB8: nop

    // 0x800B3BBC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
L_800B3BC0:
    // 0x800B3BC0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800B3BC4: nop

    // 0x800B3BC8: lw          $t2, 0x104($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X104);
    // 0x800B3BCC: lh          $t5, 0x100($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X100);
    // 0x800B3BD0: lwc1        $f10, 0xF4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XF4);
    // 0x800B3BD4: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x800B3BD8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800B3BDC: lwc1        $f18, 0xCC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x800B3BE0: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B3BE4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B3BE8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800B3BEC: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B3BF0: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800B3BF4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800B3BF8: bc1f        L_800B3C0C
    if (!c1cs) {
        // 0x800B3BFC: nop
    
            goto L_800B3C0C;
    }
    // 0x800B3BFC: nop

    // 0x800B3C00: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3C04: nop

    // 0x800B3C08: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_800B3C0C:
    // 0x800B3C0C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800B3C10: nop

    // 0x800B3C14: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800B3C18: nop

    // 0x800B3C1C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800B3C20: bne         $t8, $zero, L_800B3CC0
    if (ctx->r24 != 0) {
        // 0x800B3C24: nop
    
            goto L_800B3CC0;
    }
    // 0x800B3C24: nop

    // 0x800B3C28: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800B3C2C: nop

    // 0x800B3C30: lw          $t0, 0x108($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X108);
    // 0x800B3C34: lh          $t9, 0x102($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X102);
    // 0x800B3C38: lwc1        $f4, 0xF8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XF8);
    // 0x800B3C3C: subu        $t2, $t0, $t9
    ctx->r10 = SUB32(ctx->r8, ctx->r25);
    // 0x800B3C40: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800B3C44: lwc1        $f6, 0xD0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x800B3C48: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B3C4C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B3C50: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B3C54: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3C58: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800B3C5C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800B3C60: bc1f        L_800B3C74
    if (!c1cs) {
        // 0x800B3C64: nop
    
            goto L_800B3C74;
    }
    // 0x800B3C64: nop

    // 0x800B3C68: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3C6C: nop

    // 0x800B3C70: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_800B3C74:
    // 0x800B3C74: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800B3C78: nop

    // 0x800B3C7C: lw          $t4, 0x108($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X108);
    // 0x800B3C80: lwc1        $f8, 0xF8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x800B3C84: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800B3C88: lwc1        $f10, 0xD0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x800B3C8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B3C90: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B3C94: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B3C98: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B3C9C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800B3CA0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800B3CA4: bc1f        L_800B3CB8
    if (!c1cs) {
        // 0x800B3CA8: nop
    
            goto L_800B3CB8;
    }
    // 0x800B3CA8: nop

    // 0x800B3CAC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3CB0: nop

    // 0x800B3CB4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
L_800B3CB8:
    // 0x800B3CB8: b           L_800B3D50
    // 0x800B3CBC: nop

        goto L_800B3D50;
    // 0x800B3CBC: nop

L_800B3CC0:
    // 0x800B3CC0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800B3CC4: nop

    // 0x800B3CC8: lw          $t6, 0x108($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X108);
    // 0x800B3CCC: lh          $t7, 0x102($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X102);
    // 0x800B3CD0: lwc1        $f16, 0xF8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x800B3CD4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B3CD8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800B3CDC: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x800B3CE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B3CE4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B3CE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B3CEC: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800B3CF0: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800B3CF4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800B3CF8: bc1f        L_800B3D0C
    if (!c1cs) {
        // 0x800B3CFC: nop
    
            goto L_800B3D0C;
    }
    // 0x800B3CFC: nop

    // 0x800B3D00: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3D04: nop

    // 0x800B3D08: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
L_800B3D0C:
    // 0x800B3D0C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800B3D10: nop

    // 0x800B3D14: lw          $t9, 0x108($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X108);
    // 0x800B3D18: lwc1        $f18, 0xF8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x800B3D1C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800B3D20: lwc1        $f8, 0xD0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x800B3D24: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B3D28: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B3D2C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800B3D30: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B3D34: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800B3D38: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800B3D3C: bc1f        L_800B3D50
    if (!c1cs) {
        // 0x800B3D40: nop
    
            goto L_800B3D50;
    }
    // 0x800B3D40: nop

    // 0x800B3D44: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3D48: nop

    // 0x800B3D4C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_800B3D50:
    // 0x800B3D50: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800B3D54: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800B3D58: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B3D5C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B3D60: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x800B3D64: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3D68: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800B3D6C: bne         $at, $zero, L_800B3AC8
    if (ctx->r1 != 0) {
        // 0x800B3D70: sw          $t3, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r11;
            goto L_800B3AC8;
    }
    // 0x800B3D70: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
L_800B3D74:
    // 0x800B3D74: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B3D78: nop

    // 0x800B3D7C: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800B3D80: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B3D84: nop

    // 0x800B3D88: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800B3D8C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B3D90: nop

    // 0x800B3D94: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800B3D98: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B3D9C: nop

    // 0x800B3DA0: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800B3DA4: b           L_800B3DB4
    // 0x800B3DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3DB4;
    // 0x800B3DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3DAC: b           L_800B3DB4
    // 0x800B3DB0: nop

        goto L_800B3DB4;
    // 0x800B3DB0: nop

L_800B3DB4:
    // 0x800B3DB4: jr          $ra
    // 0x800B3DB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B3DB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80096474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009647C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80096480: lw          $t6, -0x800($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X800);
    // 0x80096484: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80096488: addiu       $t7, $t7, -0x2820
    ctx->r15 = ADD32(ctx->r15, -0X2820);
    // 0x8009648C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80096490: slti        $at, $t8, 0x1F01
    ctx->r1 = SIGNED(ctx->r24) < 0X1F01 ? 1 : 0;
    // 0x80096494: bne         $at, $zero, L_800964A4
    if (ctx->r1 != 0) {
        // 0x80096498: nop
    
            goto L_800964A4;
    }
    // 0x80096498: nop

    // 0x8009649C: b           L_800967C8
    // 0x800964A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800967C8;
    // 0x800964A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800964A4:
    // 0x800964A4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800964A8: lw          $t9, -0x4CD8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CD8);
    // 0x800964AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800964B0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800964B4: addiu       $t1, $t1, -0x44B8
    ctx->r9 = ADD32(ctx->r9, -0X44B8);
    // 0x800964B8: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800964BC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800964C0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x800964C4: jal         0x800BCFCC
    // 0x800964C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x800964C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800964CC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800964D0: lw          $t2, -0x800($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X800);
    // 0x800964D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800964D8: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x800964DC: sw          $t3, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r11;
    // 0x800964E0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800964E4: lw          $t4, -0x4CE0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CE0);
    // 0x800964E8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800964EC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800964F0: addiu       $t6, $t6, -0x44B8
    ctx->r14 = ADD32(ctx->r14, -0X44B8);
    // 0x800964F4: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800964F8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800964FC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x80096500: jal         0x800BCFCC
    // 0x80096504: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x80096504: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80096508: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8009650C: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x80096510: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096514: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x80096518: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x8009651C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096520: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096524: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096528: addiu       $a1, $a1, 0x6B98
    ctx->r5 = ADD32(ctx->r5, 0X6B98);
    // 0x8009652C: jal         0x800BCFCC
    // 0x80096530: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x80096530: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80096534: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80096538: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x8009653C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096540: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80096544: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x80096548: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009654C: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096550: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096554: addiu       $a1, $a1, 0x6BA0
    ctx->r5 = ADD32(ctx->r5, 0X6BA0);
    // 0x80096558: jal         0x800BCFCC
    // 0x8009655C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x8009655C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80096560: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096564: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x80096568: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009656C: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80096570: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x80096574: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096578: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x8009657C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096580: addiu       $a1, $a1, 0x6BA8
    ctx->r5 = ADD32(ctx->r5, 0X6BA8);
    // 0x80096584: jal         0x800BCFCC
    // 0x80096588: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x80096588: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x8009658C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096590: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x80096594: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096598: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x8009659C: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x800965A0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800965A4: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800965A8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800965AC: addiu       $a1, $a1, 0x6BC0
    ctx->r5 = ADD32(ctx->r5, 0X6BC0);
    // 0x800965B0: jal         0x800BCFCC
    // 0x800965B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x800965B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x800965B8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800965BC: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x800965C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800965C4: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800965C8: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x800965CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800965D0: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800965D4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800965D8: addiu       $a1, $a1, 0x6C08
    ctx->r5 = ADD32(ctx->r5, 0X6C08);
    // 0x800965DC: jal         0x800BCFCC
    // 0x800965E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_6;
    // 0x800965E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x800965E4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800965E8: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x800965EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800965F0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800965F4: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x800965F8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800965FC: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096600: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096604: addiu       $a1, $a1, 0x6C14
    ctx->r5 = ADD32(ctx->r5, 0X6C14);
    // 0x80096608: jal         0x800BCFCC
    // 0x8009660C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_7;
    // 0x8009660C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80096610: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80096614: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x80096618: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009661C: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80096620: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x80096624: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096628: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x8009662C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096630: addiu       $a1, $a1, -0x4CE0
    ctx->r5 = ADD32(ctx->r5, -0X4CE0);
    // 0x80096634: jal         0x800BCFCC
    // 0x80096638: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_8;
    // 0x80096638: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x8009663C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096640: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x80096644: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096648: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x8009664C: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x80096650: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096654: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096658: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8009665C: addiu       $a1, $a1, -0x4CD8
    ctx->r5 = ADD32(ctx->r5, -0X4CD8);
    // 0x80096660: jal         0x800BCFCC
    // 0x80096664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_9;
    // 0x80096664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x80096668: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8009666C: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x80096670: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096674: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80096678: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x8009667C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096680: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096684: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096688: addiu       $a1, $a1, -0x4CD0
    ctx->r5 = ADD32(ctx->r5, -0X4CD0);
    // 0x8009668C: jal         0x800BCFCC
    // 0x80096690: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_10;
    // 0x80096690: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x80096694: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096698: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x8009669C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800966A0: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800966A4: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x800966A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800966AC: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800966B0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800966B4: addiu       $a1, $a1, -0x4CC8
    ctx->r5 = ADD32(ctx->r5, -0X4CC8);
    // 0x800966B8: jal         0x800BCFCC
    // 0x800966BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_11;
    // 0x800966BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x800966C0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800966C4: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x800966C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800966CC: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800966D0: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x800966D4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800966D8: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800966DC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800966E0: addiu       $a1, $a1, -0x4CBC
    ctx->r5 = ADD32(ctx->r5, -0X4CBC);
    // 0x800966E4: jal         0x800BCFCC
    // 0x800966E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_12;
    // 0x800966E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x800966EC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800966F0: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x800966F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800966F8: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800966FC: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x80096700: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096704: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096708: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8009670C: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x80096710: jal         0x800BCFCC
    // 0x80096714: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_13;
    // 0x80096714: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_13:
    // 0x80096718: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8009671C: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x80096720: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096724: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80096728: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x8009672C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096730: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096734: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096738: addiu       $a1, $a1, -0x4510
    ctx->r5 = ADD32(ctx->r5, -0X4510);
    // 0x8009673C: jal         0x800BCFCC
    // 0x80096740: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_14;
    // 0x80096740: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_14:
    // 0x80096744: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096748: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x8009674C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096750: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80096754: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x80096758: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009675C: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096760: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096764: addiu       $a1, $a1, -0x44D8
    ctx->r5 = ADD32(ctx->r5, -0X44D8);
    // 0x80096768: jal         0x800BCFCC
    // 0x8009676C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_15;
    // 0x8009676C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_15:
    // 0x80096770: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096774: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x80096778: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009677C: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x80096780: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x80096784: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096788: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x8009678C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096790: addiu       $a1, $a1, -0x44BC
    ctx->r5 = ADD32(ctx->r5, -0X44BC);
    // 0x80096794: jal         0x800BCFCC
    // 0x80096798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_16;
    // 0x80096798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_16:
    // 0x8009679C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800967A0: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x800967A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800967A8: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800967AC: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x800967B0: jal         0x800C4270
    // 0x800967B4: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_17;
    // 0x800967B4: nop

    after_17:
    // 0x800967B8: b           L_800967C8
    // 0x800967BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800967C8;
    // 0x800967BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800967C0: b           L_800967C8
    // 0x800967C4: nop

        goto L_800967C8;
    // 0x800967C4: nop

L_800967C8:
    // 0x800967C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800967CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800967D0: jr          $ra
    // 0x800967D4: nop

    return;
    // 0x800967D4: nop

;}
RECOMP_FUNC void func_800778D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800778D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800778D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800778D8: nop

    // 0x800778DC: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x800778E0: nop

    // 0x800778E4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800778E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800778EC: jr          $ra
    // 0x800778F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800778F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800778F4: jr          $ra
    // 0x800778F8: nop

    return;
    // 0x800778F8: nop

    // 0x800778FC: jr          $ra
    // 0x80077900: nop

    return;
    // 0x80077900: nop

;}
RECOMP_FUNC void _loadBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D59B8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D59BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D59C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D59C4: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800D59C8: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800D59CC: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800D59D0: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800D59D4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800D59D8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D59DC: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x800D59E0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x800D59E4: beq         $at, $zero, L_800D59F0
    if (ctx->r1 == 0) {
        // 0x800D59E8: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_800D59F0;
    }
    // 0x800D59E8: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x800D59EC: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_800D59F0:
    // 0x800D59F0: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x800D59F4: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x800D59F8: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x800D59FC: beq         $at, $zero, L_800D5ADC
    if (ctx->r1 == 0) {
        // 0x800D5A00: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_800D5ADC;
    }
    // 0x800D5A00: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800D5A04: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x800D5A08: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D5A0C: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x800D5A10: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800D5A14: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800D5A18: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800D5A1C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800D5A20: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800D5A24: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800D5A28: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800D5A2C: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x800D5A30: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800D5A34: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x800D5A38: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800D5A3C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800D5A40: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800D5A44: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800D5A48: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800D5A4C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800D5A50: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800D5A54: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D5A58: jal         0x800C79C0
    // 0x800D5A5C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800D5A5C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800D5A60: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800D5A64: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800D5A68: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D5A6C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800D5A70: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800D5A74: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800D5A78: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800D5A7C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D5A80: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800D5A84: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D5A88: subu        $t8, $a3, $t1
    ctx->r24 = SUB32(ctx->r7, ctx->r9);
    // 0x800D5A8C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800D5A90: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D5A94: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x800D5A98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D5A9C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800D5AA0: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800D5AA4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D5AA8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D5AAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D5AB0: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800D5AB4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D5AB8: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x800D5ABC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800D5AC0: jal         0x800C79C0
    // 0x800D5AC4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800D5AC4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x800D5AC8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800D5ACC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800D5AD0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800D5AD4: b           L_800D5B20
    // 0x800D5AD8: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
        goto L_800D5B20;
    // 0x800D5AD8: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_800D5ADC:
    // 0x800D5ADC: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x800D5AE0: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D5AE4: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800D5AE8: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x800D5AEC: sw          $a3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r7;
    // 0x800D5AF0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800D5AF4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D5AF8: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x800D5AFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D5B00: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800D5B04: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800D5B08: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D5B0C: jal         0x800C79C0
    // 0x800D5B10: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D5B10: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800D5B14: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800D5B18: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D5B1C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800D5B20:
    // 0x800D5B20: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D5B24: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x800D5B28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D5B2C: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800D5B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5B34: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800D5B38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D5B3C: jr          $ra
    // 0x800D5B40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D5B40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8006F9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F9B0: jal         0x80061348
    // 0x8006F9B4: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F9B4: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006F9B8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F9BC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F9C0: b           L_8006F9D0
    // 0x8006F9C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F9D0;
    // 0x8006F9C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F9C8: b           L_8006F9D0
    // 0x8006F9CC: nop

        goto L_8006F9D0;
    // 0x8006F9CC: nop

L_8006F9D0:
    // 0x8006F9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F9D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F9D8: jr          $ra
    // 0x8006F9DC: nop

    return;
    // 0x8006F9DC: nop

;}
RECOMP_FUNC void func_800744A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800744A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800744AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800744B0: nop

    // 0x800744B4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800744B8: nop

    // 0x800744BC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800744C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800744C4: jr          $ra
    // 0x800744C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800744C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800744CC: jr          $ra
    // 0x800744D0: nop

    return;
    // 0x800744D0: nop

    // 0x800744D4: jr          $ra
    // 0x800744D8: nop

    return;
    // 0x800744D8: nop

;}
RECOMP_FUNC void func_8000F624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F624: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F62C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000F630: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8000F634: jal         0x8000F9D0
    // 0x8000F638: nop

    func_8000F9D0(rdram, ctx);
        goto after_0;
    // 0x8000F638: nop

    after_0:
    // 0x8000F63C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000F640: nop

    // 0x8000F644: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000F648: nop

    // 0x8000F64C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8000F650: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000F654: nop

    // 0x8000F658: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x8000F65C: nop

    // 0x8000F660: slti        $at, $t9, 0x4000
    ctx->r1 = SIGNED(ctx->r25) < 0X4000 ? 1 : 0;
    // 0x8000F664: bne         $at, $zero, L_8000F67C
    if (ctx->r1 != 0) {
        // 0x8000F668: nop
    
            goto L_8000F67C;
    }
    // 0x8000F668: nop

    // 0x8000F66C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000F670: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000F674: bne         $at, $zero, L_8000F7D4
    if (ctx->r1 != 0) {
        // 0x8000F678: nop
    
            goto L_8000F7D4;
    }
    // 0x8000F678: nop

L_8000F67C:
    // 0x8000F67C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000F680: nop

    // 0x8000F684: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8000F688: lwc1        $f6, 0x74($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X74);
    // 0x8000F68C: nop

    // 0x8000F690: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000F694: swc1        $f8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f8.u32l;
    // 0x8000F698: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000F69C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000F6A0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000F6A4: nop

    // 0x8000F6A8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8000F6AC: lhu         $t3, 0x6($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X6);
    // 0x8000F6B0: nop

    // 0x8000F6B4: blez        $t3, L_8000F7CC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000F6B8: nop
    
            goto L_8000F7CC;
    }
    // 0x8000F6B8: nop

L_8000F6BC:
    // 0x8000F6BC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000F6C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F6C4: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F6C8: lwc1        $f10, 0x6C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X6C);
    // 0x8000F6CC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F6D0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000F6D4: lwc1        $f4, 0xCC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8000F6D8: nop

    // 0x8000F6DC: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8000F6E0: swc1        $f6, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f6.u32l;
    // 0x8000F6E4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000F6E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F6EC: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F6F0: lwc1        $f8, 0x70($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X70);
    // 0x8000F6F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F6F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000F6FC: lwc1        $f4, 0xD0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x8000F700: nop

    // 0x8000F704: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8000F708: swc1        $f18, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f18.u32l;
    // 0x8000F70C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000F710: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000F714: lwc1        $f6, 0x74($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X74);
    // 0x8000F718: lwc1        $f11, -0x2B98($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2B98);
    // 0x8000F71C: lwc1        $f10, -0x2B94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B94);
    // 0x8000F720: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000F724: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8000F728: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F72C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F730: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F734: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8000F738: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8000F73C: lwc1        $f8, 0xF4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF4);
    // 0x8000F740: nop

    // 0x8000F744: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8000F748: add.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f10.d + ctx->f6.d;
    // 0x8000F74C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8000F750: swc1        $f4, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f4.u32l;
    // 0x8000F754: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000F758: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000F75C: lwc1        $f18, 0x74($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X74);
    // 0x8000F760: lwc1        $f11, -0x2B90($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2B90);
    // 0x8000F764: lwc1        $f10, -0x2B8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B8C);
    // 0x8000F768: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8000F76C: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8000F770: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F774: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F778: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F77C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8000F780: mul.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8000F784: lwc1        $f8, 0xF8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XF8);
    // 0x8000F788: nop

    // 0x8000F78C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8000F790: add.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d + ctx->f18.d;
    // 0x8000F794: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8000F798: swc1        $f6, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f6.u32l;
    // 0x8000F79C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8000F7A0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F7A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7A8: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8000F7AC: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x8000F7B0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8000F7B4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8000F7B8: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x8000F7BC: nop

    // 0x8000F7C0: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000F7C4: bne         $at, $zero, L_8000F6BC
    if (ctx->r1 != 0) {
        // 0x8000F7C8: nop
    
            goto L_8000F6BC;
    }
    // 0x8000F7C8: nop

L_8000F7CC:
    // 0x8000F7CC: b           L_8000F9B8
    // 0x8000F7D0: nop

        goto L_8000F9B8;
    // 0x8000F7D0: nop

L_8000F7D4:
    // 0x8000F7D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7D8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000F7DC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000F7E0: nop

    // 0x8000F7E4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000F7E8: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x8000F7EC: nop

    // 0x8000F7F0: blez        $t0, L_8000F8A0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000F7F4: nop
    
            goto L_8000F8A0;
    }
    // 0x8000F7F4: nop

L_8000F7F8:
    // 0x8000F7F8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F800: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F804: lwc1        $f4, 0x6C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X6C);
    // 0x8000F808: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F80C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000F810: lwc1        $f18, 0xCC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8000F814: nop

    // 0x8000F818: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8000F81C: swc1        $f16, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f16.u32l;
    // 0x8000F820: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000F824: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F828: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F82C: lwc1        $f6, 0x70($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X70);
    // 0x8000F830: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F834: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8000F838: lwc1        $f18, 0xD0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x8000F83C: nop

    // 0x8000F840: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8000F844: swc1        $f10, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f10.u32l;
    // 0x8000F848: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000F84C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F850: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F854: lwc1        $f16, 0x74($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X74);
    // 0x8000F858: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F85C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000F860: lwc1        $f18, 0xD4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XD4);
    // 0x8000F864: nop

    // 0x8000F868: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8000F86C: swc1        $f8, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f8.u32l;
    // 0x8000F870: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000F874: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F878: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000F87C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000F880: addiu       $t0, $t8, 0x160
    ctx->r8 = ADD32(ctx->r24, 0X160);
    // 0x8000F884: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8000F888: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8000F88C: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x8000F890: nop

    // 0x8000F894: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000F898: bne         $at, $zero, L_8000F7F8
    if (ctx->r1 != 0) {
        // 0x8000F89C: nop
    
            goto L_8000F7F8;
    }
    // 0x8000F89C: nop

L_8000F8A0:
    // 0x8000F8A0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000F8A4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8000F8A8: lw          $t5, 0x1AC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1AC);
    // 0x8000F8AC: nop

    // 0x8000F8B0: bne         $t5, $at, L_8000F9B8
    if (ctx->r13 != ctx->r1) {
        // 0x8000F8B4: nop
    
            goto L_8000F9B8;
    }
    // 0x8000F8B4: nop

    // 0x8000F8B8: lw          $t6, 0x1A8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1A8);
    // 0x8000F8BC: nop

    // 0x8000F8C0: andi        $t3, $t6, 0x40
    ctx->r11 = ctx->r14 & 0X40;
    // 0x8000F8C4: beq         $t3, $zero, L_8000F9B8
    if (ctx->r11 == 0) {
        // 0x8000F8C8: nop
    
            goto L_8000F9B8;
    }
    // 0x8000F8C8: nop

    // 0x8000F8CC: jal         0x8000D688
    // 0x8000F8D0: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    func_8000D688(rdram, ctx);
        goto after_1;
    // 0x8000F8D0: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_1:
    // 0x8000F8D4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8000F8D8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F8DC: nop

    // 0x8000F8E0: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x8000F8E4: nop

    // 0x8000F8E8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8000F8EC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000F8F0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000F8F4: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x8000F8F8: nop

    // 0x8000F8FC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8000F900: lhu         $t9, 0x6($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X6);
    // 0x8000F904: nop

    // 0x8000F908: blez        $t9, L_8000F9B8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8000F90C: nop
    
            goto L_8000F9B8;
    }
    // 0x8000F90C: nop

L_8000F910:
    // 0x8000F910: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000F914: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F918: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F91C: lwc1        $f10, 0x6C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x8000F920: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F924: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000F928: lwc1        $f18, 0xCC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8000F92C: nop

    // 0x8000F930: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8000F934: swc1        $f4, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f4.u32l;
    // 0x8000F938: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000F93C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F940: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F944: lwc1        $f8, 0x70($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X70);
    // 0x8000F948: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F94C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000F950: lwc1        $f18, 0xD0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8000F954: nop

    // 0x8000F958: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8000F95C: swc1        $f6, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f6.u32l;
    // 0x8000F960: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000F964: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F968: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F96C: lwc1        $f4, 0x74($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X74);
    // 0x8000F970: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F974: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000F978: lwc1        $f18, 0xD4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XD4);
    // 0x8000F97C: nop

    // 0x8000F980: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8000F984: swc1        $f16, 0xD4($t7)
    MEM_W(0XD4, ctx->r15) = ctx->f16.u32l;
    // 0x8000F988: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000F98C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F990: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000F994: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x8000F998: addiu       $t9, $t0, 0x160
    ctx->r25 = ADD32(ctx->r8, 0X160);
    // 0x8000F99C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000F9A0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8000F9A4: lhu         $t5, 0x6($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X6);
    // 0x8000F9A8: nop

    // 0x8000F9AC: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000F9B0: bne         $at, $zero, L_8000F910
    if (ctx->r1 != 0) {
        // 0x8000F9B4: nop
    
            goto L_8000F910;
    }
    // 0x8000F9B4: nop

L_8000F9B8:
    // 0x8000F9B8: b           L_8000F9C0
    // 0x8000F9BC: nop

        goto L_8000F9C0;
    // 0x8000F9BC: nop

L_8000F9C0:
    // 0x8000F9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F9C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000F9C8: jr          $ra
    // 0x8000F9CC: nop

    return;
    // 0x8000F9CC: nop

;}
RECOMP_FUNC void func_800627B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800627B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800627BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800627C0: jal         0x8005F064
    // 0x800627C4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800627C4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_0:
    // 0x800627C8: b           L_800627D8
    // 0x800627CC: nop

        goto L_800627D8;
    // 0x800627CC: nop

    // 0x800627D0: b           L_800627D8
    // 0x800627D4: nop

        goto L_800627D8;
    // 0x800627D4: nop

L_800627D8:
    // 0x800627D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800627DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800627E0: jr          $ra
    // 0x800627E4: nop

    return;
    // 0x800627E4: nop

;}
RECOMP_FUNC void func_8006A9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A9C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A9C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A9C8: jal         0x80061348
    // 0x8006A9CC: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006A9CC: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x8006A9D0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A9D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A9D8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A9DC: beq         $v0, $zero, L_8006A9F8
    if (ctx->r2 == 0) {
        // 0x8006A9E0: nop
    
            goto L_8006A9F8;
    }
    // 0x8006A9E0: nop

    // 0x8006A9E4: jal         0x80061348
    // 0x8006A9E8: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006A9E8: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    after_1:
    // 0x8006A9EC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A9F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A9F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006A9F8:
    // 0x8006A9F8: b           L_8006AA08
    // 0x8006A9FC: nop

        goto L_8006AA08;
    // 0x8006A9FC: nop

    // 0x8006AA00: b           L_8006AA08
    // 0x8006AA04: nop

        goto L_8006AA08;
    // 0x8006AA04: nop

L_8006AA08:
    // 0x8006AA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006AA0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006AA10: jr          $ra
    // 0x8006AA14: nop

    return;
    // 0x8006AA14: nop

;}
RECOMP_FUNC void func_800077A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800077A0: addiu       $sp, $sp, -0x500
    ctx->r29 = ADD32(ctx->r29, -0X500);
    // 0x800077A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800077A8: sw          $a0, 0x500($sp)
    MEM_W(0X500, ctx->r29) = ctx->r4;
    // 0x800077AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800077B0: lw          $t6, 0x500($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X500);
    // 0x800077B4: nop

    // 0x800077B8: sw          $t6, 0x4F0($sp)
    MEM_W(0X4F0, ctx->r29) = ctx->r14;
    // 0x800077BC: lw          $t7, 0x4F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4F0);
    // 0x800077C0: nop

    // 0x800077C4: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800077C8: nop

    // 0x800077CC: sw          $t8, 0x4EC($sp)
    MEM_W(0X4EC, ctx->r29) = ctx->r24;
    // 0x800077D0: jal         0x800045AC
    // 0x800077D4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800045AC(rdram, ctx);
        goto after_0;
    // 0x800077D4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800077D8: sw          $v0, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r2;
    // 0x800077DC: lw          $t9, 0x378($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X378);
    // 0x800077E0: nop

    // 0x800077E4: beq         $t9, $zero, L_80007804
    if (ctx->r25 == 0) {
        // 0x800077E8: nop
    
            goto L_80007804;
    }
    // 0x800077E8: nop

    // 0x800077EC: lw          $t0, 0x378($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X378);
    // 0x800077F0: nop

    // 0x800077F4: lw          $t1, 0x1A0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A0);
    // 0x800077F8: nop

    // 0x800077FC: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80007800: sw          $t2, 0x1A0($t0)
    MEM_W(0X1A0, ctx->r8) = ctx->r10;
L_80007804:
    // 0x80007804: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80007808: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8000780C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007810: bne         $t3, $at, L_8000784C
    if (ctx->r11 != ctx->r1) {
        // 0x80007814: nop
    
            goto L_8000784C;
    }
    // 0x80007814: nop

    // 0x80007818: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8000781C: addiu       $t4, $t4, -0x6070
    ctx->r12 = ADD32(ctx->r12, -0X6070);
    // 0x80007820: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007824: sw          $t4, -0x5B34($at)
    MEM_W(-0X5B34, ctx->r1) = ctx->r12;
    // 0x80007828: lui         $t5, 0x8099
    ctx->r13 = S32(0X8099 << 16);
    // 0x8000782C: addiu       $t5, $t5, 0x75C0
    ctx->r13 = ADD32(ctx->r13, 0X75C0);
    // 0x80007830: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007834: sw          $t5, -0x5B3C($at)
    MEM_W(-0X5B3C, ctx->r1) = ctx->r13;
    // 0x80007838: lui         $t6, 0x8099
    ctx->r14 = S32(0X8099 << 16);
    // 0x8000783C: addiu       $t6, $t6, 0x7600
    ctx->r14 = ADD32(ctx->r14, 0X7600);
    // 0x80007840: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007844: b           L_80007890
    // 0x80007848: sw          $t6, -0x5B38($at)
    MEM_W(-0X5B38, ctx->r1) = ctx->r14;
        goto L_80007890;
    // 0x80007848: sw          $t6, -0x5B38($at)
    MEM_W(-0X5B38, ctx->r1) = ctx->r14;
L_8000784C:
    // 0x8000784C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80007850: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x80007854: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80007858: bne         $t7, $at, L_80007890
    if (ctx->r15 != ctx->r1) {
        // 0x8000785C: nop
    
            goto L_80007890;
    }
    // 0x8000785C: nop

    // 0x80007860: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80007864: addiu       $t8, $t8, -0x5DD0
    ctx->r24 = ADD32(ctx->r24, -0X5DD0);
    // 0x80007868: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000786C: sw          $t8, -0x5B34($at)
    MEM_W(-0X5B34, ctx->r1) = ctx->r24;
    // 0x80007870: lui         $t9, 0x8099
    ctx->r25 = S32(0X8099 << 16);
    // 0x80007874: addiu       $t9, $t9, 0x7740
    ctx->r25 = ADD32(ctx->r25, 0X7740);
    // 0x80007878: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000787C: sw          $t9, -0x5B3C($at)
    MEM_W(-0X5B3C, ctx->r1) = ctx->r25;
    // 0x80007880: lui         $t1, 0x8099
    ctx->r9 = S32(0X8099 << 16);
    // 0x80007884: addiu       $t1, $t1, 0x7770
    ctx->r9 = ADD32(ctx->r9, 0X7770);
    // 0x80007888: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000788C: sw          $t1, -0x5B38($at)
    MEM_W(-0X5B38, ctx->r1) = ctx->r9;
L_80007890:
    // 0x80007890: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007894: sw          $zero, -0x5B40($at)
    MEM_W(-0X5B40, ctx->r1) = 0;
    // 0x80007898: sw          $zero, 0x374($sp)
    MEM_W(0X374, ctx->r29) = 0;
    // 0x8000789C: sw          $zero, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = 0;
    // 0x800078A0: sw          $zero, 0x370($sp)
    MEM_W(0X370, ctx->r29) = 0;
    // 0x800078A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800078A8: nop

    // 0x800078AC: swc1        $f4, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->f4.u32l;
    // 0x800078B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800078B4: nop

    // 0x800078B8: swc1        $f6, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->f6.u32l;
    // 0x800078BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800078C0: nop

    // 0x800078C4: swc1        $f8, 0x35C($sp)
    MEM_W(0X35C, ctx->r29) = ctx->f8.u32l;
    // 0x800078C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800078CC: nop

    // 0x800078D0: swc1        $f10, 0x360($sp)
    MEM_W(0X360, ctx->r29) = ctx->f10.u32l;
    // 0x800078D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800078D8: nop

    // 0x800078DC: swc1        $f16, 0x364($sp)
    MEM_W(0X364, ctx->r29) = ctx->f16.u32l;
    // 0x800078E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800078E4: nop

    // 0x800078E8: swc1        $f18, 0x368($sp)
    MEM_W(0X368, ctx->r29) = ctx->f18.u32l;
    // 0x800078EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800078F0: jal         0x80099E2C
    // 0x800078F4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x800078F4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_1:
    // 0x800078F8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800078FC: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x80007900: lh          $a2, 0x7280($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7280);
    // 0x80007904: lh          $a1, 0x7274($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7274);
    // 0x80007908: jal         0x80008FF0
    // 0x8000790C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80008FF0(rdram, ctx);
        goto after_2;
    // 0x8000790C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80007910: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80007914: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x80007918: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000791C: lw          $t0, 0x138($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X138);
    // 0x80007920: nop

    // 0x80007924: sw          $t0, -0x5B2C($at)
    MEM_W(-0X5B2C, ctx->r1) = ctx->r8;
    // 0x80007928: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000792C: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80007930: nop

    // 0x80007934: lh          $a0, 0x122($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X122);
    // 0x80007938: nop

    // 0x8000793C: sll         $t4, $a0, 8
    ctx->r12 = S32(ctx->r4 << 8);
    // 0x80007940: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80007944: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x80007948: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8000794C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80007950: jal         0x800BC6EC
    // 0x80007954: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80007954: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x80007958: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000795C: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80007960: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80007964: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007968: sw          $s0, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r16;
    // 0x8000796C: sw          $s0, -0x5B30($at)
    MEM_W(-0X5B30, ctx->r1) = ctx->r16;
    // 0x80007970: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80007974: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80007978: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000797C: lh          $a2, 0x122($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X122);
    // 0x80007980: lw          $a1, -0x5B2C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5B2C);
    // 0x80007984: lw          $a0, 0x138($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X138);
    // 0x80007988: sll         $t9, $a2, 8
    ctx->r25 = S32(ctx->r6 << 8);
    // 0x8000798C: jal         0x800BD038
    // 0x80007990: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    SysMem_Copy16(rdram, ctx);
        goto after_4;
    // 0x80007990: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_4:
    // 0x80007994: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80007998: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8000799C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800079A0: lh          $t0, 0x122($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X122);
    // 0x800079A4: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x800079A8: sll         $t3, $t0, 8
    ctx->r11 = S32(ctx->r8 << 8);
    // 0x800079AC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800079B0: lw          $a1, -0x5B2C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5B2C);
    // 0x800079B4: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800079B8: jal         0x800BD038
    // 0x800079BC: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    SysMem_Copy16(rdram, ctx);
        goto after_5;
    // 0x800079BC: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    after_5:
    // 0x800079C0: sw          $zero, 0x4FC($sp)
    MEM_W(0X4FC, ctx->r29) = 0;
L_800079C4:
    // 0x800079C4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800079C8: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x800079CC: lw          $t6, 0x4FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4FC);
    // 0x800079D0: lh          $t0, 0x122($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X122);
    // 0x800079D4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800079D8: lw          $t5, -0x5B30($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B30);
    // 0x800079DC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800079E0: sll         $t2, $t0, 8
    ctx->r10 = S32(ctx->r8 << 8);
    // 0x800079E4: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x800079E8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800079EC: lhu         $t9, 0x1D0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1D0);
    // 0x800079F0: addu        $t3, $t5, $t4
    ctx->r11 = ADD32(ctx->r13, ctx->r12);
    // 0x800079F4: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x800079F8: sh          $t9, 0x1E0($t6)
    MEM_H(0X1E0, ctx->r14) = ctx->r25;
    // 0x800079FC: lw          $t8, 0x4FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4FC);
    // 0x80007A00: nop

    // 0x80007A04: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80007A08: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x80007A0C: bne         $at, $zero, L_800079C4
    if (ctx->r1 != 0) {
        // 0x80007A10: sw          $t1, 0x4FC($sp)
        MEM_W(0X4FC, ctx->r29) = ctx->r9;
            goto L_800079C4;
    }
    // 0x80007A10: sw          $t1, 0x4FC($sp)
    MEM_W(0X4FC, ctx->r29) = ctx->r9;
    // 0x80007A14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007A18: sw          $zero, -0x5B28($at)
    MEM_W(-0X5B28, ctx->r1) = 0;
    // 0x80007A1C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80007A20: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80007A24: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x80007A28: lw          $t0, -0x5B30($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B30);
    // 0x80007A2C: nop

    // 0x80007A30: sw          $t0, 0x138($t2)
    MEM_W(0X138, ctx->r10) = ctx->r8;
    // 0x80007A34: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80007A38: lw          $a0, -0x5B34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B34);
    // 0x80007A3C: jal         0x80009D34
    // 0x80007A40: nop

    func_80009D34(rdram, ctx);
        goto after_6;
    // 0x80007A40: nop

    after_6:
    // 0x80007A44: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80007A48: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x80007A4C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80007A50: lh          $t4, 0x122($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X122);
    // 0x80007A54: lw          $t9, -0x5B30($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B30);
    // 0x80007A58: sll         $t3, $t4, 8
    ctx->r11 = S32(ctx->r12 << 8);
    // 0x80007A5C: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x80007A60: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80007A64: sw          $t6, 0x138($t5)
    MEM_W(0X138, ctx->r13) = ctx->r14;
    // 0x80007A68: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80007A6C: lw          $a0, -0x5B34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B34);
    // 0x80007A70: jal         0x80009D34
    // 0x80007A74: nop

    func_80009D34(rdram, ctx);
        goto after_7;
    // 0x80007A74: nop

    after_7:
    // 0x80007A78: jal         0x80009E5C
    // 0x80007A7C: nop

    func_80009E5C(rdram, ctx);
        goto after_8;
    // 0x80007A7C: nop

    after_8:
    // 0x80007A80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007A84: sw          $zero, -0x5B28($at)
    MEM_W(-0X5B28, ctx->r1) = 0;
    // 0x80007A88: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x80007A8C: addiu       $t1, $t8, 0x1C8
    ctx->r9 = ADD32(ctx->r24, 0X1C8);
    // 0x80007A90: sw          $t1, 0x380($sp)
    MEM_W(0X380, ctx->r29) = ctx->r9;
    // 0x80007A94: lw          $a0, 0x380($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X380);
    // 0x80007A98: jal         0x80099E2C
    // 0x80007A9C: nop

    func_80099E2C(rdram, ctx);
        goto after_9;
    // 0x80007A9C: nop

    after_9:
    // 0x80007AA0: lw          $t0, 0x380($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X380);
    // 0x80007AA4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80007AA8: lw          $t2, 0xC0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC0);
    // 0x80007AAC: nop

    // 0x80007AB0: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80007AB4: sw          $t4, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r12;
    // 0x80007AB8: lw          $t7, 0x380($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X380);
    // 0x80007ABC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80007AC0: sh          $t3, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r11;
    // 0x80007AC4: lw          $t6, 0x380($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X380);
    // 0x80007AC8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80007ACC: sh          $t9, 0x114($t6)
    MEM_H(0X114, ctx->r14) = ctx->r25;
    // 0x80007AD0: lw          $t8, 0x380($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X380);
    // 0x80007AD4: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80007AD8: sw          $t5, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r13;
    // 0x80007ADC: lw          $t2, 0x380($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X380);
    // 0x80007AE0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80007AE4: sh          $t1, 0x100($t2)
    MEM_H(0X100, ctx->r10) = ctx->r9;
    // 0x80007AE8: lw          $t0, 0x380($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X380);
    // 0x80007AEC: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80007AF0: sh          $t4, 0x102($t0)
    MEM_H(0X102, ctx->r8) = ctx->r12;
    // 0x80007AF4: lw          $t7, 0x380($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X380);
    // 0x80007AF8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80007AFC: sh          $t3, 0x118($t7)
    MEM_H(0X118, ctx->r15) = ctx->r11;
    // 0x80007B00: lw          $t6, 0x380($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X380);
    // 0x80007B04: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80007B08: sh          $t9, 0x11A($t6)
    MEM_H(0X11A, ctx->r14) = ctx->r25;
    // 0x80007B0C: lw          $t8, 0x380($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X380);
    // 0x80007B10: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80007B14: sh          $t5, 0x11C($t8)
    MEM_H(0X11C, ctx->r24) = ctx->r13;
    // 0x80007B18: lw          $t2, 0x380($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X380);
    // 0x80007B1C: addiu       $t1, $zero, 0xAF
    ctx->r9 = ADD32(0, 0XAF);
    // 0x80007B20: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x80007B24: lw          $t0, 0x380($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X380);
    // 0x80007B28: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80007B2C: sh          $t4, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r12;
    // 0x80007B30: sw          $zero, 0x4F8($sp)
    MEM_W(0X4F8, ctx->r29) = 0;
    // 0x80007B34: lw          $t3, 0x4F8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F8);
    // 0x80007B38: nop

    // 0x80007B3C: bne         $t3, $zero, L_800083D4
    if (ctx->r11 != 0) {
        // 0x80007B40: nop
    
            goto L_800083D4;
    }
    // 0x80007B40: nop

L_80007B44:
    // 0x80007B44: lw          $t7, 0x4F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007B48: addiu       $a1, $sp, 0x4E8
    ctx->r5 = ADD32(ctx->r29, 0X4E8);
    // 0x80007B4C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80007B50: jal         0x800C143C
    // 0x80007B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_10;
    // 0x80007B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80007B58: lw          $t9, 0x4E8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4E8);
    // 0x80007B5C: nop

    // 0x80007B60: lh          $s0, 0x0($t9)
    ctx->r16 = MEM_H(ctx->r25, 0X0);
    // 0x80007B64: nop

    // 0x80007B68: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80007B6C: bne         $at, $zero, L_80007B88
    if (ctx->r1 != 0) {
        // 0x80007B70: nop
    
            goto L_80007B88;
    }
    // 0x80007B70: nop

    // 0x80007B74: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80007B78: beq         $s0, $at, L_80008244
    if (ctx->r16 == ctx->r1) {
        // 0x80007B7C: nop
    
            goto L_80008244;
    }
    // 0x80007B7C: nop

    // 0x80007B80: b           L_800083BC
    // 0x80007B84: nop

        goto L_800083BC;
    // 0x80007B84: nop

L_80007B88:
    // 0x80007B88: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x80007B8C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80007B90: beq         $at, $zero, L_800083BC
    if (ctx->r1 == 0) {
        // 0x80007B94: nop
    
            goto L_800083BC;
    }
    // 0x80007B94: nop

    // 0x80007B98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80007B9C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80007BA0: addu        $at, $at, $t6
    gpr jr_addend_80007BAC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80007BA4: lw          $t6, -0x2E44($at)
    ctx->r14 = ADD32(ctx->r1, -0X2E44);
    // 0x80007BA8: nop

    // 0x80007BAC: jr          $t6
    // 0x80007BB0: nop

    switch (jr_addend_80007BAC >> 2) {
        case 0: goto L_80007BB4; break;
        case 1: goto L_80007E34; break;
        case 2: goto L_800083B4; break;
        case 3: goto L_8000839C; break;
        case 4: goto L_80007F18; break;
        default: switch_error(__func__, 0x80007BAC, 0x800ED1BC);
    }
    // 0x80007BB0: nop

L_80007BB4:
    // 0x80007BB4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80007BB8: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80007BBC: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80007BC0: nop

    // 0x80007BC4: andi        $t1, $t8, 0x2
    ctx->r9 = ctx->r24 & 0X2;
    // 0x80007BC8: bne         $t1, $zero, L_80007E2C
    if (ctx->r9 != 0) {
        // 0x80007BCC: nop
    
            goto L_80007E2C;
    }
    // 0x80007BCC: nop

    // 0x80007BD0: lw          $t2, 0x4EC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007BD4: nop

    // 0x80007BD8: addiu       $t4, $t2, 0x7FFF
    ctx->r12 = ADD32(ctx->r10, 0X7FFF);
    // 0x80007BDC: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x80007BE0: nop

    // 0x80007BE4: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80007BE8: beq         $at, $zero, L_80007E2C
    if (ctx->r1 == 0) {
        // 0x80007BEC: nop
    
            goto L_80007E2C;
    }
    // 0x80007BEC: nop

    // 0x80007BF0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80007BF4: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x80007BF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80007BFC: sw          $t0, 0x30AC($at)
    MEM_W(0X30AC, ctx->r1) = ctx->r8;
    // 0x80007C00: jal         0x80099768
    // 0x80007C04: nop

    func_80099768(rdram, ctx);
        goto after_11;
    // 0x80007C04: nop

    after_11:
    // 0x80007C08: jal         0x800AFB28
    // 0x80007C0C: nop

    func_800AFB28(rdram, ctx);
        goto after_12;
    // 0x80007C0C: nop

    after_12:
    // 0x80007C10: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80007C14: lw          $t7, -0x4CC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CC4);
    // 0x80007C18: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80007C1C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80007C20: lw          $t3, -0x4CCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CCC);
    // 0x80007C24: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80007C28: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80007C2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80007C30: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x80007C34: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80007C38: jal         0x800BE510
    // 0x80007C3C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800BE510(rdram, ctx);
        goto after_13;
    // 0x80007C3C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_13:
    // 0x80007C40: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80007C44: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80007C48: lw          $t6, -0x4CC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CC4);
    // 0x80007C4C: lw          $t9, -0x4CCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CCC);
    // 0x80007C50: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80007C54: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80007C58: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80007C5C: jal         0x8009A04C
    // 0x80007C60: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_8009A04C(rdram, ctx);
        goto after_14;
    // 0x80007C60: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_14:
    // 0x80007C64: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80007C68: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80007C6C: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80007C70: nop

    // 0x80007C74: andi        $t1, $t8, 0x8
    ctx->r9 = ctx->r24 & 0X8;
    // 0x80007C78: beq         $t1, $zero, L_80007C88
    if (ctx->r9 == 0) {
        // 0x80007C7C: nop
    
            goto L_80007C88;
    }
    // 0x80007C7C: nop

    // 0x80007C80: jal         0x80033788
    // 0x80007C84: nop

    func_80033788(rdram, ctx);
        goto after_15;
    // 0x80007C84: nop

    after_15:
L_80007C88:
    // 0x80007C88: jal         0x80032604
    // 0x80007C8C: nop

    func_80032604(rdram, ctx);
        goto after_16;
    // 0x80007C8C: nop

    after_16:
    // 0x80007C90: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80007C94: addiu       $t2, $t2, 0x7340
    ctx->r10 = ADD32(ctx->r10, 0X7340);
    // 0x80007C98: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80007C9C: jal         0x8000262C
    // 0x80007CA0: addiu       $a1, $t2, 0x580
    ctx->r5 = ADD32(ctx->r10, 0X580);
    func_8000262C(rdram, ctx);
        goto after_17;
    // 0x80007CA0: addiu       $a1, $t2, 0x580
    ctx->r5 = ADD32(ctx->r10, 0X580);
    after_17:
    // 0x80007CA4: jal         0x80002824
    // 0x80007CA8: nop

    func_80002824(rdram, ctx);
        goto after_18;
    // 0x80007CA8: nop

    after_18:
    // 0x80007CAC: jal         0x8000849C
    // 0x80007CB0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8000849C(rdram, ctx);
        goto after_19;
    // 0x80007CB0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_19:
    // 0x80007CB4: jal         0x800305A4
    // 0x80007CB8: nop

    func_800305A4(rdram, ctx);
        goto after_20;
    // 0x80007CB8: nop

    after_20:
    // 0x80007CBC: jal         0x8002A39C
    // 0x80007CC0: nop

    func_8002A39C(rdram, ctx);
        goto after_21;
    // 0x80007CC0: nop

    after_21:
    // 0x80007CC4: jal         0x80082958
    // 0x80007CC8: nop

    func_80082958(rdram, ctx);
        goto after_22;
    // 0x80007CC8: nop

    after_22:
    // 0x80007CCC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80007CD0: lw          $t4, -0x73AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73AC);
    // 0x80007CD4: nop

    // 0x80007CD8: beq         $t4, $zero, L_80007D2C
    if (ctx->r12 == 0) {
        // 0x80007CDC: sw          $t4, 0x384($sp)
        MEM_W(0X384, ctx->r29) = ctx->r12;
            goto L_80007D2C;
    }
    // 0x80007CDC: sw          $t4, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r12;
L_80007CE0:
    // 0x80007CE0: jal         0x800C1754
    // 0x80007CE4: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_23;
    // 0x80007CE4: nop

    after_23:
    // 0x80007CE8: lw          $a0, 0x384($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X384);
    // 0x80007CEC: jal         0x8009A14C
    // 0x80007CF0: nop

    func_8009A14C(rdram, ctx);
        goto after_24;
    // 0x80007CF0: nop

    after_24:
    // 0x80007CF4: lw          $a0, 0x384($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X384);
    // 0x80007CF8: jal         0x800997D8
    // 0x80007CFC: nop

    func_800997D8(rdram, ctx);
        goto after_25;
    // 0x80007CFC: nop

    after_25:
    // 0x80007D00: jal         0x800C1A28
    // 0x80007D04: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_26;
    // 0x80007D04: nop

    after_26:
    // 0x80007D08: lw          $t0, 0x384($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X384);
    // 0x80007D0C: nop

    // 0x80007D10: lw          $t3, 0x14C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X14C);
    // 0x80007D14: nop

    // 0x80007D18: sw          $t3, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r11;
    // 0x80007D1C: lw          $t7, 0x384($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X384);
    // 0x80007D20: nop

    // 0x80007D24: bne         $t7, $zero, L_80007CE0
    if (ctx->r15 != 0) {
        // 0x80007D28: nop
    
            goto L_80007CE0;
    }
    // 0x80007D28: nop

L_80007D2C:
    // 0x80007D2C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80007D30: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80007D34: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x80007D38: nop

    // 0x80007D3C: andi        $t5, $t6, 0x100
    ctx->r13 = ctx->r14 & 0X100;
    // 0x80007D40: bne         $t5, $zero, L_80007D64
    if (ctx->r13 != 0) {
        // 0x80007D44: nop
    
            goto L_80007D64;
    }
    // 0x80007D44: nop

    // 0x80007D48: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80007D4C: jal         0x8009A664
    // 0x80007D50: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_27;
    // 0x80007D50: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_27:
    // 0x80007D54: jal         0x8002C2F8
    // 0x80007D58: nop

    func_8002C2F8(rdram, ctx);
        goto after_28;
    // 0x80007D58: nop

    after_28:
    // 0x80007D5C: b           L_80007D78
    // 0x80007D60: nop

        goto L_80007D78;
    // 0x80007D60: nop

L_80007D64:
    // 0x80007D64: jal         0x8002C2F8
    // 0x80007D68: nop

    func_8002C2F8(rdram, ctx);
        goto after_29;
    // 0x80007D68: nop

    after_29:
    // 0x80007D6C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80007D70: jal         0x8009A664
    // 0x80007D74: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_30;
    // 0x80007D74: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_30:
L_80007D78:
    // 0x80007D78: jal         0x8001635C
    // 0x80007D7C: nop

    func_8001635C(rdram, ctx);
        goto after_31;
    // 0x80007D7C: nop

    after_31:
    // 0x80007D80: jal         0x800BE684
    // 0x80007D84: nop

    func_800BE684(rdram, ctx);
        goto after_32;
    // 0x80007D84: nop

    after_32:
    // 0x80007D88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80007D8C: jal         0x8009A664
    // 0x80007D90: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_33;
    // 0x80007D90: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_33:
    // 0x80007D94: jal         0x800BE610
    // 0x80007D98: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_34;
    // 0x80007D98: nop

    after_34:
    // 0x80007D9C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80007DA0: lw          $t8, 0x1B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B4C);
    // 0x80007DA4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80007DA8: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x80007DAC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80007DB0: jal         0x8009908C
    // 0x80007DB4: subu        $a1, $t1, $t8
    ctx->r5 = SUB32(ctx->r9, ctx->r24);
    CreateGfxTask(rdram, ctx);
        goto after_35;
    // 0x80007DB4: subu        $a1, $t1, $t8
    ctx->r5 = SUB32(ctx->r9, ctx->r24);
    after_35:
    // 0x80007DB8: lw          $t2, 0x4F0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007DBC: nop

    // 0x80007DC0: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80007DC4: jal         0x80098D24
    // 0x80007DC8: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_36;
    // 0x80007DC8: nop

    after_36:
    // 0x80007DCC: jal         0x80099450
    // 0x80007DD0: nop

    func_80099450(rdram, ctx);
        goto after_37;
    // 0x80007DD0: nop

    after_37:
    // 0x80007DD4: jal         0x80001F54
    // 0x80007DD8: nop

    func_80001F54(rdram, ctx);
        goto after_38;
    // 0x80007DD8: nop

    after_38:
    // 0x80007DDC: jal         0x800020A8
    // 0x80007DE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800020A8(rdram, ctx);
        goto after_39;
    // 0x80007DE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_39:
    // 0x80007DE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007DE8: bne         $v0, $at, L_80007E10
    if (ctx->r2 != ctx->r1) {
        // 0x80007DEC: nop
    
            goto L_80007E10;
    }
    // 0x80007DEC: nop

    // 0x80007DF0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80007DF4: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80007DF8: lhu         $t0, 0x0($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0X0);
    // 0x80007DFC: nop

    // 0x80007E00: ori         $t3, $t0, 0x2
    ctx->r11 = ctx->r8 | 0X2;
    // 0x80007E04: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x80007E08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80007E0C: sw          $t7, 0x4F8($sp)
    MEM_W(0X4F8, ctx->r29) = ctx->r15;
L_80007E10:
    // 0x80007E10: lw          $t9, 0x4EC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007E14: nop

    // 0x80007E18: addiu       $t6, $t9, 0x7FFF
    ctx->r14 = ADD32(ctx->r25, 0X7FFF);
    // 0x80007E1C: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x80007E20: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80007E24: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80007E28: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
L_80007E2C:
    // 0x80007E2C: b           L_800083C4
    // 0x80007E30: nop

        goto L_800083C4;
    // 0x80007E30: nop

L_80007E34:
    // 0x80007E34: lw          $t1, 0x4EC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007E38: nop

    // 0x80007E3C: addiu       $t8, $t1, 0x7FFF
    ctx->r24 = ADD32(ctx->r9, 0X7FFF);
    // 0x80007E40: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80007E44: nop

    // 0x80007E48: beq         $t8, $zero, L_80007E8C
    if (ctx->r24 == 0) {
        // 0x80007E4C: nop
    
            goto L_80007E8C;
    }
    // 0x80007E4C: nop

    // 0x80007E50: jal         0x80099520
    // 0x80007E54: nop

    func_80099520(rdram, ctx);
        goto after_40;
    // 0x80007E54: nop

    after_40:
    // 0x80007E58: lw          $t2, 0x4EC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007E5C: nop

    // 0x80007E60: addiu       $t0, $t2, 0x7FFF
    ctx->r8 = ADD32(ctx->r10, 0X7FFF);
    // 0x80007E64: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x80007E68: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x80007E6C: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x80007E70: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x80007E74: jal         0x800C40D0
    // 0x80007E78: nop

    osGetTime_recomp(rdram, ctx);
        goto after_41;
    // 0x80007E78: nop

    after_41:
    // 0x80007E7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80007E80: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x80007E84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80007E88: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
L_80007E8C:
    // 0x80007E8C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80007E90: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80007E94: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x80007E98: nop

    // 0x80007E9C: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x80007EA0: beq         $t6, $zero, L_80007F10
    if (ctx->r14 == 0) {
        // 0x80007EA4: nop
    
            goto L_80007F10;
    }
    // 0x80007EA4: nop

    // 0x80007EA8: lw          $a0, 0x4F0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007EAC: jal         0x800065BC
    // 0x80007EB0: nop

    func_800065BC(rdram, ctx);
        goto after_42;
    // 0x80007EB0: nop

    after_42:
    // 0x80007EB4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80007EB8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80007EBC: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x80007EC0: lh          $t5, 0x7320($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7320);
    // 0x80007EC4: nop

    // 0x80007EC8: bne         $t5, $t9, L_80007EEC
    if (ctx->r13 != ctx->r25) {
        // 0x80007ECC: nop
    
            goto L_80007EEC;
    }
    // 0x80007ECC: nop

    // 0x80007ED0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80007ED4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80007ED8: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x80007EDC: lh          $t1, 0x7338($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7338);
    // 0x80007EE0: nop

    // 0x80007EE4: beq         $t1, $t8, L_80007F10
    if (ctx->r9 == ctx->r24) {
        // 0x80007EE8: nop
    
            goto L_80007F10;
    }
    // 0x80007EE8: nop

L_80007EEC:
    // 0x80007EEC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80007EF0: lh          $t0, 0x7320($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7320);
    // 0x80007EF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80007EF8: ori         $t3, $t0, 0x8000
    ctx->r11 = ctx->r8 | 0X8000;
    // 0x80007EFC: sh          $t3, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r11;
    // 0x80007F00: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80007F04: lh          $t2, 0x7338($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7338);
    // 0x80007F08: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80007F0C: sh          $t2, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r10;
L_80007F10:
    // 0x80007F10: b           L_800083C4
    // 0x80007F14: nop

        goto L_800083C4;
    // 0x80007F14: nop

L_80007F18:
    // 0x80007F18: jal         0x80032604
    // 0x80007F1C: nop

    func_80032604(rdram, ctx);
        goto after_43;
    // 0x80007F1C: nop

    after_43:
    // 0x80007F20: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80007F24: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80007F28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80007F2C: lhu         $t6, 0x11A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X11A4);
    // 0x80007F30: lhu         $t7, 0x6($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X6);
    // 0x80007F34: nop

    // 0x80007F38: and         $t5, $t7, $t6
    ctx->r13 = ctx->r15 & ctx->r14;
    // 0x80007F3C: bne         $t5, $zero, L_80007F58
    if (ctx->r13 != 0) {
        // 0x80007F40: nop
    
            goto L_80007F58;
    }
    // 0x80007F40: nop

    // 0x80007F44: lhu         $t9, 0x2E($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X2E);
    // 0x80007F48: nop

    // 0x80007F4C: and         $t1, $t9, $t6
    ctx->r9 = ctx->r25 & ctx->r14;
    // 0x80007F50: beq         $t1, $zero, L_80007FA8
    if (ctx->r9 == 0) {
        // 0x80007F54: nop
    
            goto L_80007FA8;
    }
    // 0x80007F54: nop

L_80007F58:
    // 0x80007F58: jal         0x80098BF4
    // 0x80007F5C: nop

    func_80098BF4(rdram, ctx);
        goto after_44;
    // 0x80007F5C: nop

    after_44:
    // 0x80007F60: lw          $t8, 0x4EC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007F64: nop

    // 0x80007F68: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x80007F6C: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80007F70: lw          $t0, 0x4F0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007F74: nop

    // 0x80007F78: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80007F7C: jal         0x800C13B8
    // 0x80007F80: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_45;
    // 0x80007F80: nop

    after_45:
    // 0x80007F84: jal         0x80098820
    // 0x80007F88: nop

    func_80098820(rdram, ctx);
        goto after_46;
    // 0x80007F88: nop

    after_46:
    // 0x80007F8C: lw          $t3, 0x4F0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007F90: nop

    // 0x80007F94: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80007F98: jal         0x80098D24
    // 0x80007F9C: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_47;
    // 0x80007F9C: nop

    after_47:
    // 0x80007FA0: b           L_800083C4
    // 0x80007FA4: nop

        goto L_800083C4;
    // 0x80007FA4: nop

L_80007FA8:
    // 0x80007FA8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80007FAC: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80007FB0: lhu         $t7, 0x0($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X0);
    // 0x80007FB4: nop

    // 0x80007FB8: andi        $t5, $t7, 0x20
    ctx->r13 = ctx->r15 & 0X20;
    // 0x80007FBC: beq         $t5, $zero, L_80008080
    if (ctx->r13 == 0) {
        // 0x80007FC0: nop
    
            goto L_80008080;
    }
    // 0x80007FC0: nop

    // 0x80007FC4: jal         0x80096474
    // 0x80007FC8: nop

    func_80096474(rdram, ctx);
        goto after_48;
    // 0x80007FC8: nop

    after_48:
    // 0x80007FCC: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80007FD0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80007FD4: sw          $t4, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r12;
    // 0x80007FD8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80007FDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80007FE0: sw          $t9, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r25;
    // 0x80007FE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80007FE8: sh          $zero, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = 0;
    // 0x80007FEC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80007FF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007FF4: sw          $t6, 0x6C08($at)
    MEM_W(0X6C08, ctx->r1) = ctx->r14;
    // 0x80007FF8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007FFC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80008000: sw          $t1, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r9;
    // 0x80008004: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80008008: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000800C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008010: swc1        $f16, -0x4CBC($at)
    MEM_W(-0X4CBC, ctx->r1) = ctx->f16.u32l;
    // 0x80008014: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80008018: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000801C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008020: swc1        $f18, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f18.u32l;
    // 0x80008024: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80008028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000802C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008030: swc1        $f4, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f4.u32l;
    // 0x80008034: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80008038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000803C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008040: swc1        $f6, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f6.u32l;
    // 0x80008044: jal         0x80090728
    // 0x80008048: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_80090728(rdram, ctx);
        goto after_49;
    // 0x80008048: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_49:
    // 0x8000804C: jal         0x800C4160
    // 0x80008050: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_50;
    // 0x80008050: nop

    after_50:
    // 0x80008054: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80008058: jal         0x8008ECCC
    // 0x8000805C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_51;
    // 0x8000805C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80008060: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80008064: jal         0x8008EAA8
    // 0x80008068: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8008EAA8(rdram, ctx);
        goto after_52;
    // 0x80008068: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_52:
    // 0x8000806C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80008070: jal         0x8008ECE4
    // 0x80008074: addiu       $a0, $a0, -0x2E50
    ctx->r4 = ADD32(ctx->r4, -0X2E50);
    func_8008ECE4(rdram, ctx);
        goto after_53;
    // 0x80008074: addiu       $a0, $a0, -0x2E50
    ctx->r4 = ADD32(ctx->r4, -0X2E50);
    after_53:
    // 0x80008078: jal         0x800967D8
    // 0x8000807C: nop

    func_800967D8(rdram, ctx);
        goto after_54;
    // 0x8000807C: nop

    after_54:
L_80008080:
    // 0x80008080: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80008084: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80008088: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000808C: lhu         $t3, 0x1038($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1038);
    // 0x80008090: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x80008094: nop

    // 0x80008098: and         $t2, $t0, $t3
    ctx->r10 = ctx->r8 & ctx->r11;
    // 0x8000809C: beq         $t2, $zero, L_800080DC
    if (ctx->r10 == 0) {
        // 0x800080A0: nop
    
            goto L_800080DC;
    }
    // 0x800080A0: nop

    // 0x800080A4: jal         0x80098868
    // 0x800080A8: nop

    func_80098868(rdram, ctx);
        goto after_55;
    // 0x800080A8: nop

    after_55:
    // 0x800080AC: jal         0x80098C1C
    // 0x800080B0: nop

    func_80098C1C(rdram, ctx);
        goto after_56;
    // 0x800080B0: nop

    after_56:
    // 0x800080B4: jal         0x80098820
    // 0x800080B8: nop

    func_80098820(rdram, ctx);
        goto after_57;
    // 0x800080B8: nop

    after_57:
    // 0x800080BC: lw          $t7, 0x4F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4F0);
    // 0x800080C0: nop

    // 0x800080C4: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x800080C8: jal         0x80098D24
    // 0x800080CC: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_58;
    // 0x800080CC: nop

    after_58:
    // 0x800080D0: sw          $zero, 0x4F4($sp)
    MEM_W(0X4F4, ctx->r29) = 0;
    // 0x800080D4: b           L_800083C4
    // 0x800080D8: nop

        goto L_800083C4;
    // 0x800080D8: nop

L_800080DC:
    // 0x800080DC: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800080E0: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x800080E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800080E8: lhu         $t9, 0x1042($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1042);
    // 0x800080EC: lhu         $t4, 0x6($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X6);
    // 0x800080F0: nop

    // 0x800080F4: and         $t6, $t4, $t9
    ctx->r14 = ctx->r12 & ctx->r25;
    // 0x800080F8: beq         $t6, $zero, L_80008228
    if (ctx->r14 == 0) {
        // 0x800080FC: nop
    
            goto L_80008228;
    }
    // 0x800080FC: nop

    // 0x80008100: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80008104: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80008108: lhu         $t8, 0x0($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X0);
    // 0x8000810C: nop

    // 0x80008110: ori         $t0, $t8, 0x4
    ctx->r8 = ctx->r24 | 0X4;
    // 0x80008114: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x80008118: jal         0x80098CD8
    // 0x8000811C: nop

    func_80098CD8(rdram, ctx);
        goto after_59;
    // 0x8000811C: nop

    after_59:
    // 0x80008120: jal         0x80098BF4
    // 0x80008124: nop

    func_80098BF4(rdram, ctx);
        goto after_60;
    // 0x80008124: nop

    after_60:
    // 0x80008128: jal         0x80098820
    // 0x8000812C: nop

    func_80098820(rdram, ctx);
        goto after_61;
    // 0x8000812C: nop

    after_61:
    // 0x80008130: jal         0x80098868
    // 0x80008134: nop

    func_80098868(rdram, ctx);
        goto after_62;
    // 0x80008134: nop

    after_62:
    // 0x80008138: lw          $t3, 0x4EC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4EC);
    // 0x8000813C: nop

    // 0x80008140: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x80008144: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80008148: lw          $t2, 0x4F0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F0);
    // 0x8000814C: nop

    // 0x80008150: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80008154: jal         0x800C13B8
    // 0x80008158: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_63;
    // 0x80008158: nop

    after_63:
    // 0x8000815C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80008160: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80008164: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x80008168: nop

    // 0x8000816C: ori         $t4, $t5, 0x8000
    ctx->r12 = ctx->r13 | 0X8000;
    // 0x80008170: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
    // 0x80008174: lw          $a0, 0x4F0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4F0);
    // 0x80008178: jal         0x800065BC
    // 0x8000817C: nop

    func_800065BC(rdram, ctx);
        goto after_64;
    // 0x8000817C: nop

    after_64:
    // 0x80008180: jal         0x80098CFC
    // 0x80008184: nop

    func_80098CFC(rdram, ctx);
        goto after_65;
    // 0x80008184: nop

    after_65:
    // 0x80008188: jal         0x80098BB8
    // 0x8000818C: nop

    func_80098BB8(rdram, ctx);
        goto after_66;
    // 0x8000818C: nop

    after_66:
    // 0x80008190: jal         0x80098C1C
    // 0x80008194: nop

    func_80098C1C(rdram, ctx);
        goto after_67;
    // 0x80008194: nop

    after_67:
    // 0x80008198: jal         0x80098868
    // 0x8000819C: nop

    func_80098868(rdram, ctx);
        goto after_68;
    // 0x8000819C: nop

    after_68:
    // 0x800081A0: jal         0x80098820
    // 0x800081A4: nop

    func_80098820(rdram, ctx);
        goto after_69;
    // 0x800081A4: nop

    after_69:
    // 0x800081A8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800081AC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800081B0: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x800081B4: lh          $t9, 0x7320($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7320);
    // 0x800081B8: nop

    // 0x800081BC: bne         $t9, $t6, L_800081E0
    if (ctx->r25 != ctx->r14) {
        // 0x800081C0: nop
    
            goto L_800081E0;
    }
    // 0x800081C0: nop

    // 0x800081C4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800081C8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800081CC: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x800081D0: lh          $t8, 0x7338($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7338);
    // 0x800081D4: nop

    // 0x800081D8: beq         $t8, $t0, L_8000820C
    if (ctx->r24 == ctx->r8) {
        // 0x800081DC: nop
    
            goto L_8000820C;
    }
    // 0x800081DC: nop

L_800081E0:
    // 0x800081E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800081E4: lh          $t1, 0x7320($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7320);
    // 0x800081E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800081EC: ori         $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 | 0X8000;
    // 0x800081F0: sh          $t3, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r11;
    // 0x800081F4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800081F8: lh          $t2, 0x7338($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7338);
    // 0x800081FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008200: sh          $t2, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r10;
    // 0x80008204: jal         0x80098BF4
    // 0x80008208: nop

    func_80098BF4(rdram, ctx);
        goto after_70;
    // 0x80008208: nop

    after_70:
L_8000820C:
    // 0x8000820C: lw          $t5, 0x4F0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4F0);
    // 0x80008210: nop

    // 0x80008214: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80008218: jal         0x80098D24
    // 0x8000821C: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_71;
    // 0x8000821C: nop

    after_71:
    // 0x80008220: b           L_800083C4
    // 0x80008224: nop

        goto L_800083C4;
    // 0x80008224: nop

L_80008228:
    // 0x80008228: lw          $t4, 0x4F0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4F0);
    // 0x8000822C: nop

    // 0x80008230: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x80008234: jal         0x80098D24
    // 0x80008238: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_72;
    // 0x80008238: nop

    after_72:
    // 0x8000823C: b           L_800083C4
    // 0x80008240: nop

        goto L_800083C4;
    // 0x80008240: nop

L_80008244:
    // 0x80008244: lw          $t7, 0x4F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4F0);
    // 0x80008248: addiu       $a1, $sp, 0x4E8
    ctx->r5 = ADD32(ctx->r29, 0X4E8);
    // 0x8000824C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80008250: jal         0x800C143C
    // 0x80008254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_73;
    // 0x80008254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_73:
    // 0x80008258: lw          $t9, 0x4E8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4E8);
    // 0x8000825C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80008260: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80008264: nop

    // 0x80008268: bne         $t6, $at, L_800082A4
    if (ctx->r14 != ctx->r1) {
        // 0x8000826C: nop
    
            goto L_800082A4;
    }
    // 0x8000826C: nop

    // 0x80008270: b           L_80008278
    // 0x80008274: nop

        goto L_80008278;
    // 0x80008274: nop

L_80008278:
    // 0x80008278: jal         0x80099520
    // 0x8000827C: nop

    func_80099520(rdram, ctx);
        goto after_74;
    // 0x8000827C: nop

    after_74:
    // 0x80008280: lw          $t8, 0x4EC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4EC);
    // 0x80008284: nop

    // 0x80008288: addiu       $t0, $t8, 0x7FFF
    ctx->r8 = ADD32(ctx->r24, 0X7FFF);
    // 0x8000828C: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x80008290: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x80008294: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80008298: sw          $t1, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r9;
    // 0x8000829C: b           L_800082A4
    // 0x800082A0: nop

        goto L_800082A4;
    // 0x800082A0: nop

L_800082A4:
    // 0x800082A4: lw          $t3, 0x4EC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4EC);
    // 0x800082A8: nop

    // 0x800082AC: addiu       $t2, $t3, 0x7FFF
    ctx->r10 = ADD32(ctx->r11, 0X7FFF);
    // 0x800082B0: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800082B4: nop

    // 0x800082B8: bne         $t2, $zero, L_800082C8
    if (ctx->r10 != 0) {
        // 0x800082BC: nop
    
            goto L_800082C8;
    }
    // 0x800082BC: nop

    // 0x800082C0: b           L_800082D0
    // 0x800082C4: nop

        goto L_800082D0;
    // 0x800082C4: nop

L_800082C8:
    // 0x800082C8: b           L_80008244
    // 0x800082CC: nop

        goto L_80008244;
    // 0x800082CC: nop

L_800082D0:
    // 0x800082D0: jal         0x80005460
    // 0x800082D4: nop

    func_80005460(rdram, ctx);
        goto after_75;
    // 0x800082D4: nop

    after_75:
    // 0x800082D8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800082DC: lw          $a1, -0x73E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73E8);
    // 0x800082E0: addiu       $a0, $sp, 0x388
    ctx->r4 = ADD32(ctx->r29, 0X388);
    // 0x800082E4: jal         0x800BCFCC
    // 0x800082E8: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    SysMem_Copy8(rdram, ctx);
        goto after_76;
    // 0x800082E8: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    after_76:
    // 0x800082EC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800082F0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800082F4: lh          $a1, -0x73E4($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73E4);
    // 0x800082F8: lh          $a0, -0x73F0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X73F0);
    // 0x800082FC: jal         0x80005124
    // 0x80008300: nop

    func_80005124(rdram, ctx);
        goto after_77;
    // 0x80008300: nop

    after_77:
    // 0x80008304: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80008308: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8000830C: lwc1        $f8, 0x454($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X454);
    // 0x80008310: nop

    // 0x80008314: swc1        $f8, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f8.u32l;
    // 0x80008318: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000831C: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x80008320: lwc1        $f10, 0x458($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X458);
    // 0x80008324: nop

    // 0x80008328: swc1        $f10, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f10.u32l;
    // 0x8000832C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80008330: lh          $t7, -0x73F0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73F0);
    // 0x80008334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008338: sh          $t7, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r15;
    // 0x8000833C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008340: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
    // 0x80008344: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80008348: lh          $t9, -0x73E4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X73E4);
    // 0x8000834C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008350: sh          $t9, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r25;
    // 0x80008354: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008358: sh          $t9, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r25;
    // 0x8000835C: lw          $t6, 0x4EC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4EC);
    // 0x80008360: nop

    // 0x80008364: addiu       $at, $t6, 0x7FFF
    ctx->r1 = ADD32(ctx->r14, 0X7FFF);
    // 0x80008368: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x8000836C: lw          $t0, 0x4F0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F0);
    // 0x80008370: nop

    // 0x80008374: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80008378: jal         0x800C13B8
    // 0x8000837C: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_78;
    // 0x8000837C: nop

    after_78:
    // 0x80008380: jal         0x80098820
    // 0x80008384: nop

    func_80098820(rdram, ctx);
        goto after_79;
    // 0x80008384: nop

    after_79:
    // 0x80008388: lw          $t1, 0x4F0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4F0);
    // 0x8000838C: nop

    // 0x80008390: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
    // 0x80008394: b           L_800083C4
    // 0x80008398: nop

        goto L_800083C4;
    // 0x80008398: nop

L_8000839C:
    // 0x8000839C: jal         0x800029BC
    // 0x800083A0: nop

    func_800029BC(rdram, ctx);
        goto after_80;
    // 0x800083A0: nop

    after_80:
L_800083A4:
    // 0x800083A4: b           L_800083A4
    pause_self(rdram);
    // 0x800083A8: nop

    // 0x800083AC: b           L_800083C4
    // 0x800083B0: nop

        goto L_800083C4;
    // 0x800083B0: nop

L_800083B4:
    // 0x800083B4: b           L_800083C4
    // 0x800083B8: nop

        goto L_800083C4;
    // 0x800083B8: nop

L_800083BC:
    // 0x800083BC: b           L_800083C4
    // 0x800083C0: nop

        goto L_800083C4;
    // 0x800083C0: nop

L_800083C4:
    // 0x800083C4: lw          $t8, 0x4F8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4F8);
    // 0x800083C8: nop

    // 0x800083CC: beq         $t8, $zero, L_80007B44
    if (ctx->r24 == 0) {
        // 0x800083D0: nop
    
            goto L_80007B44;
    }
    // 0x800083D0: nop

L_800083D4:
    // 0x800083D4: lw          $t3, 0x4EC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4EC);
    // 0x800083D8: nop

    // 0x800083DC: addiu       $t2, $t3, 0x7FFF
    ctx->r10 = ADD32(ctx->r11, 0X7FFF);
    // 0x800083E0: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800083E4: nop

    // 0x800083E8: blez        $t2, L_8000846C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800083EC: nop
    
            goto L_8000846C;
    }
    // 0x800083EC: nop

L_800083F0:
    // 0x800083F0: lw          $t5, 0x4F0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4F0);
    // 0x800083F4: addiu       $a1, $sp, 0x4E8
    ctx->r5 = ADD32(ctx->r29, 0X4E8);
    // 0x800083F8: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x800083FC: jal         0x800C143C
    // 0x80008400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_81;
    // 0x80008400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_81:
    // 0x80008404: lw          $t4, 0x4E8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4E8);
    // 0x80008408: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000840C: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x80008410: nop

    // 0x80008414: bne         $t7, $at, L_80008450
    if (ctx->r15 != ctx->r1) {
        // 0x80008418: nop
    
            goto L_80008450;
    }
    // 0x80008418: nop

    // 0x8000841C: b           L_80008424
    // 0x80008420: nop

        goto L_80008424;
    // 0x80008420: nop

L_80008424:
    // 0x80008424: jal         0x80099520
    // 0x80008428: nop

    func_80099520(rdram, ctx);
        goto after_82;
    // 0x80008428: nop

    after_82:
    // 0x8000842C: lw          $t9, 0x4EC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4EC);
    // 0x80008430: nop

    // 0x80008434: addiu       $t6, $t9, 0x7FFF
    ctx->r14 = ADD32(ctx->r25, 0X7FFF);
    // 0x80008438: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x8000843C: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80008440: addiu       $t0, $t6, -0x1
    ctx->r8 = ADD32(ctx->r14, -0X1);
    // 0x80008444: sw          $t0, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r8;
    // 0x80008448: b           L_80008450
    // 0x8000844C: nop

        goto L_80008450;
    // 0x8000844C: nop

L_80008450:
    // 0x80008450: lw          $t1, 0x4EC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4EC);
    // 0x80008454: nop

    // 0x80008458: addiu       $t8, $t1, 0x7FFF
    ctx->r24 = ADD32(ctx->r9, 0X7FFF);
    // 0x8000845C: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80008460: nop

    // 0x80008464: bgtz        $t8, L_800083F0
    if (SIGNED(ctx->r24) > 0) {
        // 0x80008468: nop
    
            goto L_800083F0;
    }
    // 0x80008468: nop

L_8000846C:
    // 0x8000846C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80008470: lw          $a0, -0x5B30($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B30);
    // 0x80008474: jal         0x800BC980
    // 0x80008478: nop

    SysMem_Free(rdram, ctx);
        goto after_83;
    // 0x80008478: nop

    after_83:
    // 0x8000847C: jal         0x80009F10
    // 0x80008480: nop

    func_80009F10(rdram, ctx);
        goto after_84;
    // 0x80008480: nop

    after_84:
    // 0x80008484: b           L_8000848C
    // 0x80008488: nop

        goto L_8000848C;
    // 0x80008488: nop

L_8000848C:
    // 0x8000848C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80008490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008494: jr          $ra
    // 0x80008498: addiu       $sp, $sp, 0x500
    ctx->r29 = ADD32(ctx->r29, 0X500);
    return;
    // 0x80008498: addiu       $sp, $sp, 0x500
    ctx->r29 = ADD32(ctx->r29, 0X500);
;}
RECOMP_FUNC void func_800684A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800684A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800684A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800684AC: jal         0x80061488
    // 0x800684B0: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800684B0: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    after_0:
    // 0x800684B4: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800684B8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800684BC: b           L_800684CC
    // 0x800684C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800684CC;
    // 0x800684C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800684C4: b           L_800684CC
    // 0x800684C8: nop

        goto L_800684CC;
    // 0x800684C8: nop

L_800684CC:
    // 0x800684CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800684D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800684D4: jr          $ra
    // 0x800684D8: nop

    return;
    // 0x800684D8: nop

;}
RECOMP_FUNC void func_800499B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800499B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800499B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800499B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800499BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800499C0: lw          $t6, 0x6C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C4);
    // 0x800499C4: nop

    // 0x800499C8: beq         $t6, $zero, L_800499DC
    if (ctx->r14 == 0) {
        // 0x800499CC: nop
    
            goto L_800499DC;
    }
    // 0x800499CC: nop

    // 0x800499D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800499D4: jal         0x80049544
    // 0x800499D8: nop

    func_80049544(rdram, ctx);
        goto after_0;
    // 0x800499D8: nop

    after_0:
L_800499DC:
    // 0x800499DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800499E0: jal         0x80032410
    // 0x800499E4: nop

    func_80032410(rdram, ctx);
        goto after_1;
    // 0x800499E4: nop

    after_1:
    // 0x800499E8: b           L_800499F0
    // 0x800499EC: nop

        goto L_800499F0;
    // 0x800499EC: nop

L_800499F0:
    // 0x800499F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800499F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800499F8: jr          $ra
    // 0x800499FC: nop

    return;
    // 0x800499FC: nop

;}
RECOMP_FUNC void func_8006CB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB90: jal         0x8005F064
    // 0x8006CB94: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CB94: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    after_0:
    // 0x8006CB98: b           L_8006CBA8
    // 0x8006CB9C: nop

        goto L_8006CBA8;
    // 0x8006CB9C: nop

    // 0x8006CBA0: b           L_8006CBA8
    // 0x8006CBA4: nop

        goto L_8006CBA8;
    // 0x8006CBA4: nop

L_8006CBA8:
    // 0x8006CBA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CBB0: jr          $ra
    // 0x8006CBB4: nop

    return;
    // 0x8006CBB4: nop

;}
RECOMP_FUNC void func_8008A964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A96C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008A970: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008A974: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8008A978: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008A97C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8008A980: lbu         $t7, -0x6230($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6230);
    // 0x8008A984: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008A988: nop

    // 0x8008A98C: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x8008A990: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008A994: nop

    // 0x8008A998: sh          $zero, 0xA($t9)
    MEM_H(0XA, ctx->r25) = 0;
    // 0x8008A99C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008A9A0: nop

    // 0x8008A9A4: lhu         $a0, 0x8($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X8);
    // 0x8008A9A8: nop

    // 0x8008A9AC: sll         $t1, $a0, 6
    ctx->r9 = S32(ctx->r4 << 6);
    // 0x8008A9B0: jal         0x800BC6EC
    // 0x8008A9B4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008A9B4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
    // 0x8008A9B8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008A9BC: nop

    // 0x8008A9C0: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x8008A9C4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008A9C8: nop

    // 0x8008A9CC: lhu         $a0, 0x8($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X8);
    // 0x8008A9D0: nop

    // 0x8008A9D4: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8008A9D8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8008A9DC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A9E0: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8008A9E4: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8008A9E8: jal         0x800BC6EC
    // 0x8008A9EC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8008A9EC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_1:
    // 0x8008A9F0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008A9F4: nop

    // 0x8008A9F8: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8008A9FC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA00: nop

    // 0x8008AA04: lhu         $a2, 0x8($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X8);
    // 0x8008AA08: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008AA0C: jal         0x800B1B3C
    // 0x8008AA10: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    func_800B1B3C(rdram, ctx);
        goto after_2;
    // 0x8008AA10: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_2:
    // 0x8008AA14: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AA1C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8008AA20: lhu         $a1, 0x8($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X8);
    // 0x8008AA24: jal         0x8008AAA8
    // 0x8008AA28: nop

    func_8008AAA8(rdram, ctx);
        goto after_3;
    // 0x8008AA28: nop

    after_3:
    // 0x8008AA2C: b           L_8008AA34
    // 0x8008AA30: nop

        goto L_8008AA34;
    // 0x8008AA30: nop

L_8008AA34:
    // 0x8008AA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AA3C: jr          $ra
    // 0x8008AA40: nop

    return;
    // 0x8008AA40: nop

;}
RECOMP_FUNC void func_800657AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800657AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800657B0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800657B4: nop

    // 0x800657B8: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x800657BC: nop

    // 0x800657C0: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x800657C4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800657C8: jr          $ra
    // 0x800657CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800657CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800657D0: jr          $ra
    // 0x800657D4: nop

    return;
    // 0x800657D4: nop

    // 0x800657D8: jr          $ra
    // 0x800657DC: nop

    return;
    // 0x800657DC: nop

;}
