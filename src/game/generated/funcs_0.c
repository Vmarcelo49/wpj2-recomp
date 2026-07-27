#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800AD774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD774: sltiu       $at, $a0, 0x8
    ctx->r1 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x800AD778: beq         $at, $zero, L_800AD7DC
    if (ctx->r1 == 0) {
        // 0x800AD77C: nop
    
            goto L_800AD7DC;
    }
    // 0x800AD77C: nop

    // 0x800AD780: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800AD784: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AD788: addu        $at, $at, $t6
    gpr jr_addend_800AD794 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AD78C: lw          $t6, -0x720($at)
    ctx->r14 = ADD32(ctx->r1, -0X720);
    // 0x800AD790: nop

    // 0x800AD794: jr          $t6
    // 0x800AD798: nop

    switch (jr_addend_800AD794 >> 2) {
        case 0: goto L_800AD79C; break;
        case 1: goto L_800AD7A4; break;
        case 2: goto L_800AD7AC; break;
        case 3: goto L_800AD7B4; break;
        case 4: goto L_800AD7BC; break;
        case 5: goto L_800AD7C4; break;
        case 6: goto L_800AD7CC; break;
        case 7: goto L_800AD7D4; break;
        default: switch_error(__func__, 0x800AD794, 0x800EF8E0);
    }
    // 0x800AD798: nop

L_800AD79C:
    // 0x800AD79C: jr          $ra
    // 0x800AD7A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800AD7A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD7A4:
    // 0x800AD7A4: jr          $ra
    // 0x800AD7A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800AD7A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800AD7AC:
    // 0x800AD7AC: jr          $ra
    // 0x800AD7B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800AD7B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800AD7B4:
    // 0x800AD7B4: jr          $ra
    // 0x800AD7B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x800AD7B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800AD7BC:
    // 0x800AD7BC: jr          $ra
    // 0x800AD7C0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x800AD7C0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800AD7C4:
    // 0x800AD7C4: jr          $ra
    // 0x800AD7C8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x800AD7C8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_800AD7CC:
    // 0x800AD7CC: jr          $ra
    // 0x800AD7D0: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    return;
    // 0x800AD7D0: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_800AD7D4:
    // 0x800AD7D4: jr          $ra
    // 0x800AD7D8: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    return;
    // 0x800AD7D8: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_800AD7DC:
    // 0x800AD7DC: jr          $ra
    // 0x800AD7E0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x800AD7E0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8006D394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D39C: jal         0x80061488
    // 0x8006D3A0: addiu       $a0, $zero, 0x574
    ctx->r4 = ADD32(0, 0X574);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006D3A0: addiu       $a0, $zero, 0x574
    ctx->r4 = ADD32(0, 0X574);
    after_0:
    // 0x8006D3A4: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x8006D3A8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006D3AC: b           L_8006D3BC
    // 0x8006D3B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D3BC;
    // 0x8006D3B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D3B4: b           L_8006D3BC
    // 0x8006D3B8: nop

        goto L_8006D3BC;
    // 0x8006D3B8: nop

L_8006D3BC:
    // 0x8006D3BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D3C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D3C4: jr          $ra
    // 0x8006D3C8: nop

    return;
    // 0x8006D3C8: nop

;}
RECOMP_FUNC void func_80070D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070DA0: jal         0x80061348
    // 0x80070DA4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070DA4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_0:
    // 0x80070DA8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070DAC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070DB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070DB4: beq         $v0, $zero, L_80070E08
    if (ctx->r2 == 0) {
        // 0x80070DB8: nop
    
            goto L_80070E08;
    }
    // 0x80070DB8: nop

    // 0x80070DBC: jal         0x80061348
    // 0x80070DC0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070DC0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070DC4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070DC8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070DCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070DD0: beq         $v0, $zero, L_80070E08
    if (ctx->r2 == 0) {
        // 0x80070DD4: nop
    
            goto L_80070E08;
    }
    // 0x80070DD4: nop

    // 0x80070DD8: jal         0x80061348
    // 0x80070DDC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070DDC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070DE0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070DE4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070DE8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070DEC: beq         $v0, $zero, L_80070E08
    if (ctx->r2 == 0) {
        // 0x80070DF0: nop
    
            goto L_80070E08;
    }
    // 0x80070DF0: nop

    // 0x80070DF4: jal         0x80061348
    // 0x80070DF8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070DF8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070DFC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070E00: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070E04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070E08:
    // 0x80070E08: b           L_80070E18
    // 0x80070E0C: nop

        goto L_80070E18;
    // 0x80070E0C: nop

    // 0x80070E10: b           L_80070E18
    // 0x80070E14: nop

        goto L_80070E18;
    // 0x80070E14: nop

L_80070E18:
    // 0x80070E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070E20: jr          $ra
    // 0x80070E24: nop

    return;
    // 0x80070E24: nop

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
RECOMP_FUNC void Sys_SwapFrameBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ECCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008ECD0: sw          $a0, -0x44BC($at)
    MEM_W(-0X44BC, ctx->r1) = ctx->r4;
    // 0x8008ECD4: jr          $ra
    // 0x8008ECD8: nop

    return;
    // 0x8008ECD8: nop

    // 0x8008ECDC: jr          $ra
    // 0x8008ECE0: nop

    return;
    // 0x8008ECE0: nop

;}
RECOMP_FUNC void func_80031AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031AC8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031ACC: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x80031AD0: nop

    // 0x80031AD4: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80031AD8: beq         $at, $zero, L_80031AE8
    if (ctx->r1 == 0) {
        // 0x80031ADC: nop
    
            goto L_80031AE8;
    }
    // 0x80031ADC: nop

    // 0x80031AE0: jr          $ra
    // 0x80031AE4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    return;
    // 0x80031AE4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80031AE8:
    // 0x80031AE8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80031AEC: lh          $t7, 0x2518($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2518);
    // 0x80031AF0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80031AF4: bne         $t7, $at, L_80031B28
    if (ctx->r15 != ctx->r1) {
        // 0x80031AF8: nop
    
            goto L_80031B28;
    }
    // 0x80031AF8: nop

    // 0x80031AFC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80031B00: lh          $t8, 0x2570($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2570);
    // 0x80031B04: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80031B08: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80031B0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80031B10: lw          $t0, 0x79D0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X79D0);
    // 0x80031B14: nop

    // 0x80031B18: bne         $t0, $zero, L_80031B28
    if (ctx->r8 != 0) {
        // 0x80031B1C: nop
    
            goto L_80031B28;
    }
    // 0x80031B1C: nop

    // 0x80031B20: jr          $ra
    // 0x80031B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031B28:
    // 0x80031B28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031B2C: lwc1        $f4, 0x2530($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2530);
    // 0x80031B30: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80031B34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80031B38: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80031B3C: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80031B40: nop

    // 0x80031B44: bc1t        L_80031B54
    if (c1cs) {
        // 0x80031B48: nop
    
            goto L_80031B54;
    }
    // 0x80031B48: nop

    // 0x80031B4C: jr          $ra
    // 0x80031B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80031B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031B54:
    // 0x80031B54: jr          $ra
    // 0x80031B58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80031B58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80031B5C: jr          $ra
    // 0x80031B60: nop

    return;
    // 0x80031B60: nop

    // 0x80031B64: jr          $ra
    // 0x80031B68: nop

    return;
    // 0x80031B68: nop

;}
RECOMP_FUNC void func_8000C3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C3B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000C3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C3B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000C3BC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000C3C0: nop

    // 0x8000C3C4: bne         $t6, $zero, L_8000C3D4
    if (ctx->r14 != 0) {
        // 0x8000C3C8: nop
    
            goto L_8000C3D4;
    }
    // 0x8000C3C8: nop

    // 0x8000C3CC: b           L_8000C574
    // 0x8000C3D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C574;
    // 0x8000C3D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C3D4:
    // 0x8000C3D4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000C3D8: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8000C3DC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000C3E0: bne         $t7, $at, L_8000C3F0
    if (ctx->r15 != ctx->r1) {
        // 0x8000C3E4: nop
    
            goto L_8000C3F0;
    }
    // 0x8000C3E4: nop

    // 0x8000C3E8: b           L_8000C574
    // 0x8000C3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C574;
    // 0x8000C3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C3F0:
    // 0x8000C3F0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000C3F4: nop

    // 0x8000C3F8: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x8000C3FC: nop

    // 0x8000C400: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000C404: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C408: nop

    // 0x8000C40C: beq         $t0, $zero, L_8000C438
    if (ctx->r8 == 0) {
        // 0x8000C410: nop
    
            goto L_8000C438;
    }
    // 0x8000C410: nop

    // 0x8000C414: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000C418: nop

    // 0x8000C41C: beq         $t1, $zero, L_8000C438
    if (ctx->r9 == 0) {
        // 0x8000C420: nop
    
            goto L_8000C438;
    }
    // 0x8000C420: nop

    // 0x8000C424: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C428: nop

    // 0x8000C42C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8000C430: jal         0x8000DD94
    // 0x8000C434: nop

    func_8000DD94(rdram, ctx);
        goto after_0;
    // 0x8000C434: nop

    after_0:
L_8000C438:
    // 0x8000C438: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000C43C: lw          $a0, -0x2828($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2828);
    // 0x8000C440: jal         0x800BCCE4
    // 0x8000C444: nop

    func_800BCCE4(rdram, ctx);
        goto after_1;
    // 0x8000C444: nop

    after_1:
    // 0x8000C448: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000C44C: sw          $zero, -0x2828($at)
    MEM_W(-0X2828, ctx->r1) = 0;
    // 0x8000C450: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8000C454: lw          $t3, 0x3070($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3070);
    // 0x8000C458: nop

    // 0x8000C45C: beq         $t3, $zero, L_8000C47C
    if (ctx->r11 == 0) {
        // 0x8000C460: nop
    
            goto L_8000C47C;
    }
    // 0x8000C460: nop

    // 0x8000C464: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C468: lw          $a0, 0x3070($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3070);
    // 0x8000C46C: jal         0x800BCCE4
    // 0x8000C470: nop

    func_800BCCE4(rdram, ctx);
        goto after_2;
    // 0x8000C470: nop

    after_2:
    // 0x8000C474: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C478: sw          $zero, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = 0;
L_8000C47C:
    // 0x8000C47C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8000C480: lw          $t4, 0x3078($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3078);
    // 0x8000C484: nop

    // 0x8000C488: beq         $t4, $zero, L_8000C4A8
    if (ctx->r12 == 0) {
        // 0x8000C48C: nop
    
            goto L_8000C4A8;
    }
    // 0x8000C48C: nop

    // 0x8000C490: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C494: lw          $a0, 0x3078($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3078);
    // 0x8000C498: jal         0x800BCCE4
    // 0x8000C49C: nop

    func_800BCCE4(rdram, ctx);
        goto after_3;
    // 0x8000C49C: nop

    after_3:
    // 0x8000C4A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C4A4: sw          $zero, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = 0;
L_8000C4A8:
    // 0x8000C4A8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8000C4AC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000C4B0: lw          $t6, 0x1A0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000C4B4: nop

    // 0x8000C4B8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8000C4BC: sw          $t7, 0x1A0($t5)
    MEM_W(0X1A0, ctx->r13) = ctx->r15;
    // 0x8000C4C0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000C4C4: nop

    // 0x8000C4C8: lw          $t9, 0x1A0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A0);
    // 0x8000C4CC: nop

    // 0x8000C4D0: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x8000C4D4: sw          $t0, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = ctx->r8;
    // 0x8000C4D8: jal         0x80016264
    // 0x8000C4DC: nop

    func_80016264(rdram, ctx);
        goto after_4;
    // 0x8000C4DC: nop

    after_4:
    // 0x8000C4E0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8000C4E4: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000C4E8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8000C4EC: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8000C4F0: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8000C4F4: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x8000C4F8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000C4FC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000C500: lhu         $t6, 0x6($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X6);
    // 0x8000C504: nop

    // 0x8000C508: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x8000C50C: sh          $t7, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r15;
    // 0x8000C510: addiu       $t5, $zero, -0x2
    ctx->r13 = ADD32(0, -0X2);
    // 0x8000C514: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C518: sh          $t5, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r13;
    // 0x8000C51C: jal         0x80031728
    // 0x8000C520: nop

    func_80031728(rdram, ctx);
        goto after_5;
    // 0x8000C520: nop

    after_5:
    // 0x8000C524: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C528: nop

    // 0x8000C52C: beq         $t9, $zero, L_8000C564
    if (ctx->r25 == 0) {
        // 0x8000C530: nop
    
            goto L_8000C564;
    }
    // 0x8000C530: nop

    // 0x8000C534: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000C538: nop

    // 0x8000C53C: beq         $t0, $zero, L_8000C564
    if (ctx->r8 == 0) {
        // 0x8000C540: nop
    
            goto L_8000C564;
    }
    // 0x8000C540: nop

    // 0x8000C544: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C548: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x8000C54C: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8000C550: nop

    // 0x8000C554: lw          $t3, 0x1A0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A0);
    // 0x8000C558: nop

    // 0x8000C55C: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8000C560: sw          $t1, 0x1A0($t2)
    MEM_W(0X1A0, ctx->r10) = ctx->r9;
L_8000C564:
    // 0x8000C564: b           L_8000C574
    // 0x8000C568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C574;
    // 0x8000C568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C56C: b           L_8000C574
    // 0x8000C570: nop

        goto L_8000C574;
    // 0x8000C570: nop

L_8000C574:
    // 0x8000C574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C57C: jr          $ra
    // 0x8000C580: nop

    return;
    // 0x8000C580: nop

;}
RECOMP_FUNC void func_80072C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072C48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072C4C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072C50: nop

    // 0x80072C54: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80072C58: nop

    // 0x80072C5C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072C60: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072C64: jr          $ra
    // 0x80072C68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072C68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072C6C: jr          $ra
    // 0x80072C70: nop

    return;
    // 0x80072C70: nop

    // 0x80072C74: jr          $ra
    // 0x80072C78: nop

    return;
    // 0x80072C78: nop

;}
RECOMP_FUNC void func_80061B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061B38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061B3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061B40: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80061B44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061B48: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80061B4C: nop

    // 0x80061B50: bltz        $t6, L_80061D08
    if (SIGNED(ctx->r14) < 0) {
        // 0x80061B54: nop
    
            goto L_80061D08;
    }
    // 0x80061B54: nop

L_80061B58:
    // 0x80061B58: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x80061B5C: lui         $t9, 0x809E
    ctx->r25 = S32(0X809E << 16);
    // 0x80061B60: addiu       $t9, $t9, -0x44B4
    ctx->r25 = ADD32(ctx->r25, -0X44B4);
    // 0x80061B64: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80061B68: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80061B6C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061B70: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80061B74: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x80061B78: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80061B7C: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80061B80: jal         0x800BD1FC
    // 0x80061B84: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80061B84: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_0:
    // 0x80061B88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80061B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061B90: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80061B94: jal         0x800BD218
    // 0x80061B98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80061B98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80061B9C: lbu         $t1, 0x2C($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2C);
    // 0x80061BA0: nop

    // 0x80061BA4: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80061BA8: sb          $t2, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r10;
    // 0x80061BAC: lbu         $s0, 0x29($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X29);
    // 0x80061BB0: nop

    // 0x80061BB4: beq         $s0, $zero, L_80061BD0
    if (ctx->r16 == 0) {
        // 0x80061BB8: nop
    
            goto L_80061BD0;
    }
    // 0x80061BB8: nop

    // 0x80061BBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80061BC0: beq         $s0, $at, L_80061BF0
    if (ctx->r16 == ctx->r1) {
        // 0x80061BC4: nop
    
            goto L_80061BF0;
    }
    // 0x80061BC4: nop

    // 0x80061BC8: b           L_80061C10
    // 0x80061BCC: nop

        goto L_80061C10;
    // 0x80061BCC: nop

L_80061BD0:
    // 0x80061BD0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061BD4: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80061BD8: nop

    // 0x80061BDC: lh          $t4, 0x38($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X38);
    // 0x80061BE0: nop

    // 0x80061BE4: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    // 0x80061BE8: b           L_80061C18
    // 0x80061BEC: nop

        goto L_80061C18;
    // 0x80061BEC: nop

L_80061BF0:
    // 0x80061BF0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80061BF4: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80061BF8: nop

    // 0x80061BFC: lh          $t6, 0x3A($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X3A);
    // 0x80061C00: nop

    // 0x80061C04: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x80061C08: b           L_80061C18
    // 0x80061C0C: nop

        goto L_80061C18;
    // 0x80061C0C: nop

L_80061C10:
    // 0x80061C10: addiu       $t8, $zero, 0x3E7
    ctx->r24 = ADD32(0, 0X3E7);
    // 0x80061C14: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
L_80061C18:
    // 0x80061C18: lbu         $t9, 0x29($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X29);
    // 0x80061C1C: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80061C20: bne         $t9, $at, L_80061C48
    if (ctx->r25 != ctx->r1) {
        // 0x80061C24: nop
    
            goto L_80061C48;
    }
    // 0x80061C24: nop

    // 0x80061C28: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80061C2C: lw          $t7, 0x718C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X718C);
    // 0x80061C30: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
    // 0x80061C34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80061C38: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80061C3C: sw          $t1, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r9;
    // 0x80061C40: b           L_80061CF4
    // 0x80061C44: nop

        goto L_80061CF4;
    // 0x80061C44: nop

L_80061C48:
    // 0x80061C48: lbu         $t3, 0x29($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X29);
    // 0x80061C4C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80061C50: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80061C54: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80061C58: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80061C5C: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80061C60: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x80061C64: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80061C68: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80061C6C: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
    // 0x80061C70: lbu         $t0, 0x29($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X29);
    // 0x80061C74: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80061C78: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80061C7C: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x80061C80: lh          $t2, 0x0($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X0);
    // 0x80061C84: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x80061C88: nop

    // 0x80061C8C: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80061C90: bne         $at, $zero, L_80061CB8
    if (ctx->r1 != 0) {
        // 0x80061C94: nop
    
            goto L_80061CB8;
    }
    // 0x80061C94: nop

    // 0x80061C98: lbu         $t9, 0x29($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X29);
    // 0x80061C9C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80061CA0: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80061CA4: lh          $t6, 0x2A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A);
    // 0x80061CA8: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80061CAC: addu        $t0, $t8, $t5
    ctx->r8 = ADD32(ctx->r24, ctx->r13);
    // 0x80061CB0: b           L_80061CF4
    // 0x80061CB4: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
        goto L_80061CF4;
    // 0x80061CB4: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
