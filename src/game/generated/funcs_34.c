#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80069C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069C08: jal         0x80061348
    // 0x80069C0C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069C0C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x80069C10: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069C14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069C18: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069C1C: beq         $v0, $zero, L_80069C38
    if (ctx->r2 == 0) {
        // 0x80069C20: nop
    
            goto L_80069C38;
    }
    // 0x80069C20: nop

    // 0x80069C24: jal         0x80061348
    // 0x80069C28: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069C28: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    after_1:
    // 0x80069C2C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069C30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069C34: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80069C38:
    // 0x80069C38: b           L_80069C48
    // 0x80069C3C: nop

        goto L_80069C48;
    // 0x80069C3C: nop

    // 0x80069C40: b           L_80069C48
    // 0x80069C44: nop

        goto L_80069C48;
    // 0x80069C44: nop

L_80069C48:
    // 0x80069C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069C50: jr          $ra
    // 0x80069C54: nop

    return;
    // 0x80069C54: nop

;}
RECOMP_FUNC void AudioDriver_GetSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B97E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B97E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B97EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B97F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B97F4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B97F8: lw          $t6, -0x17E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17E0);
    // 0x800B97FC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B9800: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B9804: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800B9808: nop

    // 0x800B980C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800B9810: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800B9814: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B9818: lw          $t1, -0x17E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17E0);
    // 0x800B981C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800B9820: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800B9824: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800B9828: nop

    // 0x800B982C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800B9830: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9834: nop

    // 0x800B9838: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x800B983C: beq         $t6, $zero, L_800B9854
    if (ctx->r14 == 0) {
        // 0x800B9840: nop
    
            goto L_800B9854;
    }
    // 0x800B9840: nop

    // 0x800B9844: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9848: nop

    // 0x800B984C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B9850: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_800B9854:
    // 0x800B9854: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9858: lw          $a1, -0x17D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17D4);
    // 0x800B985C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B9860: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9864: jal         0x800BC590
    // 0x800B9868: nop

    AudioDmaCopy(rdram, ctx);
        goto after_0;
    // 0x800B9868: nop

    after_0:
    // 0x800B986C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9870: b           L_800B9880
    // 0x800B9874: nop

        goto L_800B9880;
    // 0x800B9874: nop

    // 0x800B9878: b           L_800B9880
    // 0x800B987C: nop

        goto L_800B9880;
    // 0x800B987C: nop

L_800B9880:
    // 0x800B9880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9888: jr          $ra
    // 0x800B988C: nop

    return;
    // 0x800B988C: nop

;}
RECOMP_FUNC void func_80062DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062DBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062DC4: jal         0x80061488
    // 0x80062DC8: addiu       $a0, $zero, 0x6A9
    ctx->r4 = ADD32(0, 0X6A9);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062DC8: addiu       $a0, $zero, 0x6A9
    ctx->r4 = ADD32(0, 0X6A9);
    after_0:
    // 0x80062DCC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062DD0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062DD4: b           L_80062DE4
    // 0x80062DD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062DE4;
    // 0x80062DD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062DDC: b           L_80062DE4
    // 0x80062DE0: nop

        goto L_80062DE4;
    // 0x80062DE0: nop

L_80062DE4:
    // 0x80062DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062DEC: jr          $ra
    // 0x80062DF0: nop

    return;
    // 0x80062DF0: nop

;}
RECOMP_FUNC void func_8008C160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C160: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C164: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8008C168: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8008C16C:
    // 0x8008C16C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008C170: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008C174: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008C178: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008C17C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008C180: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008C184: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8008C188: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008C18C: lhu         $t8, 0x7AE8($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7AE8);
    // 0x8008C190: nop

    // 0x8008C194: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008C198: beq         $t9, $zero, L_8008C1BC
    if (ctx->r25 == 0) {
        // 0x8008C19C: nop
    
            goto L_8008C1BC;
    }
    // 0x8008C19C: nop

    // 0x8008C1A0: andi        $t0, $t8, 0x4000
    ctx->r8 = ctx->r24 & 0X4000;
    // 0x8008C1A4: beq         $t0, $zero, L_8008C1BC
    if (ctx->r8 == 0) {
        // 0x8008C1A8: nop
    
            goto L_8008C1BC;
    }
    // 0x8008C1A8: nop

    // 0x8008C1AC: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8008C1B0: nop

    // 0x8008C1B4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008C1B8: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_8008C1BC:
    // 0x8008C1BC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008C1C0: nop

    // 0x8008C1C4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008C1C8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8008C1CC: bne         $at, $zero, L_8008C16C
    if (ctx->r1 != 0) {
        // 0x8008C1D0: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8008C16C;
    }
    // 0x8008C1D0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008C1D4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008C1D8: b           L_8008C1E8
    // 0x8008C1DC: nop

        goto L_8008C1E8;
    // 0x8008C1DC: nop

    // 0x8008C1E0: b           L_8008C1E8
    // 0x8008C1E4: nop

        goto L_8008C1E8;
    // 0x8008C1E4: nop

L_8008C1E8:
    // 0x8008C1E8: jr          $ra
    // 0x8008C1EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C1EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80042C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042C60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80042C64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042C68: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80042C6C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80042C70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042C74: jal         0x800C4240
    // 0x80042C78: nop

    guRandom(rdram, ctx);
        goto after_0;
    // 0x80042C78: nop

    after_0:
    // 0x80042C7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80042C80: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80042C84: mfhi        $t6
    ctx->r14 = hi;
    // 0x80042C88: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80042C8C: bne         $at, $zero, L_80042D10
    if (ctx->r1 != 0) {
        // 0x80042C90: nop
    
            goto L_80042D10;
    }
    // 0x80042C90: nop

    // 0x80042C94: jal         0x800C4240
    // 0x80042C98: nop

    guRandom(rdram, ctx);
        goto after_1;
    // 0x80042C98: nop

    after_1:
    // 0x80042C9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80042CA0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80042CA4: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x80042CA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80042CAC: lwc1        $f9, -0x1298($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1298);
    // 0x80042CB0: lwc1        $f8, -0x1294($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1294);
    // 0x80042CB4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80042CB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80042CBC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80042CC0: lwc1        $f16, -0x128C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X128C);
    // 0x80042CC4: lwc1        $f17, -0x1290($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1290);
    // 0x80042CC8: mfhi        $t7
    ctx->r15 = hi;
    // 0x80042CCC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80042CD0: nop

    // 0x80042CD4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80042CD8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80042CDC: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80042CE0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80042CE4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80042CE8: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80042CEC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80042CF0: bc1f        L_80042D08
    if (!c1cs) {
        // 0x80042CF4: nop
    
            goto L_80042D08;
    }
    // 0x80042CF4: nop

    // 0x80042CF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80042CFC: lwc1        $f18, -0x1288($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1288);
    // 0x80042D00: nop

    // 0x80042D04: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_80042D08:
    // 0x80042D08: b           L_80042D78
    // 0x80042D0C: nop

        goto L_80042D78;
    // 0x80042D0C: nop

L_80042D10:
    // 0x80042D10: jal         0x800C4240
    // 0x80042D14: nop

    guRandom(rdram, ctx);
        goto after_2;
    // 0x80042D14: nop

    after_2:
    // 0x80042D18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80042D1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80042D20: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x80042D24: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80042D28: lwc1        $f7, -0x1280($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1280);
    // 0x80042D2C: lwc1        $f6, -0x127C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X127C);
    // 0x80042D30: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80042D34: nop

    // 0x80042D38: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80042D3C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80042D40: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80042D44: nop

    // 0x80042D48: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80042D4C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80042D50: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80042D54: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x80042D58: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80042D5C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80042D60: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80042D64: bc1f        L_80042D78
    if (!c1cs) {
        // 0x80042D68: nop
    
            goto L_80042D78;
    }
    // 0x80042D68: nop

    // 0x80042D6C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80042D70: nop

    // 0x80042D74: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
L_80042D78:
    // 0x80042D78: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80042D7C: b           L_80042D8C
    // 0x80042D80: nop

        goto L_80042D8C;
    // 0x80042D80: nop

    // 0x80042D84: b           L_80042D8C
    // 0x80042D88: nop

        goto L_80042D8C;
    // 0x80042D88: nop

L_80042D8C:
    // 0x80042D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042D94: jr          $ra
    // 0x80042D98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80042D98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800B9E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9E90: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B9E94:
    // 0x800B9E94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9E98: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9E9C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B9EA0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B9EA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9EA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B9EAC: lw          $t8, -0x1A64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1A64);
    // 0x800B9EB0: nop

    // 0x800B9EB4: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800B9EB8: beq         $t9, $zero, L_800B9EE0
    if (ctx->r25 == 0) {
        // 0x800B9EBC: nop
    
            goto L_800B9EE0;
    }
    // 0x800B9EBC: nop

    // 0x800B9EC0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9EC4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800B9EC8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800B9ECC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B9ED0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B9ED4: addiu       $t2, $t2, -0x1A68
    ctx->r10 = ADD32(ctx->r10, -0X1A68);
    // 0x800B9ED8: jal         0x800BA748
    // 0x800B9EDC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    func_800BA748(rdram, ctx);
        goto after_0;
    // 0x800B9EDC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_0:
L_800B9EE0:
    // 0x800B9EE0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9EE4: nop

    // 0x800B9EE8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B9EEC: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800B9EF0: bne         $at, $zero, L_800B9E94
    if (ctx->r1 != 0) {
        // 0x800B9EF4: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B9E94;
    }
    // 0x800B9EF4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B9EF8: b           L_800B9F00
    // 0x800B9EFC: nop

        goto L_800B9F00;
    // 0x800B9EFC: nop

L_800B9F00:
    // 0x800B9F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9F04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9F08: jr          $ra
    // 0x800B9F0C: nop

    return;
    // 0x800B9F0C: nop

;}
RECOMP_FUNC void func_80098C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098C40: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098C44: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098C48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098C4C: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80098C50: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098C54: jr          $ra
    // 0x80098C58: nop

    return;
    // 0x80098C58: nop

    // 0x80098C5C: jr          $ra
    // 0x80098C60: nop

    return;
    // 0x80098C60: nop

;}
RECOMP_FUNC void func_8002206C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002206C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022074: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80022078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002207C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80022080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80022084: jal         0x800BB448
    // 0x80022088: nop

    func_800BB448(rdram, ctx);
        goto after_0;
    // 0x80022088: nop

    after_0:
    // 0x8002208C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80022090: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80022094: nop

    // 0x80022098: bne         $t6, $zero, L_800220A8
    if (ctx->r14 != 0) {
        // 0x8002209C: nop
    
            goto L_800220A8;
    }
    // 0x8002209C: nop

    // 0x800220A0: b           L_800220E4
    // 0x800220A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800220E4;
    // 0x800220A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800220A8:
    // 0x800220A8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800220AC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800220B0: nop

    // 0x800220B4: sw          $t7, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r15;
    // 0x800220B8: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x800220BC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800220C0: nop

    // 0x800220C4: sb          $t9, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = ctx->r25;
    // 0x800220C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800220CC: jal         0x800BB4B4
    // 0x800220D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BB4B4(rdram, ctx);
        goto after_1;
    // 0x800220D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800220D4: b           L_800220E4
    // 0x800220D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800220E4;
    // 0x800220D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800220DC: b           L_800220E4
    // 0x800220E0: nop

        goto L_800220E4;
    // 0x800220E0: nop

L_800220E4:
    // 0x800220E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800220E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800220EC: jr          $ra
    // 0x800220F0: nop

    return;
    // 0x800220F0: nop

;}
RECOMP_FUNC void func_8006F1EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F1F0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F1F4: nop

    // 0x8006F1F8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F1FC: nop

    // 0x8006F200: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F204: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F208: jr          $ra
    // 0x8006F20C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F20C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F210: jr          $ra
    // 0x8006F214: nop

    return;
    // 0x8006F214: nop

    // 0x8006F218: jr          $ra
    // 0x8006F21C: nop

    return;
    // 0x8006F21C: nop

;}
RECOMP_FUNC void func_8006B9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B9BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B9C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B9C4: jal         0x80061488
    // 0x8006B9C8: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006B9C8: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    after_0:
    // 0x8006B9CC: slti        $t6, $v0, 0x5
    ctx->r14 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8006B9D0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006B9D4: b           L_8006B9E4
    // 0x8006B9D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006B9E4;
    // 0x8006B9D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B9DC: b           L_8006B9E4
    // 0x8006B9E0: nop

        goto L_8006B9E4;
    // 0x8006B9E0: nop

L_8006B9E4:
    // 0x8006B9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B9E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B9EC: jr          $ra
    // 0x8006B9F0: nop

    return;
    // 0x8006B9F0: nop

;}
RECOMP_FUNC void SoundDebugMenu_SfxTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021AE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021AE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80021AE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80021AEC: nop

    // 0x80021AF0: bltz        $t6, L_80021D3C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80021AF4: nop
    
            goto L_80021D3C;
    }
    // 0x80021AF4: nop

    // 0x80021AF8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80021AFC: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80021B00: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80021B04: lhu         $t9, 0xEEC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEEC);
    // 0x80021B08: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80021B0C: nop

    // 0x80021B10: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80021B14: beq         $t0, $zero, L_80021B30
    if (ctx->r8 == 0) {
        // 0x80021B18: nop
    
            goto L_80021B30;
    }
    // 0x80021B18: nop

    // 0x80021B1C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021B20: lw          $t1, -0x33B8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33B8);
    // 0x80021B24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021B28: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021B2C: sw          $t2, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = ctx->r10;
L_80021B30:
    // 0x80021B30: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80021B34: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80021B38: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021B3C: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x80021B40: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80021B44: nop

    // 0x80021B48: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80021B4C: beq         $t6, $zero, L_80021B68
    if (ctx->r14 == 0) {
        // 0x80021B50: nop
    
            goto L_80021B68;
    }
    // 0x80021B50: nop

    // 0x80021B54: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80021B58: lw          $t7, -0x33B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33B8);
    // 0x80021B5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021B60: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80021B64: sw          $t8, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = ctx->r24;
L_80021B68:
    // 0x80021B68: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80021B6C: lw          $t9, -0x33B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33B8);
    // 0x80021B70: nop

    // 0x80021B74: bgez        $t9, L_80021B84
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80021B78: nop
    
            goto L_80021B84;
    }
    // 0x80021B78: nop

    // 0x80021B7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021B80: sw          $zero, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = 0;
L_80021B84:
    // 0x80021B84: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80021B88: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80021B8C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021B90: lhu         $t2, 0x1258($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1258);
    // 0x80021B94: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x80021B98: nop

    // 0x80021B9C: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80021BA0: beq         $t3, $zero, L_80021BD4
    if (ctx->r11 == 0) {
        // 0x80021BA4: nop
    
            goto L_80021BD4;
    }
    // 0x80021BA4: nop

    // 0x80021BA8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80021BAC: lh          $t4, -0x48B0($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X48B0);
    // 0x80021BB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021BB4: addiu       $t5, $t4, 0x64
    ctx->r13 = ADD32(ctx->r12, 0X64);
    // 0x80021BB8: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80021BBC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80021BC0: bgtz        $t7, L_80021BD4
    if (SIGNED(ctx->r15) > 0) {
        // 0x80021BC4: sh          $t5, -0x48B0($at)
        MEM_H(-0X48B0, ctx->r1) = ctx->r13;
            goto L_80021BD4;
    }
    // 0x80021BC4: sh          $t5, -0x48B0($at)
    MEM_H(-0X48B0, ctx->r1) = ctx->r13;
    // 0x80021BC8: addiu       $t8, $zero, 0x7FFF
    ctx->r24 = ADD32(0, 0X7FFF);
    // 0x80021BCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021BD0: sh          $t8, -0x48B0($at)
    MEM_H(-0X48B0, ctx->r1) = ctx->r24;
L_80021BD4:
    // 0x80021BD4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80021BD8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80021BDC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80021BE0: lhu         $t1, 0x1260($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1260);
    // 0x80021BE4: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x80021BE8: nop

    // 0x80021BEC: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x80021BF0: beq         $t2, $zero, L_80021C20
    if (ctx->r10 == 0) {
        // 0x80021BF4: nop
    
            goto L_80021C20;
    }
    // 0x80021BF4: nop

    // 0x80021BF8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80021BFC: lh          $t3, -0x48B0($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X48B0);
    // 0x80021C00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021C04: addiu       $t4, $t3, -0x64
    ctx->r12 = ADD32(ctx->r11, -0X64);
    // 0x80021C08: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80021C0C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80021C10: bgez        $t6, L_80021C20
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80021C14: sh          $t4, -0x48B0($at)
        MEM_H(-0X48B0, ctx->r1) = ctx->r12;
            goto L_80021C20;
    }
    // 0x80021C14: sh          $t4, -0x48B0($at)
    MEM_H(-0X48B0, ctx->r1) = ctx->r12;
    // 0x80021C18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021C1C: sh          $zero, -0x48B0($at)
    MEM_H(-0X48B0, ctx->r1) = 0;
L_80021C20:
    // 0x80021C20: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80021C24: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80021C28: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80021C2C: lhu         $t9, 0x126C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X126C);
    // 0x80021C30: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80021C34: nop

    // 0x80021C38: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80021C3C: beq         $t0, $zero, L_80021C78
    if (ctx->r8 == 0) {
        // 0x80021C40: nop
    
            goto L_80021C78;
    }
    // 0x80021C40: nop

    // 0x80021C44: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80021C48: lh          $t1, -0x48AC($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X48AC);
    // 0x80021C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021C50: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021C54: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80021C58: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80021C5C: sh          $t2, -0x48AC($at)
    MEM_H(-0X48AC, ctx->r1) = ctx->r10;
    // 0x80021C60: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x80021C64: bne         $at, $zero, L_80021C78
    if (ctx->r1 != 0) {
        // 0x80021C68: nop
    
            goto L_80021C78;
    }
    // 0x80021C68: nop

    // 0x80021C6C: addiu       $t5, $zero, 0x7F
    ctx->r13 = ADD32(0, 0X7F);
    // 0x80021C70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021C74: sh          $t5, -0x48AC($at)
    MEM_H(-0X48AC, ctx->r1) = ctx->r13;
L_80021C78:
    // 0x80021C78: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80021C7C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80021C80: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021C84: lhu         $t8, 0x11AC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X11AC);
    // 0x80021C88: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x80021C8C: nop

    // 0x80021C90: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80021C94: beq         $t9, $zero, L_80021CC4
    if (ctx->r25 == 0) {
        // 0x80021C98: nop
    
            goto L_80021CC4;
    }
    // 0x80021C98: nop

    // 0x80021C9C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80021CA0: lh          $t0, -0x48AC($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X48AC);
    // 0x80021CA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021CA8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80021CAC: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80021CB0: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80021CB4: bgez        $t3, L_80021CC4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80021CB8: sh          $t1, -0x48AC($at)
        MEM_H(-0X48AC, ctx->r1) = ctx->r9;
            goto L_80021CC4;
    }
    // 0x80021CB8: sh          $t1, -0x48AC($at)
    MEM_H(-0X48AC, ctx->r1) = ctx->r9;
    // 0x80021CBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021CC0: sh          $zero, -0x48AC($at)
    MEM_H(-0X48AC, ctx->r1) = 0;
L_80021CC4:
    // 0x80021CC4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80021CC8: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80021CCC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80021CD0: lhu         $t6, 0xFF4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XFF4);
    // 0x80021CD4: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80021CD8: nop

    // 0x80021CDC: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x80021CE0: beq         $t7, $zero, L_80021D08
    if (ctx->r15 == 0) {
        // 0x80021CE4: nop
    
            goto L_80021D08;
    }
    // 0x80021CE4: nop

    // 0x80021CE8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80021CEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80021CF0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80021CF4: lh          $a2, -0x48AC($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X48AC);
    // 0x80021CF8: lh          $a1, -0x48B0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X48B0);
    // 0x80021CFC: lw          $a0, -0x33B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33B8);
    // 0x80021D00: jal         0x8002206C
    // 0x80021D04: nop

    func_8002206C(rdram, ctx);
        goto after_0;
    // 0x80021D04: nop

    after_0:
L_80021D08:
    // 0x80021D08: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80021D0C: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80021D10: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021D14: lhu         $t0, 0x101C($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X101C);
    // 0x80021D18: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x80021D1C: nop

    // 0x80021D20: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x80021D24: beq         $t1, $zero, L_80021D3C
    if (ctx->r9 == 0) {
        // 0x80021D28: nop
    
            goto L_80021D3C;
    }
    // 0x80021D28: nop

    // 0x80021D2C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80021D30: lw          $a0, -0x33B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33B8);
    // 0x80021D34: jal         0x800220F4
    // 0x80021D38: nop

    func_800220F4(rdram, ctx);
        goto after_1;
    // 0x80021D38: nop

    after_1:
L_80021D3C:
    // 0x80021D3C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80021D40: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80021D44: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80021D48: lh          $a3, -0x48AC($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X48AC);
    // 0x80021D4C: lh          $a2, -0x48B0($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X48B0);
    // 0x80021D50: lw          $a1, -0x33B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X33B8);
    // 0x80021D54: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021D58: jal         0x8008ECE4
    // 0x80021D5C: addiu       $a0, $a0, -0x1D10
    ctx->r4 = ADD32(ctx->r4, -0X1D10);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x80021D5C: addiu       $a0, $a0, -0x1D10
    ctx->r4 = ADD32(ctx->r4, -0X1D10);
    after_2:
    // 0x80021D60: b           L_80021D70
    // 0x80021D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021D70;
    // 0x80021D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021D68: b           L_80021D70
    // 0x80021D6C: nop

        goto L_80021D70;
    // 0x80021D6C: nop

L_80021D70:
    // 0x80021D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021D78: jr          $ra
    // 0x80021D7C: nop

    return;
    // 0x80021D7C: nop

;}
RECOMP_FUNC void func_8006D804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D80C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D810: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D814: nop

    // 0x8006D818: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006D81C: nop

    // 0x8006D820: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D824: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D828: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D82C: beq         $v0, $zero, L_8006D860
    if (ctx->r2 == 0) {
        // 0x8006D830: nop
    
            goto L_8006D860;
    }
    // 0x8006D830: nop

    // 0x8006D834: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x8006D838: nop

    // 0x8006D83C: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D840: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006D844: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006D848: beq         $v0, $zero, L_8006D860
    if (ctx->r2 == 0) {
        // 0x8006D84C: nop
    
            goto L_8006D860;
    }
    // 0x8006D84C: nop

    // 0x8006D850: jal         0x8005F064
    // 0x8006D854: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D854: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    after_0:
    // 0x8006D858: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006D85C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006D860:
    // 0x8006D860: b           L_8006D870
    // 0x8006D864: nop

        goto L_8006D870;
    // 0x8006D864: nop

    // 0x8006D868: b           L_8006D870
    // 0x8006D86C: nop

        goto L_8006D870;
    // 0x8006D86C: nop

L_8006D870:
    // 0x8006D870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D878: jr          $ra
    // 0x8006D87C: nop

    return;
    // 0x8006D87C: nop

;}
RECOMP_FUNC void func_80070330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070338: jal         0x80061348
    // 0x8007033C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007033C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070340: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070348: beq         $v0, $zero, L_80070398
    if (ctx->r2 == 0) {
        // 0x8007034C: nop
    
            goto L_80070398;
    }
    // 0x8007034C: nop

    // 0x80070350: jal         0x80061348
    // 0x80070354: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070354: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070358: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007035C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070360: beq         $v0, $zero, L_80070398
    if (ctx->r2 == 0) {
        // 0x80070364: nop
    
            goto L_80070398;
    }
    // 0x80070364: nop

    // 0x80070368: jal         0x80061348
    // 0x8007036C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007036C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070370: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070374: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070378: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007037C: beq         $v0, $zero, L_80070398
    if (ctx->r2 == 0) {
        // 0x80070380: nop
    
            goto L_80070398;
    }
    // 0x80070380: nop

    // 0x80070384: jal         0x80061348
    // 0x80070388: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070388: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x8007038C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070390: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070394: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070398:
    // 0x80070398: b           L_800703A8
    // 0x8007039C: nop

        goto L_800703A8;
    // 0x8007039C: nop

    // 0x800703A0: b           L_800703A8
    // 0x800703A4: nop

        goto L_800703A8;
    // 0x800703A4: nop

L_800703A8:
    // 0x800703A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800703AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800703B0: jr          $ra
    // 0x800703B4: nop

    return;
    // 0x800703B4: nop

;}
RECOMP_FUNC void func_8005007C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005007C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050084: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80050088: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005008C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80050090: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050094: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80050098: nop

    // 0x8005009C: beq         $t6, $t7, L_800500AC
    if (ctx->r14 == ctx->r15) {
        // 0x800500A0: nop
    
            goto L_800500AC;
    }
    // 0x800500A0: nop

    // 0x800500A4: b           L_8005030C
    // 0x800500A8: nop

        goto L_8005030C;
    // 0x800500A8: nop

L_800500AC:
    // 0x800500AC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800500B0: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800500B4: addiu       $at, $zero, 0x93
    ctx->r1 = ADD32(0, 0X93);
    // 0x800500B8: lh          $t9, 0x4A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4A);
    // 0x800500BC: nop

    // 0x800500C0: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x800500C4: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800500C8: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800500CC: beq         $t2, $at, L_800500E8
    if (ctx->r10 == ctx->r1) {
        // 0x800500D0: sh          $t0, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r8;
            goto L_800500E8;
    }
    // 0x800500D0: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    // 0x800500D4: sll         $t3, $t0, 16
    ctx->r11 = S32(ctx->r8 << 16);
    // 0x800500D8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800500DC: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x800500E0: bne         $t4, $at, L_800501E8
    if (ctx->r12 != ctx->r1) {
        // 0x800500E4: nop
    
            goto L_800501E8;
    }
    // 0x800500E4: nop

L_800500E8:
    // 0x800500E8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800500EC: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800500F0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800500F4: lh          $a1, 0x42($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X42);
    // 0x800500F8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800500FC: jal         0x8004EF90
    // 0x80050100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_0;
    // 0x80050100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80050104: jal         0x800B9000
    // 0x80050108: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x80050108: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x8005010C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050110: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80050114: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80050118: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005011C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80050120: swc1        $f4, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f4.u32l;
    // 0x80050124: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050128: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005012C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050130: swc1        $f6, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f6.u32l;
    // 0x80050134: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80050138: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005013C: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80050140: lwc1        $f17, -0x10D0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X10D0);
    // 0x80050144: lwc1        $f16, -0x10CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X10CC);
    // 0x80050148: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005014C: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80050150: nop

    // 0x80050154: bc1f        L_800501C4
    if (!c1cs) {
        // 0x80050158: nop
    
            goto L_800501C4;
    }
    // 0x80050158: nop

