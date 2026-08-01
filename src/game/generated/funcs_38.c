#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8007755C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007755C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077560: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077564: nop

    // 0x80077568: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x8007756C: nop

    // 0x80077570: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077574: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077578: jr          $ra
    // 0x8007757C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007757C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077580: jr          $ra
    // 0x80077584: nop

    return;
    // 0x80077584: nop

    // 0x80077588: jr          $ra
    // 0x8007758C: nop

    return;
    // 0x8007758C: nop

;}
RECOMP_FUNC void func_80042D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042D9C: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80042DA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042DA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80042DA8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80042DAC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80042DB0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80042DB4: lw          $t6, 0x7214($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7214);
    // 0x80042DB8: nop

    // 0x80042DBC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80042DC0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80042DC4: nop

    // 0x80042DC8: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80042DCC: nop

    // 0x80042DD0: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x80042DD4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80042DD8: nop

    // 0x80042DDC: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80042DE0: nop

    // 0x80042DE4: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x80042DE8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80042DEC: nop

    // 0x80042DF0: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80042DF4: nop

    // 0x80042DF8: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x80042DFC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80042E00: nop

    // 0x80042E04: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80042E08: nop

    // 0x80042E0C: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x80042E10: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80042E14: nop

    // 0x80042E18: lwc1        $f16, 0x10($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X10);
    // 0x80042E1C: nop

    // 0x80042E20: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x80042E24: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80042E28: nop

    // 0x80042E2C: lwc1        $f18, 0x14($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80042E30: nop

    // 0x80042E34: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80042E38: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80042E3C: nop

    // 0x80042E40: lwc1        $f4, 0x18($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80042E44: nop

    // 0x80042E48: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x80042E4C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80042E50: nop

    // 0x80042E54: lwc1        $f6, 0x1C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80042E58: nop

    // 0x80042E5C: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x80042E60: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80042E64: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80042E68: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x80042E6C: nop

    // 0x80042E70: sh          $t6, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r14;
    // 0x80042E74: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80042E78: lhu         $s0, -0x73C8($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X73C8);
    // 0x80042E7C: nop

    // 0x80042E80: beq         $s0, $zero, L_80042EA8
    if (ctx->r16 == 0) {
        // 0x80042E84: nop
    
            goto L_80042EA8;
    }
    // 0x80042E84: nop

    // 0x80042E88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042E8C: beq         $s0, $at, L_80042F80
    if (ctx->r16 == ctx->r1) {
        // 0x80042E90: nop
    
            goto L_80042F80;
    }
    // 0x80042E90: nop

    // 0x80042E94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80042E98: beq         $s0, $at, L_80043128
    if (ctx->r16 == ctx->r1) {
        // 0x80042E9C: nop
    
            goto L_80043128;
    }
    // 0x80042E9C: nop

    // 0x80042EA0: b           L_80043224
    // 0x80042EA4: nop

        goto L_80043224;
    // 0x80042EA4: nop

L_80042EA8:
    // 0x80042EA8: jal         0x800C1850
    // 0x80042EAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_0;
    // 0x80042EAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80042EB0: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80042EB4: jal         0x800C25B8
    // 0x80042EB8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_1;
    // 0x80042EB8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80042EBC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80042EC0: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x80042EC4: nop

    // 0x80042EC8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80042ECC: bgez        $t7, L_80042EE8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80042ED0: cvt.d.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
            goto L_80042EE8;
    }
    // 0x80042ED0: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80042ED4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80042ED8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80042EDC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80042EE0: nop

    // 0x80042EE4: add.d       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f10.d + ctx->f16.d;
L_80042EE8:
    // 0x80042EE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80042EEC: lwc1        $f19, -0x1278($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1278);
    // 0x80042EF0: lwc1        $f18, -0x1274($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1274);
    // 0x80042EF4: nop

    // 0x80042EF8: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80042EFC: jal         0x800C3338
    // 0x80042F00: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_2;
    // 0x80042F00: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_2:
    // 0x80042F04: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80042F08: lwc1        $f12, -0x1270($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1270);
    // 0x80042F0C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80042F10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80042F14: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80042F18: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80042F1C: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80042F20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80042F24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80042F28: jal         0x800C2304
    // 0x80042F2C: add.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f16.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_3;
    // 0x80042F2C: add.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f16.fl;
    after_3:
    // 0x80042F30: jal         0x800B1844
    // 0x80042F34: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_800B1844(rdram, ctx);
        goto after_4;
    // 0x80042F34: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_4:
    // 0x80042F38: jal         0x800C1850
    // 0x80042F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_5;
    // 0x80042F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80042F40: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80042F44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80042F48: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80042F4C: jal         0x800C25B8
    // 0x80042F50: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_6;
    // 0x80042F50: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_6:
    // 0x80042F54: addiu       $t8, $sp, 0x88
    ctx->r24 = ADD32(ctx->r29, 0X88);
    // 0x80042F58: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80042F5C: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80042F60: lwc1        $f14, 0x4($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80042F64: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80042F68: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80042F6C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80042F70: jal         0x800C2304
    // 0x80042F74: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_7;
    // 0x80042F74: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_7:
    // 0x80042F78: b           L_80043224
    // 0x80042F7C: nop

        goto L_80043224;
    // 0x80042F7C: nop

L_80042F80:
    // 0x80042F80: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80042F84: lhu         $t9, 0x70E0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X70E0);
    // 0x80042F88: nop

    // 0x80042F8C: beq         $t9, $zero, L_80042FDC
    if (ctx->r25 == 0) {
        // 0x80042F90: nop
    
            goto L_80042FDC;
    }
    // 0x80042F90: nop

    // 0x80042F94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042F98: lwc1        $f8, 0x50D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80042F9C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80042FA0: lwc1        $f11, -0x1268($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1268);
    // 0x80042FA4: lwc1        $f10, -0x1264($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1264);
    // 0x80042FA8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80042FAC: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x80042FB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042FB4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80042FB8: swc1        $f4, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f4.u32l;
    // 0x80042FBC: jal         0x800C3070
    // 0x80042FC0: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    MathUtil_Sinf(rdram, ctx);
        goto after_8;
    // 0x80042FC0: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    after_8:
    // 0x80042FC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80042FC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80042FCC: nop

    // 0x80042FD0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80042FD4: b           L_80042FE8
    // 0x80042FD8: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
        goto L_80042FE8;
    // 0x80042FD8: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
L_80042FDC:
    // 0x80042FDC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80042FE0: nop

    // 0x80042FE4: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
L_80042FE8:
    // 0x80042FE8: jal         0x800C1850
    // 0x80042FEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_9;
    // 0x80042FEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80042FF0: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80042FF4: jal         0x800C25B8
    // 0x80042FF8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_10;
    // 0x80042FF8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_10:
    // 0x80042FFC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043000: lwc1        $f12, -0x1260($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1260);
    // 0x80043004: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80043008: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004300C: jal         0x800C2304
    // 0x80043010: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_11;
    // 0x80043010: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
    // 0x80043014: jal         0x800B1844
    // 0x80043018: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_800B1844(rdram, ctx);
        goto after_12;
    // 0x80043018: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_12:
    // 0x8004301C: addiu       $t0, $sp, 0x88
    ctx->r8 = ADD32(ctx->r29, 0X88);
    // 0x80043020: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80043024: nop

    // 0x80043028: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x8004302C: addiu       $t1, $sp, 0x88
    ctx->r9 = ADD32(ctx->r29, 0X88);
    // 0x80043030: lwc1        $f18, 0x4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80043034: nop

    // 0x80043038: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
    // 0x8004303C: addiu       $t2, $sp, 0x88
    ctx->r10 = ADD32(ctx->r29, 0X88);
    // 0x80043040: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80043044: nop

    // 0x80043048: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
    // 0x8004304C: jal         0x800C1850
    // 0x80043050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_13;
    // 0x80043050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80043054: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80043058: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004305C: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80043060: nop

    // 0x80043064: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80043068: jal         0x800C25B8
    // 0x8004306C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_14;
    // 0x8004306C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_14:
    // 0x80043070: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043074: lwc1        $f12, -0x125C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X125C);
    // 0x80043078: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x8004307C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80043080: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80043084: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x80043088: lw          $a2, 0x50D0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X50D0);
    // 0x8004308C: jal         0x800C2304
    // 0x80043090: add.s       $f14, $f16, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f10.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_15;
    // 0x80043090: add.s       $f14, $f16, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f10.fl;
    after_15:
    // 0x80043094: jal         0x800B1844
    // 0x80043098: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_800B1844(rdram, ctx);
        goto after_16;
    // 0x80043098: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_16:
    // 0x8004309C: addiu       $t3, $sp, 0x88
    ctx->r11 = ADD32(ctx->r29, 0X88);
    // 0x800430A0: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800430A4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800430A8: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x800430AC: swc1        $f18, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f18.u32l;
    // 0x800430B0: addiu       $t5, $sp, 0x88
    ctx->r13 = ADD32(ctx->r29, 0X88);
    // 0x800430B4: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x800430B8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800430BC: addiu       $t6, $t6, 0x7158
    ctx->r14 = ADD32(ctx->r14, 0X7158);
    // 0x800430C0: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    // 0x800430C4: addiu       $t7, $sp, 0x88
    ctx->r15 = ADD32(ctx->r29, 0X88);
    // 0x800430C8: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800430CC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800430D0: addiu       $t8, $t8, 0x7158
    ctx->r24 = ADD32(ctx->r24, 0X7158);
    // 0x800430D4: swc1        $f6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f6.u32l;
    // 0x800430D8: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800430DC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800430E0: addiu       $t9, $t9, 0x7158
    ctx->r25 = ADD32(ctx->r25, 0X7158);
    // 0x800430E4: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
    // 0x800430E8: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800430EC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800430F0: addiu       $t0, $t0, 0x7158
    ctx->r8 = ADD32(ctx->r8, 0X7158);
    // 0x800430F4: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x800430F8: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800430FC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80043100: addiu       $t1, $t1, 0x7158
    ctx->r9 = ADD32(ctx->r9, 0X7158);
    // 0x80043104: swc1        $f10, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f10.u32l;
    // 0x80043108: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004310C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80043110: addiu       $a1, $a1, 0x7158
    ctx->r5 = ADD32(ctx->r5, 0X7158);
    // 0x80043114: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80043118: jal         0x800B1250
    // 0x8004311C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_17;
    // 0x8004311C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80043120: b           L_80043224
    // 0x80043124: nop

        goto L_80043224;
    // 0x80043124: nop

L_80043128:
    // 0x80043128: jal         0x800C1850
    // 0x8004312C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_18;
    // 0x8004312C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x80043130: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80043134: jal         0x800C25B8
    // 0x80043138: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_19;
    // 0x80043138: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_19:
    // 0x8004313C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043140: lwc1        $f12, -0x1258($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1258);
    // 0x80043144: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80043148: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004314C: jal         0x800C2304
    // 0x80043150: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_20;
    // 0x80043150: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_20:
    // 0x80043154: jal         0x800B1844
    // 0x80043158: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_800B1844(rdram, ctx);
        goto after_21;
    // 0x80043158: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_21:
    // 0x8004315C: addiu       $t2, $sp, 0x88
    ctx->r10 = ADD32(ctx->r29, 0X88);
    // 0x80043160: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80043164: nop

    // 0x80043168: swc1        $f18, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f18.u32l;
    // 0x8004316C: addiu       $t3, $sp, 0x88
    ctx->r11 = ADD32(ctx->r29, 0X88);
    // 0x80043170: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80043174: nop

    // 0x80043178: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x8004317C: addiu       $t4, $sp, 0x88
    ctx->r12 = ADD32(ctx->r29, 0X88);
    // 0x80043180: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80043184: nop

    // 0x80043188: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x8004318C: lui         $at, 0x4548
    ctx->r1 = S32(0X4548 << 16);
    // 0x80043190: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043194: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80043198: addiu       $t5, $t5, 0x7158
    ctx->r13 = ADD32(ctx->r13, 0X7158);
    // 0x8004319C: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x800431A0: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x800431A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800431A8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800431AC: addiu       $t6, $t6, 0x7158
    ctx->r14 = ADD32(ctx->r14, 0X7158);
    // 0x800431B0: swc1        $f16, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f16.u32l;
    // 0x800431B4: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x800431B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800431BC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800431C0: addiu       $t7, $t7, 0x7158
    ctx->r15 = ADD32(ctx->r15, 0X7158);
    // 0x800431C4: swc1        $f10, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f10.u32l;
    // 0x800431C8: addiu       $t8, $sp, 0x88
    ctx->r24 = ADD32(ctx->r29, 0X88);
    // 0x800431CC: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800431D0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800431D4: addiu       $t9, $t9, 0x7158
    ctx->r25 = ADD32(ctx->r25, 0X7158);
    // 0x800431D8: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x800431DC: addiu       $t0, $sp, 0x88
    ctx->r8 = ADD32(ctx->r29, 0X88);
    // 0x800431E0: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800431E4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800431E8: addiu       $t1, $t1, 0x7158
    ctx->r9 = ADD32(ctx->r9, 0X7158);
    // 0x800431EC: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x800431F0: addiu       $t2, $sp, 0x88
    ctx->r10 = ADD32(ctx->r29, 0X88);
    // 0x800431F4: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800431F8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800431FC: addiu       $t3, $t3, 0x7158
    ctx->r11 = ADD32(ctx->r11, 0X7158);
    // 0x80043200: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x80043204: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80043208: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8004320C: addiu       $a1, $a1, 0x7158
    ctx->r5 = ADD32(ctx->r5, 0X7158);
    // 0x80043210: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80043214: jal         0x800B1250
    // 0x80043218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_22;
    // 0x80043218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x8004321C: b           L_80043224
    // 0x80043220: nop

        goto L_80043224;
    // 0x80043220: nop

L_80043224:
    // 0x80043224: jal         0x800C1680
    // 0x80043228: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_23;
    // 0x80043228: nop

    after_23:
    // 0x8004322C: jal         0x800AD680
    // 0x80043230: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800AD680(rdram, ctx);
        goto after_24;
    // 0x80043230: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_24:
    // 0x80043234: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80043238: lw          $t4, -0x4CC4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CC4);
    // 0x8004323C: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80043240: addiu       $t5, $t4, 0x64
    ctx->r13 = ADD32(ctx->r12, 0X64);
    // 0x80043244: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80043248: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004324C: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    // 0x80043250: jal         0x800AF184
    // 0x80043254: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    func_800AF184(rdram, ctx);
        goto after_25;
    // 0x80043254: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    after_25:
    // 0x80043258: jal         0x800C1850
    // 0x8004325C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_26;
    // 0x8004325C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x80043260: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80043264: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80043268: jal         0x800AD1E4
    // 0x8004326C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_27;
    // 0x8004326C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_27:
    // 0x80043270: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80043274: lw          $t6, -0x4CCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CCC);
    // 0x80043278: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8004327C: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80043280: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80043284: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043288: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004328C: lwc1        $f14, -0x1254($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1254);
    // 0x80043290: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80043294: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80043298: jal         0x800C2304
    // 0x8004329C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_28;
    // 0x8004329C: nop

    after_28:
    // 0x800432A0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800432A4: lw          $t9, 0x1B44($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1B44);
    // 0x800432A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800432AC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800432B0: sw          $t0, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r8;
    // 0x800432B4: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800432B8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800432BC: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800432C0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800432C4: lui         $t3, 0x100
    ctx->r11 = S32(0X100 << 16);
    // 0x800432C8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800432CC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800432D0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800432D4: addiu       $t3, $t3, 0x158
    ctx->r11 = ADD32(ctx->r11, 0X158);
    // 0x800432D8: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800432DC: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800432E0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800432E4: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x800432E8: addiu       $a1, $a1, 0x2D8
    ctx->r5 = ADD32(ctx->r5, 0X2D8);
    // 0x800432EC: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800432F0: jal         0x800B18C4
    // 0x800432F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800B18C4(rdram, ctx);
        goto after_29;
    // 0x800432F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_29:
    // 0x800432F8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800432FC: lw          $t7, 0x7240($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7240);
    // 0x80043300: nop

    // 0x80043304: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80043308: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8004330C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80043310: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80043314: nop

    // 0x80043318: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8004331C: nop

    // 0x80043320: bc1f        L_800433C0
    if (!c1cs) {
        // 0x80043324: nop
    
            goto L_800433C0;
    }
    // 0x80043324: nop

    // 0x80043328: sh          $zero, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = 0;
L_8004332C:
    // 0x8004332C: jal         0x800C1850
    // 0x80043330: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_30;
    // 0x80043330: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_30:
    // 0x80043334: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80043338: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004333C: jal         0x800C25B8
    // 0x80043340: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_31;
    // 0x80043340: nop

    after_31:
    // 0x80043344: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80043348: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x8004334C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80043350: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80043354: jal         0x800C2304
    // 0x80043358: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_32;
    // 0x80043358: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_32:
    // 0x8004335C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80043360: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80043364: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80043368: jal         0x800C2948
    // 0x8004336C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_33;
    // 0x8004336C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_33:
    // 0x80043370: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80043374: lw          $t8, 0x722C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X722C);
    // 0x80043378: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8004337C: lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18);
    // 0x80043380: jal         0x800A42C8
    // 0x80043384: nop

    func_800A42C8(rdram, ctx);
        goto after_34;
    // 0x80043384: nop

    after_34:
    // 0x80043388: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004338C: nop

    // 0x80043390: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80043394: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80043398: lh          $t1, 0xC6($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XC6);
    // 0x8004339C: nop

    // 0x800433A0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800433A4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800433A8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800433AC: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x800433B0: bne         $at, $zero, L_8004332C
    if (ctx->r1 != 0) {
        // 0x800433B4: sh          $t2, 0xC6($sp)
        MEM_H(0XC6, ctx->r29) = ctx->r10;
            goto L_8004332C;
    }
    // 0x800433B4: sh          $t2, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = ctx->r10;
    // 0x800433B8: b           L_800433D0
    // 0x800433BC: nop

        goto L_800433D0;
    // 0x800433BC: nop

L_800433C0:
    // 0x800433C0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800433C4: nop

    // 0x800433C8: addiu       $t7, $t5, 0x50
    ctx->r15 = ADD32(ctx->r13, 0X50);
    // 0x800433CC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_800433D0:
    // 0x800433D0: sh          $zero, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = 0;
L_800433D4:
    // 0x800433D4: jal         0x800C1850
    // 0x800433D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_35;
    // 0x800433D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_35:
    // 0x800433DC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800433E0: nop

    // 0x800433E4: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800433E8: jal         0x800C25B8
    // 0x800433EC: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_36;
    // 0x800433EC: nop

    after_36:
    // 0x800433F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800433F4: lwc1        $f12, -0x1250($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1250);
    // 0x800433F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800433FC: lwc1        $f14, -0x124C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X124C);
    // 0x80043400: jal         0x800C2304
    // 0x80043404: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_37;
    // 0x80043404: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_37:
    // 0x80043408: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004340C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80043410: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80043414: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80043418: jal         0x800C2948
    // 0x8004341C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_38;
    // 0x8004341C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_38:
    // 0x80043420: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80043424: lw          $t8, 0x722C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X722C);
    // 0x80043428: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8004342C: lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18);
    // 0x80043430: jal         0x800A42C8
    // 0x80043434: nop

    func_800A42C8(rdram, ctx);
        goto after_39;
    // 0x80043434: nop

    after_39:
    // 0x80043438: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004343C: nop

    // 0x80043440: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80043444: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80043448: lh          $t1, 0xC6($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XC6);
    // 0x8004344C: nop

    // 0x80043450: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80043454: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80043458: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004345C: slti        $at, $t4, 0x11
    ctx->r1 = SIGNED(ctx->r12) < 0X11 ? 1 : 0;
    // 0x80043460: bne         $at, $zero, L_800433D4
    if (ctx->r1 != 0) {
        // 0x80043464: sh          $t2, 0xC6($sp)
        MEM_H(0XC6, ctx->r29) = ctx->r10;
            goto L_800433D4;
    }
    // 0x80043464: sh          $t2, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = ctx->r10;
    // 0x80043468: jal         0x800C1850
    // 0x8004346C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_40;
    // 0x8004346C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_40:
    // 0x80043470: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x80043474: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80043478: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004347C: jal         0x800C2304
    // 0x80043480: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_41;
    // 0x80043480: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_41:
    // 0x80043484: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043488: lwc1        $f12, -0x1248($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1248);
    // 0x8004348C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80043490: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80043494: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80043498: jal         0x800C2948
    // 0x8004349C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_42;
    // 0x8004349C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_42:
    // 0x800434A0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800434A4: lw          $t5, 0x722C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X722C);
    // 0x800434A8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800434AC: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800434B0: jal         0x800A42C8
    // 0x800434B4: nop

    func_800A42C8(rdram, ctx);
        goto after_43;
    // 0x800434B4: nop

    after_43:
    // 0x800434B8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800434BC: lhu         $t7, -0x73C8($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X73C8);
    // 0x800434C0: nop

    // 0x800434C4: beq         $t7, $zero, L_80043588
    if (ctx->r15 == 0) {
        // 0x800434C8: nop
    
            goto L_80043588;
    }
    // 0x800434C8: nop

    // 0x800434CC: jal         0x800C1850
    // 0x800434D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_44;
    // 0x800434D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_44:
    // 0x800434D4: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800434D8: jal         0x800C25B8
    // 0x800434DC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_45;
    // 0x800434DC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_45:
    // 0x800434E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800434E4: lw          $t6, 0x258C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X258C);
    // 0x800434E8: nop

    // 0x800434EC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800434F0: bgez        $t6, L_8004350C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800434F4: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_8004350C;
    }
    // 0x800434F4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800434F8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800434FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80043500: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80043504: nop

    // 0x80043508: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_8004350C:
    // 0x8004350C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043510: lwc1        $f17, -0x1240($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1240);
    // 0x80043514: lwc1        $f16, -0x123C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X123C);
    // 0x80043518: nop

    // 0x8004351C: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80043520: jal         0x800C3338
    // 0x80043524: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_46;
    // 0x80043524: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_46:
    // 0x80043528: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004352C: lwc1        $f12, -0x1238($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1238);
    // 0x80043530: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80043534: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80043538: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8004353C: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80043540: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80043544: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043548: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004354C: jal         0x800C2304
    // 0x80043550: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_47;
    // 0x80043550: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    after_47:
    // 0x80043554: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043558: lwc1        $f12, -0x1234($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1234);
    // 0x8004355C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043560: lwc1        $f14, -0x1230($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1230);
    // 0x80043564: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80043568: jal         0x800C2948
    // 0x8004356C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_48;
    // 0x8004356C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_48:
    // 0x80043570: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80043574: lw          $t8, 0x722C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X722C);
    // 0x80043578: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8004357C: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x80043580: jal         0x800A42C8
    // 0x80043584: nop

    func_800A42C8(rdram, ctx);
        goto after_49;
    // 0x80043584: nop

    after_49:
L_80043588:
    // 0x80043588: jal         0x800C1850
    // 0x8004358C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_50;
    // 0x8004358C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_50:
    // 0x80043590: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80043594: jal         0x800C25B8
    // 0x80043598: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_51;
    // 0x80043598: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_51:
    // 0x8004359C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800435A0: lw          $t9, 0x258C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X258C);
    // 0x800435A4: nop

    // 0x800435A8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800435AC: bgez        $t9, L_800435C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800435B0: cvt.d.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
            goto L_800435C8;
    }
    // 0x800435B0: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x800435B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800435B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800435BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800435C0: nop

    // 0x800435C4: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_800435C8:
    // 0x800435C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800435CC: lwc1        $f19, -0x1228($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1228);
    // 0x800435D0: lwc1        $f18, -0x1224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1224);
    // 0x800435D4: nop

    // 0x800435D8: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800435DC: jal         0x800C3070
    // 0x800435E0: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_52;
    // 0x800435E0: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_52:
    // 0x800435E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800435E8: lwc1        $f12, -0x1220($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1220);
    // 0x800435EC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800435F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800435F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800435F8: mul.s       $f6, $f20, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800435FC: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80043600: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80043604: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80043608: jal         0x800C2304
    // 0x8004360C: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_53;
    // 0x8004360C: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    after_53:
    // 0x80043610: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043614: lwc1        $f12, -0x121C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X121C);
    // 0x80043618: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004361C: lwc1        $f14, -0x1218($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1218);
    // 0x80043620: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80043624: jal         0x800C2948
    // 0x80043628: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_54;
    // 0x80043628: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_54:
    // 0x8004362C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80043630: lw          $t0, 0x722C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X722C);
    // 0x80043634: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80043638: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x8004363C: jal         0x800A42C8
    // 0x80043640: nop

    func_800A42C8(rdram, ctx);
        goto after_55;
    // 0x80043640: nop

    after_55:
    // 0x80043644: jal         0x800C1850
    // 0x80043648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_56;
    // 0x80043648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_56:
    // 0x8004364C: lwc1        $f12, 0xAC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80043650: jal         0x800C25B8
    // 0x80043654: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_57;
    // 0x80043654: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_57:
    // 0x80043658: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004365C: lw          $t1, 0x258C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X258C);
    // 0x80043660: nop

    // 0x80043664: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80043668: bgez        $t1, L_80043684
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8004366C: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_80043684;
    }
    // 0x8004366C: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80043670: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80043674: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80043678: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004367C: nop

    // 0x80043680: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_80043684:
    // 0x80043684: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043688: lwc1        $f9, -0x1210($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1210);
    // 0x8004368C: lwc1        $f8, -0x120C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X120C);
    // 0x80043690: nop

    // 0x80043694: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80043698: jal         0x800C3070
    // 0x8004369C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_58;
    // 0x8004369C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_58:
    // 0x800436A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800436A4: lwc1        $f12, -0x1208($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1208);
    // 0x800436A8: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800436AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800436B0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800436B4: mul.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x800436B8: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x800436BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800436C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800436C4: jal         0x800C2304
    // 0x800436C8: add.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f4.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_59;
    // 0x800436C8: add.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f4.fl;
    after_59:
    // 0x800436CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800436D0: lwc1        $f12, -0x1204($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1204);
    // 0x800436D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800436D8: lwc1        $f14, -0x1200($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1200);
    // 0x800436DC: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x800436E0: jal         0x800C2948
    // 0x800436E4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_60;
    // 0x800436E4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_60:
    // 0x800436E8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800436EC: lw          $t2, 0x722C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X722C);
    // 0x800436F0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800436F4: lw          $a0, 0x10($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X10);
    // 0x800436F8: jal         0x800A42C8
    // 0x800436FC: nop

    func_800A42C8(rdram, ctx);
        goto after_61;
    // 0x800436FC: nop

    after_61:
    // 0x80043700: jal         0x800C1850
    // 0x80043704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_62;
    // 0x80043704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_62:
    // 0x80043708: lwc1        $f12, 0xA8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8004370C: jal         0x800C25B8
    // 0x80043710: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_63;
    // 0x80043710: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_63:
    // 0x80043714: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80043718: lw          $t3, 0x258C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X258C);
    // 0x8004371C: nop

    // 0x80043720: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80043724: bgez        $t3, L_80043740
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80043728: cvt.d.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
            goto L_80043740;
    }
    // 0x80043728: cvt.d.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
    // 0x8004372C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80043730: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80043734: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80043738: nop

    // 0x8004373C: add.d       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f8.d + ctx->f6.d;
L_80043740:
    // 0x80043740: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043744: lwc1        $f11, -0x11F8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X11F8);
    // 0x80043748: lwc1        $f10, -0x11F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X11F4);
    // 0x8004374C: nop

    // 0x80043750: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80043754: jal         0x800C3070
    // 0x80043758: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_64;
    // 0x80043758: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_64:
    // 0x8004375C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043760: lwc1        $f12, -0x11F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X11F0);
    // 0x80043764: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80043768: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004376C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80043770: mul.s       $f18, $f20, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x80043774: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80043778: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004377C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80043780: jal         0x800C2304
    // 0x80043784: add.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f6.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_65;
    // 0x80043784: add.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f6.fl;
    after_65:
    // 0x80043788: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004378C: lwc1        $f12, -0x11EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X11EC);
    // 0x80043790: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043794: lwc1        $f14, -0x11E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X11E8);
    // 0x80043798: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x8004379C: jal         0x800C2948
    // 0x800437A0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_66;
    // 0x800437A0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_66:
    // 0x800437A4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800437A8: lw          $t4, 0x722C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X722C);
    // 0x800437AC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800437B0: lw          $a0, 0x14($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X14);
    // 0x800437B4: jal         0x800A42C8
    // 0x800437B8: nop

    func_800A42C8(rdram, ctx);
        goto after_67;
    // 0x800437B8: nop

    after_67:
    // 0x800437BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800437C0: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800437C4: lwc1        $f17, -0x11E0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X11E0);
    // 0x800437C8: lwc1        $f16, -0x11DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X11DC);
    // 0x800437CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800437D0: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x800437D4: nop

    // 0x800437D8: bc1f        L_80043884
    if (!c1cs) {
        // 0x800437DC: nop
    
            goto L_80043884;
    }
    // 0x800437DC: nop

    // 0x800437E0: jal         0x800C1850
    // 0x800437E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_68;
    // 0x800437E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_68:
    // 0x800437E8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800437EC: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x800437F0: nop

    // 0x800437F4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800437F8: bgez        $t5, L_80043814
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800437FC: cvt.d.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
            goto L_80043814;
    }
    // 0x800437FC: cvt.d.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
    // 0x80043800: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80043804: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80043808: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004380C: nop

    // 0x80043810: add.d       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f18.d + ctx->f6.d;
L_80043814:
    // 0x80043814: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043818: lwc1        $f9, -0x11D8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X11D8);
    // 0x8004381C: lwc1        $f8, -0x11D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X11D4);
    // 0x80043820: nop

    // 0x80043824: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80043828: jal         0x800C3070
    // 0x8004382C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_69;
    // 0x8004382C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_69:
    // 0x80043830: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043834: lwc1        $f12, -0x11D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X11D0);
    // 0x80043838: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004383C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80043840: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80043844: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80043848: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004384C: lwc1        $f6, -0x11CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X11CC);
    // 0x80043850: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80043854: jal         0x800C2304
    // 0x80043858: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_70;
    // 0x80043858: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_70:
    // 0x8004385C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80043860: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80043864: jal         0x800C25B8
    // 0x80043868: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_71;
    // 0x80043868: nop

    after_71:
    // 0x8004386C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80043870: lw          $t7, 0x722C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X722C);
    // 0x80043874: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80043878: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x8004387C: jal         0x800A42C8
    // 0x80043880: nop

    func_800A42C8(rdram, ctx);
        goto after_72;
    // 0x80043880: nop

    after_72:
L_80043884:
    // 0x80043884: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80043888: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004388C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043890: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80043894: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80043898: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004389C: mul.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x800438A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800438A4: lwc1        $f4, 0x50D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x800438A8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800438AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800438B0: sub.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d - ctx->f16.d;
    // 0x800438B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800438B8: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x800438BC: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x800438C0: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x800438C4: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x800438C8: bc1f        L_800438DC
    if (!c1cs) {
        // 0x800438CC: nop
    
            goto L_800438DC;
    }
    // 0x800438CC: nop

    // 0x800438D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800438D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800438D8: swc1        $f6, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f6.u32l;
L_800438DC:
    // 0x800438DC: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x800438E0: lhu         $s0, 0x70E0($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X70E0);
    // 0x800438E4: nop

    // 0x800438E8: beq         $s0, $zero, L_8004391C
    if (ctx->r16 == 0) {
        // 0x800438EC: nop
    
            goto L_8004391C;
    }
    // 0x800438EC: nop

    // 0x800438F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800438F4: beq         $s0, $at, L_8004397C
    if (ctx->r16 == ctx->r1) {
        // 0x800438F8: nop
    
            goto L_8004397C;
    }
    // 0x800438F8: nop

    // 0x800438FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80043900: beq         $s0, $at, L_800439D4
    if (ctx->r16 == ctx->r1) {
        // 0x80043904: nop
    
            goto L_800439D4;
    }
    // 0x80043904: nop

    // 0x80043908: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004390C: beq         $s0, $at, L_80043AD4
    if (ctx->r16 == ctx->r1) {
        // 0x80043910: nop
    
            goto L_80043AD4;
    }
    // 0x80043910: nop

    // 0x80043914: b           L_80043ADC
    // 0x80043918: nop

        goto L_80043ADC;
    // 0x80043918: nop

L_8004391C:
    // 0x8004391C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80043920: lwc1        $f16, 0x50C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80043924: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043928: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004392C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80043930: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80043934: swc1        $f18, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f18.u32l;
    // 0x80043938: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004393C: lwc1        $f5, -0x11C8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X11C8);
    // 0x80043940: lwc1        $f4, -0x11C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X11C4);
    // 0x80043944: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80043948: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8004394C: nop

    // 0x80043950: bc1f        L_80043974
    if (!c1cs) {
        // 0x80043954: nop
    
            goto L_80043974;
    }
    // 0x80043954: nop

    // 0x80043958: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004395C: lhu         $t6, 0x70E0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X70E0);
    // 0x80043960: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80043964: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80043968: sh          $t8, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r24;
    // 0x8004396C: jal         0x800B9000
    // 0x80043970: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800B9000(rdram, ctx);
        goto after_73;
    // 0x80043970: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_73:
L_80043974:
    // 0x80043974: b           L_80043ADC
    // 0x80043978: nop

        goto L_80043ADC;
    // 0x80043978: nop

L_8004397C:
    // 0x8004397C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043980: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80043984: lwc1        $f9, -0x11C0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X11C0);
    // 0x80043988: lwc1        $f8, -0x11BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X11BC);
    // 0x8004398C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80043990: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80043994: nop

    // 0x80043998: bc1f        L_800439CC
    if (!c1cs) {
        // 0x8004399C: nop
    
            goto L_800439CC;
    }
    // 0x8004399C: nop

    // 0x800439A0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800439A4: lhu         $t9, 0x70E0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X70E0);
    // 0x800439A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800439AC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800439B0: sh          $t0, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r8;
    // 0x800439B4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800439B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800439BC: sh          $t1, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r9;
    // 0x800439C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800439C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800439C8: swc1        $f18, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f18.u32l;
L_800439CC:
    // 0x800439CC: b           L_80043ADC
    // 0x800439D0: nop

        goto L_80043ADC;
    // 0x800439D0: nop

L_800439D4:
    // 0x800439D4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800439D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800439DC: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800439E0: nop

    // 0x800439E4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800439E8: nop

    // 0x800439EC: bc1f        L_80043ACC
    if (!c1cs) {
        // 0x800439F0: nop
    
            goto L_80043ACC;
    }
    // 0x800439F0: nop

    // 0x800439F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800439F8: lwc1        $f6, 0x50C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x800439FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043A00: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80043A04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80043A08: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80043A0C: swc1        $f8, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f8.u32l;
    // 0x80043A10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043A14: lwc1        $f11, -0x11B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X11B8);
    // 0x80043A18: lwc1        $f10, -0x11B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X11B4);
    // 0x80043A1C: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80043A20: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x80043A24: nop

    // 0x80043A28: bc1f        L_80043ACC
    if (!c1cs) {
        // 0x80043A2C: nop
    
            goto L_80043ACC;
    }
    // 0x80043A2C: nop

    // 0x80043A30: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80043A34: lhu         $t2, 0x70E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X70E0);
    // 0x80043A38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80043A3C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80043A40: sh          $t3, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r11;
    // 0x80043A44: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80043A48: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80043A4C: sw          $t4, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r12;
    // 0x80043A50: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80043A54: lh          $t5, 0x7254($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7254);
    // 0x80043A58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80043A5C: ori         $t7, $t5, 0x8000
    ctx->r15 = ctx->r13 | 0X8000;
    // 0x80043A60: sh          $t7, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r15;
    // 0x80043A64: jal         0x80021F20
    // 0x80043A68: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_74;
    // 0x80043A68: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_74:
    // 0x80043A6C: addiu       $t6, $zero, 0x3D
    ctx->r14 = ADD32(0, 0X3D);
    // 0x80043A70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80043A74: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
    // 0x80043A78: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80043A7C: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80043A80: nop

    // 0x80043A84: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80043A88: nop

    // 0x80043A8C: bc1f        L_80043ACC
    if (!c1cs) {
        // 0x80043A90: nop
    
            goto L_80043ACC;
    }
    // 0x80043A90: nop

    // 0x80043A94: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80043A98: nop

    // 0x80043A9C: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80043AA0: nop

    // 0x80043AA4: bc1f        L_80043ACC
    if (!c1cs) {
        // 0x80043AA8: nop
    
            goto L_80043ACC;
    }
    // 0x80043AA8: nop

    // 0x80043AAC: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80043AB0: nop

    // 0x80043AB4: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80043AB8: nop

    // 0x80043ABC: bc1f        L_80043ACC
    if (!c1cs) {
        // 0x80043AC0: nop
    
            goto L_80043ACC;
    }
    // 0x80043AC0: nop

    // 0x80043AC4: jal         0x8005F0DC
    // 0x80043AC8: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    func_8005F0DC(rdram, ctx);
        goto after_75;
    // 0x80043AC8: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    after_75:
L_80043ACC:
    // 0x80043ACC: b           L_80043ADC
    // 0x80043AD0: nop

        goto L_80043ADC;
    // 0x80043AD0: nop

L_80043AD4:
    // 0x80043AD4: b           L_80043ADC
    // 0x80043AD8: nop

        goto L_80043ADC;
    // 0x80043AD8: nop

L_80043ADC:
    // 0x80043ADC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80043AE0: lhu         $t8, 0x70E0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X70E0);
    // 0x80043AE4: nop

    // 0x80043AE8: beq         $t8, $zero, L_80043C34
    if (ctx->r24 == 0) {
        // 0x80043AEC: nop
    
            goto L_80043C34;
    }
    // 0x80043AEC: nop

    // 0x80043AF0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80043AF4: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80043AF8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80043AFC: lhu         $t1, 0xFF4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XFF4);
    // 0x80043B00: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x80043B04: nop

    // 0x80043B08: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x80043B0C: beq         $t2, $zero, L_80043B24
    if (ctx->r10 == 0) {
        // 0x80043B10: nop
    
            goto L_80043B24;
    }
    // 0x80043B10: nop

    // 0x80043B14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043B18: lwc1        $f18, -0x11B0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X11B0);
    // 0x80043B1C: b           L_80043B30
    // 0x80043B20: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
        goto L_80043B30;
    // 0x80043B20: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
L_80043B24:
    // 0x80043B24: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80043B28: nop

    // 0x80043B2C: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
L_80043B30:
    // 0x80043B30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043B34: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80043B38: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80043B3C: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80043B40: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80043B44: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80043B48: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x80043B4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043B50: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80043B54: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80043B58: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80043B5C: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80043B60: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80043B64: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x80043B68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043B6C: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80043B70: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80043B74: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80043B78: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80043B7C: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80043B80: swc1        $f16, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f16.u32l;
    // 0x80043B84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043B88: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80043B8C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80043B90: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80043B94: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80043B98: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80043B9C: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x80043BA0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80043BA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043BA8: lh          $t4, 0x20($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X20);
    // 0x80043BAC: lwc1        $f19, -0x11A8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X11A8);
    // 0x80043BB0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80043BB4: lwc1        $f18, -0x11A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X11A4);
    // 0x80043BB8: cvt.d.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
    // 0x80043BBC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043BC0: lwc1        $f11, -0x11A0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X11A0);
    // 0x80043BC4: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80043BC8: lwc1        $f10, -0x119C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X119C);
    // 0x80043BCC: lwc1        $f12, 0xA4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80043BD0: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x80043BD4: jal         0x80042C60
    // 0x80043BD8: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    func_80042C60(rdram, ctx);
        goto after_76;
    // 0x80043BD8: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    after_76:
    // 0x80043BDC: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80043BE0: nop

    // 0x80043BE4: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80043BE8: swc1        $f4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f4.u32l;
    // 0x80043BEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043BF0: lwc1        $f14, -0x1198($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1198);
    // 0x80043BF4: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80043BF8: jal         0x80042C60
    // 0x80043BFC: nop

    func_80042C60(rdram, ctx);
        goto after_77;
    // 0x80043BFC: nop

    after_77:
    // 0x80043C00: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x80043C04: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043C08: lwc1        $f14, -0x1194($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1194);
    // 0x80043C0C: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80043C10: jal         0x80042C60
    // 0x80043C14: nop

    func_80042C60(rdram, ctx);
        goto after_78;
    // 0x80043C14: nop

    after_78:
    // 0x80043C18: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x80043C1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80043C20: lwc1        $f14, -0x1190($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1190);
    // 0x80043C24: lwc1        $f12, 0x98($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80043C28: jal         0x80042C60
    // 0x80043C2C: nop

    func_80042C60(rdram, ctx);
        goto after_79;
    // 0x80043C2C: nop

    after_79:
    // 0x80043C30: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
L_80043C34:
    // 0x80043C34: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80043C38: lhu         $t7, 0x10F2($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X10F2);
    // 0x80043C3C: lhu         $t5, 0x86($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X86);
    // 0x80043C40: nop

    // 0x80043C44: and         $t6, $t5, $t7
    ctx->r14 = ctx->r13 & ctx->r15;
    // 0x80043C48: beq         $t6, $zero, L_80043C90
    if (ctx->r14 == 0) {
        // 0x80043C4C: nop
    
            goto L_80043C90;
    }
    // 0x80043C4C: nop

    // 0x80043C50: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80043C54: lhu         $t8, 0x70E0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X70E0);
    // 0x80043C58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043C5C: bne         $t8, $at, L_80043C90
    if (ctx->r24 != ctx->r1) {
        // 0x80043C60: nop
    
            goto L_80043C90;
    }
    // 0x80043C60: nop

    // 0x80043C64: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80043C68: lhu         $t9, -0x73C8($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X73C8);
    // 0x80043C6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80043C70: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80043C74: sh          $t0, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r8;
    // 0x80043C78: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80043C7C: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80043C80: bne         $at, $zero, L_80043C90
    if (ctx->r1 != 0) {
        // 0x80043C84: nop
    
            goto L_80043C90;
    }
    // 0x80043C84: nop

    // 0x80043C88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80043C8C: sh          $zero, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = 0;
L_80043C90:
    // 0x80043C90: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80043C94: lhu         $t2, -0x73C8($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X73C8);
    // 0x80043C98: nop

    // 0x80043C9C: beq         $t2, $zero, L_80043CC4
    if (ctx->r10 == 0) {
        // 0x80043CA0: nop
    
            goto L_80043CC4;
    }
    // 0x80043CA0: nop

    // 0x80043CA4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80043CA8: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80043CAC: nop

    // 0x80043CB0: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80043CB4: nop

    // 0x80043CB8: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x80043CBC: b           L_80043D1C
    // 0x80043CC0: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
        goto L_80043D1C;
    // 0x80043CC0: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
L_80043CC4:
    // 0x80043CC4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80043CC8: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80043CCC: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80043CD0: lw          $t6, 0xC0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC0);
    // 0x80043CD4: nop

    // 0x80043CD8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80043CDC: sw          $t8, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r24;
    // 0x80043CE0: jal         0x800C1850
    // 0x80043CE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_80;
    // 0x80043CE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_80:
    // 0x80043CE8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80043CEC: addiu       $t9, $t9, 0x2618
    ctx->r25 = ADD32(ctx->r25, 0X2618);
    // 0x80043CF0: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x80043CF4: nop

    // 0x80043CF8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80043CFC: jal         0x8009A14C
    // 0x80043D00: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_8009A14C(rdram, ctx);
        goto after_81;
    // 0x80043D00: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_81:
    // 0x80043D04: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80043D08: jal         0x800C2780
    // 0x80043D0C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateZ(rdram, ctx);
        goto after_82;
    // 0x80043D0C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_82:
    // 0x80043D10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80043D14: jal         0x800997D8
    // 0x80043D18: nop

    func_800997D8(rdram, ctx);
        goto after_83;
    // 0x80043D18: nop

    after_83:
L_80043D1C:
    // 0x80043D1C: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80043D20: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80043D24: nop

    // 0x80043D28: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x80043D2C: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80043D30: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80043D34: nop

    // 0x80043D38: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x80043D3C: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80043D40: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80043D44: nop

    // 0x80043D48: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
    // 0x80043D4C: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80043D50: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80043D54: nop

    // 0x80043D58: swc1        $f6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f6.u32l;
    // 0x80043D5C: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80043D60: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80043D64: nop

    // 0x80043D68: swc1        $f16, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f16.u32l;
    // 0x80043D6C: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80043D70: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80043D74: nop

    // 0x80043D78: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x80043D7C: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80043D80: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80043D84: nop

    // 0x80043D88: swc1        $f18, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f18.u32l;
    // 0x80043D8C: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80043D90: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80043D94: nop

    // 0x80043D98: swc1        $f8, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f8.u32l;
    // 0x80043D9C: b           L_80043DA4
    // 0x80043DA0: nop

        goto L_80043DA4;
    // 0x80043DA0: nop

L_80043DA4:
    // 0x80043DA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80043DA8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80043DAC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80043DB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80043DB4: jr          $ra
    // 0x80043DB8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80043DB8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x80043DBC: nop

;}
RECOMP_FUNC void func_8000C584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C584: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000C588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C58C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000C590: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8000C594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C598: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000C59C: nop

    // 0x8000C5A0: slti        $at, $t6, 0x1F4
    ctx->r1 = SIGNED(ctx->r14) < 0X1F4 ? 1 : 0;
    // 0x8000C5A4: beq         $at, $zero, L_8000C5C8
    if (ctx->r1 == 0) {
        // 0x8000C5A8: nop
    
            goto L_8000C5C8;
    }
    // 0x8000C5A8: nop

    // 0x8000C5AC: lui         $t7, 0x8099
    ctx->r15 = S32(0X8099 << 16);
    // 0x8000C5B0: addiu       $t7, $t7, 0x20
    ctx->r15 = ADD32(ctx->r15, 0X20);
    // 0x8000C5B4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8000C5B8: lui         $t8, 0x8099
    ctx->r24 = S32(0X8099 << 16);
    // 0x8000C5BC: addiu       $t8, $t8, 0x180
    ctx->r24 = ADD32(ctx->r24, 0X180);
    // 0x8000C5C0: b           L_8000C5E0
    // 0x8000C5C4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_8000C5E0;
    // 0x8000C5C4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_8000C5C8:
    // 0x8000C5C8: lui         $t9, 0x8099
    ctx->r25 = S32(0X8099 << 16);
    // 0x8000C5CC: addiu       $t9, $t9, 0x73B0
    ctx->r25 = ADD32(ctx->r25, 0X73B0);
    // 0x8000C5D0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000C5D4: lui         $t0, 0x8099
    ctx->r8 = S32(0X8099 << 16);
    // 0x8000C5D8: addiu       $t0, $t0, 0x73D0
    ctx->r8 = ADD32(ctx->r8, 0X73D0);
    // 0x8000C5DC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
L_8000C5E0:
    // 0x8000C5E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C5E4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C5E8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C5EC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C5F0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8000C5F4: jal         0x800BD1FC
    // 0x8000C5F8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8000C5F8: nop

    after_0:
    // 0x8000C5FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000C604: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8000C608: jal         0x800BD218
    // 0x8000C60C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8000C60C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x8000C610: lh          $t1, 0x38($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X38);
    // 0x8000C614: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000C618: nop

    // 0x8000C61C: bne         $t1, $t2, L_8000C62C
    if (ctx->r9 != ctx->r10) {
        // 0x8000C620: nop
    
            goto L_8000C62C;
    }
    // 0x8000C620: nop

    // 0x8000C624: b           L_8000C64C
    // 0x8000C628: nop

        goto L_8000C64C;
    // 0x8000C628: nop

L_8000C62C:
    // 0x8000C62C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8000C630: nop

    // 0x8000C634: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8000C638: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8000C63C: lh          $t5, 0x38($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X38);
    // 0x8000C640: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C644: bne         $t5, $at, L_8000C5E0
    if (ctx->r13 != ctx->r1) {
        // 0x8000C648: nop
    
            goto L_8000C5E0;
    }
    // 0x8000C648: nop

L_8000C64C:
    // 0x8000C64C: lh          $t6, 0x38($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X38);
    // 0x8000C650: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C654: bne         $t6, $at, L_8000C664
    if (ctx->r14 != ctx->r1) {
        // 0x8000C658: nop
    
            goto L_8000C664;
    }
    // 0x8000C658: nop

    // 0x8000C65C: b           L_8000C768
    // 0x8000C660: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000C768;
    // 0x8000C660: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000C664:
    // 0x8000C664: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C668: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8000C66C: nop

    // 0x8000C670: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8000C674: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8000C678: nop

    // 0x8000C67C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8000C680: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8000C684: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C688: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C68C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C690: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C694: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8000C698: jal         0x800BD1FC
    // 0x8000C69C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8000C69C: nop

    after_2:
    // 0x8000C6A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000C6A8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8000C6AC: jal         0x800BD218
    // 0x8000C6B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8000C6B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x8000C6B4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C6B8: nop

    // 0x8000C6BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8000C6C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8000C6C4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000C6C8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8000C6CC: nop

    // 0x8000C6D0: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x8000C6D4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8000C6D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8000C6DC: jal         0x8000D164
    // 0x8000C6E0: nop

    TempHeap_Alloc(rdram, ctx);
        goto after_4;
    // 0x8000C6E0: nop

    after_4:
    // 0x8000C6E4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8000C6E8: nop

    // 0x8000C6EC: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    // 0x8000C6F0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8000C6F4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8000C6F8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000C6FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C700: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C704: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C708: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C70C: jal         0x800BD1FC
    // 0x8000C710: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8000C710: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    after_5:
    // 0x8000C714: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8000C718: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C71C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8000C720: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x8000C724: jal         0x800BD218
    // 0x8000C728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_6;
    // 0x8000C728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8000C72C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8000C730: nop

    // 0x8000C734: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8000C738: nop

    // 0x8000C73C: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x8000C740: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8000C744: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8000C748: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8000C74C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8000C750: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x8000C754: sw          $t8, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r24;
    // 0x8000C758: b           L_8000C768
    // 0x8000C75C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C768;
    // 0x8000C75C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C760: b           L_8000C768
    // 0x8000C764: nop

        goto L_8000C768;
    // 0x8000C764: nop

L_8000C768:
    // 0x8000C768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C76C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C770: jr          $ra
    // 0x8000C774: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000C774: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void alUnlink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7890: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C7894: beql        $v0, $zero, L_800C78A8
    if (ctx->r2 == 0) {
        // 0x800C7898: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800C78A8;
    }
    goto skip_0;
    // 0x800C7898: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800C789C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C78A0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C78A4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800C78A8:
    // 0x800C78A8: beq         $v0, $zero, L_800C78B8
    if (ctx->r2 == 0) {
        // 0x800C78AC: nop
    
            goto L_800C78B8;
    }
    // 0x800C78AC: nop

    // 0x800C78B0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800C78B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800C78B8:
    // 0x800C78B8: jr          $ra
    // 0x800C78BC: nop

    return;
    // 0x800C78BC: nop

;}
RECOMP_FUNC void func_800730F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800730F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800730F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800730F8: nop

    // 0x800730FC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073100: nop

    // 0x80073104: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073108: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007310C: jr          $ra
    // 0x80073110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073114: jr          $ra
    // 0x80073118: nop

    return;
    // 0x80073118: nop

    // 0x8007311C: jr          $ra
    // 0x80073120: nop

    return;
    // 0x80073120: nop

;}
RECOMP_FUNC void func_80077AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077AFC: jal         0x80061488
    // 0x80077B00: addiu       $a0, $zero, 0x56A
    ctx->r4 = ADD32(0, 0X56A);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077B00: addiu       $a0, $zero, 0x56A
    ctx->r4 = ADD32(0, 0X56A);
    after_0:
    // 0x80077B04: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80077B08: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077B0C: b           L_80077B1C
    // 0x80077B10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077B1C;
    // 0x80077B10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077B14: b           L_80077B1C
    // 0x80077B18: nop

        goto L_80077B1C;
    // 0x80077B18: nop

L_80077B1C:
    // 0x80077B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077B24: jr          $ra
    // 0x80077B28: nop

    return;
    // 0x80077B28: nop

;}
RECOMP_FUNC void func_800B749C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B749C: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x800B74A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B74A4: sw          $t6, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r14;
    // 0x800B74A8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800B74AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B74B0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800B74B4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B74B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B74BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B74C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B74C4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B74C8: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B74CC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B74D0: swc1        $f18, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f18.u32l;
    // 0x800B74D4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800B74D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B74DC: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
    // 0x800B74E0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B74E4: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x800B74E8: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x800B74EC: nop

    // 0x800B74F0: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x800B74F4: sh          $t1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r9;
    // 0x800B74F8: jr          $ra
    // 0x800B74FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B74FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80073E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073E7C: jal         0x80061348
    // 0x80073E80: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073E80: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073E84: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073E88: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073E8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073E90: beq         $v0, $zero, L_80073EE4
    if (ctx->r2 == 0) {
        // 0x80073E94: nop
    
            goto L_80073EE4;
    }
    // 0x80073E94: nop

    // 0x80073E98: jal         0x80061348
    // 0x80073E9C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073E9C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073EA0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073EA4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073EA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073EAC: beq         $v0, $zero, L_80073EE4
    if (ctx->r2 == 0) {
        // 0x80073EB0: nop
    
            goto L_80073EE4;
    }
    // 0x80073EB0: nop

    // 0x80073EB4: jal         0x80061348
    // 0x80073EB8: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073EB8: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073EBC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073EC0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073EC4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073EC8: beq         $v0, $zero, L_80073EE4
    if (ctx->r2 == 0) {
        // 0x80073ECC: nop
    
            goto L_80073EE4;
    }
    // 0x80073ECC: nop

    // 0x80073ED0: jal         0x80061348
    // 0x80073ED4: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073ED4: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073ED8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073EDC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073EE0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073EE4:
    // 0x80073EE4: b           L_80073EF4
    // 0x80073EE8: nop

        goto L_80073EF4;
    // 0x80073EE8: nop

    // 0x80073EEC: b           L_80073EF4
    // 0x80073EF0: nop

        goto L_80073EF4;
    // 0x80073EF0: nop

L_80073EF4:
    // 0x80073EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073EFC: jr          $ra
    // 0x80073F00: nop

    return;
    // 0x80073F00: nop

;}
RECOMP_FUNC void func_8007578C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007578C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075794: jal         0x80061348
    // 0x80075798: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075798: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x8007579C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800757A0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800757A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800757A8: beq         $v0, $zero, L_800757FC
    if (ctx->r2 == 0) {
        // 0x800757AC: nop
    
            goto L_800757FC;
    }
    // 0x800757AC: nop

    // 0x800757B0: jal         0x80061348
    // 0x800757B4: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800757B4: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x800757B8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800757BC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800757C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800757C4: beq         $v0, $zero, L_800757FC
    if (ctx->r2 == 0) {
        // 0x800757C8: nop
    
            goto L_800757FC;
    }
    // 0x800757C8: nop

    // 0x800757CC: jal         0x80061348
    // 0x800757D0: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800757D0: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x800757D4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800757D8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800757DC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800757E0: beq         $v0, $zero, L_800757FC
    if (ctx->r2 == 0) {
        // 0x800757E4: nop
    
            goto L_800757FC;
    }
    // 0x800757E4: nop

    // 0x800757E8: jal         0x80061348
    // 0x800757EC: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800757EC: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x800757F0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800757F4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800757F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800757FC:
    // 0x800757FC: b           L_8007580C
    // 0x80075800: nop

        goto L_8007580C;
    // 0x80075800: nop

    // 0x80075804: b           L_8007580C
    // 0x80075808: nop

        goto L_8007580C;
    // 0x80075808: nop

L_8007580C:
    // 0x8007580C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075814: jr          $ra
    // 0x80075818: nop

    return;
    // 0x80075818: nop

;}
RECOMP_FUNC void func_800B18C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B18C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B18C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B18CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B18D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800B18D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B18D8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800B18DC: addiu       $t7, $t7, -0x7330
    ctx->r15 = ADD32(ctx->r15, -0X7330);
    // 0x800B18E0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800B18E4: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800B18E8: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800B18EC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800B18F0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800B18F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B18F8: nop

    // 0x800B18FC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B1900: nop

    // 0x800B1904: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800B1908: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800B190C: lhu         $t2, -0x778($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X778);
    // 0x800B1910: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800B1914: lw          $t4, -0x77C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X77C);
    // 0x800B1918: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x800B191C: jal         0x800C2AE8
    // 0x800B1920: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_0;
    // 0x800B1920: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x800B1924: jal         0x800C1850
    // 0x800B1928: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_1;
    // 0x800B1928: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800B192C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1930: nop

    // 0x800B1934: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x800B1938: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800B193C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800B1940: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x800B1944: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800B1948: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B194C: addu        $t9, $sp, $t7
    ctx->r25 = ADD32(ctx->r29, ctx->r15);
    // 0x800B1950: lh          $t9, 0x24($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X24);
    // 0x800B1954: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800B1958: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800B195C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800B1960: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800B1964: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x800B1968: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800B196C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800B1970: lhu         $t5, -0x778($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X778);
    // 0x800B1974: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B1978: lw          $t6, -0x77C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77C);
    // 0x800B197C: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800B1980: sll         $t8, $t5, 6
    ctx->r24 = S32(ctx->r13 << 6);
    // 0x800B1984: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B1988: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B198C: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800B1990: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800B1994: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B1998: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800B199C: lhu         $t1, -0x778($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X778);
    // 0x800B19A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B19A4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B19A8: sh          $t2, -0x778($at)
    MEM_H(-0X778, ctx->r1) = ctx->r10;
    // 0x800B19AC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B19B0: nop

    // 0x800B19B4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800B19B8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800B19BC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800B19C0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B19C4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800B19C8: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800B19CC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B19D0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800B19D4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B19D8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B19DC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800B19E0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800B19E4: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x800B19E8: nop

    // 0x800B19EC: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800B19F0: beq         $at, $zero, L_800B1A24
    if (ctx->r1 == 0) {
        // 0x800B19F4: nop
    
            goto L_800B1A24;
    }
    // 0x800B19F4: nop

    // 0x800B19F8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B19FC: nop

    // 0x800B1A00: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800B1A04: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800B1A08: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800B1A0C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B1A10: lui         $t3, 0xBD00
    ctx->r11 = S32(0XBD00 << 16);
    // 0x800B1A14: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800B1A18: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800B1A1C: nop

    // 0x800B1A20: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
L_800B1A24:
    // 0x800B1A24: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1A28: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B1A2C: nop

    // 0x800B1A30: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800B1A34: b           L_800B1A3C
    // 0x800B1A38: nop

        goto L_800B1A3C;
    // 0x800B1A38: nop

L_800B1A3C:
    // 0x800B1A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1A40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B1A44: jr          $ra
    // 0x800B1A48: nop

    return;
    // 0x800B1A48: nop

;}
RECOMP_FUNC void func_80023CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023CA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80023CAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80023CB0: lh          $t6, 0x2588($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2588);
    // 0x80023CB4: addiu       $at, $zero, -0x25
    ctx->r1 = ADD32(0, -0X25);
    // 0x80023CB8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80023CBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023CC0: sh          $t7, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r15;
    // 0x80023CC4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80023CC8: lh          $t8, 0x664($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X664);
    // 0x80023CCC: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x80023CD0: beq         $t8, $at, L_80023E38
    if (ctx->r24 == ctx->r1) {
        // 0x80023CD4: nop
    
            goto L_80023E38;
    }
    // 0x80023CD4: nop

    // 0x80023CD8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80023CDC: lhu         $t9, 0x126C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X126C);
    // 0x80023CE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80023CE4: nop

    // 0x80023CE8: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x80023CEC: beq         $t1, $zero, L_80023D60
    if (ctx->r9 == 0) {
        // 0x80023CF0: nop
    
            goto L_80023D60;
    }
    // 0x80023CF0: nop

    // 0x80023CF4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80023CF8: lh          $t2, 0x2588($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2588);
    // 0x80023CFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023D00: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80023D04: sh          $t3, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r11;
    // 0x80023D08: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023D0C: lwc1        $f4, -0x7820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80023D10: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80023D14: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023D18: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80023D1C: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80023D20: nop

    // 0x80023D24: bc1f        L_80023D58
    if (!c1cs) {
        // 0x80023D28: nop
    
            goto L_80023D58;
    }
    // 0x80023D28: nop

    // 0x80023D2C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023D30: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80023D34: jal         0x8002A0F8
    // 0x80023D38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_0;
    // 0x80023D38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80023D3C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80023D40: bne         $at, $zero, L_80023D58
    if (ctx->r1 != 0) {
        // 0x80023D44: nop
    
            goto L_80023D58;
    }
    // 0x80023D44: nop

    // 0x80023D48: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80023D4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023D50: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023D54: swc1        $f10, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f10.u32l;
L_80023D58:
    // 0x80023D58: b           L_80023E38
    // 0x80023D5C: nop

        goto L_80023E38;
    // 0x80023D5C: nop

L_80023D60:
    // 0x80023D60: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80023D64: lhu         $t4, 0x1260($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1260);
    // 0x80023D68: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80023D6C: nop

    // 0x80023D70: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80023D74: beq         $t6, $zero, L_80023E38
    if (ctx->r14 == 0) {
        // 0x80023D78: nop
    
            goto L_80023E38;
    }
    // 0x80023D78: nop

    // 0x80023D7C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80023D80: lh          $t7, 0x2588($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2588);
    // 0x80023D84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023D88: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80023D8C: sh          $t8, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r24;
    // 0x80023D90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023D94: lwc1        $f16, -0x7820($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80023D98: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80023D9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023DA0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80023DA4: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x80023DA8: nop

    // 0x80023DAC: bc1f        L_80023E38
    if (!c1cs) {
        // 0x80023DB0: nop
    
            goto L_80023E38;
    }
    // 0x80023DB0: nop

    // 0x80023DB4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023DB8: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80023DBC: jal         0x8002A0F8
    // 0x80023DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002A0F8(rdram, ctx);
        goto after_1;
    // 0x80023DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80023DC4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80023DC8: bne         $at, $zero, L_80023E38
    if (ctx->r1 != 0) {
        // 0x80023DCC: nop
    
            goto L_80023E38;
    }
    // 0x80023DCC: nop

    // 0x80023DD0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023DD4: lwc1        $f6, -0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80023DD8: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80023DDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023DE0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80023DE4: c.eq.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d == ctx->f10.d;
    // 0x80023DE8: nop

    // 0x80023DEC: bc1f        L_80023E38
    if (!c1cs) {
        // 0x80023DF0: nop
    
            goto L_80023E38;
    }
    // 0x80023DF0: nop

    // 0x80023DF4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80023DF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80023DFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023E00: swc1        $f16, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f16.u32l;
    // 0x80023E04: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80023E08: lw          $t9, 0x3074($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3074);
    // 0x80023E0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80023E10: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80023E14: nop

    // 0x80023E18: sw          $t0, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r8;
    // 0x80023E1C: jal         0x80029ED8
    // 0x80023E20: nop

    func_80029ED8(rdram, ctx);
        goto after_2;
    // 0x80023E20: nop

    after_2:
    // 0x80023E24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80023E28: jal         0x8002A22C
    // 0x80023E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002A22C(rdram, ctx);
        goto after_3;
    // 0x80023E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80023E30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80023E34: sw          $v0, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r2;
L_80023E38:
    // 0x80023E38: b           L_80023E40
    // 0x80023E3C: nop

        goto L_80023E40;
    // 0x80023E3C: nop

L_80023E40:
    // 0x80023E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023E48: jr          $ra
    // 0x80023E4C: nop

    return;
    // 0x80023E4C: nop

;}
RECOMP_FUNC void ContPak_SetPfsCodes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE0C0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800AE0C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE0C8: sh          $a0, 0x1646($at)
    MEM_H(0X1646, ctx->r1) = ctx->r4;
    // 0x800AE0CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE0D0: sw          $a1, 0x164C($at)
    MEM_W(0X164C, ctx->r1) = ctx->r5;
    // 0x800AE0D4: jr          $ra
    // 0x800AE0D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE0D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE0DC: jr          $ra
    // 0x800AE0E0: nop

    return;
    // 0x800AE0E0: nop

    // 0x800AE0E4: jr          $ra
    // 0x800AE0E8: nop

    return;
    // 0x800AE0E8: nop

;}
RECOMP_FUNC void alEnvmixerParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D113C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1140: beq         $a1, $v0, L_800D11E0
    if (ctx->r5 == ctx->r2) {
        // 0x800D1144: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800D11E0;
    }
    // 0x800D1144: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D1148: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D114C: beq         $a1, $at, L_800D116C
    if (ctx->r5 == ctx->r1) {
        // 0x800D1150: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800D116C;
    }
    // 0x800D1150: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D1154: beq         $a1, $at, L_800D118C
    if (ctx->r5 == ctx->r1) {
        // 0x800D1158: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800D118C;
    }
    // 0x800D1158: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D115C: beql        $a1, $at, L_800D11BC
    if (ctx->r5 == ctx->r1) {
        // 0x800D1160: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_800D11BC;
    }
    goto skip_0;
    // 0x800D1160: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x800D1164: b           L_800D11EC
    // 0x800D1168: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
        goto L_800D11EC;
    // 0x800D1168: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800D116C:
    // 0x800D116C: lw          $v0, 0x40($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X40);
    // 0x800D1170: beql        $v0, $zero, L_800D1184
    if (ctx->r2 == 0) {
        // 0x800D1174: sw          $a2, 0x3C($a3)
        MEM_W(0X3C, ctx->r7) = ctx->r6;
            goto L_800D1184;
    }
    goto skip_1;
    // 0x800D1174: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
    skip_1:
    // 0x800D1178: b           L_800D1184
    // 0x800D117C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_800D1184;
    // 0x800D117C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800D1180: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
L_800D1184:
    // 0x800D1184: b           L_800D1200
    // 0x800D1188: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
        goto L_800D1200;
    // 0x800D1188: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