L_80061CB8:
    // 0x80061CB8: lbu         $t1, 0x29($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X29);
    // 0x80061CBC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80061CC0: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80061CC4: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80061CC8: addu        $t2, $t7, $t3
    ctx->r10 = ADD32(ctx->r15, ctx->r11);
    // 0x80061CCC: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80061CD0: nop

    // 0x80061CD4: bgez        $t4, L_80061CF4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80061CD8: nop
    
            goto L_80061CF4;
    }
    // 0x80061CD8: nop

    // 0x80061CDC: lbu         $t8, 0x29($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X29);
    // 0x80061CE0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80061CE4: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80061CE8: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80061CEC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80061CF0: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
L_80061CF4:
    // 0x80061CF4: lbu         $t0, 0x2C($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2C);
    // 0x80061CF8: nop

    // 0x80061CFC: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80061D00: bne         $t1, $zero, L_80061B58
    if (ctx->r9 != 0) {
        // 0x80061D04: nop
    
            goto L_80061B58;
    }
    // 0x80061D04: nop

L_80061D08:
    // 0x80061D08: b           L_80061D10
    // 0x80061D0C: nop

        goto L_80061D10;
    // 0x80061D0C: nop

L_80061D10:
    // 0x80061D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80061D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061D18: jr          $ra
    // 0x80061D1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80061D1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80076444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007644C: jal         0x80061488
    // 0x80076450: addiu       $a0, $zero, 0x515
    ctx->r4 = ADD32(0, 0X515);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076450: addiu       $a0, $zero, 0x515
    ctx->r4 = ADD32(0, 0X515);
    after_0:
    // 0x80076454: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076458: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007645C: b           L_8007646C
    // 0x80076460: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007646C;
    // 0x80076460: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076464: b           L_8007646C
    // 0x80076468: nop

        goto L_8007646C;
    // 0x80076468: nop

L_8007646C:
    // 0x8007646C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076474: jr          $ra
    // 0x80076478: nop

    return;
    // 0x80076478: nop

;}
RECOMP_FUNC void func_8006C3F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C3F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C3F8: jal         0x8005F064
    // 0x8006C3FC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C3FC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_0:
    // 0x8006C400: b           L_8006C410
    // 0x8006C404: nop

        goto L_8006C410;
    // 0x8006C404: nop

    // 0x8006C408: b           L_8006C410
    // 0x8006C40C: nop

        goto L_8006C410;
    // 0x8006C40C: nop

L_8006C410:
    // 0x8006C410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C418: jr          $ra
    // 0x8006C41C: nop

    return;
    // 0x8006C41C: nop

;}
RECOMP_FUNC void func_80089584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089584: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80089588: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008958C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80089590: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80089594: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80089598: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x8008959C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800895A0: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x800895A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800895A8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800895AC: nop

    // 0x800895B0: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800895B4: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800895B8: nop

    // 0x800895BC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800895C0: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x800895C4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800895C8: nop

    // 0x800895CC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800895D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800895D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800895D8: nop

    // 0x800895DC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800895E0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800895E4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800895E8: sh          $t9, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r25;
    // 0x800895EC: nop

    // 0x800895F0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800895F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800895F8: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x800895FC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80089600: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x80089604: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80089608: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8008960C: nop

    // 0x80089610: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80089614: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80089618: nop

    // 0x8008961C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80089620: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80089624: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80089628: nop

    // 0x8008962C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80089630: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80089634: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80089638: nop

    // 0x8008963C: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x80089640: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80089644: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80089648: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    // 0x8008964C: nop

    // 0x80089650: ori         $t4, $zero, 0x8003
    ctx->r12 = 0 | 0X8003;
    // 0x80089654: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80089658: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8008965C:
    // 0x8008965C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80089660:
    // 0x80089660: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80089664: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80089668: bne         $t5, $at, L_8008968C
    if (ctx->r13 != ctx->r1) {
        // 0x8008966C: nop
    
            goto L_8008968C;
    }
    // 0x8008966C: nop

    // 0x80089670: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80089674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089678: beq         $t6, $at, L_800896AC
    if (ctx->r14 == ctx->r1) {
        // 0x8008967C: nop
    
            goto L_800896AC;
    }
    // 0x8008967C: nop

    // 0x80089680: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80089684: beq         $t6, $at, L_800896AC
    if (ctx->r14 == ctx->r1) {
        // 0x80089688: nop
    
            goto L_800896AC;
    }
    // 0x80089688: nop

L_8008968C:
    // 0x8008968C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80089690: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80089694: bne         $t7, $at, L_800896B4
    if (ctx->r15 != ctx->r1) {
        // 0x80089698: nop
    
            goto L_800896B4;
    }
    // 0x80089698: nop

    // 0x8008969C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800896A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800896A4: bne         $t8, $at, L_800896B4
    if (ctx->r24 != ctx->r1) {
        // 0x800896A8: nop
    
            goto L_800896B4;
    }
    // 0x800896A8: nop

L_800896AC:
    // 0x800896AC: b           L_80089760
    // 0x800896B0: nop

        goto L_80089760;
    // 0x800896B0: nop

L_800896B4:
    // 0x800896B4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800896B8: nop

    // 0x800896BC: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800896C0: addiu       $t1, $t0, 0x6
    ctx->r9 = ADD32(ctx->r8, 0X6);
    // 0x800896C4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800896C8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800896CC: nop

    // 0x800896D0: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x800896D4: bne         $at, $zero, L_800896EC
    if (ctx->r1 != 0) {
        // 0x800896D8: nop
    
            goto L_800896EC;
    }
    // 0x800896D8: nop

    // 0x800896DC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800896E0: nop

    // 0x800896E4: addiu       $t4, $t3, 0x56
    ctx->r12 = ADD32(ctx->r11, 0X56);
    // 0x800896E8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_800896EC:
    // 0x800896EC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800896F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800896F4: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800896F8: mfhi        $t6
    ctx->r14 = hi;
    // 0x800896FC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80089700: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80089704: addiu       $t8, $t7, 0x5
    ctx->r24 = ADD32(ctx->r15, 0X5);
    // 0x80089708: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008970C: lh          $t9, 0x2C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2C);
    // 0x80089710: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80089714: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x80089718: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8008971C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80089720: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80089724: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80089728: addiu       $t5, $t1, 0xE
    ctx->r13 = ADD32(ctx->r9, 0XE);
    // 0x8008972C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80089730: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x80089734: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089738: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8008973C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80089740: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80089744: addiu       $a3, $t4, -0xD
    ctx->r7 = ADD32(ctx->r12, -0XD);
    // 0x80089748: jal         0x800897A8
    // 0x8008974C: addiu       $a2, $t1, -0x2
    ctx->r6 = ADD32(ctx->r9, -0X2);
    func_800897A8(rdram, ctx);
        goto after_0;
    // 0x8008974C: addiu       $a2, $t1, -0x2
    ctx->r6 = ADD32(ctx->r9, -0X2);
    after_0:
    // 0x80089750: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x80089754: nop

    // 0x80089758: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008975C: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
L_80089760:
    // 0x80089760: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80089764: nop

    // 0x80089768: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8008976C: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x80089770: bne         $at, $zero, L_80089660
    if (ctx->r1 != 0) {
        // 0x80089774: sw          $t2, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r10;
            goto L_80089660;
    }
    // 0x80089774: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80089778: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008977C: nop

    // 0x80089780: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x80089784: slti        $at, $t1, 0x12
    ctx->r1 = SIGNED(ctx->r9) < 0X12 ? 1 : 0;
    // 0x80089788: bne         $at, $zero, L_8008965C
    if (ctx->r1 != 0) {
        // 0x8008978C: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_8008965C;
    }
    // 0x8008978C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80089790: b           L_80089798
    // 0x80089794: nop

        goto L_80089798;
    // 0x80089794: nop

L_80089798:
    // 0x80089798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008979C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800897A0: jr          $ra
    // 0x800897A4: nop

    return;
    // 0x800897A4: nop

;}
RECOMP_FUNC void func_8000E524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000E528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E52C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000E530: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000E534: nop

    // 0x8000E538: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000E53C: nop

    // 0x8000E540: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8000E544: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000E548: addiu       $a1, $sp, 0x1A
    ctx->r5 = ADD32(ctx->r29, 0X1A);
    // 0x8000E54C: lw          $a0, 0x7C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X7C);
    // 0x8000E550: jal         0x8004A054
    // 0x8000E554: nop

    func_8004A054(rdram, ctx);
        goto after_0;
    // 0x8000E554: nop

    after_0:
    // 0x8000E558: bne         $v0, $zero, L_8000E568
    if (ctx->r2 != 0) {
        // 0x8000E55C: nop
    
            goto L_8000E568;
    }
    // 0x8000E55C: nop

    // 0x8000E560: b           L_8000E668
    // 0x8000E564: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E668;
    // 0x8000E564: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E568:
    // 0x8000E568: jal         0x80031AC8
    // 0x8000E56C: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x8000E56C: nop

    after_1:
    // 0x8000E570: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000E574: beq         $v0, $at, L_8000E5BC
    if (ctx->r2 == ctx->r1) {
        // 0x8000E578: nop
    
            goto L_8000E5BC;
    }
    // 0x8000E578: nop

    // 0x8000E57C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000E580: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8000E584: addiu       $a0, $t9, 0xC
    ctx->r4 = ADD32(ctx->r25, 0XC);
    // 0x8000E588: jal         0x800B2CBC
    // 0x8000E58C: addiu       $a1, $t9, 0x10
    ctx->r5 = ADD32(ctx->r25, 0X10);
    func_800B2CBC(rdram, ctx);
        goto after_2;
    // 0x8000E58C: addiu       $a1, $t9, 0x10
    ctx->r5 = ADD32(ctx->r25, 0X10);
    after_2:
    // 0x8000E590: jal         0x80031728
    // 0x8000E594: nop

    func_80031728(rdram, ctx);
        goto after_3;
    // 0x8000E594: nop

    after_3:
    // 0x8000E598: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000E59C: ori         $t0, $zero, 0xE007
    ctx->r8 = 0 | 0XE007;
    // 0x8000E5A0: sh          $t0, 0x62($t1)
    MEM_H(0X62, ctx->r9) = ctx->r8;
    // 0x8000E5A4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000E5A8: nop

    // 0x8000E5AC: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x8000E5B0: nop

    // 0x8000E5B4: ori         $t4, $t3, 0x100
    ctx->r12 = ctx->r11 | 0X100;
    // 0x8000E5B8: sw          $t4, 0x1A8($t2)
    MEM_W(0X1A8, ctx->r10) = ctx->r12;
L_8000E5BC:
    // 0x8000E5BC: lh          $t5, 0x1A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1A);
    // 0x8000E5C0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000E5C4: nop

    // 0x8000E5C8: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x8000E5CC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000E5D0: nop

    // 0x8000E5D4: sw          $zero, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = 0;
    // 0x8000E5D8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000E5DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8000E5E0: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000E5E4: nop

    // 0x8000E5E8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8000E5EC: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x8000E5F0: nop

    // 0x8000E5F4: blez        $t0, L_8000E640
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000E5F8: nop
    
            goto L_8000E640;
    }
    // 0x8000E5F8: nop

L_8000E5FC:
    // 0x8000E5FC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000E600: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8000E604: lw          $t3, 0x94($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X94);
    // 0x8000E608: nop

    // 0x8000E60C: sw          $t3, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r11;
    // 0x8000E610: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E614: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000E618: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000E61C: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8000E620: addiu       $t7, $t6, 0x160
    ctx->r15 = ADD32(ctx->r14, 0X160);
    // 0x8000E624: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8000E628: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8000E62C: lhu         $t8, 0x6($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X6);
    // 0x8000E630: nop

    // 0x8000E634: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000E638: bne         $at, $zero, L_8000E5FC
    if (ctx->r1 != 0) {
        // 0x8000E63C: nop
    
            goto L_8000E5FC;
    }
    // 0x8000E63C: nop

L_8000E640:
    // 0x8000E640: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000E644: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000E648: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000E64C: nop

    // 0x8000E650: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8000E654: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x8000E658: b           L_8000E668
    // 0x8000E65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E668;
    // 0x8000E65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E660: b           L_8000E668
    // 0x8000E664: nop

        goto L_8000E668;
    // 0x8000E664: nop

L_8000E668:
    // 0x8000E668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E66C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000E670: jr          $ra
    // 0x8000E674: nop

    return;
    // 0x8000E674: nop

;}
RECOMP_FUNC void func_8008D29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D29C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008D2A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008D2A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008D2A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008D2AC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008D2B0: nop

    // 0x8008D2B4: lh          $s0, 0x2($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X2);
    // 0x8008D2B8: nop

    // 0x8008D2BC: beq         $s0, $zero, L_8008D2F0
    if (ctx->r16 == 0) {
        // 0x8008D2C0: nop
    
            goto L_8008D2F0;
    }
    // 0x8008D2C0: nop

    // 0x8008D2C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D2C8: beq         $s0, $at, L_8008D304
    if (ctx->r16 == ctx->r1) {
        // 0x8008D2CC: nop
    
            goto L_8008D304;
    }
    // 0x8008D2CC: nop

    // 0x8008D2D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008D2D4: beq         $s0, $at, L_8008D318
    if (ctx->r16 == ctx->r1) {
        // 0x8008D2D8: nop
    
            goto L_8008D318;
    }
    // 0x8008D2D8: nop

    // 0x8008D2DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008D2E0: beq         $s0, $at, L_8008D32C
    if (ctx->r16 == ctx->r1) {
        // 0x8008D2E4: nop
    
            goto L_8008D32C;
    }
    // 0x8008D2E4: nop

    // 0x8008D2E8: b           L_8008D334
    // 0x8008D2EC: nop

        goto L_8008D334;
    // 0x8008D2EC: nop

L_8008D2F0:
    // 0x8008D2F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008D2F4: jal         0x8008D34C
    // 0x8008D2F8: nop

    func_8008D34C(rdram, ctx);
        goto after_0;
    // 0x8008D2F8: nop

    after_0:
    // 0x8008D2FC: b           L_8008D334
    // 0x8008D300: nop

        goto L_8008D334;
    // 0x8008D300: nop

L_8008D304:
    // 0x8008D304: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008D308: jal         0x8008D708
    // 0x8008D30C: nop

    func_8008D708(rdram, ctx);
        goto after_1;
    // 0x8008D30C: nop

    after_1:
    // 0x8008D310: b           L_8008D334
    // 0x8008D314: nop

        goto L_8008D334;
    // 0x8008D314: nop

L_8008D318:
    // 0x8008D318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008D31C: jal         0x8008D90C
    // 0x8008D320: nop

    func_8008D90C(rdram, ctx);
        goto after_2;
    // 0x8008D320: nop

    after_2:
    // 0x8008D324: b           L_8008D334
    // 0x8008D328: nop

        goto L_8008D334;
    // 0x8008D328: nop

L_8008D32C:
    // 0x8008D32C: b           L_8008D334
    // 0x8008D330: nop

        goto L_8008D334;
    // 0x8008D330: nop

L_8008D334:
    // 0x8008D334: b           L_8008D33C
    // 0x8008D338: nop

        goto L_8008D33C;
    // 0x8008D338: nop

L_8008D33C:
    // 0x8008D33C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008D344: jr          $ra
    // 0x8008D348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008D348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __CSPPostNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C8534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8538: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800C853C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C8540: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C8544: bnel        $t6, $at, L_800C8594
    if (ctx->r14 != ctx->r1) {
        // 0x800C8548: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8594;
    }
    goto skip_0;
    // 0x800C8548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C854C: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x800C8550: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800C8554: beql        $a0, $zero, L_800C8594
    if (ctx->r4 == 0) {
        // 0x800C8558: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8594;
    }
    goto skip_1;
    // 0x800C8558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C855C: jal         0x800CAB2C
    // 0x800C8560: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    __alCSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x800C8560: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C8564: beq         $v0, $zero, L_800C8590
    if (ctx->r2 == 0) {
        // 0x800C8568: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_800C8590;
    }
    // 0x800C8568: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800C856C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800C8570: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x800C8574: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8578: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x800C857C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800C8580: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8584: mflo        $a2
    ctx->r6 = lo;
    // 0x800C8588: jal         0x800D3A2C
    // 0x800C858C: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x800C858C: nop

    after_1:
L_800C8590:
    // 0x800C8590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8594:
    // 0x800C8594: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C8598: jr          $ra
    // 0x800C859C: nop

    return;
    // 0x800C859C: nop

;}
RECOMP_FUNC void func_8008B4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B4EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B4F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B4F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B4F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B4FC: addiu       $t6, $t6, 0x4720
    ctx->r14 = ADD32(ctx->r14, 0X4720);
    // 0x8008B500: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8008B504: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8008B508: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B50C: beq         $t7, $at, L_8008B5E8
    if (ctx->r15 == ctx->r1) {
        // 0x8008B510: nop
    
            goto L_8008B5E8;
    }
    // 0x8008B510: nop

L_8008B514:
    // 0x8008B514: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B518: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8008B51C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008B520: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008B524: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008B528: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008B52C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8008B530: lh          $t0, 0x4720($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X4720);
    // 0x8008B534: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x8008B538: nop

    // 0x8008B53C: bne         $t0, $t2, L_8008B5BC
    if (ctx->r8 != ctx->r10) {
        // 0x8008B540: nop
    
            goto L_8008B5BC;
    }
    // 0x8008B540: nop

    // 0x8008B544: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B548: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008B54C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8008B550: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008B554: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008B558: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8008B55C: lh          $t5, 0x4722($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X4722);
    // 0x8008B560: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B564: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x8008B568: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B56C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008B570: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008B574: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008B578: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008B57C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008B580: lh          $t8, 0x4724($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X4724);
    // 0x8008B584: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B588: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x8008B58C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B590: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008B594: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8008B598: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8008B59C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008B5A0: addiu       $t0, $t0, 0x4720
    ctx->r8 = ADD32(ctx->r8, 0X4720);
    // 0x8008B5A4: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8008B5A8: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
    // 0x8008B5AC: lh          $a2, 0x8($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X8);
    // 0x8008B5B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008B5B4: jal         0x8008B2FC
    // 0x8008B5B8: nop

    func_8008B2FC(rdram, ctx);
        goto after_0;
    // 0x8008B5B8: nop

    after_0:
L_8008B5BC:
    // 0x8008B5BC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B5C0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B5C4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008B5C8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008B5CC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008B5D0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B5D4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008B5D8: lh          $t6, 0x4720($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X4720);
    // 0x8008B5DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B5E0: bne         $t6, $at, L_8008B514
    if (ctx->r14 != ctx->r1) {
        // 0x8008B5E4: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_8008B514;
    }
    // 0x8008B5E4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
L_8008B5E8:
    // 0x8008B5E8: b           L_8008B5F0
    // 0x8008B5EC: nop

        goto L_8008B5F0;
    // 0x8008B5EC: nop

L_8008B5F0:
    // 0x8008B5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B5F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B5F8: jr          $ra
    // 0x8008B5FC: nop

    return;
    // 0x8008B5FC: nop

;}
RECOMP_FUNC void func_8008CE48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CE48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CE4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CE50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008CE54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008CE58: jal         0x800220F4
    // 0x8008CE5C: nop

    func_800220F4(rdram, ctx);
        goto after_0;
    // 0x8008CE5C: nop

    after_0:
    // 0x8008CE60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008CE64: jal         0x800B9000
    // 0x8008CE68: nop

    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8008CE68: nop

    after_1:
    // 0x8008CE6C: b           L_8008CE74
    // 0x8008CE70: nop

        goto L_8008CE74;
    // 0x8008CE70: nop

L_8008CE74:
    // 0x8008CE74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CE78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CE7C: jr          $ra
    // 0x8008CE80: nop

    return;
    // 0x8008CE80: nop

    // 0x8008CE84: nop

    // 0x8008CE88: nop

    // 0x8008CE8C: nop

;}
RECOMP_FUNC void func_800771DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800771DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800771E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800771E4: jal         0x80061488
    // 0x800771E8: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800771E8: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    after_0:
    // 0x800771EC: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800771F0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800771F4: b           L_80077204
    // 0x800771F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077204;
    // 0x800771F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800771FC: b           L_80077204
    // 0x80077200: nop

        goto L_80077204;
    // 0x80077200: nop

L_80077204:
    // 0x80077204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007720C: jr          $ra
    // 0x80077210: nop

    return;
    // 0x80077210: nop

;}
RECOMP_FUNC void func_800634E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800634E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800634E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800634EC: jal         0x80061488
    // 0x800634F0: addiu       $a0, $zero, 0x5E7
    ctx->r4 = ADD32(0, 0X5E7);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800634F0: addiu       $a0, $zero, 0x5E7
    ctx->r4 = ADD32(0, 0X5E7);
    after_0:
    // 0x800634F4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800634F8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800634FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063500: beq         $v0, $zero, L_80063564
    if (ctx->r2 == 0) {
        // 0x80063504: nop
    
            goto L_80063564;
    }
    // 0x80063504: nop

    // 0x80063508: jal         0x80061348
    // 0x8006350C: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006350C: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_1:
    // 0x80063510: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063514: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063518: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006351C: beq         $v0, $zero, L_80063564
    if (ctx->r2 == 0) {
        // 0x80063520: nop
    
            goto L_80063564;
    }
    // 0x80063520: nop

    // 0x80063524: jal         0x80061348
    // 0x80063528: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80063528: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_2:
    // 0x8006352C: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063530: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80063534: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063538: beq         $v0, $zero, L_80063564
    if (ctx->r2 == 0) {
        // 0x8006353C: nop
    
            goto L_80063564;
    }
    // 0x8006353C: nop

    // 0x80063540: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80063544: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80063548: nop

    // 0x8006354C: lh          $v0, 0x20($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X20);
    // 0x80063550: nop

    // 0x80063554: slti        $t0, $v0, 0x12C
    ctx->r8 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80063558: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x8006355C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80063560: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80063564:
    // 0x80063564: b           L_80063574
    // 0x80063568: nop

        goto L_80063574;
    // 0x80063568: nop

    // 0x8006356C: b           L_80063574
    // 0x80063570: nop

        goto L_80063574;
    // 0x80063570: nop

L_80063574:
    // 0x80063574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006357C: jr          $ra
    // 0x80063580: nop

    return;
    // 0x80063580: nop

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
RECOMP_FUNC void func_8006703C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006703C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067044: jal         0x80061488
    // 0x80067048: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067048: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    after_0:
    // 0x8006704C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067050: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067054: b           L_80067064
    // 0x80067058: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067064;
    // 0x80067058: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006705C: b           L_80067064
    // 0x80067060: nop

        goto L_80067064;
    // 0x80067060: nop

L_80067064:
    // 0x80067064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006706C: jr          $ra
    // 0x80067070: nop

    return;
    // 0x80067070: nop

;}
RECOMP_FUNC void SoundDebugMenu_SfxOneShotTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021D8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80021D90: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80021D94: nop

    // 0x80021D98: bltz        $t6, L_80021E94
    if (SIGNED(ctx->r14) < 0) {
        // 0x80021D9C: nop
    
            goto L_80021E94;
    }
    // 0x80021D9C: nop

    // 0x80021DA0: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80021DA4: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80021DA8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80021DAC: lhu         $t9, 0xEEC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEEC);
    // 0x80021DB0: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80021DB4: nop

    // 0x80021DB8: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80021DBC: beq         $t0, $zero, L_80021DD8
    if (ctx->r8 == 0) {
        // 0x80021DC0: nop
    
            goto L_80021DD8;
    }
    // 0x80021DC0: nop

    // 0x80021DC4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021DC8: lw          $t1, -0x33B8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33B8);
    // 0x80021DCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021DD0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021DD4: sw          $t2, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = ctx->r10;
L_80021DD8:
    // 0x80021DD8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80021DDC: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80021DE0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021DE4: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x80021DE8: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80021DEC: nop

    // 0x80021DF0: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80021DF4: beq         $t6, $zero, L_80021E10
    if (ctx->r14 == 0) {
        // 0x80021DF8: nop
    
            goto L_80021E10;
    }
    // 0x80021DF8: nop

    // 0x80021DFC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80021E00: lw          $t7, -0x33B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33B8);
    // 0x80021E04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021E08: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80021E0C: sw          $t8, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = ctx->r24;
L_80021E10:
    // 0x80021E10: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80021E14: lw          $t9, -0x33B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33B8);
    // 0x80021E18: nop

    // 0x80021E1C: bgez        $t9, L_80021E2C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80021E20: nop
    
            goto L_80021E2C;
    }
    // 0x80021E20: nop

    // 0x80021E24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021E28: sw          $zero, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = 0;
L_80021E2C:
    // 0x80021E2C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80021E30: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80021E34: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021E38: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x80021E3C: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x80021E40: nop

    // 0x80021E44: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80021E48: beq         $t3, $zero, L_80021E60
    if (ctx->r11 == 0) {
        // 0x80021E4C: nop
    
            goto L_80021E60;
    }
    // 0x80021E4C: nop

    // 0x80021E50: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80021E54: lw          $a0, -0x33B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33B8);
    // 0x80021E58: jal         0x800B9000
    // 0x80021E5C: nop

    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x80021E5C: nop

    after_0:
L_80021E60:
    // 0x80021E60: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80021E64: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80021E68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80021E6C: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x80021E70: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80021E74: nop

    // 0x80021E78: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x80021E7C: beq         $t7, $zero, L_80021E94
    if (ctx->r15 == 0) {
        // 0x80021E80: nop
    
            goto L_80021E94;
    }
    // 0x80021E80: nop

    // 0x80021E84: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80021E88: lw          $a0, -0x33B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33B8);
    // 0x80021E8C: jal         0x800220F4
    // 0x80021E90: nop

    func_800220F4(rdram, ctx);
        goto after_1;
    // 0x80021E90: nop

    after_1:
L_80021E94:
    // 0x80021E94: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80021E98: lw          $a1, -0x33B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X33B8);
    // 0x80021E9C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021EA0: jal         0x8008ECE4
    // 0x80021EA4: addiu       $a0, $a0, -0x1CF8
    ctx->r4 = ADD32(ctx->r4, -0X1CF8);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x80021EA4: addiu       $a0, $a0, -0x1CF8
    ctx->r4 = ADD32(ctx->r4, -0X1CF8);
    after_2:
    // 0x80021EA8: b           L_80021EB8
    // 0x80021EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021EB8;
    // 0x80021EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021EB0: b           L_80021EB8
    // 0x80021EB4: nop

        goto L_80021EB8;
    // 0x80021EB4: nop

L_80021EB8:
    // 0x80021EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021EC0: jr          $ra
    // 0x80021EC4: nop

    return;
    // 0x80021EC4: nop

;}
RECOMP_FUNC void func_80069CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069CE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80069CEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80069CF0: nop

    // 0x80069CF4: lh          $v0, 0x38($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X38);
    // 0x80069CF8: nop

    // 0x80069CFC: xori        $t7, $v0, 0x3E7
    ctx->r15 = ctx->r2 ^ 0X3E7;
    // 0x80069D00: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069D04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069D08: beq         $v0, $zero, L_80069D24
    if (ctx->r2 == 0) {
        // 0x80069D0C: nop
    
            goto L_80069D24;
    }
    // 0x80069D0C: nop

    // 0x80069D10: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x80069D14: nop

    // 0x80069D18: xori        $t8, $v0, 0x3E7
    ctx->r24 = ctx->r2 ^ 0X3E7;
    // 0x80069D1C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069D20: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80069D24:
    // 0x80069D24: jr          $ra
    // 0x80069D28: nop

    return;
    // 0x80069D28: nop

    // 0x80069D2C: jr          $ra
    // 0x80069D30: nop

    return;
    // 0x80069D30: nop

    // 0x80069D34: jr          $ra
    // 0x80069D38: nop

    return;
    // 0x80069D38: nop

;}
RECOMP_FUNC void __osBlockSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C70F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C70FC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800C7100: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800C7104: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x800C7108: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800C710C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7110: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C7114: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800C7118: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800C711C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800C7120: jal         0x800CE34C
    // 0x800C7124: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7124: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800C7128: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C712C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800C7130: beq         $t8, $zero, L_800C7140
    if (ctx->r24 == 0) {
        // 0x800C7134: nop
    
            goto L_800C7140;
    }
    // 0x800C7134: nop

    // 0x800C7138: b           L_800C71D8
    // 0x800C713C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800C71D8;
    // 0x800C713C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C7140:
    // 0x800C7140: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800C7144:
    // 0x800C7144: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x800C7148: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800C714C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7150: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C7154: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800C7158: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800C715C: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800C7160: jal         0x800CF390
    // 0x800C7164: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamRead_recomp(rdram, ctx);
        goto after_1;
    // 0x800C7164: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800C7168: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C716C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800C7170: beq         $t3, $zero, L_800C7190
    if (ctx->r11 == 0) {
        // 0x800C7174: nop
    
            goto L_800C7190;
    }
    // 0x800C7174: nop

    // 0x800C7178: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800C717C: sb          $zero, 0x65($t4)
    MEM_B(0X65, ctx->r12) = 0;
    // 0x800C7180: jal         0x800CE34C
    // 0x800C7184: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800C7184: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800C7188: b           L_800C71D8
    // 0x800C718C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800C71D8;
    // 0x800C718C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800C7190:
    // 0x800C7190: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C7194: jal         0x800CD660
    // 0x800C7198: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    __osSumcalc(rdram, ctx);
        goto after_3;
    // 0x800C7198: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x800C719C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800C71A0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800C71A4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800C71A8: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800C71AC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800C71B0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C71B4: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800C71B8: bne         $at, $zero, L_800C7144
    if (ctx->r1 != 0) {
        // 0x800C71BC: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_800C7144;
    }
    // 0x800C71BC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800C71C0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800C71C4: sb          $zero, 0x65($t0)
    MEM_B(0X65, ctx->r8) = 0;
    // 0x800C71C8: jal         0x800CE34C
    // 0x800C71CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800C71CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800C71D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C71D4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800C71D8:
    // 0x800C71D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C71DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800C71E0: jr          $ra
    // 0x800C71E4: nop

    return;
    // 0x800C71E4: nop

;}
RECOMP_FUNC void func_800711A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800711A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800711A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800711A8: jal         0x80061348
    // 0x800711AC: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800711AC: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_0:
    // 0x800711B0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800711B4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800711B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800711BC: beq         $v0, $zero, L_80071210
    if (ctx->r2 == 0) {
        // 0x800711C0: nop
    
            goto L_80071210;
    }
    // 0x800711C0: nop

    // 0x800711C4: jal         0x80061348
    // 0x800711C8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800711C8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x800711CC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800711D0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800711D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800711D8: beq         $v0, $zero, L_80071210
    if (ctx->r2 == 0) {
        // 0x800711DC: nop
    
            goto L_80071210;
    }
    // 0x800711DC: nop

    // 0x800711E0: jal         0x80061348
    // 0x800711E4: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800711E4: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x800711E8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800711EC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800711F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800711F4: beq         $v0, $zero, L_80071210
    if (ctx->r2 == 0) {
        // 0x800711F8: nop
    
            goto L_80071210;
    }
    // 0x800711F8: nop

    // 0x800711FC: jal         0x80061348
    // 0x80071200: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071200: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_3:
    // 0x80071204: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071208: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007120C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071210:
    // 0x80071210: b           L_80071220
    // 0x80071214: nop

        goto L_80071220;
    // 0x80071214: nop

    // 0x80071218: b           L_80071220
    // 0x8007121C: nop

        goto L_80071220;
    // 0x8007121C: nop

L_80071220:
    // 0x80071220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071228: jr          $ra
    // 0x8007122C: nop

    return;
    // 0x8007122C: nop

;}
RECOMP_FUNC void func_8005275C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005275C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052760: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80052764: nop

    // 0x80052768: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005276C: nop

    // 0x80052770: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x80052774: beq         $at, $zero, L_80052784
    if (ctx->r1 == 0) {
        // 0x80052778: nop
    
            goto L_80052784;
    }
    // 0x80052778: nop

    // 0x8005277C: jr          $ra
    // 0x80052780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80052780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052784:
    // 0x80052784: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052788: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005278C: nop

    // 0x80052790: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80052794: nop

    // 0x80052798: slti        $at, $t9, 0x3D
    ctx->r1 = SIGNED(ctx->r25) < 0X3D ? 1 : 0;
    // 0x8005279C: beq         $at, $zero, L_800527AC
    if (ctx->r1 == 0) {
        // 0x800527A0: nop
    
            goto L_800527AC;
    }
    // 0x800527A0: nop

    // 0x800527A4: jr          $ra
    // 0x800527A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800527A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800527AC:
    // 0x800527AC: jr          $ra
    // 0x800527B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800527B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void AudioMgr_InitThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8A2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B8A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8A34: jal         0x800B84F0
    // 0x800B8A38: nop

    func_800B84F0(rdram, ctx);
        goto after_0;
    // 0x800B8A38: nop

    after_0:
    // 0x800B8A3C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800B8A40: addiu       $a0, $a0, -0x7584
    ctx->r4 = ADD32(ctx->r4, -0X7584);
    // 0x800B8A44: jal         0x800C0780
    // 0x800B8A48: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    Thread_CreateExtended(rdram, ctx);
        goto after_1;
    // 0x800B8A48: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x800B8A4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B8A50: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8A54: nop

    // 0x800B8A58: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800B8A5C: jal         0x800C0C8C
    // 0x800B8A60: nop

    Thread_Start(rdram, ctx);
        goto after_2;
    // 0x800B8A60: nop

    after_2:
    // 0x800B8A64: b           L_800B8A6C
    // 0x800B8A68: nop

        goto L_800B8A6C;
    // 0x800B8A68: nop

L_800B8A6C:
    // 0x800B8A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B8A74: jr          $ra
    // 0x800B8A78: nop

    return;
    // 0x800B8A78: nop

;}
RECOMP_FUNC void func_80072F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072F28: jal         0x8005F064
    // 0x80072F2C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80072F2C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x80072F30: b           L_80072F40
    // 0x80072F34: nop

        goto L_80072F40;
    // 0x80072F34: nop

    // 0x80072F38: b           L_80072F40
    // 0x80072F3C: nop

        goto L_80072F40;
    // 0x80072F3C: nop

L_80072F40:
    // 0x80072F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072F48: jr          $ra
    // 0x80072F4C: nop

    return;
    // 0x80072F4C: nop

;}
RECOMP_FUNC void func_80066004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066004: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066008: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006600C: nop

    // 0x80066010: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80066014: nop

    // 0x80066018: slti        $t7, $v0, 0x259
    ctx->r15 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x8006601C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066020: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066024: beq         $v0, $zero, L_8006603C
    if (ctx->r2 == 0) {
        // 0x80066028: nop
    
            goto L_8006603C;
    }
    // 0x80066028: nop

    // 0x8006602C: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80066030: nop

    // 0x80066034: slti        $t8, $v0, 0x2BD
    ctx->r24 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80066038: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006603C:
    // 0x8006603C: jr          $ra
    // 0x80066040: nop

    return;
    // 0x80066040: nop

    // 0x80066044: jr          $ra
    // 0x80066048: nop

    return;
    // 0x80066048: nop

    // 0x8006604C: jr          $ra
    // 0x80066050: nop

    return;
    // 0x80066050: nop

;}
RECOMP_FUNC void func_800AD70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD70C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AD710: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AD714: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800AD718: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800AD71C:
    // 0x800AD71C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800AD720: nop

    // 0x800AD724: and         $t8, $t7, $a0
    ctx->r24 = ctx->r15 & ctx->r4;
    // 0x800AD728: beq         $t8, $zero, L_800AD73C
    if (ctx->r24 == 0) {
        // 0x800AD72C: nop
    
            goto L_800AD73C;
    }
    // 0x800AD72C: nop

    // 0x800AD730: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800AD734: b           L_800AD76C
    // 0x800AD738: nop

        goto L_800AD76C;
    // 0x800AD738: nop