L_8005015C:
    // 0x8005015C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050160: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050164: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80050168: lw          $a2, 0x28($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X28);
    // 0x8005016C: jal         0x8005D07C
    // 0x80050170: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8005D07C(rdram, ctx);
        goto after_2;
    // 0x80050170: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x80050174: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80050178: jal         0x800499B0
    // 0x8005017C: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8005017C: nop

    after_3:
    // 0x80050180: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050184: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050188: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005018C: lwc1        $f18, 0x28($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X28);
    // 0x80050190: lwc1        $f4, 0x30($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80050194: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80050198: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005019C: swc1        $f6, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f6.u32l;
    // 0x800501A0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800501A4: lwc1        $f16, -0x10C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X10C4);
    // 0x800501A8: lwc1        $f8, 0x10($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800501AC: lwc1        $f17, -0x10C8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X10C8);
    // 0x800501B0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800501B4: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x800501B8: nop

    // 0x800501BC: bc1t        L_8005015C
    if (c1cs) {
        // 0x800501C0: nop
    
            goto L_8005015C;
    }
    // 0x800501C0: nop

L_800501C4:
    // 0x800501C4: jal         0x80031728
    // 0x800501C8: nop

    func_80031728(rdram, ctx);
        goto after_4;
    // 0x800501C8: nop

    after_4:
    // 0x800501CC: jal         0x80059D80
    // 0x800501D0: nop

    func_80059D80(rdram, ctx);
        goto after_5;
    // 0x800501D0: nop

    after_5:
L_800501D4:
    // 0x800501D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800501D8: jal         0x800499B0
    // 0x800501DC: nop

    func_800499B0(rdram, ctx);
        goto after_6;
    // 0x800501DC: nop

    after_6:
    // 0x800501E0: b           L_800501D4
    // 0x800501E4: nop

        goto L_800501D4;
    // 0x800501E4: nop

L_800501E8:
    // 0x800501E8: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x800501EC: addiu       $at, $zero, 0x88
    ctx->r1 = ADD32(0, 0X88);
    // 0x800501F0: beq         $t0, $at, L_80050204
    if (ctx->r8 == ctx->r1) {
        // 0x800501F4: nop
    
            goto L_80050204;
    }
    // 0x800501F4: nop

    // 0x800501F8: addiu       $at, $zero, 0x8B
    ctx->r1 = ADD32(0, 0X8B);
    // 0x800501FC: bne         $t0, $at, L_80050304
    if (ctx->r8 != ctx->r1) {
        // 0x80050200: nop
    
            goto L_80050304;
    }
    // 0x80050200: nop

L_80050204:
    // 0x80050204: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80050208: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005020C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80050210: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80050214: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    // 0x80050218: jal         0x8004EF90
    // 0x8005021C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_7;
    // 0x8005021C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80050220: jal         0x800B9000
    // 0x80050224: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800B9000(rdram, ctx);
        goto after_8;
    // 0x80050224: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_8:
    // 0x80050228: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005022C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80050230: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050234: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80050238: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005023C: swc1        $f18, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f18.u32l;
    // 0x80050240: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80050244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80050248: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005024C: swc1        $f4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f4.u32l;
    // 0x80050250: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80050254: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80050258: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8005025C: lwc1        $f11, -0x10C0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X10C0);
    // 0x80050260: lwc1        $f10, -0x10BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X10BC);
    // 0x80050264: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80050268: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x8005026C: nop

    // 0x80050270: bc1f        L_800502E0
    if (!c1cs) {
        // 0x80050274: nop
    
            goto L_800502E0;
    }
    // 0x80050274: nop

L_80050278:
    // 0x80050278: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005027C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050280: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80050284: lw          $a2, 0x28($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X28);
    // 0x80050288: jal         0x8005D07C
    // 0x8005028C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_8005D07C(rdram, ctx);
        goto after_9;
    // 0x8005028C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_9:
    // 0x80050290: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80050294: jal         0x800499B0
    // 0x80050298: nop

    func_800499B0(rdram, ctx);
        goto after_10;
    // 0x80050298: nop

    after_10:
    // 0x8005029C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800502A0: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800502A4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800502A8: lwc1        $f16, 0x28($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X28);
    // 0x800502AC: lwc1        $f18, 0x30($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X30);
    // 0x800502B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800502B4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800502B8: swc1        $f4, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f4.u32l;
    // 0x800502BC: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x800502C0: lwc1        $f10, -0x10B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X10B4);
    // 0x800502C4: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800502C8: lwc1        $f11, -0x10B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X10B8);
    // 0x800502CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800502D0: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x800502D4: nop

    // 0x800502D8: bc1t        L_80050278
    if (c1cs) {
        // 0x800502DC: nop
    
            goto L_80050278;
    }
    // 0x800502DC: nop

L_800502E0:
    // 0x800502E0: jal         0x80031728
    // 0x800502E4: nop

    func_80031728(rdram, ctx);
        goto after_11;
    // 0x800502E4: nop

    after_11:
    // 0x800502E8: jal         0x80059D80
    // 0x800502EC: nop

    func_80059D80(rdram, ctx);
        goto after_12;
    // 0x800502EC: nop

    after_12:
L_800502F0:
    // 0x800502F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800502F4: jal         0x800499B0
    // 0x800502F8: nop

    func_800499B0(rdram, ctx);
        goto after_13;
    // 0x800502F8: nop

    after_13:
    // 0x800502FC: b           L_800502F0
    // 0x80050300: nop

        goto L_800502F0;
    // 0x80050300: nop

L_80050304:
    // 0x80050304: b           L_8005030C
    // 0x80050308: nop

        goto L_8005030C;
    // 0x80050308: nop

L_8005030C:
    // 0x8005030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80050314: jr          $ra
    // 0x80050318: nop

    return;
    // 0x80050318: nop

;}
RECOMP_FUNC void alResampleNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF92C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CF930: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CF934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CF938: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF93C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF940: addiu       $a2, $a2, 0xD20
    ctx->r6 = ADD32(ctx->r6, 0XD20);
    // 0x800CF944: addiu       $a1, $a1, 0xE0C
    ctx->r5 = ADD32(ctx->r5, 0XE0C);
    // 0x800CF948: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CF94C: jal         0x800D56B0
    // 0x800CF950: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF950: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800CF954: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800CF958: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CF95C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CF960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CF964: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800CF968: jal         0x800C7950
    // 0x800CF96C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CF96C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CF970: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CF974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CF978: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CF97C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CF980: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CF984: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800CF988: sw          $t7, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r15;
    // 0x800CF98C: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x800CF990: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x800CF994: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x800CF998: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x800CF99C: swc1        $f4, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f4.u32l;
    // 0x800CF9A0: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
    // 0x800CF9A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF9A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CF9AC: jr          $ra
    // 0x800CF9B0: nop

    return;
    // 0x800CF9B0: nop

;}
RECOMP_FUNC void func_8006B57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B57C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B584: jal         0x80061488
    // 0x8006B588: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006B588: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    after_0:
    // 0x8006B58C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006B590: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006B594: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B598: beq         $v0, $zero, L_8006B5BC
    if (ctx->r2 == 0) {
        // 0x8006B59C: nop
    
            goto L_8006B5BC;
    }
    // 0x8006B59C: nop

    // 0x8006B5A0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8006B5A4: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8006B5A8: nop

    // 0x8006B5AC: lh          $v0, 0x2E($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2E);
    // 0x8006B5B0: nop

    // 0x8006B5B4: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B5B8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006B5BC:
    // 0x8006B5BC: b           L_8006B5CC
    // 0x8006B5C0: nop

        goto L_8006B5CC;
    // 0x8006B5C0: nop

    // 0x8006B5C4: b           L_8006B5CC
    // 0x8006B5C8: nop

        goto L_8006B5CC;
    // 0x8006B5C8: nop

L_8006B5CC:
    // 0x8006B5CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B5D4: jr          $ra
    // 0x8006B5D8: nop

    return;
    // 0x8006B5D8: nop

;}
RECOMP_FUNC void func_8006E588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E58C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E590: jal         0x80061348
    // 0x8006E594: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E594: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E598: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E59C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E5A0: beq         $v0, $zero, L_8006E5B8
    if (ctx->r2 == 0) {
        // 0x8006E5A4: nop
    
            goto L_8006E5B8;
    }
    // 0x8006E5A4: nop

    // 0x8006E5A8: jal         0x80061348
    // 0x8006E5AC: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E5AC: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    after_1:
    // 0x8006E5B0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E5B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E5B8:
    // 0x8006E5B8: b           L_8006E5C8
    // 0x8006E5BC: nop

        goto L_8006E5C8;
    // 0x8006E5BC: nop

    // 0x8006E5C0: b           L_8006E5C8
    // 0x8006E5C4: nop

        goto L_8006E5C8;
    // 0x8006E5C4: nop

L_8006E5C8:
    // 0x8006E5C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E5CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E5D0: jr          $ra
    // 0x8006E5D4: nop

    return;
    // 0x8006E5D4: nop

;}
RECOMP_FUNC void func_800997D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800997D8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800997DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800997E0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800997E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800997E8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800997EC: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x800997F0: nop

    // 0x800997F4: slti        $at, $t6, 0x200
    ctx->r1 = SIGNED(ctx->r14) < 0X200 ? 1 : 0;
    // 0x800997F8: bne         $at, $zero, L_80099808
    if (ctx->r1 != 0) {
        // 0x800997FC: nop
    
            goto L_80099808;
    }
    // 0x800997FC: nop

    // 0x80099800: b           L_80099E1C
    // 0x80099804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80099E1C;
    // 0x80099804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80099808:
    // 0x80099808: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8009980C: nop

    // 0x80099810: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x80099814: nop

    // 0x80099818: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8009981C: beq         $t9, $zero, L_8009982C
    if (ctx->r25 == 0) {
        // 0x80099820: nop
    
            goto L_8009982C;
    }
    // 0x80099820: nop

    // 0x80099824: b           L_80099E1C
    // 0x80099828: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80099E1C;
    // 0x80099828: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_8009982C:
    // 0x8009982C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80099830: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80099834: lwc1        $f4, 0xF4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XF4);
    // 0x80099838: nop

    // 0x8009983C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80099840: nop

    // 0x80099844: bc1f        L_8009985C
    if (!c1cs) {
        // 0x80099848: nop
    
            goto L_8009985C;
    }
    // 0x80099848: nop

    // 0x8009984C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80099850: nop

    // 0x80099854: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80099858: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
L_8009985C:
    // 0x8009985C: jal         0x800C1680
    // 0x80099860: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x80099860: nop

    after_0:
    // 0x80099864: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80099868: nop

    // 0x8009986C: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80099870: nop

    // 0x80099874: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80099878: bne         $t5, $zero, L_80099888
    if (ctx->r13 != 0) {
        // 0x8009987C: nop
    
            goto L_80099888;
    }
    // 0x8009987C: nop

    // 0x80099880: jal         0x800C197C
    // 0x80099884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_ClearRotation(rdram, ctx);
        goto after_1;
    // 0x80099884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_80099888:
    // 0x80099888: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009988C: lw          $t7, 0x70E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E4);
    // 0x80099890: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80099894: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x80099898: jal         0x800C2AE8
    // 0x8009989C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_2;
    // 0x8009989C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x800998A0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800998A4: jal         0x800C1A84
    // 0x800998A8: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_3;
    // 0x800998A8: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_3:
    // 0x800998AC: jal         0x800C1A28
    // 0x800998B0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_4;
    // 0x800998B0: nop

    after_4:
    // 0x800998B4: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800998B8: nop

    // 0x800998BC: lhu         $t0, 0xC4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XC4);
    // 0x800998C0: nop

    // 0x800998C4: bne         $t0, $zero, L_800998D8
    if (ctx->r8 != 0) {
        // 0x800998C8: nop
    
            goto L_800998D8;
    }
    // 0x800998C8: nop

    // 0x800998CC: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800998D0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800998D4: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
L_800998D8:
    // 0x800998D8: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800998DC: nop

    // 0x800998E0: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x800998E4: nop

    // 0x800998E8: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x800998EC: bne         $t5, $zero, L_80099B88
    if (ctx->r13 != 0) {
        // 0x800998F0: nop
    
            goto L_80099B88;
    }
    // 0x800998F0: nop

    // 0x800998F4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800998F8: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x800998FC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80099900: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099904: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x80099908: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8009990C: sw          $t7, 0x30C8($at)
    MEM_W(0X30C8, ctx->r1) = ctx->r15;
    // 0x80099910: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80099914: lw          $t9, 0x7188($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7188);
    // 0x80099918: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009991C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80099920: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80099924: sh          $zero, 0x30D0($at)
    MEM_H(0X30D0, ctx->r1) = 0;
    // 0x80099928: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009992C: lw          $t1, 0x7238($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7238);
    // 0x80099930: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80099934: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80099938: bne         $t2, $zero, L_80099964
    if (ctx->r10 != 0) {
        // 0x8009993C: nop
    
            goto L_80099964;
    }
    // 0x8009993C: nop

    // 0x80099940: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80099944: lw          $t4, 0x7188($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7188);
    // 0x80099948: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8009994C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099950: lwc1        $f8, 0xB8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XB8);
    // 0x80099954: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80099958: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8009995C: b           L_800999E8
    // 0x80099960: swc1        $f8, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f8.u32l;
        goto L_800999E8;
    // 0x80099960: swc1        $f8, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f8.u32l;
L_80099964:
    // 0x80099964: jal         0x800C1680
    // 0x80099968: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_5;
    // 0x80099968: nop

    after_5:
    // 0x8009996C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80099970: nop

    // 0x80099974: lhu         $a0, 0xC4($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XC4);
    // 0x80099978: jal         0x800AD70C
    // 0x8009997C: nop

    func_800AD70C(rdram, ctx);
        goto after_6;
    // 0x8009997C: nop

    after_6:
    // 0x80099980: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80099984: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80099988: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8009998C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80099990: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80099994: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80099998: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8009999C: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x800999A0: addiu       $t8, $t7, 0xA0
    ctx->r24 = ADD32(ctx->r15, 0XA0);
    // 0x800999A4: jal         0x800C1AF4
    // 0x800999A8: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_7;
    // 0x800999A8: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_7:
    // 0x800999AC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800999B0: jal         0x800C1D44
    // 0x800999B4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_8;
    // 0x800999B4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_8:
    // 0x800999B8: jal         0x800C1A84
    // 0x800999BC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_9;
    // 0x800999BC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_9:
    // 0x800999C0: jal         0x800C1A28
    // 0x800999C4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_10;
    // 0x800999C4: nop

    after_10:
    // 0x800999C8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800999CC: lw          $t1, 0x7188($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7188);
    // 0x800999D0: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800999D4: lwc1        $f10, 0x38($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X38);
    // 0x800999D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800999DC: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800999E0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800999E4: swc1        $f10, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f10.u32l;
L_800999E8:
    // 0x800999E8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800999EC: lw          $t3, 0x7188($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7188);
    // 0x800999F0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800999F4: addiu       $t5, $t5, 0x30C8
    ctx->r13 = ADD32(ctx->r13, 0X30C8);
    // 0x800999F8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800999FC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80099A00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099A04: sw          $t6, 0x50D4($at)
    MEM_W(0X50D4, ctx->r1) = ctx->r14;
    // 0x80099A08: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80099A0C: lw          $t7, 0x7188($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7188);
    // 0x80099A10: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80099A14: blez        $t7, L_80099B5C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80099A18: nop
    
            goto L_80099B5C;
    }
    // 0x80099A18: nop

L_80099A1C:
    // 0x80099A1C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80099A20: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80099A24: addiu       $t0, $t0, 0x30C8
    ctx->r8 = ADD32(ctx->r8, 0X30C8);
    // 0x80099A28: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80099A2C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80099A30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099A34: sw          $t1, 0x50CC($at)
    MEM_W(0X50CC, ctx->r1) = ctx->r9;
    // 0x80099A38: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80099A3C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80099A40: lw          $t3, 0x50CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50CC);
    // 0x80099A44: lw          $t2, 0x50D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50D4);
    // 0x80099A48: lwc1        $f18, 0xC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80099A4C: lwc1        $f16, 0xC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80099A50: nop

    // 0x80099A54: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80099A58: nop

    // 0x80099A5C: bc1f        L_80099A84
    if (!c1cs) {
        // 0x80099A60: nop
    
            goto L_80099A84;
    }
    // 0x80099A60: nop

    // 0x80099A64: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80099A68: lw          $t4, 0x50D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50D4);
    // 0x80099A6C: nop

    // 0x80099A70: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x80099A74: nop

    // 0x80099A78: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80099A7C: b           L_80099B40
    // 0x80099A80: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
        goto L_80099B40;
    // 0x80099A80: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
L_80099A84:
    // 0x80099A84: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80099A88: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80099A8C: lw          $t8, 0x50CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50CC);
    // 0x80099A90: lw          $t7, 0x50D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50D4);
    // 0x80099A94: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80099A98: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80099A9C: nop

    // 0x80099AA0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80099AA4: nop

    // 0x80099AA8: bc1f        L_80099B24
    if (!c1cs) {
        // 0x80099AAC: nop
    
            goto L_80099B24;
    }
    // 0x80099AAC: nop

    // 0x80099AB0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80099AB4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80099AB8: lw          $t2, 0x50D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50D4);
    // 0x80099ABC: lw          $t9, 0x50CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50CC);
    // 0x80099AC0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80099AC4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80099AC8: lw          $t5, 0xC8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC8);
    // 0x80099ACC: lw          $t1, 0xC8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC8);
    // 0x80099AD0: nop

    // 0x80099AD4: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80099AD8: bne         $at, $zero, L_80099B00
    if (ctx->r1 != 0) {
        // 0x80099ADC: nop
    
            goto L_80099B00;
    }
    // 0x80099ADC: nop

    // 0x80099AE0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80099AE4: lw          $t6, 0x50CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50CC);
    // 0x80099AE8: nop

    // 0x80099AEC: lh          $t4, 0x8($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X8);
    // 0x80099AF0: nop

    // 0x80099AF4: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x80099AF8: b           L_80099B1C
    // 0x80099AFC: sh          $t7, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r15;
        goto L_80099B1C;
    // 0x80099AFC: sh          $t7, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r15;
L_80099B00:
    // 0x80099B00: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80099B04: lw          $t8, 0x50D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50D4);
    // 0x80099B08: nop

    // 0x80099B0C: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x80099B10: nop

    // 0x80099B14: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80099B18: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
L_80099B1C:
    // 0x80099B1C: b           L_80099B40
    // 0x80099B20: nop

        goto L_80099B40;
    // 0x80099B20: nop

L_80099B24:
    // 0x80099B24: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80099B28: lw          $t2, 0x50CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50CC);
    // 0x80099B2C: nop

    // 0x80099B30: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x80099B34: nop

    // 0x80099B38: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x80099B3C: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
L_80099B40:
    // 0x80099B40: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80099B44: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80099B48: lw          $t7, 0x7188($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7188);
    // 0x80099B4C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80099B50: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80099B54: bne         $at, $zero, L_80099A1C
    if (ctx->r1 != 0) {
        // 0x80099B58: sw          $t4, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r12;
            goto L_80099A1C;
    }
    // 0x80099B58: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
L_80099B5C:
    // 0x80099B5C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80099B60: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x80099B64: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099B68: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80099B6C: sw          $t9, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = ctx->r25;
    // 0x80099B70: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80099B74: lw          $v0, 0x7188($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7188);
    // 0x80099B78: b           L_80099E1C
    // 0x80099B7C: nop

        goto L_80099E1C;
    // 0x80099B7C: nop

    // 0x80099B80: b           L_80099E14
    // 0x80099B84: nop

        goto L_80099E14;
    // 0x80099B84: nop

L_80099B88:
    // 0x80099B88: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80099B8C: lw          $t8, 0x7204($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7204);
    // 0x80099B90: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80099B94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099B98: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x80099B9C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80099BA0: sw          $t0, 0x50E0($at)
    MEM_W(0X50E0, ctx->r1) = ctx->r8;
    // 0x80099BA4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80099BA8: lw          $t1, 0x7204($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7204);
    // 0x80099BAC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099BB0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80099BB4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80099BB8: sh          $zero, 0x50E8($at)
    MEM_H(0X50E8, ctx->r1) = 0;
    // 0x80099BBC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80099BC0: lw          $t5, 0x7238($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7238);
    // 0x80099BC4: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80099BC8: and         $t4, $t5, $at
    ctx->r12 = ctx->r13 & ctx->r1;
    // 0x80099BCC: bne         $t4, $zero, L_80099BF8
    if (ctx->r12 != 0) {
        // 0x80099BD0: nop
    
            goto L_80099BF8;
    }
    // 0x80099BD0: nop

    // 0x80099BD4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80099BD8: lw          $t6, 0x7204($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7204);
    // 0x80099BDC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80099BE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099BE4: lwc1        $f8, 0xB8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XB8);
    // 0x80099BE8: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x80099BEC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80099BF0: b           L_80099C7C
    // 0x80099BF4: swc1        $f8, 0x50EC($at)
    MEM_W(0X50EC, ctx->r1) = ctx->f8.u32l;
        goto L_80099C7C;
    // 0x80099BF4: swc1        $f8, 0x50EC($at)
    MEM_W(0X50EC, ctx->r1) = ctx->f8.u32l;
L_80099BF8:
    // 0x80099BF8: jal         0x800C1680
    // 0x80099BFC: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_11;
    // 0x80099BFC: nop

    after_11:
    // 0x80099C00: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80099C04: nop

    // 0x80099C08: lhu         $a0, 0xC4($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XC4);
    // 0x80099C0C: jal         0x800AD70C
    // 0x80099C10: nop

    func_800AD70C(rdram, ctx);
        goto after_12;
    // 0x80099C10: nop

    after_12:
    // 0x80099C14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80099C18: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80099C1C: addu        $t0, $t0, $s0
    ctx->r8 = ADD32(ctx->r8, ctx->r16);
    // 0x80099C20: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80099C24: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x80099C28: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80099C2C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80099C30: addiu       $t1, $t1, 0x61D8
    ctx->r9 = ADD32(ctx->r9, 0X61D8);
    // 0x80099C34: addiu       $t3, $t0, 0xA0
    ctx->r11 = ADD32(ctx->r8, 0XA0);
    // 0x80099C38: jal         0x800C1AF4
    // 0x80099C3C: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_13;
    // 0x80099C3C: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    after_13:
    // 0x80099C40: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80099C44: jal         0x800C1D44
    // 0x80099C48: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_14;
    // 0x80099C48: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_14:
    // 0x80099C4C: jal         0x800C1A84
    // 0x80099C50: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_15;
    // 0x80099C50: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_15:
    // 0x80099C54: jal         0x800C1A28
    // 0x80099C58: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_16;
    // 0x80099C58: nop

    after_16:
    // 0x80099C5C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80099C60: lw          $t5, 0x7204($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7204);
    // 0x80099C64: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x80099C68: lwc1        $f10, 0x38($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X38);
    // 0x80099C6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099C70: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x80099C74: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80099C78: swc1        $f10, 0x50EC($at)
    MEM_W(0X50EC, ctx->r1) = ctx->f10.u32l;
L_80099C7C:
    // 0x80099C7C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80099C80: lw          $t7, 0x7204($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7204);
    // 0x80099C84: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80099C88: addiu       $t9, $t9, 0x50E0
    ctx->r25 = ADD32(ctx->r25, 0X50E0);
    // 0x80099C8C: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80099C90: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80099C94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099C98: sw          $t8, 0x50D4($at)
    MEM_W(0X50D4, ctx->r1) = ctx->r24;
    // 0x80099C9C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80099CA0: lw          $t0, 0x7204($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7204);
    // 0x80099CA4: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80099CA8: blez        $t0, L_80099DF0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80099CAC: nop
    
            goto L_80099DF0;
    }
    // 0x80099CAC: nop

L_80099CB0:
    // 0x80099CB0: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80099CB4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80099CB8: addiu       $t2, $t2, 0x50E0
    ctx->r10 = ADD32(ctx->r10, 0X50E0);
    // 0x80099CBC: sll         $t1, $t3, 4
    ctx->r9 = S32(ctx->r11 << 4);
    // 0x80099CC0: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x80099CC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099CC8: sw          $t5, 0x50CC($at)
    MEM_W(0X50CC, ctx->r1) = ctx->r13;
    // 0x80099CCC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80099CD0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80099CD4: lw          $t7, 0x50CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50CC);
    // 0x80099CD8: lw          $t4, 0x50D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50D4);
    // 0x80099CDC: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80099CE0: lwc1        $f16, 0xC($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80099CE4: nop

    // 0x80099CE8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80099CEC: nop

    // 0x80099CF0: bc1f        L_80099D18
    if (!c1cs) {
        // 0x80099CF4: nop
    
            goto L_80099D18;
    }
    // 0x80099CF4: nop

    // 0x80099CF8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80099CFC: lw          $t6, 0x50D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50D4);
    // 0x80099D00: nop

    // 0x80099D04: lh          $t9, 0x8($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X8);
    // 0x80099D08: nop

    // 0x80099D0C: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80099D10: b           L_80099DD4
    // 0x80099D14: sh          $t8, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r24;
        goto L_80099DD4;
    // 0x80099D14: sh          $t8, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r24;
L_80099D18:
    // 0x80099D18: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80099D1C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80099D20: lw          $t3, 0x50CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50CC);
    // 0x80099D24: lw          $t0, 0x50D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50D4);
    // 0x80099D28: lwc1        $f6, 0xC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80099D2C: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80099D30: nop

    // 0x80099D34: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80099D38: nop

    // 0x80099D3C: bc1f        L_80099DB8
    if (!c1cs) {
        // 0x80099D40: nop
    
            goto L_80099DB8;
    }
    // 0x80099D40: nop

    // 0x80099D44: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80099D48: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80099D4C: lw          $t4, 0x50D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50D4);
    // 0x80099D50: lw          $t1, 0x50CC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50CC);
    // 0x80099D54: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80099D58: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80099D5C: lw          $t9, 0xC8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC8);
    // 0x80099D60: lw          $t5, 0xC8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC8);
    // 0x80099D64: nop

    // 0x80099D68: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80099D6C: bne         $at, $zero, L_80099D94
    if (ctx->r1 != 0) {
        // 0x80099D70: nop
    
            goto L_80099D94;
    }
    // 0x80099D70: nop

    // 0x80099D74: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80099D78: lw          $t8, 0x50CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50CC);
    // 0x80099D7C: nop

    // 0x80099D80: lh          $t6, 0x8($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X8);
    // 0x80099D84: nop

    // 0x80099D88: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x80099D8C: b           L_80099DB0
    // 0x80099D90: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
        goto L_80099DB0;
    // 0x80099D90: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
L_80099D94:
    // 0x80099D94: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80099D98: lw          $t3, 0x50D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50D4);
    // 0x80099D9C: nop

    // 0x80099DA0: lh          $t1, 0x8($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X8);
    // 0x80099DA4: nop

    // 0x80099DA8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80099DAC: sh          $t2, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r10;
L_80099DB0:
    // 0x80099DB0: b           L_80099DD4
    // 0x80099DB4: nop

        goto L_80099DD4;
    // 0x80099DB4: nop

L_80099DB8:
    // 0x80099DB8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80099DBC: lw          $t4, 0x50CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50CC);
    // 0x80099DC0: nop

    // 0x80099DC4: lh          $t7, 0x8($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X8);
    // 0x80099DC8: nop

    // 0x80099DCC: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x80099DD0: sh          $t5, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r13;
L_80099DD4:
    // 0x80099DD4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80099DD8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80099DDC: lw          $t0, 0x7204($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7204);
    // 0x80099DE0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80099DE4: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80099DE8: bne         $at, $zero, L_80099CB0
    if (ctx->r1 != 0) {
        // 0x80099DEC: sw          $t6, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r14;
            goto L_80099CB0;
    }
    // 0x80099DEC: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
