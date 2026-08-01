#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800628A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800628A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800628AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800628B0: jal         0x8005F064
    // 0x800628B4: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800628B4: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    after_0:
    // 0x800628B8: b           L_800628C8
    // 0x800628BC: nop

        goto L_800628C8;
    // 0x800628BC: nop

    // 0x800628C0: b           L_800628C8
    // 0x800628C4: nop

        goto L_800628C8;
    // 0x800628C4: nop

L_800628C8:
    // 0x800628C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800628CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800628D0: jr          $ra
    // 0x800628D4: nop

    return;
    // 0x800628D4: nop

;}
RECOMP_FUNC void func_8006EF1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EF20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EF24: jal         0x80061348
    // 0x8006EF28: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EF28: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_0:
    // 0x8006EF2C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EF30: b           L_8006EF40
    // 0x8006EF34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EF40;
    // 0x8006EF34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EF38: b           L_8006EF40
    // 0x8006EF3C: nop

        goto L_8006EF40;
    // 0x8006EF3C: nop

L_8006EF40:
    // 0x8006EF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EF48: jr          $ra
    // 0x8006EF4C: nop

    return;
    // 0x8006EF4C: nop

;}
RECOMP_FUNC void func_8006C600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C608: jal         0x8005F064
    // 0x8006C60C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C60C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_0:
    // 0x8006C610: b           L_8006C620
    // 0x8006C614: nop

        goto L_8006C620;
    // 0x8006C614: nop

    // 0x8006C618: b           L_8006C620
    // 0x8006C61C: nop

        goto L_8006C620;
    // 0x8006C61C: nop

L_8006C620:
    // 0x8006C620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C628: jr          $ra
    // 0x8006C62C: nop

    return;
    // 0x8006C62C: nop

;}
RECOMP_FUNC void func_800659BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800659BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800659C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800659C4: jal         0x80061488
    // 0x800659C8: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800659C8: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    after_0:
    // 0x800659CC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800659D0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800659D4: b           L_800659E4
    // 0x800659D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800659E4;
    // 0x800659D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800659DC: b           L_800659E4
    // 0x800659E0: nop

        goto L_800659E4;
    // 0x800659E0: nop

L_800659E4:
    // 0x800659E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800659E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800659EC: jr          $ra
    // 0x800659F0: nop

    return;
    // 0x800659F0: nop

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
RECOMP_FUNC void func_800124B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800124B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800124BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800124C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800124C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800124C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800124CC: jal         0x8000DA44
    // 0x800124D0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800124D0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800124D4: bgez        $v0, L_800124E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800124D8: nop
    
            goto L_800124E4;
    }
    // 0x800124D8: nop

    // 0x800124DC: b           L_80012624
    // 0x800124E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012624;
    // 0x800124E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800124E4:
    // 0x800124E4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800124E8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800124EC: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800124F0: nop

    // 0x800124F4: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800124F8: bne         $at, $zero, L_80012518
    if (ctx->r1 != 0) {
        // 0x800124FC: nop
    
            goto L_80012518;
    }
    // 0x800124FC: nop

    // 0x80012500: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80012504: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80012508: beq         $at, $zero, L_80012518
    if (ctx->r1 == 0) {
        // 0x8001250C: nop
    
            goto L_80012518;
    }
    // 0x8001250C: nop

    // 0x80012510: b           L_80012624
    // 0x80012514: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012624;
    // 0x80012514: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012518:
    // 0x80012518: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8001251C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80012520: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80012524: nop

    // 0x80012528: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x8001252C: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x80012530: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80012534: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80012538: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8001253C: nop

    // 0x80012540: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012544: swc1        $f6, 0x1B0($t3)
    MEM_W(0X1B0, ctx->r11) = ctx->f6.u32l;
    // 0x80012548: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x8001254C: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x80012550: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80012554: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80012558: lwc1        $f16, -0x71C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8001255C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80012560: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80012564: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80012568: swc1        $f18, 0x1B4($t6)
    MEM_W(0X1B4, ctx->r14) = ctx->f18.u32l;
    // 0x8001256C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80012570: nop

    // 0x80012574: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x80012578: nop

    // 0x8001257C: bne         $t8, $zero, L_80012598
    if (ctx->r24 != 0) {
        // 0x80012580: nop
    
            goto L_80012598;
    }
    // 0x80012580: nop

    // 0x80012584: jal         0x8000D164
    // 0x80012588: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    TempHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x80012588: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x8001258C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80012590: nop

    // 0x80012594: sw          $v0, 0x20C($t9)
    MEM_W(0X20C, ctx->r25) = ctx->r2;
L_80012598:
    // 0x80012598: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001259C: nop

    // 0x800125A0: lw          $t1, 0x20C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20C);
    // 0x800125A4: nop

    // 0x800125A8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800125AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800125B0: jal         0x8000E3D4
    // 0x800125B4: nop

    func_8000E3D4(rdram, ctx);
        goto after_2;
    // 0x800125B4: nop

    after_2:
    // 0x800125B8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800125BC: nop

    // 0x800125C0: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x800125C4: addiu       $t3, $sp, 0x2C
    ctx->r11 = ADD32(ctx->r29, 0X2C);
    // 0x800125C8: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x800125CC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800125D0: nop

    // 0x800125D4: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x800125D8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800125DC: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x800125E0: lhu         $a2, 0x2($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X2);
    // 0x800125E4: lwc1        $f4, 0x1B4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B4);
    // 0x800125E8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800125EC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800125F0: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x800125F4: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x800125F8: lw          $a3, 0x1B0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1B0);
    // 0x800125FC: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80012600: jal         0x800298A4
    // 0x80012604: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800298A4(rdram, ctx);
        goto after_3;
    // 0x80012604: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80012608: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001260C: nop

    // 0x80012610: sw          $v0, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->r2;
    // 0x80012614: b           L_80012624
    // 0x80012618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012624;
    // 0x80012618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001261C: b           L_80012624
    // 0x80012620: nop

        goto L_80012624;
    // 0x80012620: nop

L_80012624:
    // 0x80012624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012628: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001262C: jr          $ra
    // 0x80012630: nop

    return;
    // 0x80012630: nop

;}
RECOMP_FUNC void func_800669F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800669F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800669FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066A00: jal         0x80061348
    // 0x80066A04: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066A04: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80066A08: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066A0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066A10: beq         $v0, $zero, L_80066A28
    if (ctx->r2 == 0) {
        // 0x80066A14: nop
    
            goto L_80066A28;
    }
    // 0x80066A14: nop

    // 0x80066A18: jal         0x80061348
    // 0x80066A1C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066A1C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x80066A20: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066A24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066A28:
    // 0x80066A28: b           L_80066A38
    // 0x80066A2C: nop

        goto L_80066A38;
    // 0x80066A2C: nop

    // 0x80066A30: b           L_80066A38
    // 0x80066A34: nop

        goto L_80066A38;
    // 0x80066A34: nop

L_80066A38:
    // 0x80066A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066A40: jr          $ra
    // 0x80066A44: nop

    return;
    // 0x80066A44: nop

;}
RECOMP_FUNC void func_800B3230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B3234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3238: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B323C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B3240: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B3244: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800B3248: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800B324C: jal         0x800B3EC0
    // 0x800B3250: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800B3EC0(rdram, ctx);
        goto after_0;
    // 0x800B3250: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800B3254: beq         $v0, $zero, L_800B3264
    if (ctx->r2 == 0) {
        // 0x800B3258: nop
    
            goto L_800B3264;
    }
    // 0x800B3258: nop

    // 0x800B325C: b           L_800B32D4
    // 0x800B3260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B32D4;
    // 0x800B3260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B3264:
    // 0x800B3264: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B3268: nop

    // 0x800B326C: beq         $t6, $zero, L_800B3284
    if (ctx->r14 == 0) {
        // 0x800B3270: nop
    
            goto L_800B3284;
    }
    // 0x800B3270: nop

    // 0x800B3274: lhu         $t7, 0x20($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X20);
    // 0x800B3278: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800B327C: nop

    // 0x800B3280: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_800B3284:
    // 0x800B3284: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3288: nop

    // 0x800B328C: beq         $t9, $zero, L_800B32A4
    if (ctx->r25 == 0) {
        // 0x800B3290: nop
    
            goto L_800B32A4;
    }
    // 0x800B3290: nop

    // 0x800B3294: lh          $t0, 0x22($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X22);
    // 0x800B3298: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B329C: nop

    // 0x800B32A0: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
L_800B32A4:
    // 0x800B32A4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B32A8: nop

    // 0x800B32AC: beq         $t2, $zero, L_800B32C4
    if (ctx->r10 == 0) {
        // 0x800B32B0: nop
    
            goto L_800B32C4;
    }
    // 0x800B32B0: nop

    // 0x800B32B4: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x800B32B8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B32BC: nop

    // 0x800B32C0: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
L_800B32C4:
    // 0x800B32C4: b           L_800B32D4
    // 0x800B32C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B32D4;
    // 0x800B32C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B32CC: b           L_800B32D4
    // 0x800B32D0: nop

        goto L_800B32D4;
    // 0x800B32D0: nop

L_800B32D4:
    // 0x800B32D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B32D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B32DC: jr          $ra
    // 0x800B32E0: nop

    return;
    // 0x800B32E0: nop

;}
RECOMP_FUNC void func_80070ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070ED8: jal         0x80061348
    // 0x80070EDC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070EDC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_0:
    // 0x80070EE0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070EE4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070EE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070EEC: beq         $v0, $zero, L_80070F40
    if (ctx->r2 == 0) {
        // 0x80070EF0: nop
    
            goto L_80070F40;
    }
    // 0x80070EF0: nop

    // 0x80070EF4: jal         0x80061348
    // 0x80070EF8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070EF8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070EFC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070F00: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070F04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070F08: beq         $v0, $zero, L_80070F40
    if (ctx->r2 == 0) {
        // 0x80070F0C: nop
    
            goto L_80070F40;
    }
    // 0x80070F0C: nop

    // 0x80070F10: jal         0x80061348
    // 0x80070F14: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070F14: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_2:
    // 0x80070F18: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070F1C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070F20: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070F24: beq         $v0, $zero, L_80070F40
    if (ctx->r2 == 0) {
        // 0x80070F28: nop
    
            goto L_80070F40;
    }
    // 0x80070F28: nop

    // 0x80070F2C: jal         0x80061348
    // 0x80070F30: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070F30: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070F34: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070F38: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070F3C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070F40:
    // 0x80070F40: b           L_80070F50
    // 0x80070F44: nop

        goto L_80070F50;
    // 0x80070F44: nop

    // 0x80070F48: b           L_80070F50
    // 0x80070F4C: nop

        goto L_80070F50;
    // 0x80070F4C: nop

L_80070F50:
    // 0x80070F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070F58: jr          $ra
    // 0x80070F5C: nop

    return;
    // 0x80070F5C: nop

;}
RECOMP_FUNC void alSynAllocVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3FE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D3FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3FF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3FF4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D3FF8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D3FFC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800D4000: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D4004: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x800D4008: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x800D400C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800D4010: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x800D4014: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800D4018: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x800D401C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800D4020: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x800D4024: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x800D4028: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800D402C: jal         0x800D3F00
    // 0x800D4030: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _allocatePVoice(rdram, ctx);
        goto after_0;
    // 0x800D4030: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800D4034: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4038: beql        $t9, $zero, L_800D4110
    if (ctx->r25 == 0) {
        // 0x800D403C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800D4110;
    }
    goto skip_0;
    // 0x800D403C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800D4040: beq         $v0, $zero, L_800D40F4
    if (ctx->r2 == 0) {
        // 0x800D4044: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_800D40F4;
    }
    // 0x800D4044: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x800D4048: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x800D404C: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x800D4050: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4054: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800D4058: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800D405C: jal         0x800C7C00
    // 0x800D4060: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_1;
    // 0x800D4060: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x800D4064: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800D4068: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D406C: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x800D4070: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800D4074: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800D4078: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800D407C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800D4080: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4084: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D4088: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D408C: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x800D4090: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x800D4094: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800D4098: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D409C: jalr        $t9
    // 0x800D40A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D40A0: nop

    after_2:
    // 0x800D40A4: jal         0x800C7C00
    // 0x800D40A8: nop

    __allocParam(rdram, ctx);
        goto after_3;
    // 0x800D40A8: nop

    after_3:
    // 0x800D40AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D40B0: beq         $v0, $zero, L_800D40FC
    if (ctx->r2 == 0) {
        // 0x800D40B4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D40FC;
    }
    // 0x800D40B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D40B8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800D40BC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800D40C0: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800D40C4: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800D40C8: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x800D40CC: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800D40D0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D40D4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D40D8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800D40DC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D40E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D40E4: jalr        $t9
    // 0x800D40E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800D40E8: nop

    after_4:
    // 0x800D40EC: b           L_800D4100
    // 0x800D40F0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_800D4100;
    // 0x800D40F0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800D40F4:
    // 0x800D40F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D40F8: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_800D40FC:
    // 0x800D40FC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800D4100:
    // 0x800D4100: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x800D4104: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4108: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800D410C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800D4110:
    // 0x800D4110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4118: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800D411C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800D4120: jr          $ra
    // 0x800D4124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D4124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ContPak_SetFileReadParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEE6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEE70: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEE74: nop

    // 0x800AEE78: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AEE7C: beq         $t7, $zero, L_800AEE8C
    if (ctx->r15 == 0) {
        // 0x800AEE80: nop
    
            goto L_800AEE8C;
    }
    // 0x800AEE80: nop

    // 0x800AEE84: jr          $ra
    // 0x800AEE88: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEE88: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEE8C:
    // 0x800AEE8C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEE90: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEE94: nop

    // 0x800AEE98: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AEE9C: beq         $t9, $zero, L_800AEEAC
    if (ctx->r25 == 0) {
        // 0x800AEEA0: nop
    
            goto L_800AEEAC;
    }
    // 0x800AEEA0: nop

    // 0x800AEEA4: jr          $ra
    // 0x800AEEA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEEA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEEAC:
    // 0x800AEEAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEEB0: sw          $a0, 0x167C($at)
    MEM_W(0X167C, ctx->r1) = ctx->r4;
    // 0x800AEEB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEEB8: sw          $a1, 0x1678($at)
    MEM_W(0X1678, ctx->r1) = ctx->r5;
    // 0x800AEEBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEEC0: sw          $a2, 0x1674($at)
    MEM_W(0X1674, ctx->r1) = ctx->r6;
    // 0x800AEEC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEEC8: sw          $a3, 0x1670($at)
    MEM_W(0X1670, ctx->r1) = ctx->r7;
    // 0x800AEECC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEED0: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800AEED4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEED8: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x800AEEDC: sw          $t1, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r9;
    // 0x800AEEE0: jr          $ra
    // 0x800AEEE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AEEE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEEE8: jr          $ra
    // 0x800AEEEC: nop

    return;
    // 0x800AEEEC: nop

    // 0x800AEEF0: jr          $ra
    // 0x800AEEF4: nop

    return;
    // 0x800AEEF4: nop