L_800AD73C:
    // 0x800AD73C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800AD740: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800AD744: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800AD748: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800AD74C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800AD750: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x800AD754: bne         $at, $zero, L_800AD71C
    if (ctx->r1 != 0) {
        // 0x800AD758: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_800AD71C;
    }
    // 0x800AD758: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800AD75C: b           L_800AD76C
    // 0x800AD760: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800AD76C;
    // 0x800AD760: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AD764: b           L_800AD76C
    // 0x800AD768: nop

        goto L_800AD76C;
    // 0x800AD768: nop

L_800AD76C:
    // 0x800AD76C: jr          $ra
    // 0x800AD770: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AD770: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006B7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B7E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B7E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B7EC: jal         0x80061488
    // 0x8006B7F0: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006B7F0: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    after_0:
    // 0x8006B7F4: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006B7F8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006B7FC: b           L_8006B80C
    // 0x8006B800: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006B80C;
    // 0x8006B800: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B804: b           L_8006B80C
    // 0x8006B808: nop

        goto L_8006B80C;
    // 0x8006B808: nop

L_8006B80C:
    // 0x8006B80C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B814: jr          $ra
    // 0x8006B818: nop

    return;
    // 0x8006B818: nop

;}
RECOMP_FUNC void func_8006E04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E04C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E054: jal         0x80061348
    // 0x8006E058: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E058: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x8006E05C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E060: b           L_8006E070
    // 0x8006E064: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E070;
    // 0x8006E064: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E068: b           L_8006E070
    // 0x8006E06C: nop

        goto L_8006E070;
    // 0x8006E06C: nop

L_8006E070:
    // 0x8006E070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E078: jr          $ra
    // 0x8006E07C: nop

    return;
    // 0x8006E07C: nop

;}
RECOMP_FUNC void alMainBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF888: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CF88C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CF890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF894: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF898: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF89C: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
    // 0x800CF8A0: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    // 0x800CF8A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CF8A8: jal         0x800D56B0
    // 0x800CF8AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF8AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x800CF8B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CF8B4: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CF8B8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CF8BC: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800CF8C0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF8C4: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800CF8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF8CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF8D0: jr          $ra
    // 0x800CF8D4: nop

    return;
    // 0x800CF8D4: nop

;}
RECOMP_FUNC void func_8006F180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F188: jal         0x80061348
    // 0x8006F18C: addiu       $a0, $zero, 0x2CD
    ctx->r4 = ADD32(0, 0X2CD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F18C: addiu       $a0, $zero, 0x2CD
    ctx->r4 = ADD32(0, 0X2CD);
    after_0:
    // 0x8006F190: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F194: b           L_8006F1A4
    // 0x8006F198: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F1A4;
    // 0x8006F198: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F19C: b           L_8006F1A4
    // 0x8006F1A0: nop

        goto L_8006F1A4;
    // 0x8006F1A0: nop

L_8006F1A4:
    // 0x8006F1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F1A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F1AC: jr          $ra
    // 0x8006F1B0: nop

    return;
    // 0x8006F1B0: nop

;}
RECOMP_FUNC void func_800062C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800062C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800062C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800062C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800062CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800062D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800062D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800062D8: nop

    // 0x800062DC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800062E0: jal         0x80096474
    // 0x800062E4: nop

    func_80096474(rdram, ctx);
        goto after_0;
    // 0x800062E4: nop

    after_0:
    // 0x800062E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800062EC: nop

    // 0x800062F0: lw          $a0, 0x128($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X128);
    // 0x800062F4: jal         0x8008ECCC
    // 0x800062F8: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_1;
    // 0x800062F8: nop

    after_1:
    // 0x800062FC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80006300: nop

    // 0x80006304: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x80006308: lh          $t0, 0x102($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X102);
    // 0x8000630C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80006310: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80006314: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006318: jal         0x8008EC8C
    // 0x8000631C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_8008EC8C(rdram, ctx);
        goto after_2;
    // 0x8000631C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_2:
    // 0x80006320: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80006324: nop

    // 0x80006328: lh          $t2, 0x100($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X100);
    // 0x8000632C: lh          $t3, 0x102($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X102);
    // 0x80006330: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80006334: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80006338: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000633C: jal         0x8008ECAC
    // 0x80006340: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_8008ECAC(rdram, ctx);
        goto after_3;
    // 0x80006340: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_3:
    // 0x80006344: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80006348: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000634C: sw          $t4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r12;
    // 0x80006350: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80006354: lw          $t6, -0x4CE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CE0);
    // 0x80006358: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000635C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80006360: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80006364: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80006368: sh          $t5, -0x44B8($at)
    MEM_H(-0X44B8, ctx->r1) = ctx->r13;
    // 0x8000636C: jal         0x80090754
    // 0x80006370: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    func_80090754(rdram, ctx);
        goto after_4;
    // 0x80006370: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    after_4:
    // 0x80006374: jal         0x80090728
    // 0x80006378: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    func_80090728(rdram, ctx);
        goto after_5;
    // 0x80006378: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_5:
    // 0x8000637C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80006380:
    // 0x80006380: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80006384: nop

    // 0x80006388: bne         $t9, $zero, L_800063A4
    if (ctx->r25 != 0) {
        // 0x8000638C: nop
    
            goto L_800063A4;
    }
    // 0x8000638C: nop

    // 0x80006390: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006394: jal         0x8008EAA8
    // 0x80006398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_6;
    // 0x80006398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8000639C: b           L_80006470
    // 0x800063A0: nop

        goto L_80006470;
    // 0x800063A0: nop

L_800063A4:
    // 0x800063A4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800063A8: nop

    // 0x800063AC: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800063B0: bne         $at, $zero, L_800063DC
    if (ctx->r1 != 0) {
        // 0x800063B4: nop
    
            goto L_800063DC;
    }
    // 0x800063B4: nop

    // 0x800063B8: slti        $at, $t8, 0xC
    ctx->r1 = SIGNED(ctx->r24) < 0XC ? 1 : 0;
    // 0x800063BC: beq         $at, $zero, L_800063DC
    if (ctx->r1 == 0) {
        // 0x800063C0: nop
    
            goto L_800063DC;
    }
    // 0x800063C0: nop

    // 0x800063C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800063C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800063CC: jal         0x8008EAA8
    // 0x800063D0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_7;
    // 0x800063D0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_7:
    // 0x800063D4: b           L_80006470
    // 0x800063D8: nop

        goto L_80006470;
    // 0x800063D8: nop

L_800063DC:
    // 0x800063DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800063E0: nop

    // 0x800063E4: slti        $at, $t0, 0xC
    ctx->r1 = SIGNED(ctx->r8) < 0XC ? 1 : 0;
    // 0x800063E8: bne         $at, $zero, L_80006414
    if (ctx->r1 != 0) {
        // 0x800063EC: nop
    
            goto L_80006414;
    }
    // 0x800063EC: nop

    // 0x800063F0: slti        $at, $t0, 0x18
    ctx->r1 = SIGNED(ctx->r8) < 0X18 ? 1 : 0;
    // 0x800063F4: beq         $at, $zero, L_80006414
    if (ctx->r1 == 0) {
        // 0x800063F8: nop
    
            goto L_80006414;
    }
    // 0x800063F8: nop

    // 0x800063FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80006400: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80006404: jal         0x8008EAA8
    // 0x80006408: addiu       $a1, $a1, -0x7
    ctx->r5 = ADD32(ctx->r5, -0X7);
    func_8008EAA8(rdram, ctx);
        goto after_8;
    // 0x80006408: addiu       $a1, $a1, -0x7
    ctx->r5 = ADD32(ctx->r5, -0X7);
    after_8:
    // 0x8000640C: b           L_80006470
    // 0x80006410: nop

        goto L_80006470;
    // 0x80006410: nop

L_80006414:
    // 0x80006414: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80006418: nop

    // 0x8000641C: slti        $at, $t2, 0x18
    ctx->r1 = SIGNED(ctx->r10) < 0X18 ? 1 : 0;
    // 0x80006420: bne         $at, $zero, L_8000644C
    if (ctx->r1 != 0) {
        // 0x80006424: nop
    
            goto L_8000644C;
    }
    // 0x80006424: nop

    // 0x80006428: slti        $at, $t2, 0x1C
    ctx->r1 = SIGNED(ctx->r10) < 0X1C ? 1 : 0;
    // 0x8000642C: beq         $at, $zero, L_8000644C
    if (ctx->r1 == 0) {
        // 0x80006430: nop
    
            goto L_8000644C;
    }
    // 0x80006430: nop

    // 0x80006434: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80006438: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8000643C: jal         0x8008EAA8
    // 0x80006440: addiu       $a1, $a1, -0x13
    ctx->r5 = ADD32(ctx->r5, -0X13);
    func_8008EAA8(rdram, ctx);
        goto after_9;
    // 0x80006440: addiu       $a1, $a1, -0x13
    ctx->r5 = ADD32(ctx->r5, -0X13);
    after_9:
    // 0x80006444: b           L_80006470
    // 0x80006448: nop

        goto L_80006470;
    // 0x80006448: nop

L_8000644C:
    // 0x8000644C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80006450: nop

    // 0x80006454: slti        $at, $t1, 0x1C
    ctx->r1 = SIGNED(ctx->r9) < 0X1C ? 1 : 0;
    // 0x80006458: bne         $at, $zero, L_80006470
    if (ctx->r1 != 0) {
        // 0x8000645C: nop
    
            goto L_80006470;
    }
    // 0x8000645C: nop

    // 0x80006460: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80006464: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80006468: jal         0x8008EAA8
    // 0x8000646C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    func_8008EAA8(rdram, ctx);
        goto after_10;
    // 0x8000646C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    after_10:
L_80006470:
    // 0x80006470: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80006474: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80006478: lw          $t9, -0x6080($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6080);
    // 0x8000647C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80006480: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80006484: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80006488: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8000648C: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80006490: lh          $t0, 0x0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X0);
    // 0x80006494: nop

    // 0x80006498: bne         $t7, $t0, L_800064CC
    if (ctx->r15 != ctx->r8) {
        // 0x8000649C: nop
    
            goto L_800064CC;
    }
    // 0x8000649C: nop

    // 0x800064A0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800064A4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800064A8: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x800064AC: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x800064B0: lh          $a2, 0x0($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X0);
    // 0x800064B4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800064B8: addiu       $a0, $a0, -0x2E80
    ctx->r4 = ADD32(ctx->r4, -0X2E80);
    // 0x800064BC: jal         0x8008ECE4
    // 0x800064C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008ECE4(rdram, ctx);
        goto after_11;
    // 0x800064C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x800064C4: b           L_80006550
    // 0x800064C8: nop

        goto L_80006550;
    // 0x800064C8: nop

L_800064CC:
    // 0x800064CC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800064D0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800064D4: lw          $t5, -0x6080($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6080);
    // 0x800064D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800064DC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800064E0: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800064E4: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x800064E8: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x800064EC: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x800064F0: nop

    // 0x800064F4: slt         $at, $t7, $t2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800064F8: beq         $at, $zero, L_8000652C
    if (ctx->r1 == 0) {
        // 0x800064FC: nop
    
            goto L_8000652C;
    }
    // 0x800064FC: nop

    // 0x80006500: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80006504: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80006508: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x8000650C: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x80006510: lh          $a2, 0x0($t5)
    ctx->r6 = MEM_H(ctx->r13, 0X0);
    // 0x80006514: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80006518: addiu       $a0, $a0, -0x2E74
    ctx->r4 = ADD32(ctx->r4, -0X2E74);
    // 0x8000651C: jal         0x8008ECE4
    // 0x80006520: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8008ECE4(rdram, ctx);
        goto after_12;
    // 0x80006520: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_12:
    // 0x80006524: b           L_80006550
    // 0x80006528: nop

        goto L_80006550;
    // 0x80006528: nop

L_8000652C:
    // 0x8000652C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80006530: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80006534: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x80006538: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x8000653C: lh          $a2, 0x0($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X0);
    // 0x80006540: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80006544: addiu       $a0, $a0, -0x2E68
    ctx->r4 = ADD32(ctx->r4, -0X2E68);
    // 0x80006548: jal         0x8008ECE4
    // 0x8000654C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008ECE4(rdram, ctx);
        goto after_13;
    // 0x8000654C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
L_80006550:
    // 0x80006550: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80006554: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80006558: nop

    // 0x8000655C: bne         $t7, $t2, L_80006578
    if (ctx->r15 != ctx->r10) {
        // 0x80006560: nop
    
            goto L_80006578;
    }
    // 0x80006560: nop

    // 0x80006564: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80006568: jal         0x8008ECE4
    // 0x8000656C: addiu       $a0, $a0, -0x2E5C
    ctx->r4 = ADD32(ctx->r4, -0X2E5C);
    func_8008ECE4(rdram, ctx);
        goto after_14;
    // 0x8000656C: addiu       $a0, $a0, -0x2E5C
    ctx->r4 = ADD32(ctx->r4, -0X2E5C);
    after_14:
    // 0x80006570: b           L_80006584
    // 0x80006574: nop

        goto L_80006584;
    // 0x80006574: nop

L_80006578:
    // 0x80006578: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000657C: jal         0x8008ECE4
    // 0x80006580: addiu       $a0, $a0, -0x2E58
    ctx->r4 = ADD32(ctx->r4, -0X2E58);
    func_8008ECE4(rdram, ctx);
        goto after_15;
    // 0x80006580: addiu       $a0, $a0, -0x2E58
    ctx->r4 = ADD32(ctx->r4, -0X2E58);
    after_15:
L_80006584:
    // 0x80006584: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80006588: nop

    // 0x8000658C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80006590: slti        $at, $t4, 0x2A
    ctx->r1 = SIGNED(ctx->r12) < 0X2A ? 1 : 0;
    // 0x80006594: bne         $at, $zero, L_80006380
    if (ctx->r1 != 0) {
        // 0x80006598: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_80006380;
    }
    // 0x80006598: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8000659C: jal         0x800967D8
    // 0x800065A0: nop

    func_800967D8(rdram, ctx);
        goto after_16;
    // 0x800065A0: nop

    after_16:
    // 0x800065A4: b           L_800065AC
    // 0x800065A8: nop

        goto L_800065AC;
    // 0x800065A8: nop

L_800065AC:
    // 0x800065AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800065B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800065B4: jr          $ra
    // 0x800065B8: nop

    return;
    // 0x800065B8: nop

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
RECOMP_FUNC void func_8006C030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C038: jal         0x8005F064
    // 0x8006C03C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C03C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_0:
    // 0x8006C040: b           L_8006C050
    // 0x8006C044: nop

        goto L_8006C050;
    // 0x8006C044: nop

    // 0x8006C048: b           L_8006C050
    // 0x8006C04C: nop

        goto L_8006C050;
    // 0x8006C04C: nop

L_8006C050:
    // 0x8006C050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C058: jr          $ra
    // 0x8006C05C: nop

    return;
    // 0x8006C05C: nop