L_80099DF0:
    // 0x80099DF0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80099DF4: lw          $t8, 0x7204($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7204);
    // 0x80099DF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099DFC: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80099E00: sw          $t1, 0x7204($at)
    MEM_W(0X7204, ctx->r1) = ctx->r9;
    // 0x80099E04: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80099E08: lw          $v0, 0x7204($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7204);
    // 0x80099E0C: b           L_80099E1C
    // 0x80099E10: nop

        goto L_80099E1C;
    // 0x80099E10: nop

L_80099E14:
    // 0x80099E14: b           L_80099E1C
    // 0x80099E18: nop

        goto L_80099E1C;
    // 0x80099E18: nop

L_80099E1C:
    // 0x80099E1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80099E20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80099E24: jr          $ra
    // 0x80099E28: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80099E28: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80073738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073738: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007373C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073740: nop

    // 0x80073744: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073748: nop

    // 0x8007374C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80073750: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073754: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073758: beq         $v0, $zero, L_80073770
    if (ctx->r2 == 0) {
        // 0x8007375C: nop
    
            goto L_80073770;
    }
    // 0x8007375C: nop

    // 0x80073760: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073764: nop

    // 0x80073768: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8007376C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80073770:
    // 0x80073770: jr          $ra
    // 0x80073774: nop

    return;
    // 0x80073774: nop

    // 0x80073778: jr          $ra
    // 0x8007377C: nop

    return;
    // 0x8007377C: nop

    // 0x80073780: jr          $ra
    // 0x80073784: nop

    return;
    // 0x80073784: nop

;}
RECOMP_FUNC void func_8006B5DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B5DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B5E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B5E4: nop

    // 0x8006B5E8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B5EC: nop

    // 0x8006B5F0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B5F4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B5F8: jr          $ra
    // 0x8006B5FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B5FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B600: jr          $ra
    // 0x8006B604: nop

    return;
    // 0x8006B604: nop

    // 0x8006B608: jr          $ra
    // 0x8006B60C: nop

    return;
    // 0x8006B60C: nop

;}
RECOMP_FUNC void ObjectCheckDebugMenu_DrawUI(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F6B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001F6BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F6C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001F6C4: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x8001F6C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001F6CC: nop

    // 0x8001F6D0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8001F6D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F6D8: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001F6DC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8001F6E0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001F6E4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8001F6E8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8001F6EC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8001F6F0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F6F4: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001F6F8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8001F6FC: nop

    // 0x8001F700: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8001F704: beq         $t5, $zero, L_8001F718
    if (ctx->r13 == 0) {
        // 0x8001F708: nop
    
            goto L_8001F718;
    }
    // 0x8001F708: nop

    // 0x8001F70C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F710: b           L_8001F71C
    // 0x8001F714: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
        goto L_8001F71C;
    // 0x8001F714: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_8001F718:
    // 0x8001F718: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8001F71C:
    // 0x8001F71C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001F720: jal         0x8008EAA8
    // 0x8001F724: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001F724: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8001F728: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001F72C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001F730: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001F734: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001F738: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001F73C: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x8001F740: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F744: addiu       $a0, $a0, -0x2474
    ctx->r4 = ADD32(ctx->r4, -0X2474);
    // 0x8001F748: srl         $a1, $t9, 16
    ctx->r5 = S32(U32(ctx->r25) >> 16);
    // 0x8001F74C: andi        $a2, $t9, 0xFFFF
    ctx->r6 = ctx->r25 & 0XFFFF;
    // 0x8001F750: jal         0x8008ECE4
    // 0x8001F754: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001F754: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8001F758: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F75C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001F760: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8001F764: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F768: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001F76C: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8001F770: lh          $a0, -0x4A00($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4A00);
    // 0x8001F774: jal         0x8008EAA8
    // 0x8001F778: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8001F778: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8001F77C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F780: jal         0x8008ECE4
    // 0x8001F784: addiu       $a0, $a0, -0x2448
    ctx->r4 = ADD32(ctx->r4, -0X2448);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001F784: addiu       $a0, $a0, -0x2448
    ctx->r4 = ADD32(ctx->r4, -0X2448);
    after_3:
    // 0x8001F788: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001F78C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001F790: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x8001F794: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F798: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001F79C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8001F7A0: lh          $a0, -0x49FE($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X49FE);
    // 0x8001F7A4: jal         0x8008EAA8
    // 0x8001F7A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x8001F7A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8001F7AC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F7B0: jal         0x8008ECE4
    // 0x8001F7B4: addiu       $a0, $a0, -0x2444
    ctx->r4 = ADD32(ctx->r4, -0X2444);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8001F7B4: addiu       $a0, $a0, -0x2444
    ctx->r4 = ADD32(ctx->r4, -0X2444);
    after_5:
    // 0x8001F7B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F7BC: jal         0x8008EAA8
    // 0x8001F7C0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8008EAA8(rdram, ctx);
        goto after_6;
    // 0x8001F7C0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_6:
    // 0x8001F7C4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F7C8: jal         0x8008ECE4
    // 0x8001F7CC: addiu       $a0, $a0, -0x2440
    ctx->r4 = ADD32(ctx->r4, -0X2440);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001F7CC: addiu       $a0, $a0, -0x2440
    ctx->r4 = ADD32(ctx->r4, -0X2440);
    after_7:
    // 0x8001F7D0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F7D4: jal         0x8008ECE4
    // 0x8001F7D8: addiu       $a0, $a0, -0x241C
    ctx->r4 = ADD32(ctx->r4, -0X241C);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x8001F7D8: addiu       $a0, $a0, -0x241C
    ctx->r4 = ADD32(ctx->r4, -0X241C);
    after_8:
    // 0x8001F7DC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F7E0: jal         0x8008ECE4
    // 0x8001F7E4: addiu       $a0, $a0, -0x23F0
    ctx->r4 = ADD32(ctx->r4, -0X23F0);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8001F7E4: addiu       $a0, $a0, -0x23F0
    ctx->r4 = ADD32(ctx->r4, -0X23F0);
    after_9:
    // 0x8001F7E8: b           L_8001F7F0
    // 0x8001F7EC: nop

        goto L_8001F7F0;
    // 0x8001F7EC: nop

L_8001F7F0:
    // 0x8001F7F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F7F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001F7F8: jr          $ra
    // 0x8001F7FC: nop

    return;
    // 0x8001F7FC: nop

;}
RECOMP_FUNC void func_80043DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043DC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043DC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80043DCC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80043DD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80043DD4: sh          $t6, 0x30C0($at)
    MEM_H(0X30C0, ctx->r1) = ctx->r14;
    // 0x80043DD8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80043DDC: lhu         $t7, 0x30C0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X30C0);
    // 0x80043DE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80043DE4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80043DE8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80043DEC: lw          $t9, -0x2BC8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BC8);
    // 0x80043DF0: nop

    // 0x80043DF4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80043DF8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80043DFC: nop

    // 0x80043E00: jalr        $t9
    // 0x80043E04: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80043E04: nop

    after_0:
    // 0x80043E08: b           L_80043E10
    // 0x80043E0C: nop

        goto L_80043E10;
    // 0x80043E0C: nop

L_80043E10:
    // 0x80043E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043E14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043E18: jr          $ra
    // 0x80043E1C: nop

    return;
    // 0x80043E1C: nop

;}
RECOMP_FUNC void func_8006A638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A63C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A640: jal         0x80061348
    // 0x8006A644: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006A644: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006A648: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A64C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A650: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A654: beq         $v0, $zero, L_8006A694
    if (ctx->r2 == 0) {
        // 0x8006A658: nop
    
            goto L_8006A694;
    }
    // 0x8006A658: nop

    // 0x8006A65C: jal         0x80061348
    // 0x8006A660: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006A660: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006A664: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A668: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A66C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A670: beq         $v0, $zero, L_8006A694
    if (ctx->r2 == 0) {
        // 0x8006A674: nop
    
            goto L_8006A694;
    }
    // 0x8006A674: nop

    // 0x8006A678: jal         0x80061348
    // 0x8006A67C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006A67C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006A680: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A684: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A688: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A68C: bne         $v0, $zero, L_8006A8D8
    if (ctx->r2 != 0) {
        // 0x8006A690: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A690: nop

L_8006A694:
    // 0x8006A694: jal         0x80061348
    // 0x8006A698: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006A698: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006A69C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A6A0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A6A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006A6A8: beq         $v0, $zero, L_8006A6E8
    if (ctx->r2 == 0) {
        // 0x8006A6AC: nop
    
            goto L_8006A6E8;
    }
    // 0x8006A6AC: nop

    // 0x8006A6B0: jal         0x80061348
    // 0x8006A6B4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006A6B4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006A6B8: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006A6BC: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006A6C0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006A6C4: beq         $v0, $zero, L_8006A6E8
    if (ctx->r2 == 0) {
        // 0x8006A6C8: nop
    
            goto L_8006A6E8;
    }
    // 0x8006A6C8: nop

    // 0x8006A6CC: jal         0x80061348
    // 0x8006A6D0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006A6D0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006A6D4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006A6D8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006A6DC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006A6E0: bne         $v0, $zero, L_8006A8D8
    if (ctx->r2 != 0) {
        // 0x8006A6E4: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A6E4: nop

L_8006A6E8:
    // 0x8006A6E8: jal         0x80061348
    // 0x8006A6EC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006A6EC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006A6F0: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006A6F4: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006A6F8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006A6FC: beq         $v0, $zero, L_8006A73C
    if (ctx->r2 == 0) {
        // 0x8006A700: nop
    
            goto L_8006A73C;
    }
    // 0x8006A700: nop

    // 0x8006A704: jal         0x80061348
    // 0x8006A708: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006A708: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006A70C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006A710: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006A714: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006A718: beq         $v0, $zero, L_8006A73C
    if (ctx->r2 == 0) {
        // 0x8006A71C: nop
    
            goto L_8006A73C;
    }
    // 0x8006A71C: nop

    // 0x8006A720: jal         0x80061348
    // 0x8006A724: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006A724: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006A728: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A72C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A730: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A734: bne         $v0, $zero, L_8006A8D8
    if (ctx->r2 != 0) {
        // 0x8006A738: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A738: nop

L_8006A73C:
    // 0x8006A73C: jal         0x80061348
    // 0x8006A740: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006A740: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006A744: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A748: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A74C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A750: beq         $v0, $zero, L_8006A790
    if (ctx->r2 == 0) {
        // 0x8006A754: nop
    
            goto L_8006A790;
    }
    // 0x8006A754: nop

    // 0x8006A758: jal         0x80061348
    // 0x8006A75C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006A75C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006A760: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A764: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A768: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A76C: beq         $v0, $zero, L_8006A790
    if (ctx->r2 == 0) {
        // 0x8006A770: nop
    
            goto L_8006A790;
    }
    // 0x8006A770: nop

    // 0x8006A774: jal         0x80061348
    // 0x8006A778: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006A778: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006A77C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A780: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A784: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A788: bne         $v0, $zero, L_8006A8D8
    if (ctx->r2 != 0) {
        // 0x8006A78C: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A78C: nop

L_8006A790:
    // 0x8006A790: jal         0x80061348
    // 0x8006A794: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006A794: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006A798: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A79C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A7A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A7A4: beq         $v0, $zero, L_8006A7E4
    if (ctx->r2 == 0) {
        // 0x8006A7A8: nop
    
            goto L_8006A7E4;
    }
    // 0x8006A7A8: nop

    // 0x8006A7AC: jal         0x80061348
    // 0x8006A7B0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006A7B0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006A7B4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A7B8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A7BC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006A7C0: beq         $v0, $zero, L_8006A7E4
    if (ctx->r2 == 0) {
        // 0x8006A7C4: nop
    
            goto L_8006A7E4;
    }
    // 0x8006A7C4: nop

    // 0x8006A7C8: jal         0x80061348
    // 0x8006A7CC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006A7CC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006A7D0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006A7D4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006A7D8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006A7DC: bne         $v0, $zero, L_8006A8D8
    if (ctx->r2 != 0) {
        // 0x8006A7E0: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A7E0: nop

L_8006A7E4:
    // 0x8006A7E4: jal         0x80061348
    // 0x8006A7E8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006A7E8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006A7EC: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006A7F0: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006A7F4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006A7F8: beq         $v0, $zero, L_8006A838
    if (ctx->r2 == 0) {
        // 0x8006A7FC: nop
    
            goto L_8006A838;
    }
    // 0x8006A7FC: nop

    // 0x8006A800: jal         0x80061348
    // 0x8006A804: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006A804: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006A808: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006A80C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006A810: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006A814: beq         $v0, $zero, L_8006A838
    if (ctx->r2 == 0) {
        // 0x8006A818: nop
    
            goto L_8006A838;
    }
    // 0x8006A818: nop

    // 0x8006A81C: jal         0x80061348
    // 0x8006A820: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006A820: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006A824: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006A828: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006A82C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006A830: bne         $v0, $zero, L_8006A8D8
    if (ctx->r2 != 0) {
        // 0x8006A834: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A834: nop

L_8006A838:
    // 0x8006A838: jal         0x80061348
    // 0x8006A83C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006A83C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006A840: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A844: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A848: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A84C: beq         $v0, $zero, L_8006A88C
    if (ctx->r2 == 0) {
        // 0x8006A850: nop
    
            goto L_8006A88C;
    }
    // 0x8006A850: nop

    // 0x8006A854: jal         0x80061348
    // 0x8006A858: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006A858: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006A85C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A860: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A864: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A868: beq         $v0, $zero, L_8006A88C
    if (ctx->r2 == 0) {
        // 0x8006A86C: nop
    
            goto L_8006A88C;
    }
    // 0x8006A86C: nop

    // 0x8006A870: jal         0x80061348
    // 0x8006A874: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006A874: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006A878: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A87C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A880: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A884: bne         $v0, $zero, L_8006A8D8
    if (ctx->r2 != 0) {
        // 0x8006A888: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A888: nop

L_8006A88C:
    // 0x8006A88C: jal         0x80061348
    // 0x8006A890: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006A890: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006A894: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A898: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A89C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A8A0: beq         $v0, $zero, L_8006A8D8
    if (ctx->r2 == 0) {
        // 0x8006A8A4: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A8A4: nop

    // 0x8006A8A8: jal         0x80061348
    // 0x8006A8AC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006A8AC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006A8B0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A8B4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A8B8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A8BC: beq         $v0, $zero, L_8006A8D8
    if (ctx->r2 == 0) {
        // 0x8006A8C0: nop
    
            goto L_8006A8D8;
    }
    // 0x8006A8C0: nop

    // 0x8006A8C4: jal         0x80061348
    // 0x8006A8C8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006A8C8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006A8CC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A8D0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A8D4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006A8D8:
    // 0x8006A8D8: b           L_8006A8E8
    // 0x8006A8DC: nop

        goto L_8006A8E8;
    // 0x8006A8DC: nop

    // 0x8006A8E0: b           L_8006A8E8
    // 0x8006A8E4: nop

        goto L_8006A8E8;
    // 0x8006A8E4: nop

L_8006A8E8:
    // 0x8006A8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A8EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A8F0: jr          $ra
    // 0x8006A8F4: nop

    return;
    // 0x8006A8F4: nop

;}
RECOMP_FUNC void func_80075BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075BC8: jal         0x80061488
    // 0x80075BCC: addiu       $a0, $zero, 0x464
    ctx->r4 = ADD32(0, 0X464);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075BCC: addiu       $a0, $zero, 0x464
    ctx->r4 = ADD32(0, 0X464);
    after_0:
    // 0x80075BD0: slti        $t6, $v0, 0x4
    ctx->r14 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80075BD4: b           L_80075BE4
    // 0x80075BD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075BE4;
    // 0x80075BD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075BDC: b           L_80075BE4
    // 0x80075BE0: nop

        goto L_80075BE4;
    // 0x80075BE0: nop

L_80075BE4:
    // 0x80075BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075BEC: jr          $ra
    // 0x80075BF0: nop

    return;
    // 0x80075BF0: nop

;}
RECOMP_FUNC void func_80077B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077B6C: jal         0x80061488
    // 0x80077B70: addiu       $a0, $zero, 0x5B2
    ctx->r4 = ADD32(0, 0X5B2);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077B70: addiu       $a0, $zero, 0x5B2
    ctx->r4 = ADD32(0, 0X5B2);
    after_0:
    // 0x80077B74: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80077B78: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077B7C: b           L_80077B8C
    // 0x80077B80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077B8C;
    // 0x80077B80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077B84: b           L_80077B8C
    // 0x80077B88: nop

        goto L_80077B8C;
    // 0x80077B88: nop

L_80077B8C:
    // 0x80077B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077B94: jr          $ra
    // 0x80077B98: nop

    return;
    // 0x80077B98: nop

;}
RECOMP_FUNC void func_8001E348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E348: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E34C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E350: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001E354: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E358: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E35C: jal         0x8008EAA8
    // 0x8001E360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001E360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001E364: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001E368: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E36C: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001E370: jal         0x8008ECE4
    // 0x8001E374: addiu       $a0, $a0, -0x2628
    ctx->r4 = ADD32(ctx->r4, -0X2628);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001E374: addiu       $a0, $a0, -0x2628
    ctx->r4 = ADD32(ctx->r4, -0X2628);
    after_1:
    // 0x8001E378: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001E37C: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x8001E380: nop

    // 0x8001E384: beq         $s0, $zero, L_8001E3AC
    if (ctx->r16 == 0) {
        // 0x8001E388: nop
    
            goto L_8001E3AC;
    }
    // 0x8001E388: nop

    // 0x8001E38C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E390: beq         $s0, $at, L_8001E3C0
    if (ctx->r16 == ctx->r1) {
        // 0x8001E394: nop
    
            goto L_8001E3C0;
    }
    // 0x8001E394: nop

    // 0x8001E398: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001E39C: beq         $s0, $at, L_8001E574
    if (ctx->r16 == ctx->r1) {
        // 0x8001E3A0: nop
    
            goto L_8001E574;
    }
    // 0x8001E3A0: nop

    // 0x8001E3A4: b           L_8001E600
    // 0x8001E3A8: nop

        goto L_8001E600;
    // 0x8001E3A8: nop

L_8001E3AC:
    // 0x8001E3AC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001E3B0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001E3B4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001E3B8: b           L_8001E608
    // 0x8001E3BC: nop

        goto L_8001E608;
    // 0x8001E3BC: nop

L_8001E3C0:
    // 0x8001E3C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E3C4: jal         0x8008EAA8
    // 0x8001E3C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8001E3C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x8001E3CC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E3D0: jal         0x8008ECE4
    // 0x8001E3D4: addiu       $a0, $a0, -0x261C
    ctx->r4 = ADD32(ctx->r4, -0X261C);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001E3D4: addiu       $a0, $a0, -0x261C
    ctx->r4 = ADD32(ctx->r4, -0X261C);
    after_3:
    // 0x8001E3D8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001E3DC: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001E3E0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001E3E4: nop

    // 0x8001E3E8: bne         $t9, $zero, L_8001E428
    if (ctx->r25 != 0) {
        // 0x8001E3EC: nop
    
            goto L_8001E428;
    }
    // 0x8001E3EC: nop

    // 0x8001E3F0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E3F4: jal         0x8008EAA8
    // 0x8001E3F8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x8001E3F8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x8001E3FC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E400: jal         0x8008ECE4
    // 0x8001E404: addiu       $a0, $a0, -0x25F0
    ctx->r4 = ADD32(ctx->r4, -0X25F0);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8001E404: addiu       $a0, $a0, -0x25F0
    ctx->r4 = ADD32(ctx->r4, -0X25F0);
    after_5:
    // 0x8001E408: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E40C: jal         0x8008EAA8
    // 0x8001E410: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8008EAA8(rdram, ctx);
        goto after_6;
    // 0x8001E410: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x8001E414: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E418: jal         0x8008ECE4
    // 0x8001E41C: addiu       $a0, $a0, -0x25E8
    ctx->r4 = ADD32(ctx->r4, -0X25E8);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001E41C: addiu       $a0, $a0, -0x25E8
    ctx->r4 = ADD32(ctx->r4, -0X25E8);
    after_7:
    // 0x8001E420: b           L_8001E458
    // 0x8001E424: nop

        goto L_8001E458;
    // 0x8001E424: nop

L_8001E428:
    // 0x8001E428: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E42C: jal         0x8008EAA8
    // 0x8001E430: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008EAA8(rdram, ctx);
        goto after_8;
    // 0x8001E430: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x8001E434: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E438: jal         0x8008ECE4
    // 0x8001E43C: addiu       $a0, $a0, -0x25E0
    ctx->r4 = ADD32(ctx->r4, -0X25E0);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8001E43C: addiu       $a0, $a0, -0x25E0
    ctx->r4 = ADD32(ctx->r4, -0X25E0);
    after_9:
    // 0x8001E440: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E444: jal         0x8008EAA8
    // 0x8001E448: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8008EAA8(rdram, ctx);
        goto after_10;
    // 0x8001E448: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_10:
    // 0x8001E44C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E450: jal         0x8008ECE4
    // 0x8001E454: addiu       $a0, $a0, -0x25D8
    ctx->r4 = ADD32(ctx->r4, -0X25D8);
    func_8008ECE4(rdram, ctx);
        goto after_11;
    // 0x8001E454: addiu       $a0, $a0, -0x25D8
    ctx->r4 = ADD32(ctx->r4, -0X25D8);
    after_11:
L_8001E458:
    // 0x8001E458: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001E45C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001E460: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001E464: lhu         $t2, 0xE68($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XE68);
    // 0x8001E468: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x8001E46C: nop

    // 0x8001E470: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8001E474: bne         $t3, $zero, L_8001E494
    if (ctx->r11 != 0) {
        // 0x8001E478: nop
    
            goto L_8001E494;
    }
    // 0x8001E478: nop

    // 0x8001E47C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001E480: lhu         $t4, 0xE74($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XE74);
    // 0x8001E484: nop

    // 0x8001E488: and         $t5, $t1, $t4
    ctx->r13 = ctx->r9 & ctx->r12;
    // 0x8001E48C: beq         $t5, $zero, L_8001E4AC
    if (ctx->r13 == 0) {
        // 0x8001E490: nop
    
            goto L_8001E4AC;
    }
    // 0x8001E490: nop

L_8001E494:
    // 0x8001E494: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001E498: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001E49C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001E4A0: nop

    // 0x8001E4A4: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x8001E4A8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_8001E4AC:
    // 0x8001E4AC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E4B0: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001E4B4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001E4B8: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x8001E4BC: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8001E4C0: nop

    // 0x8001E4C4: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x8001E4C8: beq         $t3, $zero, L_8001E528
    if (ctx->r11 == 0) {
        // 0x8001E4CC: nop
    
            goto L_8001E528;
    }
    // 0x8001E4CC: nop

    // 0x8001E4D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001E4D4: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001E4D8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8001E4DC: nop

    // 0x8001E4E0: bne         $t4, $zero, L_8001E528
    if (ctx->r12 != 0) {
        // 0x8001E4E4: nop
    
            goto L_8001E528;
    }
    // 0x8001E4E4: nop

    // 0x8001E4E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8001E4EC: lw          $a0, 0x648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X648);
    // 0x8001E4F0: jal         0x800BCB10
    // 0x8001E4F4: nop

    func_800BCB10(rdram, ctx);
        goto after_12;
    // 0x8001E4F4: nop

    after_12:
    // 0x8001E4F8: jal         0x8005D2B0
    // 0x8001E4FC: nop

    func_8005D2B0(rdram, ctx);
        goto after_13;
    // 0x8001E4FC: nop

    after_13:
    // 0x8001E500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E504: sw          $v0, 0x648($at)
    MEM_W(0X648, ctx->r1) = ctx->r2;
    // 0x8001E508: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E50C: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001E510: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8001E514: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001E518: lw          $t7, 0x25E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E4);
    // 0x8001E51C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E520: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001E524: sw          $t8, 0x25E4($at)
    MEM_W(0X25E4, ctx->r1) = ctx->r24;
L_8001E528:
    // 0x8001E528: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001E52C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8001E530: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001E534: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x8001E538: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x8001E53C: nop

    // 0x8001E540: and         $t2, $t9, $t0
    ctx->r10 = ctx->r25 & ctx->r8;
    // 0x8001E544: beq         $t2, $zero, L_8001E56C
    if (ctx->r10 == 0) {
        // 0x8001E548: nop
    
            goto L_8001E56C;
    }
    // 0x8001E548: nop

    // 0x8001E54C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001E550: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001E554: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8001E558: nop

    // 0x8001E55C: beq         $t1, $zero, L_8001E56C
    if (ctx->r9 == 0) {
        // 0x8001E560: nop
    
            goto L_8001E56C;
    }
    // 0x8001E560: nop

    // 0x8001E564: b           L_8001E644
    // 0x8001E568: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E644;
    // 0x8001E568: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E56C:
    // 0x8001E56C: b           L_8001E608
    // 0x8001E570: nop

        goto L_8001E608;
    // 0x8001E570: nop

L_8001E574:
    // 0x8001E574: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E578: jal         0x8008EAA8
    // 0x8001E57C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_14;
    // 0x8001E57C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x8001E580: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E584: jal         0x8008ECE4
    // 0x8001E588: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    func_8008ECE4(rdram, ctx);
        goto after_15;
    // 0x8001E588: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    after_15:
    // 0x8001E58C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E590: jal         0x8008EAA8
    // 0x8001E594: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008EAA8(rdram, ctx);
        goto after_16;
    // 0x8001E594: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_16:
    // 0x8001E598: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E59C: jal         0x8008ECE4
    // 0x8001E5A0: addiu       $a0, $a0, -0x25A4
    ctx->r4 = ADD32(ctx->r4, -0X25A4);
    func_8008ECE4(rdram, ctx);
        goto after_17;
    // 0x8001E5A0: addiu       $a0, $a0, -0x25A4
    ctx->r4 = ADD32(ctx->r4, -0X25A4);
    after_17:
    // 0x8001E5A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E5A8: jal         0x8008EAA8
    // 0x8001E5AC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8008EAA8(rdram, ctx);
        goto after_18;
    // 0x8001E5AC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_18:
    // 0x8001E5B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E5B4: jal         0x8008ECE4
    // 0x8001E5B8: addiu       $a0, $a0, -0x259C
    ctx->r4 = ADD32(ctx->r4, -0X259C);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x8001E5B8: addiu       $a0, $a0, -0x259C
    ctx->r4 = ADD32(ctx->r4, -0X259C);
    after_19:
    // 0x8001E5BC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001E5C0: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001E5C4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8001E5C8: nop

    // 0x8001E5CC: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8001E5D0: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8001E5D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001E5D8: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001E5DC: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x8001E5E0: nop

    // 0x8001E5E4: slti        $at, $t6, 0x79
    ctx->r1 = SIGNED(ctx->r14) < 0X79 ? 1 : 0;
    // 0x8001E5E8: bne         $at, $zero, L_8001E5F8
    if (ctx->r1 != 0) {
        // 0x8001E5EC: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5EC: nop

    // 0x8001E5F0: b           L_8001E644
    // 0x8001E5F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E644;
    // 0x8001E5F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E5F8:
    // 0x8001E5F8: b           L_8001E608
    // 0x8001E5FC: nop

        goto L_8001E608;
    // 0x8001E5FC: nop

L_8001E600:
    // 0x8001E600: b           L_8001E608
    // 0x8001E604: nop

        goto L_8001E608;
    // 0x8001E604: nop

L_8001E608:
    // 0x8001E608: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E60C: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001E610: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001E614: lhu         $t2, 0x11A4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X11A4);
    // 0x8001E618: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8001E61C: nop

    // 0x8001E620: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x8001E624: beq         $t3, $zero, L_8001E634
    if (ctx->r11 == 0) {
        // 0x8001E628: nop
    
            goto L_8001E634;
    }
    // 0x8001E628: nop

    // 0x8001E62C: b           L_8001E644
    // 0x8001E630: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E644;
    // 0x8001E630: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E634:
    // 0x8001E634: b           L_8001E644
    // 0x8001E638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001E644;
    // 0x8001E638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E63C: b           L_8001E644
    // 0x8001E640: nop

        goto L_8001E644;
    // 0x8001E640: nop

L_8001E644:
    // 0x8001E644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E648: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E64C: jr          $ra
    // 0x8001E650: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E650: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800669A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800669A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800669AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800669B0: jal         0x80061348
    // 0x800669B4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800669B4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800669B8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800669BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800669C0: beq         $v0, $zero, L_800669D8
    if (ctx->r2 == 0) {
        // 0x800669C4: nop
    
            goto L_800669D8;
    }
    // 0x800669C4: nop

    // 0x800669C8: jal         0x80061348
    // 0x800669CC: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800669CC: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x800669D0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800669D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800669D8:
    // 0x800669D8: b           L_800669E8
    // 0x800669DC: nop

        goto L_800669E8;
    // 0x800669DC: nop

    // 0x800669E0: b           L_800669E8
    // 0x800669E4: nop

        goto L_800669E8;
    // 0x800669E4: nop

L_800669E8:
    // 0x800669E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800669EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800669F0: jr          $ra
    // 0x800669F4: nop

    return;
    // 0x800669F4: nop

;}
RECOMP_FUNC void func_8002BBE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BBE8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BBEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BBF0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002BBF4: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8002BBF8: slt         $a1, $at, $a0
    ctx->r5 = SIGNED(ctx->r1) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002BBFC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8002BC00: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8002BC04: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002BC08: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BC0C: beq         $a1, $zero, L_8002BC1C
    if (ctx->r5 == 0) {
        // 0x8002BC10: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8002BC1C;
    }
    // 0x8002BC10: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8002BC14: b           L_8002BC7C
    // 0x8002BC18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002BC7C;
    // 0x8002BC18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002BC1C:
    // 0x8002BC1C: bgez        $a0, L_8002BC2C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002BC20: sra         $t8, $a0, 3
        ctx->r24 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8002BC2C;
    }
    // 0x8002BC20: sra         $t8, $a0, 3
    ctx->r24 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8002BC24: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8002BC28: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8002BC2C:
    // 0x8002BC2C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8002BC30: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002BC34: lbu         $t9, -0x414C($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X414C);
    // 0x8002BC38: bgez        $a0, L_8002BC4C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002BC3C: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_8002BC4C;
    }
    // 0x8002BC3C: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x8002BC40: beq         $t0, $zero, L_8002BC4C
    if (ctx->r8 == 0) {
        // 0x8002BC44: nop
    
            goto L_8002BC4C;
    }
    // 0x8002BC44: nop

    // 0x8002BC48: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_8002BC4C:
    // 0x8002BC4C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8002BC50: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x8002BC54: srav        $v0, $t9, $t2
    ctx->r2 = S32(SIGNED(ctx->r25) >> (ctx->r10 & 31));
    // 0x8002BC58: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8002BC5C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8002BC60: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8002BC64: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8002BC68: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002BC6C: b           L_8002BC7C
    // 0x8002BC70: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_8002BC7C;
    // 0x8002BC70: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8002BC74: b           L_8002BC7C
    // 0x8002BC78: nop

        goto L_8002BC7C;
    // 0x8002BC78: nop

L_8002BC7C:
    // 0x8002BC7C: jr          $ra
    // 0x8002BC80: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002BC80: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006B850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B850: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B854: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B858: nop

    // 0x8006B85C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B860: nop

    // 0x8006B864: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B868: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B86C: jr          $ra
    // 0x8006B870: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B870: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B874: jr          $ra
    // 0x8006B878: nop

    return;
    // 0x8006B878: nop

    // 0x8006B87C: jr          $ra
    // 0x8006B880: nop

    return;
    // 0x8006B880: nop

;}
RECOMP_FUNC void func_80066B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066B84: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80066B88: nop

    // 0x80066B8C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80066B90: nop

    // 0x80066B94: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80066B98: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066B9C: jr          $ra
    // 0x80066BA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80066BA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066BA4: jr          $ra
    // 0x80066BA8: nop

    return;
    // 0x80066BA8: nop

    // 0x80066BAC: jr          $ra
    // 0x80066BB0: nop

    return;
    // 0x80066BB0: nop

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
RECOMP_FUNC void func_80072E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E54: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072E58: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072E5C: nop

    // 0x80072E60: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072E64: nop

    // 0x80072E68: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072E6C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072E70: jr          $ra
    // 0x80072E74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072E74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072E78: jr          $ra
    // 0x80072E7C: nop

    return;
    // 0x80072E7C: nop

    // 0x80072E80: jr          $ra
    // 0x80072E84: nop

    return;
    // 0x80072E84: nop

;}
RECOMP_FUNC void func_80074B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074BA0: jal         0x80061348
    // 0x80074BA4: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074BA4: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x80074BA8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074BAC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074BB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074BB4: beq         $v0, $zero, L_80074C08
    if (ctx->r2 == 0) {
        // 0x80074BB8: nop
    
            goto L_80074C08;
    }
    // 0x80074BB8: nop

    // 0x80074BBC: jal         0x80061348
    // 0x80074BC0: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074BC0: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074BC4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074BC8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074BCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074BD0: beq         $v0, $zero, L_80074C08
    if (ctx->r2 == 0) {
        // 0x80074BD4: nop
    
            goto L_80074C08;
    }
    // 0x80074BD4: nop

    // 0x80074BD8: jal         0x80061348
    // 0x80074BDC: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074BDC: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074BE0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074BE4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074BE8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074BEC: beq         $v0, $zero, L_80074C08
    if (ctx->r2 == 0) {
        // 0x80074BF0: nop
    
            goto L_80074C08;
    }
    // 0x80074BF0: nop

    // 0x80074BF4: jal         0x80061348
    // 0x80074BF8: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074BF8: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074BFC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074C00: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074C04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074C08:
    // 0x80074C08: b           L_80074C18
    // 0x80074C0C: nop

        goto L_80074C18;
    // 0x80074C0C: nop

    // 0x80074C10: b           L_80074C18
    // 0x80074C14: nop

        goto L_80074C18;
    // 0x80074C14: nop

L_80074C18:
    // 0x80074C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074C1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074C20: jr          $ra
    // 0x80074C24: nop

    return;
    // 0x80074C24: nop

;}
RECOMP_FUNC void func_80065228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065228: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006522C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065230: nop

    // 0x80065234: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80065238: nop

    // 0x8006523C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80065240: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065244: jr          $ra
    // 0x80065248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006524C: jr          $ra
    // 0x80065250: nop

    return;
    // 0x80065250: nop

    // 0x80065254: jr          $ra
    // 0x80065258: nop

    return;
    // 0x80065258: nop

