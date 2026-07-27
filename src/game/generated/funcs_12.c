#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void _timeToSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AF8: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x800C7AFC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800C7B00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C7B04: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800C7B08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7B0C: ldc1        $f4, -0xA0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XA0);
    // 0x800C7B10: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C7B14: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C7B18: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800C7B1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C7B20: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C7B24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C7B28: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C7B2C: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x800C7B30: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800C7B34: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800C7B38: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7B3C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C7B40: nop

    // 0x800C7B44: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x800C7B48: jr          $ra
    // 0x800C7B4C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800C7B4C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void func_80064FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064FEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064FF4: jal         0x8005F064
    // 0x80064FF8: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064FF8: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x80064FFC: b           L_8006500C
    // 0x80065000: nop

        goto L_8006500C;
    // 0x80065000: nop

    // 0x80065004: b           L_8006500C
    // 0x80065008: nop

        goto L_8006500C;
    // 0x80065008: nop

L_8006500C:
    // 0x8006500C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065014: jr          $ra
    // 0x80065018: nop

    return;
    // 0x80065018: nop

;}
RECOMP_FUNC void ContPak_DeleteFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE664: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AE66C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE670: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE674: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800AE678: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE67C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE680: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE684: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE688: lw          $t8, 0x1640($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1640);
    // 0x800AE68C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE690: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AE694: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800AE698: lw          $t0, 0x15D8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X15D8);
    // 0x800AE69C: nop

    // 0x800AE6A0: bne         $t0, $zero, L_800AE798
    if (ctx->r8 != 0) {
        // 0x800AE6A4: nop
    
            goto L_800AE798;
    }
    // 0x800AE6A4: nop

    // 0x800AE6A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE6AC: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE6B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE6B4: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x800AE6B8: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
    // 0x800AE6BC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE6C0: lw          $t3, 0x1640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1640);
    // 0x800AE6C4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE6C8: addiu       $t5, $t5, 0x13D0
    ctx->r13 = ADD32(ctx->r13, 0X13D0);
    // 0x800AE6CC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800AE6D0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AE6D4: lhu         $a1, 0x8($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X8);
    // 0x800AE6D8: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x800AE6DC: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x800AE6E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE6E4: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AE6E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800AE6EC: jal         0x800C6BE0
    // 0x800AE6F0: addiu       $a3, $t6, 0xE
    ctx->r7 = ADD32(ctx->r14, 0XE);
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE6F0: addiu       $a3, $t6, 0xE
    ctx->r7 = ADD32(ctx->r14, 0XE);
    after_0:
    // 0x800AE6F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE6F8: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AE6FC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE700: lw          $t8, 0x1684($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1684);
    // 0x800AE704: nop

    // 0x800AE708: bne         $t8, $zero, L_800AE790
    if (ctx->r24 != 0) {
        // 0x800AE70C: nop
    
            goto L_800AE790;
    }
    // 0x800AE70C: nop

    // 0x800AE710: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE714: lw          $t0, 0x1640($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1640);
    // 0x800AE718: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE71C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AE720: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800AE724: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800AE728: sw          $t9, 0x15D8($at)
    MEM_W(0X15D8, ctx->r1) = ctx->r25;
    // 0x800AE72C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE730: lw          $t3, 0x1640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1640);
    // 0x800AE734: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE738: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800AE73C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800AE740: lw          $t5, 0x13D0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X13D0);
    // 0x800AE744: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AE748: lw          $t2, 0x1638($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1638);
    // 0x800AE74C: addiu       $t6, $t5, 0xFF
    ctx->r14 = ADD32(ctx->r13, 0XFF);
    // 0x800AE750: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x800AE754: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE758: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800AE75C: sw          $t8, 0x1638($at)
    MEM_W(0X1638, ctx->r1) = ctx->r24;
    // 0x800AE760: jal         0x800AE40C
    // 0x800AE764: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_1;
    // 0x800AE764: nop

    after_1:
    // 0x800AE768: bgez        $v0, L_800AE790
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AE76C: nop
    
            goto L_800AE790;
    }
    // 0x800AE76C: nop

    // 0x800AE770: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE774: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AE778: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800AE77C: and         $t9, $t0, $at
    ctx->r25 = ctx->r8 & ctx->r1;
    // 0x800AE780: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE784: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AE788: b           L_800AE7EC
    // 0x800AE78C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE7EC;
    // 0x800AE78C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE790:
    // 0x800AE790: b           L_800AE7C4
    // 0x800AE794: nop

        goto L_800AE7C4;
    // 0x800AE794: nop

L_800AE798:
    // 0x800AE798: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE79C: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE7A0: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800AE7A4: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800AE7A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE7AC: sw          $t3, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r11;
    // 0x800AE7B0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800AE7B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE7B8: sw          $t4, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r12;
    // 0x800AE7BC: b           L_800AE7EC
    // 0x800AE7C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE7EC;
    // 0x800AE7C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE7C4:
    // 0x800AE7C4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE7C8: lw          $t5, 0x129C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X129C);
    // 0x800AE7CC: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800AE7D0: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800AE7D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE7D8: sw          $t6, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r14;
    // 0x800AE7DC: b           L_800AE7EC
    // 0x800AE7E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE7EC;
    // 0x800AE7E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE7E4: b           L_800AE7EC
    // 0x800AE7E8: nop

        goto L_800AE7EC;
    // 0x800AE7E8: nop

L_800AE7EC:
    // 0x800AE7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE7F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE7F4: jr          $ra
    // 0x800AE7F8: nop

    return;
    // 0x800AE7F8: nop

;}
RECOMP_FUNC void CreateSchedulerThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800984B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800984B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800984BC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800984C0: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x800984C4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800984C8: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x800984CC: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x800984D0: jal         0x80097068
    // 0x800984D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    Scheduler_CreateSchedulerThread(rdram, ctx);
        goto after_0;
    // 0x800984D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x800984D8: b           L_800984E0
    // 0x800984DC: nop

        goto L_800984E0;
    // 0x800984DC: nop

L_800984E0:
    // 0x800984E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800984E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800984E8: jr          $ra
    // 0x800984EC: nop

    return;
    // 0x800984EC: nop

;}
RECOMP_FUNC void func_800C3874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3874: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C3878: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C387C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800C3880: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3884: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C3888: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C388C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3890: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C3894: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C3898: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C389C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C38A0: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x800C38A4: jal         0x800C42A0
    // 0x800C38A8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C38A8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_0:
    // 0x800C38AC: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C38B0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C38B4: jal         0x800C38F4
    // 0x800C38B8: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    func_800C38F4(rdram, ctx);
        goto after_1;
    // 0x800C38B8: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    after_1:
    // 0x800C38BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C38C0: lwc1        $f5, -0x150($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X150);
    // 0x800C38C4: lwc1        $f4, -0x14C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14C);
    // 0x800C38C8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800C38CC: sub.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d - ctx->f6.d;
    // 0x800C38D0: b           L_800C38E0
    // 0x800C38D4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_800C38E0;
    // 0x800C38D4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800C38D8: b           L_800C38E0
    // 0x800C38DC: nop

        goto L_800C38E0;
    // 0x800C38DC: nop

L_800C38E0:
    // 0x800C38E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C38E4: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C38E8: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C38EC: jr          $ra
    // 0x800C38F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C38F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alMainBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0080: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D0084: bne         $a1, $at, L_800D00A8
    if (ctx->r5 != ctx->r1) {
        // 0x800D0088: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800D00A8;
    }
    // 0x800D0088: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800D008C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800D0090: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D0094: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800D0098: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800D009C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800D00A0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800D00A4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800D00A8:
    // 0x800D00A8: jr          $ra
    // 0x800D00AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D00AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80073020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073020: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073024: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073028: nop

    // 0x8007302C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073030: nop

    // 0x80073034: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80073038: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007303C: jr          $ra
    // 0x80073040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073044: jr          $ra
    // 0x80073048: nop

    return;
    // 0x80073048: nop

    // 0x8007304C: jr          $ra
    // 0x80073050: nop

    return;
    // 0x80073050: nop

;}
RECOMP_FUNC void func_8006BC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BC08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BC0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BC10: jal         0x80061488
    // 0x8006BC14: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006BC14: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    after_0:
    // 0x8006BC18: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006BC1C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006BC20: b           L_8006BC30
    // 0x8006BC24: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006BC30;
    // 0x8006BC24: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006BC28: b           L_8006BC30
    // 0x8006BC2C: nop

        goto L_8006BC30;
    // 0x8006BC2C: nop

L_8006BC30:
    // 0x8006BC30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BC34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BC38: jr          $ra
    // 0x8006BC3C: nop

    return;
    // 0x8006BC3C: nop

;}
RECOMP_FUNC void func_80063C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063C48: jal         0x8005F064
    // 0x80063C4C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063C4C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063C50: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063C54: b           L_80063C64
    // 0x80063C58: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063C64;
    // 0x80063C58: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063C5C: b           L_80063C64
    // 0x80063C60: nop

        goto L_80063C64;
    // 0x80063C60: nop

L_80063C64:
    // 0x80063C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063C6C: jr          $ra
    // 0x80063C70: nop

    return;
    // 0x80063C70: nop

;}
RECOMP_FUNC void func_800234D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800234D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800234DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800234E0: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800234E4: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800234E8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800234EC: lw          $t7, 0xD70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD70);
    // 0x800234F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800234F4: sh          $t6, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r14;
    // 0x800234F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800234FC: lw          $t8, 0xD70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD70);
    // 0x80023500: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80023504: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x80023508: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002350C: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80023510: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80023514: lw          $t1, 0x24F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X24F0);
    // 0x80023518: nop

    // 0x8002351C: lh          $t2, 0x102($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X102);
    // 0x80023520: nop

    // 0x80023524: sw          $t2, 0x1B50($at)
    MEM_W(0X1B50, ctx->r1) = ctx->r10;
    // 0x80023528: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002352C: lw          $t3, 0xD70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD70);
    // 0x80023530: nop

    // 0x80023534: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80023538: nop

    // 0x8002353C: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80023540: lhu         $t5, 0x2E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2E);
    // 0x80023544: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80023548: beq         $t5, $at, L_8002355C
    if (ctx->r13 == ctx->r1) {
        // 0x8002354C: nop
    
            goto L_8002355C;
    }
    // 0x8002354C: nop

    // 0x80023550: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80023554: bne         $t5, $at, L_800235A8
    if (ctx->r13 != ctx->r1) {
        // 0x80023558: nop
    
            goto L_800235A8;
    }
    // 0x80023558: nop

L_8002355C:
    // 0x8002355C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80023560: lw          $t6, 0x1B50($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B50);
    // 0x80023564: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80023568: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002356C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80023570: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80023574: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023578: nop

    // 0x8002357C: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80023580: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80023584: nop

    // 0x80023588: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002358C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80023590: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80023594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80023598: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x8002359C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800235A0: swc1        $f16, 0x1B50($at)
    MEM_W(0X1B50, ctx->r1) = ctx->f16.u32l;
    // 0x800235A4: nop

L_800235A8:
    // 0x800235A8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800235AC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800235B0: lw          $t9, 0xD70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD70);
    // 0x800235B4: lw          $t8, 0x1B50($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B50);
    // 0x800235B8: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800235BC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800235C0: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x800235C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800235C8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800235CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800235D0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800235D4: addiu       $t0, $t0, 0xD78
    ctx->r8 = ADD32(ctx->r8, 0XD78);
    // 0x800235D8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800235DC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800235E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800235E4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800235E8: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800235EC: jal         0x800C3D70
    // 0x800235F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C3D70(rdram, ctx);
        goto after_0;
    // 0x800235F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800235F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800235F8: lwc1        $f16, 0xD90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XD90);
    // 0x800235FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023600: lwc1        $f19, -0x1C68($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1C68);
    // 0x80023604: lwc1        $f18, -0x1C64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1C64);
    // 0x80023608: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002360C: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80023610: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023614: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80023618: swc1        $f8, 0xD98($at)
    MEM_W(0XD98, ctx->r1) = ctx->f8.u32l;
    // 0x8002361C: b           L_80023624
    // 0x80023620: nop

        goto L_80023624;
    // 0x80023620: nop

L_80023624:
    // 0x80023624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023628: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002362C: jr          $ra
    // 0x80023630: nop

    return;
    // 0x80023630: nop

