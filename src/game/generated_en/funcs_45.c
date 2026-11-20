#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void Main_UpdateControllers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE960: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BE964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BE968: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BE96C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BE970: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BE974: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800BE978: nop

    // 0x800BE97C: bne         $t6, $zero, L_800BE9A4
    if (ctx->r14 != 0) {
        // 0x800BE980: nop

            goto L_800BE9A4;
    }
    // 0x800BE980: nop

    // 0x800BE984: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE988: jal         0x800C5590
    // 0x800BE98C: addiu       $a0, $a0, 0x24E0
    ctx->r4 = ADD32(ctx->r4, 0X24E0);
    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x800BE98C: addiu       $a0, $a0, 0x24E0
    ctx->r4 = ADD32(ctx->r4, 0X24E0);
    after_0:
    // 0x800BE990: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE994: addiu       $a0, $a0, 0x24E0
    ctx->r4 = ADD32(ctx->r4, 0X24E0);
    // 0x800BE998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BE99C: jal         0x800C4C40
    // 0x800BE9A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE9A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_800BE9A4:
    // 0x800BE9A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE9A8: jal         0x800C5654
    // 0x800BE9AC: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    osContGetReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x800BE9AC: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    after_2:
    // 0x800BE9B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800BE9B4:
    // 0x800BE9B4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE9B8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BE9BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BE9C0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BE9C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800BE9C8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800BE9CC: lbu         $t9, 0x255C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X255C);
    // 0x800BE9D0: nop

    // 0x800BE9D4: bne         $t9, $zero, L_800BEC00
    if (ctx->r25 != 0) {
        // 0x800BE9D8: nop

            goto L_800BEC00;
    }
    // 0x800BE9D8: nop

    // 0x800BE9DC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE9E0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BE9E4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BE9E8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BE9EC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800BE9F0: addiu       $t2, $t2, 0xDA8
    ctx->r10 = ADD32(ctx->r10, 0XDA8);
    // 0x800BE9F4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800BE9F8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BE9FC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA00: nop

    // 0x800BEA04: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800BEA08: nop

    // 0x800BEA0C: beq         $t5, $zero, L_800BEA3C
    if (ctx->r13 == 0) {
        // 0x800BEA10: nop

            goto L_800BEA3C;
    }
    // 0x800BEA10: nop

    // 0x800BEA14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BEA18: lwc1        $f4, 0xE50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE50);
    // 0x800BEA1C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA20: nop

    // 0x800BEA24: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x800BEA28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BEA2C: lwc1        $f6, 0xE5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE5C);
    // 0x800BEA30: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA34: nop

    // 0x800BEA38: swc1        $f6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f6.u32l;
L_800BEA3C:
    // 0x800BEA3C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA40: nop

    // 0x800BEA44: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BEA48: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA4C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800BEA50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEA54: lwc1        $f8, 0x18($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X18);
    // 0x800BEA58: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEA5C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BEA60: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BEA64: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800BEA68: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800BEA6C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BEA70: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800BEA74: lb          $t2, 0x255A($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X255A);
    // 0x800BEA78: nop

    // 0x800BEA7C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800BEA80: nop

    // 0x800BEA84: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BEA88: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BEA8C: swc1        $f6, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f6.u32l;
    // 0x800BEA90: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA94: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800BEA98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEA9C: lwc1        $f8, 0x1C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800BEAA0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEAA4: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BEAA8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800BEAAC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800BEAB0: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800BEAB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BEAB8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800BEABC: lb          $t6, 0x255B($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X255B);
    // 0x800BEAC0: nop

    // 0x800BEAC4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800BEAC8: nop

    // 0x800BEACC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BEAD0: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800BEAD4: swc1        $f6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f6.u32l;
    // 0x800BEAD8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BEADC: nop

    // 0x800BEAE0: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x800BEAE4: nop

    // 0x800BEAE8: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800BEAEC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEAF0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BEAF4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BEAF8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800BEAFC: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800BEB00: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800BEB04: lhu         $t2, 0x2558($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X2558);
    // 0x800BEB08: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB0C: nop

    // 0x800BEB10: sh          $t2, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r10;
    // 0x800BEB14: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB18: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BEB1C: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800BEB20: nop

    // 0x800BEB24: xor         $t3, $t5, $t6
    ctx->r11 = ctx->r13 ^ ctx->r14;
    // 0x800BEB28: and         $t7, $t3, $t5
    ctx->r15 = ctx->r11 & ctx->r13;
    // 0x800BEB2C: sh          $t7, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r15;
    // 0x800BEB30: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BEB38: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800BEB3C: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800BEB40: nop

    // 0x800BEB44: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800BEB48: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x800BEB4C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB50: nop

    // 0x800BEB54: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800BEB58: lhu         $t2, 0xA($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0XA);
    // 0x800BEB5C: nop

    // 0x800BEB60: beq         $t1, $t2, L_800BEBA4
    if (ctx->r9 == ctx->r10) {
        // 0x800BEB64: nop

            goto L_800BEBA4;
    }
    // 0x800BEB64: nop

    // 0x800BEB68: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB6C: nop

    // 0x800BEB70: lhu         $t6, 0x4($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X4);
    // 0x800BEB74: nop

    // 0x800BEB78: sh          $t6, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r14;
    // 0x800BEB7C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB80: nop

    // 0x800BEB84: lhu         $t5, 0x4($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X4);
    // 0x800BEB88: nop

    // 0x800BEB8C: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
    // 0x800BEB90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800BEB94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BEB98: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB9C: b           L_800BEBF8
    // 0x800BEBA0: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
        goto L_800BEBF8;
    // 0x800BEBA0: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
L_800BEBA4:
    // 0x800BEBA4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BEBA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BEBAC: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800BEBB0: nop

    // 0x800BEBB4: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800BEBB8: nop

    // 0x800BEBBC: bc1f        L_800BEBEC
    if (!c1cs) {
        // 0x800BEBC0: nop

            goto L_800BEBEC;
    }
    // 0x800BEBC0: nop

    // 0x800BEBC4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BEBC8: nop

    // 0x800BEBCC: lhu         $t0, 0xA($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0XA);
    // 0x800BEBD0: nop

    // 0x800BEBD4: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
    // 0x800BEBD8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800BEBDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BEBE0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BEBE4: b           L_800BEBF8
    // 0x800BEBE8: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
        goto L_800BEBF8;
    // 0x800BEBE8: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
L_800BEBEC:
    // 0x800BEBEC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BEBF0: nop

    // 0x800BEBF4: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
L_800BEBF8:
    // 0x800BEBF8: b           L_800BEC98
    // 0x800BEBFC: nop

        goto L_800BEC98;
    // 0x800BEBFC: nop

L_800BEC00:
    // 0x800BEC00: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEC04: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BEC08: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800BEC0C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800BEC10: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800BEC14: addiu       $t5, $t5, 0xDA8
    ctx->r13 = ADD32(ctx->r13, 0XDA8);
    // 0x800BEC18: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x800BEC1C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BEC20: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800BEC28: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800BEC2C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC30: nop

    // 0x800BEC34: sh          $zero, 0xA($t0)
    MEM_H(0XA, ctx->r8) = 0;
    // 0x800BEC38: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC3C: nop

    // 0x800BEC40: lhu         $s1, 0xA($t8)
    ctx->r17 = MEM_HU(ctx->r24, 0XA);
    // 0x800BEC44: nop

    // 0x800BEC48: sh          $s1, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r17;
    // 0x800BEC4C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC50: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800BEC54: sh          $s0, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r16;
    // 0x800BEC58: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC5C: nop

    // 0x800BEC60: sh          $s0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r16;
    // 0x800BEC64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BEC68: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC6C: nop

    // 0x800BEC70: swc1        $f10, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f10.u32l;
    // 0x800BEC74: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC78: nop

    // 0x800BEC7C: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800BEC80: nop

    // 0x800BEC84: swc1        $f4, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f4.u32l;
    // 0x800BEC88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800BEC8C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC90: nop

    // 0x800BEC94: swc1        $f16, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f16.u32l;
L_800BEC98:
    // 0x800BEC98: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEC9C: nop

    // 0x800BECA0: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x800BECA4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800BECA8: bne         $at, $zero, L_800BE9B4
    if (ctx->r1 != 0) {
        // 0x800BECAC: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_800BE9B4;
    }
    // 0x800BECAC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800BECB0: b           L_800BECB8
    // 0x800BECB4: nop

        goto L_800BECB8;
    // 0x800BECB4: nop

L_800BECB8:
    // 0x800BECB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BECBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BECC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BECC4: jr          $ra
    // 0x800BECC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800BECC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Main_SetContRawStickScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BECCC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BECD0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800BECD4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BECD8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800BECDC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800BECE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BECE4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800BECE8: lw          $t7, 0xDA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XDA8);
    // 0x800BECEC: nop

    // 0x800BECF0: beq         $t7, $zero, L_800BED00
    if (ctx->r15 == 0) {
        // 0x800BECF4: nop

            goto L_800BED00;
    }
    // 0x800BECF4: nop

    // 0x800BECF8: b           L_800BED40
    // 0x800BECFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BED40;
    // 0x800BECFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BED00:
    // 0x800BED00: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800BED04: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800BED08: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800BED0C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800BED10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BED14: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BED18: swc1        $f4, 0xDC0($at)
    MEM_W(0XDC0, ctx->r1) = ctx->f4.u32l;
    // 0x800BED1C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BED20: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800BED24: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BED28: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800BED2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BED30: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800BED34: swc1        $f6, 0xDC4($at)
    MEM_W(0XDC4, ctx->r1) = ctx->f6.u32l;
    // 0x800BED38: b           L_800BED40
    // 0x800BED3C: nop

        goto L_800BED40;
    // 0x800BED3C: nop

L_800BED40:
    // 0x800BED40: jr          $ra
    // 0x800BED44: nop

    return;
    // 0x800BED44: nop

;}
RECOMP_FUNC void Main_SetContStickScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BED4C: swc1        $f12, 0xE50($at)
    MEM_W(0XE50, ctx->r1) = ctx->f12.u32l;
    // 0x800BED50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BED54: swc1        $f14, 0xE5C($at)
    MEM_W(0XE5C, ctx->r1) = ctx->f14.u32l;
    // 0x800BED58: jr          $ra
    // 0x800BED5C: nop

    return;
    // 0x800BED5C: nop

    // 0x800BED60: jr          $ra
    // 0x800BED64: nop

    return;
    // 0x800BED64: nop

;}
RECOMP_FUNC void func_800BED68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED68: nop

    // 0x800BED6C: nop

;}
RECOMP_FUNC void Spi_GetHeader(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BED74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BED78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BED7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BED80: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800BED84: addiu       $a1, $a1, 0x490
    ctx->r5 = ADD32(ctx->r5, 0X490);
    // 0x800BED88: jal         0x800BD218
    // 0x800BED8C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    SysMem_DmaCopy(rdram, ctx);
        goto after_0;
    // 0x800BED8C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x800BED90: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BED94: addiu       $t6, $t6, 0x490
    ctx->r14 = ADD32(ctx->r14, 0X490);
    // 0x800BED98: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BED9C: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800BEDA0: bne         $t7, $at, L_800BEE28
    if (ctx->r15 != ctx->r1) {
        // 0x800BEDA4: nop

            goto L_800BEE28;
    }
    // 0x800BEDA4: nop

    // 0x800BEDA8: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x800BEDAC: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800BEDB0: bne         $t8, $at, L_800BEE28
    if (ctx->r24 != ctx->r1) {
        // 0x800BEDB4: nop

            goto L_800BEE28;
    }
    // 0x800BEDB4: nop

    // 0x800BEDB8: lbu         $t9, 0x2($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X2);
    // 0x800BEDBC: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x800BEDC0: bne         $t9, $at, L_800BEE28
    if (ctx->r25 != ctx->r1) {
        // 0x800BEDC4: nop

            goto L_800BEE28;
    }
    // 0x800BEDC4: nop

    // 0x800BEDC8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BEDCC: addiu       $t0, $t0, 0x490
    ctx->r8 = ADD32(ctx->r8, 0X490);
    // 0x800BEDD0: lbu         $t1, 0x3($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3);
    // 0x800BEDD4: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800BEDD8: beq         $t1, $at, L_800BEE10
    if (ctx->r9 == ctx->r1) {
        // 0x800BEDDC: nop

            goto L_800BEE10;
    }
    // 0x800BEDDC: nop

    // 0x800BEDE0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BEDE4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BEDE8: lw          $t3, 0x49C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X49C);
    // 0x800BEDEC: lw          $t2, 0x498($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X498);
    // 0x800BEDF0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BEDF4: lw          $t5, 0x4A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4A0);
    // 0x800BEDF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800BEDFC: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800BEE00: b           L_800BEE38
    // 0x800BEE04: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
        goto L_800BEE38;
    // 0x800BEE04: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800BEE08: b           L_800BEE20
    // 0x800BEE0C: nop

        goto L_800BEE20;
    // 0x800BEE0C: nop

L_800BEE10:
    // 0x800BEE10: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800BEE14: lw          $v0, 0x494($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X494);
    // 0x800BEE18: b           L_800BEE38
    // 0x800BEE1C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
        goto L_800BEE38;
    // 0x800BEE1C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
L_800BEE20:
    // 0x800BEE20: b           L_800BEE30
    // 0x800BEE24: nop

        goto L_800BEE30;
    // 0x800BEE24: nop

L_800BEE28:
    // 0x800BEE28: b           L_800BEE38
    // 0x800BEE2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BEE38;
    // 0x800BEE2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BEE30:
    // 0x800BEE30: b           L_800BEE38
    // 0x800BEE34: nop

        goto L_800BEE38;
    // 0x800BEE34: nop

L_800BEE38:
    // 0x800BEE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BEE3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BEE40: jr          $ra
    // 0x800BEE44: nop

    return;
    // 0x800BEE44: nop

;}
RECOMP_FUNC void Spi_LimitedDecompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEE48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BEE4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEE50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BEE54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BEE58: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEE5C: jal         0x800BC6EC
    // 0x800BEE60: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800BEE60: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x800BEE64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BEE68: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEE6C: nop

    // 0x800BEE70: bne         $t6, $zero, L_800BEE80
    if (ctx->r14 != 0) {
        // 0x800BEE74: nop

            goto L_800BEE80;
    }
    // 0x800BEE74: nop

    // 0x800BEE78: b           L_800BF0A4
    // 0x800BEE7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BF0A4;
    // 0x800BEE7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BEE80:
    // 0x800BEE80: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEE84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800BEE88: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x800BEE8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEE90: bgez        $a2, L_800BEEA0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BEE94: sra         $t7, $a2, 3
        ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
            goto L_800BEEA0;
    }
    // 0x800BEE94: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800BEE98: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x800BEE9C: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800BEEA0:
    // 0x800BEEA0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800BEEA4: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800BEEA8: jal         0x800BD218
    // 0x800BEEAC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800BEEAC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_1:
    // 0x800BEEB0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEEB4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEEB8: sw          $t9, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r25;
    // 0x800BEEBC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BEEC0: lw          $t0, 0x434($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X434);
    // 0x800BEEC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEEC8: sw          $t0, 0x458($at)
    MEM_W(0X458, ctx->r1) = ctx->r8;
    // 0x800BEECC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BEED0: addiu       $t1, $t1, 0x490
    ctx->r9 = ADD32(ctx->r9, 0X490);
    // 0x800BEED4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800BEED8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BEEDC: addiu       $t2, $t2, 0x4A8
    ctx->r10 = ADD32(ctx->r10, 0X4A8);
    // 0x800BEEE0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEEE4: sw          $t2, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r10;
    // 0x800BEEE8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BEEEC:
    // 0x800BEEEC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BEEF0: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BEEF4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BEEF8: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800BEEFC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BEF00: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x800BEF04: lw          $t8, 0x434($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434);
    // 0x800BEF08: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BEF0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEF10: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BEF14: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BEF18: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800BEF1C: sw          $t9, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r25;
    // 0x800BEF20: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BEF24: nop

    // 0x800BEF28: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BEF2C: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x800BEF30: bne         $at, $zero, L_800BEEEC
    if (ctx->r1 != 0) {
        // 0x800BEF34: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_800BEEEC;
    }
    // 0x800BEF34: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800BEF38: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BEF3C: addiu       $t2, $t2, 0x490
    ctx->r10 = ADD32(ctx->r10, 0X490);
    // 0x800BEF40: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x800BEF44: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800BEF48: beq         $t3, $at, L_800BF048
    if (ctx->r11 == ctx->r1) {
        // 0x800BEF4C: nop

            goto L_800BF048;
    }
    // 0x800BEF4C: nop

    // 0x800BEF50: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BEF54:
    // 0x800BEF54: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BEF58: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BEF5C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BEF60: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800BEF64: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BEF68: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800BEF6C: lw          $t9, 0x434($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X434);
    // 0x800BEF70: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BEF74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEF78: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BEF7C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BEF80: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800BEF84: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
    // 0x800BEF88: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BEF8C: nop

    // 0x800BEF90: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BEF94: sltiu       $at, $t2, 0xC
    ctx->r1 = ctx->r10 < 0XC ? 1 : 0;
    // 0x800BEF98: bne         $at, $zero, L_800BEF54
    if (ctx->r1 != 0) {
        // 0x800BEF9C: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800BEF54;
    }
    // 0x800BEF9C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800BEFA0: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BEFA4: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BEFA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEFAC: sw          $t3, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r11;
    // 0x800BEFB0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BEFB4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BEFB8: lw          $t5, 0x498($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X498);
    // 0x800BEFBC: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BEFC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEFC4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800BEFC8: sw          $t6, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r14;
    // 0x800BEFCC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BEFD0: lw          $t7, 0x434($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X434);
    // 0x800BEFD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEFD8: sw          $t7, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r15;
    // 0x800BEFDC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BEFE0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BEFE4: lw          $t9, 0x49C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X49C);
    // 0x800BEFE8: lw          $t8, 0x434($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434);
    // 0x800BEFEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEFF0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BEFF4: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
    // 0x800BEFF8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BEFFC: lw          $t1, 0x434($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X434);
    // 0x800BF000: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF004: sw          $t1, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r9;
    // 0x800BF008: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF00C: lw          $t2, 0x454($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X454);
    // 0x800BF010: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF014: sw          $t2, 0x46C($at)
    MEM_W(0X46C, ctx->r1) = ctx->r10;
    // 0x800BF018: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF01C: lw          $t3, 0x43C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X43C);
    // 0x800BF020: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF024: sw          $t3, 0x45C($at)
    MEM_W(0X45C, ctx->r1) = ctx->r11;
    // 0x800BF028: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF02C: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BF030: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF034: sw          $t4, 0x460($at)
    MEM_W(0X460, ctx->r1) = ctx->r12;
    // 0x800BF038: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF03C: lw          $t5, 0x44C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X44C);
    // 0x800BF040: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF044: sw          $t5, 0x464($at)
    MEM_W(0X464, ctx->r1) = ctx->r13;
