#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80063770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063778: jal         0x8005F064
    // 0x8006377C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006377C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063780: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063784: b           L_80063794
    // 0x80063788: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063794;
    // 0x80063788: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006378C: b           L_80063794
    // 0x80063790: nop

        goto L_80063794;
    // 0x80063790: nop

L_80063794:
    // 0x80063794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006379C: jr          $ra
    // 0x800637A0: nop

    return;
    // 0x800637A0: nop

;}
RECOMP_FUNC void func_8006C2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C2D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C2D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C2D8: jal         0x8005F064
    // 0x8006C2DC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C2DC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x8006C2E0: b           L_8006C2F0
    // 0x8006C2E4: nop

        goto L_8006C2F0;
    // 0x8006C2E4: nop

    // 0x8006C2E8: b           L_8006C2F0
    // 0x8006C2EC: nop

        goto L_8006C2F0;
    // 0x8006C2EC: nop

L_8006C2F0:
    // 0x8006C2F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C2F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C2F8: jr          $ra
    // 0x8006C2FC: nop

    return;
    // 0x8006C2FC: nop

;}
RECOMP_FUNC void func_8007654C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007654C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076550: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076554: nop

    // 0x80076558: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8007655C: nop

    // 0x80076560: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076564: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076568: jr          $ra
    // 0x8007656C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007656C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076570: jr          $ra
    // 0x80076574: nop

    return;
    // 0x80076574: nop

    // 0x80076578: jr          $ra
    // 0x8007657C: nop

    return;
    // 0x8007657C: nop

;}
RECOMP_FUNC void func_80031C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C5C: jr          $ra
    // 0x80031C60: nop

    return;
    // 0x80031C60: nop

    // 0x80031C64: jr          $ra
    // 0x80031C68: nop

    return;
    // 0x80031C68: nop

;}
RECOMP_FUNC void MtxUtil_ClearTranslation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1908: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C190C: bne         $a0, $zero, L_800C1924
    if (ctx->r4 != 0) {
        // 0x800C1910: nop
    
            goto L_800C1924;
    }
    // 0x800C1910: nop

    // 0x800C1914: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1918: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C191C: b           L_800C1928
    // 0x800C1920: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
        goto L_800C1928;
    // 0x800C1920: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
L_800C1924:
    // 0x800C1924: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
L_800C1928:
    // 0x800C1928: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C192C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800C1930: nop

    // 0x800C1934: swc1        $f4, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f4.u32l;
    // 0x800C1938: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C193C: nop

    // 0x800C1940: lwc1        $f12, 0x38($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X38);
    // 0x800C1944: nop

    // 0x800C1948: swc1        $f12, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f12.u32l;
    // 0x800C194C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C1950: nop

    // 0x800C1954: swc1        $f12, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f12.u32l;
    // 0x800C1958: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C195C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C1960: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C1964: nop

    // 0x800C1968: swc1        $f6, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f6.u32l;
    // 0x800C196C: b           L_800C1974
    // 0x800C1970: nop

        goto L_800C1974;
    // 0x800C1970: nop

L_800C1974:
    // 0x800C1974: jr          $ra
    // 0x800C1978: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1978: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006508C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006508C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065090: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065094: nop

    // 0x80065098: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006509C: nop

    // 0x800650A0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800650A4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800650A8: jr          $ra
    // 0x800650AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800650AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800650B0: jr          $ra
    // 0x800650B4: nop

    return;
    // 0x800650B4: nop

    // 0x800650B8: jr          $ra
    // 0x800650BC: nop

    return;
    // 0x800650BC: nop

;}
RECOMP_FUNC void func_800B79FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B79FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B7A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7A04: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B7A08: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B7A0C:
    // 0x800B7A0C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B7A10: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B7A14: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7A18: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7A1C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7A20: sh          $t7, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r15;
    // 0x800B7A24: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B7A28: nop

    // 0x800B7A2C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7A30: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B7A34: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B7A38: nop

    // 0x800B7A3C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7A40: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B7A44: bne         $at, $zero, L_800B7A0C
    if (ctx->r1 != 0) {
        // 0x800B7A48: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_800B7A0C;
    }
    // 0x800B7A48: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B7A4C: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B7A50: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7A54: ori         $at, $zero, 0xE000
    ctx->r1 = 0 | 0XE000;
    // 0x800B7A58: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B7A5C: bne         $at, $zero, L_800B7A74
    if (ctx->r1 != 0) {
        // 0x800B7A60: nop
    
            goto L_800B7A74;
    }
    // 0x800B7A60: nop

    // 0x800B7A64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B7A68: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B7A6C: bne         $at, $zero, L_800B7A7C
    if (ctx->r1 != 0) {
        // 0x800B7A70: nop
    
            goto L_800B7A7C;
    }
    // 0x800B7A70: nop

L_800B7A74:
    // 0x800B7A74: b           L_800B7B84
    // 0x800B7A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7B84;
    // 0x800B7A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7A7C:
    // 0x800B7A7C: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B7A80: lhu         $t7, 0x2($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7A84: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800B7A88: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x800B7A8C: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x800B7A90: sltiu       $at, $t9, 0xD
    ctx->r1 = ctx->r25 < 0XD ? 1 : 0;
    // 0x800B7A94: beq         $at, $zero, L_800B7B50
    if (ctx->r1 == 0) {
        // 0x800B7A98: nop
    
            goto L_800B7B50;
    }
    // 0x800B7A98: nop

    // 0x800B7A9C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B7AA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B7AA4: addu        $at, $at, $t9
    gpr jr_addend_800B7AB0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B7AA8: lw          $t9, -0x558($at)
    ctx->r25 = ADD32(ctx->r1, -0X558);
    // 0x800B7AAC: nop

    // 0x800B7AB0: jr          $t9
    // 0x800B7AB4: nop

    switch (jr_addend_800B7AB0 >> 2) {
        case 0: goto L_800B7AB8; break;
        case 1: goto L_800B7AB8; break;
        case 2: goto L_800B7AB8; break;
        case 3: goto L_800B7AB8; break;
        case 4: goto L_800B7B50; break;
        case 5: goto L_800B7B50; break;
        case 6: goto L_800B7B50; break;
        case 7: goto L_800B7B50; break;
        case 8: goto L_800B7AB8; break;
        case 9: goto L_800B7AB8; break;
        case 10: goto L_800B7AB8; break;
        case 11: goto L_800B7AB8; break;
        case 12: goto L_800B7AB8; break;
        default: switch_error(__func__, 0x800B7AB0, 0x800EFAA8);
    }
    // 0x800B7AB4: nop

L_800B7AB8:
    // 0x800B7AB8: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B7ABC: lhu         $a0, 0x4($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X4);
    // 0x800B7AC0: jal         0x8000D688
    // 0x800B7AC4: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B7AC4: nop

    after_0:
    // 0x800B7AC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B7ACC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7AD0: nop

    // 0x800B7AD4: bne         $t1, $zero, L_800B7AE4
    if (ctx->r9 != 0) {
        // 0x800B7AD8: nop
    
            goto L_800B7AE4;
    }
    // 0x800B7AD8: nop

    // 0x800B7ADC: b           L_800B7B84
    // 0x800B7AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7B84;
    // 0x800B7AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7AE4:
    // 0x800B7AE4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7AE8: nop

    // 0x800B7AEC: lw          $t3, 0x20C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20C);
    // 0x800B7AF0: nop

    // 0x800B7AF4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800B7AF8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7AFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B7B00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B7B04: lwc1        $f4, 0x1F0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1F0);
    // 0x800B7B08: nop

    // 0x800B7B0C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800B7B10: nop

    // 0x800B7B14: bc1f        L_800B7B24
    if (!c1cs) {
        // 0x800B7B18: nop
    
            goto L_800B7B24;
    }
    // 0x800B7B18: nop

    // 0x800B7B1C: b           L_800B7B84
    // 0x800B7B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B7B84;
    // 0x800B7B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B7B24:
    // 0x800B7B24: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B7B28: lhu         $a0, 0x4($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X4);
    // 0x800B7B2C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800B7B30: jal         0x8000D934
    // 0x800B7B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8000D934(rdram, ctx);
        goto after_1;
    // 0x800B7B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800B7B38: bgez        $v0, L_800B7B48
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B7B3C: nop
    
            goto L_800B7B48;
    }
    // 0x800B7B3C: nop

    // 0x800B7B40: b           L_800B7B84
    // 0x800B7B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7B84;
    // 0x800B7B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7B48:
    // 0x800B7B48: b           L_800B7B58
    // 0x800B7B4C: nop

        goto L_800B7B58;
    // 0x800B7B4C: nop

L_800B7B50:
    // 0x800B7B50: b           L_800B7B84
    // 0x800B7B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7B84;
    // 0x800B7B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7B58:
    // 0x800B7B58: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7B5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B7B60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B7B64: lwc1        $f8, 0x1F0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1F0);
    // 0x800B7B68: nop

    // 0x800B7B6C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B7B70: swc1        $f16, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = ctx->f16.u32l;
    // 0x800B7B74: b           L_800B7B84
    // 0x800B7B78: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7B84;
    // 0x800B7B78: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B7B7C: b           L_800B7B84
    // 0x800B7B80: nop

        goto L_800B7B84;
    // 0x800B7B80: nop

L_800B7B84:
    // 0x800B7B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7B88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B7B8C: jr          $ra
    // 0x800B7B90: nop

    return;
    // 0x800B7B90: nop

;}
RECOMP_FUNC void func_800B202C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B202C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800B2030: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B2034: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800B2038: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800B203C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800B2040: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800B2044: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B2048: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800B204C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800B2050: nop

    // 0x800B2054: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B2058: nop

    // 0x800B205C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B2060: nop

    // 0x800B2064: bne         $t8, $zero, L_800B2088
    if (ctx->r24 != 0) {
        // 0x800B2068: nop
    
            goto L_800B2088;
    }
    // 0x800B2068: nop

    // 0x800B206C: jal         0x800BC6EC
    // 0x800B2070: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800B2070: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800B2074: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800B2078: nop

    // 0x800B207C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B2080: nop

    // 0x800B2084: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_800B2088:
    // 0x800B2088: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800B208C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800B2090: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800B2094: nop

    // 0x800B2098: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x800B209C: jal         0x800B3EC0
    // 0x800B20A0: nop

    func_800B3EC0(rdram, ctx);
        goto after_1;
    // 0x800B20A0: nop

    after_1:
    // 0x800B20A4: beq         $v0, $zero, L_800B20B4
    if (ctx->r2 == 0) {
        // 0x800B20A8: nop
    
            goto L_800B20B4;
    }
    // 0x800B20A8: nop

    // 0x800B20AC: b           L_800B23B4
    // 0x800B20B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B23B4;
    // 0x800B20B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B20B4:
    // 0x800B20B4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800B20B8: nop

    // 0x800B20BC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800B20C0: nop

    // 0x800B20C4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800B20C8: nop

    // 0x800B20CC: lbu         $t6, 0xE($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XE);
    // 0x800B20D0: nop

    // 0x800B20D4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800B20D8: lbu         $t7, 0x7B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X7B);
    // 0x800B20DC: nop

    // 0x800B20E0: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800B20E4: beq         $t8, $zero, L_800B2114
    if (ctx->r24 == 0) {
        // 0x800B20E8: nop
    
            goto L_800B2114;
    }
    // 0x800B20E8: nop

    // 0x800B20EC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800B20F0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B20F4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B20F8: nop

    // 0x800B20FC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800B2100: nop

    // 0x800B2104: lbu         $t3, 0xF($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XF);
    // 0x800B2108: nop

    // 0x800B210C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800B2110: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_800B2114:
    // 0x800B2114: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800B2118: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B211C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B2120: lw          $t0, 0xD34($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD34);
    // 0x800B2124: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B2128: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B212C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B2130: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B2134: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B2138: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B213C: jal         0x800BD1FC
    // 0x800B2140: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B2140: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_2:
    // 0x800B2144: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2148: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B214C: sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6 << 1);
    // 0x800B2150: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800B2154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B2158: jal         0x800BD218
    // 0x800B215C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B215C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x800B2160: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2164: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B2168: blez        $t2, L_800B2214
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B216C: nop
    
            goto L_800B2214;
    }
    // 0x800B216C: nop

L_800B2170:
    // 0x800B2170: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B2174: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800B2178: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800B217C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B2180: sll         $t0, $t4, 1
    ctx->r8 = S32(ctx->r12 << 1);
    // 0x800B2184: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x800B2188: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B218C: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x800B2190: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B2194: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B2198: lhu         $a2, 0x40($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X40);
    // 0x800B219C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B21A0: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B21A4: lbu         $t1, 0x7B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7B);
    // 0x800B21A8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B21AC: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800B21B0: lhu         $a3, 0x6E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X6E);
    // 0x800B21B4: sll         $t8, $t4, 6
    ctx->r24 = S32(ctx->r12 << 6);
    // 0x800B21B8: addu        $a0, $t3, $t5
    ctx->r4 = ADD32(ctx->r11, ctx->r13);
    // 0x800B21BC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800B21C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B21C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800B21C8: jal         0x800B23C4
    // 0x800B21CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_800B23C4(rdram, ctx);
        goto after_4;
    // 0x800B21CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_4:
    // 0x800B21D0: beq         $v0, $zero, L_800B21FC
    if (ctx->r2 == 0) {
        // 0x800B21D4: nop
    
            goto L_800B21FC;
    }
    // 0x800B21D4: nop

    // 0x800B21D8: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800B21DC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B21E0: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800B21E4: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x800B21E8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800B21EC: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B21F0: nop

    // 0x800B21F4: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x800B21F8: sh          $t8, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r24;
L_800B21FC:
    // 0x800B21FC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B2200: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2204: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x800B2208: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B220C: bne         $at, $zero, L_800B2170
    if (ctx->r1 != 0) {
        // 0x800B2210: sw          $t0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r8;
            goto L_800B2170;
    }
    // 0x800B2210: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_800B2214:
    // 0x800B2214: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2218: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B221C: blez        $t2, L_800B226C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B2220: nop
    
            goto L_800B226C;
    }
    // 0x800B2220: nop

L_800B2224:
    // 0x800B2224: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800B2228: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B222C: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800B2230: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x800B2234: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800B2238: lhu         $t6, 0x3A($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X3A);
    // 0x800B223C: nop

    // 0x800B2240: andi        $t4, $t6, 0x400
    ctx->r12 = ctx->r14 & 0X400;
    // 0x800B2244: bne         $t4, $zero, L_800B2254
    if (ctx->r12 != 0) {
        // 0x800B2248: nop
    
            goto L_800B2254;
    }
    // 0x800B2248: nop

    // 0x800B224C: b           L_800B226C
    // 0x800B2250: nop

        goto L_800B226C;
    // 0x800B2250: nop

