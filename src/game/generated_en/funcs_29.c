#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80073B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073B0C: jal         0x80061348
    // 0x80073B10: addiu       $a0, $zero, 0x558
    ctx->r4 = ADD32(0, 0X558);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073B10: addiu       $a0, $zero, 0x558
    ctx->r4 = ADD32(0, 0X558);
    after_0:
    // 0x80073B14: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073B18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073B1C: b           L_80073B2C
    // 0x80073B20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80073B2C;
    // 0x80073B20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073B24: b           L_80073B2C
    // 0x80073B28: nop

        goto L_80073B2C;
    // 0x80073B28: nop

L_80073B2C:
    // 0x80073B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073B34: jr          $ra
    // 0x80073B38: nop

    return;
    // 0x80073B38: nop

;}
RECOMP_FUNC void func_80073B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073B44: jal         0x80061348
    // 0x80073B48: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073B48: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073B4C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073B50: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073B54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073B58: beq         $v0, $zero, L_80073BAC
    if (ctx->r2 == 0) {
        // 0x80073B5C: nop

            goto L_80073BAC;
    }
    // 0x80073B5C: nop

    // 0x80073B60: jal         0x80061348
    // 0x80073B64: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073B64: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073B68: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073B6C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073B70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073B74: beq         $v0, $zero, L_80073BAC
    if (ctx->r2 == 0) {
        // 0x80073B78: nop

            goto L_80073BAC;
    }
    // 0x80073B78: nop

    // 0x80073B7C: jal         0x80061348
    // 0x80073B80: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073B80: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073B84: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073B88: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073B8C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073B90: beq         $v0, $zero, L_80073BAC
    if (ctx->r2 == 0) {
        // 0x80073B94: nop

            goto L_80073BAC;
    }
    // 0x80073B94: nop

    // 0x80073B98: jal         0x80061348
    // 0x80073B9C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073B9C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073BA0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073BA4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073BA8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073BAC:
    // 0x80073BAC: b           L_80073BBC
    // 0x80073BB0: nop

        goto L_80073BBC;
    // 0x80073BB0: nop

    // 0x80073BB4: b           L_80073BBC
    // 0x80073BB8: nop

        goto L_80073BBC;
    // 0x80073BB8: nop

L_80073BBC:
    // 0x80073BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073BC4: jr          $ra
    // 0x80073BC8: nop

    return;
    // 0x80073BC8: nop

;}
RECOMP_FUNC void func_80073BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073BD4: jal         0x80061348
    // 0x80073BD8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073BD8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073BDC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073BE0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073BE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073BE8: beq         $v0, $zero, L_80073C3C
    if (ctx->r2 == 0) {
        // 0x80073BEC: nop

            goto L_80073C3C;
    }
    // 0x80073BEC: nop

    // 0x80073BF0: jal         0x80061348
    // 0x80073BF4: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073BF4: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073BF8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073BFC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073C00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073C04: beq         $v0, $zero, L_80073C3C
    if (ctx->r2 == 0) {
        // 0x80073C08: nop

            goto L_80073C3C;
    }
    // 0x80073C08: nop

    // 0x80073C0C: jal         0x80061348
    // 0x80073C10: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073C10: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073C14: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073C18: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073C1C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073C20: beq         $v0, $zero, L_80073C3C
    if (ctx->r2 == 0) {
        // 0x80073C24: nop

            goto L_80073C3C;
    }
    // 0x80073C24: nop

    // 0x80073C28: jal         0x80061348
    // 0x80073C2C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073C2C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073C30: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073C34: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073C38: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073C3C:
    // 0x80073C3C: b           L_80073C4C
    // 0x80073C40: nop

        goto L_80073C4C;
    // 0x80073C40: nop

    // 0x80073C44: b           L_80073C4C
    // 0x80073C48: nop

        goto L_80073C4C;
    // 0x80073C48: nop

L_80073C4C:
    // 0x80073C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073C50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073C54: jr          $ra
    // 0x80073C58: nop

    return;
    // 0x80073C58: nop

;}
RECOMP_FUNC void func_80073C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073C64: jal         0x80061348
    // 0x80073C68: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073C68: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073C6C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073C70: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073C74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073C78: beq         $v0, $zero, L_80073CCC
    if (ctx->r2 == 0) {
        // 0x80073C7C: nop

            goto L_80073CCC;
    }
    // 0x80073C7C: nop

    // 0x80073C80: jal         0x80061348
    // 0x80073C84: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073C84: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073C88: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073C8C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073C90: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073C94: beq         $v0, $zero, L_80073CCC
    if (ctx->r2 == 0) {
        // 0x80073C98: nop

            goto L_80073CCC;
    }
    // 0x80073C98: nop

    // 0x80073C9C: jal         0x80061348
    // 0x80073CA0: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073CA0: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073CA4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073CA8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073CAC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073CB0: beq         $v0, $zero, L_80073CCC
    if (ctx->r2 == 0) {
        // 0x80073CB4: nop

            goto L_80073CCC;
    }
    // 0x80073CB4: nop

    // 0x80073CB8: jal         0x80061348
    // 0x80073CBC: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073CBC: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073CC0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073CC4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073CC8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073CCC:
    // 0x80073CCC: b           L_80073CDC
    // 0x80073CD0: nop

        goto L_80073CDC;
    // 0x80073CD0: nop

    // 0x80073CD4: b           L_80073CDC
    // 0x80073CD8: nop

        goto L_80073CDC;
    // 0x80073CD8: nop

L_80073CDC:
    // 0x80073CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073CE4: jr          $ra
    // 0x80073CE8: nop

    return;
    // 0x80073CE8: nop