L_800BF048:
    // 0x800BF048: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BF04C: lw          $t6, 0x494($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X494);
    // 0x800BF050: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800BF054: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800BF058: sltu        $at, $t6, $at
    ctx->r1 = ctx->r14 < ctx->r1 ? 1 : 0;
    // 0x800BF05C: beq         $at, $zero, L_800BF088
    if (ctx->r1 == 0) {
        // 0x800BF060: nop

            goto L_800BF088;
    }
    // 0x800BF060: nop

    // 0x800BF064: jal         0x800BFB60
    // 0x800BF068: nop

    Spi_Decompress(rdram, ctx);
        goto after_2;
    // 0x800BF068: nop

    after_2:
    // 0x800BF06C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF070: jal         0x800BC980
    // 0x800BF074: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800BF074: nop

    after_3:
    // 0x800BF078: b           L_800BF0A4
    // 0x800BF07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF0A4;
    // 0x800BF07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF080: b           L_800BF09C
    // 0x800BF084: nop

        goto L_800BF09C;
    // 0x800BF084: nop

L_800BF088:
    // 0x800BF088: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF08C: jal         0x800BC980
    // 0x800BF090: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x800BF090: nop

    after_4:
    // 0x800BF094: b           L_800BF0A4
    // 0x800BF098: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BF0A4;
    // 0x800BF098: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BF09C:
    // 0x800BF09C: b           L_800BF0A4
    // 0x800BF0A0: nop

        goto L_800BF0A4;
    // 0x800BF0A0: nop

L_800BF0A4:
    // 0x800BF0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF0A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BF0AC: jr          $ra
    // 0x800BF0B0: nop

    return;
    // 0x800BF0B0: nop

;}
RECOMP_FUNC void Spi_DecompressAsset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF0B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BF0B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF0BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BF0C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BF0C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BF0C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF0CC: jal         0x800BC6EC
    // 0x800BF0D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800BF0D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x800BF0D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BF0D8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF0DC: nop

    // 0x800BF0E0: bne         $t6, $zero, L_800BF0F0
    if (ctx->r14 != 0) {
        // 0x800BF0E4: nop

            goto L_800BF0F0;
    }
    // 0x800BF0E4: nop

    // 0x800BF0E8: b           L_800BF2D8
    // 0x800BF0EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BF2D8;
    // 0x800BF0EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BF0F0:
    // 0x800BF0F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF0F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800BF0F8: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x800BF0FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF100: bgez        $a2, L_800BF110
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BF104: sra         $t7, $a2, 3
        ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
            goto L_800BF110;
    }
    // 0x800BF104: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800BF108: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x800BF10C: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800BF110:
    // 0x800BF110: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800BF114: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800BF118: jal         0x800BD218
    // 0x800BF11C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800BF11C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_1:
    // 0x800BF120: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF124: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF128: sw          $t9, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r25;
    // 0x800BF12C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BF130: lw          $t0, 0x434($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X434);
    // 0x800BF134: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF138: sw          $t0, 0x458($at)
    MEM_W(0X458, ctx->r1) = ctx->r8;
    // 0x800BF13C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BF140: addiu       $t1, $t1, 0x490
    ctx->r9 = ADD32(ctx->r9, 0X490);
    // 0x800BF144: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800BF148: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800BF14C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF150: sw          $t2, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r10;
    // 0x800BF154: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BF158:
    // 0x800BF158: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF15C: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BF160: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BF164: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800BF168: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF16C: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x800BF170: lw          $t8, 0x434($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434);
    // 0x800BF174: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BF178: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF17C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BF180: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BF184: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800BF188: sw          $t9, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r25;
    // 0x800BF18C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BF190: nop

    // 0x800BF194: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BF198: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x800BF19C: bne         $at, $zero, L_800BF158
    if (ctx->r1 != 0) {
        // 0x800BF1A0: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_800BF158;
    }
    // 0x800BF1A0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800BF1A4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF1A8: addiu       $t2, $t2, 0x490
    ctx->r10 = ADD32(ctx->r10, 0X490);
    // 0x800BF1AC: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x800BF1B0: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800BF1B4: beq         $t3, $at, L_800BF2B4
    if (ctx->r11 == ctx->r1) {
        // 0x800BF1B8: nop

            goto L_800BF2B4;
    }
    // 0x800BF1B8: nop

    // 0x800BF1BC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BF1C0:
    // 0x800BF1C0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF1C4: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BF1C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BF1CC: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800BF1D0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF1D4: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800BF1D8: lw          $t9, 0x434($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X434);
    // 0x800BF1DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BF1E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF1E4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BF1E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BF1EC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800BF1F0: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
    // 0x800BF1F4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BF1F8: nop

    // 0x800BF1FC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BF200: sltiu       $at, $t2, 0xC
    ctx->r1 = ctx->r10 < 0XC ? 1 : 0;
    // 0x800BF204: bne         $at, $zero, L_800BF1C0
    if (ctx->r1 != 0) {
        // 0x800BF208: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800BF1C0;
    }
    // 0x800BF208: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800BF20C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF210: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BF214: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF218: sw          $t3, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r11;
    // 0x800BF21C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF220: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF224: lw          $t5, 0x498($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X498);
    // 0x800BF228: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BF22C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF230: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800BF234: sw          $t6, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r14;
    // 0x800BF238: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF23C: lw          $t7, 0x434($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X434);
    // 0x800BF240: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF244: sw          $t7, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r15;
    // 0x800BF248: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF24C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF250: lw          $t9, 0x49C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X49C);
    // 0x800BF254: lw          $t8, 0x434($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434);
    // 0x800BF258: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF25C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BF260: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
    // 0x800BF264: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BF268: lw          $t1, 0x434($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X434);
    // 0x800BF26C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF270: sw          $t1, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r9;
    // 0x800BF274: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF278: lw          $t2, 0x454($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X454);
    // 0x800BF27C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF280: sw          $t2, 0x46C($at)
    MEM_W(0X46C, ctx->r1) = ctx->r10;
    // 0x800BF284: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF288: lw          $t3, 0x43C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X43C);
    // 0x800BF28C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF290: sw          $t3, 0x45C($at)
    MEM_W(0X45C, ctx->r1) = ctx->r11;
    // 0x800BF294: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF298: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BF29C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF2A0: sw          $t4, 0x460($at)
    MEM_W(0X460, ctx->r1) = ctx->r12;
    // 0x800BF2A4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF2A8: lw          $t5, 0x44C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X44C);
    // 0x800BF2AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF2B0: sw          $t5, 0x464($at)
    MEM_W(0X464, ctx->r1) = ctx->r13;
L_800BF2B4:
    // 0x800BF2B4: jal         0x800BFB60
    // 0x800BF2B8: nop

    Spi_Decompress(rdram, ctx);
        goto after_2;
    // 0x800BF2B8: nop

    after_2:
    // 0x800BF2BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF2C0: jal         0x800BC980
    // 0x800BF2C4: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800BF2C4: nop

    after_3:
    // 0x800BF2C8: b           L_800BF2D8
    // 0x800BF2CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF2D8;
    // 0x800BF2CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF2D0: b           L_800BF2D8
    // 0x800BF2D4: nop

        goto L_800BF2D8;
    // 0x800BF2D4: nop

L_800BF2D8:
    // 0x800BF2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF2DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BF2E0: jr          $ra
    // 0x800BF2E4: nop

    return;
    // 0x800BF2E4: nop

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
RECOMP_FUNC void Spi_Compress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF6C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BF6CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF6D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BF6D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BF6D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF6DC: sw          $zero, 0x474($at)
    MEM_W(0X474, ctx->r1) = 0;
    // 0x800BF6E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF6E4: sw          $zero, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = 0;
    // 0x800BF6E8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800BF6EC: nop

    // 0x800BF6F0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800BF6F4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800BF6F8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800BF6FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF700: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
    // 0x800BF704: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BF708:
    // 0x800BF708: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF70C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF710: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BF714: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BF718: sw          $t7, 0x228($at)
    MEM_W(0X228, ctx->r1) = ctx->r15;
    // 0x800BF71C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF720: nop

    // 0x800BF724: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BF728: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800BF72C: bne         $at, $zero, L_800BF708
    if (ctx->r1 != 0) {
        // 0x800BF730: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800BF708;
    }
    // 0x800BF730: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BF734: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800BF738: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF73C: sw          $t1, 0x42C($at)
    MEM_W(0X42C, ctx->r1) = ctx->r9;
    // 0x800BF740: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BF744: nop

    // 0x800BF748: blez        $t2, L_800BFB38
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BF74C: nop

            goto L_800BFB38;
    }
    // 0x800BF74C: nop

L_800BF750:
    // 0x800BF750: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF754: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF758: lw          $t4, 0x458($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X458);
    // 0x800BF75C: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BF760: nop

    // 0x800BF764: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800BF768: slti        $at, $t5, 0x1001
    ctx->r1 = SIGNED(ctx->r13) < 0X1001 ? 1 : 0;
    // 0x800BF76C: bne         $at, $zero, L_800BF780
    if (ctx->r1 != 0) {
        // 0x800BF770: nop

            goto L_800BF780;
    }
    // 0x800BF770: nop

    // 0x800BF774: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x800BF778: b           L_800BF79C
    // 0x800BF77C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_800BF79C;
    // 0x800BF77C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_800BF780:
    // 0x800BF780: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF784: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF788: lw          $t8, 0x458($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X458);
    // 0x800BF78C: lw          $t7, 0x434($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X434);
    // 0x800BF790: nop

    // 0x800BF794: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800BF798: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800BF79C:
    // 0x800BF79C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7A0: nop

    // 0x800BF7A4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800BF7A8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7AC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800BF7B0: blez        $t1, L_800BF81C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800BF7B4: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_800BF81C;
    }
    // 0x800BF7B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BF7B8:
    // 0x800BF7B8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF7BC: lw          $t2, 0x434($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X434);
    // 0x800BF7C0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7C4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800BF7C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800BF7CC: jal         0x800C00A4
    // 0x800BF7D0: subu        $a1, $t2, $t3
    ctx->r5 = SUB32(ctx->r10, ctx->r11);
    func_800C00A4(rdram, ctx);
        goto after_0;
    // 0x800BF7D0: subu        $a1, $t2, $t3
    ctx->r5 = SUB32(ctx->r10, ctx->r11);
    after_0:
    // 0x800BF7D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BF7D8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF7DC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BF7E0: nop

    // 0x800BF7E4: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BF7E8: beq         $at, $zero, L_800BF808
    if (ctx->r1 == 0) {
        // 0x800BF7EC: nop

            goto L_800BF808;
    }
    // 0x800BF7EC: nop

    // 0x800BF7F0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7F4: nop

    // 0x800BF7F8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800BF7FC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF800: nop

    // 0x800BF804: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800BF808:
    // 0x800BF808: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BF80C: nop

    // 0x800BF810: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800BF814: bgtz        $t9, L_800BF7B8
    if (SIGNED(ctx->r25) > 0) {
        // 0x800BF818: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_800BF7B8;
    }
    // 0x800BF818: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800BF81C:
    // 0x800BF81C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800BF820: nop

    // 0x800BF824: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800BF828: beq         $at, $zero, L_800BF94C
    if (ctx->r1 == 0) {
        // 0x800BF82C: nop

            goto L_800BF94C;
    }
    // 0x800BF82C: nop

    // 0x800BF830: jal         0x800C0278
    // 0x800BF834: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C0278(rdram, ctx);
        goto after_1;
    // 0x800BF834: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800BF838: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800BF83C: nop

    // 0x800BF840: bne         $t1, $zero, L_800BF8F8
    if (ctx->r9 != 0) {
        // 0x800BF844: nop

            goto L_800BF8F8;
    }
    // 0x800BF844: nop

    // 0x800BF848: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF84C: lw          $t2, 0x434($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X434);
    // 0x800BF850: nop

    // 0x800BF854: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x800BF858: nop

    // 0x800BF85C: andi        $t3, $a0, 0xFF
    ctx->r11 = ctx->r4 & 0XFF;
    // 0x800BF860: jal         0x800C0444
    // 0x800BF864: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800C0444(rdram, ctx);
        goto after_2;
    // 0x800BF864: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_2:
    // 0x800BF868: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BF86C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF870: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BF874: bne         $t4, $at, L_800BF8C8
    if (ctx->r12 != ctx->r1) {
        // 0x800BF878: nop

            goto L_800BF8C8;
    }
    // 0x800BF878: nop

    // 0x800BF87C: jal         0x800C0278
    // 0x800BF880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C0278(rdram, ctx);
        goto after_3;
    // 0x800BF880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800BF884: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF888: lw          $t5, 0x434($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X434);
    // 0x800BF88C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF890: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BF894: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800BF898: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF89C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800BF8A0: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BF8A4: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BF8A8: lw          $t0, 0x434($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X434);
    // 0x800BF8AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF8B0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BF8B4: sw          $t9, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r25;
    // 0x800BF8B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF8BC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BF8C0: b           L_800BF8F0
    // 0x800BF8C4: sw          $t1, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r9;
        goto L_800BF8F0;
    // 0x800BF8C4: sw          $t1, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r9;
