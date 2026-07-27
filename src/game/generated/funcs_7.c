#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void alSndpDeallocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C97F0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800C97F4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C97F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C97FC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800C9800: sll         $v1, $t7, 2
    ctx->r3 = S32(ctx->r15 << 2);
    // 0x800C9804: subu        $v1, $v1, $t7
    ctx->r3 = SUB32(ctx->r3, ctx->r15);
    // 0x800C9808: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800C980C: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9810: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x800C9814: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9818: bne         $t9, $zero, L_800C9838
    if (ctx->r25 != 0) {
        // 0x800C981C: nop
    
            goto L_800C9838;
    }
    // 0x800C981C: nop

    // 0x800C9820: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x800C9824: lw          $t1, 0x3C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X3C);
    // 0x800C9828: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800C982C: bne         $t7, $t1, L_800C9838
    if (ctx->r15 != ctx->r9) {
        // 0x800C9830: nop
    
            goto L_800C9838;
    }
    // 0x800C9830: nop

    // 0x800C9834: sw          $t2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r10;
L_800C9838:
    // 0x800C9838: jr          $ra
    // 0x800C983C: nop

    return;
    // 0x800C983C: nop

;}
RECOMP_FUNC void func_800681C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800681C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800681C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800681CC: nop

    // 0x800681D0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800681D4: nop

    // 0x800681D8: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800681DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800681E0: jr          $ra
    // 0x800681E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800681E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800681E8: jr          $ra
    // 0x800681EC: nop

    return;
    // 0x800681EC: nop

    // 0x800681F0: jr          $ra
    // 0x800681F4: nop

    return;
    // 0x800681F4: nop

;}
RECOMP_FUNC void func_80016264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016264: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001626C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80016270:
    // 0x80016270: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016274: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80016278: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001627C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80016280: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x80016284: nop

    // 0x80016288: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8001628C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80016290: nop

    // 0x80016294: beq         $t9, $zero, L_8001632C
    if (ctx->r25 == 0) {
        // 0x80016298: nop
    
            goto L_8001632C;
    }
    // 0x80016298: nop

    // 0x8001629C: lw          $t0, 0x1A4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A4);
    // 0x800162A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800162A4: beq         $t0, $at, L_8001632C
    if (ctx->r8 == ctx->r1) {
        // 0x800162A8: nop
    
            goto L_8001632C;
    }
    // 0x800162A8: nop

    // 0x800162AC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800162B0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800162B4: lw          $t2, 0x1A0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A0);
    // 0x800162B8: nop

    // 0x800162BC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800162C0: sw          $t3, 0x1A0($t1)
    MEM_W(0X1A0, ctx->r9) = ctx->r11;
    // 0x800162C4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800162C8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800162CC: lw          $t5, 0x1A4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A4);
    // 0x800162D0: nop

    // 0x800162D4: beq         $t5, $at, L_800162E8
    if (ctx->r13 == ctx->r1) {
        // 0x800162D8: nop
    
            goto L_800162E8;
    }
    // 0x800162D8: nop

    // 0x800162DC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800162E0: bne         $t5, $at, L_8001632C
    if (ctx->r13 != ctx->r1) {
        // 0x800162E4: nop
    
            goto L_8001632C;
    }
    // 0x800162E4: nop

L_800162E8:
    // 0x800162E8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800162EC: nop

    // 0x800162F0: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x800162F4: nop

    // 0x800162F8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800162FC: beq         $t8, $zero, L_8001632C
    if (ctx->r24 == 0) {
        // 0x80016300: nop
    
            goto L_8001632C;
    }
    // 0x80016300: nop

    // 0x80016304: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80016308: nop

    // 0x8001630C: lw          $a0, 0x12C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X12C);
    // 0x80016310: jal         0x800BCCE4
    // 0x80016314: nop

    func_800BCCE4(rdram, ctx);
        goto after_0;
    // 0x80016314: nop

    after_0:
    // 0x80016318: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8001631C: nop

    // 0x80016320: lw          $a0, 0x128($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X128);
    // 0x80016324: jal         0x800BCCE4
    // 0x80016328: nop

    func_800BCCE4(rdram, ctx);
        goto after_1;
    // 0x80016328: nop

    after_1:
L_8001632C:
    // 0x8001632C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80016330: nop

    // 0x80016334: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80016338: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8001633C: bne         $at, $zero, L_80016270
    if (ctx->r1 != 0) {
        // 0x80016340: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_80016270;
    }
    // 0x80016340: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80016344: b           L_8001634C
    // 0x80016348: nop

        goto L_8001634C;
    // 0x80016348: nop

L_8001634C:
    // 0x8001634C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016354: jr          $ra
    // 0x80016358: nop

    return;
    // 0x80016358: nop

;}
RECOMP_FUNC void func_80073A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073A9C: jal         0x80061488
    // 0x80073AA0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073AA0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073AA4: xori        $t6, $v0, 0x5
    ctx->r14 = ctx->r2 ^ 0X5;
    // 0x80073AA8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073AAC: b           L_80073ABC
    // 0x80073AB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073ABC;
    // 0x80073AB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073AB4: b           L_80073ABC
    // 0x80073AB8: nop

        goto L_80073ABC;
    // 0x80073AB8: nop

L_80073ABC:
    // 0x80073ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073AC4: jr          $ra
    // 0x80073AC8: nop

    return;
    // 0x80073AC8: nop

;}
RECOMP_FUNC void alResamplePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0E0C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D0E10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D0E14: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800D0E18: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800D0E1C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800D0E20: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D0E24: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800D0E28: bne         $a2, $zero, L_800D0E38
    if (ctx->r6 != 0) {
        // 0x800D0E2C: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_800D0E38;
    }
    // 0x800D0E2C: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x800D0E30: b           L_800D1004
    // 0x800D0E34: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_800D1004;
    // 0x800D0E34: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_800D0E38:
    // 0x800D0E38: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800D0E3C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800D0E40: beql        $t7, $zero, L_800D0EAC
    if (ctx->r15 == 0) {
        // 0x800D0E44: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_800D0EAC;
    }
    goto skip_0;
    // 0x800D0E44: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x800D0E48: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800D0E4C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800D0E50: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800D0E54: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D0E58: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800D0E5C: jalr        $t9
    // 0x800D0E60: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D0E60: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800D0E64: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x800D0E68: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D0E6C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D0E70: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800D0E74: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800D0E78: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800D0E7C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800D0E80: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800D0E84: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800D0E88: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800D0E8C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800D0E90: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800D0E94: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800D0E98: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D0E9C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800D0EA0: b           L_800D1000
    // 0x800D0EA4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_800D1000;
    // 0x800D0EA4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800D0EA8: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_800D0EAC:
    // 0x800D0EAC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0EB0: ldc1        $f4, 0x2F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X2F8);
    // 0x800D0EB4: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800D0EB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0EBC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800D0EC0: nop

    // 0x800D0EC4: bc1fl       L_800D0EDC
    if (!c1cs) {
        // 0x800D0EC8: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_800D0EDC;
    }
    goto skip_1;
    // 0x800D0EC8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x800D0ECC: lwc1        $f8, 0x300($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X300);
    // 0x800D0ED0: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800D0ED4: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800D0ED8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_800D0EDC:
    // 0x800D0EDC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800D0EE0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D0EE4: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800D0EE8: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800D0EEC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800D0EF0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800D0EF4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800D0EF8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800D0EFC: nop

    // 0x800D0F00: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D0F04: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D0F08: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x800D0F0C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800D0F10: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800D0F14: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800D0F18: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800D0F1C: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800D0F20: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800D0F24: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D0F28: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D0F2C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800D0F30: nop

    // 0x800D0F34: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800D0F38: nop

    // 0x800D0F3C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D0F40: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800D0F44: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800D0F48: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800D0F4C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800D0F50: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800D0F54: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800D0F58: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800D0F5C: jalr        $t9
    // 0x800D0F60: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D0F60: nop

    after_1:
    // 0x800D0F64: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800D0F68: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x800D0F6C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800D0F70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D0F74: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800D0F78: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0F7C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800D0F80: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800D0F84: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D0F88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D0F8C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800D0F90: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D0F94: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800D0F98: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800D0F9C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800D0FA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D0FA4: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800D0FA8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800D0FAC: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D0FB0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D0FB4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800D0FB8: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x800D0FBC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800D0FC0: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800D0FC4: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800D0FC8: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800D0FCC: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800D0FD0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800D0FD4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800D0FD8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800D0FDC: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800D0FE0: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x800D0FE4: jal         0x800C79C0
    // 0x800D0FE8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D0FE8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x800D0FEC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800D0FF0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800D0FF4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800D0FF8: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800D0FFC: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_800D1000:
    // 0x800D1000: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800D1004:
    // 0x800D1004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1008: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D100C: jr          $ra
    // 0x800D1010: nop

    return;
    // 0x800D1010: nop

;}
RECOMP_FUNC void func_80068C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068C78: jal         0x80061488
    // 0x80068C7C: addiu       $a0, $zero, 0x367
    ctx->r4 = ADD32(0, 0X367);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068C7C: addiu       $a0, $zero, 0x367
    ctx->r4 = ADD32(0, 0X367);
    after_0:
    // 0x80068C80: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068C84: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068C88: b           L_80068C98
    // 0x80068C8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068C98;
    // 0x80068C8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068C90: b           L_80068C98
    // 0x80068C94: nop

        goto L_80068C98;
    // 0x80068C94: nop

L_80068C98:
    // 0x80068C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068CA0: jr          $ra
    // 0x80068CA4: nop

    return;
    // 0x80068CA4: nop

;}
RECOMP_FUNC void func_8006CA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CAA0: jal         0x8005F064
    // 0x8006CAA4: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CAA4: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    after_0:
    // 0x8006CAA8: b           L_8006CAB8
    // 0x8006CAAC: nop

        goto L_8006CAB8;
    // 0x8006CAAC: nop

    // 0x8006CAB0: b           L_8006CAB8
    // 0x8006CAB4: nop

        goto L_8006CAB8;
    // 0x8006CAB4: nop

L_8006CAB8:
    // 0x8006CAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CAC0: jr          $ra
    // 0x8006CAC4: nop

    return;
    // 0x8006CAC4: nop

;}
RECOMP_FUNC void func_80066538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006653C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066540: jal         0x80061348
    // 0x80066544: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066544: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x80066548: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006654C: b           L_8006655C
    // 0x80066550: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006655C;
    // 0x80066550: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066554: b           L_8006655C
    // 0x80066558: nop

        goto L_8006655C;
    // 0x80066558: nop

L_8006655C:
    // 0x8006655C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066564: jr          $ra
    // 0x80066568: nop

    return;
    // 0x80066568: nop

;}
RECOMP_FUNC void func_800672C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800672C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800672C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800672CC: jal         0x80061488
    // 0x800672D0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800672D0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800672D4: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800672D8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800672DC: b           L_800672EC
    // 0x800672E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800672EC;
    // 0x800672E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800672E4: b           L_800672EC
    // 0x800672E8: nop

        goto L_800672EC;
    // 0x800672E8: nop

L_800672EC:
    // 0x800672EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800672F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800672F4: jr          $ra
    // 0x800672F8: nop

    return;
    // 0x800672F8: nop

;}
RECOMP_FUNC void func_80077A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077A40: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077A44: nop

    // 0x80077A48: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80077A4C: nop

    // 0x80077A50: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077A54: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077A58: jr          $ra
    // 0x80077A5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077A5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077A60: jr          $ra
    // 0x80077A64: nop

    return;
    // 0x80077A64: nop

    // 0x80077A68: jr          $ra
    // 0x80077A6C: nop

    return;
    // 0x80077A6C: nop

;}
RECOMP_FUNC void func_8003A7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A7F0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8003A7F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003A7F8: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8003A7FC: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8003A800: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x8003A804: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8003A808: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003A80C: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8003A810: nop

    // 0x8003A814: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8003A818: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x8003A81C: nop

    // 0x8003A820: addiu       $t8, $t7, 0x30
    ctx->r24 = ADD32(ctx->r15, 0X30);
    // 0x8003A824: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8003A828: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x8003A82C: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8003A830: nop

    // 0x8003A834: lhu         $s0, 0x2($t9)
    ctx->r16 = MEM_HU(ctx->r25, 0X2);
    // 0x8003A838: nop

    // 0x8003A83C: beq         $s0, $zero, L_8003A870
    if (ctx->r16 == 0) {
        // 0x8003A840: nop
    
            goto L_8003A870;
    }
    // 0x8003A840: nop

    // 0x8003A844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003A848: beq         $s0, $at, L_8003ACE4
    if (ctx->r16 == ctx->r1) {
        // 0x8003A84C: nop
    
            goto L_8003ACE4;
    }
    // 0x8003A84C: nop

    // 0x8003A850: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003A854: beq         $s0, $at, L_8003ADFC
    if (ctx->r16 == ctx->r1) {
        // 0x8003A858: nop
    
            goto L_8003ADFC;
    }
    // 0x8003A858: nop

    // 0x8003A85C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003A860: beq         $s0, $at, L_8003AE54
    if (ctx->r16 == ctx->r1) {
        // 0x8003A864: nop
    
            goto L_8003AE54;
    }
    // 0x8003A864: nop

    // 0x8003A868: b           L_8003AE5C
    // 0x8003A86C: nop

        goto L_8003AE5C;
    // 0x8003A86C: nop

L_8003A870:
    // 0x8003A870: lhu         $t0, 0x8A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X8A);
    // 0x8003A874: nop

    // 0x8003A878: beq         $t0, $zero, L_8003ACDC
    if (ctx->r8 == 0) {
        // 0x8003A87C: nop
    
            goto L_8003ACDC;
    }
    // 0x8003A87C: nop

    // 0x8003A880: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003A884: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x8003A888: nop

    // 0x8003A88C: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003A890: nop

    // 0x8003A894: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x8003A898: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003A89C: lw          $t2, 0x7278($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7278);
    // 0x8003A8A0: nop

    // 0x8003A8A4: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8003A8A8: nop

    // 0x8003A8AC: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8003A8B0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003A8B4: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x8003A8B8: nop

    // 0x8003A8BC: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8003A8C0: nop

    // 0x8003A8C4: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x8003A8C8: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8003A8CC: nop

    // 0x8003A8D0: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003A8D4: nop

    // 0x8003A8D8: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8003A8DC: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8003A8E0: nop

    // 0x8003A8E4: lwc1        $f16, 0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8003A8E8: nop

    // 0x8003A8EC: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x8003A8F0: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8003A8F4: nop

    // 0x8003A8F8: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8003A8FC: nop

    // 0x8003A900: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x8003A904: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8003A908: nop

    // 0x8003A90C: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8003A910: nop

    // 0x8003A914: bne         $t8, $zero, L_8003ABC8
    if (ctx->r24 != 0) {
        // 0x8003A918: nop
    
            goto L_8003ABC8;
    }
    // 0x8003A918: nop

    // 0x8003A91C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8003A920: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003A924: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003A928: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8003A92C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003A930: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003A934: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003A938: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8003A93C: lui         $a3, 0x437A
    ctx->r7 = S32(0X437A << 16);
    // 0x8003A940: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8003A944: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003A948: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8003A94C: jal         0x800C3C80
    // 0x8003A950: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_0;
    // 0x8003A950: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8003A954: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8003A958: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8003A95C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003A960: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003A964: nop

    // 0x8003A968: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8003A96C: nop

    // 0x8003A970: bc1t        L_8003ABC8
    if (c1cs) {
        // 0x8003A974: nop
    
            goto L_8003ABC8;
    }
    // 0x8003A974: nop

    // 0x8003A978: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x8003A97C: addiu       $t9, $zero, 0x5A
    ctx->r25 = ADD32(0, 0X5A);
    // 0x8003A980: sh          $t9, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r25;
    // 0x8003A984: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003A988: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8003A98C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003A990: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003A994: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A998: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8003A99C: nop

    // 0x8003A9A0: bc1f        L_8003ABC8
    if (!c1cs) {
        // 0x8003A9A4: nop
    
            goto L_8003ABC8;
    }
    // 0x8003A9A4: nop

    // 0x8003A9A8: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003A9AC: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8003A9B0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003A9B4: addiu       $t1, $zero, 0x69
    ctx->r9 = ADD32(0, 0X69);
    // 0x8003A9B8: addiu       $t2, $zero, 0x1E3
    ctx->r10 = ADD32(0, 0X1E3);
    // 0x8003A9BC: addiu       $t3, $zero, 0x36
    ctx->r11 = ADD32(0, 0X36);
    // 0x8003A9C0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8003A9C4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8003A9C8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003A9CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003A9D0: jal         0x80033D78
    // 0x8003A9D4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80033D78(rdram, ctx);
        goto after_1;
    // 0x8003A9D4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_1:
    // 0x8003A9D8: sh          $v0, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r2;
    // 0x8003A9DC: lh          $t4, 0x78($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X78);
    // 0x8003A9E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003A9E4: beq         $t4, $at, L_8003ABC8
    if (ctx->r12 == ctx->r1) {
        // 0x8003A9E8: nop
    
            goto L_8003ABC8;
    }
    // 0x8003A9E8: nop

    // 0x8003A9EC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003A9F0: lw          $t5, 0x7214($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7214);
    // 0x8003A9F4: nop

    // 0x8003A9F8: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8003A9FC: sh          $zero, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = 0;
L_8003AA00:
    // 0x8003AA00: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8003AA04: lh          $t7, 0x7A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X7A);
    // 0x8003AA08: nop

    // 0x8003AA0C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003AA10: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8003AA14: nop

    // 0x8003AA18: bne         $t9, $zero, L_8003AA28
    if (ctx->r25 != 0) {
        // 0x8003AA1C: nop
    
            goto L_8003AA28;
    }
    // 0x8003AA1C: nop

    // 0x8003AA20: b           L_8003AA48
    // 0x8003AA24: nop

        goto L_8003AA48;
    // 0x8003AA24: nop

L_8003AA28:
    // 0x8003AA28: lh          $t0, 0x7A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X7A);
    // 0x8003AA2C: nop

    // 0x8003AA30: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8003AA34: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8003AA38: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8003AA3C: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x8003AA40: bne         $at, $zero, L_8003AA00
    if (ctx->r1 != 0) {
        // 0x8003AA44: sh          $t1, 0x7A($sp)
        MEM_H(0X7A, ctx->r29) = ctx->r9;
            goto L_8003AA00;
    }
    // 0x8003AA44: sh          $t1, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r9;
L_8003AA48:
    // 0x8003AA48: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003AA4C: lh          $t6, 0x7A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X7A);
    // 0x8003AA50: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003AA54: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8003AA58: sb          $t4, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r12;
    // 0x8003AA5C: lh          $t9, 0x7A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X7A);
    // 0x8003AA60: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8003AA64: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8003AA68: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8003AA6C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003AA70: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8003AA74: addiu       $t2, $t1, 0xC
    ctx->r10 = ADD32(ctx->r9, 0XC);
    // 0x8003AA78: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8003AA7C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8003AA80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003AA84: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8003AA88: nop

    // 0x8003AA8C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x8003AA90: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x8003AA94: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8003AA98: nop

    // 0x8003AA9C: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x8003AAA0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003AAA4: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8003AAA8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003AAAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003AAB0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003AAB4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8003AAB8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003AABC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003AAC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003AAC4: nop

    // 0x8003AAC8: div.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x8003AACC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003AAD0: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8003AAD4: jal         0x800C1850
    // 0x8003AAD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_2;
    // 0x8003AAD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8003AADC: jal         0x800C4240
    // 0x8003AAE0: nop

    guRandom(rdram, ctx);
        goto after_3;
    // 0x8003AAE0: nop

    after_3:
    // 0x8003AAE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003AAE8: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8003AAEC: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x8003AAF0: mfhi        $t4
    ctx->r12 = hi;
    // 0x8003AAF4: addiu       $t7, $t4, -0x1E
    ctx->r15 = ADD32(ctx->r12, -0X1E);
    // 0x8003AAF8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8003AAFC: jal         0x800C23E8
    // 0x8003AB00: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8003AB00: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_4:
    // 0x8003AB04: jal         0x800C4240
    // 0x8003AB08: nop

    guRandom(rdram, ctx);
        goto after_5;
    // 0x8003AB08: nop

    after_5:
    // 0x8003AB0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003AB10: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8003AB14: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x8003AB18: mfhi        $t9
    ctx->r25 = hi;
    // 0x8003AB1C: addiu       $t8, $t9, -0x1E
    ctx->r24 = ADD32(ctx->r25, -0X1E);
    // 0x8003AB20: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8003AB24: jal         0x800C25B8
    // 0x8003AB28: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    MtxUtil_RotateY(rdram, ctx);
        goto after_6;
    // 0x8003AB28: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_6:
    // 0x8003AB2C: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003AB30: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003AB34: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003AB38: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8003AB3C: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003AB40: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8003AB44: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003AB48: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003AB4C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003AB50: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8003AB54: mul.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8003AB58: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8003AB5C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8003AB60: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003AB64: jal         0x800C2304
    // 0x8003AB68: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_7;
    // 0x8003AB68: nop

    after_7:
    // 0x8003AB6C: jal         0x800B1844
    // 0x8003AB70: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    func_800B1844(rdram, ctx);
        goto after_8;
    // 0x8003AB70: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_8:
    // 0x8003AB74: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003AB78: nop

    // 0x8003AB7C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003AB80: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x8003AB84: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x8003AB88: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8003AB8C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8003AB90: nop

    // 0x8003AB94: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8003AB98: addiu       $t5, $sp, 0x60
    ctx->r13 = ADD32(ctx->r29, 0X60);
    // 0x8003AB9C: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8003ABA0: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8003ABA4: nop

    // 0x8003ABA8: swc1        $f6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f6.u32l;
    // 0x8003ABAC: addiu       $t4, $sp, 0x60
    ctx->r12 = ADD32(ctx->r29, 0X60);
    // 0x8003ABB0: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8003ABB4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8003ABB8: nop

    // 0x8003ABBC: swc1        $f10, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f10.u32l;
    // 0x8003ABC0: jal         0x800B9000
    // 0x8003ABC4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_800B9000(rdram, ctx);
        goto after_9;
    // 0x8003ABC4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_9:
L_8003ABC8:
    // 0x8003ABC8: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003ABCC: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8003ABD0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003ABD4: jal         0x80039C5C
    // 0x8003ABD8: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    func_80039C5C(rdram, ctx);
        goto after_10;
    // 0x8003ABD8: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    after_10:
    // 0x8003ABDC: beq         $v0, $zero, L_8003ACDC
    if (ctx->r2 == 0) {
        // 0x8003ABE0: nop
    
            goto L_8003ACDC;
    }
    // 0x8003ABE0: nop

    // 0x8003ABE4: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x8003ABE8: nop

    // 0x8003ABEC: lhu         $t8, 0x6($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X6);
    // 0x8003ABF0: nop

    // 0x8003ABF4: bne         $t8, $zero, L_8003ACA4
    if (ctx->r24 != 0) {
        // 0x8003ABF8: nop
    
            goto L_8003ACA4;
    }
    // 0x8003ABF8: nop

    // 0x8003ABFC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8003AC00: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8003AC04: nop

    // 0x8003AC08: addiu       $t1, $t0, 0x48
    ctx->r9 = ADD32(ctx->r8, 0X48);
    // 0x8003AC0C: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8003AC10: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8003AC14: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x8003AC18: lh          $s0, 0x0($t2)
    ctx->r16 = MEM_H(ctx->r10, 0X0);
    // 0x8003AC1C: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x8003AC20: slt         $t3, $at, $s0
    ctx->r11 = SIGNED(ctx->r1) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8003AC24: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x8003AC28: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8003AC2C: beq         $s0, $zero, L_8003AC40
    if (ctx->r16 == 0) {
        // 0x8003AC30: sh          $t6, 0x0($t2)
        MEM_H(0X0, ctx->r10) = ctx->r14;
            goto L_8003AC40;
    }
    // 0x8003AC30: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
    // 0x8003AC34: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8003AC38: addiu       $t4, $zero, 0x3E8
    ctx->r12 = ADD32(0, 0X3E8);
    // 0x8003AC3C: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
L_8003AC40:
    // 0x8003AC40: jal         0x800B9000
    // 0x8003AC44: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_800B9000(rdram, ctx);
        goto after_11;
    // 0x8003AC44: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_11:
    // 0x8003AC48: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003AC4C: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8003AC50: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003AC54: addiu       $t9, $zero, 0x69
    ctx->r25 = ADD32(0, 0X69);
    // 0x8003AC58: addiu       $t8, $zero, 0x1E1
    ctx->r24 = ADD32(0, 0X1E1);
    // 0x8003AC5C: addiu       $t0, $zero, 0x36
    ctx->r8 = ADD32(0, 0X36);
    // 0x8003AC60: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8003AC64: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003AC68: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003AC6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003AC70: jal         0x80033D78
    // 0x8003AC74: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80033D78(rdram, ctx);
        goto after_12;
    // 0x8003AC74: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_12:
    // 0x8003AC78: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x8003AC7C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8003AC80: sh          $t1, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r9;
    // 0x8003AC84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003AC88: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x8003AC8C: nop

    // 0x8003AC90: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x8003AC94: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8003AC98: sh          $t6, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r14;
    // 0x8003AC9C: b           L_8003AE5C
    // 0x8003ACA0: nop

        goto L_8003AE5C;
    // 0x8003ACA0: nop

L_8003ACA4:
    // 0x8003ACA4: jal         0x800B9000
    // 0x8003ACA8: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    func_800B9000(rdram, ctx);
        goto after_13;
    // 0x8003ACA8: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    after_13:
    // 0x8003ACAC: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003ACB0: nop

    // 0x8003ACB4: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x8003ACB8: nop

    // 0x8003ACBC: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x8003ACC0: sh          $t7, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r15;
    // 0x8003ACC4: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8003ACC8: nop

    // 0x8003ACCC: lhu         $t8, 0x2($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X2);
    // 0x8003ACD0: nop

    // 0x8003ACD4: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8003ACD8: sh          $t0, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r8;
L_8003ACDC:
    // 0x8003ACDC: b           L_8003AE5C
    // 0x8003ACE0: nop

        goto L_8003AE5C;
    // 0x8003ACE0: nop

L_8003ACE4:
    // 0x8003ACE4: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x8003ACE8: nop

    // 0x8003ACEC: lhu         $t3, 0x4($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X4);
    // 0x8003ACF0: nop

    // 0x8003ACF4: bgez        $t3, L_8003AD08
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8003ACF8: andi        $t5, $t3, 0x1
        ctx->r13 = ctx->r11 & 0X1;
            goto L_8003AD08;
    }
    // 0x8003ACF8: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x8003ACFC: beq         $t5, $zero, L_8003AD08
    if (ctx->r13 == 0) {
        // 0x8003AD00: nop
    
            goto L_8003AD08;
    }
    // 0x8003AD00: nop

    // 0x8003AD04: addiu       $t5, $t5, -0x2
    ctx->r13 = ADD32(ctx->r13, -0X2);
L_8003AD08:
    // 0x8003AD08: beq         $t5, $zero, L_8003AD28
    if (ctx->r13 == 0) {
        // 0x8003AD0C: nop
    
            goto L_8003AD28;
    }
    // 0x8003AD0C: nop

    // 0x8003AD10: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8003AD14: sb          $t6, 0x7F($sp)
    MEM_B(0X7F, ctx->r29) = ctx->r14;
    // 0x8003AD18: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x8003AD1C: sb          $t4, 0x7E($sp)
    MEM_B(0X7E, ctx->r29) = ctx->r12;
    // 0x8003AD20: b           L_8003AD34
    // 0x8003AD24: sb          $zero, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = 0;
        goto L_8003AD34;
    // 0x8003AD24: sb          $zero, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = 0;
L_8003AD28:
    // 0x8003AD28: sb          $zero, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = 0;
    // 0x8003AD2C: sb          $zero, 0x7E($sp)
    MEM_B(0X7E, ctx->r29) = 0;
    // 0x8003AD30: sb          $zero, 0x7F($sp)
    MEM_B(0X7F, ctx->r29) = 0;
L_8003AD34:
    // 0x8003AD34: lbu         $t7, 0x7F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X7F);
    // 0x8003AD38: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8003AD3C: nop

    // 0x8003AD40: sh          $t7, 0xCC($t2)
    MEM_H(0XCC, ctx->r10) = ctx->r15;
    // 0x8003AD44: lbu         $t8, 0x7E($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X7E);
    // 0x8003AD48: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8003AD4C: nop

    // 0x8003AD50: sh          $t8, 0xCE($t0)
    MEM_H(0XCE, ctx->r8) = ctx->r24;
    // 0x8003AD54: lbu         $t9, 0x7D($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7D);
    // 0x8003AD58: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003AD5C: nop

    // 0x8003AD60: sh          $t9, 0xD0($t1)
    MEM_H(0XD0, ctx->r9) = ctx->r25;
    // 0x8003AD64: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x8003AD68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003AD6C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003AD70: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8003AD74: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8003AD78: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003AD7C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003AD80: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8003AD84: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x8003AD88: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003AD8C: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003AD90: nop

    // 0x8003AD94: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8003AD98: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8003AD9C: nop

    // 0x8003ADA0: bc1f        L_8003ADF4
    if (!c1cs) {
        // 0x8003ADA4: nop
    
            goto L_8003ADF4;
    }
    // 0x8003ADA4: nop

    // 0x8003ADA8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003ADAC: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8003ADB0: nop

    // 0x8003ADB4: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8003ADB8: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x8003ADBC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8003ADC0: lhu         $s0, 0x4($t4)
    ctx->r16 = MEM_HU(ctx->r12, 0X4);
    // 0x8003ADC4: lhu         $t2, 0x4($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X4);
    // 0x8003ADC8: slt         $t7, $at, $s0
    ctx->r15 = SIGNED(ctx->r1) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8003ADCC: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8003ADD0: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8003ADD4: beq         $s0, $zero, L_8003ADF4
    if (ctx->r16 == 0) {
        // 0x8003ADD8: sh          $t8, 0x4($t4)
        MEM_H(0X4, ctx->r12) = ctx->r24;
            goto L_8003ADF4;
    }
    // 0x8003ADD8: sh          $t8, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r24;
    // 0x8003ADDC: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x8003ADE0: nop

    // 0x8003ADE4: sh          $zero, 0x4($t0)
    MEM_H(0X4, ctx->r8) = 0;
    // 0x8003ADE8: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8003ADEC: nop

    // 0x8003ADF0: sh          $zero, 0x2($t9)
    MEM_H(0X2, ctx->r25) = 0;
L_8003ADF4:
    // 0x8003ADF4: b           L_8003AE5C
    // 0x8003ADF8: nop

        goto L_8003AE5C;
    // 0x8003ADF8: nop

L_8003ADFC:
    // 0x8003ADFC: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x8003AE00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003AE04: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003AE08: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003AE0C: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x8003AE10: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003AE14: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003AE18: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x8003AE1C: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x8003AE20: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003AE24: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8003AE28: nop

    // 0x8003AE2C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8003AE30: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8003AE34: nop

    // 0x8003AE38: bc1f        L_8003AE4C
    if (!c1cs) {
        // 0x8003AE3C: nop
    
            goto L_8003AE4C;
    }
    // 0x8003AE3C: nop

    // 0x8003AE40: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8003AE44: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003AE48: sh          $t5, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r13;
L_8003AE4C:
    // 0x8003AE4C: b           L_8003AE5C
    // 0x8003AE50: nop

        goto L_8003AE5C;
    // 0x8003AE50: nop

L_8003AE54:
    // 0x8003AE54: b           L_8003AE5C
    // 0x8003AE58: nop

        goto L_8003AE5C;
    // 0x8003AE58: nop

L_8003AE5C:
    // 0x8003AE5C: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8003AE60: nop

    // 0x8003AE64: lhu         $t2, 0x8($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X8);
    // 0x8003AE68: nop

    // 0x8003AE6C: beq         $t2, $zero, L_8003AE8C
    if (ctx->r10 == 0) {
        // 0x8003AE70: nop
    
            goto L_8003AE8C;
    }
    // 0x8003AE70: nop

    // 0x8003AE74: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8003AE78: nop

    // 0x8003AE7C: lhu         $t4, 0x8($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X8);
    // 0x8003AE80: nop

    // 0x8003AE84: addiu       $t0, $t4, -0x1
    ctx->r8 = ADD32(ctx->r12, -0X1);
    // 0x8003AE88: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
L_8003AE8C:
    // 0x8003AE8C: lh          $v0, 0x76($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X76);
    // 0x8003AE90: b           L_8003AEA0
    // 0x8003AE94: nop

        goto L_8003AEA0;
    // 0x8003AE94: nop

    // 0x8003AE98: b           L_8003AEA0
    // 0x8003AE9C: nop

        goto L_8003AEA0;
    // 0x8003AE9C: nop

L_8003AEA0:
    // 0x8003AEA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AEA4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003AEA8: jr          $ra
    // 0x8003AEAC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8003AEAC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8006C978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C97C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C980: jal         0x8005F064
    // 0x8006C984: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C984: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x8006C988: b           L_8006C998
    // 0x8006C98C: nop

        goto L_8006C998;
    // 0x8006C98C: nop

    // 0x8006C990: b           L_8006C998
    // 0x8006C994: nop

        goto L_8006C998;
    // 0x8006C994: nop

L_8006C998:
    // 0x8006C998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C99C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C9A0: jr          $ra
    // 0x8006C9A4: nop

    return;
    // 0x8006C9A4: nop

;}
RECOMP_FUNC void func_800C3650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3654: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3658: lwc1        $f7, -0x170($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X170);
    // 0x800C365C: lwc1        $f6, -0x16C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X16C);
    // 0x800C3660: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C3664: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C3668: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800C366C: swc1        $f10, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f10.u32l;
    // 0x800C3670: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C3674: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800C3678: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C367C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C3680: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x800C3684: nop

    // 0x800C3688: bc1f        L_800C36A4
    if (!c1cs) {
        // 0x800C368C: nop
    
            goto L_800C36A4;
    }
    // 0x800C368C: nop

    // 0x800C3690: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C3694: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3698: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C369C: b           L_800C36BC
    // 0x800C36A0: add.d       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f14.d = ctx->f18.d + ctx->f6.d;
        goto L_800C36BC;
    // 0x800C36A0: add.d       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f14.d = ctx->f18.d + ctx->f6.d;