;}
RECOMP_FUNC void ContThread_InitControllers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD800: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AD804: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD808: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AD80C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AD810: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AD814: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD818: sw          $zero, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = 0;
    // 0x800AD81C: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x800AD820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD824: sh          $t6, 0xE68($at)
    MEM_H(0XE68, ctx->r1) = ctx->r14;
    // 0x800AD828: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x800AD82C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD830: sh          $t7, 0xE74($at)
    MEM_H(0XE74, ctx->r1) = ctx->r15;
    // 0x800AD834: addiu       $t8, $zero, 0x200
    ctx->r24 = ADD32(0, 0X200);
    // 0x800AD838: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD83C: sh          $t8, 0xEC0($at)
    MEM_H(0XEC0, ctx->r1) = ctx->r24;
    // 0x800AD840: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x800AD844: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD848: sh          $t9, 0xEEC($at)
    MEM_H(0XEEC, ctx->r1) = ctx->r25;
    // 0x800AD84C: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x800AD850: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD854: sh          $t0, 0xFF4($at)
    MEM_H(0XFF4, ctx->r1) = ctx->r8;
    // 0x800AD858: addiu       $t1, $zero, 0x4000
    ctx->r9 = ADD32(0, 0X4000);
    // 0x800AD85C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD860: sh          $t1, 0x101C($at)
    MEM_H(0X101C, ctx->r1) = ctx->r9;
    // 0x800AD864: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800AD868: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD86C: sh          $t2, 0x1038($at)
    MEM_H(0X1038, ctx->r1) = ctx->r10;
    // 0x800AD870: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x800AD874: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD878: sh          $t3, 0x1042($at)
    MEM_H(0X1042, ctx->r1) = ctx->r11;
    // 0x800AD87C: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x800AD880: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD884: sh          $t4, 0x10F2($at)
    MEM_H(0X10F2, ctx->r1) = ctx->r12;
    // 0x800AD888: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x800AD88C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD890: sh          $t5, 0x11A4($at)
    MEM_H(0X11A4, ctx->r1) = ctx->r13;
    // 0x800AD894: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800AD898: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD89C: sh          $t6, 0x11AC($at)
    MEM_H(0X11AC, ctx->r1) = ctx->r14;
    // 0x800AD8A0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800AD8A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8A8: sh          $t7, 0x1258($at)
    MEM_H(0X1258, ctx->r1) = ctx->r15;
    // 0x800AD8AC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800AD8B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8B4: sh          $t8, 0x1260($at)
    MEM_H(0X1260, ctx->r1) = ctx->r24;
    // 0x800AD8B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AD8BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8C0: sh          $t9, 0x126C($at)
    MEM_H(0X126C, ctx->r1) = ctx->r25;
    // 0x800AD8C4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800AD8C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD8CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8D0: swc1        $f4, 0xE50($at)
    MEM_W(0XE50, ctx->r1) = ctx->f4.u32l;
    // 0x800AD8D4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800AD8D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD8DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8E0: swc1        $f6, 0xE5C($at)
    MEM_W(0XE5C, ctx->r1) = ctx->f6.u32l;
    // 0x800AD8E4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800AD8E8:
    // 0x800AD8E8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800AD8EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8F0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AD8F4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800AD8F8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800AD8FC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800AD900: sw          $zero, 0xDA8($at)
    MEM_W(0XDA8, ctx->r1) = 0;
    // 0x800AD904: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800AD908: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD90C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AD910: lwc1        $f8, 0xE50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XE50);
    // 0x800AD914: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800AD918: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800AD91C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD920: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800AD924: swc1        $f8, 0xDC0($at)
    MEM_W(0XDC0, ctx->r1) = ctx->f8.u32l;
    // 0x800AD928: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800AD92C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD930: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AD934: lwc1        $f10, 0xE5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE5C);
    // 0x800AD938: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800AD93C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800AD940: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD944: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800AD948: swc1        $f10, 0xDC4($at)
    MEM_W(0XDC4, ctx->r1) = ctx->f10.u32l;
    // 0x800AD94C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800AD950: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800AD954: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AD958: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800AD95C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AD960: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AD964: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800AD968: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD96C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AD970: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800AD974: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800AD978: addiu       $t0, $t0, 0xDA8
    ctx->r8 = ADD32(ctx->r8, 0XDA8);
    // 0x800AD97C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AD980: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800AD984: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AD988: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AD98C: swc1        $f16, 0xDB4($at)
    MEM_W(0XDB4, ctx->r1) = ctx->f16.u32l;
    // 0x800AD990: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800AD994: lwc1        $f18, 0xC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800AD998: nop

    // 0x800AD99C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AD9A0: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x800AD9A4: nop

    // 0x800AD9A8: andi        $at, $s2, 0x4
    ctx->r1 = ctx->r18 & 0X4;
    // 0x800AD9AC: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x800AD9B0: beq         $s2, $zero, L_800ADA04
    if (ctx->r18 == 0) {
        // 0x800AD9B4: nop
    
            goto L_800ADA04;
    }
    // 0x800AD9B4: nop

    // 0x800AD9B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AD9BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD9C0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AD9C4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800AD9C8: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800AD9CC: nop

    // 0x800AD9D0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD9D4: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x800AD9D8: nop

    // 0x800AD9DC: andi        $at, $s2, 0x4
    ctx->r1 = ctx->r18 & 0X4;
    // 0x800AD9E0: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x800AD9E4: bne         $s2, $zero, L_800AD9FC
    if (ctx->r18 != 0) {
        // 0x800AD9E8: nop
    
            goto L_800AD9FC;
    }
    // 0x800AD9E8: nop

    // 0x800AD9EC: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x800AD9F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD9F4: b           L_800ADA14
    // 0x800AD9F8: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_800ADA14;
    // 0x800AD9F8: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_800AD9FC:
    // 0x800AD9FC: b           L_800ADA14
    // 0x800ADA00: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_800ADA14;
    // 0x800ADA00: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800ADA04:
    // 0x800ADA04: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x800ADA08: nop

    // 0x800ADA0C: bltz        $s2, L_800AD9FC
    if (SIGNED(ctx->r18) < 0) {
        // 0x800ADA10: nop
    
            goto L_800AD9FC;
    }
    // 0x800ADA10: nop

L_800ADA14:
    // 0x800ADA14: andi        $t3, $s2, 0xFFFF
    ctx->r11 = ctx->r18 & 0XFFFF;
    // 0x800ADA18: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x800ADA1C: sh          $s2, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r18;
    // 0x800ADA20: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA24: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800ADA2C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800ADA30: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800ADA34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADA38: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800ADA3C: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x800ADA40: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ADA44: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA48: sh          $s1, 0xDB0($at)
    MEM_H(0XDB0, ctx->r1) = ctx->r17;
    // 0x800ADA4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800ADA50: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800ADA54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADA58: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800ADA5C: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800ADA60: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800ADA64: sh          $s0, 0xDAE($at)
    MEM_H(0XDAE, ctx->r1) = ctx->r16;
    // 0x800ADA68: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800ADA6C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800ADA70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADA74: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800ADA78: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800ADA7C: sh          $s0, 0xDAC($at)
    MEM_H(0XDAC, ctx->r1) = ctx->r16;
    // 0x800ADA80: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA84: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA88: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x800ADA8C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800ADA90: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x800ADA94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800ADA98: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800ADA9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADAA0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ADAA4: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x800ADAA8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800ADAAC: addiu       $t4, $t4, 0xDA8
    ctx->r12 = ADD32(ctx->r12, 0XDA8);
    // 0x800ADAB0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800ADAB4: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800ADAB8: swc1        $f6, 0xDBC($at)
    MEM_W(0XDBC, ctx->r1) = ctx->f6.u32l;
    // 0x800ADABC: lwc1        $f8, 0x14($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800ADAC0: nop

    // 0x800ADAC4: swc1        $f8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f8.u32l;
    // 0x800ADAC8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800ADACC: nop

    // 0x800ADAD0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800ADAD4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800ADAD8: bne         $at, $zero, L_800AD8E8
    if (ctx->r1 != 0) {
        // 0x800ADADC: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_800AD8E8;
    }
    // 0x800ADADC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800ADAE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ADAE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADAE8: sw          $t8, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = ctx->r24;
    // 0x800ADAEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADAF0: sw          $zero, 0x128C($at)
    MEM_W(0X128C, ctx->r1) = 0;
    // 0x800ADAF4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800ADAF8: addiu       $a0, $a0, -0x23B0
    ctx->r4 = ADD32(ctx->r4, -0X23B0);
    // 0x800ADAFC: jal         0x800C0780
    // 0x800ADB00: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    Thread_CreateExtended(rdram, ctx);
        goto after_0;
    // 0x800ADB00: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x800ADB04: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800ADB08: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADB0C: nop

    // 0x800ADB10: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x800ADB14: nop

    // 0x800ADB18: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800ADB1C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADB20: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800ADB24: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800ADB28: addiu       $t1, $t1, 0x3DF8
    ctx->r9 = ADD32(ctx->r9, 0X3DF8);
    // 0x800ADB2C: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x800ADB30: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800ADB34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADB38: sh          $t4, 0x16A0($at)
    MEM_H(0X16A0, ctx->r1) = ctx->r12;
    // 0x800ADB3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ADB40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADB44: sh          $t5, 0x16C8($at)
    MEM_H(0X16C8, ctx->r1) = ctx->r13;
    // 0x800ADB48: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800ADB4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADB50: sh          $t6, 0x19B0($at)
    MEM_H(0X19B0, ctx->r1) = ctx->r14;
    // 0x800ADB54: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADB58: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800ADB5C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x800ADB60: jal         0x800C1154
    // 0x800ADB64: nop

    func_800C1154(rdram, ctx);
        goto after_1;
    // 0x800ADB64: nop

    after_1:
    // 0x800ADB68: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800ADB6C: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADB70: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800ADB74: addiu       $a2, $a2, 0x16A0
    ctx->r6 = ADD32(ctx->r6, 0X16A0);
    // 0x800ADB78: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800ADB7C: jal         0x800C4720
    // 0x800ADB80: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800ADB80: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    after_2:
    // 0x800ADB84: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800ADB88: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADB8C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800ADB90: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800ADB94: addiu       $a2, $a2, 0x2540
    ctx->r6 = ADD32(ctx->r6, 0X2540);
    // 0x800ADB98: addiu       $a1, $a1, 0x127C
    ctx->r5 = ADD32(ctx->r5, 0X127C);
    // 0x800ADB9C: jal         0x800C51D0
    // 0x800ADBA0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    osContInit_recomp(rdram, ctx);
        goto after_3;
    // 0x800ADBA0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_3:
    // 0x800ADBA4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800ADBA8: addiu       $t8, $t8, 0x2540
    ctx->r24 = ADD32(ctx->r24, 0X2540);
    // 0x800ADBAC: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x800ADBB0: nop

    // 0x800ADBB4: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800ADBB8: beq         $t0, $zero, L_800ADC1C
    if (ctx->r8 == 0) {
        // 0x800ADBBC: nop
    
            goto L_800ADC1C;
    }
    // 0x800ADBBC: nop

    // 0x800ADBC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADBC4: sw          $zero, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = 0;
    // 0x800ADBC8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800ADBCC: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADBD0: jal         0x800C5590
    // 0x800ADBD4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    osContStartReadData_recomp(rdram, ctx);
        goto after_4;
    // 0x800ADBD4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_4:
    // 0x800ADBD8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADBDC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800ADBE0: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x800ADBE4: jal         0x800C143C
    // 0x800ADBE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_5;
    // 0x800ADBE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800ADBEC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800ADBF0: jal         0x800C5654
    // 0x800ADBF4: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    osContGetReadData_recomp(rdram, ctx);
        goto after_6;
    // 0x800ADBF4: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    after_6:
    // 0x800ADBF8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800ADBFC: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADC00: jal         0x800AE0EC
    // 0x800ADC04: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    ContPak_InitializePak(rdram, ctx);
        goto after_7;
    // 0x800ADC04: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_7:
    // 0x800ADC08: jal         0x800AE40C
    // 0x800ADC0C: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_8;
    // 0x800ADC0C: nop

    after_8:
    // 0x800ADC10: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800ADC14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADC18: sw          $t3, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = ctx->r11;
L_800ADC1C:
    // 0x800ADC1C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADC20: nop

    // 0x800ADC24: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x800ADC28: jal         0x800C0C8C
    // 0x800ADC2C: nop

    Thread_Start(rdram, ctx);
        goto after_9;
    // 0x800ADC2C: nop

    after_9:
    // 0x800ADC30: b           L_800ADC38
    // 0x800ADC34: nop

        goto L_800ADC38;
    // 0x800ADC34: nop

L_800ADC38:
    // 0x800ADC38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800ADC3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ADC40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADC44: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800ADC48: jr          $ra
    // 0x800ADC4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800ADC4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80086600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086600: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80086608: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008660C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80086610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80086614: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80086618: nop

    // 0x8008661C: lh          $s0, 0xC14($t6)
    ctx->r16 = MEM_H(ctx->r14, 0XC14);
    // 0x80086620: nop

    // 0x80086624: beq         $s0, $zero, L_80086640
    if (ctx->r16 == 0) {
        // 0x80086628: nop
    
            goto L_80086640;
    }
    // 0x80086628: nop

    // 0x8008662C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086630: beq         $s0, $at, L_800866D8
    if (ctx->r16 == ctx->r1) {
        // 0x80086634: nop
    
            goto L_800866D8;
    }
    // 0x80086634: nop

    // 0x80086638: b           L_800867C4
    // 0x8008663C: nop

        goto L_800867C4;
    // 0x8008663C: nop

L_80086640:
    // 0x80086640: jal         0x800AEBF4
    // 0x80086644: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_0;
    // 0x80086644: nop

    after_0:
    // 0x80086648: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008664C: nop

    // 0x80086650: sw          $v0, 0xC00($t7)
    MEM_W(0XC00, ctx->r15) = ctx->r2;
    // 0x80086654: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80086658: nop

    // 0x8008665C: lw          $t9, 0xC00($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC00);
    // 0x80086660: nop

    // 0x80086664: bltz        $t9, L_800866A0
    if (SIGNED(ctx->r25) < 0) {
        // 0x80086668: nop
    
            goto L_800866A0;
    }
    // 0x80086668: nop

    // 0x8008666C: slti        $at, $t9, 0x1000
    ctx->r1 = SIGNED(ctx->r25) < 0X1000 ? 1 : 0;
    // 0x80086670: beq         $at, $zero, L_800866A0
    if (ctx->r1 == 0) {
        // 0x80086674: nop
    
            goto L_800866A0;
    }
    // 0x80086674: nop

    // 0x80086678: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008667C: nop

    // 0x80086680: lw          $a0, 0xC00($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC00);
    // 0x80086684: jal         0x800AE5F0
    // 0x80086688: nop

    ContPak_SetFileDeleteParams(rdram, ctx);
        goto after_1;
    // 0x80086688: nop

    after_1:
    // 0x8008668C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80086690: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80086694: sh          $t1, 0xC14($t2)
    MEM_H(0XC14, ctx->r10) = ctx->r9;
    // 0x80086698: b           L_800867C4
    // 0x8008669C: nop

        goto L_800867C4;
    // 0x8008669C: nop

L_800866A0:
    // 0x800866A0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800866A4: nop

    // 0x800866A8: lw          $t4, 0xC00($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC00);
    // 0x800866AC: nop

    // 0x800866B0: slti        $at, $t4, 0x1000
    ctx->r1 = SIGNED(ctx->r12) < 0X1000 ? 1 : 0;
    // 0x800866B4: bne         $at, $zero, L_800866D0
    if (ctx->r1 != 0) {
        // 0x800866B8: nop
    
            goto L_800866D0;
    }
    // 0x800866B8: nop

    // 0x800866BC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800866C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800866C4: sh          $t5, 0xBEC($t6)
    MEM_H(0XBEC, ctx->r14) = ctx->r13;
    // 0x800866C8: b           L_800867E0
    // 0x800866CC: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800867E0;
    // 0x800866CC: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_800866D0:
    // 0x800866D0: b           L_800867C4
    // 0x800866D4: nop

        goto L_800867C4;
    // 0x800866D4: nop

L_800866D8:
    // 0x800866D8: jal         0x800AE7FC
    // 0x800866DC: nop

    ContPak_GetDeleteFileResult(rdram, ctx);
        goto after_2;
    // 0x800866DC: nop

    after_2:
    // 0x800866E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800866E4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800866E8: nop

    // 0x800866EC: bne         $t7, $zero, L_8008679C
    if (ctx->r15 != 0) {
        // 0x800866F0: nop
    
            goto L_8008679C;
    }
    // 0x800866F0: nop

    // 0x800866F4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800866F8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800866FC: lh          $t9, 0xBE8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XBE8);
    // 0x80086700: addiu       $t1, $t1, 0x7AE8
    ctx->r9 = ADD32(ctx->r9, 0X7AE8);
    // 0x80086704: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80086708: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8008670C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80086710: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80086714: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80086718: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8008671C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086720: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80086724: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80086728: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x8008672C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80086730: nop

    // 0x80086734: lh          $t6, 0xBE8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBE8);
    // 0x80086738: nop

    // 0x8008673C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80086740: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80086744: lw          $t9, 0xC04($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC04);
    // 0x80086748: nop

    // 0x8008674C: beq         $t9, $zero, L_80086794
    if (ctx->r25 == 0) {
        // 0x80086750: nop
    
            goto L_80086794;
    }
    // 0x80086750: nop

    // 0x80086754: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80086758: nop

    // 0x8008675C: lh          $t1, 0xBE8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XBE8);
    // 0x80086760: nop

    // 0x80086764: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80086768: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008676C: lw          $a0, 0xC04($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC04);
    // 0x80086770: jal         0x800BC980
    // 0x80086774: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80086774: nop

    after_3:
    // 0x80086778: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008677C: nop

    // 0x80086780: lh          $t6, 0xBE8($t2)
    ctx->r14 = MEM_H(ctx->r10, 0XBE8);
    // 0x80086784: nop

    // 0x80086788: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8008678C: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x80086790: sw          $zero, 0xC04($t7)
    MEM_W(0XC04, ctx->r15) = 0;
L_80086794:
    // 0x80086794: b           L_800867E0
    // 0x80086798: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_800867E0;
    // 0x80086798: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8008679C:
    // 0x8008679C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800867A0: nop

    // 0x800867A4: slti        $at, $t8, 0x1000
    ctx->r1 = SIGNED(ctx->r24) < 0X1000 ? 1 : 0;
    // 0x800867A8: bne         $at, $zero, L_800867C4
    if (ctx->r1 != 0) {
        // 0x800867AC: nop
    
            goto L_800867C4;
    }
    // 0x800867AC: nop

    // 0x800867B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800867B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800867B8: sh          $t9, 0xBEC($t1)
    MEM_H(0XBEC, ctx->r9) = ctx->r25;
    // 0x800867BC: b           L_800867E0
    // 0x800867C0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800867E0;
    // 0x800867C0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_800867C4:
    // 0x800867C4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800867C8: nop

    // 0x800867CC: lh          $v0, 0x4($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X4);
    // 0x800867D0: b           L_800867E0
    // 0x800867D4: nop

        goto L_800867E0;
    // 0x800867D4: nop

    // 0x800867D8: b           L_800867E0
    // 0x800867DC: nop

        goto L_800867E0;
    // 0x800867DC: nop

L_800867E0:
    // 0x800867E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800867E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800867E8: jr          $ra
    // 0x800867EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800867EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80065F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065F38: jal         0x80061348
    // 0x80065F3C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065F3C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80065F40: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065F44: b           L_80065F54
    // 0x80065F48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065F54;
    // 0x80065F48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065F4C: b           L_80065F54
    // 0x80065F50: nop

        goto L_80065F54;
    // 0x80065F50: nop

