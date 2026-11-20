#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80064A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064A70: jal         0x80061488
    // 0x80064A74: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064A74: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064A78: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064A7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064A80: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064A84: nop

            goto L_80064B14;
    }
    // 0x80064A84: nop

    // 0x80064A88: jal         0x80061488
    // 0x80064A8C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064A8C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064A90: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064A98: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064A9C: nop

            goto L_80064B14;
    }
    // 0x80064A9C: nop

    // 0x80064AA0: jal         0x80061488
    // 0x80064AA4: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064AA4: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x80064AA8: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064AAC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064AB0: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064AB4: nop

            goto L_80064B14;
    }
    // 0x80064AB4: nop

    // 0x80064AB8: jal         0x80061488
    // 0x80064ABC: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x80064ABC: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064AC0: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064AC4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80064AC8: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064ACC: nop

            goto L_80064B14;
    }
    // 0x80064ACC: nop

    // 0x80064AD0: jal         0x80061488
    // 0x80064AD4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064AD4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x80064AD8: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064ADC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064AE0: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064AE4: nop

            goto L_80064B14;
    }
    // 0x80064AE4: nop

    // 0x80064AE8: jal         0x8005F064
    // 0x80064AEC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064AEC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064AF0: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064AF4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064AF8: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064AFC: nop

            goto L_80064B14;
    }
    // 0x80064AFC: nop

    // 0x80064B00: jal         0x80061348
    // 0x80064B04: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064B04: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064B08: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064B0C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064B10: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064B14:
    // 0x80064B14: b           L_80064B24
    // 0x80064B18: nop

        goto L_80064B24;
    // 0x80064B18: nop

    // 0x80064B1C: b           L_80064B24
    // 0x80064B20: nop

        goto L_80064B24;
    // 0x80064B20: nop

L_80064B24:
    // 0x80064B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064B2C: jr          $ra
    // 0x80064B30: nop

    return;
    // 0x80064B30: nop

;}
RECOMP_FUNC void func_80064B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064B3C: jal         0x8005F064
    // 0x80064B40: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064B40: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x80064B44: b           L_80064B54
    // 0x80064B48: nop

        goto L_80064B54;
    // 0x80064B48: nop

    // 0x80064B4C: b           L_80064B54
    // 0x80064B50: nop

        goto L_80064B54;
    // 0x80064B50: nop

L_80064B54:
    // 0x80064B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064B5C: jr          $ra
    // 0x80064B60: nop

    return;
    // 0x80064B60: nop

;}
RECOMP_FUNC void func_80064B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064B68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064B6C: nop

    // 0x80064B70: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064B74: nop

    // 0x80064B78: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064B7C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064B80: jr          $ra
    // 0x80064B84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064B84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064B88: jr          $ra
    // 0x80064B8C: nop

    return;
    // 0x80064B8C: nop

    // 0x80064B90: jr          $ra
    // 0x80064B94: nop

    return;
    // 0x80064B94: nop

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
RECOMP_FUNC void func_80064BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064BD0: jal         0x8005F064
    // 0x80064BD4: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064BD4: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x80064BD8: b           L_80064BE8
    // 0x80064BDC: nop

        goto L_80064BE8;
    // 0x80064BDC: nop

    // 0x80064BE0: b           L_80064BE8
    // 0x80064BE4: nop

        goto L_80064BE8;
    // 0x80064BE4: nop

L_80064BE8:
    // 0x80064BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064BF0: jr          $ra
    // 0x80064BF4: nop

    return;
    // 0x80064BF4: nop

;}
RECOMP_FUNC void func_80064BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064C00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064C04: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064C08: nop

    // 0x80064C0C: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064C10: nop

    // 0x80064C14: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80064C18: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064C1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064C20: beq         $v0, $zero, L_80064C38
    if (ctx->r2 == 0) {
        // 0x80064C24: nop

            goto L_80064C38;
    }
    // 0x80064C24: nop

    // 0x80064C28: jal         0x8005F064
    // 0x80064C2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064C2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064C30: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064C34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80064C38:
    // 0x80064C38: b           L_80064C48
    // 0x80064C3C: nop

        goto L_80064C48;
    // 0x80064C3C: nop

    // 0x80064C40: b           L_80064C48
    // 0x80064C44: nop

        goto L_80064C48;
    // 0x80064C44: nop

