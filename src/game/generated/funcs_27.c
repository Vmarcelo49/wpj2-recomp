#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8003D180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D180: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x8003D184: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003D188: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003D18C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8003D190: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003D194: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8003D198: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003D19C: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x8003D1A0: nop

    // 0x8003D1A4: beq         $t6, $zero, L_8003D1C0
    if (ctx->r14 == 0) {
        // 0x8003D1A8: nop
    
            goto L_8003D1C0;
    }
    // 0x8003D1A8: nop

    // 0x8003D1AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003D1B0: nop

    // 0x8003D1B4: swc1        $f4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f4.u32l;
    // 0x8003D1B8: b           L_8003D218
    // 0x8003D1BC: swc1        $f4, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f4.u32l;
        goto L_8003D218;
    // 0x8003D1BC: swc1        $f4, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f4.u32l;
L_8003D1C0:
    // 0x8003D1C0: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8003D1C4: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8003D1C8: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8003D1CC: nop

    // 0x8003D1D0: swc1        $f6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f6.u32l;
    // 0x8003D1D4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8003D1D8: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8003D1DC: lwc1        $f8, 0x14($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8003D1E0: nop

    // 0x8003D1E4: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x8003D1E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D1EC: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003D1F0: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8003D1F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003D1F8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D1FC: c.eq.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d == ctx->f18.d;
    // 0x8003D200: nop

    // 0x8003D204: bc1f        L_8003D218
    if (!c1cs) {
        // 0x8003D208: nop
    
            goto L_8003D218;
    }
    // 0x8003D208: nop

    // 0x8003D20C: addiu       $a0, $sp, 0x128
    ctx->r4 = ADD32(ctx->r29, 0X128);
    // 0x8003D210: jal         0x80034048
    // 0x8003D214: addiu       $a1, $sp, 0x124
    ctx->r5 = ADD32(ctx->r29, 0X124);
    func_80034048(rdram, ctx);
        goto after_0;
    // 0x8003D214: addiu       $a1, $sp, 0x124
    ctx->r5 = ADD32(ctx->r29, 0X124);
    after_0:
L_8003D218:
    // 0x8003D218: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8003D21C: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8003D220: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8003D224: nop

    // 0x8003D228: sh          $t0, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r8;
    // 0x8003D22C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D230: lwc1        $f4, 0x50D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003D234: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D238: lwc1        $f6, 0x50D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003D23C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8003D240: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003D244: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D248: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8003D24C: c.eq.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d == ctx->f16.d;
    // 0x8003D250: nop

    // 0x8003D254: bc1f        L_8003D2FC
    if (!c1cs) {
        // 0x8003D258: nop
    
            goto L_8003D2FC;
    }
    // 0x8003D258: nop

    // 0x8003D25C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8003D260: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D264: lwc1        $f18, 0x7324($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003D268: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8003D26C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D270: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D274: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8003D278: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003D27C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8003D280: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8003D284: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8003D288: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8003D28C: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x8003D290: mfhi        $t5
    ctx->r13 = hi;
    // 0x8003D294: beq         $t5, $zero, L_8003D2FC
    if (ctx->r13 == 0) {
        // 0x8003D298: nop
    
            goto L_8003D2FC;
    }
    // 0x8003D298: nop

    // 0x8003D29C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003D2A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D2A4: lwc1        $f6, 0x7324($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003D2A8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003D2AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D2B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D2B4: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8003D2B8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8003D2BC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8003D2C0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003D2C4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8003D2C8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003D2CC: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8003D2D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D2D4: lwc1        $f19, -0x1410($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1410);
    // 0x8003D2D8: lwc1        $f18, -0x140C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X140C);
    // 0x8003D2DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D2E0: mflo        $t0
    ctx->r8 = lo;
    // 0x8003D2E4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8003D2E8: nop

    // 0x8003D2EC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x8003D2F0: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8003D2F4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8003D2F8: swc1        $f6, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f6.u32l;
L_8003D2FC:
    // 0x8003D2FC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003D300: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8003D304: nop

    // 0x8003D308: lh          $t2, 0x42($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X42);
    // 0x8003D30C: nop

    // 0x8003D310: sh          $t2, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r10;
    // 0x8003D314: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D318: lwc1        $f8, 0x7324($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003D31C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D320: lwc1        $f17, -0x1408($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1408);
    // 0x8003D324: lwc1        $f16, -0x1404($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1404);
    // 0x8003D328: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8003D32C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8003D330: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003D334: swc1        $f4, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f4.u32l;
    // 0x8003D338: jal         0x800C3070
    // 0x8003D33C: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x8003D33C: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    after_1:
    // 0x8003D340: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D344: lwc1        $f6, 0x720C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x8003D348: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D34C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003D350: lwc1        $f10, -0x73EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003D354: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003D358: addiu       $t3, $t3, 0x7158
    ctx->r11 = ADD32(ctx->r11, 0X7158);
    // 0x8003D35C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003D360: swc1        $f16, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f16.u32l;
    // 0x8003D364: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D368: lwc1        $f18, -0x73E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x8003D36C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003D370: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x8003D374: swc1        $f18, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f18.u32l;
    // 0x8003D378: lwc1        $f12, 0x12C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8003D37C: jal         0x800C3338
    // 0x8003D380: nop

    MathUtil_Cosf(rdram, ctx);
        goto after_2;
    // 0x8003D380: nop

    after_2:
    // 0x8003D384: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D388: lwc1        $f4, 0x720C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x8003D38C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D390: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003D394: lwc1        $f8, -0x73D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003D398: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003D39C: addiu       $t5, $t5, 0x7158
    ctx->r13 = ADD32(ctx->r13, 0X7158);
    // 0x8003D3A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003D3A4: swc1        $f10, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f10.u32l;
    // 0x8003D3A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D3AC: lwc1        $f16, -0x73EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003D3B0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003D3B4: addiu       $t6, $t6, 0x7158
    ctx->r14 = ADD32(ctx->r14, 0X7158);
    // 0x8003D3B8: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8003D3BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D3C0: lwc1        $f18, -0x73E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x8003D3C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003D3C8: addiu       $t7, $t7, 0x7158
    ctx->r15 = ADD32(ctx->r15, 0X7158);
    // 0x8003D3CC: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x8003D3D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D3D4: lwc1        $f4, -0x73D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003D3D8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003D3DC: addiu       $t8, $t8, 0x7158
    ctx->r24 = ADD32(ctx->r24, 0X7158);
    // 0x8003D3E0: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x8003D3E4: jal         0x800C1680
    // 0x8003D3E8: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_3;
    // 0x8003D3E8: nop

    after_3:
    // 0x8003D3EC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003D3F0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8003D3F4: addiu       $a1, $a1, 0x7158
    ctx->r5 = ADD32(ctx->r5, 0X7158);
    // 0x8003D3F8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8003D3FC: jal         0x800B1250
    // 0x8003D400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_4;
    // 0x8003D400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8003D404: jal         0x800C1A84
    // 0x8003D408: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_5;
    // 0x8003D408: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x8003D40C: jal         0x800AD680
    // 0x8003D410: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800AD680(rdram, ctx);
        goto after_6;
    // 0x8003D410: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x8003D414: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8003D418: lw          $t9, -0x73B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73B8);
    // 0x8003D41C: nop

    // 0x8003D420: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8003D424: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8003D428: lw          $t0, -0x73B4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73B4);
    // 0x8003D42C: nop

    // 0x8003D430: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003D434: jal         0x800C1850
    // 0x8003D438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_7;
    // 0x8003D438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8003D43C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D440: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x8003D444: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x8003D448: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003D44C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003D450: jal         0x800C2304
    // 0x8003D454: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_8;
    // 0x8003D454: nop

    after_8:
    // 0x8003D458: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8003D45C: jal         0x800997D8
    // 0x8003D460: nop

    func_800997D8(rdram, ctx);
        goto after_9;
    // 0x8003D460: nop

    after_9:
    // 0x8003D464: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8003D468: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003D46C: jal         0x800B26E0
    // 0x8003D470: nop

    func_800B26E0(rdram, ctx);
        goto after_10;
    // 0x8003D470: nop

    after_10:
    // 0x8003D474: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8003D478: jal         0x80033C60
    // 0x8003D47C: nop

    func_80033C60(rdram, ctx);
        goto after_11;
    // 0x8003D47C: nop

    after_11:
    // 0x8003D480: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8003D484: lhu         $t1, -0x7396($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X7396);
    // 0x8003D488: nop

    // 0x8003D48C: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x8003D490: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8003D494: lw          $t2, -0x73A0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73A0);
    // 0x8003D498: nop

    // 0x8003D49C: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8003D4A0: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
    // 0x8003D4A4: jal         0x800C1850
    // 0x8003D4A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_12;
    // 0x8003D4A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x8003D4AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D4B0: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003D4B4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003D4B8: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x8003D4BC: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x8003D4C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003D4C4: jal         0x800C2304
    // 0x8003D4C8: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_13;
    // 0x8003D4C8: nop

    after_13:
    // 0x8003D4CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D4D0: lwc1        $f12, 0xE60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x8003D4D4: jal         0x800C25B8
    // 0x8003D4D8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_14;
    // 0x8003D4D8: nop

    after_14:
    // 0x8003D4DC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8003D4E0: lw          $t3, 0x258C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X258C);
    // 0x8003D4E4: nop

    // 0x8003D4E8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8003D4EC: bgez        $t3, L_8003D508
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8003D4F0: cvt.d.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
            goto L_8003D508;
    }
    // 0x8003D4F0: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8003D4F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003D4F8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003D4FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003D500: nop

    // 0x8003D504: add.d       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f8.d + ctx->f10.d;
L_8003D508:
    // 0x8003D508: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D50C: lwc1        $f17, -0x1400($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1400);
    // 0x8003D510: lwc1        $f16, -0x13FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X13FC);
    // 0x8003D514: nop

    // 0x8003D518: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8003D51C: jal         0x800C3070
    // 0x8003D520: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_15;
    // 0x8003D520: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_15:
    // 0x8003D524: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003D528: lw          $t4, 0x258C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X258C);
    // 0x8003D52C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8003D530: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8003D534: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003D538: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8003D53C: bgez        $t5, L_8003D558
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003D540: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_8003D558;
    }
    // 0x8003D540: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8003D544: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003D548: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003D54C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003D550: nop

    // 0x8003D554: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
L_8003D558:
    // 0x8003D558: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D55C: lwc1        $f9, -0x13F8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X13F8);
    // 0x8003D560: lwc1        $f8, -0x13F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X13F4);
    // 0x8003D564: nop

    // 0x8003D568: mul.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D56C: jal         0x800C3338
    // 0x8003D570: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_16;
    // 0x8003D570: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_16:
    // 0x8003D574: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D578: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D57C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003D580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003D584: mul.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8003D588: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003D58C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003D590: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003D594: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8003D598: mul.s       $f14, $f20, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8003D59C: jal         0x800C2304
    // 0x8003D5A0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_17;
    // 0x8003D5A0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_17:
    // 0x8003D5A4: lh          $t6, 0x134($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X134);
    // 0x8003D5A8: sh          $zero, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = 0;
    // 0x8003D5AC: blez        $t6, L_8003D5F4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003D5B0: nop
    
            goto L_8003D5F4;
    }
    // 0x8003D5B0: nop

L_8003D5B4:
    // 0x8003D5B4: lhu         $t7, 0x13C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X13C);
    // 0x8003D5B8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8003D5BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003D5C0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8003D5C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8003D5C8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8003D5CC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8003D5D0: jal         0x800997D8
    // 0x8003D5D4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    func_800997D8(rdram, ctx);
        goto after_18;
    // 0x8003D5D4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_18:
    // 0x8003D5D8: lhu         $t0, 0x13C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X13C);
    // 0x8003D5DC: lh          $t3, 0x134($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X134);
    // 0x8003D5E0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8003D5E4: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8003D5E8: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003D5EC: bne         $at, $zero, L_8003D5B4
    if (ctx->r1 != 0) {
        // 0x8003D5F0: sh          $t1, 0x13C($sp)
        MEM_H(0X13C, ctx->r29) = ctx->r9;
            goto L_8003D5B4;
    }
    // 0x8003D5F0: sh          $t1, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r9;
L_8003D5F4:
    // 0x8003D5F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D5F8: lwc1        $f8, -0x3A80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x8003D5FC: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8003D600: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003D604: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8003D608: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8003D60C: nop

    // 0x8003D610: bc1f        L_8003D720
    if (!c1cs) {
        // 0x8003D614: nop
    
            goto L_8003D720;
    }
    // 0x8003D614: nop

    // 0x8003D618: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D61C: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x8003D620: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D624: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8003D628: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003D62C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D630: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x8003D634: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D638: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8003D63C: swc1        $f16, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f16.u32l;
    // 0x8003D640: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D644: lwc1        $f5, -0x13F0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X13F0);
    // 0x8003D648: lwc1        $f4, -0x13EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X13EC);
    // 0x8003D64C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003D650: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8003D654: nop

    // 0x8003D658: bc1f        L_8003D688
    if (!c1cs) {
        // 0x8003D65C: nop
    
            goto L_8003D688;
    }
    // 0x8003D65C: nop

    // 0x8003D660: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D664: lwc1        $f10, 0xE60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x8003D668: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D66C: lwc1        $f9, -0x13E8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X13E8);
    // 0x8003D670: lwc1        $f8, -0x13E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X13E4);
    // 0x8003D674: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D678: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x8003D67C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D680: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003D684: swc1        $f18, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f18.u32l;
L_8003D688:
    // 0x8003D688: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D68C: lwc1        $f4, -0x3A80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x8003D690: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D694: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8003D698: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003D69C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D6A0: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x8003D6A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003D6A8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8003D6AC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8003D6B0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003D6B4: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8003D6B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D6BC: bc1f        L_8003D6D0
    if (!c1cs) {
        // 0x8003D6C0: swc1        $f16, -0x3A80($at)
        MEM_W(-0X3A80, ctx->r1) = ctx->f16.u32l;
            goto L_8003D6D0;
    }
    // 0x8003D6C0: swc1        $f16, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f16.u32l;
    // 0x8003D6C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003D6C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D6CC: swc1        $f10, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f10.u32l;
L_8003D6D0:
    // 0x8003D6D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D6D4: lwc1        $f6, -0x3A80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x8003D6D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D6DC: lwc1        $f17, -0x13E0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X13E0);
    // 0x8003D6E0: lwc1        $f16, -0x13DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X13DC);
    // 0x8003D6E4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003D6E8: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x8003D6EC: nop

    // 0x8003D6F0: bc1f        L_8003D720
    if (!c1cs) {
        // 0x8003D6F4: nop
    
            goto L_8003D720;
    }
    // 0x8003D6F4: nop

    // 0x8003D6F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D6FC: lwc1        $f18, -0x3A80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x8003D700: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D704: lwc1        $f11, -0x13D8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X13D8);
    // 0x8003D708: lwc1        $f10, -0x13D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X13D4);
    // 0x8003D70C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003D710: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x8003D714: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D718: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8003D71C: swc1        $f8, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f8.u32l;
L_8003D720:
    // 0x8003D720: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D724: lwc1        $f16, -0x3A7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x8003D728: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8003D72C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003D730: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003D734: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8003D738: nop

    // 0x8003D73C: bc1f        L_8003D840
    if (!c1cs) {
        // 0x8003D740: nop
    
            goto L_8003D840;
    }
    // 0x8003D740: nop

    // 0x8003D744: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D748: lwc1        $f10, 0xE60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x8003D74C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D750: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003D754: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D758: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D75C: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x8003D760: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003D764: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003D768: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8003D76C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003D770: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8003D774: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D778: bc1f        L_8003D7A8
    if (!c1cs) {
        // 0x8003D77C: swc1        $f18, 0xE60($at)
        MEM_W(0XE60, ctx->r1) = ctx->f18.u32l;
            goto L_8003D7A8;
    }
    // 0x8003D77C: swc1        $f18, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f18.u32l;
    // 0x8003D780: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D784: lwc1        $f6, 0xE60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x8003D788: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D78C: lwc1        $f17, -0x13D0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X13D0);
    // 0x8003D790: lwc1        $f16, -0x13CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X13CC);
    // 0x8003D794: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003D798: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x8003D79C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D7A0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003D7A4: swc1        $f4, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f4.u32l;
L_8003D7A8:
    // 0x8003D7A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D7AC: lwc1        $f10, -0x3A7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x8003D7B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D7B4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003D7B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D7BC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D7C0: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x8003D7C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003D7C8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003D7CC: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8003D7D0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003D7D4: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8003D7D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D7DC: bc1f        L_8003D7F0
    if (!c1cs) {
        // 0x8003D7E0: swc1        $f18, -0x3A7C($at)
        MEM_W(-0X3A7C, ctx->r1) = ctx->f18.u32l;
            goto L_8003D7F0;
    }
    // 0x8003D7E0: swc1        $f18, -0x3A7C($at)
    MEM_W(-0X3A7C, ctx->r1) = ctx->f18.u32l;
    // 0x8003D7E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003D7E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D7EC: swc1        $f6, -0x3A7C($at)
    MEM_W(-0X3A7C, ctx->r1) = ctx->f6.u32l;
