#include "recomp.h"
#include "shims.h"
#include "funcs.h"

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
RECOMP_FUNC void func_80069D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80069D74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80069D78: nop

    // 0x80069D7C: lh          $v0, 0x3A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X3A);
    // 0x80069D80: nop

    // 0x80069D84: xori        $t7, $v0, 0x3E7
    ctx->r15 = ctx->r2 ^ 0X3E7;
    // 0x80069D88: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069D8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069D90: beq         $v0, $zero, L_80069DAC
    if (ctx->r2 == 0) {
        // 0x80069D94: nop

            goto L_80069DAC;
    }
    // 0x80069D94: nop

    // 0x80069D98: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80069D9C: nop

    // 0x80069DA0: xori        $t8, $v0, 0x3E7
    ctx->r24 = ctx->r2 ^ 0X3E7;
    // 0x80069DA4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069DA8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80069DAC:
    // 0x80069DAC: jr          $ra
    // 0x80069DB0: nop

    return;
    // 0x80069DB0: nop

    // 0x80069DB4: jr          $ra
    // 0x80069DB8: nop

    return;
    // 0x80069DB8: nop

    // 0x80069DBC: jr          $ra
    // 0x80069DC0: nop

    return;
    // 0x80069DC0: nop

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
RECOMP_FUNC void func_80069DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069E00: jal         0x80061348
    // 0x80069E04: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069E04: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x80069E08: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80069E0C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069E10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069E14: beq         $v0, $zero, L_80069E54
    if (ctx->r2 == 0) {
        // 0x80069E18: nop

            goto L_80069E54;
    }
    // 0x80069E18: nop

    // 0x80069E1C: jal         0x80061348
    // 0x80069E20: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069E20: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x80069E24: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069E28: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069E2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069E30: beq         $v0, $zero, L_80069E54
    if (ctx->r2 == 0) {
        // 0x80069E34: nop

            goto L_80069E54;
    }
    // 0x80069E34: nop

    // 0x80069E38: jal         0x80061348
    // 0x80069E3C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80069E3C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x80069E40: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069E44: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069E48: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069E4C: bne         $v0, $zero, L_8006A098
    if (ctx->r2 != 0) {
        // 0x80069E50: nop

            goto L_8006A098;
    }
    // 0x80069E50: nop

L_80069E54:
    // 0x80069E54: jal         0x80061348
    // 0x80069E58: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80069E58: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x80069E5C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069E60: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069E64: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069E68: beq         $v0, $zero, L_80069EA8
    if (ctx->r2 == 0) {
        // 0x80069E6C: nop

            goto L_80069EA8;
    }
    // 0x80069E6C: nop

    // 0x80069E70: jal         0x80061348
    // 0x80069E74: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x80069E74: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x80069E78: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80069E7C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069E80: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069E84: beq         $v0, $zero, L_80069EA8
    if (ctx->r2 == 0) {
        // 0x80069E88: nop

            goto L_80069EA8;
    }
    // 0x80069E88: nop

    // 0x80069E8C: jal         0x80061348
    // 0x80069E90: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x80069E90: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x80069E94: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069E98: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069E9C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069EA0: bne         $v0, $zero, L_8006A098
    if (ctx->r2 != 0) {
        // 0x80069EA4: nop

            goto L_8006A098;
    }
    // 0x80069EA4: nop

L_80069EA8:
    // 0x80069EA8: jal         0x80061348
    // 0x80069EAC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80069EAC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x80069EB0: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069EB4: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069EB8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80069EBC: beq         $v0, $zero, L_80069EFC
    if (ctx->r2 == 0) {
        // 0x80069EC0: nop

            goto L_80069EFC;
    }
    // 0x80069EC0: nop

    // 0x80069EC4: jal         0x80061348
    // 0x80069EC8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x80069EC8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x80069ECC: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069ED0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80069ED4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069ED8: beq         $v0, $zero, L_80069EFC
    if (ctx->r2 == 0) {
        // 0x80069EDC: nop

            goto L_80069EFC;
    }
    // 0x80069EDC: nop

    // 0x80069EE0: jal         0x80061348
    // 0x80069EE4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x80069EE4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x80069EE8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x80069EEC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069EF0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069EF4: bne         $v0, $zero, L_8006A098
    if (ctx->r2 != 0) {
        // 0x80069EF8: nop

            goto L_8006A098;
    }
    // 0x80069EF8: nop

L_80069EFC:
    // 0x80069EFC: jal         0x80061348
    // 0x80069F00: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x80069F00: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x80069F04: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069F08: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80069F0C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069F10: beq         $v0, $zero, L_80069F50
    if (ctx->r2 == 0) {
        // 0x80069F14: nop

            goto L_80069F50;
    }
    // 0x80069F14: nop

    // 0x80069F18: jal         0x80061348
    // 0x80069F1C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x80069F1C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x80069F20: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80069F24: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069F28: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069F2C: beq         $v0, $zero, L_80069F50
    if (ctx->r2 == 0) {
        // 0x80069F30: nop

            goto L_80069F50;
    }
    // 0x80069F30: nop

    // 0x80069F34: jal         0x80061348
    // 0x80069F38: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x80069F38: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x80069F3C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069F40: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069F44: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069F48: bne         $v0, $zero, L_8006A098
    if (ctx->r2 != 0) {
        // 0x80069F4C: nop

            goto L_8006A098;
    }
    // 0x80069F4C: nop

L_80069F50:
    // 0x80069F50: jal         0x80061348
    // 0x80069F54: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x80069F54: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x80069F58: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069F5C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069F60: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069F64: beq         $v0, $zero, L_80069FA4
    if (ctx->r2 == 0) {
        // 0x80069F68: nop

            goto L_80069FA4;
    }
    // 0x80069F68: nop

    // 0x80069F6C: jal         0x80061348
    // 0x80069F70: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x80069F70: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x80069F74: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069F78: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069F7C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069F80: beq         $v0, $zero, L_80069FA4
    if (ctx->r2 == 0) {
        // 0x80069F84: nop

            goto L_80069FA4;
    }
    // 0x80069F84: nop

    // 0x80069F88: jal         0x80061348
    // 0x80069F8C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x80069F8C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x80069F90: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80069F94: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069F98: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069F9C: bne         $v0, $zero, L_8006A098
    if (ctx->r2 != 0) {
        // 0x80069FA0: nop

            goto L_8006A098;
    }
    // 0x80069FA0: nop

L_80069FA4:
    // 0x80069FA4: jal         0x80061348
    // 0x80069FA8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x80069FA8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x80069FAC: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069FB0: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069FB4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069FB8: beq         $v0, $zero, L_80069FF8
    if (ctx->r2 == 0) {
        // 0x80069FBC: nop

            goto L_80069FF8;
    }
    // 0x80069FBC: nop

    // 0x80069FC0: jal         0x80061348
    // 0x80069FC4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069FC4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069FC8: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069FCC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069FD0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80069FD4: beq         $v0, $zero, L_80069FF8
    if (ctx->r2 == 0) {
        // 0x80069FD8: nop

            goto L_80069FF8;
    }
    // 0x80069FD8: nop

    // 0x80069FDC: jal         0x80061348
    // 0x80069FE0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x80069FE0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x80069FE4: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069FE8: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80069FEC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069FF0: bne         $v0, $zero, L_8006A098
    if (ctx->r2 != 0) {
        // 0x80069FF4: nop

            goto L_8006A098;
    }
    // 0x80069FF4: nop

L_80069FF8:
    // 0x80069FF8: jal         0x80061348
    // 0x80069FFC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x80069FFC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006A000: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A004: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A008: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A00C: beq         $v0, $zero, L_8006A04C
    if (ctx->r2 == 0) {
        // 0x8006A010: nop

            goto L_8006A04C;
    }
    // 0x8006A010: nop

    // 0x8006A014: jal         0x80061348
    // 0x8006A018: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006A018: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006A01C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A020: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A024: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A028: beq         $v0, $zero, L_8006A04C
    if (ctx->r2 == 0) {
        // 0x8006A02C: nop

            goto L_8006A04C;
    }
    // 0x8006A02C: nop

    // 0x8006A030: jal         0x80061348
    // 0x8006A034: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006A034: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006A038: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A03C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A040: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A044: bne         $v0, $zero, L_8006A098
    if (ctx->r2 != 0) {
        // 0x8006A048: nop

            goto L_8006A098;
    }
    // 0x8006A048: nop

L_8006A04C:
    // 0x8006A04C: jal         0x80061348
    // 0x8006A050: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006A050: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006A054: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A058: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A05C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A060: beq         $v0, $zero, L_8006A098
    if (ctx->r2 == 0) {
        // 0x8006A064: nop

            goto L_8006A098;
    }
    // 0x8006A064: nop

    // 0x8006A068: jal         0x80061348
    // 0x8006A06C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006A06C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006A070: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A074: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A078: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A07C: beq         $v0, $zero, L_8006A098
    if (ctx->r2 == 0) {
        // 0x8006A080: nop

            goto L_8006A098;
    }
    // 0x8006A080: nop

    // 0x8006A084: jal         0x80061348
    // 0x8006A088: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006A088: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006A08C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A090: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A094: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006A098:
    // 0x8006A098: b           L_8006A0A8
    // 0x8006A09C: nop

        goto L_8006A0A8;
    // 0x8006A09C: nop

    // 0x8006A0A0: b           L_8006A0A8
    // 0x8006A0A4: nop

        goto L_8006A0A8;
    // 0x8006A0A4: nop