;}
RECOMP_FUNC void func_80069D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80069D40: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80069D44: nop

    // 0x80069D48: lh          $v0, 0x38($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X38);
    // 0x80069D4C: nop

    // 0x80069D50: xori        $t7, $v0, 0x3E7
    ctx->r15 = ctx->r2 ^ 0X3E7;
    // 0x80069D54: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069D58: jr          $ra
    // 0x80069D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80069D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069D60: jr          $ra
    // 0x80069D64: nop

    return;
    // 0x80069D64: nop

    // 0x80069D68: jr          $ra
    // 0x80069D6C: nop

    return;
    // 0x80069D6C: nop

;}
RECOMP_FUNC void _collectPVoices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7B8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C7B90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C7B94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C7B98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C7B9C: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x800C7BA0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C7BA4: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
    // 0x800C7BA8: beql        $s0, $zero, L_800C7BD4
    if (ctx->r16 == 0) {
        // 0x800C7BAC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C7BD4;
    }
    goto skip_0;
    // 0x800C7BAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800C7BB0:
    // 0x800C7BB0: jal         0x800C7890
    // 0x800C7BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C7BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C7BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C7BBC: jal         0x800C78C0
    // 0x800C7BC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C7BC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800C7BC4: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x800C7BC8: bne         $s0, $zero, L_800C7BB0
    if (ctx->r16 != 0) {
        // 0x800C7BCC: nop
    
            goto L_800C7BB0;
    }
    // 0x800C7BCC: nop

    // 0x800C7BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C7BD4:
    // 0x800C7BD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C7BD8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7BDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C7BE0: jr          $ra
    // 0x800C7BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C7BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
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
RECOMP_FUNC void func_8008A46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A46C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008A470: bgez        $a1, L_8008A4CC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008A474: nop
    
            goto L_8008A4CC;
    }
    // 0x8008A474: nop

    // 0x8008A478: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008A47C:
    // 0x8008A47C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008A480: nop

    // 0x8008A484: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008A488: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008A48C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008A490: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008A494: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8008A498: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008A49C: lw          $t9, 0x268($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X268);
    // 0x8008A4A0: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x8008A4A4: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8008A4A8: sw          $t0, 0x268($t1)
    MEM_W(0X268, ctx->r9) = ctx->r8;
    // 0x8008A4AC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008A4B0: nop

    // 0x8008A4B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008A4B8: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8008A4BC: bne         $at, $zero, L_8008A47C
    if (ctx->r1 != 0) {
        // 0x8008A4C0: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8008A47C;
    }
    // 0x8008A4C0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8008A4C4: b           L_8008A510
    // 0x8008A4C8: nop

        goto L_8008A510;
    // 0x8008A4C8: nop

L_8008A4CC:
    // 0x8008A4CC: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8008A4D0: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8008A4D4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A4D8: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8008A4DC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8008A4E0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8008A4E4: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8008A4E8: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8008A4EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A4F0: lw          $t6, 0x268($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X268);
    // 0x8008A4F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8008A4F8: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8008A4FC: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x8008A500: ori         $t8, $t6, 0x80
    ctx->r24 = ctx->r14 | 0X80;
    // 0x8008A504: sw          $t8, 0x268($t7)
    MEM_W(0X268, ctx->r15) = ctx->r24;
    // 0x8008A508: b           L_8008A510
    // 0x8008A50C: nop

        goto L_8008A510;
    // 0x8008A50C: nop

L_8008A510:
    // 0x8008A510: jr          $ra
    // 0x8008A514: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008A514: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_80076E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076E80: jal         0x80061488
    // 0x80076E84: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076E84: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076E88: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076E8C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076E90: b           L_80076EA0
    // 0x80076E94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076EA0;
    // 0x80076E94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076E98: b           L_80076EA0
    // 0x80076E9C: nop

        goto L_80076EA0;
    // 0x80076E9C: nop

L_80076EA0:
    // 0x80076EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076EA8: jr          $ra
    // 0x80076EAC: nop

    return;
    // 0x80076EAC: nop

;}
RECOMP_FUNC void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCC80: beq         $a2, $zero, L_800CCCEC
    if (ctx->r6 == 0) {
        // 0x800CCC84: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800CCCEC;
    }
    // 0x800CCC84: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CCC88: beq         $a0, $a1, L_800CCCEC
    if (ctx->r4 == ctx->r5) {
        // 0x800CCC8C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800CCCEC;
    }
    // 0x800CCC8C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CCC90: bnel        $at, $zero, L_800CCCB4
    if (ctx->r1 != 0) {
        // 0x800CCC94: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CCCB4;
    }
    goto skip_0;
    // 0x800CCC94: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x800CCC98: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x800CCC9C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CCCA0: beql        $at, $zero, L_800CCCB4
    if (ctx->r1 == 0) {
        // 0x800CCCA4: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CCCB4;
    }
    goto skip_1;
    // 0x800CCCA4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x800CCCA8: b           L_800CCE18
    // 0x800CCCAC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800CCE18;
    // 0x800CCCAC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800CCCB0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CCCB4:
    // 0x800CCCB4: bne         $at, $zero, L_800CCCCC
    if (ctx->r1 != 0) {
        // 0x800CCCB8: nop
    
            goto L_800CCCCC;
    }
    // 0x800CCCB8: nop

    // 0x800CCCBC: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800CCCC0: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800CCCC4: beq         $v0, $v1, L_800CCCF4
    if (ctx->r2 == ctx->r3) {
        // 0x800CCCC8: nop
    
            goto L_800CCCF4;
    }
    // 0x800CCCC8: nop

L_800CCCCC:
    // 0x800CCCCC: beq         $a2, $zero, L_800CCCEC
    if (ctx->r6 == 0) {
        // 0x800CCCD0: nop
    
            goto L_800CCCEC;
    }
    // 0x800CCCD0: nop

    // 0x800CCCD4: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_800CCCD8:
    // 0x800CCCD8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CCCDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CCCE0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CCCE4: bne         $a0, $v1, L_800CCCD8
    if (ctx->r4 != ctx->r3) {
        // 0x800CCCE8: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_800CCCD8;
    }
    // 0x800CCCE8: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_800CCCEC:
    // 0x800CCCEC: jr          $ra
    // 0x800CCCF0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CCCF0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800CCCF4:
    // 0x800CCCF4: beq         $v0, $zero, L_800CCD58
    if (ctx->r2 == 0) {
        // 0x800CCCF8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CCD58;
    }
    // 0x800CCCF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CCCFC: beq         $v0, $at, L_800CCD3C
    if (ctx->r2 == ctx->r1) {
        // 0x800CCD00: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CCD3C;
    }
    // 0x800CCD00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CCD04: beql        $v0, $at, L_800CCD28
    if (ctx->r2 == ctx->r1) {
        // 0x800CCD08: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800CCD28;
    }
    goto skip_2;
    // 0x800CCD08: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x800CCD0C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CCD10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CCD14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CCD18: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CCD1C: b           L_800CCD58
    // 0x800CCD20: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800CCD58;
    // 0x800CCD20: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800CCD24: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800CCD28:
    // 0x800CCD28: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800CCD2C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800CCD30: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800CCD34: b           L_800CCD58
    // 0x800CCD38: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800CCD58;
    // 0x800CCD38: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800CCD3C:
    // 0x800CCD3C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CCD40: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800CCD44: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800CCD48: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800CCD4C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800CCD50: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800CCD54: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800CCD58:
    // 0x800CCD58: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800CCD5C: bnel        $at, $zero, L_800CCDB8
    if (ctx->r1 != 0) {
        // 0x800CCD60: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CCDB8;
    }
    goto skip_3;
    // 0x800CCD60: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800CCD64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CCD68: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800CCD6C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800CCD70: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800CCD74: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800CCD78: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CCD7C: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x800CCD80: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800CCD84: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800CCD88: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800CCD8C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CCD90: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x800CCD94: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x800CCD98: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x800CCD9C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x800CCDA0: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x800CCDA4: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x800CCDA8: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x800CCDAC: b           L_800CCD58
    // 0x800CCDB0: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800CCD58;
    // 0x800CCDB0: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_800CCDB4:
    // 0x800CCDB4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CCDB8:
    // 0x800CCDB8: bnel        $at, $zero, L_800CCDF4
    if (ctx->r1 != 0) {
        // 0x800CCDBC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CCDF4;
    }
    goto skip_4;
    // 0x800CCDBC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x800CCDC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CCDC4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800CCDC8: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800CCDCC: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800CCDD0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800CCDD4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800CCDD8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CCDDC: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x800CCDE0: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x800CCDE4: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x800CCDE8: b           L_800CCDB4
    // 0x800CCDEC: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_800CCDB4;
    // 0x800CCDEC: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_800CCDF0:
    // 0x800CCDF0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CCDF4:
    // 0x800CCDF4: bne         $at, $zero, L_800CCCCC
    if (ctx->r1 != 0) {
        // 0x800CCDF8: nop
    
            goto L_800CCCCC;
    }
    // 0x800CCDF8: nop

    // 0x800CCDFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CCE00: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CCE04: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CCE08: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CCE0C: b           L_800CCDF0
    // 0x800CCE10: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_800CCDF0;
    // 0x800CCE10: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800CCE14: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CCE18:
    // 0x800CCE18: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800CCE1C: bne         $at, $zero, L_800CCE34
    if (ctx->r1 != 0) {
        // 0x800CCE20: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800CCE34;
    }
    // 0x800CCE20: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800CCE24: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800CCE28: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800CCE2C: beq         $v0, $v1, L_800CCE64
    if (ctx->r2 == ctx->r3) {
        // 0x800CCE30: nop
    
            goto L_800CCE64;
    }
    // 0x800CCE30: nop

L_800CCE34:
    // 0x800CCE34: beq         $a2, $zero, L_800CCCEC
    if (ctx->r6 == 0) {
        // 0x800CCE38: nop
    
            goto L_800CCCEC;
    }
    // 0x800CCE38: nop

    // 0x800CCE3C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CCE40: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CCE44: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800CCE48:
    // 0x800CCE48: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CCE4C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CCE50: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CCE54: bne         $a0, $v1, L_800CCE48
    if (ctx->r4 != ctx->r3) {
        // 0x800CCE58: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800CCE48;
    }
    // 0x800CCE58: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800CCE5C: jr          $ra
    // 0x800CCE60: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CCE60: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800CCE64:
    // 0x800CCE64: beq         $v0, $zero, L_800CCEC8
    if (ctx->r2 == 0) {
        // 0x800CCE68: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CCEC8;
    }
    // 0x800CCE68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CCE6C: beq         $v0, $at, L_800CCEAC
    if (ctx->r2 == ctx->r1) {
        // 0x800CCE70: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CCEAC;
    }
    // 0x800CCE70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CCE74: beql        $v0, $at, L_800CCE98
    if (ctx->r2 == ctx->r1) {
        // 0x800CCE78: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_800CCE98;
    }
    goto skip_5;
    // 0x800CCE78: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x800CCE7C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800CCE80: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CCE84: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CCE88: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CCE8C: b           L_800CCEC8
    // 0x800CCE90: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800CCEC8;
    // 0x800CCE90: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800CCE94: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_800CCE98:
    // 0x800CCE98: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800CCE9C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800CCEA0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800CCEA4: b           L_800CCEC8
    // 0x800CCEA8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_800CCEC8;
    // 0x800CCEA8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800CCEAC:
    // 0x800CCEAC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800CCEB0: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x800CCEB4: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x800CCEB8: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x800CCEBC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800CCEC0: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x800CCEC4: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_800CCEC8:
    // 0x800CCEC8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800CCECC: bnel        $at, $zero, L_800CCF28
    if (ctx->r1 != 0) {
        // 0x800CCED0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CCF28;
    }
    goto skip_6;
    // 0x800CCED0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x800CCED4: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CCED8: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CCEDC: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CCEE0: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CCEE4: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x800CCEE8: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x800CCEEC: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x800CCEF0: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x800CCEF4: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x800CCEF8: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x800CCEFC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CCF00: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800CCF04: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x800CCF08: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800CCF0C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800CCF10: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800CCF14: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800CCF18: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800CCF1C: b           L_800CCEC8
    // 0x800CCF20: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_800CCEC8;
    // 0x800CCF20: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800CCF24:
    // 0x800CCF24: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CCF28:
    // 0x800CCF28: bnel        $at, $zero, L_800CCF64
    if (ctx->r1 != 0) {
        // 0x800CCF2C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CCF64;
    }
    goto skip_7;
    // 0x800CCF2C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800CCF30: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CCF34: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CCF38: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CCF3C: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CCF40: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800CCF44: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800CCF48: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CCF4C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800CCF50: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x800CCF54: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800CCF58: b           L_800CCF24
    // 0x800CCF5C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800CCF24;
    // 0x800CCF5C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_800CCF60:
    // 0x800CCF60: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CCF64:
    // 0x800CCF64: bne         $at, $zero, L_800CCE34
    if (ctx->r1 != 0) {
        // 0x800CCF68: nop
    
            goto L_800CCE34;
    }
    // 0x800CCF68: nop

    // 0x800CCF6C: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CCF70: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800CCF74: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800CCF78: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CCF7C: b           L_800CCF60
    // 0x800CCF80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800CCF60;
    // 0x800CCF80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_80071350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071358: jal         0x80061348
    // 0x8007135C: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007135C: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071360: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071364: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071368: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007136C: beq         $v0, $zero, L_800713C0
    if (ctx->r2 == 0) {
        // 0x80071370: nop
    
            goto L_800713C0;
    }
    // 0x80071370: nop

    // 0x80071374: jal         0x80061348
    // 0x80071378: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071378: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x8007137C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071380: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071384: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071388: beq         $v0, $zero, L_800713C0
    if (ctx->r2 == 0) {
        // 0x8007138C: nop
    
            goto L_800713C0;
    }
    // 0x8007138C: nop

    // 0x80071390: jal         0x80061348
    // 0x80071394: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071394: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x80071398: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007139C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800713A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800713A4: beq         $v0, $zero, L_800713C0
    if (ctx->r2 == 0) {
        // 0x800713A8: nop
    
            goto L_800713C0;
    }
    // 0x800713A8: nop

    // 0x800713AC: jal         0x80061348
    // 0x800713B0: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800713B0: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x800713B4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800713B8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800713BC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800713C0:
    // 0x800713C0: b           L_800713D0
    // 0x800713C4: nop

        goto L_800713D0;
    // 0x800713C4: nop

    // 0x800713C8: b           L_800713D0
    // 0x800713CC: nop

        goto L_800713D0;
    // 0x800713CC: nop