;}
RECOMP_FUNC void func_800636D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800636D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800636D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800636DC: nop

    // 0x800636E0: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x800636E4: nop

    // 0x800636E8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800636EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800636F0: jr          $ra
    // 0x800636F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800636F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800636F8: jr          $ra
    // 0x800636FC: nop

    return;
    // 0x800636FC: nop

    // 0x80063700: jr          $ra
    // 0x80063704: nop

    return;
    // 0x80063704: nop

;}
RECOMP_FUNC void func_800906F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800906F8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800906FC: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80090700: sra         $t7, $a1, 15
    ctx->r15 = S32(SIGNED(ctx->r5) >> 15);
    // 0x80090704: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80090708: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009070C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80090710: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80090714: sh          $t8, -0x44B8($at)
    MEM_H(-0X44B8, ctx->r1) = ctx->r24;
    // 0x80090718: jr          $ra
    // 0x8009071C: nop

    return;
    // 0x8009071C: nop

    // 0x80090720: jr          $ra
    // 0x80090724: nop

    return;
    // 0x80090724: nop

;}
RECOMP_FUNC void func_80069DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80069DC8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80069DCC: nop

    // 0x80069DD0: lh          $v0, 0x3A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X3A);
    // 0x80069DD4: nop

    // 0x80069DD8: xori        $t7, $v0, 0x3E7
    ctx->r15 = ctx->r2 ^ 0X3E7;
    // 0x80069DDC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069DE0: jr          $ra
    // 0x80069DE4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80069DE4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069DE8: jr          $ra
    // 0x80069DEC: nop

    return;
    // 0x80069DEC: nop

    // 0x80069DF0: jr          $ra
    // 0x80069DF4: nop

    return;
    // 0x80069DF4: nop

;}
RECOMP_FUNC void func_8006CC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC94: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CC98: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CC9C: nop

    // 0x8006CCA0: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x8006CCA4: nop

    // 0x8006CCA8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006CCAC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CCB0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CCB4: beq         $v0, $zero, L_8006CCD0
    if (ctx->r2 == 0) {
        // 0x8006CCB8: nop
    
            goto L_8006CCD0;
    }
    // 0x8006CCB8: nop

    // 0x8006CCBC: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x8006CCC0: nop

    // 0x8006CCC4: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006CCC8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006CCCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CCD0:
    // 0x8006CCD0: jr          $ra
    // 0x8006CCD4: nop

    return;
    // 0x8006CCD4: nop

    // 0x8006CCD8: jr          $ra
    // 0x8006CCDC: nop

    return;
    // 0x8006CCDC: nop

    // 0x8006CCE0: jr          $ra
    // 0x8006CCE4: nop

    return;
    // 0x8006CCE4: nop

;}
RECOMP_FUNC void func_8006C880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C888: jal         0x80061488
    // 0x8006C88C: addiu       $a0, $zero, 0x687
    ctx->r4 = ADD32(0, 0X687);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006C88C: addiu       $a0, $zero, 0x687
    ctx->r4 = ADD32(0, 0X687);
    after_0:
    // 0x8006C890: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006C894: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006C898: b           L_8006C8A8
    // 0x8006C89C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006C8A8;
    // 0x8006C89C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006C8A0: b           L_8006C8A8
    // 0x8006C8A4: nop

        goto L_8006C8A8;
    // 0x8006C8A4: nop

L_8006C8A8:
    // 0x8006C8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C8AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C8B0: jr          $ra
    // 0x8006C8B4: nop

    return;
    // 0x8006C8B4: nop

;}
RECOMP_FUNC void func_80097498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097498: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009749C: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x800974A0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800974A4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800974A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800974AC: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x800974B0: jr          $ra
    // 0x800974B4: nop

    return;
    // 0x800974B4: nop

    // 0x800974B8: jr          $ra
    // 0x800974BC: nop

    return;
    // 0x800974BC: nop

;}
RECOMP_FUNC void func_80005880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005880: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x80005884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005888: sw          $a0, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r4;
    // 0x8000588C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005890: lw          $t6, 0x1E0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1E0);
    // 0x80005894: nop

    // 0x80005898: sw          $t6, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r14;
    // 0x8000589C: lw          $t7, 0x1CC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1CC);
    // 0x800058A0: nop

    // 0x800058A4: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800058A8: nop

    // 0x800058AC: sw          $t8, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r24;
    // 0x800058B0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800058B4: lh          $t9, 0x72AC($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X72AC);
    // 0x800058B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800058BC: bne         $t9, $at, L_80005900
    if (ctx->r25 != ctx->r1) {
        // 0x800058C0: nop
    
            goto L_80005900;
    }
    // 0x800058C0: nop

    // 0x800058C4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800058C8: lh          $t0, 0x72B4($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X72B4);
    // 0x800058CC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800058D0: beq         $t0, $at, L_800058E4
    if (ctx->r8 == ctx->r1) {
        // 0x800058D4: nop
    
            goto L_800058E4;
    }
    // 0x800058D4: nop

    // 0x800058D8: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800058DC: bne         $t0, $at, L_80005900
    if (ctx->r8 != ctx->r1) {
        // 0x800058E0: nop
    
            goto L_80005900;
    }
    // 0x800058E0: nop

L_800058E4:
    // 0x800058E4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800058E8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800058EC: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x800058F0: nop

    // 0x800058F4: ori         $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 | 0X8000;
    // 0x800058F8: b           L_8000591C
    // 0x800058FC: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
        goto L_8000591C;
    // 0x800058FC: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
L_80005900:
    // 0x80005900: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80005904: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80005908: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x8000590C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80005910: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80005914: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80005918: sh          $t6, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r14;
L_8000591C:
    // 0x8000591C: lw          $t7, 0x1C8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005920: nop

    // 0x80005924: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x80005928: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x8000592C: nop

    // 0x80005930: blez        $t8, L_800059B4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80005934: nop
    
            goto L_800059B4;
    }
    // 0x80005934: nop

L_80005938:
    // 0x80005938: lw          $t9, 0x1CC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1CC);
    // 0x8000593C: addiu       $a1, $sp, 0x1C4
    ctx->r5 = ADD32(ctx->r29, 0X1C4);
    // 0x80005940: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80005944: jal         0x800C143C
    // 0x80005948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_0;
    // 0x80005948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8000594C: lw          $t0, 0x1C4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C4);
    // 0x80005950: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80005954: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x80005958: nop

    // 0x8000595C: bne         $t2, $at, L_80005998
    if (ctx->r10 != ctx->r1) {
        // 0x80005960: nop
    
            goto L_80005998;
    }
    // 0x80005960: nop

    // 0x80005964: b           L_8000596C
    // 0x80005968: nop

        goto L_8000596C;
    // 0x80005968: nop

L_8000596C:
    // 0x8000596C: jal         0x80099520
    // 0x80005970: nop

    func_80099520(rdram, ctx);
        goto after_1;
    // 0x80005970: nop

    after_1:
    // 0x80005974: lw          $t3, 0x1C8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005978: nop

    // 0x8000597C: addiu       $t1, $t3, 0x7FFF
    ctx->r9 = ADD32(ctx->r11, 0X7FFF);
    // 0x80005980: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x80005984: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x80005988: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x8000598C: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
    // 0x80005990: b           L_80005998
    // 0x80005994: nop

        goto L_80005998;
    // 0x80005994: nop

L_80005998:
    // 0x80005998: lw          $t6, 0x1C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C8);
    // 0x8000599C: nop

    // 0x800059A0: addiu       $t4, $t6, 0x7FFF
    ctx->r12 = ADD32(ctx->r14, 0X7FFF);
    // 0x800059A4: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x800059A8: nop

    // 0x800059AC: bgtz        $t4, L_80005938
    if (SIGNED(ctx->r12) > 0) {
        // 0x800059B0: nop
    
            goto L_80005938;
    }
    // 0x800059B0: nop

L_800059B4:
    // 0x800059B4: jal         0x80098820
    // 0x800059B8: nop

    func_80098820(rdram, ctx);
        goto after_2;
    // 0x800059B8: nop

    after_2:
    // 0x800059BC: jal         0x80098868
    // 0x800059C0: nop

    func_80098868(rdram, ctx);
        goto after_3;
    // 0x800059C0: nop

    after_3:
    // 0x800059C4: sw          $zero, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = 0;
L_800059C8:
    // 0x800059C8: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800059CC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800059D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800059D4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800059D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800059DC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800059E0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800059E4: addiu       $t9, $t9, -0x71B0
    ctx->r25 = ADD32(ctx->r25, -0X71B0);
    // 0x800059E8: jal         0x80099E2C
    // 0x800059EC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    func_80099E2C(rdram, ctx);
        goto after_4;
    // 0x800059EC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x800059F0: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800059F4: nop

    // 0x800059F8: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800059FC: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x80005A00: bne         $at, $zero, L_800059C8
    if (ctx->r1 != 0) {
        // 0x80005A04: sw          $t2, 0x1DC($sp)
        MEM_W(0X1DC, ctx->r29) = ctx->r10;
            goto L_800059C8;
    }
    // 0x80005A04: sw          $t2, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r10;
    // 0x80005A08: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005A0C: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80005A10: jal         0x800A6670
    // 0x80005A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_5;
    // 0x80005A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80005A18: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005A1C: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80005A20: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80005A24: jal         0x800A6670
    // 0x80005A28: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_6;
    // 0x80005A28: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_6:
    // 0x80005A2C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005A30: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80005A34: lh          $a1, 0x72B4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X72B4);
    // 0x80005A38: lh          $a0, 0x72AC($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X72AC);
    // 0x80005A3C: jal         0x80005124
    // 0x80005A40: nop

    func_80005124(rdram, ctx);
        goto after_7;
    // 0x80005A40: nop

    after_7:
    // 0x80005A44: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
    // 0x80005A48: lw          $t1, 0x1D0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D0);
    // 0x80005A4C: nop

    // 0x80005A50: bne         $t1, $zero, L_80005A64
    if (ctx->r9 != 0) {
        // 0x80005A54: nop
    
            goto L_80005A64;
    }
    // 0x80005A54: nop

    // 0x80005A58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80005A5C: jal         0x800A6F20
    // 0x80005A60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800A6F20(rdram, ctx);
        goto after_8;
    // 0x80005A60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_8:
L_80005A64:
    // 0x80005A64: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80005A68: lbu         $t5, 0x125A($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X125A);
    // 0x80005A6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80005A70: ori         $t3, $t5, 0x1
    ctx->r11 = ctx->r13 | 0X1;
    // 0x80005A74: sb          $t3, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = ctx->r11;
    // 0x80005A78: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005A7C: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80005A80: lhu         $t4, 0x4($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X4);
    // 0x80005A84: nop

    // 0x80005A88: andi        $t7, $t4, 0x8000
    ctx->r15 = ctx->r12 & 0X8000;
    // 0x80005A8C: beq         $t7, $zero, L_80005AA4
    if (ctx->r15 == 0) {
        // 0x80005A90: nop
    
            goto L_80005AA4;
    }
    // 0x80005A90: nop

    // 0x80005A94: jal         0x800831E0
    // 0x80005A98: nop

    func_800831E0(rdram, ctx);
        goto after_9;
    // 0x80005A98: nop

    after_9:
    // 0x80005A9C: b           L_80005AAC
    // 0x80005AA0: nop

        goto L_80005AAC;
    // 0x80005AA0: nop

L_80005AA4:
    // 0x80005AA4: jal         0x80079910
    // 0x80005AA8: nop

    func_80079910(rdram, ctx);
        goto after_10;
    // 0x80005AA8: nop

    after_10:
L_80005AAC:
    // 0x80005AAC: sw          $zero, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = 0;
    // 0x80005AB0: lw          $t8, 0x1CC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1CC);
    // 0x80005AB4: nop

    // 0x80005AB8: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80005ABC: jal         0x800C13B8
    // 0x80005AC0: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_11;
    // 0x80005AC0: nop

    after_11:
    // 0x80005AC4: jal         0x80098820
    // 0x80005AC8: nop

    func_80098820(rdram, ctx);
        goto after_12;
    // 0x80005AC8: nop

    after_12:
    // 0x80005ACC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80005AD0: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80005AD4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80005AD8: nop

    // 0x80005ADC: andi        $t2, $t0, 0x40
    ctx->r10 = ctx->r8 & 0X40;
    // 0x80005AE0: beq         $t2, $zero, L_80005AF8
    if (ctx->r10 == 0) {
        // 0x80005AE4: nop
    
            goto L_80005AF8;
    }
    // 0x80005AE4: nop

    // 0x80005AE8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80005AEC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80005AF0: jal         0x80021FF8
    // 0x80005AF4: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_80021FF8(rdram, ctx);
        goto after_13;
    // 0x80005AF4: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_13:
L_80005AF8:
    // 0x80005AF8: jal         0x80098BF4
    // 0x80005AFC: nop

    func_80098BF4(rdram, ctx);
        goto after_14;
    // 0x80005AFC: nop

    after_14:
    // 0x80005B00: lw          $t1, 0x1D8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D8);
    // 0x80005B04: nop

    // 0x80005B08: bne         $t1, $zero, L_80006114
    if (ctx->r9 != 0) {
        // 0x80005B0C: nop
    
            goto L_80006114;
    }
    // 0x80005B0C: nop

L_80005B10:
    // 0x80005B10: lw          $t5, 0x1CC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1CC);
    // 0x80005B14: addiu       $a1, $sp, 0x1C4
    ctx->r5 = ADD32(ctx->r29, 0X1C4);
    // 0x80005B18: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80005B1C: jal         0x800C143C
    // 0x80005B20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_15;
    // 0x80005B20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80005B24: lw          $t3, 0x1C4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C4);
    // 0x80005B28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005B2C: lh          $s0, 0x0($t3)
    ctx->r16 = MEM_H(ctx->r11, 0X0);
    // 0x80005B30: nop

    // 0x80005B34: beq         $s0, $at, L_80005B74
    if (ctx->r16 == ctx->r1) {
        // 0x80005B38: nop
    
            goto L_80005B74;
    }
    // 0x80005B38: nop

    // 0x80005B3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80005B40: beq         $s0, $at, L_80005EB0
    if (ctx->r16 == ctx->r1) {
        // 0x80005B44: nop
    
            goto L_80005EB0;
    }
    // 0x80005B44: nop

    // 0x80005B48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80005B4C: beq         $s0, $at, L_800060F4
    if (ctx->r16 == ctx->r1) {
        // 0x80005B50: nop
    
            goto L_800060F4;
    }
    // 0x80005B50: nop

    // 0x80005B54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80005B58: beq         $s0, $at, L_800060DC
    if (ctx->r16 == ctx->r1) {
        // 0x80005B5C: nop
    
            goto L_800060DC;
    }
    // 0x80005B5C: nop

    // 0x80005B60: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80005B64: beq         $s0, $at, L_80005F10
    if (ctx->r16 == ctx->r1) {
        // 0x80005B68: nop
    
            goto L_80005F10;
    }
    // 0x80005B68: nop

    // 0x80005B6C: b           L_800060FC
    // 0x80005B70: nop

        goto L_800060FC;
    // 0x80005B70: nop

L_80005B74:
    // 0x80005B74: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005B78: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80005B7C: lhu         $t4, 0x0($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X0);
    // 0x80005B80: nop

    // 0x80005B84: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80005B88: bne         $t7, $zero, L_80005EA8
    if (ctx->r15 != 0) {
        // 0x80005B8C: nop
    
            goto L_80005EA8;
    }
    // 0x80005B8C: nop

    // 0x80005B90: lw          $t8, 0x1C8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005B94: nop

    // 0x80005B98: addiu       $t9, $t8, 0x7FFF
    ctx->r25 = ADD32(ctx->r24, 0X7FFF);
    // 0x80005B9C: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x80005BA0: nop

    // 0x80005BA4: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80005BA8: beq         $at, $zero, L_80005EA8
    if (ctx->r1 == 0) {
        // 0x80005BAC: nop
    
            goto L_80005EA8;
    }
    // 0x80005BAC: nop

    // 0x80005BB0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80005BB4: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x80005BB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80005BBC: sw          $t0, 0x30AC($at)
    MEM_W(0X30AC, ctx->r1) = ctx->r8;
    // 0x80005BC0: jal         0x80099768
    // 0x80005BC4: nop

    func_80099768(rdram, ctx);
        goto after_16;
    // 0x80005BC4: nop

    after_16:
    // 0x80005BC8: jal         0x800AFB28
    // 0x80005BCC: nop

    func_800AFB28(rdram, ctx);
        goto after_17;
    // 0x80005BCC: nop

    after_17:
    // 0x80005BD0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80005BD4: lw          $t1, -0x4CC4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4CC4);
    // 0x80005BD8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80005BDC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80005BE0: lw          $t2, -0x4CCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CCC);
    // 0x80005BE4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005BE8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80005BEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80005BF0: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x80005BF4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80005BF8: jal         0x800BE510
    // 0x80005BFC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800BE510(rdram, ctx);
        goto after_18;
    // 0x80005BFC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_18:
    // 0x80005C00: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80005C04: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80005C08: lw          $t3, -0x4CC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CC4);
    // 0x80005C0C: lw          $t5, -0x4CCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CCC);
    // 0x80005C10: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80005C14: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80005C18: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80005C1C: jal         0x8009A04C
    // 0x80005C20: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_8009A04C(rdram, ctx);
        goto after_19;
    // 0x80005C20: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_19:
    // 0x80005C24: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005C28: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80005C2C: lhu         $t4, 0x0($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X0);
    // 0x80005C30: nop

    // 0x80005C34: andi        $t7, $t4, 0x8
    ctx->r15 = ctx->r12 & 0X8;
    // 0x80005C38: beq         $t7, $zero, L_80005C48
    if (ctx->r15 == 0) {
        // 0x80005C3C: nop
    
            goto L_80005C48;
    }
    // 0x80005C3C: nop

    // 0x80005C40: jal         0x80033788
    // 0x80005C44: nop

    func_80033788(rdram, ctx);
        goto after_20;
    // 0x80005C44: nop

    after_20:
L_80005C48:
    // 0x80005C48: jal         0x80032604
    // 0x80005C4C: nop

    func_80032604(rdram, ctx);
        goto after_21;
    // 0x80005C4C: nop

    after_21:
    // 0x80005C50: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80005C54: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80005C58: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x80005C5C: nop

    // 0x80005C60: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80005C64: beq         $t0, $zero, L_80005CA8
    if (ctx->r8 == 0) {
        // 0x80005C68: nop
    
            goto L_80005CA8;
    }
    // 0x80005C68: nop

    // 0x80005C6C: jal         0x80083700
    // 0x80005C70: nop

    func_80083700(rdram, ctx);
        goto after_22;
    // 0x80005C70: nop

    after_22:
    // 0x80005C74: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80005C78: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80005C7C: lhu         $t1, 0x4($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X4);
    // 0x80005C80: nop

    // 0x80005C84: andi        $t5, $t1, 0x8
    ctx->r13 = ctx->r9 & 0X8;
    // 0x80005C88: beq         $t5, $zero, L_80005CA0
    if (ctx->r13 == 0) {
        // 0x80005C8C: nop
    
            goto L_80005CA0;
    }
    // 0x80005C8C: nop

    // 0x80005C90: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80005C94: sw          $t3, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r11;
    // 0x80005C98: b           L_80006104
    // 0x80005C9C: nop

        goto L_80006104;
    // 0x80005C9C: nop

L_80005CA0:
    // 0x80005CA0: b           L_80005CD4
    // 0x80005CA4: nop

        goto L_80005CD4;
    // 0x80005CA4: nop

L_80005CA8:
    // 0x80005CA8: jal         0x80079CCC
    // 0x80005CAC: nop

    func_80079CCC(rdram, ctx);
        goto after_23;
    // 0x80005CAC: nop

    after_23:
    // 0x80005CB0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005CB4: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80005CB8: lhu         $t4, 0x4($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X4);
    // 0x80005CBC: nop

    // 0x80005CC0: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80005CC4: beq         $t7, $zero, L_80005CD4
    if (ctx->r15 == 0) {
        // 0x80005CC8: nop
    
            goto L_80005CD4;
    }
    // 0x80005CC8: nop

    // 0x80005CCC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80005CD0: sw          $t8, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r24;