;}
RECOMP_FUNC void MtxUtil_Pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1A28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1A2C: lw          $t6, 0xCD8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCD8);
    // 0x800C1A30: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800C1A34: bne         $t6, $at, L_800C1A44
    if (ctx->r14 != ctx->r1) {
        // 0x800C1A38: nop
    
            goto L_800C1A44;
    }
    // 0x800C1A38: nop

    // 0x800C1A3C: jr          $ra
    // 0x800C1A40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800C1A40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C1A44:
    // 0x800C1A44: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C1A48: lw          $t7, 0xCD8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCD8);
    // 0x800C1A4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1A50: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C1A54: sw          $t8, 0xCD8($at)
    MEM_W(0XCD8, ctx->r1) = ctx->r24;
    // 0x800C1A58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C1A5C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C1A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1A64: addiu       $t0, $t9, -0x40
    ctx->r8 = ADD32(ctx->r25, -0X40);
    // 0x800C1A68: sw          $t0, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r8;
    // 0x800C1A6C: jr          $ra
    // 0x800C1A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C1A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1A74: jr          $ra
    // 0x800C1A78: nop

    return;
    // 0x800C1A78: nop

    // 0x800C1A7C: jr          $ra
    // 0x800C1A80: nop

    return;
    // 0x800C1A80: nop

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
    // 0x8007EA50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007EA54: negu        $t7, $s0
    ctx->r15 = SUB32(0, ctx->r16);
    // 0x8007EA58: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007EA5C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8007EA60: lw          $t6, 0x6B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B98);
    // 0x8007EA64: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007EA68: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
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
RECOMP_FUNC void func_80065950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065950: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065954: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065958: nop

    // 0x8006595C: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80065960: nop

    // 0x80065964: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80065968: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006596C: jr          $ra
    // 0x80065970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065974: jr          $ra
    // 0x80065978: nop

    return;
    // 0x80065978: nop

    // 0x8006597C: jr          $ra
    // 0x80065980: nop

    return;
    // 0x80065980: nop

;}
RECOMP_FUNC void func_800140D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800140D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800140DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800140E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800140E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800140E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800140EC: jal         0x8000DA44
    // 0x800140F0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800140F0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800140F4: bgez        $v0, L_80014104
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800140F8: nop
    
            goto L_80014104;
    }
    // 0x800140F8: nop

    // 0x800140FC: b           L_80014218
    // 0x80014100: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80014218;
    // 0x80014100: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014104:
    // 0x80014104: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014108: nop

    // 0x8001410C: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80014110: nop

    // 0x80014114: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80014118: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8001411C:
    // 0x8001411C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80014120: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80014124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80014128: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001412C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80014130: swc1        $f4, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f4.u32l;
    // 0x80014134: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80014138: nop

    // 0x8001413C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80014140: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x80014144: bne         $at, $zero, L_8001411C
    if (ctx->r1 != 0) {
        // 0x80014148: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8001411C;
    }
    // 0x80014148: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8001414C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80014150: nop

    // 0x80014154: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80014158: nop

    // 0x8001415C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80014160: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80014164: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80014168: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8001416C: nop

    // 0x80014170: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80014174: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x80014178: nop

    // 0x8001417C: blez        $t9, L_80014208
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80014180: nop
    
            goto L_80014208;
    }
    // 0x80014180: nop

L_80014184:
    // 0x80014184: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80014188: lhu         $a0, 0x4($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X4);
    // 0x8001418C: jal         0x80014BD4
    // 0x80014190: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80014190: nop

    after_1:
    // 0x80014194: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80014198: nop

    // 0x8001419C: swc1        $f0, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f0.u32l;
    // 0x800141A0: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x800141A4: lhu         $a0, 0x6($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X6);
    // 0x800141A8: jal         0x80014BD4
    // 0x800141AC: nop

    func_80014BD4(rdram, ctx);
        goto after_2;
    // 0x800141AC: nop

    after_2:
    // 0x800141B0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800141B4: nop

    // 0x800141B8: swc1        $f0, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f0.u32l;
    // 0x800141BC: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800141C0: lhu         $a0, 0x8($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X8);
    // 0x800141C4: jal         0x80014BD4
    // 0x800141C8: nop

    func_80014BD4(rdram, ctx);
        goto after_3;
    // 0x800141C8: nop

    after_3:
    // 0x800141CC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800141D0: nop

    // 0x800141D4: swc1        $f0, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f0.u32l;
    // 0x800141D8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800141DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800141E0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800141E4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x800141E8: addiu       $t9, $t6, 0x160
    ctx->r25 = ADD32(ctx->r14, 0X160);
    // 0x800141EC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800141F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800141F4: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x800141F8: nop

    // 0x800141FC: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80014200: bne         $at, $zero, L_80014184
    if (ctx->r1 != 0) {
        // 0x80014204: nop
    
            goto L_80014184;
    }
    // 0x80014204: nop

L_80014208:
    // 0x80014208: b           L_80014218
    // 0x8001420C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80014218;
    // 0x8001420C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014210: b           L_80014218
    // 0x80014214: nop

        goto L_80014218;
    // 0x80014214: nop

L_80014218:
    // 0x80014218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001421C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014220: jr          $ra
    // 0x80014224: nop

    return;
    // 0x80014224: nop

;}
RECOMP_FUNC void func_8008DB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DB7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008DB80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DB84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008DB88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DB8C: jal         0x8001ABEC
    // 0x8008DB90: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001ABEC(rdram, ctx);
        goto after_0;
    // 0x8008DB90: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_0:
    // 0x8008DB94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008DB98:
    // 0x8008DB98: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008DB9C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DBA0: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8008DBA4: nop

    // 0x8008DBA8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008DBAC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008DBB0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8008DBB4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8008DBB8: lh          $t1, 0x3AC($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X3AC);
    // 0x8008DBBC: nop

    // 0x8008DBC0: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8008DBC4: bne         $at, $zero, L_8008DBD4
    if (ctx->r1 != 0) {
        // 0x8008DBC8: nop
    
            goto L_8008DBD4;
    }
    // 0x8008DBC8: nop

    // 0x8008DBCC: b           L_8008DC7C
    // 0x8008DBD0: nop

        goto L_8008DC7C;
    // 0x8008DBD0: nop

L_8008DBD4:
    // 0x8008DBD4: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8008DBD8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DBDC: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x8008DBE0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DBE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DBE8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8008DBEC: addiu       $t5, $t4, 0x11
    ctx->r13 = ADD32(ctx->r12, 0X11);
    // 0x8008DBF0: sw          $t5, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r13;
    // 0x8008DBF4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8008DBF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008DBFC: addiu       $a0, $a0, -0xA20
    ctx->r4 = ADD32(ctx->r4, -0XA20);
    // 0x8008DC00: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x8008DC04: jal         0x8008ECE4
    // 0x8008DC08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8008DC08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_1:
    // 0x8008DC0C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008DC10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008DC14: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008DC18: lbu         $a0, 0x4C20($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4C20);
    // 0x8008DC1C: jal         0x8005F064
    // 0x8008DC20: nop

    func_8005F064(rdram, ctx);
        goto after_2;
    // 0x8008DC20: nop

    after_2:
    // 0x8008DC24: bne         $v0, $zero, L_8008DC34
    if (ctx->r2 != 0) {
        // 0x8008DC28: nop
    
            goto L_8008DC34;
    }
    // 0x8008DC28: nop

    // 0x8008DC2C: b           L_8008DC64
    // 0x8008DC30: nop

        goto L_8008DC64;
    // 0x8008DC30: nop

L_8008DC34:
    // 0x8008DC34: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x8008DC38: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DC3C: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x8008DC40: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DC44: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DC48: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8008DC4C: addiu       $t0, $t6, 0x11
    ctx->r8 = ADD32(ctx->r14, 0X11);
    // 0x8008DC50: sw          $t0, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r8;
    // 0x8008DC54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DC58: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008DC5C: jal         0x8008DE78
    // 0x8008DC60: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008DE78(rdram, ctx);
        goto after_3;
    // 0x8008DC60: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_3:
L_8008DC64:
    // 0x8008DC64: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DC68: nop

    // 0x8008DC6C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008DC70: slti        $at, $t2, 0x7
    ctx->r1 = SIGNED(ctx->r10) < 0X7 ? 1 : 0;
    // 0x8008DC74: bne         $at, $zero, L_8008DB98
    if (ctx->r1 != 0) {
        // 0x8008DC78: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8008DB98;
    }
    // 0x8008DC78: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_8008DC7C:
    // 0x8008DC7C: addiu       $t3, $zero, 0x55
    ctx->r11 = ADD32(0, 0X55);
    // 0x8008DC80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DC84: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x8008DC88: addiu       $t4, $zero, 0x84
    ctx->r12 = ADD32(0, 0X84);
    // 0x8008DC8C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DC90: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x8008DC94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DC98: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8008DC9C: jal         0x8008DE78
    // 0x8008DCA0: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    func_8008DE78(rdram, ctx);
        goto after_4;
    // 0x8008DCA0: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    after_4:
    // 0x8008DCA4: addiu       $t5, $zero, 0x88
    ctx->r13 = ADD32(0, 0X88);
    // 0x8008DCA8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DCAC: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x8008DCB0: addiu       $t7, $zero, 0x84
    ctx->r15 = ADD32(0, 0X84);
    // 0x8008DCB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DCB8: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x8008DCBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DCC0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8008DCC4: jal         0x8008DE78
    // 0x8008DCC8: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    func_8008DE78(rdram, ctx);
        goto after_5;
    // 0x8008DCC8: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    after_5:
    // 0x8008DCCC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8008DCD0: nop

    // 0x8008DCD4: lw          $t9, 0x2A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2A8);
    // 0x8008DCD8: nop

    // 0x8008DCDC: sh          $zero, 0x20($t9)
    MEM_H(0X20, ctx->r25) = 0;
    // 0x8008DCE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DCE4: jal         0x8001ACDC
    // 0x8008DCE8: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001ACDC(rdram, ctx);
        goto after_6;
    // 0x8008DCE8: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_6:
    // 0x8008DCEC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008DCF0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8008DCF4: lw          $t0, 0x230($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X230);
    // 0x8008DCF8: nop

    // 0x8008DCFC: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8008DD00: sw          $t1, 0x230($t6)
    MEM_W(0X230, ctx->r14) = ctx->r9;
    // 0x8008DD04: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008DD08: nop

    // 0x8008DD0C: lw          $t3, 0x230($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X230);
    // 0x8008DD10: nop

    // 0x8008DD14: ori         $t4, $t3, 0x810
    ctx->r12 = ctx->r11 | 0X810;
    // 0x8008DD18: sw          $t4, 0x230($t2)
    MEM_W(0X230, ctx->r10) = ctx->r12;
    // 0x8008DD1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DD20: jal         0x8001ADBC
    // 0x8008DD24: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001ADBC(rdram, ctx);
        goto after_7;
    // 0x8008DD24: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_7:
    // 0x8008DD28: b           L_8008DD30
    // 0x8008DD2C: nop

        goto L_8008DD30;
    // 0x8008DD2C: nop

L_8008DD30:
    // 0x8008DD30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DD34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008DD38: jr          $ra
    // 0x8008DD3C: nop

    return;
    // 0x8008DD3C: nop

;}
RECOMP_FUNC void func_80075E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075E58: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075E5C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075E60: nop

    // 0x80075E64: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075E68: nop

    // 0x80075E6C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075E70: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075E74: jr          $ra
    // 0x80075E78: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075E78: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075E7C: jr          $ra
    // 0x80075E80: nop

    return;
    // 0x80075E80: nop

    // 0x80075E84: jr          $ra
    // 0x80075E88: nop

    return;
    // 0x80075E88: nop

;}
RECOMP_FUNC void func_800685E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800685E4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800685E8: nop

    // 0x800685EC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800685F0: nop

    // 0x800685F4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800685F8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800685FC: jr          $ra
    // 0x80068600: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068600: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068604: jr          $ra
    // 0x80068608: nop

    return;
    // 0x80068608: nop

    // 0x8006860C: jr          $ra
    // 0x80068610: nop

    return;
    // 0x80068610: nop

;}
RECOMP_FUNC void func_8008AA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AA44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008AA48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AA4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008AA50: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA54: nop

    // 0x8008AA58: lhu         $a2, 0x8($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X8);
    // 0x8008AA5C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008AA60: jal         0x800B1C10
    // 0x8008AA64: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    func_800B1C10(rdram, ctx);
        goto after_0;
    // 0x8008AA64: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x8008AA68: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA6C: nop

    // 0x8008AA70: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x8008AA74: jal         0x800BC980
    // 0x8008AA78: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x8008AA78: nop

    after_1:
    // 0x8008AA7C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA80: nop

    // 0x8008AA84: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8008AA88: jal         0x800BC980
    // 0x8008AA8C: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8008AA8C: nop

    after_2:
    // 0x8008AA90: b           L_8008AA98
    // 0x8008AA94: nop

        goto L_8008AA98;
    // 0x8008AA94: nop