L_800BF8C8:
    // 0x800BF8C8: jal         0x800C0278
    // 0x800BF8CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C0278(rdram, ctx);
        goto after_4;
    // 0x800BF8CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800BF8D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF8D4: jal         0x800C0108
    // 0x800BF8D8: nop

    func_800C0108(rdram, ctx);
        goto after_5;
    // 0x800BF8D8: nop

    after_5:
    // 0x800BF8DC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF8E0: lw          $t2, 0x434($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X434);
    // 0x800BF8E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF8E8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BF8EC: sw          $t3, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r11;
L_800BF8F0:
    // 0x800BF8F0: b           L_800BF938
    // 0x800BF8F4: nop

        goto L_800BF938;
    // 0x800BF8F4: nop

L_800BF8F8:
    // 0x800BF8F8: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF8FC: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BF900: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BF904: lw          $t6, 0x444($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X444);
    // 0x800BF908: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800BF90C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF910: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800BF914: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BF918: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF91C: lw          $t9, 0x434($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X434);
    // 0x800BF920: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF924: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BF928: sw          $t8, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r24;
    // 0x800BF92C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF930: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BF934: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
L_800BF938:
    // 0x800BF938: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BF93C: nop

    // 0x800BF940: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800BF944: b           L_800BFB28
    // 0x800BF948: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
        goto L_800BFB28;
    // 0x800BF948: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_800BF94C:
    // 0x800BF94C: jal         0x800C0278
    // 0x800BF950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C0278(rdram, ctx);
        goto after_6;
    // 0x800BF950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800BF954: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF958: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BF95C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800BF960: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF964: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BF968: sw          $t5, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r13;
    // 0x800BF96C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BF970: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BF974: nop

    // 0x800BF978: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800BF97C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800BF980: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800BF984: nop

    // 0x800BF988: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800BF98C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800BF990: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800BF994: nop

    // 0x800BF998: addiu       $t2, $t1, -0x3
    ctx->r10 = ADD32(ctx->r9, -0X3);
    // 0x800BF99C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800BF9A0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800BF9A4: nop

    // 0x800BF9A8: slti        $at, $t3, 0xF
    ctx->r1 = SIGNED(ctx->r11) < 0XF ? 1 : 0;
    // 0x800BF9AC: bne         $at, $zero, L_800BFAB4
    if (ctx->r1 != 0) {
        // 0x800BF9B0: nop

            goto L_800BFAB4;
    }
    // 0x800BF9B0: nop

    // 0x800BF9B4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800BF9B8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF9BC: bgez        $t4, L_800BF9CC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800BF9C0: sra         $t5, $t4, 8
        ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
            goto L_800BF9CC;
    }
    // 0x800BF9C0: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800BF9C4: addiu       $at, $t4, 0xFF
    ctx->r1 = ADD32(ctx->r12, 0XFF);
    // 0x800BF9C8: sra         $t5, $at, 8
    ctx->r13 = S32(SIGNED(ctx->r1) >> 8);
L_800BF9CC:
    // 0x800BF9CC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800BF9D0: lw          $t9, 0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X444);
    // 0x800BF9D4: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800BF9D8: ori         $t8, $t7, 0xF0
    ctx->r24 = ctx->r15 | 0XF0;
    // 0x800BF9DC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BF9E0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BF9E4: lw          $t0, 0x444($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X444);
    // 0x800BF9E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF9EC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BF9F0: sw          $t1, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r9;
    // 0x800BF9F4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800BF9F8: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF9FC: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BFA00: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800BFA04: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BFA08: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x800BFA0C: lw          $t5, 0x444($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X444);
    // 0x800BFA10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFA14: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800BFA18: sw          $t6, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r14;
    // 0x800BFA1C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BFA20: nop

    // 0x800BFA24: addiu       $t8, $t7, -0xF
    ctx->r24 = ADD32(ctx->r15, -0XF);
    // 0x800BFA28: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_800BFA2C:
    // 0x800BFA2C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800BFA30: nop

    // 0x800BFA34: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x800BFA38: bne         $at, $zero, L_800BFA78
    if (ctx->r1 != 0) {
        // 0x800BFA3C: nop

            goto L_800BFA78;
    }
    // 0x800BFA3C: nop

    // 0x800BFA40: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFA44: lw          $t1, 0x444($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X444);
    // 0x800BFA48: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800BFA4C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BFA50: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800BFA54: lw          $t2, 0x444($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X444);
    // 0x800BFA58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFA5C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BFA60: sw          $t3, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r11;
    // 0x800BFA64: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800BFA68: nop

    // 0x800BFA6C: addiu       $t5, $t4, -0xFF
    ctx->r13 = ADD32(ctx->r12, -0XFF);
    // 0x800BFA70: b           L_800BFAA4
    // 0x800BFA74: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
        goto L_800BFAA4;
    // 0x800BFA74: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
L_800BFA78:
    // 0x800BFA78: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFA7C: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BFA80: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BFA84: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFA88: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800BFA8C: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFA90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFA94: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BFA98: sw          $t9, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r25;
    // 0x800BFA9C: b           L_800BFAAC
    // 0x800BFAA0: nop

        goto L_800BFAAC;
    // 0x800BFAA0: nop

L_800BFAA4:
    // 0x800BFAA4: b           L_800BFA2C
    // 0x800BFAA8: nop

        goto L_800BFA2C;
    // 0x800BFAA8: nop

L_800BFAAC:
    // 0x800BFAAC: b           L_800BFB28
    // 0x800BFAB0: nop

        goto L_800BFB28;
    // 0x800BFAB0: nop

L_800BFAB4:
    // 0x800BFAB4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800BFAB8: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x800BFABC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFAC0: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x800BFAC4: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFAC8: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800BFACC: bgez        $t3, L_800BFADC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BFAD0: sra         $t4, $t3, 8
        ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
            goto L_800BFADC;
    }
    // 0x800BFAD0: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800BFAD4: addiu       $at, $t3, 0xFF
    ctx->r1 = ADD32(ctx->r11, 0XFF);
    // 0x800BFAD8: sra         $t4, $at, 8
    ctx->r12 = S32(SIGNED(ctx->r1) >> 8);
L_800BFADC:
    // 0x800BFADC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800BFAE0: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x800BFAE4: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x800BFAE8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFAEC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800BFAF0: lw          $t9, 0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X444);
    // 0x800BFAF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFAF8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BFAFC: sw          $t0, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r8;
    // 0x800BFB00: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800BFB04: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFB08: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BFB0C: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x800BFB10: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BFB14: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x800BFB18: lw          $t5, 0x444($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X444);
    // 0x800BFB1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFB20: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800BFB24: sw          $t2, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r10;
L_800BFB28:
    // 0x800BFB28: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BFB2C: nop

    // 0x800BFB30: bgtz        $t6, L_800BF750
    if (SIGNED(ctx->r14) > 0) {
        // 0x800BFB34: nop

            goto L_800BF750;
    }
    // 0x800BFB34: nop

L_800BFB38:
    // 0x800BFB38: jal         0x800C03C8
    // 0x800BFB3C: nop

    func_800C03C8(rdram, ctx);
        goto after_7;
    // 0x800BFB3C: nop

    after_7:
    // 0x800BFB40: jal         0x800C0194
    // 0x800BFB44: nop

    func_800C0194(rdram, ctx);
        goto after_8;
    // 0x800BFB44: nop

    after_8:
    // 0x800BFB48: b           L_800BFB50
    // 0x800BFB4C: nop

        goto L_800BFB50;
    // 0x800BFB4C: nop

L_800BFB50:
    // 0x800BFB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFB54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BFB58: jr          $ra
    // 0x800BFB5C: nop

    return;
    // 0x800BFB5C: nop

;}
RECOMP_FUNC void Spi_Decompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFB60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BFB64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BFB68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BFB6C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFB70: sw          $zero, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = 0;
    // 0x800BFB74: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800BFB78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800BFB7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFB80: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
    // 0x800BFB84: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BFB88:
    // 0x800BFB88: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BFB8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFB90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BFB94: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BFB98: sw          $t6, 0x228($at)
    MEM_W(0X228, ctx->r1) = ctx->r14;
    // 0x800BFB9C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BFBA0: nop

    // 0x800BFBA4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BFBA8: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800BFBAC: bne         $at, $zero, L_800BFB88
    if (ctx->r1 != 0) {
        // 0x800BFBB0: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_800BFB88;
    }
    // 0x800BFBB0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800BFBB4: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800BFBB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFBBC: sw          $t0, 0x42C($at)
    MEM_W(0X42C, ctx->r1) = ctx->r8;
    // 0x800BFBC0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFBC4: addiu       $t1, $t1, 0x490
    ctx->r9 = ADD32(ctx->r9, 0X490);
    // 0x800BFBC8: lbu         $t2, 0x3($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X3);
    // 0x800BFBCC: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800BFBD0: bne         $t2, $at, L_800BFDE0
    if (ctx->r10 != ctx->r1) {
        // 0x800BFBD4: nop

            goto L_800BFDE0;
    }
    // 0x800BFBD4: nop

    // 0x800BFBD8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BFBDC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFBE0: lw          $t4, 0x46C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X46C);
    // 0x800BFBE4: lw          $t3, 0x454($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X454);
    // 0x800BFBE8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFBEC: lw          $t6, 0x494($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X494);
    // 0x800BFBF0: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800BFBF4: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x800BFBF8: beq         $at, $zero, L_800BFDD8
    if (ctx->r1 == 0) {
        // 0x800BFBFC: nop

            goto L_800BFDD8;
    }
    // 0x800BFBFC: nop

L_800BFC00:
    // 0x800BFC00: jal         0x800C0328
    // 0x800BFC04: nop

    func_800C0328(rdram, ctx);
        goto after_0;
    // 0x800BFC04: nop

    after_0:
    // 0x800BFC08: beq         $v0, $zero, L_800BFC54
    if (ctx->r2 == 0) {
        // 0x800BFC0C: nop

            goto L_800BFC54;
    }
    // 0x800BFC0C: nop

    // 0x800BFC10: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFC14: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BFC18: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFC1C: lw          $t9, 0x454($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X454);
    // 0x800BFC20: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800BFC24: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BFC28: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BFC2C: lw          $t0, 0x454($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X454);
    // 0x800BFC30: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BFC34: lw          $t2, 0x444($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X444);
    // 0x800BFC38: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFC3C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BFC40: sw          $t1, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r9;
    // 0x800BFC44: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFC48: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BFC4C: b           L_800BFDB0
    // 0x800BFC50: sw          $t3, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r11;
        goto L_800BFDB0;
    // 0x800BFC50: sw          $t3, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r11;
L_800BFC54:
    // 0x800BFC54: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFC58: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BFC5C: nop

    // 0x800BFC60: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800BFC64: nop

    // 0x800BFC68: bgez        $t5, L_800BFC78
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800BFC6C: sra         $t6, $t5, 4
        ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
            goto L_800BFC78;
    }
    // 0x800BFC6C: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800BFC70: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x800BFC74: sra         $t6, $at, 4
    ctx->r14 = S32(SIGNED(ctx->r1) >> 4);
L_800BFC78:
    // 0x800BFC78: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800BFC7C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800BFC80: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFC84: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFC88: nop

    // 0x800BFC8C: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x800BFC90: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x800BFC94: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800BFC98: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800BFC9C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800BFCA0: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800BFCA4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800BFCA8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800BFCAC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFCB0: lw          $t6, 0x444($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X444);
    // 0x800BFCB4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFCB8: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800BFCBC: sw          $t7, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r15;
    // 0x800BFCC0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BFCC4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800BFCC8: bne         $t9, $at, L_800BFD4C
    if (ctx->r25 != ctx->r1) {
        // 0x800BFCCC: nop

            goto L_800BFD4C;
    }
    // 0x800BFCCC: nop

L_800BFCD0:
    // 0x800BFCD0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFCD4: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFCD8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800BFCDC: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x800BFCE0: nop

    // 0x800BFCE4: bne         $t1, $at, L_800BFD14
    if (ctx->r9 != ctx->r1) {
        // 0x800BFCE8: nop

            goto L_800BFD14;
    }
    // 0x800BFCE8: nop

    // 0x800BFCEC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BFCF0: nop

    // 0x800BFCF4: addiu       $t0, $t2, 0xFF
    ctx->r8 = ADD32(ctx->r10, 0XFF);
    // 0x800BFCF8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800BFCFC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BFD00: lw          $t3, 0x444($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X444);
    // 0x800BFD04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFD08: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800BFD0C: b           L_800BFD44
    // 0x800BFD10: sw          $t4, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r12;
        goto L_800BFD44;
    // 0x800BFD10: sw          $t4, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r12;
L_800BFD14:
    // 0x800BFD14: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFD18: lw          $t6, 0x444($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X444);
    // 0x800BFD1C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BFD20: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BFD24: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFD28: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800BFD2C: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x800BFD30: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x800BFD34: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800BFD38: sw          $t1, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r9;
    // 0x800BFD3C: b           L_800BFD4C
    // 0x800BFD40: nop

        goto L_800BFD4C;
    // 0x800BFD40: nop