L_80005CD4:
    // 0x80005CD4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80005CD8: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80005CDC: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x80005CE0: nop

    // 0x80005CE4: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x80005CE8: bne         $t2, $zero, L_80005D00
    if (ctx->r10 != 0) {
        // 0x80005CEC: nop
    
            goto L_80005D00;
    }
    // 0x80005CEC: nop

    // 0x80005CF0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005CF4: addiu       $a0, $a0, 0x7340
    ctx->r4 = ADD32(ctx->r4, 0X7340);
    // 0x80005CF8: jal         0x8000262C
    // 0x80005CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000262C(rdram, ctx);
        goto after_24;
    // 0x80005CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
L_80005D00:
    // 0x80005D00: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80005D04: addiu       $a0, $a0, -0x71B0
    ctx->r4 = ADD32(ctx->r4, -0X71B0);
    // 0x80005D08: jal         0x8000262C
    // 0x80005D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000262C(rdram, ctx);
        goto after_25;
    // 0x80005D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80005D10: jal         0x80002824
    // 0x80005D14: nop

    func_80002824(rdram, ctx);
        goto after_26;
    // 0x80005D14: nop

    after_26:
    // 0x80005D18: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80005D1C: lh          $t1, 0x721C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X721C);
    // 0x80005D20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005D24: beq         $t1, $at, L_80005D38
    if (ctx->r9 == ctx->r1) {
        // 0x80005D28: nop
    
            goto L_80005D38;
    }
    // 0x80005D28: nop

    // 0x80005D2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80005D30: bne         $t1, $at, L_80005D40
    if (ctx->r9 != ctx->r1) {
        // 0x80005D34: nop
    
            goto L_80005D40;
    }
    // 0x80005D34: nop

L_80005D38:
    // 0x80005D38: jal         0x80034310
    // 0x80005D3C: nop

    func_80034310(rdram, ctx);
        goto after_27;
    // 0x80005D3C: nop

    after_27:
L_80005D40:
    // 0x80005D40: jal         0x800305A4
    // 0x80005D44: nop

    func_800305A4(rdram, ctx);
        goto after_28;
    // 0x80005D44: nop

    after_28:
    // 0x80005D48: jal         0x8002A39C
    // 0x80005D4C: nop

    func_8002A39C(rdram, ctx);
        goto after_29;
    // 0x80005D4C: nop

    after_29:
    // 0x80005D50: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80005D54: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80005D58: lhu         $t3, 0x6($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X6);
    // 0x80005D5C: nop

    // 0x80005D60: andi        $t6, $t3, 0x8000
    ctx->r14 = ctx->r11 & 0X8000;
    // 0x80005D64: bne         $t6, $zero, L_80005D7C
    if (ctx->r14 != 0) {
        // 0x80005D68: nop
    
            goto L_80005D7C;
    }
    // 0x80005D68: nop

    // 0x80005D6C: jal         0x8004DEA4
    // 0x80005D70: nop

    func_8004DEA4(rdram, ctx);
        goto after_30;
    // 0x80005D70: nop

    after_30:
    // 0x80005D74: jal         0x80082958
    // 0x80005D78: nop

    func_80082958(rdram, ctx);
        goto after_31;
    // 0x80005D78: nop

    after_31:
L_80005D7C:
    // 0x80005D7C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80005D80: lw          $t4, -0x73AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73AC);
    // 0x80005D84: nop

    // 0x80005D88: beq         $t4, $zero, L_80005DDC
    if (ctx->r12 == 0) {
        // 0x80005D8C: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_80005DDC;
    }
    // 0x80005D8C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80005D90:
    // 0x80005D90: jal         0x800C1754
    // 0x80005D94: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_32;
    // 0x80005D94: nop

    after_32:
    // 0x80005D98: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80005D9C: jal         0x8009A14C
    // 0x80005DA0: nop

    func_8009A14C(rdram, ctx);
        goto after_33;
    // 0x80005DA0: nop

    after_33:
    // 0x80005DA4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80005DA8: jal         0x800997D8
    // 0x80005DAC: nop

    func_800997D8(rdram, ctx);
        goto after_34;
    // 0x80005DAC: nop

    after_34:
    // 0x80005DB0: jal         0x800C1A28
    // 0x80005DB4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_35;
    // 0x80005DB4: nop

    after_35:
    // 0x80005DB8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80005DBC: nop

    // 0x80005DC0: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x80005DC4: nop

    // 0x80005DC8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80005DCC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80005DD0: nop

    // 0x80005DD4: bne         $t9, $zero, L_80005D90
    if (ctx->r25 != 0) {
        // 0x80005DD8: nop
    
            goto L_80005D90;
    }
    // 0x80005DD8: nop

L_80005DDC:
    // 0x80005DDC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80005DE0: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80005DE4: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x80005DE8: nop

    // 0x80005DEC: andi        $t1, $t2, 0x100
    ctx->r9 = ctx->r10 & 0X100;
    // 0x80005DF0: bne         $t1, $zero, L_80005E14
    if (ctx->r9 != 0) {
        // 0x80005DF4: nop
    
            goto L_80005E14;
    }
    // 0x80005DF4: nop

    // 0x80005DF8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005DFC: jal         0x8009A664
    // 0x80005E00: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_36;
    // 0x80005E00: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_36:
    // 0x80005E04: jal         0x8002C2F8
    // 0x80005E08: nop

    func_8002C2F8(rdram, ctx);
        goto after_37;
    // 0x80005E08: nop

    after_37:
    // 0x80005E0C: b           L_80005E28
    // 0x80005E10: nop

        goto L_80005E28;
    // 0x80005E10: nop

L_80005E14:
    // 0x80005E14: jal         0x8002C2F8
    // 0x80005E18: nop

    func_8002C2F8(rdram, ctx);
        goto after_38;
    // 0x80005E18: nop

    after_38:
    // 0x80005E1C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005E20: jal         0x8009A664
    // 0x80005E24: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_39;
    // 0x80005E24: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_39:
L_80005E28:
    // 0x80005E28: jal         0x8001635C
    // 0x80005E2C: nop

    func_8001635C(rdram, ctx);
        goto after_40;
    // 0x80005E2C: nop

    after_40:
    // 0x80005E30: jal         0x800BE684
    // 0x80005E34: nop

    func_800BE684(rdram, ctx);
        goto after_41;
    // 0x80005E34: nop

    after_41:
    // 0x80005E38: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005E3C: jal         0x8009A664
    // 0x80005E40: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_42;
    // 0x80005E40: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_42:
    // 0x80005E44: jal         0x800BE610
    // 0x80005E48: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_43;
    // 0x80005E48: nop

    after_43:
    // 0x80005E4C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80005E50: lw          $t5, 0x1B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B4C);
    // 0x80005E54: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80005E58: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x80005E5C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80005E60: jal         0x8009908C
    // 0x80005E64: subu        $a1, $t3, $t5
    ctx->r5 = SUB32(ctx->r11, ctx->r13);
    CreateGfxTask(rdram, ctx);
        goto after_44;
    // 0x80005E64: subu        $a1, $t3, $t5
    ctx->r5 = SUB32(ctx->r11, ctx->r13);
    after_44:
    // 0x80005E68: lw          $t6, 0x1CC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1CC);
    // 0x80005E6C: nop

    // 0x80005E70: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80005E74: jal         0x80098D24
    // 0x80005E78: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_45;
    // 0x80005E78: nop

    after_45:
    // 0x80005E7C: jal         0x80099450
    // 0x80005E80: nop

    func_80099450(rdram, ctx);
        goto after_46;
    // 0x80005E80: nop

    after_46:
    // 0x80005E84: jal         0x80001F54
    // 0x80005E88: nop

    func_80001F54(rdram, ctx);
        goto after_47;
    // 0x80005E88: nop

    after_47:
    // 0x80005E8C: lw          $t4, 0x1C8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005E90: nop

    // 0x80005E94: addiu       $t7, $t4, 0x7FFF
    ctx->r15 = ADD32(ctx->r12, 0X7FFF);
    // 0x80005E98: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80005E9C: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80005EA0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80005EA4: sw          $t8, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r24;
L_80005EA8:
    // 0x80005EA8: b           L_80006104
    // 0x80005EAC: nop

        goto L_80006104;
    // 0x80005EAC: nop

L_80005EB0:
    // 0x80005EB0: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005EB4: nop

    // 0x80005EB8: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x80005EBC: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x80005EC0: nop

    // 0x80005EC4: beq         $t0, $zero, L_80005F08
    if (ctx->r8 == 0) {
        // 0x80005EC8: nop
    
            goto L_80005F08;
    }
    // 0x80005EC8: nop

    // 0x80005ECC: jal         0x80099520
    // 0x80005ED0: nop

    func_80099520(rdram, ctx);
        goto after_48;
    // 0x80005ED0: nop

    after_48:
    // 0x80005ED4: lw          $t2, 0x1C8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005ED8: nop

    // 0x80005EDC: addiu       $t1, $t2, 0x7FFF
    ctx->r9 = ADD32(ctx->r10, 0X7FFF);
    // 0x80005EE0: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x80005EE4: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x80005EE8: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x80005EEC: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x80005EF0: jal         0x800C40D0
    // 0x80005EF4: nop

    osGetTime_recomp(rdram, ctx);
        goto after_49;
    // 0x80005EF4: nop

    after_49:
    // 0x80005EF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80005EFC: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x80005F00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80005F04: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
L_80005F08:
    // 0x80005F08: b           L_80006104
    // 0x80005F0C: nop

        goto L_80006104;
    // 0x80005F0C: nop

L_80005F10:
    // 0x80005F10: lw          $t5, 0x1C8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005F14: nop

    // 0x80005F18: addiu       $t6, $t5, 0x7FFF
    ctx->r14 = ADD32(ctx->r13, 0X7FFF);
    // 0x80005F1C: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x80005F20: nop

    // 0x80005F24: blez        $t6, L_80005FA8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80005F28: nop
    
            goto L_80005FA8;
    }
    // 0x80005F28: nop

L_80005F2C:
    // 0x80005F2C: lw          $t7, 0x1CC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1CC);
    // 0x80005F30: addiu       $a1, $sp, 0x1C4
    ctx->r5 = ADD32(ctx->r29, 0X1C4);
    // 0x80005F34: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80005F38: jal         0x800C143C
    // 0x80005F3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_50;
    // 0x80005F3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_50:
    // 0x80005F40: lw          $t8, 0x1C4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C4);
    // 0x80005F44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80005F48: lh          $t4, 0x0($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X0);
    // 0x80005F4C: nop

    // 0x80005F50: bne         $t4, $at, L_80005F8C
    if (ctx->r12 != ctx->r1) {
        // 0x80005F54: nop
    
            goto L_80005F8C;
    }
    // 0x80005F54: nop

    // 0x80005F58: b           L_80005F60
    // 0x80005F5C: nop

        goto L_80005F60;
    // 0x80005F5C: nop

L_80005F60:
    // 0x80005F60: jal         0x80099520
    // 0x80005F64: nop

    func_80099520(rdram, ctx);
        goto after_51;
    // 0x80005F64: nop

    after_51:
    // 0x80005F68: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005F6C: nop

    // 0x80005F70: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x80005F74: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x80005F78: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80005F7C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80005F80: sw          $t1, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r9;
    // 0x80005F84: b           L_80005F8C
    // 0x80005F88: nop

        goto L_80005F8C;
    // 0x80005F88: nop

L_80005F8C:
    // 0x80005F8C: lw          $t3, 0x1C8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005F90: nop

    // 0x80005F94: addiu       $t2, $t3, 0x7FFF
    ctx->r10 = ADD32(ctx->r11, 0X7FFF);
    // 0x80005F98: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x80005F9C: nop

    // 0x80005FA0: bgtz        $t2, L_80005F2C
    if (SIGNED(ctx->r10) > 0) {
        // 0x80005FA4: nop
    
            goto L_80005F2C;
    }
    // 0x80005FA4: nop

L_80005FA8:
    // 0x80005FA8: jal         0x80098820
    // 0x80005FAC: nop

    func_80098820(rdram, ctx);
        goto after_52;
    // 0x80005FAC: nop

    after_52:
    // 0x80005FB0: jal         0x80098868
    // 0x80005FB4: nop

    func_80098868(rdram, ctx);
        goto after_53;
    // 0x80005FB4: nop

    after_53:
    // 0x80005FB8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005FBC: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80005FC0: jal         0x800A6670
    // 0x80005FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_54;
    // 0x80005FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
    // 0x80005FC8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005FCC: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80005FD0: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80005FD4: jal         0x800A6670
    // 0x80005FD8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_55;
    // 0x80005FD8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_55:
    // 0x80005FDC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005FE0: lw          $a1, -0x73E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73E8);
    // 0x80005FE4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80005FE8: jal         0x800BCFCC
    // 0x80005FEC: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    SysMem_Copy8(rdram, ctx);
        goto after_56;
    // 0x80005FEC: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    after_56:
    // 0x80005FF0: lw          $t5, 0x1D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D0);
    // 0x80005FF4: nop

    // 0x80005FF8: bne         $t5, $zero, L_80006008
    if (ctx->r13 != 0) {
        // 0x80005FFC: nop
    
            goto L_80006008;
    }
    // 0x80005FFC: nop

    // 0x80006000: jal         0x80005460
    // 0x80006004: nop

    func_80005460(rdram, ctx);
        goto after_57;
    // 0x80006004: nop

    after_57:
L_80006008:
    // 0x80006008: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000600C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80006010: lh          $a1, 0x72B4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X72B4);
    // 0x80006014: lh          $a0, 0x72AC($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X72AC);
    // 0x80006018: jal         0x80005124
    // 0x8000601C: nop

    func_80005124(rdram, ctx);
        goto after_58;
    // 0x8000601C: nop

    after_58:
    // 0x80006020: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
    // 0x80006024: lw          $t6, 0x1D0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D0);
    // 0x80006028: nop

    // 0x8000602C: bne         $t6, $zero, L_80006040
    if (ctx->r14 != 0) {
        // 0x80006030: nop
    
            goto L_80006040;
    }
    // 0x80006030: nop

    // 0x80006034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80006038: jal         0x800A6F20
    // 0x8000603C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800A6F20(rdram, ctx);
        goto after_59;
    // 0x8000603C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_59:
L_80006040:
    // 0x80006040: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80006044: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80006048: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8000604C: nop

    // 0x80006050: swc1        $f16, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f16.u32l;
    // 0x80006054: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80006058: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8000605C: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80006060: nop

    // 0x80006064: swc1        $f18, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f18.u32l;
    // 0x80006068: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000606C: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80006070: lhu         $t0, 0x4($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0X4);
    // 0x80006074: nop

    // 0x80006078: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x8000607C: beq         $t1, $zero, L_80006094
    if (ctx->r9 == 0) {
        // 0x80006080: nop
    
            goto L_80006094;
    }
    // 0x80006080: nop

    // 0x80006084: jal         0x80083E28
    // 0x80006088: nop

    func_80083E28(rdram, ctx);
        goto after_60;
    // 0x80006088: nop

    after_60:
    // 0x8000608C: b           L_8000609C
    // 0x80006090: nop

        goto L_8000609C;
    // 0x80006090: nop

L_80006094:
    // 0x80006094: jal         0x8007A0B0
    // 0x80006098: nop

    func_8007A0B0(rdram, ctx);
        goto after_61;
    // 0x80006098: nop

    after_61:
L_8000609C:
    // 0x8000609C: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x800060A0: nop

    // 0x800060A4: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x800060A8: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x800060AC: lw          $t3, 0x1CC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1CC);
    // 0x800060B0: nop

    // 0x800060B4: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x800060B8: jal         0x800C13B8
    // 0x800060BC: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_62;
    // 0x800060BC: nop

    after_62:
    // 0x800060C0: jal         0x80098820
    // 0x800060C4: nop

    func_80098820(rdram, ctx);
        goto after_63;
    // 0x800060C4: nop

    after_63:
    // 0x800060C8: lw          $t2, 0x1CC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1CC);
    // 0x800060CC: nop

    // 0x800060D0: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800060D4: b           L_80006104
    // 0x800060D8: nop

        goto L_80006104;
    // 0x800060D8: nop

L_800060DC:
    // 0x800060DC: jal         0x800029BC
    // 0x800060E0: nop

    func_800029BC(rdram, ctx);
        goto after_64;
    // 0x800060E0: nop

    after_64:
L_800060E4:
    // 0x800060E4: b           L_800060E4
    pause_self(rdram);
    // 0x800060E8: nop

    // 0x800060EC: b           L_80006104
    // 0x800060F0: nop

        goto L_80006104;
    // 0x800060F0: nop

L_800060F4:
    // 0x800060F4: b           L_80006104
    // 0x800060F8: nop

        goto L_80006104;
    // 0x800060F8: nop

L_800060FC:
    // 0x800060FC: b           L_80006104
    // 0x80006100: nop

        goto L_80006104;
    // 0x80006100: nop

L_80006104:
    // 0x80006104: lw          $t5, 0x1D8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D8);
    // 0x80006108: nop

    // 0x8000610C: beq         $t5, $zero, L_80005B10
    if (ctx->r13 == 0) {
        // 0x80006110: nop
    
            goto L_80005B10;
    }
    // 0x80006110: nop

L_80006114:
    // 0x80006114: lw          $t6, 0x1C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C8);
    // 0x80006118: nop

    // 0x8000611C: addiu       $t7, $t6, 0x7FFF
    ctx->r15 = ADD32(ctx->r14, 0X7FFF);
    // 0x80006120: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80006124: nop

    // 0x80006128: blez        $t7, L_800061AC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000612C: nop
    
            goto L_800061AC;
    }
    // 0x8000612C: nop

L_80006130:
    // 0x80006130: lw          $t8, 0x1CC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1CC);
    // 0x80006134: addiu       $a1, $sp, 0x1C4
    ctx->r5 = ADD32(ctx->r29, 0X1C4);
    // 0x80006138: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000613C: jal         0x800C143C
    // 0x80006140: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_65;
    // 0x80006140: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_65:
    // 0x80006144: lw          $t4, 0x1C4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000614C: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x80006150: nop

    // 0x80006154: bne         $t0, $at, L_80006190
    if (ctx->r8 != ctx->r1) {
        // 0x80006158: nop
    
            goto L_80006190;
    }
    // 0x80006158: nop

    // 0x8000615C: b           L_80006164
    // 0x80006160: nop

        goto L_80006164;
    // 0x80006160: nop

L_80006164:
    // 0x80006164: jal         0x80099520
    // 0x80006168: nop

    func_80099520(rdram, ctx);
        goto after_66;
    // 0x80006168: nop

    after_66:
    // 0x8000616C: lw          $t1, 0x1C8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C8);
    // 0x80006170: nop

    // 0x80006174: addiu       $t9, $t1, 0x7FFF
    ctx->r25 = ADD32(ctx->r9, 0X7FFF);
    // 0x80006178: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x8000617C: addiu       $at, $t1, 0x7FFF
    ctx->r1 = ADD32(ctx->r9, 0X7FFF);
    // 0x80006180: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80006184: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x80006188: b           L_80006190
    // 0x8000618C: nop

        goto L_80006190;
    // 0x8000618C: nop

L_80006190:
    // 0x80006190: lw          $t2, 0x1C8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C8);
    // 0x80006194: nop

    // 0x80006198: addiu       $t5, $t2, 0x7FFF
    ctx->r13 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000619C: lw          $t5, 0x2ED($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2ED);
    // 0x800061A0: nop

    // 0x800061A4: bgtz        $t5, L_80006130
    if (SIGNED(ctx->r13) > 0) {
        // 0x800061A8: nop
    
            goto L_80006130;
    }
    // 0x800061A8: nop

L_800061AC:
    // 0x800061AC: jal         0x80098820
    // 0x800061B0: nop

    func_80098820(rdram, ctx);
        goto after_67;
    // 0x800061B0: nop

    after_67:
    // 0x800061B4: jal         0x80098868
    // 0x800061B8: nop

    func_80098868(rdram, ctx);
        goto after_68;
    // 0x800061B8: nop

    after_68:
    // 0x800061BC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800061C0: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800061C4: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800061C8: nop

    // 0x800061CC: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x800061D0: beq         $t8, $zero, L_800061E8
    if (ctx->r24 == 0) {
        // 0x800061D4: nop
    
            goto L_800061E8;
    }
    // 0x800061D4: nop

    // 0x800061D8: jal         0x80083AD0
    // 0x800061DC: nop

    func_80083AD0(rdram, ctx);
        goto after_69;
    // 0x800061DC: nop

    after_69:
    // 0x800061E0: b           L_800061F0
    // 0x800061E4: nop

        goto L_800061F0;
    // 0x800061E4: nop

L_800061E8:
    // 0x800061E8: jal         0x80079F34
    // 0x800061EC: nop

    func_80079F34(rdram, ctx);
        goto after_70;
    // 0x800061EC: nop

    after_70:
L_800061F0:
    // 0x800061F0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800061F4: lbu         $t4, 0x125A($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X125A);
    // 0x800061F8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800061FC: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x80006200: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80006204: sb          $t0, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = ctx->r8;
    // 0x80006208: lw          $t9, 0x1D0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D0);
    // 0x8000620C: nop

    // 0x80006210: bne         $t9, $zero, L_80006244
    if (ctx->r25 != 0) {
        // 0x80006214: nop
    
            goto L_80006244;
    }
    // 0x80006214: nop

    // 0x80006218: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000621C: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80006220: jal         0x800A6670
    // 0x80006224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_71;
    // 0x80006224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_71:
    // 0x80006228: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000622C: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80006230: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80006234: jal         0x800A6670
    // 0x80006238: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_72;
    // 0x80006238: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_72:
    // 0x8000623C: jal         0x80005460
    // 0x80006240: nop

    func_80005460(rdram, ctx);
        goto after_73;
    // 0x80006240: nop

    after_73:
L_80006244:
    // 0x80006244: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80006248: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x8000624C: jal         0x800A6670
    // 0x80006250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_74;
    // 0x80006250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_74:
    // 0x80006254: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80006258: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x8000625C: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80006260: jal         0x800A6670
    // 0x80006264: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_75;
    // 0x80006264: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_75:
    // 0x80006268: lw          $t3, 0x1CC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1CC);
    // 0x8000626C: nop

    // 0x80006270: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80006274: jal         0x800C13B8
    // 0x80006278: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_76;
    // 0x80006278: nop

    after_76:
    // 0x8000627C: jal         0x80098820
    // 0x80006280: nop

    func_80098820(rdram, ctx);
        goto after_77;
    // 0x80006280: nop

    after_77:
    // 0x80006284: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80006288: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000628C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80006290: addiu       $at, $zero, -0x45
    ctx->r1 = ADD32(0, -0X45);
    // 0x80006294: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x80006298: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
    // 0x8000629C: b           L_800062A4
    // 0x800062A0: nop

        goto L_800062A4;
    // 0x800062A0: nop

L_800062A4:
    // 0x800062A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800062A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800062AC: jr          $ra
    // 0x800062B0: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x800062B0: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    // 0x800062B4: nop

    // 0x800062B8: nop

    // 0x800062BC: nop

;}
RECOMP_FUNC void func_8002D200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D200: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002D204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D208: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002D20C: lw          $t6, 0x307C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X307C);
    // 0x8002D210: nop

    // 0x8002D214: beq         $t6, $zero, L_8002D390
    if (ctx->r14 == 0) {
        // 0x8002D218: nop
    
            goto L_8002D390;
    }
    // 0x8002D218: nop

    // 0x8002D21C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002D220: lw          $t7, 0x1B44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B44);
    // 0x8002D224: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D228: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8002D22C: sw          $t8, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r24;
    // 0x8002D230: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8002D234: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D238: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8002D23C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8002D240: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8002D244: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8002D248: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D24C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002D250: addiu       $t1, $t1, -0x47F8
    ctx->r9 = ADD32(ctx->r9, -0X47F8);
    // 0x8002D254: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8002D258: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8002D25C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002D260: lw          $t4, 0x1B44($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B44);
    // 0x8002D264: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D268: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8002D26C: sw          $t5, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r13;
    // 0x8002D270: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8002D274: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002D278: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8002D27C: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x8002D280: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8002D284: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002D288: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x8002D28C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8002D290: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002D294: lw          $t0, 0x1B44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B44);
    // 0x8002D298: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D29C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002D2A0: sw          $t1, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r9;
    // 0x8002D2A4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8002D2A8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002D2AC: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x8002D2B0: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x8002D2B4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8002D2B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8002D2BC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8002D2C0: ori         $t4, $t4, 0x60
    ctx->r12 = ctx->r12 | 0X60;
    // 0x8002D2C4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8002D2C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002D2CC: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x8002D2D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D2D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D2D8: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x8002D2DC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8002D2E0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8002D2E4: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x8002D2E8: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8002D2EC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8002D2F0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002D2F4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002D2F8: addiu       $t0, $t0, -0x4820
    ctx->r8 = ADD32(ctx->r8, -0X4820);
    // 0x8002D2FC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002D300: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8002D304: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002D308: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x8002D30C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D310: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8002D314: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x8002D318: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8002D31C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D320: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x8002D324: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x8002D328: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8002D32C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8002D330: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D334: addiu       $t7, $t7, -0x4820
    ctx->r15 = ADD32(ctx->r15, -0X4820);
    // 0x8002D338: addiu       $t8, $t7, 0x18
    ctx->r24 = ADD32(ctx->r15, 0X18);
    // 0x8002D33C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8002D340: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002D344: lw          $t0, 0x1B44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B44);
    // 0x8002D348: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D34C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002D350: sw          $t1, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r9;
    // 0x8002D354: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8002D358: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8002D35C: lui         $t2, 0x38A
    ctx->r10 = S32(0X38A << 16);
    // 0x8002D360: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x8002D364: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8002D368: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8002D36C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8002D370: addiu       $t4, $t4, -0x4820
    ctx->r12 = ADD32(ctx->r12, -0X4820);
    // 0x8002D374: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8002D378: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8002D37C: lw          $a1, 0x307C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X307C);
    // 0x8002D380: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002D384: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002D388: jal         0x800B18C4
    // 0x8002D38C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800B18C4(rdram, ctx);
        goto after_0;
    // 0x8002D38C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
L_8002D390:
    // 0x8002D390: b           L_8002D398
    // 0x8002D394: nop

        goto L_8002D398;
    // 0x8002D394: nop

L_8002D398:
    // 0x8002D398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D39C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002D3A0: jr          $ra
    // 0x8002D3A4: nop

    return;
    // 0x8002D3A4: nop

;}
RECOMP_FUNC void func_8006554C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006554C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065554: jal         0x8005F064
    // 0x80065558: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065558: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_0:
    // 0x8006555C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065560: b           L_80065570
    // 0x80065564: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065570;
    // 0x80065564: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065568: b           L_80065570
    // 0x8006556C: nop

        goto L_80065570;
    // 0x8006556C: nop