L_800D118C:
    // 0x800D118C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800D1190: sw          $v0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r2;
    // 0x800D1194: sw          $zero, 0x48($a3)
    MEM_W(0X48, ctx->r7) = 0;
    // 0x800D1198: beq         $a0, $zero, L_800D1200
    if (ctx->r4 == 0) {
        // 0x800D119C: sh          $v0, 0x1A($a3)
        MEM_H(0X1A, ctx->r7) = ctx->r2;
            goto L_800D1200;
    }
    // 0x800D119C: sh          $v0, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r2;
    // 0x800D11A0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D11A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800D11A8: jalr        $t9
    // 0x800D11AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D11AC: nop

    after_0:
    // 0x800D11B0: b           L_800D1204
    // 0x800D11B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D1204;
    // 0x800D11B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D11B8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800D11BC:
    // 0x800D11BC: sw          $v0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r2;
    // 0x800D11C0: beql        $a0, $zero, L_800D1204
    if (ctx->r4 == 0) {
        // 0x800D11C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D1204;
    }
    goto skip_2;
    // 0x800D11C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800D11C8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D11CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D11D0: jalr        $t9
    // 0x800D11D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D11D4: nop

    after_1:
    // 0x800D11D8: b           L_800D1204
    // 0x800D11DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D1204;
    // 0x800D11DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D11E0:
    // 0x800D11E0: b           L_800D1200
    // 0x800D11E4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800D1200;
    // 0x800D11E4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x800D11E8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800D11EC:
    // 0x800D11EC: beql        $a0, $zero, L_800D1204
    if (ctx->r4 == 0) {
        // 0x800D11F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D1204;
    }
    goto skip_3;
    // 0x800D11F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800D11F4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D11F8: jalr        $t9
    // 0x800D11FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D11FC: nop

    after_2:
L_800D1200:
    // 0x800D1200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D1204:
    // 0x800D1204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D1208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D120C: jr          $ra
    // 0x800D1210: nop

    return;
    // 0x800D1210: nop

;}
RECOMP_FUNC void alAuxBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF8D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF8DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CF8E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CF8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF8E8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF8EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF8F0: addiu       $a1, $a1, 0x1CB0
    ctx->r5 = ADD32(ctx->r5, 0X1CB0);
    // 0x800CF8F4: addiu       $a2, $a2, 0x1C80
    ctx->r6 = ADD32(ctx->r6, 0X1C80);
    // 0x800CF8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CF8FC: jal         0x800D56B0
    // 0x800CF900: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF900: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x800CF904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CF908: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CF90C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CF910: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800CF914: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF918: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800CF91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF924: jr          $ra
    // 0x800CF928: nop

    return;
    // 0x800CF928: nop

;}
RECOMP_FUNC void func_80090DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090DC0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090DC4: addiu       $t6, $t6, -0x3AB8
    ctx->r14 = ADD32(ctx->r14, -0X3AB8);
    // 0x80090DC8: sh          $zero, 0x104($t6)
    MEM_H(0X104, ctx->r14) = 0;
    // 0x80090DCC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090DD0: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, -0X3AB8);
    // 0x80090DD4: sh          $zero, 0x106($t7)
    MEM_H(0X106, ctx->r15) = 0;
    // 0x80090DD8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090DDC: addiu       $t8, $t8, -0x3AB8
    ctx->r24 = ADD32(ctx->r24, -0X3AB8);
    // 0x80090DE0: sh          $zero, 0x108($t8)
    MEM_H(0X108, ctx->r24) = 0;
    // 0x80090DE4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80090DE8: addiu       $t9, $t9, -0x3AB8
    ctx->r25 = ADD32(ctx->r25, -0X3AB8);
    // 0x80090DEC: sh          $zero, 0x10A($t9)
    MEM_H(0X10A, ctx->r25) = 0;
    // 0x80090DF0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090DF4: addiu       $t0, $t0, -0x3AB8
    ctx->r8 = ADD32(ctx->r8, -0X3AB8);
    // 0x80090DF8: sh          $zero, 0x10C($t0)
    MEM_H(0X10C, ctx->r8) = 0;
    // 0x80090DFC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80090E00: addiu       $t1, $t1, -0x2870
    ctx->r9 = ADD32(ctx->r9, -0X2870);
    // 0x80090E04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090E08: sw          $t1, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r9;
    // 0x80090E0C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80090E10: lhu         $t2, -0x44C8($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X44C8);
    // 0x80090E14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090E18: sh          $t2, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r10;
    // 0x80090E1C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80090E20: lhu         $t3, -0x44C0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X44C0);
    // 0x80090E24: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80090E28: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80090E2C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80090E30: lh          $t5, -0x3AB8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X3AB8);
    // 0x80090E34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090E38: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80090E3C: nop

    // 0x80090E40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090E44: swc1        $f6, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f6.u32l;
    // 0x80090E48: jr          $ra
    // 0x80090E4C: nop

    return;
    // 0x80090E4C: nop

    // 0x80090E50: jr          $ra
    // 0x80090E54: nop

    return;
    // 0x80090E54: nop

;}
RECOMP_FUNC void func_8006D188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D188: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D18C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D190: nop

    // 0x8006D194: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006D198: nop

    // 0x8006D19C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D1A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D1A4: jr          $ra
    // 0x8006D1A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D1A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D1AC: jr          $ra
    // 0x8006D1B0: nop

    return;
    // 0x8006D1B0: nop

    // 0x8006D1B4: jr          $ra
    // 0x8006D1B8: nop

    return;
    // 0x8006D1B8: nop

;}
RECOMP_FUNC void func_8006C510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C518: jal         0x8005F064
    // 0x8006C51C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C51C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_0:
    // 0x8006C520: b           L_8006C530
    // 0x8006C524: nop

        goto L_8006C530;
    // 0x8006C524: nop

    // 0x8006C528: b           L_8006C530
    // 0x8006C52C: nop

        goto L_8006C530;
    // 0x8006C52C: nop

L_8006C530:
    // 0x8006C530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C538: jr          $ra
    // 0x8006C53C: nop

    return;
    // 0x8006C53C: nop

;}
RECOMP_FUNC void func_80065CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065CEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065CF0: nop

    // 0x80065CF4: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80065CF8: nop

    // 0x80065CFC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80065D00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065D04: beq         $v0, $zero, L_80065D1C
    if (ctx->r2 == 0) {
        // 0x80065D08: nop
    
            goto L_80065D1C;
    }
    // 0x80065D08: nop

    // 0x80065D0C: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80065D10: nop

    // 0x80065D14: slti        $t8, $v0, 0x321
    ctx->r24 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80065D18: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065D1C:
    // 0x80065D1C: jr          $ra
    // 0x80065D20: nop

    return;
    // 0x80065D20: nop

    // 0x80065D24: jr          $ra
    // 0x80065D28: nop

    return;
    // 0x80065D28: nop

    // 0x80065D2C: jr          $ra
    // 0x80065D30: nop

    return;
    // 0x80065D30: nop

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
RECOMP_FUNC void func_8005F31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F31C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005F320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F324: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005F328: addiu       $t6, $t6, 0x4C20
    ctx->r14 = ADD32(ctx->r14, 0X4C20);
    // 0x8005F32C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8005F330: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005F334: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8005F338: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8005F33C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005F340: beq         $t7, $at, L_8005F3A4
    if (ctx->r15 == ctx->r1) {
        // 0x8005F344: nop
    
            goto L_8005F3A4;
    }
    // 0x8005F344: nop

L_8005F348:
    // 0x8005F348: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005F34C: nop

    // 0x8005F350: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8005F354: jal         0x8005F064
    // 0x8005F358: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8005F358: nop

    after_0:
    // 0x8005F35C: bne         $v0, $zero, L_8005F36C
    if (ctx->r2 != 0) {
        // 0x8005F360: nop
    
            goto L_8005F36C;
    }
    // 0x8005F360: nop

    // 0x8005F364: b           L_8005F37C
    // 0x8005F368: nop

        goto L_8005F37C;
    // 0x8005F368: nop

L_8005F36C:
    // 0x8005F36C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F370: nop

    // 0x8005F374: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005F378: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_8005F37C:
    // 0x8005F37C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005F380: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005F384: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8005F388: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F38C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8005F390: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8005F394: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005F398: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005F39C: bne         $t5, $at, L_8005F348
    if (ctx->r13 != ctx->r1) {
        // 0x8005F3A0: nop
    
            goto L_8005F348;
    }
    // 0x8005F3A0: nop

L_8005F3A4:
    // 0x8005F3A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F3A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005F3AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005F3B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005F3B4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005F3B8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005F3BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005F3C0: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8005F3C4: bne         $t8, $zero, L_8005F3D0
    if (ctx->r24 != 0) {
        // 0x8005F3C8: nop
    
            goto L_8005F3D0;
    }
    // 0x8005F3C8: nop

    // 0x8005F3CC: break       7
    do_break(2147873740);
L_8005F3D0:
    // 0x8005F3D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005F3D4: bne         $t8, $at, L_8005F3E8
    if (ctx->r24 != ctx->r1) {
        // 0x8005F3D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005F3E8;
    }
    // 0x8005F3D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005F3DC: bne         $t7, $at, L_8005F3E8
    if (ctx->r15 != ctx->r1) {
        // 0x8005F3E0: nop
    
            goto L_8005F3E8;
    }
    // 0x8005F3E0: nop

    // 0x8005F3E4: break       6
    do_break(2147873764);
L_8005F3E8:
    // 0x8005F3E8: mflo        $v0
    ctx->r2 = lo;
    // 0x8005F3EC: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8005F3F0: b           L_8005F400
    // 0x8005F3F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005F400;
    // 0x8005F3F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8005F3F8: b           L_8005F400
    // 0x8005F3FC: nop

        goto L_8005F400;
    // 0x8005F3FC: nop

L_8005F400:
    // 0x8005F400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005F408: jr          $ra
    // 0x8005F40C: nop

    return;
    // 0x8005F40C: nop

;}
RECOMP_FUNC void Scheduler_RspTaskYield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097F0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097F10: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80097F14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80097F18: lw          $t7, 0x294($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X294);
    // 0x80097F1C: nop

    // 0x80097F20: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80097F24: nop

    // 0x80097F28: bne         $t8, $at, L_80097F60
    if (ctx->r24 != ctx->r1) {
        // 0x80097F2C: nop
    
            goto L_80097F60;
    }
    // 0x80097F2C: nop

    // 0x80097F30: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80097F34: nop

    // 0x80097F38: lw          $t0, 0x294($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X294);
    // 0x80097F3C: nop

    // 0x80097F40: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80097F44: nop

    // 0x80097F48: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80097F4C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80097F50: jal         0x800C51B0
    // 0x80097F54: nop

    osSpTaskYield_recomp(rdram, ctx);
        goto after_0;
    // 0x80097F54: nop

    after_0:
    // 0x80097F58: b           L_80097F60
    // 0x80097F5C: nop

        goto L_80097F60;
    // 0x80097F5C: nop

L_80097F60:
    // 0x80097F60: b           L_80097F68
    // 0x80097F64: nop

        goto L_80097F68;
    // 0x80097F64: nop

L_80097F68:
    // 0x80097F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097F70: jr          $ra
    // 0x80097F74: nop

    return;
    // 0x80097F74: nop

;}
RECOMP_FUNC void alSynAllocFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFFE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CFFE4: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x800CFFE8: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800CFFEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CFFF0: sll         $s1, $t6, 2
    ctx->r17 = S32(ctx->r14 << 2);
    // 0x800CFFF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CFFF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CFFFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D0000: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x800D0004: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x800D0008: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x800D000C: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x800D0010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D0014: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x800D0018: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800D001C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x800D0020: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D0024: jal         0x800CFBA0
    // 0x800D0028: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    alFxNew(rdram, ctx);
        goto after_0;
    // 0x800D0028: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x800D002C: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x800D0030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D0034: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x800D0038: jal         0x800D5FC4
    // 0x800D003C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    alFxParam(rdram, ctx);
        goto after_1;
    // 0x800D003C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x800D0040: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800D0044: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x800D0048: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800D004C: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x800D0050: jal         0x800D0080
    // 0x800D0054: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    alMainBusParam(rdram, ctx);
        goto after_2;
    // 0x800D0054: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    after_2:
    // 0x800D0058: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x800D005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0060: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D0064: addu        $v0, $t2, $s1
    ctx->r2 = ADD32(ctx->r10, ctx->r17);
    // 0x800D0068: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D006C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D0070: jr          $ra
    // 0x800D0074: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x800D0074: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
;}
RECOMP_FUNC void func_80077EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077EE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077EE4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077EE8: nop

    // 0x80077EEC: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80077EF0: nop

    // 0x80077EF4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077EF8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077EFC: jr          $ra
    // 0x80077F00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077F00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077F04: jr          $ra
    // 0x80077F08: nop

    return;
    // 0x80077F08: nop

    // 0x80077F0C: jr          $ra
    // 0x80077F10: nop

    return;
    // 0x80077F10: nop

;}
RECOMP_FUNC void func_80064B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064BA0: jal         0x8005F064
    // 0x80064BA4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064BA4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80064BA8: b           L_80064BB8
    // 0x80064BAC: nop

        goto L_80064BB8;
    // 0x80064BAC: nop

    // 0x80064BB0: b           L_80064BB8
    // 0x80064BB4: nop

        goto L_80064BB8;
    // 0x80064BB4: nop

L_80064BB8:
    // 0x80064BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064BC0: jr          $ra
    // 0x80064BC4: nop

    return;
    // 0x80064BC4: nop

;}
RECOMP_FUNC void func_80077590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077590: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077594: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077598: nop

    // 0x8007759C: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x800775A0: nop

    // 0x800775A4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800775A8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800775AC: jr          $ra
    // 0x800775B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800775B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800775B4: jr          $ra
    // 0x800775B8: nop

    return;
    // 0x800775B8: nop

    // 0x800775BC: jr          $ra
    // 0x800775C0: nop

    return;
    // 0x800775C0: nop

;}
RECOMP_FUNC void func_8008A730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008A73C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008A740: jal         0x80031BB0
    // 0x8008A744: nop

    func_80031BB0(rdram, ctx);
        goto after_0;
    // 0x8008A744: nop

    after_0:
    // 0x8008A748: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8008A74C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008A750: nop

    // 0x8008A754: sh          $t6, 0x73C($t7)
    MEM_H(0X73C, ctx->r15) = ctx->r14;
    // 0x8008A758: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008A75C: nop

    // 0x8008A760: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8008A764: nop

    // 0x8008A768: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8008A76C: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x8008A770: b           L_8008A778
    // 0x8008A774: nop

        goto L_8008A778;
    // 0x8008A774: nop

L_8008A778:
    // 0x8008A778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A780: jr          $ra
    // 0x8008A784: nop

    return;
    // 0x8008A784: nop

;}
RECOMP_FUNC void func_8006728C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006728C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067294: jal         0x80061488
    // 0x80067298: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067298: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x8006729C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800672A0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800672A4: b           L_800672B4
    // 0x800672A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800672B4;
    // 0x800672A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800672AC: b           L_800672B4
    // 0x800672B0: nop

        goto L_800672B4;
    // 0x800672B0: nop

L_800672B4:
    // 0x800672B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800672B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800672BC: jr          $ra
    // 0x800672C0: nop

    return;
    // 0x800672C0: nop

;}
RECOMP_FUNC void func_80016BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016BFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80016C00: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80016C04: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80016C08: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80016C0C: jal         0x80016074
    // 0x80016C10: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80016C10: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_0:
    // 0x80016C14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80016C18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C1C: nop

    // 0x80016C20: bne         $t6, $zero, L_80016C30
    if (ctx->r14 != 0) {
        // 0x80016C24: nop
    
            goto L_80016C30;
    }
    // 0x80016C24: nop

    // 0x80016C28: b           L_80016F70
    // 0x80016C2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80016F70;
    // 0x80016C2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80016C30:
    // 0x80016C30: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C34: nop

    // 0x80016C38: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80016C3C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C40: nop

    // 0x80016C44: lw          $t9, 0x1A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A8);
    // 0x80016C48: nop

    // 0x80016C4C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80016C50: sw          $t0, 0x1A8($t8)
    MEM_W(0X1A8, ctx->r24) = ctx->r8;
    // 0x80016C54: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C58: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x80016C5C: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x80016C60: nop

    // 0x80016C64: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80016C68: sw          $t3, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r11;
    // 0x80016C6C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016C70: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C74: nop

    // 0x80016C78: swc1        $f4, 0x1EC($t4)
    MEM_W(0X1EC, ctx->r12) = ctx->f4.u32l;
    // 0x80016C7C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C80: nop

    // 0x80016C84: lwc1        $f6, 0x1EC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X1EC);
    // 0x80016C88: nop

    // 0x80016C8C: swc1        $f6, 0x1E8($t5)
    MEM_W(0X1E8, ctx->r13) = ctx->f6.u32l;
    // 0x80016C90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016C94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C98: nop

    // 0x80016C9C: swc1        $f8, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->f8.u32l;
    // 0x80016CA0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80016CA4: nop

    // 0x80016CA8: lwc1        $f10, 0x1F4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X1F4);
    // 0x80016CAC: nop

    // 0x80016CB0: swc1        $f10, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f10.u32l;
    // 0x80016CB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016CB8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80016CBC: nop

    // 0x80016CC0: swc1        $f16, 0x1FC($t9)
    MEM_W(0X1FC, ctx->r25) = ctx->f16.u32l;
    // 0x80016CC4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016CC8: nop

    // 0x80016CCC: lwc1        $f18, 0x1FC($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X1FC);
    // 0x80016CD0: nop

    // 0x80016CD4: swc1        $f18, 0x1F8($t0)
    MEM_W(0X1F8, ctx->r8) = ctx->f18.u32l;
    // 0x80016CD8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80016CDC: nop

    // 0x80016CE0: andi        $t2, $t8, 0x4
    ctx->r10 = ctx->r24 & 0X4;
    // 0x80016CE4: beq         $t2, $zero, L_80016E64
    if (ctx->r10 == 0) {
        // 0x80016CE8: nop
    
            goto L_80016E64;
    }
    // 0x80016CE8: nop

    // 0x80016CEC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80016CF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016CF4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80016CF8: nop

    // 0x80016CFC: swc1        $f4, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f4.u32l;
    // 0x80016D00: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80016D04: nop

    // 0x80016D08: lwc1        $f6, 0xD0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80016D0C: nop

    // 0x80016D10: swc1        $f6, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f6.u32l;
    // 0x80016D14: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80016D18: nop

    // 0x80016D1C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80016D20: beq         $t5, $zero, L_80016D80
    if (ctx->r13 == 0) {
        // 0x80016D24: nop
    
            goto L_80016D80;
    }
    // 0x80016D24: nop

    // 0x80016D28: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016D2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016D30: swc1        $f8, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f8.u32l;
    // 0x80016D34: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016D38: swc1        $f8, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f8.u32l;
    // 0x80016D3C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016D40: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016D44: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80016D48: nop

    // 0x80016D4C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80016D50: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016D54: nop

    // 0x80016D58: swc1        $f4, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = ctx->f4.u32l;
    // 0x80016D5C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80016D60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016D64: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016D68: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016D6C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80016D70: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80016D74: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80016D78: b           L_80016DB8
    // 0x80016D7C: swc1        $f18, 0x1F4($t7)
    MEM_W(0X1F4, ctx->r15) = ctx->f18.u32l;
        goto L_80016DB8;
    // 0x80016D7C: swc1        $f18, 0x1F4($t7)
    MEM_W(0X1F4, ctx->r15) = ctx->f18.u32l;
L_80016D80:
    // 0x80016D80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016D84: lwc1        $f4, 0x61C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x80016D88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016D8C: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80016D90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016D94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80016D98: swc1        $f8, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f8.u32l;
    // 0x80016D9C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016DA0: lwc1        $f10, 0x61C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80016DA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016DA8: lwc1        $f16, 0x7224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80016DAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016DB0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80016DB4: swc1        $f18, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f18.u32l;
L_80016DB8:
    // 0x80016DB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80016DBC: nop

    // 0x80016DC0: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x80016DC4: beq         $t0, $zero, L_80016E24
    if (ctx->r8 == 0) {
        // 0x80016DC8: nop
    
            goto L_80016E24;
    }
    // 0x80016DC8: nop

    // 0x80016DCC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016DD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016DD4: swc1        $f4, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f4.u32l;
    // 0x80016DD8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016DDC: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
    // 0x80016DE0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016DE4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016DE8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80016DEC: nop

    // 0x80016DF0: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016DF4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80016DF8: nop

    // 0x80016DFC: swc1        $f16, 0x1F8($t8)
    MEM_W(0X1F8, ctx->r24) = ctx->f16.u32l;
    // 0x80016E00: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80016E04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80016E08: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016E0C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016E10: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80016E14: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80016E18: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80016E1C: b           L_80016E5C
    // 0x80016E20: swc1        $f10, 0x1FC($t2)
    MEM_W(0X1FC, ctx->r10) = ctx->f10.u32l;
        goto L_80016E5C;
    // 0x80016E20: swc1        $f10, 0x1FC($t2)
    MEM_W(0X1FC, ctx->r10) = ctx->f10.u32l;
L_80016E24:
    // 0x80016E24: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016E28: lwc1        $f16, 0x61C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80016E2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016E30: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80016E34: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016E38: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80016E3C: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
    // 0x80016E40: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016E44: lwc1        $f6, 0x61D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x80016E48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016E4C: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80016E50: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016E54: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80016E58: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
L_80016E5C:
    // 0x80016E5C: b           L_80016F60
    // 0x80016E60: nop

        goto L_80016F60;
    // 0x80016E60: nop

L_80016E64:
    // 0x80016E64: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80016E68: nop

    // 0x80016E6C: andi        $t1, $t3, 0x8
    ctx->r9 = ctx->r11 & 0X8;
    // 0x80016E70: beq         $t1, $zero, L_80016F58
    if (ctx->r9 == 0) {
        // 0x80016E74: nop
    
            goto L_80016F58;
    }
    // 0x80016E74: nop

    // 0x80016E78: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016E7C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80016E80: nop

    // 0x80016E84: swc1        $f16, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f16.u32l;
    // 0x80016E88: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016E8C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80016E90: nop

    // 0x80016E94: swc1        $f18, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f18.u32l;
    // 0x80016E98: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80016E9C: nop

    // 0x80016EA0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016EA4: beq         $t7, $zero, L_80016EF4
    if (ctx->r15 == 0) {
        // 0x80016EA8: nop
    
            goto L_80016EF4;
    }
    // 0x80016EA8: nop

    // 0x80016EAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016EB0: lwc1        $f6, 0x6190($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x80016EB4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016EB8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016EBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80016EC0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80016EC4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016EC8: swc1        $f16, 0x1F0($t9)
    MEM_W(0X1F0, ctx->r25) = ctx->f16.u32l;
    // 0x80016ECC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016ED0: lwc1        $f18, 0x6198($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x80016ED4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016ED8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016EDC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80016EE0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016EE4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80016EE8: nop

    // 0x80016EEC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016EF0: swc1        $f16, 0x1F4($t0)
    MEM_W(0X1F4, ctx->r8) = ctx->f16.u32l;
L_80016EF4:
    // 0x80016EF4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80016EF8: nop

    // 0x80016EFC: andi        $t2, $t8, 0x2
    ctx->r10 = ctx->r24 & 0X2;
    // 0x80016F00: beq         $t2, $zero, L_80016F50
    if (ctx->r10 == 0) {
        // 0x80016F04: nop
    
            goto L_80016F50;
    }
    // 0x80016F04: nop

    // 0x80016F08: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016F0C: lwc1        $f4, 0x6194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x80016F10: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016F14: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016F18: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80016F1C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80016F20: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80016F24: swc1        $f10, 0x1F8($t3)
    MEM_W(0X1F8, ctx->r11) = ctx->f10.u32l;
    // 0x80016F28: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016F2C: lwc1        $f16, 0x619C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x80016F30: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016F34: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016F38: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80016F3C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80016F40: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80016F44: nop

    // 0x80016F48: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80016F4C: swc1        $f10, 0x1FC($t1)
    MEM_W(0X1FC, ctx->r9) = ctx->f10.u32l;
L_80016F50:
    // 0x80016F50: b           L_80016F60
    // 0x80016F54: nop

        goto L_80016F60;
    // 0x80016F54: nop

L_80016F58:
    // 0x80016F58: b           L_80016F70
    // 0x80016F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80016F70;
    // 0x80016F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016F60:
    // 0x80016F60: b           L_80016F70
    // 0x80016F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016F70;
    // 0x80016F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016F68: b           L_80016F70
    // 0x80016F6C: nop

        goto L_80016F70;
    // 0x80016F6C: nop

L_80016F70:
    // 0x80016F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016F74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016F78: jr          $ra
    // 0x80016F7C: nop

    return;
    // 0x80016F7C: nop

;}
RECOMP_FUNC void func_80098BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098BF4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098BF8: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098BFC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80098C00: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80098C04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098C08: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098C0C: jr          $ra
    // 0x80098C10: nop

    return;
    // 0x80098C10: nop

    // 0x80098C14: jr          $ra
    // 0x80098C18: nop

    return;
    // 0x80098C18: nop

;}
RECOMP_FUNC void func_80064F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064F54: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064F58: nop

    // 0x80064F5C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064F60: nop

    // 0x80064F64: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80064F68: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064F6C: jr          $ra
    // 0x80064F70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064F70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064F74: jr          $ra
    // 0x80064F78: nop

    return;
    // 0x80064F78: nop

    // 0x80064F7C: jr          $ra
    // 0x80064F80: nop

    return;
    // 0x80064F80: nop

;}
RECOMP_FUNC void func_80099520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099520: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80099524: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80099528: lw          $t6, 0x40CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X40CC);
    // 0x8009952C: nop

    // 0x80099530: beq         $t6, $zero, L_80099610
    if (ctx->r14 == 0) {
        // 0x80099534: nop
    
            goto L_80099610;
    }
    // 0x80099534: nop

    // 0x80099538: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8009953C: lw          $t7, 0x40CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X40CC);
    // 0x80099540: nop

    // 0x80099544: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80099548: bgez        $t7, L_80099560
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8009954C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80099560;
    }
    // 0x8009954C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80099550: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80099554: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80099558: nop

    // 0x8009955C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80099560:
    // 0x80099560: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80099564: lw          $t8, 0x2554($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2554);
    // 0x80099568: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009956C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80099570: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80099574: swc1        $f6, 0x2538($at)
    MEM_W(0X2538, ctx->r1) = ctx->f6.u32l;
    // 0x80099578: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8009957C: lw          $t0, 0x2554($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2554);
    // 0x80099580: nop

    // 0x80099584: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80099588: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8009958C: beq         $at, $zero, L_800995A0
    if (ctx->r1 == 0) {
        // 0x80099590: nop
    
            goto L_800995A0;
    }
    // 0x80099590: nop

    // 0x80099594: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80099598: b           L_800995A8
    // 0x8009959C: sw          $t1, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = ctx->r9;
        goto L_800995A8;
    // 0x8009959C: sw          $t1, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = ctx->r9;
L_800995A0:
    // 0x800995A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800995A4: sw          $zero, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = 0;
L_800995A8:
    // 0x800995A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800995AC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800995B0: swc1        $f10, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f10.u32l;
L_800995B4:
    // 0x800995B4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800995B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800995BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800995C0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800995C4: lwc1        $f18, 0x2538($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2538);
    // 0x800995C8: lwc1        $f16, 0x0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800995CC: nop

    // 0x800995D0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800995D4: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x800995D8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800995DC: nop

    // 0x800995E0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800995E4: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x800995E8: bne         $at, $zero, L_800995B4
    if (ctx->r1 != 0) {
        // 0x800995EC: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_800995B4;
    }
    // 0x800995EC: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800995F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800995F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800995F8: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800995FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80099600: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80099604: swc1        $f10, 0x257C($at)
    MEM_W(0X257C, ctx->r1) = ctx->f10.u32l;
    // 0x80099608: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009960C: sw          $zero, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = 0;
L_80099610:
    // 0x80099610: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80099614: lw          $t6, 0x40D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X40D0);
    // 0x80099618: nop

    // 0x8009961C: sltiu       $at, $t6, 0x2
    ctx->r1 = ctx->r14 < 0X2 ? 1 : 0;
    // 0x80099620: beq         $at, $zero, L_80099640
    if (ctx->r1 == 0) {
        // 0x80099624: nop
    
            goto L_80099640;
    }
    // 0x80099624: nop

    // 0x80099628: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009962C: sw          $zero, 0x40D0($at)
    MEM_W(0X40D0, ctx->r1) = 0;
    // 0x80099630: b           L_80099658
    // 0x80099634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80099658;
    // 0x80099634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80099638: b           L_80099650
    // 0x8009963C: nop

        goto L_80099650;
    // 0x8009963C: nop

L_80099640:
    // 0x80099640: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80099644: sw          $zero, 0x40D0($at)
    MEM_W(0X40D0, ctx->r1) = 0;
    // 0x80099648: b           L_80099658
    // 0x8009964C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80099658;
    // 0x8009964C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80099650:
    // 0x80099650: b           L_80099658
    // 0x80099654: nop

        goto L_80099658;
    // 0x80099654: nop

L_80099658:
    // 0x80099658: jr          $ra
    // 0x8009965C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8009965C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006DEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DEF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DF00: jal         0x80061348
    // 0x8006DF04: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DF04: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006DF08: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DF0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DF10: beq         $v0, $zero, L_8006DF28
    if (ctx->r2 == 0) {
        // 0x8006DF14: nop
    
            goto L_8006DF28;
    }
    // 0x8006DF14: nop

    // 0x8006DF18: jal         0x80061348
    // 0x8006DF1C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DF1C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x8006DF20: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DF24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DF28:
    // 0x8006DF28: b           L_8006DF38
    // 0x8006DF2C: nop

        goto L_8006DF38;
    // 0x8006DF2C: nop

    // 0x8006DF30: b           L_8006DF38
    // 0x8006DF34: nop

        goto L_8006DF38;
    // 0x8006DF34: nop

L_8006DF38:
    // 0x8006DF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DF3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DF40: jr          $ra
    // 0x8006DF44: nop

    return;
    // 0x8006DF44: nop

;}
RECOMP_FUNC void func_8006D158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D158: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D15C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D160: nop

    // 0x8006D164: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x8006D168: nop

    // 0x8006D16C: slti        $t7, $v0, 0x3E8
    ctx->r15 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    // 0x8006D170: jr          $ra
    // 0x8006D174: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D174: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D178: jr          $ra
    // 0x8006D17C: nop

    return;
    // 0x8006D17C: nop

    // 0x8006D180: jr          $ra
    // 0x8006D184: nop

    return;
    // 0x8006D184: nop

;}
RECOMP_FUNC void alSeqpSetBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CACE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CACE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CACE8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800CACEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CACF0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800CACF4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CACF8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CACFC: jal         0x800D3A2C
    // 0x800CAD00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CAD00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CAD04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAD08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CAD0C: jr          $ra
    // 0x800CAD10: nop

    return;
    // 0x800CAD10: nop

;}
RECOMP_FUNC void func_800739EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800739EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800739F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800739F4: jal         0x80061488
    // 0x800739F8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800739F8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x800739FC: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80073A00: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073A04: b           L_80073A14
    // 0x80073A08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073A14;
    // 0x80073A08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073A0C: b           L_80073A14
    // 0x80073A10: nop

        goto L_80073A14;
    // 0x80073A10: nop

L_80073A14:
    // 0x80073A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073A1C: jr          $ra
    // 0x80073A20: nop

    return;
    // 0x80073A20: nop

;}
RECOMP_FUNC void func_80070880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070888: jal         0x80061348
    // 0x8007088C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007088C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070890: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070894: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070898: beq         $v0, $zero, L_800708E8
    if (ctx->r2 == 0) {
        // 0x8007089C: nop
    
            goto L_800708E8;
    }
    // 0x8007089C: nop

    // 0x800708A0: jal         0x80061348
    // 0x800708A4: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800708A4: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800708A8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800708AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800708B0: beq         $v0, $zero, L_800708E8
    if (ctx->r2 == 0) {
        // 0x800708B4: nop
    
            goto L_800708E8;
    }
    // 0x800708B4: nop

    // 0x800708B8: jal         0x80061348
    // 0x800708BC: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800708BC: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800708C0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800708C4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800708C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800708CC: beq         $v0, $zero, L_800708E8
    if (ctx->r2 == 0) {
        // 0x800708D0: nop
    
            goto L_800708E8;
    }
    // 0x800708D0: nop

    // 0x800708D4: jal         0x80061348
    // 0x800708D8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800708D8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800708DC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800708E0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800708E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800708E8:
    // 0x800708E8: b           L_800708F8
    // 0x800708EC: nop

        goto L_800708F8;
    // 0x800708EC: nop

    // 0x800708F0: b           L_800708F8
    // 0x800708F4: nop

        goto L_800708F8;
    // 0x800708F4: nop

L_800708F8:
    // 0x800708F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800708FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070900: jr          $ra
    // 0x80070904: nop

    return;
    // 0x80070904: nop

;}
RECOMP_FUNC void func_800730BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800730BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800730C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800730C4: nop

    // 0x800730C8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800730CC: nop

    // 0x800730D0: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x800730D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800730D8: jr          $ra
    // 0x800730DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800730DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800730E0: jr          $ra
    // 0x800730E4: nop

    return;
    // 0x800730E4: nop

    // 0x800730E8: jr          $ra
    // 0x800730EC: nop

    return;
    // 0x800730EC: nop