L_800C36A4:
    // 0x800C36A4: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C36A8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C36AC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C36B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C36B4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800C36B8: sub.d       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f10.d - ctx->f16.d;
L_800C36BC:
    // 0x800C36BC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C36C0: nop

    // 0x800C36C4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800C36C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C36CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C36D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C36D4: cvt.w.d     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = CVT_W_D(ctx->f14.d);
    // 0x800C36D8: lwc1        $f11, -0x168($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X168);
    // 0x800C36DC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800C36E0: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800C36E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C36E8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800C36EC: lwc1        $f10, -0x164($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X164);
    // 0x800C36F0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C36F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C36F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C36FC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800C3700: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C3704: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x800C3708: lwc1        $f4, -0x15C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X15C);
    // 0x800C370C: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x800C3710: lwc1        $f5, -0x160($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X160);
    // 0x800C3714: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C3718: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800C371C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C3720: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C3724: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800C3728: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C372C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x800C3730: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800C3734: mul.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800C3738: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C373C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C3740: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3744: sub.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f18.d - ctx->f16.d;
    // 0x800C3748: nop

    // 0x800C374C: div.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x800C3750: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3754: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3758: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C375C: sub.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f4.d - ctx->f8.d;
    // 0x800C3760: nop

    // 0x800C3764: div.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x800C3768: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800C376C: lwc1        $f18, -0x154($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X154);
    // 0x800C3770: lwc1        $f19, -0x158($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X158);
    // 0x800C3774: sub.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f6.d - ctx->f16.d;
    // 0x800C3778: nop

    // 0x800C377C: div.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x800C3780: add.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f10.d + ctx->f18.d;
    // 0x800C3784: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x800C3788: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800C378C: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800C3790: nop

    // 0x800C3794: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800C3798: beq         $t9, $zero, L_800C37EC
    if (ctx->r25 == 0) {
        // 0x800C379C: nop
    
            goto L_800C37EC;
    }
    // 0x800C379C: nop

    // 0x800C37A0: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C37A4: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800C37A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C37AC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800C37B0: c.eq.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d == ctx->f10.d;
    // 0x800C37B4: nop

    // 0x800C37B8: bc1t        L_800C37D4
    if (c1cs) {
        // 0x800C37BC: nop
    
            goto L_800C37D4;
    }
    // 0x800C37BC: nop

    // 0x800C37C0: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800C37C4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C37C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C37CC: b           L_800C37E4
    // 0x800C37D0: div.d       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f14.d = DIV_D(ctx->f18.d, ctx->f4.d);
        goto L_800C37E4;
    // 0x800C37D0: div.d       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f14.d = DIV_D(ctx->f18.d, ctx->f4.d);
L_800C37D4:
    // 0x800C37D4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800C37D8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800C37DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C37E0: nop

L_800C37E4:
    // 0x800C37E4: b           L_800C3800
    // 0x800C37E8: cvt.s.d     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f0.fl = CVT_S_D(ctx->f14.d);
        goto L_800C3800;
    // 0x800C37E8: cvt.s.d     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f0.fl = CVT_S_D(ctx->f14.d);
L_800C37EC:
    // 0x800C37EC: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C37F0: b           L_800C3800
    // 0x800C37F4: nop

        goto L_800C3800;
    // 0x800C37F4: nop

    // 0x800C37F8: b           L_800C3800
    // 0x800C37FC: nop

        goto L_800C3800;
    // 0x800C37FC: nop

L_800C3800:
    // 0x800C3800: jr          $ra
    // 0x800C3804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C3804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80070AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070AF8: jal         0x80061348
    // 0x80070AFC: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070AFC: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80070B00: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070B04: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070B08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070B0C: beq         $v0, $zero, L_80070B60
    if (ctx->r2 == 0) {
        // 0x80070B10: nop
    
            goto L_80070B60;
    }
    // 0x80070B10: nop

    // 0x80070B14: jal         0x80061348
    // 0x80070B18: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070B18: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_1:
    // 0x80070B1C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070B20: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070B24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070B28: beq         $v0, $zero, L_80070B60
    if (ctx->r2 == 0) {
        // 0x80070B2C: nop
    
            goto L_80070B60;
    }
    // 0x80070B2C: nop

    // 0x80070B30: jal         0x80061348
    // 0x80070B34: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070B34: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070B38: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070B3C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070B40: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070B44: beq         $v0, $zero, L_80070B60
    if (ctx->r2 == 0) {
        // 0x80070B48: nop
    
            goto L_80070B60;
    }
    // 0x80070B48: nop

    // 0x80070B4C: jal         0x80061348
    // 0x80070B50: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070B50: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070B54: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070B58: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070B5C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070B60:
    // 0x80070B60: b           L_80070B70
    // 0x80070B64: nop

        goto L_80070B70;
    // 0x80070B64: nop

    // 0x80070B68: b           L_80070B70
    // 0x80070B6C: nop

        goto L_80070B70;
    // 0x80070B6C: nop

L_80070B70:
    // 0x80070B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070B78: jr          $ra
    // 0x80070B7C: nop

    return;
    // 0x80070B7C: nop

;}
RECOMP_FUNC void ContPak_GetDeleteFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE7FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE800: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE804: nop

    // 0x800AE808: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x800AE80C: beq         $t7, $zero, L_800AE81C
    if (ctx->r15 == 0) {
        // 0x800AE810: nop
    
            goto L_800AE81C;
    }
    // 0x800AE810: nop

    // 0x800AE814: jr          $ra
    // 0x800AE818: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE818: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE81C:
    // 0x800AE81C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE820: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE824: nop

    // 0x800AE828: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x800AE82C: beq         $t9, $zero, L_800AE83C
    if (ctx->r25 == 0) {
        // 0x800AE830: nop
    
            goto L_800AE83C;
    }
    // 0x800AE830: nop

    // 0x800AE834: jr          $ra
    // 0x800AE838: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE838: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE83C:
    // 0x800AE83C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE840: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AE844: nop

    // 0x800AE848: beq         $t0, $zero, L_800AE868
    if (ctx->r8 == 0) {
        // 0x800AE84C: nop
    
            goto L_800AE868;
    }
    // 0x800AE84C: nop

    // 0x800AE850: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AE854: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AE858: nop

    // 0x800AE85C: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AE860: jr          $ra
    // 0x800AE864: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AE864: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AE868:
    // 0x800AE868: jr          $ra
    // 0x800AE86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE870: jr          $ra
    // 0x800AE874: nop

    return;
    // 0x800AE874: nop

    // 0x800AE878: jr          $ra
    // 0x800AE87C: nop

    return;
    // 0x800AE87C: nop

;}
RECOMP_FUNC void func_8001F104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F104: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001F108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F10C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001F110: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001F114: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001F118: nop

    // 0x8001F11C: bltz        $t6, L_8001F350
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001F120: nop
    
            goto L_8001F350;
    }
    // 0x8001F120: nop

    // 0x8001F124: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001F128: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001F12C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F130: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001F134: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001F138: nop

    // 0x8001F13C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001F140: beq         $t0, $zero, L_8001F15C
    if (ctx->r8 == 0) {
        // 0x8001F144: nop
    
            goto L_8001F15C;
    }
    // 0x8001F144: nop

    // 0x8001F148: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F14C: lw          $t1, 0x15D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X15D4);
    // 0x8001F150: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F154: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001F158: sw          $t2, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r10;
L_8001F15C:
    // 0x8001F15C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001F160: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001F164: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F168: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001F16C: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001F170: nop

    // 0x8001F174: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001F178: beq         $t6, $zero, L_8001F194
    if (ctx->r14 == 0) {
        // 0x8001F17C: nop
    
            goto L_8001F194;
    }
    // 0x8001F17C: nop

    // 0x8001F180: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001F184: lw          $t7, 0x15D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X15D4);
    // 0x8001F188: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F18C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001F190: sw          $t8, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r24;
L_8001F194:
    // 0x8001F194: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001F198: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001F19C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F1A0: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001F1A4: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001F1A8: nop

    // 0x8001F1AC: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001F1B0: beq         $t2, $zero, L_8001F1CC
    if (ctx->r10 == 0) {
        // 0x8001F1B4: nop
    
            goto L_8001F1CC;
    }
    // 0x8001F1B4: nop

    // 0x8001F1B8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F1BC: lw          $t3, 0x15D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X15D4);
    // 0x8001F1C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F1C4: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x8001F1C8: sw          $t4, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r12;
L_8001F1CC:
    // 0x8001F1CC: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001F1D0: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001F1D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001F1D8: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001F1DC: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001F1E0: nop

    // 0x8001F1E4: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001F1E8: beq         $t8, $zero, L_8001F204
    if (ctx->r24 == 0) {
        // 0x8001F1EC: nop
    
            goto L_8001F204;
    }
    // 0x8001F1EC: nop

    // 0x8001F1F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F1F4: lw          $t9, 0x15D4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X15D4);
    // 0x8001F1F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F1FC: addiu       $t0, $t9, -0xA
    ctx->r8 = ADD32(ctx->r25, -0XA);
    // 0x8001F200: sw          $t0, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r8;
L_8001F204:
    // 0x8001F204: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001F208: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001F20C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F210: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001F214: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001F218: nop

    // 0x8001F21C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001F220: beq         $t4, $zero, L_8001F23C
    if (ctx->r12 == 0) {
        // 0x8001F224: nop
    
            goto L_8001F23C;
    }
    // 0x8001F224: nop

    // 0x8001F228: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F22C: lw          $t5, 0x15D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X15D4);
    // 0x8001F230: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F234: addiu       $t6, $t5, 0x64
    ctx->r14 = ADD32(ctx->r13, 0X64);
    // 0x8001F238: sw          $t6, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r14;
L_8001F23C:
    // 0x8001F23C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001F240: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001F244: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F248: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001F24C: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001F250: nop

    // 0x8001F254: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001F258: beq         $t0, $zero, L_8001F274
    if (ctx->r8 == 0) {
        // 0x8001F25C: nop
    
            goto L_8001F274;
    }
    // 0x8001F25C: nop

    // 0x8001F260: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F264: lw          $t1, 0x15D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X15D4);
    // 0x8001F268: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F26C: addiu       $t2, $t1, -0x64
    ctx->r10 = ADD32(ctx->r9, -0X64);
    // 0x8001F270: sw          $t2, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r10;
L_8001F274:
    // 0x8001F274: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001F278: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001F27C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F280: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x8001F284: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001F288: nop

    // 0x8001F28C: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001F290: beq         $t6, $zero, L_8001F2AC
    if (ctx->r14 == 0) {
        // 0x8001F294: nop
    
            goto L_8001F2AC;
    }
    // 0x8001F294: nop

    // 0x8001F298: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8001F29C: lw          $t7, 0x70E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E8);
    // 0x8001F2A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001F2A4: addiu       $t8, $t7, 0x1388
    ctx->r24 = ADD32(ctx->r15, 0X1388);
    // 0x8001F2A8: sw          $t8, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r24;
L_8001F2AC:
    // 0x8001F2AC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001F2B0: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001F2B4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F2B8: lhu         $t1, 0xEEC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XEEC);
    // 0x8001F2BC: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001F2C0: nop

    // 0x8001F2C4: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001F2C8: beq         $t2, $zero, L_8001F2E4
    if (ctx->r10 == 0) {
        // 0x8001F2CC: nop
    
            goto L_8001F2E4;
    }
    // 0x8001F2CC: nop

    // 0x8001F2D0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001F2D4: lw          $t3, 0x70E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70E8);
    // 0x8001F2D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001F2DC: addiu       $t4, $t3, 0x1388
    ctx->r12 = ADD32(ctx->r11, 0X1388);
    // 0x8001F2E0: sw          $t4, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r12;
L_8001F2E4:
    // 0x8001F2E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F2E8: lw          $t5, 0x15D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X15D4);
    // 0x8001F2EC: nop

    // 0x8001F2F0: bgez        $t5, L_8001F300
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8001F2F4: nop
    
            goto L_8001F300;
    }
    // 0x8001F2F4: nop

    // 0x8001F2F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F2FC: sw          $zero, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = 0;
L_8001F300:
    // 0x8001F300: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001F304: lw          $t6, 0x15D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X15D4);
    // 0x8001F308: nop

    // 0x8001F30C: slti        $at, $t6, 0x1388
    ctx->r1 = SIGNED(ctx->r14) < 0X1388 ? 1 : 0;
    // 0x8001F310: bne         $at, $zero, L_8001F324
    if (ctx->r1 != 0) {
        // 0x8001F314: nop
    
            goto L_8001F324;
    }
    // 0x8001F314: nop

    // 0x8001F318: addiu       $t7, $zero, 0x1387
    ctx->r15 = ADD32(0, 0X1387);
    // 0x8001F31C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F320: sw          $t7, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r15;
L_8001F324:
    // 0x8001F324: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001F328: lw          $t8, 0x15D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X15D4);
    // 0x8001F32C: nop

    // 0x8001F330: beq         $t8, $zero, L_8001F350
    if (ctx->r24 == 0) {
        // 0x8001F334: nop
    
            goto L_8001F350;
    }
    // 0x8001F334: nop

    // 0x8001F338: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F33C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8001F340: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x8001F344: lw          $t9, 0x15D4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X15D4);
    // 0x8001F348: nop

    // 0x8001F34C: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_8001F350:
    // 0x8001F350: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8001F354: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8001F358: lw          $a2, 0x70E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X70E8);
    // 0x8001F35C: lw          $a1, 0x15D4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X15D4);
    // 0x8001F360: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F364: jal         0x8008ECE4
    // 0x8001F368: addiu       $a0, $a0, -0x24A8
    ctx->r4 = ADD32(ctx->r4, -0X24A8);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001F368: addiu       $a0, $a0, -0x24A8
    ctx->r4 = ADD32(ctx->r4, -0X24A8);
    after_0:
    // 0x8001F36C: b           L_8001F37C
    // 0x8001F370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F37C;
    // 0x8001F370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F374: b           L_8001F37C
    // 0x8001F378: nop

        goto L_8001F37C;
    // 0x8001F378: nop

L_8001F37C:
    // 0x8001F37C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001F384: jr          $ra
    // 0x8001F388: nop

    return;
    // 0x8001F388: nop

;}
RECOMP_FUNC void func_8005E19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E19C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005E1A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005E1A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E1A8: sw          $zero, 0xE70($at)
    MEM_W(0XE70, ctx->r1) = 0;
    // 0x8005E1AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005E1B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8005E1B4:
    // 0x8005E1B4: jal         0x8005E908
    // 0x8005E1B8: nop

    func_8005E908(rdram, ctx);
        goto after_0;
    // 0x8005E1B8: nop

    after_0:
    // 0x8005E1BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005E1C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E1C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005E1C8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8005E1CC: sw          $v0, 0xE80($at)
    MEM_W(0XE80, ctx->r1) = ctx->r2;
    // 0x8005E1D0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005E1D4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E1D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005E1DC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8005E1E0: lw          $t1, 0xE80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE80);
    // 0x8005E1E4: nop

    // 0x8005E1E8: sb          $t9, 0x7E($t1)
    MEM_B(0X7E, ctx->r9) = ctx->r25;
    // 0x8005E1EC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005E1F0: nop

    // 0x8005E1F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005E1F8: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8005E1FC: bne         $at, $zero, L_8005E1B4
    if (ctx->r1 != 0) {
        // 0x8005E200: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8005E1B4;
    }
    // 0x8005E200: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8005E204: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005E208: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x8005E20C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005E210: bne         $t4, $at, L_8005E2EC
    if (ctx->r12 != ctx->r1) {
        // 0x8005E214: nop
    
            goto L_8005E2EC;
    }
    // 0x8005E214: nop

    // 0x8005E218: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8005E21C: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x8005E220: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8005E224: bne         $t5, $at, L_8005E2EC
    if (ctx->r13 != ctx->r1) {
        // 0x8005E228: nop
    
            goto L_8005E2EC;
    }
    // 0x8005E228: nop

    // 0x8005E22C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E230: addiu       $t7, $t7, 0x1280
    ctx->r15 = ADD32(ctx->r15, 0X1280);
    // 0x8005E234: addiu       $t6, $zero, 0x258
    ctx->r14 = ADD32(0, 0X258);
    // 0x8005E238: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8005E23C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E240: addiu       $t0, $t0, 0x1280
    ctx->r8 = ADD32(ctx->r8, 0X1280);
    // 0x8005E244: addiu       $t8, $zero, 0x258
    ctx->r24 = ADD32(0, 0X258);
    // 0x8005E248: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
    // 0x8005E24C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E250: addiu       $t1, $t1, 0x1280
    ctx->r9 = ADD32(ctx->r9, 0X1280);
    // 0x8005E254: addiu       $t9, $zero, 0x258
    ctx->r25 = ADD32(0, 0X258);
    // 0x8005E258: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
    // 0x8005E25C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005E260: addiu       $t3, $t3, 0x1280
    ctx->r11 = ADD32(ctx->r11, 0X1280);
    // 0x8005E264: addiu       $t2, $zero, 0x258
    ctx->r10 = ADD32(0, 0X258);
    // 0x8005E268: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
    // 0x8005E26C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005E270: addiu       $t5, $t5, 0x1280
    ctx->r13 = ADD32(ctx->r13, 0X1280);
    // 0x8005E274: addiu       $t4, $zero, 0x258
    ctx->r12 = ADD32(0, 0X258);
    // 0x8005E278: sh          $t4, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r12;
    // 0x8005E27C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E280: addiu       $t7, $t7, 0x1280
    ctx->r15 = ADD32(ctx->r15, 0X1280);
    // 0x8005E284: addiu       $t6, $zero, 0x258
    ctx->r14 = ADD32(0, 0X258);
    // 0x8005E288: sh          $t6, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r14;
    // 0x8005E28C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E290: addiu       $t0, $t0, 0x1290
    ctx->r8 = ADD32(ctx->r8, 0X1290);
    // 0x8005E294: addiu       $t8, $zero, 0x3E7
    ctx->r24 = ADD32(0, 0X3E7);
    // 0x8005E298: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8005E29C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E2A0: addiu       $t1, $t1, 0x1290
    ctx->r9 = ADD32(ctx->r9, 0X1290);
    // 0x8005E2A4: addiu       $t9, $zero, 0x384
    ctx->r25 = ADD32(0, 0X384);
    // 0x8005E2A8: sh          $t9, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r25;
    // 0x8005E2AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005E2B0: addiu       $t3, $t3, 0x1290
    ctx->r11 = ADD32(ctx->r11, 0X1290);
    // 0x8005E2B4: addiu       $t2, $zero, 0x5DC
    ctx->r10 = ADD32(0, 0X5DC);
    // 0x8005E2B8: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x8005E2BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005E2C0: addiu       $t5, $t5, 0x1290
    ctx->r13 = ADD32(ctx->r13, 0X1290);
    // 0x8005E2C4: addiu       $t4, $zero, 0x384
    ctx->r12 = ADD32(0, 0X384);
    // 0x8005E2C8: sh          $t4, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r12;
    // 0x8005E2CC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E2D0: addiu       $t7, $t7, 0x1290
    ctx->r15 = ADD32(ctx->r15, 0X1290);
    // 0x8005E2D4: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x8005E2D8: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x8005E2DC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E2E0: addiu       $t0, $t0, 0x1290
    ctx->r8 = ADD32(ctx->r8, 0X1290);
    // 0x8005E2E4: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x8005E2E8: sh          $t8, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r24;
L_8005E2EC:
    // 0x8005E2EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E2F0: addiu       $t9, $t9, 0xE80
    ctx->r25 = ADD32(ctx->r25, 0XE80);
    // 0x8005E2F4: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8005E2F8: nop

    // 0x8005E2FC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8005E300: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E304: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8005E308: nop

    // 0x8005E30C: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x8005E310: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005E314: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8005E318: nop

    // 0x8005E31C: swc1        $f6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f6.u32l;
    // 0x8005E320: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005E324: addiu       $t4, $zero, 0x3E
    ctx->r12 = ADD32(0, 0X3E);
    // 0x8005E328: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x8005E32C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005E330: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x8005E334: sh          $t6, 0x7C($t7)
    MEM_H(0X7C, ctx->r15) = ctx->r14;
    // 0x8005E338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005E33C: jal         0x8005EC54
    // 0x8005E340: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_8005EC54(rdram, ctx);
        goto after_1;
    // 0x8005E340: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_1:
    // 0x8005E344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005E348: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8005E34C: addiu       $a2, $zero, 0x19A
    ctx->r6 = ADD32(0, 0X19A);
    // 0x8005E350: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    // 0x8005E354: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E358: jal         0x8004F3E8
    // 0x8005E35C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004F3E8(rdram, ctx);
        goto after_2;
    // 0x8005E35C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8005E360: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005E364: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E368: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005E36C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005E370: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8005E374: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x8005E378: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8005E37C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005E380: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E384: addiu       $t9, $t9, 0xE80
    ctx->r25 = ADD32(ctx->r25, 0XE80);
    // 0x8005E388: lw          $t4, 0x1C($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X1C);
    // 0x8005E38C: nop

    // 0x8005E390: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8005E394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005E398: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005E39C: nop

    // 0x8005E3A0: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x8005E3A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005E3A8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3AC: nop

    // 0x8005E3B0: swc1        $f10, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f10.u32l;
    // 0x8005E3B4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8005E3B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005E3BC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3C0: nop

    // 0x8005E3C4: swc1        $f16, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f16.u32l;
    // 0x8005E3C8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3CC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005E3D0: lw          $t1, 0x38($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X38);
    // 0x8005E3D4: nop

    // 0x8005E3D8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8005E3DC: sw          $t2, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r10;
    // 0x8005E3E0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3E4: nop

    // 0x8005E3E8: lw          $t8, 0x38($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X38);
    // 0x8005E3EC: nop

    // 0x8005E3F0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8005E3F4: sw          $t9, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->r25;
    // 0x8005E3F8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3FC: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8005E400: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x8005E404: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005E408: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x8005E40C: sh          $t6, 0x7C($t7)
    MEM_H(0X7C, ctx->r15) = ctx->r14;
    // 0x8005E410: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005E414: jal         0x8005EC54
    // 0x8005E418: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_8005EC54(rdram, ctx);
        goto after_3;
    // 0x8005E418: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_3:
    // 0x8005E41C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005E420: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8005E424: addiu       $a2, $zero, 0x143
    ctx->r6 = ADD32(0, 0X143);
    // 0x8005E428: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8005E42C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E430: jal         0x8004F3E8
    // 0x8005E434: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004F3E8(rdram, ctx);
        goto after_4;
    // 0x8005E434: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x8005E438: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005E43C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E440: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8005E444: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8005E448: or          $t8, $t1, $zero
    ctx->r24 = ctx->r9 | 0;
    // 0x8005E44C: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x8005E450: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8005E454: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8005E458: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8005E45C: b           L_8005E464
    // 0x8005E460: nop

        goto L_8005E464;
    // 0x8005E460: nop

L_8005E464:
    // 0x8005E464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E468: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005E46C: jr          $ra
    // 0x8005E470: nop

    return;
    // 0x8005E470: nop

;}
RECOMP_FUNC void func_80013FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013FEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80013FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013FF4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80013FF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80013FFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80014000: jal         0x8000DA44
    // 0x80014004: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80014004: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80014008: bgez        $v0, L_80014018
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001400C: nop
    
            goto L_80014018;
    }
    // 0x8001400C: nop

    // 0x80014010: b           L_800140C8
    // 0x80014014: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800140C8;
    // 0x80014014: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014018:
    // 0x80014018: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001401C: nop

    // 0x80014020: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80014024: nop

    // 0x80014028: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8001402C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80014030: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80014034: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80014038: nop

    // 0x8001403C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80014040: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x80014044: nop

    // 0x80014048: blez        $t0, L_800140B8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001404C: nop
    
            goto L_800140B8;
    }
    // 0x8001404C: nop

L_80014050:
    // 0x80014050: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x80014054: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    // 0x80014058: jal         0x80014BD4
    // 0x8001405C: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x8001405C: nop

    after_1:
    // 0x80014060: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80014064: nop

    // 0x80014068: swc1        $f0, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f0.u32l;
    // 0x8001406C: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x80014070: lhu         $a0, 0x6($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X6);
    // 0x80014074: jal         0x80014BD4
    // 0x80014078: nop

    func_80014BD4(rdram, ctx);
        goto after_2;
    // 0x80014078: nop

    after_2:
    // 0x8001407C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80014080: nop

    // 0x80014084: swc1        $f0, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f0.u32l;
    // 0x80014088: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001408C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80014090: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80014094: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80014098: addiu       $t9, $t7, 0x160
    ctx->r25 = ADD32(ctx->r15, 0X160);
    // 0x8001409C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800140A0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800140A4: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x800140A8: nop

    // 0x800140AC: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800140B0: bne         $at, $zero, L_80014050
    if (ctx->r1 != 0) {
        // 0x800140B4: nop
    
            goto L_80014050;
    }
    // 0x800140B4: nop

L_800140B8:
    // 0x800140B8: b           L_800140C8
    // 0x800140BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800140C8;
    // 0x800140BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800140C0: b           L_800140C8
    // 0x800140C4: nop

        goto L_800140C8;
    // 0x800140C4: nop

L_800140C8:
    // 0x800140C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800140CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800140D0: jr          $ra
    // 0x800140D4: nop

    return;
    // 0x800140D4: nop

;}
RECOMP_FUNC void func_8003E700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E700: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x8003E704: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003E708: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8003E70C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003E710: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8003E714: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003E718: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x8003E71C: nop

    // 0x8003E720: bne         $t6, $zero, L_8003E740
    if (ctx->r14 != 0) {
        // 0x8003E724: nop
    
            goto L_8003E740;
    }
    // 0x8003E724: nop

    // 0x8003E728: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003E72C: lhu         $t7, 0x728E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X728E);
    // 0x8003E730: nop

    // 0x8003E734: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8003E738: beq         $t8, $zero, L_8003E754
    if (ctx->r24 == 0) {
        // 0x8003E73C: nop
    
            goto L_8003E754;
    }
    // 0x8003E73C: nop

L_8003E740:
    // 0x8003E740: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003E744: nop

    // 0x8003E748: swc1        $f4, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f4.u32l;
    // 0x8003E74C: b           L_8003E7AC
    // 0x8003E750: swc1        $f4, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f4.u32l;
        goto L_8003E7AC;
    // 0x8003E750: swc1        $f4, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f4.u32l;
L_8003E754:
    // 0x8003E754: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8003E758: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8003E75C: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8003E760: nop

    // 0x8003E764: swc1        $f6, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f6.u32l;
    // 0x8003E768: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8003E76C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8003E770: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8003E774: nop

    // 0x8003E778: swc1        $f8, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f8.u32l;
    // 0x8003E77C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E780: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8003E784: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8003E788: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003E78C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003E790: c.eq.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d == ctx->f18.d;
    // 0x8003E794: nop

    // 0x8003E798: bc1f        L_8003E7AC
    if (!c1cs) {
        // 0x8003E79C: nop
    
            goto L_8003E7AC;
    }
    // 0x8003E79C: nop

    // 0x8003E7A0: addiu       $a0, $sp, 0x180
    ctx->r4 = ADD32(ctx->r29, 0X180);
    // 0x8003E7A4: jal         0x80034048
    // 0x8003E7A8: addiu       $a1, $sp, 0x17C
    ctx->r5 = ADD32(ctx->r29, 0X17C);
    func_80034048(rdram, ctx);
        goto after_0;
    // 0x8003E7A8: addiu       $a1, $sp, 0x17C
    ctx->r5 = ADD32(ctx->r29, 0X17C);
    after_0:
L_8003E7AC:
    // 0x8003E7AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E7B0: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003E7B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003E7B8: lwc1        $f9, -0x13A0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X13A0);
    // 0x8003E7BC: lwc1        $f8, -0x139C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X139C);
    // 0x8003E7C0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003E7C4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003E7C8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003E7CC: swc1        $f16, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->f16.u32l;
    // 0x8003E7D0: jal         0x800C3070
    // 0x8003E7D4: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x8003E7D4: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    after_1:
    // 0x8003E7D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E7DC: lwc1        $f18, 0x720C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x8003E7E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E7E4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8003E7E8: lwc1        $f6, -0x73EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003E7EC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003E7F0: addiu       $t1, $t1, 0x7158
    ctx->r9 = ADD32(ctx->r9, 0X7158);
    // 0x8003E7F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003E7F8: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x8003E7FC: lwc1        $f12, 0x184($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X184);
    // 0x8003E800: jal         0x800C3338
    // 0x8003E804: nop

    MathUtil_Cosf(rdram, ctx);
        goto after_2;
    // 0x8003E804: nop

    after_2:
    // 0x8003E808: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E80C: lwc1        $f10, 0x720C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x8003E810: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E814: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8003E818: lwc1        $f18, -0x73D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003E81C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003E820: addiu       $t2, $t2, 0x7158
    ctx->r10 = ADD32(ctx->r10, 0X7158);
    // 0x8003E824: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003E828: swc1        $f4, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f4.u32l;
    // 0x8003E82C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E830: lwc1        $f6, -0x73EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003E834: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003E838: addiu       $t3, $t3, 0x7158
    ctx->r11 = ADD32(ctx->r11, 0X7158);
    // 0x8003E83C: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
    // 0x8003E840: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E844: lwc1        $f8, -0x73E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x8003E848: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003E84C: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x8003E850: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003E854: addiu       $t5, $t5, 0x7158
    ctx->r13 = ADD32(ctx->r13, 0X7158);
    // 0x8003E858: swc1        $f8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f8.u32l;
    // 0x8003E85C: lwc1        $f10, 0x4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8003E860: nop

    // 0x8003E864: swc1        $f10, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f10.u32l;
    // 0x8003E868: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E86C: lwc1        $f16, -0x73D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003E870: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003E874: addiu       $t6, $t6, 0x7158
    ctx->r14 = ADD32(ctx->r14, 0X7158);
    // 0x8003E878: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x8003E87C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003E880: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8003E884: addiu       $a1, $a1, 0x7158
    ctx->r5 = ADD32(ctx->r5, 0X7158);
    // 0x8003E888: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8003E88C: jal         0x800B1250
    // 0x8003E890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_3;
    // 0x8003E890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8003E894: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8003E898: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003E89C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003E8A0: jal         0x800C2304
    // 0x8003E8A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_4;
    // 0x8003E8A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_4:
    // 0x8003E8A8: jal         0x800C1A84
    // 0x8003E8AC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_5;
    // 0x8003E8AC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_5:
    // 0x8003E8B0: jal         0x800AD680
    // 0x8003E8B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800AD680(rdram, ctx);
        goto after_6;
    // 0x8003E8B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x8003E8B8: jal         0x800C1680
    // 0x8003E8BC: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_7;
    // 0x8003E8BC: nop

    after_7:
    // 0x8003E8C0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8003E8C4: lh          $t7, 0x65C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X65C);
    // 0x8003E8C8: nop

    // 0x8003E8CC: beq         $t7, $zero, L_8003E99C
    if (ctx->r15 == 0) {
        // 0x8003E8D0: nop
    
            goto L_8003E99C;
    }
    // 0x8003E8D0: nop

    // 0x8003E8D4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8003E8D8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003E8DC: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    // 0x8003E8E0: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x8003E8E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003E8E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8003E8EC: jal         0x800A57C4
    // 0x8003E8F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800A57C4(rdram, ctx);
        goto after_8;
    // 0x8003E8F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
    // 0x8003E8F4: jal         0x800C1850
    // 0x8003E8F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_9;
    // 0x8003E8F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8003E8FC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003E900: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8003E904: jal         0x800AD1E4
    // 0x8003E908: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_10;
    // 0x8003E908: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x8003E90C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8003E910: lw          $t9, -0x4CCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CCC);
    // 0x8003E914: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8003E918: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x8003E91C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8003E920: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003E924: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003E928: lwc1        $f14, -0x1398($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X1398);
    // 0x8003E92C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003E930: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8003E934: jal         0x800C2304
    // 0x8003E938: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_11;
    // 0x8003E938: nop

    after_11:
    // 0x8003E93C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003E940: lw          $t2, 0x1B44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1B44);
    // 0x8003E944: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003E948: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8003E94C: sw          $t3, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r11;
    // 0x8003E950: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8003E954: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8003E958: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003E95C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8003E960: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8003E964: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8003E968: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8003E96C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8003E970: addiu       $t6, $t6, 0x158
    ctx->r14 = ADD32(ctx->r14, 0X158);
    // 0x8003E974: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8003E978: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8003E97C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003E980: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x8003E984: addiu       $a1, $a1, 0x2D8
    ctx->r5 = ADD32(ctx->r5, 0X2D8);
    // 0x8003E988: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8003E98C: jal         0x800B18C4
    // 0x8003E990: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800B18C4(rdram, ctx);
        goto after_12;
    // 0x8003E990: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_12:
    // 0x8003E994: b           L_8003E9B8
    // 0x8003E998: nop

        goto L_8003E9B8;
    // 0x8003E998: nop

L_8003E99C:
    // 0x8003E99C: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    // 0x8003E9A0: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x8003E9A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003E9A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8003E9AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003E9B0: jal         0x800A57C4
    // 0x8003E9B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800A57C4(rdram, ctx);
        goto after_13;
    // 0x8003E9B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_13:
L_8003E9B8:
    // 0x8003E9B8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8003E9BC: lw          $t0, -0x73B4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73B4);
    // 0x8003E9C0: nop

    // 0x8003E9C4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8003E9C8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8003E9CC: lw          $t9, -0x73B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73B8);
    // 0x8003E9D0: nop

    // 0x8003E9D4: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8003E9D8: jal         0x800C1850
    // 0x8003E9DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_14;
    // 0x8003E9DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8003E9E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003E9E4: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x8003E9E8: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x8003E9EC: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003E9F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003E9F4: jal         0x800C2304
    // 0x8003E9F8: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_15;
    // 0x8003E9F8: nop

    after_15:
    // 0x8003E9FC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8003EA00: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8003EA04: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x8003EA08: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003EA0C: jal         0x800997D8
    // 0x8003EA10: nop

    func_800997D8(rdram, ctx);
        goto after_16;
    // 0x8003EA10: nop

    after_16:
    // 0x8003EA14: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003EA18: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8003EA1C: jal         0x800B26E0
    // 0x8003EA20: nop

    func_800B26E0(rdram, ctx);
        goto after_17;
    // 0x8003EA20: nop

    after_17:
    // 0x8003EA24: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8003EA28: jal         0x80033C60
    // 0x8003EA2C: nop

    func_80033C60(rdram, ctx);
        goto after_18;
    // 0x8003EA2C: nop

    after_18:
    // 0x8003EA30: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8003EA34: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003EA38: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8003EA3C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003EA40: jal         0x800AF184
    // 0x8003EA44: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    func_800AF184(rdram, ctx);
        goto after_19;
    // 0x8003EA44: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    after_19:
    // 0x8003EA48: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003EA4C: lw          $t3, 0x7240($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7240);
    // 0x8003EA50: nop

    // 0x8003EA54: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x8003EA58: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8003EA5C: nop

    // 0x8003EA60: beq         $t4, $zero, L_8003FB40
    if (ctx->r12 == 0) {
        // 0x8003EA64: nop
    
            goto L_8003FB40;
    }
    // 0x8003EA64: nop

L_8003EA68:
    // 0x8003EA68: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003EA6C: nop

    // 0x8003EA70: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003EA74: nop

    // 0x8003EA78: swc1        $f4, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->f4.u32l;
    // 0x8003EA7C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8003EA80: nop

    // 0x8003EA84: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8003EA88: nop

    // 0x8003EA8C: swc1        $f6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f6.u32l;
    // 0x8003EA90: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003EA94: nop

    // 0x8003EA98: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8003EA9C: nop

    // 0x8003EAA0: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
    // 0x8003EAA4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8003EAA8: nop

    // 0x8003EAAC: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8003EAB0: nop

    // 0x8003EAB4: swc1        $f10, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f10.u32l;
    // 0x8003EAB8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8003EABC: nop

    // 0x8003EAC0: lwc1        $f16, 0x10($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8003EAC4: nop

    // 0x8003EAC8: swc1        $f16, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f16.u32l;
    // 0x8003EACC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003EAD0: nop

    // 0x8003EAD4: lwc1        $f18, 0x14($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8003EAD8: nop

    // 0x8003EADC: swc1        $f18, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f18.u32l;
    // 0x8003EAE0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8003EAE4: nop

    // 0x8003EAE8: lhu         $t2, 0x1C($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X1C);
    // 0x8003EAEC: nop

    // 0x8003EAF0: sh          $t2, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r10;
    // 0x8003EAF4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8003EAF8: nop

    // 0x8003EAFC: lhu         $t4, 0x1E($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X1E);
    // 0x8003EB00: nop

    // 0x8003EB04: sh          $t4, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r12;
    // 0x8003EB08: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003EB0C: nop

    // 0x8003EB10: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x8003EB14: nop

    // 0x8003EB18: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8003EB1C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003EB20: nop

    // 0x8003EB24: lhu         $t8, 0x20($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X20);
    // 0x8003EB28: nop

    // 0x8003EB2C: sh          $t8, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r24;
    // 0x8003EB30: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8003EB34: nop

    // 0x8003EB38: addiu       $t9, $t0, 0x28
    ctx->r25 = ADD32(ctx->r8, 0X28);
    // 0x8003EB3C: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8003EB40: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8003EB44: nop

    // 0x8003EB48: addiu       $t2, $t1, 0x188
    ctx->r10 = ADD32(ctx->r9, 0X188);
    // 0x8003EB4C: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8003EB50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003EB54: lwc1        $f6, -0x73EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003EB58: lwc1        $f4, 0x174($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003EB5C: nop

    // 0x8003EB60: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003EB64: swc1        $f8, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f8.u32l;
    // 0x8003EB68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003EB6C: lwc1        $f16, -0x73D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003EB70: lwc1        $f10, 0x170($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003EB74: nop

    // 0x8003EB78: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003EB7C: swc1        $f18, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f18.u32l;
    // 0x8003EB80: lwc1        $f4, 0x140($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X140);
    // 0x8003EB84: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x8003EB88: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8003EB8C: nop

    // 0x8003EB90: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8003EB94: jal         0x800C42A0
    // 0x8003EB98: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_20;
    // 0x8003EB98: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_20:
    // 0x8003EB9C: swc1        $f0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f0.u32l;
    // 0x8003EBA0: lhu         $s0, 0x13A($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X13A);
    // 0x8003EBA4: nop

    // 0x8003EBA8: beq         $s0, $zero, L_8003EBD0
    if (ctx->r16 == 0) {
        // 0x8003EBAC: nop
    
            goto L_8003EBD0;
    }
    // 0x8003EBAC: nop

    // 0x8003EBB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003EBB4: beq         $s0, $at, L_8003F7F4
    if (ctx->r16 == ctx->r1) {
        // 0x8003EBB8: nop
    
            goto L_8003F7F4;
    }
    // 0x8003EBB8: nop

    // 0x8003EBBC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003EBC0: beq         $s0, $at, L_8003F8B8
    if (ctx->r16 == ctx->r1) {
        // 0x8003EBC4: nop
    
            goto L_8003F8B8;
    }
    // 0x8003EBC4: nop

    // 0x8003EBC8: b           L_8003F8C0
    // 0x8003EBCC: nop

        goto L_8003F8C0;
    // 0x8003EBCC: nop

L_8003EBD0:
    // 0x8003EBD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003EBD4: lwc1        $f16, 0x50D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003EBD8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003EBDC: lwc1        $f18, 0x50D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003EBE0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8003EBE4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003EBE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003EBEC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8003EBF0: c.eq.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d == ctx->f6.d;
    // 0x8003EBF4: nop

    // 0x8003EBF8: bc1f        L_8003EC44
    if (!c1cs) {
        // 0x8003EBFC: nop
    
            goto L_8003EC44;
    }
    // 0x8003EBFC: nop

    // 0x8003EC00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003EC04: lwc1        $f16, 0x7324($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003EC08: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003EC0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003EC10: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003EC14: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8003EC18: swc1        $f18, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f18.u32l;
    // 0x8003EC1C: bc1f        L_8003EC44
    if (!c1cs) {
        // 0x8003EC20: nop
    
            goto L_8003EC44;
    }
    // 0x8003EC20: nop

    // 0x8003EC24: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003EC28: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003EC2C: lwc1        $f11, -0x1390($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1390);
    // 0x8003EC30: lwc1        $f10, -0x138C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X138C);
    // 0x8003EC34: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8003EC38: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8003EC3C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003EC40: swc1        $f18, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f18.u32l;
L_8003EC44:
    // 0x8003EC44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003EC48: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003EC4C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8003EC50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003EC54: nop

    // 0x8003EC58: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8003EC5C: nop

    // 0x8003EC60: bc1t        L_8003EC84
    if (c1cs) {
        // 0x8003EC64: nop
    
            goto L_8003EC84;
    }
    // 0x8003EC64: nop

    // 0x8003EC68: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003EC6C: lwc1        $f6, -0x1388($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1388);
    // 0x8003EC70: nop

    // 0x8003EC74: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8003EC78: nop

    // 0x8003EC7C: bc1f        L_8003EC90
    if (!c1cs) {
        // 0x8003EC80: nop
    
            goto L_8003EC90;
    }
    // 0x8003EC80: nop

L_8003EC84:
    // 0x8003EC84: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003EC88: b           L_8003ED08
    // 0x8003EC8C: swc1        $f10, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f10.u32l;
        goto L_8003ED08;
    // 0x8003EC8C: swc1        $f10, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f10.u32l;
L_8003EC90:
    // 0x8003EC90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003EC94: lwc1        $f16, 0x7324($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003EC98: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x8003EC9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003ECA0: nop

    // 0x8003ECA4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8003ECA8: nop

    // 0x8003ECAC: bc1f        L_8003ECC4
    if (!c1cs) {
        // 0x8003ECB0: nop
    
            goto L_8003ECC4;
    }
    // 0x8003ECB0: nop

    // 0x8003ECB4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003ECB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003ECBC: b           L_8003ED08
    // 0x8003ECC0: swc1        $f8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f8.u32l;
        goto L_8003ED08;
    // 0x8003ECC0: swc1        $f8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f8.u32l;
L_8003ECC4:
    // 0x8003ECC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003ECC8: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8003ECCC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8003ECD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003ECD4: nop

    // 0x8003ECD8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003ECDC: nop

    // 0x8003ECE0: bc1f        L_8003ECF8
    if (!c1cs) {
        // 0x8003ECE4: nop
    
            goto L_8003ECF8;
    }
    // 0x8003ECE4: nop

    // 0x8003ECE8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003ECEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003ECF0: b           L_8003ED08
    // 0x8003ECF4: swc1        $f10, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f10.u32l;
        goto L_8003ED08;
    // 0x8003ECF4: swc1        $f10, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f10.u32l;
L_8003ECF8:
    // 0x8003ECF8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8003ECFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003ED00: nop

    // 0x8003ED04: swc1        $f16, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f16.u32l;
L_8003ED08:
    // 0x8003ED08: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003ED0C: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8003ED10: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003ED14: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8003ED18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003ED1C: swc1        $f4, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f4.u32l;
    // 0x8003ED20: bc1f        L_8003ED48
    if (!c1cs) {
        // 0x8003ED24: nop
    
            goto L_8003ED48;
    }
    // 0x8003ED24: nop

    // 0x8003ED28: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003ED2C: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8003ED30: lwc1        $f19, -0x1380($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1380);
    // 0x8003ED34: lwc1        $f18, -0x137C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X137C);
    // 0x8003ED38: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003ED3C: add.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f16.d + ctx->f18.d;
    // 0x8003ED40: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003ED44: swc1        $f4, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f4.u32l;
L_8003ED48:
    // 0x8003ED48: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003ED4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003ED50: lwc1        $f6, 0x168($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8003ED54: nop

    // 0x8003ED58: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x8003ED5C: nop

    // 0x8003ED60: bc1f        L_8003EDA8
    if (!c1cs) {
        // 0x8003ED64: nop
    
            goto L_8003EDA8;
    }
    // 0x8003ED64: nop

    // 0x8003ED68: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8003ED6C: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x8003ED70: bne         $t3, $at, L_8003ED88
    if (ctx->r11 != ctx->r1) {
        // 0x8003ED74: nop
    
            goto L_8003ED88;
    }
    // 0x8003ED74: nop

    // 0x8003ED78: lhu         $t4, 0x138($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X138);
    // 0x8003ED7C: nop

    // 0x8003ED80: beq         $t4, $zero, L_8003EDA8
    if (ctx->r12 == 0) {
        // 0x8003ED84: nop
    
            goto L_8003EDA8;
    }
    // 0x8003ED84: nop

L_8003ED88:
    // 0x8003ED88: lhu         $t5, 0x18A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003ED8C: nop

    // 0x8003ED90: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8003ED94: sh          $t6, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r14;
    // 0x8003ED98: addiu       $t7, $zero, 0x8E
    ctx->r15 = ADD32(0, 0X8E);
    // 0x8003ED9C: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x8003EDA0: b           L_8003EFD0
    // 0x8003EDA4: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
        goto L_8003EFD0;
    // 0x8003EDA4: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
L_8003EDA8:
    // 0x8003EDA8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8003EDAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003EDB0: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8003EDB4: nop

    // 0x8003EDB8: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8003EDBC: nop

    // 0x8003EDC0: bc1f        L_8003EE0C
    if (!c1cs) {
        // 0x8003EDC4: nop
    
            goto L_8003EE0C;
    }
    // 0x8003EDC4: nop

    // 0x8003EDC8: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8003EDCC: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x8003EDD0: bne         $t8, $at, L_8003EDE8
    if (ctx->r24 != ctx->r1) {
        // 0x8003EDD4: nop
    
            goto L_8003EDE8;
    }
    // 0x8003EDD4: nop

    // 0x8003EDD8: lhu         $t0, 0x138($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X138);
    // 0x8003EDDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003EDE0: beq         $t0, $at, L_8003EE0C
    if (ctx->r8 == ctx->r1) {
        // 0x8003EDE4: nop
    
            goto L_8003EE0C;
    }
    // 0x8003EDE4: nop

L_8003EDE8:
    // 0x8003EDE8: lhu         $t9, 0x18A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003EDEC: nop

    // 0x8003EDF0: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x8003EDF4: sh          $t1, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r9;
    // 0x8003EDF8: addiu       $t2, $zero, 0x8E
    ctx->r10 = ADD32(0, 0X8E);
    // 0x8003EDFC: sw          $t2, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r10;
    // 0x8003EE00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003EE04: b           L_8003EFD0
    // 0x8003EE08: sh          $t3, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r11;
        goto L_8003EFD0;
    // 0x8003EE08: sh          $t3, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r11;
L_8003EE0C:
    // 0x8003EE0C: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8003EE10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003EE14: nop

    // 0x8003EE18: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x8003EE1C: nop

    // 0x8003EE20: bc1f        L_8003EEF0
    if (!c1cs) {
        // 0x8003EE24: nop
    
            goto L_8003EEF0;
    }
    // 0x8003EE24: nop

    // 0x8003EE28: jal         0x800C1850
    // 0x8003EE2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_21;
    // 0x8003EE2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x8003EE30: lwc1        $f12, 0x174($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003EE34: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003EE38: lw          $a2, 0x170($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X170);
    // 0x8003EE3C: jal         0x800C2304
    // 0x8003EE40: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_22;
    // 0x8003EE40: nop

    after_22:
    // 0x8003EE44: jal         0x800C2070
    // 0x8003EE48: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    func_800C2070(rdram, ctx);
        goto after_23;
    // 0x8003EE48: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    after_23:
    // 0x8003EE4C: addiu       $t4, $sp, 0xB4
    ctx->r12 = ADD32(ctx->r29, 0XB4);
    // 0x8003EE50: lwc1        $f6, 0x38($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X38);
    // 0x8003EE54: nop

    // 0x8003EE58: swc1        $f6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f6.u32l;
    // 0x8003EE5C: lwc1        $f10, 0x164($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003EE60: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003EE64: nop

    // 0x8003EE68: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8003EE6C: nop

    // 0x8003EE70: bc1f        L_8003EEA4
    if (!c1cs) {
        // 0x8003EE74: nop
    
            goto L_8003EEA4;
    }
    // 0x8003EE74: nop

    // 0x8003EE78: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8003EE7C: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8003EE80: beq         $t5, $at, L_8003EEA4
    if (ctx->r13 == ctx->r1) {
        // 0x8003EE84: nop
    
            goto L_8003EEA4;
    }
    // 0x8003EE84: nop

    // 0x8003EE88: lhu         $t6, 0x18A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003EE8C: nop

    // 0x8003EE90: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8003EE94: sh          $t7, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r15;
    // 0x8003EE98: addiu       $t8, $zero, 0x69
    ctx->r24 = ADD32(0, 0X69);
    // 0x8003EE9C: b           L_8003EEE8
    // 0x8003EEA0: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
        goto L_8003EEE8;
    // 0x8003EEA0: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
L_8003EEA4:
    // 0x8003EEA4: lwc1        $f18, 0x164($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003EEA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003EEAC: nop

    // 0x8003EEB0: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8003EEB4: nop

    // 0x8003EEB8: bc1f        L_8003EEE8
    if (!c1cs) {
        // 0x8003EEBC: nop
    
            goto L_8003EEE8;
    }
    // 0x8003EEBC: nop

    // 0x8003EEC0: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8003EEC4: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8003EEC8: beq         $t0, $at, L_8003EEE8
    if (ctx->r8 == ctx->r1) {
        // 0x8003EECC: nop
    
            goto L_8003EEE8;
    }
    // 0x8003EECC: nop

    // 0x8003EED0: lhu         $t9, 0x18A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003EED4: nop

    // 0x8003EED8: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x8003EEDC: sh          $t1, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r9;
    // 0x8003EEE0: addiu       $t2, $zero, 0x65
    ctx->r10 = ADD32(0, 0X65);
    // 0x8003EEE4: sw          $t2, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r10;
L_8003EEE8:
    // 0x8003EEE8: b           L_8003EFD0
    // 0x8003EEEC: nop

        goto L_8003EFD0;
    // 0x8003EEEC: nop

L_8003EEF0:
    // 0x8003EEF0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003EEF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EEF8: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8003EEFC: nop

    // 0x8003EF00: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8003EF04: nop

    // 0x8003EF08: bc1f        L_8003EFD0
    if (!c1cs) {
        // 0x8003EF0C: nop
    
            goto L_8003EFD0;
    }
    // 0x8003EF0C: nop

    // 0x8003EF10: jal         0x800C1850
    // 0x8003EF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_24;
    // 0x8003EF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x8003EF18: lwc1        $f12, 0x174($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003EF1C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003EF20: lw          $a2, 0x170($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X170);
    // 0x8003EF24: jal         0x800C2304
    // 0x8003EF28: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_25;
    // 0x8003EF28: nop

    after_25:
    // 0x8003EF2C: jal         0x800C2070
    // 0x8003EF30: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    func_800C2070(rdram, ctx);
        goto after_26;
    // 0x8003EF30: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    after_26:
    // 0x8003EF34: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x8003EF38: lwc1        $f10, 0x38($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X38);
    // 0x8003EF3C: nop

    // 0x8003EF40: swc1        $f10, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f10.u32l;
    // 0x8003EF44: lwc1        $f16, 0x164($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003EF48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003EF4C: nop

    // 0x8003EF50: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8003EF54: nop

    // 0x8003EF58: bc1f        L_8003EF8C
    if (!c1cs) {
        // 0x8003EF5C: nop
    
            goto L_8003EF8C;
    }
    // 0x8003EF5C: nop

    // 0x8003EF60: lw          $t4, 0x194($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X194);
    // 0x8003EF64: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8003EF68: beq         $t4, $at, L_8003EF8C
    if (ctx->r12 == ctx->r1) {
        // 0x8003EF6C: nop
    
            goto L_8003EF8C;
    }
    // 0x8003EF6C: nop

    // 0x8003EF70: lhu         $t5, 0x18A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003EF74: nop

    // 0x8003EF78: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8003EF7C: sh          $t6, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r14;
    // 0x8003EF80: addiu       $t7, $zero, 0x69
    ctx->r15 = ADD32(0, 0X69);
    // 0x8003EF84: b           L_8003EFD0
    // 0x8003EF88: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
        goto L_8003EFD0;
    // 0x8003EF88: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
L_8003EF8C:
    // 0x8003EF8C: lwc1        $f8, 0x164($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003EF90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003EF94: nop

    // 0x8003EF98: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8003EF9C: nop

    // 0x8003EFA0: bc1f        L_8003EFD0
    if (!c1cs) {
        // 0x8003EFA4: nop
    
            goto L_8003EFD0;
    }
    // 0x8003EFA4: nop

    // 0x8003EFA8: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8003EFAC: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8003EFB0: beq         $t8, $at, L_8003EFD0
    if (ctx->r24 == ctx->r1) {
        // 0x8003EFB4: nop
    
            goto L_8003EFD0;
    }
    // 0x8003EFB4: nop

    // 0x8003EFB8: lhu         $t0, 0x18A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003EFBC: nop

    // 0x8003EFC0: ori         $t9, $t0, 0x1
    ctx->r25 = ctx->r8 | 0X1;
    // 0x8003EFC4: sh          $t9, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r25;
    // 0x8003EFC8: addiu       $t1, $zero, 0x65
    ctx->r9 = ADD32(0, 0X65);
    // 0x8003EFCC: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