L_800713D0:
    // 0x800713D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800713D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800713D8: jr          $ra
    // 0x800713DC: nop

    return;
    // 0x800713DC: nop

;}
RECOMP_FUNC void func_80009FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009FA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009FA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009FAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80009FB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009FB4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80009FB8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80009FBC: lw          $t6, -0x73CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73CC);
    // 0x80009FC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009FC4: beq         $t6, $at, L_80009FE0
    if (ctx->r14 == ctx->r1) {
        // 0x80009FC8: nop
    
            goto L_80009FE0;
    }
    // 0x80009FC8: nop

    // 0x80009FCC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80009FD0: lw          $a0, -0x73CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73CC);
    // 0x80009FD4: jal         0x80016074
    // 0x80009FD8: nop

    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80009FD8: nop

    after_0:
    // 0x80009FDC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80009FE0:
    // 0x80009FE0: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80009FE4: lh          $s0, -0x73A8($s0)
    ctx->r16 = MEM_H(ctx->r16, -0X73A8);
    // 0x80009FE8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80009FEC: beq         $s0, $at, L_8000A020
    if (ctx->r16 == ctx->r1) {
        // 0x80009FF0: nop
    
            goto L_8000A020;
    }
    // 0x80009FF0: nop

    // 0x80009FF4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80009FF8: beq         $s0, $at, L_8000A020
    if (ctx->r16 == ctx->r1) {
        // 0x80009FFC: nop
    
            goto L_8000A020;
    }
    // 0x80009FFC: nop

    // 0x8000A000: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x8000A004: beq         $s0, $at, L_8000A028
    if (ctx->r16 == ctx->r1) {
        // 0x8000A008: nop
    
            goto L_8000A028;
    }
    // 0x8000A008: nop

    // 0x8000A00C: addiu       $at, $zero, 0x1F6
    ctx->r1 = ADD32(0, 0X1F6);
    // 0x8000A010: beq         $s0, $at, L_8000A020
    if (ctx->r16 == ctx->r1) {
        // 0x8000A014: nop
    
            goto L_8000A020;
    }
    // 0x8000A014: nop

    // 0x8000A018: b           L_8000A25C
    // 0x8000A01C: nop

        goto L_8000A25C;
    // 0x8000A01C: nop

L_8000A020:
    // 0x8000A020: b           L_8000A25C
    // 0x8000A024: nop

        goto L_8000A25C;
    // 0x8000A024: nop

L_8000A028:
    // 0x8000A028: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000A02C: nop

    // 0x8000A030: beq         $t7, $zero, L_8000A04C
    if (ctx->r15 == 0) {
        // 0x8000A034: nop
    
            goto L_8000A04C;
    }
    // 0x8000A034: nop

    // 0x8000A038: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8000A03C: nop

    // 0x8000A040: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000A044: bne         $t9, $zero, L_8000A25C
    if (ctx->r25 != 0) {
        // 0x8000A048: nop
    
            goto L_8000A25C;
    }
    // 0x8000A048: nop

L_8000A04C:
    // 0x8000A04C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000A050: nop

    // 0x8000A054: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000A058: nop

    // 0x8000A05C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8000A060: bne         $t2, $zero, L_8000A254
    if (ctx->r10 != 0) {
        // 0x8000A064: nop
    
            goto L_8000A254;
    }
    // 0x8000A064: nop

    // 0x8000A068: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000A06C: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8000A070: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8000A074: lhu         $t5, 0x11A4($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X11A4);
    // 0x8000A078: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8000A07C: nop

    // 0x8000A080: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8000A084: beq         $t6, $zero, L_8000A254
    if (ctx->r14 == 0) {
        // 0x8000A088: nop
    
            goto L_8000A254;
    }
    // 0x8000A088: nop

    // 0x8000A08C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000A090: jal         0x800198F8
    // 0x8000A094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800198F8(rdram, ctx);
        goto after_1;
    // 0x8000A094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8000A098: jal         0x800045AC
    // 0x8000A09C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_2;
    // 0x8000A09C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8000A0A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000A0A4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000A0A8: nop

    // 0x8000A0AC: beq         $t7, $zero, L_8000A0E0
    if (ctx->r15 == 0) {
        // 0x8000A0B0: nop
    
            goto L_8000A0E0;
    }
    // 0x8000A0B0: nop

    // 0x8000A0B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000A0B8: nop

    // 0x8000A0BC: lw          $t9, 0x1A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A8);
    // 0x8000A0C0: nop

    // 0x8000A0C4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8000A0C8: sw          $t0, 0x1A8($t8)
    MEM_W(0X1A8, ctx->r24) = ctx->r8;
    // 0x8000A0CC: jal         0x8000BB00
    // 0x8000A0D0: nop

    func_8000BB00(rdram, ctx);
        goto after_3;
    // 0x8000A0D0: nop

    after_3:
    // 0x8000A0D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8000A0D8: jal         0x8000C3B0
    // 0x8000A0DC: nop

    func_8000C3B0(rdram, ctx);
        goto after_4;
    // 0x8000A0DC: nop

    after_4:
L_8000A0E0:
    // 0x8000A0E0: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x8000A0E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A0E8: sh          $t1, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r9;
    // 0x8000A0EC: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x8000A0F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A0F4: sh          $t2, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r10;
    // 0x8000A0F8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000A0FC: nop

    // 0x8000A100: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x8000A104: nop

    // 0x8000A108: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8000A10C: sw          $t5, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = ctx->r13;
    // 0x8000A110: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8000A114: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A118: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
    // 0x8000A11C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000A120: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000A124: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x8000A128: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8000A12C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A130: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A134: swc1        $f4, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f4.u32l;
    // 0x8000A138: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x8000A13C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A140: sw          $t9, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r25;
    // 0x8000A144: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x8000A148: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A14C: sw          $t0, -0x44F4($at)
    MEM_W(-0X44F4, ctx->r1) = ctx->r8;
    // 0x8000A150: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000A154: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A158: swc1        $f6, -0x44F0($at)
    MEM_W(-0X44F0, ctx->r1) = ctx->f6.u32l;
    // 0x8000A15C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8000A160: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000A164: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A168: swc1        $f8, -0x44EC($at)
    MEM_W(-0X44EC, ctx->r1) = ctx->f8.u32l;
    // 0x8000A16C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000A170: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A174: swc1        $f10, -0x44E8($at)
    MEM_W(-0X44E8, ctx->r1) = ctx->f10.u32l;
    // 0x8000A178: jal         0x80022124
    // 0x8000A17C: nop

    func_80022124(rdram, ctx);
        goto after_5;
    // 0x8000A17C: nop

    after_5:
    // 0x8000A180: jal         0x80021F20
    // 0x8000A184: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_6;
    // 0x8000A184: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_6:
    // 0x8000A188: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000A18C: lui         $t8, 0x7FFF
    ctx->r24 = S32(0X7FFF << 16);
    // 0x8000A190: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8000A194: sw          $t8, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r24;
    // 0x8000A198: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000A19C: nop

    // 0x8000A1A0: lw          $t4, 0xC0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC0);
    // 0x8000A1A4: nop

    // 0x8000A1A8: ori         $t5, $t4, 0x48
    ctx->r13 = ctx->r12 | 0X48;
    // 0x8000A1AC: sw          $t5, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r13;
    // 0x8000A1B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000A1B4: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8000A1B8: sh          $t3, 0xC4($t6)
    MEM_H(0XC4, ctx->r14) = ctx->r11;
    // 0x8000A1BC: jal         0x80016074
    // 0x8000A1C0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_7;
    // 0x8000A1C0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_7:
    // 0x8000A1C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000A1C8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000A1CC: nop

    // 0x8000A1D0: beq         $t7, $zero, L_8000A1E4
    if (ctx->r15 == 0) {
        // 0x8000A1D4: nop
    
            goto L_8000A1E4;
    }
    // 0x8000A1D4: nop

    // 0x8000A1D8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000A1DC: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8000A1E0: sh          $t9, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r25;
L_8000A1E4:
    // 0x8000A1E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000A1E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000A1EC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000A1F0: addiu       $t8, $t8, 0x61D8
    ctx->r24 = ADD32(ctx->r24, 0X61D8);
    // 0x8000A1F4: swc1        $f16, 0x5F4($t8)
    MEM_W(0X5F4, ctx->r24) = ctx->f16.u32l;
    // 0x8000A1F8: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8000A1FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000A200: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000A204: addiu       $t1, $t1, 0x61D8
    ctx->r9 = ADD32(ctx->r9, 0X61D8);
    // 0x8000A208: swc1        $f18, 0x5FC($t1)
    MEM_W(0X5FC, ctx->r9) = ctx->f18.u32l;
    // 0x8000A20C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000A210: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000A214: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x8000A218: swc1        $f4, 0x72C($t4)
    MEM_W(0X72C, ctx->r12) = ctx->f4.u32l;
    // 0x8000A21C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000A220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000A224: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000A228: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x8000A22C: swc1        $f6, 0x734($t5)
    MEM_W(0X734, ctx->r13) = ctx->f6.u32l;
    // 0x8000A230: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000A234: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000A238: addiu       $t2, $t2, 0x61D8
    ctx->r10 = ADD32(ctx->r10, 0X61D8);
    // 0x8000A23C: swc1        $f8, 0x4BC($t2)
    MEM_W(0X4BC, ctx->r10) = ctx->f8.u32l;
    // 0x8000A240: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000A244: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A248: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000A24C: addiu       $t3, $t3, 0x61D8
    ctx->r11 = ADD32(ctx->r11, 0X61D8);
    // 0x8000A250: swc1        $f10, 0x4C4($t3)
    MEM_W(0X4C4, ctx->r11) = ctx->f10.u32l;
L_8000A254:
    // 0x8000A254: b           L_8000A25C
    // 0x8000A258: nop

        goto L_8000A25C;
    // 0x8000A258: nop

