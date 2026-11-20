#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void AudioDriver_UpdateOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBBBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BBBC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BBBC4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BBBC8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BBBCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BBBD0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800BBBD4: nop

    // 0x800BBBD8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800BBBDC: addiu       $t7, $zero, 0x3E80
    ctx->r15 = ADD32(0, 0X3E80);
    // 0x800BBBE0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800BBBE4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BBBE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BBBEC: lbu         $s0, 0x4($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X4);
    // 0x800BBBF0: nop

    // 0x800BBBF4: beq         $s0, $at, L_800BBC58
    if (ctx->r16 == ctx->r1) {
        // 0x800BBBF8: nop

            goto L_800BBC58;
    }
    // 0x800BBBF8: nop

    // 0x800BBBFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BBC00: beq         $s0, $at, L_800BBD9C
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC04: nop

            goto L_800BBD9C;
    }
    // 0x800BBC04: nop

    // 0x800BBC08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BBC0C: beq         $s0, $at, L_800BBE68
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC10: nop

            goto L_800BBE68;
    }
    // 0x800BBC10: nop

    // 0x800BBC14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BBC18: beq         $s0, $at, L_800BBF80
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC1C: nop

            goto L_800BBF80;
    }
    // 0x800BBC1C: nop

    // 0x800BBC20: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800BBC24: beq         $s0, $at, L_800BC098
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC28: nop

            goto L_800BC098;
    }
    // 0x800BBC28: nop

    // 0x800BBC2C: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x800BBC30: beq         $s0, $at, L_800BC1B0
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC34: nop

            goto L_800BC1B0;
    }
    // 0x800BBC34: nop

    // 0x800BBC38: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x800BBC3C: beq         $s0, $at, L_800BC230
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC40: nop

            goto L_800BC230;
    }
    // 0x800BBC40: nop

    // 0x800BBC44: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x800BBC48: beq         $s0, $at, L_800BC358
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC4C: nop

            goto L_800BC358;
    }
    // 0x800BBC4C: nop

    // 0x800BBC50: b           L_800BC480
    // 0x800BBC54: nop

        goto L_800BC480;
    // 0x800BBC54: nop

L_800BBC58:
    // 0x800BBC58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBC5C: nop

    // 0x800BBC60: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x800BBC64: nop

    // 0x800BBC68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BBC6C: sh          $t1, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r9;
    // 0x800BBC70: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BBC74: nop

    // 0x800BBC78: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800BBC7C: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x800BBC80: nop

    // 0x800BBC84: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BBC88: bne         $at, $zero, L_800BBC9C
    if (ctx->r1 != 0) {
        // 0x800BBC8C: nop

            goto L_800BBC9C;
    }
    // 0x800BBC8C: nop

    // 0x800BBC90: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BBC94: nop

    // 0x800BBC98: sh          $zero, 0x8($t5)
    MEM_H(0X8, ctx->r13) = 0;
L_800BBC9C:
    // 0x800BBC9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BBCA0: nop

    // 0x800BBCA4: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x800BBCA8: nop

    // 0x800BBCAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BBCB0: bgez        $t7, L_800BBCC8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800BBCB4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BBCC8;
    }
    // 0x800BBCB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBCB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBCBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBCC0: nop

    // 0x800BBCC4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800BBCC8:
    // 0x800BBCC8: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x800BBCCC: nop

    // 0x800BBCD0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BBCD4: bgez        $t8, L_800BBCEC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800BBCD8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BBCEC;
    }
    // 0x800BBCD8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBCDC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBCE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BBCE4: nop

    // 0x800BBCE8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800BBCEC:
    // 0x800BBCEC: nop

    // 0x800BBCF0: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BBCF4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800BBCF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BBCFC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBD00: lwc1        $f19, -0x238($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X238);
    // 0x800BBD04: lwc1        $f18, -0x234($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X234);
    // 0x800BBD08: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800BBD0C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800BBD10: jal         0x800CAE10
    // 0x800BBD14: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800BBD14: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_0:
    // 0x800BBD18: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800BBD1C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BBD20: nop

    // 0x800BBD24: lbu         $t1, 0xC($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XC);
    // 0x800BBD28: nop

    // 0x800BBD2C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800BBD30: bgez        $t1, L_800BBD48
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800BBD34: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BBD48;
    }
    // 0x800BBD34: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBD38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBD3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBD40: nop

    // 0x800BBD44: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800BBD48:
    // 0x800BBD48: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBD4C: nop

    // 0x800BBD50: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBD54: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800BBD58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBD5C: nop

    // 0x800BBD60: lbu         $t2, 0xD($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XD);
    // 0x800BBD64: nop

    // 0x800BBD68: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800BBD6C: bgez        $t2, L_800BBD84
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BBD70: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800BBD84;
    }
    // 0x800BBD70: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BBD74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBD78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBD7C: nop

    // 0x800BBD80: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_800BBD84:
    // 0x800BBD84: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBD88: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BBD8C: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800BBD90: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x800BBD94: b           L_800BC480
    // 0x800BBD98: nop

        goto L_800BC480;
    // 0x800BBD98: nop

L_800BBD9C:
    // 0x800BBD9C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BBDA0: nop

    // 0x800BBDA4: lbu         $t5, 0x5($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X5);
    // 0x800BBDA8: nop

    // 0x800BBDAC: bne         $t5, $zero, L_800BBDFC
    if (ctx->r13 != 0) {
        // 0x800BBDB0: nop

            goto L_800BBDFC;
    }
    // 0x800BBDB0: nop

    // 0x800BBDB4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BBDB8: nop

    // 0x800BBDBC: lbu         $t6, 0xE($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XE);
    // 0x800BBDC0: nop

    // 0x800BBDC4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800BBDC8: bgez        $t6, L_800BBDE0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800BBDCC: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BBDE0;
    }
    // 0x800BBDCC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BBDD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBDD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBDD8: nop

    // 0x800BBDDC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800BBDE0:
    // 0x800BBDE0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BBDE4: nop

    // 0x800BBDE8: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x800BBDEC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BBDF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BBDF4: b           L_800BBE40
    // 0x800BBDF8: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
        goto L_800BBE40;
    // 0x800BBDF8: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
L_800BBDFC:
    // 0x800BBDFC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE00: nop

    // 0x800BBE04: lbu         $t2, 0xD($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XD);
    // 0x800BBE08: nop

    // 0x800BBE0C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800BBE10: bgez        $t2, L_800BBE28
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BBE14: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BBE28;
    }
    // 0x800BBE14: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBE18: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBE1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BBE20: nop

    // 0x800BBE24: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_800BBE28:
    // 0x800BBE28: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BBE2C: nop

    // 0x800BBE30: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x800BBE34: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE38: nop

    // 0x800BBE3C: sb          $zero, 0x5($t4)
    MEM_B(0X5, ctx->r12) = 0;
L_800BBE40:
    // 0x800BBE40: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE44: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800BBE48: lhu         $t6, 0x6($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X6);
    // 0x800BBE4C: nop

    // 0x800BBE50: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBE54: mflo        $t8
    ctx->r24 = lo;
    // 0x800BBE58: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800BBE5C: nop

    // 0x800BBE60: b           L_800BC480
    // 0x800BBE64: nop

        goto L_800BC480;
    // 0x800BBE64: nop

L_800BBE68:
    // 0x800BBE68: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE6C: nop

    // 0x800BBE70: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x800BBE74: nop

    // 0x800BBE78: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x800BBE7C: sh          $t9, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r25;
    // 0x800BBE80: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE84: nop

    // 0x800BBE88: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800BBE8C: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x800BBE90: nop

    // 0x800BBE94: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BBE98: beq         $at, $zero, L_800BBEAC
    if (ctx->r1 == 0) {
        // 0x800BBE9C: nop

            goto L_800BBEAC;
    }
    // 0x800BBE9C: nop

    // 0x800BBEA0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BBEA4: nop

    // 0x800BBEA8: sh          $zero, 0x8($t7)
    MEM_H(0X8, ctx->r15) = 0;
L_800BBEAC:
    // 0x800BBEAC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BBEB0: nop

    // 0x800BBEB4: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x800BBEB8: nop

    // 0x800BBEBC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800BBEC0: bgez        $t6, L_800BBED8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800BBEC4: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BBED8;
    }
    // 0x800BBEC4: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BBEC8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBECC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BBED0: nop

    // 0x800BBED4: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800BBED8:
    // 0x800BBED8: lhu         $t8, 0x6($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X6);
    // 0x800BBEDC: nop

    // 0x800BBEE0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800BBEE4: bgez        $t8, L_800BBEFC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800BBEE8: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BBEFC;
    }
    // 0x800BBEE8: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBEEC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBEF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BBEF4: nop

    // 0x800BBEF8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800BBEFC:
    // 0x800BBEFC: nop

    // 0x800BBF00: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BBF04: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800BBF08: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BBF0C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBF10: lbu         $t9, 0xD($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0XD);
    // 0x800BBF14: nop

    // 0x800BBF18: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800BBF1C: bgez        $t9, L_800BBF34
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BBF20: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BBF34;
    }
    // 0x800BBF20: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBF24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBF28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBF2C: nop

    // 0x800BBF30: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800BBF34:
    // 0x800BBF34: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BBF38: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800BBF3C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BBF40: nop

    // 0x800BBF44: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x800BBF48: nop

    // 0x800BBF4C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800BBF50: bgez        $t2, L_800BBF68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BBF54: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BBF68;
    }
    // 0x800BBF54: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BBF58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBF5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBF60: nop

    // 0x800BBF64: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_800BBF68:
    // 0x800BBF68: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBF6C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BBF70: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800BBF74: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x800BBF78: b           L_800BC480
    // 0x800BBF7C: nop

        goto L_800BC480;
    // 0x800BBF7C: nop

L_800BBF80:
    // 0x800BBF80: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BBF84: nop

    // 0x800BBF88: lhu         $t7, 0x8($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X8);
    // 0x800BBF8C: nop

    // 0x800BBF90: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800BBF94: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
    // 0x800BBF98: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BBF9C: nop

    // 0x800BBFA0: lhu         $t8, 0x8($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X8);
    // 0x800BBFA4: lhu         $t1, 0x6($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X6);
    // 0x800BBFA8: nop

    // 0x800BBFAC: slt         $at, $t1, $t8
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BBFB0: beq         $at, $zero, L_800BBFC4
    if (ctx->r1 == 0) {
        // 0x800BBFB4: nop

            goto L_800BBFC4;
    }
    // 0x800BBFB4: nop

    // 0x800BBFB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBFBC: nop

    // 0x800BBFC0: sh          $zero, 0x8($t9)
    MEM_H(0X8, ctx->r25) = 0;
L_800BBFC4:
    // 0x800BBFC4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BBFC8: nop

    // 0x800BBFCC: lhu         $t2, 0x8($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X8);
    // 0x800BBFD0: nop

    // 0x800BBFD4: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800BBFD8: bgez        $t2, L_800BBFF0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BBFDC: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BBFF0;
    }
    // 0x800BBFDC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBFE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBFE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBFE8: nop

    // 0x800BBFEC: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_800BBFF0:
    // 0x800BBFF0: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x800BBFF4: nop

    // 0x800BBFF8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800BBFFC: bgez        $t3, L_800BC014
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BC000: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BC014;
    }
    // 0x800BC000: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC004: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BC00C: nop

    // 0x800BC010: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_800BC014:
    // 0x800BC014: nop

    // 0x800BC018: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800BC01C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800BC020: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BC024: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC028: lbu         $t6, 0xD($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XD);
    // 0x800BC02C: nop

    // 0x800BC030: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800BC034: bgez        $t6, L_800BC04C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800BC038: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BC04C;
    }
    // 0x800BC038: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC03C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC040: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BC044: nop

    // 0x800BC048: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_800BC04C:
    // 0x800BC04C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800BC050: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800BC054: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BC058: nop

    // 0x800BC05C: lbu         $t5, 0xC($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XC);
    // 0x800BC060: nop

    // 0x800BC064: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800BC068: bgez        $t5, L_800BC080
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800BC06C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BC080;
    }
    // 0x800BC06C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BC070: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC074: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BC078: nop

    // 0x800BC07C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800BC080:
    // 0x800BC080: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC084: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BC088: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800BC08C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800BC090: b           L_800BC480
    // 0x800BC094: nop

        goto L_800BC480;
    // 0x800BC094: nop

L_800BC098:
    // 0x800BC098: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BC09C: nop

    // 0x800BC0A0: lhu         $t9, 0x8($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X8);
    // 0x800BC0A4: nop

    // 0x800BC0A8: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800BC0AC: sh          $t2, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r10;
    // 0x800BC0B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC0B4: nop

    // 0x800BC0B8: lhu         $t3, 0x8($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X8);
    // 0x800BC0BC: lhu         $t7, 0x6($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X6);
    // 0x800BC0C0: nop

    // 0x800BC0C4: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC0C8: bne         $at, $zero, L_800BC0DC
    if (ctx->r1 != 0) {
        // 0x800BC0CC: nop

            goto L_800BC0DC;
    }
    // 0x800BC0CC: nop

    // 0x800BC0D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC0D4: nop

    // 0x800BC0D8: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
L_800BC0DC:
    // 0x800BC0DC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BC0E0: nop

    // 0x800BC0E4: lhu         $t5, 0x8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X8);
    // 0x800BC0E8: nop

    // 0x800BC0EC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800BC0F0: bgez        $t5, L_800BC108
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800BC0F4: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800BC108;
    }
    // 0x800BC0F4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BC0F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC0FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BC100: nop

    // 0x800BC104: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_800BC108:
    // 0x800BC108: lhu         $t8, 0x6($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X6);
    // 0x800BC10C: nop

    // 0x800BC110: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800BC114: bgez        $t8, L_800BC12C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800BC118: cvt.s.w     $f8, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BC12C;
    }
    // 0x800BC118: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC11C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BC124: nop

    // 0x800BC128: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800BC12C:
    // 0x800BC12C: nop

    // 0x800BC130: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BC134: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800BC138: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BC13C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC140: lwc1        $f5, -0x230($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X230);
    // 0x800BC144: lwc1        $f4, -0x22C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X22C);
    // 0x800BC148: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800BC14C: mul.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x800BC150: jal         0x800CAE10
    // 0x800BC154: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BC154: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800BC158: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BC15C: nop

    // 0x800BC160: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800BC164: nop

    // 0x800BC168: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800BC16C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800BC170: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800BC174: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC178: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800BC17C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BC180: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BC184: nop

    // 0x800BC188: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800BC18C: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x800BC190: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800BC194: jal         0x800CADC0
    // 0x800BC198: nop

    alCents2Ratio(rdram, ctx);
        goto after_2;
    // 0x800BC198: nop

    after_2:
    // 0x800BC19C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800BC1A0: nop

    // 0x800BC1A4: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x800BC1A8: b           L_800BC480
    // 0x800BC1AC: nop

        goto L_800BC480;
    // 0x800BC1AC: nop

L_800BC1B0:
    // 0x800BC1B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1B4: nop

    // 0x800BC1B8: lbu         $t3, 0x5($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X5);
    // 0x800BC1BC: nop

    // 0x800BC1C0: bne         $t3, $zero, L_800BC1E8
    if (ctx->r11 != 0) {
        // 0x800BC1C4: nop

            goto L_800BC1E8;
    }
    // 0x800BC1C4: nop

    // 0x800BC1C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BC1D0: sb          $t7, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r15;
    // 0x800BC1D4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1D8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800BC1DC: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800BC1E0: b           L_800BC208
    // 0x800BC1E4: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
        goto L_800BC208;
    // 0x800BC1E4: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
L_800BC1E8:
    // 0x800BC1E8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1EC: nop

    // 0x800BC1F0: sb          $zero, 0x5($t8)
    MEM_B(0X5, ctx->r24) = 0;
    // 0x800BC1F4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1F8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800BC1FC: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800BC200: nop

    // 0x800BC204: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
L_800BC208:
    // 0x800BC208: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC20C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BC210: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x800BC214: nop

    // 0x800BC218: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC21C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC220: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800BC224: nop

    // 0x800BC228: b           L_800BC480
    // 0x800BC22C: nop

        goto L_800BC480;
    // 0x800BC22C: nop