L_8008AA98:
    // 0x8008AA98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AA9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AAA0: jr          $ra
    // 0x8008AAA4: nop

    return;
    // 0x8008AAA4: nop

;}
RECOMP_FUNC void func_800B4680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4680: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B4684: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800B4688: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800B468C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x800B4690: lbu         $t8, 0x10($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X10);
    // 0x800B4694: nop

    // 0x800B4698: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B469C: bne         $at, $zero, L_800B46AC
    if (ctx->r1 != 0) {
        // 0x800B46A0: nop
    
            goto L_800B46AC;
    }
    // 0x800B46A0: nop

    // 0x800B46A4: b           L_800B4798
    // 0x800B46A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B4798;
    // 0x800B46A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B46AC:
    // 0x800B46AC: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x800B46B0: nop

    // 0x800B46B4: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x800B46B8: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800B46BC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800B46C0: lbu         $t2, 0x10($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X10);
    // 0x800B46C4: nop

    // 0x800B46C8: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B46CC: beq         $at, $zero, L_800B4764
    if (ctx->r1 == 0) {
        // 0x800B46D0: nop
    
            goto L_800B4764;
    }
    // 0x800B46D0: nop

L_800B46D4:
    // 0x800B46D4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800B46D8: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800B46DC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800B46E0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B46E4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800B46E8: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800B46EC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800B46F0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B46F4: nop

    // 0x800B46F8: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x800B46FC: nop

    // 0x800B4700: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800B4704: bne         $t9, $zero, L_800B4714
    if (ctx->r25 != 0) {
        // 0x800B4708: nop
    
            goto L_800B4714;
    }
    // 0x800B4708: nop

    // 0x800B470C: b           L_800B4738
    // 0x800B4710: nop

        goto L_800B4738;
    // 0x800B4710: nop

L_800B4714:
    // 0x800B4714: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800B4718: nop

    // 0x800B471C: lhu         $t0, 0x0($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X0);
    // 0x800B4720: nop

    // 0x800B4724: andi        $t2, $t0, 0x7FFF
    ctx->r10 = ctx->r8 & 0X7FFF;
    // 0x800B4728: bne         $t2, $a1, L_800B4738
    if (ctx->r10 != ctx->r5) {
        // 0x800B472C: nop
    
            goto L_800B4738;
    }
    // 0x800B472C: nop

    // 0x800B4730: b           L_800B4764
    // 0x800B4734: nop

        goto L_800B4764;
    // 0x800B4734: nop

L_800B4738:
    // 0x800B4738: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800B473C: nop

    // 0x800B4740: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800B4744: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x800B4748: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x800B474C: nop

    // 0x800B4750: lbu         $t7, 0x10($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X10);
    // 0x800B4754: nop

    // 0x800B4758: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B475C: bne         $at, $zero, L_800B46D4
    if (ctx->r1 != 0) {
        // 0x800B4760: nop
    
            goto L_800B46D4;
    }
    // 0x800B4760: nop

L_800B4764:
    // 0x800B4764: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800B4768: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800B476C: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x800B4770: nop

    // 0x800B4774: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B4778: beq         $at, $zero, L_800B4788
    if (ctx->r1 == 0) {
        // 0x800B477C: nop
    
            goto L_800B4788;
    }
    // 0x800B477C: nop

    // 0x800B4780: b           L_800B4798
    // 0x800B4784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B4798;
    // 0x800B4784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B4788:
    // 0x800B4788: b           L_800B4798
    // 0x800B478C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B4798;
    // 0x800B478C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4790: b           L_800B4798
    // 0x800B4794: nop

        goto L_800B4798;
    // 0x800B4794: nop

L_800B4798:
    // 0x800B4798: jr          $ra
    // 0x800B479C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B479C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80055498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055498: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005549C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800554A0: addiu       $t7, $t7, -0x27CC
    ctx->r15 = ADD32(ctx->r15, -0X27CC);
    // 0x800554A4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800554A8: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x800554AC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800554B0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800554B4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800554B8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800554BC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800554C0: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800554C4: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x800554C8: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800554CC: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x800554D0: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x800554D4: lw          $t0, 0x14($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X14);
    // 0x800554D8: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x800554DC: sw          $t0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r8;
    // 0x800554E0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800554E4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800554E8: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x800554EC: nop

    // 0x800554F0: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x800554F4: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x800554F8: nop

    // 0x800554FC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80055500: sh          $t4, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r12;
    // 0x80055504: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80055508: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x8005550C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80055510: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80055514: nop

    // 0x80055518: lh          $t8, 0xC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0XC);
    // 0x8005551C: lh          $t6, 0xA($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XA);
    // 0x80055520: nop

    // 0x80055524: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80055528: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x8005552C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80055530: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
    // 0x80055534: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80055538: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005553C: nop

    // 0x80055540: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x80055544: lh          $t3, 0x10($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X10);
    // 0x80055548: nop

    // 0x8005554C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80055550: sh          $t4, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r12;
    // 0x80055554: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80055558: sh          $t5, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r13;
    // 0x8005555C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80055560: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80055564: nop

    // 0x80055568: lh          $t8, 0x16($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X16);
    // 0x8005556C: lh          $t6, 0x14($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X14);
    // 0x80055570: nop

    // 0x80055574: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80055578: sh          $t7, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r15;
L_8005557C:
    // 0x8005557C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80055580: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80055584:
    // 0x80055584: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80055588: nop

    // 0x8005558C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80055590: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x80055594: addu        $t4, $a0, $t1
    ctx->r12 = ADD32(ctx->r4, ctx->r9);
    // 0x80055598: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x8005559C: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x800555A0: nop

    // 0x800555A4: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800555A8: beq         $at, $zero, L_80055620
    if (ctx->r1 == 0) {
        // 0x800555AC: nop
    
            goto L_80055620;
    }
    // 0x800555AC: nop

    // 0x800555B0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800555B4: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x800555B8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800555BC: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800555C0: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x800555C4: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x800555C8: nop

    // 0x800555CC: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800555D0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800555D4: nop

    // 0x800555D8: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800555DC: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800555E0: lwl         $at, 0x4($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X4);
    // 0x800555E4: lwr         $at, 0x7($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X7);
    // 0x800555E8: addu        $t3, $a0, $t4
    ctx->r11 = ADD32(ctx->r4, ctx->r12);
    // 0x800555EC: swl         $at, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r1);
    // 0x800555F0: swr         $at, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r1);
    // 0x800555F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800555F8: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x800555FC: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80055600: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80055604: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x80055608: swl         $at, 0x4($t7)
    do_swl(rdram, 0X4, ctx->r15, ctx->r1);
    // 0x8005560C: swr         $at, 0x7($t7)
    do_swr(rdram, 0X7, ctx->r15, ctx->r1);
    // 0x80055610: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80055614: nop

    // 0x80055618: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8005561C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80055620:
    // 0x80055620: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80055624: nop

    // 0x80055628: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005562C: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80055630: bne         $at, $zero, L_80055584
    if (ctx->r1 != 0) {
        // 0x80055634: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80055584;
    }
    // 0x80055634: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80055638: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005563C: nop

    // 0x80055640: bne         $t0, $zero, L_8005557C
    if (ctx->r8 != 0) {
        // 0x80055644: nop
    
            goto L_8005557C;
    }
    // 0x80055644: nop

    // 0x80055648: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005564C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80055650: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80055654:
    // 0x80055654: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80055658: nop

    // 0x8005565C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80055660: addu        $t7, $t1, $a0
    ctx->r15 = ADD32(ctx->r9, ctx->r4);
    // 0x80055664: lh          $t2, 0x2($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X2);
    // 0x80055668: nop

    // 0x8005566C: beq         $t2, $zero, L_8005574C
    if (ctx->r10 == 0) {
        // 0x80055670: nop
    
            goto L_8005574C;
    }
    // 0x80055670: nop

    // 0x80055674: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055678: nop

    // 0x8005567C: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80055680: addu        $t3, $t8, $a0
    ctx->r11 = ADD32(ctx->r24, ctx->r4);
    // 0x80055684: lh          $t5, 0x2($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X2);
    // 0x80055688: nop

    // 0x8005568C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80055690: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80055694: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80055698: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8005569C: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x800556A0: addu        $t4, $sp, $t2
    ctx->r12 = ADD32(ctx->r29, ctx->r10);
    // 0x800556A4: addu        $t9, $t0, $a0
    ctx->r25 = ADD32(ctx->r8, ctx->r4);
    // 0x800556A8: lh          $t1, 0x2($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X2);
    // 0x800556AC: lw          $t4, 0x4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4);
    // 0x800556B0: addu        $t3, $t0, $a0
    ctx->r11 = ADD32(ctx->r8, ctx->r4);
    // 0x800556B4: multu       $t1, $t4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800556B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800556BC: sh          $t8, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r24;
    // 0x800556C0: nop

    // 0x800556C4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800556C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800556CC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800556D0: addu        $t9, $t6, $a0
    ctx->r25 = ADD32(ctx->r14, ctx->r4);
    // 0x800556D4: lh          $t7, 0x2($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X2);
    // 0x800556D8: addu        $t1, $t6, $a0
    ctx->r9 = ADD32(ctx->r14, ctx->r4);
    // 0x800556DC: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800556E0: mflo        $t2
    ctx->r10 = lo;
    // 0x800556E4: sh          $t2, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r10;
    // 0x800556E8: nop

    // 0x800556EC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800556F0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800556F4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800556F8: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x800556FC: lh          $t5, 0x2($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X2);
    // 0x80055700: nop

    // 0x80055704: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x80055708: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8005570C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80055710: nop

    // 0x80055714: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80055718: beq         $at, $zero, L_8005574C
    if (ctx->r1 == 0) {
        // 0x8005571C: nop
    
            goto L_8005574C;
    }
    // 0x8005571C: nop

    // 0x80055720: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80055724: addu        $t2, $t6, $a0
    ctx->r10 = ADD32(ctx->r14, ctx->r4);
    // 0x80055728: lh          $t1, 0x6($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X6);
    // 0x8005572C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80055730: nop

    // 0x80055734: beq         $t1, $t0, L_8005574C
    if (ctx->r9 == ctx->r8) {
        // 0x80055738: nop
    
            goto L_8005574C;
    }
    // 0x80055738: nop

    // 0x8005573C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80055740: nop

    // 0x80055744: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x80055748: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
L_8005574C:
    // 0x8005574C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055750: nop

    // 0x80055754: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80055758: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8005575C: bne         $at, $zero, L_80055654
    if (ctx->r1 != 0) {
        // 0x80055760: sw          $t5, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r13;
            goto L_80055654;
    }
    // 0x80055760: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80055764: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80055768: nop

    // 0x8005576C: bne         $t9, $zero, L_800557A8
    if (ctx->r25 != 0) {
        // 0x80055770: nop
    
            goto L_800557A8;
    }
    // 0x80055770: nop

    // 0x80055774: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80055778: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8005577C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80055780: lw          $t2, 0x670($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X670);
    // 0x80055784: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055788: bgez        $t2, L_8005579C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8005578C: andi        $t1, $t2, 0x3
        ctx->r9 = ctx->r10 & 0X3;
            goto L_8005579C;
    }
    // 0x8005578C: andi        $t1, $t2, 0x3
    ctx->r9 = ctx->r10 & 0X3;
    // 0x80055790: beq         $t1, $zero, L_8005579C
    if (ctx->r9 == 0) {
        // 0x80055794: nop
    
            goto L_8005579C;
    }
    // 0x80055794: nop

    // 0x80055798: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_8005579C:
    // 0x8005579C: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x800557A0: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x800557A4: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
L_800557A8:
    // 0x800557A8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800557AC: lw          $t3, 0x670($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X670);
    // 0x800557B0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800557B4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800557B8: div         $zero, $t3, $t4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r12)));
    // 0x800557BC: bne         $t4, $zero, L_800557C8
    if (ctx->r12 != 0) {
        // 0x800557C0: nop
    
            goto L_800557C8;
    }
    // 0x800557C0: nop

    // 0x800557C4: break       7
    do_break(2147833796);
L_800557C8:
    // 0x800557C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800557CC: bne         $t4, $at, L_800557E0
    if (ctx->r12 != ctx->r1) {
        // 0x800557D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800557E0;
    }
    // 0x800557D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800557D4: bne         $t3, $at, L_800557E0
    if (ctx->r11 != ctx->r1) {
        // 0x800557D8: nop
    
            goto L_800557E0;
    }
    // 0x800557D8: nop

    // 0x800557DC: break       6
    do_break(2147833820);
L_800557E0:
    // 0x800557E0: mfhi        $t5
    ctx->r13 = hi;
    // 0x800557E4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800557E8: nop

L_800557EC:
    // 0x800557EC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800557F0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800557F4: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x800557F8: addu        $t1, $a0, $t2
    ctx->r9 = ADD32(ctx->r4, ctx->r10);
    // 0x800557FC: lh          $t0, 0x2($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2);
    // 0x80055800: nop

    // 0x80055804: subu        $t6, $t9, $t0
    ctx->r14 = SUB32(ctx->r25, ctx->r8);
    // 0x80055808: bgez        $t6, L_8005582C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005580C: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_8005582C;
    }
    // 0x8005580C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80055810: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80055814: nop

    // 0x80055818: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8005581C: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x80055820: lh          $v0, 0x0($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X0);
    // 0x80055824: b           L_80055868
    // 0x80055828: nop

        goto L_80055868;
    // 0x80055828: nop

L_8005582C:
    // 0x8005582C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80055830: nop

    // 0x80055834: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80055838: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8005583C: bne         $at, $zero, L_800557EC
    if (ctx->r1 != 0) {
        // 0x80055840: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_800557EC;
    }
    // 0x80055840: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80055844: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80055848: nop

    // 0x8005584C: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80055850: addu        $t9, $t1, $a0
    ctx->r25 = ADD32(ctx->r9, ctx->r4);
    // 0x80055854: lh          $v0, 0x0($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X0);
    // 0x80055858: b           L_80055868
    // 0x8005585C: nop

        goto L_80055868;
    // 0x8005585C: nop

    // 0x80055860: b           L_80055868
    // 0x80055864: nop

        goto L_80055868;
    // 0x80055864: nop

