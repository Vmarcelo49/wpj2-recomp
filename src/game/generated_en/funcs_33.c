#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80077A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A08: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077A0C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077A10: nop

    // 0x80077A14: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077A18: nop

    // 0x80077A1C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077A20: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077A24: jr          $ra
    // 0x80077A28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077A28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077A2C: jr          $ra
    // 0x80077A30: nop

    return;
    // 0x80077A30: nop

    // 0x80077A34: jr          $ra
    // 0x80077A38: nop

    return;
    // 0x80077A38: nop

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
RECOMP_FUNC void func_80077A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077A74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077A78: nop

    // 0x80077A7C: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x80077A80: nop

    // 0x80077A84: slti        $t7, $v0, 0x65
    ctx->r15 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x80077A88: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077A8C: bne         $v0, $zero, L_80077AA4
    if (ctx->r2 != 0) {
        // 0x80077A90: nop

            goto L_80077AA4;
    }
    // 0x80077A90: nop

    // 0x80077A94: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80077A98: nop

    // 0x80077A9C: slti        $t8, $v0, 0x65
    ctx->r24 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x80077AA0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80077AA4:
    // 0x80077AA4: jr          $ra
    // 0x80077AA8: nop

    return;
    // 0x80077AA8: nop

    // 0x80077AAC: jr          $ra
    // 0x80077AB0: nop

    return;
    // 0x80077AB0: nop

    // 0x80077AB4: jr          $ra
    // 0x80077AB8: nop

    return;
    // 0x80077AB8: nop

;}
RECOMP_FUNC void func_80077ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077ABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077AC4: jal         0x80061348
    // 0x80077AC8: addiu       $a0, $zero, 0x5C7
    ctx->r4 = ADD32(0, 0X5C7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80077AC8: addiu       $a0, $zero, 0x5C7
    ctx->r4 = ADD32(0, 0X5C7);
    after_0:
    // 0x80077ACC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077AD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077AD4: b           L_80077AE4
    // 0x80077AD8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80077AE4;
    // 0x80077AD8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077ADC: b           L_80077AE4
    // 0x80077AE0: nop

        goto L_80077AE4;
    // 0x80077AE0: nop

L_80077AE4:
    // 0x80077AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077AEC: jr          $ra
    // 0x80077AF0: nop

    return;
    // 0x80077AF0: nop

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
RECOMP_FUNC void func_80077B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077B34: jal         0x80061488
    // 0x80077B38: addiu       $a0, $zero, 0x56E
    ctx->r4 = ADD32(0, 0X56E);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077B38: addiu       $a0, $zero, 0x56E
    ctx->r4 = ADD32(0, 0X56E);
    after_0:
    // 0x80077B3C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80077B40: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077B44: b           L_80077B54
    // 0x80077B48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077B54;
    // 0x80077B48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077B4C: b           L_80077B54
    // 0x80077B50: nop

        goto L_80077B54;
    // 0x80077B50: nop

L_80077B54:
    // 0x80077B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077B5C: jr          $ra
    // 0x80077B60: nop

    return;
    // 0x80077B60: nop

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
RECOMP_FUNC void func_80077B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B9C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077BA0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077BA4: nop

    // 0x80077BA8: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80077BAC: nop

    // 0x80077BB0: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80077BB4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077BB8: jr          $ra
    // 0x80077BBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077BBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077BC0: jr          $ra
    // 0x80077BC4: nop

    return;
    // 0x80077BC4: nop

    // 0x80077BC8: jr          $ra
    // 0x80077BCC: nop

    return;
    // 0x80077BCC: nop

;}
RECOMP_FUNC void func_80077BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077BD0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077BD4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077BD8: nop

    // 0x80077BDC: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80077BE0: nop

    // 0x80077BE4: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80077BE8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077BEC: jr          $ra
    // 0x80077BF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077BF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077BF4: jr          $ra
    // 0x80077BF8: nop

    return;
    // 0x80077BF8: nop

    // 0x80077BFC: jr          $ra
    // 0x80077C00: nop

    return;
    // 0x80077C00: nop

;}
RECOMP_FUNC void func_80077C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077C04: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077C08: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077C0C: nop

    // 0x80077C10: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80077C14: nop

    // 0x80077C18: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80077C1C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077C20: jr          $ra
    // 0x80077C24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077C24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077C28: jr          $ra
    // 0x80077C2C: nop

    return;
    // 0x80077C2C: nop

    // 0x80077C30: jr          $ra
    // 0x80077C34: nop

    return;
    // 0x80077C34: nop

;}
RECOMP_FUNC void func_80077C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077C40: jal         0x80061488
    // 0x80077C44: addiu       $a0, $zero, 0x5F5
    ctx->r4 = ADD32(0, 0X5F5);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077C44: addiu       $a0, $zero, 0x5F5
    ctx->r4 = ADD32(0, 0X5F5);
    after_0:
    // 0x80077C48: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80077C4C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80077C50: b           L_80077C60
    // 0x80077C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077C60;
    // 0x80077C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077C58: b           L_80077C60
    // 0x80077C5C: nop

        goto L_80077C60;
    // 0x80077C5C: nop

L_80077C60:
    // 0x80077C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077C68: jr          $ra
    // 0x80077C6C: nop

    return;
    // 0x80077C6C: nop

;}
RECOMP_FUNC void func_80077C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077C78: jal         0x80061348
    // 0x80077C7C: addiu       $a0, $zero, 0x558
    ctx->r4 = ADD32(0, 0X558);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80077C7C: addiu       $a0, $zero, 0x558
    ctx->r4 = ADD32(0, 0X558);
    after_0:
    // 0x80077C80: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077C84: b           L_80077C94
    // 0x80077C88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077C94;
    // 0x80077C88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077C8C: b           L_80077C94
    // 0x80077C90: nop

        goto L_80077C94;
    // 0x80077C90: nop

L_80077C94:
    // 0x80077C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077C9C: jr          $ra
    // 0x80077CA0: nop

    return;
    // 0x80077CA0: nop

;}
RECOMP_FUNC void func_80077CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077CA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077CA8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077CAC: nop

    // 0x80077CB0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80077CB4: nop

    // 0x80077CB8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80077CBC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077CC0: jr          $ra
    // 0x80077CC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077CC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077CC8: jr          $ra
    // 0x80077CCC: nop

    return;
    // 0x80077CCC: nop

    // 0x80077CD0: jr          $ra
    // 0x80077CD4: nop

    return;
    // 0x80077CD4: nop

;}
RECOMP_FUNC void func_80077CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077CE0: jal         0x80061488
    // 0x80077CE4: addiu       $a0, $zero, 0x561
    ctx->r4 = ADD32(0, 0X561);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077CE4: addiu       $a0, $zero, 0x561
    ctx->r4 = ADD32(0, 0X561);
    after_0:
    // 0x80077CE8: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077CEC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077CF0: b           L_80077D00
    // 0x80077CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077D00;
    // 0x80077CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077CF8: b           L_80077D00
    // 0x80077CFC: nop

        goto L_80077D00;
    // 0x80077CFC: nop

L_80077D00:
    // 0x80077D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077D08: jr          $ra
    // 0x80077D0C: nop

    return;
    // 0x80077D0C: nop

;}
RECOMP_FUNC void func_80077D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077D14: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077D18: nop

    // 0x80077D1C: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80077D20: nop

    // 0x80077D24: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80077D28: jr          $ra
    // 0x80077D2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077D2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077D30: jr          $ra
    // 0x80077D34: nop

    return;
    // 0x80077D34: nop

    // 0x80077D38: jr          $ra
    // 0x80077D3C: nop

    return;
    // 0x80077D3C: nop

;}
RECOMP_FUNC void func_80077D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077D44: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077D48: nop

    // 0x80077D4C: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80077D50: nop

    // 0x80077D54: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80077D58: jr          $ra
    // 0x80077D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077D60: jr          $ra
    // 0x80077D64: nop

    return;
    // 0x80077D64: nop

    // 0x80077D68: jr          $ra
    // 0x80077D6C: nop

    return;
    // 0x80077D6C: nop

;}
RECOMP_FUNC void func_80077D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077D74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077D78: nop

    // 0x80077D7C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80077D80: nop

    // 0x80077D84: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80077D88: jr          $ra
    // 0x80077D8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077D8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077D90: jr          $ra
    // 0x80077D94: nop

    return;
    // 0x80077D94: nop

    // 0x80077D98: jr          $ra
    // 0x80077D9C: nop

    return;
    // 0x80077D9C: nop

;}
RECOMP_FUNC void func_80077DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077DA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077DA8: jal         0x8005F064
    // 0x80077DAC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077DAC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077DB0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077DB4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077DB8: beq         $v0, $zero, L_80077DD0
    if (ctx->r2 == 0) {
        // 0x80077DBC: nop

            goto L_80077DD0;
    }
    // 0x80077DBC: nop

    // 0x80077DC0: jal         0x8005F064
    // 0x80077DC4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80077DC4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x80077DC8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077DCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80077DD0:
    // 0x80077DD0: b           L_80077DE0
    // 0x80077DD4: nop

        goto L_80077DE0;
    // 0x80077DD4: nop

    // 0x80077DD8: b           L_80077DE0
    // 0x80077DDC: nop

        goto L_80077DE0;
    // 0x80077DDC: nop

L_80077DE0:
    // 0x80077DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077DE8: jr          $ra
    // 0x80077DEC: nop

    return;
    // 0x80077DEC: nop

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
RECOMP_FUNC void func_80077E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077E48: jal         0x8005F064
    // 0x80077E4C: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077E4C: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077E50: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077E54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077E58: beq         $v0, $zero, L_80077E70
    if (ctx->r2 == 0) {
        // 0x80077E5C: nop

            goto L_80077E70;
    }
    // 0x80077E5C: nop

    // 0x80077E60: jal         0x8005F064
    // 0x80077E64: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80077E64: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x80077E68: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077E6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80077E70:
    // 0x80077E70: b           L_80077E80
    // 0x80077E74: nop

        goto L_80077E80;
    // 0x80077E74: nop

    // 0x80077E78: b           L_80077E80
    // 0x80077E7C: nop

        goto L_80077E80;
    // 0x80077E7C: nop

L_80077E80:
    // 0x80077E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077E88: jr          $ra
    // 0x80077E8C: nop

    return;
    // 0x80077E8C: nop

;}
RECOMP_FUNC void func_80077E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077E98: jal         0x8005F064
    // 0x80077E9C: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077E9C: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077EA0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077EA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077EA8: beq         $v0, $zero, L_80077EC0
    if (ctx->r2 == 0) {
        // 0x80077EAC: nop

            goto L_80077EC0;
    }
    // 0x80077EAC: nop

    // 0x80077EB0: jal         0x8005F064
    // 0x80077EB4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80077EB4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x80077EB8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077EBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80077EC0:
    // 0x80077EC0: b           L_80077ED0
    // 0x80077EC4: nop

        goto L_80077ED0;
    // 0x80077EC4: nop

    // 0x80077EC8: b           L_80077ED0
    // 0x80077ECC: nop

        goto L_80077ED0;
    // 0x80077ECC: nop

L_80077ED0:
    // 0x80077ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077ED8: jr          $ra
    // 0x80077EDC: nop

    return;
    // 0x80077EDC: nop

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
RECOMP_FUNC void func_80077F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077F18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077F1C: nop

    // 0x80077F20: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80077F24: nop

    // 0x80077F28: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077F2C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077F30: jr          $ra
    // 0x80077F34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077F34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077F38: jr          $ra
    // 0x80077F3C: nop

    return;
    // 0x80077F3C: nop

    // 0x80077F40: jr          $ra
    // 0x80077F44: nop

    return;
    // 0x80077F44: nop

;}
RECOMP_FUNC void func_80077F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077F4C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077F50: nop

    // 0x80077F54: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077F58: nop

    // 0x80077F5C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077F60: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077F64: jr          $ra
    // 0x80077F68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077F68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077F6C: jr          $ra
    // 0x80077F70: nop

    return;
    // 0x80077F70: nop

    // 0x80077F74: jr          $ra
    // 0x80077F78: nop

    return;
    // 0x80077F78: nop

;}
RECOMP_FUNC void func_80077F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077F80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077F84: nop

    // 0x80077F88: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80077F8C: nop

    // 0x80077F90: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077F94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077F98: jr          $ra
    // 0x80077F9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077F9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077FA0: jr          $ra
    // 0x80077FA4: nop

    return;
    // 0x80077FA4: nop

    // 0x80077FA8: jr          $ra
    // 0x80077FAC: nop

    return;
    // 0x80077FAC: nop

;}
RECOMP_FUNC void func_80077FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077FB8: jal         0x8005F064
    // 0x80077FBC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077FBC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077FC0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077FC4: b           L_80077FD4
    // 0x80077FC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077FD4;
    // 0x80077FC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077FCC: b           L_80077FD4
    // 0x80077FD0: nop

        goto L_80077FD4;
    // 0x80077FD0: nop

L_80077FD4:
    // 0x80077FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077FDC: jr          $ra
    // 0x80077FE0: nop

    return;
    // 0x80077FE0: nop

;}
RECOMP_FUNC void func_80077FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FE4: nop

    // 0x80077FE8: nop

    // 0x80077FEC: nop

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
RECOMP_FUNC void func_800780C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800780C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800780C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800780C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800780CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800780D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800780D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800780D8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800780DC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800780E0: lh          $t7, 0x14($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X14);
    // 0x800780E4: nop

    // 0x800780E8: bne         $t7, $at, L_800780F8
    if (ctx->r15 != ctx->r1) {
        // 0x800780EC: nop

            goto L_800780F8;
    }
    // 0x800780EC: nop

    // 0x800780F0: b           L_80078158
    // 0x800780F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078158;
    // 0x800780F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800780F8:
    // 0x800780F8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800780FC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80078100: lh          $a3, 0x14($t8)
    ctx->r7 = MEM_H(ctx->r24, 0X14);
    // 0x80078104: lw          $a2, 0xA0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XA0);
    // 0x80078108: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007810C: lhu         $t9, 0x42($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X42);
    // 0x80078110: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80078114: addiu       $a1, $t8, 0x20
    ctx->r5 = ADD32(ctx->r24, 0X20);
    // 0x80078118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007811C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80078120: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80078124: jal         0x80078628
    // 0x80078128: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80078628(rdram, ctx);
        goto after_0;
    // 0x80078128: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x8007812C: bne         $v0, $zero, L_80078148
    if (ctx->r2 != 0) {
        // 0x80078130: nop

            goto L_80078148;
    }
    // 0x80078130: nop

    // 0x80078134: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80078138: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8007813C: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x80078140: b           L_80078158
    // 0x80078144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078158;
    // 0x80078144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078148:
    // 0x80078148: b           L_80078158
    // 0x8007814C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078158;
    // 0x8007814C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078150: b           L_80078158
    // 0x80078154: nop

        goto L_80078158;
    // 0x80078154: nop

L_80078158:
    // 0x80078158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007815C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80078160: jr          $ra
    // 0x80078164: nop

    return;
    // 0x80078164: nop

;}
RECOMP_FUNC void func_80078168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078168: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007816C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80078170: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80078174: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80078178: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8007817C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80078180: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80078184: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80078188: jal         0x8009A3E8
    // 0x8007818C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_8009A3E8(rdram, ctx);
        goto after_0;
    // 0x8007818C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80078190: bgez        $v0, L_800781C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80078194: nop

            goto L_800781C0;
    }
    // 0x80078194: nop

    // 0x80078198: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007819C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800781A0: nop

    // 0x800781A4: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800781A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800781AC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800781B0: nop

    // 0x800781B4: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800781B8: b           L_80078298
    // 0x800781BC: nop

        goto L_80078298;
    // 0x800781BC: nop

L_800781C0:
    // 0x800781C0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800781C4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800781C8: lwc1        $f8, 0xCC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x800781CC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800781D0: lwc1        $f18, 0xD0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x800781D4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800781D8: lhu         $t9, 0x62($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X62);
    // 0x800781DC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800781E0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800781E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800781E8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800781EC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800781F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800781F4: jal         0x8007915C
    // 0x800781F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8007915C(rdram, ctx);
        goto after_1;
    // 0x800781F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x800781FC: jal         0x8001AB84
    // 0x80078200: nop

    func_8001AB84(rdram, ctx);
        goto after_2;
    // 0x80078200: nop

    after_2:
    // 0x80078204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80078208: jal         0x8008EAA8
    // 0x8007820C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x8007820C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80078210: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80078214: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80078218: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007821C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80078220: swc1        $f19, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x80078224: lwc1        $f4, 0xCC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x80078228: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007822C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80078230: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80078234: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80078238: swc1        $f7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x8007823C: lwc1        $f8, 0xD0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80078240: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80078244: mfc1        $a2, $f11
    ctx->r6 = (int32_t)ctx->f_odd[(11 - 1) * 2];
    // 0x80078248: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007824C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80078250: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80078254: swc1        $f11, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
    // 0x80078258: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8007825C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80078260: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80078264: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80078268: swc1        $f19, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x8007826C: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80078270: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80078274: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80078278: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8007827C: swc1        $f7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x80078280: jal         0x8008ECE4
    // 0x80078284: addiu       $a0, $a0, -0xE00
    ctx->r4 = ADD32(ctx->r4, -0XE00);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x80078284: addiu       $a0, $a0, -0xE00
    ctx->r4 = ADD32(ctx->r4, -0XE00);
    after_4:
    // 0x80078288: jal         0x8001AC74
    // 0x8007828C: nop

    func_8001AC74(rdram, ctx);
        goto after_5;
    // 0x8007828C: nop

    after_5:
    // 0x80078290: b           L_80078298
    // 0x80078294: nop

        goto L_80078298;
    // 0x80078294: nop

L_80078298:
    // 0x80078298: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007829C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800782A0: jr          $ra
    // 0x800782A4: nop

    return;
    // 0x800782A4: nop

;}
RECOMP_FUNC void func_800782A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800782A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800782AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800782B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800782B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800782B8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800782BC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800782C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800782C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800782C8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800782CC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800782D0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800782D4: nop

    // 0x800782D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800782DC: nop

    // 0x800782E0: bc1f        L_80078304
    if (!c1cs) {
        // 0x800782E4: nop

            goto L_80078304;
    }
    // 0x800782E4: nop

    // 0x800782E8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800782EC: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800782F0: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x800782F4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800782F8: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x800782FC: b           L_8007831C
    // 0x80078300: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
        goto L_8007831C;
    // 0x80078300: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
L_80078304:
    // 0x80078304: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80078308: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x8007830C: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80078310: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80078314: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x80078318: swc1        $f18, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f18.u32l;
L_8007831C:
    // 0x8007831C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80078320: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80078324: nop

    // 0x80078328: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8007832C: nop

    // 0x80078330: bc1f        L_80078354
    if (!c1cs) {
        // 0x80078334: nop

            goto L_80078354;
    }
    // 0x80078334: nop

    // 0x80078338: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007833C: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x80078340: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x80078344: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80078348: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x8007834C: b           L_8007836C
    // 0x80078350: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
        goto L_8007836C;
    // 0x80078350: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
L_80078354:
    // 0x80078354: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80078358: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x8007835C: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x80078360: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80078364: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x80078368: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
L_8007836C:
    // 0x8007836C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80078370: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80078374: nop

    // 0x80078378: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007837C: nop

    // 0x80078380: bne         $t7, $zero, L_80078390
    if (ctx->r15 != 0) {
        // 0x80078384: nop

            goto L_80078390;
    }
    // 0x80078384: nop

    // 0x80078388: b           L_800783DC
    // 0x8007838C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800783DC;
    // 0x8007838C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078390:
    // 0x80078390: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80078394: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80078398: lhu         $t8, 0x4E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4E);
    // 0x8007839C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800783A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800783A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800783A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800783AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800783B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800783B4: jal         0x80078628
    // 0x800783B8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80078628(rdram, ctx);
        goto after_0;
    // 0x800783B8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x800783BC: bne         $v0, $zero, L_800783CC
    if (ctx->r2 != 0) {
        // 0x800783C0: nop

            goto L_800783CC;
    }
    // 0x800783C0: nop

    // 0x800783C4: b           L_800783DC
    // 0x800783C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800783DC;
    // 0x800783C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800783CC:
    // 0x800783CC: b           L_800783DC
    // 0x800783D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800783DC;
    // 0x800783D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800783D4: b           L_800783DC
    // 0x800783D8: nop

        goto L_800783DC;
    // 0x800783D8: nop

L_800783DC:
    // 0x800783DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800783E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800783E4: jr          $ra
    // 0x800783E8: nop

    return;
    // 0x800783E8: nop

;}
RECOMP_FUNC void func_800783EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800783EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800783F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800783F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800783F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800783FC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80078400: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80078404: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80078408: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8007840C: lh          $t7, 0x14($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X14);
    // 0x80078410: nop

    // 0x80078414: bne         $t7, $at, L_80078424
    if (ctx->r15 != ctx->r1) {
        // 0x80078418: nop

            goto L_80078424;
    }
    // 0x80078418: nop

    // 0x8007841C: b           L_80078484
    // 0x80078420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078484;
    // 0x80078420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078424:
    // 0x80078424: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80078428: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007842C: lh          $a3, 0x14($t8)
    ctx->r7 = MEM_H(ctx->r24, 0X14);
    // 0x80078430: lw          $a2, 0xA0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XA0);
    // 0x80078434: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80078438: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x8007843C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80078440: addiu       $a1, $t8, 0x20
    ctx->r5 = ADD32(ctx->r24, 0X20);
    // 0x80078444: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80078448: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007844C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80078450: jal         0x80078628
    // 0x80078454: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80078628(rdram, ctx);
        goto after_0;
    // 0x80078454: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x80078458: bne         $v0, $zero, L_80078474
    if (ctx->r2 != 0) {
        // 0x8007845C: nop

            goto L_80078474;
    }
    // 0x8007845C: nop

    // 0x80078460: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80078464: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80078468: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x8007846C: b           L_80078484
    // 0x80078470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078484;
    // 0x80078470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078474:
    // 0x80078474: b           L_80078484
    // 0x80078478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078484;
    // 0x80078478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007847C: b           L_80078484
    // 0x80078480: nop

        goto L_80078484;
    // 0x80078480: nop