L_80064C48:
    // 0x80064C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064C50: jr          $ra
    // 0x80064C54: nop

    return;
    // 0x80064C54: nop

;}
RECOMP_FUNC void func_80064C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064C60: jal         0x80061488
    // 0x80064C64: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064C64: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064C68: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064C6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064C70: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064C74: nop

            goto L_80064D04;
    }
    // 0x80064C74: nop

    // 0x80064C78: jal         0x80061488
    // 0x80064C7C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064C7C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064C80: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064C84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064C88: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064C8C: nop

            goto L_80064D04;
    }
    // 0x80064C8C: nop

    // 0x80064C90: jal         0x80061488
    // 0x80064C94: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064C94: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x80064C98: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064C9C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064CA0: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064CA4: nop

            goto L_80064D04;
    }
    // 0x80064CA4: nop

    // 0x80064CA8: jal         0x80061488
    // 0x80064CAC: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x80064CAC: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064CB0: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064CB4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80064CB8: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064CBC: nop

            goto L_80064D04;
    }
    // 0x80064CBC: nop

    // 0x80064CC0: jal         0x80061488
    // 0x80064CC4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064CC4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x80064CC8: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064CCC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064CD0: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064CD4: nop

            goto L_80064D04;
    }
    // 0x80064CD4: nop

    // 0x80064CD8: jal         0x8005F064
    // 0x80064CDC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064CDC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064CE0: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064CE4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064CE8: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064CEC: nop

            goto L_80064D04;
    }
    // 0x80064CEC: nop

    // 0x80064CF0: jal         0x80061348
    // 0x80064CF4: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064CF4: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064CF8: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064CFC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064D00: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064D04:
    // 0x80064D04: b           L_80064D14
    // 0x80064D08: nop

        goto L_80064D14;
    // 0x80064D08: nop

    // 0x80064D0C: b           L_80064D14
    // 0x80064D10: nop

        goto L_80064D14;
    // 0x80064D10: nop

L_80064D14:
    // 0x80064D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064D1C: jr          $ra
    // 0x80064D20: nop

    return;
    // 0x80064D20: nop

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
RECOMP_FUNC void func_80064DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064DF0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064DF4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064DF8: nop

    // 0x80064DFC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064E00: nop

    // 0x80064E04: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064E08: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064E0C: jr          $ra
    // 0x80064E10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064E10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064E14: jr          $ra
    // 0x80064E18: nop

    return;
    // 0x80064E18: nop

    // 0x80064E1C: jr          $ra
    // 0x80064E20: nop

    return;
    // 0x80064E20: nop

;}
RECOMP_FUNC void func_80064E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064E2C: jal         0x8005F064
    // 0x80064E30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064E30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064E34: b           L_80064E44
    // 0x80064E38: nop

        goto L_80064E44;
    // 0x80064E38: nop

    // 0x80064E3C: b           L_80064E44
    // 0x80064E40: nop

        goto L_80064E44;
    // 0x80064E40: nop

L_80064E44:
    // 0x80064E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064E4C: jr          $ra
    // 0x80064E50: nop

    return;
    // 0x80064E50: nop

;}
RECOMP_FUNC void func_80064E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064E5C: jal         0x8005F064
    // 0x80064E60: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064E60: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_0:
    // 0x80064E64: b           L_80064E74
    // 0x80064E68: nop

        goto L_80064E74;
    // 0x80064E68: nop

    // 0x80064E6C: b           L_80064E74
    // 0x80064E70: nop

        goto L_80064E74;
    // 0x80064E70: nop

L_80064E74:
    // 0x80064E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064E7C: jr          $ra
    // 0x80064E80: nop

    return;
    // 0x80064E80: nop

;}
RECOMP_FUNC void func_80064E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064E88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064E8C: nop

    // 0x80064E90: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064E94: nop

    // 0x80064E98: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064E9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064EA0: jr          $ra
    // 0x80064EA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064EA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064EA8: jr          $ra
    // 0x80064EAC: nop

    return;
    // 0x80064EAC: nop

    // 0x80064EB0: jr          $ra
    // 0x80064EB4: nop

    return;
    // 0x80064EB4: nop

