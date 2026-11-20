#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800D4564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4564: nop

    // 0x800D4568: nop

    // 0x800D456C: nop

;}
RECOMP_FUNC void func_800D45C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D45C8: nop

    // 0x800D45CC: nop

;}
RECOMP_FUNC void func_800D4624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4624: nop

    // 0x800D4628: nop

    // 0x800D462C: nop

;}
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4630: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800D4634: bne         $at, $zero, L_800D46AC
    if (ctx->r1 != 0) {
        // 0x800D4638: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_800D46AC;
    }
    // 0x800D4638: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800D463C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800D4640: beq         $v1, $zero, L_800D4650
    if (ctx->r3 == 0) {
        // 0x800D4644: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_800D4650;
    }
    // 0x800D4644: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800D4648: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x800D464C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800D4650:
    // 0x800D4650: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800D4654: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D4658: beq         $a3, $zero, L_800D468C
    if (ctx->r7 == 0) {
        // 0x800D465C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D468C;
    }
    // 0x800D465C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D4660: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D4664:
    // 0x800D4664: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D4668: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x800D466C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x800D4670: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x800D4674: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x800D4678: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800D467C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x800D4680: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x800D4684: bne         $a0, $a3, L_800D4664
    if (ctx->r4 != ctx->r7) {
        // 0x800D4688: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D4664;
    }
    // 0x800D4688: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D468C:
    // 0x800D468C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4690: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D4694: beq         $a3, $zero, L_800D46AC
    if (ctx->r7 == 0) {
        // 0x800D4698: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D46AC;
    }
    // 0x800D4698: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D469C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D46A0:
    // 0x800D46A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D46A4: bne         $a0, $a3, L_800D46A0
    if (ctx->r4 != ctx->r7) {
        // 0x800D46A8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D46A0;
    }
    // 0x800D46A8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D46AC:
    // 0x800D46AC: blez        $a1, L_800D46C4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D46B0: nop

            goto L_800D46C4;
    }
    // 0x800D46B0: nop

    // 0x800D46B4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800D46B8:
    // 0x800D46B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D46BC: bne         $a0, $a1, L_800D46B8
    if (ctx->r4 != ctx->r5) {
        // 0x800D46C0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800D46B8;
    }
    // 0x800D46C0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800D46C4:
    // 0x800D46C4: jr          $ra
    // 0x800D46C8: nop

    return;
    // 0x800D46C8: nop

;}
RECOMP_FUNC void func_800D46CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D46CC: nop

;}
RECOMP_FUNC void __osSetHWIntrRoutine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D46D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D46D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D46D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D46DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D46E0: jal         0x800CBA20
    // 0x800D46E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x800D46E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800D46E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D46EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D46F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D46F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800D46F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D46FC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D4700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4704: jal         0x800CBA40
    // 0x800D4708: sw          $t6, -0x32E0($at)
    MEM_W(-0X32E0, ctx->r1) = ctx->r14;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x800D4708: sw          $t6, -0x32E0($at)
    MEM_W(-0X32E0, ctx->r1) = ctx->r14;
    after_1:
    // 0x800D470C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4710: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D4718: jr          $ra
    // 0x800D471C: nop

    return;
    // 0x800D471C: nop

;}
RECOMP_FUNC void func_800D4F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4F94: nop

    // 0x800D4F98: nop

    // 0x800D4F9C: nop

;}
RECOMP_FUNC void func_800D54FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D54FC: nop

;}
RECOMP_FUNC void func_800D552C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D552C: nop

;}
RECOMP_FUNC void alFilterNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D56B0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800D56B4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800D56B8: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800D56BC: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x800D56C0: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x800D56C4: jr          $ra
    // 0x800D56C8: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x800D56C8: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_800D56CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D56CC: nop

;}
RECOMP_FUNC void _doModFunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D56D0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800D56D4: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800D56D8: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800D56DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D56E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D56E4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D56E8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800D56EC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D56F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D56F4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800D56F8: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800D56FC: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800D5700: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800D5704: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D5708: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800D570C: nop

    // 0x800D5710: bc1fl       L_800D5738
    if (!c1cs) {
        // 0x800D5714: cvt.s.d     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d);
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
            goto L_800D5738;
    }
    goto skip_0;
    // 0x800D5714: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d);
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    skip_0:
    // 0x800D5718: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800D571C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D5720: nop

    // 0x800D5724: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x800D5728: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800D572C: b           L_800D573C
    // 0x800D5730: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_800D573C;
    // 0x800D5730: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800D5734: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d);
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
L_800D5738:
    // 0x800D5738: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_800D573C:
    // 0x800D573C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800D5740: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D5744: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800D5748: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800D574C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D5750: bc1fl       L_800D5760
    if (!c1cs) {
        // 0x800D5754: cvt.d.s     $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl);
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
            goto L_800D5760;
    }
    goto skip_1;
    // 0x800D5754: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl);
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    skip_1:
    // 0x800D5758: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl);
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800D575C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl);
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
L_800D5760:
    // 0x800D5760: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800D5764: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x800D5768: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x800D576C: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl);
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800D5770: jr          $ra
    // 0x800D5774: nop

    return;
    // 0x800D5774: nop

;}
RECOMP_FUNC void _filterBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5778: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D577C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5780: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800D5784: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800D5788: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800D578C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800D5790: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D5794: lui         $t2, 0xB00
    ctx->r10 = S32(0XB00 << 16);
    // 0x800D5798: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x800D579C: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x800D57A0: ori         $t2, $t2, 0x20
    ctx->r10 = ctx->r10 | 0X20;
    // 0x800D57A4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D57A8: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D57AC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800D57B0: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x800D57B4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D57B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D57BC: jal         0x800C79C0
    // 0x800D57C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800D57C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800D57C4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800D57C8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D57CC: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x800D57D0: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x800D57D4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800D57D8: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x800D57DC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D57E0: lw          $t4, 0x2C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X2C);
    // 0x800D57E4: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x800D57E8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800D57EC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800D57F0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800D57F4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D57F8: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x800D57FC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800D5800: lw          $a0, 0x28($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X28);
    // 0x800D5804: jal         0x800C79C0
    // 0x800D5808: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800D5808: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x800D580C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D5810: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D5814: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800D5818: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x800D581C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5820: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800D5824: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D5828: jr          $ra
    // 0x800D582C: nop

    return;
    // 0x800D582C: nop

;}
RECOMP_FUNC void _saveBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5830: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D5834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D5838: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D583C: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800D5840: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800D5844: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800D5848: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800D584C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800D5850: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D5854: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x800D5858: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x800D585C: beq         $at, $zero, L_800D5868
    if (ctx->r1 == 0) {
        // 0x800D5860: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_800D5868;
    }
    // 0x800D5860: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x800D5864: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_800D5868:
    // 0x800D5868: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x800D586C: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x800D5870: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x800D5874: beq         $at, $zero, L_800D5968
    if (ctx->r1 == 0) {
        // 0x800D5878: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_800D5968;
    }
    // 0x800D5878: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800D587C: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x800D5880: sra         $t8, $t3, 1
    ctx->r24 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800D5884: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800D5888: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800D588C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800D5890: andi        $t8, $t3, 0xFFFF
    ctx->r24 = ctx->r11 & 0XFFFF;
    // 0x800D5894: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800D5898: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800D589C: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800D58A0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800D58A4: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x800D58A8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800D58AC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800D58B0: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800D58B4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800D58B8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D58BC: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800D58C0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800D58C4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800D58C8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800D58CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D58D0: jal         0x800C79C0
    // 0x800D58D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800D58D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800D58D8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800D58DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D58E0: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800D58E4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800D58E8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800D58EC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800D58F0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D58F4: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800D58F8: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x800D58FC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D5900: subu        $t7, $a3, $t1
    ctx->r15 = SUB32(ctx->r7, ctx->r9);
    // 0x800D5904: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800D5908: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800D590C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800D5910: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800D5914: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800D5918: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D591C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D5920: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800D5924: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D5928: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800D592C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800D5930: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x800D5934: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800D5938: jal         0x800C79C0
    // 0x800D593C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800D593C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x800D5940: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800D5944: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800D5948: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D594C: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x800D5950: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800D5954: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800D5958: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D595C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D5960: b           L_800D59A4
    // 0x800D5964: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800D59A4;
    // 0x800D5964: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800D5968:
    // 0x800D5968: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x800D596C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800D5970: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800D5974: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800D5978: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D597C: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800D5980: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D5984: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800D5988: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D598C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800D5990: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D5994: jal         0x800C79C0
    // 0x800D5998: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D5998: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800D599C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800D59A0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800D59A4:
    // 0x800D59A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D59A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800D59AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D59B0: jr          $ra
    // 0x800D59B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D59B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
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
RECOMP_FUNC void _loadOutputBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5B44: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D5B48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D5B4C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D5B50: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D5B54: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800D5B58: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x800D5B5C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D5B60: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800D5B64: beq         $t6, $zero, L_800D5D20
    if (ctx->r14 == 0) {
        // 0x800D5B68: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_800D5D20;
    }
    // 0x800D5B68: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D5B6C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800D5B70: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800D5B74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D5B78: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D5B7C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800D5B80: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800D5B84: jal         0x800D56D0
    // 0x800D5B88: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    _doModFunc(rdram, ctx);
        goto after_0;
    // 0x800D5B88: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    after_0:
    // 0x800D5B8C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800D5B90: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800D5B94: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800D5B98: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800D5B9C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D5BA0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D5BA4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5BA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D5BAC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D5BB0: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x800D5BB4: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D5BB8: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D5BBC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D5BC0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800D5BC4: nop

    // 0x800D5BC8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D5BCC: nop

    // 0x800D5BD0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5BD4: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D5BD8: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800D5BDC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800D5BE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D5BE4: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x800D5BE8: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x800D5BEC: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D5BF0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800D5BF4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D5BF8: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800D5BFC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D5C00: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800D5C04: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800D5C08: nop

    // 0x800D5C0C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800D5C10: nop

    // 0x800D5C14: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D5C18: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x800D5C1C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x800D5C20: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x800D5C24: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800D5C28: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x800D5C2C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800D5C30: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x800D5C34: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800D5C38: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800D5C3C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x800D5C40: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800D5C44: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800D5C48: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800D5C4C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800D5C50: subu        $a1, $t0, $t3
    ctx->r5 = SUB32(ctx->r8, ctx->r11);
    // 0x800D5C54: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800D5C58: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800D5C5C: addu        $a3, $t1, $t8
    ctx->r7 = ADD32(ctx->r9, ctx->r24);
    // 0x800D5C60: jal         0x800D59B8
    // 0x800D5C64: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _loadBuffer(rdram, ctx);
        goto after_1;
    // 0x800D5C64: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800D5C68: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800D5C6C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D5C70: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D5C74: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x800D5C78: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800D5C7C: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800D5C80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D5C84: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800D5C88: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x800D5C8C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800D5C90: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D5C94: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800D5C98: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D5C9C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800D5CA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D5CA4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D5CA8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800D5CAC: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x800D5CB0: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D5CB4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800D5CB8: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x800D5CBC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800D5CC0: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800D5CC4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800D5CC8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D5CCC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800D5CD0: nop

    // 0x800D5CD4: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800D5CD8: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x800D5CDC: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800D5CE0: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800D5CE4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D5CE8: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x800D5CEC: jal         0x800C79C0
    // 0x800D5CF0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D5CF0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800D5CF4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800D5CF8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800D5CFC: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800D5D00: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x800D5D04: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800D5D08: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x800D5D0C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x800D5D10: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x800D5D14: subu        $t5, $t9, $s1
    ctx->r13 = SUB32(ctx->r25, ctx->r17);
    // 0x800D5D18: b           L_800D5D50
    // 0x800D5D1C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
        goto L_800D5D50;
    // 0x800D5D1C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