;}
RECOMP_FUNC void func_80073CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073CF4: jal         0x80061348
    // 0x80073CF8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073CF8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073CFC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073D00: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073D04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073D08: beq         $v0, $zero, L_80073D5C
    if (ctx->r2 == 0) {
        // 0x80073D0C: nop

            goto L_80073D5C;
    }
    // 0x80073D0C: nop

    // 0x80073D10: jal         0x80061348
    // 0x80073D14: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073D14: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073D18: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073D1C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073D20: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073D24: beq         $v0, $zero, L_80073D5C
    if (ctx->r2 == 0) {
        // 0x80073D28: nop

            goto L_80073D5C;
    }
    // 0x80073D28: nop

    // 0x80073D2C: jal         0x80061348
    // 0x80073D30: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073D30: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073D34: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073D38: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073D3C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073D40: beq         $v0, $zero, L_80073D5C
    if (ctx->r2 == 0) {
        // 0x80073D44: nop

            goto L_80073D5C;
    }
    // 0x80073D44: nop

    // 0x80073D48: jal         0x80061348
    // 0x80073D4C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073D4C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073D50: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073D54: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073D58: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073D5C:
    // 0x80073D5C: b           L_80073D6C
    // 0x80073D60: nop

        goto L_80073D6C;
    // 0x80073D60: nop

    // 0x80073D64: b           L_80073D6C
    // 0x80073D68: nop

        goto L_80073D6C;
    // 0x80073D68: nop

L_80073D6C:
    // 0x80073D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073D74: jr          $ra
    // 0x80073D78: nop

    return;
    // 0x80073D78: nop

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
RECOMP_FUNC void func_80073DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073DEC: jal         0x80061348
    // 0x80073DF0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073DF0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073DF4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073DF8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073DFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073E00: beq         $v0, $zero, L_80073E54
    if (ctx->r2 == 0) {
        // 0x80073E04: nop

            goto L_80073E54;
    }
    // 0x80073E04: nop

    // 0x80073E08: jal         0x80061348
    // 0x80073E0C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073E0C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073E10: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073E14: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073E18: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073E1C: beq         $v0, $zero, L_80073E54
    if (ctx->r2 == 0) {
        // 0x80073E20: nop

            goto L_80073E54;
    }
    // 0x80073E20: nop

    // 0x80073E24: jal         0x80061348
    // 0x80073E28: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073E28: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073E2C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073E30: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073E34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073E38: beq         $v0, $zero, L_80073E54
    if (ctx->r2 == 0) {
        // 0x80073E3C: nop

            goto L_80073E54;
    }
    // 0x80073E3C: nop

    // 0x80073E40: jal         0x80061348
    // 0x80073E44: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073E44: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073E48: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073E4C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073E50: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073E54:
    // 0x80073E54: b           L_80073E64
    // 0x80073E58: nop

        goto L_80073E64;
    // 0x80073E58: nop

    // 0x80073E5C: b           L_80073E64
    // 0x80073E60: nop

        goto L_80073E64;
    // 0x80073E60: nop

L_80073E64:
    // 0x80073E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073E6C: jr          $ra
    // 0x80073E70: nop

    return;
    // 0x80073E70: nop

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
RECOMP_FUNC void func_80073F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073F0C: jal         0x80061348
    // 0x80073F10: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073F10: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073F14: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073F18: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073F1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073F20: beq         $v0, $zero, L_80073F74
    if (ctx->r2 == 0) {
        // 0x80073F24: nop

            goto L_80073F74;
    }
    // 0x80073F24: nop

    // 0x80073F28: jal         0x80061348
    // 0x80073F2C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073F2C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073F30: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073F34: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073F38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073F3C: beq         $v0, $zero, L_80073F74
    if (ctx->r2 == 0) {
        // 0x80073F40: nop

            goto L_80073F74;
    }
    // 0x80073F40: nop

    // 0x80073F44: jal         0x80061348
    // 0x80073F48: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073F48: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073F4C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073F50: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073F54: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073F58: beq         $v0, $zero, L_80073F74
    if (ctx->r2 == 0) {
        // 0x80073F5C: nop

            goto L_80073F74;
    }
    // 0x80073F5C: nop

    // 0x80073F60: jal         0x80061348
    // 0x80073F64: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073F64: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073F68: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073F6C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073F70: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073F74:
    // 0x80073F74: b           L_80073F84
    // 0x80073F78: nop

        goto L_80073F84;
    // 0x80073F78: nop

    // 0x80073F7C: b           L_80073F84
    // 0x80073F80: nop

        goto L_80073F84;
    // 0x80073F80: nop

L_80073F84:
    // 0x80073F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073F88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073F8C: jr          $ra
    // 0x80073F90: nop

    return;
    // 0x80073F90: nop

;}
RECOMP_FUNC void func_80073F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073F94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073F98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073F9C: jal         0x80061348
    // 0x80073FA0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073FA0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073FA4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073FA8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073FAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073FB0: beq         $v0, $zero, L_80074004
    if (ctx->r2 == 0) {
        // 0x80073FB4: nop

            goto L_80074004;
    }
    // 0x80073FB4: nop

    // 0x80073FB8: jal         0x80061348
    // 0x80073FBC: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073FBC: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073FC0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073FC4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073FC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073FCC: beq         $v0, $zero, L_80074004
    if (ctx->r2 == 0) {
        // 0x80073FD0: nop

            goto L_80074004;
    }
    // 0x80073FD0: nop

    // 0x80073FD4: jal         0x80061348
    // 0x80073FD8: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073FD8: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073FDC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073FE0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073FE4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073FE8: beq         $v0, $zero, L_80074004
    if (ctx->r2 == 0) {
        // 0x80073FEC: nop

            goto L_80074004;
    }
    // 0x80073FEC: nop

    // 0x80073FF0: jal         0x80061348
    // 0x80073FF4: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073FF4: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073FF8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073FFC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074000: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074004:
    // 0x80074004: b           L_80074014
    // 0x80074008: nop

        goto L_80074014;
    // 0x80074008: nop

    // 0x8007400C: b           L_80074014
    // 0x80074010: nop

        goto L_80074014;
    // 0x80074010: nop

L_80074014:
    // 0x80074014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007401C: jr          $ra
    // 0x80074020: nop

    return;
    // 0x80074020: nop

;}
RECOMP_FUNC void func_80074024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007402C: jal         0x80061348
    // 0x80074030: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074030: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x80074034: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074038: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007403C: b           L_8007404C
    // 0x80074040: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007404C;
    // 0x80074040: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074044: b           L_8007404C
    // 0x80074048: nop

        goto L_8007404C;
    // 0x80074048: nop

L_8007404C:
    // 0x8007404C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074054: jr          $ra
    // 0x80074058: nop

    return;
    // 0x80074058: nop