;}
RECOMP_FUNC void func_80064EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064EB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064EBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064EC0: nop

    // 0x80064EC4: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80064EC8: nop

    // 0x80064ECC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80064ED0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064ED4: jr          $ra
    // 0x80064ED8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064ED8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064EDC: jr          $ra
    // 0x80064EE0: nop

    return;
    // 0x80064EE0: nop

    // 0x80064EE4: jr          $ra
    // 0x80064EE8: nop

    return;
    // 0x80064EE8: nop

;}
RECOMP_FUNC void func_80064EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064EF4: jal         0x8005F064
    // 0x80064EF8: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064EF8: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x80064EFC: b           L_80064F0C
    // 0x80064F00: nop

        goto L_80064F0C;
    // 0x80064F00: nop

    // 0x80064F04: b           L_80064F0C
    // 0x80064F08: nop

        goto L_80064F0C;
    // 0x80064F08: nop

L_80064F0C:
    // 0x80064F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064F14: jr          $ra
    // 0x80064F18: nop

    return;
    // 0x80064F18: nop

;}
RECOMP_FUNC void func_80064F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064F20: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064F24: nop

    // 0x80064F28: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80064F2C: nop

    // 0x80064F30: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064F34: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064F38: jr          $ra
    // 0x80064F3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064F3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064F40: jr          $ra
    // 0x80064F44: nop

    return;
    // 0x80064F44: nop

    // 0x80064F48: jr          $ra
    // 0x80064F4C: nop

    return;
    // 0x80064F4C: nop

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
RECOMP_FUNC void func_80064F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064F88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064F8C: nop

    // 0x80064F90: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80064F94: nop

    // 0x80064F98: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064F9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064FA0: jr          $ra
    // 0x80064FA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064FA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064FA8: jr          $ra
    // 0x80064FAC: nop

    return;
    // 0x80064FAC: nop

    // 0x80064FB0: jr          $ra
    // 0x80064FB4: nop

    return;
    // 0x80064FB4: nop

;}
RECOMP_FUNC void func_80064FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064FB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064FBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064FC0: nop

    // 0x80064FC4: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x80064FC8: nop

    // 0x80064FCC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064FD0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064FD4: jr          $ra
    // 0x80064FD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064FD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064FDC: jr          $ra
    // 0x80064FE0: nop

    return;
    // 0x80064FE0: nop

    // 0x80064FE4: jr          $ra
    // 0x80064FE8: nop

    return;
    // 0x80064FE8: nop

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
RECOMP_FUNC void func_8006501C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006501C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065024: jal         0x80061488
    // 0x80065028: addiu       $a0, $zero, 0x5E0
    ctx->r4 = ADD32(0, 0X5E0);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065028: addiu       $a0, $zero, 0x5E0
    ctx->r4 = ADD32(0, 0X5E0);
    after_0:
    // 0x8006502C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80065030: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065034: b           L_80065044
    // 0x80065038: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065044;
    // 0x80065038: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006503C: b           L_80065044
    // 0x80065040: nop

        goto L_80065044;
    // 0x80065040: nop

L_80065044:
    // 0x80065044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006504C: jr          $ra
    // 0x80065050: nop

    return;
    // 0x80065050: nop

;}
RECOMP_FUNC void func_80065054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006505C: jal         0x80061488
    // 0x80065060: addiu       $a0, $zero, 0x5E0
    ctx->r4 = ADD32(0, 0X5E0);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065060: addiu       $a0, $zero, 0x5E0
    ctx->r4 = ADD32(0, 0X5E0);
    after_0:
    // 0x80065064: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80065068: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006506C: b           L_8006507C
    // 0x80065070: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006507C;
    // 0x80065070: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065074: b           L_8006507C
    // 0x80065078: nop

        goto L_8006507C;
    // 0x80065078: nop

L_8006507C:
    // 0x8006507C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065084: jr          $ra
    // 0x80065088: nop

    return;
    // 0x80065088: nop

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
RECOMP_FUNC void func_800650C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800650C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800650C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800650C8: nop

    // 0x800650CC: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x800650D0: nop

    // 0x800650D4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800650D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800650DC: jr          $ra
    // 0x800650E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800650E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800650E4: jr          $ra
    // 0x800650E8: nop

    return;
    // 0x800650E8: nop

    // 0x800650EC: jr          $ra
    // 0x800650F0: nop

    return;
    // 0x800650F0: nop