L_800D5D20:
    // 0x800D5D20: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800D5D24: lw          $t7, 0x18($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X18);
    // 0x800D5D28: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800D5D2C: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800D5D30: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800D5D34: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800D5D38: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800D5D3C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D5D40: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x800D5D44: jal         0x800D59B8
    // 0x800D5D48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _loadBuffer(rdram, ctx);
        goto after_3;
    // 0x800D5D48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x800D5D4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D5D50:
    // 0x800D5D50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D5D54: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5D58: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D5D5C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800D5D60: jr          $ra
    // 0x800D5D64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D5D64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void alFxParamHdl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5D68: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x800D5D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5D70: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x800D5D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5D78: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800D5D7C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D5D80: beq         $at, $zero, L_800D5FB0
    if (ctx->r1 == 0) {
        // 0x800D5D84: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_800D5FB0;
    }
    // 0x800D5D84: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800D5D88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D5D8C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5D90: addu        $at, $at, $t6
    gpr jr_addend_800D5D98 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D5D94: lw          $t6, 0x5E0($at)
    ctx->r14 = ADD32(ctx->r1, 0X5E0);
    // 0x800D5D98: jr          $t6
    // 0x800D5D9C: nop

    switch (jr_addend_800D5D98 >> 2) {
        case 0: goto L_800D5DA0; break;
        case 1: goto L_800D5DD4; break;
        case 2: goto L_800D5E34; break;
        case 3: goto L_800D5E08; break;
        case 4: goto L_800D5E60; break;
        case 5: goto L_800D5E8C; break;
        case 6: goto L_800D5EF4; break;
        case 7: goto L_800D5F6C; break;
        default: switch_error(__func__, 0x800D5D98, 0x800F05E0);
    }
    // 0x800D5D9C: nop

L_800D5DA0:
    // 0x800D5DA0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D5DA4: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x800D5DA8: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800D5DAC: bgez        $v1, L_800D5DBC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D5DB0: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D5DBC;
    }
    // 0x800D5DB0: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D5DB4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D5DB8: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800D5DBC:
    // 0x800D5DBC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800D5DC0: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800D5DC4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800D5DC8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800D5DCC: b           L_800D5FB0
    // 0x800D5DD0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_800D5FB0;
    // 0x800D5DD0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_800D5DD4:
    // 0x800D5DD4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D5DD8: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x800D5DDC: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x800D5DE0: bgez        $v1, L_800D5DF0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D5DE4: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D5DF0;
    }
    // 0x800D5DE4: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D5DE8: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D5DEC: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_800D5DF0:
    // 0x800D5DF0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800D5DF4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800D5DF8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800D5DFC: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x800D5E00: b           L_800D5FB0
    // 0x800D5E04: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_800D5FB0;
    // 0x800D5E04: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_800D5E08:
    // 0x800D5E08: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800D5E0C: bgez        $v1, L_800D5E1C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D5E10: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D5E1C;
    }
    // 0x800D5E10: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D5E14: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D5E18: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800D5E1C:
    // 0x800D5E1C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800D5E20: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800D5E24: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800D5E28: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800D5E2C: b           L_800D5FB0
    // 0x800D5E30: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_800D5FB0;
    // 0x800D5E30: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_800D5E34:
    // 0x800D5E34: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800D5E38: bgez        $v1, L_800D5E48
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D5E3C: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D5E48;
    }
    // 0x800D5E3C: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D5E40: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D5E44: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800D5E48:
    // 0x800D5E48: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800D5E4C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800D5E50: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800D5E54: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x800D5E58: b           L_800D5FB0
    // 0x800D5E5C: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_800D5FB0;
    // 0x800D5E5C: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_800D5E60:
    // 0x800D5E60: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800D5E64: bgez        $v1, L_800D5E74
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D5E68: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D5E74;
    }
    // 0x800D5E68: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D5E6C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D5E70: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800D5E74:
    // 0x800D5E74: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800D5E78: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x800D5E7C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800D5E80: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800D5E84: b           L_800D5FB0
    // 0x800D5E88: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_800D5FB0;
    // 0x800D5E88: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_800D5E8C:
    // 0x800D5E8C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800D5E90: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800D5E94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D5E98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D5E9C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800D5EA0: lw          $t2, -0x33E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X33E0);
    // 0x800D5EA4: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800D5EA8: lw          $t4, 0x44($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44);
    // 0x800D5EAC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D5EB0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800D5EB4: nop

    // 0x800D5EB8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800D5EBC: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800D5EC0: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d);
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x800D5EC4: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x800D5EC8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800D5ECC: bgez        $v1, L_800D5EDC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D5ED0: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D5EDC;
    }
    // 0x800D5ED0: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D5ED4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D5ED8: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800D5EDC:
    // 0x800D5EDC: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800D5EE0: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x800D5EE4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800D5EE8: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x800D5EEC: b           L_800D5FB0
    // 0x800D5EF0: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_800D5FB0;
    // 0x800D5EF0: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_800D5EF4:
    // 0x800D5EF4: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800D5EF8: bgez        $v1, L_800D5F08
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D5EFC: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D5F08;
    }
    // 0x800D5EFC: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D5F00: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D5F04: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800D5F08:
    // 0x800D5F08: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800D5F0C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D5F10: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800D5F14: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x800D5F18: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800D5F1C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800D5F20: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800D5F24: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D5F28: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x800D5F2C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D5F30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D5F34: bgez        $t6, L_800D5F4C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800D5F38: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_800D5F4C;
    }
    // 0x800D5F38: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x800D5F3C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D5F40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D5F44: nop

    // 0x800D5F48: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_800D5F4C:
    // 0x800D5F4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5F50: ldc1        $f10, 0x600($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X600);
    // 0x800D5F54: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800D5F58: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800D5F5C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800D5F60: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800D5F64: b           L_800D5FB0
    // 0x800D5F68: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_800D5FB0;
    // 0x800D5F68: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_800D5F6C:
    // 0x800D5F6C: bgez        $v1, L_800D5F7C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D5F70: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D5F7C;
    }
    // 0x800D5F70: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D5F74: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D5F78: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800D5F7C:
    // 0x800D5F7C: lw          $t3, 0x20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X20);
    // 0x800D5F80: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800D5F84: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x800D5F88: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800D5F8C: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x800D5F90: lw          $a1, 0x20($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X20);
    // 0x800D5F94: beql        $a1, $zero, L_800D5FB4
    if (ctx->r5 == 0) {
        // 0x800D5F98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D5FB4;
    }
    goto skip_0;
    // 0x800D5F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D5F9C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x800D5FA0: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800D5FA4: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800D5FA8: jal         0x800CFB00
    // 0x800D5FAC: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    _init_lpfilter(rdram, ctx);
        goto after_0;
    // 0x800D5FAC: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    after_0:
L_800D5FB0:
    // 0x800D5FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D5FB4:
    // 0x800D5FB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5FB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D5FBC: jr          $ra
    // 0x800D5FC0: nop

    return;
    // 0x800D5FC0: nop

;}
RECOMP_FUNC void alFxParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5FC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D5FC8: bne         $a1, $at, L_800D5FD4
    if (ctx->r5 != ctx->r1) {
        // 0x800D5FCC: nop

            goto L_800D5FD4;
    }
    // 0x800D5FCC: nop

    // 0x800D5FD0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_800D5FD4:
    // 0x800D5FD4: jr          $ra
    // 0x800D5FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D5FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alFxPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5FDC: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800D5FE0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D5FE4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800D5FE8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D5FEC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D5FF0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D5FF4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D5FF8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D5FFC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D6000: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D6004: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D6008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D600C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800D6010: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800D6014: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800D6018: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800D601C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D6020: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800D6024: jalr        $t9
    // 0x800D6028: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D6028: nop

    after_0:
    // 0x800D602C: sll         $s1, $s6, 1
    ctx->r17 = S32(ctx->r22 << 1);
    // 0x800D6030: lui         $t8, 0xC00
    ctx->r24 = S32(0XC00 << 16);
    // 0x800D6034: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800D6038: lui         $t3, 0xC00
    ctx->r11 = S32(0XC00 << 16);
    // 0x800D603C: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x800D6040: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x800D6044: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800D6048: ori         $t2, $t2, 0x6C0
    ctx->r10 = ctx->r10 | 0X6C0;
    // 0x800D604C: ori         $t8, $t8, 0xDA83
    ctx->r24 = ctx->r24 | 0XDA83;
    // 0x800D6050: ori         $t4, $t4, 0x6C0
    ctx->r12 = ctx->r12 | 0X6C0;
    // 0x800D6054: ori         $t3, $t3, 0x5A82
    ctx->r11 = ctx->r11 | 0X5A82;
    // 0x800D6058: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D605C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D6060: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800D6064: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800D6068: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x800D606C: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800D6070: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x800D6074: addiu       $t5, $v0, 0x18
    ctx->r13 = ADD32(ctx->r2, 0X18);
    // 0x800D6078: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800D607C: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x800D6080: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800D6084: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800D6088: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x800D608C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D6090: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x800D6094: jal         0x800D5830
    // 0x800D6098: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer(rdram, ctx);
        goto after_1;
    // 0x800D6098: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x800D609C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800D60A0: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800D60A4: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x800D60A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D60AC: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x800D60B0: lbu         $t9, 0x24($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X24);
    // 0x800D60B4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800D60B8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800D60BC: blezl       $t9, L_800D629C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D60C0: lw          $v1, 0x1C($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X1C);
            goto L_800D629C;
    }
    goto skip_0;
    // 0x800D60C0: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    skip_0:
    // 0x800D60C4: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