L_8006A0A8:
    // 0x8006A0A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A0AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A0B0: jr          $ra
    // 0x8006A0B4: nop

    return;
    // 0x8006A0B4: nop

;}
RECOMP_FUNC void func_8006A0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A0BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A0C0: jal         0x80061348
    // 0x8006A0C4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006A0C4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006A0C8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A0CC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A0D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A0D4: beq         $v0, $zero, L_8006A114
    if (ctx->r2 == 0) {
        // 0x8006A0D8: nop

            goto L_8006A114;
    }
    // 0x8006A0D8: nop

    // 0x8006A0DC: jal         0x80061348
    // 0x8006A0E0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006A0E0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006A0E4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A0E8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A0EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A0F0: beq         $v0, $zero, L_8006A114
    if (ctx->r2 == 0) {
        // 0x8006A0F4: nop

            goto L_8006A114;
    }
    // 0x8006A0F4: nop

    // 0x8006A0F8: jal         0x80061348
    // 0x8006A0FC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006A0FC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006A100: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A104: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A108: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A10C: bne         $v0, $zero, L_8006A358
    if (ctx->r2 != 0) {
        // 0x8006A110: nop

            goto L_8006A358;
    }
    // 0x8006A110: nop

L_8006A114:
    // 0x8006A114: jal         0x80061348
    // 0x8006A118: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006A118: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006A11C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A120: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A124: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006A128: beq         $v0, $zero, L_8006A168
    if (ctx->r2 == 0) {
        // 0x8006A12C: nop

            goto L_8006A168;
    }
    // 0x8006A12C: nop

    // 0x8006A130: jal         0x80061348
    // 0x8006A134: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006A134: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006A138: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006A13C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006A140: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006A144: beq         $v0, $zero, L_8006A168
    if (ctx->r2 == 0) {
        // 0x8006A148: nop

            goto L_8006A168;
    }
    // 0x8006A148: nop

    // 0x8006A14C: jal         0x80061348
    // 0x8006A150: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006A150: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006A154: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006A158: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006A15C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006A160: bne         $v0, $zero, L_8006A358
    if (ctx->r2 != 0) {
        // 0x8006A164: nop

            goto L_8006A358;
    }
    // 0x8006A164: nop

L_8006A168:
    // 0x8006A168: jal         0x80061348
    // 0x8006A16C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006A16C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006A170: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006A174: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006A178: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006A17C: beq         $v0, $zero, L_8006A1BC
    if (ctx->r2 == 0) {
        // 0x8006A180: nop

            goto L_8006A1BC;
    }
    // 0x8006A180: nop

    // 0x8006A184: jal         0x80061348
    // 0x8006A188: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006A188: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006A18C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006A190: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006A194: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006A198: beq         $v0, $zero, L_8006A1BC
    if (ctx->r2 == 0) {
        // 0x8006A19C: nop

            goto L_8006A1BC;
    }
    // 0x8006A19C: nop

    // 0x8006A1A0: jal         0x80061348
    // 0x8006A1A4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006A1A4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006A1A8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A1AC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A1B0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A1B4: bne         $v0, $zero, L_8006A358
    if (ctx->r2 != 0) {
        // 0x8006A1B8: nop

            goto L_8006A358;
    }
    // 0x8006A1B8: nop

L_8006A1BC:
    // 0x8006A1BC: jal         0x80061348
    // 0x8006A1C0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006A1C0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006A1C4: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A1C8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A1CC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A1D0: beq         $v0, $zero, L_8006A210
    if (ctx->r2 == 0) {
        // 0x8006A1D4: nop

            goto L_8006A210;
    }
    // 0x8006A1D4: nop

    // 0x8006A1D8: jal         0x80061348
    // 0x8006A1DC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006A1DC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006A1E0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A1E4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A1E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A1EC: beq         $v0, $zero, L_8006A210
    if (ctx->r2 == 0) {
        // 0x8006A1F0: nop

            goto L_8006A210;
    }
    // 0x8006A1F0: nop

    // 0x8006A1F4: jal         0x80061348
    // 0x8006A1F8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006A1F8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006A1FC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A200: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A204: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A208: bne         $v0, $zero, L_8006A358
    if (ctx->r2 != 0) {
        // 0x8006A20C: nop

            goto L_8006A358;
    }
    // 0x8006A20C: nop

L_8006A210:
    // 0x8006A210: jal         0x80061348
    // 0x8006A214: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006A214: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006A218: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A21C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A220: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A224: beq         $v0, $zero, L_8006A264
    if (ctx->r2 == 0) {
        // 0x8006A228: nop

            goto L_8006A264;
    }
    // 0x8006A228: nop

    // 0x8006A22C: jal         0x80061348
    // 0x8006A230: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006A230: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006A234: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A238: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A23C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006A240: beq         $v0, $zero, L_8006A264
    if (ctx->r2 == 0) {
        // 0x8006A244: nop

            goto L_8006A264;
    }
    // 0x8006A244: nop

    // 0x8006A248: jal         0x80061348
    // 0x8006A24C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006A24C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006A250: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006A254: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006A258: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006A25C: bne         $v0, $zero, L_8006A358
    if (ctx->r2 != 0) {
        // 0x8006A260: nop

            goto L_8006A358;
    }
    // 0x8006A260: nop

L_8006A264:
    // 0x8006A264: jal         0x80061348
    // 0x8006A268: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006A268: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006A26C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006A270: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006A274: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006A278: beq         $v0, $zero, L_8006A2B8
    if (ctx->r2 == 0) {
        // 0x8006A27C: nop

            goto L_8006A2B8;
    }
    // 0x8006A27C: nop

    // 0x8006A280: jal         0x80061348
    // 0x8006A284: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006A284: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006A288: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006A28C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006A290: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006A294: beq         $v0, $zero, L_8006A2B8
    if (ctx->r2 == 0) {
        // 0x8006A298: nop

            goto L_8006A2B8;
    }
    // 0x8006A298: nop

    // 0x8006A29C: jal         0x80061348
    // 0x8006A2A0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006A2A0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006A2A4: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006A2A8: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006A2AC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006A2B0: bne         $v0, $zero, L_8006A358
    if (ctx->r2 != 0) {
        // 0x8006A2B4: nop

            goto L_8006A358;
    }
    // 0x8006A2B4: nop

L_8006A2B8:
    // 0x8006A2B8: jal         0x80061348
    // 0x8006A2BC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006A2BC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006A2C0: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A2C4: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A2C8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A2CC: beq         $v0, $zero, L_8006A30C
    if (ctx->r2 == 0) {
        // 0x8006A2D0: nop

            goto L_8006A30C;
    }
    // 0x8006A2D0: nop

    // 0x8006A2D4: jal         0x80061348
    // 0x8006A2D8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006A2D8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006A2DC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A2E0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A2E4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A2E8: beq         $v0, $zero, L_8006A30C
    if (ctx->r2 == 0) {
        // 0x8006A2EC: nop

            goto L_8006A30C;
    }
    // 0x8006A2EC: nop

    // 0x8006A2F0: jal         0x80061348
    // 0x8006A2F4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006A2F4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006A2F8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A2FC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A300: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A304: bne         $v0, $zero, L_8006A358
    if (ctx->r2 != 0) {
        // 0x8006A308: nop

            goto L_8006A358;
    }
    // 0x8006A308: nop

L_8006A30C:
    // 0x8006A30C: jal         0x80061348
    // 0x8006A310: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006A310: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006A314: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A318: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A31C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A320: beq         $v0, $zero, L_8006A358
    if (ctx->r2 == 0) {
        // 0x8006A324: nop

            goto L_8006A358;
    }
    // 0x8006A324: nop

    // 0x8006A328: jal         0x80061348
    // 0x8006A32C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006A32C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006A330: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A334: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A338: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A33C: beq         $v0, $zero, L_8006A358
    if (ctx->r2 == 0) {
        // 0x8006A340: nop

            goto L_8006A358;
    }
    // 0x8006A340: nop

    // 0x8006A344: jal         0x80061348
    // 0x8006A348: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006A348: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006A34C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A350: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A354: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006A358:
    // 0x8006A358: b           L_8006A368
    // 0x8006A35C: nop

        goto L_8006A368;
    // 0x8006A35C: nop

    // 0x8006A360: b           L_8006A368
    // 0x8006A364: nop

        goto L_8006A368;
    // 0x8006A364: nop

L_8006A368:
    // 0x8006A368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A36C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A370: jr          $ra
    // 0x8006A374: nop

    return;
    // 0x8006A374: nop