;}
RECOMP_FUNC void func_8007405C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007405C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074064: jal         0x80061348
    // 0x80074068: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074068: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x8007406C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074070: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074074: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074078: beq         $v0, $zero, L_80074094
    if (ctx->r2 == 0) {
        // 0x8007407C: nop

            goto L_80074094;
    }
    // 0x8007407C: nop

    // 0x80074080: jal         0x80061348
    // 0x80074084: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074084: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074088: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007408C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074090: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074094:
    // 0x80074094: b           L_800740A4
    // 0x80074098: nop

        goto L_800740A4;
    // 0x80074098: nop

    // 0x8007409C: b           L_800740A4
    // 0x800740A0: nop

        goto L_800740A4;
    // 0x800740A0: nop

L_800740A4:
    // 0x800740A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800740A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800740AC: jr          $ra
    // 0x800740B0: nop

    return;
    // 0x800740B0: nop

;}
RECOMP_FUNC void func_800740B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800740B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800740B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800740BC: jal         0x80061348
    // 0x800740C0: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800740C0: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x800740C4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800740C8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800740CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800740D0: beq         $v0, $zero, L_800740EC
    if (ctx->r2 == 0) {
        // 0x800740D4: nop

            goto L_800740EC;
    }
    // 0x800740D4: nop

    // 0x800740D8: jal         0x80061348
    // 0x800740DC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800740DC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x800740E0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800740E4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800740E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800740EC:
    // 0x800740EC: b           L_800740FC
    // 0x800740F0: nop

        goto L_800740FC;
    // 0x800740F0: nop

    // 0x800740F4: b           L_800740FC
    // 0x800740F8: nop

        goto L_800740FC;
    // 0x800740F8: nop

L_800740FC:
    // 0x800740FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074104: jr          $ra
    // 0x80074108: nop

    return;
    // 0x80074108: nop

;}
RECOMP_FUNC void func_8007410C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007410C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074114: jal         0x80061348
    // 0x80074118: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074118: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x8007411C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074120: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074124: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074128: beq         $v0, $zero, L_80074144
    if (ctx->r2 == 0) {
        // 0x8007412C: nop

            goto L_80074144;
    }
    // 0x8007412C: nop

    // 0x80074130: jal         0x80061348
    // 0x80074134: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074134: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074138: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007413C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074140: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074144:
    // 0x80074144: b           L_80074154
    // 0x80074148: nop

        goto L_80074154;
    // 0x80074148: nop

    // 0x8007414C: b           L_80074154
    // 0x80074150: nop

        goto L_80074154;
    // 0x80074150: nop

L_80074154:
    // 0x80074154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007415C: jr          $ra
    // 0x80074160: nop

    return;
    // 0x80074160: nop

;}
RECOMP_FUNC void func_80074164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007416C: jal         0x80061348
    // 0x80074170: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074170: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x80074174: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074178: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007417C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074180: beq         $v0, $zero, L_8007419C
    if (ctx->r2 == 0) {
        // 0x80074184: nop

            goto L_8007419C;
    }
    // 0x80074184: nop

    // 0x80074188: jal         0x80061348
    // 0x8007418C: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007418C: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074190: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074194: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074198: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8007419C:
    // 0x8007419C: b           L_800741AC
    // 0x800741A0: nop

        goto L_800741AC;
    // 0x800741A0: nop

    // 0x800741A4: b           L_800741AC
    // 0x800741A8: nop

        goto L_800741AC;
    // 0x800741A8: nop

L_800741AC:
    // 0x800741AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800741B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800741B4: jr          $ra
    // 0x800741B8: nop

    return;
    // 0x800741B8: nop

;}
RECOMP_FUNC void func_800741BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800741BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800741C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800741C4: jal         0x80061348
    // 0x800741C8: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800741C8: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_0:
    // 0x800741CC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800741D0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800741D4: b           L_800741E4
    // 0x800741D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800741E4;
    // 0x800741D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800741DC: b           L_800741E4
    // 0x800741E0: nop

        goto L_800741E4;
    // 0x800741E0: nop

L_800741E4:
    // 0x800741E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800741E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800741EC: jr          $ra
    // 0x800741F0: nop

    return;
    // 0x800741F0: nop

;}
RECOMP_FUNC void func_800741F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800741F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800741F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800741FC: jal         0x80061348
    // 0x80074200: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074200: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x80074204: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074208: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007420C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074210: beq         $v0, $zero, L_8007422C
    if (ctx->r2 == 0) {
        // 0x80074214: nop

            goto L_8007422C;
    }
    // 0x80074214: nop

    // 0x80074218: jal         0x80061348
    // 0x8007421C: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007421C: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074220: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074224: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074228: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8007422C:
    // 0x8007422C: b           L_8007423C
    // 0x80074230: nop

        goto L_8007423C;
    // 0x80074230: nop

    // 0x80074234: b           L_8007423C
    // 0x80074238: nop

        goto L_8007423C;
    // 0x80074238: nop

L_8007423C:
    // 0x8007423C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074244: jr          $ra
    // 0x80074248: nop

    return;
    // 0x80074248: nop

;}
RECOMP_FUNC void func_8007424C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007424C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074254: jal         0x80061348
    // 0x80074258: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074258: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x8007425C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074260: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074264: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074268: beq         $v0, $zero, L_80074284
    if (ctx->r2 == 0) {
        // 0x8007426C: nop

            goto L_80074284;
    }
    // 0x8007426C: nop

    // 0x80074270: jal         0x80061348
    // 0x80074274: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074274: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074278: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007427C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074280: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074284:
    // 0x80074284: b           L_80074294
    // 0x80074288: nop

        goto L_80074294;
    // 0x80074288: nop

    // 0x8007428C: b           L_80074294
    // 0x80074290: nop

        goto L_80074294;
    // 0x80074290: nop

L_80074294:
    // 0x80074294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007429C: jr          $ra
    // 0x800742A0: nop

    return;
    // 0x800742A0: nop

;}
RECOMP_FUNC void func_800742A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800742A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800742A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800742AC: jal         0x80061348
    // 0x800742B0: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800742B0: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x800742B4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800742B8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800742BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800742C0: beq         $v0, $zero, L_800742DC
    if (ctx->r2 == 0) {
        // 0x800742C4: nop

            goto L_800742DC;
    }
    // 0x800742C4: nop

    // 0x800742C8: jal         0x80061348
    // 0x800742CC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800742CC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x800742D0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800742D4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800742D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800742DC:
    // 0x800742DC: b           L_800742EC
    // 0x800742E0: nop

        goto L_800742EC;
    // 0x800742E0: nop

    // 0x800742E4: b           L_800742EC
    // 0x800742E8: nop

        goto L_800742EC;
    // 0x800742E8: nop