L_8003D7F0:
    // 0x8003D7F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D7F4: lwc1        $f8, -0x3A7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x8003D7F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D7FC: lwc1        $f19, -0x13C8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X13C8);
    // 0x8003D800: lwc1        $f18, -0x13C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X13C4);
    // 0x8003D804: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8003D808: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8003D80C: nop

    // 0x8003D810: bc1f        L_8003D840
    if (!c1cs) {
        // 0x8003D814: nop
    
            goto L_8003D840;
    }
    // 0x8003D814: nop

    // 0x8003D818: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D81C: lwc1        $f4, -0x3A7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x8003D820: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D824: lwc1        $f7, -0x13C0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X13C0);
    // 0x8003D828: lwc1        $f6, -0x13BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X13BC);
    // 0x8003D82C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D830: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x8003D834: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D838: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8003D83C: swc1        $f16, -0x3A7C($at)
    MEM_W(-0X3A7C, ctx->r1) = ctx->f16.u32l;
L_8003D840:
    // 0x8003D840: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D844: lwc1        $f18, -0x3A80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x8003D848: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D84C: lwc1        $f4, -0x3A7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x8003D850: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003D854: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003D858: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D85C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D860: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8003D864: nop

    // 0x8003D868: bc1f        L_8003D938
    if (!c1cs) {
        // 0x8003D86C: nop
    
            goto L_8003D938;
    }
    // 0x8003D86C: nop

    // 0x8003D870: jal         0x800C4240
    // 0x8003D874: nop

    guRandom(rdram, ctx);
        goto after_19;
    // 0x8003D874: nop

    after_19:
    // 0x8003D878: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x8003D87C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8003D880: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8003D884: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003D888: mfhi        $t4
    ctx->r12 = hi;
    // 0x8003D88C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8003D890: nop

    // 0x8003D894: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8003D898: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x8003D89C: nop

    // 0x8003D8A0: bc1f        L_8003D938
    if (!c1cs) {
        // 0x8003D8A4: nop
    
            goto L_8003D938;
    }
    // 0x8003D8A4: nop

    // 0x8003D8A8: jal         0x800C4240
    // 0x8003D8AC: nop

    guRandom(rdram, ctx);
        goto after_20;
    // 0x8003D8AC: nop

    after_20:
    // 0x8003D8B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003D8B4: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8003D8B8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003D8BC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003D8C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D8C4: mfhi        $t5
    ctx->r13 = hi;
    // 0x8003D8C8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8003D8CC: nop

    // 0x8003D8D0: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x8003D8D4: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8003D8D8: nop

    // 0x8003D8DC: bc1f        L_8003D910
    if (!c1cs) {
        // 0x8003D8E0: nop
    
            goto L_8003D910;
    }
    // 0x8003D8E0: nop

    // 0x8003D8E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D8E8: lwc1        $f16, -0x3A80($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x8003D8EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D8F0: lwc1        $f5, -0x13B8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X13B8);
    // 0x8003D8F4: lwc1        $f4, -0x13B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X13B4);
    // 0x8003D8F8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003D8FC: add.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f18.d + ctx->f4.d;
    // 0x8003D900: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D904: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8003D908: b           L_8003D938
    // 0x8003D90C: swc1        $f6, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f6.u32l;
        goto L_8003D938;
    // 0x8003D90C: swc1        $f6, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f6.u32l;
L_8003D910:
    // 0x8003D910: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D914: lwc1        $f8, -0x3A7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x8003D918: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D91C: lwc1        $f19, -0x13B0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X13B0);
    // 0x8003D920: lwc1        $f18, -0x13AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X13AC);
    // 0x8003D924: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8003D928: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8003D92C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D930: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003D934: swc1        $f10, -0x3A7C($at)
    MEM_W(-0X3A7C, ctx->r1) = ctx->f10.u32l;
L_8003D938:
    // 0x8003D938: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8003D93C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003D940: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8003D944: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003D948: jal         0x800AF184
    // 0x8003D94C: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    func_800AF184(rdram, ctx);
        goto after_21;
    // 0x8003D94C: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    after_21:
    // 0x8003D950: jal         0x800C1AF4
    // 0x8003D954: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_22;
    // 0x8003D954: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_22:
    // 0x8003D958: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003D95C: lw          $t6, 0x71FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71FC);
    // 0x8003D960: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003D964: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8003D968: lwc1        $f6, -0x73D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003D96C: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x8003D970: lw          $a3, -0x73EC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X73EC);
    // 0x8003D974: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8003D978: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8003D97C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8003D980: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8003D984: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x8003D988: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x8003D98C: jal         0x800349C0
    // 0x8003D990: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800349C0(rdram, ctx);
        goto after_23;
    // 0x8003D990: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_23:
    // 0x8003D994: jal         0x800C1850
    // 0x8003D998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_24;
    // 0x8003D998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x8003D99C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D9A0: lwc1        $f12, 0x7324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003D9A4: jal         0x800C25B8
    // 0x8003D9A8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_25;
    // 0x8003D9A8: nop

    after_25:
    // 0x8003D9AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003D9B0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003D9B4: jal         0x800C2304
    // 0x8003D9B8: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_26;
    // 0x8003D9B8: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_26:
    // 0x8003D9BC: jal         0x800C1A84
    // 0x8003D9C0: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_27;
    // 0x8003D9C0: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    after_27:
    // 0x8003D9C4: addiu       $t9, $sp, 0x98
    ctx->r25 = ADD32(ctx->r29, 0X98);
    // 0x8003D9C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D9CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003D9D0: lwc1        $f8, 0x30($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X30);
    // 0x8003D9D4: nop

    // 0x8003D9D8: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8003D9DC: swc1        $f18, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f18.u32l;
    // 0x8003D9E0: addiu       $t0, $sp, 0x98
    ctx->r8 = ADD32(ctx->r29, 0X98);
    // 0x8003D9E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D9E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003D9EC: lwc1        $f4, 0x38($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X38);
    // 0x8003D9F0: nop

    // 0x8003D9F4: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8003D9F8: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    // 0x8003D9FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003DA00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003DA04: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8003DA08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003DA0C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8003DA10: lwc1        $f4, -0x73EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003DA14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003DA18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003DA1C: lwc1        $f6, 0x118($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8003DA20: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003DA24: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003DA28: lw          $t1, 0x71FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X71FC);
    // 0x8003DA2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003DA30: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x8003DA34: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003DA38: lwc1        $f18, -0x73D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003DA3C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8003DA40: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003DA44: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8003DA48: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x8003DA4C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8003DA50: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8003DA54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003DA58: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8003DA5C: jal         0x800346E4
    // 0x8003DA60: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800346E4(rdram, ctx);
        goto after_28;
    // 0x8003DA60: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_28:
    // 0x8003DA64: sh          $v0, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r2;
    // 0x8003DA68: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003DA6C: lh          $t4, 0x6C0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C0);
    // 0x8003DA70: nop

    // 0x8003DA74: beq         $t4, $zero, L_8003DA9C
    if (ctx->r12 == 0) {
        // 0x8003DA78: nop
    
            goto L_8003DA9C;
    }
    // 0x8003DA78: nop

    // 0x8003DA7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DA80: lwc1        $f10, 0x720C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x8003DA84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003DA88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003DA8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DA90: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8003DA94: b           L_8003DC1C
    // 0x8003DA98: swc1        $f8, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f8.u32l;
        goto L_8003DC1C;
    // 0x8003DA98: swc1        $f8, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f8.u32l;
L_8003DA9C:
    // 0x8003DA9C: lhu         $t5, 0x136($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X136);
    // 0x8003DAA0: nop

    // 0x8003DAA4: beq         $t5, $zero, L_8003DC1C
    if (ctx->r13 == 0) {
        // 0x8003DAA8: nop
    
            goto L_8003DC1C;
    }
    // 0x8003DAA8: nop

    // 0x8003DAAC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8003DAB0: beq         $t5, $at, L_8003DC1C
    if (ctx->r13 == ctx->r1) {
        // 0x8003DAB4: nop
    
            goto L_8003DC1C;
    }
    // 0x8003DAB4: nop

    // 0x8003DAB8: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8003DABC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003DAC0: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
    // 0x8003DAC4: lhu         $t7, 0x136($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X136);
    // 0x8003DAC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DACC: bne         $t7, $at, L_8003DB20
    if (ctx->r15 != ctx->r1) {
        // 0x8003DAD0: nop
    
            goto L_8003DB20;
    }
    // 0x8003DAD0: nop

    // 0x8003DAD4: addiu       $t8, $zero, -0x7FFD
    ctx->r24 = ADD32(0, -0X7FFD);
    // 0x8003DAD8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DADC: sh          $t8, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r24;
    // 0x8003DAE0: addiu       $t9, $zero, 0x49
    ctx->r25 = ADD32(0, 0X49);
    // 0x8003DAE4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DAE8: sh          $t9, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r25;
    // 0x8003DAEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003DAF0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003DAF4: sh          $t0, -0x498($at)
    MEM_H(-0X498, ctx->r1) = ctx->r8;
    // 0x8003DAF8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003DAFC: lh          $t1, 0x6C0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X6C0);
    // 0x8003DB00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003DB04: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8003DB08: sh          $t2, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r10;
    // 0x8003DB0C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003DB10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003DB14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DB18: b           L_8003DC1C
    // 0x8003DB1C: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
        goto L_8003DC1C;
    // 0x8003DB1C: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
L_8003DB20:
    // 0x8003DB20: lhu         $t3, 0x136($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X136);
    // 0x8003DB24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003DB28: bne         $t3, $at, L_8003DB78
    if (ctx->r11 != ctx->r1) {
        // 0x8003DB2C: nop
    
            goto L_8003DB78;
    }
    // 0x8003DB2C: nop

    // 0x8003DB30: addiu       $t4, $zero, -0x7FFD
    ctx->r12 = ADD32(0, -0X7FFD);
    // 0x8003DB34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DB38: sh          $t4, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r12;
    // 0x8003DB3C: addiu       $t5, $zero, 0x49
    ctx->r13 = ADD32(0, 0X49);
    // 0x8003DB40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DB44: sh          $t5, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r13;
    // 0x8003DB48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003DB4C: sh          $zero, -0x498($at)
    MEM_H(-0X498, ctx->r1) = 0;
    // 0x8003DB50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003DB54: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x8003DB58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003DB5C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003DB60: sh          $t7, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r15;
    // 0x8003DB64: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003DB68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003DB6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DB70: b           L_8003DC1C
    // 0x8003DB74: swc1        $f18, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f18.u32l;
        goto L_8003DC1C;
    // 0x8003DB74: swc1        $f18, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f18.u32l;
L_8003DB78:
    // 0x8003DB78: lhu         $t8, 0x136($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X136);
    // 0x8003DB7C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003DB80: lw          $t0, 0x7214($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7214);
    // 0x8003DB84: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003DB88: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8003DB8C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8003DB90: addiu       $t2, $t1, -0x9
    ctx->r10 = ADD32(ctx->r9, -0X9);
    // 0x8003DB94: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x8003DB98: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8003DB9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DBA0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8003DBA4: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x8003DBA8: ori         $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 | 0X8000;
    // 0x8003DBAC: sh          $t5, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r13;
    // 0x8003DBB0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8003DBB4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8003DBB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DBBC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8003DBC0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8003DBC4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8003DBC8: sh          $t8, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r24;
    // 0x8003DBCC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8003DBD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DBD4: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8003DBD8: nop

    // 0x8003DBDC: sh          $t1, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r9;
    // 0x8003DBE0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8003DBE4: lh          $t2, 0x6C0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X6C0);
    // 0x8003DBE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003DBEC: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8003DBF0: sh          $t4, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r12;
    // 0x8003DBF4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003DBF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003DBFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DC00: swc1        $f4, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f4.u32l;
    // 0x8003DC04: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003DC08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003DC0C: sb          $t5, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r13;
    // 0x8003DC10: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8003DC14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003DC18: sw          $t3, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r11;
L_8003DC1C:
    // 0x8003DC1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DC20: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003DC24: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003DC28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003DC2C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003DC30: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8003DC34: nop

    // 0x8003DC38: bc1t        L_8003DDA0
    if (c1cs) {
        // 0x8003DC3C: nop
    
            goto L_8003DDA0;
    }
    // 0x8003DC3C: nop

    // 0x8003DC40: lhu         $t6, 0x136($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X136);
    // 0x8003DC44: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8003DC48: bne         $t6, $at, L_8003DCA0
    if (ctx->r14 != ctx->r1) {
        // 0x8003DC4C: nop
    
            goto L_8003DCA0;
    }
    // 0x8003DC4C: nop

    // 0x8003DC50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003DC54: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003DC58: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8003DC5C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8003DC60: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x8003DC64: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x8003DC68: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8003DC6C: lhu         $a3, 0x13A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X13A);
    // 0x8003DC70: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x8003DC74: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003DC78: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8003DC7C: jal         0x800B1F0C
    // 0x8003DC80: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_29;
    // 0x8003DC80: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_29:
    // 0x8003DC84: addiu       $t8, $zero, 0x27
    ctx->r24 = ADD32(0, 0X27);
    // 0x8003DC88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DC8C: sh          $t8, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r24;
    // 0x8003DC90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003DC94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DC98: b           L_8003DCF4
    // 0x8003DC9C: swc1        $f4, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f4.u32l;
        goto L_8003DCF4;
    // 0x8003DC9C: swc1        $f4, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f4.u32l;
L_8003DCA0:
    // 0x8003DCA0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003DCA4: lhu         $t7, 0x70E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X70E0);
    // 0x8003DCA8: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8003DCAC: beq         $t7, $at, L_8003DCF4
    if (ctx->r15 == ctx->r1) {
        // 0x8003DCB0: nop
    
            goto L_8003DCF4;
    }
    // 0x8003DCB0: nop

    // 0x8003DCB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003DCB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003DCBC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8003DCC0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8003DCC4: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x8003DCC8: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x8003DCCC: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8003DCD0: lhu         $a3, 0x13A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X13A);
    // 0x8003DCD4: ori         $a2, $a2, 0x90
    ctx->r6 = ctx->r6 | 0X90;
    // 0x8003DCD8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003DCDC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8003DCE0: jal         0x800B1F0C
    // 0x8003DCE4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_30;
    // 0x8003DCE4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_30:
    // 0x8003DCE8: addiu       $t9, $zero, 0x90
    ctx->r25 = ADD32(0, 0X90);
    // 0x8003DCEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DCF0: sh          $t9, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r25;
L_8003DCF4:
    // 0x8003DCF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DCF8: lwc1        $f8, 0x50C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003DCFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003DD00: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003DD04: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003DD08: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8003DD0C: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8003DD10: nop

    // 0x8003DD14: bc1f        L_8003DD3C
    if (!c1cs) {
        // 0x8003DD18: nop
    
            goto L_8003DD3C;
    }
    // 0x8003DD18: nop

    // 0x8003DD1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DD20: lwc1        $f4, 0x50C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003DD24: nop

    // 0x8003DD28: swc1        $f4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f4.u32l;
    // 0x8003DD2C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003DD30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DD34: b           L_8003DD58
    // 0x8003DD38: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
        goto L_8003DD58;
    // 0x8003DD38: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
L_8003DD3C:
    // 0x8003DD3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003DD40: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003DD44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DD48: lwc1        $f6, 0x50C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003DD4C: swc1        $f20, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f20.u32l;
    // 0x8003DD50: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x8003DD54: swc1        $f8, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f8.u32l;
L_8003DD58:
    // 0x8003DD58: addiu       $t0, $sp, 0x98
    ctx->r8 = ADD32(ctx->r29, 0X98);
    // 0x8003DD5C: lwc1        $f18, 0x30($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8003DD60: lwc1        $f16, 0x120($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003DD64: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003DD68: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003DD6C: lwc1        $f10, -0x73EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003DD70: nop

    // 0x8003DD74: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8003DD78: swc1        $f6, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f6.u32l;
    // 0x8003DD7C: addiu       $t1, $sp, 0x98
    ctx->r9 = ADD32(ctx->r29, 0X98);
    // 0x8003DD80: lwc1        $f16, 0x38($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X38);
    // 0x8003DD84: lwc1        $f8, 0x120($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003DD88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003DD8C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8003DD90: lwc1        $f10, -0x73D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003DD94: nop

    // 0x8003DD98: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003DD9C: swc1        $f4, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f4.u32l;