L_800B2254:
    // 0x800B2254: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800B2258: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B225C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B2260: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B2264: bne         $at, $zero, L_800B2224
    if (ctx->r1 != 0) {
        // 0x800B2268: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_800B2224;
    }
    // 0x800B2268: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
L_800B226C:
    // 0x800B226C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B2270: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2274: nop

    // 0x800B2278: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B227C: bne         $at, $zero, L_800B228C
    if (ctx->r1 != 0) {
        // 0x800B2280: nop
    
            goto L_800B228C;
    }
    // 0x800B2280: nop

    // 0x800B2284: b           L_800B23B4
    // 0x800B2288: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B23B4;
    // 0x800B2288: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B228C:
    // 0x800B228C: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800B2290: nop

    // 0x800B2294: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B2298: nop

    // 0x800B229C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800B22A0: nop

    // 0x800B22A4: andi        $t6, $t8, 0x4
    ctx->r14 = ctx->r24 & 0X4;
    // 0x800B22A8: beq         $t6, $zero, L_800B231C
    if (ctx->r14 == 0) {
        // 0x800B22AC: nop
    
            goto L_800B231C;
    }
    // 0x800B22AC: nop

    // 0x800B22B0: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800B22B4: nop

    // 0x800B22B8: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x800B22BC: nop

    // 0x800B22C0: lhu         $t1, 0x3A($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X3A);
    // 0x800B22C4: nop

    // 0x800B22C8: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x800B22CC: beq         $t2, $zero, L_800B231C
    if (ctx->r10 == 0) {
        // 0x800B22D0: nop
    
            goto L_800B231C;
    }
    // 0x800B22D0: nop

    // 0x800B22D4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800B22D8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800B22DC: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800B22E0: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x800B22E4: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x800B22E8: nop

    // 0x800B22EC: lbu         $t7, 0xE($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XE);
    // 0x800B22F0: nop

    // 0x800B22F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B22F8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B22FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2300: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B2304: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800B2308: addu        $t0, $t8, $t4
    ctx->r8 = ADD32(ctx->r24, ctx->r12);
    // 0x800B230C: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x800B2310: nop

    // 0x800B2314: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x800B2318: sw          $t2, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r10;
L_800B231C:
    // 0x800B231C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2320: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B2324: blez        $t3, L_800B23A0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B2328: nop
    
            goto L_800B23A0;
    }
    // 0x800B2328: nop

L_800B232C:
    // 0x800B232C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800B2330: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800B2334: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800B2338: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x800B233C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800B2340: lhu         $t4, 0x3A($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X3A);
    // 0x800B2344: nop

    // 0x800B2348: andi        $t1, $t4, 0x400
    ctx->r9 = ctx->r12 & 0X400;
    // 0x800B234C: beq         $t1, $zero, L_800B2388
    if (ctx->r9 == 0) {
        // 0x800B2350: nop
    
            goto L_800B2388;
    }
    // 0x800B2350: nop

    // 0x800B2354: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B2358: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800B235C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800B2360: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x800B2364: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B2368: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x800B236C: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x800B2370: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800B2374: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x800B2378: lw          $t9, 0xC0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC0);
    // 0x800B237C: nop

    // 0x800B2380: ori         $t6, $t9, 0x80
    ctx->r14 = ctx->r25 | 0X80;
    // 0x800B2384: sw          $t6, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r14;
L_800B2388:
    // 0x800B2388: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B238C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2390: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x800B2394: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B2398: bne         $at, $zero, L_800B232C
    if (ctx->r1 != 0) {
        // 0x800B239C: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_800B232C;
    }
    // 0x800B239C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_800B23A0:
    // 0x800B23A0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800B23A4: b           L_800B23B4
    // 0x800B23A8: nop

        goto L_800B23B4;
    // 0x800B23A8: nop

    // 0x800B23AC: b           L_800B23B4
    // 0x800B23B0: nop

        goto L_800B23B4;
    // 0x800B23B0: nop

L_800B23B4:
    // 0x800B23B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B23B8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B23BC: jr          $ra
    // 0x800B23C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800B23C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8006FD34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FD34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FD3C: jal         0x80061348
    // 0x8006FD40: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FD40: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FD44: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FD48: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FD4C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FD50: beq         $v0, $zero, L_8006FDA4
    if (ctx->r2 == 0) {
        // 0x8006FD54: nop
    
            goto L_8006FDA4;
    }
    // 0x8006FD54: nop

    // 0x8006FD58: jal         0x80061348
    // 0x8006FD5C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FD5C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FD60: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FD64: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FD68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FD6C: beq         $v0, $zero, L_8006FDA4
    if (ctx->r2 == 0) {
        // 0x8006FD70: nop
    
            goto L_8006FDA4;
    }
    // 0x8006FD70: nop

    // 0x8006FD74: jal         0x80061348
    // 0x8006FD78: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FD78: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FD7C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FD80: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FD84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FD88: beq         $v0, $zero, L_8006FDA4
    if (ctx->r2 == 0) {
        // 0x8006FD8C: nop
    
            goto L_8006FDA4;
    }
    // 0x8006FD8C: nop

    // 0x8006FD90: jal         0x80061348
    // 0x8006FD94: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FD94: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FD98: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FD9C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FDA0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FDA4:
    // 0x8006FDA4: b           L_8006FDB4
    // 0x8006FDA8: nop

        goto L_8006FDB4;
    // 0x8006FDA8: nop

    // 0x8006FDAC: b           L_8006FDB4
    // 0x8006FDB0: nop

        goto L_8006FDB4;
    // 0x8006FDB0: nop

L_8006FDB4:
    // 0x8006FDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FDB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FDBC: jr          $ra
    // 0x8006FDC0: nop

    return;
    // 0x8006FDC0: nop

;}
RECOMP_FUNC void func_80062E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062E2C: jal         0x8005F064
    // 0x80062E30: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062E30: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80062E34: b           L_80062E44
    // 0x80062E38: nop

        goto L_80062E44;
    // 0x80062E38: nop

    // 0x80062E3C: b           L_80062E44
    // 0x80062E40: nop

        goto L_80062E44;
    // 0x80062E40: nop

L_80062E44:
    // 0x80062E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062E4C: jr          $ra
    // 0x80062E50: nop

    return;
    // 0x80062E50: nop

;}
RECOMP_FUNC void Spi_Compress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF6C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BF6CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF6D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BF6D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BF6D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF6DC: sw          $zero, 0x474($at)
    MEM_W(0X474, ctx->r1) = 0;
    // 0x800BF6E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF6E4: sw          $zero, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = 0;
    // 0x800BF6E8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800BF6EC: nop

    // 0x800BF6F0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800BF6F4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800BF6F8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800BF6FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF700: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
    // 0x800BF704: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BF708:
    // 0x800BF708: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF70C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF710: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BF714: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BF718: sw          $t7, 0x228($at)
    MEM_W(0X228, ctx->r1) = ctx->r15;
    // 0x800BF71C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF720: nop

    // 0x800BF724: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BF728: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800BF72C: bne         $at, $zero, L_800BF708
    if (ctx->r1 != 0) {
        // 0x800BF730: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800BF708;
    }
    // 0x800BF730: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BF734: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800BF738: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF73C: sw          $t1, 0x42C($at)
    MEM_W(0X42C, ctx->r1) = ctx->r9;
    // 0x800BF740: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BF744: nop

    // 0x800BF748: blez        $t2, L_800BFB38
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BF74C: nop
    
            goto L_800BFB38;
    }
    // 0x800BF74C: nop

L_800BF750:
    // 0x800BF750: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF754: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF758: lw          $t4, 0x458($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X458);
    // 0x800BF75C: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BF760: nop

    // 0x800BF764: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800BF768: slti        $at, $t5, 0x1001
    ctx->r1 = SIGNED(ctx->r13) < 0X1001 ? 1 : 0;
    // 0x800BF76C: bne         $at, $zero, L_800BF780
    if (ctx->r1 != 0) {
        // 0x800BF770: nop
    
            goto L_800BF780;
    }
    // 0x800BF770: nop

    // 0x800BF774: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x800BF778: b           L_800BF79C
    // 0x800BF77C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_800BF79C;
    // 0x800BF77C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_800BF780:
    // 0x800BF780: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF784: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF788: lw          $t8, 0x458($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X458);
    // 0x800BF78C: lw          $t7, 0x434($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X434);
    // 0x800BF790: nop

    // 0x800BF794: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800BF798: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800BF79C:
    // 0x800BF79C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7A0: nop

    // 0x800BF7A4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800BF7A8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7AC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800BF7B0: blez        $t1, L_800BF81C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800BF7B4: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_800BF81C;
    }
    // 0x800BF7B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BF7B8:
    // 0x800BF7B8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF7BC: lw          $t2, 0x434($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X434);
    // 0x800BF7C0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7C4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800BF7C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800BF7CC: jal         0x800C00A4
    // 0x800BF7D0: subu        $a1, $t2, $t3
    ctx->r5 = SUB32(ctx->r10, ctx->r11);
    static_5_800C00A4(rdram, ctx);
        goto after_0;
    // 0x800BF7D0: subu        $a1, $t2, $t3
    ctx->r5 = SUB32(ctx->r10, ctx->r11);
    after_0:
    // 0x800BF7D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BF7D8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF7DC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BF7E0: nop

    // 0x800BF7E4: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BF7E8: beq         $at, $zero, L_800BF808
    if (ctx->r1 == 0) {
        // 0x800BF7EC: nop
    
            goto L_800BF808;
    }
    // 0x800BF7EC: nop

    // 0x800BF7F0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7F4: nop

    // 0x800BF7F8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800BF7FC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF800: nop

    // 0x800BF804: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800BF808:
    // 0x800BF808: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BF80C: nop

    // 0x800BF810: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800BF814: bgtz        $t9, L_800BF7B8
    if (SIGNED(ctx->r25) > 0) {
        // 0x800BF818: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_800BF7B8;
    }
    // 0x800BF818: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800BF81C:
    // 0x800BF81C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800BF820: nop

    // 0x800BF824: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800BF828: beq         $at, $zero, L_800BF94C
    if (ctx->r1 == 0) {
        // 0x800BF82C: nop
    
            goto L_800BF94C;
    }
    // 0x800BF82C: nop

    // 0x800BF830: jal         0x800C0278
    // 0x800BF834: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C0278(rdram, ctx);
        goto after_1;
    // 0x800BF834: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800BF838: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800BF83C: nop

    // 0x800BF840: bne         $t1, $zero, L_800BF8F8
    if (ctx->r9 != 0) {
        // 0x800BF844: nop
    
            goto L_800BF8F8;
    }
    // 0x800BF844: nop

    // 0x800BF848: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF84C: lw          $t2, 0x434($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X434);
    // 0x800BF850: nop

    // 0x800BF854: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x800BF858: nop

    // 0x800BF85C: andi        $t3, $a0, 0xFF
    ctx->r11 = ctx->r4 & 0XFF;
    // 0x800BF860: jal         0x800C0444
    // 0x800BF864: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800C0444(rdram, ctx);
        goto after_2;
    // 0x800BF864: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_2:
    // 0x800BF868: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BF86C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF870: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BF874: bne         $t4, $at, L_800BF8C8
    if (ctx->r12 != ctx->r1) {
        // 0x800BF878: nop
    
            goto L_800BF8C8;
    }
    // 0x800BF878: nop

    // 0x800BF87C: jal         0x800C0278
    // 0x800BF880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C0278(rdram, ctx);
        goto after_3;
    // 0x800BF880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800BF884: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF888: lw          $t5, 0x434($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X434);
    // 0x800BF88C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF890: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BF894: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800BF898: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF89C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800BF8A0: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BF8A4: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BF8A8: lw          $t0, 0x434($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X434);
    // 0x800BF8AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF8B0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BF8B4: sw          $t9, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r25;
    // 0x800BF8B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF8BC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BF8C0: b           L_800BF8F0
    // 0x800BF8C4: sw          $t1, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r9;
        goto L_800BF8F0;
    // 0x800BF8C4: sw          $t1, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r9;
L_800BF8C8:
    // 0x800BF8C8: jal         0x800C0278
    // 0x800BF8CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C0278(rdram, ctx);
        goto after_4;
    // 0x800BF8CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800BF8D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF8D4: jal         0x800C0108
    // 0x800BF8D8: nop

    func_800C0108(rdram, ctx);
        goto after_5;
    // 0x800BF8D8: nop

    after_5:
    // 0x800BF8DC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF8E0: lw          $t2, 0x434($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X434);
    // 0x800BF8E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF8E8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BF8EC: sw          $t3, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r11;
L_800BF8F0:
    // 0x800BF8F0: b           L_800BF938
    // 0x800BF8F4: nop

        goto L_800BF938;
    // 0x800BF8F4: nop

L_800BF8F8:
    // 0x800BF8F8: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF8FC: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BF900: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BF904: lw          $t6, 0x444($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X444);
    // 0x800BF908: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800BF90C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF910: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800BF914: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BF918: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF91C: lw          $t9, 0x434($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X434);
    // 0x800BF920: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF924: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BF928: sw          $t8, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r24;
    // 0x800BF92C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF930: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BF934: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
L_800BF938:
    // 0x800BF938: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BF93C: nop

    // 0x800BF940: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800BF944: b           L_800BFB28
    // 0x800BF948: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
        goto L_800BFB28;
    // 0x800BF948: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_800BF94C:
    // 0x800BF94C: jal         0x800C0278
    // 0x800BF950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C0278(rdram, ctx);
        goto after_6;
    // 0x800BF950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800BF954: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF958: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BF95C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800BF960: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF964: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BF968: sw          $t5, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r13;
    // 0x800BF96C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BF970: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BF974: nop

    // 0x800BF978: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800BF97C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800BF980: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800BF984: nop

    // 0x800BF988: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800BF98C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800BF990: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800BF994: nop

    // 0x800BF998: addiu       $t2, $t1, -0x3
    ctx->r10 = ADD32(ctx->r9, -0X3);
    // 0x800BF99C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800BF9A0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800BF9A4: nop

    // 0x800BF9A8: slti        $at, $t3, 0xF
    ctx->r1 = SIGNED(ctx->r11) < 0XF ? 1 : 0;
    // 0x800BF9AC: bne         $at, $zero, L_800BFAB4
    if (ctx->r1 != 0) {
        // 0x800BF9B0: nop
    
            goto L_800BFAB4;
    }
    // 0x800BF9B0: nop

    // 0x800BF9B4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800BF9B8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF9BC: bgez        $t4, L_800BF9CC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800BF9C0: sra         $t5, $t4, 8
        ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
            goto L_800BF9CC;
    }
    // 0x800BF9C0: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800BF9C4: addiu       $at, $t4, 0xFF
    ctx->r1 = ADD32(ctx->r12, 0XFF);
    // 0x800BF9C8: sra         $t5, $at, 8
    ctx->r13 = S32(SIGNED(ctx->r1) >> 8);