;}
RECOMP_FUNC void func_800650F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800650F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800650F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800650FC: jal         0x8005F064
    // 0x80065100: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065100: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x80065104: b           L_80065114
    // 0x80065108: nop

        goto L_80065114;
    // 0x80065108: nop

    // 0x8006510C: b           L_80065114
    // 0x80065110: nop

        goto L_80065114;
    // 0x80065110: nop

L_80065114:
    // 0x80065114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006511C: jr          $ra
    // 0x80065120: nop

    return;
    // 0x80065120: nop

;}
RECOMP_FUNC void func_80065124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065124: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065128: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006512C: nop

    // 0x80065130: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x80065134: nop

    // 0x80065138: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006513C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065140: jr          $ra
    // 0x80065144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065148: jr          $ra
    // 0x8006514C: nop

    return;
    // 0x8006514C: nop

    // 0x80065150: jr          $ra
    // 0x80065154: nop

    return;
    // 0x80065154: nop

;}
RECOMP_FUNC void func_80065158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065158: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006515C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065160: nop

    // 0x80065164: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x80065168: nop

    // 0x8006516C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80065170: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065174: jr          $ra
    // 0x80065178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006517C: jr          $ra
    // 0x80065180: nop

    return;
    // 0x80065180: nop

    // 0x80065184: jr          $ra
    // 0x80065188: nop

    return;
    // 0x80065188: nop

;}
RECOMP_FUNC void func_8006518C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006518C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065190: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065194: nop

    // 0x80065198: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x8006519C: nop

    // 0x800651A0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800651A4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800651A8: jr          $ra
    // 0x800651AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800651AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800651B0: jr          $ra
    // 0x800651B4: nop

    return;
    // 0x800651B4: nop

    // 0x800651B8: jr          $ra
    // 0x800651BC: nop

    return;
    // 0x800651BC: nop

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
RECOMP_FUNC void func_800651F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800651F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800651F8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800651FC: nop

    // 0x80065200: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80065204: nop

    // 0x80065208: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006520C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065210: jr          $ra
    // 0x80065214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065218: jr          $ra
    // 0x8006521C: nop

    return;
    // 0x8006521C: nop

    // 0x80065220: jr          $ra
    // 0x80065224: nop

    return;
    // 0x80065224: nop

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
RECOMP_FUNC void func_8006525C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006525C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065260: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065264: nop

    // 0x80065268: lh          $v0, 0x26($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X26);
    // 0x8006526C: nop

    // 0x80065270: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80065274: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065278: jr          $ra
    // 0x8006527C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006527C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065280: jr          $ra
    // 0x80065284: nop

    return;
    // 0x80065284: nop

    // 0x80065288: jr          $ra
    // 0x8006528C: nop

    return;
    // 0x8006528C: nop

;}
RECOMP_FUNC void func_80065290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065298: jal         0x8005F064
    // 0x8006529C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006529C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800652A0: b           L_800652B0
    // 0x800652A4: nop

        goto L_800652B0;
    // 0x800652A4: nop

    // 0x800652A8: b           L_800652B0
    // 0x800652AC: nop

        goto L_800652B0;
    // 0x800652AC: nop

L_800652B0:
    // 0x800652B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800652B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800652B8: jr          $ra
    // 0x800652BC: nop

    return;
    // 0x800652BC: nop

;}
RECOMP_FUNC void func_800652C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800652C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800652C8: jal         0x8005F064
    // 0x800652CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800652CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x800652D0: b           L_800652E0
    // 0x800652D4: nop

        goto L_800652E0;
    // 0x800652D4: nop

    // 0x800652D8: b           L_800652E0
    // 0x800652DC: nop

        goto L_800652E0;
    // 0x800652DC: nop

L_800652E0:
    // 0x800652E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800652E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800652E8: jr          $ra
    // 0x800652EC: nop

    return;
    // 0x800652EC: nop

;}
RECOMP_FUNC void func_800652F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800652F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800652F8: jal         0x8005F064
    // 0x800652FC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800652FC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80065300: b           L_80065310
    // 0x80065304: nop

        goto L_80065310;
    // 0x80065304: nop

    // 0x80065308: b           L_80065310
    // 0x8006530C: nop

        goto L_80065310;
    // 0x8006530C: nop

L_80065310:
    // 0x80065310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065318: jr          $ra
    // 0x8006531C: nop

    return;
    // 0x8006531C: nop