L_80065570:
    // 0x80065570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065578: jr          $ra
    // 0x8006557C: nop

    return;
    // 0x8006557C: nop

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
RECOMP_FUNC void func_80066BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066BF0: jal         0x80061348
    // 0x80066BF4: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066BF4: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    after_0:
    // 0x80066BF8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066BFC: b           L_80066C0C
    // 0x80066C00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066C0C;
    // 0x80066C00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066C04: b           L_80066C0C
    // 0x80066C08: nop

        goto L_80066C0C;
    // 0x80066C08: nop

L_80066C0C:
    // 0x80066C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066C14: jr          $ra
    // 0x80066C18: nop

    return;
    // 0x80066C18: nop

;}
RECOMP_FUNC void func_80072340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072348: jal         0x80061488
    // 0x8007234C: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007234C: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    after_0:
    // 0x80072350: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80072354: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072358: b           L_80072368
    // 0x8007235C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072368;
    // 0x8007235C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072360: b           L_80072368
    // 0x80072364: nop

        goto L_80072368;
    // 0x80072364: nop

L_80072368:
    // 0x80072368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007236C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072370: jr          $ra
    // 0x80072374: nop

    return;
    // 0x80072374: nop

;}
RECOMP_FUNC void func_8004A0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A0B4: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8004A0B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004A0BC: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x8004A0C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8004A0C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8004A0C8: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8004A0CC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8004A0D0: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x8004A0D4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8004A0D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A0DC: nop

    // 0x8004A0E0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8004A0E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004A0E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A0EC: nop

    // 0x8004A0F0: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8004A0F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004A0F8: nop

    // 0x8004A0FC: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8004A100: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x8004A104: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8004A108: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8004A10C: nop

    // 0x8004A110: sw          $t9, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r25;
    // 0x8004A114: lw          $t0, 0x12C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A118: nop

    // 0x8004A11C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8004A120: nop

    // 0x8004A124: sw          $t1, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r9;
    // 0x8004A128: lw          $t2, 0x12C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A12C: nop

    // 0x8004A130: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x8004A134: jal         0x80098754
    // 0x8004A138: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8004A138: nop

    after_0:
    // 0x8004A13C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8004A140: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8004A144: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8004A148: nop

    // 0x8004A14C: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8004A150: beq         $t5, $zero, L_8004A180
    if (ctx->r13 == 0) {
        // 0x8004A154: nop
    
            goto L_8004A180;
    }
    // 0x8004A154: nop

L_8004A158:
    // 0x8004A158: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A15C: jal         0x800499B0
    // 0x8004A160: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x8004A160: nop

    after_1:
    // 0x8004A164: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004A168: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004A16C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004A170: nop

    // 0x8004A174: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8004A178: bne         $t8, $zero, L_8004A158
    if (ctx->r24 != 0) {
        // 0x8004A17C: nop
    
            goto L_8004A158;
    }
    // 0x8004A17C: nop

L_8004A180:
    // 0x8004A180: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A184: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A188: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004A18C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004A190: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004A194: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004A198: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004A19C: bne         $t2, $zero, L_8004A1E4
    if (ctx->r10 != 0) {
        // 0x8004A1A0: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004A1E4;
    }
    // 0x8004A1A0: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A1A4: bne         $t3, $zero, L_8004A1E4
    if (ctx->r11 != 0) {
        // 0x8004A1A8: nop
    
            goto L_8004A1E4;
    }
    // 0x8004A1A8: nop

L_8004A1AC:
    // 0x8004A1AC: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A1B0: jal         0x800499B0
    // 0x8004A1B4: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8004A1B4: nop

    after_2:
    // 0x8004A1B8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A1BC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004A1C0: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004A1C4: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004A1C8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004A1CC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004A1D0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004A1D4: bne         $t8, $zero, L_8004A1E4
    if (ctx->r24 != 0) {
        // 0x8004A1D8: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004A1E4;
    }
    // 0x8004A1D8: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004A1DC: beq         $t9, $zero, L_8004A1AC
    if (ctx->r25 == 0) {
        // 0x8004A1E0: nop
    
            goto L_8004A1AC;
    }
    // 0x8004A1E0: nop

L_8004A1E4:
    // 0x8004A1E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A1E8: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004A1EC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004A1F0: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x8004A1F4: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004A1F8: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x8004A1FC: bne         $t2, $zero, L_8004A20C
    if (ctx->r10 != 0) {
        // 0x8004A200: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004A20C;
    }
    // 0x8004A200: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A204: beq         $t3, $zero, L_8004A214
    if (ctx->r11 == 0) {
        // 0x8004A208: nop
    
            goto L_8004A214;
    }
    // 0x8004A208: nop

L_8004A20C:
    // 0x8004A20C: b           L_8004AB04
    // 0x8004A210: nop

        goto L_8004AB04;
    // 0x8004A210: nop

L_8004A214:
    // 0x8004A214: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8004A218: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8004A21C: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x8004A220: nop

    // 0x8004A224: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x8004A228: beq         $t7, $zero, L_8004A258
    if (ctx->r15 == 0) {
        // 0x8004A22C: nop
    
            goto L_8004A258;
    }
    // 0x8004A22C: nop

L_8004A230:
    // 0x8004A230: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A234: jal         0x800499B0
    // 0x8004A238: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8004A238: nop

    after_3:
    // 0x8004A23C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8004A240: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8004A244: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8004A248: nop

    // 0x8004A24C: andi        $t5, $t9, 0x400
    ctx->r13 = ctx->r25 & 0X400;
    // 0x8004A250: bne         $t5, $zero, L_8004A230
    if (ctx->r13 != 0) {
        // 0x8004A254: nop
    
            goto L_8004A230;
    }
    // 0x8004A254: nop

L_8004A258:
    // 0x8004A258: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A25C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004A260: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004A264: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004A268: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8004A26C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004A270: bne         $t4, $zero, L_8004A280
    if (ctx->r12 != 0) {
        // 0x8004A274: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8004A280;
    }
    // 0x8004A274: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004A278: beq         $t5, $zero, L_8004A438
    if (ctx->r13 == 0) {
        // 0x8004A27C: nop
    
            goto L_8004A438;
    }
    // 0x8004A27C: nop

L_8004A280:
    // 0x8004A280: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004A284: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A288: sh          $t1, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r9;
    // 0x8004A28C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A290: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004A294: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8004A298: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x8004A29C: nop

    // 0x8004A2A0: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x8004A2A4: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2A8: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A2A8: nop

    // 0x8004A2AC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8004A2B0: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2B4: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A2B4: nop

    // 0x8004A2B8: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8004A2BC: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2C0: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A2C0: nop

    // 0x8004A2C4: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8004A2C8: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2CC: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A2CC: nop

    // 0x8004A2D0: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x8004A2D4: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2D8: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A2D8: nop

    // 0x8004A2DC: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8004A2E0: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2E4: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A2E4: nop

    // 0x8004A2E8: addiu       $at, $zero, 0x73
    ctx->r1 = ADD32(0, 0X73);
    // 0x8004A2EC: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2F0: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A2F0: nop

    // 0x8004A2F4: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8004A2F8: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2FC: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A2FC: nop

    // 0x8004A300: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A304: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A308: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x8004A30C: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x8004A310: nop

    // 0x8004A314: andi        $t2, $t0, 0x1FFF
    ctx->r10 = ctx->r8 & 0X1FFF;
    // 0x8004A318: beq         $t2, $at, L_8004A32C
    if (ctx->r10 == ctx->r1) {
        // 0x8004A31C: nop
    
            goto L_8004A32C;
    }
    // 0x8004A31C: nop

    // 0x8004A320: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x8004A324: bne         $t2, $at, L_8004A380
    if (ctx->r10 != ctx->r1) {
        // 0x8004A328: nop
    
            goto L_8004A380;
    }
    // 0x8004A328: nop

L_8004A32C:
    // 0x8004A32C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004A330: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004A334: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A338: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004A33C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8004A340: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8004A344: lui         $at, 0xFFBF
    ctx->r1 = S32(0XFFBF << 16);
    // 0x8004A348: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004A34C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8004A350: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004A354: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8004A358: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004A35C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004A360: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004A364: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8004A368: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x8004A36C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8004A370: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8004A374: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8004A378: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8004A37C: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
L_8004A380:
    // 0x8004A380: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A384: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004A388: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004A38C: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004A390: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004A394: bne         $t8, $zero, L_8004A3D4
    if (ctx->r24 != 0) {
        // 0x8004A398: andi        $t9, $t7, 0x2
        ctx->r25 = ctx->r15 & 0X2;
            goto L_8004A3D4;
    }
    // 0x8004A398: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x8004A39C: bne         $t9, $zero, L_8004A3D4
    if (ctx->r25 != 0) {
        // 0x8004A3A0: nop
    
            goto L_8004A3D4;
    }
    // 0x8004A3A0: nop

L_8004A3A4:
    // 0x8004A3A4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A3A8: jal         0x800499B0
    // 0x8004A3AC: nop

    func_800499B0(rdram, ctx);
        goto after_4;
    // 0x8004A3AC: nop

    after_4:
    // 0x8004A3B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A3B4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004A3B8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004A3BC: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x8004A3C0: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x8004A3C4: bne         $t2, $zero, L_8004A3D4
    if (ctx->r10 != 0) {
        // 0x8004A3C8: andi        $t3, $t1, 0x2
        ctx->r11 = ctx->r9 & 0X2;
            goto L_8004A3D4;
    }
    // 0x8004A3C8: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x8004A3CC: beq         $t3, $zero, L_8004A3A4
    if (ctx->r11 == 0) {
        // 0x8004A3D0: nop
    
            goto L_8004A3A4;
    }
    // 0x8004A3D0: nop

L_8004A3D4:
    // 0x8004A3D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A3D8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004A3DC: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x8004A3E0: sw          $t4, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r12;
    // 0x8004A3E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A3E8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004A3EC: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A3F0: lh          $a1, 0x4A($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X4A);
    // 0x8004A3F4: nop

    // 0x8004A3F8: andi        $t8, $a1, 0x1FFF
    ctx->r24 = ctx->r5 & 0X1FFF;
    // 0x8004A3FC: jal         0x8005218C
    // 0x8004A400: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8005218C(rdram, ctx);
        goto after_5;
    // 0x8004A400: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_5:
    // 0x8004A404: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A408: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A40C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A410: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004A414: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004A418: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8004A41C: lui         $at, 0xFFBF
    ctx->r1 = S32(0XFFBF << 16);
    // 0x8004A420: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004A424: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A428: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8004A42C: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8004A430: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A434: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
L_8004A438:
    // 0x8004A438: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A43C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004A440: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004A444: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8004A448: lw          $t5, 0x4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4);
    // 0x8004A44C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004A450: bne         $t6, $zero, L_8004A460
    if (ctx->r14 != 0) {
        // 0x8004A454: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_8004A460;
    }
    // 0x8004A454: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8004A458: beq         $t7, $zero, L_8004A4BC
    if (ctx->r15 == 0) {
        // 0x8004A45C: nop
    
            goto L_8004A4BC;
    }
    // 0x8004A45C: nop

L_8004A460:
    // 0x8004A460: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A464: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004A468: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A46C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004A470: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8004A474: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8004A478: lui         $at, 0xFDFF
    ctx->r1 = S32(0XFDFF << 16);
    // 0x8004A47C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004A480: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A484: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8004A488: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8004A48C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A490: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x8004A494: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004A498: beq         $t9, $at, L_8004A4BC
    if (ctx->r25 == ctx->r1) {
        // 0x8004A49C: nop
    
            goto L_8004A4BC;
    }
    // 0x8004A49C: nop

    // 0x8004A4A0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A4A4: lh          $t4, 0x6C0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C0);
    // 0x8004A4A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A4AC: beq         $t4, $at, L_8004A4BC
    if (ctx->r12 == ctx->r1) {
        // 0x8004A4B0: nop
    
            goto L_8004A4BC;
    }
    // 0x8004A4B0: nop

    // 0x8004A4B4: b           L_8004A55C
    // 0x8004A4B8: nop

        goto L_8004A55C;
    // 0x8004A4B8: nop

L_8004A4BC:
    // 0x8004A4BC: jal         0x8005A768
    // 0x8004A4C0: nop

    func_8005A768(rdram, ctx);
        goto after_6;
    // 0x8004A4C0: nop

    after_6:
    // 0x8004A4C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A4C8: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
    // 0x8004A4CC: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8004A4D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A4D4: sh          $t5, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r13;
    // 0x8004A4D8: jal         0x80057960
    // 0x8004A4DC: nop

    func_80057960(rdram, ctx);
        goto after_7;
    // 0x8004A4DC: nop

    after_7:
    // 0x8004A4E0: sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    // 0x8004A4E4: lw          $t6, 0x120($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X120);
    // 0x8004A4E8: nop

    // 0x8004A4EC: beq         $t6, $zero, L_8004A4FC
    if (ctx->r14 == 0) {
        // 0x8004A4F0: nop
    
            goto L_8004A4FC;
    }
    // 0x8004A4F0: nop

    // 0x8004A4F4: b           L_8004AB04
    // 0x8004A4F8: nop

        goto L_8004AB04;
    // 0x8004A4F8: nop

L_8004A4FC:
    // 0x8004A4FC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004A500: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x8004A504: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004A508: bne         $t7, $at, L_8004A52C
    if (ctx->r15 != ctx->r1) {
        // 0x8004A50C: nop
    
            goto L_8004A52C;
    }
    // 0x8004A50C: nop

    // 0x8004A510: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004A514: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004A518: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004A51C: bne         $t0, $at, L_8004A52C
    if (ctx->r8 != ctx->r1) {
        // 0x8004A520: nop
    
            goto L_8004A52C;
    }
    // 0x8004A520: nop

    // 0x8004A524: b           L_8004AB04
    // 0x8004A528: nop

        goto L_8004AB04;
    // 0x8004A528: nop

L_8004A52C:
    // 0x8004A52C: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A530: jal         0x80050AC4
    // 0x8004A534: nop

    func_80050AC4(rdram, ctx);
        goto after_8;
    // 0x8004A534: nop

    after_8:
    // 0x8004A538: jal         0x80057960
    // 0x8004A53C: nop

    func_80057960(rdram, ctx);
        goto after_9;
    // 0x8004A53C: nop

    after_9:
    // 0x8004A540: sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    // 0x8004A544: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x8004A548: nop

    // 0x8004A54C: beq         $t1, $zero, L_8004A55C
    if (ctx->r9 == 0) {
        // 0x8004A550: nop
    
            goto L_8004A55C;
    }
    // 0x8004A550: nop

    // 0x8004A554: b           L_8004AB04
    // 0x8004A558: nop

        goto L_8004AB04;
    // 0x8004A558: nop

L_8004A55C:
    // 0x8004A55C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004A560: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004A564: nop

    // 0x8004A568: sw          $zero, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = 0;
    // 0x8004A56C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004A570: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004A574: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004A578: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8004A57C: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x8004A580: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004A584: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8004A588: bne         $t4, $zero, L_8004A598
    if (ctx->r12 != 0) {
        // 0x8004A58C: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004A598;
    }
    // 0x8004A58C: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004A590: beq         $t5, $zero, L_8004A5B4
    if (ctx->r13 == 0) {
        // 0x8004A594: nop
    
            goto L_8004A5B4;
    }
    // 0x8004A594: nop

L_8004A598:
    // 0x8004A598: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A59C: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x8004A5A0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8004A5A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A5A8: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x8004A5AC: b           L_8004AAA8
    // 0x8004A5B0: nop

        goto L_8004AAA8;
    // 0x8004A5B0: nop

L_8004A5B4:
    // 0x8004A5B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A5B8: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x8004A5BC: nop

    // 0x8004A5C0: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x8004A5C4: beq         $at, $zero, L_8004A688
    if (ctx->r1 == 0) {
        // 0x8004A5C8: nop
    
            goto L_8004A688;
    }
    // 0x8004A5C8: nop

    // 0x8004A5CC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A5D0: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x8004A5D4: nop

    // 0x8004A5D8: beq         $t0, $zero, L_8004A644
    if (ctx->r8 == 0) {
        // 0x8004A5DC: nop
    
            goto L_8004A644;
    }
    // 0x8004A5DC: nop

L_8004A5E0:
    // 0x8004A5E0: jal         0x8005151C
    // 0x8004A5E4: nop

    func_8005151C(rdram, ctx);
        goto after_10;
    // 0x8004A5E4: nop

    after_10:
    // 0x8004A5E8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004A5EC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004A5F0: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004A5F4: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8004A5F8: lh          $t2, 0x4A($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4A);
    // 0x8004A5FC: nop

    // 0x8004A600: beq         $t2, $t3, L_8004A624
    if (ctx->r10 == ctx->r11) {
        // 0x8004A604: nop
    
            goto L_8004A624;
    }
    // 0x8004A604: nop

    // 0x8004A608: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A60C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004A610: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8004A614: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A618: lh          $a1, 0x42($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X42);
    // 0x8004A61C: jal         0x8004EF90
    // 0x8004A620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_11;
    // 0x8004A620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
L_8004A624:
    // 0x8004A624: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A628: jal         0x800499B0
    // 0x8004A62C: nop

    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x8004A62C: nop

    after_12:
    // 0x8004A630: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A634: lh          $t9, 0x6C0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X6C0);
    // 0x8004A638: nop

    // 0x8004A63C: bne         $t9, $zero, L_8004A5E0
    if (ctx->r25 != 0) {
        // 0x8004A640: nop
    
            goto L_8004A5E0;
    }
    // 0x8004A640: nop

L_8004A644:
    // 0x8004A644: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A648: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A64C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004A650: lh          $t4, 0x10F0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10F0);
    // 0x8004A654: nop

    // 0x8004A658: sb          $t4, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r12;
    // 0x8004A65C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A660: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004A664: nop

    // 0x8004A668: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8004A66C: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x8004A670: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8004A674: ori         $t3, $t1, 0x4000
    ctx->r11 = ctx->r9 | 0X4000;
    // 0x8004A678: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8004A67C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8004A680: b           L_8004A598
    // 0x8004A684: nop

        goto L_8004A598;
    // 0x8004A684: nop

L_8004A688:
    // 0x8004A688: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A68C: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x8004A690: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004A694: beq         $t7, $at, L_8004A958
    if (ctx->r15 == ctx->r1) {
        // 0x8004A698: nop
    
            goto L_8004A958;
    }
    // 0x8004A698: nop

    // 0x8004A69C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A6A0: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004A6A4: nop

    // 0x8004A6A8: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x8004A6AC: nop

    // 0x8004A6B0: slti        $at, $t9, 0x2BC
    ctx->r1 = SIGNED(ctx->r25) < 0X2BC ? 1 : 0;
    // 0x8004A6B4: bne         $at, $zero, L_8004A720
    if (ctx->r1 != 0) {
        // 0x8004A6B8: nop
    
            goto L_8004A720;
    }
    // 0x8004A6B8: nop

    // 0x8004A6BC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A6C0: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004A6C4: nop

    // 0x8004A6C8: lh          $t5, 0x2E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2E);
    // 0x8004A6CC: nop

    // 0x8004A6D0: slti        $at, $t5, 0x384
    ctx->r1 = SIGNED(ctx->r13) < 0X384 ? 1 : 0;
    // 0x8004A6D4: beq         $at, $zero, L_8004A6F4
    if (ctx->r1 == 0) {
        // 0x8004A6D8: nop
    
            goto L_8004A6F4;
    }
    // 0x8004A6D8: nop

    // 0x8004A6DC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A6E0: lw          $t0, 0x670($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X670);
    // 0x8004A6E4: nop

    // 0x8004A6E8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8004A6EC: beq         $t1, $zero, L_8004A720
    if (ctx->r9 == 0) {
        // 0x8004A6F0: nop
    
            goto L_8004A720;
    }
    // 0x8004A6F0: nop

L_8004A6F4:
    // 0x8004A6F4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004A6F8: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004A6FC: nop

    // 0x8004A700: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8004A704: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8004A708: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8004A70C: ori         $t9, $t7, 0x2000
    ctx->r25 = ctx->r15 | 0X2000;
    // 0x8004A710: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8004A714: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8004A718: b           L_8004A598
    // 0x8004A71C: nop

        goto L_8004A598;
    // 0x8004A71C: nop

L_8004A720:
    // 0x8004A720: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004A724: lh          $a0, 0x10F0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X10F0);
    // 0x8004A728: jal         0x8005A2CC
    // 0x8004A72C: nop

    func_8005A2CC(rdram, ctx);
        goto after_13;
    // 0x8004A72C: nop

    after_13:
    // 0x8004A730: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004A734: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x8004A738: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004A73C: bne         $t3, $at, L_8004A800
    if (ctx->r11 != ctx->r1) {
        // 0x8004A740: nop
    
            goto L_8004A800;
    }
    // 0x8004A740: nop

    // 0x8004A744: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A748: jal         0x800527C4
    // 0x8004A74C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800527C4(rdram, ctx);
        goto after_14;
    // 0x8004A74C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8004A750: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A754: lh          $t4, 0x6C0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C0);
    // 0x8004A758: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A75C: bne         $t4, $at, L_8004A76C
    if (ctx->r12 != ctx->r1) {
        // 0x8004A760: nop
    
            goto L_8004A76C;
    }
    // 0x8004A760: nop

    // 0x8004A764: b           L_8004A438
    // 0x8004A768: nop

        goto L_8004A438;
    // 0x8004A768: nop

L_8004A76C:
    // 0x8004A76C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A770: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x8004A774: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004A778: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A77C: nop
    
            goto L_8004A7E0;
    }
    // 0x8004A77C: nop

    // 0x8004A780: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004A784: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A788: nop
    
            goto L_8004A7E0;
    }
    // 0x8004A788: nop

    // 0x8004A78C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A790: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A794: nop
    
            goto L_8004A7E0;
    }
    // 0x8004A794: nop

    // 0x8004A798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004A79C: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A7A0: nop
    
            goto L_8004A7E0;
    }
    // 0x8004A7A0: nop

    // 0x8004A7A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A7A8: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A7AC: nop
    
            goto L_8004A7E0;
    }
    // 0x8004A7AC: nop

    // 0x8004A7B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004A7B4: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A7B8: nop
    
            goto L_8004A7E0;
    }
    // 0x8004A7B8: nop

    // 0x8004A7BC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A7C0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004A7C4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004A7C8: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8004A7CC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004A7D0: bne         $t8, $zero, L_8004A7E0
    if (ctx->r24 != 0) {
        // 0x8004A7D4: andi        $t9, $t7, 0x1000
        ctx->r25 = ctx->r15 & 0X1000;
            goto L_8004A7E0;
    }
    // 0x8004A7D4: andi        $t9, $t7, 0x1000
    ctx->r25 = ctx->r15 & 0X1000;
    // 0x8004A7D8: beq         $t9, $zero, L_8004A7F8
    if (ctx->r25 == 0) {
        // 0x8004A7DC: nop
    
            goto L_8004A7F8;
    }
    // 0x8004A7DC: nop

L_8004A7E0:
    // 0x8004A7E0: jal         0x80061F08
    // 0x8004A7E4: nop

    func_80061F08(rdram, ctx);
        goto after_15;
    // 0x8004A7E4: nop

    after_15:
    // 0x8004A7E8: bne         $v0, $zero, L_8004A7F8
    if (ctx->r2 != 0) {
        // 0x8004A7EC: nop
    
            goto L_8004A7F8;
    }
    // 0x8004A7EC: nop

    // 0x8004A7F0: b           L_8004A55C
    // 0x8004A7F4: nop

        goto L_8004A55C;
    // 0x8004A7F4: nop

L_8004A7F8:
    // 0x8004A7F8: b           L_8004A950
    // 0x8004A7FC: nop

        goto L_8004A950;
    // 0x8004A7FC: nop

L_8004A800:
    // 0x8004A800: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004A804: lh          $t1, 0x10F0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X10F0);
    // 0x8004A808: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004A80C: bne         $t1, $at, L_8004A8C4
    if (ctx->r9 != ctx->r1) {
        // 0x8004A810: nop
    
            goto L_8004A8C4;
    }
    // 0x8004A810: nop

    // 0x8004A814: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004A818: lw          $t2, 0x11A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11A0);
    // 0x8004A81C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8004A820: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x8004A824: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x8004A828: nop

    // 0x8004A82C: bne         $t3, $t4, L_8004A8B4
    if (ctx->r11 != ctx->r12) {
        // 0x8004A830: nop
    
            goto L_8004A8B4;
    }
    // 0x8004A830: nop

    // 0x8004A834: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004A838: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004A83C: lh          $t5, 0x4($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X4);
    // 0x8004A840: nop

    // 0x8004A844: bne         $t5, $t0, L_8004A8B4
    if (ctx->r13 != ctx->r8) {
        // 0x8004A848: nop
    
            goto L_8004A8B4;
    }
    // 0x8004A848: nop

    // 0x8004A84C: lh          $t6, 0x6($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X6);
    // 0x8004A850: nop

    // 0x8004A854: bne         $t6, $zero, L_8004A8B4
    if (ctx->r14 != 0) {
        // 0x8004A858: nop
    
            goto L_8004A8B4;
    }
    // 0x8004A858: nop

    // 0x8004A85C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A860: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A864: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004A868: lw          $t7, 0x11A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11A0);
    // 0x8004A86C: nop

    // 0x8004A870: sw          $t7, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->r15;
    // 0x8004A874: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A878: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A87C: nop

    // 0x8004A880: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8004A884: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8004A888: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8004A88C: ori         $t1, $t5, 0x8000
    ctx->r9 = ctx->r13 | 0X8000;
    // 0x8004A890: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8004A894: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8004A898: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8004A89C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A8A0: sh          $t3, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r11;
    // 0x8004A8A4: b           L_8004AAA8
    // 0x8004A8A8: nop

        goto L_8004AAA8;
    // 0x8004A8A8: nop

    // 0x8004A8AC: b           L_8004A8BC
    // 0x8004A8B0: nop

        goto L_8004A8BC;
    // 0x8004A8B0: nop

L_8004A8B4:
    // 0x8004A8B4: b           L_8004A438
    // 0x8004A8B8: nop

        goto L_8004A438;
    // 0x8004A8B8: nop

L_8004A8BC:
    // 0x8004A8BC: b           L_8004A950
    // 0x8004A8C0: nop

        goto L_8004A950;
    // 0x8004A8C0: nop

L_8004A8C4:
    // 0x8004A8C4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004A8C8: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x8004A8CC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004A8D0: bne         $t2, $at, L_8004A950
    if (ctx->r10 != ctx->r1) {
        // 0x8004A8D4: nop
    
            goto L_8004A950;
    }
    // 0x8004A8D4: nop

    // 0x8004A8D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A8DC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A8E0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004A8E4: lw          $t6, 0x11A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11A8);
    // 0x8004A8E8: nop

    // 0x8004A8EC: sw          $t6, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->r14;
    // 0x8004A8F0: jal         0x80059ED0
    // 0x8004A8F4: nop

    func_80059ED0(rdram, ctx);
        goto after_16;
    // 0x8004A8F4: nop

    after_16:
    // 0x8004A8F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A8FC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004A900: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004A904: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x8004A908: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8004A90C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8004A910: or          $t1, $t5, $at
    ctx->r9 = ctx->r13 | ctx->r1;
    // 0x8004A914: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8004A918: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8004A91C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A920: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A924: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8004A928: lw          $t3, 0x58($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X58);
    // 0x8004A92C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004A930: lbu         $a0, 0x16($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X16);
    // 0x8004A934: jal         0x8008312C
    // 0x8004A938: nop

    func_8008312C(rdram, ctx);
        goto after_17;
    // 0x8004A938: nop

    after_17:
    // 0x8004A93C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8004A940: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A944: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x8004A948: b           L_8004AAA8
    // 0x8004A94C: nop

        goto L_8004AAA8;
    // 0x8004A94C: nop