L_80055868:
    // 0x80055868: jr          $ra
    // 0x8005586C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005586C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80069C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069C60: jal         0x80061488
    // 0x80069C64: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80069C64: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_0:
    // 0x80069C68: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80069C6C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80069C70: b           L_80069C80
    // 0x80069C74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80069C80;
    // 0x80069C74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069C78: b           L_80069C80
    // 0x80069C7C: nop

        goto L_80069C80;
    // 0x80069C7C: nop

L_80069C80:
    // 0x80069C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069C88: jr          $ra
    // 0x80069C8C: nop

    return;
    // 0x80069C8C: nop

;}
RECOMP_FUNC void func_8008E510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E510: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008E514: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8008E518: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8008E51C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008E520: addiu       $t6, $t6, 0x4C50
    ctx->r14 = ADD32(ctx->r14, 0X4C50);
    // 0x8008E524: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_8008E528:
    // 0x8008E528: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008E52C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8008E530: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8008E534: nop

    // 0x8008E538: bne         $t8, $at, L_8008E548
    if (ctx->r24 != ctx->r1) {
        // 0x8008E53C: nop
    
            goto L_8008E548;
    }
    // 0x8008E53C: nop

    // 0x8008E540: b           L_8008E594
    // 0x8008E544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E594;
    // 0x8008E544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E548:
    // 0x8008E548: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008E54C: nop

    // 0x8008E550: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8008E554: nop

    // 0x8008E558: bne         $t0, $a0, L_8008E578
    if (ctx->r8 != ctx->r4) {
        // 0x8008E55C: nop
    
            goto L_8008E578;
    }
    // 0x8008E55C: nop

    // 0x8008E560: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x8008E564: nop

    // 0x8008E568: bne         $t1, $a1, L_8008E578
    if (ctx->r9 != ctx->r5) {
        // 0x8008E56C: nop
    
            goto L_8008E578;
    }
    // 0x8008E56C: nop

    // 0x8008E570: b           L_8008E594
    // 0x8008E574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008E594;
    // 0x8008E574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E578:
    // 0x8008E578: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008E57C: nop

    // 0x8008E580: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8008E584: b           L_8008E528
    // 0x8008E588: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
        goto L_8008E528;
    // 0x8008E588: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8008E58C: b           L_8008E594
    // 0x8008E590: nop

        goto L_8008E594;
    // 0x8008E590: nop

L_8008E594:
    // 0x8008E594: jr          $ra
    // 0x8008E598: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008E598: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008E59C: nop

;}
RECOMP_FUNC void MtxUtil_SetCurrentFromMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2B28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C2B2C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2B30: lw          $a0, 0xCE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE4);
    // 0x800C2B34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C2B38: jal         0x800C2F1C
    // 0x800C2B3C: nop

    MtxUtil__MtxToMtxF(rdram, ctx);
        goto after_0;
    // 0x800C2B3C: nop

    after_0:
    // 0x800C2B40: b           L_800C2B48
    // 0x800C2B44: nop

        goto L_800C2B48;
    // 0x800C2B44: nop

L_800C2B48:
    // 0x800C2B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2B50: jr          $ra
    // 0x800C2B54: nop

    return;
    // 0x800C2B54: nop

;}
RECOMP_FUNC void func_80077FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FF0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80077FF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80077FF8: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x80077FFC: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x80078000: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80078004: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x80078008: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8007800C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80078010: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80078014: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x80078018: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x8007801C: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x80078020: jal         0x800B35D4
    // 0x80078024: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B35D4(rdram, ctx);
        goto after_0;
    // 0x80078024: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80078028: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007802C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80078030: nop

    // 0x80078034: bgtz        $t8, L_80078044
    if (SIGNED(ctx->r24) > 0) {
        // 0x80078038: nop
    
            goto L_80078044;
    }
    // 0x80078038: nop

    // 0x8007803C: b           L_800780B0
    // 0x80078040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800780B0;
    // 0x80078040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078044:
    // 0x80078044: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80078048: addiu       $t9, $t9, 0x7340
    ctx->r25 = ADD32(ctx->r25, 0X7340);
    // 0x8007804C: lw          $t0, 0x144($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X144);
    // 0x80078050: nop

    // 0x80078054: bne         $t0, $zero, L_80078064
    if (ctx->r8 != 0) {
        // 0x80078058: nop
    
            goto L_80078064;
    }
    // 0x80078058: nop

    // 0x8007805C: b           L_800780B0
    // 0x80078060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800780B0;
    // 0x80078060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078064:
    // 0x80078064: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80078068: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8007806C: lhu         $t1, 0xCA($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XCA);
    // 0x80078070: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80078074: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80078078: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8007807C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80078080: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80078084: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80078088: jal         0x80078628
    // 0x8007808C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_80078628(rdram, ctx);
        goto after_1;
    // 0x8007808C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_1:
    // 0x80078090: bne         $v0, $zero, L_800780A0
    if (ctx->r2 != 0) {
        // 0x80078094: nop
    
            goto L_800780A0;
    }
    // 0x80078094: nop

    // 0x80078098: b           L_800780B0
    // 0x8007809C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800780B0;
    // 0x8007809C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800780A0:
    // 0x800780A0: b           L_800780B0
    // 0x800780A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800780B0;
    // 0x800780A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800780A8: b           L_800780B0
    // 0x800780AC: nop

        goto L_800780B0;
    // 0x800780AC: nop

L_800780B0:
    // 0x800780B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800780B4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x800780B8: jr          $ra
    // 0x800780BC: nop

    return;
    // 0x800780BC: nop

;}
RECOMP_FUNC void func_80060E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E24: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80060E28: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80060E2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060E30: beq         $a1, $at, L_80060E64
    if (ctx->r5 == ctx->r1) {
        // 0x80060E34: nop
    
            goto L_80060E64;
    }
    // 0x80060E34: nop

    // 0x80060E38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060E3C: beq         $a1, $at, L_80060E6C
    if (ctx->r5 == ctx->r1) {
        // 0x80060E40: nop
    
            goto L_80060E6C;
    }
    // 0x80060E40: nop

    // 0x80060E44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80060E48: beq         $a1, $at, L_80060E74
    if (ctx->r5 == ctx->r1) {
        // 0x80060E4C: nop
    
            goto L_80060E74;
    }
    // 0x80060E4C: nop

    // 0x80060E50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80060E54: beq         $a1, $at, L_80060E7C
    if (ctx->r5 == ctx->r1) {
        // 0x80060E58: nop
    
            goto L_80060E7C;
    }
    // 0x80060E58: nop

    // 0x80060E5C: b           L_80060E84
    // 0x80060E60: nop

        goto L_80060E84;
    // 0x80060E60: nop

L_80060E64:
    // 0x80060E64: b           L_80060E94
    // 0x80060E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060E94;
    // 0x80060E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060E6C:
    // 0x80060E6C: b           L_80060E94
    // 0x80060E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060E94;
    // 0x80060E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060E74:
    // 0x80060E74: b           L_80060E94
    // 0x80060E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060E94;
    // 0x80060E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060E7C:
    // 0x80060E7C: b           L_80060E94
    // 0x80060E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060E94;
    // 0x80060E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060E84:
    // 0x80060E84: b           L_80060E94
    // 0x80060E88: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80060E94;
    // 0x80060E88: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80060E8C: b           L_80060E94
    // 0x80060E90: nop

        goto L_80060E94;
    // 0x80060E90: nop

L_80060E94:
    // 0x80060E94: jr          $ra
    // 0x80060E98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80060E98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80074354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007435C: jal         0x80061348
    // 0x80074360: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074360: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x80074364: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074368: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007436C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074370: beq         $v0, $zero, L_800743C4
    if (ctx->r2 == 0) {
        // 0x80074374: nop
    
            goto L_800743C4;
    }
    // 0x80074374: nop

    // 0x80074378: jal         0x80061348
    // 0x8007437C: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007437C: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074380: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074384: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074388: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007438C: beq         $v0, $zero, L_800743C4
    if (ctx->r2 == 0) {
        // 0x80074390: nop
    
            goto L_800743C4;
    }
    // 0x80074390: nop

    // 0x80074394: jal         0x80061348
    // 0x80074398: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074398: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x8007439C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800743A0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800743A4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800743A8: beq         $v0, $zero, L_800743C4
    if (ctx->r2 == 0) {
        // 0x800743AC: nop
    
            goto L_800743C4;
    }
    // 0x800743AC: nop

    // 0x800743B0: jal         0x80061348
    // 0x800743B4: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800743B4: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x800743B8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800743BC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800743C0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800743C4:
    // 0x800743C4: b           L_800743D4
    // 0x800743C8: nop

        goto L_800743D4;
    // 0x800743C8: nop

    // 0x800743CC: b           L_800743D4
    // 0x800743D0: nop

        goto L_800743D4;
    // 0x800743D0: nop

L_800743D4:
    // 0x800743D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800743D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800743DC: jr          $ra
    // 0x800743E0: nop

    return;
    // 0x800743E0: nop

;}
RECOMP_FUNC void _frexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1048: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800D104C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D1050: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D1054: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D1058: c.eq.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d == ctx->f2.d;
    // 0x800D105C: nop

    // 0x800D1060: bc1fl       L_800D1074
    if (!c1cs) {
        // 0x800D1064: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800D1074;
    }
    goto skip_0;
    // 0x800D1064: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_0:
    // 0x800D1068: jr          $ra
    // 0x800D106C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x800D106C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800D1070: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800D1074:
    // 0x800D1074: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800D1078: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800D107C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D1080: bc1fl       L_800D1094
    if (!c1cs) {
        // 0x800D1084: neg.d       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
            goto L_800D1094;
    }
    goto skip_1;
    // 0x800D1084: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
    skip_1:
    // 0x800D1088: b           L_800D1094
    // 0x800D108C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800D1094;
    // 0x800D108C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800D1090: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
L_800D1094:
    // 0x800D1094: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800D1098: nop

    // 0x800D109C: bc1fl       L_800D10D4
    if (!c1cs) {
        // 0x800D10A0: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800D10D4;
    }
    goto skip_2;
    // 0x800D10A0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_2:
    // 0x800D10A4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D10A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D10AC: nop

L_800D10B0:
    // 0x800D10B0: mul.d       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x800D10B4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D10B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D10BC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D10C0: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800D10C4: nop

    // 0x800D10C8: bc1t        L_800D10B0
    if (c1cs) {
        // 0x800D10CC: nop
    
            goto L_800D10B0;
    }
    // 0x800D10CC: nop

    // 0x800D10D0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_800D10D4:
    // 0x800D10D4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D10D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D10DC: nop

    // 0x800D10E0: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x800D10E4: nop

    // 0x800D10E8: bc1fl       L_800D1110
    if (!c1cs) {
        // 0x800D10EC: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800D1110;
    }
    goto skip_3;
    // 0x800D10EC: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_3:
    // 0x800D10F0: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
L_800D10F4:
    // 0x800D10F4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D10F8: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x800D10FC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800D1100: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D1104: bc1tl       L_800D10F4
    if (c1cs) {
        // 0x800D1108: add.d       $f0, $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
            goto L_800D10F4;
    }
    goto skip_4;
    // 0x800D1108: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    skip_4:
    // 0x800D110C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800D1110:
    // 0x800D1110: nop

    // 0x800D1114: bc1fl       L_800D1128
    if (!c1cs) {
        // 0x800D1118: neg.d       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
            goto L_800D1128;
    }
    goto skip_5;
    // 0x800D1118: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
    skip_5:
    // 0x800D111C: b           L_800D1128
    // 0x800D1120: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
        goto L_800D1128;
    // 0x800D1120: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x800D1124: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
L_800D1128:
    // 0x800D1128: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x800D112C: jr          $ra
    // 0x800D1130: nop

    return;
    // 0x800D1130: nop

;}
RECOMP_FUNC void func_80073600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073600: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073604: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073608: nop

    // 0x8007360C: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80073610: nop

    // 0x80073614: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80073618: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007361C: jr          $ra
    // 0x80073620: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073620: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073624: jr          $ra
    // 0x80073628: nop

    return;
    // 0x80073628: nop

    // 0x8007362C: jr          $ra
    // 0x80073630: nop

    return;
    // 0x80073630: nop

;}
RECOMP_FUNC void func_8006800C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006800C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068010: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068014: nop

    // 0x80068018: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006801C: nop

    // 0x80068020: slti        $t7, $v0, 0x190
    ctx->r15 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80068024: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068028: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006802C: beq         $v0, $zero, L_80068064
    if (ctx->r2 == 0) {
        // 0x80068030: nop
    
            goto L_80068064;
    }
    // 0x80068030: nop

    // 0x80068034: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80068038: nop

    // 0x8006803C: slti        $t8, $v0, 0x190
    ctx->r24 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80068040: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80068044: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80068048: beq         $v0, $zero, L_80068064
    if (ctx->r2 == 0) {
        // 0x8006804C: nop
    
            goto L_80068064;
    }
    // 0x8006804C: nop

    // 0x80068050: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80068054: nop

    // 0x80068058: slti        $t9, $v0, 0x190
    ctx->r25 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x8006805C: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80068060: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80068064:
    // 0x80068064: jr          $ra
    // 0x80068068: nop

    return;
    // 0x80068068: nop

    // 0x8006806C: jr          $ra
    // 0x80068070: nop

    return;
    // 0x80068070: nop

    // 0x80068074: jr          $ra
    // 0x80068078: nop

    return;
    // 0x80068078: nop

;}
RECOMP_FUNC void SysMem_GetFreeSpace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCEBC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BCEC0: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x800BCEC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCEC8: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x800BCECC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCED0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCED4: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCED8: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCEDC: nop

    // 0x800BCEE0: beq         $t6, $t7, L_800BCF54
    if (ctx->r14 == ctx->r15) {
        // 0x800BCEE4: sw          $t6, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r14;
            goto L_800BCF54;
    }
    // 0x800BCEE4: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