L_800D60C8:
    // 0x800D60C8: lw          $t7, 0x20($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X20);
    // 0x800D60CC: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x800D60D0: addu        $t8, $t8, $s7
    ctx->r24 = ADD32(ctx->r24, ctx->r23);
    // 0x800D60D4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800D60D8: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x800D60DC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800D60E0: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x800D60E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D60E8: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800D60EC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800D60F0: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800D60F4: addu        $s4, $v0, $t4
    ctx->r20 = ADD32(ctx->r2, ctx->r12);
    // 0x800D60F8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800D60FC: bne         $s4, $v1, L_800D6124
    if (ctx->r20 != ctx->r3) {
        // 0x800D6100: addu        $fp, $v0, $t9
        ctx->r30 = ADD32(ctx->r2, ctx->r25);
            goto L_800D6124;
    }
    // 0x800D6100: addu        $fp, $v0, $t9
    ctx->r30 = ADD32(ctx->r2, ctx->r25);
    // 0x800D6104: or          $t7, $s2, $zero
    ctx->r15 = ctx->r18 | 0;
    // 0x800D6108: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x800D610C: sll         $s5, $t7, 16
    ctx->r21 = S32(ctx->r15 << 16);
    // 0x800D6110: sra         $t2, $s5, 16
    ctx->r10 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800D6114: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800D6118: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800D611C: b           L_800D613C
    // 0x800D6120: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
        goto L_800D613C;
    // 0x800D6120: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
L_800D6124:
    // 0x800D6124: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D6128: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800D612C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800D6130: jal         0x800D59B8
    // 0x800D6134: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadBuffer(rdram, ctx);
        goto after_2;
    // 0x800D6134: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x800D6138: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D613C:
    // 0x800D613C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D6140: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D6144: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800D6148: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800D614C: jal         0x800D5B44
    // 0x800D6150: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadOutputBuffer(rdram, ctx);
        goto after_3;
    // 0x800D6150: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x800D6154: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x800D6158: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D615C: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800D6160: beq         $a0, $zero, L_800D61B4
    if (ctx->r4 == 0) {
        // 0x800D6164: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_800D61B4;
    }
    // 0x800D6164: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x800D6168: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x800D616C: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x800D6170: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800D6174: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800D6178: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800D617C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D6180: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x800D6184: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800D6188: bnel        $t2, $zero, L_800D61B8
    if (ctx->r10 != 0) {
        // 0x800D618C: lh          $v1, 0xA($s1)
        ctx->r3 = MEM_H(ctx->r17, 0XA);
            goto L_800D61B8;
    }
    goto skip_1;
    // 0x800D618C: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    skip_1:
    // 0x800D6190: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x800D6194: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D6198: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800D619C: bne         $t3, $zero, L_800D61B4
    if (ctx->r11 != 0) {
        // 0x800D61A0: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800D61B4;
    }
    // 0x800D61A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800D61A4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800D61A8: jal         0x800D5830
    // 0x800D61AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer(rdram, ctx);
        goto after_4;
    // 0x800D61AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x800D61B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D61B4:
    // 0x800D61B4: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
L_800D61B8:
    // 0x800D61B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800D61BC: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800D61C0: beq         $v1, $zero, L_800D6200
    if (ctx->r3 == 0) {
        // 0x800D61C4: andi        $t5, $v1, 0xFFFF
        ctx->r13 = ctx->r3 & 0XFFFF;
            goto L_800D6200;
    }
    // 0x800D61C4: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800D61C8: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800D61CC: andi        $t8, $s5, 0xFFFF
    ctx->r24 = ctx->r21 & 0XFFFF;
    // 0x800D61D0: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x800D61D4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800D61D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D61DC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800D61E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D61E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800D61E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D61EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D61F0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800D61F4: jal         0x800D5830
    // 0x800D61F8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer(rdram, ctx);
        goto after_5;
    // 0x800D61F8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x800D61FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D6200:
    // 0x800D6200: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800D6204: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D6208: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800D620C: beql        $a0, $zero, L_800D6224
    if (ctx->r4 == 0) {
        // 0x800D6210: lw          $t3, 0x24($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X24);
            goto L_800D6224;
    }
    goto skip_2;
    // 0x800D6210: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    skip_2:
    // 0x800D6214: jal         0x800D5778
    // 0x800D6218: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _filterBuffer(rdram, ctx);
        goto after_6;
    // 0x800D6218: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x800D621C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D6220: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
L_800D6224:
    // 0x800D6224: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D6228: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800D622C: bne         $t3, $zero, L_800D6244
    if (ctx->r11 != 0) {
        // 0x800D6230: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800D6244;
    }
    // 0x800D6230: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800D6234: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800D6238: jal         0x800D5830
    // 0x800D623C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer(rdram, ctx);
        goto after_7;
    // 0x800D623C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x800D6240: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D6244:
    // 0x800D6244: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x800D6248: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800D624C: sll         $t4, $s7, 16
    ctx->r12 = S32(ctx->r23 << 16);
    // 0x800D6250: beq         $v1, $zero, L_800D627C
    if (ctx->r3 == 0) {
        // 0x800D6254: sra         $s7, $t4, 16
        ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
            goto L_800D627C;
    }
    // 0x800D6254: sra         $s7, $t4, 16
    ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800D6258: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800D625C: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800D6260: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800D6264: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800D6268: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x800D626C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800D6270: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D6274: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D6278: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800D627C:
    // 0x800D627C: lbu         $t6, 0x24($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X24);
    // 0x800D6280: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x800D6284: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x800D6288: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D628C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800D6290: bne         $at, $zero, L_800D60C8
    if (ctx->r1 != 0) {
        // 0x800D6294: addu        $v1, $v0, $t3
        ctx->r3 = ADD32(ctx->r2, ctx->r11);
            goto L_800D60C8;
    }
    // 0x800D6294: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x800D6298: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
L_800D629C:
    // 0x800D629C: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x800D62A0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800D62A4: lw          $t3, 0x14($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X14);
    // 0x800D62A8: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x800D62AC: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800D62B0: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x800D62B4: sltu        $at, $t4, $t8
    ctx->r1 = ctx->r12 < ctx->r24 ? 1 : 0;
    // 0x800D62B8: beq         $at, $zero, L_800D62C8
    if (ctx->r1 == 0) {
        // 0x800D62BC: sw          $t8, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r24;
            goto L_800D62C8;
    }
    // 0x800D62BC: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x800D62C0: subu        $t5, $t8, $t2
    ctx->r13 = SUB32(ctx->r24, ctx->r10);
    // 0x800D62C4: sw          $t5, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r13;
L_800D62C8:
    // 0x800D62C8: lui         $t6, 0xA00
    ctx->r14 = S32(0XA00 << 16);
    // 0x800D62CC: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x800D62D0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D62D4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D62D8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800D62DC: lui         $at, 0x6C0
    ctx->r1 = S32(0X6C0 << 16);
    // 0x800D62E0: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800D62E4: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800D62E8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D62EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D62F0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D62F4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D62F8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D62FC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D6300: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D6304: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D6308: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D630C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D6310: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D6314: jr          $ra
    // 0x800D6318: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800D6318: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800D631C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D631C: nop

;}
RECOMP_FUNC void alCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6320: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D6324: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800D6328: blez        $a2, L_800D638C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800D632C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800D638C;
    }
    // 0x800D632C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D6330: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x800D6334: beq         $a1, $zero, L_800D635C
    if (ctx->r5 == 0) {
        // 0x800D6338: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D635C;
    }
    // 0x800D6338: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800D633C:
    // 0x800D633C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D6340: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800D6344: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D6348: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D634C: bne         $a0, $a3, L_800D633C
    if (ctx->r4 != ctx->r7) {
        // 0x800D6350: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_800D633C;
    }
    // 0x800D6350: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800D6354: beq         $a3, $a2, L_800D638C
    if (ctx->r7 == ctx->r6) {
        // 0x800D6358: nop

            goto L_800D638C;
    }
    // 0x800D6358: nop

L_800D635C:
    // 0x800D635C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800D6360: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800D6364: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D6368: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x800D636C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800D6370: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D6374: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x800D6378: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x800D637C: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x800D6380: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x800D6384: bne         $a3, $a2, L_800D635C
    if (ctx->r7 != ctx->r6) {
        // 0x800D6388: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_800D635C;
    }
    // 0x800D6388: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_800D638C:
    // 0x800D638C: jr          $ra
    // 0x800D6390: nop

    return;
    // 0x800D6390: nop

;}
RECOMP_FUNC void func_800D6394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6394: nop

    // 0x800D6398: nop

    // 0x800D639C: nop

;}
RECOMP_FUNC void alSeqGetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63A0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800D63A4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D63A8: lh          $t7, 0x1A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1A);
    // 0x800D63AC: sh          $t7, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r15;
    // 0x800D63B0: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x800D63B4: jr          $ra
    // 0x800D63B8: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    return;
    // 0x800D63B8: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void alSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63BC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800D63C0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800D63C4: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x800D63C8: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x800D63CC: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x800D63D0: jr          $ra
    // 0x800D63D4: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    return;
    // 0x800D63D4: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void alSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63D8: jr          $ra
    // 0x800D63DC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x800D63DC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_800D63E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63E0: jr          $ra
    // 0x800D63E4: nop

    return;
    // 0x800D63E4: nop

    // 0x800D63E8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800D63EC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D63F0: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800D63F4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800D63F8: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x800D63FC: beq         $t7, $zero, L_800D642C
    if (ctx->r15 == 0) {
        // 0x800D6400: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D642C;
    }
    // 0x800D6400: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D6404: andi        $a1, $v0, 0x7F
    ctx->r5 = ctx->r2 & 0X7F;
L_800D6408:
    // 0x800D6408: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800D640C: sll         $t9, $a1, 7
    ctx->r25 = S32(ctx->r5 << 7);
    // 0x800D6410: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D6414: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D6418: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800D641C: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x800D6420: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x800D6424: bne         $t7, $zero, L_800D6408
    if (ctx->r15 != 0) {
        // 0x800D6428: addu        $a1, $t9, $t6
        ctx->r5 = ADD32(ctx->r25, ctx->r14);
            goto L_800D6408;
    }
    // 0x800D6428: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
L_800D642C:
    // 0x800D642C: jr          $ra
    // 0x800D6430: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800D6430: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void alSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D643C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D6440: jal         0x800D63E8
    // 0x800D6444: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    static_1_800D63E8(rdram, ctx);
        goto after_0;
    // 0x800D6444: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_0:
    // 0x800D6448: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x800D644C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D6450: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800D6454: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800D6458: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x800D645C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D6460: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800D6464: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D6468: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D646C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D6470: bne         $a0, $at, L_800D6530
    if (ctx->r4 != ctx->r1) {
        // 0x800D6474: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_800D6530;
    }
    // 0x800D6474: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800D6478: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800D647C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D6480: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800D6484: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x800D6488: bne         $v0, $at, L_800D64F8
    if (ctx->r2 != ctx->r1) {
        // 0x800D648C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800D64F8;
    }
    // 0x800D648C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800D6490: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D6494: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x800D6498: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D649C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D64A0: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x800D64A4: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D64A8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D64AC: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800D64B0: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800D64B4: sb          $v0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r2;
    // 0x800D64B8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D64BC: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D64C0: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D64C4: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D64C8: sb          $a0, 0xB($a3)
    MEM_B(0XB, ctx->r7) = ctx->r4;
    // 0x800D64CC: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D64D0: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800D64D4: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800D64D8: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x800D64DC: sb          $a1, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r5;
    // 0x800D64E0: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D64E4: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D64E8: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800D64EC: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x800D64F0: b           L_800D6528
    // 0x800D64F4: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
        goto L_800D6528;
    // 0x800D64F4: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