L_800BC230:
    // 0x800BC230: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC234: nop

    // 0x800BC238: lhu         $t5, 0x8($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X8);
    // 0x800BC23C: nop

    // 0x800BC240: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800BC244: sh          $t4, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r12;
    // 0x800BC248: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BC24C: nop

    // 0x800BC250: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800BC254: lhu         $t2, 0x6($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X6);
    // 0x800BC258: nop

    // 0x800BC25C: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BC260: beq         $at, $zero, L_800BC274
    if (ctx->r1 == 0) {
        // 0x800BC264: nop

            goto L_800BC274;
    }
    // 0x800BC264: nop

    // 0x800BC268: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC26C: nop

    // 0x800BC270: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
L_800BC274:
    // 0x800BC274: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BC278: nop

    // 0x800BC27C: lhu         $t3, 0x8($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X8);
    // 0x800BC280: nop

    // 0x800BC284: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800BC288: bgez        $t3, L_800BC2A0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BC28C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BC2A0;
    }
    // 0x800BC28C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BC290: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC294: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BC298: nop

    // 0x800BC29C: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_800BC2A0:
    // 0x800BC2A0: lhu         $t7, 0x6($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X6);
    // 0x800BC2A4: nop

    // 0x800BC2A8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800BC2AC: bgez        $t7, L_800BC2C4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800BC2B0: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BC2C4;
    }
    // 0x800BC2B0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC2B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC2B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BC2BC: nop

    // 0x800BC2C0: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_800BC2C4:
    // 0x800BC2C4: nop

    // 0x800BC2C8: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BC2CC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800BC2D0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BC2D4: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC2D8: lw          $t4, 0x10($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X10);
    // 0x800BC2DC: nop

    // 0x800BC2E0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800BC2E4: nop

    // 0x800BC2E8: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC2EC: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800BC2F0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800BC2F4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC2F8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC2FC: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800BC300: nop

    // 0x800BC304: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BC308: nop

    // 0x800BC30C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC310: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800BC314: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800BC318: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BC31C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC320: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BC324: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BC328: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BC32C: nop

    // 0x800BC330: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800BC334: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800BC338: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BC33C: jal         0x800CADC0
    // 0x800BC340: nop

    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x800BC340: nop

    after_3:
    // 0x800BC344: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800BC348: nop

    // 0x800BC34C: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x800BC350: b           L_800BC480
    // 0x800BC354: nop

        goto L_800BC480;
    // 0x800BC354: nop

L_800BC358:
    // 0x800BC358: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC35C: nop

    // 0x800BC360: lhu         $t3, 0x8($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X8);
    // 0x800BC364: nop

    // 0x800BC368: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x800BC36C: sh          $t1, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r9;
    // 0x800BC370: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BC374: nop

    // 0x800BC378: lhu         $t5, 0x8($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X8);
    // 0x800BC37C: lhu         $t4, 0x6($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X6);
    // 0x800BC380: nop

    // 0x800BC384: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800BC388: beq         $at, $zero, L_800BC39C
    if (ctx->r1 == 0) {
        // 0x800BC38C: nop

            goto L_800BC39C;
    }
    // 0x800BC38C: nop

    // 0x800BC390: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC394: nop

    // 0x800BC398: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
L_800BC39C:
    // 0x800BC39C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BC3A0: nop

    // 0x800BC3A4: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800BC3A8: nop

    // 0x800BC3AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BC3B0: bgez        $t9, L_800BC3C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BC3B4: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BC3C8;
    }
    // 0x800BC3B4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC3B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC3BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BC3C0: nop

    // 0x800BC3C4: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_800BC3C8:
    // 0x800BC3C8: lhu         $t2, 0x6($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X6);
    // 0x800BC3CC: nop

    // 0x800BC3D0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800BC3D4: bgez        $t2, L_800BC3EC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BC3D8: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BC3EC;
    }
    // 0x800BC3D8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BC3DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC3E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BC3E4: nop

    // 0x800BC3E8: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800BC3EC:
    // 0x800BC3EC: nop

    // 0x800BC3F0: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BC3F4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800BC3F8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800BC3FC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC400: lw          $t1, 0x10($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X10);
    // 0x800BC404: nop

    // 0x800BC408: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800BC40C: nop

    // 0x800BC410: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BC414: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800BC418: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800BC41C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC420: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC424: lw          $t7, 0xC($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XC);
    // 0x800BC428: nop

    // 0x800BC42C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BC430: nop

    // 0x800BC434: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC438: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800BC43C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x800BC440: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800BC444: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC448: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800BC44C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BC450: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BC454: nop

    // 0x800BC458: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BC45C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800BC460: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800BC464: jal         0x800CADC0
    // 0x800BC468: nop

    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x800BC468: nop

    after_4:
    // 0x800BC46C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800BC470: nop

    // 0x800BC474: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x800BC478: b           L_800BC480
    // 0x800BC47C: nop

        goto L_800BC480;
    // 0x800BC47C: nop

L_800BC480:
    // 0x800BC480: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800BC484: b           L_800BC494
    // 0x800BC488: nop

        goto L_800BC494;
    // 0x800BC488: nop

    // 0x800BC48C: b           L_800BC494
    // 0x800BC490: nop

        goto L_800BC494;
    // 0x800BC490: nop

L_800BC494:
    // 0x800BC494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BC49C: jr          $ra
    // 0x800BC4A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800BC4A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void AudioDriver_StopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC4A4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BC4A8: lw          $t6, -0x1D90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1D90);
    // 0x800BC4AC: nop

    // 0x800BC4B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BC4B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BC4B8: sw          $a0, -0x1D90($at)
    MEM_W(-0X1D90, ctx->r1) = ctx->r4;
    // 0x800BC4BC: jr          $ra
    // 0x800BC4C0: nop

    return;
    // 0x800BC4C0: nop

    // 0x800BC4C4: jr          $ra
    // 0x800BC4C8: nop

    return;
    // 0x800BC4C8: nop

;}
RECOMP_FUNC void AudioDriver_SetupOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC4CC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BC4D0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BC4D4: addiu       $t6, $t6, -0x1D88
    ctx->r14 = ADD32(ctx->r14, -0X1D88);
    // 0x800BC4D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BC4DC: sw          $t6, -0x1D90($at)
    MEM_W(-0X1D90, ctx->r1) = ctx->r14;
    // 0x800BC4E0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800BC4E4: addiu       $t7, $t7, -0x1D88
    ctx->r15 = ADD32(ctx->r15, -0X1D88);
    // 0x800BC4E8: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800BC4EC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800BC4F0:
    // 0x800BC4F0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800BC4F4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800BC4F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BC4FC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800BC500: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BC504: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800BC508: addiu       $t0, $t9, 0x14
    ctx->r8 = ADD32(ctx->r25, 0X14);
    // 0x800BC50C: addiu       $t1, $t1, -0x1D88
    ctx->r9 = ADD32(ctx->r9, -0X1D88);
    // 0x800BC510: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800BC514: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800BC518: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800BC51C: nop

    // 0x800BC520: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800BC524: nop

    // 0x800BC528: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x800BC52C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BC530: nop

    // 0x800BC534: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BC538: slti        $at, $t7, 0x27
    ctx->r1 = SIGNED(ctx->r15) < 0X27 ? 1 : 0;
    // 0x800BC53C: bne         $at, $zero, L_800BC4F0
    if (ctx->r1 != 0) {
        // 0x800BC540: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800BC4F0;
    }
    // 0x800BC540: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800BC544: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BC548: nop

    // 0x800BC54C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BC550: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800BC554: addiu       $t9, $t9, -0x49C0
    ctx->r25 = ADD32(ctx->r25, -0X49C0);
    // 0x800BC558: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x800BC55C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800BC560: addiu       $t0, $t0, -0x4444
    ctx->r8 = ADD32(ctx->r8, -0X4444);
    // 0x800BC564: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x800BC568: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800BC56C: addiu       $t1, $t1, -0x3B5C
    ctx->r9 = ADD32(ctx->r9, -0X3B5C);
    // 0x800BC570: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x800BC574: b           L_800BC57C
    // 0x800BC578: nop

        goto L_800BC57C;
    // 0x800BC578: nop

L_800BC57C:
    // 0x800BC57C: jr          $ra
    // 0x800BC580: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BC580: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800BC584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC584: nop

    // 0x800BC588: nop

    // 0x800BC58C: nop

;}
RECOMP_FUNC void AudioDmaCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC590: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BC594: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC598: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BC59C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BC5A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BC5A4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BC5A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BC5AC: jal         0x800CAFD0
    // 0x800BC5B0: nop

    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800BC5B0: nop

    after_0:
    // 0x800BC5B4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800BC5B8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800BC5BC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BC5C0: addiu       $t8, $t8, -0x1E48
    ctx->r24 = ADD32(ctx->r24, -0X1E48);
    // 0x800BC5C4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BC5C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800BC5CC: addiu       $a0, $a0, -0x1E28
    ctx->r4 = ADD32(ctx->r4, -0X1E28);
    // 0x800BC5D0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800BC5D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BC5D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BC5DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BC5E0: jal         0x800C81D0
    // 0x800BC5E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x800BC5E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x800BC5E8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BC5EC: addiu       $a0, $a0, -0x1E48
    ctx->r4 = ADD32(ctx->r4, -0X1E48);
    // 0x800BC5F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BC5F4: jal         0x800C4C40
    // 0x800BC5F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800BC5F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800BC5FC: b           L_800BC604
    // 0x800BC600: nop

        goto L_800BC604;
    // 0x800BC600: nop

L_800BC604:
    // 0x800BC604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BC608: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BC60C: jr          $ra
    // 0x800BC610: nop

    return;
    // 0x800BC610: nop

;}
RECOMP_FUNC void func_800BC614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC614: nop

    // 0x800BC618: nop

    // 0x800BC61C: nop

;}
RECOMP_FUNC void SysMem_HeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC620: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BC624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC628: jal         0x800C41A0
    // 0x800BC62C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800BC62C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800BC630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BC634: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800BC638: addiu       $t6, $t6, 0x5800
    ctx->r14 = ADD32(ctx->r14, 0X5800);
    // 0x800BC63C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC640: sw          $t6, 0x25DC($at)
    MEM_W(0X25DC, ctx->r1) = ctx->r14;
    // 0x800BC644: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BC648: lw          $t7, 0x25DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25DC);
    // 0x800BC64C: nop

    // 0x800BC650: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x800BC654: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BC658: lw          $t9, 0x25DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25DC);
    // 0x800BC65C: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x800BC660: ori         $t8, $t8, 0xB4FF
    ctx->r24 = ctx->r24 | 0XB4FF;
    // 0x800BC664: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x800BC668: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BC66C: lw          $t0, 0x25DC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X25DC);
    // 0x800BC670: nop

    // 0x800BC674: sw          $t0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r8;
    // 0x800BC678: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BC67C: lw          $t1, 0x25DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X25DC);
    // 0x800BC680: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800BC684: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800BC688: addiu       $t4, $t4, 0x5800
    ctx->r12 = ADD32(ctx->r12, 0X5800);
    // 0x800BC68C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800BC690: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BC694: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BC698: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BC69C: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BC6A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC6A4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800BC6A8: nop

    // 0x800BC6AC: sw          $t7, 0x25E8($at)
    MEM_W(0X25E8, ctx->r1) = ctx->r15;
    // 0x800BC6B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC6B4: sw          $zero, 0x2610($at)
    MEM_W(0X2610, ctx->r1) = 0;
    // 0x800BC6B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC6BC: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x800BC6C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC6C4: sw          $zero, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = 0;
    // 0x800BC6C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC6CC: jal         0x800C41A0
    // 0x800BC6D0: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800BC6D0: nop

    after_1:
    // 0x800BC6D4: b           L_800BC6DC
    // 0x800BC6D8: nop

        goto L_800BC6DC;
    // 0x800BC6D8: nop

L_800BC6DC:
    // 0x800BC6DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC6E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BC6E4: jr          $ra
    // 0x800BC6E8: nop

    return;
    // 0x800BC6E8: nop

;}
RECOMP_FUNC void SysMem_HeapAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC6EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC6F0: addiu       $t6, $a0, 0xF
    ctx->r14 = ADD32(ctx->r4, 0XF);
    // 0x800BC6F4: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x800BC6F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BC6FC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800BC700: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BC704: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BC708: lw          $t0, 0x25E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X25E8);
    // 0x800BC70C: lw          $t9, 0x25DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25DC);
    // 0x800BC710: nop

    // 0x800BC714: beq         $t9, $t0, L_800BC900
    if (ctx->r25 == ctx->r8) {
        // 0x800BC718: sw          $t9, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r25;
            goto L_800BC900;
    }
    // 0x800BC718: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_800BC71C:
    // 0x800BC71C: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800BC720: nop

    // 0x800BC724: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800BC728: nop

    // 0x800BC72C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800BC730: beq         $t3, $zero, L_800BC740
    if (ctx->r11 == 0) {
        // 0x800BC734: nop

            goto L_800BC740;
    }
    // 0x800BC734: nop

    // 0x800BC738: b           L_800BC8DC
    // 0x800BC73C: nop

        goto L_800BC8DC;
    // 0x800BC73C: nop

L_800BC740:
    // 0x800BC740: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800BC744: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800BC748: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800BC74C: nop

    // 0x800BC750: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x800BC754: bne         $at, $zero, L_800BC8DC
    if (ctx->r1 != 0) {
        // 0x800BC758: nop

            goto L_800BC8DC;
    }
    // 0x800BC758: nop

    // 0x800BC75C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800BC760: nop

    // 0x800BC764: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800BC768: nop

    // 0x800BC76C: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800BC770: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800BC774: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800BC778: nop

    // 0x800BC77C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x800BC780: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800BC784: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800BC788: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800BC78C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800BC790: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800BC794: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BC798: nop

    // 0x800BC79C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800BC7A0: nop

    // 0x800BC7A4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800BC7A8: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x800BC7AC: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7B0: nop

    // 0x800BC7B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800BC7B8: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7BC: nop

    // 0x800BC7C0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800BC7C4: nop

    // 0x800BC7C8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800BC7CC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800BC7D0: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7D4: nop

    // 0x800BC7D8: beq         $t1, $t2, L_800BC8D0
    if (ctx->r9 == ctx->r10) {
        // 0x800BC7DC: nop

            goto L_800BC8D0;
    }
    // 0x800BC7DC: nop

    // 0x800BC7E0: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x800BC7E4: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7E8: nop

    // 0x800BC7EC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800BC7F0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800BC7F4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7F8: nop

    // 0x800BC7FC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800BC800: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800BC804: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800BC808: nop

    // 0x800BC80C: subu        $t9, $t5, $t8
    ctx->r25 = SUB32(ctx->r13, ctx->r24);
    // 0x800BC810: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x800BC814: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x800BC818: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800BC81C: nop

    // 0x800BC820: sw          $zero, 0xC($t1)
    MEM_W(0XC, ctx->r9) = 0;
    // 0x800BC824: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800BC828: nop

    // 0x800BC82C: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x800BC830: nop

    // 0x800BC834: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800BC838: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BC83C: lw          $t6, 0x25E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25E8);
    // 0x800BC840: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800BC844: nop

    // 0x800BC848: beq         $t3, $t6, L_800BC8D0
    if (ctx->r11 == ctx->r14) {
        // 0x800BC84C: nop

            goto L_800BC8D0;
    }
    // 0x800BC84C: nop

    // 0x800BC850: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800BC854: nop

    // 0x800BC858: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x800BC85C: nop

    // 0x800BC860: andi        $t9, $t5, 0x1
    ctx->r25 = ctx->r13 & 0X1;
    // 0x800BC864: beq         $t9, $zero, L_800BC87C
    if (ctx->r25 == 0) {
        // 0x800BC868: nop

            goto L_800BC87C;
    }
    // 0x800BC868: nop

    // 0x800BC86C: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800BC870: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800BC874: b           L_800BC8D0
    // 0x800BC878: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
        goto L_800BC8D0;
    // 0x800BC878: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_800BC87C:
    // 0x800BC87C: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800BC880: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800BC884: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800BC888: nop

    // 0x800BC88C: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800BC890: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800BC894: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800BC898: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x800BC89C: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x800BC8A0: nop

    // 0x800BC8A4: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x800BC8A8: sw          $t9, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r25;
    // 0x800BC8AC: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800BC8B0: nop

    // 0x800BC8B4: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x800BC8B8: nop

    // 0x800BC8BC: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800BC8C0: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800BC8C4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800BC8C8: nop

    // 0x800BC8CC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_800BC8D0:
    // 0x800BC8D0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800BC8D4: b           L_800BC910
    // 0x800BC8D8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
        goto L_800BC910;
    // 0x800BC8D8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_800BC8DC:
    // 0x800BC8DC: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800BC8E0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BC8E4: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800BC8E8: lw          $t5, 0x25E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X25E8);
    // 0x800BC8EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800BC8F0: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800BC8F4: nop

    // 0x800BC8F8: bne         $t6, $t5, L_800BC71C
    if (ctx->r14 != ctx->r13) {
        // 0x800BC8FC: nop

            goto L_800BC71C;
    }
    // 0x800BC8FC: nop