;}
RECOMP_FUNC void func_8006A378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A37C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A380: jal         0x80061348
    // 0x8006A384: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006A384: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006A388: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A38C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A390: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A394: beq         $v0, $zero, L_8006A3D4
    if (ctx->r2 == 0) {
        // 0x8006A398: nop

            goto L_8006A3D4;
    }
    // 0x8006A398: nop

    // 0x8006A39C: jal         0x80061348
    // 0x8006A3A0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006A3A0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006A3A4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A3A8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A3AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A3B0: beq         $v0, $zero, L_8006A3D4
    if (ctx->r2 == 0) {
        // 0x8006A3B4: nop

            goto L_8006A3D4;
    }
    // 0x8006A3B4: nop

    // 0x8006A3B8: jal         0x80061348
    // 0x8006A3BC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006A3BC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006A3C0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A3C4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A3C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A3CC: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A3D0: nop

            goto L_8006A618;
    }
    // 0x8006A3D0: nop

L_8006A3D4:
    // 0x8006A3D4: jal         0x80061348
    // 0x8006A3D8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006A3D8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006A3DC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A3E0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A3E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006A3E8: beq         $v0, $zero, L_8006A428
    if (ctx->r2 == 0) {
        // 0x8006A3EC: nop

            goto L_8006A428;
    }
    // 0x8006A3EC: nop

    // 0x8006A3F0: jal         0x80061348
    // 0x8006A3F4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006A3F4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006A3F8: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006A3FC: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006A400: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006A404: beq         $v0, $zero, L_8006A428
    if (ctx->r2 == 0) {
        // 0x8006A408: nop

            goto L_8006A428;
    }
    // 0x8006A408: nop

    // 0x8006A40C: jal         0x80061348
    // 0x8006A410: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006A410: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006A414: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006A418: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006A41C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006A420: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A424: nop

            goto L_8006A618;
    }
    // 0x8006A424: nop

L_8006A428:
    // 0x8006A428: jal         0x80061348
    // 0x8006A42C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006A42C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006A430: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006A434: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006A438: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006A43C: beq         $v0, $zero, L_8006A47C
    if (ctx->r2 == 0) {
        // 0x8006A440: nop

            goto L_8006A47C;
    }
    // 0x8006A440: nop

    // 0x8006A444: jal         0x80061348
    // 0x8006A448: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006A448: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006A44C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006A450: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006A454: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006A458: beq         $v0, $zero, L_8006A47C
    if (ctx->r2 == 0) {
        // 0x8006A45C: nop

            goto L_8006A47C;
    }
    // 0x8006A45C: nop

    // 0x8006A460: jal         0x80061348
    // 0x8006A464: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006A464: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006A468: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A46C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A470: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A474: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A478: nop

            goto L_8006A618;
    }
    // 0x8006A478: nop

L_8006A47C:
    // 0x8006A47C: jal         0x80061348
    // 0x8006A480: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006A480: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006A484: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A488: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A48C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A490: beq         $v0, $zero, L_8006A4D0
    if (ctx->r2 == 0) {
        // 0x8006A494: nop

            goto L_8006A4D0;
    }
    // 0x8006A494: nop

    // 0x8006A498: jal         0x80061348
    // 0x8006A49C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006A49C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006A4A0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A4A4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A4A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A4AC: beq         $v0, $zero, L_8006A4D0
    if (ctx->r2 == 0) {
        // 0x8006A4B0: nop

            goto L_8006A4D0;
    }
    // 0x8006A4B0: nop

    // 0x8006A4B4: jal         0x80061348
    // 0x8006A4B8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006A4B8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006A4BC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A4C0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A4C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A4C8: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A4CC: nop

            goto L_8006A618;
    }
    // 0x8006A4CC: nop

L_8006A4D0:
    // 0x8006A4D0: jal         0x80061348
    // 0x8006A4D4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006A4D4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006A4D8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A4DC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A4E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A4E4: beq         $v0, $zero, L_8006A524
    if (ctx->r2 == 0) {
        // 0x8006A4E8: nop

            goto L_8006A524;
    }
    // 0x8006A4E8: nop

    // 0x8006A4EC: jal         0x80061348
    // 0x8006A4F0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006A4F0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006A4F4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A4F8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A4FC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006A500: beq         $v0, $zero, L_8006A524
    if (ctx->r2 == 0) {
        // 0x8006A504: nop

            goto L_8006A524;
    }
    // 0x8006A504: nop

    // 0x8006A508: jal         0x80061348
    // 0x8006A50C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006A50C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006A510: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006A514: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006A518: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006A51C: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A520: nop

            goto L_8006A618;
    }
    // 0x8006A520: nop

L_8006A524:
    // 0x8006A524: jal         0x80061348
    // 0x8006A528: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006A528: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006A52C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006A530: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006A534: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006A538: beq         $v0, $zero, L_8006A578
    if (ctx->r2 == 0) {
        // 0x8006A53C: nop

            goto L_8006A578;
    }
    // 0x8006A53C: nop

    // 0x8006A540: jal         0x80061348
    // 0x8006A544: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006A544: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006A548: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006A54C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006A550: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006A554: beq         $v0, $zero, L_8006A578
    if (ctx->r2 == 0) {
        // 0x8006A558: nop

            goto L_8006A578;
    }
    // 0x8006A558: nop

    // 0x8006A55C: jal         0x80061348
    // 0x8006A560: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006A560: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006A564: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006A568: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006A56C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006A570: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A574: nop

            goto L_8006A618;
    }
    // 0x8006A574: nop

L_8006A578:
    // 0x8006A578: jal         0x80061348
    // 0x8006A57C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006A57C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006A580: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A584: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A588: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A58C: beq         $v0, $zero, L_8006A5CC
    if (ctx->r2 == 0) {
        // 0x8006A590: nop

            goto L_8006A5CC;
    }
    // 0x8006A590: nop

    // 0x8006A594: jal         0x80061348
    // 0x8006A598: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006A598: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006A59C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A5A0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A5A4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A5A8: beq         $v0, $zero, L_8006A5CC
    if (ctx->r2 == 0) {
        // 0x8006A5AC: nop

            goto L_8006A5CC;
    }
    // 0x8006A5AC: nop

    // 0x8006A5B0: jal         0x80061348
    // 0x8006A5B4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006A5B4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006A5B8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A5BC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A5C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A5C4: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A5C8: nop

            goto L_8006A618;
    }
    // 0x8006A5C8: nop

L_8006A5CC:
    // 0x8006A5CC: jal         0x80061348
    // 0x8006A5D0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006A5D0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006A5D4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A5D8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A5DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A5E0: beq         $v0, $zero, L_8006A618
    if (ctx->r2 == 0) {
        // 0x8006A5E4: nop

            goto L_8006A618;
    }
    // 0x8006A5E4: nop

    // 0x8006A5E8: jal         0x80061348
    // 0x8006A5EC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006A5EC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006A5F0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A5F4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A5F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A5FC: beq         $v0, $zero, L_8006A618
    if (ctx->r2 == 0) {
        // 0x8006A600: nop

            goto L_8006A618;
    }
    // 0x8006A600: nop

    // 0x8006A604: jal         0x80061348
    // 0x8006A608: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006A608: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006A60C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A610: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A614: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006A618:
    // 0x8006A618: b           L_8006A628
    // 0x8006A61C: nop

        goto L_8006A628;
    // 0x8006A61C: nop

    // 0x8006A620: b           L_8006A628
    // 0x8006A624: nop

        goto L_8006A628;
    // 0x8006A624: nop

L_8006A628:
    // 0x8006A628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A62C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A630: jr          $ra
    // 0x8006A634: nop

    return;
    // 0x8006A634: nop

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
RECOMP_FUNC void func_8006A8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A8F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A8FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A900: jal         0x80061488
    // 0x8006A904: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006A904: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_0:
    // 0x8006A908: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006A90C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006A910: b           L_8006A920
    // 0x8006A914: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006A920;
    // 0x8006A914: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A918: b           L_8006A920
    // 0x8006A91C: nop

        goto L_8006A920;
    // 0x8006A91C: nop

L_8006A920:
    // 0x8006A920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A928: jr          $ra
    // 0x8006A92C: nop

    return;
    // 0x8006A92C: nop

;}
RECOMP_FUNC void func_8006A930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A938: jal         0x80061348
    // 0x8006A93C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006A93C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x8006A940: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A944: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A948: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A94C: beq         $v0, $zero, L_8006A968
    if (ctx->r2 == 0) {
        // 0x8006A950: nop

            goto L_8006A968;
    }
    // 0x8006A950: nop

    // 0x8006A954: jal         0x80061348
    // 0x8006A958: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006A958: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    after_1:
    // 0x8006A95C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A960: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A964: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006A968:
    // 0x8006A968: b           L_8006A978
    // 0x8006A96C: nop

        goto L_8006A978;
    // 0x8006A96C: nop

    // 0x8006A970: b           L_8006A978
    // 0x8006A974: nop

        goto L_8006A978;
    // 0x8006A974: nop

L_8006A978:
    // 0x8006A978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A980: jr          $ra
    // 0x8006A984: nop

    return;
    // 0x8006A984: nop

;}
RECOMP_FUNC void func_8006A988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A990: jal         0x80061488
    // 0x8006A994: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006A994: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_0:
    // 0x8006A998: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006A99C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006A9A0: b           L_8006A9B0
    // 0x8006A9A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006A9B0;
    // 0x8006A9A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A9A8: b           L_8006A9B0
    // 0x8006A9AC: nop

        goto L_8006A9B0;
    // 0x8006A9AC: nop