L_80078484:
    // 0x80078484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078488: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007848C: jr          $ra
    // 0x80078490: nop

    return;
    // 0x80078490: nop

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
RECOMP_FUNC void func_800784E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800784E8: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800784EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800784F0: sw          $a0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r4;
    // 0x800784F4: sw          $a1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r5;
    // 0x800784F8: sw          $a2, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r6;
    // 0x800784FC: sw          $a3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r7;
    // 0x80078500: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    // 0x80078504: lw          $a2, 0x140($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X140);
    // 0x80078508: lw          $a3, 0x144($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X144);
    // 0x8007850C: jal         0x800B35D4
    // 0x80078510: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    func_800B35D4(rdram, ctx);
        goto after_0;
    // 0x80078510: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    after_0:
    // 0x80078514: sw          $v0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r2;
    // 0x80078518: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x8007851C: nop

    // 0x80078520: bne         $t6, $zero, L_80078530
    if (ctx->r14 != 0) {
        // 0x80078524: nop

            goto L_80078530;
    }
    // 0x80078524: nop

    // 0x80078528: b           L_80078618
    // 0x8007852C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078618;
    // 0x8007852C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078530:
    // 0x80078530: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x80078534: lw          $a2, 0x150($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X150);
    // 0x80078538: lw          $a3, 0x154($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X154);
    // 0x8007853C: jal         0x800B35D4
    // 0x80078540: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800B35D4(rdram, ctx);
        goto after_1;
    // 0x80078540: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80078544: sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    // 0x80078548: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x8007854C: nop

    // 0x80078550: bne         $t7, $zero, L_80078560
    if (ctx->r15 != 0) {
        // 0x80078554: nop

            goto L_80078560;
    }
    // 0x80078554: nop

    // 0x80078558: b           L_80078618
    // 0x8007855C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078618;
    // 0x8007855C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078560:
    // 0x80078560: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x80078564: lw          $a1, 0x134($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X134);
    // 0x80078568: addiu       $t9, $sp, 0x128
    ctx->r25 = ADD32(ctx->r29, 0X128);
    // 0x8007856C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80078570: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80078574: addiu       $a2, $sp, 0x12C
    ctx->r6 = ADD32(ctx->r29, 0X12C);
    // 0x80078578: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8007857C: jal         0x80078A8C
    // 0x80078580: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80078A8C(rdram, ctx);
        goto after_2;
    // 0x80078580: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x80078584: beq         $v0, $zero, L_80078608
    if (ctx->r2 == 0) {
        // 0x80078588: nop

            goto L_80078608;
    }
    // 0x80078588: nop

    // 0x8007858C: sw          $zero, 0x124($sp)
    MEM_W(0X124, ctx->r29) = 0;
L_80078590:
    // 0x80078590: lw          $t0, 0x12C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X12C);
    // 0x80078594: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80078598: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007859C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800785A0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800785A4: lw          $t6, 0x138($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X138);
    // 0x800785A8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800785AC: lwc1        $f4, 0xA4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XA4);
    // 0x800785B0: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800785B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800785B8: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800785BC: lw          $t9, 0x128($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X128);
    // 0x800785C0: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800785C4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800785C8: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800785CC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800785D0: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x800785D4: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800785D8: lwc1        $f6, 0x24($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X24);
    // 0x800785DC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x800785E0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x800785E4: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800785E8: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x800785EC: nop

    // 0x800785F0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800785F4: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800785F8: bne         $at, $zero, L_80078590
    if (ctx->r1 != 0) {
        // 0x800785FC: sw          $t9, 0x124($sp)
        MEM_W(0X124, ctx->r29) = ctx->r25;
            goto L_80078590;
    }
    // 0x800785FC: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80078600: b           L_80078618
    // 0x80078604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078618;
    // 0x80078604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80078608:
    // 0x80078608: b           L_80078618
    // 0x8007860C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078618;
    // 0x8007860C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80078610: b           L_80078618
    // 0x80078614: nop

        goto L_80078618;
    // 0x80078614: nop

L_80078618:
    // 0x80078618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007861C: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x80078620: jr          $ra
    // 0x80078624: nop

    return;
    // 0x80078624: nop

;}
RECOMP_FUNC void func_80078628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078628: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x8007862C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80078630: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x80078634: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    // 0x80078638: sw          $a2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r6;
    // 0x8007863C: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x80078640: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80078644: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80078648: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8007864C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80078650: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80078654: nop

    // 0x80078658: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007865C: nop

    // 0x80078660: bne         $t7, $zero, L_80078670
    if (ctx->r15 != 0) {
        // 0x80078664: nop

            goto L_80078670;
    }
    // 0x80078664: nop

    // 0x80078668: b           L_80078A7C
    // 0x8007866C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078A7C;
    // 0x8007866C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078670:
    // 0x80078670: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80078674: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80078678: lh          $t0, 0x106($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X106);
    // 0x8007867C: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x80078680: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80078684: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80078688: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8007868C: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80078690: lh          $t4, 0x106($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X106);
    // 0x80078694: nop

    // 0x80078698: sh          $t4, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r12;
L_8007869C:
    // 0x8007869C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800786A0:
    // 0x800786A0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800786A4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800786A8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800786AC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800786B0: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x800786B4: sh          $t6, 0x50($t0)
    MEM_H(0X50, ctx->r8) = ctx->r14;
    // 0x800786B8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800786BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800786C0: bne         $t1, $at, L_800786FC
    if (ctx->r9 != ctx->r1) {
        // 0x800786C4: nop

            goto L_800786FC;
    }
    // 0x800786C4: nop

    // 0x800786C8: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x800786CC: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x800786D0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800786D4: bne         $t2, $at, L_800786FC
    if (ctx->r10 != ctx->r1) {
        // 0x800786D8: nop

            goto L_800786FC;
    }
    // 0x800786D8: nop

    // 0x800786DC: lhu         $t3, 0x2($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X2);
    // 0x800786E0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800786E4: bne         $t3, $at, L_800786FC
    if (ctx->r11 != ctx->r1) {
        // 0x800786E8: nop

            goto L_800786FC;
    }
    // 0x800786E8: nop

    // 0x800786EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800786F0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800786F4: b           L_8007871C
    // 0x800786F8: nop

        goto L_8007871C;
    // 0x800786F8: nop

L_800786FC:
    // 0x800786FC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80078700: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80078704: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80078708: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x8007870C: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x80078710: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80078714: bne         $at, $zero, L_800786A0
    if (ctx->r1 != 0) {
        // 0x80078718: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_800786A0;
    }
    // 0x80078718: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_8007871C:
    // 0x8007871C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80078720: nop

    // 0x80078724: beq         $t0, $zero, L_80078734
    if (ctx->r8 == 0) {
        // 0x80078728: nop

            goto L_80078734;
    }
    // 0x80078728: nop

    // 0x8007872C: b           L_80078A30
    // 0x80078730: nop

        goto L_80078A30;
    // 0x80078730: nop

L_80078734:
    // 0x80078734: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x80078738: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8007873C: nop

    // 0x80078740: andi        $t9, $t2, 0x8000
    ctx->r25 = ctx->r10 & 0X8000;
    // 0x80078744: beq         $t9, $zero, L_80078754
    if (ctx->r25 == 0) {
        // 0x80078748: nop

            goto L_80078754;
    }
    // 0x80078748: nop

    // 0x8007874C: b           L_80078A1C
    // 0x80078750: nop

        goto L_80078A1C;
    // 0x80078750: nop

L_80078754:
    // 0x80078754: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80078758: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x8007875C: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80078760: nop

    // 0x80078764: andi        $t5, $t4, 0xFF00
    ctx->r13 = ctx->r12 & 0XFF00;
    // 0x80078768: sh          $t5, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r13;
    // 0x8007876C: lhu         $s0, 0x3E($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X3E);
    // 0x80078770: nop

    // 0x80078774: beq         $s0, $zero, L_8007879C
    if (ctx->r16 == 0) {
        // 0x80078778: nop

            goto L_8007879C;
    }
    // 0x80078778: nop

    // 0x8007877C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80078780: beq         $s0, $at, L_800787C0
    if (ctx->r16 == ctx->r1) {
        // 0x80078784: nop

            goto L_800787C0;
    }
    // 0x80078784: nop

    // 0x80078788: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8007878C: beq         $s0, $at, L_800787E4
    if (ctx->r16 == ctx->r1) {
        // 0x80078790: nop

            goto L_800787E4;
    }
    // 0x80078790: nop

    // 0x80078794: b           L_80078808
    // 0x80078798: nop

        goto L_80078808;
    // 0x80078798: nop

L_8007879C:
    // 0x8007879C: lhu         $t6, 0x112($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X112);
    // 0x800787A0: nop

    // 0x800787A4: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800787A8: beq         $t8, $zero, L_800787B8
    if (ctx->r24 == 0) {
        // 0x800787AC: nop

            goto L_800787B8;
    }
    // 0x800787AC: nop

    // 0x800787B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800787B4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800787B8:
    // 0x800787B8: b           L_80078808
    // 0x800787BC: nop

        goto L_80078808;
    // 0x800787BC: nop

L_800787C0:
    // 0x800787C0: lhu         $t0, 0x112($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X112);
    // 0x800787C4: nop

    // 0x800787C8: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800787CC: beq         $t1, $zero, L_800787DC
    if (ctx->r9 == 0) {
        // 0x800787D0: nop

            goto L_800787DC;
    }
    // 0x800787D0: nop

    // 0x800787D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800787D8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800787DC:
    // 0x800787DC: b           L_80078808
    // 0x800787E0: nop

        goto L_80078808;
    // 0x800787E0: nop

L_800787E4:
    // 0x800787E4: lhu         $t9, 0x112($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X112);
    // 0x800787E8: nop

    // 0x800787EC: andi        $t3, $t9, 0x4
    ctx->r11 = ctx->r25 & 0X4;
    // 0x800787F0: beq         $t3, $zero, L_80078800
    if (ctx->r11 == 0) {
        // 0x800787F4: nop

            goto L_80078800;
    }
    // 0x800787F4: nop

    // 0x800787F8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800787FC: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80078800:
    // 0x80078800: b           L_80078808
    // 0x80078804: nop

        goto L_80078808;
    // 0x80078804: nop

L_80078808:
    // 0x80078808: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8007880C: nop

    // 0x80078810: bne         $t5, $zero, L_80078820
    if (ctx->r13 != 0) {
        // 0x80078814: nop

            goto L_80078820;
    }
    // 0x80078814: nop

    // 0x80078818: b           L_80078A1C
    // 0x8007881C: nop

        goto L_80078A1C;
    // 0x8007881C: nop

L_80078820:
    // 0x80078820: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x80078824: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x80078828: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x8007882C: nop

    // 0x80078830: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80078834: beq         $at, $zero, L_80078878
    if (ctx->r1 == 0) {
        // 0x80078838: nop

            goto L_80078878;
    }
    // 0x80078838: nop

    // 0x8007883C: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x80078840: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80078844: addiu       $t2, $sp, 0xE4
    ctx->r10 = ADD32(ctx->r29, 0XE4);
    // 0x80078848: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8007884C: nop

    // 0x80078850: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078854: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80078858: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x8007885C: lh          $t3, 0x4($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X4);
    // 0x80078860: addiu       $t4, $sp, 0xE4
    ctx->r12 = ADD32(ctx->r29, 0XE4);
    // 0x80078864: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80078868: nop

    // 0x8007886C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80078870: b           L_800788B0
    // 0x80078874: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
        goto L_800788B0;
    // 0x80078874: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
L_80078878:
    // 0x80078878: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x8007887C: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80078880: addiu       $t8, $sp, 0xE4
    ctx->r24 = ADD32(ctx->r29, 0XE4);
    // 0x80078884: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80078888: nop

    // 0x8007888C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80078890: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x80078894: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x80078898: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x8007889C: addiu       $t1, $sp, 0xE4
    ctx->r9 = ADD32(ctx->r29, 0XE4);
    // 0x800788A0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800788A4: nop

    // 0x800788A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800788AC: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
L_800788B0:
    // 0x800788B0: addiu       $t2, $sp, 0x50
    ctx->r10 = ADD32(ctx->r29, 0X50);
    // 0x800788B4: lh          $t9, 0x2($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X2);
    // 0x800788B8: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x800788BC: nop

    // 0x800788C0: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800788C4: beq         $at, $zero, L_80078908
    if (ctx->r1 == 0) {
        // 0x800788C8: nop

            goto L_80078908;
    }
    // 0x800788C8: nop

    // 0x800788CC: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x800788D0: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x800788D4: addiu       $t6, $sp, 0xE4
    ctx->r14 = ADD32(ctx->r29, 0XE4);
    // 0x800788D8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800788DC: nop

    // 0x800788E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800788E4: swc1        $f10, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f10.u32l;
    // 0x800788E8: addiu       $t8, $sp, 0x50
    ctx->r24 = ADD32(ctx->r29, 0X50);
    // 0x800788EC: lh          $t7, 0x6($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X6);
    // 0x800788F0: addiu       $t0, $sp, 0xE4
    ctx->r8 = ADD32(ctx->r29, 0XE4);
    // 0x800788F4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800788F8: nop

    // 0x800788FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80078900: b           L_80078940
    // 0x80078904: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
        goto L_80078940;
    // 0x80078904: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
L_80078908:
    // 0x80078908: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x8007890C: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x80078910: addiu       $t9, $sp, 0xE4
    ctx->r25 = ADD32(ctx->r29, 0XE4);
    // 0x80078914: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80078918: nop

    // 0x8007891C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078920: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x80078924: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x80078928: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x8007892C: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
    // 0x80078930: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80078934: nop

    // 0x80078938: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007893C: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
L_80078940:
    // 0x80078940: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80078944: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80078948: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8007894C: blez        $t8, L_800789E0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80078950: nop

            goto L_800789E0;
    }
    // 0x80078950: nop

L_80078954:
    // 0x80078954: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80078958: nop

    // 0x8007895C: bgez        $t7, L_80078970
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80078960: andi        $t0, $t7, 0x1
        ctx->r8 = ctx->r15 & 0X1;
            goto L_80078970;
    }
    // 0x80078960: andi        $t0, $t7, 0x1
    ctx->r8 = ctx->r15 & 0X1;
    // 0x80078964: beq         $t0, $zero, L_80078970
    if (ctx->r8 == 0) {
        // 0x80078968: nop

            goto L_80078970;
    }
    // 0x80078968: nop

    // 0x8007896C: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_80078970:
    // 0x80078970: bne         $t0, $zero, L_800789A0
    if (ctx->r8 != 0) {
        // 0x80078974: nop

            goto L_800789A0;
    }
    // 0x80078974: nop

    // 0x80078978: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8007897C: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x80078980: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80078984: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x80078988: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8007898C: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80078990: addu        $t4, $sp, $t9
    ctx->r12 = ADD32(ctx->r29, ctx->r25);
    // 0x80078994: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80078998: b           L_800789C4
    // 0x8007899C: swc1        $f4, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f4.u32l;
        goto L_800789C4;
    // 0x8007899C: swc1        $f4, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f4.u32l;
L_800789A0:
    // 0x800789A0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800789A4: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x800789A8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800789AC: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800789B0: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800789B4: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800789B8: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x800789BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800789C0: swc1        $f10, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f10.u32l;
L_800789C4:
    // 0x800789C4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800789C8: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x800789CC: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800789D0: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800789D4: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800789D8: bne         $at, $zero, L_80078954
    if (ctx->r1 != 0) {
        // 0x800789DC: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_80078954;
    }
    // 0x800789DC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
L_800789E0:
    // 0x800789E0: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x800789E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800789E8: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x800789EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800789F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800789F4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800789F8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800789FC: jal         0x80078A8C
    // 0x80078A00: addiu       $a3, $sp, 0xE4
    ctx->r7 = ADD32(ctx->r29, 0XE4);
    func_80078A8C(rdram, ctx);
        goto after_0;
    // 0x80078A00: addiu       $a3, $sp, 0xE4
    ctx->r7 = ADD32(ctx->r29, 0XE4);
    after_0:
    // 0x80078A04: beq         $v0, $zero, L_80078A1C
    if (ctx->r2 == 0) {
        // 0x80078A08: nop

            goto L_80078A1C;
    }
    // 0x80078A08: nop

    // 0x80078A0C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80078A10: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80078A14: b           L_80078A30
    // 0x80078A18: nop

        goto L_80078A30;
    // 0x80078A18: nop

L_80078A1C:
    // 0x80078A1C: lh          $t7, 0xF6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XF6);
    // 0x80078A20: nop

    // 0x80078A24: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80078A28: b           L_8007869C
    // 0x80078A2C: sh          $t8, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r24;
        goto L_8007869C;
    // 0x80078A2C: sh          $t8, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r24;
L_80078A30:
    // 0x80078A30: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80078A34: nop

    // 0x80078A38: bne         $t0, $zero, L_80078A48
    if (ctx->r8 != 0) {
        // 0x80078A3C: nop

            goto L_80078A48;
    }
    // 0x80078A3C: nop

    // 0x80078A40: b           L_80078A7C
    // 0x80078A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078A7C;
    // 0x80078A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078A48:
    // 0x80078A48: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x80078A4C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80078A50: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x80078A54: lh          $a2, 0xF6($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XF6);
    // 0x80078A58: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    // 0x80078A5C: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    // 0x80078A60: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80078A64: jal         0x80079404
    // 0x80078A68: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_80079404(rdram, ctx);
        goto after_1;
    // 0x80078A68: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_1:
    // 0x80078A6C: b           L_80078A7C
    // 0x80078A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078A7C;
    // 0x80078A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078A74: b           L_80078A7C
    // 0x80078A78: nop

        goto L_80078A7C;
    // 0x80078A78: nop

L_80078A7C:
    // 0x80078A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078A80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80078A84: jr          $ra
    // 0x80078A88: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80078A88: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80078A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078A90: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80078A94: blez        $a1, L_80079114
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80078A98: sw          $zero, 0x14($sp)
        MEM_W(0X14, ctx->r29) = 0;
            goto L_80079114;
    }
    // 0x80078A98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80078A9C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80078AA0: nop

    // 0x80078AA4: bne         $t6, $zero, L_80079114
    if (ctx->r14 != 0) {
        // 0x80078AA8: nop

            goto L_80079114;
    }
    // 0x80078AA8: nop

L_80078AAC:
    // 0x80078AAC: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80078AB0: nop

    // 0x80078AB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80078AB8: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x80078ABC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80078AC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80078AC4: blez        $t9, L_800790D4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80078AC8: nop

            goto L_800790D4;
    }
    // 0x80078AC8: nop

    // 0x80078ACC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80078AD0: nop

    // 0x80078AD4: bne         $t0, $zero, L_800790D4
    if (ctx->r8 != 0) {
        // 0x80078AD8: nop

            goto L_800790D4;
    }
    // 0x80078AD8: nop

L_80078ADC:
    // 0x80078ADC: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x80078AE0: nop

    // 0x80078AE4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80078AE8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x80078AEC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x80078AF0: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80078AF4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80078AF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80078AFC: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80078B00: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80078B04: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80078B08: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80078B0C: nop

    // 0x80078B10: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078B14: nop

    // 0x80078B18: bc1f        L_80078B44
    if (!c1cs) {
        // 0x80078B1C: nop

            goto L_80078B44;
    }
    // 0x80078B1C: nop

    // 0x80078B20: addu        $t9, $a0, $t4
    ctx->r25 = ADD32(ctx->r4, ctx->r12);
    // 0x80078B24: addu        $t0, $a3, $t7
    ctx->r8 = ADD32(ctx->r7, ctx->r15);
    // 0x80078B28: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80078B2C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80078B30: nop

    // 0x80078B34: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078B38: nop

    // 0x80078B3C: bc1t        L_80078B9C
    if (c1cs) {
        // 0x80078B40: nop

            goto L_80078B9C;
    }
    // 0x80078B40: nop

L_80078B44:
    // 0x80078B44: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80078B48: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x80078B4C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80078B50: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80078B54: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x80078B58: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80078B5C: lwc1        $f16, 0x8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80078B60: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80078B64: nop

    // 0x80078B68: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078B6C: nop

    // 0x80078B70: bc1f        L_80078C5C
    if (!c1cs) {
        // 0x80078B74: nop

            goto L_80078C5C;
    }
    // 0x80078B74: nop

    // 0x80078B78: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x80078B7C: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x80078B80: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80078B84: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80078B88: nop

    // 0x80078B8C: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078B90: nop

    // 0x80078B94: bc1f        L_80078C5C
    if (!c1cs) {
        // 0x80078B98: nop

            goto L_80078C5C;
    }
    // 0x80078B98: nop