L_8003EFD0:
    // 0x8003EFD0: jal         0x800C1850
    // 0x8003EFD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_27;
    // 0x8003EFD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x8003EFD8: lwc1        $f12, 0x160($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003EFDC: jal         0x800C25B8
    // 0x8003EFE0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_28;
    // 0x8003EFE0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_28:
    // 0x8003EFE4: lwc1        $f12, 0x140($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X140);
    // 0x8003EFE8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003EFEC: lw          $a2, 0x13C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X13C);
    // 0x8003EFF0: jal         0x800C2304
    // 0x8003EFF4: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_29;
    // 0x8003EFF4: nop

    after_29:
    // 0x8003EFF8: jal         0x800B1844
    // 0x8003EFFC: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_800B1844(rdram, ctx);
        goto after_30;
    // 0x8003EFFC: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_30:
    // 0x8003F000: addiu       $t2, $sp, 0xA8
    ctx->r10 = ADD32(ctx->r29, 0XA8);
    // 0x8003F004: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8003F008: nop

    // 0x8003F00C: swc1        $f6, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f6.u32l;
    // 0x8003F010: addiu       $t3, $sp, 0xA8
    ctx->r11 = ADD32(ctx->r29, 0XA8);
    // 0x8003F014: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8003F018: nop

    // 0x8003F01C: swc1        $f10, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f10.u32l;
    // 0x8003F020: jal         0x800C1850
    // 0x8003F024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_31;
    // 0x8003F024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x8003F028: lwc1        $f12, 0x160($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F02C: jal         0x800C25B8
    // 0x8003F030: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_32;
    // 0x8003F030: nop

    after_32:
    // 0x8003F034: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003F038: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003F03C: jal         0x800C2304
    // 0x8003F040: lui         $a2, 0xBFC0
    ctx->r6 = S32(0XBFC0 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_33;
    // 0x8003F040: lui         $a2, 0xBFC0
    ctx->r6 = S32(0XBFC0 << 16);
    after_33:
    // 0x8003F044: jal         0x800B1844
    // 0x8003F048: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_800B1844(rdram, ctx);
        goto after_34;
    // 0x8003F048: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_34:
    // 0x8003F04C: addiu       $t4, $sp, 0xA8
    ctx->r12 = ADD32(ctx->r29, 0XA8);
    // 0x8003F050: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003F054: nop

    // 0x8003F058: swc1        $f16, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f16.u32l;
    // 0x8003F05C: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x8003F060: lwc1        $f18, 0x8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8003F064: nop

    // 0x8003F068: swc1        $f18, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f18.u32l;
    // 0x8003F06C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8003F070: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F074: lwc1        $f8, 0x150($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003F078: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003F07C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8003F080: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003F084: lwc1        $f10, 0x174($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003F088: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003F08C: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8003F090: lw          $t6, 0x71FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71FC);
    // 0x8003F094: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8003F098: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8003F09C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003F0A0: lwc1        $f6, 0x170($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003F0A4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003F0A8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003F0AC: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x8003F0B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8003F0B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8003F0B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8003F0BC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8003F0C0: jal         0x800346E4
    // 0x8003F0C4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800346E4(rdram, ctx);
        goto after_35;
    // 0x8003F0C4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_35:
    // 0x8003F0C8: beq         $v0, $zero, L_8003F124
    if (ctx->r2 == 0) {
        // 0x8003F0CC: nop
    
            goto L_8003F124;
    }
    // 0x8003F0CC: nop

    // 0x8003F0D0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003F0D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F0D8: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F0DC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8003F0E0: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003F0E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003F0E8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8003F0EC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8003F0F0: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
    // 0x8003F0F4: bc1f        L_8003F11C
    if (!c1cs) {
        // 0x8003F0F8: nop
    
            goto L_8003F11C;
    }
    // 0x8003F0F8: nop

    // 0x8003F0FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003F100: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F104: lwc1        $f19, -0x1378($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1378);
    // 0x8003F108: lwc1        $f18, -0x1374($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1374);
    // 0x8003F10C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003F110: add.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f16.d + ctx->f18.d;
    // 0x8003F114: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003F118: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
L_8003F11C:
    // 0x8003F11C: b           L_8003F5CC
    // 0x8003F120: nop

        goto L_8003F5CC;
    // 0x8003F120: nop

L_8003F124:
    // 0x8003F124: sh          $zero, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = 0;
    // 0x8003F128: jal         0x800C1850
    // 0x8003F12C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_36;
    // 0x8003F12C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x8003F130: lwc1        $f12, 0x160($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F134: jal         0x800C25B8
    // 0x8003F138: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_37;
    // 0x8003F138: nop

    after_37:
    // 0x8003F13C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003F140: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003F144: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003F148: jal         0x800C2304
    // 0x8003F14C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_38;
    // 0x8003F14C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_38:
    // 0x8003F150: jal         0x800B1844
    // 0x8003F154: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_800B1844(rdram, ctx);
        goto after_39;
    // 0x8003F154: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_39:
    // 0x8003F158: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003F15C: addiu       $t9, $sp, 0xA8
    ctx->r25 = ADD32(ctx->r29, 0XA8);
    // 0x8003F160: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8003F164: lw          $t0, 0x71FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X71FC);
    // 0x8003F168: lwc1        $f10, 0x174($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003F16C: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8003F170: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003F174: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003F178: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x8003F17C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8003F180: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003F184: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x8003F188: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8003F18C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8003F190: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8003F194: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003F198: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8003F19C: jal         0x800346E4
    // 0x8003F1A0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800346E4(rdram, ctx);
        goto after_40;
    // 0x8003F1A0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_40:
    // 0x8003F1A4: bne         $v0, $zero, L_8003F1B4
    if (ctx->r2 != 0) {
        // 0x8003F1A8: nop
    
            goto L_8003F1B4;
    }
    // 0x8003F1A8: nop

    // 0x8003F1AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003F1B0: sh          $t3, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r11;
L_8003F1B4:
    // 0x8003F1B4: jal         0x800C1850
    // 0x8003F1B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_41;
    // 0x8003F1B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_41:
    // 0x8003F1BC: lwc1        $f12, 0x160($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F1C0: jal         0x800C25B8
    // 0x8003F1C4: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_42;
    // 0x8003F1C4: nop

    after_42:
    // 0x8003F1C8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8003F1CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003F1D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003F1D4: jal         0x800C2304
    // 0x8003F1D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_43;
    // 0x8003F1D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_43:
    // 0x8003F1DC: jal         0x800B1844
    // 0x8003F1E0: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_800B1844(rdram, ctx);
        goto after_44;
    // 0x8003F1E0: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_44:
    // 0x8003F1E4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003F1E8: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x8003F1EC: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003F1F0: lw          $t4, 0x71FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X71FC);
    // 0x8003F1F4: lwc1        $f10, 0x174($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003F1F8: lwc1        $f18, 0x8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8003F1FC: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003F200: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003F204: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x8003F208: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8003F20C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003F210: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8003F214: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8003F218: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8003F21C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8003F220: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003F224: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8003F228: jal         0x800346E4
    // 0x8003F22C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800346E4(rdram, ctx);
        goto after_45;
    // 0x8003F22C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_45:
    // 0x8003F230: bne         $v0, $zero, L_8003F248
    if (ctx->r2 != 0) {
        // 0x8003F234: nop
    
            goto L_8003F248;
    }
    // 0x8003F234: nop

    // 0x8003F238: lhu         $t8, 0x18C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003F23C: nop

    // 0x8003F240: ori         $t0, $t8, 0x2
    ctx->r8 = ctx->r24 | 0X2;
    // 0x8003F244: sh          $t0, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r8;
L_8003F248:
    // 0x8003F248: lhu         $t9, 0x18C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003F24C: nop

    // 0x8003F250: beq         $t9, $zero, L_8003F2CC
    if (ctx->r25 == 0) {
        // 0x8003F254: nop
    
            goto L_8003F2CC;
    }
    // 0x8003F254: nop

    // 0x8003F258: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003F25C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F260: lwc1        $f10, 0x150($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003F264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F268: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8003F26C: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003F270: lwc1        $f18, 0x174($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003F274: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003F278: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003F27C: lw          $t1, 0x71FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X71FC);
    // 0x8003F280: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8003F284: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x8003F288: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003F28C: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003F290: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003F294: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003F298: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x8003F29C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8003F2A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8003F2A4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8003F2A8: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8003F2AC: jal         0x800346E4
    // 0x8003F2B0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800346E4(rdram, ctx);
        goto after_46;
    // 0x8003F2B0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_46:
    // 0x8003F2B4: bne         $v0, $zero, L_8003F2CC
    if (ctx->r2 != 0) {
        // 0x8003F2B8: nop
    
            goto L_8003F2CC;
    }
    // 0x8003F2B8: nop

    // 0x8003F2BC: lhu         $t4, 0x18C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003F2C0: nop

    // 0x8003F2C4: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x8003F2C8: sh          $t5, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r13;
L_8003F2CC:
    // 0x8003F2CC: lhu         $t6, 0x18C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003F2D0: nop

    // 0x8003F2D4: beq         $t6, $zero, L_8003F33C
    if (ctx->r14 == 0) {
        // 0x8003F2D8: nop
    
            goto L_8003F33C;
    }
    // 0x8003F2D8: nop

    // 0x8003F2DC: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003F2E0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003F2E4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8003F2E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003F2EC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8003F2F0: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x8003F2F4: lui         $at, 0x405E
    ctx->r1 = S32(0X405E << 16);
    // 0x8003F2F8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003F2FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003F300: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003F304: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003F308: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x8003F30C: swc1        $f16, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f16.u32l;
    // 0x8003F310: bc1f        L_8003F334
    if (!c1cs) {
        // 0x8003F314: nop
    
            goto L_8003F334;
    }
    // 0x8003F314: nop

    // 0x8003F318: lhu         $t7, 0x18A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F31C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8003F320: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8003F324: sh          $t8, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r24;
    // 0x8003F328: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003F32C: nop

    // 0x8003F330: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
L_8003F334:
    // 0x8003F334: b           L_8003F358
    // 0x8003F338: nop

        goto L_8003F358;
    // 0x8003F338: nop

L_8003F33C:
    // 0x8003F33C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003F340: nop

    // 0x8003F344: swc1        $f6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f6.u32l;
    // 0x8003F348: lhu         $t0, 0x18A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F34C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8003F350: and         $t9, $t0, $at
    ctx->r25 = ctx->r8 & ctx->r1;
    // 0x8003F354: sh          $t9, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r25;
L_8003F358:
    // 0x8003F358: lwc1        $f10, 0x158($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003F35C: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x8003F360: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003F364: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003F368: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003F36C: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8003F370: nop

    // 0x8003F374: bc1f        L_8003F5A4
    if (!c1cs) {
        // 0x8003F378: nop
    
            goto L_8003F5A4;
    }
    // 0x8003F378: nop

    // 0x8003F37C: lhu         $t1, 0x18A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F380: nop

    // 0x8003F384: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x8003F388: bne         $t2, $zero, L_8003F5A4
    if (ctx->r10 != 0) {
        // 0x8003F38C: nop
    
            goto L_8003F5A4;
    }
    // 0x8003F38C: nop

    // 0x8003F390: lhu         $t3, 0x18A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F394: nop

    // 0x8003F398: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8003F39C: sh          $t4, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r12;
    // 0x8003F3A0: sh          $zero, 0x192($sp)
    MEM_H(0X192, ctx->r29) = 0;
    // 0x8003F3A4: lhu         $t5, 0x18C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003F3A8: nop

    // 0x8003F3AC: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8003F3B0: beq         $t6, $zero, L_8003F434
    if (ctx->r14 == 0) {
        // 0x8003F3B4: nop
    
            goto L_8003F434;
    }
    // 0x8003F3B4: nop

    // 0x8003F3B8: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x8003F3BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003F3C0: nop

    // 0x8003F3C4: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8003F3C8: nop

    // 0x8003F3CC: bc1f        L_8003F3DC
    if (!c1cs) {
        // 0x8003F3D0: nop
    
            goto L_8003F3DC;
    }
    // 0x8003F3D0: nop

    // 0x8003F3D4: b           L_8003F3E8
    // 0x8003F3D8: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
        goto L_8003F3E8;
    // 0x8003F3D8: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
L_8003F3DC:
    // 0x8003F3DC: lwc1        $f20, 0x148($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X148);
    // 0x8003F3E0: nop

    // 0x8003F3E4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8003F3E8:
    // 0x8003F3E8: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x8003F3EC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003F3F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003F3F4: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x8003F3F8: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8003F3FC: nop

    // 0x8003F400: bc1f        L_8003F434
    if (!c1cs) {
        // 0x8003F404: nop
    
            goto L_8003F434;
    }
    // 0x8003F404: nop

    // 0x8003F408: lwc1        $f16, 0x144($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003F40C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8003F410: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003F414: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003F418: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8003F41C: nop

    // 0x8003F420: bc1f        L_8003F434
    if (!c1cs) {
        // 0x8003F424: nop
    
            goto L_8003F434;
    }
    // 0x8003F424: nop

    // 0x8003F428: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003F42C: b           L_8003F4D4
    // 0x8003F430: sh          $t7, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r15;
        goto L_8003F4D4;
    // 0x8003F430: sh          $t7, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r15;
L_8003F434:
    // 0x8003F434: lwc1        $f8, 0x16C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003F438: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x8003F43C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003F440: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003F444: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8003F448: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x8003F44C: nop

    // 0x8003F450: bc1f        L_8003F4D4
    if (!c1cs) {
        // 0x8003F454: nop
    
            goto L_8003F4D4;
    }
    // 0x8003F454: nop

    // 0x8003F458: lhu         $t8, 0x18C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003F45C: nop

    // 0x8003F460: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x8003F464: beq         $t0, $zero, L_8003F498
    if (ctx->r8 == 0) {
        // 0x8003F468: nop
    
            goto L_8003F498;
    }
    // 0x8003F468: nop

    // 0x8003F46C: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8003F470: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F474: lwc1        $f16, 0x148($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X148);
    // 0x8003F478: nop

    // 0x8003F47C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8003F480: nop

    // 0x8003F484: bc1f        L_8003F498
    if (!c1cs) {
        // 0x8003F488: nop
    
            goto L_8003F498;
    }
    // 0x8003F488: nop

    // 0x8003F48C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003F490: b           L_8003F4D4
    // 0x8003F494: sh          $t9, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r25;
        goto L_8003F4D4;
    // 0x8003F494: sh          $t9, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r25;
L_8003F498:
    // 0x8003F498: lhu         $t1, 0x18C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003F49C: nop

    // 0x8003F4A0: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8003F4A4: beq         $t2, $zero, L_8003F4D4
    if (ctx->r10 == 0) {
        // 0x8003F4A8: nop
    
            goto L_8003F4D4;
    }
    // 0x8003F4A8: nop

    // 0x8003F4AC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8003F4B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003F4B4: lwc1        $f4, 0x148($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X148);
    // 0x8003F4B8: nop

    // 0x8003F4BC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8003F4C0: nop

    // 0x8003F4C4: bc1f        L_8003F4D4
    if (!c1cs) {
        // 0x8003F4C8: nop
    
            goto L_8003F4D4;
    }
    // 0x8003F4C8: nop

    // 0x8003F4CC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003F4D0: sh          $t3, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r11;
L_8003F4D4:
    // 0x8003F4D4: lhu         $t4, 0x18C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003F4D8: lhu         $t5, 0x192($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X192);
    // 0x8003F4DC: nop

    // 0x8003F4E0: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8003F4E4: beq         $t6, $zero, L_8003F57C
    if (ctx->r14 == 0) {
        // 0x8003F4E8: nop
    
            goto L_8003F57C;
    }
    // 0x8003F4E8: nop

    // 0x8003F4EC: lhu         $t7, 0x192($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X192);
    // 0x8003F4F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F4F4: bne         $t7, $at, L_8003F530
    if (ctx->r15 != ctx->r1) {
        // 0x8003F4F8: nop
    
            goto L_8003F530;
    }
    // 0x8003F4F8: nop

    // 0x8003F4FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003F500: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003F504: lwc1        $f6, 0x160($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F508: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003F50C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8003F510: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8003F514: swc1        $f16, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f16.u32l;
    // 0x8003F518: bc1f        L_8003F530
    if (!c1cs) {
        // 0x8003F51C: nop
    
            goto L_8003F530;
    }
    // 0x8003F51C: nop

    // 0x8003F520: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8003F524: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F528: b           L_8003F574
    // 0x8003F52C: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
        goto L_8003F574;
    // 0x8003F52C: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
L_8003F530:
    // 0x8003F530: lhu         $t8, 0x192($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X192);
    // 0x8003F534: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F538: bne         $t8, $at, L_8003F574
    if (ctx->r24 != ctx->r1) {
        // 0x8003F53C: nop
    
            goto L_8003F574;
    }
    // 0x8003F53C: nop

    // 0x8003F540: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003F544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F548: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F54C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F550: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003F554: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8003F558: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8003F55C: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
    // 0x8003F560: bc1f        L_8003F574
    if (!c1cs) {
        // 0x8003F564: nop
    
            goto L_8003F574;
    }
    // 0x8003F564: nop

    // 0x8003F568: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003F56C: nop

    // 0x8003F570: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
L_8003F574:
    // 0x8003F574: b           L_8003F5A4
    // 0x8003F578: nop

        goto L_8003F5A4;
    // 0x8003F578: nop

L_8003F57C:
    // 0x8003F57C: jal         0x800C4240
    // 0x8003F580: nop

    guRandom(rdram, ctx);
        goto after_47;
    // 0x8003F580: nop

    after_47:
    // 0x8003F584: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F588: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8003F58C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003F590: mfhi        $t0
    ctx->r8 = hi;
    // 0x8003F594: sllv        $t1, $t9, $t0
    ctx->r9 = S32(ctx->r25 << (ctx->r8 & 31));
    // 0x8003F598: sh          $t1, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r9;
    // 0x8003F59C: b           L_8003F4D4
    // 0x8003F5A0: nop

        goto L_8003F4D4;
    // 0x8003F5A0: nop

L_8003F5A4:
    // 0x8003F5A4: lwc1        $f4, 0x174($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003F5A8: lwc1        $f8, 0x150($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003F5AC: nop

    // 0x8003F5B0: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003F5B4: swc1        $f6, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->f6.u32l;
    // 0x8003F5B8: lwc1        $f10, 0x170($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003F5BC: lwc1        $f16, 0x14C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003F5C0: nop

    // 0x8003F5C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003F5C8: swc1        $f18, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f18.u32l;
L_8003F5CC:
    // 0x8003F5CC: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8003F5D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003F5D4: lwc1        $f4, 0x16C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003F5D8: nop

    // 0x8003F5DC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8003F5E0: nop

    // 0x8003F5E4: bc1f        L_8003F7C4
    if (!c1cs) {
        // 0x8003F5E8: nop
    
            goto L_8003F7C4;
    }
    // 0x8003F5E8: nop

    // 0x8003F5EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003F5F0: sh          $t2, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r10;
    // 0x8003F5F4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003F5F8: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003F5FC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8003F600: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003F604: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003F608: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x8003F60C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8003F610: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8003F614: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003F618: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8003F61C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8003F620: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8003F624: mfhi        $t7
    ctx->r15 = hi;
    // 0x8003F628: bne         $t7, $zero, L_8003F698
    if (ctx->r15 != 0) {
        // 0x8003F62C: nop
    
            goto L_8003F698;
    }
    // 0x8003F62C: nop

    // 0x8003F630: lwc1        $f16, 0x144($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003F634: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003F638: nop

    // 0x8003F63C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8003F640: nop

    // 0x8003F644: bc1f        L_8003F690
    if (!c1cs) {
        // 0x8003F648: nop
    
            goto L_8003F690;
    }
    // 0x8003F648: nop

    // 0x8003F64C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003F650: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003F654: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F658: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003F65C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8003F660: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8003F664: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x8003F668: bc1f        L_8003F690
    if (!c1cs) {
        // 0x8003F66C: nop
    
            goto L_8003F690;
    }
    // 0x8003F66C: nop

    // 0x8003F670: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003F674: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F678: lwc1        $f5, -0x1370($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1370);
    // 0x8003F67C: lwc1        $f4, -0x136C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X136C);
    // 0x8003F680: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003F684: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x8003F688: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8003F68C: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
L_8003F690:
    // 0x8003F690: b           L_8003F780
    // 0x8003F694: nop

        goto L_8003F780;
    // 0x8003F694: nop

L_8003F698:
    // 0x8003F698: lwc1        $f10, 0x158($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003F69C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8003F6A0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003F6A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003F6A8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003F6AC: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8003F6B0: nop

    // 0x8003F6B4: bc1f        L_8003F780
    if (!c1cs) {
        // 0x8003F6B8: nop
    
            goto L_8003F780;
    }
    // 0x8003F6B8: nop

    // 0x8003F6BC: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8003F6C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F6C4: nop

    // 0x8003F6C8: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8003F6CC: nop

    // 0x8003F6D0: bc1f        L_8003F780
    if (!c1cs) {
        // 0x8003F6D4: nop
    
            goto L_8003F780;
    }
    // 0x8003F6D4: nop

    // 0x8003F6D8: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x8003F6DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003F6E0: nop

    // 0x8003F6E4: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8003F6E8: nop

    // 0x8003F6EC: bc1f        L_8003F734
    if (!c1cs) {
        // 0x8003F6F0: nop
    
            goto L_8003F734;
    }
    // 0x8003F6F0: nop

    // 0x8003F6F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003F6F8: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F6FC: lwc1        $f11, -0x1368($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1368);
    // 0x8003F700: lwc1        $f10, -0x1364($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1364);
    // 0x8003F704: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003F708: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x8003F70C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003F710: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8003F714: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8003F718: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
    // 0x8003F71C: bc1f        L_8003F734
    if (!c1cs) {
        // 0x8003F720: nop
    
            goto L_8003F734;
    }
    // 0x8003F720: nop

    // 0x8003F724: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8003F728: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003F72C: b           L_8003F780
    // 0x8003F730: swc1        $f16, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f16.u32l;
        goto L_8003F780;
    // 0x8003F730: swc1        $f16, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f16.u32l;
L_8003F734:
    // 0x8003F734: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003F738: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003F73C: lwc1        $f5, -0x1360($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1360);
    // 0x8003F740: lwc1        $f4, -0x135C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X135C);
    // 0x8003F744: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8003F748: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x8003F74C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003F750: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8003F754: lwc1        $f19, -0x1358($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1358);
    // 0x8003F758: lwc1        $f18, -0x1354($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1354);
    // 0x8003F75C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8003F760: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8003F764: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x8003F768: bc1f        L_8003F77C
    if (!c1cs) {
        // 0x8003F76C: nop
    
            goto L_8003F77C;
    }
    // 0x8003F76C: nop

    // 0x8003F770: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003F774: b           L_8003F780
    // 0x8003F778: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
        goto L_8003F780;
    // 0x8003F778: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_8003F77C:
    // 0x8003F77C: sh          $zero, 0x192($sp)
    MEM_H(0X192, ctx->r29) = 0;
L_8003F780:
    // 0x8003F780: lhu         $t8, 0x192($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X192);
    // 0x8003F784: nop

    // 0x8003F788: beq         $t8, $zero, L_8003F7BC
    if (ctx->r24 == 0) {
        // 0x8003F78C: nop
    
            goto L_8003F7BC;
    }
    // 0x8003F78C: nop

    // 0x8003F790: lhu         $t9, 0x18A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F794: nop

    // 0x8003F798: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8003F79C: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
    // 0x8003F7A0: addiu       $t1, $zero, 0x18D
    ctx->r9 = ADD32(0, 0X18D);
    // 0x8003F7A4: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x8003F7A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003F7AC: nop

    // 0x8003F7B0: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    // 0x8003F7B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003F7B8: sh          $t2, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r10;
L_8003F7BC:
    // 0x8003F7BC: b           L_8003F7EC
    // 0x8003F7C0: nop

        goto L_8003F7EC;
    // 0x8003F7C0: nop

L_8003F7C4:
    // 0x8003F7C4: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8003F7C8: addiu       $at, $zero, 0x18D
    ctx->r1 = ADD32(0, 0X18D);
    // 0x8003F7CC: bne         $t3, $at, L_8003F7EC
    if (ctx->r11 != ctx->r1) {
        // 0x8003F7D0: nop
    
            goto L_8003F7EC;
    }
    // 0x8003F7D0: nop

    // 0x8003F7D4: addiu       $t4, $zero, 0x65
    ctx->r12 = ADD32(0, 0X65);
    // 0x8003F7D8: sw          $t4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r12;
    // 0x8003F7DC: lhu         $t5, 0x18A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F7E0: nop

    // 0x8003F7E4: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8003F7E8: sh          $t6, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r14;
L_8003F7EC:
    // 0x8003F7EC: b           L_8003F8C0
    // 0x8003F7F0: nop

        goto L_8003F8C0;
    // 0x8003F7F0: nop

L_8003F7F4:
    // 0x8003F7F4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8003F7F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F7FC: lwc1        $f8, 0x16C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003F800: nop

    // 0x8003F804: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8003F808: nop

    // 0x8003F80C: bc1f        L_8003F81C
    if (!c1cs) {
        // 0x8003F810: nop
    
            goto L_8003F81C;
    }
    // 0x8003F810: nop

    // 0x8003F814: b           L_8003F8B0
    // 0x8003F818: sh          $zero, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = 0;
        goto L_8003F8B0;
    // 0x8003F818: sh          $zero, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = 0;
L_8003F81C:
    // 0x8003F81C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003F820: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F824: lwc1        $f16, 0x16C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003F828: nop

    // 0x8003F82C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8003F830: nop

    // 0x8003F834: bc1f        L_8003F864
    if (!c1cs) {
        // 0x8003F838: nop
    
            goto L_8003F864;
    }
    // 0x8003F838: nop

    // 0x8003F83C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003F840: lhu         $t7, 0x728E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X728E);
    // 0x8003F844: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003F848: ori         $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 | 0X8000;
    // 0x8003F84C: sh          $t8, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r24;
    // 0x8003F850: lhu         $t9, 0x18A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F854: nop

    // 0x8003F858: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x8003F85C: b           L_8003F8B0
    // 0x8003F860: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
        goto L_8003F8B0;
    // 0x8003F860: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
L_8003F864:
    // 0x8003F864: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003F868: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003F86C: lwc1        $f10, 0x15C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003F870: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003F874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F878: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8003F87C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8003F880: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8003F884: bc1f        L_8003F8B0
    if (!c1cs) {
        // 0x8003F888: nop
    
            goto L_8003F8B0;
    }
    // 0x8003F888: nop

    // 0x8003F88C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003F890: lhu         $t1, 0x728E($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X728E);
    // 0x8003F894: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003F898: ori         $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 | 0X8000;
    // 0x8003F89C: sh          $t2, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r10;
    // 0x8003F8A0: lhu         $t3, 0x18A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F8A4: nop

    // 0x8003F8A8: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x8003F8AC: sh          $t4, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r12;
L_8003F8B0:
    // 0x8003F8B0: b           L_8003F8C0
    // 0x8003F8B4: nop

        goto L_8003F8C0;
    // 0x8003F8B4: nop

L_8003F8B8:
    // 0x8003F8B8: b           L_8003F8C0
    // 0x8003F8BC: nop

        goto L_8003F8C0;
    // 0x8003F8BC: nop

L_8003F8C0:
    // 0x8003F8C0: lhu         $t5, 0x18A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F8C4: nop

    // 0x8003F8C8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8003F8CC: beq         $t6, $zero, L_8003F91C
    if (ctx->r14 == 0) {
        // 0x8003F8D0: nop
    
            goto L_8003F91C;
    }
    // 0x8003F8D0: nop

    // 0x8003F8D4: lw          $a2, 0x194($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X194);
    // 0x8003F8D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003F8DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003F8E0: lhu         $t8, 0x138($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X138);
    // 0x8003F8E4: lui         $at, 0x3D
    ctx->r1 = S32(0X3D << 16);
    // 0x8003F8E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003F8EC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8003F8F0: or          $t7, $a2, $at
    ctx->r15 = ctx->r6 | ctx->r1;
    // 0x8003F8F4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8003F8F8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x8003F8FC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8003F900: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8003F904: jal         0x800B1F0C
    // 0x8003F908: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_800B1F0C(rdram, ctx);
        goto after_48;
    // 0x8003F908: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_48:
    // 0x8003F90C: lhu         $t9, 0x18A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F910: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8003F914: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8003F918: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
L_8003F91C:
    // 0x8003F91C: lhu         $t1, 0x18A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F920: nop

    // 0x8003F924: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8003F928: beq         $t2, $zero, L_8003F9A0
    if (ctx->r10 == 0) {
        // 0x8003F92C: nop
    
            goto L_8003F9A0;
    }
    // 0x8003F92C: nop

    // 0x8003F930: jal         0x800B9000
    // 0x8003F934: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    func_800B9000(rdram, ctx);
        goto after_49;
    // 0x8003F934: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_49:
    // 0x8003F938: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8003F93C: sh          $t3, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r11;
    // 0x8003F940: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8003F944: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003F948: sw          $t4, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r12;
    // 0x8003F94C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003F950: lh          $t5, 0x7254($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7254);
    // 0x8003F954: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003F958: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x8003F95C: sh          $t6, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r14;
    // 0x8003F960: addiu       $t7, $zero, 0x3A
    ctx->r15 = ADD32(0, 0X3A);
    // 0x8003F964: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003F968: sh          $t7, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r15;
    // 0x8003F96C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003F970: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003F974: sw          $t8, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = ctx->r24;
    // 0x8003F978: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003F97C: sw          $zero, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = 0;
    // 0x8003F980: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003F984: sw          $zero, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = 0;
    // 0x8003F988: lhu         $t9, 0x18A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003F98C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8003F990: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8003F994: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
    // 0x8003F998: jal         0x80031728
    // 0x8003F99C: nop

    func_80031728(rdram, ctx);
        goto after_50;
    // 0x8003F99C: nop

    after_50:
L_8003F9A0:
    // 0x8003F9A0: jal         0x800C1850
    // 0x8003F9A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_51;
    // 0x8003F9A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_51:
    // 0x8003F9A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003F9AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F9B0: lwc1        $f12, 0x174($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003F9B4: lw          $a2, 0x170($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X170);
    // 0x8003F9B8: jal         0x800C2304
    // 0x8003F9BC: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_52;
    // 0x8003F9BC: nop

    after_52:
    // 0x8003F9C0: jal         0x800C2070
    // 0x8003F9C4: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    func_800C2070(rdram, ctx);
        goto after_53;
    // 0x8003F9C4: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    after_53:
    // 0x8003F9C8: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x8003F9CC: lwc1        $f12, 0x30($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X30);
    // 0x8003F9D0: lwc1        $f14, 0x34($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8003F9D4: lw          $a2, 0x38($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X38);
    // 0x8003F9D8: jal         0x800AF1F0
    // 0x8003F9DC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_800AF1F0(rdram, ctx);
        goto after_54;
    // 0x8003F9DC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_54:
    // 0x8003F9E0: beq         $v0, $zero, L_8003FA0C
    if (ctx->r2 == 0) {
        // 0x8003F9E4: nop
    
            goto L_8003FA0C;
    }
    // 0x8003F9E4: nop

    // 0x8003F9E8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8003F9EC: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8003F9F0: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x8003F9F4: nop

    // 0x8003F9F8: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8003F9FC: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
    // 0x8003FA00: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FA04: jal         0x800997D8
    // 0x8003FA08: nop

    func_800997D8(rdram, ctx);
        goto after_55;
    // 0x8003FA08: nop

    after_55:
L_8003FA0C:
    // 0x8003FA0C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FA10: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8003FA14: jal         0x800B26E0
    // 0x8003FA18: nop

    func_800B26E0(rdram, ctx);
        goto after_56;
    // 0x8003FA18: nop

    after_56:
    // 0x8003FA1C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8003FA20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003FA24: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003FA28: nop

    // 0x8003FA2C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8003FA30: nop

    // 0x8003FA34: bc1f        L_8003FA7C
    if (!c1cs) {
        // 0x8003FA38: nop
    
            goto L_8003FA7C;
    }
    // 0x8003FA38: nop

    // 0x8003FA3C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8003FA40: jal         0x800B3434
    // 0x8003FA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_57;
    // 0x8003FA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_57:
    // 0x8003FA48: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x8003FA4C: beq         $t5, $zero, L_8003FA7C
    if (ctx->r13 == 0) {
        // 0x8003FA50: nop
    
            goto L_8003FA7C;
    }
    // 0x8003FA50: nop

    // 0x8003FA54: lwc1        $f8, 0x140($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X140);
    // 0x8003FA58: lwc1        $f6, 0x13C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x8003FA5C: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8003FA60: lw          $a3, 0x7324($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7324);
    // 0x8003FA64: lw          $a2, 0x16C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X16C);
    // 0x8003FA68: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x8003FA6C: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x8003FA70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8003FA74: jal         0x8003E568
    // 0x8003FA78: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_8003E568(rdram, ctx);
        goto after_58;
    // 0x8003FA78: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_58:
L_8003FA7C:
    // 0x8003FA7C: lwc1        $f16, 0x174($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003FA80: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8003FA84: nop

    // 0x8003FA88: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8003FA8C: lwc1        $f18, 0x170($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003FA90: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003FA94: nop

    // 0x8003FA98: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x8003FA9C: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003FAA0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8003FAA4: nop

    // 0x8003FAA8: swc1        $f10, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f10.u32l;
    // 0x8003FAAC: lwc1        $f4, 0x154($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003FAB0: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003FAB4: nop

    // 0x8003FAB8: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x8003FABC: lwc1        $f8, 0x15C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003FAC0: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8003FAC4: nop

    // 0x8003FAC8: swc1        $f8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f8.u32l;
    // 0x8003FACC: lwc1        $f6, 0x158($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003FAD0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8003FAD4: nop

    // 0x8003FAD8: swc1        $f6, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f6.u32l;
    // 0x8003FADC: lhu         $t3, 0x13A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X13A);
    // 0x8003FAE0: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8003FAE4: nop

    // 0x8003FAE8: sh          $t3, 0x1C($t4)
    MEM_H(0X1C, ctx->r12) = ctx->r11;
    // 0x8003FAEC: lhu         $t2, 0x18A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003FAF0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003FAF4: nop

    // 0x8003FAF8: sh          $t2, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r10;
    // 0x8003FAFC: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x8003FB00: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003FB04: nop

    // 0x8003FB08: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
    // 0x8003FB0C: lhu         $t8, 0x138($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X138);
    // 0x8003FB10: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003FB14: nop

    // 0x8003FB18: sh          $t8, 0x20($t9)
    MEM_H(0X20, ctx->r25) = ctx->r24;
    // 0x8003FB1C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8003FB20: nop

    // 0x8003FB24: lw          $t1, 0x1C8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C8);
    // 0x8003FB28: nop

    // 0x8003FB2C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x8003FB30: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8003FB34: nop

    // 0x8003FB38: bne         $t3, $zero, L_8003EA68
    if (ctx->r11 != 0) {
        // 0x8003FB3C: nop
    
            goto L_8003EA68;
    }
    // 0x8003FB3C: nop

L_8003FB40:
    // 0x8003FB40: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003FB44: lw          $t4, 0x7220($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7220);
    // 0x8003FB48: nop

    // 0x8003FB4C: sw          $t4, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r12;
    // 0x8003FB50: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x8003FB54: nop

    // 0x8003FB58: beq         $t2, $zero, L_800400F8
    if (ctx->r10 == 0) {
        // 0x8003FB5C: nop
    
            goto L_800400F8;
    }
    // 0x8003FB5C: nop

L_8003FB60:
    // 0x8003FB60: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x8003FB64: nop

    // 0x8003FB68: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003FB6C: nop

    // 0x8003FB70: swc1        $f16, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->f16.u32l;
    // 0x8003FB74: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x8003FB78: nop

    // 0x8003FB7C: lwc1        $f18, 0x4($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8003FB80: nop

    // 0x8003FB84: swc1        $f18, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f18.u32l;
    // 0x8003FB88: lw          $t7, 0x134($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X134);
    // 0x8003FB8C: nop

    // 0x8003FB90: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8003FB94: nop

    // 0x8003FB98: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
    // 0x8003FB9C: sh          $zero, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = 0;
    // 0x8003FBA0: lw          $t8, 0x134($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X134);
    // 0x8003FBA4: nop

    // 0x8003FBA8: lhu         $s0, 0x10($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X10);
    // 0x8003FBAC: nop

    // 0x8003FBB0: beq         $s0, $zero, L_8003FBE4
    if (ctx->r16 == 0) {
        // 0x8003FBB4: nop
    
            goto L_8003FBE4;
    }
    // 0x8003FBB4: nop

    // 0x8003FBB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003FBBC: beq         $s0, $at, L_8003FD20
    if (ctx->r16 == ctx->r1) {
        // 0x8003FBC0: nop
    
            goto L_8003FD20;
    }
    // 0x8003FBC0: nop

    // 0x8003FBC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003FBC8: beq         $s0, $at, L_8003FD7C
    if (ctx->r16 == ctx->r1) {
        // 0x8003FBCC: nop
    
            goto L_8003FD7C;
    }
    // 0x8003FBCC: nop

    // 0x8003FBD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FBD4: beq         $s0, $at, L_8003FEA8
    if (ctx->r16 == ctx->r1) {
        // 0x8003FBD8: nop
    
            goto L_8003FEA8;
    }
    // 0x8003FBD8: nop

    // 0x8003FBDC: b           L_8003FF1C
    // 0x8003FBE0: nop

        goto L_8003FF1C;
    // 0x8003FBE0: nop

L_8003FBE4:
    // 0x8003FBE4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003FBE8: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003FBEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003FBF0: lwc1        $f14, -0x73D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003FBF4: lw          $a2, 0x174($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X174);
    // 0x8003FBF8: lw          $a3, 0x170($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X170);
    // 0x8003FBFC: jal         0x800C3C08
    // 0x8003FC00: nop

    MathUtil_GetDistance2D(rdram, ctx);
        goto after_59;
    // 0x8003FC00: nop

    after_59:
    // 0x8003FC04: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003FC08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003FC0C: nop

    // 0x8003FC10: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8003FC14: nop

    // 0x8003FC18: bc1f        L_8003FC44
    if (!c1cs) {
        // 0x8003FC1C: nop
    
            goto L_8003FC44;
    }
    // 0x8003FC1C: nop

    // 0x8003FC20: lw          $t0, 0x134($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X134);
    // 0x8003FC24: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003FC28: sh          $t9, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r25;
    // 0x8003FC2C: jal         0x800220F4
    // 0x8003FC30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800220F4(rdram, ctx);
        goto after_60;
    // 0x8003FC30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_60:
    // 0x8003FC34: jal         0x800B9000
    // 0x8003FC38: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B9000(rdram, ctx);
        goto after_61;
    // 0x8003FC38: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_61:
    // 0x8003FC3C: b           L_8003FD18
    // 0x8003FC40: nop

        goto L_8003FD18;
    // 0x8003FC40: nop

L_8003FC44:
    // 0x8003FC44: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x8003FC48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003FC4C: lhu         $t3, 0x12($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X12);
    // 0x8003FC50: nop

    // 0x8003FC54: bne         $t3, $at, L_8003FD18
    if (ctx->r11 != ctx->r1) {
        // 0x8003FC58: nop
    
            goto L_8003FD18;
    }
    // 0x8003FC58: nop

    // 0x8003FC5C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003FC60: lw          $t4, 0x7240($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7240);
    // 0x8003FC64: nop

    // 0x8003FC68: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x8003FC6C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8003FC70: nop

    // 0x8003FC74: beq         $t2, $zero, L_8003FD18
    if (ctx->r10 == 0) {
        // 0x8003FC78: nop
    
            goto L_8003FD18;
    }
    // 0x8003FC78: nop

L_8003FC7C:
    // 0x8003FC7C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003FC80: lw          $a2, 0x174($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X174);
    // 0x8003FC84: lw          $a3, 0x170($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X170);
    // 0x8003FC88: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003FC8C: lwc1        $f14, 0x4($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8003FC90: jal         0x800C3C08
    // 0x8003FC94: nop

    MathUtil_GetDistance2D(rdram, ctx);
        goto after_62;
    // 0x8003FC94: nop

    after_62:
    // 0x8003FC98: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003FC9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003FCA0: nop

    // 0x8003FCA4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8003FCA8: nop

    // 0x8003FCAC: bc1f        L_8003FCF4
    if (!c1cs) {
        // 0x8003FCB0: nop
    
            goto L_8003FCF4;
    }
    // 0x8003FCB0: nop

    // 0x8003FCB4: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x8003FCB8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FCBC: lhu         $t7, 0x12($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X12);
    // 0x8003FCC0: nop

    // 0x8003FCC4: bne         $t7, $at, L_8003FCD8
    if (ctx->r15 != ctx->r1) {
        // 0x8003FCC8: nop
    
            goto L_8003FCD8;
    }
    // 0x8003FCC8: nop

    // 0x8003FCCC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003FCD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003FCD4: sh          $t8, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = ctx->r24;
L_8003FCD8:
    // 0x8003FCD8: lw          $t0, 0x134($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X134);
    // 0x8003FCDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003FCE0: sh          $t9, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r25;
    // 0x8003FCE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003FCE8: sh          $t1, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r9;
    // 0x8003FCEC: b           L_8003FD18
    // 0x8003FCF0: nop

        goto L_8003FD18;
    // 0x8003FCF0: nop

L_8003FCF4:
    // 0x8003FCF4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8003FCF8: nop

    // 0x8003FCFC: lw          $t4, 0x1C8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C8);
    // 0x8003FD00: nop

    // 0x8003FD04: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x8003FD08: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8003FD0C: nop

    // 0x8003FD10: bne         $t2, $zero, L_8003FC7C
    if (ctx->r10 != 0) {
        // 0x8003FD14: nop
    
            goto L_8003FC7C;
    }
    // 0x8003FD14: nop

L_8003FD18:
    // 0x8003FD18: b           L_8003FF1C
    // 0x8003FD1C: nop

        goto L_8003FF1C;
    // 0x8003FD1C: nop

L_8003FD20:
    // 0x8003FD20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003FD24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003FD28: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003FD2C: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x8003FD30: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003FD34: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003FD38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003FD3C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8003FD40: c.le.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d <= ctx->f10.d;
    // 0x8003FD44: swc1        $f18, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f18.u32l;
    // 0x8003FD48: bc1f        L_8003FD74
    if (!c1cs) {
        // 0x8003FD4C: nop
    
            goto L_8003FD74;
    }
    // 0x8003FD4C: nop

    // 0x8003FD50: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x8003FD54: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8003FD58: sh          $t5, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r13;
    // 0x8003FD5C: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8003FD60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003FD64: nop

    // 0x8003FD68: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
    // 0x8003FD6C: jal         0x800220F4
    // 0x8003FD70: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800220F4(rdram, ctx);
        goto after_63;
    // 0x8003FD70: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_63:
L_8003FD74:
    // 0x8003FD74: b           L_8003FF1C
    // 0x8003FD78: nop

        goto L_8003FF1C;
    // 0x8003FD78: nop

L_8003FD7C:
    // 0x8003FD7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003FD80: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003FD84: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003FD88: lwc1        $f14, -0x73D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003FD8C: lw          $a2, 0x174($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X174);
    // 0x8003FD90: lw          $a3, 0x170($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X170);
    // 0x8003FD94: jal         0x800C3C08
    // 0x8003FD98: nop

    MathUtil_GetDistance2D(rdram, ctx);
        goto after_64;
    // 0x8003FD98: nop

    after_64:
    // 0x8003FD9C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003FDA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003FDA4: nop

    // 0x8003FDA8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8003FDAC: nop

    // 0x8003FDB0: bc1f        L_8003FDC4
    if (!c1cs) {
        // 0x8003FDB4: nop
    
            goto L_8003FDC4;
    }
    // 0x8003FDB4: nop

    // 0x8003FDB8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003FDBC: b           L_8003FDC8
    // 0x8003FDC0: sh          $t7, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r15;
        goto L_8003FDC8;
    // 0x8003FDC0: sh          $t7, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r15;
L_8003FDC4:
    // 0x8003FDC4: sh          $zero, 0x192($sp)
    MEM_H(0X192, ctx->r29) = 0;
L_8003FDC8:
    // 0x8003FDC8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003FDCC: lw          $t8, 0x7240($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7240);
    // 0x8003FDD0: nop

    // 0x8003FDD4: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8003FDD8: sh          $zero, 0x190($sp)
    MEM_H(0X190, ctx->r29) = 0;
    // 0x8003FDDC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003FDE0: nop

    // 0x8003FDE4: beq         $t9, $zero, L_8003FE60
    if (ctx->r25 == 0) {
        // 0x8003FDE8: nop
    
            goto L_8003FE60;
    }
    // 0x8003FDE8: nop

L_8003FDEC:
    // 0x8003FDEC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8003FDF0: lw          $a2, 0x174($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X174);
    // 0x8003FDF4: lw          $a3, 0x170($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X170);
    // 0x8003FDF8: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003FDFC: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8003FE00: jal         0x800C3C08
    // 0x8003FE04: nop

    MathUtil_GetDistance2D(rdram, ctx);
        goto after_65;
    // 0x8003FE04: nop

    after_65:
    // 0x8003FE08: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003FE0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003FE10: nop

    // 0x8003FE14: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003FE18: nop

    // 0x8003FE1C: bc1f        L_8003FE3C
    if (!c1cs) {
        // 0x8003FE20: nop
    
            goto L_8003FE3C;
    }
    // 0x8003FE20: nop

    // 0x8003FE24: lhu         $t1, 0x190($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X190);
    // 0x8003FE28: nop

    // 0x8003FE2C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8003FE30: sh          $t3, 0x190($sp)
    MEM_H(0X190, ctx->r29) = ctx->r11;
    // 0x8003FE34: b           L_8003FE60
    // 0x8003FE38: nop

        goto L_8003FE60;
    // 0x8003FE38: nop

L_8003FE3C:
    // 0x8003FE3C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8003FE40: nop

    // 0x8003FE44: lw          $t2, 0x1C8($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X1C8);
    // 0x8003FE48: nop

    // 0x8003FE4C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8003FE50: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003FE54: nop

    // 0x8003FE58: bne         $t5, $zero, L_8003FDEC
    if (ctx->r13 != 0) {
        // 0x8003FE5C: nop
    
            goto L_8003FDEC;
    }
    // 0x8003FE5C: nop

L_8003FE60:
    // 0x8003FE60: lhu         $t6, 0x190($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X190);
    // 0x8003FE64: nop

    // 0x8003FE68: beq         $t6, $zero, L_8003FE74
    if (ctx->r14 == 0) {
        // 0x8003FE6C: nop
    
            goto L_8003FE74;
    }
    // 0x8003FE6C: nop

    // 0x8003FE70: sh          $zero, 0x192($sp)
    MEM_H(0X192, ctx->r29) = 0;
L_8003FE74:
    // 0x8003FE74: lhu         $t7, 0x192($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X192);
    // 0x8003FE78: nop

    // 0x8003FE7C: beq         $t7, $zero, L_8003FEA0
    if (ctx->r15 == 0) {
        // 0x8003FE80: nop
    
            goto L_8003FEA0;
    }
    // 0x8003FE80: nop

    // 0x8003FE84: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x8003FE88: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003FE8C: sh          $t8, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r24;
    // 0x8003FE90: jal         0x800220F4
    // 0x8003FE94: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800220F4(rdram, ctx);
        goto after_66;
    // 0x8003FE94: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_66:
    // 0x8003FE98: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003FE9C: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
L_8003FEA0:
    // 0x8003FEA0: b           L_8003FF1C
    // 0x8003FEA4: nop

        goto L_8003FF1C;
    // 0x8003FEA4: nop

L_8003FEA8:
    // 0x8003FEA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003FEAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003FEB0: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003FEB4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8003FEB8: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8003FEBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003FEC0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8003FEC4: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8003FEC8: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
    // 0x8003FECC: bc1f        L_8003FF14
    if (!c1cs) {
        // 0x8003FED0: nop
    
            goto L_8003FF14;
    }
    // 0x8003FED0: nop

    // 0x8003FED4: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x8003FED8: nop

    // 0x8003FEDC: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x8003FEE0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003FEE4: nop

    // 0x8003FEE8: swc1        $f16, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f16.u32l;
    // 0x8003FEEC: jal         0x800220F4
    // 0x8003FEF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800220F4(rdram, ctx);
        goto after_67;
    // 0x8003FEF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_67:
    // 0x8003FEF4: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x8003FEF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FEFC: lhu         $t4, 0x12($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X12);
    // 0x8003FF00: nop

    // 0x8003FF04: bne         $t4, $at, L_8003FF14
    if (ctx->r12 != ctx->r1) {
        // 0x8003FF08: nop
    
            goto L_8003FF14;
    }
    // 0x8003FF08: nop

    // 0x8003FF0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003FF10: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
L_8003FF14:
    // 0x8003FF14: b           L_8003FF1C
    // 0x8003FF18: nop

        goto L_8003FF1C;
    // 0x8003FF18: nop

L_8003FF1C:
    // 0x8003FF1C: lhu         $t2, 0x18A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003FF20: nop

    // 0x8003FF24: beq         $t2, $zero, L_8003FFD4
    if (ctx->r10 == 0) {
        // 0x8003FF28: nop
    
            goto L_8003FFD4;
    }
    // 0x8003FF28: nop

    // 0x8003FF2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003FF30: lwc1        $f10, -0x73EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003FF34: lwc1        $f18, 0x174($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003FF38: nop

    // 0x8003FF3C: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8003FF40: swc1        $f4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f4.u32l;
    // 0x8003FF44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003FF48: lwc1        $f6, -0x73D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8003FF4C: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003FF50: nop

    // 0x8003FF54: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8003FF58: swc1        $f16, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f16.u32l;
    // 0x8003FF5C: lwc1        $f18, 0x140($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X140);
    // 0x8003FF60: lwc1        $f4, 0x13C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x8003FF64: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8003FF68: nop

    // 0x8003FF6C: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8003FF70: jal         0x800C42A0
    // 0x8003FF74: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_68;
    // 0x8003FF74: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_68:
    // 0x8003FF78: swc1        $f0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f0.u32l;
    // 0x8003FF7C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8003FF80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003FF84: lwc1        $f6, 0x168($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8003FF88: nop

    // 0x8003FF8C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8003FF90: nop

    // 0x8003FF94: bc1f        L_8003FFAC
    if (!c1cs) {
        // 0x8003FF98: nop
    
            goto L_8003FFAC;
    }
    // 0x8003FF98: nop

    // 0x8003FF9C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8003FFA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003FFA4: nop

    // 0x8003FFA8: swc1        $f18, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f18.u32l;
L_8003FFAC:
    // 0x8003FFAC: lwc1        $f4, 0x140($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X140);
    // 0x8003FFB0: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x8003FFB4: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8003FFB8: lw          $a3, 0x7324($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7324);
    // 0x8003FFBC: lw          $a2, 0x168($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X168);
    // 0x8003FFC0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8003FFC4: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x8003FFC8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003FFCC: jal         0x8003E568
    // 0x8003FFD0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_8003E568(rdram, ctx);
        goto after_69;
    // 0x8003FFD0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_69:
L_8003FFD4:
    // 0x8003FFD4: jal         0x800C1850
    // 0x8003FFD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_70;
    // 0x8003FFD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_70:
    // 0x8003FFDC: lwc1        $f12, 0x174($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003FFE0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003FFE4: lw          $a2, 0x170($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X170);
    // 0x8003FFE8: jal         0x800C2304
    // 0x8003FFEC: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_71;
    // 0x8003FFEC: nop

    after_71:
    // 0x8003FFF0: jal         0x800C2070
    // 0x8003FFF4: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    func_800C2070(rdram, ctx);
        goto after_72;
    // 0x8003FFF4: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    after_72:
    // 0x8003FFF8: lwc1        $f8, 0x16C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003FFFC: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x80040000: nop

    // 0x80040004: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x80040008: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8004000C: lwc1        $f12, 0x30($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X30);
    // 0x80040010: lwc1        $f14, 0x34($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X34);
    // 0x80040014: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80040018: jal         0x800AF1F0
    // 0x8004001C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_800AF1F0(rdram, ctx);
        goto after_73;
    // 0x8004001C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_73:
    // 0x80040020: beq         $v0, $zero, L_800400D4
    if (ctx->r2 == 0) {
        // 0x80040024: nop
    
            goto L_800400D4;
    }
    // 0x80040024: nop

    // 0x80040028: lw          $t7, 0x134($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X134);
    // 0x8004002C: nop

    // 0x80040030: lwc1        $f12, 0x8($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80040034: jal         0x800C25B8
    // 0x80040038: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_74;
    // 0x80040038: nop

    after_74:
    // 0x8004003C: lwc1        $f12, 0x16C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x80040040: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80040044: jal         0x800C2304
    // 0x80040048: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_75;
    // 0x80040048: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_75:
    // 0x8004004C: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x80040050: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80040054: lhu         $t0, 0x12($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X12);
    // 0x80040058: lw          $t8, 0x722C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X722C);
    // 0x8004005C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80040060: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x80040064: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80040068: jal         0x800A42C8
    // 0x8004006C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800A42C8(rdram, ctx);
        goto after_76;
    // 0x8004006C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_76:
    // 0x80040070: lw          $t4, 0x134($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X134);
    // 0x80040074: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80040078: lhu         $t2, 0x12($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X12);
    // 0x8004007C: nop

    // 0x80040080: bne         $t2, $at, L_80040094
    if (ctx->r10 != ctx->r1) {
        // 0x80040084: nop
    
            goto L_80040094;
    }
    // 0x80040084: nop

    // 0x80040088: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8004008C: b           L_8004009C
    // 0x80040090: sh          $t5, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r13;
        goto L_8004009C;
    // 0x80040090: sh          $t5, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r13;
L_80040094:
    // 0x80040094: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80040098: sh          $t6, 0x192($sp)
    MEM_H(0X192, ctx->r29) = ctx->r14;
L_8004009C:
    // 0x8004009C: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800400A0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800400A4: add.s       $f12, $f6, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f6.fl;
    // 0x800400A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800400AC: jal         0x800C2304
    // 0x800400B0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_77;
    // 0x800400B0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_77:
    // 0x800400B4: lhu         $t9, 0x192($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X192);
    // 0x800400B8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800400BC: lw          $t7, 0x722C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X722C);
    // 0x800400C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800400C4: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x800400C8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800400CC: jal         0x800A42C8
    // 0x800400D0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800A42C8(rdram, ctx);
        goto after_78;
    // 0x800400D0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_78:
L_800400D4:
    // 0x800400D4: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x800400D8: nop

    // 0x800400DC: lw          $t3, 0x14($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X14);
    // 0x800400E0: nop

    // 0x800400E4: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    // 0x800400E8: lw          $t4, 0x134($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X134);
    // 0x800400EC: nop

    // 0x800400F0: bne         $t4, $zero, L_8003FB60
    if (ctx->r12 != 0) {
        // 0x800400F4: nop
    
            goto L_8003FB60;
    }
    // 0x800400F4: nop

L_800400F8:
    // 0x800400F8: jal         0x800C1AF4
    // 0x800400FC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_79;
    // 0x800400FC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_79:
    // 0x80040100: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80040104: lw          $t2, 0x71FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71FC);
    // 0x80040108: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004010C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80040110: lwc1        $f16, -0x73D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80040114: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x80040118: lw          $a3, -0x73EC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X73EC);
    // 0x8004011C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80040120: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80040124: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80040128: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004012C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80040130: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80040134: jal         0x800349C0
    // 0x80040138: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800349C0(rdram, ctx);
        goto after_80;
    // 0x80040138: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_80:
    // 0x8004013C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80040140: lw          $t9, 0x724C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X724C);
    // 0x80040144: nop

    // 0x80040148: beq         $t9, $zero, L_80040210
    if (ctx->r25 == 0) {
        // 0x8004014C: sw          $t9, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r25;
            goto L_80040210;
    }
    // 0x8004014C: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80040150: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80040154: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80040158: lbu         $t0, 0xC($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0XC);
    // 0x8004015C: nop

    // 0x80040160: beq         $t0, $at, L_80040210
    if (ctx->r8 == ctx->r1) {
        // 0x80040164: nop
    
            goto L_80040210;
    }
    // 0x80040164: nop

L_80040168:
    // 0x80040168: jal         0x800C1850
    // 0x8004016C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_81;
    // 0x8004016C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_81:
    // 0x80040170: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80040174: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80040178: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8004017C: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x80040180: jal         0x800C2304
    // 0x80040184: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_82;
    // 0x80040184: nop

    after_82:
    // 0x80040188: jal         0x800C2070
    // 0x8004018C: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    func_800C2070(rdram, ctx);
        goto after_83;
    // 0x8004018C: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    after_83:
    // 0x80040190: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x80040194: lwc1        $f12, 0x30($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80040198: lwc1        $f14, 0x34($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8004019C: lw          $a2, 0x38($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X38);
    // 0x800401A0: jal         0x800AF1F0
    // 0x800401A4: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800AF1F0(rdram, ctx);
        goto after_84;
    // 0x800401A4: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_84:
    // 0x800401A8: beq         $v0, $zero, L_800401E8
    if (ctx->r2 == 0) {
        // 0x800401AC: nop
    
            goto L_800401E8;
    }
    // 0x800401AC: nop

    // 0x800401B0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800401B4: nop

    // 0x800401B8: lwc1        $f12, 0x0($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800401BC: jal         0x800C25B8
    // 0x800401C0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_85;
    // 0x800401C0: nop

    after_85:
    // 0x800401C4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800401C8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800401CC: lbu         $t5, 0xC($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XC);
    // 0x800401D0: lw          $t4, 0x722C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X722C);
    // 0x800401D4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800401D8: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x800401DC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800401E0: jal         0x800A42C8
    // 0x800401E4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800A42C8(rdram, ctx);
        goto after_86;
    // 0x800401E4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_86:
L_800401E8:
    // 0x800401E8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800401EC: nop

    // 0x800401F0: addiu       $t0, $t7, 0x10
    ctx->r8 = ADD32(ctx->r15, 0X10);
    // 0x800401F4: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x800401F8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800401FC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80040200: lbu         $t1, 0xC($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0XC);
    // 0x80040204: nop

    // 0x80040208: bne         $t1, $at, L_80040168
    if (ctx->r9 != ctx->r1) {
        // 0x8004020C: nop
    
            goto L_80040168;
    }
    // 0x8004020C: nop

L_80040210:
    // 0x80040210: jal         0x800C1850
    // 0x80040214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_87;
    // 0x80040214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_87:
    // 0x80040218: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004021C: lwc1        $f12, 0x7324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80040220: jal         0x800C25B8
    // 0x80040224: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_88;
    // 0x80040224: nop

    after_88:
    // 0x80040228: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004022C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80040230: jal         0x800C2304
    // 0x80040234: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_89;
    // 0x80040234: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_89:
    // 0x80040238: jal         0x800C1A84
    // 0x8004023C: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_90;
    // 0x8004023C: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    after_90:
    // 0x80040240: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80040244: lwc1        $f18, 0x30($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X30);
    // 0x80040248: nop

    // 0x8004024C: swc1        $f18, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->f18.u32l;
    // 0x80040250: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80040254: lwc1        $f4, 0x38($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X38);
    // 0x80040258: nop

    // 0x8004025C: swc1        $f4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f4.u32l;
    // 0x80040260: sh          $zero, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = 0;
    // 0x80040264: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80040268: lh          $t5, 0x6C0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C0);
    // 0x8004026C: nop

    // 0x80040270: bne         $t5, $zero, L_80040390
    if (ctx->r13 != 0) {
        // 0x80040274: nop
    
            goto L_80040390;
    }
    // 0x80040274: nop

    // 0x80040278: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004027C: lwc1        $f10, 0x50D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80040280: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040284: lwc1        $f8, 0x50D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x80040288: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8004028C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80040290: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80040294: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80040298: c.eq.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d == ctx->f18.d;
    // 0x8004029C: nop

    // 0x800402A0: bc1f        L_80040314
    if (!c1cs) {
        // 0x800402A4: nop
    
            goto L_80040314;
    }
    // 0x800402A4: nop

    // 0x800402A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800402AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800402B0: lwc1        $f4, 0x174($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X174);
    // 0x800402B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800402B8: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800402BC: lwc1        $f6, -0x73EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x800402C0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800402C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800402C8: lwc1        $f18, 0x170($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X170);
    // 0x800402CC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800402D0: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800402D4: lw          $t4, 0x71FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X71FC);
    // 0x800402D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800402DC: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x800402E0: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800402E4: lwc1        $f8, -0x73D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x800402E8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800402EC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800402F0: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800402F4: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x800402F8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800402FC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80040300: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80040304: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80040308: jal         0x800346E4
    // 0x8004030C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800346E4(rdram, ctx);
        goto after_91;
    // 0x8004030C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_91:
    // 0x80040310: sh          $v0, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r2;
L_80040314:
    // 0x80040314: lhu         $t7, 0x18C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X18C);
    // 0x80040318: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004031C: bne         $t7, $at, L_80040390
    if (ctx->r15 != ctx->r1) {
        // 0x80040320: nop
    
            goto L_80040390;
    }
    // 0x80040320: nop

    // 0x80040324: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80040328: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004032C: sh          $t0, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r8;
    // 0x80040330: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80040334: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80040338: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004033C: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
    // 0x80040340: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80040344: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040348: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
    // 0x8004034C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80040350: lh          $t1, 0x7254($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7254);
    // 0x80040354: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040358: ori         $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 | 0X8000;
    // 0x8004035C: sh          $t3, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r11;
    // 0x80040360: addiu       $t2, $zero, 0x3B
    ctx->r10 = ADD32(0, 0X3B);
    // 0x80040364: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040368: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
    // 0x8004036C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80040370: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80040374: sw          $t5, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = ctx->r13;
    // 0x80040378: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8004037C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80040380: sw          $t4, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = ctx->r12;
    // 0x80040384: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80040388: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8004038C: sw          $t6, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = ctx->r14;
L_80040390:
    // 0x80040390: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80040394: lhu         $t9, 0x6C0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X6C0);
    // 0x80040398: nop

    // 0x8004039C: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x800403A0: beq         $at, $zero, L_800405E8
    if (ctx->r1 == 0) {
        // 0x800403A4: nop
    
            goto L_800405E8;
    }
    // 0x800403A4: nop

    // 0x800403A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800403AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800403B0: addu        $at, $at, $t9
    gpr jr_addend_800403BC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800403B4: lw          $t9, -0x1350($at)
    ctx->r25 = ADD32(ctx->r1, -0X1350);
    // 0x800403B8: nop

    // 0x800403BC: jr          $t9
    // 0x800403C0: nop

    switch (jr_addend_800403BC >> 2) {
        case 0: goto L_800403C4; break;
        case 1: goto L_80040418; break;
        case 2: goto L_80040470; break;
        case 3: goto L_8004053C; break;
        case 4: goto L_80040544; break;
        case 5: goto L_800405C4; break;
        default: switch_error(__func__, 0x800403BC, 0x800EECB0);
    }
    // 0x800403C0: nop

L_800403C4:
    // 0x800403C4: lhu         $t7, 0x18C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X18C);
    // 0x800403C8: nop

    // 0x800403CC: beq         $t7, $zero, L_80040410
    if (ctx->r15 == 0) {
        // 0x800403D0: nop
    
            goto L_80040410;
    }
    // 0x800403D0: nop

    // 0x800403D4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800403D8: beq         $t7, $at, L_80040410
    if (ctx->r15 == ctx->r1) {
        // 0x800403DC: nop
    
            goto L_80040410;
    }
    // 0x800403DC: nop

    // 0x800403E0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800403E4: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x800403E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800403EC: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x800403F0: sh          $t8, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r24;
    // 0x800403F4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800403F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800403FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040400: swc1        $f18, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f18.u32l;
    // 0x80040404: lhu         $t1, 0x18C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X18C);
    // 0x80040408: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004040C: sh          $t1, 0x7236($at)
    MEM_H(0X7236, ctx->r1) = ctx->r9;
L_80040410:
    // 0x80040410: b           L_800405E8
    // 0x80040414: nop

        goto L_800405E8;
    // 0x80040414: nop

L_80040418:
    // 0x80040418: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004041C: lwc1        $f4, 0x50C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80040420: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80040424: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80040428: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8004042C: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x80040430: nop

    // 0x80040434: bc1f        L_80040468
    if (!c1cs) {
        // 0x80040438: nop
    
            goto L_80040468;
    }
    // 0x80040438: nop

    // 0x8004043C: jal         0x800B9000
    // 0x80040440: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800B9000(rdram, ctx);
        goto after_92;
    // 0x80040440: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_92:
    // 0x80040444: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80040448: lh          $t3, 0x6C0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X6C0);
    // 0x8004044C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040450: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80040454: sh          $t2, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r10;
    // 0x80040458: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004045C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80040460: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040464: swc1        $f6, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f6.u32l;
L_80040468:
    // 0x80040468: b           L_800405E8
    // 0x8004046C: nop

        goto L_800405E8;
    // 0x8004046C: nop

L_80040470:
    // 0x80040470: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040474: lwc1        $f16, 0x50D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x80040478: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004047C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80040480: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80040484: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x80040488: nop

    // 0x8004048C: bc1f        L_80040534
    if (!c1cs) {
        // 0x80040490: nop
    
            goto L_80040534;
    }
    // 0x80040490: nop

    // 0x80040494: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80040498: lh          $t5, 0x6C0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C0);
    // 0x8004049C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800404A0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800404A4: sh          $t4, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r12;
    // 0x800404A8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800404AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800404B0: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
    // 0x800404B4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800404B8: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x800404BC: lhu         $t7, 0x2($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X2);
    // 0x800404C0: nop

    // 0x800404C4: ori         $t0, $t7, 0x8
    ctx->r8 = ctx->r15 | 0X8;
    // 0x800404C8: sh          $t0, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r8;
    // 0x800404CC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800404D0: lhu         $t8, 0x7236($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7236);
    // 0x800404D4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800404D8: lw          $t3, 0x7214($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7214);
    // 0x800404DC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800404E0: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x800404E4: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x800404E8: addiu       $t5, $t2, -0x3
    ctx->r13 = ADD32(ctx->r10, -0X3);
    // 0x800404EC: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x800404F0: addiu       $t4, $zero, -0x7FF4
    ctx->r12 = ADD32(0, -0X7FF4);
    // 0x800404F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800404F8: sh          $t4, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r12;
    // 0x800404FC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80040500: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040504: sh          $t6, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r14;
    // 0x80040508: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8004050C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040510: lbu         $t0, 0x2($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X2);
    // 0x80040514: nop

    // 0x80040518: sh          $t0, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r8;
    // 0x8004051C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80040520: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040524: sb          $t9, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r25;
    // 0x80040528: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8004052C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040530: sw          $t8, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r24;
L_80040534:
    // 0x80040534: b           L_800405E8
    // 0x80040538: nop

        goto L_800405E8;
    // 0x80040538: nop

L_8004053C:
    // 0x8004053C: b           L_800405E8
    // 0x80040540: nop

        goto L_800405E8;
    // 0x80040540: nop

L_80040544:
    // 0x80040544: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040548: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8004054C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80040550: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80040554: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80040558: c.eq.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d == ctx->f6.d;
    // 0x8004055C: nop

    // 0x80040560: bc1f        L_800405BC
    if (!c1cs) {
        // 0x80040564: nop
    
            goto L_800405BC;
    }
    // 0x80040564: nop

    // 0x80040568: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004056C: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80040570: jal         0x80031728
    // 0x80040574: nop

    func_80031728(rdram, ctx);
        goto after_93;
    // 0x80040574: nop

    after_93:
    // 0x80040578: jal         0x80031874
    // 0x8004057C: nop

    func_80031874(rdram, ctx);
        goto after_94;
    // 0x8004057C: nop

    after_94:
    // 0x80040580: jal         0x80031B6C
    // 0x80040584: nop

    func_80031B6C(rdram, ctx);
        goto after_95;
    // 0x80040584: nop

    after_95:
    // 0x80040588: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004058C: lh          $t3, 0x7268($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7268);
    // 0x80040590: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80040594: lw          $t1, 0x7284($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7284);
    // 0x80040598: bgez        $t3, L_800405A8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8004059C: sra         $t2, $t3, 1
        ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
            goto L_800405A8;
    }
    // 0x8004059C: sra         $t2, $t3, 1
    ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800405A0: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x800405A4: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_800405A8:
    // 0x800405A8: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x800405AC: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x800405B0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x800405B4: jal         0x800319B0
    // 0x800405B8: nop

    func_800319B0(rdram, ctx);
        goto after_96;
    // 0x800405B8: nop

    after_96:
L_800405BC:
    // 0x800405BC: b           L_800405E8
    // 0x800405C0: nop

        goto L_800405E8;
    // 0x800405C0: nop

L_800405C4:
    // 0x800405C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800405C8: lwc1        $f16, 0x720C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x800405CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800405D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800405D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800405D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800405DC: swc1        $f4, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f4.u32l;
    // 0x800405E0: b           L_800405E8
    // 0x800405E4: nop

        goto L_800405E8;
    // 0x800405E4: nop

L_800405E8:
    // 0x800405E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800405EC: lwc1        $f10, 0x50D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x800405F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800405F4: lwc1        $f8, 0x50D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x800405F8: nop

    // 0x800405FC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80040600: swc1        $f6, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f6.u32l;
    // 0x80040604: lwc1        $f16, 0x178($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80040608: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004060C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80040610: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80040614: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x80040618: nop

    // 0x8004061C: bc1f        L_80040694
    if (!c1cs) {
        // 0x80040620: nop
    
            goto L_80040694;
    }
    // 0x80040620: nop

    // 0x80040624: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040628: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8004062C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040630: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80040634: nop

    // 0x80040638: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8004063C: nop

    // 0x80040640: bc1f        L_80040694
    if (!c1cs) {
        // 0x80040644: nop
    
            goto L_80040694;
    }
    // 0x80040644: nop

    // 0x80040648: lwc1        $f6, 0x17C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8004064C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80040650: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80040654: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80040658: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8004065C: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x80040660: nop

    // 0x80040664: bc1f        L_80040694
    if (!c1cs) {
        // 0x80040668: nop
    
            goto L_80040694;
    }
    // 0x80040668: nop

    // 0x8004066C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040670: lwc1        $f4, 0x50C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80040674: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80040678: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004067C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80040680: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80040684: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x80040688: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004068C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80040690: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
L_80040694:
    // 0x80040694: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040698: lwc1        $f4, 0x50C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8004069C: lwc1        $f18, 0x178($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800406A0: nop

    // 0x800406A4: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800406A8: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x800406AC: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800406B0: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x800406B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800406B8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800406BC: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x800406C0: nop

    // 0x800406C4: bc1f        L_80040718
    if (!c1cs) {
        // 0x800406C8: nop
    
            goto L_80040718;
    }
    // 0x800406C8: nop

    // 0x800406CC: lwc1        $f18, 0x180($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X180);
    // 0x800406D0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800406D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800406D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800406DC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800406E0: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x800406E4: nop

    // 0x800406E8: bc1f        L_80040718
    if (!c1cs) {
        // 0x800406EC: nop
    
            goto L_80040718;
    }
    // 0x800406EC: nop

    // 0x800406F0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800406F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800406F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800406FC: swc1        $f8, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f8.u32l;
    // 0x80040700: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040704: lwc1        $f6, -0x3A80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x80040708: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
    // 0x8004070C: add.s       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80040710: swc1        $f20, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f20.u32l;
    // 0x80040714: swc1        $f16, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f16.u32l;
L_80040718:
    // 0x80040718: lwc1        $f18, 0x178($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8004071C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80040720: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80040724: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80040728: c.eq.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d == ctx->f10.d;
    // 0x8004072C: nop

    // 0x80040730: bc1f        L_80040784
    if (!c1cs) {
        // 0x80040734: nop
    
            goto L_80040784;
    }
    // 0x80040734: nop

    // 0x80040738: lwc1        $f8, 0x180($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X180);
    // 0x8004073C: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80040740: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80040744: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80040748: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004074C: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x80040750: nop

    // 0x80040754: bc1f        L_80040784
    if (!c1cs) {
        // 0x80040758: nop
    
            goto L_80040784;
    }
    // 0x80040758: nop

    // 0x8004075C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80040760: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80040764: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040768: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x8004076C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040770: lwc1        $f4, -0x3A7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x80040774: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
    // 0x80040778: add.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8004077C: swc1        $f20, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f20.u32l;
    // 0x80040780: swc1        $f10, -0x3A7C($at)
    MEM_W(-0X3A7C, ctx->r1) = ctx->f10.u32l;
L_80040784:
    // 0x80040784: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80040788: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8004078C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80040790: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80040794: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x80040798: nop

    // 0x8004079C: bc1f        L_800407E4
    if (!c1cs) {
        // 0x800407A0: nop
    
            goto L_800407E4;
    }
    // 0x800407A0: nop

    // 0x800407A4: lwc1        $f18, 0x17C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x800407A8: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800407AC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800407B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800407B4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800407B8: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x800407BC: nop

    // 0x800407C0: bc1f        L_800407E4
    if (!c1cs) {
        // 0x800407C4: nop
    
            goto L_800407E4;
    }
    // 0x800407C4: nop

    // 0x800407C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800407CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800407D0: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800407D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800407D8: add.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800407DC: swc1        $f20, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f20.u32l;
    // 0x800407E0: swc1        $f6, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f6.u32l;
L_800407E4:
    // 0x800407E4: lwc1        $f16, 0x178($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800407E8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800407EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800407F0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800407F4: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x800407F8: nop

    // 0x800407FC: bc1f        L_800408C4
    if (!c1cs) {
        // 0x80040800: nop
    
            goto L_800408C4;
    }
    // 0x80040800: nop

    // 0x80040804: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80040808: lhu         $t6, 0x70E0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X70E0);
    // 0x8004080C: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80040810: beq         $t6, $at, L_800408C4
    if (ctx->r14 == ctx->r1) {
        // 0x80040814: nop
    
            goto L_800408C4;
    }
    // 0x80040814: nop

    // 0x80040818: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004081C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040820: lwc1        $f10, 0x17C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x80040824: nop

    // 0x80040828: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8004082C: nop

    // 0x80040830: bc1f        L_800408C4
    if (!c1cs) {
        // 0x80040834: nop
    
            goto L_800408C4;
    }
    // 0x80040834: nop

    // 0x80040838: lwc1        $f6, 0x180($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X180);
    // 0x8004083C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80040840: nop

    // 0x80040844: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80040848: nop

    // 0x8004084C: bc1f        L_8004085C
    if (!c1cs) {
        // 0x80040850: nop
    
            goto L_8004085C;
    }
    // 0x80040850: nop

    // 0x80040854: b           L_80040868
    // 0x80040858: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
        goto L_80040868;
    // 0x80040858: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
L_8004085C:
    // 0x8004085C: lwc1        $f20, 0x180($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X180);
    // 0x80040860: nop

    // 0x80040864: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80040868:
    // 0x80040868: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004086C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80040870: nop

    // 0x80040874: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x80040878: nop

    // 0x8004087C: bc1f        L_800408C4
    if (!c1cs) {
        // 0x80040880: nop
    
            goto L_800408C4;
    }
    // 0x80040880: nop

    // 0x80040884: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80040888: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004088C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80040890: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80040894: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x80040898: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x8004089C: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800408A0: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x800408A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800408A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800408AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800408B0: jal         0x800B1F0C
    // 0x800408B4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_97;
    // 0x800408B4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_97:
    // 0x800408B8: addiu       $t7, $zero, 0x27
    ctx->r15 = ADD32(0, 0X27);
    // 0x800408BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800408C0: sh          $t7, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r15;
L_800408C4:
    // 0x800408C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800408C8: lwc1        $f8, 0x50D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x800408CC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800408D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800408D4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800408D8: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x800408DC: nop

    // 0x800408E0: bc1t        L_800409D4
    if (c1cs) {
        // 0x800408E4: nop
    
            goto L_800409D4;
    }
    // 0x800408E4: nop

    // 0x800408E8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800408EC: lhu         $t0, 0x70E0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X70E0);
    // 0x800408F0: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x800408F4: beq         $t0, $at, L_8004093C
    if (ctx->r8 == ctx->r1) {
        // 0x800408F8: nop
    
            goto L_8004093C;
    }
    // 0x800408F8: nop

    // 0x800408FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80040900: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80040904: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80040908: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8004090C: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x80040910: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x80040914: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80040918: ori         $a2, $a2, 0x59
    ctx->r6 = ctx->r6 | 0X59;
    // 0x8004091C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80040920: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80040924: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80040928: jal         0x800B1F0C
    // 0x8004092C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_98;
    // 0x8004092C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_98:
    // 0x80040930: addiu       $t9, $zero, 0x59
    ctx->r25 = ADD32(0, 0X59);
    // 0x80040934: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040938: sh          $t9, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r25;
L_8004093C:
    // 0x8004093C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040940: lwc1        $f10, 0x50D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x80040944: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80040948: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8004094C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80040950: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80040954: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80040958: nop

    // 0x8004095C: bc1f        L_80040984
    if (!c1cs) {
        // 0x80040960: nop
    
            goto L_80040984;
    }
    // 0x80040960: nop

    // 0x80040964: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040968: lwc1        $f6, 0x50D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8004096C: nop

    // 0x80040970: swc1        $f6, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f6.u32l;
    // 0x80040974: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80040978: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004097C: b           L_800409BC
    // 0x80040980: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
        goto L_800409BC;
    // 0x80040980: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
L_80040984:
    // 0x80040984: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040988: lwc1        $f4, 0x50D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8004098C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80040990: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80040994: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80040998: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8004099C: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x800409A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800409A4: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x800409A8: swc1        $f6, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f6.u32l;
    // 0x800409AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800409B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800409B4: nop

    // 0x800409B8: swc1        $f18, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f18.u32l;
L_800409BC:
    // 0x800409BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800409C0: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x800409C4: lwc1        $f10, 0x178($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800409C8: nop

    // 0x800409CC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800409D0: swc1        $f8, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f8.u32l;
L_800409D4:
    // 0x800409D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800409D8: lwc1        $f16, 0x50D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x800409DC: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800409E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800409E4: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x800409E8: c.eq.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d == ctx->f18.d;
    // 0x800409EC: nop

    // 0x800409F0: bc1t        L_80040AE8
    if (c1cs) {
        // 0x800409F4: nop
    
            goto L_80040AE8;
    }
    // 0x800409F4: nop

    // 0x800409F8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800409FC: lhu         $t8, 0x70E0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X70E0);
    // 0x80040A00: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x80040A04: beq         $t8, $at, L_80040A50
    if (ctx->r24 == ctx->r1) {
        // 0x80040A08: nop
    
            goto L_80040A50;
    }
    // 0x80040A08: nop

    // 0x80040A0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80040A10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80040A14: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80040A18: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80040A1C: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x80040A20: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x80040A24: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80040A28: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80040A2C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80040A30: ori         $a2, $a2, 0x59
    ctx->r6 = ctx->r6 | 0X59;
    // 0x80040A34: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80040A38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80040A3C: jal         0x800B1F0C
    // 0x80040A40: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_99;
    // 0x80040A40: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_99:
    // 0x80040A44: addiu       $t2, $zero, 0x59
    ctx->r10 = ADD32(0, 0X59);
    // 0x80040A48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040A4C: sh          $t2, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r10;
L_80040A50:
    // 0x80040A50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040A54: lwc1        $f8, 0x50D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80040A58: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80040A5C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80040A60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80040A64: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80040A68: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x80040A6C: nop

    // 0x80040A70: bc1f        L_80040A98
    if (!c1cs) {
        // 0x80040A74: nop
    
            goto L_80040A98;
    }
    // 0x80040A74: nop

    // 0x80040A78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040A7C: lwc1        $f18, 0x50D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80040A80: nop

    // 0x80040A84: swc1        $f18, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f18.u32l;
    // 0x80040A88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80040A8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040A90: b           L_80040AD0
    // 0x80040A94: swc1        $f4, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f4.u32l;
        goto L_80040AD0;
    // 0x80040A94: swc1        $f4, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f4.u32l;
L_80040A98:
    // 0x80040A98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040A9C: lwc1        $f10, 0x50D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80040AA0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80040AA4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80040AA8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80040AAC: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80040AB0: sub.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d - ctx->f16.d;
    // 0x80040AB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040AB8: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80040ABC: swc1        $f18, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f18.u32l;
    // 0x80040AC0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80040AC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040AC8: nop

    // 0x80040ACC: swc1        $f4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f4.u32l;
L_80040AD0:
    // 0x80040AD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040AD4: lwc1        $f10, 0x7324($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80040AD8: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80040ADC: nop

    // 0x80040AE0: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80040AE4: swc1        $f16, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f16.u32l;
L_80040AE8:
    // 0x80040AE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040AEC: lwc1        $f6, 0x7324($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80040AF0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80040AF4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80040AF8: nop

    // 0x80040AFC: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x80040B00: nop

    // 0x80040B04: bc1f        L_80040B2C
    if (!c1cs) {
        // 0x80040B08: nop
    
            goto L_80040B2C;
    }
    // 0x80040B08: nop

    // 0x80040B0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040B10: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80040B14: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80040B18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80040B1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040B20: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80040B24: b           L_80040B68
    // 0x80040B28: swc1        $f8, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f8.u32l;
        goto L_80040B68;
    // 0x80040B28: swc1        $f8, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f8.u32l;
L_80040B2C:
    // 0x80040B2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040B30: lwc1        $f16, 0x7324($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80040B34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80040B38: nop

    // 0x80040B3C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80040B40: nop

    // 0x80040B44: bc1f        L_80040B68
    if (!c1cs) {
        // 0x80040B48: nop
    
            goto L_80040B68;
    }
    // 0x80040B48: nop

    // 0x80040B4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040B50: lwc1        $f18, 0x7324($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80040B54: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80040B58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040B5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040B60: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80040B64: swc1        $f10, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f10.u32l;
L_80040B68:
    // 0x80040B68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040B6C: lwc1        $f8, 0x50C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80040B70: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80040B74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80040B78: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80040B7C: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x80040B80: nop

    // 0x80040B84: bc1t        L_80040CE0
    if (c1cs) {
        // 0x80040B88: nop
    
            goto L_80040CE0;
    }
    // 0x80040B88: nop

    // 0x80040B8C: lhu         $t1, 0x18C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X18C);
    // 0x80040B90: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80040B94: bne         $t1, $at, L_80040BEC
    if (ctx->r9 != ctx->r1) {
        // 0x80040B98: nop
    
            goto L_80040BEC;
    }
    // 0x80040B98: nop

    // 0x80040B9C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80040BA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80040BA4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80040BA8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80040BAC: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x80040BB0: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x80040BB4: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80040BB8: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x80040BBC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80040BC0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80040BC4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80040BC8: jal         0x800B1F0C
    // 0x80040BCC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_100;
    // 0x80040BCC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_100:
    // 0x80040BD0: addiu       $t5, $zero, 0x27
    ctx->r13 = ADD32(0, 0X27);
    // 0x80040BD4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040BD8: sh          $t5, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r13;
    // 0x80040BDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80040BE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040BE4: b           L_80040C40
    // 0x80040BE8: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
        goto L_80040C40;
    // 0x80040BE8: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