L_800BC900:
    // 0x800BC900: b           L_800BC910
    // 0x800BC904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BC910;
    // 0x800BC904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BC908: b           L_800BC910
    // 0x800BC90C: nop

        goto L_800BC910;
    // 0x800BC90C: nop

L_800BC910:
    // 0x800BC910: jr          $ra
    // 0x800BC914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800BC914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
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
RECOMP_FUNC void SysMem_Free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC980: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BC984: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x800BC988: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800BC98C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800BC990: nop

    // 0x800BC994: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800BC998: nop

    // 0x800BC99C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BC9A0: bne         $t9, $zero, L_800BC9B0
    if (ctx->r25 != 0) {
        // 0x800BC9A4: nop

            goto L_800BC9B0;
    }
    // 0x800BC9A4: nop

    // 0x800BC9A8: b           L_800BCB08
    // 0x800BC9AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BCB08;
    // 0x800BC9AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BC9B0:
    // 0x800BC9B0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800BC9B4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800BC9B8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800BC9BC: nop

    // 0x800BC9C0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800BC9C4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x800BC9C8: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800BC9CC: nop

    // 0x800BC9D0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800BC9D4: nop

    // 0x800BC9D8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800BC9DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BC9E0: lw          $t6, 0x25E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25E8);
    // 0x800BC9E4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800BC9E8: nop

    // 0x800BC9EC: beq         $t5, $t6, L_800BCA5C
    if (ctx->r13 == ctx->r14) {
        // 0x800BC9F0: nop

            goto L_800BCA5C;
    }
    // 0x800BC9F0: nop

    // 0x800BC9F4: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x800BC9F8: nop

    // 0x800BC9FC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800BCA00: bne         $t8, $zero, L_800BCA5C
    if (ctx->r24 != 0) {
        // 0x800BCA04: nop

            goto L_800BCA5C;
    }
    // 0x800BCA04: nop

    // 0x800BCA08: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800BCA0C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA10: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x800BCA14: nop

    // 0x800BCA18: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800BCA1C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA20: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800BCA24: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x800BCA28: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x800BCA2C: nop

    // 0x800BCA30: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x800BCA34: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
    // 0x800BCA38: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA3C: nop

    // 0x800BCA40: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800BCA44: nop

    // 0x800BCA48: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800BCA4C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA50: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800BCA54: nop

    // 0x800BCA58: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_800BCA5C:
    // 0x800BCA5C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA60: nop

    // 0x800BCA64: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800BCA68: nop

    // 0x800BCA6C: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x800BCA70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCA74: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCA78: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA7C: nop

    // 0x800BCA80: beq         $t3, $t6, L_800BCAF8
    if (ctx->r11 == ctx->r14) {
        // 0x800BCA84: nop

            goto L_800BCAF8;
    }
    // 0x800BCA84: nop

    // 0x800BCA88: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800BCA8C: nop

    // 0x800BCA90: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x800BCA94: nop

    // 0x800BCA98: andi        $t7, $t0, 0x1
    ctx->r15 = ctx->r8 & 0X1;
    // 0x800BCA9C: bne         $t7, $zero, L_800BCAF8
    if (ctx->r15 != 0) {
        // 0x800BCAA0: nop

            goto L_800BCAF8;
    }
    // 0x800BCAA0: nop

    // 0x800BCAA4: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800BCAA8: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800BCAAC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800BCAB0: nop

    // 0x800BCAB4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800BCAB8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800BCABC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800BCAC0: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800BCAC4: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x800BCAC8: nop

    // 0x800BCACC: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x800BCAD0: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x800BCAD4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800BCAD8: nop

    // 0x800BCADC: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x800BCAE0: nop

    // 0x800BCAE4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800BCAE8: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800BCAEC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800BCAF0: nop

    // 0x800BCAF4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_800BCAF8:
    // 0x800BCAF8: b           L_800BCB08
    // 0x800BCAFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BCB08;
    // 0x800BCAFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BCB00: b           L_800BCB08
    // 0x800BCB04: nop

        goto L_800BCB08;
    // 0x800BCB04: nop

L_800BCB08:
    // 0x800BCB08: jr          $ra
    // 0x800BCB0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BCB0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800BCB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCB10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCB14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCB18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BCB1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BCB20: jal         0x800BCCE4
    // 0x800BCB24: nop

    func_800BCCE4(rdram, ctx);
        goto after_0;
    // 0x800BCB24: nop

    after_0:
    // 0x800BCB28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BCB2C: jal         0x800BC980
    // 0x800BCB30: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800BCB30: nop

    after_1:
    // 0x800BCB34: b           L_800BCB44
    // 0x800BCB38: nop

        goto L_800BCB44;
    // 0x800BCB38: nop

    // 0x800BCB3C: b           L_800BCB44
    // 0x800BCB40: nop

        goto L_800BCB44;
    // 0x800BCB40: nop

L_800BCB44:
    // 0x800BCB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCB48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BCB4C: jr          $ra
    // 0x800BCB50: nop

    return;
    // 0x800BCB50: nop

;}
RECOMP_FUNC void func_800BCB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCB54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BCB58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCB5C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCB60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCB64: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCB68: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCB6C: nop

    // 0x800BCB70: beq         $t6, $t7, L_800BCBE0
    if (ctx->r14 == ctx->r15) {
        // 0x800BCB74: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800BCBE0;
    }
    // 0x800BCB74: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800BCB78:
    // 0x800BCB78: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCB7C: nop

    // 0x800BCB80: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BCB84: nop

    // 0x800BCB88: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800BCB8C: bne         $t0, $zero, L_800BCB9C
    if (ctx->r8 != 0) {
        // 0x800BCB90: nop

            goto L_800BCB9C;
    }
    // 0x800BCB90: nop

    // 0x800BCB94: b           L_800BCBC4
    // 0x800BCB98: nop

        goto L_800BCBC4;
    // 0x800BCB98: nop

L_800BCB9C:
    // 0x800BCB9C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCBA0: nop

    // 0x800BCBA4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800BCBA8: nop

    // 0x800BCBAC: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800BCBB0: bne         $t3, $zero, L_800BCBC4
    if (ctx->r11 != 0) {
        // 0x800BCBB4: nop

            goto L_800BCBC4;
    }
    // 0x800BCBB4: nop

    // 0x800BCBB8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCBBC: jal         0x800BC980
    // 0x800BCBC0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800BCBC0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
L_800BCBC4:
    // 0x800BCBC4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCBC8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCBCC: lw          $t6, 0x25E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25E8);
    // 0x800BCBD0: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800BCBD4: nop

    // 0x800BCBD8: bne         $t5, $t6, L_800BCB78
    if (ctx->r13 != ctx->r14) {
        // 0x800BCBDC: sw          $t5, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r13;
            goto L_800BCB78;
    }
    // 0x800BCBDC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
L_800BCBE0:
    // 0x800BCBE0: b           L_800BCBE8
    // 0x800BCBE4: nop

        goto L_800BCBE8;
    // 0x800BCBE4: nop

L_800BCBE8:
    // 0x800BCBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCBEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BCBF0: jr          $ra
    // 0x800BCBF4: nop

    return;
    // 0x800BCBF4: nop

;}
RECOMP_FUNC void func_800BCBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCBF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BCBFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCC00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCC04: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCC08: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCC0C: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCC10: nop

    // 0x800BCC14: beq         $t6, $t7, L_800BCC74
    if (ctx->r14 == ctx->r15) {
        // 0x800BCC18: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800BCC74;
    }
    // 0x800BCC18: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800BCC1C:
    // 0x800BCC1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC20: nop

    // 0x800BCC24: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BCC28: nop

    // 0x800BCC2C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800BCC30: bne         $t0, $zero, L_800BCC40
    if (ctx->r8 != 0) {
        // 0x800BCC34: nop

            goto L_800BCC40;
    }
    // 0x800BCC34: nop

    // 0x800BCC38: b           L_800BCC58
    // 0x800BCC3C: nop

        goto L_800BCC58;
    // 0x800BCC3C: nop

L_800BCC40:
    // 0x800BCC40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC44: jal         0x800BCCE4
    // 0x800BCC48: nop

    func_800BCCE4(rdram, ctx);
        goto after_0;
    // 0x800BCC48: nop

    after_0:
    // 0x800BCC4C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC50: jal         0x800BC980
    // 0x800BCC54: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800BCC54: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
L_800BCC58:
    // 0x800BCC58: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC5C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BCC60: lw          $t3, 0x25E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X25E8);
    // 0x800BCC64: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800BCC68: nop

    // 0x800BCC6C: bne         $t2, $t3, L_800BCC1C
    if (ctx->r10 != ctx->r11) {
        // 0x800BCC70: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_800BCC1C;
    }
    // 0x800BCC70: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_800BCC74:
    // 0x800BCC74: b           L_800BCC7C
    // 0x800BCC78: nop

        goto L_800BCC7C;
    // 0x800BCC78: nop

L_800BCC7C:
    // 0x800BCC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCC80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BCC84: jr          $ra
    // 0x800BCC88: nop

    return;
    // 0x800BCC88: nop

;}
RECOMP_FUNC void SysMem_MarkHeap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCC8C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCC90: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x800BCC94: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BCC98: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800BCC9C: nop

    // 0x800BCCA0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800BCCA4: nop

    // 0x800BCCA8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BCCAC: bne         $t9, $zero, L_800BCCBC
    if (ctx->r25 != 0) {
        // 0x800BCCB0: nop

            goto L_800BCCBC;
    }
    // 0x800BCCB0: nop

    // 0x800BCCB4: b           L_800BCCDC
    // 0x800BCCB8: nop

        goto L_800BCCDC;
    // 0x800BCCB8: nop

L_800BCCBC:
    // 0x800BCCBC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800BCCC0: nop

    // 0x800BCCC4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800BCCC8: nop

    // 0x800BCCCC: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800BCCD0: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x800BCCD4: b           L_800BCCDC
    // 0x800BCCD8: nop

        goto L_800BCCDC;
    // 0x800BCCD8: nop

L_800BCCDC:
    // 0x800BCCDC: jr          $ra
    // 0x800BCCE0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCCE0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800BCCE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCCE4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCCE8: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x800BCCEC: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BCCF0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800BCCF4: nop

    // 0x800BCCF8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800BCCFC: nop

    // 0x800BCD00: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BCD04: bne         $t9, $zero, L_800BCD14
    if (ctx->r25 != 0) {
        // 0x800BCD08: nop

            goto L_800BCD14;
    }
    // 0x800BCD08: nop

    // 0x800BCD0C: b           L_800BCD34
    // 0x800BCD10: nop

        goto L_800BCD34;
    // 0x800BCD10: nop

L_800BCD14:
    // 0x800BCD14: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800BCD18: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800BCD1C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800BCD20: nop

    // 0x800BCD24: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800BCD28: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x800BCD2C: b           L_800BCD34
    // 0x800BCD30: nop

        goto L_800BCD34;
    // 0x800BCD30: nop

L_800BCD34:
    // 0x800BCD34: jr          $ra
    // 0x800BCD38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCD38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_GetUnlockedSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCD3C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCD40: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800BCD44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCD48: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x800BCD4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCD50: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCD54: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCD58: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCD5C: nop

    // 0x800BCD60: beq         $t6, $t7, L_800BCDD8
    if (ctx->r14 == ctx->r15) {
        // 0x800BCD64: sw          $t6, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r14;
            goto L_800BCDD8;
    }
    // 0x800BCD64: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
L_800BCD68:
    // 0x800BCD68: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCD6C: nop

    // 0x800BCD70: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BCD74: nop

    // 0x800BCD78: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800BCD7C: beq         $t0, $zero, L_800BCDBC
    if (ctx->r8 == 0) {
        // 0x800BCD80: nop

            goto L_800BCDBC;
    }
    // 0x800BCD80: nop

    // 0x800BCD84: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x800BCD88: bne         $t1, $zero, L_800BCDBC
    if (ctx->r9 != 0) {
        // 0x800BCD8C: nop

            goto L_800BCDBC;
    }
    // 0x800BCD8C: nop

    // 0x800BCD90: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800BCD94: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BCD98: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800BCD9C: nop

    // 0x800BCDA0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800BCDA4: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800BCDA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCDAC: lh          $t6, 0x2638($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2638);
    // 0x800BCDB0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCDB4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BCDB8: sh          $t7, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = ctx->r15;
L_800BCDBC:
    // 0x800BCDBC: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCDC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BCDC4: lw          $t9, 0x25E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25E8);
    // 0x800BCDC8: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x800BCDCC: nop

    // 0x800BCDD0: bne         $t0, $t9, L_800BCD68
    if (ctx->r8 != ctx->r25) {
        // 0x800BCDD4: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_800BCD68;
    }
    // 0x800BCDD4: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_800BCDD8:
    // 0x800BCDD8: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800BCDDC: nop

    // 0x800BCDE0: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800BCDE4: b           L_800BCDF4
    // 0x800BCDE8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800BCDF4;
    // 0x800BCDE8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800BCDEC: b           L_800BCDF4
    // 0x800BCDF0: nop

        goto L_800BCDF4;
    // 0x800BCDF0: nop

L_800BCDF4:
    // 0x800BCDF4: jr          $ra
    // 0x800BCDF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCDF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_GetLockedSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCDFC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCE00: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800BCE04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCE08: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x800BCE0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCE10: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCE14: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCE18: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCE1C: nop

    // 0x800BCE20: beq         $t6, $t7, L_800BCE98
    if (ctx->r14 == ctx->r15) {
        // 0x800BCE24: sw          $t6, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r14;
            goto L_800BCE98;
    }
    // 0x800BCE24: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
L_800BCE28:
    // 0x800BCE28: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCE2C: nop

    // 0x800BCE30: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BCE34: nop

    // 0x800BCE38: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800BCE3C: beq         $t0, $zero, L_800BCE7C
    if (ctx->r8 == 0) {
        // 0x800BCE40: nop

            goto L_800BCE7C;
    }
    // 0x800BCE40: nop

    // 0x800BCE44: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x800BCE48: beq         $t1, $zero, L_800BCE7C
    if (ctx->r9 == 0) {
        // 0x800BCE4C: nop

            goto L_800BCE7C;
    }
    // 0x800BCE4C: nop

    // 0x800BCE50: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800BCE54: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BCE58: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800BCE5C: nop

    // 0x800BCE60: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800BCE64: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800BCE68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCE6C: lh          $t6, 0x2638($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2638);
    // 0x800BCE70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCE74: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BCE78: sh          $t7, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = ctx->r15;
L_800BCE7C:
    // 0x800BCE7C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCE80: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BCE84: lw          $t9, 0x25E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25E8);
    // 0x800BCE88: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x800BCE8C: nop

    // 0x800BCE90: bne         $t0, $t9, L_800BCE28
    if (ctx->r8 != ctx->r25) {
        // 0x800BCE94: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_800BCE28;
    }
    // 0x800BCE94: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_800BCE98:
    // 0x800BCE98: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800BCE9C: nop

    // 0x800BCEA0: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800BCEA4: b           L_800BCEB4
    // 0x800BCEA8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800BCEB4;
    // 0x800BCEA8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800BCEAC: b           L_800BCEB4
    // 0x800BCEB0: nop

        goto L_800BCEB4;
    // 0x800BCEB0: nop

L_800BCEB4:
    // 0x800BCEB4: jr          $ra
    // 0x800BCEB8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCEB8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_GetFreeSpace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCEBC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BCEC0: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x800BCEC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCEC8: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x800BCECC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCED0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCED4: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCED8: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCEDC: nop

    // 0x800BCEE0: beq         $t6, $t7, L_800BCF54
    if (ctx->r14 == ctx->r15) {
        // 0x800BCEE4: sw          $t6, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r14;
            goto L_800BCF54;
    }
    // 0x800BCEE4: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