L_800BFD44:
    // 0x800BFD44: b           L_800BFCD0
    // 0x800BFD48: nop

        goto L_800BFCD0;
    // 0x800BFD48: nop

L_800BFD4C:
    // 0x800BFD4C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BFD50: nop

    // 0x800BFD54: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x800BFD58: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800BFD5C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800BFD60: nop

    // 0x800BFD64: blez        $t3, L_800BFDB0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BFD68: nop

            goto L_800BFDB0;
    }
    // 0x800BFD68: nop

L_800BFD6C:
    // 0x800BFD6C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFD70: lw          $t4, 0x454($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X454);
    // 0x800BFD74: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800BFD78: nop

    // 0x800BFD7C: subu        $t5, $t4, $t7
    ctx->r13 = SUB32(ctx->r12, ctx->r15);
    // 0x800BFD80: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x800BFD84: nop

    // 0x800BFD88: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    // 0x800BFD8C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFD90: lw          $t1, 0x454($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X454);
    // 0x800BFD94: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BFD98: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFD9C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BFDA0: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800BFDA4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800BFDA8: bgtz        $t6, L_800BFD6C
    if (SIGNED(ctx->r14) > 0) {
        // 0x800BFDAC: sw          $t2, 0x454($at)
        MEM_W(0X454, ctx->r1) = ctx->r10;
            goto L_800BFD6C;
    }
    // 0x800BFDAC: sw          $t2, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r10;
L_800BFDB0:
    // 0x800BFDB0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BFDB4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BFDB8: lw          $t3, 0x46C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X46C);
    // 0x800BFDBC: lw          $t0, 0x454($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X454);
    // 0x800BFDC0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BFDC4: lw          $t5, 0x494($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X494);
    // 0x800BFDC8: subu        $t7, $t0, $t3
    ctx->r15 = SUB32(ctx->r8, ctx->r11);
    // 0x800BFDCC: sltu        $at, $t7, $t5
    ctx->r1 = ctx->r15 < ctx->r13 ? 1 : 0;
    // 0x800BFDD0: bne         $at, $zero, L_800BFC00
    if (ctx->r1 != 0) {
        // 0x800BFDD4: nop

            goto L_800BFC00;
    }
    // 0x800BFDD4: nop

L_800BFDD8:
    // 0x800BFDD8: b           L_800C008C
    // 0x800BFDDC: nop

        goto L_800C008C;
    // 0x800BFDDC: nop

L_800BFDE0:
    // 0x800BFDE0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFDE4: addiu       $t9, $t9, 0x490
    ctx->r25 = ADD32(ctx->r25, 0X490);
    // 0x800BFDE8: lbu         $t4, 0x3($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X3);
    // 0x800BFDEC: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x800BFDF0: bne         $t4, $at, L_800C006C
    if (ctx->r12 != ctx->r1) {
        // 0x800BFDF4: nop

            goto L_800C006C;
    }
    // 0x800BFDF4: nop

    // 0x800BFDF8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFDFC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFE00: lw          $t1, 0x46C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X46C);
    // 0x800BFE04: lw          $t8, 0x454($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X454);
    // 0x800BFE08: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFE0C: lw          $t6, 0x494($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X494);
    // 0x800BFE10: subu        $t2, $t8, $t1
    ctx->r10 = SUB32(ctx->r24, ctx->r9);
    // 0x800BFE14: sltu        $at, $t2, $t6
    ctx->r1 = ctx->r10 < ctx->r14 ? 1 : 0;
    // 0x800BFE18: beq         $at, $zero, L_800C0064
    if (ctx->r1 == 0) {
        // 0x800BFE1C: nop

            goto L_800C0064;
    }
    // 0x800BFE1C: nop

L_800BFE20:
    // 0x800BFE20: jal         0x800C0328
    // 0x800BFE24: nop

    func_800C0328(rdram, ctx);
        goto after_1;
    // 0x800BFE24: nop

    after_1:
    // 0x800BFE28: beq         $v0, $zero, L_800BFEE0
    if (ctx->r2 == 0) {
        // 0x800BFE2C: nop

            goto L_800BFEE0;
    }
    // 0x800BFE2C: nop

    // 0x800BFE30: jal         0x800C0328
    // 0x800BFE34: nop

    func_800C0328(rdram, ctx);
        goto after_2;
    // 0x800BFE34: nop

    after_2:
    // 0x800BFE38: beq         $v0, $zero, L_800BFEA4
    if (ctx->r2 == 0) {
        // 0x800BFE3C: nop

            goto L_800BFEA4;
    }
    // 0x800BFE3C: nop

    // 0x800BFE40: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BFE44: lw          $t0, 0x444($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X444);
    // 0x800BFE48: nop

    // 0x800BFE4C: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x800BFE50: nop

    // 0x800BFE54: andi        $t3, $a0, 0xFF
    ctx->r11 = ctx->r4 & 0XFF;
    // 0x800BFE58: jal         0x800C055C
    // 0x800BFE5C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800C055C(rdram, ctx);
        goto after_3;
    // 0x800BFE5C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_3:
    // 0x800BFE60: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFE64: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BFE68: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFE6C: lw          $t9, 0x454($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X454);
    // 0x800BFE70: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x800BFE74: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFE78: sb          $t5, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r13;
    // 0x800BFE7C: lw          $t4, 0x454($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X454);
    // 0x800BFE80: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFE84: lw          $t1, 0x444($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X444);
    // 0x800BFE88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFE8C: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x800BFE90: sw          $t8, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r24;
    // 0x800BFE94: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFE98: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BFE9C: b           L_800BFED8
    // 0x800BFEA0: sw          $t2, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r10;
        goto L_800BFED8;
    // 0x800BFEA0: sw          $t2, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r10;
L_800BFEA4:
    // 0x800BFEA4: jal         0x800C01D4
    // 0x800BFEA8: nop

    func_800C01D4(rdram, ctx);
        goto after_4;
    // 0x800BFEA8: nop

    after_4:
    // 0x800BFEAC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800BFEB0: jal         0x800C0534
    // 0x800BFEB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C0534(rdram, ctx);
        goto after_5;
    // 0x800BFEB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800BFEB8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFEBC: lw          $t6, 0x454($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X454);
    // 0x800BFEC0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BFEC4: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x800BFEC8: lw          $t0, 0x454($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X454);
    // 0x800BFECC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFED0: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x800BFED4: sw          $t3, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r11;
L_800BFED8:
    // 0x800BFED8: b           L_800C003C
    // 0x800BFEDC: nop

        goto L_800C003C;
    // 0x800BFEDC: nop

L_800BFEE0:
    // 0x800BFEE0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFEE4: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BFEE8: nop

    // 0x800BFEEC: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x800BFEF0: nop

    // 0x800BFEF4: bgez        $t5, L_800BFF04
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800BFEF8: sra         $t9, $t5, 4
        ctx->r25 = S32(SIGNED(ctx->r13) >> 4);
            goto L_800BFF04;
    }
    // 0x800BFEF8: sra         $t9, $t5, 4
    ctx->r25 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800BFEFC: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x800BFF00: sra         $t9, $at, 4
    ctx->r25 = S32(SIGNED(ctx->r1) >> 4);
L_800BFF04:
    // 0x800BFF04: andi        $t4, $t9, 0xF
    ctx->r12 = ctx->r25 & 0XF;
    // 0x800BFF08: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800BFF0C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFF10: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFF14: nop

    // 0x800BFF18: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x800BFF1C: lbu         $t1, 0x1($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X1);
    // 0x800BFF20: andi        $t0, $t6, 0xF
    ctx->r8 = ctx->r14 & 0XF;
    // 0x800BFF24: sll         $t3, $t0, 8
    ctx->r11 = S32(ctx->r8 << 8);
    // 0x800BFF28: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800BFF2C: addu        $t7, $t2, $t3
    ctx->r15 = ADD32(ctx->r10, ctx->r11);
    // 0x800BFF30: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x800BFF34: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800BFF38: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFF3C: lw          $t9, 0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X444);
    // 0x800BFF40: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFF44: addiu       $t4, $t9, 0x2
    ctx->r12 = ADD32(ctx->r25, 0X2);
    // 0x800BFF48: sw          $t4, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r12;
    // 0x800BFF4C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BFF50: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800BFF54: bne         $t1, $at, L_800BFFD8
    if (ctx->r9 != ctx->r1) {
        // 0x800BFF58: nop

            goto L_800BFFD8;
    }
    // 0x800BFF58: nop

L_800BFF5C:
    // 0x800BFF5C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFF60: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFF64: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800BFF68: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x800BFF6C: nop

    // 0x800BFF70: bne         $t6, $at, L_800BFFA0
    if (ctx->r14 != ctx->r1) {
        // 0x800BFF74: nop

            goto L_800BFFA0;
    }
    // 0x800BFF74: nop

    // 0x800BFF78: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BFF7C: nop

    // 0x800BFF80: addiu       $t2, $t0, 0xFF
    ctx->r10 = ADD32(ctx->r8, 0XFF);
    // 0x800BFF84: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800BFF88: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BFF8C: lw          $t3, 0x444($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X444);
    // 0x800BFF90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFF94: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x800BFF98: b           L_800BFFD0
    // 0x800BFF9C: sw          $t7, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r15;
        goto L_800BFFD0;
    // 0x800BFF9C: sw          $t7, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r15;
L_800BFFA0:
    // 0x800BFFA0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFFA4: lw          $t9, 0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X444);
    // 0x800BFFA8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BFFAC: lbu         $t4, 0x0($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X0);
    // 0x800BFFB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFFB4: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800BFFB8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BFFBC: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x800BFFC0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800BFFC4: sw          $t6, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r14;
    // 0x800BFFC8: b           L_800BFFD8
    // 0x800BFFCC: nop

        goto L_800BFFD8;
    // 0x800BFFCC: nop

L_800BFFD0:
    // 0x800BFFD0: b           L_800BFF5C
    // 0x800BFFD4: nop

        goto L_800BFF5C;
    // 0x800BFFD4: nop

L_800BFFD8:
    // 0x800BFFD8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BFFDC: nop

    // 0x800BFFE0: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
    // 0x800BFFE4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800BFFE8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800BFFEC: nop

    // 0x800BFFF0: blez        $t3, L_800C003C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BFFF4: nop

            goto L_800C003C;
    }
    // 0x800BFFF4: nop

L_800BFFF8:
    // 0x800BFFF8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFFFC: lw          $t7, 0x454($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X454);
    // 0x800C0000: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C0004: nop

    // 0x800C0008: subu        $t5, $t7, $t4
    ctx->r13 = SUB32(ctx->r15, ctx->r12);
    // 0x800C000C: lbu         $t1, 0x0($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X0);
    // 0x800C0010: nop

    // 0x800C0014: sb          $t1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r9;
    // 0x800C0018: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C001C: lw          $t6, 0x454($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X454);
    // 0x800C0020: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C0024: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0028: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x800C002C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C0030: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800C0034: bgtz        $t9, L_800BFFF8
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C0038: sw          $t0, 0x454($at)
        MEM_W(0X454, ctx->r1) = ctx->r8;
            goto L_800BFFF8;
    }
    // 0x800C0038: sw          $t0, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r8;
L_800C003C:
    // 0x800C003C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800C0040: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800C0044: lw          $t3, 0x46C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X46C);
    // 0x800C0048: lw          $t2, 0x454($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X454);
    // 0x800C004C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800C0050: lw          $t5, 0x494($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X494);
    // 0x800C0054: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800C0058: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x800C005C: bne         $at, $zero, L_800BFE20
    if (ctx->r1 != 0) {
        // 0x800C0060: nop

            goto L_800BFE20;
    }
    // 0x800C0060: nop

L_800C0064:
    // 0x800C0064: b           L_800C008C
    // 0x800C0068: nop

        goto L_800C008C;
    // 0x800C0068: nop

L_800C006C:
    // 0x800C006C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800C0070: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800C0074: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800C0078: lw          $a2, 0x494($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X494);
    // 0x800C007C: lw          $a1, 0x434($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X434);
    // 0x800C0080: lw          $a0, 0x454($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X454);
    // 0x800C0084: jal         0x800BCFCC
    // 0x800C0088: nop

    SysMem_Copy8(rdram, ctx);
        goto after_6;
    // 0x800C0088: nop

    after_6:
L_800C008C:
    // 0x800C008C: b           L_800C0094
    // 0x800C0090: nop

        goto L_800C0094;
    // 0x800C0090: nop

L_800C0094:
    // 0x800C0094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C009C: jr          $ra
    // 0x800C00A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C00A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C00A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C00A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C00A8: blez        $a2, L_800C00EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800C00AC: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_800C00EC;
    }
    // 0x800C00AC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800C00B0:
    // 0x800C00B0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800C00B4: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800C00B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C00BC: xor         $a3, $t6, $t7
    ctx->r7 = ctx->r14 ^ ctx->r15;
    // 0x800C00C0: sltu        $a3, $zero, $a3
    ctx->r7 = 0 < ctx->r7 ? 1 : 0;
    // 0x800C00C4: beq         $a3, $zero, L_800C00D4
    if (ctx->r7 == 0) {
        // 0x800C00C8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800C00D4;
    }
    // 0x800C00C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C00CC: b           L_800C00EC
    // 0x800C00D0: nop

        goto L_800C00EC;
    // 0x800C00D0: nop

L_800C00D4:
    // 0x800C00D4: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800C00D8: nop

    // 0x800C00DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C00E0: slt         $at, $t9, $a2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C00E4: bne         $at, $zero, L_800C00B0
    if (ctx->r1 != 0) {
        // 0x800C00E8: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_800C00B0;
    }
    // 0x800C00E8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_800C00EC:
    // 0x800C00EC: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800C00F0: b           L_800C0100
    // 0x800C00F4: nop

        goto L_800C0100;
    // 0x800C00F4: nop

    // 0x800C00F8: b           L_800C0100
    // 0x800C00FC: nop

        goto L_800C0100;
    // 0x800C00FC: nop

L_800C0100:
    // 0x800C0100: jr          $ra
    // 0x800C0104: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C0104: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C0108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0108: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C010C: lw          $t6, 0x484($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X484);
    // 0x800C0110: nop

    // 0x800C0114: bne         $t6, $zero, L_800C014C
    if (ctx->r14 != 0) {
        // 0x800C0118: nop

            goto L_800C014C;
    }
    // 0x800C0118: nop

    // 0x800C011C: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x800C0120: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800C0124: lw          $t0, 0x43C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X43C);
    // 0x800C0128: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800C012C: andi        $t9, $t8, 0xF0
    ctx->r25 = ctx->r24 & 0XF0;
    // 0x800C0130: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x800C0134: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800C0138: lw          $t1, 0x484($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X484);
    // 0x800C013C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0140: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800C0144: b           L_800C0184
    // 0x800C0148: sw          $t2, 0x484($at)
    MEM_W(0X484, ctx->r1) = ctx->r10;
        goto L_800C0184;
    // 0x800C0148: sw          $t2, 0x484($at)
    MEM_W(0X484, ctx->r1) = ctx->r10;