L_800BF9CC:
    // 0x800BF9CC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800BF9D0: lw          $t9, 0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X444);
    // 0x800BF9D4: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800BF9D8: ori         $t8, $t7, 0xF0
    ctx->r24 = ctx->r15 | 0XF0;
    // 0x800BF9DC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BF9E0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BF9E4: lw          $t0, 0x444($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X444);
    // 0x800BF9E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF9EC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BF9F0: sw          $t1, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r9;
    // 0x800BF9F4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800BF9F8: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF9FC: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BFA00: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800BFA04: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BFA08: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x800BFA0C: lw          $t5, 0x444($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X444);
    // 0x800BFA10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFA14: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800BFA18: sw          $t6, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r14;
    // 0x800BFA1C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BFA20: nop

    // 0x800BFA24: addiu       $t8, $t7, -0xF
    ctx->r24 = ADD32(ctx->r15, -0XF);
    // 0x800BFA28: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_800BFA2C:
    // 0x800BFA2C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800BFA30: nop

    // 0x800BFA34: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x800BFA38: bne         $at, $zero, L_800BFA78
    if (ctx->r1 != 0) {
        // 0x800BFA3C: nop
    
            goto L_800BFA78;
    }
    // 0x800BFA3C: nop

    // 0x800BFA40: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFA44: lw          $t1, 0x444($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X444);
    // 0x800BFA48: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800BFA4C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BFA50: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800BFA54: lw          $t2, 0x444($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X444);
    // 0x800BFA58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFA5C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BFA60: sw          $t3, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r11;
    // 0x800BFA64: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800BFA68: nop

    // 0x800BFA6C: addiu       $t5, $t4, -0xFF
    ctx->r13 = ADD32(ctx->r12, -0XFF);
    // 0x800BFA70: b           L_800BFAA4
    // 0x800BFA74: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
        goto L_800BFAA4;
    // 0x800BFA74: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
L_800BFA78:
    // 0x800BFA78: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFA7C: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BFA80: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BFA84: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFA88: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800BFA8C: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFA90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFA94: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BFA98: sw          $t9, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r25;
    // 0x800BFA9C: b           L_800BFAAC
    // 0x800BFAA0: nop

        goto L_800BFAAC;
    // 0x800BFAA0: nop

L_800BFAA4:
    // 0x800BFAA4: b           L_800BFA2C
    // 0x800BFAA8: nop

        goto L_800BFA2C;
    // 0x800BFAA8: nop

L_800BFAAC:
    // 0x800BFAAC: b           L_800BFB28
    // 0x800BFAB0: nop

        goto L_800BFB28;
    // 0x800BFAB0: nop

L_800BFAB4:
    // 0x800BFAB4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800BFAB8: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x800BFABC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFAC0: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x800BFAC4: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFAC8: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800BFACC: bgez        $t3, L_800BFADC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BFAD0: sra         $t4, $t3, 8
        ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
            goto L_800BFADC;
    }
    // 0x800BFAD0: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800BFAD4: addiu       $at, $t3, 0xFF
    ctx->r1 = ADD32(ctx->r11, 0XFF);
    // 0x800BFAD8: sra         $t4, $at, 8
    ctx->r12 = S32(SIGNED(ctx->r1) >> 8);
L_800BFADC:
    // 0x800BFADC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800BFAE0: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x800BFAE4: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x800BFAE8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFAEC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800BFAF0: lw          $t9, 0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X444);
    // 0x800BFAF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFAF8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BFAFC: sw          $t0, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r8;
    // 0x800BFB00: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800BFB04: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFB08: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BFB0C: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x800BFB10: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BFB14: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x800BFB18: lw          $t5, 0x444($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X444);
    // 0x800BFB1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFB20: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800BFB24: sw          $t2, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r10;
L_800BFB28:
    // 0x800BFB28: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BFB2C: nop

    // 0x800BFB30: bgtz        $t6, L_800BF750
    if (SIGNED(ctx->r14) > 0) {
        // 0x800BFB34: nop
    
            goto L_800BF750;
    }
    // 0x800BFB34: nop

L_800BFB38:
    // 0x800BFB38: jal         0x800C03C8
    // 0x800BFB3C: nop

    func_800C03C8(rdram, ctx);
        goto after_7;
    // 0x800BFB3C: nop

    after_7:
    // 0x800BFB40: jal         0x800C0194
    // 0x800BFB44: nop

    func_800C0194(rdram, ctx);
        goto after_8;
    // 0x800BFB44: nop

    after_8:
    // 0x800BFB48: b           L_800BFB50
    // 0x800BFB4C: nop

        goto L_800BFB50;
    // 0x800BFB4C: nop

L_800BFB50:
    // 0x800BFB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFB54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BFB58: jr          $ra
    // 0x800BFB5C: nop

    return;
    // 0x800BFB5C: nop

;}
RECOMP_FUNC void func_8006FA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FA90: jal         0x80061348
    // 0x8006FA94: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FA94: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FA98: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FA9C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FAA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FAA4: beq         $v0, $zero, L_8006FAF8
    if (ctx->r2 == 0) {
        // 0x8006FAA8: nop
    
            goto L_8006FAF8;
    }
    // 0x8006FAA8: nop

    // 0x8006FAAC: jal         0x80061348
    // 0x8006FAB0: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FAB0: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FAB4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FAB8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FABC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FAC0: beq         $v0, $zero, L_8006FAF8
    if (ctx->r2 == 0) {
        // 0x8006FAC4: nop
    
            goto L_8006FAF8;
    }
    // 0x8006FAC4: nop

    // 0x8006FAC8: jal         0x80061348
    // 0x8006FACC: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FACC: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FAD0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FAD4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FAD8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FADC: beq         $v0, $zero, L_8006FAF8
    if (ctx->r2 == 0) {
        // 0x8006FAE0: nop
    
            goto L_8006FAF8;
    }
    // 0x8006FAE0: nop

    // 0x8006FAE4: jal         0x80061348
    // 0x8006FAE8: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FAE8: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FAEC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FAF0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FAF4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FAF8:
    // 0x8006FAF8: b           L_8006FB08
    // 0x8006FAFC: nop

        goto L_8006FB08;
    // 0x8006FAFC: nop

    // 0x8006FB00: b           L_8006FB08
    // 0x8006FB04: nop

        goto L_8006FB08;
    // 0x8006FB04: nop

L_8006FB08:
    // 0x8006FB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FB0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FB10: jr          $ra
    // 0x8006FB14: nop

    return;
    // 0x8006FB14: nop

;}
RECOMP_FUNC void func_80066240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066248: jal         0x80061348
    // 0x8006624C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006624C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066250: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066254: b           L_80066264
    // 0x80066258: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066264;
    // 0x80066258: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006625C: b           L_80066264
    // 0x80066260: nop

        goto L_80066264;
    // 0x80066260: nop

L_80066264:
    // 0x80066264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006626C: jr          $ra
    // 0x80066270: nop

    return;
    // 0x80066270: nop

;}
RECOMP_FUNC void func_8006CF1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CF20: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CF24: nop

    // 0x8006CF28: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x8006CF2C: nop

    // 0x8006CF30: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CF34: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CF38: jr          $ra
    // 0x8006CF3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CF3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CF40: jr          $ra
    // 0x8006CF44: nop

    return;
    // 0x8006CF44: nop

    // 0x8006CF48: jr          $ra
    // 0x8006CF4C: nop

    return;
    // 0x8006CF4C: nop

;}
RECOMP_FUNC void func_800B1F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1F0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B1F10: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B1F14: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B1F18: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B1F1C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800B1F20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800B1F24: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B1F28: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F2C: nop

    // 0x800B1F30: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B1F34: nop

    // 0x800B1F38: bne         $t7, $zero, L_800B1F54
    if (ctx->r15 != 0) {
        // 0x800B1F3C: nop
    
            goto L_800B1F54;
    }
    // 0x800B1F3C: nop

    // 0x800B1F40: jal         0x800BC6EC
    // 0x800B1F44: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800B1F44: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800B1F48: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F4C: nop

    // 0x800B1F50: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
L_800B1F54:
    // 0x800B1F54: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F58: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B1F5C: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800B1F60: jal         0x800B3EC0
    // 0x800B1F64: nop

    func_800B3EC0(rdram, ctx);
        goto after_1;
    // 0x800B1F64: nop

    after_1:
    // 0x800B1F68: beq         $v0, $zero, L_800B1F78
    if (ctx->r2 == 0) {
        // 0x800B1F6C: nop
    
            goto L_800B1F78;
    }
    // 0x800B1F6C: nop

    // 0x800B1F70: b           L_800B201C
    // 0x800B1F74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B201C;
    // 0x800B1F74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B1F78:
    // 0x800B1F78: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F7C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800B1F80: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800B1F84: lw          $t3, 0xD34($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD34);
    // 0x800B1F88: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800B1F8C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B1F90: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B1F94: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B1F98: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B1F9C: jal         0x800BD1FC
    // 0x800B1FA0: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B1FA0: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x800B1FA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B1FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1FAC: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x800B1FB0: jal         0x800BD218
    // 0x800B1FB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B1FB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x800B1FB8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B1FBC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B1FC0: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x800B1FC4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B1FC8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1FCC: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x800B1FD0: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800B1FD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B1FD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800B1FDC: jal         0x800B23C4
    // 0x800B1FE0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_800B23C4(rdram, ctx);
        goto after_4;
    // 0x800B1FE0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_4:
    // 0x800B1FE4: beq         $v0, $zero, L_800B200C
    if (ctx->r2 == 0) {
        // 0x800B1FE8: nop
    
            goto L_800B200C;
    }
    // 0x800B1FE8: nop

    // 0x800B1FEC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1FF0: nop

    // 0x800B1FF4: lhu         $t6, 0x3A($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B1FF8: nop

    // 0x800B1FFC: ori         $t7, $t6, 0x400
    ctx->r15 = ctx->r14 | 0X400;
    // 0x800B2000: sh          $t7, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r15;
    // 0x800B2004: b           L_800B201C
    // 0x800B2008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B201C;
    // 0x800B2008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B200C:
    // 0x800B200C: b           L_800B201C
    // 0x800B2010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B201C;
    // 0x800B2010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B2014: b           L_800B201C
    // 0x800B2018: nop

        goto L_800B201C;
    // 0x800B2018: nop

L_800B201C:
    // 0x800B201C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2020: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B2024: jr          $ra
    // 0x800B2028: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B2028: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800643D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800643D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800643D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800643DC: jal         0x80061488
    // 0x800643E0: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800643E0: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    after_0:
    // 0x800643E4: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x800643E8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800643EC: b           L_800643FC
    // 0x800643F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800643FC;
    // 0x800643F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800643F4: b           L_800643FC
    // 0x800643F8: nop

        goto L_800643FC;
    // 0x800643F8: nop

L_800643FC:
    // 0x800643FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064404: jr          $ra
    // 0x80064408: nop

    return;
    // 0x80064408: nop

;}
RECOMP_FUNC void AudioMgr_ClearAudioDMA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B93E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B93E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B93E8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B93EC: lw          $t6, -0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3068);
    // 0x800B93F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800B93F4: blez        $t6, L_800B9438
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B93F8: nop
    
            goto L_800B9438;
    }
    // 0x800B93F8: nop

L_800B93FC:
    // 0x800B93FC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9400: addiu       $a0, $a0, -0x3060
    ctx->r4 = ADD32(ctx->r4, -0X3060);
    // 0x800B9404: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800B9408: jal         0x800C1570
    // 0x800B940C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_ReceiveMsg(rdram, ctx);
        goto after_0;
    // 0x800B940C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800B9410: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9414: bne         $v0, $at, L_800B941C
    if (ctx->r2 != ctx->r1) {
        // 0x800B9418: nop
    
            goto L_800B941C;
    }
    // 0x800B9418: nop

L_800B941C:
    // 0x800B941C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B9420: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B9424: lw          $t9, -0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3068);
    // 0x800B9428: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B942C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B9430: bne         $at, $zero, L_800B93FC
    if (ctx->r1 != 0) {
        // 0x800B9434: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_800B93FC;
    }
    // 0x800B9434: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_800B9438:
    // 0x800B9438: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B943C: lw          $t0, -0x336C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X336C);
    // 0x800B9440: nop

    // 0x800B9444: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B9448: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B944C: nop

    // 0x800B9450: beq         $t1, $zero, L_800B9534
    if (ctx->r9 == 0) {
        // 0x800B9454: nop
    
            goto L_800B9534;
    }
    // 0x800B9454: nop

L_800B9458:
    // 0x800B9458: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B945C: nop

    // 0x800B9460: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B9464: nop

    // 0x800B9468: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800B946C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9470: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800B9474: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800B9478: lw          $t4, -0x3364($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3364);
    // 0x800B947C: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x800B9480: sltu        $at, $t7, $t4
    ctx->r1 = ctx->r15 < ctx->r12 ? 1 : 0;
    // 0x800B9484: beq         $at, $zero, L_800B9518
    if (ctx->r1 == 0) {
        // 0x800B9488: nop
    
            goto L_800B9518;
    }
    // 0x800B9488: nop

    // 0x800B948C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9490: lw          $t8, -0x336C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X336C);
    // 0x800B9494: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9498: nop

    // 0x800B949C: bne         $t8, $t9, L_800B94B8
    if (ctx->r24 != ctx->r25) {
        // 0x800B94A0: nop
    
            goto L_800B94B8;
    }
    // 0x800B94A0: nop

    // 0x800B94A4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B94A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B94AC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B94B0: nop

    // 0x800B94B4: sw          $t1, -0x336C($at)
    MEM_W(-0X336C, ctx->r1) = ctx->r9;