L_800742EC:
    // 0x800742EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800742F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800742F4: jr          $ra
    // 0x800742F8: nop

    return;
    // 0x800742F8: nop

;}
RECOMP_FUNC void func_800742FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800742FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074304: jal         0x80061348
    // 0x80074308: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074308: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x8007430C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074310: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074314: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074318: beq         $v0, $zero, L_80074334
    if (ctx->r2 == 0) {
        // 0x8007431C: nop

            goto L_80074334;
    }
    // 0x8007431C: nop

    // 0x80074320: jal         0x80061348
    // 0x80074324: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074324: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074328: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007432C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074330: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074334:
    // 0x80074334: b           L_80074344
    // 0x80074338: nop

        goto L_80074344;
    // 0x80074338: nop

    // 0x8007433C: b           L_80074344
    // 0x80074340: nop

        goto L_80074344;
    // 0x80074340: nop

L_80074344:
    // 0x80074344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007434C: jr          $ra
    // 0x80074350: nop

    return;
    // 0x80074350: nop

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
RECOMP_FUNC void func_800743E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800743E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800743E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800743EC: jal         0x80061348
    // 0x800743F0: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800743F0: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x800743F4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800743F8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800743FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074400: beq         $v0, $zero, L_80074454
    if (ctx->r2 == 0) {
        // 0x80074404: nop

            goto L_80074454;
    }
    // 0x80074404: nop

    // 0x80074408: jal         0x80061348
    // 0x8007440C: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007440C: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074410: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074414: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074418: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007441C: beq         $v0, $zero, L_80074454
    if (ctx->r2 == 0) {
        // 0x80074420: nop

            goto L_80074454;
    }
    // 0x80074420: nop

    // 0x80074424: jal         0x80061348
    // 0x80074428: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074428: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x8007442C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074430: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074434: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074438: beq         $v0, $zero, L_80074454
    if (ctx->r2 == 0) {
        // 0x8007443C: nop

            goto L_80074454;
    }
    // 0x8007443C: nop

    // 0x80074440: jal         0x80061348
    // 0x80074444: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074444: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074448: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007444C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074450: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074454:
    // 0x80074454: b           L_80074464
    // 0x80074458: nop

        goto L_80074464;
    // 0x80074458: nop

    // 0x8007445C: b           L_80074464
    // 0x80074460: nop

        goto L_80074464;
    // 0x80074460: nop

L_80074464:
    // 0x80074464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007446C: jr          $ra
    // 0x80074470: nop

    return;
    // 0x80074470: nop

;}
RECOMP_FUNC void func_80074474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074474: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074478: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007447C: nop

    // 0x80074480: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80074484: nop

    // 0x80074488: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007448C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80074490: jr          $ra
    // 0x80074494: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80074494: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074498: jr          $ra
    // 0x8007449C: nop

    return;
    // 0x8007449C: nop

    // 0x800744A0: jr          $ra
    // 0x800744A4: nop

    return;
    // 0x800744A4: nop

;}
RECOMP_FUNC void func_800744A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800744A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800744AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800744B0: nop

    // 0x800744B4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800744B8: nop

    // 0x800744BC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800744C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800744C4: jr          $ra
    // 0x800744C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800744C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800744CC: jr          $ra
    // 0x800744D0: nop

    return;
    // 0x800744D0: nop

    // 0x800744D4: jr          $ra
    // 0x800744D8: nop

    return;
    // 0x800744D8: nop

;}
RECOMP_FUNC void func_800744DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800744DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800744E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800744E4: jal         0x80061348
    // 0x800744E8: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800744E8: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x800744EC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800744F0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800744F4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800744F8: beq         $v0, $zero, L_8007454C
    if (ctx->r2 == 0) {
        // 0x800744FC: nop

            goto L_8007454C;
    }
    // 0x800744FC: nop

    // 0x80074500: jal         0x80061348
    // 0x80074504: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074504: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074508: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007450C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074510: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074514: beq         $v0, $zero, L_8007454C
    if (ctx->r2 == 0) {
        // 0x80074518: nop

            goto L_8007454C;
    }
    // 0x80074518: nop

    // 0x8007451C: jal         0x80061348
    // 0x80074520: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074520: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x80074524: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074528: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007452C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074530: beq         $v0, $zero, L_8007454C
    if (ctx->r2 == 0) {
        // 0x80074534: nop

            goto L_8007454C;
    }
    // 0x80074534: nop

    // 0x80074538: jal         0x80061348
    // 0x8007453C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007453C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074540: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074544: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074548: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007454C:
    // 0x8007454C: b           L_8007455C
    // 0x80074550: nop

        goto L_8007455C;
    // 0x80074550: nop

    // 0x80074554: b           L_8007455C
    // 0x80074558: nop

        goto L_8007455C;
    // 0x80074558: nop

L_8007455C:
    // 0x8007455C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074564: jr          $ra
    // 0x80074568: nop

    return;
    // 0x80074568: nop

;}
RECOMP_FUNC void func_8007456C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007456C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074574: jal         0x80061348
    // 0x80074578: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074578: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x8007457C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074580: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074584: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074588: beq         $v0, $zero, L_800745DC
    if (ctx->r2 == 0) {
        // 0x8007458C: nop

            goto L_800745DC;
    }
    // 0x8007458C: nop

    // 0x80074590: jal         0x80061348
    // 0x80074594: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074594: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074598: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007459C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800745A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800745A4: beq         $v0, $zero, L_800745DC
    if (ctx->r2 == 0) {
        // 0x800745A8: nop

            goto L_800745DC;
    }
    // 0x800745A8: nop

    // 0x800745AC: jal         0x80061348
    // 0x800745B0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800745B0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x800745B4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800745B8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800745BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800745C0: beq         $v0, $zero, L_800745DC
    if (ctx->r2 == 0) {
        // 0x800745C4: nop

            goto L_800745DC;
    }
    // 0x800745C4: nop

    // 0x800745C8: jal         0x80061348
    // 0x800745CC: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800745CC: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x800745D0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800745D4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800745D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800745DC:
    // 0x800745DC: b           L_800745EC
    // 0x800745E0: nop

        goto L_800745EC;
    // 0x800745E0: nop

    // 0x800745E4: b           L_800745EC
    // 0x800745E8: nop

        goto L_800745EC;
    // 0x800745E8: nop