L_800C014C:
    // 0x800C014C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800C0150: lw          $t3, 0x43C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X43C);
    // 0x800C0154: andi        $t5, $a0, 0xFF
    ctx->r13 = ctx->r4 & 0XFF;
    // 0x800C0158: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800C015C: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x800C0160: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800C0164: sb          $t7, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r15;
    // 0x800C0168: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800C016C: lw          $t8, 0x43C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X43C);
    // 0x800C0170: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0174: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C0178: sw          $t9, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r25;
    // 0x800C017C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0180: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
L_800C0184:
    // 0x800C0184: jr          $ra
    // 0x800C0188: nop

    return;
    // 0x800C0188: nop

    // 0x800C018C: jr          $ra
    // 0x800C0190: nop

    return;
    // 0x800C0190: nop

;}
RECOMP_FUNC void func_800C0194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0194: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C0198: lw          $t6, 0x484($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X484);
    // 0x800C019C: nop

    // 0x800C01A0: beq         $t6, $zero, L_800C01C4
    if (ctx->r14 == 0) {
        // 0x800C01A4: nop

            goto L_800C01C4;
    }
    // 0x800C01A4: nop

    // 0x800C01A8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C01AC: lw          $t7, 0x43C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X43C);
    // 0x800C01B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C01B4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C01B8: sw          $t8, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r24;
    // 0x800C01BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C01C0: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
L_800C01C4:
    // 0x800C01C4: jr          $ra
    // 0x800C01C8: nop

    return;
    // 0x800C01C8: nop

    // 0x800C01CC: jr          $ra
    // 0x800C01D0: nop

    return;
    // 0x800C01D0: nop

;}
RECOMP_FUNC void func_800C01D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C01D4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C01D8: lw          $t6, 0x484($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X484);
    // 0x800C01DC: nop

    // 0x800C01E0: bne         $t6, $zero, L_800C022C
    if (ctx->r14 != 0) {
        // 0x800C01E4: nop

            goto L_800C022C;
    }
    // 0x800C01E4: nop

    // 0x800C01E8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C01EC: lw          $t7, 0x484($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X484);
    // 0x800C01F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C01F4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C01F8: sw          $t8, 0x484($at)
    MEM_W(0X484, ctx->r1) = ctx->r24;
    // 0x800C01FC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800C0200: lw          $t9, 0x43C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X43C);
    // 0x800C0204: nop

    // 0x800C0208: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x800C020C: nop

    // 0x800C0210: sra         $t0, $v0, 4
    ctx->r8 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800C0214: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800C0218: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x800C021C: jr          $ra
    // 0x800C0220: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800C0220: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800C0224: b           L_800C0268
    // 0x800C0228: nop

        goto L_800C0268;
    // 0x800C0228: nop

L_800C022C:
    // 0x800C022C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800C0230: lw          $t2, 0x43C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X43C);
    // 0x800C0234: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0238: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C023C: sw          $t3, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r11;
    // 0x800C0240: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0244: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
    // 0x800C0248: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800C024C: lw          $t4, 0x43C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X43C);
    // 0x800C0250: nop

    // 0x800C0254: lbu         $v0, -0x1($t4)
    ctx->r2 = MEM_BU(ctx->r12, -0X1);
    // 0x800C0258: nop

    // 0x800C025C: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x800C0260: jr          $ra
    // 0x800C0264: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    return;
    // 0x800C0264: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800C0268:
    // 0x800C0268: jr          $ra
    // 0x800C026C: nop

    return;
    // 0x800C026C: nop

    // 0x800C0270: jr          $ra
    // 0x800C0274: nop

    return;
    // 0x800C0274: nop

;}
RECOMP_FUNC void func_800C0278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0278: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C027C: lw          $t6, 0x47C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X47C);
    // 0x800C0280: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800C0284: bne         $t6, $at, L_800C02A8
    if (ctx->r14 != ctx->r1) {
        // 0x800C0288: nop

            goto L_800C02A8;
    }
    // 0x800C0288: nop

    // 0x800C028C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0290: sw          $zero, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = 0;
    // 0x800C0294: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C0298: lw          $t7, 0x44C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X44C);
    // 0x800C029C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C02A0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C02A4: sw          $t8, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r24;
L_800C02A8:
    // 0x800C02A8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800C02AC: lw          $t9, 0x44C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X44C);
    // 0x800C02B0: nop

    // 0x800C02B4: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800C02B8: nop

    // 0x800C02BC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800C02C0: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
    // 0x800C02C4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800C02C8: lw          $t2, 0x44C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X44C);
    // 0x800C02CC: nop

    // 0x800C02D0: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800C02D4: nop

    // 0x800C02D8: andi        $t4, $t3, 0xFE
    ctx->r12 = ctx->r11 & 0XFE;
    // 0x800C02DC: sb          $t4, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r12;
    // 0x800C02E0: beq         $a0, $zero, L_800C0304
    if (ctx->r4 == 0) {
        // 0x800C02E4: nop

            goto L_800C0304;
    }
    // 0x800C02E4: nop

    // 0x800C02E8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800C02EC: lw          $t5, 0x44C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X44C);
    // 0x800C02F0: nop

    // 0x800C02F4: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800C02F8: nop

    // 0x800C02FC: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800C0300: sb          $t7, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r15;
L_800C0304:
    // 0x800C0304: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800C0308: lw          $t8, 0x47C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X47C);
    // 0x800C030C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0310: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800C0314: sw          $t0, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = ctx->r8;
    // 0x800C0318: jr          $ra
    // 0x800C031C: nop

    return;
    // 0x800C031C: nop

    // 0x800C0320: jr          $ra
    // 0x800C0324: nop

    return;
    // 0x800C0324: nop

;}
RECOMP_FUNC void func_800C0328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0328: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C032C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C0330: lw          $t6, 0x47C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X47C);
    // 0x800C0334: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800C0338: bne         $t6, $at, L_800C035C
    if (ctx->r14 != ctx->r1) {
        // 0x800C033C: nop

            goto L_800C035C;
    }
    // 0x800C033C: nop

    // 0x800C0340: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0344: sw          $zero, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = 0;
    // 0x800C0348: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C034C: lw          $t7, 0x44C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X44C);
    // 0x800C0350: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0354: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C0358: sw          $t8, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r24;
L_800C035C:
    // 0x800C035C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800C0360: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800C0364: lw          $t9, 0x44C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X44C);
    // 0x800C0368: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800C036C: lw          $t1, 0x47C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X47C);
    // 0x800C0370: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800C0374: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x800C0378: srav        $t3, $t2, $t1
    ctx->r11 = S32(SIGNED(ctx->r10) >> (ctx->r9 & 31));
    // 0x800C037C: and         $t4, $t0, $t3
    ctx->r12 = ctx->r8 & ctx->r11;
    // 0x800C0380: beq         $t4, $zero, L_800C0398
    if (ctx->r12 == 0) {
        // 0x800C0384: nop

            goto L_800C0398;
    }
    // 0x800C0384: nop

    // 0x800C0388: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800C038C: nop

    // 0x800C0390: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800C0394: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_800C0398:
    // 0x800C0398: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C039C: lw          $t7, 0x47C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X47C);
    // 0x800C03A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C03A4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C03A8: sw          $t8, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = ctx->r24;
    // 0x800C03AC: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800C03B0: b           L_800C03C0
    // 0x800C03B4: nop

        goto L_800C03C0;
    // 0x800C03B4: nop

    // 0x800C03B8: b           L_800C03C0
    // 0x800C03BC: nop

        goto L_800C03C0;
    // 0x800C03BC: nop

L_800C03C0:
    // 0x800C03C0: jr          $ra
    // 0x800C03C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C03C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C03C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C03C8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C03CC: lw          $t6, 0x47C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X47C);
    // 0x800C03D0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800C03D4: beq         $t6, $at, L_800C0420
    if (ctx->r14 == ctx->r1) {
        // 0x800C03D8: nop

            goto L_800C0420;
    }
    // 0x800C03D8: nop

L_800C03DC:
    // 0x800C03DC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C03E0: lw          $t7, 0x44C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X44C);
    // 0x800C03E4: nop

    // 0x800C03E8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C03EC: nop

    // 0x800C03F0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C03F4: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800C03F8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800C03FC: lw          $t0, 0x47C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X47C);
    // 0x800C0400: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0404: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C0408: sw          $t1, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = ctx->r9;
    // 0x800C040C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800C0410: lw          $t2, 0x47C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X47C);
    // 0x800C0414: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800C0418: bne         $t2, $at, L_800C03DC
    if (ctx->r10 != ctx->r1) {
        // 0x800C041C: nop

            goto L_800C03DC;
    }
    // 0x800C041C: nop

L_800C0420:
    // 0x800C0420: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800C0424: lw          $t3, 0x44C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X44C);
    // 0x800C0428: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C042C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C0430: sw          $t4, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r12;
    // 0x800C0434: jr          $ra
    // 0x800C0438: nop

    return;
    // 0x800C0438: nop

    // 0x800C043C: jr          $ra
    // 0x800C0440: nop

    return;
    // 0x800C0440: nop

;}
RECOMP_FUNC void func_800C0444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0444: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C0448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C044C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C0450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C0454: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C0458: lw          $t6, 0x42C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X42C);
    // 0x800C045C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800C0460: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800C0464: bne         $at, $zero, L_800C0474
    if (ctx->r1 != 0) {
        // 0x800C0468: nop

            goto L_800C0474;
    }
    // 0x800C0468: nop

    // 0x800C046C: b           L_800C0480
    // 0x800C0470: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
        goto L_800C0480;
    // 0x800C0470: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
L_800C0474:
    // 0x800C0474: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800C0478: lw          $s0, 0x42C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X42C);
    // 0x800C047C: nop

L_800C0480:
    // 0x800C0480: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C0484: nop

    // 0x800C0488: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800C048C: beq         $at, $zero, L_800C0508
    if (ctx->r1 == 0) {
        // 0x800C0490: nop

            goto L_800C0508;
    }
    // 0x800C0490: nop

L_800C0494:
    // 0x800C0494: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800C0498: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800C049C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C04A0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800C04A4: lw          $t0, 0x228($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X228);
    // 0x800C04A8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C04AC: nop

    // 0x800C04B0: bne         $t0, $t1, L_800C04C4
    if (ctx->r8 != ctx->r9) {
        // 0x800C04B4: nop

            goto L_800C04C4;
    }
    // 0x800C04B4: nop

    // 0x800C04B8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800C04BC: b           L_800C0524
    // 0x800C04C0: nop

        goto L_800C0524;
    // 0x800C04C0: nop

L_800C04C4:
    // 0x800C04C4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800C04C8: lw          $t4, 0x42C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X42C);
    // 0x800C04CC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800C04D0: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x800C04D4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C04D8: bne         $at, $zero, L_800C04E8
    if (ctx->r1 != 0) {
        // 0x800C04DC: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_800C04E8;
    }
    // 0x800C04DC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800C04E0: b           L_800C04F4
    // 0x800C04E4: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
        goto L_800C04F4;
    // 0x800C04E4: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
L_800C04E8:
    // 0x800C04E8: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800C04EC: lw          $s0, 0x42C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X42C);
    // 0x800C04F0: nop

L_800C04F4:
    // 0x800C04F4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C04F8: nop

    // 0x800C04FC: slt         $at, $t5, $s0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800C0500: bne         $at, $zero, L_800C0494
    if (ctx->r1 != 0) {
        // 0x800C0504: nop

            goto L_800C0494;
    }
    // 0x800C0504: nop

L_800C0508:
    // 0x800C0508: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C050C: jal         0x800C055C
    // 0x800C0510: nop

    func_800C055C(rdram, ctx);
        goto after_0;
    // 0x800C0510: nop

    after_0:
    // 0x800C0514: b           L_800C0524
    // 0x800C0518: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0524;
    // 0x800C0518: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C051C: b           L_800C0524
    // 0x800C0520: nop

        goto L_800C0524;
    // 0x800C0520: nop

L_800C0524:
    // 0x800C0524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0528: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C052C: jr          $ra
    // 0x800C0530: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C0530: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C0534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0534: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C0538: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800C053C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800C0540: lw          $v0, 0x228($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X228);
    // 0x800C0544: jr          $ra
    // 0x800C0548: nop

    return;
    // 0x800C0548: nop

    // 0x800C054C: jr          $ra
    // 0x800C0550: nop

    return;
    // 0x800C0550: nop

    // 0x800C0554: jr          $ra
    // 0x800C0558: nop

    return;
    // 0x800C0558: nop

;}
RECOMP_FUNC void func_800C055C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C055C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C0560: lw          $t6, 0x42C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X42C);
    // 0x800C0564: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0568: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800C056C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C0570: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C0574: sw          $a0, 0x228($at)
    MEM_W(0X228, ctx->r1) = ctx->r4;
    // 0x800C0578: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800C057C: lw          $t9, 0x42C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X42C);
    // 0x800C0580: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0584: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C0588: sw          $t0, 0x42C($at)
    MEM_W(0X42C, ctx->r1) = ctx->r8;
    // 0x800C058C: jr          $ra
    // 0x800C0590: nop

    return;
    // 0x800C0590: nop

    // 0x800C0594: jr          $ra
    // 0x800C0598: nop

    return;
    // 0x800C0598: nop

;}
RECOMP_FUNC void func_800C059C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C059C: nop

;}
RECOMP_FUNC void Thread_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C05A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C05A4: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
L_800C05A8:
    // 0x800C05A8: lbu         $t6, 0x7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7);
    // 0x800C05AC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C05B0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C05B4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C05B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C05BC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C05C0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C05C4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C05C8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C05CC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C05D0: sb          $zero, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = 0;
    // 0x800C05D4: lbu         $t8, 0x7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X7);
    // 0x800C05D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C05DC: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800C05E0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C05E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C05E8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C05EC: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800C05F0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C05F4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C05F8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C05FC: sb          $zero, -0x63C7($at)
    MEM_B(-0X63C7, ctx->r1) = 0;
    // 0x800C0600: lbu         $t0, 0x7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7);
    // 0x800C0604: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800C0608: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800C060C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800C0610: sw          $zero, 0x3DC0($at)
    MEM_W(0X3DC0, ctx->r1) = 0;
    // 0x800C0614: lbu         $t2, 0x7($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X7);
    // 0x800C0618: nop

    // 0x800C061C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C0620: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800C0624: slti        $at, $t4, 0xC
    ctx->r1 = SIGNED(ctx->r12) < 0XC ? 1 : 0;
    // 0x800C0628: bne         $at, $zero, L_800C05A8
    if (ctx->r1 != 0) {
        // 0x800C062C: sb          $t3, 0x7($sp)
        MEM_B(0X7, ctx->r29) = ctx->r11;
            goto L_800C05A8;
    }
    // 0x800C062C: sb          $t3, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r11;
    // 0x800C0630: b           L_800C0638
    // 0x800C0634: nop

        goto L_800C0638;
    // 0x800C0634: nop

L_800C0638:
    // 0x800C0638: jr          $ra
    // 0x800C063C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C063C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Thread_CreateSimple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0640: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C0644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0648: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C064C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C0650: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C0654: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