L_800B94B8:
    // 0x800B94B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B94BC: jal         0x800C7890
    // 0x800B94C0: nop

    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800B94C0: nop

    after_1:
    // 0x800B94C4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800B94C8: lw          $t2, -0x3368($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3368);
    // 0x800B94CC: nop

    // 0x800B94D0: beq         $t2, $zero, L_800B94F4
    if (ctx->r10 == 0) {
        // 0x800B94D4: nop
    
            goto L_800B94F4;
    }
    // 0x800B94D4: nop

    // 0x800B94D8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B94DC: lw          $a1, -0x3368($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3368);
    // 0x800B94E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B94E4: jal         0x800C78C0
    // 0x800B94E8: nop

    alLink(rdram, ctx);
        goto after_2;
    // 0x800B94E8: nop

    after_2:
    // 0x800B94EC: b           L_800B9518
    // 0x800B94F0: nop

        goto L_800B9518;
    // 0x800B94F0: nop

L_800B94F4:
    // 0x800B94F4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B94F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B94FC: sw          $t3, -0x3368($at)
    MEM_W(-0X3368, ctx->r1) = ctx->r11;
    // 0x800B9500: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9504: nop

    // 0x800B9508: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800B950C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9510: nop

    // 0x800B9514: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_800B9518:
    // 0x800B9518: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B951C: nop

    // 0x800B9520: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B9524: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9528: nop

    // 0x800B952C: bne         $t7, $zero, L_800B9458
    if (ctx->r15 != 0) {
        // 0x800B9530: nop
    
            goto L_800B9458;
    }
    // 0x800B9530: nop

L_800B9534:
    // 0x800B9534: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9538: sw          $zero, -0x3068($at)
    MEM_W(-0X3068, ctx->r1) = 0;
    // 0x800B953C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9540: lw          $t8, -0x3364($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3364);
    // 0x800B9544: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9548: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B954C: sw          $t9, -0x3364($at)
    MEM_W(-0X3364, ctx->r1) = ctx->r25;
    // 0x800B9550: b           L_800B9558
    // 0x800B9554: nop

        goto L_800B9558;
    // 0x800B9554: nop

L_800B9558:
    // 0x800B9558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B955C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B9560: jr          $ra
    // 0x800B9564: nop

    return;
    // 0x800B9564: nop

;}
RECOMP_FUNC void func_80070E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070E7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80070E80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80070E84: nop

    // 0x80070E88: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80070E8C: nop

    // 0x80070E90: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80070E94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80070E98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070E9C: beq         $v0, $zero, L_80070EB8
    if (ctx->r2 == 0) {
        // 0x80070EA0: nop
    
            goto L_80070EB8;
    }
    // 0x80070EA0: nop

    // 0x80070EA4: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80070EA8: nop

    // 0x80070EAC: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80070EB0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80070EB4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80070EB8:
    // 0x80070EB8: jr          $ra
    // 0x80070EBC: nop

    return;
    // 0x80070EBC: nop

    // 0x80070EC0: jr          $ra
    // 0x80070EC4: nop

    return;
    // 0x80070EC4: nop

    // 0x80070EC8: jr          $ra
    // 0x80070ECC: nop

    return;
    // 0x80070ECC: nop

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
RECOMP_FUNC void func_80065B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065B28: jal         0x80061488
    // 0x80065B2C: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065B2C: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065B30: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065B34: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065B38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065B3C: beq         $v0, $zero, L_80065B64
    if (ctx->r2 == 0) {
        // 0x80065B40: nop
    
            goto L_80065B64;
    }
    // 0x80065B40: nop

    // 0x80065B44: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80065B48: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80065B4C: nop

    // 0x80065B50: lh          $v0, 0x36($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X36);
    // 0x80065B54: nop

    // 0x80065B58: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065B5C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065B60: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065B64:
    // 0x80065B64: b           L_80065B74
    // 0x80065B68: nop

        goto L_80065B74;
    // 0x80065B68: nop

    // 0x80065B6C: b           L_80065B74
    // 0x80065B70: nop

        goto L_80065B74;
    // 0x80065B70: nop

L_80065B74:
    // 0x80065B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065B7C: jr          $ra
    // 0x80065B80: nop

    return;
    // 0x80065B80: nop

;}
RECOMP_FUNC void func_80070A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070A68: jal         0x80061348
    // 0x80070A6C: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070A6C: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80070A70: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070A74: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070A78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070A7C: beq         $v0, $zero, L_80070AD0
    if (ctx->r2 == 0) {
        // 0x80070A80: nop
    
            goto L_80070AD0;
    }
    // 0x80070A80: nop

    // 0x80070A84: jal         0x80061348
    // 0x80070A88: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070A88: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_1:
    // 0x80070A8C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070A90: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070A98: beq         $v0, $zero, L_80070AD0
    if (ctx->r2 == 0) {
        // 0x80070A9C: nop
    
            goto L_80070AD0;
    }
    // 0x80070A9C: nop

    // 0x80070AA0: jal         0x80061348
    // 0x80070AA4: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070AA4: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070AA8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070AAC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070AB0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070AB4: beq         $v0, $zero, L_80070AD0
    if (ctx->r2 == 0) {
        // 0x80070AB8: nop
    
            goto L_80070AD0;
    }
    // 0x80070AB8: nop

    // 0x80070ABC: jal         0x80061348
    // 0x80070AC0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070AC0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070AC4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070AC8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070ACC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070AD0:
    // 0x80070AD0: b           L_80070AE0
    // 0x80070AD4: nop

        goto L_80070AE0;
    // 0x80070AD4: nop

    // 0x80070AD8: b           L_80070AE0
    // 0x80070ADC: nop

        goto L_80070AE0;
    // 0x80070ADC: nop

L_80070AE0:
    // 0x80070AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070AE8: jr          $ra
    // 0x80070AEC: nop

    return;
    // 0x80070AEC: nop

;}
RECOMP_FUNC void func_8006E85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E85C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E864: jal         0x80061348
    // 0x8006E868: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E868: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E86C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E870: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E874: beq         $v0, $zero, L_8006E890
    if (ctx->r2 == 0) {
        // 0x8006E878: nop
    
            goto L_8006E890;
    }
    // 0x8006E878: nop

    // 0x8006E87C: jal         0x80061348
    // 0x8006E880: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E880: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    after_1:
    // 0x8006E884: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006E888: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006E88C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E890:
    // 0x8006E890: b           L_8006E8A0
    // 0x8006E894: nop

        goto L_8006E8A0;
    // 0x8006E894: nop

    // 0x8006E898: b           L_8006E8A0
    // 0x8006E89C: nop

        goto L_8006E8A0;
    // 0x8006E89C: nop

L_8006E8A0:
    // 0x8006E8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E8A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E8A8: jr          $ra
    // 0x8006E8AC: nop

    return;
    // 0x8006E8AC: nop

;}
RECOMP_FUNC void func_8001CD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CDA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CDA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001CDA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001CDAC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001CDB0: nop

    // 0x8001CDB4: bltz        $t6, L_8001CDF8
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001CDB8: nop
    
            goto L_8001CDF8;
    }
    // 0x8001CDB8: nop

    // 0x8001CDBC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CDC0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CDC4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CDC8: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001CDCC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CDD0: nop

    // 0x8001CDD4: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CDD8: beq         $t0, $zero, L_8001CDF8
    if (ctx->r8 == 0) {
        // 0x8001CDDC: nop
    
            goto L_8001CDF8;
    }
    // 0x8001CDDC: nop

    // 0x8001CDE0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001CDE4: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8001CDE8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8001CDEC: nop

    // 0x8001CDF0: xori        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 ^ 0X10;
    // 0x8001CDF4: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_8001CDF8:
    // 0x8001CDF8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001CDFC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001CE00: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8001CE04: nop

    // 0x8001CE08: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x8001CE0C: beq         $t6, $zero, L_8001CE28
    if (ctx->r14 == 0) {
        // 0x8001CE10: nop
    
            goto L_8001CE28;
    }
    // 0x8001CE10: nop

    // 0x8001CE14: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CE18: jal         0x8008ECE4
    // 0x8001CE1C: addiu       $a0, $a0, -0x26C4
    ctx->r4 = ADD32(ctx->r4, -0X26C4);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CE1C: addiu       $a0, $a0, -0x26C4
    ctx->r4 = ADD32(ctx->r4, -0X26C4);
    after_0:
    // 0x8001CE20: b           L_8001CE34
    // 0x8001CE24: nop

        goto L_8001CE34;
    // 0x8001CE24: nop

L_8001CE28:
    // 0x8001CE28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CE2C: jal         0x8008ECE4
    // 0x8001CE30: addiu       $a0, $a0, -0x26BC
    ctx->r4 = ADD32(ctx->r4, -0X26BC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CE30: addiu       $a0, $a0, -0x26BC
    ctx->r4 = ADD32(ctx->r4, -0X26BC);
    after_1:
L_8001CE34:
    // 0x8001CE34: b           L_8001CE44
    // 0x8001CE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CE44;
    // 0x8001CE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CE3C: b           L_8001CE44
    // 0x8001CE40: nop

        goto L_8001CE44;
    // 0x8001CE40: nop

L_8001CE44:
    // 0x8001CE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CE4C: jr          $ra
    // 0x8001CE50: nop

    return;
    // 0x8001CE50: nop

;}
RECOMP_FUNC void func_800971D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800971D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800971D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800971DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800971E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800971E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800971E8: jal         0x800C41A0
    // 0x800971EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800971EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800971F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800971F4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800971F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800971FC: nop

    // 0x80097200: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80097204: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80097208: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8009720C: lw          $t9, 0x280($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X280);
    // 0x80097210: nop

    // 0x80097214: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80097218: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8009721C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80097220: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80097224: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80097228: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8009722C: nop

    // 0x80097230: sw          $t3, 0x280($t4)
    MEM_W(0X280, ctx->r12) = ctx->r11;
    // 0x80097234: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80097238: jal         0x800C41A0
    // 0x8009723C: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8009723C: nop

    after_1:
    // 0x80097240: b           L_80097248
    // 0x80097244: nop

        goto L_80097248;
    // 0x80097244: nop

L_80097248:
    // 0x80097248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009724C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097250: jr          $ra
    // 0x80097254: nop

    return;
    // 0x80097254: nop

;}
RECOMP_FUNC void func_800B5AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5AF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B5AF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B5AF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B5AFC: jal         0x800B8104
    // 0x800B5B00: nop

    func_800B8104(rdram, ctx);
        goto after_0;
    // 0x800B5B00: nop

    after_0:
    // 0x800B5B04: beq         $v0, $zero, L_800B5B14
    if (ctx->r2 == 0) {
        // 0x800B5B08: nop
    
            goto L_800B5B14;
    }
    // 0x800B5B08: nop

    // 0x800B5B0C: b           L_800B5E80
    // 0x800B5B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B5E80;
    // 0x800B5B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5B14:
    // 0x800B5B14: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5B18: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5B1C: ori         $at, $zero, 0xE000
    ctx->r1 = 0 | 0XE000;
    // 0x800B5B20: lhu         $s0, 0x6($t6)
    ctx->r16 = MEM_HU(ctx->r14, 0X6);
    // 0x800B5B24: nop

    // 0x800B5B28: beq         $s0, $at, L_800B5B50
    if (ctx->r16 == ctx->r1) {
        // 0x800B5B2C: nop
    
            goto L_800B5B50;
    }
    // 0x800B5B2C: nop

    // 0x800B5B30: ori         $at, $zero, 0xE006
    ctx->r1 = 0 | 0XE006;
    // 0x800B5B34: beq         $s0, $at, L_800B5DE8
    if (ctx->r16 == ctx->r1) {
        // 0x800B5B38: nop
    
            goto L_800B5DE8;
    }
    // 0x800B5B38: nop

    // 0x800B5B3C: ori         $at, $zero, 0xE011
    ctx->r1 = 0 | 0XE011;
    // 0x800B5B40: beq         $s0, $at, L_800B5C70
    if (ctx->r16 == ctx->r1) {
        // 0x800B5B44: nop
    
            goto L_800B5C70;
    }
    // 0x800B5B44: nop

    // 0x800B5B48: b           L_800B5E3C
    // 0x800B5B4C: nop

        goto L_800B5E3C;
    // 0x800B5B4C: nop

L_800B5B50:
    // 0x800B5B50: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5B54: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5B58: nop

    // 0x800B5B5C: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x800B5B60: nop

    // 0x800B5B64: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x800B5B68: beq         $t9, $zero, L_800B5BB8
    if (ctx->r25 == 0) {
        // 0x800B5B6C: nop
    
            goto L_800B5BB8;
    }
    // 0x800B5B6C: nop

    // 0x800B5B70: jal         0x80031AC8
    // 0x800B5B74: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x800B5B74: nop

    after_1:
    // 0x800B5B78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B5B7C: bne         $v0, $at, L_800B5BB0
    if (ctx->r2 != ctx->r1) {
        // 0x800B5B80: nop
    
            goto L_800B5BB0;
    }
    // 0x800B5B80: nop

    // 0x800B5B84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B5B88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5B8C: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x800B5B90: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800B5B94: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800B5B98: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x800B5B9C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x800B5BA0: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x800B5BA4: nor         $t3, $t2, $zero
    ctx->r11 = ~(ctx->r10 | 0);
    // 0x800B5BA8: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x800B5BAC: sh          $t4, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r12;
L_800B5BB0:
    // 0x800B5BB0: b           L_800B5E4C
    // 0x800B5BB4: nop

        goto L_800B5E4C;
    // 0x800B5BB4: nop

L_800B5BB8:
    // 0x800B5BB8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B5BBC: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B5BC0: nop

    // 0x800B5BC4: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x800B5BC8: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800B5BCC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800B5BD0: bgez        $t6, L_800B5BE8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B5BD4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800B5BE8;
    }
    // 0x800B5BD4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B5BD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B5BDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B5BE0: nop

    // 0x800B5BE4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800B5BE8:
    // 0x800B5BE8: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x800B5BEC: nop

    // 0x800B5BF0: bc1f        L_800B5C28
    if (!c1cs) {
        // 0x800B5BF4: nop
    
            goto L_800B5C28;
    }
    // 0x800B5BF4: nop

    // 0x800B5BF8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5BFC: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5C00: nop

    // 0x800B5C04: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x800B5C08: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5C0C: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5C10: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B5C14: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x800B5C18: nop

    // 0x800B5C1C: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x800B5C20: b           L_800B5C68
    // 0x800B5C24: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
        goto L_800B5C68;
    // 0x800B5C24: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