L_8003DDA0:
    // 0x8003DDA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DDA4: lwc1        $f6, 0x50D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003DDA8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8003DDAC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003DDB0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003DDB4: c.eq.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d == ctx->f16.d;
    // 0x8003DDB8: nop

    // 0x8003DDBC: bc1t        L_8003DEF4
    if (c1cs) {
        // 0x8003DDC0: nop
    
            goto L_8003DEF4;
    }
    // 0x8003DDC0: nop

    // 0x8003DDC4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003DDC8: lhu         $t2, 0x70E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X70E0);
    // 0x8003DDCC: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x8003DDD0: beq         $t2, $at, L_8003DE18
    if (ctx->r10 == ctx->r1) {
        // 0x8003DDD4: nop
    
            goto L_8003DE18;
    }
    // 0x8003DDD4: nop

    // 0x8003DDD8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003DDDC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003DDE0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8003DDE4: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8003DDE8: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x8003DDEC: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x8003DDF0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8003DDF4: lhu         $a3, 0x13A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X13A);
    // 0x8003DDF8: ori         $a2, $a2, 0x59
    ctx->r6 = ctx->r6 | 0X59;
    // 0x8003DDFC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003DE00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8003DE04: jal         0x800B1F0C
    // 0x8003DE08: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_31;
    // 0x8003DE08: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_31:
    // 0x8003DE0C: addiu       $t4, $zero, 0x59
    ctx->r12 = ADD32(0, 0X59);
    // 0x8003DE10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DE14: sh          $t4, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r12;
L_8003DE18:
    // 0x8003DE18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003DE1C: nop

    // 0x8003DE20: swc1        $f4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f4.u32l;
    // 0x8003DE24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DE28: lwc1        $f6, 0x50D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003DE2C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8003DE30: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003DE34: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003DE38: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003DE3C: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x8003DE40: nop

    // 0x8003DE44: bc1f        L_8003DE6C
    if (!c1cs) {
        // 0x8003DE48: nop
    
            goto L_8003DE6C;
    }
    // 0x8003DE48: nop

    // 0x8003DE4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DE50: lwc1        $f10, 0x50D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003DE54: nop

    // 0x8003DE58: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x8003DE5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003DE60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DE64: b           L_8003DEA4
    // 0x8003DE68: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
        goto L_8003DEA4;
    // 0x8003DE68: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
L_8003DE6C:
    // 0x8003DE6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DE70: lwc1        $f4, 0x50D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003DE74: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8003DE78: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003DE7C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003DE80: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003DE84: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x8003DE88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DE8C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8003DE90: swc1        $f10, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f10.u32l;
    // 0x8003DE94: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003DE98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003DE9C: nop

    // 0x8003DEA0: swc1        $f18, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f18.u32l;
L_8003DEA4:
    // 0x8003DEA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DEA8: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003DEAC: lwc1        $f6, 0x120($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003DEB0: nop

    // 0x8003DEB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003DEB8: swc1        $f8, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f8.u32l;
    // 0x8003DEBC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003DEC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003DEC4: nop

    // 0x8003DEC8: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x8003DECC: nop

    // 0x8003DED0: bc1f        L_8003DEF4
    if (!c1cs) {
        // 0x8003DED4: nop
    
            goto L_8003DEF4;
    }
    // 0x8003DED4: nop

    // 0x8003DED8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DEDC: lwc1        $f10, 0x7324($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003DEE0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003DEE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003DEE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DEEC: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003DEF0: swc1        $f4, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f4.u32l;
L_8003DEF4:
    // 0x8003DEF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DEF8: lwc1        $f6, 0x50D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003DEFC: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8003DF00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003DF04: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003DF08: c.eq.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d == ctx->f16.d;
    // 0x8003DF0C: nop

    // 0x8003DF10: bc1t        L_8003E03C
    if (c1cs) {
        // 0x8003DF14: nop
    
            goto L_8003E03C;
    }
    // 0x8003DF14: nop

    // 0x8003DF18: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003DF1C: lhu         $t5, 0x70E0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X70E0);
    // 0x8003DF20: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x8003DF24: beq         $t5, $at, L_8003DF70
    if (ctx->r13 == ctx->r1) {
        // 0x8003DF28: nop
    
            goto L_8003DF70;
    }
    // 0x8003DF28: nop

    // 0x8003DF2C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003DF30: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003DF34: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8003DF38: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8003DF3C: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x8003DF40: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x8003DF44: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8003DF48: lhu         $a3, 0x13A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X13A);
    // 0x8003DF4C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003DF50: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8003DF54: ori         $a2, $a2, 0x59
    ctx->r6 = ctx->r6 | 0X59;
    // 0x8003DF58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8003DF5C: jal         0x800B1F0C
    // 0x8003DF60: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_32;
    // 0x8003DF60: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_32:
    // 0x8003DF64: addiu       $t6, $zero, 0x59
    ctx->r14 = ADD32(0, 0X59);
    // 0x8003DF68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DF6C: sh          $t6, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r14;
L_8003DF70:
    // 0x8003DF70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003DF74: nop

    // 0x8003DF78: swc1        $f4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f4.u32l;
    // 0x8003DF7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DF80: lwc1        $f6, 0x50D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003DF84: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8003DF88: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003DF8C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003DF90: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003DF94: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x8003DF98: nop

    // 0x8003DF9C: bc1f        L_8003DFC4
    if (!c1cs) {
        // 0x8003DFA0: nop
    
            goto L_8003DFC4;
    }
    // 0x8003DFA0: nop

    // 0x8003DFA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DFA8: lwc1        $f10, 0x50D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003DFAC: nop

    // 0x8003DFB0: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x8003DFB4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003DFB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DFBC: b           L_8003DFFC
    // 0x8003DFC0: swc1        $f18, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f18.u32l;
        goto L_8003DFFC;
    // 0x8003DFC0: swc1        $f18, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f18.u32l;
L_8003DFC4:
    // 0x8003DFC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DFC8: lwc1        $f4, 0x50D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003DFCC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8003DFD0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003DFD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003DFD8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003DFDC: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x8003DFE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003DFE4: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8003DFE8: swc1        $f10, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f10.u32l;
    // 0x8003DFEC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003DFF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003DFF4: nop

    // 0x8003DFF8: swc1        $f18, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f18.u32l;
L_8003DFFC:
    // 0x8003DFFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E000: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003E004: lwc1        $f6, 0x120($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E008: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003E00C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003E010: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x8003E014: swc1        $f8, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f8.u32l;
    // 0x8003E018: bc1f        L_8003E03C
    if (!c1cs) {
        // 0x8003E01C: nop
    
            goto L_8003E03C;
    }
    // 0x8003E01C: nop

    // 0x8003E020: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E024: lwc1        $f10, 0x7324($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003E028: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003E02C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003E030: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E034: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003E038: swc1        $f4, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f4.u32l;
L_8003E03C:
    // 0x8003E03C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E040: lwc1        $f6, 0x50D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003E044: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E048: lwc1        $f8, 0x50D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003E04C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E050: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003E054: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003E058: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8003E05C: swc1        $f18, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f18.u32l;
    // 0x8003E060: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E064: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003E068: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003E06C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003E070: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8003E074: nop

    // 0x8003E078: bc1f        L_8003E140
    if (!c1cs) {
        // 0x8003E07C: nop
    
            goto L_8003E140;
    }
    // 0x8003E07C: nop

    // 0x8003E080: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003E084: lhu         $t8, 0x70E0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X70E0);
    // 0x8003E088: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x8003E08C: beq         $t8, $at, L_8003E140
    if (ctx->r24 == ctx->r1) {
        // 0x8003E090: nop
    
            goto L_8003E140;
    }
    // 0x8003E090: nop

    // 0x8003E094: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003E098: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E09C: lwc1        $f16, 0x124($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8003E0A0: nop

    // 0x8003E0A4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8003E0A8: nop

    // 0x8003E0AC: bc1f        L_8003E140
    if (!c1cs) {
        // 0x8003E0B0: nop
    
            goto L_8003E140;
    }
    // 0x8003E0B0: nop

    // 0x8003E0B4: lwc1        $f18, 0x128($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8003E0B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003E0BC: nop

    // 0x8003E0C0: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8003E0C4: nop

    // 0x8003E0C8: bc1f        L_8003E0D8
    if (!c1cs) {
        // 0x8003E0CC: nop
    
            goto L_8003E0D8;
    }
    // 0x8003E0CC: nop

    // 0x8003E0D0: b           L_8003E0E4
    // 0x8003E0D4: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
        goto L_8003E0E4;
    // 0x8003E0D4: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_8003E0D8:
    // 0x8003E0D8: lwc1        $f20, 0x128($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8003E0DC: nop

    // 0x8003E0E0: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8003E0E4:
    // 0x8003E0E4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003E0E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003E0EC: nop

    // 0x8003E0F0: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x8003E0F4: nop

    // 0x8003E0F8: bc1f        L_8003E140
    if (!c1cs) {
        // 0x8003E0FC: nop
    
            goto L_8003E140;
    }
    // 0x8003E0FC: nop

    // 0x8003E100: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003E104: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003E108: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8003E10C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8003E110: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x8003E114: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x8003E118: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8003E11C: lhu         $a3, 0x13A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X13A);
    // 0x8003E120: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x8003E124: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003E128: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8003E12C: jal         0x800B1F0C
    // 0x8003E130: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_33;
    // 0x8003E130: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_33:
    // 0x8003E134: addiu       $t7, $zero, 0x27
    ctx->r15 = ADD32(0, 0X27);
    // 0x8003E138: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E13C: sh          $t7, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r15;
L_8003E140:
    // 0x8003E140: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E144: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8003E148: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003E14C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8003E150: c.eq.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d == ctx->f18.d;
    // 0x8003E154: nop

    // 0x8003E158: bc1f        L_8003E1B0
    if (!c1cs) {
        // 0x8003E15C: nop
    
            goto L_8003E1B0;
    }
    // 0x8003E15C: nop

    // 0x8003E160: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8003E164: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8003E168: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003E16C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003E170: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003E174: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x8003E178: nop

    // 0x8003E17C: bc1f        L_8003E1B0
    if (!c1cs) {
        // 0x8003E180: nop
    
            goto L_8003E1B0;
    }
    // 0x8003E180: nop

    // 0x8003E184: lhu         $t9, 0x136($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X136);
    // 0x8003E188: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8003E18C: beq         $t9, $at, L_8003E1B0
    if (ctx->r25 == ctx->r1) {
        // 0x8003E190: nop
    
            goto L_8003E1B0;
    }
    // 0x8003E190: nop

    // 0x8003E194: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003E198: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003E19C: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E1A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E1A4: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8003E1A8: swc1        $f20, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f20.u32l;
    // 0x8003E1AC: swc1        $f4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f4.u32l;
L_8003E1B0:
    // 0x8003E1B0: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E1B4: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003E1B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003E1BC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8003E1C0: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8003E1C4: nop

    // 0x8003E1C8: bc1f        L_8003E240
    if (!c1cs) {
        // 0x8003E1CC: nop
    
            goto L_8003E240;
    }
    // 0x8003E1CC: nop

    // 0x8003E1D0: lwc1        $f16, 0x124($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8003E1D4: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x8003E1D8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003E1DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003E1E0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003E1E4: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8003E1E8: nop

    // 0x8003E1EC: bc1f        L_8003E240
    if (!c1cs) {
        // 0x8003E1F0: nop
    
            goto L_8003E240;
    }
    // 0x8003E1F0: nop

    // 0x8003E1F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003E1F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003E1FC: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E200: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E204: add.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8003E208: swc1        $f20, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f20.u32l;
    // 0x8003E20C: swc1        $f6, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f6.u32l;
    // 0x8003E210: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8003E214: lh          $t0, 0x664($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X664);
    // 0x8003E218: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8003E21C: beq         $t0, $at, L_8003E240
    if (ctx->r8 == ctx->r1) {
        // 0x8003E220: nop
    
            goto L_8003E240;
    }
    // 0x8003E220: nop

    // 0x8003E224: addiu       $t1, $zero, 0x1A
    ctx->r9 = ADD32(0, 0X1A);
    // 0x8003E228: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003E22C: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x8003E230: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003E234: sh          $t2, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r10;
    // 0x8003E238: jal         0x800B9000
    // 0x8003E23C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_800B9000(rdram, ctx);
        goto after_34;
    // 0x8003E23C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_34:
L_8003E240:
    // 0x8003E240: lwc1        $f8, 0x120($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E244: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8003E248: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003E24C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8003E250: c.eq.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d == ctx->f10.d;
    // 0x8003E254: nop

    // 0x8003E258: bc1f        L_8003E2E0
    if (!c1cs) {
        // 0x8003E25C: nop
    
            goto L_8003E2E0;
    }
    // 0x8003E25C: nop

    // 0x8003E260: lwc1        $f4, 0x128($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8003E264: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8003E268: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8003E26C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003E270: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003E274: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8003E278: nop

    // 0x8003E27C: bc1f        L_8003E2E0
    if (!c1cs) {
        // 0x8003E280: nop
    
            goto L_8003E2E0;
    }
    // 0x8003E280: nop

    // 0x8003E284: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003E288: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8003E28C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E290: swc1        $f22, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f22.u32l;
    // 0x8003E294: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E298: lwc1        $f8, -0x3A80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x8003E29C: lwc1        $f16, 0x120($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E2A0: add.s       $f20, $f8, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8003E2A4: add.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8003E2A8: swc1        $f20, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f20.u32l;
    // 0x8003E2AC: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x8003E2B0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003E2B4: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x8003E2B8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003E2BC: beq         $t4, $at, L_8003E2E0
    if (ctx->r12 == ctx->r1) {
        // 0x8003E2C0: nop
    
            goto L_8003E2E0;
    }
    // 0x8003E2C0: nop

    // 0x8003E2C4: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8003E2C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003E2CC: sh          $t5, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r13;
    // 0x8003E2D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003E2D4: sh          $t3, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r11;
    // 0x8003E2D8: jal         0x800B9000
    // 0x8003E2DC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_800B9000(rdram, ctx);
        goto after_35;
    // 0x8003E2DC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_35:
L_8003E2E0:
    // 0x8003E2E0: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8003E2E4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8003E2E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003E2EC: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003E2F0: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x8003E2F4: nop

    // 0x8003E2F8: bc1f        L_8003E378
    if (!c1cs) {
        // 0x8003E2FC: nop
    
            goto L_8003E378;
    }
    // 0x8003E2FC: nop

    // 0x8003E300: lwc1        $f8, 0x128($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8003E304: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x8003E308: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003E30C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003E310: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8003E314: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x8003E318: nop

    // 0x8003E31C: bc1f        L_8003E378
    if (!c1cs) {
        // 0x8003E320: nop
    
            goto L_8003E378;
    }
    // 0x8003E320: nop

    // 0x8003E324: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003E328: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003E32C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E330: swc1        $f20, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f20.u32l;
    // 0x8003E334: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E338: lwc1        $f4, -0x3A7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x8003E33C: nop

    // 0x8003E340: add.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8003E344: swc1        $f18, -0x3A7C($at)
    MEM_W(-0X3A7C, ctx->r1) = ctx->f18.u32l;
    // 0x8003E348: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003E34C: lh          $t6, 0x664($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X664);
    // 0x8003E350: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003E354: beq         $t6, $at, L_8003E378
    if (ctx->r14 == ctx->r1) {
        // 0x8003E358: nop
    
            goto L_8003E378;
    }
    // 0x8003E358: nop

    // 0x8003E35C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8003E360: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003E364: sh          $t8, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r24;
    // 0x8003E368: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003E36C: sh          $t7, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r15;
    // 0x8003E370: jal         0x800B9000
    // 0x8003E374: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_800B9000(rdram, ctx);
        goto after_36;
    // 0x8003E374: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_36:
L_8003E378:
    // 0x8003E378: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8003E37C: addiu       $t9, $t9, -0x73A0
    ctx->r25 = ADD32(ctx->r25, -0X73A0);
    // 0x8003E380: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8003E384: jal         0x800B2748
    // 0x8003E388: addiu       $a1, $t9, 0x4
    ctx->r5 = ADD32(ctx->r25, 0X4);
    func_800B2748(rdram, ctx);
        goto after_37;
    // 0x8003E388: addiu       $a1, $t9, 0x4
    ctx->r5 = ADD32(ctx->r25, 0X4);
    after_37:
    // 0x8003E38C: sh          $v0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r2;
    // 0x8003E390: lh          $t0, 0x134($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X134);
    // 0x8003E394: nop

    // 0x8003E398: bgez        $t0, L_8003E3B4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8003E39C: nop
    
            goto L_8003E3B4;
    }
    // 0x8003E39C: nop

    // 0x8003E3A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003E3A4: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x8003E3A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003E3AC: b           L_8003E494
    // 0x8003E3B0: sh          $t1, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r9;
        goto L_8003E494;
    // 0x8003E3B0: sh          $t1, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r9;