L_80040BEC:
    // 0x80040BEC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80040BF0: lhu         $t4, 0x70E0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X70E0);
    // 0x80040BF4: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80040BF8: beq         $t4, $at, L_80040C40
    if (ctx->r12 == ctx->r1) {
        // 0x80040BFC: nop
    
            goto L_80040C40;
    }
    // 0x80040BFC: nop

    // 0x80040C00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80040C04: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80040C08: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80040C0C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80040C10: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x80040C14: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x80040C18: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80040C1C: ori         $a2, $a2, 0x90
    ctx->r6 = ctx->r6 | 0X90;
    // 0x80040C20: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80040C24: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80040C28: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80040C2C: jal         0x800B1F0C
    // 0x80040C30: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_101;
    // 0x80040C30: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_101:
    // 0x80040C34: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x80040C38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040C3C: sh          $t6, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r14;
L_80040C40:
    // 0x80040C40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040C44: lwc1        $f6, 0x50C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80040C48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040C4C: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80040C50: nop

    // 0x80040C54: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80040C58: nop

    // 0x80040C5C: bc1f        L_80040C84
    if (!c1cs) {
        // 0x80040C60: nop
    
            goto L_80040C84;
    }
    // 0x80040C60: nop

    // 0x80040C64: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040C68: lwc1        $f4, 0x50C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80040C6C: nop

    // 0x80040C70: swc1        $f4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f4.u32l;
    // 0x80040C74: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80040C78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040C7C: b           L_80040CA0
    // 0x80040C80: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
        goto L_80040CA0;
    // 0x80040C80: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
L_80040C84:
    // 0x80040C84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040C88: lwc1        $f20, 0x257C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80040C8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040C90: lwc1        $f8, 0x50C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80040C94: swc1        $f20, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f20.u32l;
    // 0x80040C98: sub.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x80040C9C: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
L_80040CA0:
    // 0x80040CA0: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80040CA4: lwc1        $f18, 0x174($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X174);
    // 0x80040CA8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040CAC: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80040CB0: lwc1        $f10, -0x73EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80040CB4: nop

    // 0x80040CB8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80040CBC: swc1        $f8, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f8.u32l;
    // 0x80040CC0: lwc1        $f16, 0x178($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80040CC4: lwc1        $f6, 0x170($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X170);
    // 0x80040CC8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040CCC: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80040CD0: lwc1        $f10, -0x73D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80040CD4: nop

    // 0x80040CD8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80040CDC: swc1        $f4, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f4.u32l;
L_80040CE0:
    // 0x80040CE0: jal         0x800C1A28
    // 0x80040CE4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_102;
    // 0x80040CE4: nop

    after_102:
    // 0x80040CE8: b           L_80040CF0
    // 0x80040CEC: nop

        goto L_80040CF0;
    // 0x80040CEC: nop

L_80040CF0:
    // 0x80040CF0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80040CF4: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80040CF8: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80040CFC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80040D00: jr          $ra
    // 0x80040D04: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    return;
    // 0x80040D04: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
;}
RECOMP_FUNC void func_80071730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071730: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071734: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071738: nop

    // 0x8007173C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80071740: nop

    // 0x80071744: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071748: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007174C: jr          $ra
    // 0x80071750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071754: jr          $ra
    // 0x80071758: nop

    return;
    // 0x80071758: nop

    // 0x8007175C: jr          $ra
    // 0x80071760: nop

    return;
    // 0x80071760: nop

;}
RECOMP_FUNC void func_80074AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074AD8: jal         0x80061488
    // 0x80074ADC: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80074ADC: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    after_0:
    // 0x80074AE0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80074AE4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80074AE8: b           L_80074AF8
    // 0x80074AEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80074AF8;
    // 0x80074AEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074AF0: b           L_80074AF8
    // 0x80074AF4: nop

        goto L_80074AF8;
    // 0x80074AF4: nop

L_80074AF8:
    // 0x80074AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074B00: jr          $ra
    // 0x80074B04: nop

    return;
    // 0x80074B04: nop

;}
RECOMP_FUNC void func_800B8398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8398: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B839C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B83A0: sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // 0x800B83A4: jal         0x80016074
    // 0x800B83A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800B83A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x800B83AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B83B0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B83B4: nop

    // 0x800B83B8: beq         $t6, $zero, L_800B83EC
    if (ctx->r14 == 0) {
        // 0x800B83BC: nop
    
            goto L_800B83EC;
    }
    // 0x800B83BC: nop

    // 0x800B83C0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B83C4: nop

    // 0x800B83C8: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x800B83CC: nop

    // 0x800B83D0: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800B83D4: bne         $t9, $zero, L_800B83EC
    if (ctx->r25 != 0) {
        // 0x800B83D8: nop
    
            goto L_800B83EC;
    }
    // 0x800B83D8: nop

    // 0x800B83DC: lhu         $t0, 0x1A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B83E0: nop

    // 0x800B83E4: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x800B83E8: sh          $t1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r9;
L_800B83EC:
    // 0x800B83EC: jal         0x80016074
    // 0x800B83F0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80016074(rdram, ctx);
        goto after_1;
    // 0x800B83F0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x800B83F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B83F8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B83FC: nop

    // 0x800B8400: beq         $t2, $zero, L_800B8434
    if (ctx->r10 == 0) {
        // 0x800B8404: nop
    
            goto L_800B8434;
    }
    // 0x800B8404: nop

    // 0x800B8408: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B840C: nop

    // 0x800B8410: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x800B8414: nop

    // 0x800B8418: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800B841C: bne         $t5, $zero, L_800B8434
    if (ctx->r13 != 0) {
        // 0x800B8420: nop
    
            goto L_800B8434;
    }
    // 0x800B8420: nop

    // 0x800B8424: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B8428: nop

    // 0x800B842C: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x800B8430: sh          $t7, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r15;
L_800B8434:
    // 0x800B8434: jal         0x80016074
    // 0x800B8438: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_2;
    // 0x800B8438: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x800B843C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B8440: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8444: nop

    // 0x800B8448: beq         $t8, $zero, L_800B847C
    if (ctx->r24 == 0) {
        // 0x800B844C: nop
    
            goto L_800B847C;
    }
    // 0x800B844C: nop

    // 0x800B8450: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8454: nop

    // 0x800B8458: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x800B845C: nop

    // 0x800B8460: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800B8464: bne         $t1, $zero, L_800B847C
    if (ctx->r9 != 0) {
        // 0x800B8468: nop
    
            goto L_800B847C;
    }
    // 0x800B8468: nop

    // 0x800B846C: lhu         $t2, 0x1A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B8470: nop

    // 0x800B8474: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x800B8478: sh          $t3, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r11;
L_800B847C:
    // 0x800B847C: jal         0x80016074
    // 0x800B8480: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_3;
    // 0x800B8480: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_3:
    // 0x800B8484: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B8488: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B848C: nop

    // 0x800B8490: beq         $t4, $zero, L_800B84C4
    if (ctx->r12 == 0) {
        // 0x800B8494: nop
    
            goto L_800B84C4;
    }
    // 0x800B8494: nop

    // 0x800B8498: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B849C: nop

    // 0x800B84A0: lw          $t6, 0x1A8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1A8);
    // 0x800B84A4: nop

    // 0x800B84A8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x800B84AC: bne         $t7, $zero, L_800B84C4
    if (ctx->r15 != 0) {
        // 0x800B84B0: nop
    
            goto L_800B84C4;
    }
    // 0x800B84B0: nop

    // 0x800B84B4: lhu         $t8, 0x1A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B84B8: nop

    // 0x800B84BC: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x800B84C0: sh          $t9, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r25;
L_800B84C4:
    // 0x800B84C4: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B84C8: b           L_800B84D8
    // 0x800B84CC: nop

        goto L_800B84D8;
    // 0x800B84CC: nop

    // 0x800B84D0: b           L_800B84D8
    // 0x800B84D4: nop

        goto L_800B84D8;
    // 0x800B84D4: nop

L_800B84D8:
    // 0x800B84D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B84DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B84E0: jr          $ra
    // 0x800B84E4: nop

    return;
    // 0x800B84E4: nop

    // 0x800B84E8: nop

    // 0x800B84EC: nop

;}
RECOMP_FUNC void func_800A7230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A723C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A7240: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A7244: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800A7248: nop

    // 0x800A724C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800A7250: bne         $t8, $zero, L_800A7260
    if (ctx->r24 != 0) {
        // 0x800A7254: nop
    
            goto L_800A7260;
    }
    // 0x800A7254: nop

    // 0x800A7258: b           L_800A72AC
    // 0x800A725C: nop

        goto L_800A72AC;
    // 0x800A725C: nop

L_800A7260:
    // 0x800A7260: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800A7264: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A7268: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800A726C: lwc1        $f4, 0xCC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800A7270: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A7274: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800A7278: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A727C: lwc1        $f8, 0xD0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x800A7280: lwc1        $f10, 0xE4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XE4);
    // 0x800A7284: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A7288: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A728C: lwc1        $f4, 0xD4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XD4);
    // 0x800A7290: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A7294: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A7298: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800A729C: jal         0x800C2304
    // 0x800A72A0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_0;
    // 0x800A72A0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x800A72A4: b           L_800A72AC
    // 0x800A72A8: nop

        goto L_800A72AC;
    // 0x800A72A8: nop

L_800A72AC:
    // 0x800A72AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A72B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A72B4: jr          $ra
    // 0x800A72B8: nop

    return;
    // 0x800A72B8: nop

;}
RECOMP_FUNC void func_8001DC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001DC04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DC08: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001DC0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DC10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001DC14: jal         0x8008EAA8
    // 0x8001DC18: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001DC18: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8001DC1C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001DC20: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DC24: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001DC28: jal         0x8008ECE4
    // 0x8001DC2C: addiu       $a0, $a0, -0x2660
    ctx->r4 = ADD32(ctx->r4, -0X2660);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001DC2C: addiu       $a0, $a0, -0x2660
    ctx->r4 = ADD32(ctx->r4, -0X2660);
    after_1:
    // 0x8001DC30: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001DC34: lw          $t7, 0x6B98($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6B98);
    // 0x8001DC38: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DC3C: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DC40: sw          $t7, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r15;
    // 0x8001DC44: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001DC48: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x8001DC4C: nop

    // 0x8001DC50: beq         $s0, $zero, L_8001DC6C
    if (ctx->r16 == 0) {
        // 0x8001DC54: nop
    
            goto L_8001DC6C;
    }
    // 0x8001DC54: nop

    // 0x8001DC58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001DC5C: beq         $s0, $at, L_8001DCC8
    if (ctx->r16 == ctx->r1) {
        // 0x8001DC60: nop
    
            goto L_8001DCC8;
    }
    // 0x8001DC60: nop

    // 0x8001DC64: b           L_8001E2E8
    // 0x8001DC68: nop

        goto L_8001E2E8;
    // 0x8001DC68: nop

L_8001DC6C:
    // 0x8001DC6C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001DC70: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001DC74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001DC78: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8001DC7C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001DC80: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001DC84: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001DC88: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8001DC8C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DC90: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001DC94: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x8001DC98: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001DC9C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001DCA0: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x8001DCA4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001DCA8: lw          $t5, -0x4DB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4DB8);
    // 0x8001DCAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DCB0: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001DCB4: sw          $t5, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r13;
    // 0x8001DCB8: lui         $t7, 0x7FFF
    ctx->r15 = S32(0X7FFF << 16);
    // 0x8001DCBC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8001DCC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001DCC4: sw          $t7, -0x4DB8($at)
    MEM_W(-0X4DB8, ctx->r1) = ctx->r15;
L_8001DCC8:
    // 0x8001DCC8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001DCCC: jal         0x8008EAA8
    // 0x8001DCD0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8001DCD0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8001DCD4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DCD8: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DCDC: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8001DCE0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001DCE4: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8001DCE8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001DCEC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001DCF0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8001DCF4: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8001DCF8: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x8001DCFC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DD00: jal         0x8008ECE4
    // 0x8001DD04: addiu       $a0, $a0, -0x2654
    ctx->r4 = ADD32(ctx->r4, -0X2654);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001DD04: addiu       $a0, $a0, -0x2654
    ctx->r4 = ADD32(ctx->r4, -0X2654);
    after_3:
    // 0x8001DD08: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001DD0C: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001DD10: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DD14: lhu         $t3, 0x101C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X101C);
    // 0x8001DD18: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001DD1C: nop

    // 0x8001DD20: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001DD24: beq         $t4, $zero, L_8001DD44
    if (ctx->r12 == 0) {
        // 0x8001DD28: nop
    
            goto L_8001DD44;
    }
    // 0x8001DD28: nop

    // 0x8001DD2C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001DD30: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001DD34: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8001DD38: nop

    // 0x8001DD3C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8001DD40: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
L_8001DD44:
    // 0x8001DD44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001DD48: jal         0x8008EAA8
    // 0x8001DD4C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x8001DD4C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_4:
    // 0x8001DD50: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DD54: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DD58: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8001DD5C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001DD60: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8001DD64: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001DD68: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001DD6C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8001DD70: nop

    // 0x8001DD74: bne         $t1, $zero, L_8001DE08
    if (ctx->r9 != 0) {
        // 0x8001DD78: nop
    
            goto L_8001DE08;
    }
    // 0x8001DD78: nop

    // 0x8001DD7C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DD80: jal         0x8008ECE4
    // 0x8001DD84: addiu       $a0, $a0, -0x2640
    ctx->r4 = ADD32(ctx->r4, -0X2640);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8001DD84: addiu       $a0, $a0, -0x2640
    ctx->r4 = ADD32(ctx->r4, -0X2640);
    after_5:
    // 0x8001DD88: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001DD8C: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001DD90: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001DD94: lhu         $t4, 0x1260($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1260);
    // 0x8001DD98: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x8001DD9C: nop

    // 0x8001DDA0: and         $t6, $t3, $t4
    ctx->r14 = ctx->r11 & ctx->r12;
    // 0x8001DDA4: beq         $t6, $zero, L_8001DDC4
    if (ctx->r14 == 0) {
        // 0x8001DDA8: nop
    
            goto L_8001DDC4;
    }
    // 0x8001DDA8: nop

    // 0x8001DDAC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001DDB0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001DDB4: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x8001DDB8: nop

    // 0x8001DDBC: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8001DDC0: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
L_8001DDC4:
    // 0x8001DDC4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001DDC8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001DDCC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001DDD0: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001DDD4: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001DDD8: nop

    // 0x8001DDDC: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001DDE0: beq         $t2, $zero, L_8001DE00
    if (ctx->r10 == 0) {
        // 0x8001DDE4: nop
    
            goto L_8001DE00;
    }
    // 0x8001DDE4: nop

    // 0x8001DDE8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DDEC: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001DDF0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8001DDF4: nop

    // 0x8001DDF8: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8001DDFC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_8001DE00:
    // 0x8001DE00: b           L_8001DE8C
    // 0x8001DE04: nop

        goto L_8001DE8C;
    // 0x8001DE04: nop

L_8001DE08:
    // 0x8001DE08: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DE0C: jal         0x8008ECE4
    // 0x8001DE10: addiu       $a0, $a0, -0x2634
    ctx->r4 = ADD32(ctx->r4, -0X2634);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8001DE10: addiu       $a0, $a0, -0x2634
    ctx->r4 = ADD32(ctx->r4, -0X2634);
    after_6:
    // 0x8001DE14: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001DE18: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001DE1C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001DE20: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001DE24: lhu         $t8, 0x8($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X8);
    // 0x8001DE28: nop

    // 0x8001DE2C: and         $t9, $t8, $t7
    ctx->r25 = ctx->r24 & ctx->r15;
    // 0x8001DE30: beq         $t9, $zero, L_8001DE50
    if (ctx->r25 == 0) {
        // 0x8001DE34: nop
    
            goto L_8001DE50;
    }
    // 0x8001DE34: nop

    // 0x8001DE38: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001DE3C: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001DE40: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8001DE44: nop

    // 0x8001DE48: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8001DE4C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
L_8001DE50:
    // 0x8001DE50: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001DE54: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8001DE58: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DE5C: lhu         $t3, 0x1258($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1258);
    // 0x8001DE60: lhu         $t6, 0x8($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X8);
    // 0x8001DE64: nop

    // 0x8001DE68: and         $t5, $t6, $t3
    ctx->r13 = ctx->r14 & ctx->r11;
    // 0x8001DE6C: beq         $t5, $zero, L_8001DE8C
    if (ctx->r13 == 0) {
        // 0x8001DE70: nop
    
            goto L_8001DE8C;
    }
    // 0x8001DE70: nop

    // 0x8001DE74: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DE78: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DE7C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8001DE80: nop

    // 0x8001DE84: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8001DE88: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
L_8001DE8C:
    // 0x8001DE8C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001DE90: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001DE94: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001DE98: nop

    // 0x8001DE9C: bgtz        $t2, L_8001DEB4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8001DEA0: nop
    
            goto L_8001DEB4;
    }
    // 0x8001DEA0: nop

    // 0x8001DEA4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001DEA8: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001DEAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001DEB0: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_8001DEB4:
    // 0x8001DEB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DEB8: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001DEBC: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8001DEC0: nop

    // 0x8001DEC4: bgtz        $t3, L_8001DEDC
    if (SIGNED(ctx->r11) > 0) {
        // 0x8001DEC8: nop
    
            goto L_8001DEDC;
    }
    // 0x8001DEC8: nop

    // 0x8001DECC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001DED0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001DED4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001DED8: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
L_8001DEDC:
    // 0x8001DEDC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001DEE0: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001DEE4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001DEE8: lhu         $t1, 0xFF4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XFF4);
    // 0x8001DEEC: lhu         $t8, 0x8($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X8);
    // 0x8001DEF0: nop

    // 0x8001DEF4: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001DEF8: beq         $t2, $zero, L_8001DF18
    if (ctx->r10 == 0) {
        // 0x8001DEFC: nop
    
            goto L_8001DF18;
    }
    // 0x8001DEFC: nop

    // 0x8001DF00: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DF04: lbu         $a0, 0x1918($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1918);
    // 0x8001DF08: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8001DF0C: addiu       $a1, $a1, -0x820
    ctx->r5 = ADD32(ctx->r5, -0X820);
    // 0x8001DF10: jal         0x800C1264
    // 0x8001DF14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_7;
    // 0x8001DF14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
L_8001DF18:
    // 0x8001DF18: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001DF1C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001DF20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DF24: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8001DF28: lhu         $t4, 0x6($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X6);
    // 0x8001DF2C: nop

    // 0x8001DF30: and         $t3, $t4, $t6
    ctx->r11 = ctx->r12 & ctx->r14;
    // 0x8001DF34: beq         $t3, $zero, L_8001DF54
    if (ctx->r11 == 0) {
        // 0x8001DF38: nop
    
            goto L_8001DF54;
    }
    // 0x8001DF38: nop

    // 0x8001DF3C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001DF40: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001DF44: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8001DF48: nop

    // 0x8001DF4C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8001DF50: sw          $t9, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r25;
L_8001DF54:
    // 0x8001DF54: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DF58: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DF5C: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // 0x8001DF60: nop

    // 0x8001DF64: bgez        $t1, L_8001DF78
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001DF68: andi        $t2, $t1, 0x3
        ctx->r10 = ctx->r9 & 0X3;
            goto L_8001DF78;
    }
    // 0x8001DF68: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8001DF6C: beq         $t2, $zero, L_8001DF78
    if (ctx->r10 == 0) {
        // 0x8001DF70: nop
    
            goto L_8001DF78;
    }
    // 0x8001DF70: nop

    // 0x8001DF74: addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
L_8001DF78:
    // 0x8001DF78: sw          $t2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r10;
    // 0x8001DF7C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001DF80: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8001DF84: nop

    // 0x8001DF88: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8001DF8C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8001DF90:
    // 0x8001DF90: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001DF94: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8001DF98: lw          $t6, 0xC0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC0);
    // 0x8001DF9C: nop

    // 0x8001DFA0: and         $t3, $t6, $at
    ctx->r11 = ctx->r14 & ctx->r1;
    // 0x8001DFA4: beq         $t3, $zero, L_8001E2C8
    if (ctx->r11 == 0) {
        // 0x8001DFA8: nop
    
            goto L_8001E2C8;
    }
    // 0x8001DFA8: nop

    // 0x8001DFAC: jal         0x800C1754
    // 0x8001DFB0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_8;
    // 0x8001DFB0: nop

    after_8:
    // 0x8001DFB4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001DFB8: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001DFBC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8001DFC0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DFC4: nop

    // 0x8001DFC8: bne         $t9, $t5, L_8001E298
    if (ctx->r25 != ctx->r13) {
        // 0x8001DFCC: nop
    
            goto L_8001E298;
    }
    // 0x8001DFCC: nop

    // 0x8001DFD0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001DFD4: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001DFD8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DFDC: lhu         $t8, 0x126C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X126C);
    // 0x8001DFE0: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8001DFE4: nop

    // 0x8001DFE8: and         $t0, $t2, $t8
    ctx->r8 = ctx->r10 & ctx->r24;
    // 0x8001DFEC: beq         $t0, $zero, L_8001E00C
    if (ctx->r8 == 0) {
        // 0x8001DFF0: nop
    
            goto L_8001E00C;
    }
    // 0x8001DFF0: nop

    // 0x8001DFF4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001DFF8: nop

    // 0x8001DFFC: lw          $t6, 0xC0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC0);
    // 0x8001E000: nop

    // 0x8001E004: xori        $t3, $t6, 0x8
    ctx->r11 = ctx->r14 ^ 0X8;
    // 0x8001E008: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
L_8001E00C:
    // 0x8001E00C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E010: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E014: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E018: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x8001E01C: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8001E020: nop

    // 0x8001E024: and         $t1, $t9, $t5
    ctx->r9 = ctx->r25 & ctx->r13;
    // 0x8001E028: beq         $t1, $zero, L_8001E06C
    if (ctx->r9 == 0) {
        // 0x8001E02C: nop
    
            goto L_8001E06C;
    }
    // 0x8001E02C: nop

    // 0x8001E030: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E034: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8001E038: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E03C: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E040: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001E044: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E048: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8001E04C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E050: nop

    // 0x8001E054: lwc1        $f16, 0xCC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8001E058: nop

    // 0x8001E05C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E060: sub.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d - ctx->f10.d;
    // 0x8001E064: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8001E068: swc1        $f4, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f4.u32l;
L_8001E06C:
    // 0x8001E06C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001E070: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001E074: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001E078: lhu         $t6, 0xEEC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XEEC);
    // 0x8001E07C: lhu         $t0, 0x4($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X4);
    // 0x8001E080: nop

    // 0x8001E084: and         $t3, $t0, $t6
    ctx->r11 = ctx->r8 & ctx->r14;
    // 0x8001E088: beq         $t3, $zero, L_8001E0CC
    if (ctx->r11 == 0) {
        // 0x8001E08C: nop
    
            goto L_8001E0CC;
    }
    // 0x8001E08C: nop

    // 0x8001E090: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E094: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001E098: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E09C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E0A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001E0A4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E0A8: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8001E0AC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001E0B0: nop

    // 0x8001E0B4: lwc1        $f6, 0xCC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8001E0B8: nop

    // 0x8001E0BC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E0C0: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x8001E0C4: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8001E0C8: swc1        $f8, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f8.u32l;
L_8001E0CC:
    // 0x8001E0CC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E0D0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E0D4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E0D8: lhu         $t5, 0xE68($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XE68);
    // 0x8001E0DC: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8001E0E0: nop

    // 0x8001E0E4: and         $t1, $t9, $t5
    ctx->r9 = ctx->r25 & ctx->r13;
    // 0x8001E0E8: beq         $t1, $zero, L_8001E12C
    if (ctx->r9 == 0) {
        // 0x8001E0EC: nop
    
            goto L_8001E12C;
    }
    // 0x8001E0EC: nop

    // 0x8001E0F0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E0F4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001E0F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E0FC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E100: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001E104: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E108: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8001E10C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E110: nop

    // 0x8001E114: lwc1        $f16, 0xD0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8001E118: nop

    // 0x8001E11C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E120: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x8001E124: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8001E128: swc1        $f18, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f18.u32l;
L_8001E12C:
    // 0x8001E12C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001E130: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001E134: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001E138: lhu         $t6, 0xE74($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XE74);
    // 0x8001E13C: lhu         $t0, 0x4($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X4);
    // 0x8001E140: nop

    // 0x8001E144: and         $t3, $t0, $t6
    ctx->r11 = ctx->r8 & ctx->r14;
    // 0x8001E148: beq         $t3, $zero, L_8001E18C
    if (ctx->r11 == 0) {
        // 0x8001E14C: nop
    
            goto L_8001E18C;
    }
    // 0x8001E14C: nop

    // 0x8001E150: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E154: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8001E158: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E15C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E160: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001E164: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E168: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8001E16C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001E170: nop

    // 0x8001E174: lwc1        $f6, 0xD0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8001E178: nop

    // 0x8001E17C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E180: sub.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f18.d - ctx->f10.d;
    // 0x8001E184: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8001E188: swc1        $f4, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f4.u32l;
L_8001E18C:
    // 0x8001E18C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E190: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E194: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E198: lhu         $t5, 0x1038($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1038);
    // 0x8001E19C: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8001E1A0: nop

    // 0x8001E1A4: and         $t1, $t9, $t5
    ctx->r9 = ctx->r25 & ctx->r13;
    // 0x8001E1A8: beq         $t1, $zero, L_8001E1EC
    if (ctx->r9 == 0) {
        // 0x8001E1AC: nop
    
            goto L_8001E1EC;
    }
    // 0x8001E1AC: nop

    // 0x8001E1B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E1B4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001E1B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E1BC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E1C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001E1C4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E1C8: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8001E1CC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E1D0: nop

    // 0x8001E1D4: lwc1        $f16, 0xD4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XD4);
    // 0x8001E1D8: nop

    // 0x8001E1DC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E1E0: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x8001E1E4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8001E1E8: swc1        $f8, 0xD4($t2)
    MEM_W(0XD4, ctx->r10) = ctx->f8.u32l;
L_8001E1EC:
    // 0x8001E1EC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001E1F0: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001E1F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001E1F8: lhu         $t6, 0x1042($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1042);
    // 0x8001E1FC: lhu         $t0, 0x4($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X4);
    // 0x8001E200: nop

    // 0x8001E204: and         $t3, $t0, $t6
    ctx->r11 = ctx->r8 & ctx->r14;
    // 0x8001E208: beq         $t3, $zero, L_8001E24C
    if (ctx->r11 == 0) {
        // 0x8001E20C: nop
    
            goto L_8001E24C;
    }
    // 0x8001E20C: nop

    // 0x8001E210: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E214: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001E218: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E21C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E220: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001E224: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E228: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8001E22C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001E230: nop

    // 0x8001E234: lwc1        $f6, 0xD4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XD4);
    // 0x8001E238: nop

    // 0x8001E23C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E240: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8001E244: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8001E248: swc1        $f18, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f18.u32l;
L_8001E24C:
    // 0x8001E24C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001E250: nop

    // 0x8001E254: lh          $t9, 0x11E($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X11E);
    // 0x8001E258: nop

    // 0x8001E25C: bgez        $t9, L_8001E270
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001E260: nop
    
            goto L_8001E270;
    }
    // 0x8001E260: nop

    // 0x8001E264: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001E268: nop

    // 0x8001E26C: sh          $zero, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = 0;
L_8001E270:
    // 0x8001E270: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001E274: nop

    // 0x8001E278: lh          $t2, 0x11E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X11E);
    // 0x8001E27C: nop

    // 0x8001E280: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x8001E284: bne         $at, $zero, L_8001E298
    if (ctx->r1 != 0) {
        // 0x8001E288: nop
    
            goto L_8001E298;
    }
    // 0x8001E288: nop

    // 0x8001E28C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001E290: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001E294: sh          $t8, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r24;
L_8001E298:
    // 0x8001E298: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001E29C: jal         0x800A7230
    // 0x8001E2A0: nop

    func_800A7230(rdram, ctx);
        goto after_9;
    // 0x8001E2A0: nop

    after_9:
    // 0x8001E2A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001E2A8: jal         0x800997D8
    // 0x8001E2AC: nop

    func_800997D8(rdram, ctx);
        goto after_10;
    // 0x8001E2AC: nop

    after_10:
    // 0x8001E2B0: jal         0x800C1A28
    // 0x8001E2B4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_11;
    // 0x8001E2B4: nop

    after_11:
    // 0x8001E2B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001E2BC: nop

    // 0x8001E2C0: addiu       $t3, $t6, 0x160
    ctx->r11 = ADD32(ctx->r14, 0X160);
    // 0x8001E2C4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_8001E2C8:
    // 0x8001E2C8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E2CC: nop

    // 0x8001E2D0: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x8001E2D4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8001E2D8: bne         $at, $zero, L_8001DF90
    if (ctx->r1 != 0) {
        // 0x8001E2DC: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_8001DF90;
    }
    // 0x8001E2DC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8001E2E0: b           L_8001E2E8
    // 0x8001E2E4: nop

        goto L_8001E2E8;
    // 0x8001E2E4: nop

L_8001E2E8:
    // 0x8001E2E8: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E2EC: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001E2F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001E2F4: lhu         $t1, 0x11A4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X11A4);
    // 0x8001E2F8: lhu         $t5, 0x6($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X6);
    // 0x8001E2FC: nop

    // 0x8001E300: and         $t2, $t5, $t1
    ctx->r10 = ctx->r13 & ctx->r9;
    // 0x8001E304: beq         $t2, $zero, L_8001E328
    if (ctx->r10 == 0) {
        // 0x8001E308: nop
    
            goto L_8001E328;
    }
    // 0x8001E308: nop

    // 0x8001E30C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001E310: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001E314: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x8001E318: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001E31C: sw          $t0, -0x4DB8($at)
    MEM_W(-0X4DB8, ctx->r1) = ctx->r8;
    // 0x8001E320: b           L_8001E338
    // 0x8001E324: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E338;
    // 0x8001E324: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E328:
    // 0x8001E328: b           L_8001E338
    // 0x8001E32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001E338;
    // 0x8001E32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E330: b           L_8001E338
    // 0x8001E334: nop

        goto L_8001E338;
    // 0x8001E334: nop

L_8001E338:
    // 0x8001E338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E33C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E340: jr          $ra
    // 0x8001E344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000DB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DB14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000DB18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000DB1C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000DB20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DB24: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000DB28: lh          $t6, -0x73C0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X73C0);
    // 0x8000DB2C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000DB30: bne         $t6, $at, L_8000DB40
    if (ctx->r14 != ctx->r1) {
        // 0x8000DB34: nop
    
            goto L_8000DB40;
    }
    // 0x8000DB34: nop

    // 0x8000DB38: b           L_8000DD84
    // 0x8000DB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DB40:
    // 0x8000DB40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000DB44: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000DB48: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000DB4C: nop

    // 0x8000DB50: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8000DB54: beq         $t9, $zero, L_8000DB64
    if (ctx->r25 == 0) {
        // 0x8000DB58: nop
    
            goto L_8000DB64;
    }
    // 0x8000DB58: nop

    // 0x8000DB5C: b           L_8000DD84
    // 0x8000DB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DB64:
    // 0x8000DB64: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8000DB68: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x8000DB6C: nop

    // 0x8000DB70: beq         $t0, $zero, L_8000DBAC
    if (ctx->r8 == 0) {
        // 0x8000DB74: nop
    
            goto L_8000DBAC;
    }
    // 0x8000DB74: nop

    // 0x8000DB78: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x8000DB7C: nop

    // 0x8000DB80: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000DB84: beq         $t2, $zero, L_8000DBAC
    if (ctx->r10 == 0) {
        // 0x8000DB88: nop
    
            goto L_8000DBAC;
    }
    // 0x8000DB88: nop

    // 0x8000DB8C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8000DB90: nop

    // 0x8000DB94: lw          $t4, 0x1A0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A0);
    // 0x8000DB98: nop

    // 0x8000DB9C: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x8000DBA0: sw          $t5, 0x1A0($t3)
    MEM_W(0X1A0, ctx->r11) = ctx->r13;
    // 0x8000DBA4: b           L_8000DD84
    // 0x8000DBA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DBA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DBAC:
    // 0x8000DBAC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8000DBB0: nop

    // 0x8000DBB4: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x8000DBB8: nop

    // 0x8000DBBC: bne         $t7, $zero, L_8000DD34
    if (ctx->r15 != 0) {
        // 0x8000DBC0: nop
    
            goto L_8000DD34;
    }
    // 0x8000DBC0: nop

    // 0x8000DBC4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000DBC8: lh          $t8, -0x7290($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7290);
    // 0x8000DBCC: nop

    // 0x8000DBD0: slti        $at, $t8, 0x1F4
    ctx->r1 = SIGNED(ctx->r24) < 0X1F4 ? 1 : 0;
    // 0x8000DBD4: beq         $at, $zero, L_8000DBF8
    if (ctx->r1 == 0) {
        // 0x8000DBD8: nop
    
            goto L_8000DBF8;
    }
    // 0x8000DBD8: nop

    // 0x8000DBDC: lui         $t9, 0x8094
    ctx->r25 = S32(0X8094 << 16);
    // 0x8000DBE0: addiu       $t9, $t9, 0x7340
    ctx->r25 = ADD32(ctx->r25, 0X7340);
    // 0x8000DBE4: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8000DBE8: lui         $t0, 0x8095
    ctx->r8 = S32(0X8095 << 16);
    // 0x8000DBEC: addiu       $t0, $t0, -0x6EB0
    ctx->r8 = ADD32(ctx->r8, -0X6EB0);
    // 0x8000DBF0: b           L_8000DC10
    // 0x8000DBF4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
        goto L_8000DC10;
    // 0x8000DBF4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8000DBF8:
    // 0x8000DBF8: lui         $t1, 0x8099
    ctx->r9 = S32(0X8099 << 16);
    // 0x8000DBFC: addiu       $t1, $t1, 0x3AE0
    ctx->r9 = ADD32(ctx->r9, 0X3AE0);
    // 0x8000DC00: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8000DC04: lui         $t2, 0x8099
    ctx->r10 = S32(0X8099 << 16);
    // 0x8000DC08: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8000DC0C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_8000DC10:
    // 0x8000DC10: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000DC14: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000DC18: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000DC1C: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000DC20: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8000DC24: jal         0x800BD1FC
    // 0x8000DC28: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8000DC28: nop

    after_0:
    // 0x8000DC2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000DC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000DC34: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8000DC38: jal         0x800BD218
    // 0x8000DC3C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8000DC3C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_1:
    // 0x8000DC40: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000DC44: lh          $t5, -0x7290($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X7290);
    // 0x8000DC48: lh          $t4, 0x2C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2C);
    // 0x8000DC4C: nop

    // 0x8000DC50: bne         $t4, $t5, L_8000DCA8
    if (ctx->r12 != ctx->r13) {
        // 0x8000DC54: nop
    
            goto L_8000DCA8;
    }
    // 0x8000DC54: nop

    // 0x8000DC58: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000DC5C: lh          $t6, -0x7288($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7288);
    // 0x8000DC60: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x8000DC64: nop

    // 0x8000DC68: bne         $t3, $t6, L_8000DCA8
    if (ctx->r11 != ctx->r14) {
        // 0x8000DC6C: nop
    
            goto L_8000DCA8;
    }
    // 0x8000DC6C: nop

    // 0x8000DC70: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000DC74: lh          $t8, -0x7280($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7280);
    // 0x8000DC78: lh          $t7, 0x30($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X30);
    // 0x8000DC7C: nop

    // 0x8000DC80: bne         $t7, $t8, L_8000DCA8
    if (ctx->r15 != ctx->r24) {
        // 0x8000DC84: nop
    
            goto L_8000DCA8;
    }
    // 0x8000DC84: nop

    // 0x8000DC88: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000DC8C: nop

    // 0x8000DC90: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x8000DC94: nop

    // 0x8000DC98: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8000DC9C: sw          $t1, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->r9;
    // 0x8000DCA0: b           L_8000DCC8
    // 0x8000DCA4: nop

        goto L_8000DCC8;
    // 0x8000DCA4: nop