L_800C0658:
    // 0x800C0658: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x800C065C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0660: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0664: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0668: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C066C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0670: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0674: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0678: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C067C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0680: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0684: nop

    // 0x800C0688: bne         $t8, $zero, L_800C0698
    if (ctx->r24 != 0) {
        // 0x800C068C: nop

            goto L_800C0698;
    }
    // 0x800C068C: nop

    // 0x800C0690: b           L_800C06B4
    // 0x800C0694: nop

        goto L_800C06B4;
    // 0x800C0694: nop

L_800C0698:
    // 0x800C0698: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x800C069C: nop

    // 0x800C06A0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C06A4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C06A8: slti        $at, $t1, 0xC
    ctx->r1 = SIGNED(ctx->r9) < 0XC ? 1 : 0;
    // 0x800C06AC: bne         $at, $zero, L_800C0658
    if (ctx->r1 != 0) {
        // 0x800C06B0: sb          $t0, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r8;
            goto L_800C0658;
    }
    // 0x800C06B0: sb          $t0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r8;
L_800C06B4:
    // 0x800C06B4: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x800C06B8: nop

    // 0x800C06BC: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x800C06C0: bne         $at, $zero, L_800C06D0
    if (ctx->r1 != 0) {
        // 0x800C06C4: nop

            goto L_800C06D0;
    }
    // 0x800C06C4: nop

    // 0x800C06C8: b           L_800C0770
    // 0x800C06CC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_800C0770;
    // 0x800C06CC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800C06D0:
    // 0x800C06D0: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x800C06D4: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C06D8: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800C06DC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800C06E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800C06E4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800C06E8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x800C06EC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800C06F0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800C06F4: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800C06F8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800C06FC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C0700: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800C0704: addiu       $t6, $t6, 0x1950
    ctx->r14 = ADD32(ctx->r14, 0X1950);
    // 0x800C0708: addu        $t7, $t4, $at
    ctx->r15 = ADD32(ctx->r12, ctx->r1);
    // 0x800C070C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0710: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0714: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800C0718: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C071C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x800C0720: addiu       $a1, $t3, 0xA
    ctx->r5 = ADD32(ctx->r11, 0XA);
    // 0x800C0724: jal         0x800C4800
    // 0x800C0728: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C0728: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x800C072C: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x800C0730: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C0734: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800C0738: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C073C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800C0740: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800C0744: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800C0748: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C074C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800C0750: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800C0754: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800C0758: sb          $t0, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = ctx->r8;
    // 0x800C075C: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x800C0760: b           L_800C0770
    // 0x800C0764: nop

        goto L_800C0770;
    // 0x800C0764: nop

    // 0x800C0768: b           L_800C0770
    // 0x800C076C: nop

        goto L_800C0770;
    // 0x800C076C: nop

L_800C0770:
    // 0x800C0770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C0778: jr          $ra
    // 0x800C077C: nop

    return;
    // 0x800C077C: nop

;}
RECOMP_FUNC void Thread_CreateExtended(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0780: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C0784: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C0788: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C078C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800C0790: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C0794: sb          $zero, 0x37($sp)
    MEM_B(0X37, ctx->r29) = 0;
L_800C0798:
    // 0x800C0798: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800C079C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C07A0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C07A4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C07A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C07AC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C07B0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C07B4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C07B8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C07BC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C07C0: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C07C4: nop

    // 0x800C07C8: bne         $t8, $zero, L_800C07D8
    if (ctx->r24 != 0) {
        // 0x800C07CC: nop

            goto L_800C07D8;
    }
    // 0x800C07CC: nop

    // 0x800C07D0: b           L_800C07F4
    // 0x800C07D4: nop

        goto L_800C07F4;
    // 0x800C07D4: nop

L_800C07D8:
    // 0x800C07D8: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x800C07DC: nop

    // 0x800C07E0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C07E4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C07E8: slti        $at, $t1, 0xC
    ctx->r1 = SIGNED(ctx->r9) < 0XC ? 1 : 0;
    // 0x800C07EC: bne         $at, $zero, L_800C0798
    if (ctx->r1 != 0) {
        // 0x800C07F0: sb          $t0, 0x37($sp)
        MEM_B(0X37, ctx->r29) = ctx->r8;
            goto L_800C0798;
    }
    // 0x800C07F0: sb          $t0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r8;
L_800C07F4:
    // 0x800C07F4: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x800C07F8: nop

    // 0x800C07FC: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x800C0800: bne         $at, $zero, L_800C0810
    if (ctx->r1 != 0) {
        // 0x800C0804: nop

            goto L_800C0810;
    }
    // 0x800C0804: nop

    // 0x800C0808: b           L_800C0978
    // 0x800C080C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0978;
    // 0x800C080C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0810:
    // 0x800C0810: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x800C0814: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800C0818: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800C081C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C0820: lw          $t5, 0x3DC0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3DC0);
    // 0x800C0824: nop

    // 0x800C0828: bne         $t5, $zero, L_800C085C
    if (ctx->r13 != 0) {
        // 0x800C082C: nop

            goto L_800C085C;
    }
    // 0x800C082C: nop

    // 0x800C0830: jal         0x800BC918
    // 0x800C0834: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_0;
    // 0x800C0834: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x800C0838: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800C083C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800C0840: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C0844: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C0848: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C084C: bne         $s0, $zero, L_800C085C
    if (ctx->r16 != 0) {
        // 0x800C0850: sw          $s0, 0x3DC0($at)
        MEM_W(0X3DC0, ctx->r1) = ctx->r16;
            goto L_800C085C;
    }
    // 0x800C0850: sw          $s0, 0x3DC0($at)
    MEM_W(0X3DC0, ctx->r1) = ctx->r16;
    // 0x800C0854: b           L_800C0978
    // 0x800C0858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0978;
    // 0x800C0858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C085C:
    // 0x800C085C: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x800C0860: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800C0864: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C0868: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800C086C: lw          $t0, 0x3DC0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3DC0);
    // 0x800C0870: nop

    // 0x800C0874: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800C0878: lbu         $t1, 0x37($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X37);
    // 0x800C087C: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0880: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800C0884: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C0888: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800C088C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800C0890: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800C0894: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C0898: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800C089C: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800C08A0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800C08A4: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800C08A8: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x800C08AC: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x800C08B0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800C08B4: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x800C08B8: addiu       $t4, $t4, 0x1950
    ctx->r12 = ADD32(ctx->r12, 0X1950);
    // 0x800C08BC: addu        $t6, $t2, $at
    ctx->r14 = ADD32(ctx->r10, ctx->r1);
    // 0x800C08C0: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x800C08C4: lw          $a3, 0x3DC0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3DC0);
    // 0x800C08C8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800C08CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C08D0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x800C08D4: addiu       $a1, $t1, 0xA
    ctx->r5 = ADD32(ctx->r9, 0XA);
    // 0x800C08D8: jal         0x800C4800
    // 0x800C08DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800C08DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_1:
    // 0x800C08E0: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x800C08E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C08E8: sll         $t3, $t0, 5
    ctx->r11 = S32(ctx->r8 << 5);
    // 0x800C08EC: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x800C08F0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C08F4: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x800C08F8: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800C08FC: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x800C0900: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800C0904: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C0908: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x800C090C: sb          $t9, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = ctx->r25;
    // 0x800C0910: lbu         $t1, 0x37($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X37);
    // 0x800C0914: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800C0918: nop

    // 0x800C091C: sb          $t1, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r9;
    // 0x800C0920: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x800C0924: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800C0928: sll         $t6, $t2, 5
    ctx->r14 = S32(ctx->r10 << 5);
    // 0x800C092C: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x800C0930: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0934: subu        $t6, $t6, $t2
    ctx->r14 = SUB32(ctx->r14, ctx->r10);
    // 0x800C0938: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C093C: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x800C0940: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C0944: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C0948: addiu       $t4, $t4, 0x1950
    ctx->r12 = ADD32(ctx->r12, 0X1950);
    // 0x800C094C: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x800C0950: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    // 0x800C0954: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800C0958: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800C095C: nop

    // 0x800C0960: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800C0964: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800C0968: b           L_800C0978
    // 0x800C096C: nop

        goto L_800C0978;
    // 0x800C096C: nop

    // 0x800C0970: b           L_800C0978
    // 0x800C0974: nop

        goto L_800C0978;
    // 0x800C0974: nop

L_800C0978:
    // 0x800C0978: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C097C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C0980: jr          $ra
    // 0x800C0984: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C0984: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C0988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0988: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C098C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800C0990: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C0994: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0998: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800C099C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C09A0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C09A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C09A8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800C09AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C09B0: lbu         $t7, -0x63C8($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X63C8);
    // 0x800C09B4: nop

    // 0x800C09B8: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800C09BC: bne         $t8, $zero, L_800C09CC
    if (ctx->r24 != 0) {
        // 0x800C09C0: nop

            goto L_800C09CC;
    }
    // 0x800C09C0: nop

    // 0x800C09C4: jr          $ra
    // 0x800C09C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800C09C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C09CC:
    // 0x800C09CC: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x800C09D0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800C09D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C09D8: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800C09DC: sll         $t4, $a0, 5
    ctx->r12 = S32(ctx->r4 << 5);
    // 0x800C09E0: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800C09E4: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800C09E8: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800C09EC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800C09F0: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C09F4: addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // 0x800C09F8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x800C09FC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C0A00: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800C0A04: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x800C0A08: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800C0A0C: addiu       $t2, $t1, 0x7FFF
    ctx->r10 = ADD32(ctx->r9, 0X7FFF);
    // 0x800C0A10: lbu         $t2, 0x2E9($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X2E9);
    // 0x800C0A14: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800C0A18: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800C0A1C: addiu       $at, $t5, 0x7FFF
    ctx->r1 = ADD32(ctx->r13, 0X7FFF);
    // 0x800C0A20: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800C0A24: sb          $t3, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r11;
    // 0x800C0A28: jr          $ra
    // 0x800C0A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C0A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0A30: jr          $ra
    // 0x800C0A34: nop

    return;
    // 0x800C0A34: nop

    // 0x800C0A38: jr          $ra
    // 0x800C0A3C: nop

    return;
    // 0x800C0A3C: nop

;}
RECOMP_FUNC void func_800C0A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0A40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C0A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0A48: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800C0A4C:
    // 0x800C0A4C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0A50: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0A54: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0A58: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0A5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0A60: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0A64: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0A68: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0A6C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0A70: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0A74: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0A78: nop

    // 0x800C0A7C: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0A80: beq         $t9, $zero, L_800C0B40
    if (ctx->r25 == 0) {
        // 0x800C0A84: nop

            goto L_800C0B40;
    }
    // 0x800C0A84: nop

    // 0x800C0A88: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x800C0A8C: beq         $t0, $zero, L_800C0B40
    if (ctx->r8 == 0) {
        // 0x800C0A90: nop

            goto L_800C0B40;
    }
    // 0x800C0A90: nop

    // 0x800C0A94: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0A98: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x800C0A9C: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800C0AA0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C0AA4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800C0AA8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800C0AAC: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800C0AB0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C0AB4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800C0AB8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800C0ABC: lbu         $t3, -0x63C8($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X63C8);
    // 0x800C0AC0: nop

    // 0x800C0AC4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x800C0AC8: beq         $t4, $zero, L_800C0ADC
    if (ctx->r12 == 0) {
        // 0x800C0ACC: nop

            goto L_800C0ADC;
    }
    // 0x800C0ACC: nop

    // 0x800C0AD0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0AD4: jal         0x800989BC
    // 0x800C0AD8: nop

    func_800989BC(rdram, ctx);
        goto after_0;
    // 0x800C0AD8: nop

    after_0:
L_800C0ADC:
    // 0x800C0ADC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0AE0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C0AE4: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800C0AE8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C0AEC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0AF0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800C0AF4: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C0AF8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C0AFC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C0B00: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C0B04: sb          $zero, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = 0;
    // 0x800C0B08: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0B0C: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0B10: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x800C0B14: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800C0B18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C0B1C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800C0B20: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800C0B24: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800C0B28: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C0B2C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C0B30: addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // 0x800C0B34: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x800C0B38: jal         0x800CB840
    // 0x800C0B3C: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    osDestroyThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800C0B3C: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    after_1:
L_800C0B40:
    // 0x800C0B40: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0B44: nop

    // 0x800C0B48: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800C0B4C: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x800C0B50: bne         $at, $zero, L_800C0A4C
    if (ctx->r1 != 0) {
        // 0x800C0B54: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_800C0A4C;
    }
    // 0x800C0B54: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800C0B58: b           L_800C0B60
    // 0x800C0B5C: nop

        goto L_800C0B60;
    // 0x800C0B5C: nop

L_800C0B60:
    // 0x800C0B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0B64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C0B68: jr          $ra
    // 0x800C0B6C: nop

    return;
    // 0x800C0B6C: nop

;}
RECOMP_FUNC void Thread_DestroyThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0B78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0B7C: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0B80: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0B84: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0B88: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0B8C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0B90: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0B94: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0B98: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0B9C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0BA0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0BA4: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0BA8: nop

    // 0x800C0BAC: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0BB0: bne         $t9, $zero, L_800C0BC0
    if (ctx->r25 != 0) {
        // 0x800C0BB4: nop

            goto L_800C0BC0;
    }
    // 0x800C0BB4: nop

    // 0x800C0BB8: b           L_800C0C7C
    // 0x800C0BBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0C7C;
    // 0x800C0BBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0BC0:
    // 0x800C0BC0: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0BC4: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x800C0BC8: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C0BCC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0BD0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C0BD4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C0BD8: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C0BDC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0BE0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C0BE4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C0BE8: lbu         $t2, -0x63C8($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X63C8);
    // 0x800C0BEC: nop

    // 0x800C0BF0: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800C0BF4: beq         $t3, $zero, L_800C0C08
    if (ctx->r11 == 0) {
        // 0x800C0BF8: nop

            goto L_800C0C08;
    }
    // 0x800C0BF8: nop

    // 0x800C0BFC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0C00: jal         0x800989BC
    // 0x800C0C04: nop

    func_800989BC(rdram, ctx);
        goto after_0;
    // 0x800C0C04: nop

    after_0:
L_800C0C08:
    // 0x800C0C08: lbu         $t4, 0x1B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0C0C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C0C10: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x800C0C14: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C0C18: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C0C1C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C0C20: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800C0C24: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C0C28: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800C0C2C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C0C30: sb          $zero, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = 0;
    // 0x800C0C34: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0C38: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0C3C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0C40: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0C44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0C48: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0C4C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0C50: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0C54: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0C58: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C0C5C: addiu       $t9, $t9, 0x1950
    ctx->r25 = ADD32(ctx->r25, 0X1950);
    // 0x800C0C60: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800C0C64: jal         0x800CB840
    // 0x800C0C68: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    osDestroyThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800C0C68: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x800C0C6C: b           L_800C0C7C
    // 0x800C0C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0C7C;
    // 0x800C0C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0C74: b           L_800C0C7C
    // 0x800C0C78: nop

        goto L_800C0C7C;
    // 0x800C0C78: nop