L_80065F54:
    // 0x80065F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065F5C: jr          $ra
    // 0x80065F60: nop

    return;
    // 0x80065F60: nop

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
RECOMP_FUNC void func_80085D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085D34: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80085D38: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80085D3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80085D40: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085D44: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80085D48: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80085D4C: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80085D50: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80085D54: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80085D58: beq         $t0, $zero, L_80085EC8
    if (ctx->r8 == 0) {
        // 0x80085D5C: nop
    
            goto L_80085EC8;
    }
    // 0x80085D5C: nop

    // 0x80085D60: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80085D64: jal         0x8008A518
    // 0x80085D68: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80085D68: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80085D6C: beq         $v0, $zero, L_80085EC8
    if (ctx->r2 == 0) {
        // 0x80085D70: nop
    
            goto L_80085EC8;
    }
    // 0x80085D70: nop

    // 0x80085D74: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x80085D78: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80085D7C: bne         $t1, $at, L_80085D94
    if (ctx->r9 != ctx->r1) {
        // 0x80085D80: nop
    
            goto L_80085D94;
    }
    // 0x80085D80: nop

    // 0x80085D84: jal         0x8008CE48
    // 0x80085D88: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80085D88: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80085D8C: b           L_80085F10
    // 0x80085D90: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80085F10;
    // 0x80085D90: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80085D94:
    // 0x80085D94: lhu         $t2, 0x24($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X24);
    // 0x80085D98: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80085D9C: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085DA0: bne         $at, $zero, L_80085EC8
    if (ctx->r1 != 0) {
        // 0x80085DA4: nop
    
            goto L_80085EC8;
    }
    // 0x80085DA4: nop

    // 0x80085DA8: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80085DAC: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085DB0: beq         $at, $zero, L_80085EC8
    if (ctx->r1 == 0) {
        // 0x80085DB4: nop
    
            goto L_80085EC8;
    }
    // 0x80085DB4: nop

    // 0x80085DB8: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x80085DBC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80085DC0: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80085DC4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80085DC8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80085DCC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80085DD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80085DD4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80085DD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085DDC: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x80085DE0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80085DE4: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80085DE8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80085DEC: sh          $t4, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r12;
    // 0x80085DF0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80085DF4: nop

    // 0x80085DF8: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x80085DFC: nop

    // 0x80085E00: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80085E04: beq         $t1, $zero, L_80085EB4
    if (ctx->r9 == 0) {
        // 0x80085E08: nop
    
            goto L_80085EB4;
    }
    // 0x80085E08: nop

    // 0x80085E0C: lhu         $t2, 0x1E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1E);
    // 0x80085E10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80085E14: sh          $t2, 0x7A16($at)
    MEM_H(0X7A16, ctx->r1) = ctx->r10;
    // 0x80085E18: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80085E1C: nop

    // 0x80085E20: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80085E24: nop

    // 0x80085E28: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x80085E2C: beq         $t5, $zero, L_80085E90
    if (ctx->r13 == 0) {
        // 0x80085E30: nop
    
            goto L_80085E90;
    }
    // 0x80085E30: nop

    // 0x80085E34: jal         0x8008CE48
    // 0x80085E38: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80085E38: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x80085E3C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80085E40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085E44: addiu       $a0, $a0, -0x6110
    ctx->r4 = ADD32(ctx->r4, -0X6110);
    // 0x80085E48: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80085E4C: jal         0x8008BE0C
    // 0x80085E50: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    func_8008BE0C(rdram, ctx);
        goto after_3;
    // 0x80085E50: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_3:
    // 0x80085E54: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80085E58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085E5C: addiu       $a0, $a0, -0x611C
    ctx->r4 = ADD32(ctx->r4, -0X611C);
    // 0x80085E60: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80085E64: jal         0x8008BE0C
    // 0x80085E68: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    func_8008BE0C(rdram, ctx);
        goto after_4;
    // 0x80085E68: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    after_4:
    // 0x80085E6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80085E70: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80085E74: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80085E78: jal         0x800BCFCC
    // 0x80085E7C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x80085E7C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_5:
    // 0x80085E80: b           L_80085F10
    // 0x80085E84: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_80085F10;
    // 0x80085E84: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x80085E88: b           L_80085EAC
    // 0x80085E8C: nop

        goto L_80085EAC;
    // 0x80085E8C: nop

L_80085E90:
    // 0x80085E90: jal         0x8008CE48
    // 0x80085E94: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80085E94: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_6:
    // 0x80085E98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80085E9C: jal         0x8008C0D8
    // 0x80085EA0: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8008C0D8(rdram, ctx);
        goto after_7;
    // 0x80085EA0: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_7:
    // 0x80085EA4: b           L_80085F10
    // 0x80085EA8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_80085F10;
    // 0x80085EA8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80085EAC:
    // 0x80085EAC: b           L_80085EC8
    // 0x80085EB0: nop

        goto L_80085EC8;
    // 0x80085EB0: nop

L_80085EB4:
    // 0x80085EB4: jal         0x8008CE48
    // 0x80085EB8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80085EB8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_8:
    // 0x80085EBC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80085EC0: jal         0x8008A730
    // 0x80085EC4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_9;
    // 0x80085EC4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_9:
L_80085EC8:
    // 0x80085EC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085ECC: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x80085ED0: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x80085ED4: nop

    // 0x80085ED8: and         $t9, $t6, $t7
    ctx->r25 = ctx->r14 & ctx->r15;
    // 0x80085EDC: beq         $t9, $zero, L_80085EF4
    if (ctx->r25 == 0) {
        // 0x80085EE0: nop
    
            goto L_80085EF4;
    }
    // 0x80085EE0: nop

    // 0x80085EE4: jal         0x8008CE48
    // 0x80085EE8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80085EE8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_10:
    // 0x80085EEC: b           L_80085F10
    // 0x80085EF0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80085F10;
    // 0x80085EF0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80085EF4:
    // 0x80085EF4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80085EF8: nop

    // 0x80085EFC: lh          $v0, 0x4($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X4);
    // 0x80085F00: b           L_80085F10
    // 0x80085F04: nop

        goto L_80085F10;
    // 0x80085F04: nop

    // 0x80085F08: b           L_80085F10
    // 0x80085F0C: nop

        goto L_80085F10;
    // 0x80085F0C: nop

L_80085F10:
    // 0x80085F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085F14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80085F18: jr          $ra
    // 0x80085F1C: nop

    return;
    // 0x80085F1C: nop

;}
RECOMP_FUNC void func_8001CF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF70: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001CF74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CF78: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8001CF7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001CF80: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001CF84: jal         0x8008EAA8
    // 0x8001CF88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001CF88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001CF8C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8001CF90: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CF94: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001CF98: jal         0x8008ECE4
    // 0x8001CF9C: addiu       $a0, $a0, -0x26A4
    ctx->r4 = ADD32(ctx->r4, -0X26A4);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CF9C: addiu       $a0, $a0, -0x26A4
    ctx->r4 = ADD32(ctx->r4, -0X26A4);
    after_1:
    // 0x8001CFA0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001CFA4: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x8001CFA8: nop

    // 0x8001CFAC: beq         $s0, $zero, L_8001CFC8
    if (ctx->r16 == 0) {
        // 0x8001CFB0: nop
    
            goto L_8001CFC8;
    }
    // 0x8001CFB0: nop

    // 0x8001CFB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CFB8: beq         $s0, $at, L_8001D1D4
    if (ctx->r16 == ctx->r1) {
        // 0x8001CFBC: nop
    
            goto L_8001D1D4;
    }
    // 0x8001CFBC: nop

    // 0x8001CFC0: b           L_8001DB3C
    // 0x8001CFC4: nop

        goto L_8001DB3C;
    // 0x8001CFC4: nop

L_8001CFC8:
    // 0x8001CFC8: jal         0x800BC6EC
    // 0x8001CFCC: addiu       $a0, $zero, 0xB00
    ctx->r4 = ADD32(0, 0XB00);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8001CFCC: addiu       $a0, $zero, 0xB00
    ctx->r4 = ADD32(0, 0XB00);
    after_2:
    // 0x8001CFD0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001CFD4: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8001CFD8: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8001CFDC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CFE0: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001CFE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001CFE8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001CFEC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001CFF0: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001CFF4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8001CFF8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001CFFC: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001D000: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8001D004: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8001D008: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001D00C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001D010: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001D014: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8001D018: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D01C: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001D020: sw          $zero, 0x10($t5)
    MEM_W(0X10, ctx->r13) = 0;
    // 0x8001D024: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8001D028:
    // 0x8001D028: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8001D02C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001D030: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001D034: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001D038: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001D03C: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x8001D040: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001D044: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001D048: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8001D04C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001D050: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8001D054: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001D058: jal         0x80099E2C
    // 0x8001D05C: nop

    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x8001D05C: nop

    after_3:
    // 0x8001D060: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D064: nop

    // 0x8001D068: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x8001D06C: nop

    // 0x8001D070: ori         $t3, $t2, 0x10C
    ctx->r11 = ctx->r10 | 0X10C;
    // 0x8001D074: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
    // 0x8001D078: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D07C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001D080: sh          $t4, 0x116($t5)
    MEM_H(0X116, ctx->r13) = ctx->r12;
    // 0x8001D084: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8001D088: lw          $t6, -0x4D48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D48);
    // 0x8001D08C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D090: nop

    // 0x8001D094: sw          $t6, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r14;
    // 0x8001D098: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001D09C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001D0A0: addiu       $t7, $t7, -0x4B18
    ctx->r15 = ADD32(ctx->r15, -0X4B18);
    // 0x8001D0A4: sw          $t7, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r15;
    // 0x8001D0A8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D0AC: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x8001D0B0: sw          $t0, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r8;
    // 0x8001D0B4: jal         0x800BC6EC
    // 0x8001D0B8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8001D0B8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_4:
    // 0x8001D0BC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D0C0: nop

    // 0x8001D0C4: sw          $v0, 0x12C($t3)
    MEM_W(0X12C, ctx->r11) = ctx->r2;
    // 0x8001D0C8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D0CC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8001D0D0: lw          $t4, 0x12C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X12C);
    // 0x8001D0D4: nop

    // 0x8001D0D8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_8001D0DC:
    // 0x8001D0DC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001D0E0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001D0E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001D0E8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001D0EC: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x8001D0F0: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8001D0F4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8001D0F8: nop

    // 0x8001D0FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8001D100: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8001D104: bne         $at, $zero, L_8001D0DC
    if (ctx->r1 != 0) {
        // 0x8001D108: sw          $t0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r8;
            goto L_8001D0DC;
    }
    // 0x8001D108: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8001D10C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001D110: nop

    // 0x8001D114: bne         $t2, $zero, L_8001D164
    if (ctx->r10 != 0) {
        // 0x8001D118: nop
    
            goto L_8001D164;
    }
    // 0x8001D118: nop

    // 0x8001D11C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001D120: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D124: nop

    // 0x8001D128: swc1        $f6, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f6.u32l;
    // 0x8001D12C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001D130: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D134: nop

    // 0x8001D138: swc1        $f8, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f8.u32l;
    // 0x8001D13C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D140: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D144: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8001D148: nop

    // 0x8001D14C: swc1        $f10, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f10.u32l;
    // 0x8001D150: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D154: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001D158: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001D15C: b           L_8001D1B4
    // 0x8001D160: swc1        $f16, 0xE4($t6)
    MEM_W(0XE4, ctx->r14) = ctx->f16.u32l;
        goto L_8001D1B4;
    // 0x8001D160: swc1        $f16, 0xE4($t6)
    MEM_W(0XE4, ctx->r14) = ctx->f16.u32l;
L_8001D164:
    // 0x8001D164: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D168: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D16C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D170: nop

    // 0x8001D174: swc1        $f18, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f18.u32l;
    // 0x8001D178: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D17C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D180: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D184: nop

    // 0x8001D188: swc1        $f4, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f4.u32l;
    // 0x8001D18C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001D190: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D194: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8001D198: nop

    // 0x8001D19C: swc1        $f6, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f6.u32l;
    // 0x8001D1A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D1A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D1A8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001D1AC: nop

    // 0x8001D1B0: swc1        $f8, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->f8.u32l;
L_8001D1B4:
    // 0x8001D1B4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8001D1B8: nop

    // 0x8001D1BC: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8001D1C0: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8001D1C4: bne         $at, $zero, L_8001D028
    if (ctx->r1 != 0) {
        // 0x8001D1C8: sw          $t2, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r10;
            goto L_8001D028;
    }
    // 0x8001D1C8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8001D1CC: b           L_8001DB44
    // 0x8001D1D0: nop

        goto L_8001DB44;
    // 0x8001D1D0: nop

L_8001D1D4:
    // 0x8001D1D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001D1D8: jal         0x8008EAA8
    // 0x8001D1DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_5;
    // 0x8001D1DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8001D1E0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001D1E4: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001D1E8: lw          $a1, 0x10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X10);
    // 0x8001D1EC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001D1F0: jal         0x8008ECE4
    // 0x8001D1F4: addiu       $a0, $a0, -0x2698
    ctx->r4 = ADD32(ctx->r4, -0X2698);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8001D1F4: addiu       $a0, $a0, -0x2698
    ctx->r4 = ADD32(ctx->r4, -0X2698);
    after_6:
    // 0x8001D1F8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D1FC: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D200: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x8001D204: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x8001D208: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001D20C: jal         0x8008ECE4
    // 0x8001D210: addiu       $a0, $a0, -0x2684
    ctx->r4 = ADD32(ctx->r4, -0X2684);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001D210: addiu       $a0, $a0, -0x2684
    ctx->r4 = ADD32(ctx->r4, -0X2684);
    after_7:
    // 0x8001D214: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001D218: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8001D21C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D220: lhu         $t5, 0x1042($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1042);
    // 0x8001D224: lhu         $t6, 0x6($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X6);
    // 0x8001D228: nop

    // 0x8001D22C: and         $t8, $t6, $t5
    ctx->r24 = ctx->r14 & ctx->r13;
    // 0x8001D230: beq         $t8, $zero, L_8001D4D8
    if (ctx->r24 == 0) {
        // 0x8001D234: nop
    
            goto L_8001D4D8;
    }
    // 0x8001D234: nop

    // 0x8001D238: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8001D23C:
    // 0x8001D23C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8001D240: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D244: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8001D248: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8001D24C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001D250: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8001D254: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001D258: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8001D25C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8001D260: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8001D264: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8001D268: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D26C: nop

    // 0x8001D270: lw          $t4, 0x12C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X12C);
    // 0x8001D274: nop

    // 0x8001D278: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8001D27C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001D280: jal         0x80099E2C
    // 0x8001D284: nop

    func_80099E2C(rdram, ctx);
        goto after_8;
    // 0x8001D284: nop

    after_8:
    // 0x8001D288: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001D28C: nop

    // 0x8001D290: lw          $t5, 0xC0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC0);
    // 0x8001D294: nop

    // 0x8001D298: ori         $t8, $t5, 0x10C
    ctx->r24 = ctx->r13 | 0X10C;
    // 0x8001D29C: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x8001D2A0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001D2A8: sh          $t7, 0x116($t0)
    MEM_H(0X116, ctx->r8) = ctx->r15;
    // 0x8001D2AC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001D2B0: lw          $t9, -0x4D48($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D48);
    // 0x8001D2B4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2B8: nop

    // 0x8001D2BC: sw          $t9, 0x138($t2)
    MEM_W(0X138, ctx->r10) = ctx->r25;
    // 0x8001D2C0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2C4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8001D2C8: addiu       $t3, $t3, -0x4B18
    ctx->r11 = ADD32(ctx->r11, -0X4B18);
    // 0x8001D2CC: sw          $t3, 0x128($t1)
    MEM_W(0X128, ctx->r9) = ctx->r11;
    // 0x8001D2D0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2D4: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x8001D2D8: sw          $t4, 0xC8($t5)
    MEM_W(0XC8, ctx->r13) = ctx->r12;
    // 0x8001D2DC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001D2E0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2E4: nop

    // 0x8001D2E8: sw          $t8, 0x12C($t6)
    MEM_W(0X12C, ctx->r14) = ctx->r24;
    // 0x8001D2EC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2F0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8001D2F4: lw          $t0, 0x12C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X12C);
    // 0x8001D2F8: nop

    // 0x8001D2FC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_8001D300:
    // 0x8001D300: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8001D304: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001D308: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001D30C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001D310: addu        $t1, $t9, $t3
    ctx->r9 = ADD32(ctx->r25, ctx->r11);
    // 0x8001D314: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8001D318: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8001D31C: nop

    // 0x8001D320: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8001D324: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x8001D328: bne         $at, $zero, L_8001D300
    if (ctx->r1 != 0) {
        // 0x8001D32C: sw          $t5, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r13;
            goto L_8001D300;
    }
    // 0x8001D32C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8001D330: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D334: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D338: lw          $t6, 0x10($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X10);
    // 0x8001D33C: nop

    // 0x8001D340: bne         $t6, $zero, L_8001D3F8
    if (ctx->r14 != 0) {
        // 0x8001D344: nop
    
            goto L_8001D3F8;
    }
    // 0x8001D344: nop

    // 0x8001D348: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8001D34C: nop

    // 0x8001D350: bne         $t7, $zero, L_8001D3A0
    if (ctx->r15 != 0) {
        // 0x8001D354: nop
    
            goto L_8001D3A0;
    }
    // 0x8001D354: nop

    // 0x8001D358: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001D35C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D360: nop

    // 0x8001D364: swc1        $f16, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f16.u32l;
    // 0x8001D368: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001D36C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D370: nop

    // 0x8001D374: swc1        $f18, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f18.u32l;
    // 0x8001D378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D37C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D380: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001D384: nop

    // 0x8001D388: swc1        $f4, 0xEC($t9)
    MEM_W(0XEC, ctx->r25) = ctx->f4.u32l;
    // 0x8001D38C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D390: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D394: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D398: b           L_8001D3F0
    // 0x8001D39C: swc1        $f6, 0xE4($t3)
    MEM_W(0XE4, ctx->r11) = ctx->f6.u32l;
        goto L_8001D3F0;
    // 0x8001D39C: swc1        $f6, 0xE4($t3)
    MEM_W(0XE4, ctx->r11) = ctx->f6.u32l;
L_8001D3A0:
    // 0x8001D3A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D3A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D3A8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D3AC: nop

    // 0x8001D3B0: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    // 0x8001D3B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D3B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D3BC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8001D3C0: nop

    // 0x8001D3C4: swc1        $f10, 0xF0($t4)
    MEM_W(0XF0, ctx->r12) = ctx->f10.u32l;
    // 0x8001D3C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001D3CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001D3D0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D3D4: nop

    // 0x8001D3D8: swc1        $f16, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f16.u32l;
    // 0x8001D3DC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D3E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D3E4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D3E8: nop

    // 0x8001D3EC: swc1        $f18, 0xE4($t8)
    MEM_W(0XE4, ctx->r24) = ctx->f18.u32l;
L_8001D3F0:
    // 0x8001D3F0: b           L_8001D490
    // 0x8001D3F4: nop

        goto L_8001D490;
    // 0x8001D3F4: nop