L_8004A950:
    // 0x8004A950: b           L_8004AA94
    // 0x8004A954: nop

        goto L_8004AA94;
    // 0x8004A954: nop

L_8004A958:
    // 0x8004A958: jal         0x80056118
    // 0x8004A95C: nop

    func_80056118(rdram, ctx);
        goto after_18;
    // 0x8004A95C: nop

    after_18:
    // 0x8004A960: bne         $v0, $zero, L_8004AA94
    if (ctx->r2 != 0) {
        // 0x8004A964: nop
    
            goto L_8004AA94;
    }
    // 0x8004A964: nop

    // 0x8004A968: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8004A96C: lw          $s0, 0x678($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X678);
    // 0x8004A970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A974: bgez        $s0, L_8004A988
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8004A978: andi        $t6, $s0, 0x7
        ctx->r14 = ctx->r16 & 0X7;
            goto L_8004A988;
    }
    // 0x8004A978: andi        $t6, $s0, 0x7
    ctx->r14 = ctx->r16 & 0X7;
    // 0x8004A97C: beq         $t6, $zero, L_8004A988
    if (ctx->r14 == 0) {
        // 0x8004A980: nop
    
            goto L_8004A988;
    }
    // 0x8004A980: nop

    // 0x8004A984: addiu       $t6, $t6, -0x8
    ctx->r14 = ADD32(ctx->r14, -0X8);
L_8004A988:
    // 0x8004A988: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8004A98C: beq         $s0, $at, L_8004A9B4
    if (ctx->r16 == ctx->r1) {
        // 0x8004A990: nop
    
            goto L_8004A9B4;
    }
    // 0x8004A990: nop

    // 0x8004A994: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004A998: beq         $s0, $at, L_8004A9B4
    if (ctx->r16 == ctx->r1) {
        // 0x8004A99C: nop
    
            goto L_8004A9B4;
    }
    // 0x8004A99C: nop

    // 0x8004A9A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A9A4: beq         $s0, $at, L_8004AA08
    if (ctx->r16 == ctx->r1) {
        // 0x8004A9A8: nop
    
            goto L_8004AA08;
    }
    // 0x8004A9A8: nop

    // 0x8004A9AC: b           L_8004AA94
    // 0x8004A9B0: nop

        goto L_8004AA94;
    // 0x8004A9B0: nop

L_8004A9B4:
    // 0x8004A9B4: jal         0x80057538
    // 0x8004A9B8: nop

    func_80057538(rdram, ctx);
        goto after_19;
    // 0x8004A9B8: nop

    after_19:
    // 0x8004A9BC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A9C0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004A9C4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8004A9C8: beq         $s1, $zero, L_8004AA00
    if (ctx->r17 == 0) {
        // 0x8004A9CC: sw          $s1, 0x5C($t7)
        MEM_W(0X5C, ctx->r15) = ctx->r17;
            goto L_8004AA00;
    }
    // 0x8004A9CC: sw          $s1, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->r17;
    // 0x8004A9D0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A9D4: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004A9D8: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004A9DC: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8004A9E0: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x8004A9E4: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x8004A9E8: ori         $t8, $t0, 0x2
    ctx->r24 = ctx->r8 | 0X2;
    // 0x8004A9EC: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x8004A9F0: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8004A9F4: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8004A9F8: b           L_8004A598
    // 0x8004A9FC: nop

        goto L_8004A598;
    // 0x8004A9FC: nop

L_8004AA00:
    // 0x8004AA00: b           L_8004AA94
    // 0x8004AA04: nop

        goto L_8004AA94;
    // 0x8004AA04: nop

L_8004AA08:
    // 0x8004AA08: jal         0x80061E14
    // 0x8004AA0C: nop

    func_80061E14(rdram, ctx);
        goto after_20;
    // 0x8004AA0C: nop

    after_20:
    // 0x8004AA10: beq         $v0, $zero, L_8004AA20
    if (ctx->r2 == 0) {
        // 0x8004AA14: nop
    
            goto L_8004AA20;
    }
    // 0x8004AA14: nop

    // 0x8004AA18: b           L_8004A598
    // 0x8004AA1C: nop

        goto L_8004A598;
    // 0x8004AA1C: nop

L_8004AA20:
    // 0x8004AA20: jal         0x80057714
    // 0x8004AA24: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_80057714(rdram, ctx);
        goto after_21;
    // 0x8004AA24: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_21:
    // 0x8004AA28: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004AA2C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004AA30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004AA34: beq         $s0, $zero, L_8004AA8C
    if (ctx->r16 == 0) {
        // 0x8004AA38: sw          $s0, 0x58($t5)
        MEM_W(0X58, ctx->r13) = ctx->r16;
            goto L_8004AA8C;
    }
    // 0x8004AA38: sw          $s0, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r16;
    // 0x8004AA3C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AA40: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004AA44: lui         $at, 0x201
    ctx->r1 = S32(0X201 << 16);
    // 0x8004AA48: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x8004AA4C: or          $t6, $t3, $zero
    ctx->r14 = ctx->r11 | 0;
    // 0x8004AA50: lw          $t3, 0x4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4);
    // 0x8004AA54: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x8004AA58: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8004AA5C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8004AA60: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8004AA64: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004AA68: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004AA6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8004AA70: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x8004AA74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004AA78: lbu         $a0, 0x16($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X16);
    // 0x8004AA7C: jal         0x8008312C
    // 0x8004AA80: nop

    func_8008312C(rdram, ctx);
        goto after_22;
    // 0x8004AA80: nop

    after_22:
    // 0x8004AA84: b           L_8004A598
    // 0x8004AA88: nop

        goto L_8004A598;
    // 0x8004AA88: nop

L_8004AA8C:
    // 0x8004AA8C: b           L_8004AA94
    // 0x8004AA90: nop

        goto L_8004AA94;
    // 0x8004AA90: nop

L_8004AA94:
    // 0x8004AA94: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004AA98: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x8004AA9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004AAA0: bne         $t9, $at, L_8004A438
    if (ctx->r25 != ctx->r1) {
        // 0x8004AAA4: nop
    
            goto L_8004A438;
    }
    // 0x8004AAA4: nop

L_8004AAA8:
    // 0x8004AAA8: jal         0x80031AC8
    // 0x8004AAAC: nop

    func_80031AC8(rdram, ctx);
        goto after_23;
    // 0x8004AAAC: nop

    after_23:
    // 0x8004AAB0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004AAB4: bne         $v0, $at, L_8004AAD0
    if (ctx->r2 != ctx->r1) {
        // 0x8004AAB8: nop
    
            goto L_8004AAD0;
    }
    // 0x8004AAB8: nop

    // 0x8004AABC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004AAC0: lh          $t4, 0x6C0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C0);
    // 0x8004AAC4: nop

    // 0x8004AAC8: beq         $t4, $zero, L_8004AB04
    if (ctx->r12 == 0) {
        // 0x8004AACC: nop
    
            goto L_8004AB04;
    }
    // 0x8004AACC: nop

L_8004AAD0:
    // 0x8004AAD0: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004AAD4: jal         0x800499B0
    // 0x8004AAD8: nop

    func_800499B0(rdram, ctx);
        goto after_24;
    // 0x8004AAD8: nop

    after_24:
    // 0x8004AADC: jal         0x80031AC8
    // 0x8004AAE0: nop

    func_80031AC8(rdram, ctx);
        goto after_25;
    // 0x8004AAE0: nop

    after_25:
    // 0x8004AAE4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004AAE8: bne         $v0, $at, L_8004AAD0
    if (ctx->r2 != ctx->r1) {
        // 0x8004AAEC: nop
    
            goto L_8004AAD0;
    }
    // 0x8004AAEC: nop

    // 0x8004AAF0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004AAF4: lh          $t5, 0x6C0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C0);
    // 0x8004AAF8: nop

    // 0x8004AAFC: bne         $t5, $zero, L_8004AAD0
    if (ctx->r13 != 0) {
        // 0x8004AB00: nop
    
            goto L_8004AAD0;
    }
    // 0x8004AB00: nop

L_8004AB04:
    // 0x8004AB04: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
L_8004AB08:
    // 0x8004AB08: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8004AB0C: jal         0x8005F268
    // 0x8004AB10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_8005F268(rdram, ctx);
        goto after_26;
    // 0x8004AB10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_26:
    // 0x8004AB14: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8004AB18: nop

    // 0x8004AB1C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8004AB20: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8004AB24: bne         $at, $zero, L_8004AB08
    if (ctx->r1 != 0) {
        // 0x8004AB28: sw          $t3, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r11;
            goto L_8004AB08;
    }
    // 0x8004AB28: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
L_8004AB2C:
    // 0x8004AB2C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004AB30: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004AB34: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004AB38: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8004AB3C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004AB40: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004AB44: bne         $t8, $zero, L_8004AB7C
    if (ctx->r24 != 0) {
        // 0x8004AB48: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004AB7C;
    }
    // 0x8004AB48: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004AB4C: bne         $t9, $zero, L_8004AB7C
    if (ctx->r25 != 0) {
        // 0x8004AB50: nop
    
            goto L_8004AB7C;
    }
    // 0x8004AB50: nop

    // 0x8004AB54: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    // 0x8004AB58: addiu       $a1, $sp, 0x11C
    ctx->r5 = ADD32(ctx->r29, 0X11C);
    // 0x8004AB5C: jal         0x80054690
    // 0x8004AB60: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_80054690(rdram, ctx);
        goto after_27;
    // 0x8004AB60: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_27:
    // 0x8004AB64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004AB68: lw          $a0, 0x120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X120);
    // 0x8004AB6C: jal         0x80060440
    // 0x8004AB70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80060440(rdram, ctx);
        goto after_28;
    // 0x8004AB70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_28:
    // 0x8004AB74: bne         $v0, $zero, L_8004AB7C
    if (ctx->r2 != 0) {
        // 0x8004AB78: nop
    
            goto L_8004AB7C;
    }
    // 0x8004AB78: nop

L_8004AB7C:
    // 0x8004AB7C: jal         0x80031AC8
    // 0x8004AB80: nop

    func_80031AC8(rdram, ctx);
        goto after_29;
    // 0x8004AB80: nop

    after_29:
    // 0x8004AB84: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004AB88: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8004AB8C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004AB90: beq         $t1, $at, L_8004ABD0
    if (ctx->r9 == ctx->r1) {
        // 0x8004AB94: nop
    
            goto L_8004ABD0;
    }
    // 0x8004AB94: nop

    // 0x8004AB98: beq         $t1, $zero, L_8004ABD0
    if (ctx->r9 == 0) {
        // 0x8004AB9C: nop
    
            goto L_8004ABD0;
    }
    // 0x8004AB9C: nop

L_8004ABA0:
    // 0x8004ABA0: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004ABA4: jal         0x800499B0
    // 0x8004ABA8: nop

    func_800499B0(rdram, ctx);
        goto after_30;
    // 0x8004ABA8: nop

    after_30:
    // 0x8004ABAC: jal         0x80031AC8
    // 0x8004ABB0: nop

    func_80031AC8(rdram, ctx);
        goto after_31;
    // 0x8004ABB0: nop

    after_31:
    // 0x8004ABB4: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004ABB8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8004ABBC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004ABC0: beq         $t4, $at, L_8004ABD0
    if (ctx->r12 == ctx->r1) {
        // 0x8004ABC4: nop
    
            goto L_8004ABD0;
    }
    // 0x8004ABC4: nop

    // 0x8004ABC8: bne         $t4, $zero, L_8004ABA0
    if (ctx->r12 != 0) {
        // 0x8004ABCC: nop
    
            goto L_8004ABA0;
    }
    // 0x8004ABCC: nop

L_8004ABD0:
    // 0x8004ABD0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004ABD4: lh          $t5, 0x6C0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C0);
    // 0x8004ABD8: nop

    // 0x8004ABDC: beq         $t5, $zero, L_8004AC04
    if (ctx->r13 == 0) {
        // 0x8004ABE0: nop
    
            goto L_8004AC04;
    }
    // 0x8004ABE0: nop

L_8004ABE4:
    // 0x8004ABE4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004ABE8: jal         0x800499B0
    // 0x8004ABEC: nop

    func_800499B0(rdram, ctx);
        goto after_32;
    // 0x8004ABEC: nop

    after_32:
    // 0x8004ABF0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004ABF4: lh          $t2, 0x6C0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X6C0);
    // 0x8004ABF8: nop

    // 0x8004ABFC: bne         $t2, $zero, L_8004ABE4
    if (ctx->r10 != 0) {
        // 0x8004AC00: nop
    
            goto L_8004ABE4;
    }
    // 0x8004AC00: nop

L_8004AC04:
    // 0x8004AC04: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AC08: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004AC0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004AC10: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8004AC14: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004AC18: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x8004AC1C: lui         $at, 0xFBFB
    ctx->r1 = S32(0XFBFB << 16);
    // 0x8004AC20: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004AC24: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004AC28: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004AC2C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8004AC30: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004AC34: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004AC38: lw          $a1, 0xE64($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XE64);
    // 0x8004AC3C: lw          $a0, 0x640($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X640);
    // 0x8004AC40: jal         0x8006081C
    // 0x8004AC44: nop

    func_8006081C(rdram, ctx);
        goto after_33;
    // 0x8004AC44: nop

    after_33:
    // 0x8004AC48: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
    // 0x8004AC4C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004AC50: lw          $t8, 0x640($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X640);
    // 0x8004AC54: nop

    // 0x8004AC58: lbu         $t9, 0xA($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XA);
    // 0x8004AC5C: nop

    // 0x8004AC60: bne         $t9, $zero, L_8004AD3C
    if (ctx->r25 != 0) {
        // 0x8004AC64: nop
    
            goto L_8004AD3C;
    }
    // 0x8004AC64: nop

    // 0x8004AC68: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004AC6C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004AC70: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004AC74: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8004AC78: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004AC7C: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8004AC80: bne         $t0, $zero, L_8004AD3C
    if (ctx->r8 != 0) {
        // 0x8004AC84: and         $t1, $t3, $at
        ctx->r9 = ctx->r11 & ctx->r1;
            goto L_8004AD3C;
    }
    // 0x8004AC84: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004AC88: bne         $t1, $zero, L_8004AD3C
    if (ctx->r9 != 0) {
        // 0x8004AC8C: nop
    
            goto L_8004AD3C;
    }
    // 0x8004AC8C: nop

    // 0x8004AC90: jal         0x80031AC8
    // 0x8004AC94: nop

    func_80031AC8(rdram, ctx);
        goto after_34;
    // 0x8004AC94: nop

    after_34:
    // 0x8004AC98: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004AC9C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8004ACA0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004ACA4: beq         $t5, $at, L_8004ACE4
    if (ctx->r13 == ctx->r1) {
        // 0x8004ACA8: nop
    
            goto L_8004ACE4;
    }
    // 0x8004ACA8: nop

    // 0x8004ACAC: beq         $t5, $zero, L_8004ACE4
    if (ctx->r13 == 0) {
        // 0x8004ACB0: nop
    
            goto L_8004ACE4;
    }
    // 0x8004ACB0: nop

L_8004ACB4:
    // 0x8004ACB4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004ACB8: jal         0x800499B0
    // 0x8004ACBC: nop

    func_800499B0(rdram, ctx);
        goto after_35;
    // 0x8004ACBC: nop

    after_35:
    // 0x8004ACC0: jal         0x80031AC8
    // 0x8004ACC4: nop

    func_80031AC8(rdram, ctx);
        goto after_36;
    // 0x8004ACC4: nop

    after_36:
    // 0x8004ACC8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004ACCC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8004ACD0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004ACD4: beq         $t6, $at, L_8004ACE4
    if (ctx->r14 == ctx->r1) {
        // 0x8004ACD8: nop
    
            goto L_8004ACE4;
    }
    // 0x8004ACD8: nop

    // 0x8004ACDC: bne         $t6, $zero, L_8004ACB4
    if (ctx->r14 != 0) {
        // 0x8004ACE0: nop
    
            goto L_8004ACB4;
    }
    // 0x8004ACE0: nop

L_8004ACE4:
    // 0x8004ACE4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004ACE8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004ACEC: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004ACF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8004ACF4: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8004ACF8: andi        $t4, $t8, 0x1
    ctx->r12 = ctx->r24 & 0X1;
    // 0x8004ACFC: bne         $t4, $zero, L_8004AD3C
    if (ctx->r12 != 0) {
        // 0x8004AD00: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004AD3C;
    }
    // 0x8004AD00: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004AD04: bne         $t5, $zero, L_8004AD3C
    if (ctx->r13 != 0) {
        // 0x8004AD08: nop
    
            goto L_8004AD3C;
    }
    // 0x8004AD08: nop

    // 0x8004AD0C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004AD10: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004AD14: nop

    // 0x8004AD18: lbu         $a0, 0x8($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X8);
    // 0x8004AD1C: jal         0x80060E24
    // 0x8004AD20: nop

    func_80060E24(rdram, ctx);
        goto after_37;
    // 0x8004AD20: nop

    after_37:
    // 0x8004AD24: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004AD28: lw          $a1, 0xE64($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XE64);
    // 0x8004AD2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004AD30: jal         0x80060ACC
    // 0x8004AD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060ACC(rdram, ctx);
        goto after_38;
    // 0x8004AD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8004AD38: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
L_8004AD3C:
    // 0x8004AD3C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AD40: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004AD44: addiu       $at, $zero, 0x64D
    ctx->r1 = ADD32(0, 0X64D);
    // 0x8004AD48: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x8004AD4C: nop

    // 0x8004AD50: bne         $t0, $at, L_8004ADB4
    if (ctx->r8 != ctx->r1) {
        // 0x8004AD54: nop
    
            goto L_8004ADB4;
    }
    // 0x8004AD54: nop

    // 0x8004AD58: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004AD5C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004AD60: nop

    // 0x8004AD64: lbu         $a0, 0x8($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X8);
    // 0x8004AD68: jal         0x80060E24
    // 0x8004AD6C: nop

    func_80060E24(rdram, ctx);
        goto after_39;
    // 0x8004AD6C: nop

    after_39:
    // 0x8004AD70: bne         $v0, $zero, L_8004ADB4
    if (ctx->r2 != 0) {
        // 0x8004AD74: nop
    
            goto L_8004ADB4;
    }
    // 0x8004AD74: nop

    // 0x8004AD78: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x8004AD7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004AD80: sh          $t6, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r14;
    // 0x8004AD84: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    // 0x8004AD88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004AD8C: sh          $t7, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r15;
    // 0x8004AD90: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8004AD94: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8004AD98: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8004AD9C: nop

    // 0x8004ADA0: ori         $t4, $t9, 0x40
    ctx->r12 = ctx->r25 | 0X40;
    // 0x8004ADA4: sh          $t4, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r12;
    // 0x8004ADA8: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004ADAC: jal         0x800499B0
    // 0x8004ADB0: nop

    func_800499B0(rdram, ctx);
        goto after_40;
    // 0x8004ADB0: nop

    after_40:
L_8004ADB4:
    // 0x8004ADB4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004ADB8: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004ADBC: nop

    // 0x8004ADC0: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004ADC4: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004ADC8: andi        $t0, $t2, 0x1
    ctx->r8 = ctx->r10 & 0X1;
    // 0x8004ADCC: bne         $t0, $zero, L_8004ADDC
    if (ctx->r8 != 0) {
        // 0x8004ADD0: andi        $t1, $t3, 0x0
        ctx->r9 = ctx->r11 & 0X0;
            goto L_8004ADDC;
    }
    // 0x8004ADD0: andi        $t1, $t3, 0x0
    ctx->r9 = ctx->r11 & 0X0;
    // 0x8004ADD4: beq         $t1, $zero, L_8004AE44
    if (ctx->r9 == 0) {
        // 0x8004ADD8: nop
    
            goto L_8004AE44;
    }
    // 0x8004ADD8: nop

L_8004ADDC:
    // 0x8004ADDC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004ADE0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004ADE4: nop

    // 0x8004ADE8: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8004ADEC: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x8004ADF0: andi        $t8, $t4, 0x2
    ctx->r24 = ctx->r12 & 0X2;
    // 0x8004ADF4: bne         $t8, $zero, L_8004AE04
    if (ctx->r24 != 0) {
        // 0x8004ADF8: andi        $t9, $t5, 0x0
        ctx->r25 = ctx->r13 & 0X0;
            goto L_8004AE04;
    }
    // 0x8004ADF8: andi        $t9, $t5, 0x0
    ctx->r25 = ctx->r13 & 0X0;
    // 0x8004ADFC: beq         $t9, $zero, L_8004AE10
    if (ctx->r25 == 0) {
        // 0x8004AE00: nop
    
            goto L_8004AE10;
    }
    // 0x8004AE00: nop

L_8004AE04:
    // 0x8004AE04: addiu       $t7, $zero, 0x6F1
    ctx->r15 = ADD32(0, 0X6F1);
    // 0x8004AE08: b           L_8004AE18
    // 0x8004AE0C: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
        goto L_8004AE18;
    // 0x8004AE0C: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
L_8004AE10:
    // 0x8004AE10: addiu       $t2, $zero, 0xFD2
    ctx->r10 = ADD32(0, 0XFD2);
    // 0x8004AE14: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
L_8004AE18:
    // 0x8004AE18: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AE1C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004AE20: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004AE24: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8004AE28: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004AE2C: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x8004AE30: lui         $at, 0xFDFF
    ctx->r1 = S32(0XFDFF << 16);
    // 0x8004AE34: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004AE38: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004AE3C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004AE40: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_8004AE44:
    // 0x8004AE44: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004AE48: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004AE4C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004AE50: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8004AE54: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004AE58: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8004AE5C: bne         $t2, $zero, L_8004AE6C
    if (ctx->r10 != 0) {
        // 0x8004AE60: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_8004AE6C;
    }
    // 0x8004AE60: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x8004AE64: beq         $t3, $zero, L_8004AE80
    if (ctx->r11 == 0) {
        // 0x8004AE68: nop
    
            goto L_8004AE80;
    }
    // 0x8004AE68: nop

L_8004AE6C:
    // 0x8004AE6C: lh          $t5, 0x72($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X72);
    // 0x8004AE70: addiu       $at, $zero, 0x6F1
    ctx->r1 = ADD32(0, 0X6F1);
    // 0x8004AE74: beq         $t5, $at, L_8004AE80
    if (ctx->r13 == ctx->r1) {
        // 0x8004AE78: nop
    
            goto L_8004AE80;
    }
    // 0x8004AE78: nop

    // 0x8004AE7C: sh          $zero, 0x72($sp)
    MEM_H(0X72, ctx->r29) = 0;
L_8004AE80:
    // 0x8004AE80: lh          $t0, 0x72($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X72);
    // 0x8004AE84: nop

    // 0x8004AE88: beq         $t0, $zero, L_8004AEAC
    if (ctx->r8 == 0) {
        // 0x8004AE8C: nop
    
            goto L_8004AEAC;
    }
    // 0x8004AE8C: nop

    // 0x8004AE90: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004AE94: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8004AE98: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x8004AE9C: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x8004AEA0: lh          $a0, 0x72($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X72);
    // 0x8004AEA4: jal         0x80061990
    // 0x8004AEA8: nop

    func_80061990(rdram, ctx);
        goto after_41;
    // 0x8004AEA8: nop

    after_41:
L_8004AEAC:
    // 0x8004AEAC: lh          $t1, 0x72($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X72);
    // 0x8004AEB0: addiu       $at, $zero, 0x4AF
    ctx->r1 = ADD32(0, 0X4AF);
    // 0x8004AEB4: bne         $t1, $at, L_8004AEE0
    if (ctx->r9 != ctx->r1) {
        // 0x8004AEB8: nop
    
            goto L_8004AEE0;
    }
    // 0x8004AEB8: nop

    // 0x8004AEBC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004AEC0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004AEC4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004AEC8: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8004AECC: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x8004AED0: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x8004AED4: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8004AED8: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8004AEDC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_8004AEE0:
    // 0x8004AEE0: lh          $t7, 0x72($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X72);
    // 0x8004AEE4: nop

    // 0x8004AEE8: bne         $t7, $zero, L_8004AB7C
    if (ctx->r15 != 0) {
        // 0x8004AEEC: nop
    
            goto L_8004AB7C;
    }
    // 0x8004AEEC: nop

    // 0x8004AEF0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004AEF4: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004AEF8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8004AEFC: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004AF00: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004AF04: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x8004AF08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004AF0C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004AF10: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8004AF14: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8004AF18: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AF1C: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004AF20: addiu       $at, $zero, 0x62A
    ctx->r1 = ADD32(0, 0X62A);
    // 0x8004AF24: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x8004AF28: nop

    // 0x8004AF2C: beq         $t8, $at, L_8004AF40
    if (ctx->r24 == ctx->r1) {
        // 0x8004AF30: nop
    
            goto L_8004AF40;
    }
    // 0x8004AF30: nop

    // 0x8004AF34: addiu       $at, $zero, 0x62D
    ctx->r1 = ADD32(0, 0X62D);
    // 0x8004AF38: bne         $t8, $at, L_8004AFA0
    if (ctx->r24 != ctx->r1) {
        // 0x8004AF3C: nop
    
            goto L_8004AFA0;
    }
    // 0x8004AF3C: nop

L_8004AF40:
    // 0x8004AF40: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004AF44: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004AF48: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004AF4C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004AF50: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004AF54: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8004AF58: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x8004AF5C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8004AF60: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8004AF64: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004AF68: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004AF6C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8004AF70: sw          $t4, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r12;
    // 0x8004AF74: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004AF78: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004AF7C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004AF80: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004AF84: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004AF88: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004AF8C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004AF90: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004AF94: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8004AF98: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8004AF9C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_8004AFA0:
    // 0x8004AFA0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AFA4: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004AFA8: addiu       $at, $zero, 0x624
    ctx->r1 = ADD32(0, 0X624);
    // 0x8004AFAC: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x8004AFB0: nop

    // 0x8004AFB4: beq         $t0, $at, L_8004AFC8
    if (ctx->r8 == ctx->r1) {
        // 0x8004AFB8: nop
    
            goto L_8004AFC8;
    }
    // 0x8004AFB8: nop

    // 0x8004AFBC: addiu       $at, $zero, 0x628
    ctx->r1 = ADD32(0, 0X628);
    // 0x8004AFC0: bne         $t0, $at, L_8004B028
    if (ctx->r8 != ctx->r1) {
        // 0x8004AFC4: nop
    
            goto L_8004B028;
    }
    // 0x8004AFC4: nop