L_800D64F8:
    // 0x800D64F8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800D64FC: bne         $v0, $at, L_800D6528
    if (ctx->r2 != ctx->r1) {
        // 0x800D6500: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_800D6528;
    }
    // 0x800D6500: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800D6504: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x800D6508: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D650C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D6510: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x800D6514: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D6518: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D651C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D6520: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D6524: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_800D6528:
    // 0x800D6528: b           L_800D65A8
    // 0x800D652C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
        goto L_800D65A8;
    // 0x800D652C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
L_800D6530:
    // 0x800D6530: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D6534: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800D6538: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x800D653C: beq         $t6, $zero, L_800D6564
    if (ctx->r14 == 0) {
        // 0x800D6540: sw          $t1, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->r9;
            goto L_800D6564;
    }
    // 0x800D6540: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D6544: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D6548: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D654C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D6550: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800D6554: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800D6558: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800D655C: b           L_800D6570
    // 0x800D6560: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
        goto L_800D6570;
    // 0x800D6560: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
L_800D6564:
    // 0x800D6564: lh          $t8, 0x1A($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1A);
    // 0x800D6568: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800D656C: sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
L_800D6570:
    // 0x800D6570: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    // 0x800D6574: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800D6578: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800D657C: beq         $t9, $at, L_800D65A4
    if (ctx->r25 == ctx->r1) {
        // 0x800D6580: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_800D65A4;
    }
    // 0x800D6580: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800D6584: beql        $t9, $at, L_800D65A8
    if (ctx->r25 == ctx->r1) {
        // 0x800D6588: sb          $zero, 0xA($a3)
        MEM_B(0XA, ctx->r7) = 0;
            goto L_800D65A8;
    }
    goto skip_0;
    // 0x800D6588: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
    skip_0:
    // 0x800D658C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D6590: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D6594: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800D6598: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x800D659C: b           L_800D65A8
    // 0x800D65A0: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
        goto L_800D65A8;
    // 0x800D65A0: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_800D65A4:
    // 0x800D65A4: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
L_800D65A8:
    // 0x800D65A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D65AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D65B0: jr          $ra
    // 0x800D65B4: nop

    return;
    // 0x800D65B4: nop

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
RECOMP_FUNC void alSeqSecToTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D66D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D66DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D66E0: ldc1        $f6, 0x610($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X610);
    // 0x800D66E4: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x800D66E8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800D66EC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D66F0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800D66F4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D66F8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800D66FC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800D6700: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800D6704: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800D6708: bgezl       $a2, L_800D6724
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800D670C: div.d       $f8, $f18, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
            goto L_800D6724;
    }
    goto skip_0;
    // 0x800D670C: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    skip_0:
    // 0x800D6710: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800D6714: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800D6718: nop

    // 0x800D671C: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
    // 0x800D6720: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
L_800D6724:
    // 0x800D6724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D6728: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800D672C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D6730: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800D6734: nop

    // 0x800D6738: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800D673C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800D6740: nop

    // 0x800D6744: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800D6748: beql        $v0, $zero, L_800D67A4
    if (ctx->r2 == 0) {
        // 0x800D674C: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800D67A4;
    }
    goto skip_1;
    // 0x800D674C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x800D6750: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D6754: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D6758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D675C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D6760: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800D6764: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800D6768: nop

    // 0x800D676C: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800D6770: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800D6774: nop

    // 0x800D6778: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800D677C: bnel        $v0, $zero, L_800D6798
    if (ctx->r2 != 0) {
        // 0x800D6780: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_800D6798;
    }
    goto skip_2;
    // 0x800D6780: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_2:
    // 0x800D6784: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800D6788: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D678C: jr          $ra
    // 0x800D6790: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x800D6790: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800D6794: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
L_800D6798:
    // 0x800D6798: jr          $ra
    // 0x800D679C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800D679C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800D67A0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800D67A4:
    // 0x800D67A4: nop

    // 0x800D67A8: bltzl       $v0, L_800D6798
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D67AC: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_800D6798;
    }
    goto skip_3;
    // 0x800D67AC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_3:
    // 0x800D67B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D67B4: jr          $ra
    // 0x800D67B8: nop

    return;
    // 0x800D67B8: nop

;}
RECOMP_FUNC void alSeqTicksToSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D67BC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800D67C0: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800D67C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D67C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D67CC: bgez        $a2, L_800D67E0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800D67D0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800D67E0;
    }
    // 0x800D67D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D67D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D67D8: nop

    // 0x800D67DC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800D67E0:
    // 0x800D67E0: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x800D67E4: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D67E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D67EC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800D67F0: ldc1        $f10, 0x618($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X618);
    // 0x800D67F4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D67F8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800D67FC: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x800D6800: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800D6804: div.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f18.d);
    // 0x800D6808: jr          $ra
    // 0x800D680C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    return;
    // 0x800D680C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
;}
RECOMP_FUNC void __alSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6810: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6818: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x800D681C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D6820: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800D6824: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D6828: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D682C: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x800D6830: bne         $at, $zero, L_800D6840
    if (ctx->r1 != 0) {
        // 0x800D6834: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_800D6840;
    }
    // 0x800D6834: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800D6838: b           L_800D6858
    // 0x800D683C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D6858;
    // 0x800D683C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6840:
    // 0x800D6840: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800D6844: jal         0x800D63E8
    // 0x800D6848: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    static_1_800D63E8(rdram, ctx);
        goto after_0;
    // 0x800D6848: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800D684C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800D6850: sw          $a3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r7;
    // 0x800D6854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D6858:
    // 0x800D6858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D685C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D6860: jr          $ra
    // 0x800D6864: nop

    return;
    // 0x800D6864: nop

;}
RECOMP_FUNC void func_800D6868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6868: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800D686C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800D6870: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x800D6874: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800D6878: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800D687C: sll         $t6, $v1, 24
    ctx->r14 = S32(ctx->r3 << 24);
    // 0x800D6880: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D6884: or          $v1, $t6, $t9
    ctx->r3 = ctx->r14 | ctx->r25;
    // 0x800D6888: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800D688C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800D6890: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800D6894: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D6898: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800D689C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800D68A0: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x800D68A4: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x800D68A8: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800D68AC: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800D68B0: jr          $ra
    // 0x800D68B4: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
    return;
    // 0x800D68B4: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
    // 0x800D68B8: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800D68BC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800D68C0: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x800D68C4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800D68C8: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x800D68CC: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x800D68D0: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800D68D4: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800D68D8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800D68DC: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800D68E0: jr          $ra
    // 0x800D68E4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    return;
    // 0x800D68E4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void alSeqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D68E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D68EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D68F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D68F4: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800D68F8: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    // 0x800D68FC: sh          $zero, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = 0;
    // 0x800D6900: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800D6904: jal         0x800D6868
    // 0x800D6908: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    func_800D6868(rdram, ctx);
        goto after_0;
    // 0x800D6908: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    after_0:
    // 0x800D690C: lui         $at, 0x4D54
    ctx->r1 = S32(0X4D54 << 16);
    // 0x800D6910: ori         $at, $at, 0x6864
    ctx->r1 = ctx->r1 | 0X6864;
    // 0x800D6914: bnel        $v0, $at, L_800D69B4
    if (ctx->r2 != ctx->r1) {
        // 0x800D6918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_0;
    // 0x800D6918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D691C: jal         0x800D6868
    // 0x800D6920: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800D6868(rdram, ctx);
        goto after_1;
    // 0x800D6920: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x800D6924: jal         0x800D68B8
    // 0x800D6928: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    static_1_800D68B8(rdram, ctx);
        goto after_2;
    // 0x800D6928: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x800D692C: bnel        $v0, $zero, L_800D69B4
    if (ctx->r2 != 0) {
        // 0x800D6930: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_1;
    // 0x800D6930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800D6934: jal         0x800D68B8
    // 0x800D6938: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    static_1_800D68B8(rdram, ctx);
        goto after_3;
    // 0x800D6938: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x800D693C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D6940: bnel        $v0, $at, L_800D69B4
    if (ctx->r2 != ctx->r1) {
        // 0x800D6944: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_2;
    // 0x800D6944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800D6948: jal         0x800D68B8
    // 0x800D694C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    static_1_800D68B8(rdram, ctx);
        goto after_4;
    // 0x800D694C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x800D6950: sh          $v0, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r2;
    // 0x800D6954: lh          $v1, 0x18($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X18);
    // 0x800D6958: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800D695C: bnel        $t6, $zero, L_800D69B4
    if (ctx->r14 != 0) {
        // 0x800D6960: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_3;
    // 0x800D6960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800D6964: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800D6968: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D696C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D6970: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D6974: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D6978: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D697C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800D6980: div.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800D6984: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800D6988: jal         0x800D6868
    // 0x800D698C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    func_800D6868(rdram, ctx);
        goto after_5;
    // 0x800D698C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    after_5:
    // 0x800D6990: lui         $at, 0x4D54
    ctx->r1 = S32(0X4D54 << 16);
    // 0x800D6994: ori         $at, $at, 0x726B
    ctx->r1 = ctx->r1 | 0X726B;
    // 0x800D6998: bnel        $v0, $at, L_800D69B4
    if (ctx->r2 != ctx->r1) {
        // 0x800D699C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_4;
    // 0x800D699C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800D69A0: jal         0x800D6868
    // 0x800D69A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800D6868(rdram, ctx);
        goto after_6;
    // 0x800D69A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x800D69A8: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x800D69AC: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800D69B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D69B4:
    // 0x800D69B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D69B8: jr          $ra
    // 0x800D69BC: nop

    return;
    // 0x800D69BC: nop

;}
RECOMP_FUNC void alSynSetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D69C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D69C4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800D69C8: jr          $ra
    // 0x800D69CC: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
    return;
    // 0x800D69CC: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_800D6ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6ABC: nop

;}
RECOMP_FUNC void func_800D6B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6B18: nop

    // 0x800D6B1C: nop

;}
RECOMP_FUNC void func_800D6B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6B6C: nop

;}
RECOMP_FUNC void func_800E8CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8CB0: nop

;}
RECOMP_FUNC void func_800ECC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC14: nop

    // 0x800ECC18: nop

    // 0x800ECC1C: nop

;}
RECOMP_FUNC void func_800ECC24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC24: nop

    // 0x800ECC28: nop

    // 0x800ECC2C: nop

    // 0x800ECC30: nop

    // 0x800ECC34: nop

    // 0x800ECC38: nop

    // 0x800ECC3C: nop