L_80078B9C:
    // 0x80078B9C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80078BA0: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80078BA4: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80078BA8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80078BAC: addu        $t8, $a3, $t5
    ctx->r24 = ADD32(ctx->r7, ctx->r13);
    // 0x80078BB0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80078BB4: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80078BB8: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80078BBC: nop

    // 0x80078BC0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80078BC4: nop

    // 0x80078BC8: bc1f        L_80078BF4
    if (!c1cs) {
        // 0x80078BCC: nop

            goto L_80078BF4;
    }
    // 0x80078BCC: nop

    // 0x80078BD0: addu        $t2, $a0, $t0
    ctx->r10 = ADD32(ctx->r4, ctx->r8);
    // 0x80078BD4: addu        $t4, $a3, $t5
    ctx->r12 = ADD32(ctx->r7, ctx->r13);
    // 0x80078BD8: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80078BDC: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80078BE0: nop

    // 0x80078BE4: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80078BE8: nop

    // 0x80078BEC: bc1t        L_80078C4C
    if (c1cs) {
        // 0x80078BF0: nop

            goto L_80078C4C;
    }
    // 0x80078BF0: nop

L_80078BF4:
    // 0x80078BF4: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80078BF8: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80078BFC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80078C00: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80078C04: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x80078C08: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x80078C0C: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80078C10: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80078C14: nop

    // 0x80078C18: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078C1C: nop

    // 0x80078C20: bc1f        L_80078C5C
    if (!c1cs) {
        // 0x80078C24: nop

            goto L_80078C5C;
    }
    // 0x80078C24: nop

    // 0x80078C28: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80078C2C: addu        $t2, $a3, $t3
    ctx->r10 = ADD32(ctx->r7, ctx->r11);
    // 0x80078C30: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80078C34: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80078C38: nop

    // 0x80078C3C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078C40: nop

    // 0x80078C44: bc1f        L_80078C5C
    if (!c1cs) {
        // 0x80078C48: nop

            goto L_80078C5C;
    }
    // 0x80078C48: nop

L_80078C4C:
    // 0x80078C4C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80078C50: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80078C54: b           L_800790D4
    // 0x80078C58: nop

        goto L_800790D4;
    // 0x80078C58: nop

L_80078C5C:
    // 0x80078C5C: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x80078C60: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80078C64: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80078C68: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80078C6C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80078C70: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80078C74: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80078C78: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80078C7C: nop

    // 0x80078C80: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078C84: nop

    // 0x80078C88: bc1f        L_80078CB4
    if (!c1cs) {
        // 0x80078C8C: nop

            goto L_80078CB4;
    }
    // 0x80078C8C: nop

    // 0x80078C90: addu        $t0, $a3, $t6
    ctx->r8 = ADD32(ctx->r7, ctx->r14);
    // 0x80078C94: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x80078C98: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80078C9C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80078CA0: nop

    // 0x80078CA4: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078CA8: nop

    // 0x80078CAC: bc1t        L_80078D0C
    if (c1cs) {
        // 0x80078CB0: nop

            goto L_80078D0C;
    }
    // 0x80078CB0: nop

L_80078CB4:
    // 0x80078CB4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80078CB8: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80078CBC: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80078CC0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80078CC4: addu        $t9, $a0, $t1
    ctx->r25 = ADD32(ctx->r4, ctx->r9);
    // 0x80078CC8: addu        $t4, $a3, $t5
    ctx->r12 = ADD32(ctx->r7, ctx->r13);
    // 0x80078CCC: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80078CD0: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80078CD4: nop

    // 0x80078CD8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80078CDC: nop

    // 0x80078CE0: bc1f        L_80078DCC
    if (!c1cs) {
        // 0x80078CE4: nop

            goto L_80078DCC;
    }
    // 0x80078CE4: nop

    // 0x80078CE8: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80078CEC: addu        $t0, $a0, $t1
    ctx->r8 = ADD32(ctx->r4, ctx->r9);
    // 0x80078CF0: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80078CF4: lwc1        $f16, 0x8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80078CF8: nop

    // 0x80078CFC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80078D00: nop

    // 0x80078D04: bc1f        L_80078DCC
    if (!c1cs) {
        // 0x80078D08: nop

            goto L_80078DCC;
    }
    // 0x80078D08: nop

L_80078D0C:
    // 0x80078D0C: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80078D10: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x80078D14: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80078D18: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80078D1C: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x80078D20: addu        $t2, $a3, $t3
    ctx->r10 = ADD32(ctx->r7, ctx->r11);
    // 0x80078D24: lwc1        $f4, 0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80078D28: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80078D2C: nop

    // 0x80078D30: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078D34: nop

    // 0x80078D38: bc1f        L_80078D64
    if (!c1cs) {
        // 0x80078D3C: nop

            goto L_80078D64;
    }
    // 0x80078D3C: nop

    // 0x80078D40: addu        $t5, $a3, $t3
    ctx->r13 = ADD32(ctx->r7, ctx->r11);
    // 0x80078D44: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x80078D48: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80078D4C: lwc1        $f8, 0x4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80078D50: nop

    // 0x80078D54: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078D58: nop

    // 0x80078D5C: bc1t        L_80078DBC
    if (c1cs) {
        // 0x80078D60: nop

            goto L_80078DBC;
    }
    // 0x80078D60: nop

L_80078D64:
    // 0x80078D64: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80078D68: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80078D6C: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80078D70: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80078D74: addu        $t9, $a0, $t4
    ctx->r25 = ADD32(ctx->r4, ctx->r12);
    // 0x80078D78: addu        $t8, $a3, $t0
    ctx->r24 = ADD32(ctx->r7, ctx->r8);
    // 0x80078D7C: lwc1        $f16, 0xC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80078D80: lwc1        $f18, 0x4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80078D84: nop

    // 0x80078D88: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078D8C: nop

    // 0x80078D90: bc1f        L_80078DCC
    if (!c1cs) {
        // 0x80078D94: nop

            goto L_80078DCC;
    }
    // 0x80078D94: nop

    // 0x80078D98: addu        $t3, $a3, $t0
    ctx->r11 = ADD32(ctx->r7, ctx->r8);
    // 0x80078D9C: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80078DA0: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80078DA4: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80078DA8: nop

    // 0x80078DAC: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078DB0: nop

    // 0x80078DB4: bc1f        L_80078DCC
    if (!c1cs) {
        // 0x80078DB8: nop

            goto L_80078DCC;
    }
    // 0x80078DB8: nop

L_80078DBC:
    // 0x80078DBC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80078DC0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80078DC4: b           L_800790D4
    // 0x80078DC8: nop

        goto L_800790D4;
    // 0x80078DC8: nop

L_80078DCC:
    // 0x80078DCC: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80078DD0: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80078DD4: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80078DD8: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80078DDC: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x80078DE0: addu        $t8, $a0, $t1
    ctx->r24 = ADD32(ctx->r4, ctx->r9);
    // 0x80078DE4: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80078DE8: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80078DEC: nop

    // 0x80078DF0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80078DF4: nop

    // 0x80078DF8: bc1f        L_80078E24
    if (!c1cs) {
        // 0x80078DFC: nop

            goto L_80078E24;
    }
    // 0x80078DFC: nop

    // 0x80078E00: addu        $t3, $a0, $t1
    ctx->r11 = ADD32(ctx->r4, ctx->r9);
    // 0x80078E04: addu        $t4, $a3, $t9
    ctx->r12 = ADD32(ctx->r7, ctx->r25);
    // 0x80078E08: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80078E0C: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80078E10: nop

    // 0x80078E14: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80078E18: nop

    // 0x80078E1C: bc1t        L_80078E7C
    if (c1cs) {
        // 0x80078E20: nop

            goto L_80078E7C;
    }
    // 0x80078E20: nop

L_80078E24:
    // 0x80078E24: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80078E28: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80078E2C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80078E30: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80078E34: addu        $t0, $a3, $t2
    ctx->r8 = ADD32(ctx->r7, ctx->r10);
    // 0x80078E38: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x80078E3C: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80078E40: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80078E44: nop

    // 0x80078E48: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078E4C: nop

    // 0x80078E50: bc1f        L_80078F3C
    if (!c1cs) {
        // 0x80078E54: nop

            goto L_80078F3C;
    }
    // 0x80078E54: nop

    // 0x80078E58: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x80078E5C: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x80078E60: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80078E64: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80078E68: nop

    // 0x80078E6C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078E70: nop

    // 0x80078E74: bc1f        L_80078F3C
    if (!c1cs) {
        // 0x80078E78: nop

            goto L_80078F3C;
    }
    // 0x80078E78: nop

L_80078E7C:
    // 0x80078E7C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80078E80: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80078E84: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80078E88: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078E8C: addu        $t0, $a0, $t8
    ctx->r8 = ADD32(ctx->r4, ctx->r24);
    // 0x80078E90: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x80078E94: lwc1        $f16, 0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80078E98: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80078E9C: nop

    // 0x80078EA0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078EA4: nop

    // 0x80078EA8: bc1f        L_80078ED4
    if (!c1cs) {
        // 0x80078EAC: nop

            goto L_80078ED4;
    }
    // 0x80078EAC: nop

    // 0x80078EB0: addu        $t7, $a3, $t4
    ctx->r15 = ADD32(ctx->r7, ctx->r12);
    // 0x80078EB4: addu        $t1, $a0, $t8
    ctx->r9 = ADD32(ctx->r4, ctx->r24);
    // 0x80078EB8: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80078EBC: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80078EC0: nop

    // 0x80078EC4: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078EC8: nop

    // 0x80078ECC: bc1t        L_80078F2C
    if (c1cs) {
        // 0x80078ED0: nop

            goto L_80078F2C;
    }
    // 0x80078ED0: nop

L_80078ED4:
    // 0x80078ED4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80078ED8: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80078EDC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80078EE0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80078EE4: addu        $t0, $a0, $t6
    ctx->r8 = ADD32(ctx->r4, ctx->r14);
    // 0x80078EE8: addu        $t9, $a3, $t3
    ctx->r25 = ADD32(ctx->r7, ctx->r11);
    // 0x80078EEC: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80078EF0: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80078EF4: nop

    // 0x80078EF8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80078EFC: nop

    // 0x80078F00: bc1f        L_80078F3C
    if (!c1cs) {
        // 0x80078F04: nop

            goto L_80078F3C;
    }
    // 0x80078F04: nop

    // 0x80078F08: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80078F0C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80078F10: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80078F14: lwc1        $f16, 0xC($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80078F18: nop

    // 0x80078F1C: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80078F20: nop

    // 0x80078F24: bc1f        L_80078F3C
    if (!c1cs) {
        // 0x80078F28: nop

            goto L_80078F3C;
    }
    // 0x80078F28: nop

L_80078F2C:
    // 0x80078F2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80078F30: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80078F34: b           L_800790D4
    // 0x80078F38: nop

        goto L_800790D4;
    // 0x80078F38: nop

L_80078F3C:
    // 0x80078F3C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80078F40: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80078F44: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80078F48: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80078F4C: addu        $t3, $a0, $t0
    ctx->r11 = ADD32(ctx->r4, ctx->r8);
    // 0x80078F50: addu        $t9, $a3, $t2
    ctx->r25 = ADD32(ctx->r7, ctx->r10);
    // 0x80078F54: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80078F58: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80078F5C: nop

    // 0x80078F60: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078F64: nop

    // 0x80078F68: bc1f        L_80078F94
    if (!c1cs) {
        // 0x80078F6C: nop

            goto L_80078F94;
    }
    // 0x80078F6C: nop

    // 0x80078F70: addu        $t4, $a3, $t2
    ctx->r12 = ADD32(ctx->r7, ctx->r10);
    // 0x80078F74: addu        $t6, $a0, $t0
    ctx->r14 = ADD32(ctx->r4, ctx->r8);
    // 0x80078F78: lwc1        $f10, 0x8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80078F7C: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80078F80: nop

    // 0x80078F84: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078F88: nop

    // 0x80078F8C: bc1t        L_80078FEC
    if (c1cs) {
        // 0x80078F90: nop

            goto L_80078FEC;
    }
    // 0x80078F90: nop

L_80078F94:
    // 0x80078F94: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80078F98: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80078F9C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80078FA0: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80078FA4: addu        $t3, $a0, $t5
    ctx->r11 = ADD32(ctx->r4, ctx->r13);
    // 0x80078FA8: addu        $t1, $a3, $t8
    ctx->r9 = ADD32(ctx->r7, ctx->r24);
    // 0x80078FAC: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80078FB0: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80078FB4: nop

    // 0x80078FB8: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078FBC: nop

    // 0x80078FC0: bc1f        L_800790AC
    if (!c1cs) {
        // 0x80078FC4: nop

            goto L_800790AC;
    }
    // 0x80078FC4: nop

    // 0x80078FC8: addu        $t2, $a3, $t8
    ctx->r10 = ADD32(ctx->r7, ctx->r24);
    // 0x80078FCC: addu        $t4, $a0, $t5
    ctx->r12 = ADD32(ctx->r4, ctx->r13);
    // 0x80078FD0: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80078FD4: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80078FD8: nop

    // 0x80078FDC: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078FE0: nop

    // 0x80078FE4: bc1f        L_800790AC
    if (!c1cs) {
        // 0x80078FE8: nop

            goto L_800790AC;
    }
    // 0x80078FE8: nop

L_80078FEC:
    // 0x80078FEC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80078FF0: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80078FF4: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80078FF8: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x80078FFC: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x80079000: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80079004: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80079008: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8007900C: nop

    // 0x80079010: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80079014: nop

    // 0x80079018: bc1f        L_80079044
    if (!c1cs) {
        // 0x8007901C: nop

            goto L_80079044;
    }
    // 0x8007901C: nop

    // 0x80079020: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x80079024: addu        $t2, $a3, $t9
    ctx->r10 = ADD32(ctx->r7, ctx->r25);
    // 0x80079028: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8007902C: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80079030: nop

    // 0x80079034: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80079038: nop

    // 0x8007903C: bc1t        L_8007909C
    if (c1cs) {
        // 0x80079040: nop

            goto L_8007909C;
    }
    // 0x80079040: nop

L_80079044:
    // 0x80079044: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80079048: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8007904C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80079050: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80079054: addu        $t3, $a3, $t1
    ctx->r11 = ADD32(ctx->r7, ctx->r9);
    // 0x80079058: addu        $t0, $a0, $t4
    ctx->r8 = ADD32(ctx->r4, ctx->r12);
    // 0x8007905C: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80079060: lwc1        $f6, 0x4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80079064: nop

    // 0x80079068: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8007906C: nop

    // 0x80079070: bc1f        L_800790AC
    if (!c1cs) {
        // 0x80079074: nop

            goto L_800790AC;
    }
    // 0x80079074: nop

    // 0x80079078: addu        $t6, $a0, $t4
    ctx->r14 = ADD32(ctx->r4, ctx->r12);
    // 0x8007907C: addu        $t8, $a3, $t1
    ctx->r24 = ADD32(ctx->r7, ctx->r9);
    // 0x80079080: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80079084: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80079088: nop

    // 0x8007908C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80079090: nop

    // 0x80079094: bc1f        L_800790AC
    if (!c1cs) {
        // 0x80079098: nop

            goto L_800790AC;
    }
    // 0x80079098: nop

L_8007909C:
    // 0x8007909C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800790A0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800790A4: b           L_800790D4
    // 0x800790A8: nop

        goto L_800790D4;
    // 0x800790A8: nop

L_800790AC:
    // 0x800790AC: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x800790B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800790B4: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x800790B8: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800790BC: beq         $at, $zero, L_800790D4
    if (ctx->r1 == 0) {
        // 0x800790C0: sw          $t5, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r13;
            goto L_800790D4;
    }
    // 0x800790C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800790C4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800790C8: nop

    // 0x800790CC: beq         $t7, $zero, L_80078ADC
    if (ctx->r15 == 0) {
        // 0x800790D0: nop

            goto L_80078ADC;
    }
    // 0x800790D0: nop

L_800790D4:
    // 0x800790D4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800790D8: nop

    // 0x800790DC: beq         $t3, $zero, L_800790EC
    if (ctx->r11 == 0) {
        // 0x800790E0: nop

            goto L_800790EC;
    }
    // 0x800790E0: nop

    // 0x800790E4: b           L_80079114
    // 0x800790E8: nop

        goto L_80079114;
    // 0x800790E8: nop

L_800790EC:
    // 0x800790EC: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800790F0: nop

    // 0x800790F4: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800790F8: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800790FC: beq         $at, $zero, L_80079114
    if (ctx->r1 == 0) {
        // 0x80079100: sw          $t6, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r14;
            goto L_80079114;
    }
    // 0x80079100: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80079104: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80079108: nop

    // 0x8007910C: beq         $t1, $zero, L_80078AAC
    if (ctx->r9 == 0) {
        // 0x80079110: nop

            goto L_80078AAC;
    }
    // 0x80079110: nop

L_80079114:
    // 0x80079114: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80079118: nop

    // 0x8007911C: beq         $t8, $zero, L_80079140
    if (ctx->r24 == 0) {
        // 0x80079120: nop

            goto L_80079140;
    }
    // 0x80079120: nop

    // 0x80079124: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80079128: nop

    // 0x8007912C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80079130: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80079134: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80079138: nop

    // 0x8007913C: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
L_80079140:
    // 0x80079140: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80079144: b           L_80079154
    // 0x80079148: nop

        goto L_80079154;
    // 0x80079148: nop

    // 0x8007914C: b           L_80079154
    // 0x80079150: nop

        goto L_80079154;
    // 0x80079150: nop

L_80079154:
    // 0x80079154: jr          $ra
    // 0x80079158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80079158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8007915C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007915C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80079160: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80079164: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80079168: nop

    // 0x8007916C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80079170: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80079174: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x80079178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007917C: bne         $t6, $at, L_800792C0
    if (ctx->r14 != ctx->r1) {
        // 0x80079180: nop

            goto L_800792C0;
    }
    // 0x80079180: nop

    // 0x80079184: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80079188: nop

    // 0x8007918C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80079190: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80079194: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80079198: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007919C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800791A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800791A4: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x800791A8: nop

    // 0x800791AC: bc1f        L_80079240
    if (!c1cs) {
        // 0x800791B0: nop

            goto L_80079240;
    }
    // 0x800791B0: nop

    // 0x800791B4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800791B8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800791BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800791C0: nop

    // 0x800791C4: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x800791C8: nop

    // 0x800791CC: bc1f        L_80079240
    if (!c1cs) {
        // 0x800791D0: nop

            goto L_80079240;
    }
    // 0x800791D0: nop

    // 0x800791D4: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800791D8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800791DC: lw          $t7, 0xA4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XA4);
    // 0x800791E0: lw          $t1, 0xA4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XA4);
    // 0x800791E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800791E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800791EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800791F0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800791F4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800791F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800791FC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80079200: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80079204: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80079208: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x8007920C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80079210: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80079214: lwc1        $f6, 0x20($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80079218: lwc1        $f4, 0x28($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8007921C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80079220: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80079224: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80079228: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007922C: mul.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80079230: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x80079234: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80079238: b           L_8007924C
    // 0x8007923C: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
        goto L_8007924C;
    // 0x8007923C: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
L_80079240:
    // 0x80079240: lwc1        $f16, 0x14($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80079244: nop

    // 0x80079248: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
L_8007924C:
    // 0x8007924C: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80079250: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80079254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80079258: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007925C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80079260: nop

    // 0x80079264: bc1f        L_80079294
    if (!c1cs) {
        // 0x80079268: nop

            goto L_80079294;
    }
    // 0x80079268: nop

    // 0x8007926C: lw          $t5, 0xA4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XA4);
    // 0x80079270: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80079274: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80079278: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007927C: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80079280: lwc1        $f8, 0x20($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80079284: nop

    // 0x80079288: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007928C: b           L_800792B8
    // 0x80079290: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
        goto L_800792B8;
    // 0x80079290: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
L_80079294:
    // 0x80079294: lw          $t9, 0xA4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA4);
    // 0x80079298: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8007929C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800792A0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800792A4: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x800792A8: lwc1        $f18, 0x28($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X28);
    // 0x800792AC: nop

    // 0x800792B0: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800792B4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_800792B8:
    // 0x800792B8: b           L_800793FC
    // 0x800792BC: nop

        goto L_800793FC;
    // 0x800792BC: nop

L_800792C0:
    // 0x800792C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800792C4: nop

    // 0x800792C8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800792CC: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800792D0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800792D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800792D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800792DC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800792E0: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x800792E4: nop

    // 0x800792E8: bc1f        L_8007937C
    if (!c1cs) {
        // 0x800792EC: nop

            goto L_8007937C;
    }
    // 0x800792EC: nop

    // 0x800792F0: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800792F4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800792F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800792FC: nop

    // 0x80079300: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x80079304: nop

    // 0x80079308: bc1f        L_8007937C
    if (!c1cs) {
        // 0x8007930C: nop

            goto L_8007937C;
    }
    // 0x8007930C: nop

    // 0x80079310: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80079314: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80079318: lw          $t3, 0xA4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XA4);
    // 0x8007931C: lw          $t7, 0xA4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XA4);
    // 0x80079320: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80079324: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80079328: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007932C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80079330: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80079334: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80079338: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007933C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80079340: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x80079344: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80079348: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007934C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80079350: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80079354: lwc1        $f4, 0x2C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X2C);
    // 0x80079358: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007935C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80079360: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80079364: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80079368: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8007936C: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x80079370: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80079374: b           L_80079388
    // 0x80079378: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
        goto L_80079388;
    // 0x80079378: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
L_8007937C:
    // 0x8007937C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80079380: nop

    // 0x80079384: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