L_8000A25C:
    // 0x8000A25C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000A260: nop

    // 0x8000A264: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x8000A268: nop

    // 0x8000A26C: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x8000A270: beq         $t9, $zero, L_8000A2A0
    if (ctx->r25 == 0) {
        // 0x8000A274: nop
    
            goto L_8000A2A0;
    }
    // 0x8000A274: nop

    // 0x8000A278: jal         0x800C1754
    // 0x8000A27C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_8;
    // 0x8000A27C: nop

    after_8:
    // 0x8000A280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000A284: jal         0x8009A14C
    // 0x8000A288: nop

    func_8009A14C(rdram, ctx);
        goto after_9;
    // 0x8000A288: nop

    after_9:
    // 0x8000A28C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000A290: jal         0x800997D8
    // 0x8000A294: nop

    func_800997D8(rdram, ctx);
        goto after_10;
    // 0x8000A294: nop

    after_10:
    // 0x8000A298: jal         0x800C1A28
    // 0x8000A29C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_11;
    // 0x8000A29C: nop

    after_11:
L_8000A2A0:
    // 0x8000A2A0: b           L_8000A2B0
    // 0x8000A2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000A2B0;
    // 0x8000A2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000A2A8: b           L_8000A2B0
    // 0x8000A2AC: nop

        goto L_8000A2B0;
    // 0x8000A2AC: nop

L_8000A2B0:
    // 0x8000A2B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A2B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000A2B8: jr          $ra
    // 0x8000A2BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000A2BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80060440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060440: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80060444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060448: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8006044C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80060450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060454: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80060458: nop

    // 0x8006045C: beq         $t6, $zero, L_8006046C
    if (ctx->r14 == 0) {
        // 0x80060460: nop
    
            goto L_8006046C;
    }
    // 0x80060460: nop

    // 0x80060464: b           L_80060478
    // 0x80060468: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
        goto L_80060478;
    // 0x80060468: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8006046C:
    // 0x8006046C: jal         0x80061E14
    // 0x80060470: nop

    func_80061E14(rdram, ctx);
        goto after_0;
    // 0x80060470: nop

    after_0:
    // 0x80060474: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80060478:
    // 0x80060478: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8006047C: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80060480: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80060484: bne         $t7, $at, L_800604BC
    if (ctx->r15 != ctx->r1) {
        // 0x80060488: nop
    
            goto L_800604BC;
    }
    // 0x80060488: nop

    // 0x8006048C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80060490: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x80060494: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80060498: bne         $t8, $at, L_800604BC
    if (ctx->r24 != ctx->r1) {
        // 0x8006049C: nop
    
            goto L_800604BC;
    }
    // 0x8006049C: nop

    // 0x800604A0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800604A4: lw          $t9, 0x1358($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1358);
    // 0x800604A8: nop

    // 0x800604AC: addiu       $t0, $t9, 0xFA0
    ctx->r8 = ADD32(ctx->r25, 0XFA0);
    // 0x800604B0: sh          $t0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r8;
    // 0x800604B4: b           L_800607DC
    // 0x800604B8: nop

        goto L_800607DC;
    // 0x800604B8: nop

L_800604BC:
    // 0x800604BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800604C0: jal         0x8005A144
    // 0x800604C4: nop

    func_8005A144(rdram, ctx);
        goto after_1;
    // 0x800604C4: nop

    after_1:
    // 0x800604C8: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x800604CC: lh          $t1, 0x36($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X36);
    // 0x800604D0: nop

    // 0x800604D4: blez        $t1, L_800604E4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800604D8: nop
    
            goto L_800604E4;
    }
    // 0x800604D8: nop

    // 0x800604DC: b           L_800607DC
    // 0x800604E0: nop

        goto L_800607DC;
    // 0x800604E0: nop

L_800604E4:
    // 0x800604E4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800604E8: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800604EC: beq         $s0, $at, L_80060520
    if (ctx->r16 == ctx->r1) {
        // 0x800604F0: nop
    
            goto L_80060520;
    }
    // 0x800604F0: nop

    // 0x800604F4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800604F8: beq         $s0, $at, L_80060574
    if (ctx->r16 == ctx->r1) {
        // 0x800604FC: nop
    
            goto L_80060574;
    }
    // 0x800604FC: nop

    // 0x80060500: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80060504: beq         $s0, $at, L_800605C8
    if (ctx->r16 == ctx->r1) {
        // 0x80060508: nop
    
            goto L_800605C8;
    }
    // 0x80060508: nop

    // 0x8006050C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80060510: beq         $s0, $at, L_8006061C
    if (ctx->r16 == ctx->r1) {
        // 0x80060514: nop
    
            goto L_8006061C;
    }
    // 0x80060514: nop

    // 0x80060518: b           L_80060670
    // 0x8006051C: nop

        goto L_80060670;
    // 0x8006051C: nop

L_80060520:
    // 0x80060520: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80060524: nop

    // 0x80060528: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x8006052C: nop

    // 0x80060530: bne         $t3, $zero, L_80060540
    if (ctx->r11 != 0) {
        // 0x80060534: nop
    
            goto L_80060540;
    }
    // 0x80060534: nop

    // 0x80060538: b           L_80060670
    // 0x8006053C: nop

        goto L_80060670;
    // 0x8006053C: nop

L_80060540:
    // 0x80060540: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80060544: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060548: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006054C: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x80060550: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x80060554: lh          $a0, 0x8($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X8);
    // 0x80060558: jal         0x80061990
    // 0x8006055C: nop

    func_80061990(rdram, ctx);
        goto after_2;
    // 0x8006055C: nop

    after_2:
    // 0x80060560: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80060564: nop

    // 0x80060568: lh          $v0, 0x8($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X8);
    // 0x8006056C: b           L_8006080C
    // 0x80060570: nop

        goto L_8006080C;
    // 0x80060570: nop

L_80060574:
    // 0x80060574: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80060578: nop

    // 0x8006057C: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x80060580: nop

    // 0x80060584: bne         $t7, $zero, L_80060594
    if (ctx->r15 != 0) {
        // 0x80060588: nop
    
            goto L_80060594;
    }
    // 0x80060588: nop

    // 0x8006058C: b           L_80060670
    // 0x80060590: nop

        goto L_80060670;
    // 0x80060590: nop

L_80060594:
    // 0x80060594: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80060598: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8006059C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800605A0: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x800605A4: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x800605A8: lh          $a0, 0xA($t8)
    ctx->r4 = MEM_H(ctx->r24, 0XA);
    // 0x800605AC: jal         0x80061990
    // 0x800605B0: nop

    func_80061990(rdram, ctx);
        goto after_3;
    // 0x800605B0: nop

    after_3:
    // 0x800605B4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800605B8: nop

    // 0x800605BC: lh          $v0, 0xA($t9)
    ctx->r2 = MEM_H(ctx->r25, 0XA);
    // 0x800605C0: b           L_8006080C
    // 0x800605C4: nop

        goto L_8006080C;
    // 0x800605C4: nop

L_800605C8:
    // 0x800605C8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800605CC: nop

    // 0x800605D0: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x800605D4: nop

    // 0x800605D8: bne         $t1, $zero, L_800605E8
    if (ctx->r9 != 0) {
        // 0x800605DC: nop
    
            goto L_800605E8;
    }
    // 0x800605DC: nop

    // 0x800605E0: b           L_80060670
    // 0x800605E4: nop

        goto L_80060670;
    // 0x800605E4: nop

L_800605E8:
    // 0x800605E8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800605EC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800605F0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800605F4: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x800605F8: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x800605FC: lh          $a0, 0xC($t2)
    ctx->r4 = MEM_H(ctx->r10, 0XC);
    // 0x80060600: jal         0x80061990
    // 0x80060604: nop

    func_80061990(rdram, ctx);
        goto after_4;
    // 0x80060604: nop

    after_4:
    // 0x80060608: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8006060C: nop

    // 0x80060610: lh          $v0, 0xC($t3)
    ctx->r2 = MEM_H(ctx->r11, 0XC);
    // 0x80060614: b           L_8006080C
    // 0x80060618: nop

        goto L_8006080C;
    // 0x80060618: nop

L_8006061C:
    // 0x8006061C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80060620: nop

    // 0x80060624: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x80060628: nop

    // 0x8006062C: bne         $t5, $zero, L_8006063C
    if (ctx->r13 != 0) {
        // 0x80060630: nop
    
            goto L_8006063C;
    }
    // 0x80060630: nop

    // 0x80060634: b           L_80060670
    // 0x80060638: nop

        goto L_80060670;
    // 0x80060638: nop

L_8006063C:
    // 0x8006063C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80060640: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060644: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80060648: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x8006064C: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x80060650: lh          $a0, 0xE($t6)
    ctx->r4 = MEM_H(ctx->r14, 0XE);
    // 0x80060654: jal         0x80061990
    // 0x80060658: nop

    func_80061990(rdram, ctx);
        goto after_5;
    // 0x80060658: nop

    after_5:
    // 0x8006065C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80060660: nop

    // 0x80060664: lh          $v0, 0xE($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XE);
    // 0x80060668: b           L_8006080C
    // 0x8006066C: nop

        goto L_8006080C;
    // 0x8006066C: nop

L_80060670:
    // 0x80060670: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80060674: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80060678: nop

    // 0x8006067C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80060680: nop

    // 0x80060684: beq         $t9, $zero, L_800606B4
    if (ctx->r25 == 0) {
        // 0x80060688: nop
    
            goto L_800606B4;
    }
    // 0x80060688: nop

    // 0x8006068C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80060690: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80060694: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80060698: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8006069C: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x800606A0: sh          $t1, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r9;
    // 0x800606A4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800606A8: nop

    // 0x800606AC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800606B0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800606B4:
    // 0x800606B4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800606B8: nop

    // 0x800606BC: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800606C0: nop

    // 0x800606C4: beq         $t8, $zero, L_800606F4
    if (ctx->r24 == 0) {
        // 0x800606C8: nop
    
            goto L_800606F4;
    }
    // 0x800606C8: nop

    // 0x800606CC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800606D0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800606D4: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x800606D8: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x800606DC: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x800606E0: sh          $t0, 0x38($t3)
    MEM_H(0X38, ctx->r11) = ctx->r8;
    // 0x800606E4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800606E8: nop

    // 0x800606EC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800606F0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_800606F4:
    // 0x800606F4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800606F8: nop

    // 0x800606FC: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80060700: nop

    // 0x80060704: beq         $t7, $zero, L_80060734
    if (ctx->r15 == 0) {
        // 0x80060708: nop
    
            goto L_80060734;
    }
    // 0x80060708: nop

    // 0x8006070C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80060710: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80060714: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80060718: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x8006071C: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x80060720: sh          $t9, 0x38($t1)
    MEM_H(0X38, ctx->r9) = ctx->r25;
    // 0x80060724: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80060728: nop

    // 0x8006072C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80060730: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_80060734:
    // 0x80060734: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80060738: nop

    // 0x8006073C: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x80060740: nop

    // 0x80060744: beq         $t6, $zero, L_80060774
    if (ctx->r14 == 0) {
        // 0x80060748: nop
    
            goto L_80060774;
    }
    // 0x80060748: nop

    // 0x8006074C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80060750: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80060754: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80060758: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x8006075C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x80060760: sh          $t8, 0x38($t0)
    MEM_H(0X38, ctx->r8) = ctx->r24;
    // 0x80060764: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80060768: nop

    // 0x8006076C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80060770: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_80060774:
    // 0x80060774: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80060778: nop

    // 0x8006077C: bne         $t4, $zero, L_800607A4
    if (ctx->r12 != 0) {
        // 0x80060780: nop
    
            goto L_800607A4;
    }
    // 0x80060780: nop

    // 0x80060784: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060788: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006078C: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x80060790: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x80060794: jal         0x80061990
    // 0x80060798: addiu       $a0, $zero, 0x1386
    ctx->r4 = ADD32(0, 0X1386);
    func_80061990(rdram, ctx);
        goto after_6;
    // 0x80060798: addiu       $a0, $zero, 0x1386
    ctx->r4 = ADD32(0, 0X1386);
    after_6:
    // 0x8006079C: b           L_8006080C
    // 0x800607A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006080C;
    // 0x800607A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800607A4:
    // 0x800607A4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800607A8: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x800607AC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800607B0: nop

    // 0x800607B4: divu        $zero, $t5, $t6
    lo = S32(U32(ctx->r13) / U32(ctx->r14)); hi = S32(U32(ctx->r13) % U32(ctx->r14));
    // 0x800607B8: bne         $t6, $zero, L_800607C4
    if (ctx->r14 != 0) {
        // 0x800607BC: nop
    
            goto L_800607C4;
    }
    // 0x800607BC: nop

    // 0x800607C0: break       7
    do_break(2147878848);