L_8000DCA8:
    // 0x8000DCA8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000DCAC: nop

    // 0x8000DCB0: addiu       $t4, $t2, 0xC
    ctx->r12 = ADD32(ctx->r10, 0XC);
    // 0x8000DCB4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8000DCB8: lh          $t5, 0x2C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2C);
    // 0x8000DCBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DCC0: bne         $t5, $at, L_8000DC10
    if (ctx->r13 != ctx->r1) {
        // 0x8000DCC4: nop
    
            goto L_8000DC10;
    }
    // 0x8000DCC4: nop

L_8000DCC8:
    // 0x8000DCC8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8000DCCC: nop

    // 0x8000DCD0: lw          $t6, 0x1A8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1A8);
    // 0x8000DCD4: nop

    // 0x8000DCD8: bne         $t6, $zero, L_8000DCE8
    if (ctx->r14 != 0) {
        // 0x8000DCDC: nop
    
            goto L_8000DCE8;
    }
    // 0x8000DCDC: nop

    // 0x8000DCE0: b           L_8000DD84
    // 0x8000DCE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000DD84;
    // 0x8000DCE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000DCE8:
    // 0x8000DCE8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000DCEC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000DCF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000DCF4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000DCF8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000DCFC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000DD00: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8000DD04: jal         0x800BD1FC
    // 0x8000DD08: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8000DD08: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_2:
    // 0x8000DD0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000DD10: jal         0x800B55B0
    // 0x8000DD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B55B0(rdram, ctx);
        goto after_3;
    // 0x8000DD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000DD18: beq         $v0, $zero, L_8000DD2C
    if (ctx->r2 == 0) {
        // 0x8000DD1C: nop
    
            goto L_8000DD2C;
    }
    // 0x8000DD1C: nop

    // 0x8000DD20: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8000DD24: nop

    // 0x8000DD28: sw          $zero, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = 0;
L_8000DD2C:
    // 0x8000DD2C: b           L_8000DD84
    // 0x8000DD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DD34:
    // 0x8000DD34: jal         0x800B56F0
    // 0x8000DD38: nop

    func_800B56F0(rdram, ctx);
        goto after_4;
    // 0x8000DD38: nop

    after_4:
    // 0x8000DD3C: beq         $v0, $zero, L_8000DD74
    if (ctx->r2 == 0) {
        // 0x8000DD40: nop
    
            goto L_8000DD74;
    }
    // 0x8000DD40: nop

    // 0x8000DD44: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000DD48: nop

    // 0x8000DD4C: sw          $zero, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = 0;
    // 0x8000DD50: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8000DD54: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x8000DD58: nop

    // 0x8000DD5C: beq         $t2, $zero, L_8000DD74
    if (ctx->r10 == 0) {
        // 0x8000DD60: nop
    
            goto L_8000DD74;
    }
    // 0x8000DD60: nop

    // 0x8000DD64: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8000DD68: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x8000DD6C: nop

    // 0x8000DD70: sh          $zero, 0x4($t4)
    MEM_H(0X4, ctx->r12) = 0;
L_8000DD74:
    // 0x8000DD74: b           L_8000DD84
    // 0x8000DD78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DD78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DD7C: b           L_8000DD84
    // 0x8000DD80: nop

        goto L_8000DD84;
    // 0x8000DD80: nop

L_8000DD84:
    // 0x8000DD84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DD88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DD8C: jr          $ra
    // 0x8000DD90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000DD90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800611EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800611EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800611F0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800611F4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800611F8: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x800611FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061200: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061204: nop

    // 0x80061208: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006120C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80061210: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061214: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061218: nop

    // 0x8006121C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061220: bne         $at, $zero, L_80061330
    if (ctx->r1 != 0) {
        // 0x80061224: nop
    
            goto L_80061330;
    }
    // 0x80061224: nop

L_80061228:
    // 0x80061228: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8006122C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80061230: nop

    // 0x80061234: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061238: bgez        $t2, L_80061248
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006123C: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80061248;
    }
    // 0x8006123C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80061240: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061244: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80061248:
    // 0x80061248: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8006124C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80061250: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061254: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061258: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8006125C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80061260: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80061264: lw          $t4, 0x640($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X640);
    // 0x80061268: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006126C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80061270: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80061274: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80061278: nop

    // 0x8006127C: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80061280: beq         $at, $zero, L_8006129C
    if (ctx->r1 == 0) {
        // 0x80061284: nop
    
            goto L_8006129C;
    }
    // 0x80061284: nop

    // 0x80061288: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8006128C: nop

    // 0x80061290: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80061294: b           L_80061318
    // 0x80061298: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
        goto L_80061318;
    // 0x80061298: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_8006129C:
    // 0x8006129C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800612A0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800612A4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800612A8: lw          $t7, 0x650($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X650);
    // 0x800612AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800612B0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800612B4: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x800612B8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800612BC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800612C0: lh          $t5, 0x0($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X0);
    // 0x800612C4: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800612C8: nop

    // 0x800612CC: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800612D0: beq         $at, $zero, L_800612EC
    if (ctx->r1 == 0) {
        // 0x800612D4: nop
    
            goto L_800612EC;
    }
    // 0x800612D4: nop

    // 0x800612D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800612DC: nop

    // 0x800612E0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800612E4: b           L_80061318
    // 0x800612E8: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
        goto L_80061318;
    // 0x800612E8: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
L_800612EC:
    // 0x800612EC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800612F0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800612F4: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800612F8: lw          $t2, 0x650($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X650);
    // 0x800612FC: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80061300: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80061304: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80061308: sb          $a0, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r4;
    // 0x8006130C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80061310: b           L_80061340
    // 0x80061314: nop

        goto L_80061340;
    // 0x80061314: nop

L_80061318:
    // 0x80061318: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8006131C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061320: nop

    // 0x80061324: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061328: beq         $at, $zero, L_80061228
    if (ctx->r1 == 0) {
        // 0x8006132C: nop
    
            goto L_80061228;
    }
    // 0x8006132C: nop

L_80061330:
    // 0x80061330: b           L_80061340
    // 0x80061334: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80061340;
    // 0x80061334: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80061338: b           L_80061340
    // 0x8006133C: nop

        goto L_80061340;
    // 0x8006133C: nop

L_80061340:
    // 0x80061340: jr          $ra
    // 0x80061344: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80061344: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006490C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006490C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064914: jal         0x8005F064
    // 0x80064918: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064918: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_0:
    // 0x8006491C: b           L_8006492C
    // 0x80064920: nop

        goto L_8006492C;
    // 0x80064920: nop

    // 0x80064924: b           L_8006492C
    // 0x80064928: nop

        goto L_8006492C;
    // 0x80064928: nop

L_8006492C:
    // 0x8006492C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064934: jr          $ra
    // 0x80064938: nop

    return;
    // 0x80064938: nop

;}
RECOMP_FUNC void func_800764B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800764B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800764B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800764B8: nop

    // 0x800764BC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800764C0: nop

    // 0x800764C4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800764C8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800764CC: jr          $ra
    // 0x800764D0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800764D0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800764D4: jr          $ra
    // 0x800764D8: nop

    return;
    // 0x800764D8: nop

    // 0x800764DC: jr          $ra
    // 0x800764E0: nop

    return;
    // 0x800764E0: nop

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
RECOMP_FUNC void func_80067D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067D74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067D78: nop

    // 0x80067D7C: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067D80: nop

    // 0x80067D84: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067D88: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067D8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067D90: beq         $v0, $zero, L_80067DAC
    if (ctx->r2 == 0) {
        // 0x80067D94: nop
    
            goto L_80067DAC;
    }
    // 0x80067D94: nop

    // 0x80067D98: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067D9C: nop

    // 0x80067DA0: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067DA4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067DA8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067DAC:
    // 0x80067DAC: jr          $ra
    // 0x80067DB0: nop

    return;
    // 0x80067DB0: nop

    // 0x80067DB4: jr          $ra
    // 0x80067DB8: nop

    return;
    // 0x80067DB8: nop

    // 0x80067DBC: jr          $ra
    // 0x80067DC0: nop

    return;
    // 0x80067DC0: nop

;}
RECOMP_FUNC void func_80067C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C98: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067C9C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067CA0: nop

    // 0x80067CA4: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067CA8: nop

    // 0x80067CAC: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067CB0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067CB4: jr          $ra
    // 0x80067CB8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067CB8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067CBC: jr          $ra
    // 0x80067CC0: nop

    return;
    // 0x80067CC0: nop

    // 0x80067CC4: jr          $ra
    // 0x80067CC8: nop

    return;
    // 0x80067CC8: nop

;}
RECOMP_FUNC void func_8006EF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EF88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EF8C: jal         0x80061348
    // 0x8006EF90: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EF90: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    after_0:
    // 0x8006EF94: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006EF98: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006EF9C: b           L_8006EFAC
    // 0x8006EFA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EFAC;
    // 0x8006EFA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EFA4: b           L_8006EFAC
    // 0x8006EFA8: nop

        goto L_8006EFAC;
    // 0x8006EFA8: nop

L_8006EFAC:
    // 0x8006EFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EFB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EFB4: jr          $ra
    // 0x8006EFB8: nop

    return;
    // 0x8006EFB8: nop

;}
RECOMP_FUNC void func_80050AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050AC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80050AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050ACC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80050AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_80050AD4:
    // 0x80050AD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050AD8: lw          $t6, 0x6CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6CC);
    // 0x80050ADC: nop

    // 0x80050AE0: beq         $t6, $zero, L_8005110C
    if (ctx->r14 == 0) {
        // 0x80050AE4: nop
    
            goto L_8005110C;
    }
    // 0x80050AE4: nop

    // 0x80050AE8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80050AEC: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80050AF0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80050AF4: bne         $t7, $at, L_8005110C
    if (ctx->r15 != ctx->r1) {
        // 0x80050AF8: nop
    
            goto L_8005110C;
    }
    // 0x80050AF8: nop

    // 0x80050AFC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050B00: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80050B04: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80050B08: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80050B0C: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x80050B10: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050B14: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80050B18: bne         $t2, $zero, L_8005110C
    if (ctx->r10 != 0) {
        // 0x80050B1C: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8005110C;
    }
    // 0x80050B1C: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80050B20: bne         $t3, $zero, L_8005110C
    if (ctx->r11 != 0) {
        // 0x80050B24: nop
    
            goto L_8005110C;
    }
    // 0x80050B24: nop

    // 0x80050B28: jal         0x80057960
    // 0x80050B2C: nop

    func_80057960(rdram, ctx);
        goto after_0;
    // 0x80050B2C: nop

    after_0:
    // 0x80050B30: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80050B34: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80050B38: nop

    // 0x80050B3C: bne         $t9, $zero, L_8005110C
    if (ctx->r25 != 0) {
        // 0x80050B40: nop
    
            goto L_8005110C;
    }
    // 0x80050B40: nop

L_80050B44:
    // 0x80050B44: jal         0x80055148
    // 0x80050B48: nop

    func_80055148(rdram, ctx);
        goto after_1;
    // 0x80050B48: nop

    after_1:
    // 0x80050B4C: beq         $v0, $zero, L_80050B5C
    if (ctx->r2 == 0) {
        // 0x80050B50: nop
    
            goto L_80050B5C;
    }
    // 0x80050B50: nop

    // 0x80050B54: b           L_8005110C
    // 0x80050B58: nop

        goto L_8005110C;
    // 0x80050B58: nop

L_80050B5C:
    // 0x80050B5C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80050B60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80050B68: jal         0x80052508
    // 0x80050B6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_2;
    // 0x80050B6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80050B70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80050B74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050B78: beq         $s0, $at, L_80050BA0
    if (ctx->r16 == ctx->r1) {
        // 0x80050B7C: nop
    
            goto L_80050BA0;
    }
    // 0x80050B7C: nop

    // 0x80050B80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050B84: beq         $s0, $at, L_80050BA0
    if (ctx->r16 == ctx->r1) {
        // 0x80050B88: nop
    
            goto L_80050BA0;
    }
    // 0x80050B88: nop

    // 0x80050B8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050B90: beq         $s0, $at, L_80050BB0
    if (ctx->r16 == ctx->r1) {
        // 0x80050B94: nop
    
            goto L_80050BB0;
    }
    // 0x80050B94: nop

    // 0x80050B98: b           L_80050BC0
    // 0x80050B9C: nop

        goto L_80050BC0;
    // 0x80050B9C: nop

L_80050BA0:
    // 0x80050BA0: addiu       $t4, $zero, 0x70
    ctx->r12 = ADD32(0, 0X70);
    // 0x80050BA4: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80050BA8: b           L_80050E20
    // 0x80050BAC: nop

        goto L_80050E20;
    // 0x80050BAC: nop

L_80050BB0:
    // 0x80050BB0: addiu       $t5, $zero, 0x70
    ctx->r13 = ADD32(0, 0X70);
    // 0x80050BB4: sh          $t5, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r13;
    // 0x80050BB8: b           L_80050E20
    // 0x80050BBC: nop

        goto L_80050E20;
    // 0x80050BBC: nop

L_80050BC0:
    // 0x80050BC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050BC4: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x80050BC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80050BCC: beq         $t6, $at, L_80050BF8
    if (ctx->r14 == ctx->r1) {
        // 0x80050BD0: nop
    
            goto L_80050BF8;
    }
    // 0x80050BD0: nop

    // 0x80050BD4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80050BD8: bne         $t6, $at, L_80050D44
    if (ctx->r14 != ctx->r1) {
        // 0x80050BDC: nop
    
            goto L_80050D44;
    }
    // 0x80050BDC: nop

    // 0x80050BE0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80050BE4: lhu         $t7, -0x6504($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6504);
    // 0x80050BE8: nop

    // 0x80050BEC: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80050BF0: beq         $t8, $zero, L_80050D44
    if (ctx->r24 == 0) {
        // 0x80050BF4: nop
    
            goto L_80050D44;
    }
    // 0x80050BF4: nop

L_80050BF8:
    // 0x80050BF8: jal         0x80061E14
    // 0x80050BFC: nop

    func_80061E14(rdram, ctx);
        goto after_3;
    // 0x80050BFC: nop

    after_3:
    // 0x80050C00: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80050C04: beq         $v0, $at, L_80050C60
    if (ctx->r2 == ctx->r1) {
        // 0x80050C08: nop
    
            goto L_80050C60;
    }
    // 0x80050C08: nop

    // 0x80050C0C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80050C10: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80050C14: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80050C18: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80050C1C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80050C20: bne         $t4, $zero, L_80050C60
    if (ctx->r12 != 0) {
        // 0x80050C24: andi        $t5, $t3, 0x20
        ctx->r13 = ctx->r11 & 0X20;
            goto L_80050C60;
    }
    // 0x80050C24: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x80050C28: bne         $t5, $zero, L_80050C60
    if (ctx->r13 != 0) {
        // 0x80050C2C: nop
    
            goto L_80050C60;
    }
    // 0x80050C2C: nop

    // 0x80050C30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050C34: jal         0x800507AC
    // 0x80050C38: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800507AC(rdram, ctx);
        goto after_4;
    // 0x80050C38: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_4:
    // 0x80050C3C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050C40: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050C44: nop

    // 0x80050C48: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80050C4C: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80050C50: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x80050C54: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x80050C58: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80050C5C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_80050C60:
    // 0x80050C60: jal         0x80061E14
    // 0x80050C64: nop

    func_80061E14(rdram, ctx);
        goto after_5;
    // 0x80050C64: nop

    after_5:
    // 0x80050C68: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80050C6C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80050C70: nop

    // 0x80050C74: beq         $t0, $zero, L_80050C8C
    if (ctx->r8 == 0) {
        // 0x80050C78: nop
    
            goto L_80050C8C;
    }
    // 0x80050C78: nop

    // 0x80050C7C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80050C80: nop

    // 0x80050C84: addiu       $t3, $t2, -0x17
    ctx->r11 = ADD32(ctx->r10, -0X17);
    // 0x80050C88: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80050C8C:
    // 0x80050C8C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80050C90: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80050C94: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80050C98: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80050C9C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80050CA0: lw          $t4, 0x670($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X670);
    // 0x80050CA4: lw          $t7, -0x27E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X27E0);
    // 0x80050CA8: nop

    // 0x80050CAC: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80050CB0: beq         $at, $zero, L_80050D28
    if (ctx->r1 == 0) {
        // 0x80050CB4: nop
    
            goto L_80050D28;
    }
    // 0x80050CB4: nop

    // 0x80050CB8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80050CBC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80050CC0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80050CC4: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80050CC8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050CCC: lw          $t8, 0x670($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X670);
    // 0x80050CD0: lw          $t0, -0x27E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X27E0);
    // 0x80050CD4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80050CD8: div         $zero, $t8, $t0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r8)));
    // 0x80050CDC: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80050CE0: lw          $t5, -0x27F4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X27F4);
    // 0x80050CE4: bne         $t0, $zero, L_80050CF0
    if (ctx->r8 != 0) {
        // 0x80050CE8: nop
    
            goto L_80050CF0;
    }
    // 0x80050CE8: nop

    // 0x80050CEC: break       7
    do_break(2147814636);
L_80050CF0:
    // 0x80050CF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050CF4: bne         $t0, $at, L_80050D08
    if (ctx->r8 != ctx->r1) {
        // 0x80050CF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80050D08;
    }
    // 0x80050CF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80050CFC: bne         $t8, $at, L_80050D08
    if (ctx->r24 != ctx->r1) {
        // 0x80050D00: nop
    
            goto L_80050D08;
    }
    // 0x80050D00: nop

    // 0x80050D04: break       6
    do_break(2147814660);
L_80050D08:
    // 0x80050D08: mfhi        $t2
    ctx->r10 = hi;
    // 0x80050D0C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80050D10: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x80050D14: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80050D18: nop

    // 0x80050D1C: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80050D20: b           L_80050E20
    // 0x80050D24: nop

        goto L_80050E20;
    // 0x80050D24: nop

L_80050D28:
    // 0x80050D28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050D2C: jal         0x80051700
    // 0x80050D30: nop

    func_80051700(rdram, ctx);
        goto after_6;
    // 0x80050D30: nop

    after_6:
    // 0x80050D34: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80050D38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80050D3C: b           L_80050E20
    // 0x80050D40: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_80050E20;
    // 0x80050D40: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_80050D44:
    // 0x80050D44: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050D48: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050D4C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80050D50: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80050D54: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x80050D58: bne         $t0, $zero, L_80050D68
    if (ctx->r8 != 0) {
        // 0x80050D5C: andi        $t1, $t9, 0x20
        ctx->r9 = ctx->r25 & 0X20;
            goto L_80050D68;
    }
    // 0x80050D5C: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x80050D60: beq         $t1, $zero, L_80050D9C
    if (ctx->r9 == 0) {
        // 0x80050D64: nop
    
            goto L_80050D9C;
    }
    // 0x80050D64: nop

L_80050D68:
    // 0x80050D68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050D6C: jal         0x800507AC
    // 0x80050D70: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    func_800507AC(rdram, ctx);
        goto after_7;
    // 0x80050D70: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_7:
    // 0x80050D74: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80050D78: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80050D7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050D80: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80050D84: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x80050D88: and         $t4, $t6, $at
    ctx->r12 = ctx->r14 & ctx->r1;
    // 0x80050D8C: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80050D90: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x80050D94: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80050D98: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_80050D9C:
    // 0x80050D9C: jal         0x80061E14
    // 0x80050DA0: nop

    func_80061E14(rdram, ctx);
        goto after_8;
    // 0x80050DA0: nop

    after_8:
    // 0x80050DA4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80050DA8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80050DAC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80050DB0: beq         $t3, $at, L_80050DF0
    if (ctx->r11 == ctx->r1) {
        // 0x80050DB4: nop
    
            goto L_80050DF0;
    }
    // 0x80050DB4: nop

    // 0x80050DB8: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80050DBC: beq         $t3, $at, L_80050DF0
    if (ctx->r11 == ctx->r1) {
        // 0x80050DC0: nop
    
            goto L_80050DF0;
    }
    // 0x80050DC0: nop

    // 0x80050DC4: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80050DC8: beq         $t3, $at, L_80050DF0
    if (ctx->r11 == ctx->r1) {
        // 0x80050DCC: nop
    
            goto L_80050DF0;
    }
    // 0x80050DCC: nop

    // 0x80050DD0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050DD4: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80050DD8: nop

    // 0x80050DDC: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x80050DE0: nop

    // 0x80050DE4: slti        $at, $t9, 0x384
    ctx->r1 = SIGNED(ctx->r25) < 0X384 ? 1 : 0;
    // 0x80050DE8: bne         $at, $zero, L_80050E0C
    if (ctx->r1 != 0) {
        // 0x80050DEC: nop
    
            goto L_80050E0C;
    }
    // 0x80050DEC: nop

L_80050DF0:
    // 0x80050DF0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050DF4: jal         0x80051700
    // 0x80050DF8: nop

    func_80051700(rdram, ctx);
        goto after_9;
    // 0x80050DF8: nop

    after_9:
    // 0x80050DFC: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80050E00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80050E04: b           L_80050E20
    // 0x80050E08: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
        goto L_80050E20;
    // 0x80050E08: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
L_80050E0C:
    // 0x80050E0C: jal         0x8005151C
    // 0x80050E10: nop

    func_8005151C(rdram, ctx);
        goto after_10;
    // 0x80050E10: nop

    after_10:
    // 0x80050E14: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80050E18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80050E1C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_80050E20:
    // 0x80050E20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050E24: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80050E28: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80050E2C: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x80050E30: nop

    // 0x80050E34: bne         $t7, $t4, L_80050E50
    if (ctx->r15 != ctx->r12) {
        // 0x80050E38: nop
    
            goto L_80050E50;
    }
    // 0x80050E38: nop

    // 0x80050E3C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050E40: jal         0x800499B0
    // 0x80050E44: nop

    func_800499B0(rdram, ctx);
        goto after_11;
    // 0x80050E44: nop

    after_11:
    // 0x80050E48: b           L_8005109C
    // 0x80050E4C: nop

        goto L_8005109C;
    // 0x80050E4C: nop

L_80050E50:
    // 0x80050E50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80050E54: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80050E58: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x80050E5C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80050E60: lh          $a1, 0x42($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X42);
    // 0x80050E64: jal         0x8004EF90
    // 0x80050E68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_12;
    // 0x80050E68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80050E6C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80050E70: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80050E74: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80050E78: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80050E7C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80050E80: bne         $t0, $zero, L_80050EA0
    if (ctx->r8 != 0) {
        // 0x80050E84: andi        $t1, $t9, 0x100
        ctx->r9 = ctx->r25 & 0X100;
            goto L_80050EA0;
    }
    // 0x80050E84: andi        $t1, $t9, 0x100
    ctx->r9 = ctx->r25 & 0X100;
    // 0x80050E88: bne         $t1, $zero, L_80050EA0
    if (ctx->r9 != 0) {
        // 0x80050E8C: nop
    
            goto L_80050EA0;
    }
    // 0x80050E8C: nop

    // 0x80050E90: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80050E94: nop

    // 0x80050E98: beq         $t3, $zero, L_80050EB4
    if (ctx->r11 == 0) {
        // 0x80050E9C: nop
    
            goto L_80050EB4;
    }
    // 0x80050E9C: nop

L_80050EA0:
    // 0x80050EA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050EA4: jal         0x800499B0
    // 0x80050EA8: nop

    func_800499B0(rdram, ctx);
        goto after_13;
    // 0x80050EA8: nop

    after_13:
    // 0x80050EAC: b           L_8005109C
    // 0x80050EB0: nop

        goto L_8005109C;
    // 0x80050EB0: nop

L_80050EB4:
    // 0x80050EB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050EB8: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x80050EBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80050EC0: beq         $t6, $at, L_80050ED4
    if (ctx->r14 == ctx->r1) {
        // 0x80050EC4: nop
    
            goto L_80050ED4;
    }
    // 0x80050EC4: nop

    // 0x80050EC8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80050ECC: bne         $t6, $at, L_80050FF4
    if (ctx->r14 != ctx->r1) {
        // 0x80050ED0: nop
    
            goto L_80050FF4;
    }
    // 0x80050ED0: nop

L_80050ED4:
    // 0x80050ED4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80050ED8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050EDC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050EE0: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x80050EE4: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80050EE8: bne         $t2, $zero, L_80050F78
    if (ctx->r10 != 0) {
        // 0x80050EEC: andi        $t3, $t5, 0x2
        ctx->r11 = ctx->r13 & 0X2;
            goto L_80050F78;
    }
    // 0x80050EEC: andi        $t3, $t5, 0x2
    ctx->r11 = ctx->r13 & 0X2;
    // 0x80050EF0: bne         $t3, $zero, L_80050F78
    if (ctx->r11 != 0) {
        // 0x80050EF4: nop
    
            goto L_80050F78;
    }
    // 0x80050EF4: nop

    // 0x80050EF8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80050EFC: bne         $t8, $zero, L_80050F78
    if (ctx->r24 != 0) {
        // 0x80050F00: andi        $t9, $t5, 0x1000
        ctx->r25 = ctx->r13 & 0X1000;
            goto L_80050F78;
    }
    // 0x80050F00: andi        $t9, $t5, 0x1000
    ctx->r25 = ctx->r13 & 0X1000;
    // 0x80050F04: bne         $t9, $zero, L_80050F78
    if (ctx->r25 != 0) {
        // 0x80050F08: nop
    
            goto L_80050F78;
    }
    // 0x80050F08: nop

    // 0x80050F0C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80050F10: lh          $t0, 0x10F0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X10F0);
    // 0x80050F14: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80050F18: bne         $t0, $at, L_80050F78
    if (ctx->r8 != ctx->r1) {
        // 0x80050F1C: nop
    
            goto L_80050F78;
    }
    // 0x80050F1C: nop

L_80050F20:
    // 0x80050F20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050F24: jal         0x800499B0
    // 0x80050F28: nop

    func_800499B0(rdram, ctx);
        goto after_14;
    // 0x80050F28: nop

    after_14:
    // 0x80050F2C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050F30: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050F34: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050F38: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80050F3C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80050F40: bne         $t2, $zero, L_80050F78
    if (ctx->r10 != 0) {
        // 0x80050F44: andi        $t3, $t7, 0x2
        ctx->r11 = ctx->r15 & 0X2;
            goto L_80050F78;
    }
    // 0x80050F44: andi        $t3, $t7, 0x2
    ctx->r11 = ctx->r15 & 0X2;
    // 0x80050F48: bne         $t3, $zero, L_80050F78
    if (ctx->r11 != 0) {
        // 0x80050F4C: nop
    
            goto L_80050F78;
    }
    // 0x80050F4C: nop

    // 0x80050F50: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80050F54: bne         $t4, $zero, L_80050F78
    if (ctx->r12 != 0) {
        // 0x80050F58: andi        $t5, $t7, 0x1000
        ctx->r13 = ctx->r15 & 0X1000;
            goto L_80050F78;
    }
    // 0x80050F58: andi        $t5, $t7, 0x1000
    ctx->r13 = ctx->r15 & 0X1000;
    // 0x80050F5C: bne         $t5, $zero, L_80050F78
    if (ctx->r13 != 0) {
        // 0x80050F60: nop
    
            goto L_80050F78;
    }
    // 0x80050F60: nop

    // 0x80050F64: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050F68: lh          $t8, 0x10F0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X10F0);
    // 0x80050F6C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80050F70: beq         $t8, $at, L_80050F20
    if (ctx->r24 == ctx->r1) {
        // 0x80050F74: nop
    
            goto L_80050F20;
    }
    // 0x80050F74: nop

L_80050F78:
    // 0x80050F78: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050F7C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050F80: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050F84: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80050F88: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80050F8C: bne         $t2, $zero, L_80050F9C
    if (ctx->r10 != 0) {
        // 0x80050F90: andi        $t3, $t1, 0x1000
        ctx->r11 = ctx->r9 & 0X1000;
            goto L_80050F9C;
    }
    // 0x80050F90: andi        $t3, $t1, 0x1000
    ctx->r11 = ctx->r9 & 0X1000;
    // 0x80050F94: beq         $t3, $zero, L_80050FA4
    if (ctx->r11 == 0) {
        // 0x80050F98: nop
    
            goto L_80050FA4;
    }
    // 0x80050F98: nop

L_80050F9C:
    // 0x80050F9C: b           L_8005110C
    // 0x80050FA0: nop

        goto L_8005110C;
    // 0x80050FA0: nop

L_80050FA4:
    // 0x80050FA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050FA8: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x80050FAC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80050FB0: beq         $t6, $at, L_80050FEC
    if (ctx->r14 == ctx->r1) {
        // 0x80050FB4: nop
    
            goto L_80050FEC;
    }
    // 0x80050FB4: nop

    // 0x80050FB8: jal         0x80061F08
    // 0x80050FBC: nop

    func_80061F08(rdram, ctx);
        goto after_15;
    // 0x80050FBC: nop

    after_15:
    // 0x80050FC0: bne         $v0, $zero, L_80050FD8
    if (ctx->r2 != 0) {
        // 0x80050FC4: nop
    
            goto L_80050FD8;
    }
    // 0x80050FC4: nop

    // 0x80050FC8: b           L_8005110C
    // 0x80050FCC: nop

        goto L_8005110C;
    // 0x80050FCC: nop

    // 0x80050FD0: b           L_80050FEC
    // 0x80050FD4: nop

        goto L_80050FEC;
    // 0x80050FD4: nop

L_80050FD8:
    // 0x80050FD8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80050FDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80050FE0: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
    // 0x80050FE4: b           L_80050ED4
    // 0x80050FE8: nop

        goto L_80050ED4;
    // 0x80050FE8: nop

L_80050FEC:
    // 0x80050FEC: b           L_8005109C
    // 0x80050FF0: nop

        goto L_8005109C;
    // 0x80050FF0: nop

L_80050FF4:
    // 0x80050FF4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80050FF8: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80050FFC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051000: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80051004: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80051008: bne         $t0, $zero, L_80051070
    if (ctx->r8 != 0) {
        // 0x8005100C: andi        $t1, $t9, 0x2
        ctx->r9 = ctx->r25 & 0X2;
            goto L_80051070;
    }
    // 0x8005100C: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x80051010: bne         $t1, $zero, L_80051070
    if (ctx->r9 != 0) {
        // 0x80051014: nop
    
            goto L_80051070;
    }
    // 0x80051014: nop

    // 0x80051018: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005101C: bne         $t2, $zero, L_80051070
    if (ctx->r10 != 0) {
        // 0x80051020: andi        $t3, $t9, 0x1000
        ctx->r11 = ctx->r25 & 0X1000;
            goto L_80051070;
    }
    // 0x80051020: andi        $t3, $t9, 0x1000
    ctx->r11 = ctx->r25 & 0X1000;
    // 0x80051024: bne         $t3, $zero, L_80051070
    if (ctx->r11 != 0) {
        // 0x80051028: nop
    
            goto L_80051070;
    }
    // 0x80051028: nop

L_8005102C:
    // 0x8005102C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051030: jal         0x800499B0
    // 0x80051034: nop

    func_800499B0(rdram, ctx);
        goto after_16;
    // 0x80051034: nop

    after_16:
    // 0x80051038: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005103C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80051040: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80051044: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80051048: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8005104C: bne         $t4, $zero, L_80051070
    if (ctx->r12 != 0) {
        // 0x80051050: andi        $t5, $t7, 0x2
        ctx->r13 = ctx->r15 & 0X2;
            goto L_80051070;
    }
    // 0x80051050: andi        $t5, $t7, 0x2
    ctx->r13 = ctx->r15 & 0X2;
    // 0x80051054: bne         $t5, $zero, L_80051070
    if (ctx->r13 != 0) {
        // 0x80051058: nop
    
            goto L_80051070;
    }
    // 0x80051058: nop

    // 0x8005105C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051060: bne         $t0, $zero, L_80051070
    if (ctx->r8 != 0) {
        // 0x80051064: andi        $t1, $t7, 0x1000
        ctx->r9 = ctx->r15 & 0X1000;
            goto L_80051070;
    }
    // 0x80051064: andi        $t1, $t7, 0x1000
    ctx->r9 = ctx->r15 & 0X1000;
    // 0x80051068: beq         $t1, $zero, L_8005102C
    if (ctx->r9 == 0) {
        // 0x8005106C: nop
    
            goto L_8005102C;
    }
    // 0x8005106C: nop