L_8003E3B4:
    // 0x8003E3B4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8003E3B8: lh          $t2, 0x664($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X664);
    // 0x8003E3BC: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8003E3C0: beq         $t2, $at, L_8003E460
    if (ctx->r10 == ctx->r1) {
        // 0x8003E3C4: nop
    
            goto L_8003E460;
    }
    // 0x8003E3C4: nop

    // 0x8003E3C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E3CC: lwc1        $f6, 0x50C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003E3D0: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8003E3D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003E3D8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003E3DC: c.eq.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d == ctx->f16.d;
    // 0x8003E3E0: nop

    // 0x8003E3E4: bc1t        L_8003E404
    if (c1cs) {
        // 0x8003E3E8: nop
    
            goto L_8003E404;
    }
    // 0x8003E3E8: nop

    // 0x8003E3EC: addiu       $t4, $zero, 0x1B
    ctx->r12 = ADD32(0, 0X1B);
    // 0x8003E3F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003E3F4: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
    // 0x8003E3F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003E3FC: b           L_8003E458
    // 0x8003E400: sh          $t5, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r13;
        goto L_8003E458;
    // 0x8003E400: sh          $t5, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r13;
L_8003E404:
    // 0x8003E404: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E408: lwc1        $f10, 0x50D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003E40C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E410: lwc1        $f4, 0x50D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003E414: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003E418: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8003E41C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003E420: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8003E424: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8003E428: nop

    // 0x8003E42C: bc1f        L_8003E458
    if (!c1cs) {
        // 0x8003E430: nop
    
            goto L_8003E458;
    }
    // 0x8003E430: nop

    // 0x8003E434: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8003E438: lh          $t3, 0x664($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X664);
    // 0x8003E43C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8003E440: bne         $t3, $at, L_8003E458
    if (ctx->r11 != ctx->r1) {
        // 0x8003E444: nop
    
            goto L_8003E458;
    }
    // 0x8003E444: nop

    // 0x8003E448: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003E44C: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x8003E450: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003E454: sh          $t6, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r14;
L_8003E458:
    // 0x8003E458: b           L_8003E494
    // 0x8003E45C: nop

        goto L_8003E494;
    // 0x8003E45C: nop

L_8003E460:
    // 0x8003E460: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E464: lwc1        $f16, 0x50C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003E468: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8003E46C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003E470: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003E474: c.eq.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d == ctx->f4.d;
    // 0x8003E478: nop

    // 0x8003E47C: bc1f        L_8003E494
    if (!c1cs) {
        // 0x8003E480: nop
    
            goto L_8003E494;
    }
    // 0x8003E480: nop

    // 0x8003E484: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003E488: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x8003E48C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003E490: sh          $t8, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r24;
L_8003E494:
    // 0x8003E494: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E498: lwc1        $f18, 0x50C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003E49C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003E4A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003E4A4: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8003E4A8: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8003E4AC: nop

    // 0x8003E4B0: bc1t        L_8003E4E0
    if (c1cs) {
        // 0x8003E4B4: nop
    
            goto L_8003E4E0;
    }
    // 0x8003E4B4: nop

    // 0x8003E4B8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8003E4BC: lh          $t7, 0x664($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X664);
    // 0x8003E4C0: nop

    // 0x8003E4C4: bne         $t7, $zero, L_8003E4E0
    if (ctx->r15 != 0) {
        // 0x8003E4C8: nop
    
            goto L_8003E4E0;
    }
    // 0x8003E4C8: nop

    // 0x8003E4CC: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x8003E4D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003E4D4: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x8003E4D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003E4DC: sh          $t0, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r8;
L_8003E4E0:
    // 0x8003E4E0: lhu         $t1, 0x138($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X138);
    // 0x8003E4E4: nop

    // 0x8003E4E8: beq         $t1, $zero, L_8003E530
    if (ctx->r9 == 0) {
        // 0x8003E4EC: nop
    
            goto L_8003E530;
    }
    // 0x8003E4EC: nop

    // 0x8003E4F0: lhu         $t4, 0x138($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X138);
    // 0x8003E4F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003E4F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003E4FC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8003E500: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8003E504: lh          $a2, 0x664($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X664);
    // 0x8003E508: addiu       $t2, $t2, -0x73A0
    ctx->r10 = ADD32(ctx->r10, -0X73A0);
    // 0x8003E50C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8003E510: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8003E514: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8003E518: addiu       $a1, $t2, 0x4
    ctx->r5 = ADD32(ctx->r10, 0X4);
    // 0x8003E51C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8003E520: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8003E524: jal         0x800B202C
    // 0x8003E528: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B202C(rdram, ctx);
        goto after_38;
    // 0x8003E528: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_38:
    // 0x8003E52C: sh          $v0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r2;
L_8003E530:
    // 0x8003E530: lh          $t3, 0x134($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X134);
    // 0x8003E534: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E538: sh          $t3, -0x7396($at)
    MEM_H(-0X7396, ctx->r1) = ctx->r11;
    // 0x8003E53C: jal         0x800C1A28
    // 0x8003E540: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_39;
    // 0x8003E540: nop

    after_39:
    // 0x8003E544: b           L_8003E54C
    // 0x8003E548: nop

        goto L_8003E54C;
    // 0x8003E548: nop

L_8003E54C:
    // 0x8003E54C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003E550: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003E554: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003E558: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8003E55C: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003E560: jr          $ra
    // 0x8003E564: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x8003E564: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void func_800AF330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF330: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800AF334: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AF338: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800AF33C: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800AF340: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x800AF344: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800AF348: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800AF34C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800AF350: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800AF354: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AF358: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800AF35C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AF360: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800AF364: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AF368: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800AF36C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF370: lw          $t6, -0x4CC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CC4);
    // 0x800AF374: addiu       $t7, $zero, -0x14
    ctx->r15 = ADD32(0, -0X14);
    // 0x800AF378: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800AF37C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AF380: nop

    // 0x800AF384: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AF388: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x800AF38C: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x800AF390: nop

    // 0x800AF394: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800AF398: nop

    // 0x800AF39C: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    // 0x800AF3A0: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x800AF3A4: nop

    // 0x800AF3A8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800AF3AC: sw          $t2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r10;
    // 0x800AF3B0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800AF3B4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800AF3B8: lui         $t3, 0x106
    ctx->r11 = S32(0X106 << 16);
    // 0x800AF3BC: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x800AF3C0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800AF3C4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800AF3C8: lhu         $t5, -0x778($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X778);
    // 0x800AF3CC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF3D0: lw          $t6, -0x77C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77C);
    // 0x800AF3D4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800AF3D8: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x800AF3DC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800AF3E0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800AF3E4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800AF3E8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800AF3EC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800AF3F0: jal         0x800C1680
    // 0x800AF3F4: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800AF3F4: nop

    after_0:
    // 0x800AF3F8: jal         0x800C1850
    // 0x800AF3FC: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    MtxUtil_Identity(rdram, ctx);
        goto after_1;
    // 0x800AF3FC: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    after_1:
    // 0x800AF400: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800AF404: addiu       $t1, $sp, 0xBC
    ctx->r9 = ADD32(ctx->r29, 0XBC);
    // 0x800AF408: swc1        $f8, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f8.u32l;
    // 0x800AF40C: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800AF410: addiu       $t2, $sp, 0xBC
    ctx->r10 = ADD32(ctx->r29, 0XBC);
    // 0x800AF414: swc1        $f10, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f10.u32l;
    // 0x800AF418: lwc1        $f16, 0x110($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800AF41C: addiu       $t3, $sp, 0xBC
    ctx->r11 = ADD32(ctx->r29, 0XBC);
    // 0x800AF420: swc1        $f16, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f16.u32l;
    // 0x800AF424: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x800AF428: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800AF42C: lhu         $t5, 0xC($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XC);
    // 0x800AF430: nop

    // 0x800AF434: beq         $t5, $at, L_800AF6B0
    if (ctx->r13 == ctx->r1) {
        // 0x800AF438: nop
    
            goto L_800AF6B0;
    }
    // 0x800AF438: nop

L_800AF43C:
    // 0x800AF43C: jal         0x800C1AF4
    // 0x800AF440: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_2;
    // 0x800AF440: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    after_2:
    // 0x800AF444: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x800AF448: nop

    // 0x800AF44C: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x800AF450: lh          $t9, 0x4($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X4);
    // 0x800AF454: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800AF458: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800AF45C: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800AF460: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AF464: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AF468: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800AF46C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800AF470: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AF474: jal         0x800C2304
    // 0x800AF478: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_3;
    // 0x800AF478: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_3:
    // 0x800AF47C: lw          $t0, 0x104($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X104);
    // 0x800AF480: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AF484: addiu       $t1, $t0, 0xA
    ctx->r9 = ADD32(ctx->r8, 0XA);
    // 0x800AF488: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x800AF48C: lh          $t2, 0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XA);
    // 0x800AF490: nop

    // 0x800AF494: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800AF498: nop

    // 0x800AF49C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AF4A0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800AF4A4: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x800AF4A8: bc1t        L_800AF4BC
    if (c1cs) {
        // 0x800AF4AC: nop
    
            goto L_800AF4BC;
    }
    // 0x800AF4AC: nop

    // 0x800AF4B0: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AF4B4: jal         0x800C2780
    // 0x800AF4B8: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_4;
    // 0x800AF4B8: nop

    after_4:
L_800AF4BC:
    // 0x800AF4BC: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800AF4C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AF4C4: lh          $t4, -0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, -0X2);
    // 0x800AF4C8: nop

    // 0x800AF4CC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800AF4D0: nop

    // 0x800AF4D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AF4D8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800AF4DC: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x800AF4E0: bc1t        L_800AF4F4
    if (c1cs) {
        // 0x800AF4E4: nop
    
            goto L_800AF4F4;
    }
    // 0x800AF4E4: nop

    // 0x800AF4E8: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AF4EC: jal         0x800C25B8
    // 0x800AF4F0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_5;
    // 0x800AF4F0: nop

    after_5:
L_800AF4F4:
    // 0x800AF4F4: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800AF4F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AF4FC: lh          $t6, -0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, -0X4);
    // 0x800AF500: nop

    // 0x800AF504: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800AF508: nop

    // 0x800AF50C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AF510: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800AF514: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x800AF518: bc1t        L_800AF52C
    if (c1cs) {
        // 0x800AF51C: nop
    
            goto L_800AF52C;
    }
    // 0x800AF51C: nop

    // 0x800AF520: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AF524: jal         0x800C23E8
    // 0x800AF528: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_6;
    // 0x800AF528: nop

    after_6:
L_800AF52C:
    // 0x800AF52C: jal         0x800C2070
    // 0x800AF530: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    func_800C2070(rdram, ctx);
        goto after_7;
    // 0x800AF530: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    after_7:
    // 0x800AF534: addiu       $t8, $sp, 0x7C
    ctx->r24 = ADD32(ctx->r29, 0X7C);
    // 0x800AF538: lwc1        $f18, 0x30($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X30);
    // 0x800AF53C: nop

    // 0x800AF540: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x800AF544: addiu       $t7, $sp, 0x7C
    ctx->r15 = ADD32(ctx->r29, 0X7C);
    // 0x800AF548: lwc1        $f4, 0x34($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X34);
    // 0x800AF54C: nop

    // 0x800AF550: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800AF554: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800AF558: lwc1        $f6, 0x38($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X38);
    // 0x800AF55C: nop

    // 0x800AF560: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AF564: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800AF568: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF56C: lwc1        $f16, 0x430($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X430);
    // 0x800AF570: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800AF574: nop

    // 0x800AF578: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x800AF57C: nop

    // 0x800AF580: bc1f        L_800AF690
    if (!c1cs) {
        // 0x800AF584: nop
    
            goto L_800AF690;
    }
    // 0x800AF584: nop

    // 0x800AF588: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF58C: lwc1        $f18, 0x438($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X438);
    // 0x800AF590: nop

    // 0x800AF594: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x800AF598: nop

    // 0x800AF59C: bc1f        L_800AF690
    if (!c1cs) {
        // 0x800AF5A0: nop
    
            goto L_800AF690;
    }
    // 0x800AF5A0: nop

    // 0x800AF5A4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800AF5A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AF5AC: nop

    // 0x800AF5B0: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800AF5B4: nop

    // 0x800AF5B8: bc1f        L_800AF5C8
    if (!c1cs) {
        // 0x800AF5BC: nop
    
            goto L_800AF5C8;
    }
    // 0x800AF5BC: nop

    // 0x800AF5C0: b           L_800AF5D4
    // 0x800AF5C4: mov.s       $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    ctx->f24.fl = ctx->f4.fl;
        goto L_800AF5D4;
    // 0x800AF5C4: mov.s       $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    ctx->f24.fl = ctx->f4.fl;
L_800AF5C8:
    // 0x800AF5C8: lwc1        $f24, 0x70($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800AF5CC: nop

    // 0x800AF5D0: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
L_800AF5D4:
    // 0x800AF5D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF5D8: lwc1        $f8, 0x440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X440);
    // 0x800AF5DC: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AF5E0: mul.s       $f16, $f24, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x800AF5E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AF5E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF5EC: lwc1        $f10, 0x450($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X450);
    // 0x800AF5F0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x800AF5F4: add.s       $f22, $f16, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800AF5F8: bc1f        L_800AF608
    if (!c1cs) {
        // 0x800AF5FC: swc1        $f22, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f22.u32l;
            goto L_800AF608;
    }
    // 0x800AF5FC: swc1        $f22, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f22.u32l;
    // 0x800AF600: b           L_800AF614
    // 0x800AF604: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
        goto L_800AF614;
    // 0x800AF604: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_800AF608:
    // 0x800AF608: lwc1        $f20, 0x78($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AF60C: nop

    // 0x800AF610: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_800AF614:
    // 0x800AF614: c.le.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl <= ctx->f22.fl;
    // 0x800AF618: nop

    // 0x800AF61C: bc1f        L_800AF690
    if (!c1cs) {
        // 0x800AF620: nop
    
            goto L_800AF690;
    }
    // 0x800AF620: nop

    // 0x800AF624: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800AF628: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AF62C: nop

    // 0x800AF630: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800AF634: nop

    // 0x800AF638: bc1f        L_800AF648
    if (!c1cs) {
        // 0x800AF63C: nop
    
            goto L_800AF648;
    }
    // 0x800AF63C: nop

    // 0x800AF640: b           L_800AF654
    // 0x800AF644: mov.s       $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = ctx->f4.fl;
        goto L_800AF654;
    // 0x800AF644: mov.s       $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = ctx->f4.fl;
L_800AF648:
    // 0x800AF648: lwc1        $f26, 0x74($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800AF64C: nop

    // 0x800AF650: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = -ctx->f26.fl;
L_800AF654:
    // 0x800AF654: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800AF658: nop

    // 0x800AF65C: c.le.s      $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f26.fl <= ctx->f16.fl;
    // 0x800AF660: nop

    // 0x800AF664: bc1f        L_800AF690
    if (!c1cs) {
        // 0x800AF668: nop
    
            goto L_800AF690;
    }
    // 0x800AF668: nop

    // 0x800AF66C: lw          $t0, 0x104($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X104);
    // 0x800AF670: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800AF674: lhu         $t2, 0xC($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0XC);
    // 0x800AF678: lw          $t1, 0x1C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1C8);
    // 0x800AF67C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AF680: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800AF684: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x800AF688: jal         0x800A42C8
    // 0x800AF68C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800A42C8(rdram, ctx);
        goto after_8;
    // 0x800AF68C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_8:
L_800AF690:
    // 0x800AF690: lw          $t5, 0x104($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X104);
    // 0x800AF694: nop

    // 0x800AF698: lhu         $s0, 0xE($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0XE);
    // 0x800AF69C: addiu       $t8, $t5, 0x10
    ctx->r24 = ADD32(ctx->r13, 0X10);
    // 0x800AF6A0: sltiu       $t6, $s0, 0x1
    ctx->r14 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x800AF6A4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800AF6A8: bne         $s0, $zero, L_800AF43C
    if (ctx->r16 != 0) {
        // 0x800AF6AC: sw          $t8, 0x104($sp)
        MEM_W(0X104, ctx->r29) = ctx->r24;
            goto L_800AF43C;
    }
    // 0x800AF6AC: sw          $t8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r24;
L_800AF6B0:
    // 0x800AF6B0: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x800AF6B4: nop

    // 0x800AF6B8: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800AF6BC: sw          $t9, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r25;
    // 0x800AF6C0: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x800AF6C4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800AF6C8: lui         $t0, 0xBD00
    ctx->r8 = S32(0XBD00 << 16);
    // 0x800AF6CC: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800AF6D0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800AF6D4: nop

    // 0x800AF6D8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AF6DC: jal         0x800C1A28
    // 0x800AF6E0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_9;
    // 0x800AF6E0: nop

    after_9:
    // 0x800AF6E4: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x800AF6E8: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x800AF6EC: nop

    // 0x800AF6F0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800AF6F4: b           L_800AF6FC
    // 0x800AF6F8: nop

        goto L_800AF6FC;
    // 0x800AF6F8: nop