L_800BCEE8:
    // 0x800BCEE8: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800BCEEC: nop

    // 0x800BCEF0: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    // 0x800BCEF4: nop

    // 0x800BCEF8: sltiu       $t9, $a0, 0x1
    ctx->r25 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x800BCEFC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800BCF00: andi        $t0, $a0, 0x1
    ctx->r8 = ctx->r4 & 0X1;
    // 0x800BCF04: beq         $t0, $zero, L_800BCF38
    if (ctx->r8 == 0) {
        // 0x800BCF08: nop
    
            goto L_800BCF38;
    }
    // 0x800BCF08: nop

    // 0x800BCF0C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800BCF10: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800BCF14: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800BCF18: nop

    // 0x800BCF1C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800BCF20: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800BCF24: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BCF28: lh          $t5, 0x2638($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2638);
    // 0x800BCF2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCF30: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800BCF34: sh          $t6, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = ctx->r14;
L_800BCF38:
    // 0x800BCF38: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800BCF3C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BCF40: lw          $t9, 0x25E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25E8);
    // 0x800BCF44: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800BCF48: nop

    // 0x800BCF4C: bne         $t8, $t9, L_800BCEE8
    if (ctx->r24 != ctx->r25) {
        // 0x800BCF50: sw          $t8, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r24;
            goto L_800BCEE8;
    }
    // 0x800BCF50: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
L_800BCF54:
    // 0x800BCF54: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
    // 0x800BCF58: nop

    // 0x800BCF5C: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x800BCF60: b           L_800BCF70
    // 0x800BCF64: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800BCF70;
    // 0x800BCF64: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800BCF68: b           L_800BCF70
    // 0x800BCF6C: nop

        goto L_800BCF70;
    // 0x800BCF6C: nop

L_800BCF70:
    // 0x800BCF70: jr          $ra
    // 0x800BCF74: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BCF74: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8002E414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E414: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002E418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E41C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E420: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002E424: lhu         $t6, -0x6504($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6504);
    // 0x8002E428: nop

    // 0x8002E42C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8002E430: bne         $t7, $zero, L_8002E440
    if (ctx->r15 != 0) {
        // 0x8002E434: nop
    
            goto L_8002E440;
    }
    // 0x8002E434: nop

    // 0x8002E438: b           L_8002EAE0
    // 0x8002E43C: nop

        goto L_8002EAE0;
    // 0x8002E43C: nop

L_8002E440:
    // 0x8002E440: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8002E444: lw          $t8, -0x73D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73D0);
    // 0x8002E448: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E44C: nop

    // 0x8002E450: swc1        $f4, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f4.u32l;
    // 0x8002E454: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x8002E458: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002E45C: lw          $t9, 0x16C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X16C0);
    // 0x8002E460: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E464: nop

    // 0x8002E468: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8002E46C: lui         $at, 0x42DE
    ctx->r1 = S32(0X42DE << 16);
    // 0x8002E470: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002E474: lw          $t0, 0x2648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2648);
    // 0x8002E478: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E47C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002E480: swc1        $f8, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f8.u32l;
    // 0x8002E484: lw          $t1, 0x2648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2648);
    // 0x8002E488: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002E48C: lw          $t2, 0x2644($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2644);
    // 0x8002E490: lwc1        $f10, 0xD0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x8002E494: nop

    // 0x8002E498: swc1        $f10, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f10.u32l;
    // 0x8002E49C: jal         0x800C1754
    // 0x8002E4A0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8002E4A0: nop

    after_0:
    // 0x8002E4A4: jal         0x800A7160
    // 0x8002E4A8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800A7160(rdram, ctx);
        goto after_1;
    // 0x8002E4A8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x8002E4AC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002E4B0: addiu       $t3, $t3, 0x7340
    ctx->r11 = ADD32(ctx->r11, 0X7340);
    // 0x8002E4B4: lwc1        $f12, 0x1010($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X1010);
    // 0x8002E4B8: jal         0x800C2780
    // 0x8002E4BC: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8002E4BC: nop

    after_2:
    // 0x8002E4C0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002E4C4: addiu       $t4, $t4, 0x7340
    ctx->r12 = ADD32(ctx->r12, 0X7340);
    // 0x8002E4C8: lwc1        $f12, 0x100C($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X100C);
    // 0x8002E4CC: jal         0x800C25B8
    // 0x8002E4D0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8002E4D0: nop

    after_3:
    // 0x8002E4D4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002E4D8: addiu       $t5, $t5, 0x7340
    ctx->r13 = ADD32(ctx->r13, 0X7340);
    // 0x8002E4DC: lwc1        $f12, 0x1008($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X1008);
    // 0x8002E4E0: jal         0x800C23E8
    // 0x8002E4E4: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8002E4E4: nop

    after_4:
    // 0x8002E4E8: jal         0x800A72BC
    // 0x8002E4EC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800A72BC(rdram, ctx);
        goto after_5;
    // 0x8002E4EC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_5:
    // 0x8002E4F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E4F4: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E4F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E4FC: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002E500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E504: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8002E508: swc1        $f4, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f4.u32l;
    // 0x8002E50C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002E510: lh          $s0, 0x25A4($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X25A4);
    // 0x8002E514: nop

    // 0x8002E518: beq         $s0, $zero, L_8002E54C
    if (ctx->r16 == 0) {
        // 0x8002E51C: nop
    
            goto L_8002E54C;
    }
    // 0x8002E51C: nop

    // 0x8002E520: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002E524: beq         $s0, $at, L_8002E5F8
    if (ctx->r16 == ctx->r1) {
        // 0x8002E528: nop
    
            goto L_8002E5F8;
    }
    // 0x8002E528: nop

    // 0x8002E52C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002E530: beq         $s0, $at, L_8002E6A4
    if (ctx->r16 == ctx->r1) {
        // 0x8002E534: nop
    
            goto L_8002E6A4;
    }
    // 0x8002E534: nop

    // 0x8002E538: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E53C: beq         $s0, $at, L_8002E6A4
    if (ctx->r16 == ctx->r1) {
        // 0x8002E540: nop
    
            goto L_8002E6A4;
    }
    // 0x8002E540: nop

    // 0x8002E544: b           L_8002E750
    // 0x8002E548: nop

        goto L_8002E750;
    // 0x8002E548: nop

L_8002E54C:
    // 0x8002E54C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E550: lwc1        $f6, 0x25B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E554: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E558: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002E55C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E560: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002E564: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8002E568: nop

    // 0x8002E56C: bc1f        L_8002E5F0
    if (!c1cs) {
        // 0x8002E570: nop
    
            goto L_8002E5F0;
    }
    // 0x8002E570: nop

L_8002E574:
    // 0x8002E574: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002E578: lw          $t6, 0x2644($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2644);
    // 0x8002E57C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E580: lw          $a0, 0x138($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X138);
    // 0x8002E584: jal         0x80030438
    // 0x8002E588: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80030438(rdram, ctx);
        goto after_6;
    // 0x8002E588: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_6:
    // 0x8002E58C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E590: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E594: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E598: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E59C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E5A0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E5A4: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x8002E5A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E5AC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002E5B0: swc1        $f8, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f8.u32l;
    // 0x8002E5B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E5B8: lh          $t7, 0x25C4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X25C4);
    // 0x8002E5BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E5C0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002E5C4: sh          $t8, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r24;
    // 0x8002E5C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E5CC: lwc1        $f10, 0x25B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E5D0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E5D4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E5D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E5DC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E5E0: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8002E5E4: nop

    // 0x8002E5E8: bc1t        L_8002E574
    if (c1cs) {
        // 0x8002E5EC: nop
    
            goto L_8002E574;
    }
    // 0x8002E5EC: nop

L_8002E5F0:
    // 0x8002E5F0: b           L_8002E750
    // 0x8002E5F4: nop

        goto L_8002E750;
    // 0x8002E5F4: nop

L_8002E5F8:
    // 0x8002E5F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E5FC: lwc1        $f4, 0x25B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E600: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E604: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E608: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E60C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002E610: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8002E614: nop

    // 0x8002E618: bc1f        L_8002E69C
    if (!c1cs) {
        // 0x8002E61C: nop
    
            goto L_8002E69C;
    }
    // 0x8002E61C: nop

L_8002E620:
    // 0x8002E620: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002E624: lw          $t9, 0x2644($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2644);
    // 0x8002E628: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8002E62C: lw          $a0, 0x138($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X138);
    // 0x8002E630: jal         0x80030438
    // 0x8002E634: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_80030438(rdram, ctx);
        goto after_7;
    // 0x8002E634: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_7:
    // 0x8002E638: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E63C: lwc1        $f10, 0x25B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E640: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E644: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E648: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E64C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E650: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x8002E654: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E658: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8002E65C: swc1        $f6, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f6.u32l;
    // 0x8002E660: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002E664: lh          $t0, 0x25C4($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X25C4);
    // 0x8002E668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E66C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8002E670: sh          $t1, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r9;
    // 0x8002E674: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E678: lwc1        $f8, 0x25B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E67C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E680: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E684: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E688: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E68C: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x8002E690: nop

    // 0x8002E694: bc1t        L_8002E620
    if (c1cs) {
        // 0x8002E698: nop
    
            goto L_8002E620;
    }
    // 0x8002E698: nop

L_8002E69C:
    // 0x8002E69C: b           L_8002E750
    // 0x8002E6A0: nop

        goto L_8002E750;
    // 0x8002E6A0: nop

L_8002E6A4:
    // 0x8002E6A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E6A8: lwc1        $f18, 0x25B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E6AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E6B0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E6B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E6B8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E6BC: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8002E6C0: nop

    // 0x8002E6C4: bc1f        L_8002E748
    if (!c1cs) {
        // 0x8002E6C8: nop
    
            goto L_8002E748;
    }
    // 0x8002E6C8: nop

L_8002E6CC:
    // 0x8002E6CC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002E6D0: lw          $t2, 0x2644($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2644);
    // 0x8002E6D4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8002E6D8: lw          $a0, 0x138($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X138);
    // 0x8002E6DC: jal         0x80030438
    // 0x8002E6E0: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    func_80030438(rdram, ctx);
        goto after_8;
    // 0x8002E6E0: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    after_8:
    // 0x8002E6E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E6E8: lwc1        $f8, 0x25B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E6EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E6F0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E6F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E6F8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E6FC: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8002E700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E704: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002E708: swc1        $f4, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f4.u32l;
    // 0x8002E70C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002E710: lh          $t3, 0x25C4($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X25C4);
    // 0x8002E714: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E718: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002E71C: sh          $t4, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r12;
    // 0x8002E720: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E724: lwc1        $f6, 0x25B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E728: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E72C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002E730: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E734: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002E738: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8002E73C: nop

    // 0x8002E740: bc1t        L_8002E6CC
    if (c1cs) {
        // 0x8002E744: nop
    
            goto L_8002E6CC;
    }
    // 0x8002E744: nop

L_8002E748:
    // 0x8002E748: b           L_8002E750
    // 0x8002E74C: nop

        goto L_8002E750;
    // 0x8002E74C: nop

L_8002E750:
    // 0x8002E750: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002E754: lh          $t5, 0x25C4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X25C4);
    // 0x8002E758: nop

    // 0x8002E75C: slti        $at, $t5, 0x1F
    ctx->r1 = SIGNED(ctx->r13) < 0X1F ? 1 : 0;
    // 0x8002E760: bne         $at, $zero, L_8002E79C
    if (ctx->r1 != 0) {
        // 0x8002E764: nop
    
            goto L_8002E79C;
    }
    // 0x8002E764: nop

    // 0x8002E768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E76C: sh          $zero, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = 0;
    // 0x8002E770: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002E774: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8002E778: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E77C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002E780: lh          $a1, 0x25A4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X25A4);
    // 0x8002E784: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E788: lh          $a2, 0x0($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X0);
    // 0x8002E78C: jal         0x8002D3B0
    // 0x8002E790: nop

    func_8002D3B0(rdram, ctx);
        goto after_9;
    // 0x8002E790: nop

    after_9:
    // 0x8002E794: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E798: sh          $v0, 0x25A4($at)
    MEM_H(0X25A4, ctx->r1) = ctx->r2;
L_8002E79C:
    // 0x8002E79C: jal         0x800C1850
    // 0x8002E7A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_10;
    // 0x8002E7A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8002E7A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E7A8: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E7AC: jal         0x8009A14C
    // 0x8002E7B0: nop

    func_8009A14C(rdram, ctx);
        goto after_11;
    // 0x8002E7B0: nop

    after_11:
    // 0x8002E7B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E7B8: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E7BC: jal         0x800997D8
    // 0x8002E7C0: nop

    func_800997D8(rdram, ctx);
        goto after_12;
    // 0x8002E7C0: nop

    after_12:
    // 0x8002E7C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E7C8: lwc1        $f16, 0x25BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E7CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E7D0: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002E7D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E7D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8002E7DC: swc1        $f4, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f4.u32l;
    // 0x8002E7E0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002E7E4: lh          $s0, 0x25AC($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X25AC);
    // 0x8002E7E8: nop

    // 0x8002E7EC: beq         $s0, $zero, L_8002E820
    if (ctx->r16 == 0) {
        // 0x8002E7F0: nop
    
            goto L_8002E820;
    }
    // 0x8002E7F0: nop

    // 0x8002E7F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002E7F8: beq         $s0, $at, L_8002E8CC
    if (ctx->r16 == ctx->r1) {
        // 0x8002E7FC: nop
    
            goto L_8002E8CC;
    }
    // 0x8002E7FC: nop

    // 0x8002E800: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002E804: beq         $s0, $at, L_8002E978
    if (ctx->r16 == ctx->r1) {
        // 0x8002E808: nop
    
            goto L_8002E978;
    }
    // 0x8002E808: nop

    // 0x8002E80C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E810: beq         $s0, $at, L_8002E978
    if (ctx->r16 == ctx->r1) {
        // 0x8002E814: nop
    
            goto L_8002E978;
    }
    // 0x8002E814: nop

    // 0x8002E818: b           L_8002EA24
    // 0x8002E81C: nop

        goto L_8002EA24;
    // 0x8002E81C: nop