;}
RECOMP_FUNC void func_8009A22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A22C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009A230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009A234: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8009A238: lw          $a2, 0x7218($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7218);
    // 0x8009A23C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009A240: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8009A244: jal         0x800C2304
    // 0x8009A248: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_0;
    // 0x8009A248: nop

    after_0:
    // 0x8009A24C: b           L_8009A254
    // 0x8009A250: nop

        goto L_8009A254;
    // 0x8009A250: nop

L_8009A254:
    // 0x8009A254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009A258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009A25C: jr          $ra
    // 0x8009A260: nop

    return;
    // 0x8009A260: nop

;}
RECOMP_FUNC void func_800633A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800633A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800633AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800633B0: jal         0x8005F064
    // 0x800633B4: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800633B4: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_0:
    // 0x800633B8: b           L_800633C8
    // 0x800633BC: nop

        goto L_800633C8;
    // 0x800633BC: nop

    // 0x800633C0: b           L_800633C8
    // 0x800633C4: nop

        goto L_800633C8;
    // 0x800633C4: nop

L_800633C8:
    // 0x800633C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800633CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800633D0: jr          $ra
    // 0x800633D4: nop

    return;
    // 0x800633D4: nop

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
RECOMP_FUNC void MathUtil_MultiplyVec3fComponents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3BC4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C3BC8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C3BCC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C3BD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C3BD4: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C3BD8: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C3BDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C3BE0: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800C3BE4: nop

    // 0x800C3BE8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C3BEC: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800C3BF0: jr          $ra
    // 0x800C3BF4: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    return;
    // 0x800C3BF4: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800C3BF8: jr          $ra
    // 0x800C3BFC: nop

    return;
    // 0x800C3BFC: nop

    // 0x800C3C00: jr          $ra
    // 0x800C3C04: nop

    return;
    // 0x800C3C04: nop

;}
RECOMP_FUNC void func_8006F324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F324: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F328: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F32C: nop

    // 0x8006F330: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F334: nop

    // 0x8006F338: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F33C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F340: jr          $ra
    // 0x8006F344: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F344: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F348: jr          $ra
    // 0x8006F34C: nop

    return;
    // 0x8006F34C: nop

    // 0x8006F350: jr          $ra
    // 0x8006F354: nop

    return;
    // 0x8006F354: nop

;}
RECOMP_FUNC void func_800A735C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A735C: addiu       $sp, $sp, -0x1A0
    ctx->r29 = ADD32(ctx->r29, -0X1A0);
    // 0x800A7360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7364: sw          $a0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r4;
    // 0x800A7368: sw          $a1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r5;
    // 0x800A736C: sw          $a2, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r6;
    // 0x800A7370: lw          $t6, 0x1A0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A0);
    // 0x800A7374: nop

    // 0x800A7378: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A737C: nop

    // 0x800A7380: sw          $t7, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r15;
    // 0x800A7384: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7388: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A738C: lw          $t0, 0x7250($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7250);
    // 0x800A7390: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x800A7394: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A7398: lw          $t2, 0x7258($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7258);
    // 0x800A739C: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800A73A0: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x800A73A4: sw          $t3, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r11;
    // 0x800A73A8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A73AC: sw          $t4, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r12;
    // 0x800A73B0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A73B4: lw          $t6, 0x70E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70E4);
    // 0x800A73B8: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x800A73BC: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800A73C0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800A73C4: sw          $t8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r24;
    // 0x800A73C8: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A73CC: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x800A73D0: lh          $t0, 0x11E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X11E);
    // 0x800A73D4: lwc1        $f8, 0xE8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x800A73D8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A73DC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A73E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A73E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A73E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A73EC: nop

    // 0x800A73F0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A73F4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A73F8: nop

    // 0x800A73FC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A7400: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7404: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7408: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A740C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A7410: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800A7414: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A7418: sh          $t3, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r11;
    // 0x800A741C: nop

    // 0x800A7420: lw          $t4, 0x178($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X178);
    // 0x800A7424: nop

    // 0x800A7428: andi        $t6, $t4, 0x40
    ctx->r14 = ctx->r12 & 0X40;
    // 0x800A742C: bne         $t6, $zero, L_800A7470
    if (ctx->r14 != 0) {
        // 0x800A7430: nop
    
            goto L_800A7470;
    }
    // 0x800A7430: nop

    // 0x800A7434: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7438: nop

    // 0x800A743C: lwc1        $f6, 0xF4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XF4);
    // 0x800A7440: lwc1        $f8, 0xFC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XFC);
    // 0x800A7444: nop

    // 0x800A7448: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A744C: swc1        $f10, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f10.u32l;
    // 0x800A7450: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7454: nop

    // 0x800A7458: lwc1        $f16, 0xF8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XF8);
    // 0x800A745C: lwc1        $f18, 0xFC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x800A7460: nop

    // 0x800A7464: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A7468: b           L_800A74C8
    // 0x800A746C: swc1        $f4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f4.u32l;
        goto L_800A74C8;
    // 0x800A746C: swc1        $f4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f4.u32l;
L_800A7470:
    // 0x800A7470: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7474: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A7478: lwc1        $f6, 0xF4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x800A747C: lwc1        $f8, 0xFC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x800A7480: lwc1        $f16, 0xB8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XB8);
    // 0x800A7484: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A7488: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A748C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800A7490: nop

    // 0x800A7494: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A7498: swc1        $f6, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f6.u32l;
    // 0x800A749C: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A74A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A74A4: lwc1        $f8, 0xF8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x800A74A8: lwc1        $f16, 0xFC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XFC);
    // 0x800A74AC: lwc1        $f18, 0xB8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XB8);
    // 0x800A74B0: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A74B4: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A74B8: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A74BC: nop

    // 0x800A74C0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A74C4: swc1        $f8, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f8.u32l;
L_800A74C8:
    // 0x800A74C8: jal         0x800C1754
    // 0x800A74CC: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x800A74CC: nop

    after_0:
    // 0x800A74D0: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    // 0x800A74D4: jal         0x800C2B20
    // 0x800A74D8: nop

    MtxUtil_SetCurrentFromMtx(rdram, ctx);
        goto after_1;
    // 0x800A74D8: nop

    after_1:
    // 0x800A74DC: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A74E0: jal         0x800C1D44
    // 0x800A74E4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_2;
    // 0x800A74E4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_2:
    // 0x800A74E8: lw          $t0, 0x178($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X178);
    // 0x800A74EC: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800A74F0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800A74F4: beq         $t1, $zero, L_800A7540
    if (ctx->r9 == 0) {
        // 0x800A74F8: nop
    
            goto L_800A7540;
    }
    // 0x800A74F8: nop

    // 0x800A74FC: jal         0x800C1680
    // 0x800A7500: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_3;
    // 0x800A7500: nop

    after_3:
    // 0x800A7504: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7508: jal         0x800C1AF4
    // 0x800A750C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_4;
    // 0x800A750C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_4:
    // 0x800A7510: jal         0x800C1908
    // 0x800A7514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_ClearTranslation(rdram, ctx);
        goto after_5;
    // 0x800A7514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x800A7518: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A751C: jal         0x800C1A84
    // 0x800A7520: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_6;
    // 0x800A7520: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_6:
    // 0x800A7524: jal         0x800C1A28
    // 0x800A7528: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_7;
    // 0x800A7528: nop

    after_7:
    // 0x800A752C: jal         0x800C197C
    // 0x800A7530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_ClearRotation(rdram, ctx);
        goto after_8;
    // 0x800A7530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A7534: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A7538: jal         0x800C1D44
    // 0x800A753C: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    func_800C1D44(rdram, ctx);
        goto after_9;
    // 0x800A753C: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_9:
L_800A7540:
    // 0x800A7540: lwc1        $f12, 0x144($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A7544: lwc1        $f14, 0x140($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A7548: jal         0x800C2948
    // 0x800A754C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_10;
    // 0x800A754C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_10:
    // 0x800A7550: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A7554: lw          $t3, 0x70E4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70E4);
    // 0x800A7558: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A755C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x800A7560: jal         0x800C2AE8
    // 0x800A7564: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_11;
    // 0x800A7564: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    after_11:
    // 0x800A7568: jal         0x800C1A28
    // 0x800A756C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_12;
    // 0x800A756C: nop

    after_12:
    // 0x800A7570: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7574: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A7578: nop

    // 0x800A757C: swc1        $f16, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f16.u32l;
    // 0x800A7580: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7584: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A7588: nop

    // 0x800A758C: swc1        $f18, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f18.u32l;
    // 0x800A7590: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7594: nop

    // 0x800A7598: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x800A759C: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A75A0: sw          $t6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r14;
    // 0x800A75A4: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x800A75A8: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A75AC: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x800A75B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A75B4: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x800A75B8: nop

    // 0x800A75BC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A75C0: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A75C4: nop

    // 0x800A75C8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A75CC: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A75D0: sw          $t0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r8;
    // 0x800A75D4: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x800A75D8: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A75DC: ori         $t3, $t3, 0x201
    ctx->r11 = ctx->r11 | 0X201;
    // 0x800A75E0: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A75E4: lw          $t4, 0x134($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X134);
    // 0x800A75E8: nop

    // 0x800A75EC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800A75F0: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A75F4: nop

    // 0x800A75F8: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x800A75FC: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A7600: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
    // 0x800A7604: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x800A7608: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x800A760C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A7610: lw          $t0, 0x130($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X130);
    // 0x800A7614: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800A7618: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A761C: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7620: nop

    // 0x800A7624: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A7628: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A762C: sw          $t1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r9;
    // 0x800A7630: lw          $t4, 0x12C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X12C);
    // 0x800A7634: lui         $t2, 0x106
    ctx->r10 = S32(0X106 << 16);
    // 0x800A7638: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x800A763C: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A7640: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A7644: lw          $t5, 0x70E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E4);
    // 0x800A7648: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A764C: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A7650: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x800A7654: lw          $t0, 0x12C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X12C);
    // 0x800A7658: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A765C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A7660: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800A7664: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A7668: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A766C: nop

    // 0x800A7670: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A7674: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A7678: sw          $t1, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r9;
    // 0x800A767C: lw          $t4, 0x128($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X128);
    // 0x800A7680: lui         $t2, 0xBB00
    ctx->r10 = S32(0XBB00 << 16);
    // 0x800A7684: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x800A7688: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A768C: lw          $t6, 0x128($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X128);
    // 0x800A7690: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800A7694: ori         $t5, $t5, 0x8000
    ctx->r13 = ctx->r13 | 0X8000;
    // 0x800A7698: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A769C: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x800A76A0: nop

    // 0x800A76A4: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x800A76A8: beq         $t8, $zero, L_800A7720
    if (ctx->r24 == 0) {
        // 0x800A76AC: nop
    
            goto L_800A7720;
    }
    // 0x800A76AC: nop

    // 0x800A76B0: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A76B4: nop

    // 0x800A76B8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A76BC: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A76C0: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x800A76C4: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x800A76C8: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x800A76CC: ori         $t1, $t1, 0xFE24
    ctx->r9 = ctx->r9 | 0XFE24;
    // 0x800A76D0: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A76D4: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x800A76D8: lui         $t2, 0xFF30
    ctx->r10 = S32(0XFF30 << 16);
    // 0x800A76DC: ori         $t2, $t2, 0xF3FF
    ctx->r10 = ctx->r10 | 0XF3FF;
    // 0x800A76E0: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800A76E4: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A76E8: nop

    // 0x800A76EC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A76F0: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A76F4: sw          $t5, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r13;
    // 0x800A76F8: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x800A76FC: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x800A7700: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x800A7704: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A7708: lw          $t0, 0x120($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X120);
    // 0x800A770C: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x800A7710: ori         $t9, $t9, 0x233
    ctx->r25 = ctx->r25 | 0X233;
    // 0x800A7714: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A7718: b           L_800A780C
    // 0x800A771C: nop

        goto L_800A780C;
    // 0x800A771C: nop

L_800A7720:
    // 0x800A7720: lw          $t1, 0x178($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X178);
    // 0x800A7724: nop

    // 0x800A7728: andi        $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 & 0X8000;
    // 0x800A772C: beq         $t3, $zero, L_800A77A4
    if (ctx->r11 == 0) {
        // 0x800A7730: nop
    
            goto L_800A77A4;
    }
    // 0x800A7730: nop

    // 0x800A7734: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7738: nop

    // 0x800A773C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800A7740: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A7744: sw          $t2, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r10;
    // 0x800A7748: lw          $t6, 0x11C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X11C);
    // 0x800A774C: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x800A7750: ori         $t5, $t5, 0xFE24
    ctx->r13 = ctx->r13 | 0XFE24;
    // 0x800A7754: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A7758: lw          $t8, 0x11C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X11C);
    // 0x800A775C: lui         $t7, 0xFF30
    ctx->r15 = S32(0XFF30 << 16);
    // 0x800A7760: ori         $t7, $t7, 0xF3FF
    ctx->r15 = ctx->r15 | 0XF3FF;
    // 0x800A7764: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A7768: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A776C: nop

    // 0x800A7770: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A7774: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A7778: sw          $t9, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r25;
    // 0x800A777C: lw          $t3, 0x118($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X118);
    // 0x800A7780: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x800A7784: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x800A7788: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A778C: lw          $t4, 0x118($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X118);
    // 0x800A7790: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x800A7794: ori         $t2, $t2, 0x4A50
    ctx->r10 = ctx->r10 | 0X4A50;
    // 0x800A7798: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800A779C: b           L_800A780C
    // 0x800A77A0: nop

        goto L_800A780C;
    // 0x800A77A0: nop

L_800A77A4:
    // 0x800A77A4: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A77A8: nop

    // 0x800A77AC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A77B0: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A77B4: sw          $t5, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r13;
    // 0x800A77B8: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x800A77BC: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x800A77C0: ori         $t7, $t7, 0xFE24
    ctx->r15 = ctx->r15 | 0XFE24;
    // 0x800A77C4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A77C8: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800A77CC: lui         $t9, 0xFF30
    ctx->r25 = S32(0XFF30 << 16);
    // 0x800A77D0: ori         $t9, $t9, 0xF3FF
    ctx->r25 = ctx->r25 | 0XF3FF;
    // 0x800A77D4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A77D8: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A77DC: nop

    // 0x800A77E0: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A77E4: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A77E8: sw          $t1, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r9;
    // 0x800A77EC: lw          $t4, 0x110($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X110);
    // 0x800A77F0: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x800A77F4: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x800A77F8: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A77FC: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x800A7800: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x800A7804: ori         $t5, $t5, 0x3078
    ctx->r13 = ctx->r13 | 0X3078;
    // 0x800A7808: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_800A780C:
    // 0x800A780C: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x800A7810: nop

    // 0x800A7814: andi        $t8, $t7, 0x800
    ctx->r24 = ctx->r15 & 0X800;
    // 0x800A7818: bne         $t8, $zero, L_800A7854
    if (ctx->r24 != 0) {
        // 0x800A781C: nop
    
            goto L_800A7854;
    }
    // 0x800A781C: nop

    // 0x800A7820: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7824: nop

    // 0x800A7828: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A782C: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A7830: sw          $t9, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r25;
    // 0x800A7834: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    // 0x800A7838: lui         $t1, 0xB700
    ctx->r9 = S32(0XB700 << 16);
    // 0x800A783C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A7840: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x800A7844: addiu       $t2, $zero, 0x205
    ctx->r10 = ADD32(0, 0X205);
    // 0x800A7848: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800A784C: b           L_800A7880
    // 0x800A7850: nop

        goto L_800A7880;
    // 0x800A7850: nop

L_800A7854:
    // 0x800A7854: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7858: nop

    // 0x800A785C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A7860: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A7864: sw          $t5, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r13;
    // 0x800A7868: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x800A786C: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x800A7870: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A7874: lw          $t0, 0x108($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X108);
    // 0x800A7878: addiu       $t9, $zero, 0x2205
    ctx->r25 = ADD32(0, 0X2205);
    // 0x800A787C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_800A7880:
    // 0x800A7880: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7884: nop

    // 0x800A7888: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A788C: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A7890: sw          $t1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r9;
    // 0x800A7894: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x800A7898: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x800A789C: ori         $t2, $t2, 0x1301
    ctx->r10 = ctx->r10 | 0X1301;
    // 0x800A78A0: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A78A4: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800A78A8: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x800A78AC: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A78B0: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A78B4: nop

    // 0x800A78B8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A78BC: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A78C0: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x800A78C4: lw          $t0, 0x100($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X100);
    // 0x800A78C8: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A78CC: ori         $t9, $t9, 0x1102
    ctx->r25 = ctx->r25 | 0X1102;
    // 0x800A78D0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A78D4: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x800A78D8: nop

    // 0x800A78DC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A78E0: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A78E4: nop

    // 0x800A78E8: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A78EC: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A78F0: sw          $t3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r11;
    // 0x800A78F4: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x800A78F8: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800A78FC: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x800A7900: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A7904: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x800A7908: nop

    // 0x800A790C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A7910: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7914: nop

    // 0x800A7918: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A791C: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A7920: sw          $t7, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r15;
    // 0x800A7924: lw          $t0, 0xF8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF8);
    // 0x800A7928: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A792C: ori         $t9, $t9, 0x903
    ctx->r25 = ctx->r25 | 0X903;
    // 0x800A7930: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A7934: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x800A7938: addiu       $t1, $zero, 0xC00
    ctx->r9 = ADD32(0, 0XC00);
    // 0x800A793C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800A7940: lw          $t2, 0x178($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X178);
    // 0x800A7944: nop

    // 0x800A7948: andi        $t4, $t2, 0x4
    ctx->r12 = ctx->r10 & 0X4;
    // 0x800A794C: bne         $t4, $zero, L_800A798C
    if (ctx->r12 != 0) {
        // 0x800A7950: nop
    
            goto L_800A798C;
    }
    // 0x800A7950: nop

    // 0x800A7954: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7958: nop

    // 0x800A795C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A7960: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A7964: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800A7968: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x800A796C: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A7970: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x800A7974: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A7978: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x800A797C: nop

    // 0x800A7980: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A7984: b           L_800A79BC
    // 0x800A7988: nop

        goto L_800A79BC;
    // 0x800A7988: nop

L_800A798C:
    // 0x800A798C: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7990: nop

    // 0x800A7994: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A7998: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A799C: sw          $t0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r8;
    // 0x800A79A0: lw          $t2, 0xF0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF0);
    // 0x800A79A4: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A79A8: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x800A79AC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A79B0: lw          $t5, 0xF0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF0);
    // 0x800A79B4: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x800A79B8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_800A79BC:
    // 0x800A79BC: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A79C0: nop

    // 0x800A79C4: lh          $t7, 0x10C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10C);
    // 0x800A79C8: nop

    // 0x800A79CC: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x800A79D0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800A79D4: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A79D8: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A79DC: nop

    // 0x800A79E0: lh          $t1, 0x10E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10E);
    // 0x800A79E4: nop

    // 0x800A79E8: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x800A79EC: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x800A79F0: sw          $t2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r10;
    // 0x800A79F4: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A79F8: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x800A79FC: lwc1        $f10, 0xB0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XB0);
    // 0x800A7A00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A7A04: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800A7A08: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A7A0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A7A10: nop

    // 0x800A7A14: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A7A18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7A1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7A20: nop

    // 0x800A7A24: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A7A28: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800A7A2C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A7A30: sw          $t6, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r14;
    // 0x800A7A34: nop

    // 0x800A7A38: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7A3C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800A7A40: lh          $t8, 0x10C($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X10C);
    // 0x800A7A44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A7A48: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800A7A4C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A7A50: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A7A54: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7A58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7A5C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A7A60: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A7A64: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800A7A68: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A7A6C: nop

    // 0x800A7A70: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A7A74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7A78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7A7C: nop

    // 0x800A7A80: cvt.w.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_D(ctx->f18.d);
    // 0x800A7A84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A7A88: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
    // 0x800A7A8C: nop

    // 0x800A7A90: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800A7A94: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A7A98: nop

    // 0x800A7A9C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800A7AA0: addiu       $t2, $t3, -0x3F
    ctx->r10 = ADD32(ctx->r11, -0X3F);
    // 0x800A7AA4: bgez        $t2, L_800A7AB4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A7AA8: sra         $t4, $t2, 6
        ctx->r12 = S32(SIGNED(ctx->r10) >> 6);
            goto L_800A7AB4;
    }
    // 0x800A7AA8: sra         $t4, $t2, 6
    ctx->r12 = S32(SIGNED(ctx->r10) >> 6);
    // 0x800A7AAC: addiu       $at, $t2, 0x3F
    ctx->r1 = ADD32(ctx->r10, 0X3F);
    // 0x800A7AB0: sra         $t4, $at, 6
    ctx->r12 = S32(SIGNED(ctx->r1) >> 6);
L_800A7AB4:
    // 0x800A7AB4: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800A7AB8: sw          $t5, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r13;
    // 0x800A7ABC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A7AC0: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7AC4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A7AC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7ACC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7AD0: lwc1        $f4, 0xB4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XB4);
    // 0x800A7AD4: nop

    // 0x800A7AD8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A7ADC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A7AE0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A7AE4: addiu       $t9, $t8, -0x80
    ctx->r25 = ADD32(ctx->r24, -0X80);
    // 0x800A7AE8: sw          $t9, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r25;
    // 0x800A7AEC: lw          $t0, 0x180($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X180);
    // 0x800A7AF0: nop

    // 0x800A7AF4: bgez        $t0, L_800A7B04
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A7AF8: sra         $t1, $t0, 5
        ctx->r9 = S32(SIGNED(ctx->r8) >> 5);
            goto L_800A7B04;
    }
    // 0x800A7AF8: sra         $t1, $t0, 5
    ctx->r9 = S32(SIGNED(ctx->r8) >> 5);
    // 0x800A7AFC: addiu       $at, $t0, 0x1F
    ctx->r1 = ADD32(ctx->r8, 0X1F);
    // 0x800A7B00: sra         $t1, $at, 5
    ctx->r9 = S32(SIGNED(ctx->r1) >> 5);
L_800A7B04:
    // 0x800A7B04: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x800A7B08: addiu       $t2, $t3, -0x20
    ctx->r10 = ADD32(ctx->r11, -0X20);
    // 0x800A7B0C: sw          $t2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r10;
    // 0x800A7B10: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7B14: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800A7B18: lh          $t5, 0x10E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X10E);
    // 0x800A7B1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A7B20: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800A7B24: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A7B28: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7B2C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A7B30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A7B34: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A7B38: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800A7B3C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800A7B40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A7B44: nop

    // 0x800A7B48: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A7B4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7B50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7B54: nop

    // 0x800A7B58: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A7B5C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A7B60: swc1        $f16, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f16.u32l;
    // 0x800A7B64: nop

    // 0x800A7B68: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
L_800A7B6C:
    // 0x800A7B6C: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800A7B70: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A7B74: nop

    // 0x800A7B78: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A7B7C: beq         $at, $zero, L_800A7B8C
    if (ctx->r1 == 0) {
        // 0x800A7B80: nop
    
            goto L_800A7B8C;
    }
    // 0x800A7B80: nop

    // 0x800A7B84: b           L_800A94BC
    // 0x800A7B88: nop

        goto L_800A94BC;
    // 0x800A7B88: nop

L_800A7B8C:
    // 0x800A7B8C: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800A7B90: nop

    // 0x800A7B94: bgez        $t9, L_800A7BA4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A7B98: nop
    
            goto L_800A7BA4;
    }
    // 0x800A7B98: nop

    // 0x800A7B9C: b           L_800A94BC
    // 0x800A7BA0: nop

        goto L_800A94BC;
    // 0x800A7BA0: nop

L_800A7BA4:
    // 0x800A7BA4: sw          $zero, 0x154($sp)
    MEM_W(0X154, ctx->r29) = 0;
    // 0x800A7BA8: lw          $t0, 0x180($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X180);
    // 0x800A7BAC: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x800A7BB0: sw          $zero, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = 0;
    // 0x800A7BB4: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800A7BB8: sw          $t3, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r11;
L_800A7BBC:
    // 0x800A7BBC: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800A7BC0: lw          $t4, 0x188($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X188);
    // 0x800A7BC4: nop

    // 0x800A7BC8: slt         $at, $t4, $t2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A7BCC: beq         $at, $zero, L_800A7BDC
    if (ctx->r1 == 0) {
        // 0x800A7BD0: nop
    
            goto L_800A7BDC;
    }
    // 0x800A7BD0: nop

    // 0x800A7BD4: b           L_800A8FD8
    // 0x800A7BD8: nop

        goto L_800A8FD8;
    // 0x800A7BD8: nop

L_800A7BDC:
    // 0x800A7BDC: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800A7BE0: nop

    // 0x800A7BE4: bgez        $t5, L_800A7BF4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A7BE8: nop
    
            goto L_800A7BF4;
    }
    // 0x800A7BE8: nop

    // 0x800A7BEC: b           L_800A8FD8
    // 0x800A7BF0: nop

        goto L_800A8FD8;
    // 0x800A7BF0: nop

L_800A7BF4:
    // 0x800A7BF4: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7BF8: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x800A7BFC: lh          $t9, 0x10C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X10C);
    // 0x800A7C00: bgez        $t6, L_800A7C10
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800A7C04: sra         $t7, $t6, 8
        ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
            goto L_800A7C10;
    }
    // 0x800A7C04: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800A7C08: addiu       $at, $t6, 0xFF
    ctx->r1 = ADD32(ctx->r14, 0XFF);
    // 0x800A7C0C: sra         $t7, $at, 8
    ctx->r15 = S32(SIGNED(ctx->r1) >> 8);
L_800A7C10:
    // 0x800A7C10: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7C14: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A7C18: mflo        $t0
    ctx->r8 = lo;
    // 0x800A7C1C: bgez        $t1, L_800A7C2C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800A7C20: sra         $t3, $t1, 6
        ctx->r11 = S32(SIGNED(ctx->r9) >> 6);
            goto L_800A7C2C;
    }
    // 0x800A7C20: sra         $t3, $t1, 6
    ctx->r11 = S32(SIGNED(ctx->r9) >> 6);
    // 0x800A7C24: addiu       $at, $t1, 0x3F
    ctx->r1 = ADD32(ctx->r9, 0X3F);
    // 0x800A7C28: sra         $t3, $at, 6
    ctx->r11 = S32(SIGNED(ctx->r1) >> 6);
L_800A7C2C:
    // 0x800A7C2C: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x800A7C30: sw          $t2, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r10;
    // 0x800A7C34: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7C38: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A7C3C: lw          $t5, 0x13C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X13C);
    // 0x800A7C40: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800A7C44: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800A7C48: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800A7C4C: lh          $t3, 0x124($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X124);
    // 0x800A7C50: bgez        $t9, L_800A7C60
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A7C54: sra         $t1, $t9, 12
        ctx->r9 = S32(SIGNED(ctx->r25) >> 12);
            goto L_800A7C60;
    }
    // 0x800A7C54: sra         $t1, $t9, 12
    ctx->r9 = S32(SIGNED(ctx->r25) >> 12);
    // 0x800A7C58: addiu       $at, $t9, 0xFFF
    ctx->r1 = ADD32(ctx->r25, 0XFFF);
    // 0x800A7C5C: sra         $t1, $at, 12
    ctx->r9 = S32(SIGNED(ctx->r1) >> 12);
L_800A7C60:
    // 0x800A7C60: andi        $t0, $t1, 0x7
    ctx->r8 = ctx->r9 & 0X7;
    // 0x800A7C64: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x800A7C68: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x800A7C6C: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x800A7C70: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7C74: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800A7C78: lw          $t5, 0x13C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X13C);
    // 0x800A7C7C: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x800A7C80: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800A7C84: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x800A7C88: lw          $t9, 0x140($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X140);
    // 0x800A7C8C: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x800A7C90: sll         $t0, $t4, 3
    ctx->r8 = S32(ctx->r12 << 3);
    // 0x800A7C94: bgez        $t3, L_800A7CA8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A7C98: andi        $t2, $t3, 0xFF
        ctx->r10 = ctx->r11 & 0XFF;
            goto L_800A7CA8;
    }
    // 0x800A7C98: andi        $t2, $t3, 0xFF
    ctx->r10 = ctx->r11 & 0XFF;
    // 0x800A7C9C: beq         $t2, $zero, L_800A7CA8
    if (ctx->r10 == 0) {
        // 0x800A7CA0: nop
    
            goto L_800A7CA8;
    }
    // 0x800A7CA0: nop

    // 0x800A7CA4: addiu       $t2, $t2, -0x100
    ctx->r10 = ADD32(ctx->r10, -0X100);
L_800A7CA8:
    // 0x800A7CA8: bgez        $t2, L_800A7CB8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A7CAC: sra         $t8, $t2, 5
        ctx->r24 = S32(SIGNED(ctx->r10) >> 5);
            goto L_800A7CB8;
    }
    // 0x800A7CAC: sra         $t8, $t2, 5
    ctx->r24 = S32(SIGNED(ctx->r10) >> 5);
    // 0x800A7CB0: addiu       $at, $t2, 0x1F
    ctx->r1 = ADD32(ctx->r10, 0X1F);
    // 0x800A7CB4: sra         $t8, $at, 5
    ctx->r24 = S32(SIGNED(ctx->r1) >> 5);
L_800A7CB8:
    // 0x800A7CB8: addu        $t5, $t0, $t8
    ctx->r13 = ADD32(ctx->r8, ctx->r24);
    // 0x800A7CBC: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800A7CC0: addu        $t1, $t9, $t7
    ctx->r9 = ADD32(ctx->r25, ctx->r15);
    // 0x800A7CC4: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x800A7CC8: nop

    // 0x800A7CCC: sh          $t4, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r12;
    // 0x800A7CD0: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7CD4: lhu         $t0, 0x14A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A7CD8: lw          $t2, 0x110($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X110);
    // 0x800A7CDC: nop

    // 0x800A7CE0: bne         $t2, $t0, L_800A7CF0
    if (ctx->r10 != ctx->r8) {
        // 0x800A7CE4: nop
    
            goto L_800A7CF0;
    }
    // 0x800A7CE4: nop

    // 0x800A7CE8: b           L_800A8FD8
    // 0x800A7CEC: nop

        goto L_800A8FD8;
    // 0x800A7CEC: nop

L_800A7CF0:
    // 0x800A7CF0: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7CF4: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A7CF8: lw          $t5, 0x13C($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X13C);
    // 0x800A7CFC: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800A7D00: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x800A7D04: lhu         $t1, 0x0($t7)
    ctx->r9 = MEM_HU(ctx->r15, 0X0);
    // 0x800A7D08: nop

    // 0x800A7D0C: andi        $t4, $t1, 0x8000
    ctx->r12 = ctx->r9 & 0X8000;
    // 0x800A7D10: sw          $t4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r12;
    // 0x800A7D14: lhu         $t3, 0x14A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A7D18: lw          $t0, 0x170($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X170);
    // 0x800A7D1C: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7D20: bgez        $t3, L_800A7D30
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A7D24: sra         $t2, $t3, 12
        ctx->r10 = S32(SIGNED(ctx->r11) >> 12);
            goto L_800A7D30;
    }
    // 0x800A7D24: sra         $t2, $t3, 12
    ctx->r10 = S32(SIGNED(ctx->r11) >> 12);
    // 0x800A7D28: addiu       $at, $t3, 0xFFF
    ctx->r1 = ADD32(ctx->r11, 0XFFF);
    // 0x800A7D2C: sra         $t2, $at, 12
    ctx->r10 = S32(SIGNED(ctx->r1) >> 12);
L_800A7D30:
    // 0x800A7D30: lh          $t9, 0x122($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X122);
    // 0x800A7D34: addu        $t8, $t2, $t0
    ctx->r24 = ADD32(ctx->r10, ctx->r8);
    // 0x800A7D38: andi        $t6, $t8, 0x7
    ctx->r14 = ctx->r24 & 0X7;
    // 0x800A7D3C: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A7D40: beq         $at, $zero, L_800A7D50
    if (ctx->r1 == 0) {
        // 0x800A7D44: nop
    
            goto L_800A7D50;
    }
    // 0x800A7D44: nop

    // 0x800A7D48: b           L_800A7D68
    // 0x800A7D4C: sw          $t6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r14;
        goto L_800A7D68;
    // 0x800A7D4C: sw          $t6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r14;
L_800A7D50:
    // 0x800A7D50: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7D54: nop

    // 0x800A7D58: lh          $t1, 0x122($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X122);
    // 0x800A7D5C: nop

    // 0x800A7D60: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x800A7D64: sw          $t4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r12;
L_800A7D68:
    // 0x800A7D68: lhu         $t3, 0x14A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A7D6C: nop

    // 0x800A7D70: andi        $t2, $t3, 0xFFF
    ctx->r10 = ctx->r11 & 0XFFF;
    // 0x800A7D74: sh          $t2, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r10;
    // 0x800A7D78: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800A7D7C: nop

    // 0x800A7D80: bne         $t0, $zero, L_800A7D98
    if (ctx->r8 != 0) {
        // 0x800A7D84: nop
    
            goto L_800A7D98;
    }
    // 0x800A7D84: nop

    // 0x800A7D88: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A7D8C: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A7D90: nop

    // 0x800A7D94: sw          $t8, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r24;