;}
RECOMP_FUNC void func_80065320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065320: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065324: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065328: nop

    // 0x8006532C: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80065330: nop

    // 0x80065334: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065338: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006533C: jr          $ra
    // 0x80065340: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065340: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065344: jr          $ra
    // 0x80065348: nop

    return;
    // 0x80065348: nop

    // 0x8006534C: jr          $ra
    // 0x80065350: nop

    return;
    // 0x80065350: nop

;}
RECOMP_FUNC void func_80065354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065354: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065358: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006535C: nop

    // 0x80065360: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80065364: nop

    // 0x80065368: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x8006536C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065370: beq         $v0, $zero, L_80065388
    if (ctx->r2 == 0) {
        // 0x80065374: nop

            goto L_80065388;
    }
    // 0x80065374: nop

    // 0x80065378: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x8006537C: nop

    // 0x80065380: slti        $t8, $v0, 0x1F5
    ctx->r24 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80065384: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065388:
    // 0x80065388: jr          $ra
    // 0x8006538C: nop

    return;
    // 0x8006538C: nop

    // 0x80065390: jr          $ra
    // 0x80065394: nop

    return;
    // 0x80065394: nop

    // 0x80065398: jr          $ra
    // 0x8006539C: nop

    return;
    // 0x8006539C: nop

;}
RECOMP_FUNC void func_800653A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800653A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800653A8: nop

    // 0x800653AC: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x800653B0: nop

    // 0x800653B4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800653B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800653BC: jr          $ra
    // 0x800653C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800653C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800653C4: jr          $ra
    // 0x800653C8: nop

    return;
    // 0x800653C8: nop

    // 0x800653CC: jr          $ra
    // 0x800653D0: nop

    return;
    // 0x800653D0: nop

;}
RECOMP_FUNC void func_800653D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800653D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800653DC: nop

    // 0x800653E0: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x800653E4: nop

    // 0x800653E8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800653EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800653F0: jr          $ra
    // 0x800653F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800653F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800653F8: jr          $ra
    // 0x800653FC: nop

    return;
    // 0x800653FC: nop

    // 0x80065400: jr          $ra
    // 0x80065404: nop

    return;
    // 0x80065404: nop

;}
RECOMP_FUNC void func_80065408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065408: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006540C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065410: nop

    // 0x80065414: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80065418: nop

    // 0x8006541C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80065420: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065424: jr          $ra
    // 0x80065428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006542C: jr          $ra
    // 0x80065430: nop

    return;
    // 0x80065430: nop

    // 0x80065434: jr          $ra
    // 0x80065438: nop

    return;
    // 0x80065438: nop

;}
RECOMP_FUNC void func_8006543C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006543C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065444: jal         0x8005F064
    // 0x80065448: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065448: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    after_0:
    // 0x8006544C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80065450: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065454: beq         $v0, $zero, L_8006546C
    if (ctx->r2 == 0) {
        // 0x80065458: nop

            goto L_8006546C;
    }
    // 0x80065458: nop

    // 0x8006545C: jal         0x8005F064
    // 0x80065460: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80065460: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_1:
    // 0x80065464: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065468: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006546C:
    // 0x8006546C: b           L_8006547C
    // 0x80065470: nop

        goto L_8006547C;
    // 0x80065470: nop

    // 0x80065474: b           L_8006547C
    // 0x80065478: nop

        goto L_8006547C;
    // 0x80065478: nop

L_8006547C:
    // 0x8006547C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065484: jr          $ra
    // 0x80065488: nop

    return;
    // 0x80065488: nop

;}
RECOMP_FUNC void func_8006548C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006548C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065494: jal         0x8005F064
    // 0x80065498: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065498: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x8006549C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800654A0: b           L_800654B0
    // 0x800654A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800654B0;
    // 0x800654A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800654A8: b           L_800654B0
    // 0x800654AC: nop

        goto L_800654B0;
    // 0x800654AC: nop

L_800654B0:
    // 0x800654B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800654B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800654B8: jr          $ra
    // 0x800654BC: nop

    return;
    // 0x800654BC: nop