;}
RECOMP_FUNC void func_800ECC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC80: nop

    // 0x800ECC84: nop

    // 0x800ECC88: nop

    // 0x800ECC8C: nop

    // 0x800ECC90: nop

    // 0x800ECC94: nop

    // 0x800ECC98: nop

    // 0x800ECC9C: nop

    // 0x800ECCA0: nop

    // 0x800ECCA4: nop

    // 0x800ECCA8: nop

    // 0x800ECCAC: nop

    // 0x800ECCB0: nop

    // 0x800ECCB4: nop

    // 0x800ECCB8: nop

    // 0x800ECCBC: nop

    // 0x800ECCC0: nop

    // 0x800ECCC4: nop

    // 0x800ECCC8: nop

    // 0x800ECCCC: nop

    // 0x800ECCD0: nop

    // 0x800ECCD4: nop

    // 0x800ECCD8: nop

    // 0x800ECCDC: nop

;}
RECOMP_FUNC void func_800ECCEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECCEC: nop

;}
RECOMP_FUNC void func_800ECCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECCF4: nop

    // 0x800ECCF8: nop

    // 0x800ECCFC: nop

;}
RECOMP_FUNC void func_800ECD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECD18: nop

    // 0x800ECD1C: nop

;}
RECOMP_FUNC void func_800ED024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED024: nop

    // 0x800ED028: nop

    // 0x800ED02C: nop

;}
RECOMP_FUNC void func_800EF790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF790: lb          $t1, -0x7CB0($zero)
    ctx->r9 = MEM_B(0, -0X7CB0);
    // 0x800EF794: lb          $t1, -0x7DA0($zero)
    ctx->r9 = MEM_B(0, -0X7DA0);
    // 0x800EF798: lb          $t1, -0x7F00($zero)
    ctx->r9 = MEM_B(0, -0X7F00);
    // 0x800EF79C: lb          $t1, -0x7CB0($zero)
    ctx->r9 = MEM_B(0, -0X7CB0);
    // 0x800EF7A0: lb          $t1, -0x7CB0($zero)
    ctx->r9 = MEM_B(0, -0X7CB0);
    // 0x800EF7A4: lb          $t1, -0x7DA0($zero)
    ctx->r9 = MEM_B(0, -0X7DA0);
    // 0x800EF7A8: lb          $t1, -0x7DA0($zero)
    ctx->r9 = MEM_B(0, -0X7DA0);
    // 0x800EF7AC: nop

;}
RECOMP_FUNC void static_1_800C82F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C82F0: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800C82F4: bne         $t6, $zero, L_800C83D4
    if (ctx->r14 != 0) {
        // 0x800C82F8: nop

            goto L_800C83D4;
    }
    // 0x800C82F8: nop

    // 0x800C82FC: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800C8300: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C8304: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x800C8308: blez        $t7, L_800C83D4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C830C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C83D4;
    }
    // 0x800C830C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C8310: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C8314: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C8318: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_800C831C:
    // 0x800C831C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C8320: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C8324: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x800C8328: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C832C: bnel        $t6, $zero, L_800C83C0
    if (ctx->r14 != 0) {
        // 0x800C8330: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C83C0;
    }
    goto skip_0;
    // 0x800C8330: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800C8334: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800C8338: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x800C833C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C8340: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C8344: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x800C8348: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800C834C: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x800C8350: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C8354: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800C8358: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800C835C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x800C8360: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800C8364: bnel        $t9, $zero, L_800C83C0
    if (ctx->r25 != 0) {
        // 0x800C8368: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C83C0;
    }
    goto skip_1;
    // 0x800C8368: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_1:
    // 0x800C836C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800C8370: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x800C8374: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x800C8378: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C837C: bne         $a2, $zero, L_800C83A4
    if (ctx->r6 != 0) {
        // 0x800C8380: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_800C83A4;
    }
    // 0x800C8380: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C8384: lw          $t8, 0x10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X10);
    // 0x800C8388: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C838C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C8390: beq         $a2, $zero, L_800C83BC
    if (ctx->r6 == 0) {
        // 0x800C8394: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_800C83BC;
    }
    // 0x800C8394: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x800C8398: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x800C839C: b           L_800C83BC
    // 0x800C83A0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_800C83BC;
    // 0x800C83A0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_800C83A4:
    // 0x800C83A4: bnel        $t2, $a2, L_800C83C0
    if (ctx->r10 != ctx->r6) {
        // 0x800C83A8: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C83C0;
    }
    goto skip_2;
    // 0x800C83A8: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_2:
    // 0x800C83AC: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C83B0: beq         $a2, $zero, L_800C83BC
    if (ctx->r6 == 0) {
        // 0x800C83B4: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_800C83BC;
    }
    // 0x800C83B4: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x800C83B8: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_800C83BC:
    // 0x800C83BC: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
L_800C83C0:
    // 0x800C83C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C83C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C83C8: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C83CC: bnel        $at, $zero, L_800C831C
    if (ctx->r1 != 0) {
        // 0x800C83D0: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_800C831C;
    }
    goto skip_3;
    // 0x800C83D0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
L_800C83D4:
    // 0x800C83D4: jr          $ra
    // 0x800C83D8: nop

    return;
    // 0x800C83D8: nop

    // 0x800C83DC: jr          $ra
    // 0x800C83E0: nop

    return;
    // 0x800C83E0: nop

;}
RECOMP_FUNC void static_1_800C85DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C85DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C85E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C85E4: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800C85E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C85EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C85F0: bne         $t6, $at, L_800C879C
    if (ctx->r14 != ctx->r1) {
        // 0x800C85F4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800C879C;
    }
    // 0x800C85F4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C85F8: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800C85FC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800C8600: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800C8604: bnel        $t7, $at, L_800C87A0
    if (ctx->r15 != ctx->r1) {
        // 0x800C8608: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C87A0;
    }
    goto skip_0;
    // 0x800C8608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C860C: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x800C8610: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x800C8614: lw          $fp, 0x24($s7)
    ctx->r30 = MEM_W(ctx->r23, 0X24);
    // 0x800C8618: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C861C: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x800C8620: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C8624: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C8628: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800C862C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800C8630: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800C8634: jal         0x800C85A0
    // 0x800C8638: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800C85A0(rdram, ctx);
        goto after_0;
    // 0x800C8638: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800C863C: lw          $s1, 0x50($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X50);
    // 0x800C8640: beq         $s1, $zero, L_800C86B8
    if (ctx->r17 == 0) {
        // 0x800C8644: nop

            goto L_800C86B8;
    }
    // 0x800C8644: nop

    // 0x800C8648: addiu       $s4, $zero, 0x15
    ctx->r20 = ADD32(0, 0X15);
L_800C864C:
    // 0x800C864C: lh          $t7, 0xC($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC);
    // 0x800C8650: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800C8654: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x800C8658: bne         $s4, $t7, L_800C86B0
    if (ctx->r20 != ctx->r15) {
        // 0x800C865C: addu        $s0, $s0, $t9
        ctx->r16 = ADD32(ctx->r16, ctx->r25);
            goto L_800C86B0;
    }
    // 0x800C865C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x800C8660: jal         0x800C7890
    // 0x800C8664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C8664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800C8668: beql        $s3, $zero, L_800C8688
    if (ctx->r19 == 0) {
        // 0x800C866C: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_800C8688;
    }
    goto skip_1;
    // 0x800C866C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_1:
    // 0x800C8670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C8674: jal         0x800C78C0
    // 0x800C8678: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C8678: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x800C867C: b           L_800C8690
    // 0x800C8680: nop

        goto L_800C8690;
    // 0x800C8680: nop

    // 0x800C8684: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800C8688:
    // 0x800C8688: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x800C868C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
L_800C8690:
    // 0x800C8690: beq         $s2, $zero, L_800C86AC
    if (ctx->r18 == 0) {
        // 0x800C8694: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_800C86AC;
    }
    // 0x800C8694: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800C8698: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x800C869C: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x800C86A0: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C86A4: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800C86A8: sw          $t6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r14;
L_800C86AC:
    // 0x800C86AC: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_800C86B0:
    // 0x800C86B0: bne         $s2, $zero, L_800C864C
    if (ctx->r18 != 0) {
        // 0x800C86B4: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800C864C;
    }
    // 0x800C86B4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_800C86B8:
    // 0x800C86B8: beq         $s3, $zero, L_800C879C
    if (ctx->r19 == 0) {
        // 0x800C86BC: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_800C879C;
    }
    // 0x800C86BC: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800C86C0: addiu       $s4, $s7, 0x48
    ctx->r20 = ADD32(ctx->r23, 0X48);
    // 0x800C86C4: addiu       $s5, $s4, 0x8
    ctx->r21 = ADD32(ctx->r20, 0X8);
    // 0x800C86C8: addiu       $s6, $zero, -0x8
    ctx->r22 = ADD32(0, -0X8);
L_800C86CC:
    // 0x800C86CC: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800C86D0: lw          $t7, 0x24($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X24);
    // 0x800C86D4: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x800C86D8: div         $zero, $t9, $fp
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r30)));
    // 0x800C86DC: mflo        $v0
    ctx->r2 = lo;
    // 0x800C86E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C86E4: bne         $fp, $zero, L_800C86F0
    if (ctx->r30 != 0) {
        // 0x800C86E8: nop

            goto L_800C86F0;
    }
    // 0x800C86E8: nop

    // 0x800C86EC: break       7
    do_break(2148304620);
L_800C86F0:
    // 0x800C86F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C86F4: bne         $fp, $at, L_800C8708
    if (ctx->r30 != ctx->r1) {
        // 0x800C86F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C8708;
    }
    // 0x800C86F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C86FC: bne         $t9, $at, L_800C8708
    if (ctx->r25 != ctx->r1) {
        // 0x800C8700: nop

            goto L_800C8708;
    }
    // 0x800C8700: nop

    // 0x800C8704: break       6
    do_break(2148304644);
L_800C8708:
    // 0x800C8708: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C870C: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x800C8710: mflo        $t8
    ctx->r24 = lo;
    // 0x800C8714: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x800C8718: jal         0x800C41A0
    // 0x800C871C: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C871C: nop

    after_3:
    // 0x800C8720: beq         $s4, $s6, L_800C878C
    if (ctx->r20 == ctx->r22) {
        // 0x800C8724: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800C878C;
    }
    // 0x800C8724: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C8728: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800C872C:
    // 0x800C872C: bnel        $a0, $zero, L_800C874C
    if (ctx->r4 != 0) {
        // 0x800C8730: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_800C874C;
    }
    goto skip_2;
    // 0x800C8730: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_2:
    // 0x800C8734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C8738: jal         0x800C78C0
    // 0x800C873C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800C873C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800C8740: b           L_800C878C
    // 0x800C8744: nop

        goto L_800C878C;
    // 0x800C8744: nop

    // 0x800C8748: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_800C874C:
    // 0x800C874C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800C8750: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8754: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C8758: beq         $at, $zero, L_800C877C
    if (ctx->r1 == 0) {
        // 0x800C875C: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800C877C;
    }
    // 0x800C875C: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800C8760: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x800C8764: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800C8768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C876C: jal         0x800C78C0
    // 0x800C8770: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800C8770: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800C8774: b           L_800C878C
    // 0x800C8778: nop

        goto L_800C878C;
    // 0x800C8778: nop