L_800A7D98:
    // 0x800A7D98: lw          $t5, 0x174($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X174);
    // 0x800A7D9C: lw          $t9, 0x170($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X170);
    // 0x800A7DA0: nop

    // 0x800A7DA4: beq         $t5, $t9, L_800A80CC
    if (ctx->r13 == ctx->r25) {
        // 0x800A7DA8: nop
    
            goto L_800A80CC;
    }
    // 0x800A7DA8: nop

    // 0x800A7DAC: lw          $t6, 0x170($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X170);
    // 0x800A7DB0: nop

    // 0x800A7DB4: sw          $t6, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r14;
    // 0x800A7DB8: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7DBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A7DC0: lh          $t1, 0x116($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X116);
    // 0x800A7DC4: nop

    // 0x800A7DC8: beq         $t1, $at, L_800A8070
    if (ctx->r9 == ctx->r1) {
        // 0x800A7DCC: nop
    
            goto L_800A8070;
    }
    // 0x800A7DCC: nop

    // 0x800A7DD0: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7DD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7DD8: lh          $t3, 0x116($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X116);
    // 0x800A7DDC: nop

    // 0x800A7DE0: bne         $t3, $at, L_800A7F14
    if (ctx->r11 != ctx->r1) {
        // 0x800A7DE4: nop
    
            goto L_800A7F14;
    }
    // 0x800A7DE4: nop

    // 0x800A7DE8: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7DEC: nop

    // 0x800A7DF0: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A7DF4: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A7DF8: sw          $t2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r10;
    // 0x800A7DFC: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x800A7E00: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800A7E04: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800A7E08: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7E0C: lw          $t7, 0x174($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X174);
    // 0x800A7E10: lw          $t6, 0x138($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X138);
    // 0x800A7E14: sll         $t1, $t7, 8
    ctx->r9 = S32(ctx->r15 << 8);
    // 0x800A7E18: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x800A7E1C: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x800A7E20: addu        $t3, $t6, $t4
    ctx->r11 = ADD32(ctx->r14, ctx->r12);
    // 0x800A7E24: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x800A7E28: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7E2C: nop

    // 0x800A7E30: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A7E34: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A7E38: sw          $t0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r8;
    // 0x800A7E3C: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
    // 0x800A7E40: lui         $t5, 0xE800
    ctx->r13 = S32(0XE800 << 16);
    // 0x800A7E44: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800A7E48: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x800A7E4C: nop

    // 0x800A7E50: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A7E54: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7E58: nop

    // 0x800A7E5C: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x800A7E60: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A7E64: sw          $t1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r9;
    // 0x800A7E68: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x800A7E6C: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x800A7E70: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x800A7E74: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A7E78: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x800A7E7C: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x800A7E80: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800A7E84: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7E88: nop

    // 0x800A7E8C: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x800A7E90: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A7E94: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x800A7E98: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x800A7E9C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800A7EA0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A7EA4: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x800A7EA8: nop

    // 0x800A7EAC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A7EB0: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7EB4: nop

    // 0x800A7EB8: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x800A7EBC: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A7EC0: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x800A7EC4: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x800A7EC8: lui         $t3, 0xF000
    ctx->r11 = S32(0XF000 << 16);
    // 0x800A7ECC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A7ED0: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800A7ED4: lui         $t0, 0x73F
    ctx->r8 = S32(0X73F << 16);
    // 0x800A7ED8: ori         $t0, $t0, 0xC000
    ctx->r8 = ctx->r8 | 0XC000;
    // 0x800A7EDC: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800A7EE0: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7EE4: nop

    // 0x800A7EE8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800A7EEC: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A7EF0: sw          $t5, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r13;
    // 0x800A7EF4: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x800A7EF8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800A7EFC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800A7F00: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x800A7F04: nop

    // 0x800A7F08: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A7F0C: b           L_800A8038
    // 0x800A7F10: nop

        goto L_800A8038;
    // 0x800A7F10: nop

L_800A7F14:
    // 0x800A7F14: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7F18: nop

    // 0x800A7F1C: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800A7F20: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A7F24: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
    // 0x800A7F28: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x800A7F2C: lui         $t2, 0xFD10
    ctx->r10 = S32(0XFD10 << 16);
    // 0x800A7F30: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A7F34: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7F38: lw          $t9, 0x174($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X174);
    // 0x800A7F3C: lw          $t5, 0x138($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X138);
    // 0x800A7F40: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800A7F44: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x800A7F48: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x800A7F4C: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x800A7F50: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800A7F54: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7F58: nop

    // 0x800A7F5C: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A7F60: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A7F64: sw          $t3, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r11;
    // 0x800A7F68: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800A7F6C: lui         $t0, 0xE800
    ctx->r8 = S32(0XE800 << 16);
    // 0x800A7F70: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800A7F74: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800A7F78: nop

    // 0x800A7F7C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A7F80: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7F84: nop

    // 0x800A7F88: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800A7F8C: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A7F90: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x800A7F94: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800A7F98: lui         $t1, 0xF500
    ctx->r9 = S32(0XF500 << 16);
    // 0x800A7F9C: ori         $t1, $t1, 0x100
    ctx->r9 = ctx->r9 | 0X100;
    // 0x800A7FA0: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x800A7FA4: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x800A7FA8: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x800A7FAC: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A7FB0: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7FB4: nop

    // 0x800A7FB8: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A7FBC: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A7FC0: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x800A7FC4: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800A7FC8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800A7FCC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A7FD0: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x800A7FD4: nop

    // 0x800A7FD8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A7FDC: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7FE0: nop

    // 0x800A7FE4: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x800A7FE8: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A7FEC: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A7FF0: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A7FF4: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x800A7FF8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800A7FFC: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800A8000: lui         $t3, 0x703
    ctx->r11 = S32(0X703 << 16);
    // 0x800A8004: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x800A8008: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x800A800C: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8010: nop

    // 0x800A8014: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A8018: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A801C: sw          $t0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r8;
    // 0x800A8020: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800A8024: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800A8028: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A802C: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x800A8030: nop

    // 0x800A8034: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
L_800A8038:
    // 0x800A8038: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A803C: nop

    // 0x800A8040: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x800A8044: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A8048: sw          $t1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r9;
    // 0x800A804C: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x800A8050: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800A8054: ori         $t4, $t4, 0xE02
    ctx->r12 = ctx->r12 | 0XE02;
    // 0x800A8058: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A805C: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800A8060: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800A8064: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800A8068: b           L_800A80A0
    // 0x800A806C: nop

        goto L_800A80A0;
    // 0x800A806C: nop

L_800A8070:
    // 0x800A8070: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8074: nop

    // 0x800A8078: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A807C: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A8080: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x800A8084: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800A8088: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A808C: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x800A8090: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800A8094: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x800A8098: nop

    // 0x800A809C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
L_800A80A0:
    // 0x800A80A0: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A80A4: nop

    // 0x800A80A8: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x800A80AC: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A80B0: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x800A80B4: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x800A80B8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800A80BC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A80C0: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800A80C4: nop

    // 0x800A80C8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800A80CC:
    // 0x800A80CC: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x800A80D0: nop

    // 0x800A80D4: bne         $t8, $zero, L_800A85E4
    if (ctx->r24 != 0) {
        // 0x800A80D8: nop
    
            goto L_800A85E4;
    }
    // 0x800A80D8: nop

    // 0x800A80DC: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800A80E0: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x800A80E4: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A80E8: subu        $t5, $t9, $t7
    ctx->r13 = SUB32(ctx->r25, ctx->r15);
    // 0x800A80EC: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800A80F0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A80F4: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A80F8: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A80FC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A8100: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A8104: nop

    // 0x800A8108: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A810C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8110: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8114: nop

    // 0x800A8118: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A811C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800A8120: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A8124: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x800A8128: nop

    // 0x800A812C: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x800A8130: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8134: lwc1        $f10, 0x140($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A8138: subu        $t0, $t3, $t2
    ctx->r8 = SUB32(ctx->r11, ctx->r10);
    // 0x800A813C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A8140: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8144: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8148: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A814C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A8150: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8154: nop

    // 0x800A8158: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A815C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8160: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8164: nop

    // 0x800A8168: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A816C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800A8170: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8174: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x800A8178: nop

    // 0x800A817C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A8180: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8184: lhu         $t5, 0x14A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A8188: nop

    // 0x800A818C: sh          $t5, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r13;
    // 0x800A8190: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A8194: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8198: nop

    // 0x800A819C: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800A81A0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A81A4: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A81A8: nop

    // 0x800A81AC: sh          $zero, 0xA($t4)
    MEM_H(0XA, ctx->r12) = 0;
    // 0x800A81B0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A81B4: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A81B8: nop

    // 0x800A81BC: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x800A81C0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A81C4: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A81C8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A81CC: sb          $t2, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r10;
    // 0x800A81D0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A81D4: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A81D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A81DC: sb          $t8, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r24;
    // 0x800A81E0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A81E4: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A81E8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A81EC: sb          $t7, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r15;
    // 0x800A81F0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800A81F4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A81F8: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A81FC: lh          $t1, -0x4CDC($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CDC);
    // 0x800A8200: nop

    // 0x800A8204: sb          $t1, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r9;
    // 0x800A8208: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A820C: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A8210: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A8214: addiu       $t3, $t4, 0x10
    ctx->r11 = ADD32(ctx->r12, 0X10);
    // 0x800A8218: sw          $t3, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r11;
    // 0x800A821C: lw          $t2, 0x184($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X184);
    // 0x800A8220: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8224: lwc1        $f18, 0x144($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A8228: subu        $t8, $t2, $t0
    ctx->r24 = SUB32(ctx->r10, ctx->r8);
    // 0x800A822C: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x800A8230: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800A8234: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A8238: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A823C: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8240: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A8244: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A8248: nop

    // 0x800A824C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8250: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8254: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8258: nop

    // 0x800A825C: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A8260: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800A8264: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A8268: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
    // 0x800A826C: nop

    // 0x800A8270: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x800A8274: lw          $t4, 0x17C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8278: lwc1        $f16, 0x140($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A827C: subu        $t3, $t6, $t4
    ctx->r11 = SUB32(ctx->r14, ctx->r12);
    // 0x800A8280: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A8284: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8288: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A828C: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8290: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8294: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A8298: nop

    // 0x800A829C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A82A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A82A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A82A8: nop

    // 0x800A82AC: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A82B0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800A82B4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A82B8: sh          $t0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r8;
    // 0x800A82BC: nop

    // 0x800A82C0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A82C4: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A82C8: nop

    // 0x800A82CC: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
    // 0x800A82D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A82D4: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A82D8: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x800A82DC: sh          $t7, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r15;
    // 0x800A82E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A82E4: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A82E8: nop

    // 0x800A82EC: sh          $zero, 0xA($t1)
    MEM_H(0XA, ctx->r9) = 0;
    // 0x800A82F0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A82F4: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A82F8: nop

    // 0x800A82FC: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x800A8300: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8304: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8308: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A830C: sb          $t4, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r12;
    // 0x800A8310: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A8314: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8318: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A831C: sb          $t2, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r10;
    // 0x800A8320: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A8324: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A8328: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A832C: sb          $t8, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r24;
    // 0x800A8330: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800A8334: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A8338: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A833C: lh          $t7, -0x4CDC($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4CDC);
    // 0x800A8340: nop

    // 0x800A8344: sb          $t7, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r15;
    // 0x800A8348: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A834C: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8350: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A8354: addiu       $t6, $t1, 0x10
    ctx->r14 = ADD32(ctx->r9, 0X10);
    // 0x800A8358: sw          $t6, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r14;
    // 0x800A835C: lw          $t4, 0x184($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X184);
    // 0x800A8360: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8364: lwc1        $f8, 0x144($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A8368: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800A836C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A8370: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A8374: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8378: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A837C: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A8380: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A8384: nop

    // 0x800A8388: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A838C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8390: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8394: nop

    // 0x800A8398: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A839C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800A83A0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A83A4: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x800A83A8: nop

    // 0x800A83AC: lw          $t7, 0x168($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X168);
    // 0x800A83B0: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800A83B4: lwc1        $f6, 0x140($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A83B8: subu        $t1, $t7, $t5
    ctx->r9 = SUB32(ctx->r15, ctx->r13);
    // 0x800A83BC: addiu       $t6, $t1, -0x20
    ctx->r14 = ADD32(ctx->r9, -0X20);
    // 0x800A83C0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A83C4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A83C8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A83CC: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A83D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A83D4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A83D8: nop

    // 0x800A83DC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A83E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A83E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A83E8: nop

    // 0x800A83EC: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A83F0: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800A83F4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A83F8: sh          $t3, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r11;
    // 0x800A83FC: nop

    // 0x800A8400: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A8404: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8408: nop

    // 0x800A840C: sh          $zero, 0x4($t0)
    MEM_H(0X4, ctx->r8) = 0;
    // 0x800A8410: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8414: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8418: nop

    // 0x800A841C: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x800A8420: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8424: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8428: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x800A842C: sh          $t9, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r25;
    // 0x800A8430: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A8434: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A8438: nop

    // 0x800A843C: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800A8440: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A8444: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8448: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A844C: sb          $t1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r9;
    // 0x800A8450: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8454: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8458: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A845C: sb          $t4, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r12;
    // 0x800A8460: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A8464: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8468: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A846C: sb          $t2, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r10;
    // 0x800A8470: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800A8474: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A8478: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A847C: lh          $t8, -0x4CDC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CDC);
    // 0x800A8480: nop

    // 0x800A8484: sb          $t8, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r24;
    // 0x800A8488: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A848C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8490: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A8494: addiu       $t5, $t7, 0x10
    ctx->r13 = ADD32(ctx->r15, 0X10);
    // 0x800A8498: sw          $t5, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r13;
    // 0x800A849C: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A84A0: lw          $t6, 0x16C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X16C);
    // 0x800A84A4: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A84A8: subu        $t4, $t1, $t6
    ctx->r12 = SUB32(ctx->r9, ctx->r14);
    // 0x800A84AC: addiu       $t3, $t4, 0x40
    ctx->r11 = ADD32(ctx->r12, 0X40);
    // 0x800A84B0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800A84B4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A84B8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A84BC: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A84C0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A84C4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A84C8: nop

    // 0x800A84CC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A84D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A84D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A84D8: nop

    // 0x800A84DC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A84E0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800A84E4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A84E8: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x800A84EC: nop

    // 0x800A84F0: lw          $t9, 0x168($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X168);
    // 0x800A84F4: lw          $t7, 0x17C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X17C);
    // 0x800A84F8: lwc1        $f10, 0x140($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A84FC: subu        $t5, $t9, $t7
    ctx->r13 = SUB32(ctx->r25, ctx->r15);
    // 0x800A8500: addiu       $t1, $t5, -0x20
    ctx->r9 = ADD32(ctx->r13, -0X20);
    // 0x800A8504: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800A8508: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A850C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8510: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8514: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A8518: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A851C: nop

    // 0x800A8520: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A8524: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8528: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A852C: nop

    // 0x800A8530: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A8534: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800A8538: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A853C: sh          $t4, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r12;
    // 0x800A8540: nop

    // 0x800A8544: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A8548: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A854C: nop

    // 0x800A8550: sh          $zero, 0x4($t2)
    MEM_H(0X4, ctx->r10) = 0;
    // 0x800A8554: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8558: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A855C: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x800A8560: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
    // 0x800A8564: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8568: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A856C: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x800A8570: sh          $t9, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r25;
    // 0x800A8574: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A8578: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A857C: nop

    // 0x800A8580: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800A8584: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A8588: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A858C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A8590: sb          $t1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r9;
    // 0x800A8594: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8598: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A859C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A85A0: sb          $t4, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r12;
    // 0x800A85A4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A85A8: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A85AC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A85B0: sb          $t2, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r10;
    // 0x800A85B4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800A85B8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A85BC: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A85C0: lh          $t8, -0x4CDC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CDC);
    // 0x800A85C4: nop

    // 0x800A85C8: sb          $t8, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r24;
    // 0x800A85CC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A85D0: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A85D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A85D8: addiu       $t5, $t7, 0x10
    ctx->r13 = ADD32(ctx->r15, 0X10);
    // 0x800A85DC: b           L_800A8AE8
    // 0x800A85E0: sw          $t5, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r13;
        goto L_800A8AE8;
    // 0x800A85E0: sw          $t5, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r13;
L_800A85E4:
    // 0x800A85E4: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A85E8: lw          $t6, 0x16C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X16C);
    // 0x800A85EC: lwc1        $f18, 0x144($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A85F0: subu        $t4, $t1, $t6
    ctx->r12 = SUB32(ctx->r9, ctx->r14);
    // 0x800A85F4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800A85F8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A85FC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A8600: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8604: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A8608: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A860C: nop

    // 0x800A8610: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A8614: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8618: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A861C: nop

    // 0x800A8620: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A8624: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800A8628: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A862C: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x800A8630: nop

    // 0x800A8634: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800A8638: lw          $t9, 0x17C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X17C);
    // 0x800A863C: lwc1        $f16, 0x140($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A8640: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x800A8644: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800A8648: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A864C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A8650: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8654: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8658: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A865C: nop

    // 0x800A8660: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A8664: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8668: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A866C: nop

    // 0x800A8670: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8674: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800A8678: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A867C: sh          $t1, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r9;
    // 0x800A8680: nop

    // 0x800A8684: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8688: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A868C: lhu         $t4, 0x14A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A8690: nop

    // 0x800A8694: sh          $t4, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r12;
    // 0x800A8698: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A869C: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A86A0: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x800A86A4: sh          $t2, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r10;
    // 0x800A86A8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A86AC: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A86B0: nop

    // 0x800A86B4: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x800A86B8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A86BC: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A86C0: nop

    // 0x800A86C4: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x800A86C8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A86CC: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A86D0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A86D4: sb          $t7, 0xC($t5)
    MEM_B(0XC, ctx->r13) = ctx->r15;
    // 0x800A86D8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A86DC: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A86E0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A86E4: sb          $t1, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r9;
    // 0x800A86E8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A86EC: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A86F0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A86F4: sb          $t4, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r12;
    // 0x800A86F8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800A86FC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A8700: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8704: lh          $t2, -0x4CDC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CDC);
    // 0x800A8708: nop

    // 0x800A870C: sb          $t2, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r10;
    // 0x800A8710: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8714: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8718: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A871C: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800A8720: sw          $t9, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r25;
    // 0x800A8724: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800A8728: lw          $t5, 0x16C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X16C);
    // 0x800A872C: lwc1        $f8, 0x144($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A8730: subu        $t1, $t7, $t5
    ctx->r9 = SUB32(ctx->r15, ctx->r13);
    // 0x800A8734: addiu       $t6, $t1, 0x40
    ctx->r14 = ADD32(ctx->r9, 0X40);
    // 0x800A8738: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A873C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A8740: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8744: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A8748: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A874C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A8750: nop

    // 0x800A8754: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A8758: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A875C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8760: nop

    // 0x800A8764: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A8768: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800A876C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A8770: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x800A8774: nop

    // 0x800A8778: lw          $t0, 0x168($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X168);
    // 0x800A877C: lw          $t8, 0x17C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8780: lwc1        $f6, 0x140($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A8784: subu        $t9, $t0, $t8
    ctx->r25 = SUB32(ctx->r8, ctx->r24);
    // 0x800A8788: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A878C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A8790: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8794: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8798: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A879C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A87A0: nop

    // 0x800A87A4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A87A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A87AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A87B0: nop

    // 0x800A87B4: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A87B8: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800A87BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A87C0: sh          $t5, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r13;
    // 0x800A87C4: nop

    // 0x800A87C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A87CC: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A87D0: nop

    // 0x800A87D4: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x800A87D8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A87DC: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A87E0: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x800A87E4: sh          $t4, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r12;
    // 0x800A87E8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A87EC: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A87F0: nop

    // 0x800A87F4: sh          $zero, 0xA($t2)
    MEM_H(0XA, ctx->r10) = 0;
    // 0x800A87F8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A87FC: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8800: nop

    // 0x800A8804: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x800A8808: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A880C: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A8810: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A8814: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
    // 0x800A8818: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A881C: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A8820: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A8824: sb          $t7, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r15;
    // 0x800A8828: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A882C: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8830: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A8834: sb          $t1, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r9;
    // 0x800A8838: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800A883C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8840: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8844: lh          $t4, -0x4CDC($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CDC);
    // 0x800A8848: nop

    // 0x800A884C: sb          $t4, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r12;
    // 0x800A8850: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A8854: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A8858: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A885C: addiu       $t0, $t2, 0x10
    ctx->r8 = ADD32(ctx->r10, 0X10);
    // 0x800A8860: sw          $t0, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r8;
    // 0x800A8864: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x800A8868: lw          $t9, 0x16C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X16C);
    // 0x800A886C: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A8870: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x800A8874: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800A8878: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A887C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A8880: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8884: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A8888: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A888C: nop

    // 0x800A8890: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A8894: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8898: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A889C: nop

    // 0x800A88A0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A88A4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800A88A8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A88AC: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x800A88B0: nop

    // 0x800A88B4: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x800A88B8: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x800A88BC: lwc1        $f10, 0x140($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A88C0: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800A88C4: addiu       $t0, $t2, -0x20
    ctx->r8 = ADD32(ctx->r10, -0X20);
    // 0x800A88C8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A88CC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A88D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A88D4: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A88D8: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A88DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A88E0: nop

    // 0x800A88E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A88E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A88EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A88F0: nop

    // 0x800A88F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A88F8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800A88FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8900: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x800A8904: nop

    // 0x800A8908: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A890C: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A8910: nop

    // 0x800A8914: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800A8918: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A891C: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8920: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x800A8924: sh          $t1, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r9;
    // 0x800A8928: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A892C: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8930: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x800A8934: sh          $t4, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r12;
    // 0x800A8938: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A893C: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A8940: nop

    // 0x800A8944: sh          $zero, 0x6($t2)
    MEM_H(0X6, ctx->r10) = 0;
    // 0x800A8948: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A894C: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8950: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A8954: sb          $t0, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r8;
    // 0x800A8958: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A895C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8960: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A8964: sb          $t9, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r25;
    // 0x800A8968: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A896C: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8970: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A8974: sb          $t5, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r13;
    // 0x800A8978: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800A897C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A8980: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A8984: lh          $t6, -0x4CDC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CDC);
    // 0x800A8988: nop

    // 0x800A898C: sb          $t6, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r14;
    // 0x800A8990: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8994: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8998: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A899C: addiu       $t2, $t3, 0x10
    ctx->r10 = ADD32(ctx->r11, 0X10);
    // 0x800A89A0: sw          $t2, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r10;
    // 0x800A89A4: lw          $t0, 0x184($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X184);
    // 0x800A89A8: lw          $t8, 0x16C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X16C);
    // 0x800A89AC: lwc1        $f18, 0x144($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A89B0: subu        $t9, $t0, $t8
    ctx->r25 = SUB32(ctx->r8, ctx->r24);
    // 0x800A89B4: addiu       $t7, $t9, 0x40
    ctx->r15 = ADD32(ctx->r25, 0X40);
    // 0x800A89B8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A89BC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A89C0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A89C4: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A89C8: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A89CC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A89D0: nop

    // 0x800A89D4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A89D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A89DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A89E0: nop

    // 0x800A89E4: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A89E8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800A89EC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A89F0: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x800A89F4: nop

    // 0x800A89F8: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x800A89FC: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8A00: lwc1        $f16, 0x140($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A8A04: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800A8A08: addiu       $t0, $t2, -0x20
    ctx->r8 = ADD32(ctx->r10, -0X20);
    // 0x800A8A0C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800A8A10: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8A14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A8A18: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8A1C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8A20: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8A24: nop

    // 0x800A8A28: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A8A2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8A30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8A34: nop

    // 0x800A8A38: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8A3C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800A8A40: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8A44: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x800A8A48: nop

    // 0x800A8A4C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A8A50: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A8A54: nop

    // 0x800A8A58: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800A8A5C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A8A60: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8A64: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x800A8A68: sh          $t1, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r9;
    // 0x800A8A6C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8A70: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8A74: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x800A8A78: sh          $t4, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r12;
    // 0x800A8A7C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A8A80: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A8A84: nop

    // 0x800A8A88: sh          $zero, 0x6($t2)
    MEM_H(0X6, ctx->r10) = 0;
    // 0x800A8A8C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8A90: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8A94: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A8A98: sb          $t0, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r8;
    // 0x800A8A9C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8AA0: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8AA4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A8AA8: sb          $t9, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r25;
    // 0x800A8AAC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A8AB0: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8AB4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A8AB8: sb          $t5, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r13;
    // 0x800A8ABC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800A8AC0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A8AC4: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A8AC8: lh          $t6, -0x4CDC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CDC);
    // 0x800A8ACC: nop

    // 0x800A8AD0: sb          $t6, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r14;
    // 0x800A8AD4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8AD8: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8ADC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A8AE0: addiu       $t2, $t3, 0x10
    ctx->r10 = ADD32(ctx->r11, 0X10);
    // 0x800A8AE4: sw          $t2, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r10;
L_800A8AE8:
    // 0x800A8AE8: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800A8AEC: nop

    // 0x800A8AF0: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x800A8AF4: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
    // 0x800A8AF8: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x800A8AFC: nop

    // 0x800A8B00: slti        $at, $t9, 0x9
    ctx->r1 = SIGNED(ctx->r25) < 0X9 ? 1 : 0;
    // 0x800A8B04: beq         $at, $zero, L_800A8B28
    if (ctx->r1 == 0) {
        // 0x800A8B08: nop
    
            goto L_800A8B28;
    }
    // 0x800A8B08: nop

    // 0x800A8B0C: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800A8B10: nop

    // 0x800A8B14: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800A8B18: beq         $at, $zero, L_800A8B28
    if (ctx->r1 == 0) {
        // 0x800A8B1C: nop
    
            goto L_800A8B28;
    }
    // 0x800A8B1C: nop

    // 0x800A8B20: b           L_800A8FD8
    // 0x800A8B24: nop

        goto L_800A8FD8;
    // 0x800A8B24: nop

L_800A8B28:
    // 0x800A8B28: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8B2C: nop

    // 0x800A8B30: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x800A8B34: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A8B38: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    // 0x800A8B3C: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800A8B40: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800A8B44: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800A8B48: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x800A8B4C: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x800A8B50: andi        $t0, $t2, 0xFF
    ctx->r8 = ctx->r10 & 0XFF;
    // 0x800A8B54: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x800A8B58: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x800A8B5C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800A8B60: andi        $t5, $t7, 0xFFFF
    ctx->r13 = ctx->r15 & 0XFFFF;
    // 0x800A8B64: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800A8B68: or          $t1, $t9, $t5
    ctx->r9 = ctx->r25 | ctx->r13;
    // 0x800A8B6C: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x800A8B70: lw          $t3, 0x198($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X198);
    // 0x800A8B74: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x800A8B78: nop

    // 0x800A8B7C: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x800A8B80: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800A8B84: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x800A8B88: blez        $t0, L_800A8FD4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800A8B8C: nop
    
            goto L_800A8FD4;
    }
    // 0x800A8B8C: nop

L_800A8B90:
    // 0x800A8B90: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800A8B94: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x800A8B98: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x800A8B9C: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800A8BA0: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800A8BA4: lh          $t1, 0x4($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X4);
    // 0x800A8BA8: nop

    // 0x800A8BAC: sh          $t1, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r9;
    // 0x800A8BB0: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800A8BB4: lw          $t6, 0x198($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X198);
    // 0x800A8BB8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x800A8BBC: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x800A8BC0: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x800A8BC4: sh          $zero, 0x4($t4)
    MEM_H(0X4, ctx->r12) = 0;
    // 0x800A8BC8: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A8BCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A8BD0: lh          $t8, 0x116($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X116);
    // 0x800A8BD4: nop

    // 0x800A8BD8: bne         $t8, $at, L_800A8D50
    if (ctx->r24 != ctx->r1) {
        // 0x800A8BDC: nop
    
            goto L_800A8D50;
    }
    // 0x800A8BDC: nop

    // 0x800A8BE0: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8BE4: nop

    // 0x800A8BE8: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800A8BEC: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A8BF0: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x800A8BF4: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x800A8BF8: lui         $t1, 0xFD50
    ctx->r9 = S32(0XFD50 << 16);
    // 0x800A8BFC: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A8C00: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A8C04: lhu         $t0, 0x14A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A8C08: lw          $t6, 0x128($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X128);
    // 0x800A8C0C: sll         $t4, $t0, 6
    ctx->r12 = S32(ctx->r8 << 6);
    // 0x800A8C10: sll         $t7, $t4, 5
    ctx->r15 = S32(ctx->r12 << 5);
    // 0x800A8C14: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A8C18: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x800A8C1C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A8C20: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A8C24: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800A8C28: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x800A8C2C: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8C30: nop

    // 0x800A8C34: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A8C38: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A8C3C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A8C40: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x800A8C44: lui         $t2, 0xF550
    ctx->r10 = S32(0XF550 << 16);
    // 0x800A8C48: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A8C4C: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800A8C50: lui         $t4, 0x709
    ctx->r12 = S32(0X709 << 16);
    // 0x800A8C54: ori         $t4, $t4, 0x4160
    ctx->r12 = ctx->r12 | 0X4160;
    // 0x800A8C58: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x800A8C5C: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8C60: nop

    // 0x800A8C64: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A8C68: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A8C6C: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x800A8C70: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800A8C74: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800A8C78: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A8C7C: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x800A8C80: nop

    // 0x800A8C84: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A8C88: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8C8C: nop

    // 0x800A8C90: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A8C94: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A8C98: sw          $t3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r11;
    // 0x800A8C9C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A8CA0: lui         $t0, 0xF300
    ctx->r8 = S32(0XF300 << 16);
    // 0x800A8CA4: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800A8CA8: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x800A8CAC: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x800A8CB0: ori         $t6, $t6, 0xF100
    ctx->r14 = ctx->r14 | 0XF100;
    // 0x800A8CB4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A8CB8: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8CBC: nop

    // 0x800A8CC0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A8CC4: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A8CC8: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x800A8CCC: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x800A8CD0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800A8CD4: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800A8CD8: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x800A8CDC: nop

    // 0x800A8CE0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A8CE4: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8CE8: nop

    // 0x800A8CEC: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A8CF0: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A8CF4: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800A8CF8: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800A8CFC: lui         $t4, 0xF548
    ctx->r12 = S32(0XF548 << 16);
    // 0x800A8D00: ori         $t4, $t4, 0x1000
    ctx->r12 = ctx->r12 | 0X1000;
    // 0x800A8D04: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800A8D08: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A8D0C: lui         $t7, 0x9
    ctx->r15 = S32(0X9 << 16);
    // 0x800A8D10: ori         $t7, $t7, 0x4160
    ctx->r15 = ctx->r15 | 0X4160;
    // 0x800A8D14: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A8D18: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8D1C: nop

    // 0x800A8D20: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800A8D24: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A8D28: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800A8D2C: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x800A8D30: lui         $t1, 0xF200
    ctx->r9 = S32(0XF200 << 16);
    // 0x800A8D34: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A8D38: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800A8D3C: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800A8D40: ori         $t2, $t2, 0xC07C
    ctx->r10 = ctx->r10 | 0XC07C;
    // 0x800A8D44: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800A8D48: b           L_800A8EC8
    // 0x800A8D4C: nop

        goto L_800A8EC8;
    // 0x800A8D4C: nop