L_800607C4:
    // 0x800607C4: mfhi        $t7
    ctx->r15 = hi;
    // 0x800607C8: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x800607CC: addu        $t8, $sp, $t2
    ctx->r24 = ADD32(ctx->r29, ctx->r10);
    // 0x800607D0: lh          $t8, 0x38($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X38);
    // 0x800607D4: nop

    // 0x800607D8: sh          $t8, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r24;
L_800607DC:
    // 0x800607DC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800607E0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800607E4: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x800607E8: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x800607EC: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x800607F0: jal         0x80061990
    // 0x800607F4: nop

    func_80061990(rdram, ctx);
        goto after_7;
    // 0x800607F4: nop

    after_7:
    // 0x800607F8: lh          $v0, 0x36($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X36);
    // 0x800607FC: b           L_8006080C
    // 0x80060800: nop

        goto L_8006080C;
    // 0x80060800: nop

    // 0x80060804: b           L_8006080C
    // 0x80060808: nop

        goto L_8006080C;
    // 0x80060808: nop

L_8006080C:
    // 0x8006080C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060814: jr          $ra
    // 0x80060818: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80060818: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800776C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800776C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800776CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800776D0: jal         0x80061488
    // 0x800776D4: addiu       $a0, $zero, 0x6CE
    ctx->r4 = ADD32(0, 0X6CE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800776D4: addiu       $a0, $zero, 0x6CE
    ctx->r4 = ADD32(0, 0X6CE);
    after_0:
    // 0x800776D8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800776DC: b           L_800776EC
    // 0x800776E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800776EC;
    // 0x800776E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800776E4: b           L_800776EC
    // 0x800776E8: nop

        goto L_800776EC;
    // 0x800776E8: nop

L_800776EC:
    // 0x800776EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800776F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800776F4: jr          $ra
    // 0x800776F8: nop

    return;
    // 0x800776F8: nop

;}
RECOMP_FUNC void func_80031C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80031C38: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80031C3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031C40: lhu         $t6, -0x6504($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6504);
    // 0x80031C44: xor         $t7, $a0, $at
    ctx->r15 = ctx->r4 ^ ctx->r1;
    // 0x80031C48: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80031C4C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80031C50: sh          $t8, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = ctx->r24;
    // 0x80031C54: jr          $ra
    // 0x80031C58: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    return;
    // 0x80031C58: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
;}
RECOMP_FUNC void func_80009F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009F10: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009F14: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80009F18: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80009F1C: nop

    // 0x80009F20: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80009F24: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80009F28:
    // 0x80009F28: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80009F2C: lw          $t7, -0x5B2C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5B2C);
    // 0x80009F30: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80009F34: nop

    // 0x80009F38: sw          $t7, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r15;
    // 0x80009F3C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80009F40: nop

    // 0x80009F44: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80009F48: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80009F4C: bne         $at, $zero, L_80009F28
    if (ctx->r1 != 0) {
        // 0x80009F50: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_80009F28;
    }
    // 0x80009F50: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80009F54: b           L_80009F5C
    // 0x80009F58: nop

        goto L_80009F5C;
    // 0x80009F58: nop

L_80009F5C:
    // 0x80009F5C: jr          $ra
    // 0x80009F60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80009F60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80009F64: nop

    // 0x80009F68: nop

    // 0x80009F6C: nop

;}
RECOMP_FUNC void func_8006D624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D62C: jal         0x80061348
    // 0x8006D630: addiu       $a0, $zero, 0x71D
    ctx->r4 = ADD32(0, 0X71D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D630: addiu       $a0, $zero, 0x71D
    ctx->r4 = ADD32(0, 0X71D);
    after_0:
    // 0x8006D634: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D638: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D63C: b           L_8006D64C
    // 0x8006D640: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_8006D64C;
    // 0x8006D640: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D644: b           L_8006D64C
    // 0x8006D648: nop

        goto L_8006D64C;
    // 0x8006D648: nop

L_8006D64C:
    // 0x8006D64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D654: jr          $ra
    // 0x8006D658: nop

    return;
    // 0x8006D658: nop

;}
RECOMP_FUNC void func_8006B774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B77C: jal         0x80061488
    // 0x8006B780: addiu       $a0, $zero, 0x202
    ctx->r4 = ADD32(0, 0X202);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006B780: addiu       $a0, $zero, 0x202
    ctx->r4 = ADD32(0, 0X202);
    after_0:
    // 0x8006B784: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006B788: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006B78C: b           L_8006B79C
    // 0x8006B790: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006B79C;
    // 0x8006B790: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B794: b           L_8006B79C
    // 0x8006B798: nop

        goto L_8006B79C;
    // 0x8006B798: nop

L_8006B79C:
    // 0x8006B79C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B7A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B7A4: jr          $ra
    // 0x8006B7A8: nop

    return;
    // 0x8006B7A8: nop

;}
RECOMP_FUNC void func_800B69C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B69C4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800B69C8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B69CC: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B69D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B69D4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B69D8: sh          $t6, -0x73F0($at)
    MEM_H(-0X73F0, ctx->r1) = ctx->r14;
    // 0x800B69DC: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x800B69E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B69E4: sh          $t7, -0x73E4($at)
    MEM_H(-0X73E4, ctx->r1) = ctx->r15;
    // 0x800B69E8: b           L_800B69F8
    // 0x800B69EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B69F8;
    // 0x800B69EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B69F0: b           L_800B69F8
    // 0x800B69F4: nop

        goto L_800B69F8;
    // 0x800B69F4: nop

L_800B69F8:
    // 0x800B69F8: jr          $ra
    // 0x800B69FC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800B69FC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80075484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075484: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075488: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007548C: nop

    // 0x80075490: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80075494: nop

    // 0x80075498: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x8007549C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800754A0: jr          $ra
    // 0x800754A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800754A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800754A8: jr          $ra
    // 0x800754AC: nop

    return;
    // 0x800754AC: nop

    // 0x800754B0: jr          $ra
    // 0x800754B4: nop

    return;
    // 0x800754B4: nop

;}
RECOMP_FUNC void func_800758AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800758AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800758B0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800758B4: nop

    // 0x800758B8: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800758BC: nop

    // 0x800758C0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800758C4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800758C8: jr          $ra
    // 0x800758CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800758CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800758D0: jr          $ra
    // 0x800758D4: nop

    return;
    // 0x800758D4: nop

    // 0x800758D8: jr          $ra
    // 0x800758DC: nop

    return;
    // 0x800758DC: nop

;}
RECOMP_FUNC void func_8006C1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C1B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C1B8: jal         0x8005F064
    // 0x8006C1BC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C1BC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_0:
    // 0x8006C1C0: b           L_8006C1D0
    // 0x8006C1C4: nop

        goto L_8006C1D0;
    // 0x8006C1C4: nop

    // 0x8006C1C8: b           L_8006C1D0
    // 0x8006C1CC: nop

        goto L_8006C1D0;
    // 0x8006C1CC: nop

L_8006C1D0:
    // 0x8006C1D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C1D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C1D8: jr          $ra
    // 0x8006C1DC: nop

    return;
    // 0x8006C1DC: nop

;}
RECOMP_FUNC void func_80066728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006672C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066730: jal         0x80061348
    // 0x80066734: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066734: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x80066738: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006673C: b           L_8006674C
    // 0x80066740: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006674C;
    // 0x80066740: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066744: b           L_8006674C
    // 0x80066748: nop

        goto L_8006674C;
    // 0x80066748: nop

L_8006674C:
    // 0x8006674C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066754: jr          $ra
    // 0x80066758: nop

    return;
    // 0x80066758: nop

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
RECOMP_FUNC void func_800671B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800671B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800671B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800671B8: jal         0x80061488
    // 0x800671BC: addiu       $a0, $zero, 0x2DD
    ctx->r4 = ADD32(0, 0X2DD);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800671BC: addiu       $a0, $zero, 0x2DD
    ctx->r4 = ADD32(0, 0X2DD);
    after_0:
    // 0x800671C0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800671C4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800671C8: b           L_800671D8
    // 0x800671CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800671D8;
    // 0x800671CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800671D0: b           L_800671D8
    // 0x800671D4: nop

        goto L_800671D8;
    // 0x800671D4: nop

L_800671D8:
    // 0x800671D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800671DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800671E0: jr          $ra
    // 0x800671E4: nop

    return;
    // 0x800671E4: nop

;}
RECOMP_FUNC void func_80005124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005124: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000512C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80005130: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80005134: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x80005138: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x8000513C: jal         0x80004410
    // 0x80005140: nop

    func_80004410(rdram, ctx);
        goto after_0;
    // 0x80005140: nop

    after_0:
    // 0x80005144: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80005148: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000514C: nop

    // 0x80005150: bne         $t6, $zero, L_80005160
    if (ctx->r14 != 0) {
        // 0x80005154: nop
    
            goto L_80005160;
    }
    // 0x80005154: nop

    // 0x80005158: b           L_800051C4
    // 0x8000515C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800051C4;
    // 0x8000515C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005160:
    // 0x80005160: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80005164: nop

    // 0x80005168: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8000516C: nop

    // 0x80005170: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80005174: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80005178: nop

    // 0x8000517C: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x80005180: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80005184: jal         0x800C4270
    // 0x80005188: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x80005188: nop

    after_1:
    // 0x8000518C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80005190: jal         0x80004CD4
    // 0x80005194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80004CD4(rdram, ctx);
        goto after_2;
    // 0x80005194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80005198: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000519C: bne         $v0, $at, L_800051B4
    if (ctx->r2 != ctx->r1) {
        // 0x800051A0: nop
    
            goto L_800051B4;
    }
    // 0x800051A0: nop

    // 0x800051A4: jal         0x80005460
    // 0x800051A8: nop

    func_80005460(rdram, ctx);
        goto after_3;
    // 0x800051A8: nop

    after_3:
    // 0x800051AC: b           L_800051C4
    // 0x800051B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800051C4;
    // 0x800051B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800051B4:
    // 0x800051B4: b           L_800051C4
    // 0x800051B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800051C4;
    // 0x800051B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800051BC: b           L_800051C4
    // 0x800051C0: nop

        goto L_800051C4;
    // 0x800051C0: nop

L_800051C4:
    // 0x800051C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800051C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800051CC: jr          $ra
    // 0x800051D0: nop

    return;
    // 0x800051D0: nop

;}
RECOMP_FUNC void func_80063044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006304C: jal         0x8005F064
    // 0x80063050: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063050: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_0:
    // 0x80063054: b           L_80063064
    // 0x80063058: nop

        goto L_80063064;
    // 0x80063058: nop

    // 0x8006305C: b           L_80063064
    // 0x80063060: nop

        goto L_80063064;
    // 0x80063060: nop

L_80063064:
    // 0x80063064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006306C: jr          $ra
    // 0x80063070: nop

    return;
    // 0x80063070: nop

;}
RECOMP_FUNC void func_8002D3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D3B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002D3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D3B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002D3BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002D3C0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002D3C4: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x8002D3C8: nop

    // 0x8002D3CC: slti        $at, $t6, 0x79
    ctx->r1 = SIGNED(ctx->r14) < 0X79 ? 1 : 0;
    // 0x8002D3D0: bne         $at, $zero, L_8002D3E0
    if (ctx->r1 != 0) {
        // 0x8002D3D4: nop
    
            goto L_8002D3E0;
    }
    // 0x8002D3D4: nop

    // 0x8002D3D8: b           L_8002D424
    // 0x8002D3DC: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
        goto L_8002D424;
    // 0x8002D3DC: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
L_8002D3E0:
    // 0x8002D3E0: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x8002D3E4: nop

    // 0x8002D3E8: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x8002D3EC: bne         $at, $zero, L_8002D400
    if (ctx->r1 != 0) {
        // 0x8002D3F0: nop
    
            goto L_8002D400;
    }
    // 0x8002D3F0: nop

    // 0x8002D3F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002D3F8: b           L_8002D424
    // 0x8002D3FC: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
        goto L_8002D424;
    // 0x8002D3FC: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
