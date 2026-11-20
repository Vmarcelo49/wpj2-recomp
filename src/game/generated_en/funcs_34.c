#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8007B710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B710: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007B714: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007B718: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007B71C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007B720: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007B724: nop

    // 0x8007B728: beq         $t6, $zero, L_8007BA98
    if (ctx->r14 == 0) {
        // 0x8007B72C: nop

            goto L_8007BA98;
    }
    // 0x8007B72C: nop

    // 0x8007B730: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B734: lb          $t7, 0x7108($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7108);
    // 0x8007B738: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007B73C: nop

    // 0x8007B740: bne         $t7, $t8, L_8007B750
    if (ctx->r15 != ctx->r24) {
        // 0x8007B744: nop

            goto L_8007B750;
    }
    // 0x8007B744: nop

    // 0x8007B748: b           L_8007C53C
    // 0x8007B74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007B74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B750:
    // 0x8007B750: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8007B754: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B758: sb          $t9, 0x7108($at)
    MEM_B(0X7108, ctx->r1) = ctx->r25;
    // 0x8007B75C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007B760: lb          $t0, 0x7108($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7108);
    // 0x8007B764: nop

    // 0x8007B768: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007B76C: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8007B770: beq         $at, $zero, L_8007BA90
    if (ctx->r1 == 0) {
        // 0x8007B774: nop

            goto L_8007BA90;
    }
    // 0x8007B774: nop

    // 0x8007B778: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007B77C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007B780: addu        $at, $at, $t1
    gpr jr_addend_8007B78C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007B784: lw          $t1, -0xD20($at)
    ctx->r9 = ADD32(ctx->r1, -0XD20);
    // 0x8007B788: nop

    // 0x8007B78C: jr          $t1
    // 0x8007B790: nop

    switch (jr_addend_8007B78C >> 2) {
        case 0: goto L_8007B794; break;
        case 1: goto L_8007B7F0; break;
        case 2: goto L_8007B840; break;
        case 3: goto L_8007B9A0; break;
        case 4: goto L_8007B9F0; break;
        case 5: goto L_8007BA40; break;
        default: switch_error(__func__, 0x8007B78C, 0x800EF2E0);
    }
    // 0x8007B790: nop

L_8007B794:
    // 0x8007B794: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007B798: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B79C: swc1        $f4, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f4.u32l;
    // 0x8007B7A0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007B7A4: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007B7A8: addiu       $t2, $zero, 0xE0
    ctx->r10 = ADD32(0, 0XE0);
    // 0x8007B7AC: sh          $t2, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r10;
    // 0x8007B7B0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007B7B4: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007B7B8: addiu       $t4, $zero, -0xA
    ctx->r12 = ADD32(0, -0XA);
    // 0x8007B7BC: sh          $t4, 0x120($t5)
    MEM_H(0X120, ctx->r13) = ctx->r12;
    // 0x8007B7C0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B7C4: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007B7C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B7CC: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8007B7D0: sh          $t7, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r15;
    // 0x8007B7D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007B7D8: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007B7DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B7E0: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x8007B7E4: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007B7E8: b           L_8007BA90
    // 0x8007B7EC: nop

        goto L_8007BA90;
    // 0x8007B7EC: nop

L_8007B7F0:
    // 0x8007B7F0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007B7F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007B7F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B7FC: swc1        $f6, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f6.u32l;
    // 0x8007B800: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007B804: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007B808: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x8007B80C: sh          $t0, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r8;
    // 0x8007B810: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007B814: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007B818: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B81C: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x8007B820: sh          $t3, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r11;
    // 0x8007B824: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B828: lh          $t4, 0x713A($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X713A);
    // 0x8007B82C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B830: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x8007B834: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
    // 0x8007B838: b           L_8007BA90
    // 0x8007B83C: nop

        goto L_8007BA90;
    // 0x8007B83C: nop

L_8007B840:
    // 0x8007B840: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007B844: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007B848: jal         0x800A4074
    // 0x8007B84C: nop

    func_800A4074(rdram, ctx);
        goto after_0;
    // 0x8007B84C: nop

    after_0:
    // 0x8007B850: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B854: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007B858: addiu       $t6, $zero, 0x7D0
    ctx->r14 = ADD32(0, 0X7D0);
    // 0x8007B85C: sw          $t6, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r14;
    // 0x8007B860: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007B864: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007B868: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x8007B86C: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x8007B870: nop

    // 0x8007B874: sh          $t8, 0x1FE($t0)
    MEM_H(0X1FE, ctx->r8) = ctx->r24;
    // 0x8007B878: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007B87C: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007B880: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8007B884: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
    // 0x8007B888: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B88C: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007B890: addiu       $t3, $zero, 0xE0
    ctx->r11 = ADD32(0, 0XE0);
    // 0x8007B894: sh          $t3, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r11;
    // 0x8007B898: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B89C: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007B8A0: addiu       $t5, $zero, -0xA
    ctx->r13 = ADD32(0, -0XA);
    // 0x8007B8A4: sh          $t5, 0x120($t6)
    MEM_H(0X120, ctx->r14) = ctx->r13;
    // 0x8007B8A8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B8AC: addiu       $t7, $t7, 0x70F0
    ctx->r15 = ADD32(ctx->r15, 0X70F0);
    // 0x8007B8B0: addiu       $a0, $t7, 0x20
    ctx->r4 = ADD32(ctx->r15, 0X20);
    // 0x8007B8B4: addiu       $a1, $t7, 0x24
    ctx->r5 = ADD32(ctx->r15, 0X24);
    // 0x8007B8B8: addiu       $a2, $t7, 0x28
    ctx->r6 = ADD32(ctx->r15, 0X28);
    // 0x8007B8BC: addiu       $a3, $t7, 0x2C
    ctx->r7 = ADD32(ctx->r15, 0X2C);
    // 0x8007B8C0: jal         0x8007B12C
    // 0x8007B8C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007B12C(rdram, ctx);
        goto after_1;
    // 0x8007B8C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8007B8C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007B8CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B8D0: lwc1        $f8, 0x7110($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7110);
    // 0x8007B8D4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007B8D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007B8DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007B8E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B8E4: lwc1        $f16, 0x7114($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7114);
    // 0x8007B8E8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007B8EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B8F0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007B8F4: lwc1        $f18, 0x711C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X711C);
    // 0x8007B8F8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8007B8FC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007B900: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007B904: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007B908: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007B90C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8007B910: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007B914: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007B918: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B91C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007B920: lwc1        $f10, 0x7118($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7118);
    // 0x8007B924: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007B928: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8007B92C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007B930: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8007B934: nop

    // 0x8007B938: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8007B93C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007B940: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007B944: nop

    // 0x8007B948: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007B94C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8007B950: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007B954: nop

    // 0x8007B958: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8007B95C: nop

    // 0x8007B960: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8007B964: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007B968: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007B96C: nop

    // 0x8007B970: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007B974: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8007B978: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8007B97C: jal         0x800A39C4
    // 0x8007B980: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800A39C4(rdram, ctx);
        goto after_2;
    // 0x8007B980: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_2:
    // 0x8007B984: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007B988: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007B98C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B990: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x8007B994: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007B998: b           L_8007BA90
    // 0x8007B99C: nop

        goto L_8007BA90;
    // 0x8007B99C: nop

L_8007B9A0:
    // 0x8007B9A0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007B9A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007B9A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B9AC: swc1        $f8, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f8.u32l;
    // 0x8007B9B0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B9B4: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007B9B8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8007B9BC: sh          $t5, 0x11E($t6)
    MEM_H(0X11E, ctx->r14) = ctx->r13;
    // 0x8007B9C0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B9C4: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007B9C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B9CC: ori         $t9, $t7, 0x8
    ctx->r25 = ctx->r15 | 0X8;
    // 0x8007B9D0: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007B9D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007B9D8: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007B9DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B9E0: ori         $t0, $t8, 0x40
    ctx->r8 = ctx->r24 | 0X40;
    // 0x8007B9E4: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007B9E8: b           L_8007BA90
    // 0x8007B9EC: nop

        goto L_8007BA90;
    // 0x8007B9EC: nop

L_8007B9F0:
    // 0x8007B9F0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007B9F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B9F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B9FC: swc1        $f10, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f10.u32l;
    // 0x8007BA00: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BA04: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BA08: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8007BA0C: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x8007BA10: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BA14: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007BA18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA1C: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x8007BA20: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007BA24: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BA28: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007BA2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA30: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x8007BA34: sh          $t6, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r14;
    // 0x8007BA38: b           L_8007BA90
    // 0x8007BA3C: nop

        goto L_8007BA90;
    // 0x8007BA3C: nop

L_8007BA40:
    // 0x8007BA40: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007BA44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007BA48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA4C: swc1        $f18, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f18.u32l;
    // 0x8007BA50: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BA54: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BA58: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8007BA5C: sh          $t7, 0x11E($t9)
    MEM_H(0X11E, ctx->r25) = ctx->r15;
    // 0x8007BA60: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BA64: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007BA68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA6C: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x8007BA70: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007BA74: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BA78: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007BA7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA80: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x8007BA84: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
    // 0x8007BA88: b           L_8007BA90
    // 0x8007BA8C: nop

        goto L_8007BA90;
    // 0x8007BA8C: nop

L_8007BA90:
    // 0x8007BA90: b           L_8007C53C
    // 0x8007BA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007BA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007BA98:
    // 0x8007BA98: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BA9C: lb          $t3, 0x7108($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7108);
    // 0x8007BAA0: nop

    // 0x8007BAA4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007BAA8: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x8007BAAC: beq         $at, $zero, L_8007C19C
    if (ctx->r1 == 0) {
        // 0x8007BAB0: nop

            goto L_8007C19C;
    }
    // 0x8007BAB0: nop

    // 0x8007BAB4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007BAB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007BABC: addu        $at, $at, $t4
    gpr jr_addend_8007BAC8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8007BAC0: lw          $t4, -0xD08($at)
    ctx->r12 = ADD32(ctx->r1, -0XD08);
    // 0x8007BAC4: nop

    // 0x8007BAC8: jr          $t4
    // 0x8007BACC: nop

    switch (jr_addend_8007BAC8 >> 2) {
        case 0: goto L_8007C194; break;
        case 1: goto L_8007C19C; break;
        case 2: goto L_8007BAD0; break;
        case 3: goto L_8007BC80; break;
        case 4: goto L_8007BD94; break;
        case 5: goto L_8007BE94; break;
        case 6: goto L_8007BF84; break;
        case 7: goto L_8007C0A4; break;
        default: switch_error(__func__, 0x8007BAC8, 0x800EF2F8);
    }
    // 0x8007BACC: nop

L_8007BAD0:
    // 0x8007BAD0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BAD4: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007BAD8: nop

    // 0x8007BADC: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x8007BAE0: beq         $t6, $zero, L_8007BB80
    if (ctx->r14 == 0) {
        // 0x8007BAE4: nop

            goto L_8007BB80;
    }
    // 0x8007BAE4: nop

    // 0x8007BAE8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BAEC: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BAF0: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8007BAF4: sw          $t7, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r15;
    // 0x8007BAF8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BAFC: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007BB00: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007BB04: sh          $t8, 0x116($t0)
    MEM_H(0X116, ctx->r8) = ctx->r24;
    // 0x8007BB08: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BB0C: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007BB10: nop

    // 0x8007BB14: sh          $zero, 0x114($t1)
    MEM_H(0X114, ctx->r9) = 0;
    // 0x8007BB18: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BB1C: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BB20: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8007BB24: sw          $t2, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r10;
    // 0x8007BB28: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BB2C: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007BB30: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8007BB34: sh          $t4, 0x118($t5)
    MEM_H(0X118, ctx->r13) = ctx->r12;
    // 0x8007BB38: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BB3C: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007BB40: nop

    // 0x8007BB44: sh          $zero, 0x11A($t6)
    MEM_H(0X11A, ctx->r14) = 0;
    // 0x8007BB48: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BB4C: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007BB50: nop

    // 0x8007BB54: sh          $zero, 0x11C($t7)
    MEM_H(0X11C, ctx->r15) = 0;
    // 0x8007BB58: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BB5C: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BB60: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8007BB64: sh          $t9, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r25;
    // 0x8007BB68: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BB6C: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007BB70: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007BB74: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8007BB78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BB7C: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
L_8007BB80:
    // 0x8007BB80: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BB84: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007BB88: addiu       $a0, $t2, 0x20
    ctx->r4 = ADD32(ctx->r10, 0X20);
    // 0x8007BB8C: addiu       $a1, $t2, 0x24
    ctx->r5 = ADD32(ctx->r10, 0X24);
    // 0x8007BB90: addiu       $a2, $t2, 0x28
    ctx->r6 = ADD32(ctx->r10, 0X28);
    // 0x8007BB94: addiu       $a3, $t2, 0x2C
    ctx->r7 = ADD32(ctx->r10, 0X2C);
    // 0x8007BB98: jal         0x8007B12C
    // 0x8007BB9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007B12C(rdram, ctx);
        goto after_3;
    // 0x8007BB9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8007BBA0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BBA4: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BBA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007BBAC: lh          $t4, 0x120($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X120);
    // 0x8007BBB0: lh          $t5, 0x11E($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X11E);
    // 0x8007BBB4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8007BBB8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007BBBC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007BBC0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8007BBC4: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8007BBC8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007BBCC: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8007BBD0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007BBD4: nop

    // 0x8007BBD8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8007BBDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007BBE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007BBE4: nop

    // 0x8007BBE8: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007BBEC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8007BBF0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007BBF4: sh          $t7, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r15;
    // 0x8007BBF8: nop

    // 0x8007BBFC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BC00: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BC04: nop

    // 0x8007BC08: lh          $t8, 0x11E($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X11E);
    // 0x8007BC0C: nop

    // 0x8007BC10: bgez        $t8, L_8007BC38
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007BC14: nop

            goto L_8007BC38;
    }
    // 0x8007BC14: nop

    // 0x8007BC18: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BC1C: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007BC20: nop

    // 0x8007BC24: sh          $zero, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = 0;
    // 0x8007BC28: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BC2C: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BC30: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8007BC34: sh          $t1, 0x120($t2)
    MEM_H(0X120, ctx->r10) = ctx->r9;
L_8007BC38:
    // 0x8007BC38: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007BC3C: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007BC40: nop

    // 0x8007BC44: lh          $t5, 0x11E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X11E);
    // 0x8007BC48: nop

    // 0x8007BC4C: slti        $at, $t5, 0xE1
    ctx->r1 = SIGNED(ctx->r13) < 0XE1 ? 1 : 0;
    // 0x8007BC50: bne         $at, $zero, L_8007BC78
    if (ctx->r1 != 0) {
        // 0x8007BC54: nop

            goto L_8007BC78;
    }
    // 0x8007BC54: nop

    // 0x8007BC58: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BC5C: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007BC60: addiu       $t6, $zero, 0xE0
    ctx->r14 = ADD32(0, 0XE0);
    // 0x8007BC64: sh          $t6, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r14;
    // 0x8007BC68: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BC6C: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BC70: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x8007BC74: sh          $t3, 0x120($t9)
    MEM_H(0X120, ctx->r25) = ctx->r11;
L_8007BC78:
    // 0x8007BC78: b           L_8007C1B4
    // 0x8007BC7C: nop

        goto L_8007C1B4;
    // 0x8007BC7C: nop

L_8007BC80:
    // 0x8007BC80: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BC84: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007BC88: nop

    // 0x8007BC8C: andi        $t0, $t8, 0x40
    ctx->r8 = ctx->r24 & 0X40;
    // 0x8007BC90: beq         $t0, $zero, L_8007BD30
    if (ctx->r8 == 0) {
        // 0x8007BC94: nop

            goto L_8007BD30;
    }
    // 0x8007BC94: nop

    // 0x8007BC98: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BC9C: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BCA0: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8007BCA4: sw          $t1, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r9;
    // 0x8007BCA8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BCAC: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007BCB0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8007BCB4: sh          $t4, 0x116($t5)
    MEM_H(0X116, ctx->r13) = ctx->r12;
    // 0x8007BCB8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BCBC: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007BCC0: nop

    // 0x8007BCC4: sh          $zero, 0x114($t6)
    MEM_H(0X114, ctx->r14) = 0;
    // 0x8007BCC8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BCCC: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BCD0: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8007BCD4: sw          $t7, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r15;
    // 0x8007BCD8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BCDC: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BCE0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8007BCE4: sh          $t9, 0x118($t8)
    MEM_H(0X118, ctx->r24) = ctx->r25;
    // 0x8007BCE8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BCEC: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007BCF0: nop

    // 0x8007BCF4: sh          $zero, 0x11A($t0)
    MEM_H(0X11A, ctx->r8) = 0;
    // 0x8007BCF8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BCFC: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007BD00: nop

    // 0x8007BD04: sh          $zero, 0x11C($t1)
    MEM_H(0X11C, ctx->r9) = 0;
    // 0x8007BD08: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007BD0C: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007BD10: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8007BD14: sh          $t2, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r10;
    // 0x8007BD18: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BD1C: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007BD20: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007BD24: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8007BD28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BD2C: sh          $t6, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r14;
L_8007BD30:
    // 0x8007BD30: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BD34: addiu       $t7, $t7, 0x70F0
    ctx->r15 = ADD32(ctx->r15, 0X70F0);
    // 0x8007BD38: addiu       $a0, $t7, 0x20
    ctx->r4 = ADD32(ctx->r15, 0X20);
    // 0x8007BD3C: addiu       $a1, $t7, 0x24
    ctx->r5 = ADD32(ctx->r15, 0X24);
    // 0x8007BD40: addiu       $a2, $t7, 0x28
    ctx->r6 = ADD32(ctx->r15, 0X28);
    // 0x8007BD44: addiu       $a3, $t7, 0x2C
    ctx->r7 = ADD32(ctx->r15, 0X2C);
    // 0x8007BD48: jal         0x8007B12C
    // 0x8007BD4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007B12C(rdram, ctx);
        goto after_4;
    // 0x8007BD4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8007BD50: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BD54: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BD58: nop

    // 0x8007BD5C: lh          $t9, 0x11E($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X11E);
    // 0x8007BD60: nop

    // 0x8007BD64: beq         $t9, $zero, L_8007BD7C
    if (ctx->r25 == 0) {
        // 0x8007BD68: nop

            goto L_8007BD7C;
    }
    // 0x8007BD68: nop

    // 0x8007BD6C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BD70: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BD74: b           L_8007BD8C
    // 0x8007BD78: sh          $zero, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = 0;
        goto L_8007BD8C;
    // 0x8007BD78: sh          $zero, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = 0;
L_8007BD7C:
    // 0x8007BD7C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BD80: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007BD84: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x8007BD88: sh          $t0, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r8;
L_8007BD8C:
    // 0x8007BD8C: b           L_8007C1B4
    // 0x8007BD90: nop

        goto L_8007C1B4;
    // 0x8007BD90: nop

L_8007BD94:
    // 0x8007BD94: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BD98: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007BD9C: addiu       $a0, $t2, 0x20
    ctx->r4 = ADD32(ctx->r10, 0X20);
    // 0x8007BDA0: addiu       $a1, $t2, 0x24
    ctx->r5 = ADD32(ctx->r10, 0X24);
    // 0x8007BDA4: addiu       $a2, $t2, 0x28
    ctx->r6 = ADD32(ctx->r10, 0X28);
    // 0x8007BDA8: addiu       $a3, $t2, 0x2C
    ctx->r7 = ADD32(ctx->r10, 0X2C);
    // 0x8007BDAC: jal         0x8007B12C
    // 0x8007BDB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007B12C(rdram, ctx);
        goto after_5;
    // 0x8007BDB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8007BDB4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007BDB8: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007BDBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007BDC0: lh          $t5, 0x120($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X120);
    // 0x8007BDC4: lh          $t6, 0x11E($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X11E);
    // 0x8007BDC8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8007BDCC: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007BDD0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007BDD4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8007BDD8: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007BDDC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007BDE0: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8007BDE4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007BDE8: nop

    // 0x8007BDEC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8007BDF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007BDF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007BDF8: nop

    // 0x8007BDFC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007BE00: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8007BE04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007BE08: sh          $t3, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r11;
    // 0x8007BE0C: nop

    // 0x8007BE10: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BE14: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BE18: nop

    // 0x8007BE1C: lh          $t8, 0x11E($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X11E);
    // 0x8007BE20: nop

    // 0x8007BE24: bgez        $t8, L_8007BE4C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007BE28: nop

            goto L_8007BE4C;
    }
    // 0x8007BE28: nop

    // 0x8007BE2C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BE30: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007BE34: nop

    // 0x8007BE38: sh          $zero, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = 0;
    // 0x8007BE3C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BE40: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BE44: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8007BE48: sh          $t1, 0x120($t2)
    MEM_H(0X120, ctx->r10) = ctx->r9;
L_8007BE4C:
    // 0x8007BE4C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BE50: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007BE54: nop

    // 0x8007BE58: lh          $t6, 0x11E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X11E);
    // 0x8007BE5C: nop

    // 0x8007BE60: slti        $at, $t6, 0xE1
    ctx->r1 = SIGNED(ctx->r14) < 0XE1 ? 1 : 0;
    // 0x8007BE64: bne         $at, $zero, L_8007BE8C
    if (ctx->r1 != 0) {
        // 0x8007BE68: nop

            goto L_8007BE8C;
    }
    // 0x8007BE68: nop

    // 0x8007BE6C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BE70: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BE74: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x8007BE78: sh          $t7, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r15;
    // 0x8007BE7C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BE80: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BE84: addiu       $t4, $zero, -0xA
    ctx->r12 = ADD32(0, -0XA);
    // 0x8007BE88: sh          $t4, 0x120($t9)
    MEM_H(0X120, ctx->r25) = ctx->r12;
L_8007BE8C:
    // 0x8007BE8C: b           L_8007C1B4
    // 0x8007BE90: nop

        goto L_8007C1B4;
    // 0x8007BE90: nop

L_8007BE94:
    // 0x8007BE94: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BE98: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007BE9C: nop

    // 0x8007BEA0: andi        $t0, $t8, 0x40
    ctx->r8 = ctx->r24 & 0X40;
    // 0x8007BEA4: beq         $t0, $zero, L_8007BF58
    if (ctx->r8 == 0) {
        // 0x8007BEA8: nop

            goto L_8007BF58;
    }
    // 0x8007BEA8: nop

    // 0x8007BEAC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BEB0: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BEB4: addiu       $t1, $zero, 0x48
    ctx->r9 = ADD32(0, 0X48);
    // 0x8007BEB8: sw          $t1, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r9;
    // 0x8007BEBC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BEC0: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007BEC4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007BEC8: sh          $t5, 0x116($t6)
    MEM_H(0X116, ctx->r14) = ctx->r13;
    // 0x8007BECC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BED0: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007BED4: nop

    // 0x8007BED8: sh          $zero, 0x114($t7)
    MEM_H(0X114, ctx->r15) = 0;
    // 0x8007BEDC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007BEE0: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007BEE4: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8007BEE8: sw          $t3, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r11;
    // 0x8007BEEC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BEF0: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BEF4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8007BEF8: sh          $t9, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r25;
    // 0x8007BEFC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BF00: lw          $t1, 0x70F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F0);
    // 0x8007BF04: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8007BF08: sh          $t0, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r8;
    // 0x8007BF0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007BF10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007BF14: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007BF18: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007BF1C: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007BF20: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007BF24: lui         $a2, 0x91
    ctx->r6 = S32(0X91 << 16);
    // 0x8007BF28: ori         $a2, $a2, 0x245
    ctx->r6 = ctx->r6 | 0X245;
    // 0x8007BF2C: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x8007BF30: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007BF34: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8007BF38: jal         0x800B1F0C
    // 0x8007BF3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_6;
    // 0x8007BF3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8007BF40: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BF44: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007BF48: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007BF4C: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x8007BF50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BF54: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
L_8007BF58:
    // 0x8007BF58: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BF5C: addiu       $t6, $t6, 0x70F0
    ctx->r14 = ADD32(ctx->r14, 0X70F0);
    // 0x8007BF60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007BF64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007BF68: addiu       $a0, $t6, 0x20
    ctx->r4 = ADD32(ctx->r14, 0X20);
    // 0x8007BF6C: addiu       $a1, $t6, 0x24
    ctx->r5 = ADD32(ctx->r14, 0X24);
    // 0x8007BF70: addiu       $a2, $t6, 0x28
    ctx->r6 = ADD32(ctx->r14, 0X28);
    // 0x8007BF74: jal         0x8007B12C
    // 0x8007BF78: addiu       $a3, $t6, 0x2C
    ctx->r7 = ADD32(ctx->r14, 0X2C);
    func_8007B12C(rdram, ctx);
        goto after_7;
    // 0x8007BF78: addiu       $a3, $t6, 0x2C
    ctx->r7 = ADD32(ctx->r14, 0X2C);
    after_7:
    // 0x8007BF7C: b           L_8007C1B4
    // 0x8007BF80: nop

        goto L_8007C1B4;
    // 0x8007BF80: nop

L_8007BF84:
    // 0x8007BF84: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BF88: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007BF8C: nop

    // 0x8007BF90: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x8007BF94: beq         $t4, $zero, L_8007C078
    if (ctx->r12 == 0) {
        // 0x8007BF98: nop

            goto L_8007C078;
    }
    // 0x8007BF98: nop

    // 0x8007BF9C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BFA0: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BFA4: addiu       $t9, $zero, 0x48
    ctx->r25 = ADD32(0, 0X48);
    // 0x8007BFA8: sw          $t9, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r25;
    // 0x8007BFAC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BFB0: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007BFB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007BFB8: sh          $t0, 0x116($t1)
    MEM_H(0X116, ctx->r9) = ctx->r8;
    // 0x8007BFBC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BFC0: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BFC4: nop

    // 0x8007BFC8: sh          $zero, 0x114($t2)
    MEM_H(0X114, ctx->r10) = 0;
    // 0x8007BFCC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BFD0: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007BFD4: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x8007BFD8: sw          $t5, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r13;
    // 0x8007BFDC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BFE0: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007BFE4: nop

    // 0x8007BFE8: sh          $zero, 0x118($t7)
    MEM_H(0X118, ctx->r15) = 0;
    // 0x8007BFEC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BFF0: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BFF4: nop

    // 0x8007BFF8: sh          $zero, 0x11A($t3)
    MEM_H(0X11A, ctx->r11) = 0;
    // 0x8007BFFC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007C000: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007C004: nop

    // 0x8007C008: sh          $zero, 0x11C($t4)
    MEM_H(0X11C, ctx->r12) = 0;
    // 0x8007C00C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C010: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007C014: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8007C018: sh          $t9, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r25;
    // 0x8007C01C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C020: lw          $t1, 0x70F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F0);
    // 0x8007C024: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8007C028: sh          $t0, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r8;
    // 0x8007C02C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007C030: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007C034: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C038: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007C03C: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007C040: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C044: lui         $a2, 0xAD
    ctx->r6 = S32(0XAD << 16);
    // 0x8007C048: ori         $a2, $a2, 0x245
    ctx->r6 = ctx->r6 | 0X245;
    // 0x8007C04C: addiu       $a3, $zero, 0x54
    ctx->r7 = ADD32(0, 0X54);
    // 0x8007C050: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007C054: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8007C058: jal         0x800B1F0C
    // 0x8007C05C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_8;
    // 0x8007C05C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x8007C060: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C064: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007C068: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007C06C: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x8007C070: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C074: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
L_8007C078:
    // 0x8007C078: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C07C: addiu       $t6, $t6, 0x70F0
    ctx->r14 = ADD32(ctx->r14, 0X70F0);
    // 0x8007C080: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8007C084: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007C088: addiu       $a0, $t6, 0x20
    ctx->r4 = ADD32(ctx->r14, 0X20);
    // 0x8007C08C: addiu       $a1, $t6, 0x24
    ctx->r5 = ADD32(ctx->r14, 0X24);
    // 0x8007C090: addiu       $a2, $t6, 0x28
    ctx->r6 = ADD32(ctx->r14, 0X28);
    // 0x8007C094: jal         0x8007B12C
    // 0x8007C098: addiu       $a3, $t6, 0x2C
    ctx->r7 = ADD32(ctx->r14, 0X2C);
    func_8007B12C(rdram, ctx);
        goto after_9;
    // 0x8007C098: addiu       $a3, $t6, 0x2C
    ctx->r7 = ADD32(ctx->r14, 0X2C);
    after_9:
    // 0x8007C09C: b           L_8007C1B4
    // 0x8007C0A0: nop

        goto L_8007C1B4;
    // 0x8007C0A0: nop

L_8007C0A4:
    // 0x8007C0A4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C0A8: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007C0AC: nop

    // 0x8007C0B0: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x8007C0B4: beq         $t4, $zero, L_8007C168
    if (ctx->r12 == 0) {
        // 0x8007C0B8: nop

            goto L_8007C168;
    }
    // 0x8007C0B8: nop

    // 0x8007C0BC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C0C0: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007C0C4: addiu       $t9, $zero, 0x48
    ctx->r25 = ADD32(0, 0X48);
    // 0x8007C0C8: sw          $t9, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r25;
    // 0x8007C0CC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C0D0: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007C0D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007C0D8: sh          $t0, 0x116($t1)
    MEM_H(0X116, ctx->r9) = ctx->r8;
    // 0x8007C0DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C0E0: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007C0E4: nop

    // 0x8007C0E8: sh          $zero, 0x114($t2)
    MEM_H(0X114, ctx->r10) = 0;
    // 0x8007C0EC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C0F0: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007C0F4: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x8007C0F8: sw          $t5, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r13;
    // 0x8007C0FC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C100: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007C104: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8007C108: sh          $t7, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r15;
    // 0x8007C10C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007C110: lw          $t9, 0x70F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F0);
    // 0x8007C114: ori         $t4, $zero, 0xFFFF
    ctx->r12 = 0 | 0XFFFF;
    // 0x8007C118: sh          $t4, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r12;
    // 0x8007C11C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007C120: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007C124: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C128: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007C12C: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007C130: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C134: lui         $a2, 0x92
    ctx->r6 = S32(0X92 << 16);
    // 0x8007C138: ori         $a2, $a2, 0x245
    ctx->r6 = ctx->r6 | 0X245;
    // 0x8007C13C: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x8007C140: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007C144: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8007C148: jal         0x800B1F0C
    // 0x8007C14C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_10;
    // 0x8007C14C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x8007C150: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C154: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007C158: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007C15C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8007C160: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C164: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
L_8007C168:
    // 0x8007C168: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C16C: addiu       $t1, $t1, 0x70F0
    ctx->r9 = ADD32(ctx->r9, 0X70F0);
    // 0x8007C170: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007C174: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8007C178: addiu       $a0, $t1, 0x20
    ctx->r4 = ADD32(ctx->r9, 0X20);
    // 0x8007C17C: addiu       $a1, $t1, 0x24
    ctx->r5 = ADD32(ctx->r9, 0X24);
    // 0x8007C180: addiu       $a2, $t1, 0x28
    ctx->r6 = ADD32(ctx->r9, 0X28);
    // 0x8007C184: jal         0x8007B12C
    // 0x8007C188: addiu       $a3, $t1, 0x2C
    ctx->r7 = ADD32(ctx->r9, 0X2C);
    func_8007B12C(rdram, ctx);
        goto after_11;
    // 0x8007C188: addiu       $a3, $t1, 0x2C
    ctx->r7 = ADD32(ctx->r9, 0X2C);
    after_11:
    // 0x8007C18C: b           L_8007C1B4
    // 0x8007C190: nop

        goto L_8007C1B4;
    // 0x8007C190: nop

L_8007C194:
    // 0x8007C194: b           L_8007C1B4
    // 0x8007C198: nop

        goto L_8007C1B4;
    // 0x8007C198: nop

L_8007C19C:
    // 0x8007C19C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007C1A0: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007C1A4: nop

    // 0x8007C1A8: sh          $zero, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = 0;
    // 0x8007C1AC: b           L_8007C1B4
    // 0x8007C1B0: nop

        goto L_8007C1B4;
    // 0x8007C1B0: nop

L_8007C1B4:
    // 0x8007C1B4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C1B8: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007C1BC: nop

    // 0x8007C1C0: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8007C1C4: beq         $t7, $zero, L_8007C470
    if (ctx->r15 == 0) {
        // 0x8007C1C8: nop

            goto L_8007C470;
    }
    // 0x8007C1C8: nop

    // 0x8007C1CC: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8007C1D0: lb          $s0, 0x7108($s0)
    ctx->r16 = MEM_B(ctx->r16, 0X7108);
    // 0x8007C1D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007C1D8: beq         $s0, $at, L_8007C3D8
    if (ctx->r16 == ctx->r1) {
        // 0x8007C1DC: nop

            goto L_8007C3D8;
    }
    // 0x8007C1DC: nop

    // 0x8007C1E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C1E4: beq         $s0, $at, L_8007C20C
    if (ctx->r16 == ctx->r1) {
        // 0x8007C1E8: nop

            goto L_8007C20C;
    }
    // 0x8007C1E8: nop

    // 0x8007C1EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007C1F0: beq         $s0, $at, L_8007C20C
    if (ctx->r16 == ctx->r1) {
        // 0x8007C1F4: nop

            goto L_8007C20C;
    }
    // 0x8007C1F4: nop

    // 0x8007C1F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007C1FC: beq         $s0, $at, L_8007C2DC
    if (ctx->r16 == ctx->r1) {
        // 0x8007C200: nop

            goto L_8007C2DC;
    }
    // 0x8007C200: nop

    // 0x8007C204: b           L_8007C3E0
    // 0x8007C208: nop

        goto L_8007C3E0;
    // 0x8007C208: nop

L_8007C20C:
    // 0x8007C20C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C210: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C214: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007C218: lwc1        $f18, 0x7110($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7110);
    // 0x8007C21C: nop

    // 0x8007C220: swc1        $f18, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f18.u32l;
    // 0x8007C224: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C228: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007C22C: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007C230: lwc1        $f4, 0x7114($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7114);
    // 0x8007C234: nop

    // 0x8007C238: swc1        $f4, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f4.u32l;
    // 0x8007C23C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007C240: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C244: lwc1        $f16, 0x7118($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7118);
    // 0x8007C248: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007C24C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C250: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C254: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C258: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007C25C: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007C260: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8007C264: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007C268: sh          $t8, 0x100($t0)
    MEM_H(0X100, ctx->r8) = ctx->r24;
    // 0x8007C26C: nop

    // 0x8007C270: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8007C274: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C278: lwc1        $f6, 0x711C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X711C);
    // 0x8007C27C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8007C280: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C284: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C288: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007C28C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007C290: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007C294: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8007C298: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8007C29C: sh          $t2, 0x102($t5)
    MEM_H(0X102, ctx->r13) = ctx->r10;
    // 0x8007C2A0: nop

    // 0x8007C2A4: jal         0x800C1754
    // 0x8007C2A8: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_12;
    // 0x8007C2A8: nop

    after_12:
    // 0x8007C2AC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C2B0: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C2B4: jal         0x8009A14C
    // 0x8007C2B8: nop

    func_8009A14C(rdram, ctx);
        goto after_13;
    // 0x8007C2B8: nop

    after_13:
    // 0x8007C2BC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C2C0: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C2C4: jal         0x800997D8
    // 0x8007C2C8: nop

    func_800997D8(rdram, ctx);
        goto after_14;
    // 0x8007C2C8: nop

    after_14:
    // 0x8007C2CC: jal         0x800C1A28
    // 0x8007C2D0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_15;
    // 0x8007C2D0: nop

    after_15:
    // 0x8007C2D4: b           L_8007C470
    // 0x8007C2D8: nop

        goto L_8007C470;
    // 0x8007C2D8: nop

L_8007C2DC:
    // 0x8007C2DC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007C2E0: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007C2E4: addiu       $t6, $zero, 0x7D0
    ctx->r14 = ADD32(0, 0X7D0);
    // 0x8007C2E8: sw          $t6, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r14;
    // 0x8007C2EC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007C2F0: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007C2F4: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x8007C2F8: lw          $t9, 0x138($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X138);
    // 0x8007C2FC: nop

    // 0x8007C300: sh          $t3, 0x1FE($t9)
    MEM_H(0X1FE, ctx->r25) = ctx->r11;
    // 0x8007C304: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C308: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007C30C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8007C310: sh          $t8, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r24;
    // 0x8007C314: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8007C318: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C31C: lwc1        $f18, 0x7110($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7110);
    // 0x8007C320: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8007C324: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C328: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C32C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C330: lwc1        $f16, 0x7114($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7114);
    // 0x8007C334: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007C338: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C33C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8007C340: lwc1        $f8, 0x711C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X711C);
    // 0x8007C344: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8007C348: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8007C34C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C350: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8007C354: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C358: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8007C35C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C360: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C364: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C368: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007C36C: lwc1        $f4, 0x7118($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7118);
    // 0x8007C370: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8007C374: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8007C378: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007C37C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8007C380: nop

    // 0x8007C384: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8007C388: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C38C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C390: nop

    // 0x8007C394: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007C398: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8007C39C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8007C3A0: nop

    // 0x8007C3A4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007C3A8: nop

    // 0x8007C3AC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8007C3B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C3B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C3B8: nop

    // 0x8007C3BC: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007C3C0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8007C3C4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007C3C8: jal         0x800A39C4
    // 0x8007C3CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800A39C4(rdram, ctx);
        goto after_16;
    // 0x8007C3CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_16:
    // 0x8007C3D0: b           L_8007C470
    // 0x8007C3D4: nop

        goto L_8007C470;
    // 0x8007C3D4: nop

L_8007C3D8:
    // 0x8007C3D8: b           L_8007C470
    // 0x8007C3DC: nop

        goto L_8007C470;
    // 0x8007C3DC: nop

L_8007C3E0:
    // 0x8007C3E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C3E4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007C3E8: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007C3EC: lwc1        $f18, 0x7110($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7110);
    // 0x8007C3F0: nop

    // 0x8007C3F4: swc1        $f18, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f18.u32l;
    // 0x8007C3F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C3FC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C400: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007C404: lwc1        $f4, 0x7114($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7114);
    // 0x8007C408: nop

    // 0x8007C40C: swc1        $f4, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f4.u32l;
    // 0x8007C410: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C414: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007C418: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007C41C: lwc1        $f8, 0x7118($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7118);
    // 0x8007C420: nop

    // 0x8007C424: swc1        $f8, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f8.u32l;
    // 0x8007C428: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C42C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C430: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007C434: lwc1        $f6, 0x711C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X711C);
    // 0x8007C438: nop

    // 0x8007C43C: swc1        $f6, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f6.u32l;
    // 0x8007C440: jal         0x800C1754
    // 0x8007C444: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_17;
    // 0x8007C444: nop

    after_17:
    // 0x8007C448: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C44C: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C450: jal         0x8009A14C
    // 0x8007C454: nop

    func_8009A14C(rdram, ctx);
        goto after_18;
    // 0x8007C454: nop

    after_18:
    // 0x8007C458: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C45C: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C460: jal         0x800997D8
    // 0x8007C464: nop

    func_800997D8(rdram, ctx);
        goto after_19;
    // 0x8007C464: nop

    after_19:
    // 0x8007C468: jal         0x800C1A28
    // 0x8007C46C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_20;
    // 0x8007C46C: nop

    after_20:
L_8007C470:
    // 0x8007C470: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C474: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007C478: nop

    // 0x8007C47C: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8007C480: beq         $t1, $zero, L_8007C490
    if (ctx->r9 == 0) {
        // 0x8007C484: nop

            goto L_8007C490;
    }
    // 0x8007C484: nop

    // 0x8007C488: b           L_8007C53C
    // 0x8007C48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007C48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C490:
    // 0x8007C490: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C494: lwc1        $f16, 0x710C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X710C);
    // 0x8007C498: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007C49C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C4A0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8007C4A4: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8007C4A8: nop

    // 0x8007C4AC: bc1f        L_8007C52C
    if (!c1cs) {
        // 0x8007C4B0: nop

            goto L_8007C52C;
    }
    // 0x8007C4B0: nop

    // 0x8007C4B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C4B8: lwc1        $f4, 0x710C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X710C);
    // 0x8007C4BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007C4C0: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007C4C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C4C8: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8007C4CC: swc1        $f6, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f6.u32l;
    // 0x8007C4D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C4D4: lwc1        $f16, 0x710C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X710C);
    // 0x8007C4D8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007C4DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C4E0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8007C4E4: c.le.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d <= ctx->f18.d;
    // 0x8007C4E8: nop

    // 0x8007C4EC: bc1f        L_8007C524
    if (!c1cs) {
        // 0x8007C4F0: nop

            goto L_8007C524;
    }
    // 0x8007C4F0: nop

    // 0x8007C4F4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C4F8: lb          $t2, 0x7108($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7108);
    // 0x8007C4FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007C500: beq         $t2, $at, L_8007C514
    if (ctx->r10 == ctx->r1) {
        // 0x8007C504: nop

            goto L_8007C514;
    }
    // 0x8007C504: nop

    // 0x8007C508: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007C50C: bne         $t2, $at, L_8007C51C
    if (ctx->r10 != ctx->r1) {
        // 0x8007C510: nop

            goto L_8007C51C;
    }
    // 0x8007C510: nop

L_8007C514:
    // 0x8007C514: jal         0x8007B710
    // 0x8007C518: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007B710(rdram, ctx);
        goto after_21;
    // 0x8007C518: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
L_8007C51C:
    // 0x8007C51C: b           L_8007C53C
    // 0x8007C520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007C520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C524:
    // 0x8007C524: b           L_8007C53C
    // 0x8007C528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007C53C;
    // 0x8007C528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007C52C:
    // 0x8007C52C: b           L_8007C53C
    // 0x8007C530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007C530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C534: b           L_8007C53C
    // 0x8007C538: nop

        goto L_8007C53C;
    // 0x8007C538: nop

L_8007C53C:
    // 0x8007C53C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C540: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007C544: jr          $ra
    // 0x8007C548: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007C548: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8007C54C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C54C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C550: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C554: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007C558: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007C55C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C560: nop

    // 0x8007C564: beq         $t6, $zero, L_8007C914
    if (ctx->r14 == 0) {
        // 0x8007C568: nop

            goto L_8007C914;
    }
    // 0x8007C568: nop

    // 0x8007C56C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C570: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007C574: addiu       $a0, $a0, 0x7190
    ctx->r4 = ADD32(ctx->r4, 0X7190);
    // 0x8007C578: jal         0x800BCFCC
    // 0x8007C57C: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x8007C57C: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_0:
    // 0x8007C580: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C584: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C588: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x8007C58C: nop

    // 0x8007C590: beq         $s0, $at, L_8007C5B8
    if (ctx->r16 == ctx->r1) {
        // 0x8007C594: nop

            goto L_8007C5B8;
    }
    // 0x8007C594: nop

    // 0x8007C598: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007C59C: beq         $s0, $at, L_8007C874
    if (ctx->r16 == ctx->r1) {
        // 0x8007C5A0: nop

            goto L_8007C874;
    }
    // 0x8007C5A0: nop

    // 0x8007C5A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007C5A8: beq         $s0, $at, L_8007C874
    if (ctx->r16 == ctx->r1) {
        // 0x8007C5AC: nop

            goto L_8007C874;
    }
    // 0x8007C5AC: nop

    // 0x8007C5B0: b           L_8007C90C
    // 0x8007C5B4: nop

        goto L_8007C90C;
    // 0x8007C5B4: nop

L_8007C5B8:
    // 0x8007C5B8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007C5BC: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007C5C0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007C5C4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8007C5C8:
    // 0x8007C5C8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007C5CC: nop

    // 0x8007C5D0: bne         $t9, $zero, L_8007C5E0
    if (ctx->r25 != 0) {
        // 0x8007C5D4: nop

            goto L_8007C5E0;
    }
    // 0x8007C5D4: nop

    // 0x8007C5D8: b           L_8007C6D0
    // 0x8007C5DC: nop

        goto L_8007C6D0;
    // 0x8007C5DC: nop

L_8007C5E0:
    // 0x8007C5E0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007C5E4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007C5E8: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x8007C5EC: nop

    // 0x8007C5F0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8007C5F4: sw          $t2, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r10;
    // 0x8007C5F8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007C5FC: nop

    // 0x8007C600: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x8007C604: nop

    // 0x8007C608: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8007C60C: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x8007C610: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C614: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007C618: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8007C61C: nop

    // 0x8007C620: swc1        $f4, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f4.u32l;
    // 0x8007C624: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007C628: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007C62C: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8007C630: nop

    // 0x8007C634: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8007C638: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007C63C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007C640: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8007C644: nop

    // 0x8007C648: swc1        $f8, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f8.u32l;
    // 0x8007C64C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007C650: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007C654: lwc1        $f10, 0x10($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8007C658: nop

    // 0x8007C65C: swc1        $f10, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f10.u32l;
    // 0x8007C660: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007C664: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007C668: lwc1        $f16, 0x14($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8007C66C: nop

    // 0x8007C670: swc1        $f16, 0xE8($t3)
    MEM_W(0XE8, ctx->r11) = ctx->f16.u32l;
    // 0x8007C674: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C678: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007C67C: lwc1        $f18, 0x18($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X18);
    // 0x8007C680: nop

    // 0x8007C684: swc1        $f18, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f18.u32l;
    // 0x8007C688: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007C68C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007C690: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8007C694: nop

    // 0x8007C698: swc1        $f4, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f4.u32l;
    // 0x8007C69C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007C6A0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007C6A4: lhu         $t2, 0x20($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X20);
    // 0x8007C6A8: nop

    // 0x8007C6AC: sh          $t2, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r10;
    // 0x8007C6B0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007C6B4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007C6B8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007C6BC: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8007C6C0: addiu       $t6, $t3, 0x160
    ctx->r14 = ADD32(ctx->r11, 0X160);
    // 0x8007C6C4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8007C6C8: bne         $at, $zero, L_8007C5C8
    if (ctx->r1 != 0) {
        // 0x8007C6CC: sw          $t5, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r13;
            goto L_8007C5C8;
    }
    // 0x8007C6CC: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8007C6D0:
    // 0x8007C6D0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C6D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C6D8: lwc1        $f6, 0x24($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X24);
    // 0x8007C6DC: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8007C6E0: lwc1        $f16, 0x44($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8007C6E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007C6E8: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007C6EC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007C6F0: swc1        $f18, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f18.u32l;
    // 0x8007C6F4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007C6F8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C6FC: lwc1        $f4, 0x28($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X28);
    // 0x8007C700: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8007C704: lwc1        $f10, 0x44($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8007C708: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007C70C: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007C710: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007C714: swc1        $f16, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = ctx->f16.u32l;
    // 0x8007C718: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007C71C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C720: lwc1        $f18, 0x2C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X2C);
    // 0x8007C724: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8007C728: lwc1        $f8, 0x44($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X44);
    // 0x8007C72C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007C730: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007C734: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007C738: swc1        $f10, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f10.u32l;
    // 0x8007C73C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007C740: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C744: lwc1        $f16, 0x30($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X30);
    // 0x8007C748: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8007C74C: lwc1        $f6, 0x44($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8007C750: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007C754: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007C758: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007C75C: swc1        $f8, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->f8.u32l;
    // 0x8007C760: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C764: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007C768: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x8007C76C: lwc1        $f16, 0x14($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8007C770: lwc1        $f4, 0x44($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X44);
    // 0x8007C774: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8007C778: addiu       $t5, $t5, 0x7190
    ctx->r13 = ADD32(ctx->r13, 0X7190);
    // 0x8007C77C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007C780: swc1        $f6, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f6.u32l;
    // 0x8007C784: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C788: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C78C: lwc1        $f8, 0x38($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X38);
    // 0x8007C790: lwc1        $f10, 0x18($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X18);
    // 0x8007C794: lwc1        $f18, 0x44($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8007C798: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8007C79C: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007C7A0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007C7A4: swc1        $f4, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f4.u32l;
    // 0x8007C7A8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007C7AC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C7B0: lwc1        $f6, 0x3C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x8007C7B4: lwc1        $f8, 0x1C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8007C7B8: lwc1        $f16, 0x44($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8007C7BC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007C7C0: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007C7C4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007C7C8: swc1        $f18, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->f18.u32l;
    // 0x8007C7CC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007C7D0: nop

    // 0x8007C7D4: lhu         $t0, 0x40($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0X40);
    // 0x8007C7D8: nop

    // 0x8007C7DC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8007C7E0: bgez        $t0, L_8007C7F8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007C7E4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8007C7F8;
    }
    // 0x8007C7E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007C7E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007C7EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C7F0: nop

    // 0x8007C7F4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8007C7F8:
    // 0x8007C7F8: lhu         $t4, 0x20($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X20);
    // 0x8007C7FC: nop

    // 0x8007C800: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8007C804: bgez        $t4, L_8007C81C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007C808: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8007C81C;
    }
    // 0x8007C808: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007C80C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007C810: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007C814: nop

    // 0x8007C818: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8007C81C:
    // 0x8007C81C: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8007C820: lwc1        $f8, 0x44($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X44);
    // 0x8007C824: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C828: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8007C82C: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007C830: swc1        $f10, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->f10.u32l;
    // 0x8007C834: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C838: nop

    // 0x8007C83C: lhu         $t5, 0x20($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X20);
    // 0x8007C840: nop

    // 0x8007C844: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8007C848: bgez        $t5, L_8007C860
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007C84C: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8007C860;
    }
    // 0x8007C84C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007C850: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007C854: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007C858: nop

    // 0x8007C85C: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_8007C860:
    // 0x8007C860: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007C864: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007C868: swc1        $f6, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->f6.u32l;
    // 0x8007C86C: b           L_8007C90C
    // 0x8007C870: nop

        goto L_8007C90C;
    // 0x8007C870: nop

L_8007C874:
    // 0x8007C874: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007C878: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007C87C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007C880: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C884: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C888: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8007C88C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007C890: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007C894: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8007C898: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8007C89C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007C8A0: sh          $t1, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r9;
    // 0x8007C8A4: nop

    // 0x8007C8A8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007C8AC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C8B0: lwc1        $f10, 0x44($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8007C8B4: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007C8B8: swc1        $f10, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f10.u32l;
    // 0x8007C8BC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8007C8C0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C8C4: lwc1        $f18, 0x24($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X24);
    // 0x8007C8C8: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007C8CC: swc1        $f18, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f18.u32l;
    // 0x8007C8D0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007C8D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007C8D8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8007C8DC: nop

    // 0x8007C8E0: bne         $t7, $at, L_8007C904
    if (ctx->r15 != ctx->r1) {
        // 0x8007C8E4: nop

            goto L_8007C904;
    }
    // 0x8007C8E4: nop

    // 0x8007C8E8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007C8EC: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007C8F0: nop

    // 0x8007C8F4: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x8007C8F8: nop

    // 0x8007C8FC: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x8007C900: sw          $t1, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r9;
L_8007C904:
    // 0x8007C904: b           L_8007C90C
    // 0x8007C908: nop

        goto L_8007C90C;
    // 0x8007C908: nop

L_8007C90C:
    // 0x8007C90C: b           L_8007D528
    // 0x8007C910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007D528;
    // 0x8007C910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C914:
    // 0x8007C914: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007C918: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8007C91C: lw          $s0, 0x7190($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7190);
    // 0x8007C920: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C924: beq         $s0, $at, L_8007C94C
    if (ctx->r16 == ctx->r1) {
        // 0x8007C928: nop

            goto L_8007C94C;
    }
    // 0x8007C928: nop

    // 0x8007C92C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007C930: beq         $s0, $at, L_8007D344
    if (ctx->r16 == ctx->r1) {
        // 0x8007C934: nop

            goto L_8007D344;
    }
    // 0x8007C934: nop

    // 0x8007C938: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007C93C: beq         $s0, $at, L_8007D344
    if (ctx->r16 == ctx->r1) {
        // 0x8007C940: nop

            goto L_8007D344;
    }
    // 0x8007C940: nop

    // 0x8007C944: b           L_8007D500
    // 0x8007C948: nop

        goto L_8007D500;
    // 0x8007C948: nop

L_8007C94C:
    // 0x8007C94C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C950: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007C954: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007C958: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007C95C: lwc1        $f16, 0x48($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8007C960: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007C964: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8007C968: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007C96C: nop

    // 0x8007C970: lwc1        $f8, 0xCC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8007C974: nop

    // 0x8007C978: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8007C97C: swc1        $f10, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f10.u32l;
    // 0x8007C980: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C984: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007C988: lwc1        $f18, 0x48($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X48);
    // 0x8007C98C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007C990: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007C994: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007C998: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x8007C99C: nop

    // 0x8007C9A0: bc1t        L_8007CA3C
    if (c1cs) {
        // 0x8007C9A4: nop

            goto L_8007CA3C;
    }
    // 0x8007C9A4: nop

    // 0x8007C9A8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007C9AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007C9B0: nop

    // 0x8007C9B4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x8007C9B8: nop

    // 0x8007C9BC: bc1f        L_8007C9EC
    if (!c1cs) {
        // 0x8007C9C0: nop

            goto L_8007C9EC;
    }
    // 0x8007C9C0: nop

    // 0x8007C9C4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007C9C8: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007C9CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C9D0: lwc1        $f10, 0x71B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71B4);
    // 0x8007C9D4: lwc1        $f4, 0xCC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x8007C9D8: nop

    // 0x8007C9DC: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8007C9E0: nop

    // 0x8007C9E4: bc1t        L_8007CA3C
    if (c1cs) {
        // 0x8007C9E8: nop

            goto L_8007CA3C;
    }
    // 0x8007C9E8: nop

L_8007C9EC:
    // 0x8007C9EC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C9F0: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007C9F4: lwc1        $f18, 0x48($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8007C9F8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8007C9FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007CA00: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CA04: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8007CA08: nop

    // 0x8007CA0C: bc1f        L_8007CA54
    if (!c1cs) {
        // 0x8007CA10: nop

            goto L_8007CA54;
    }
    // 0x8007CA10: nop

    // 0x8007CA14: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007CA18: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007CA1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CA20: lwc1        $f4, 0x71B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71B4);
    // 0x8007CA24: lwc1        $f8, 0xCC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8007CA28: nop

    // 0x8007CA2C: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8007CA30: nop

    // 0x8007CA34: bc1f        L_8007CA54
    if (!c1cs) {
        // 0x8007CA38: nop

            goto L_8007CA54;
    }
    // 0x8007CA38: nop

L_8007CA3C:
    // 0x8007CA3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CA40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007CA44: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007CA48: lwc1        $f10, 0x71B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71B4);
    // 0x8007CA4C: b           L_8007CA5C
    // 0x8007CA50: swc1        $f10, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f10.u32l;
        goto L_8007CA5C;
    // 0x8007CA50: swc1        $f10, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f10.u32l;
L_8007CA54:
    // 0x8007CA54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007CA58: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8007CA5C:
    // 0x8007CA5C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007CA60: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007CA64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CA68: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CA6C: lwc1        $f18, 0x4C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4C);
    // 0x8007CA70: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007CA74: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8007CA78: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007CA7C: nop

    // 0x8007CA80: lwc1        $f8, 0xD0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8007CA84: nop

    // 0x8007CA88: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007CA8C: swc1        $f4, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f4.u32l;
    // 0x8007CA90: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007CA94: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007CA98: lwc1        $f10, 0x4C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x8007CA9C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CAA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CAA4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CAA8: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x8007CAAC: nop

    // 0x8007CAB0: bc1t        L_8007CB4C
    if (c1cs) {
        // 0x8007CAB4: nop

            goto L_8007CB4C;
    }
    // 0x8007CAB4: nop

    // 0x8007CAB8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CABC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CAC0: nop

    // 0x8007CAC4: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x8007CAC8: nop

    // 0x8007CACC: bc1f        L_8007CAFC
    if (!c1cs) {
        // 0x8007CAD0: nop

            goto L_8007CAFC;
    }
    // 0x8007CAD0: nop

    // 0x8007CAD4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007CAD8: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007CADC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CAE0: lwc1        $f4, 0x71B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71B8);
    // 0x8007CAE4: lwc1        $f16, 0xD0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8007CAE8: nop

    // 0x8007CAEC: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x8007CAF0: nop

    // 0x8007CAF4: bc1t        L_8007CB4C
    if (c1cs) {
        // 0x8007CAF8: nop

            goto L_8007CB4C;
    }
    // 0x8007CAF8: nop

L_8007CAFC:
    // 0x8007CAFC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007CB00: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007CB04: lwc1        $f10, 0x4C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4C);
    // 0x8007CB08: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007CB0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007CB10: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CB14: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8007CB18: nop

    // 0x8007CB1C: bc1f        L_8007CB64
    if (!c1cs) {
        // 0x8007CB20: nop

            goto L_8007CB64;
    }
    // 0x8007CB20: nop

    // 0x8007CB24: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007CB28: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007CB2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CB30: lwc1        $f16, 0x71B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71B8);
    // 0x8007CB34: lwc1        $f8, 0xD0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8007CB38: nop

    // 0x8007CB3C: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x8007CB40: nop

    // 0x8007CB44: bc1f        L_8007CB64
    if (!c1cs) {
        // 0x8007CB48: nop

            goto L_8007CB64;
    }
    // 0x8007CB48: nop

L_8007CB4C:
    // 0x8007CB4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CB50: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007CB54: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007CB58: lwc1        $f4, 0x71B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71B8);
    // 0x8007CB5C: b           L_8007CB6C
    // 0x8007CB60: swc1        $f4, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f4.u32l;
        goto L_8007CB6C;
    // 0x8007CB60: swc1        $f4, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f4.u32l;
L_8007CB64:
    // 0x8007CB64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007CB68: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_8007CB6C:
    // 0x8007CB6C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007CB70: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007CB74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CB78: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CB7C: lwc1        $f10, 0x50($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X50);
    // 0x8007CB80: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007CB84: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8007CB88: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007CB8C: nop

    // 0x8007CB90: lwc1        $f8, 0xF4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF4);
    // 0x8007CB94: nop

    // 0x8007CB98: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8007CB9C: swc1        $f16, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f16.u32l;
    // 0x8007CBA0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007CBA4: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007CBA8: lwc1        $f4, 0x50($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X50);
    // 0x8007CBAC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CBB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CBB4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CBB8: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x8007CBBC: nop

    // 0x8007CBC0: bc1t        L_8007CC5C
    if (c1cs) {
        // 0x8007CBC4: nop

            goto L_8007CC5C;
    }
    // 0x8007CBC4: nop

    // 0x8007CBC8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CBCC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CBD0: nop

    // 0x8007CBD4: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8007CBD8: nop

    // 0x8007CBDC: bc1f        L_8007CC0C
    if (!c1cs) {
        // 0x8007CBE0: nop

            goto L_8007CC0C;
    }
    // 0x8007CBE0: nop

    // 0x8007CBE4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007CBE8: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007CBEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CBF0: lwc1        $f16, 0x71BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71BC);
    // 0x8007CBF4: lwc1        $f18, 0xF4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x8007CBF8: nop

    // 0x8007CBFC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x8007CC00: nop

    // 0x8007CC04: bc1t        L_8007CC5C
    if (c1cs) {
        // 0x8007CC08: nop

            goto L_8007CC5C;
    }
    // 0x8007CC08: nop

L_8007CC0C:
    // 0x8007CC0C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007CC10: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007CC14: lwc1        $f4, 0x50($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X50);
    // 0x8007CC18: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007CC1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007CC20: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CC24: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8007CC28: nop

    // 0x8007CC2C: bc1f        L_8007CC74
    if (!c1cs) {
        // 0x8007CC30: nop

            goto L_8007CC74;
    }
    // 0x8007CC30: nop

    // 0x8007CC34: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007CC38: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007CC3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CC40: lwc1        $f18, 0x71BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71BC);
    // 0x8007CC44: lwc1        $f8, 0xF4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x8007CC48: nop

    // 0x8007CC4C: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8007CC50: nop

    // 0x8007CC54: bc1f        L_8007CC74
    if (!c1cs) {
        // 0x8007CC58: nop

            goto L_8007CC74;
    }
    // 0x8007CC58: nop

L_8007CC5C:
    // 0x8007CC5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CC60: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007CC64: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8007CC68: lwc1        $f16, 0x71BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71BC);
    // 0x8007CC6C: b           L_8007CC7C
    // 0x8007CC70: swc1        $f16, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f16.u32l;
        goto L_8007CC7C;
    // 0x8007CC70: swc1        $f16, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f16.u32l;
L_8007CC74:
    // 0x8007CC74: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007CC78: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_8007CC7C:
    // 0x8007CC7C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007CC80: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007CC84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CC88: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CC8C: lwc1        $f4, 0x54($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X54);
    // 0x8007CC90: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007CC94: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007CC98: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007CC9C: nop

    // 0x8007CCA0: lwc1        $f8, 0xF8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x8007CCA4: nop

    // 0x8007CCA8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007CCAC: swc1        $f18, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f18.u32l;
    // 0x8007CCB0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007CCB4: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007CCB8: lwc1        $f16, 0x54($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X54);
    // 0x8007CCBC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CCC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CCC4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8007CCC8: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8007CCCC: nop

    // 0x8007CCD0: bc1t        L_8007CD6C
    if (c1cs) {
        // 0x8007CCD4: nop

            goto L_8007CD6C;
    }
    // 0x8007CCD4: nop

    // 0x8007CCD8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CCDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CCE0: nop

    // 0x8007CCE4: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x8007CCE8: nop

    // 0x8007CCEC: bc1f        L_8007CD1C
    if (!c1cs) {
        // 0x8007CCF0: nop

            goto L_8007CD1C;
    }
    // 0x8007CCF0: nop

    // 0x8007CCF4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007CCF8: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007CCFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CD00: lwc1        $f18, 0x71C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71C0);
    // 0x8007CD04: lwc1        $f10, 0xF8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x8007CD08: nop

    // 0x8007CD0C: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x8007CD10: nop

    // 0x8007CD14: bc1t        L_8007CD6C
    if (c1cs) {
        // 0x8007CD18: nop

            goto L_8007CD6C;
    }
    // 0x8007CD18: nop

L_8007CD1C:
    // 0x8007CD1C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007CD20: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007CD24: lwc1        $f16, 0x54($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X54);
    // 0x8007CD28: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8007CD2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007CD30: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8007CD34: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8007CD38: nop

    // 0x8007CD3C: bc1f        L_8007CD84
    if (!c1cs) {
        // 0x8007CD40: nop

            goto L_8007CD84;
    }
    // 0x8007CD40: nop

    // 0x8007CD44: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007CD48: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007CD4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CD50: lwc1        $f10, 0x71C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71C0);
    // 0x8007CD54: lwc1        $f8, 0xF8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x8007CD58: nop

    // 0x8007CD5C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x8007CD60: nop

    // 0x8007CD64: bc1f        L_8007CD84
    if (!c1cs) {
        // 0x8007CD68: nop

            goto L_8007CD84;
    }
    // 0x8007CD68: nop

L_8007CD6C:
    // 0x8007CD6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CD70: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007CD74: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8007CD78: lwc1        $f18, 0x71C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71C0);
    // 0x8007CD7C: b           L_8007CD8C
    // 0x8007CD80: swc1        $f18, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f18.u32l;
        goto L_8007CD8C;
    // 0x8007CD80: swc1        $f18, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f18.u32l;
L_8007CD84:
    // 0x8007CD84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007CD88: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8007CD8C:
    // 0x8007CD8C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007CD90: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007CD94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CD98: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CD9C: lwc1        $f16, 0x58($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X58);
    // 0x8007CDA0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007CDA4: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8007CDA8: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007CDAC: nop

    // 0x8007CDB0: lwc1        $f8, 0xE8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XE8);
    // 0x8007CDB4: nop

    // 0x8007CDB8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8007CDBC: swc1        $f10, 0xE8($t3)
    MEM_W(0XE8, ctx->r11) = ctx->f10.u32l;
    // 0x8007CDC0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007CDC4: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007CDC8: lwc1        $f18, 0x58($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8007CDCC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CDD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CDD4: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CDD8: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x8007CDDC: nop

    // 0x8007CDE0: bc1t        L_8007CE7C
    if (c1cs) {
        // 0x8007CDE4: nop

            goto L_8007CE7C;
    }
    // 0x8007CDE4: nop

    // 0x8007CDE8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CDEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CDF0: nop

    // 0x8007CDF4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x8007CDF8: nop

    // 0x8007CDFC: bc1f        L_8007CE2C
    if (!c1cs) {
        // 0x8007CE00: nop

            goto L_8007CE2C;
    }
    // 0x8007CE00: nop

    // 0x8007CE04: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007CE08: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007CE0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CE10: lwc1        $f10, 0x71C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71C4);
    // 0x8007CE14: lwc1        $f4, 0xE8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x8007CE18: nop

    // 0x8007CE1C: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8007CE20: nop

    // 0x8007CE24: bc1t        L_8007CE7C
    if (c1cs) {
        // 0x8007CE28: nop

            goto L_8007CE7C;
    }
    // 0x8007CE28: nop

L_8007CE2C:
    // 0x8007CE2C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007CE30: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007CE34: lwc1        $f18, 0x58($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X58);
    // 0x8007CE38: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8007CE3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007CE40: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CE44: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8007CE48: nop

    // 0x8007CE4C: bc1f        L_8007CE94
    if (!c1cs) {
        // 0x8007CE50: nop

            goto L_8007CE94;
    }
    // 0x8007CE50: nop

    // 0x8007CE54: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007CE58: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007CE5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CE60: lwc1        $f4, 0x71C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71C4);
    // 0x8007CE64: lwc1        $f8, 0xE8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XE8);
    // 0x8007CE68: nop

    // 0x8007CE6C: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8007CE70: nop

    // 0x8007CE74: bc1f        L_8007CE94
    if (!c1cs) {
        // 0x8007CE78: nop

            goto L_8007CE94;
    }
    // 0x8007CE78: nop

L_8007CE7C:
    // 0x8007CE7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CE80: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007CE84: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8007CE88: lwc1        $f10, 0x71C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71C4);
    // 0x8007CE8C: b           L_8007CE9C
    // 0x8007CE90: swc1        $f10, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f10.u32l;
        goto L_8007CE9C;
    // 0x8007CE90: swc1        $f10, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f10.u32l;
L_8007CE94:
    // 0x8007CE94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007CE98: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8007CE9C:
    // 0x8007CE9C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007CEA0: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007CEA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CEA8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CEAC: lwc1        $f18, 0x5C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x8007CEB0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007CEB4: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8007CEB8: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007CEBC: nop

    // 0x8007CEC0: lwc1        $f8, 0xEC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XEC);
    // 0x8007CEC4: nop

    // 0x8007CEC8: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007CECC: swc1        $f4, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f4.u32l;
    // 0x8007CED0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007CED4: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007CED8: lwc1        $f10, 0x5C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X5C);
    // 0x8007CEDC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CEE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CEE4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CEE8: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x8007CEEC: nop

    // 0x8007CEF0: bc1t        L_8007CF8C
    if (c1cs) {
        // 0x8007CEF4: nop

            goto L_8007CF8C;
    }
    // 0x8007CEF4: nop

    // 0x8007CEF8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CEFC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CF00: nop

    // 0x8007CF04: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x8007CF08: nop

    // 0x8007CF0C: bc1f        L_8007CF3C
    if (!c1cs) {
        // 0x8007CF10: nop

            goto L_8007CF3C;
    }
    // 0x8007CF10: nop

    // 0x8007CF14: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007CF18: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007CF1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CF20: lwc1        $f4, 0x71C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71C8);
    // 0x8007CF24: lwc1        $f16, 0xEC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XEC);
    // 0x8007CF28: nop

    // 0x8007CF2C: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x8007CF30: nop

    // 0x8007CF34: bc1t        L_8007CF8C
    if (c1cs) {
        // 0x8007CF38: nop

            goto L_8007CF8C;
    }
    // 0x8007CF38: nop

L_8007CF3C:
    // 0x8007CF3C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007CF40: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007CF44: lwc1        $f10, 0x5C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x8007CF48: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007CF4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007CF50: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CF54: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8007CF58: nop

    // 0x8007CF5C: bc1f        L_8007CFA4
    if (!c1cs) {
        // 0x8007CF60: nop

            goto L_8007CFA4;
    }
    // 0x8007CF60: nop

    // 0x8007CF64: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007CF68: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007CF6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CF70: lwc1        $f16, 0x71C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71C8);
    // 0x8007CF74: lwc1        $f8, 0xEC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XEC);
    // 0x8007CF78: nop

    // 0x8007CF7C: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x8007CF80: nop

    // 0x8007CF84: bc1f        L_8007CFA4
    if (!c1cs) {
        // 0x8007CF88: nop

            goto L_8007CFA4;
    }
    // 0x8007CF88: nop

L_8007CF8C:
    // 0x8007CF8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CF90: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007CF94: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007CF98: lwc1        $f4, 0x71C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71C8);
    // 0x8007CF9C: b           L_8007CFAC
    // 0x8007CFA0: swc1        $f4, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f4.u32l;
        goto L_8007CFAC;
    // 0x8007CFA0: swc1        $f4, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f4.u32l;
L_8007CFA4:
    // 0x8007CFA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007CFA8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8007CFAC:
    // 0x8007CFAC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007CFB0: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007CFB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CFB8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CFBC: lwc1        $f10, 0x60($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X60);
    // 0x8007CFC0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007CFC4: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8007CFC8: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007CFCC: nop

    // 0x8007CFD0: lwc1        $f8, 0xF0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8007CFD4: nop

    // 0x8007CFD8: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8007CFDC: swc1        $f16, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f16.u32l;
    // 0x8007CFE0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007CFE4: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007CFE8: lwc1        $f4, 0x60($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X60);
    // 0x8007CFEC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CFF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CFF4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CFF8: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x8007CFFC: nop

    // 0x8007D000: bc1t        L_8007D09C
    if (c1cs) {
        // 0x8007D004: nop

            goto L_8007D09C;
    }
    // 0x8007D004: nop

    // 0x8007D008: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007D00C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007D010: nop

    // 0x8007D014: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8007D018: nop

    // 0x8007D01C: bc1f        L_8007D04C
    if (!c1cs) {
        // 0x8007D020: nop

            goto L_8007D04C;
    }
    // 0x8007D020: nop

    // 0x8007D024: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007D028: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007D02C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D030: lwc1        $f16, 0x71CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71CC);
    // 0x8007D034: lwc1        $f18, 0xF0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x8007D038: nop

    // 0x8007D03C: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x8007D040: nop

    // 0x8007D044: bc1t        L_8007D09C
    if (c1cs) {
        // 0x8007D048: nop

            goto L_8007D09C;
    }
    // 0x8007D048: nop

L_8007D04C:
    // 0x8007D04C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007D050: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007D054: lwc1        $f4, 0x60($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X60);
    // 0x8007D058: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007D05C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007D060: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007D064: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8007D068: nop

    // 0x8007D06C: bc1f        L_8007D0B4
    if (!c1cs) {
        // 0x8007D070: nop

            goto L_8007D0B4;
    }
    // 0x8007D070: nop

    // 0x8007D074: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007D078: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007D07C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D080: lwc1        $f18, 0x71CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71CC);
    // 0x8007D084: lwc1        $f8, 0xF0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XF0);
    // 0x8007D088: nop

    // 0x8007D08C: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8007D090: nop

    // 0x8007D094: bc1f        L_8007D0B4
    if (!c1cs) {
        // 0x8007D098: nop

            goto L_8007D0B4;
    }
    // 0x8007D098: nop

L_8007D09C:
    // 0x8007D09C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D0A0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007D0A4: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007D0A8: lwc1        $f16, 0x71CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71CC);
    // 0x8007D0AC: b           L_8007D0BC
    // 0x8007D0B0: swc1        $f16, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f16.u32l;
        goto L_8007D0BC;
    // 0x8007D0B0: swc1        $f16, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f16.u32l;
L_8007D0B4:
    // 0x8007D0B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007D0B8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_8007D0BC:
    // 0x8007D0BC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007D0C0: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007D0C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D0C8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007D0CC: lwc1        $f4, 0x64($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X64);
    // 0x8007D0D0: lwc1        $f8, 0x68($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X68);
    // 0x8007D0D4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007D0D8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007D0DC: swc1        $f18, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->f18.u32l;
    // 0x8007D0E0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007D0E4: addiu       $t9, $t9, 0x7190
    ctx->r25 = ADD32(ctx->r25, 0X7190);
    // 0x8007D0E8: lwc1        $f16, 0x64($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X64);
    // 0x8007D0EC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007D0F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007D0F4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8007D0F8: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8007D0FC: nop

    // 0x8007D100: bc1t        L_8007D1BC
    if (c1cs) {
        // 0x8007D104: nop

            goto L_8007D1BC;
    }
    // 0x8007D104: nop

    // 0x8007D108: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007D10C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007D110: nop

    // 0x8007D114: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x8007D118: nop

    // 0x8007D11C: bc1f        L_8007D15C
    if (!c1cs) {
        // 0x8007D120: nop

            goto L_8007D15C;
    }
    // 0x8007D120: nop

    // 0x8007D124: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007D128: lhu         $t1, 0x71D0($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X71D0);
    // 0x8007D12C: lwc1        $f10, 0x68($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X68);
    // 0x8007D130: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8007D134: bgez        $t1, L_8007D14C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8007D138: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8007D14C;
    }
    // 0x8007D138: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007D13C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007D140: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007D144: nop

    // 0x8007D148: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_8007D14C:
    // 0x8007D14C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8007D150: nop

    // 0x8007D154: bc1t        L_8007D1BC
    if (c1cs) {
        // 0x8007D158: nop

            goto L_8007D1BC;
    }
    // 0x8007D158: nop

L_8007D15C:
    // 0x8007D15C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007D160: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007D164: lwc1        $f4, 0x64($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X64);
    // 0x8007D168: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007D16C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007D170: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007D174: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x8007D178: nop

    // 0x8007D17C: bc1f        L_8007D1D4
    if (!c1cs) {
        // 0x8007D180: nop

            goto L_8007D1D4;
    }
    // 0x8007D180: nop

    // 0x8007D184: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007D188: lhu         $t0, 0x71D0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X71D0);
    // 0x8007D18C: lwc1        $f6, 0x68($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X68);
    // 0x8007D190: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8007D194: bgez        $t0, L_8007D1AC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007D198: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8007D1AC;
    }
    // 0x8007D198: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007D19C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007D1A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007D1A4: nop

    // 0x8007D1A8: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8007D1AC:
    // 0x8007D1AC: c.le.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl <= ctx->f16.fl;
    // 0x8007D1B0: nop

    // 0x8007D1B4: bc1f        L_8007D1D4
    if (!c1cs) {
        // 0x8007D1B8: nop

            goto L_8007D1D4;
    }
    // 0x8007D1B8: nop

L_8007D1BC:
    // 0x8007D1BC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007D1C0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007D1C4: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8007D1C8: lhu         $t4, 0x71D0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X71D0);
    // 0x8007D1CC: b           L_8007D214
    // 0x8007D1D0: sh          $t4, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r12;
        goto L_8007D214;
    // 0x8007D1D0: sh          $t4, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r12;
L_8007D1D4:
    // 0x8007D1D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007D1D8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D1DC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8007D1E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007D1E4: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007D1E8: lwc1        $f8, 0x68($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X68);
    // 0x8007D1EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007D1F0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007D1F4: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007D1F8: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007D1FC: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8007D200: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007D204: sh          $t5, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r13;
    // 0x8007D208: nop

    // 0x8007D20C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007D210: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8007D214:
    // 0x8007D214: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007D218: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007D21C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007D220: addiu       $t0, $t8, 0x160
    ctx->r8 = ADD32(ctx->r24, 0X160);
    // 0x8007D224: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8007D228: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_8007D22C:
    // 0x8007D22C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007D230: nop

    // 0x8007D234: bne         $t4, $zero, L_8007D244
    if (ctx->r12 != 0) {
        // 0x8007D238: nop

            goto L_8007D244;
    }
    // 0x8007D238: nop

    // 0x8007D23C: b           L_8007D324
    // 0x8007D240: nop

        goto L_8007D324;
    // 0x8007D240: nop

L_8007D244:
    // 0x8007D244: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007D248: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8007D24C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007D250: lwc1        $f10, 0xCC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8007D254: nop

    // 0x8007D258: swc1        $f10, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f10.u32l;
    // 0x8007D25C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007D260: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007D264: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007D268: lwc1        $f4, 0xD0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8007D26C: nop

    // 0x8007D270: swc1        $f4, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f4.u32l;
    // 0x8007D274: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007D278: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007D27C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007D280: lwc1        $f6, 0xF4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x8007D284: nop

    // 0x8007D288: swc1        $f6, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f6.u32l;
    // 0x8007D28C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007D290: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8007D294: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8007D298: lwc1        $f16, 0xF8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x8007D29C: nop

    // 0x8007D2A0: swc1        $f16, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f16.u32l;
    // 0x8007D2A4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007D2A8: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8007D2AC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2B0: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8007D2B4: nop

    // 0x8007D2B8: swc1        $f8, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f8.u32l;
    // 0x8007D2BC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007D2C0: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8007D2C4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2C8: lwc1        $f18, 0xEC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XEC);
    // 0x8007D2CC: nop

    // 0x8007D2D0: swc1        $f18, 0xEC($t3)
    MEM_W(0XEC, ctx->r11) = ctx->f18.u32l;
    // 0x8007D2D4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007D2D8: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007D2DC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2E0: lwc1        $f10, 0xF0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XF0);
    // 0x8007D2E4: nop

    // 0x8007D2E8: swc1        $f10, 0xF0($t5)
    MEM_W(0XF0, ctx->r13) = ctx->f10.u32l;
    // 0x8007D2EC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007D2F0: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007D2F4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2F8: lh          $t9, 0x11E($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X11E);
    // 0x8007D2FC: nop

    // 0x8007D300: sh          $t9, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r25;
    // 0x8007D304: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007D308: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007D30C: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8007D310: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8007D314: addiu       $t2, $t4, 0x160
    ctx->r10 = ADD32(ctx->r12, 0X160);
    // 0x8007D318: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8007D31C: bne         $at, $zero, L_8007D22C
    if (ctx->r1 != 0) {
        // 0x8007D320: sw          $t0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r8;
            goto L_8007D22C;
    }
    // 0x8007D320: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_8007D324:
    // 0x8007D324: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D328: nop

    // 0x8007D32C: bne         $t3, $zero, L_8007D33C
    if (ctx->r11 != 0) {
        // 0x8007D330: nop

            goto L_8007D33C;
    }
    // 0x8007D330: nop

    // 0x8007D334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D338: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
L_8007D33C:
    // 0x8007D33C: b           L_8007D500
    // 0x8007D340: nop

        goto L_8007D500;
    // 0x8007D340: nop

L_8007D344:
    // 0x8007D344: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007D348: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007D34C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D350: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007D354: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8007D358: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007D35C: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007D360: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007D364: nop

    // 0x8007D368: lh          $t4, 0x11E($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X11E);
    // 0x8007D36C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8007D370: nop

    // 0x8007D374: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8007D378: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007D37C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007D380: nop

    // 0x8007D384: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007D388: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8007D38C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8007D390: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8007D394: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8007D398: addu        $t2, $t4, $t1
    ctx->r10 = ADD32(ctx->r12, ctx->r9);
    // 0x8007D39C: sh          $t2, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = ctx->r10;
    // 0x8007D3A0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007D3A4: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007D3A8: lwc1        $f18, 0x48($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8007D3AC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8007D3B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D3B4: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8007D3B8: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8007D3BC: nop

    // 0x8007D3C0: bc1f        L_8007D440
    if (!c1cs) {
        // 0x8007D3C4: nop

            goto L_8007D440;
    }
    // 0x8007D3C4: nop

    // 0x8007D3C8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007D3CC: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007D3D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007D3D4: lh          $t6, 0x11E($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X11E);
    // 0x8007D3D8: addiu       $t5, $t5, 0x7190
    ctx->r13 = ADD32(ctx->r13, 0X7190);
    // 0x8007D3DC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8007D3E0: lwc1        $f8, 0x4C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4C);
    // 0x8007D3E4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007D3E8: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x8007D3EC: nop

    // 0x8007D3F0: bc1f        L_8007D430
    if (!c1cs) {
        // 0x8007D3F4: nop

            goto L_8007D430;
    }
    // 0x8007D3F4: nop

    // 0x8007D3F8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007D3FC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007D400: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007D404: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007D408: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007D40C: lwc1        $f18, 0x4C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8007D410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007D414: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007D418: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007D41C: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8007D420: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8007D424: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007D428: b           L_8007D438
    // 0x8007D42C: sh          $t4, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r12;
        goto L_8007D438;
    // 0x8007D42C: sh          $t4, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r12;
L_8007D430:
    // 0x8007D430: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007D434: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8007D438:
    // 0x8007D438: b           L_8007D4B0
    // 0x8007D43C: nop

        goto L_8007D4B0;
    // 0x8007D43C: nop

L_8007D440:
    // 0x8007D440: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007D444: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007D448: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D44C: lh          $t0, 0x11E($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X11E);
    // 0x8007D450: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007D454: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8007D458: lwc1        $f16, 0x4C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X4C);
    // 0x8007D45C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007D460: c.le.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl <= ctx->f16.fl;
    // 0x8007D464: nop

    // 0x8007D468: bc1f        L_8007D4A8
    if (!c1cs) {
        // 0x8007D46C: nop

            goto L_8007D4A8;
    }
    // 0x8007D46C: nop

    // 0x8007D470: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8007D474: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007D478: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8007D47C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007D480: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007D484: lwc1        $f8, 0x4C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4C);
    // 0x8007D488: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007D48C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007D490: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007D494: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007D498: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8007D49C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8007D4A0: b           L_8007D4B0
    // 0x8007D4A4: sh          $t7, 0x11E($t9)
    MEM_H(0X11E, ctx->r25) = ctx->r15;
        goto L_8007D4B0;
    // 0x8007D4A4: sh          $t7, 0x11E($t9)
    MEM_H(0X11E, ctx->r25) = ctx->r15;
L_8007D4A8:
    // 0x8007D4A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007D4AC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8007D4B0:
    // 0x8007D4B0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D4B4: nop

    // 0x8007D4B8: bne         $t1, $zero, L_8007D4F8
    if (ctx->r9 != 0) {
        // 0x8007D4BC: nop

            goto L_8007D4F8;
    }
    // 0x8007D4BC: nop

    // 0x8007D4C0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007D4C4: lw          $t2, 0x7190($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7190);
    // 0x8007D4C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007D4CC: bne         $t2, $at, L_8007D4F0
    if (ctx->r10 != ctx->r1) {
        // 0x8007D4D0: nop

            goto L_8007D4F0;
    }
    // 0x8007D4D0: nop

    // 0x8007D4D4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007D4D8: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007D4DC: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8007D4E0: lw          $t0, 0xC0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC0);
    // 0x8007D4E4: nop

    // 0x8007D4E8: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8007D4EC: sw          $t3, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r11;
L_8007D4F0:
    // 0x8007D4F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D4F4: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
L_8007D4F8:
    // 0x8007D4F8: b           L_8007D500
    // 0x8007D4FC: nop

        goto L_8007D500;
    // 0x8007D4FC: nop

L_8007D500:
    // 0x8007D500: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D504: nop

    // 0x8007D508: beq         $t6, $zero, L_8007D518
    if (ctx->r14 == 0) {
        // 0x8007D50C: nop

            goto L_8007D518;
    }
    // 0x8007D50C: nop

    // 0x8007D510: b           L_8007D528
    // 0x8007D514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007D528;
    // 0x8007D514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007D518:
    // 0x8007D518: b           L_8007D528
    // 0x8007D51C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007D528;
    // 0x8007D51C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007D520: b           L_8007D528
    // 0x8007D524: nop

        goto L_8007D528;
    // 0x8007D524: nop

L_8007D528:
    // 0x8007D528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D52C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007D530: jr          $ra
    // 0x8007D534: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007D534: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8007D538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D538: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8007D53C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D540: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007D544: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007D548: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007D54C: nop

    // 0x8007D550: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8007D554: bne         $t7, $zero, L_8007D564
    if (ctx->r15 != 0) {
        // 0x8007D558: nop

            goto L_8007D564;
    }
    // 0x8007D558: nop

    // 0x8007D55C: b           L_8007DF2C
    // 0x8007D560: nop

        goto L_8007DF2C;
    // 0x8007D560: nop

L_8007D564:
    // 0x8007D564: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8007D568: jal         0x8001ABEC
    // 0x8007D56C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001ABEC(rdram, ctx);
        goto after_0;
    // 0x8007D56C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_0:
    // 0x8007D570: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007D574: jal         0x8008EAA8
    // 0x8007D578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_1;
    // 0x8007D578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8007D57C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D580: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007D584: swc1        $f4, -0x3974($at)
    MEM_W(-0X3974, ctx->r1) = ctx->f4.u32l;
    // 0x8007D588: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007D58C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007D590: swc1        $f6, -0x3970($at)
    MEM_W(-0X3970, ctx->r1) = ctx->f6.u32l;
    // 0x8007D594: jal         0x8007E94C
    // 0x8007D598: nop

    func_8007E94C(rdram, ctx);
        goto after_2;
    // 0x8007D598: nop

    after_2:
    // 0x8007D59C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007D5A0: lw          $t8, 0x7100($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7100);
    // 0x8007D5A4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007D5A8: bne         $t8, $at, L_8007D764
    if (ctx->r24 != ctx->r1) {
        // 0x8007D5AC: nop

            goto L_8007D764;
    }
    // 0x8007D5AC: nop

    // 0x8007D5B0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007D5B4: lw          $t9, 0x7104($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7104);
    // 0x8007D5B8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8007D5BC: bne         $t9, $at, L_8007D764
    if (ctx->r25 != ctx->r1) {
        // 0x8007D5C0: nop

            goto L_8007D764;
    }
    // 0x8007D5C0: nop

    // 0x8007D5C4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007D5C8: lb          $t0, 0x7140($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7140);
    // 0x8007D5CC: nop

    // 0x8007D5D0: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8007D5D4: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8007D5D8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8007D5DC: slti        $at, $t1, 0x28
    ctx->r1 = SIGNED(ctx->r9) < 0X28 ? 1 : 0;
    // 0x8007D5E0: beq         $at, $zero, L_8007D764
    if (ctx->r1 == 0) {
        // 0x8007D5E4: nop

            goto L_8007D764;
    }
    // 0x8007D5E4: nop

L_8007D5E8:
    // 0x8007D5E8: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8007D5EC: nop

    // 0x8007D5F0: slti        $at, $t2, 0x28
    ctx->r1 = SIGNED(ctx->r10) < 0X28 ? 1 : 0;
    // 0x8007D5F4: beq         $at, $zero, L_8007D644
    if (ctx->r1 == 0) {
        // 0x8007D5F8: nop

            goto L_8007D644;
    }
    // 0x8007D5F8: nop

L_8007D5FC:
    // 0x8007D5FC: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8007D600: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007D604: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007D608: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007D60C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007D610: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8007D614: lh          $t5, 0x2460($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2460);
    // 0x8007D618: nop

    // 0x8007D61C: bltz        $t5, L_8007D62C
    if (SIGNED(ctx->r13) < 0) {
        // 0x8007D620: nop

            goto L_8007D62C;
    }
    // 0x8007D620: nop

    // 0x8007D624: b           L_8007D644
    // 0x8007D628: nop

        goto L_8007D644;
    // 0x8007D628: nop

L_8007D62C:
    // 0x8007D62C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8007D630: nop

    // 0x8007D634: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007D638: slti        $at, $t7, 0x28
    ctx->r1 = SIGNED(ctx->r15) < 0X28 ? 1 : 0;
    // 0x8007D63C: bne         $at, $zero, L_8007D5FC
    if (ctx->r1 != 0) {
        // 0x8007D640: sw          $t7, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r15;
            goto L_8007D5FC;
    }
    // 0x8007D640: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
L_8007D644:
    // 0x8007D644: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8007D648: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007D64C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007D650: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007D654: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8007D658: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8007D65C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007D660: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007D664: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007D668: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007D66C: lw          $a2, 0x2458($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2458);
    // 0x8007D670: jal         0x800BD1FC
    // 0x8007D674: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8007D674: nop

    after_3:
    // 0x8007D678: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007D67C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D680: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007D684: jal         0x800BD218
    // 0x8007D688: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x8007D688: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_4:
    // 0x8007D68C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8007D690: jal         0x800805C4
    // 0x8007D694: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800805C4(rdram, ctx);
        goto after_5;
    // 0x8007D694: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_5:
    // 0x8007D698: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007D69C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8007D6A0: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8007D6A4: addiu       $a1, $a1, 0x6BA0
    ctx->r5 = ADD32(ctx->r5, 0X6BA0);
    // 0x8007D6A8: addiu       $a0, $a0, 0x6B98
    ctx->r4 = ADD32(ctx->r4, 0X6B98);
    // 0x8007D6AC: jal         0x8007EB90
    // 0x8007D6B0: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    func_8007EB90(rdram, ctx);
        goto after_6;
    // 0x8007D6B0: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    after_6:
    // 0x8007D6B4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8007D6B8: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x8007D6BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D6C0: addiu       $t1, $t0, 0x5
    ctx->r9 = ADD32(ctx->r8, 0X5);
    // 0x8007D6C4: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8007D6C8: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8007D6CC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007D6D0: lw          $t3, -0x3908($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3908);
    // 0x8007D6D4: lhu         $t2, 0x2A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2A);
    // 0x8007D6D8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8007D6DC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8007D6E0: sh          $t2, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r10;
    // 0x8007D6E4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8007D6E8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007D6EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D6F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007D6F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007D6F8: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x8007D6FC: lh          $a3, 0x2460($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X2460);
    // 0x8007D700: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8007D704: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8007D708: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x8007D70C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8007D710: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D714: addiu       $a0, $a0, -0xDD0
    ctx->r4 = ADD32(ctx->r4, -0XDD0);
    // 0x8007D718: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8007D71C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8007D720: jal         0x8008ECE4
    // 0x8007D724: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8007D724: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    after_7:
    // 0x8007D728: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8007D72C: nop

    // 0x8007D730: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007D734: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8007D738: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8007D73C: nop

    // 0x8007D740: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8007D744: slti        $at, $t3, 0x6
    ctx->r1 = SIGNED(ctx->r11) < 0X6 ? 1 : 0;
    // 0x8007D748: beq         $at, $zero, L_8007D764
    if (ctx->r1 == 0) {
        // 0x8007D74C: sw          $t3, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r11;
            goto L_8007D764;
    }
    // 0x8007D74C: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x8007D750: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8007D754: nop

    // 0x8007D758: slti        $at, $t5, 0x28
    ctx->r1 = SIGNED(ctx->r13) < 0X28 ? 1 : 0;
    // 0x8007D75C: bne         $at, $zero, L_8007D5E8
    if (ctx->r1 != 0) {
        // 0x8007D760: nop

            goto L_8007D5E8;
    }
    // 0x8007D760: nop

L_8007D764:
    // 0x8007D764: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007D768: lw          $t2, 0x7100($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7100);
    // 0x8007D76C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007D770: bne         $t2, $at, L_8007D9D4
    if (ctx->r10 != ctx->r1) {
        // 0x8007D774: nop

            goto L_8007D9D4;
    }
    // 0x8007D774: nop

    // 0x8007D778: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007D77C: lw          $t6, 0x7104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7104);
    // 0x8007D780: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007D784: beq         $t6, $at, L_8007D798
    if (ctx->r14 == ctx->r1) {
        // 0x8007D788: nop

            goto L_8007D798;
    }
    // 0x8007D788: nop

    // 0x8007D78C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007D790: bne         $t6, $at, L_8007D9D4
    if (ctx->r14 != ctx->r1) {
        // 0x8007D794: nop

            goto L_8007D9D4;
    }
    // 0x8007D794: nop

L_8007D798:
    // 0x8007D798: addiu       $t7, $zero, 0xAD
    ctx->r15 = ADD32(0, 0XAD);
    // 0x8007D79C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D7A0: sw          $t7, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r15;
    // 0x8007D7A4: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8007D7A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D7AC: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x8007D7B0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007D7B4: lw          $t0, -0x3908($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3908);
    // 0x8007D7B8: ori         $t9, $zero, 0xD6B5
    ctx->r25 = 0 | 0XD6B5;
    // 0x8007D7BC: sh          $t9, 0x100($t0)
    MEM_H(0X100, ctx->r8) = ctx->r25;
    // 0x8007D7C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D7C4: addiu       $a0, $a0, -0xDC4
    ctx->r4 = ADD32(ctx->r4, -0XDC4);
    // 0x8007D7C8: jal         0x8008ECE4
    // 0x8007D7CC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x8007D7CC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_8:
    // 0x8007D7D0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007D7D4: lw          $t1, 0x70E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E8);
    // 0x8007D7D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007D7DC: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8007D7E0: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x8007D7E4: bne         $at, $zero, L_8007D808
    if (ctx->r1 != 0) {
        // 0x8007D7E8: nop

            goto L_8007D808;
    }
    // 0x8007D7E8: nop

    // 0x8007D7EC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D7F0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8007D7F4: ori         $a1, $a1, 0x869F
    ctx->r5 = ctx->r5 | 0X869F;
    // 0x8007D7F8: jal         0x8008ECE4
    // 0x8007D7FC: addiu       $a0, $a0, -0xDC0
    ctx->r4 = ADD32(ctx->r4, -0XDC0);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8007D7FC: addiu       $a0, $a0, -0xDC0
    ctx->r4 = ADD32(ctx->r4, -0XDC0);
    after_9:
    // 0x8007D800: b           L_8007D81C
    // 0x8007D804: nop

        goto L_8007D81C;
    // 0x8007D804: nop

L_8007D808:
    // 0x8007D808: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007D80C: lw          $a1, 0x70E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70E8);
    // 0x8007D810: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D814: jal         0x8008ECE4
    // 0x8007D818: addiu       $a0, $a0, -0xDB8
    ctx->r4 = ADD32(ctx->r4, -0XDB8);
    func_8008ECE4(rdram, ctx);
        goto after_10;
    // 0x8007D818: addiu       $a0, $a0, -0xDB8
    ctx->r4 = ADD32(ctx->r4, -0XDB8);
    after_10:
L_8007D81C:
    // 0x8007D81C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007D820: lb          $t4, 0x7142($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7142);
    // 0x8007D824: nop

    // 0x8007D828: bltz        $t4, L_8007D9D4
    if (SIGNED(ctx->r12) < 0) {
        // 0x8007D82C: nop

            goto L_8007D9D4;
    }
    // 0x8007D82C: nop

    // 0x8007D830: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D834: lb          $t3, 0x7142($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7142);
    // 0x8007D838: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007D83C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8007D840: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8007D844: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007D848: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8007D84C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007D850: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007D854: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007D858: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007D85C: lw          $a2, 0x2458($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2458);
    // 0x8007D860: jal         0x800BD1FC
    // 0x8007D864: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_11;
    // 0x8007D864: nop

    after_11:
    // 0x8007D868: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007D86C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D870: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007D874: jal         0x800BD218
    // 0x8007D878: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_12;
    // 0x8007D878: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_12:
    // 0x8007D87C: jal         0x800808A4
    // 0x8007D880: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800808A4(rdram, ctx);
        goto after_13;
    // 0x8007D880: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_13:
    // 0x8007D884: addiu       $t2, $zero, 0x24
    ctx->r10 = ADD32(0, 0X24);
    // 0x8007D888: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D88C: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x8007D890: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8007D894: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D898: sw          $t6, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r14;
    // 0x8007D89C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007D8A0: jal         0x8008ECE4
    // 0x8007D8A4: addiu       $a0, $a0, 0x7180
    ctx->r4 = ADD32(ctx->r4, 0X7180);
    func_8008ECE4(rdram, ctx);
        goto after_14;
    // 0x8007D8A4: addiu       $a0, $a0, 0x7180
    ctx->r4 = ADD32(ctx->r4, 0X7180);
    after_14:
    // 0x8007D8A8: jal         0x80080698
    // 0x8007D8AC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80080698(rdram, ctx);
        goto after_15;
    // 0x8007D8AC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_15:
    // 0x8007D8B0: negu        $t7, $v0
    ctx->r15 = SUB32(0, ctx->r2);
    // 0x8007D8B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D8B8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007D8BC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8007D8C0: addiu       $t9, $zero, 0x26
    ctx->r25 = ADD32(0, 0X26);
    // 0x8007D8C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D8C8: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8007D8CC: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8007D8D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D8D4: sw          $t0, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r8;
    // 0x8007D8D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D8DC: addiu       $a0, $a0, -0xDA4
    ctx->r4 = ADD32(ctx->r4, -0XDA4);
    // 0x8007D8E0: jal         0x8008ECE4
    // 0x8007D8E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008ECE4(rdram, ctx);
        goto after_16;
    // 0x8007D8E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_16:
    // 0x8007D8E8: addiu       $t1, $zero, 0x9D
    ctx->r9 = ADD32(0, 0X9D);
    // 0x8007D8EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D8F0: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8007D8F4: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8007D8F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D8FC: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x8007D900: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D904: lw          $t3, 0x7104($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7104);
    // 0x8007D908: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007D90C: bne         $t3, $at, L_8007D958
    if (ctx->r11 != ctx->r1) {
        // 0x8007D910: nop

            goto L_8007D958;
    }
    // 0x8007D910: nop

    // 0x8007D914: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007D918: lb          $t5, 0x7142($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7142);
    // 0x8007D91C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007D920: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8007D924: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x8007D928: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007D92C: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x8007D930: lh          $a1, 0x2460($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2460);
    // 0x8007D934: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D938: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8007D93C: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8007D940: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8007D944: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8007D948: jal         0x8008ECE4
    // 0x8007D94C: addiu       $a0, $a0, -0xDA0
    ctx->r4 = ADD32(ctx->r4, -0XDA0);
    func_8008ECE4(rdram, ctx);
        goto after_17;
    // 0x8007D94C: addiu       $a0, $a0, -0xDA0
    ctx->r4 = ADD32(ctx->r4, -0XDA0);
    after_17:
    // 0x8007D950: b           L_8007D9D4
    // 0x8007D954: nop

        goto L_8007D9D4;
    // 0x8007D954: nop

L_8007D958:
    // 0x8007D958: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007D95C: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007D960: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007D964: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D968: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007D96C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007D970: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007D974: lh          $t9, 0x2462($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2462);
    // 0x8007D978: nop

    // 0x8007D97C: bgez        $t9, L_8007D998
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007D980: nop

            goto L_8007D998;
    }
    // 0x8007D980: nop

    // 0x8007D984: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D988: jal         0x8008ECE4
    // 0x8007D98C: addiu       $a0, $a0, -0xD98
    ctx->r4 = ADD32(ctx->r4, -0XD98);
    func_8008ECE4(rdram, ctx);
        goto after_18;
    // 0x8007D98C: addiu       $a0, $a0, -0xD98
    ctx->r4 = ADD32(ctx->r4, -0XD98);
    after_18:
    // 0x8007D990: b           L_8007D9D4
    // 0x8007D994: nop

        goto L_8007D9D4;
    // 0x8007D994: nop

L_8007D998:
    // 0x8007D998: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007D99C: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007D9A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007D9A4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007D9A8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8007D9AC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007D9B0: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8007D9B4: lh          $a1, 0x2462($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2462);
    // 0x8007D9B8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D9BC: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8007D9C0: addu        $t4, $t4, $a1
    ctx->r12 = ADD32(ctx->r12, ctx->r5);
    // 0x8007D9C4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8007D9C8: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8007D9CC: jal         0x8008ECE4
    // 0x8007D9D0: addiu       $a0, $a0, -0xD90
    ctx->r4 = ADD32(ctx->r4, -0XD90);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x8007D9D0: addiu       $a0, $a0, -0xD90
    ctx->r4 = ADD32(ctx->r4, -0XD90);
    after_19:
L_8007D9D4:
    // 0x8007D9D4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D9D8: lw          $t3, 0x7100($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7100);
    // 0x8007D9DC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007D9E0: bne         $t3, $at, L_8007DAFC
    if (ctx->r11 != ctx->r1) {
        // 0x8007D9E4: nop

            goto L_8007DAFC;
    }
    // 0x8007D9E4: nop

    // 0x8007D9E8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007D9EC: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007D9F0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007D9F4: bne         $t5, $at, L_8007DAFC
    if (ctx->r13 != ctx->r1) {
        // 0x8007D9F8: nop

            goto L_8007DAFC;
    }
    // 0x8007D9F8: nop

    // 0x8007D9FC: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_8007DA00:
    // 0x8007DA00: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007DA04: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8007DA08: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DA0C: addiu       $a1, $a1, 0x6BA0
    ctx->r5 = ADD32(ctx->r5, 0X6BA0);
    // 0x8007DA10: addiu       $a0, $a0, 0x6B98
    ctx->r4 = ADD32(ctx->r4, 0X6B98);
    // 0x8007DA14: jal         0x8007EB90
    // 0x8007DA18: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    func_8007EB90(rdram, ctx);
        goto after_20;
    // 0x8007DA18: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    after_20:
    // 0x8007DA1C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DA20: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DA24: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8007DA28: subu        $t6, $t6, $t2
    ctx->r14 = SUB32(ctx->r14, ctx->r10);
    // 0x8007DA2C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007DA30: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8007DA34: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DA38: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DA3C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007DA40: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007DA44: lw          $a2, 0x2798($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2798);
    // 0x8007DA48: jal         0x800BD1FC
    // 0x8007DA4C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_21;
    // 0x8007DA4C: nop

    after_21:
    // 0x8007DA50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007DA54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DA58: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007DA5C: jal         0x800BD218
    // 0x8007DA60: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_22;
    // 0x8007DA60: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_22:
    // 0x8007DA64: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DA68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007DA6C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007DA70: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007DA74: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007DA78: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8007DA7C: lbu         $a0, 0x27A8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27A8);
    // 0x8007DA80: jal         0x8005F064
    // 0x8007DA84: nop

    func_8005F064(rdram, ctx);
        goto after_23;
    // 0x8007DA84: nop

    after_23:
    // 0x8007DA88: beq         $v0, $zero, L_8007DAB0
    if (ctx->r2 == 0) {
        // 0x8007DA8C: nop

            goto L_8007DAB0;
    }
    // 0x8007DA8C: nop

    // 0x8007DA90: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DA94: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007DA98: lw          $t0, -0x3908($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3908);
    // 0x8007DA9C: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8007DAA0: addiu       $t9, $zero, 0x6319
    ctx->r25 = ADD32(0, 0X6319);
    // 0x8007DAA4: addu        $t3, $t0, $t4
    ctx->r11 = ADD32(ctx->r8, ctx->r12);
    // 0x8007DAA8: b           L_8007DACC
    // 0x8007DAAC: sh          $t9, 0x100($t3)
    MEM_H(0X100, ctx->r11) = ctx->r25;
        goto L_8007DACC;
    // 0x8007DAAC: sh          $t9, 0x100($t3)
    MEM_H(0X100, ctx->r11) = ctx->r25;
L_8007DAB0:
    // 0x8007DAB0: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DAB4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007DAB8: lw          $t2, -0x3908($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3908);
    // 0x8007DABC: lhu         $t5, 0x2A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2A);
    // 0x8007DAC0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8007DAC4: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8007DAC8: sh          $t5, 0x100($t8)
    MEM_H(0X100, ctx->r24) = ctx->r13;
L_8007DACC:
    // 0x8007DACC: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DAD0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DAD4: addiu       $a0, $a0, -0xD88
    ctx->r4 = ADD32(ctx->r4, -0XD88);
    // 0x8007DAD8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8007DADC: jal         0x8008ECE4
    // 0x8007DAE0: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_24;
    // 0x8007DAE0: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    after_24:
    // 0x8007DAE4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DAE8: nop

    // 0x8007DAEC: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8007DAF0: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x8007DAF4: bne         $at, $zero, L_8007DA00
    if (ctx->r1 != 0) {
        // 0x8007DAF8: sw          $t0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r8;
            goto L_8007DA00;
    }
    // 0x8007DAF8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
L_8007DAFC:
    // 0x8007DAFC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007DB00: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007DB04: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007DB08: bne         $t4, $at, L_8007DEF4
    if (ctx->r12 != ctx->r1) {
        // 0x8007DB0C: nop

            goto L_8007DEF4;
    }
    // 0x8007DB0C: nop

    // 0x8007DB10: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007DB14: lw          $t9, 0x7104($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7104);
    // 0x8007DB18: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8007DB1C: bne         $t9, $at, L_8007DEF4
    if (ctx->r25 != ctx->r1) {
        // 0x8007DB20: nop

            goto L_8007DEF4;
    }
    // 0x8007DB20: nop

    // 0x8007DB24: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007DB28: lw          $t6, -0x3908($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3908);
    // 0x8007DB2C: addiu       $t3, $zero, 0x2109
    ctx->r11 = ADD32(0, 0X2109);
    // 0x8007DB30: sh          $t3, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r11;
    // 0x8007DB34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DB38: addiu       $a0, $a0, -0xD80
    ctx->r4 = ADD32(ctx->r4, -0XD80);
    // 0x8007DB3C: jal         0x8008ECE4
    // 0x8007DB40: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_25;
    // 0x8007DB40: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_25:
    // 0x8007DB44: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8007DB48: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DB4C: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x8007DB50: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x8007DB54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DB58: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x8007DB5C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007DB60: lb          $t5, 0x7142($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7142);
    // 0x8007DB64: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DB68: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8007DB6C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8007DB70: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007DB74: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8007DB78: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DB7C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DB80: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007DB84: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007DB88: lw          $a2, 0x279C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X279C);
    // 0x8007DB8C: jal         0x800BD1FC
    // 0x8007DB90: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_26;
    // 0x8007DB90: nop

    after_26:
    // 0x8007DB94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007DB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DB9C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007DBA0: jal         0x800BD218
    // 0x8007DBA4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_27;
    // 0x8007DBA4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_27:
    // 0x8007DBA8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007DBAC: addiu       $t1, $t1, -0x3808
    ctx->r9 = ADD32(ctx->r9, -0X3808);
    // 0x8007DBB0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8007DBB4: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x8007DBB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DBBC: addiu       $a0, $a0, -0xD7C
    ctx->r4 = ADD32(ctx->r4, -0XD7C);
    // 0x8007DBC0: jal         0x8008ECE4
    // 0x8007DBC4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_8008ECE4(rdram, ctx);
        goto after_28;
    // 0x8007DBC4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_28:
    // 0x8007DBC8: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8007DBCC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DBD0: sw          $t0, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r8;
    // 0x8007DBD4: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x8007DBD8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DBDC: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x8007DBE0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007DBE4: addiu       $t9, $t9, -0x3808
    ctx->r25 = ADD32(ctx->r25, -0X3808);
    // 0x8007DBE8: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    // 0x8007DBEC: lw          $a2, 0xC($t9)
    ctx->r6 = MEM_W(ctx->r25, 0XC);
    // 0x8007DBF0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DBF4: jal         0x8008ECE4
    // 0x8007DBF8: addiu       $a0, $a0, -0xD70
    ctx->r4 = ADD32(ctx->r4, -0XD70);
    func_8008ECE4(rdram, ctx);
        goto after_29;
    // 0x8007DBF8: addiu       $a0, $a0, -0xD70
    ctx->r4 = ADD32(ctx->r4, -0XD70);
    after_29:
    // 0x8007DBFC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007DC00: lb          $t3, 0x7142($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7142);
    // 0x8007DC04: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007DC08: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8007DC0C: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x8007DC10: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007DC14: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8007DC18: lh          $t2, 0x27AA($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X27AA);
    // 0x8007DC1C: nop

    // 0x8007DC20: bgez        $t2, L_8007DC48
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007DC24: nop

            goto L_8007DC48;
    }
    // 0x8007DC24: nop

    // 0x8007DC28: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007DC2C: addiu       $t7, $t7, -0x3808
    ctx->r15 = ADD32(ctx->r15, -0X3808);
    // 0x8007DC30: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x8007DC34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DC38: jal         0x8008ECE4
    // 0x8007DC3C: addiu       $a0, $a0, -0xD68
    ctx->r4 = ADD32(ctx->r4, -0XD68);
    func_8008ECE4(rdram, ctx);
        goto after_30;
    // 0x8007DC3C: addiu       $a0, $a0, -0xD68
    ctx->r4 = ADD32(ctx->r4, -0XD68);
    after_30:
    // 0x8007DC40: b           L_8007DC84
    // 0x8007DC44: nop

        goto L_8007DC84;
    // 0x8007DC44: nop

L_8007DC48:
    // 0x8007DC48: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007DC4C: lb          $t8, 0x7142($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X7142);
    // 0x8007DC50: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007DC54: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8007DC58: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8007DC5C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007DC60: addiu       $t5, $t5, -0x3808
    ctx->r13 = ADD32(ctx->r13, -0X3808);
    // 0x8007DC64: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DC68: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8007DC6C: lh          $a2, 0x27AA($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X27AA);
    // 0x8007DC70: lw          $a1, 0x10($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X10);
    // 0x8007DC74: lw          $a3, 0x14($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X14);
    // 0x8007DC78: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DC7C: jal         0x8008ECE4
    // 0x8007DC80: addiu       $a0, $a0, -0xD64
    ctx->r4 = ADD32(ctx->r4, -0XD64);
    func_8008ECE4(rdram, ctx);
        goto after_31;
    // 0x8007DC80: addiu       $a0, $a0, -0xD64
    ctx->r4 = ADD32(ctx->r4, -0XD64);
    after_31:
L_8007DC84:
    // 0x8007DC84: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007DC88: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007DC8C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DC90: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x8007DC94: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x8007DC98: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8007DC9C: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8007DCA0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DCA4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DCA8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007DCAC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007DCB0: lw          $a2, 0x27A0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X27A0);
    // 0x8007DCB4: jal         0x800BD1FC
    // 0x8007DCB8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_32;
    // 0x8007DCB8: nop

    after_32:
    // 0x8007DCBC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007DCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DCC4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007DCC8: jal         0x800BD218
    // 0x8007DCCC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_33;
    // 0x8007DCCC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_33:
    // 0x8007DCD0: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8007DCD4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DCD8: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8007DCDC: addiu       $t3, $zero, 0x4A
    ctx->r11 = ADD32(0, 0X4A);
    // 0x8007DCE0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DCE4: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8007DCE8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007DCEC: addiu       $t6, $t6, -0x3808
    ctx->r14 = ADD32(ctx->r14, -0X3808);
    // 0x8007DCF0: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x8007DCF4: lw          $a2, 0xC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XC);
    // 0x8007DCF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DCFC: addiu       $a0, $a0, -0xD5C
    ctx->r4 = ADD32(ctx->r4, -0XD5C);
    // 0x8007DD00: jal         0x8008ECE4
    // 0x8007DD04: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_8008ECE4(rdram, ctx);
        goto after_34;
    // 0x8007DD04: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_34:
    // 0x8007DD08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007DD0C: lb          $t2, 0x7142($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7142);
    // 0x8007DD10: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007DD14: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8007DD18: subu        $t7, $t7, $t2
    ctx->r15 = SUB32(ctx->r15, ctx->r10);
    // 0x8007DD1C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007DD20: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007DD24: lw          $t8, 0x27A4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X27A4);
    // 0x8007DD28: nop

    // 0x8007DD2C: beq         $t8, $zero, L_8007DDA8
    if (ctx->r24 == 0) {
        // 0x8007DD30: nop

            goto L_8007DDA8;
    }
    // 0x8007DD30: nop

    // 0x8007DD34: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007DD38: lb          $t1, 0x7142($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X7142);
    // 0x8007DD3C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DD40: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x8007DD44: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x8007DD48: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007DD4C: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8007DD50: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DD54: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DD58: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007DD5C: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007DD60: lw          $a2, 0x27A4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X27A4);
    // 0x8007DD64: jal         0x800BD1FC
    // 0x8007DD68: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_35;
    // 0x8007DD68: nop

    after_35:
    // 0x8007DD6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007DD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DD74: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007DD78: jal         0x800BD218
    // 0x8007DD7C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_36;
    // 0x8007DD7C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_36:
    // 0x8007DD80: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x8007DD84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DD88: sw          $t0, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r8;
    // 0x8007DD8C: addiu       $t4, $zero, 0x57
    ctx->r12 = ADD32(0, 0X57);
    // 0x8007DD90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DD94: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x8007DD98: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DD9C: addiu       $a0, $a0, -0xD54
    ctx->r4 = ADD32(ctx->r4, -0XD54);
    // 0x8007DDA0: jal         0x8008ECE4
    // 0x8007DDA4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008ECE4(rdram, ctx);
        goto after_37;
    // 0x8007DDA4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_37:
L_8007DDA8:
    // 0x8007DDA8: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x8007DDAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DDB0: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8007DDB4: addiu       $t3, $zero, 0x68
    ctx->r11 = ADD32(0, 0X68);
    // 0x8007DDB8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DDBC: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8007DDC0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007DDC4: lw          $t2, -0x3908($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3908);
    // 0x8007DDC8: addiu       $t6, $zero, 0x2109
    ctx->r14 = ADD32(0, 0X2109);
    // 0x8007DDCC: sh          $t6, 0x102($t2)
    MEM_H(0X102, ctx->r10) = ctx->r14;
    // 0x8007DDD0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007DDD4: addiu       $t7, $t7, -0x3808
    ctx->r15 = ADD32(ctx->r15, -0X3808);
    // 0x8007DDD8: lw          $a2, 0x1C($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X1C);
    // 0x8007DDDC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DDE0: addiu       $a0, $a0, -0xD50
    ctx->r4 = ADD32(ctx->r4, -0XD50);
    // 0x8007DDE4: jal         0x8008ECE4
    // 0x8007DDE8: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    func_8008ECE4(rdram, ctx);
        goto after_38;
    // 0x8007DDE8: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    after_38:
    // 0x8007DDEC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8007DDF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DDF4: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x8007DDF8: addiu       $t1, $zero, 0x68
    ctx->r9 = ADD32(0, 0X68);
    // 0x8007DDFC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE00: sw          $t1, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r9;
    // 0x8007DE04: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007DE08: lw          $t0, -0x3908($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3908);
    // 0x8007DE0C: ori         $t5, $zero, 0xD6B5
    ctx->r13 = 0 | 0XD6B5;
    // 0x8007DE10: sh          $t5, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r13;
    // 0x8007DE14: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007DE18: lb          $t4, 0x7142($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7142);
    // 0x8007DE1C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DE20: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8007DE24: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x8007DE28: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8007DE2C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8007DE30: lh          $a2, 0x27AC($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X27AC);
    // 0x8007DE34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DE38: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8007DE3C: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x8007DE40: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8007DE44: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8007DE48: addiu       $a0, $a0, -0xD48
    ctx->r4 = ADD32(ctx->r4, -0XD48);
    // 0x8007DE4C: jal         0x8008ECE4
    // 0x8007DE50: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_39;
    // 0x8007DE50: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_39:
    // 0x8007DE54: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x8007DE58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE5C: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x8007DE60: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8007DE64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE68: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x8007DE6C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007DE70: addiu       $t7, $t7, -0x3808
    ctx->r15 = ADD32(ctx->r15, -0X3808);
    // 0x8007DE74: lw          $a2, 0x20($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X20);
    // 0x8007DE78: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DE7C: addiu       $a0, $a0, -0xD40
    ctx->r4 = ADD32(ctx->r4, -0XD40);
    // 0x8007DE80: jal         0x8008ECE4
    // 0x8007DE84: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    func_8008ECE4(rdram, ctx);
        goto after_40;
    // 0x8007DE84: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    after_40:
    // 0x8007DE88: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8007DE8C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE90: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x8007DE94: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x8007DE98: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE9C: sw          $t1, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r9;
    // 0x8007DEA0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007DEA4: lw          $t5, 0x70E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E8);
    // 0x8007DEA8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007DEAC: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8007DEB0: sltu        $at, $t5, $at
    ctx->r1 = ctx->r13 < ctx->r1 ? 1 : 0;
    // 0x8007DEB4: bne         $at, $zero, L_8007DEDC
    if (ctx->r1 != 0) {
        // 0x8007DEB8: nop

            goto L_8007DEDC;
    }
    // 0x8007DEB8: nop

    // 0x8007DEBC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DEC0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8007DEC4: ori         $a2, $a2, 0x869F
    ctx->r6 = ctx->r6 | 0X869F;
    // 0x8007DEC8: addiu       $a0, $a0, -0xD38
    ctx->r4 = ADD32(ctx->r4, -0XD38);
    // 0x8007DECC: jal         0x8008ECE4
    // 0x8007DED0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_41;
    // 0x8007DED0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_41:
    // 0x8007DED4: b           L_8007DEF4
    // 0x8007DED8: nop

        goto L_8007DEF4;
    // 0x8007DED8: nop

L_8007DEDC:
    // 0x8007DEDC: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8007DEE0: lw          $a2, 0x70E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X70E8);
    // 0x8007DEE4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DEE8: addiu       $a0, $a0, -0xD30
    ctx->r4 = ADD32(ctx->r4, -0XD30);
    // 0x8007DEEC: jal         0x8008ECE4
    // 0x8007DEF0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_42;
    // 0x8007DEF0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_42:
L_8007DEF4:
    // 0x8007DEF4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007DEF8: lw          $t0, -0x3908($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3908);
    // 0x8007DEFC: nop

    // 0x8007DF00: sh          $zero, 0x20($t0)
    MEM_H(0X20, ctx->r8) = 0;
    // 0x8007DF04: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8007DF08: jal         0x8001ACDC
    // 0x8007DF0C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001ACDC(rdram, ctx);
        goto after_43;
    // 0x8007DF0C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_43:
    // 0x8007DF10: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8007DF14: jal         0x8001ADBC
    // 0x8007DF18: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001ADBC(rdram, ctx);
        goto after_44;
    // 0x8007DF18: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_44:
    // 0x8007DF1C: b           L_8007DF2C
    // 0x8007DF20: nop

        goto L_8007DF2C;
    // 0x8007DF20: nop

    // 0x8007DF24: b           L_8007DF2C
    // 0x8007DF28: nop

        goto L_8007DF2C;
    // 0x8007DF28: nop

L_8007DF2C:
    // 0x8007DF2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007DF30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007DF34: jr          $ra
    // 0x8007DF38: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8007DF38: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8007DF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DF3C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8007DF40: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8007DF44: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8007DF48: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8007DF4C: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8007DF50: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8007DF54: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8007DF58: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8007DF5C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8007DF60: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8007DF64: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8007DF68: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8007DF6C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007DF70: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8007DF74: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007DF78: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007DF7C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007DF80: bne         $t6, $at, L_8007DFA8
    if (ctx->r14 != ctx->r1) {
        // 0x8007DF84: nop

            goto L_8007DFA8;
    }
    // 0x8007DF84: nop

    // 0x8007DF88: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007DF8C: lw          $t7, 0x7104($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7104);
    // 0x8007DF90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007DF94: beq         $t7, $at, L_8007DFB0
    if (ctx->r15 == ctx->r1) {
        // 0x8007DF98: nop

            goto L_8007DFB0;
    }
    // 0x8007DF98: nop

    // 0x8007DF9C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007DFA0: beq         $t7, $at, L_8007DFB0
    if (ctx->r15 == ctx->r1) {
        // 0x8007DFA4: nop

            goto L_8007DFB0;
    }
    // 0x8007DFA4: nop

L_8007DFA8:
    // 0x8007DFA8: b           L_8007E914
    // 0x8007DFAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E914;
    // 0x8007DFAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007DFB0:
    // 0x8007DFB0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007DFB4: lb          $t8, 0x7142($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X7142);
    // 0x8007DFB8: nop

    // 0x8007DFBC: bgez        $t8, L_8007DFCC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007DFC0: nop

            goto L_8007DFCC;
    }
    // 0x8007DFC0: nop

    // 0x8007DFC4: b           L_8007E914
    // 0x8007DFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E914;
    // 0x8007DFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007DFCC:
    // 0x8007DFCC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007DFD0: lb          $t9, 0x7142($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7142);
    // 0x8007DFD4: nop

    // 0x8007DFD8: sb          $t9, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r25;
    // 0x8007DFDC: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x8007DFE0: nop

    // 0x8007DFE4: beq         $t0, $zero, L_8007E158
    if (ctx->r8 == 0) {
        // 0x8007DFE8: nop

            goto L_8007E158;
    }
    // 0x8007DFE8: nop

    // 0x8007DFEC: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x8007DFF0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8007DFF4: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8007DFF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007DFFC: sw          $t2, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = ctx->r10;
    // 0x8007E000: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x8007E004: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E008: beq         $s0, $at, L_8007E024
    if (ctx->r16 == ctx->r1) {
        // 0x8007E00C: nop

            goto L_8007E024;
    }
    // 0x8007E00C: nop

    // 0x8007E010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E014: beq         $s0, $at, L_8007E0A0
    if (ctx->r16 == ctx->r1) {
        // 0x8007E018: nop

            goto L_8007E0A0;
    }
    // 0x8007E018: nop

    // 0x8007E01C: b           L_8007E150
    // 0x8007E020: nop

        goto L_8007E150;
    // 0x8007E020: nop

L_8007E024:
    // 0x8007E024: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E028: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E02C: swc1        $f4, 0x7120($at)
    MEM_W(0X7120, ctx->r1) = ctx->f4.u32l;
    // 0x8007E030: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007E034: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007E038: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E03C: swc1        $f6, 0x7124($at)
    MEM_W(0X7124, ctx->r1) = ctx->f6.u32l;
    // 0x8007E040: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007E044: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E048: swc1        $f8, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f8.u32l;
    // 0x8007E04C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007E050: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007E054: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007E058: swc1        $f10, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f10.u32l;
    // 0x8007E05C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007E060: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007E064: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007E068: addiu       $t4, $t4, 0x7190
    ctx->r12 = ADD32(ctx->r12, 0X7190);
    // 0x8007E06C: swc1        $f16, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f16.u32l;
    // 0x8007E070: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E074: lwc1        $f18, -0xCE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XCE8);
    // 0x8007E078: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007E07C: addiu       $t5, $t5, 0x7190
    ctx->r13 = ADD32(ctx->r13, 0X7190);
    // 0x8007E080: swc1        $f18, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f18.u32l;
    // 0x8007E084: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E088: lwc1        $f4, -0xCE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XCE4);
    // 0x8007E08C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007E090: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007E094: swc1        $f4, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f4.u32l;
    // 0x8007E098: b           L_8007E150
    // 0x8007E09C: nop

        goto L_8007E150;
    // 0x8007E09C: nop

L_8007E0A0:
    // 0x8007E0A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007E0A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E0A8: swc1        $f6, 0x7120($at)
    MEM_W(0X7120, ctx->r1) = ctx->f6.u32l;
    // 0x8007E0AC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007E0B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007E0B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E0B8: swc1        $f8, 0x7124($at)
    MEM_W(0X7124, ctx->r1) = ctx->f8.u32l;
    // 0x8007E0BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007E0C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E0C4: swc1        $f10, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f10.u32l;
    // 0x8007E0C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007E0CC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007E0D0: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007E0D4: swc1        $f16, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f16.u32l;
    // 0x8007E0D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007E0DC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007E0E0: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007E0E4: swc1        $f18, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->f18.u32l;
    // 0x8007E0E8: lb          $t9, 0x6B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E0EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E0F0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007E0F4: lwc1        $f5, -0xCE0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XCE0);
    // 0x8007E0F8: lwc1        $f4, -0xCDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XCDC);
    // 0x8007E0FC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8007E100: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8007E104: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E108: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8007E10C: lwc1        $f6, 0x2468($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x8007E110: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x8007E114: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007E118: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007E11C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007E120: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x8007E124: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007E128: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8007E12C: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007E130: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8007E134: swc1        $f6, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f6.u32l;
    // 0x8007E138: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E13C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007E140: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007E144: swc1        $f4, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->f4.u32l;
    // 0x8007E148: b           L_8007E150
    // 0x8007E14C: nop

        goto L_8007E150;
    // 0x8007E14C: nop

L_8007E150:
    // 0x8007E150: b           L_8007E914
    // 0x8007E154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E914;
    // 0x8007E154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007E158:
    // 0x8007E158: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007E15C: lw          $t3, 0x7190($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7190);
    // 0x8007E160: nop

    // 0x8007E164: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x8007E168: beq         $t4, $zero, L_8007E1F0
    if (ctx->r12 == 0) {
        // 0x8007E16C: nop

            goto L_8007E1F0;
    }
    // 0x8007E16C: nop

    // 0x8007E170: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E174: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E178: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007E17C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007E180: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E184: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007E188: lwc1        $f18, 0x714C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E18C: nop

    // 0x8007E190: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8007E194: swc1        $f6, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f6.u32l;
    // 0x8007E198: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E19C: lwc1        $f4, 0x714C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E1A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E1A4: lwc1        $f11, -0xCD8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XCD8);
    // 0x8007E1A8: lwc1        $f10, -0xCD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XCD4);
    // 0x8007E1AC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007E1B0: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8007E1B4: nop

    // 0x8007E1B8: bc1f        L_8007E1E8
    if (!c1cs) {
        // 0x8007E1BC: nop

            goto L_8007E1E8;
    }
    // 0x8007E1BC: nop

    // 0x8007E1C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E1C4: lwc1        $f18, 0x714C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E1C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E1CC: lwc1        $f7, -0xCD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XCD0);
    // 0x8007E1D0: lwc1        $f6, -0xCCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XCCC);
    // 0x8007E1D4: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007E1D8: sub.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = ctx->f16.d - ctx->f6.d;
    // 0x8007E1DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E1E0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8007E1E4: swc1        $f8, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f8.u32l;
L_8007E1E8:
    // 0x8007E1E8: b           L_8007E3EC
    // 0x8007E1EC: nop

        goto L_8007E3EC;
    // 0x8007E1EC: nop

L_8007E1F0:
    // 0x8007E1F0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8007E1F4: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8007E1F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007E1FC: lhu         $t7, 0x1042($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1042);
    // 0x8007E200: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x8007E204: nop

    // 0x8007E208: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8007E20C: beq         $t8, $zero, L_8007E290
    if (ctx->r24 == 0) {
        // 0x8007E210: nop

            goto L_8007E290;
    }
    // 0x8007E210: nop

    // 0x8007E214: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007E218: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007E21C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E220: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x8007E224: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007E228: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8007E22C: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8007E230: lwc1        $f10, 0x14($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8007E234: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8007E238: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007E23C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007E240: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007E244: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8007E248: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E24C: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8007E250: swc1        $f4, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f4.u32l;
    // 0x8007E254: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8007E258: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8007E25C: lwc1        $f8, 0x10($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8007E260: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007E264: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007E268: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007E26C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007E270: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8007E274: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E278: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8007E27C: swc1        $f6, 0x7150($at)
    MEM_W(0X7150, ctx->r1) = ctx->f6.u32l;
    // 0x8007E280: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E284: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E288: b           L_8007E3EC
    // 0x8007E28C: swc1        $f4, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f4.u32l;
        goto L_8007E3EC;
    // 0x8007E28C: swc1        $f4, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f4.u32l;
L_8007E290:
    // 0x8007E290: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007E294: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007E298: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8007E29C: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8007E2A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2A4: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007E2A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2AC: lwc1        $f8, 0x714C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E2B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E2B4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E2B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2BC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007E2C0: swc1        $f18, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f18.u32l;
    // 0x8007E2C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2C8: lwc1        $f16, 0x714C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E2CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E2D0: lwc1        $f5, -0xCC8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XCC8);
    // 0x8007E2D4: lwc1        $f4, -0xCC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XCC4);
    // 0x8007E2D8: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8007E2DC: c.le.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d <= ctx->f6.d;
    // 0x8007E2E0: nop

    // 0x8007E2E4: bc1f        L_8007E314
    if (!c1cs) {
        // 0x8007E2E8: nop

            goto L_8007E314;
    }
    // 0x8007E2E8: nop

    // 0x8007E2EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2F0: lwc1        $f8, 0x714C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E2F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E2F8: lwc1        $f19, -0xCC0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XCC0);
    // 0x8007E2FC: lwc1        $f18, -0xCBC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XCBC);
    // 0x8007E300: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007E304: sub.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f10.d - ctx->f18.d;
    // 0x8007E308: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E30C: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8007E310: swc1        $f6, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f6.u32l;
L_8007E314:
    // 0x8007E314: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E318: lwc1        $f4, 0x7150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7150);
    // 0x8007E31C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E320: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E324: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E328: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8007E32C: swc1        $f10, 0x7150($at)
    MEM_W(0X7150, ctx->r1) = ctx->f10.u32l;
    // 0x8007E330: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E334: lwc1        $f18, 0x7150($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7150);
    // 0x8007E338: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E33C: lwc1        $f7, -0xCB8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XCB8);
    // 0x8007E340: lwc1        $f6, -0xCB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XCB4);
    // 0x8007E344: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007E348: c.le.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d <= ctx->f16.d;
    // 0x8007E34C: nop

    // 0x8007E350: bc1f        L_8007E380
    if (!c1cs) {
        // 0x8007E354: nop

            goto L_8007E380;
    }
    // 0x8007E354: nop

    // 0x8007E358: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E35C: lwc1        $f4, 0x7150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7150);
    // 0x8007E360: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E364: lwc1        $f11, -0xCB0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XCB0);
    // 0x8007E368: lwc1        $f10, -0xCAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XCAC);
    // 0x8007E36C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007E370: sub.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = ctx->f8.d - ctx->f10.d;
    // 0x8007E374: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E378: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8007E37C: swc1        $f16, 0x7150($at)
    MEM_W(0X7150, ctx->r1) = ctx->f16.u32l;
L_8007E380:
    // 0x8007E380: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E384: lwc1        $f6, 0x7154($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7154);
    // 0x8007E388: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E38C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E390: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E394: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8007E398: swc1        $f8, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f8.u32l;
    // 0x8007E39C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E3A0: lwc1        $f10, 0x7154($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7154);
    // 0x8007E3A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E3A8: lwc1        $f17, -0xCA8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XCA8);
    // 0x8007E3AC: lwc1        $f16, -0xCA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XCA4);
    // 0x8007E3B0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007E3B4: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x8007E3B8: nop

    // 0x8007E3BC: bc1f        L_8007E3EC
    if (!c1cs) {
        // 0x8007E3C0: nop

            goto L_8007E3EC;
    }
    // 0x8007E3C0: nop

    // 0x8007E3C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E3C8: lwc1        $f6, 0x7154($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7154);
    // 0x8007E3CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E3D0: lwc1        $f9, -0xCA0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XCA0);
    // 0x8007E3D4: lwc1        $f8, -0xC9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XC9C);
    // 0x8007E3D8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8007E3DC: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x8007E3E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E3E4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8007E3E8: swc1        $f18, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f18.u32l;
L_8007E3EC:
    // 0x8007E3EC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007E3F0: lb          $t6, 0x7143($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7143);
    // 0x8007E3F4: lb          $t5, 0x6B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E3F8: nop

    // 0x8007E3FC: beq         $t5, $t6, L_8007E534
    if (ctx->r13 == ctx->r14) {
        // 0x8007E400: nop

            goto L_8007E534;
    }
    // 0x8007E400: nop

    // 0x8007E404: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007E408: lw          $t7, 0x307C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X307C);
    // 0x8007E40C: nop

    // 0x8007E410: beq         $t7, $zero, L_8007E438
    if (ctx->r15 == 0) {
        // 0x8007E414: nop

            goto L_8007E438;
    }
    // 0x8007E414: nop

    // 0x8007E418: jal         0x800B0E08
    // 0x8007E41C: nop

    func_800B0E08(rdram, ctx);
        goto after_0;
    // 0x8007E41C: nop

    after_0:
    // 0x8007E420: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007E424: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8007E428: jal         0x800BC980
    // 0x8007E42C: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x8007E42C: nop

    after_1:
    // 0x8007E430: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E434: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_8007E438:
    // 0x8007E438: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007E43C: lb          $t8, 0x7142($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X7142);
    // 0x8007E440: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E444: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8007E448: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8007E44C: lhu         $a0, -0x4770($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4770);
    // 0x8007E450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8007E454: jal         0x800AFB70
    // 0x8007E458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x8007E458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8007E45C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E460: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x8007E464: lb          $t0, 0x6B($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E468: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E46C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007E470: sh          $t1, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r9;
    // 0x8007E474: lb          $t2, 0x6B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E478: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E47C: sb          $t2, 0x7143($at)
    MEM_B(0X7143, ctx->r1) = ctx->r10;
    // 0x8007E480: lb          $t3, 0x6B($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E484: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007E488: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007E48C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8007E490: lh          $t5, -0x4574($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4574);
    // 0x8007E494: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E498: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8007E49C: nop

    // 0x8007E4A0: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007E4A4: swc1        $f6, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f6.u32l;
    // 0x8007E4A8: lb          $t6, 0x6B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E4AC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007E4B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007E4B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007E4B8: lh          $t8, -0x4572($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4572);
    // 0x8007E4BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E4C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8007E4C4: nop

    // 0x8007E4C8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007E4CC: swc1        $f8, 0x7150($at)
    MEM_W(0X7150, ctx->r1) = ctx->f8.u32l;
    // 0x8007E4D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007E4D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E4D8: swc1        $f10, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f10.u32l;
    // 0x8007E4DC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007E4E0: lb          $t9, 0x7142($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7142);
    // 0x8007E4E4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007E4E8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007E4EC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8007E4F0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8007E4F4: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8007E4F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007E4FC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007E500: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007E504: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007E508: lw          $a2, 0x245C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X245C);
    // 0x8007E50C: jal         0x800BD1FC
    // 0x8007E510: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8007E510: nop

    after_3:
    // 0x8007E514: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007E518: jal         0x80080910
    // 0x8007E51C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_4;
    // 0x8007E51C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8007E520: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007E524: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007E528: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E52C: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8007E530: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
L_8007E534:
    // 0x8007E534: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007E538: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x8007E53C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007E540: lw          $t4, 0x7190($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7190);
    // 0x8007E544: nop

    // 0x8007E548: beq         $t4, $zero, L_8007E78C
    if (ctx->r12 == 0) {
        // 0x8007E54C: nop

            goto L_8007E78C;
    }
    // 0x8007E54C: nop

    // 0x8007E550: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007E554: addiu       $t5, $t5, 0x7190
    ctx->r13 = ADD32(ctx->r13, 0X7190);
    // 0x8007E558: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E55C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E560: lwc1        $f18, 0x54($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X54);
    // 0x8007E564: lwc1        $f4, 0x4C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4C);
    // 0x8007E568: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8007E56C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007E570: swc1        $f8, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = ctx->f8.u32l;
    // 0x8007E574: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007E578: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007E57C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E580: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E584: lwc1        $f10, 0x48($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8007E588: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E58C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007E590: lwc1        $f4, 0x7120($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7120);
    // 0x8007E594: nop

    // 0x8007E598: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8007E59C: swc1        $f6, 0x7120($at)
    MEM_W(0X7120, ctx->r1) = ctx->f6.u32l;
    // 0x8007E5A0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007E5A4: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007E5A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E5AC: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E5B0: lwc1        $f8, 0x4C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8007E5B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E5B8: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007E5BC: lwc1        $f4, 0x7124($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7124);
    // 0x8007E5C0: nop

    // 0x8007E5C4: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8007E5C8: swc1        $f16, 0x7124($at)
    MEM_W(0X7124, ctx->r1) = ctx->f16.u32l;
    // 0x8007E5CC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007E5D0: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007E5D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E5D8: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E5DC: lwc1        $f6, 0x50($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X50);
    // 0x8007E5E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E5E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007E5E8: lwc1        $f4, 0x7128($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7128);
    // 0x8007E5EC: nop

    // 0x8007E5F0: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8007E5F4: swc1        $f18, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f18.u32l;
    // 0x8007E5F8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007E5FC: lw          $t9, 0x7190($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7190);
    // 0x8007E600: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8007E604: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8007E608: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8007E60C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E610: bne         $t0, $at, L_8007E66C
    if (ctx->r8 != ctx->r1) {
        // 0x8007E614: nop

            goto L_8007E66C;
    }
    // 0x8007E614: nop

    // 0x8007E618: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E61C: lwc1        $f16, 0x7124($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7124);
    // 0x8007E620: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E624: lwc1        $f9, -0xC98($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XC98);
    // 0x8007E628: lwc1        $f8, -0xC94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XC94);
    // 0x8007E62C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8007E630: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8007E634: nop

    // 0x8007E638: bc1f        L_8007E664
    if (!c1cs) {
        // 0x8007E63C: nop

            goto L_8007E664;
    }
    // 0x8007E63C: nop

    // 0x8007E640: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8007E644: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007E648: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007E64C: nop

    // 0x8007E650: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8007E654: bne         $t2, $zero, L_8007E664
    if (ctx->r10 != 0) {
        // 0x8007E658: nop

            goto L_8007E664;
    }
    // 0x8007E658: nop

    // 0x8007E65C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E660: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
L_8007E664:
    // 0x8007E664: b           L_8007E784
    // 0x8007E668: nop

        goto L_8007E784;
    // 0x8007E668: nop

L_8007E66C:
    // 0x8007E66C: lb          $t3, 0x6B($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E670: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E674: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007E678: lwc1        $f4, 0x7128($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7128);
    // 0x8007E67C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007E680: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007E684: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E688: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8007E68C: lwc1        $f10, 0x2468($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x8007E690: nop

    // 0x8007E694: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8007E698: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x8007E69C: nop

    // 0x8007E6A0: bc1f        L_8007E784
    if (!c1cs) {
        // 0x8007E6A4: nop

            goto L_8007E784;
    }
    // 0x8007E6A4: nop

    // 0x8007E6A8: lb          $t5, 0x6B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E6AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E6B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8007E6B4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8007E6B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8007E6BC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8007E6C0: lwc1        $f16, 0x2468($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x8007E6C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E6C8: lwc1        $f11, -0xC90($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XC90);
    // 0x8007E6CC: lwc1        $f10, -0xC8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XC8C);
    // 0x8007E6D0: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = -ctx->f16.fl;
    // 0x8007E6D4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007E6D8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8007E6DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E6E0: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8007E6E4: swc1        $f18, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f18.u32l;
    // 0x8007E6E8: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8007E6EC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007E6F0: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007E6F4: nop

    // 0x8007E6F8: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8007E6FC: bne         $t8, $zero, L_8007E784
    if (ctx->r24 != 0) {
        // 0x8007E700: nop

            goto L_8007E784;
    }
    // 0x8007E700: nop

    // 0x8007E704: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E708: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
    // 0x8007E70C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007E710: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007E714: nop

    // 0x8007E718: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x8007E71C: beq         $t0, $zero, L_8007E768
    if (ctx->r8 == 0) {
        // 0x8007E720: nop

            goto L_8007E768;
    }
    // 0x8007E720: nop

    // 0x8007E724: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007E728: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007E72C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E730: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8007E734: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
    // 0x8007E738: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8007E73C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E740: sh          $t3, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r11;
    // 0x8007E744: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8007E748: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E74C: sh          $t4, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r12;
    // 0x8007E750: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E754: sw          $zero, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = 0;
    // 0x8007E758: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8007E75C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E760: b           L_8007E784
    // 0x8007E764: sb          $t5, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r13;
        goto L_8007E784;
    // 0x8007E764: sb          $t5, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r13;
L_8007E768:
    // 0x8007E768: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007E76C: lw          $t6, 0x70FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70FC);
    // 0x8007E770: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E774: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8007E778: nop

    // 0x8007E77C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007E780: sb          $t8, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r24;
L_8007E784:
    // 0x8007E784: b           L_8007E7B8
    // 0x8007E788: nop

        goto L_8007E7B8;
    // 0x8007E788: nop

L_8007E78C:
    // 0x8007E78C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8007E790: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007E794: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E798: swc1        $f16, 0x7120($at)
    MEM_W(0X7120, ctx->r1) = ctx->f16.u32l;
    // 0x8007E79C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007E7A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007E7A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E7A8: swc1        $f6, 0x7124($at)
    MEM_W(0X7124, ctx->r1) = ctx->f6.u32l;
    // 0x8007E7AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007E7B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E7B4: swc1        $f8, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f8.u32l;
L_8007E7B8:
    // 0x8007E7B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007E7BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007E7C0: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x8007E7C4: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x8007E7C8: swc1        $f10, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f10.u32l;
    // 0x8007E7CC: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8007E7D0: nop

    // 0x8007E7D4: swc1        $f4, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f4.u32l;
    // 0x8007E7D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007E7DC: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x8007E7E0: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x8007E7E4: swc1        $f18, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f18.u32l;
    // 0x8007E7E8: lwc1        $f28, 0x8($t2)
    ctx->f28.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8007E7EC: addiu       $t3, $sp, 0x70
    ctx->r11 = ADD32(ctx->r29, 0X70);
    // 0x8007E7F0: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x8007E7F4: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x8007E7F8: swc1        $f28, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f28.u32l;
    // 0x8007E7FC: swc1        $f26, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f26.u32l;
    // 0x8007E800: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x8007E804: addiu       $t4, $sp, 0x70
    ctx->r12 = ADD32(ctx->r29, 0X70);
    // 0x8007E808: swc1        $f24, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f24.u32l;
    // 0x8007E80C: addiu       $t5, $sp, 0x70
    ctx->r13 = ADD32(ctx->r29, 0X70);
    // 0x8007E810: swc1        $f22, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f22.u32l;
    // 0x8007E814: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8007E818: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8007E81C: swc1        $f20, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f20.u32l;
    // 0x8007E820: addiu       $t7, $sp, 0x70
    ctx->r15 = ADD32(ctx->r29, 0X70);
    // 0x8007E824: swc1        $f20, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f20.u32l;
    // 0x8007E828: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007E82C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007E830: addiu       $t8, $sp, 0x70
    ctx->r24 = ADD32(ctx->r29, 0X70);
    // 0x8007E834: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x8007E838: swc1        $f16, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f16.u32l;
    // 0x8007E83C: lwc1        $f20, 0x20($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8007E840: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x8007E844: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x8007E848: swc1        $f20, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f20.u32l;
    // 0x8007E84C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007E850: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8007E854: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8007E858: jal         0x800B1250
    // 0x8007E85C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_5;
    // 0x8007E85C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8007E860: jal         0x800C1850
    // 0x8007E864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_6;
    // 0x8007E864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8007E868: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E86C: lwc1        $f12, 0x7120($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7120);
    // 0x8007E870: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E874: lwc1        $f14, 0x7124($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7124);
    // 0x8007E878: jal         0x800C2304
    // 0x8007E87C: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_7;
    // 0x8007E87C: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    after_7:
    // 0x8007E880: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E884: lwc1        $f12, 0x714C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E888: jal         0x800C23E8
    // 0x8007E88C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_8;
    // 0x8007E88C: nop

    after_8:
    // 0x8007E890: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E894: lwc1        $f12, 0x7150($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7150);
    // 0x8007E898: jal         0x800C25B8
    // 0x8007E89C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_9;
    // 0x8007E89C: nop

    after_9:
    // 0x8007E8A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E8A4: lwc1        $f12, 0x7154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7154);
    // 0x8007E8A8: jal         0x800C2780
    // 0x8007E8AC: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_10;
    // 0x8007E8AC: nop

    after_10:
    // 0x8007E8B0: lb          $t1, 0x6B($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E8B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E8B8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007E8BC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8007E8C0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007E8C4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8007E8C8: lwc1        $f6, 0x2468($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x8007E8CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E8D0: lwc1        $f8, 0x7128($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7128);
    // 0x8007E8D4: nop

    // 0x8007E8D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E8DC: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x8007E8E0: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007E8E4: nop

    // 0x8007E8E8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8007E8EC: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x8007E8F0: jal         0x800C2948
    // 0x8007E8F4: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_11;
    // 0x8007E8F4: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_11:
    // 0x8007E8F8: jal         0x8002D200
    // 0x8007E8FC: nop

    func_8002D200(rdram, ctx);
        goto after_12;
    // 0x8007E8FC: nop

    after_12:
    // 0x8007E900: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x8007E904: b           L_8007E914
    // 0x8007E908: nop

        goto L_8007E914;
    // 0x8007E908: nop

    // 0x8007E90C: b           L_8007E914
    // 0x8007E910: nop

        goto L_8007E914;
    // 0x8007E910: nop

L_8007E914:
    // 0x8007E914: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007E918: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8007E91C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007E920: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8007E924: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007E928: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8007E92C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007E930: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8007E934: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007E938: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8007E93C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007E940: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8007E944: jr          $ra
    // 0x8007E948: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8007E948: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8007E94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E94C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007E950: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007E954: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007E958: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8007E95C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007E960: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007E964: nop

    // 0x8007E968: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007E96C: nop

    // 0x8007E970: bne         $t7, $zero, L_8007E980
    if (ctx->r15 != 0) {
        // 0x8007E974: nop

            goto L_8007E980;
    }
    // 0x8007E974: nop

    // 0x8007E978: b           L_8007EB80
    // 0x8007E97C: nop

        goto L_8007EB80;
    // 0x8007E97C: nop

L_8007E980:
    // 0x8007E980: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8007E984:
    // 0x8007E984: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007E988: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007E98C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007E990: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x8007E994: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8007E998: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8007E99C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8007E9A0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8007E9A4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E9A8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8007E9AC: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8007E9B0: nop

    // 0x8007E9B4: bne         $t5, $at, L_8007E9D4
    if (ctx->r13 != ctx->r1) {
        // 0x8007E9B8: nop

            goto L_8007E9D4;
    }
    // 0x8007E9B8: nop

    // 0x8007E9BC: lhu         $t6, 0x2($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X2);
    // 0x8007E9C0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8007E9C4: bne         $t6, $at, L_8007E9D4
    if (ctx->r14 != ctx->r1) {
        // 0x8007E9C8: nop

            goto L_8007E9D4;
    }
    // 0x8007E9C8: nop

    // 0x8007E9CC: b           L_8007EB78
    // 0x8007E9D0: nop

        goto L_8007EB78;
    // 0x8007E9D0: nop

L_8007E9D4:
    // 0x8007E9D4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E9D8: nop

    // 0x8007E9DC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8007E9E0: nop

    // 0x8007E9E4: andi        $t0, $t8, 0x3C
    ctx->r8 = ctx->r24 & 0X3C;
    // 0x8007E9E8: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007E9EC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8007E9F0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007E9F4: nop

    // 0x8007E9F8: bne         $t9, $zero, L_8007EA08
    if (ctx->r25 != 0) {
        // 0x8007E9FC: nop

            goto L_8007EA08;
    }
    // 0x8007E9FC: nop

    // 0x8007EA00: b           L_8007EB64
    // 0x8007EA04: nop

        goto L_8007EB64;
    // 0x8007EA04: nop

L_8007EA08:
    // 0x8007EA08: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007EA0C: nop

    // 0x8007EA10: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8007EA14: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8007EA18: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007EA1C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8007EA20: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8007EA24: addiu       $a1, $a1, 0x6BA0
    ctx->r5 = ADD32(ctx->r5, 0X6BA0);
    // 0x8007EA28: addiu       $a0, $a0, 0x6B98
    ctx->r4 = ADD32(ctx->r4, 0X6B98);
    // 0x8007EA2C: jal         0x8007EB90
    // 0x8007EA30: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    func_8007EB90(rdram, ctx);
        goto after_0;
    // 0x8007EA30: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    after_0:
    // 0x8007EA34: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007EA38: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8007EA3C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8007EA40: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8007EA44: lw          $a0, -0x37E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37E0);
    // 0x8007EA48: jal         0x80080698
    // 0x8007EA4C: nop

    func_80080698(rdram, ctx);
        goto after_1;
    // 0x8007EA4C: nop

    after_1:
    // 0x8007EA50: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x8007EA54: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007EA58: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007EA5C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8007EA60: lw          $t6, 0x6B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B98);
    // 0x8007EA64: mflo        $t8
    ctx->r24 = lo;
    // 0x8007EA68: negu        $t8, $t8
    ctx->r24 = SUB32(0, ctx->r24);
    // 0x8007EA6C: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x8007EA70: addiu       $t1, $t0, 0x18
    ctx->r9 = ADD32(ctx->r8, 0X18);
    // 0x8007EA74: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007EA78: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8007EA7C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007EA80: lw          $t9, 0x7100($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7100);
    // 0x8007EA84: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EA88: bne         $t9, $at, L_8007EAD4
    if (ctx->r25 != ctx->r1) {
        // 0x8007EA8C: nop

            goto L_8007EAD4;
    }
    // 0x8007EA8C: nop

    // 0x8007EA90: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007EA94: lw          $t2, 0x7104($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7104);
    // 0x8007EA98: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007EA9C: bne         $t2, $at, L_8007EAD4
    if (ctx->r10 != ctx->r1) {
        // 0x8007EAA0: nop

            goto L_8007EAD4;
    }
    // 0x8007EAA0: nop

    // 0x8007EAA4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8007EAA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007EAAC: bne         $t3, $at, L_8007EAD4
    if (ctx->r11 != ctx->r1) {
        // 0x8007EAB0: nop

            goto L_8007EAD4;
    }
    // 0x8007EAB0: nop

    // 0x8007EAB4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007EAB8: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007EABC: nop

    // 0x8007EAC0: andi        $t4, $t5, 0x100
    ctx->r12 = ctx->r13 & 0X100;
    // 0x8007EAC4: beq         $t4, $zero, L_8007EAD4
    if (ctx->r12 == 0) {
        // 0x8007EAC8: nop

            goto L_8007EAD4;
    }
    // 0x8007EAC8: nop

    // 0x8007EACC: addiu       $t7, $zero, 0x6319
    ctx->r15 = ADD32(0, 0X6319);
    // 0x8007EAD0: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
L_8007EAD4:
    // 0x8007EAD4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007EAD8: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007EADC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EAE0: bne         $t6, $at, L_8007EB20
    if (ctx->r14 != ctx->r1) {
        // 0x8007EAE4: nop

            goto L_8007EB20;
    }
    // 0x8007EAE4: nop

    // 0x8007EAE8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007EAEC: lw          $t8, 0x7104($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7104);
    // 0x8007EAF0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007EAF4: bne         $t8, $at, L_8007EB20
    if (ctx->r24 != ctx->r1) {
        // 0x8007EAF8: nop

            goto L_8007EB20;
    }
    // 0x8007EAF8: nop

    // 0x8007EAFC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007EB00: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007EB04: beq         $t0, $at, L_8007EB18
    if (ctx->r8 == ctx->r1) {
        // 0x8007EB08: nop

            goto L_8007EB18;
    }
    // 0x8007EB08: nop

    // 0x8007EB0C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EB10: bne         $t0, $at, L_8007EB20
    if (ctx->r8 != ctx->r1) {
        // 0x8007EB14: nop

            goto L_8007EB20;
    }
    // 0x8007EB14: nop

L_8007EB18:
    // 0x8007EB18: b           L_8007EB64
    // 0x8007EB1C: nop

        goto L_8007EB64;
    // 0x8007EB1C: nop

L_8007EB20:
    // 0x8007EB20: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007EB24: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007EB28: lw          $t9, -0x3908($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3908);
    // 0x8007EB2C: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x8007EB30: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8007EB34: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x8007EB38: sh          $t1, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r9;
    // 0x8007EB3C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007EB40: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x8007EB44: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8007EB48: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8007EB4C: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8007EB50: lw          $a2, -0x37E0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X37E0);
    // 0x8007EB54: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007EB58: addiu       $a0, $a0, -0xD28
    ctx->r4 = ADD32(ctx->r4, -0XD28);
    // 0x8007EB5C: jal         0x8008ECE4
    // 0x8007EB60: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8007EB60: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_2:
L_8007EB64:
    // 0x8007EB64: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007EB68: nop

    // 0x8007EB6C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8007EB70: b           L_8007E984
    // 0x8007EB74: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_8007E984;
    // 0x8007EB74: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8007EB78:
    // 0x8007EB78: b           L_8007EB80
    // 0x8007EB7C: nop

        goto L_8007EB80;
    // 0x8007EB7C: nop

L_8007EB80:
    // 0x8007EB80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007EB84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007EB88: jr          $ra
    // 0x8007EB8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007EB8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8007EB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EB90: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007EB94: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007EB98: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007EB9C: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8007EBA0: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007EBA4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8007EBA8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007EBAC: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8007EBB0: beq         $a0, $zero, L_8007EC18
    if (ctx->r4 == 0) {
        // 0x8007EBB4: nop

            goto L_8007EC18;
    }
    // 0x8007EBB4: nop

    // 0x8007EBB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007EBBC: lwc1        $f4, -0x3890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3890);
    // 0x8007EBC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007EBC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007EBC8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8007EBCC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007EBD0: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8007EBD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007EBD8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8007EBDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007EBE0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007EBE4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8007EBE8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007EBEC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8007EBF0: nop

    // 0x8007EBF4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8007EBF8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007EBFC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007EC00: nop

    // 0x8007EC04: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007EC08: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8007EC0C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8007EC10: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8007EC14: nop

L_8007EC18:
    // 0x8007EC18: beq         $a1, $zero, L_8007EC84
    if (ctx->r5 == 0) {
        // 0x8007EC1C: nop

            goto L_8007EC84;
    }
    // 0x8007EC1C: nop

    // 0x8007EC20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007EC24: lwc1        $f16, -0x388C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X388C);
    // 0x8007EC28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007EC2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007EC30: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8007EC34: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8007EC38: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8007EC3C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007EC40: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x8007EC44: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8007EC48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007EC4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007EC50: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8007EC54: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8007EC58: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007EC5C: nop

    // 0x8007EC60: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8007EC64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007EC68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007EC6C: nop

    // 0x8007EC70: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007EC74: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8007EC78: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007EC7C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EC80: nop

L_8007EC84:
    // 0x8007EC84: beq         $a2, $zero, L_8007ECA0
    if (ctx->r6 == 0) {
        // 0x8007EC88: nop

            goto L_8007ECA0;
    }
    // 0x8007EC88: nop

    // 0x8007EC8C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007EC90: nop

    // 0x8007EC94: lhu         $t1, 0xA($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XA);
    // 0x8007EC98: nop

    // 0x8007EC9C: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
L_8007ECA0:
    // 0x8007ECA0: b           L_8007ECA8
    // 0x8007ECA4: nop

        goto L_8007ECA8;
    // 0x8007ECA4: nop

L_8007ECA8:
    // 0x8007ECA8: jr          $ra
    // 0x8007ECAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007ECAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8007ECB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ECB0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007ECB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007ECB8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8007ECBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007ECC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007ECC4: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x8007ECC8: lhu         $t6, 0x4A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4A);
    // 0x8007ECCC: nop

    // 0x8007ECD0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8007ECD4: beq         $t8, $zero, L_8007EE20
    if (ctx->r24 == 0) {
        // 0x8007ECD8: nop

            goto L_8007EE20;
    }
    // 0x8007ECD8: nop

    // 0x8007ECDC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007ECE0: lw          $t9, 0x7100($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7100);
    // 0x8007ECE4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007ECE8: bne         $t9, $at, L_8007ED44
    if (ctx->r25 != ctx->r1) {
        // 0x8007ECEC: nop

            goto L_8007ED44;
    }
    // 0x8007ECEC: nop

    // 0x8007ECF0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007ECF4: lw          $t0, 0x7104($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7104);
    // 0x8007ECF8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007ECFC: beq         $t0, $at, L_8007ED10
    if (ctx->r8 == ctx->r1) {
        // 0x8007ED00: nop

            goto L_8007ED10;
    }
    // 0x8007ED00: nop

    // 0x8007ED04: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007ED08: bne         $t0, $at, L_8007ED44
    if (ctx->r8 != ctx->r1) {
        // 0x8007ED0C: nop

            goto L_8007ED44;
    }
    // 0x8007ED0C: nop

L_8007ED10:
    // 0x8007ED10: jal         0x800B9000
    // 0x8007ED14: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x8007ED14: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x8007ED18: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x8007ED1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED20: sh          $t1, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r9;
    // 0x8007ED24: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8007ED28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED2C: sh          $t2, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r10;
    // 0x8007ED30: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007ED34: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007ED38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED3C: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8007ED40: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
L_8007ED44:
    // 0x8007ED44: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007ED48: lw          $t5, 0x7100($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7100);
    // 0x8007ED4C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007ED50: bne         $t5, $at, L_8007EDA0
    if (ctx->r13 != ctx->r1) {
        // 0x8007ED54: nop

            goto L_8007EDA0;
    }
    // 0x8007ED54: nop

    // 0x8007ED58: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007ED5C: lw          $t6, 0x7104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7104);
    // 0x8007ED60: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8007ED64: bne         $t6, $at, L_8007EDA0
    if (ctx->r14 != ctx->r1) {
        // 0x8007ED68: nop

            goto L_8007EDA0;
    }
    // 0x8007ED68: nop

    // 0x8007ED6C: jal         0x800B9000
    // 0x8007ED70: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8007ED70: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_1:
    // 0x8007ED74: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8007ED78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED7C: sh          $t7, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r15;
    // 0x8007ED80: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8007ED84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED88: sh          $t8, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r24;
    // 0x8007ED8C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007ED90: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007ED94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED98: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8007ED9C: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
L_8007EDA0:
    // 0x8007EDA0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007EDA4: lw          $t1, 0x7100($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7100);
    // 0x8007EDA8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EDAC: bne         $t1, $at, L_8007EDDC
    if (ctx->r9 != ctx->r1) {
        // 0x8007EDB0: nop

            goto L_8007EDDC;
    }
    // 0x8007EDB0: nop

    // 0x8007EDB4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007EDB8: lw          $t2, 0x7104($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7104);
    // 0x8007EDBC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007EDC0: bne         $t2, $at, L_8007EDDC
    if (ctx->r10 != ctx->r1) {
        // 0x8007EDC4: nop

            goto L_8007EDDC;
    }
    // 0x8007EDC4: nop

    // 0x8007EDC8: jal         0x800B9000
    // 0x8007EDCC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_2;
    // 0x8007EDCC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x8007EDD0: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8007EDD4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EDD8: sh          $t3, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r11;
L_8007EDDC:
    // 0x8007EDDC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007EDE0: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007EDE4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EDE8: bne         $t4, $at, L_8007EE18
    if (ctx->r12 != ctx->r1) {
        // 0x8007EDEC: nop

            goto L_8007EE18;
    }
    // 0x8007EDEC: nop

    // 0x8007EDF0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007EDF4: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007EDF8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007EDFC: bne         $t5, $at, L_8007EE18
    if (ctx->r13 != ctx->r1) {
        // 0x8007EE00: nop

            goto L_8007EE18;
    }
    // 0x8007EE00: nop

    // 0x8007EE04: jal         0x800B9000
    // 0x8007EE08: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8007EE08: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_3:
    // 0x8007EE0C: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8007EE10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EE14: sh          $t6, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r14;
L_8007EE18:
    // 0x8007EE18: b           L_8007F868
    // 0x8007EE1C: nop

        goto L_8007F868;
    // 0x8007EE1C: nop

L_8007EE20:
    // 0x8007EE20: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8007EE24: lh          $a3, 0x7132($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7132);
    // 0x8007EE28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007EE2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007EE30: jal         0x8007EB90
    // 0x8007EE34: addiu       $a2, $sp, 0x2E
    ctx->r6 = ADD32(ctx->r29, 0X2E);
    func_8007EB90(rdram, ctx);
        goto after_4;
    // 0x8007EE34: addiu       $a2, $sp, 0x2E
    ctx->r6 = ADD32(ctx->r29, 0X2E);
    after_4:
    // 0x8007EE38: lhu         $t7, 0x2E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2E);
    // 0x8007EE3C: addiu       $at, $zero, 0x2109
    ctx->r1 = ADD32(0, 0X2109);
    // 0x8007EE40: bne         $t7, $at, L_8007EE58
    if (ctx->r15 != ctx->r1) {
        // 0x8007EE44: nop

            goto L_8007EE58;
    }
    // 0x8007EE44: nop

    // 0x8007EE48: jal         0x8007B710
    // 0x8007EE4C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8007B710(rdram, ctx);
        goto after_5;
    // 0x8007EE4C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x8007EE50: b           L_8007EE60
    // 0x8007EE54: nop

        goto L_8007EE60;
    // 0x8007EE54: nop

L_8007EE58:
    // 0x8007EE58: jal         0x8007B710
    // 0x8007EE5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007B710(rdram, ctx);
        goto after_6;
    // 0x8007EE5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
L_8007EE60:
    // 0x8007EE60: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007EE64: addiu       $t8, $t8, 0x70F0
    ctx->r24 = ADD32(ctx->r24, 0X70F0);
    // 0x8007EE68: lh          $t9, 0x3C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X3C);
    // 0x8007EE6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007EE70: beq         $t9, $at, L_8007F004
    if (ctx->r25 == ctx->r1) {
        // 0x8007EE74: nop

            goto L_8007F004;
    }
    // 0x8007EE74: nop

    // 0x8007EE78: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007EE7C: addiu       $t0, $t0, 0x70F0
    ctx->r8 = ADD32(ctx->r8, 0X70F0);
    // 0x8007EE80: lh          $t1, 0x3C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X3C);
    // 0x8007EE84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EE88: sh          $t1, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r9;
    // 0x8007EE8C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007EE90: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007EE94: lh          $t3, 0x3E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X3E);
    // 0x8007EE98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EE9C: sh          $t3, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r11;
    // 0x8007EEA0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007EEA4: lh          $t4, 0x713A($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X713A);
    // 0x8007EEA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EEAC: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x8007EEB0: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
    // 0x8007EEB4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007EEB8: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007EEBC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EEC0: bne         $t6, $at, L_8007EF1C
    if (ctx->r14 != ctx->r1) {
        // 0x8007EEC4: nop

            goto L_8007EF1C;
    }
    // 0x8007EEC4: nop

    // 0x8007EEC8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007EECC: lw          $t7, 0x7104($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7104);
    // 0x8007EED0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8007EED4: bne         $t7, $at, L_8007EF1C
    if (ctx->r15 != ctx->r1) {
        // 0x8007EED8: nop

            goto L_8007EF1C;
    }
    // 0x8007EED8: nop

    // 0x8007EEDC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007EEE0: lh          $t8, 0x7132($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7132);
    // 0x8007EEE4: nop

    // 0x8007EEE8: bltz        $t8, L_8007EF1C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007EEEC: nop

            goto L_8007EF1C;
    }
    // 0x8007EEEC: nop

    // 0x8007EEF0: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8007EEF4: beq         $at, $zero, L_8007EF1C
    if (ctx->r1 == 0) {
        // 0x8007EEF8: nop

            goto L_8007EF1C;
    }
    // 0x8007EEF8: nop

    // 0x8007EEFC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007EF00: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007EF04: lh          $a1, 0x7132($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7132);
    // 0x8007EF08: lb          $a0, 0x7140($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7140);
    // 0x8007EF0C: jal         0x8007F930
    // 0x8007EF10: nop

    func_8007F930(rdram, ctx);
        goto after_7;
    // 0x8007EF10: nop

    after_7:
    // 0x8007EF14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EF18: sb          $v0, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r2;
L_8007EF1C:
    // 0x8007EF1C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007EF20: lw          $t9, 0x7100($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7100);
    // 0x8007EF24: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EF28: bne         $t9, $at, L_8007EFCC
    if (ctx->r25 != ctx->r1) {
        // 0x8007EF2C: nop

            goto L_8007EFCC;
    }
    // 0x8007EF2C: nop

    // 0x8007EF30: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007EF34: lw          $t0, 0x7104($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7104);
    // 0x8007EF38: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007EF3C: bne         $t0, $at, L_8007EFCC
    if (ctx->r8 != ctx->r1) {
        // 0x8007EF40: nop

            goto L_8007EFCC;
    }
    // 0x8007EF40: nop

    // 0x8007EF44: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007EF48: lh          $t1, 0x7132($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7132);
    // 0x8007EF4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007EF50: bne         $t1, $at, L_8007EFCC
    if (ctx->r9 != ctx->r1) {
        // 0x8007EF54: nop

            goto L_8007EFCC;
    }
    // 0x8007EF54: nop

    // 0x8007EF58: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007EF5C: lw          $t2, 0x70FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70FC);
    // 0x8007EF60: nop

    // 0x8007EF64: bne         $t2, $zero, L_8007EFB0
    if (ctx->r10 != 0) {
        // 0x8007EF68: nop

            goto L_8007EFB0;
    }
    // 0x8007EF68: nop

    // 0x8007EF6C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007EF70: lw          $a0, 0x70FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70FC);
    // 0x8007EF74: jal         0x8007A514
    // 0x8007EF78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8007A514(rdram, ctx);
        goto after_8;
    // 0x8007EF78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8007EF7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EF80: sw          $v0, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r2;
    // 0x8007EF84: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007EF88: lw          $t3, 0x70FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70FC);
    // 0x8007EF8C: nop

    // 0x8007EF90: bne         $t3, $zero, L_8007EFB0
    if (ctx->r11 != 0) {
        // 0x8007EF94: nop

            goto L_8007EFB0;
    }
    // 0x8007EF94: nop

    // 0x8007EF98: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007EF9C: lh          $t4, 0x713A($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X713A);
    // 0x8007EFA0: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8007EFA4: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8007EFA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EFAC: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
L_8007EFB0:
    // 0x8007EFB0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007EFB4: lw          $t6, 0x70FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70FC);
    // 0x8007EFB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EFBC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8007EFC0: nop

    // 0x8007EFC4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007EFC8: sb          $t8, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r24;
L_8007EFCC:
    // 0x8007EFCC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007EFD0: lw          $t9, 0x7100($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7100);
    // 0x8007EFD4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EFD8: bne         $t9, $at, L_8007F004
    if (ctx->r25 != ctx->r1) {
        // 0x8007EFDC: nop

            goto L_8007F004;
    }
    // 0x8007EFDC: nop

    // 0x8007EFE0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007EFE4: lw          $t0, 0x7104($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7104);
    // 0x8007EFE8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007EFEC: bne         $t0, $at, L_8007F004
    if (ctx->r8 != ctx->r1) {
        // 0x8007EFF0: nop

            goto L_8007F004;
    }
    // 0x8007EFF0: nop

    // 0x8007EFF4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007EFF8: lh          $t1, 0x7132($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7132);
    // 0x8007EFFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F000: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
L_8007F004:
    // 0x8007F004: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F008: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007F00C: lh          $t3, 0x3E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X3E);
    // 0x8007F010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F014: bne         $t3, $at, L_8007F054
    if (ctx->r11 != ctx->r1) {
        // 0x8007F018: nop

            goto L_8007F054;
    }
    // 0x8007F018: nop

    // 0x8007F01C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007F020: lw          $t4, 0x70F8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F8);
    // 0x8007F024: nop

    // 0x8007F028: bne         $t4, $zero, L_8007F040
    if (ctx->r12 != 0) {
        // 0x8007F02C: nop

            goto L_8007F040;
    }
    // 0x8007F02C: nop

    // 0x8007F030: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x8007F034: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F038: b           L_8007F04C
    // 0x8007F03C: sh          $t5, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r13;
        goto L_8007F04C;
    // 0x8007F03C: sh          $t5, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r13;
L_8007F040:
    // 0x8007F040: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8007F044: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F048: sh          $t6, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r14;
L_8007F04C:
    // 0x8007F04C: b           L_8007F868
    // 0x8007F050: nop

        goto L_8007F868;
    // 0x8007F050: nop

L_8007F054:
    // 0x8007F054: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F058: addiu       $t7, $t7, 0x70F0
    ctx->r15 = ADD32(ctx->r15, 0X70F0);
    // 0x8007F05C: lh          $t8, 0x3E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X3E);
    // 0x8007F060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F064: bne         $t8, $at, L_8007F0A8
    if (ctx->r24 != ctx->r1) {
        // 0x8007F068: nop

            goto L_8007F0A8;
    }
    // 0x8007F068: nop

    // 0x8007F06C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F070: lb          $a0, 0x7140($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7140);
    // 0x8007F074: jal         0x8007F930
    // 0x8007F078: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
    func_8007F930(rdram, ctx);
        goto after_9;
    // 0x8007F078: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
    after_9:
    // 0x8007F07C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F080: sb          $v0, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = ctx->r2;
    // 0x8007F084: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F088: lb          $t9, 0x7140($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7140);
    // 0x8007F08C: nop

    // 0x8007F090: bgez        $t9, L_8007F0A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007F094: nop

            goto L_8007F0A0;
    }
    // 0x8007F094: nop

    // 0x8007F098: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F09C: sb          $zero, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = 0;
L_8007F0A0:
    // 0x8007F0A0: b           L_8007F868
    // 0x8007F0A4: nop

        goto L_8007F868;
    // 0x8007F0A4: nop

L_8007F0A8:
    // 0x8007F0A8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F0AC: addiu       $t0, $t0, 0x70F0
    ctx->r8 = ADD32(ctx->r8, 0X70F0);
    // 0x8007F0B0: lh          $t1, 0x3E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X3E);
    // 0x8007F0B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007F0B8: bne         $t1, $at, L_8007F118
    if (ctx->r9 != ctx->r1) {
        // 0x8007F0BC: nop

            goto L_8007F118;
    }
    // 0x8007F0BC: nop

    // 0x8007F0C0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F0C4: lb          $a0, 0x7140($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7140);
    // 0x8007F0C8: jal         0x8007F930
    // 0x8007F0CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8007F930(rdram, ctx);
        goto after_10;
    // 0x8007F0CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x8007F0D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F0D4: sb          $v0, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = ctx->r2;
    // 0x8007F0D8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8007F0DC: jal         0x8007F930
    // 0x8007F0E0: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    func_8007F930(rdram, ctx);
        goto after_11;
    // 0x8007F0E0: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    after_11:
    // 0x8007F0E4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8007F0E8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F0EC: lb          $t2, 0x7140($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7140);
    // 0x8007F0F0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8007F0F4: nop

    // 0x8007F0F8: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007F0FC: bne         $at, $zero, L_8007F110
    if (ctx->r1 != 0) {
        // 0x8007F100: nop

            goto L_8007F110;
    }
    // 0x8007F100: nop

    // 0x8007F104: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8007F108: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F10C: sb          $t4, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = ctx->r12;
L_8007F110:
    // 0x8007F110: b           L_8007F868
    // 0x8007F114: nop

        goto L_8007F868;
    // 0x8007F114: nop

L_8007F118:
    // 0x8007F118: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007F11C: addiu       $t5, $t5, 0x70F0
    ctx->r13 = ADD32(ctx->r13, 0X70F0);
    // 0x8007F120: lh          $t6, 0x3E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X3E);
    // 0x8007F124: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007F128: bne         $t6, $at, L_8007F3AC
    if (ctx->r14 != ctx->r1) {
        // 0x8007F12C: nop

            goto L_8007F3AC;
    }
    // 0x8007F12C: nop

    // 0x8007F130: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F134: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007F138: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F13C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007F140: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8007F144: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007F148: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8007F14C: lh          $t2, 0x2460($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2460);
    // 0x8007F150: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F154: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007F158: lw          $t8, 0x718C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X718C);
    // 0x8007F15C: lw          $t7, 0x70E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E8);
    // 0x8007F160: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8007F164: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007F168: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8007F16C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007F170: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x8007F174: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8007F178: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007F17C: nop

    // 0x8007F180: bgez        $t5, L_8007F1D4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007F184: nop

            goto L_8007F1D4;
    }
    // 0x8007F184: nop

    // 0x8007F188: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007F18C: addiu       $t6, $t6, 0x2440
    ctx->r14 = ADD32(ctx->r14, 0X2440);
    // 0x8007F190: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F194: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F198: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F19C: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F1A0: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x8007F1A4: jal         0x800BD1FC
    // 0x8007F1A8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_12;
    // 0x8007F1A8: nop

    after_12:
    // 0x8007F1AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F1B0: jal         0x80080910
    // 0x8007F1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_13;
    // 0x8007F1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8007F1B8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F1BC: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007F1C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F1C4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8007F1C8: sh          $t8, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r24;
    // 0x8007F1CC: b           L_8007F868
    // 0x8007F1D0: nop

        goto L_8007F868;
    // 0x8007F1D0: nop

L_8007F1D4:
    // 0x8007F1D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007F1D8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F1DC: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007F1E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007F1E4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8007F1E8: lbu         $t1, 0x1B19($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1B19);
    // 0x8007F1EC: nop

    // 0x8007F1F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8007F1F4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F1F8: lb          $t2, 0x7142($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7142);
    // 0x8007F1FC: nop

    // 0x8007F200: beq         $t2, $zero, L_8007F214
    if (ctx->r10 == 0) {
        // 0x8007F204: nop

            goto L_8007F214;
    }
    // 0x8007F204: nop

    // 0x8007F208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F20C: bne         $t2, $at, L_8007F238
    if (ctx->r10 != ctx->r1) {
        // 0x8007F210: nop

            goto L_8007F238;
    }
    // 0x8007F210: nop

L_8007F214:
    // 0x8007F214: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F218: lb          $t9, 0x7142($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7142);
    // 0x8007F21C: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8007F220: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x8007F224: lbu         $s0, 0x1B40($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0X1B40);
    // 0x8007F228: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007F22C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8007F230: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8007F234: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_8007F238:
    // 0x8007F238: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F23C: lb          $t6, 0x7142($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7142);
    // 0x8007F240: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007F244: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007F248: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007F24C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F250: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007F254: lh          $t8, 0x2464($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2464);
    // 0x8007F258: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007F25C: nop

    // 0x8007F260: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007F264: bne         $at, $zero, L_8007F300
    if (ctx->r1 != 0) {
        // 0x8007F268: nop

            goto L_8007F300;
    }
    // 0x8007F268: nop

    // 0x8007F26C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007F270: nop

    // 0x8007F274: beq         $t0, $zero, L_8007F2B4
    if (ctx->r8 == 0) {
        // 0x8007F278: nop

            goto L_8007F2B4;
    }
    // 0x8007F278: nop

    // 0x8007F27C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F280: addiu       $t1, $t1, 0x2440
    ctx->r9 = ADD32(ctx->r9, 0X2440);
    // 0x8007F284: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F288: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F28C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F290: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F294: lw          $a2, 0x14($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X14);
    // 0x8007F298: jal         0x800BD1FC
    // 0x8007F29C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_14;
    // 0x8007F29C: nop

    after_14:
    // 0x8007F2A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F2A4: jal         0x80080910
    // 0x8007F2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_15;
    // 0x8007F2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8007F2AC: b           L_8007F2E4
    // 0x8007F2B0: nop

        goto L_8007F2E4;
    // 0x8007F2B0: nop

L_8007F2B4:
    // 0x8007F2B4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F2B8: addiu       $t2, $t2, 0x2440
    ctx->r10 = ADD32(ctx->r10, 0X2440);
    // 0x8007F2BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F2C0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F2C4: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F2C8: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F2CC: lw          $a2, 0xC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0XC);
    // 0x8007F2D0: jal         0x800BD1FC
    // 0x8007F2D4: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_16;
    // 0x8007F2D4: nop

    after_16:
    // 0x8007F2D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F2DC: jal         0x80080910
    // 0x8007F2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_17;
    // 0x8007F2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_8007F2E4:
    // 0x8007F2E4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F2E8: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007F2EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F2F0: ori         $t3, $t9, 0x10
    ctx->r11 = ctx->r25 | 0X10;
    // 0x8007F2F4: sh          $t3, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r11;
    // 0x8007F2F8: b           L_8007F868
    // 0x8007F2FC: nop

        goto L_8007F868;
    // 0x8007F2FC: nop

L_8007F300:
    // 0x8007F300: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F304: lb          $t6, 0x7142($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7142);
    // 0x8007F308: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007F30C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007F310: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007F314: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F318: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8007F31C: lh          $t5, 0x2460($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2460);
    // 0x8007F320: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007F324: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8007F328: lw          $t4, 0x718C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X718C);
    // 0x8007F32C: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8007F330: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8007F334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F338: subu        $t0, $t4, $t8
    ctx->r8 = SUB32(ctx->r12, ctx->r24);
    // 0x8007F33C: sw          $t0, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r8;
    // 0x8007F340: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F344: addiu       $t1, $t1, 0x2440
    ctx->r9 = ADD32(ctx->r9, 0X2440);
    // 0x8007F348: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F34C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F350: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F354: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F358: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8007F35C: jal         0x800BD1FC
    // 0x8007F360: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_18;
    // 0x8007F360: nop

    after_18:
    // 0x8007F364: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F368: jal         0x80080910
    // 0x8007F36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_19;
    // 0x8007F36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8007F370: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F374: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007F378: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F37C: ori         $t9, $t2, 0x10
    ctx->r25 = ctx->r10 | 0X10;
    // 0x8007F380: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007F384: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F388: lb          $a0, 0x7142($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7142);
    // 0x8007F38C: jal         0x80029C8C
    // 0x8007F390: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_80029C8C(rdram, ctx);
        goto after_20;
    // 0x8007F390: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_20:
    // 0x8007F394: jal         0x800B9000
    // 0x8007F398: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800B9000(rdram, ctx);
        goto after_21;
    // 0x8007F398: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_21:
    // 0x8007F39C: jal         0x8007DF3C
    // 0x8007F3A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007DF3C(rdram, ctx);
        goto after_22;
    // 0x8007F3A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x8007F3A4: b           L_8007F868
    // 0x8007F3A8: nop

        goto L_8007F868;
    // 0x8007F3A8: nop

L_8007F3AC:
    // 0x8007F3AC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007F3B0: addiu       $t3, $t3, 0x70F0
    ctx->r11 = ADD32(ctx->r11, 0X70F0);
    // 0x8007F3B4: lh          $t6, 0x3E($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X3E);
    // 0x8007F3B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007F3BC: bne         $t6, $at, L_8007F5A0
    if (ctx->r14 != ctx->r1) {
        // 0x8007F3C0: nop

            goto L_8007F5A0;
    }
    // 0x8007F3C0: nop

    // 0x8007F3C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F3C8: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007F3CC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007F3D0: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8007F3D4: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8007F3D8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007F3DC: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F3E0: lh          $t4, 0x2462($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2462);
    // 0x8007F3E4: nop

    // 0x8007F3E8: bgez        $t4, L_8007F43C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007F3EC: nop

            goto L_8007F43C;
    }
    // 0x8007F3EC: nop

    // 0x8007F3F0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007F3F4: addiu       $t8, $t8, 0x2440
    ctx->r24 = ADD32(ctx->r24, 0X2440);
    // 0x8007F3F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F3FC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F400: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F404: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F408: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x8007F40C: jal         0x800BD1FC
    // 0x8007F410: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_23;
    // 0x8007F410: nop

    after_23:
    // 0x8007F414: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F418: jal         0x80080910
    // 0x8007F41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_24;
    // 0x8007F41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8007F420: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F424: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007F428: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F42C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8007F430: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007F434: b           L_8007F868
    // 0x8007F438: nop

        goto L_8007F868;
    // 0x8007F438: nop

L_8007F43C:
    // 0x8007F43C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F440: addiu       $t2, $t2, 0x2440
    ctx->r10 = ADD32(ctx->r10, 0X2440);
    // 0x8007F444: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F448: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F44C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F450: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F454: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8007F458: jal         0x800BD1FC
    // 0x8007F45C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_25;
    // 0x8007F45C: nop

    after_25:
    // 0x8007F460: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F464: jal         0x80080910
    // 0x8007F468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_26;
    // 0x8007F468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8007F46C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F470: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007F474: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F478: ori         $t3, $t9, 0x10
    ctx->r11 = ctx->r25 | 0X10;
    // 0x8007F47C: sh          $t3, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r11;
    // 0x8007F480: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F484: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007F488: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007F48C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8007F490: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8007F494: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007F498: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F49C: lh          $t4, 0x2462($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2462);
    // 0x8007F4A0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F4A4: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8007F4A8: lw          $t6, 0x718C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X718C);
    // 0x8007F4AC: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x8007F4B0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8007F4B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F4B8: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x8007F4BC: sw          $t0, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r8;
    // 0x8007F4C0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007F4C4: lw          $t1, 0x70FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70FC);
    // 0x8007F4C8: nop

    // 0x8007F4CC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8007F4D0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8007F4D4: nop

    // 0x8007F4D8: lw          $t9, 0x18($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X18);
    // 0x8007F4DC: nop

    // 0x8007F4E0: beq         $t9, $zero, L_8007F50C
    if (ctx->r25 == 0) {
        // 0x8007F4E4: nop

            goto L_8007F50C;
    }
    // 0x8007F4E4: nop

    // 0x8007F4E8: lh          $t3, 0x2($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X2);
    // 0x8007F4EC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007F4F0: bne         $t3, $at, L_8007F50C
    if (ctx->r11 != ctx->r1) {
        // 0x8007F4F4: nop

            goto L_8007F50C;
    }
    // 0x8007F4F4: nop

    // 0x8007F4F8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8007F4FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F500: lw          $t5, 0x18($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X18);
    // 0x8007F504: b           L_8007F57C
    // 0x8007F508: sw          $t5, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r13;
        goto L_8007F57C;
    // 0x8007F508: sw          $t5, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r13;
L_8007F50C:
    // 0x8007F50C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8007F510: jal         0x8007A514
    // 0x8007F514: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8007A514(rdram, ctx);
        goto after_27;
    // 0x8007F514: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_27:
    // 0x8007F518: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007F51C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8007F520: nop

    // 0x8007F524: bne         $t4, $zero, L_8007F570
    if (ctx->r12 != 0) {
        // 0x8007F528: nop

            goto L_8007F570;
    }
    // 0x8007F528: nop

    // 0x8007F52C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007F530: addiu       $t6, $t6, 0x2440
    ctx->r14 = ADD32(ctx->r14, 0X2440);
    // 0x8007F534: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F538: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F53C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F540: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F544: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x8007F548: jal         0x800BD1FC
    // 0x8007F54C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_28;
    // 0x8007F54C: nop

    after_28:
    // 0x8007F550: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F554: jal         0x80080910
    // 0x8007F558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_29;
    // 0x8007F558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8007F55C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007F560: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007F564: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F568: ori         $t0, $t8, 0x310
    ctx->r8 = ctx->r24 | 0X310;
    // 0x8007F56C: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
L_8007F570:
    // 0x8007F570: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8007F574: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F578: sw          $t1, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r9;
L_8007F57C:
    // 0x8007F57C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8007F580: jal         0x800299C4
    // 0x8007F584: nop

    func_800299C4(rdram, ctx);
        goto after_30;
    // 0x8007F584: nop

    after_30:
    // 0x8007F588: jal         0x800B9000
    // 0x8007F58C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800B9000(rdram, ctx);
        goto after_31;
    // 0x8007F58C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_31:
    // 0x8007F590: jal         0x8007DF3C
    // 0x8007F594: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007DF3C(rdram, ctx);
        goto after_32;
    // 0x8007F594: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_32:
    // 0x8007F598: b           L_8007F868
    // 0x8007F59C: nop

        goto L_8007F868;
    // 0x8007F59C: nop

L_8007F5A0:
    // 0x8007F5A0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F5A4: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007F5A8: lh          $t9, 0x3E($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X3E);
    // 0x8007F5AC: nop

    // 0x8007F5B0: bne         $t9, $zero, L_8007F618
    if (ctx->r25 != 0) {
        // 0x8007F5B4: nop

            goto L_8007F618;
    }
    // 0x8007F5B4: nop

    // 0x8007F5B8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007F5BC: lb          $t3, 0x7142($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7142);
    // 0x8007F5C0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007F5C4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8007F5C8: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8007F5CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F5D0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8007F5D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F5D8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F5DC: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F5E0: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F5E4: lw          $a2, 0x245C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X245C);
    // 0x8007F5E8: jal         0x800BD1FC
    // 0x8007F5EC: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_33;
    // 0x8007F5EC: nop

    after_33:
    // 0x8007F5F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F5F4: jal         0x80080910
    // 0x8007F5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_34;
    // 0x8007F5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8007F5FC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007F600: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007F604: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F608: ori         $t4, $t5, 0x10
    ctx->r12 = ctx->r13 | 0X10;
    // 0x8007F60C: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007F610: b           L_8007F868
    // 0x8007F614: nop

        goto L_8007F868;
    // 0x8007F614: nop

L_8007F618:
    // 0x8007F618: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F61C: addiu       $t6, $t6, 0x70F0
    ctx->r14 = ADD32(ctx->r14, 0X70F0);
    // 0x8007F620: lh          $t8, 0x3E($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X3E);
    // 0x8007F624: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007F628: bne         $t8, $at, L_8007F858
    if (ctx->r24 != ctx->r1) {
        // 0x8007F62C: nop

            goto L_8007F858;
    }
    // 0x8007F62C: nop

    // 0x8007F630: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F634: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007F638: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F63C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007F640: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007F644: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007F648: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8007F64C: lbu         $a0, 0x27A8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27A8);
    // 0x8007F650: jal         0x8005F064
    // 0x8007F654: nop

    func_8005F064(rdram, ctx);
        goto after_35;
    // 0x8007F654: nop

    after_35:
    // 0x8007F658: bne         $v0, $zero, L_8007F7B8
    if (ctx->r2 != 0) {
        // 0x8007F65C: nop

            goto L_8007F7B8;
    }
    // 0x8007F65C: nop

    // 0x8007F660: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F664: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007F668: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007F66C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8007F670: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x8007F674: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007F678: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F67C: lh          $t4, 0x27AC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X27AC);
    // 0x8007F680: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F684: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F688: lw          $t9, 0x718C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X718C);
    // 0x8007F68C: lw          $t2, 0x70E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70E8);
    // 0x8007F690: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8007F694: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8007F698: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8007F69C: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8007F6A0: subu        $t8, $t3, $t6
    ctx->r24 = SUB32(ctx->r11, ctx->r14);
    // 0x8007F6A4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8007F6A8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007F6AC: nop

    // 0x8007F6B0: bltz        $t0, L_8007F780
    if (SIGNED(ctx->r8) < 0) {
        // 0x8007F6B4: nop

            goto L_8007F780;
    }
    // 0x8007F6B4: nop

    // 0x8007F6B8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F6BC: addiu       $t1, $t1, 0x278C
    ctx->r9 = ADD32(ctx->r9, 0X278C);
    // 0x8007F6C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F6C4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F6C8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F6CC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F6D0: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x8007F6D4: jal         0x800BD1FC
    // 0x8007F6D8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_36;
    // 0x8007F6D8: nop

    after_36:
    // 0x8007F6DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F6E0: jal         0x80080910
    // 0x8007F6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_37;
    // 0x8007F6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x8007F6E8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F6EC: lb          $t9, 0x7142($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7142);
    // 0x8007F6F0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007F6F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007F6F8: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x8007F6FC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007F700: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8007F704: lh          $t5, 0x27AC($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X27AC);
    // 0x8007F708: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F70C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8007F710: lw          $t2, 0x718C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X718C);
    // 0x8007F714: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F718: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8007F71C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F720: subu        $t3, $t2, $t4
    ctx->r11 = SUB32(ctx->r10, ctx->r12);
    // 0x8007F724: sw          $t3, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r11;
    // 0x8007F728: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F72C: lb          $t6, 0x7142($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7142);
    // 0x8007F730: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F734: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8007F738: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8007F73C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007F740: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8007F744: lbu         $a0, 0x27A8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27A8);
    // 0x8007F748: jal         0x8005F0DC
    // 0x8007F74C: nop

    func_8005F0DC(rdram, ctx);
        goto after_38;
    // 0x8007F74C: nop

    after_38:
    // 0x8007F750: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F754: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007F758: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F75C: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x8007F760: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007F764: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8007F768: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F76C: sh          $t9, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r25;
    // 0x8007F770: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8007F774: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F778: b           L_8007F7B0
    // 0x8007F77C: sh          $t7, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r15;
        goto L_8007F7B0;
    // 0x8007F77C: sh          $t7, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r15;
L_8007F780:
    // 0x8007F780: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007F784: addiu       $t5, $t5, 0x278C
    ctx->r13 = ADD32(ctx->r13, 0X278C);
    // 0x8007F788: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F78C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F790: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F794: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F798: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x8007F79C: jal         0x800BD1FC
    // 0x8007F7A0: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_39;
    // 0x8007F7A0: nop

    after_39:
    // 0x8007F7A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F7A8: jal         0x80080910
    // 0x8007F7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_40;
    // 0x8007F7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
L_8007F7B0:
    // 0x8007F7B0: b           L_8007F83C
    // 0x8007F7B4: nop

        goto L_8007F83C;
    // 0x8007F7B4: nop

L_8007F7B8:
    // 0x8007F7B8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F7BC: addiu       $t2, $t2, 0x278C
    ctx->r10 = ADD32(ctx->r10, 0X278C);
    // 0x8007F7C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F7C4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F7C8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F7CC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F7D0: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x8007F7D4: jal         0x800BD1FC
    // 0x8007F7D8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_41;
    // 0x8007F7D8: nop

    after_41:
    // 0x8007F7DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F7E0: jal         0x80080910
    // 0x8007F7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_42;
    // 0x8007F7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8007F7E8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007F7EC: lb          $t4, 0x7142($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7142);
    // 0x8007F7F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F7F4: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8007F7F8: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x8007F7FC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8007F800: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8007F804: lbu         $a0, 0x27A8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27A8);
    // 0x8007F808: jal         0x8005F0DC
    // 0x8007F80C: nop

    func_8005F0DC(rdram, ctx);
        goto after_43;
    // 0x8007F80C: nop

    after_43:
    // 0x8007F810: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F814: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007F818: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F81C: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8007F820: sh          $t8, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r24;
    // 0x8007F824: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x8007F828: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F82C: sh          $t0, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r8;
    // 0x8007F830: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8007F834: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F838: sh          $t1, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r9;
L_8007F83C:
    // 0x8007F83C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F840: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007F844: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F848: ori         $t7, $t9, 0x210
    ctx->r15 = ctx->r25 | 0X210;
    // 0x8007F84C: sh          $t7, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r15;
    // 0x8007F850: b           L_8007F868
    // 0x8007F854: nop

        goto L_8007F868;
    // 0x8007F854: nop

L_8007F858:
    // 0x8007F858: b           L_8007F868
    // 0x8007F85C: nop

        goto L_8007F868;
    // 0x8007F85C: nop

    // 0x8007F860: b           L_8007F868
    // 0x8007F864: nop

        goto L_8007F868;
    // 0x8007F864: nop

L_8007F868:
    // 0x8007F868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F86C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007F870: jr          $ra
    // 0x8007F874: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007F874: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8007F878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007F884: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F888: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007F88C: jal         0x800A4104
    // 0x8007F890: nop

    func_800A4104(rdram, ctx);
        goto after_0;
    // 0x8007F890: nop

    after_0:
    // 0x8007F894: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F898: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007F89C: jal         0x800A3FC0
    // 0x8007F8A0: nop

    func_800A3FC0(rdram, ctx);
        goto after_1;
    // 0x8007F8A0: nop

    after_1:
    // 0x8007F8A4: jal         0x800BC6EC
    // 0x8007F8A8: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8007F8A8: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_2:
    // 0x8007F8AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F8B0: sw          $v0, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = ctx->r2;
    // 0x8007F8B4: jal         0x800BC6EC
    // 0x8007F8B8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x8007F8B8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_3:
    // 0x8007F8BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F8C0: sw          $v0, 0x70F0($at)
    MEM_W(0X70F0, ctx->r1) = ctx->r2;
    // 0x8007F8C4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F8C8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007F8CC: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007F8D0: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007F8D4: jal         0x800B1B04
    // 0x8007F8D8: nop

    func_800B1B04(rdram, ctx);
        goto after_4;
    // 0x8007F8D8: nop

    after_4:
    // 0x8007F8DC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F8E0: lh          $t6, 0x7132($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7132);
    // 0x8007F8E4: nop

    // 0x8007F8E8: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x8007F8EC: beq         $at, $zero, L_8007F904
    if (ctx->r1 == 0) {
        // 0x8007F8F0: nop

            goto L_8007F904;
    }
    // 0x8007F8F0: nop

    // 0x8007F8F4: jal         0x8007B710
    // 0x8007F8F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8007B710(rdram, ctx);
        goto after_5;
    // 0x8007F8F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x8007F8FC: b           L_8007F90C
    // 0x8007F900: nop

        goto L_8007F90C;
    // 0x8007F900: nop

L_8007F904:
    // 0x8007F904: jal         0x8007B710
    // 0x8007F908: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8007B710(rdram, ctx);
        goto after_6;
    // 0x8007F908: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_6:
L_8007F90C:
    // 0x8007F90C: addiu       $t7, $zero, 0x33
    ctx->r15 = ADD32(0, 0X33);
    // 0x8007F910: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F914: sh          $t7, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r15;
    // 0x8007F918: b           L_8007F920
    // 0x8007F91C: nop

        goto L_8007F920;
    // 0x8007F91C: nop

L_8007F920:
    // 0x8007F920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007F924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007F928: jr          $ra
    // 0x8007F92C: nop

    return;
    // 0x8007F92C: nop

;}
RECOMP_FUNC void func_8007F930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F930: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007F934: bltz        $a1, L_8007F9CC
    if (SIGNED(ctx->r5) < 0) {
        // 0x8007F938: nop

            goto L_8007F9CC;
    }
    // 0x8007F938: nop

    // 0x8007F93C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8007F940: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8007F944: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007F948: nop

    // 0x8007F94C: slti        $at, $t6, 0x28
    ctx->r1 = SIGNED(ctx->r14) < 0X28 ? 1 : 0;
    // 0x8007F950: beq         $at, $zero, L_8007F9C0
    if (ctx->r1 == 0) {
        // 0x8007F954: nop

            goto L_8007F9C0;
    }
    // 0x8007F954: nop

L_8007F958:
    // 0x8007F958: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007F95C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007F960: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007F964: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007F968: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007F96C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007F970: lh          $t9, 0x2460($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2460);
    // 0x8007F974: nop

    // 0x8007F978: bltz        $t9, L_8007F9A8
    if (SIGNED(ctx->r25) < 0) {
        // 0x8007F97C: nop

            goto L_8007F9A8;
    }
    // 0x8007F97C: nop

    // 0x8007F980: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007F984: nop

    // 0x8007F988: bne         $t0, $a1, L_8007F998
    if (ctx->r8 != ctx->r5) {
        // 0x8007F98C: nop

            goto L_8007F998;
    }
    // 0x8007F98C: nop

    // 0x8007F990: b           L_8007F9C0
    // 0x8007F994: nop

        goto L_8007F9C0;
    // 0x8007F994: nop

L_8007F998:
    // 0x8007F998: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8007F99C: nop

    // 0x8007F9A0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8007F9A4: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_8007F9A8:
    // 0x8007F9A8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8007F9AC: nop

    // 0x8007F9B0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007F9B4: slti        $at, $t4, 0x28
    ctx->r1 = SIGNED(ctx->r12) < 0X28 ? 1 : 0;
    // 0x8007F9B8: bne         $at, $zero, L_8007F958
    if (ctx->r1 != 0) {
        // 0x8007F9BC: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8007F958;
    }
    // 0x8007F9BC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
L_8007F9C0:
    // 0x8007F9C0: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8007F9C4: b           L_8007FA5C
    // 0x8007F9C8: nop

        goto L_8007FA5C;
    // 0x8007F9C8: nop

L_8007F9CC:
    // 0x8007F9CC: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8007F9D0: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8007F9D4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8007F9D8: nop

    // 0x8007F9DC: bltz        $t5, L_8007FA48
    if (SIGNED(ctx->r13) < 0) {
        // 0x8007F9E0: nop

            goto L_8007FA48;
    }
    // 0x8007F9E0: nop

L_8007F9E4:
    // 0x8007F9E4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007F9E8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007F9EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007F9F0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007F9F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F9F8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007F9FC: lh          $t8, 0x2460($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2460);
    // 0x8007FA00: nop

    // 0x8007FA04: bltz        $t8, L_8007FA34
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007FA08: nop

            goto L_8007FA34;
    }
    // 0x8007FA08: nop

    // 0x8007FA0C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007FA10: nop

    // 0x8007FA14: bne         $t9, $a1, L_8007FA24
    if (ctx->r25 != ctx->r5) {
        // 0x8007FA18: nop

            goto L_8007FA24;
    }
    // 0x8007FA18: nop

    // 0x8007FA1C: b           L_8007FA48
    // 0x8007FA20: nop

        goto L_8007FA48;
    // 0x8007FA20: nop

L_8007FA24:
    // 0x8007FA24: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007FA28: nop

    // 0x8007FA2C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007FA30: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_8007FA34:
    // 0x8007FA34: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8007FA38: nop

    // 0x8007FA3C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8007FA40: bgez        $t3, L_8007F9E4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007FA44: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8007F9E4;
    }
    // 0x8007FA44: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_8007FA48:
    // 0x8007FA48: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8007FA4C: b           L_8007FA5C
    // 0x8007FA50: nop

        goto L_8007FA5C;
    // 0x8007FA50: nop

    // 0x8007FA54: b           L_8007FA5C
    // 0x8007FA58: nop

        goto L_8007FA5C;
    // 0x8007FA58: nop

L_8007FA5C:
    // 0x8007FA5C: jr          $ra
    // 0x8007FA60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007FA60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8007FA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FA64: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8007FA68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FA6C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007FA70: lh          $t6, 0x7130($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7130);
    // 0x8007FA74: nop

    // 0x8007FA78: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007FA7C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x8007FA80: beq         $at, $zero, L_800805A4
    if (ctx->r1 == 0) {
        // 0x8007FA84: nop

            goto L_800805A4;
    }
    // 0x8007FA84: nop

    // 0x8007FA88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007FA8C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FA90: addu        $at, $at, $t7
    gpr jr_addend_8007FA9C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007FA94: lw          $t7, -0xC88($at)
    ctx->r15 = ADD32(ctx->r1, -0XC88);
    // 0x8007FA98: nop

    // 0x8007FA9C: jr          $t7
    // 0x8007FAA0: nop

    switch (jr_addend_8007FA9C >> 2) {
        case 0: goto L_8007FAA4; break;
        case 1: goto L_8007FBC8; break;
        case 2: goto L_8007FC28; break;
        case 3: goto L_800805A4; break;
        case 4: goto L_800805A4; break;
        case 5: goto L_800805A4; break;
        case 6: goto L_800805A4; break;
        case 7: goto L_800805A4; break;
        case 8: goto L_800805A4; break;
        case 9: goto L_800805A4; break;
        case 10: goto L_8007FC9C; break;
        case 11: goto L_8007FD0C; break;
        case 12: goto L_8007FD6C; break;
        case 13: goto L_8007FE78; break;
        case 14: goto L_800805A4; break;
        case 15: goto L_800805A4; break;
        case 16: goto L_800805A4; break;
        case 17: goto L_800805A4; break;
        case 18: goto L_800805A4; break;
        case 19: goto L_800805A4; break;
        case 20: goto L_8007FEA0; break;
        case 21: goto L_8007FFE0; break;
        case 22: goto L_80080040; break;
        case 23: goto L_800805A4; break;
        case 24: goto L_800805A4; break;
        case 25: goto L_800805A4; break;
        case 26: goto L_800805A4; break;
        case 27: goto L_800805A4; break;
        case 28: goto L_800805A4; break;
        case 29: goto L_800805A4; break;
        case 30: goto L_800800B4; break;
        case 31: goto L_8008013C; break;
        case 32: goto L_80080184; break;
        case 33: goto L_800802AC; break;
        case 34: goto L_800805A4; break;
        case 35: goto L_800805A4; break;
        case 36: goto L_800805A4; break;
        case 37: goto L_800805A4; break;
        case 38: goto L_800805A4; break;
        case 39: goto L_800805A4; break;
        case 40: goto L_800802D4; break;
        case 41: goto L_800803F0; break;
        case 42: goto L_800805A4; break;
        case 43: goto L_800805A4; break;
        case 44: goto L_800805A4; break;
        case 45: goto L_800805A4; break;
        case 46: goto L_800805A4; break;
        case 47: goto L_800805A4; break;
        case 48: goto L_800805A4; break;
        case 49: goto L_800805A4; break;
        case 50: goto L_80080448; break;
        case 51: goto L_8008057C; break;
        default: switch_error(__func__, 0x8007FA9C, 0x800EF378);
    }
    // 0x8007FAA0: nop

L_8007FAA4:
    // 0x8007FAA4: jal         0x80031C34
    // 0x8007FAA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80031C34(rdram, ctx);
        goto after_0;
    // 0x8007FAA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8007FAAC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007FAB0: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007FAB4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007FAB8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007FABC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FAC0: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007FAC4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007FAC8: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007FACC: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8007FAD0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8007FAD4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FAD8: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007FADC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007FAE0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8007FAE4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FAE8: lwc1        $f4, -0xBB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XBB8);
    // 0x8007FAEC: nop

    // 0x8007FAF0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8007FAF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FAF8: lwc1        $f6, -0xBB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XBB4);
    // 0x8007FAFC: nop

    // 0x8007FB00: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8007FB04: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FB08: lwc1        $f8, -0xBB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XBB0);
    // 0x8007FB0C: nop

    // 0x8007FB10: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8007FB14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FB18: lwc1        $f10, -0xBAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XBAC);
    // 0x8007FB1C: nop

    // 0x8007FB20: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8007FB24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007FB28: nop

    // 0x8007FB2C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8007FB30: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8007FB34: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8007FB38: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8007FB3C: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
    // 0x8007FB40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007FB44: nop

    // 0x8007FB48: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8007FB4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007FB50: nop

    // 0x8007FB54: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8007FB58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007FB5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007FB60: nop

    // 0x8007FB64: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8007FB68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007FB6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007FB70: nop

    // 0x8007FB74: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8007FB78: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007FB7C: nop

    // 0x8007FB80: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8007FB84: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8007FB88: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8007FB8C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8007FB90: sh          $t4, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r12;
    // 0x8007FB94: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FB98: lwc1        $f16, -0xBA8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XBA8);
    // 0x8007FB9C: nop

    // 0x8007FBA0: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8007FBA4: jal         0x8007C54C
    // 0x8007FBA8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_1;
    // 0x8007FBA8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8007FBAC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007FBB0: lh          $t5, 0x7130($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7130);
    // 0x8007FBB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FBB8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8007FBBC: sh          $t6, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r14;
    // 0x8007FBC0: b           L_800805AC
    // 0x8007FBC4: nop

        goto L_800805AC;
    // 0x8007FBC4: nop

L_8007FBC8:
    // 0x8007FBC8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007FBCC: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8007FBD0: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x8007FBD4: nop

    // 0x8007FBD8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8007FBDC: sh          $t9, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r25;
    // 0x8007FBE0: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x8007FBE4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FBE8: sh          $t0, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r8;
    // 0x8007FBEC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8007FBF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FBF4: sh          $t1, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r9;
    // 0x8007FBF8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007FBFC: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007FC00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FC04: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8007FC08: sh          $t3, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r11;
    // 0x8007FC0C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007FC10: lh          $t4, 0x7130($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7130);
    // 0x8007FC14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FC18: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007FC1C: sh          $t5, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r13;
    // 0x8007FC20: b           L_800805AC
    // 0x8007FC24: nop

        goto L_800805AC;
    // 0x8007FC24: nop

L_8007FC28:
    // 0x8007FC28: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007FC2C: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007FC30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FC34: ori         $t8, $t6, 0x20
    ctx->r24 = ctx->r14 | 0X20;
    // 0x8007FC38: sh          $t8, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r24;
    // 0x8007FC3C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8007FC40: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8007FC44: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007FC48: nop

    // 0x8007FC4C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8007FC50: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8007FC54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007FC58: nop

    // 0x8007FC5C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8007FC60: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007FC64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007FC68: nop

    // 0x8007FC6C: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8007FC70: jal         0x8007C54C
    // 0x8007FC74: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_2;
    // 0x8007FC74: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8007FC78: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007FC7C: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007FC80: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FC84: ori         $t0, $t7, 0x8
    ctx->r8 = ctx->r15 | 0X8;
    // 0x8007FC88: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007FC8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FC90: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
    // 0x8007FC94: b           L_800805AC
    // 0x8007FC98: nop

        goto L_800805AC;
    // 0x8007FC98: nop

L_8007FC9C:
    // 0x8007FC9C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007FCA0: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007FCA4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007FCA8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8007FCAC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FCB0: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
    // 0x8007FCB4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8007FCB8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8007FCBC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8007FCC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007FCC4: nop

    // 0x8007FCC8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8007FCCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007FCD0: nop

    // 0x8007FCD4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8007FCD8: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8007FCDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007FCE0: nop

    // 0x8007FCE4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8007FCE8: jal         0x8007C54C
    // 0x8007FCEC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_3;
    // 0x8007FCEC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x8007FCF0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007FCF4: lh          $t4, 0x7130($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7130);
    // 0x8007FCF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FCFC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007FD00: sh          $t5, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r13;
    // 0x8007FD04: b           L_800805AC
    // 0x8007FD08: nop

        goto L_800805AC;
    // 0x8007FD08: nop

L_8007FD0C:
    // 0x8007FD0C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007FD10: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007FD14: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8007FD18: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8007FD1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FD20: sh          $t8, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r24;
    // 0x8007FD24: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8007FD28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FD2C: sh          $t9, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r25;
    // 0x8007FD30: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8007FD34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FD38: sh          $t7, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r15;
    // 0x8007FD3C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007FD40: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007FD44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FD48: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x8007FD4C: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007FD50: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007FD54: lh          $t2, 0x7130($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7130);
    // 0x8007FD58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FD5C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007FD60: sh          $t3, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r11;
    // 0x8007FD64: b           L_800805AC
    // 0x8007FD68: nop

        goto L_800805AC;
    // 0x8007FD68: nop

L_8007FD6C:
    // 0x8007FD6C: jal         0x80031C04
    // 0x8007FD70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80031C04(rdram, ctx);
        goto after_4;
    // 0x8007FD70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8007FD74: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007FD78: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8007FD7C: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x8007FD80: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007FD84: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8007FD88: sh          $t6, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r14;
    // 0x8007FD8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007FD90: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8007FD94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007FD98: nop

    // 0x8007FD9C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8007FDA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007FDA4: nop

    // 0x8007FDA8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8007FDAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007FDB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007FDB4: nop

    // 0x8007FDB8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8007FDBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007FDC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007FDC4: nop

    // 0x8007FDC8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8007FDCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007FDD0: nop

    // 0x8007FDD4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8007FDD8: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8007FDDC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8007FDE0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8007FDE4: sh          $t9, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r25;
    // 0x8007FDE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FDEC: lwc1        $f16, -0xBA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XBA4);
    // 0x8007FDF0: nop

    // 0x8007FDF4: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8007FDF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FDFC: lwc1        $f18, -0xBA0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XBA0);
    // 0x8007FE00: nop

    // 0x8007FE04: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x8007FE08: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FE0C: lwc1        $f4, -0xB9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XB9C);
    // 0x8007FE10: nop

    // 0x8007FE14: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x8007FE18: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FE1C: lwc1        $f6, -0xB98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XB98);
    // 0x8007FE20: nop

    // 0x8007FE24: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x8007FE28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007FE2C: nop

    // 0x8007FE30: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x8007FE34: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8007FE38: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8007FE3C: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8007FE40: sh          $t7, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r15;
    // 0x8007FE44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FE48: lwc1        $f10, -0xB94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XB94);
    // 0x8007FE4C: nop

    // 0x8007FE50: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x8007FE54: jal         0x8007C54C
    // 0x8007FE58: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_5;
    // 0x8007FE58: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_5:
    // 0x8007FE5C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007FE60: lh          $t0, 0x7130($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7130);
    // 0x8007FE64: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FE68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007FE6C: sh          $t1, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r9;
    // 0x8007FE70: b           L_800805AC
    // 0x8007FE74: nop

        goto L_800805AC;
    // 0x8007FE74: nop

L_8007FE78:
    // 0x8007FE78: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007FE7C: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x8007FE80: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x8007FE84: nop

    // 0x8007FE88: ori         $t5, $t3, 0x2
    ctx->r13 = ctx->r11 | 0X2;
    // 0x8007FE8C: sh          $t5, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r13;
    // 0x8007FE90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FE94: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
    // 0x8007FE98: b           L_800805AC
    // 0x8007FE9C: nop

        goto L_800805AC;
    // 0x8007FE9C: nop

L_8007FEA0:
    // 0x8007FEA0: jal         0x80031C34
    // 0x8007FEA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80031C34(rdram, ctx);
        goto after_6;
    // 0x8007FEA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8007FEA8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007FEAC: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007FEB0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007FEB4: and         $t4, $t6, $at
    ctx->r12 = ctx->r14 & ctx->r1;
    // 0x8007FEB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FEBC: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007FEC0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007FEC4: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007FEC8: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8007FECC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007FED0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FED4: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007FED8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007FEDC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8007FEE0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FEE4: lwc1        $f16, -0xB90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XB90);
    // 0x8007FEE8: nop

    // 0x8007FEEC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8007FEF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FEF4: lwc1        $f18, -0xB8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XB8C);
    // 0x8007FEF8: nop

    // 0x8007FEFC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8007FF00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FF04: lwc1        $f4, -0xB88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XB88);
    // 0x8007FF08: nop

    // 0x8007FF0C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007FF10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FF14: lwc1        $f6, -0xB84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XB84);
    // 0x8007FF18: nop

    // 0x8007FF1C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8007FF20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FF24: lwc1        $f8, -0xB80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XB80);
    // 0x8007FF28: nop

    // 0x8007FF2C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8007FF30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FF34: lwc1        $f10, -0xB7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XB7C);
    // 0x8007FF38: nop

    // 0x8007FF3C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8007FF40: lui         $at, 0x4202
    ctx->r1 = S32(0X4202 << 16);
    // 0x8007FF44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007FF48: nop

    // 0x8007FF4C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8007FF50: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8007FF54: sh          $t0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r8;
    // 0x8007FF58: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007FF5C: nop

    // 0x8007FF60: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8007FF64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007FF68: nop

    // 0x8007FF6C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8007FF70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007FF74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007FF78: nop

    // 0x8007FF7C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8007FF80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007FF84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007FF88: nop

    // 0x8007FF8C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8007FF90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007FF94: nop

    // 0x8007FF98: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8007FF9C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8007FFA0: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8007FFA4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8007FFA8: sh          $t1, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r9;
    // 0x8007FFAC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007FFB0: lwc1        $f16, -0xB78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XB78);
    // 0x8007FFB4: nop

    // 0x8007FFB8: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8007FFBC: jal         0x8007C54C
    // 0x8007FFC0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_7;
    // 0x8007FFC0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_7:
    // 0x8007FFC4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007FFC8: lh          $t3, 0x7130($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7130);
    // 0x8007FFCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007FFD0: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8007FFD4: sh          $t5, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r13;
    // 0x8007FFD8: b           L_800805AC
    // 0x8007FFDC: nop

        goto L_800805AC;
    // 0x8007FFDC: nop

L_8007FFE0:
    // 0x8007FFE0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007FFE4: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x8007FFE8: lhu         $t6, 0x4($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X4);
    // 0x8007FFEC: nop

    // 0x8007FFF0: ori         $t4, $t6, 0x1
    ctx->r12 = ctx->r14 | 0X1;
    // 0x8007FFF4: sh          $t4, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r12;
    // 0x8007FFF8: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x8007FFFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080000: sh          $t8, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r24;
    // 0x80080004: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80080008: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008000C: sh          $t9, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r25;
    // 0x80080010: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80080014: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x80080018: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008001C: ori         $t0, $t7, 0x4
    ctx->r8 = ctx->r15 | 0X4;
    // 0x80080020: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x80080024: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80080028: lh          $t1, 0x7130($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7130);
    // 0x8008002C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080030: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80080034: sh          $t3, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r11;
    // 0x80080038: b           L_800805AC
    // 0x8008003C: nop

        goto L_800805AC;
    // 0x8008003C: nop

L_80080040:
    // 0x80080040: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80080044: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x80080048: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008004C: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x80080050: sh          $t6, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r14;
    // 0x80080054: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80080058: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8008005C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80080060: nop

    // 0x80080064: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80080068: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008006C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80080070: nop

    // 0x80080074: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80080078: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8008007C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80080080: nop

    // 0x80080084: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80080088: jal         0x8007C54C
    // 0x8008008C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_8;
    // 0x8008008C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_8:
    // 0x80080090: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80080094: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x80080098: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008009C: ori         $t8, $t2, 0x8
    ctx->r24 = ctx->r10 | 0X8;
    // 0x800800A0: sh          $t8, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r24;
    // 0x800800A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800800A8: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
    // 0x800800AC: b           L_800805AC
    // 0x800800B0: nop

        goto L_800805AC;
    // 0x800800B0: nop

L_800800B4:
    // 0x800800B4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800800B8: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x800800BC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800800C0: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800800C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800800C8: sh          $t7, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r15;
    // 0x800800CC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800800D0: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x800800D4: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800800D8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800800DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800800E0: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x800800E4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800800E8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800800EC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800800F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800800F4: nop

    // 0x800800F8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800800FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80080100: nop

    // 0x80080104: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80080108: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8008010C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80080110: nop

    // 0x80080114: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x80080118: jal         0x8007C54C
    // 0x8008011C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_9;
    // 0x8008011C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_9:
    // 0x80080120: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80080124: lh          $t5, 0x7130($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7130);
    // 0x80080128: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008012C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80080130: sh          $t6, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r14;
    // 0x80080134: b           L_800805AC
    // 0x80080138: nop

        goto L_800805AC;
    // 0x80080138: nop

L_8008013C:
    // 0x8008013C: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80080140: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080144: sh          $t4, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r12;
    // 0x80080148: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x8008014C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080150: sh          $t2, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r10;
    // 0x80080154: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80080158: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8008015C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080160: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80080164: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x80080168: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8008016C: lh          $t7, 0x7130($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7130);
    // 0x80080170: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080174: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80080178: sh          $t0, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r8;
    // 0x8008017C: b           L_800805AC
    // 0x80080180: nop

        goto L_800805AC;
    // 0x80080180: nop

L_80080184:
    // 0x80080184: jal         0x80031C04
    // 0x80080188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80031C04(rdram, ctx);
        goto after_10;
    // 0x80080188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x8008018C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80080190: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80080194: lhu         $t3, 0x4($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X4);
    // 0x80080198: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008019C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800801A0: sh          $t5, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r13;
    // 0x800801A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800801A8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800801AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800801B0: nop

    // 0x800801B4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800801B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800801BC: nop

    // 0x800801C0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800801C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800801C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800801CC: nop

    // 0x800801D0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800801D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800801D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800801DC: nop

    // 0x800801E0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800801E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800801E8: nop

    // 0x800801EC: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800801F0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800801F4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800801F8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800801FC: sh          $t4, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r12;
    // 0x80080200: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080204: lwc1        $f16, -0xB74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XB74);
    // 0x80080208: nop

    // 0x8008020C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80080210: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080214: lwc1        $f18, -0xB70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XB70);
    // 0x80080218: nop

    // 0x8008021C: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x80080220: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080224: lwc1        $f4, -0xB6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XB6C);
    // 0x80080228: nop

    // 0x8008022C: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80080230: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080234: lwc1        $f6, -0xB68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XB68);
    // 0x80080238: nop

    // 0x8008023C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80080240: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080244: lwc1        $f8, -0xB64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XB64);
    // 0x80080248: nop

    // 0x8008024C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80080250: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080254: lwc1        $f10, -0xB60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XB60);
    // 0x80080258: nop

    // 0x8008025C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80080260: lui         $at, 0x4202
    ctx->r1 = S32(0X4202 << 16);
    // 0x80080264: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80080268: nop

    // 0x8008026C: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80080270: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80080274: sh          $t2, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r10;
    // 0x80080278: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008027C: lwc1        $f18, -0xB5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XB5C);
    // 0x80080280: nop

    // 0x80080284: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x80080288: jal         0x8007C54C
    // 0x8008028C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_11;
    // 0x8008028C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_11:
    // 0x80080290: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80080294: lh          $t8, 0x7130($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7130);
    // 0x80080298: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008029C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800802A0: sh          $t9, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r25;
    // 0x800802A4: b           L_800805AC
    // 0x800802A8: nop

        goto L_800805AC;
    // 0x800802A8: nop

L_800802AC:
    // 0x800802AC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800802B0: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800802B4: lhu         $t0, 0x4($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X4);
    // 0x800802B8: nop

    // 0x800802BC: ori         $t3, $t0, 0x2
    ctx->r11 = ctx->r8 | 0X2;
    // 0x800802C0: sh          $t3, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r11;
    // 0x800802C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800802C8: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
    // 0x800802CC: b           L_800805AC
    // 0x800802D0: nop

        goto L_800805AC;
    // 0x800802D0: nop

L_800802D4:
    // 0x800802D4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800802D8: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x800802DC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800802E0: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x800802E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800802E8: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x800802EC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800802F0: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x800802F4: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800802F8: and         $t4, $t6, $at
    ctx->r12 = ctx->r14 & ctx->r1;
    // 0x800802FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080300: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x80080304: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80080308: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8008030C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080310: lwc1        $f4, -0xB58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XB58);
    // 0x80080314: nop

    // 0x80080318: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8008031C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080320: lwc1        $f6, -0xB54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XB54);
    // 0x80080324: nop

    // 0x80080328: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8008032C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080330: lwc1        $f8, -0xB50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XB50);
    // 0x80080334: nop

    // 0x80080338: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8008033C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080340: lwc1        $f10, -0xB4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XB4C);
    // 0x80080344: nop

    // 0x80080348: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8008034C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80080350: nop

    // 0x80080354: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80080358: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8008035C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80080360: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80080364: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    // 0x80080368: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008036C: nop

    // 0x80080370: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80080374: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80080378: nop

    // 0x8008037C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80080380: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80080384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80080388: nop

    // 0x8008038C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80080390: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80080394: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80080398: nop

    // 0x8008039C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800803A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800803A4: nop

    // 0x800803A8: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800803AC: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800803B0: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800803B4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800803B8: sh          $t9, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r25;
    // 0x800803BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800803C0: lwc1        $f16, -0xB48($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XB48);
    // 0x800803C4: nop

    // 0x800803C8: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x800803CC: jal         0x8007C54C
    // 0x800803D0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_12;
    // 0x800803D0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_12:
    // 0x800803D4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800803D8: lh          $t0, 0x7130($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7130);
    // 0x800803DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800803E0: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x800803E4: sh          $t3, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r11;
    // 0x800803E8: b           L_800805AC
    // 0x800803EC: nop

        goto L_800805AC;
    // 0x800803EC: nop

L_800803F0:
    // 0x800803F0: jal         0x8007B710
    // 0x800803F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8007B710(rdram, ctx);
        goto after_13;
    // 0x800803F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x800803F8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800803FC: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80080400: lhu         $t5, 0x4($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X4);
    // 0x80080404: nop

    // 0x80080408: ori         $t1, $t5, 0x1
    ctx->r9 = ctx->r13 | 0X1;
    // 0x8008040C: sh          $t1, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r9;
    // 0x80080410: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80080414: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x80080418: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008041C: ori         $t4, $t6, 0x8
    ctx->r12 = ctx->r14 | 0X8;
    // 0x80080420: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x80080424: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80080428: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8008042C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080430: ori         $t8, $t2, 0x20
    ctx->r24 = ctx->r10 | 0X20;
    // 0x80080434: sh          $t8, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r24;
    // 0x80080438: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008043C: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
    // 0x80080440: b           L_800805AC
    // 0x80080444: nop

        goto L_800805AC;
    // 0x80080444: nop

L_80080448:
    // 0x80080448: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008044C: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80080450: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x80080454: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80080458: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8008045C: sh          $t3, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r11;
    // 0x80080460: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80080464: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x80080468: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8008046C: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x80080470: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080474: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x80080478: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8008047C: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x80080480: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80080484: and         $t6, $t7, $at
    ctx->r14 = ctx->r15 & ctx->r1;
    // 0x80080488: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008048C: sh          $t6, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r14;
    // 0x80080490: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80080494: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80080498: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008049C: nop

    // 0x800804A0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800804A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800804A8: nop

    // 0x800804AC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800804B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800804B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800804B8: nop

    // 0x800804BC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800804C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800804C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800804C8: nop

    // 0x800804CC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800804D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800804D4: nop

    // 0x800804D8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800804DC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800804E0: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800804E4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800804E8: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
    // 0x800804EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800804F0: lwc1        $f16, -0xB44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XB44);
    // 0x800804F4: nop

    // 0x800804F8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x800804FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080500: lwc1        $f18, -0xB40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XB40);
    // 0x80080504: nop

    // 0x80080508: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x8008050C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080510: lwc1        $f4, -0xB3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XB3C);
    // 0x80080514: nop

    // 0x80080518: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x8008051C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080520: lwc1        $f6, -0xB38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XB38);
    // 0x80080524: nop

    // 0x80080528: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x8008052C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80080530: nop

    // 0x80080534: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80080538: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8008053C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80080540: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80080544: sh          $t8, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r24;
    // 0x80080548: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008054C: lwc1        $f10, -0xB34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XB34);
    // 0x80080550: nop

    // 0x80080554: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80080558: jal         0x8007C54C
    // 0x8008055C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8007C54C(rdram, ctx);
        goto after_14;
    // 0x8008055C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_14:
    // 0x80080560: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80080564: lh          $t0, 0x7130($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7130);
    // 0x80080568: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008056C: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80080570: sh          $t3, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r11;
    // 0x80080574: b           L_800805AC
    // 0x80080578: nop

        goto L_800805AC;
    // 0x80080578: nop

L_8008057C:
    // 0x8008057C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80080580: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80080584: lhu         $t5, 0x4($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X4);
    // 0x80080588: nop

    // 0x8008058C: ori         $t1, $t5, 0x2
    ctx->r9 = ctx->r13 | 0X2;
    // 0x80080590: sh          $t1, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r9;
    // 0x80080594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080598: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
    // 0x8008059C: b           L_800805AC
    // 0x800805A0: nop

        goto L_800805AC;
    // 0x800805A0: nop

L_800805A4:
    // 0x800805A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800805A8: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
L_800805AC:
    // 0x800805AC: b           L_800805B4
    // 0x800805B0: nop

        goto L_800805B4;
    // 0x800805B0: nop

L_800805B4:
    // 0x800805B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800805B8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800805BC: jr          $ra
    // 0x800805C0: nop

    return;
    // 0x800805C0: nop

;}
RECOMP_FUNC void func_800805C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800805C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800805C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800805CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800805D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800805D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800805D8: jal         0x80080698
    // 0x800805DC: nop

    func_80080698(rdram, ctx);
        goto after_0;
    // 0x800805DC: nop

    after_0:
    // 0x800805E0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800805E4: nop

    // 0x800805E8: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800805EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800805F0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800805F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800805F8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800805FC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80080600: nop

    // 0x80080604: beq         $t9, $at, L_8008063C
    if (ctx->r25 == ctx->r1) {
        // 0x80080608: nop

            goto L_8008063C;
    }
    // 0x80080608: nop

    // 0x8008060C: beq         $t9, $zero, L_8008063C
    if (ctx->r25 == 0) {
        // 0x80080610: nop

            goto L_8008063C;
    }
    // 0x80080610: nop

L_80080614:
    // 0x80080614: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80080618: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008061C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80080620: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80080624: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80080628: nop

    // 0x8008062C: beq         $t2, $at, L_8008063C
    if (ctx->r10 == ctx->r1) {
        // 0x80080630: nop

            goto L_8008063C;
    }
    // 0x80080630: nop

    // 0x80080634: bne         $t2, $zero, L_80080614
    if (ctx->r10 != 0) {
        // 0x80080638: nop

            goto L_80080614;
    }
    // 0x80080638: nop

L_8008063C:
    // 0x8008063C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80080640: nop

    // 0x80080644: bltz        $t3, L_80080674
    if (SIGNED(ctx->r11) < 0) {
        // 0x80080648: nop

            goto L_80080674;
    }
    // 0x80080648: nop

L_8008064C:
    // 0x8008064C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80080650: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80080654: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80080658: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008065C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80080660: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80080664: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80080668: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008066C: bgez        $t7, L_8008064C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80080670: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8008064C;
    }
    // 0x80080670: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80080674:
    // 0x80080674: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80080678: nop

    // 0x8008067C: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x80080680: b           L_80080688
    // 0x80080684: nop

        goto L_80080688;
    // 0x80080684: nop

L_80080688:
    // 0x80080688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008068C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80080690: jr          $ra
    // 0x80080694: nop

    return;
    // 0x80080694: nop

;}
RECOMP_FUNC void func_80080698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080698: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008069C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800806A0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800806A4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800806A8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800806AC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800806B0: beq         $t7, $at, L_8008071C
    if (ctx->r15 == ctx->r1) {
        // 0x800806B4: nop

            goto L_8008071C;
    }
    // 0x800806B4: nop

    // 0x800806B8: beq         $t7, $zero, L_8008071C
    if (ctx->r15 == 0) {
        // 0x800806BC: nop

            goto L_8008071C;
    }
    // 0x800806BC: nop

L_800806C0:
    // 0x800806C0: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800806C4: nop

    // 0x800806C8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800806CC: nop

    // 0x800806D0: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800806D4: bne         $at, $zero, L_800806EC
    if (ctx->r1 != 0) {
        // 0x800806D8: nop

            goto L_800806EC;
    }
    // 0x800806D8: nop

    // 0x800806DC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800806E0: nop

    // 0x800806E4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800806E8: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_800806EC:
    // 0x800806EC: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800806F0: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800806F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800806F8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800806FC: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80080700: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x80080704: lbu         $t6, 0x0($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X0);
    // 0x80080708: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008070C: beq         $t6, $at, L_8008071C
    if (ctx->r14 == ctx->r1) {
        // 0x80080710: nop

            goto L_8008071C;
    }
    // 0x80080710: nop

    // 0x80080714: bne         $t6, $zero, L_800806C0
    if (ctx->r14 != 0) {
        // 0x80080718: nop

            goto L_800806C0;
    }
    // 0x80080718: nop

L_8008071C:
    // 0x8008071C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80080720: b           L_80080730
    // 0x80080724: nop

        goto L_80080730;
    // 0x80080724: nop

    // 0x80080728: b           L_80080730
    // 0x8008072C: nop

        goto L_80080730;
    // 0x8008072C: nop

L_80080730:
    // 0x80080730: jr          $ra
    // 0x80080734: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80080734: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80080738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080738: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008073C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80080740: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080744: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80080748:
    // 0x80080748: jal         0x800BC6EC
    // 0x8008074C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008074C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_0:
    // 0x80080750: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80080754: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80080758: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008075C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80080760: sw          $v0, -0x3808($at)
    MEM_W(-0X3808, ctx->r1) = ctx->r2;
    // 0x80080764: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80080768: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008076C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80080770: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80080774: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80080778: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008077C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80080780: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80080784: lw          $a2, 0x23F8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X23F8);
    // 0x80080788: jal         0x800BD1FC
    // 0x8008078C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x8008078C: nop

    after_1:
    // 0x80080790: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80080794: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80080798: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8008079C: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x800807A0: lw          $a1, -0x3808($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3808);
    // 0x800807A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800807A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800807AC: jal         0x800BD218
    // 0x800807B0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800807B0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_2:
    // 0x800807B4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800807B8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800807BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800807C0: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x800807C4: lw          $a0, -0x3808($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3808);
    // 0x800807C8: jal         0x800808A4
    // 0x800807CC: nop

    func_800808A4(rdram, ctx);
        goto after_3;
    // 0x800807CC: nop

    after_3:
    // 0x800807D0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800807D4: nop

    // 0x800807D8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800807DC: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x800807E0: bne         $at, $zero, L_80080748
    if (ctx->r1 != 0) {
        // 0x800807E4: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80080748;
    }
    // 0x800807E4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800807E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800807EC:
    // 0x800807EC: jal         0x800BC6EC
    // 0x800807F0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800807F0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_4:
    // 0x800807F4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800807F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800807FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80080800: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80080804: sw          $v0, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = ctx->r2;
    // 0x80080808: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008080C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080810: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80080814: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80080818: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008081C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80080820: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80080824: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80080828: lw          $a2, 0x241C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X241C);
    // 0x8008082C: jal         0x800BD1FC
    // 0x80080830: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x80080830: nop

    after_5:
    // 0x80080834: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80080838: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8008083C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80080840: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80080844: lw          $a1, -0x37E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X37E0);
    // 0x80080848: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80080850: jal         0x800BD218
    // 0x80080854: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_6;
    // 0x80080854: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_6:
    // 0x80080858: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008085C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80080860: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80080864: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80080868: lw          $a0, -0x37E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37E0);
    // 0x8008086C: jal         0x800808A4
    // 0x80080870: nop

    func_800808A4(rdram, ctx);
        goto after_7;
    // 0x80080870: nop

    after_7:
    // 0x80080874: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80080878: nop

    // 0x8008087C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80080880: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x80080884: bne         $at, $zero, L_800807EC
    if (ctx->r1 != 0) {
        // 0x80080888: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800807EC;
    }
    // 0x80080888: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8008088C: b           L_80080894
    // 0x80080890: nop

        goto L_80080894;
    // 0x80080890: nop

L_80080894:
    // 0x80080894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80080898: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008089C: jr          $ra
    // 0x800808A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800808A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800808A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800808A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800808A8: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800808AC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800808B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800808B4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800808B8: nop

    // 0x800808BC: beq         $t7, $at, L_800808F4
    if (ctx->r15 == ctx->r1) {
        // 0x800808C0: nop

            goto L_800808F4;
    }
    // 0x800808C0: nop

    // 0x800808C4: beq         $t7, $zero, L_800808F4
    if (ctx->r15 == 0) {
        // 0x800808C8: nop

            goto L_800808F4;
    }
    // 0x800808C8: nop

L_800808CC:
    // 0x800808CC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800808D0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800808D4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800808D8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800808DC: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800808E0: nop

    // 0x800808E4: beq         $t0, $at, L_800808F4
    if (ctx->r8 == ctx->r1) {
        // 0x800808E8: nop

            goto L_800808F4;
    }
    // 0x800808E8: nop

    // 0x800808EC: bne         $t0, $zero, L_800808CC
    if (ctx->r8 != 0) {
        // 0x800808F0: nop

            goto L_800808CC;
    }
    // 0x800808F0: nop

L_800808F4:
    // 0x800808F4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800808F8: nop

    // 0x800808FC: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80080900: b           L_80080908
    // 0x80080904: nop

        goto L_80080908;
    // 0x80080904: nop

L_80080908:
    // 0x80080908: jr          $ra
    // 0x8008090C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008090C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80080910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008091C: jal         0x800317E4
    // 0x80080920: nop

    func_800317E4(rdram, ctx);
        goto after_0;
    // 0x80080920: nop

    after_0:
    // 0x80080924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80080928: jal         0x800319B0
    // 0x8008092C: nop

    func_800319B0(rdram, ctx);
        goto after_1;
    // 0x8008092C: nop

    after_1:
    // 0x80080930: b           L_80080938
    // 0x80080934: nop

        goto L_80080938;
    // 0x80080934: nop

L_80080938:
    // 0x80080938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008093C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080940: jr          $ra
    // 0x80080944: nop

    return;
    // 0x80080944: nop

;}
RECOMP_FUNC void func_80080948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080948: b           L_80080964
    // 0x8008094C: nop

        goto L_80080964;
    // 0x8008094C: nop

    // 0x80080950: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80080954: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80080958: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8008095C: b           L_80080A78
    // 0x80080960: sh          $t7, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r15;
        goto L_80080A78;
    // 0x80080960: sh          $t7, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r15;
L_80080964:
    // 0x80080964: sh          $zero, 0x56($a0)
    MEM_H(0X56, ctx->r4) = 0;
    // 0x80080968: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008096C: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80080970: lwc1        $f4, 0x10($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80080974: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80080978: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008097C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80080980: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80080984: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80080988: nop

    // 0x8008098C: bc1f        L_800809AC
    if (!c1cs) {
        // 0x80080990: nop

            goto L_800809AC;
    }
    // 0x80080990: nop

    // 0x80080994: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80080998: lhu         $t0, 0xEEC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XEEC);
    // 0x8008099C: lhu         $t9, 0x56($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X56);
    // 0x800809A0: nop

    // 0x800809A4: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800809A8: sh          $t1, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r9;
L_800809AC:
    // 0x800809AC: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800809B0: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x800809B4: lwc1        $f10, 0x10($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800809B8: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800809BC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800809C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800809C4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800809C8: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x800809CC: nop

    // 0x800809D0: bc1f        L_800809F0
    if (!c1cs) {
        // 0x800809D4: nop

            goto L_800809F0;
    }
    // 0x800809D4: nop

    // 0x800809D8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800809DC: lhu         $t4, 0xEC0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XEC0);
    // 0x800809E0: lhu         $t3, 0x56($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X56);
    // 0x800809E4: nop

    // 0x800809E8: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800809EC: sh          $t5, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r13;
L_800809F0:
    // 0x800809F0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800809F4: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x800809F8: lwc1        $f4, 0x14($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800809FC: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80080A00: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80080A04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80080A08: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80080A0C: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80080A10: nop

    // 0x80080A14: bc1f        L_80080A34
    if (!c1cs) {
        // 0x80080A18: nop

            goto L_80080A34;
    }
    // 0x80080A18: nop

    // 0x80080A1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80080A20: lhu         $t8, 0xE68($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XE68);
    // 0x80080A24: lhu         $t7, 0x56($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X56);
    // 0x80080A28: nop

    // 0x80080A2C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80080A30: sh          $t9, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r25;
L_80080A34:
    // 0x80080A34: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80080A38: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80080A3C: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80080A40: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80080A44: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80080A48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80080A4C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80080A50: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80080A54: nop

    // 0x80080A58: bc1f        L_80080A78
    if (!c1cs) {
        // 0x80080A5C: nop

            goto L_80080A78;
    }
    // 0x80080A5C: nop

    // 0x80080A60: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80080A64: lhu         $t2, 0xE74($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XE74);
    // 0x80080A68: lhu         $t1, 0x56($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X56);
    // 0x80080A6C: nop

    // 0x80080A70: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80080A74: sh          $t3, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r11;
L_80080A78:
    // 0x80080A78: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80080A7C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80080A80: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80080A84: nop

    // 0x80080A88: sh          $t5, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r13;
    // 0x80080A8C: jr          $ra
    // 0x80080A90: nop

    return;
    // 0x80080A90: nop

    // 0x80080A94: jr          $ra
    // 0x80080A98: nop

    return;
    // 0x80080A98: nop

    // 0x80080A9C: nop

;}
RECOMP_FUNC void func_80080AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080AA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80080AA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80080AA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80080AAC: jal         0x800BC6EC
    // 0x80080AB0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80080AB0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x80080AB4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80080AB8: nop

    // 0x80080ABC: sw          $v0, 0x20C($t6)
    MEM_W(0X20C, ctx->r14) = ctx->r2;
    // 0x80080AC0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80080AC4: nop

    // 0x80080AC8: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x80080ACC: nop

    // 0x80080AD0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80080AD4: jal         0x80081FB8
    // 0x80080AD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80081FB8(rdram, ctx);
        goto after_1;
    // 0x80080AD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80080ADC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80080AE0: nop

    // 0x80080AE4: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80080AE8: jal         0x80081FB8
    // 0x80080AEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80081FB8(rdram, ctx);
        goto after_2;
    // 0x80080AEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80080AF0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80080AF4: nop

    // 0x80080AF8: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80080AFC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80080B04: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80080B08: nop

    // 0x80080B0C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80080B10: nop

    // 0x80080B14: swc1        $f4, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f4.u32l;
    // 0x80080B18: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B1C: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x80080B20: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80080B24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80080B28: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80080B2C: nop

    // 0x80080B30: swc1        $f6, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f6.u32l;
    // 0x80080B34: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B38: nop

    // 0x80080B3C: sh          $zero, 0xE($t7)
    MEM_H(0XE, ctx->r15) = 0;
    // 0x80080B40: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B44: nop

    // 0x80080B48: lhu         $a0, 0xE($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XE);
    // 0x80080B4C: jal         0x80081B00
    // 0x80080B50: nop

    func_80081B00(rdram, ctx);
        goto after_3;
    // 0x80080B50: nop

    after_3:
    // 0x80080B54: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B58: nop

    // 0x80080B5C: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x80080B60: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80080B68: sh          $t0, 0xC($t1)
    MEM_H(0XC, ctx->r9) = ctx->r8;
    // 0x80080B6C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B70: nop

    // 0x80080B74: sh          $zero, 0xA($t2)
    MEM_H(0XA, ctx->r10) = 0;
    // 0x80080B78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80080B7C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B80: nop

    // 0x80080B84: swc1        $f8, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f8.u32l;
    // 0x80080B88: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B8C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80080B90: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80080B94: lh          $t6, -0x498($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X498);
    // 0x80080B98: lh          $t5, 0x7280($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7280);
    // 0x80080B9C: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x80080BA0: lh          $a3, 0x7274($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7274);
    // 0x80080BA4: addiu       $a0, $t4, 0x16
    ctx->r4 = ADD32(ctx->r12, 0X16);
    // 0x80080BA8: addiu       $a1, $t4, 0x18
    ctx->r5 = ADD32(ctx->r12, 0X18);
    // 0x80080BAC: addiu       $a2, $t4, 0x1A
    ctx->r6 = ADD32(ctx->r12, 0X1A);
    // 0x80080BB0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80080BB4: jal         0x80081B90
    // 0x80080BB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_80081B90(rdram, ctx);
        goto after_4;
    // 0x80080BB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_4:
    // 0x80080BBC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80080BC0: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80080BC4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80080BC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80080BCC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80080BD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80080BD4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80080BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80080BDC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80080BE0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80080BE4: addiu       $a1, $t8, 0x4
    ctx->r5 = ADD32(ctx->r24, 0X4);
    // 0x80080BE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80080BEC: jal         0x800B202C
    // 0x80080BF0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_5;
    // 0x80080BF0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80080BF4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80080BF8: nop

    // 0x80080BFC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80080C00: nop

    // 0x80080C04: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // 0x80080C08: b           L_80080C18
    // 0x80080C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80080C18;
    // 0x80080C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80080C10: b           L_80080C18
    // 0x80080C14: nop

        goto L_80080C18;
    // 0x80080C14: nop

L_80080C18:
    // 0x80080C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80080C1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80080C20: jr          $ra
    // 0x80080C24: nop

    return;
    // 0x80080C24: nop

;}
RECOMP_FUNC void func_80080C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080C28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80080C2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80080C30: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80080C34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80080C38: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80080C3C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80080C40: nop

    // 0x80080C44: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x80080C48: nop

    // 0x80080C4C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80080C50: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080C54: nop

    // 0x80080C58: lhu         $t0, 0xE($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XE);
    // 0x80080C5C: nop

    // 0x80080C60: sltiu       $at, $t0, 0x7
    ctx->r1 = ctx->r8 < 0X7 ? 1 : 0;
    // 0x80080C64: beq         $at, $zero, L_800810F8
    if (ctx->r1 == 0) {
        // 0x80080C68: nop

            goto L_800810F8;
    }
    // 0x80080C68: nop

    // 0x80080C6C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80080C70: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080C74: addu        $at, $at, $t0
    gpr jr_addend_80080C80 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80080C78: lw          $t0, -0xB30($at)
    ctx->r8 = ADD32(ctx->r1, -0XB30);
    // 0x80080C7C: nop

    // 0x80080C80: jr          $t0
    // 0x80080C84: nop

    switch (jr_addend_80080C80 >> 2) {
        case 0: goto L_80080C88; break;
        case 1: goto L_80080D20; break;
        case 2: goto L_80080D78; break;
        case 3: goto L_80080DE0; break;
        case 4: goto L_80080F20; break;
        case 5: goto L_80080F90; break;
        case 6: goto L_80081000; break;
        default: switch_error(__func__, 0x80080C80, 0x800EF4D0);
    }
    // 0x80080C84: nop

L_80080C88:
    // 0x80080C88: jal         0x80016074
    // 0x80080C8C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80080C8C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80080C90: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80080C94: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80080C98: nop

    // 0x80080C9C: beq         $t1, $zero, L_80080CC4
    if (ctx->r9 == 0) {
        // 0x80080CA0: nop

            goto L_80080CC4;
    }
    // 0x80080CA0: nop

    // 0x80080CA4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80080CA8: nop

    // 0x80080CAC: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x80080CB0: nop

    // 0x80080CB4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80080CB8: bne         $t4, $zero, L_80080CC4
    if (ctx->r12 != 0) {
        // 0x80080CBC: nop

            goto L_80080CC4;
    }
    // 0x80080CBC: nop

    // 0x80080CC0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80080CC4:
    // 0x80080CC4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80080CC8: nop

    // 0x80080CCC: beq         $t5, $zero, L_80080D18
    if (ctx->r13 == 0) {
        // 0x80080CD0: nop

            goto L_80080D18;
    }
    // 0x80080CD0: nop

    // 0x80080CD4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080CD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80080CDC: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x80080CE0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80080CE4: nop

    // 0x80080CE8: lhu         $a0, 0xE($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XE);
    // 0x80080CEC: jal         0x80081B00
    // 0x80080CF0: nop

    func_80081B00(rdram, ctx);
        goto after_1;
    // 0x80080CF0: nop

    after_1:
    // 0x80080CF4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080CF8: nop

    // 0x80080CFC: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x80080D00: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D04: nop

    // 0x80080D08: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x80080D0C: nop

    // 0x80080D10: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80080D14: sh          $t2, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r10;
L_80080D18:
    // 0x80080D18: b           L_80081108
    // 0x80080D1C: nop

        goto L_80081108;
    // 0x80080D1C: nop

L_80080D20:
    // 0x80080D20: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D24: nop

    // 0x80080D28: lhu         $t4, 0xC($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC);
    // 0x80080D2C: nop

    // 0x80080D30: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80080D34: beq         $t5, $zero, L_80080D44
    if (ctx->r13 == 0) {
        // 0x80080D38: nop

            goto L_80080D44;
    }
    // 0x80080D38: nop

    // 0x80080D3C: b           L_80081108
    // 0x80080D40: nop

        goto L_80081108;
    // 0x80080D40: nop

L_80080D44:
    // 0x80080D44: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D48: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80080D4C: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x80080D50: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D54: nop

    // 0x80080D58: lhu         $a0, 0xE($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XE);
    // 0x80080D5C: jal         0x80081B00
    // 0x80080D60: nop

    func_80081B00(rdram, ctx);
        goto after_2;
    // 0x80080D60: nop

    after_2:
    // 0x80080D64: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D68: nop

    // 0x80080D6C: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x80080D70: b           L_80081108
    // 0x80080D74: nop

        goto L_80081108;
    // 0x80080D74: nop

L_80080D78:
    // 0x80080D78: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80080D7C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80080D80: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80080D84: nop

    // 0x80080D88: ori         $t0, $t2, 0x40
    ctx->r8 = ctx->r10 | 0X40;
    // 0x80080D8C: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x80080D90: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080D98: lh          $t4, 0x16($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X16);
    // 0x80080D9C: nop

    // 0x80080DA0: sh          $t4, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r12;
    // 0x80080DA4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80080DA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080DAC: lh          $t6, 0x18($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X18);
    // 0x80080DB0: nop

    // 0x80080DB4: sh          $t6, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r14;
    // 0x80080DB8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080DBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080DC0: lh          $t8, 0x1A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X1A);
    // 0x80080DC4: nop

    // 0x80080DC8: sh          $t8, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r24;
    // 0x80080DCC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80080DD0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80080DD4: sh          $t9, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r25;
    // 0x80080DD8: b           L_80081108
    // 0x80080DDC: nop

        goto L_80081108;
    // 0x80080DDC: nop

L_80080DE0:
    // 0x80080DE0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80080DE4: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80080DE8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80080DEC: nop

    // 0x80080DF0: andi        $t3, $t1, 0x40
    ctx->r11 = ctx->r9 & 0X40;
    // 0x80080DF4: beq         $t3, $zero, L_80080E04
    if (ctx->r11 == 0) {
        // 0x80080DF8: nop

            goto L_80080E04;
    }
    // 0x80080DF8: nop

    // 0x80080DFC: b           L_80081108
    // 0x80080E00: nop

        goto L_80081108;
    // 0x80080E00: nop

L_80080E04:
    // 0x80080E04: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80080E08: lh          $t4, 0x7132($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7132);
    // 0x80080E0C: nop

    // 0x80080E10: sh          $t4, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r12;
    // 0x80080E14: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80080E18: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80080E1C: lh          $t6, 0x16($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X16);
    // 0x80080E20: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80080E24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80080E28: lh          $t7, 0x18($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X18);
    // 0x80080E2C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80080E30: lh          $t0, 0x728C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X728C);
    // 0x80080E34: lh          $t2, 0x7280($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7280);
    // 0x80080E38: lh          $t9, 0x7274($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7274);
    // 0x80080E3C: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x80080E40: addiu       $a0, $t5, 0x1C
    ctx->r4 = ADD32(ctx->r13, 0X1C);
    // 0x80080E44: addiu       $a1, $t5, 0x1E
    ctx->r5 = ADD32(ctx->r13, 0X1E);
    // 0x80080E48: addiu       $a2, $t5, 0x20
    ctx->r6 = ADD32(ctx->r13, 0X20);
    // 0x80080E4C: addiu       $a3, $t5, 0x22
    ctx->r7 = ADD32(ctx->r13, 0X22);
    // 0x80080E50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80080E54: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80080E58: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80080E5C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80080E60: jal         0x80081CE8
    // 0x80080E64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80081CE8(rdram, ctx);
        goto after_3;
    // 0x80080E64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_3:
    // 0x80080E68: bgez        $v0, L_80080EBC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80080E6C: nop

            goto L_80080EBC;
    }
    // 0x80080E6C: nop

    // 0x80080E70: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80080E74: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80080E78: sh          $t1, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r9;
    // 0x80080E7C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80080E80: nop

    // 0x80080E84: lhu         $a0, 0xE($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0XE);
    // 0x80080E88: jal         0x80081B00
    // 0x80080E8C: nop

    func_80081B00(rdram, ctx);
        goto after_4;
    // 0x80080E8C: nop

    after_4:
    // 0x80080E90: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80080E94: nop

    // 0x80080E98: sh          $v0, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r2;
    // 0x80080E9C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EA0: nop

    // 0x80080EA4: lhu         $t7, 0xC($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0XC);
    // 0x80080EA8: nop

    // 0x80080EAC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80080EB0: sh          $t8, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r24;
    // 0x80080EB4: b           L_80081108
    // 0x80080EB8: nop

        goto L_80081108;
    // 0x80080EB8: nop

L_80080EBC:
    // 0x80080EBC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EC0: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x80080EC4: lh          $t2, 0x1A($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X1A);
    // 0x80080EC8: nop

    // 0x80080ECC: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80080ED0: beq         $at, $zero, L_80080EE8
    if (ctx->r1 == 0) {
        // 0x80080ED4: nop

            goto L_80080EE8;
    }
    // 0x80080ED4: nop

    // 0x80080ED8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80080EE0: b           L_80080EF4
    // 0x80080EE4: sh          $t1, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r9;
        goto L_80080EF4;
    // 0x80080EE4: sh          $t1, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r9;
L_80080EE8:
    // 0x80080EE8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EEC: nop

    // 0x80080EF0: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
L_80080EF4:
    // 0x80080EF4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EF8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80080EFC: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x80080F00: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F04: nop

    // 0x80080F08: lhu         $t5, 0xC($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0XC);
    // 0x80080F0C: nop

    // 0x80080F10: ori         $t9, $t5, 0x2
    ctx->r25 = ctx->r13 | 0X2;
    // 0x80080F14: sh          $t9, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r25;
    // 0x80080F18: b           L_80081108
    // 0x80080F1C: nop

        goto L_80081108;
    // 0x80080F1C: nop

L_80080F20:
    // 0x80080F20: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F24: nop

    // 0x80080F28: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x80080F2C: nop

    // 0x80080F30: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80080F34: beq         $t1, $zero, L_80080F44
    if (ctx->r9 == 0) {
        // 0x80080F38: nop

            goto L_80080F44;
    }
    // 0x80080F38: nop

    // 0x80080F3C: b           L_80081108
    // 0x80080F40: nop

        goto L_80081108;
    // 0x80080F40: nop

L_80080F44:
    // 0x80080F44: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F48: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80080F4C: sh          $t3, 0xE($t4)
    MEM_H(0XE, ctx->r12) = ctx->r11;
    // 0x80080F50: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F54: nop

    // 0x80080F58: lhu         $a0, 0xE($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XE);
    // 0x80080F5C: jal         0x80081B00
    // 0x80080F60: nop

    func_80081B00(rdram, ctx);
        goto after_5;
    // 0x80080F60: nop

    after_5:
    // 0x80080F64: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F68: nop

    // 0x80080F6C: sh          $v0, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r2;
    // 0x80080F70: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F74: nop

    // 0x80080F78: lhu         $t9, 0xC($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0XC);
    // 0x80080F7C: nop

    // 0x80080F80: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x80080F84: sh          $t8, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r24;
    // 0x80080F88: b           L_80081108
    // 0x80080F8C: nop

        goto L_80081108;
    // 0x80080F8C: nop

L_80080F90:
    // 0x80080F90: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F94: nop

    // 0x80080F98: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x80080F9C: nop

    // 0x80080FA0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80080FA4: beq         $t1, $zero, L_80080FB4
    if (ctx->r9 == 0) {
        // 0x80080FA8: nop

            goto L_80080FB4;
    }
    // 0x80080FA8: nop

    // 0x80080FAC: b           L_80081108
    // 0x80080FB0: nop

        goto L_80081108;
    // 0x80080FB0: nop

L_80080FB4:
    // 0x80080FB4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FB8: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80080FBC: sh          $t3, 0xE($t4)
    MEM_H(0XE, ctx->r12) = ctx->r11;
    // 0x80080FC0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FC4: nop

    // 0x80080FC8: lhu         $a0, 0xE($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XE);
    // 0x80080FCC: jal         0x80081B00
    // 0x80080FD0: nop

    func_80081B00(rdram, ctx);
        goto after_6;
    // 0x80080FD0: nop

    after_6:
    // 0x80080FD4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FD8: nop

    // 0x80080FDC: sh          $v0, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r2;
    // 0x80080FE0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FE4: nop

    // 0x80080FE8: lhu         $t8, 0xC($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0XC);
    // 0x80080FEC: nop

    // 0x80080FF0: ori         $t5, $t8, 0x1
    ctx->r13 = ctx->r24 | 0X1;
    // 0x80080FF4: sh          $t5, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r13;
    // 0x80080FF8: b           L_80081108
    // 0x80080FFC: nop

        goto L_80081108;
    // 0x80080FFC: nop

L_80081000:
    // 0x80081000: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80081004: nop

    // 0x80081008: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x8008100C: nop

    // 0x80081010: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80081014: beq         $t1, $zero, L_80081024
    if (ctx->r9 == 0) {
        // 0x80081018: nop

            goto L_80081024;
    }
    // 0x80081018: nop

    // 0x8008101C: b           L_80081108
    // 0x80081020: nop

        goto L_80081108;
    // 0x80081020: nop

L_80081024:
    // 0x80081024: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80081028: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008102C: lh          $t4, 0x22($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X22);
    // 0x80081030: nop

    // 0x80081034: bne         $t4, $at, L_800810BC
    if (ctx->r12 != ctx->r1) {
        // 0x80081038: nop

            goto L_800810BC;
    }
    // 0x80081038: nop

    // 0x8008103C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80081040: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80081044: lh          $t7, 0x1C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1C);
    // 0x80081048: nop

    // 0x8008104C: sh          $t7, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r15;
    // 0x80081050: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80081054: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80081058: lh          $t5, 0x1E($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X1E);
    // 0x8008105C: nop

    // 0x80081060: sh          $t5, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r13;
    // 0x80081064: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80081068: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008106C: lh          $t2, 0x20($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X20);
    // 0x80081070: nop

    // 0x80081074: sh          $t2, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r10;
    // 0x80081078: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008107C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081080: sw          $t0, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r8;
    // 0x80081084: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80081088: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008108C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80081090: swc1        $f4, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f4.u32l;
    // 0x80081094: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80081098: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8008109C: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
    // 0x800810A0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800810A4: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x800810A8: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x800810AC: nop

    // 0x800810B0: ori         $t6, $t4, 0x2
    ctx->r14 = ctx->r12 | 0X2;
    // 0x800810B4: b           L_800810E4
    // 0x800810B8: sh          $t6, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r14;
        goto L_800810E4;
    // 0x800810B8: sh          $t6, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r14;
L_800810BC:
    // 0x800810BC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800810C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800810C4: lh          $t8, 0x22($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X22);
    // 0x800810C8: nop

    // 0x800810CC: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x800810D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800810D4: lh          $t5, 0x7254($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7254);
    // 0x800810D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800810DC: ori         $t9, $t5, 0x8000
    ctx->r25 = ctx->r13 | 0X8000;
    // 0x800810E0: sh          $t9, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r25;
L_800810E4:
    // 0x800810E4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800810E8: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800810EC: sh          $t2, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r10;
    // 0x800810F0: b           L_80081108
    // 0x800810F4: nop

        goto L_80081108;
    // 0x800810F4: nop

L_800810F8:
    // 0x800810F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800810FC: sh          $zero, -0x498($at)
    MEM_H(-0X498, ctx->r1) = 0;
    // 0x80081100: b           L_80081108
    // 0x80081104: nop

        goto L_80081108;
    // 0x80081104: nop

L_80081108:
    // 0x80081108: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008110C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80081110: lhu         $t4, 0xE($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0XE);
    // 0x80081114: nop

    // 0x80081118: beq         $t4, $at, L_8008112C
    if (ctx->r12 == ctx->r1) {
        // 0x8008111C: nop

            goto L_8008112C;
    }
    // 0x8008111C: nop

    // 0x80081120: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80081124: jal         0x80081204
    // 0x80081128: nop

    func_80081204(rdram, ctx);
        goto after_7;
    // 0x80081128: nop

    after_7:
L_8008112C:
    // 0x8008112C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80081130: nop

    // 0x80081134: lhu         $t3, 0xC($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0XC);
    // 0x80081138: nop

    // 0x8008113C: andi        $t7, $t3, 0x1
    ctx->r15 = ctx->r11 & 0X1;
    // 0x80081140: beq         $t7, $zero, L_80081174
    if (ctx->r15 == 0) {
        // 0x80081144: nop

            goto L_80081174;
    }
    // 0x80081144: nop

    // 0x80081148: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8008114C: jal         0x80081260
    // 0x80081150: nop

    func_80081260(rdram, ctx);
        goto after_8;
    // 0x80081150: nop

    after_8:
    // 0x80081154: bgez        $v0, L_80081174
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80081158: nop

            goto L_80081174;
    }
    // 0x80081158: nop

    // 0x8008115C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80081160: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80081164: lhu         $t5, 0xC($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0XC);
    // 0x80081168: nop

    // 0x8008116C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80081170: sh          $t9, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r25;
L_80081174:
    // 0x80081174: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80081178: nop

    // 0x8008117C: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x80081180: nop

    // 0x80081184: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80081188: beq         $t1, $zero, L_800811BC
    if (ctx->r9 == 0) {
        // 0x8008118C: nop

            goto L_800811BC;
    }
    // 0x8008118C: nop

    // 0x80081190: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80081194: jal         0x80081554
    // 0x80081198: nop

    func_80081554(rdram, ctx);
        goto after_9;
    // 0x80081198: nop

    after_9:
    // 0x8008119C: bgez        $v0, L_800811BC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800811A0: nop

            goto L_800811BC;
    }
    // 0x800811A0: nop

    // 0x800811A4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800811A8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800811AC: lhu         $t6, 0xC($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0XC);
    // 0x800811B0: nop

    // 0x800811B4: and         $t3, $t6, $at
    ctx->r11 = ctx->r14 & ctx->r1;
    // 0x800811B8: sh          $t3, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r11;
L_800811BC:
    // 0x800811BC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800811C0: nop

    // 0x800811C4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800811C8: jal         0x80081A60
    // 0x800811CC: nop

    func_80081A60(rdram, ctx);
        goto after_10;
    // 0x800811CC: nop

    after_10:
    // 0x800811D0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800811D4: nop

    // 0x800811D8: lw          $a0, 0x4($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4);
    // 0x800811DC: jal         0x80081A60
    // 0x800811E0: nop

    func_80081A60(rdram, ctx);
        goto after_11;
    // 0x800811E0: nop

    after_11:
    // 0x800811E4: b           L_800811F4
    // 0x800811E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800811F4;
    // 0x800811E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800811EC: b           L_800811F4
    // 0x800811F0: nop

        goto L_800811F4;
    // 0x800811F0: nop

L_800811F4:
    // 0x800811F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800811F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800811FC: jr          $ra
    // 0x80081200: nop

    return;
    // 0x80081200: nop

;}
RECOMP_FUNC void func_80081204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008120C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80081210: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80081214: nop

    // 0x80081218: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008121C: nop

    // 0x80081220: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80081224: jal         0x800B2748
    // 0x80081228: addiu       $a1, $t7, 0x4
    ctx->r5 = ADD32(ctx->r15, 0X4);
    func_800B2748(rdram, ctx);
        goto after_0;
    // 0x80081228: addiu       $a1, $t7, 0x4
    ctx->r5 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x8008122C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80081230: nop

    // 0x80081234: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80081238: nop

    // 0x8008123C: sh          $v0, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r2;
    // 0x80081240: b           L_80081250
    // 0x80081244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081250;
    // 0x80081244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80081248: b           L_80081250
    // 0x8008124C: nop

        goto L_80081250;
    // 0x8008124C: nop

L_80081250:
    // 0x80081250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081258: jr          $ra
    // 0x8008125C: nop

    return;
    // 0x8008125C: nop

;}
RECOMP_FUNC void func_80081260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081260: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80081264: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80081268: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008126C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80081270: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081274: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80081278: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008127C: nop

    // 0x80081280: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80081284: nop

    // 0x80081288: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x8008128C: nop

    // 0x80081290: blez        $t9, L_80081380
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80081294: nop

            goto L_80081380;
    }
    // 0x80081294: nop

    // 0x80081298: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008129C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800812A0: lhu         $t1, 0xA($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XA);
    // 0x800812A4: nop

    // 0x800812A8: andi        $t2, $t1, 0xE
    ctx->r10 = ctx->r9 & 0XE;
    // 0x800812AC: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800812B0: beq         $t3, $at, L_80081380
    if (ctx->r11 == ctx->r1) {
        // 0x800812B4: nop

            goto L_80081380;
    }
    // 0x800812B4: nop

    // 0x800812B8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800812BC: nop

    // 0x800812C0: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800812C4: nop

    // 0x800812C8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800812CC: jal         0x800B2748
    // 0x800812D0: addiu       $a1, $t5, 0x4
    ctx->r5 = ADD32(ctx->r13, 0X4);
    func_800B2748(rdram, ctx);
        goto after_0;
    // 0x800812D0: addiu       $a1, $t5, 0x4
    ctx->r5 = ADD32(ctx->r13, 0X4);
    after_0:
    // 0x800812D4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800812D8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800812DC: nop

    // 0x800812E0: blez        $t6, L_80081380
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800812E4: nop

            goto L_80081380;
    }
    // 0x800812E4: nop

    // 0x800812E8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800812EC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800812F0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800812F4: nop

    // 0x800812F8: sh          $t7, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r15;
    // 0x800812FC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80081300: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80081304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081308: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x8008130C: jal         0x800B3434
    // 0x80081310: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B3434(rdram, ctx);
        goto after_1;
    // 0x80081310: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80081314: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80081318: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x8008131C: nop

    // 0x80081320: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x80081324: beq         $t2, $zero, L_8008134C
    if (ctx->r10 == 0) {
        // 0x80081328: nop

            goto L_8008134C;
    }
    // 0x80081328: nop

    // 0x8008132C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80081330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081334: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x80081338: jal         0x800B32E4
    // 0x8008133C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B32E4(rdram, ctx);
        goto after_2;
    // 0x8008133C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x80081340: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80081344: jal         0x800B9000
    // 0x80081348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x80081348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8008134C:
    // 0x8008134C: lhu         $t4, 0x36($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X36);
    // 0x80081350: nop

    // 0x80081354: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80081358: beq         $t5, $zero, L_80081380
    if (ctx->r13 == 0) {
        // 0x8008135C: nop

            goto L_80081380;
    }
    // 0x8008135C: nop

    // 0x80081360: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80081364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80081368: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8008136C: jal         0x800B32E4
    // 0x80081370: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B32E4(rdram, ctx);
        goto after_4;
    // 0x80081370: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80081374: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80081378: jal         0x800B9000
    // 0x8008137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x8008137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80081380:
    // 0x80081380: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80081384: nop

    // 0x80081388: bne         $t8, $zero, L_80081398
    if (ctx->r24 != 0) {
        // 0x8008138C: nop

            goto L_80081398;
    }
    // 0x8008138C: nop

    // 0x80081390: b           L_80081544
    // 0x80081394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081544;
    // 0x80081394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081398:
    // 0x80081398: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008139C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800813A0: lhu         $t9, 0x8($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X8);
    // 0x800813A4: lhu         $t2, 0xE($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0XE);
    // 0x800813A8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800813AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800813B0: lh          $t1, 0x2830($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2830);
    // 0x800813B4: nop

    // 0x800813B8: bne         $t1, $t2, L_800814FC
    if (ctx->r9 != ctx->r10) {
        // 0x800813BC: nop

            goto L_800814FC;
    }
    // 0x800813BC: nop

    // 0x800813C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800813C4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800813C8: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x800813CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800813D0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800813D4: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x800813D8: lh          $a3, 0x2832($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X2832);
    // 0x800813DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800813E0: or          $t6, $a3, $at
    ctx->r14 = ctx->r7 | ctx->r1;
    // 0x800813E4: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800813E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800813EC: jal         0x800B3230
    // 0x800813F0: addiu       $a0, $t3, 0xA
    ctx->r4 = ADD32(ctx->r11, 0XA);
    func_800B3230(rdram, ctx);
        goto after_6;
    // 0x800813F0: addiu       $a0, $t3, 0xA
    ctx->r4 = ADD32(ctx->r11, 0XA);
    after_6:
    // 0x800813F4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800813F8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800813FC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80081400: lhu         $t0, 0x8($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X8);
    // 0x80081404: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80081408: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8008140C: lwc1        $f4, 0xCC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x80081410: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80081414: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80081418: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8008141C: lh          $a3, 0x42($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X42);
    // 0x80081420: lh          $a2, 0x2832($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X2832);
    // 0x80081424: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80081428: lwc1        $f6, 0xD0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8008142C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80081430: or          $t1, $a2, $at
    ctx->r9 = ctx->r6 | ctx->r1;
    // 0x80081434: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80081438: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008143C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80081440: addiu       $a1, $t9, 0x4
    ctx->r5 = ADD32(ctx->r25, 0X4);
    // 0x80081444: jal         0x800B202C
    // 0x80081448: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_7;
    // 0x80081448: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8008144C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80081450: nop

    // 0x80081454: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80081458: nop

    // 0x8008145C: sh          $v0, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r2;
    // 0x80081460: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80081464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081468: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8008146C: jal         0x800B3434
    // 0x80081470: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B3434(rdram, ctx);
        goto after_8;
    // 0x80081470: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_8:
    // 0x80081474: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80081478: lhu         $t8, 0x36($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X36);
    // 0x8008147C: nop

    // 0x80081480: andi        $t0, $t8, 0x4000
    ctx->r8 = ctx->r24 & 0X4000;
    // 0x80081484: beq         $t0, $zero, L_800814AC
    if (ctx->r8 == 0) {
        // 0x80081488: nop

            goto L_800814AC;
    }
    // 0x80081488: nop

    // 0x8008148C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80081490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081494: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80081498: jal         0x800B32E4
    // 0x8008149C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B32E4(rdram, ctx);
        goto after_9;
    // 0x8008149C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_9:
    // 0x800814A0: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x800814A4: jal         0x800B9000
    // 0x800814A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_10;
    // 0x800814A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_800814AC:
    // 0x800814AC: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x800814B0: nop

    // 0x800814B4: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x800814B8: beq         $t2, $zero, L_800814E0
    if (ctx->r10 == 0) {
        // 0x800814BC: nop

            goto L_800814E0;
    }
    // 0x800814BC: nop

    // 0x800814C0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800814C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800814C8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800814CC: jal         0x800B32E4
    // 0x800814D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B32E4(rdram, ctx);
        goto after_11;
    // 0x800814D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_11:
    // 0x800814D4: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x800814D8: jal         0x800B9000
    // 0x800814DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_12;
    // 0x800814DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_800814E0:
    // 0x800814E0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800814E4: nop

    // 0x800814E8: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x800814EC: nop

    // 0x800814F0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800814F4: b           L_80081534
    // 0x800814F8: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
        goto L_80081534;
    // 0x800814F8: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
L_800814FC:
    // 0x800814FC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80081500: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081504: lhu         $t8, 0x8($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X8);
    // 0x80081508: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008150C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80081510: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80081514: lh          $t7, 0x2830($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2830);
    // 0x80081518: nop

    // 0x8008151C: bne         $t7, $at, L_8008152C
    if (ctx->r15 != ctx->r1) {
        // 0x80081520: nop

            goto L_8008152C;
    }
    // 0x80081520: nop

    // 0x80081524: b           L_80081544
    // 0x80081528: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80081544;
    // 0x80081528: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_8008152C:
    // 0x8008152C: b           L_80081544
    // 0x80081530: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081544;
    // 0x80081530: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80081534:
    // 0x80081534: b           L_80081544
    // 0x80081538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081544;
    // 0x80081538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008153C: b           L_80081544
    // 0x80081540: nop

        goto L_80081544;
    // 0x80081540: nop

L_80081544:
    // 0x80081544: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80081548: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008154C: jr          $ra
    // 0x80081550: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80081550: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80081554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081554: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80081558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008155C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80081560: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80081564: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80081568: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008156C: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80081570: nop

    // 0x80081574: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80081578: swc1        $f8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f8.u32l;
    // 0x8008157C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80081580: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081584: lwc1        $f16, -0xB14($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XB14);
    // 0x80081588: lwc1        $f10, 0x10($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8008158C: nop

    // 0x80081590: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80081594: nop

    // 0x80081598: bc1f        L_800815B8
    if (!c1cs) {
        // 0x8008159C: nop

            goto L_800815B8;
    }
    // 0x8008159C: nop

    // 0x800815A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800815A4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800815A8: nop

    // 0x800815AC: swc1        $f18, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f18.u32l;
    // 0x800815B0: b           L_80081A50
    // 0x800815B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081A50;
    // 0x800815B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800815B8:
    // 0x800815B8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800815BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800815C0: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800815C4: nop

    // 0x800815C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800815CC: nop

    // 0x800815D0: bc1f        L_800816A0
    if (!c1cs) {
        // 0x800815D4: nop

            goto L_800816A0;
    }
    // 0x800815D4: nop

    // 0x800815D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800815DC: nop

    // 0x800815E0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800815E4: nop

    // 0x800815E8: bc1f        L_800816A0
    if (!c1cs) {
        // 0x800815EC: nop

            goto L_800816A0;
    }
    // 0x800815EC: nop

    // 0x800815F0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800815F4: nop

    // 0x800815F8: lhu         $t1, 0x14($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X14);
    // 0x800815FC: nop

    // 0x80081600: bne         $t1, $zero, L_80081618
    if (ctx->r9 != 0) {
        // 0x80081604: nop

            goto L_80081618;
    }
    // 0x80081604: nop

    // 0x80081608: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008160C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80081610: b           L_80081628
    // 0x80081614: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
        goto L_80081628;
    // 0x80081614: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
L_80081618:
    // 0x80081618: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8008161C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081620: nop

    // 0x80081624: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
L_80081628:
    // 0x80081628: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008162C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80081630: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80081634: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80081638: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008163C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80081640: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80081644: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081648: lwc1        $f11, -0xB10($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XB10);
    // 0x8008164C: lwc1        $f10, -0xB0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XB0C);
    // 0x80081650: nop

    // 0x80081654: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80081658: jal         0x800C3070
    // 0x8008165C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_0;
    // 0x8008165C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_0:
    // 0x80081660: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80081664: nop

    // 0x80081668: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8008166C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80081670: nop

    // 0x80081674: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80081678: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008167C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80081680: nop

    // 0x80081684: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80081688: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8008168C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80081690: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80081694: nop

    // 0x80081698: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008169C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_800816A0:
    // 0x800816A0: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800816A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800816A8: lwc1        $f16, 0x10($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800816AC: nop

    // 0x800816B0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800816B4: nop

    // 0x800816B8: bc1f        L_800817C4
    if (!c1cs) {
        // 0x800816BC: nop

            goto L_800817C4;
    }
    // 0x800816BC: nop

    // 0x800816C0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800816C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800816C8: nop

    // 0x800816CC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800816D0: nop

    // 0x800816D4: bc1f        L_800817C4
    if (!c1cs) {
        // 0x800816D8: nop

            goto L_800817C4;
    }
    // 0x800816D8: nop

    // 0x800816DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800816E0: lw          $t6, 0x2890($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2890);
    // 0x800816E4: nop

    // 0x800816E8: bne         $t6, $zero, L_80081774
    if (ctx->r14 != 0) {
        // 0x800816EC: nop

            goto L_80081774;
    }
    // 0x800816EC: nop

    // 0x800816F0: jal         0x800B9000
    // 0x800816F4: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x800816F4: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_1:
    // 0x800816F8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800816FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081700: nop

    // 0x80081704: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80081708: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8008170C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80081710: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80081714: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x80081718: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008171C: addiu       $t8, $zero, 0xA8
    ctx->r24 = ADD32(0, 0XA8);
    // 0x80081720: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80081724: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80081728: nop

    // 0x8008172C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80081730: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80081734: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80081738: nop

    // 0x8008173C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80081740: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80081744: nop

    // 0x80081748: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8008174C: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x80081750: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80081754: jal         0x80016620
    // 0x80081758: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_2;
    // 0x80081758: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8008175C: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80081760: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80081764: sw          $t0, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r8;
    // 0x80081768: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008176C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081770: sw          $t1, 0x2890($at)
    MEM_W(0X2890, ctx->r1) = ctx->r9;
L_80081774:
    // 0x80081774: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80081778: nop

    // 0x8008177C: lhu         $t3, 0x14($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X14);
    // 0x80081780: nop

    // 0x80081784: bne         $t3, $zero, L_800817AC
    if (ctx->r11 != 0) {
        // 0x80081788: nop

            goto L_800817AC;
    }
    // 0x80081788: nop

    // 0x8008178C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80081790: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80081794: lwc1        $f16, 0x10($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80081798: nop

    // 0x8008179C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800817A0: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800817A4: b           L_800817C4
    // 0x800817A8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
        goto L_800817C4;
    // 0x800817A8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_800817AC:
    // 0x800817AC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800817B0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800817B4: lwc1        $f10, 0x10($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800817B8: nop

    // 0x800817BC: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800817C0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
L_800817C4:
    // 0x800817C4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800817C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800817CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800817D0: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800817D4: nop

    // 0x800817D8: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x800817DC: nop

    // 0x800817E0: bc1f        L_800818F0
    if (!c1cs) {
        // 0x800817E4: nop

            goto L_800818F0;
    }
    // 0x800817E4: nop

    // 0x800817E8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800817EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800817F0: nop

    // 0x800817F4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800817F8: nop

    // 0x800817FC: bc1f        L_800818F0
    if (!c1cs) {
        // 0x80081800: nop

            goto L_800818F0;
    }
    // 0x80081800: nop

    // 0x80081804: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081808: lw          $t7, 0x2890($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2890);
    // 0x8008180C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80081810: bne         $t7, $at, L_80081898
    if (ctx->r15 != ctx->r1) {
        // 0x80081814: nop

            goto L_80081898;
    }
    // 0x80081814: nop

    // 0x80081818: jal         0x800B9000
    // 0x8008181C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8008181C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_3:
    // 0x80081820: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80081824: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80081828: nop

    // 0x8008182C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80081830: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80081834: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80081838: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8008183C: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x80081840: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80081844: addiu       $t9, $zero, 0xA8
    ctx->r25 = ADD32(0, 0XA8);
    // 0x80081848: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8008184C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80081850: nop

    // 0x80081854: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80081858: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008185C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081860: nop

    // 0x80081864: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80081868: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008186C: nop

    // 0x80081870: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80081874: addiu       $t0, $zero, 0x3E8
    ctx->r8 = ADD32(0, 0X3E8);
    // 0x80081878: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8008187C: jal         0x80016620
    // 0x80081880: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_4;
    // 0x80081880: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x80081884: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80081888: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8008188C: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
    // 0x80081890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081894: sw          $zero, 0x2890($at)
    MEM_W(0X2890, ctx->r1) = 0;
L_80081898:
    // 0x80081898: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008189C: nop

    // 0x800818A0: lhu         $t3, 0x14($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X14);
    // 0x800818A4: nop

    // 0x800818A8: bne         $t3, $zero, L_800818D0
    if (ctx->r11 != 0) {
        // 0x800818AC: nop

            goto L_800818D0;
    }
    // 0x800818AC: nop

    // 0x800818B0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800818B4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800818B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800818BC: lwc1        $f8, 0x10($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800818C0: nop

    // 0x800818C4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800818C8: b           L_800818F0
    // 0x800818CC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
        goto L_800818F0;
    // 0x800818CC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_800818D0:
    // 0x800818D0: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800818D4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800818D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800818DC: lwc1        $f16, 0x10($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800818E0: nop

    // 0x800818E4: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800818E8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800818EC: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_800818F0:
    // 0x800818F0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800818F4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800818F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800818FC: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80081900: nop

    // 0x80081904: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80081908: nop

    // 0x8008190C: bc1f        L_80081A18
    if (!c1cs) {
        // 0x80081910: nop

            goto L_80081A18;
    }
    // 0x80081910: nop

    // 0x80081914: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081918: lwc1        $f18, -0xB08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XB08);
    // 0x8008191C: nop

    // 0x80081920: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80081924: nop

    // 0x80081928: bc1f        L_80081A18
    if (!c1cs) {
        // 0x8008192C: nop

            goto L_80081A18;
    }
    // 0x8008192C: nop

    // 0x80081930: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80081934: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80081938: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008193C: lwc1        $f16, 0x10($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80081940: nop

    // 0x80081944: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x80081948: nop

    // 0x8008194C: bc1f        L_8008195C
    if (!c1cs) {
        // 0x80081950: nop

            goto L_8008195C;
    }
    // 0x80081950: nop

    // 0x80081954: jal         0x800B9000
    // 0x80081958: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x80081958: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_5:
L_8008195C:
    // 0x8008195C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80081960: nop

    // 0x80081964: lhu         $t9, 0x14($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X14);
    // 0x80081968: nop

    // 0x8008196C: bne         $t9, $zero, L_80081984
    if (ctx->r25 != 0) {
        // 0x80081970: nop

            goto L_80081984;
    }
    // 0x80081970: nop

    // 0x80081974: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80081978: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008197C: b           L_80081994
    // 0x80081980: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
        goto L_80081994;
    // 0x80081980: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
L_80081984:
    // 0x80081984: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80081988: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008198C: nop

    // 0x80081990: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
L_80081994:
    // 0x80081994: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80081998: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8008199C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800819A0: lwc1        $f8, 0x10($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800819A4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800819A8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800819AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800819B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800819B4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800819B8: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800819BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800819C0: lwc1        $f9, -0xB00($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XB00);
    // 0x800819C4: lwc1        $f8, -0xAFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XAFC);
    // 0x800819C8: nop

    // 0x800819CC: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x800819D0: jal         0x800C3070
    // 0x800819D4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_6;
    // 0x800819D4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_6:
    // 0x800819D8: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800819DC: nop

    // 0x800819E0: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800819E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800819E8: nop

    // 0x800819EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800819F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800819F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800819F8: nop

    // 0x800819FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80081A00: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80081A04: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80081A08: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80081A0C: nop

    // 0x80081A10: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80081A14: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_80081A18:
    // 0x80081A18: jal         0x800C1754
    // 0x80081A1C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_7;
    // 0x80081A1C: nop

    after_7:
    // 0x80081A20: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80081A24: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80081A28: jal         0x800C2304
    // 0x80081A2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_8;
    // 0x80081A2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80081A30: jal         0x800AD5EC
    // 0x80081A34: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800AD5EC(rdram, ctx);
        goto after_9;
    // 0x80081A34: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_9:
    // 0x80081A38: jal         0x800C1A28
    // 0x80081A3C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_10;
    // 0x80081A3C: nop

    after_10:
    // 0x80081A40: b           L_80081A50
    // 0x80081A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081A50;
    // 0x80081A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80081A48: b           L_80081A50
    // 0x80081A4C: nop

        goto L_80081A50;
    // 0x80081A4C: nop

L_80081A50:
    // 0x80081A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081A54: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80081A58: jr          $ra
    // 0x80081A5C: nop

    return;
    // 0x80081A5C: nop

;}
RECOMP_FUNC void func_80081A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081A60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081A68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80081A6C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80081A70: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80081A74: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80081A78: nop

    // 0x80081A7C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80081A80: lhu         $t8, 0xA($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0XA);
    // 0x80081A84: nop

    // 0x80081A88: blez        $t8, L_80081AE8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80081A8C: nop

            goto L_80081AE8;
    }
    // 0x80081A8C: nop

L_80081A90:
    // 0x80081A90: jal         0x800C1754
    // 0x80081A94: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x80081A94: nop

    after_0:
    // 0x80081A98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80081A9C: jal         0x8009A14C
    // 0x80081AA0: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x80081AA0: nop

    after_1:
    // 0x80081AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80081AA8: jal         0x800997D8
    // 0x80081AAC: nop

    func_800997D8(rdram, ctx);
        goto after_2;
    // 0x80081AAC: nop

    after_2:
    // 0x80081AB0: jal         0x800C1A28
    // 0x80081AB4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x80081AB4: nop

    after_3:
    // 0x80081AB8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80081ABC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80081AC0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80081AC4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80081AC8: addiu       $t2, $t1, 0x160
    ctx->r10 = ADD32(ctx->r9, 0X160);
    // 0x80081ACC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80081AD0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80081AD4: lhu         $t4, 0xA($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XA);
    // 0x80081AD8: nop

    // 0x80081ADC: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80081AE0: bne         $at, $zero, L_80081A90
    if (ctx->r1 != 0) {
        // 0x80081AE4: nop

            goto L_80081A90;
    }
    // 0x80081AE4: nop

L_80081AE8:
    // 0x80081AE8: b           L_80081AF0
    // 0x80081AEC: nop

        goto L_80081AF0;
    // 0x80081AEC: nop

L_80081AF0:
    // 0x80081AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081AF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80081AF8: jr          $ra
    // 0x80081AFC: nop

    return;
    // 0x80081AFC: nop

;}
RECOMP_FUNC void func_80081B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081B00: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80081B04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80081B08: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80081B0C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80081B10: addiu       $t6, $t6, 0x2830
    ctx->r14 = ADD32(ctx->r14, 0X2830);
    // 0x80081B14: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80081B18: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80081B1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081B20: beq         $t7, $at, L_80081B78
    if (ctx->r15 == ctx->r1) {
        // 0x80081B24: nop

            goto L_80081B78;
    }
    // 0x80081B24: nop

L_80081B28:
    // 0x80081B28: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80081B2C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80081B30: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80081B34: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80081B38: lh          $t0, 0x2830($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X2830);
    // 0x80081B3C: nop

    // 0x80081B40: bne         $t0, $a0, L_80081B54
    if (ctx->r8 != ctx->r4) {
        // 0x80081B44: nop

            goto L_80081B54;
    }
    // 0x80081B44: nop

    // 0x80081B48: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80081B4C: b           L_80081B88
    // 0x80081B50: nop

        goto L_80081B88;
    // 0x80081B50: nop

L_80081B54:
    // 0x80081B54: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80081B58: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80081B5C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80081B60: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80081B64: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80081B68: lh          $t4, 0x2830($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2830);
    // 0x80081B6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081B70: bne         $t4, $at, L_80081B28
    if (ctx->r12 != ctx->r1) {
        // 0x80081B74: sw          $t2, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r10;
            goto L_80081B28;
    }
    // 0x80081B74: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
L_80081B78:
    // 0x80081B78: b           L_80081B88
    // 0x80081B7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081B88;
    // 0x80081B7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80081B80: b           L_80081B88
    // 0x80081B84: nop

        goto L_80081B88;
    // 0x80081B84: nop

L_80081B88:
    // 0x80081B88: jr          $ra
    // 0x80081B8C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80081B8C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80081B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081B90: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80081B94: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80081B98: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80081B9C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80081BA0: addiu       $t6, $t6, 0x2848
    ctx->r14 = ADD32(ctx->r14, 0X2848);
    // 0x80081BA4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80081BA8: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80081BAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081BB0: beq         $t7, $at, L_80081C98
    if (ctx->r15 == ctx->r1) {
        // 0x80081BB4: nop

            goto L_80081C98;
    }
    // 0x80081BB4: nop

L_80081BB8:
    // 0x80081BB8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80081BBC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80081BC0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80081BC4: addiu       $t0, $t0, 0x2848
    ctx->r8 = ADD32(ctx->r8, 0X2848);
    // 0x80081BC8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80081BCC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80081BD0: lb          $t2, 0x3($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X3);
    // 0x80081BD4: nop

    // 0x80081BD8: bne         $t2, $a3, L_80081C70
    if (ctx->r10 != ctx->r7) {
        // 0x80081BDC: nop

            goto L_80081C70;
    }
    // 0x80081BDC: nop

    // 0x80081BE0: lb          $t3, 0x4($t1)
    ctx->r11 = MEM_B(ctx->r9, 0X4);
    // 0x80081BE4: lh          $t4, 0x1A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1A);
    // 0x80081BE8: nop

    // 0x80081BEC: bne         $t3, $t4, L_80081C70
    if (ctx->r11 != ctx->r12) {
        // 0x80081BF0: nop

            goto L_80081C70;
    }
    // 0x80081BF0: nop

    // 0x80081BF4: lb          $t5, 0x5($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X5);
    // 0x80081BF8: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80081BFC: nop

    // 0x80081C00: bne         $t5, $t6, L_80081C70
    if (ctx->r13 != ctx->r14) {
        // 0x80081C04: nop

            goto L_80081C70;
    }
    // 0x80081C04: nop

    // 0x80081C08: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80081C0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80081C10: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80081C14: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80081C18: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80081C1C: lb          $t9, 0x2848($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X2848);
    // 0x80081C20: nop

    // 0x80081C24: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80081C28: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80081C2C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80081C30: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x80081C34: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80081C38: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80081C3C: lb          $t3, 0x2849($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X2849);
    // 0x80081C40: nop

    // 0x80081C44: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80081C48: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80081C4C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80081C50: sll         $t1, $t4, 3
    ctx->r9 = S32(ctx->r12 << 3);
    // 0x80081C54: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x80081C58: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80081C5C: lb          $t5, 0x284A($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X284A);
    // 0x80081C60: nop

    // 0x80081C64: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x80081C68: b           L_80081CE0
    // 0x80081C6C: nop

        goto L_80081CE0;
    // 0x80081C6C: nop

L_80081C70:
    // 0x80081C70: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80081C74: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80081C78: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80081C7C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80081C80: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80081C84: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80081C88: lb          $t9, 0x2848($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X2848);
    // 0x80081C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081C90: bne         $t9, $at, L_80081BB8
    if (ctx->r25 != ctx->r1) {
        // 0x80081C94: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80081BB8;
    }
    // 0x80081C94: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_80081C98:
    // 0x80081C98: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x80081C9C: nop

    // 0x80081CA0: bne         $t0, $zero, L_80081CC0
    if (ctx->r8 != 0) {
        // 0x80081CA4: nop

            goto L_80081CC0;
    }
    // 0x80081CA4: nop

    // 0x80081CA8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80081CAC: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x80081CB0: addiu       $t3, $zero, 0x47
    ctx->r11 = ADD32(0, 0X47);
    // 0x80081CB4: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80081CB8: b           L_80081CD8
    // 0x80081CBC: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
        goto L_80081CD8;
    // 0x80081CBC: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
L_80081CC0:
    // 0x80081CC0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80081CC4: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x80081CC8: addiu       $t1, $zero, 0x48
    ctx->r9 = ADD32(0, 0X48);
    // 0x80081CCC: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80081CD0: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80081CD4: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
L_80081CD8:
    // 0x80081CD8: b           L_80081CE0
    // 0x80081CDC: nop

        goto L_80081CE0;
    // 0x80081CDC: nop

L_80081CE0:
    // 0x80081CE0: jr          $ra
    // 0x80081CE4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80081CE4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80081CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081CE8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80081CEC: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80081CF0: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x80081CF4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80081CF8: bne         $t6, $at, L_80081DE4
    if (ctx->r14 != ctx->r1) {
        // 0x80081CFC: nop

            goto L_80081DE4;
    }
    // 0x80081CFC: nop

    // 0x80081D00: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80081D04: nop

    // 0x80081D08: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80081D0C: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x80081D10: nop

    // 0x80081D14: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80081D18: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80081D1C: lh          $t9, -0x498($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X498);
    // 0x80081D20: nop

    // 0x80081D24: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80081D28: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80081D2C: addiu       $t0, $t0, 0x2848
    ctx->r8 = ADD32(ctx->r8, 0X2848);
    // 0x80081D30: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80081D34: lb          $t1, 0x0($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X0);
    // 0x80081D38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081D3C: beq         $t1, $at, L_80081DD4
    if (ctx->r9 == ctx->r1) {
        // 0x80081D40: nop

            goto L_80081DD4;
    }
    // 0x80081D40: nop

L_80081D44:
    // 0x80081D44: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80081D48: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80081D4C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80081D50: addiu       $t5, $t5, 0x2848
    ctx->r13 = ADD32(ctx->r13, 0X2848);
    // 0x80081D54: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80081D58: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80081D5C: lb          $t7, 0x3($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X3);
    // 0x80081D60: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x80081D64: nop

    // 0x80081D68: bne         $t2, $t7, L_80081DAC
    if (ctx->r10 != ctx->r15) {
        // 0x80081D6C: nop

            goto L_80081DAC;
    }
    // 0x80081D6C: nop

    // 0x80081D70: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80081D74: lb          $t9, 0x4($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X4);
    // 0x80081D78: nop

    // 0x80081D7C: bne         $t8, $t9, L_80081DAC
    if (ctx->r24 != ctx->r25) {
        // 0x80081D80: nop

            goto L_80081DAC;
    }
    // 0x80081D80: nop

    // 0x80081D84: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80081D88: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80081D8C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80081D90: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80081D94: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80081D98: lb          $t3, 0x284E($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X284E);
    // 0x80081D9C: nop

    // 0x80081DA0: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x80081DA4: b           L_80081FB0
    // 0x80081DA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081FB0;
    // 0x80081DA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80081DAC:
    // 0x80081DAC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80081DB0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081DB4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80081DB8: sll         $t2, $t5, 3
    ctx->r10 = S32(ctx->r13 << 3);
    // 0x80081DBC: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x80081DC0: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80081DC4: lb          $t7, 0x2848($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X2848);
    // 0x80081DC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081DCC: bne         $t7, $at, L_80081D44
    if (ctx->r15 != ctx->r1) {
        // 0x80081DD0: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_80081D44;
    }
    // 0x80081DD0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
L_80081DD4:
    // 0x80081DD4: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x80081DD8: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x80081DDC: b           L_80081FB0
    // 0x80081DE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081FB0;
    // 0x80081DE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80081DE4:
    // 0x80081DE4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80081DE8: addiu       $t8, $t8, 0x2848
    ctx->r24 = ADD32(ctx->r24, 0X2848);
    // 0x80081DEC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80081DF0: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x80081DF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081DF8: beq         $t9, $at, L_80081F50
    if (ctx->r25 == ctx->r1) {
        // 0x80081DFC: nop

            goto L_80081F50;
    }
    // 0x80081DFC: nop

L_80081E00:
    // 0x80081E00: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80081E04: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80081E08: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80081E0C: addiu       $t3, $t3, 0x2848
    ctx->r11 = ADD32(ctx->r11, 0X2848);
    // 0x80081E10: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80081E14: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80081E18: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x80081E1C: lh          $t2, 0x1A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1A);
    // 0x80081E20: nop

    // 0x80081E24: bne         $t5, $t2, L_80081F28
    if (ctx->r13 != ctx->r10) {
        // 0x80081E28: nop

            goto L_80081F28;
    }
    // 0x80081E28: nop

    // 0x80081E2C: lb          $t7, 0x1($t4)
    ctx->r15 = MEM_B(ctx->r12, 0X1);
    // 0x80081E30: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80081E34: nop

    // 0x80081E38: bne         $t7, $t6, L_80081F28
    if (ctx->r15 != ctx->r14) {
        // 0x80081E3C: nop

            goto L_80081F28;
    }
    // 0x80081E3C: nop

    // 0x80081E40: lb          $t8, 0x2($t4)
    ctx->r24 = MEM_B(ctx->r12, 0X2);
    // 0x80081E44: lh          $t9, 0x22($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X22);
    // 0x80081E48: nop

    // 0x80081E4C: bne         $t8, $t9, L_80081F28
    if (ctx->r24 != ctx->r25) {
        // 0x80081E50: nop

            goto L_80081F28;
    }
    // 0x80081E50: nop

    // 0x80081E54: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80081E58: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80081E5C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80081E60: addiu       $t3, $t3, 0x2848
    ctx->r11 = ADD32(ctx->r11, 0X2848);
    // 0x80081E64: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80081E68: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80081E6C: lb          $t2, 0x3($t5)
    ctx->r10 = MEM_B(ctx->r13, 0X3);
    // 0x80081E70: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80081E74: nop

    // 0x80081E78: bne         $t2, $t7, L_80081E9C
    if (ctx->r10 != ctx->r15) {
        // 0x80081E7C: nop

            goto L_80081E9C;
    }
    // 0x80081E7C: nop

    // 0x80081E80: lb          $t6, 0x4($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X4);
    // 0x80081E84: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x80081E88: nop

    // 0x80081E8C: bne         $t6, $t4, L_80081E9C
    if (ctx->r14 != ctx->r12) {
        // 0x80081E90: nop

            goto L_80081E9C;
    }
    // 0x80081E90: nop

    // 0x80081E94: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80081E98: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
L_80081E9C:
    // 0x80081E9C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80081EA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80081EA4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80081EA8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80081EAC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80081EB0: lb          $t1, 0x284B($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X284B);
    // 0x80081EB4: nop

    // 0x80081EB8: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80081EBC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80081EC0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081EC4: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x80081EC8: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80081ECC: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80081ED0: lb          $t7, 0x284C($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X284C);
    // 0x80081ED4: nop

    // 0x80081ED8: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x80081EDC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80081EE0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80081EE4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80081EE8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80081EEC: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x80081EF0: lb          $t4, 0x284D($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X284D);
    // 0x80081EF4: nop

    // 0x80081EF8: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
    // 0x80081EFC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80081F00: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80081F04: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80081F08: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80081F0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80081F10: lb          $t0, 0x284E($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X284E);
    // 0x80081F14: nop

    // 0x80081F18: sh          $t0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r8;
    // 0x80081F1C: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80081F20: b           L_80081FB0
    // 0x80081F24: nop

        goto L_80081FB0;
    // 0x80081F24: nop

L_80081F28:
    // 0x80081F28: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80081F2C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081F30: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80081F34: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x80081F38: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80081F3C: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80081F40: lb          $t7, 0x2848($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X2848);
    // 0x80081F44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081F48: bne         $t7, $at, L_80081E00
    if (ctx->r15 != ctx->r1) {
        // 0x80081F4C: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_80081E00;
    }
    // 0x80081F4C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_80081F50:
    // 0x80081F50: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80081F54: addiu       $t5, $t5, 0x2848
    ctx->r13 = ADD32(ctx->r13, 0X2848);
    // 0x80081F58: lb          $t6, 0x3($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X3);
    // 0x80081F5C: nop

    // 0x80081F60: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x80081F64: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80081F68: addiu       $t4, $t4, 0x2848
    ctx->r12 = ADD32(ctx->r12, 0X2848);
    // 0x80081F6C: lb          $t8, 0x4($t4)
    ctx->r24 = MEM_B(ctx->r12, 0X4);
    // 0x80081F70: nop

    // 0x80081F74: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80081F78: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80081F7C: addiu       $t9, $t9, 0x2848
    ctx->r25 = ADD32(ctx->r25, 0X2848);
    // 0x80081F80: lb          $t0, 0x5($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X5);
    // 0x80081F84: nop

    // 0x80081F88: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x80081F8C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80081F90: addiu       $t1, $t1, 0x2848
    ctx->r9 = ADD32(ctx->r9, 0X2848);
    // 0x80081F94: lb          $t3, 0x6($t1)
    ctx->r11 = MEM_B(ctx->r9, 0X6);
    // 0x80081F98: nop

    // 0x80081F9C: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x80081FA0: b           L_80081FB0
    // 0x80081FA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081FB0;
    // 0x80081FA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80081FA8: b           L_80081FB0
    // 0x80081FAC: nop

        goto L_80081FB0;
    // 0x80081FAC: nop

L_80081FB0:
    // 0x80081FB0: jr          $ra
    // 0x80081FB4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80081FB4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80081FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081FB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80081FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081FC0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80081FC4: jal         0x800BC6EC
    // 0x80081FC8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80081FC8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x80081FCC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80081FD0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80081FD4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081FD8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80081FDC: lbu         $t7, -0x6230($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6230);
    // 0x80081FE0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80081FE4: nop

    // 0x80081FE8: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x80081FEC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80081FF0: nop

    // 0x80081FF4: sh          $zero, 0xA($t9)
    MEM_H(0XA, ctx->r25) = 0;
    // 0x80081FF8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80081FFC: nop

    // 0x80082000: lhu         $a0, 0x8($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X8);
    // 0x80082004: nop

    // 0x80082008: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8008200C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80082010: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80082014: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80082018: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x8008201C: jal         0x800BC6EC
    // 0x80082020: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80082020: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_1:
    // 0x80082024: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082028: nop

    // 0x8008202C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x80082030: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80082034: nop

    // 0x80082038: lhu         $a0, 0x8($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X8);
    // 0x8008203C: nop

    // 0x80082040: sll         $t4, $a0, 6
    ctx->r12 = S32(ctx->r4 << 6);
    // 0x80082044: jal         0x800BC6EC
    // 0x80082048: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80082048: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_2:
    // 0x8008204C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80082050: nop

    // 0x80082054: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x80082058: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008205C: nop

    // 0x80082060: lhu         $a2, 0x8($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X8);
    // 0x80082064: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80082068: jal         0x800B1B3C
    // 0x8008206C: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    func_800B1B3C(rdram, ctx);
        goto after_3;
    // 0x8008206C: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_3:
    // 0x80082070: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80082074: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80082078: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8008207C: nop

    // 0x80082080: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80082084: lhu         $t9, 0x8($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X8);
    // 0x80082088: nop

    // 0x8008208C: blez        $t9, L_80082100
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80082090: nop

            goto L_80082100;
    }
    // 0x80082090: nop

L_80082094:
    // 0x80082094: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80082098: jal         0x80099E2C
    // 0x8008209C: nop

    func_80099E2C(rdram, ctx);
        goto after_4;
    // 0x8008209C: nop

    after_4:
    // 0x800820A0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800820A4: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x800820A8: sh          $t0, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r8;
    // 0x800820AC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800820B0: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x800820B4: sw          $t2, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r10;
    // 0x800820B8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800820BC: nop

    // 0x800820C0: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x800820C4: nop

    // 0x800820C8: ori         $t6, $t5, 0xC
    ctx->r14 = ctx->r13 | 0XC;
    // 0x800820CC: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x800820D0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800820D4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800820D8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800820DC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800820E0: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x800820E4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800820E8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800820EC: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x800820F0: nop

    // 0x800820F4: slt         $at, $t7, $t2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800820F8: bne         $at, $zero, L_80082094
    if (ctx->r1 != 0) {
        // 0x800820FC: nop

            goto L_80082094;
    }
    // 0x800820FC: nop

L_80082100:
    // 0x80082100: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80082104: b           L_80082114
    // 0x80082108: nop

        goto L_80082114;
    // 0x80082108: nop

    // 0x8008210C: b           L_80082114
    // 0x80082110: nop

        goto L_80082114;
    // 0x80082110: nop

L_80082114:
    // 0x80082114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008211C: jr          $ra
    // 0x80082120: nop

    return;
    // 0x80082120: nop

;}
RECOMP_FUNC void func_80082124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008212C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80082130: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80082134: nop

    // 0x80082138: lhu         $a2, 0x8($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X8);
    // 0x8008213C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80082140: jal         0x800B1C10
    // 0x80082144: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    func_800B1C10(rdram, ctx);
        goto after_0;
    // 0x80082144: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x80082148: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008214C: nop

    // 0x80082150: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80082154: jal         0x800BC980
    // 0x80082158: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80082158: nop

    after_1:
    // 0x8008215C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80082160: nop

    // 0x80082164: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x80082168: jal         0x800BC980
    // 0x8008216C: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8008216C: nop

    after_2:
    // 0x80082170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80082174: jal         0x800BC980
    // 0x80082178: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80082178: nop

    after_3:
    // 0x8008217C: b           L_80082184
    // 0x80082180: nop

        goto L_80082184;
    // 0x80082180: nop

L_80082184:
    // 0x80082184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008218C: jr          $ra
    // 0x80082190: nop

    return;
    // 0x80082190: nop

    // 0x80082194: nop

    // 0x80082198: nop

    // 0x8008219C: nop

;}
RECOMP_FUNC void func_800821A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800821A0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800821A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800821A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800821AC: sw          $zero, 0x165C($at)
    MEM_W(0X165C, ctx->r1) = 0;
    // 0x800821B0: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800821B4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800821B8: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x800821BC: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x800821C0: nop

    // 0x800821C4: bne         $t7, $zero, L_800821D4
    if (ctx->r15 != 0) {
        // 0x800821C8: nop

            goto L_800821D4;
    }
    // 0x800821C8: nop

    // 0x800821CC: b           L_800824FC
    // 0x800821D0: nop

        goto L_800824FC;
    // 0x800821D0: nop

L_800821D4:
    // 0x800821D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800821D8: addiu       $t8, $t8, 0x7340
    ctx->r24 = ADD32(ctx->r24, 0X7340);
    // 0x800821DC: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x800821E0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800821E4: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x800821E8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800821EC: nop

    // 0x800821F0: bne         $t0, $at, L_80082208
    if (ctx->r8 != ctx->r1) {
        // 0x800821F4: nop

            goto L_80082208;
    }
    // 0x800821F4: nop

    // 0x800821F8: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x800821FC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80082200: beq         $t1, $at, L_800824F4
    if (ctx->r9 == ctx->r1) {
        // 0x80082204: nop

            goto L_800824F4;
    }
    // 0x80082204: nop

L_80082208:
    // 0x80082208: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8008220C: jal         0x8008250C
    // 0x80082210: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008250C(rdram, ctx);
        goto after_0;
    // 0x80082210: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80082214: beq         $v0, $zero, L_800824C4
    if (ctx->r2 == 0) {
        // 0x80082218: nop

            goto L_800824C4;
    }
    // 0x80082218: nop

    // 0x8008221C: jal         0x800BC6EC
    // 0x80082220: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80082220: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_1:
    // 0x80082224: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80082228: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8008222C: lw          $t2, 0x165C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X165C);
    // 0x80082230: nop

    // 0x80082234: bne         $t2, $zero, L_8008224C
    if (ctx->r10 != 0) {
        // 0x80082238: nop

            goto L_8008224C;
    }
    // 0x80082238: nop

    // 0x8008223C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80082240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082244: b           L_8008226C
    // 0x80082248: sw          $t3, 0x165C($at)
    MEM_W(0X165C, ctx->r1) = ctx->r11;
        goto L_8008226C;
    // 0x80082248: sw          $t3, 0x165C($at)
    MEM_W(0X165C, ctx->r1) = ctx->r11;
L_8008224C:
    // 0x8008224C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80082250: nop

    // 0x80082254: beq         $t4, $zero, L_8008226C
    if (ctx->r12 == 0) {
        // 0x80082258: nop

            goto L_8008226C;
    }
    // 0x80082258: nop

    // 0x8008225C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80082260: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80082264: nop

    // 0x80082268: sw          $t5, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r13;
L_8008226C:
    // 0x8008226C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80082270: nop

    // 0x80082274: sw          $zero, 0x44($t7)
    MEM_W(0X44, ctx->r15) = 0;
    // 0x80082278: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8008227C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80082280: nop

    // 0x80082284: sw          $t8, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r24;
    // 0x80082288: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8008228C: nop

    // 0x80082290: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x80082294: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80082298: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8008229C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800822A0: nop

    // 0x800822A4: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x800822A8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800822AC: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x800822B0: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800822B4: nop

    // 0x800822B8: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x800822BC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800822C0: nop

    // 0x800822C4: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800822C8: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800822CC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800822D0: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x800822D4: nop

    // 0x800822D8: andi        $t8, $t7, 0x3C
    ctx->r24 = ctx->r15 & 0X3C;
    // 0x800822DC: sra         $t0, $t8, 2
    ctx->r8 = S32(SIGNED(ctx->r24) >> 2);
    // 0x800822E0: sh          $t0, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r8;
    // 0x800822E4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800822E8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800822EC: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x800822F0: nop

    // 0x800822F4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800822F8: nop

    // 0x800822FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082300: swc1        $f6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f6.u32l;
    // 0x80082304: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80082308: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8008230C: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x80082310: nop

    // 0x80082314: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80082318: nop

    // 0x8008231C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80082320: swc1        $f10, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f10.u32l;
    // 0x80082324: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80082328: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8008232C: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x80082330: nop

    // 0x80082334: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80082338: nop

    // 0x8008233C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80082340: swc1        $f18, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f18.u32l;
    // 0x80082344: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80082348: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8008234C: lh          $t1, 0xE($t9)
    ctx->r9 = MEM_H(ctx->r25, 0XE);
    // 0x80082350: nop

    // 0x80082354: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80082358: nop

    // 0x8008235C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082360: swc1        $f6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f6.u32l;
    // 0x80082364: lh          $t3, 0x2C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2C);
    // 0x80082368: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8008236C: nop

    // 0x80082370: sh          $t3, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r11;
    // 0x80082374: lh          $t5, 0x2E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2E);
    // 0x80082378: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8008237C: nop

    // 0x80082380: sh          $t5, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r13;
    // 0x80082384: lh          $t7, 0x30($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X30);
    // 0x80082388: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8008238C: nop

    // 0x80082390: sh          $t7, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r15;
    // 0x80082394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082398: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8008239C: nop

    // 0x800823A0: swc1        $f8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f8.u32l;
    // 0x800823A4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800823A8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800823AC: nop

    // 0x800823B0: sw          $t9, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r25;
    // 0x800823B4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800823B8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800823BC: nop

    // 0x800823C0: sw          $t2, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r10;
    // 0x800823C4: lhu         $t4, 0x3C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3C);
    // 0x800823C8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800823CC: nop

    // 0x800823D0: sh          $t4, 0x2C($t5)
    MEM_H(0X2C, ctx->r13) = ctx->r12;
    // 0x800823D4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800823D8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800823DC: nop

    // 0x800823E0: sw          $t6, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r14;
    // 0x800823E4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800823E8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800823EC: nop

    // 0x800823F0: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x800823F4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800823F8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800823FC: nop

    // 0x80082400: sw          $t9, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r25;
    // 0x80082404: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80082408: nop

    // 0x8008240C: lh          $t3, 0xC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XC);
    // 0x80082410: nop

    // 0x80082414: beq         $t3, $zero, L_800824B8
    if (ctx->r11 == 0) {
        // 0x80082418: nop

            goto L_800824B8;
    }
    // 0x80082418: nop

    // 0x8008241C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80082420: nop

    // 0x80082424: lwc1        $f10, 0x14($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X14);
    // 0x80082428: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x8008242C: lh          $t7, 0xA($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XA);
    // 0x80082430: lhu         $a3, 0x2C($t4)
    ctx->r7 = MEM_HU(ctx->r12, 0X2C);
    // 0x80082434: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80082438: lwc1        $f16, 0x18($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8008243C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80082440: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80082444: addiu       $a0, $t4, 0x24
    ctx->r4 = ADD32(ctx->r12, 0X24);
    // 0x80082448: addiu       $a1, $t4, 0x28
    ctx->r5 = ADD32(ctx->r12, 0X28);
    // 0x8008244C: or          $a2, $t6, $t7
    ctx->r6 = ctx->r14 | ctx->r15;
    // 0x80082450: jal         0x800B202C
    // 0x80082454: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_2;
    // 0x80082454: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80082458: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8008245C: nop

    // 0x80082460: sw          $v0, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r2;
    // 0x80082464: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80082468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008246C: jal         0x8005A5F4
    // 0x80082470: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8005A5F4(rdram, ctx);
        goto after_3;
    // 0x80082470: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x80082474: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80082478: nop

    // 0x8008247C: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x80082480: nop

    // 0x80082484: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80082488: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x8008248C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80082490: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082494: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80082498: nop

    // 0x8008249C: bne         $t3, $at, L_800824B0
    if (ctx->r11 != ctx->r1) {
        // 0x800824A0: nop

            goto L_800824B0;
    }
    // 0x800824A0: nop

    // 0x800824A4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800824A8: nop

    // 0x800824AC: sh          $zero, 0xC($t5)
    MEM_H(0XC, ctx->r13) = 0;
L_800824B0:
    // 0x800824B0: b           L_800824C4
    // 0x800824B4: nop

        goto L_800824C4;
    // 0x800824B4: nop

L_800824B8:
    // 0x800824B8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800824BC: nop

    // 0x800824C0: sw          $zero, 0x30($t6)
    MEM_W(0X30, ctx->r14) = 0;
L_800824C4:
    // 0x800824C4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800824C8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800824CC: addiu       $t4, $t7, 0x10
    ctx->r12 = ADD32(ctx->r15, 0X10);
    // 0x800824D0: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x800824D4: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x800824D8: nop

    // 0x800824DC: bne         $t8, $at, L_80082208
    if (ctx->r24 != ctx->r1) {
        // 0x800824E0: nop

            goto L_80082208;
    }
    // 0x800824E0: nop

    // 0x800824E4: lhu         $t9, 0x2($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X2);
    // 0x800824E8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800824EC: bne         $t9, $at, L_80082208
    if (ctx->r25 != ctx->r1) {
        // 0x800824F0: nop

            goto L_80082208;
    }
    // 0x800824F0: nop

L_800824F4:
    // 0x800824F4: b           L_800824FC
    // 0x800824F8: nop

        goto L_800824FC;
    // 0x800824F8: nop

L_800824FC:
    // 0x800824FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80082500: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80082504: jr          $ra
    // 0x80082508: nop

    return;
    // 0x80082508: nop

;}
RECOMP_FUNC void func_8008250C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008250C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80082510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082514: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80082518: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008251C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80082520: nop

    // 0x80082524: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x80082528: nop

    // 0x8008252C: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    // 0x80082530: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x80082534: nop

    // 0x80082538: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008253C: bne         $t9, $zero, L_80082554
    if (ctx->r25 != 0) {
        // 0x80082540: nop

            goto L_80082554;
    }
    // 0x80082540: nop

    // 0x80082544: andi        $t0, $t8, 0x7F00
    ctx->r8 = ctx->r24 & 0X7F00;
    // 0x80082548: sra         $t1, $t0, 8
    ctx->r9 = S32(SIGNED(ctx->r8) >> 8);
    // 0x8008254C: bne         $t1, $zero, L_80082938
    if (ctx->r9 != 0) {
        // 0x80082550: nop

            goto L_80082938;
    }
    // 0x80082550: nop

L_80082554:
    // 0x80082554: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80082558: addiu       $t2, $t2, 0x3B8C
    ctx->r10 = ADD32(ctx->r10, 0X3B8C);
    // 0x8008255C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80082560: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80082564: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082568: beq         $t3, $at, L_80082938
    if (ctx->r11 == ctx->r1) {
        // 0x8008256C: nop

            goto L_80082938;
    }
    // 0x8008256C: nop

L_80082570:
    // 0x80082570: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80082574: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80082578: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008257C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80082580: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80082584: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80082588: lh          $t6, 0x3B8C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X3B8C);
    // 0x8008258C: nop

    // 0x80082590: bne         $t6, $t7, L_80082914
    if (ctx->r14 != ctx->r15) {
        // 0x80082594: nop

            goto L_80082914;
    }
    // 0x80082594: nop

    // 0x80082598: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008259C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800825A0: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800825A4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800825A8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800825AC: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x800825B0: lh          $t0, 0x3B8E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3B8E);
    // 0x800825B4: nop

    // 0x800825B8: bne         $t0, $t1, L_80082914
    if (ctx->r8 != ctx->r9) {
        // 0x800825BC: nop

            goto L_80082914;
    }
    // 0x800825BC: nop

    // 0x800825C0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800825C4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800825C8: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800825CC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800825D0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800825D4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800825D8: lh          $t9, 0x3B90($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X3B90);
    // 0x800825DC: andi        $t4, $t3, 0x3C
    ctx->r12 = ctx->r11 & 0X3C;
    // 0x800825E0: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x800825E4: bne         $t5, $t9, L_80082914
    if (ctx->r13 != ctx->r25) {
        // 0x800825E8: nop

            goto L_80082914;
    }
    // 0x800825E8: nop

    // 0x800825EC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800825F0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800825F4: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800825F8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800825FC: lh          $t1, 0x3B92($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3B92);
    // 0x80082600: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80082604: nop

    // 0x80082608: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x8008260C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80082610: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80082614: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80082618: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8008261C: lh          $t6, 0x3B94($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X3B94);
    // 0x80082620: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80082624: nop

    // 0x80082628: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x8008262C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80082630: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80082634: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80082638: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8008263C: lh          $t8, 0x3B92($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X3B92);
    // 0x80082640: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80082644: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80082648: lbu         $a0, -0x6230($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6230);
    // 0x8008264C: nop

    // 0x80082650: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80082654: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80082658: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008265C: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80082660: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80082664: jal         0x800BC6EC
    // 0x80082668: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80082668: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
    // 0x8008266C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80082670: nop

    // 0x80082674: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x80082678: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008267C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80082680: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80082684: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80082688: lh          $t4, 0x3B92($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X3B92);
    // 0x8008268C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80082690: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80082694: lbu         $a0, -0x6230($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6230);
    // 0x80082698: nop

    // 0x8008269C: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x800826A0: jal         0x800BC6EC
    // 0x800826A4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800826A4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x800826A8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800826AC: nop

    // 0x800826B0: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    // 0x800826B4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800826B8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800826BC: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x800826C0: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800826C4: lh          $t8, 0x3B96($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X3B96);
    // 0x800826C8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800826CC: nop

    // 0x800826D0: sh          $t8, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r24;
    // 0x800826D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800826D8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800826DC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800826E0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800826E4: lh          $t3, 0x3B98($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X3B98);
    // 0x800826E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800826EC: nop

    // 0x800826F0: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
    // 0x800826F4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800826F8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800826FC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80082700: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80082704: lh          $t5, 0x3B9A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X3B9A);
    // 0x80082708: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8008270C: nop

    // 0x80082710: sh          $t5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r13;
    // 0x80082714: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80082718: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008271C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80082720: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80082724: lh          $t2, 0x3B92($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X3B92);
    // 0x80082728: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8008272C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80082730: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x80082734: lbu         $a2, -0x6230($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X6230);
    // 0x80082738: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x8008273C: jal         0x800B1B3C
    // 0x80082740: addiu       $a1, $t8, 0xC
    ctx->r5 = ADD32(ctx->r24, 0XC);
    func_800B1B3C(rdram, ctx);
        goto after_2;
    // 0x80082740: addiu       $a1, $t8, 0xC
    ctx->r5 = ADD32(ctx->r24, 0XC);
    after_2:
    // 0x80082744: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80082748: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8008274C: sw          $t3, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r11;
    // 0x80082750: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80082754: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80082758: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008275C: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80082760: lh          $t5, 0x3B9C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X3B9C);
    // 0x80082764: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80082768: nop

    // 0x8008276C: sw          $t5, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r13;
    // 0x80082770: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80082774: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80082778: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8008277C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80082780: lh          $t1, 0x3B92($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3B92);
    // 0x80082784: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80082788: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8008278C: lbu         $t2, -0x6230($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6230);
    // 0x80082790: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80082794: blez        $t2, L_80082908
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80082798: nop

            goto L_80082908;
    }
    // 0x80082798: nop

L_8008279C:
    // 0x8008279C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800827A0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800827A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800827A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800827AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800827B0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800827B4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800827B8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800827BC: jal         0x80099E2C
    // 0x800827C0: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x800827C0: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    after_3:
    // 0x800827C4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800827C8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800827CC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800827D0: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800827D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800827D8: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x800827DC: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800827E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800827E4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x800827E8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800827EC: swc1        $f4, 0xD4($t1)
    MEM_W(0XD4, ctx->r9) = ctx->f4.u32l;
    // 0x800827F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800827F4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800827F8: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800827FC: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x80082800: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082804: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80082808: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008280C: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x80082810: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80082814: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80082818: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8008281C: swc1        $f6, 0xF4($t7)
    MEM_W(0XF4, ctx->r15) = ctx->f6.u32l;
    // 0x80082820: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082824: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80082828: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008282C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80082830: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80082834: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x80082838: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008283C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80082840: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80082844: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80082848: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008284C: swc1        $f8, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f8.u32l;
    // 0x80082850: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80082854: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80082858: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8008285C: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x80082860: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80082864: lw          $t3, 0x8($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X8);
    // 0x80082868: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x8008286C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80082870: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80082874: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x80082878: sh          $t2, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r10;
    // 0x8008287C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80082880: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80082884: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80082888: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x8008288C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80082890: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80082894: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x80082898: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8008289C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x800828A0: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x800828A4: sw          $t9, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r25;
    // 0x800828A8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800828AC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800828B0: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800828B4: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800828B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800828BC: lw          $t2, 0x8($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X8);
    // 0x800828C0: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800828C4: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800828C8: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800828CC: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800828D0: sh          $t3, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r11;
    // 0x800828D4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800828D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800828DC: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800828E0: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x800828E4: lh          $t7, 0x3B92($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X3B92);
    // 0x800828E8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800828EC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800828F0: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800828F4: lbu         $t5, -0x6230($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X6230);
    // 0x800828F8: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x800828FC: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80082900: bne         $at, $zero, L_8008279C
    if (ctx->r1 != 0) {
        // 0x80082904: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_8008279C;
    }
    // 0x80082904: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_80082908:
    // 0x80082908: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8008290C: b           L_80082948
    // 0x80082910: nop

        goto L_80082948;
    // 0x80082910: nop

L_80082914:
    // 0x80082914: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082918: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008291C: addiu       $t8, $t2, 0x9
    ctx->r24 = ADD32(ctx->r10, 0X9);
    // 0x80082920: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80082924: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80082928: lh          $t1, 0x3B8C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3B8C);
    // 0x8008292C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082930: bne         $t1, $at, L_80082570
    if (ctx->r9 != ctx->r1) {
        // 0x80082934: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80082570;
    }
    // 0x80082934: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80082938:
    // 0x80082938: b           L_80082948
    // 0x8008293C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80082948;
    // 0x8008293C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80082940: b           L_80082948
    // 0x80082944: nop

        goto L_80082948;
    // 0x80082944: nop

L_80082948:
    // 0x80082948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008294C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80082950: jr          $ra
    // 0x80082954: nop

    return;
    // 0x80082954: nop

;}
RECOMP_FUNC void func_80082958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082958: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008295C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80082964: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80082968: lw          $t6, 0x165C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X165C);
    // 0x8008296C: nop

    // 0x80082970: bne         $t6, $zero, L_80082980
    if (ctx->r14 != 0) {
        // 0x80082974: nop

            goto L_80082980;
    }
    // 0x80082974: nop

    // 0x80082978: b           L_80082BF4
    // 0x8008297C: nop

        goto L_80082BF4;
    // 0x8008297C: nop

L_80082980:
    // 0x80082980: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80082984: lw          $t7, 0x165C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X165C);
    // 0x80082988: nop

    // 0x8008298C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80082990:
    // 0x80082990: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80082994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80082998: lh          $s0, 0xC($t8)
    ctx->r16 = MEM_H(ctx->r24, 0XC);
    // 0x8008299C: nop

    // 0x800829A0: beq         $s0, $at, L_800829D4
    if (ctx->r16 == ctx->r1) {
        // 0x800829A4: nop

            goto L_800829D4;
    }
    // 0x800829A4: nop

    // 0x800829A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800829AC: beq         $s0, $at, L_800829E8
    if (ctx->r16 == ctx->r1) {
        // 0x800829B0: nop

            goto L_800829E8;
    }
    // 0x800829B0: nop

    // 0x800829B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800829B8: beq         $s0, $at, L_80082B0C
    if (ctx->r16 == ctx->r1) {
        // 0x800829BC: nop

            goto L_80082B0C;
    }
    // 0x800829BC: nop

    // 0x800829C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800829C4: beq         $s0, $at, L_80082BA8
    if (ctx->r16 == ctx->r1) {
        // 0x800829C8: nop

            goto L_80082BA8;
    }
    // 0x800829C8: nop

    // 0x800829CC: b           L_80082BB0
    // 0x800829D0: nop

        goto L_80082BB0;
    // 0x800829D0: nop

L_800829D4:
    // 0x800829D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800829D8: jal         0x80082C04
    // 0x800829DC: nop

    func_80082C04(rdram, ctx);
        goto after_0;
    // 0x800829DC: nop

    after_0:
    // 0x800829E0: b           L_80082BB0
    // 0x800829E4: nop

        goto L_80082BB0;
    // 0x800829E4: nop

L_800829E8:
    // 0x800829E8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800829EC: addiu       $at, $zero, 0x244
    ctx->r1 = ADD32(0, 0X244);
    // 0x800829F0: lh          $s0, 0xA($t9)
    ctx->r16 = MEM_H(ctx->r25, 0XA);
    // 0x800829F4: nop

    // 0x800829F8: beq         $s0, $at, L_80082A20
    if (ctx->r16 == ctx->r1) {
        // 0x800829FC: nop

            goto L_80082A20;
    }
    // 0x800829FC: nop

    // 0x80082A00: addiu       $at, $zero, 0x246
    ctx->r1 = ADD32(0, 0X246);
    // 0x80082A04: beq         $s0, $at, L_80082A74
    if (ctx->r16 == ctx->r1) {
        // 0x80082A08: nop

            goto L_80082A74;
    }
    // 0x80082A08: nop

    // 0x80082A0C: addiu       $at, $zero, 0x247
    ctx->r1 = ADD32(0, 0X247);
    // 0x80082A10: beq         $s0, $at, L_80082AD4
    if (ctx->r16 == ctx->r1) {
        // 0x80082A14: nop

            goto L_80082AD4;
    }
    // 0x80082A14: nop

    // 0x80082A18: b           L_80082B04
    // 0x80082A1C: nop

        goto L_80082B04;
    // 0x80082A1C: nop

L_80082A20:
    // 0x80082A20: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80082A24: nop

    // 0x80082A28: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80082A2C: nop

    // 0x80082A30: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x80082A34: beq         $t2, $zero, L_80082A6C
    if (ctx->r10 == 0) {
        // 0x80082A38: nop

            goto L_80082A6C;
    }
    // 0x80082A38: nop

    // 0x80082A3C: andi        $t3, $t1, 0x4
    ctx->r11 = ctx->r9 & 0X4;
    // 0x80082A40: beq         $t3, $zero, L_80082A6C
    if (ctx->r11 == 0) {
        // 0x80082A44: nop

            goto L_80082A6C;
    }
    // 0x80082A44: nop

    // 0x80082A48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80082A4C: jal         0x80082D18
    // 0x80082A50: addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    func_80082D18(rdram, ctx);
        goto after_1;
    // 0x80082A50: addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    after_1:
    // 0x80082A54: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80082A58: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80082A5C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80082A60: nop

    // 0x80082A64: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80082A68: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
L_80082A6C:
    // 0x80082A6C: b           L_80082B04
    // 0x80082A70: nop

        goto L_80082B04;
    // 0x80082A70: nop

L_80082A74:
    // 0x80082A74: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80082A78: nop

    // 0x80082A7C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80082A80: nop

    // 0x80082A84: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80082A88: beq         $t9, $zero, L_80082ACC
    if (ctx->r25 == 0) {
        // 0x80082A8C: nop

            goto L_80082ACC;
    }
    // 0x80082A8C: nop

    // 0x80082A90: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x80082A94: beq         $t0, $zero, L_80082ACC
    if (ctx->r8 == 0) {
        // 0x80082A98: nop

            goto L_80082ACC;
    }
    // 0x80082A98: nop

    // 0x80082A9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80082AA0: jal         0x80082D18
    // 0x80082AA4: addiu       $a1, $zero, 0x247
    ctx->r5 = ADD32(0, 0X247);
    func_80082D18(rdram, ctx);
        goto after_2;
    // 0x80082AA4: addiu       $a1, $zero, 0x247
    ctx->r5 = ADD32(0, 0X247);
    after_2:
    // 0x80082AA8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082AAC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80082AB0: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x80082AB4: nop

    // 0x80082AB8: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80082ABC: sb          $t3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r11;
    // 0x80082AC0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80082AC4: nop

    // 0x80082AC8: sh          $zero, 0xE($t5)
    MEM_H(0XE, ctx->r13) = 0;
L_80082ACC:
    // 0x80082ACC: b           L_80082B04
    // 0x80082AD0: nop

        goto L_80082B04;
    // 0x80082AD0: nop

L_80082AD4:
    // 0x80082AD4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80082AD8: nop

    // 0x80082ADC: lbu         $t4, 0x0($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X0);
    // 0x80082AE0: nop

    // 0x80082AE4: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80082AE8: beq         $t7, $zero, L_80082AFC
    if (ctx->r15 == 0) {
        // 0x80082AEC: nop

            goto L_80082AFC;
    }
    // 0x80082AEC: nop

    // 0x80082AF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80082AF4: jal         0x80082D18
    // 0x80082AF8: addiu       $a1, $zero, 0x244
    ctx->r5 = ADD32(0, 0X244);
    func_80082D18(rdram, ctx);
        goto after_3;
    // 0x80082AF8: addiu       $a1, $zero, 0x244
    ctx->r5 = ADD32(0, 0X244);
    after_3:
L_80082AFC:
    // 0x80082AFC: b           L_80082B04
    // 0x80082B00: nop

        goto L_80082B04;
    // 0x80082B00: nop

L_80082B04:
    // 0x80082B04: b           L_80082BB0
    // 0x80082B08: nop

        goto L_80082BB0;
    // 0x80082B08: nop

L_80082B0C:
    // 0x80082B0C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80082B10: nop

    // 0x80082B14: lh          $t8, 0xE($t9)
    ctx->r24 = MEM_H(ctx->r25, 0XE);
    // 0x80082B18: nop

    // 0x80082B1C: slti        $at, $t8, 0x259
    ctx->r1 = SIGNED(ctx->r24) < 0X259 ? 1 : 0;
    // 0x80082B20: bne         $at, $zero, L_80082B6C
    if (ctx->r1 != 0) {
        // 0x80082B24: nop

            goto L_80082B6C;
    }
    // 0x80082B24: nop

    // 0x80082B28: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80082B2C: nop

    // 0x80082B30: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80082B34: nop

    // 0x80082B38: andi        $t3, $t1, 0x4
    ctx->r11 = ctx->r9 & 0X4;
    // 0x80082B3C: beq         $t3, $zero, L_80082B58
    if (ctx->r11 == 0) {
        // 0x80082B40: nop

            goto L_80082B58;
    }
    // 0x80082B40: nop

    // 0x80082B44: lh          $t2, 0xE($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XE);
    // 0x80082B48: nop

    // 0x80082B4C: slti        $at, $t2, 0x259
    ctx->r1 = SIGNED(ctx->r10) < 0X259 ? 1 : 0;
    // 0x80082B50: bne         $at, $zero, L_80082B64
    if (ctx->r1 != 0) {
        // 0x80082B54: nop

            goto L_80082B64;
    }
    // 0x80082B54: nop

L_80082B58:
    // 0x80082B58: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80082B5C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80082B60: sh          $t5, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r13;
L_80082B64:
    // 0x80082B64: b           L_80082BA0
    // 0x80082B68: nop

        goto L_80082BA0;
    // 0x80082B68: nop

L_80082B6C:
    // 0x80082B6C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80082B70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082B74: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80082B78: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80082B7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082B80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082B84: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80082B88: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80082B8C: lh          $t7, 0xE($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XE);
    // 0x80082B90: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80082B94: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80082B98: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x80082B9C: sh          $t1, 0xE($t4)
    MEM_H(0XE, ctx->r12) = ctx->r9;
L_80082BA0:
    // 0x80082BA0: b           L_80082BB0
    // 0x80082BA4: nop

        goto L_80082BB0;
    // 0x80082BA4: nop

L_80082BA8:
    // 0x80082BA8: b           L_80082BB0
    // 0x80082BAC: nop

        goto L_80082BB0;
    // 0x80082BAC: nop

L_80082BB0:
    // 0x80082BB0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80082BB4: nop

    // 0x80082BB8: lh          $t0, 0xC($t3)
    ctx->r8 = MEM_H(ctx->r11, 0XC);
    // 0x80082BBC: nop

    // 0x80082BC0: blez        $t0, L_80082BD4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80082BC4: nop

            goto L_80082BD4;
    }
    // 0x80082BC4: nop

    // 0x80082BC8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80082BCC: jal         0x80082DD4
    // 0x80082BD0: nop

    func_80082DD4(rdram, ctx);
        goto after_4;
    // 0x80082BD0: nop

    after_4:
L_80082BD4:
    // 0x80082BD4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082BD8: nop

    // 0x80082BDC: lw          $t5, 0x44($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X44);
    // 0x80082BE0: nop

    // 0x80082BE4: bne         $t5, $zero, L_80082990
    if (ctx->r13 != 0) {
        // 0x80082BE8: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80082990;
    }
    // 0x80082BE8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80082BEC: b           L_80082BF4
    // 0x80082BF0: nop

        goto L_80082BF4;
    // 0x80082BF0: nop

L_80082BF4:
    // 0x80082BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082BF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80082BFC: jr          $ra
    // 0x80082C00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80082C00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80082C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082C0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80082C10: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80082C14: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80082C18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082C1C: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80082C20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80082C24: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80082C28: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80082C2C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80082C30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082C34: lwc1        $f16, 0x10($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80082C38: nop

    // 0x80082C3C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80082C40: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x80082C44: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80082C48: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    // 0x80082C4C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082C50: lwc1        $f18, -0xAEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XAEC);
    // 0x80082C54: lwc1        $f8, 0x10($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80082C58: lwc1        $f19, -0xAF0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XAF0);
    // 0x80082C5C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80082C60: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x80082C64: nop

    // 0x80082C68: bc1f        L_80082C94
    if (!c1cs) {
        // 0x80082C6C: nop

            goto L_80082C94;
    }
    // 0x80082C6C: nop

    // 0x80082C70: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80082C74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082C78: lwc1        $f10, 0x10($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80082C7C: lwc1        $f5, -0xAE8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XAE8);
    // 0x80082C80: lwc1        $f4, -0xAE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XAE4);
    // 0x80082C84: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80082C88: sub.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = ctx->f6.d - ctx->f4.d;
    // 0x80082C8C: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80082C90: swc1        $f16, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f16.u32l;
L_80082C94:
    // 0x80082C94: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082C98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082C9C: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80082CA0: lwc1        $f7, -0xAE0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XAE0);
    // 0x80082CA4: lwc1        $f6, -0xADC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XADC);
    // 0x80082CA8: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80082CAC: mul.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80082CB0: jal         0x800C3070
    // 0x80082CB4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_0;
    // 0x80082CB4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_0:
    // 0x80082CB8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80082CBC: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80082CC0: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80082CC4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80082CC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082CCC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80082CD0: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x80082CD4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80082CD8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80082CDC: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80082CE0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80082CE4: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80082CE8: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x80082CEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082CF0: nop

    // 0x80082CF4: sub.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = ctx->f16.d - ctx->f8.d;
    // 0x80082CF8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80082CFC: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
    // 0x80082D00: b           L_80082D08
    // 0x80082D04: nop

        goto L_80082D08;
    // 0x80082D04: nop

L_80082D08:
    // 0x80082D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082D0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082D10: jr          $ra
    // 0x80082D14: nop

    return;
    // 0x80082D14: nop

;}
RECOMP_FUNC void func_80082D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082D1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80082D20: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80082D24: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80082D28: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80082D2C: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x80082D30: lwc1        $f4, 0x14($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80082D34: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x80082D38: lhu         $a3, 0x2C($t6)
    ctx->r7 = MEM_HU(ctx->r14, 0X2C);
    // 0x80082D3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80082D40: lwc1        $f6, 0x18($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80082D44: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80082D48: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80082D4C: addiu       $a0, $t6, 0x24
    ctx->r4 = ADD32(ctx->r14, 0X24);
    // 0x80082D50: addiu       $a1, $t6, 0x28
    ctx->r5 = ADD32(ctx->r14, 0X28);
    // 0x80082D54: or          $a2, $t8, $t9
    ctx->r6 = ctx->r24 | ctx->r25;
    // 0x80082D58: jal         0x800B202C
    // 0x80082D5C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_0;
    // 0x80082D5C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80082D60: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80082D64: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80082D68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082D6C: beq         $t0, $at, L_80082DA4
    if (ctx->r8 == ctx->r1) {
        // 0x80082D70: nop

            goto L_80082DA4;
    }
    // 0x80082D70: nop

    // 0x80082D74: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80082D78: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80082D7C: nop

    // 0x80082D80: sw          $t1, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r9;
    // 0x80082D84: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x80082D88: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80082D8C: nop

    // 0x80082D90: sh          $t3, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r11;
    // 0x80082D94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80082D98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082D9C: jal         0x8005A5F4
    // 0x80082DA0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8005A5F4(rdram, ctx);
        goto after_1;
    // 0x80082DA0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
L_80082DA4:
    // 0x80082DA4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80082DA8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80082DAC: lbu         $t7, 0x0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X0);
    // 0x80082DB0: nop

    // 0x80082DB4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80082DB8: sb          $t8, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r24;
    // 0x80082DBC: b           L_80082DC4
    // 0x80082DC0: nop

        goto L_80082DC4;
    // 0x80082DC0: nop

L_80082DC4:
    // 0x80082DC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80082DC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80082DCC: jr          $ra
    // 0x80082DD0: nop

    return;
    // 0x80082DD0: nop

;}
RECOMP_FUNC void func_80082DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082DDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80082DE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80082DE4: nop

    // 0x80082DE8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80082DEC: nop

    // 0x80082DF0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80082DF4: beq         $t8, $zero, L_80082E18
    if (ctx->r24 == 0) {
        // 0x80082DF8: nop

            goto L_80082E18;
    }
    // 0x80082DF8: nop

    // 0x80082DFC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082E00: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80082E04: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80082E08: nop

    // 0x80082E0C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80082E10: b           L_80082E80
    // 0x80082E14: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
        goto L_80082E80;
    // 0x80082E14: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
L_80082E18:
    // 0x80082E18: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80082E1C: nop

    // 0x80082E20: addiu       $a0, $t2, 0x24
    ctx->r4 = ADD32(ctx->r10, 0X24);
    // 0x80082E24: jal         0x800B2748
    // 0x80082E28: addiu       $a1, $t2, 0x28
    ctx->r5 = ADD32(ctx->r10, 0X28);
    func_800B2748(rdram, ctx);
        goto after_0;
    // 0x80082E28: addiu       $a1, $t2, 0x28
    ctx->r5 = ADD32(ctx->r10, 0X28);
    after_0:
    // 0x80082E2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80082E30: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80082E34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082E38: beq         $t3, $at, L_80082E68
    if (ctx->r11 == ctx->r1) {
        // 0x80082E3C: nop

            goto L_80082E68;
    }
    // 0x80082E3C: nop

    // 0x80082E40: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80082E44: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80082E48: nop

    // 0x80082E4C: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
    // 0x80082E50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80082E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082E58: jal         0x8005A5F4
    // 0x80082E5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8005A5F4(rdram, ctx);
        goto after_1;
    // 0x80082E5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x80082E60: b           L_80082E80
    // 0x80082E64: nop

        goto L_80082E80;
    // 0x80082E64: nop

L_80082E68:
    // 0x80082E68: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80082E6C: nop

    // 0x80082E70: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80082E74: nop

    // 0x80082E78: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80082E7C: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
L_80082E80:
    // 0x80082E80: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80082E84: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80082E88: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80082E8C: nop

    // 0x80082E90: blez        $t1, L_80083074
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80082E94: nop

            goto L_80083074;
    }
    // 0x80082E94: nop

L_80082E98:
    // 0x80082E98: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80082E9C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082EA0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80082EA4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80082EA8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082EAC: lw          $t2, 0x24($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X24);
    // 0x80082EB0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80082EB4: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80082EB8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80082EBC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80082EC0: swc1        $f4, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f4.u32l;
    // 0x80082EC4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80082EC8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082ECC: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80082ED0: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80082ED4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80082ED8: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80082EDC: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80082EE0: lwc1        $f6, 0x18($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X18);
    // 0x80082EE4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80082EE8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80082EEC: swc1        $f6, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f6.u32l;
    // 0x80082EF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80082EF4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082EF8: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80082EFC: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80082F00: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082F04: lw          $t3, 0x24($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X24);
    // 0x80082F08: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80082F0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082F10: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80082F14: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80082F18: swc1        $f8, 0xD4($t5)
    MEM_W(0XD4, ctx->r13) = ctx->f8.u32l;
    // 0x80082F1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80082F20: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082F24: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80082F28: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80082F2C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80082F30: lw          $t6, 0x24($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X24);
    // 0x80082F34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80082F38: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80082F3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082F40: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80082F44: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x80082F48: swc1        $f10, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f10.u32l;
    // 0x80082F4C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80082F50: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082F54: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80082F58: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80082F5C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082F60: lw          $t2, 0x24($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X24);
    // 0x80082F64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80082F68: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80082F6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80082F70: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80082F74: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80082F78: swc1        $f16, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f16.u32l;
    // 0x80082F7C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80082F80: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082F84: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80082F88: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80082F8C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80082F90: lw          $t6, 0x24($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X24);
    // 0x80082F94: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80082F98: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80082F9C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80082FA0: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x80082FA4: sh          $t8, 0x11E($t9)
    MEM_H(0X11E, ctx->r25) = ctx->r24;
    // 0x80082FA8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80082FAC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80082FB0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80082FB4: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80082FB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80082FBC: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x80082FC0: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80082FC4: lw          $t2, 0x38($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X38);
    // 0x80082FC8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80082FCC: addu        $t0, $t4, $t7
    ctx->r8 = ADD32(ctx->r12, ctx->r15);
    // 0x80082FD0: sw          $t2, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->r10;
    // 0x80082FD4: jal         0x800C1754
    // 0x80082FD8: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_2;
    // 0x80082FD8: nop

    after_2:
    // 0x80082FDC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80082FE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80082FE4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80082FE8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80082FEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80082FF0: lw          $t1, 0x24($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X24);
    // 0x80082FF4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80082FF8: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80082FFC: jal         0x8009A14C
    // 0x80083000: addu        $a0, $t1, $t9
    ctx->r4 = ADD32(ctx->r9, ctx->r25);
    func_8009A14C(rdram, ctx);
        goto after_3;
    // 0x80083000: addu        $a0, $t1, $t9
    ctx->r4 = ADD32(ctx->r9, ctx->r25);
    after_3:
    // 0x80083004: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80083008: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8008300C: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x80083010: nop

    // 0x80083014: andi        $t4, $t5, 0x200
    ctx->r12 = ctx->r13 & 0X200;
    // 0x80083018: bne         $t4, $zero, L_80083048
    if (ctx->r12 != 0) {
        // 0x8008301C: nop

            goto L_80083048;
    }
    // 0x8008301C: nop

    // 0x80083020: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80083024: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80083028: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8008302C: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x80083030: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083034: lw          $t2, 0x24($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X24);
    // 0x80083038: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x8008303C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80083040: jal         0x800997D8
    // 0x80083044: addu        $a0, $t2, $t6
    ctx->r4 = ADD32(ctx->r10, ctx->r14);
    func_800997D8(rdram, ctx);
        goto after_4;
    // 0x80083044: addu        $a0, $t2, $t6
    ctx->r4 = ADD32(ctx->r10, ctx->r14);
    after_4:
L_80083048:
    // 0x80083048: jal         0x800C1A28
    // 0x8008304C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_5;
    // 0x8008304C: nop

    after_5:
    // 0x80083050: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80083054: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80083058: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x8008305C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083060: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80083064: nop

    // 0x80083068: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8008306C: bne         $at, $zero, L_80082E98
    if (ctx->r1 != 0) {
        // 0x80083070: nop

            goto L_80082E98;
    }
    // 0x80083070: nop

L_80083074:
    // 0x80083074: b           L_8008307C
    // 0x80083078: nop

        goto L_8008307C;
    // 0x80083078: nop

L_8008307C:
    // 0x8008307C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083084: jr          $ra
    // 0x80083088: nop

    return;
    // 0x80083088: nop

;}
RECOMP_FUNC void func_8008308C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008308C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80083090: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083094: lw          $t6, 0x165C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X165C);
    // 0x80083098: nop

    // 0x8008309C: bne         $t6, $zero, L_800830AC
    if (ctx->r14 != 0) {
        // 0x800830A0: nop

            goto L_800830AC;
    }
    // 0x800830A0: nop

    // 0x800830A4: b           L_80083124
    // 0x800830A8: nop

        goto L_80083124;
    // 0x800830A8: nop

L_800830AC:
    // 0x800830AC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800830B0: lw          $t7, 0x165C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X165C);
    // 0x800830B4: nop

    // 0x800830B8: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_800830BC:
    // 0x800830BC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800830C0: nop

    // 0x800830C4: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x800830C8: nop

    // 0x800830CC: bne         $t9, $a0, L_80083104
    if (ctx->r25 != ctx->r4) {
        // 0x800830D0: nop

            goto L_80083104;
    }
    // 0x800830D0: nop

    // 0x800830D4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800830D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800830DC: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x800830E0: nop

    // 0x800830E4: bne         $t1, $at, L_80083104
    if (ctx->r9 != ctx->r1) {
        // 0x800830E8: nop

            goto L_80083104;
    }
    // 0x800830E8: nop

    // 0x800830EC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800830F0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800830F4: sh          $t2, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r10;
    // 0x800830F8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800830FC: nop

    // 0x80083100: sh          $zero, 0xE($t4)
    MEM_H(0XE, ctx->r12) = 0;
L_80083104:
    // 0x80083104: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80083108: nop

    // 0x8008310C: lw          $t6, 0x44($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X44);
    // 0x80083110: nop

    // 0x80083114: bne         $t6, $zero, L_800830BC
    if (ctx->r14 != 0) {
        // 0x80083118: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800830BC;
    }
    // 0x80083118: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008311C: b           L_80083124
    // 0x80083120: nop

        goto L_80083124;
    // 0x80083120: nop

L_80083124:
    // 0x80083124: jr          $ra
    // 0x80083128: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80083128: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008312C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008312C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80083130: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083134: lw          $t6, 0x165C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X165C);
    // 0x80083138: nop

    // 0x8008313C: bne         $t6, $zero, L_8008314C
    if (ctx->r14 != 0) {
        // 0x80083140: nop

            goto L_8008314C;
    }
    // 0x80083140: nop

    // 0x80083144: b           L_800831D8
    // 0x80083148: nop

        goto L_800831D8;
    // 0x80083148: nop

L_8008314C:
    // 0x8008314C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80083150: lw          $t7, 0x165C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X165C);
    // 0x80083154: nop

    // 0x80083158: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_8008315C:
    // 0x8008315C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80083160: nop

    // 0x80083164: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x80083168: nop

    // 0x8008316C: bne         $t9, $a0, L_800831B8
    if (ctx->r25 != ctx->r4) {
        // 0x80083170: nop

            goto L_800831B8;
    }
    // 0x80083170: nop

    // 0x80083174: beq         $a2, $zero, L_80083198
    if (ctx->r6 == 0) {
        // 0x80083178: nop

            goto L_80083198;
    }
    // 0x80083178: nop

    // 0x8008317C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80083180: nop

    // 0x80083184: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80083188: nop

    // 0x8008318C: or          $t2, $t1, $a1
    ctx->r10 = ctx->r9 | ctx->r5;
    // 0x80083190: b           L_800831B0
    // 0x80083194: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
        goto L_800831B0;
    // 0x80083194: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
L_80083198:
    // 0x80083198: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008319C: nor         $t5, $a1, $zero
    ctx->r13 = ~(ctx->r5 | 0);
    // 0x800831A0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800831A4: nop

    // 0x800831A8: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x800831AC: sb          $t6, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r14;
L_800831B0:
    // 0x800831B0: b           L_800831D0
    // 0x800831B4: nop

        goto L_800831D0;
    // 0x800831B4: nop

L_800831B8:
    // 0x800831B8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800831BC: nop

    // 0x800831C0: lw          $t8, 0x44($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X44);
    // 0x800831C4: nop

    // 0x800831C8: bne         $t8, $zero, L_8008315C
    if (ctx->r24 != 0) {
        // 0x800831CC: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_8008315C;
    }
    // 0x800831CC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_800831D0:
    // 0x800831D0: b           L_800831D8
    // 0x800831D4: nop

        goto L_800831D8;
    // 0x800831D4: nop

L_800831D8:
    // 0x800831D8: jr          $ra
    // 0x800831DC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800831DC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800831E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800831E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800831E8: jal         0x800BC6EC
    // 0x800831EC: addiu       $a0, $zero, 0xC30
    ctx->r4 = ADD32(0, 0XC30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800831EC: addiu       $a0, $zero, 0xC30
    ctx->r4 = ADD32(0, 0XC30);
    after_0:
    // 0x800831F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800831F4: sw          $v0, 0x7B4C($at)
    MEM_W(0X7B4C, ctx->r1) = ctx->r2;
    // 0x800831F8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800831FC: lh          $t6, 0x72AC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72AC);
    // 0x80083200: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80083204: bne         $t6, $at, L_80083244
    if (ctx->r14 != ctx->r1) {
        // 0x80083208: nop

            goto L_80083244;
    }
    // 0x80083208: nop

    // 0x8008320C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80083210: lh          $t7, 0x72B4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X72B4);
    // 0x80083214: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80083218: bne         $t7, $at, L_80083244
    if (ctx->r15 != ctx->r1) {
        // 0x8008321C: nop

            goto L_80083244;
    }
    // 0x8008321C: nop

    // 0x80083220: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083224: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083228: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8008322C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80083230: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083234: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x80083238: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008323C: b           L_8008326C
    // 0x80083240: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
        goto L_8008326C;
    // 0x80083240: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
L_80083244:
    // 0x80083244: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083248: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x8008324C: nop

    // 0x80083250: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x80083254: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083258: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x8008325C: nop

    // 0x80083260: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x80083264: jal         0x80021ED0
    // 0x80083268: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_1;
    // 0x80083268: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_1:
L_8008326C:
    // 0x8008326C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083270: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083274: nop

    // 0x80083278: sh          $zero, 0x2($t4)
    MEM_H(0X2, ctx->r12) = 0;
    // 0x8008327C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083280: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083284: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x80083288: jal         0x8008A964
    // 0x8008328C: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_8008A964(rdram, ctx);
        goto after_2;
    // 0x8008328C: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_2:
    // 0x80083290: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083294: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083298: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x8008329C: jal         0x8008A964
    // 0x800832A0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_8008A964(rdram, ctx);
        goto after_3;
    // 0x800832A0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_3:
    // 0x800832A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800832A8: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x800832AC: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x800832B0: jal         0x8008A964
    // 0x800832B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_8008A964(rdram, ctx);
        goto after_4;
    // 0x800832B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_4:
    // 0x800832B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800832BC: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x800832C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800832C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800832C8: swc1        $f4, 0x744($t5)
    MEM_W(0X744, ctx->r13) = ctx->f4.u32l;
    // 0x800832CC: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x800832D0: nop

    // 0x800832D4: lwc1        $f6, 0x744($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X744);
    // 0x800832D8: nop

    // 0x800832DC: swc1        $f6, 0x740($t6)
    MEM_W(0X740, ctx->r14) = ctx->f6.u32l;
    // 0x800832E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800832E4: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800832E8: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x800832EC: lwc1        $f8, 0x740($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X740);
    // 0x800832F0: ori         $a2, $a2, 0x229
    ctx->r6 = ctx->r6 | 0X229;
    // 0x800832F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800832F8: lwc1        $f10, 0x744($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X744);
    // 0x800832FC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80083300: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x80083304: addiu       $a0, $t7, 0x3C
    ctx->r4 = ADD32(ctx->r15, 0X3C);
    // 0x80083308: addiu       $a1, $t7, 0x40
    ctx->r5 = ADD32(ctx->r15, 0X40);
    // 0x8008330C: jal         0x800B202C
    // 0x80083310: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B202C(rdram, ctx);
        goto after_5;
    // 0x80083310: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80083314: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083318: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x8008331C: nop

    // 0x80083320: sh          $v0, 0x46($t8)
    MEM_H(0X46, ctx->r24) = ctx->r2;
    // 0x80083324: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083328: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x8008332C: nop

    // 0x80083330: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80083334: nop

    // 0x80083338: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x8008333C: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x80083340: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083344: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008334C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80083350: jal         0x8008AAA8
    // 0x80083354: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_8008AAA8(rdram, ctx);
        goto after_6;
    // 0x80083354: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_6:
    // 0x80083358: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008335C: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x80083360: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80083364: sh          $t2, 0x160($t3)
    MEM_H(0X160, ctx->r11) = ctx->r10;
    // 0x80083368: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008336C: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083370: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083374: sh          $zero, 0x164($t4)
    MEM_H(0X164, ctx->r12) = 0;
    // 0x80083378: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x8008337C: nop

    // 0x80083380: lh          $t6, 0x164($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X164);
    // 0x80083384: nop

    // 0x80083388: sh          $t6, 0x162($t5)
    MEM_H(0X162, ctx->r13) = ctx->r14;
    // 0x8008338C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083390: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083394: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80083398: sw          $t7, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->r15;
    // 0x8008339C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800833A0:
    // 0x800833A0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800833A4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800833A8: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x800833AC: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x800833B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800833B4: lw          $t0, 0x7B4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B4C);
    // 0x800833B8: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x800833BC: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800833C0: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    // 0x800833C4: addiu       $a0, $a0, 0x1A8
    ctx->r4 = ADD32(ctx->r4, 0X1A8);
    // 0x800833C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800833CC: jal         0x8008AAA8
    // 0x800833D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8008AAA8(rdram, ctx);
        goto after_7;
    // 0x800833D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800833D4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800833D8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800833DC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800833E0: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800833E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800833E8: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x800833EC: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800833F0: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800833F4: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x800833F8: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x800833FC: sh          $t2, 0x2C2($t5)
    MEM_H(0X2C2, ctx->r13) = ctx->r10;
    // 0x80083400: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80083404: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083408: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8008340C: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80083410: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80083414: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083418: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8008341C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80083420: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80083424: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80083428: sh          $t7, 0x2C4($t9)
    MEM_H(0X2C4, ctx->r25) = ctx->r15;
    // 0x8008342C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80083430: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083434: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80083438: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x8008343C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083440: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083444: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80083448: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8008344C: addu        $t2, $t4, $t6
    ctx->r10 = ADD32(ctx->r12, ctx->r14);
    // 0x80083450: sh          $zero, 0x2C0($t2)
    MEM_H(0X2C0, ctx->r10) = 0;
    // 0x80083454: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80083458: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008345C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80083460: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x80083464: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80083468: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x8008346C: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x80083470: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80083474: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x80083478: lw          $t7, 0x268($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X268);
    // 0x8008347C: nop

    // 0x80083480: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x80083484: sw          $t9, 0x268($t0)
    MEM_W(0X268, ctx->r8) = ctx->r25;
    // 0x80083488: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008348C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083490: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80083494: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x80083498: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008349C: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x800834A0: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x800834A4: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800834A8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800834AC: addu        $t1, $t4, $t2
    ctx->r9 = ADD32(ctx->r12, ctx->r10);
    // 0x800834B0: sw          $t3, 0x270($t1)
    MEM_W(0X270, ctx->r9) = ctx->r11;
    // 0x800834B4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800834B8: nop

    // 0x800834BC: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800834C0: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800834C4: bne         $at, $zero, L_800833A0
    if (ctx->r1 != 0) {
        // 0x800834C8: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_800833A0;
    }
    // 0x800834C8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800834CC: jal         0x800BC6EC
    // 0x800834D0: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x800834D0: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    after_8:
    // 0x800834D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800834D8: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800834DC: nop

    // 0x800834E0: sw          $v0, 0x728($t7)
    MEM_W(0X728, ctx->r15) = ctx->r2;
    // 0x800834E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800834E8: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x800834EC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800834F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800834F4: lw          $t0, 0x728($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X728);
    // 0x800834F8: nop

    // 0x800834FC: swc1        $f16, 0x1B0($t0)
    MEM_W(0X1B0, ctx->r8) = ctx->f16.u32l;
    // 0x80083500: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083504: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083508: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x8008350C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80083510: lw          $t4, 0x728($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X728);
    // 0x80083514: nop

    // 0x80083518: swc1        $f18, 0x1B4($t4)
    MEM_W(0X1B4, ctx->r12) = ctx->f18.u32l;
    // 0x8008351C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083520: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083524: nop

    // 0x80083528: lw          $a0, 0x728($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X728);
    // 0x8008352C: jal         0x8001A690
    // 0x80083530: nop

    func_8001A690(rdram, ctx);
        goto after_9;
    // 0x80083530: nop

    after_9:
    // 0x80083534: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083538: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x8008353C: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80083540: lw          $t5, 0x728($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X728);
    // 0x80083544: nop

    // 0x80083548: sh          $t3, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r11;
    // 0x8008354C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083550: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083554: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80083558: lw          $t7, 0x728($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X728);
    // 0x8008355C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083560: swc1        $f4, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f4.u32l;
    // 0x80083564: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083568: nop

    // 0x8008356C: lw          $t0, 0x728($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X728);
    // 0x80083570: nop

    // 0x80083574: lwc1        $f6, 0xD0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80083578: nop

    // 0x8008357C: swc1        $f6, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f6.u32l;
    // 0x80083580: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083584: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083588: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8008358C: lw          $t2, 0x728($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X728);
    // 0x80083590: nop

    // 0x80083594: sw          $t6, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r14;
    // 0x80083598: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008359C: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x800835A0: nop

    // 0x800835A4: lw          $a0, 0x728($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X728);
    // 0x800835A8: jal         0x8008C0A4
    // 0x800835AC: nop

    func_8008C0A4(rdram, ctx);
        goto after_10;
    // 0x800835AC: nop

    after_10:
    // 0x800835B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800835B4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x800835B8: jal         0x8008ABB4
    // 0x800835BC: nop

    func_8008ABB4(rdram, ctx);
        goto after_11;
    // 0x800835BC: nop

    after_11:
    // 0x800835C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800835C4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x800835C8: jal         0x8008AD88
    // 0x800835CC: nop

    func_8008AD88(rdram, ctx);
        goto after_12;
    // 0x800835CC: nop

    after_12:
    // 0x800835D0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800835D4: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x800835D8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800835DC: sh          $t3, 0x73C($t5)
    MEM_H(0X73C, ctx->r13) = ctx->r11;
    // 0x800835E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800835E4: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x800835E8: nop

    // 0x800835EC: sh          $zero, 0xBD8($t8)
    MEM_H(0XBD8, ctx->r24) = 0;
    // 0x800835F0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800835F4: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800835F8: nop

    // 0x800835FC: sh          $zero, 0xBEC($t7)
    MEM_H(0XBEC, ctx->r15) = 0;
    // 0x80083600: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80083604:
    // 0x80083604: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80083608: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008360C: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083610: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80083614: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x80083618: sw          $zero, 0xC04($t6)
    MEM_W(0XC04, ctx->r14) = 0;
    // 0x8008361C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80083620: nop

    // 0x80083624: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x80083628: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8008362C: bne         $at, $zero, L_80083604
    if (ctx->r1 != 0) {
        // 0x80083630: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80083604;
    }
    // 0x80083630: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80083634: jal         0x800BC6EC
    // 0x80083638: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_13;
    // 0x80083638: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    after_13:
    // 0x8008363C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083640: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x80083644: nop

    // 0x80083648: sw          $v0, 0xC10($t3)
    MEM_W(0XC10, ctx->r11) = ctx->r2;
    // 0x8008364C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083650: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083654: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80083658: nop

    // 0x8008365C: swc1        $f8, 0xBD4($t5)
    MEM_W(0XBD4, ctx->r13) = ctx->f8.u32l;
    // 0x80083660: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80083664: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083668: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x8008366C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083670: nop

    // 0x80083674: swc1        $f10, 0xC24($t8)
    MEM_W(0XC24, ctx->r24) = ctx->f10.u32l;
    // 0x80083678: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8008367C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80083680: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x80083684: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80083688: nop

    // 0x8008368C: swc1        $f16, 0xC28($t7)
    MEM_W(0XC28, ctx->r15) = ctx->f16.u32l;
    // 0x80083690: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80083694: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80083698: lhu         $t9, 0x4($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X4);
    // 0x8008369C: addiu       $at, $zero, -0x19
    ctx->r1 = ADD32(0, -0X19);
    // 0x800836A0: and         $t4, $t9, $at
    ctx->r12 = ctx->r25 & ctx->r1;
    // 0x800836A4: sh          $t4, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r12;
    // 0x800836A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800836AC: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800836B0: lhu         $t2, 0x4($t6)
    ctx->r10 = MEM_HU(ctx->r14, 0X4);
    // 0x800836B4: nop

    // 0x800836B8: ori         $t1, $t2, 0x1
    ctx->r9 = ctx->r10 | 0X1;
    // 0x800836BC: sh          $t1, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r9;
    // 0x800836C0: jal         0x8003168C
    // 0x800836C4: nop

    func_8003168C(rdram, ctx);
        goto after_14;
    // 0x800836C4: nop

    after_14:
    // 0x800836C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800836CC: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x800836D0: jal         0x80088CC4
    // 0x800836D4: nop

    func_80088CC4(rdram, ctx);
        goto after_15;
    // 0x800836D4: nop

    after_15:
    // 0x800836D8: jal         0x80031C34
    // 0x800836DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80031C34(rdram, ctx);
        goto after_16;
    // 0x800836DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x800836E0: b           L_800836F0
    // 0x800836E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800836F0;
    // 0x800836E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800836E8: b           L_800836F0
    // 0x800836EC: nop

        goto L_800836F0;
    // 0x800836EC: nop

L_800836F0:
    // 0x800836F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800836F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800836F8: jr          $ra
    // 0x800836FC: nop

    return;
    // 0x800836FC: nop

;}
RECOMP_FUNC void func_80083700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083708: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008370C: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083710: nop

    // 0x80083714: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80083718: nop

    // 0x8008371C: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80083720: beq         $t8, $zero, L_8008375C
    if (ctx->r24 == 0) {
        // 0x80083724: nop

            goto L_8008375C;
    }
    // 0x80083724: nop

    // 0x80083728: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008372C: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083730: jal         0x80088F50
    // 0x80083734: nop

    func_80088F50(rdram, ctx);
        goto after_0;
    // 0x80083734: nop

    after_0:
    // 0x80083738: beq         $v0, $zero, L_8008375C
    if (ctx->r2 == 0) {
        // 0x8008373C: nop

            goto L_8008375C;
    }
    // 0x8008373C: nop

    // 0x80083740: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083744: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083748: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8008374C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80083750: nop

    // 0x80083754: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80083758: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_8008375C:
    // 0x8008375C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083760: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083764: jal         0x8008AF5C
    // 0x80083768: nop

    func_8008AF5C(rdram, ctx);
        goto after_1;
    // 0x80083768: nop

    after_1:
    // 0x8008376C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083770: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083774: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80083778: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x8008377C: nop

    // 0x80083780: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80083784: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80083788: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008378C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80083790: lw          $t5, 0x4538($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4538);
    // 0x80083794: nop

    // 0x80083798: beq         $t5, $zero, L_8008383C
    if (ctx->r13 == 0) {
        // 0x8008379C: nop

            goto L_8008383C;
    }
    // 0x8008379C: nop

    // 0x800837A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800837A4: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x800837A8: nop

    // 0x800837AC: lw          $a0, 0x728($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X728);
    // 0x800837B0: jal         0x8001ABEC
    // 0x800837B4: nop

    func_8001ABEC(rdram, ctx);
        goto after_2;
    // 0x800837B4: nop

    after_2:
    // 0x800837B8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800837BC: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800837C0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800837C4: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x800837C8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800837CC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800837D0: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800837D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800837D8: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x800837DC: lw          $t9, 0x4538($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4538);
    // 0x800837E0: nop

    // 0x800837E4: jalr        $t9
    // 0x800837E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800837E8: nop

    after_3:
    // 0x800837EC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800837F0: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x800837F4: nop

    // 0x800837F8: lw          $t2, 0x728($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X728);
    // 0x800837FC: nop

    // 0x80083800: lw          $t3, 0x138($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X138);
    // 0x80083804: nop

    // 0x80083808: sh          $zero, 0x20($t3)
    MEM_H(0X20, ctx->r11) = 0;
    // 0x8008380C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083810: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083814: nop

    // 0x80083818: lw          $a0, 0x728($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X728);
    // 0x8008381C: jal         0x8001ACDC
    // 0x80083820: nop

    func_8001ACDC(rdram, ctx);
        goto after_4;
    // 0x80083820: nop

    after_4:
    // 0x80083824: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083828: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x8008382C: nop

    // 0x80083830: lw          $a0, 0x728($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X728);
    // 0x80083834: jal         0x8001ADBC
    // 0x80083838: nop

    func_8001ADBC(rdram, ctx);
        goto after_5;
    // 0x80083838: nop

    after_5:
L_8008383C:
    // 0x8008383C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083840: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083844: jal         0x8008CC08
    // 0x80083848: nop

    func_8008CC08(rdram, ctx);
        goto after_6;
    // 0x80083848: nop

    after_6:
    // 0x8008384C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083850: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083854: jal         0x80089BA4
    // 0x80083858: nop

    func_80089BA4(rdram, ctx);
        goto after_7;
    // 0x80083858: nop

    after_7:
    // 0x8008385C: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x80083860: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083864: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083868: nop

    // 0x8008386C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80083870: nop

    // 0x80083874: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80083878: bne         $t8, $zero, L_800838F4
    if (ctx->r24 != 0) {
        // 0x8008387C: nop

            goto L_800838F4;
    }
    // 0x8008387C: nop

    // 0x80083880: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80083884: lw          $t0, 0x7B4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B4C);
    // 0x80083888: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008388C: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
    // 0x80083890: nop

    // 0x80083894: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80083898: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8008389C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800838A0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800838A4: lw          $t2, 0x4534($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4534);
    // 0x800838A8: nop

    // 0x800838AC: beq         $t2, $zero, L_800838EC
    if (ctx->r10 == 0) {
        // 0x800838B0: nop

            goto L_800838EC;
    }
    // 0x800838B0: nop

    // 0x800838B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800838B8: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x800838BC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800838C0: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x800838C4: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x800838C8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800838CC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800838D0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800838D4: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800838D8: lw          $t9, 0x4534($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4534);
    // 0x800838DC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800838E0: jalr        $t9
    // 0x800838E4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800838E4: nop

    after_8:
    // 0x800838E8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_800838EC:
    // 0x800838EC: b           L_8008390C
    // 0x800838F0: nop

        goto L_8008390C;
    // 0x800838F0: nop

L_800838F4:
    // 0x800838F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800838F8: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x800838FC: nop

    // 0x80083900: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80083904: nop

    // 0x80083908: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
L_8008390C:
    // 0x8008390C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083910: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083914: jal         0x8008A808
    // 0x80083918: nop

    func_8008A808(rdram, ctx);
        goto after_9;
    // 0x80083918: nop

    after_9:
    // 0x8008391C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083920: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083924: nop

    // 0x80083928: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x8008392C: nop

    // 0x80083930: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80083934: beq         $t1, $zero, L_8008394C
    if (ctx->r9 == 0) {
        // 0x80083938: nop

            goto L_8008394C;
    }
    // 0x80083938: nop

    // 0x8008393C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083940: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083944: jal         0x8008B108
    // 0x80083948: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_8008B108(rdram, ctx);
        goto after_10;
    // 0x80083948: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_10:
L_8008394C:
    // 0x8008394C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083950: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083954: nop

    // 0x80083958: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8008395C: nop

    // 0x80083960: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80083964: beq         $t4, $zero, L_8008397C
    if (ctx->r12 == 0) {
        // 0x80083968: nop

            goto L_8008397C;
    }
    // 0x80083968: nop

    // 0x8008396C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083970: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083974: jal         0x8008B108
    // 0x80083978: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_8008B108(rdram, ctx);
        goto after_11;
    // 0x80083978: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_11:
L_8008397C:
    // 0x8008397C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083980: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083984: nop

    // 0x80083988: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x8008398C: nop

    // 0x80083990: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x80083994: beq         $t6, $zero, L_800839E4
    if (ctx->r14 == 0) {
        // 0x80083998: nop

            goto L_800839E4;
    }
    // 0x80083998: nop

    // 0x8008399C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800839A0:
    // 0x800839A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800839A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800839A8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800839AC: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800839B0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800839B4: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800839B8: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800839BC: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x800839C0: addu        $a0, $t7, $t0
    ctx->r4 = ADD32(ctx->r15, ctx->r8);
    // 0x800839C4: jal         0x8008B18C
    // 0x800839C8: addiu       $a0, $a0, 0x1A8
    ctx->r4 = ADD32(ctx->r4, 0X1A8);
    func_8008B18C(rdram, ctx);
        goto after_12;
    // 0x800839C8: addiu       $a0, $a0, 0x1A8
    ctx->r4 = ADD32(ctx->r4, 0X1A8);
    after_12:
    // 0x800839CC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800839D0: nop

    // 0x800839D4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800839D8: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x800839DC: bne         $at, $zero, L_800839A0
    if (ctx->r1 != 0) {
        // 0x800839E0: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_800839A0;
    }
    // 0x800839E0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800839E4:
    // 0x800839E4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800839E8: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x800839EC: nop

    // 0x800839F0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800839F4: nop

    // 0x800839F8: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800839FC: beq         $t5, $zero, L_80083A1C
    if (ctx->r13 == 0) {
        // 0x80083A00: nop

            goto L_80083A1C;
    }
    // 0x80083A00: nop

    // 0x80083A04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083A08: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083A0C: nop

    // 0x80083A10: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80083A14: jal         0x8008B1D8
    // 0x80083A18: addiu       $a1, $t9, 0x48
    ctx->r5 = ADD32(ctx->r25, 0X48);
    func_8008B1D8(rdram, ctx);
        goto after_13;
    // 0x80083A18: addiu       $a1, $t9, 0x48
    ctx->r5 = ADD32(ctx->r25, 0X48);
    after_13:
L_80083A1C:
    // 0x80083A1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083A20: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083A24: nop

    // 0x80083A28: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80083A2C: nop

    // 0x80083A30: andi        $t7, $t8, 0x2
    ctx->r15 = ctx->r24 & 0X2;
    // 0x80083A34: beq         $t7, $zero, L_80083A4C
    if (ctx->r15 == 0) {
        // 0x80083A38: nop

            goto L_80083A4C;
    }
    // 0x80083A38: nop

    // 0x80083A3C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083A40: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083A44: jal         0x8008B108
    // 0x80083A48: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_8008B108(rdram, ctx);
        goto after_14;
    // 0x80083A48: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_14:
L_80083A4C:
    // 0x80083A4C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083A50: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x80083A54: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x80083A58: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80083A5C: nop

    // 0x80083A60: beq         $t0, $t2, L_80083AB0
    if (ctx->r8 == ctx->r10) {
        // 0x80083A64: nop

            goto L_80083AB0;
    }
    // 0x80083A64: nop

    // 0x80083A68: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083A6C: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083A70: lh          $t3, 0x1E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X1E);
    // 0x80083A74: nop

    // 0x80083A78: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x80083A7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083A80: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083A84: jal         0x80088DF4
    // 0x80083A88: nop

    func_80088DF4(rdram, ctx);
        goto after_15;
    // 0x80083A88: nop

    after_15:
    // 0x80083A8C: bne         $v0, $zero, L_80083AB0
    if (ctx->r2 != 0) {
        // 0x80083A90: nop

            goto L_80083AB0;
    }
    // 0x80083A90: nop

    // 0x80083A94: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083A98: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083A9C: nop

    // 0x80083AA0: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x80083AA4: nop

    // 0x80083AA8: ori         $t6, $t9, 0x40
    ctx->r14 = ctx->r25 | 0X40;
    // 0x80083AAC: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_80083AB0:
    // 0x80083AB0: b           L_80083AC0
    // 0x80083AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80083AC0;
    // 0x80083AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80083AB8: b           L_80083AC0
    // 0x80083ABC: nop

        goto L_80083AC0;
    // 0x80083ABC: nop

L_80083AC0:
    // 0x80083AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083AC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083AC8: jr          $ra
    // 0x80083ACC: nop

    return;
    // 0x80083ACC: nop

;}
RECOMP_FUNC void func_80083AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80083AD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80083AD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80083ADC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083AE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80083AE4: sh          $t6, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r14;
    // 0x80083AE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80083AEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80083AF0: sh          $t7, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r15;
    // 0x80083AF4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083AF8: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083AFC: nop

    // 0x80083B00: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80083B04: nop

    // 0x80083B08: andi        $t0, $t9, 0x800
    ctx->r8 = ctx->r25 & 0X800;
    // 0x80083B0C: beq         $t0, $zero, L_80083B30
    if (ctx->r8 == 0) {
        // 0x80083B10: nop

            goto L_80083B30;
    }
    // 0x80083B10: nop

    // 0x80083B14: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80083B18: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80083B1C: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x80083B20: nop

    // 0x80083B24: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80083B28: b           L_80083B48
    // 0x80083B2C: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
        goto L_80083B48;
    // 0x80083B2C: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
L_80083B30:
    // 0x80083B30: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80083B34: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80083B38: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80083B3C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80083B40: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80083B44: sh          $t6, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r14;
L_80083B48:
    // 0x80083B48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80083B4C: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x80083B50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80083B54: lh          $s0, 0xBEC($t7)
    ctx->r16 = MEM_H(ctx->r15, 0XBEC);
    // 0x80083B58: nop

    // 0x80083B5C: beq         $s0, $at, L_80083B78
    if (ctx->r16 == ctx->r1) {
        // 0x80083B60: nop

            goto L_80083B78;
    }
    // 0x80083B60: nop

    // 0x80083B64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80083B68: beq         $s0, $at, L_80083B8C
    if (ctx->r16 == ctx->r1) {
        // 0x80083B6C: nop

            goto L_80083B8C;
    }
    // 0x80083B6C: nop

    // 0x80083B70: b           L_80083BA0
    // 0x80083B74: nop

        goto L_80083BA0;
    // 0x80083B74: nop

L_80083B78:
    // 0x80083B78: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x80083B7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80083B80: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x80083B84: b           L_80083BB0
    // 0x80083B88: nop

        goto L_80083BB0;
    // 0x80083B88: nop

L_80083B8C:
    // 0x80083B8C: addiu       $t9, $zero, 0x1F6
    ctx->r25 = ADD32(0, 0X1F6);
    // 0x80083B90: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80083B94: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
    // 0x80083B98: b           L_80083BB0
    // 0x80083B9C: nop

        goto L_80083BB0;
    // 0x80083B9C: nop

L_80083BA0:
    // 0x80083BA0: jal         0x80083F28
    // 0x80083BA4: nop

    func_80083F28(rdram, ctx);
        goto after_0;
    // 0x80083BA4: nop

    after_0:
    // 0x80083BA8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80083BAC: sh          $v0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r2;
L_80083BB0:
    // 0x80083BB0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083BB4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083BB8: jal         0x8008AA44
    // 0x80083BBC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_8008AA44(rdram, ctx);
        goto after_1;
    // 0x80083BBC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_1:
    // 0x80083BC0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083BC4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083BC8: jal         0x8008AA44
    // 0x80083BCC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_8008AA44(rdram, ctx);
        goto after_2;
    // 0x80083BCC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_2:
    // 0x80083BD0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083BD4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083BD8: jal         0x8008AA44
    // 0x80083BDC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_8008AA44(rdram, ctx);
        goto after_3;
    // 0x80083BDC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_3:
    // 0x80083BE0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80083BE4: lw          $t0, 0x7B4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B4C);
    // 0x80083BE8: nop

    // 0x80083BEC: lw          $a0, 0x72C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X72C);
    // 0x80083BF0: jal         0x800BC980
    // 0x80083BF4: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x80083BF4: nop

    after_4:
    // 0x80083BF8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083BFC: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083C00: nop

    // 0x80083C04: lw          $t3, 0x734($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X734);
    // 0x80083C08: nop

    // 0x80083C0C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80083C10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80083C14: nop

    // 0x80083C18: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80083C1C: nop

    // 0x80083C20: beq         $t5, $zero, L_80083C64
    if (ctx->r13 == 0) {
        // 0x80083C24: nop

            goto L_80083C64;
    }
    // 0x80083C24: nop

L_80083C28:
    // 0x80083C28: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80083C2C: nop

    // 0x80083C30: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80083C34: jal         0x800BC980
    // 0x80083C38: nop

    SysMem_Free(rdram, ctx);
        goto after_5;
    // 0x80083C38: nop

    after_5:
    // 0x80083C3C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80083C40: nop

    // 0x80083C44: addiu       $t7, $t4, 0x4
    ctx->r15 = ADD32(ctx->r12, 0X4);
    // 0x80083C48: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80083C4C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80083C50: nop

    // 0x80083C54: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80083C58: nop

    // 0x80083C5C: bne         $t9, $zero, L_80083C28
    if (ctx->r25 != 0) {
        // 0x80083C60: nop

            goto L_80083C28;
    }
    // 0x80083C60: nop

L_80083C64:
    // 0x80083C64: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80083C68: lw          $t0, 0x7B4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B4C);
    // 0x80083C6C: nop

    // 0x80083C70: lw          $a0, 0x734($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X734);
    // 0x80083C74: jal         0x800BC980
    // 0x80083C78: nop

    SysMem_Free(rdram, ctx);
        goto after_6;
    // 0x80083C78: nop

    after_6:
    // 0x80083C7C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083C80: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083C84: nop

    // 0x80083C88: lw          $a0, 0x730($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X730);
    // 0x80083C8C: jal         0x800BC980
    // 0x80083C90: nop

    SysMem_Free(rdram, ctx);
        goto after_7;
    // 0x80083C90: nop

    after_7:
    // 0x80083C94: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083C98: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x80083C9C: nop

    // 0x80083CA0: lw          $t1, 0x738($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X738);
    // 0x80083CA4: nop

    // 0x80083CA8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80083CAC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80083CB0: nop

    // 0x80083CB4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80083CB8: nop

    // 0x80083CBC: beq         $t6, $zero, L_80083D00
    if (ctx->r14 == 0) {
        // 0x80083CC0: nop

            goto L_80083D00;
    }
    // 0x80083CC0: nop

L_80083CC4:
    // 0x80083CC4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80083CC8: nop

    // 0x80083CCC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80083CD0: jal         0x800BC980
    // 0x80083CD4: nop

    SysMem_Free(rdram, ctx);
        goto after_8;
    // 0x80083CD4: nop

    after_8:
    // 0x80083CD8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80083CDC: nop

    // 0x80083CE0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80083CE4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80083CE8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80083CEC: nop

    // 0x80083CF0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80083CF4: nop

    // 0x80083CF8: bne         $t0, $zero, L_80083CC4
    if (ctx->r8 != 0) {
        // 0x80083CFC: nop

            goto L_80083CC4;
    }
    // 0x80083CFC: nop

L_80083D00:
    // 0x80083D00: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083D04: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083D08: nop

    // 0x80083D0C: lw          $a0, 0x738($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X738);
    // 0x80083D10: jal         0x800BC980
    // 0x80083D14: nop

    SysMem_Free(rdram, ctx);
        goto after_9;
    // 0x80083D14: nop

    after_9:
    // 0x80083D18: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083D1C: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x80083D20: nop

    // 0x80083D24: lw          $a0, 0x728($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X728);
    // 0x80083D28: jal         0x8001AE90
    // 0x80083D2C: nop

    func_8001AE90(rdram, ctx);
        goto after_10;
    // 0x80083D2C: nop

    after_10:
    // 0x80083D30: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083D34: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x80083D38: nop

    // 0x80083D3C: lw          $a0, 0x728($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X728);
    // 0x80083D40: jal         0x800BC980
    // 0x80083D44: nop

    SysMem_Free(rdram, ctx);
        goto after_11;
    // 0x80083D44: nop

    after_11:
    // 0x80083D48: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80083D4C:
    // 0x80083D4C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80083D50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083D54: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083D58: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80083D5C: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80083D60: lw          $t8, 0xC04($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC04);
    // 0x80083D64: nop

    // 0x80083D68: beq         $t8, $zero, L_80083D90
    if (ctx->r24 == 0) {
        // 0x80083D6C: nop

            goto L_80083D90;
    }
    // 0x80083D6C: nop

    // 0x80083D70: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80083D74: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083D78: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083D7C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80083D80: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80083D84: lw          $a0, 0xC04($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC04);
    // 0x80083D88: jal         0x800BC980
    // 0x80083D8C: nop

    SysMem_Free(rdram, ctx);
        goto after_12;
    // 0x80083D8C: nop

    after_12:
L_80083D90:
    // 0x80083D90: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80083D94: nop

    // 0x80083D98: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x80083D9C: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80083DA0: bne         $at, $zero, L_80083D4C
    if (ctx->r1 != 0) {
        // 0x80083DA4: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_80083D4C;
    }
    // 0x80083DA4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80083DA8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083DAC: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083DB0: nop

    // 0x80083DB4: lw          $a0, 0xC10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC10);
    // 0x80083DB8: jal         0x800BC980
    // 0x80083DBC: nop

    SysMem_Free(rdram, ctx);
        goto after_13;
    // 0x80083DBC: nop

    after_13:
    // 0x80083DC0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083DC4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083DC8: jal         0x800BC980
    // 0x80083DCC: nop

    SysMem_Free(rdram, ctx);
        goto after_14;
    // 0x80083DCC: nop

    after_14:
    // 0x80083DD0: jal         0x80031728
    // 0x80083DD4: nop

    func_80031728(rdram, ctx);
        goto after_15;
    // 0x80083DD4: nop

    after_15:
    // 0x80083DD8: jal         0x80031C04
    // 0x80083DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80031C04(rdram, ctx);
        goto after_16;
    // 0x80083DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80083DE0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083DE4: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083DE8: nop

    // 0x80083DEC: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x80083DF0: nop

    // 0x80083DF4: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x80083DF8: bne         $t8, $zero, L_80083E08
    if (ctx->r24 != 0) {
        // 0x80083DFC: nop

            goto L_80083E08;
    }
    // 0x80083DFC: nop

    // 0x80083E00: jal         0x80021F20
    // 0x80083E04: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_17;
    // 0x80083E04: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_17:
L_80083E08:
    // 0x80083E08: b           L_80083E18
    // 0x80083E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80083E18;
    // 0x80083E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80083E10: b           L_80083E18
    // 0x80083E14: nop

        goto L_80083E18;
    // 0x80083E14: nop

L_80083E18:
    // 0x80083E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80083E1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80083E20: jr          $ra
    // 0x80083E24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80083E24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80083E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083E30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083E34: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083E38: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80083E3C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80083E40: nop

    // 0x80083E44: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80083E48: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80083E4C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083E50: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083E54: nop

    // 0x80083E58: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80083E5C: nop

    // 0x80083E60: sh          $t0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r8;
    // 0x80083E64: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083E68: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x80083E6C: nop

    // 0x80083E70: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x80083E74: nop

    // 0x80083E78: sh          $t2, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r10;
    // 0x80083E7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083E80: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083E84: jal         0x80088CC4
    // 0x80083E88: nop

    func_80088CC4(rdram, ctx);
        goto after_0;
    // 0x80083E88: nop

    after_0:
    // 0x80083E8C: b           L_80083E9C
    // 0x80083E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80083E9C;
    // 0x80083E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80083E94: b           L_80083E9C
    // 0x80083E98: nop

        goto L_80083E9C;
    // 0x80083E98: nop

L_80083E9C:
    // 0x80083E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083EA4: jr          $ra
    // 0x80083EA8: nop

    return;
    // 0x80083EA8: nop

;}
RECOMP_FUNC void func_80083EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083EB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80083EB8: sh          $zero, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = 0;
    // 0x80083EBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80083EC0: sh          $zero, 0x7A12($at)
    MEM_H(0X7A12, ctx->r1) = 0;
    // 0x80083EC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80083EC8: sh          $zero, 0x7A14($at)
    MEM_H(0X7A14, ctx->r1) = 0;
    // 0x80083ECC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80083ED0:
    // 0x80083ED0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80083ED4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083ED8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80083EDC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80083EE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80083EE4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80083EE8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80083EEC: addiu       $t8, $t8, 0x7AE8
    ctx->r24 = ADD32(ctx->r24, 0X7AE8);
    // 0x80083EF0: jal         0x8008C0D8
    // 0x80083EF4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    func_8008C0D8(rdram, ctx);
        goto after_0;
    // 0x80083EF4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80083EF8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80083EFC: nop

    // 0x80083F00: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80083F04: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80083F08: bne         $at, $zero, L_80083ED0
    if (ctx->r1 != 0) {
        // 0x80083F0C: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_80083ED0;
    }
    // 0x80083F0C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80083F10: b           L_80083F18
    // 0x80083F14: nop

        goto L_80083F18;
    // 0x80083F14: nop

L_80083F18:
    // 0x80083F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083F1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083F20: jr          $ra
    // 0x80083F24: nop

    return;
    // 0x80083F24: nop

;}
RECOMP_FUNC void func_80083F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083F30: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80083F34: addiu       $t6, $t6, 0x4C0C
    ctx->r14 = ADD32(ctx->r14, 0X4C0C);
    // 0x80083F38: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80083F3C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80083F40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083F44: beq         $t7, $at, L_80083FB8
    if (ctx->r15 == ctx->r1) {
        // 0x80083F48: nop

            goto L_80083FB8;
    }
    // 0x80083F48: nop

L_80083F4C:
    // 0x80083F4C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80083F50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083F54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80083F58: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80083F5C: lh          $a0, 0x4C0C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4C0C);
    // 0x80083F60: jal         0x8005F064
    // 0x80083F64: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80083F64: nop

    after_0:
    // 0x80083F68: beq         $v0, $zero, L_80083F94
    if (ctx->r2 == 0) {
        // 0x80083F6C: nop

            goto L_80083F94;
    }
    // 0x80083F6C: nop

    // 0x80083F70: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80083F74: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083F78: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80083F7C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80083F80: lh          $v0, 0x4C0E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4C0E);
    // 0x80083F84: b           L_80083FC8
    // 0x80083F88: nop

        goto L_80083FC8;
    // 0x80083F88: nop

    // 0x80083F8C: b           L_80083FB8
    // 0x80083F90: nop

        goto L_80083FB8;
    // 0x80083F90: nop

L_80083F94:
    // 0x80083F94: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80083F98: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80083F9C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80083FA0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80083FA4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80083FA8: lh          $t5, 0x4C0C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X4C0C);
    // 0x80083FAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083FB0: bne         $t5, $at, L_80083F4C
    if (ctx->r13 != ctx->r1) {
        // 0x80083FB4: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_80083F4C;
    }
    // 0x80083FB4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_80083FB8:
    // 0x80083FB8: b           L_80083FC8
    // 0x80083FBC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80083FC8;
    // 0x80083FBC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x80083FC0: b           L_80083FC8
    // 0x80083FC4: nop

        goto L_80083FC8;
    // 0x80083FC4: nop

L_80083FC8:
    // 0x80083FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083FCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083FD0: jr          $ra
    // 0x80083FD4: nop

    return;
    // 0x80083FD4: nop

;}
RECOMP_FUNC void func_80083FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80083FE4: jal         0x80083EAC
    // 0x80083FE8: nop

    func_80083EAC(rdram, ctx);
        goto after_0;
    // 0x80083FE8: nop

    after_0:
    // 0x80083FEC: jal         0x800AE348
    // 0x80083FF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    ContPak_SetPakInitializationAttempts(rdram, ctx);
        goto after_1;
    // 0x80083FF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80083FF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80083FF8: nop

    // 0x80083FFC: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80084000: b           L_80084010
    // 0x80084004: nop

        goto L_80084010;
    // 0x80084004: nop

    // 0x80084008: b           L_80084010
    // 0x8008400C: nop

        goto L_80084010;
    // 0x8008400C: nop

L_80084010:
    // 0x80084010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084018: jr          $ra
    // 0x8008401C: nop

    return;
    // 0x8008401C: nop

;}
RECOMP_FUNC void func_80084020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084020: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084028: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008402C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80084030: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084034: jal         0x8008C34C
    // 0x80084038: nop

    func_8008C34C(rdram, ctx);
        goto after_0;
    // 0x80084038: nop

    after_0:
    // 0x8008403C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084040: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80084044: beq         $s0, $at, L_80084148
    if (ctx->r16 == ctx->r1) {
        // 0x80084048: nop

            goto L_80084148;
    }
    // 0x80084048: nop

    // 0x8008404C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80084050: beq         $s0, $at, L_800840E8
    if (ctx->r16 == ctx->r1) {
        // 0x80084054: nop

            goto L_800840E8;
    }
    // 0x80084054: nop

    // 0x80084058: beq         $s0, $zero, L_80084068
    if (ctx->r16 == 0) {
        // 0x8008405C: nop

            goto L_80084068;
    }
    // 0x8008405C: nop

    // 0x80084060: b           L_800841A0
    // 0x80084064: nop

        goto L_800841A0;
    // 0x80084064: nop

L_80084068:
    // 0x80084068: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008406C: lhu         $t6, 0x7A10($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7A10);
    // 0x80084070: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084074: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x80084078: sh          $t7, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = ctx->r15;
    // 0x8008407C: jal         0x800AE580
    // 0x80084080: nop

    ContPak_GetAvailableSlots(rdram, ctx);
        goto after_1;
    // 0x80084080: nop

    after_1:
    // 0x80084084: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80084088: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x8008408C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084090: sh          $t9, 0x7A14($at)
    MEM_H(0X7A14, ctx->r1) = ctx->r25;
    // 0x80084094: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80084098: lw          $t0, 0x1638($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1638);
    // 0x8008409C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800840A0: sh          $t0, 0x7A12($at)
    MEM_H(0X7A12, ctx->r1) = ctx->r8;
    // 0x800840A4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800840A8: nop

    // 0x800840AC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800840B0: nop

    // 0x800840B4: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x800840B8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x800840BC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800840C0: nop

    // 0x800840C4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800840C8: nop

    // 0x800840CC: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x800840D0: beq         $t6, $zero, L_800840E0
    if (ctx->r14 == 0) {
        // 0x800840D4: nop

            goto L_800840E0;
    }
    // 0x800840D4: nop

    // 0x800840D8: b           L_800841BC
    // 0x800840DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800841BC;
    // 0x800840DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800840E0:
    // 0x800840E0: b           L_800841BC
    // 0x800840E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800841BC;
    // 0x800840E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800840E8:
    // 0x800840E8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800840EC: lhu         $t7, 0x7A10($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7A10);
    // 0x800840F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800840F4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800840F8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800840FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084100: sh          $t8, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = ctx->r24;
    // 0x80084104: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084108: nop

    // 0x8008410C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80084110: nop

    // 0x80084114: andi        $t2, $t0, 0x8000
    ctx->r10 = ctx->r8 & 0X8000;
    // 0x80084118: beq         $t2, $zero, L_80084128
    if (ctx->r10 == 0) {
        // 0x8008411C: nop

            goto L_80084128;
    }
    // 0x8008411C: nop

    // 0x80084120: b           L_800841BC
    // 0x80084124: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800841BC;
    // 0x80084124: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084128:
    // 0x80084128: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8008412C: nop

    // 0x80084130: lhu         $t1, 0x0($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X0);
    // 0x80084134: nop

    // 0x80084138: ori         $t4, $t1, 0x200
    ctx->r12 = ctx->r9 | 0X200;
    // 0x8008413C: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
    // 0x80084140: b           L_800841BC
    // 0x80084144: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800841BC;
    // 0x80084144: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80084148:
    // 0x80084148: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008414C: lhu         $t5, 0x7A10($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7A10);
    // 0x80084150: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084154: ori         $t6, $t5, 0xC000
    ctx->r14 = ctx->r13 | 0XC000;
    // 0x80084158: sh          $t6, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = ctx->r14;
    // 0x8008415C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80084160: nop

    // 0x80084164: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80084168: nop

    // 0x8008416C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80084170: beq         $t9, $zero, L_80084180
    if (ctx->r25 == 0) {
        // 0x80084174: nop

            goto L_80084180;
    }
    // 0x80084174: nop

    // 0x80084178: b           L_800841BC
    // 0x8008417C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800841BC;
    // 0x8008417C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084180:
    // 0x80084180: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084184: nop

    // 0x80084188: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x8008418C: nop

    // 0x80084190: ori         $t1, $t2, 0x200
    ctx->r9 = ctx->r10 | 0X200;
    // 0x80084194: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
    // 0x80084198: b           L_800841BC
    // 0x8008419C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800841BC;
    // 0x8008419C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800841A0:
    // 0x800841A0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800841A4: nop

    // 0x800841A8: lh          $v0, 0x4($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X4);
    // 0x800841AC: b           L_800841BC
    // 0x800841B0: nop

        goto L_800841BC;
    // 0x800841B0: nop

    // 0x800841B4: b           L_800841BC
    // 0x800841B8: nop

        goto L_800841BC;
    // 0x800841B8: nop

L_800841BC:
    // 0x800841BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800841C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800841C4: jr          $ra
    // 0x800841C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800841C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800841CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800841D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800841D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800841D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800841DC: nop

    // 0x800841E0: sh          $zero, 0xBFE($t6)
    MEM_H(0XBFE, ctx->r14) = 0;
    // 0x800841E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800841E8: nop

    // 0x800841EC: lh          $a1, 0xBFE($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XBFE);
    // 0x800841F0: jal         0x8008C2E8
    // 0x800841F4: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_0;
    // 0x800841F4: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    after_0:
    // 0x800841F8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800841FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084200: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80084204: jal         0x800AEA98
    // 0x80084208: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_1;
    // 0x80084208: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_1:
    // 0x8008420C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80084210: nop

    // 0x80084214: sh          $zero, 0xC14($t8)
    MEM_H(0XC14, ctx->r24) = 0;
    // 0x80084218: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008421C: nop

    // 0x80084220: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x80084224: b           L_80084234
    // 0x80084228: nop

        goto L_80084234;
    // 0x80084228: nop

    // 0x8008422C: b           L_80084234
    // 0x80084230: nop

        goto L_80084234;
    // 0x80084230: nop

L_80084234:
    // 0x80084234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008423C: jr          $ra
    // 0x80084240: nop

    return;
    // 0x80084240: nop

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
RECOMP_FUNC void func_800847EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800847F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800847F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800847F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800847FC: jal         0x8008A46C
    // 0x80084800: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80084800: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80084804: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80084808: nop

    // 0x8008480C: sh          $zero, 0xC14($t6)
    MEM_H(0XC14, ctx->r14) = 0;
    // 0x80084810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084814: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80084818: lh          $a1, 0x7A16($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7A16);
    // 0x8008481C: jal         0x8008C2E8
    // 0x80084820: addiu       $a0, $a0, 0xBEE
    ctx->r4 = ADD32(ctx->r4, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_1;
    // 0x80084820: addiu       $a0, $a0, 0xBEE
    ctx->r4 = ADD32(ctx->r4, 0XBEE);
    after_1:
    // 0x80084824: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80084828: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008482C: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80084830: jal         0x800AEA98
    // 0x80084834: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_2;
    // 0x80084834: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_2:
    // 0x80084838: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008483C: nop

    // 0x80084840: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80084844: nop

    // 0x80084848: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008484C: beq         $t9, $zero, L_80084888
    if (ctx->r25 == 0) {
        // 0x80084850: nop

            goto L_80084888;
    }
    // 0x80084850: nop

    // 0x80084854: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80084858: lh          $t0, 0x7A16($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7A16);
    // 0x8008485C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80084860: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80084864: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80084868: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008486C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80084870: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80084874: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80084878: addiu       $t2, $t2, 0x7AE8
    ctx->r10 = ADD32(ctx->r10, 0X7AE8);
    // 0x8008487C: lw          $a1, 0xC10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC10);
    // 0x80084880: jal         0x8008C558
    // 0x80084884: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    func_8008C558(rdram, ctx);
        goto after_3;
    // 0x80084884: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_3:
L_80084888:
    // 0x80084888: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008488C: nop

    // 0x80084890: lh          $v0, 0x4($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X4);
    // 0x80084894: b           L_800848A4
    // 0x80084898: nop

        goto L_800848A4;
    // 0x80084898: nop

    // 0x8008489C: b           L_800848A4
    // 0x800848A0: nop

        goto L_800848A4;
    // 0x800848A0: nop

L_800848A4:
    // 0x800848A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800848A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800848AC: jr          $ra
    // 0x800848B0: nop

    return;
    // 0x800848B0: nop

;}
RECOMP_FUNC void func_800848B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800848B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800848BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800848C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800848C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800848C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800848CC: nop

    // 0x800848D0: lh          $s0, 0xC14($t6)
    ctx->r16 = MEM_H(ctx->r14, 0XC14);
    // 0x800848D4: nop

    // 0x800848D8: beq         $s0, $zero, L_8008490C
    if (ctx->r16 == 0) {
        // 0x800848DC: nop

            goto L_8008490C;
    }
    // 0x800848DC: nop

    // 0x800848E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800848E4: beq         $s0, $at, L_80084A70
    if (ctx->r16 == ctx->r1) {
        // 0x800848E8: nop

            goto L_80084A70;
    }
    // 0x800848E8: nop

    // 0x800848EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800848F0: beq         $s0, $at, L_80084B34
    if (ctx->r16 == ctx->r1) {
        // 0x800848F4: nop

            goto L_80084B34;
    }
    // 0x800848F4: nop

    // 0x800848F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800848FC: beq         $s0, $at, L_80084C80
    if (ctx->r16 == ctx->r1) {
        // 0x80084900: nop

            goto L_80084C80;
    }
    // 0x80084900: nop

    // 0x80084904: b           L_80084D2C
    // 0x80084908: nop

        goto L_80084D2C;
    // 0x80084908: nop

L_8008490C:
    // 0x8008490C: jal         0x800AEBF4
    // 0x80084910: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_0;
    // 0x80084910: nop

    after_0:
    // 0x80084914: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80084918: nop

    // 0x8008491C: sw          $v0, 0xC00($t7)
    MEM_W(0XC00, ctx->r15) = ctx->r2;
    // 0x80084920: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084924: addiu       $at, $zero, 0x1005
    ctx->r1 = ADD32(0, 0X1005);
    // 0x80084928: lw          $t9, 0xC00($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC00);
    // 0x8008492C: nop

    // 0x80084930: bne         $t9, $at, L_80084978
    if (ctx->r25 != ctx->r1) {
        // 0x80084934: nop

            goto L_80084978;
    }
    // 0x80084934: nop

    // 0x80084938: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008493C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80084940: lh          $a1, 0x7A16($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7A16);
    // 0x80084944: jal         0x8008C2E8
    // 0x80084948: addiu       $a0, $a0, 0xBEE
    ctx->r4 = ADD32(ctx->r4, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_1;
    // 0x80084948: addiu       $a0, $a0, 0xBEE
    ctx->r4 = ADD32(ctx->r4, 0XBEE);
    after_1:
    // 0x8008494C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80084950: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084954: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80084958: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    // 0x8008495C: jal         0x800AE880
    // 0x80084960: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetOpenFileParams(rdram, ctx);
        goto after_2;
    // 0x80084960: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_2:
    // 0x80084964: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084968: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008496C: sh          $t0, 0xC14($t1)
    MEM_H(0XC14, ctx->r9) = ctx->r8;
    // 0x80084970: b           L_80084D2C
    // 0x80084974: nop

        goto L_80084D2C;
    // 0x80084974: nop

L_80084978:
    // 0x80084978: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008497C: nop

    // 0x80084980: lw          $t3, 0xC00($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC00);
    // 0x80084984: nop

    // 0x80084988: bltz        $t3, L_80084A10
    if (SIGNED(ctx->r11) < 0) {
        // 0x8008498C: nop

            goto L_80084A10;
    }
    // 0x8008498C: nop

    // 0x80084990: slti        $at, $t3, 0x1000
    ctx->r1 = SIGNED(ctx->r11) < 0X1000 ? 1 : 0;
    // 0x80084994: beq         $at, $zero, L_80084A10
    if (ctx->r1 == 0) {
        // 0x80084998: nop

            goto L_80084A10;
    }
    // 0x80084998: nop

    // 0x8008499C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800849A0: nop

    // 0x800849A4: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x800849A8: nop

    // 0x800849AC: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x800849B0: beq         $t6, $zero, L_800849E4
    if (ctx->r14 == 0) {
        // 0x800849B4: nop

            goto L_800849E4;
    }
    // 0x800849B4: nop

    // 0x800849B8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800849BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800849C0: lw          $a0, 0xC00($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC00);
    // 0x800849C4: lw          $a3, 0xC10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC10);
    // 0x800849C8: jal         0x800AEE6C
    // 0x800849CC: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileReadParams(rdram, ctx);
        goto after_3;
    // 0x800849CC: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_3:
    // 0x800849D0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800849D4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800849D8: sh          $t8, 0xC14($t9)
    MEM_H(0XC14, ctx->r25) = ctx->r24;
    // 0x800849DC: b           L_80084D2C
    // 0x800849E0: nop

        goto L_80084D2C;
    // 0x800849E0: nop

L_800849E4:
    // 0x800849E4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800849E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800849EC: lw          $a0, 0xC00($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC00);
    // 0x800849F0: lw          $a3, 0xC10($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC10);
    // 0x800849F4: jal         0x800AEC80
    // 0x800849F8: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_4;
    // 0x800849F8: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_4:
    // 0x800849FC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80084A00: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80084A04: sh          $t1, 0xC14($t2)
    MEM_H(0XC14, ctx->r10) = ctx->r9;
    // 0x80084A08: b           L_80084D2C
    // 0x80084A0C: nop

        goto L_80084D2C;
    // 0x80084A0C: nop

L_80084A10:
    // 0x80084A10: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084A14: nop

    // 0x80084A18: lw          $t4, 0xC00($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC00);
    // 0x80084A1C: nop

    // 0x80084A20: slti        $at, $t4, 0x1000
    ctx->r1 = SIGNED(ctx->r12) < 0X1000 ? 1 : 0;
    // 0x80084A24: bne         $at, $zero, L_80084A68
    if (ctx->r1 != 0) {
        // 0x80084A28: nop

            goto L_80084A68;
    }
    // 0x80084A28: nop

    // 0x80084A2C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084A30: nop

    // 0x80084A34: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80084A38: nop

    // 0x80084A3C: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80084A40: beq         $t7, $zero, L_80084A54
    if (ctx->r15 == 0) {
        // 0x80084A44: nop

            goto L_80084A54;
    }
    // 0x80084A44: nop

    // 0x80084A48: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084A4C: b           L_80084A60
    // 0x80084A50: sh          $zero, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = 0;
        goto L_80084A60;
    // 0x80084A50: sh          $zero, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = 0;
L_80084A54:
    // 0x80084A54: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084A58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80084A5C: sh          $t9, 0xBEC($t0)
    MEM_H(0XBEC, ctx->r8) = ctx->r25;
L_80084A60:
    // 0x80084A60: b           L_80084D48
    // 0x80084A64: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80084D48;
    // 0x80084A64: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084A68:
    // 0x80084A68: b           L_80084D2C
    // 0x80084A6C: nop

        goto L_80084D2C;
    // 0x80084A6C: nop

L_80084A70:
    // 0x80084A70: jal         0x800AEA0C
    // 0x80084A74: nop

    ContPak_GetOpenFileResult(rdram, ctx);
        goto after_5;
    // 0x80084A74: nop

    after_5:
    // 0x80084A78: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084A7C: nop

    // 0x80084A80: sw          $v0, 0xC00($t1)
    MEM_W(0XC00, ctx->r9) = ctx->r2;
    // 0x80084A84: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80084A88: nop

    // 0x80084A8C: lw          $t3, 0xC00($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC00);
    // 0x80084A90: nop

    // 0x80084A94: bltz        $t3, L_80084AD4
    if (SIGNED(ctx->r11) < 0) {
        // 0x80084A98: nop

            goto L_80084AD4;
    }
    // 0x80084A98: nop

    // 0x80084A9C: slti        $at, $t3, 0x1000
    ctx->r1 = SIGNED(ctx->r11) < 0X1000 ? 1 : 0;
    // 0x80084AA0: beq         $at, $zero, L_80084AD4
    if (ctx->r1 == 0) {
        // 0x80084AA4: nop

            goto L_80084AD4;
    }
    // 0x80084AA4: nop

    // 0x80084AA8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80084AAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084AB0: lw          $a0, 0xC00($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC00);
    // 0x80084AB4: lw          $a3, 0xC10($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XC10);
    // 0x80084AB8: jal         0x800AEC80
    // 0x80084ABC: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_6;
    // 0x80084ABC: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_6:
    // 0x80084AC0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80084AC4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80084AC8: sh          $t5, 0xC14($t6)
    MEM_H(0XC14, ctx->r14) = ctx->r13;
    // 0x80084ACC: b           L_80084D2C
    // 0x80084AD0: nop

        goto L_80084D2C;
    // 0x80084AD0: nop

L_80084AD4:
    // 0x80084AD4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80084AD8: nop

    // 0x80084ADC: lw          $t8, 0xC00($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC00);
    // 0x80084AE0: nop

    // 0x80084AE4: slti        $at, $t8, 0x1000
    ctx->r1 = SIGNED(ctx->r24) < 0X1000 ? 1 : 0;
    // 0x80084AE8: bne         $at, $zero, L_80084B2C
    if (ctx->r1 != 0) {
        // 0x80084AEC: nop

            goto L_80084B2C;
    }
    // 0x80084AEC: nop

    // 0x80084AF0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084AF4: nop

    // 0x80084AF8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80084AFC: nop

    // 0x80084B00: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80084B04: beq         $t1, $zero, L_80084B18
    if (ctx->r9 == 0) {
        // 0x80084B08: nop

            goto L_80084B18;
    }
    // 0x80084B08: nop

    // 0x80084B0C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80084B10: b           L_80084B24
    // 0x80084B14: sh          $zero, 0xBEC($t2)
    MEM_H(0XBEC, ctx->r10) = 0;
        goto L_80084B24;
    // 0x80084B14: sh          $zero, 0xBEC($t2)
    MEM_H(0XBEC, ctx->r10) = 0;
L_80084B18:
    // 0x80084B18: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80084B1C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80084B20: sh          $t3, 0xBEC($t4)
    MEM_H(0XBEC, ctx->r12) = ctx->r11;
L_80084B24:
    // 0x80084B24: b           L_80084D48
    // 0x80084B28: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80084D48;
    // 0x80084B28: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084B2C:
    // 0x80084B2C: b           L_80084D2C
    // 0x80084B30: nop

        goto L_80084D2C;
    // 0x80084B30: nop

L_80084B34:
    // 0x80084B34: jal         0x800AEDE8
    // 0x80084B38: nop

    ContPak_GetWriteFileResult(rdram, ctx);
        goto after_7;
    // 0x80084B38: nop

    after_7:
    // 0x80084B3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80084B40: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80084B44: nop

    // 0x80084B48: bne         $t5, $zero, L_80084C28
    if (ctx->r13 != 0) {
        // 0x80084B4C: nop

            goto L_80084C28;
    }
    // 0x80084B4C: nop

    // 0x80084B50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80084B54: lh          $t6, 0x7A16($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7A16);
    // 0x80084B58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084B5C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80084B60: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80084B64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80084B68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80084B6C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80084B70: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80084B74: addiu       $t8, $t8, 0x7AE8
    ctx->r24 = ADD32(ctx->r24, 0X7AE8);
    // 0x80084B78: lw          $a1, 0xC10($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC10);
    // 0x80084B7C: jal         0x8008C558
    // 0x80084B80: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    func_8008C558(rdram, ctx);
        goto after_8;
    // 0x80084B80: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_8:
    // 0x80084B84: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084B88: nop

    // 0x80084B8C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80084B90: nop

    // 0x80084B94: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x80084B98: bne         $t2, $zero, L_80084C20
    if (ctx->r10 != 0) {
        // 0x80084B9C: nop

            goto L_80084C20;
    }
    // 0x80084B9C: nop

    // 0x80084BA0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084BA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80084BA8: lh          $t4, 0xBEC($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XBEC);
    // 0x80084BAC: nop

    // 0x80084BB0: bne         $t4, $at, L_80084BEC
    if (ctx->r12 != ctx->r1) {
        // 0x80084BB4: nop

            goto L_80084BEC;
    }
    // 0x80084BB4: nop

    // 0x80084BB8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80084BBC: lh          $t5, 0x7A16($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7A16);
    // 0x80084BC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80084BC4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80084BC8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80084BCC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80084BD0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80084BD4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80084BD8: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x80084BDC: jal         0x8008C6E0
    // 0x80084BE0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    func_8008C6E0(rdram, ctx);
        goto after_9;
    // 0x80084BE0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_9:
    // 0x80084BE4: b           L_80084C20
    // 0x80084BE8: nop

        goto L_80084C20;
    // 0x80084BE8: nop

L_80084BEC:
    // 0x80084BEC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80084BF0: lh          $t9, 0x7A16($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7A16);
    // 0x80084BF4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084BF8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80084BFC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80084C00: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80084C04: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80084C08: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80084C0C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80084C10: addiu       $t1, $t1, 0x7AE8
    ctx->r9 = ADD32(ctx->r9, 0X7AE8);
    // 0x80084C14: lw          $a0, 0xC10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC10);
    // 0x80084C18: jal         0x8008C634
    // 0x80084C1C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_8008C634(rdram, ctx);
        goto after_10;
    // 0x80084C1C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_10:
L_80084C20:
    // 0x80084C20: b           L_80084D48
    // 0x80084C24: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80084D48;
    // 0x80084C24: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80084C28:
    // 0x80084C28: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80084C2C: nop

    // 0x80084C30: slti        $at, $t2, 0x1000
    ctx->r1 = SIGNED(ctx->r10) < 0X1000 ? 1 : 0;
    // 0x80084C34: bne         $at, $zero, L_80084C78
    if (ctx->r1 != 0) {
        // 0x80084C38: nop

            goto L_80084C78;
    }
    // 0x80084C38: nop

    // 0x80084C3C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084C40: nop

    // 0x80084C44: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80084C48: nop

    // 0x80084C4C: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80084C50: beq         $t5, $zero, L_80084C64
    if (ctx->r13 == 0) {
        // 0x80084C54: nop

            goto L_80084C64;
    }
    // 0x80084C54: nop

    // 0x80084C58: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80084C5C: b           L_80084C70
    // 0x80084C60: sh          $zero, 0xBEC($t6)
    MEM_H(0XBEC, ctx->r14) = 0;
        goto L_80084C70;
    // 0x80084C60: sh          $zero, 0xBEC($t6)
    MEM_H(0XBEC, ctx->r14) = 0;
L_80084C64:
    // 0x80084C64: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084C68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80084C6C: sh          $t7, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = ctx->r15;
L_80084C70:
    // 0x80084C70: b           L_80084D48
    // 0x80084C74: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80084D48;
    // 0x80084C74: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084C78:
    // 0x80084C78: b           L_80084D2C
    // 0x80084C7C: nop

        goto L_80084D2C;
    // 0x80084C7C: nop

L_80084C80:
    // 0x80084C80: jal         0x800AEFD4
    // 0x80084C84: nop

    ContPak_GetReadFileResult(rdram, ctx);
        goto after_11;
    // 0x80084C84: nop

    after_11:
    // 0x80084C88: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80084C8C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80084C90: nop

    // 0x80084C94: bne         $t9, $zero, L_80084CDC
    if (ctx->r25 != 0) {
        // 0x80084C98: nop

            goto L_80084CDC;
    }
    // 0x80084C98: nop

    // 0x80084C9C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084CA0: nop

    // 0x80084CA4: lw          $a0, 0xC10($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC10);
    // 0x80084CA8: jal         0x8008C528
    // 0x80084CAC: addiu       $a1, $t0, 0xE
    ctx->r5 = ADD32(ctx->r8, 0XE);
    func_8008C528(rdram, ctx);
        goto after_12;
    // 0x80084CAC: addiu       $a1, $t0, 0xE
    ctx->r5 = ADD32(ctx->r8, 0XE);
    after_12:
    // 0x80084CB0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084CB8: lw          $a0, 0xC00($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC00);
    // 0x80084CBC: lw          $a3, 0xC10($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XC10);
    // 0x80084CC0: jal         0x800AEC80
    // 0x80084CC4: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_13;
    // 0x80084CC4: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_13:
    // 0x80084CC8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084CCC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80084CD0: sh          $t2, 0xC14($t3)
    MEM_H(0XC14, ctx->r11) = ctx->r10;
    // 0x80084CD4: b           L_80084D2C
    // 0x80084CD8: nop

        goto L_80084D2C;
    // 0x80084CD8: nop

L_80084CDC:
    // 0x80084CDC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80084CE0: nop

    // 0x80084CE4: slti        $at, $t4, 0x1000
    ctx->r1 = SIGNED(ctx->r12) < 0X1000 ? 1 : 0;
    // 0x80084CE8: bne         $at, $zero, L_80084D2C
    if (ctx->r1 != 0) {
        // 0x80084CEC: nop

            goto L_80084D2C;
    }
    // 0x80084CEC: nop

    // 0x80084CF0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084CF4: nop

    // 0x80084CF8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80084CFC: nop

    // 0x80084D00: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80084D04: beq         $t7, $zero, L_80084D18
    if (ctx->r15 == 0) {
        // 0x80084D08: nop

            goto L_80084D18;
    }
    // 0x80084D08: nop

    // 0x80084D0C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084D10: b           L_80084D24
    // 0x80084D14: sh          $zero, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = 0;
        goto L_80084D24;
    // 0x80084D14: sh          $zero, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = 0;
L_80084D18:
    // 0x80084D18: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084D1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80084D20: sh          $t9, 0xBEC($t0)
    MEM_H(0XBEC, ctx->r8) = ctx->r25;
L_80084D24:
    // 0x80084D24: b           L_80084D48
    // 0x80084D28: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80084D48;
    // 0x80084D28: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084D2C:
    // 0x80084D2C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084D30: nop

    // 0x80084D34: lh          $v0, 0x4($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X4);
    // 0x80084D38: b           L_80084D48
    // 0x80084D3C: nop

        goto L_80084D48;
    // 0x80084D3C: nop

    // 0x80084D40: b           L_80084D48
    // 0x80084D44: nop

        goto L_80084D48;
    // 0x80084D44: nop

L_80084D48:
    // 0x80084D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80084D4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084D50: jr          $ra
    // 0x80084D54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80084D54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80084D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084D60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80084D64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084D68: jal         0x8008B600
    // 0x80084D6C: nop

    func_8008B600(rdram, ctx);
        goto after_0;
    // 0x80084D6C: nop

    after_0:
    // 0x80084D70: b           L_80084D78
    // 0x80084D74: nop

        goto L_80084D78;
    // 0x80084D74: nop

L_80084D78:
    // 0x80084D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084D80: jr          $ra
    // 0x80084D84: nop

    return;
    // 0x80084D84: nop

;}
RECOMP_FUNC void func_80084D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084D90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80084D94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80084D98: jal         0x8008A46C
    // 0x80084D9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80084D9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80084DA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80084DA4: jal         0x80089170
    // 0x80084DA8: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80084DA8: nop

    after_1:
    // 0x80084DAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80084DB0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80084DB4: jal         0x800898D8
    // 0x80084DB8: addiu       $a2, $zero, 0x4008
    ctx->r6 = ADD32(0, 0X4008);
    func_800898D8(rdram, ctx);
        goto after_2;
    // 0x80084DB8: addiu       $a2, $zero, 0x4008
    ctx->r6 = ADD32(0, 0X4008);
    after_2:
    // 0x80084DBC: beq         $v0, $zero, L_80084E0C
    if (ctx->r2 == 0) {
        // 0x80084DC0: nop

            goto L_80084E0C;
    }
    // 0x80084DC0: nop

    // 0x80084DC4: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80084DC8: lh          $t7, 0x22($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X22);
    // 0x80084DCC: lh          $t9, 0x20($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20);
    // 0x80084DD0: lh          $t0, 0x24($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X24);
    // 0x80084DD4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80084DD8: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x80084DDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80084DE0: bgez        $a1, L_80084DF0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80084DE4: sra         $t8, $a1, 1
        ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80084DF0;
    }
    // 0x80084DE4: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80084DE8: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80084DEC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80084DF0:
    // 0x80084DF0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80084DF4: bgez        $a2, L_80084E04
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80084DF8: sra         $t1, $a2, 1
        ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80084E04;
    }
    // 0x80084DF8: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80084DFC: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80084E00: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80084E04:
    // 0x80084E04: jal         0x80089B04
    // 0x80084E08: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_80089B04(rdram, ctx);
        goto after_3;
    // 0x80084E08: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_3:
L_80084E0C:
    // 0x80084E0C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80084E10: nop

    // 0x80084E14: lh          $v0, 0x4($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X4);
    // 0x80084E18: b           L_80084E28
    // 0x80084E1C: nop

        goto L_80084E28;
    // 0x80084E1C: nop

    // 0x80084E20: b           L_80084E28
    // 0x80084E24: nop

        goto L_80084E28;
    // 0x80084E24: nop

L_80084E28:
    // 0x80084E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084E2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80084E30: jr          $ra
    // 0x80084E34: nop

    return;
    // 0x80084E34: nop

;}
RECOMP_FUNC void func_80084E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80084E3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084E40: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80084E44: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80084E48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084E4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80084E50: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80084E54: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80084E58: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80084E5C: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80084E60: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80084E64: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80084E68: beq         $t0, $zero, L_80084EF8
    if (ctx->r8 == 0) {
        // 0x80084E6C: nop

            goto L_80084EF8;
    }
    // 0x80084E6C: nop

    // 0x80084E70: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80084E74: jal         0x8008A518
    // 0x80084E78: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80084E78: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80084E7C: beq         $v0, $zero, L_80084EF8
    if (ctx->r2 == 0) {
        // 0x80084E80: nop

            goto L_80084EF8;
    }
    // 0x80084E80: nop

    // 0x80084E84: lhu         $s0, 0x24($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X24);
    // 0x80084E88: addiu       $at, $zero, 0x4007
    ctx->r1 = ADD32(0, 0X4007);
    // 0x80084E8C: beq         $s0, $at, L_80084EA8
    if (ctx->r16 == ctx->r1) {
        // 0x80084E90: nop

            goto L_80084EA8;
    }
    // 0x80084E90: nop

    // 0x80084E94: addiu       $at, $zero, 0x4008
    ctx->r1 = ADD32(0, 0X4008);
    // 0x80084E98: beq         $s0, $at, L_80084EDC
    if (ctx->r16 == ctx->r1) {
        // 0x80084E9C: nop

            goto L_80084EDC;
    }
    // 0x80084E9C: nop

    // 0x80084EA0: b           L_80084EF8
    // 0x80084EA4: nop

        goto L_80084EF8;
    // 0x80084EA4: nop

L_80084EA8:
    // 0x80084EA8: jal         0x8008CE48
    // 0x80084EAC: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80084EAC: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80084EB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80084EB4: jal         0x8008C0D8
    // 0x80084EB8: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8008C0D8(rdram, ctx);
        goto after_2;
    // 0x80084EB8: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_2:
    // 0x80084EBC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80084EC0: nop

    // 0x80084EC4: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80084EC8: nop

    // 0x80084ECC: ori         $t3, $t2, 0x800
    ctx->r11 = ctx->r10 | 0X800;
    // 0x80084ED0: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80084ED4: b           L_80084F4C
    // 0x80084ED8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_80084F4C;
    // 0x80084ED8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80084EDC:
    // 0x80084EDC: jal         0x8008CE48
    // 0x80084EE0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80084EE0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x80084EE4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80084EE8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80084EEC: sh          $t4, 0xBEC($t5)
    MEM_H(0XBEC, ctx->r13) = ctx->r12;
    // 0x80084EF0: b           L_80084F4C
    // 0x80084EF4: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80084F4C;
    // 0x80084EF4: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80084EF8:
    // 0x80084EF8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80084EFC: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x80084F00: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x80084F04: nop

    // 0x80084F08: and         $t9, $t6, $t7
    ctx->r25 = ctx->r14 & ctx->r15;
    // 0x80084F0C: beq         $t9, $zero, L_80084F30
    if (ctx->r25 == 0) {
        // 0x80084F10: nop

            goto L_80084F30;
    }
    // 0x80084F10: nop

    // 0x80084F14: jal         0x8008CE48
    // 0x80084F18: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x80084F18: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_4:
    // 0x80084F1C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80084F20: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80084F24: sh          $t8, 0xBEC($t0)
    MEM_H(0XBEC, ctx->r8) = ctx->r24;
    // 0x80084F28: b           L_80084F4C
    // 0x80084F2C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80084F4C;
    // 0x80084F2C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80084F30:
    // 0x80084F30: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80084F34: nop

    // 0x80084F38: lh          $v0, 0x4($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X4);
    // 0x80084F3C: b           L_80084F4C
    // 0x80084F40: nop

        goto L_80084F4C;
    // 0x80084F40: nop

    // 0x80084F44: b           L_80084F4C
    // 0x80084F48: nop

        goto L_80084F4C;
    // 0x80084F48: nop

L_80084F4C:
    // 0x80084F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80084F50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084F54: jr          $ra
    // 0x80084F58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80084F58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