L_800A8D50:
    // 0x800A8D50: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A8D54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8D58: lh          $t6, 0x116($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X116);
    // 0x800A8D5C: nop

    // 0x800A8D60: bne         $t6, $at, L_800A8EC8
    if (ctx->r14 != ctx->r1) {
        // 0x800A8D64: nop
    
            goto L_800A8EC8;
    }
    // 0x800A8D64: nop

    // 0x800A8D68: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8D6C: nop

    // 0x800A8D70: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A8D74: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A8D78: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x800A8D7C: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x800A8D80: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x800A8D84: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A8D88: lhu         $t2, 0x14A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A8D8C: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A8D90: sll         $t0, $t2, 6
    ctx->r8 = S32(ctx->r10 << 6);
    // 0x800A8D94: lw          $t3, 0x128($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X128);
    // 0x800A8D98: sll         $t4, $t0, 5
    ctx->r12 = S32(ctx->r8 << 5);
    // 0x800A8D9C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800A8DA0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800A8DA4: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800A8DA8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A8DAC: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8DB0: nop

    // 0x800A8DB4: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800A8DB8: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A8DBC: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    // 0x800A8DC0: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x800A8DC4: lui         $t1, 0xF510
    ctx->r9 = S32(0XF510 << 16);
    // 0x800A8DC8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A8DCC: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800A8DD0: lui         $t0, 0x709
    ctx->r8 = S32(0X709 << 16);
    // 0x800A8DD4: ori         $t0, $t0, 0x4160
    ctx->r8 = ctx->r8 | 0X4160;
    // 0x800A8DD8: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x800A8DDC: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8DE0: nop

    // 0x800A8DE4: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800A8DE8: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A8DEC: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
    // 0x800A8DF0: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800A8DF4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800A8DF8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A8DFC: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800A8E00: nop

    // 0x800A8E04: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A8E08: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8E0C: nop

    // 0x800A8E10: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x800A8E14: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A8E18: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    // 0x800A8E1C: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800A8E20: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x800A8E24: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A8E28: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x800A8E2C: lui         $t4, 0x77F
    ctx->r12 = S32(0X77F << 16);
    // 0x800A8E30: ori         $t4, $t4, 0xF080
    ctx->r12 = ctx->r12 | 0XF080;
    // 0x800A8E34: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A8E38: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8E3C: nop

    // 0x800A8E40: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A8E44: sw          $t7, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r15;
    // 0x800A8E48: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x800A8E4C: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800A8E50: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A8E54: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A8E58: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x800A8E5C: nop

    // 0x800A8E60: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A8E64: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8E68: nop

    // 0x800A8E6C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A8E70: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A8E74: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800A8E78: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800A8E7C: lui         $t0, 0xF510
    ctx->r8 = S32(0XF510 << 16);
    // 0x800A8E80: ori         $t0, $t0, 0x2000
    ctx->r8 = ctx->r8 | 0X2000;
    // 0x800A8E84: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800A8E88: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A8E8C: lui         $t3, 0x9
    ctx->r11 = S32(0X9 << 16);
    // 0x800A8E90: ori         $t3, $t3, 0x4160
    ctx->r11 = ctx->r11 | 0X4160;
    // 0x800A8E94: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800A8E98: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8E9C: nop

    // 0x800A8EA0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A8EA4: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A8EA8: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x800A8EAC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800A8EB0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800A8EB4: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A8EB8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800A8EBC: lui         $t1, 0xF
    ctx->r9 = S32(0XF << 16);
    // 0x800A8EC0: ori         $t1, $t1, 0xC07C
    ctx->r9 = ctx->r9 | 0XC07C;
    // 0x800A8EC4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_800A8EC8:
    // 0x800A8EC8: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8ECC: nop

    // 0x800A8ED0: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800A8ED4: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A8ED8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x800A8EDC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800A8EE0: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
    // 0x800A8EE4: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800A8EE8: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800A8EEC: nop

    // 0x800A8EF0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A8EF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A8EF8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A8EFC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800A8F00: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800A8F04: addiu       $t2, $t9, 0x1E
    ctx->r10 = ADD32(ctx->r25, 0X1E);
    // 0x800A8F08: andi        $t0, $t2, 0xFF
    ctx->r8 = ctx->r10 & 0XFF;
    // 0x800A8F0C: sll         $t1, $t5, 16
    ctx->r9 = S32(ctx->r13 << 16);
    // 0x800A8F10: sll         $t4, $t0, 8
    ctx->r12 = S32(ctx->r8 << 8);
    // 0x800A8F14: addiu       $t6, $t9, 0xA
    ctx->r14 = ADD32(ctx->r25, 0XA);
    // 0x800A8F18: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x800A8F1C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A8F20: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x800A8F24: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800A8F28: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x800A8F2C: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8F30: nop

    // 0x800A8F34: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A8F38: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A8F3C: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x800A8F40: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800A8F44: lui         $t1, 0xBF00
    ctx->r9 = S32(0XBF00 << 16);
    // 0x800A8F48: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800A8F4C: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x800A8F50: nop

    // 0x800A8F54: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800A8F58: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800A8F5C: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x800A8F60: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800A8F64: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x800A8F68: addiu       $t5, $t3, 0x14
    ctx->r13 = ADD32(ctx->r11, 0X14);
    // 0x800A8F6C: andi        $t2, $t5, 0xFF
    ctx->r10 = ctx->r13 & 0XFF;
    // 0x800A8F70: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800A8F74: sll         $t0, $t2, 8
    ctx->r8 = S32(ctx->r10 << 8);
    // 0x800A8F78: addiu       $t4, $t3, 0x1E
    ctx->r12 = ADD32(ctx->r11, 0X1E);
    // 0x800A8F7C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800A8F80: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800A8F84: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800A8F88: or          $t6, $t1, $t9
    ctx->r14 = ctx->r9 | ctx->r25;
    // 0x800A8F8C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A8F90: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8F94: nop

    // 0x800A8F98: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x800A8F9C: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A8FA0: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x800A8FA4: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800A8FA8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A8FAC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800A8FB0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800A8FB4: nop

    // 0x800A8FB8: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A8FBC: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800A8FC0: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x800A8FC4: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x800A8FC8: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A8FCC: bne         $at, $zero, L_800A8B90
    if (ctx->r1 != 0) {
        // 0x800A8FD0: sw          $t1, 0x150($sp)
        MEM_W(0X150, ctx->r29) = ctx->r9;
            goto L_800A8B90;
    }
    // 0x800A8FD0: sw          $t1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r9;
L_800A8FD4:
    // 0x800A8FD4: sw          $zero, 0x154($sp)
    MEM_W(0X154, ctx->r29) = 0;
L_800A8FD8:
    // 0x800A8FD8: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x800A8FDC: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8FE0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A8FE4: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x800A8FE8: addiu       $t2, $t5, 0x20
    ctx->r10 = ADD32(ctx->r13, 0X20);
    // 0x800A8FEC: sw          $t2, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r10;
    // 0x800A8FF0: bne         $at, $zero, L_800A7BBC
    if (ctx->r1 != 0) {
        // 0x800A8FF4: sw          $t7, 0x15C($sp)
        MEM_W(0X15C, ctx->r29) = ctx->r15;
            goto L_800A7BBC;
    }
    // 0x800A8FF4: sw          $t7, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r15;
    // 0x800A8FF8: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x800A8FFC: nop

    // 0x800A9000: beq         $t8, $zero, L_800A94BC
    if (ctx->r24 == 0) {
        // 0x800A9004: nop
    
            goto L_800A94BC;
    }
    // 0x800A9004: nop

    // 0x800A9008: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A900C: nop

    // 0x800A9010: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800A9014: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A9018: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800A901C: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800A9020: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800A9024: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x800A9028: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x800A902C: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x800A9030: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x800A9034: sll         $t2, $t5, 16
    ctx->r10 = S32(ctx->r13 << 16);
    // 0x800A9038: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x800A903C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800A9040: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800A9044: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x800A9048: or          $t3, $t7, $t0
    ctx->r11 = ctx->r15 | ctx->r8;
    // 0x800A904C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A9050: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x800A9054: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800A9058: nop

    // 0x800A905C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800A9060: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x800A9064: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x800A9068: blez        $t5, L_800A94BC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A906C: nop
    
            goto L_800A94BC;
    }
    // 0x800A906C: nop

L_800A9070:
    // 0x800A9070: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800A9074: nop

    // 0x800A9078: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x800A907C: sw          $t1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r9;
    // 0x800A9080: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800A9084: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x800A9088: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x800A908C: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x800A9090: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800A9094: lh          $t9, 0x4($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X4);
    // 0x800A9098: nop

    // 0x800A909C: sh          $t9, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r25;
    // 0x800A90A0: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800A90A4: lw          $t6, 0x198($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X198);
    // 0x800A90A8: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x800A90AC: sll         $t1, $t2, 4
    ctx->r9 = S32(ctx->r10 << 4);
    // 0x800A90B0: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x800A90B4: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x800A90B8: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A90BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A90C0: lh          $t8, 0x116($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X116);
    // 0x800A90C4: nop

    // 0x800A90C8: bne         $t8, $at, L_800A9240
    if (ctx->r24 != ctx->r1) {
        // 0x800A90CC: nop
    
            goto L_800A9240;
    }
    // 0x800A90CC: nop

    // 0x800A90D0: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A90D4: nop

    // 0x800A90D8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A90DC: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A90E0: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x800A90E4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800A90E8: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x800A90EC: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A90F0: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A90F4: lhu         $t1, 0x14A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A90F8: lw          $t6, 0x128($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X128);
    // 0x800A90FC: sll         $t7, $t1, 6
    ctx->r15 = S32(ctx->r9 << 6);
    // 0x800A9100: sll         $t0, $t7, 5
    ctx->r8 = S32(ctx->r15 << 5);
    // 0x800A9104: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A9108: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800A910C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A9110: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x800A9114: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x800A9118: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A911C: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A9120: nop

    // 0x800A9124: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800A9128: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A912C: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x800A9130: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800A9134: lui         $t2, 0xF550
    ctx->r10 = S32(0XF550 << 16);
    // 0x800A9138: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800A913C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800A9140: lui         $t7, 0x709
    ctx->r15 = S32(0X709 << 16);
    // 0x800A9144: ori         $t7, $t7, 0x4160
    ctx->r15 = ctx->r15 | 0X4160;
    // 0x800A9148: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800A914C: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A9150: nop

    // 0x800A9154: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A9158: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A915C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x800A9160: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800A9164: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x800A9168: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A916C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A9170: nop

    // 0x800A9174: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A9178: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A917C: nop

    // 0x800A9180: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x800A9184: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A9188: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x800A918C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800A9190: lui         $t1, 0xF300
    ctx->r9 = S32(0XF300 << 16);
    // 0x800A9194: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x800A9198: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800A919C: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x800A91A0: ori         $t6, $t6, 0xF100
    ctx->r14 = ctx->r14 | 0XF100;
    // 0x800A91A4: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800A91A8: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800A91AC: nop

    // 0x800A91B0: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x800A91B4: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A91B8: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x800A91BC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800A91C0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800A91C4: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x800A91C8: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800A91CC: nop

    // 0x800A91D0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A91D4: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A91D8: nop

    // 0x800A91DC: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x800A91E0: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A91E4: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x800A91E8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800A91EC: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x800A91F0: ori         $t7, $t7, 0x1000
    ctx->r15 = ctx->r15 | 0X1000;
    // 0x800A91F4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x800A91F8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800A91FC: lui         $t0, 0x9
    ctx->r8 = S32(0X9 << 16);
    // 0x800A9200: ori         $t0, $t0, 0x4160
    ctx->r8 = ctx->r8 | 0X4160;
    // 0x800A9204: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800A9208: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A920C: nop

    // 0x800A9210: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A9214: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A9218: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x800A921C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A9220: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800A9224: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A9228: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A922C: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800A9230: ori         $t2, $t2, 0xC07C
    ctx->r10 = ctx->r10 | 0XC07C;
    // 0x800A9234: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x800A9238: b           L_800A93B8
    // 0x800A923C: nop

        goto L_800A93B8;
    // 0x800A923C: nop

L_800A9240:
    // 0x800A9240: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A9244: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9248: lh          $t6, 0x116($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X116);
    // 0x800A924C: nop

    // 0x800A9250: bne         $t6, $at, L_800A93B8
    if (ctx->r14 != ctx->r1) {
        // 0x800A9254: nop
    
            goto L_800A93B8;
    }
    // 0x800A9254: nop

    // 0x800A9258: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A925C: nop

    // 0x800A9260: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A9264: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A9268: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x800A926C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800A9270: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x800A9274: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A9278: lhu         $t2, 0x14A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A927C: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A9280: sll         $t1, $t2, 6
    ctx->r9 = S32(ctx->r10 << 6);
    // 0x800A9284: lw          $t5, 0x128($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X128);
    // 0x800A9288: sll         $t7, $t1, 5
    ctx->r15 = S32(ctx->r9 << 5);
    // 0x800A928C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800A9290: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800A9294: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x800A9298: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800A929C: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A92A0: nop

    // 0x800A92A4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A92A8: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A92AC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800A92B0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A92B4: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x800A92B8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800A92BC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A92C0: lui         $t1, 0x709
    ctx->r9 = S32(0X709 << 16);
    // 0x800A92C4: ori         $t1, $t1, 0x4160
    ctx->r9 = ctx->r9 | 0X4160;
    // 0x800A92C8: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x800A92CC: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A92D0: nop

    // 0x800A92D4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A92D8: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A92DC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800A92E0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800A92E4: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x800A92E8: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800A92EC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A92F0: nop

    // 0x800A92F4: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A92F8: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x800A92FC: nop

    // 0x800A9300: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x800A9304: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A9308: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800A930C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A9310: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x800A9314: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800A9318: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A931C: lui         $t7, 0x77F
    ctx->r15 = S32(0X77F << 16);
    // 0x800A9320: ori         $t7, $t7, 0xF080
    ctx->r15 = ctx->r15 | 0XF080;
    // 0x800A9324: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800A9328: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A932C: nop

    // 0x800A9330: addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
    // 0x800A9334: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A9338: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800A933C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800A9340: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A9344: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800A9348: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800A934C: nop

    // 0x800A9350: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800A9354: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A9358: nop

    // 0x800A935C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800A9360: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A9364: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800A9368: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A936C: lui         $t1, 0xF510
    ctx->r9 = S32(0XF510 << 16);
    // 0x800A9370: ori         $t1, $t1, 0x2000
    ctx->r9 = ctx->r9 | 0X2000;
    // 0x800A9374: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x800A9378: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800A937C: lui         $t5, 0x9
    ctx->r13 = S32(0X9 << 16);
    // 0x800A9380: ori         $t5, $t5, 0x4160
    ctx->r13 = ctx->r13 | 0X4160;
    // 0x800A9384: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A9388: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A938C: nop

    // 0x800A9390: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A9394: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A9398: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800A939C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A93A0: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x800A93A4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A93A8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A93AC: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x800A93B0: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x800A93B4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
L_800A93B8:
    // 0x800A93B8: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A93BC: nop

    // 0x800A93C0: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800A93C4: sw          $t7, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r15;
    // 0x800A93C8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800A93CC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800A93D0: lui         $t5, 0xBF00
    ctx->r13 = S32(0XBF00 << 16);
    // 0x800A93D4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A93D8: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800A93DC: nop

    // 0x800A93E0: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800A93E4: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x800A93E8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800A93EC: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x800A93F0: addiu       $t9, $t8, 0x1E
    ctx->r25 = ADD32(ctx->r24, 0X1E);
    // 0x800A93F4: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x800A93F8: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800A93FC: sll         $t1, $t2, 8
    ctx->r9 = S32(ctx->r10 << 8);
    // 0x800A9400: addiu       $t5, $t8, 0xA
    ctx->r13 = ADD32(ctx->r24, 0XA);
    // 0x800A9404: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800A9408: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800A940C: or          $t7, $t4, $t1
    ctx->r15 = ctx->r12 | ctx->r9;
    // 0x800A9410: or          $t0, $t7, $t6
    ctx->r8 = ctx->r15 | ctx->r14;
    // 0x800A9414: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800A9418: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A941C: nop

    // 0x800A9420: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800A9424: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A9428: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800A942C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A9430: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x800A9434: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800A9438: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800A943C: nop

    // 0x800A9440: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x800A9444: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x800A9448: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800A944C: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x800A9450: addiu       $t0, $t5, 0x14
    ctx->r8 = ADD32(ctx->r13, 0X14);
    // 0x800A9454: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x800A9458: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800A945C: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x800A9460: addiu       $t4, $t5, 0x1E
    ctx->r12 = ADD32(ctx->r13, 0X1E);
    // 0x800A9464: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A9468: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800A946C: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x800A9470: or          $t8, $t2, $t1
    ctx->r24 = ctx->r10 | ctx->r9;
    // 0x800A9474: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x800A9478: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A947C: nop

    // 0x800A9480: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800A9484: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A9488: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800A948C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800A9490: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800A9494: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800A9498: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800A949C: nop

    // 0x800A94A0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A94A4: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800A94A8: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    // 0x800A94AC: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x800A94B0: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A94B4: bne         $at, $zero, L_800A9070
    if (ctx->r1 != 0) {
        // 0x800A94B8: sw          $t2, 0x150($sp)
        MEM_W(0X150, ctx->r29) = ctx->r10;
            goto L_800A9070;
    }
    // 0x800A94B8: sw          $t2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r10;
L_800A94BC:
    // 0x800A94BC: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x800A94C0: lw          $t0, 0x184($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X184);
    // 0x800A94C4: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800A94C8: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x800A94CC: addiu       $t3, $t0, 0x40
    ctx->r11 = ADD32(ctx->r8, 0X40);
    // 0x800A94D0: sw          $t3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r11;
    // 0x800A94D4: bne         $at, $zero, L_800A7B6C
    if (ctx->r1 != 0) {
        // 0x800A94D8: sw          $t7, 0x160($sp)
        MEM_W(0X160, ctx->r29) = ctx->r15;
            goto L_800A7B6C;
    }
    // 0x800A94D8: sw          $t7, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r15;
    // 0x800A94DC: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A94E0: nop

    // 0x800A94E4: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800A94E8: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A94EC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A94F0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800A94F4: lui         $t5, 0xBD00
    ctx->r13 = S32(0XBD00 << 16);
    // 0x800A94F8: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A94FC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800A9500: nop

    // 0x800A9504: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800A9508: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A950C: nop

    // 0x800A9510: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800A9514: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A9518: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A951C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9520: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800A9524: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800A9528: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A952C: nop

    // 0x800A9530: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A9534: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A9538: lw          $t9, 0x1A0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A0);
    // 0x800A953C: nop

    // 0x800A9540: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800A9544: b           L_800A9554
    // 0x800A9548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A9554;
    // 0x800A9548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A954C: b           L_800A9554
    // 0x800A9550: nop

        goto L_800A9554;
    // 0x800A9550: nop

L_800A9554:
    // 0x800A9554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9558: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
    // 0x800A955C: jr          $ra
    // 0x800A9560: nop

    return;
    // 0x800A9560: nop

;}
RECOMP_FUNC void func_80063D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D10: jal         0x8005F064
    // 0x80063D14: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063D14: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x80063D18: b           L_80063D28
    // 0x80063D1C: nop

        goto L_80063D28;
    // 0x80063D1C: nop

    // 0x80063D20: b           L_80063D28
    // 0x80063D24: nop

        goto L_80063D28;
    // 0x80063D24: nop

L_80063D28:
    // 0x80063D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063D30: jr          $ra
    // 0x80063D34: nop

    return;
    // 0x80063D34: nop

;}
RECOMP_FUNC void func_80077868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077868: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007786C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077870: nop

    // 0x80077874: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077878: nop

    // 0x8007787C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077880: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077884: jr          $ra
    // 0x80077888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007788C: jr          $ra
    // 0x80077890: nop

    return;
    // 0x80077890: nop

    // 0x80077894: jr          $ra
    // 0x80077898: nop

    return;
    // 0x80077898: nop

;}
RECOMP_FUNC void func_800B23C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B23C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B23C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B23CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B23D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B23D4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B23D8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800B23DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B23E0: lbu         $t6, 0x43($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X43);
    // 0x800B23E4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B23E8: nop

    // 0x800B23EC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800B23F0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B23F4: nop

    // 0x800B23F8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800B23FC: nop

    // 0x800B2400: bne         $t9, $zero, L_800B241C
    if (ctx->r25 != 0) {
        // 0x800B2404: nop
    
            goto L_800B241C;
    }
    // 0x800B2404: nop

    // 0x800B2408: jal         0x800BC6EC
    // 0x800B240C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800B240C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x800B2410: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2414: nop

    // 0x800B2418: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
L_800B241C:
    // 0x800B241C: lhu         $t1, 0x32($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X32);
    // 0x800B2420: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800B2424: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B2428: lw          $t3, 0xD38($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD38);
    // 0x800B242C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B2430: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B2434: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B2438: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B243C: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B2440: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B2444: jal         0x800BD1FC
    // 0x800B2448: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x800B2448: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x800B244C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2450: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B2454: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x800B2458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B245C: jal         0x800BD218
    // 0x800B2460: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800B2460: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_2:
    // 0x800B2464: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2468: nop

    // 0x800B246C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800B2470: nop

    // 0x800B2474: bne         $t6, $zero, L_800B2490
    if (ctx->r14 != 0) {
        // 0x800B2478: nop
    
            goto L_800B2490;
    }
    // 0x800B2478: nop

    // 0x800B247C: jal         0x800BC6EC
    // 0x800B2480: addiu       $a0, $zero, 0x380
    ctx->r4 = ADD32(0, 0X380);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800B2480: addiu       $a0, $zero, 0x380
    ctx->r4 = ADD32(0, 0X380);
    after_3:
    // 0x800B2484: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2488: nop

    // 0x800B248C: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
L_800B2490:
    // 0x800B2490: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2494: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B2498: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800B249C: lw          $t1, 0xD3C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD3C);
    // 0x800B24A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B24A4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B24A8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B24AC: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B24B0: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B24B4: jal         0x800BD1FC
    // 0x800B24B8: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x800B24B8: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    after_4:
    // 0x800B24BC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B24C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B24C4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800B24C8: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x800B24CC: lbu         $a2, 0x10($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X10);
    // 0x800B24D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B24D4: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x800B24D8: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x800B24DC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800B24E0: jal         0x800BD218
    // 0x800B24E4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x800B24E4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_5:
    // 0x800B24E8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B24EC: nop

    // 0x800B24F0: sb          $zero, 0x30($t5)
    MEM_B(0X30, ctx->r13) = 0;
    // 0x800B24F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B24F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B24FC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800B2500: lwc1        $f9, -0x6C0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X6C0);
    // 0x800B2504: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x800B2508: lwc1        $f8, -0x6BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6BC);
    // 0x800B250C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B2510: nop

    // 0x800B2514: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800B2518: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800B251C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800B2520: swc1        $f16, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f16.u32l;
    // 0x800B2524: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2528: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B252C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800B2530: lwc1        $f7, -0x6B8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X6B8);
    // 0x800B2534: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x800B2538: lwc1        $f6, -0x6B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6B4);
    // 0x800B253C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800B2540: nop

    // 0x800B2544: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800B2548: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800B254C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B2550: swc1        $f10, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f10.u32l;
    // 0x800B2554: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2558: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B255C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800B2560: lwc1        $f5, -0x6B0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X6B0);
    // 0x800B2564: lh          $t4, 0x8($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X8);
    // 0x800B2568: lwc1        $f4, -0x6AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6AC);
    // 0x800B256C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800B2570: nop

    // 0x800B2574: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800B2578: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800B257C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B2580: swc1        $f8, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f8.u32l;
    // 0x800B2584: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2588: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B258C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x800B2590: lwc1        $f19, -0x6A8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X6A8);
    // 0x800B2594: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x800B2598: lwc1        $f18, -0x6A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6A4);
    // 0x800B259C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800B25A0: nop

    // 0x800B25A4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800B25A8: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B25AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800B25B0: swc1        $f6, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->f6.u32l;
    // 0x800B25B4: lbu         $t6, 0x43($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X43);
    // 0x800B25B8: nop

    // 0x800B25BC: andi        $t0, $t6, 0x1
    ctx->r8 = ctx->r14 & 0X1;
    // 0x800B25C0: beq         $t0, $zero, L_800B25F8
    if (ctx->r8 == 0) {
        // 0x800B25C4: nop
    
            goto L_800B25F8;
    }
    // 0x800B25C4: nop

    // 0x800B25C8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B25CC: nop

    // 0x800B25D0: lwc1        $f8, 0x20($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800B25D4: nop

    // 0x800B25D8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B25DC: swc1        $f10, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f10.u32l;
    // 0x800B25E0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B25E4: nop

    // 0x800B25E8: lwc1        $f16, 0x28($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X28);
    // 0x800B25EC: nop

    // 0x800B25F0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B25F4: swc1        $f18, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f18.u32l;
L_800B25F8:
    // 0x800B25F8: lbu         $t3, 0x43($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X43);
    // 0x800B25FC: nop

    // 0x800B2600: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x800B2604: beq         $t4, $zero, L_800B263C
    if (ctx->r12 == 0) {
        // 0x800B2608: nop
    
            goto L_800B263C;
    }
    // 0x800B2608: nop

    // 0x800B260C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2610: nop

    // 0x800B2614: lwc1        $f4, 0x24($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X24);
    // 0x800B2618: nop

    // 0x800B261C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B2620: swc1        $f6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f6.u32l;
    // 0x800B2624: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2628: nop

    // 0x800B262C: lwc1        $f8, 0x2C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x800B2630: nop

    // 0x800B2634: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B2638: swc1        $f10, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f10.u32l;
L_800B263C:
    // 0x800B263C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B2640: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2644: nop

    // 0x800B2648: swc1        $f16, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f16.u32l;
    // 0x800B264C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2650: nop

    // 0x800B2654: sb          $zero, 0x38($t5)
    MEM_B(0X38, ctx->r13) = 0;
    // 0x800B2658: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B265C: nop

    // 0x800B2660: sh          $zero, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = 0;
    // 0x800B2664: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B2668: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B266C: nop

    // 0x800B2670: swc1        $f18, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f18.u32l;
    // 0x800B2674: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B2678: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B267C: nop

    // 0x800B2680: swc1        $f4, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f4.u32l;
    // 0x800B2684: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800B2688: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800B268C: lw          $t3, 0xC0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XC0);
    // 0x800B2690: nop

    // 0x800B2694: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800B2698: sw          $t4, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r12;
    // 0x800B269C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B26A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800B26A4: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x800B26A8: jal         0x800B407C
    // 0x800B26AC: nop

    func_800B407C(rdram, ctx);
        goto after_6;
    // 0x800B26AC: nop

    after_6:
    // 0x800B26B0: beq         $v0, $zero, L_800B26C0
    if (ctx->r2 == 0) {
        // 0x800B26B4: nop
    
            goto L_800B26C0;
    }
    // 0x800B26B4: nop

    // 0x800B26B8: b           L_800B26D0
    // 0x800B26BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B26D0;
    // 0x800B26BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B26C0:
    // 0x800B26C0: b           L_800B26D0
    // 0x800B26C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B26D0;
    // 0x800B26C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B26C8: b           L_800B26D0
    // 0x800B26CC: nop

        goto L_800B26D0;
    // 0x800B26CC: nop

L_800B26D0:
    // 0x800B26D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B26D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B26D8: jr          $ra
    // 0x800B26DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B26DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
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
RECOMP_FUNC void func_80002F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F20: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80002F24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80002F28: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80002F2C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80002F30: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80002F34: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80002F38: nop

    // 0x80002F3C: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80002F40: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80002F44: jal         0x80098820
    // 0x80002F48: nop

    func_80098820(rdram, ctx);
        goto after_0;
    // 0x80002F48: nop

    after_0:
    // 0x80002F4C: jal         0x800C0A40
    // 0x80002F50: nop

    func_800C0A40(rdram, ctx);
        goto after_1;
    // 0x80002F50: nop

    after_1:
    // 0x80002F54: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80002F58: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80002F5C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80002F60: nop

    // 0x80002F64: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80002F68: bne         $t1, $zero, L_80002F84
    if (ctx->r9 != 0) {
        // 0x80002F6C: nop
    
            goto L_80002F84;
    }
    // 0x80002F6C: nop

    // 0x80002F70: lhu         $t2, 0x6($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X6);
    // 0x80002F74: nop

    // 0x80002F78: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x80002F7C: beq         $t3, $zero, L_80002FAC
    if (ctx->r11 == 0) {
        // 0x80002F80: nop
    
            goto L_80002FAC;
    }
    // 0x80002F80: nop

L_80002F84:
    // 0x80002F84: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80002F88: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80002F8C: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80002F90: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80002F94: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80002F98: sh          $t7, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r15;
    // 0x80002F9C: jal         0x8000BB00
    // 0x80002FA0: nop

    func_8000BB00(rdram, ctx);
        goto after_2;
    // 0x80002FA0: nop

    after_2:
    // 0x80002FA4: b           L_80003230
    // 0x80002FA8: nop

        goto L_80003230;
    // 0x80002FA8: nop

L_80002FAC:
    // 0x80002FAC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80002FB0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80002FB4: lh          $t6, -0x73C0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X73C0);
    // 0x80002FB8: lh          $t8, -0x73A8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X73A8);
    // 0x80002FBC: nop

    // 0x80002FC0: beq         $t8, $t6, L_800030E4
    if (ctx->r24 == ctx->r14) {
        // 0x80002FC4: nop
    
            goto L_800030E4;
    }
    // 0x80002FC4: nop

    // 0x80002FC8: bltz        $t8, L_800030E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80002FCC: nop
    
            goto L_800030E4;
    }
    // 0x80002FCC: nop

    // 0x80002FD0: bltz        $t6, L_800030E4
    if (SIGNED(ctx->r14) < 0) {
        // 0x80002FD4: nop
    
            goto L_800030E4;
    }
    // 0x80002FD4: nop

    // 0x80002FD8: jal         0x800045AC
    // 0x80002FDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_3;
    // 0x80002FDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80002FE0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80002FE4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80002FE8: nop

    // 0x80002FEC: beq         $t0, $zero, L_800030DC
    if (ctx->r8 == 0) {
        // 0x80002FF0: nop
    
            goto L_800030DC;
    }
    // 0x80002FF0: nop

    // 0x80002FF4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80002FF8: lh          $t1, -0x73C0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X73C0);
    // 0x80002FFC: nop

    // 0x80003000: sw          $t1, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r9;
    // 0x80003004: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80003008: jal         0x8000C3B0
    // 0x8000300C: nop

    func_8000C3B0(rdram, ctx);
        goto after_4;
    // 0x8000300C: nop

    after_4:
    // 0x80003010: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80003014: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80003018: lhu         $t2, 0x6($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X6);
    // 0x8000301C: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80003020: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80003024: sh          $t3, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r11;
    // 0x80003028: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000302C: nop

    // 0x80003030: lw          $t7, 0x1A8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1A8);
    // 0x80003034: nop

    // 0x80003038: ori         $t4, $t7, 0x1
    ctx->r12 = ctx->r15 | 0X1;
    // 0x8000303C: sw          $t4, 0x1A8($t5)
    MEM_W(0X1A8, ctx->r13) = ctx->r12;
    // 0x80003040: jal         0x8000BB00
    // 0x80003044: nop

    func_8000BB00(rdram, ctx);
        goto after_5;
    // 0x80003044: nop

    after_5:
    // 0x80003048: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x8000304C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80003050: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x80003054: jal         0x80016074
    // 0x80003058: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_6;
    // 0x80003058: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_6:
    // 0x8000305C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80003060: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80003064: nop

    // 0x80003068: beq         $t6, $zero, L_80003098
    if (ctx->r14 == 0) {
        // 0x8000306C: nop
    
            goto L_80003098;
    }
    // 0x8000306C: nop

    // 0x80003070: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80003074: nop

    // 0x80003078: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000307C: nop

    // 0x80003080: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80003084: beq         $t2, $zero, L_80003098
    if (ctx->r10 == 0) {
        // 0x80003088: nop
    
            goto L_80003098;
    }
    // 0x80003088: nop

    // 0x8000308C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80003090: jal         0x80019F4C
    // 0x80003094: nop

    func_80019F4C(rdram, ctx);
        goto after_7;
    // 0x80003094: nop

    after_7:
L_80003098:
    // 0x80003098: jal         0x80016074
    // 0x8000309C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_8;
    // 0x8000309C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_8:
    // 0x800030A0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800030A4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800030A8: nop

    // 0x800030AC: beq         $t3, $zero, L_800030DC
    if (ctx->r11 == 0) {
        // 0x800030B0: nop
    
            goto L_800030DC;
    }
    // 0x800030B0: nop

    // 0x800030B4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800030B8: nop

    // 0x800030BC: lw          $t7, 0x1A8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X1A8);
    // 0x800030C0: nop

    // 0x800030C4: andi        $t4, $t7, 0x7
    ctx->r12 = ctx->r15 & 0X7;
    // 0x800030C8: beq         $t4, $zero, L_800030DC
    if (ctx->r12 == 0) {
        // 0x800030CC: nop
    
            goto L_800030DC;
    }
    // 0x800030CC: nop

    // 0x800030D0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800030D4: jal         0x80019F4C
    // 0x800030D8: nop

    func_80019F4C(rdram, ctx);
        goto after_9;
    // 0x800030D8: nop

    after_9:
L_800030DC:
    // 0x800030DC: b           L_80003230
    // 0x800030E0: nop

        goto L_80003230;
    // 0x800030E0: nop