L_800C877C:
    // 0x800C877C: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x800C8780: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800C8784: bnel        $s0, $zero, L_800C872C
    if (ctx->r16 != 0) {
        // 0x800C8788: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800C872C;
    }
    goto skip_3;
    // 0x800C8788: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_800C878C:
    // 0x800C878C: jal         0x800C41A0
    // 0x800C8790: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800C8790: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x800C8794: bne         $s2, $zero, L_800C86CC
    if (ctx->r18 != 0) {
        // 0x800C8798: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800C86CC;
    }
    // 0x800C8798: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_800C879C:
    // 0x800C879C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C87A0:
    // 0x800C87A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C87A4: jr          $ra
    // 0x800C87A8: nop

    return;
    // 0x800C87A8: nop

;}
RECOMP_FUNC void static_1_800C87AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87AC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C87B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C87B4: lbu         $s6, 0x8($t0)
    ctx->r22 = MEM_BU(ctx->r8, 0X8);
    // 0x800C87B8: lbu         $s4, 0x9($t0)
    ctx->r20 = MEM_BU(ctx->r8, 0X9);
    // 0x800C87BC: lbu         $s1, 0xA($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0XA);
    // 0x800C87C0: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x800C87C4: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x800C87C8: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x800C87CC: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x800C87D0: beq         $at, $zero, L_800C8FC4
    if (ctx->r1 == 0) {
        // 0x800C87D4: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_800C8FC4;
    }
    // 0x800C87D4: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x800C87D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C87DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C87E0: addu        $at, $at, $t7
    gpr jr_addend_800C87E8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C87E4: lw          $t7, -0x90($at)
    ctx->r15 = ADD32(ctx->r1, -0X90);
    // 0x800C87E8: jr          $t7
    // 0x800C87EC: nop

    switch (jr_addend_800C87E8 >> 2) {
        case 0: goto L_800C8B90; break;
        case 1: goto L_800C8FC4; break;
        case 2: goto L_800C8FC4; break;
        case 3: goto L_800C8FC4; break;
        case 4: goto L_800C8FC4; break;
        case 5: goto L_800C8FC4; break;
        case 6: goto L_800C8FC4; break;
        case 7: goto L_800C8FC4; break;
        case 8: goto L_800C8FC4; break;
        case 9: goto L_800C8FC4; break;
        case 10: goto L_800C8FC4; break;
        case 11: goto L_800C8FC4; break;
        case 12: goto L_800C8FC4; break;
        case 13: goto L_800C8FC4; break;
        case 14: goto L_800C8FC4; break;
        case 15: goto L_800C8FC4; break;
        case 16: goto L_800C87F0; break;
        case 17: goto L_800C8FC4; break;
        case 18: goto L_800C8FC4; break;
        case 19: goto L_800C8FC4; break;
        case 20: goto L_800C8FC4; break;
        case 21: goto L_800C8FC4; break;
        case 22: goto L_800C8FC4; break;
        case 23: goto L_800C8FC4; break;
        case 24: goto L_800C8FC4; break;
        case 25: goto L_800C8FC4; break;
        case 26: goto L_800C8FC4; break;
        case 27: goto L_800C8FC4; break;
        case 28: goto L_800C8FC4; break;
        case 29: goto L_800C8FC4; break;
        case 30: goto L_800C8FC4; break;
        case 31: goto L_800C8FC4; break;
        case 32: goto L_800C8BE8; break;
        case 33: goto L_800C8FC4; break;
        case 34: goto L_800C8FC4; break;
        case 35: goto L_800C8FC4; break;
        case 36: goto L_800C8FC4; break;
        case 37: goto L_800C8FC4; break;
        case 38: goto L_800C8FC4; break;
        case 39: goto L_800C8FC4; break;
        case 40: goto L_800C8FC4; break;
        case 41: goto L_800C8FC4; break;
        case 42: goto L_800C8FC4; break;
        case 43: goto L_800C8FC4; break;
        case 44: goto L_800C8FC4; break;
        case 45: goto L_800C8FC4; break;
        case 46: goto L_800C8FC4; break;
        case 47: goto L_800C8FC4; break;
        case 48: goto L_800C8CC0; break;
        case 49: goto L_800C8FC4; break;
        case 50: goto L_800C8FC4; break;
        case 51: goto L_800C8FC4; break;
        case 52: goto L_800C8FC4; break;
        case 53: goto L_800C8FC4; break;
        case 54: goto L_800C8FC4; break;
        case 55: goto L_800C8FC4; break;
        case 56: goto L_800C8FC4; break;
        case 57: goto L_800C8FC4; break;
        case 58: goto L_800C8FC4; break;
        case 59: goto L_800C8FC4; break;
        case 60: goto L_800C8FC4; break;
        case 61: goto L_800C8FC4; break;
        case 62: goto L_800C8FC4; break;
        case 63: goto L_800C8FC4; break;
        case 64: goto L_800C8EF8; break;
        case 65: goto L_800C8FC4; break;
        case 66: goto L_800C8FC4; break;
        case 67: goto L_800C8FC4; break;
        case 68: goto L_800C8FC4; break;
        case 69: goto L_800C8FC4; break;
        case 70: goto L_800C8FC4; break;
        case 71: goto L_800C8FC4; break;
        case 72: goto L_800C8FC4; break;
        case 73: goto L_800C8FC4; break;
        case 74: goto L_800C8FC4; break;
        case 75: goto L_800C8FC4; break;
        case 76: goto L_800C8FC4; break;
        case 77: goto L_800C8FC4; break;
        case 78: goto L_800C8FC4; break;
        case 79: goto L_800C8FC4; break;
        case 80: goto L_800C8C4C; break;
        case 81: goto L_800C8FC4; break;
        case 82: goto L_800C8FC4; break;
        case 83: goto L_800C8FC4; break;
        case 84: goto L_800C8FC4; break;
        case 85: goto L_800C8FC4; break;
        case 86: goto L_800C8FC4; break;
        case 87: goto L_800C8FC4; break;
        case 88: goto L_800C8FC4; break;
        case 89: goto L_800C8FC4; break;
        case 90: goto L_800C8FC4; break;
        case 91: goto L_800C8FC4; break;
        case 92: goto L_800C8FC4; break;
        case 93: goto L_800C8FC4; break;
        case 94: goto L_800C8FC4; break;
        case 95: goto L_800C8FC4; break;
        case 96: goto L_800C8F2C; break;
        default: switch_error(__func__, 0x800C87E8, 0x800EFF70);
    }
    // 0x800C87EC: nop

L_800C87F0:
    // 0x800C87F0: beql        $s1, $zero, L_800C8B94
    if (ctx->r17 == 0) {
        // 0x800C87F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C8B94;
    }
    goto skip_0;
    // 0x800C87F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x800C87F8: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x800C87FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C8800: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8804: bne         $t8, $at, L_800C8FC4
    if (ctx->r24 != ctx->r1) {
        // 0x800C8808: andi        $a1, $s4, 0xFF
        ctx->r5 = ctx->r20 & 0XFF;
            goto L_800C8FC4;
    }
    // 0x800C8808: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C880C: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C8810: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800C8814: jal         0x800D26D0
    // 0x800C8818: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    __lookupSoundQuick(rdram, ctx);
        goto after_0;
    // 0x800C8818: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_0:
    // 0x800C881C: beq         $v0, $zero, L_800C8FC4
    if (ctx->r2 == 0) {
        // 0x800C8820: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800C8FC4;
    }
    // 0x800C8820: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800C8824: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800C8828: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800C882C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8830: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800C8834: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x800C8838: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x800C883C: sb          $zero, 0x78($sp)
    MEM_B(0X78, ctx->r29) = 0;
    // 0x800C8840: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C8844: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C8848: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800C884C: jal         0x800D2660
    // 0x800C8850: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    __mapVoice(rdram, ctx);
        goto after_1;
    // 0x800C8850: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    after_1:
    // 0x800C8854: beq         $v0, $zero, L_800C8FC4
    if (ctx->r2 == 0) {
        // 0x800C8858: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8FC4;
    }
    // 0x800C8858: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C885C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8860: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800C8864: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x800C8868: jal         0x800D3FE8
    // 0x800C886C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    alSynAllocVoice(rdram, ctx);
        goto after_2;
    // 0x800C886C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x800C8870: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x800C8874: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x800C8878: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800C887C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800C8880: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x800C8884: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x800C8888: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x800C888C: bnel        $at, $zero, L_800C88A0
    if (ctx->r1 != 0) {
        // 0x800C8890: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_800C88A0;
    }
    goto skip_1;
    // 0x800C8890: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
    // 0x800C8894: b           L_800C88A0
    // 0x800C8898: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800C88A0;
    // 0x800C8898: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x800C889C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800C88A0:
    // 0x800C88A0: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x800C88A4: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C88A8: lb          $t6, 0x5($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5);
    // 0x800C88AC: subu        $t8, $s4, $t7
    ctx->r24 = SUB32(ctx->r20, ctx->r15);
    // 0x800C88B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C88B4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C88B8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C88BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C88C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C88C4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x800C88C8: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800C88CC: jal         0x800CADC0
    // 0x800C88D0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x800C88D0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x800C88D4: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800C88D8: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800C88DC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800C88E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C88E4: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x800C88E8: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x800C88EC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800C88F0: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    // 0x800C88F4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800C88F8: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x800C88FC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800C8900: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x800C8904: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800C8908: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x800C890C: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x800C8910: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800C8914: lbu         $a2, 0x4($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X4);
    // 0x800C8918: beql        $a2, $zero, L_800C8984
    if (ctx->r6 == 0) {
        // 0x800C891C: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800C8984;
    }
    goto skip_2;
    // 0x800C891C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x800C8920: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800C8924: beql        $v0, $zero, L_800C8984
    if (ctx->r2 == 0) {
        // 0x800C8928: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800C8984;
    }
    goto skip_3;
    // 0x800C8928: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
    // 0x800C892C: lbu         $t9, 0x6($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6);
    // 0x800C8930: lbu         $a3, 0x5($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X5);
    // 0x800C8934: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800C8938: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C893C: lbu         $t6, 0x7($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X7);
    // 0x800C8940: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800C8944: jalr        $v0
    // 0x800C8948: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800C8948: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x800C894C: beq         $v0, $zero, L_800C8980
    if (ctx->r2 == 0) {
        // 0x800C8950: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_800C8980;
    }
    // 0x800C8950: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800C8954: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800C8958: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C895C: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800C8960: addiu       $a0, $s2, 0x48
    ctx->r4 = ADD32(ctx->r18, 0X48);
    // 0x800C8964: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C8968: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C896C: jal         0x800D3A2C
    // 0x800C8970: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x800C8970: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_5:
    // 0x800C8974: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800C8978: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x800C897C: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800C8980:
    // 0x800C8980: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_800C8984:
    // 0x800C8984: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C8988: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C898C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C8990: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C8994: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C8998: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C899C: nop

    // 0x800C89A0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800C89A4: beql        $t7, $zero, L_800C89F4
    if (ctx->r15 == 0) {
        // 0x800C89A8: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_800C89F4;
    }
    goto skip_4;
    // 0x800C89A8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x800C89AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C89B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C89B4: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C89B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C89BC: nop

    // 0x800C89C0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C89C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C89C8: nop

    // 0x800C89CC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800C89D0: bne         $t7, $zero, L_800C89E8
    if (ctx->r15 != 0) {
        // 0x800C89D4: nop

            goto L_800C89E8;
    }
    // 0x800C89D4: nop

    // 0x800C89D8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C89DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C89E0: b           L_800C8A00
    // 0x800C89E4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800C8A00;
    // 0x800C89E4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800C89E8:
    // 0x800C89E8: b           L_800C8A00
    // 0x800C89EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800C8A00;
    // 0x800C89EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C89F0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_800C89F4:
    // 0x800C89F4: nop

    // 0x800C89F8: bltz        $t7, L_800C89E8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800C89FC: nop

            goto L_800C89E8;
    }
    // 0x800C89FC: nop