L_800745EC:
    // 0x800745EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800745F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800745F4: jr          $ra
    // 0x800745F8: nop

    return;
    // 0x800745F8: nop

;}
RECOMP_FUNC void func_800745FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800745FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074604: jal         0x80061348
    // 0x80074608: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074608: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x8007460C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074610: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074614: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074618: beq         $v0, $zero, L_8007466C
    if (ctx->r2 == 0) {
        // 0x8007461C: nop

            goto L_8007466C;
    }
    // 0x8007461C: nop

    // 0x80074620: jal         0x80061348
    // 0x80074624: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074624: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074628: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007462C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074634: beq         $v0, $zero, L_8007466C
    if (ctx->r2 == 0) {
        // 0x80074638: nop

            goto L_8007466C;
    }
    // 0x80074638: nop

    // 0x8007463C: jal         0x80061348
    // 0x80074640: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074640: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x80074644: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074648: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007464C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074650: beq         $v0, $zero, L_8007466C
    if (ctx->r2 == 0) {
        // 0x80074654: nop

            goto L_8007466C;
    }
    // 0x80074654: nop

    // 0x80074658: jal         0x80061348
    // 0x8007465C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007465C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074660: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074664: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074668: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007466C:
    // 0x8007466C: b           L_8007467C
    // 0x80074670: nop

        goto L_8007467C;
    // 0x80074670: nop

    // 0x80074674: b           L_8007467C
    // 0x80074678: nop

        goto L_8007467C;
    // 0x80074678: nop

L_8007467C:
    // 0x8007467C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074684: jr          $ra
    // 0x80074688: nop

    return;
    // 0x80074688: nop

;}
RECOMP_FUNC void func_8007468C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007468C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074694: jal         0x80061348
    // 0x80074698: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074698: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x8007469C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800746A0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800746A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800746A8: beq         $v0, $zero, L_800746FC
    if (ctx->r2 == 0) {
        // 0x800746AC: nop

            goto L_800746FC;
    }
    // 0x800746AC: nop

    // 0x800746B0: jal         0x80061348
    // 0x800746B4: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800746B4: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x800746B8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800746BC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800746C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800746C4: beq         $v0, $zero, L_800746FC
    if (ctx->r2 == 0) {
        // 0x800746C8: nop

            goto L_800746FC;
    }
    // 0x800746C8: nop

    // 0x800746CC: jal         0x80061348
    // 0x800746D0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800746D0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x800746D4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800746D8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800746DC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800746E0: beq         $v0, $zero, L_800746FC
    if (ctx->r2 == 0) {
        // 0x800746E4: nop

            goto L_800746FC;
    }
    // 0x800746E4: nop

    // 0x800746E8: jal         0x80061348
    // 0x800746EC: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800746EC: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x800746F0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800746F4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800746F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800746FC:
    // 0x800746FC: b           L_8007470C
    // 0x80074700: nop

        goto L_8007470C;
    // 0x80074700: nop

    // 0x80074704: b           L_8007470C
    // 0x80074708: nop

        goto L_8007470C;
    // 0x80074708: nop

L_8007470C:
    // 0x8007470C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074714: jr          $ra
    // 0x80074718: nop

    return;
    // 0x80074718: nop

;}
RECOMP_FUNC void func_8007471C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007471C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074724: jal         0x80061348
    // 0x80074728: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074728: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x8007472C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074730: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074734: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074738: beq         $v0, $zero, L_8007478C
    if (ctx->r2 == 0) {
        // 0x8007473C: nop

            goto L_8007478C;
    }
    // 0x8007473C: nop

    // 0x80074740: jal         0x80061348
    // 0x80074744: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074744: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074748: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007474C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074754: beq         $v0, $zero, L_8007478C
    if (ctx->r2 == 0) {
        // 0x80074758: nop

            goto L_8007478C;
    }
    // 0x80074758: nop

    // 0x8007475C: jal         0x80061348
    // 0x80074760: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074760: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x80074764: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074768: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007476C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074770: beq         $v0, $zero, L_8007478C
    if (ctx->r2 == 0) {
        // 0x80074774: nop

            goto L_8007478C;
    }
    // 0x80074774: nop

    // 0x80074778: jal         0x80061348
    // 0x8007477C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007477C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074780: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074784: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074788: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007478C:
    // 0x8007478C: b           L_8007479C
    // 0x80074790: nop

        goto L_8007479C;
    // 0x80074790: nop

    // 0x80074794: b           L_8007479C
    // 0x80074798: nop

        goto L_8007479C;
    // 0x80074798: nop

L_8007479C:
    // 0x8007479C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800747A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800747A4: jr          $ra
    // 0x800747A8: nop

    return;
    // 0x800747A8: nop

;}
RECOMP_FUNC void func_800747AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800747AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800747B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800747B4: jal         0x80061348
    // 0x800747B8: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800747B8: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x800747BC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800747C0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800747C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800747C8: beq         $v0, $zero, L_8007481C
    if (ctx->r2 == 0) {
        // 0x800747CC: nop

            goto L_8007481C;
    }
    // 0x800747CC: nop

    // 0x800747D0: jal         0x80061348
    // 0x800747D4: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800747D4: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x800747D8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800747DC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800747E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800747E4: beq         $v0, $zero, L_8007481C
    if (ctx->r2 == 0) {
        // 0x800747E8: nop

            goto L_8007481C;
    }
    // 0x800747E8: nop

    // 0x800747EC: jal         0x80061348
    // 0x800747F0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800747F0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x800747F4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800747F8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800747FC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074800: beq         $v0, $zero, L_8007481C
    if (ctx->r2 == 0) {
        // 0x80074804: nop

            goto L_8007481C;
    }
    // 0x80074804: nop

    // 0x80074808: jal         0x80061348
    // 0x8007480C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007480C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074810: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074814: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074818: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007481C:
    // 0x8007481C: b           L_8007482C
    // 0x80074820: nop

        goto L_8007482C;
    // 0x80074820: nop

    // 0x80074824: b           L_8007482C
    // 0x80074828: nop

        goto L_8007482C;
    // 0x80074828: nop