L_800B5C28:
    // 0x800B5C28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5C2C: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800B5C30: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B5C34: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B5C38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B5C3C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B5C40: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B5C44: mul.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800B5C48: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B5C4C: nop

    // 0x800B5C50: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800B5C54: nop

    // 0x800B5C58: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800B5C5C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x800B5C60: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800B5C64: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
L_800B5C68:
    // 0x800B5C68: b           L_800B5E4C
    // 0x800B5C6C: nop

        goto L_800B5E4C;
    // 0x800B5C6C: nop

L_800B5C70:
    // 0x800B5C70: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B5C74: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B5C78: nop

    // 0x800B5C7C: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x800B5C80: nop

    // 0x800B5C84: andi        $t0, $t4, 0x400
    ctx->r8 = ctx->r12 & 0X400;
    // 0x800B5C88: beq         $t0, $zero, L_800B5CD8
    if (ctx->r8 == 0) {
        // 0x800B5C8C: nop
    
            goto L_800B5CD8;
    }
    // 0x800B5C8C: nop

    // 0x800B5C90: jal         0x80031AC8
    // 0x800B5C94: nop

    func_80031AC8(rdram, ctx);
        goto after_2;
    // 0x800B5C94: nop

    after_2:
    // 0x800B5C98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B5C9C: bne         $v0, $at, L_800B5CD0
    if (ctx->r2 != ctx->r1) {
        // 0x800B5CA0: nop
    
            goto L_800B5CD0;
    }
    // 0x800B5CA0: nop

    // 0x800B5CA4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B5CA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5CAC: swc1        $f8, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f8.u32l;
    // 0x800B5CB0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800B5CB4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B5CB8: lhu         $t7, 0x10F2($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X10F2);
    // 0x800B5CBC: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x800B5CC0: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x800B5CC4: nor         $t9, $t7, $zero
    ctx->r25 = ~(ctx->r15 | 0);
    // 0x800B5CC8: and         $t2, $t6, $t9
    ctx->r10 = ctx->r14 & ctx->r25;
    // 0x800B5CCC: sh          $t2, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r10;
L_800B5CD0:
    // 0x800B5CD0: b           L_800B5E4C
    // 0x800B5CD4: nop

        goto L_800B5E4C;
    // 0x800B5CD4: nop

L_800B5CD8:
    // 0x800B5CD8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800B5CDC: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800B5CE0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800B5CE4: lhu         $t3, 0x10F2($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X10F2);
    // 0x800B5CE8: lhu         $t1, 0x6($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X6);
    // 0x800B5CEC: nop

    // 0x800B5CF0: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x800B5CF4: beq         $t4, $zero, L_800B5D30
    if (ctx->r12 == 0) {
        // 0x800B5CF8: nop
    
            goto L_800B5D30;
    }
    // 0x800B5CF8: nop

    // 0x800B5CFC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B5D00: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B5D04: nop

    // 0x800B5D08: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x800B5D0C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5D10: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5D14: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B5D18: lhu         $t6, 0x4($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X4);
    // 0x800B5D1C: nop

    // 0x800B5D20: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x800B5D24: sh          $t9, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r25;
    // 0x800B5D28: b           L_800B5E4C
    // 0x800B5D2C: nop

        goto L_800B5E4C;
    // 0x800B5D2C: nop

L_800B5D30:
    // 0x800B5D30: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B5D34: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B5D38: nop

    // 0x800B5D3C: lhu         $t5, 0x8($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X8);
    // 0x800B5D40: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800B5D44: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800B5D48: bgez        $t5, L_800B5D60
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B5D4C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800B5D60;
    }
    // 0x800B5D4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B5D50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B5D54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B5D58: nop

    // 0x800B5D5C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800B5D60:
    // 0x800B5D60: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x800B5D64: nop

    // 0x800B5D68: bc1f        L_800B5DA0
    if (!c1cs) {
        // 0x800B5D6C: nop
    
            goto L_800B5DA0;
    }
    // 0x800B5D6C: nop

    // 0x800B5D70: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5D74: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5D78: nop

    // 0x800B5D7C: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x800B5D80: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B5D84: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B5D88: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B5D8C: lhu         $t3, 0x4($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X4);
    // 0x800B5D90: nop

    // 0x800B5D94: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800B5D98: b           L_800B5DE0
    // 0x800B5D9C: sh          $t4, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r12;
        goto L_800B5DE0;
    // 0x800B5D9C: sh          $t4, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r12;
L_800B5DA0:
    // 0x800B5DA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5DA4: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800B5DA8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B5DAC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B5DB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B5DB4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B5DB8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800B5DBC: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B5DC0: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B5DC4: nop

    // 0x800B5DC8: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800B5DCC: nop

    // 0x800B5DD0: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x800B5DD4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800B5DD8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800B5DDC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
L_800B5DE0:
    // 0x800B5DE0: b           L_800B5E4C
    // 0x800B5DE4: nop

        goto L_800B5E4C;
    // 0x800B5DE4: nop

L_800B5DE8:
    // 0x800B5DE8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5DEC: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5DF0: nop

    // 0x800B5DF4: lhu         $a0, 0x8($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X8);
    // 0x800B5DF8: jal         0x800B5E90
    // 0x800B5DFC: nop

    func_800B5E90(rdram, ctx);
        goto after_3;
    // 0x800B5DFC: nop

    after_3:
    // 0x800B5E00: beq         $v0, $zero, L_800B5E34
    if (ctx->r2 == 0) {
        // 0x800B5E04: nop
    
            goto L_800B5E34;
    }
    // 0x800B5E04: nop

    // 0x800B5E08: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B5E0C: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B5E10: nop

    // 0x800B5E14: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x800B5E18: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5E1C: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5E20: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B5E24: lhu         $t2, 0x4($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X4);
    // 0x800B5E28: nop

    // 0x800B5E2C: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x800B5E30: sh          $t5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r13;
L_800B5E34:
    // 0x800B5E34: b           L_800B5E4C
    // 0x800B5E38: nop

        goto L_800B5E4C;
    // 0x800B5E38: nop

L_800B5E3C:
    // 0x800B5E3C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5E40: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5E44: nop

    // 0x800B5E48: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
L_800B5E4C:
    // 0x800B5E4C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B5E50: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B5E54: nop

    // 0x800B5E58: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x800B5E5C: nop

    // 0x800B5E60: bne         $t4, $zero, L_800B5E70
    if (ctx->r12 != 0) {
        // 0x800B5E64: nop
    
            goto L_800B5E70;
    }
    // 0x800B5E64: nop

    // 0x800B5E68: b           L_800B5E80
    // 0x800B5E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B5E80;
    // 0x800B5E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B5E70:
    // 0x800B5E70: b           L_800B5E80
    // 0x800B5E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B5E80;
    // 0x800B5E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B5E78: b           L_800B5E80
    // 0x800B5E7C: nop

        goto L_800B5E80;
    // 0x800B5E7C: nop

L_800B5E80:
    // 0x800B5E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5E84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5E88: jr          $ra
    // 0x800B5E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B5E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006D8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D8B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D8BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D8C0: nop

    // 0x8006D8C4: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006D8C8: nop

    // 0x8006D8CC: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D8D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D8D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D8D8: beq         $v0, $zero, L_8006D8F4
    if (ctx->r2 == 0) {
        // 0x8006D8DC: nop
    
            goto L_8006D8F4;
    }
    // 0x8006D8DC: nop

    // 0x8006D8E0: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x8006D8E4: nop

    // 0x8006D8E8: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D8EC: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006D8F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006D8F4:
    // 0x8006D8F4: jr          $ra
    // 0x8006D8F8: nop

    return;
    // 0x8006D8F8: nop

    // 0x8006D8FC: jr          $ra
    // 0x8006D900: nop

    return;
    // 0x8006D900: nop

    // 0x8006D904: jr          $ra
    // 0x8006D908: nop

    return;
    // 0x8006D908: nop

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
RECOMP_FUNC void func_80067144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006714C: jal         0x80061488
    // 0x80067150: addiu       $a0, $zero, 0x2D9
    ctx->r4 = ADD32(0, 0X2D9);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067150: addiu       $a0, $zero, 0x2D9
    ctx->r4 = ADD32(0, 0X2D9);
    after_0:
    // 0x80067154: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80067158: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006715C: b           L_8006716C
    // 0x80067160: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006716C;
    // 0x80067160: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067164: b           L_8006716C
    // 0x80067168: nop

        goto L_8006716C;
    // 0x80067168: nop

L_8006716C:
    // 0x8006716C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067174: jr          $ra
    // 0x80067178: nop

    return;
    // 0x80067178: nop

;}
RECOMP_FUNC void func_8009A04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A04C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009A050: lwc1        $f4, -0x840($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X840);
    // 0x8009A054: add.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x8009A058: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009A05C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009A060: swc1        $f8, 0x18E0($at)
    MEM_W(0X18E0, ctx->r1) = ctx->f8.u32l;
    // 0x8009A064: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009A068: swc1        $f12, 0x18E8($at)
    MEM_W(0X18E8, ctx->r1) = ctx->f12.u32l;
    // 0x8009A06C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009A070: swc1        $f14, 0x18F0($at)
    MEM_W(0X18F0, ctx->r1) = ctx->f14.u32l;
    // 0x8009A074: jr          $ra
    // 0x8009A078: nop

    return;
    // 0x8009A078: nop

    // 0x8009A07C: jr          $ra
    // 0x8009A080: nop

    return;
    // 0x8009A080: nop

;}
RECOMP_FUNC void func_80077694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077694: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077698: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007769C: nop

    // 0x800776A0: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x800776A4: nop

    // 0x800776A8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800776AC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800776B0: jr          $ra
    // 0x800776B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800776B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800776B8: jr          $ra
    // 0x800776BC: nop

    return;
    // 0x800776BC: nop

    // 0x800776C0: jr          $ra
    // 0x800776C4: nop

    return;
    // 0x800776C4: nop

;}
RECOMP_FUNC void func_800651C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800651C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800651C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800651C8: nop

    // 0x800651CC: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x800651D0: nop

    // 0x800651D4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800651D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800651DC: jr          $ra
    // 0x800651E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800651E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800651E4: jr          $ra
    // 0x800651E8: nop

    return;
    // 0x800651E8: nop

    // 0x800651EC: jr          $ra
    // 0x800651F0: nop

    return;
    // 0x800651F0: nop

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
RECOMP_FUNC void func_8006CA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CA10: jal         0x8005F064
    // 0x8006CA14: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CA14: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    after_0:
    // 0x8006CA18: b           L_8006CA28
    // 0x8006CA1C: nop

        goto L_8006CA28;
    // 0x8006CA1C: nop

    // 0x8006CA20: b           L_8006CA28
    // 0x8006CA24: nop

        goto L_8006CA28;
    // 0x8006CA24: nop

L_8006CA28:
    // 0x8006CA28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CA2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CA30: jr          $ra
    // 0x8006CA34: nop

    return;
    // 0x8006CA34: nop

;}
RECOMP_FUNC void func_800719A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800719A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800719A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800719AC: jal         0x8005F064
    // 0x800719B0: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800719B0: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_0:
    // 0x800719B4: b           L_800719C4
    // 0x800719B8: nop

        goto L_800719C4;
    // 0x800719B8: nop

    // 0x800719BC: b           L_800719C4
    // 0x800719C0: nop

        goto L_800719C4;
    // 0x800719C0: nop

L_800719C4:
    // 0x800719C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800719C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800719CC: jr          $ra
    // 0x800719D0: nop

    return;
    // 0x800719D0: nop

;}
RECOMP_FUNC void ContPak_ReadFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEEF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AEEFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AEF00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEF04: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEF08: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800AEF0C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AEF10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEF14: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AEF18: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEF1C: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEF20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEF24: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x800AEF28: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AEF2C: jal         0x800AE40C
    // 0x800AEF30: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_0;
    // 0x800AEF30: nop

    after_0:
    // 0x800AEF34: bgez        $v0, L_800AEF5C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AEF38: nop
    
            goto L_800AEF5C;
    }
    // 0x800AEF38: nop

    // 0x800AEF3C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEF40: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AEF44: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800AEF48: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AEF4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEF50: sw          $t1, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r9;
    // 0x800AEF54: b           L_800AEFC4
    // 0x800AEF58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AEFC4;
    // 0x800AEF58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEF5C:
    // 0x800AEF5C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AEF60: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AEF64: lw          $t3, 0x1670($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1670);
    // 0x800AEF68: lw          $t2, 0x1674($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1674);
    // 0x800AEF6C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AEF70: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800AEF74: lw          $a3, 0x1678($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1678);
    // 0x800AEF78: lw          $a1, 0x167C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X167C);
    // 0x800AEF7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AEF80: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AEF84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AEF88: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AEF8C: jal         0x800C72EC
    // 0x800AEF90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_1;
    // 0x800AEF90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x800AEF94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEF98: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AEF9C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AEFA0: lw          $t4, 0x129C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X129C);
    // 0x800AEFA4: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800AEFA8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800AEFAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEFB0: sw          $t5, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r13;
    // 0x800AEFB4: b           L_800AEFC4
    // 0x800AEFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AEFC4;
    // 0x800AEFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEFBC: b           L_800AEFC4
    // 0x800AEFC0: nop

        goto L_800AEFC4;
    // 0x800AEFC0: nop

L_800AEFC4:
    // 0x800AEFC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEFC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AEFCC: jr          $ra
    // 0x800AEFD0: nop

    return;
    // 0x800AEFD0: nop

;}
RECOMP_FUNC void func_8006EDAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EDB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EDB4: jal         0x80061348
    // 0x8006EDB8: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EDB8: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    after_0:
    // 0x8006EDBC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EDC0: b           L_8006EDD0
    // 0x8006EDC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EDD0;
    // 0x8006EDC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EDC8: b           L_8006EDD0
    // 0x8006EDCC: nop

        goto L_8006EDD0;
    // 0x8006EDCC: nop

L_8006EDD0:
    // 0x8006EDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EDD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EDD8: jr          $ra
    // 0x8006EDDC: nop

    return;
    // 0x8006EDDC: nop