L_8006A9B0:
    // 0x8006A9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A9B8: jr          $ra
    // 0x8006A9BC: nop

    return;
    // 0x8006A9BC: nop

;}
RECOMP_FUNC void func_8006A9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A9C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A9C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A9C8: jal         0x80061348
    // 0x8006A9CC: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006A9CC: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x8006A9D0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A9D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A9D8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A9DC: beq         $v0, $zero, L_8006A9F8
    if (ctx->r2 == 0) {
        // 0x8006A9E0: nop

            goto L_8006A9F8;
    }
    // 0x8006A9E0: nop

    // 0x8006A9E4: jal         0x80061348
    // 0x8006A9E8: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006A9E8: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    after_1:
    // 0x8006A9EC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A9F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A9F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006A9F8:
    // 0x8006A9F8: b           L_8006AA08
    // 0x8006A9FC: nop

        goto L_8006AA08;
    // 0x8006A9FC: nop

    // 0x8006AA00: b           L_8006AA08
    // 0x8006AA04: nop

        goto L_8006AA08;
    // 0x8006AA04: nop

L_8006AA08:
    // 0x8006AA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006AA0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006AA10: jr          $ra
    // 0x8006AA14: nop

    return;
    // 0x8006AA14: nop

;}
RECOMP_FUNC void func_8006AA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AA18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006AA1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006AA20: jal         0x80061348
    // 0x8006AA24: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006AA24: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006AA28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AA2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AA30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AA34: beq         $v0, $zero, L_8006AA74
    if (ctx->r2 == 0) {
        // 0x8006AA38: nop

            goto L_8006AA74;
    }
    // 0x8006AA38: nop

    // 0x8006AA3C: jal         0x80061348
    // 0x8006AA40: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006AA40: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006AA44: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AA48: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AA4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AA50: beq         $v0, $zero, L_8006AA74
    if (ctx->r2 == 0) {
        // 0x8006AA54: nop

            goto L_8006AA74;
    }
    // 0x8006AA54: nop

    // 0x8006AA58: jal         0x80061348
    // 0x8006AA5C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006AA5C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006AA60: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AA64: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AA68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AA6C: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AA70: nop

            goto L_8006ACB8;
    }
    // 0x8006AA70: nop

L_8006AA74:
    // 0x8006AA74: jal         0x80061348
    // 0x8006AA78: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006AA78: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006AA7C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AA80: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AA84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006AA88: beq         $v0, $zero, L_8006AAC8
    if (ctx->r2 == 0) {
        // 0x8006AA8C: nop

            goto L_8006AAC8;
    }
    // 0x8006AA8C: nop

    // 0x8006AA90: jal         0x80061348
    // 0x8006AA94: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006AA94: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006AA98: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006AA9C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006AAA0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006AAA4: beq         $v0, $zero, L_8006AAC8
    if (ctx->r2 == 0) {
        // 0x8006AAA8: nop

            goto L_8006AAC8;
    }
    // 0x8006AAA8: nop

    // 0x8006AAAC: jal         0x80061348
    // 0x8006AAB0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006AAB0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006AAB4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006AAB8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006AABC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006AAC0: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AAC4: nop

            goto L_8006ACB8;
    }
    // 0x8006AAC4: nop

L_8006AAC8:
    // 0x8006AAC8: jal         0x80061348
    // 0x8006AACC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006AACC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006AAD0: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006AAD4: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006AAD8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006AADC: beq         $v0, $zero, L_8006AB1C
    if (ctx->r2 == 0) {
        // 0x8006AAE0: nop

            goto L_8006AB1C;
    }
    // 0x8006AAE0: nop

    // 0x8006AAE4: jal         0x80061348
    // 0x8006AAE8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006AAE8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006AAEC: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006AAF0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006AAF4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006AAF8: beq         $v0, $zero, L_8006AB1C
    if (ctx->r2 == 0) {
        // 0x8006AAFC: nop

            goto L_8006AB1C;
    }
    // 0x8006AAFC: nop

    // 0x8006AB00: jal         0x80061348
    // 0x8006AB04: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006AB04: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006AB08: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006AB0C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006AB10: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006AB14: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AB18: nop

            goto L_8006ACB8;
    }
    // 0x8006AB18: nop

L_8006AB1C:
    // 0x8006AB1C: jal         0x80061348
    // 0x8006AB20: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006AB20: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006AB24: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006AB28: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006AB2C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006AB30: beq         $v0, $zero, L_8006AB70
    if (ctx->r2 == 0) {
        // 0x8006AB34: nop

            goto L_8006AB70;
    }
    // 0x8006AB34: nop

    // 0x8006AB38: jal         0x80061348
    // 0x8006AB3C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006AB3C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006AB40: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AB44: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AB48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AB4C: beq         $v0, $zero, L_8006AB70
    if (ctx->r2 == 0) {
        // 0x8006AB50: nop

            goto L_8006AB70;
    }
    // 0x8006AB50: nop

    // 0x8006AB54: jal         0x80061348
    // 0x8006AB58: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006AB58: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006AB5C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AB60: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AB64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AB68: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AB6C: nop

            goto L_8006ACB8;
    }
    // 0x8006AB6C: nop

L_8006AB70:
    // 0x8006AB70: jal         0x80061348
    // 0x8006AB74: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006AB74: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006AB78: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AB7C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AB80: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AB84: beq         $v0, $zero, L_8006ABC4
    if (ctx->r2 == 0) {
        // 0x8006AB88: nop

            goto L_8006ABC4;
    }
    // 0x8006AB88: nop

    // 0x8006AB8C: jal         0x80061348
    // 0x8006AB90: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006AB90: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006AB94: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AB98: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AB9C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006ABA0: beq         $v0, $zero, L_8006ABC4
    if (ctx->r2 == 0) {
        // 0x8006ABA4: nop

            goto L_8006ABC4;
    }
    // 0x8006ABA4: nop

    // 0x8006ABA8: jal         0x80061348
    // 0x8006ABAC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006ABAC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006ABB0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006ABB4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006ABB8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006ABBC: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006ABC0: nop

            goto L_8006ACB8;
    }
    // 0x8006ABC0: nop

L_8006ABC4:
    // 0x8006ABC4: jal         0x80061348
    // 0x8006ABC8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006ABC8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006ABCC: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006ABD0: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006ABD4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006ABD8: beq         $v0, $zero, L_8006AC18
    if (ctx->r2 == 0) {
        // 0x8006ABDC: nop

            goto L_8006AC18;
    }
    // 0x8006ABDC: nop

    // 0x8006ABE0: jal         0x80061348
    // 0x8006ABE4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006ABE4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006ABE8: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006ABEC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006ABF0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006ABF4: beq         $v0, $zero, L_8006AC18
    if (ctx->r2 == 0) {
        // 0x8006ABF8: nop

            goto L_8006AC18;
    }
    // 0x8006ABF8: nop

    // 0x8006ABFC: jal         0x80061348
    // 0x8006AC00: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006AC00: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006AC04: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006AC08: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006AC0C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006AC10: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AC14: nop

            goto L_8006ACB8;
    }
    // 0x8006AC14: nop

L_8006AC18:
    // 0x8006AC18: jal         0x80061348
    // 0x8006AC1C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006AC1C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006AC20: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006AC24: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006AC28: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006AC2C: beq         $v0, $zero, L_8006AC6C
    if (ctx->r2 == 0) {
        // 0x8006AC30: nop

            goto L_8006AC6C;
    }
    // 0x8006AC30: nop

    // 0x8006AC34: jal         0x80061348
    // 0x8006AC38: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006AC38: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006AC3C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006AC40: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006AC44: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006AC48: beq         $v0, $zero, L_8006AC6C
    if (ctx->r2 == 0) {
        // 0x8006AC4C: nop

            goto L_8006AC6C;
    }
    // 0x8006AC4C: nop

    // 0x8006AC50: jal         0x80061348
    // 0x8006AC54: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006AC54: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006AC58: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AC5C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AC60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AC64: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AC68: nop

            goto L_8006ACB8;
    }
    // 0x8006AC68: nop

L_8006AC6C:
    // 0x8006AC6C: jal         0x80061348
    // 0x8006AC70: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006AC70: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006AC74: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AC78: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AC7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AC80: beq         $v0, $zero, L_8006ACB8
    if (ctx->r2 == 0) {
        // 0x8006AC84: nop

            goto L_8006ACB8;
    }
    // 0x8006AC84: nop

    // 0x8006AC88: jal         0x80061348
    // 0x8006AC8C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006AC8C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006AC90: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AC94: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AC98: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AC9C: beq         $v0, $zero, L_8006ACB8
    if (ctx->r2 == 0) {
        // 0x8006ACA0: nop

            goto L_8006ACB8;
    }
    // 0x8006ACA0: nop

    // 0x8006ACA4: jal         0x80061348
    // 0x8006ACA8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006ACA8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006ACAC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006ACB0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006ACB4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006ACB8:
    // 0x8006ACB8: b           L_8006ACC8
    // 0x8006ACBC: nop

        goto L_8006ACC8;
    // 0x8006ACBC: nop

    // 0x8006ACC0: b           L_8006ACC8
    // 0x8006ACC4: nop

        goto L_8006ACC8;
    // 0x8006ACC4: nop