L_80079388:
    // 0x80079388: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8007938C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80079390: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80079394: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80079398: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8007939C: nop

    // 0x800793A0: bc1f        L_800793D0
    if (!c1cs) {
        // 0x800793A4: nop

            goto L_800793D0;
    }
    // 0x800793A4: nop

    // 0x800793A8: lw          $t1, 0xA4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XA4);
    // 0x800793AC: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800793B0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800793B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800793B8: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x800793BC: lwc1        $f8, 0x24($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800793C0: nop

    // 0x800793C4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800793C8: b           L_800793F4
    // 0x800793CC: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
        goto L_800793F4;
    // 0x800793CC: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_800793D0:
    // 0x800793D0: lw          $t5, 0xA4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XA4);
    // 0x800793D4: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800793D8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800793DC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800793E0: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800793E4: lwc1        $f18, 0x2C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x800793E8: nop

    // 0x800793EC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800793F0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_800793F4:
    // 0x800793F4: b           L_800793FC
    // 0x800793F8: nop

        goto L_800793FC;
    // 0x800793F8: nop

L_800793FC:
    // 0x800793FC: jr          $ra
    // 0x80079400: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80079400: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80079404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079404: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007940C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80079410: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80079414: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80079418: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007941C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80079420: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x80079424: jal         0x8007959C
    // 0x80079428: nop

    func_8007959C(rdram, ctx);
        goto after_0;
    // 0x80079428: nop

    after_0:
    // 0x8007942C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80079430: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80079434: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80079438: nop

    // 0x8007943C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80079440: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80079444: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80079448: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8007944C: nop

    // 0x80079450: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x80079454: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80079458: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007945C: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80079460: nop

    // 0x80079464: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x80079468: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007946C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80079470: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80079474: nop

    // 0x80079478: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
    // 0x8007947C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80079480: nop

    // 0x80079484: addiu       $t5, $t4, 0x20
    ctx->r13 = ADD32(ctx->r12, 0X20);
    // 0x80079488: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8007948C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80079490: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80079494: blez        $t6, L_80079564
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80079498: nop

            goto L_80079564;
    }
    // 0x80079498: nop

L_8007949C:
    // 0x8007949C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800794A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800794A4: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800794A8: nop

    // 0x800794AC: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800794B0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800794B4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800794B8: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x800794BC: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800794C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800794C4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800794C8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800794CC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800794D0: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800794D4: nop

    // 0x800794D8: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x800794DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800794E0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800794E4: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800794E8: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800794EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800794F0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800794F4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800794F8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800794FC: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80079500: nop

    // 0x80079504: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80079508: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007950C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80079510: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80079514: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80079518: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8007951C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80079520: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80079524: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80079528: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8007952C: nop

    // 0x80079530: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80079534: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80079538: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007953C: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80079540: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80079544: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80079548: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8007954C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80079550: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80079554: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80079558: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007955C: bne         $at, $zero, L_8007949C
    if (ctx->r1 != 0) {
        // 0x80079560: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8007949C;
    }
    // 0x80079560: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_80079564:
    // 0x80079564: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80079568: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007956C: nop

    // 0x80079570: sw          $t4, 0xA0($t5)
    MEM_W(0XA0, ctx->r13) = ctx->r12;
    // 0x80079574: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80079578: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007957C: nop

    // 0x80079580: sw          $t6, 0xA4($t7)
    MEM_W(0XA4, ctx->r15) = ctx->r14;
    // 0x80079584: b           L_8007958C
    // 0x80079588: nop

        goto L_8007958C;
    // 0x80079588: nop

L_8007958C:
    // 0x8007958C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80079594: jr          $ra
    // 0x80079598: nop

    return;
    // 0x80079598: nop

;}
RECOMP_FUNC void func_8007959C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007959C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800795A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800795A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800795A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800795AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800795B0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800795B4: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x800795B8: nop

    // 0x800795BC: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x800795C0: nop

    // 0x800795C4: bne         $t7, $zero, L_800795D4
    if (ctx->r15 != 0) {
        // 0x800795C8: nop

            goto L_800795D4;
    }
    // 0x800795C8: nop

    // 0x800795CC: b           L_800797E4
    // 0x800795D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800797E4;
    // 0x800795D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800795D4:
    // 0x800795D4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800795D8: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x800795DC: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
    // 0x800795E0: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x800795E4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800795E8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800795EC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800795F0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800795F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800795F8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800795FC: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80079600: nop

    // 0x80079604: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80079608: nop

    // 0x8007960C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079610: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80079614: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80079618: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007961C: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80079620: nop

    // 0x80079624: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80079628: nop

    // 0x8007962C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80079630: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x80079634: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80079638: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007963C: lh          $t9, 0x4($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X4);
    // 0x80079640: nop

    // 0x80079644: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80079648: nop

    // 0x8007964C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80079650: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x80079654: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80079658: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007965C: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x80079660: nop

    // 0x80079664: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80079668: nop

    // 0x8007966C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079670: swc1        $f6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f6.u32l;
    // 0x80079674: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x80079678: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007967C: nop

    // 0x80079680: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80079684: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80079688: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007968C: lhu         $t0, 0x8($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X8);
    // 0x80079690: nop

    // 0x80079694: andi        $t1, $t0, 0xFF00
    ctx->r9 = ctx->r8 & 0XFF00;
    // 0x80079698: sh          $t1, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r9;
    // 0x8007969C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800796A0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800796A4: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800796A8: nop

    // 0x800796AC: sh          $t3, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r11;
    // 0x800796B0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800796B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800796B8: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x800796BC: nop

    // 0x800796C0: andi        $t7, $t6, 0x3C
    ctx->r15 = ctx->r14 & 0X3C;
    // 0x800796C4: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800796C8: sb          $t8, 0x16($t0)
    MEM_B(0X16, ctx->r8) = ctx->r24;
    // 0x800796CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800796D0: nop

    // 0x800796D4: lh          $s0, 0x10($t1)
    ctx->r16 = MEM_H(ctx->r9, 0X10);
    // 0x800796D8: nop

    // 0x800796DC: beq         $s0, $zero, L_800796F8
    if (ctx->r16 == 0) {
        // 0x800796E0: nop

            goto L_800796F8;
    }
    // 0x800796E0: nop

    // 0x800796E4: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800796E8: beq         $s0, $at, L_80079774
    if (ctx->r16 == ctx->r1) {
        // 0x800796EC: nop

            goto L_80079774;
    }
    // 0x800796EC: nop

    // 0x800796F0: b           L_800797D4
    // 0x800796F4: nop

        goto L_800797D4;
    // 0x800796F4: nop

L_800796F8:
    // 0x800796F8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800796FC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80079700: lhu         $t2, 0xC($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0XC);
    // 0x80079704: nop

    // 0x80079708: sh          $t2, 0x1C($t3)
    MEM_H(0X1C, ctx->r11) = ctx->r10;
    // 0x8007970C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80079710: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80079714: lhu         $t5, 0xE($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XE);
    // 0x80079718: nop

    // 0x8007971C: sh          $t5, 0x1E($t6)
    MEM_H(0X1E, ctx->r14) = ctx->r13;
    // 0x80079720: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80079724: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80079728: lhu         $t8, 0xA($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XA);
    // 0x8007972C: nop

    // 0x80079730: bne         $t8, $at, L_8007974C
    if (ctx->r24 != ctx->r1) {
        // 0x80079734: nop

            goto L_8007974C;
    }
    // 0x80079734: nop

    // 0x80079738: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007973C: nop

    // 0x80079740: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
    // 0x80079744: b           L_800797D4
    // 0x80079748: nop

        goto L_800797D4;
    // 0x80079748: nop

L_8007974C:
    // 0x8007974C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80079750: nop

    // 0x80079754: lhu         $a0, 0xA($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XA);
    // 0x80079758: jal         0x800797F4
    // 0x8007975C: nop

    func_800797F4(rdram, ctx);
        goto after_0;
    // 0x8007975C: nop

    after_0:
    // 0x80079760: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80079764: nop

    // 0x80079768: sw          $v0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r2;
    // 0x8007976C: b           L_800797D4
    // 0x80079770: nop

        goto L_800797D4;
    // 0x80079770: nop

L_80079774:
    // 0x80079774: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80079778: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007977C: lhu         $t3, 0xA($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XA);
    // 0x80079780: nop

    // 0x80079784: sh          $t3, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r11;
    // 0x80079788: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007978C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80079790: lhu         $t6, 0xC($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0XC);
    // 0x80079794: nop

    // 0x80079798: sh          $t6, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r14;
    // 0x8007979C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800797A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800797A4: lhu         $t0, 0xE($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0XE);
    // 0x800797A8: nop

    // 0x800797AC: sh          $t0, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r8;
    // 0x800797B0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800797B4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800797B8: lhu         $t2, 0x8($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X8);
    // 0x800797BC: nop

    // 0x800797C0: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x800797C4: sra         $t4, $t3, 6
    ctx->r12 = S32(SIGNED(ctx->r11) >> 6);
    // 0x800797C8: sb          $t4, 0x1E($t5)
    MEM_B(0X1E, ctx->r13) = ctx->r12;
    // 0x800797CC: b           L_800797D4
    // 0x800797D0: nop

        goto L_800797D4;
    // 0x800797D0: nop

L_800797D4:
    // 0x800797D4: b           L_800797E4
    // 0x800797D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800797E4;
    // 0x800797D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800797DC: b           L_800797E4
    // 0x800797E0: nop

        goto L_800797E4;
    // 0x800797E0: nop

L_800797E4:
    // 0x800797E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800797E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800797EC: jr          $ra
    // 0x800797F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800797F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800797F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800797F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800797F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800797FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80079800: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079804: jal         0x800BC6EC
    // 0x80079808: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80079808: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x8007980C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80079810: lui         $t6, 0x807A
    ctx->r14 = S32(0X807A << 16);
    // 0x80079814: lui         $t7, 0x807A
    ctx->r15 = S32(0X807A << 16);
    // 0x80079818: addiu       $t7, $t7, 0x7B08
    ctx->r15 = ADD32(ctx->r15, 0X7B08);
    // 0x8007981C: addiu       $t6, $t6, 0x7BE0
    ctx->r14 = ADD32(ctx->r14, 0X7BE0);
    // 0x80079820: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80079824: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80079828: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007982C: jal         0x800BC6EC
    // 0x80079830: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80079830: nop

    after_1:
    // 0x80079834: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80079838: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007983C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80079840: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x80079844: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x80079848: lui         $a2, 0x807A
    ctx->r6 = S32(0X807A << 16);
    // 0x8007984C: jal         0x800BD1FC
    // 0x80079850: addiu       $a2, $a2, 0x7B08
    ctx->r6 = ADD32(ctx->r6, 0X7B08);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x80079850: addiu       $a2, $a2, 0x7B08
    ctx->r6 = ADD32(ctx->r6, 0X7B08);
    after_2:
    // 0x80079854: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80079858: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007985C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80079860: jal         0x800BD218
    // 0x80079864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x80079864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80079868: lhu         $t0, 0x3A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3A);
    // 0x8007986C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80079870: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80079874: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80079878: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8007987C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80079880: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80079884: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x80079888: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x8007988C: jal         0x800BD1FC
    // 0x80079890: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x80079890: nop

    after_4:
    // 0x80079894: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80079898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007989C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800798A0: jal         0x800BD218
    // 0x800798A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x800798A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x800798A8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800798AC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800798B0: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x800798B4: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x800798B8: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x800798BC: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x800798C0: jal         0x800BD1FC
    // 0x800798C4: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x800798C4: nop

    after_6:
    // 0x800798C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800798CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800798D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800798D4: jal         0x800BD218
    // 0x800798D8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_7;
    // 0x800798D8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_7:
    // 0x800798DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800798E0: jal         0x800BC980
    // 0x800798E4: nop

    SysMem_Free(rdram, ctx);
        goto after_8;
    // 0x800798E4: nop

    after_8:
    // 0x800798E8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800798EC: b           L_800798FC
    // 0x800798F0: nop

        goto L_800798FC;
    // 0x800798F0: nop

    // 0x800798F4: b           L_800798FC
    // 0x800798F8: nop

        goto L_800798FC;
    // 0x800798F8: nop

L_800798FC:
    // 0x800798FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80079900: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079904: jr          $ra
    // 0x80079908: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80079908: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007990C: nop

;}
RECOMP_FUNC void func_80079910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079918: jal         0x80080738
    // 0x8007991C: nop

    func_80080738(rdram, ctx);
        goto after_0;
    // 0x8007991C: nop

    after_0:
    // 0x80079920: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079924: sw          $zero, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = 0;
    // 0x80079928: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007992C: sw          $zero, 0x70F0($at)
    MEM_W(0X70F0, ctx->r1) = 0;
    // 0x80079930: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079934: sw          $zero, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = 0;
    // 0x80079938: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007993C: sw          $zero, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = 0;
    // 0x80079940: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079944: lh          $t6, 0x72AC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72AC);
    // 0x80079948: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007994C: sw          $t6, 0x7100($at)
    MEM_W(0X7100, ctx->r1) = ctx->r14;
    // 0x80079950: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079954: lh          $t7, 0x72B4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X72B4);
    // 0x80079958: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007995C: sw          $t7, 0x7104($at)
    MEM_W(0X7104, ctx->r1) = ctx->r15;
    // 0x80079960: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079964: sh          $zero, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = 0;
    // 0x80079968: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007996C: sh          $zero, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = 0;
    // 0x80079970: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079974: sb          $zero, 0x7108($at)
    MEM_B(0X7108, ctx->r1) = 0;
    // 0x80079978: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007997C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079980: swc1        $f4, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f4.u32l;
    // 0x80079984: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80079988: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007998C: swc1        $f6, 0x711C($at)
    MEM_W(0X711C, ctx->r1) = ctx->f6.u32l;
    // 0x80079990: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079994: swc1        $f6, 0x7118($at)
    MEM_W(0X7118, ctx->r1) = ctx->f6.u32l;
    // 0x80079998: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007999C: swc1        $f6, 0x7114($at)
    MEM_W(0X7114, ctx->r1) = ctx->f6.u32l;
    // 0x800799A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799A4: swc1        $f6, 0x7110($at)
    MEM_W(0X7110, ctx->r1) = ctx->f6.u32l;
    // 0x800799A8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800799AC: addiu       $t8, $t8, 0x70F0
    ctx->r24 = ADD32(ctx->r24, 0X70F0);
    // 0x800799B0: sh          $zero, 0x3C($t8)
    MEM_H(0X3C, ctx->r24) = 0;
    // 0x800799B4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800799B8: addiu       $t9, $t9, 0x70F0
    ctx->r25 = ADD32(ctx->r25, 0X70F0);
    // 0x800799BC: sh          $zero, 0x3E($t9)
    MEM_H(0X3E, ctx->r25) = 0;
    // 0x800799C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799C4: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
    // 0x800799C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799CC: sh          $zero, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = 0;
    // 0x800799D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800799D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799D8: swc1        $f8, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f8.u32l;
    // 0x800799DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799E0: sb          $zero, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = 0;
    // 0x800799E4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800799E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799EC: sb          $t0, 0x7143($at)
    MEM_B(0X7143, ctx->r1) = ctx->r8;
    // 0x800799F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799F4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800799F8: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
    // 0x800799FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80079A00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079A04: swc1        $f10, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f10.u32l;
    // 0x80079A08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079A0C: lh          $t2, 0x72AC($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X72AC);
    // 0x80079A10: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80079A14: bne         $t2, $at, L_80079A30
    if (ctx->r10 != ctx->r1) {
        // 0x80079A18: nop

            goto L_80079A30;
    }
    // 0x80079A18: nop

    // 0x80079A1C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80079A20: lh          $t3, 0x72B4($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X72B4);
    // 0x80079A24: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80079A28: beq         $t3, $at, L_80079A58
    if (ctx->r11 == ctx->r1) {
        // 0x80079A2C: nop

            goto L_80079A58;
    }
    // 0x80079A2C: nop

L_80079A30:
    // 0x80079A30: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80079A34: lh          $t4, 0x72AC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X72AC);
    // 0x80079A38: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80079A3C: bne         $t4, $at, L_80079B68
    if (ctx->r12 != ctx->r1) {
        // 0x80079A40: nop

            goto L_80079B68;
    }
    // 0x80079A40: nop

    // 0x80079A44: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079A48: lh          $t5, 0x72B4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X72B4);
    // 0x80079A4C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80079A50: bne         $t5, $at, L_80079B68
    if (ctx->r13 != ctx->r1) {
        // 0x80079A54: nop

            goto L_80079B68;
    }
    // 0x80079A54: nop

L_80079A58:
    // 0x80079A58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079A5C: sb          $zero, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = 0;
    // 0x80079A60: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079A64: lh          $t6, 0x72AC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72AC);
    // 0x80079A68: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80079A6C: bne         $t6, $at, L_80079AA0
    if (ctx->r14 != ctx->r1) {
        // 0x80079A70: nop

            goto L_80079AA0;
    }
    // 0x80079A70: nop

    // 0x80079A74: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079A78: lh          $t7, 0x72B4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X72B4);
    // 0x80079A7C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80079A80: bne         $t7, $at, L_80079AA0
    if (ctx->r15 != ctx->r1) {
        // 0x80079A84: nop

            goto L_80079AA0;
    }
    // 0x80079A84: nop

    // 0x80079A88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079A8C: sw          $zero, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = 0;
    // 0x80079A90: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80079A94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079A98: b           L_80079AB8
    // 0x80079A9C: sh          $t8, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r24;
        goto L_80079AB8;
    // 0x80079A9C: sh          $t8, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r24;
L_80079AA0:
    // 0x80079AA0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80079AA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079AA8: sw          $t9, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = ctx->r25;
    // 0x80079AAC: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x80079AB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079AB4: sh          $t0, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r8;
L_80079AB8:
    // 0x80079AB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079ABC: sh          $zero, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = 0;
    // 0x80079AC0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80079AC4: lw          $t1, 0x70F8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F8);
    // 0x80079AC8: nop

    // 0x80079ACC: bne         $t1, $zero, L_80079B10
    if (ctx->r9 != 0) {
        // 0x80079AD0: nop

            goto L_80079B10;
    }
    // 0x80079AD0: nop

    // 0x80079AD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80079AD8: jal         0x8007A514
    // 0x80079ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8007A514(rdram, ctx);
        goto after_1;
    // 0x80079ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80079AE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079AE4: sw          $v0, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r2;
    // 0x80079AE8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079AEC: lw          $t2, 0x70FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70FC);
    // 0x80079AF0: nop

    // 0x80079AF4: bne         $t2, $zero, L_80079B10
    if (ctx->r10 != 0) {
        // 0x80079AF8: nop

            goto L_80079B10;
    }
    // 0x80079AF8: nop

    // 0x80079AFC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80079B00: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x80079B04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079B08: ori         $t4, $t3, 0x100
    ctx->r12 = ctx->r11 | 0X100;
    // 0x80079B0C: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
L_80079B10:
    // 0x80079B10: jal         0x800BC6EC
    // 0x80079B14: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80079B14: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_2:
    // 0x80079B18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079B1C: sw          $v0, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = ctx->r2;
    // 0x80079B20: jal         0x800BC6EC
    // 0x80079B24: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80079B24: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_3:
    // 0x80079B28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079B2C: sw          $v0, 0x70F0($at)
    MEM_W(0X70F0, ctx->r1) = ctx->r2;
    // 0x80079B30: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079B34: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x80079B38: jal         0x80099E2C
    // 0x80079B3C: nop

    func_80099E2C(rdram, ctx);
        goto after_4;
    // 0x80079B3C: nop

    after_4:
    // 0x80079B40: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079B44: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80079B48: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x80079B4C: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x80079B50: jal         0x800B1B04
    // 0x80079B54: nop

    func_800B1B04(rdram, ctx);
        goto after_5;
    // 0x80079B54: nop

    after_5:
    // 0x80079B58: jal         0x8007B710
    // 0x80079B5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007B710(rdram, ctx);
        goto after_6;
    // 0x80079B5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80079B60: jal         0x8003168C
    // 0x80079B64: nop

    func_8003168C(rdram, ctx);
        goto after_7;
    // 0x80079B64: nop

    after_7:
L_80079B68:
    // 0x80079B68: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079B6C: lh          $t5, 0x72AC($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X72AC);
    // 0x80079B70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80079B74: bne         $t5, $at, L_80079C64
    if (ctx->r13 != ctx->r1) {
        // 0x80079B78: nop

            goto L_80079C64;
    }
    // 0x80079B78: nop

    // 0x80079B7C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079B80: lh          $t6, 0x72B4($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72B4);
    // 0x80079B84: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80079B88: beq         $t6, $at, L_80079B9C
    if (ctx->r14 == ctx->r1) {
        // 0x80079B8C: nop

            goto L_80079B9C;
    }
    // 0x80079B8C: nop

    // 0x80079B90: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x80079B94: bne         $t6, $at, L_80079C64
    if (ctx->r14 != ctx->r1) {
        // 0x80079B98: nop

            goto L_80079C64;
    }
    // 0x80079B98: nop

L_80079B9C:
    // 0x80079B9C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80079BA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079BA4: sh          $t7, 0x7144($at)
    MEM_H(0X7144, ctx->r1) = ctx->r15;
    // 0x80079BA8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80079BAC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079BB0: sb          $t8, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = ctx->r24;
    // 0x80079BB4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80079BB8: lh          $t9, 0x72B4($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X72B4);
    // 0x80079BBC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80079BC0: bne         $t9, $at, L_80079BD8
    if (ctx->r25 != ctx->r1) {
        // 0x80079BC4: nop

            goto L_80079BD8;
    }
    // 0x80079BC4: nop

    // 0x80079BC8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80079BCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079BD0: b           L_80079C08
    // 0x80079BD4: sw          $t0, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = ctx->r8;
        goto L_80079C08;
    // 0x80079BD4: sw          $t0, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = ctx->r8;
