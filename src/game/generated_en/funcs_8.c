#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800527B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800527B4: jr          $ra
    // 0x800527B8: nop

    return;
    // 0x800527B8: nop

    // 0x800527BC: jr          $ra
    // 0x800527C0: nop

    return;
    // 0x800527C0: nop

;}
RECOMP_FUNC void func_800527C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800527C4: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800527C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800527CC: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800527D0: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800527D4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800527D8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800527DC: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800527E0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800527E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800527E8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800527EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800527F0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800527F4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800527F8: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800527FC: lui         $at, 0xFBFB
    ctx->r1 = S32(0XFBFB << 16);
    // 0x80052800: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80052804: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80052808: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8005280C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80052810: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x80052814: nop

    // 0x80052818: beq         $t7, $zero, L_80052830
    if (ctx->r15 == 0) {
        // 0x8005281C: nop

            goto L_80052830;
    }
    // 0x8005281C: nop

    // 0x80052820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052824: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80052828: b           L_8005283C
    // 0x8005282C: cvt.d.s     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f20.d = CVT_D_S(ctx->f4.fl);
        goto L_8005283C;
    // 0x8005282C: cvt.d.s     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f20.d = CVT_D_S(ctx->f4.fl);
L_80052830:
    // 0x80052830: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x80052834: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80052838: nop

L_8005283C:
    // 0x8005283C: cvt.s.d     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d);
    ctx->f6.fl = CVT_S_D(ctx->f20.d);
    // 0x80052840: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052844: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80052848: jal         0x80054198
    // 0x8005284C: nop

    func_80054198(rdram, ctx);
        goto after_0;
    // 0x8005284C: nop

    after_0:
    // 0x80052850: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052854: jal         0x80054264
    // 0x80052858: nop

    func_80054264(rdram, ctx);
        goto after_1;
    // 0x80052858: nop

    after_1:
    // 0x8005285C: beq         $v0, $zero, L_80052888
    if (ctx->r2 == 0) {
        // 0x80052860: nop

            goto L_80052888;
    }
    // 0x80052860: nop

    // 0x80052864: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052868: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x8005286C: jal         0x80052508
    // 0x80052870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_2;
    // 0x80052870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80052874: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80052878: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005287C: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x80052880: b           L_80053564
    // 0x80052884: nop

        goto L_80053564;
    // 0x80052884: nop

L_80052888:
    // 0x80052888: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005288C: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80052890: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052894: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x80052898: nop

            goto L_800528FC;
    }
    // 0x80052898: nop

    // 0x8005289C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800528A0: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528A4: nop

            goto L_800528FC;
    }
    // 0x800528A4: nop

    // 0x800528A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800528AC: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528B0: nop

            goto L_800528FC;
    }
    // 0x800528B0: nop

    // 0x800528B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800528B8: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528BC: nop

            goto L_800528FC;
    }
    // 0x800528BC: nop

    // 0x800528C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800528C4: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528C8: nop

            goto L_800528FC;
    }
    // 0x800528C8: nop

    // 0x800528CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800528D0: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528D4: nop

            goto L_800528FC;
    }
    // 0x800528D4: nop

    // 0x800528D8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800528DC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800528E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800528E4: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x800528E8: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800528EC: bne         $t0, $zero, L_800528FC
    if (ctx->r8 != 0) {
        // 0x800528F0: andi        $t1, $t9, 0x1000
        ctx->r9 = ctx->r25 & 0X1000;
            goto L_800528FC;
    }
    // 0x800528F0: andi        $t1, $t9, 0x1000
    ctx->r9 = ctx->r25 & 0X1000;
    // 0x800528F4: beq         $t1, $zero, L_8005293C
    if (ctx->r9 == 0) {
        // 0x800528F8: nop

            goto L_8005293C;
    }
    // 0x800528F8: nop

L_800528FC:
    // 0x800528FC: jal         0x80061F08
    // 0x80052900: nop

    func_80061F08(rdram, ctx);
        goto after_3;
    // 0x80052900: nop

    after_3:
    // 0x80052904: bne         $v0, $zero, L_8005293C
    if (ctx->r2 != 0) {
        // 0x80052908: nop

            goto L_8005293C;
    }
    // 0x80052908: nop

    // 0x8005290C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80052910: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x80052914: nop

    // 0x80052918: slti        $at, $t5, 0x6
    ctx->r1 = SIGNED(ctx->r13) < 0X6 ? 1 : 0;
    // 0x8005291C: beq         $at, $zero, L_80052934
    if (ctx->r1 == 0) {
        // 0x80052920: nop

            goto L_80052934;
    }
    // 0x80052920: nop

    // 0x80052924: jal         0x8005A578
    // 0x80052928: nop

    func_8005A578(rdram, ctx);
        goto after_4;
    // 0x80052928: nop

    after_4:
    // 0x8005292C: beq         $v0, $zero, L_8005293C
    if (ctx->r2 == 0) {
        // 0x80052930: nop

            goto L_8005293C;
    }
    // 0x80052930: nop

L_80052934:
    // 0x80052934: b           L_80053564
    // 0x80052938: nop

        goto L_80053564;
    // 0x80052938: nop

L_8005293C:
    // 0x8005293C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052940: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80052944: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052948: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8005294C: lh          $t2, 0xC($t6)
    ctx->r10 = MEM_H(ctx->r14, 0XC);
    // 0x80052950: lh          $t4, 0xE($t6)
    ctx->r12 = MEM_H(ctx->r14, 0XE);
    // 0x80052954: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x80052958: lw          $t0, 0x678($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X678);
    // 0x8005295C: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x80052960: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80052964: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80052968: beq         $at, $zero, L_8005298C
    if (ctx->r1 == 0) {
        // 0x8005296C: nop

            goto L_8005298C;
    }
    // 0x8005296C: nop

    // 0x80052970: lw          $t1, 0x104($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X104);
    // 0x80052974: nop

    // 0x80052978: bne         $t1, $zero, L_8005298C
    if (ctx->r9 != 0) {
        // 0x8005297C: nop

            goto L_8005298C;
    }
    // 0x8005297C: nop

    // 0x80052980: addiu       $t5, $zero, 0x8E
    ctx->r13 = ADD32(0, 0X8E);
    // 0x80052984: b           L_80052994
    // 0x80052988: sh          $t5, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r13;
        goto L_80052994;
    // 0x80052988: sh          $t5, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r13;
L_8005298C:
    // 0x8005298C: addiu       $t7, $zero, 0x71
    ctx->r15 = ADD32(0, 0X71);
    // 0x80052990: sh          $t7, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r15;
L_80052994:
    // 0x80052994: lh          $t2, 0xF6($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XF6);
    // 0x80052998: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x8005299C: bne         $t2, $at, L_800529E0
    if (ctx->r10 != ctx->r1) {
        // 0x800529A0: nop

            goto L_800529E0;
    }
    // 0x800529A0: nop

    // 0x800529A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800529A8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800529AC: nop

    // 0x800529B0: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x800529B4: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x800529B8: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x800529BC: ori         $t9, $t5, 0x80
    ctx->r25 = ctx->r13 | 0X80;
    // 0x800529C0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800529C4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800529C8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800529CC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800529D0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800529D4: lw          $t3, 0x258C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X258C);
    // 0x800529D8: nop

    // 0x800529DC: sw          $t3, 0x90($t0)
    MEM_W(0X90, ctx->r8) = ctx->r11;
L_800529E0:
    // 0x800529E0: lh          $a0, 0xF6($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XF6);
    // 0x800529E4: jal         0x80056E88
    // 0x800529E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_5;
    // 0x800529E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800529EC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800529F0: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800529F4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800529F8: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800529FC: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80052A00: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x80052A04: lh          $a1, 0x42($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X42);
    // 0x80052A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052A0C: jal         0x8004EF90
    // 0x80052A10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_6;
    // 0x80052A10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80052A14: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80052A18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052A1C: sh          $t2, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r10;
L_80052A20:
    // 0x80052A20: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80052A24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052A28: sh          $t4, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r12;
L_80052A2C:
    // 0x80052A2C: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052A30: jal         0x800499B0
    // 0x80052A34: nop

    func_800499B0(rdram, ctx);
        goto after_7;
    // 0x80052A34: nop

    after_7:
    // 0x80052A38: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80052A3C: lbu         $t5, 0xD74($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0XD74);
    // 0x80052A40: nop

    // 0x80052A44: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80052A48: bne         $at, $zero, L_80052AEC
    if (ctx->r1 != 0) {
        // 0x80052A4C: nop

            goto L_80052AEC;
    }
    // 0x80052A4C: nop

    // 0x80052A50: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052A54: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052A58: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80052A5C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80052A60: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80052A64: bne         $t0, $zero, L_80052A74
    if (ctx->r8 != 0) {
        // 0x80052A68: andi        $t1, $t7, 0x80
        ctx->r9 = ctx->r15 & 0X80;
            goto L_80052A74;
    }
    // 0x80052A68: andi        $t1, $t7, 0x80
    ctx->r9 = ctx->r15 & 0X80;
    // 0x80052A6C: beq         $t1, $zero, L_80052AEC
    if (ctx->r9 == 0) {
        // 0x80052A70: nop

            goto L_80052AEC;
    }
    // 0x80052A70: nop

L_80052A74:
    // 0x80052A74: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80052A78: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80052A7C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80052A80: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x80052A84: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80052A88: bne         $t4, $zero, L_80052A98
    if (ctx->r12 != 0) {
        // 0x80052A8C: andi        $t5, $t3, 0x8
        ctx->r13 = ctx->r11 & 0X8;
            goto L_80052A98;
    }
    // 0x80052A8C: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x80052A90: beq         $t5, $zero, L_80052AA0
    if (ctx->r13 == 0) {
        // 0x80052A94: nop

            goto L_80052AA0;
    }
    // 0x80052A94: nop

L_80052A98:
    // 0x80052A98: b           L_80052AA4
    // 0x80052A9C: addiu       $s1, $zero, -0x3C
    ctx->r17 = ADD32(0, -0X3C);
        goto L_80052AA4;
    // 0x80052A9C: addiu       $s1, $zero, -0x3C
    ctx->r17 = ADD32(0, -0X3C);
L_80052AA0:
    // 0x80052AA0: addiu       $s1, $zero, 0x3C
    ctx->r17 = ADD32(0, 0X3C);
L_80052AA4:
    // 0x80052AA4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052AA8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052AAC: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80052AB0: lw          $a1, 0x4C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4C);
    // 0x80052AB4: lw          $a2, 0x50($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X50);
    // 0x80052AB8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80052ABC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80052AC0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80052AC4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80052AC8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80052ACC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80052AD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052AD4: jal         0x80077FF0
    // 0x80052AD8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_80077FF0(rdram, ctx);
        goto after_8;
    // 0x80052AD8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x80052ADC: beq         $v0, $zero, L_80052AEC
    if (ctx->r2 == 0) {
        // 0x80052AE0: nop

            goto L_80052AEC;
    }
    // 0x80052AE0: nop

    // 0x80052AE4: b           L_800532C4
    // 0x80052AE8: nop

        goto L_800532C4;
    // 0x80052AE8: nop

L_80052AEC:
    // 0x80052AEC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80052AF0: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80052AF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80052AF8: bne         $t7, $at, L_80052B60
    if (ctx->r15 != ctx->r1) {
        // 0x80052AFC: nop

            goto L_80052B60;
    }
    // 0x80052AFC: nop

    // 0x80052B00: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052B04: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x80052B08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052B0C: beq         $t0, $at, L_80052B60
    if (ctx->r8 == ctx->r1) {
        // 0x80052B10: nop

            goto L_80052B60;
    }
    // 0x80052B10: nop

    // 0x80052B14: jal         0x80057960
    // 0x80052B18: nop

    func_80057960(rdram, ctx);
        goto after_9;
    // 0x80052B18: nop

    after_9:
    // 0x80052B1C: bne         $v0, $zero, L_80052B60
    if (ctx->r2 != 0) {
        // 0x80052B20: nop

            goto L_80052B60;
    }
    // 0x80052B20: nop

    // 0x80052B24: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052B28: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80052B2C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80052B30: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80052B34: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80052B38: bne         $t4, $zero, L_80052B60
    if (ctx->r12 != 0) {
        // 0x80052B3C: andi        $t5, $t3, 0x1000
        ctx->r13 = ctx->r11 & 0X1000;
            goto L_80052B60;
    }
    // 0x80052B3C: andi        $t5, $t3, 0x1000
    ctx->r13 = ctx->r11 & 0X1000;
    // 0x80052B40: bne         $t5, $zero, L_80052B60
    if (ctx->r13 != 0) {
        // 0x80052B44: nop

            goto L_80052B60;
    }
    // 0x80052B44: nop

    // 0x80052B48: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80052B4C: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80052B50: bne         $t8, $zero, L_80052B60
    if (ctx->r24 != 0) {
        // 0x80052B54: and         $t9, $t3, $at
        ctx->r25 = ctx->r11 & ctx->r1;
            goto L_80052B60;
    }
    // 0x80052B54: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80052B58: beq         $t9, $zero, L_80052A2C
    if (ctx->r25 == 0) {
        // 0x80052B5C: nop

            goto L_80052A2C;
    }
    // 0x80052B5C: nop

L_80052B60:
    // 0x80052B60: jal         0x80057960
    // 0x80052B64: nop

    func_80057960(rdram, ctx);
        goto after_10;
    // 0x80052B64: nop

    after_10:
    // 0x80052B68: beq         $v0, $zero, L_80052B84
    if (ctx->r2 == 0) {
        // 0x80052B6C: nop

            goto L_80052B84;
    }
    // 0x80052B6C: nop

    // 0x80052B70: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80052B74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052B78: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x80052B7C: b           L_80053554
    // 0x80052B80: nop

        goto L_80053554;
    // 0x80052B80: nop

L_80052B84:
    // 0x80052B84: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80052B88: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80052B8C: nop

    // 0x80052B90: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80052B94: beq         $at, $zero, L_80052BB4
    if (ctx->r1 == 0) {
        // 0x80052B98: nop

            goto L_80052BB4;
    }
    // 0x80052B98: nop

    // 0x80052B9C: jal         0x8005A578
    // 0x80052BA0: nop

    func_8005A578(rdram, ctx);
        goto after_11;
    // 0x80052BA0: nop

    after_11:
    // 0x80052BA4: bne         $v0, $zero, L_80052BB4
    if (ctx->r2 != 0) {
        // 0x80052BA8: nop

            goto L_80052BB4;
    }
    // 0x80052BA8: nop

    // 0x80052BAC: b           L_80052A20
    // 0x80052BB0: nop

        goto L_80052A20;
    // 0x80052BB0: nop

L_80052BB4:
    // 0x80052BB4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052BB8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80052BBC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80052BC0: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80052BC4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80052BC8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80052BCC: bne         $t2, $zero, L_80052BDC
    if (ctx->r10 != 0) {
        // 0x80052BD0: and         $t3, $t5, $at
        ctx->r11 = ctx->r13 & ctx->r1;
            goto L_80052BDC;
    }
    // 0x80052BD0: and         $t3, $t5, $at
    ctx->r11 = ctx->r13 & ctx->r1;
    // 0x80052BD4: beq         $t3, $zero, L_80052C20
    if (ctx->r11 == 0) {
        // 0x80052BD8: nop

            goto L_80052C20;
    }
    // 0x80052BD8: nop

L_80052BDC:
    // 0x80052BDC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052BE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052BE4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052BE8: lw          $t1, 0x258C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X258C);
    // 0x80052BEC: nop

    // 0x80052BF0: sw          $t1, 0x94($t8)
    MEM_W(0X94, ctx->r24) = ctx->r9;
    // 0x80052BF4: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052BF8: jal         0x80054618
    // 0x80052BFC: nop

    func_80054618(rdram, ctx);
        goto after_12;
    // 0x80052BFC: nop

    after_12:
    // 0x80052C00: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052C04: jal         0x800543B0
    // 0x80052C08: nop

    func_800543B0(rdram, ctx);
        goto after_13;
    // 0x80052C08: nop

    after_13:
    // 0x80052C0C: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80052C10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052C14: sh          $t9, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r25;
    // 0x80052C18: b           L_80053554
    // 0x80052C1C: nop

        goto L_80053554;
    // 0x80052C1C: nop

L_80052C20:
    // 0x80052C20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052C24: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80052C28: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80052C2C: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80052C30: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80052C34: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80052C38: bne         $t4, $zero, L_80052C48
    if (ctx->r12 != 0) {
        // 0x80052C3C: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_80052C48;
    }
    // 0x80052C3C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80052C40: beq         $t5, $zero, L_80052DF4
    if (ctx->r13 == 0) {
        // 0x80052C44: nop

            goto L_80052DF4;
    }
    // 0x80052C44: nop

L_80052C48:
    // 0x80052C48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80052C4C: lh          $t7, 0x12BA($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X12BA);
    // 0x80052C50: nop

    // 0x80052C54: andi        $t2, $t7, 0xC0
    ctx->r10 = ctx->r15 & 0XC0;
    // 0x80052C58: bne         $t2, $zero, L_80052C68
    if (ctx->r10 != 0) {
        // 0x80052C5C: nop

            goto L_80052C68;
    }
    // 0x80052C5C: nop

    // 0x80052C60: b           L_800532C4
    // 0x80052C64: nop

        goto L_800532C4;
    // 0x80052C64: nop

L_80052C68:
    // 0x80052C68: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052C6C: lbu         $t3, 0xD74($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0XD74);
    // 0x80052C70: nop

    // 0x80052C74: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x80052C78: bne         $at, $zero, L_80052C88
    if (ctx->r1 != 0) {
        // 0x80052C7C: nop

            goto L_80052C88;
    }
    // 0x80052C7C: nop

    // 0x80052C80: b           L_800532C4
    // 0x80052C84: nop

        goto L_800532C4;
    // 0x80052C84: nop

L_80052C88:
    // 0x80052C88: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052C8C: lbu         $t8, 0xD74($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0XD74);
    // 0x80052C90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052C94: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80052C98: sb          $t9, 0xD74($at)
    MEM_B(0XD74, ctx->r1) = ctx->r25;
    // 0x80052C9C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052CA0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80052CA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052CA8: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80052CAC: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80052CB0: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x80052CB4: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x80052CB8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80052CBC: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80052CC0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80052CC4: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80052CC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80052CCC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052CD0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80052CD4: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x80052CD8: nop

    // 0x80052CDC: sw          $t7, 0x94($t2)
    MEM_W(0X94, ctx->r10) = ctx->r15;
    // 0x80052CE0: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052CE4: jal         0x800507AC
    // 0x80052CE8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    func_800507AC(rdram, ctx);
        goto after_14;
    // 0x80052CE8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    after_14:
    // 0x80052CEC: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052CF0: jal         0x800507AC
    // 0x80052CF4: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800507AC(rdram, ctx);
        goto after_15;
    // 0x80052CF4: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_15:
    // 0x80052CF8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052CFC: jal         0x800543B0
    // 0x80052D00: nop

    func_800543B0(rdram, ctx);
        goto after_16;
    // 0x80052D00: nop

    after_16:
    // 0x80052D04: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052D08: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    // 0x80052D0C: jal         0x80052508
    // 0x80052D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_17;
    // 0x80052D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80052D14: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052D18: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80052D1C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052D20: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D24: nop

            goto L_80052D88;
    }
    // 0x80052D24: nop

    // 0x80052D28: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80052D2C: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D30: nop

            goto L_80052D88;
    }
    // 0x80052D30: nop

    // 0x80052D34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052D38: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D3C: nop

            goto L_80052D88;
    }
    // 0x80052D3C: nop

    // 0x80052D40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052D44: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D48: nop

            goto L_80052D88;
    }
    // 0x80052D48: nop

    // 0x80052D4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052D50: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D54: nop

            goto L_80052D88;
    }
    // 0x80052D54: nop

    // 0x80052D58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80052D5C: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D60: nop

            goto L_80052D88;
    }
    // 0x80052D60: nop

    // 0x80052D64: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052D68: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052D6C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80052D70: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80052D74: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80052D78: bne         $t4, $zero, L_80052D88
    if (ctx->r12 != 0) {
        // 0x80052D7C: andi        $t5, $t1, 0x1000
        ctx->r13 = ctx->r9 & 0X1000;
            goto L_80052D88;
    }
    // 0x80052D7C: andi        $t5, $t1, 0x1000
    ctx->r13 = ctx->r9 & 0X1000;
    // 0x80052D80: beq         $t5, $zero, L_80052DC8
    if (ctx->r13 == 0) {
        // 0x80052D84: nop

            goto L_80052DC8;
    }
    // 0x80052D84: nop

L_80052D88:
    // 0x80052D88: jal         0x80061F08
    // 0x80052D8C: nop

    func_80061F08(rdram, ctx);
        goto after_18;
    // 0x80052D8C: nop

    after_18:
    // 0x80052D90: bne         $v0, $zero, L_80052DC8
    if (ctx->r2 != 0) {
        // 0x80052D94: nop

            goto L_80052DC8;
    }
    // 0x80052D94: nop

    // 0x80052D98: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80052D9C: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x80052DA0: nop

    // 0x80052DA4: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80052DA8: beq         $at, $zero, L_80052DC0
    if (ctx->r1 == 0) {
        // 0x80052DAC: nop

            goto L_80052DC0;
    }
    // 0x80052DAC: nop

    // 0x80052DB0: jal         0x8005A578
    // 0x80052DB4: nop

    func_8005A578(rdram, ctx);
        goto after_19;
    // 0x80052DB4: nop

    after_19:
    // 0x80052DB8: beq         $v0, $zero, L_80052DC8
    if (ctx->r2 == 0) {
        // 0x80052DBC: nop

            goto L_80052DC8;
    }
    // 0x80052DBC: nop

L_80052DC0:
    // 0x80052DC0: b           L_80053554
    // 0x80052DC4: nop

        goto L_80053554;
    // 0x80052DC4: nop

L_80052DC8:
    // 0x80052DC8: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x80052DCC: nop

    // 0x80052DD0: bne         $t6, $zero, L_80052DE4
    if (ctx->r14 != 0) {
        // 0x80052DD4: nop

            goto L_80052DE4;
    }
    // 0x80052DD4: nop

    // 0x80052DD8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052DDC: jal         0x80054198
    // 0x80052DE0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80054198(rdram, ctx);
        goto after_20;
    // 0x80052DE0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_20:
L_80052DE4:
    // 0x80052DE4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80052DE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052DEC: b           L_80053540
    // 0x80052DF0: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
        goto L_80053540;
    // 0x80052DF0: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
L_80052DF4:
    // 0x80052DF4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052DF8: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x80052DFC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052E00: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E04: nop

            goto L_80052E68;
    }
    // 0x80052E04: nop

    // 0x80052E08: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80052E0C: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E10: nop

            goto L_80052E68;
    }
    // 0x80052E10: nop

    // 0x80052E14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052E18: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E1C: nop

            goto L_80052E68;
    }
    // 0x80052E1C: nop

    // 0x80052E20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052E24: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E28: nop

            goto L_80052E68;
    }
    // 0x80052E28: nop

    // 0x80052E2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052E30: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E34: nop

            goto L_80052E68;
    }
    // 0x80052E34: nop

    // 0x80052E38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80052E3C: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E40: nop

            goto L_80052E68;
    }
    // 0x80052E40: nop

    // 0x80052E44: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052E48: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80052E4C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80052E50: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80052E54: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80052E58: bne         $t0, $zero, L_80052E68
    if (ctx->r8 != 0) {
        // 0x80052E5C: andi        $t1, $t9, 0x1000
        ctx->r9 = ctx->r25 & 0X1000;
            goto L_80052E68;
    }
    // 0x80052E5C: andi        $t1, $t9, 0x1000
    ctx->r9 = ctx->r25 & 0X1000;
    // 0x80052E60: beq         $t1, $zero, L_80052EB0
    if (ctx->r9 == 0) {
        // 0x80052E64: nop

            goto L_80052EB0;
    }
    // 0x80052E64: nop

L_80052E68:
    // 0x80052E68: jal         0x80061F08
    // 0x80052E6C: nop

    func_80061F08(rdram, ctx);
        goto after_21;
    // 0x80052E6C: nop

    after_21:
    // 0x80052E70: bne         $v0, $zero, L_80052EB0
    if (ctx->r2 != 0) {
        // 0x80052E74: nop

            goto L_80052EB0;
    }
    // 0x80052E74: nop

    // 0x80052E78: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80052E7C: lh          $t4, 0x10F0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10F0);
    // 0x80052E80: nop

    // 0x80052E84: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x80052E88: beq         $at, $zero, L_80052EA0
    if (ctx->r1 == 0) {
        // 0x80052E8C: nop

            goto L_80052EA0;
    }
    // 0x80052E8C: nop

    // 0x80052E90: jal         0x8005A578
    // 0x80052E94: nop

    func_8005A578(rdram, ctx);
        goto after_22;
    // 0x80052E94: nop

    after_22:
    // 0x80052E98: beq         $v0, $zero, L_80052EA8
    if (ctx->r2 == 0) {
        // 0x80052E9C: nop

            goto L_80052EA8;
    }
    // 0x80052E9C: nop

L_80052EA0:
    // 0x80052EA0: b           L_800532D0
    // 0x80052EA4: nop

        goto L_800532D0;
    // 0x80052EA4: nop

L_80052EA8:
    // 0x80052EA8: b           L_80053540
    // 0x80052EAC: nop

        goto L_80053540;
    // 0x80052EAC: nop

L_80052EB0:
    // 0x80052EB0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80052EB4: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x80052EB8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80052EBC: bne         $t5, $at, L_8005329C
    if (ctx->r13 != ctx->r1) {
        // 0x80052EC0: nop

            goto L_8005329C;
    }
    // 0x80052EC0: nop

    // 0x80052EC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052EC8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80052ECC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80052ED0: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80052ED4: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80052ED8: bne         $t8, $zero, L_80052EE8
    if (ctx->r24 != 0) {
        // 0x80052EDC: andi        $t9, $t3, 0x80
        ctx->r25 = ctx->r11 & 0X80;
            goto L_80052EE8;
    }
    // 0x80052EDC: andi        $t9, $t3, 0x80
    ctx->r25 = ctx->r11 & 0X80;
    // 0x80052EE0: beq         $t9, $zero, L_80052EF8
    if (ctx->r25 == 0) {
        // 0x80052EE4: nop

            goto L_80052EF8;
    }
    // 0x80052EE4: nop

L_80052EE8:
    // 0x80052EE8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80052EEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052EF0: b           L_80053294
    // 0x80052EF4: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
        goto L_80053294;
    // 0x80052EF4: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
L_80052EF8:
    // 0x80052EF8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80052EFC: lw          $a1, 0xE60($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XE60);
    // 0x80052F00: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052F04: jal         0x80054198
    // 0x80052F08: nop

    func_80054198(rdram, ctx);
        goto after_23;
    // 0x80052F08: nop

    after_23:
    // 0x80052F0C: beq         $v0, $zero, L_800530F8
    if (ctx->r2 == 0) {
        // 0x80052F10: nop

            goto L_800530F8;
    }
    // 0x80052F10: nop

    // 0x80052F14: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052F18: lh          $t0, 0x10F0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X10F0);
    // 0x80052F1C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052F20: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F24: nop

            goto L_80052F88;
    }
    // 0x80052F24: nop

    // 0x80052F28: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80052F2C: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F30: nop

            goto L_80052F88;
    }
    // 0x80052F30: nop

    // 0x80052F34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052F38: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F3C: nop

            goto L_80052F88;
    }
    // 0x80052F3C: nop

    // 0x80052F40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052F44: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F48: nop

            goto L_80052F88;
    }
    // 0x80052F48: nop

    // 0x80052F4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052F50: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F54: nop

            goto L_80052F88;
    }
    // 0x80052F54: nop

    // 0x80052F58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80052F5C: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F60: nop

            goto L_80052F88;
    }
    // 0x80052F60: nop

    // 0x80052F64: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052F68: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80052F6C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80052F70: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x80052F74: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80052F78: bne         $t6, $zero, L_80052F88
    if (ctx->r14 != 0) {
        // 0x80052F7C: andi        $t7, $t5, 0x1000
        ctx->r15 = ctx->r13 & 0X1000;
            goto L_80052F88;
    }
    // 0x80052F7C: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x80052F80: beq         $t7, $zero, L_80052FC8
    if (ctx->r15 == 0) {
        // 0x80052F84: nop

            goto L_80052FC8;
    }
    // 0x80052F84: nop

L_80052F88:
    // 0x80052F88: jal         0x80061F08
    // 0x80052F8C: nop

    func_80061F08(rdram, ctx);
        goto after_24;
    // 0x80052F8C: nop

    after_24:
    // 0x80052F90: bne         $v0, $zero, L_80052FC8
    if (ctx->r2 != 0) {
        // 0x80052F94: nop

            goto L_80052FC8;
    }
    // 0x80052F94: nop

    // 0x80052F98: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052F9C: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x80052FA0: nop

    // 0x80052FA4: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x80052FA8: beq         $at, $zero, L_80052FC0
    if (ctx->r1 == 0) {
        // 0x80052FAC: nop

            goto L_80052FC0;
    }
    // 0x80052FAC: nop

    // 0x80052FB0: jal         0x8005A578
    // 0x80052FB4: nop

    func_8005A578(rdram, ctx);
        goto after_25;
    // 0x80052FB4: nop

    after_25:
    // 0x80052FB8: beq         $v0, $zero, L_80052FC8
    if (ctx->r2 == 0) {
        // 0x80052FBC: nop

            goto L_80052FC8;
    }
    // 0x80052FBC: nop

L_80052FC0:
    // 0x80052FC0: b           L_80053554
    // 0x80052FC4: nop

        goto L_80053554;
    // 0x80052FC4: nop

L_80052FC8:
    // 0x80052FC8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052FCC: jal         0x80054264
    // 0x80052FD0: nop

    func_80054264(rdram, ctx);
        goto after_26;
    // 0x80052FD0: nop

    after_26:
    // 0x80052FD4: beq         $v0, $zero, L_800530B4
    if (ctx->r2 == 0) {
        // 0x80052FD8: nop

            goto L_800530B4;
    }
    // 0x80052FD8: nop

    // 0x80052FDC: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052FE0: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x80052FE4: jal         0x80052508
    // 0x80052FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_27;
    // 0x80052FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80052FEC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052FF0: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80052FF4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052FF8: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80052FFC: nop

            goto L_80053060;
    }
    // 0x80052FFC: nop

    // 0x80053000: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053004: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80053008: nop

            goto L_80053060;
    }
    // 0x80053008: nop

    // 0x8005300C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053010: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80053014: nop

            goto L_80053060;
    }
    // 0x80053014: nop

    // 0x80053018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005301C: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80053020: nop

            goto L_80053060;
    }
    // 0x80053020: nop

    // 0x80053024: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053028: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x8005302C: nop

            goto L_80053060;
    }
    // 0x8005302C: nop

    // 0x80053030: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053034: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80053038: nop

            goto L_80053060;
    }
    // 0x80053038: nop

    // 0x8005303C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80053040: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80053044: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80053048: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005304C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80053050: bne         $t4, $zero, L_80053060
    if (ctx->r12 != 0) {
        // 0x80053054: andi        $t5, $t1, 0x1000
        ctx->r13 = ctx->r9 & 0X1000;
            goto L_80053060;
    }
    // 0x80053054: andi        $t5, $t1, 0x1000
    ctx->r13 = ctx->r9 & 0X1000;
    // 0x80053058: beq         $t5, $zero, L_800530A0
    if (ctx->r13 == 0) {
        // 0x8005305C: nop

            goto L_800530A0;
    }
    // 0x8005305C: nop

L_80053060:
    // 0x80053060: jal         0x80061F08
    // 0x80053064: nop

    func_80061F08(rdram, ctx);
        goto after_28;
    // 0x80053064: nop

    after_28:
    // 0x80053068: bne         $v0, $zero, L_800530A0
    if (ctx->r2 != 0) {
        // 0x8005306C: nop

            goto L_800530A0;
    }
    // 0x8005306C: nop

    // 0x80053070: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80053074: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x80053078: nop

    // 0x8005307C: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80053080: beq         $at, $zero, L_80053098
    if (ctx->r1 == 0) {
        // 0x80053084: nop

            goto L_80053098;
    }
    // 0x80053084: nop

    // 0x80053088: jal         0x8005A578
    // 0x8005308C: nop

    func_8005A578(rdram, ctx);
        goto after_29;
    // 0x8005308C: nop

    after_29:
    // 0x80053090: beq         $v0, $zero, L_800530A0
    if (ctx->r2 == 0) {
        // 0x80053094: nop

            goto L_800530A0;
    }
    // 0x80053094: nop

L_80053098:
    // 0x80053098: b           L_80053554
    // 0x8005309C: nop

        goto L_80053554;
    // 0x8005309C: nop

L_800530A0:
    // 0x800530A0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800530A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800530A8: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x800530AC: b           L_80053554
    // 0x800530B0: nop

        goto L_80053554;
    // 0x800530B0: nop

L_800530B4:
    // 0x800530B4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x800530B8: jal         0x80056E88
    // 0x800530BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_30;
    // 0x800530BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x800530C0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800530C4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x800530C8: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800530CC: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800530D0: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800530D4: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x800530D8: lh          $a1, 0x42($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X42);
    // 0x800530DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800530E0: jal         0x8004EF90
    // 0x800530E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_31;
    // 0x800530E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_31:
    // 0x800530E8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800530EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800530F0: b           L_80053294
    // 0x800530F4: sh          $t3, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r11;
        goto L_80053294;
    // 0x800530F4: sh          $t3, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r11;
L_800530F8:
    // 0x800530F8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x800530FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053100: jal         0x80052508
    // 0x80053104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_32;
    // 0x80053104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x80053108: bne         $v0, $zero, L_80053294
    if (ctx->r2 != 0) {
        // 0x8005310C: nop

            goto L_80053294;
    }
    // 0x8005310C: nop

    // 0x80053110: jal         0x80061E14
    // 0x80053114: nop

    func_80061E14(rdram, ctx);
        goto after_33;
    // 0x80053114: nop

    after_33:
    // 0x80053118: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    // 0x8005311C: lw          $t8, 0xFC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XFC);
    // 0x80053120: nop

    // 0x80053124: beq         $t8, $zero, L_80053144
    if (ctx->r24 == 0) {
        // 0x80053128: nop

            goto L_80053144;
    }
    // 0x80053128: nop

    // 0x8005312C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80053130: beq         $t8, $at, L_80053144
    if (ctx->r24 == ctx->r1) {
        // 0x80053134: nop

            goto L_80053144;
    }
    // 0x80053134: nop

    // 0x80053138: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8005313C: bne         $t8, $at, L_80053294
    if (ctx->r24 != ctx->r1) {
        // 0x80053140: nop

            goto L_80053294;
    }
    // 0x80053140: nop

L_80053144:
    // 0x80053144: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80053148: jal         0x80054264
    // 0x8005314C: nop

    func_80054264(rdram, ctx);
        goto after_34;
    // 0x8005314C: nop

    after_34:
    // 0x80053150: beq         $v0, $zero, L_80053230
    if (ctx->r2 == 0) {
        // 0x80053154: nop

            goto L_80053230;
    }
    // 0x80053154: nop

    // 0x80053158: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x8005315C: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x80053160: jal         0x80052508
    // 0x80053164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_35;
    // 0x80053164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x80053168: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005316C: lh          $t0, 0x10F0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X10F0);
    // 0x80053170: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053174: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x80053178: nop

            goto L_800531DC;
    }
    // 0x80053178: nop

    // 0x8005317C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053180: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x80053184: nop

            goto L_800531DC;
    }
    // 0x80053184: nop

    // 0x80053188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005318C: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x80053190: nop

            goto L_800531DC;
    }
    // 0x80053190: nop

    // 0x80053194: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053198: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x8005319C: nop

            goto L_800531DC;
    }
    // 0x8005319C: nop

    // 0x800531A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800531A4: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x800531A8: nop

            goto L_800531DC;
    }
    // 0x800531A8: nop

    // 0x800531AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800531B0: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x800531B4: nop

            goto L_800531DC;
    }
    // 0x800531B4: nop

    // 0x800531B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800531BC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x800531C0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800531C4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x800531C8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800531CC: bne         $t6, $zero, L_800531DC
    if (ctx->r14 != 0) {
        // 0x800531D0: andi        $t7, $t5, 0x1000
        ctx->r15 = ctx->r13 & 0X1000;
            goto L_800531DC;
    }
    // 0x800531D0: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x800531D4: beq         $t7, $zero, L_8005321C
    if (ctx->r15 == 0) {
        // 0x800531D8: nop

            goto L_8005321C;
    }
    // 0x800531D8: nop

L_800531DC:
    // 0x800531DC: jal         0x80061F08
    // 0x800531E0: nop

    func_80061F08(rdram, ctx);
        goto after_36;
    // 0x800531E0: nop

    after_36:
    // 0x800531E4: bne         $v0, $zero, L_8005321C
    if (ctx->r2 != 0) {
        // 0x800531E8: nop

            goto L_8005321C;
    }
    // 0x800531E8: nop

    // 0x800531EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800531F0: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x800531F4: nop

    // 0x800531F8: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x800531FC: beq         $at, $zero, L_80053214
    if (ctx->r1 == 0) {
        // 0x80053200: nop

            goto L_80053214;
    }
    // 0x80053200: nop

    // 0x80053204: jal         0x8005A578
    // 0x80053208: nop

    func_8005A578(rdram, ctx);
        goto after_37;
    // 0x80053208: nop

    after_37:
    // 0x8005320C: beq         $v0, $zero, L_8005321C
    if (ctx->r2 == 0) {
        // 0x80053210: nop

            goto L_8005321C;
    }
    // 0x80053210: nop

L_80053214:
    // 0x80053214: b           L_80053554
    // 0x80053218: nop

        goto L_80053554;
    // 0x80053218: nop

L_8005321C:
    // 0x8005321C: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80053220: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80053224: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x80053228: b           L_80053554
    // 0x8005322C: nop

        goto L_80053554;
    // 0x8005322C: nop

L_80053230:
    // 0x80053230: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80053234: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80053238: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x8005323C: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80053240: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    // 0x80053244: jal         0x8004EF90
    // 0x80053248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_38;
    // 0x80053248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_38:
    // 0x8005324C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80053250: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80053254: nop

    // 0x80053258: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005325C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80053260: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80053264: ori         $t5, $t1, 0x80
    ctx->r13 = ctx->r9 | 0X80;
    // 0x80053268: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8005326C: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80053270: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80053274: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80053278: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x8005327C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80053280: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80053284: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80053288: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x8005328C: nop

    // 0x80053290: sw          $t7, 0x90($t9)
    MEM_W(0X90, ctx->r25) = ctx->r15;
L_80053294:
    // 0x80053294: b           L_80053540
    // 0x80053298: nop

        goto L_80053540;
    // 0x80053298: nop

L_8005329C:
    // 0x8005329C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800532A0: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x800532A4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800532A8: beq         $t2, $at, L_800532C4
    if (ctx->r10 == ctx->r1) {
        // 0x800532AC: nop

            goto L_800532C4;
    }
    // 0x800532AC: nop

    // 0x800532B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800532B4: lh          $t3, 0x6C0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X6C0);
    // 0x800532B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800532BC: bne         $t3, $at, L_80053540
    if (ctx->r11 != ctx->r1) {
        // 0x800532C0: nop

            goto L_80053540;
    }
    // 0x800532C0: nop

L_800532C4:
    // 0x800532C4: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800532C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800532CC: sh          $t0, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r8;
L_800532D0:
    // 0x800532D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800532D4: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x800532D8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800532DC: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x800532E0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800532E4: bne         $t8, $zero, L_800532F4
    if (ctx->r24 != 0) {
        // 0x800532E8: andi        $t9, $t5, 0x80
        ctx->r25 = ctx->r13 & 0X80;
            goto L_800532F4;
    }
    // 0x800532E8: andi        $t9, $t5, 0x80
    ctx->r25 = ctx->r13 & 0X80;
    // 0x800532EC: beq         $t9, $zero, L_800533E4
    if (ctx->r25 == 0) {
        // 0x800532F0: nop

            goto L_800533E4;
    }
    // 0x800532F0: nop

L_800532F4:
    // 0x800532F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800532F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800532FC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80053300: lw          $t6, 0x258C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X258C);
    // 0x80053304: nop

    // 0x80053308: sw          $t6, 0x94($t7)
    MEM_W(0X94, ctx->r15) = ctx->r14;
    // 0x8005330C: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    // 0x80053310: jal         0x80056E88
    // 0x80053314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_39;
    // 0x80053314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80053318: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005331C: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80053320: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80053324: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80053328: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8005332C: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x80053330: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80053334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80053338: jal         0x8004EF90
    // 0x8005333C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_40;
    // 0x8005333C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_40:
    // 0x80053340: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80053344: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80053348: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8005334C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80053350: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x80053354: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80053358: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005335C: bne         $t8, $zero, L_800533A4
    if (ctx->r24 != 0) {
        // 0x80053360: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_800533A4;
    }
    // 0x80053360: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80053364: bne         $t9, $zero, L_800533A4
    if (ctx->r25 != 0) {
        // 0x80053368: nop

            goto L_800533A4;
    }
    // 0x80053368: nop

L_8005336C:
    // 0x8005336C: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80053370: jal         0x800499B0
    // 0x80053374: nop

    func_800499B0(rdram, ctx);
        goto after_41;
    // 0x80053374: nop

    after_41:
    // 0x80053378: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005337C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80053380: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80053384: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80053388: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x8005338C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80053390: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80053394: bne         $t2, $zero, L_800533A4
    if (ctx->r10 != 0) {
        // 0x80053398: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_800533A4;
    }
    // 0x80053398: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8005339C: beq         $t3, $zero, L_8005336C
    if (ctx->r11 == 0) {
        // 0x800533A0: nop

            goto L_8005336C;
    }
    // 0x800533A0: nop

L_800533A4:
    // 0x800533A4: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x800533A8: jal         0x800543B0
    // 0x800533AC: nop

    func_800543B0(rdram, ctx);
        goto after_42;
    // 0x800533AC: nop

    after_42:
    // 0x800533B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800533B4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800533B8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800533BC: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x800533C0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800533C4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800533C8: bne         $t8, $zero, L_800533D8
    if (ctx->r24 != 0) {
        // 0x800533CC: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_800533D8;
    }
    // 0x800533CC: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x800533D0: beq         $t9, $zero, L_800533E4
    if (ctx->r25 == 0) {
        // 0x800533D4: nop

            goto L_800533E4;
    }
    // 0x800533D4: nop

L_800533D8:
    // 0x800533D8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x800533DC: jal         0x80054618
    // 0x800533E0: nop

    func_80054618(rdram, ctx);
        goto after_43;
    // 0x800533E0: nop

    after_43:
L_800533E4:
    // 0x800533E4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800533E8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x800533EC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800533F0: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x800533F4: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800533F8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800533FC: bne         $t2, $zero, L_8005340C
    if (ctx->r10 != 0) {
        // 0x80053400: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_8005340C;
    }
    // 0x80053400: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x80053404: beq         $t3, $zero, L_8005348C
    if (ctx->r11 == 0) {
        // 0x80053408: nop

            goto L_8005348C;
    }
    // 0x80053408: nop

L_8005340C:
    // 0x8005340C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80053410: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80053414: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80053418: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005341C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80053420: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80053424: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x80053428: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005342C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80053430: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80053434: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80053438: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005343C: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80053440: nop

    // 0x80053444: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80053448: nop

    // 0x8005344C: slti        $at, $t6, 0x3D
    ctx->r1 = SIGNED(ctx->r14) < 0X3D ? 1 : 0;
    // 0x80053450: bne         $at, $zero, L_80053478
    if (ctx->r1 != 0) {
        // 0x80053454: nop

            goto L_80053478;
    }
    // 0x80053454: nop

    // 0x80053458: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x8005345C: nop

    // 0x80053460: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x80053464: bne         $at, $zero, L_80053478
    if (ctx->r1 != 0) {
        // 0x80053468: nop

            goto L_80053478;
    }
    // 0x80053468: nop

    // 0x8005346C: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80053470: jal         0x80054198
    // 0x80053474: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80054198(rdram, ctx);
        goto after_44;
    // 0x80053474: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_44:
L_80053478:
    // 0x80053478: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8005347C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80053480: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x80053484: b           L_80053554
    // 0x80053488: nop

        goto L_80053554;
    // 0x80053488: nop

L_8005348C:
    // 0x8005348C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80053490: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80053494: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053498: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x8005349C: nop

            goto L_80053500;
    }
    // 0x8005349C: nop

    // 0x800534A0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800534A4: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534A8: nop

            goto L_80053500;
    }
    // 0x800534A8: nop

    // 0x800534AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800534B0: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534B4: nop

            goto L_80053500;
    }
    // 0x800534B4: nop

    // 0x800534B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800534BC: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534C0: nop

            goto L_80053500;
    }
    // 0x800534C0: nop

    // 0x800534C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800534C8: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534CC: nop

            goto L_80053500;
    }
    // 0x800534CC: nop

    // 0x800534D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800534D4: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534D8: nop

            goto L_80053500;
    }
    // 0x800534D8: nop

    // 0x800534DC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800534E0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800534E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800534E8: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x800534EC: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800534F0: bne         $t0, $zero, L_80053500
    if (ctx->r8 != 0) {
        // 0x800534F4: andi        $t1, $t9, 0x1000
        ctx->r9 = ctx->r25 & 0X1000;
            goto L_80053500;
    }
    // 0x800534F4: andi        $t1, $t9, 0x1000
    ctx->r9 = ctx->r25 & 0X1000;
    // 0x800534F8: beq         $t1, $zero, L_80053540
    if (ctx->r9 == 0) {
        // 0x800534FC: nop

            goto L_80053540;
    }
    // 0x800534FC: nop

L_80053500:
    // 0x80053500: jal         0x80061F08
    // 0x80053504: nop

    func_80061F08(rdram, ctx);
        goto after_45;
    // 0x80053504: nop

    after_45:
    // 0x80053508: bne         $v0, $zero, L_80053540
    if (ctx->r2 != 0) {
        // 0x8005350C: nop

            goto L_80053540;
    }
    // 0x8005350C: nop

    // 0x80053510: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80053514: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x80053518: nop

    // 0x8005351C: slti        $at, $t5, 0x6
    ctx->r1 = SIGNED(ctx->r13) < 0X6 ? 1 : 0;
    // 0x80053520: beq         $at, $zero, L_80053538
    if (ctx->r1 == 0) {
        // 0x80053524: nop

            goto L_80053538;
    }
    // 0x80053524: nop

    // 0x80053528: jal         0x8005A578
    // 0x8005352C: nop

    func_8005A578(rdram, ctx);
        goto after_46;
    // 0x8005352C: nop

    after_46:
    // 0x80053530: beq         $v0, $zero, L_80053540
    if (ctx->r2 == 0) {
        // 0x80053534: nop

            goto L_80053540;
    }
    // 0x80053534: nop

L_80053538:
    // 0x80053538: b           L_80053554
    // 0x8005353C: nop

        goto L_80053554;
    // 0x8005353C: nop

L_80053540:
    // 0x80053540: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80053544: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x80053548: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005354C: bne         $t6, $at, L_80052A20
    if (ctx->r14 != ctx->r1) {
        // 0x80053550: nop

            goto L_80052A20;
    }
    // 0x80053550: nop

L_80053554:
    // 0x80053554: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80053558: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
    // 0x8005355C: b           L_80053564
    // 0x80053560: nop

        goto L_80053564;
    // 0x80053560: nop

L_80053564:
    // 0x80053564: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80053568: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8005356C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80053570: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80053574: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80053578: jr          $ra
    // 0x8005357C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8005357C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
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
RECOMP_FUNC void func_80054198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054198: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005419C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800541A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800541A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800541A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800541AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800541B0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800541B4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800541B8: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800541BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800541C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800541C4: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x800541C8: nop

    // 0x800541CC: bc1f        L_800541DC
    if (!c1cs) {
        // 0x800541D0: nop

            goto L_800541DC;
    }
    // 0x800541D0: nop

    // 0x800541D4: b           L_800541E4
    // 0x800541D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
        goto L_800541E4;
    // 0x800541D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800541DC:
    // 0x800541DC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800541E0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_800541E4:
    // 0x800541E4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800541E8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800541EC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800541F0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800541F4: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800541F8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800541FC: xor         $t5, $t1, $t3
    ctx->r13 = ctx->r9 ^ ctx->r11;
    // 0x80054200: andi        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 & 0X8;
    // 0x80054204: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x80054208: sra         $t2, $t9, 31
    ctx->r10 = S32(SIGNED(ctx->r25) >> 31);
    // 0x8005420C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80054210: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80054214: beq         $t8, $zero, L_80054240
    if (ctx->r24 == 0) {
        // 0x80054218: xor         $t4, $t0, $t2
        ctx->r12 = ctx->r8 ^ ctx->r10;
            goto L_80054240;
    }
    // 0x80054218: xor         $t4, $t0, $t2
    ctx->r12 = ctx->r8 ^ ctx->r10;
    // 0x8005421C: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x80054220: jal         0x80056E88
    // 0x80054224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_0;
    // 0x80054224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80054228: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8005422C: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80054230: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80054234: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80054238: jal         0x800507AC
    // 0x8005423C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_1;
    // 0x8005423C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
L_80054240:
    // 0x80054240: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80054244: b           L_80054254
    // 0x80054248: nop

        goto L_80054254;
    // 0x80054248: nop

    // 0x8005424C: b           L_80054254
    // 0x80054250: nop

        goto L_80054254;
    // 0x80054250: nop

L_80054254:
    // 0x80054254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80054258: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005425C: jr          $ra
    // 0x80054260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80054260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80054264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054264: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80054268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005426C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80054270: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054274: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80054278: nop

    // 0x8005427C: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80054280: nop

    // 0x80054284: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80054288: jal         0x80059E28
    // 0x8005428C: nop

    func_80059E28(rdram, ctx);
        goto after_0;
    // 0x8005428C: nop

    after_0:
    // 0x80054290: beq         $v0, $zero, L_800542A0
    if (ctx->r2 == 0) {
        // 0x80054294: nop

            goto L_800542A0;
    }
    // 0x80054294: nop

    // 0x80054298: b           L_800543A0
    // 0x8005429C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800543A0;
    // 0x8005429C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800542A0:
    // 0x800542A0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800542A4: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x800542A8: nop

    // 0x800542AC: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x800542B0: nop

    // 0x800542B4: slti        $at, $t9, 0xFB
    ctx->r1 = SIGNED(ctx->r25) < 0XFB ? 1 : 0;
    // 0x800542B8: bne         $at, $zero, L_800542CC
    if (ctx->r1 != 0) {
        // 0x800542BC: nop

            goto L_800542CC;
    }
    // 0x800542BC: nop

    // 0x800542C0: addiu       $t0, $zero, 0xFA
    ctx->r8 = ADD32(0, 0XFA);
    // 0x800542C4: b           L_800542CC
    // 0x800542C8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
        goto L_800542CC;
    // 0x800542C8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_800542CC:
    // 0x800542CC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800542D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800542D4: lw          $t1, 0x670($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X670);
    // 0x800542D8: addiu       $t3, $t2, 0x2EE
    ctx->r11 = ADD32(ctx->r10, 0X2EE);
    // 0x800542DC: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800542E0: beq         $at, $zero, L_80054390
    if (ctx->r1 == 0) {
        // 0x800542E4: nop

            goto L_80054390;
    }
    // 0x800542E4: nop

    // 0x800542E8: jal         0x800B9000
    // 0x800542EC: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x800542EC: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_1:
    // 0x800542F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800542F4: jal         0x800507AC
    // 0x800542F8: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    func_800507AC(rdram, ctx);
        goto after_2;
    // 0x800542F8: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    after_2:
    // 0x800542FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80054300: jal         0x800507AC
    // 0x80054304: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    func_800507AC(rdram, ctx);
        goto after_3;
    // 0x80054304: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    after_3:
    // 0x80054308: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005430C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054314: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80054318: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8005431C: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80054320: lui         $at, 0xFBFB
    ctx->r1 = S32(0XFBFB << 16);
    // 0x80054324: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80054328: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8005432C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80054330: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80054334: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054338: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8005433C: nop

    // 0x80054340: lh          $t0, 0xE($t5)
    ctx->r8 = MEM_H(ctx->r13, 0XE);
    // 0x80054344: nop

    // 0x80054348: addiu       $t2, $t0, 0xA
    ctx->r10 = ADD32(ctx->r8, 0XA);
    // 0x8005434C: sh          $t2, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r10;
    // 0x80054350: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054354: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80054358: nop

    // 0x8005435C: lh          $t3, 0xE($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XE);
    // 0x80054360: nop

    // 0x80054364: slti        $at, $t3, 0x3E8
    ctx->r1 = SIGNED(ctx->r11) < 0X3E8 ? 1 : 0;
    // 0x80054368: bne         $at, $zero, L_80054380
    if (ctx->r1 != 0) {
        // 0x8005436C: nop

            goto L_80054380;
    }
    // 0x8005436C: nop

    // 0x80054370: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054374: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80054378: addiu       $t6, $zero, 0x3E7
    ctx->r14 = ADD32(0, 0X3E7);
    // 0x8005437C: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
L_80054380:
    // 0x80054380: b           L_800543A0
    // 0x80054384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800543A0;
    // 0x80054384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80054388: b           L_80054398
    // 0x8005438C: nop

        goto L_80054398;
    // 0x8005438C: nop

L_80054390:
    // 0x80054390: b           L_800543A0
    // 0x80054394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800543A0;
    // 0x80054394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054398:
    // 0x80054398: b           L_800543A0
    // 0x8005439C: nop

        goto L_800543A0;
    // 0x8005439C: nop

L_800543A0:
    // 0x800543A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800543A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800543A8: jr          $ra
    // 0x800543AC: nop

    return;
    // 0x800543AC: nop

;}
RECOMP_FUNC void func_800543B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800543B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800543B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800543B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800543BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800543C0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800543C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800543C8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800543CC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800543D0: bne         $t0, $zero, L_800543E0
    if (ctx->r8 != 0) {
        // 0x800543D4: andi        $t1, $t9, 0x80
        ctx->r9 = ctx->r25 & 0X80;
            goto L_800543E0;
    }
    // 0x800543D4: andi        $t1, $t9, 0x80
    ctx->r9 = ctx->r25 & 0X80;
    // 0x800543D8: beq         $t1, $zero, L_80054600
    if (ctx->r9 == 0) {
        // 0x800543DC: nop

            goto L_80054600;
    }
    // 0x800543DC: nop

L_800543E0:
    // 0x800543E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800543E4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800543E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800543EC: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x800543F0: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x800543F4: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x800543F8: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800543FC: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80054400: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80054404: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80054408: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005440C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80054410: nop

    // 0x80054414: lw          $t8, 0x94($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X94);
    // 0x80054418: lw          $t9, 0x90($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X90);
    // 0x8005441C: nop

    // 0x80054420: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80054424: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80054428: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005442C: nop

    // 0x80054430: sltiu       $at, $t1, 0x65
    ctx->r1 = ctx->r9 < 0X65 ? 1 : 0;
    // 0x80054434: bne         $at, $zero, L_80054444
    if (ctx->r1 != 0) {
        // 0x80054438: nop

            goto L_80054444;
    }
    // 0x80054438: nop

    // 0x8005443C: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80054440: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_80054444:
    // 0x80054444: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80054448: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005444C: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80054450: mflo        $t4
    ctx->r12 = lo;
    // 0x80054454: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80054458: nop

    // 0x8005445C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054460: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80054464: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80054468: lh          $t7, 0xC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XC);
    // 0x8005446C: nop

    // 0x80054470: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80054474: sh          $t8, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r24;
    // 0x80054478: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005447C: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80054480: nop

    // 0x80054484: lh          $t0, 0xC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XC);
    // 0x80054488: nop

    // 0x8005448C: slti        $at, $t0, 0x3E8
    ctx->r1 = SIGNED(ctx->r8) < 0X3E8 ? 1 : 0;
    // 0x80054490: bne         $at, $zero, L_800544A8
    if (ctx->r1 != 0) {
        // 0x80054494: nop

            goto L_800544A8;
    }
    // 0x80054494: nop

    // 0x80054498: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005449C: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x800544A0: addiu       $t1, $zero, 0x3E7
    ctx->r9 = ADD32(0, 0X3E7);
    // 0x800544A4: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
L_800544A8:
    // 0x800544A8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800544AC: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x800544B0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800544B4: lh          $t4, 0xE($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XE);
    // 0x800544B8: nop

    // 0x800544BC: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800544C0: sh          $t6, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r14;
    // 0x800544C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800544C8: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x800544CC: nop

    // 0x800544D0: lh          $t5, 0xE($t8)
    ctx->r13 = MEM_H(ctx->r24, 0XE);
    // 0x800544D4: nop

    // 0x800544D8: slti        $at, $t5, 0x3E8
    ctx->r1 = SIGNED(ctx->r13) < 0X3E8 ? 1 : 0;
    // 0x800544DC: bne         $at, $zero, L_800544F4
    if (ctx->r1 != 0) {
        // 0x800544E0: nop

            goto L_800544F4;
    }
    // 0x800544E0: nop

    // 0x800544E4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800544E8: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x800544EC: addiu       $t9, $zero, 0x3E7
    ctx->r25 = ADD32(0, 0X3E7);
    // 0x800544F0: sh          $t9, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r25;
L_800544F4:
    // 0x800544F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800544F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800544FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80054500: jal         0x80052508
    // 0x80054504: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    func_80052508(rdram, ctx);
        goto after_0;
    // 0x80054504: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_0:
    // 0x80054508: jal         0x8005A578
    // 0x8005450C: nop

    func_8005A578(rdram, ctx);
        goto after_1;
    // 0x8005450C: nop

    after_1:
    // 0x80054510: beq         $v0, $zero, L_80054584
    if (ctx->r2 == 0) {
        // 0x80054514: nop

            goto L_80054584;
    }
    // 0x80054514: nop

    // 0x80054518: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005451C: lw          $t1, 0x480($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X480);
    // 0x80054520: nop

    // 0x80054524: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80054528: nop

    // 0x8005452C: bne         $t2, $zero, L_80054584
    if (ctx->r10 != 0) {
        // 0x80054530: nop

            goto L_80054584;
    }
    // 0x80054530: nop

    // 0x80054534: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054538: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8005453C: nop

    // 0x80054540: lh          $t7, 0xC($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XC);
    // 0x80054544: lh          $t6, 0x50($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X50);
    // 0x80054548: nop

    // 0x8005454C: subu        $t3, $t7, $t6
    ctx->r11 = SUB32(ctx->r15, ctx->r14);
    // 0x80054550: slti        $at, $t3, 0xFA
    ctx->r1 = SIGNED(ctx->r11) < 0XFA ? 1 : 0;
    // 0x80054554: bne         $at, $zero, L_80054584
    if (ctx->r1 != 0) {
        // 0x80054558: nop

            goto L_80054584;
    }
    // 0x80054558: nop

    // 0x8005455C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054560: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80054564: nop

    // 0x80054568: lh          $t5, 0xC($t8)
    ctx->r13 = MEM_H(ctx->r24, 0XC);
    // 0x8005456C: nop

    // 0x80054570: sh          $t5, 0x50($t8)
    MEM_H(0X50, ctx->r24) = ctx->r13;
    // 0x80054574: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80054578: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x8005457C: addiu       $t9, $zero, 0x75A
    ctx->r25 = ADD32(0, 0X75A);
    // 0x80054580: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_80054584:
    // 0x80054584: jal         0x8005A578
    // 0x80054588: nop

    func_8005A578(rdram, ctx);
        goto after_2;
    // 0x80054588: nop

    after_2:
    // 0x8005458C: beq         $v0, $zero, L_80054600
    if (ctx->r2 == 0) {
        // 0x80054590: nop

            goto L_80054600;
    }
    // 0x80054590: nop

    // 0x80054594: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80054598: lw          $t1, 0x480($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X480);
    // 0x8005459C: nop

    // 0x800545A0: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x800545A4: nop

    // 0x800545A8: bne         $t2, $zero, L_80054600
    if (ctx->r10 != 0) {
        // 0x800545AC: nop

            goto L_80054600;
    }
    // 0x800545AC: nop

    // 0x800545B0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800545B4: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x800545B8: nop

    // 0x800545BC: lh          $t7, 0xE($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XE);
    // 0x800545C0: lh          $t6, 0x52($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X52);
    // 0x800545C4: nop

    // 0x800545C8: subu        $t3, $t7, $t6
    ctx->r11 = SUB32(ctx->r15, ctx->r14);
    // 0x800545CC: slti        $at, $t3, 0xFA
    ctx->r1 = SIGNED(ctx->r11) < 0XFA ? 1 : 0;
    // 0x800545D0: bne         $at, $zero, L_80054600
    if (ctx->r1 != 0) {
        // 0x800545D4: nop

            goto L_80054600;
    }
    // 0x800545D4: nop

    // 0x800545D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800545DC: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800545E0: nop

    // 0x800545E4: lh          $t8, 0xE($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XE);
    // 0x800545E8: nop

    // 0x800545EC: sh          $t8, 0x52($t5)
    MEM_H(0X52, ctx->r13) = ctx->r24;
    // 0x800545F0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800545F4: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x800545F8: addiu       $t9, $zero, 0x75B
    ctx->r25 = ADD32(0, 0X75B);
    // 0x800545FC: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_80054600:
    // 0x80054600: b           L_80054608
    // 0x80054604: nop

        goto L_80054608;
    // 0x80054604: nop

L_80054608:
    // 0x80054608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005460C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80054610: jr          $ra
    // 0x80054614: nop

    return;
    // 0x80054614: nop

;}
RECOMP_FUNC void func_80054618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005461C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80054624: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054628: jal         0x800507AC
    // 0x8005462C: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    func_800507AC(rdram, ctx);
        goto after_0;
    // 0x8005462C: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    after_0:
    // 0x80054630: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054634: jal         0x800507AC
    // 0x80054638: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    func_800507AC(rdram, ctx);
        goto after_1;
    // 0x80054638: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    after_1:
    // 0x8005463C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80054644: jal         0x80052508
    // 0x80054648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_2;
    // 0x80054648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8005464C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054650: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80054654: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054658: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8005465C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80054660: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80054664: lui         $at, 0xFBFF
    ctx->r1 = S32(0XFBFF << 16);
    // 0x80054668: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005466C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80054670: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80054674: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80054678: b           L_80054680
    // 0x8005467C: nop

        goto L_80054680;
    // 0x8005467C: nop

L_80054680:
    // 0x80054680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80054688: jr          $ra
    // 0x8005468C: nop

    return;
    // 0x8005468C: nop

;}
RECOMP_FUNC void func_80054690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054690: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80054694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80054698: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8005469C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x800546A0: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800546A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800546A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800546AC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800546B0: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x800546B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800546B8: bne         $t6, $at, L_80054700
    if (ctx->r14 != ctx->r1) {
        // 0x800546BC: nop

            goto L_80054700;
    }
    // 0x800546BC: nop

    // 0x800546C0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800546C4: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x800546C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800546CC: bne         $t7, $at, L_80054700
    if (ctx->r15 != ctx->r1) {
        // 0x800546D0: nop

            goto L_80054700;
    }
    // 0x800546D0: nop

    // 0x800546D4: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800546D8: nop

    // 0x800546DC: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800546E0: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800546E4: nop

    // 0x800546E8: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800546EC: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800546F0: nop

    // 0x800546F4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800546F8: b           L_80055134
    // 0x800546FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055134;
    // 0x800546FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054700:
    // 0x80054700: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054704: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80054708: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005470C: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80054710: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80054714: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80054718: bne         $t4, $zero, L_80054728
    if (ctx->r12 != 0) {
        // 0x8005471C: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_80054728;
    }
    // 0x8005471C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80054720: beq         $t5, $zero, L_8005475C
    if (ctx->r13 == 0) {
        // 0x80054724: nop

            goto L_8005475C;
    }
    // 0x80054724: nop

L_80054728:
    // 0x80054728: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005472C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80054730: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054734: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80054738: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005473C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80054740: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80054744: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80054748: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005474C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80054750: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80054754: b           L_80054EE4
    // 0x80054758: nop

        goto L_80054EE4;
    // 0x80054758: nop

L_8005475C:
    // 0x8005475C: jal         0x80057960
    // 0x80054760: nop

    func_80057960(rdram, ctx);
        goto after_0;
    // 0x80054760: nop

    after_0:
    // 0x80054764: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80054768: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8005476C: nop

    // 0x80054770: beq         $t7, $zero, L_800547D8
    if (ctx->r15 == 0) {
        // 0x80054774: nop

            goto L_800547D8;
    }
    // 0x80054774: nop

    // 0x80054778: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8005477C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054780: nop

    // 0x80054784: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054788: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005478C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054790: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054794: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80054798: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8005479C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800547A0: addiu       $at, $zero, -0x6001
    ctx->r1 = ADD32(0, -0X6001);
    // 0x800547A4: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800547A8: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800547AC: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800547B0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800547B4: lw          $t5, 0x480($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X480);
    // 0x800547B8: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800547BC: nop

    // 0x800547C0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800547C4: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800547C8: nop

    // 0x800547CC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800547D0: b           L_80055134
    // 0x800547D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055134;
    // 0x800547D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800547D8:
    // 0x800547D8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800547DC: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800547E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800547E4: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x800547E8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800547EC: bne         $t0, $zero, L_800547FC
    if (ctx->r8 != 0) {
        // 0x800547F0: andi        $t1, $t9, 0x1000
        ctx->r9 = ctx->r25 & 0X1000;
            goto L_800547FC;
    }
    // 0x800547F0: andi        $t1, $t9, 0x1000
    ctx->r9 = ctx->r25 & 0X1000;
    // 0x800547F4: beq         $t1, $zero, L_80054860
    if (ctx->r9 == 0) {
        // 0x800547F8: nop

            goto L_80054860;
    }
    // 0x800547F8: nop

L_800547FC:
    // 0x800547FC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80054800: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80054804: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054808: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8005480C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80054810: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80054814: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80054818: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005481C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80054820: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80054824: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80054828: lw          $t2, 0x488($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X488);
    // 0x8005482C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80054830: nop

    // 0x80054834: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80054838: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005483C: lw          $t9, 0x488($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X488);
    // 0x80054840: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80054844: nop

    // 0x80054848: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8005484C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80054850: nop

    // 0x80054854: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80054858: b           L_80055134
    // 0x8005485C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x8005485C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054860:
    // 0x80054860: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054864: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054868: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005486C: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80054870: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80054874: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80054878: bne         $t2, $zero, L_80054888
    if (ctx->r10 != 0) {
        // 0x8005487C: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_80054888;
    }
    // 0x8005487C: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x80054880: beq         $t3, $zero, L_80054914
    if (ctx->r11 == 0) {
        // 0x80054884: nop

            goto L_80054914;
    }
    // 0x80054884: nop

L_80054888:
    // 0x80054888: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005488C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80054890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054894: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80054898: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8005489C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800548A0: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x800548A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800548A8: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800548AC: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x800548B0: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x800548B4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800548B8: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x800548BC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800548C0: lh          $t6, 0x3C($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X3C);
    // 0x800548C4: lw          $t2, 0x5A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5A8);
    // 0x800548C8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800548CC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800548D0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800548D4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800548D8: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x800548DC: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800548E0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800548E4: lw          $t9, 0x5A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5A8);
    // 0x800548E8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800548EC: nop

    // 0x800548F0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800548F4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800548F8: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x800548FC: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x80054900: lh          $t5, 0x3C($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X3C);
    // 0x80054904: nop

    // 0x80054908: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x8005490C: b           L_80055134
    // 0x80054910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054914:
    // 0x80054914: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054918: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005491C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80054920: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80054924: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80054928: bne         $t8, $zero, L_80054938
    if (ctx->r24 != 0) {
        // 0x8005492C: andi        $t9, $t3, 0x2000
        ctx->r25 = ctx->r11 & 0X2000;
            goto L_80054938;
    }
    // 0x8005492C: andi        $t9, $t3, 0x2000
    ctx->r25 = ctx->r11 & 0X2000;
    // 0x80054930: beq         $t9, $zero, L_8005499C
    if (ctx->r25 == 0) {
        // 0x80054934: nop

            goto L_8005499C;
    }
    // 0x80054934: nop

L_80054938:
    // 0x80054938: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005493C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80054940: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054944: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80054948: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8005494C: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x80054950: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x80054954: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80054958: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8005495C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80054960: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054964: lw          $t6, 0x63C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63C);
    // 0x80054968: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8005496C: addiu       $t2, $t6, 0x24
    ctx->r10 = ADD32(ctx->r14, 0X24);
    // 0x80054970: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054974: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054978: lw          $t8, 0x63C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63C);
    // 0x8005497C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80054980: nop

    // 0x80054984: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054988: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8005498C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80054990: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80054994: b           L_80055134
    // 0x80054998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005499C:
    // 0x8005499C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800549A0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800549A4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800549A8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800549AC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800549B0: bne         $t2, $zero, L_800549C0
    if (ctx->r10 != 0) {
        // 0x800549B4: andi        $t3, $t7, 0x4000
        ctx->r11 = ctx->r15 & 0X4000;
            goto L_800549C0;
    }
    // 0x800549B4: andi        $t3, $t7, 0x4000
    ctx->r11 = ctx->r15 & 0X4000;
    // 0x800549B8: beq         $t3, $zero, L_80054A60
    if (ctx->r11 == 0) {
        // 0x800549BC: nop

            goto L_80054A60;
    }
    // 0x800549BC: nop

L_800549C0:
    // 0x800549C0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800549C4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800549C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800549CC: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x800549D0: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x800549D4: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800549D8: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x800549DC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800549E0: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x800549E4: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x800549E8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800549EC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800549F0: nop

    // 0x800549F4: lbu         $a0, 0x8($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X8);
    // 0x800549F8: jal         0x80060E24
    // 0x800549FC: nop

    func_80060E24(rdram, ctx);
        goto after_1;
    // 0x800549FC: nop

    after_1:
    // 0x80054A00: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80054A04: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054A08: lw          $t7, 0x63C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63C);
    // 0x80054A0C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80054A10: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054A14: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80054A18: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80054A1C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054A20: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054A24: lw          $t8, 0x63C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63C);
    // 0x80054A28: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80054A2C: nop

    // 0x80054A30: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054A34: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80054A38: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80054A3C: nop

    // 0x80054A40: lbu         $a0, 0x8($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X8);
    // 0x80054A44: jal         0x80060E24
    // 0x80054A48: nop

    func_80060E24(rdram, ctx);
        goto after_2;
    // 0x80054A48: nop

    after_2:
    // 0x80054A4C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80054A50: nop

    // 0x80054A54: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80054A58: b           L_80055134
    // 0x80054A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054A60:
    // 0x80054A60: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054A64: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80054A68: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80054A6C: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80054A70: lw          $t5, 0x4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4);
    // 0x80054A74: bne         $t6, $zero, L_80054A84
    if (ctx->r14 != 0) {
        // 0x80054A78: andi        $t7, $t5, 0x8000
        ctx->r15 = ctx->r13 & 0X8000;
            goto L_80054A84;
    }
    // 0x80054A78: andi        $t7, $t5, 0x8000
    ctx->r15 = ctx->r13 & 0X8000;
    // 0x80054A7C: beq         $t7, $zero, L_80054C88
    if (ctx->r15 == 0) {
        // 0x80054A80: nop

            goto L_80054C88;
    }
    // 0x80054A80: nop

L_80054A84:
    // 0x80054A84: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80054A88: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80054A8C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80054A90: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x80054A94: nop

    // 0x80054A98: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x80054A9C: nop

    // 0x80054AA0: beq         $t8, $at, L_80054B34
    if (ctx->r24 == ctx->r1) {
        // 0x80054AA4: nop

            goto L_80054B34;
    }
    // 0x80054AA4: nop

    // 0x80054AA8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80054AAC: beq         $t8, $at, L_80054B34
    if (ctx->r24 == ctx->r1) {
        // 0x80054AB0: nop

            goto L_80054B34;
    }
    // 0x80054AB0: nop

    // 0x80054AB4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80054AB8: beq         $t8, $at, L_80054B34
    if (ctx->r24 == ctx->r1) {
        // 0x80054ABC: nop

            goto L_80054B34;
    }
    // 0x80054ABC: nop

    // 0x80054AC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80054AC4: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80054AC8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80054ACC: lw          $t0, 0x5C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X5C);
    // 0x80054AD0: lw          $t5, 0x478($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X478);
    // 0x80054AD4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80054AD8: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80054ADC: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x80054AE0: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x80054AE4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80054AE8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80054AEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80054AF0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80054AF4: lw          $t2, 0x478($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X478);
    // 0x80054AF8: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80054AFC: nop

    // 0x80054B00: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054B04: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054B08: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80054B0C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80054B10: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x80054B14: nop

    // 0x80054B18: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80054B1C: nop

    // 0x80054B20: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80054B24: b           L_80055134
    // 0x80054B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80054B2C: b           L_80054C88
    // 0x80054B30: nop

        goto L_80054C88;
    // 0x80054B30: nop

L_80054B34:
    // 0x80054B34: jal         0x8005A578
    // 0x80054B38: nop

    func_8005A578(rdram, ctx);
        goto after_3;
    // 0x80054B38: nop

    after_3:
    // 0x80054B3C: bne         $v0, $zero, L_80054C1C
    if (ctx->r2 != 0) {
        // 0x80054B40: nop

            goto L_80054C1C;
    }
    // 0x80054B40: nop

    // 0x80054B44: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054B48: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054B4C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80054B50: lw          $t5, 0x5C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X5C);
    // 0x80054B54: nop

    // 0x80054B58: lh          $s0, 0x0($t5)
    ctx->r16 = MEM_H(ctx->r13, 0X0);
    // 0x80054B5C: nop

    // 0x80054B60: beq         $s0, $at, L_80054B88
    if (ctx->r16 == ctx->r1) {
        // 0x80054B64: nop

            goto L_80054B88;
    }
    // 0x80054B64: nop

    // 0x80054B68: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80054B6C: beq         $s0, $at, L_80054BD8
    if (ctx->r16 == ctx->r1) {
        // 0x80054B70: nop

            goto L_80054BD8;
    }
    // 0x80054B70: nop

    // 0x80054B74: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80054B78: beq         $s0, $at, L_80054BB0
    if (ctx->r16 == ctx->r1) {
        // 0x80054B7C: nop

            goto L_80054BB0;
    }
    // 0x80054B7C: nop

    // 0x80054B80: b           L_80054C00
    // 0x80054B84: nop

        goto L_80054C00;
    // 0x80054B84: nop

L_80054B88:
    // 0x80054B88: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80054B8C: lw          $t6, 0x478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X478);
    // 0x80054B90: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80054B94: addiu       $t7, $t6, 0x306
    ctx->r15 = ADD32(ctx->r14, 0X306);
    // 0x80054B98: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80054B9C: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80054BA0: addiu       $t3, $zero, 0x2B
    ctx->r11 = ADD32(0, 0X2B);
    // 0x80054BA4: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054BA8: b           L_80054C00
    // 0x80054BAC: nop

        goto L_80054C00;
    // 0x80054BAC: nop

L_80054BB0:
    // 0x80054BB0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80054BB4: lw          $t9, 0x478($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X478);
    // 0x80054BB8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80054BBC: addiu       $t0, $t9, 0x318
    ctx->r8 = ADD32(ctx->r25, 0X318);
    // 0x80054BC0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80054BC4: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80054BC8: addiu       $t4, $zero, 0x2C
    ctx->r12 = ADD32(0, 0X2C);
    // 0x80054BCC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80054BD0: b           L_80054C00
    // 0x80054BD4: nop

        goto L_80054C00;
    // 0x80054BD4: nop

L_80054BD8:
    // 0x80054BD8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80054BDC: lw          $t6, 0x478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X478);
    // 0x80054BE0: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80054BE4: addiu       $t7, $t6, 0x32A
    ctx->r15 = ADD32(ctx->r14, 0X32A);
    // 0x80054BE8: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80054BEC: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80054BF0: addiu       $t3, $zero, 0x2D
    ctx->r11 = ADD32(0, 0X2D);
    // 0x80054BF4: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054BF8: b           L_80054C00
    // 0x80054BFC: nop

        goto L_80054C00;
    // 0x80054BFC: nop

L_80054C00:
    // 0x80054C00: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80054C04: lw          $t9, 0x478($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X478);
    // 0x80054C08: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80054C0C: nop

    // 0x80054C10: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80054C14: b           L_80055134
    // 0x80054C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054C1C:
    // 0x80054C1C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054C20: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80054C24: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80054C28: lw          $t4, 0x5C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X5C);
    // 0x80054C2C: lw          $t7, 0x478($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X478);
    // 0x80054C30: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80054C34: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054C38: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80054C3C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80054C40: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80054C44: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80054C48: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054C4C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80054C50: lw          $t8, 0x478($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X478);
    // 0x80054C54: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80054C58: nop

    // 0x80054C5C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054C60: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80054C64: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80054C68: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80054C6C: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x80054C70: nop

    // 0x80054C74: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x80054C78: nop

    // 0x80054C7C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80054C80: b           L_80055134
    // 0x80054C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054C88:
    // 0x80054C88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054C8C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80054C90: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80054C94: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80054C98: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80054C9C: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80054CA0: bne         $t8, $zero, L_80054CB0
    if (ctx->r24 != 0) {
        // 0x80054CA4: and         $t9, $t3, $at
        ctx->r25 = ctx->r11 & ctx->r1;
            goto L_80054CB0;
    }
    // 0x80054CA4: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80054CA8: beq         $t9, $zero, L_80054D60
    if (ctx->r25 == 0) {
        // 0x80054CAC: nop

            goto L_80054D60;
    }
    // 0x80054CAC: nop

L_80054CB0:
    // 0x80054CB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054CB4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80054CB8: nop

    // 0x80054CBC: lw          $a0, 0x58($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X58);
    // 0x80054CC0: jal         0x80056C60
    // 0x80054CC4: nop

    func_80056C60(rdram, ctx);
        goto after_4;
    // 0x80054CC4: nop

    after_4:
    // 0x80054CC8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80054CCC: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80054CD0: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80054CD4: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x80054CD8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80054CDC: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x80054CE0: lh          $t4, 0x2C52($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2C52);
    // 0x80054CE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054CE8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80054CEC: lw          $t6, 0x630($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X630);
    // 0x80054CF0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80054CF4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054CF8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80054CFC: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x80054D00: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054D04: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054D08: lw          $t8, 0x630($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X630);
    // 0x80054D0C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80054D10: nop

    // 0x80054D14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054D18: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054D1C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80054D20: nop

    // 0x80054D24: lw          $a0, 0x58($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X58);
    // 0x80054D28: jal         0x80056C60
    // 0x80054D2C: nop

    func_80056C60(rdram, ctx);
        goto after_5;
    // 0x80054D2C: nop

    after_5:
    // 0x80054D30: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80054D34: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80054D38: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80054D3C: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x80054D40: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80054D44: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x80054D48: lh          $t4, 0x2C52($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2C52);
    // 0x80054D4C: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80054D50: nop

    // 0x80054D54: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80054D58: b           L_80055134
    // 0x80054D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054D60:
    // 0x80054D60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054D64: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80054D68: nop

    // 0x80054D6C: lh          $t2, 0x0($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X0);
    // 0x80054D70: nop

    // 0x80054D74: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x80054D78: beq         $at, $zero, L_80054DBC
    if (ctx->r1 == 0) {
        // 0x80054D7C: nop

            goto L_80054DBC;
    }
    // 0x80054D7C: nop

    // 0x80054D80: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80054D84: lw          $t3, 0x638($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X638);
    // 0x80054D88: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80054D8C: nop

    // 0x80054D90: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054D94: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80054D98: lw          $t9, 0x638($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X638);
    // 0x80054D9C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80054DA0: nop

    // 0x80054DA4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80054DA8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80054DAC: nop

    // 0x80054DB0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80054DB4: b           L_80055134
    // 0x80054DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054DBC:
    // 0x80054DBC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054DC0: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80054DC4: nop

    // 0x80054DC8: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80054DCC: nop

    // 0x80054DD0: slti        $at, $t4, 0x3D
    ctx->r1 = SIGNED(ctx->r12) < 0X3D ? 1 : 0;
    // 0x80054DD4: beq         $at, $zero, L_80054E18
    if (ctx->r1 == 0) {
        // 0x80054DD8: nop

            goto L_80054E18;
    }
    // 0x80054DD8: nop

    // 0x80054DDC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054DE0: lw          $t5, 0x638($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X638);
    // 0x80054DE4: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80054DE8: addiu       $t6, $t5, 0x12
    ctx->r14 = ADD32(ctx->r13, 0X12);
    // 0x80054DEC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80054DF0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80054DF4: lw          $t3, 0x638($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X638);
    // 0x80054DF8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80054DFC: nop

    // 0x80054E00: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054E04: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80054E08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80054E0C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80054E10: b           L_80055134
    // 0x80054E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054E18:
    // 0x80054E18: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80054E1C: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80054E20: nop

    // 0x80054E24: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80054E28: nop

    // 0x80054E2C: slti        $at, $t1, 0x384
    ctx->r1 = SIGNED(ctx->r9) < 0X384 ? 1 : 0;
    // 0x80054E30: bne         $at, $zero, L_80054E74
    if (ctx->r1 != 0) {
        // 0x80054E34: nop

            goto L_80054E74;
    }
    // 0x80054E34: nop

    // 0x80054E38: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054E3C: lw          $t4, 0x638($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X638);
    // 0x80054E40: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80054E44: addiu       $t5, $t4, 0x24
    ctx->r13 = ADD32(ctx->r12, 0X24);
    // 0x80054E48: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80054E4C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80054E50: lw          $t2, 0x638($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X638);
    // 0x80054E54: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80054E58: nop

    // 0x80054E5C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054E60: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80054E64: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80054E68: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054E6C: b           L_80055134
    // 0x80054E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054E74:
    // 0x80054E74: jal         0x80061F08
    // 0x80054E78: nop

    func_80061F08(rdram, ctx);
        goto after_6;
    // 0x80054E78: nop

    after_6:
    // 0x80054E7C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80054E80: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80054E84: nop

    // 0x80054E88: beq         $t7, $zero, L_80054EE4
    if (ctx->r15 == 0) {
        // 0x80054E8C: nop

            goto L_80054EE4;
    }
    // 0x80054E8C: nop

    // 0x80054E90: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80054E94: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80054E98: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80054E9C: lw          $t4, 0x470($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X470);
    // 0x80054EA0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80054EA4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80054EA8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80054EAC: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80054EB0: addiu       $t6, $t5, -0x1B0
    ctx->r14 = ADD32(ctx->r13, -0X1B0);
    // 0x80054EB4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80054EB8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80054EBC: lw          $t3, 0x470($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X470);
    // 0x80054EC0: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80054EC4: nop

    // 0x80054EC8: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054ECC: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80054ED0: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80054ED4: addiu       $t7, $t9, -0x18
    ctx->r15 = ADD32(ctx->r25, -0X18);
    // 0x80054ED8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80054EDC: b           L_80055134
    // 0x80054EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055134;
    // 0x80054EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054EE4:
    // 0x80054EE4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054EE8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80054EEC: nop

    // 0x80054EF0: lw          $t4, 0xB8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XB8);
    // 0x80054EF4: nop

    // 0x80054EF8: beq         $t4, $zero, L_80054F78
    if (ctx->r12 == 0) {
        // 0x80054EFC: nop

            goto L_80054F78;
    }
    // 0x80054EFC: nop

    // 0x80054F00: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054F04: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80054F08: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80054F0C: lw          $t6, 0xB8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XB8);
    // 0x80054F10: lw          $t3, 0x468($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X468);
    // 0x80054F14: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x80054F18: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x80054F1C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80054F20: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80054F24: addu        $t8, $t2, $t3
    ctx->r24 = ADD32(ctx->r10, ctx->r11);
    // 0x80054F28: addiu       $t9, $t8, -0x12
    ctx->r25 = ADD32(ctx->r24, -0X12);
    // 0x80054F2C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80054F30: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80054F34: lw          $t0, 0x468($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X468);
    // 0x80054F38: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80054F3C: nop

    // 0x80054F40: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80054F44: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054F48: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054F4C: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80054F50: lw          $t5, 0xB8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XB8);
    // 0x80054F54: nop

    // 0x80054F58: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80054F5C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80054F60: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80054F64: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80054F68: nop

    // 0x80054F6C: sw          $zero, 0xB8($t3)
    MEM_W(0XB8, ctx->r11) = 0;
    // 0x80054F70: b           L_80055134
    // 0x80054F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054F78:
    // 0x80054F78: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80054F7C: jal         0x80055E40
    // 0x80054F80: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_80055E40(rdram, ctx);
        goto after_7;
    // 0x80054F80: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_7:
    // 0x80054F84: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80054F88: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80054F8C: nop

    // 0x80054F90: beq         $t8, $zero, L_80054FA0
    if (ctx->r24 == 0) {
        // 0x80054F94: nop

            goto L_80054FA0;
    }
    // 0x80054F94: nop

    // 0x80054F98: b           L_80055084
    // 0x80054F9C: nop

        goto L_80055084;
    // 0x80054F9C: nop

L_80054FA0:
    // 0x80054FA0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80054FA4: lw          $t9, 0x670($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X670);
    // 0x80054FA8: nop

    // 0x80054FAC: slti        $at, $t9, 0x12C
    ctx->r1 = SIGNED(ctx->r25) < 0X12C ? 1 : 0;
    // 0x80054FB0: beq         $at, $zero, L_80055028
    if (ctx->r1 == 0) {
        // 0x80054FB4: nop

            goto L_80055028;
    }
    // 0x80054FB4: nop

    // 0x80054FB8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054FBC: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x80054FC0: nop

    // 0x80054FC4: andi        $t0, $t7, 0x7
    ctx->r8 = ctx->r15 & 0X7;
    // 0x80054FC8: srl         $t1, $t0, 1
    ctx->r9 = S32(U32(ctx->r8) >> 1);
    // 0x80054FCC: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80054FD0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80054FD4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80054FD8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80054FDC: lw          $t6, 0x468($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X468);
    // 0x80054FE0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80054FE4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054FE8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80054FEC: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x80054FF0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054FF4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80054FF8: lw          $t8, 0x468($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X468);
    // 0x80054FFC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80055000: nop

    // 0x80055004: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80055008: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8005500C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80055010: nop

    // 0x80055014: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80055018: b           L_80055134
    // 0x8005501C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x8005501C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80055020: b           L_8005512C
    // 0x80055024: nop

        goto L_8005512C;
    // 0x80055024: nop

L_80055028:
    // 0x80055028: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005502C: lw          $t1, 0x670($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X670);
    // 0x80055030: nop

    // 0x80055034: slti        $at, $t1, 0x15E
    ctx->r1 = SIGNED(ctx->r9) < 0X15E ? 1 : 0;
    // 0x80055038: beq         $at, $zero, L_80055084
    if (ctx->r1 == 0) {
        // 0x8005503C: nop

            goto L_80055084;
    }
    // 0x8005503C: nop

    // 0x80055040: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80055044: lw          $t4, 0x468($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X468);
    // 0x80055048: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8005504C: addiu       $t5, $t4, 0x120
    ctx->r13 = ADD32(ctx->r12, 0X120);
    // 0x80055050: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80055054: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80055058: lw          $t2, 0x468($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X468);
    // 0x8005505C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80055060: nop

    // 0x80055064: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80055068: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8005506C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80055070: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80055074: b           L_80055134
    // 0x80055078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80055078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005507C: b           L_8005512C
    // 0x80055080: nop

        goto L_8005512C;
    // 0x80055080: nop

L_80055084:
    // 0x80055084: jal         0x80055CC4
    // 0x80055088: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80055CC4(rdram, ctx);
        goto after_8;
    // 0x80055088: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x8005508C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80055090: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80055094: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80055098: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8005509C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800550A0: lw          $t1, -0x2A60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2A60);
    // 0x800550A4: nop

    // 0x800550A8: bne         $t1, $zero, L_800550DC
    if (ctx->r9 != 0) {
        // 0x800550AC: nop

            goto L_800550DC;
    }
    // 0x800550AC: nop

    // 0x800550B0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800550B4: jal         0x80055E40
    // 0x800550B8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80055E40(rdram, ctx);
        goto after_9;
    // 0x800550B8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_9:
    // 0x800550BC: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800550C0: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800550C4: nop

    // 0x800550C8: beq         $t4, $zero, L_800550DC
    if (ctx->r12 == 0) {
        // 0x800550CC: nop

            goto L_800550DC;
    }
    // 0x800550CC: nop

    // 0x800550D0: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800550D4: nop

    // 0x800550D8: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
L_800550DC:
    // 0x800550DC: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800550E0: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800550E4: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x800550E8: lw          $t3, 0x468($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X468);
    // 0x800550EC: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x800550F0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800550F4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800550F8: addu        $t8, $t2, $t3
    ctx->r24 = ADD32(ctx->r10, ctx->r11);
    // 0x800550FC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80055100: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80055104: lw          $t7, 0x468($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X468);
    // 0x80055108: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8005510C: nop

    // 0x80055110: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80055114: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80055118: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x8005511C: nop

    // 0x80055120: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x80055124: b           L_80055134
    // 0x80055128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80055128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005512C:
    // 0x8005512C: b           L_80055134
    // 0x80055130: nop

        goto L_80055134;
    // 0x80055130: nop

L_80055134:
    // 0x80055134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80055138: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005513C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80055140: jr          $ra
    // 0x80055144: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80055144: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80055148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005514C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055150: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80055154: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80055158: nop

    // 0x8005515C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80055160: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80055164: andi        $t0, $t8, 0x8
    ctx->r8 = ctx->r24 & 0X8;
    // 0x80055168: bne         $t0, $zero, L_80055178
    if (ctx->r8 != 0) {
        // 0x8005516C: andi        $t1, $t9, 0x0
        ctx->r9 = ctx->r25 & 0X0;
            goto L_80055178;
    }
    // 0x8005516C: andi        $t1, $t9, 0x0
    ctx->r9 = ctx->r25 & 0X0;
    // 0x80055170: beq         $t1, $zero, L_8005522C
    if (ctx->r9 == 0) {
        // 0x80055174: nop

            goto L_8005522C;
    }
    // 0x80055174: nop

L_80055178:
    // 0x80055178: jal         0x8005A768
    // 0x8005517C: nop

    func_8005A768(rdram, ctx);
        goto after_0;
    // 0x8005517C: nop

    after_0:
    // 0x80055180: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80055184: lw          $t7, 0x6CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6CC);
    // 0x80055188: nop

    // 0x8005518C: subu        $t2, $v0, $t7
    ctx->r10 = SUB32(ctx->r2, ctx->r15);
    // 0x80055190: slti        $at, $t2, 0x79
    ctx->r1 = SIGNED(ctx->r10) < 0X79 ? 1 : 0;
    // 0x80055194: bne         $at, $zero, L_80055224
    if (ctx->r1 != 0) {
        // 0x80055198: nop

            goto L_80055224;
    }
    // 0x80055198: nop

    // 0x8005519C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800551A0: lh          $t3, 0x6C0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X6C0);
    // 0x800551A4: nop

    // 0x800551A8: bne         $t3, $zero, L_80055224
    if (ctx->r11 != 0) {
        // 0x800551AC: nop

            goto L_80055224;
    }
    // 0x800551AC: nop

    // 0x800551B0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800551B4: lbu         $t4, 0x125A($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X125A);
    // 0x800551B8: nop

    // 0x800551BC: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800551C0: bne         $t5, $zero, L_80055224
    if (ctx->r13 != 0) {
        // 0x800551C4: nop

            goto L_80055224;
    }
    // 0x800551C4: nop

    // 0x800551C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800551CC: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x800551D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800551D4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800551D8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800551DC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800551E0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800551E4: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800551E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800551EC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800551F0: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x800551F4: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x800551F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800551FC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80055200: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80055204: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80055208: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8005520C: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x80055210: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x80055214: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80055218: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8005521C: b           L_80055488
    // 0x80055220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055488;
    // 0x80055220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80055224:
    // 0x80055224: b           L_80055488
    // 0x80055228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x80055228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005522C:
    // 0x8005522C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80055230: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80055234: nop

    // 0x80055238: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x8005523C: nop

    // 0x80055240: slti        $at, $t9, 0x384
    ctx->r1 = SIGNED(ctx->r25) < 0X384 ? 1 : 0;
    // 0x80055244: bne         $at, $zero, L_80055254
    if (ctx->r1 != 0) {
        // 0x80055248: nop

            goto L_80055254;
    }
    // 0x80055248: nop

    // 0x8005524C: b           L_80055488
    // 0x80055250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x80055250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80055254:
    // 0x80055254: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80055258: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005525C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80055260: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80055264: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x80055268: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8005526C: bne         $t2, $zero, L_8005527C
    if (ctx->r10 != 0) {
        // 0x80055270: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_8005527C;
    }
    // 0x80055270: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x80055274: beq         $t3, $zero, L_80055338
    if (ctx->r11 == 0) {
        // 0x80055278: nop

            goto L_80055338;
    }
    // 0x80055278: nop

L_8005527C:
    // 0x8005527C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80055280: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80055284: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055288: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8005528C: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x80055290: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80055294: lui         $at, 0xDFFF
    ctx->r1 = S32(0XDFFF << 16);
    // 0x80055298: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005529C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x800552A0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800552A4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800552A8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800552AC: lw          $t0, 0x5A8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5A8);
    // 0x800552B0: nop

    // 0x800552B4: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800552B8: nop

    // 0x800552BC: bne         $t6, $zero, L_800552F4
    if (ctx->r14 != 0) {
        // 0x800552C0: nop

            goto L_800552F4;
    }
    // 0x800552C0: nop

    // 0x800552C4: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x800552C8: nop

    // 0x800552CC: bne         $t7, $zero, L_800552F4
    if (ctx->r15 != 0) {
        // 0x800552D0: nop

            goto L_800552F4;
    }
    // 0x800552D0: nop

    // 0x800552D4: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800552D8: nop

    // 0x800552DC: bne         $t2, $zero, L_800552F4
    if (ctx->r10 != 0) {
        // 0x800552E0: nop

            goto L_800552F4;
    }
    // 0x800552E0: nop

    // 0x800552E4: lh          $t3, 0x6($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X6);
    // 0x800552E8: nop

    // 0x800552EC: beq         $t3, $zero, L_80055330
    if (ctx->r11 == 0) {
        // 0x800552F0: nop

            goto L_80055330;
    }
    // 0x800552F0: nop

L_800552F4:
    // 0x800552F4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800552F8: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800552FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80055300: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80055304: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80055308: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x8005530C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80055310: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80055314: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80055318: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005531C: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x80055320: b           L_80055488
    // 0x80055324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055488;
    // 0x80055324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055328: b           L_80055338
    // 0x8005532C: nop

        goto L_80055338;
    // 0x8005532C: nop

L_80055330:
    // 0x80055330: b           L_80055488
    // 0x80055334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x80055334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80055338:
    // 0x80055338: jal         0x8005A578
    // 0x8005533C: nop

    func_8005A578(rdram, ctx);
        goto after_1;
    // 0x8005533C: nop

    after_1:
    // 0x80055340: beq         $v0, $zero, L_80055478
    if (ctx->r2 == 0) {
        // 0x80055344: nop

            goto L_80055478;
    }
    // 0x80055344: nop

    // 0x80055348: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005534C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80055350: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80055354: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x80055358: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8005535C: bne         $t0, $zero, L_80055478
    if (ctx->r8 != 0) {
        // 0x80055360: andi        $t1, $t3, 0x1000
        ctx->r9 = ctx->r11 & 0X1000;
            goto L_80055478;
    }
    // 0x80055360: andi        $t1, $t3, 0x1000
    ctx->r9 = ctx->r11 & 0X1000;
    // 0x80055364: bne         $t1, $zero, L_80055478
    if (ctx->r9 != 0) {
        // 0x80055368: nop

            goto L_80055478;
    }
    // 0x80055368: nop

    // 0x8005536C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80055370: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80055374: addiu       $at, $zero, 0xE10
    ctx->r1 = ADD32(0, 0XE10);
    // 0x80055378: lh          $t9, 0x3E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X3E);
    // 0x8005537C: nop

    // 0x80055380: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80055384: mflo        $t6
    ctx->r14 = lo;
    // 0x80055388: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8005538C: beq         $at, $zero, L_800553A4
    if (ctx->r1 == 0) {
        // 0x80055390: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800553A4;
    }
    // 0x80055390: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80055394: lh          $t7, 0x3E($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X3E);
    // 0x80055398: nop

    // 0x8005539C: bgez        $t7, L_800553BC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800553A0: nop

            goto L_800553BC;
    }
    // 0x800553A0: nop

L_800553A4:
    // 0x800553A4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800553A8: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800553AC: addiu       $t4, $zero, 0xE10
    ctx->r12 = ADD32(0, 0XE10);
    // 0x800553B0: sh          $t4, 0x3E($t5)
    MEM_H(0X3E, ctx->r13) = ctx->r12;
    // 0x800553B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800553B8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_800553BC:
    // 0x800553BC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800553C0: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x800553C4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800553C8: lh          $t0, 0x3C($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X3C);
    // 0x800553CC: nop

    // 0x800553D0: beq         $t0, $t1, L_80055478
    if (ctx->r8 == ctx->r9) {
        // 0x800553D4: nop

            goto L_80055478;
    }
    // 0x800553D4: nop

    // 0x800553D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800553DC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800553E0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800553E4: nop

    // 0x800553E8: sh          $t9, 0x3C($t6)
    MEM_H(0X3C, ctx->r14) = ctx->r25;
    // 0x800553EC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800553F0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800553F4: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800553F8: lw          $t4, 0x5A8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5A8);
    // 0x800553FC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80055400: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80055404: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x80055408: lh          $t2, 0x0($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X0);
    // 0x8005540C: nop

    // 0x80055410: bne         $t2, $zero, L_80055448
    if (ctx->r10 != 0) {
        // 0x80055414: nop

            goto L_80055448;
    }
    // 0x80055414: nop

    // 0x80055418: lh          $t3, 0x2($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X2);
    // 0x8005541C: nop

    // 0x80055420: bne         $t3, $zero, L_80055448
    if (ctx->r11 != 0) {
        // 0x80055424: nop

            goto L_80055448;
    }
    // 0x80055424: nop

    // 0x80055428: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
    // 0x8005542C: nop

    // 0x80055430: bne         $t0, $zero, L_80055448
    if (ctx->r8 != 0) {
        // 0x80055434: nop

            goto L_80055448;
    }
    // 0x80055434: nop

    // 0x80055438: lh          $t1, 0x6($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X6);
    // 0x8005543C: nop

    // 0x80055440: beq         $t1, $zero, L_80055478
    if (ctx->r9 == 0) {
        // 0x80055444: nop

            goto L_80055478;
    }
    // 0x80055444: nop

L_80055448:
    // 0x80055448: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005544C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80055450: nop

    // 0x80055454: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80055458: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8005545C: or          $t4, $t9, $zero
    ctx->r12 = ctx->r25 | 0;
    // 0x80055460: ori         $t8, $t6, 0x8
    ctx->r24 = ctx->r14 | 0X8;
    // 0x80055464: ori         $t9, $t7, 0x0
    ctx->r25 = ctx->r15 | 0X0;
    // 0x80055468: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8005546C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80055470: b           L_80055488
    // 0x80055474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x80055474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80055478:
    // 0x80055478: b           L_80055488
    // 0x8005547C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x8005547C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80055480: b           L_80055488
    // 0x80055484: nop

        goto L_80055488;
    // 0x80055484: nop

L_80055488:
    // 0x80055488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005548C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80055490: jr          $ra
    // 0x80055494: nop

    return;
    // 0x80055494: nop

;}
RECOMP_FUNC void func_80055498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055498: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005549C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800554A0: addiu       $t7, $t7, -0x27CC
    ctx->r15 = ADD32(ctx->r15, -0X27CC);
    // 0x800554A4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800554A8: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x800554AC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800554B0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800554B4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800554B8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800554BC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800554C0: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800554C4: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x800554C8: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800554CC: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x800554D0: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x800554D4: lw          $t0, 0x14($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X14);
    // 0x800554D8: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x800554DC: sw          $t0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r8;
    // 0x800554E0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800554E4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800554E8: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x800554EC: nop

    // 0x800554F0: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x800554F4: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x800554F8: nop

    // 0x800554FC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80055500: sh          $t4, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r12;
    // 0x80055504: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80055508: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x8005550C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80055510: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80055514: nop

    // 0x80055518: lh          $t8, 0xC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0XC);
    // 0x8005551C: lh          $t6, 0xA($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XA);
    // 0x80055520: nop

    // 0x80055524: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80055528: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x8005552C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80055530: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
    // 0x80055534: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80055538: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005553C: nop

    // 0x80055540: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x80055544: lh          $t3, 0x10($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X10);
    // 0x80055548: nop

    // 0x8005554C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80055550: sh          $t4, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r12;
    // 0x80055554: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80055558: sh          $t5, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r13;
    // 0x8005555C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80055560: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80055564: nop

    // 0x80055568: lh          $t8, 0x16($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X16);
    // 0x8005556C: lh          $t6, 0x14($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X14);
    // 0x80055570: nop

    // 0x80055574: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80055578: sh          $t7, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r15;
L_8005557C:
    // 0x8005557C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80055580: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80055584:
    // 0x80055584: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80055588: nop

    // 0x8005558C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80055590: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x80055594: addu        $t4, $a0, $t1
    ctx->r12 = ADD32(ctx->r4, ctx->r9);
    // 0x80055598: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x8005559C: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x800555A0: nop

    // 0x800555A4: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800555A8: beq         $at, $zero, L_80055620
    if (ctx->r1 == 0) {
        // 0x800555AC: nop

            goto L_80055620;
    }
    // 0x800555AC: nop

    // 0x800555B0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800555B4: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x800555B8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800555BC: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800555C0: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x800555C4: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x800555C8: nop

    // 0x800555CC: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800555D0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800555D4: nop

    // 0x800555D8: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800555DC: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800555E0: lwl         $at, 0x4($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X4);
    // 0x800555E4: lwr         $at, 0x7($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X7);
    // 0x800555E8: addu        $t3, $a0, $t4
    ctx->r11 = ADD32(ctx->r4, ctx->r12);
    // 0x800555EC: swl         $at, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r1);
    // 0x800555F0: swr         $at, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r1);
    // 0x800555F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800555F8: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x800555FC: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80055600: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80055604: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x80055608: swl         $at, 0x4($t7)
    do_swl(rdram, 0X4, ctx->r15, ctx->r1);
    // 0x8005560C: swr         $at, 0x7($t7)
    do_swr(rdram, 0X7, ctx->r15, ctx->r1);
    // 0x80055610: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80055614: nop

    // 0x80055618: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8005561C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80055620:
    // 0x80055620: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80055624: nop

    // 0x80055628: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005562C: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80055630: bne         $at, $zero, L_80055584
    if (ctx->r1 != 0) {
        // 0x80055634: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80055584;
    }
    // 0x80055634: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80055638: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005563C: nop

    // 0x80055640: bne         $t0, $zero, L_8005557C
    if (ctx->r8 != 0) {
        // 0x80055644: nop

            goto L_8005557C;
    }
    // 0x80055644: nop

    // 0x80055648: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005564C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80055650: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80055654:
    // 0x80055654: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80055658: nop

    // 0x8005565C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80055660: addu        $t7, $t1, $a0
    ctx->r15 = ADD32(ctx->r9, ctx->r4);
    // 0x80055664: lh          $t2, 0x2($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X2);
    // 0x80055668: nop

    // 0x8005566C: beq         $t2, $zero, L_8005574C
    if (ctx->r10 == 0) {
        // 0x80055670: nop

            goto L_8005574C;
    }
    // 0x80055670: nop

    // 0x80055674: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055678: nop

    // 0x8005567C: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80055680: addu        $t3, $t8, $a0
    ctx->r11 = ADD32(ctx->r24, ctx->r4);
    // 0x80055684: lh          $t5, 0x2($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X2);
    // 0x80055688: nop

    // 0x8005568C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80055690: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80055694: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80055698: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8005569C: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x800556A0: addu        $t4, $sp, $t2
    ctx->r12 = ADD32(ctx->r29, ctx->r10);
    // 0x800556A4: addu        $t9, $t0, $a0
    ctx->r25 = ADD32(ctx->r8, ctx->r4);
    // 0x800556A8: lh          $t1, 0x2($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X2);
    // 0x800556AC: lw          $t4, 0x4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4);
    // 0x800556B0: addu        $t3, $t0, $a0
    ctx->r11 = ADD32(ctx->r8, ctx->r4);
    // 0x800556B4: multu       $t1, $t4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800556B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800556BC: sh          $t8, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r24;
    // 0x800556C0: nop

    // 0x800556C4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800556C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800556CC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800556D0: addu        $t9, $t6, $a0
    ctx->r25 = ADD32(ctx->r14, ctx->r4);
    // 0x800556D4: lh          $t7, 0x2($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X2);
    // 0x800556D8: addu        $t1, $t6, $a0
    ctx->r9 = ADD32(ctx->r14, ctx->r4);
    // 0x800556DC: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800556E0: mflo        $t2
    ctx->r10 = lo;
    // 0x800556E4: sh          $t2, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r10;
    // 0x800556E8: nop

    // 0x800556EC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800556F0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800556F4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800556F8: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x800556FC: lh          $t5, 0x2($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X2);
    // 0x80055700: nop

    // 0x80055704: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x80055708: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8005570C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80055710: nop

    // 0x80055714: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80055718: beq         $at, $zero, L_8005574C
    if (ctx->r1 == 0) {
        // 0x8005571C: nop

            goto L_8005574C;
    }
    // 0x8005571C: nop

    // 0x80055720: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80055724: addu        $t2, $t6, $a0
    ctx->r10 = ADD32(ctx->r14, ctx->r4);
    // 0x80055728: lh          $t1, 0x6($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X6);
    // 0x8005572C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80055730: nop

    // 0x80055734: beq         $t1, $t0, L_8005574C
    if (ctx->r9 == ctx->r8) {
        // 0x80055738: nop

            goto L_8005574C;
    }
    // 0x80055738: nop

    // 0x8005573C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80055740: nop

    // 0x80055744: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x80055748: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
L_8005574C:
    // 0x8005574C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055750: nop

    // 0x80055754: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80055758: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8005575C: bne         $at, $zero, L_80055654
    if (ctx->r1 != 0) {
        // 0x80055760: sw          $t5, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r13;
            goto L_80055654;
    }
    // 0x80055760: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80055764: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80055768: nop

    // 0x8005576C: bne         $t9, $zero, L_800557A8
    if (ctx->r25 != 0) {
        // 0x80055770: nop

            goto L_800557A8;
    }
    // 0x80055770: nop

    // 0x80055774: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80055778: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8005577C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80055780: lw          $t2, 0x670($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X670);
    // 0x80055784: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055788: bgez        $t2, L_8005579C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8005578C: andi        $t1, $t2, 0x3
        ctx->r9 = ctx->r10 & 0X3;
            goto L_8005579C;
    }
    // 0x8005578C: andi        $t1, $t2, 0x3
    ctx->r9 = ctx->r10 & 0X3;
    // 0x80055790: beq         $t1, $zero, L_8005579C
    if (ctx->r9 == 0) {
        // 0x80055794: nop

            goto L_8005579C;
    }
    // 0x80055794: nop

    // 0x80055798: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_8005579C:
    // 0x8005579C: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x800557A0: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x800557A4: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
L_800557A8:
    // 0x800557A8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800557AC: lw          $t3, 0x670($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X670);
    // 0x800557B0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800557B4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800557B8: div         $zero, $t3, $t4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r12)));
    // 0x800557BC: bne         $t4, $zero, L_800557C8
    if (ctx->r12 != 0) {
        // 0x800557C0: nop

            goto L_800557C8;
    }
    // 0x800557C0: nop

    // 0x800557C4: break       7
    do_break(2147833796);
L_800557C8:
    // 0x800557C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800557CC: bne         $t4, $at, L_800557E0
    if (ctx->r12 != ctx->r1) {
        // 0x800557D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800557E0;
    }
    // 0x800557D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800557D4: bne         $t3, $at, L_800557E0
    if (ctx->r11 != ctx->r1) {
        // 0x800557D8: nop

            goto L_800557E0;
    }
    // 0x800557D8: nop

    // 0x800557DC: break       6
    do_break(2147833820);
L_800557E0:
    // 0x800557E0: mfhi        $t5
    ctx->r13 = hi;
    // 0x800557E4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800557E8: nop

L_800557EC:
    // 0x800557EC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800557F0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800557F4: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x800557F8: addu        $t1, $a0, $t2
    ctx->r9 = ADD32(ctx->r4, ctx->r10);
    // 0x800557FC: lh          $t0, 0x2($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2);
    // 0x80055800: nop

    // 0x80055804: subu        $t6, $t9, $t0
    ctx->r14 = SUB32(ctx->r25, ctx->r8);
    // 0x80055808: bgez        $t6, L_8005582C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005580C: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_8005582C;
    }
    // 0x8005580C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80055810: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80055814: nop

    // 0x80055818: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8005581C: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x80055820: lh          $v0, 0x0($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X0);
    // 0x80055824: b           L_80055868
    // 0x80055828: nop

        goto L_80055868;
    // 0x80055828: nop

L_8005582C:
    // 0x8005582C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80055830: nop

    // 0x80055834: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80055838: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8005583C: bne         $at, $zero, L_800557EC
    if (ctx->r1 != 0) {
        // 0x80055840: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_800557EC;
    }
    // 0x80055840: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80055844: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80055848: nop

    // 0x8005584C: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80055850: addu        $t9, $t1, $a0
    ctx->r25 = ADD32(ctx->r9, ctx->r4);
    // 0x80055854: lh          $v0, 0x0($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X0);
    // 0x80055858: b           L_80055868
    // 0x8005585C: nop

        goto L_80055868;
    // 0x8005585C: nop

    // 0x80055860: b           L_80055868
    // 0x80055864: nop

        goto L_80055868;
    // 0x80055864: nop

L_80055868:
    // 0x80055868: jr          $ra
    // 0x8005586C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005586C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80055870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055870: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80055874: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80055878: addiu       $t7, $t7, -0x27B0
    ctx->r15 = ADD32(ctx->r15, -0X27B0);
    // 0x8005587C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80055880: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80055884: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80055888: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8005588C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80055890: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80055894: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80055898: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8005589C: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x800558A0: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800558A4: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x800558A8: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x800558AC: lw          $t0, 0x14($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X14);
    // 0x800558B0: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x800558B4: sw          $t0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r8;
    // 0x800558B8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_800558BC:
    // 0x800558BC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800558C0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800558C4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800558C8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800558CC: addiu       $t5, $t5, -0x2AC0
    ctx->r13 = ADD32(ctx->r13, -0X2AC0);
    // 0x800558D0: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800558D4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800558D8: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x800558DC: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x800558E0: lw          $t3, 0xC($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XC);
    // 0x800558E4: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x800558E8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800558EC: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800558F0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800558F4: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x800558F8: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x800558FC: nop

    // 0x80055900: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80055904: bne         $at, $zero, L_80055920
    if (ctx->r1 != 0) {
        // 0x80055908: nop

            goto L_80055920;
    }
    // 0x80055908: nop

    // 0x8005590C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80055910: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80055914: addu        $t3, $a0, $t7
    ctx->r11 = ADD32(ctx->r4, ctx->r15);
    // 0x80055918: b           L_80055944
    // 0x8005591C: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
        goto L_80055944;
    // 0x8005591C: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
L_80055920:
    // 0x80055920: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80055924: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80055928: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8005592C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80055930: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x80055934: lw          $t0, -0x2AB8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AB8);
    // 0x80055938: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8005593C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80055940: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
L_80055944:
    // 0x80055944: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80055948: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8005594C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80055950: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80055954: addiu       $t4, $t4, -0x2AC0
    ctx->r12 = ADD32(ctx->r12, -0X2AC0);
    // 0x80055958: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8005595C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80055960: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80055964: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x80055968: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8005596C: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x80055970: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x80055974: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80055978: addu        $t0, $t2, $t8
    ctx->r8 = ADD32(ctx->r10, ctx->r24);
    // 0x8005597C: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80055980: lh          $t1, 0x0($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X0);
    // 0x80055984: nop

    // 0x80055988: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005598C: bne         $at, $zero, L_800559A4
    if (ctx->r1 != 0) {
        // 0x80055990: nop

            goto L_800559A4;
    }
    // 0x80055990: nop

    // 0x80055994: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055998: addu        $t0, $a0, $t8
    ctx->r8 = ADD32(ctx->r4, ctx->r24);
    // 0x8005599C: b           L_800559DC
    // 0x800559A0: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
        goto L_800559DC;
    // 0x800559A0: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
L_800559A4:
    // 0x800559A4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800559A8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800559AC: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x800559B0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800559B4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800559B8: lw          $t4, -0x2AB4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AB4);
    // 0x800559BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800559C0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800559C4: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x800559C8: addu        $t7, $t5, $t1
    ctx->r15 = ADD32(ctx->r13, ctx->r9);
    // 0x800559CC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800559D0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800559D4: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x800559D8: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
L_800559DC:
    // 0x800559DC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800559E0: nop

    // 0x800559E4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800559E8: sltiu       $at, $t3, 0x7
    ctx->r1 = ctx->r11 < 0X7 ? 1 : 0;
    // 0x800559EC: bne         $at, $zero, L_800558BC
    if (ctx->r1 != 0) {
        // 0x800559F0: sw          $t3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r11;
            goto L_800558BC;
    }
    // 0x800559F0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_800559F4:
    // 0x800559F4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800559F8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_800559FC:
    // 0x800559FC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055A00: nop

    // 0x80055A04: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80055A08: addu        $t1, $t5, $a0
    ctx->r9 = ADD32(ctx->r13, ctx->r4);
    // 0x80055A0C: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80055A10: lh          $t9, 0x6($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X6);
    // 0x80055A14: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x80055A18: nop

    // 0x80055A1C: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80055A20: beq         $at, $zero, L_80055A98
    if (ctx->r1 == 0) {
        // 0x80055A24: nop

            goto L_80055A98;
    }
    // 0x80055A24: nop

    // 0x80055A28: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80055A2C: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80055A30: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80055A34: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80055A38: lwl         $at, 0x0($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0X0);
    // 0x80055A3C: lwr         $at, 0x3($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0X3);
    // 0x80055A40: nop

    // 0x80055A44: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80055A48: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80055A4C: nop

    // 0x80055A50: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80055A54: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x80055A58: lwl         $at, 0x4($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X4);
    // 0x80055A5C: lwr         $at, 0x7($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X7);
    // 0x80055A60: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80055A64: swl         $at, 0x0($t7)
    do_swl(rdram, 0X0, ctx->r15, ctx->r1);
    // 0x80055A68: swr         $at, 0x3($t7)
    do_swr(rdram, 0X3, ctx->r15, ctx->r1);
    // 0x80055A6C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055A70: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80055A74: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80055A78: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80055A7C: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x80055A80: swl         $at, 0x4($t3)
    do_swl(rdram, 0X4, ctx->r11, ctx->r1);
    // 0x80055A84: swr         $at, 0x7($t3)
    do_swr(rdram, 0X7, ctx->r11, ctx->r1);
    // 0x80055A88: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80055A8C: nop

    // 0x80055A90: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80055A94: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80055A98:
    // 0x80055A98: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80055A9C: nop

    // 0x80055AA0: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80055AA4: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x80055AA8: bne         $at, $zero, L_800559FC
    if (ctx->r1 != 0) {
        // 0x80055AAC: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_800559FC;
    }
    // 0x80055AAC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80055AB0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80055AB4: nop

    // 0x80055AB8: bne         $t4, $zero, L_800559F4
    if (ctx->r12 != 0) {
        // 0x80055ABC: nop

            goto L_800559F4;
    }
    // 0x80055ABC: nop

    // 0x80055AC0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80055AC4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80055AC8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80055ACC:
    // 0x80055ACC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80055AD0: nop

    // 0x80055AD4: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80055AD8: addu        $t3, $t5, $a0
    ctx->r11 = ADD32(ctx->r13, ctx->r4);
    // 0x80055ADC: lh          $t1, 0x2($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X2);
    // 0x80055AE0: nop

    // 0x80055AE4: beq         $t1, $zero, L_80055BC4
    if (ctx->r9 == 0) {
        // 0x80055AE8: nop

            goto L_80055BC4;
    }
    // 0x80055AE8: nop

    // 0x80055AEC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80055AF0: nop

    // 0x80055AF4: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80055AF8: addu        $t7, $t0, $a0
    ctx->r15 = ADD32(ctx->r8, ctx->r4);
    // 0x80055AFC: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x80055B00: nop

    // 0x80055B04: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80055B08: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80055B0C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80055B10: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80055B14: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80055B18: addu        $t6, $sp, $t1
    ctx->r14 = ADD32(ctx->r29, ctx->r9);
    // 0x80055B1C: addu        $t8, $t4, $a0
    ctx->r24 = ADD32(ctx->r12, ctx->r4);
    // 0x80055B20: lh          $t5, 0x2($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X2);
    // 0x80055B24: lw          $t6, 0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4);
    // 0x80055B28: addu        $t7, $t4, $a0
    ctx->r15 = ADD32(ctx->r12, ctx->r4);
    // 0x80055B2C: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055B30: mflo        $t0
    ctx->r8 = lo;
    // 0x80055B34: sh          $t0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r8;
    // 0x80055B38: nop

    // 0x80055B3C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80055B40: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80055B44: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80055B48: addu        $t8, $t2, $a0
    ctx->r24 = ADD32(ctx->r10, ctx->r4);
    // 0x80055B4C: lh          $t3, 0x2($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X2);
    // 0x80055B50: addu        $t5, $t2, $a0
    ctx->r13 = ADD32(ctx->r10, ctx->r4);
    // 0x80055B54: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80055B58: mflo        $t1
    ctx->r9 = lo;
    // 0x80055B5C: sh          $t1, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r9;
    // 0x80055B60: nop

    // 0x80055B64: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055B68: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80055B6C: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x80055B70: addu        $t7, $a0, $t0
    ctx->r15 = ADD32(ctx->r4, ctx->r8);
    // 0x80055B74: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x80055B78: nop

    // 0x80055B7C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80055B80: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80055B84: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80055B88: nop

    // 0x80055B8C: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x80055B90: beq         $at, $zero, L_80055BC4
    if (ctx->r1 == 0) {
        // 0x80055B94: nop

            goto L_80055BC4;
    }
    // 0x80055B94: nop

    // 0x80055B98: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80055B9C: addu        $t1, $t2, $a0
    ctx->r9 = ADD32(ctx->r10, ctx->r4);
    // 0x80055BA0: lh          $t5, 0x6($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X6);
    // 0x80055BA4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80055BA8: nop

    // 0x80055BAC: beq         $t5, $t4, L_80055BC4
    if (ctx->r13 == ctx->r12) {
        // 0x80055BB0: nop

            goto L_80055BC4;
    }
    // 0x80055BB0: nop

    // 0x80055BB4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80055BB8: nop

    // 0x80055BBC: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80055BC0: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_80055BC4:
    // 0x80055BC4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80055BC8: nop

    // 0x80055BCC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80055BD0: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x80055BD4: bne         $at, $zero, L_80055ACC
    if (ctx->r1 != 0) {
        // 0x80055BD8: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80055ACC;
    }
    // 0x80055BD8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80055BDC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80055BE0: nop

    // 0x80055BE4: bne         $t8, $zero, L_80055BFC
    if (ctx->r24 != 0) {
        // 0x80055BE8: nop

            goto L_80055BFC;
    }
    // 0x80055BE8: nop

    // 0x80055BEC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80055BF0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80055BF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80055BF8: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
L_80055BFC:
    // 0x80055BFC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80055C00: lw          $t1, 0x670($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X670);
    // 0x80055C04: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80055C08: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80055C0C: div         $zero, $t1, $t5
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r13)));
    // 0x80055C10: bne         $t5, $zero, L_80055C1C
    if (ctx->r13 != 0) {
        // 0x80055C14: nop

            goto L_80055C1C;
    }
    // 0x80055C14: nop

    // 0x80055C18: break       7
    do_break(2147834904);
L_80055C1C:
    // 0x80055C1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055C20: bne         $t5, $at, L_80055C34
    if (ctx->r13 != ctx->r1) {
        // 0x80055C24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80055C34;
    }
    // 0x80055C24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80055C28: bne         $t1, $at, L_80055C34
    if (ctx->r9 != ctx->r1) {
        // 0x80055C2C: nop

            goto L_80055C34;
    }
    // 0x80055C2C: nop

    // 0x80055C30: break       6
    do_break(2147834928);
L_80055C34:
    // 0x80055C34: mfhi        $t4
    ctx->r12 = hi;
    // 0x80055C38: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80055C3C: nop

L_80055C40:
    // 0x80055C40: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80055C44: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80055C48: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80055C4C: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x80055C50: lh          $t8, 0x2($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X2);
    // 0x80055C54: nop

    // 0x80055C58: subu        $t3, $t0, $t8
    ctx->r11 = SUB32(ctx->r8, ctx->r24);
    // 0x80055C5C: bgez        $t3, L_80055C80
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80055C60: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_80055C80;
    }
    // 0x80055C60: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80055C64: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80055C68: nop

    // 0x80055C6C: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80055C70: addu        $t5, $t1, $a0
    ctx->r13 = ADD32(ctx->r9, ctx->r4);
    // 0x80055C74: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x80055C78: b           L_80055CBC
    // 0x80055C7C: nop

        goto L_80055CBC;
    // 0x80055C7C: nop

L_80055C80:
    // 0x80055C80: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055C84: nop

    // 0x80055C88: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x80055C8C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80055C90: bne         $at, $zero, L_80055C40
    if (ctx->r1 != 0) {
        // 0x80055C94: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_80055C40;
    }
    // 0x80055C94: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80055C98: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80055C9C: nop

    // 0x80055CA0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80055CA4: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80055CA8: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80055CAC: b           L_80055CBC
    // 0x80055CB0: nop

        goto L_80055CBC;
    // 0x80055CB0: nop

    // 0x80055CB4: b           L_80055CBC
    // 0x80055CB8: nop

        goto L_80055CBC;
    // 0x80055CB8: nop

L_80055CBC:
    // 0x80055CBC: jr          $ra
    // 0x80055CC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80055CC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80055CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055CC4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80055CC8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80055CCC:
    // 0x80055CCC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80055CD0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80055CD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055CD8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80055CDC: addiu       $t0, $t0, -0x2AC0
    ctx->r8 = ADD32(ctx->r8, -0X2AC0);
    // 0x80055CE0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80055CE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80055CE8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80055CEC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80055CF0: lw          $t8, 0xC($t1)
    ctx->r24 = MEM_W(ctx->r9, 0XC);
    // 0x80055CF4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80055CF8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80055CFC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80055D00: addu        $t4, $t6, $t3
    ctx->r12 = ADD32(ctx->r14, ctx->r11);
    // 0x80055D04: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80055D08: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x80055D0C: nop

    // 0x80055D10: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80055D14: bne         $at, $zero, L_80055D30
    if (ctx->r1 != 0) {
        // 0x80055D18: nop

            goto L_80055D30;
    }
    // 0x80055D18: nop

    // 0x80055D1C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80055D20: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80055D24: addu        $t8, $a0, $t4
    ctx->r24 = ADD32(ctx->r4, ctx->r12);
    // 0x80055D28: b           L_80055D54
    // 0x80055D2C: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
        goto L_80055D54;
    // 0x80055D2C: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
L_80055D30:
    // 0x80055D30: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80055D34: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80055D38: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80055D3C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80055D40: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x80055D44: lw          $t5, -0x2AB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AB8);
    // 0x80055D48: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80055D4C: addu        $t1, $a0, $t2
    ctx->r9 = ADD32(ctx->r4, ctx->r10);
    // 0x80055D50: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
L_80055D54:
    // 0x80055D54: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80055D58: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80055D5C: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80055D60: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80055D64: addiu       $t9, $t9, -0x2AC0
    ctx->r25 = ADD32(ctx->r25, -0X2AC0);
    // 0x80055D68: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80055D6C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80055D70: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80055D74: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x80055D78: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x80055D7C: sll         $t2, $t6, 1
    ctx->r10 = S32(ctx->r14 << 1);
    // 0x80055D80: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x80055D84: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80055D88: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x80055D8C: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80055D90: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80055D94: nop

    // 0x80055D98: slt         $at, $t1, $t6
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80055D9C: bne         $at, $zero, L_80055DB4
    if (ctx->r1 != 0) {
        // 0x80055DA0: nop

            goto L_80055DB4;
    }
    // 0x80055DA0: nop

    // 0x80055DA4: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x80055DA8: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x80055DAC: b           L_80055DEC
    // 0x80055DB0: sh          $t1, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r9;
        goto L_80055DEC;
    // 0x80055DB0: sh          $t1, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r9;
L_80055DB4:
    // 0x80055DB4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80055DB8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80055DBC: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80055DC0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055DC4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80055DC8: lw          $t9, -0x2AB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AB4);
    // 0x80055DCC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80055DD0: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80055DD4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80055DD8: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x80055DDC: lh          $t2, 0x0($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X0);
    // 0x80055DE0: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80055DE4: addu        $t5, $a0, $t1
    ctx->r13 = ADD32(ctx->r4, ctx->r9);
    // 0x80055DE8: sh          $t2, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r10;
L_80055DEC:
    // 0x80055DEC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80055DF0: nop

    // 0x80055DF4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80055DF8: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80055DFC: bne         $at, $zero, L_80055CCC
    if (ctx->r1 != 0) {
        // 0x80055E00: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_80055CCC;
    }
    // 0x80055E00: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80055E04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80055E08: lw          $t9, 0x258C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X258C);
    // 0x80055E0C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80055E10: srl         $t0, $t9, 1
    ctx->r8 = S32(U32(ctx->r25) >> 1);
    // 0x80055E14: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x80055E18: mfhi        $t6
    ctx->r14 = hi;
    // 0x80055E1C: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80055E20: addu        $t3, $t4, $a0
    ctx->r11 = ADD32(ctx->r12, ctx->r4);
    // 0x80055E24: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x80055E28: b           L_80055E38
    // 0x80055E2C: nop

        goto L_80055E38;
    // 0x80055E2C: nop

    // 0x80055E30: b           L_80055E38
    // 0x80055E34: nop

        goto L_80055E38;
    // 0x80055E34: nop

L_80055E38:
    // 0x80055E38: jr          $ra
    // 0x80055E3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80055E3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80055E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055E40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80055E44: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80055E48: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80055E4C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80055E50:
    // 0x80055E50: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80055E54: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80055E58: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055E5C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80055E60: addiu       $t0, $t0, -0x2AC0
    ctx->r8 = ADD32(ctx->r8, -0X2AC0);
    // 0x80055E64: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80055E68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80055E6C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80055E70: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80055E74: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80055E78: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80055E7C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80055E80: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80055E84: addu        $t4, $t6, $t3
    ctx->r12 = ADD32(ctx->r14, ctx->r11);
    // 0x80055E88: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80055E8C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80055E90: nop

    // 0x80055E94: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80055E98: bne         $at, $zero, L_80055F38
    if (ctx->r1 != 0) {
        // 0x80055E9C: nop

            goto L_80055F38;
    }
    // 0x80055E9C: nop

    // 0x80055EA0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80055EA4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80055EA8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80055EAC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80055EB0: addiu       $t1, $t1, -0x2AC0
    ctx->r9 = ADD32(ctx->r9, -0X2AC0);
    // 0x80055EB4: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x80055EB8: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x80055EBC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80055EC0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80055EC4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80055EC8: lw          $t9, -0x2A60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2A60);
    // 0x80055ECC: nop

    // 0x80055ED0: beq         $t9, $zero, L_80055F38
    if (ctx->r25 == 0) {
        // 0x80055ED4: nop

            goto L_80055F38;
    }
    // 0x80055ED4: nop

    // 0x80055ED8: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80055EDC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80055EE0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80055EE4: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80055EE8: addu        $t3, $t5, $t2
    ctx->r11 = ADD32(ctx->r13, ctx->r10);
    // 0x80055EEC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80055EF0: nop

    // 0x80055EF4: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80055EF8: bne         $at, $zero, L_80055F38
    if (ctx->r1 != 0) {
        // 0x80055EFC: nop

            goto L_80055F38;
    }
    // 0x80055EFC: nop

    // 0x80055F00: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80055F04: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80055F08: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80055F0C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80055F10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80055F14: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80055F18: lw          $t9, -0x2AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AB8);
    // 0x80055F1C: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80055F20: addu        $t5, $sp, $t0
    ctx->r13 = ADD32(ctx->r29, ctx->r8);
    // 0x80055F24: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80055F28: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80055F2C: nop

    // 0x80055F30: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80055F34: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80055F38:
    // 0x80055F38: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055F3C: nop

    // 0x80055F40: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x80055F44: sltiu       $at, $t1, 0x7
    ctx->r1 = ctx->r9 < 0X7 ? 1 : 0;
    // 0x80055F48: bne         $at, $zero, L_80055E50
    if (ctx->r1 != 0) {
        // 0x80055F4C: sw          $t1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r9;
            goto L_80055E50;
    }
    // 0x80055F4C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80055F50: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80055F54: nop

    // 0x80055F58: bne         $t6, $zero, L_80055F70
    if (ctx->r14 != 0) {
        // 0x80055F5C: nop

            goto L_80055F70;
    }
    // 0x80055F5C: nop

    // 0x80055F60: b           L_80055FB0
    // 0x80055F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055FB0;
    // 0x80055F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80055F68: b           L_80055FA8
    // 0x80055F6C: nop

        goto L_80055FA8;
    // 0x80055F6C: nop

L_80055F70:
    // 0x80055F70: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80055F74: lw          $t8, 0x258C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X258C);
    // 0x80055F78: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80055F7C: srl         $t7, $t8, 1
    ctx->r15 = S32(U32(ctx->r24) >> 1);
    // 0x80055F80: divu        $zero, $t7, $t9
    lo = S32(U32(ctx->r15) / U32(ctx->r25)); hi = S32(U32(ctx->r15) % U32(ctx->r25));
    // 0x80055F84: bne         $t9, $zero, L_80055F90
    if (ctx->r25 != 0) {
        // 0x80055F88: nop

            goto L_80055F90;
    }
    // 0x80055F88: nop

    // 0x80055F8C: break       7
    do_break(2147835788);
L_80055F90:
    // 0x80055F90: mfhi        $t0
    ctx->r8 = hi;
    // 0x80055F94: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80055F98: addu        $v0, $sp, $t5
    ctx->r2 = ADD32(ctx->r29, ctx->r13);
    // 0x80055F9C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80055FA0: b           L_80055FB0
    // 0x80055FA4: nop

        goto L_80055FB0;
    // 0x80055FA4: nop

L_80055FA8:
    // 0x80055FA8: b           L_80055FB0
    // 0x80055FAC: nop

        goto L_80055FB0;
    // 0x80055FAC: nop

L_80055FB0:
    // 0x80055FB0: jr          $ra
    // 0x80055FB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80055FB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80055FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80055FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80055FC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80055FC8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80055FCC: nop

    // 0x80055FD0: beq         $t6, $zero, L_8005608C
    if (ctx->r14 == 0) {
        // 0x80055FD4: nop

            goto L_8005608C;
    }
    // 0x80055FD4: nop

    // 0x80055FD8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80055FDC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80055FE0: bne         $t7, $at, L_80056058
    if (ctx->r15 != ctx->r1) {
        // 0x80055FE4: nop

            goto L_80056058;
    }
    // 0x80055FE4: nop

    // 0x80055FE8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80055FEC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80055FF0: nop

    // 0x80055FF4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80055FF8: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80055FFC: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80056000: ori         $t3, $t1, 0x1000
    ctx->r11 = ctx->r9 | 0X1000;
    // 0x80056004: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80056008: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005600C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80056010: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80056014: sh          $t9, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r25;
    // 0x80056018: jal         0x8005A578
    // 0x8005601C: nop

    func_8005A578(rdram, ctx);
        goto after_0;
    // 0x8005601C: nop

    after_0:
    // 0x80056020: bne         $v0, $zero, L_80056050
    if (ctx->r2 != 0) {
        // 0x80056024: nop

            goto L_80056050;
    }
    // 0x80056024: nop

    // 0x80056028: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005602C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80056030: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056034: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80056038: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8005603C: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x80056040: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80056044: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x80056048: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8005604C: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_80056050:
    // 0x80056050: b           L_8005608C
    // 0x80056054: nop

        goto L_8005608C;
    // 0x80056054: nop

L_80056058:
    // 0x80056058: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005605C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80056060: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056064: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80056068: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8005606C: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x80056070: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80056074: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80056078: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8005607C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80056080: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80056084: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80056088: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
L_8005608C:
    // 0x8005608C: b           L_80056094
    // 0x80056090: nop

        goto L_80056094;
    // 0x80056090: nop

L_80056094:
    // 0x80056094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005609C: jr          $ra
    // 0x800560A0: nop

    return;
    // 0x800560A0: nop

;}
RECOMP_FUNC void func_800560A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800560A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800560A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800560AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800560B0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800560B4: nop

    // 0x800560B8: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800560BC: nop

    // 0x800560C0: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x800560C4: bne         $at, $zero, L_800560F0
    if (ctx->r1 != 0) {
        // 0x800560C8: nop

            goto L_800560F0;
    }
    // 0x800560C8: nop

    // 0x800560CC: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x800560D0: nop

    // 0x800560D4: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x800560D8: bne         $at, $zero, L_800560F0
    if (ctx->r1 != 0) {
        // 0x800560DC: nop

            goto L_800560F0;
    }
    // 0x800560DC: nop

    // 0x800560E0: jal         0x80061E14
    // 0x800560E4: nop

    func_80061E14(rdram, ctx);
        goto after_0;
    // 0x800560E4: nop

    after_0:
    // 0x800560E8: beq         $v0, $zero, L_800560F8
    if (ctx->r2 == 0) {
        // 0x800560EC: nop

            goto L_800560F8;
    }
    // 0x800560EC: nop

L_800560F0:
    // 0x800560F0: b           L_80056108
    // 0x800560F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80056108;
    // 0x800560F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800560F8:
    // 0x800560F8: b           L_80056108
    // 0x800560FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80056108;
    // 0x800560FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056100: b           L_80056108
    // 0x80056104: nop

        goto L_80056108;
    // 0x80056104: nop

L_80056108:
    // 0x80056108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005610C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80056110: jr          $ra
    // 0x80056114: nop

    return;
    // 0x80056114: nop

;}
RECOMP_FUNC void func_80056118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056118: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005611C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056120: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056124: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80056128: nop

    // 0x8005612C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80056130: nop

    // 0x80056134: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x80056138: bne         $at, $zero, L_80056164
    if (ctx->r1 != 0) {
        // 0x8005613C: nop

            goto L_80056164;
    }
    // 0x8005613C: nop

    // 0x80056140: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x80056144: nop

    // 0x80056148: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x8005614C: bne         $at, $zero, L_80056164
    if (ctx->r1 != 0) {
        // 0x80056150: nop

            goto L_80056164;
    }
    // 0x80056150: nop

    // 0x80056154: jal         0x80061F08
    // 0x80056158: nop

    func_80061F08(rdram, ctx);
        goto after_0;
    // 0x80056158: nop

    after_0:
    // 0x8005615C: beq         $v0, $zero, L_8005616C
    if (ctx->r2 == 0) {
        // 0x80056160: nop

            goto L_8005616C;
    }
    // 0x80056160: nop

L_80056164:
    // 0x80056164: b           L_8005617C
    // 0x80056168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005617C;
    // 0x80056168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005616C:
    // 0x8005616C: b           L_8005617C
    // 0x80056170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005617C;
    // 0x80056170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056174: b           L_8005617C
    // 0x80056178: nop

        goto L_8005617C;
    // 0x80056178: nop

L_8005617C:
    // 0x8005617C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80056184: jr          $ra
    // 0x80056188: nop

    return;
    // 0x80056188: nop

;}
RECOMP_FUNC void func_8005618C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005618C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056190: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056194: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80056198: nop

    // 0x8005619C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800561A0: nop

    // 0x800561A4: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x800561A8: bne         $at, $zero, L_800561C4
    if (ctx->r1 != 0) {
        // 0x800561AC: nop

            goto L_800561C4;
    }
    // 0x800561AC: nop

    // 0x800561B0: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x800561B4: nop

    // 0x800561B8: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x800561BC: beq         $at, $zero, L_800561CC
    if (ctx->r1 == 0) {
        // 0x800561C0: nop

            goto L_800561CC;
    }
    // 0x800561C0: nop

L_800561C4:
    // 0x800561C4: b           L_800561DC
    // 0x800561C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800561DC;
    // 0x800561C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800561CC:
    // 0x800561CC: b           L_800561DC
    // 0x800561D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800561DC;
    // 0x800561D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800561D4: b           L_800561DC
    // 0x800561D8: nop

        goto L_800561DC;
    // 0x800561D8: nop

L_800561DC:
    // 0x800561DC: jr          $ra
    // 0x800561E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800561E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800561E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800561E4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800561E8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800561EC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800561F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800561F4: addiu       $t6, $t6, -0x2A20
    ctx->r14 = ADD32(ctx->r14, -0X2A20);
    // 0x800561F8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800561FC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80056200: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056204: beq         $t7, $at, L_8005625C
    if (ctx->r15 == ctx->r1) {
        // 0x80056208: nop

            goto L_8005625C;
    }
    // 0x80056208: nop

L_8005620C:
    // 0x8005620C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80056210: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80056214: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80056218: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8005621C: lh          $t0, -0x2A20($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2A20);
    // 0x80056220: nop

    // 0x80056224: bne         $t0, $a0, L_80056238
    if (ctx->r8 != ctx->r4) {
        // 0x80056228: nop

            goto L_80056238;
    }
    // 0x80056228: nop

    // 0x8005622C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80056230: b           L_8005626C
    // 0x80056234: nop

        goto L_8005626C;
    // 0x80056234: nop

L_80056238:
    // 0x80056238: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005623C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80056240: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80056244: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80056248: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8005624C: lh          $t4, -0x2A20($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X2A20);
    // 0x80056250: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056254: bne         $t4, $at, L_8005620C
    if (ctx->r12 != ctx->r1) {
        // 0x80056258: sw          $t2, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r10;
            goto L_8005620C;
    }
    // 0x80056258: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
L_8005625C:
    // 0x8005625C: b           L_8005626C
    // 0x80056260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005626C;
    // 0x80056260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80056264: b           L_8005626C
    // 0x80056268: nop

        goto L_8005626C;
    // 0x80056268: nop

L_8005626C:
    // 0x8005626C: jr          $ra
    // 0x80056270: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80056270: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80056274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056274: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80056278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005627C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80056280: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80056284: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056288: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005628C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80056290: lw          $t7, 0x5C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X5C);
    // 0x80056294: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80056298: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8005629C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800562A0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800562A4: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x800562A8: lh          $a3, -0x28C0($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X28C0);
    // 0x800562AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800562B0: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800562B4: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800562B8: ori         $t1, $a3, 0x14B
    ctx->r9 = ctx->r7 | 0X14B;
    // 0x800562BC: jal         0x800B3230
    // 0x800562C0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    func_800B3230(rdram, ctx);
        goto after_0;
    // 0x800562C0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    after_0:
    // 0x800562C4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800562C8: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800562CC: nop

    // 0x800562D0: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x800562D4: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800562D8: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800562DC: nop

    // 0x800562E0: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800562E4: nop

    // 0x800562E8: bc1f        L_80056318
    if (!c1cs) {
        // 0x800562EC: nop

            goto L_80056318;
    }
    // 0x800562EC: nop

    // 0x800562F0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800562F4: nop

    // 0x800562F8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800562FC: nop

    // 0x80056300: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80056304: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80056308: nop

    // 0x8005630C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80056310: b           L_80056338
    // 0x80056314: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
        goto L_80056338;
    // 0x80056314: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
L_80056318:
    // 0x80056318: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005631C: nop

    // 0x80056320: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80056324: nop

    // 0x80056328: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8005632C: nop

    // 0x80056330: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80056334: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
L_80056338:
    // 0x80056338: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005633C: nop

    // 0x80056340: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80056344: nop

    // 0x80056348: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8005634C: nop

    // 0x80056350: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80056354: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80056358: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005635C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80056360: nop

    // 0x80056364: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80056368: nop

    // 0x8005636C: bc1f        L_80056388
    if (!c1cs) {
        // 0x80056370: nop

            goto L_80056388;
    }
    // 0x80056370: nop

    // 0x80056374: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80056378: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005637C: nop

    // 0x80056380: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80056384: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
L_80056388:
    // 0x80056388: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005638C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80056390: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80056394: lw          $t2, 0x5C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X5C);
    // 0x80056398: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8005639C: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800563A0: nop

    // 0x800563A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800563A8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800563AC: nop

    // 0x800563B0: bc1f        L_800563C4
    if (!c1cs) {
        // 0x800563B4: nop

            goto L_800563C4;
    }
    // 0x800563B4: nop

    // 0x800563B8: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800563BC: b           L_800563E8
    // 0x800563C0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
        goto L_800563E8;
    // 0x800563C0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
L_800563C4:
    // 0x800563C4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800563C8: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800563CC: nop

    // 0x800563D0: lw          $t4, 0x5C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X5C);
    // 0x800563D4: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800563D8: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800563DC: nop

    // 0x800563E0: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800563E4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
L_800563E8:
    // 0x800563E8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800563EC: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x800563F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800563F4: bne         $t5, $at, L_80056430
    if (ctx->r13 != ctx->r1) {
        // 0x800563F8: nop

            goto L_80056430;
    }
    // 0x800563F8: nop

    // 0x800563FC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80056400: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x80056404: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056408: bne         $t6, $at, L_80056430
    if (ctx->r14 != ctx->r1) {
        // 0x8005640C: nop

            goto L_80056430;
    }
    // 0x8005640C: nop

    // 0x80056410: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80056414: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80056418: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005641C: lw          $t8, 0x5C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X5C);
    // 0x80056420: nop

    // 0x80056424: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80056428: b           L_80056580
    // 0x8005642C: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
        goto L_80056580;
    // 0x8005642C: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
L_80056430:
    // 0x80056430: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80056434: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80056438: nop

    // 0x8005643C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80056440: nop

    // 0x80056444: bc1f        L_80056558
    if (!c1cs) {
        // 0x80056448: nop

            goto L_80056558;
    }
    // 0x80056448: nop

    // 0x8005644C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80056450: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80056454: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80056458: lw          $t0, 0x5C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X5C);
    // 0x8005645C: nop

    // 0x80056460: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80056464: nop

    // 0x80056468: bne         $t1, $at, L_80056480
    if (ctx->r9 != ctx->r1) {
        // 0x8005646C: nop

            goto L_80056480;
    }
    // 0x8005646C: nop

    // 0x80056470: jal         0x8005A578
    // 0x80056474: nop

    func_8005A578(rdram, ctx);
        goto after_1;
    // 0x80056474: nop

    after_1:
    // 0x80056478: beq         $v0, $zero, L_80056558
    if (ctx->r2 == 0) {
        // 0x8005647C: nop

            goto L_80056558;
    }
    // 0x8005647C: nop

L_80056480:
    // 0x80056480: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80056484: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80056488: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8005648C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80056490: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80056494: nop

    // 0x80056498: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8005649C: nop

    // 0x800564A0: bc1f        L_800564C4
    if (!c1cs) {
        // 0x800564A4: nop

            goto L_800564C4;
    }
    // 0x800564A4: nop

    // 0x800564A8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800564AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800564B0: nop

    // 0x800564B4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800564B8: nop

    // 0x800564BC: bc1t        L_80056558
    if (c1cs) {
        // 0x800564C0: nop

            goto L_80056558;
    }
    // 0x800564C0: nop

L_800564C4:
    // 0x800564C4: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800564C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800564CC: nop

    // 0x800564D0: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800564D4: nop

    // 0x800564D8: bc1f        L_80056504
    if (!c1cs) {
        // 0x800564DC: nop

            goto L_80056504;
    }
    // 0x800564DC: nop

    // 0x800564E0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800564E4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800564E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800564EC: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800564F0: nop

    // 0x800564F4: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800564F8: nop

    // 0x800564FC: bc1t        L_80056544
    if (c1cs) {
        // 0x80056500: nop

            goto L_80056544;
    }
    // 0x80056500: nop

L_80056504:
    // 0x80056504: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056508: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005650C: nop

    // 0x80056510: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80056514: nop

    // 0x80056518: bc1f        L_80056558
    if (!c1cs) {
        // 0x8005651C: nop

            goto L_80056558;
    }
    // 0x8005651C: nop

    // 0x80056520: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80056524: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80056528: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005652C: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80056530: nop

    // 0x80056534: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80056538: nop

    // 0x8005653C: bc1f        L_80056558
    if (!c1cs) {
        // 0x80056540: nop

            goto L_80056558;
    }
    // 0x80056540: nop

L_80056544:
    // 0x80056544: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80056548: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005654C: nop

    // 0x80056550: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80056554: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
L_80056558:
    // 0x80056558: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005655C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80056560: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056564: lw          $t6, 0x5C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X5C);
    // 0x80056568: nop

    // 0x8005656C: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80056570: b           L_80056580
    // 0x80056574: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
        goto L_80056580;
    // 0x80056574: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80056578: b           L_80056580
    // 0x8005657C: nop

        goto L_80056580;
    // 0x8005657C: nop

L_80056580:
    // 0x80056580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80056588: jr          $ra
    // 0x8005658C: nop

    return;
    // 0x8005658C: nop

;}
RECOMP_FUNC void func_80056590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80056594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056598: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005659C: lhu         $a0, 0x20($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X20);
    // 0x800565A0: nop

    // 0x800565A4: andi        $t6, $a0, 0x1FFF
    ctx->r14 = ctx->r4 & 0X1FFF;
    // 0x800565A8: jal         0x800561E4
    // 0x800565AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800561E4(rdram, ctx);
        goto after_0;
    // 0x800565AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800565B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800565B4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800565B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800565BC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800565C0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800565C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800565C8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800565CC: lh          $t9, -0x2A1E($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2A1E);
    // 0x800565D0: nop

    // 0x800565D4: sh          $t9, 0x60($t0)
    MEM_H(0X60, ctx->r8) = ctx->r25;
    // 0x800565D8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800565DC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800565E0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800565E4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800565E8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800565EC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800565F0: lh          $t3, -0x2A1C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2A1C);
    // 0x800565F4: nop

    // 0x800565F8: sh          $t3, 0x62($t4)
    MEM_H(0X62, ctx->r12) = ctx->r11;
    // 0x800565FC: lh          $t5, 0x22($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X22);
    // 0x80056600: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056604: beq         $t5, $at, L_80056638
    if (ctx->r13 == ctx->r1) {
        // 0x80056608: nop

            goto L_80056638;
    }
    // 0x80056608: nop

    // 0x8005660C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056610: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80056614: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80056618: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005661C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80056620: bne         $t0, $zero, L_80056630
    if (ctx->r8 != 0) {
        // 0x80056624: andi        $t1, $t9, 0x400
        ctx->r9 = ctx->r25 & 0X400;
            goto L_80056630;
    }
    // 0x80056624: andi        $t1, $t9, 0x400
    ctx->r9 = ctx->r25 & 0X400;
    // 0x80056628: beq         $t1, $zero, L_80056638
    if (ctx->r9 == 0) {
        // 0x8005662C: nop

            goto L_80056638;
    }
    // 0x8005662C: nop

L_80056630:
    // 0x80056630: b           L_80056648
    // 0x80056634: sh          $zero, 0x64($t6)
    MEM_H(0X64, ctx->r14) = 0;
        goto L_80056648;
    // 0x80056634: sh          $zero, 0x64($t6)
    MEM_H(0X64, ctx->r14) = 0;
L_80056638:
    // 0x80056638: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005663C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80056640: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80056644: sh          $t7, 0x64($t2)
    MEM_H(0X64, ctx->r10) = ctx->r15;
L_80056648:
    // 0x80056648: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005664C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80056650: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80056654: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80056658: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005665C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80056660: lh          $t5, -0x2A1A($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2A1A);
    // 0x80056664: nop

    // 0x80056668: sh          $t5, 0x66($t8)
    MEM_H(0X66, ctx->r24) = ctx->r13;
    // 0x8005666C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80056670: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80056674: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80056678: lhu         $t0, 0x62($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X62);
    // 0x8005667C: nop

    // 0x80056680: bne         $t0, $at, L_800566D0
    if (ctx->r8 != ctx->r1) {
        // 0x80056684: nop

            goto L_800566D0;
    }
    // 0x80056684: nop

    // 0x80056688: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005668C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80056690: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80056694: lw          $t6, 0x5C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X5C);
    // 0x80056698: nop

    // 0x8005669C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800566A0: nop

    // 0x800566A4: beq         $t7, $at, L_800566C0
    if (ctx->r15 == ctx->r1) {
        // 0x800566A8: nop

            goto L_800566C0;
    }
    // 0x800566A8: nop

    // 0x800566AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800566B0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800566B4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800566B8: b           L_800566D0
    // 0x800566BC: sh          $t2, 0x62($t3)
    MEM_H(0X62, ctx->r11) = ctx->r10;
        goto L_800566D0;
    // 0x800566BC: sh          $t2, 0x62($t3)
    MEM_H(0X62, ctx->r11) = ctx->r10;
L_800566C0:
    // 0x800566C0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800566C4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800566C8: addiu       $t4, $zero, 0x15A
    ctx->r12 = ADD32(0, 0X15A);
    // 0x800566CC: sh          $t4, 0x60($t5)
    MEM_H(0X60, ctx->r13) = ctx->r12;
L_800566D0:
    // 0x800566D0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800566D4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800566D8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800566DC: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x800566E0: lhu         $t2, 0x60($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X60);
    // 0x800566E4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800566E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800566EC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800566F0: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x800566F4: lh          $t6, -0x28C0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X28C0);
    // 0x800566F8: addiu       $a1, $t8, 0x68
    ctx->r5 = ADD32(ctx->r24, 0X68);
    // 0x800566FC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80056700: addiu       $a2, $t8, 0x6A
    ctx->r6 = ADD32(ctx->r24, 0X6A);
    // 0x80056704: jal         0x800B3230
    // 0x80056708: or          $a3, $t7, $t2
    ctx->r7 = ctx->r15 | ctx->r10;
    func_800B3230(rdram, ctx);
        goto after_1;
    // 0x80056708: or          $a3, $t7, $t2
    ctx->r7 = ctx->r15 | ctx->r10;
    after_1:
    // 0x8005670C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80056710: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80056714: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80056718: lhu         $t4, 0x62($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X62);
    // 0x8005671C: nop

    // 0x80056720: bne         $t4, $at, L_800567AC
    if (ctx->r12 != ctx->r1) {
        // 0x80056724: nop

            goto L_800567AC;
    }
    // 0x80056724: nop

    // 0x80056728: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005672C: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80056730: nop

    // 0x80056734: lh          $t9, 0xA($t5)
    ctx->r25 = MEM_H(ctx->r13, 0XA);
    // 0x80056738: nop

    // 0x8005673C: slti        $at, $t9, 0x321
    ctx->r1 = SIGNED(ctx->r25) < 0X321 ? 1 : 0;
    // 0x80056740: bne         $at, $zero, L_800567AC
    if (ctx->r1 != 0) {
        // 0x80056744: nop

            goto L_800567AC;
    }
    // 0x80056744: nop

    // 0x80056748: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005674C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80056750: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056754: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x80056758: nop

    // 0x8005675C: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80056760: nop

    // 0x80056764: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x80056768: nop

            goto L_800567AC;
    }
    // 0x80056768: nop

    // 0x8005676C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80056770: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x80056774: nop

            goto L_800567AC;
    }
    // 0x80056774: nop

    // 0x80056778: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8005677C: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x80056780: nop

            goto L_800567AC;
    }
    // 0x80056780: nop

    // 0x80056784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80056788: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x8005678C: nop

            goto L_800567AC;
    }
    // 0x8005678C: nop

    // 0x80056790: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80056794: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x80056798: nop

            goto L_800567AC;
    }
    // 0x80056798: nop

    // 0x8005679C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800567A0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800567A4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800567A8: sh          $t8, 0x62($t7)
    MEM_H(0X62, ctx->r15) = ctx->r24;
L_800567AC:
    // 0x800567AC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800567B0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800567B4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800567B8: lhu         $t3, 0x66($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X66);
    // 0x800567BC: nop

    // 0x800567C0: beq         $t3, $at, L_800567D8
    if (ctx->r11 == ctx->r1) {
        // 0x800567C4: nop

            goto L_800567D8;
    }
    // 0x800567C4: nop

    // 0x800567C8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800567CC: nop

    // 0x800567D0: bgez        $t4, L_80056808
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800567D4: nop

            goto L_80056808;
    }
    // 0x800567D4: nop

L_800567D8:
    // 0x800567D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800567DC: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800567E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800567E4: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x800567E8: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x800567EC: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x800567F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800567F4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800567F8: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x800567FC: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80056800: b           L_80056830
    // 0x80056804: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_80056830;
    // 0x80056804: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_80056808:
    // 0x80056808: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005680C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80056810: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80056814: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80056818: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x8005681C: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x80056820: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x80056824: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x80056828: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8005682C: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_80056830:
    // 0x80056830: b           L_80056838
    // 0x80056834: nop

        goto L_80056838;
    // 0x80056834: nop

L_80056838:
    // 0x80056838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005683C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80056840: jr          $ra
    // 0x80056844: nop

    return;
    // 0x80056844: nop

;}
RECOMP_FUNC void func_80056848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005684C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056850: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80056854: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056858: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005685C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80056860: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80056864: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80056868: bne         $t0, $zero, L_80056890
    if (ctx->r8 != 0) {
        // 0x8005686C: andi        $t1, $t9, 0x8000
        ctx->r9 = ctx->r25 & 0X8000;
            goto L_80056890;
    }
    // 0x8005686C: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x80056870: bne         $t1, $zero, L_80056890
    if (ctx->r9 != 0) {
        // 0x80056874: nop

            goto L_80056890;
    }
    // 0x80056874: nop

    // 0x80056878: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005687C: nop

    // 0x80056880: bne         $t7, $zero, L_80056890
    if (ctx->r15 != 0) {
        // 0x80056884: nop

            goto L_80056890;
    }
    // 0x80056884: nop

    // 0x80056888: b           L_80056B64
    // 0x8005688C: nop

        goto L_80056B64;
    // 0x8005688C: nop

L_80056890:
    // 0x80056890: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80056894: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80056898: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005689C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800568A0: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800568A4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800568A8: bne         $t6, $zero, L_800568B8
    if (ctx->r14 != 0) {
        // 0x800568AC: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_800568B8;
    }
    // 0x800568AC: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800568B0: beq         $t7, $zero, L_80056B5C
    if (ctx->r15 == 0) {
        // 0x800568B4: nop

            goto L_80056B5C;
    }
    // 0x800568B4: nop

L_800568B8:
    // 0x800568B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800568BC: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x800568C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800568C4: jal         0x800B334C
    // 0x800568C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_0;
    // 0x800568C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x800568CC: andi        $t3, $v0, 0x2000
    ctx->r11 = ctx->r2 & 0X2000;
    // 0x800568D0: beq         $t3, $zero, L_80056B5C
    if (ctx->r11 == 0) {
        // 0x800568D4: nop

            goto L_80056B5C;
    }
    // 0x800568D4: nop

    // 0x800568D8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800568DC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800568E0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800568E4: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800568E8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800568EC: bne         $t2, $zero, L_800568FC
    if (ctx->r10 != 0) {
        // 0x800568F0: andi        $t3, $t1, 0x8
        ctx->r11 = ctx->r9 & 0X8;
            goto L_800568FC;
    }
    // 0x800568F0: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x800568F4: beq         $t3, $zero, L_80056918
    if (ctx->r11 == 0) {
        // 0x800568F8: nop

            goto L_80056918;
    }
    // 0x800568F8: nop

L_800568FC:
    // 0x800568FC: lh          $t9, 0x68($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X68);
    // 0x80056900: nop

    // 0x80056904: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80056908: nop

    // 0x8005690C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80056910: b           L_80056940
    // 0x80056914: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
        goto L_80056940;
    // 0x80056914: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_80056918:
    // 0x80056918: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005691C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80056920: nop

    // 0x80056924: lh          $t5, 0x68($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X68);
    // 0x80056928: nop

    // 0x8005692C: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80056930: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80056934: nop

    // 0x80056938: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005693C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_80056940:
    // 0x80056940: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80056944: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80056948: addiu       $at, $zero, 0x128
    ctx->r1 = ADD32(0, 0X128);
    // 0x8005694C: lh          $t0, 0x4A($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X4A);
    // 0x80056950: nop

    // 0x80056954: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x80056958: beq         $t1, $at, L_800569A8
    if (ctx->r9 == ctx->r1) {
        // 0x8005695C: nop

            goto L_800569A8;
    }
    // 0x8005695C: nop

    // 0x80056960: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80056964: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80056968: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005696C: lwc1        $f16, 0xC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80056970: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x80056974: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80056978: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8005697C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80056980: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80056984: nop

    // 0x80056988: lh          $t9, 0x6A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6A);
    // 0x8005698C: lwc1        $f6, 0x10($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80056990: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80056994: lw          $t4, 0x5C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X5C);
    // 0x80056998: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005699C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800569A0: b           L_800569CC
    // 0x800569A4: swc1        $f16, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f16.u32l;
        goto L_800569CC;
    // 0x800569A4: swc1        $f16, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f16.u32l;
L_800569A8:
    // 0x800569A8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800569AC: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800569B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800569B4: lw          $t6, 0x5C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X5C);
    // 0x800569B8: nop

    // 0x800569BC: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800569C0: nop

    // 0x800569C4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800569C8: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
L_800569CC:
    // 0x800569CC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800569D0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800569D4: nop

    // 0x800569D8: lhu         $t0, 0x62($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X62);
    // 0x800569DC: lhu         $t1, 0x64($t7)
    ctx->r9 = MEM_HU(ctx->r15, 0X64);
    // 0x800569E0: lw          $a0, 0x5C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X5C);
    // 0x800569E4: lhu         $a1, 0x60($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X60);
    // 0x800569E8: jal         0x80029538
    // 0x800569EC: or          $a2, $t0, $t1
    ctx->r6 = ctx->r8 | ctx->r9;
    func_80029538(rdram, ctx);
        goto after_1;
    // 0x800569EC: or          $a2, $t0, $t1
    ctx->r6 = ctx->r8 | ctx->r9;
    after_1:
    // 0x800569F0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800569F4: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800569F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800569FC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80056A00: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80056A04: and         $t4, $t8, $at
    ctx->r12 = ctx->r24 & ctx->r1;
    // 0x80056A08: lui         $at, 0xFFF7
    ctx->r1 = S32(0XFFF7 << 16);
    // 0x80056A0C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80056A10: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x80056A14: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80056A18: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80056A1C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80056A20: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80056A24: addiu       $at, $zero, 0x144
    ctx->r1 = ADD32(0, 0X144);
    // 0x80056A28: lhu         $t6, 0x60($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X60);
    // 0x80056A2C: nop

    // 0x80056A30: bne         $t6, $at, L_80056AEC
    if (ctx->r14 != ctx->r1) {
        // 0x80056A34: nop

            goto L_80056AEC;
    }
    // 0x80056A34: nop

    // 0x80056A38: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80056A3C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80056A40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056A44: lw          $t0, 0x5C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X5C);
    // 0x80056A48: nop

    // 0x80056A4C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80056A50: nop

    // 0x80056A54: beq         $t1, $at, L_80056A68
    if (ctx->r9 == ctx->r1) {
        // 0x80056A58: nop

            goto L_80056A68;
    }
    // 0x80056A58: nop

    // 0x80056A5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80056A60: bne         $t1, $at, L_80056AEC
    if (ctx->r9 != ctx->r1) {
        // 0x80056A64: nop

            goto L_80056AEC;
    }
    // 0x80056A64: nop

L_80056A68:
    // 0x80056A68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80056A6C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80056A70: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80056A74: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x80056A78: addiu       $t5, $t5, 0x1B18
    ctx->r13 = ADD32(ctx->r13, 0X1B18);
    // 0x80056A7C: lh          $t4, 0x0($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X0);
    // 0x80056A80: nop

    // 0x80056A84: addu        $t2, $t4, $t5
    ctx->r10 = ADD32(ctx->r12, ctx->r13);
    // 0x80056A88: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80056A8C: nop

    // 0x80056A90: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x80056A94: sb          $t6, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r14;
    // 0x80056A98: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80056A9C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80056AA0: nop

    // 0x80056AA4: lw          $t0, 0x5C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X5C);
    // 0x80056AA8: nop

    // 0x80056AAC: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80056AB0: nop

    // 0x80056AB4: addiu       $t8, $t1, 0x27
    ctx->r24 = ADD32(ctx->r9, 0X27);
    // 0x80056AB8: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80056ABC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80056AC0: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80056AC4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80056AC8: lw          $t4, 0x5C($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X5C);
    // 0x80056ACC: addiu       $t3, $t3, 0x1B18
    ctx->r11 = ADD32(ctx->r11, 0X1B18);
    // 0x80056AD0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80056AD4: nop

    // 0x80056AD8: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x80056ADC: lbu         $t2, 0x0($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X0);
    // 0x80056AE0: nop

    // 0x80056AE4: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x80056AE8: sb          $t7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r15;
L_80056AEC:
    // 0x80056AEC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80056AF0: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80056AF4: nop

    // 0x80056AF8: lhu         $t8, 0x66($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X66);
    // 0x80056AFC: nop

    // 0x80056B00: beq         $t8, $zero, L_80056B5C
    if (ctx->r24 == 0) {
        // 0x80056B04: nop

            goto L_80056B5C;
    }
    // 0x80056B04: nop

    // 0x80056B08: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80056B0C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80056B10: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80056B14: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80056B18: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80056B1C: bne         $t2, $zero, L_80056B5C
    if (ctx->r10 != 0) {
        // 0x80056B20: andi        $t3, $t5, 0x600
        ctx->r11 = ctx->r13 & 0X600;
            goto L_80056B5C;
    }
    // 0x80056B20: andi        $t3, $t5, 0x600
    ctx->r11 = ctx->r13 & 0X600;
    // 0x80056B24: bne         $t3, $zero, L_80056B5C
    if (ctx->r11 != 0) {
        // 0x80056B28: nop

            goto L_80056B5C;
    }
    // 0x80056B28: nop

    // 0x80056B2C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80056B30: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80056B34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056B38: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80056B3C: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80056B40: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80056B44: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80056B48: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x80056B4C: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80056B50: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80056B54: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80056B58: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_80056B5C:
    // 0x80056B5C: b           L_80056B64
    // 0x80056B60: nop

        goto L_80056B64;
    // 0x80056B60: nop

L_80056B64:
    // 0x80056B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056B68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80056B6C: jr          $ra
    // 0x80056B70: nop

    return;
    // 0x80056B70: nop

;}
RECOMP_FUNC void func_80056B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056B74: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80056B78: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80056B7C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056B80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80056B84: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x80056B88: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056B8C: nop

            goto L_80056BC8;
    }
    // 0x80056B8C: nop

    // 0x80056B90: addiu       $at, $zero, 0x79
    ctx->r1 = ADD32(0, 0X79);
    // 0x80056B94: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056B98: nop

            goto L_80056BC8;
    }
    // 0x80056B98: nop

    // 0x80056B9C: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
    // 0x80056BA0: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056BA4: nop

            goto L_80056BC8;
    }
    // 0x80056BA4: nop

    // 0x80056BA8: addiu       $at, $zero, 0x7B
    ctx->r1 = ADD32(0, 0X7B);
    // 0x80056BAC: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056BB0: nop

            goto L_80056BC8;
    }
    // 0x80056BB0: nop

    // 0x80056BB4: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x80056BB8: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056BBC: nop

            goto L_80056BC8;
    }
    // 0x80056BBC: nop

    // 0x80056BC0: b           L_80056BFC
    // 0x80056BC4: nop

        goto L_80056BFC;
    // 0x80056BC4: nop

L_80056BC8:
    // 0x80056BC8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056BCC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80056BD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056BD4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80056BD8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80056BDC: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80056BE0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80056BE4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80056BE8: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80056BEC: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80056BF0: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80056BF4: b           L_80056BFC
    // 0x80056BF8: nop

        goto L_80056BFC;
    // 0x80056BF8: nop

L_80056BFC:
    // 0x80056BFC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80056C00: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80056C04: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80056C08: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x80056C0C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80056C10: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80056C14: bne         $t4, $zero, L_80056C24
    if (ctx->r12 != 0) {
        // 0x80056C18: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_80056C24;
    }
    // 0x80056C18: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80056C1C: beq         $t5, $zero, L_80056C50
    if (ctx->r13 == 0) {
        // 0x80056C20: nop

            goto L_80056C50;
    }
    // 0x80056C20: nop

L_80056C24:
    // 0x80056C24: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80056C28: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80056C2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056C30: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80056C34: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80056C38: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x80056C3C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80056C40: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80056C44: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x80056C48: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80056C4C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_80056C50:
    // 0x80056C50: b           L_80056C58
    // 0x80056C54: nop

        goto L_80056C58;
    // 0x80056C54: nop

L_80056C58:
    // 0x80056C58: jr          $ra
    // 0x80056C5C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80056C5C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80056C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056C60: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056C64: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80056C68: addiu       $t6, $t6, 0x2C4C
    ctx->r14 = ADD32(ctx->r14, 0X2C4C);
    // 0x80056C6C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80056C70: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80056C74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056C78: beq         $t7, $at, L_80056D10
    if (ctx->r15 == ctx->r1) {
        // 0x80056C7C: nop

            goto L_80056D10;
    }
    // 0x80056C7C: nop

L_80056C80:
    // 0x80056C80: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x80056C84: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80056C88: addiu       $t0, $t0, 0x2C4C
    ctx->r8 = ADD32(ctx->r8, 0X2C4C);
    // 0x80056C8C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80056C90: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80056C94: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80056C98: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80056C9C: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80056CA0: nop

    // 0x80056CA4: bne         $t2, $t3, L_80056CE4
    if (ctx->r10 != ctx->r11) {
        // 0x80056CA8: nop

            goto L_80056CE4;
    }
    // 0x80056CA8: nop

    // 0x80056CAC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80056CB0: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80056CB4: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80056CB8: nop

    // 0x80056CBC: bne         $t4, $t5, L_80056CE4
    if (ctx->r12 != ctx->r13) {
        // 0x80056CC0: nop

            goto L_80056CE4;
    }
    // 0x80056CC0: nop

    // 0x80056CC4: lh          $t6, 0x4($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X4);
    // 0x80056CC8: lbu         $t7, 0x16($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X16);
    // 0x80056CCC: nop

    // 0x80056CD0: bne         $t6, $t7, L_80056CE4
    if (ctx->r14 != ctx->r15) {
        // 0x80056CD4: nop

            goto L_80056CE4;
    }
    // 0x80056CD4: nop

    // 0x80056CD8: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
    // 0x80056CDC: b           L_80056D20
    // 0x80056CE0: nop

        goto L_80056D20;
    // 0x80056CE0: nop

L_80056CE4:
    // 0x80056CE4: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x80056CE8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80056CEC: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x80056CF0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x80056CF4: sra         $t2, $t0, 16
    ctx->r10 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80056CF8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80056CFC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80056D00: lh          $t4, 0x2C4C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2C4C);
    // 0x80056D04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056D08: bne         $t4, $at, L_80056C80
    if (ctx->r12 != ctx->r1) {
        // 0x80056D0C: sh          $t9, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r25;
            goto L_80056C80;
    }
    // 0x80056D0C: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
L_80056D10:
    // 0x80056D10: b           L_80056D20
    // 0x80056D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80056D20;
    // 0x80056D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056D18: b           L_80056D20
    // 0x80056D1C: nop

        goto L_80056D20;
    // 0x80056D1C: nop

L_80056D20:
    // 0x80056D20: jr          $ra
    // 0x80056D24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80056D24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80056D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056D28: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80056D2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80056D30: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056D34: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80056D38: addiu       $t6, $t6, 0x2C4C
    ctx->r14 = ADD32(ctx->r14, 0X2C4C);
    // 0x80056D3C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80056D40: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80056D44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056D48: beq         $t7, $at, L_80056DDC
    if (ctx->r15 == ctx->r1) {
        // 0x80056D4C: nop

            goto L_80056DDC;
    }
    // 0x80056D4C: nop

L_80056D50:
    // 0x80056D50: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x80056D54: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80056D58: addiu       $t0, $t0, 0x2C4C
    ctx->r8 = ADD32(ctx->r8, 0X2C4C);
    // 0x80056D5C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80056D60: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80056D64: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80056D68: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80056D6C: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80056D70: nop

    // 0x80056D74: bne         $t2, $t3, L_80056DB0
    if (ctx->r10 != ctx->r11) {
        // 0x80056D78: nop

            goto L_80056DB0;
    }
    // 0x80056D78: nop

    // 0x80056D7C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80056D80: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80056D84: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80056D88: nop

    // 0x80056D8C: bne         $t4, $t5, L_80056DB0
    if (ctx->r12 != ctx->r13) {
        // 0x80056D90: nop

            goto L_80056DB0;
    }
    // 0x80056D90: nop

    // 0x80056D94: lh          $t6, 0x4($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X4);
    // 0x80056D98: nop

    // 0x80056D9C: bne         $t6, $a0, L_80056DB0
    if (ctx->r14 != ctx->r4) {
        // 0x80056DA0: nop

            goto L_80056DB0;
    }
    // 0x80056DA0: nop

    // 0x80056DA4: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
    // 0x80056DA8: b           L_80056DEC
    // 0x80056DAC: nop

        goto L_80056DEC;
    // 0x80056DAC: nop

L_80056DB0:
    // 0x80056DB0: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x80056DB4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80056DB8: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x80056DBC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80056DC0: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80056DC4: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80056DC8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80056DCC: lh          $t3, 0x2C4C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2C4C);
    // 0x80056DD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056DD4: bne         $t3, $at, L_80056D50
    if (ctx->r11 != ctx->r1) {
        // 0x80056DD8: sh          $t8, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r24;
            goto L_80056D50;
    }
    // 0x80056DD8: sh          $t8, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r24;
L_80056DDC:
    // 0x80056DDC: b           L_80056DEC
    // 0x80056DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80056DEC;
    // 0x80056DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056DE4: b           L_80056DEC
    // 0x80056DE8: nop

        goto L_80056DEC;
    // 0x80056DE8: nop

L_80056DEC:
    // 0x80056DEC: jr          $ra
    // 0x80056DF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80056DF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80056DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056DF4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056DF8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80056DFC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80056E00: addiu       $t6, $t6, 0x2C4C
    ctx->r14 = ADD32(ctx->r14, 0X2C4C);
    // 0x80056E04: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80056E08: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80056E0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056E10: beq         $t7, $at, L_80056E70
    if (ctx->r15 == ctx->r1) {
        // 0x80056E14: nop

            goto L_80056E70;
    }
    // 0x80056E14: nop

L_80056E18:
    // 0x80056E18: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x80056E1C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80056E20: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80056E24: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80056E28: lh          $t0, 0x2C52($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X2C52);
    // 0x80056E2C: nop

    // 0x80056E30: bne         $t0, $a0, L_80056E44
    if (ctx->r8 != ctx->r4) {
        // 0x80056E34: nop

            goto L_80056E44;
    }
    // 0x80056E34: nop

    // 0x80056E38: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
    // 0x80056E3C: b           L_80056E80
    // 0x80056E40: nop

        goto L_80056E80;
    // 0x80056E40: nop

L_80056E44:
    // 0x80056E44: lh          $t1, 0x6($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6);
    // 0x80056E48: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80056E4C: addiu       $t2, $t1, 0xA
    ctx->r10 = ADD32(ctx->r9, 0XA);
    // 0x80056E50: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80056E54: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80056E58: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80056E5C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80056E60: lh          $t6, 0x2C4C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2C4C);
    // 0x80056E64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056E68: bne         $t6, $at, L_80056E18
    if (ctx->r14 != ctx->r1) {
        // 0x80056E6C: sh          $t2, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r10;
            goto L_80056E18;
    }
    // 0x80056E6C: sh          $t2, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r10;
L_80056E70:
    // 0x80056E70: b           L_80056E80
    // 0x80056E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80056E80;
    // 0x80056E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056E78: b           L_80056E80
    // 0x80056E7C: nop

        goto L_80056E80;
    // 0x80056E7C: nop

L_80056E80:
    // 0x80056E80: jr          $ra
    // 0x80056E84: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80056E84: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80056E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056E88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80056E8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80056E90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80056E94: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80056E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80056E9C: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80056EA0: nop

    // 0x80056EA4: andi        $t7, $t6, 0xC000
    ctx->r15 = ctx->r14 & 0XC000;
    // 0x80056EA8: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x80056EAC: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x80056EB0: nop

    // 0x80056EB4: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x80056EB8: sh          $t9, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r25;
    // 0x80056EBC: jal         0x800560A4
    // 0x80056EC0: nop

    func_800560A4(rdram, ctx);
        goto after_0;
    // 0x80056EC0: nop

    after_0:
    // 0x80056EC4: bne         $v0, $zero, L_80056F10
    if (ctx->r2 != 0) {
        // 0x80056EC8: nop

            goto L_80056F10;
    }
    // 0x80056EC8: nop

    // 0x80056ECC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80056ED0: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80056ED4: nop

    // 0x80056ED8: lh          $t1, 0x2E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2E);
    // 0x80056EDC: nop

    // 0x80056EE0: slti        $at, $t1, 0x384
    ctx->r1 = SIGNED(ctx->r9) < 0X384 ? 1 : 0;
    // 0x80056EE4: beq         $at, $zero, L_80056F10
    if (ctx->r1 == 0) {
        // 0x80056EE8: nop

            goto L_80056F10;
    }
    // 0x80056EE8: nop

    // 0x80056EEC: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x80056EF0: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80056EF4: nop

    // 0x80056EF8: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x80056EFC: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80056F00: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80056F04: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80056F08: b           L_800574BC
    // 0x80056F0C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x80056F0C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80056F10:
    // 0x80056F10: jal         0x800526C0
    // 0x80056F14: nop

    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x80056F14: nop

    after_1:
    // 0x80056F18: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80056F1C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80056F20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056F24: bne         $t6, $at, L_80056F44
    if (ctx->r14 != ctx->r1) {
        // 0x80056F28: nop

            goto L_80056F44;
    }
    // 0x80056F28: nop

    // 0x80056F2C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80056F30: nop

    // 0x80056F34: beq         $t7, $zero, L_80056F44
    if (ctx->r15 == 0) {
        // 0x80056F38: nop

            goto L_80056F44;
    }
    // 0x80056F38: nop

    // 0x80056F3C: b           L_800574BC
    // 0x80056F40: addiu       $v0, $zero, 0xAF
    ctx->r2 = ADD32(0, 0XAF);
        goto L_800574BC;
    // 0x80056F40: addiu       $v0, $zero, 0xAF
    ctx->r2 = ADD32(0, 0XAF);
L_80056F44:
    // 0x80056F44: jal         0x80061D20
    // 0x80056F48: nop

    func_80061D20(rdram, ctx);
        goto after_2;
    // 0x80056F48: nop

    after_2:
    // 0x80056F4C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80056F50: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80056F54: nop

    // 0x80056F58: beq         $t8, $zero, L_80056F6C
    if (ctx->r24 == 0) {
        // 0x80056F5C: nop

            goto L_80056F6C;
    }
    // 0x80056F5C: nop

    // 0x80056F60: addiu       $t9, $t8, -0x17
    ctx->r25 = ADD32(ctx->r24, -0X17);
    // 0x80056F64: b           L_80056F70
    // 0x80056F68: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
        goto L_80056F70;
    // 0x80056F68: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_80056F6C:
    // 0x80056F6C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80056F70:
    // 0x80056F70: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80056F74: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80056F78: nop

    // 0x80056F7C: lh          $t1, 0x2E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2E);
    // 0x80056F80: nop

    // 0x80056F84: slti        $at, $t1, 0x384
    ctx->r1 = SIGNED(ctx->r9) < 0X384 ? 1 : 0;
    // 0x80056F88: bne         $at, $zero, L_80056F98
    if (ctx->r1 != 0) {
        // 0x80056F8C: nop

            goto L_80056F98;
    }
    // 0x80056F8C: nop

    // 0x80056F90: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80056F94: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_80056F98:
    // 0x80056F98: lh          $s0, 0x32($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X32);
    // 0x80056F9C: nop

    // 0x80056FA0: slti        $at, $s0, 0xA1
    ctx->r1 = SIGNED(ctx->r16) < 0XA1 ? 1 : 0;
    // 0x80056FA4: bne         $at, $zero, L_80056FCC
    if (ctx->r1 != 0) {
        // 0x80056FA8: nop

            goto L_80056FCC;
    }
    // 0x80056FA8: nop

    // 0x80056FAC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80056FB0: beq         $s0, $at, L_80057230
    if (ctx->r16 == ctx->r1) {
        // 0x80056FB4: nop

            goto L_80057230;
    }
    // 0x80056FB4: nop

    // 0x80056FB8: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x80056FBC: beq         $s0, $at, L_800573D0
    if (ctx->r16 == ctx->r1) {
        // 0x80056FC0: nop

            goto L_800573D0;
    }
    // 0x80056FC0: nop

    // 0x80056FC4: b           L_8005746C
    // 0x80056FC8: nop

        goto L_8005746C;
    // 0x80056FC8: nop

L_80056FCC:
    // 0x80056FCC: slti        $at, $s0, 0x24
    ctx->r1 = SIGNED(ctx->r16) < 0X24 ? 1 : 0;
    // 0x80056FD0: bne         $at, $zero, L_80057004
    if (ctx->r1 != 0) {
        // 0x80056FD4: nop

            goto L_80057004;
    }
    // 0x80056FD4: nop

    // 0x80056FD8: addiu       $t3, $s0, -0x45
    ctx->r11 = ADD32(ctx->r16, -0X45);
    // 0x80056FDC: sltiu       $at, $t3, 0x5C
    ctx->r1 = ctx->r11 < 0X5C ? 1 : 0;
    // 0x80056FE0: beq         $at, $zero, L_8005746C
    if (ctx->r1 == 0) {
        // 0x80056FE4: nop

            goto L_8005746C;
    }
    // 0x80056FE4: nop

    // 0x80056FE8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80056FEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80056FF0: addu        $at, $at, $t3
    gpr jr_addend_80056FFC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80056FF4: lw          $t3, -0x10A0($at)
    ctx->r11 = ADD32(ctx->r1, -0X10A0);
    // 0x80056FF8: nop

    // 0x80056FFC: jr          $t3
    // 0x80057000: nop

    switch (jr_addend_80056FFC >> 2) {
        case 0: goto L_80057264; break;
        case 1: goto L_8005746C; break;
        case 2: goto L_8005746C; break;
        case 3: goto L_8005746C; break;
        case 4: goto L_80057298; break;
        case 5: goto L_8005746C; break;
        case 6: goto L_8005746C; break;
        case 7: goto L_8005746C; break;
        case 8: goto L_800572CC; break;
        case 9: goto L_8005746C; break;
        case 10: goto L_8005746C; break;
        case 11: goto L_8005746C; break;
        case 12: goto L_80057300; break;
        case 13: goto L_8005746C; break;
        case 14: goto L_8005746C; break;
        case 15: goto L_8005746C; break;
        case 16: goto L_80057334; break;
        case 17: goto L_8005746C; break;
        case 18: goto L_8005746C; break;
        case 19: goto L_8005746C; break;
        case 20: goto L_8005746C; break;
        case 21: goto L_80057368; break;
        case 22: goto L_8005746C; break;
        case 23: goto L_8005746C; break;
        case 24: goto L_8005746C; break;
        case 25: goto L_8005739C; break;
        case 26: goto L_8005746C; break;
        case 27: goto L_8005746C; break;
        case 28: goto L_8005746C; break;
        case 29: goto L_8005746C; break;
        case 30: goto L_8005746C; break;
        case 31: goto L_8005746C; break;
        case 32: goto L_80057194; break;
        case 33: goto L_8005746C; break;
        case 34: goto L_8005746C; break;
        case 35: goto L_8005746C; break;
        case 36: goto L_80057160; break;
        case 37: goto L_8005746C; break;
        case 38: goto L_8005746C; break;
        case 39: goto L_8005746C; break;
        case 40: goto L_8005746C; break;
        case 41: goto L_8005746C; break;
        case 42: goto L_8005746C; break;
        case 43: goto L_8005746C; break;
        case 44: goto L_80057024; break;
        case 45: goto L_8005746C; break;
        case 46: goto L_8005746C; break;
        case 47: goto L_8005746C; break;
        case 48: goto L_8005746C; break;
        case 49: goto L_8005746C; break;
        case 50: goto L_8005746C; break;
        case 51: goto L_8005746C; break;
        case 52: goto L_8005746C; break;
        case 53: goto L_8005746C; break;
        case 54: goto L_8005746C; break;
        case 55: goto L_8005746C; break;
        case 56: goto L_8005746C; break;
        case 57: goto L_8005746C; break;
        case 58: goto L_8005746C; break;
        case 59: goto L_8005746C; break;
        case 60: goto L_80057404; break;
        case 61: goto L_8005746C; break;
        case 62: goto L_8005746C; break;
        case 63: goto L_8005746C; break;
        case 64: goto L_8005746C; break;
        case 65: goto L_8005746C; break;
        case 66: goto L_8005746C; break;
        case 67: goto L_8005746C; break;
        case 68: goto L_8005746C; break;
        case 69: goto L_8005746C; break;
        case 70: goto L_8005746C; break;
        case 71: goto L_8005746C; break;
        case 72: goto L_8005746C; break;
        case 73: goto L_8005746C; break;
        case 74: goto L_80057438; break;
        case 75: goto L_8005746C; break;
        case 76: goto L_8005746C; break;
        case 77: goto L_8005746C; break;
        case 78: goto L_8005746C; break;
        case 79: goto L_8005746C; break;
        case 80: goto L_8005746C; break;
        case 81: goto L_8005746C; break;
        case 82: goto L_8005746C; break;
        case 83: goto L_8005746C; break;
        case 84: goto L_8005746C; break;
        case 85: goto L_8005746C; break;
        case 86: goto L_800571C8; break;
        case 87: goto L_8005746C; break;
        case 88: goto L_8005746C; break;
        case 89: goto L_8005746C; break;
        case 90: goto L_8005746C; break;
        case 91: goto L_800571FC; break;
        default: switch_error(__func__, 0x80056FFC, 0x800EEF60);
    }
    // 0x80057000: nop

L_80057004:
    // 0x80057004: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80057008: beq         $s0, $at, L_800570C4
    if (ctx->r16 == ctx->r1) {
        // 0x8005700C: nop

            goto L_800570C4;
    }
    // 0x8005700C: nop

    // 0x80057010: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80057014: beq         $s0, $at, L_80057090
    if (ctx->r16 == ctx->r1) {
        // 0x80057018: nop

            goto L_80057090;
    }
    // 0x80057018: nop

    // 0x8005701C: b           L_8005746C
    // 0x80057020: nop

        goto L_8005746C;
    // 0x80057020: nop

L_80057024:
    // 0x80057024: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80057028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005702C: beq         $s0, $at, L_80057048
    if (ctx->r16 == ctx->r1) {
        // 0x80057030: nop

            goto L_80057048;
    }
    // 0x80057030: nop

    // 0x80057034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80057038: beq         $s0, $at, L_80057050
    if (ctx->r16 == ctx->r1) {
        // 0x8005703C: nop

            goto L_80057050;
    }
    // 0x8005703C: nop

    // 0x80057040: b           L_80057058
    // 0x80057044: nop

        goto L_80057058;
    // 0x80057044: nop

L_80057048:
    // 0x80057048: b           L_800574BC
    // 0x8005704C: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
        goto L_800574BC;
    // 0x8005704C: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
L_80057050:
    // 0x80057050: b           L_800574BC
    // 0x80057054: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
        goto L_800574BC;
    // 0x80057054: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
L_80057058:
    // 0x80057058: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8005705C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80057060: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80057064: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80057068: lh          $v0, -0x2794($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2794);
    // 0x8005706C: b           L_800574BC
    // 0x80057070: nop

        goto L_800574BC;
    // 0x80057070: nop

    // 0x80057074: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80057078: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005707C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80057080: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80057084: lh          $v0, -0x2794($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2794);
    // 0x80057088: b           L_800574BC
    // 0x8005708C: nop

        goto L_800574BC;
    // 0x8005708C: nop

L_80057090:
    // 0x80057090: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80057094: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80057098: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005709C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800570A0: lh          $t0, -0x278A($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X278A);
    // 0x800570A4: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800570A8: nop

    // 0x800570AC: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800570B0: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800570B4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800570B8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800570BC: b           L_800574BC
    // 0x800570C0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x800570C0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800570C4:
    // 0x800570C4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800570C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800570CC: beq         $s0, $at, L_800570E8
    if (ctx->r16 == ctx->r1) {
        // 0x800570D0: nop

            goto L_800570E8;
    }
    // 0x800570D0: nop

    // 0x800570D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800570D8: beq         $s0, $at, L_800570F0
    if (ctx->r16 == ctx->r1) {
        // 0x800570DC: nop

            goto L_800570F0;
    }
    // 0x800570DC: nop

    // 0x800570E0: b           L_800570F8
    // 0x800570E4: nop

        goto L_800570F8;
    // 0x800570E4: nop

L_800570E8:
    // 0x800570E8: b           L_800574BC
    // 0x800570EC: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
        goto L_800574BC;
    // 0x800570EC: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
L_800570F0:
    // 0x800570F0: b           L_800574BC
    // 0x800570F4: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
        goto L_800574BC;
    // 0x800570F4: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
L_800570F8:
    // 0x800570F8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800570FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80057100: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80057104: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80057108: lh          $t6, -0x2780($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2780);
    // 0x8005710C: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80057110: nop

    // 0x80057114: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x80057118: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8005711C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80057120: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057124: b           L_800574BC
    // 0x80057128: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x80057128: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8005712C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80057130: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80057134: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80057138: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005713C: lh          $t2, -0x2780($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X2780);
    // 0x80057140: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80057144: nop

    // 0x80057148: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x8005714C: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80057150: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80057154: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057158: b           L_800574BC
    // 0x8005715C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x8005715C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80057160:
    // 0x80057160: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80057164: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80057168: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8005716C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80057170: lh          $t8, -0x2776($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2776);
    // 0x80057174: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80057178: nop

    // 0x8005717C: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    // 0x80057180: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80057184: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80057188: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005718C: b           L_800574BC
    // 0x80057190: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800574BC;
    // 0x80057190: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80057194:
    // 0x80057194: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80057198: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8005719C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800571A0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800571A4: lh          $t4, -0x276C($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X276C);
    // 0x800571A8: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x800571AC: nop

    // 0x800571B0: or          $v0, $t4, $t5
    ctx->r2 = ctx->r12 | ctx->r13;
    // 0x800571B4: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800571B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800571BC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800571C0: b           L_800574BC
    // 0x800571C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800574BC;
    // 0x800571C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800571C8:
    // 0x800571C8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800571CC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800571D0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800571D4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800571D8: lh          $t0, -0x2762($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2762);
    // 0x800571DC: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800571E0: nop

    // 0x800571E4: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800571E8: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800571EC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800571F0: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800571F4: b           L_800574BC
    // 0x800571F8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x800571F8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800571FC:
    // 0x800571FC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80057200: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80057204: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80057208: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005720C: lh          $t6, -0x2758($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2758);
    // 0x80057210: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80057214: nop

    // 0x80057218: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x8005721C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057220: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80057224: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057228: b           L_800574BC
    // 0x8005722C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x8005722C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80057230:
    // 0x80057230: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80057234: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80057238: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8005723C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80057240: lh          $t2, -0x274E($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X274E);
    // 0x80057244: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80057248: nop

    // 0x8005724C: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x80057250: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80057254: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80057258: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005725C: b           L_800574BC
    // 0x80057260: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x80057260: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80057264:
    // 0x80057264: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80057268: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005726C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80057270: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80057274: lh          $t8, -0x2744($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2744);
    // 0x80057278: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8005727C: nop

    // 0x80057280: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    // 0x80057284: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80057288: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8005728C: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057290: b           L_800574BC
    // 0x80057294: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800574BC;
    // 0x80057294: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80057298:
    // 0x80057298: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005729C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800572A0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800572A4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800572A8: lh          $t4, -0x273A($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X273A);
    // 0x800572AC: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x800572B0: nop

    // 0x800572B4: or          $v0, $t4, $t5
    ctx->r2 = ctx->r12 | ctx->r13;
    // 0x800572B8: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800572BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800572C0: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800572C4: b           L_800574BC
    // 0x800572C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800574BC;
    // 0x800572C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800572CC:
    // 0x800572CC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800572D0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800572D4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800572D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800572DC: lh          $t0, -0x2730($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2730);
    // 0x800572E0: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800572E4: nop

    // 0x800572E8: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800572EC: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800572F0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800572F4: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800572F8: b           L_800574BC
    // 0x800572FC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x800572FC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80057300:
    // 0x80057300: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80057304: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80057308: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8005730C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80057310: lh          $t6, -0x2726($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2726);
    // 0x80057314: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80057318: nop

    // 0x8005731C: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x80057320: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057324: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80057328: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005732C: b           L_800574BC
    // 0x80057330: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x80057330: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80057334:
    // 0x80057334: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80057338: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8005733C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80057340: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80057344: lh          $t2, -0x271C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X271C);
    // 0x80057348: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8005734C: nop

    // 0x80057350: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x80057354: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80057358: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8005735C: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057360: b           L_800574BC
    // 0x80057364: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x80057364: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80057368:
    // 0x80057368: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005736C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80057370: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80057374: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80057378: lh          $t8, -0x2712($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2712);
    // 0x8005737C: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80057380: nop

    // 0x80057384: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    // 0x80057388: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8005738C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80057390: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057394: b           L_800574BC
    // 0x80057398: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800574BC;
    // 0x80057398: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8005739C:
    // 0x8005739C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800573A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800573A4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800573A8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800573AC: lh          $t4, -0x2708($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X2708);
    // 0x800573B0: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x800573B4: nop

    // 0x800573B8: or          $v0, $t4, $t5
    ctx->r2 = ctx->r12 | ctx->r13;
    // 0x800573BC: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800573C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800573C4: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800573C8: b           L_800574BC
    // 0x800573CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800574BC;
    // 0x800573CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800573D0:
    // 0x800573D0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800573D4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800573D8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800573DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800573E0: lh          $t0, -0x26FE($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X26FE);
    // 0x800573E4: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800573E8: nop

    // 0x800573EC: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800573F0: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800573F4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800573F8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800573FC: b           L_800574BC
    // 0x80057400: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x80057400: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80057404:
    // 0x80057404: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80057408: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005740C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80057410: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80057414: lh          $t6, -0x26F4($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26F4);
    // 0x80057418: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x8005741C: nop

    // 0x80057420: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x80057424: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057428: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8005742C: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057430: b           L_800574BC
    // 0x80057434: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x80057434: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80057438:
    // 0x80057438: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005743C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80057440: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80057444: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80057448: lh          $t2, -0x26EA($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X26EA);
    // 0x8005744C: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80057450: nop

    // 0x80057454: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x80057458: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8005745C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80057460: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057464: b           L_800574BC
    // 0x80057468: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x80057468: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8005746C:
    // 0x8005746C: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x80057470: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x80057474: nop

    // 0x80057478: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x8005747C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057480: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80057484: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057488: b           L_800574BC
    // 0x8005748C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x8005748C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80057490: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x80057494: lh          $t1, 0x32($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X32);
    // 0x80057498: nop

    // 0x8005749C: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800574A0: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800574A4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800574A8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800574AC: b           L_800574BC
    // 0x800574B0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x800574B0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800574B4: b           L_800574BC
    // 0x800574B8: nop

        goto L_800574BC;
    // 0x800574B8: nop

L_800574BC:
    // 0x800574BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800574C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800574C4: jr          $ra
    // 0x800574C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800574C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800574CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800574CC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800574D0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800574D4: addiu       $t6, $a0, -0x104
    ctx->r14 = ADD32(ctx->r4, -0X104);
    // 0x800574D8: sltiu       $at, $t6, 0xE
    ctx->r1 = ctx->r14 < 0XE ? 1 : 0;
    // 0x800574DC: beq         $at, $zero, L_80057520
    if (ctx->r1 == 0) {
        // 0x800574E0: nop

            goto L_80057520;
    }
    // 0x800574E0: nop

    // 0x800574E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800574E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800574EC: addu        $at, $at, $t6
    gpr jr_addend_800574F8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800574F0: lw          $t6, -0xF30($at)
    ctx->r14 = ADD32(ctx->r1, -0XF30);
    // 0x800574F4: nop

    // 0x800574F8: jr          $t6
    // 0x800574FC: nop

    switch (jr_addend_800574F8 >> 2) {
        case 0: goto L_80057500; break;
        case 1: goto L_80057508; break;
        case 2: goto L_80057500; break;
        case 3: goto L_80057518; break;
        case 4: goto L_80057510; break;
        case 5: goto L_80057518; break;
        case 6: goto L_80057508; break;
        case 7: goto L_80057510; break;
        case 8: goto L_80057510; break;
        case 9: goto L_80057518; break;
        case 10: goto L_80057518; break;
        case 11: goto L_80057500; break;
        case 12: goto L_80057508; break;
        case 13: goto L_80057500; break;
        default: switch_error(__func__, 0x800574F8, 0x800EF0D0);
    }
    // 0x800574FC: nop

L_80057500:
    // 0x80057500: jr          $ra
    // 0x80057504: addiu       $v0, $zero, 0x69
    ctx->r2 = ADD32(0, 0X69);
    return;
    // 0x80057504: addiu       $v0, $zero, 0x69
    ctx->r2 = ADD32(0, 0X69);
L_80057508:
    // 0x80057508: jr          $ra
    // 0x8005750C: addiu       $v0, $zero, 0x6A
    ctx->r2 = ADD32(0, 0X6A);
    return;
    // 0x8005750C: addiu       $v0, $zero, 0x6A
    ctx->r2 = ADD32(0, 0X6A);
L_80057510:
    // 0x80057510: jr          $ra
    // 0x80057514: addiu       $v0, $zero, 0x6B
    ctx->r2 = ADD32(0, 0X6B);
    return;
    // 0x80057514: addiu       $v0, $zero, 0x6B
    ctx->r2 = ADD32(0, 0X6B);
L_80057518:
    // 0x80057518: jr          $ra
    // 0x8005751C: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    return;
    // 0x8005751C: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
L_80057520:
    // 0x80057520: jr          $ra
    // 0x80057524: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80057524: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80057528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057528: jr          $ra
    // 0x8005752C: nop

    return;
    // 0x8005752C: nop

    // 0x80057530: jr          $ra
    // 0x80057534: nop

    return;
    // 0x80057534: nop

;}
RECOMP_FUNC void func_80057538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057538: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005753C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80057540: lh          $t6, 0x1B48($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1B48);
    // 0x80057544: nop

    // 0x80057548: bne         $t6, $zero, L_80057558
    if (ctx->r14 != 0) {
        // 0x8005754C: nop

            goto L_80057558;
    }
    // 0x8005754C: nop

    // 0x80057550: b           L_8005770C
    // 0x80057554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005770C;
    // 0x80057554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057558:
    // 0x80057558: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005755C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80057560: lw          $t8, 0x306C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X306C);
    // 0x80057564: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x80057568: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8005756C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80057570: blez        $t7, L_80057644
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80057574: sw          $t7, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r15;
            goto L_80057644;
    }
    // 0x80057574: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80057578:
    // 0x80057578: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005757C: nop

    // 0x80057580: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x80057584: nop

    // 0x80057588: bne         $t0, $zero, L_8005761C
    if (ctx->r8 != 0) {
        // 0x8005758C: nop

            goto L_8005761C;
    }
    // 0x8005758C: nop

    // 0x80057590: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x80057594: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80057598: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x8005759C: nop

            goto L_8005761C;
    }
    // 0x8005759C: nop

    // 0x800575A0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800575A4: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575A8: nop

            goto L_8005761C;
    }
    // 0x800575A8: nop

    // 0x800575AC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800575B0: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575B4: nop

            goto L_8005761C;
    }
    // 0x800575B4: nop

    // 0x800575B8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800575BC: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575C0: nop

            goto L_8005761C;
    }
    // 0x800575C0: nop

    // 0x800575C4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800575C8: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575CC: nop

            goto L_8005761C;
    }
    // 0x800575CC: nop

    // 0x800575D0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800575D4: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575D8: nop

            goto L_8005761C;
    }
    // 0x800575D8: nop

    // 0x800575DC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800575E0: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575E4: nop

            goto L_8005761C;
    }
    // 0x800575E4: nop

    // 0x800575E8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x800575EC: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575F0: nop

            goto L_8005761C;
    }
    // 0x800575F0: nop

    // 0x800575F4: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800575F8: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575FC: nop

            goto L_8005761C;
    }
    // 0x800575FC: nop

    // 0x80057600: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80057604: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x80057608: nop

            goto L_8005761C;
    }
    // 0x80057608: nop

    // 0x8005760C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80057610: nop

    // 0x80057614: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80057618: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
L_8005761C:
    // 0x8005761C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80057620: nop

    // 0x80057624: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x80057628: nop

    // 0x8005762C: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80057630: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80057634: nop

    // 0x80057638: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8005763C: bgtz        $t8, L_80057578
    if (SIGNED(ctx->r24) > 0) {
        // 0x80057640: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_80057578;
    }
    // 0x80057640: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_80057644:
    // 0x80057644: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80057648: nop

    // 0x8005764C: bne         $t7, $zero, L_8005765C
    if (ctx->r15 != 0) {
        // 0x80057650: nop

            goto L_8005765C;
    }
    // 0x80057650: nop

    // 0x80057654: b           L_8005770C
    // 0x80057658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005770C;
    // 0x80057658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005765C:
    // 0x8005765C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80057660: lw          $t0, 0x670($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X670);
    // 0x80057664: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80057668: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005766C: div         $zero, $t0, $t9
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r25)));
    // 0x80057670: lw          $t2, 0x306C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X306C);
    // 0x80057674: bne         $t9, $zero, L_80057680
    if (ctx->r25 != 0) {
        // 0x80057678: nop

            goto L_80057680;
    }
    // 0x80057678: nop

    // 0x8005767C: break       7
    do_break(2147841660);
L_80057680:
    // 0x80057680: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057684: bne         $t9, $at, L_80057698
    if (ctx->r25 != ctx->r1) {
        // 0x80057688: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80057698;
    }
    // 0x80057688: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005768C: bne         $t0, $at, L_80057698
    if (ctx->r8 != ctx->r1) {
        // 0x80057690: nop

            goto L_80057698;
    }
    // 0x80057690: nop

    // 0x80057694: break       6
    do_break(2147841684);
L_80057698:
    // 0x80057698: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8005769C: mfhi        $t1
    ctx->r9 = hi;
    // 0x800576A0: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800576A4: blez        $t1, L_800576F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800576A8: nop

            goto L_800576F8;
    }
    // 0x800576A8: nop

L_800576AC:
    // 0x800576AC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800576B0: nop

    // 0x800576B4: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x800576B8: nop

    // 0x800576BC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800576C0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800576C4: nop

    // 0x800576C8: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x800576CC: nop

    // 0x800576D0: bne         $t6, $zero, L_800576E8
    if (ctx->r14 != 0) {
        // 0x800576D4: nop

            goto L_800576E8;
    }
    // 0x800576D4: nop

    // 0x800576D8: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800576DC: nop

    // 0x800576E0: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800576E4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800576E8:
    // 0x800576E8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800576EC: nop

    // 0x800576F0: bgtz        $t0, L_800576AC
    if (SIGNED(ctx->r8) > 0) {
        // 0x800576F4: nop

            goto L_800576AC;
    }
    // 0x800576F4: nop

L_800576F8:
    // 0x800576F8: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800576FC: b           L_8005770C
    // 0x80057700: nop

        goto L_8005770C;
    // 0x80057700: nop

    // 0x80057704: b           L_8005770C
    // 0x80057708: nop

        goto L_8005770C;
    // 0x80057708: nop

L_8005770C:
    // 0x8005770C: jr          $ra
    // 0x80057710: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80057710: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80057714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057714: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80057718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005771C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80057720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057724: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80057728: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8005772C: nop

    // 0x80057730: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80057734: nop

    // 0x80057738: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8005773C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80057740: nop

    // 0x80057744: bne         $t8, $zero, L_80057754
    if (ctx->r24 != 0) {
        // 0x80057748: nop

            goto L_80057754;
    }
    // 0x80057748: nop

    // 0x8005774C: b           L_800578D8
    // 0x80057750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800578D8;
    // 0x80057750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057754:
    // 0x80057754: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80057758: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8005775C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80057760: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80057764: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80057768: bne         $t0, $at, L_80057780
    if (ctx->r8 != ctx->r1) {
        // 0x8005776C: nop

            goto L_80057780;
    }
    // 0x8005776C: nop

    // 0x80057770: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x80057774: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80057778: beq         $t1, $at, L_80057848
    if (ctx->r9 == ctx->r1) {
        // 0x8005777C: nop

            goto L_80057848;
    }
    // 0x8005777C: nop

L_80057780:
    // 0x80057780: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80057784: nop

    // 0x80057788: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x8005778C: nop

    // 0x80057790: andi        $t4, $t3, 0xFF00
    ctx->r12 = ctx->r11 & 0XFF00;
    // 0x80057794: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80057798: bne         $t5, $zero, L_80057810
    if (ctx->r13 != 0) {
        // 0x8005779C: nop

            goto L_80057810;
    }
    // 0x8005779C: nop

    // 0x800577A0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800577A4: nop

    // 0x800577A8: lhu         $a0, 0x8($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X8);
    // 0x800577AC: nop

    // 0x800577B0: sra         $t7, $a0, 2
    ctx->r15 = S32(SIGNED(ctx->r4) >> 2);
    // 0x800577B4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800577B8: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x800577BC: jal         0x80056D28
    // 0x800577C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80056D28(rdram, ctx);
        goto after_0;
    // 0x800577C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x800577C4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800577C8: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800577CC: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800577D0: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800577D4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800577D8: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800577DC: lh          $t1, 0x2C5E($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2C5E);
    // 0x800577E0: nop

    // 0x800577E4: beq         $t1, $zero, L_80057810
    if (ctx->r9 == 0) {
        // 0x800577E8: nop

            goto L_80057810;
    }
    // 0x800577E8: nop

    // 0x800577EC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800577F0: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800577F4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800577F8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800577FC: sw          $t2, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r10;
    // 0x80057800: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80057804: nop

    // 0x80057808: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005780C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
L_80057810:
    // 0x80057810: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80057814: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80057818: addiu       $t0, $t8, 0x10
    ctx->r8 = ADD32(ctx->r24, 0X10);
    // 0x8005781C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80057820: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x80057824: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80057828: lhu         $t3, 0x0($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X0);
    // 0x8005782C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80057830: bne         $t3, $at, L_80057780
    if (ctx->r11 != ctx->r1) {
        // 0x80057834: nop

            goto L_80057780;
    }
    // 0x80057834: nop

    // 0x80057838: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x8005783C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80057840: bne         $t2, $at, L_80057780
    if (ctx->r10 != ctx->r1) {
        // 0x80057844: nop

            goto L_80057780;
    }
    // 0x80057844: nop

L_80057848:
    // 0x80057848: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8005784C: nop

    // 0x80057850: bne         $t4, $zero, L_80057860
    if (ctx->r12 != 0) {
        // 0x80057854: nop

            goto L_80057860;
    }
    // 0x80057854: nop

    // 0x80057858: b           L_800578D8
    // 0x8005785C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800578D8;
    // 0x8005785C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057860:
    // 0x80057860: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80057864: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x80057868: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8005786C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80057870: divu        $zero, $t5, $t6
    lo = S32(U32(ctx->r13) / U32(ctx->r14)); hi = S32(U32(ctx->r13) % U32(ctx->r14));
    // 0x80057874: bne         $t6, $zero, L_80057880
    if (ctx->r14 != 0) {
        // 0x80057878: nop

            goto L_80057880;
    }
    // 0x80057878: nop

    // 0x8005787C: break       7
    do_break(2147842172);
L_80057880:
    // 0x80057880: mfhi        $t7
    ctx->r15 = hi;
    // 0x80057884: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80057888: addu        $a1, $sp, $t8
    ctx->r5 = ADD32(ctx->r29, ctx->r24);
    // 0x8005788C: lw          $a1, 0x28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X28);
    // 0x80057890: jal         0x8007959C
    // 0x80057894: nop

    func_8007959C(rdram, ctx);
        goto after_1;
    // 0x80057894: nop

    after_1:
    // 0x80057898: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8005789C: nop

    // 0x800578A0: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x800578A4: nop

    // 0x800578A8: beq         $t1, $zero, L_800578C4
    if (ctx->r9 == 0) {
        // 0x800578AC: nop

            goto L_800578C4;
    }
    // 0x800578AC: nop

    // 0x800578B0: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x800578B4: nop

    // 0x800578B8: lw          $a0, 0x18($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X18);
    // 0x800578BC: jal         0x800BC980
    // 0x800578C0: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x800578C0: nop

    after_2:
L_800578C4:
    // 0x800578C4: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x800578C8: b           L_800578D8
    // 0x800578CC: nop

        goto L_800578D8;
    // 0x800578CC: nop

    // 0x800578D0: b           L_800578D8
    // 0x800578D4: nop

        goto L_800578D8;
    // 0x800578D4: nop

L_800578D8:
    // 0x800578D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800578DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800578E0: jr          $ra
    // 0x800578E4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800578E4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800578E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800578E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800578EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800578F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800578F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800578F8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800578FC: nop

    // 0x80057900: bltz        $t6, L_80057948
    if (SIGNED(ctx->r14) < 0) {
        // 0x80057904: nop

            goto L_80057948;
    }
    // 0x80057904: nop

L_80057908:
    // 0x80057908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005790C: jal         0x800499B0
    // 0x80057910: nop

    func_800499B0(rdram, ctx);
        goto after_0;
    // 0x80057910: nop

    after_0:
    // 0x80057914: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80057918: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005791C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80057920: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80057924: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057928: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005792C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80057930: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80057934: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80057938: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005793C: subu        $t0, $t7, $t9
    ctx->r8 = SUB32(ctx->r15, ctx->r25);
    // 0x80057940: bgez        $t0, L_80057908
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80057944: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_80057908;
    }
    // 0x80057944: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_80057948:
    // 0x80057948: b           L_80057950
    // 0x8005794C: nop

        goto L_80057950;
    // 0x8005794C: nop

L_80057950:
    // 0x80057950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057958: jr          $ra
    // 0x8005795C: nop

    return;
    // 0x8005795C: nop

;}
RECOMP_FUNC void func_80057960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057968: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8005796C: lw          $t6, 0x480($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X480);
    // 0x80057970: nop

    // 0x80057974: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80057978: jal         0x8005A578
    // 0x8005797C: nop

    func_8005A578(rdram, ctx);
        goto after_0;
    // 0x8005797C: nop

    after_0:
    // 0x80057980: beq         $v0, $zero, L_80057A98
    if (ctx->r2 == 0) {
        // 0x80057984: nop

            goto L_80057A98;
    }
    // 0x80057984: nop

    // 0x80057988: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005798C: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80057990: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057994: beq         $t7, $at, L_80057A98
    if (ctx->r15 == ctx->r1) {
        // 0x80057998: nop

            goto L_80057A98;
    }
    // 0x80057998: nop

    // 0x8005799C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800579A0: lh          $t8, 0x6C0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X6C0);
    // 0x800579A4: nop

    // 0x800579A8: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800579AC: beq         $at, $zero, L_80057A98
    if (ctx->r1 == 0) {
        // 0x800579B0: nop

            goto L_80057A98;
    }
    // 0x800579B0: nop

    // 0x800579B4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800579B8: nop

    // 0x800579BC: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800579C0: nop

    // 0x800579C4: bne         $t0, $zero, L_800579FC
    if (ctx->r8 != 0) {
        // 0x800579C8: nop

            goto L_800579FC;
    }
    // 0x800579C8: nop

    // 0x800579CC: lh          $t1, 0x2($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X2);
    // 0x800579D0: nop

    // 0x800579D4: bne         $t1, $zero, L_800579FC
    if (ctx->r9 != 0) {
        // 0x800579D8: nop

            goto L_800579FC;
    }
    // 0x800579D8: nop

    // 0x800579DC: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x800579E0: nop

    // 0x800579E4: bne         $t2, $zero, L_800579FC
    if (ctx->r10 != 0) {
        // 0x800579E8: nop

            goto L_800579FC;
    }
    // 0x800579E8: nop

    // 0x800579EC: lh          $t3, 0x6($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X6);
    // 0x800579F0: nop

    // 0x800579F4: beq         $t3, $zero, L_80057A58
    if (ctx->r11 == 0) {
        // 0x800579F8: nop

            goto L_80057A58;
    }
    // 0x800579F8: nop

L_800579FC:
    // 0x800579FC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80057A00: addiu       $at, $zero, 0x694
    ctx->r1 = ADD32(0, 0X694);
    // 0x80057A04: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80057A08: nop

    // 0x80057A0C: bne         $t5, $at, L_80057A4C
    if (ctx->r13 != ctx->r1) {
        // 0x80057A10: nop

            goto L_80057A4C;
    }
    // 0x80057A10: nop

    // 0x80057A14: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80057A18: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80057A1C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80057A20: nop

    // 0x80057A24: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x80057A28: beq         $t8, $zero, L_80057A4C
    if (ctx->r24 == 0) {
        // 0x80057A2C: nop

            goto L_80057A4C;
    }
    // 0x80057A2C: nop

    // 0x80057A30: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80057A34: nop

    // 0x80057A38: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x80057A3C: b           L_80057AA8
    // 0x80057A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80057AA8;
    // 0x80057A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057A44: b           L_80057A58
    // 0x80057A48: nop

        goto L_80057A58;
    // 0x80057A48: nop

L_80057A4C:
    // 0x80057A4C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80057A50: b           L_80057AA8
    // 0x80057A54: nop

        goto L_80057AA8;
    // 0x80057A54: nop

L_80057A58:
    // 0x80057A58: jal         0x8005A7C0
    // 0x80057A5C: nop

    func_8005A7C0(rdram, ctx);
        goto after_1;
    // 0x80057A5C: nop

    after_1:
    // 0x80057A60: beq         $v0, $zero, L_80057A98
    if (ctx->r2 == 0) {
        // 0x80057A64: nop

            goto L_80057A98;
    }
    // 0x80057A64: nop

    // 0x80057A68: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80057A6C: lw          $t2, 0x480($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X480);
    // 0x80057A70: addiu       $t1, $zero, 0x6DD
    ctx->r9 = ADD32(0, 0X6DD);
    // 0x80057A74: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80057A78: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80057A7C: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80057A80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80057A84: sh          $t9, 0x4E($t3)
    MEM_H(0X4E, ctx->r11) = ctx->r25;
    // 0x80057A88: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80057A8C: lw          $v0, 0x480($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X480);
    // 0x80057A90: b           L_80057AA8
    // 0x80057A94: nop

        goto L_80057AA8;
    // 0x80057A94: nop

L_80057A98:
    // 0x80057A98: b           L_80057AA8
    // 0x80057A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80057AA8;
    // 0x80057A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057AA0: b           L_80057AA8
    // 0x80057AA4: nop

        goto L_80057AA8;
    // 0x80057AA4: nop

L_80057AA8:
    // 0x80057AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057AAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80057AB0: jr          $ra
    // 0x80057AB4: nop

    return;
    // 0x80057AB4: nop

;}
RECOMP_FUNC void func_80057AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057AB8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80057ABC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80057AC0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80057AC4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80057AC8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80057ACC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80057AD0: nop

    // 0x80057AD4: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80057AD8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80057ADC: nop

    // 0x80057AE0: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80057AE4: nop

    // 0x80057AE8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80057AEC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80057AF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80057AF4: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x80057AF8: lw          $t0, 0x2F9($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2F9);
    // 0x80057AFC: nop

    // 0x80057B00: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80057B04: sw          $t0, 0xE70($at)
    MEM_W(0XE70, ctx->r1) = ctx->r8;
    // 0x80057B08: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80057B0C: nop

    // 0x80057B10: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80057B14: jal         0x80098754
    // 0x80057B18: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x80057B18: nop

    after_0:
    // 0x80057B1C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057B20: jal         0x80032410
    // 0x80057B24: nop

    func_80032410(rdram, ctx);
        goto after_1;
    // 0x80057B24: nop

    after_1:
    // 0x80057B28: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80057B2C: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80057B30: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80057B34: nop

    // 0x80057B38: andi        $t4, $t3, 0x402
    ctx->r12 = ctx->r11 & 0X402;
    // 0x80057B3C: beq         $t4, $zero, L_80057B6C
    if (ctx->r12 == 0) {
        // 0x80057B40: nop

            goto L_80057B6C;
    }
    // 0x80057B40: nop

L_80057B44:
    // 0x80057B44: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057B48: jal         0x800499B0
    // 0x80057B4C: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x80057B4C: nop

    after_2:
    // 0x80057B50: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80057B54: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80057B58: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80057B5C: nop

    // 0x80057B60: andi        $t7, $t6, 0x402
    ctx->r15 = ctx->r14 & 0X402;
    // 0x80057B64: bne         $t7, $zero, L_80057B44
    if (ctx->r15 != 0) {
        // 0x80057B68: nop

            goto L_80057B44;
    }
    // 0x80057B68: nop

L_80057B6C:
    // 0x80057B6C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80057B70: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80057B74: lh          $a1, 0x7C($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X7C);
    // 0x80057B78: lw          $a3, 0x44($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X44);
    // 0x80057B7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80057B80: addiu       $a2, $zero, 0x8F
    ctx->r6 = ADD32(0, 0X8F);
    // 0x80057B84: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80057B88: jal         0x8004F3E8
    // 0x80057B8C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8004F3E8(rdram, ctx);
        goto after_3;
    // 0x80057B8C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_3:
    // 0x80057B90: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80057B94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057B98: nop

    // 0x80057B9C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80057BA0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80057BA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80057BA8: nop

    // 0x80057BAC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_80057BB0:
    // 0x80057BB0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80057BB4: nop

    // 0x80057BB8: bne         $t0, $zero, L_80057C34
    if (ctx->r8 != 0) {
        // 0x80057BBC: nop

            goto L_80057C34;
    }
    // 0x80057BBC: nop

    // 0x80057BC0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80057BC4: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80057BC8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80057BCC: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80057BD0: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80057BD4: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80057BD8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80057BDC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80057BE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80057BE4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80057BE8: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x80057BEC: nop

    // 0x80057BF0: bc1f        L_80057C34
    if (!c1cs) {
        // 0x80057BF4: nop

            goto L_80057C34;
    }
    // 0x80057BF4: nop

    // 0x80057BF8: lui         $at, 0x4089
    ctx->r1 = S32(0X4089 << 16);
    // 0x80057BFC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80057C00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80057C04: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80057C08: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80057C0C: nop

    // 0x80057C10: bc1f        L_80057C34
    if (!c1cs) {
        // 0x80057C14: nop

            goto L_80057C34;
    }
    // 0x80057C14: nop

    // 0x80057C18: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80057C1C: nop

    // 0x80057C20: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80057C24: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80057C28: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80057C2C: nop

    // 0x80057C30: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_80057C34:
    // 0x80057C34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80057C38: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057C3C: lwc1        $f11, -0xEF8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XEF8);
    // 0x80057C40: lwc1        $f10, -0xEF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEF4);
    // 0x80057C44: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80057C48: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80057C4C: jal         0x800C3070
    // 0x80057C50: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_4;
    // 0x80057C50: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_4:
    // 0x80057C54: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80057C58: lwc1        $f17, -0xEF0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XEF0);
    // 0x80057C5C: lwc1        $f16, -0xEEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x80057C60: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80057C64: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x80057C68: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80057C6C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80057C70: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80057C74: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80057C78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80057C7C: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x80057C80: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80057C84: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80057C88: jal         0x8005D07C
    // 0x80057C8C: nop

    func_8005D07C(rdram, ctx);
        goto after_5;
    // 0x80057C8C: nop

    after_5:
    // 0x80057C90: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80057C94: nop

    // 0x80057C98: beq         $t5, $zero, L_80057D34
    if (ctx->r13 == 0) {
        // 0x80057C9C: nop

            goto L_80057D34;
    }
    // 0x80057C9C: nop

    // 0x80057CA0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057CA4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80057CA8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80057CAC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80057CB0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80057CB4: add.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = ctx->f4.d + ctx->f18.d;
    // 0x80057CB8: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80057CBC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80057CC0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057CC4: lui         $at, 0x405E
    ctx->r1 = S32(0X405E << 16);
    // 0x80057CC8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80057CCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80057CD0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80057CD4: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80057CD8: nop

    // 0x80057CDC: bc1f        L_80057D0C
    if (!c1cs) {
        // 0x80057CE0: nop

            goto L_80057D0C;
    }
    // 0x80057CE0: nop

    // 0x80057CE4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80057CE8: nop

    // 0x80057CEC: addiu       $a0, $t6, 0x4C
    ctx->r4 = ADD32(ctx->r14, 0X4C);
    // 0x80057CF0: jal         0x800B2748
    // 0x80057CF4: addiu       $a1, $t6, 0x50
    ctx->r5 = ADD32(ctx->r14, 0X50);
    func_800B2748(rdram, ctx);
        goto after_6;
    // 0x80057CF4: addiu       $a1, $t6, 0x50
    ctx->r5 = ADD32(ctx->r14, 0X50);
    after_6:
    // 0x80057CF8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80057CFC: nop

    // 0x80057D00: addiu       $a0, $t7, 0x50
    ctx->r4 = ADD32(ctx->r15, 0X50);
    // 0x80057D04: jal         0x8005A5F4
    // 0x80057D08: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_7;
    // 0x80057D08: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_7:
L_80057D0C:
    // 0x80057D0C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80057D10: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057D14: lwc1        $f7, -0xEE8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XEE8);
    // 0x80057D18: lwc1        $f6, -0xEE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x80057D1C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80057D20: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80057D24: nop

    // 0x80057D28: bc1f        L_80057D34
    if (!c1cs) {
        // 0x80057D2C: nop

            goto L_80057D34;
    }
    // 0x80057D2C: nop

    // 0x80057D30: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80057D34:
    // 0x80057D34: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057D38: jal         0x800499B0
    // 0x80057D3C: nop

    func_800499B0(rdram, ctx);
        goto after_8;
    // 0x80057D3C: nop

    after_8:
    // 0x80057D40: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80057D44: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x80057D48: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80057D4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80057D50: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80057D54: nop

    // 0x80057D58: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80057D5C: nop

    // 0x80057D60: bc1t        L_80057BB0
    if (c1cs) {
        // 0x80057D64: nop

            goto L_80057BB0;
    }
    // 0x80057D64: nop

    // 0x80057D68: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80057D6C: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x80057D70: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x80057D74: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80057D78: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80057D7C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80057D80: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80057D84: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80057D88: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80057D8C: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80057D90: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80057D94: nop

    // 0x80057D98: sb          $zero, 0x20($t4)
    MEM_B(0X20, ctx->r12) = 0;
    // 0x80057D9C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80057DA0: nop

    // 0x80057DA4: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80057DA8: jal         0x80098AD8
    // 0x80057DAC: nop

    func_80098AD8(rdram, ctx);
        goto after_9;
    // 0x80057DAC: nop

    after_9:
    // 0x80057DB0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057DB4: jal         0x80049544
    // 0x80057DB8: nop

    func_80049544(rdram, ctx);
        goto after_10;
    // 0x80057DB8: nop

    after_10:
    // 0x80057DBC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80057DC0: nop

    // 0x80057DC4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80057DC8: jal         0x800C0D34
    // 0x80057DCC: nop

    Thread_StopThread(rdram, ctx);
        goto after_11;
    // 0x80057DCC: nop

    after_11:
L_80057DD0:
    // 0x80057DD0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057DD4: jal         0x800499B0
    // 0x80057DD8: nop

    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x80057DD8: nop

    after_12:
    // 0x80057DDC: b           L_80057DD0
    // 0x80057DE0: nop

        goto L_80057DD0;
    // 0x80057DE0: nop

    // 0x80057DE4: b           L_80057DEC
    // 0x80057DE8: nop

        goto L_80057DEC;
    // 0x80057DE8: nop

L_80057DEC:
    // 0x80057DEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80057DF0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80057DF4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80057DF8: jr          $ra
    // 0x80057DFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80057DFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80057E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057E00: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80057E04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80057E08: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80057E0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057E10: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80057E14: nop

    // 0x80057E18: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x80057E1C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80057E20: nop

    // 0x80057E24: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80057E28: nop

    // 0x80057E2C: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80057E30: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80057E34: nop

    // 0x80057E38: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80057E3C: jal         0x80098754
    // 0x80057E40: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x80057E40: nop

    after_0:
    // 0x80057E44: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80057E48: jal         0x8005F268
    // 0x80057E4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F268(rdram, ctx);
        goto after_1;
    // 0x80057E4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80057E50: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80057E54: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80057E58: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80057E5C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80057E60: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80057E64: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80057E68: bne         $t4, $zero, L_80057EAC
    if (ctx->r12 != 0) {
        // 0x80057E6C: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_80057EAC;
    }
    // 0x80057E6C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80057E70: bne         $t5, $zero, L_80057EAC
    if (ctx->r13 != 0) {
        // 0x80057E74: nop

            goto L_80057EAC;
    }
    // 0x80057E74: nop

L_80057E78:
    // 0x80057E78: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80057E7C: jal         0x800499B0
    // 0x80057E80: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x80057E80: nop

    after_2:
    // 0x80057E84: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80057E88: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80057E8C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80057E90: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80057E94: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80057E98: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80057E9C: bne         $t8, $zero, L_80057EAC
    if (ctx->r24 != 0) {
        // 0x80057EA0: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_80057EAC;
    }
    // 0x80057EA0: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80057EA4: beq         $t9, $zero, L_80057E78
    if (ctx->r25 == 0) {
        // 0x80057EA8: nop

            goto L_80057E78;
    }
    // 0x80057EA8: nop

L_80057EAC:
    // 0x80057EAC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80057EB0: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80057EB4: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x80057EB8: nop

    // 0x80057EBC: andi        $t3, $t2, 0x402
    ctx->r11 = ctx->r10 & 0X402;
    // 0x80057EC0: beq         $t3, $zero, L_80057EF0
    if (ctx->r11 == 0) {
        // 0x80057EC4: nop

            goto L_80057EF0;
    }
    // 0x80057EC4: nop

L_80057EC8:
    // 0x80057EC8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80057ECC: jal         0x800499B0
    // 0x80057ED0: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x80057ED0: nop

    after_3:
    // 0x80057ED4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80057ED8: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80057EDC: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80057EE0: nop

    // 0x80057EE4: andi        $t1, $t5, 0x402
    ctx->r9 = ctx->r13 & 0X402;
    // 0x80057EE8: bne         $t1, $zero, L_80057EC8
    if (ctx->r9 != 0) {
        // 0x80057EEC: nop

            goto L_80057EC8;
    }
    // 0x80057EEC: nop

L_80057EF0:
    // 0x80057EF0: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    // 0x80057EF4: jal         0x80056E88
    // 0x80057EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_4;
    // 0x80057EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80057EFC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80057F00: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80057F04: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80057F08: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80057F0C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80057F10: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80057F14: lh          $a1, 0x42($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X42);
    // 0x80057F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80057F1C: jal         0x8004EF90
    // 0x80057F20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_5;
    // 0x80057F20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80057F24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057F28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057F2C: nop

    // 0x80057F30: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80057F34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80057F38: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80057F3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80057F40: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x80057F44: lwc1        $f17, -0xEE0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XEE0);
    // 0x80057F48: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80057F4C: lwc1        $f16, -0xEDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEDC);
    // 0x80057F50: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80057F54: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80057F58: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80057F5C: nop

    // 0x80057F60: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x80057F64: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80057F68: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x80057F6C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80057F70: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80057F74: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80057F78: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80057F7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80057F80: lh          $t2, 0xE($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XE);
    // 0x80057F84: lwc1        $f19, -0xED8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XED8);
    // 0x80057F88: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80057F8C: lwc1        $f18, -0xED4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XED4);
    // 0x80057F90: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80057F94: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80057F98: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80057F9C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80057FA0: nop

    // 0x80057FA4: div.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f18.d);
    // 0x80057FA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80057FAC: nop

    // 0x80057FB0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80057FB4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80057FB8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80057FBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80057FC0: nop

    // 0x80057FC4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80057FC8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80057FCC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80057FD0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80057FD4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80057FD8: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80057FDC: nop

    // 0x80057FE0: lwc1        $f18, 0x10($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X10);
    // 0x80057FE4: nop

    // 0x80057FE8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
L_80057FEC:
    // 0x80057FEC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80057FF0: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80057FF4: bne         $t4, $at, L_80058064
    if (ctx->r12 != ctx->r1) {
        // 0x80057FF8: nop

            goto L_80058064;
    }
    // 0x80057FF8: nop

    // 0x80057FFC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80058000: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80058004: addiu       $at, $zero, 0x116
    ctx->r1 = ADD32(0, 0X116);
    // 0x80058008: lh          $t1, 0x4A($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X4A);
    // 0x8005800C: nop

    // 0x80058010: bne         $t1, $at, L_80058064
    if (ctx->r9 != ctx->r1) {
        // 0x80058014: nop

            goto L_80058064;
    }
    // 0x80058014: nop

    // 0x80058018: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005801C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80058020: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80058024: sw          $t6, 0x9C($t7)
    MEM_W(0X9C, ctx->r15) = ctx->r14;
    // 0x80058028: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8005802C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80058030: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80058034: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058038: nop

    // 0x8005803C: swc1        $f8, 0xA0($t8)
    MEM_W(0XA0, ctx->r24) = ctx->f8.u32l;
    // 0x80058040: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058044: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80058048: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8005804C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80058050: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80058054: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80058058: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x8005805C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80058060: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
L_80058064:
    // 0x80058064: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80058068: nop

    // 0x8005806C: bne         $t4, $zero, L_80058124
    if (ctx->r12 != 0) {
        // 0x80058070: nop

            goto L_80058124;
    }
    // 0x80058070: nop

    // 0x80058074: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80058078: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005807C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80058080: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x80058084: lwc1        $f16, 0xC($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80058088: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8005808C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80058090: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058094: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80058098: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005809C: nop

    // 0x800580A0: bc1f        L_80058124
    if (!c1cs) {
        // 0x800580A4: nop

            goto L_80058124;
    }
    // 0x800580A4: nop

    // 0x800580A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800580AC: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800580B0: nop

    // 0x800580B4: lh          $t8, 0xE($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XE);
    // 0x800580B8: nop

    // 0x800580BC: slti        $at, $t8, 0x12C
    ctx->r1 = SIGNED(ctx->r24) < 0X12C ? 1 : 0;
    // 0x800580C0: bne         $at, $zero, L_80058124
    if (ctx->r1 != 0) {
        // 0x800580C4: nop

            goto L_80058124;
    }
    // 0x800580C4: nop

    // 0x800580C8: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x800580CC: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800580D0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800580D4: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800580D8: bne         $t2, $zero, L_80058124
    if (ctx->r10 != 0) {
        // 0x800580DC: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80058124;
    }
    // 0x800580DC: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800580E0: bne         $t3, $zero, L_80058124
    if (ctx->r11 != 0) {
        // 0x800580E4: nop

            goto L_80058124;
    }
    // 0x800580E4: nop

    // 0x800580E8: lui         $at, 0x4089
    ctx->r1 = S32(0X4089 << 16);
    // 0x800580EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800580F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800580F4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800580F8: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x800580FC: nop

    // 0x80058100: bc1f        L_80058124
    if (!c1cs) {
        // 0x80058104: nop

            goto L_80058124;
    }
    // 0x80058104: nop

    // 0x80058108: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8005810C: nop

    // 0x80058110: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x80058114: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x80058118: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005811C: nop

    // 0x80058120: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
L_80058124:
    // 0x80058124: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80058128: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005812C: lwc1        $f17, -0xED0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XED0);
    // 0x80058130: lwc1        $f16, -0xECC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XECC);
    // 0x80058134: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80058138: mul.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x8005813C: jal         0x800C3070
    // 0x80058140: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_6;
    // 0x80058140: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_6:
    // 0x80058144: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80058148: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005814C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80058150: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80058154: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80058158: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005815C: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x80058160: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80058164: jal         0x8005D07C
    // 0x80058168: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_7;
    // 0x80058168: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_7:
    // 0x8005816C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80058170: nop

    // 0x80058174: beq         $t5, $zero, L_8005829C
    if (ctx->r13 == 0) {
        // 0x80058178: nop

            goto L_8005829C;
    }
    // 0x80058178: nop

    // 0x8005817C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80058180: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80058184: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80058188: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005818C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80058190: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x80058194: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80058198: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8005819C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800581A0: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800581A4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800581A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800581AC: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x800581B0: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x800581B4: nop

    // 0x800581B8: bc1f        L_80058274
    if (!c1cs) {
        // 0x800581BC: nop

            goto L_80058274;
    }
    // 0x800581BC: nop

    // 0x800581C0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800581C4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800581C8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800581CC: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800581D0: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800581D4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800581D8: bne         $t6, $zero, L_80058274
    if (ctx->r14 != 0) {
        // 0x800581DC: and         $t7, $t9, $at
        ctx->r15 = ctx->r25 & ctx->r1;
            goto L_80058274;
    }
    // 0x800581DC: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800581E0: bne         $t7, $zero, L_80058274
    if (ctx->r15 != 0) {
        // 0x800581E4: nop

            goto L_80058274;
    }
    // 0x800581E4: nop

    // 0x800581E8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800581EC: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800581F0: nop

    // 0x800581F4: addiu       $a0, $t0, 0x4C
    ctx->r4 = ADD32(ctx->r8, 0X4C);
    // 0x800581F8: jal         0x800B2748
    // 0x800581FC: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    func_800B2748(rdram, ctx);
        goto after_8;
    // 0x800581FC: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    after_8:
    // 0x80058200: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80058204: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80058208: nop

    // 0x8005820C: addiu       $a0, $t1, 0x50
    ctx->r4 = ADD32(ctx->r9, 0X50);
    // 0x80058210: jal         0x8005A5F4
    // 0x80058214: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_9;
    // 0x80058214: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_9:
    // 0x80058218: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8005821C: nop

    // 0x80058220: bgez        $t2, L_80058234
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80058224: andi        $t3, $t2, 0x7
        ctx->r11 = ctx->r10 & 0X7;
            goto L_80058234;
    }
    // 0x80058224: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x80058228: beq         $t3, $zero, L_80058234
    if (ctx->r11 == 0) {
        // 0x8005822C: nop

            goto L_80058234;
    }
    // 0x8005822C: nop

    // 0x80058230: addiu       $t3, $t3, -0x8
    ctx->r11 = ADD32(ctx->r11, -0X8);
L_80058234:
    // 0x80058234: bne         $t3, $zero, L_80058274
    if (ctx->r11 != 0) {
        // 0x80058238: nop

            goto L_80058274;
    }
    // 0x80058238: nop

    // 0x8005823C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80058240: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80058244: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x80058248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005824C: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80058250: nop

    // 0x80058254: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80058258: nop

    // 0x8005825C: bc1f        L_80058274
    if (!c1cs) {
        // 0x80058260: nop

            goto L_80058274;
    }
    // 0x80058260: nop

    // 0x80058264: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80058268: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8005826C: jal         0x80052508
    // 0x80058270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_10;
    // 0x80058270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
L_80058274:
    // 0x80058274: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80058278: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005827C: lwc1        $f17, -0xEC8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XEC8);
    // 0x80058280: lwc1        $f16, -0xEC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEC4);
    // 0x80058284: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80058288: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x8005828C: nop

    // 0x80058290: bc1f        L_8005829C
    if (!c1cs) {
        // 0x80058294: nop

            goto L_8005829C;
    }
    // 0x80058294: nop

    // 0x80058298: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_8005829C:
    // 0x8005829C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800582A0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800582A4: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x800582A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800582AC: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800582B0: nop

    // 0x800582B4: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x800582B8: nop

    // 0x800582BC: bc1f        L_80058324
    if (!c1cs) {
        // 0x800582C0: nop

            goto L_80058324;
    }
    // 0x800582C0: nop

    // 0x800582C4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800582C8: nop

    // 0x800582CC: beq         $t8, $zero, L_800582E4
    if (ctx->r24 == 0) {
        // 0x800582D0: nop

            goto L_800582E4;
    }
    // 0x800582D0: nop

    // 0x800582D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800582D8: lwc1        $f10, -0xEC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEC0);
    // 0x800582DC: nop

    // 0x800582E0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
L_800582E4:
    // 0x800582E4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800582E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800582EC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800582F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800582F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800582F8: jal         0x800ACC34
    // 0x800582FC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800ACC34(rdram, ctx);
        goto after_11;
    // 0x800582FC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_11:
    // 0x80058300: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058304: beq         $v0, $at, L_80058324
    if (ctx->r2 == ctx->r1) {
        // 0x80058308: nop

            goto L_80058324;
    }
    // 0x80058308: nop

    // 0x8005830C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058310: lwc1        $f16, 0x125C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X125C);
    // 0x80058314: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80058318: nop

    // 0x8005831C: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80058320: swc1        $f8, 0x125C($at)
    MEM_W(0X125C, ctx->r1) = ctx->f8.u32l;
L_80058324:
    // 0x80058324: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80058328: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8005832C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80058330: mfhi        $t6
    ctx->r14 = hi;
    // 0x80058334: bne         $t6, $zero, L_8005842C
    if (ctx->r14 != 0) {
        // 0x80058338: nop

            goto L_8005842C;
    }
    // 0x80058338: nop

    // 0x8005833C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80058340: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80058344: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80058348: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8005834C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80058350: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80058354: bne         $t2, $zero, L_8005842C
    if (ctx->r10 != 0) {
        // 0x80058358: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8005842C;
    }
    // 0x80058358: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8005835C: bne         $t3, $zero, L_8005842C
    if (ctx->r11 != 0) {
        // 0x80058360: nop

            goto L_8005842C;
    }
    // 0x80058360: nop

    // 0x80058364: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x80058368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005836C: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80058370: nop

    // 0x80058374: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80058378: nop

    // 0x8005837C: bc1f        L_8005842C
    if (!c1cs) {
        // 0x80058380: nop

            goto L_8005842C;
    }
    // 0x80058380: nop

    // 0x80058384: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80058388: jal         0x80054264
    // 0x8005838C: nop

    func_80054264(rdram, ctx);
        goto after_12;
    // 0x8005838C: nop

    after_12:
    // 0x80058390: beq         $v0, $zero, L_8005842C
    if (ctx->r2 == 0) {
        // 0x80058394: nop

            goto L_8005842C;
    }
    // 0x80058394: nop

    // 0x80058398: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8005839C: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x800583A0: jal         0x80052508
    // 0x800583A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_13;
    // 0x800583A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x800583A8: beq         $v0, $zero, L_800583F8
    if (ctx->r2 == 0) {
        // 0x800583AC: nop

            goto L_800583F8;
    }
    // 0x800583AC: nop

    // 0x800583B0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800583B4: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x800583B8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800583BC: lh          $a1, 0x42($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X42);
    // 0x800583C0: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    // 0x800583C4: jal         0x8004EF90
    // 0x800583C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_14;
    // 0x800583C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x800583CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800583D0: nop

    // 0x800583D4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800583D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800583DC: nop

    // 0x800583E0: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x800583E4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800583E8: nop

    // 0x800583EC: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800583F0: b           L_8005842C
    // 0x800583F4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_8005842C;
    // 0x800583F4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800583F8:
    // 0x800583F8: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    // 0x800583FC: jal         0x80056E88
    // 0x80058400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_15;
    // 0x80058400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80058404: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80058408: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005840C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80058410: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80058414: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80058418: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8005841C: lh          $a1, 0x42($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X42);
    // 0x80058420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80058424: jal         0x8004EF90
    // 0x80058428: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_16;
    // 0x80058428: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
L_8005842C:
    // 0x8005842C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80058430: nop

    // 0x80058434: bgez        $t0, L_80058448
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80058438: andi        $t1, $t0, 0xF
        ctx->r9 = ctx->r8 & 0XF;
            goto L_80058448;
    }
    // 0x80058438: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x8005843C: beq         $t1, $zero, L_80058448
    if (ctx->r9 == 0) {
        // 0x80058440: nop

            goto L_80058448;
    }
    // 0x80058440: nop

    // 0x80058444: addiu       $t1, $t1, -0x10
    ctx->r9 = ADD32(ctx->r9, -0X10);
L_80058448:
    // 0x80058448: bne         $t1, $zero, L_80058510
    if (ctx->r9 != 0) {
        // 0x8005844C: nop

            goto L_80058510;
    }
    // 0x8005844C: nop

    // 0x80058450: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80058454: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80058458: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x8005845C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058460: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80058464: nop

    // 0x80058468: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8005846C: nop

    // 0x80058470: bc1f        L_80058510
    if (!c1cs) {
        // 0x80058474: nop

            goto L_80058510;
    }
    // 0x80058474: nop

    // 0x80058478: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8005847C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80058480: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80058484: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80058488: bne         $t8, $zero, L_80058510
    if (ctx->r24 != 0) {
        // 0x8005848C: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_80058510;
    }
    // 0x8005848C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80058490: bne         $t9, $zero, L_80058510
    if (ctx->r25 != 0) {
        // 0x80058494: nop

            goto L_80058510;
    }
    // 0x80058494: nop

    // 0x80058498: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8005849C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800584A0: jal         0x80052508
    // 0x800584A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_17;
    // 0x800584A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x800584A8: beq         $v0, $zero, L_80058510
    if (ctx->r2 == 0) {
        // 0x800584AC: nop

            goto L_80058510;
    }
    // 0x800584AC: nop

    // 0x800584B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800584B4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800584B8: addiu       $at, $zero, 0x6D
    ctx->r1 = ADD32(0, 0X6D);
    // 0x800584BC: lh          $t7, 0x4A($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X4A);
    // 0x800584C0: nop

    // 0x800584C4: beq         $t7, $at, L_80058510
    if (ctx->r15 == ctx->r1) {
        // 0x800584C8: nop

            goto L_80058510;
    }
    // 0x800584C8: nop

    // 0x800584CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800584D0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800584D4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800584D8: lh          $a1, 0x42($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X42);
    // 0x800584DC: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    // 0x800584E0: jal         0x8004EF90
    // 0x800584E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_18;
    // 0x800584E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x800584E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800584EC: nop

    // 0x800584F0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800584F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800584F8: nop

    // 0x800584FC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80058500: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80058504: nop

    // 0x80058508: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005850C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80058510:
    // 0x80058510: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80058514: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80058518: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005851C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80058520: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80058524: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80058528: bne         $t8, $zero, L_80058538
    if (ctx->r24 != 0) {
        // 0x8005852C: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_80058538;
    }
    // 0x8005852C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80058530: beq         $t9, $zero, L_800586D4
    if (ctx->r25 == 0) {
        // 0x80058534: nop

            goto L_800586D4;
    }
    // 0x80058534: nop

L_80058538:
    // 0x80058538: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005853C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80058540: nop

    // 0x80058544: addiu       $a0, $t3, 0x4C
    ctx->r4 = ADD32(ctx->r11, 0X4C);
    // 0x80058548: jal         0x800B2748
    // 0x8005854C: addiu       $a1, $t3, 0x50
    ctx->r5 = ADD32(ctx->r11, 0X50);
    func_800B2748(rdram, ctx);
        goto after_19;
    // 0x8005854C: addiu       $a1, $t3, 0x50
    ctx->r5 = ADD32(ctx->r11, 0X50);
    after_19:
    // 0x80058550: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80058554: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80058558: nop

    // 0x8005855C: addiu       $a0, $t7, 0x50
    ctx->r4 = ADD32(ctx->r15, 0X50);
    // 0x80058560: jal         0x8005A5F4
    // 0x80058564: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_20;
    // 0x80058564: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_20:
    // 0x80058568: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005856C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80058570: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80058574: lwc1        $f6, 0x34($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X34);
    // 0x80058578: lwc1        $f19, -0xEB8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XEB8);
    // 0x8005857C: lwc1        $f18, -0xEB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEB4);
    // 0x80058580: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80058584: mul.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80058588: jal         0x800C3070
    // 0x8005858C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_21;
    // 0x8005858C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_21:
    // 0x80058590: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80058594: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80058598: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005859C: nop

    // 0x800585A0: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800585A4: nop

    // 0x800585A8: bc1f        L_800585E8
    if (!c1cs) {
        // 0x800585AC: nop

            goto L_800585E8;
    }
    // 0x800585AC: nop

    // 0x800585B0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800585B4: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x800585B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800585BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800585C0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800585C4: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800585C8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800585CC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800585D0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800585D4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800585D8: add.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = ctx->f4.d + ctx->f8.d;
    // 0x800585DC: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x800585E0: b           L_800586D4
    // 0x800585E4: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
        goto L_800586D4;
    // 0x800585E4: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
L_800585E8:
    // 0x800585E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800585EC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x800585F0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800585F4: nop

    // 0x800585F8: swc1        $f18, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f18.u32l;
    // 0x800585FC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80058600: nop

    // 0x80058604: bgez        $t2, L_80058618
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80058608: andi        $t4, $t2, 0x1
        ctx->r12 = ctx->r10 & 0X1;
            goto L_80058618;
    }
    // 0x80058608: andi        $t4, $t2, 0x1
    ctx->r12 = ctx->r10 & 0X1;
    // 0x8005860C: beq         $t4, $zero, L_80058618
    if (ctx->r12 == 0) {
        // 0x80058610: nop

            goto L_80058618;
    }
    // 0x80058610: nop

    // 0x80058614: addiu       $t4, $t4, -0x2
    ctx->r12 = ADD32(ctx->r12, -0X2);
L_80058618:
    // 0x80058618: bne         $t4, $zero, L_800586D4
    if (ctx->r12 != 0) {
        // 0x8005861C: nop

            goto L_800586D4;
    }
    // 0x8005861C: nop

    // 0x80058620: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80058624: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80058628: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x8005862C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058630: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80058634: nop

    // 0x80058638: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8005863C: nop

    // 0x80058640: bc1f        L_800586D4
    if (!c1cs) {
        // 0x80058644: nop

            goto L_800586D4;
    }
    // 0x80058644: nop

    // 0x80058648: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8005864C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80058650: jal         0x80052508
    // 0x80058654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_22;
    // 0x80058654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80058658: beq         $v0, $zero, L_800586D4
    if (ctx->r2 == 0) {
        // 0x8005865C: nop

            goto L_800586D4;
    }
    // 0x8005865C: nop

    // 0x80058660: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80058664: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80058668: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8005866C: lh          $a1, 0x42($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X42);
    // 0x80058670: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    // 0x80058674: jal         0x8004EF90
    // 0x80058678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_23;
    // 0x80058678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x8005867C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058680: nop

    // 0x80058684: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80058688: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005868C: nop

    // 0x80058690: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80058694: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80058698: nop

    // 0x8005869C: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x800586A0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800586A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800586A8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800586AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800586B0: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800586B4: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x800586B8: and         $t2, $t6, $at
    ctx->r10 = ctx->r14 & ctx->r1;
    // 0x800586BC: lw          $t7, 0x4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4);
    // 0x800586C0: lui         $at, 0xFEFF
    ctx->r1 = S32(0XFEFF << 16);
    // 0x800586C4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800586C8: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x800586CC: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x800586D0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_800586D4:
    // 0x800586D4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800586D8: nop

    // 0x800586DC: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x800586E0: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800586E4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800586E8: jal         0x800499B0
    // 0x800586EC: nop

    func_800499B0(rdram, ctx);
        goto after_24;
    // 0x800586EC: nop

    after_24:
    // 0x800586F0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800586F4: nop

    // 0x800586F8: bne         $t5, $zero, L_80058768
    if (ctx->r13 != 0) {
        // 0x800586FC: nop

            goto L_80058768;
    }
    // 0x800586FC: nop

    // 0x80058700: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80058704: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80058708: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x8005870C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80058710: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80058714: nop

    // 0x80058718: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x8005871C: nop

    // 0x80058720: bc1f        L_80058768
    if (!c1cs) {
        // 0x80058724: nop

            goto L_80058768;
    }
    // 0x80058724: nop

    // 0x80058728: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8005872C: nop

    // 0x80058730: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80058734: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80058738: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005873C: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x80058740: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x80058744: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058748: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005874C: nop

    // 0x80058750: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80058754: nop

    // 0x80058758: bc1f        L_80058768
    if (!c1cs) {
        // 0x8005875C: nop

            goto L_80058768;
    }
    // 0x8005875C: nop

    // 0x80058760: jal         0x8005F0DC
    // 0x80058764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F0DC(rdram, ctx);
        goto after_25;
    // 0x80058764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_25:
L_80058768:
    // 0x80058768: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005876C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80058770: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80058774: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80058778: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8005877C: nop

    // 0x80058780: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80058784: nop

    // 0x80058788: bc1t        L_80057FEC
    if (c1cs) {
        // 0x8005878C: nop

            goto L_80057FEC;
    }
    // 0x8005878C: nop

    // 0x80058790: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80058794: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80058798: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8005879C: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800587A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800587A4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800587A8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800587AC: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x800587B0: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800587B4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800587B8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800587BC: nop

    // 0x800587C0: sb          $zero, 0x20($t8)
    MEM_B(0X20, ctx->r24) = 0;
    // 0x800587C4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800587C8: nop

    // 0x800587CC: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x800587D0: jal         0x80098AD8
    // 0x800587D4: nop

    func_80098AD8(rdram, ctx);
        goto after_26;
    // 0x800587D4: nop

    after_26:
    // 0x800587D8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800587DC: jal         0x80049544
    // 0x800587E0: nop

    func_80049544(rdram, ctx);
        goto after_27;
    // 0x800587E0: nop

    after_27:
    // 0x800587E4: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800587E8: nop

    // 0x800587EC: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800587F0: jal         0x800C0D34
    // 0x800587F4: nop

    Thread_StopThread(rdram, ctx);
        goto after_28;
    // 0x800587F4: nop

    after_28:
L_800587F8:
    // 0x800587F8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800587FC: jal         0x800499B0
    // 0x80058800: nop

    func_800499B0(rdram, ctx);
        goto after_29;
    // 0x80058800: nop

    after_29:
    // 0x80058804: b           L_800587F8
    // 0x80058808: nop

        goto L_800587F8;
    // 0x80058808: nop

    // 0x8005880C: b           L_80058814
    // 0x80058810: nop

        goto L_80058814;
    // 0x80058810: nop

L_80058814:
    // 0x80058814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80058818: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005881C: jr          $ra
    // 0x80058820: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80058820: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80058824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005882C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80058830: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80058834: nop

    // 0x80058838: beq         $t6, $zero, L_80058B34
    if (ctx->r14 == 0) {
        // 0x8005883C: nop

            goto L_80058B34;
    }
    // 0x8005883C: nop

    // 0x80058840: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80058844: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80058848: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005884C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80058850: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80058854: bne         $t0, $zero, L_80058864
    if (ctx->r8 != 0) {
        // 0x80058858: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_80058864;
    }
    // 0x80058858: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005885C: beq         $t1, $zero, L_80058B34
    if (ctx->r9 == 0) {
        // 0x80058860: nop

            goto L_80058B34;
    }
    // 0x80058860: nop

L_80058864:
    // 0x80058864: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x80058868: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x8005886C: andi        $t2, $t7, 0x1FFF
    ctx->r10 = ctx->r15 & 0X1FFF;
    // 0x80058870: bne         $t2, $at, L_80058B34
    if (ctx->r10 != ctx->r1) {
        // 0x80058874: nop

            goto L_80058B34;
    }
    // 0x80058874: nop

    // 0x80058878: lw          $t3, 0x5C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X5C);
    // 0x8005887C: nop

    // 0x80058880: beq         $t3, $zero, L_80058B34
    if (ctx->r11 == 0) {
        // 0x80058884: nop

            goto L_80058B34;
    }
    // 0x80058884: nop

    // 0x80058888: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8005888C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80058890: bne         $t4, $at, L_80058B34
    if (ctx->r12 != ctx->r1) {
        // 0x80058894: nop

            goto L_80058B34;
    }
    // 0x80058894: nop

    // 0x80058898: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005889C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800588A0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800588A4: lw          $t8, 0x50($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X50);
    // 0x800588A8: nop

    // 0x800588AC: lbu         $t9, 0x30($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X30);
    // 0x800588B0: nop

    // 0x800588B4: bne         $t9, $at, L_80058B34
    if (ctx->r25 != ctx->r1) {
        // 0x800588B8: nop

            goto L_80058B34;
    }
    // 0x800588B8: nop

    // 0x800588BC: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x800588C0: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x800588C4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800588C8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800588CC: bne         $t2, $zero, L_80058B34
    if (ctx->r10 != 0) {
        // 0x800588D0: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80058B34;
    }
    // 0x800588D0: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800588D4: bne         $t3, $zero, L_80058B34
    if (ctx->r11 != 0) {
        // 0x800588D8: nop

            goto L_80058B34;
    }
    // 0x800588D8: nop

    // 0x800588DC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800588E0: addiu       $t7, $t7, 0xE80
    ctx->r15 = ADD32(ctx->r15, 0XE80);
    // 0x800588E4: lw          $t6, 0x1C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X1C);
    // 0x800588E8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800588EC: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x800588F0: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x800588F4: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x800588F8: bne         $t8, $zero, L_80058B34
    if (ctx->r24 != 0) {
        // 0x800588FC: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_80058B34;
    }
    // 0x800588FC: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80058900: bne         $t9, $zero, L_80058B34
    if (ctx->r25 != 0) {
        // 0x80058904: nop

            goto L_80058B34;
    }
    // 0x80058904: nop

    // 0x80058908: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005890C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80058910: nop

    // 0x80058914: lw          $t1, 0x98($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X98);
    // 0x80058918: nop

    // 0x8005891C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80058920: bne         $t2, $zero, L_8005894C
    if (ctx->r10 != 0) {
        // 0x80058924: nop

            goto L_8005894C;
    }
    // 0x80058924: nop

    // 0x80058928: jal         0x800B9000
    // 0x8005892C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x8005892C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_0:
    // 0x80058930: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80058934: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80058938: nop

    // 0x8005893C: lw          $t7, 0x98($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X98);
    // 0x80058940: nop

    // 0x80058944: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x80058948: sw          $t6, 0x98($t3)
    MEM_W(0X98, ctx->r11) = ctx->r14;
L_8005894C:
    // 0x8005894C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80058950: addiu       $t4, $t4, 0x2BB0
    ctx->r12 = ADD32(ctx->r12, 0X2BB0);
    // 0x80058954: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80058958: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005895C: nop

    // 0x80058960: beq         $t5, $zero, L_80058B34
    if (ctx->r13 == 0) {
        // 0x80058964: nop

            goto L_80058B34;
    }
    // 0x80058964: nop

    // 0x80058968: lbu         $t8, 0x1($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X1);
    // 0x8005896C: nop

    // 0x80058970: beq         $t8, $zero, L_80058B34
    if (ctx->r24 == 0) {
        // 0x80058974: nop

            goto L_80058B34;
    }
    // 0x80058974: nop

L_80058978:
    // 0x80058978: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005897C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80058980: addiu       $t0, $t0, 0x2BB0
    ctx->r8 = ADD32(ctx->r8, 0X2BB0);
    // 0x80058984: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80058988: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8005898C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80058990: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80058994: nop

    // 0x80058998: bne         $t2, $t7, L_80058AFC
    if (ctx->r10 != ctx->r15) {
        // 0x8005899C: nop

            goto L_80058AFC;
    }
    // 0x8005899C: nop

    // 0x800589A0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800589A4: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x800589A8: lbu         $t6, 0x1($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1);
    // 0x800589AC: nop

    // 0x800589B0: bne         $t6, $t3, L_80058AFC
    if (ctx->r14 != ctx->r11) {
        // 0x800589B4: nop

            goto L_80058AFC;
    }
    // 0x800589B4: nop

    // 0x800589B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800589BC: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800589C0: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800589C4: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800589C8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800589CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800589D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800589D4: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800589D8: nop

    // 0x800589DC: bc1f        L_800589EC
    if (!c1cs) {
        // 0x800589E0: nop

            goto L_800589EC;
    }
    // 0x800589E0: nop

    // 0x800589E4: b           L_80058A60
    // 0x800589E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
        goto L_80058A60;
    // 0x800589E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800589EC:
    // 0x800589EC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800589F0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800589F4: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800589F8: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800589FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80058A00: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80058A04: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80058A08: nop

    // 0x80058A0C: bc1f        L_80058A20
    if (!c1cs) {
        // 0x80058A10: nop

            goto L_80058A20;
    }
    // 0x80058A10: nop

    // 0x80058A14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80058A18: b           L_80058A60
    // 0x80058A1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_80058A60;
    // 0x80058A1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_80058A20:
    // 0x80058A20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058A24: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80058A28: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80058A2C: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80058A30: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80058A34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058A38: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80058A3C: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80058A40: nop

    // 0x80058A44: bc1f        L_80058A58
    if (!c1cs) {
        // 0x80058A48: nop

            goto L_80058A58;
    }
    // 0x80058A48: nop

    // 0x80058A4C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80058A50: b           L_80058A60
    // 0x80058A54: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
        goto L_80058A60;
    // 0x80058A54: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_80058A58:
    // 0x80058A58: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80058A5C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_80058A60:
    // 0x80058A60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80058A64: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80058A68: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80058A6C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80058A70: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80058A74: lw          $t7, 0x4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4);
    // 0x80058A78: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80058A7C: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x80058A80: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80058A84: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80058A88: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80058A8C: lw          $t3, 0x670($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X670);
    // 0x80058A90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80058A94: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80058A98: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80058A9C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80058AA0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80058AA4: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80058AA8: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x80058AAC: lbu         $t6, 0x2BB2($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2BB2);
    // 0x80058AB0: mflo        $t8
    ctx->r24 = lo;
    // 0x80058AB4: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80058AB8: beq         $at, $zero, L_80058AFC
    if (ctx->r1 == 0) {
        // 0x80058ABC: nop

            goto L_80058AFC;
    }
    // 0x80058ABC: nop

    // 0x80058AC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80058AC4: addiu       $t7, $t7, 0xE80
    ctx->r15 = ADD32(ctx->r15, 0XE80);
    // 0x80058AC8: lw          $t4, 0x1C($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X1C);
    // 0x80058ACC: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80058AD0: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80058AD4: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x80058AD8: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80058ADC: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x80058AE0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80058AE4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80058AE8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80058AEC: lw          $t5, -0x794($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X794);
    // 0x80058AF0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80058AF4: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80058AF8: sw          $t9, -0x794($at)
    MEM_W(-0X794, ctx->r1) = ctx->r25;
L_80058AFC:
    // 0x80058AFC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80058B00: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80058B04: addiu       $t6, $t8, 0x6
    ctx->r14 = ADD32(ctx->r24, 0X6);
    // 0x80058B08: addiu       $t7, $t7, 0x2BB0
    ctx->r15 = ADD32(ctx->r15, 0X2BB0);
    // 0x80058B0C: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x80058B10: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80058B14: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80058B18: nop

    // 0x80058B1C: beq         $t1, $zero, L_80058B34
    if (ctx->r9 == 0) {
        // 0x80058B20: nop

            goto L_80058B34;
    }
    // 0x80058B20: nop

    // 0x80058B24: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x80058B28: nop

    // 0x80058B2C: bne         $t2, $zero, L_80058978
    if (ctx->r10 != 0) {
        // 0x80058B30: nop

            goto L_80058978;
    }
    // 0x80058B30: nop

L_80058B34:
    // 0x80058B34: b           L_80058B3C
    // 0x80058B38: nop

        goto L_80058B3C;
    // 0x80058B38: nop

L_80058B3C:
    // 0x80058B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058B40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058B44: jr          $ra
    // 0x80058B48: nop

    return;
    // 0x80058B48: nop

;}
RECOMP_FUNC void func_80058B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80058B50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058B54: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80058B58: addiu       $t6, $t6, 0xE80
    ctx->r14 = ADD32(ctx->r14, 0XE80);
    // 0x80058B5C: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80058B60: nop

    // 0x80058B64: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80058B68: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80058B6C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80058B70: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80058B74: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80058B78: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80058B7C: bne         $t2, $zero, L_80058B8C
    if (ctx->r10 != 0) {
        // 0x80058B80: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80058B8C;
    }
    // 0x80058B80: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80058B84: beq         $t3, $zero, L_80058E60
    if (ctx->r11 == 0) {
        // 0x80058B88: nop

            goto L_80058E60;
    }
    // 0x80058B88: nop

L_80058B8C:
    // 0x80058B8C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80058B90: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80058B94: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80058B98: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80058B9C: bne         $t6, $zero, L_80058CE8
    if (ctx->r14 != 0) {
        // 0x80058BA0: andi        $t7, $t5, 0x1
        ctx->r15 = ctx->r13 & 0X1;
            goto L_80058CE8;
    }
    // 0x80058BA0: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80058BA4: bne         $t7, $zero, L_80058CE8
    if (ctx->r15 != 0) {
        // 0x80058BA8: nop

            goto L_80058CE8;
    }
    // 0x80058BA8: nop

    // 0x80058BAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80058BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058BB4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80058BB8: nop

    // 0x80058BBC: swc1        $f4, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f4.u32l;
    // 0x80058BC0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80058BC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058BC8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80058BCC: nop

    // 0x80058BD0: swc1        $f6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f6.u32l;
    // 0x80058BD4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80058BD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058BDC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80058BE0: nop

    // 0x80058BE4: swc1        $f8, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f8.u32l;
    // 0x80058BE8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80058BEC: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80058BF0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80058BF4: lwc1        $f10, 0x10($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80058BF8: nop

    // 0x80058BFC: swc1        $f10, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f10.u32l;
    // 0x80058C00: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058C04: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80058C08: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80058C0C: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80058C10: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80058C14: bne         $t6, $zero, L_80058C24
    if (ctx->r14 != 0) {
        // 0x80058C18: andi        $t7, $t5, 0x8
        ctx->r15 = ctx->r13 & 0X8;
            goto L_80058C24;
    }
    // 0x80058C18: andi        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 & 0X8;
    // 0x80058C1C: beq         $t7, $zero, L_80058C68
    if (ctx->r15 == 0) {
        // 0x80058C20: nop

            goto L_80058C68;
    }
    // 0x80058C20: nop

L_80058C24:
    // 0x80058C24: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80058C28: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80058C2C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80058C30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80058C34: lwc1        $f16, 0xC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80058C38: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80058C3C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80058C40: swc1        $f4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f4.u32l;
    // 0x80058C44: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80058C48: nop

    // 0x80058C4C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80058C50: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80058C54: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x80058C58: ori         $t5, $t3, 0x8
    ctx->r13 = ctx->r11 | 0X8;
    // 0x80058C5C: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80058C60: b           L_80058CAC
    // 0x80058C64: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80058CAC;
    // 0x80058C64: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80058C68:
    // 0x80058C68: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058C6C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80058C70: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80058C74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058C78: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80058C7C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80058C80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80058C84: swc1        $f10, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f10.u32l;
    // 0x80058C88: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80058C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058C90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80058C94: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80058C98: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80058C9C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80058CA0: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80058CA4: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x80058CA8: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
L_80058CAC:
    // 0x80058CAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80058CB0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80058CB4: addiu       $a2, $zero, 0x143
    ctx->r6 = ADD32(0, 0X143);
    // 0x80058CB8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80058CBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80058CC0: jal         0x8004F3E8
    // 0x80058CC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004F3E8(rdram, ctx);
        goto after_0;
    // 0x80058CC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x80058CC8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80058CCC: nop

    // 0x80058CD0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80058CD4: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80058CD8: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x80058CDC: ori         $t7, $t5, 0x1
    ctx->r15 = ctx->r13 | 0X1;
    // 0x80058CE0: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80058CE4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_80058CE8:
    // 0x80058CE8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80058CEC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80058CF0: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80058CF4: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80058CF8: bne         $t0, $zero, L_80058D08
    if (ctx->r8 != 0) {
        // 0x80058CFC: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_80058D08;
    }
    // 0x80058CFC: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x80058D00: beq         $t1, $zero, L_80058D2C
    if (ctx->r9 == 0) {
        // 0x80058D04: nop

            goto L_80058D2C;
    }
    // 0x80058D04: nop

L_80058D08:
    // 0x80058D08: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80058D0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D10: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D14: lwc1        $f16, 0x24($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X24);
    // 0x80058D18: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80058D1C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80058D20: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80058D24: b           L_80058D4C
    // 0x80058D28: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
        goto L_80058D4C;
    // 0x80058D28: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
L_80058D2C:
    // 0x80058D2C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80058D30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D34: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D38: lwc1        $f10, 0x24($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X24);
    // 0x80058D3C: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80058D40: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80058D44: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80058D48: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
L_80058D4C:
    // 0x80058D4C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80058D50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D54: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D58: lwc1        $f8, 0x28($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80058D5C: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80058D60: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80058D64: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80058D68: swc1        $f18, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f18.u32l;
    // 0x80058D6C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80058D70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D74: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D78: lwc1        $f4, 0x30($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X30);
    // 0x80058D7C: lwc1        $f6, 0x28($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X28);
    // 0x80058D80: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80058D84: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80058D88: swc1        $f16, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f16.u32l;
    // 0x80058D8C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80058D90: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80058D94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D98: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D9C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80058DA0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80058DA4: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80058DA8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80058DAC: nop

    // 0x80058DB0: lwc1        $f10, 0x20($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80058DB4: nop

    // 0x80058DB8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80058DBC: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x80058DC0: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80058DC4: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
    // 0x80058DC8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80058DCC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80058DD0: lwc1        $f8, 0x20($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80058DD4: lwc1        $f17, -0xEB0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XEB0);
    // 0x80058DD8: lwc1        $f16, -0xEAC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEAC);
    // 0x80058DDC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80058DE0: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80058DE4: nop

    // 0x80058DE8: bc1f        L_80058E14
    if (!c1cs) {
        // 0x80058DEC: nop

            goto L_80058E14;
    }
    // 0x80058DEC: nop

    // 0x80058DF0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80058DF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80058DF8: lwc1        $f6, 0x20($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80058DFC: lwc1        $f19, -0xEA8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XEA8);
    // 0x80058E00: lwc1        $f18, -0xEA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEA4);
    // 0x80058E04: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80058E08: sub.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
    // 0x80058E0C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80058E10: swc1        $f10, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f10.u32l;
L_80058E14:
    // 0x80058E14: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80058E18: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x80058E1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058E20: lwc1        $f16, 0x10($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80058E24: nop

    // 0x80058E28: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80058E2C: nop

    // 0x80058E30: bc1f        L_80058E60
    if (!c1cs) {
        // 0x80058E34: nop

            goto L_80058E60;
    }
    // 0x80058E34: nop

    // 0x80058E38: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80058E3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058E40: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80058E44: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80058E48: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80058E4C: lui         $at, 0xFF7F
    ctx->r1 = S32(0XFF7F << 16);
    // 0x80058E50: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x80058E54: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80058E58: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80058E5C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_80058E60:
    // 0x80058E60: b           L_80058E68
    // 0x80058E64: nop

        goto L_80058E68;
    // 0x80058E64: nop

L_80058E68:
    // 0x80058E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80058E6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80058E70: jr          $ra
    // 0x80058E74: nop

    return;
    // 0x80058E74: nop

;}
RECOMP_FUNC void func_80058E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058E78: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80058E7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80058E80: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80058E84: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80058E88: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_80058E8C:
    // 0x80058E8C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80058E90: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058E94: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80058E98: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80058E9C: lw          $t9, 0xE80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE80);
    // 0x80058EA0: nop

    // 0x80058EA4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80058EA8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80058EAC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80058EB0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80058EB4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80058EB8: bne         $t4, $zero, L_80058EC8
    if (ctx->r12 != 0) {
        // 0x80058EBC: andi        $t5, $t3, 0x1
        ctx->r13 = ctx->r11 & 0X1;
            goto L_80058EC8;
    }
    // 0x80058EBC: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x80058EC0: beq         $t5, $zero, L_80059B70
    if (ctx->r13 == 0) {
        // 0x80058EC4: nop

            goto L_80059B70;
    }
    // 0x80058EC4: nop

L_80058EC8:
    // 0x80058EC8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80058ECC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80058ED0: nop

    // 0x80058ED4: beq         $t1, $zero, L_80059480
    if (ctx->r9 == 0) {
        // 0x80058ED8: nop

            goto L_80059480;
    }
    // 0x80058ED8: nop

    // 0x80058EDC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80058EE0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80058EE4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80058EE8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80058EEC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80058EF0: bne         $t0, $zero, L_80059480
    if (ctx->r8 != 0) {
        // 0x80058EF4: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_80059480;
    }
    // 0x80058EF4: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80058EF8: bne         $t1, $zero, L_80059480
    if (ctx->r9 != 0) {
        // 0x80058EFC: nop

            goto L_80059480;
    }
    // 0x80058EFC: nop

    // 0x80058F00: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80058F04: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80058F08: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x80058F0C: lui         $at, 0x44
    ctx->r1 = S32(0X44 << 16);
    // 0x80058F10: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80058F14: bne         $t4, $zero, L_80059000
    if (ctx->r12 != 0) {
        // 0x80058F18: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_80059000;
    }
    // 0x80058F18: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80058F1C: bne         $t5, $zero, L_80059000
    if (ctx->r13 != 0) {
        // 0x80058F20: nop

            goto L_80059000;
    }
    // 0x80058F20: nop

    // 0x80058F24: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80058F28: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80058F2C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80058F30: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80058F34: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x80058F38: or          $t7, $t1, $zero
    ctx->r15 = ctx->r9 | 0;
    // 0x80058F3C: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x80058F40: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80058F44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058F48: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80058F4C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80058F50: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80058F54: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80058F58: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80058F5C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80058F60: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80058F64: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80058F68: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80058F6C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80058F70: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80058F74: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80058F78: nop

    // 0x80058F7C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80058F80: nop

    // 0x80058F84: bc1f        L_80058FAC
    if (!c1cs) {
        // 0x80058F88: nop

            goto L_80058FAC;
    }
    // 0x80058F88: nop

    // 0x80058F8C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80058F90: nop

    // 0x80058F94: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80058F98: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80058F9C: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80058FA0: ori         $t5, $t1, 0x8
    ctx->r13 = ctx->r9 | 0X8;
    // 0x80058FA4: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x80058FA8: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
L_80058FAC:
    // 0x80058FAC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80058FB0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80058FB4: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80058FB8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80058FBC: sra         $t0, $t7, 31
    ctx->r8 = S32(SIGNED(ctx->r15) >> 31);
    // 0x80058FC0: xor         $t4, $t8, $t0
    ctx->r12 = ctx->r24 ^ ctx->r8;
    // 0x80058FC4: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80058FC8: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80058FCC: andi        $t9, $t3, 0x8
    ctx->r25 = ctx->r11 & 0X8;
    // 0x80058FD0: bne         $t4, $zero, L_80058FE0
    if (ctx->r12 != 0) {
        // 0x80058FD4: xor         $t5, $t9, $t1
        ctx->r13 = ctx->r25 ^ ctx->r9;
            goto L_80058FE0;
    }
    // 0x80058FD4: xor         $t5, $t9, $t1
    ctx->r13 = ctx->r25 ^ ctx->r9;
    // 0x80058FD8: beq         $t5, $zero, L_80059000
    if (ctx->r13 == 0) {
        // 0x80058FDC: nop

            goto L_80059000;
    }
    // 0x80058FDC: nop

L_80058FE0:
    // 0x80058FE0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80058FE4: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80058FE8: lh          $a1, 0x7C($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X7C);
    // 0x80058FEC: lw          $a3, 0x44($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X44);
    // 0x80058FF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80058FF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80058FF8: jal         0x8004F3E8
    // 0x80058FFC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8004F3E8(rdram, ctx);
        goto after_0;
    // 0x80058FFC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
L_80059000:
    // 0x80059000: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80059004: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80059008: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005900C: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80059010: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80059014: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80059018: bne         $t0, $zero, L_80059114
    if (ctx->r8 != 0) {
        // 0x8005901C: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_80059114;
    }
    // 0x8005901C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80059020: bne         $t1, $zero, L_80059114
    if (ctx->r9 != 0) {
        // 0x80059024: nop

            goto L_80059114;
    }
    // 0x80059024: nop

    // 0x80059028: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005902C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80059030: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80059034: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x80059038: lw          $a1, 0x4C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4C);
    // 0x8005903C: lw          $a2, 0x50($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X50);
    // 0x80059040: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80059044: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x80059048: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8005904C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80059050: lw          $t6, 0x50($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X50);
    // 0x80059054: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80059058: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005905C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80059060: jal         0x800784E8
    // 0x80059064: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800784E8(rdram, ctx);
        goto after_1;
    // 0x80059064: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_1:
    // 0x80059068: beq         $v0, $zero, L_80059114
    if (ctx->r2 == 0) {
        // 0x8005906C: nop

            goto L_80059114;
    }
    // 0x8005906C: nop

    // 0x80059070: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80059074: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x80059078: lh          $t9, 0x7C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X7C);
    // 0x8005907C: nop

    // 0x80059080: bne         $t9, $at, L_80059090
    if (ctx->r25 != ctx->r1) {
        // 0x80059084: nop

            goto L_80059090;
    }
    // 0x80059084: nop

    // 0x80059088: b           L_80059094
    // 0x8005908C: addiu       $s0, $zero, 0x32
    ctx->r16 = ADD32(0, 0X32);
        goto L_80059094;
    // 0x8005908C: addiu       $s0, $zero, 0x32
    ctx->r16 = ADD32(0, 0X32);
L_80059090:
    // 0x80059090: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
L_80059094:
    // 0x80059094: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80059098: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8005909C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800590A0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800590A4: nop

    // 0x800590A8: subu        $t3, $t1, $s0
    ctx->r11 = SUB32(ctx->r9, ctx->r16);
    // 0x800590AC: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x800590B0: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800590B4: nop

    // 0x800590B8: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800590BC: nop

    // 0x800590C0: bgez        $t5, L_800590D8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800590C4: nop

            goto L_800590D8;
    }
    // 0x800590C4: nop

    // 0x800590C8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800590CC: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x800590D0: nop

    // 0x800590D4: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
L_800590D8:
    // 0x800590D8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800590DC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800590E0: jal         0x8005C90C
    // 0x800590E4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_8005C90C(rdram, ctx);
        goto after_2;
    // 0x800590E4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x800590E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800590EC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800590F0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800590F4: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x800590F8: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x800590FC: or          $t8, $t2, $zero
    ctx->r24 = ctx->r10 | 0;
    // 0x80059100: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x80059104: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80059108: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8005910C: jal         0x800B9000
    // 0x80059110: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x80059110: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_3:
L_80059114:
    // 0x80059114: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80059118: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005911C: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80059120: lw          $t1, 0x4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4);
    // 0x80059124: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80059128: bne         $t4, $zero, L_80059480
    if (ctx->r12 != 0) {
        // 0x8005912C: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_80059480;
    }
    // 0x8005912C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80059130: bne         $t5, $zero, L_80059480
    if (ctx->r13 != 0) {
        // 0x80059134: nop

            goto L_80059480;
    }
    // 0x80059134: nop

    // 0x80059138: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005913C: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x80059140: nop

    // 0x80059144: beq         $t7, $zero, L_80059480
    if (ctx->r15 == 0) {
        // 0x80059148: nop

            goto L_80059480;
    }
    // 0x80059148: nop

    // 0x8005914C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80059150: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80059154: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80059158: lw          $t2, 0x306C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X306C);
    // 0x8005915C: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x80059160: beq         $t2, $zero, L_80059480
    if (ctx->r10 == 0) {
        // 0x80059164: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_80059480;
    }
    // 0x80059164: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80059168: beq         $t3, $zero, L_80059480
    if (ctx->r11 == 0) {
        // 0x8005916C: nop

            goto L_80059480;
    }
    // 0x8005916C: nop

L_80059170:
    // 0x80059170: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80059174: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80059178: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8005917C: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80059180: nop

    // 0x80059184: bne         $t9, $t6, L_80059458
    if (ctx->r25 != ctx->r14) {
        // 0x80059188: nop

            goto L_80059458;
    }
    // 0x80059188: nop

    // 0x8005918C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80059190: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x80059194: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x80059198: nop

    // 0x8005919C: bne         $t0, $t1, L_80059458
    if (ctx->r8 != ctx->r9) {
        // 0x800591A0: nop

            goto L_80059458;
    }
    // 0x800591A0: nop

    // 0x800591A4: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800591A8: nop

    // 0x800591AC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800591B0: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x800591B4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800591B8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800591BC: lbu         $t2, 0x10($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X10);
    // 0x800591C0: nop

    // 0x800591C4: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800591C8: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x800591CC: lw          $t9, 0x24F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X24F4);
    // 0x800591D0: nop

    // 0x800591D4: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800591D8: nop

    // 0x800591DC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800591E0: nop

    // 0x800591E4: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800591E8: sh          $t0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r8;
    // 0x800591EC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800591F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800591F4: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x800591F8: nop

    // 0x800591FC: bne         $t4, $at, L_80059214
    if (ctx->r12 != ctx->r1) {
        // 0x80059200: nop

            goto L_80059214;
    }
    // 0x80059200: nop

    // 0x80059204: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80059208: addiu       $at, $zero, 0x151
    ctx->r1 = ADD32(0, 0X151);
    // 0x8005920C: beq         $t5, $at, L_80059264
    if (ctx->r13 == ctx->r1) {
        // 0x80059210: nop

            goto L_80059264;
    }
    // 0x80059210: nop

L_80059214:
    // 0x80059214: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80059218: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005921C: lh          $t2, 0x0($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X0);
    // 0x80059220: nop

    // 0x80059224: bne         $t2, $at, L_8005923C
    if (ctx->r10 != ctx->r1) {
        // 0x80059228: nop

            goto L_8005923C;
    }
    // 0x80059228: nop

    // 0x8005922C: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x80059230: addiu       $at, $zero, 0x154
    ctx->r1 = ADD32(0, 0X154);
    // 0x80059234: beq         $t3, $at, L_80059264
    if (ctx->r11 == ctx->r1) {
        // 0x80059238: nop

            goto L_80059264;
    }
    // 0x80059238: nop

L_8005923C:
    // 0x8005923C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80059240: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80059244: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80059248: nop

    // 0x8005924C: bne         $t6, $at, L_80059458
    if (ctx->r14 != ctx->r1) {
        // 0x80059250: nop

            goto L_80059458;
    }
    // 0x80059250: nop

    // 0x80059254: lh          $t8, 0x6($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X6);
    // 0x80059258: nop

    // 0x8005925C: bne         $t8, $zero, L_80059458
    if (ctx->r24 != 0) {
        // 0x80059260: nop

            goto L_80059458;
    }
    // 0x80059260: nop

L_80059264:
    // 0x80059264: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80059268: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8005926C: lbu         $t1, 0x10($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X10);
    // 0x80059270: addiu       $t5, $t5, 0x24D8
    ctx->r13 = ADD32(ctx->r13, 0X24D8);
    // 0x80059274: sll         $t4, $t1, 5
    ctx->r12 = S32(ctx->r9 << 5);
    // 0x80059278: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8005927C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80059280: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x80059284: lw          $a2, 0x1C($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X1C);
    // 0x80059288: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    // 0x8005928C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80059290: lw          $t6, 0x4C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4C);
    // 0x80059294: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80059298: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005929C: lw          $t9, 0x50($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X50);
    // 0x800592A0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800592A4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800592A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800592AC: jal         0x800784E8
    // 0x800592B0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_800784E8(rdram, ctx);
        goto after_4;
    // 0x800592B0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_4:
    // 0x800592B4: beq         $v0, $zero, L_80059458
    if (ctx->r2 == 0) {
        // 0x800592B8: nop

            goto L_80059458;
    }
    // 0x800592B8: nop

    // 0x800592BC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800592C0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800592C4: jal         0x8005C90C
    // 0x800592C8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_8005C90C(rdram, ctx);
        goto after_5;
    // 0x800592C8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x800592CC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800592D0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800592D4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800592D8: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x800592DC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800592E0: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x800592E4: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x800592E8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800592EC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800592F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800592F4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800592F8: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x800592FC: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80059300: lui         $at, 0xFFBF
    ctx->r1 = S32(0XFFBF << 16);
    // 0x80059304: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80059308: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8005930C: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80059310: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80059314: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80059318: nop

    // 0x8005931C: lw          $t5, 0x88($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X88);
    // 0x80059320: nop

    // 0x80059324: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x80059328: sw          $t2, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->r10;
    // 0x8005932C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80059330: nop

    // 0x80059334: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80059338: nop

    // 0x8005933C: swc1        $f8, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f8.u32l;
    // 0x80059340: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80059344: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80059348: nop

    // 0x8005934C: swc1        $f10, 0xA0($t0)
    MEM_W(0XA0, ctx->r8) = ctx->f10.u32l;
    // 0x80059350: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80059354: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x80059358: lh          $t7, 0x7C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X7C);
    // 0x8005935C: nop

    // 0x80059360: bne         $t7, $at, L_80059370
    if (ctx->r15 != ctx->r1) {
        // 0x80059364: nop

            goto L_80059370;
    }
    // 0x80059364: nop

    // 0x80059368: b           L_80059374
    // 0x8005936C: addiu       $s0, $zero, 0xAF
    ctx->r16 = ADD32(0, 0XAF);
        goto L_80059374;
    // 0x8005936C: addiu       $s0, $zero, 0xAF
    ctx->r16 = ADD32(0, 0XAF);
L_80059370:
    // 0x80059370: addiu       $s0, $zero, 0x189
    ctx->r16 = ADD32(0, 0X189);
L_80059374:
    // 0x80059374: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80059378: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005937C: lh          $a1, 0x7C($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X7C);
    // 0x80059380: lw          $a3, 0x44($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X44);
    // 0x80059384: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80059388: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005938C: jal         0x8004F3E8
    // 0x80059390: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_8004F3E8(rdram, ctx);
        goto after_6;
    // 0x80059390: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_6:
    // 0x80059394: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80059398: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8005939C: lh          $t1, 0x7C($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X7C);
    // 0x800593A0: nop

    // 0x800593A4: bne         $t1, $at, L_800593B4
    if (ctx->r9 != ctx->r1) {
        // 0x800593A8: nop

            goto L_800593B4;
    }
    // 0x800593A8: nop

    // 0x800593AC: b           L_800593B8
    // 0x800593B0: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
        goto L_800593B8;
    // 0x800593B0: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
L_800593B4:
    // 0x800593B4: addiu       $s0, $zero, 0x13
    ctx->r16 = ADD32(0, 0X13);
L_800593B8:
    // 0x800593B8: jal         0x800B9000
    // 0x800593BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_7;
    // 0x800593BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800593C0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800593C4: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800593C8: nop

    // 0x800593CC: lh          $t2, 0x6($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X6);
    // 0x800593D0: nop

    // 0x800593D4: addiu       $t4, $t2, 0x14
    ctx->r12 = ADD32(ctx->r10, 0X14);
    // 0x800593D8: sh          $t4, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r12;
    // 0x800593DC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800593E0: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x800593E4: nop

    // 0x800593E8: lh          $t0, 0x6($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X6);
    // 0x800593EC: nop

    // 0x800593F0: slti        $at, $t0, 0x3E8
    ctx->r1 = SIGNED(ctx->r8) < 0X3E8 ? 1 : 0;
    // 0x800593F4: bne         $at, $zero, L_8005940C
    if (ctx->r1 != 0) {
        // 0x800593F8: nop

            goto L_8005940C;
    }
    // 0x800593F8: nop

    // 0x800593FC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80059400: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80059404: addiu       $t6, $zero, 0x3E7
    ctx->r14 = ADD32(0, 0X3E7);
    // 0x80059408: sh          $t6, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r14;
L_8005940C:
    // 0x8005940C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80059410: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80059414: nop

    // 0x80059418: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x8005941C: nop

    // 0x80059420: addiu       $t1, $t9, 0x14
    ctx->r9 = ADD32(ctx->r25, 0X14);
    // 0x80059424: sh          $t1, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r9;
    // 0x80059428: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005942C: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80059430: nop

    // 0x80059434: lh          $t4, 0x8($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X8);
    // 0x80059438: nop

    // 0x8005943C: slti        $at, $t4, 0x3E8
    ctx->r1 = SIGNED(ctx->r12) < 0X3E8 ? 1 : 0;
    // 0x80059440: bne         $at, $zero, L_80059458
    if (ctx->r1 != 0) {
        // 0x80059444: nop

            goto L_80059458;
    }
    // 0x80059444: nop

    // 0x80059448: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005944C: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80059450: addiu       $t5, $zero, 0x3E7
    ctx->r13 = ADD32(0, 0X3E7);
    // 0x80059454: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
L_80059458:
    // 0x80059458: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005945C: nop

    // 0x80059460: lw          $t6, 0x18($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X18);
    // 0x80059464: nop

    // 0x80059468: beq         $t6, $zero, L_80059480
    if (ctx->r14 == 0) {
        // 0x8005946C: sw          $t6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r14;
            goto L_80059480;
    }
    // 0x8005946C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80059470: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80059474: nop

    // 0x80059478: bne         $t7, $zero, L_80059170
    if (ctx->r15 != 0) {
        // 0x8005947C: nop

            goto L_80059170;
    }
    // 0x8005947C: nop

L_80059480:
    // 0x80059480: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80059484: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80059488: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8005948C: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x80059490: lui         $at, 0x444
    ctx->r1 = S32(0X444 << 16);
    // 0x80059494: bne         $t2, $zero, L_800595C8
    if (ctx->r10 != 0) {
        // 0x80059498: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_800595C8;
    }
    // 0x80059498: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x8005949C: bne         $t3, $zero, L_800595C8
    if (ctx->r11 != 0) {
        // 0x800594A0: nop

            goto L_800595C8;
    }
    // 0x800594A0: nop

    // 0x800594A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800594A8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800594AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800594B0: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800594B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800594B8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800594BC: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x800594C0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800594C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800594C8: lwc1        $f8, 0x34($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X34);
    // 0x800594CC: nop

    // 0x800594D0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800594D4: add.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f18.d = ctx->f10.d + ctx->f6.d;
    // 0x800594D8: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x800594DC: swc1        $f16, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f16.u32l;
    // 0x800594E0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800594E4: lwc1        $f10, -0xE9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE9C);
    // 0x800594E8: lwc1        $f4, 0x34($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X34);
    // 0x800594EC: lwc1        $f11, -0xEA0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XEA0);
    // 0x800594F0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800594F4: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x800594F8: nop

    // 0x800594FC: bc1f        L_80059528
    if (!c1cs) {
        // 0x80059500: nop

            goto L_80059528;
    }
    // 0x80059500: nop

    // 0x80059504: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80059508: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005950C: lwc1        $f6, 0x34($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X34);
    // 0x80059510: lwc1        $f17, -0xE98($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XE98);
    // 0x80059514: lwc1        $f16, -0xE94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XE94);
    // 0x80059518: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8005951C: sub.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = ctx->f18.d - ctx->f16.d;
    // 0x80059520: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80059524: swc1        $f8, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f8.u32l;
L_80059528:
    // 0x80059528: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005952C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80059530: lwc1        $f10, 0x34($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80059534: lwc1        $f19, -0xE90($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XE90);
    // 0x80059538: lwc1        $f18, -0xE8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XE8C);
    // 0x8005953C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80059540: mul.d       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x80059544: jal         0x800C3070
    // 0x80059548: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_8;
    // 0x80059548: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_8:
    // 0x8005954C: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80059550: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80059554: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x80059558: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005955C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80059560: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80059564: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80059568: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005956C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80059570: lwc1        $f18, 0x28($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80059574: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80059578: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8005957C: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x80059580: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80059584: nop

    // 0x80059588: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x8005958C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80059590: swc1        $f18, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f18.u32l;
    // 0x80059594: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80059598: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8005959C: lh          $t8, 0x7C($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X7C);
    // 0x800595A0: nop

    // 0x800595A4: beq         $t8, $at, L_800595B8
    if (ctx->r24 == ctx->r1) {
        // 0x800595A8: nop

            goto L_800595B8;
    }
    // 0x800595A8: nop

    // 0x800595AC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800595B0: jal         0x80059BA0
    // 0x800595B4: nop

    func_80059BA0(rdram, ctx);
        goto after_9;
    // 0x800595B4: nop

    after_9:
L_800595B8:
    // 0x800595B8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800595BC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800595C0: jal         0x8005D07C
    // 0x800595C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_10;
    // 0x800595C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_10:
L_800595C8:
    // 0x800595C8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800595CC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800595D0: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x800595D4: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x800595D8: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x800595DC: bne         $t4, $zero, L_800595EC
    if (ctx->r12 != 0) {
        // 0x800595E0: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_800595EC;
    }
    // 0x800595E0: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800595E4: beq         $t5, $zero, L_8005975C
    if (ctx->r13 == 0) {
        // 0x800595E8: nop

            goto L_8005975C;
    }
    // 0x800595E8: nop

L_800595EC:
    // 0x800595EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800595F0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800595F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800595F8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800595FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80059600: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80059604: mul.d       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80059608: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005960C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80059610: lwc1        $f10, 0x6C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x80059614: nop

    // 0x80059618: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005961C: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80059620: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80059624: swc1        $f16, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f16.u32l;
    // 0x80059628: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005962C: lwc1        $f18, -0xE84($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XE84);
    // 0x80059630: lwc1        $f8, 0x6C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X6C);
    // 0x80059634: lwc1        $f19, -0xE88($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XE88);
    // 0x80059638: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005963C: c.le.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d <= ctx->f10.d;
    // 0x80059640: nop

    // 0x80059644: bc1f        L_800596A8
    if (!c1cs) {
        // 0x80059648: nop

            goto L_800596A8;
    }
    // 0x80059648: nop

    // 0x8005964C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80059650: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80059654: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80059658: nop

    // 0x8005965C: swc1        $f4, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f4.u32l;
    // 0x80059660: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80059664: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059668: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005966C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80059670: and         $t2, $t8, $at
    ctx->r10 = ctx->r24 & ctx->r1;
    // 0x80059674: lui         $at, 0xFFBF
    ctx->r1 = S32(0XFFBF << 16);
    // 0x80059678: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005967C: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x80059680: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x80059684: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80059688: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005968C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80059690: lh          $a1, 0x7C($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X7C);
    // 0x80059694: lw          $a3, 0x44($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X44);
    // 0x80059698: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005969C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800596A0: jal         0x8004F3E8
    // 0x800596A4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_8004F3E8(rdram, ctx);
        goto after_11;
    // 0x800596A4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_11:
L_800596A8:
    // 0x800596A8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800596AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800596B0: lwc1        $f6, 0x6C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X6C);
    // 0x800596B4: lwc1        $f9, -0xE80($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XE80);
    // 0x800596B8: lwc1        $f8, -0xE7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE7C);
    // 0x800596BC: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x800596C0: mul.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x800596C4: jal         0x800C3070
    // 0x800596C8: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_12;
    // 0x800596C8: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_12:
    // 0x800596CC: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800596D0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800596D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800596D8: lwc1        $f18, 0x2C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x800596DC: nop

    // 0x800596E0: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x800596E4: nop

    // 0x800596E8: bc1t        L_800596F8
    if (c1cs) {
        // 0x800596EC: nop

            goto L_800596F8;
    }
    // 0x800596EC: nop

    // 0x800596F0: b           L_80059708
    // 0x800596F4: nop

        goto L_80059708;
    // 0x800596F4: nop

L_800596F8:
    // 0x800596F8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800596FC: nop

    // 0x80059700: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = -ctx->f6.fl;
    // 0x80059704: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
L_80059708:
    // 0x80059708: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8005970C: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80059710: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80059714: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80059718: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005971C: mul.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x80059720: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80059724: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80059728: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8005972C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80059730: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80059734: add.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = ctx->f16.d + ctx->f4.d;
    // 0x80059738: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005973C: nop

    // 0x80059740: sub.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = ctx->f10.d - ctx->f8.d;
    // 0x80059744: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80059748: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
    // 0x8005974C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80059750: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80059754: jal         0x8005D07C
    // 0x80059758: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_13;
    // 0x80059758: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_13:
L_8005975C:
    // 0x8005975C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80059760: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80059764: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80059768: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8005976C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80059770: bne         $t2, $zero, L_80059780
    if (ctx->r10 != 0) {
        // 0x80059774: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_80059780;
    }
    // 0x80059774: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x80059778: beq         $t3, $zero, L_8005996C
    if (ctx->r11 == 0) {
        // 0x8005977C: nop

            goto L_8005996C;
    }
    // 0x8005977C: nop

L_80059780:
    // 0x80059780: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80059784: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x80059788: lh          $t4, 0x7C($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X7C);
    // 0x8005978C: nop

    // 0x80059790: bne         $t4, $at, L_800597E4
    if (ctx->r12 != ctx->r1) {
        // 0x80059794: nop

            goto L_800597E4;
    }
    // 0x80059794: nop

    // 0x80059798: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8005979C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800597A0: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x800597A4: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x800597A8: bne         $t6, $zero, L_800597B8
    if (ctx->r14 != 0) {
        // 0x800597AC: andi        $t7, $t1, 0x2
        ctx->r15 = ctx->r9 & 0X2;
            goto L_800597B8;
    }
    // 0x800597AC: andi        $t7, $t1, 0x2
    ctx->r15 = ctx->r9 & 0X2;
    // 0x800597B0: beq         $t7, $zero, L_800597DC
    if (ctx->r15 == 0) {
        // 0x800597B4: nop

            goto L_800597DC;
    }
    // 0x800597B4: nop

L_800597B8:
    // 0x800597B8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800597BC: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800597C0: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x800597C4: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x800597C8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800597CC: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800597D0: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800597D4: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x800597D8: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
L_800597DC:
    // 0x800597DC: b           L_8005996C
    // 0x800597E0: nop

        goto L_8005996C;
    // 0x800597E0: nop

L_800597E4:
    // 0x800597E4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800597E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800597EC: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800597F0: lwc1        $f16, 0xA0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XA0);
    // 0x800597F4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800597F8: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800597FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80059800: swc1        $f10, 0xA0($t9)
    MEM_W(0XA0, ctx->r25) = ctx->f10.u32l;
    // 0x80059804: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80059808: nop

    // 0x8005980C: lwc1        $f8, 0xA0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XA0);
    // 0x80059810: nop

    // 0x80059814: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80059818: nop

    // 0x8005981C: bc1f        L_8005996C
    if (!c1cs) {
        // 0x80059820: nop

            goto L_8005996C;
    }
    // 0x80059820: nop

    // 0x80059824: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059828: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005982C: nop

    // 0x80059830: swc1        $f6, 0xA0($t1)
    MEM_W(0XA0, ctx->r9) = ctx->f6.u32l;
    // 0x80059834: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80059838: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005983C: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80059840: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80059844: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x80059848: lui         $at, 0xFBFF
    ctx->r1 = S32(0XFBFF << 16);
    // 0x8005984C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80059850: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80059854: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80059858: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8005985C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80059860: nop

    // 0x80059864: lw          $t8, 0x88($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X88);
    // 0x80059868: nop

    // 0x8005986C: sltiu       $at, $t8, 0x2
    ctx->r1 = ctx->r24 < 0X2 ? 1 : 0;
    // 0x80059870: bne         $at, $zero, L_800598CC
    if (ctx->r1 != 0) {
        // 0x80059874: nop

            goto L_800598CC;
    }
    // 0x80059874: nop

    // 0x80059878: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005987C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80059880: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80059884: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80059888: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8005988C: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x80059890: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80059894: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80059898: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005989C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800598A0: nop

    // 0x800598A4: swc1        $f16, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f16.u32l;
    // 0x800598A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800598AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800598B0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800598B4: nop

    // 0x800598B8: swc1        $f4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f4.u32l;
    // 0x800598BC: jal         0x800B9000
    // 0x800598C0: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_800B9000(rdram, ctx);
        goto after_14;
    // 0x800598C0: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_14:
    // 0x800598C4: b           L_8005996C
    // 0x800598C8: nop

        goto L_8005996C;
    // 0x800598C8: nop

L_800598CC:
    // 0x800598CC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800598D0: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x800598D4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800598D8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800598DC: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800598E0: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x800598E4: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x800598E8: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x800598EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800598F0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800598F4: nop

    // 0x800598F8: swc1        $f10, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f10.u32l;
    // 0x800598FC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80059900: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80059904: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80059908: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8005990C: lwc1        $f18, 0xC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80059910: nop

    // 0x80059914: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80059918: nop

    // 0x8005991C: bc1f        L_8005993C
    if (!c1cs) {
        // 0x80059920: nop

            goto L_8005993C;
    }
    // 0x80059920: nop

    // 0x80059924: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80059928: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8005992C: nop

    // 0x80059930: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80059934: b           L_8005994C
    // 0x80059938: swc1        $f16, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f16.u32l;
        goto L_8005994C;
    // 0x80059938: swc1        $f16, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f16.u32l;
L_8005993C:
    // 0x8005993C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80059940: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80059944: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059948: swc1        $f10, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->f10.u32l;
L_8005994C:
    // 0x8005994C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80059950: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x80059954: lh          $a1, 0x7C($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X7C);
    // 0x80059958: lw          $a3, 0x44($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X44);
    // 0x8005995C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80059960: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80059964: jal         0x8004F3E8
    // 0x80059968: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_8004F3E8(rdram, ctx);
        goto after_15;
    // 0x80059968: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_15:
L_8005996C:
    // 0x8005996C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80059970: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80059974: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80059978: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8005997C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80059980: bne         $t6, $zero, L_80059990
    if (ctx->r14 != 0) {
        // 0x80059984: and         $t7, $t1, $at
        ctx->r15 = ctx->r9 & ctx->r1;
            goto L_80059990;
    }
    // 0x80059984: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x80059988: beq         $t7, $zero, L_80059B70
    if (ctx->r15 == 0) {
        // 0x8005998C: nop

            goto L_80059B70;
    }
    // 0x8005998C: nop

L_80059990:
    // 0x80059990: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80059994: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80059998: lwc1        $f18, -0x71C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8005999C: lwc1        $f8, 0x10($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800599A0: nop

    // 0x800599A4: c.eq.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl == ctx->f18.fl;
    // 0x800599A8: nop

    // 0x800599AC: bc1t        L_80059A70
    if (c1cs) {
        // 0x800599B0: nop

            goto L_80059A70;
    }
    // 0x800599B0: nop

    // 0x800599B4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800599B8: nop

    // 0x800599BC: lwc1        $f6, 0x10($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800599C0: lwc1        $f16, 0x28($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X28);
    // 0x800599C4: nop

    // 0x800599C8: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800599CC: swc1        $f4, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f4.u32l;
    // 0x800599D0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800599D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800599D8: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800599DC: lwc1        $f10, 0x30($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X30);
    // 0x800599E0: lwc1        $f6, 0x28($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X28);
    // 0x800599E4: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800599E8: sub.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800599EC: swc1        $f16, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f16.u32l;
    // 0x800599F0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800599F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800599F8: jal         0x8005D07C
    // 0x800599FC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_16;
    // 0x800599FC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_16:
    // 0x80059A00: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80059A08: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x80059A0C: lwc1        $f4, 0x10($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X10);
    // 0x80059A10: nop

    // 0x80059A14: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x80059A18: nop

    // 0x80059A1C: bc1f        L_80059A68
    if (!c1cs) {
        // 0x80059A20: nop

            goto L_80059A68;
    }
    // 0x80059A20: nop

    // 0x80059A24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80059A28: lwc1        $f8, -0x71C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x80059A2C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A30: nop

    // 0x80059A34: swc1        $f8, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f8.u32l;
    // 0x80059A38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059A3C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A40: nop

    // 0x80059A44: swc1        $f6, 0xA0($t9)
    MEM_W(0XA0, ctx->r25) = ctx->f6.u32l;
    // 0x80059A48: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A4C: addiu       $a2, $zero, 0xAF
    ctx->r6 = ADD32(0, 0XAF);
    // 0x80059A50: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    // 0x80059A54: lw          $a3, 0x44($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X44);
    // 0x80059A58: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80059A5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80059A60: jal         0x8004F3E8
    // 0x80059A64: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_8004F3E8(rdram, ctx);
        goto after_17;
    // 0x80059A64: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_17:
L_80059A68:
    // 0x80059A68: b           L_80059B70
    // 0x80059A6C: nop

        goto L_80059B70;
    // 0x80059A6C: nop

L_80059A70:
    // 0x80059A70: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A74: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80059A78: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80059A7C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80059A80: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80059A84: bne         $t2, $zero, L_80059B0C
    if (ctx->r10 != 0) {
        // 0x80059A88: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_80059B0C;
    }
    // 0x80059A88: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x80059A8C: bne         $t3, $zero, L_80059B0C
    if (ctx->r11 != 0) {
        // 0x80059A90: nop

            goto L_80059B0C;
    }
    // 0x80059A90: nop

    // 0x80059A94: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059A9C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80059AA0: lwc1        $f18, 0xA0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XA0);
    // 0x80059AA4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059AA8: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80059AAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80059AB0: swc1        $f4, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->f4.u32l;
    // 0x80059AB4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80059AB8: nop

    // 0x80059ABC: lwc1        $f10, 0xA0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XA0);
    // 0x80059AC0: nop

    // 0x80059AC4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80059AC8: nop

    // 0x80059ACC: bc1f        L_80059B04
    if (!c1cs) {
        // 0x80059AD0: nop

            goto L_80059B04;
    }
    // 0x80059AD0: nop

    // 0x80059AD4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80059AD8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80059ADC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80059AE0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80059AE4: or          $t6, $t0, $zero
    ctx->r14 = ctx->r8 | 0;
    // 0x80059AE8: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x80059AEC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80059AF0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80059AF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059AF8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80059AFC: nop

    // 0x80059B00: swc1        $f6, 0xA0($t9)
    MEM_W(0XA0, ctx->r25) = ctx->f6.u32l;
L_80059B04:
    // 0x80059B04: b           L_80059B70
    // 0x80059B08: nop

        goto L_80059B70;
    // 0x80059B08: nop

L_80059B0C:
    // 0x80059B0C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80059B10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059B14: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80059B18: lwc1        $f18, 0xA0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XA0);
    // 0x80059B1C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059B20: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80059B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80059B28: swc1        $f4, 0xA0($t2)
    MEM_W(0XA0, ctx->r10) = ctx->f4.u32l;
    // 0x80059B2C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80059B30: nop

    // 0x80059B34: lwc1        $f10, 0xA0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XA0);
    // 0x80059B38: nop

    // 0x80059B3C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80059B40: nop

    // 0x80059B44: bc1f        L_80059B70
    if (!c1cs) {
        // 0x80059B48: nop

            goto L_80059B70;
    }
    // 0x80059B48: nop

    // 0x80059B4C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80059B50: lui         $at, 0x7FFB
    ctx->r1 = S32(0X7FFB << 16);
    // 0x80059B54: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x80059B58: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x80059B5C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80059B60: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80059B64: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x80059B68: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80059B6C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
L_80059B70:
    // 0x80059B70: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80059B74: nop

    // 0x80059B78: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80059B7C: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x80059B80: bne         $at, $zero, L_80058E8C
    if (ctx->r1 != 0) {
        // 0x80059B84: sw          $t8, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r24;
            goto L_80058E8C;
    }
    // 0x80059B84: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x80059B88: b           L_80059B90
    // 0x80059B8C: nop

        goto L_80059B90;
    // 0x80059B8C: nop

L_80059B90:
    // 0x80059B90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80059B94: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80059B98: jr          $ra
    // 0x80059B9C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80059B9C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80059BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BA0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059BA4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80059BA8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80059BAC: lw          $t7, 0x306C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X306C);
    // 0x80059BB0: lh          $t6, 0x1B48($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1B48);
    // 0x80059BB4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80059BB8: bne         $t7, $zero, L_80059BC8
    if (ctx->r15 != 0) {
        // 0x80059BBC: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_80059BC8;
    }
    // 0x80059BBC: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80059BC0: blez        $t6, L_80059C2C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80059BC4: nop

            goto L_80059C2C;
    }
    // 0x80059BC4: nop

L_80059BC8:
    // 0x80059BC8: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80059BCC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80059BD0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80059BD4: nop

    // 0x80059BD8: bne         $t9, $at, L_80059C08
    if (ctx->r25 != ctx->r1) {
        // 0x80059BDC: nop

            goto L_80059C08;
    }
    // 0x80059BDC: nop

    // 0x80059BE0: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80059BE4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80059BE8: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80059BEC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80059BF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80059BF4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80059BF8: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80059BFC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80059C00: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80059C04: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_80059C08:
    // 0x80059C08: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x80059C0C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80059C10: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80059C14: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80059C18: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80059C1C: bne         $t2, $zero, L_80059BC8
    if (ctx->r10 != 0) {
        // 0x80059C20: sw          $t2, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r10;
            goto L_80059BC8;
    }
    // 0x80059C20: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80059C24: bgtz        $t4, L_80059BC8
    if (SIGNED(ctx->r12) > 0) {
        // 0x80059C28: nop

            goto L_80059BC8;
    }
    // 0x80059C28: nop

L_80059C2C:
    // 0x80059C2C: b           L_80059C34
    // 0x80059C30: nop

        goto L_80059C34;
    // 0x80059C30: nop

L_80059C34:
    // 0x80059C34: jr          $ra
    // 0x80059C38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059C38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059C44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80059C48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80059C4C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80059C50: addiu       $t6, $t6, 0x28A0
    ctx->r14 = ADD32(ctx->r14, 0X28A0);
    // 0x80059C54: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80059C58: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80059C5C: nop

    // 0x80059C60: beq         $t7, $zero, L_80059D28
    if (ctx->r15 == 0) {
        // 0x80059C64: nop

            goto L_80059D28;
    }
    // 0x80059C64: nop

    // 0x80059C68: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x80059C6C: nop

    // 0x80059C70: beq         $t8, $zero, L_80059D28
    if (ctx->r24 == 0) {
        // 0x80059C74: nop

            goto L_80059D28;
    }
    // 0x80059C74: nop

L_80059C78:
    // 0x80059C78: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80059C7C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80059C80: addiu       $t0, $t0, 0x28A0
    ctx->r8 = ADD32(ctx->r8, 0X28A0);
    // 0x80059C84: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80059C88: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80059C8C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80059C90: nop

    // 0x80059C94: bne         $t2, $t3, L_80059CF0
    if (ctx->r10 != ctx->r11) {
        // 0x80059C98: nop

            goto L_80059CF0;
    }
    // 0x80059C98: nop

    // 0x80059C9C: lbu         $t4, 0x1($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X1);
    // 0x80059CA0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80059CA4: nop

    // 0x80059CA8: bne         $t4, $t5, L_80059CF0
    if (ctx->r12 != ctx->r13) {
        // 0x80059CAC: nop

            goto L_80059CF0;
    }
    // 0x80059CAC: nop

    // 0x80059CB0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80059CB4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80059CB8: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80059CBC: lbu         $t6, 0x28A2($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X28A2);
    // 0x80059CC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80059CC4: sh          $t6, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r14;
    // 0x80059CC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059CCC: sb          $t6, 0xD9C($at)
    MEM_B(0XD9C, ctx->r1) = ctx->r14;
    // 0x80059CD0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80059CD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059CD8: sb          $t8, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r24;
    // 0x80059CDC: addiu       $t9, $zero, 0x1F
    ctx->r25 = ADD32(0, 0X1F);
    // 0x80059CE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059CE4: sh          $t9, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r25;
    // 0x80059CE8: b           L_80059D38
    // 0x80059CEC: nop

        goto L_80059D38;
    // 0x80059CEC: nop

L_80059CF0:
    // 0x80059CF0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80059CF4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80059CF8: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
    // 0x80059CFC: addiu       $t3, $t3, 0x28A0
    ctx->r11 = ADD32(ctx->r11, 0X28A0);
    // 0x80059D00: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x80059D04: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80059D08: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80059D0C: nop

    // 0x80059D10: beq         $t4, $zero, L_80059D28
    if (ctx->r12 == 0) {
        // 0x80059D14: nop

            goto L_80059D28;
    }
    // 0x80059D14: nop

    // 0x80059D18: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x80059D1C: nop

    // 0x80059D20: bne         $t5, $zero, L_80059C78
    if (ctx->r13 != 0) {
        // 0x80059D24: nop

            goto L_80059C78;
    }
    // 0x80059D24: nop

L_80059D28:
    // 0x80059D28: jal         0x80059D48
    // 0x80059D2C: nop

    func_80059D48(rdram, ctx);
        goto after_0;
    // 0x80059D2C: nop

    after_0:
    // 0x80059D30: b           L_80059D38
    // 0x80059D34: nop

        goto L_80059D38;
    // 0x80059D34: nop

L_80059D38:
    // 0x80059D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059D40: jr          $ra
    // 0x80059D44: nop

    return;
    // 0x80059D44: nop

;}
RECOMP_FUNC void func_80059D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059D48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80059D4C: lbu         $t6, 0xD94($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0XD94);
    // 0x80059D50: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80059D54: beq         $t6, $at, L_80059D64
    if (ctx->r14 == ctx->r1) {
        // 0x80059D58: nop

            goto L_80059D64;
    }
    // 0x80059D58: nop

    // 0x80059D5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059D60: sb          $zero, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = 0;
L_80059D64:
    // 0x80059D64: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x80059D68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059D6C: sh          $t7, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r15;
    // 0x80059D70: jr          $ra
    // 0x80059D74: nop

    return;
    // 0x80059D74: nop

    // 0x80059D78: jr          $ra
    // 0x80059D7C: nop

    return;
    // 0x80059D7C: nop

;}
RECOMP_FUNC void func_80059D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059D88: addiu       $t6, $zero, 0x33
    ctx->r14 = ADD32(0, 0X33);
    // 0x80059D8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80059D90: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
    // 0x80059D94: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80059D98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80059D9C: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
    // 0x80059DA0: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x80059DA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80059DA8: sh          $t8, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r24;
    // 0x80059DAC: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80059DB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80059DB4: sw          $t9, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r25;
    // 0x80059DB8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80059DBC: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80059DC0: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x80059DC4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80059DC8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80059DCC: sh          $t2, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r10;
    // 0x80059DD0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80059DD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80059DD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80059DDC: swc1        $f4, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f4.u32l;
    // 0x80059DE0: addiu       $t3, $zero, 0xFE
    ctx->r11 = ADD32(0, 0XFE);
    // 0x80059DE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059DE8: sb          $t3, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r11;
    // 0x80059DEC: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x80059DF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059DF4: sh          $t4, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r12;
    // 0x80059DF8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80059DFC: sw          $zero, -0x794($at)
    MEM_W(-0X794, ctx->r1) = 0;
    // 0x80059E00: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80059E04: sh          $zero, -0x498($at)
    MEM_H(-0X498, ctx->r1) = 0;
    // 0x80059E08: jal         0x80031914
    // 0x80059E0C: nop

    func_80031914(rdram, ctx);
        goto after_0;
    // 0x80059E0C: nop

    after_0:
    // 0x80059E10: b           L_80059E18
    // 0x80059E14: nop

        goto L_80059E18;
    // 0x80059E14: nop

L_80059E18:
    // 0x80059E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059E20: jr          $ra
    // 0x80059E24: nop

    return;
    // 0x80059E24: nop

;}
RECOMP_FUNC void func_80059E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E28: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059E2C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80059E30: addiu       $t6, $t6, 0x28A8
    ctx->r14 = ADD32(ctx->r14, 0X28A8);
    // 0x80059E34: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80059E38: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80059E3C: nop

    // 0x80059E40: beq         $t7, $zero, L_80059EB8
    if (ctx->r15 == 0) {
        // 0x80059E44: nop

            goto L_80059EB8;
    }
    // 0x80059E44: nop

L_80059E48:
    // 0x80059E48: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80059E4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80059E50: addiu       $t0, $t0, 0x28A8
    ctx->r8 = ADD32(ctx->r8, 0X28A8);
    // 0x80059E54: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80059E58: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80059E5C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80059E60: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80059E64: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80059E68: nop

    // 0x80059E6C: bne         $t2, $t3, L_80059E94
    if (ctx->r10 != ctx->r11) {
        // 0x80059E70: nop

            goto L_80059E94;
    }
    // 0x80059E70: nop

    // 0x80059E74: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80059E78: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80059E7C: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80059E80: nop

    // 0x80059E84: bne         $t4, $t5, L_80059E94
    if (ctx->r12 != ctx->r13) {
        // 0x80059E88: nop

            goto L_80059E94;
    }
    // 0x80059E88: nop

    // 0x80059E8C: b           L_80059EC8
    // 0x80059E90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80059EC8;
    // 0x80059E90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059E94:
    // 0x80059E94: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80059E98: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80059E9C: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80059EA0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80059EA4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80059EA8: lh          $t9, 0x28A8($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X28A8);
    // 0x80059EAC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80059EB0: bne         $t9, $zero, L_80059E48
    if (ctx->r25 != 0) {
        // 0x80059EB4: nop

            goto L_80059E48;
    }
    // 0x80059EB4: nop

L_80059EB8:
    // 0x80059EB8: b           L_80059EC8
    // 0x80059EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059EC8;
    // 0x80059EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059EC0: b           L_80059EC8
    // 0x80059EC4: nop

        goto L_80059EC8;
    // 0x80059EC4: nop

L_80059EC8:
    // 0x80059EC8: jr          $ra
    // 0x80059ECC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059ECC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059ED0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80059ED4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059ED8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80059EDC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80059EE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80059EE4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80059EE8: nop

    // 0x80059EEC: lw          $t7, 0x58($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X58);
    // 0x80059EF0: nop

    // 0x80059EF4: lbu         $t8, 0x16($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X16);
    // 0x80059EF8: nop

    // 0x80059EFC: sb          $t8, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r24;
    // 0x80059F00: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80059F04: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80059F08: nop

    // 0x80059F0C: lw          $a0, 0x58($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X58);
    // 0x80059F10: jal         0x80056C60
    // 0x80059F14: nop

    func_80056C60(rdram, ctx);
        goto after_0;
    // 0x80059F14: nop

    after_0:
    // 0x80059F18: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80059F1C: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80059F20: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80059F24: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x80059F28: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80059F2C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80059F30: lh          $t2, 0x2C52($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2C52);
    // 0x80059F34: nop

    // 0x80059F38: sh          $t2, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r10;
    // 0x80059F3C: jal         0x80059E28
    // 0x80059F40: nop

    func_80059E28(rdram, ctx);
        goto after_1;
    // 0x80059F40: nop

    after_1:
    // 0x80059F44: bne         $v0, $zero, L_80059F54
    if (ctx->r2 != 0) {
        // 0x80059F48: nop

            goto L_80059F54;
    }
    // 0x80059F48: nop

    // 0x80059F4C: b           L_8005A130
    // 0x80059F50: nop

        goto L_8005A130;
    // 0x80059F50: nop

L_80059F54:
    // 0x80059F54: lh          $t3, 0x34($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X34);
    // 0x80059F58: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80059F5C: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F60: nop

            goto L_80059FC0;
    }
    // 0x80059F60: nop

    // 0x80059F64: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80059F68: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F6C: nop

            goto L_80059FC0;
    }
    // 0x80059F6C: nop

    // 0x80059F70: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80059F74: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F78: nop

            goto L_80059FC0;
    }
    // 0x80059F78: nop

    // 0x80059F7C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80059F80: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F84: nop

            goto L_80059FC0;
    }
    // 0x80059F84: nop

    // 0x80059F88: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80059F8C: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F90: nop

            goto L_80059FC0;
    }
    // 0x80059F90: nop

    // 0x80059F94: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80059F98: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F9C: nop

            goto L_80059FC0;
    }
    // 0x80059F9C: nop

    // 0x80059FA0: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80059FA4: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059FA8: nop

            goto L_80059FC0;
    }
    // 0x80059FA8: nop

    // 0x80059FAC: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80059FB0: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059FB4: nop

            goto L_80059FC0;
    }
    // 0x80059FB4: nop

    // 0x80059FB8: b           L_8005A130
    // 0x80059FBC: nop

        goto L_8005A130;
    // 0x80059FBC: nop

L_80059FC0:
    // 0x80059FC0: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x80059FC4: nop

    // 0x80059FC8: bne         $t4, $zero, L_80059FFC
    if (ctx->r12 != 0) {
        // 0x80059FCC: nop

            goto L_80059FFC;
    }
    // 0x80059FCC: nop

    // 0x80059FD0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80059FD4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80059FD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059FDC: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80059FE0: nop

    // 0x80059FE4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80059FE8: nop

    // 0x80059FEC: bc1f        L_80059FFC
    if (!c1cs) {
        // 0x80059FF0: nop

            goto L_80059FFC;
    }
    // 0x80059FF0: nop

    // 0x80059FF4: b           L_8005A130
    // 0x80059FF8: nop

        goto L_8005A130;
    // 0x80059FF8: nop

L_80059FFC:
    // 0x80059FFC: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x8005A000: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A004: bne         $t6, $at, L_8005A038
    if (ctx->r14 != ctx->r1) {
        // 0x8005A008: nop

            goto L_8005A038;
    }
    // 0x8005A008: nop

    // 0x8005A00C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A010: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A014: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005A018: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005A01C: nop

    // 0x8005A020: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8005A024: nop

    // 0x8005A028: bc1f        L_8005A038
    if (!c1cs) {
        // 0x8005A02C: nop

            goto L_8005A038;
    }
    // 0x8005A02C: nop

    // 0x8005A030: b           L_8005A130
    // 0x8005A034: nop

        goto L_8005A130;
    // 0x8005A034: nop

L_8005A038:
    // 0x8005A038: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005A03C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005A040: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A044: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005A048: lw          $a0, 0x58($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X58);
    // 0x8005A04C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005A050: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8005A054: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8005A058: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    // 0x8005A05C: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x8005A060: jal         0x800782A8
    // 0x8005A064: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800782A8(rdram, ctx);
        goto after_2;
    // 0x8005A064: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8005A068: bne         $v0, $zero, L_8005A078
    if (ctx->r2 != 0) {
        // 0x8005A06C: nop

            goto L_8005A078;
    }
    // 0x8005A06C: nop

    // 0x8005A070: b           L_8005A130
    // 0x8005A074: nop

        goto L_8005A130;
    // 0x8005A074: nop

L_8005A078:
    // 0x8005A078: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005A07C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005A080: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x8005A084: lw          $t1, 0x58($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X58);
    // 0x8005A088: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8005A08C: lbu         $t2, 0x16($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X16);
    // 0x8005A090: nop

    // 0x8005A094: beq         $t2, $t4, L_8005A0A4
    if (ctx->r10 == ctx->r12) {
        // 0x8005A098: nop

            goto L_8005A0A4;
    }
    // 0x8005A098: nop

    // 0x8005A09C: b           L_8005A0A8
    // 0x8005A0A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8005A0A8;
    // 0x8005A0A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8005A0A4:
    // 0x8005A0A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8005A0A8:
    // 0x8005A0A8: beq         $s1, $zero, L_8005A128
    if (ctx->r17 == 0) {
        // 0x8005A0AC: nop

            goto L_8005A128;
    }
    // 0x8005A0AC: nop

L_8005A0B0:
    // 0x8005A0B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005A0B4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005A0B8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A0BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005A0C0: lw          $a0, 0x58($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X58);
    // 0x8005A0C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A0C8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005A0CC: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8005A0D0: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    // 0x8005A0D4: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x8005A0D8: jal         0x800783EC
    // 0x8005A0DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800783EC(rdram, ctx);
        goto after_3;
    // 0x8005A0DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8005A0E0: bne         $v0, $zero, L_8005A0F0
    if (ctx->r2 != 0) {
        // 0x8005A0E4: nop

            goto L_8005A0F0;
    }
    // 0x8005A0E4: nop

    // 0x8005A0E8: b           L_8005A130
    // 0x8005A0EC: nop

        goto L_8005A130;
    // 0x8005A0EC: nop

L_8005A0F0:
    // 0x8005A0F0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A0F4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A0F8: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x8005A0FC: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x8005A100: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8005A104: lbu         $t9, 0x16($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X16);
    // 0x8005A108: nop

    // 0x8005A10C: beq         $t9, $t1, L_8005A11C
    if (ctx->r25 == ctx->r9) {
        // 0x8005A110: nop

            goto L_8005A11C;
    }
    // 0x8005A110: nop

    // 0x8005A114: b           L_8005A120
    // 0x8005A118: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8005A120;
    // 0x8005A118: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8005A11C:
    // 0x8005A11C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8005A120:
    // 0x8005A120: bne         $s1, $zero, L_8005A0B0
    if (ctx->r17 != 0) {
        // 0x8005A124: nop

            goto L_8005A0B0;
    }
    // 0x8005A124: nop

L_8005A128:
    // 0x8005A128: b           L_8005A130
    // 0x8005A12C: nop

        goto L_8005A130;
    // 0x8005A12C: nop

L_8005A130:
    // 0x8005A130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005A134: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A138: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005A13C: jr          $ra
    // 0x8005A140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005A140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005A144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A14C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005A150: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A154: lw          $t6, 0x630($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X630);
    // 0x8005A158: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005A15C: addiu       $t7, $t6, 0x318
    ctx->r15 = ADD32(ctx->r14, 0X318);
    // 0x8005A160: beq         $t7, $t8, L_8005A188
    if (ctx->r15 == ctx->r24) {
        // 0x8005A164: nop

            goto L_8005A188;
    }
    // 0x8005A164: nop

    // 0x8005A168: addiu       $t9, $t6, 0x32A
    ctx->r25 = ADD32(ctx->r14, 0X32A);
    // 0x8005A16C: beq         $t9, $t8, L_8005A188
    if (ctx->r25 == ctx->r24) {
        // 0x8005A170: nop

            goto L_8005A188;
    }
    // 0x8005A170: nop

    // 0x8005A174: addiu       $t0, $t6, 0x18C
    ctx->r8 = ADD32(ctx->r14, 0X18C);
    // 0x8005A178: beq         $t0, $t8, L_8005A188
    if (ctx->r8 == ctx->r24) {
        // 0x8005A17C: nop

            goto L_8005A188;
    }
    // 0x8005A17C: nop

    // 0x8005A180: b           L_8005A2BC
    // 0x8005A184: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A184: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005A188:
    // 0x8005A188: jal         0x80059E28
    // 0x8005A18C: nop

    func_80059E28(rdram, ctx);
        goto after_0;
    // 0x8005A18C: nop

    after_0:
    // 0x8005A190: bne         $v0, $zero, L_8005A1A0
    if (ctx->r2 != 0) {
        // 0x8005A194: nop

            goto L_8005A1A0;
    }
    // 0x8005A194: nop

    // 0x8005A198: b           L_8005A2BC
    // 0x8005A19C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A19C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005A1A0:
    // 0x8005A1A0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005A1A4: lw          $t1, 0x630($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X630);
    // 0x8005A1A8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8005A1AC: addiu       $t2, $t1, 0x318
    ctx->r10 = ADD32(ctx->r9, 0X318);
    // 0x8005A1B0: bne         $t2, $t3, L_8005A220
    if (ctx->r10 != ctx->r11) {
        // 0x8005A1B4: nop

            goto L_8005A220;
    }
    // 0x8005A1B4: nop

    // 0x8005A1B8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005A1BC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005A1C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A1C4: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8005A1C8: nop

    // 0x8005A1CC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005A1D0: nop

    // 0x8005A1D4: bc1f        L_8005A1EC
    if (!c1cs) {
        // 0x8005A1D8: nop

            goto L_8005A1EC;
    }
    // 0x8005A1D8: nop

    // 0x8005A1DC: b           L_8005A2BC
    // 0x8005A1E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A1E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005A1E4: b           L_8005A220
    // 0x8005A1E8: nop

        goto L_8005A220;
    // 0x8005A1E8: nop

L_8005A1EC:
    // 0x8005A1EC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005A1F0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005A1F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A1F8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8005A1FC: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8005A200: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x8005A204: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8005A208: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005A20C: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x8005A210: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8005A214: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x8005A218: b           L_8005A2BC
    // 0x8005A21C: addiu       $v0, $zero, 0x5BD
    ctx->r2 = ADD32(0, 0X5BD);
        goto L_8005A2BC;
    // 0x8005A21C: addiu       $v0, $zero, 0x5BD
    ctx->r2 = ADD32(0, 0X5BD);
L_8005A220:
    // 0x8005A220: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005A224: lw          $t9, 0x630($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X630);
    // 0x8005A228: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005A22C: addiu       $t8, $t9, 0x32A
    ctx->r24 = ADD32(ctx->r25, 0X32A);
    // 0x8005A230: beq         $t8, $t2, L_8005A244
    if (ctx->r24 == ctx->r10) {
        // 0x8005A234: nop

            goto L_8005A244;
    }
    // 0x8005A234: nop

    // 0x8005A238: addiu       $t3, $t9, 0x18C
    ctx->r11 = ADD32(ctx->r25, 0X18C);
    // 0x8005A23C: bne         $t3, $t2, L_8005A2AC
    if (ctx->r11 != ctx->r10) {
        // 0x8005A240: nop

            goto L_8005A2AC;
    }
    // 0x8005A240: nop

L_8005A244:
    // 0x8005A244: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005A248: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005A24C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005A250: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8005A254: nop

    // 0x8005A258: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8005A25C: nop

    // 0x8005A260: bc1f        L_8005A278
    if (!c1cs) {
        // 0x8005A264: nop

            goto L_8005A278;
    }
    // 0x8005A264: nop

    // 0x8005A268: b           L_8005A2BC
    // 0x8005A26C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A26C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005A270: b           L_8005A2AC
    // 0x8005A274: nop

        goto L_8005A2AC;
    // 0x8005A274: nop

L_8005A278:
    // 0x8005A278: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A27C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005A280: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A284: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8005A288: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x8005A28C: and         $t8, $t0, $at
    ctx->r24 = ctx->r8 & ctx->r1;
    // 0x8005A290: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8005A294: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005A298: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x8005A29C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8005A2A0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8005A2A4: b           L_8005A2BC
    // 0x8005A2A8: addiu       $v0, $zero, 0x5BD
    ctx->r2 = ADD32(0, 0X5BD);
        goto L_8005A2BC;
    // 0x8005A2A8: addiu       $v0, $zero, 0x5BD
    ctx->r2 = ADD32(0, 0X5BD);
L_8005A2AC:
    // 0x8005A2AC: b           L_8005A2BC
    // 0x8005A2B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A2B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005A2B4: b           L_8005A2BC
    // 0x8005A2B8: nop

        goto L_8005A2BC;
    // 0x8005A2B8: nop

L_8005A2BC:
    // 0x8005A2BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A2C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A2C4: jr          $ra
    // 0x8005A2C8: nop

    return;
    // 0x8005A2C8: nop

;}
RECOMP_FUNC void func_8005A2CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A2CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005A2D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A2D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005A2D8: jal         0x80059E28
    // 0x8005A2DC: nop

    func_80059E28(rdram, ctx);
        goto after_0;
    // 0x8005A2DC: nop

    after_0:
    // 0x8005A2E0: beq         $v0, $zero, L_8005A2F8
    if (ctx->r2 == 0) {
        // 0x8005A2E4: nop

            goto L_8005A2F8;
    }
    // 0x8005A2E4: nop

    // 0x8005A2E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005A2EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005A2F0: beq         $t6, $at, L_8005A300
    if (ctx->r14 == ctx->r1) {
        // 0x8005A2F4: nop

            goto L_8005A300;
    }
    // 0x8005A2F4: nop

L_8005A2F8:
    // 0x8005A2F8: b           L_8005A470
    // 0x8005A2FC: nop

        goto L_8005A470;
    // 0x8005A2FC: nop

L_8005A300:
    // 0x8005A300: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A304: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A308: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A30C: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x8005A310: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005A314: nop

    // 0x8005A318: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005A31C: nop

    // 0x8005A320: bc1f        L_8005A368
    if (!c1cs) {
        // 0x8005A324: nop

            goto L_8005A368;
    }
    // 0x8005A324: nop

    // 0x8005A328: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005A32C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005A330: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005A334: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8005A338: nop

    // 0x8005A33C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8005A340: nop

    // 0x8005A344: bc1f        L_8005A35C
    if (!c1cs) {
        // 0x8005A348: nop

            goto L_8005A35C;
    }
    // 0x8005A348: nop

    // 0x8005A34C: b           L_8005A470
    // 0x8005A350: nop

        goto L_8005A470;
    // 0x8005A350: nop

    // 0x8005A354: b           L_8005A360
    // 0x8005A358: nop

        goto L_8005A360;
    // 0x8005A358: nop

L_8005A35C:
    // 0x8005A35C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8005A360:
    // 0x8005A360: b           L_8005A3A4
    // 0x8005A364: nop

        goto L_8005A3A4;
    // 0x8005A364: nop

L_8005A368:
    // 0x8005A368: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005A36C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005A370: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005A374: lwc1        $f16, 0xC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8005A378: nop

    // 0x8005A37C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8005A380: nop

    // 0x8005A384: bc1f        L_8005A39C
    if (!c1cs) {
        // 0x8005A388: nop

            goto L_8005A39C;
    }
    // 0x8005A388: nop

    // 0x8005A38C: b           L_8005A470
    // 0x8005A390: nop

        goto L_8005A470;
    // 0x8005A390: nop

    // 0x8005A394: b           L_8005A3A4
    // 0x8005A398: nop

        goto L_8005A3A4;
    // 0x8005A398: nop

L_8005A39C:
    // 0x8005A39C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005A3A0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8005A3A4:
    // 0x8005A3A4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A3A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005A3AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005A3B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005A3B4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8005A3B8: addiu       $a0, $a0, 0x1048
    ctx->r4 = ADD32(ctx->r4, 0X1048);
    // 0x8005A3BC: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8005A3C0: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    // 0x8005A3C4: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x8005A3C8: jal         0x800782A8
    // 0x8005A3CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800782A8(rdram, ctx);
        goto after_1;
    // 0x8005A3CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8005A3D0: bne         $v0, $zero, L_8005A3E0
    if (ctx->r2 != 0) {
        // 0x8005A3D4: nop

            goto L_8005A3E0;
    }
    // 0x8005A3D4: nop

    // 0x8005A3D8: b           L_8005A470
    // 0x8005A3DC: nop

        goto L_8005A470;
    // 0x8005A3DC: nop

L_8005A3E0:
    // 0x8005A3E0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005A3E4: lbu         $t2, 0x105E($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X105E);
    // 0x8005A3E8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005A3EC: nop

    // 0x8005A3F0: beq         $t2, $t3, L_8005A44C
    if (ctx->r10 == ctx->r11) {
        // 0x8005A3F4: nop

            goto L_8005A44C;
    }
    // 0x8005A3F4: nop

L_8005A3F8:
    // 0x8005A3F8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A3FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A400: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005A404: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005A408: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8005A40C: addiu       $a0, $a0, 0x1048
    ctx->r4 = ADD32(ctx->r4, 0X1048);
    // 0x8005A410: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8005A414: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    // 0x8005A418: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x8005A41C: jal         0x800783EC
    // 0x8005A420: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800783EC(rdram, ctx);
        goto after_2;
    // 0x8005A420: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8005A424: bne         $v0, $zero, L_8005A434
    if (ctx->r2 != 0) {
        // 0x8005A428: nop

            goto L_8005A434;
    }
    // 0x8005A428: nop

    // 0x8005A42C: b           L_8005A470
    // 0x8005A430: nop

        goto L_8005A470;
    // 0x8005A430: nop

L_8005A434:
    // 0x8005A434: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005A438: lbu         $t5, 0x105E($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X105E);
    // 0x8005A43C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005A440: nop

    // 0x8005A444: bne         $t5, $t6, L_8005A3F8
    if (ctx->r13 != ctx->r14) {
        // 0x8005A448: nop

            goto L_8005A3F8;
    }
    // 0x8005A448: nop

L_8005A44C:
    // 0x8005A44C: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8005A450: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A454: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
    // 0x8005A458: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005A45C: addiu       $t8, $t8, 0x1048
    ctx->r24 = ADD32(ctx->r24, 0X1048);
    // 0x8005A460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A464: sw          $t8, 0x11A8($at)
    MEM_W(0X11A8, ctx->r1) = ctx->r24;
    // 0x8005A468: b           L_8005A470
    // 0x8005A46C: nop

        goto L_8005A470;
    // 0x8005A46C: nop

L_8005A470:
    // 0x8005A470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A474: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005A478: jr          $ra
    // 0x8005A47C: nop

    return;
    // 0x8005A47C: nop

;}
RECOMP_FUNC void func_8005A480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A480: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005A484: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8005A488: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8005A48C: nop

    // 0x8005A490: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8005A494: nop

    // 0x8005A498: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005A49C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005A4A0: nop

    // 0x8005A4A4: bne         $t8, $zero, L_8005A4B4
    if (ctx->r24 != 0) {
        // 0x8005A4A8: nop

            goto L_8005A4B4;
    }
    // 0x8005A4A8: nop

    // 0x8005A4AC: b           L_8005A570
    // 0x8005A4B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A570;
    // 0x8005A4B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A4B4:
    // 0x8005A4B4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005A4B8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005A4BC: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8005A4C0: nop

    // 0x8005A4C4: bne         $t0, $at, L_8005A4DC
    if (ctx->r8 != ctx->r1) {
        // 0x8005A4C8: nop

            goto L_8005A4DC;
    }
    // 0x8005A4C8: nop

    // 0x8005A4CC: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x8005A4D0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005A4D4: beq         $t1, $at, L_8005A560
    if (ctx->r9 == ctx->r1) {
        // 0x8005A4D8: nop

            goto L_8005A560;
    }
    // 0x8005A4D8: nop

L_8005A4DC:
    // 0x8005A4DC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005A4E0: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8005A4E4: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x8005A4E8: nop

    // 0x8005A4EC: andi        $t4, $t3, 0xFF00
    ctx->r12 = ctx->r11 & 0XFF00;
    // 0x8005A4F0: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x8005A4F4: bne         $t5, $at, L_8005A530
    if (ctx->r13 != ctx->r1) {
        // 0x8005A4F8: nop

            goto L_8005A530;
    }
    // 0x8005A4F8: nop

    // 0x8005A4FC: andi        $t6, $t3, 0x3C
    ctx->r14 = ctx->r11 & 0X3C;
    // 0x8005A500: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x8005A504: bne         $t7, $a0, L_8005A530
    if (ctx->r15 != ctx->r4) {
        // 0x8005A508: nop

            goto L_8005A530;
    }
    // 0x8005A508: nop

    // 0x8005A50C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005A510: nop

    // 0x8005A514: lhu         $v0, 0x8($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X8);
    // 0x8005A518: nop

    // 0x8005A51C: andi        $t0, $v0, 0xC0
    ctx->r8 = ctx->r2 & 0XC0;
    // 0x8005A520: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8005A524: sra         $t9, $v0, 6
    ctx->r25 = S32(SIGNED(ctx->r2) >> 6);
    // 0x8005A528: b           L_8005A570
    // 0x8005A52C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005A570;
    // 0x8005A52C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8005A530:
    // 0x8005A530: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005A534: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005A538: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x8005A53C: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8005A540: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x8005A544: nop

    // 0x8005A548: bne         $t4, $at, L_8005A4DC
    if (ctx->r12 != ctx->r1) {
        // 0x8005A54C: nop

            goto L_8005A4DC;
    }
    // 0x8005A54C: nop

    // 0x8005A550: lhu         $t5, 0x2($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X2);
    // 0x8005A554: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005A558: bne         $t5, $at, L_8005A4DC
    if (ctx->r13 != ctx->r1) {
        // 0x8005A55C: nop

            goto L_8005A4DC;
    }
    // 0x8005A55C: nop

L_8005A560:
    // 0x8005A560: b           L_8005A570
    // 0x8005A564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A570;
    // 0x8005A564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A568: b           L_8005A570
    // 0x8005A56C: nop

        goto L_8005A570;
    // 0x8005A56C: nop

L_8005A570:
    // 0x8005A570: jr          $ra
    // 0x8005A574: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005A574: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005A578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A578: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8005A57C: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8005A580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A584: bne         $t6, $at, L_8005A5AC
    if (ctx->r14 != ctx->r1) {
        // 0x8005A588: nop

            goto L_8005A5AC;
    }
    // 0x8005A588: nop

    // 0x8005A58C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005A590: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8005A594: nop

    // 0x8005A598: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8005A59C: beq         $at, $zero, L_8005A5AC
    if (ctx->r1 == 0) {
        // 0x8005A5A0: nop

            goto L_8005A5AC;
    }
    // 0x8005A5A0: nop

    // 0x8005A5A4: jr          $ra
    // 0x8005A5A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005A5A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A5AC:
    // 0x8005A5AC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8005A5B0: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x8005A5B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005A5B8: bne         $t8, $at, L_8005A5DC
    if (ctx->r24 != ctx->r1) {
        // 0x8005A5BC: nop

            goto L_8005A5DC;
    }
    // 0x8005A5BC: nop

    // 0x8005A5C0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8005A5C4: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x8005A5C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A5CC: bne         $t9, $at, L_8005A5DC
    if (ctx->r25 != ctx->r1) {
        // 0x8005A5D0: nop

            goto L_8005A5DC;
    }
    // 0x8005A5D0: nop

    // 0x8005A5D4: jr          $ra
    // 0x8005A5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005A5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A5DC:
    // 0x8005A5DC: jr          $ra
    // 0x8005A5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005A5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8005A5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A5E4: jr          $ra
    // 0x8005A5E8: nop

    return;
    // 0x8005A5E8: nop

    // 0x8005A5EC: jr          $ra
    // 0x8005A5F0: nop

    return;
    // 0x8005A5F0: nop

;}
RECOMP_FUNC void func_8005A5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A5F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005A5F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A5FC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005A600: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005A604: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005A608: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005A60C: jal         0x800B3434
    // 0x8005A610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_0;
    // 0x8005A610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8005A614: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x8005A618: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x8005A61C: nop

    // 0x8005A620: andi        $t7, $t6, 0xC000
    ctx->r15 = ctx->r14 & 0XC000;
    // 0x8005A624: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005A628: beq         $t8, $zero, L_8005A6A4
    if (ctx->r24 == 0) {
        // 0x8005A62C: sh          $t7, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r15;
            goto L_8005A6A4;
    }
    // 0x8005A62C: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x8005A630: lhu         $t9, 0x2A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2A);
    // 0x8005A634: nop

    // 0x8005A638: andi        $t0, $t9, 0x4000
    ctx->r8 = ctx->r25 & 0X4000;
    // 0x8005A63C: beq         $t0, $zero, L_8005A64C
    if (ctx->r8 == 0) {
        // 0x8005A640: nop

            goto L_8005A64C;
    }
    // 0x8005A640: nop

    // 0x8005A644: b           L_8005A650
    // 0x8005A648: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8005A650;
    // 0x8005A648: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8005A64C:
    // 0x8005A64C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8005A650:
    // 0x8005A650: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005A654: jal         0x800B32E4
    // 0x8005A658: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800B32E4(rdram, ctx);
        goto after_1;
    // 0x8005A658: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8005A65C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005A660: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005A664: nop

    // 0x8005A668: beq         $t1, $zero, L_8005A698
    if (ctx->r9 == 0) {
        // 0x8005A66C: nop

            goto L_8005A698;
    }
    // 0x8005A66C: nop

    // 0x8005A670: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A674: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8005A678: bne         $t2, $at, L_8005A698
    if (ctx->r10 != ctx->r1) {
        // 0x8005A67C: nop

            goto L_8005A698;
    }
    // 0x8005A67C: nop

    // 0x8005A680: lh          $t3, 0x7C($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X7C);
    // 0x8005A684: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A688: bne         $t3, $at, L_8005A698
    if (ctx->r11 != ctx->r1) {
        // 0x8005A68C: nop

            goto L_8005A698;
    }
    // 0x8005A68C: nop

    // 0x8005A690: addiu       $t4, $zero, 0x8C
    ctx->r12 = ADD32(0, 0X8C);
    // 0x8005A694: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8005A698:
    // 0x8005A698: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A69C: jal         0x800B9000
    // 0x8005A6A0: nop

    func_800B9000(rdram, ctx);
        goto after_2;
    // 0x8005A6A0: nop

    after_2:
L_8005A6A4:
    // 0x8005A6A4: b           L_8005A6AC
    // 0x8005A6A8: nop

        goto L_8005A6AC;
    // 0x8005A6A8: nop

L_8005A6AC:
    // 0x8005A6AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A6B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005A6B4: jr          $ra
    // 0x8005A6B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005A6B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005A6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A6BC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005A6C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A6C4: nop

    // 0x8005A6C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8005A6CC: nop

    // 0x8005A6D0: bc1f        L_8005A71C
    if (!c1cs) {
        // 0x8005A6D4: nop

            goto L_8005A71C;
    }
    // 0x8005A6D4: nop

    // 0x8005A6D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A6DC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005A6E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005A6E4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005A6E8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8005A6EC: bne         $t0, $zero, L_8005A70C
    if (ctx->r8 != 0) {
        // 0x8005A6F0: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_8005A70C;
    }
    // 0x8005A6F0: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x8005A6F4: bne         $t1, $zero, L_8005A70C
    if (ctx->r9 != 0) {
        // 0x8005A6F8: nop

            goto L_8005A70C;
    }
    // 0x8005A6F8: nop

    // 0x8005A6FC: jr          $ra
    // 0x8005A700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005A700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A704: b           L_8005A714
    // 0x8005A708: nop

        goto L_8005A714;
    // 0x8005A708: nop

L_8005A70C:
    // 0x8005A70C: jr          $ra
    // 0x8005A710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005A710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A714:
    // 0x8005A714: b           L_8005A758
    // 0x8005A718: nop

        goto L_8005A758;
    // 0x8005A718: nop

L_8005A71C:
    // 0x8005A71C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A720: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A724: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005A728: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8005A72C: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8005A730: bne         $t4, $zero, L_8005A740
    if (ctx->r12 != 0) {
        // 0x8005A734: andi        $t5, $t3, 0x8
        ctx->r13 = ctx->r11 & 0X8;
            goto L_8005A740;
    }
    // 0x8005A734: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x8005A738: beq         $t5, $zero, L_8005A750
    if (ctx->r13 == 0) {
        // 0x8005A73C: nop

            goto L_8005A750;
    }
    // 0x8005A73C: nop

L_8005A740:
    // 0x8005A740: jr          $ra
    // 0x8005A744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005A744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A748: b           L_8005A758
    // 0x8005A74C: nop

        goto L_8005A758;
    // 0x8005A74C: nop

L_8005A750:
    // 0x8005A750: jr          $ra
    // 0x8005A754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005A754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A758:
    // 0x8005A758: jr          $ra
    // 0x8005A75C: nop

    return;
    // 0x8005A75C: nop

    // 0x8005A760: jr          $ra
    // 0x8005A764: nop

    return;
    // 0x8005A764: nop

;}