L_8007482C:
    // 0x8007482C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074834: jr          $ra
    // 0x80074838: nop

    return;
    // 0x80074838: nop

;}
RECOMP_FUNC void func_8007483C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007483C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074844: jal         0x80061348
    // 0x80074848: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074848: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x8007484C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074850: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074854: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074858: beq         $v0, $zero, L_800748AC
    if (ctx->r2 == 0) {
        // 0x8007485C: nop

            goto L_800748AC;
    }
    // 0x8007485C: nop

    // 0x80074860: jal         0x80061348
    // 0x80074864: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074864: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074868: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007486C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074870: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074874: beq         $v0, $zero, L_800748AC
    if (ctx->r2 == 0) {
        // 0x80074878: nop

            goto L_800748AC;
    }
    // 0x80074878: nop

    // 0x8007487C: jal         0x80061348
    // 0x80074880: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074880: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074884: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074888: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007488C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074890: beq         $v0, $zero, L_800748AC
    if (ctx->r2 == 0) {
        // 0x80074894: nop

            goto L_800748AC;
    }
    // 0x80074894: nop

    // 0x80074898: jal         0x80061348
    // 0x8007489C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007489C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x800748A0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800748A4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800748A8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800748AC:
    // 0x800748AC: b           L_800748BC
    // 0x800748B0: nop

        goto L_800748BC;
    // 0x800748B0: nop

    // 0x800748B4: b           L_800748BC
    // 0x800748B8: nop

        goto L_800748BC;
    // 0x800748B8: nop

L_800748BC:
    // 0x800748BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800748C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800748C4: jr          $ra
    // 0x800748C8: nop

    return;
    // 0x800748C8: nop

;}
RECOMP_FUNC void func_800748CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800748CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800748D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800748D4: jal         0x80061348
    // 0x800748D8: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800748D8: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x800748DC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800748E0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800748E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800748E8: beq         $v0, $zero, L_8007493C
    if (ctx->r2 == 0) {
        // 0x800748EC: nop

            goto L_8007493C;
    }
    // 0x800748EC: nop

    // 0x800748F0: jal         0x80061348
    // 0x800748F4: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800748F4: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x800748F8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800748FC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074900: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074904: beq         $v0, $zero, L_8007493C
    if (ctx->r2 == 0) {
        // 0x80074908: nop

            goto L_8007493C;
    }
    // 0x80074908: nop

    // 0x8007490C: jal         0x80061348
    // 0x80074910: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074910: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074914: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074918: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007491C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074920: beq         $v0, $zero, L_8007493C
    if (ctx->r2 == 0) {
        // 0x80074924: nop

            goto L_8007493C;
    }
    // 0x80074924: nop

    // 0x80074928: jal         0x80061348
    // 0x8007492C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007492C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074930: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074934: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074938: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007493C:
    // 0x8007493C: b           L_8007494C
    // 0x80074940: nop

        goto L_8007494C;
    // 0x80074940: nop

    // 0x80074944: b           L_8007494C
    // 0x80074948: nop

        goto L_8007494C;
    // 0x80074948: nop

L_8007494C:
    // 0x8007494C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074954: jr          $ra
    // 0x80074958: nop

    return;
    // 0x80074958: nop

;}
RECOMP_FUNC void func_8007495C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007495C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074964: jal         0x80061348
    // 0x80074968: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074968: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x8007496C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074970: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074974: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074978: beq         $v0, $zero, L_800749CC
    if (ctx->r2 == 0) {
        // 0x8007497C: nop

            goto L_800749CC;
    }
    // 0x8007497C: nop

    // 0x80074980: jal         0x80061348
    // 0x80074984: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074984: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074988: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007498C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074990: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074994: beq         $v0, $zero, L_800749CC
    if (ctx->r2 == 0) {
        // 0x80074998: nop

            goto L_800749CC;
    }
    // 0x80074998: nop

    // 0x8007499C: jal         0x80061348
    // 0x800749A0: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800749A0: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x800749A4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800749A8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800749AC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800749B0: beq         $v0, $zero, L_800749CC
    if (ctx->r2 == 0) {
        // 0x800749B4: nop

            goto L_800749CC;
    }
    // 0x800749B4: nop

    // 0x800749B8: jal         0x80061348
    // 0x800749BC: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800749BC: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x800749C0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800749C4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800749C8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800749CC:
    // 0x800749CC: b           L_800749DC
    // 0x800749D0: nop

        goto L_800749DC;
    // 0x800749D0: nop

    // 0x800749D4: b           L_800749DC
    // 0x800749D8: nop

        goto L_800749DC;
    // 0x800749D8: nop

L_800749DC:
    // 0x800749DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800749E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800749E4: jr          $ra
    // 0x800749E8: nop

    return;
    // 0x800749E8: nop

;}
RECOMP_FUNC void func_800749EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800749EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800749F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800749F4: jal         0x80061348
    // 0x800749F8: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800749F8: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x800749FC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074A00: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074A04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074A08: beq         $v0, $zero, L_80074A5C
    if (ctx->r2 == 0) {
        // 0x80074A0C: nop

            goto L_80074A5C;
    }
    // 0x80074A0C: nop

    // 0x80074A10: jal         0x80061348
    // 0x80074A14: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074A14: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074A18: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074A1C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074A20: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074A24: beq         $v0, $zero, L_80074A5C
    if (ctx->r2 == 0) {
        // 0x80074A28: nop

            goto L_80074A5C;
    }
    // 0x80074A28: nop

    // 0x80074A2C: jal         0x80061348
    // 0x80074A30: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074A30: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074A34: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074A38: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074A3C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074A40: beq         $v0, $zero, L_80074A5C
    if (ctx->r2 == 0) {
        // 0x80074A44: nop

            goto L_80074A5C;
    }
    // 0x80074A44: nop

    // 0x80074A48: jal         0x80061348
    // 0x80074A4C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074A4C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074A50: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074A54: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074A58: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074A5C:
    // 0x80074A5C: b           L_80074A6C
    // 0x80074A60: nop

        goto L_80074A6C;
    // 0x80074A60: nop

    // 0x80074A64: b           L_80074A6C
    // 0x80074A68: nop

        goto L_80074A6C;
    // 0x80074A68: nop