L_80079BD8:
    // 0x80079BD8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80079BDC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079BE0: sw          $t1, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = ctx->r9;
    // 0x80079BE4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079BE8: lh          $t2, 0x7132($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7132);
    // 0x80079BEC: nop

    // 0x80079BF0: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80079BF4: beq         $at, $zero, L_80079C08
    if (ctx->r1 == 0) {
        // 0x80079BF8: nop

            goto L_80079C08;
    }
    // 0x80079BF8: nop

    // 0x80079BFC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80079C00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079C04: sh          $t3, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r11;
L_80079C08:
    // 0x80079C08: jal         0x800A3918
    // 0x80079C0C: nop

    func_800A3918(rdram, ctx);
        goto after_8;
    // 0x80079C0C: nop

    after_8:
    // 0x80079C10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079C14: sw          $v0, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = ctx->r2;
    // 0x80079C18: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079C1C: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x80079C20: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80079C24: sh          $t4, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r12;
    // 0x80079C28: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079C2C: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x80079C30: addiu       $t6, $zero, 0x7D0
    ctx->r14 = ADD32(0, 0X7D0);
    // 0x80079C34: sw          $t6, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r14;
    // 0x80079C38: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80079C3C: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x80079C40: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x80079C44: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x80079C48: nop

    // 0x80079C4C: sh          $t8, 0x1FE($t0)
    MEM_H(0X1FE, ctx->r8) = ctx->r24;
    // 0x80079C50: addiu       $t1, $zero, 0x29
    ctx->r9 = ADD32(0, 0X29);
    // 0x80079C54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079C58: sh          $t1, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r9;
    // 0x80079C5C: jal         0x8007B710
    // 0x80079C60: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_8007B710(rdram, ctx);
        goto after_9;
    // 0x80079C60: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_9:
L_80079C64:
    // 0x80079C64: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80079C68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80079C6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80079C70: swc1        $f16, -0x3890($at)
    MEM_W(-0X3890, ctx->r1) = ctx->f16.u32l;
    // 0x80079C74: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x80079C78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80079C7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80079C80: swc1        $f18, -0x388C($at)
    MEM_W(-0X388C, ctx->r1) = ctx->f18.u32l;
    // 0x80079C84: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80079C88: jal         0x8001A690
    // 0x80079C8C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001A690(rdram, ctx);
        goto after_10;
    // 0x80079C8C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_10:
    // 0x80079C90: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80079C94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80079C98: sh          $t2, -0x397C($at)
    MEM_H(-0X397C, ctx->r1) = ctx->r10;
    // 0x80079C9C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80079CA0: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80079CA4: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x80079CA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80079CAC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80079CB0: sh          $t5, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r13;
    // 0x80079CB4: b           L_80079CBC
    // 0x80079CB8: nop

        goto L_80079CBC;
    // 0x80079CB8: nop

L_80079CBC:
    // 0x80079CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80079CC4: jr          $ra
    // 0x80079CC8: nop

    return;
    // 0x80079CC8: nop

;}
RECOMP_FUNC void func_80079CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079CCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079CD4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80079CD8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079CDC: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x80079CE0: nop

    // 0x80079CE4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80079CE8: beq         $t7, $zero, L_80079CF8
    if (ctx->r15 == 0) {
        // 0x80079CEC: nop

            goto L_80079CF8;
    }
    // 0x80079CEC: nop

    // 0x80079CF0: b           L_80079F24
    // 0x80079CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079CF8:
    // 0x80079CF8: jal         0x8007C54C
    // 0x80079CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8007C54C(rdram, ctx);
        goto after_0;
    // 0x80079CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80079D00: beq         $v0, $zero, L_80079D10
    if (ctx->r2 == 0) {
        // 0x80079D04: nop

            goto L_80079D10;
    }
    // 0x80079D04: nop

    // 0x80079D08: b           L_80079F24
    // 0x80079D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079D10:
    // 0x80079D10: jal         0x8007D538
    // 0x80079D14: nop

    func_8007D538(rdram, ctx);
        goto after_1;
    // 0x80079D14: nop

    after_1:
    // 0x80079D18: jal         0x8007B710
    // 0x80079D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8007B710(rdram, ctx);
        goto after_2;
    // 0x80079D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80079D20: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80079D24: jal         0x8007DF3C
    // 0x80079D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8007DF3C(rdram, ctx);
        goto after_3;
    // 0x80079D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80079D2C: beq         $v0, $zero, L_80079D3C
    if (ctx->r2 == 0) {
        // 0x80079D30: nop

            goto L_80079D3C;
    }
    // 0x80079D30: nop

    // 0x80079D34: b           L_80079F24
    // 0x80079D38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079D38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079D3C:
    // 0x80079D3C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80079D40: nop

    // 0x80079D44: beq         $t8, $zero, L_80079D54
    if (ctx->r24 == 0) {
        // 0x80079D48: nop

            goto L_80079D54;
    }
    // 0x80079D48: nop

    // 0x80079D4C: b           L_80079F24
    // 0x80079D50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079D50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079D54:
    // 0x80079D54: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80079D58: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x80079D5C: nop

    // 0x80079D60: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x80079D64: beq         $t0, $zero, L_80079D98
    if (ctx->r8 == 0) {
        // 0x80079D68: nop

            goto L_80079D98;
    }
    // 0x80079D68: nop

    // 0x80079D6C: andi        $t1, $t9, 0x10
    ctx->r9 = ctx->r25 & 0X10;
    // 0x80079D70: bne         $t1, $zero, L_80079D98
    if (ctx->r9 != 0) {
        // 0x80079D74: nop

            goto L_80079D98;
    }
    // 0x80079D74: nop

    // 0x80079D78: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079D7C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80079D80: lh          $a1, 0x7138($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7138);
    // 0x80079D84: lh          $a0, 0x7136($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7136);
    // 0x80079D88: jal         0x8007A488
    // 0x80079D8C: nop

    func_8007A488(rdram, ctx);
        goto after_4;
    // 0x80079D8C: nop

    after_4:
    // 0x80079D90: b           L_80079F24
    // 0x80079D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079D98:
    // 0x80079D98: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079D9C: lh          $t2, 0x7130($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7130);
    // 0x80079DA0: nop

    // 0x80079DA4: beq         $t2, $zero, L_80079DBC
    if (ctx->r10 == 0) {
        // 0x80079DA8: nop

            goto L_80079DBC;
    }
    // 0x80079DA8: nop

    // 0x80079DAC: jal         0x8007FA64
    // 0x80079DB0: nop

    func_8007FA64(rdram, ctx);
        goto after_5;
    // 0x80079DB0: nop

    after_5:
    // 0x80079DB4: b           L_80079F24
    // 0x80079DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079DBC:
    // 0x80079DBC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80079DC0: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x80079DC4: nop

    // 0x80079DC8: andi        $t4, $t3, 0x200
    ctx->r12 = ctx->r11 & 0X200;
    // 0x80079DCC: bne         $t4, $zero, L_80079DF4
    if (ctx->r12 != 0) {
        // 0x80079DD0: nop

            goto L_80079DF4;
    }
    // 0x80079DD0: nop

    // 0x80079DD4: jal         0x80031AC8
    // 0x80079DD8: nop

    func_80031AC8(rdram, ctx);
        goto after_6;
    // 0x80079DD8: nop

    after_6:
    // 0x80079DDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079DE0: bne         $v0, $at, L_80079DF4
    if (ctx->r2 != ctx->r1) {
        // 0x80079DE4: nop

            goto L_80079DF4;
    }
    // 0x80079DE4: nop

    // 0x80079DE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80079DEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80079DF0: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
L_80079DF4:
    // 0x80079DF4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079DF8: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x80079DFC: nop

    // 0x80079E00: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80079E04: beq         $t6, $zero, L_80079E94
    if (ctx->r14 == 0) {
        // 0x80079E08: nop

            goto L_80079E94;
    }
    // 0x80079E08: nop

    // 0x80079E0C: jal         0x80031AC8
    // 0x80079E10: nop

    func_80031AC8(rdram, ctx);
        goto after_7;
    // 0x80079E10: nop

    after_7:
    // 0x80079E14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80079E18: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079E1C: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x80079E20: nop

    // 0x80079E24: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x80079E28: beq         $t8, $zero, L_80079E4C
    if (ctx->r24 == 0) {
        // 0x80079E2C: nop

            goto L_80079E4C;
    }
    // 0x80079E2C: nop

    // 0x80079E30: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80079E34: nop

    // 0x80079E38: beq         $t0, $zero, L_80079E4C
    if (ctx->r8 == 0) {
        // 0x80079E3C: nop

            goto L_80079E4C;
    }
    // 0x80079E3C: nop

    // 0x80079E40: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80079E44: bne         $t0, $at, L_80079E8C
    if (ctx->r8 != ctx->r1) {
        // 0x80079E48: nop

            goto L_80079E8C;
    }
    // 0x80079E48: nop

L_80079E4C:
    // 0x80079E4C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80079E50: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x80079E54: addiu       $at, $zero, -0x211
    ctx->r1 = ADD32(0, -0X211);
    // 0x80079E58: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80079E5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079E60: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x80079E64: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079E68: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x80079E6C: nop

    // 0x80079E70: andi        $t3, $t2, 0x104
    ctx->r11 = ctx->r10 & 0X104;
    // 0x80079E74: beq         $t3, $zero, L_80079E84
    if (ctx->r11 == 0) {
        // 0x80079E78: nop

            goto L_80079E84;
    }
    // 0x80079E78: nop

    // 0x80079E7C: b           L_80079F24
    // 0x80079E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079E84:
    // 0x80079E84: jal         0x8007B710
    // 0x80079E88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007B710(rdram, ctx);
        goto after_8;
    // 0x80079E88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
L_80079E8C:
    // 0x80079E8C: b           L_80079F24
    // 0x80079E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079E94:
    // 0x80079E94: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079E98: jal         0x80080948
    // 0x80079E9C: addiu       $a0, $a0, 0x70F0
    ctx->r4 = ADD32(ctx->r4, 0X70F0);
    func_80080948(rdram, ctx);
        goto after_9;
    // 0x80079E9C: addiu       $a0, $a0, 0x70F0
    ctx->r4 = ADD32(ctx->r4, 0X70F0);
    after_9:
    // 0x80079EA0: jal         0x8007A8B8
    // 0x80079EA4: nop

    func_8007A8B8(rdram, ctx);
        goto after_10;
    // 0x80079EA4: nop

    after_10:
    // 0x80079EA8: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80079EAC: lhu         $t4, 0x26($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X26);
    // 0x80079EB0: nop

    // 0x80079EB4: beq         $t4, $zero, L_80079F14
    if (ctx->r12 == 0) {
        // 0x80079EB8: nop

            goto L_80079F14;
    }
    // 0x80079EB8: nop

    // 0x80079EBC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079EC0: lw          $t5, 0x70F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F8);
    // 0x80079EC4: nop

    // 0x80079EC8: beq         $t5, $zero, L_80079EDC
    if (ctx->r13 == 0) {
        // 0x80079ECC: nop

            goto L_80079EDC;
    }
    // 0x80079ECC: nop

    // 0x80079ED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079ED4: bne         $t5, $at, L_80079EE8
    if (ctx->r13 != ctx->r1) {
        // 0x80079ED8: nop

            goto L_80079EE8;
    }
    // 0x80079ED8: nop

L_80079EDC:
    // 0x80079EDC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x80079EE0: jal         0x8007ECB0
    // 0x80079EE4: nop

    func_8007ECB0(rdram, ctx);
        goto after_11;
    // 0x80079EE4: nop

    after_11:
L_80079EE8:
    // 0x80079EE8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079EEC: lw          $t6, 0x70F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F8);
    // 0x80079EF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079EF4: beq         $t6, $at, L_80079F08
    if (ctx->r14 == ctx->r1) {
        // 0x80079EF8: nop

            goto L_80079F08;
    }
    // 0x80079EF8: nop

    // 0x80079EFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80079F00: bne         $t6, $at, L_80079F14
    if (ctx->r14 != ctx->r1) {
        // 0x80079F04: nop

            goto L_80079F14;
    }
    // 0x80079F04: nop

L_80079F08:
    // 0x80079F08: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x80079F0C: jal         0x8007F878
    // 0x80079F10: nop

    func_8007F878(rdram, ctx);
        goto after_12;
    // 0x80079F10: nop

    after_12:
L_80079F14:
    // 0x80079F14: b           L_80079F24
    // 0x80079F18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079F18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80079F1C: b           L_80079F24
    // 0x80079F20: nop

        goto L_80079F24;
    // 0x80079F20: nop

L_80079F24:
    // 0x80079F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079F28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80079F2C: jr          $ra
    // 0x80079F30: nop

    return;
    // 0x80079F30: nop

;}
RECOMP_FUNC void func_80079F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079F3C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079F40: lw          $t6, 0x307C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X307C);
    // 0x80079F44: nop

    // 0x80079F48: beq         $t6, $zero, L_80079F70
    if (ctx->r14 == 0) {
        // 0x80079F4C: nop

            goto L_80079F70;
    }
    // 0x80079F4C: nop

    // 0x80079F50: jal         0x800B0E08
    // 0x80079F54: nop

    func_800B0E08(rdram, ctx);
        goto after_0;
    // 0x80079F54: nop

    after_0:
    // 0x80079F58: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079F5C: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x80079F60: jal         0x800BC980
    // 0x80079F64: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80079F64: nop

    after_1:
    // 0x80079F68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079F6C: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_80079F70:
    // 0x80079F70: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80079F74: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80079F78:
    // 0x80079F78: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80079F7C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80079F80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80079F84: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80079F88: lw          $a0, -0x3808($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3808);
    // 0x80079F8C: jal         0x800BC980
    // 0x80079F90: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x80079F90: nop

    after_2:
    // 0x80079F94: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80079F98: nop

    // 0x80079F9C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80079FA0: bgez        $t1, L_80079F78
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80079FA4: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_80079F78;
    }
    // 0x80079FA4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80079FA8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80079FAC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_80079FB0:
    // 0x80079FB0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80079FB4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80079FB8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80079FBC: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80079FC0: lw          $a0, -0x37E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37E0);
    // 0x80079FC4: jal         0x800BC980
    // 0x80079FC8: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80079FC8: nop

    after_3:
    // 0x80079FCC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80079FD0: nop

    // 0x80079FD4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80079FD8: bgez        $t6, L_80079FB0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80079FDC: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_80079FB0;
    }
    // 0x80079FDC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80079FE0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079FE4: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x80079FE8: nop

    // 0x80079FEC: bne         $t7, $zero, L_8007A008
    if (ctx->r15 != 0) {
        // 0x80079FF0: nop

            goto L_8007A008;
    }
    // 0x80079FF0: nop

    // 0x80079FF4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80079FF8: lw          $t8, 0x70F0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F0);
    // 0x80079FFC: nop

    // 0x8007A000: beq         $t8, $zero, L_8007A020
    if (ctx->r24 == 0) {
        // 0x8007A004: nop

            goto L_8007A020;
    }
    // 0x8007A004: nop

L_8007A008:
    // 0x8007A008: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007A00C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007A010: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007A014: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007A018: jal         0x800B1BC8
    // 0x8007A01C: nop

    func_800B1BC8(rdram, ctx);
        goto after_4;
    // 0x8007A01C: nop

    after_4:
L_8007A020:
    // 0x8007A020: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007A024: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007A028: nop

    // 0x8007A02C: beq         $t9, $zero, L_8007A044
    if (ctx->r25 == 0) {
        // 0x8007A030: nop

            goto L_8007A044;
    }
    // 0x8007A030: nop

    // 0x8007A034: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007A038: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007A03C: jal         0x800BC980
    // 0x8007A040: nop

    SysMem_Free(rdram, ctx);
        goto after_5;
    // 0x8007A040: nop

    after_5:
L_8007A044:
    // 0x8007A044: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007A048: lw          $t0, 0x70F0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F0);
    // 0x8007A04C: nop

    // 0x8007A050: beq         $t0, $zero, L_8007A068
    if (ctx->r8 == 0) {
        // 0x8007A054: nop

            goto L_8007A068;
    }
    // 0x8007A054: nop

    // 0x8007A058: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007A05C: lw          $a0, 0x70F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F0);
    // 0x8007A060: jal         0x800BC980
    // 0x8007A064: nop

    SysMem_Free(rdram, ctx);
        goto after_6;
    // 0x8007A064: nop

    after_6:
L_8007A068:
    // 0x8007A068: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007A06C: lw          $t1, 0x70F8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F8);
    // 0x8007A070: nop

    // 0x8007A074: bne         $t1, $zero, L_8007A084
    if (ctx->r9 != 0) {
        // 0x8007A078: nop

            goto L_8007A084;
    }
    // 0x8007A078: nop

    // 0x8007A07C: jal         0x80029ED8
    // 0x8007A080: nop

    func_80029ED8(rdram, ctx);
        goto after_7;
    // 0x8007A080: nop

    after_7:
L_8007A084:
    // 0x8007A084: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8007A088: jal         0x8001AE90
    // 0x8007A08C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001AE90(rdram, ctx);
        goto after_8;
    // 0x8007A08C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_8:
    // 0x8007A090: jal         0x80031728
    // 0x8007A094: nop

    func_80031728(rdram, ctx);
        goto after_9;
    // 0x8007A094: nop

    after_9:
    // 0x8007A098: b           L_8007A0A0
    // 0x8007A09C: nop

        goto L_8007A0A0;
    // 0x8007A09C: nop

L_8007A0A0:
    // 0x8007A0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A0A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007A0A8: jr          $ra
    // 0x8007A0AC: nop

    return;
    // 0x8007A0AC: nop

;}
RECOMP_FUNC void func_8007A0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A0B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007A0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A0B8: jal         0x800317E4
    // 0x8007A0BC: nop

    func_800317E4(rdram, ctx);
        goto after_0;
    // 0x8007A0BC: nop

    after_0:
    // 0x8007A0C0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007A0C4: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007A0C8: nop

    // 0x8007A0CC: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8007A0D0: nop

    // 0x8007A0D4: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x8007A0D8: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x8007A0DC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007A0E0: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007A0E4: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8007A0E8: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x8007A0EC: nop

    // 0x8007A0F0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8007A0F4: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
    // 0x8007A0F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8007A0FC:
    // 0x8007A0FC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007A100: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007A104: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8007A108: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007A10C: lw          $t4, -0x3914($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3914);
    // 0x8007A110: nop

    // 0x8007A114: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8007A118: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007A11C: lwc1        $f8, -0x3890($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3890);
    // 0x8007A120: lwc1        $f10, -0x388C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X388C);
    // 0x8007A124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007A128: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007A12C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007A130: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007A134: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8007A138: nop

    // 0x8007A13C: bc1f        L_8007A190
    if (!c1cs) {
        // 0x8007A140: nop

            goto L_8007A190;
    }
    // 0x8007A140: nop

L_8007A144:
    // 0x8007A144: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007A148: nop

    // 0x8007A14C: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x8007A150: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A154: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007A158: lwc1        $f8, -0x3890($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3890);
    // 0x8007A15C: lwc1        $f10, -0x388C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X388C);
    // 0x8007A160: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007A164: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8007A168: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007A16C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007A170: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007A174: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8007A178: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007A17C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8007A180: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8007A184: nop

    // 0x8007A188: bc1t        L_8007A144
    if (c1cs) {
        // 0x8007A18C: nop

            goto L_8007A144;
    }
    // 0x8007A18C: nop

L_8007A190:
    // 0x8007A190: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A194: nop

    // 0x8007A198: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8007A19C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8007A1A0: bne         $at, $zero, L_8007A0FC
    if (ctx->r1 != 0) {
        // 0x8007A1A4: sw          $t9, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r25;
            goto L_8007A0FC;
    }
    // 0x8007A1A4: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007A1A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A1AC: sh          $zero, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = 0;
    // 0x8007A1B0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007A1B4: lw          $t2, 0x7100($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7100);
    // 0x8007A1B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A1BC: bne         $t2, $at, L_8007A210
    if (ctx->r10 != ctx->r1) {
        // 0x8007A1C0: nop

            goto L_8007A210;
    }
    // 0x8007A1C0: nop

    // 0x8007A1C4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007A1C8: lw          $t3, 0x7104($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7104);
    // 0x8007A1CC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007A1D0: bne         $t3, $at, L_8007A210
    if (ctx->r11 != ctx->r1) {
        // 0x8007A1D4: nop

            goto L_8007A210;
    }
    // 0x8007A1D4: nop

    // 0x8007A1D8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007A1DC: lh          $t4, 0x72AC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X72AC);
    // 0x8007A1E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A1E4: bne         $t4, $at, L_8007A210
    if (ctx->r12 != ctx->r1) {
        // 0x8007A1E8: nop

            goto L_8007A210;
    }
    // 0x8007A1E8: nop

    // 0x8007A1EC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A1F0: lh          $t5, 0x72B4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X72B4);
    // 0x8007A1F4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007A1F8: bne         $t5, $at, L_8007A210
    if (ctx->r13 != ctx->r1) {
        // 0x8007A1FC: nop

            goto L_8007A210;
    }
    // 0x8007A1FC: nop

    // 0x8007A200: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007A204: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007A208: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A20C: sb          $t7, 0x7141($at)
    MEM_B(0X7141, ctx->r1) = ctx->r15;