L_800AF6FC:
    // 0x800AF6FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF700: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800AF704: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AF708: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800AF70C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AF710: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800AF714: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AF718: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800AF71C: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AF720: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800AF724: jr          $ra
    // 0x800AF728: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800AF728: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
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
RECOMP_FUNC void func_80063DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063DE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063DE4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063DE8: nop

    // 0x80063DEC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80063DF0: nop

    // 0x80063DF4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80063DF8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063DFC: jr          $ra
    // 0x80063E00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063E00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063E04: jr          $ra
    // 0x80063E08: nop

    return;
    // 0x80063E08: nop

    // 0x80063E0C: jr          $ra
    // 0x80063E10: nop

    return;
    // 0x80063E10: nop

;}
RECOMP_FUNC void func_8006C770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C778: jal         0x8005F064
    // 0x8006C77C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C77C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_0:
    // 0x8006C780: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006C784: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006C788: beq         $v0, $zero, L_8006C7A0
    if (ctx->r2 == 0) {
        // 0x8006C78C: nop
    
            goto L_8006C7A0;
    }
    // 0x8006C78C: nop

    // 0x8006C790: jal         0x80061348
    // 0x8006C794: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006C794: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_1:
    // 0x8006C798: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C79C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006C7A0:
    // 0x8006C7A0: b           L_8006C7B0
    // 0x8006C7A4: nop

        goto L_8006C7B0;
    // 0x8006C7A4: nop

    // 0x8006C7A8: b           L_8006C7B0
    // 0x8006C7AC: nop

        goto L_8006C7B0;
    // 0x8006C7AC: nop

L_8006C7B0:
    // 0x8006C7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C7B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C7B8: jr          $ra
    // 0x8006C7BC: nop

    return;
    // 0x8006C7BC: nop

;}
RECOMP_FUNC void func_800AD680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD688: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AD68C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AD690: nop

    // 0x800AD694: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800AD698: bne         $at, $zero, L_800AD6A8
    if (ctx->r1 != 0) {
        // 0x800AD69C: nop
    
            goto L_800AD6A8;
    }
    // 0x800AD69C: nop

    // 0x800AD6A0: b           L_800AD6FC
    // 0x800AD6A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AD6FC;
    // 0x800AD6A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AD6A8:
    // 0x800AD6A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AD6AC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800AD6B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AD6B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AD6B8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD6BC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800AD6C0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD6C4: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x800AD6C8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD6CC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AD6D0: jal         0x800C1680
    // 0x800AD6D4: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800AD6D4: nop

    after_0:
    // 0x800AD6D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD6DC: jal         0x800C1A84
    // 0x800AD6E0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_1;
    // 0x800AD6E0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_1:
    // 0x800AD6E4: jal         0x800C1A28
    // 0x800AD6E8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_2;
    // 0x800AD6E8: nop

    after_2:
    // 0x800AD6EC: b           L_800AD6FC
    // 0x800AD6F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD6FC;
    // 0x800AD6F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD6F4: b           L_800AD6FC
    // 0x800AD6F8: nop

        goto L_800AD6FC;
    // 0x800AD6F8: nop

L_800AD6FC:
    // 0x800AD6FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AD704: jr          $ra
    // 0x800AD708: nop

    return;
    // 0x800AD708: nop

;}
RECOMP_FUNC void func_80061840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061840: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80061844: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80061848: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006184C: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x80061850: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061854: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061858: nop

    // 0x8006185C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80061860: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80061864: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061868: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8006186C: nop

    // 0x80061870: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061874: bne         $at, $zero, L_80061978
    if (ctx->r1 != 0) {
        // 0x80061878: nop
    
            goto L_80061978;
    }
    // 0x80061878: nop

L_8006187C:
    // 0x8006187C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80061880: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80061884: nop

    // 0x80061888: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8006188C: bgez        $t2, L_8006189C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061890: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_8006189C;
    }
    // 0x80061890: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80061894: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061898: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8006189C:
    // 0x8006189C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800618A0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800618A4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800618A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800618AC: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x800618B0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800618B4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800618B8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800618BC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800618C0: nop

    // 0x800618C4: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800618C8: beq         $at, $zero, L_800618E4
    if (ctx->r1 == 0) {
        // 0x800618CC: nop
    
            goto L_800618E4;
    }
    // 0x800618CC: nop

    // 0x800618D0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800618D4: nop

    // 0x800618D8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800618DC: b           L_80061960
    // 0x800618E0: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_80061960;
    // 0x800618E0: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_800618E4:
    // 0x800618E4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800618E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800618EC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800618F0: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x800618F4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800618F8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800618FC: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80061900: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x80061904: nop

    // 0x80061908: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006190C: beq         $at, $zero, L_80061928
    if (ctx->r1 == 0) {
        // 0x80061910: nop
    
            goto L_80061928;
    }
    // 0x80061910: nop

    // 0x80061914: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80061918: nop

    // 0x8006191C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80061920: b           L_80061960
    // 0x80061924: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_80061960;
    // 0x80061924: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80061928:
    // 0x80061928: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8006192C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80061930: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80061934: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x80061938: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8006193C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80061940: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80061944: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80061948: subu        $v0, $t2, $t0
    ctx->r2 = SUB32(ctx->r10, ctx->r8);
    // 0x8006194C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80061950: mflo        $t1
    ctx->r9 = lo;
    // 0x80061954: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80061958: b           L_80061988
    // 0x8006195C: nop

        goto L_80061988;
    // 0x8006195C: nop

L_80061960:
    // 0x80061960: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x80061964: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x80061968: nop

    // 0x8006196C: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061970: beq         $at, $zero, L_8006187C
    if (ctx->r1 == 0) {
        // 0x80061974: nop
    
            goto L_8006187C;
    }
    // 0x80061974: nop

L_80061978:
    // 0x80061978: b           L_80061988
    // 0x8006197C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80061988;
    // 0x8006197C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80061980: b           L_80061988
    // 0x80061984: nop

        goto L_80061988;
    // 0x80061984: nop

L_80061988:
    // 0x80061988: jr          $ra
    // 0x8006198C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006198C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006479C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006479C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800647A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800647A4: jal         0x80061488
    // 0x800647A8: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800647A8: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x800647AC: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800647B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800647B4: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x800647B8: nop
    
            goto L_80064848;
    }
    // 0x800647B8: nop

    // 0x800647BC: jal         0x80061488
    // 0x800647C0: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x800647C0: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x800647C4: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800647C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800647CC: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x800647D0: nop
    
            goto L_80064848;
    }
    // 0x800647D0: nop

    // 0x800647D4: jal         0x80061488
    // 0x800647D8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x800647D8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x800647DC: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800647E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800647E4: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x800647E8: nop
    
            goto L_80064848;
    }
    // 0x800647E8: nop

    // 0x800647EC: jal         0x80061488
    // 0x800647F0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x800647F0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x800647F4: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800647F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800647FC: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x80064800: nop
    
            goto L_80064848;
    }
    // 0x80064800: nop

    // 0x80064804: jal         0x80061488
    // 0x80064808: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064808: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x8006480C: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064810: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064814: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x80064818: nop
    
            goto L_80064848;
    }
    // 0x80064818: nop

    // 0x8006481C: jal         0x8005F064
    // 0x80064820: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064820: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064824: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064828: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006482C: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x80064830: nop
    
            goto L_80064848;
    }
    // 0x80064830: nop

    // 0x80064834: jal         0x80061348
    // 0x80064838: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064838: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x8006483C: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064840: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064844: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064848:
    // 0x80064848: b           L_80064858
    // 0x8006484C: nop

        goto L_80064858;
    // 0x8006484C: nop

    // 0x80064850: b           L_80064858
    // 0x80064854: nop

        goto L_80064858;
    // 0x80064854: nop

L_80064858:
    // 0x80064858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006485C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064860: jr          $ra
    // 0x80064864: nop

    return;
    // 0x80064864: nop

;}
RECOMP_FUNC void func_80076254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076254: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076258: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007625C: nop

    // 0x80076260: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076264: nop

    // 0x80076268: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007626C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076270: jr          $ra
    // 0x80076274: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076274: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076278: jr          $ra
    // 0x8007627C: nop

    return;
    // 0x8007627C: nop

    // 0x80076280: jr          $ra
    // 0x80076284: nop

    return;
    // 0x80076284: nop

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
RECOMP_FUNC void func_80063264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006326C: jal         0x80061488
    // 0x80063270: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063270: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    after_0:
    // 0x80063274: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063278: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006327C: b           L_8006328C
    // 0x80063280: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006328C;
    // 0x80063280: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063284: b           L_8006328C
    // 0x80063288: nop

        goto L_8006328C;
    // 0x80063288: nop

L_8006328C:
    // 0x8006328C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063294: jr          $ra
    // 0x80063298: nop

    return;
    // 0x80063298: nop

;}
RECOMP_FUNC void func_80067470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067478: jal         0x80061488
    // 0x8006747C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006747C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_0:
    // 0x80067480: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067484: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067488: b           L_80067498
    // 0x8006748C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067498;
    // 0x8006748C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067490: b           L_80067498
    // 0x80067494: nop

        goto L_80067498;
    // 0x80067494: nop

L_80067498:
    // 0x80067498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006749C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800674A0: jr          $ra
    // 0x800674A4: nop

    return;
    // 0x800674A4: nop

;}
RECOMP_FUNC void func_80073D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073D7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073D80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073D84: nop

    // 0x80073D88: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073D8C: nop

    // 0x80073D90: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073D94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073D98: jr          $ra
    // 0x80073D9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073D9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073DA0: jr          $ra
    // 0x80073DA4: nop

    return;
    // 0x80073DA4: nop

    // 0x80073DA8: jr          $ra
    // 0x80073DAC: nop

    return;
    // 0x80073DAC: nop

;}
RECOMP_FUNC void func_80070B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070B80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80070B84: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80070B88: nop

    // 0x80070B8C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80070B90: nop

    // 0x80070B94: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80070B98: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80070B9C: jr          $ra
    // 0x80070BA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80070BA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070BA4: jr          $ra
    // 0x80070BA8: nop

    return;
    // 0x80070BA8: nop

    // 0x80070BAC: jr          $ra
    // 0x80070BB0: nop

    return;
    // 0x80070BB0: nop

;}
RECOMP_FUNC void func_80074DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074DE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074DEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80074DF0: nop

    // 0x80074DF4: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80074DF8: nop

    // 0x80074DFC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80074E00: jr          $ra
    // 0x80074E04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80074E04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074E08: jr          $ra
    // 0x80074E0C: nop

    return;
    // 0x80074E0C: nop

    // 0x80074E10: jr          $ra
    // 0x80074E14: nop

    return;
    // 0x80074E14: nop

;}
RECOMP_FUNC void func_80062FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062FE8: jal         0x8005F064
    // 0x80062FEC: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062FEC: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x80062FF0: b           L_80063000
    // 0x80062FF4: nop

        goto L_80063000;
    // 0x80062FF4: nop

    // 0x80062FF8: b           L_80063000
    // 0x80062FFC: nop

        goto L_80063000;
    // 0x80062FFC: nop

L_80063000:
    // 0x80063000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063008: jr          $ra
    // 0x8006300C: nop

    return;
    // 0x8006300C: nop

;}
RECOMP_FUNC void func_80098CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098CD8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098CDC: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098CE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098CE4: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x80098CE8: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098CEC: jr          $ra
    // 0x80098CF0: nop

    return;
    // 0x80098CF0: nop

    // 0x80098CF4: jr          $ra
    // 0x80098CF8: nop

    return;
    // 0x80098CF8: nop

;}
RECOMP_FUNC void func_800629F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800629F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800629FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062A00: jal         0x8005F064
    // 0x80062A04: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062A04: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x80062A08: b           L_80062A18
    // 0x80062A0C: nop

        goto L_80062A18;
    // 0x80062A0C: nop

    // 0x80062A10: b           L_80062A18
    // 0x80062A14: nop

        goto L_80062A18;
    // 0x80062A14: nop

L_80062A18:
    // 0x80062A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062A20: jr          $ra
    // 0x80062A24: nop

    return;
    // 0x80062A24: nop

;}
RECOMP_FUNC void func_80098C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098C1C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098C20: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098C24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098C28: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80098C2C: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098C30: jr          $ra
    // 0x80098C34: nop

    return;
    // 0x80098C34: nop

    // 0x80098C38: jr          $ra
    // 0x80098C3C: nop

    return;
    // 0x80098C3C: nop

;}
RECOMP_FUNC void Scheduler_CreateSchedulerThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009706C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80097074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097078: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009707C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80097080: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097084: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097088: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8009708C: addiu       $a2, $a2, 0x756C
    ctx->r6 = ADD32(ctx->r6, 0X756C);
    // 0x80097090: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80097094: addiu       $a0, $t6, 0xD0
    ctx->r4 = ADD32(ctx->r14, 0XD0);
    // 0x80097098: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8009709C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800970A0: jal         0x800C4800
    // 0x800970A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800970A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x800970A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800970AC: jal         0x800C4950
    // 0x800970B0: addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800970B0: addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
    after_1:
    // 0x800970B4: b           L_800970BC
    // 0x800970B8: nop

        goto L_800970BC;
    // 0x800970B8: nop

L_800970BC:
    // 0x800970BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800970C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800970C4: jr          $ra
    // 0x800970C8: nop

    return;
    // 0x800970C8: nop

;}
RECOMP_FUNC void func_80065778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065778: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006577C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065780: nop

    // 0x80065784: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80065788: nop

    // 0x8006578C: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80065790: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065794: jr          $ra
    // 0x80065798: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065798: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006579C: jr          $ra
    // 0x800657A0: nop

    return;
    // 0x800657A0: nop

    // 0x800657A4: jr          $ra
    // 0x800657A8: nop

    return;
    // 0x800657A8: nop

;}
RECOMP_FUNC void func_80089418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089418: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008941C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80089420: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80089424: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80089428: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008942C: addiu       $t6, $zero, 0x2A
    ctx->r14 = ADD32(0, 0X2A);
    // 0x80089430: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
    // 0x80089434: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80089438: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x8008943C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80089440: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80089444:
    // 0x80089444: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80089448: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8008944C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80089450: nop

    // 0x80089454: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80089458: nop

    // 0x8008945C: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80089460: bne         $t1, $zero, L_80089478
    if (ctx->r9 != 0) {
        // 0x80089464: nop
    
            goto L_80089478;
    }
    // 0x80089464: nop

    // 0x80089468: lhu         $t2, 0x3A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3A);
    // 0x8008946C: nop

    // 0x80089470: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80089474: sh          $t3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r11;
L_80089478:
    // 0x80089478: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8008947C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089480: beq         $s0, $at, L_8008949C
    if (ctx->r16 == ctx->r1) {
        // 0x80089484: nop
    
            goto L_8008949C;
    }
    // 0x80089484: nop

    // 0x80089488: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008948C: beq         $s0, $at, L_800894D0
    if (ctx->r16 == ctx->r1) {
        // 0x80089490: nop
    
            goto L_800894D0;
    }
    // 0x80089490: nop

    // 0x80089494: b           L_80089504
    // 0x80089498: nop

        goto L_80089504;
    // 0x80089498: nop

L_8008949C:
    // 0x8008949C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800894A0: nop

    // 0x800894A4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800894A8: nop

    // 0x800894AC: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x800894B0: bne         $t6, $zero, L_800894C8
    if (ctx->r14 != 0) {
        // 0x800894B4: nop
    
            goto L_800894C8;
    }
    // 0x800894B4: nop

    // 0x800894B8: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x800894BC: nop

    // 0x800894C0: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x800894C4: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
L_800894C8:
    // 0x800894C8: b           L_80089504
    // 0x800894CC: nop

        goto L_80089504;
    // 0x800894CC: nop

L_800894D0:
    // 0x800894D0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800894D4: nop

    // 0x800894D8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800894DC: nop

    // 0x800894E0: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x800894E4: beq         $t1, $zero, L_800894FC
    if (ctx->r9 == 0) {
        // 0x800894E8: nop
    
            goto L_800894FC;
    }
    // 0x800894E8: nop

    // 0x800894EC: lhu         $t2, 0x3A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3A);
    // 0x800894F0: nop

    // 0x800894F4: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x800894F8: sh          $t3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r11;
L_800894FC:
    // 0x800894FC: b           L_80089504
    // 0x80089500: nop

        goto L_80089504;
    // 0x80089500: nop

L_80089504:
    // 0x80089504: lh          $t4, 0x42($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X42);
    // 0x80089508: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8008950C: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x80089510: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80089514: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80089518: addiu       $t5, $zero, 0x31
    ctx->r13 = ADD32(0, 0X31);
    // 0x8008951C: addiu       $t6, $t4, 0x28
    ctx->r14 = ADD32(ctx->r12, 0X28);
    // 0x80089520: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80089524: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80089528: addiu       $a2, $zero, -0x71
    ctx->r6 = ADD32(0, -0X71);
    // 0x8008952C: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x80089530: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x80089534: jal         0x800897A8
    // 0x80089538: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800897A8(rdram, ctx);
        goto after_0;
    // 0x80089538: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8008953C: lh          $t8, 0x42($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X42);
    // 0x80089540: nop

    // 0x80089544: addiu       $t9, $t8, -0x30
    ctx->r25 = ADD32(ctx->r24, -0X30);
    // 0x80089548: sh          $t9, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r25;
    // 0x8008954C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80089550: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80089554: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80089558: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8008955C: addiu       $t3, $t2, 0x16
    ctx->r11 = ADD32(ctx->r10, 0X16);
    // 0x80089560: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80089564: bne         $at, $zero, L_80089444
    if (ctx->r1 != 0) {
        // 0x80089568: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_80089444;
    }
    // 0x80089568: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8008956C: b           L_80089574
    // 0x80089570: nop

        goto L_80089574;
    // 0x80089570: nop