L_8006ACC8:
    // 0x8006ACC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ACCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ACD0: jr          $ra
    // 0x8006ACD4: nop

    return;
    // 0x8006ACD4: nop

;}
RECOMP_FUNC void func_8006ACD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ACD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ACDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ACE0: jal         0x80061348
    // 0x8006ACE4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006ACE4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006ACE8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006ACEC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006ACF0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006ACF4: beq         $v0, $zero, L_8006AD34
    if (ctx->r2 == 0) {
        // 0x8006ACF8: nop

            goto L_8006AD34;
    }
    // 0x8006ACF8: nop

    // 0x8006ACFC: jal         0x80061348
    // 0x8006AD00: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006AD00: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006AD04: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AD08: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AD0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AD10: beq         $v0, $zero, L_8006AD34
    if (ctx->r2 == 0) {
        // 0x8006AD14: nop

            goto L_8006AD34;
    }
    // 0x8006AD14: nop

    // 0x8006AD18: jal         0x80061348
    // 0x8006AD1C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006AD1C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006AD20: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AD24: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AD28: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AD2C: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AD30: nop

            goto L_8006AF78;
    }
    // 0x8006AD30: nop

L_8006AD34:
    // 0x8006AD34: jal         0x80061348
    // 0x8006AD38: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006AD38: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006AD3C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AD40: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AD44: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006AD48: beq         $v0, $zero, L_8006AD88
    if (ctx->r2 == 0) {
        // 0x8006AD4C: nop

            goto L_8006AD88;
    }
    // 0x8006AD4C: nop

    // 0x8006AD50: jal         0x80061348
    // 0x8006AD54: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006AD54: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006AD58: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006AD5C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006AD60: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006AD64: beq         $v0, $zero, L_8006AD88
    if (ctx->r2 == 0) {
        // 0x8006AD68: nop

            goto L_8006AD88;
    }
    // 0x8006AD68: nop

    // 0x8006AD6C: jal         0x80061348
    // 0x8006AD70: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006AD70: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006AD74: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006AD78: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006AD7C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006AD80: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AD84: nop

            goto L_8006AF78;
    }
    // 0x8006AD84: nop

L_8006AD88:
    // 0x8006AD88: jal         0x80061348
    // 0x8006AD8C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006AD8C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006AD90: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006AD94: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006AD98: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006AD9C: beq         $v0, $zero, L_8006ADDC
    if (ctx->r2 == 0) {
        // 0x8006ADA0: nop

            goto L_8006ADDC;
    }
    // 0x8006ADA0: nop

    // 0x8006ADA4: jal         0x80061348
    // 0x8006ADA8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006ADA8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006ADAC: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006ADB0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006ADB4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006ADB8: beq         $v0, $zero, L_8006ADDC
    if (ctx->r2 == 0) {
        // 0x8006ADBC: nop

            goto L_8006ADDC;
    }
    // 0x8006ADBC: nop

    // 0x8006ADC0: jal         0x80061348
    // 0x8006ADC4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006ADC4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006ADC8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006ADCC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006ADD0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006ADD4: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006ADD8: nop

            goto L_8006AF78;
    }
    // 0x8006ADD8: nop

L_8006ADDC:
    // 0x8006ADDC: jal         0x80061348
    // 0x8006ADE0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006ADE0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006ADE4: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006ADE8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006ADEC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006ADF0: beq         $v0, $zero, L_8006AE30
    if (ctx->r2 == 0) {
        // 0x8006ADF4: nop

            goto L_8006AE30;
    }
    // 0x8006ADF4: nop

    // 0x8006ADF8: jal         0x80061348
    // 0x8006ADFC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006ADFC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006AE00: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AE04: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AE08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AE0C: beq         $v0, $zero, L_8006AE30
    if (ctx->r2 == 0) {
        // 0x8006AE10: nop

            goto L_8006AE30;
    }
    // 0x8006AE10: nop

    // 0x8006AE14: jal         0x80061348
    // 0x8006AE18: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006AE18: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006AE1C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AE20: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AE24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AE28: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AE2C: nop

            goto L_8006AF78;
    }
    // 0x8006AE2C: nop

L_8006AE30:
    // 0x8006AE30: jal         0x80061348
    // 0x8006AE34: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006AE34: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006AE38: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AE3C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AE40: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AE44: beq         $v0, $zero, L_8006AE84
    if (ctx->r2 == 0) {
        // 0x8006AE48: nop

            goto L_8006AE84;
    }
    // 0x8006AE48: nop

    // 0x8006AE4C: jal         0x80061348
    // 0x8006AE50: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006AE50: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006AE54: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AE58: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AE5C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006AE60: beq         $v0, $zero, L_8006AE84
    if (ctx->r2 == 0) {
        // 0x8006AE64: nop

            goto L_8006AE84;
    }
    // 0x8006AE64: nop

    // 0x8006AE68: jal         0x80061348
    // 0x8006AE6C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006AE6C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006AE70: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006AE74: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006AE78: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006AE7C: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AE80: nop

            goto L_8006AF78;
    }
    // 0x8006AE80: nop

L_8006AE84:
    // 0x8006AE84: jal         0x80061348
    // 0x8006AE88: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006AE88: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006AE8C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006AE90: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006AE94: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006AE98: beq         $v0, $zero, L_8006AED8
    if (ctx->r2 == 0) {
        // 0x8006AE9C: nop

            goto L_8006AED8;
    }
    // 0x8006AE9C: nop

    // 0x8006AEA0: jal         0x80061348
    // 0x8006AEA4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006AEA4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006AEA8: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006AEAC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006AEB0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006AEB4: beq         $v0, $zero, L_8006AED8
    if (ctx->r2 == 0) {
        // 0x8006AEB8: nop

            goto L_8006AED8;
    }
    // 0x8006AEB8: nop

    // 0x8006AEBC: jal         0x80061348
    // 0x8006AEC0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006AEC0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006AEC4: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006AEC8: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006AECC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006AED0: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AED4: nop

            goto L_8006AF78;
    }
    // 0x8006AED4: nop

L_8006AED8:
    // 0x8006AED8: jal         0x80061348
    // 0x8006AEDC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006AEDC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006AEE0: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006AEE4: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006AEE8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006AEEC: beq         $v0, $zero, L_8006AF2C
    if (ctx->r2 == 0) {
        // 0x8006AEF0: nop

            goto L_8006AF2C;
    }
    // 0x8006AEF0: nop

    // 0x8006AEF4: jal         0x80061348
    // 0x8006AEF8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006AEF8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006AEFC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006AF00: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006AF04: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006AF08: beq         $v0, $zero, L_8006AF2C
    if (ctx->r2 == 0) {
        // 0x8006AF0C: nop

            goto L_8006AF2C;
    }
    // 0x8006AF0C: nop

    // 0x8006AF10: jal         0x80061348
    // 0x8006AF14: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006AF14: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006AF18: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AF1C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AF20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AF24: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AF28: nop

            goto L_8006AF78;
    }
    // 0x8006AF28: nop

L_8006AF2C:
    // 0x8006AF2C: jal         0x80061348
    // 0x8006AF30: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006AF30: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006AF34: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AF38: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AF3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AF40: beq         $v0, $zero, L_8006AF78
    if (ctx->r2 == 0) {
        // 0x8006AF44: nop

            goto L_8006AF78;
    }
    // 0x8006AF44: nop

    // 0x8006AF48: jal         0x80061348
    // 0x8006AF4C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006AF4C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006AF50: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AF54: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AF58: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AF5C: beq         $v0, $zero, L_8006AF78
    if (ctx->r2 == 0) {
        // 0x8006AF60: nop

            goto L_8006AF78;
    }
    // 0x8006AF60: nop

    // 0x8006AF64: jal         0x80061348
    // 0x8006AF68: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006AF68: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006AF6C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AF70: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AF74: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006AF78:
    // 0x8006AF78: b           L_8006AF88
    // 0x8006AF7C: nop

        goto L_8006AF88;
    // 0x8006AF7C: nop

    // 0x8006AF80: b           L_8006AF88
    // 0x8006AF84: nop

        goto L_8006AF88;
    // 0x8006AF84: nop

L_8006AF88:
    // 0x8006AF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006AF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006AF90: jr          $ra
    // 0x8006AF94: nop

    return;
    // 0x8006AF94: nop

;}
RECOMP_FUNC void func_8006AF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AF98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006AF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006AFA0: jal         0x80061348
    // 0x8006AFA4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006AFA4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006AFA8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AFAC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AFB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AFB4: beq         $v0, $zero, L_8006AFF4
    if (ctx->r2 == 0) {
        // 0x8006AFB8: nop

            goto L_8006AFF4;
    }
    // 0x8006AFB8: nop

    // 0x8006AFBC: jal         0x80061348
    // 0x8006AFC0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006AFC0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006AFC4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AFC8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AFCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AFD0: beq         $v0, $zero, L_8006AFF4
    if (ctx->r2 == 0) {
        // 0x8006AFD4: nop

            goto L_8006AFF4;
    }
    // 0x8006AFD4: nop

    // 0x8006AFD8: jal         0x80061348
    // 0x8006AFDC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006AFDC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006AFE0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AFE4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AFE8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AFEC: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006AFF0: nop

            goto L_8006B238;
    }
    // 0x8006AFF0: nop