L_8007A210:
    // 0x8007A210: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A214: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007A218: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A21C: bne         $t6, $at, L_8007A290
    if (ctx->r14 != ctx->r1) {
        // 0x8007A220: nop

            goto L_8007A290;
    }
    // 0x8007A220: nop

    // 0x8007A224: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007A228: lw          $t0, 0x7104($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7104);
    // 0x8007A22C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007A230: bne         $t0, $at, L_8007A290
    if (ctx->r8 != ctx->r1) {
        // 0x8007A234: nop

            goto L_8007A290;
    }
    // 0x8007A234: nop

    // 0x8007A238: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A23C: lh          $t8, 0x72AC($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X72AC);
    // 0x8007A240: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A244: bne         $t8, $at, L_8007A290
    if (ctx->r24 != ctx->r1) {
        // 0x8007A248: nop

            goto L_8007A290;
    }
    // 0x8007A248: nop

    // 0x8007A24C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007A250: lh          $t1, 0x72B4($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X72B4);
    // 0x8007A254: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007A258: bne         $t1, $at, L_8007A290
    if (ctx->r9 != ctx->r1) {
        // 0x8007A25C: nop

            goto L_8007A290;
    }
    // 0x8007A25C: nop

    // 0x8007A260: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007A264: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007A268: nop

    // 0x8007A26C: andi        $t2, $t9, 0x100
    ctx->r10 = ctx->r25 & 0X100;
    // 0x8007A270: beq         $t2, $zero, L_8007A284
    if (ctx->r10 == 0) {
        // 0x8007A274: nop

            goto L_8007A284;
    }
    // 0x8007A274: nop

    // 0x8007A278: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A27C: b           L_8007A290
    // 0x8007A280: sh          $zero, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = 0;
        goto L_8007A290;
    // 0x8007A280: sh          $zero, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = 0;
L_8007A284:
    // 0x8007A284: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007A288: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A28C: sh          $t3, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r11;
L_8007A290:
    // 0x8007A290: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007A294: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007A298: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A29C: bne         $t4, $at, L_8007A2C8
    if (ctx->r12 != ctx->r1) {
        // 0x8007A2A0: nop

            goto L_8007A2C8;
    }
    // 0x8007A2A0: nop

    // 0x8007A2A4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A2A8: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007A2AC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8007A2B0: bne         $t5, $at, L_8007A2C8
    if (ctx->r13 != ctx->r1) {
        // 0x8007A2B4: nop

            goto L_8007A2C8;
    }
    // 0x8007A2B4: nop

    // 0x8007A2B8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007A2BC: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007A2C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A2C4: sh          $t7, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r15;
L_8007A2C8:
    // 0x8007A2C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A2CC: lh          $t6, 0x72AC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72AC);
    // 0x8007A2D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A2D4: sw          $t6, 0x7100($at)
    MEM_W(0X7100, ctx->r1) = ctx->r14;
    // 0x8007A2D8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007A2DC: lh          $t0, 0x72B4($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X72B4);
    // 0x8007A2E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A2E4: sw          $t0, 0x7104($at)
    MEM_W(0X7104, ctx->r1) = ctx->r8;
    // 0x8007A2E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A2EC: sb          $zero, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = 0;
    // 0x8007A2F0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A2F4: lw          $t8, 0x7100($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7100);
    // 0x8007A2F8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A2FC: bne         $t8, $at, L_8007A35C
    if (ctx->r24 != ctx->r1) {
        // 0x8007A300: nop

            goto L_8007A35C;
    }
    // 0x8007A300: nop

    // 0x8007A304: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007A308: lw          $t1, 0x7104($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7104);
    // 0x8007A30C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007A310: bne         $t1, $at, L_8007A35C
    if (ctx->r9 != ctx->r1) {
        // 0x8007A314: nop

            goto L_8007A35C;
    }
    // 0x8007A314: nop

    // 0x8007A318: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A31C: jal         0x8007A514
    // 0x8007A320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8007A514(rdram, ctx);
        goto after_1;
    // 0x8007A320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8007A324: bne         $v0, $zero, L_8007A344
    if (ctx->r2 != 0) {
        // 0x8007A328: nop

            goto L_8007A344;
    }
    // 0x8007A328: nop

    // 0x8007A32C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007A330: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007A334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A338: ori         $t2, $t9, 0x100
    ctx->r10 = ctx->r25 | 0X100;
    // 0x8007A33C: b           L_8007A35C
    // 0x8007A340: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
        goto L_8007A35C;
    // 0x8007A340: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
L_8007A344:
    // 0x8007A344: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007A348: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007A34C: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x8007A350: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8007A354: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A358: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
L_8007A35C:
    // 0x8007A35C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A360: lw          $t5, 0x7100($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7100);
    // 0x8007A364: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A368: bne         $t5, $at, L_8007A3BC
    if (ctx->r13 != ctx->r1) {
        // 0x8007A36C: nop

            goto L_8007A3BC;
    }
    // 0x8007A36C: nop

    // 0x8007A370: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007A374: lw          $t7, 0x7104($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7104);
    // 0x8007A378: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007A37C: bne         $t7, $at, L_8007A3BC
    if (ctx->r15 != ctx->r1) {
        // 0x8007A380: nop

            goto L_8007A3BC;
    }
    // 0x8007A380: nop

    // 0x8007A384: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A388: lb          $t6, 0x7141($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7141);
    // 0x8007A38C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A390: sb          $t6, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r14;
    // 0x8007A394: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007A398: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A39C: sb          $t0, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = ctx->r8;
    // 0x8007A3A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007A3A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007A3A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A3AC: swc1        $f16, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f16.u32l;
    // 0x8007A3B0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8007A3B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A3B8: sb          $t8, 0x7143($at)
    MEM_B(0X7143, ctx->r1) = ctx->r24;
L_8007A3BC:
    // 0x8007A3BC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007A3C0: lw          $t1, 0x7100($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7100);
    // 0x8007A3C4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A3C8: bne         $t1, $at, L_8007A40C
    if (ctx->r9 != ctx->r1) {
        // 0x8007A3CC: nop

            goto L_8007A40C;
    }
    // 0x8007A3CC: nop

    // 0x8007A3D0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007A3D4: lw          $t9, 0x7104($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7104);
    // 0x8007A3D8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007A3DC: bne         $t9, $at, L_8007A40C
    if (ctx->r25 != ctx->r1) {
        // 0x8007A3E0: nop

            goto L_8007A40C;
    }
    // 0x8007A3E0: nop

    // 0x8007A3E4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8007A3E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A3EC: sb          $t2, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = ctx->r10;
    // 0x8007A3F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007A3F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007A3F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A3FC: swc1        $f18, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f18.u32l;
    // 0x8007A400: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8007A404: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A408: sb          $t3, 0x7143($at)
    MEM_B(0X7143, ctx->r1) = ctx->r11;
L_8007A40C:
    // 0x8007A40C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007A410: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007A414: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A418: bne         $t4, $at, L_8007A440
    if (ctx->r12 != ctx->r1) {
        // 0x8007A41C: nop

            goto L_8007A440;
    }
    // 0x8007A41C: nop

    // 0x8007A420: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A424: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007A428: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007A42C: bne         $t5, $at, L_8007A440
    if (ctx->r13 != ctx->r1) {
        // 0x8007A430: nop

            goto L_8007A440;
    }
    // 0x8007A430: nop

    // 0x8007A434: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8007A438: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A43C: sb          $t7, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = ctx->r15;
L_8007A440:
    // 0x8007A440: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A444: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007A448: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A44C: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x8007A450: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A454: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007A458: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A45C: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007A460: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8007A464: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x8007A468: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A46C: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007A470: b           L_8007A478
    // 0x8007A474: nop

        goto L_8007A478;
    // 0x8007A474: nop

L_8007A478:
    // 0x8007A478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A47C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007A480: jr          $ra
    // 0x8007A484: nop

    return;
    // 0x8007A484: nop

;}
RECOMP_FUNC void func_8007A488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A48C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007A494: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007A498: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007A49C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A4A0: sh          $t6, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r14;
    // 0x8007A4A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A4A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A4AC: sh          $t7, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r15;
    // 0x8007A4B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007A4B4: lbu         $a0, 0x1918($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1918);
    // 0x8007A4B8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8007A4BC: addiu       $a1, $a1, -0x820
    ctx->r5 = ADD32(ctx->r5, -0X820);
    // 0x8007A4C0: jal         0x800C1264
    // 0x8007A4C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x8007A4C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007A4C8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A4CC: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007A4D0: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8007A4D4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007A4D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A4DC: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007A4E0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007A4E4: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007A4E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A4EC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8007A4F0: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007A4F4: b           L_8007A504
    // 0x8007A4F8: nop

        goto L_8007A504;
    // 0x8007A4F8: nop

    // 0x8007A4FC: b           L_8007A504
    // 0x8007A500: nop

        goto L_8007A504;
    // 0x8007A500: nop

L_8007A504:
    // 0x8007A504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A50C: jr          $ra
    // 0x8007A510: nop

    return;
    // 0x8007A510: nop

;}
RECOMP_FUNC void func_8007A514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A514: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A51C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007A520: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007A524: jal         0x80029ED8
    // 0x8007A528: nop

    func_80029ED8(rdram, ctx);
        goto after_0;
    // 0x8007A528: nop

    after_0:
    // 0x8007A52C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A530: nop

    // 0x8007A534: bltz        $t6, L_8007A620
    if (SIGNED(ctx->r14) < 0) {
        // 0x8007A538: nop

            goto L_8007A620;
    }
    // 0x8007A538: nop

    // 0x8007A53C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007A540: nop

    // 0x8007A544: bne         $t7, $zero, L_8007A564
    if (ctx->r15 != 0) {
        // 0x8007A548: nop

            goto L_8007A564;
    }
    // 0x8007A548: nop

    // 0x8007A54C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A550: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x8007A554: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007A558: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8007A55C: b           L_8007A578
    // 0x8007A560: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
        goto L_8007A578;
    // 0x8007A560: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
L_8007A564:
    // 0x8007A564: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007A568: nop

    // 0x8007A56C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8007A570: nop

    // 0x8007A574: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
L_8007A578:
    // 0x8007A578: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007A57C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007A580: nop

    // 0x8007A584: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x8007A588: nop

    // 0x8007A58C: beq         $t3, $zero, L_8007A5FC
    if (ctx->r11 == 0) {
        // 0x8007A590: nop

            goto L_8007A5FC;
    }
    // 0x8007A590: nop

L_8007A594:
    // 0x8007A594: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007A598: nop

    // 0x8007A59C: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x8007A5A0: nop

    // 0x8007A5A4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8007A5A8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007A5AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A5B0: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x8007A5B4: nop

    // 0x8007A5B8: bne         $t7, $at, L_8007A5E4
    if (ctx->r15 != ctx->r1) {
        // 0x8007A5BC: nop

            goto L_8007A5E4;
    }
    // 0x8007A5BC: nop

    // 0x8007A5C0: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8007A5C4: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8007A5C8: nop

    // 0x8007A5CC: beq         $t8, $t9, L_8007A5E4
    if (ctx->r24 == ctx->r25) {
        // 0x8007A5D0: nop

            goto L_8007A5E4;
    }
    // 0x8007A5D0: nop

    // 0x8007A5D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007A5D8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8007A5DC: b           L_8007A5FC
    // 0x8007A5E0: nop

        goto L_8007A5FC;
    // 0x8007A5E0: nop

L_8007A5E4:
    // 0x8007A5E4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A5E8: nop

    // 0x8007A5EC: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x8007A5F0: nop

    // 0x8007A5F4: bne         $t2, $zero, L_8007A594
    if (ctx->r10 != 0) {
        // 0x8007A5F8: nop

            goto L_8007A594;
    }
    // 0x8007A5F8: nop

L_8007A5FC:
    // 0x8007A5FC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007A600: nop

    // 0x8007A604: bne         $t3, $zero, L_8007A614
    if (ctx->r11 != 0) {
        // 0x8007A608: nop

            goto L_8007A614;
    }
    // 0x8007A608: nop

    // 0x8007A60C: b           L_8007A8A8
    // 0x8007A610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007A8A8;
    // 0x8007A610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A614:
    // 0x8007A614: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007A618: b           L_8007A8A8
    // 0x8007A61C: nop

        goto L_8007A8A8;
    // 0x8007A61C: nop

L_8007A620:
    // 0x8007A620: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007A624: nop

    // 0x8007A628: bne         $t4, $zero, L_8007A744
    if (ctx->r12 != 0) {
        // 0x8007A62C: nop

            goto L_8007A744;
    }
    // 0x8007A62C: nop

    // 0x8007A630: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A634: addiu       $t5, $t5, 0x2578
    ctx->r13 = ADD32(ctx->r13, 0X2578);
    // 0x8007A638: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8007A63C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007A640: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007A644: nop

    // 0x8007A648: lw          $t6, 0x18($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X18);
    // 0x8007A64C: nop

    // 0x8007A650: beq         $t6, $zero, L_8007A6AC
    if (ctx->r14 == 0) {
        // 0x8007A654: nop

            goto L_8007A6AC;
    }
    // 0x8007A654: nop

L_8007A658:
    // 0x8007A658: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007A65C: nop

    // 0x8007A660: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8007A664: nop

    // 0x8007A668: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007A66C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007A670: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A674: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x8007A678: nop

    // 0x8007A67C: bne         $t1, $at, L_8007A694
    if (ctx->r9 != ctx->r1) {
        // 0x8007A680: nop

            goto L_8007A694;
    }
    // 0x8007A680: nop

    // 0x8007A684: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007A688: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8007A68C: b           L_8007A6AC
    // 0x8007A690: nop

        goto L_8007A6AC;
    // 0x8007A690: nop

L_8007A694:
    // 0x8007A694: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007A698: nop

    // 0x8007A69C: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8007A6A0: nop

    // 0x8007A6A4: bne         $t4, $zero, L_8007A658
    if (ctx->r12 != 0) {
        // 0x8007A6A8: nop

            goto L_8007A658;
    }
    // 0x8007A6A8: nop

L_8007A6AC:
    // 0x8007A6AC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007A6B0: nop

    // 0x8007A6B4: bne         $t5, $zero, L_8007A6C4
    if (ctx->r13 != 0) {
        // 0x8007A6B8: nop

            goto L_8007A6C4;
    }
    // 0x8007A6B8: nop

    // 0x8007A6BC: b           L_8007A8A8
    // 0x8007A6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007A8A8;
    // 0x8007A6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A6C4:
    // 0x8007A6C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A6C8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007A6CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007A6D0: nop

    // 0x8007A6D4: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8007A6D8: nop

    // 0x8007A6DC: beq         $t8, $zero, L_8007A738
    if (ctx->r24 == 0) {
        // 0x8007A6E0: nop

            goto L_8007A738;
    }
    // 0x8007A6E0: nop

L_8007A6E4:
    // 0x8007A6E4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007A6E8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A6EC: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x8007A6F0: nop

    // 0x8007A6F4: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x8007A6F8: nop

    // 0x8007A6FC: beq         $t1, $at, L_8007A70C
    if (ctx->r9 == ctx->r1) {
        // 0x8007A700: nop

            goto L_8007A70C;
    }
    // 0x8007A700: nop

    // 0x8007A704: b           L_8007A738
    // 0x8007A708: nop

        goto L_8007A738;
    // 0x8007A708: nop

L_8007A70C:
    // 0x8007A70C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007A710: nop

    // 0x8007A714: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x8007A718: nop

    // 0x8007A71C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8007A720: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007A724: nop

    // 0x8007A728: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x8007A72C: nop

    // 0x8007A730: bne         $t5, $zero, L_8007A6E4
    if (ctx->r13 != 0) {
        // 0x8007A734: nop

            goto L_8007A6E4;
    }
    // 0x8007A734: nop

L_8007A738:
    // 0x8007A738: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8007A73C: b           L_8007A75C
    // 0x8007A740: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
        goto L_8007A75C;
    // 0x8007A740: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
L_8007A744:
    // 0x8007A744: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8007A748: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007A74C: nop

    // 0x8007A750: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8007A754: nop

    // 0x8007A758: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
L_8007A75C:
    // 0x8007A75C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A760: nop

    // 0x8007A764: beq         $t9, $zero, L_8007A778
    if (ctx->r25 == 0) {
        // 0x8007A768: nop

            goto L_8007A778;
    }
    // 0x8007A768: nop

    // 0x8007A76C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007A770: b           L_8007A814
    // 0x8007A774: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_8007A814;
    // 0x8007A774: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8007A778:
    // 0x8007A778: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007A77C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A780: nop

    // 0x8007A784: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8007A788: nop

    // 0x8007A78C: beq         $t2, $zero, L_8007A7FC
    if (ctx->r10 == 0) {
        // 0x8007A790: nop

            goto L_8007A7FC;
    }
    // 0x8007A790: nop

L_8007A794:
    // 0x8007A794: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007A798: nop

    // 0x8007A79C: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8007A7A0: nop

    // 0x8007A7A4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8007A7A8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007A7AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A7B0: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x8007A7B4: nop

    // 0x8007A7B8: bne         $t7, $at, L_8007A7E4
    if (ctx->r15 != ctx->r1) {
        // 0x8007A7BC: nop

            goto L_8007A7E4;
    }
    // 0x8007A7BC: nop

    // 0x8007A7C0: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8007A7C4: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x8007A7C8: nop

    // 0x8007A7CC: beq         $t6, $t8, L_8007A7E4
    if (ctx->r14 == ctx->r24) {
        // 0x8007A7D0: nop

            goto L_8007A7E4;
    }
    // 0x8007A7D0: nop

    // 0x8007A7D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007A7D8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8007A7DC: b           L_8007A7FC
    // 0x8007A7E0: nop

        goto L_8007A7FC;
    // 0x8007A7E0: nop

L_8007A7E4:
    // 0x8007A7E4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007A7E8: nop

    // 0x8007A7EC: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8007A7F0: nop

    // 0x8007A7F4: bne         $t1, $zero, L_8007A794
    if (ctx->r9 != 0) {
        // 0x8007A7F8: nop

            goto L_8007A794;
    }
    // 0x8007A7F8: nop

L_8007A7FC:
    // 0x8007A7FC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007A800: nop

    // 0x8007A804: bne         $t2, $zero, L_8007A814
    if (ctx->r10 != 0) {
        // 0x8007A808: nop

            goto L_8007A814;
    }
    // 0x8007A808: nop

    // 0x8007A80C: b           L_8007A8A8
    // 0x8007A810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007A8A8;
    // 0x8007A810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A814:
    // 0x8007A814: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007A818: nop

    // 0x8007A81C: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8007A820: nop

    // 0x8007A824: sh          $t4, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r12;
    // 0x8007A828: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007A82C: nop

    // 0x8007A830: lw          $t5, 0x14($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X14);
    // 0x8007A834: nop

    // 0x8007A838: beq         $t5, $zero, L_8007A894
    if (ctx->r13 == 0) {
        // 0x8007A83C: nop

            goto L_8007A894;
    }
    // 0x8007A83C: nop

L_8007A840:
    // 0x8007A840: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007A844: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x8007A848: lw          $t8, 0x14($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14);
    // 0x8007A84C: nop

    // 0x8007A850: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8007A854: nop

    // 0x8007A858: beq         $t9, $t0, L_8007A868
    if (ctx->r25 == ctx->r8) {
        // 0x8007A85C: nop

            goto L_8007A868;
    }
    // 0x8007A85C: nop

    // 0x8007A860: b           L_8007A894
    // 0x8007A864: nop

        goto L_8007A894;
    // 0x8007A864: nop

L_8007A868:
    // 0x8007A868: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A86C: nop

    // 0x8007A870: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8007A874: nop

    // 0x8007A878: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8007A87C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007A880: nop

    // 0x8007A884: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8007A888: nop

    // 0x8007A88C: bne         $t4, $zero, L_8007A840
    if (ctx->r12 != 0) {
        // 0x8007A890: nop

            goto L_8007A840;
    }
    // 0x8007A890: nop

L_8007A894:
    // 0x8007A894: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007A898: b           L_8007A8A8
    // 0x8007A89C: nop

        goto L_8007A8A8;
    // 0x8007A89C: nop

    // 0x8007A8A0: b           L_8007A8A8
    // 0x8007A8A4: nop

        goto L_8007A8A8;
    // 0x8007A8A4: nop

L_8007A8A8:
    // 0x8007A8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A8AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A8B0: jr          $ra
    // 0x8007A8B4: nop

    return;
    // 0x8007A8B4: nop

;}
RECOMP_FUNC void func_8007A8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A8B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A8BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A8C0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A8C4: lw          $t6, 0x70F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F8);
    // 0x8007A8C8: nop

    // 0x8007A8CC: beq         $t6, $zero, L_8007A8E0
    if (ctx->r14 == 0) {
        // 0x8007A8D0: nop

            goto L_8007A8E0;
    }
    // 0x8007A8D0: nop

    // 0x8007A8D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007A8D8: bne         $t6, $at, L_8007A910
    if (ctx->r14 != ctx->r1) {
        // 0x8007A8DC: nop

            goto L_8007A910;
    }
    // 0x8007A8DC: nop

L_8007A8E0:
    // 0x8007A8E0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007A8E4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8007A8E8: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x8007A8EC: lhu         $t7, 0x7148($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7148);
    // 0x8007A8F0: nop

    // 0x8007A8F4: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8007A8F8: beq         $t9, $zero, L_8007A910
    if (ctx->r25 == 0) {
        // 0x8007A8FC: nop

            goto L_8007A910;
    }
    // 0x8007A8FC: nop

    // 0x8007A900: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007A904: lhu         $v0, 0x101C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X101C);
    // 0x8007A908: b           L_8007AA80
    // 0x8007A90C: nop

        goto L_8007AA80;
    // 0x8007A90C: nop