L_8002E820:
    // 0x8002E820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E824: lwc1        $f6, 0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E828: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E82C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002E830: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E834: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002E838: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8002E83C: nop

    // 0x8002E840: bc1f        L_8002E8C4
    if (!c1cs) {
        // 0x8002E844: nop
    
            goto L_8002E8C4;
    }
    // 0x8002E844: nop

L_8002E848:
    // 0x8002E848: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E84C: lw          $t7, 0x2648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2648);
    // 0x8002E850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E854: lw          $a0, 0x138($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X138);
    // 0x8002E858: jal         0x80030438
    // 0x8002E85C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80030438(rdram, ctx);
        goto after_13;
    // 0x8002E85C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_13:
    // 0x8002E860: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E864: lwc1        $f16, 0x25BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E868: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E86C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E870: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E874: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E878: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x8002E87C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E880: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002E884: swc1        $f8, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f8.u32l;
    // 0x8002E888: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002E88C: lh          $t8, 0x25CC($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X25CC);
    // 0x8002E890: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E894: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002E898: sh          $t9, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r25;
    // 0x8002E89C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E8A0: lwc1        $f10, 0x25BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E8A4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E8A8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E8AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E8B0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E8B4: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8002E8B8: nop

    // 0x8002E8BC: bc1t        L_8002E848
    if (c1cs) {
        // 0x8002E8C0: nop
    
            goto L_8002E848;
    }
    // 0x8002E8C0: nop

L_8002E8C4:
    // 0x8002E8C4: b           L_8002EA24
    // 0x8002E8C8: nop

        goto L_8002EA24;
    // 0x8002E8C8: nop

L_8002E8CC:
    // 0x8002E8CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E8D0: lwc1        $f4, 0x25BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E8D4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E8D8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E8DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E8E0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002E8E4: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8002E8E8: nop

    // 0x8002E8EC: bc1f        L_8002E970
    if (!c1cs) {
        // 0x8002E8F0: nop
    
            goto L_8002E970;
    }
    // 0x8002E8F0: nop

L_8002E8F4:
    // 0x8002E8F4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002E8F8: lw          $t0, 0x2648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2648);
    // 0x8002E8FC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8002E900: lw          $a0, 0x138($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X138);
    // 0x8002E904: jal         0x80030438
    // 0x8002E908: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_80030438(rdram, ctx);
        goto after_14;
    // 0x8002E908: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_14:
    // 0x8002E90C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E910: lwc1        $f10, 0x25BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E914: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E918: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E91C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E920: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E924: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x8002E928: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E92C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8002E930: swc1        $f6, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f6.u32l;
    // 0x8002E934: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002E938: lh          $t1, 0x25CC($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X25CC);
    // 0x8002E93C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E940: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8002E944: sh          $t2, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r10;
    // 0x8002E948: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E94C: lwc1        $f8, 0x25BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E950: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E954: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E958: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E95C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E960: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x8002E964: nop

    // 0x8002E968: bc1t        L_8002E8F4
    if (c1cs) {
        // 0x8002E96C: nop
    
            goto L_8002E8F4;
    }
    // 0x8002E96C: nop

L_8002E970:
    // 0x8002E970: b           L_8002EA24
    // 0x8002E974: nop

        goto L_8002EA24;
    // 0x8002E974: nop

L_8002E978:
    // 0x8002E978: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E97C: lwc1        $f18, 0x25BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E980: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E984: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E988: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E98C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E990: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8002E994: nop

    // 0x8002E998: bc1f        L_8002EA1C
    if (!c1cs) {
        // 0x8002E99C: nop
    
            goto L_8002EA1C;
    }
    // 0x8002E99C: nop

L_8002E9A0:
    // 0x8002E9A0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002E9A4: lw          $t3, 0x2648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2648);
    // 0x8002E9A8: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8002E9AC: lw          $a0, 0x138($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X138);
    // 0x8002E9B0: jal         0x80030438
    // 0x8002E9B4: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    func_80030438(rdram, ctx);
        goto after_15;
    // 0x8002E9B4: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    after_15:
    // 0x8002E9B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E9BC: lwc1        $f8, 0x25BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E9C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E9C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E9C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E9CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E9D0: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8002E9D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E9D8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002E9DC: swc1        $f4, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f4.u32l;
    // 0x8002E9E0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002E9E4: lh          $t4, 0x25CC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X25CC);
    // 0x8002E9E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E9EC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002E9F0: sh          $t5, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r13;
    // 0x8002E9F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E9F8: lwc1        $f6, 0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E9FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002EA00: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002EA04: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002EA08: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EA0C: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8002EA10: nop

    // 0x8002EA14: bc1t        L_8002E9A0
    if (c1cs) {
        // 0x8002EA18: nop
    
            goto L_8002E9A0;
    }
    // 0x8002EA18: nop

L_8002EA1C:
    // 0x8002EA1C: b           L_8002EA24
    // 0x8002EA20: nop

        goto L_8002EA24;
    // 0x8002EA20: nop

L_8002EA24:
    // 0x8002EA24: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002EA28: lh          $t6, 0x25CC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X25CC);
    // 0x8002EA2C: nop

    // 0x8002EA30: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x8002EA34: bne         $at, $zero, L_8002EAA8
    if (ctx->r1 != 0) {
        // 0x8002EA38: nop
    
            goto L_8002EAA8;
    }
    // 0x8002EA38: nop

    // 0x8002EA3C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002EA40: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8002EA44: nop

    // 0x8002EA48: bne         $t7, $zero, L_8002EA5C
    if (ctx->r15 != 0) {
        // 0x8002EA4C: nop
    
            goto L_8002EA5C;
    }
    // 0x8002EA4C: nop

    // 0x8002EA50: addiu       $t8, $zero, 0x3E7
    ctx->r24 = ADD32(0, 0X3E7);
    // 0x8002EA54: b           L_8002EA7C
    // 0x8002EA58: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
        goto L_8002EA7C;
    // 0x8002EA58: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
L_8002EA5C:
    // 0x8002EA5C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002EA60: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8002EA64: nop

    // 0x8002EA68: lw          $t0, 0xB4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XB4);
    // 0x8002EA6C: nop

    // 0x8002EA70: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8002EA74: nop

    // 0x8002EA78: sh          $t1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r9;
L_8002EA7C:
    // 0x8002EA7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002EA80: sh          $zero, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = 0;
    // 0x8002EA84: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EA88: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002EA8C: lh          $a1, 0x25AC($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X25AC);
    // 0x8002EA90: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002EA94: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    // 0x8002EA98: jal         0x8002D3B0
    // 0x8002EA9C: nop

    func_8002D3B0(rdram, ctx);
        goto after_16;
    // 0x8002EA9C: nop

    after_16:
    // 0x8002EAA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002EAA4: sh          $v0, 0x25AC($at)
    MEM_H(0X25AC, ctx->r1) = ctx->r2;
L_8002EAA8:
    // 0x8002EAA8: jal         0x800C1850
    // 0x8002EAAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_17;
    // 0x8002EAAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x8002EAB0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EAB4: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002EAB8: jal         0x8009A14C
    // 0x8002EABC: nop

    func_8009A14C(rdram, ctx);
        goto after_18;
    // 0x8002EABC: nop

    after_18:
    // 0x8002EAC0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EAC4: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002EAC8: jal         0x800997D8
    // 0x8002EACC: nop

    func_800997D8(rdram, ctx);
        goto after_19;
    // 0x8002EACC: nop

    after_19:
    // 0x8002EAD0: jal         0x800C1A28
    // 0x8002EAD4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_20;
    // 0x8002EAD4: nop

    after_20:
    // 0x8002EAD8: b           L_8002EAE0
    // 0x8002EADC: nop

        goto L_8002EAE0;
    // 0x8002EADC: nop

L_8002EAE0:
    // 0x8002EAE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EAE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002EAE8: jr          $ra
    // 0x8002EAEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002EAEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002EAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EAF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002EAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EAF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002EAFC: nop

    // 0x8002EB00: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8002EB04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EB08: lwc1        $f6, -0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EB0C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002EB10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002EB14: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EB18: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8002EB1C: nop

    // 0x8002EB20: bc1f        L_8002EBD4
    if (!c1cs) {
        // 0x8002EB24: nop
    
            goto L_8002EBD4;
    }
    // 0x8002EB24: nop

    // 0x8002EB28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002EB2C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002EB30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002EB34: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002EB38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002EB3C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002EB40: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x8002EB44: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EB48: lwc1        $f8, -0x7820($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EB4C: nop

    // 0x8002EB50: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002EB54: add.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f10.d + ctx->f6.d;
    // 0x8002EB58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EB5C: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8002EB60: swc1        $f16, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f16.u32l;
    // 0x8002EB64: lui         $at, 0xC030
    ctx->r1 = S32(0XC030 << 16);
    // 0x8002EB68: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002EB6C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002EB70: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x8002EB74: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8002EB78: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8002EB7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EB80: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EB84: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002EB88: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EB8C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8002EB90: c.le.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d <= ctx->f16.d;
    // 0x8002EB94: nop

    // 0x8002EB98: bc1f        L_8002EBCC
    if (!c1cs) {
        // 0x8002EB9C: nop
    
            goto L_8002EBCC;
    }
    // 0x8002EB9C: nop

    // 0x8002EBA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002EBA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EBA8: swc1        $f4, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f4.u32l;
    // 0x8002EBAC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8002EBB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002EBB4: jal         0x8002A22C
    // 0x8002EBB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002A22C(rdram, ctx);
        goto after_0;
    // 0x8002EBB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8002EBBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002EBC0: sw          $v0, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r2;
    // 0x8002EBC4: jal         0x80029ED8
    // 0x8002EBC8: nop

    func_80029ED8(rdram, ctx);
        goto after_1;
    // 0x8002EBC8: nop

    after_1:
L_8002EBCC:
    // 0x8002EBCC: b           L_8002EC6C
    // 0x8002EBD0: nop

        goto L_8002EC6C;
    // 0x8002EBD0: nop

L_8002EBD4:
    // 0x8002EBD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EBD8: lwc1        $f10, -0x7820($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EBDC: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8002EBE0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002EBE4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8002EBE8: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8002EBEC: nop

    // 0x8002EBF0: bc1f        L_8002EC6C
    if (!c1cs) {
        // 0x8002EBF4: nop
    
            goto L_8002EC6C;
    }
    // 0x8002EBF4: nop

    // 0x8002EBF8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002EBFC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002EC00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002EC04: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002EC08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002EC0C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8002EC10: mul.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x8002EC14: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EC18: lwc1        $f6, -0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EC1C: nop

    // 0x8002EC20: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EC24: sub.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f18.d - ctx->f10.d;
    // 0x8002EC28: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8002EC2C: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x8002EC30: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8002EC34: swc1        $f16, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f16.u32l;
    // 0x8002EC38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EC3C: lwc1        $f6, -0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EC40: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002EC44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002EC48: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EC4C: c.le.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d <= ctx->f10.d;
    // 0x8002EC50: nop

    // 0x8002EC54: bc1f        L_8002EC6C
    if (!c1cs) {
        // 0x8002EC58: nop
    
            goto L_8002EC6C;
    }
    // 0x8002EC58: nop

    // 0x8002EC5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EC60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EC64: swc1        $f8, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f8.u32l;
    // 0x8002EC68: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_8002EC6C:
    // 0x8002EC6C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002EC70: b           L_8002EC80
    // 0x8002EC74: nop

        goto L_8002EC80;
    // 0x8002EC74: nop

    // 0x8002EC78: b           L_8002EC80
    // 0x8002EC7C: nop

        goto L_8002EC80;
    // 0x8002EC7C: nop

L_8002EC80:
    // 0x8002EC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002EC84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002EC88: jr          $ra
    // 0x8002EC8C: nop

    return;
    // 0x8002EC8C: nop

;}
RECOMP_FUNC void func_8000F598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F59C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F5A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000F5A4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000F5A8: nop

    // 0x8000F5AC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000F5B0: nop

    // 0x8000F5B4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8000F5B8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F5BC: nop

    // 0x8000F5C0: addiu       $a0, $t8, 0xC
    ctx->r4 = ADD32(ctx->r24, 0XC);
    // 0x8000F5C4: jal         0x800B2748
    // 0x8000F5C8: addiu       $a1, $t8, 0x10
    ctx->r5 = ADD32(ctx->r24, 0X10);
    func_800B2748(rdram, ctx);
        goto after_0;
    // 0x8000F5C8: addiu       $a1, $t8, 0x10
    ctx->r5 = ADD32(ctx->r24, 0X10);
    after_0:
    // 0x8000F5CC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8000F5D0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8000F5D4: nop

    // 0x8000F5D8: bgez        $t9, L_8000F5FC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000F5DC: nop
    
            goto L_8000F5FC;
    }
    // 0x8000F5DC: nop

    // 0x8000F5E0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F5E4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000F5E8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000F5EC: nop

    // 0x8000F5F0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8000F5F4: b           L_8000F60C
    // 0x8000F5F8: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
        goto L_8000F60C;
    // 0x8000F5F8: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
L_8000F5FC:
    // 0x8000F5FC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8000F600: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F604: nop

    // 0x8000F608: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
L_8000F60C:
    // 0x8000F60C: b           L_8000F614
    // 0x8000F610: nop

        goto L_8000F614;
    // 0x8000F610: nop