;}
RECOMP_FUNC void func_800029BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800029BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800029C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800029C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800029C8: jal         0x800C41A0
    // 0x800029CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800029CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800029D0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800029D4: jal         0x800C4160
    // 0x800029D8: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x800029D8: nop

    after_1:
    // 0x800029DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800029E0: jal         0x800C4240
    // 0x800029E4: nop

    guRandom(rdram, ctx);
        goto after_2;
    // 0x800029E4: nop

    after_2:
    // 0x800029E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800029EC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800029F0: mfhi        $s0
    ctx->r16 = hi;
    // 0x800029F4: beq         $s0, $zero, L_80002A1C
    if (ctx->r16 == 0) {
        // 0x800029F8: nop
    
            goto L_80002A1C;
    }
    // 0x800029F8: nop

    // 0x800029FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002A00: beq         $s0, $at, L_80002B28
    if (ctx->r16 == ctx->r1) {
        // 0x80002A04: nop
    
            goto L_80002B28;
    }
    // 0x80002A04: nop

    // 0x80002A08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002A0C: beq         $s0, $at, L_80002E3C
    if (ctx->r16 == ctx->r1) {
        // 0x80002A10: nop
    
            goto L_80002E3C;
    }
    // 0x80002A10: nop

    // 0x80002A14: b           L_80002EFC
    // 0x80002A18: nop

        goto L_80002EFC;
    // 0x80002A18: nop

L_80002A1C:
    // 0x80002A1C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_80002A20:
    // 0x80002A20: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80002A24: nop

    // 0x80002A28: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80002A2C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80002A30: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002A34: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80002A38: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80002A3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002A40: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80002A44: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80002A48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002A4C: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x80002A50: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80002A54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002A58: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x80002A5C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80002A60: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80002A64: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80002A68: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80002A6C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80002A70: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80002A74: addiu       $a2, $a2, 0x4F
    ctx->r6 = ADD32(ctx->r6, 0X4F);
    // 0x80002A78: addiu       $a0, $t5, 0x8
    ctx->r4 = ADD32(ctx->r13, 0X8);
    // 0x80002A7C: jal         0x800BD110
    // 0x80002A80: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    SysMem_Copy64(rdram, ctx);
        goto after_3;
    // 0x80002A80: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_3:
    // 0x80002A84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002A88: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_80002A8C:
    // 0x80002A8C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80002A90: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80002A94: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80002A98: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80002A9C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80002AA0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80002AA4: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80002AA8: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x80002AAC: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80002AB0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80002AB4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80002AB8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80002ABC: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x80002AC0: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x80002AC4: jal         0x800BD110
    // 0x80002AC8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    SysMem_Copy64(rdram, ctx);
        goto after_4;
    // 0x80002AC8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_4:
    // 0x80002ACC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80002AD0: nop

    // 0x80002AD4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80002AD8: slti        $at, $t5, 0xF
    ctx->r1 = SIGNED(ctx->r13) < 0XF ? 1 : 0;
    // 0x80002ADC: bne         $at, $zero, L_80002A8C
    if (ctx->r1 != 0) {
        // 0x80002AE0: sw          $t5, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r13;
            goto L_80002A8C;
    }
    // 0x80002AE0: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80002AE4: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x80002AE8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80002AEC:
    // 0x80002AEC: jal         0x800C4270
    // 0x80002AF0: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_5;
    // 0x80002AF0: nop

    after_5:
    // 0x80002AF4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80002AF8: nop

    // 0x80002AFC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80002B00: bgtz        $t8, L_80002AEC
    if (SIGNED(ctx->r24) > 0) {
        // 0x80002B04: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_80002AEC;
    }
    // 0x80002B04: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80002B08: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80002B0C: nop

    // 0x80002B10: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80002B14: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80002B18: bne         $at, $zero, L_80002A20
    if (ctx->r1 != 0) {
        // 0x80002B1C: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_80002A20;
    }
    // 0x80002B1C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80002B20: b           L_80002EFC
    // 0x80002B24: nop

        goto L_80002EFC;
    // 0x80002B24: nop

L_80002B28:
    // 0x80002B28: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_80002B2C:
    // 0x80002B2C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80002B30: nop

    // 0x80002B34: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80002B38: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80002B3C:
    // 0x80002B3C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80002B40:
    // 0x80002B40: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80002B44: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80002B48: bltz        $t2, L_80002DC8
    if (SIGNED(ctx->r10) < 0) {
        // 0x80002B4C: nop
    
            goto L_80002DC8;
    }
    // 0x80002B4C: nop

L_80002B50:
    // 0x80002B50: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80002B54: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80002B58: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80002B5C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80002B60: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80002B64: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80002B68: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80002B6C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80002B70: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80002B74: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80002B78: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80002B7C: lhu         $t4, -0x6100($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X6100);
    // 0x80002B80: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80002B84: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80002B88: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80002B8C: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80002B90: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x80002B94: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002B98: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x80002B9C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80002BA0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80002BA4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80002BA8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80002BAC: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80002BB0: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x80002BB4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002BB8: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x80002BBC: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80002BC0: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80002BC4: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x80002BC8: lhu         $t7, -0x6100($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6100);
    // 0x80002BCC: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x80002BD0: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x80002BD4: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80002BD8: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80002BDC: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80002BE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002BE4: sh          $t9, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r25;
    // 0x80002BE8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80002BEC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80002BF0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80002BF4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80002BF8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80002BFC: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x80002C00: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80002C04: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80002C08: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80002C0C: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80002C10: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x80002C14: lhu         $t5, -0x6100($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X6100);
    // 0x80002C18: sll         $t3, $t3, 6
    ctx->r11 = S32(ctx->r11 << 6);
    // 0x80002C1C: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x80002C20: addu        $t9, $t0, $t2
    ctx->r25 = ADD32(ctx->r8, ctx->r10);
    // 0x80002C24: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x80002C28: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80002C2C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002C30: sh          $t1, 0x20($t7)
    MEM_H(0X20, ctx->r15) = ctx->r9;
    // 0x80002C34: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80002C38: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80002C3C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80002C40: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80002C44: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80002C48: addu        $t6, $t0, $t4
    ctx->r14 = ADD32(ctx->r8, ctx->r12);
    // 0x80002C4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80002C50: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80002C54: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80002C58: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80002C5C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80002C60: lhu         $t0, -0x6100($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X6100);
    // 0x80002C64: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80002C68: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x80002C6C: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x80002C70: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x80002C74: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80002C78: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002C7C: sh          $t3, 0x30($t5)
    MEM_H(0X30, ctx->r13) = ctx->r11;
    // 0x80002C80: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80002C84: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80002C88: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80002C8C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80002C90: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80002C94: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80002C98: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80002C9C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80002CA0: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x80002CA4: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80002CA8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80002CAC: lhu         $t6, -0x6100($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6100);
    // 0x80002CB0: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x80002CB4: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80002CB8: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80002CBC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80002CC0: addu        $t0, $t3, $t7
    ctx->r8 = ADD32(ctx->r11, ctx->r15);
    // 0x80002CC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002CC8: sh          $t9, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r25;
    // 0x80002CCC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80002CD0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80002CD4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80002CD8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80002CDC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80002CE0: addu        $t8, $t2, $t5
    ctx->r24 = ADD32(ctx->r10, ctx->r13);
    // 0x80002CE4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80002CE8: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80002CEC: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x80002CF0: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x80002CF4: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80002CF8: lhu         $t2, -0x6100($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X6100);
    // 0x80002CFC: sll         $t3, $t3, 6
    ctx->r11 = S32(ctx->r11 << 6);
    // 0x80002D00: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x80002D04: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80002D08: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80002D0C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80002D10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002D14: sh          $t1, 0x50($t6)
    MEM_H(0X50, ctx->r14) = ctx->r9;
    // 0x80002D18: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80002D1C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80002D20: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80002D24: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80002D28: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x80002D2C: addu        $t4, $t8, $t0
    ctx->r12 = ADD32(ctx->r24, ctx->r8);
    // 0x80002D30: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80002D34: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80002D38: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80002D3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80002D40: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x80002D44: lhu         $t8, -0x6100($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6100);
    // 0x80002D48: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80002D4C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80002D50: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x80002D54: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80002D58: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80002D5C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002D60: sh          $t3, 0x60($t2)
    MEM_H(0X60, ctx->r10) = ctx->r11;
    // 0x80002D64: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80002D68: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80002D6C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80002D70: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80002D74: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80002D78: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80002D7C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80002D80: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80002D84: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80002D88: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80002D8C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80002D90: lhu         $t4, -0x6100($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X6100);
    // 0x80002D94: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x80002D98: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x80002D9C: addu        $t3, $t7, $t0
    ctx->r11 = ADD32(ctx->r15, ctx->r8);
    // 0x80002DA0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80002DA4: addu        $t8, $t3, $t6
    ctx->r24 = ADD32(ctx->r11, ctx->r14);
    // 0x80002DA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002DAC: sh          $t9, 0x70($t8)
    MEM_H(0X70, ctx->r24) = ctx->r25;
    // 0x80002DB0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80002DB4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80002DB8: addiu       $t7, $t1, 0x1
    ctx->r15 = ADD32(ctx->r9, 0X1);
    // 0x80002DBC: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80002DC0: beq         $at, $zero, L_80002B50
    if (ctx->r1 == 0) {
        // 0x80002DC4: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_80002B50;
    }
    // 0x80002DC4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_80002DC8:
    // 0x80002DC8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80002DCC: nop

    // 0x80002DD0: addiu       $t5, $t2, 0x40
    ctx->r13 = ADD32(ctx->r10, 0X40);
    // 0x80002DD4: slti        $at, $t5, 0x140
    ctx->r1 = SIGNED(ctx->r13) < 0X140 ? 1 : 0;
    // 0x80002DD8: bne         $at, $zero, L_80002B40
    if (ctx->r1 != 0) {
        // 0x80002DDC: sw          $t5, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r13;
            goto L_80002B40;
    }
    // 0x80002DDC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80002DE0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80002DE4: nop

    // 0x80002DE8: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x80002DEC: slti        $at, $t3, 0xF0
    ctx->r1 = SIGNED(ctx->r11) < 0XF0 ? 1 : 0;
    // 0x80002DF0: bne         $at, $zero, L_80002B3C
    if (ctx->r1 != 0) {
        // 0x80002DF4: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_80002B3C;
    }
    // 0x80002DF4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80002DF8: b           L_80002E1C
    // 0x80002DFC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
        goto L_80002E1C;
    // 0x80002DFC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80002E00:
    // 0x80002E00: jal         0x800C4270
    // 0x80002E04: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_6;
    // 0x80002E04: nop

    after_6:
    // 0x80002E08: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80002E0C: nop

    // 0x80002E10: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80002E14: bgtz        $t9, L_80002E00
    if (SIGNED(ctx->r25) > 0) {
        // 0x80002E18: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80002E00;
    }
    // 0x80002E18: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80002E1C:
    // 0x80002E1C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80002E20: nop

    // 0x80002E24: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80002E28: slti        $at, $t1, 0x40
    ctx->r1 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // 0x80002E2C: bne         $at, $zero, L_80002B2C
    if (ctx->r1 != 0) {
        // 0x80002E30: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_80002B2C;
    }
    // 0x80002E30: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80002E34: b           L_80002EFC
    // 0x80002E38: nop

        goto L_80002EFC;
    // 0x80002E38: nop

L_80002E3C:
    // 0x80002E3C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_80002E40:
    // 0x80002E40: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80002E44: nop

    // 0x80002E48: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80002E4C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80002E50:
    // 0x80002E50: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80002E54: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80002E58: bltz        $t0, L_80002E90
    if (SIGNED(ctx->r8) < 0) {
        // 0x80002E5C: nop
    
            goto L_80002E90;
    }
    // 0x80002E5C: nop

L_80002E60:
    // 0x80002E60: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80002E64: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80002E68: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x80002E6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80002E70: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x80002E74: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x80002E78: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80002E7C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80002E80: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80002E84: slt         $at, $t1, $t8
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80002E88: beq         $at, $zero, L_80002E60
    if (ctx->r1 == 0) {
        // 0x80002E8C: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_80002E60;
    }
    // 0x80002E8C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_80002E90:
    // 0x80002E90: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80002E94: nop

    // 0x80002E98: addiu       $t0, $t7, 0xC
    ctx->r8 = ADD32(ctx->r15, 0XC);
    // 0x80002E9C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80002EA0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80002EA4: nop

    // 0x80002EA8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80002EAC: slti        $at, $t5, 0x3200
    ctx->r1 = SIGNED(ctx->r13) < 0X3200 ? 1 : 0;
    // 0x80002EB0: bne         $at, $zero, L_80002E50
    if (ctx->r1 != 0) {
        // 0x80002EB4: sw          $t5, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r13;
            goto L_80002E50;
    }
    // 0x80002EB4: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80002EB8: addiu       $t3, $zero, 0x320
    ctx->r11 = ADD32(0, 0X320);
    // 0x80002EBC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80002EC0:
    // 0x80002EC0: jal         0x800C4270
    // 0x80002EC4: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_7;
    // 0x80002EC4: nop

    after_7:
    // 0x80002EC8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80002ECC: nop

    // 0x80002ED0: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x80002ED4: bgtz        $t6, L_80002EC0
    if (SIGNED(ctx->r14) > 0) {
        // 0x80002ED8: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80002EC0;
    }
    // 0x80002ED8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80002EDC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80002EE0: nop

    // 0x80002EE4: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80002EE8: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x80002EEC: bne         $at, $zero, L_80002E40
    if (ctx->r1 != 0) {
        // 0x80002EF0: sw          $t8, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r24;
            goto L_80002E40;
    }
    // 0x80002EF0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80002EF4: b           L_80002EFC
    // 0x80002EF8: nop

        goto L_80002EFC;
    // 0x80002EF8: nop

L_80002EFC:
    // 0x80002EFC: b           L_80002EFC
    pause_self(rdram);
    // 0x80002F00: nop

    // 0x80002F04: b           L_80002F0C
    // 0x80002F08: nop

        goto L_80002F0C;
    // 0x80002F08: nop