L_8002D400:
    // 0x8002D400: lh          $t9, 0x3A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3A);
    // 0x8002D404: nop

    // 0x8002D408: bne         $t9, $zero, L_8002D41C
    if (ctx->r25 != 0) {
        // 0x8002D40C: nop
    
            goto L_8002D41C;
    }
    // 0x8002D40C: nop

    // 0x8002D410: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8002D414: b           L_8002D424
    // 0x8002D418: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
        goto L_8002D424;
    // 0x8002D418: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
L_8002D41C:
    // 0x8002D41C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8002D420: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
L_8002D424:
    // 0x8002D424: lh          $t2, 0x36($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X36);
    // 0x8002D428: nop

    // 0x8002D42C: bltz        $t2, L_8002D450
    if (SIGNED(ctx->r10) < 0) {
        // 0x8002D430: nop
    
            goto L_8002D450;
    }
    // 0x8002D430: nop

    // 0x8002D434: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x8002D438: nop

    // 0x8002D43C: bne         $t2, $t3, L_8002D450
    if (ctx->r10 != ctx->r11) {
        // 0x8002D440: nop
    
            goto L_8002D450;
    }
    // 0x8002D440: nop

    // 0x8002D444: lh          $v0, 0x2E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2E);
    // 0x8002D448: b           L_8002D588
    // 0x8002D44C: nop

        goto L_8002D588;
    // 0x8002D44C: nop

L_8002D450:
    // 0x8002D450: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002D454: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002D458: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x8002D45C: addiu       $a2, $a2, 0x3E00
    ctx->r6 = ADD32(ctx->r6, 0X3E00);
    // 0x8002D460: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002D464: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002D468: jal         0x800BD1FC
    // 0x8002D46C: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, 0X200);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8002D46C: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, 0X200);
    after_0:
    // 0x8002D470: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8002D474: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002D478: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D47C: lw          $a1, 0x138($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X138);
    // 0x8002D480: jal         0x800BD218
    // 0x8002D484: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8002D484: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    after_1:
    // 0x8002D488: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002D48C: nop

    // 0x8002D490: lw          $t6, 0x128($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X128);
    // 0x8002D494: nop

    // 0x8002D498: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8002D49C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002D4A0: nop

    // 0x8002D4A4: beq         $t7, $zero, L_8002D4B8
    if (ctx->r15 == 0) {
        // 0x8002D4A8: nop
    
            goto L_8002D4B8;
    }
    // 0x8002D4A8: nop

    // 0x8002D4AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002D4B0: jal         0x800BC980
    // 0x8002D4B4: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8002D4B4: nop

    after_2:
L_8002D4B8:
    // 0x8002D4B8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8002D4BC: addiu       $t8, $t8, 0x5B0
    ctx->r24 = ADD32(ctx->r24, 0X5B0);
    // 0x8002D4C0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8002D4C4: lh          $t9, 0x2E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2E);
    // 0x8002D4C8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002D4CC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002D4D0: lui         $t2, 0x809B
    ctx->r10 = S32(0X809B << 16);
    // 0x8002D4D4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8002D4D8: addiu       $t1, $t0, 0x1A8
    ctx->r9 = ADD32(ctx->r8, 0X1A8);
    // 0x8002D4DC: addiu       $t2, $t2, 0x3C30
    ctx->r10 = ADD32(ctx->r10, 0X3C30);
    // 0x8002D4E0: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002D4E4: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002D4E8: jal         0x800BD1FC
    // 0x8002D4EC: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8002D4EC: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x8002D4F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8002D4F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D4F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8002D4FC: jal         0x800BD218
    // 0x8002D500: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x8002D500: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x8002D504: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D508: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002D50C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8002D510: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002D514: lui         $t5, 0x809B
    ctx->r13 = S32(0X809B << 16);
    // 0x8002D518: addiu       $t5, $t5, 0x1E10
    ctx->r13 = ADD32(ctx->r13, 0X1E10);
    // 0x8002D51C: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002D520: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002D524: jal         0x800BD1FC
    // 0x8002D528: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8002D528: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x8002D52C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8002D530: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D534: jal         0x800BED70
    // 0x8002D538: nop

    Spi_GetHeader(rdram, ctx);
        goto after_6;
    // 0x8002D538: nop

    after_6:
    // 0x8002D53C: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8002D540: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8002D544: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8002D548: jal         0x800BC6EC
    // 0x8002D54C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x8002D54C: nop

    after_7:
    // 0x8002D550: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8002D554: nop

    // 0x8002D558: sw          $v0, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->r2;
    // 0x8002D55C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8002D560: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D564: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x8002D568: lw          $a2, 0x128($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X128);
    // 0x8002D56C: jal         0x800BF0B4
    // 0x8002D570: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_8;
    // 0x8002D570: nop

    after_8:
    // 0x8002D574: lh          $v0, 0x2E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2E);
    // 0x8002D578: b           L_8002D588
    // 0x8002D57C: nop

        goto L_8002D588;
    // 0x8002D57C: nop

    // 0x8002D580: b           L_8002D588
    // 0x8002D584: nop

        goto L_8002D588;
    // 0x8002D584: nop

L_8002D588:
    // 0x8002D588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D58C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002D590: jr          $ra
    // 0x8002D594: nop

    return;
    // 0x8002D594: nop

;}
RECOMP_FUNC void func_8006B6A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B6A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B6A8: nop

    // 0x8006B6AC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B6B0: nop

    // 0x8006B6B4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B6B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B6BC: jr          $ra
    // 0x8006B6C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B6C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B6C4: jr          $ra
    // 0x8006B6C8: nop

    return;
    // 0x8006B6C8: nop

    // 0x8006B6CC: jr          $ra
    // 0x8006B6D0: nop

    return;
    // 0x8006B6D0: nop

;}
RECOMP_FUNC void alCSeqGetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA1E0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800CA1E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CA1E8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800CA1EC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800CA1F0: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800CA1F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA1F8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800CA1FC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800CA200: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x800CA204: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800CA208: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CA20C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
L_800CA210:
    // 0x800CA210: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
    // 0x800CA214: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800CA218: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800CA21C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CA220: lw          $t1, 0x58($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X58);
    // 0x800CA224: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800CA228: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800CA22C: sw          $t1, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r9;
    // 0x800CA230: lbu         $t2, 0x98($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X98);
    // 0x800CA234: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800CA238: sb          $t2, 0x8A($a3)
    MEM_B(0X8A, ctx->r7) = ctx->r10;
    // 0x800CA23C: lbu         $t3, 0xA6($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA6);
    // 0x800CA240: sb          $t3, 0x9A($a3)
    MEM_B(0X9A, ctx->r7) = ctx->r11;
    // 0x800CA244: lw          $t4, 0xB0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XB0);
    // 0x800CA248: sw          $t4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r12;
    // 0x800CA24C: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x800CA250: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x800CA254: lw          $t6, 0x54($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X54);
    // 0x800CA258: sw          $t6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r14;
    // 0x800CA25C: lbu         $t7, 0x97($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X97);
    // 0x800CA260: sb          $t7, 0x8B($a3)
    MEM_B(0X8B, ctx->r7) = ctx->r15;
    // 0x800CA264: lbu         $t8, 0xA7($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XA7);
    // 0x800CA268: sb          $t8, 0x9B($a3)
    MEM_B(0X9B, ctx->r7) = ctx->r24;
    // 0x800CA26C: lw          $t9, 0xB4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XB4);
    // 0x800CA270: bne         $v0, $a0, L_800CA210
    if (ctx->r2 != ctx->r4) {
        // 0x800CA274: sw          $t9, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r25;
            goto L_800CA210;
    }
    // 0x800CA274: sw          $t9, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r25;
    // 0x800CA278: jr          $ra
    // 0x800CA27C: nop

    return;
    // 0x800CA27C: nop

;}
RECOMP_FUNC void func_8006D274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D27C: jal         0x80061348
    // 0x8006D280: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D280: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006D284: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D288: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D28C: beq         $v0, $zero, L_8006D2A4
    if (ctx->r2 == 0) {
        // 0x8006D290: nop
    
            goto L_8006D2A4;
    }
    // 0x8006D290: nop

    // 0x8006D294: jal         0x80061348
    // 0x8006D298: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006D298: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x8006D29C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D2A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006D2A4:
    // 0x8006D2A4: b           L_8006D2B4
    // 0x8006D2A8: nop

        goto L_8006D2B4;
    // 0x8006D2A8: nop

    // 0x8006D2AC: b           L_8006D2B4
    // 0x8006D2B0: nop

        goto L_8006D2B4;
    // 0x8006D2B0: nop

L_8006D2B4:
    // 0x8006D2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D2B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D2BC: jr          $ra
    // 0x8006D2C0: nop

    return;
    // 0x8006D2C0: nop

;}
RECOMP_FUNC void func_8008C0A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0A4: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8008C0A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008C0AC: sh          $t6, 0x100($t7)
    MEM_H(0X100, ctx->r15) = ctx->r14;
    // 0x8008C0B0: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8008C0B4: ori         $t8, $zero, 0xD6B5
    ctx->r24 = 0 | 0XD6B5;
    // 0x8008C0B8: sh          $t8, 0x102($t9)
    MEM_H(0X102, ctx->r25) = ctx->r24;
    // 0x8008C0BC: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x8008C0C0: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8008C0C4: sh          $t0, 0x104($t1)
    MEM_H(0X104, ctx->r9) = ctx->r8;
    // 0x8008C0C8: jr          $ra
    // 0x8008C0CC: nop

    return;
    // 0x8008C0CC: nop

    // 0x8008C0D0: jr          $ra
    // 0x8008C0D4: nop

    return;
    // 0x8008C0D4: nop

;}
RECOMP_FUNC void func_80099450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80099454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099458: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009945C: sw          $zero, 0x2528($at)
    MEM_W(0X2528, ctx->r1) = 0;
    // 0x80099460: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80099464: lhu         $t6, 0x24FC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X24FC);
    // 0x80099468: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009946C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80099470: sh          $t7, 0x24FC($at)
    MEM_H(0X24FC, ctx->r1) = ctx->r15;
    // 0x80099474: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80099478: lhu         $t8, 0x24FC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X24FC);
    // 0x8009947C: nop

    // 0x80099480: beq         $t8, $zero, L_8009949C
    if (ctx->r24 == 0) {
        // 0x80099484: nop
    
            goto L_8009949C;
    }
    // 0x80099484: nop

    // 0x80099488: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x8009948C: addiu       $t9, $t9, -0x5800
    ctx->r25 = ADD32(ctx->r25, -0X5800);
    // 0x80099490: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80099494: b           L_800994AC
    // 0x80099498: sw          $t9, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r25;
        goto L_800994AC;
    // 0x80099498: sw          $t9, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r25;
L_8009949C:
    // 0x8009949C: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x800994A0: addiu       $t0, $t0, 0x0
    ctx->r8 = ADD32(ctx->r8, 0X0);
    // 0x800994A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800994A8: sw          $t0, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r8;
L_800994AC:
    // 0x800994AC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800994B0: lhu         $t1, 0x24FC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X24FC);
    // 0x800994B4: nop

    // 0x800994B8: beq         $t1, $zero, L_800994D4
    if (ctx->r9 == 0) {
        // 0x800994BC: nop
    
            goto L_800994D4;
    }
    // 0x800994BC: nop

    // 0x800994C0: lui         $t2, 0x8020
    ctx->r10 = S32(0X8020 << 16);
    // 0x800994C4: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x800994C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800994CC: b           L_800994E4
    // 0x800994D0: sw          $t2, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r10;
        goto L_800994E4;
    // 0x800994D0: sw          $t2, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r10;
L_800994D4:
    // 0x800994D4: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x800994D8: addiu       $t3, $t3, -0x5800
    ctx->r11 = ADD32(ctx->r11, -0X5800);
    // 0x800994DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800994E0: sw          $t3, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r11;
L_800994E4:
    // 0x800994E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800994E8: lw          $a0, 0x24D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D0);
    // 0x800994EC: jal         0x8008ECCC
    // 0x800994F0: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_0;
    // 0x800994F0: nop

    after_0:
    // 0x800994F4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800994F8: lw          $t4, 0x258C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X258C);
    // 0x800994FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80099500: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80099504: sw          $t5, 0x258C($at)
    MEM_W(0X258C, ctx->r1) = ctx->r13;
    // 0x80099508: b           L_80099510
    // 0x8009950C: nop

        goto L_80099510;
    // 0x8009950C: nop