L_8000F614:
    // 0x8000F614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F61C: jr          $ra
    // 0x8000F620: nop

    return;
    // 0x8000F620: nop

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
RECOMP_FUNC void func_8001EE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EE30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001EE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EE38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001EE3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001EE40: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001EE44: nop

    // 0x8001EE48: bltz        $t6, L_8001F098
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001EE4C: nop
    
            goto L_8001F098;
    }
    // 0x8001EE4C: nop

    // 0x8001EE50: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EE54: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EE58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EE5C: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001EE60: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001EE64: nop

    // 0x8001EE68: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001EE6C: beq         $t0, $zero, L_8001EE88
    if (ctx->r8 == 0) {
        // 0x8001EE70: nop
    
            goto L_8001EE88;
    }
    // 0x8001EE70: nop

    // 0x8001EE74: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8001EE78: lw          $t1, -0x4A0C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4A0C);
    // 0x8001EE7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EE80: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001EE84: sw          $t2, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r10;
L_8001EE88:
    // 0x8001EE88: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001EE8C: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001EE90: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001EE94: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001EE98: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001EE9C: nop

    // 0x8001EEA0: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001EEA4: beq         $t6, $zero, L_8001EEC0
    if (ctx->r14 == 0) {
        // 0x8001EEA8: nop
    
            goto L_8001EEC0;
    }
    // 0x8001EEA8: nop

    // 0x8001EEAC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001EEB0: lw          $t7, -0x4A0C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A0C);
    // 0x8001EEB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EEB8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001EEBC: sw          $t8, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r24;
L_8001EEC0:
    // 0x8001EEC0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001EEC4: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001EEC8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001EECC: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001EED0: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001EED4: nop

    // 0x8001EED8: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001EEDC: beq         $t2, $zero, L_8001EEF8
    if (ctx->r10 == 0) {
        // 0x8001EEE0: nop
    
            goto L_8001EEF8;
    }
    // 0x8001EEE0: nop

    // 0x8001EEE4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8001EEE8: lw          $t3, -0x4A0C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4A0C);
    // 0x8001EEEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EEF0: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x8001EEF4: sw          $t4, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r12;
L_8001EEF8:
    // 0x8001EEF8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001EEFC: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001EF00: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001EF04: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001EF08: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001EF0C: nop

    // 0x8001EF10: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001EF14: beq         $t8, $zero, L_8001EF30
    if (ctx->r24 == 0) {
        // 0x8001EF18: nop
    
            goto L_8001EF30;
    }
    // 0x8001EF18: nop

    // 0x8001EF1C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001EF20: lw          $t9, -0x4A0C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4A0C);
    // 0x8001EF24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EF28: addiu       $t0, $t9, -0xA
    ctx->r8 = ADD32(ctx->r25, -0XA);
    // 0x8001EF2C: sw          $t0, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r8;
L_8001EF30:
    // 0x8001EF30: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001EF34: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001EF38: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001EF3C: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001EF40: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001EF44: nop

    // 0x8001EF48: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001EF4C: beq         $t4, $zero, L_8001EF68
    if (ctx->r12 == 0) {
        // 0x8001EF50: nop
    
            goto L_8001EF68;
    }
    // 0x8001EF50: nop

    // 0x8001EF54: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8001EF58: lw          $t5, -0x4A0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4A0C);
    // 0x8001EF5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EF60: addiu       $t6, $t5, 0x64
    ctx->r14 = ADD32(ctx->r13, 0X64);
    // 0x8001EF64: sw          $t6, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r14;
L_8001EF68:
    // 0x8001EF68: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EF6C: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EF70: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EF74: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001EF78: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001EF7C: nop

    // 0x8001EF80: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001EF84: beq         $t0, $zero, L_8001EFA0
    if (ctx->r8 == 0) {
        // 0x8001EF88: nop
    
            goto L_8001EFA0;
    }
    // 0x8001EF88: nop

    // 0x8001EF8C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8001EF90: lw          $t1, -0x4A0C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4A0C);
    // 0x8001EF94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EF98: addiu       $t2, $t1, -0x64
    ctx->r10 = ADD32(ctx->r9, -0X64);
    // 0x8001EF9C: sw          $t2, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r10;
L_8001EFA0:
    // 0x8001EFA0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8001EFA4: lw          $t3, -0x4A0C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4A0C);
    // 0x8001EFA8: nop

    // 0x8001EFAC: bgtz        $t3, L_8001EFC0
    if (SIGNED(ctx->r11) > 0) {
        // 0x8001EFB0: nop
    
            goto L_8001EFC0;
    }
    // 0x8001EFB0: nop

    // 0x8001EFB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001EFB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EFBC: sw          $t4, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r12;
L_8001EFC0:
    // 0x8001EFC0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8001EFC4: lw          $t5, -0x4A0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4A0C);
    // 0x8001EFC8: nop

    // 0x8001EFCC: slti        $at, $t5, 0x201
    ctx->r1 = SIGNED(ctx->r13) < 0X201 ? 1 : 0;
    // 0x8001EFD0: bne         $at, $zero, L_8001EFE4
    if (ctx->r1 != 0) {
        // 0x8001EFD4: nop
    
            goto L_8001EFE4;
    }
    // 0x8001EFD4: nop

    // 0x8001EFD8: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x8001EFDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EFE0: sw          $t6, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r14;
L_8001EFE4:
    // 0x8001EFE4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EFE8: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EFEC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EFF0: lhu         $t9, 0x10F2($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X10F2);
    // 0x8001EFF4: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x8001EFF8: nop

    // 0x8001EFFC: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001F000: beq         $t0, $zero, L_8001F048
    if (ctx->r8 == 0) {
        // 0x8001F004: nop
    
            goto L_8001F048;
    }
    // 0x8001F004: nop

    // 0x8001F008: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F00C: lw          $a0, -0x4A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A0C);
    // 0x8001F010: jal         0x8005F064
    // 0x8001F014: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8001F014: nop

    after_0:
    // 0x8001F018: beq         $v0, $zero, L_8001F038
    if (ctx->r2 == 0) {
        // 0x8001F01C: nop
    
            goto L_8001F038;
    }
    // 0x8001F01C: nop

    // 0x8001F020: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F024: lw          $a0, -0x4A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A0C);
    // 0x8001F028: jal         0x8005F268
    // 0x8001F02C: nop

    func_8005F268(rdram, ctx);
        goto after_1;
    // 0x8001F02C: nop

    after_1:
    // 0x8001F030: b           L_8001F048
    // 0x8001F034: nop

        goto L_8001F048;
    // 0x8001F034: nop

L_8001F038:
    // 0x8001F038: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F03C: lw          $a0, -0x4A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A0C);
    // 0x8001F040: jal         0x8005F0DC
    // 0x8001F044: nop

    func_8005F0DC(rdram, ctx);
        goto after_2;
    // 0x8001F044: nop

    after_2:
L_8001F048:
    // 0x8001F048: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001F04C: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001F050: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F054: lhu         $t3, 0x1042($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1042);
    // 0x8001F058: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001F05C: nop

    // 0x8001F060: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001F064: beq         $t4, $zero, L_8001F098
    if (ctx->r12 == 0) {
        // 0x8001F068: nop
    
            goto L_8001F098;
    }
    // 0x8001F068: nop

    // 0x8001F06C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001F070: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
L_8001F074:
    // 0x8001F074: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F078: jal         0x8005F268
    // 0x8001F07C: nop

    func_8005F268(rdram, ctx);
        goto after_3;
    // 0x8001F07C: nop

    after_3:
    // 0x8001F080: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F084: nop

    // 0x8001F088: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001F08C: slti        $at, $t7, 0x201
    ctx->r1 = SIGNED(ctx->r15) < 0X201 ? 1 : 0;
    // 0x8001F090: bne         $at, $zero, L_8001F074
    if (ctx->r1 != 0) {
        // 0x8001F094: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8001F074;
    }
    // 0x8001F094: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8001F098:
    // 0x8001F098: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8001F09C: lw          $a1, -0x4A0C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4A0C);
    // 0x8001F0A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F0A4: jal         0x8008ECE4
    // 0x8001F0A8: addiu       $a0, $a0, -0x24BC
    ctx->r4 = ADD32(ctx->r4, -0X24BC);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8001F0A8: addiu       $a0, $a0, -0x24BC
    ctx->r4 = ADD32(ctx->r4, -0X24BC);
    after_4:
    // 0x8001F0AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F0B0: lw          $a0, -0x4A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A0C);
    // 0x8001F0B4: jal         0x8005F064
    // 0x8001F0B8: nop

    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x8001F0B8: nop

    after_5:
    // 0x8001F0BC: beq         $v0, $zero, L_8001F0D8
    if (ctx->r2 == 0) {
        // 0x8001F0C0: nop
    
            goto L_8001F0D8;
    }
    // 0x8001F0C0: nop

    // 0x8001F0C4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F0C8: jal         0x8008ECE4
    // 0x8001F0CC: addiu       $a0, $a0, -0x24B0
    ctx->r4 = ADD32(ctx->r4, -0X24B0);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8001F0CC: addiu       $a0, $a0, -0x24B0
    ctx->r4 = ADD32(ctx->r4, -0X24B0);
    after_6:
    // 0x8001F0D0: b           L_8001F0E4
    // 0x8001F0D4: nop

        goto L_8001F0E4;
    // 0x8001F0D4: nop

L_8001F0D8:
    // 0x8001F0D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F0DC: jal         0x8008ECE4
    // 0x8001F0E0: addiu       $a0, $a0, -0x24AC
    ctx->r4 = ADD32(ctx->r4, -0X24AC);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001F0E0: addiu       $a0, $a0, -0x24AC
    ctx->r4 = ADD32(ctx->r4, -0X24AC);
    after_7:
L_8001F0E4:
    // 0x8001F0E4: b           L_8001F0F4
    // 0x8001F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F0F4;
    // 0x8001F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F0EC: b           L_8001F0F4
    // 0x8001F0F0: nop

        goto L_8001F0F4;
    // 0x8001F0F0: nop

L_8001F0F4:
    // 0x8001F0F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F0F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001F0FC: jr          $ra
    // 0x8001F100: nop

    return;
    // 0x8001F100: nop

;}
RECOMP_FUNC void func_8008D45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D45C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008D460: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D464: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008D468: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8008D46C: lwc1        $f4, 0xE8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8008D470: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008D474: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008D478: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8008D47C: nop

    // 0x8008D480: bc1f        L_8008D5D0
    if (!c1cs) {
        // 0x8008D484: nop
    
            goto L_8008D5D0;
    }
    // 0x8008D484: nop

    // 0x8008D488: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008D48C: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008D490: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8008D494: beq         $t7, $zero, L_8008D584
    if (ctx->r15 == 0) {
        // 0x8008D498: sw          $t7, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r15;
            goto L_8008D584;
    }
    // 0x8008D498: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_8008D49C:
    // 0x8008D49C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8008D4A0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8008D4A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008D4A8: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008D4AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008D4B0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8008D4B4: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8008D4B8: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008D4BC: nop

    // 0x8008D4C0: lwc1        $f6, 0xE8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8008D4C4: nop

    // 0x8008D4C8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008D4CC: sub.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d - ctx->f4.d;
    // 0x8008D4D0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8008D4D4: swc1        $f10, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f10.u32l;
    // 0x8008D4D8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8008D4DC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008D4E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008D4E4: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008D4E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008D4EC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008D4F0: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8008D4F4: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008D4F8: nop

    // 0x8008D4FC: lwc1        $f16, 0xF0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x8008D500: nop

    // 0x8008D504: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8008D508: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x8008D50C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8008D510: swc1        $f18, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f18.u32l;
    // 0x8008D514: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008D518: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008D51C: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8008D520: lwc1        $f11, -0xA08($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XA08);
    // 0x8008D524: lwc1        $f10, -0xA04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XA04);
    // 0x8008D528: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8008D52C: nop

    // 0x8008D530: div.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x8008D534: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8008D538: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008D53C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008D540: nop

    // 0x8008D544: sub.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d - ctx->f4.d;
    // 0x8008D548: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x8008D54C: swc1        $f12, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f12.u32l;
    // 0x8008D550: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008D554: nop

    // 0x8008D558: swc1        $f12, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f12.u32l;
    // 0x8008D55C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8008D560: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008D564: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008D568: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8008D56C: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x8008D570: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x8008D574: beq         $at, $zero, L_8008D584
    if (ctx->r1 == 0) {
        // 0x8008D578: sw          $t3, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r11;
            goto L_8008D584;
    }
    // 0x8008D578: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x8008D57C: bne         $t5, $zero, L_8008D49C
    if (ctx->r13 != 0) {
        // 0x8008D580: nop
    
            goto L_8008D49C;
    }
    // 0x8008D580: nop

L_8008D584:
    // 0x8008D584: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D588: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008D58C: nop

    // 0x8008D590: lwc1        $f12, 0xF4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XF4);
    // 0x8008D594: nop

    // 0x8008D598: swc1        $f12, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->f12.u32l;
    // 0x8008D59C: swc1        $f12, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->f12.u32l;
    // 0x8008D5A0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008D5A4: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008D5A8: nop

    // 0x8008D5AC: lwc1        $f8, 0xE8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x8008D5B0: nop

    // 0x8008D5B4: swc1        $f8, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->f8.u32l;
    // 0x8008D5B8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008D5BC: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8008D5C0: nop

    // 0x8008D5C4: lwc1        $f16, 0xF0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8008D5C8: b           L_8008D6F0
    // 0x8008D5CC: swc1        $f16, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f16.u32l;
        goto L_8008D6F0;
    // 0x8008D5CC: swc1        $f16, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f16.u32l;
L_8008D5D0:
    // 0x8008D5D0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008D5D4: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8008D5D8: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8008D5DC: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