L_800030E4:
    // 0x800030E4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800030E8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800030EC: lh          $t8, -0x73C0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X73C0);
    // 0x800030F0: lh          $t5, -0x73A8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X73A8);
    // 0x800030F4: nop

    // 0x800030F8: bne         $t5, $t8, L_80003230
    if (ctx->r13 != ctx->r24) {
        // 0x800030FC: nop
    
            goto L_80003230;
    }
    // 0x800030FC: nop

    // 0x80003100: bltz        $t8, L_80003230
    if (SIGNED(ctx->r24) < 0) {
        // 0x80003104: nop
    
            goto L_80003230;
    }
    // 0x80003104: nop

    // 0x80003108: jal         0x800045AC
    // 0x8000310C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_10;
    // 0x8000310C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x80003110: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80003114: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80003118: nop

    // 0x8000311C: beq         $t6, $zero, L_80003230
    if (ctx->r14 == 0) {
        // 0x80003120: nop
    
            goto L_80003230;
    }
    // 0x80003120: nop

    // 0x80003124: lw          $t0, 0x20C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X20C);
    // 0x80003128: nop

    // 0x8000312C: beq         $t0, $zero, L_80003230
    if (ctx->r8 == 0) {
        // 0x80003130: nop
    
            goto L_80003230;
    }
    // 0x80003130: nop

    // 0x80003134: lhu         $t1, 0x14($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X14);
    // 0x80003138: nop

    // 0x8000313C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80003140: beq         $t2, $zero, L_80003230
    if (ctx->r10 == 0) {
        // 0x80003144: nop
    
            goto L_80003230;
    }
    // 0x80003144: nop

    // 0x80003148: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000314C: lh          $t3, -0x73C0($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X73C0);
    // 0x80003150: nop

    // 0x80003154: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x80003158: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000315C: jal         0x8000C3B0
    // 0x80003160: nop

    func_8000C3B0(rdram, ctx);
        goto after_11;
    // 0x80003160: nop

    after_11:
    // 0x80003164: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80003168: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8000316C: lhu         $t7, 0x6($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X6);
    // 0x80003170: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80003174: and         $t4, $t7, $at
    ctx->r12 = ctx->r15 & ctx->r1;
    // 0x80003178: sh          $t4, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r12;
    // 0x8000317C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80003180: nop

    // 0x80003184: lw          $t8, 0x1A8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1A8);
    // 0x80003188: nop

    // 0x8000318C: ori         $t6, $t8, 0x1
    ctx->r14 = ctx->r24 | 0X1;
    // 0x80003190: sw          $t6, 0x1A8($t5)
    MEM_W(0X1A8, ctx->r13) = ctx->r14;
    // 0x80003194: jal         0x8000BB00
    // 0x80003198: nop

    func_8000BB00(rdram, ctx);
        goto after_12;
    // 0x80003198: nop

    after_12:
    // 0x8000319C: lw          $t0, 0x100($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X100);
    // 0x800031A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800031A4: sh          $t0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r8;
    // 0x800031A8: jal         0x80016074
    // 0x800031AC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_13;
    // 0x800031AC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_13:
    // 0x800031B0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800031B4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800031B8: nop

    // 0x800031BC: beq         $t1, $zero, L_800031EC
    if (ctx->r9 == 0) {
        // 0x800031C0: nop
    
            goto L_800031EC;
    }
    // 0x800031C0: nop

    // 0x800031C4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800031C8: nop

    // 0x800031CC: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x800031D0: nop

    // 0x800031D4: andi        $t7, $t3, 0x7
    ctx->r15 = ctx->r11 & 0X7;
    // 0x800031D8: beq         $t7, $zero, L_800031EC
    if (ctx->r15 == 0) {
        // 0x800031DC: nop
    
            goto L_800031EC;
    }
    // 0x800031DC: nop

    // 0x800031E0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800031E4: jal         0x80019F4C
    // 0x800031E8: nop

    func_80019F4C(rdram, ctx);
        goto after_14;
    // 0x800031E8: nop

    after_14:
L_800031EC:
    // 0x800031EC: jal         0x80016074
    // 0x800031F0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_15;
    // 0x800031F0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_15:
    // 0x800031F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800031F8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800031FC: nop

    // 0x80003200: beq         $t4, $zero, L_80003230
    if (ctx->r12 == 0) {
        // 0x80003204: nop
    
            goto L_80003230;
    }
    // 0x80003204: nop

    // 0x80003208: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000320C: nop

    // 0x80003210: lw          $t8, 0x1A8($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X1A8);
    // 0x80003214: nop

    // 0x80003218: andi        $t6, $t8, 0x7
    ctx->r14 = ctx->r24 & 0X7;
    // 0x8000321C: beq         $t6, $zero, L_80003230
    if (ctx->r14 == 0) {
        // 0x80003220: nop
    
            goto L_80003230;
    }
    // 0x80003220: nop

    // 0x80003224: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80003228: jal         0x80019F4C
    // 0x8000322C: nop

    func_80019F4C(rdram, ctx);
        goto after_16;
    // 0x8000322C: nop

    after_16:
L_80003230:
    // 0x80003230: jal         0x800BCB54
    // 0x80003234: nop

    func_800BCB54(rdram, ctx);
        goto after_17;
    // 0x80003234: nop

    after_17:
    // 0x80003238: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000323C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80003240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003244: jal         0x800BDC70
    // 0x80003248: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BDC70(rdram, ctx);
        goto after_18;
    // 0x80003248: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_18:
    // 0x8000324C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003250: sw          $zero, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = 0;
    // 0x80003254: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80003258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000325C: sw          $t5, 0x7244($at)
    MEM_W(0X7244, ctx->r1) = ctx->r13;
    // 0x80003260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80003264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80003268: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000326C: swc1        $f4, 0x727C($at)
    MEM_W(0X727C, ctx->r1) = ctx->f4.u32l;
    // 0x80003270: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003274: swc1        $f4, 0x7270($at)
    MEM_W(0X7270, ctx->r1) = ctx->f4.u32l;
    // 0x80003278: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000327C: swc1        $f4, 0x7264($at)
    MEM_W(0X7264, ctx->r1) = ctx->f4.u32l;
    // 0x80003280: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80003284: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80003288: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000328C: swc1        $f6, 0x25D0($at)
    MEM_W(0X25D0, ctx->r1) = ctx->f6.u32l;
    // 0x80003290: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80003294: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80003298: sw          $t0, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r8;
    // 0x8000329C: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x800032A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800032A4: sw          $t1, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r9;
    // 0x800032A8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800032AC: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800032B0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800032B4: addiu       $at, $zero, -0x1201
    ctx->r1 = ADD32(0, -0X1201);
    // 0x800032B8: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x800032BC: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
    // 0x800032C0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800032C4: lh          $t4, -0x73C0($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X73C0);
    // 0x800032C8: nop

    // 0x800032CC: bltz        $t4, L_800032E4
    if (SIGNED(ctx->r12) < 0) {
        // 0x800032D0: nop
    
            goto L_800032E4;
    }
    // 0x800032D0: nop

    // 0x800032D4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800032D8: lh          $t9, -0x73C0($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X73C0);
    // 0x800032DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800032E0: sh          $t9, -0x73A8($at)
    MEM_H(-0X73A8, ctx->r1) = ctx->r25;
L_800032E4:
    // 0x800032E4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800032E8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800032EC: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x800032F0: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800032F4: nop

    // 0x800032F8: bne         $t8, $t6, L_80003340
    if (ctx->r24 != ctx->r14) {
        // 0x800032FC: nop
    
            goto L_80003340;
    }
    // 0x800032FC: nop

    // 0x80003300: bne         $t8, $zero, L_80003340
    if (ctx->r24 != 0) {
        // 0x80003304: nop
    
            goto L_80003340;
    }
    // 0x80003304: nop

    // 0x80003308: addiu       $t5, $zero, 0x1F4
    ctx->r13 = ADD32(0, 0X1F4);
    // 0x8000330C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80003310: sh          $t5, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r13;
    // 0x80003314: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80003318: lh          $t0, -0x73C0($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X73C0);
    // 0x8000331C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80003320: sh          $t0, -0x73A8($at)
    MEM_H(-0X73A8, ctx->r1) = ctx->r8;
    // 0x80003324: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80003328: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000332C: sh          $t1, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r9;
    // 0x80003330: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80003334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003338: b           L_80003390
    // 0x8000333C: sh          $t3, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r11;
        goto L_80003390;
    // 0x8000333C: sh          $t3, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r11;
L_80003340:
    // 0x80003340: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80003344: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80003348: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x8000334C: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80003350: nop

    // 0x80003354: bne         $t7, $t2, L_80003390
    if (ctx->r15 != ctx->r10) {
        // 0x80003358: nop
    
            goto L_80003390;
    }
    // 0x80003358: nop

    // 0x8000335C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80003360: bne         $t7, $at, L_80003390
    if (ctx->r15 != ctx->r1) {
        // 0x80003364: nop
    
            goto L_80003390;
    }
    // 0x80003364: nop

    // 0x80003368: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000336C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003370: sh          $t4, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r12;
    // 0x80003374: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003378: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000337C: sh          $t9, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r25;
    // 0x80003380: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80003384: lh          $t6, -0x73A8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X73A8);
    // 0x80003388: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000338C: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
L_80003390:
    // 0x80003390: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80003394: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80003398: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000339C: jal         0x80099F90
    // 0x800033A0: nop

    func_80099F90(rdram, ctx);
        goto after_19;
    // 0x800033A0: nop

    after_19:
    // 0x800033A4: jal         0x80004510
    // 0x800033A8: nop

    func_80004510(rdram, ctx);
        goto after_20;
    // 0x800033A8: nop

    after_20:
    // 0x800033AC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800033B0: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800033B4: lhu         $t5, 0x0($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X0);
    // 0x800033B8: nop

    // 0x800033BC: andi        $t0, $t5, 0x80
    ctx->r8 = ctx->r13 & 0X80;
    // 0x800033C0: bne         $t0, $zero, L_800035E4
    if (ctx->r8 != 0) {
        // 0x800033C4: nop
    
            goto L_800035E4;
    }
    // 0x800033C4: nop

    // 0x800033C8: jal         0x80004654
    // 0x800033CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80004654(rdram, ctx);
        goto after_21;
    // 0x800033CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_21:
    // 0x800033D0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800033D4: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800033D8: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x800033DC: nop

    // 0x800033E0: andi        $t2, $t3, 0x200
    ctx->r10 = ctx->r11 & 0X200;
    // 0x800033E4: beq         $t2, $zero, L_800035E4
    if (ctx->r10 == 0) {
        // 0x800033E8: nop
    
            goto L_800035E4;
    }
    // 0x800033E8: nop

    // 0x800033EC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800033F0: addiu       $t7, $t7, 0x3DF8
    ctx->r15 = ADD32(ctx->r15, 0X3DF8);
    // 0x800033F4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800033F8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800033FC: jal         0x800C143C
    // 0x80003400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_22;
    // 0x80003400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x80003404: jal         0x80015E50
    // 0x80003408: nop

    func_80015E50(rdram, ctx);
        goto after_23;
    // 0x80003408: nop

    after_23:
    // 0x8000340C: jal         0x80015E94
    // 0x80003410: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80015E94(rdram, ctx);
        goto after_24;
    // 0x80003410: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_24:
    // 0x80003414: jal         0x80015E94
    // 0x80003418: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80015E94(rdram, ctx);
        goto after_25;
    // 0x80003418: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_25:
    // 0x8000341C: jal         0x80015E94
    // 0x80003420: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80015E94(rdram, ctx);
        goto after_26;
    // 0x80003420: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_26:
    // 0x80003424: jal         0x80015E94
    // 0x80003428: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80015E94(rdram, ctx);
        goto after_27;
    // 0x80003428: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_27:
    // 0x8000342C: jal         0x80015E94
    // 0x80003430: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80015E94(rdram, ctx);
        goto after_28;
    // 0x80003430: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_28:
    // 0x80003434: jal         0x800161E0
    // 0x80003438: nop

    func_800161E0(rdram, ctx);
        goto after_29;
    // 0x80003438: nop

    after_29:
    // 0x8000343C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80003440: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80003444: lhu         $t9, 0x2($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X2);
    // 0x80003448: nop

    // 0x8000344C: andi        $t6, $t9, 0x2
    ctx->r14 = ctx->r25 & 0X2;
    // 0x80003450: beq         $t6, $zero, L_8000346C
    if (ctx->r14 == 0) {
        // 0x80003454: nop
    
            goto L_8000346C;
    }
    // 0x80003454: nop

    // 0x80003458: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8000345C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80003460: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80003464: b           L_800034B8
    // 0x80003468: swc1        $f8, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f8.u32l;
        goto L_800034B8;
    // 0x80003468: swc1        $f8, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f8.u32l;
L_8000346C:
    // 0x8000346C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80003470: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80003474: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x80003478: nop

    // 0x8000347C: andi        $t0, $t5, 0x4
    ctx->r8 = ctx->r13 & 0X4;
    // 0x80003480: beq         $t0, $zero, L_800034B8
    if (ctx->r8 == 0) {
        // 0x80003484: nop
    
            goto L_800034B8;
    }
    // 0x80003484: nop

    // 0x80003488: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8000348C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80003490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80003494: swc1        $f10, -0x44CC($at)
    MEM_W(-0X44CC, ctx->r1) = ctx->f10.u32l;
    // 0x80003498: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8000349C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800034A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800034A4: swc1        $f16, -0x44C4($at)
    MEM_W(-0X44C4, ctx->r1) = ctx->f16.u32l;
    // 0x800034A8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800034AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800034B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800034B4: swc1        $f18, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f18.u32l;
L_800034B8:
    // 0x800034B8: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800034BC: addiu       $t1, $t1, 0x3DF8
    ctx->r9 = ADD32(ctx->r9, 0X3DF8);
    // 0x800034C0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800034C4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800034C8: jal         0x800C143C
    // 0x800034CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_30;
    // 0x800034CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_30:
    // 0x800034D0: jal         0x800045AC
    // 0x800034D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_31;
    // 0x800034D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_31:
    // 0x800034D8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800034DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800034E0: jal         0x8000BDDC
    // 0x800034E4: nop

    func_8000BDDC(rdram, ctx);
        goto after_32;
    // 0x800034E4: nop

    after_32:
    // 0x800034E8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800034EC: addiu       $t3, $t3, 0x3DF8
    ctx->r11 = ADD32(ctx->r11, 0X3DF8);
    // 0x800034F0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800034F4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800034F8: jal         0x800C143C
    // 0x800034FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_33;
    // 0x800034FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_33:
    // 0x80003500: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80003504: lh          $t2, 0x7254($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7254);
    // 0x80003508: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000350C: andi        $t7, $t2, 0x7FFF
    ctx->r15 = ctx->r10 & 0X7FFF;
    // 0x80003510: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
    // 0x80003514: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80003518: lh          $t4, 0x725C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X725C);
    // 0x8000351C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003520: andi        $t9, $t4, 0x7FFF
    ctx->r25 = ctx->r12 & 0X7FFF;
    // 0x80003524: sh          $t9, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r25;
    // 0x80003528: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000352C: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80003530: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80003534: nop

    // 0x80003538: andi        $t5, $t8, 0x4000
    ctx->r13 = ctx->r24 & 0X4000;
    // 0x8000353C: bne         $t5, $zero, L_80003554
    if (ctx->r13 != 0) {
        // 0x80003540: nop
    
            goto L_80003554;
    }
    // 0x80003540: nop

    // 0x80003544: jal         0x8000BB00
    // 0x80003548: nop

    func_8000BB00(rdram, ctx);
        goto after_34;
    // 0x80003548: nop

    after_34:
    // 0x8000354C: b           L_80003594
    // 0x80003550: nop

        goto L_80003594;
    // 0x80003550: nop

L_80003554:
    // 0x80003554: jal         0x8000BC7C
    // 0x80003558: nop

    func_8000BC7C(rdram, ctx);
        goto after_35;
    // 0x80003558: nop

    after_35:
    // 0x8000355C: jal         0x80004510
    // 0x80003560: nop

    func_80004510(rdram, ctx);
        goto after_36;
    // 0x80003560: nop

    after_36:
    // 0x80003564: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80003568: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8000356C: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x80003570: nop

    // 0x80003574: ori         $t3, $t1, 0x4
    ctx->r11 = ctx->r9 | 0X4;
    // 0x80003578: sh          $t3, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r11;
    // 0x8000357C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80003580: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80003584: lhu         $t7, 0x6($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X6);
    // 0x80003588: nop

    // 0x8000358C: ori         $t4, $t7, 0x800
    ctx->r12 = ctx->r15 | 0X800;
    // 0x80003590: sh          $t4, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r12;
L_80003594:
    // 0x80003594: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80003598: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8000359C: lhu         $t6, 0x6($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X6);
    // 0x800035A0: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x800035A4: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800035A8: sh          $t8, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r24;
    // 0x800035AC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800035B0: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x800035B4: lhu         $t1, 0x0($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X0);
    // 0x800035B8: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800035BC: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800035C0: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
    // 0x800035C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800035C8: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800035CC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800035D0: addiu       $t0, $t0, 0x3DF8
    ctx->r8 = ADD32(ctx->r8, 0X3DF8);
    // 0x800035D4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800035D8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800035DC: jal         0x800C143C
    // 0x800035E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_37;
    // 0x800035E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_37:
L_800035E4:
    // 0x800035E4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800035E8: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800035EC: lhu         $t4, 0x6($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X6);
    // 0x800035F0: nop

    // 0x800035F4: andi        $t2, $t4, 0x2000
    ctx->r10 = ctx->r12 & 0X2000;
    // 0x800035F8: beq         $t2, $zero, L_80003618
    if (ctx->r10 == 0) {
        // 0x800035FC: nop
    
            goto L_80003618;
    }
    // 0x800035FC: nop

    // 0x80003600: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80003604: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80003608: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x8000360C: nop

    // 0x80003610: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80003614: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
L_80003618:
    // 0x80003618: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000361C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80003620: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x80003624: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x80003628: jal         0x80004410
    // 0x8000362C: nop

    func_80004410(rdram, ctx);
        goto after_38;
    // 0x8000362C: nop

    after_38:
    // 0x80003630: sw          $v0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r2;
    // 0x80003634: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x80003638: nop

    // 0x8000363C: bne         $t1, $zero, L_8000364C
    if (ctx->r9 != 0) {
        // 0x80003640: nop
    
            goto L_8000364C;
    }
    // 0x80003640: nop

    // 0x80003644: b           L_80004400
    // 0x80003648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80004400;
    // 0x80003648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000364C:
    // 0x8000364C: jal         0x800C4270
    // 0x80003650: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_39;
    // 0x80003650: nop

    after_39:
    // 0x80003654: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x80003658: nop

    // 0x8000365C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80003660: nop

    // 0x80003664: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x80003668: lw          $t0, 0xF4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF4);
    // 0x8000366C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003670: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x80003674: addiu       $t4, $t0, 0x2
    ctx->r12 = ADD32(ctx->r8, 0X2);
    // 0x80003678: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    // 0x8000367C: sh          $t7, 0x721C($at)
    MEM_H(0X721C, ctx->r1) = ctx->r15;
    // 0x80003680: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80003684: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003688: lhu         $t8, 0x0($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X0);
    // 0x8000368C: addiu       $t9, $t2, 0x2
    ctx->r25 = ADD32(ctx->r10, 0X2);
    // 0x80003690: sw          $t9, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r25;
    // 0x80003694: sh          $t8, 0x72D4($at)
    MEM_H(0X72D4, ctx->r1) = ctx->r24;
    // 0x80003698: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8000369C: lh          $t6, 0x72D4($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72D4);
    // 0x800036A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800036A4: bne         $t6, $at, L_800036B4
    if (ctx->r14 != ctx->r1) {
        // 0x800036A8: nop
    
            goto L_800036B4;
    }
    // 0x800036A8: nop

    // 0x800036AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800036B0: sh          $zero, 0x72D4($at)
    MEM_H(0X72D4, ctx->r1) = 0;
L_800036B4:
    // 0x800036B4: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    // 0x800036B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800036BC: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x800036C0: addiu       $t5, $t1, 0x2
    ctx->r13 = ADD32(ctx->r9, 0X2);
    // 0x800036C4: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800036C8: sw          $t3, -0x71BC($at)
    MEM_W(-0X71BC, ctx->r1) = ctx->r11;
    // 0x800036CC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800036D0: lw          $t7, -0x71BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71BC);
    // 0x800036D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800036D8: bne         $t7, $at, L_800036EC
    if (ctx->r15 != ctx->r1) {
        // 0x800036DC: nop
    
            goto L_800036EC;
    }
    // 0x800036DC: nop

    // 0x800036E0: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x800036E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800036E8: sw          $t0, -0x71BC($at)
    MEM_W(-0X71BC, ctx->r1) = ctx->r8;
L_800036EC:
    // 0x800036EC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800036F0: lw          $t4, -0x33BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X33BC);
    // 0x800036F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800036F8: sw          $t4, 0x18EC($at)
    MEM_W(0X18EC, ctx->r1) = ctx->r12;
    // 0x800036FC: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x80003700: nop

    // 0x80003704: lh          $t2, 0x0($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X0);
    // 0x80003708: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000370C: sw          $t9, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r25;
    // 0x80003710: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x80003714: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80003718: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000371C: beq         $t6, $at, L_80003764
    if (ctx->r14 == ctx->r1) {
        // 0x80003720: nop
    
            goto L_80003764;
    }
    // 0x80003720: nop

    // 0x80003724: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80003728: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000372C: sw          $t3, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r11;
    // 0x80003730: jal         0x800BB578
    // 0x80003734: nop

    func_800BB578(rdram, ctx);
        goto after_40;
    // 0x80003734: nop

    after_40:
    // 0x80003738: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x8000373C: sw          $t1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r9;
    // 0x80003740: lw          $t5, 0x104($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X104);
    // 0x80003744: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80003748: beq         $t5, $at, L_80003764
    if (ctx->r13 == ctx->r1) {
        // 0x8000374C: nop
    
            goto L_80003764;
    }
    // 0x8000374C: nop

    // 0x80003750: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003754: lw          $t7, -0x33BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33BC);
    // 0x80003758: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000375C: nor         $t0, $t7, $zero
    ctx->r8 = ~(ctx->r15 | 0);
    // 0x80003760: sw          $t0, 0x18EC($at)
    MEM_W(0X18EC, ctx->r1) = ctx->r8;
L_80003764:
    // 0x80003764: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80003768: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000376C: lhu         $t2, 0x6($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X6);
    // 0x80003770: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80003774: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x80003778: sh          $t8, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r24;
    // 0x8000377C: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80003780: nop

    // 0x80003784: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80003788: addiu       $t3, $t9, 0x2
    ctx->r11 = ADD32(ctx->r25, 0X2);
    // 0x8000378C: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
    // 0x80003790: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x80003794: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x80003798: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000379C: beq         $t1, $at, L_800037BC
    if (ctx->r9 == ctx->r1) {
        // 0x800037A0: nop
    
            goto L_800037BC;
    }
    // 0x800037A0: nop

    // 0x800037A4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800037A8: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x800037AC: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x800037B0: nop

    // 0x800037B4: ori         $t0, $t7, 0x2
    ctx->r8 = ctx->r15 | 0X2;
    // 0x800037B8: sh          $t0, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r8;
L_800037BC:
    // 0x800037BC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800037C0: lh          $t2, 0x721C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X721C);
    // 0x800037C4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800037C8: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800037CC: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x800037D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800037D4: sh          $t8, 0x721C($at)
    MEM_H(0X721C, ctx->r1) = ctx->r24;
    // 0x800037D8: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800037DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800037E0: sh          $t4, 0x7228($at)
    MEM_H(0X7228, ctx->r1) = ctx->r12;
    // 0x800037E4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800037E8: lh          $t6, 0x7228($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7228);
    // 0x800037EC: nop

    // 0x800037F0: beq         $t6, $zero, L_8000380C
    if (ctx->r14 == 0) {
        // 0x800037F4: nop
    
            goto L_8000380C;
    }
    // 0x800037F4: nop

    // 0x800037F8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800037FC: lw          $t9, 0x7238($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7238);
    // 0x80003800: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003804: ori         $t3, $t9, 0x8000
    ctx->r11 = ctx->r25 | 0X8000;
    // 0x80003808: sw          $t3, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r11;
L_8000380C:
    // 0x8000380C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80003810: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80003814: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x80003818: nop

    // 0x8000381C: andi        $t0, $t7, 0x80
    ctx->r8 = ctx->r15 & 0X80;
    // 0x80003820: beq         $t0, $zero, L_8000383C
    if (ctx->r8 == 0) {
        // 0x80003824: nop
    
            goto L_8000383C;
    }
    // 0x80003824: nop

    // 0x80003828: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000382C: lh          $t5, 0x721C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X721C);
    // 0x80003830: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003834: addiu       $t2, $t5, 0x2
    ctx->r10 = ADD32(ctx->r13, 0X2);
    // 0x80003838: sh          $t2, 0x721C($at)
    MEM_H(0X721C, ctx->r1) = ctx->r10;
L_8000383C:
    // 0x8000383C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80003840: lh          $t8, 0x721C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X721C);
    // 0x80003844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003848: beq         $t8, $at, L_8000385C
    if (ctx->r24 == ctx->r1) {
        // 0x8000384C: nop
    
            goto L_8000385C;
    }
    // 0x8000384C: nop

    // 0x80003850: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80003854: bne         $t8, $at, L_80003878
    if (ctx->r24 != ctx->r1) {
        // 0x80003858: nop
    
            goto L_80003878;
    }
    // 0x80003858: nop

L_8000385C:
    // 0x8000385C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80003860: lw          $t4, 0x7238($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7238);
    // 0x80003864: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80003868: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8000386C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80003870: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003874: sw          $t6, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r14;
L_80003878:
    // 0x80003878: addiu       $a0, $sp, 0xF4
    ctx->r4 = ADD32(ctx->r29, 0XF4);
    // 0x8000387C: jal         0x80004CD4
    // 0x80003880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80004CD4(rdram, ctx);
        goto after_41;
    // 0x80003880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x80003884: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003888: bne         $v0, $at, L_80003898
    if (ctx->r2 != ctx->r1) {
        // 0x8000388C: nop
    
            goto L_80003898;
    }
    // 0x8000388C: nop

    // 0x80003890: b           L_80004400
    // 0x80003894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80004400;
    // 0x80003894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003898:
    // 0x80003898: jal         0x80004ADC
    // 0x8000389C: nop

    func_80004ADC(rdram, ctx);
        goto after_42;
    // 0x8000389C: nop

    after_42:
    // 0x800038A0: lui         $t9, 0x809B
    ctx->r25 = S32(0X809B << 16);
    // 0x800038A4: lui         $t3, 0x809B
    ctx->r11 = S32(0X809B << 16);
    // 0x800038A8: addiu       $t3, $t3, -0x7E70
    ctx->r11 = ADD32(ctx->r11, -0X7E70);
    // 0x800038AC: addiu       $t9, $t9, -0x7DD0
    ctx->r25 = ADD32(ctx->r25, -0X7DD0);
    // 0x800038B0: subu        $a0, $t9, $t3
    ctx->r4 = SUB32(ctx->r25, ctx->r11);
    // 0x800038B4: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x800038B8: srl         $t1, $a0, 3
    ctx->r9 = S32(U32(ctx->r4) >> 3);
    // 0x800038BC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800038C0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800038C4: jal         0x800BC6EC
    // 0x800038C8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_43;
    // 0x800038C8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_43:
    // 0x800038CC: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800038D0: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800038D4: nop

    // 0x800038D8: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x800038DC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800038E0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800038E4: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800038E8: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800038EC: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x800038F0: jal         0x800BD1FC
    // 0x800038F4: addiu       $a2, $a2, -0x7E70
    ctx->r6 = ADD32(ctx->r6, -0X7E70);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_44;
    // 0x800038F4: addiu       $a2, $a2, -0x7E70
    ctx->r6 = ADD32(ctx->r6, -0X7E70);
    after_44:
    // 0x800038F8: lui         $t5, 0x809B
    ctx->r13 = S32(0X809B << 16);
    // 0x800038FC: lui         $t2, 0x809B
    ctx->r10 = S32(0X809B << 16);
    // 0x80003900: addiu       $t2, $t2, -0x7E70
    ctx->r10 = ADD32(ctx->r10, -0X7E70);
    // 0x80003904: addiu       $t5, $t5, -0x7DD0
    ctx->r13 = ADD32(ctx->r13, -0X7DD0);
    // 0x80003908: subu        $a2, $t5, $t2
    ctx->r6 = SUB32(ctx->r13, ctx->r10);
    // 0x8000390C: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x80003910: srl         $t8, $a2, 3
    ctx->r24 = S32(U32(ctx->r6) >> 3);
    // 0x80003914: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80003918: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x8000391C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80003920: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80003928: jal         0x800BD218
    // 0x8000392C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_45;
    // 0x8000392C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_45:
    // 0x80003930: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003934: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80003938: jal         0x800BCFCC
    // 0x8000393C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_46;
    // 0x8000393C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_46:
    // 0x80003940: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003944: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80003948: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8000394C: jal         0x800BCFCC
    // 0x80003950: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_47;
    // 0x80003950: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_47:
    // 0x80003954: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80003958: jal         0x800BC980
    // 0x8000395C: nop

    SysMem_Free(rdram, ctx);
        goto after_48;
    // 0x8000395C: nop

    after_48:
    // 0x80003960: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80003964: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80003968: lui         $t6, 0x4000
    ctx->r14 = S32(0X4000 << 16);
    // 0x8000396C: ori         $t6, $t6, 0x4C
    ctx->r14 = ctx->r14 | 0X4C;
    // 0x80003970: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x80003974: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80003978: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8000397C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80003980: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80003984: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80003988: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8000398C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80003990: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80003994: jal         0x800A66EC
    // 0x80003998: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_800A66EC(rdram, ctx);
        goto after_49;
    // 0x80003998: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_49:
    // 0x8000399C: lui         $t1, 0x809B
    ctx->r9 = S32(0X809B << 16);
    // 0x800039A0: lui         $t7, 0x809B
    ctx->r15 = S32(0X809B << 16);
    // 0x800039A4: addiu       $t7, $t7, -0x7E70
    ctx->r15 = ADD32(ctx->r15, -0X7E70);
    // 0x800039A8: addiu       $t1, $t1, -0x7DD0
    ctx->r9 = ADD32(ctx->r9, -0X7DD0);
    // 0x800039AC: subu        $a0, $t1, $t7
    ctx->r4 = SUB32(ctx->r9, ctx->r15);
    // 0x800039B0: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x800039B4: srl         $t0, $a0, 3
    ctx->r8 = S32(U32(ctx->r4) >> 3);
    // 0x800039B8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800039BC: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800039C0: jal         0x800BC6EC
    // 0x800039C4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_50;
    // 0x800039C4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_50:
    // 0x800039C8: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800039CC: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x800039D0: nop

    // 0x800039D4: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x800039D8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800039DC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800039E0: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800039E4: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800039E8: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x800039EC: jal         0x800BD1FC
    // 0x800039F0: addiu       $a2, $a2, -0x7E70
    ctx->r6 = ADD32(ctx->r6, -0X7E70);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_51;
    // 0x800039F0: addiu       $a2, $a2, -0x7E70
    ctx->r6 = ADD32(ctx->r6, -0X7E70);
    after_51:
    // 0x800039F4: lui         $t8, 0x809B
    ctx->r24 = S32(0X809B << 16);
    // 0x800039F8: lui         $t4, 0x809B
    ctx->r12 = S32(0X809B << 16);
    // 0x800039FC: addiu       $t4, $t4, -0x7E70
    ctx->r12 = ADD32(ctx->r12, -0X7E70);
    // 0x80003A00: addiu       $t8, $t8, -0x7DD0
    ctx->r24 = ADD32(ctx->r24, -0X7DD0);
    // 0x80003A04: subu        $a2, $t8, $t4
    ctx->r6 = SUB32(ctx->r24, ctx->r12);
    // 0x80003A08: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x80003A0C: srl         $t6, $a2, 3
    ctx->r14 = S32(U32(ctx->r6) >> 3);
    // 0x80003A10: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80003A14: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x80003A18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80003A1C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80003A24: jal         0x800BD218
    // 0x80003A28: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_52;
    // 0x80003A28: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_52:
L_80003A2C:
    // 0x80003A2C: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80003A30: nop

    // 0x80003A34: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80003A38: nop

    // 0x80003A3C: bne         $t1, $zero, L_80003A58
    if (ctx->r9 != 0) {
        // 0x80003A40: nop
    
            goto L_80003A58;
    }
    // 0x80003A40: nop

    // 0x80003A44: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80003A48: jal         0x800BC980
    // 0x80003A4C: nop

    SysMem_Free(rdram, ctx);
        goto after_53;
    // 0x80003A4C: nop

    after_53:
    // 0x80003A50: b           L_80004400
    // 0x80003A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80004400;
    // 0x80003A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003A58:
    // 0x80003A58: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80003A5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003A60: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x80003A64: nop

    // 0x80003A68: bne         $t0, $at, L_80003A88
    if (ctx->r8 != ctx->r1) {
        // 0x80003A6C: nop
    
            goto L_80003A88;
    }
    // 0x80003A6C: nop

    // 0x80003A70: lh          $t5, 0x2($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X2);
    // 0x80003A74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80003A78: bne         $t5, $at, L_80003A88
    if (ctx->r13 != ctx->r1) {
        // 0x80003A7C: nop
    
            goto L_80003A88;
    }
    // 0x80003A7C: nop

    // 0x80003A80: b           L_80003A9C
    // 0x80003A84: nop

        goto L_80003A9C;
    // 0x80003A84: nop

L_80003A88:
    // 0x80003A88: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x80003A8C: nop

    // 0x80003A90: addiu       $t8, $t2, 0x20
    ctx->r24 = ADD32(ctx->r10, 0X20);
    // 0x80003A94: b           L_80003A2C
    // 0x80003A98: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
        goto L_80003A2C;
    // 0x80003A98: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