L_800BCEE8:
    // 0x800BCEE8: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800BCEEC: nop

    // 0x800BCEF0: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    // 0x800BCEF4: nop

    // 0x800BCEF8: sltiu       $t9, $a0, 0x1
    ctx->r25 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x800BCEFC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800BCF00: andi        $t0, $a0, 0x1
    ctx->r8 = ctx->r4 & 0X1;
    // 0x800BCF04: beq         $t0, $zero, L_800BCF38
    if (ctx->r8 == 0) {
        // 0x800BCF08: nop

            goto L_800BCF38;
    }
    // 0x800BCF08: nop

    // 0x800BCF0C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800BCF10: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800BCF14: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800BCF18: nop

    // 0x800BCF1C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800BCF20: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800BCF24: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BCF28: lh          $t5, 0x2638($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2638);
    // 0x800BCF2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCF30: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800BCF34: sh          $t6, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = ctx->r14;
L_800BCF38:
    // 0x800BCF38: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800BCF3C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BCF40: lw          $t9, 0x25E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25E8);
    // 0x800BCF44: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800BCF48: nop

    // 0x800BCF4C: bne         $t8, $t9, L_800BCEE8
    if (ctx->r24 != ctx->r25) {
        // 0x800BCF50: sw          $t8, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r24;
            goto L_800BCEE8;
    }
    // 0x800BCF50: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
L_800BCF54:
    // 0x800BCF54: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
    // 0x800BCF58: nop

    // 0x800BCF5C: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x800BCF60: b           L_800BCF70
    // 0x800BCF64: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800BCF70;
    // 0x800BCF64: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800BCF68: b           L_800BCF70
    // 0x800BCF6C: nop

        goto L_800BCF70;
    // 0x800BCF6C: nop

L_800BCF70:
    // 0x800BCF70: jr          $ra
    // 0x800BCF74: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BCF74: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800BCF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCF78: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCF7C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800BCF80: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800BCF84: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800BCF88: beq         $a1, $zero, L_800BCFBC
    if (ctx->r5 == 0) {
        // 0x800BCF8C: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_800BCFBC;
    }
    // 0x800BCF8C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800BCF90:
    // 0x800BCF90: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800BCF94: nop

    // 0x800BCF98: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BCF9C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800BCFA0: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800BCFA4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800BCFA8: nop

    // 0x800BCFAC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BCFB0: sltu        $at, $t1, $a1
    ctx->r1 = ctx->r9 < ctx->r5 ? 1 : 0;
    // 0x800BCFB4: bne         $at, $zero, L_800BCF90
    if (ctx->r1 != 0) {
        // 0x800BCFB8: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800BCF90;
    }
    // 0x800BCFB8: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_800BCFBC:
    // 0x800BCFBC: b           L_800BCFC4
    // 0x800BCFC0: nop

        goto L_800BCFC4;
    // 0x800BCFC0: nop

L_800BCFC4:
    // 0x800BCFC4: jr          $ra
    // 0x800BCFC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCFC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_Copy8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCFCC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCFD0: bne         $a2, $zero, L_800BCFE0
    if (ctx->r6 != 0) {
        // 0x800BCFD4: nop

            goto L_800BCFE0;
    }
    // 0x800BCFD4: nop

    // 0x800BCFD8: b           L_800BD030
    // 0x800BCFDC: nop

        goto L_800BD030;
    // 0x800BCFDC: nop

L_800BCFE0:
    // 0x800BCFE0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BCFE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BCFE8: blez        $a2, L_800BD028
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BCFEC: nop

            goto L_800BD028;
    }
    // 0x800BCFEC: nop

L_800BCFF0:
    // 0x800BCFF0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BCFF4: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCFF8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BCFFC: nop

    // 0x800BD000: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800BD004: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800BD008: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800BD00C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BD010: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BD014: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x800BD018: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800BD01C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD020: bgtz        $a2, L_800BCFF0
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD024: nop

            goto L_800BCFF0;
    }
    // 0x800BD024: nop

L_800BD028:
    // 0x800BD028: b           L_800BD030
    // 0x800BD02C: nop

        goto L_800BD030;
    // 0x800BD02C: nop

L_800BD030:
    // 0x800BD030: jr          $ra
    // 0x800BD034: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD034: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_Copy16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD038: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD03C: bne         $a2, $zero, L_800BD04C
    if (ctx->r6 != 0) {
        // 0x800BD040: nop

            goto L_800BD04C;
    }
    // 0x800BD040: nop

    // 0x800BD044: b           L_800BD09C
    // 0x800BD048: nop

        goto L_800BD09C;
    // 0x800BD048: nop

L_800BD04C:
    // 0x800BD04C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BD050: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BD054: blez        $a2, L_800BD094
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BD058: nop

            goto L_800BD094;
    }
    // 0x800BD058: nop

L_800BD05C:
    // 0x800BD05C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BD060: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BD064: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800BD068: nop

    // 0x800BD06C: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800BD070: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800BD074: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800BD078: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800BD07C: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x800BD080: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x800BD084: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800BD088: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD08C: bgtz        $a2, L_800BD05C
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD090: nop

            goto L_800BD05C;
    }
    // 0x800BD090: nop

L_800BD094:
    // 0x800BD094: b           L_800BD09C
    // 0x800BD098: nop

        goto L_800BD09C;
    // 0x800BD098: nop

L_800BD09C:
    // 0x800BD09C: jr          $ra
    // 0x800BD0A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD0A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_Copy32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD0A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD0A8: bne         $a2, $zero, L_800BD0B8
    if (ctx->r6 != 0) {
        // 0x800BD0AC: nop

            goto L_800BD0B8;
    }
    // 0x800BD0AC: nop

    // 0x800BD0B0: b           L_800BD108
    // 0x800BD0B4: nop

        goto L_800BD108;
    // 0x800BD0B4: nop

L_800BD0B8:
    // 0x800BD0B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BD0BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BD0C0: blez        $a2, L_800BD100
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BD0C4: nop

            goto L_800BD100;
    }
    // 0x800BD0C4: nop

L_800BD0C8:
    // 0x800BD0C8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BD0CC: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BD0D0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800BD0D4: nop

    // 0x800BD0D8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800BD0DC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800BD0E0: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800BD0E4: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x800BD0E8: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800BD0EC: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x800BD0F0: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800BD0F4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD0F8: bgtz        $a2, L_800BD0C8
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD0FC: nop

            goto L_800BD0C8;
    }
    // 0x800BD0FC: nop

L_800BD100:
    // 0x800BD100: b           L_800BD108
    // 0x800BD104: nop

        goto L_800BD108;
    // 0x800BD104: nop

L_800BD108:
    // 0x800BD108: jr          $ra
    // 0x800BD10C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD10C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_Copy64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD110: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD114: bne         $a2, $zero, L_800BD124
    if (ctx->r6 != 0) {
        // 0x800BD118: nop

            goto L_800BD124;
    }
    // 0x800BD118: nop

    // 0x800BD11C: b           L_800BD178
    // 0x800BD120: nop

        goto L_800BD178;
    // 0x800BD120: nop

L_800BD124:
    // 0x800BD124: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BD128: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BD12C: blez        $a2, L_800BD170
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BD130: nop

            goto L_800BD170;
    }
    // 0x800BD130: nop

L_800BD134:
    // 0x800BD134: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BD138: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800BD13C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800BD140: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800BD144: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800BD148: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800BD14C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BD150: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800BD154: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BD158: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800BD15C: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800BD160: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800BD164: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD168: bgtz        $a2, L_800BD134
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD16C: nop

            goto L_800BD134;
    }
    // 0x800BD16C: nop

L_800BD170:
    // 0x800BD170: b           L_800BD178
    // 0x800BD174: nop

        goto L_800BD178;
    // 0x800BD174: nop

L_800BD178:
    // 0x800BD178: jr          $ra
    // 0x800BD17C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD17C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_Bcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD180: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD184: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BD188: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BD18C: blez        $a2, L_800BD1E4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BD190: nop

            goto L_800BD1E4;
    }
    // 0x800BD190: nop

L_800BD194:
    // 0x800BD194: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BD198: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BD19C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD1A0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800BD1A4: nop

    // 0x800BD1A8: beq         $t7, $t9, L_800BD1B8
    if (ctx->r15 == ctx->r25) {
        // 0x800BD1AC: nop

            goto L_800BD1B8;
    }
    // 0x800BD1AC: nop

    // 0x800BD1B0: b           L_800BD1E4
    // 0x800BD1B4: nop

        goto L_800BD1E4;
    // 0x800BD1B4: nop

L_800BD1B8:
    // 0x800BD1B8: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800BD1BC: nop

    // 0x800BD1C0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BD1C4: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800BD1C8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BD1CC: nop

    // 0x800BD1D0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BD1D4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800BD1D8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD1DC: bgtz        $a2, L_800BD194
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD1E0: nop

            goto L_800BD194;
    }
    // 0x800BD1E0: nop

L_800BD1E4:
    // 0x800BD1E4: b           L_800BD1F4
    // 0x800BD1E8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800BD1F4;
    // 0x800BD1E8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800BD1EC: b           L_800BD1F4
    // 0x800BD1F0: nop

        goto L_800BD1F4;
    // 0x800BD1F0: nop

L_800BD1F4:
    // 0x800BD1F4: jr          $ra
    // 0x800BD1F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD1F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void SysMem_GetPhysicalAddressFromVirtual(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD1FC: subu        $t6, $a2, $a1
    ctx->r14 = SUB32(ctx->r6, ctx->r5);
    // 0x800BD200: jr          $ra
    // 0x800BD204: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x800BD204: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800BD208: jr          $ra
    // 0x800BD20C: nop

    return;
    // 0x800BD20C: nop

    // 0x800BD210: jr          $ra
    // 0x800BD214: nop

    return;
    // 0x800BD214: nop

;}
RECOMP_FUNC void SysMem_DmaCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD218: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BD21C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BD220: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800BD224: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800BD228: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800BD22C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800BD230: nop

    // 0x800BD234: bne         $t6, $zero, L_800BD244
    if (ctx->r14 != 0) {
        // 0x800BD238: nop

            goto L_800BD244;
    }
    // 0x800BD238: nop

    // 0x800BD23C: b           L_800BD610
    // 0x800BD240: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BD610;
    // 0x800BD240: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BD244:
    // 0x800BD244: jal         0x800C4270
    // 0x800BD248: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800BD248: nop

    after_0:
    // 0x800BD24C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800BD250: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD254: sltu        $at, $t7, $at
    ctx->r1 = ctx->r15 < ctx->r1 ? 1 : 0;
    // 0x800BD258: bne         $at, $zero, L_800BD28C
    if (ctx->r1 != 0) {
        // 0x800BD25C: nop

            goto L_800BD28C;
    }
    // 0x800BD25C: nop

    // 0x800BD260: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x800BD264: sltu        $at, $t7, $at
    ctx->r1 = ctx->r15 < ctx->r1 ? 1 : 0;
    // 0x800BD268: beq         $at, $zero, L_800BD28C
    if (ctx->r1 == 0) {
        // 0x800BD26C: nop

            goto L_800BD28C;
    }
    // 0x800BD26C: nop

    // 0x800BD270: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD274: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800BD278: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800BD27C: jal         0x800BCFCC
    // 0x800BD280: nop

    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x800BD280: nop

    after_1:
    // 0x800BD284: b           L_800BD610
    // 0x800BD288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BD610;
    // 0x800BD288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BD28C:
    // 0x800BD28C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800BD290: nop

    // 0x800BD294: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BD298: beq         $t9, $zero, L_800BD2A8
    if (ctx->r25 == 0) {
        // 0x800BD29C: nop

            goto L_800BD2A8;
    }
    // 0x800BD29C: nop

    // 0x800BD2A0: b           L_800BD610
    // 0x800BD2A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BD610;
    // 0x800BD2A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BD2A8:
    // 0x800BD2A8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800BD2AC: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x800BD2B0: sltu        $at, $t0, $at
    ctx->r1 = ctx->r8 < ctx->r1 ? 1 : 0;
    // 0x800BD2B4: bne         $at, $zero, L_800BD2C4
    if (ctx->r1 != 0) {
        // 0x800BD2B8: nop

            goto L_800BD2C4;
    }
    // 0x800BD2B8: nop

    // 0x800BD2BC: b           L_800BD610
    // 0x800BD2C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BD610;
    // 0x800BD2C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BD2C4:
    // 0x800BD2C4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD2C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD2CC: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x800BD2D0: bne         $at, $zero, L_800BD2E8
    if (ctx->r1 != 0) {
        // 0x800BD2D4: nop

            goto L_800BD2E8;
    }
    // 0x800BD2D4: nop

    // 0x800BD2D8: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x800BD2DC: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x800BD2E0: bne         $at, $zero, L_800BD2F0
    if (ctx->r1 != 0) {
        // 0x800BD2E4: nop

            goto L_800BD2F0;
    }
    // 0x800BD2E4: nop

L_800BD2E8:
    // 0x800BD2E8: b           L_800BD610
    // 0x800BD2EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BD610;
    // 0x800BD2EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BD2F0:
    // 0x800BD2F0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BD2F4: lw          $t2, 0x2640($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2640);
    // 0x800BD2F8: nop

    // 0x800BD2FC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800BD300: beq         $t3, $zero, L_800BD4B0
    if (ctx->r11 == 0) {
        // 0x800BD304: nop

            goto L_800BD4B0;
    }
    // 0x800BD304: nop

    // 0x800BD308: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800BD30C: lw          $t4, 0x2640($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2640);
    // 0x800BD310: nop

    // 0x800BD314: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800BD318: bne         $t5, $zero, L_800BD32C
    if (ctx->r13 != 0) {
        // 0x800BD31C: nop

            goto L_800BD32C;
    }
    // 0x800BD31C: nop

    // 0x800BD320: jal         0x800C41A0
    // 0x800BD324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x800BD324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800BD328: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_800BD32C:
    // 0x800BD32C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD330: nop

    // 0x800BD334: addiu       $t7, $t6, 0xF
    ctx->r15 = ADD32(ctx->r14, 0XF);
    // 0x800BD338: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x800BD33C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800BD340: bne         $t9, $t6, L_800BD3C4
    if (ctx->r25 != ctx->r14) {
        // 0x800BD344: nop

            goto L_800BD3C4;
    }
    // 0x800BD344: nop

    // 0x800BD348: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD34C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800BD350: jal         0x800CAFD0
    // 0x800BD354: nop

    osInvalDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x800BD354: nop

    after_3:
    // 0x800BD358: jal         0x800CB080
    // 0x800BD35C: nop

    osPiGetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x800BD35C: nop

    after_4:
    // 0x800BD360: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x800BD364: beq         $t0, $zero, L_800BD380
    if (ctx->r8 == 0) {
        // 0x800BD368: nop

            goto L_800BD380;
    }
    // 0x800BD368: nop

L_800BD36C:
    // 0x800BD36C: jal         0x800CB080
    // 0x800BD370: nop

    osPiGetStatus_recomp(rdram, ctx);
        goto after_5;
    // 0x800BD370: nop

    after_5:
    // 0x800BD374: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x800BD378: bne         $t1, $zero, L_800BD36C
    if (ctx->r9 != 0) {
        // 0x800BD37C: nop

            goto L_800BD36C;
    }
    // 0x800BD37C: nop

L_800BD380:
    // 0x800BD380: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800BD384: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD388: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800BD38C: jal         0x800CB090
    // 0x800BD390: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osPiRawStartDma_recomp(rdram, ctx);
        goto after_6;
    // 0x800BD390: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800BD394: jal         0x800CB080
    // 0x800BD398: nop

    osPiGetStatus_recomp(rdram, ctx);
        goto after_7;
    // 0x800BD398: nop

    after_7:
    // 0x800BD39C: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x800BD3A0: beq         $t2, $zero, L_800BD3BC
    if (ctx->r10 == 0) {
        // 0x800BD3A4: nop

            goto L_800BD3BC;
    }
    // 0x800BD3A4: nop

L_800BD3A8:
    // 0x800BD3A8: jal         0x800CB080
    // 0x800BD3AC: nop

    osPiGetStatus_recomp(rdram, ctx);
        goto after_8;
    // 0x800BD3AC: nop

    after_8:
    // 0x800BD3B0: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x800BD3B4: bne         $t3, $zero, L_800BD3A8
    if (ctx->r11 != 0) {
        // 0x800BD3B8: nop

            goto L_800BD3A8;
    }
    // 0x800BD3B8: nop