L_80074A6C:
    // 0x80074A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074A74: jr          $ra
    // 0x80074A78: nop

    return;
    // 0x80074A78: nop

;}
RECOMP_FUNC void func_80074A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074A7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074A80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80074A84: nop

    // 0x80074A88: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x80074A8C: nop

    // 0x80074A90: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80074A94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80074A98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074A9C: bne         $v0, $zero, L_80074AB8
    if (ctx->r2 != 0) {
        // 0x80074AA0: nop

            goto L_80074AB8;
    }
    // 0x80074AA0: nop

    // 0x80074AA4: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x80074AA8: nop

    // 0x80074AAC: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80074AB0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80074AB4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80074AB8:
    // 0x80074AB8: jr          $ra
    // 0x80074ABC: nop

    return;
    // 0x80074ABC: nop

    // 0x80074AC0: jr          $ra
    // 0x80074AC4: nop

    return;
    // 0x80074AC4: nop

    // 0x80074AC8: jr          $ra
    // 0x80074ACC: nop

    return;
    // 0x80074ACC: nop

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
RECOMP_FUNC void func_80074B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074B10: jal         0x80061348
    // 0x80074B14: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074B14: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x80074B18: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074B1C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074B20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074B24: beq         $v0, $zero, L_80074B78
    if (ctx->r2 == 0) {
        // 0x80074B28: nop

            goto L_80074B78;
    }
    // 0x80074B28: nop

    // 0x80074B2C: jal         0x80061348
    // 0x80074B30: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074B30: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074B34: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074B38: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074B3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074B40: beq         $v0, $zero, L_80074B78
    if (ctx->r2 == 0) {
        // 0x80074B44: nop

            goto L_80074B78;
    }
    // 0x80074B44: nop

    // 0x80074B48: jal         0x80061348
    // 0x80074B4C: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074B4C: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074B50: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074B54: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074B58: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074B5C: beq         $v0, $zero, L_80074B78
    if (ctx->r2 == 0) {
        // 0x80074B60: nop

            goto L_80074B78;
    }
    // 0x80074B60: nop

    // 0x80074B64: jal         0x80061348
    // 0x80074B68: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074B68: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074B6C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074B70: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074B74: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074B78:
    // 0x80074B78: b           L_80074B88
    // 0x80074B7C: nop

        goto L_80074B88;
    // 0x80074B7C: nop

    // 0x80074B80: b           L_80074B88
    // 0x80074B84: nop

        goto L_80074B88;
    // 0x80074B84: nop

L_80074B88:
    // 0x80074B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074B90: jr          $ra
    // 0x80074B94: nop

    return;
    // 0x80074B94: nop

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
RECOMP_FUNC void func_80074C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074C30: jal         0x80061348
    // 0x80074C34: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074C34: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x80074C38: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074C3C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074C40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074C44: beq         $v0, $zero, L_80074C98
    if (ctx->r2 == 0) {
        // 0x80074C48: nop

            goto L_80074C98;
    }
    // 0x80074C48: nop

    // 0x80074C4C: jal         0x80061348
    // 0x80074C50: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074C50: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074C54: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074C58: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074C5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074C60: beq         $v0, $zero, L_80074C98
    if (ctx->r2 == 0) {
        // 0x80074C64: nop

            goto L_80074C98;
    }
    // 0x80074C64: nop

    // 0x80074C68: jal         0x80061348
    // 0x80074C6C: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074C6C: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074C70: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074C74: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074C78: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074C7C: beq         $v0, $zero, L_80074C98
    if (ctx->r2 == 0) {
        // 0x80074C80: nop

            goto L_80074C98;
    }
    // 0x80074C80: nop

    // 0x80074C84: jal         0x80061348
    // 0x80074C88: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074C88: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074C8C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074C90: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074C94: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074C98:
    // 0x80074C98: b           L_80074CA8
    // 0x80074C9C: nop

        goto L_80074CA8;
    // 0x80074C9C: nop

    // 0x80074CA0: b           L_80074CA8
    // 0x80074CA4: nop

        goto L_80074CA8;
    // 0x80074CA4: nop

L_80074CA8:
    // 0x80074CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074CB0: jr          $ra
    // 0x80074CB4: nop

    return;
    // 0x80074CB4: nop

;}
RECOMP_FUNC void func_80074CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074CC0: jal         0x80061348
    // 0x80074CC4: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074CC4: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x80074CC8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074CCC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074CD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074CD4: beq         $v0, $zero, L_80074D28
    if (ctx->r2 == 0) {
        // 0x80074CD8: nop

            goto L_80074D28;
    }
    // 0x80074CD8: nop

    // 0x80074CDC: jal         0x80061348
    // 0x80074CE0: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074CE0: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074CE4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074CE8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074CEC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074CF0: beq         $v0, $zero, L_80074D28
    if (ctx->r2 == 0) {
        // 0x80074CF4: nop

            goto L_80074D28;
    }
    // 0x80074CF4: nop

    // 0x80074CF8: jal         0x80061348
    // 0x80074CFC: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074CFC: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074D00: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074D04: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074D08: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074D0C: beq         $v0, $zero, L_80074D28
    if (ctx->r2 == 0) {
        // 0x80074D10: nop

            goto L_80074D28;
    }
    // 0x80074D10: nop

    // 0x80074D14: jal         0x80061348
    // 0x80074D18: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074D18: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074D1C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074D20: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074D24: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074D28:
    // 0x80074D28: b           L_80074D38
    // 0x80074D2C: nop

        goto L_80074D38;
    // 0x80074D2C: nop

    // 0x80074D30: b           L_80074D38
    // 0x80074D34: nop

        goto L_80074D38;
    // 0x80074D34: nop

L_80074D38:
    // 0x80074D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074D40: jr          $ra
    // 0x80074D44: nop

    return;
    // 0x80074D44: nop

;}
RECOMP_FUNC void func_80074D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074D4C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80074D50: nop

    // 0x80074D54: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80074D58: nop

    // 0x80074D5C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80074D60: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80074D64: jr          $ra
    // 0x80074D68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80074D68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074D6C: jr          $ra
    // 0x80074D70: nop

    return;
    // 0x80074D70: nop

    // 0x80074D74: jr          $ra
    // 0x80074D78: nop

    return;
    // 0x80074D78: nop