L_80051070:
    // 0x80051070: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051074: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80051078: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005107C: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x80051080: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x80051084: bne         $t4, $zero, L_80051094
    if (ctx->r12 != 0) {
        // 0x80051088: andi        $t5, $t3, 0x1000
        ctx->r13 = ctx->r11 & 0X1000;
            goto L_80051094;
    }
    // 0x80051088: andi        $t5, $t3, 0x1000
    ctx->r13 = ctx->r11 & 0X1000;
    // 0x8005108C: beq         $t5, $zero, L_8005109C
    if (ctx->r13 == 0) {
        // 0x80051090: nop
    
            goto L_8005109C;
    }
    // 0x80051090: nop

L_80051094:
    // 0x80051094: b           L_8005110C
    // 0x80051098: nop

        goto L_8005110C;
    // 0x80051098: nop

L_8005109C:
    // 0x8005109C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800510A0: lw          $t9, 0x6CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CC);
    // 0x800510A4: nop

    // 0x800510A8: beq         $t9, $zero, L_8005110C
    if (ctx->r25 == 0) {
        // 0x800510AC: nop
    
            goto L_8005110C;
    }
    // 0x800510AC: nop

    // 0x800510B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800510B4: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x800510B8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800510BC: bne         $t6, $at, L_8005110C
    if (ctx->r14 != ctx->r1) {
        // 0x800510C0: nop
    
            goto L_8005110C;
    }
    // 0x800510C0: nop

    // 0x800510C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800510C8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800510CC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800510D0: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x800510D4: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x800510D8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800510DC: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x800510E0: bne         $t8, $zero, L_8005110C
    if (ctx->r24 != 0) {
        // 0x800510E4: and         $t9, $t1, $at
        ctx->r25 = ctx->r9 & ctx->r1;
            goto L_8005110C;
    }
    // 0x800510E4: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x800510E8: bne         $t9, $zero, L_8005110C
    if (ctx->r25 != 0) {
        // 0x800510EC: nop
    
            goto L_8005110C;
    }
    // 0x800510EC: nop

    // 0x800510F0: jal         0x80057960
    // 0x800510F4: nop

    func_80057960(rdram, ctx);
        goto after_17;
    // 0x800510F4: nop

    after_17:
    // 0x800510F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800510FC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80051100: nop

    // 0x80051104: beq         $t2, $zero, L_80050B44
    if (ctx->r10 == 0) {
        // 0x80051108: nop
    
            goto L_80050B44;
    }
    // 0x80051108: nop

L_8005110C:
    // 0x8005110C: jal         0x80057960
    // 0x80051110: nop

    func_80057960(rdram, ctx);
        goto after_18;
    // 0x80051110: nop

    after_18:
    // 0x80051114: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80051118: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005111C: nop

    // 0x80051120: beq         $t3, $zero, L_80051138
    if (ctx->r11 == 0) {
        // 0x80051124: nop
    
            goto L_80051138;
    }
    // 0x80051124: nop

    // 0x80051128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005112C: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x80051130: b           L_80051368
    // 0x80051134: nop

        goto L_80051368;
    // 0x80051134: nop

L_80051138:
    // 0x80051138: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005113C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80051140: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051144: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80051148: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005114C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80051150: bne         $t0, $zero, L_80051160
    if (ctx->r8 != 0) {
        // 0x80051154: and         $t1, $t7, $at
        ctx->r9 = ctx->r15 & ctx->r1;
            goto L_80051160;
    }
    // 0x80051154: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x80051158: beq         $t1, $zero, L_80051170
    if (ctx->r9 == 0) {
        // 0x8005115C: nop
    
            goto L_80051170;
    }
    // 0x8005115C: nop

L_80051160:
    // 0x80051160: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051164: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x80051168: b           L_80051368
    // 0x8005116C: nop

        goto L_80051368;
    // 0x8005116C: nop

L_80051170:
    // 0x80051170: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80051174: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80051178: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005117C: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x80051180: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80051184: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80051188: bne         $t2, $zero, L_80051198
    if (ctx->r10 != 0) {
        // 0x8005118C: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_80051198;
    }
    // 0x8005118C: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x80051190: beq         $t3, $zero, L_800511B8
    if (ctx->r11 == 0) {
        // 0x80051194: nop
    
            goto L_800511B8;
    }
    // 0x80051194: nop

L_80051198:
    // 0x80051198: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005119C: jal         0x80054618
    // 0x800511A0: nop

    func_80054618(rdram, ctx);
        goto after_19;
    // 0x800511A0: nop

    after_19:
    // 0x800511A4: jal         0x8005A768
    // 0x800511A8: nop

    func_8005A768(rdram, ctx);
        goto after_20;
    // 0x800511A8: nop

    after_20:
    // 0x800511AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800511B0: b           L_80051354
    // 0x800511B4: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
        goto L_80051354;
    // 0x800511B4: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
L_800511B8:
    // 0x800511B8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800511BC: lh          $t4, 0x10F0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10F0);
    // 0x800511C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800511C4: bne         $t4, $at, L_800511F0
    if (ctx->r12 != ctx->r1) {
        // 0x800511C8: nop
    
            goto L_800511F0;
    }
    // 0x800511C8: nop

    // 0x800511CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800511D0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800511D4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800511D8: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x800511DC: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800511E0: bne         $t8, $zero, L_800511F0
    if (ctx->r24 != 0) {
        // 0x800511E4: andi        $t9, $t1, 0x1000
        ctx->r25 = ctx->r9 & 0X1000;
            goto L_800511F0;
    }
    // 0x800511E4: andi        $t9, $t1, 0x1000
    ctx->r25 = ctx->r9 & 0X1000;
    // 0x800511E8: beq         $t9, $zero, L_80051298
    if (ctx->r25 == 0) {
        // 0x800511EC: nop
    
            goto L_80051298;
    }
    // 0x800511EC: nop

L_800511F0:
    // 0x800511F0: jal         0x80061F08
    // 0x800511F4: nop

    func_80061F08(rdram, ctx);
        goto after_21;
    // 0x800511F4: nop

    after_21:
    // 0x800511F8: bne         $v0, $zero, L_80051258
    if (ctx->r2 != 0) {
        // 0x800511FC: nop
    
            goto L_80051258;
    }
    // 0x800511FC: nop

    // 0x80051200: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051204: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80051208: nop

    // 0x8005120C: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80051210: beq         $at, $zero, L_80051248
    if (ctx->r1 == 0) {
        // 0x80051214: nop
    
            goto L_80051248;
    }
    // 0x80051214: nop

    // 0x80051218: jal         0x8005A578
    // 0x8005121C: nop

    func_8005A578(rdram, ctx);
        goto after_22;
    // 0x8005121C: nop

    after_22:
    // 0x80051220: bne         $v0, $zero, L_80051248
    if (ctx->r2 != 0) {
        // 0x80051224: nop
    
            goto L_80051248;
    }
    // 0x80051224: nop

    // 0x80051228: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8005122C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051230: sh          $t5, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r13;
    // 0x80051234: jal         0x8005A768
    // 0x80051238: nop

    func_8005A768(rdram, ctx);
        goto after_23;
    // 0x80051238: nop

    after_23:
    // 0x8005123C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051240: b           L_80051250
    // 0x80051244: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
        goto L_80051250;
    // 0x80051244: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
L_80051248:
    // 0x80051248: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005124C: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
L_80051250:
    // 0x80051250: b           L_80051290
    // 0x80051254: nop

        goto L_80051290;
    // 0x80051254: nop

L_80051258:
    // 0x80051258: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8005125C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051260: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x80051264: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80051268: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005126C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80051270: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80051274: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80051278: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8005127C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x80051280: ori         $at, $at, 0xEFFF
    ctx->r1 = ctx->r1 | 0XEFFF;
    // 0x80051284: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80051288: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8005128C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_80051290:
    // 0x80051290: b           L_80051354
    // 0x80051294: nop

        goto L_80051354;
    // 0x80051294: nop

L_80051298:
    // 0x80051298: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005129C: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x800512A0: nop

    // 0x800512A4: bne         $t0, $zero, L_800512CC
    if (ctx->r8 != 0) {
        // 0x800512A8: nop
    
            goto L_800512CC;
    }
    // 0x800512A8: nop

    // 0x800512AC: jal         0x8005A578
    // 0x800512B0: nop

    func_8005A578(rdram, ctx);
        goto after_24;
    // 0x800512B0: nop

    after_24:
    // 0x800512B4: bne         $v0, $zero, L_800512E0
    if (ctx->r2 != 0) {
        // 0x800512B8: nop
    
            goto L_800512E0;
    }
    // 0x800512B8: nop

    // 0x800512BC: jal         0x80061F08
    // 0x800512C0: nop

    func_80061F08(rdram, ctx);
        goto after_25;
    // 0x800512C0: nop

    after_25:
    // 0x800512C4: bne         $v0, $zero, L_800512E0
    if (ctx->r2 != 0) {
        // 0x800512C8: nop
    
            goto L_800512E0;
    }
    // 0x800512C8: nop

L_800512CC:
    // 0x800512CC: jal         0x8005A768
    // 0x800512D0: nop

    func_8005A768(rdram, ctx);
        goto after_26;
    // 0x800512D0: nop

    after_26:
    // 0x800512D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800512D8: b           L_80051354
    // 0x800512DC: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
        goto L_80051354;
    // 0x800512DC: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
L_800512E0:
    // 0x800512E0: jal         0x80061E14
    // 0x800512E4: nop

    func_80061E14(rdram, ctx);
        goto after_27;
    // 0x800512E4: nop

    after_27:
    // 0x800512E8: bne         $v0, $zero, L_80051354
    if (ctx->r2 != 0) {
        // 0x800512EC: nop
    
            goto L_80051354;
    }
    // 0x800512EC: nop

    // 0x800512F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800512F4: lwc1        $f4, 0xDA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XDA0);
    // 0x800512F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800512FC: nop

    // 0x80051300: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80051304: nop

    // 0x80051308: bc1f        L_80051348
    if (!c1cs) {
        // 0x8005130C: nop
    
            goto L_80051348;
    }
    // 0x8005130C: nop

    // 0x80051310: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051314: lwc1        $f8, 0xE48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XE48);
    // 0x80051318: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005131C: nop

    // 0x80051320: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80051324: nop

    // 0x80051328: bc1f        L_80051348
    if (!c1cs) {
        // 0x8005132C: nop
    
            goto L_80051348;
    }
    // 0x8005132C: nop

    // 0x80051330: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80051334: lbu         $t1, 0x125A($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X125A);
    // 0x80051338: nop

    // 0x8005133C: andi        $t8, $t1, 0x2
    ctx->r24 = ctx->r9 & 0X2;
    // 0x80051340: beq         $t8, $zero, L_80051354
    if (ctx->r24 == 0) {
        // 0x80051344: nop
    
            goto L_80051354;
    }
    // 0x80051344: nop

L_80051348:
    // 0x80051348: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8005134C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051350: sw          $t9, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r25;
L_80051354:
    // 0x80051354: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051358: lw          $t2, 0x6CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6CC);
    // 0x8005135C: nop

    // 0x80051360: bne         $t2, $zero, L_80050AD4
    if (ctx->r10 != 0) {
        // 0x80051364: nop
    
            goto L_80050AD4;
    }
    // 0x80051364: nop

L_80051368:
    // 0x80051368: b           L_80051370
    // 0x8005136C: nop

        goto L_80051370;
    // 0x8005136C: nop

L_80051370:
    // 0x80051370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80051374: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051378: jr          $ra
    // 0x8005137C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005137C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80063988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063988: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006398C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063990: nop

    // 0x80063994: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80063998: nop

    // 0x8006399C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800639A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800639A4: jr          $ra
    // 0x800639A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800639A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800639AC: jr          $ra
    // 0x800639B0: nop

    return;
    // 0x800639B0: nop

    // 0x800639B4: jr          $ra
    // 0x800639B8: nop

    return;
    // 0x800639B8: nop

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
RECOMP_FUNC void alClose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78E4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C78E8: lw          $t6, -0x33E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33E0);
    // 0x800C78EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C78F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C78F4: beql        $t6, $zero, L_800C7910
    if (ctx->r14 == 0) {
        // 0x800C78F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C7910;
    }
    goto skip_0;
    // 0x800C78F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C78FC: jal         0x800CF740
    // 0x800C7900: nop

    alSynDelete(rdram, ctx);
        goto after_0;
    // 0x800C7900: nop

    after_0:
    // 0x800C7904: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C7908: sw          $zero, -0x33E0($at)
    MEM_W(-0X33E0, ctx->r1) = 0;
    // 0x800C790C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C7910:
    // 0x800C7910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7914: jr          $ra
    // 0x800C7918: nop

    return;
    // 0x800C7918: nop

;}
RECOMP_FUNC void func_8007789C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007789C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800778A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800778A4: nop

    // 0x800778A8: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x800778AC: nop

    // 0x800778B0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800778B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800778B8: jr          $ra
    // 0x800778BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800778BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800778C0: jr          $ra
    // 0x800778C4: nop

    return;
    // 0x800778C4: nop

    // 0x800778C8: jr          $ra
    // 0x800778CC: nop

    return;
    // 0x800778CC: nop

;}
RECOMP_FUNC void func_8006D5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D5BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D5C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D5C4: nop

    // 0x8006D5C8: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D5CC: nop

    // 0x8006D5D0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D5D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D5D8: jr          $ra
    // 0x8006D5DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D5DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D5E0: jr          $ra
    // 0x8006D5E4: nop

    return;
    // 0x8006D5E4: nop

    // 0x8006D5E8: jr          $ra
    // 0x8006D5EC: nop

    return;
    // 0x8006D5EC: nop

;}
RECOMP_FUNC void func_80031914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003191C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031920: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x80031924: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80031928: bne         $t6, $at, L_80031990
    if (ctx->r14 != ctx->r1) {
        // 0x8003192C: nop
    
            goto L_80031990;
    }
    // 0x8003192C: nop

    // 0x80031930: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80031934: lh          $t7, 0x2570($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2570);
    // 0x80031938: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003193C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80031940: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80031944: lw          $t9, 0x79D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X79D0);
    // 0x80031948: nop

    // 0x8003194C: bne         $t9, $zero, L_80031990
    if (ctx->r25 != 0) {
        // 0x80031950: nop
    
            goto L_80031990;
    }
    // 0x80031950: nop

    // 0x80031954: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80031958: lbu         $t0, -0x6A00($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6A00);
    // 0x8003195C: nop

    // 0x80031960: beq         $t0, $zero, L_80031978
    if (ctx->r8 == 0) {
        // 0x80031964: nop
    
            goto L_80031978;
    }
    // 0x80031964: nop

    // 0x80031968: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x8003196C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031970: b           L_80031980
    // 0x80031974: sh          $t1, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r9;
        goto L_80031980;
    // 0x80031974: sh          $t1, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r9;
L_80031978:
    // 0x80031978: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003197C: sh          $zero, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = 0;
L_80031980:
    // 0x80031980: jal         0x8009600C
    // 0x80031984: nop

    func_8009600C(rdram, ctx);
        goto after_0;
    // 0x80031984: nop

    after_0:
    // 0x80031988: b           L_800319A0
    // 0x8003198C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800319A0;
    // 0x8003198C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031990:
    // 0x80031990: b           L_800319A0
    // 0x80031994: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800319A0;
    // 0x80031994: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80031998: b           L_800319A0
    // 0x8003199C: nop

        goto L_800319A0;
    // 0x8003199C: nop

L_800319A0:
    // 0x800319A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800319A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800319A8: jr          $ra
    // 0x800319AC: nop

    return;
    // 0x800319AC: nop

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
RECOMP_FUNC void func_80072620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072620: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072624: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072628: nop

    // 0x8007262C: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072630: nop

    // 0x80072634: slti        $t7, $v0, 0x14A
    ctx->r15 = SIGNED(ctx->r2) < 0X14A ? 1 : 0;
    // 0x80072638: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007263C: jr          $ra
    // 0x80072640: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072640: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072644: jr          $ra
    // 0x80072648: nop

    return;
    // 0x80072648: nop

    // 0x8007264C: jr          $ra
    // 0x80072650: nop

    return;
    // 0x80072650: nop

;}
RECOMP_FUNC void func_8003168C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003168C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031690: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x80031694: nop

    // 0x80031698: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x8003169C: bne         $at, $zero, L_800316AC
    if (ctx->r1 != 0) {
        // 0x800316A0: nop
    
            goto L_800316AC;
    }
    // 0x800316A0: nop

    // 0x800316A4: jr          $ra
    // 0x800316A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800316A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800316AC:
    // 0x800316AC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800316B0: lh          $t7, 0x664($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X664);
    // 0x800316B4: nop

    // 0x800316B8: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x800316BC: bne         $at, $zero, L_800316CC
    if (ctx->r1 != 0) {
        // 0x800316C0: nop
    
            goto L_800316CC;
    }
    // 0x800316C0: nop

    // 0x800316C4: jr          $ra
    // 0x800316C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800316C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800316CC:
    // 0x800316CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800316D0: sh          $zero, 0x2524($at)
    MEM_H(0X2524, ctx->r1) = 0;
    // 0x800316D4: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x800316D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800316DC: sh          $t8, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r24;
    // 0x800316E0: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x800316E4: lbu         $t9, -0x6A00($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6A00);
    // 0x800316E8: nop

    // 0x800316EC: beq         $t9, $zero, L_80031700
    if (ctx->r25 == 0) {
        // 0x800316F0: nop
    
            goto L_80031700;
    }
    // 0x800316F0: nop

    // 0x800316F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800316F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800316FC: swc1        $f4, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f4.u32l;
L_80031700:
    // 0x80031700: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80031704: sh          $zero, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = 0;
    // 0x80031708: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003170C: sh          $zero, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = 0;
    // 0x80031710: jr          $ra
    // 0x80031714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80075604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007560C: jal         0x80061348
    // 0x80075610: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075610: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x80075614: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075618: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007561C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075620: beq         $v0, $zero, L_80075674
    if (ctx->r2 == 0) {
        // 0x80075624: nop
    
            goto L_80075674;
    }
    // 0x80075624: nop

    // 0x80075628: jal         0x80061348
    // 0x8007562C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007562C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075630: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075634: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075638: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007563C: beq         $v0, $zero, L_80075674
    if (ctx->r2 == 0) {
        // 0x80075640: nop
    
            goto L_80075674;
    }
    // 0x80075640: nop

    // 0x80075644: jal         0x80061348
    // 0x80075648: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075648: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x8007564C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075650: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075654: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075658: beq         $v0, $zero, L_80075674
    if (ctx->r2 == 0) {
        // 0x8007565C: nop
    
            goto L_80075674;
    }
    // 0x8007565C: nop

    // 0x80075660: jal         0x80061348
    // 0x80075664: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075664: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075668: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007566C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075670: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075674:
    // 0x80075674: b           L_80075684
    // 0x80075678: nop

        goto L_80075684;
    // 0x80075678: nop

    // 0x8007567C: b           L_80075684
    // 0x80075680: nop

        goto L_80075684;
    // 0x80075680: nop

L_80075684:
    // 0x80075684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007568C: jr          $ra
    // 0x80075690: nop

    return;
    // 0x80075690: nop

;}
RECOMP_FUNC void func_80070160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070168: jal         0x80061348
    // 0x8007016C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007016C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070170: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070174: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070178: beq         $v0, $zero, L_800701C8
    if (ctx->r2 == 0) {
        // 0x8007017C: nop
    
            goto L_800701C8;
    }
    // 0x8007017C: nop

    // 0x80070180: jal         0x80061348
    // 0x80070184: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070184: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070188: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007018C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070190: beq         $v0, $zero, L_800701C8
    if (ctx->r2 == 0) {
        // 0x80070194: nop
    
            goto L_800701C8;
    }
    // 0x80070194: nop

    // 0x80070198: jal         0x80061348
    // 0x8007019C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007019C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800701A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800701A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800701A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800701AC: beq         $v0, $zero, L_800701C8
    if (ctx->r2 == 0) {
        // 0x800701B0: nop
    
            goto L_800701C8;
    }
    // 0x800701B0: nop

    // 0x800701B4: jal         0x80061348
    // 0x800701B8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800701B8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800701BC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800701C0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800701C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800701C8:
    // 0x800701C8: b           L_800701D8
    // 0x800701CC: nop

        goto L_800701D8;
    // 0x800701CC: nop

    // 0x800701D0: b           L_800701D8
    // 0x800701D4: nop

        goto L_800701D8;
    // 0x800701D4: nop

L_800701D8:
    // 0x800701D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800701DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800701E0: jr          $ra
    // 0x800701E4: nop

    return;
    // 0x800701E4: nop

;}
RECOMP_FUNC void func_8008BA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BA24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008BA28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BA2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008BA30: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008BA34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008BA38: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008BA3C: lwc1        $f4, 0xBD4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XBD4);
    // 0x8008BA40: nop

    // 0x8008BA44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008BA48: swc1        $f8, 0xBD4($t6)
    MEM_W(0XBD4, ctx->r14) = ctx->f8.u32l;
    // 0x8008BA4C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008BA50: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8008BA54: lwc1        $f10, 0xBD4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XBD4);
    // 0x8008BA58: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008BA5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008BA60: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8008BA64: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8008BA68: nop

    // 0x8008BA6C: bc1f        L_8008BAEC
    if (!c1cs) {
        // 0x8008BA70: nop
    
            goto L_8008BAEC;
    }
    // 0x8008BA70: nop

L_8008BA74:
    // 0x8008BA74: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8008BA78: nop

    // 0x8008BA7C: lh          $t9, 0xBD8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XBD8);
    // 0x8008BA80: nop

    // 0x8008BA84: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008BA88: bgez        $t0, L_8008BA9C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8008BA8C: andi        $t1, $t0, 0x3
        ctx->r9 = ctx->r8 & 0X3;
            goto L_8008BA9C;
    }
    // 0x8008BA8C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x8008BA90: beq         $t1, $zero, L_8008BA9C
    if (ctx->r9 == 0) {
        // 0x8008BA94: nop
    
            goto L_8008BA9C;
    }
    // 0x8008BA94: nop

    // 0x8008BA98: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_8008BA9C:
    // 0x8008BA9C: sh          $t1, 0xBD8($t8)
    MEM_H(0XBD8, ctx->r24) = ctx->r9;
    // 0x8008BAA0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008BAA4: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8008BAA8: lwc1        $f4, 0xBD4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XBD4);
    // 0x8008BAAC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008BAB0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008BAB4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008BAB8: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8008BABC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8008BAC0: swc1        $f16, 0xBD4($t2)
    MEM_W(0XBD4, ctx->r10) = ctx->f16.u32l;
    // 0x8008BAC4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8008BAC8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8008BACC: lwc1        $f18, 0xBD4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XBD4);
    // 0x8008BAD0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008BAD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008BAD8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8008BADC: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8008BAE0: nop

    // 0x8008BAE4: bc1t        L_8008BA74
    if (c1cs) {
        // 0x8008BAE8: nop
    
            goto L_8008BA74;
    }
    // 0x8008BAE8: nop

L_8008BAEC:
    // 0x8008BAEC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008BAF0: addiu       $a0, $a0, -0xA98
    ctx->r4 = ADD32(ctx->r4, -0XA98);
    // 0x8008BAF4: jal         0x8008ECE4
    // 0x8008BAF8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8008BAF8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_0:
    // 0x8008BAFC: addiu       $t4, $zero, 0xBB
    ctx->r12 = ADD32(0, 0XBB);
    // 0x8008BB00: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BB04: sw          $t4, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r12;
    // 0x8008BB08: addiu       $t5, $zero, 0x82
    ctx->r13 = ADD32(0, 0X82);
    // 0x8008BB0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BB10: sw          $t5, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r13;
    // 0x8008BB14: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8008BB18:
    // 0x8008BB18: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008BB1C: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x8008BB20: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008BB24: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008BB28: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x8008BB2C: addiu       $a1, $a1, -0xA94
    ctx->r5 = ADD32(ctx->r5, -0XA94);
    // 0x8008BB30: jal         0x800BCFCC
    // 0x8008BB34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x8008BB34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x8008BB38: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008BB3C: nop

    // 0x8008BB40: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008BB44: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8008BB48: bne         $at, $zero, L_8008BB18
    if (ctx->r1 != 0) {
        // 0x8008BB4C: sw          $t1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r9;
            goto L_8008BB18;
    }
    // 0x8008BB4C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008BB50: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x8008BB54: sb          $zero, 0xA($t8)
    MEM_B(0XA, ctx->r24) = 0;
    // 0x8008BB58: jal         0x8008ECE4
    // 0x8008BB5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8008BB5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8008BB60: addiu       $t2, $zero, 0xBB
    ctx->r10 = ADD32(0, 0XBB);
    // 0x8008BB64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BB68: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x8008BB6C: addiu       $t3, $zero, 0x82
    ctx->r11 = ADD32(0, 0X82);
    // 0x8008BB70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BB74: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8008BB78: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008BB7C: addiu       $a1, $a1, -0xA90
    ctx->r5 = ADD32(ctx->r5, -0XA90);
    // 0x8008BB80: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8008BB84: jal         0x800BCFCC
    // 0x8008BB88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x8008BB88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x8008BB8C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008BB90: addiu       $t4, $sp, 0x1C
    ctx->r12 = ADD32(ctx->r29, 0X1C);
    // 0x8008BB94: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x8008BB98: lh          $t7, 0xBE8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XBE8);
    // 0x8008BB9C: nop

    // 0x8008BBA0: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8008BBA4: sb          $t9, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r25;
    // 0x8008BBA8: jal         0x8008ECE4
    // 0x8008BBAC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8008BBAC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x8008BBB0: addiu       $t0, $zero, 0xEF
    ctx->r8 = ADD32(0, 0XEF);
    // 0x8008BBB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BBB8: sw          $t0, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r8;
    // 0x8008BBBC: addiu       $t1, $zero, 0x82
    ctx->r9 = ADD32(0, 0X82);
    // 0x8008BBC0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BBC4: sw          $t1, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r9;
    // 0x8008BBC8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008BBCC: addiu       $a1, $a1, -0xA8C
    ctx->r5 = ADD32(ctx->r5, -0XA8C);
    // 0x8008BBD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8008BBD4: jal         0x800BCFCC
    // 0x8008BBD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x8008BBD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x8008BBDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8008BBE0: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x8008BBE4: lbu         $t2, 0x1($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X1);
    // 0x8008BBE8: lh          $t6, 0xBEA($t3)
    ctx->r14 = MEM_H(ctx->r11, 0XBEA);
    // 0x8008BBEC: nop

    // 0x8008BBF0: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x8008BBF4: sb          $t5, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r13;
    // 0x8008BBF8: jal         0x8008ECE4
    // 0x8008BBFC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8008BBFC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_6:
    // 0x8008BC00: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008BC04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008BC08: lh          $t9, 0xBD8($t7)
    ctx->r25 = MEM_H(ctx->r15, 0XBD8);
    // 0x8008BC0C: nop

    // 0x8008BC10: beq         $t9, $at, L_8008BC58
    if (ctx->r25 == ctx->r1) {
        // 0x8008BC14: nop
    
            goto L_8008BC58;
    }
    // 0x8008BC14: nop

    // 0x8008BC18: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008BC1C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BC20: lh          $t0, 0xBD8($t4)
    ctx->r8 = MEM_H(ctx->r12, 0XBD8);
    // 0x8008BC24: nop

    // 0x8008BC28: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8008BC2C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8008BC30: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008BC34: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8008BC38: addiu       $t3, $t1, 0xC8
    ctx->r11 = ADD32(ctx->r9, 0XC8);
    // 0x8008BC3C: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x8008BC40: addiu       $t2, $zero, 0x82
    ctx->r10 = ADD32(0, 0X82);
    // 0x8008BC44: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BC48: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x8008BC4C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008BC50: jal         0x8008ECE4
    // 0x8008BC54: addiu       $a0, $a0, -0xA88
    ctx->r4 = ADD32(ctx->r4, -0XA88);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8008BC54: addiu       $a0, $a0, -0xA88
    ctx->r4 = ADD32(ctx->r4, -0XA88);
    after_7:
L_8008BC58:
    // 0x8008BC58: b           L_8008BC60
    // 0x8008BC5C: nop

        goto L_8008BC60;
    // 0x8008BC5C: nop

L_8008BC60:
    // 0x8008BC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BC64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008BC68: jr          $ra
    // 0x8008BC6C: nop

    return;
    // 0x8008BC6C: nop

;}
RECOMP_FUNC void func_80076DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076DF8: jal         0x80061348
    // 0x80076DFC: addiu       $a0, $zero, 0x43F
    ctx->r4 = ADD32(0, 0X43F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076DFC: addiu       $a0, $zero, 0x43F
    ctx->r4 = ADD32(0, 0X43F);
    after_0:
    // 0x80076E00: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076E04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076E08: beq         $v0, $zero, L_80076E20
    if (ctx->r2 == 0) {
        // 0x80076E0C: nop
    
            goto L_80076E20;
    }
    // 0x80076E0C: nop

    // 0x80076E10: jal         0x8005F064
    // 0x80076E14: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80076E14: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_1:
    // 0x80076E18: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80076E1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80076E20:
    // 0x80076E20: b           L_80076E30
    // 0x80076E24: nop

        goto L_80076E30;
    // 0x80076E24: nop

    // 0x80076E28: b           L_80076E30
    // 0x80076E2C: nop

        goto L_80076E30;
    // 0x80076E2C: nop

L_80076E30:
    // 0x80076E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076E38: jr          $ra
    // 0x80076E3C: nop

    return;
    // 0x80076E3C: nop

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
RECOMP_FUNC void func_800131F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800131F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800131F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800131FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80013200: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80013204: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80013208: jal         0x8000DA44
    // 0x8001320C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x8001320C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80013210: bgez        $v0, L_80013220
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013214: nop
    
            goto L_80013220;
    }
    // 0x80013214: nop

    // 0x80013218: b           L_80013388
    // 0x8001321C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013388;
    // 0x8001321C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013220:
    // 0x80013220: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80013224: nop

    // 0x80013228: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001322C: nop

    // 0x80013230: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80013234: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x80013238: lhu         $a0, 0x4($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X4);
    // 0x8001323C: jal         0x8000D688
    // 0x80013240: nop

    func_8000D688(rdram, ctx);
        goto after_1;
    // 0x80013240: nop

    after_1:
    // 0x80013244: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80013248: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8001324C: nop

    // 0x80013250: bne         $t9, $zero, L_80013260
    if (ctx->r25 != 0) {
        // 0x80013254: nop
    
            goto L_80013260;
    }
    // 0x80013254: nop

    // 0x80013258: b           L_80013388
    // 0x8001325C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013388;
    // 0x8001325C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013260:
    // 0x80013260: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80013264: nop

    // 0x80013268: lw          $t1, 0x20C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20C);
    // 0x8001326C: nop

    // 0x80013270: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80013274: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80013278: nop

    // 0x8001327C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80013280: nop

    // 0x80013284: lw          $t4, 0xC8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC8);
    // 0x80013288: nop

    // 0x8001328C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80013290: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80013294: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80013298: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8001329C: nop

    // 0x800132A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800132A4: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x800132A8: nop

    // 0x800132AC: blez        $t7, L_80013300
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800132B0: nop
    
            goto L_80013300;
    }
    // 0x800132B0: nop

L_800132B4:
    // 0x800132B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800132B8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800132BC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800132C0: nop

    // 0x800132C4: lw          $t0, 0xC8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC8);
    // 0x800132C8: nop

    // 0x800132CC: sw          $t0, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r8;
    // 0x800132D0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800132D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800132D8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800132DC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800132E0: addiu       $t6, $t4, 0x160
    ctx->r14 = ADD32(ctx->r12, 0X160);
    // 0x800132E4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800132E8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800132EC: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x800132F0: nop

    // 0x800132F4: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800132F8: bne         $at, $zero, L_800132B4
    if (ctx->r1 != 0) {
        // 0x800132FC: nop
    
            goto L_800132B4;
    }
    // 0x800132FC: nop

L_80013300:
    // 0x80013300: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80013304: nop

    // 0x80013308: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8001330C: nop

    // 0x80013310: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80013314: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80013318: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8001331C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80013320: nop

    // 0x80013324: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80013328: lhu         $t2, 0x6($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X6);
    // 0x8001332C: nop

    // 0x80013330: blez        $t2, L_80013378
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80013334: nop
    
            goto L_80013378;
    }
    // 0x80013334: nop

L_80013338:
    // 0x80013338: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8001333C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80013340: nop

    // 0x80013344: sw          $t4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r12;
    // 0x80013348: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8001334C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80013350: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80013354: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x80013358: addiu       $t8, $t7, 0x160
    ctx->r24 = ADD32(ctx->r15, 0X160);
    // 0x8001335C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80013360: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80013364: lhu         $t1, 0x6($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X6);
    // 0x80013368: nop

    // 0x8001336C: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80013370: bne         $at, $zero, L_80013338
    if (ctx->r1 != 0) {
        // 0x80013374: nop
    
            goto L_80013338;
    }
    // 0x80013374: nop

L_80013378:
    // 0x80013378: b           L_80013388
    // 0x8001337C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013388;
    // 0x8001337C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013380: b           L_80013388
    // 0x80013384: nop

        goto L_80013388;
    // 0x80013384: nop

L_80013388:
    // 0x80013388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001338C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80013390: jr          $ra
    // 0x80013394: nop

    return;
    // 0x80013394: nop

;}
RECOMP_FUNC void func_80063A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A8C: jal         0x8005F064
    // 0x80063A90: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063A90: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063A94: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063A98: b           L_80063AA8
    // 0x80063A9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063AA8;
    // 0x80063A9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063AA0: b           L_80063AA8
    // 0x80063AA4: nop

        goto L_80063AA8;
    // 0x80063AA4: nop

L_80063AA8:
    // 0x80063AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063AB0: jr          $ra
    // 0x80063AB4: nop

    return;
    // 0x80063AB4: nop

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