L_800BD3BC:
    // 0x800BD3BC: b           L_800BD484
    // 0x800BD3C0: nop

        goto L_800BD484;
    // 0x800BD3C0: nop

L_800BD3C4:
    // 0x800BD3C4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800BD3C8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800BD3CC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800BD3D0: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800BD3D4: bne         $at, $zero, L_800BD3E4
    if (ctx->r1 != 0) {
        // 0x800BD3D8: nop

            goto L_800BD3E4;
    }
    // 0x800BD3D8: nop

    // 0x800BD3DC: b           L_800BD610
    // 0x800BD3E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BD610;
    // 0x800BD3E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BD3E4:
    // 0x800BD3E4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BD3E8: addiu       $t5, $t5, 0x4A8
    ctx->r13 = ADD32(ctx->r13, 0X4A8);
    // 0x800BD3EC: addiu       $t7, $t5, 0xF
    ctx->r15 = ADD32(ctx->r13, 0XF);
    // 0x800BD3F0: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x800BD3F4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800BD3F8: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800BD3FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800BD400: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800BD404: jal         0x800CAFD0
    // 0x800BD408: nop

    osInvalDCache_recomp(rdram, ctx);
        goto after_9;
    // 0x800BD408: nop

    after_9:
    // 0x800BD40C: jal         0x800CB080
    // 0x800BD410: nop

    osPiGetStatus_recomp(rdram, ctx);
        goto after_10;
    // 0x800BD410: nop

    after_10:
    // 0x800BD414: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x800BD418: beq         $t6, $zero, L_800BD434
    if (ctx->r14 == 0) {
        // 0x800BD41C: nop

            goto L_800BD434;
    }
    // 0x800BD41C: nop

L_800BD420:
    // 0x800BD420: jal         0x800CB080
    // 0x800BD424: nop

    osPiGetStatus_recomp(rdram, ctx);
        goto after_11;
    // 0x800BD424: nop

    after_11:
    // 0x800BD428: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x800BD42C: bne         $t0, $zero, L_800BD420
    if (ctx->r8 != 0) {
        // 0x800BD430: nop

            goto L_800BD420;
    }
    // 0x800BD430: nop

L_800BD434:
    // 0x800BD434: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800BD438: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800BD43C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800BD440: jal         0x800CB090
    // 0x800BD444: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osPiRawStartDma_recomp(rdram, ctx);
        goto after_12;
    // 0x800BD444: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800BD448: jal         0x800CB080
    // 0x800BD44C: nop

    osPiGetStatus_recomp(rdram, ctx);
        goto after_13;
    // 0x800BD44C: nop

    after_13:
    // 0x800BD450: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x800BD454: beq         $t1, $zero, L_800BD470
    if (ctx->r9 == 0) {
        // 0x800BD458: nop

            goto L_800BD470;
    }
    // 0x800BD458: nop

L_800BD45C:
    // 0x800BD45C: jal         0x800CB080
    // 0x800BD460: nop

    osPiGetStatus_recomp(rdram, ctx);
        goto after_14;
    // 0x800BD460: nop

    after_14:
    // 0x800BD464: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x800BD468: bne         $t2, $zero, L_800BD45C
    if (ctx->r10 != 0) {
        // 0x800BD46C: nop

            goto L_800BD45C;
    }
    // 0x800BD46C: nop

L_800BD470:
    // 0x800BD470: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD474: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BD478: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800BD47C: jal         0x800BCFCC
    // 0x800BD480: nop

    SysMem_Copy8(rdram, ctx);
        goto after_15;
    // 0x800BD480: nop

    after_15:
L_800BD484:
    // 0x800BD484: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BD488: lw          $t3, 0x2640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2640);
    // 0x800BD48C: nop

    // 0x800BD490: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x800BD494: bne         $t4, $zero, L_800BD4A8
    if (ctx->r12 != 0) {
        // 0x800BD498: nop

            goto L_800BD4A8;
    }
    // 0x800BD498: nop

    // 0x800BD49C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD4A0: jal         0x800C41A0
    // 0x800BD4A4: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_16;
    // 0x800BD4A4: nop

    after_16:
L_800BD4A8:
    // 0x800BD4A8: b           L_800BD610
    // 0x800BD4AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BD610;
    // 0x800BD4AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BD4B0:
    // 0x800BD4B0: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x800BD4B4: lw          $t5, -0x6A0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6A0C);
    // 0x800BD4B8: nop

    // 0x800BD4BC: andi        $t7, $t5, 0x7F
    ctx->r15 = ctx->r13 & 0X7F;
    // 0x800BD4C0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800BD4C4: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x800BD4C8: lw          $t8, -0x6A0C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6A0C);
    // 0x800BD4CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800BD4D0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BD4D4: sw          $t9, -0x6A0C($at)
    MEM_W(-0X6A0C, ctx->r1) = ctx->r25;
    // 0x800BD4D8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD4DC: nop

    // 0x800BD4E0: bgez        $t6, L_800BD4F4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800BD4E4: andi        $t0, $t6, 0x7
        ctx->r8 = ctx->r14 & 0X7;
            goto L_800BD4F4;
    }
    // 0x800BD4E4: andi        $t0, $t6, 0x7
    ctx->r8 = ctx->r14 & 0X7;
    // 0x800BD4E8: beq         $t0, $zero, L_800BD4F4
    if (ctx->r8 == 0) {
        // 0x800BD4EC: nop

            goto L_800BD4F4;
    }
    // 0x800BD4EC: nop

    // 0x800BD4F0: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_800BD4F4:
    // 0x800BD4F4: bne         $t0, $zero, L_800BD55C
    if (ctx->r8 != 0) {
        // 0x800BD4F8: nop

            goto L_800BD55C;
    }
    // 0x800BD4F8: nop

    // 0x800BD4FC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD500: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800BD504: jal         0x800CAFD0
    // 0x800BD508: nop

    osInvalDCache_recomp(rdram, ctx);
        goto after_17;
    // 0x800BD508: nop

    after_17:
    // 0x800BD50C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD510: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800BD514: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BD518: addiu       $t3, $t3, 0x7BC0
    ctx->r11 = ADD32(ctx->r11, 0X7BC0);
    // 0x800BD51C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD520: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800BD524: addiu       $a0, $a0, 0x7B58
    ctx->r4 = ADD32(ctx->r4, 0X7B58);
    // 0x800BD528: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800BD52C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BD530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BD534: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BD538: jal         0x800C81D0
    // 0x800BD53C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    osPiStartDma_recomp(rdram, ctx);
        goto after_18;
    // 0x800BD53C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_18:
    // 0x800BD540: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD544: addiu       $a0, $a0, 0x7BC0
    ctx->r4 = ADD32(ctx->r4, 0X7BC0);
    // 0x800BD548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BD54C: jal         0x800C4C40
    // 0x800BD550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_19;
    // 0x800BD550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x800BD554: b           L_800BD600
    // 0x800BD558: nop

        goto L_800BD600;
    // 0x800BD558: nop

L_800BD55C:
    // 0x800BD55C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800BD560: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800BD564: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800BD568: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800BD56C: bne         $at, $zero, L_800BD57C
    if (ctx->r1 != 0) {
        // 0x800BD570: nop

            goto L_800BD57C;
    }
    // 0x800BD570: nop

    // 0x800BD574: b           L_800BD610
    // 0x800BD578: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BD610;
    // 0x800BD578: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BD57C:
    // 0x800BD57C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BD580: addiu       $t5, $t5, 0x4A8
    ctx->r13 = ADD32(ctx->r13, 0X4A8);
    // 0x800BD584: addiu       $t7, $t5, 0xF
    ctx->r15 = ADD32(ctx->r13, 0XF);
    // 0x800BD588: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x800BD58C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800BD590: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800BD594: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800BD598: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800BD59C: jal         0x800CAFD0
    // 0x800BD5A0: nop

    osInvalDCache_recomp(rdram, ctx);
        goto after_20;
    // 0x800BD5A0: nop

    after_20:
    // 0x800BD5A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800BD5A8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800BD5AC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BD5B0: addiu       $t1, $t1, 0x7BC0
    ctx->r9 = ADD32(ctx->r9, 0X7BC0);
    // 0x800BD5B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD5B8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800BD5BC: addiu       $a0, $a0, 0x7B58
    ctx->r4 = ADD32(ctx->r4, 0X7B58);
    // 0x800BD5C0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800BD5C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BD5C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BD5CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD5D0: jal         0x800C81D0
    // 0x800BD5D4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPiStartDma_recomp(rdram, ctx);
        goto after_21;
    // 0x800BD5D4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_21:
    // 0x800BD5D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD5DC: addiu       $a0, $a0, 0x7BC0
    ctx->r4 = ADD32(ctx->r4, 0X7BC0);
    // 0x800BD5E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BD5E4: jal         0x800C4C40
    // 0x800BD5E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_22;
    // 0x800BD5E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x800BD5EC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800BD5F0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BD5F4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800BD5F8: jal         0x800BCFCC
    // 0x800BD5FC: nop

    SysMem_Copy8(rdram, ctx);
        goto after_23;
    // 0x800BD5FC: nop

    after_23:
L_800BD600:
    // 0x800BD600: b           L_800BD610
    // 0x800BD604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BD610;
    // 0x800BD604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BD608: b           L_800BD610
    // 0x800BD60C: nop

        goto L_800BD610;
    // 0x800BD60C: nop

L_800BD610:
    // 0x800BD610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BD614: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800BD618: jr          $ra
    // 0x800BD61C: nop

    return;
    // 0x800BD61C: nop

;}
RECOMP_FUNC void func_800BD620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD620: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD624: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BD628: lw          $t6, 0x2640($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2640);
    // 0x800BD62C: nop

    // 0x800BD630: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BD634: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BD638: lw          $t7, 0x2640($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2640);
    // 0x800BD63C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD640: or          $t8, $t7, $a0
    ctx->r24 = ctx->r15 | ctx->r4;
    // 0x800BD644: sw          $t8, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = ctx->r24;
    // 0x800BD648: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800BD64C: b           L_800BD65C
    // 0x800BD650: nop

        goto L_800BD65C;
    // 0x800BD650: nop

    // 0x800BD654: b           L_800BD65C
    // 0x800BD658: nop

        goto L_800BD65C;
    // 0x800BD658: nop

L_800BD65C:
    // 0x800BD65C: jr          $ra
    // 0x800BD660: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD660: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800BD664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD664: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD668: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BD66C: lw          $t6, 0x2640($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2640);
    // 0x800BD670: nop

    // 0x800BD674: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BD678: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BD67C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD680: lw          $t7, 0x2640($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2640);
    // 0x800BD684: xor         $t8, $a0, $at
    ctx->r24 = ctx->r4 ^ ctx->r1;
    // 0x800BD688: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD68C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x800BD690: sw          $t9, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = ctx->r25;
    // 0x800BD694: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800BD698: b           L_800BD6A8
    // 0x800BD69C: nop

        goto L_800BD6A8;
    // 0x800BD69C: nop

    // 0x800BD6A0: b           L_800BD6A8
    // 0x800BD6A4: nop

        goto L_800BD6A8;
    // 0x800BD6A4: nop

L_800BD6A8:
    // 0x800BD6A8: jr          $ra
    // 0x800BD6AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD6AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800BD6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD6B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD6B4: sw          $a0, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = ctx->r4;
    // 0x800BD6B8: jr          $ra
    // 0x800BD6BC: nop

    return;
    // 0x800BD6BC: nop

    // 0x800BD6C0: jr          $ra
    // 0x800BD6C4: nop

    return;
    // 0x800BD6C4: nop

;}
RECOMP_FUNC void func_800BD6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD6C8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BD6CC: lw          $v0, 0x2640($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2640);
    // 0x800BD6D0: jr          $ra
    // 0x800BD6D4: nop

    return;
    // 0x800BD6D4: nop

    // 0x800BD6D8: jr          $ra
    // 0x800BD6DC: nop

    return;
    // 0x800BD6DC: nop

    // 0x800BD6E0: jr          $ra
    // 0x800BD6E4: nop

    return;
    // 0x800BD6E4: nop

;}
RECOMP_FUNC void func_800BD6E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD6E8: nop

    // 0x800BD6EC: nop

;}
RECOMP_FUNC void Main_BootProc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD6F0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800BD6F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BD6F8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800BD6FC: jal         0x800CB170
    // 0x800BD700: nop

    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x800BD700: nop

    after_0:
    // 0x800BD704: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD708: sw          $zero, 0x1698($at)
    MEM_W(0X1698, ctx->r1) = 0;
    // 0x800BD70C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD710: sw          $zero, 0x16C4($at)
    MEM_W(0X16C4, ctx->r1) = 0;
    // 0x800BD714: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BD718: addiu       $t6, $t6, 0x49C8
    ctx->r14 = ADD32(ctx->r14, 0X49C8);
    // 0x800BD71C: addiu       $t7, $t6, 0x2000
    ctx->r15 = ADD32(ctx->r14, 0X2000);
    // 0x800BD720: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD724: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800BD728: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800BD72C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800BD730: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800BD734: addiu       $a2, $a2, -0x2894
    ctx->r6 = ADD32(ctx->r6, -0X2894);
    // 0x800BD738: addiu       $a0, $a0, 0x2650
    ctx->r4 = ADD32(ctx->r4, 0X2650);
    // 0x800BD73C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800BD740: jal         0x800C4800
    // 0x800BD744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800BD744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x800BD748: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD74C: jal         0x800C4950
    // 0x800BD750: addiu       $a0, $a0, 0x2650
    ctx->r4 = ADD32(ctx->r4, 0X2650);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800BD750: addiu       $a0, $a0, 0x2650
    ctx->r4 = ADD32(ctx->r4, 0X2650);
    after_2:
    // 0x800BD754: b           L_800BD75C
    // 0x800BD758: nop

        goto L_800BD75C;
    // 0x800BD758: nop

L_800BD75C:
    // 0x800BD75C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD760: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800BD764: jr          $ra
    // 0x800BD768: nop

    return;
    // 0x800BD768: nop