L_8004AFC8:
    // 0x8004AFC8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004AFCC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004AFD0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004AFD4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8004AFD8: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8004AFDC: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x8004AFE0: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8004AFE4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004AFE8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8004AFEC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004AFF0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004AFF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004AFF8: sw          $t6, 0xB8($t7)
    MEM_W(0XB8, ctx->r15) = ctx->r14;
    // 0x8004AFFC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B000: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B004: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004B008: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004B00C: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004B010: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x8004B014: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004B018: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B01C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004B020: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8004B024: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_8004B028:
    // 0x8004B028: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B02C: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004B030: addiu       $at, $zero, 0x62F
    ctx->r1 = ADD32(0, 0X62F);
    // 0x8004B034: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x8004B038: nop

    // 0x8004B03C: beq         $t8, $at, L_8004B050
    if (ctx->r24 == ctx->r1) {
        // 0x8004B040: nop
    
            goto L_8004B050;
    }
    // 0x8004B040: nop

    // 0x8004B044: addiu       $at, $zero, 0x632
    ctx->r1 = ADD32(0, 0X632);
    // 0x8004B048: bne         $t8, $at, L_8004B0B0
    if (ctx->r24 != ctx->r1) {
        // 0x8004B04C: nop
    
            goto L_8004B0B0;
    }
    // 0x8004B04C: nop

L_8004B050:
    // 0x8004B050: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004B054: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004B058: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004B05C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004B060: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004B064: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8004B068: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x8004B06C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8004B070: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8004B074: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004B078: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004B07C: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x8004B080: sw          $t4, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r12;
    // 0x8004B084: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B088: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B08C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004B090: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004B094: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004B098: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004B09C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004B0A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B0A4: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8004B0A8: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8004B0AC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_8004B0B0:
    // 0x8004B0B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B0B4: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004B0B8: addiu       $at, $zero, 0x634
    ctx->r1 = ADD32(0, 0X634);
    // 0x8004B0BC: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x8004B0C0: nop

    // 0x8004B0C4: beq         $t0, $at, L_8004B0D8
    if (ctx->r8 == ctx->r1) {
        // 0x8004B0C8: nop
    
            goto L_8004B0D8;
    }
    // 0x8004B0C8: nop

    // 0x8004B0CC: addiu       $at, $zero, 0x637
    ctx->r1 = ADD32(0, 0X637);
    // 0x8004B0D0: bne         $t0, $at, L_8004B138
    if (ctx->r8 != ctx->r1) {
        // 0x8004B0D4: nop
    
            goto L_8004B138;
    }
    // 0x8004B0D4: nop

L_8004B0D8:
    // 0x8004B0D8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B0DC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004B0E0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004B0E4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8004B0E8: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8004B0EC: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x8004B0F0: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8004B0F4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004B0F8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8004B0FC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004B100: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004B104: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8004B108: sw          $t6, 0xB8($t7)
    MEM_W(0XB8, ctx->r15) = ctx->r14;
    // 0x8004B10C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B110: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B114: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004B118: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004B11C: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004B120: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x8004B124: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004B128: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B12C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004B130: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8004B134: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_8004B138:
    // 0x8004B138: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B13C: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004B140: addiu       $at, $zero, 0x639
    ctx->r1 = ADD32(0, 0X639);
    // 0x8004B144: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x8004B148: nop

    // 0x8004B14C: beq         $t8, $at, L_8004B160
    if (ctx->r24 == ctx->r1) {
        // 0x8004B150: nop
    
            goto L_8004B160;
    }
    // 0x8004B150: nop

    // 0x8004B154: addiu       $at, $zero, 0x63D
    ctx->r1 = ADD32(0, 0X63D);
    // 0x8004B158: bne         $t8, $at, L_8004B1C0
    if (ctx->r24 != ctx->r1) {
        // 0x8004B15C: nop
    
            goto L_8004B1C0;
    }
    // 0x8004B15C: nop

L_8004B160:
    // 0x8004B160: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004B164: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004B168: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004B16C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004B170: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004B174: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8004B178: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x8004B17C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8004B180: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8004B184: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004B188: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004B18C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8004B190: sw          $t4, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r12;
    // 0x8004B194: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B198: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B19C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004B1A0: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004B1A4: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004B1A8: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004B1AC: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004B1B0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B1B4: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8004B1B8: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8004B1BC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_8004B1C0:
    // 0x8004B1C0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B1C4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004B1C8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004B1CC: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004B1D0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004B1D4: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8004B1D8: bne         $t4, $zero, L_8004AB2C
    if (ctx->r12 != 0) {
        // 0x8004B1DC: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_8004AB2C;
    }
    // 0x8004B1DC: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004B1E0: bne         $t5, $zero, L_8004AB2C
    if (ctx->r13 != 0) {
        // 0x8004B1E4: nop
    
            goto L_8004AB2C;
    }
    // 0x8004B1E4: nop

    // 0x8004B1E8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004B1EC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004B1F0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004B1F4: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8004B1F8: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004B1FC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8004B200: bne         $t2, $zero, L_8004B26C
    if (ctx->r10 != 0) {
        // 0x8004B204: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_8004B26C;
    }
    // 0x8004B204: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8004B208: bne         $t3, $zero, L_8004B26C
    if (ctx->r11 != 0) {
        // 0x8004B20C: nop
    
            goto L_8004B26C;
    }
    // 0x8004B20C: nop

    // 0x8004B210: jal         0x80031AC8
    // 0x8004B214: nop

    func_80031AC8(rdram, ctx);
        goto after_42;
    // 0x8004B214: nop

    after_42:
    // 0x8004B218: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004B21C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8004B220: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B224: beq         $t9, $at, L_8004B264
    if (ctx->r25 == ctx->r1) {
        // 0x8004B228: nop
    
            goto L_8004B264;
    }
    // 0x8004B228: nop

    // 0x8004B22C: beq         $t9, $zero, L_8004B264
    if (ctx->r25 == 0) {
        // 0x8004B230: nop
    
            goto L_8004B264;
    }
    // 0x8004B230: nop

L_8004B234:
    // 0x8004B234: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B238: jal         0x800499B0
    // 0x8004B23C: nop

    func_800499B0(rdram, ctx);
        goto after_43;
    // 0x8004B23C: nop

    after_43:
    // 0x8004B240: jal         0x80031AC8
    // 0x8004B244: nop

    func_80031AC8(rdram, ctx);
        goto after_44;
    // 0x8004B244: nop

    after_44:
    // 0x8004B248: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004B24C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8004B250: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B254: beq         $t0, $at, L_8004B264
    if (ctx->r8 == ctx->r1) {
        // 0x8004B258: nop
    
            goto L_8004B264;
    }
    // 0x8004B258: nop

    // 0x8004B25C: bne         $t0, $zero, L_8004B234
    if (ctx->r8 != 0) {
        // 0x8004B260: nop
    
            goto L_8004B234;
    }
    // 0x8004B260: nop

L_8004B264:
    // 0x8004B264: jal         0x80031B6C
    // 0x8004B268: nop

    func_80031B6C(rdram, ctx);
        goto after_45;
    // 0x8004B268: nop

    after_45:
L_8004B26C:
    // 0x8004B26C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B270: lw          $t1, 0x640($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X640);
    // 0x8004B274: addiu       $at, $zero, 0x751
    ctx->r1 = ADD32(0, 0X751);
    // 0x8004B278: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x8004B27C: nop

    // 0x8004B280: bne         $t4, $at, L_8004B2A8
    if (ctx->r12 != ctx->r1) {
        // 0x8004B284: nop
    
            goto L_8004B2A8;
    }
    // 0x8004B284: nop

    // 0x8004B288: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004B28C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004B290: addiu       $t5, $zero, 0xE10
    ctx->r13 = ADD32(0, 0XE10);
    // 0x8004B294: sh          $t5, 0x3E($t8)
    MEM_H(0X3E, ctx->r24) = ctx->r13;
    // 0x8004B298: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004B29C: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004B2A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004B2A4: sh          $t6, 0x3C($t7)
    MEM_H(0X3C, ctx->r15) = ctx->r14;
L_8004B2A8:
    // 0x8004B2A8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004B2AC: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x8004B2B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004B2B4: bne         $t2, $at, L_8004B378
    if (ctx->r10 != ctx->r1) {
        // 0x8004B2B8: nop
    
            goto L_8004B378;
    }
    // 0x8004B2B8: nop

    // 0x8004B2BC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004B2C0: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8004B2C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004B2C8: bne         $t3, $at, L_8004B378
    if (ctx->r11 != ctx->r1) {
        // 0x8004B2CC: nop
    
            goto L_8004B378;
    }
    // 0x8004B2CC: nop

    // 0x8004B2D0: jal         0x8005F064
    // 0x8004B2D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F064(rdram, ctx);
        goto after_46;
    // 0x8004B2D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_46:
    // 0x8004B2D8: bne         $v0, $zero, L_8004B334
    if (ctx->r2 != 0) {
        // 0x8004B2DC: nop
    
            goto L_8004B334;
    }
    // 0x8004B2DC: nop

    // 0x8004B2E0: addiu       $t9, $zero, 0x38
    ctx->r25 = ADD32(0, 0X38);
    // 0x8004B2E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004B2E8: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
    // 0x8004B2EC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004B2F0: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8004B2F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B2F8: ori         $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 | 0X8000;
    // 0x8004B2FC: sh          $t1, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r9;
    // 0x8004B300: jal         0x80031914
    // 0x8004B304: nop

    func_80031914(rdram, ctx);
        goto after_47;
    // 0x8004B304: nop

    after_47:
    // 0x8004B308: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004B30C: lw          $a0, 0x7260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7260);
    // 0x8004B310: jal         0x800BCB10
    // 0x8004B314: nop

    func_800BCB10(rdram, ctx);
        goto after_48;
    // 0x8004B314: nop

    after_48:
L_8004B318:
    // 0x8004B318: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B31C: jal         0x800499B0
    // 0x8004B320: nop

    func_800499B0(rdram, ctx);
        goto after_49;
    // 0x8004B320: nop

    after_49:
    // 0x8004B324: b           L_8004B318
    // 0x8004B328: nop

        goto L_8004B318;
    // 0x8004B328: nop

    // 0x8004B32C: b           L_8004B378
    // 0x8004B330: nop

        goto L_8004B378;
    // 0x8004B330: nop

L_8004B334:
    // 0x8004B334: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8004B338: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B33C: sh          $t4, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r12;
    // 0x8004B340: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8004B344: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B348: sh          $t5, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r13;
    // 0x8004B34C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004B350: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B354: sb          $t8, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r24;
    // 0x8004B358: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8004B35C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B360: sh          $t6, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r14;
    // 0x8004B364: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8004B368: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B36C: sw          $t7, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r15;
    // 0x8004B370: jal         0x80031914
    // 0x8004B374: nop

    func_80031914(rdram, ctx);
        goto after_50;
    // 0x8004B374: nop

    after_50:
L_8004B378:
    // 0x8004B378: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B37C: lw          $t2, 0x640($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X640);
    // 0x8004B380: addiu       $at, $zero, 0x5BF
    ctx->r1 = ADD32(0, 0X5BF);
    // 0x8004B384: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8004B388: nop

    // 0x8004B38C: beq         $t3, $at, L_8004B3C4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B390: nop
    
            goto L_8004B3C4;
    }
    // 0x8004B390: nop

    // 0x8004B394: addiu       $at, $zero, 0x629
    ctx->r1 = ADD32(0, 0X629);
    // 0x8004B398: beq         $t3, $at, L_8004B3C4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B39C: nop
    
            goto L_8004B3C4;
    }
    // 0x8004B39C: nop

    // 0x8004B3A0: addiu       $at, $zero, 0x62E
    ctx->r1 = ADD32(0, 0X62E);
    // 0x8004B3A4: beq         $t3, $at, L_8004B3C4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B3A8: nop
    
            goto L_8004B3C4;
    }
    // 0x8004B3A8: nop

    // 0x8004B3AC: addiu       $at, $zero, 0x633
    ctx->r1 = ADD32(0, 0X633);
    // 0x8004B3B0: beq         $t3, $at, L_8004B3C4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B3B4: nop
    
            goto L_8004B3C4;
    }
    // 0x8004B3B4: nop

    // 0x8004B3B8: addiu       $at, $zero, 0x638
    ctx->r1 = ADD32(0, 0X638);
    // 0x8004B3BC: bne         $t3, $at, L_8004B49C
    if (ctx->r11 != ctx->r1) {
        // 0x8004B3C0: nop
    
            goto L_8004B49C;
    }
    // 0x8004B3C0: nop

L_8004B3C4:
    // 0x8004B3C4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8004B3C8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8004B3CC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8004B3D0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004B3D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004B3D8: nop

    // 0x8004B3DC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8004B3E0: jal         0x80016620
    // 0x8004B3E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80016620(rdram, ctx);
        goto after_51;
    // 0x8004B3E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_51:
    // 0x8004B3E8: jal         0x80016138
    // 0x8004B3EC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_52;
    // 0x8004B3EC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_52:
    // 0x8004B3F0: beq         $v0, $zero, L_8004B414
    if (ctx->r2 == 0) {
        // 0x8004B3F4: nop
    
            goto L_8004B414;
    }
    // 0x8004B3F4: nop

L_8004B3F8:
    // 0x8004B3F8: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B3FC: jal         0x800499B0
    // 0x8004B400: nop

    func_800499B0(rdram, ctx);
        goto after_53;
    // 0x8004B400: nop

    after_53:
    // 0x8004B404: jal         0x80016138
    // 0x8004B408: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_54;
    // 0x8004B408: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_54:
    // 0x8004B40C: bne         $v0, $zero, L_8004B3F8
    if (ctx->r2 != 0) {
        // 0x8004B410: nop
    
            goto L_8004B3F8;
    }
    // 0x8004B410: nop

L_8004B414:
    // 0x8004B414: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
L_8004B418:
    // 0x8004B418: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B41C: jal         0x800499B0
    // 0x8004B420: nop

    func_800499B0(rdram, ctx);
        goto after_55;
    // 0x8004B420: nop

    after_55:
    // 0x8004B424: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8004B428: nop

    // 0x8004B42C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8004B430: slti        $at, $t0, 0x78
    ctx->r1 = SIGNED(ctx->r8) < 0X78 ? 1 : 0;
    // 0x8004B434: bne         $at, $zero, L_8004B418
    if (ctx->r1 != 0) {
        // 0x8004B438: sw          $t0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r8;
            goto L_8004B418;
    }
    // 0x8004B438: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8004B43C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8004B440: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B444: sh          $t1, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r9;
    // 0x8004B448: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004B44C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B450: sh          $t4, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r12;
    // 0x8004B454: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B458: sb          $zero, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = 0;
    // 0x8004B45C: addiu       $t5, $zero, 0x1F
    ctx->r13 = ADD32(0, 0X1F);
    // 0x8004B460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B464: sh          $t5, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r13;
    // 0x8004B468: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8004B46C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B470: sw          $t8, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r24;
    // 0x8004B474: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004B478: lw          $t6, 0x718C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X718C);
    // 0x8004B47C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B480: addiu       $t7, $t6, -0x64
    ctx->r15 = ADD32(ctx->r14, -0X64);
    // 0x8004B484: sw          $t7, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r15;
L_8004B488:
    // 0x8004B488: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B48C: jal         0x800499B0
    // 0x8004B490: nop

    func_800499B0(rdram, ctx);
        goto after_56;
    // 0x8004B490: nop

    after_56:
    // 0x8004B494: b           L_8004B488
    // 0x8004B498: nop

        goto L_8004B488;
    // 0x8004B498: nop

L_8004B49C:
    // 0x8004B49C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B4A0: lw          $t2, 0x640($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X640);
    // 0x8004B4A4: addiu       $at, $zero, 0x6CB
    ctx->r1 = ADD32(0, 0X6CB);
    // 0x8004B4A8: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8004B4AC: nop

    // 0x8004B4B0: beq         $t3, $at, L_8004B4E4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B4B4: nop
    
            goto L_8004B4E4;
    }
    // 0x8004B4B4: nop

    // 0x8004B4B8: addiu       $at, $zero, 0x553
    ctx->r1 = ADD32(0, 0X553);
    // 0x8004B4BC: bne         $t3, $at, L_8004B568
    if (ctx->r11 != ctx->r1) {
        // 0x8004B4C0: nop
    
            goto L_8004B568;
    }
    // 0x8004B4C0: nop

    // 0x8004B4C4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004B4C8: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004B4CC: nop

    // 0x8004B4D0: lbu         $a0, 0x8($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X8);
    // 0x8004B4D4: jal         0x80060E24
    // 0x8004B4D8: nop

    func_80060E24(rdram, ctx);
        goto after_57;
    // 0x8004B4D8: nop

    after_57:
    // 0x8004B4DC: bne         $v0, $zero, L_8004B568
    if (ctx->r2 != 0) {
        // 0x8004B4E0: nop
    
            goto L_8004B568;
    }
    // 0x8004B4E0: nop

L_8004B4E4:
    // 0x8004B4E4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8004B4E8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8004B4EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8004B4F0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004B4F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004B4F8: nop

    // 0x8004B4FC: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8004B500: jal         0x80016620
    // 0x8004B504: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80016620(rdram, ctx);
        goto after_58;
    // 0x8004B504: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_58:
    // 0x8004B508: jal         0x80016138
    // 0x8004B50C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_59;
    // 0x8004B50C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_59:
    // 0x8004B510: beq         $v0, $zero, L_8004B534
    if (ctx->r2 == 0) {
        // 0x8004B514: nop
    
            goto L_8004B534;
    }
    // 0x8004B514: nop

L_8004B518:
    // 0x8004B518: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B51C: jal         0x800499B0
    // 0x8004B520: nop

    func_800499B0(rdram, ctx);
        goto after_60;
    // 0x8004B520: nop

    after_60:
    // 0x8004B524: jal         0x80016138
    // 0x8004B528: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_61;
    // 0x8004B528: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_61:
    // 0x8004B52C: bne         $v0, $zero, L_8004B518
    if (ctx->r2 != 0) {
        // 0x8004B530: nop
    
            goto L_8004B518;
    }
    // 0x8004B530: nop

L_8004B534:
    // 0x8004B534: addiu       $t0, $zero, 0x36
    ctx->r8 = ADD32(0, 0X36);
    // 0x8004B538: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004B53C: sh          $t0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r8;
    // 0x8004B540: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004B544: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8004B548: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B54C: ori         $t4, $t1, 0x8000
    ctx->r12 = ctx->r9 | 0X8000;
    // 0x8004B550: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
L_8004B554:
    // 0x8004B554: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B558: jal         0x800499B0
    // 0x8004B55C: nop

    func_800499B0(rdram, ctx);
        goto after_62;
    // 0x8004B55C: nop

    after_62:
    // 0x8004B560: b           L_8004B554
    // 0x8004B564: nop

        goto L_8004B554;
    // 0x8004B564: nop

L_8004B568:
    // 0x8004B568: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004B56C: lw          $t5, 0x640($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X640);
    // 0x8004B570: addiu       $at, $zero, 0x6FD
    ctx->r1 = ADD32(0, 0X6FD);
    // 0x8004B574: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8004B578: nop

    // 0x8004B57C: bne         $t8, $at, L_8004B5B8
    if (ctx->r24 != ctx->r1) {
        // 0x8004B580: nop
    
            goto L_8004B5B8;
    }
    // 0x8004B580: nop

    // 0x8004B584: addiu       $t6, $zero, 0x44
    ctx->r14 = ADD32(0, 0X44);
    // 0x8004B588: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004B58C: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
    // 0x8004B590: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004B594: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x8004B598: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B59C: ori         $t2, $t7, 0x8000
    ctx->r10 = ctx->r15 | 0X8000;
    // 0x8004B5A0: sh          $t2, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r10;
L_8004B5A4:
    // 0x8004B5A4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B5A8: jal         0x800499B0
    // 0x8004B5AC: nop

    func_800499B0(rdram, ctx);
        goto after_63;
    // 0x8004B5AC: nop

    after_63:
    // 0x8004B5B0: b           L_8004B5A4
    // 0x8004B5B4: nop

        goto L_8004B5A4;
    // 0x8004B5B4: nop

L_8004B5B8:
    // 0x8004B5B8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B5BC: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004B5C0: addiu       $at, $zero, 0x6DD
    ctx->r1 = ADD32(0, 0X6DD);
    // 0x8004B5C4: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8004B5C8: nop

    // 0x8004B5CC: bne         $t9, $at, L_8004B634
    if (ctx->r25 != ctx->r1) {
        // 0x8004B5D0: nop
    
            goto L_8004B634;
    }
    // 0x8004B5D0: nop

    // 0x8004B5D4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004B5D8: lh          $t0, 0x1B48($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X1B48);
    // 0x8004B5DC: nop

    // 0x8004B5E0: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8004B5E4: bne         $at, $zero, L_8004B604
    if (ctx->r1 != 0) {
        // 0x8004B5E8: nop
    
            goto L_8004B604;
    }
    // 0x8004B5E8: nop

    // 0x8004B5EC: jal         0x80029C8C
    // 0x8004B5F0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_80029C8C(rdram, ctx);
        goto after_64;
    // 0x8004B5F0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_64:
    // 0x8004B5F4: jal         0x80029ED8
    // 0x8004B5F8: nop

    func_80029ED8(rdram, ctx);
        goto after_65;
    // 0x8004B5F8: nop

    after_65:
    // 0x8004B5FC: b           L_8004B634
    // 0x8004B600: nop

        goto L_8004B634;
    // 0x8004B600: nop

L_8004B604:
    // 0x8004B604: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B608: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004B60C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004B610: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B614: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004B618: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8004B61C: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x8004B620: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x8004B624: lw          $a3, 0xC($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XC);
    // 0x8004B628: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8004B62C: jal         0x800298A4
    // 0x8004B630: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800298A4(rdram, ctx);
        goto after_66;
    // 0x8004B630: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_66:
L_8004B634:
    // 0x8004B634: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004B638: lw          $t4, 0x640($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X640);
    // 0x8004B63C: addiu       $at, $zero, 0x5C0
    ctx->r1 = ADD32(0, 0X5C0);
    // 0x8004B640: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8004B644: nop

    // 0x8004B648: bne         $t5, $at, L_8004B684
    if (ctx->r13 != ctx->r1) {
        // 0x8004B64C: nop
    
            goto L_8004B684;
    }
    // 0x8004B64C: nop

    // 0x8004B650: addiu       $t8, $zero, 0x29
    ctx->r24 = ADD32(0, 0X29);
    // 0x8004B654: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004B658: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x8004B65C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004B660: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8004B664: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B668: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8004B66C: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
L_8004B670:
    // 0x8004B670: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B674: jal         0x800499B0
    // 0x8004B678: nop

    func_800499B0(rdram, ctx);
        goto after_67;
    // 0x8004B678: nop

    after_67:
    // 0x8004B67C: b           L_8004B670
    // 0x8004B680: nop

        goto L_8004B670;
    // 0x8004B680: nop

L_8004B684:
    // 0x8004B684: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B688: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B68C: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B690: lh          $a1, 0x4A($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X4A);
    // 0x8004B694: nop

    // 0x8004B698: andi        $t3, $a1, 0x1FFF
    ctx->r11 = ctx->r5 & 0X1FFF;
    // 0x8004B69C: jal         0x8005218C
    // 0x8004B6A0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8005218C(rdram, ctx);
        goto after_68;
    // 0x8004B6A0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_68:
    // 0x8004B6A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B6A8: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
    // 0x8004B6AC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004B6B0: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8004B6B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004B6B8: bne         $t9, $at, L_8004B6E8
    if (ctx->r25 != ctx->r1) {
        // 0x8004B6BC: nop
    
            goto L_8004B6E8;
    }
    // 0x8004B6BC: nop

    // 0x8004B6C0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004B6C4: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004B6C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004B6CC: bne         $t0, $at, L_8004B6E8
    if (ctx->r8 != ctx->r1) {
        // 0x8004B6D0: nop
    
            goto L_8004B6E8;
    }
    // 0x8004B6D0: nop

L_8004B6D4:
    // 0x8004B6D4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B6D8: jal         0x800499B0
    // 0x8004B6DC: nop

    func_800499B0(rdram, ctx);
        goto after_69;
    // 0x8004B6DC: nop

    after_69:
    // 0x8004B6E0: b           L_8004B6D4
    // 0x8004B6E4: nop

        goto L_8004B6D4;
    // 0x8004B6E4: nop

L_8004B6E8:
    // 0x8004B6E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B6EC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004B6F0: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004B6F4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8004B6F8: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004B6FC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8004B700: bne         $t8, $zero, L_8004B71C
    if (ctx->r24 != 0) {
        // 0x8004B704: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_8004B71C;
    }
    // 0x8004B704: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x8004B708: bne         $t9, $zero, L_8004B71C
    if (ctx->r25 != 0) {
        // 0x8004B70C: nop
    
            goto L_8004B71C;
    }
    // 0x8004B70C: nop

    // 0x8004B710: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B714: b           L_8004B74C
    // 0x8004B718: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
        goto L_8004B74C;
    // 0x8004B718: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
L_8004B71C:
    // 0x8004B71C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004B720: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004B724: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8004B728: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8004B72C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B730: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004B734: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x8004B738: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004B73C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8004B740: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8004B744: b           L_8004A180
    // 0x8004B748: nop

        goto L_8004A180;
    // 0x8004B748: nop

L_8004B74C:
    // 0x8004B74C: b           L_8004A438
    // 0x8004B750: nop

        goto L_8004A438;
    // 0x8004B750: nop

    // 0x8004B754: b           L_8004B75C
    // 0x8004B758: nop

        goto L_8004B75C;
    // 0x8004B758: nop

L_8004B75C:
    // 0x8004B75C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004B760: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8004B764: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8004B768: jr          $ra
    // 0x8004B76C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x8004B76C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_800676B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800676B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800676B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800676B8: nop

    // 0x800676BC: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800676C0: nop

    // 0x800676C4: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x800676C8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800676CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800676D0: beq         $v0, $zero, L_800676EC
    if (ctx->r2 == 0) {
        // 0x800676D4: nop
    
            goto L_800676EC;
    }
    // 0x800676D4: nop

    // 0x800676D8: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800676DC: nop

    // 0x800676E0: slti        $t8, $v0, 0xC8
    ctx->r24 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x800676E4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800676E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800676EC:
    // 0x800676EC: jr          $ra
    // 0x800676F0: nop

    return;
    // 0x800676F0: nop

    // 0x800676F4: jr          $ra
    // 0x800676F8: nop

    return;
    // 0x800676F8: nop

    // 0x800676FC: jr          $ra
    // 0x80067700: nop

    return;
    // 0x80067700: nop

;}
RECOMP_FUNC void func_8006322C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006322C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063234: jal         0x80061488
    // 0x80063238: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063238: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    after_0:
    // 0x8006323C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063240: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063244: b           L_80063254
    // 0x80063248: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063254;
    // 0x80063248: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006324C: b           L_80063254
    // 0x80063250: nop

        goto L_80063254;
    // 0x80063250: nop

L_80063254:
    // 0x80063254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006325C: jr          $ra
    // 0x80063260: nop

    return;
    // 0x80063260: nop

;}
RECOMP_FUNC void func_80073DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073DB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073DB4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073DB8: nop

    // 0x80073DBC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073DC0: nop

    // 0x80073DC4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073DC8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073DCC: jr          $ra
    // 0x80073DD0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073DD0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073DD4: jr          $ra
    // 0x80073DD8: nop

    return;
    // 0x80073DD8: nop

    // 0x80073DDC: jr          $ra
    // 0x80073DE0: nop

    return;
    // 0x80073DE0: nop

;}