L_80002F0C:
    // 0x80002F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002F10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002F14: jr          $ra
    // 0x80002F18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80002F18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void MtxUtil_ScaleAxes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2948: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C294C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800C2950: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2954: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C2958: nop

    // 0x800C295C: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800C2960: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800C2964: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800C2968: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C296C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C2970: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C2974: nop

    // 0x800C2978: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C297C: nop

    // 0x800C2980: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C2984: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800C2988: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C298C: nop

    // 0x800C2990: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C2994: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800C2998: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C299C: nop

    // 0x800C29A0: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C29A4: nop

    // 0x800C29A8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C29AC: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x800C29B0: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800C29B4: nop

    // 0x800C29B8: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x800C29BC: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x800C29C0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800C29C4: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C29C8: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800C29CC: nop

    // 0x800C29D0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C29D4: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x800C29D8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C29DC: nop

    // 0x800C29E0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C29E4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800C29E8: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C29EC: nop

    // 0x800C29F0: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C29F4: nop

    // 0x800C29F8: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800C29FC: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x800C2A00: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C2A04: nop

    // 0x800C2A08: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800C2A0C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x800C2A10: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C2A14: nop

    // 0x800C2A18: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C2A1C: nop

    // 0x800C2A20: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800C2A24: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
    // 0x800C2A28: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C2A2C: nop

    // 0x800C2A30: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C2A34: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C2A38: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C2A3C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C2A40: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C2A44: nop

    // 0x800C2A48: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C2A4C: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
    // 0x800C2A50: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800C2A54: nop

    // 0x800C2A58: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800C2A5C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800C2A60: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C2A64: nop

    // 0x800C2A68: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800C2A6C: nop

    // 0x800C2A70: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800C2A74: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800C2A78: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C2A7C: nop

    // 0x800C2A80: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C2A84: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C2A88: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C2A8C: nop

    // 0x800C2A90: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C2A94: nop

    // 0x800C2A98: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800C2A9C: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x800C2AA0: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C2AA4: nop

    // 0x800C2AA8: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x800C2AAC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800C2AB0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C2AB4: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C2AB8: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C2ABC: nop

    // 0x800C2AC0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C2AC4: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800C2AC8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C2ACC: nop

    // 0x800C2AD0: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800C2AD4: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800C2AD8: b           L_800C2AE0
    // 0x800C2ADC: nop

        goto L_800C2AE0;
    // 0x800C2ADC: nop

L_800C2AE0:
    // 0x800C2AE0: jr          $ra
    // 0x800C2AE4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C2AE4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006E0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E0D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E0D8: jal         0x80061348
    // 0x8006E0DC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E0DC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006E0E0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E0E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E0E8: beq         $v0, $zero, L_8006E100
    if (ctx->r2 == 0) {
        // 0x8006E0EC: nop
    
            goto L_8006E100;
    }
    // 0x8006E0EC: nop

    // 0x8006E0F0: jal         0x80061348
    // 0x8006E0F4: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E0F4: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    after_1:
    // 0x8006E0F8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E0FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E100:
    // 0x8006E100: b           L_8006E110
    // 0x8006E104: nop

        goto L_8006E110;
    // 0x8006E104: nop

    // 0x8006E108: b           L_8006E110
    // 0x8006E10C: nop

        goto L_8006E110;
    // 0x8006E10C: nop

L_8006E110:
    // 0x8006E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E118: jr          $ra
    // 0x8006E11C: nop

    return;
    // 0x8006E11C: nop

;}
RECOMP_FUNC void func_80062B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062B20: jal         0x8005F064
    // 0x80062B24: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062B24: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    after_0:
    // 0x80062B28: b           L_80062B38
    // 0x80062B2C: nop

        goto L_80062B38;
    // 0x80062B2C: nop

    // 0x80062B30: b           L_80062B38
    // 0x80062B34: nop

        goto L_80062B38;
    // 0x80062B34: nop

L_80062B38:
    // 0x80062B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062B3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062B40: jr          $ra
    // 0x80062B44: nop

    return;
    // 0x80062B44: nop

;}
RECOMP_FUNC void func_800727C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800727C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800727CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800727D0: jal         0x80061488
    // 0x800727D4: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800727D4: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    after_0:
    // 0x800727D8: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800727DC: b           L_800727EC
    // 0x800727E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800727EC;
    // 0x800727E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800727E4: b           L_800727EC
    // 0x800727E8: nop

        goto L_800727EC;
    // 0x800727E8: nop

L_800727EC:
    // 0x800727EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800727F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800727F4: jr          $ra
    // 0x800727F8: nop

    return;
    // 0x800727F8: nop

;}
RECOMP_FUNC void SoundDebugMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800215A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800215A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800215A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800215AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800215B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800215B4: jal         0x8008EAA8
    // 0x800215B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x800215B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800215BC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800215C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800215C4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x800215C8: jal         0x8008ECE4
    // 0x800215CC: addiu       $a0, $a0, -0x1D3C
    ctx->r4 = ADD32(ctx->r4, -0X1D3C);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x800215CC: addiu       $a0, $a0, -0x1D3C
    ctx->r4 = ADD32(ctx->r4, -0X1D3C);
    after_1:
    // 0x800215D0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800215D4: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x800215D8: nop

    // 0x800215DC: beq         $s0, $zero, L_800215F8
    if (ctx->r16 == 0) {
        // 0x800215E0: nop
    
            goto L_800215F8;
    }
    // 0x800215E0: nop

    // 0x800215E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800215E8: beq         $s0, $at, L_80021604
    if (ctx->r16 == ctx->r1) {
        // 0x800215EC: nop
    
            goto L_80021604;
    }
    // 0x800215EC: nop

    // 0x800215F0: b           L_80021880
    // 0x800215F4: nop

        goto L_80021880;
    // 0x800215F4: nop

L_800215F8:
    // 0x800215F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800215FC: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80021600: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_80021604:
    // 0x80021604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80021608: jal         0x8008EAA8
    // 0x8002160C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8002160C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80021610: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021614: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x80021618: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002161C: nop

    // 0x80021620: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80021624: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80021628: addiu       $t0, $t0, -0x49F0
    ctx->r8 = ADD32(ctx->r8, -0X49F0);
    // 0x8002162C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80021630: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80021634: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80021638:
    // 0x80021638: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8002163C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021640: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80021644: nop

    // 0x80021648: bne         $t2, $at, L_80021658
    if (ctx->r10 != ctx->r1) {
        // 0x8002164C: nop
    
            goto L_80021658;
    }
    // 0x8002164C: nop

    // 0x80021650: b           L_800217C4
    // 0x80021654: nop

        goto L_800217C4;
    // 0x80021654: nop

L_80021658:
    // 0x80021658: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002165C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021660: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80021664: nop

    // 0x80021668: beq         $t4, $at, L_800216A4
    if (ctx->r12 == ctx->r1) {
        // 0x8002166C: nop
    
            goto L_800216A4;
    }
    // 0x8002166C: nop

    // 0x80021670: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80021674: nop

    // 0x80021678: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8002167C: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    // 0x80021680: jal         0x8008EAA8
    // 0x80021684: nop

    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x80021684: nop

    after_3:
    // 0x80021688: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002168C: nop

    // 0x80021690: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80021694: nop

    // 0x80021698: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002169C: b           L_800216C0
    // 0x800216A0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_800216C0;
    // 0x800216A0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_800216A4:
    // 0x800216A4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800216A8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800216AC: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800216B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800216B4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800216B8: jal         0x8008EAA8
    // 0x800216BC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x800216BC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_4:
L_800216C0:
    // 0x800216C0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800216C4: nop

    // 0x800216C8: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x800216CC: nop

    // 0x800216D0: beq         $t3, $zero, L_80021794
    if (ctx->r11 == 0) {
        // 0x800216D4: nop
    
            goto L_80021794;
    }
    // 0x800216D4: nop

    // 0x800216D8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800216DC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800216E0: nop

    // 0x800216E4: bne         $t4, $t5, L_8002173C
    if (ctx->r12 != ctx->r13) {
        // 0x800216E8: nop
    
            goto L_8002173C;
    }
    // 0x800216E8: nop

    // 0x800216EC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800216F0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800216F4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x800216F8: jal         0x8008ECE4
    // 0x800216FC: addiu       $a0, $a0, -0x1D30
    ctx->r4 = ADD32(ctx->r4, -0X1D30);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x800216FC: addiu       $a0, $a0, -0x1D30
    ctx->r4 = ADD32(ctx->r4, -0X1D30);
    after_5:
    // 0x80021700: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80021704: nop

    // 0x80021708: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8002170C: nop

    // 0x80021710: beq         $t8, $zero, L_80021734
    if (ctx->r24 == 0) {
        // 0x80021714: nop
    
            goto L_80021734;
    }
    // 0x80021714: nop

    // 0x80021718: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8002171C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021720: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80021724: lw          $t9, 0x14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X14);
    // 0x80021728: nop

    // 0x8002172C: jalr        $t9
    // 0x80021730: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80021730: nop

    after_6:
L_80021734:
    // 0x80021734: b           L_80021780
    // 0x80021738: nop

        goto L_80021780;
    // 0x80021738: nop

L_8002173C:
    // 0x8002173C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80021740: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021744: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x80021748: jal         0x8008ECE4
    // 0x8002174C: addiu       $a0, $a0, -0x1D2C
    ctx->r4 = ADD32(ctx->r4, -0X1D2C);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8002174C: addiu       $a0, $a0, -0x1D2C
    ctx->r4 = ADD32(ctx->r4, -0X1D2C);
    after_7:
    // 0x80021750: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80021754: nop

    // 0x80021758: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8002175C: nop

    // 0x80021760: beq         $t2, $zero, L_80021780
    if (ctx->r10 == 0) {
        // 0x80021764: nop
    
            goto L_80021780;
    }
    // 0x80021764: nop

    // 0x80021768: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002176C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80021770: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x80021774: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80021778: jalr        $t9
    // 0x8002177C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8002177C: nop

    after_8:
L_80021780:
    // 0x80021780: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80021784: nop

    // 0x80021788: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002178C: b           L_800217A8
    // 0x80021790: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
        goto L_800217A8;
    // 0x80021790: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_80021794:
    // 0x80021794: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80021798: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002179C: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x800217A0: jal         0x8008ECE4
    // 0x800217A4: addiu       $a0, $a0, -0x1D28
    ctx->r4 = ADD32(ctx->r4, -0X1D28);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x800217A4: addiu       $a0, $a0, -0x1D28
    ctx->r4 = ADD32(ctx->r4, -0X1D28);
    after_9:
L_800217A8:
    // 0x800217A8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800217AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800217B0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800217B4: addiu       $t1, $t0, 0x28
    ctx->r9 = ADD32(ctx->r8, 0X28);
    // 0x800217B8: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800217BC: b           L_80021638
    // 0x800217C0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80021638;
    // 0x800217C0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800217C4:
    // 0x800217C4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800217C8: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x800217CC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800217D0: lhu         $t9, 0xE68($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE68);
    // 0x800217D4: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800217D8: nop

    // 0x800217DC: and         $t4, $t3, $t9
    ctx->r12 = ctx->r11 & ctx->r25;
    // 0x800217E0: beq         $t4, $zero, L_800217F8
    if (ctx->r12 == 0) {
        // 0x800217E4: nop
    
            goto L_800217F8;
    }
    // 0x800217E4: nop

    // 0x800217E8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800217EC: nop

    // 0x800217F0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800217F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_800217F8:
    // 0x800217F8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800217FC: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80021800: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021804: lhu         $t0, 0xE74($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XE74);
    // 0x80021808: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8002180C: nop

    // 0x80021810: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x80021814: beq         $t1, $zero, L_8002182C
    if (ctx->r9 == 0) {
        // 0x80021818: nop
    
            goto L_8002182C;
    }
    // 0x80021818: nop

    // 0x8002181C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80021820: nop

    // 0x80021824: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80021828: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_8002182C:
    // 0x8002182C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80021830: nop

    // 0x80021834: bgez        $t9, L_8002184C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80021838: nop
    
            goto L_8002184C;
    }
    // 0x80021838: nop

    // 0x8002183C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80021840: nop

    // 0x80021844: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80021848: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8002184C:
    // 0x8002184C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80021850: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80021854: nop

    // 0x80021858: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002185C: bne         $at, $zero, L_80021868
    if (ctx->r1 != 0) {
        // 0x80021860: nop
    
            goto L_80021868;
    }
    // 0x80021860: nop

    // 0x80021864: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80021868:
    // 0x80021868: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002186C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021870: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80021874: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80021878: b           L_80021880
    // 0x8002187C: nop

        goto L_80021880;
    // 0x8002187C: nop

L_80021880:
    // 0x80021880: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80021884: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x80021888: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002188C: lhu         $t3, 0x11A4($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X11A4);
    // 0x80021890: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x80021894: nop

    // 0x80021898: and         $t9, $t2, $t3
    ctx->r25 = ctx->r10 & ctx->r11;
    // 0x8002189C: beq         $t9, $zero, L_800218AC
    if (ctx->r25 == 0) {
        // 0x800218A0: nop
    
            goto L_800218AC;
    }
    // 0x800218A0: nop

    // 0x800218A4: b           L_800218BC
    // 0x800218A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800218BC;
    // 0x800218A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800218AC:
    // 0x800218AC: b           L_800218BC
    // 0x800218B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800218BC;
    // 0x800218B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800218B4: b           L_800218BC
    // 0x800218B8: nop

        goto L_800218BC;
    // 0x800218B8: nop