L_80099510:
    // 0x80099510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80099518: jr          $ra
    // 0x8009951C: nop

    return;
    // 0x8009951C: nop

;}
RECOMP_FUNC void func_8005C304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C304: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005C308: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005C30C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C310: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005C314: nop

    // 0x8005C318: beq         $t6, $zero, L_8005C374
    if (ctx->r14 == 0) {
        // 0x8005C31C: nop
    
            goto L_8005C374;
    }
    // 0x8005C31C: nop

    // 0x8005C320: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C324: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005C328: nop

    // 0x8005C32C: beq         $t7, $zero, L_8005C374
    if (ctx->r15 == 0) {
        // 0x8005C330: nop
    
            goto L_8005C374;
    }
    // 0x8005C330: nop

    // 0x8005C334: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005C338: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8005C33C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005C340: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005C344: bne         $t0, $zero, L_8005C354
    if (ctx->r8 != 0) {
        // 0x8005C348: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8005C354;
    }
    // 0x8005C348: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005C34C: beq         $t1, $zero, L_8005C374
    if (ctx->r9 == 0) {
        // 0x8005C350: nop
    
            goto L_8005C374;
    }
    // 0x8005C350: nop

L_8005C354:
    // 0x8005C354: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8005C358: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8005C35C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005C360: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005C364: bne         $t4, $zero, L_8005C37C
    if (ctx->r12 != 0) {
        // 0x8005C368: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8005C37C;
    }
    // 0x8005C368: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8005C36C: bne         $t5, $zero, L_8005C37C
    if (ctx->r13 != 0) {
        // 0x8005C370: nop
    
            goto L_8005C37C;
    }
    // 0x8005C370: nop

L_8005C374:
    // 0x8005C374: b           L_8005C8FC
    // 0x8005C378: nop

        goto L_8005C8FC;
    // 0x8005C378: nop

L_8005C37C:
    // 0x8005C37C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C380: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005C384: nop

    // 0x8005C388: lh          $t8, 0xAC($t6)
    ctx->r24 = MEM_H(ctx->r14, 0XAC);
    // 0x8005C38C: nop

    // 0x8005C390: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8005C394: bne         $t9, $zero, L_8005C5EC
    if (ctx->r25 != 0) {
        // 0x8005C398: nop
    
            goto L_8005C5EC;
    }
    // 0x8005C398: nop

    // 0x8005C39C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005C3A0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005C3A4: nop

    // 0x8005C3A8: lh          $t1, 0xAC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XAC);
    // 0x8005C3AC: nop

    // 0x8005C3B0: andi        $t7, $t1, 0x1
    ctx->r15 = ctx->r9 & 0X1;
    // 0x8005C3B4: bne         $t7, $zero, L_8005C478
    if (ctx->r15 != 0) {
        // 0x8005C3B8: nop
    
            goto L_8005C478;
    }
    // 0x8005C3B8: nop

    // 0x8005C3BC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C3C0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005C3C4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C3C8: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005C3CC: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x8005C3D0: lw          $a1, 0x4C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4C);
    // 0x8005C3D4: lw          $a2, 0x50($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X50);
    // 0x8005C3D8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005C3DC: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8005C3E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005C3E4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005C3E8: lw          $t6, 0x50($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X50);
    // 0x8005C3EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8005C3F0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005C3F4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005C3F8: jal         0x800784E8
    // 0x8005C3FC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800784E8(rdram, ctx);
        goto after_0;
    // 0x8005C3FC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8005C400: beq         $v0, $zero, L_8005C478
    if (ctx->r2 == 0) {
        // 0x8005C404: nop
    
            goto L_8005C478;
    }
    // 0x8005C404: nop

    // 0x8005C408: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C40C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005C410: nop

    // 0x8005C414: lh          $t0, 0xAC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XAC);
    // 0x8005C418: nop

    // 0x8005C41C: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x8005C420: sh          $t1, 0xAC($t9)
    MEM_H(0XAC, ctx->r25) = ctx->r9;
    // 0x8005C424: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C428: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005C42C: nop

    // 0x8005C430: lh          $t2, 0xAC($t7)
    ctx->r10 = MEM_H(ctx->r15, 0XAC);
    // 0x8005C434: nop

    // 0x8005C438: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8005C43C: sh          $t3, 0xAC($t7)
    MEM_H(0XAC, ctx->r15) = ctx->r11;
    // 0x8005C440: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8005C444: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005C448: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005C44C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005C450: nop

    // 0x8005C454: swc1        $f4, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f4.u32l;
    // 0x8005C458: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005C45C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C460: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005C464: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005C468: nop

    // 0x8005C46C: swc1        $f6, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f6.u32l;
    // 0x8005C470: jal         0x800B9000
    // 0x8005C474: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8005C474: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
L_8005C478:
    // 0x8005C478: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C47C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005C480: nop

    // 0x8005C484: lh          $t8, 0xAC($t6)
    ctx->r24 = MEM_H(ctx->r14, 0XAC);
    // 0x8005C488: nop

    // 0x8005C48C: andi        $t0, $t8, 0x8
    ctx->r8 = ctx->r24 & 0X8;
    // 0x8005C490: bne         $t0, $zero, L_8005C5EC
    if (ctx->r8 != 0) {
        // 0x8005C494: nop
    
            goto L_8005C5EC;
    }
    // 0x8005C494: nop

    // 0x8005C498: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005C49C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005C4A0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C4A4: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005C4A8: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x8005C4AC: lw          $a1, 0x4C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4C);
    // 0x8005C4B0: lw          $a2, 0x50($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X50);
    // 0x8005C4B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005C4B8: lw          $t3, 0x4C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4C);
    // 0x8005C4BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005C4C0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8005C4C4: lw          $t7, 0x50($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X50);
    // 0x8005C4C8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8005C4CC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005C4D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005C4D4: jal         0x800784E8
    // 0x8005C4D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800784E8(rdram, ctx);
        goto after_2;
    // 0x8005C4D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_2:
    // 0x8005C4DC: beq         $v0, $zero, L_8005C5EC
    if (ctx->r2 == 0) {
        // 0x8005C4E0: nop
    
            goto L_8005C5EC;
    }
    // 0x8005C4E0: nop

    // 0x8005C4E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C4E8: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005C4EC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C4F0: lw          $t8, 0xB4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XB4);
    // 0x8005C4F4: lw          $t4, 0x670($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X670);
    // 0x8005C4F8: lh          $t0, 0xA($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XA);
    // 0x8005C4FC: nop

    // 0x8005C500: bgez        $t0, L_8005C510
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005C504: sra         $t1, $t0, 2
        ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
            goto L_8005C510;
    }
    // 0x8005C504: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8005C508: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
    // 0x8005C50C: sra         $t1, $at, 2
    ctx->r9 = S32(SIGNED(ctx->r1) >> 2);
L_8005C510:
    // 0x8005C510: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005C514: beq         $at, $zero, L_8005C54C
    if (ctx->r1 == 0) {
        // 0x8005C518: nop
    
            goto L_8005C54C;
    }
    // 0x8005C518: nop

    // 0x8005C51C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C520: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005C524: nop

    // 0x8005C528: lh          $t3, 0xAC($t9)
    ctx->r11 = MEM_H(ctx->r25, 0XAC);
    // 0x8005C52C: nop

    // 0x8005C530: ori         $t2, $t3, 0x80
    ctx->r10 = ctx->r11 | 0X80;
    // 0x8005C534: sh          $t2, 0xAC($t9)
    MEM_H(0XAC, ctx->r25) = ctx->r10;
    // 0x8005C538: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005C53C: lw          $a0, 0xE70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE70);
    // 0x8005C540: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8005C544: jal         0x8005C90C
    // 0x8005C548: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8005C90C(rdram, ctx);
        goto after_3;
    // 0x8005C548: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_3:
L_8005C54C:
    // 0x8005C54C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C550: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005C554: nop

    // 0x8005C558: lh          $t5, 0xAC($t7)
    ctx->r13 = MEM_H(ctx->r15, 0XAC);
    // 0x8005C55C: nop

    // 0x8005C560: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x8005C564: sh          $t6, 0xAC($t7)
    MEM_H(0XAC, ctx->r15) = ctx->r14;
    // 0x8005C568: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005C56C: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x8005C570: nop

    // 0x8005C574: lh          $t0, 0xAC($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XAC);
    // 0x8005C578: nop

    // 0x8005C57C: ori         $t4, $t0, 0x2
    ctx->r12 = ctx->r8 | 0X2;
    // 0x8005C580: sh          $t4, 0xAC($t8)
    MEM_H(0XAC, ctx->r24) = ctx->r12;
    // 0x8005C584: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8005C588: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005C58C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005C590: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005C594: nop

    // 0x8005C598: swc1        $f8, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f8.u32l;
    // 0x8005C59C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005C5A0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005C5A4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005C5A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005C5AC: nop

    // 0x8005C5B0: swc1        $f10, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f10.u32l;
    // 0x8005C5B4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C5B8: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005C5BC: nop

    // 0x8005C5C0: lh          $t9, 0xAC($t2)
    ctx->r25 = MEM_H(ctx->r10, 0XAC);
    // 0x8005C5C4: nop

    // 0x8005C5C8: andi        $t5, $t9, 0x80
    ctx->r13 = ctx->r25 & 0X80;
    // 0x8005C5CC: beq         $t5, $zero, L_8005C5E4
    if (ctx->r13 == 0) {
        // 0x8005C5D0: nop
    
            goto L_8005C5E4;
    }
    // 0x8005C5D0: nop

    // 0x8005C5D4: jal         0x800B9000
    // 0x8005C5D8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_800B9000(rdram, ctx);
        goto after_4;
    // 0x8005C5D8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_4:
    // 0x8005C5DC: b           L_8005C5EC
    // 0x8005C5E0: nop

        goto L_8005C5EC;
    // 0x8005C5E0: nop

L_8005C5E4:
    // 0x8005C5E4: jal         0x800B9000
    // 0x8005C5E8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x8005C5E8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_5:
L_8005C5EC:
    // 0x8005C5EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C5F0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005C5F4: nop

    // 0x8005C5F8: lh          $t7, 0xAC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XAC);
    // 0x8005C5FC: nop

    // 0x8005C600: andi        $t0, $t7, 0x2
    ctx->r8 = ctx->r15 & 0X2;
    // 0x8005C604: bne         $t0, $zero, L_8005C8F4
    if (ctx->r8 != 0) {
        // 0x8005C608: nop
    
            goto L_8005C8F4;
    }
    // 0x8005C608: nop

    // 0x8005C60C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C610: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005C614: nop

    // 0x8005C618: lh          $t8, 0xAC($t4)
    ctx->r24 = MEM_H(ctx->r12, 0XAC);
    // 0x8005C61C: nop

    // 0x8005C620: andi        $t1, $t8, 0x1
    ctx->r9 = ctx->r24 & 0X1;
    // 0x8005C624: bne         $t1, $zero, L_8005C730
    if (ctx->r9 != 0) {
        // 0x8005C628: nop
    
            goto L_8005C730;
    }
    // 0x8005C628: nop

    // 0x8005C62C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005C630: lw          $t3, 0xE70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE70);
    // 0x8005C634: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C638: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005C63C: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x8005C640: lw          $a1, 0x4C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4C);
    // 0x8005C644: lw          $a2, 0x50($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X50);
    // 0x8005C648: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005C64C: lw          $t5, 0x4C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4C);
    // 0x8005C650: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005C654: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005C658: lw          $t6, 0x50($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X50);
    // 0x8005C65C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8005C660: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005C664: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005C668: jal         0x800784E8
    // 0x8005C66C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800784E8(rdram, ctx);
        goto after_6;
    // 0x8005C66C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_6:
    // 0x8005C670: beq         $v0, $zero, L_8005C730
    if (ctx->r2 == 0) {
        // 0x8005C674: nop
    
            goto L_8005C730;
    }
    // 0x8005C674: nop

    // 0x8005C678: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005C67C: lw          $t0, 0xE70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE70);
    // 0x8005C680: nop

    // 0x8005C684: lh          $t4, 0xAC($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XAC);
    // 0x8005C688: nop

    // 0x8005C68C: ori         $t8, $t4, 0x8
    ctx->r24 = ctx->r12 | 0X8;
    // 0x8005C690: sh          $t8, 0xAC($t0)
    MEM_H(0XAC, ctx->r8) = ctx->r24;
    // 0x8005C694: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005C698: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005C69C: nop

    // 0x8005C6A0: lh          $t3, 0xAC($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XAC);
    // 0x8005C6A4: nop

    // 0x8005C6A8: ori         $t2, $t3, 0x2
    ctx->r10 = ctx->r11 | 0X2;
    // 0x8005C6AC: sh          $t2, 0xAC($t1)
    MEM_H(0XAC, ctx->r9) = ctx->r10;
    // 0x8005C6B0: jal         0x800B9000
    // 0x8005C6B4: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    func_800B9000(rdram, ctx);
        goto after_7;
    // 0x8005C6B4: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    after_7:
    // 0x8005C6B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005C6BC: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005C6C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005C6C4: jal         0x800B334C
    // 0x8005C6C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_8;
    // 0x8005C6C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_8:
    // 0x8005C6CC: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
    // 0x8005C6D0: beq         $t5, $zero, L_8005C700
    if (ctx->r13 == 0) {
        // 0x8005C6D4: nop
    
            goto L_8005C700;
    }
    // 0x8005C6D4: nop

    // 0x8005C6D8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C6DC: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005C6E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C6E4: nop

    // 0x8005C6E8: swc1        $f16, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f16.u32l;
    // 0x8005C6EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C6F0: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005C6F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005C6F8: b           L_8005C730
    // 0x8005C6FC: swc1        $f18, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f18.u32l;
        goto L_8005C730;
    // 0x8005C6FC: swc1        $f18, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f18.u32l;