L_8007A910:
    // 0x8007A910: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8007A914: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8007A918: lhu         $t1, 0xFF4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XFF4);
    // 0x8007A91C: lhu         $t0, 0x10F2($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X10F2);
    // 0x8007A920: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007A924: lhu         $t3, 0x7148($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7148);
    // 0x8007A928: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x8007A92C: and         $t4, $t3, $t2
    ctx->r12 = ctx->r11 & ctx->r10;
    // 0x8007A930: beq         $t4, $zero, L_8007A994
    if (ctx->r12 == 0) {
        // 0x8007A934: nop

            goto L_8007A994;
    }
    // 0x8007A934: nop

    // 0x8007A938: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A93C: lw          $t5, 0x70F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F8);
    // 0x8007A940: nop

    // 0x8007A944: beq         $t5, $zero, L_8007A958
    if (ctx->r13 == 0) {
        // 0x8007A948: nop

            goto L_8007A958;
    }
    // 0x8007A948: nop

    // 0x8007A94C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007A950: bne         $t5, $at, L_8007A968
    if (ctx->r13 != ctx->r1) {
        // 0x8007A954: nop

            goto L_8007A968;
    }
    // 0x8007A954: nop

L_8007A958:
    // 0x8007A958: jal         0x800B9000
    // 0x8007A95C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x8007A95C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x8007A960: b           L_8007A970
    // 0x8007A964: nop

        goto L_8007A970;
    // 0x8007A964: nop

L_8007A968:
    // 0x8007A968: jal         0x800B9000
    // 0x8007A96C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8007A96C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_1:
L_8007A970:
    // 0x8007A970: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007A974: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007A978: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x8007A97C: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8007A980: nop

    // 0x8007A984: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x8007A988: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8007A98C: b           L_8007AA80
    // 0x8007A990: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8007AA80;
    // 0x8007A990: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8007A994:
    // 0x8007A994: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A998: lwc1        $f4, 0x713C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X713C);
    // 0x8007A99C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007A9A0: nop

    // 0x8007A9A4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8007A9A8: nop

    // 0x8007A9AC: bc1f        L_8007AA08
    if (!c1cs) {
        // 0x8007A9B0: nop

            goto L_8007AA08;
    }
    // 0x8007A9B0: nop

    // 0x8007A9B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A9B8: lwc1        $f8, 0x713C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X713C);
    // 0x8007A9BC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007A9C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007A9C4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007A9C8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007A9CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007A9D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007A9D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A9D8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8007A9DC: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8007A9E0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007A9E4: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8007A9E8: sra         $t3, $t1, 16
    ctx->r11 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8007A9EC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8007A9F0: nop

    // 0x8007A9F4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007A9F8: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8007A9FC: swc1        $f6, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f6.u32l;
    // 0x8007AA00: b           L_8007AA80
    // 0x8007AA04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007AA80;
    // 0x8007AA04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AA08:
    // 0x8007AA08: jal         0x8007AA90
    // 0x8007AA0C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8007AA90(rdram, ctx);
        goto after_2;
    // 0x8007AA0C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8007AA10: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007AA14: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007AA18: nop

    // 0x8007AA1C: beq         $t2, $zero, L_8007AA70
    if (ctx->r10 == 0) {
        // 0x8007AA20: nop

            goto L_8007AA70;
    }
    // 0x8007AA20: nop

    // 0x8007AA24: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007AA28: lh          $a0, 0x7132($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7132);
    // 0x8007AA2C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8007AA30: jal         0x8007B3DC
    // 0x8007AA34: nop

    func_8007B3DC(rdram, ctx);
        goto after_3;
    // 0x8007AA34: nop

    after_3:
    // 0x8007AA38: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8007AA3C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007AA40: lh          $t5, 0x7132($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7132);
    // 0x8007AA44: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8007AA48: nop

    // 0x8007AA4C: beq         $t4, $t5, L_8007AA70
    if (ctx->r12 == ctx->r13) {
        // 0x8007AA50: nop

            goto L_8007AA70;
    }
    // 0x8007AA50: nop

    // 0x8007AA54: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x8007AA58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AA5C: sh          $t6, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r14;
    // 0x8007AA60: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007AA64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007AA68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AA6C: swc1        $f10, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f10.u32l;
L_8007AA70:
    // 0x8007AA70: b           L_8007AA80
    // 0x8007AA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007AA80;
    // 0x8007AA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007AA78: b           L_8007AA80
    // 0x8007AA7C: nop

        goto L_8007AA80;
    // 0x8007AA7C: nop

L_8007AA80:
    // 0x8007AA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007AA84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007AA88: jr          $ra
    // 0x8007AA8C: nop

    return;
    // 0x8007AA8C: nop

;}
RECOMP_FUNC void func_8007AA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AA90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007AA94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007AA98: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007AA9C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007AAA0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007AAA4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8007AAA8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8007AAAC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007AAB0: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007AAB4: nop

    // 0x8007AAB8: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x8007AABC: beq         $t8, $zero, L_8007AACC
    if (ctx->r24 == 0) {
        // 0x8007AAC0: nop

            goto L_8007AACC;
    }
    // 0x8007AAC0: nop

    // 0x8007AAC4: b           L_8007B11C
    // 0x8007AAC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B11C;
    // 0x8007AAC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AACC:
    // 0x8007AACC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007AAD0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8007AAD4: lhu         $t0, 0xEEC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XEEC);
    // 0x8007AAD8: lhu         $t9, 0x7146($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7146);
    // 0x8007AADC: nop

    // 0x8007AAE0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8007AAE4: beq         $t1, $zero, L_8007ACA8
    if (ctx->r9 == 0) {
        // 0x8007AAE8: nop

            goto L_8007ACA8;
    }
    // 0x8007AAE8: nop

    // 0x8007AAEC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007AAF0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8007AAF4: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8007AAF8: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8007AAFC: lwc1        $f4, 0x10($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X10);
    // 0x8007AB00: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007AB04: nop

    // 0x8007AB08: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8007AB0C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007AB10: lbu         $t5, 0x7134($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7134);
    // 0x8007AB14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007AB18: bne         $t5, $at, L_8007ABD8
    if (ctx->r13 != ctx->r1) {
        // 0x8007AB1C: nop

            goto L_8007ABD8;
    }
    // 0x8007AB1C: nop

    // 0x8007AB20: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007AB24: lb          $t6, 0x7142($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7142);
    // 0x8007AB28: nop

    // 0x8007AB2C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007AB30: slti        $at, $t7, 0x28
    ctx->r1 = SIGNED(ctx->r15) < 0X28 ? 1 : 0;
    // 0x8007AB34: beq         $at, $zero, L_8007AB9C
    if (ctx->r1 == 0) {
        // 0x8007AB38: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8007AB9C;
    }
    // 0x8007AB38: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007AB3C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007AB40: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007AB44: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007AB48: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007AB4C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007AB50: lh          $t9, 0x2460($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2460);
    // 0x8007AB54: nop

    // 0x8007AB58: bgez        $t9, L_8007AB9C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007AB5C: nop

            goto L_8007AB9C;
    }
    // 0x8007AB5C: nop

L_8007AB60:
    // 0x8007AB60: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AB64: nop

    // 0x8007AB68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007AB6C: slti        $at, $t1, 0x28
    ctx->r1 = SIGNED(ctx->r9) < 0X28 ? 1 : 0;
    // 0x8007AB70: beq         $at, $zero, L_8007AB9C
    if (ctx->r1 == 0) {
        // 0x8007AB74: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8007AB9C;
    }
    // 0x8007AB74: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8007AB78: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007AB7C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8007AB80: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007AB84: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8007AB88: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007AB8C: lh          $t3, 0x2460($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2460);
    // 0x8007AB90: nop

    // 0x8007AB94: bltz        $t3, L_8007AB60
    if (SIGNED(ctx->r11) < 0) {
        // 0x8007AB98: nop

            goto L_8007AB60;
    }
    // 0x8007AB98: nop

L_8007AB9C:
    // 0x8007AB9C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007ABA0: nop

    // 0x8007ABA4: slti        $at, $t4, 0x28
    ctx->r1 = SIGNED(ctx->r12) < 0X28 ? 1 : 0;
    // 0x8007ABA8: bne         $at, $zero, L_8007ABBC
    if (ctx->r1 != 0) {
        // 0x8007ABAC: nop

            goto L_8007ABBC;
    }
    // 0x8007ABAC: nop

    // 0x8007ABB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ABB4: b           L_8007ABC8
    // 0x8007ABB8: sb          $zero, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = 0;
        goto L_8007ABC8;
    // 0x8007ABB8: sb          $zero, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = 0;
L_8007ABBC:
    // 0x8007ABBC: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x8007ABC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ABC4: sb          $t5, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r13;
L_8007ABC8:
    // 0x8007ABC8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007ABCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007ABD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ABD4: swc1        $f6, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f6.u32l;
L_8007ABD8:
    // 0x8007ABD8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007ABDC: lbu         $t6, 0x7134($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7134);
    // 0x8007ABE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007ABE4: bne         $t6, $at, L_8007AC60
    if (ctx->r14 != ctx->r1) {
        // 0x8007ABE8: nop

            goto L_8007AC60;
    }
    // 0x8007ABE8: nop

    // 0x8007ABEC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007ABF0: lw          $a0, 0x70FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70FC);
    // 0x8007ABF4: jal         0x8007A514
    // 0x8007ABF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8007A514(rdram, ctx);
        goto after_0;
    // 0x8007ABF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8007ABFC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007AC00: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007AC04: nop

    // 0x8007AC08: beq         $t7, $zero, L_8007AC20
    if (ctx->r15 == 0) {
        // 0x8007AC0C: nop

            goto L_8007AC20;
    }
    // 0x8007AC0C: nop

    // 0x8007AC10: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007AC14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AC18: b           L_8007AC34
    // 0x8007AC1C: sw          $t8, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r24;
        goto L_8007AC34;
    // 0x8007AC1C: sw          $t8, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r24;
L_8007AC20:
    // 0x8007AC20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007AC24: jal         0x8007A514
    // 0x8007AC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8007A514(rdram, ctx);
        goto after_1;
    // 0x8007AC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8007AC2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AC30: sw          $v0, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r2;
L_8007AC34:
    // 0x8007AC34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007AC38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007AC3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AC40: swc1        $f8, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f8.u32l;
    // 0x8007AC44: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007AC48: lw          $t9, 0x70FC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70FC);
    // 0x8007AC4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AC50: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8007AC54: nop

    // 0x8007AC58: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007AC5C: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
L_8007AC60:
    // 0x8007AC60: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007AC64: lbu         $t2, 0x7134($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7134);
    // 0x8007AC68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007AC6C: bne         $t2, $at, L_8007ACA8
    if (ctx->r10 != ctx->r1) {
        // 0x8007AC70: nop

            goto L_8007ACA8;
    }
    // 0x8007AC70: nop

    // 0x8007AC74: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007AC78: lh          $t3, 0x7132($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7132);
    // 0x8007AC7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007AC80: beq         $t3, $at, L_8007AC9C
    if (ctx->r11 == ctx->r1) {
        // 0x8007AC84: nop

            goto L_8007AC9C;
    }
    // 0x8007AC84: nop

    // 0x8007AC88: beq         $t3, $zero, L_8007AC9C
    if (ctx->r11 == 0) {
        // 0x8007AC8C: nop

            goto L_8007AC9C;
    }
    // 0x8007AC8C: nop

    // 0x8007AC90: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007AC94: bne         $t3, $at, L_8007ACA8
    if (ctx->r11 != ctx->r1) {
        // 0x8007AC98: nop

            goto L_8007ACA8;
    }
    // 0x8007AC98: nop

L_8007AC9C:
    // 0x8007AC9C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007ACA0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007ACA4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_8007ACA8:
    // 0x8007ACA8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007ACAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007ACB0: lhu         $t6, 0xEC0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XEC0);
    // 0x8007ACB4: lhu         $t5, 0x7146($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7146);
    // 0x8007ACB8: nop

    // 0x8007ACBC: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8007ACC0: beq         $t7, $zero, L_8007AE7C
    if (ctx->r15 == 0) {
        // 0x8007ACC4: nop

            goto L_8007AE7C;
    }
    // 0x8007ACC4: nop

    // 0x8007ACC8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007ACCC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007ACD0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8007ACD4: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8007ACD8: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8007ACDC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007ACE0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8007ACE4: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x8007ACE8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007ACEC: lbu         $t1, 0x7134($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7134);
    // 0x8007ACF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007ACF4: bne         $t1, $at, L_8007ADAC
    if (ctx->r9 != ctx->r1) {
        // 0x8007ACF8: nop

            goto L_8007ADAC;
    }
    // 0x8007ACF8: nop

    // 0x8007ACFC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007AD00: lb          $t2, 0x7142($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7142);
    // 0x8007AD04: nop

    // 0x8007AD08: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8007AD0C: bltz        $t3, L_8007AD70
    if (SIGNED(ctx->r11) < 0) {
        // 0x8007AD10: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_8007AD70;
    }
    // 0x8007AD10: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8007AD14: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007AD18: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007AD1C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007AD20: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007AD24: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8007AD28: lh          $t5, 0x2460($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2460);
    // 0x8007AD2C: nop

    // 0x8007AD30: bgez        $t5, L_8007AD70
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007AD34: nop

            goto L_8007AD70;
    }
    // 0x8007AD34: nop

L_8007AD38:
    // 0x8007AD38: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AD3C: nop

    // 0x8007AD40: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007AD44: bltz        $t7, L_8007AD70
    if (SIGNED(ctx->r15) < 0) {
        // 0x8007AD48: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8007AD70;
    }
    // 0x8007AD48: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007AD4C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007AD50: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007AD54: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007AD58: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007AD5C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007AD60: lh          $t9, 0x2460($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2460);
    // 0x8007AD64: nop

    // 0x8007AD68: bltz        $t9, L_8007AD38
    if (SIGNED(ctx->r25) < 0) {
        // 0x8007AD6C: nop

            goto L_8007AD38;
    }
    // 0x8007AD6C: nop

L_8007AD70:
    // 0x8007AD70: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AD74: nop

    // 0x8007AD78: bgez        $t0, L_8007AD90
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007AD7C: nop

            goto L_8007AD90;
    }
    // 0x8007AD7C: nop

    // 0x8007AD80: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x8007AD84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AD88: b           L_8007AD9C
    // 0x8007AD8C: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
        goto L_8007AD9C;
    // 0x8007AD8C: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
L_8007AD90:
    // 0x8007AD90: lh          $t2, 0x1E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1E);
    // 0x8007AD94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AD98: sb          $t2, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r10;
L_8007AD9C:
    // 0x8007AD9C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007ADA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007ADA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ADA8: swc1        $f18, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f18.u32l;
L_8007ADAC:
    // 0x8007ADAC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007ADB0: lbu         $t3, 0x7134($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7134);
    // 0x8007ADB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007ADB8: bne         $t3, $at, L_8007AE34
    if (ctx->r11 != ctx->r1) {
        // 0x8007ADBC: nop

            goto L_8007AE34;
    }
    // 0x8007ADBC: nop

    // 0x8007ADC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007ADC4: lw          $a0, 0x70FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70FC);
    // 0x8007ADC8: jal         0x8007A514
    // 0x8007ADCC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8007A514(rdram, ctx);
        goto after_2;
    // 0x8007ADCC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8007ADD0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007ADD4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8007ADD8: nop

    // 0x8007ADDC: beq         $t4, $zero, L_8007ADF4
    if (ctx->r12 == 0) {
        // 0x8007ADE0: nop

            goto L_8007ADF4;
    }
    // 0x8007ADE0: nop

    // 0x8007ADE4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007ADE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ADEC: b           L_8007AE08
    // 0x8007ADF0: sw          $t5, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r13;
        goto L_8007AE08;
    // 0x8007ADF0: sw          $t5, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r13;
L_8007ADF4:
    // 0x8007ADF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007ADF8: jal         0x8007A514
    // 0x8007ADFC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8007A514(rdram, ctx);
        goto after_3;
    // 0x8007ADFC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8007AE00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AE04: sw          $v0, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r2;
L_8007AE08:
    // 0x8007AE08: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007AE0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007AE10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AE14: swc1        $f4, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f4.u32l;
    // 0x8007AE18: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007AE1C: lw          $t6, 0x70FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70FC);
    // 0x8007AE20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AE24: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8007AE28: nop

    // 0x8007AE2C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007AE30: sb          $t8, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r24;
L_8007AE34:
    // 0x8007AE34: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007AE38: lbu         $t9, 0x7134($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7134);
    // 0x8007AE3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007AE40: bne         $t9, $at, L_8007AE7C
    if (ctx->r25 != ctx->r1) {
        // 0x8007AE44: nop

            goto L_8007AE7C;
    }
    // 0x8007AE44: nop

    // 0x8007AE48: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007AE4C: lh          $t0, 0x7132($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7132);
    // 0x8007AE50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007AE54: beq         $t0, $at, L_8007AE70
    if (ctx->r8 == ctx->r1) {
        // 0x8007AE58: nop

            goto L_8007AE70;
    }
    // 0x8007AE58: nop

    // 0x8007AE5C: beq         $t0, $zero, L_8007AE70
    if (ctx->r8 == 0) {
        // 0x8007AE60: nop

            goto L_8007AE70;
    }
    // 0x8007AE60: nop

    // 0x8007AE64: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007AE68: bne         $t0, $at, L_8007AE7C
    if (ctx->r8 != ctx->r1) {
        // 0x8007AE6C: nop

            goto L_8007AE7C;
    }
    // 0x8007AE6C: nop

L_8007AE70:
    // 0x8007AE70: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007AE74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007AE78: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_8007AE7C:
    // 0x8007AE7C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007AE80: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8007AE84: lhu         $t3, 0xE68($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XE68);
    // 0x8007AE88: lhu         $t2, 0x7146($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X7146);
    // 0x8007AE8C: nop

    // 0x8007AE90: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8007AE94: beq         $t4, $zero, L_8007AFAC
    if (ctx->r12 == 0) {
        // 0x8007AE98: nop

            goto L_8007AFAC;
    }
    // 0x8007AE98: nop

    // 0x8007AE9C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007AEA0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8007AEA4: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8007AEA8: lwc1        $f6, 0x14($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8007AEAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007AEB0: nop

    // 0x8007AEB4: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8007AEB8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007AEBC: lbu         $t7, 0x7134($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7134);
    // 0x8007AEC0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007AEC4: bne         $t7, $at, L_8007AEF4
    if (ctx->r15 != ctx->r1) {
        // 0x8007AEC8: nop

            goto L_8007AEF4;
    }
    // 0x8007AEC8: nop

    // 0x8007AECC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007AED0: lh          $t8, 0x7132($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7132);
    // 0x8007AED4: nop

    // 0x8007AED8: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x8007AEDC: bne         $at, $zero, L_8007AEF4
    if (ctx->r1 != 0) {
        // 0x8007AEE0: nop

            goto L_8007AEF4;
    }
    // 0x8007AEE0: nop

    // 0x8007AEE4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8007AEE8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007AEEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007AEF0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_8007AEF4:
    // 0x8007AEF4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007AEF8: lbu         $t1, 0x7134($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7134);
    // 0x8007AEFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007AF00: bne         $t1, $at, L_8007AFAC
    if (ctx->r9 != ctx->r1) {
        // 0x8007AF04: nop

            goto L_8007AFAC;
    }
    // 0x8007AF04: nop

    // 0x8007AF08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007AF0C: lh          $t2, 0x7132($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7132);
    // 0x8007AF10: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007AF14: bne         $t2, $at, L_8007AF3C
    if (ctx->r10 != ctx->r1) {
        // 0x8007AF18: nop

            goto L_8007AF3C;
    }
    // 0x8007AF18: nop

    // 0x8007AF1C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007AF20: lh          $t3, 0x7144($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7144);
    // 0x8007AF24: addiu       $t5, $zero, -0x6
    ctx->r13 = ADD32(0, -0X6);
    // 0x8007AF28: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8007AF2C: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x8007AF30: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007AF34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007AF38: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_8007AF3C:
    // 0x8007AF3C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007AF40: lh          $t8, 0x7132($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7132);
    // 0x8007AF44: nop

    // 0x8007AF48: blez        $t8, L_8007AFAC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007AF4C: nop

            goto L_8007AFAC;
    }
    // 0x8007AF4C: nop

    // 0x8007AF50: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8007AF54: beq         $at, $zero, L_8007AFAC
    if (ctx->r1 == 0) {
        // 0x8007AF58: nop

            goto L_8007AFAC;
    }
    // 0x8007AF58: nop

    // 0x8007AF5C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007AF60: lw          $t9, 0x70F8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F8);
    // 0x8007AF64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007AF68: bne         $t9, $at, L_8007AFA0
    if (ctx->r25 != ctx->r1) {
        // 0x8007AF6C: nop

            goto L_8007AFA0;
    }
    // 0x8007AF6C: nop

    // 0x8007AF70: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007AF74: lh          $t0, 0x7132($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7132);
    // 0x8007AF78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AF7C: sh          $t0, 0x7144($at)
    MEM_H(0X7144, ctx->r1) = ctx->r8;
    // 0x8007AF80: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007AF84: lh          $t1, 0x7132($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7132);
    // 0x8007AF88: nop

    // 0x8007AF8C: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8007AF90: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8007AF94: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007AF98: b           L_8007AFAC
    // 0x8007AF9C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
        goto L_8007AFAC;
    // 0x8007AF9C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_8007AFA0:
    // 0x8007AFA0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007AFA4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007AFA8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8007AFAC:
    // 0x8007AFAC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007AFB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007AFB4: lhu         $t6, 0xE74($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XE74);
    // 0x8007AFB8: lhu         $t4, 0x7146($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X7146);
    // 0x8007AFBC: nop

    // 0x8007AFC0: and         $t7, $t4, $t6
    ctx->r15 = ctx->r12 & ctx->r14;
    // 0x8007AFC4: beq         $t7, $zero, L_8007B0B4
    if (ctx->r15 == 0) {
        // 0x8007AFC8: nop

            goto L_8007B0B4;
    }
    // 0x8007AFC8: nop

    // 0x8007AFCC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8007AFD0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007AFD4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8007AFD8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8007AFDC: lwc1        $f8, 0x14($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8007AFE0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007AFE4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8007AFE8: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x8007AFEC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007AFF0: lbu         $t1, 0x7134($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7134);
    // 0x8007AFF4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007AFF8: bne         $t1, $at, L_8007B028
    if (ctx->r9 != ctx->r1) {
        // 0x8007AFFC: nop

            goto L_8007B028;
    }
    // 0x8007AFFC: nop

    // 0x8007B000: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007B004: lh          $t2, 0x7132($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7132);
    // 0x8007B008: nop

    // 0x8007B00C: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x8007B010: bne         $at, $zero, L_8007B028
    if (ctx->r1 != 0) {
        // 0x8007B014: nop

            goto L_8007B028;
    }
    // 0x8007B014: nop

    // 0x8007B018: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007B01C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8007B020: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007B024: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8007B028:
    // 0x8007B028: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B02C: lbu         $t4, 0x7134($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7134);
    // 0x8007B030: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007B034: bne         $t4, $at, L_8007B0B4
    if (ctx->r12 != ctx->r1) {
        // 0x8007B038: nop

            goto L_8007B0B4;
    }
    // 0x8007B038: nop

    // 0x8007B03C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B040: lh          $t6, 0x7132($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7132);
    // 0x8007B044: nop

    // 0x8007B048: bne         $t6, $zero, L_8007B068
    if (ctx->r14 != 0) {
        // 0x8007B04C: nop

            goto L_8007B068;
    }
    // 0x8007B04C: nop

    // 0x8007B050: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B054: lh          $t7, 0x7144($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7144);
    // 0x8007B058: nop

    // 0x8007B05C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007B060: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007B064: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_8007B068:
    // 0x8007B068: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007B06C: lh          $t9, 0x7132($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7132);
    // 0x8007B070: nop

    // 0x8007B074: blez        $t9, L_8007B0B4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007B078: nop

            goto L_8007B0B4;
    }
    // 0x8007B078: nop

    // 0x8007B07C: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x8007B080: beq         $at, $zero, L_8007B0B4
    if (ctx->r1 == 0) {
        // 0x8007B084: nop

            goto L_8007B0B4;
    }
    // 0x8007B084: nop

    // 0x8007B088: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007B08C: lh          $t0, 0x7132($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7132);
    // 0x8007B090: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B094: sh          $t0, 0x7144($at)
    MEM_H(0X7144, ctx->r1) = ctx->r8;
    // 0x8007B098: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007B09C: lh          $t1, 0x7132($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7132);
    // 0x8007B0A0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8007B0A4: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x8007B0A8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8007B0AC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007B0B0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8007B0B4:
    // 0x8007B0B4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007B0B8: nop

    // 0x8007B0BC: bgez        $t4, L_8007B0CC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007B0C0: nop

            goto L_8007B0CC;
    }
    // 0x8007B0C0: nop

    // 0x8007B0C4: b           L_8007B11C
    // 0x8007B0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B11C;
    // 0x8007B0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B0CC:
    // 0x8007B0CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007B0D0: nop

    // 0x8007B0D4: beq         $t6, $zero, L_8007B0E8
    if (ctx->r14 == 0) {
        // 0x8007B0D8: nop

            goto L_8007B0E8;
    }
    // 0x8007B0D8: nop

    // 0x8007B0DC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B0E0: b           L_8007B11C
    // 0x8007B0E4: nop

        goto L_8007B11C;
    // 0x8007B0E4: nop