L_8006AFF4:
    // 0x8006AFF4: jal         0x80061348
    // 0x8006AFF8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006AFF8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006AFFC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B000: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B004: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006B008: beq         $v0, $zero, L_8006B048
    if (ctx->r2 == 0) {
        // 0x8006B00C: nop

            goto L_8006B048;
    }
    // 0x8006B00C: nop

    // 0x8006B010: jal         0x80061348
    // 0x8006B014: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006B014: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006B018: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006B01C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006B020: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006B024: beq         $v0, $zero, L_8006B048
    if (ctx->r2 == 0) {
        // 0x8006B028: nop

            goto L_8006B048;
    }
    // 0x8006B028: nop

    // 0x8006B02C: jal         0x80061348
    // 0x8006B030: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006B030: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006B034: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006B038: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006B03C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006B040: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B044: nop

            goto L_8006B238;
    }
    // 0x8006B044: nop

L_8006B048:
    // 0x8006B048: jal         0x80061348
    // 0x8006B04C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006B04C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006B050: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006B054: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006B058: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006B05C: beq         $v0, $zero, L_8006B09C
    if (ctx->r2 == 0) {
        // 0x8006B060: nop

            goto L_8006B09C;
    }
    // 0x8006B060: nop

    // 0x8006B064: jal         0x80061348
    // 0x8006B068: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006B068: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006B06C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006B070: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006B074: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006B078: beq         $v0, $zero, L_8006B09C
    if (ctx->r2 == 0) {
        // 0x8006B07C: nop

            goto L_8006B09C;
    }
    // 0x8006B07C: nop

    // 0x8006B080: jal         0x80061348
    // 0x8006B084: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006B084: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006B088: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006B08C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006B090: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006B094: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B098: nop

            goto L_8006B238;
    }
    // 0x8006B098: nop

L_8006B09C:
    // 0x8006B09C: jal         0x80061348
    // 0x8006B0A0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006B0A0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006B0A4: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006B0A8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006B0AC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006B0B0: beq         $v0, $zero, L_8006B0F0
    if (ctx->r2 == 0) {
        // 0x8006B0B4: nop

            goto L_8006B0F0;
    }
    // 0x8006B0B4: nop

    // 0x8006B0B8: jal         0x80061348
    // 0x8006B0BC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006B0BC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006B0C0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B0C4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B0C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B0CC: beq         $v0, $zero, L_8006B0F0
    if (ctx->r2 == 0) {
        // 0x8006B0D0: nop

            goto L_8006B0F0;
    }
    // 0x8006B0D0: nop

    // 0x8006B0D4: jal         0x80061348
    // 0x8006B0D8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006B0D8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006B0DC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B0E0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B0E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B0E8: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B0EC: nop

            goto L_8006B238;
    }
    // 0x8006B0EC: nop

L_8006B0F0:
    // 0x8006B0F0: jal         0x80061348
    // 0x8006B0F4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006B0F4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006B0F8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B0FC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B100: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B104: beq         $v0, $zero, L_8006B144
    if (ctx->r2 == 0) {
        // 0x8006B108: nop

            goto L_8006B144;
    }
    // 0x8006B108: nop

    // 0x8006B10C: jal         0x80061348
    // 0x8006B110: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006B110: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006B114: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B118: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B11C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006B120: beq         $v0, $zero, L_8006B144
    if (ctx->r2 == 0) {
        // 0x8006B124: nop

            goto L_8006B144;
    }
    // 0x8006B124: nop

    // 0x8006B128: jal         0x80061348
    // 0x8006B12C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006B12C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006B130: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006B134: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006B138: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006B13C: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B140: nop

            goto L_8006B238;
    }
    // 0x8006B140: nop

L_8006B144:
    // 0x8006B144: jal         0x80061348
    // 0x8006B148: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006B148: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006B14C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006B150: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006B154: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006B158: beq         $v0, $zero, L_8006B198
    if (ctx->r2 == 0) {
        // 0x8006B15C: nop

            goto L_8006B198;
    }
    // 0x8006B15C: nop

    // 0x8006B160: jal         0x80061348
    // 0x8006B164: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006B164: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006B168: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006B16C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006B170: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006B174: beq         $v0, $zero, L_8006B198
    if (ctx->r2 == 0) {
        // 0x8006B178: nop

            goto L_8006B198;
    }
    // 0x8006B178: nop

    // 0x8006B17C: jal         0x80061348
    // 0x8006B180: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006B180: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006B184: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006B188: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006B18C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006B190: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B194: nop

            goto L_8006B238;
    }
    // 0x8006B194: nop

L_8006B198:
    // 0x8006B198: jal         0x80061348
    // 0x8006B19C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006B19C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006B1A0: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006B1A4: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006B1A8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006B1AC: beq         $v0, $zero, L_8006B1EC
    if (ctx->r2 == 0) {
        // 0x8006B1B0: nop

            goto L_8006B1EC;
    }
    // 0x8006B1B0: nop

    // 0x8006B1B4: jal         0x80061348
    // 0x8006B1B8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006B1B8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006B1BC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006B1C0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006B1C4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006B1C8: beq         $v0, $zero, L_8006B1EC
    if (ctx->r2 == 0) {
        // 0x8006B1CC: nop

            goto L_8006B1EC;
    }
    // 0x8006B1CC: nop

    // 0x8006B1D0: jal         0x80061348
    // 0x8006B1D4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006B1D4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006B1D8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B1DC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B1E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B1E4: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B1E8: nop

            goto L_8006B238;
    }
    // 0x8006B1E8: nop

L_8006B1EC:
    // 0x8006B1EC: jal         0x80061348
    // 0x8006B1F0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006B1F0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006B1F4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B1F8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B1FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B200: beq         $v0, $zero, L_8006B238
    if (ctx->r2 == 0) {
        // 0x8006B204: nop

            goto L_8006B238;
    }
    // 0x8006B204: nop

    // 0x8006B208: jal         0x80061348
    // 0x8006B20C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006B20C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006B210: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B214: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B218: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B21C: beq         $v0, $zero, L_8006B238
    if (ctx->r2 == 0) {
        // 0x8006B220: nop

            goto L_8006B238;
    }
    // 0x8006B220: nop

    // 0x8006B224: jal         0x80061348
    // 0x8006B228: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006B228: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006B22C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B230: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B234: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006B238:
    // 0x8006B238: b           L_8006B248
    // 0x8006B23C: nop

        goto L_8006B248;
    // 0x8006B23C: nop

    // 0x8006B240: b           L_8006B248
    // 0x8006B244: nop

        goto L_8006B248;
    // 0x8006B244: nop

L_8006B248:
    // 0x8006B248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B24C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B250: jr          $ra
    // 0x8006B254: nop

    return;
    // 0x8006B254: nop

;}
RECOMP_FUNC void func_8006B258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B25C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B260: jal         0x80061348
    // 0x8006B264: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006B264: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006B268: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B26C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B274: beq         $v0, $zero, L_8006B2B4
    if (ctx->r2 == 0) {
        // 0x8006B278: nop

            goto L_8006B2B4;
    }
    // 0x8006B278: nop

    // 0x8006B27C: jal         0x80061348
    // 0x8006B280: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006B280: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006B284: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B288: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B28C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B290: beq         $v0, $zero, L_8006B2B4
    if (ctx->r2 == 0) {
        // 0x8006B294: nop

            goto L_8006B2B4;
    }
    // 0x8006B294: nop

    // 0x8006B298: jal         0x80061348
    // 0x8006B29C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006B29C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006B2A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B2A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B2A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B2AC: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B2B0: nop

            goto L_8006B4F8;
    }
    // 0x8006B2B0: nop

L_8006B2B4:
    // 0x8006B2B4: jal         0x80061348
    // 0x8006B2B8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006B2B8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006B2BC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B2C0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B2C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006B2C8: beq         $v0, $zero, L_8006B308
    if (ctx->r2 == 0) {
        // 0x8006B2CC: nop

            goto L_8006B308;
    }
    // 0x8006B2CC: nop

    // 0x8006B2D0: jal         0x80061348
    // 0x8006B2D4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006B2D4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006B2D8: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006B2DC: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006B2E0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006B2E4: beq         $v0, $zero, L_8006B308
    if (ctx->r2 == 0) {
        // 0x8006B2E8: nop

            goto L_8006B308;
    }
    // 0x8006B2E8: nop

    // 0x8006B2EC: jal         0x80061348
    // 0x8006B2F0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006B2F0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006B2F4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006B2F8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006B2FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006B300: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B304: nop

            goto L_8006B4F8;
    }
    // 0x8006B304: nop