L_8001D3F8:
    // 0x8001D3F8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8001D3FC: nop

    // 0x8001D400: bne         $t6, $zero, L_8001D44C
    if (ctx->r14 != 0) {
        // 0x8001D404: nop
    
            goto L_8001D44C;
    }
    // 0x8001D404: nop

    // 0x8001D408: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001D40C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8001D410: nop

    // 0x8001D414: swc1        $f4, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f4.u32l;
    // 0x8001D418: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001D41C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D420: nop

    // 0x8001D424: swc1        $f6, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f6.u32l;
    // 0x8001D428: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D42C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D430: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D434: nop

    // 0x8001D438: swc1        $f8, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f8.u32l;
    // 0x8001D43C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001D440: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001D444: b           L_8001D490
    // 0x8001D448: swc1        $f10, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->f10.u32l;
        goto L_8001D490;
    // 0x8001D448: swc1        $f10, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->f10.u32l;
L_8001D44C:
    // 0x8001D44C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001D450: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D454: nop

    // 0x8001D458: swc1        $f16, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f16.u32l;
    // 0x8001D45C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001D460: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D464: nop

    // 0x8001D468: swc1        $f18, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f18.u32l;
    // 0x8001D46C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001D470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D474: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8001D478: nop

    // 0x8001D47C: swc1        $f4, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f4.u32l;
    // 0x8001D480: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001D484: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D488: nop

    // 0x8001D48C: swc1        $f6, 0xE4($t5)
    MEM_W(0XE4, ctx->r13) = ctx->f6.u32l;
L_8001D490:
    // 0x8001D490: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8001D494: nop

    // 0x8001D498: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8001D49C: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8001D4A0: bne         $at, $zero, L_8001D23C
    if (ctx->r1 != 0) {
        // 0x8001D4A4: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8001D23C;
    }
    // 0x8001D4A4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8001D4A8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001D4AC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001D4B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001D4B4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001D4B8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001D4BC: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001D4C0: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8001D4C4: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x8001D4C8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D4CC: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D4D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001D4D4: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
L_8001D4D8:
    // 0x8001D4D8: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001D4DC: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8001D4E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D4E4: lhu         $t8, 0xFF4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XFF4);
    // 0x8001D4E8: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8001D4EC: nop

    // 0x8001D4F0: and         $t6, $t5, $t8
    ctx->r14 = ctx->r13 & ctx->r24;
    // 0x8001D4F4: beq         $t6, $zero, L_8001D514
    if (ctx->r14 == 0) {
        // 0x8001D4F8: nop
    
            goto L_8001D514;
    }
    // 0x8001D4F8: nop

    // 0x8001D4FC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D500: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001D504: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8001D508: nop

    // 0x8001D50C: xori        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 ^ 0X1;
    // 0x8001D510: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
L_8001D514:
    // 0x8001D514: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001D518: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001D51C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D520: lhu         $t1, 0x126C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X126C);
    // 0x8001D524: lhu         $t3, 0x6($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X6);
    // 0x8001D528: nop

    // 0x8001D52C: and         $t4, $t3, $t1
    ctx->r12 = ctx->r11 & ctx->r9;
    // 0x8001D530: beq         $t4, $zero, L_8001D550
    if (ctx->r12 == 0) {
        // 0x8001D534: nop
    
            goto L_8001D550;
    }
    // 0x8001D534: nop

    // 0x8001D538: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D53C: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001D540: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x8001D544: nop

    // 0x8001D548: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8001D54C: sw          $t6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r14;
L_8001D550:
    // 0x8001D550: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001D554: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001D558: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D55C: lhu         $t7, 0x11AC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X11AC);
    // 0x8001D560: lhu         $t2, 0x6($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X6);
    // 0x8001D564: nop

    // 0x8001D568: and         $t9, $t2, $t7
    ctx->r25 = ctx->r10 & ctx->r15;
    // 0x8001D56C: beq         $t9, $zero, L_8001D58C
    if (ctx->r25 == 0) {
        // 0x8001D570: nop
    
            goto L_8001D58C;
    }
    // 0x8001D570: nop

    // 0x8001D574: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001D578: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001D57C: lw          $t1, 0x8($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X8);
    // 0x8001D580: nop

    // 0x8001D584: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x8001D588: sw          $t4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r12;
L_8001D58C:
    // 0x8001D58C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001D590: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001D594: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D598: lhu         $t5, 0x1258($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1258);
    // 0x8001D59C: lhu         $t6, 0x6($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X6);
    // 0x8001D5A0: nop

    // 0x8001D5A4: and         $t0, $t6, $t5
    ctx->r8 = ctx->r14 & ctx->r13;
    // 0x8001D5A8: beq         $t0, $zero, L_8001D5C8
    if (ctx->r8 == 0) {
        // 0x8001D5AC: nop
    
            goto L_8001D5C8;
    }
    // 0x8001D5AC: nop

    // 0x8001D5B0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001D5B4: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001D5B8: lw          $t7, 0xC($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XC);
    // 0x8001D5BC: nop

    // 0x8001D5C0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8001D5C4: sw          $t9, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r25;
L_8001D5C8:
    // 0x8001D5C8: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001D5CC: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001D5D0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001D5D4: lhu         $t3, 0x1260($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1260);
    // 0x8001D5D8: lhu         $t4, 0x6($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X6);
    // 0x8001D5DC: nop

    // 0x8001D5E0: and         $t8, $t4, $t3
    ctx->r24 = ctx->r12 & ctx->r11;
    // 0x8001D5E4: beq         $t8, $zero, L_8001D604
    if (ctx->r24 == 0) {
        // 0x8001D5E8: nop
    
            goto L_8001D604;
    }
    // 0x8001D5E8: nop

    // 0x8001D5EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001D5F0: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001D5F4: lw          $t5, 0xC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC);
    // 0x8001D5F8: nop

    // 0x8001D5FC: addiu       $t0, $t5, -0x1
    ctx->r8 = ADD32(ctx->r13, -0X1);
    // 0x8001D600: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
L_8001D604:
    // 0x8001D604: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D608: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001D60C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8001D610: nop

    // 0x8001D614: bgez        $t9, L_8001D628
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001D618: nop
    
            goto L_8001D628;
    }
    // 0x8001D618: nop

    // 0x8001D61C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001D620: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001D624: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
L_8001D628:
    // 0x8001D628: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D62C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D630: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x8001D634: nop

    // 0x8001D638: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8001D63C: bne         $at, $zero, L_8001D654
    if (ctx->r1 != 0) {
        // 0x8001D640: nop
    
            goto L_8001D654;
    }
    // 0x8001D640: nop

    // 0x8001D644: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D648: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D64C: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8001D650: sw          $t3, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r11;
L_8001D654:
    // 0x8001D654: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D658: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001D65C: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x8001D660: nop

    // 0x8001D664: bgtz        $t0, L_8001D67C
    if (SIGNED(ctx->r8) > 0) {
        // 0x8001D668: nop
    
            goto L_8001D67C;
    }
    // 0x8001D668: nop

    // 0x8001D66C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D670: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001D674: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D678: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
L_8001D67C:
    // 0x8001D67C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001D680: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001D684: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8001D688: nop

    // 0x8001D68C: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x8001D690: bne         $at, $zero, L_8001D6A8
    if (ctx->r1 != 0) {
        // 0x8001D694: nop
    
            goto L_8001D6A8;
    }
    // 0x8001D694: nop

    // 0x8001D698: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001D69C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001D6A0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8001D6A4: sw          $t1, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r9;
L_8001D6A8:
    // 0x8001D6A8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001D6AC: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001D6B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D6B4: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001D6B8: lhu         $t8, 0x6($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X6);
    // 0x8001D6BC: nop

    // 0x8001D6C0: and         $t0, $t8, $t5
    ctx->r8 = ctx->r24 & ctx->r13;
    // 0x8001D6C4: beq         $t0, $zero, L_8001D6E4
    if (ctx->r8 == 0) {
        // 0x8001D6C8: nop
    
            goto L_8001D6E4;
    }
    // 0x8001D6C8: nop

    // 0x8001D6CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001D6D0: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001D6D4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8001D6D8: nop

    // 0x8001D6DC: xori        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 ^ 0X1;
    // 0x8001D6E0: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
L_8001D6E4:
    // 0x8001D6E4: jal         0x800C1680
    // 0x8001D6E8: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_9;
    // 0x8001D6E8: nop

    after_9:
    // 0x8001D6EC: jal         0x8009A22C
    // 0x8001D6F0: nop

    func_8009A22C(rdram, ctx);
        goto after_10;
    // 0x8001D6F0: nop

    after_10:
    // 0x8001D6F4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001D6F8: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001D6FC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001D700: lhu         $t4, 0x10F2($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X10F2);
    // 0x8001D704: lhu         $t1, 0x4($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X4);
    // 0x8001D708: nop

    // 0x8001D70C: and         $t3, $t1, $t4
    ctx->r11 = ctx->r9 & ctx->r12;
    // 0x8001D710: bne         $t3, $zero, L_8001D758
    if (ctx->r11 != 0) {
        // 0x8001D714: nop
    
            goto L_8001D758;
    }
    // 0x8001D714: nop

    // 0x8001D718: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D71C: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D720: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8001D724: nop

    // 0x8001D728: beq         $t5, $zero, L_8001D750
    if (ctx->r13 == 0) {
        // 0x8001D72C: nop
    
            goto L_8001D750;
    }
    // 0x8001D72C: nop

    // 0x8001D730: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8001D734: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D738: jal         0x800C25B8
    // 0x8001D73C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_11;
    // 0x8001D73C: nop

    after_11:
    // 0x8001D740: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8001D744: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D748: jal         0x800C23E8
    // 0x8001D74C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_12;
    // 0x8001D74C: nop

    after_12:
L_8001D750:
    // 0x8001D750: b           L_8001D780
    // 0x8001D754: nop

        goto L_8001D780;
    // 0x8001D754: nop

L_8001D758:
    // 0x8001D758: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001D75C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001D760: lwc1        $f12, 0x14($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8001D764: jal         0x800C25B8
    // 0x8001D768: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_13;
    // 0x8001D768: nop

    after_13:
    // 0x8001D76C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001D770: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001D774: lwc1        $f12, 0x10($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8001D778: jal         0x800C23E8
    // 0x8001D77C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_14;
    // 0x8001D77C: nop

    after_14:
L_8001D780:
    // 0x8001D780: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8001D784:
    // 0x8001D784: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001D788: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001D78C: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8001D790: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x8001D794: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8001D798: addiu       $t9, $t9, 0x2618
    ctx->r25 = ADD32(ctx->r25, 0X2618);
    // 0x8001D79C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8001D7A0: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x8001D7A4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x8001D7A8: addu        $t4, $t6, $t1
    ctx->r12 = ADD32(ctx->r14, ctx->r9);
    // 0x8001D7AC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8001D7B0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D7B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001D7B8: lwc1        $f8, 0xF0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XF0);
    // 0x8001D7BC: nop

    // 0x8001D7C0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8001D7C4: nop

    // 0x8001D7C8: bc1t        L_8001D7F0
    if (c1cs) {
        // 0x8001D7CC: nop
    
            goto L_8001D7F0;
    }
    // 0x8001D7CC: nop

    // 0x8001D7D0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D7D4: nop

    // 0x8001D7D8: lwc1        $f16, 0xF0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8001D7DC: lwc1        $f18, 0xEC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XEC);
    // 0x8001D7E0: nop

    // 0x8001D7E4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001D7E8: b           L_8001D800
    // 0x8001D7EC: swc1        $f4, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f4.u32l;
        goto L_8001D800;
    // 0x8001D7EC: swc1        $f4, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f4.u32l;
L_8001D7F0:
    // 0x8001D7F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001D7F4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D7F8: nop

    // 0x8001D7FC: swc1        $f6, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f6.u32l;
L_8001D800:
    // 0x8001D800: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D804: nop

    // 0x8001D808: lw          $t7, 0x12C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X12C);
    // 0x8001D80C: nop

    // 0x8001D810: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8001D814: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001D818: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D81C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8001D820: nop

    // 0x8001D824: swc1        $f8, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f8.u32l;
    // 0x8001D828: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D82C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D830: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x8001D834: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001D838: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x8001D83C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8001D840: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001D844: jal         0x800BCFCC
    // 0x8001D848: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_15;
    // 0x8001D848: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_15:
    // 0x8001D84C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8001D850: nop

    // 0x8001D854: bne         $t3, $zero, L_8001D934
    if (ctx->r11 != 0) {
        // 0x8001D858: nop
    
            goto L_8001D934;
    }
    // 0x8001D858: nop

    // 0x8001D85C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D860: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001D864: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8001D868: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x8001D86C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001D870: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8001D874: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8001D878: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001D87C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8001D880: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8001D884: nop

    // 0x8001D888: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8001D88C: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x8001D890: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D894: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D898: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x8001D89C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001D8A0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8001D8A4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8001D8A8: addu        $t0, $t6, $t3
    ctx->r8 = ADD32(ctx->r14, ctx->r11);
    // 0x8001D8AC: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8001D8B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D8B4: nop

    // 0x8001D8B8: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8001D8BC: nop

    // 0x8001D8C0: bc1f        L_8001D8E0
    if (!c1cs) {
        // 0x8001D8C4: nop
    
            goto L_8001D8E0;
    }
    // 0x8001D8C4: nop

    // 0x8001D8C8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D8CC: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D8D0: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x8001D8D4: nop

    // 0x8001D8D8: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x8001D8DC: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
L_8001D8E0:
    // 0x8001D8E0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001D8E4: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001D8E8: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8001D8EC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001D8F0: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8001D8F4: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8001D8F8: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x8001D8FC: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8001D900: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D904: nop

    // 0x8001D908: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8001D90C: nop

    // 0x8001D910: bc1f        L_8001D92C
    if (!c1cs) {
        // 0x8001D914: nop
    
            goto L_8001D92C;
    }
    // 0x8001D914: nop

    // 0x8001D918: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001D91C: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001D920: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x8001D924: nop

    // 0x8001D928: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
L_8001D92C:
    // 0x8001D92C: b           L_8001D958
    // 0x8001D930: nop

        goto L_8001D958;
    // 0x8001D930: nop

L_8001D934:
    // 0x8001D934: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D938: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D93C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8001D940: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8001D944: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001D948: lwc1        $f18, 0xE8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x8001D94C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8001D950: addu        $t2, $t5, $t1
    ctx->r10 = ADD32(ctx->r13, ctx->r9);
    // 0x8001D954: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
L_8001D958:
    // 0x8001D958: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8001D95C: nop

    // 0x8001D960: beq         $t4, $zero, L_8001D9F0
    if (ctx->r12 == 0) {
        // 0x8001D964: nop
    
            goto L_8001D9F0;
    }
    // 0x8001D964: nop

    // 0x8001D968: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001D96C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001D970: lwc1        $f4, 0xD0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8001D974: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001D978: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001D97C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001D980: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8001D984: nop

    // 0x8001D988: bc1f        L_8001D9B4
    if (!c1cs) {
        // 0x8001D98C: nop
    
            goto L_8001D9B4;
    }
    // 0x8001D98C: nop

    // 0x8001D990: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D994: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001D998: lwc1        $f16, 0xD0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x8001D99C: lwc1        $f19, -0x2490($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2490);
    // 0x8001D9A0: lwc1        $f18, -0x248C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X248C);
    // 0x8001D9A4: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8001D9A8: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8001D9AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001D9B0: swc1        $f6, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f6.u32l;
L_8001D9B4:
    // 0x8001D9B4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D9B8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001D9BC: lwc1        $f8, 0xD0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8001D9C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001D9C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001D9C8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8001D9CC: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8001D9D0: nop

    // 0x8001D9D4: bc1f        L_8001D9F0
    if (!c1cs) {
        // 0x8001D9D8: nop
    
            goto L_8001D9F0;
    }
    // 0x8001D9D8: nop

    // 0x8001D9DC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D9E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D9E4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8001D9E8: nop

    // 0x8001D9EC: swc1        $f18, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f18.u32l;
L_8001D9F0:
    // 0x8001D9F0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D9F4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001D9F8: lwc1        $f4, 0xE4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XE4);
    // 0x8001D9FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001DA00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001DA04: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001DA08: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8001DA0C: nop

    // 0x8001DA10: bc1f        L_8001DA3C
    if (!c1cs) {
        // 0x8001DA14: nop
    
            goto L_8001DA3C;
    }
    // 0x8001DA14: nop

    // 0x8001DA18: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001DA20: lwc1        $f16, 0xE4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XE4);
    // 0x8001DA24: lwc1        $f19, -0x2488($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2488);
    // 0x8001DA28: lwc1        $f18, -0x2484($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2484);
    // 0x8001DA2C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8001DA30: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8001DA34: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001DA38: swc1        $f6, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->f6.u32l;
L_8001DA3C:
    // 0x8001DA3C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA40: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001DA44: lwc1        $f8, 0xE4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XE4);
    // 0x8001DA48: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001DA4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001DA50: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8001DA54: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8001DA58: nop

    // 0x8001DA5C: bc1f        L_8001DA78
    if (!c1cs) {
        // 0x8001DA60: nop
    
            goto L_8001DA78;
    }
    // 0x8001DA60: nop

    // 0x8001DA64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001DA68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001DA6C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA70: nop

    // 0x8001DA74: swc1        $f18, 0xE4($t1)
    MEM_W(0XE4, ctx->r9) = ctx->f18.u32l;