L_8007B0E8:
    // 0x8007B0E8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B0EC: lbu         $t7, 0x7134($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7134);
    // 0x8007B0F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007B0F4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007B0F8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8007B0FC: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x8007B100: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007B104: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8007B108: lh          $v0, 0x23D0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X23D0);
    // 0x8007B10C: b           L_8007B11C
    // 0x8007B110: nop

        goto L_8007B11C;
    // 0x8007B110: nop

    // 0x8007B114: b           L_8007B11C
    // 0x8007B118: nop

        goto L_8007B11C;
    // 0x8007B118: nop

L_8007B11C:
    // 0x8007B11C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B120: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007B124: jr          $ra
    // 0x8007B128: nop

    return;
    // 0x8007B128: nop

;}
RECOMP_FUNC void func_8007B12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B12C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007B130: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007B134: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007B138: nop

    // 0x8007B13C: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007B140: nop

    // 0x8007B144: bne         $t7, $zero, L_8007B16C
    if (ctx->r15 != 0) {
        // 0x8007B148: nop

            goto L_8007B16C;
    }
    // 0x8007B148: nop

    // 0x8007B14C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007B150: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007B154: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007B158: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007B15C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B160: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007B164: b           L_8007B3D4
    // 0x8007B168: nop

        goto L_8007B3D4;
    // 0x8007B168: nop

L_8007B16C:
    // 0x8007B16C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007B170: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007B174: lh          $t3, 0x7132($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7132);
    // 0x8007B178: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8007B17C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8007B180: lw          $t2, 0x144($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X144);
    // 0x8007B184: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8007B188: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8007B18C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8007B190: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8007B194: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007B198: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x8007B19C: addiu       $t9, $t9, 0x70F0
    ctx->r25 = ADD32(ctx->r25, 0X70F0);
    // 0x8007B1A0: sh          $t8, 0x3C($t9)
    MEM_H(0X3C, ctx->r25) = ctx->r24;
    // 0x8007B1A4: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8007B1A8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B1AC: lh          $t3, 0xE($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XE);
    // 0x8007B1B0: addiu       $t4, $t4, 0x70F0
    ctx->r12 = ADD32(ctx->r12, 0X70F0);
    // 0x8007B1B4: sh          $t3, 0x3E($t4)
    MEM_H(0X3E, ctx->r12) = ctx->r11;
    // 0x8007B1B8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007B1BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B1C0: beq         $t0, $at, L_8007B1DC
    if (ctx->r8 == ctx->r1) {
        // 0x8007B1C4: nop

            goto L_8007B1DC;
    }
    // 0x8007B1C4: nop

    // 0x8007B1C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007B1CC: beq         $t0, $at, L_8007B25C
    if (ctx->r8 == ctx->r1) {
        // 0x8007B1D0: nop

            goto L_8007B25C;
    }
    // 0x8007B1D0: nop

    // 0x8007B1D4: b           L_8007B2DC
    // 0x8007B1D8: nop

        goto L_8007B2DC;
    // 0x8007B1D8: nop

L_8007B1DC:
    // 0x8007B1DC: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8007B1E0: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007B1E4: lh          $t5, 0xC($t2)
    ctx->r13 = MEM_H(ctx->r10, 0XC);
    // 0x8007B1E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007B1EC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8007B1F0: nop

    // 0x8007B1F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007B1F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007B1FC: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8007B200: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007B204: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8007B208: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8007B20C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8007B210: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x8007B214: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007B218: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8007B21C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007B220: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007B224: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007B228: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8007B22C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007B230: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x8007B234: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007B23C: nop

    // 0x8007B240: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8007B244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B248: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007B24C: nop

    // 0x8007B250: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x8007B254: b           L_8007B3CC
    // 0x8007B258: nop

        goto L_8007B3CC;
    // 0x8007B258: nop

L_8007B25C:
    // 0x8007B25C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8007B260: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007B264: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8007B268: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007B26C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8007B270: nop

    // 0x8007B274: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B278: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007B27C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8007B280: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007B284: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8007B288: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8007B28C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8007B290: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x8007B294: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007B298: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8007B29C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007B2A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B2A4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007B2A8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8007B2AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007B2B0: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8007B2B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B2B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007B2BC: nop

    // 0x8007B2C0: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x8007B2C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B2C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B2CC: nop

    // 0x8007B2D0: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8007B2D4: b           L_8007B3CC
    // 0x8007B2D8: nop

        goto L_8007B3CC;
    // 0x8007B2D8: nop

L_8007B2DC:
    // 0x8007B2DC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8007B2E0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007B2E4: lh          $t2, 0x0($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X0);
    // 0x8007B2E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007B2EC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007B2F0: nop

    // 0x8007B2F4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007B2F8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8007B2FC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8007B300: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007B304: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8007B308: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8007B30C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8007B310: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8007B314: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007B318: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8007B31C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007B320: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007B324: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8007B328: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8007B32C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007B330: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8007B334: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8007B338: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007B33C: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8007B340: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x8007B344: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8007B348: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007B34C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007B350: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007B354: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007B358: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8007B35C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x8007B360: c.le.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d <= ctx->f10.d;
    // 0x8007B364: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x8007B368: bc1f        L_8007B380
    if (!c1cs) {
        // 0x8007B36C: nop

            goto L_8007B380;
    }
    // 0x8007B36C: nop

    // 0x8007B370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B374: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007B378: nop

    // 0x8007B37C: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
L_8007B380:
    // 0x8007B380: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8007B384: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8007B388: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x8007B38C: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x8007B390: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8007B394: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8007B398: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007B39C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007B3A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007B3A4: sub.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f12.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8007B3A8: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x8007B3AC: c.le.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d <= ctx->f16.d;
    // 0x8007B3B0: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
    // 0x8007B3B4: bc1f        L_8007B3CC
    if (!c1cs) {
        // 0x8007B3B8: nop

            goto L_8007B3CC;
    }
    // 0x8007B3B8: nop

    // 0x8007B3BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B3C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007B3C4: nop

    // 0x8007B3C8: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_8007B3CC:
    // 0x8007B3CC: b           L_8007B3D4
    // 0x8007B3D0: nop

        goto L_8007B3D4;
    // 0x8007B3D0: nop

L_8007B3D4:
    // 0x8007B3D4: jr          $ra
    // 0x8007B3D8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007B3D8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8007B3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B3DC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8007B3E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B3E4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007B3E8: bne         $a1, $zero, L_8007B3F8
    if (ctx->r5 != 0) {
        // 0x8007B3EC: nop

            goto L_8007B3F8;
    }
    // 0x8007B3EC: nop

    // 0x8007B3F0: b           L_8007B708
    // 0x8007B3F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B708;
    // 0x8007B3F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B3F8:
    // 0x8007B3F8: blez        $a1, L_8007B574
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007B3FC: nop

            goto L_8007B574;
    }
    // 0x8007B3FC: nop

    // 0x8007B400: sh          $a0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r4;
    // 0x8007B404: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8007B408: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8007B40C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8007B410: nop

    // 0x8007B414: bltz        $t7, L_8007B56C
    if (SIGNED(ctx->r15) < 0) {
        // 0x8007B418: nop

            goto L_8007B56C;
    }
    // 0x8007B418: nop

L_8007B41C:
    // 0x8007B41C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B420: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8007B424: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8007B428: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B42C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8007B430: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007B434: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8007B438: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x8007B43C: lw          $t1, 0x144($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X144);
    // 0x8007B440: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8007B444: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8007B448: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x8007B44C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8007B450: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8007B454: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8007B458: nop

    // 0x8007B45C: bne         $t6, $at, L_8007B484
    if (ctx->r14 != ctx->r1) {
        // 0x8007B460: nop

            goto L_8007B484;
    }
    // 0x8007B460: nop

    // 0x8007B464: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x8007B468: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8007B46C: bne         $t7, $at, L_8007B484
    if (ctx->r15 != ctx->r1) {
        // 0x8007B470: nop

            goto L_8007B484;
    }
    // 0x8007B470: nop

    // 0x8007B474: lh          $a0, 0x6($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6);
    // 0x8007B478: nop

    // 0x8007B47C: b           L_8007B56C
    // 0x8007B480: nop

        goto L_8007B56C;
    // 0x8007B480: nop

L_8007B484:
    // 0x8007B484: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8007B488: addiu       $at, $zero, 0x6319
    ctx->r1 = ADD32(0, 0X6319);
    // 0x8007B48C: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x8007B490: nop

    // 0x8007B494: bne         $t9, $at, L_8007B4B4
    if (ctx->r25 != ctx->r1) {
        // 0x8007B498: nop

            goto L_8007B4B4;
    }
    // 0x8007B498: nop

    // 0x8007B49C: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x8007B4A0: nop

    // 0x8007B4A4: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8007B4A8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8007B4AC: b           L_8007B558
    // 0x8007B4B0: nop

        goto L_8007B558;
    // 0x8007B4B0: nop

L_8007B4B4:
    // 0x8007B4B4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007B4B8: lw          $t1, 0x7100($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7100);
    // 0x8007B4BC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007B4C0: bne         $t1, $at, L_8007B500
    if (ctx->r9 != ctx->r1) {
        // 0x8007B4C4: nop

            goto L_8007B500;
    }
    // 0x8007B4C4: nop

    // 0x8007B4C8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007B4CC: lw          $t3, 0x7104($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7104);
    // 0x8007B4D0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007B4D4: bne         $t3, $at, L_8007B500
    if (ctx->r11 != ctx->r1) {
        // 0x8007B4D8: nop

            goto L_8007B500;
    }
    // 0x8007B4D8: nop

    // 0x8007B4DC: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x8007B4E0: bne         $at, $zero, L_8007B500
    if (ctx->r1 != 0) {
        // 0x8007B4E4: nop

            goto L_8007B500;
    }
    // 0x8007B4E4: nop

    // 0x8007B4E8: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x8007B4EC: beq         $at, $zero, L_8007B500
    if (ctx->r1 == 0) {
        // 0x8007B4F0: nop

            goto L_8007B500;
    }
    // 0x8007B4F0: nop

    // 0x8007B4F4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007B4F8: b           L_8007B56C
    // 0x8007B4FC: nop

        goto L_8007B56C;
    // 0x8007B4FC: nop

L_8007B500:
    // 0x8007B500: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B504: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007B508: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007B50C: bne         $t4, $at, L_8007B558
    if (ctx->r12 != ctx->r1) {
        // 0x8007B510: nop

            goto L_8007B558;
    }
    // 0x8007B510: nop

    // 0x8007B514: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B518: lw          $t6, 0x7104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7104);
    // 0x8007B51C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007B520: bne         $t6, $at, L_8007B558
    if (ctx->r14 != ctx->r1) {
        // 0x8007B524: nop

            goto L_8007B558;
    }
    // 0x8007B524: nop

    // 0x8007B528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B52C: bne         $a0, $at, L_8007B558
    if (ctx->r4 != ctx->r1) {
        // 0x8007B530: nop

            goto L_8007B558;
    }
    // 0x8007B530: nop

    // 0x8007B534: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007B538: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007B53C: nop

    // 0x8007B540: andi        $t7, $t5, 0x100
    ctx->r15 = ctx->r13 & 0X100;
    // 0x8007B544: beq         $t7, $zero, L_8007B558
    if (ctx->r15 == 0) {
        // 0x8007B548: nop

            goto L_8007B558;
    }
    // 0x8007B548: nop

    // 0x8007B54C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8007B550: b           L_8007B56C
    // 0x8007B554: nop

        goto L_8007B56C;
    // 0x8007B554: nop

L_8007B558:
    // 0x8007B558: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8007B55C: nop

    // 0x8007B560: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007B564: bgez        $t9, L_8007B41C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007B568: sw          $t9, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r25;
            goto L_8007B41C;
    }
    // 0x8007B568: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
L_8007B56C:
    // 0x8007B56C: b           L_8007B708
    // 0x8007B570: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B708;
    // 0x8007B570: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B574:
    // 0x8007B574: sh          $a0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r4;
    // 0x8007B578: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8007B57C: subu        $t2, $t0, $a1
    ctx->r10 = SUB32(ctx->r8, ctx->r5);
    // 0x8007B580: bltz        $t2, L_8007B6F8
    if (SIGNED(ctx->r10) < 0) {
        // 0x8007B584: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_8007B6F8;
    }
    // 0x8007B584: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_8007B588:
    // 0x8007B588: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8007B58C: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x8007B590: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007B594: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B598: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8007B59C: bgez        $a0, L_8007B5B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8007B5A0: nop

            goto L_8007B5B4;
    }
    // 0x8007B5A0: nop

    // 0x8007B5A4: lh          $a0, 0x6($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6);
    // 0x8007B5A8: nop

    // 0x8007B5AC: b           L_8007B6F8
    // 0x8007B5B0: nop

        goto L_8007B6F8;
    // 0x8007B5B0: nop

L_8007B5B4:
    // 0x8007B5B4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B5B8: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007B5BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007B5C0: bne         $t4, $at, L_8007B5F4
    if (ctx->r12 != ctx->r1) {
        // 0x8007B5C4: nop

            goto L_8007B5F4;
    }
    // 0x8007B5C4: nop

    // 0x8007B5C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B5CC: lw          $t6, 0x7104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7104);
    // 0x8007B5D0: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8007B5D4: bne         $t6, $at, L_8007B5F4
    if (ctx->r14 != ctx->r1) {
        // 0x8007B5D8: nop

            goto L_8007B5F4;
    }
    // 0x8007B5D8: nop

    // 0x8007B5DC: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8007B5E0: beq         $at, $zero, L_8007B5F4
    if (ctx->r1 == 0) {
        // 0x8007B5E4: nop

            goto L_8007B5F4;
    }
    // 0x8007B5E4: nop

    // 0x8007B5E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8007B5EC: b           L_8007B6F8
    // 0x8007B5F0: nop

        goto L_8007B6F8;
    // 0x8007B5F0: nop

L_8007B5F4:
    // 0x8007B5F4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007B5F8: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007B5FC: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8007B600: lw          $t7, 0x144($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X144);
    // 0x8007B604: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8007B608: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007B60C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8007B610: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8007B614: addiu       $at, $zero, 0x6319
    ctx->r1 = ADD32(0, 0X6319);
    // 0x8007B618: lhu         $t1, 0xA($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0XA);
    // 0x8007B61C: nop

    // 0x8007B620: bne         $t1, $at, L_8007B640
    if (ctx->r9 != ctx->r1) {
        // 0x8007B624: nop

            goto L_8007B640;
    }
    // 0x8007B624: nop

    // 0x8007B628: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x8007B62C: nop

    // 0x8007B630: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007B634: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x8007B638: b           L_8007B6E4
    // 0x8007B63C: nop

        goto L_8007B6E4;
    // 0x8007B63C: nop

L_8007B640:
    // 0x8007B640: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B644: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007B648: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007B64C: bne         $t6, $at, L_8007B68C
    if (ctx->r14 != ctx->r1) {
        // 0x8007B650: nop

            goto L_8007B68C;
    }
    // 0x8007B650: nop

    // 0x8007B654: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007B658: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007B65C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007B660: bne         $t5, $at, L_8007B68C
    if (ctx->r13 != ctx->r1) {
        // 0x8007B664: nop

            goto L_8007B68C;
    }
    // 0x8007B664: nop

    // 0x8007B668: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x8007B66C: bne         $at, $zero, L_8007B68C
    if (ctx->r1 != 0) {
        // 0x8007B670: nop

            goto L_8007B68C;
    }
    // 0x8007B670: nop

    // 0x8007B674: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x8007B678: beq         $at, $zero, L_8007B68C
    if (ctx->r1 == 0) {
        // 0x8007B67C: nop

            goto L_8007B68C;
    }
    // 0x8007B67C: nop

    // 0x8007B680: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8007B684: b           L_8007B6F8
    // 0x8007B688: nop

        goto L_8007B6F8;
    // 0x8007B688: nop

L_8007B68C:
    // 0x8007B68C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007B690: lw          $t8, 0x7100($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7100);
    // 0x8007B694: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007B698: bne         $t8, $at, L_8007B6E4
    if (ctx->r24 != ctx->r1) {
        // 0x8007B69C: nop

            goto L_8007B6E4;
    }
    // 0x8007B69C: nop

    // 0x8007B6A0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B6A4: lw          $t7, 0x7104($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7104);
    // 0x8007B6A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007B6AC: bne         $t7, $at, L_8007B6E4
    if (ctx->r15 != ctx->r1) {
        // 0x8007B6B0: nop

            goto L_8007B6E4;
    }
    // 0x8007B6B0: nop

    // 0x8007B6B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B6B8: bne         $a0, $at, L_8007B6E4
    if (ctx->r4 != ctx->r1) {
        // 0x8007B6BC: nop

            goto L_8007B6E4;
    }
    // 0x8007B6BC: nop

    // 0x8007B6C0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007B6C4: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007B6C8: nop

    // 0x8007B6CC: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x8007B6D0: beq         $t0, $zero, L_8007B6E4
    if (ctx->r8 == 0) {
        // 0x8007B6D4: nop

            goto L_8007B6E4;
    }
    // 0x8007B6D4: nop

    // 0x8007B6D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007B6DC: b           L_8007B6F8
    // 0x8007B6E0: nop

        goto L_8007B6F8;
    // 0x8007B6E0: nop

L_8007B6E4:
    // 0x8007B6E4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8007B6E8: nop

    // 0x8007B6EC: addiu       $t1, $t2, -0x1
    ctx->r9 = ADD32(ctx->r10, -0X1);
    // 0x8007B6F0: bgez        $t1, L_8007B588
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8007B6F4: sw          $t1, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r9;
            goto L_8007B588;
    }
    // 0x8007B6F4: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
L_8007B6F8:
    // 0x8007B6F8: b           L_8007B708
    // 0x8007B6FC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B708;
    // 0x8007B6FC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007B700: b           L_8007B708
    // 0x8007B704: nop

        goto L_8007B708;
    // 0x8007B704: nop

L_8007B708:
    // 0x8007B708: jr          $ra
    // 0x8007B70C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007B70C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