L_8006B308:
    // 0x8006B308: jal         0x80061348
    // 0x8006B30C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006B30C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006B310: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006B314: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006B318: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006B31C: beq         $v0, $zero, L_8006B35C
    if (ctx->r2 == 0) {
        // 0x8006B320: nop

            goto L_8006B35C;
    }
    // 0x8006B320: nop

    // 0x8006B324: jal         0x80061348
    // 0x8006B328: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006B328: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006B32C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006B330: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006B334: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006B338: beq         $v0, $zero, L_8006B35C
    if (ctx->r2 == 0) {
        // 0x8006B33C: nop

            goto L_8006B35C;
    }
    // 0x8006B33C: nop

    // 0x8006B340: jal         0x80061348
    // 0x8006B344: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006B344: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006B348: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006B34C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006B350: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006B354: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B358: nop

            goto L_8006B4F8;
    }
    // 0x8006B358: nop

L_8006B35C:
    // 0x8006B35C: jal         0x80061348
    // 0x8006B360: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006B360: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006B364: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006B368: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006B36C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006B370: beq         $v0, $zero, L_8006B3B0
    if (ctx->r2 == 0) {
        // 0x8006B374: nop

            goto L_8006B3B0;
    }
    // 0x8006B374: nop

    // 0x8006B378: jal         0x80061348
    // 0x8006B37C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006B37C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006B380: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B384: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B388: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B38C: beq         $v0, $zero, L_8006B3B0
    if (ctx->r2 == 0) {
        // 0x8006B390: nop

            goto L_8006B3B0;
    }
    // 0x8006B390: nop

    // 0x8006B394: jal         0x80061348
    // 0x8006B398: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006B398: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006B39C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B3A0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B3A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B3A8: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B3AC: nop

            goto L_8006B4F8;
    }
    // 0x8006B3AC: nop

L_8006B3B0:
    // 0x8006B3B0: jal         0x80061348
    // 0x8006B3B4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006B3B4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006B3B8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B3BC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B3C0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B3C4: beq         $v0, $zero, L_8006B404
    if (ctx->r2 == 0) {
        // 0x8006B3C8: nop

            goto L_8006B404;
    }
    // 0x8006B3C8: nop

    // 0x8006B3CC: jal         0x80061348
    // 0x8006B3D0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006B3D0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006B3D4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B3D8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B3DC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006B3E0: beq         $v0, $zero, L_8006B404
    if (ctx->r2 == 0) {
        // 0x8006B3E4: nop

            goto L_8006B404;
    }
    // 0x8006B3E4: nop

    // 0x8006B3E8: jal         0x80061348
    // 0x8006B3EC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006B3EC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006B3F0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006B3F4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006B3F8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006B3FC: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B400: nop

            goto L_8006B4F8;
    }
    // 0x8006B400: nop

L_8006B404:
    // 0x8006B404: jal         0x80061348
    // 0x8006B408: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006B408: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006B40C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006B410: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006B414: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006B418: beq         $v0, $zero, L_8006B458
    if (ctx->r2 == 0) {
        // 0x8006B41C: nop

            goto L_8006B458;
    }
    // 0x8006B41C: nop

    // 0x8006B420: jal         0x80061348
    // 0x8006B424: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006B424: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006B428: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006B42C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006B430: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006B434: beq         $v0, $zero, L_8006B458
    if (ctx->r2 == 0) {
        // 0x8006B438: nop

            goto L_8006B458;
    }
    // 0x8006B438: nop

    // 0x8006B43C: jal         0x80061348
    // 0x8006B440: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006B440: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006B444: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006B448: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006B44C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006B450: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B454: nop

            goto L_8006B4F8;
    }
    // 0x8006B454: nop

L_8006B458:
    // 0x8006B458: jal         0x80061348
    // 0x8006B45C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006B45C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006B460: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006B464: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006B468: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006B46C: beq         $v0, $zero, L_8006B4AC
    if (ctx->r2 == 0) {
        // 0x8006B470: nop

            goto L_8006B4AC;
    }
    // 0x8006B470: nop

    // 0x8006B474: jal         0x80061348
    // 0x8006B478: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006B478: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006B47C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006B480: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006B484: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006B488: beq         $v0, $zero, L_8006B4AC
    if (ctx->r2 == 0) {
        // 0x8006B48C: nop

            goto L_8006B4AC;
    }
    // 0x8006B48C: nop

    // 0x8006B490: jal         0x80061348
    // 0x8006B494: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006B494: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006B498: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B49C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B4A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B4A4: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B4A8: nop

            goto L_8006B4F8;
    }
    // 0x8006B4A8: nop

L_8006B4AC:
    // 0x8006B4AC: jal         0x80061348
    // 0x8006B4B0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006B4B0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006B4B4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B4B8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B4BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B4C0: beq         $v0, $zero, L_8006B4F8
    if (ctx->r2 == 0) {
        // 0x8006B4C4: nop

            goto L_8006B4F8;
    }
    // 0x8006B4C4: nop

    // 0x8006B4C8: jal         0x80061348
    // 0x8006B4CC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006B4CC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006B4D0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B4D4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B4D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B4DC: beq         $v0, $zero, L_8006B4F8
    if (ctx->r2 == 0) {
        // 0x8006B4E0: nop

            goto L_8006B4F8;
    }
    // 0x8006B4E0: nop

    // 0x8006B4E4: jal         0x80061348
    // 0x8006B4E8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006B4E8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006B4EC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B4F0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B4F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006B4F8:
    // 0x8006B4F8: b           L_8006B508
    // 0x8006B4FC: nop

        goto L_8006B508;
    // 0x8006B4FC: nop

    // 0x8006B500: b           L_8006B508
    // 0x8006B504: nop

        goto L_8006B508;
    // 0x8006B504: nop

L_8006B508:
    // 0x8006B508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B50C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B510: jr          $ra
    // 0x8006B514: nop

    return;
    // 0x8006B514: nop

;}
RECOMP_FUNC void func_8006B518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B518: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B51C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B520: nop

    // 0x8006B524: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B528: nop

    // 0x8006B52C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8006B530: jr          $ra
    // 0x8006B534: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B534: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B538: jr          $ra
    // 0x8006B53C: nop

    return;
    // 0x8006B53C: nop

    // 0x8006B540: jr          $ra
    // 0x8006B544: nop

    return;
    // 0x8006B544: nop

;}
RECOMP_FUNC void func_8006B548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B548: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B54C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B550: nop

    // 0x8006B554: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B558: nop

    // 0x8006B55C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B560: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B564: jr          $ra
    // 0x8006B568: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B568: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B56C: jr          $ra
    // 0x8006B570: nop

    return;
    // 0x8006B570: nop

    // 0x8006B574: jr          $ra
    // 0x8006B578: nop

    return;
    // 0x8006B578: nop

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
RECOMP_FUNC void func_8006B610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B610: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B614: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B618: nop

    // 0x8006B61C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B620: nop

    // 0x8006B624: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B628: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B62C: jr          $ra
    // 0x8006B630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B634: jr          $ra
    // 0x8006B638: nop

    return;
    // 0x8006B638: nop

    // 0x8006B63C: jr          $ra
    // 0x8006B640: nop

    return;
    // 0x8006B640: nop

;}
RECOMP_FUNC void func_8006B644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B64C: jal         0x80061348
    // 0x8006B650: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006B650: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    after_0:
    // 0x8006B654: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006B658: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B65C: beq         $v0, $zero, L_8006B680
    if (ctx->r2 == 0) {
        // 0x8006B660: nop

            goto L_8006B680;
    }
    // 0x8006B660: nop

    // 0x8006B664: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8006B668: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8006B66C: nop

    // 0x8006B670: lh          $v0, 0x2E($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2E);
    // 0x8006B674: nop

    // 0x8006B678: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B67C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006B680:
    // 0x8006B680: b           L_8006B690
    // 0x8006B684: nop

        goto L_8006B690;
    // 0x8006B684: nop

    // 0x8006B688: b           L_8006B690
    // 0x8006B68C: nop

        goto L_8006B690;
    // 0x8006B68C: nop

L_8006B690:
    // 0x8006B690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B698: jr          $ra
    // 0x8006B69C: nop

    return;
    // 0x8006B69C: nop

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
RECOMP_FUNC void func_8006B6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B6D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B6DC: nop

    // 0x8006B6E0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B6E4: nop

    // 0x8006B6E8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006B6EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B6F0: jr          $ra
    // 0x8006B6F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B6F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B6F8: jr          $ra
    // 0x8006B6FC: nop

    return;
    // 0x8006B6FC: nop

    // 0x8006B700: jr          $ra
    // 0x8006B704: nop

    return;
    // 0x8006B704: nop

;}
RECOMP_FUNC void func_8006B708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B708: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B70C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B710: nop

    // 0x8006B714: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B718: nop

    // 0x8006B71C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006B720: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B724: jr          $ra
    // 0x8006B728: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B728: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B72C: jr          $ra
    // 0x8006B730: nop

    return;
    // 0x8006B730: nop

    // 0x8006B734: jr          $ra
    // 0x8006B738: nop

    return;
    // 0x8006B738: nop

;}
RECOMP_FUNC void func_8006B73C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B73C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B744: jal         0x80061488
    // 0x8006B748: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006B748: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    after_0:
    // 0x8006B74C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006B750: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006B754: b           L_8006B764
    // 0x8006B758: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006B764;
    // 0x8006B758: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B75C: b           L_8006B764
    // 0x8006B760: nop

        goto L_8006B764;
    // 0x8006B760: nop