L_800C8A00:
    // 0x800C8A00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C8A04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C8A08: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x800C8A0C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C8A10: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800C8A14: lbu         $a2, 0x8($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X8);
    // 0x800C8A18: addiu       $s5, $s2, 0x48
    ctx->r21 = ADD32(ctx->r18, 0X48);
    // 0x800C8A1C: beql        $a2, $zero, L_800C8A8C
    if (ctx->r6 == 0) {
        // 0x800C8A20: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800C8A8C;
    }
    goto skip_5;
    // 0x800C8A20: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_5:
    // 0x800C8A24: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800C8A28: beql        $v0, $zero, L_800C8A8C
    if (ctx->r2 == 0) {
        // 0x800C8A2C: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800C8A8C;
    }
    goto skip_6;
    // 0x800C8A2C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_6:
    // 0x800C8A30: lbu         $t9, 0xA($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XA);
    // 0x800C8A34: lbu         $a3, 0x9($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X9);
    // 0x800C8A38: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800C8A3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C8A40: lbu         $t6, 0xB($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XB);
    // 0x800C8A44: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800C8A48: jalr        $v0
    // 0x800C8A4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800C8A4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x800C8A50: beq         $v0, $zero, L_800C8A88
    if (ctx->r2 == 0) {
        // 0x800C8A54: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_800C8A88;
    }
    // 0x800C8A54: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x800C8A58: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800C8A5C: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C8A60: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800C8A64: sb          $s6, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r22;
    // 0x800C8A68: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C8A6C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C8A70: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C8A74: jal         0x800D3A2C
    // 0x800C8A78: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x800C8A78: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_7:
    // 0x800C8A7C: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800C8A80: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x800C8A84: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800C8A88:
    // 0x800C8A88: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