;}
RECOMP_FUNC void Main_IdleThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD76C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BD770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD774: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BD778: jal         0x800BC620
    // 0x800BD77C: nop

    SysMem_HeapInit(rdram, ctx);
        goto after_0;
    // 0x800BD77C: nop

    after_0:
    // 0x800BD780: jal         0x800C05A0
    // 0x800BD784: nop

    Thread_Init(rdram, ctx);
        goto after_1;
    // 0x800BD784: nop

    after_1:
    // 0x800BD788: jal         0x800ABE54
    // 0x800BD78C: nop

    func_800ABE54(rdram, ctx);
        goto after_2;
    // 0x800BD78C: nop

    after_2:
    // 0x800BD790: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800BD794: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD798: sw          $t6, 0x2584($at)
    MEM_W(0X2584, ctx->r1) = ctx->r14;
    // 0x800BD79C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BD7A0: sw          $zero, -0x7F8($at)
    MEM_W(-0X7F8, ctx->r1) = 0;
    // 0x800BD7A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BD7A8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BD7AC: addiu       $a2, $a2, 0x7A18
    ctx->r6 = ADD32(ctx->r6, 0X7A18);
    // 0x800BD7B0: addiu       $a1, $a1, 0x7B30
    ctx->r5 = ADD32(ctx->r5, 0X7B30);
    // 0x800BD7B4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800BD7B8: jal         0x800CB410
    // 0x800BD7BC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_3;
    // 0x800BD7BC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_3:
    // 0x800BD7C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD7C4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BD7C8: addiu       $a1, $a1, 0x7B78
    ctx->r5 = ADD32(ctx->r5, 0X7B78);
    // 0x800BD7CC: addiu       $a0, $a0, 0x7BC0
    ctx->r4 = ADD32(ctx->r4, 0X7BC0);
    // 0x800BD7D0: jal         0x800C42B0
    // 0x800BD7D4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x800BD7D4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x800BD7D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BD7DC:
    // 0x800BD7DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD7E0: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x800BD7E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BD7E8: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x800BD7EC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BD7F0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800BD7F4: addiu       $t1, $t1, -0x6C10
    ctx->r9 = ADD32(ctx->r9, -0X6C10);
    // 0x800BD7F8: addiu       $t9, $t9, -0x7818
    ctx->r25 = ADD32(ctx->r25, -0X7818);
    // 0x800BD7FC: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x800BD800: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x800BD804: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800BD808: jal         0x800C42B0
    // 0x800BD80C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x800BD80C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800BD810: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD814: nop

    // 0x800BD818: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BD81C: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x800BD820: bne         $at, $zero, L_800BD7DC
    if (ctx->r1 != 0) {
        // 0x800BD824: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_800BD7DC;
    }
    // 0x800BD824: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800BD828: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800BD82C: sw          $zero, -0x6A0C($at)
    MEM_W(-0X6A0C, ctx->r1) = 0;
    // 0x800BD830: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800BD834: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800BD838: addiu       $a1, $a1, 0x1918
    ctx->r5 = ADD32(ctx->r5, 0X1918);
    // 0x800BD83C: addiu       $a0, $a0, 0x450
    ctx->r4 = ADD32(ctx->r4, 0X450);
    // 0x800BD840: jal         0x800C0640
    // 0x800BD844: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    Thread_CreateSimple(rdram, ctx);
        goto after_6;
    // 0x800BD844: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_6:
    // 0x800BD848: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BD84C: sb          $v0, -0x71C4($at)
    MEM_B(-0X71C4, ctx->r1) = ctx->r2;
    // 0x800BD850: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BD854: lbu         $t4, -0x71C4($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X71C4);
    // 0x800BD858: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BD85C: sb          $t4, 0x1918($at)
    MEM_B(0X1918, ctx->r1) = ctx->r12;
    // 0x800BD860: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BD864: lbu         $a0, -0x71C4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X71C4);
    // 0x800BD868: jal         0x800C0E04
    // 0x800BD86C: nop

    Thread_GetPtr(rdram, ctx);
        goto after_7;
    // 0x800BD86C: nop

    after_7:
    // 0x800BD870: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BD874: sw          $v0, 0x1930($at)
    MEM_W(0X1930, ctx->r1) = ctx->r2;
    // 0x800BD878: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x800BD87C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BD880: sw          $t5, 0x191C($at)
    MEM_W(0X191C, ctx->r1) = ctx->r13;
    // 0x800BD884: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BD888: lw          $t6, 0x1698($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1698);
    // 0x800BD88C: nop

    // 0x800BD890: bne         $t6, $zero, L_800BD8A8
    if (ctx->r14 != 0) {
        // 0x800BD894: nop

            goto L_800BD8A8;
    }
    // 0x800BD894: nop

    // 0x800BD898: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BD89C: lbu         $a0, -0x71C4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X71C4);
    // 0x800BD8A0: jal         0x800C0C8C
    // 0x800BD8A4: nop

    Thread_Start(rdram, ctx);
        goto after_8;
    // 0x800BD8A4: nop

    after_8:
L_800BD8A8:
    // 0x800BD8A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BD8AC: jal         0x800CB5A0
    // 0x800BD8B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_9;
    // 0x800BD8B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
L_800BD8B4:
    // 0x800BD8B4: b           L_800BD8B4
    pause_self(rdram);
    // 0x800BD8B8: nop

    // 0x800BD8BC: b           L_800BD8C4
    // 0x800BD8C0: nop

        goto L_800BD8C4;
    // 0x800BD8C0: nop

L_800BD8C4:
    // 0x800BD8C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD8C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BD8CC: jr          $ra
    // 0x800BD8D0: nop

    return;
    // 0x800BD8D0: nop

;}
RECOMP_FUNC void func_800BD8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD8D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800BD8D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BD8DC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800BD8E0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800BD8E4: lui         $t6, 0x803E
    ctx->r14 = S32(0X803E << 16);
    // 0x800BD8E8: addiu       $t6, $t6, -0x5800
    ctx->r14 = ADD32(ctx->r14, -0X5800);
    // 0x800BD8EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BD8F0: sw          $t6, 0x7200($at)
    MEM_W(0X7200, ctx->r1) = ctx->r14;
    // 0x800BD8F4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800BD8F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD8FC: sw          $t7, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r15;
    // 0x800BD900: addiu       $t8, $zero, 0x4A
    ctx->r24 = ADD32(0, 0X4A);
    // 0x800BD904: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD908: sw          $t8, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r24;
    // 0x800BD90C: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x800BD910: lui         $t0, 0xF
    ctx->r8 = S32(0XF << 16);
    // 0x800BD914: addiu       $t0, $t0, 0x24E0
    ctx->r8 = ADD32(ctx->r8, 0X24E0);
    // 0x800BD918: addiu       $t9, $t9, 0x27E0
    ctx->r25 = ADD32(ctx->r25, 0X27E0);
    // 0x800BD91C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800BD920: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800BD924: sw          $t1, -0x69F4($at)
    MEM_W(-0X69F4, ctx->r1) = ctx->r9;
    // 0x800BD928: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800BD92C: addiu       $t2, $t2, 0x20A0
    ctx->r10 = ADD32(ctx->r10, 0X20A0);
    // 0x800BD930: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800BD934: sw          $t2, -0x6A04($at)
    MEM_W(-0X6A04, ctx->r1) = ctx->r10;
    // 0x800BD938: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x800BD93C: lw          $t3, -0x69F4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X69F4);
    // 0x800BD940: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BD944: addiu       $t4, $t4, 0x20A0
    ctx->r12 = ADD32(ctx->r12, 0X20A0);
    // 0x800BD948: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800BD94C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BD950: sw          $t5, -0x69FC($at)
    MEM_W(-0X69FC, ctx->r1) = ctx->r13;
    // 0x800BD954: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x800BD958: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x800BD95C: lw          $t7, -0x69F4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X69F4);
    // 0x800BD960: lw          $t6, -0x6A04($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A04);
    // 0x800BD964: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BD968: addiu       $t8, $t8, 0x7BC0
    ctx->r24 = ADD32(ctx->r24, 0X7BC0);
    // 0x800BD96C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD970: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x800BD974: addiu       $a3, $a3, 0x24E0
    ctx->r7 = ADD32(ctx->r7, 0X24E0);
    // 0x800BD978: addiu       $a0, $a0, 0x7B58
    ctx->r4 = ADD32(ctx->r4, 0X7B58);
    // 0x800BD97C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800BD980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BD984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BD988: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800BD98C: jal         0x800C81D0
    // 0x800BD990: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    osPiStartDma_recomp(rdram, ctx);
        goto after_0;
    // 0x800BD990: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800BD994: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD998: addiu       $a0, $a0, 0x7BC0
    ctx->r4 = ADD32(ctx->r4, 0X7BC0);
    // 0x800BD99C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BD9A0: jal         0x800C4C40
    // 0x800BD9A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800BD9A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800BD9A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800BD9AC: sw          $zero, 0x6BA4($at)
    MEM_W(0X6BA4, ctx->r1) = 0;
    // 0x800BD9B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BD9B4: sw          $zero, 0x1B14($at)
    MEM_W(0X1B14, ctx->r1) = 0;
    // 0x800BD9B8: b           L_800BD9C0
    // 0x800BD9BC: nop

        goto L_800BD9C0;
    // 0x800BD9BC: nop

L_800BD9C0:
    // 0x800BD9C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BD9C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800BD9C8: jr          $ra
    // 0x800BD9CC: nop

    return;
    // 0x800BD9CC: nop

;}
RECOMP_FUNC void func_800BD9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD9D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD9D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD9D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BD9DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BD9E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800BD9E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD9E8: beq         $t6, $at, L_800BDA1C
    if (ctx->r14 == ctx->r1) {
        // 0x800BD9EC: nop

            goto L_800BDA1C;
    }
    // 0x800BD9EC: nop

    // 0x800BD9F0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800BD9F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD9F8: sw          $t7, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r15;
    // 0x800BD9FC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800BDA00: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800BDA04: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BDA08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800BDA0C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800BDA10: addiu       $t0, $t0, -0x4130
    ctx->r8 = ADD32(ctx->r8, -0X4130);
    // 0x800BDA14: jal         0x800C4640
    // 0x800BDA18: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x800BDA18: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_0:
L_800BDA1C:
    // 0x800BDA1C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDA20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDA24: beq         $t1, $at, L_800BDA40
    if (ctx->r9 == ctx->r1) {
        // 0x800BDA28: nop

            goto L_800BDA40;
    }
    // 0x800BDA28: nop

    // 0x800BDA2C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDA30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDA34: sw          $t2, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r10;
    // 0x800BDA38: jal         0x800CB680
    // 0x800BDA3C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_1;
    // 0x800BDA3C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_1:
L_800BDA40:
    // 0x800BDA40: b           L_800BDA48
    // 0x800BDA44: nop

        goto L_800BDA48;
    // 0x800BDA44: nop

L_800BDA48:
    // 0x800BDA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BDA50: jr          $ra
    // 0x800BDA54: nop

    return;
    // 0x800BDA54: nop

;}
RECOMP_FUNC void func_800BDA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDA58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BDA5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BDA60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BDA64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BDA68: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800BDA6C: nop

    // 0x800BDA70: sltiu       $at, $s0, 0x41
    ctx->r1 = ctx->r16 < 0X41 ? 1 : 0;
    // 0x800BDA74: bne         $at, $zero, L_800BDA90
    if (ctx->r1 != 0) {
        // 0x800BDA78: nop

            goto L_800BDA90;
    }
    // 0x800BDA78: nop

    // 0x800BDA7C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800BDA80: beq         $s0, $at, L_800BDC14
    if (ctx->r16 == ctx->r1) {
        // 0x800BDA84: nop

            goto L_800BDC14;
    }
    // 0x800BDA84: nop

    // 0x800BDA88: b           L_800BDC48
    // 0x800BDA8C: nop

        goto L_800BDC48;
    // 0x800BDA8C: nop

L_800BDA90:
    // 0x800BDA90: sltiu       $at, $s0, 0x21
    ctx->r1 = ctx->r16 < 0X21 ? 1 : 0;
    // 0x800BDA94: bne         $at, $zero, L_800BDAB0
    if (ctx->r1 != 0) {
        // 0x800BDA98: nop

            goto L_800BDAB0;
    }
    // 0x800BDA98: nop

    // 0x800BDA9C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800BDAA0: beq         $s0, $at, L_800BDC14
    if (ctx->r16 == ctx->r1) {
        // 0x800BDAA4: nop

            goto L_800BDC14;
    }
    // 0x800BDAA4: nop

    // 0x800BDAA8: b           L_800BDC48
    // 0x800BDAAC: nop

        goto L_800BDC48;
    // 0x800BDAAC: nop

L_800BDAB0:
    // 0x800BDAB0: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x800BDAB4: sltiu       $at, $t6, 0x20
    ctx->r1 = ctx->r14 < 0X20 ? 1 : 0;
    // 0x800BDAB8: beq         $at, $zero, L_800BDC48
    if (ctx->r1 == 0) {
        // 0x800BDABC: nop

            goto L_800BDC48;
    }
    // 0x800BDABC: nop

    // 0x800BDAC0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BDAC4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BDAC8: addu        $at, $at, $t6
    gpr jr_addend_800BDAD4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800BDACC: lw          $t6, -0x220($at)
    ctx->r14 = ADD32(ctx->r1, -0X220);
    // 0x800BDAD0: nop

    // 0x800BDAD4: jr          $t6
    // 0x800BDAD8: nop

    switch (jr_addend_800BDAD4 >> 2) {
        case 0: goto L_800BDADC; break;
        case 1: goto L_800BDB10; break;
        case 2: goto L_800BDC48; break;
        case 3: goto L_800BDB44; break;
        case 4: goto L_800BDC48; break;
        case 5: goto L_800BDC48; break;
        case 6: goto L_800BDC48; break;
        case 7: goto L_800BDB78; break;
        case 8: goto L_800BDC48; break;
        case 9: goto L_800BDC48; break;
        case 10: goto L_800BDC48; break;
        case 11: goto L_800BDC48; break;
        case 12: goto L_800BDC48; break;
        case 13: goto L_800BDC48; break;
        case 14: goto L_800BDC48; break;
        case 15: goto L_800BDBAC; break;
        case 16: goto L_800BDC48; break;
        case 17: goto L_800BDC48; break;
        case 18: goto L_800BDC48; break;
        case 19: goto L_800BDC48; break;
        case 20: goto L_800BDC48; break;
        case 21: goto L_800BDC48; break;
        case 22: goto L_800BDC48; break;
        case 23: goto L_800BDC48; break;
        case 24: goto L_800BDC48; break;
        case 25: goto L_800BDC48; break;
        case 26: goto L_800BDC48; break;
        case 27: goto L_800BDC48; break;
        case 28: goto L_800BDC48; break;
        case 29: goto L_800BDC48; break;
        case 30: goto L_800BDC48; break;
        case 31: goto L_800BDBE0; break;
        default: switch_error(__func__, 0x800BDAD4, 0x800EFDE0);
    }
    // 0x800BDAD8: nop

L_800BDADC:
    // 0x800BDADC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BDAE0: lw          $t7, 0x168C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X168C);
    // 0x800BDAE4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800BDAE8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800BDAEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDAF0: sw          $t8, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r24;
    // 0x800BDAF4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BDAF8: lw          $t9, 0x168C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X168C);
    // 0x800BDAFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDB00: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800BDB04: sw          $t0, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r8;
    // 0x800BDB08: b           L_800BDC48
    // 0x800BDB0C: nop

        goto L_800BDC48;
    // 0x800BDB0C: nop

L_800BDB10:
    // 0x800BDB10: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BDB14: lw          $t1, 0x168C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X168C);
    // 0x800BDB18: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800BDB1C: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800BDB20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDB24: sw          $t2, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r10;
    // 0x800BDB28: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BDB2C: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x800BDB30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDB34: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x800BDB38: sw          $t4, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r12;
    // 0x800BDB3C: b           L_800BDC48
    // 0x800BDB40: nop

        goto L_800BDC48;
    // 0x800BDB40: nop

L_800BDB44:
    // 0x800BDB44: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BDB48: lw          $t5, 0x168C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X168C);
    // 0x800BDB4C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800BDB50: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800BDB54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDB58: sw          $t6, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r14;
    // 0x800BDB5C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BDB60: lw          $t7, 0x168C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X168C);
    // 0x800BDB64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDB68: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x800BDB6C: sw          $t8, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r24;
    // 0x800BDB70: b           L_800BDC48
    // 0x800BDB74: nop

        goto L_800BDC48;
    // 0x800BDB74: nop

L_800BDB78:
    // 0x800BDB78: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BDB7C: lw          $t9, 0x168C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X168C);
    // 0x800BDB80: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800BDB84: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800BDB88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDB8C: sw          $t0, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r8;
    // 0x800BDB90: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BDB94: lw          $t1, 0x168C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X168C);
    // 0x800BDB98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDB9C: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x800BDBA0: sw          $t2, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r10;
    // 0x800BDBA4: b           L_800BDC48
    // 0x800BDBA8: nop

        goto L_800BDC48;
    // 0x800BDBA8: nop

L_800BDBAC:
    // 0x800BDBAC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BDBB0: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x800BDBB4: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800BDBB8: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800BDBBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDBC0: sw          $t4, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r12;
    // 0x800BDBC4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BDBC8: lw          $t5, 0x168C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X168C);
    // 0x800BDBCC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDBD0: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x800BDBD4: sw          $t6, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r14;
    // 0x800BDBD8: b           L_800BDC48
    // 0x800BDBDC: nop

        goto L_800BDC48;
    // 0x800BDBDC: nop

L_800BDBE0:
    // 0x800BDBE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BDBE4: lw          $t7, 0x168C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X168C);
    // 0x800BDBE8: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800BDBEC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800BDBF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDBF4: sw          $t8, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r24;
    // 0x800BDBF8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BDBFC: lw          $t9, 0x168C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X168C);
    // 0x800BDC00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDC04: ori         $t0, $t9, 0x20
    ctx->r8 = ctx->r25 | 0X20;
    // 0x800BDC08: sw          $t0, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r8;
    // 0x800BDC0C: b           L_800BDC48
    // 0x800BDC10: nop

        goto L_800BDC48;
    // 0x800BDC10: nop