L_8006B764:
    // 0x8006B764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B76C: jr          $ra
    // 0x8006B770: nop

    return;
    // 0x8006B770: nop

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
RECOMP_FUNC void func_8006B7AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B7AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B7B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B7B4: jal         0x80061488
    // 0x8006B7B8: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006B7B8: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    after_0:
    // 0x8006B7BC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006B7C0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006B7C4: b           L_8006B7D4
    // 0x8006B7C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006B7D4;
    // 0x8006B7C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B7CC: b           L_8006B7D4
    // 0x8006B7D0: nop

        goto L_8006B7D4;
    // 0x8006B7D0: nop

L_8006B7D4:
    // 0x8006B7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B7D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B7DC: jr          $ra
    // 0x8006B7E0: nop

    return;
    // 0x8006B7E0: nop

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
RECOMP_FUNC void func_8006B81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B81C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B820: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B824: nop

    // 0x8006B828: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B82C: nop

    // 0x8006B830: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006B834: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B838: jr          $ra
    // 0x8006B83C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B83C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B840: jr          $ra
    // 0x8006B844: nop

    return;
    // 0x8006B844: nop

    // 0x8006B848: jr          $ra
    // 0x8006B84C: nop

    return;
    // 0x8006B84C: nop

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
RECOMP_FUNC void func_8006B884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B884: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B888: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B88C: nop

    // 0x8006B890: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006B894: nop

    // 0x8006B898: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8006B89C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B8A0: jr          $ra
    // 0x8006B8A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B8A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B8A8: jr          $ra
    // 0x8006B8AC: nop

    return;
    // 0x8006B8AC: nop

    // 0x8006B8B0: jr          $ra
    // 0x8006B8B4: nop

    return;
    // 0x8006B8B4: nop

;}
RECOMP_FUNC void func_8006B8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B8B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B8BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B8C0: nop

    // 0x8006B8C4: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006B8C8: nop

    // 0x8006B8CC: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8006B8D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B8D4: jr          $ra
    // 0x8006B8D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B8D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B8DC: jr          $ra
    // 0x8006B8E0: nop

    return;
    // 0x8006B8E0: nop

    // 0x8006B8E4: jr          $ra
    // 0x8006B8E8: nop

    return;
    // 0x8006B8E8: nop

;}
RECOMP_FUNC void func_8006B8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B8EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B8F0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B8F4: nop

    // 0x8006B8F8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B8FC: nop

    // 0x8006B900: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006B904: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B908: jr          $ra
    // 0x8006B90C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B90C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B910: jr          $ra
    // 0x8006B914: nop

    return;
    // 0x8006B914: nop

    // 0x8006B918: jr          $ra
    // 0x8006B91C: nop

    return;
    // 0x8006B91C: nop

;}
RECOMP_FUNC void func_8006B920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B920: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B924: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B928: nop

    // 0x8006B92C: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006B930: nop

    // 0x8006B934: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006B938: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B93C: jr          $ra
    // 0x8006B940: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B940: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B944: jr          $ra
    // 0x8006B948: nop

    return;
    // 0x8006B948: nop

    // 0x8006B94C: jr          $ra
    // 0x8006B950: nop

    return;
    // 0x8006B950: nop

;}
RECOMP_FUNC void func_8006B954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B954: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B958: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B95C: nop

    // 0x8006B960: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B964: nop

    // 0x8006B968: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006B96C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B970: jr          $ra
    // 0x8006B974: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B974: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B978: jr          $ra
    // 0x8006B97C: nop

    return;
    // 0x8006B97C: nop

    // 0x8006B980: jr          $ra
    // 0x8006B984: nop

    return;
    // 0x8006B984: nop

;}
RECOMP_FUNC void func_8006B988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B988: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B98C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B990: nop

    // 0x8006B994: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006B998: nop

    // 0x8006B99C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006B9A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B9A4: jr          $ra
    // 0x8006B9A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B9A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B9AC: jr          $ra
    // 0x8006B9B0: nop

    return;
    // 0x8006B9B0: nop

    // 0x8006B9B4: jr          $ra
    // 0x8006B9B8: nop

    return;
    // 0x8006B9B8: nop

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
RECOMP_FUNC void func_8006B9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B9F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B9F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B9FC: jal         0x80061488
    // 0x8006BA00: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006BA00: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    after_0:
    // 0x8006BA04: xori        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 ^ 0X4;
    // 0x8006BA08: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006BA0C: b           L_8006BA1C
    // 0x8006BA10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006BA1C;
    // 0x8006BA10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006BA14: b           L_8006BA1C
    // 0x8006BA18: nop

        goto L_8006BA1C;
    // 0x8006BA18: nop

L_8006BA1C:
    // 0x8006BA1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BA20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BA24: jr          $ra
    // 0x8006BA28: nop

    return;
    // 0x8006BA28: nop

;}
RECOMP_FUNC void func_8006BA2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BA2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BA30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BA34: jal         0x80061488
    // 0x8006BA38: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006BA38: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    after_0:
    // 0x8006BA3C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006BA40: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006BA44: b           L_8006BA54
    // 0x8006BA48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006BA54;
    // 0x8006BA48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006BA4C: b           L_8006BA54
    // 0x8006BA50: nop

        goto L_8006BA54;
    // 0x8006BA50: nop

L_8006BA54:
    // 0x8006BA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BA58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BA5C: jr          $ra
    // 0x8006BA60: nop

    return;
    // 0x8006BA60: nop

;}
RECOMP_FUNC void func_8006BA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BA64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BA68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BA6C: nop

    // 0x8006BA70: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BA74: nop

    // 0x8006BA78: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006BA7C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BA80: jr          $ra
    // 0x8006BA84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BA84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BA88: jr          $ra
    // 0x8006BA8C: nop

    return;
    // 0x8006BA8C: nop

    // 0x8006BA90: jr          $ra
    // 0x8006BA94: nop

    return;
    // 0x8006BA94: nop

;}
RECOMP_FUNC void func_8006BA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BA98: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BA9C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BAA0: nop

    // 0x8006BAA4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BAA8: nop

    // 0x8006BAAC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006BAB0: jr          $ra
    // 0x8006BAB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BAB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BAB8: jr          $ra
    // 0x8006BABC: nop

    return;
    // 0x8006BABC: nop

    // 0x8006BAC0: jr          $ra
    // 0x8006BAC4: nop

    return;
    // 0x8006BAC4: nop

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
RECOMP_FUNC void func_8006BAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BAFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BB00: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BB04: nop

    // 0x8006BB08: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BB0C: nop

    // 0x8006BB10: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006BB14: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BB18: jr          $ra
    // 0x8006BB1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BB1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BB20: jr          $ra
    // 0x8006BB24: nop

    return;
    // 0x8006BB24: nop

    // 0x8006BB28: jr          $ra
    // 0x8006BB2C: nop

    return;
    // 0x8006BB2C: nop

;}
RECOMP_FUNC void func_8006BB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BB34: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BB38: nop

    // 0x8006BB3C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BB40: nop

    // 0x8006BB44: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006BB48: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BB4C: jr          $ra
    // 0x8006BB50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BB50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BB54: jr          $ra
    // 0x8006BB58: nop

    return;
    // 0x8006BB58: nop

    // 0x8006BB5C: jr          $ra
    // 0x8006BB60: nop

    return;
    // 0x8006BB60: nop

;}
RECOMP_FUNC void func_8006BB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BB68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BB6C: nop

    // 0x8006BB70: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BB74: nop

    // 0x8006BB78: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006BB7C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BB80: jr          $ra
    // 0x8006BB84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BB84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BB88: jr          $ra
    // 0x8006BB8C: nop

    return;
    // 0x8006BB8C: nop

    // 0x8006BB90: jr          $ra
    // 0x8006BB94: nop

    return;
    // 0x8006BB94: nop

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
RECOMP_FUNC void func_8006BBD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BBD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BBD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BBD8: jal         0x80061488
    // 0x8006BBDC: addiu       $a0, $zero, 0x39A
    ctx->r4 = ADD32(0, 0X39A);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006BBDC: addiu       $a0, $zero, 0x39A
    ctx->r4 = ADD32(0, 0X39A);
    after_0:
    // 0x8006BBE0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006BBE4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006BBE8: b           L_8006BBF8
    // 0x8006BBEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006BBF8;
    // 0x8006BBEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006BBF0: b           L_8006BBF8
    // 0x8006BBF4: nop

        goto L_8006BBF8;
    // 0x8006BBF4: nop

L_8006BBF8:
    // 0x8006BBF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BBFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BC00: jr          $ra
    // 0x8006BC04: nop

    return;
    // 0x8006BC04: nop

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
RECOMP_FUNC void func_8006BC40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BC40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BC44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BC48: jal         0x8005F064
    // 0x8006BC4C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BC4C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x8006BC50: b           L_8006BC60
    // 0x8006BC54: nop

        goto L_8006BC60;
    // 0x8006BC54: nop

    // 0x8006BC58: b           L_8006BC60
    // 0x8006BC5C: nop

        goto L_8006BC60;
    // 0x8006BC5C: nop

L_8006BC60:
    // 0x8006BC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BC64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BC68: jr          $ra
    // 0x8006BC6C: nop

    return;
    // 0x8006BC6C: nop

;}