;}
RECOMP_FUNC void func_800654C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800654C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800654C8: jal         0x80061488
    // 0x800654CC: addiu       $a0, $zero, 0x74C
    ctx->r4 = ADD32(0, 0X74C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800654CC: addiu       $a0, $zero, 0x74C
    ctx->r4 = ADD32(0, 0X74C);
    after_0:
    // 0x800654D0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800654D4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800654D8: b           L_800654E8
    // 0x800654DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800654E8;
    // 0x800654DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800654E0: b           L_800654E8
    // 0x800654E4: nop

        goto L_800654E8;
    // 0x800654E4: nop

L_800654E8:
    // 0x800654E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800654EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800654F0: jr          $ra
    // 0x800654F4: nop

    return;
    // 0x800654F4: nop

;}
RECOMP_FUNC void func_800654F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800654FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065500: jal         0x80061348
    // 0x80065504: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065504: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_0:
    // 0x80065508: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006550C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065510: bne         $v0, $zero, L_8006552C
    if (ctx->r2 != 0) {
        // 0x80065514: nop

            goto L_8006552C;
    }
    // 0x80065514: nop

    // 0x80065518: jal         0x80061348
    // 0x8006551C: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006551C: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x80065520: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80065524: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80065528: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006552C:
    // 0x8006552C: b           L_8006553C
    // 0x80065530: nop

        goto L_8006553C;
    // 0x80065530: nop

    // 0x80065534: b           L_8006553C
    // 0x80065538: nop

        goto L_8006553C;
    // 0x80065538: nop

L_8006553C:
    // 0x8006553C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065544: jr          $ra
    // 0x80065548: nop

    return;
    // 0x80065548: nop

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
RECOMP_FUNC void func_80065580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065580: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065584: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065588: nop

    // 0x8006558C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80065590: nop

    // 0x80065594: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80065598: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006559C: beq         $v0, $zero, L_800655B8
    if (ctx->r2 == 0) {
        // 0x800655A0: nop

            goto L_800655B8;
    }
    // 0x800655A0: nop

    // 0x800655A4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800655A8: nop

    // 0x800655AC: slti        $t8, $v0, 0x12D
    ctx->r24 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x800655B0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800655B4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800655B8:
    // 0x800655B8: jr          $ra
    // 0x800655BC: nop

    return;
    // 0x800655BC: nop

    // 0x800655C0: jr          $ra
    // 0x800655C4: nop

    return;
    // 0x800655C4: nop

    // 0x800655C8: jr          $ra
    // 0x800655CC: nop

    return;
    // 0x800655CC: nop

;}
RECOMP_FUNC void func_800655D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800655D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800655D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800655D8: nop

    // 0x800655DC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800655E0: nop

    // 0x800655E4: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x800655E8: jr          $ra
    // 0x800655EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800655EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800655F0: jr          $ra
    // 0x800655F4: nop

    return;
    // 0x800655F4: nop

    // 0x800655F8: jr          $ra
    // 0x800655FC: nop

    return;
    // 0x800655FC: nop

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
RECOMP_FUNC void func_80065650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065650: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065654: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065658: nop

    // 0x8006565C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80065660: nop

    // 0x80065664: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80065668: jr          $ra
    // 0x8006566C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006566C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065670: jr          $ra
    // 0x80065674: nop

    return;
    // 0x80065674: nop

    // 0x80065678: jr          $ra
    // 0x8006567C: nop

    return;
    // 0x8006567C: nop

;}
RECOMP_FUNC void func_80065680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065688: jal         0x8005F064
    // 0x8006568C: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006568C: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_0:
    // 0x80065690: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065694: b           L_800656A4
    // 0x80065698: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800656A4;
    // 0x80065698: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006569C: b           L_800656A4
    // 0x800656A0: nop

        goto L_800656A4;
    // 0x800656A0: nop

L_800656A4:
    // 0x800656A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800656A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800656AC: jr          $ra
    // 0x800656B0: nop

    return;
    // 0x800656B0: nop

;}
RECOMP_FUNC void func_800656B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800656B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800656BC: jal         0x8005F064
    // 0x800656C0: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800656C0: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x800656C4: b           L_800656D4
    // 0x800656C8: nop

        goto L_800656D4;
    // 0x800656C8: nop

    // 0x800656CC: b           L_800656D4
    // 0x800656D0: nop

        goto L_800656D4;
    // 0x800656D0: nop

L_800656D4:
    // 0x800656D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800656D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800656DC: jr          $ra
    // 0x800656E0: nop

    return;
    // 0x800656E0: nop

;}