L_800C8A8C:
    // 0x800C8A8C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800C8A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8A94: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800C8A98: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800C8A9C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800C8AA0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C8AA4: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x800C8AA8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800C8AAC: lbu         $s1, 0xA($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0XA);
    // 0x800C8AB0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C8AB4: nop

    // 0x800C8AB8: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800C8ABC: jal         0x800D25A4
    // 0x800C8AC0: nop

    __vsPan(rdram, ctx);
        goto after_8;
    // 0x800C8AC0: nop

    after_8:
    // 0x800C8AC4: andi        $fp, $v0, 0xFF
    ctx->r30 = ctx->r2 & 0XFF;
    // 0x800C8AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8ACC: jal         0x800D2184
    // 0x800C8AD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_9;
    // 0x800C8AD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x800C8AD4: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800C8AD8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8ADC: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x800C8AE0: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x800C8AE4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C8AE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C8AEC: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x800C8AF0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C8AF4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800C8AF8: jal         0x800D4130
    // 0x800C8AFC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    alSynStartVoiceParams(rdram, ctx);
        goto after_10;
    // 0x800C8AFC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
    // 0x800C8B00: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800C8B04: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800C8B08: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x800C8B0C: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x800C8B10: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800C8B14: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C8B18: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C8B1C: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x800C8B20: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C8B24: sb          $t7, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r15;
    // 0x800C8B28: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800C8B2C: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800C8B30: jal         0x800D3A2C
    // 0x800C8B34: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    alEvtqPostEvent(rdram, ctx);
        goto after_11;
    // 0x800C8B34: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    after_11:
    // 0x800C8B38: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x800C8B3C: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x800C8B40: ori         $t9, $s6, 0x80
    ctx->r25 = ctx->r22 | 0X80;
    // 0x800C8B44: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800C8B48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C8B4C: beql        $t8, $zero, L_800C8FC8
    if (ctx->r24 == 0) {
        // 0x800C8B50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_7;
    // 0x800C8B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x800C8B54: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x800C8B58: sb          $t9, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r25;
    // 0x800C8B5C: sb          $s4, 0x95($sp)
    MEM_B(0X95, ctx->r29) = ctx->r20;
    // 0x800C8B60: sb          $zero, 0x96($sp)
    MEM_B(0X96, ctx->r29) = 0;
    // 0x800C8B64: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800C8B68: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x800C8B6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C8B70: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C8B74: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8B78: mflo        $s3
    ctx->r19 = lo;
    // 0x800C8B7C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C8B80: jal         0x800D3A2C
    // 0x800C8B84: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_12;
    // 0x800C8B84: nop

    after_12:
    // 0x800C8B88: b           L_800C8FC8
    // 0x800C8B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8B90:
    // 0x800C8B90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C8B94:
    // 0x800C8B94: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C8B98: jal         0x800D25EC
    // 0x800C8B9C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_13;
    // 0x800C8B9C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_13:
    // 0x800C8BA0: beq         $v0, $zero, L_800C8FC4
    if (ctx->r2 == 0) {
        // 0x800C8BA4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8FC4;
    }
    // 0x800C8BA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C8BA8: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x800C8BAC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800C8BB0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800C8BB4: bne         $s6, $t7, L_800C8BC4
    if (ctx->r22 != ctx->r15) {
        // 0x800C8BB8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C8BC4;
    }
    // 0x800C8BB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8BBC: b           L_800C8FC4
    // 0x800C8BC0: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_800C8FC4;
    // 0x800C8BC0: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_800C8BC4:
    // 0x800C8BC4: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800C8BC8: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800C8BCC: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800C8BD0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800C8BD4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8BD8: jal         0x800D220C
    // 0x800C8BDC: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    __seqpReleaseVoice(rdram, ctx);
        goto after_14;
    // 0x800C8BDC: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_14:
    // 0x800C8BE0: b           L_800C8FC8
    // 0x800C8BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8BE8:
    // 0x800C8BE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8BEC: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C8BF0: jal         0x800D25EC
    // 0x800C8BF4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_15;
    // 0x800C8BF4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_15:
    // 0x800C8BF8: beq         $v0, $zero, L_800C8FC4
    if (ctx->r2 == 0) {
        // 0x800C8BFC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8FC4;
    }
    // 0x800C8BFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C8C00: sb          $s1, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r17;
    // 0x800C8C04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C8C08: jal         0x800D2184
    // 0x800C8C0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_16;
    // 0x800C8C0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x800C8C10: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C8C14: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C8C18: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800C8C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8C20: jal         0x800D2160
    // 0x800C8C24: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __vsDelta(rdram, ctx);
        goto after_17;
    // 0x800C8C24: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_17:
    // 0x800C8C28: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C8C2C: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C8C30: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C8C34: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8C38: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8C3C: jal         0x800D3DD0
    // 0x800C8C40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_18;
    // 0x800C8C40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
    // 0x800C8C44: b           L_800C8FC8
    // 0x800C8C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8C4C:
    // 0x800C8C4C: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8C50: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8C54: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_8;
    // 0x800C8C54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x800C8C58: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8C5C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800C8C60:
    // 0x800C8C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8C64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C8C68: bnel        $s3, $t6, L_800C8CB0
    if (ctx->r19 != ctx->r14) {
        // 0x800C8C6C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8CB0;
    }
    goto skip_9;
    // 0x800C8C6C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x800C8C70: jal         0x800D2184
    // 0x800C8C74: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    __vsVol(rdram, ctx);
        goto after_19;
    // 0x800C8C74: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    after_19:
    // 0x800C8C78: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C8C7C: sra         $t8, $s1, 16
    ctx->r24 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C8C80: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800C8C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8C88: jal         0x800D2160
    // 0x800C8C8C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __vsDelta(rdram, ctx);
        goto after_20;
    // 0x800C8C8C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_20:
    // 0x800C8C90: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C8C94: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C8C98: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C8C9C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8CA0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8CA4: jal         0x800D3DD0
    // 0x800C8CA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_21;
    // 0x800C8CA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_21:
    // 0x800C8CAC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8CB0:
    // 0x800C8CB0: bnel        $s0, $zero, L_800C8C60
    if (ctx->r16 != 0) {
        // 0x800C8CB4: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8C60;
    }
    goto skip_10;
    // 0x800C8CB4: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_10:
    // 0x800C8CB8: b           L_800C8FC8
    // 0x800C8CBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8CBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8CC0:
    // 0x800C8CC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800C8CC4: beq         $s4, $at, L_800C8D54
    if (ctx->r20 == ctx->r1) {
        // 0x800C8CC8: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_800C8D54;
    }
    // 0x800C8CC8: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800C8CCC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800C8CD0: beq         $v0, $at, L_800C8CF8
    if (ctx->r2 == ctx->r1) {
        // 0x800C8CD4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800C8CF8;
    }
    // 0x800C8CD4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C8CD8: beq         $v0, $at, L_800C8DE4
    if (ctx->r2 == ctx->r1) {
        // 0x800C8CDC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800C8DE4;
    }
    // 0x800C8CDC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800C8CE0: beq         $v0, $at, L_800C8DF8
    if (ctx->r2 == ctx->r1) {
        // 0x800C8CE4: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_800C8DF8;
    }
    // 0x800C8CE4: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800C8CE8: beql        $v0, $at, L_800C8EAC
    if (ctx->r2 == ctx->r1) {
        // 0x800C8CEC: lw          $t9, 0x60($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X60);
            goto L_800C8EAC;
    }
    goto skip_11;
    // 0x800C8CEC: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    skip_11:
    // 0x800C8CF0: b           L_800C8FC8
    // 0x800C8CF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8CF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8CF8:
    // 0x800C8CF8: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800C8CFC: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C8D00: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C8D04: sb          $s1, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r17;
    // 0x800C8D08: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8D0C: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8D10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_12;
    // 0x800C8D10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x800C8D14: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8D18: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C8D1C:
    // 0x800C8D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8D20: bnel        $s3, $t7, L_800C8D44
    if (ctx->r19 != ctx->r15) {
        // 0x800C8D24: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8D44;
    }
    goto skip_13;
    // 0x800C8D24: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x800C8D28: jal         0x800D25A4
    // 0x800C8D2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsPan(rdram, ctx);
        goto after_22;
    // 0x800C8D2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_22:
    // 0x800C8D30: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8D34: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8D38: jal         0x800D4220
    // 0x800C8D3C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_23;
    // 0x800C8D3C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_23:
    // 0x800C8D40: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8D44:
    // 0x800C8D44: bnel        $s0, $zero, L_800C8D1C
    if (ctx->r16 != 0) {
        // 0x800C8D48: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8D1C;
    }
    goto skip_14;
    // 0x800C8D48: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_14:
    // 0x800C8D4C: b           L_800C8FC8
    // 0x800C8D50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8D50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8D54:
    // 0x800C8D54: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800C8D58: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C8D5C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C8D60: sb          $s1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r17;
    // 0x800C8D64: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8D68: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8D6C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_15;
    // 0x800C8D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x800C8D70: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8D74: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800C8D78: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C8D7C:
    // 0x800C8D7C: bnel        $s3, $t7, L_800C8DD4
    if (ctx->r19 != ctx->r15) {
        // 0x800C8D80: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8DD4;
    }
    goto skip_16;
    // 0x800C8D80: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_16:
    // 0x800C8D84: lbu         $t9, 0x34($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X34);
    // 0x800C8D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8D8C: beql        $s4, $t9, L_800C8DD4
    if (ctx->r20 == ctx->r25) {
        // 0x800C8D90: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8DD4;
    }
    goto skip_17;
    // 0x800C8D90: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x800C8D94: jal         0x800D2184
    // 0x800C8D98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_24;
    // 0x800C8D98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x800C8D9C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C8DA0: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C8DA4: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800C8DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8DAC: jal         0x800D2160
    // 0x800C8DB0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __vsDelta(rdram, ctx);
        goto after_25;
    // 0x800C8DB0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_25:
    // 0x800C8DB4: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C8DB8: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C8DBC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C8DC0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8DC4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8DC8: jal         0x800D3DD0
    // 0x800C8DCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_26;
    // 0x800C8DCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x800C8DD0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8DD4:
    // 0x800C8DD4: bnel        $s0, $zero, L_800C8D7C
    if (ctx->r16 != 0) {
        // 0x800C8DD8: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8D7C;
    }
    goto skip_18;
    // 0x800C8DD8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_18:
    // 0x800C8DDC: b           L_800C8FC8
    // 0x800C8DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8DE4:
    // 0x800C8DE4: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800C8DE8: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x800C8DEC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800C8DF0: b           L_800C8FC4
    // 0x800C8DF4: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
        goto L_800C8FC4;
    // 0x800C8DF4: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
L_800C8DF8:
    // 0x800C8DF8: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800C8DFC: sll         $t7, $s6, 4
    ctx->r15 = S32(ctx->r22 << 4);
    // 0x800C8E00: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800C8E04: sb          $s1, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r17;
    // 0x800C8E08: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8E0C: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8E10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_19;
    // 0x800C8E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x800C8E14: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8E18: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800C8E1C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800C8E20: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800C8E24: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800C8E28: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800C8E2C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800C8E30:
    // 0x800C8E30: bnel        $s3, $t6, L_800C8E98
    if (ctx->r19 != ctx->r14) {
        // 0x800C8E34: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8E98;
    }
    goto skip_20;
    // 0x800C8E34: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x800C8E38: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800C8E3C: slti        $at, $s1, 0x40
    ctx->r1 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x800C8E40: beql        $s4, $v0, L_800C8E98
    if (ctx->r20 == ctx->r2) {
        // 0x800C8E44: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8E98;
    }
    goto skip_21;
    // 0x800C8E44: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x800C8E48: bne         $at, $zero, L_800C8E60
    if (ctx->r1 != 0) {
        // 0x800C8E4C: nop

            goto L_800C8E60;
    }
    // 0x800C8E4C: nop

    // 0x800C8E50: bnel        $v0, $zero, L_800C8E98
    if (ctx->r2 != 0) {
        // 0x800C8E54: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8E98;
    }
    goto skip_22;
    // 0x800C8E54: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
    // 0x800C8E58: b           L_800C8E94
    // 0x800C8E5C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800C8E94;
    // 0x800C8E5C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_800C8E60:
    // 0x800C8E60: bne         $s6, $v0, L_800C8E70
    if (ctx->r22 != ctx->r2) {
        // 0x800C8E64: nop

            goto L_800C8E70;
    }
    // 0x800C8E64: nop

    // 0x800C8E68: b           L_800C8E94
    // 0x800C8E6C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_800C8E94;
    // 0x800C8E6C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800C8E70:
    // 0x800C8E70: bnel        $s7, $v0, L_800C8E98
    if (ctx->r23 != ctx->r2) {
        // 0x800C8E74: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8E98;
    }
    goto skip_23;
    // 0x800C8E74: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
    // 0x800C8E78: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x800C8E7C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800C8E80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8E84: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800C8E88: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8E8C: jal         0x800D220C
    // 0x800C8E90: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    __seqpReleaseVoice(rdram, ctx);
        goto after_27;
    // 0x800C8E90: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    after_27:
L_800C8E94:
    // 0x800C8E94: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8E98:
    // 0x800C8E98: bnel        $s0, $zero, L_800C8E30
    if (ctx->r16 != 0) {
        // 0x800C8E9C: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8E30;
    }
    goto skip_24;
    // 0x800C8E9C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x800C8EA0: b           L_800C8FC8
    // 0x800C8EA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8EA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C8EA8: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
L_800C8EAC:
    // 0x800C8EAC: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C8EB0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C8EB4: sb          $s1, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r17;
    // 0x800C8EB8: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8EBC: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8EC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_25;
    // 0x800C8EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
    // 0x800C8EC4: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8EC8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C8ECC:
    // 0x800C8ECC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8ED0: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C8ED4: bnel        $s3, $t7, L_800C8EE8
    if (ctx->r19 != ctx->r15) {
        // 0x800C8ED8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8EE8;
    }
    goto skip_26;
    // 0x800C8ED8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x800C8EDC: jal         0x800D42B0
    // 0x800C8EE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    alSynSetFXMix(rdram, ctx);
        goto after_28;
    // 0x800C8EE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_28:
    // 0x800C8EE4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8EE8:
    // 0x800C8EE8: bnel        $s0, $zero, L_800C8ECC
    if (ctx->r16 != 0) {
        // 0x800C8EEC: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8ECC;
    }
    goto skip_27;
    // 0x800C8EEC: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x800C8EF0: b           L_800C8FC8
    // 0x800C8EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8EF8:
    // 0x800C8EF8: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800C8EFC: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x800C8F00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8F04: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800C8F08: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800C8F0C: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800C8F10: slt         $at, $s4, $t9
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C8F14: beql        $at, $zero, L_800C8FC8
    if (ctx->r1 == 0) {
        // 0x800C8F18: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_28;
    // 0x800C8F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x800C8F1C: jal         0x800D1FD0
    // 0x800C8F20: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    __setInstChanState(rdram, ctx);
        goto after_29;
    // 0x800C8F20: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    after_29:
    // 0x800C8F24: b           L_800C8FC8
    // 0x800C8F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8F2C:
    // 0x800C8F2C: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800C8F30: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800C8F34: sll         $t8, $s1, 7
    ctx->r24 = S32(ctx->r17 << 7);
    // 0x800C8F38: addu        $t9, $t7, $fp
    ctx->r25 = ADD32(ctx->r15, ctx->r30);
    // 0x800C8F3C: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x800C8F40: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x800C8F44: addiu       $t9, $t7, -0x2000
    ctx->r25 = ADD32(ctx->r15, -0X2000);
    // 0x800C8F48: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8F4C: mflo        $a0
    ctx->r4 = lo;
    // 0x800C8F50: bgez        $a0, L_800C8F60
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C8F54: sra         $t8, $a0, 13
        ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
            goto L_800C8F60;
    }
    // 0x800C8F54: sra         $t8, $a0, 13
    ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
    // 0x800C8F58: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x800C8F5C: sra         $t8, $at, 13
    ctx->r24 = S32(SIGNED(ctx->r1) >> 13);
L_800C8F60:
    // 0x800C8F60: jal         0x800CADC0
    // 0x800C8F64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_30;
    // 0x800C8F64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_30:
    // 0x800C8F68: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800C8F6C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C8F70: addu        $t6, $t7, $fp
    ctx->r14 = ADD32(ctx->r15, ctx->r30);
    // 0x800C8F74: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x800C8F78: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8F7C: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8F80: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_29;
    // 0x800C8F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
    // 0x800C8F84: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8F88: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800C8F8C:
    // 0x800C8F8C: bnel        $s3, $t9, L_800C8FBC
    if (ctx->r19 != ctx->r25) {
        // 0x800C8F90: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8FBC;
    }
    goto skip_30;
    // 0x800C8F90: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_30:
    // 0x800C8F94: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800C8F98: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800C8F9C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8FA0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C8FA4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8FA8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C8FAC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C8FB0: jal         0x800D3E70
    // 0x800C8FB4: nop

    alSynSetPitch(rdram, ctx);
        goto after_31;
    // 0x800C8FB4: nop

    after_31:
    // 0x800C8FB8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8FBC:
    // 0x800C8FBC: bnel        $s0, $zero, L_800C8F8C
    if (ctx->r16 != 0) {
        // 0x800C8FC0: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8F8C;
    }
    goto skip_31;
    // 0x800C8FC0: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_31:
L_800C8FC4:
    // 0x800C8FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8FC8:
    // 0x800C8FC8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x800C8FCC: jr          $ra
    // 0x800C8FD0: nop

    return;
    // 0x800C8FD0: nop

    // 0x800C8FD4: jr          $ra
    // 0x800C8FD8: nop

    return;
    // 0x800C8FD8: nop

;}
RECOMP_FUNC void static_1_800CA3E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA3E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA3E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA3EC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800CA3F0: jal         0x800CA320
    // 0x800CA3F4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800CA320(rdram, ctx);
        goto after_0;
    // 0x800CA3F4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800CA3F8: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800CA3FC: beq         $t6, $zero, L_800CA428
    if (ctx->r14 == 0) {
        // 0x800CA400: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800CA428;
    }
    // 0x800CA400: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800CA404: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_800CA408:
    // 0x800CA408: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800CA40C: jal         0x800CA320
    // 0x800CA410: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800CA320(rdram, ctx);
        goto after_1;
    // 0x800CA410: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800CA414: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x800CA418: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800CA41C: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800CA420: bne         $t9, $zero, L_800CA408
    if (ctx->r25 != 0) {
        // 0x800CA424: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_800CA408;
    }
    // 0x800CA424: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_800CA428:
    // 0x800CA428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA430: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CA434: jr          $ra
    // 0x800CA438: nop

    return;
    // 0x800CA438: nop

    // 0x800CA43C: jr          $ra
    // 0x800CA440: nop

    return;
    // 0x800CA440: nop

;}