L_800BDC14:
    // 0x800BDC14: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BDC18: lw          $t1, 0x168C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X168C);
    // 0x800BDC1C: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800BDC20: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800BDC24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDC28: sw          $t2, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r10;
    // 0x800BDC2C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BDC30: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x800BDC34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDC38: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x800BDC3C: sw          $t4, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r12;
    // 0x800BDC40: b           L_800BDC48
    // 0x800BDC44: nop

        goto L_800BDC48;
    // 0x800BDC44: nop

L_800BDC48:
    // 0x800BDC48: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BDC4C: lw          $a1, 0x168C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X168C);
    // 0x800BDC50: jal         0x800BD9D0
    // 0x800BDC54: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_800BD9D0(rdram, ctx);
        goto after_0;
    // 0x800BDC54: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x800BDC58: b           L_800BDC60
    // 0x800BDC5C: nop

        goto L_800BDC60;
    // 0x800BDC5C: nop

L_800BDC60:
    // 0x800BDC60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDC64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BDC68: jr          $ra
    // 0x800BDC6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800BDC6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800BDC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDC70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BDC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDC78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BDC7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800BDC80: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800BDC84: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800BDC88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BDC8C: lw          $t6, 0x2584($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2584);
    // 0x800BDC90: nop

    // 0x800BDC94: beq         $t6, $zero, L_800BDCAC
    if (ctx->r14 == 0) {
        // 0x800BDC98: nop

            goto L_800BDCAC;
    }
    // 0x800BDC98: nop

    // 0x800BDC9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BDCA0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800BDCA4: jal         0x800BD8D4
    // 0x800BDCA8: nop

    func_800BD8D4(rdram, ctx);
        goto after_0;
    // 0x800BDCA8: nop

    after_0:
L_800BDCAC:
    // 0x800BDCAC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BDCB0: lw          $a1, 0x168C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X168C);
    // 0x800BDCB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BDCB8: jal         0x800BD9D0
    // 0x800BDCBC: nop

    func_800BD9D0(rdram, ctx);
        goto after_1;
    // 0x800BDCBC: nop

    after_1:
    // 0x800BDCC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BDCC4: lw          $t7, 0x2584($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2584);
    // 0x800BDCC8: nop

    // 0x800BDCCC: beq         $t7, $zero, L_800BDD80
    if (ctx->r15 == 0) {
        // 0x800BDCD0: nop

            goto L_800BDD80;
    }
    // 0x800BDCD0: nop

    // 0x800BDCD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDCD8: sh          $zero, 0x24FC($at)
    MEM_H(0X24FC, ctx->r1) = 0;
    // 0x800BDCDC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800BDCE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDCE4: sw          $t8, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r24;
    // 0x800BDCE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDCEC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x800BDCF0: sw          $t9, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r25;
    // 0x800BDCF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDCF8: sw          $zero, 0x251C($at)
    MEM_W(0X251C, ctx->r1) = 0;
    // 0x800BDCFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BDD00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD04: sw          $t0, 0x2528($at)
    MEM_W(0X2528, ctx->r1) = ctx->r8;
    // 0x800BDD08: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BDD0C: lhu         $t1, 0x24FC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X24FC);
    // 0x800BDD10: nop

    // 0x800BDD14: beq         $t1, $zero, L_800BDD30
    if (ctx->r9 == 0) {
        // 0x800BDD18: nop

            goto L_800BDD30;
    }
    // 0x800BDD18: nop

    // 0x800BDD1C: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x800BDD20: addiu       $t2, $t2, -0x5800
    ctx->r10 = ADD32(ctx->r10, -0X5800);
    // 0x800BDD24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD28: b           L_800BDD40
    // 0x800BDD2C: sw          $t2, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r10;
        goto L_800BDD40;
    // 0x800BDD2C: sw          $t2, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r10;
L_800BDD30:
    // 0x800BDD30: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x800BDD34: addiu       $t3, $t3, 0x0
    ctx->r11 = ADD32(ctx->r11, 0X0);
    // 0x800BDD38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD3C: sw          $t3, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r11;
L_800BDD40:
    // 0x800BDD40: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800BDD44: lhu         $t4, 0x24FC($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X24FC);
    // 0x800BDD48: nop

    // 0x800BDD4C: beq         $t4, $zero, L_800BDD68
    if (ctx->r12 == 0) {
        // 0x800BDD50: nop

            goto L_800BDD68;
    }
    // 0x800BDD50: nop

    // 0x800BDD54: lui         $t5, 0x8020
    ctx->r13 = S32(0X8020 << 16);
    // 0x800BDD58: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x800BDD5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD60: b           L_800BDD78
    // 0x800BDD64: sw          $t5, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r13;
        goto L_800BDD78;
    // 0x800BDD64: sw          $t5, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r13;
L_800BDD68:
    // 0x800BDD68: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x800BDD6C: addiu       $t6, $t6, -0x5800
    ctx->r14 = ADD32(ctx->r14, -0X5800);
    // 0x800BDD70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD74: sw          $t6, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r14;
L_800BDD78:
    // 0x800BDD78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BDD7C: sw          $zero, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = 0;
L_800BDD80:
    // 0x800BDD80: jal         0x8008E630
    // 0x800BDD84: nop

    func_8008E630(rdram, ctx);
        goto after_2;
    // 0x800BDD84: nop

    after_2:
    // 0x800BDD88: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BDD8C: lw          $a0, 0x24D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D0);
    // 0x800BDD90: jal         0x8008ECCC
    // 0x800BDD94: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_3;
    // 0x800BDD94: nop

    after_3:
    // 0x800BDD98: jal         0x800C15C0
    // 0x800BDD9C: nop

    MtxUtil_InitStack(rdram, ctx);
        goto after_4;
    // 0x800BDD9C: nop

    after_4:
    // 0x800BDDA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BDDA4:
    // 0x800BDDA4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDDA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BDDAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BDDB0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDDB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDDB8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BDDBC: swc1        $f4, 0x2538($at)
    MEM_W(0X2538, ctx->r1) = ctx->f4.u32l;
    // 0x800BDDC0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDDC4: nop

    // 0x800BDDC8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BDDCC: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800BDDD0: bne         $at, $zero, L_800BDDA4
    if (ctx->r1 != 0) {
        // 0x800BDDD4: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800BDDA4;
    }
    // 0x800BDDD4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BDDD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BDDDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BDDE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDDE4: swc1        $f6, 0x257C($at)
    MEM_W(0X257C, ctx->r1) = ctx->f6.u32l;
    // 0x800BDDE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDDEC: sw          $zero, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = 0;
    // 0x800BDDF0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800BDDF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDDF8: sw          $t1, 0x2574($at)
    MEM_W(0X2574, ctx->r1) = ctx->r9;
    // 0x800BDDFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDE00: sw          $zero, 0x258C($at)
    MEM_W(0X258C, ctx->r1) = 0;
    // 0x800BDE04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800BDE08: jal         0x80099660
    // 0x800BDE0C: addiu       $a0, $a0, 0x5E8
    ctx->r4 = ADD32(ctx->r4, 0X5E8);
    func_80099660(rdram, ctx);
        goto after_5;
    // 0x800BDE0C: addiu       $a0, $a0, 0x5E8
    ctx->r4 = ADD32(ctx->r4, 0X5E8);
    after_5:
    // 0x800BDE10: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BDE14: nop

    // 0x800BDE18: beq         $t2, $zero, L_800BDE2C
    if (ctx->r10 == 0) {
        // 0x800BDE1C: nop

            goto L_800BDE2C;
    }
    // 0x800BDE1C: nop

    // 0x800BDE20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800BDE24: jal         0x800AF060
    // 0x800BDE28: nop

    func_800AF060(rdram, ctx);
        goto after_6;
    // 0x800BDE28: nop

    after_6:
L_800BDE2C:
    // 0x800BDE2C: jal         0x800A6440
    // 0x800BDE30: nop

    func_800A6440(rdram, ctx);
        goto after_7;
    // 0x800BDE30: nop

    after_7:
    // 0x800BDE34: jal         0x800AC890
    // 0x800BDE38: nop

    func_800AC890(rdram, ctx);
        goto after_8;
    // 0x800BDE38: nop

    after_8:
    // 0x800BDE3C: jal         0x800ABAC8
    // 0x800BDE40: nop

    func_800ABAC8(rdram, ctx);
        goto after_9;
    // 0x800BDE40: nop

    after_9:
    // 0x800BDE44: jal         0x800ACE50
    // 0x800BDE48: nop

    func_800ACE50(rdram, ctx);
        goto after_10;
    // 0x800BDE48: nop

    after_10:
    // 0x800BDE4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDE50: sw          $zero, 0x2584($at)
    MEM_W(0X2584, ctx->r1) = 0;
    // 0x800BDE54: b           L_800BDE5C
    // 0x800BDE58: nop

        goto L_800BDE5C;
    // 0x800BDE58: nop

L_800BDE5C:
    // 0x800BDE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDE60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BDE64: jr          $ra
    // 0x800BDE68: nop

    return;
    // 0x800BDE68: nop

;}
RECOMP_FUNC void func_800BDE6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDE6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BDE70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDE74: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BDE78: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800BDE7C: jal         0x800C4270
    // 0x800BDE80: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800BDE80: nop

    after_0:
    // 0x800BDE84: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BDE88: nop

    // 0x800BDE8C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800BDE90: beq         $t7, $zero, L_800BDEA0
    if (ctx->r15 == 0) {
        // 0x800BDE94: nop

            goto L_800BDEA0;
    }
    // 0x800BDE94: nop

    // 0x800BDE98: jal         0x800BE068
    // 0x800BDE9C: nop

    func_800BE068(rdram, ctx);
        goto after_1;
    // 0x800BDE9C: nop

    after_1:
L_800BDEA0:
    // 0x800BDEA0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BDEA4: nop

    // 0x800BDEA8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800BDEAC: beq         $t9, $zero, L_800BDEBC
    if (ctx->r25 == 0) {
        // 0x800BDEB0: nop

            goto L_800BDEBC;
    }
    // 0x800BDEB0: nop

    // 0x800BDEB4: jal         0x800BE08C
    // 0x800BDEB8: nop

    func_800BE08C(rdram, ctx);
        goto after_2;
    // 0x800BDEB8: nop

    after_2:
L_800BDEBC:
    // 0x800BDEBC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800BDEC0: nop

    // 0x800BDEC4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BDEC8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800BDECC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDED0: sw          $zero, 0x2528($at)
    MEM_W(0X2528, ctx->r1) = 0;
    // 0x800BDED4: jal         0x800C40D0
    // 0x800BDED8: nop

    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x800BDED8: nop

    after_3:
    // 0x800BDEDC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BDEE0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BDEE4: lw          $t3, 0x19AC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X19AC);
    // 0x800BDEE8: lw          $t2, 0x19A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X19A8);
    // 0x800BDEEC: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800BDEF0: subu        $t4, $v0, $t2
    ctx->r12 = SUB32(ctx->r2, ctx->r10);
    // 0x800BDEF4: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x800BDEF8: subu        $t5, $v1, $t3
    ctx->r13 = SUB32(ctx->r3, ctx->r11);
    // 0x800BDEFC: or          $t6, $t5, $zero
    ctx->r14 = ctx->r13 | 0;
    // 0x800BDF00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF04: sw          $t6, 0x251C($at)
    MEM_W(0X251C, ctx->r1) = ctx->r14;
    // 0x800BDF08: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BDF0C: lhu         $t7, 0x24FC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X24FC);
    // 0x800BDF10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF14: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x800BDF18: sh          $t8, 0x24FC($at)
    MEM_H(0X24FC, ctx->r1) = ctx->r24;
    // 0x800BDF1C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BDF20: lhu         $t9, 0x24FC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X24FC);
    // 0x800BDF24: nop

    // 0x800BDF28: beq         $t9, $zero, L_800BDF44
    if (ctx->r25 == 0) {
        // 0x800BDF2C: nop

            goto L_800BDF44;
    }
    // 0x800BDF2C: nop

    // 0x800BDF30: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x800BDF34: addiu       $t0, $t0, -0x5800
    ctx->r8 = ADD32(ctx->r8, -0X5800);
    // 0x800BDF38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF3C: b           L_800BDF54
    // 0x800BDF40: sw          $t0, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r8;
        goto L_800BDF54;
    // 0x800BDF40: sw          $t0, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r8;
L_800BDF44:
    // 0x800BDF44: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x800BDF48: addiu       $t1, $t1, 0x0
    ctx->r9 = ADD32(ctx->r9, 0X0);
    // 0x800BDF4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF50: sw          $t1, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r9;
L_800BDF54:
    // 0x800BDF54: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BDF58: lhu         $t2, 0x24FC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X24FC);
    // 0x800BDF5C: nop

    // 0x800BDF60: beq         $t2, $zero, L_800BDF7C
    if (ctx->r10 == 0) {
        // 0x800BDF64: nop

            goto L_800BDF7C;
    }
    // 0x800BDF64: nop

    // 0x800BDF68: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x800BDF6C: addiu       $t3, $t3, 0x0
    ctx->r11 = ADD32(ctx->r11, 0X0);
    // 0x800BDF70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF74: b           L_800BDF8C
    // 0x800BDF78: sw          $t3, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r11;
        goto L_800BDF8C;
    // 0x800BDF78: sw          $t3, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r11;
L_800BDF7C:
    // 0x800BDF7C: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x800BDF80: addiu       $t4, $t4, -0x5800
    ctx->r12 = ADD32(ctx->r12, -0X5800);
    // 0x800BDF84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF88: sw          $t4, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r12;
L_800BDF8C:
    // 0x800BDF8C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BDF90: lw          $a0, 0x24D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D0);
    // 0x800BDF94: jal         0x8008ECCC
    // 0x800BDF98: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_4;
    // 0x800BDF98: nop

    after_4:
    // 0x800BDF9C: jal         0x800C40D0
    // 0x800BDFA0: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x800BDFA0: nop

    after_5:
    // 0x800BDFA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDFA8: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x800BDFAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDFB0: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
    // 0x800BDFB4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BDFB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BDFBC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800BDFC0: lw          $t6, 0x2554($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2554);
    // 0x800BDFC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BDFC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDFCC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDFD0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BDFD4: swc1        $f6, 0x2538($at)
    MEM_W(0X2538, ctx->r1) = ctx->f6.u32l;
    // 0x800BDFD8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BDFDC: lw          $t8, 0x2554($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2554);
    // 0x800BDFE0: nop

    // 0x800BDFE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BDFE8: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x800BDFEC: beq         $at, $zero, L_800BE000
    if (ctx->r1 == 0) {
        // 0x800BDFF0: nop

            goto L_800BE000;
    }
    // 0x800BDFF0: nop

    // 0x800BDFF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDFF8: b           L_800BE008
    // 0x800BDFFC: sw          $t9, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = ctx->r25;
        goto L_800BE008;
    // 0x800BDFFC: sw          $t9, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = ctx->r25;
L_800BE000:
    // 0x800BE000: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE004: sw          $zero, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = 0;
L_800BE008:
    // 0x800BE008: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BE00C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800BE010: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_800BE014:
    // 0x800BE014: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BE018: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE01C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BE020: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800BE024: lwc1        $f16, 0x2538($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2538);
    // 0x800BE028: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BE02C: nop

    // 0x800BE030: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800BE034: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800BE038: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BE03C: nop

    // 0x800BE040: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BE044: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800BE048: bne         $at, $zero, L_800BE014
    if (ctx->r1 != 0) {
        // 0x800BE04C: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_800BE014;
    }
    // 0x800BE04C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BE050: b           L_800BE058
    // 0x800BE054: nop

        goto L_800BE058;
    // 0x800BE054: nop

L_800BE058:
    // 0x800BE058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE05C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE060: jr          $ra
    // 0x800BE064: nop

    return;
    // 0x800BE064: nop

;}
RECOMP_FUNC void func_800BE068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE068: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BE06C: lw          $t6, 0x2528($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2528);
    // 0x800BE070: nop

    // 0x800BE074: bne         $t6, $zero, L_800BE07C
    if (ctx->r14 != 0) {
        // 0x800BE078: nop

            goto L_800BE07C;
    }
    // 0x800BE078: nop

L_800BE07C:
    // 0x800BE07C: jr          $ra
    // 0x800BE080: nop

    return;
    // 0x800BE080: nop

    // 0x800BE084: jr          $ra
    // 0x800BE088: nop

    return;
    // 0x800BE088: nop