L_800218BC:
    // 0x800218BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800218C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800218C4: jr          $ra
    // 0x800218C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800218C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Spi_LimitedDecompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEE48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BEE4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEE50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BEE54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BEE58: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEE5C: jal         0x800BC6EC
    // 0x800BEE60: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800BEE60: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x800BEE64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BEE68: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEE6C: nop

    // 0x800BEE70: bne         $t6, $zero, L_800BEE80
    if (ctx->r14 != 0) {
        // 0x800BEE74: nop
    
            goto L_800BEE80;
    }
    // 0x800BEE74: nop

    // 0x800BEE78: b           L_800BF0A4
    // 0x800BEE7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BF0A4;
    // 0x800BEE7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BEE80:
    // 0x800BEE80: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEE84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800BEE88: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x800BEE8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEE90: bgez        $a2, L_800BEEA0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BEE94: sra         $t7, $a2, 3
        ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
            goto L_800BEEA0;
    }
    // 0x800BEE94: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800BEE98: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x800BEE9C: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800BEEA0:
    // 0x800BEEA0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800BEEA4: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800BEEA8: jal         0x800BD218
    // 0x800BEEAC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800BEEAC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_1:
    // 0x800BEEB0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEEB4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEEB8: sw          $t9, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r25;
    // 0x800BEEBC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BEEC0: lw          $t0, 0x434($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X434);
    // 0x800BEEC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEEC8: sw          $t0, 0x458($at)
    MEM_W(0X458, ctx->r1) = ctx->r8;
    // 0x800BEECC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BEED0: addiu       $t1, $t1, 0x490
    ctx->r9 = ADD32(ctx->r9, 0X490);
    // 0x800BEED4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800BEED8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BEEDC: addiu       $t2, $t2, 0x4A8
    ctx->r10 = ADD32(ctx->r10, 0X4A8);
    // 0x800BEEE0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEEE4: sw          $t2, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r10;
    // 0x800BEEE8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BEEEC:
    // 0x800BEEEC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BEEF0: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BEEF4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BEEF8: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800BEEFC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BEF00: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x800BEF04: lw          $t8, 0x434($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434);
    // 0x800BEF08: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BEF0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEF10: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BEF14: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BEF18: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800BEF1C: sw          $t9, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r25;
    // 0x800BEF20: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BEF24: nop

    // 0x800BEF28: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BEF2C: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x800BEF30: bne         $at, $zero, L_800BEEEC
    if (ctx->r1 != 0) {
        // 0x800BEF34: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_800BEEEC;
    }
    // 0x800BEF34: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800BEF38: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BEF3C: addiu       $t2, $t2, 0x490
    ctx->r10 = ADD32(ctx->r10, 0X490);
    // 0x800BEF40: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x800BEF44: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800BEF48: beq         $t3, $at, L_800BF048
    if (ctx->r11 == ctx->r1) {
        // 0x800BEF4C: nop
    
            goto L_800BF048;
    }
    // 0x800BEF4C: nop

    // 0x800BEF50: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BEF54:
    // 0x800BEF54: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BEF58: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BEF5C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BEF60: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800BEF64: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BEF68: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800BEF6C: lw          $t9, 0x434($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X434);
    // 0x800BEF70: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BEF74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEF78: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BEF7C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BEF80: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800BEF84: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
    // 0x800BEF88: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BEF8C: nop

    // 0x800BEF90: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BEF94: sltiu       $at, $t2, 0xC
    ctx->r1 = ctx->r10 < 0XC ? 1 : 0;
    // 0x800BEF98: bne         $at, $zero, L_800BEF54
    if (ctx->r1 != 0) {
        // 0x800BEF9C: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800BEF54;
    }
    // 0x800BEF9C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800BEFA0: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BEFA4: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BEFA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEFAC: sw          $t3, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r11;
    // 0x800BEFB0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BEFB4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BEFB8: lw          $t5, 0x498($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X498);
    // 0x800BEFBC: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BEFC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEFC4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800BEFC8: sw          $t6, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r14;
    // 0x800BEFCC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BEFD0: lw          $t7, 0x434($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X434);
    // 0x800BEFD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEFD8: sw          $t7, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r15;
    // 0x800BEFDC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BEFE0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BEFE4: lw          $t9, 0x49C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X49C);
    // 0x800BEFE8: lw          $t8, 0x434($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434);
    // 0x800BEFEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BEFF0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BEFF4: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
    // 0x800BEFF8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BEFFC: lw          $t1, 0x434($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X434);
    // 0x800BF000: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF004: sw          $t1, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r9;
    // 0x800BF008: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF00C: lw          $t2, 0x454($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X454);
    // 0x800BF010: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF014: sw          $t2, 0x46C($at)
    MEM_W(0X46C, ctx->r1) = ctx->r10;
    // 0x800BF018: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF01C: lw          $t3, 0x43C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X43C);
    // 0x800BF020: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF024: sw          $t3, 0x45C($at)
    MEM_W(0X45C, ctx->r1) = ctx->r11;
    // 0x800BF028: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF02C: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BF030: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF034: sw          $t4, 0x460($at)
    MEM_W(0X460, ctx->r1) = ctx->r12;
    // 0x800BF038: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF03C: lw          $t5, 0x44C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X44C);
    // 0x800BF040: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF044: sw          $t5, 0x464($at)
    MEM_W(0X464, ctx->r1) = ctx->r13;
L_800BF048:
    // 0x800BF048: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BF04C: lw          $t6, 0x494($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X494);
    // 0x800BF050: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800BF054: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800BF058: sltu        $at, $t6, $at
    ctx->r1 = ctx->r14 < ctx->r1 ? 1 : 0;
    // 0x800BF05C: beq         $at, $zero, L_800BF088
    if (ctx->r1 == 0) {
        // 0x800BF060: nop
    
            goto L_800BF088;
    }
    // 0x800BF060: nop

    // 0x800BF064: jal         0x800BFB60
    // 0x800BF068: nop

    Spi_Decompress(rdram, ctx);
        goto after_2;
    // 0x800BF068: nop

    after_2:
    // 0x800BF06C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF070: jal         0x800BC980
    // 0x800BF074: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800BF074: nop

    after_3:
    // 0x800BF078: b           L_800BF0A4
    // 0x800BF07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF0A4;
    // 0x800BF07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF080: b           L_800BF09C
    // 0x800BF084: nop

        goto L_800BF09C;
    // 0x800BF084: nop

L_800BF088:
    // 0x800BF088: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF08C: jal         0x800BC980
    // 0x800BF090: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x800BF090: nop

    after_4:
    // 0x800BF094: b           L_800BF0A4
    // 0x800BF098: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BF0A4;
    // 0x800BF098: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BF09C:
    // 0x800BF09C: b           L_800BF0A4
    // 0x800BF0A0: nop

        goto L_800BF0A4;
    // 0x800BF0A0: nop

L_800BF0A4:
    // 0x800BF0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF0A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BF0AC: jr          $ra
    // 0x800BF0B0: nop

    return;
    // 0x800BF0B0: nop

;}
RECOMP_FUNC void func_8006FDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FDC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FDC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FDCC: jal         0x80061348
    // 0x8006FDD0: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FDD0: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FDD4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FDD8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FDDC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FDE0: beq         $v0, $zero, L_8006FE34
    if (ctx->r2 == 0) {
        // 0x8006FDE4: nop
    
            goto L_8006FE34;
    }
    // 0x8006FDE4: nop

    // 0x8006FDE8: jal         0x80061348
    // 0x8006FDEC: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FDEC: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FDF0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FDF4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FDF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FDFC: beq         $v0, $zero, L_8006FE34
    if (ctx->r2 == 0) {
        // 0x8006FE00: nop
    
            goto L_8006FE34;
    }
    // 0x8006FE00: nop

    // 0x8006FE04: jal         0x80061348
    // 0x8006FE08: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FE08: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FE0C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FE10: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FE14: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FE18: beq         $v0, $zero, L_8006FE34
    if (ctx->r2 == 0) {
        // 0x8006FE1C: nop
    
            goto L_8006FE34;
    }
    // 0x8006FE1C: nop

    // 0x8006FE20: jal         0x80061348
    // 0x8006FE24: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FE24: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FE28: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FE2C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FE30: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FE34:
    // 0x8006FE34: b           L_8006FE44
    // 0x8006FE38: nop

        goto L_8006FE44;
    // 0x8006FE38: nop

    // 0x8006FE3C: b           L_8006FE44
    // 0x8006FE40: nop

        goto L_8006FE44;
    // 0x8006FE40: nop

L_8006FE44:
    // 0x8006FE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FE48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FE4C: jr          $ra
    // 0x8006FE50: nop

    return;
    // 0x8006FE50: nop

;}
RECOMP_FUNC void func_80062C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C78: jal         0x80061488
    // 0x80062C7C: addiu       $a0, $zero, 0x6C5
    ctx->r4 = ADD32(0, 0X6C5);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062C7C: addiu       $a0, $zero, 0x6C5
    ctx->r4 = ADD32(0, 0X6C5);
    after_0:
    // 0x80062C80: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062C84: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062C88: b           L_80062C98
    // 0x80062C8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062C98;
    // 0x80062C8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062C90: b           L_80062C98
    // 0x80062C94: nop

        goto L_80062C98;
    // 0x80062C94: nop

L_80062C98:
    // 0x80062C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062CA0: jr          $ra
    // 0x80062CA4: nop

    return;
    // 0x80062CA4: nop

;}
RECOMP_FUNC void func_800B1A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1A50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A54: sw          $a0, 0xD30($at)
    MEM_W(0XD30, ctx->r1) = ctx->r4;
    // 0x800B1A58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A5C: sw          $a1, 0xD34($at)
    MEM_W(0XD34, ctx->r1) = ctx->r5;
    // 0x800B1A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A64: sw          $a2, 0xD38($at)
    MEM_W(0XD38, ctx->r1) = ctx->r6;
    // 0x800B1A68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A6C: sw          $a3, 0xD3C($at)
    MEM_W(0XD3C, ctx->r1) = ctx->r7;
    // 0x800B1A70: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800B1A74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A78: sw          $t6, 0xD40($at)
    MEM_W(0XD40, ctx->r1) = ctx->r14;
    // 0x800B1A7C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800B1A80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A84: sw          $t7, 0xD44($at)
    MEM_W(0XD44, ctx->r1) = ctx->r15;
    // 0x800B1A88: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B1A8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A90: sw          $t8, 0xD48($at)
    MEM_W(0XD48, ctx->r1) = ctx->r24;
    // 0x800B1A94: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1A98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A9C: sw          $t9, 0xD4C($at)
    MEM_W(0XD4C, ctx->r1) = ctx->r25;
    // 0x800B1AA0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B1AA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AA8: sw          $t0, 0xD50($at)
    MEM_W(0XD50, ctx->r1) = ctx->r8;
    // 0x800B1AAC: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x800B1AB0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AB4: sh          $t1, 0xD54($at)
    MEM_H(0XD54, ctx->r1) = ctx->r9;
    // 0x800B1AB8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800B1ABC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AC0: sw          $t2, 0xD60($at)
    MEM_W(0XD60, ctx->r1) = ctx->r10;
    // 0x800B1AC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AC8: sw          $zero, 0xD64($at)
    MEM_W(0XD64, ctx->r1) = 0;
    // 0x800B1ACC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AD0: sh          $zero, 0xD68($at)
    MEM_H(0XD68, ctx->r1) = 0;
    // 0x800B1AD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AD8: sh          $zero, 0xD6A($at)
    MEM_H(0XD6A, ctx->r1) = 0;
    // 0x800B1ADC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AE0: sh          $zero, 0xD6C($at)
    MEM_H(0XD6C, ctx->r1) = 0;
    // 0x800B1AE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AE8: sb          $zero, 0xD6E($at)
    MEM_B(0XD6E, ctx->r1) = 0;
    // 0x800B1AEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AF0: sb          $zero, 0xD6F($at)
    MEM_B(0XD6F, ctx->r1) = 0;
    // 0x800B1AF4: jr          $ra
    // 0x800B1AF8: nop

    return;
    // 0x800B1AF8: nop

    // 0x800B1AFC: jr          $ra
    // 0x800B1B00: nop

    return;
    // 0x800B1B00: nop

;}
RECOMP_FUNC void func_80066DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066DF8: jal         0x80061348
    // 0x80066DFC: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066DFC: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x80066E00: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066E04: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066E08: b           L_80066E18
    // 0x80066E0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066E18;
    // 0x80066E0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066E10: b           L_80066E18
    // 0x80066E14: nop

        goto L_80066E18;
    // 0x80066E14: nop

L_80066E18:
    // 0x80066E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066E20: jr          $ra
    // 0x80066E24: nop

    return;
    // 0x80066E24: nop

;}
RECOMP_FUNC void func_80064D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064D2C: jal         0x80061488
    // 0x80064D30: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064D30: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064D34: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064D38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064D3C: beq         $v0, $zero, L_80064DD0
    if (ctx->r2 == 0) {
        // 0x80064D40: nop
    
            goto L_80064DD0;
    }
    // 0x80064D40: nop

    // 0x80064D44: jal         0x80061488
    // 0x80064D48: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064D48: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064D4C: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064D50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064D54: beq         $v0, $zero, L_80064DD0
    if (ctx->r2 == 0) {
        // 0x80064D58: nop
    
            goto L_80064DD0;
    }
    // 0x80064D58: nop

    // 0x80064D5C: jal         0x80061488
    // 0x80064D60: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064D60: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x80064D64: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064D68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064D6C: beq         $v0, $zero, L_80064DD0
    if (ctx->r2 == 0) {
        // 0x80064D70: nop
    
            goto L_80064DD0;
    }
    // 0x80064D70: nop

    // 0x80064D74: jal         0x80061488
    // 0x80064D78: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x80064D78: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064D7C: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064D80: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80064D84: beq         $v0, $zero, L_80064DD0
    if (ctx->r2 == 0) {
        // 0x80064D88: nop
    
            goto L_80064DD0;
    }
    // 0x80064D88: nop

    // 0x80064D8C: jal         0x80061488
    // 0x80064D90: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064D90: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x80064D94: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064D98: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064D9C: beq         $v0, $zero, L_80064DD0
    if (ctx->r2 == 0) {
        // 0x80064DA0: nop
    
            goto L_80064DD0;
    }
    // 0x80064DA0: nop

    // 0x80064DA4: jal         0x8005F064
    // 0x80064DA8: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064DA8: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064DAC: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064DB0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064DB4: beq         $v0, $zero, L_80064DD0
    if (ctx->r2 == 0) {
        // 0x80064DB8: nop
    
            goto L_80064DD0;
    }
    // 0x80064DB8: nop

    // 0x80064DBC: jal         0x80061348
    // 0x80064DC0: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064DC0: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064DC4: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064DC8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064DCC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064DD0:
    // 0x80064DD0: b           L_80064DE0
    // 0x80064DD4: nop

        goto L_80064DE0;
    // 0x80064DD4: nop

    // 0x80064DD8: b           L_80064DE0
    // 0x80064DDC: nop

        goto L_80064DE0;
    // 0x80064DDC: nop

L_80064DE0:
    // 0x80064DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064DE8: jr          $ra
    // 0x80064DEC: nop

    return;
    // 0x80064DEC: nop

;}
RECOMP_FUNC void func_80065600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065600: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065604: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065608: nop

    // 0x8006560C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80065610: nop

    // 0x80065614: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80065618: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006561C: beq         $v0, $zero, L_80065638
    if (ctx->r2 == 0) {
        // 0x80065620: nop
    
            goto L_80065638;
    }
    // 0x80065620: nop

    // 0x80065624: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80065628: nop

    // 0x8006562C: slti        $t8, $v0, 0x12D
    ctx->r24 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80065630: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065634: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065638:
    // 0x80065638: jr          $ra
    // 0x8006563C: nop

    return;
    // 0x8006563C: nop

    // 0x80065640: jr          $ra
    // 0x80065644: nop

    return;
    // 0x80065644: nop

    // 0x80065648: jr          $ra
    // 0x8006564C: nop

    return;
    // 0x8006564C: nop

;}