L_8008D5E0:
    // 0x8008D5E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008D5E4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008D5E8: nop

    // 0x8008D5EC: swc1        $f10, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f10.u32l;
    // 0x8008D5F0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008D5F4: nop

    // 0x8008D5F8: lwc1        $f6, 0xF0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XF0);
    // 0x8008D5FC: nop

    // 0x8008D600: swc1        $f6, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f6.u32l;
    // 0x8008D604: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8008D608: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8008D60C: lw          $t4, 0xC0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC0);
    // 0x8008D610: nop

    // 0x8008D614: and         $t3, $t4, $at
    ctx->r11 = ctx->r12 & ctx->r1;
    // 0x8008D618: sw          $t3, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r11;
    // 0x8008D61C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8008D620: nop

    // 0x8008D624: lw          $t6, 0xC0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC0);
    // 0x8008D628: nop

    // 0x8008D62C: ori         $t7, $t6, 0x48
    ctx->r15 = ctx->r14 | 0X48;
    // 0x8008D630: sw          $t7, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r15;
    // 0x8008D634: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008D638: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D63C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008D640: nop

    // 0x8008D644: swc1        $f4, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f4.u32l;
    // 0x8008D648: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008D64C: nop

    // 0x8008D650: lwc1        $f18, 0xF8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x8008D654: nop

    // 0x8008D658: swc1        $f18, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f18.u32l;
    // 0x8008D65C: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x8008D660: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008D664: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008D668: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8008D66C: addiu       $t3, $t4, 0x160
    ctx->r11 = ADD32(ctx->r12, 0X160);
    // 0x8008D670: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8008D674: bne         $at, $zero, L_8008D5E0
    if (ctx->r1 != 0) {
        // 0x8008D678: sw          $t1, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r9;
            goto L_8008D5E0;
    }
    // 0x8008D678: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8008D67C: lw          $t2, 0x230($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X230);
    // 0x8008D680: addiu       $at, $zero, -0x811
    ctx->r1 = ADD32(0, -0X811);
    // 0x8008D684: and         $t6, $t2, $at
    ctx->r14 = ctx->r10 & ctx->r1;
    // 0x8008D688: sw          $t6, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r14;
    // 0x8008D68C: lw          $t7, 0x230($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X230);
    // 0x8008D690: nop

    // 0x8008D694: ori         $t5, $t7, 0x48
    ctx->r13 = ctx->r15 | 0X48;
    // 0x8008D698: sw          $t5, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r13;
    // 0x8008D69C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008D6A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008D6A4: nop

    // 0x8008D6A8: swc1        $f8, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->f8.u32l;
    // 0x8008D6AC: lwc1        $f16, 0x268($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X268);
    // 0x8008D6B0: nop

    // 0x8008D6B4: swc1        $f16, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->f16.u32l;
    // 0x8008D6B8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008D6BC: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8008D6C0: nop

    // 0x8008D6C4: lwc1        $f10, 0xE8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8008D6C8: nop

    // 0x8008D6CC: swc1        $f10, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->f10.u32l;
    // 0x8008D6D0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008D6D4: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8008D6D8: nop

    // 0x8008D6DC: lwc1        $f6, 0xF0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x8008D6E0: nop

    // 0x8008D6E4: swc1        $f6, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f6.u32l;
    // 0x8008D6E8: b           L_8008D700
    // 0x8008D6EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008D700;
    // 0x8008D6EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008D6F0:
    // 0x8008D6F0: b           L_8008D700
    // 0x8008D6F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D700;
    // 0x8008D6F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D6F8: b           L_8008D700
    // 0x8008D6FC: nop

        goto L_8008D700;
    // 0x8008D6FC: nop

L_8008D700:
    // 0x8008D700: jr          $ra
    // 0x8008D704: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008D704: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006BD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD98: jal         0x8005F064
    // 0x8006BD9C: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BD9C: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_0:
    // 0x8006BDA0: b           L_8006BDB0
    // 0x8006BDA4: nop

        goto L_8006BDB0;
    // 0x8006BDA4: nop

    // 0x8006BDA8: b           L_8006BDB0
    // 0x8006BDAC: nop

        goto L_8006BDB0;
    // 0x8006BDAC: nop

L_8006BDB0:
    // 0x8006BDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BDB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BDB8: jr          $ra
    // 0x8006BDBC: nop

    return;
    // 0x8006BDBC: nop

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
RECOMP_FUNC void func_80077104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007710C: jal         0x80061488
    // 0x80077110: addiu       $a0, $zero, 0x55C
    ctx->r4 = ADD32(0, 0X55C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077110: addiu       $a0, $zero, 0x55C
    ctx->r4 = ADD32(0, 0X55C);
    after_0:
    // 0x80077114: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077118: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007711C: b           L_8007712C
    // 0x80077120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007712C;
    // 0x80077120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077124: b           L_8007712C
    // 0x80077128: nop

        goto L_8007712C;
    // 0x80077128: nop

L_8007712C:
    // 0x8007712C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077134: jr          $ra
    // 0x80077138: nop

    return;
    // 0x80077138: nop

;}
RECOMP_FUNC void func_80028400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028400: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80028404: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80028408: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002840C: lwc1        $f7, -0x1A40($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1A40);
    // 0x80028410: lwc1        $f6, -0x1A3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1A3C);
    // 0x80028414: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80028418: nop

    // 0x8002841C: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80028420: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80028424: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80028428: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8002842C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80028430: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80028434: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x80028438: bc1f        L_8002844C
    if (!c1cs) {
        // 0x8002843C: nop
    
            goto L_8002844C;
    }
    // 0x8002843C: nop

    // 0x80028440: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80028444: nop

    // 0x80028448: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
L_8002844C:
    // 0x8002844C: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80028450: b           L_80028460
    // 0x80028454: nop

        goto L_80028460;
    // 0x80028454: nop

    // 0x80028458: b           L_80028460
    // 0x8002845C: nop

        goto L_80028460;
    // 0x8002845C: nop

L_80028460:
    // 0x80028460: jr          $ra
    // 0x80028464: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80028464: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800ABB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABB58: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800ABB5C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x800ABB60: slti        $at, $a0, 0xF1
    ctx->r1 = SIGNED(ctx->r4) < 0XF1 ? 1 : 0;
    // 0x800ABB64: bne         $at, $zero, L_800ABB74
    if (ctx->r1 != 0) {
        // 0x800ABB68: nop
    
            goto L_800ABB74;
    }
    // 0x800ABB68: nop

    // 0x800ABB6C: b           L_800ABC28
    // 0x800ABB70: nop

        goto L_800ABC28;
    // 0x800ABB70: nop

L_800ABB74:
    // 0x800ABB74: slti        $at, $a1, 0xF1
    ctx->r1 = SIGNED(ctx->r5) < 0XF1 ? 1 : 0;
    // 0x800ABB78: bne         $at, $zero, L_800ABB88
    if (ctx->r1 != 0) {
        // 0x800ABB7C: nop
    
            goto L_800ABB88;
    }
    // 0x800ABB7C: nop

    // 0x800ABB80: b           L_800ABC28
    // 0x800ABB84: nop

        goto L_800ABC28;
    // 0x800ABB84: nop

L_800ABB88:
    // 0x800ABB88: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x800ABB8C: slti        $at, $t6, 0xF1
    ctx->r1 = SIGNED(ctx->r14) < 0XF1 ? 1 : 0;
    // 0x800ABB90: bne         $at, $zero, L_800ABBA0
    if (ctx->r1 != 0) {
        // 0x800ABB94: nop
    
            goto L_800ABBA0;
    }
    // 0x800ABB94: nop

    // 0x800ABB98: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800ABB9C: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
L_800ABBA0:
    // 0x800ABBA0: blez        $a1, L_800ABC20
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800ABBA4: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_800ABC20;
    }
    // 0x800ABBA4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800ABBA8:
    // 0x800ABBA8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800ABBAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBB0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800ABBB4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800ABBB8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800ABBBC: sh          $a2, -0x4CB8($at)
    MEM_H(-0X4CB8, ctx->r1) = ctx->r6;
    // 0x800ABBC0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800ABBC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBC8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800ABBCC: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800ABBD0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800ABBD4: sh          $a2, -0x4CB6($at)
    MEM_H(-0X4CB6, ctx->r1) = ctx->r6;
    // 0x800ABBD8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800ABBDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBE0: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800ABBE4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800ABBE8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800ABBEC: sh          $a2, -0x4CB4($at)
    MEM_H(-0X4CB4, ctx->r1) = ctx->r6;
    // 0x800ABBF0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800ABBF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBF8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800ABBFC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800ABC00: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800ABC04: sh          $a2, -0x4CB2($at)
    MEM_H(-0X4CB2, ctx->r1) = ctx->r6;
    // 0x800ABC08: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800ABC0C: nop

    // 0x800ABC10: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800ABC14: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800ABC18: bne         $at, $zero, L_800ABBA8
    if (ctx->r1 != 0) {
        // 0x800ABC1C: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800ABBA8;
    }
    // 0x800ABC1C: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_800ABC20:
    // 0x800ABC20: b           L_800ABC28
    // 0x800ABC24: nop

        goto L_800ABC28;
    // 0x800ABC24: nop

L_800ABC28:
    // 0x800ABC28: jr          $ra
    // 0x800ABC2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800ABC2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80067F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067F18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067F1C: nop

    // 0x80067F20: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067F24: nop

    // 0x80067F28: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067F2C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067F30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067F34: beq         $v0, $zero, L_80067F50
    if (ctx->r2 == 0) {
        // 0x80067F38: nop
    
            goto L_80067F50;
    }
    // 0x80067F38: nop

    // 0x80067F3C: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067F40: nop

    // 0x80067F44: slti        $t8, $v0, 0x258
    ctx->r24 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067F48: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067F4C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067F50:
    // 0x80067F50: jr          $ra
    // 0x80067F54: nop

    return;
    // 0x80067F54: nop

    // 0x80067F58: jr          $ra
    // 0x80067F5C: nop

    return;
    // 0x80067F5C: nop

    // 0x80067F60: jr          $ra
    // 0x80067F64: nop

    return;
    // 0x80067F64: nop

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
RECOMP_FUNC void func_800729A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800729A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800729A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800729A8: nop

    // 0x800729AC: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800729B0: nop

    // 0x800729B4: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x800729B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800729BC: jr          $ra
    // 0x800729C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800729C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800729C4: jr          $ra
    // 0x800729C8: nop

    return;
    // 0x800729C8: nop

    // 0x800729CC: jr          $ra
    // 0x800729D0: nop

    return;
    // 0x800729D0: nop

;}
RECOMP_FUNC void func_80067934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067934: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067938: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006793C: nop

    // 0x80067940: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067944: nop

    // 0x80067948: slti        $t7, $v0, 0x96
    ctx->r15 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x8006794C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067950: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067954: beq         $v0, $zero, L_80067970
    if (ctx->r2 == 0) {
        // 0x80067958: nop
    
            goto L_80067970;
    }
    // 0x80067958: nop

    // 0x8006795C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067960: nop

    // 0x80067964: slti        $t8, $v0, 0x96
    ctx->r24 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067968: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006796C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067970:
    // 0x80067970: jr          $ra
    // 0x80067974: nop

    return;
    // 0x80067974: nop

    // 0x80067978: jr          $ra
    // 0x8006797C: nop

    return;
    // 0x8006797C: nop

    // 0x80067980: jr          $ra
    // 0x80067984: nop

    return;
    // 0x80067984: nop

;}
RECOMP_FUNC void __initChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3714: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D3718: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D371C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D3720: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D3724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3728: lbu         $t6, 0x34($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X34);
    // 0x800D372C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D3730: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D3734: blez        $t6, L_800D376C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D3738: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800D376C;
    }
    // 0x800D3738: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D373C: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
L_800D3740:
    // 0x800D3740: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D3748: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800D374C: jal         0x800D2024
    // 0x800D3750: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x800D3750: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_0:
    // 0x800D3754: lbu         $t9, 0x34($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X34);
    // 0x800D3758: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D375C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800D3760: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D3764: bnel        $at, $zero, L_800D3740
    if (ctx->r1 != 0) {
        // 0x800D3768: lw          $t7, 0x60($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X60);
            goto L_800D3740;
    }
    goto skip_0;
    // 0x800D3768: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    skip_0:
L_800D376C:
    // 0x800D376C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D3770: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3774: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3778: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D377C: jr          $ra
    // 0x800D3780: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D3780: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006C0C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C0C8: jal         0x8005F064
    // 0x8006C0CC: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C0CC: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x8006C0D0: b           L_8006C0E0
    // 0x8006C0D4: nop

        goto L_8006C0E0;
    // 0x8006C0D4: nop

    // 0x8006C0D8: b           L_8006C0E0
    // 0x8006C0DC: nop

        goto L_8006C0E0;
    // 0x8006C0DC: nop

L_8006C0E0:
    // 0x8006C0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C0E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C0E8: jr          $ra
    // 0x8006C0EC: nop

    return;
    // 0x8006C0EC: nop

;}
RECOMP_FUNC void func_800765B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800765B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800765BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800765C0: jal         0x8005F064
    // 0x800765C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800765C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x800765C8: b           L_800765D8
    // 0x800765CC: nop

        goto L_800765D8;
    // 0x800765CC: nop

    // 0x800765D0: b           L_800765D8
    // 0x800765D4: nop

        goto L_800765D8;
    // 0x800765D4: nop

L_800765D8:
    // 0x800765D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800765DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800765E0: jr          $ra
    // 0x800765E4: nop

    return;
    // 0x800765E4: nop

;}
RECOMP_FUNC void func_8006E538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E53C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E540: jal         0x80061348
    // 0x8006E544: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E544: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E548: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E54C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E550: beq         $v0, $zero, L_8006E568
    if (ctx->r2 == 0) {
        // 0x8006E554: nop
    
            goto L_8006E568;
    }
    // 0x8006E554: nop

    // 0x8006E558: jal         0x80061348
    // 0x8006E55C: addiu       $a0, $zero, 0x12B
    ctx->r4 = ADD32(0, 0X12B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E55C: addiu       $a0, $zero, 0x12B
    ctx->r4 = ADD32(0, 0X12B);
    after_1:
    // 0x8006E560: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E564: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E568:
    // 0x8006E568: b           L_8006E578
    // 0x8006E56C: nop

        goto L_8006E578;
    // 0x8006E56C: nop

    // 0x8006E570: b           L_8006E578
    // 0x8006E574: nop

        goto L_8006E578;
    // 0x8006E574: nop

L_8006E578:
    // 0x8006E578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E57C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E580: jr          $ra
    // 0x8006E584: nop

    return;
    // 0x8006E584: nop

;}