L_80089574:
    // 0x80089574: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80089578: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008957C: jr          $ra
    // 0x80089580: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80089580: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
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
RECOMP_FUNC void func_80072BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072BE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072BE4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072BE8: nop

    // 0x80072BEC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072BF0: nop

    // 0x80072BF4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072BF8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072BFC: jr          $ra
    // 0x80072C00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072C00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072C04: jr          $ra
    // 0x80072C08: nop

    return;
    // 0x80072C08: nop

    // 0x80072C0C: jr          $ra
    // 0x80072C10: nop

    return;
    // 0x80072C10: nop

;}
RECOMP_FUNC void func_80077DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077DF8: jal         0x8005F064
    // 0x80077DFC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077DFC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077E00: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077E04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077E08: beq         $v0, $zero, L_80077E20
    if (ctx->r2 == 0) {
        // 0x80077E0C: nop
    
            goto L_80077E20;
    }
    // 0x80077E0C: nop

    // 0x80077E10: jal         0x8005F064
    // 0x80077E14: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80077E14: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x80077E18: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077E1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80077E20:
    // 0x80077E20: b           L_80077E30
    // 0x80077E24: nop

        goto L_80077E30;
    // 0x80077E24: nop

    // 0x80077E28: b           L_80077E30
    // 0x80077E2C: nop

        goto L_80077E30;
    // 0x80077E2C: nop

L_80077E30:
    // 0x80077E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077E38: jr          $ra
    // 0x80077E3C: nop

    return;
    // 0x80077E3C: nop

;}
RECOMP_FUNC void func_8006C5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C5A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C5A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C5A8: jal         0x8005F064
    // 0x8006C5AC: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C5AC: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    after_0:
    // 0x8006C5B0: b           L_8006C5C0
    // 0x8006C5B4: nop

        goto L_8006C5C0;
    // 0x8006C5B4: nop

    // 0x8006C5B8: b           L_8006C5C0
    // 0x8006C5BC: nop

        goto L_8006C5C0;
    // 0x8006C5BC: nop

L_8006C5C0:
    // 0x8006C5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C5C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C5C8: jr          $ra
    // 0x8006C5CC: nop

    return;
    // 0x8006C5CC: nop

;}
RECOMP_FUNC void func_8002C004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C00C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002C014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002C018: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8002C01C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002C020: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002C024: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002C028: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C02C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C030: lwc1        $f17, -0x18F8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X18F8);
    // 0x8002C034: lwc1        $f16, -0x18F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X18F4);
    // 0x8002C038: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002C03C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C040: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8002C044: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002C048: swc1        $f4, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->f4.u32l;
    // 0x8002C04C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8002C050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002C054: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C058: swc1        $f6, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f6.u32l;
    // 0x8002C05C: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x8002C060: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C064: sh          $t6, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r14;
    // 0x8002C068: jal         0x8002BB9C
    // 0x8002C06C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8002BB9C(rdram, ctx);
        goto after_0;
    // 0x8002C06C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8002C070: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C074: swc1        $f0, -0x69E0($at)
    MEM_W(-0X69E0, ctx->r1) = ctx->f0.u32l;
    // 0x8002C078: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002C07C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C080: sh          $t7, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r15;
    // 0x8002C084: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002C088: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C08C: sh          $t8, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = ctx->r24;
    // 0x8002C090: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8002C094: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C098: sb          $t9, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = ctx->r25;
    // 0x8002C09C: jal         0x800B9000
    // 0x8002C0A0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8002C0A0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x8002C0A4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002C0A8: lw          $t0, 0x307C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X307C);
    // 0x8002C0AC: nop

    // 0x8002C0B0: bne         $t0, $zero, L_8002C0E4
    if (ctx->r8 != 0) {
        // 0x8002C0B4: nop
    
            goto L_8002C0E4;
    }
    // 0x8002C0B4: nop

    // 0x8002C0B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002C0BC: lh          $t1, 0x1644($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1644);
    // 0x8002C0C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002C0C4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002C0C8: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8002C0CC: lhu         $a0, -0x4772($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4772);
    // 0x8002C0D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C0D4: jal         0x800AFB70
    // 0x8002C0D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x8002C0D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8002C0DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002C0E0: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
L_8002C0E4:
    // 0x8002C0E4: b           L_8002C0EC
    // 0x8002C0E8: nop

        goto L_8002C0EC;
    // 0x8002C0E8: nop

L_8002C0EC:
    // 0x8002C0EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C0F4: jr          $ra
    // 0x8002C0F8: nop

    return;
    // 0x8002C0F8: nop

;}
RECOMP_FUNC void func_80076F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076F98: jal         0x80061488
    // 0x80076F9C: addiu       $a0, $zero, 0x492
    ctx->r4 = ADD32(0, 0X492);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076F9C: addiu       $a0, $zero, 0x492
    ctx->r4 = ADD32(0, 0X492);
    after_0:
    // 0x80076FA0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076FA4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076FA8: b           L_80076FB8
    // 0x80076FAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076FB8;
    // 0x80076FAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076FB0: b           L_80076FB8
    // 0x80076FB4: nop

        goto L_80076FB8;
    // 0x80076FB4: nop

L_80076FB8:
    // 0x80076FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076FC0: jr          $ra
    // 0x80076FC4: nop

    return;
    // 0x80076FC4: nop

;}
RECOMP_FUNC void alSynDelete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF740: jr          $ra
    // 0x800CF744: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x800CF744: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800B56F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B56F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B56F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B56F8: jal         0x800B5730
    // 0x800B56FC: nop

    func_800B5730(rdram, ctx);
        goto after_0;
    // 0x800B56FC: nop

    after_0:
    // 0x800B5700: beq         $v0, $zero, L_800B5710
    if (ctx->r2 == 0) {
        // 0x800B5704: nop
    
            goto L_800B5710;
    }
    // 0x800B5704: nop

    // 0x800B5708: b           L_800B5720
    // 0x800B570C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B5720;
    // 0x800B570C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B5710:
    // 0x800B5710: b           L_800B5720
    // 0x800B5714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B5720;
    // 0x800B5714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B5718: b           L_800B5720
    // 0x800B571C: nop

        goto L_800B5720;
    // 0x800B571C: nop

L_800B5720:
    // 0x800B5720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B5728: jr          $ra
    // 0x800B572C: nop

    return;
    // 0x800B572C: nop

;}
RECOMP_FUNC void MathUtil_GetDistanceIfWithinRadius(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3C80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C3C84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C3C88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C3C8C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C3C90: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800C3C94: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800C3C98: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800C3C9C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800C3CA0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3CA4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C3CA8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C3CAC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C3CB0: nop

    // 0x800C3CB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C3CB8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800C3CBC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3CC0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C3CC4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C3CC8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C3CCC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3CD0: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C3CD4: sub.s       $f22, $f10, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800C3CD8: sub.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800C3CDC: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x800C3CE0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C3CE4: swc1        $f20, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f20.u32l;
    // 0x800C3CE8: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800C3CEC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C3CF0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3CF4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800C3CF8: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800C3CFC: nop

    // 0x800C3D00: mul.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x800C3D04: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C3D08: jal         0x800C42A0
    // 0x800C3D0C: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C3D0C: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_0:
    // 0x800C3D10: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800C3D14: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C3D18: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C3D1C: nop

    // 0x800C3D20: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x800C3D24: nop

    // 0x800C3D28: bc1f        L_800C3D3C
    if (!c1cs) {
        // 0x800C3D2C: nop
    
            goto L_800C3D3C;
    }
    // 0x800C3D2C: nop

    // 0x800C3D30: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C3D34: b           L_800C3D54
    // 0x800C3D38: nop

        goto L_800C3D54;
    // 0x800C3D38: nop

L_800C3D3C:
    // 0x800C3D3C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800C3D40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C3D44: b           L_800C3D54
    // 0x800C3D48: nop

        goto L_800C3D54;
    // 0x800C3D48: nop

    // 0x800C3D4C: b           L_800C3D54
    // 0x800C3D50: nop

        goto L_800C3D54;
    // 0x800C3D50: nop

L_800C3D54:
    // 0x800C3D54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C3D58: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C3D5C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C3D60: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C3D64: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3D68: jr          $ra
    // 0x800C3D6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C3D6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
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
RECOMP_FUNC void func_8006BAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BAC8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BACC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BAD0: nop

    // 0x8006BAD4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006BAD8: nop

    // 0x8006BADC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006BAE0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BAE4: jr          $ra
    // 0x8006BAE8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BAE8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BAEC: jr          $ra
    // 0x8006BAF0: nop

    return;
    // 0x8006BAF0: nop

    // 0x8006BAF4: jr          $ra
    // 0x8006BAF8: nop

    return;
    // 0x8006BAF8: nop

;}
RECOMP_FUNC void func_80078494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078494: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80078498: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007849C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800784A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800784A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800784A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800784AC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800784B0: lhu         $t6, 0x46($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X46);
    // 0x800784B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800784B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800784BC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800784C0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800784C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800784C8: jal         0x8007915C
    // 0x800784CC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_8007915C(rdram, ctx);
        goto after_0;
    // 0x800784CC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
    // 0x800784D0: b           L_800784D8
    // 0x800784D4: nop

        goto L_800784D8;
    // 0x800784D4: nop

L_800784D8:
    // 0x800784D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800784DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800784E0: jr          $ra
    // 0x800784E4: nop

    return;
    // 0x800784E4: nop

;}
RECOMP_FUNC void func_80011B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011B88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011B90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80011B94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80011B98: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80011B9C: jal         0x8000DA44
    // 0x80011BA0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80011BA0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80011BA4: bgez        $v0, L_80011BB4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011BA8: nop
    
            goto L_80011BB4;
    }
    // 0x80011BA8: nop

    // 0x80011BAC: b           L_80011F6C
    // 0x80011BB0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011F6C;
    // 0x80011BB0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011BB4:
    // 0x80011BB4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80011BB8: nop

    // 0x80011BBC: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x80011BC0: nop

    // 0x80011BC4: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x80011BC8: sw          $t8, 0x1A8($t6)
    MEM_W(0X1A8, ctx->r14) = ctx->r24;
    // 0x80011BCC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80011BD0: nop

    // 0x80011BD4: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x80011BD8: nop

    // 0x80011BDC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80011BE0: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x80011BE4: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x80011BE8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011BEC: nop

    // 0x80011BF0: sh          $t2, 0x62($t3)
    MEM_H(0X62, ctx->r11) = ctx->r10;
    // 0x80011BF4: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80011BF8: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80011BFC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80011C00: nop

    // 0x80011C04: sh          $t5, 0x64($t7)
    MEM_H(0X64, ctx->r15) = ctx->r13;
    // 0x80011C08: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x80011C0C: lhu         $t6, 0x6($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X6);
    // 0x80011C10: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80011C14: nop

    // 0x80011C18: sh          $t6, 0x66($t9)
    MEM_H(0X66, ctx->r25) = ctx->r14;
    // 0x80011C1C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80011C20: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80011C24: lhu         $t1, 0x62($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X62);
    // 0x80011C28: ori         $at, $at, 0x1FFE
    ctx->r1 = ctx->r1 | 0X1FFE;
    // 0x80011C2C: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80011C30: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x80011C34: beq         $at, $zero, L_80011F5C
    if (ctx->r1 == 0) {
        // 0x80011C38: nop
    
            goto L_80011F5C;
    }
    // 0x80011C38: nop

    // 0x80011C3C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80011C40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80011C44: addu        $at, $at, $t2
    gpr jr_addend_80011C50 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80011C48: lw          $t2, -0x2B38($at)
    ctx->r10 = ADD32(ctx->r1, -0X2B38);
    // 0x80011C4C: nop

    // 0x80011C50: jr          $t2
    // 0x80011C54: nop

    switch (jr_addend_80011C50 >> 2) {
        case 0: goto L_80011C58; break;
        case 1: goto L_80011CA8; break;
        case 2: goto L_80011F5C; break;
        case 3: goto L_80011F5C; break;
        case 4: goto L_80011F5C; break;
        case 5: goto L_80011F5C; break;
        case 6: goto L_80011CF8; break;
        case 7: goto L_80011DC4; break;
        case 8: goto L_80011E0C; break;
        case 9: goto L_80011E5C; break;
        case 10: goto L_80011EAC; break;
        case 11: goto L_80011EFC; break;
        case 12: goto L_80011C58; break;
        case 13: goto L_80011CA8; break;
        case 14: goto L_80011CF8; break;
        default: switch_error(__func__, 0x80011C50, 0x800ED4C8);
    }
    // 0x80011C54: nop

L_80011C58:
    // 0x80011C58: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011C5C: nop

    // 0x80011C60: lh          $t5, 0x66($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X66);
    // 0x80011C64: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80011C68: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80011C6C: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x80011C70: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80011C74: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80011C78: nop

    // 0x80011C7C: bc1f        L_80011C94
    if (!c1cs) {
        // 0x80011C80: nop
    
            goto L_80011C94;
    }
    // 0x80011C80: nop

    // 0x80011C84: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011C88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80011C8C: b           L_80011CA0
    // 0x80011C90: sh          $t7, 0x68($t8)
    MEM_H(0X68, ctx->r24) = ctx->r15;
        goto L_80011CA0;
    // 0x80011C90: sh          $t7, 0x68($t8)
    MEM_H(0X68, ctx->r24) = ctx->r15;
L_80011C94:
    // 0x80011C94: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80011C98: nop

    // 0x80011C9C: sh          $zero, 0x68($t6)
    MEM_H(0X68, ctx->r14) = 0;
L_80011CA0:
    // 0x80011CA0: b           L_80011F5C
    // 0x80011CA4: nop

        goto L_80011F5C;
    // 0x80011CA4: nop

L_80011CA8:
    // 0x80011CA8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80011CAC: nop

    // 0x80011CB0: lh          $t1, 0x66($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X66);
    // 0x80011CB4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80011CB8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80011CBC: lwc1        $f10, 0xD0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80011CC0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80011CC4: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80011CC8: nop

    // 0x80011CCC: bc1f        L_80011CE4
    if (!c1cs) {
        // 0x80011CD0: nop
    
            goto L_80011CE4;
    }
    // 0x80011CD0: nop

    // 0x80011CD4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80011CD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80011CDC: b           L_80011CF0
    // 0x80011CE0: sh          $t2, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r10;
        goto L_80011CF0;
    // 0x80011CE0: sh          $t2, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r10;
L_80011CE4:
    // 0x80011CE4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011CE8: nop

    // 0x80011CEC: sh          $zero, 0x68($t3)
    MEM_H(0X68, ctx->r11) = 0;
L_80011CF0:
    // 0x80011CF0: b           L_80011F5C
    // 0x80011CF4: nop

        goto L_80011F5C;
    // 0x80011CF4: nop

L_80011CF8:
    // 0x80011CF8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80011CFC: nop

    // 0x80011D00: lw          $t7, 0x1AC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1AC);
    // 0x80011D04: nop

    // 0x80011D08: slti        $at, $t7, 0x4000
    ctx->r1 = SIGNED(ctx->r15) < 0X4000 ? 1 : 0;
    // 0x80011D0C: bne         $at, $zero, L_80011D24
    if (ctx->r1 != 0) {
        // 0x80011D10: nop
    
            goto L_80011D24;
    }
    // 0x80011D10: nop

    // 0x80011D14: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80011D18: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011D1C: bne         $at, $zero, L_80011D74
    if (ctx->r1 != 0) {
        // 0x80011D20: nop
    
            goto L_80011D74;
    }
    // 0x80011D20: nop

L_80011D24:
    // 0x80011D24: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011D28: nop

    // 0x80011D2C: lh          $t6, 0x66($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X66);
    // 0x80011D30: lwc1        $f6, 0x14($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X14);
    // 0x80011D34: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80011D38: nop

    // 0x80011D3C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011D40: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80011D44: nop

    // 0x80011D48: bc1f        L_80011D60
    if (!c1cs) {
        // 0x80011D4C: nop
    
            goto L_80011D60;
    }
    // 0x80011D4C: nop

    // 0x80011D50: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80011D54: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011D58: b           L_80011D6C
    // 0x80011D5C: sh          $t0, 0x68($t9)
    MEM_H(0X68, ctx->r25) = ctx->r8;
        goto L_80011D6C;
    // 0x80011D5C: sh          $t0, 0x68($t9)
    MEM_H(0X68, ctx->r25) = ctx->r8;