;}
RECOMP_FUNC void func_800BE08C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE08C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BE090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE094: jal         0x800C4270
    // 0x800BE098: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800BE098: nop

    after_0:
    // 0x800BE09C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE0A0: lw          $a0, 0x24D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D0);
    // 0x800BE0A4: jal         0x800C4080
    // 0x800BE0A8: nop

    osViSwapBuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE0A8: nop

    after_1:
    // 0x800BE0AC: b           L_800BE0B4
    // 0x800BE0B0: nop

        goto L_800BE0B4;
    // 0x800BE0B0: nop

L_800BE0B4:
    // 0x800BE0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE0B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BE0BC: jr          $ra
    // 0x800BE0C0: nop

    return;
    // 0x800BE0C0: nop

;}
RECOMP_FUNC void func_800BE0C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE0C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BE0C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE0CC: jal         0x800C4270
    // 0x800BE0D0: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800BE0D0: nop

    after_0:
    // 0x800BE0D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE0D8: lw          $a0, 0x24DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24DC);
    // 0x800BE0DC: jal         0x800C4080
    // 0x800BE0E0: nop

    osViSwapBuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE0E0: nop

    after_1:
    // 0x800BE0E4: b           L_800BE0EC
    // 0x800BE0E8: nop

        goto L_800BE0EC;
    // 0x800BE0E8: nop

L_800BE0EC:
    // 0x800BE0EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BE0F4: jr          $ra
    // 0x800BE0F8: nop

    return;
    // 0x800BE0F8: nop

;}
RECOMP_FUNC void Main_GfxInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE0FC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BE100: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800BE104: lw          $t6, 0x1B14($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B14);
    // 0x800BE108: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BE10C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BE110: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800BE114: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE118: mfhi        $t8
    ctx->r24 = hi;
    // 0x800BE11C: sw          $t8, 0x1B14($at)
    MEM_W(0X1B14, ctx->r1) = ctx->r24;
    // 0x800BE120: nop

    // 0x800BE124: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BE128: lhu         $t9, 0x24FC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X24FC);
    // 0x800BE12C: nop

    // 0x800BE130: beq         $t9, $zero, L_800BE140
    if (ctx->r25 == 0) {
        // 0x800BE134: nop

            goto L_800BE140;
    }
    // 0x800BE134: nop

    // 0x800BE138: b           L_800BE144
    // 0x800BE13C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800BE144;
    // 0x800BE13C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BE140:
    // 0x800BE140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800BE144:
    // 0x800BE144: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x800BE148: addiu       $t1, $t1, -0x64F8
    ctx->r9 = ADD32(ctx->r9, -0X64F8);
    // 0x800BE14C: sll         $t0, $a0, 15
    ctx->r8 = S32(ctx->r4 << 15);
    // 0x800BE150: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800BE154: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800BE158: sw          $t2, -0x6508($at)
    MEM_W(-0X6508, ctx->r1) = ctx->r10;
    // 0x800BE15C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x800BE160: lw          $t3, -0x6508($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6508);
    // 0x800BE164: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE168: sw          $t3, 0x1B4C($at)
    MEM_W(0X1B4C, ctx->r1) = ctx->r11;
    // 0x800BE16C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800BE170: lw          $t4, 0x1B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B4C);
    // 0x800BE174: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE178: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x800BE17C: b           L_800BE184
    // 0x800BE180: nop

        goto L_800BE184;
    // 0x800BE180: nop

L_800BE184:
    // 0x800BE184: jr          $ra
    // 0x800BE188: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BE188: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Main_GfxSetSegments(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE18C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BE190: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BE194: nop

    // 0x800BE198: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800BE19C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE1A0: nop

    // 0x800BE1A4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800BE1A8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800BE1AC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800BE1B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800BE1B4: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800BE1B8: ori         $t9, $t9, 0x6
    ctx->r25 = ctx->r25 | 0X6;
    // 0x800BE1BC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800BE1C0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800BE1C4: nop

    // 0x800BE1C8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800BE1CC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE1D0: nop

    // 0x800BE1D4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BE1D8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800BE1DC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800BE1E0: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BE1E4: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x800BE1E8: ori         $t4, $t4, 0x406
    ctx->r12 = ctx->r12 | 0X406;
    // 0x800BE1EC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800BE1F0: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x800BE1F4: lw          $t6, -0x6A04($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A04);
    // 0x800BE1F8: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800BE1FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE200: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800BE204: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BE208: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE20C: nop

    // 0x800BE210: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800BE214: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BE218: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800BE21C: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x800BE220: lui         $t1, 0xBC00
    ctx->r9 = S32(0XBC00 << 16);
    // 0x800BE224: ori         $t1, $t1, 0x806
    ctx->r9 = ctx->r9 | 0X806;
    // 0x800BE228: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800BE22C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x800BE230: lw          $t3, -0x6508($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6508);
    // 0x800BE234: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800BE238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE23C: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x800BE240: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800BE244: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE248: nop

    // 0x800BE24C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800BE250: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800BE254: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800BE258: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800BE25C: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x800BE260: ori         $t8, $t8, 0xC06
    ctx->r24 = ctx->r24 | 0XC06;
    // 0x800BE264: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800BE268: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BE26C: lw          $t0, 0x24DC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X24DC);
    // 0x800BE270: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800BE274: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE278: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800BE27C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800BE280: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE284: nop

    // 0x800BE288: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800BE28C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800BE290: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800BE294: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800BE298: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800BE29C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800BE2A0: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800BE2A4: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x800BE2A8: addiu       $t7, $t7, 0x58
    ctx->r15 = ADD32(ctx->r15, 0X58);
    // 0x800BE2AC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BE2B0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE2B4: nop

    // 0x800BE2B8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800BE2BC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BE2C0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800BE2C4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BE2C8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800BE2CC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800BE2D0: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800BE2D4: lui         $t3, 0x100
    ctx->r11 = S32(0X100 << 16);
    // 0x800BE2D8: addiu       $t3, $t3, 0x80
    ctx->r11 = ADD32(ctx->r11, 0X80);
    // 0x800BE2DC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800BE2E0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE2E4: nop

    // 0x800BE2E8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800BE2EC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800BE2F0: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x800BE2F4: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BE2F8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800BE2FC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800BE300: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800BE304: nop

    // 0x800BE308: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800BE30C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE310: nop

    // 0x800BE314: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800BE318: b           L_800BE320
    // 0x800BE31C: nop

        goto L_800BE320;
    // 0x800BE31C: nop

L_800BE320:
    // 0x800BE320: jr          $ra
    // 0x800BE324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800BE324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Main_GfxClearScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE328: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE32C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BE330: nop

    // 0x800BE334: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800BE338: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BE33C: nop

    // 0x800BE340: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800BE344: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800BE348: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800BE34C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800BE350: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800BE354: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x800BE358: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800BE35C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800BE360: lui         $t1, 0x30
    ctx->r9 = S32(0X30 << 16);
    // 0x800BE364: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800BE368: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800BE36C: nop

    // 0x800BE370: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800BE374: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800BE378: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800BE37C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE380: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x800BE384: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x800BE388: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800BE38C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE390: lui         $t7, 0xF0A
    ctx->r15 = S32(0XF0A << 16);
    // 0x800BE394: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x800BE398: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BE39C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BE3A0: nop

    // 0x800BE3A4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800BE3A8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800BE3AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800BE3B0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800BE3B4: lui         $t1, 0xFF10
    ctx->r9 = S32(0XFF10 << 16);
    // 0x800BE3B8: ori         $t1, $t1, 0x13F
    ctx->r9 = ctx->r9 | 0X13F;
    // 0x800BE3BC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800BE3C0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800BE3C4: lw          $t3, 0x7200($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7200);
    // 0x800BE3C8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800BE3CC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800BE3D0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800BE3D4: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800BE3D8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800BE3DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BE3E0: nop

    // 0x800BE3E4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800BE3E8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800BE3EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800BE3F0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800BE3F4: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x800BE3F8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800BE3FC: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800BE400: lui         $t0, 0xFFFC
    ctx->r8 = S32(0XFFFC << 16);
    // 0x800BE404: ori         $t0, $t0, 0xFFFC
    ctx->r8 = ctx->r8 | 0XFFFC;
    // 0x800BE408: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800BE40C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BE410: nop

    // 0x800BE414: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BE418: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BE41C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800BE420: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800BE424: lui         $t4, 0xF64F
    ctx->r12 = S32(0XF64F << 16);
    // 0x800BE428: ori         $t4, $t4, 0xC3BC
    ctx->r12 = ctx->r12 | 0XC3BC;
    // 0x800BE42C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800BE430: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800BE434: nop

    // 0x800BE438: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800BE43C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BE440: nop

    // 0x800BE444: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800BE448: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800BE44C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800BE450: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800BE454: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800BE458: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800BE45C: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800BE460: nop

    // 0x800BE464: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800BE468: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BE46C: nop

    // 0x800BE470: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BE474: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BE478: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800BE47C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800BE480: lui         $t4, 0xFE00
    ctx->r12 = S32(0XFE00 << 16);
    // 0x800BE484: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800BE488: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800BE48C: lw          $t6, 0x7200($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7200);
    // 0x800BE490: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800BE494: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800BE498: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800BE49C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800BE4A0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BE4A4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BE4A8: nop

    // 0x800BE4AC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800BE4B0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800BE4B4: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800BE4B8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BE4BC: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x800BE4C0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800BE4C4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800BE4C8: nop

    // 0x800BE4CC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800BE4D0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BE4D4: nop

    // 0x800BE4D8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800BE4DC: b           L_800BE4E4
    // 0x800BE4E0: nop

        goto L_800BE4E4;
    // 0x800BE4E0: nop

L_800BE4E4:
    // 0x800BE4E4: jr          $ra
    // 0x800BE4E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800BE4E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800BE4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE4EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BE4F0: lw          $t6, 0x2528($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2528);
    // 0x800BE4F4: nop

    // 0x800BE4F8: bne         $t6, $zero, L_800BE500
    if (ctx->r14 != 0) {
        // 0x800BE4FC: nop

            goto L_800BE500;
    }
    // 0x800BE4FC: nop

L_800BE500:
    // 0x800BE500: jr          $ra
    // 0x800BE504: nop

    return;
    // 0x800BE504: nop

    // 0x800BE508: jr          $ra
    // 0x800BE50C: nop

    return;
    // 0x800BE50C: nop

;}
RECOMP_FUNC void func_800BE510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE510: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE514: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BE518: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BE51C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800BE520: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800BE524: jal         0x800BE0FC
    // 0x800BE528: nop

    Main_GfxInit(rdram, ctx);
        goto after_0;
    // 0x800BE528: nop

    after_0:
    // 0x800BE52C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE530: jal         0x800BE18C
    // 0x800BE534: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    Main_GfxSetSegments(rdram, ctx);
        goto after_1;
    // 0x800BE534: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_1:
    // 0x800BE538: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE53C: jal         0x800BE328
    // 0x800BE540: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    Main_GfxClearScreen(rdram, ctx);
        goto after_2;
    // 0x800BE540: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_2:
    // 0x800BE544: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE548: jal         0x800ABC30
    // 0x800BE54C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_800ABC30(rdram, ctx);
        goto after_3;
    // 0x800BE54C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_3:
    // 0x800BE550: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE554: jal         0x800AC524
    // 0x800BE558: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_800AC524(rdram, ctx);
        goto after_4;
    // 0x800BE558: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_4:
    // 0x800BE55C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BE564: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800BE568: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE56C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800BE570: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BE574: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE578: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800BE57C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE580: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800BE584: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800BE588: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800BE58C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800BE590: jal         0x800B0E88
    // 0x800BE594: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800B0E88(rdram, ctx);
        goto after_5;
    // 0x800BE594: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x800BE598: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800BE59C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5A0: swc1        $f10, 0x25A0($at)
    MEM_W(0X25A0, ctx->r1) = ctx->f10.u32l;
    // 0x800BE5A4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BE5A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5AC: swc1        $f16, 0x25A8($at)
    MEM_W(0X25A8, ctx->r1) = ctx->f16.u32l;
    // 0x800BE5B0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800BE5B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5B8: swc1        $f18, 0x25B0($at)
    MEM_W(0X25B0, ctx->r1) = ctx->f18.u32l;
    // 0x800BE5BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE5C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BE5C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5C8: swc1        $f4, 0x25B8($at)
    MEM_W(0X25B8, ctx->r1) = ctx->f4.u32l;
    // 0x800BE5CC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800BE5D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE5D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5D8: swc1        $f6, 0x25C0($at)
    MEM_W(0X25C0, ctx->r1) = ctx->f6.u32l;
    // 0x800BE5DC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800BE5E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BE5E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5E8: swc1        $f8, 0x25C8($at)
    MEM_W(0X25C8, ctx->r1) = ctx->f8.u32l;
    // 0x800BE5EC: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800BE5F0: jal         0x80099FB0
    // 0x800BE5F4: nop

    func_80099FB0(rdram, ctx);
        goto after_6;
    // 0x800BE5F4: nop

    after_6:
    // 0x800BE5F8: b           L_800BE600
    // 0x800BE5FC: nop

        goto L_800BE600;
    // 0x800BE5FC: nop

L_800BE600:
    // 0x800BE600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BE604: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE608: jr          $ra
    // 0x800BE60C: nop

    return;
    // 0x800BE60C: nop

;}
RECOMP_FUNC void Main_GfxFullSync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE610: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BE614: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800BE618: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x800BE61C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE620: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800BE624: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x800BE628: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BE62C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800BE630: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x800BE634: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800BE638: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800BE63C: nop

    // 0x800BE640: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800BE644: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800BE648: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x800BE64C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE650: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800BE654: sw          $t2, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r10;
    // 0x800BE658: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800BE65C: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800BE660: lui         $t3, 0xB800
    ctx->r11 = S32(0XB800 << 16);
    // 0x800BE664: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800BE668: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800BE66C: nop

    // 0x800BE670: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800BE674: b           L_800BE67C
    // 0x800BE678: nop

        goto L_800BE67C;
    // 0x800BE678: nop

L_800BE67C:
    // 0x800BE67C: jr          $ra
    // 0x800BE680: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BE680: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800BE684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE684: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE68C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800BE690: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x800BE694: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE698: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800BE69C: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x800BE6A0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800BE6A4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BE6A8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800BE6AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800BE6B0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BE6B4: lui         $t0, 0x100
    ctx->r8 = S32(0X100 << 16);
    // 0x800BE6B8: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
    // 0x800BE6BC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800BE6C0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800BE6C4: lw          $t2, 0x1B44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1B44);
    // 0x800BE6C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE6CC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BE6D0: sw          $t3, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r11;
    // 0x800BE6D4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800BE6D8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BE6DC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800BE6E0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800BE6E4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BE6E8: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x800BE6EC: addiu       $t6, $t6, 0x58
    ctx->r14 = ADD32(ctx->r14, 0X58);
    // 0x800BE6F0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800BE6F4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800BE6F8: lw          $t8, 0x1B44($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B44);
    // 0x800BE6FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE700: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800BE704: sw          $t9, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r25;
    // 0x800BE708: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800BE70C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE710: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800BE714: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800BE718: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE71C: nop

    // 0x800BE720: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800BE724: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE728: jal         0x800BE328
    // 0x800BE72C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    Main_GfxClearScreen(rdram, ctx);
        goto after_0;
    // 0x800BE72C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_0:
    // 0x800BE730: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800BE734: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x800BE738: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE73C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800BE740: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x800BE744: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800BE748: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800BE74C: lui         $t5, 0xFF10
    ctx->r13 = S32(0XFF10 << 16);
    // 0x800BE750: ori         $t5, $t5, 0x13F
    ctx->r13 = ctx->r13 | 0X13F;
    // 0x800BE754: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800BE758: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BE75C: lw          $t7, 0x24DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X24DC);
    // 0x800BE760: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800BE764: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE768: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800BE76C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800BE770: b           L_800BE778
    // 0x800BE774: nop

        goto L_800BE778;
    // 0x800BE774: nop

L_800BE778:
    // 0x800BE778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE77C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE780: jr          $ra
    // 0x800BE784: nop

    return;
    // 0x800BE784: nop

;}
RECOMP_FUNC void Main_Unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE788: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BE78C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BE790: b           L_800BE798
    // 0x800BE794: nop

        goto L_800BE798;
    // 0x800BE794: nop

L_800BE798:
    // 0x800BE798: jr          $ra
    // 0x800BE79C: nop

    return;
    // 0x800BE79C: nop

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