L_80003A9C:
    // 0x80003A9C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003AA0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80003AA4: jal         0x800BCFCC
    // 0x80003AA8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_54;
    // 0x80003AA8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_54:
    // 0x80003AAC: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003AB0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80003AB4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80003AB8: jal         0x800BCFCC
    // 0x80003ABC: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_55;
    // 0x80003ABC: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_55:
    // 0x80003AC0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80003AC4: jal         0x800BC980
    // 0x80003AC8: nop

    SysMem_Free(rdram, ctx);
        goto after_56;
    // 0x80003AC8: nop

    after_56:
    // 0x80003ACC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80003AD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80003AD4: lui         $t4, 0x4000
    ctx->r12 = S32(0X4000 << 16);
    // 0x80003AD8: ori         $t4, $t4, 0x4C
    ctx->r12 = ctx->r12 | 0X4C;
    // 0x80003ADC: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x80003AE0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80003AE4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80003AE8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80003AEC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80003AF0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80003AF4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80003AF8: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80003AFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80003B00: jal         0x800A66EC
    // 0x80003B04: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_800A66EC(rdram, ctx);
        goto after_57;
    // 0x80003B04: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_57:
    // 0x80003B08: jal         0x8002856C
    // 0x80003B0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002856C(rdram, ctx);
        goto after_58;
    // 0x80003B0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_58:
    // 0x80003B10: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80003B14: lh          $a0, 0x72D4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X72D4);
    // 0x80003B18: jal         0x8002F5C4
    // 0x80003B1C: nop

    func_8002F5C4(rdram, ctx);
        goto after_59;
    // 0x80003B1C: nop

    after_59:
    // 0x80003B20: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80003B24: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80003B28: lhu         $t1, 0x0($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X0);
    // 0x80003B2C: nop

    // 0x80003B30: andi        $t0, $t1, 0x80
    ctx->r8 = ctx->r9 & 0X80;
    // 0x80003B34: bne         $t0, $zero, L_80003B90
    if (ctx->r8 != 0) {
        // 0x80003B38: nop
    
            goto L_80003B90;
    }
    // 0x80003B38: nop

    // 0x80003B3C: jal         0x80015E50
    // 0x80003B40: nop

    func_80015E50(rdram, ctx);
        goto after_60;
    // 0x80003B40: nop

    after_60:
    // 0x80003B44: jal         0x80015E94
    // 0x80003B48: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80015E94(rdram, ctx);
        goto after_61;
    // 0x80003B48: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_61:
    // 0x80003B4C: jal         0x80015E94
    // 0x80003B50: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80015E94(rdram, ctx);
        goto after_62;
    // 0x80003B50: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_62:
    // 0x80003B54: jal         0x80015E94
    // 0x80003B58: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80015E94(rdram, ctx);
        goto after_63;
    // 0x80003B58: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_63:
    // 0x80003B5C: jal         0x80015E94
    // 0x80003B60: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80015E94(rdram, ctx);
        goto after_64;
    // 0x80003B60: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_64:
    // 0x80003B64: jal         0x80015E94
    // 0x80003B68: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80015E94(rdram, ctx);
        goto after_65;
    // 0x80003B68: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_65:
    // 0x80003B6C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003B70: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80003B74: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x80003B78: nop

    // 0x80003B7C: andi        $t2, $t5, 0x200
    ctx->r10 = ctx->r13 & 0X200;
    // 0x80003B80: beq         $t2, $zero, L_80003B90
    if (ctx->r10 == 0) {
        // 0x80003B84: nop
    
            goto L_80003B90;
    }
    // 0x80003B84: nop

    // 0x80003B88: jal         0x800161E0
    // 0x80003B8C: nop

    func_800161E0(rdram, ctx);
        goto after_66;
    // 0x80003B8C: nop

    after_66:
L_80003B90:
    // 0x80003B90: jal         0x80015FB4
    // 0x80003B94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80015FB4(rdram, ctx);
        goto after_67;
    // 0x80003B94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_67:
    // 0x80003B98: jal         0x80015E94
    // 0x80003B9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80015E94(rdram, ctx);
        goto after_68;
    // 0x80003B9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_68:
    // 0x80003BA0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80003BA4: lh          $t8, 0x721C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X721C);
    // 0x80003BA8: nop

    // 0x80003BAC: bne         $t8, $zero, L_80003BF8
    if (ctx->r24 != 0) {
        // 0x80003BB0: nop
    
            goto L_80003BF8;
    }
    // 0x80003BB0: nop

    // 0x80003BB4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80003BB8: lhu         $t4, 0x72D4($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X72D4);
    // 0x80003BBC: nop

    // 0x80003BC0: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x80003BC4: beq         $at, $zero, L_80003BF8
    if (ctx->r1 == 0) {
        // 0x80003BC8: nop
    
            goto L_80003BF8;
    }
    // 0x80003BC8: nop

    // 0x80003BCC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80003BD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80003BD4: addu        $at, $at, $t4
    gpr jr_addend_80003BE0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80003BD8: lw          $t4, -0x2EA0($at)
    ctx->r12 = ADD32(ctx->r1, -0X2EA0);
    // 0x80003BDC: nop

    // 0x80003BE0: jr          $t4
    // 0x80003BE4: nop

    switch (jr_addend_80003BE0 >> 2) {
        case 0: goto L_80003BE8; break;
        case 1: goto L_80003BE8; break;
        case 2: goto L_80003BF0; break;
        case 3: goto L_80003BF0; break;
        case 4: goto L_80003BF0; break;
        default: switch_error(__func__, 0x80003BE0, 0x800ED160);
    }
    // 0x80003BE4: nop

L_80003BE8:
    // 0x80003BE8: jal         0x80004654
    // 0x80003BEC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80004654(rdram, ctx);
        goto after_69;
    // 0x80003BEC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_69:
L_80003BF0:
    // 0x80003BF0: b           L_80003BF8
    // 0x80003BF4: nop

        goto L_80003BF8;
    // 0x80003BF4: nop

L_80003BF8:
    // 0x80003BF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80003BFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80003C00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80003C04: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80003C08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80003C0C: swc1        $f10, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f10.u32l;
    // 0x80003C10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80003C14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80003C18: sw          $t6, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = ctx->r14;
    // 0x80003C1C: jal         0x8005E19C
    // 0x80003C20: nop

    func_8005E19C(rdram, ctx);
        goto after_70;
    // 0x80003C20: nop

    after_70:
    // 0x80003C24: jal         0x8005D800
    // 0x80003C28: nop

    func_8005D800(rdram, ctx);
        goto after_71;
    // 0x80003C28: nop

    after_71:
    // 0x80003C2C: jal         0x8005E474
    // 0x80003C30: nop

    func_8005E474(rdram, ctx);
        goto after_72;
    // 0x80003C30: nop

    after_72:
    // 0x80003C34: jal         0x800821A0
    // 0x80003C38: nop

    func_800821A0(rdram, ctx);
        goto after_73;
    // 0x80003C38: nop

    after_73:
    // 0x80003C3C: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80003C40: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80003C44: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x80003C48: nop

    // 0x80003C4C: beq         $t3, $at, L_80003CC8
    if (ctx->r11 == ctx->r1) {
        // 0x80003C50: nop
    
            goto L_80003CC8;
    }
    // 0x80003C50: nop

L_80003C54:
    // 0x80003C54: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    // 0x80003C58: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80003C5C: lhu         $t0, 0x0($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X0);
    // 0x80003C60: nop

    // 0x80003C64: bne         $t0, $at, L_80003C98
    if (ctx->r8 != ctx->r1) {
        // 0x80003C68: nop
    
            goto L_80003C98;
    }
    // 0x80003C68: nop

    // 0x80003C6C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003C70: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x80003C74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80003C78: bne         $t7, $at, L_80003C98
    if (ctx->r15 != ctx->r1) {
        // 0x80003C7C: nop
    
            goto L_80003C98;
    }
    // 0x80003C7C: nop

    // 0x80003C80: lw          $t5, 0xF4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF4);
    // 0x80003C84: nop

    // 0x80003C88: addiu       $t2, $t5, 0x2
    ctx->r10 = ADD32(ctx->r13, 0X2);
    // 0x80003C8C: sw          $t2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r10;
    // 0x80003C90: b           L_80003CB0
    // 0x80003C94: nop

        goto L_80003CB0;
    // 0x80003C94: nop

L_80003C98:
    // 0x80003C98: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x80003C9C: nop

    // 0x80003CA0: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x80003CA4: addiu       $t4, $t8, 0x2
    ctx->r12 = ADD32(ctx->r24, 0X2);
    // 0x80003CA8: jal         0x80004654
    // 0x80003CAC: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    func_80004654(rdram, ctx);
        goto after_74;
    // 0x80003CAC: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    after_74:
L_80003CB0:
    // 0x80003CB0: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x80003CB4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80003CB8: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x80003CBC: nop

    // 0x80003CC0: bne         $t9, $at, L_80003C54
    if (ctx->r25 != ctx->r1) {
        // 0x80003CC4: nop
    
            goto L_80003C54;
    }
    // 0x80003CC4: nop

L_80003CC8:
    // 0x80003CC8: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x80003CCC: nop

    // 0x80003CD0: addiu       $t1, $t3, 0x2
    ctx->r9 = ADD32(ctx->r11, 0X2);
    // 0x80003CD4: sw          $t1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r9;
    // 0x80003CD8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80003CDC: lh          $t0, 0x721C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X721C);
    // 0x80003CE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003CE4: bne         $t0, $at, L_80003DE4
    if (ctx->r8 != ctx->r1) {
        // 0x80003CE8: nop
    
            goto L_80003DE4;
    }
    // 0x80003CE8: nop

    // 0x80003CEC: b           L_80003CF4
    // 0x80003CF0: nop

        goto L_80003CF4;
    // 0x80003CF0: nop

L_80003CF4:
    // 0x80003CF4: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x80003CF8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80003CFC: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x80003D00: nop

    // 0x80003D04: beq         $t5, $at, L_80003D3C
    if (ctx->r13 == ctx->r1) {
        // 0x80003D08: nop
    
            goto L_80003D3C;
    }
    // 0x80003D08: nop

    // 0x80003D0C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80003D10: nop

    // 0x80003D14: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x80003D18: jal         0x80043DC0
    // 0x80003D1C: nop

    func_80043DC0(rdram, ctx);
        goto after_75;
    // 0x80003D1C: nop

    after_75:
    // 0x80003D20: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80003D24: lw          $t8, 0x7238($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7238);
    // 0x80003D28: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80003D2C: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80003D30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003D34: b           L_80003DDC
    // 0x80003D38: sw          $t4, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r12;
        goto L_80003DDC;
    // 0x80003D38: sw          $t4, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r12;
L_80003D3C:
    // 0x80003D3C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80003D40: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80003D44: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x80003D48: nop

    // 0x80003D4C: andi        $t3, $t9, 0x200
    ctx->r11 = ctx->r25 & 0X200;
    // 0x80003D50: bne         $t3, $zero, L_80003D68
    if (ctx->r11 != 0) {
        // 0x80003D54: nop
    
            goto L_80003D68;
    }
    // 0x80003D54: nop

    // 0x80003D58: jal         0x800AF060
    // 0x80003D5C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800AF060(rdram, ctx);
        goto after_76;
    // 0x80003D5C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_76:
    // 0x80003D60: b           L_80003DDC
    // 0x80003D64: nop

        goto L_80003DDC;
    // 0x80003D64: nop

L_80003D68:
    // 0x80003D68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003D6C: sh          $zero, 0x7228($at)
    MEM_H(0X7228, ctx->r1) = 0;
    // 0x80003D70: jal         0x800AF060
    // 0x80003D74: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800AF060(rdram, ctx);
        goto after_77;
    // 0x80003D74: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_77:
    // 0x80003D78: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
L_80003D7C:
    // 0x80003D7C: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x80003D80: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003D84: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80003D88: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80003D8C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80003D90: lw          $t7, -0x73D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73D0);
    // 0x80003D94: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80003D98: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80003D9C: addu        $t5, $t0, $t7
    ctx->r13 = ADD32(ctx->r8, ctx->r15);
    // 0x80003DA0: lw          $t2, 0xC0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0XC0);
    // 0x80003DA4: nop

    // 0x80003DA8: ori         $t8, $t2, 0x200
    ctx->r24 = ctx->r10 | 0X200;
    // 0x80003DAC: sw          $t8, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r24;
    // 0x80003DB0: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x80003DB4: nop

    // 0x80003DB8: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80003DBC: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80003DC0: bne         $at, $zero, L_80003D7C
    if (ctx->r1 != 0) {
        // 0x80003DC4: sw          $t6, 0x100($sp)
        MEM_W(0X100, ctx->r29) = ctx->r14;
            goto L_80003D7C;
    }
    // 0x80003DC4: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x80003DC8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80003DCC: lh          $t9, 0x721C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X721C);
    // 0x80003DD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003DD4: addiu       $t3, $t9, 0x2
    ctx->r11 = ADD32(ctx->r25, 0X2);
    // 0x80003DD8: sh          $t3, 0x721C($at)
    MEM_H(0X721C, ctx->r1) = ctx->r11;
L_80003DDC:
    // 0x80003DDC: b           L_80003E9C
    // 0x80003DE0: nop

        goto L_80003E9C;
    // 0x80003DE0: nop

L_80003DE4:
    // 0x80003DE4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80003DE8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80003DEC: lhu         $t0, 0x0($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X0);
    // 0x80003DF0: nop

    // 0x80003DF4: andi        $t7, $t0, 0x80
    ctx->r15 = ctx->r8 & 0X80;
    // 0x80003DF8: bne         $t7, $zero, L_80003E10
    if (ctx->r15 != 0) {
        // 0x80003DFC: nop
    
            goto L_80003E10;
    }
    // 0x80003DFC: nop

    // 0x80003E00: jal         0x800AF060
    // 0x80003E04: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800AF060(rdram, ctx);
        goto after_78;
    // 0x80003E04: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_78:
    // 0x80003E08: b           L_80003E94
    // 0x80003E0C: nop

        goto L_80003E94;
    // 0x80003E0C: nop

L_80003E10:
    // 0x80003E10: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80003E14: lh          $t2, 0x721C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X721C);
    // 0x80003E18: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80003E1C: bne         $t2, $at, L_80003E8C
    if (ctx->r10 != ctx->r1) {
        // 0x80003E20: nop
    
            goto L_80003E8C;
    }
    // 0x80003E20: nop

    // 0x80003E24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003E28: sh          $zero, 0x7228($at)
    MEM_H(0X7228, ctx->r1) = 0;
    // 0x80003E2C: jal         0x800AF060
    // 0x80003E30: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800AF060(rdram, ctx);
        goto after_79;
    // 0x80003E30: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_79:
    // 0x80003E34: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
L_80003E38:
    // 0x80003E38: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80003E3C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80003E40: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80003E44: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x80003E48: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80003E4C: lw          $t4, -0x73D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73D0);
    // 0x80003E50: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x80003E54: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80003E58: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80003E5C: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x80003E60: nop

    // 0x80003E64: ori         $t3, $t9, 0x200
    ctx->r11 = ctx->r25 | 0X200;
    // 0x80003E68: sw          $t3, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r11;
    // 0x80003E6C: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x80003E70: nop

    // 0x80003E74: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80003E78: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80003E7C: bne         $at, $zero, L_80003E38
    if (ctx->r1 != 0) {
        // 0x80003E80: sw          $t0, 0x100($sp)
        MEM_W(0X100, ctx->r29) = ctx->r8;
            goto L_80003E38;
    }
    // 0x80003E80: sw          $t0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r8;
    // 0x80003E84: b           L_80003E94
    // 0x80003E88: nop

        goto L_80003E94;
    // 0x80003E88: nop

L_80003E8C:
    // 0x80003E8C: jal         0x800AF060
    // 0x80003E90: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800AF060(rdram, ctx);
        goto after_80;
    // 0x80003E90: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_80:
L_80003E94:
    // 0x80003E94: b           L_80003E9C
    // 0x80003E98: nop

        goto L_80003E9C;
    // 0x80003E98: nop

L_80003E9C:
    // 0x80003E9C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003EA0: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80003EA4: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x80003EA8: nop

    // 0x80003EAC: andi        $t8, $t2, 0x2000
    ctx->r24 = ctx->r10 & 0X2000;
    // 0x80003EB0: bne         $t8, $zero, L_80003F30
    if (ctx->r24 != 0) {
        // 0x80003EB4: nop
    
            goto L_80003F30;
    }
    // 0x80003EB4: nop

    // 0x80003EB8: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80003EBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80003EC0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80003EC4: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x80003EC8: swc1        $f16, 0x72C($t5)
    MEM_W(0X72C, ctx->r13) = ctx->f16.u32l;
    // 0x80003ECC: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80003ED0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80003ED4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80003ED8: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x80003EDC: swc1        $f18, 0x734($t4)
    MEM_W(0X734, ctx->r12) = ctx->f18.u32l;
    // 0x80003EE0: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80003EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80003EE8: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80003EEC: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x80003EF0: swc1        $f4, 0x864($t9)
    MEM_W(0X864, ctx->r25) = ctx->f4.u32l;
    // 0x80003EF4: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80003EF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80003EFC: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80003F00: addiu       $t3, $t3, 0x61D8
    ctx->r11 = ADD32(ctx->r11, 0X61D8);
    // 0x80003F04: swc1        $f6, 0x86C($t3)
    MEM_W(0X86C, ctx->r11) = ctx->f6.u32l;
    // 0x80003F08: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80003F0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80003F10: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80003F14: addiu       $t6, $t6, 0x61D8
    ctx->r14 = ADD32(ctx->r14, 0X61D8);
    // 0x80003F18: swc1        $f8, 0x5F4($t6)
    MEM_W(0X5F4, ctx->r14) = ctx->f8.u32l;
    // 0x80003F1C: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80003F20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80003F24: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80003F28: addiu       $t1, $t1, 0x61D8
    ctx->r9 = ADD32(ctx->r9, 0X61D8);
    // 0x80003F2C: swc1        $f10, 0x5FC($t1)
    MEM_W(0X5FC, ctx->r9) = ctx->f10.u32l;
L_80003F30:
    // 0x80003F30: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80003F34: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80003F38: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x80003F3C: nop

    // 0x80003F40: andi        $t2, $t7, 0x200
    ctx->r10 = ctx->r15 & 0X200;
    // 0x80003F44: beq         $t2, $zero, L_80003F98
    if (ctx->r10 == 0) {
        // 0x80003F48: nop
    
            goto L_80003F98;
    }
    // 0x80003F48: nop

    // 0x80003F4C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80003F50: lwc1        $f16, 0x61C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80003F54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003F58: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80003F5C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80003F60: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80003F64: addiu       $t8, $t8, 0x61D8
    ctx->r24 = ADD32(ctx->r24, 0X61D8);
    // 0x80003F68: swc1        $f4, 0x72C($t8)
    MEM_W(0X72C, ctx->r24) = ctx->f4.u32l;
    // 0x80003F6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80003F70: lwc1        $f6, 0x61C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80003F74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003F78: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80003F7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80003F80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80003F84: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80003F88: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80003F8C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80003F90: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x80003F94: swc1        $f18, 0x734($t5)
    MEM_W(0X734, ctx->r13) = ctx->f18.u32l;
L_80003F98:
    // 0x80003F98: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80003F9C: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80003FA0: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x80003FA4: nop

    // 0x80003FA8: andi        $t3, $t9, 0x80
    ctx->r11 = ctx->r25 & 0X80;
    // 0x80003FAC: bne         $t3, $zero, L_80004078
    if (ctx->r11 != 0) {
        // 0x80003FB0: nop
    
            goto L_80004078;
    }
    // 0x80003FB0: nop

    // 0x80003FB4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80003FB8: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80003FBC: lhu         $t1, 0x2($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X2);
    // 0x80003FC0: nop

    // 0x80003FC4: andi        $t0, $t1, 0x1
    ctx->r8 = ctx->r9 & 0X1;
    // 0x80003FC8: beq         $t0, $zero, L_80003FE0
    if (ctx->r8 == 0) {
        // 0x80003FCC: nop
    
            goto L_80003FE0;
    }
    // 0x80003FCC: nop

    // 0x80003FD0: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80003FD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80003FD8: b           L_80004070
    // 0x80003FDC: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
        goto L_80004070;
    // 0x80003FDC: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
L_80003FE0:
    // 0x80003FE0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80003FE4: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80003FE8: lhu         $t8, 0x2($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X2);
    // 0x80003FEC: nop

    // 0x80003FF0: andi        $t5, $t8, 0x2
    ctx->r13 = ctx->r24 & 0X2;
    // 0x80003FF4: beq         $t5, $zero, L_8000400C
    if (ctx->r13 == 0) {
        // 0x80003FF8: nop
    
            goto L_8000400C;
    }
    // 0x80003FF8: nop

    // 0x80003FFC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80004000: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004004: b           L_80004070
    // 0x80004008: sw          $t4, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r12;
        goto L_80004070;
    // 0x80004008: sw          $t4, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r12;
L_8000400C:
    // 0x8000400C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80004010: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80004014: lhu         $t3, 0x2($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X2);
    // 0x80004018: nop

    // 0x8000401C: andi        $t6, $t3, 0x4
    ctx->r14 = ctx->r11 & 0X4;
    // 0x80004020: beq         $t6, $zero, L_80004038
    if (ctx->r14 == 0) {
        // 0x80004024: nop
    
            goto L_80004038;
    }
    // 0x80004024: nop

    // 0x80004028: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x8000402C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004030: b           L_80004070
    // 0x80004034: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
        goto L_80004070;
    // 0x80004034: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
L_80004038:
    // 0x80004038: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000403C: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80004040: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x80004044: nop

    // 0x80004048: andi        $t2, $t7, 0x8
    ctx->r10 = ctx->r15 & 0X8;
    // 0x8000404C: beq         $t2, $zero, L_80004064
    if (ctx->r10 == 0) {
        // 0x80004050: nop
    
            goto L_80004064;
    }
    // 0x80004050: nop

    // 0x80004054: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80004058: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000405C: b           L_80004070
    // 0x80004060: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
        goto L_80004070;
    // 0x80004060: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
L_80004064:
    // 0x80004064: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80004068: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000406C: sw          $t5, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r13;
L_80004070:
    // 0x80004070: b           L_80004124
    // 0x80004074: nop

        goto L_80004124;
    // 0x80004074: nop

L_80004078:
    // 0x80004078: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000407C: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80004080: lhu         $t9, 0x2($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X2);
    // 0x80004084: nop

    // 0x80004088: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x8000408C: beq         $t3, $zero, L_800040A4
    if (ctx->r11 == 0) {
        // 0x80004090: nop
    
            goto L_800040A4;
    }
    // 0x80004090: nop

    // 0x80004094: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80004098: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000409C: b           L_80004124
    // 0x800040A0: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
        goto L_80004124;
    // 0x800040A0: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
L_800040A4:
    // 0x800040A4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800040A8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800040AC: lhu         $t0, 0x2($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X2);
    // 0x800040B0: nop

    // 0x800040B4: andi        $t7, $t0, 0x2
    ctx->r15 = ctx->r8 & 0X2;
    // 0x800040B8: beq         $t7, $zero, L_800040D0
    if (ctx->r15 == 0) {
        // 0x800040BC: nop
    
            goto L_800040D0;
    }
    // 0x800040BC: nop

    // 0x800040C0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800040C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800040C8: b           L_80004124
    // 0x800040CC: sw          $t2, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r10;
        goto L_80004124;
    // 0x800040CC: sw          $t2, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r10;
L_800040D0:
    // 0x800040D0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800040D4: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800040D8: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x800040DC: nop

    // 0x800040E0: andi        $t4, $t5, 0x4
    ctx->r12 = ctx->r13 & 0X4;
    // 0x800040E4: beq         $t4, $zero, L_800040FC
    if (ctx->r12 == 0) {
        // 0x800040E8: nop
    
            goto L_800040FC;
    }
    // 0x800040E8: nop

    // 0x800040EC: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x800040F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800040F4: b           L_80004124
    // 0x800040F8: sw          $t9, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r25;
        goto L_80004124;
    // 0x800040F8: sw          $t9, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r25;
L_800040FC:
    // 0x800040FC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80004100: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80004104: lhu         $t6, 0x2($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X2);
    // 0x80004108: nop

    // 0x8000410C: andi        $t1, $t6, 0x8
    ctx->r9 = ctx->r14 & 0X8;
    // 0x80004110: beq         $t1, $zero, L_80004124
    if (ctx->r9 == 0) {
        // 0x80004114: nop
    
            goto L_80004124;
    }
    // 0x80004114: nop

    // 0x80004118: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8000411C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004120: sw          $t0, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r8;
L_80004124:
    // 0x80004124: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80004128: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000412C: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x80004130: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80004134: lw          $s0, -0x73CC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X73CC);
    // 0x80004138: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8000413C: beq         $s0, $at, L_800042F8
    if (ctx->r16 == ctx->r1) {
        // 0x80004140: nop
    
            goto L_800042F8;
    }
    // 0x80004140: nop

    // 0x80004144: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80004148: beq         $s0, $at, L_80004294
    if (ctx->r16 == ctx->r1) {
        // 0x8000414C: nop
    
            goto L_80004294;
    }
    // 0x8000414C: nop

    // 0x80004150: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80004154: beq         $s0, $at, L_80004164
    if (ctx->r16 == ctx->r1) {
        // 0x80004158: nop
    
            goto L_80004164;
    }
    // 0x80004158: nop

    // 0x8000415C: b           L_8000438C
    // 0x80004160: nop

        goto L_8000438C;
    // 0x80004160: nop

L_80004164:
    // 0x80004164: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004168: lwc1        $f4, -0x4508($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x8000416C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80004170: nop

    // 0x80004174: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80004178: nop

    // 0x8000417C: bc1f        L_80004198
    if (!c1cs) {
        // 0x80004180: nop
    
            goto L_80004198;
    }
    // 0x80004180: nop

    // 0x80004184: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80004188: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000418C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004190: b           L_800041F4
    // 0x80004194: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
        goto L_800041F4;
    // 0x80004194: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
L_80004198:
    // 0x80004198: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000419C: lwc1        $f10, -0x4508($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x800041A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800041A4: nop

    // 0x800041A8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800041AC: nop

    // 0x800041B0: bc1f        L_800041F4
    if (!c1cs) {
        // 0x800041B4: nop
    
            goto L_800041F4;
    }
    // 0x800041B4: nop

    // 0x800041B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800041BC: lwc1        $f18, -0x4508($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x800041C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800041C4: nop

    // 0x800041C8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800041CC: nop

    // 0x800041D0: bc1f        L_800041E0
    if (!c1cs) {
        // 0x800041D4: nop
    
            goto L_800041E0;
    }
    // 0x800041D4: nop

    // 0x800041D8: b           L_800041F4
    // 0x800041DC: nop

        goto L_800041F4;
    // 0x800041DC: nop

L_800041E0:
    // 0x800041E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800041E4: lwc1        $f6, -0x4508($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x800041E8: nop

    // 0x800041EC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800041F0: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
L_800041F4:
    // 0x800041F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800041F8: jal         0x80016620
    // 0x800041FC: addiu       $a0, $a0, -0x4508
    ctx->r4 = ADD32(ctx->r4, -0X4508);
    func_80016620(rdram, ctx);
        goto after_81;
    // 0x800041FC: addiu       $a0, $a0, -0x4508
    ctx->r4 = ADD32(ctx->r4, -0X4508);
    after_81:
    // 0x80004200: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80004204: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80004208: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000420C: swc1        $f10, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f10.u32l;
    // 0x80004210: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004214: sw          $zero, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = 0;
    // 0x80004218: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000421C: sw          $zero, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = 0;
    // 0x80004220: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004224: sw          $zero, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = 0;
    // 0x80004228: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x8000422C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004230: sw          $t2, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r10;
    // 0x80004234: addiu       $t8, $zero, 0xA8
    ctx->r24 = ADD32(0, 0XA8);
    // 0x80004238: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000423C: sw          $t8, -0x44F4($at)
    MEM_W(-0X44F4, ctx->r1) = ctx->r24;
    // 0x80004240: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80004244: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004248: swc1        $f16, -0x44F0($at)
    MEM_W(-0X44F0, ctx->r1) = ctx->f16.u32l;
    // 0x8000424C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80004250: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80004254: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004258: swc1        $f18, -0x44EC($at)
    MEM_W(-0X44EC, ctx->r1) = ctx->f18.u32l;
    // 0x8000425C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80004260: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004264: swc1        $f4, -0x44E8($at)
    MEM_W(-0X44E8, ctx->r1) = ctx->f4.u32l;
    // 0x80004268: addiu       $t5, $zero, 0x3E8
    ctx->r13 = ADD32(0, 0X3E8);
    // 0x8000426C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004270: sw          $t5, -0x44E4($at)
    MEM_W(-0X44E4, ctx->r1) = ctx->r13;
    // 0x80004274: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80004278: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000427C: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x80004280: nop

    // 0x80004284: ori         $t3, $t9, 0x400
    ctx->r11 = ctx->r25 | 0X400;
    // 0x80004288: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8000428C: b           L_800043AC
    // 0x80004290: nop

        goto L_800043AC;
    // 0x80004290: nop

L_80004294:
    // 0x80004294: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80004298: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000429C: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x800042A0: nop

    // 0x800042A4: andi        $t0, $t1, 0x80
    ctx->r8 = ctx->r9 & 0X80;
    // 0x800042A8: bne         $t0, $zero, L_800042C0
    if (ctx->r8 != 0) {
        // 0x800042AC: nop
    
            goto L_800042C0;
    }
    // 0x800042AC: nop

    // 0x800042B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800042B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800042B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800042BC: swc1        $f6, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f6.u32l;
L_800042C0:
    // 0x800042C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800042C4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800042C8: lw          $a1, -0x44D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X44D4);
    // 0x800042CC: lw          $a0, 0x18E4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18E4);
    // 0x800042D0: jal         0x80017B80
    // 0x800042D4: nop

    func_80017B80(rdram, ctx);
        goto after_82;
    // 0x800042D4: nop

    after_82:
    // 0x800042D8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800042DC: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800042E0: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x800042E4: nop

    // 0x800042E8: ori         $t8, $t2, 0x400
    ctx->r24 = ctx->r10 | 0X400;
    // 0x800042EC: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x800042F0: b           L_800043AC
    // 0x800042F4: nop

        goto L_800043AC;
    // 0x800042F4: nop

L_800042F8:
    // 0x800042F8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800042FC: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80004300: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x80004304: nop

    // 0x80004308: andi        $t3, $t9, 0x80
    ctx->r11 = ctx->r25 & 0X80;
    // 0x8000430C: bne         $t3, $zero, L_80004344
    if (ctx->r11 != 0) {
        // 0x80004310: nop
    
            goto L_80004344;
    }
    // 0x80004310: nop

    // 0x80004314: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80004318: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000431C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004320: swc1        $f8, -0x44CC($at)
    MEM_W(-0X44CC, ctx->r1) = ctx->f8.u32l;
    // 0x80004324: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80004328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000432C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004330: swc1        $f10, -0x44C4($at)
    MEM_W(-0X44C4, ctx->r1) = ctx->f10.u32l;
    // 0x80004334: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80004338: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000433C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004340: swc1        $f16, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f16.u32l;
L_80004344:
    // 0x80004344: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004348: lwc1        $f18, -0x44D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X44D4);
    // 0x8000434C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80004350: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x80004354: lw          $a3, -0x44C4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X44C4);
    // 0x80004358: lw          $a2, -0x44CC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44CC);
    // 0x8000435C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80004360: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80004364: jal         0x8001A040
    // 0x80004368: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_8001A040(rdram, ctx);
        goto after_83;
    // 0x80004368: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_83:
    // 0x8000436C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80004370: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80004374: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x80004378: nop

    // 0x8000437C: ori         $t1, $t6, 0x400
    ctx->r9 = ctx->r14 | 0X400;
    // 0x80004380: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
    // 0x80004384: b           L_800043AC
    // 0x80004388: nop

        goto L_800043AC;
    // 0x80004388: nop

L_8000438C:
    // 0x8000438C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80004390: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80004394: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x80004398: nop

    // 0x8000439C: ori         $t8, $t2, 0x400
    ctx->r24 = ctx->r10 | 0X400;
    // 0x800043A0: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x800043A4: b           L_800043AC
    // 0x800043A8: nop

        goto L_800043AC;
    // 0x800043A8: nop

L_800043AC:
    // 0x800043AC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800043B0: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x800043B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800043B8: sh          $t7, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r15;
    // 0x800043BC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800043C0: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x800043C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800043C8: sh          $t5, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r13;
    // 0x800043CC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800043D0: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x800043D4: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x800043D8: addiu       $at, $zero, -0x93
    ctx->r1 = ADD32(0, -0X93);
    // 0x800043DC: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x800043E0: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x800043E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800043E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800043EC: sw          $t1, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = ctx->r9;
    // 0x800043F0: b           L_80004400
    // 0x800043F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004400;
    // 0x800043F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800043F8: b           L_80004400
    // 0x800043FC: nop

        goto L_80004400;
    // 0x800043FC: nop

L_80004400:
    // 0x80004400: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80004404: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80004408: jr          $ra
    // 0x8000440C: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x8000440C: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
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
RECOMP_FUNC void func_8006F358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F358: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F35C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F360: nop

    // 0x8006F364: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F368: nop

    // 0x8006F36C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006F370: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F374: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F378: beq         $v0, $zero, L_8006F390
    if (ctx->r2 == 0) {
        // 0x8006F37C: nop
    
            goto L_8006F390;
    }
    // 0x8006F37C: nop

    // 0x8006F380: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F384: nop

    // 0x8006F388: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F38C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006F390:
    // 0x8006F390: jr          $ra
    // 0x8006F394: nop

    return;
    // 0x8006F394: nop

    // 0x8006F398: jr          $ra
    // 0x8006F39C: nop

    return;
    // 0x8006F39C: nop

    // 0x8006F3A0: jr          $ra
    // 0x8006F3A4: nop

    return;
    // 0x8006F3A4: nop

;}