L_80011D60:
    // 0x80011D60: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80011D64: nop

    // 0x80011D68: sh          $zero, 0x68($t1)
    MEM_H(0X68, ctx->r9) = 0;
L_80011D6C:
    // 0x80011D6C: b           L_80011DBC
    // 0x80011D70: nop

        goto L_80011DBC;
    // 0x80011D70: nop

L_80011D74:
    // 0x80011D74: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80011D78: nop

    // 0x80011D7C: lh          $t3, 0x66($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X66);
    // 0x80011D80: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x80011D84: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80011D88: lwc1        $f16, 0xD4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XD4);
    // 0x80011D8C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011D90: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80011D94: nop

    // 0x80011D98: bc1f        L_80011DB0
    if (!c1cs) {
        // 0x80011D9C: nop
    
            goto L_80011DB0;
    }
    // 0x80011D9C: nop

    // 0x80011DA0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80011DA4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80011DA8: b           L_80011DBC
    // 0x80011DAC: sh          $t5, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r13;
        goto L_80011DBC;
    // 0x80011DAC: sh          $t5, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r13;
L_80011DB0:
    // 0x80011DB0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011DB4: nop

    // 0x80011DB8: sh          $zero, 0x68($t8)
    MEM_H(0X68, ctx->r24) = 0;
L_80011DBC:
    // 0x80011DBC: b           L_80011F5C
    // 0x80011DC0: nop

        goto L_80011F5C;
    // 0x80011DC0: nop

L_80011DC4:
    // 0x80011DC4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80011DC8: nop

    // 0x80011DCC: lw          $t0, 0xC($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC);
    // 0x80011DD0: lhu         $t1, 0x66($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X66);
    // 0x80011DD4: lhu         $t9, 0x11E($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X11E);
    // 0x80011DD8: nop

    // 0x80011DDC: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80011DE0: beq         $at, $zero, L_80011DF8
    if (ctx->r1 == 0) {
        // 0x80011DE4: nop
    
            goto L_80011DF8;
    }
    // 0x80011DE4: nop

    // 0x80011DE8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80011DEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80011DF0: b           L_80011E04
    // 0x80011DF4: sh          $t4, 0x68($t2)
    MEM_H(0X68, ctx->r10) = ctx->r12;
        goto L_80011E04;
    // 0x80011DF4: sh          $t4, 0x68($t2)
    MEM_H(0X68, ctx->r10) = ctx->r12;
L_80011DF8:
    // 0x80011DF8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011DFC: nop

    // 0x80011E00: sh          $zero, 0x68($t3)
    MEM_H(0X68, ctx->r11) = 0;
L_80011E04:
    // 0x80011E04: b           L_80011F5C
    // 0x80011E08: nop

        goto L_80011F5C;
    // 0x80011E08: nop

L_80011E0C:
    // 0x80011E0C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80011E10: nop

    // 0x80011E14: lh          $t8, 0x66($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X66);
    // 0x80011E18: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x80011E1C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80011E20: lwc1        $f4, 0xE8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x80011E24: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80011E28: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80011E2C: nop

    // 0x80011E30: bc1f        L_80011E48
    if (!c1cs) {
        // 0x80011E34: nop
    
            goto L_80011E48;
    }
    // 0x80011E34: nop

    // 0x80011E38: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80011E3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011E40: b           L_80011E54
    // 0x80011E44: sh          $t0, 0x68($t6)
    MEM_H(0X68, ctx->r14) = ctx->r8;
        goto L_80011E54;
    // 0x80011E44: sh          $t0, 0x68($t6)
    MEM_H(0X68, ctx->r14) = ctx->r8;
L_80011E48:
    // 0x80011E48: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80011E4C: nop

    // 0x80011E50: sh          $zero, 0x68($t9)
    MEM_H(0X68, ctx->r25) = 0;
L_80011E54:
    // 0x80011E54: b           L_80011F5C
    // 0x80011E58: nop

        goto L_80011F5C;
    // 0x80011E58: nop

L_80011E5C:
    // 0x80011E5C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80011E60: nop

    // 0x80011E64: lh          $t2, 0x66($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X66);
    // 0x80011E68: lw          $t4, 0xC($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC);
    // 0x80011E6C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80011E70: lwc1        $f10, 0xEC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XEC);
    // 0x80011E74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80011E78: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80011E7C: nop

    // 0x80011E80: bc1f        L_80011E98
    if (!c1cs) {
        // 0x80011E84: nop
    
            goto L_80011E98;
    }
    // 0x80011E84: nop

    // 0x80011E88: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80011E8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80011E90: b           L_80011EA4
    // 0x80011E94: sh          $t3, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r11;
        goto L_80011EA4;
    // 0x80011E94: sh          $t3, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r11;
L_80011E98:
    // 0x80011E98: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80011E9C: nop

    // 0x80011EA0: sh          $zero, 0x68($t5)
    MEM_H(0X68, ctx->r13) = 0;
L_80011EA4:
    // 0x80011EA4: b           L_80011F5C
    // 0x80011EA8: nop

        goto L_80011F5C;
    // 0x80011EA8: nop

L_80011EAC:
    // 0x80011EAC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011EB0: nop

    // 0x80011EB4: lh          $t6, 0x66($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X66);
    // 0x80011EB8: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x80011EBC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80011EC0: lwc1        $f6, 0xF0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x80011EC4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011EC8: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80011ECC: nop

    // 0x80011ED0: bc1f        L_80011EE8
    if (!c1cs) {
        // 0x80011ED4: nop
    
            goto L_80011EE8;
    }
    // 0x80011ED4: nop

    // 0x80011ED8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80011EDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80011EE0: b           L_80011EF4
    // 0x80011EE4: sh          $t9, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r25;
        goto L_80011EF4;
    // 0x80011EE4: sh          $t9, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r25;
L_80011EE8:
    // 0x80011EE8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80011EEC: nop

    // 0x80011EF0: sh          $zero, 0x68($t1)
    MEM_H(0X68, ctx->r9) = 0;
L_80011EF4:
    // 0x80011EF4: b           L_80011F5C
    // 0x80011EF8: nop

        goto L_80011F5C;
    // 0x80011EF8: nop

L_80011EFC:
    // 0x80011EFC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80011F00: nop

    // 0x80011F04: lhu         $a0, 0x66($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X66);
    // 0x80011F08: jal         0x80014BD4
    // 0x80011F0C: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80011F0C: nop

    after_1:
    // 0x80011F10: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011F14: nop

    // 0x80011F18: lw          $t7, 0xC($t3)
    ctx->r15 = MEM_W(ctx->r11, 0XC);
    // 0x80011F1C: nop

    // 0x80011F20: lwc1        $f16, 0xF4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x80011F24: nop

    // 0x80011F28: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80011F2C: nop

    // 0x80011F30: bc1f        L_80011F48
    if (!c1cs) {
        // 0x80011F34: nop
    
            goto L_80011F48;
    }
    // 0x80011F34: nop

    // 0x80011F38: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80011F3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80011F40: b           L_80011F54
    // 0x80011F44: sh          $t5, 0x68($t0)
    MEM_H(0X68, ctx->r8) = ctx->r13;
        goto L_80011F54;
    // 0x80011F44: sh          $t5, 0x68($t0)
    MEM_H(0X68, ctx->r8) = ctx->r13;
L_80011F48:
    // 0x80011F48: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011F4C: nop

    // 0x80011F50: sh          $zero, 0x68($t8)
    MEM_H(0X68, ctx->r24) = 0;
L_80011F54:
    // 0x80011F54: b           L_80011F5C
    // 0x80011F58: nop

        goto L_80011F5C;
    // 0x80011F58: nop

L_80011F5C:
    // 0x80011F5C: b           L_80011F6C
    // 0x80011F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011F6C;
    // 0x80011F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011F64: b           L_80011F6C
    // 0x80011F68: nop

        goto L_80011F6C;
    // 0x80011F68: nop

L_80011F6C:
    // 0x80011F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011F70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80011F74: jr          $ra
    // 0x80011F78: nop

    return;
    // 0x80011F78: nop

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
RECOMP_FUNC void func_800774B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800774B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800774BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800774C0: jal         0x80061348
    // 0x800774C4: addiu       $a0, $zero, 0x6B0
    ctx->r4 = ADD32(0, 0X6B0);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800774C4: addiu       $a0, $zero, 0x6B0
    ctx->r4 = ADD32(0, 0X6B0);
    after_0:
    // 0x800774C8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800774CC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800774D0: b           L_800774E0
    // 0x800774D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800774E0;
    // 0x800774D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800774D8: b           L_800774E0
    // 0x800774DC: nop

        goto L_800774E0;
    // 0x800774DC: nop

L_800774E0:
    // 0x800774E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800774E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800774E8: jr          $ra
    // 0x800774EC: nop

    return;
    // 0x800774EC: nop

;}
RECOMP_FUNC void func_80034310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80034314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034318: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003431C: lhu         $t6, 0x30C0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X30C0);
    // 0x80034320: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80034324: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80034328: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003432C: lw          $t8, -0x3FA8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3FA8);
    // 0x80034330: nop

    // 0x80034334: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80034338: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8003433C: nop

    // 0x80034340: jalr        $t9
    // 0x80034344: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80034344: nop

    after_0:
    // 0x80034348: b           L_80034350
    // 0x8003434C: nop

        goto L_80034350;
    // 0x8003434C: nop

L_80034350:
    // 0x80034350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034354: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80034358: jr          $ra
    // 0x8003435C: nop

    return;
    // 0x8003435C: nop

;}
RECOMP_FUNC void func_80066378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006637C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066380: jal         0x80061348
    // 0x80066384: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066384: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066388: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006638C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066390: beq         $v0, $zero, L_800663A8
    if (ctx->r2 == 0) {
        // 0x80066394: nop
    
            goto L_800663A8;
    }
    // 0x80066394: nop

    // 0x80066398: jal         0x80061348
    // 0x8006639C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006639C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x800663A0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800663A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800663A8:
    // 0x800663A8: b           L_800663B8
    // 0x800663AC: nop

        goto L_800663B8;
    // 0x800663AC: nop

    // 0x800663B0: b           L_800663B8
    // 0x800663B4: nop

        goto L_800663B8;
    // 0x800663B4: nop

L_800663B8:
    // 0x800663B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800663BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800663C0: jr          $ra
    // 0x800663C4: nop

    return;
    // 0x800663C4: nop

;}
RECOMP_FUNC void func_8008B600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B600: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008B604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B608: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008B60C: jal         0x80090754
    // 0x8008B610: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090754(rdram, ctx);
        goto after_0;
    // 0x8008B610: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8008B614: jal         0x80090728
    // 0x8008B618: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090728(rdram, ctx);
        goto after_1;
    // 0x8008B618: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x8008B61C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B620: addiu       $a0, $a0, -0xAB0
    ctx->r4 = ADD32(ctx->r4, -0XAB0);
    // 0x8008B624: jal         0x8008ECE4
    // 0x8008B628: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8008B628: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x8008B62C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8008B630: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8008B634: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008B638: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x8008B63C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8008B640: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8008B644:
    // 0x8008B644: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008B648: nop

    // 0x8008B64C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8008B650: nop

    // 0x8008B654: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x8008B658: beq         $t0, $zero, L_8008B6F0
    if (ctx->r8 == 0) {
        // 0x8008B65C: nop
    
            goto L_8008B6F0;
    }
    // 0x8008B65C: nop

    // 0x8008B660: andi        $t1, $t9, 0x4000
    ctx->r9 = ctx->r25 & 0X4000;
    // 0x8008B664: beq         $t1, $zero, L_8008B6F0
    if (ctx->r9 == 0) {
        // 0x8008B668: nop
    
            goto L_8008B6F0;
    }
    // 0x8008B668: nop

    // 0x8008B66C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008B670: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B674: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x8008B678: addiu       $t3, $zero, 0x22
    ctx->r11 = ADD32(0, 0X22);
    // 0x8008B67C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B680: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x8008B684: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008B688: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8008B68C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8008B690: jal         0x8008BE0C
    // 0x8008B694: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    func_8008BE0C(rdram, ctx);
        goto after_3;
    // 0x8008B694: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_3:
    // 0x8008B698: jal         0x8008ECE4
    // 0x8008B69C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8008B69C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x8008B6A0: addiu       $t4, $zero, 0x6E
    ctx->r12 = ADD32(0, 0X6E);
    // 0x8008B6A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B6A8: sw          $t4, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r12;
    // 0x8008B6AC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8008B6B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B6B4: lhu         $a1, 0x10($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X10);
    // 0x8008B6B8: jal         0x8008ECE4
    // 0x8008B6BC: addiu       $a0, $a0, -0xAAC
    ctx->r4 = ADD32(ctx->r4, -0XAAC);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8008B6BC: addiu       $a0, $a0, -0xAAC
    ctx->r4 = ADD32(ctx->r4, -0XAAC);
    after_5:
    // 0x8008B6C0: addiu       $t6, $zero, 0x76
    ctx->r14 = ADD32(0, 0X76);
    // 0x8008B6C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B6C8: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x8008B6CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008B6D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B6D4: addiu       $t8, $t7, 0xF
    ctx->r24 = ADD32(ctx->r15, 0XF);
    // 0x8008B6D8: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x8008B6DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8008B6E0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B6E4: lbu         $a1, 0x12($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X12);
    // 0x8008B6E8: jal         0x8008ECE4
    // 0x8008B6EC: addiu       $a0, $a0, -0xAA8
    ctx->r4 = ADD32(ctx->r4, -0XAA8);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8008B6EC: addiu       $a0, $a0, -0xAA8
    ctx->r4 = ADD32(ctx->r4, -0XAA8);
    after_6:
L_8008B6F0:
    // 0x8008B6F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008B6F4: nop

    // 0x8008B6F8: addiu       $t1, $t9, 0x30
    ctx->r9 = ADD32(ctx->r25, 0X30);
    // 0x8008B6FC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8008B700: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B704: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8008B708: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008B70C: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x8008B710: addiu       $t5, $t4, 0x16
    ctx->r13 = ADD32(ctx->r12, 0X16);
    // 0x8008B714: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8008B718: bne         $at, $zero, L_8008B644
    if (ctx->r1 != 0) {
        // 0x8008B71C: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8008B644;
    }
    // 0x8008B71C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8008B720: b           L_8008B728
    // 0x8008B724: nop

        goto L_8008B728;
    // 0x8008B724: nop

L_8008B728:
    // 0x8008B728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B72C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008B730: jr          $ra
    // 0x8008B734: nop

    return;
    // 0x8008B734: nop

;}
RECOMP_FUNC void func_8006BB98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BB9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BBA0: jal         0x80061488
    // 0x8006BBA4: addiu       $a0, $zero, 0x39A
    ctx->r4 = ADD32(0, 0X39A);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006BBA4: addiu       $a0, $zero, 0x39A
    ctx->r4 = ADD32(0, 0X39A);
    after_0:
    // 0x8006BBA8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006BBAC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006BBB0: b           L_8006BBC0
    // 0x8006BBB4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006BBC0;
    // 0x8006BBB4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006BBB8: b           L_8006BBC0
    // 0x8006BBBC: nop

        goto L_8006BBC0;
    // 0x8006BBBC: nop

L_8006BBC0:
    // 0x8006BBC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BBC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BBC8: jr          $ra
    // 0x8006BBCC: nop

    return;
    // 0x8006BBCC: nop

;}
RECOMP_FUNC void func_8007661C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007661C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076620: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076624: nop

    // 0x80076628: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8007662C: nop

    // 0x80076630: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076634: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076638: jr          $ra
    // 0x8007663C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007663C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076640: jr          $ra
    // 0x80076644: nop

    return;
    // 0x80076644: nop

    // 0x80076648: jr          $ra
    // 0x8007664C: nop

    return;
    // 0x8007664C: nop

;}
RECOMP_FUNC void func_800739B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800739B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800739BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800739C0: nop

    // 0x800739C4: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800739C8: nop

    // 0x800739CC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800739D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800739D4: jr          $ra
    // 0x800739D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800739D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800739DC: jr          $ra
    // 0x800739E0: nop

    return;
    // 0x800739E0: nop

    // 0x800739E4: jr          $ra
    // 0x800739E8: nop

    return;
    // 0x800739E8: nop