L_8005C700:
    // 0x8005C700: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8005C704: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C708: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005C70C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005C710: nop

    // 0x8005C714: swc1        $f4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f4.u32l;
    // 0x8005C718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005C71C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C720: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005C724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005C728: nop

    // 0x8005C72C: swc1        $f6, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f6.u32l;
L_8005C730:
    // 0x8005C730: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005C734: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x8005C738: nop

    // 0x8005C73C: lh          $t0, 0xAC($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XAC);
    // 0x8005C740: nop

    // 0x8005C744: andi        $t3, $t0, 0x8
    ctx->r11 = ctx->r8 & 0X8;
    // 0x8005C748: bne         $t3, $zero, L_8005C8F4
    if (ctx->r11 != 0) {
        // 0x8005C74C: nop
    
            goto L_8005C8F4;
    }
    // 0x8005C74C: nop

    // 0x8005C750: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C754: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005C758: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005C75C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005C760: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x8005C764: lw          $a1, 0x4C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4C);
    // 0x8005C768: lw          $a2, 0x50($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X50);
    // 0x8005C76C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005C770: lw          $t9, 0x4C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4C);
    // 0x8005C774: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005C778: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8005C77C: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x8005C780: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8005C784: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005C788: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005C78C: jal         0x800784E8
    // 0x8005C790: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800784E8(rdram, ctx);
        goto after_9;
    // 0x8005C790: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_9:
    // 0x8005C794: beq         $v0, $zero, L_8005C8F4
    if (ctx->r2 == 0) {
        // 0x8005C798: nop
    
            goto L_8005C8F4;
    }
    // 0x8005C798: nop

    // 0x8005C79C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C7A0: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005C7A4: nop

    // 0x8005C7A8: lh          $t8, 0xAC($t4)
    ctx->r24 = MEM_H(ctx->r12, 0XAC);
    // 0x8005C7AC: nop

    // 0x8005C7B0: ori         $t0, $t8, 0x4
    ctx->r8 = ctx->r24 | 0X4;
    // 0x8005C7B4: sh          $t0, 0xAC($t4)
    MEM_H(0XAC, ctx->r12) = ctx->r8;
    // 0x8005C7B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005C7BC: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005C7C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005C7C4: jal         0x800B334C
    // 0x8005C7C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_10;
    // 0x8005C7C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_10:
    // 0x8005C7CC: andi        $t3, $v0, 0x2000
    ctx->r11 = ctx->r2 & 0X2000;
    // 0x8005C7D0: beq         $t3, $zero, L_8005C808
    if (ctx->r11 == 0) {
        // 0x8005C7D4: nop
    
            goto L_8005C808;
    }
    // 0x8005C7D4: nop

    // 0x8005C7D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005C7DC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C7E0: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005C7E4: lwc1        $f8, -0xE40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE40);
    // 0x8005C7E8: nop

    // 0x8005C7EC: swc1        $f8, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f8.u32l;
    // 0x8005C7F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005C7F4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005C7F8: lw          $t1, 0xE70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE70);
    // 0x8005C7FC: lwc1        $f10, -0xE3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE3C);
    // 0x8005C800: b           L_8005C8BC
    // 0x8005C804: swc1        $f10, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f10.u32l;
        goto L_8005C8BC;
    // 0x8005C804: swc1        $f10, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f10.u32l;
L_8005C808:
    // 0x8005C808: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005C80C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005C810: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C814: lw          $t6, 0xB4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XB4);
    // 0x8005C818: lw          $t9, 0x670($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X670);
    // 0x8005C81C: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8005C820: nop

    // 0x8005C824: bgez        $t7, L_8005C834
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005C828: sra         $t8, $t7, 2
        ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
            goto L_8005C834;
    }
    // 0x8005C828: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8005C82C: addiu       $at, $t7, 0x3
    ctx->r1 = ADD32(ctx->r15, 0X3);
    // 0x8005C830: sra         $t8, $at, 2
    ctx->r24 = S32(SIGNED(ctx->r1) >> 2);
L_8005C834:
    // 0x8005C834: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8005C838: beq         $at, $zero, L_8005C870
    if (ctx->r1 == 0) {
        // 0x8005C83C: nop
    
            goto L_8005C870;
    }
    // 0x8005C83C: nop

    // 0x8005C840: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005C844: lw          $t0, 0xE70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE70);
    // 0x8005C848: nop

    // 0x8005C84C: lh          $t4, 0xAC($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XAC);
    // 0x8005C850: nop

    // 0x8005C854: ori         $t3, $t4, 0x80
    ctx->r11 = ctx->r12 | 0X80;
    // 0x8005C858: sh          $t3, 0xAC($t0)
    MEM_H(0XAC, ctx->r8) = ctx->r11;
    // 0x8005C85C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005C860: lw          $a0, 0xE70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE70);
    // 0x8005C864: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8005C868: jal         0x8005C90C
    // 0x8005C86C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8005C90C(rdram, ctx);
        goto after_11;
    // 0x8005C86C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_11:
L_8005C870:
    // 0x8005C870: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C874: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005C878: nop

    // 0x8005C87C: lh          $t1, 0xAC($t2)
    ctx->r9 = MEM_H(ctx->r10, 0XAC);
    // 0x8005C880: nop

    // 0x8005C884: ori         $t5, $t1, 0x2
    ctx->r13 = ctx->r9 | 0X2;
    // 0x8005C888: sh          $t5, 0xAC($t2)
    MEM_H(0XAC, ctx->r10) = ctx->r13;
    // 0x8005C88C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8005C890: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C894: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005C898: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005C89C: nop

    // 0x8005C8A0: swc1        $f16, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f16.u32l;
    // 0x8005C8A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005C8A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C8AC: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005C8B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005C8B4: nop

    // 0x8005C8B8: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
L_8005C8BC:
    // 0x8005C8BC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C8C0: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005C8C4: nop

    // 0x8005C8C8: lh          $t8, 0xAC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0XAC);
    // 0x8005C8CC: nop

    // 0x8005C8D0: andi        $t4, $t8, 0x80
    ctx->r12 = ctx->r24 & 0X80;
    // 0x8005C8D4: beq         $t4, $zero, L_8005C8EC
    if (ctx->r12 == 0) {
        // 0x8005C8D8: nop
    
            goto L_8005C8EC;
    }
    // 0x8005C8D8: nop

    // 0x8005C8DC: jal         0x800B9000
    // 0x8005C8E0: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_800B9000(rdram, ctx);
        goto after_12;
    // 0x8005C8E0: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_12:
    // 0x8005C8E4: b           L_8005C8F4
    // 0x8005C8E8: nop

        goto L_8005C8F4;
    // 0x8005C8E8: nop

L_8005C8EC:
    // 0x8005C8EC: jal         0x800B9000
    // 0x8005C8F0: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800B9000(rdram, ctx);
        goto after_13;
    // 0x8005C8F0: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_13:
L_8005C8F4:
    // 0x8005C8F4: b           L_8005C8FC
    // 0x8005C8F8: nop

        goto L_8005C8FC;
    // 0x8005C8F8: nop

L_8005C8FC:
    // 0x8005C8FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005C900: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005C904: jr          $ra
    // 0x8005C908: nop

    return;
    // 0x8005C908: nop

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
RECOMP_FUNC void func_80072CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072CB8: jal         0x80061488
    // 0x80072CBC: addiu       $a0, $zero, 0x50F
    ctx->r4 = ADD32(0, 0X50F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072CBC: addiu       $a0, $zero, 0x50F
    ctx->r4 = ADD32(0, 0X50F);
    after_0:
    // 0x80072CC0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80072CC4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80072CC8: b           L_80072CD8
    // 0x80072CCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072CD8;
    // 0x80072CCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072CD0: b           L_80072CD8
    // 0x80072CD4: nop

        goto L_80072CD8;
    // 0x80072CD4: nop

L_80072CD8:
    // 0x80072CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072CE0: jr          $ra
    // 0x80072CE4: nop

    return;
    // 0x80072CE4: nop

;}
RECOMP_FUNC void func_80068614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068614: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068618: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006861C: nop

    // 0x80068620: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80068624: nop

    // 0x80068628: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x8006862C: jr          $ra
    // 0x80068630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068634: jr          $ra
    // 0x80068638: nop

    return;
    // 0x80068638: nop

    // 0x8006863C: jr          $ra
    // 0x80068640: nop

    return;
    // 0x80068640: nop

;}
RECOMP_FUNC void func_80067828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006782C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067830: jal         0x80061348
    // 0x80067834: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067834: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80067838: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006783C: b           L_8006784C
    // 0x80067840: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006784C;
    // 0x80067840: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067844: b           L_8006784C
    // 0x80067848: nop

        goto L_8006784C;
    // 0x80067848: nop

L_8006784C:
    // 0x8006784C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067854: jr          $ra
    // 0x80067858: nop

    return;
    // 0x80067858: nop

;}
RECOMP_FUNC void func_80068120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068120: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068124: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068128: nop

    // 0x8006812C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80068130: nop

    // 0x80068134: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068138: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006813C: jr          $ra
    // 0x80068140: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068140: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068144: jr          $ra
    // 0x80068148: nop

    return;
    // 0x80068148: nop

    // 0x8006814C: jr          $ra
    // 0x80068150: nop

    return;
    // 0x80068150: nop

;}
RECOMP_FUNC void func_80031B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031B6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031B70: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x80031B74: nop

    // 0x80031B78: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80031B7C: beq         $at, $zero, L_80031B8C
    if (ctx->r1 == 0) {
        // 0x80031B80: nop
    
            goto L_80031B8C;
    }
    // 0x80031B80: nop

    // 0x80031B84: jr          $ra
    // 0x80031B88: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    return;
    // 0x80031B88: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80031B8C:
    // 0x80031B8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80031B90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031B94: sh          $t7, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = ctx->r15;
    // 0x80031B98: jr          $ra
    // 0x80031B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8006CAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CAD0: jal         0x8005F064
    // 0x8006CAD4: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CAD4: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x8006CAD8: b           L_8006CAE8
    // 0x8006CADC: nop

        goto L_8006CAE8;
    // 0x8006CADC: nop

    // 0x8006CAE0: b           L_8006CAE8
    // 0x8006CAE4: nop

        goto L_8006CAE8;
    // 0x8006CAE4: nop

L_8006CAE8:
    // 0x8006CAE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CAEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CAF0: jr          $ra
    // 0x8006CAF4: nop

    return;
    // 0x8006CAF4: nop

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