;}
RECOMP_FUNC void func_80074D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074D80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80074D84: nop

    // 0x80074D88: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80074D8C: nop

    // 0x80074D90: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80074D94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80074D98: jr          $ra
    // 0x80074D9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80074D9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074DA0: jr          $ra
    // 0x80074DA4: nop

    return;
    // 0x80074DA4: nop

    // 0x80074DA8: jr          $ra
    // 0x80074DAC: nop

    return;
    // 0x80074DAC: nop

;}
RECOMP_FUNC void func_80074DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074DB8: jal         0x80061488
    // 0x80074DBC: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80074DBC: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80074DC0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80074DC4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80074DC8: b           L_80074DD8
    // 0x80074DCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80074DD8;
    // 0x80074DCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074DD0: b           L_80074DD8
    // 0x80074DD4: nop

        goto L_80074DD8;
    // 0x80074DD4: nop

L_80074DD8:
    // 0x80074DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074DDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074DE0: jr          $ra
    // 0x80074DE4: nop

    return;
    // 0x80074DE4: nop

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
RECOMP_FUNC void func_80074E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074E20: jal         0x80061348
    // 0x80074E24: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074E24: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80074E28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074E2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074E30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074E34: beq         $v0, $zero, L_80074E88
    if (ctx->r2 == 0) {
        // 0x80074E38: nop

            goto L_80074E88;
    }
    // 0x80074E38: nop

    // 0x80074E3C: jal         0x80061348
    // 0x80074E40: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074E40: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80074E44: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074E48: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074E4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074E50: beq         $v0, $zero, L_80074E88
    if (ctx->r2 == 0) {
        // 0x80074E54: nop

            goto L_80074E88;
    }
    // 0x80074E54: nop

    // 0x80074E58: jal         0x80061348
    // 0x80074E5C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074E5C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x80074E60: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074E64: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074E68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074E6C: beq         $v0, $zero, L_80074E88
    if (ctx->r2 == 0) {
        // 0x80074E70: nop

            goto L_80074E88;
    }
    // 0x80074E70: nop

    // 0x80074E74: jal         0x80061348
    // 0x80074E78: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074E78: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x80074E7C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074E80: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074E84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074E88:
    // 0x80074E88: b           L_80074E98
    // 0x80074E8C: nop

        goto L_80074E98;
    // 0x80074E8C: nop

    // 0x80074E90: b           L_80074E98
    // 0x80074E94: nop

        goto L_80074E98;
    // 0x80074E94: nop

L_80074E98:
    // 0x80074E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074EA0: jr          $ra
    // 0x80074EA4: nop

    return;
    // 0x80074EA4: nop

;}
RECOMP_FUNC void func_80074EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074EB0: jal         0x80061348
    // 0x80074EB4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074EB4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80074EB8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074EBC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074EC0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074EC4: beq         $v0, $zero, L_80074F18
    if (ctx->r2 == 0) {
        // 0x80074EC8: nop

            goto L_80074F18;
    }
    // 0x80074EC8: nop

    // 0x80074ECC: jal         0x80061348
    // 0x80074ED0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074ED0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80074ED4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074ED8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074EDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074EE0: beq         $v0, $zero, L_80074F18
    if (ctx->r2 == 0) {
        // 0x80074EE4: nop

            goto L_80074F18;
    }
    // 0x80074EE4: nop

    // 0x80074EE8: jal         0x80061348
    // 0x80074EEC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074EEC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x80074EF0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074EF4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074EF8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074EFC: beq         $v0, $zero, L_80074F18
    if (ctx->r2 == 0) {
        // 0x80074F00: nop

            goto L_80074F18;
    }
    // 0x80074F00: nop

    // 0x80074F04: jal         0x80061348
    // 0x80074F08: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074F08: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x80074F0C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074F10: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074F14: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074F18:
    // 0x80074F18: b           L_80074F28
    // 0x80074F1C: nop

        goto L_80074F28;
    // 0x80074F1C: nop

    // 0x80074F20: b           L_80074F28
    // 0x80074F24: nop

        goto L_80074F28;
    // 0x80074F24: nop

L_80074F28:
    // 0x80074F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074F30: jr          $ra
    // 0x80074F34: nop

    return;
    // 0x80074F34: nop

;}
RECOMP_FUNC void func_80074F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074F40: jal         0x80061348
    // 0x80074F44: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074F44: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x80074F48: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80074F4C: b           L_80074F5C
    // 0x80074F50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80074F5C;
    // 0x80074F50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074F54: b           L_80074F5C
    // 0x80074F58: nop

        goto L_80074F5C;
    // 0x80074F58: nop

L_80074F5C:
    // 0x80074F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074F64: jr          $ra
    // 0x80074F68: nop

    return;
    // 0x80074F68: nop

;}
RECOMP_FUNC void func_80074F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074F74: jal         0x80061348
    // 0x80074F78: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074F78: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    after_0:
    // 0x80074F7C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80074F80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074F84: bne         $v0, $zero, L_80074F9C
    if (ctx->r2 != 0) {
        // 0x80074F88: nop

            goto L_80074F9C;
    }
    // 0x80074F88: nop

    // 0x80074F8C: jal         0x80061348
    // 0x80074F90: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074F90: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    after_1:
    // 0x80074F94: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80074F98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074F9C:
    // 0x80074F9C: b           L_80074FAC
    // 0x80074FA0: nop

        goto L_80074FAC;
    // 0x80074FA0: nop

    // 0x80074FA4: b           L_80074FAC
    // 0x80074FA8: nop

        goto L_80074FAC;
    // 0x80074FA8: nop

L_80074FAC:
    // 0x80074FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074FB4: jr          $ra
    // 0x80074FB8: nop

    return;
    // 0x80074FB8: nop

;}
RECOMP_FUNC void func_80074FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074FC4: jal         0x80061348
    // 0x80074FC8: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074FC8: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x80074FCC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80074FD0: b           L_80074FE0
    // 0x80074FD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80074FE0;
    // 0x80074FD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074FD8: b           L_80074FE0
    // 0x80074FDC: nop

        goto L_80074FE0;
    // 0x80074FDC: nop

L_80074FE0:
    // 0x80074FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074FE8: jr          $ra
    // 0x80074FEC: nop

    return;
    // 0x80074FEC: nop

;}