;}
RECOMP_FUNC void func_8002BE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BE00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002BE04: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002BE08: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8002BE0C: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002BE10: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002BE14: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BE1C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002BE20: nop

    // 0x8002BE24: sh          $t7, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r15;
    // 0x8002BE28: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE2C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002BE30: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8002BE34: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002BE38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002BE3C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002BE40: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002BE44: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002BE48: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002BE4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BE50: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002BE54: swc1        $f16, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f16.u32l;
    // 0x8002BE58: bc1f        L_8002BE8C
    if (!c1cs) {
        // 0x8002BE5C: nop
    
            goto L_8002BE8C;
    }
    // 0x8002BE5C: nop

    // 0x8002BE60: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8002BE64: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002BE68: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002BE6C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002BE70: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002BE74: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002BE78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BE7C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002BE80: swc1        $f16, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f16.u32l;
    // 0x8002BE84: b           L_8002BEB8
    // 0x8002BE88: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
        goto L_8002BEB8;
    // 0x8002BE88: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_8002BE8C:
    // 0x8002BE8C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE90: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002BE94: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8002BE98: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002BE9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002BEA0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002BEA4: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002BEA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BEAC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002BEB0: swc1        $f10, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f10.u32l;
    // 0x8002BEB4: neg.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = -ctx->f10.fl;
L_8002BEB8:
    // 0x8002BEB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002BEBC: lwc1        $f19, -0x1908($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1908);
    // 0x8002BEC0: lwc1        $f18, -0x1904($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1904);
    // 0x8002BEC4: cvt.d.s     $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f16.d = CVT_D_S(ctx->f20.fl);
    // 0x8002BEC8: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8002BECC: nop

    // 0x8002BED0: bc1f        L_8002BEE8
    if (!c1cs) {
        // 0x8002BED4: nop
    
            goto L_8002BEE8;
    }
    // 0x8002BED4: nop

    // 0x8002BED8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002BEDC: lwc1        $f4, -0x1900($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1900);
    // 0x8002BEE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BEE4: swc1        $f4, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f4.u32l;
L_8002BEE8:
    // 0x8002BEE8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8002BEEC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002BEF0: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8002BEF4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002BEF8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002BEFC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002BF00: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8002BF04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF08: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002BF0C: swc1        $f18, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f18.u32l;
    // 0x8002BF10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF14: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002BF18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002BF1C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8002BF20: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8002BF24: addiu       $t1, $t1, 0x3090
    ctx->r9 = ADD32(ctx->r9, 0X3090);
    // 0x8002BF28: lw          $a3, 0x1618($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1618);
    // 0x8002BF2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002BF30: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002BF34: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8002BF38: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002BF3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002BF40: jal         0x800C3D70
    // 0x8002BF44: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_0;
    // 0x8002BF44: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8002BF48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002BF4C: lwc1        $f8, 0x30A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002BF50: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8002BF54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002BF58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002BF5C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002BF60: swc1        $f16, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f16.u32l;
    // 0x8002BF64: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8002BF68: jal         0x800299C4
    // 0x8002BF6C: nop

    func_800299C4(rdram, ctx);
        goto after_1;
    // 0x8002BF6C: nop

    after_1:
    // 0x8002BF70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002BF74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF78: sh          $t2, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = ctx->r10;
    // 0x8002BF7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002BF80: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002BF84: jal         0x8002BB04
    // 0x8002BF88: nop

    func_8002BB04(rdram, ctx);
        goto after_2;
    // 0x8002BF88: nop

    after_2:
    // 0x8002BF8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF90: swc1        $f0, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f0.u32l;
    // 0x8002BF94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002BF98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF9C: swc1        $f18, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f18.u32l;
    // 0x8002BFA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BFA4: swc1        $f18, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f18.u32l;
    // 0x8002BFA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BFAC: swc1        $f18, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f18.u32l;
    // 0x8002BFB0: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002BFB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BFB8: sh          $t3, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r11;
    // 0x8002BFBC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002BFC0: lh          $t4, 0x1644($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X1644);
    // 0x8002BFC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002BFC8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8002BFCC: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8002BFD0: lhu         $a0, -0x4772($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4772);
    // 0x8002BFD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002BFD8: jal         0x800AFB70
    // 0x8002BFDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_3;
    // 0x8002BFDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8002BFE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002BFE4: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x8002BFE8: b           L_8002BFF0
    // 0x8002BFEC: nop

        goto L_8002BFF0;
    // 0x8002BFEC: nop

L_8002BFF0:
    // 0x8002BFF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002BFF4: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002BFF8: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002BFFC: jr          $ra
    // 0x8002C000: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002C000: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800690C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800690C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800690CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800690D0: jal         0x80061348
    // 0x800690D4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800690D4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x800690D8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800690DC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800690E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800690E4: beq         $v0, $zero, L_80069124
    if (ctx->r2 == 0) {
        // 0x800690E8: nop
    
            goto L_80069124;
    }
    // 0x800690E8: nop

    // 0x800690EC: jal         0x80061348
    // 0x800690F0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800690F0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x800690F4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800690F8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800690FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069100: beq         $v0, $zero, L_80069124
    if (ctx->r2 == 0) {
        // 0x80069104: nop
    
            goto L_80069124;
    }
    // 0x80069104: nop

    // 0x80069108: jal         0x80061348
    // 0x8006910C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006910C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x80069110: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069114: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069118: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006911C: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x80069120: nop
    
            goto L_80069368;
    }
    // 0x80069120: nop

L_80069124:
    // 0x80069124: jal         0x80061348
    // 0x80069128: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80069128: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006912C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069130: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069134: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069138: beq         $v0, $zero, L_80069178
    if (ctx->r2 == 0) {
        // 0x8006913C: nop
    
            goto L_80069178;
    }
    // 0x8006913C: nop

    // 0x80069140: jal         0x80061348
    // 0x80069144: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x80069144: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x80069148: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006914C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069150: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069154: beq         $v0, $zero, L_80069178
    if (ctx->r2 == 0) {
        // 0x80069158: nop
    
            goto L_80069178;
    }
    // 0x80069158: nop

    // 0x8006915C: jal         0x80061348
    // 0x80069160: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x80069160: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x80069164: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069168: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006916C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069170: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x80069174: nop
    
            goto L_80069368;
    }
    // 0x80069174: nop

L_80069178:
    // 0x80069178: jal         0x80061348
    // 0x8006917C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006917C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x80069180: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069184: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069188: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006918C: beq         $v0, $zero, L_800691CC
    if (ctx->r2 == 0) {
        // 0x80069190: nop
    
            goto L_800691CC;
    }
    // 0x80069190: nop

    // 0x80069194: jal         0x80061348
    // 0x80069198: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x80069198: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006919C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x800691A0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800691A4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800691A8: beq         $v0, $zero, L_800691CC
    if (ctx->r2 == 0) {
        // 0x800691AC: nop
    
            goto L_800691CC;
    }
    // 0x800691AC: nop

    // 0x800691B0: jal         0x80061348
    // 0x800691B4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x800691B4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x800691B8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x800691BC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x800691C0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800691C4: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x800691C8: nop
    
            goto L_80069368;
    }
    // 0x800691C8: nop

L_800691CC:
    // 0x800691CC: jal         0x80061348
    // 0x800691D0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x800691D0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x800691D4: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x800691D8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x800691DC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800691E0: beq         $v0, $zero, L_80069220
    if (ctx->r2 == 0) {
        // 0x800691E4: nop
    
            goto L_80069220;
    }
    // 0x800691E4: nop

    // 0x800691E8: jal         0x80061348
    // 0x800691EC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x800691EC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x800691F0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800691F4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800691F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800691FC: beq         $v0, $zero, L_80069220
    if (ctx->r2 == 0) {
        // 0x80069200: nop
    
            goto L_80069220;
    }
    // 0x80069200: nop

    // 0x80069204: jal         0x80061348
    // 0x80069208: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x80069208: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006920C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069210: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069218: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x8006921C: nop
    
            goto L_80069368;
    }
    // 0x8006921C: nop

L_80069220:
    // 0x80069220: jal         0x80061348
    // 0x80069224: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x80069224: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x80069228: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006922C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069230: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069234: beq         $v0, $zero, L_80069274
    if (ctx->r2 == 0) {
        // 0x80069238: nop
    
            goto L_80069274;
    }
    // 0x80069238: nop

    // 0x8006923C: jal         0x80061348
    // 0x80069240: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x80069240: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x80069244: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069248: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006924C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069250: beq         $v0, $zero, L_80069274
    if (ctx->r2 == 0) {
        // 0x80069254: nop
    
            goto L_80069274;
    }
    // 0x80069254: nop

    // 0x80069258: jal         0x80061348
    // 0x8006925C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006925C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x80069260: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80069264: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069268: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006926C: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x80069270: nop
    
            goto L_80069368;
    }
    // 0x80069270: nop

L_80069274:
    // 0x80069274: jal         0x80061348
    // 0x80069278: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x80069278: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006927C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069280: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069284: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069288: beq         $v0, $zero, L_800692C8
    if (ctx->r2 == 0) {
        // 0x8006928C: nop
    
            goto L_800692C8;
    }
    // 0x8006928C: nop

    // 0x80069290: jal         0x80061348
    // 0x80069294: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069294: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069298: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006929C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x800692A0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800692A4: beq         $v0, $zero, L_800692C8
    if (ctx->r2 == 0) {
        // 0x800692A8: nop
    
            goto L_800692C8;
    }
    // 0x800692A8: nop

    // 0x800692AC: jal         0x80061348
    // 0x800692B0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x800692B0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x800692B4: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x800692B8: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800692BC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800692C0: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x800692C4: nop
    
            goto L_80069368;
    }
    // 0x800692C4: nop

L_800692C8:
    // 0x800692C8: jal         0x80061348
    // 0x800692CC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x800692CC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x800692D0: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x800692D4: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x800692D8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800692DC: beq         $v0, $zero, L_8006931C
    if (ctx->r2 == 0) {
        // 0x800692E0: nop
    
            goto L_8006931C;
    }
    // 0x800692E0: nop

    // 0x800692E4: jal         0x80061348
    // 0x800692E8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x800692E8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x800692EC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x800692F0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x800692F4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800692F8: beq         $v0, $zero, L_8006931C
    if (ctx->r2 == 0) {
        // 0x800692FC: nop
    
            goto L_8006931C;
    }
    // 0x800692FC: nop

    // 0x80069300: jal         0x80061348
    // 0x80069304: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x80069304: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x80069308: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006930C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069310: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069314: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x80069318: nop
    
            goto L_80069368;
    }
    // 0x80069318: nop

L_8006931C:
    // 0x8006931C: jal         0x80061348
    // 0x80069320: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x80069320: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x80069324: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069328: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006932C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069330: beq         $v0, $zero, L_80069368
    if (ctx->r2 == 0) {
        // 0x80069334: nop
    
            goto L_80069368;
    }
    // 0x80069334: nop

    // 0x80069338: jal         0x80061348
    // 0x8006933C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006933C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x80069340: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069344: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069348: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006934C: beq         $v0, $zero, L_80069368
    if (ctx->r2 == 0) {
        // 0x80069350: nop
    
            goto L_80069368;
    }
    // 0x80069350: nop

    // 0x80069354: jal         0x80061348
    // 0x80069358: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x80069358: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006935C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069360: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069364: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80069368:
    // 0x80069368: b           L_80069378
    // 0x8006936C: nop

        goto L_80069378;
    // 0x8006936C: nop

    // 0x80069370: b           L_80069378
    // 0x80069374: nop

        goto L_80069378;
    // 0x80069374: nop

L_80069378:
    // 0x80069378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006937C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069380: jr          $ra
    // 0x80069384: nop

    return;
    // 0x80069384: nop

;}
RECOMP_FUNC void func_80062678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062678: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006267C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062680: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80062684: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80062688: nop

    // 0x8006268C: slti        $at, $t6, 0x2710
    ctx->r1 = SIGNED(ctx->r14) < 0X2710 ? 1 : 0;
    // 0x80062690: beq         $at, $zero, L_800626B4
    if (ctx->r1 == 0) {
        // 0x80062694: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_800626B4;
    }
    // 0x80062694: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80062698: lui         $t7, 0x809D
    ctx->r15 = S32(0X809D << 16);
    // 0x8006269C: addiu       $t7, $t7, 0x7B0
    ctx->r15 = ADD32(ctx->r15, 0X7B0);
    // 0x800626A0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800626A4: lui         $t8, 0x809B
    ctx->r24 = S32(0X809B << 16);
    // 0x800626A8: addiu       $t8, $t8, 0x4200
    ctx->r24 = ADD32(ctx->r24, 0X4200);
    // 0x800626AC: b           L_800626DC
    // 0x800626B0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_800626DC;
    // 0x800626B0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_800626B4:
    // 0x800626B4: lui         $t9, 0x809D
    ctx->r25 = S32(0X809D << 16);
    // 0x800626B8: addiu       $t9, $t9, 0x45E0
    ctx->r25 = ADD32(ctx->r25, 0X45E0);
    // 0x800626BC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800626C0: lui         $t0, 0x809D
    ctx->r8 = S32(0X809D << 16);
    // 0x800626C4: addiu       $t0, $t0, 0x3920
    ctx->r8 = ADD32(ctx->r8, 0X3920);
    // 0x800626C8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800626CC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800626D0: nop

    // 0x800626D4: addiu       $t2, $t1, -0x2710
    ctx->r10 = ADD32(ctx->r9, -0X2710);
    // 0x800626D8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_800626DC:
    // 0x800626DC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800626E0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x800626E4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x800626E8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800626EC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800626F0: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800626F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800626F8: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x800626FC: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    // 0x80062700: jal         0x80096B38
    // 0x80062704: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_80096B38(rdram, ctx);
        goto after_0;
    // 0x80062704: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_0:
    // 0x80062708: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8006270C: jal         0x80031AC8
    // 0x80062710: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x80062710: nop

    after_1:
    // 0x80062714: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80062718: bne         $v0, $at, L_80062728
    if (ctx->r2 != ctx->r1) {
        // 0x8006271C: nop
    
            goto L_80062728;
    }
    // 0x8006271C: nop

    // 0x80062720: jal         0x80031874
    // 0x80062724: nop

    func_80031874(rdram, ctx);
        goto after_2;
    // 0x80062724: nop

    after_2:
L_80062728:
    // 0x80062728: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006272C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80062730: jal         0x80096C6C
    // 0x80062734: nop

    func_80096C6C(rdram, ctx);
        goto after_3;
    // 0x80062734: nop

    after_3:
    // 0x80062738: b           L_80062740
    // 0x8006273C: nop

        goto L_80062740;
    // 0x8006273C: nop

L_80062740:
    // 0x80062740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062744: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80062748: jr          $ra
    // 0x8006274C: nop

    return;
    // 0x8006274C: nop

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
RECOMP_FUNC void func_80068510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068510: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068514: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068518: nop

    // 0x8006851C: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x80068520: nop

    // 0x80068524: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80068528: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006852C: jr          $ra
    // 0x80068530: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068530: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068534: jr          $ra
    // 0x80068538: nop

    return;
    // 0x80068538: nop

    // 0x8006853C: jr          $ra
    // 0x80068540: nop

    return;
    // 0x80068540: nop

;}
RECOMP_FUNC void func_80065918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006591C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065920: jal         0x80061488
    // 0x80065924: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065924: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    after_0:
    // 0x80065928: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006592C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80065930: b           L_80065940
    // 0x80065934: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065940;
    // 0x80065934: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065938: b           L_80065940
    // 0x8006593C: nop

        goto L_80065940;
    // 0x8006593C: nop

L_80065940:
    // 0x80065940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065948: jr          $ra
    // 0x8006594C: nop

    return;
    // 0x8006594C: nop

;}
RECOMP_FUNC void func_80034230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034230: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80034234: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80034238: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003423C: nop

    // 0x80034240: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x80034244: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80034248: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8003424C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80034250: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80034254: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80034258: nop

    // 0x8003425C: bc1f        L_800342A0
    if (!c1cs) {
        // 0x80034260: nop
    
            goto L_800342A0;
    }
    // 0x80034260: nop

    // 0x80034264: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80034268: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8003426C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80034270: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80034274: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80034278: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003427C: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80034280: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x80034284: bc1f        L_80034298
    if (!c1cs) {
        // 0x80034288: nop
    
            goto L_80034298;
    }
    // 0x80034288: nop

    // 0x8003428C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80034290: nop

    // 0x80034294: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
L_80034298:
    // 0x80034298: b           L_800342F4
    // 0x8003429C: nop

        goto L_800342F4;
    // 0x8003429C: nop

L_800342A0:
    // 0x800342A0: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800342A4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800342A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800342AC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800342B0: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x800342B4: nop

    // 0x800342B8: bc1f        L_800342F4
    if (!c1cs) {
        // 0x800342BC: nop
    
            goto L_800342F4;
    }
    // 0x800342BC: nop

    // 0x800342C0: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800342C4: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800342C8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800342CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800342D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800342D4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800342D8: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x800342DC: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800342E0: bc1f        L_800342F4
    if (!c1cs) {
        // 0x800342E4: nop
    
            goto L_800342F4;
    }
    // 0x800342E4: nop

    // 0x800342E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800342EC: nop

    // 0x800342F0: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_800342F4:
    // 0x800342F4: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800342F8: nop

    // 0x800342FC: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80034300: b           L_80034308
    // 0x80034304: nop

        goto L_80034308;
    // 0x80034304: nop

L_80034308:
    // 0x80034308: jr          $ra
    // 0x8003430C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003430C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