L_8001DA78:
    // 0x8001DA78: jal         0x800C1680
    // 0x8001DA7C: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_16;
    // 0x8001DA7C: nop

    after_16:
    // 0x8001DA80: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA84: nop

    // 0x8001DA88: lwc1        $f12, 0xF0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XF0);
    // 0x8001DA8C: jal         0x800C2780
    // 0x8001DA90: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_17;
    // 0x8001DA90: nop

    after_17:
    // 0x8001DA94: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA98: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8001DA9C: lwc1        $f14, 0xD0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8001DAA0: jal         0x800C2304
    // 0x8001DAA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_18;
    // 0x8001DAA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_18:
    // 0x8001DAA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001DAAC: jal         0x800997D8
    // 0x8001DAB0: nop

    func_800997D8(rdram, ctx);
        goto after_19;
    // 0x8001DAB0: nop

    after_19:
    // 0x8001DAB4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001DAB8: nop

    // 0x8001DABC: lwc1        $f12, 0xE8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8001DAC0: jal         0x800C2780
    // 0x8001DAC4: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_20;
    // 0x8001DAC4: nop

    after_20:
    // 0x8001DAC8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001DACC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8001DAD0: lwc1        $f14, 0xE4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0XE4);
    // 0x8001DAD4: jal         0x800C2304
    // 0x8001DAD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_21;
    // 0x8001DAD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_21:
    // 0x8001DADC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001DAE0: nop

    // 0x8001DAE4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8001DAE8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8001DAEC: nop

    // 0x8001DAF0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001DAF4: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x8001DAF8: bne         $at, $zero, L_8001D784
    if (ctx->r1 != 0) {
        // 0x8001DAFC: sw          $t8, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r24;
            goto L_8001D784;
    }
    // 0x8001DAFC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8001DB00: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8001DB04: nop

    // 0x8001DB08: blez        $t9, L_8001DB2C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001DB0C: nop
    
            goto L_8001DB2C;
    }
    // 0x8001DB0C: nop

L_8001DB10:
    // 0x8001DB10: jal         0x800C1A28
    // 0x8001DB14: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_22;
    // 0x8001DB14: nop

    after_22:
    // 0x8001DB18: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8001DB1C: nop

    // 0x8001DB20: addiu       $t1, $t5, -0x1
    ctx->r9 = ADD32(ctx->r13, -0X1);
    // 0x8001DB24: bgtz        $t1, L_8001DB10
    if (SIGNED(ctx->r9) > 0) {
        // 0x8001DB28: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_8001DB10;
    }
    // 0x8001DB28: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_8001DB2C:
    // 0x8001DB2C: jal         0x800C1A28
    // 0x8001DB30: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_23;
    // 0x8001DB30: nop

    after_23:
    // 0x8001DB34: b           L_8001DB44
    // 0x8001DB38: nop

        goto L_8001DB44;
    // 0x8001DB38: nop

L_8001DB3C:
    // 0x8001DB3C: b           L_8001DB44
    // 0x8001DB40: nop

        goto L_8001DB44;
    // 0x8001DB40: nop

L_8001DB44:
    // 0x8001DB44: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001DB48: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001DB4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DB50: lhu         $t6, 0x11A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X11A4);
    // 0x8001DB54: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x8001DB58: nop

    // 0x8001DB5C: and         $t0, $t4, $t6
    ctx->r8 = ctx->r12 & ctx->r14;
    // 0x8001DB60: beq         $t0, $zero, L_8001DBE0
    if (ctx->r8 == 0) {
        // 0x8001DB64: nop
    
            goto L_8001DBE0;
    }
    // 0x8001DB64: nop

    // 0x8001DB68: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8001DB6C:
    // 0x8001DB6C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8001DB70: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DB74: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001DB78: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001DB7C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001DB80: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x8001DB84: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8001DB88: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001DB8C: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8001DB90: addu        $t5, $t7, $t9
    ctx->r13 = ADD32(ctx->r15, ctx->r25);
    // 0x8001DB94: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8001DB98: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001DB9C: nop

    // 0x8001DBA0: lw          $a0, 0x12C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X12C);
    // 0x8001DBA4: jal         0x800BC980
    // 0x8001DBA8: nop

    SysMem_Free(rdram, ctx);
        goto after_24;
    // 0x8001DBA8: nop

    after_24:
    // 0x8001DBAC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001DBB0: nop

    // 0x8001DBB4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8001DBB8: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8001DBBC: bne         $at, $zero, L_8001DB6C
    if (ctx->r1 != 0) {
        // 0x8001DBC0: sw          $t4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r12;
            goto L_8001DB6C;
    }
    // 0x8001DBC0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x8001DBC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DBC8: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x8001DBCC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8001DBD0: jal         0x800BC980
    // 0x8001DBD4: nop

    SysMem_Free(rdram, ctx);
        goto after_25;
    // 0x8001DBD4: nop

    after_25:
    // 0x8001DBD8: b           L_8001DBF0
    // 0x8001DBDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001DBF0;
    // 0x8001DBDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001DBE0:
    // 0x8001DBE0: b           L_8001DBF0
    // 0x8001DBE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001DBF0;
    // 0x8001DBE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001DBE8: b           L_8001DBF0
    // 0x8001DBEC: nop

        goto L_8001DBF0;
    // 0x8001DBEC: nop

L_8001DBF0:
    // 0x8001DBF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DBF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DBF8: jr          $ra
    // 0x8001DBFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001DBFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C791C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C7920: addiu       $v0, $v0, -0x33E0
    ctx->r2 = ADD32(ctx->r2, -0X33E0);
    // 0x800C7924: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C7928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C792C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7930: bnel        $t6, $zero, L_800C7944
    if (ctx->r14 != 0) {
        // 0x800C7934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C7944;
    }
    goto skip_0;
    // 0x800C7934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C7938: jal         0x800C7ED0
    // 0x800C793C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    alSynNew(rdram, ctx);
        goto after_0;
    // 0x800C793C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x800C7940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C7944:
    // 0x800C7944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7948: jr          $ra
    // 0x800C794C: nop

    return;
    // 0x800C794C: nop

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
RECOMP_FUNC void func_8006261C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006261C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80062620: beq         $a0, $zero, L_8006262C
    if (ctx->r4 == 0) {
        // 0x80062624: nop
    
            goto L_8006262C;
    }
    // 0x80062624: nop

    // 0x80062628: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
L_8006262C:
    // 0x8006262C: b           L_80062634
    // 0x80062630: nop

        goto L_80062634;
    // 0x80062630: nop

L_80062634:
    // 0x80062634: jr          $ra
    // 0x80062638: nop

    return;
    // 0x80062638: nop

    // 0x8006263C: nop

;}
RECOMP_FUNC void func_8006F0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F0AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F0B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F0B4: jal         0x80061348
    // 0x8006F0B8: addiu       $a0, $zero, 0x2B8
    ctx->r4 = ADD32(0, 0X2B8);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F0B8: addiu       $a0, $zero, 0x2B8
    ctx->r4 = ADD32(0, 0X2B8);
    after_0:
    // 0x8006F0BC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F0C0: b           L_8006F0D0
    // 0x8006F0C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F0D0;
    // 0x8006F0C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F0C8: b           L_8006F0D0
    // 0x8006F0CC: nop

        goto L_8006F0D0;
    // 0x8006F0CC: nop

L_8006F0D0:
    // 0x8006F0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F0D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F0D8: jr          $ra
    // 0x8006F0DC: nop

    return;
    // 0x8006F0DC: nop

;}
RECOMP_FUNC void func_80076190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076198: jal         0x80061348
    // 0x8007619C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007619C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x800761A0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800761A4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800761A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800761AC: beq         $v0, $zero, L_80076200
    if (ctx->r2 == 0) {
        // 0x800761B0: nop
    
            goto L_80076200;
    }
    // 0x800761B0: nop

    // 0x800761B4: jal         0x80061348
    // 0x800761B8: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800761B8: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x800761BC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800761C0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800761C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800761C8: beq         $v0, $zero, L_80076200
    if (ctx->r2 == 0) {
        // 0x800761CC: nop
    
            goto L_80076200;
    }
    // 0x800761CC: nop

    // 0x800761D0: jal         0x80061348
    // 0x800761D4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800761D4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x800761D8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800761DC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800761E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800761E4: beq         $v0, $zero, L_80076200
    if (ctx->r2 == 0) {
        // 0x800761E8: nop
    
            goto L_80076200;
    }
    // 0x800761E8: nop

    // 0x800761EC: jal         0x80061348
    // 0x800761F0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800761F0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x800761F4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800761F8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800761FC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076200:
    // 0x80076200: b           L_80076210
    // 0x80076204: nop

        goto L_80076210;
    // 0x80076204: nop

    // 0x80076208: b           L_80076210
    // 0x8007620C: nop

        goto L_80076210;
    // 0x8007620C: nop

L_80076210:
    // 0x80076210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076218: jr          $ra
    // 0x8007621C: nop

    return;
    // 0x8007621C: nop

;}
RECOMP_FUNC void func_800AF92C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF92C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AF934: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800AF938: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF93C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF940: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF944: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF948: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF94C: jal         0x800BD1FC
    // 0x800AF950: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800AF950: nop

    after_0:
    // 0x800AF954: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AF958: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF95C: addiu       $t6, $t6, 0x4A8
    ctx->r14 = ADD32(ctx->r14, 0X4A8);
    // 0x800AF960: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800AF964: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800AF968: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF96C: jal         0x800BD218
    // 0x800AF970: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800AF970: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800AF974: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF978: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF97C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800AF980: nop

    // 0x800AF984: sh          $t8, 0x1D0($at)
    MEM_H(0X1D0, ctx->r1) = ctx->r24;
    // 0x800AF988: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF98C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF990: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF994: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF998: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF99C: jal         0x800BD1FC
    // 0x800AF9A0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800AF9A0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_2:
    // 0x800AF9A4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AF9A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF9AC: lhu         $a0, 0x1D0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1D0);
    // 0x800AF9B0: nop

    // 0x800AF9B4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800AF9B8: jal         0x800BC6EC
    // 0x800AF9BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800AF9BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x800AF9C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF9C4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF9C8: nop

    // 0x800AF9CC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800AF9D0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800AF9D4: lhu         $a2, 0x1D0($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X1D0);
    // 0x800AF9D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800AF9DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF9E0: sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6 << 1);
    // 0x800AF9E4: jal         0x800BD218
    // 0x800AF9E8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x800AF9E8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_4:
    // 0x800AF9EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF9F0: lhu         $a0, 0x1D0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1D0);
    // 0x800AF9F4: nop

    // 0x800AF9F8: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800AF9FC: jal         0x800BC6EC
    // 0x800AFA00: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x800AFA00: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_5:
    // 0x800AFA04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AFA08: sw          $v0, 0x1C8($at)
    MEM_W(0X1C8, ctx->r1) = ctx->r2;
    // 0x800AFA0C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800AFA10: lw          $t3, 0x1C8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1C8);
    // 0x800AFA14: nop

    // 0x800AFA18: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800AFA1C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800AFA20: lhu         $t4, 0x1D0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1D0);
    // 0x800AFA24: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800AFA28: blez        $t4, L_800AFA8C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800AFA2C: nop
    
            goto L_800AFA8C;
    }
    // 0x800AFA2C: nop

L_800AFA30:
    // 0x800AFA30: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800AFA34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AFA38: lhu         $a0, 0x0($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X0);
    // 0x800AFA3C: jal         0x800AFB70
    // 0x800AFA40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_6;
    // 0x800AFA40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x800AFA44: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AFA48: nop

    // 0x800AFA4C: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800AFA50: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AFA54: nop

    // 0x800AFA58: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800AFA5C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800AFA60: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800AFA64: nop

    // 0x800AFA68: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x800AFA6C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800AFA70: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800AFA74: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800AFA78: lhu         $t3, 0x1D0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1D0);
    // 0x800AFA7C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800AFA80: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AFA84: bne         $at, $zero, L_800AFA30
    if (ctx->r1 != 0) {
        // 0x800AFA88: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800AFA30;
    }
    // 0x800AFA88: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_800AFA8C:
    // 0x800AFA8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AFA90: jal         0x800BC980
    // 0x800AFA94: nop

    SysMem_Free(rdram, ctx);
        goto after_7;
    // 0x800AFA94: nop

    after_7:
    // 0x800AFA98: b           L_800AFAA0
    // 0x800AFA9C: nop

        goto L_800AFAA0;
    // 0x800AFA9C: nop

L_800AFAA0:
    // 0x800AFAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AFAA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800AFAA8: jr          $ra
    // 0x800AFAAC: nop

    return;
    // 0x800AFAAC: nop

;}
RECOMP_FUNC void func_8006081C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006081C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060820: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060824: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80060828: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006082C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060830: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80060834: nop

    // 0x80060838: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8006083C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060840: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80060844: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80060848: nop

    // 0x8006084C: bne         $t7, $t8, L_80060868
    if (ctx->r15 != ctx->r24) {
        // 0x80060850: nop
    
            goto L_80060868;
    }
    // 0x80060850: nop

    // 0x80060854: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80060858: nop

    // 0x8006085C: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    // 0x80060860: jal         0x80061030
    // 0x80060864: nop

    func_80061030(rdram, ctx);
        goto after_0;
    // 0x80060864: nop

    after_0:
L_80060868:
    // 0x80060868: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006086C: nop

    // 0x80060870: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80060874: nop

    // 0x80060878: sh          $t1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r9;
    // 0x8006087C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80060880: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80060884: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x80060888: nop

    // 0x8006088C: beq         $t3, $at, L_80060948
    if (ctx->r11 == ctx->r1) {
        // 0x80060890: sh          $t3, 0x30($sp)
        MEM_H(0X30, ctx->r29) = ctx->r11;
            goto L_80060948;
    }
    // 0x80060890: sh          $t3, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r11;
L_80060894:
    // 0x80060894: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
    // 0x80060898: lui         $t6, 0x809F
    ctx->r14 = S32(0X809F << 16);
    // 0x8006089C: addiu       $t6, $t6, -0x5918
    ctx->r14 = ADD32(ctx->r14, -0X5918);
    // 0x800608A0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x800608A4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x800608A8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800608AC: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x800608B0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x800608B4: jal         0x800BD1FC
    // 0x800608B8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x800608B8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_1:
    // 0x800608BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800608C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800608C4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800608C8: jal         0x800BD218
    // 0x800608CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800608CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800608D0: lhu         $t7, 0x2C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2C);
    // 0x800608D4: nop

    // 0x800608D8: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x800608DC: beq         $t8, $zero, L_800608F4
    if (ctx->r24 == 0) {
        // 0x800608E0: nop
    
            goto L_800608F4;
    }
    // 0x800608E0: nop

    // 0x800608E4: lh          $t9, 0x30($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X30);
    // 0x800608E8: nop

    // 0x800608EC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800608F0: sh          $t0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r8;
L_800608F4:
    // 0x800608F4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800608F8: nop

    // 0x800608FC: jalr        $t9
    // 0x80060900: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80060900: nop

    after_3:
    // 0x80060904: bne         $v0, $zero, L_80060920
    if (ctx->r2 != 0) {
        // 0x80060908: nop
    
            goto L_80060920;
    }
    // 0x80060908: nop

    // 0x8006090C: lhu         $t1, 0x2C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2C);
    // 0x80060910: nop

    // 0x80060914: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x80060918: bne         $t2, $zero, L_80060894
    if (ctx->r10 != 0) {
        // 0x8006091C: nop
    
            goto L_80060894;
    }
    // 0x8006091C: nop

L_80060920:
    // 0x80060920: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80060924: nop

    // 0x80060928: jalr        $t9
    // 0x8006092C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8006092C: nop

    after_4:
    // 0x80060930: beq         $v0, $zero, L_80060948
    if (ctx->r2 == 0) {
        // 0x80060934: nop
    
            goto L_80060948;
    }
    // 0x80060934: nop

    // 0x80060938: lhu         $t3, 0x2C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2C);
    // 0x8006093C: nop

    // 0x80060940: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x80060944: sh          $t4, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r12;
L_80060948:
    // 0x80060948: lh          $a0, 0x32($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X32);
    // 0x8006094C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80060950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060954: jal         0x8004BA04
    // 0x80060958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004BA04(rdram, ctx);
        goto after_5;
    // 0x80060958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8006095C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80060960: nop

    // 0x80060964: lbu         $t6, 0xA($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XA);
    // 0x80060968: nop

    // 0x8006096C: beq         $t6, $zero, L_800609E4
    if (ctx->r14 == 0) {
        // 0x80060970: nop
    
            goto L_800609E4;
    }
    // 0x80060970: nop

    // 0x80060974: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80060978: nop

    // 0x8006097C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80060980: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80060984: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x80060988: bne         $t0, $zero, L_80060998
    if (ctx->r8 != 0) {
        // 0x8006098C: andi        $t1, $t9, 0x0
        ctx->r9 = ctx->r25 & 0X0;
            goto L_80060998;
    }
    // 0x8006098C: andi        $t1, $t9, 0x0
    ctx->r9 = ctx->r25 & 0X0;
    // 0x80060990: beq         $t1, $zero, L_800609A0
    if (ctx->r9 == 0) {
        // 0x80060994: nop
    
            goto L_800609A0;
    }
    // 0x80060994: nop

L_80060998:
    // 0x80060998: b           L_800609F4
    // 0x8006099C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800609F4;
    // 0x8006099C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800609A0:
    // 0x800609A0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800609A4: nop

    // 0x800609A8: lh          $a0, 0xC($t2)
    ctx->r4 = MEM_H(ctx->r10, 0XC);
    // 0x800609AC: jal         0x80061B38
    // 0x800609B0: nop

    func_80061B38(rdram, ctx);
        goto after_6;
    // 0x800609B0: nop

    after_6:
    // 0x800609B4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800609B8: nop

    // 0x800609BC: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    // 0x800609C0: jal         0x80061FFC
    // 0x800609C4: nop

    func_80061FFC(rdram, ctx);
        goto after_7;
    // 0x800609C4: nop

    after_7:
    // 0x800609C8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800609CC: nop

    // 0x800609D0: lh          $a0, 0xE($t4)
    ctx->r4 = MEM_H(ctx->r12, 0XE);
    // 0x800609D4: jal         0x80060E9C
    // 0x800609D8: nop

    func_80060E9C(rdram, ctx);
        goto after_8;
    // 0x800609D8: nop

    after_8:
    // 0x800609DC: b           L_800609F4
    // 0x800609E0: nop

        goto L_800609F4;
    // 0x800609E0: nop

L_800609E4:
    // 0x800609E4: b           L_800609F4
    // 0x800609E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800609F4;
    // 0x800609E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800609EC: b           L_800609F4
    // 0x800609F0: nop

        goto L_800609F4;
    // 0x800609F0: nop

L_800609F4:
    // 0x800609F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800609F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800609FC: jr          $ra
    // 0x80060A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80060A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