L_800C0C7C:
    // 0x800C0C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0C84: jr          $ra
    // 0x800C0C88: nop

    return;
    // 0x800C0C88: nop

;}
RECOMP_FUNC void Thread_Start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0C94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0C98: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0C9C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0CA0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0CA4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0CA8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0CAC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0CB0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0CB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0CB8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0CBC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0CC0: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0CC4: nop

    // 0x800C0CC8: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0CCC: bne         $t9, $zero, L_800C0CDC
    if (ctx->r25 != 0) {
        // 0x800C0CD0: nop

            goto L_800C0CDC;
    }
    // 0x800C0CD0: nop

    // 0x800C0CD4: b           L_800C0D24
    // 0x800C0CD8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0D24;
    // 0x800C0CD8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0CDC:
    // 0x800C0CDC: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0CE0: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0CE4: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C0CE8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0CEC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C0CF0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C0CF4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C0CF8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0CFC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C0D00: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C0D04: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C0D08: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C0D0C: jal         0x800C4950
    // 0x800C0D10: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C0D10: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x800C0D14: b           L_800C0D24
    // 0x800C0D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0D24;
    // 0x800C0D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0D1C: b           L_800C0D24
    // 0x800C0D20: nop

        goto L_800C0D24;
    // 0x800C0D20: nop

L_800C0D24:
    // 0x800C0D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0D2C: jr          $ra
    // 0x800C0D30: nop

    return;
    // 0x800C0D30: nop

;}
RECOMP_FUNC void Thread_StopThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0D34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0D40: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0D44: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0D48: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0D4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0D50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0D54: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0D58: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0D5C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0D60: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0D64: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0D68: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0D6C: nop

    // 0x800C0D70: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0D74: bne         $t9, $zero, L_800C0D84
    if (ctx->r25 != 0) {
        // 0x800C0D78: nop

            goto L_800C0D84;
    }
    // 0x800C0D78: nop

    // 0x800C0D7C: b           L_800C0DCC
    // 0x800C0D80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0DCC;
    // 0x800C0D80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0D84:
    // 0x800C0D84: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0D88: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0D8C: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C0D90: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0D94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C0D98: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C0D9C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C0DA0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0DA4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C0DA8: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C0DAC: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C0DB0: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C0DB4: jal         0x800CB940
    // 0x800C0DB8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C0DB8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x800C0DBC: b           L_800C0DCC
    // 0x800C0DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0DCC;
    // 0x800C0DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0DC4: b           L_800C0DCC
    // 0x800C0DC8: nop

        goto L_800C0DCC;
    // 0x800C0DC8: nop

L_800C0DCC:
    // 0x800C0DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0DD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0DD4: jr          $ra
    // 0x800C0DD8: nop

    return;
    // 0x800C0DD8: nop

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
RECOMP_FUNC void Thread_GetPtr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0E04: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C0E08: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800C0E0C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C0E10: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0E14: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800C0E18: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C0E1C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C0E20: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C0E24: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800C0E28: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0E2C: lbu         $t7, -0x63C8($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X63C8);
    // 0x800C0E30: nop

    // 0x800C0E34: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800C0E38: bne         $t8, $zero, L_800C0E48
    if (ctx->r24 != 0) {
        // 0x800C0E3C: nop

            goto L_800C0E48;
    }
    // 0x800C0E3C: nop

    // 0x800C0E40: jr          $ra
    // 0x800C0E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C0E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0E48:
    // 0x800C0E48: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x800C0E4C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800C0E50: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C0E54: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800C0E58: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800C0E5C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800C0E60: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C0E64: addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // 0x800C0E68: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C0E6C: jr          $ra
    // 0x800C0E70: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    return;
    // 0x800C0E70: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800C0E74: jr          $ra
    // 0x800C0E78: nop

    return;
    // 0x800C0E78: nop

    // 0x800C0E7C: jr          $ra
    // 0x800C0E80: nop

    return;
    // 0x800C0E80: nop

;}
RECOMP_FUNC void Thread_GetCreatedThreadsCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0E84: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C0E88: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800C0E8C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C0E90:
    // 0x800C0E90: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C0E94: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0E98: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0E9C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0EA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0EA4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0EA8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0EAC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0EB0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0EB4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0EB8: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0EBC: nop

    // 0x800C0EC0: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0EC4: beq         $t9, $zero, L_800C0EDC
    if (ctx->r25 == 0) {
        // 0x800C0EC8: nop

            goto L_800C0EDC;
    }
    // 0x800C0EC8: nop

    // 0x800C0ECC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800C0ED0: nop

    // 0x800C0ED4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C0ED8: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_800C0EDC:
    // 0x800C0EDC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800C0EE0: nop

    // 0x800C0EE4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C0EE8: slti        $at, $t3, 0xC
    ctx->r1 = SIGNED(ctx->r11) < 0XC ? 1 : 0;
    // 0x800C0EEC: bne         $at, $zero, L_800C0E90
    if (ctx->r1 != 0) {
        // 0x800C0EF0: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_800C0E90;
    }
    // 0x800C0EF0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800C0EF4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800C0EF8: b           L_800C0F08
    // 0x800C0EFC: nop

        goto L_800C0F08;
    // 0x800C0EFC: nop

    // 0x800C0F00: b           L_800C0F08
    // 0x800C0F04: nop

        goto L_800C0F08;
    // 0x800C0F04: nop

L_800C0F08:
    // 0x800C0F08: jr          $ra
    // 0x800C0F0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C0F0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Thread_UnkDbgFunc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0F1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C0F20: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0F24: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0F28: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0F2C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0F30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0F34: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0F38: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0F3C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0F40: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0F44: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0F48: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0F4C: nop

    // 0x800C0F50: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0F54: bne         $t9, $zero, L_800C0F64
    if (ctx->r25 != 0) {
        // 0x800C0F58: nop

            goto L_800C0F64;
    }
    // 0x800C0F58: nop

    // 0x800C0F5C: b           L_800C0FA0
    // 0x800C0F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0FA0;
    // 0x800C0F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0F64:
    // 0x800C0F64: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0F68: jal         0x800C0FFC
    // 0x800C0F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Thread_SetPriority(rdram, ctx);
        goto after_0;
    // 0x800C0F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800C0F70: beq         $v0, $zero, L_800C0F80
    if (ctx->r2 == 0) {
        // 0x800C0F74: nop

            goto L_800C0F80;
    }
    // 0x800C0F74: nop

    // 0x800C0F78: b           L_800C0FA0
    // 0x800C0F7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0FA0;
    // 0x800C0F7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0F80:
    // 0x800C0F80: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C0F84: jal         0x800C0C8C
    // 0x800C0F88: nop

    Thread_Start(rdram, ctx);
        goto after_1;
    // 0x800C0F88: nop

    after_1:
    // 0x800C0F8C: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0F90: jal         0x800C0D34
    // 0x800C0F94: nop

    Thread_StopThread(rdram, ctx);
        goto after_2;
    // 0x800C0F94: nop

    after_2:
    // 0x800C0F98: b           L_800C0FA0
    // 0x800C0F9C: nop

        goto L_800C0FA0;
    // 0x800C0F9C: nop

L_800C0FA0:
    // 0x800C0FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0FA8: jr          $ra
    // 0x800C0FAC: nop

    return;
    // 0x800C0FAC: nop

;}
RECOMP_FUNC void Thread_UnkDbgFunc1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0FB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0FBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C0FC0: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C0FC4: jal         0x800C0C8C
    // 0x800C0FC8: nop

    Thread_Start(rdram, ctx);
        goto after_0;
    // 0x800C0FC8: nop

    after_0:
    // 0x800C0FCC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0FD0: jal         0x800C0D34
    // 0x800C0FD4: nop

    Thread_StopThread(rdram, ctx);
        goto after_1;
    // 0x800C0FD4: nop

    after_1:
    // 0x800C0FD8: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C0FDC: jal         0x800C0B70
    // 0x800C0FE0: nop

    Thread_DestroyThread(rdram, ctx);
        goto after_2;
    // 0x800C0FE0: nop

    after_2:
    // 0x800C0FE4: b           L_800C0FEC
    // 0x800C0FE8: nop

        goto L_800C0FEC;
    // 0x800C0FE8: nop

L_800C0FEC:
    // 0x800C0FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0FF4: jr          $ra
    // 0x800C0FF8: nop

    return;
    // 0x800C0FF8: nop

;}
RECOMP_FUNC void Thread_SetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0FFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C1008: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C100C: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C1010: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C1014: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C1018: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C101C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C1020: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C1024: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C1028: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C102C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C1030: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C1034: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C1038: nop

    // 0x800C103C: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C1040: bne         $t9, $zero, L_800C1050
    if (ctx->r25 != 0) {
        // 0x800C1044: nop

            goto L_800C1050;
    }
    // 0x800C1044: nop

    // 0x800C1048: b           L_800C109C
    // 0x800C104C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C109C;
    // 0x800C104C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C1050:
    // 0x800C1050: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C1054: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C1058: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C105C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C1060: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C1064: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C1068: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C106C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C1070: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C1074: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C1078: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C107C: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C1080: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1084: jal         0x800CB5A0
    // 0x800C1088: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1088: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x800C108C: b           L_800C109C
    // 0x800C1090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C109C;
    // 0x800C1090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1094: b           L_800C109C
    // 0x800C1098: nop

        goto L_800C109C;
    // 0x800C1098: nop

L_800C109C:
    // 0x800C109C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C10A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C10A4: jr          $ra
    // 0x800C10A8: nop

    return;
    // 0x800C10A8: nop

;}
RECOMP_FUNC void Thread_GetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C10AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C10B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C10B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C10B8: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C10BC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C10C0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C10C4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C10C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C10CC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C10D0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C10D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C10D8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C10DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C10E0: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C10E4: nop

    // 0x800C10E8: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C10EC: bne         $t9, $zero, L_800C10FC
    if (ctx->r25 != 0) {
        // 0x800C10F0: nop

            goto L_800C10FC;
    }
    // 0x800C10F0: nop

    // 0x800C10F4: b           L_800C1144
    // 0x800C10F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1144;
    // 0x800C10F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C10FC:
    // 0x800C10FC: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C1100: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C1104: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C1108: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C110C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C1110: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C1114: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C1118: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C111C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C1120: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C1124: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C1128: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C112C: jal         0x800CBA00
    // 0x800C1130: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    osGetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1130: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x800C1134: b           L_800C1144
    // 0x800C1138: nop

        goto L_800C1144;
    // 0x800C1138: nop

    // 0x800C113C: b           L_800C1144
    // 0x800C1140: nop

        goto L_800C1144;
    // 0x800C1140: nop

L_800C1144:
    // 0x800C1144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C114C: jr          $ra
    // 0x800C1150: nop

    return;
    // 0x800C1150: nop

;}
RECOMP_FUNC void func_800C1154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C1158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C115C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C1160: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C1164: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800C1168: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C116C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C1170: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1174: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C1178: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C117C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C1180: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1184: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C1188: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800C118C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C1190: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800C1194: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1198: nop

    // 0x800C119C: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800C11A0: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800C11A4: nop

    // 0x800C11A8: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800C11AC: bne         $t2, $zero, L_800C11BC
    if (ctx->r10 != 0) {
        // 0x800C11B0: nop

            goto L_800C11BC;
    }
    // 0x800C11B0: nop

    // 0x800C11B4: b           L_800C1254
    // 0x800C11B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1254;
    // 0x800C11B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C11BC:
    // 0x800C11BC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C11C0: nop

    // 0x800C11C4: slti        $at, $t3, 0x9
    ctx->r1 = SIGNED(ctx->r11) < 0X9 ? 1 : 0;
    // 0x800C11C8: bne         $at, $zero, L_800C11D8
    if (ctx->r1 != 0) {
        // 0x800C11CC: nop

            goto L_800C11D8;
    }
    // 0x800C11CC: nop

    // 0x800C11D0: b           L_800C1254
    // 0x800C11D4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800C1254;
    // 0x800C11D4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800C11D8:
    // 0x800C11D8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800C11DC: nop

    // 0x800C11E0: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x800C11E4: lbu         $t5, 0x2EA($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2EA);
    // 0x800C11E8: nop

    // 0x800C11EC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800C11F0: beq         $t6, $zero, L_800C120C
    if (ctx->r14 == 0) {
        // 0x800C11F4: nop

            goto L_800C120C;
    }
    // 0x800C11F4: nop

    // 0x800C11F8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800C11FC: jal         0x800C13B8
    // 0x800C1200: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_0;
    // 0x800C1200: nop

    after_0:
    // 0x800C1204: b           L_800C1254
    // 0x800C1208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1254;
    // 0x800C1208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C120C:
    // 0x800C120C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1210: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800C1214: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    // 0x800C1218: ori         $at, $zero, 0x82B0
    ctx->r1 = 0 | 0X82B0;
    // 0x800C121C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C1220: jal         0x800C42B0
    // 0x800C1224: addu        $a1, $t7, $at
    ctx->r5 = ADD32(ctx->r15, ctx->r1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800C1224: addu        $a1, $t7, $at
    ctx->r5 = ADD32(ctx->r15, ctx->r1);
    after_1:
    // 0x800C1228: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C122C: nop

    // 0x800C1230: addiu       $t9, $t8, 0x7FFF
    ctx->r25 = ADD32(ctx->r24, 0X7FFF);
    // 0x800C1234: lbu         $t9, 0x2EA($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2EA);
    // 0x800C1238: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x800C123C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800C1240: sb          $t0, 0x2EA($at)
    MEM_B(0X2EA, ctx->r1) = ctx->r8;
    // 0x800C1244: b           L_800C1254
    // 0x800C1248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1254;
    // 0x800C1248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C124C: b           L_800C1254
    // 0x800C1250: nop

        goto L_800C1254;
    // 0x800C1250: nop

L_800C1254:
    // 0x800C1254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C125C: jr          $ra
    // 0x800C1260: nop

    return;
    // 0x800C1260: nop

;}
RECOMP_FUNC void Thread_SendMesgNoBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C126C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C1270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1274: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C1278: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C127C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C1280: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C1284: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1288: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C128C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C1290: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C1294: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1298: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C129C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C12A0: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C12A4: nop

    // 0x800C12A8: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C12AC: bne         $t9, $zero, L_800C12BC
    if (ctx->r25 != 0) {
        // 0x800C12B0: nop

            goto L_800C12BC;
    }
    // 0x800C12B0: nop

    // 0x800C12B4: b           L_800C1304
    // 0x800C12B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1304;
    // 0x800C12B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C12BC:
    // 0x800C12BC: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C12C0: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800C12C4: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C12C8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C12CC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C12D0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C12D4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C12D8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C12DC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C12E0: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C12E4: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C12E8: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C12EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C12F0: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800C12F4: jal         0x800C4AA0
    // 0x800C12F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C12F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C12FC: b           L_800C1304
    // 0x800C1300: nop

        goto L_800C1304;
    // 0x800C1300: nop

L_800C1304:
    // 0x800C1304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C130C: jr          $ra
    // 0x800C1310: nop

    return;
    // 0x800C1310: nop

;}
RECOMP_FUNC void func_800C1314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C1318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C131C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C1320: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C1324: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800C1328: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C132C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C1330: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1334: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C1338: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C133C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C1340: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1344: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C1348: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800C134C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C1350: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800C1354: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1358: nop

    // 0x800C135C: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800C1360: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800C1364: nop

    // 0x800C1368: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800C136C: bne         $t2, $zero, L_800C137C
    if (ctx->r10 != 0) {
        // 0x800C1370: nop

            goto L_800C137C;
    }
    // 0x800C1370: nop

    // 0x800C1374: b           L_800C13A8
    // 0x800C1378: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C13A8;
    // 0x800C1378: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C137C:
    // 0x800C137C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1380: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800C1384: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    // 0x800C1388: ori         $at, $zero, 0x82B0
    ctx->r1 = 0 | 0X82B0;
    // 0x800C138C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C1390: jal         0x800C4C40
    // 0x800C1394: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1394: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    after_0:
    // 0x800C1398: b           L_800C13A8
    // 0x800C139C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C13A8;
    // 0x800C139C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C13A0: b           L_800C13A8
    // 0x800C13A4: nop

        goto L_800C13A8;
    // 0x800C13A4: nop

L_800C13A8:
    // 0x800C13A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C13AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C13B0: jr          $ra
    // 0x800C13B4: nop

    return;
    // 0x800C13B4: nop

;}
RECOMP_FUNC void Thread_ResetMqValidCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C13B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C13BC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C13C0: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800C13C4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C13C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C13CC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800C13D0: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C13D4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C13D8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800C13DC: addiu       $t7, $t7, 0x1950
    ctx->r15 = ADD32(ctx->r15, 0X1950);
    // 0x800C13E0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C13E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C13E8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800C13EC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C13F0: nop

    // 0x800C13F4: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x800C13F8: lbu         $t0, 0x2E9($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X2E9);
    // 0x800C13FC: nop

    // 0x800C1400: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x800C1404: bne         $t1, $zero, L_800C1414
    if (ctx->r9 != 0) {
        // 0x800C1408: nop

            goto L_800C1414;
    }
    // 0x800C1408: nop

    // 0x800C140C: b           L_800C1434
    // 0x800C1410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1434;
    // 0x800C1410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C1414:
    // 0x800C1414: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800C1418: nop

    // 0x800C141C: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x800C1420: sw          $zero, 0x2D9($at)
    MEM_W(0X2D9, ctx->r1) = 0;
    // 0x800C1424: b           L_800C1434
    // 0x800C1428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1434;
    // 0x800C1428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C142C: b           L_800C1434
    // 0x800C1430: nop

        goto L_800C1434;
    // 0x800C1430: nop

L_800C1434:
    // 0x800C1434: jr          $ra
    // 0x800C1438: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C1438: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Thread_ReceiveMsgInThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C143C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C1440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1444: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C1448: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C144C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C1450: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800C1454: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C1458: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C145C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1460: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C1464: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C1468: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C146C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1470: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C1474: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800C1478: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C147C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800C1480: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1484: nop

    // 0x800C1488: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800C148C: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800C1490: nop

    // 0x800C1494: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800C1498: bne         $t2, $zero, L_800C14A8
    if (ctx->r10 != 0) {
        // 0x800C149C: nop

            goto L_800C14A8;
    }
    // 0x800C149C: nop

    // 0x800C14A0: b           L_800C14D0
    // 0x800C14A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C14D0;
    // 0x800C14A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C14A8:
    // 0x800C14A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C14AC: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800C14B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800C14B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C14B8: jal         0x800C4C40
    // 0x800C14BC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C14BC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_0:
    // 0x800C14C0: b           L_800C14D0
    // 0x800C14C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C14D0;
    // 0x800C14C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C14C8: b           L_800C14D0
    // 0x800C14CC: nop

        goto L_800C14D0;
    // 0x800C14CC: nop

L_800C14D0:
    // 0x800C14D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C14D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C14D8: jr          $ra
    // 0x800C14DC: nop

    return;
    // 0x800C14DC: nop

;}
RECOMP_FUNC void Thread_CreateMesgQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C14E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C14E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C14E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C14EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C14F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C14F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C14F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C14FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C1500: jal         0x800C42B0
    // 0x800C1504: nop

    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1504: nop

    after_0:
    // 0x800C1508: b           L_800C1518
    // 0x800C150C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1518;
    // 0x800C150C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1510: b           L_800C1518
    // 0x800C1514: nop

        goto L_800C1518;
    // 0x800C1514: nop

L_800C1518:
    // 0x800C1518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C151C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1520: jr          $ra
    // 0x800C1524: nop

    return;
    // 0x800C1524: nop

;}
RECOMP_FUNC void Thread_SendMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C152C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C1534: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1538: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C153C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1540: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1544: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C1548: jal         0x800C4AA0
    // 0x800C154C: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C154C: nop

    after_0:
    // 0x800C1550: b           L_800C1560
    // 0x800C1554: nop

        goto L_800C1560;
    // 0x800C1554: nop

    // 0x800C1558: b           L_800C1560
    // 0x800C155C: nop

        goto L_800C1560;
    // 0x800C155C: nop

L_800C1560:
    // 0x800C1560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1568: jr          $ra
    // 0x800C156C: nop

    return;
    // 0x800C156C: nop

;}
RECOMP_FUNC void Thread_ReceiveMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1578: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C157C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1580: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C1584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1588: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C158C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C1590: jal         0x800C4C40
    // 0x800C1594: nop

    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1594: nop

    after_0:
    // 0x800C1598: b           L_800C15A8
    // 0x800C159C: nop

        goto L_800C15A8;
    // 0x800C159C: nop

    // 0x800C15A0: b           L_800C15A8
    // 0x800C15A4: nop

        goto L_800C15A8;
    // 0x800C15A4: nop

L_800C15A8:
    // 0x800C15A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C15AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C15B0: jr          $ra
    // 0x800C15B4: nop

    return;
    // 0x800C15B4: nop

;}
RECOMP_FUNC void func_800C15B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C15B8: nop

    // 0x800C15BC: nop

;}
RECOMP_FUNC void MtxUtil_InitStack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C15C0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C15C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C15C8: addiu       $t6, $t6, 0x6D0
    ctx->r14 = ADD32(ctx->r14, 0X6D0);
    // 0x800C15CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C15D0: sw          $t6, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r14;
    // 0x800C15D4: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800C15D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C15DC: sw          $t7, 0xCD8($at)
    MEM_W(0XCD8, ctx->r1) = ctx->r15;
    // 0x800C15E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C15E4: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C15E8: nop

    // 0x800C15EC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800C15F0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800C15F4: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
L_800C15F8:
    // 0x800C15F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C15FC: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C1600: nop

    // 0x800C1604: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x800C1608: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C160C: nop

    // 0x800C1610: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x800C1614: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800C1618: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C161C: nop

    // 0x800C1620: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800C1624: bgtz        $t4, L_800C15F8
    if (SIGNED(ctx->r12) > 0) {
        // 0x800C1628: sw          $t4, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r12;
            goto L_800C15F8;
    }
    // 0x800C1628: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800C162C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C1630: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800C1634: lw          $t5, 0xCE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE4);
    // 0x800C1638: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C163C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1640: swc1        $f6, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f6.u32l;
    // 0x800C1644: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1648: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C164C: lwc1        $f14, 0x3C($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x800C1650: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C1654: swc1        $f14, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f14.u32l;
    // 0x800C1658: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C165C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C1660: swc1        $f12, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f12.u32l;
    // 0x800C1664: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C1668: nop

    // 0x800C166C: swc1        $f12, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f12.u32l;
    // 0x800C1670: b           L_800C1678
    // 0x800C1674: nop

        goto L_800C1678;
    // 0x800C1674: nop

L_800C1678:
    // 0x800C1678: jr          $ra
    // 0x800C167C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C167C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void MtxUtil_PushCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1680: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1684: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1688: lw          $t6, 0xCD8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCD8);
    // 0x800C168C: nop

    // 0x800C1690: bgtz        $t6, L_800C16A0
    if (SIGNED(ctx->r14) > 0) {
        // 0x800C1694: nop

            goto L_800C16A0;
    }
    // 0x800C1694: nop

    // 0x800C1698: b           L_800C174C
    // 0x800C169C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C174C;
    // 0x800C169C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C16A0:
    // 0x800C16A0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C16A4: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C16A8: nop

    // 0x800C16AC: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C16B0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C16B4: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C16B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C16BC: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x800C16C0: sw          $t9, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r25;
    // 0x800C16C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C16C8: lw          $t0, 0xCE4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE4);
    // 0x800C16CC: nop

    // 0x800C16D0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800C16D4: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800C16D8: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
L_800C16DC:
    // 0x800C16DC: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C16E0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C16E4: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C16E8: nop

    // 0x800C16EC: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x800C16F0: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800C16F4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C16F8: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C16FC: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800C1700: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800C1704: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C1708: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C170C: nop

    // 0x800C1710: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C1714: bgtz        $t9, L_800C16DC
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C1718: sw          $t9, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r25;
            goto L_800C16DC;
    }
    // 0x800C1718: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C171C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C1720: lw          $t0, 0xCD8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCD8);
    // 0x800C1724: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1728: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800C172C: sw          $t1, 0xCD8($at)
    MEM_W(0XCD8, ctx->r1) = ctx->r9;
    // 0x800C1730: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800C1734: lw          $t2, 0xCD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCD8);
    // 0x800C1738: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800C173C: b           L_800C174C
    // 0x800C1740: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
        goto L_800C174C;
    // 0x800C1740: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x800C1744: b           L_800C174C
    // 0x800C1748: nop

        goto L_800C174C;
    // 0x800C1748: nop

L_800C174C:
    // 0x800C174C: jr          $ra
    // 0x800C1750: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1750: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void MtxUtil_PushIdentity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1754: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1758: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C175C: lw          $t6, 0xCD8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCD8);
    // 0x800C1760: nop

    // 0x800C1764: bgtz        $t6, L_800C1774
    if (SIGNED(ctx->r14) > 0) {
        // 0x800C1768: nop

            goto L_800C1774;
    }
    // 0x800C1768: nop

    // 0x800C176C: b           L_800C1848
    // 0x800C1770: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1848;
    // 0x800C1770: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C1774:
    // 0x800C1774: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C1778: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C177C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1780: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x800C1784: sw          $t8, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r24;
    // 0x800C1788: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C178C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C1790: nop

    // 0x800C1794: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C1798: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800C179C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
L_800C17A0:
    // 0x800C17A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C17A4: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C17A8: nop

    // 0x800C17AC: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x800C17B0: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C17B4: nop

    // 0x800C17B8: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C17BC: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C17C0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C17C4: nop

    // 0x800C17C8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800C17CC: bgtz        $t5, L_800C17A0
    if (SIGNED(ctx->r13) > 0) {
        // 0x800C17D0: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C17A0;
    }
    // 0x800C17D0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C17D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C17D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C17DC: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C17E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C17E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C17E8: swc1        $f6, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f6.u32l;
    // 0x800C17EC: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C17F0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C17F4: lwc1        $f14, 0x3C($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x800C17F8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C17FC: swc1        $f14, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f14.u32l;
    // 0x800C1800: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C1804: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C1808: swc1        $f12, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f12.u32l;
    // 0x800C180C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C1810: nop

    // 0x800C1814: swc1        $f12, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f12.u32l;
    // 0x800C1818: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C181C: lw          $t0, 0xCD8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCD8);
    // 0x800C1820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1824: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800C1828: sw          $t1, 0xCD8($at)
    MEM_W(0XCD8, ctx->r1) = ctx->r9;
    // 0x800C182C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800C1830: lw          $t2, 0xCD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCD8);
    // 0x800C1834: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800C1838: b           L_800C1848
    // 0x800C183C: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
        goto L_800C1848;
    // 0x800C183C: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x800C1840: b           L_800C1848
    // 0x800C1844: nop

        goto L_800C1848;
    // 0x800C1844: nop

L_800C1848:
    // 0x800C1848: jr          $ra
    // 0x800C184C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C184C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void MtxUtil_Identity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1854: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800C1858: bne         $a0, $zero, L_800C1870
    if (ctx->r4 != 0) {
        // 0x800C185C: nop

            goto L_800C1870;
    }
    // 0x800C185C: nop

    // 0x800C1860: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1864: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1868: nop

    // 0x800C186C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
L_800C1870:
    // 0x800C1870: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800C1874: nop

    // 0x800C1878: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800C187C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800C1880: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
L_800C1884:
    // 0x800C1884: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C1888: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x800C188C: nop

    // 0x800C1890: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C1894: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800C1898: nop

    // 0x800C189C: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C18A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C18A4: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800C18A8: nop

    // 0x800C18AC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800C18B0: bgtz        $t3, L_800C1884
    if (SIGNED(ctx->r11) > 0) {
        // 0x800C18B4: sw          $t3, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r11;
            goto L_800C1884;
    }
    // 0x800C18B4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800C18B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C18BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C18C0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C18C4: nop

    // 0x800C18C8: swc1        $f6, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f6.u32l;
    // 0x800C18CC: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C18D0: nop

    // 0x800C18D4: lwc1        $f14, 0x3C($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X3C);
    // 0x800C18D8: nop

    // 0x800C18DC: swc1        $f14, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f14.u32l;
    // 0x800C18E0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C18E4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C18E8: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    // 0x800C18EC: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C18F0: nop

    // 0x800C18F4: swc1        $f12, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f12.u32l;
    // 0x800C18F8: b           L_800C1900
    // 0x800C18FC: nop

        goto L_800C1900;
    // 0x800C18FC: nop

L_800C1900:
    // 0x800C1900: jr          $ra
    // 0x800C1904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C1904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void MtxUtil_ClearTranslation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1908: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C190C: bne         $a0, $zero, L_800C1924
    if (ctx->r4 != 0) {
        // 0x800C1910: nop

            goto L_800C1924;
    }
    // 0x800C1910: nop

    // 0x800C1914: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1918: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C191C: b           L_800C1928
    // 0x800C1920: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
        goto L_800C1928;
    // 0x800C1920: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
L_800C1924:
    // 0x800C1924: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
L_800C1928:
    // 0x800C1928: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C192C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800C1930: nop

    // 0x800C1934: swc1        $f4, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f4.u32l;
    // 0x800C1938: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C193C: nop

    // 0x800C1940: lwc1        $f12, 0x38($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X38);
    // 0x800C1944: nop

    // 0x800C1948: swc1        $f12, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f12.u32l;
    // 0x800C194C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C1950: nop

    // 0x800C1954: swc1        $f12, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f12.u32l;
    // 0x800C1958: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C195C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C1960: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C1964: nop

    // 0x800C1968: swc1        $f6, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f6.u32l;
    // 0x800C196C: b           L_800C1974
    // 0x800C1970: nop

        goto L_800C1974;
    // 0x800C1970: nop

L_800C1974:
    // 0x800C1974: jr          $ra
    // 0x800C1978: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1978: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
