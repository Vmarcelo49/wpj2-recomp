#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80067A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A5C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067A60: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067A64: nop

    // 0x80067A68: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80067A6C: nop

    // 0x80067A70: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067A74: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067A78: jr          $ra
    // 0x80067A7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067A7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067A80: jr          $ra
    // 0x80067A84: nop

    return;
    // 0x80067A84: nop

    // 0x80067A88: jr          $ra
    // 0x80067A8C: nop

    return;
    // 0x80067A8C: nop

;}
RECOMP_FUNC void func_80067A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A90: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067A94: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067A98: nop

    // 0x80067A9C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80067AA0: nop

    // 0x80067AA4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067AA8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067AAC: jr          $ra
    // 0x80067AB0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067AB0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067AB4: jr          $ra
    // 0x80067AB8: nop

    return;
    // 0x80067AB8: nop

    // 0x80067ABC: jr          $ra
    // 0x80067AC0: nop

    return;
    // 0x80067AC0: nop

;}
RECOMP_FUNC void func_80067AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067ACC: jal         0x80061348
    // 0x80067AD0: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067AD0: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    after_0:
    // 0x80067AD4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80067AD8: b           L_80067AE8
    // 0x80067ADC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067AE8;
    // 0x80067ADC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067AE0: b           L_80067AE8
    // 0x80067AE4: nop

        goto L_80067AE8;
    // 0x80067AE4: nop

L_80067AE8:
    // 0x80067AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067AF0: jr          $ra
    // 0x80067AF4: nop

    return;
    // 0x80067AF4: nop

;}
RECOMP_FUNC void func_80067AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AF8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067AFC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067B00: nop

    // 0x80067B04: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80067B08: nop

    // 0x80067B0C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067B10: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067B14: jr          $ra
    // 0x80067B18: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067B18: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067B1C: jr          $ra
    // 0x80067B20: nop

    return;
    // 0x80067B20: nop

    // 0x80067B24: jr          $ra
    // 0x80067B28: nop

    return;
    // 0x80067B28: nop

;}
RECOMP_FUNC void func_80067B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B2C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067B30: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067B34: nop

    // 0x80067B38: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80067B3C: nop

    // 0x80067B40: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067B44: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067B48: jr          $ra
    // 0x80067B4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067B4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067B50: jr          $ra
    // 0x80067B54: nop

    return;
    // 0x80067B54: nop

    // 0x80067B58: jr          $ra
    // 0x80067B5C: nop

    return;
    // 0x80067B5C: nop

;}
RECOMP_FUNC void func_80067B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067B68: jal         0x80061488
    // 0x80067B6C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067B6C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_0:
    // 0x80067B70: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067B74: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067B78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067B7C: beq         $v0, $zero, L_80067BA4
    if (ctx->r2 == 0) {
        // 0x80067B80: nop

            goto L_80067BA4;
    }
    // 0x80067B80: nop

    // 0x80067B84: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80067B88: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80067B8C: nop

    // 0x80067B90: lh          $v0, 0xE($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XE);
    // 0x80067B94: nop

    // 0x80067B98: slti        $t8, $v0, 0x64
    ctx->r24 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067B9C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067BA0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067BA4:
    // 0x80067BA4: b           L_80067BB4
    // 0x80067BA8: nop

        goto L_80067BB4;
    // 0x80067BA8: nop

    // 0x80067BAC: b           L_80067BB4
    // 0x80067BB0: nop

        goto L_80067BB4;
    // 0x80067BB0: nop

L_80067BB4:
    // 0x80067BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067BBC: jr          $ra
    // 0x80067BC0: nop

    return;
    // 0x80067BC0: nop

;}
RECOMP_FUNC void func_80067BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067BCC: jal         0x80061488
    // 0x80067BD0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067BD0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_0:
    // 0x80067BD4: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067BD8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067BDC: b           L_80067BEC
    // 0x80067BE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067BEC;
    // 0x80067BE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067BE4: b           L_80067BEC
    // 0x80067BE8: nop

        goto L_80067BEC;
    // 0x80067BE8: nop

L_80067BEC:
    // 0x80067BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067BF4: jr          $ra
    // 0x80067BF8: nop

    return;
    // 0x80067BF8: nop

;}
RECOMP_FUNC void func_80067BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067C00: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067C04: nop

    // 0x80067C08: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067C0C: nop

    // 0x80067C10: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067C14: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067C18: jr          $ra
    // 0x80067C1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067C1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067C20: jr          $ra
    // 0x80067C24: nop

    return;
    // 0x80067C24: nop

    // 0x80067C28: jr          $ra
    // 0x80067C2C: nop

    return;
    // 0x80067C2C: nop

;}
RECOMP_FUNC void func_80067C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067C34: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067C38: nop

    // 0x80067C3C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067C40: nop

    // 0x80067C44: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067C48: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067C4C: jr          $ra
    // 0x80067C50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067C50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067C54: jr          $ra
    // 0x80067C58: nop

    return;
    // 0x80067C58: nop

    // 0x80067C5C: jr          $ra
    // 0x80067C60: nop

    return;
    // 0x80067C60: nop

;}
RECOMP_FUNC void func_80067C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067C68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067C6C: nop

    // 0x80067C70: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80067C74: nop

    // 0x80067C78: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067C7C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067C80: jr          $ra
    // 0x80067C84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067C84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067C88: jr          $ra
    // 0x80067C8C: nop

    return;
    // 0x80067C8C: nop

    // 0x80067C90: jr          $ra
    // 0x80067C94: nop

    return;
    // 0x80067C94: nop

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
RECOMP_FUNC void func_80067CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067CCC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067CD0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067CD4: nop

    // 0x80067CD8: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067CDC: nop

    // 0x80067CE0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067CE4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067CE8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067CEC: beq         $v0, $zero, L_80067D24
    if (ctx->r2 == 0) {
        // 0x80067CF0: nop

            goto L_80067D24;
    }
    // 0x80067CF0: nop

    // 0x80067CF4: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067CF8: nop

    // 0x80067CFC: slti        $t8, $v0, 0x96
    ctx->r24 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067D00: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067D04: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80067D08: beq         $v0, $zero, L_80067D24
    if (ctx->r2 == 0) {
        // 0x80067D0C: nop

            goto L_80067D24;
    }
    // 0x80067D0C: nop

    // 0x80067D10: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067D14: nop

    // 0x80067D18: slti        $t9, $v0, 0x96
    ctx->r25 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067D1C: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80067D20: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80067D24:
    // 0x80067D24: jr          $ra
    // 0x80067D28: nop

    return;
    // 0x80067D28: nop

    // 0x80067D2C: jr          $ra
    // 0x80067D30: nop

    return;
    // 0x80067D30: nop

    // 0x80067D34: jr          $ra
    // 0x80067D38: nop

    return;
    // 0x80067D38: nop

;}
RECOMP_FUNC void func_80067D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067D40: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067D44: nop

    // 0x80067D48: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067D4C: nop

    // 0x80067D50: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067D54: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067D58: jr          $ra
    // 0x80067D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067D60: jr          $ra
    // 0x80067D64: nop

    return;
    // 0x80067D64: nop

    // 0x80067D68: jr          $ra
    // 0x80067D6C: nop

    return;
    // 0x80067D6C: nop

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
RECOMP_FUNC void func_80067DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067DC8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067DCC: nop

    // 0x80067DD0: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067DD4: nop

    // 0x80067DD8: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067DDC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067DE0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067DE4: beq         $v0, $zero, L_80067E00
    if (ctx->r2 == 0) {
        // 0x80067DE8: nop

            goto L_80067E00;
    }
    // 0x80067DE8: nop

    // 0x80067DEC: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067DF0: nop

    // 0x80067DF4: slti        $t8, $v0, 0x258
    ctx->r24 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067DF8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067DFC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067E00:
    // 0x80067E00: jr          $ra
    // 0x80067E04: nop

    return;
    // 0x80067E04: nop

    // 0x80067E08: jr          $ra
    // 0x80067E0C: nop

    return;
    // 0x80067E0C: nop

    // 0x80067E10: jr          $ra
    // 0x80067E14: nop

    return;
    // 0x80067E14: nop

;}
RECOMP_FUNC void func_80067E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067E1C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067E20: nop

    // 0x80067E24: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067E28: nop

    // 0x80067E2C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067E30: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067E34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067E38: beq         $v0, $zero, L_80067E54
    if (ctx->r2 == 0) {
        // 0x80067E3C: nop

            goto L_80067E54;
    }
    // 0x80067E3C: nop

    // 0x80067E40: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067E44: nop

    // 0x80067E48: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067E4C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067E50: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067E54:
    // 0x80067E54: jr          $ra
    // 0x80067E58: nop

    return;
    // 0x80067E58: nop

    // 0x80067E5C: jr          $ra
    // 0x80067E60: nop

    return;
    // 0x80067E60: nop

    // 0x80067E64: jr          $ra
    // 0x80067E68: nop

    return;
    // 0x80067E68: nop

;}
RECOMP_FUNC void func_80067E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067E70: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067E74: nop

    // 0x80067E78: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067E7C: nop

    // 0x80067E80: slti        $t7, $v0, 0x190
    ctx->r15 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80067E84: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067E88: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067E8C: beq         $v0, $zero, L_80067EA8
    if (ctx->r2 == 0) {
        // 0x80067E90: nop

            goto L_80067EA8;
    }
    // 0x80067E90: nop

    // 0x80067E94: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067E98: nop

    // 0x80067E9C: slti        $t8, $v0, 0x190
    ctx->r24 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80067EA0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067EA4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067EA8:
    // 0x80067EA8: jr          $ra
    // 0x80067EAC: nop

    return;
    // 0x80067EAC: nop

    // 0x80067EB0: jr          $ra
    // 0x80067EB4: nop

    return;
    // 0x80067EB4: nop

    // 0x80067EB8: jr          $ra
    // 0x80067EBC: nop

    return;
    // 0x80067EBC: nop

;}
RECOMP_FUNC void func_80067EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067EC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067EC4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067EC8: nop

    // 0x80067ECC: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067ED0: nop

    // 0x80067ED4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067ED8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067EDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067EE0: beq         $v0, $zero, L_80067EFC
    if (ctx->r2 == 0) {
        // 0x80067EE4: nop

            goto L_80067EFC;
    }
    // 0x80067EE4: nop

    // 0x80067EE8: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067EEC: nop

    // 0x80067EF0: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067EF4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067EF8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067EFC:
    // 0x80067EFC: jr          $ra
    // 0x80067F00: nop

    return;
    // 0x80067F00: nop

    // 0x80067F04: jr          $ra
    // 0x80067F08: nop

    return;
    // 0x80067F08: nop

    // 0x80067F0C: jr          $ra
    // 0x80067F10: nop

    return;
    // 0x80067F10: nop

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
RECOMP_FUNC void func_80067F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067F6C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067F70: nop

    // 0x80067F74: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067F78: nop

    // 0x80067F7C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067F80: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067F84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067F88: beq         $v0, $zero, L_80067FC0
    if (ctx->r2 == 0) {
        // 0x80067F8C: nop

            goto L_80067FC0;
    }
    // 0x80067F8C: nop

    // 0x80067F90: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067F94: nop

    // 0x80067F98: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067F9C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067FA0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80067FA4: beq         $v0, $zero, L_80067FC0
    if (ctx->r2 == 0) {
        // 0x80067FA8: nop

            goto L_80067FC0;
    }
    // 0x80067FA8: nop

    // 0x80067FAC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067FB0: nop

    // 0x80067FB4: slti        $t9, $v0, 0x12C
    ctx->r25 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067FB8: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80067FBC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80067FC0:
    // 0x80067FC0: jr          $ra
    // 0x80067FC4: nop

    return;
    // 0x80067FC4: nop

    // 0x80067FC8: jr          $ra
    // 0x80067FCC: nop

    return;
    // 0x80067FCC: nop

    // 0x80067FD0: jr          $ra
    // 0x80067FD4: nop

    return;
    // 0x80067FD4: nop

;}
RECOMP_FUNC void func_80067FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067FD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067FDC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067FE0: nop

    // 0x80067FE4: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067FE8: nop

    // 0x80067FEC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067FF0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067FF4: jr          $ra
    // 0x80067FF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067FF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067FFC: jr          $ra
    // 0x80068000: nop

    return;
    // 0x80068000: nop

    // 0x80068004: jr          $ra
    // 0x80068008: nop

    return;
    // 0x80068008: nop

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
RECOMP_FUNC void func_8006807C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006807C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068080: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068084: nop

    // 0x80068088: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006808C: nop

    // 0x80068090: slti        $t7, $v0, 0x190
    ctx->r15 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80068094: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068098: jr          $ra
    // 0x8006809C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006809C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800680A0: jr          $ra
    // 0x800680A4: nop

    return;
    // 0x800680A4: nop

    // 0x800680A8: jr          $ra
    // 0x800680AC: nop

    return;
    // 0x800680AC: nop

;}
RECOMP_FUNC void func_800680B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800680B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800680B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800680B8: nop

    // 0x800680BC: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x800680C0: nop

    // 0x800680C4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800680C8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800680CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800680D0: beq         $v0, $zero, L_80068108
    if (ctx->r2 == 0) {
        // 0x800680D4: nop

            goto L_80068108;
    }
    // 0x800680D4: nop

    // 0x800680D8: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800680DC: nop

    // 0x800680E0: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800680E4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800680E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800680EC: beq         $v0, $zero, L_80068108
    if (ctx->r2 == 0) {
        // 0x800680F0: nop

            goto L_80068108;
    }
    // 0x800680F0: nop

    // 0x800680F4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800680F8: nop

    // 0x800680FC: slti        $t9, $v0, 0x1F4
    ctx->r25 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068100: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80068104: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80068108:
    // 0x80068108: jr          $ra
    // 0x8006810C: nop

    return;
    // 0x8006810C: nop

    // 0x80068110: jr          $ra
    // 0x80068114: nop

    return;
    // 0x80068114: nop

    // 0x80068118: jr          $ra
    // 0x8006811C: nop

    return;
    // 0x8006811C: nop

;}
RECOMP_FUNC void func_80068120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068120: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068124: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068128: nop

    // 0x8006812C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80068130: nop

    // 0x80068134: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068138: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006813C: jr          $ra
    // 0x80068140: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068140: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068144: jr          $ra
    // 0x80068148: nop

    return;
    // 0x80068148: nop

    // 0x8006814C: jr          $ra
    // 0x80068150: nop

    return;
    // 0x80068150: nop

;}
RECOMP_FUNC void func_80068154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068154: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068158: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006815C: nop

    // 0x80068160: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80068164: nop

    // 0x80068168: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x8006816C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068170: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068174: beq         $v0, $zero, L_800681AC
    if (ctx->r2 == 0) {
        // 0x80068178: nop

            goto L_800681AC;
    }
    // 0x80068178: nop

    // 0x8006817C: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80068180: nop

    // 0x80068184: slti        $t8, $v0, 0x258
    ctx->r24 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80068188: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006818C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80068190: beq         $v0, $zero, L_800681AC
    if (ctx->r2 == 0) {
        // 0x80068194: nop

            goto L_800681AC;
    }
    // 0x80068194: nop

    // 0x80068198: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8006819C: nop

    // 0x800681A0: slti        $t9, $v0, 0x258
    ctx->r25 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x800681A4: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x800681A8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800681AC:
    // 0x800681AC: jr          $ra
    // 0x800681B0: nop

    return;
    // 0x800681B0: nop

    // 0x800681B4: jr          $ra
    // 0x800681B8: nop

    return;
    // 0x800681B8: nop

    // 0x800681BC: jr          $ra
    // 0x800681C0: nop

    return;
    // 0x800681C0: nop

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
RECOMP_FUNC void func_800681F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800681F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800681FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068200: nop

    // 0x80068204: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80068208: nop

    // 0x8006820C: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80068210: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068214: jr          $ra
    // 0x80068218: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068218: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006821C: jr          $ra
    // 0x80068220: nop

    return;
    // 0x80068220: nop

    // 0x80068224: jr          $ra
    // 0x80068228: nop

    return;
    // 0x80068228: nop

;}
RECOMP_FUNC void func_8006822C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006822C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068230: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068234: nop

    // 0x80068238: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006823C: nop

    // 0x80068240: slti        $t7, $v0, 0x190
    ctx->r15 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80068244: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006824C: beq         $v0, $zero, L_80068284
    if (ctx->r2 == 0) {
        // 0x80068250: nop

            goto L_80068284;
    }
    // 0x80068250: nop

    // 0x80068254: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80068258: nop

    // 0x8006825C: slti        $t8, $v0, 0x190
    ctx->r24 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80068260: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80068264: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80068268: beq         $v0, $zero, L_80068284
    if (ctx->r2 == 0) {
        // 0x8006826C: nop

            goto L_80068284;
    }
    // 0x8006826C: nop

    // 0x80068270: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80068274: nop

    // 0x80068278: slti        $t9, $v0, 0x190
    ctx->r25 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x8006827C: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80068280: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80068284:
    // 0x80068284: jr          $ra
    // 0x80068288: nop

    return;
    // 0x80068288: nop

    // 0x8006828C: jr          $ra
    // 0x80068290: nop

    return;
    // 0x80068290: nop

    // 0x80068294: jr          $ra
    // 0x80068298: nop

    return;
    // 0x80068298: nop

;}
RECOMP_FUNC void func_8006829C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006829C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800682A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800682A4: nop

    // 0x800682A8: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x800682AC: nop

    // 0x800682B0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800682B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800682B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800682BC: beq         $v0, $zero, L_800682F4
    if (ctx->r2 == 0) {
        // 0x800682C0: nop

            goto L_800682F4;
    }
    // 0x800682C0: nop

    // 0x800682C4: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800682C8: nop

    // 0x800682CC: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800682D0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800682D4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800682D8: beq         $v0, $zero, L_800682F4
    if (ctx->r2 == 0) {
        // 0x800682DC: nop

            goto L_800682F4;
    }
    // 0x800682DC: nop

    // 0x800682E0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800682E4: nop

    // 0x800682E8: slti        $t9, $v0, 0x1F4
    ctx->r25 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800682EC: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x800682F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800682F4:
    // 0x800682F4: jr          $ra
    // 0x800682F8: nop

    return;
    // 0x800682F8: nop

    // 0x800682FC: jr          $ra
    // 0x80068300: nop

    return;
    // 0x80068300: nop

    // 0x80068304: jr          $ra
    // 0x80068308: nop

    return;
    // 0x80068308: nop

;}
RECOMP_FUNC void func_8006830C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006830C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068310: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068314: nop

    // 0x80068318: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006831C: nop

    // 0x80068320: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80068324: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068328: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006832C: beq         $v0, $zero, L_80068364
    if (ctx->r2 == 0) {
        // 0x80068330: nop

            goto L_80068364;
    }
    // 0x80068330: nop

    // 0x80068334: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80068338: nop

    // 0x8006833C: slti        $t8, $v0, 0x258
    ctx->r24 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80068340: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80068344: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80068348: beq         $v0, $zero, L_80068364
    if (ctx->r2 == 0) {
        // 0x8006834C: nop

            goto L_80068364;
    }
    // 0x8006834C: nop

    // 0x80068350: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80068354: nop

    // 0x80068358: slti        $t9, $v0, 0x258
    ctx->r25 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x8006835C: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80068360: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80068364:
    // 0x80068364: jr          $ra
    // 0x80068368: nop

    return;
    // 0x80068368: nop

    // 0x8006836C: jr          $ra
    // 0x80068370: nop

    return;
    // 0x80068370: nop

    // 0x80068374: jr          $ra
    // 0x80068378: nop

    return;
    // 0x80068378: nop

;}
RECOMP_FUNC void func_8006837C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006837C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068380: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068384: nop

    // 0x80068388: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006838C: nop

    // 0x80068390: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80068394: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068398: jr          $ra
    // 0x8006839C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006839C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800683A0: jr          $ra
    // 0x800683A4: nop

    return;
    // 0x800683A4: nop

    // 0x800683A8: jr          $ra
    // 0x800683AC: nop

    return;
    // 0x800683AC: nop

;}
RECOMP_FUNC void func_800683B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800683B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800683B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800683B8: nop

    // 0x800683BC: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x800683C0: nop

    // 0x800683C4: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800683C8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800683CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800683D0: beq         $v0, $zero, L_800683EC
    if (ctx->r2 == 0) {
        // 0x800683D4: nop

            goto L_800683EC;
    }
    // 0x800683D4: nop

    // 0x800683D8: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x800683DC: nop

    // 0x800683E0: slti        $t8, $v0, 0x64
    ctx->r24 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800683E4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800683E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800683EC:
    // 0x800683EC: jr          $ra
    // 0x800683F0: nop

    return;
    // 0x800683F0: nop

    // 0x800683F4: jr          $ra
    // 0x800683F8: nop

    return;
    // 0x800683F8: nop

    // 0x800683FC: jr          $ra
    // 0x80068400: nop

    return;
    // 0x80068400: nop

;}
RECOMP_FUNC void func_80068404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068404: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068408: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006840C: nop

    // 0x80068410: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068414: nop

    // 0x80068418: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006841C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068420: jr          $ra
    // 0x80068424: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068424: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068428: jr          $ra
    // 0x8006842C: nop

    return;
    // 0x8006842C: nop

    // 0x80068430: jr          $ra
    // 0x80068434: nop

    return;
    // 0x80068434: nop

;}
RECOMP_FUNC void func_80068438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068438: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006843C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068440: nop

    // 0x80068444: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80068448: nop

    // 0x8006844C: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80068450: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068454: jr          $ra
    // 0x80068458: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068458: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006845C: jr          $ra
    // 0x80068460: nop

    return;
    // 0x80068460: nop

    // 0x80068464: jr          $ra
    // 0x80068468: nop

    return;
    // 0x80068468: nop

;}
RECOMP_FUNC void func_8006846C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006846C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068474: jal         0x80061488
    // 0x80068478: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068478: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    after_0:
    // 0x8006847C: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80068480: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80068484: b           L_80068494
    // 0x80068488: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068494;
    // 0x80068488: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006848C: b           L_80068494
    // 0x80068490: nop

        goto L_80068494;
    // 0x80068490: nop

L_80068494:
    // 0x80068494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006849C: jr          $ra
    // 0x800684A0: nop

    return;
    // 0x800684A0: nop

;}
RECOMP_FUNC void func_800684A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800684A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800684A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800684AC: jal         0x80061488
    // 0x800684B0: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800684B0: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    after_0:
    // 0x800684B4: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800684B8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800684BC: b           L_800684CC
    // 0x800684C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800684CC;
    // 0x800684C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800684C4: b           L_800684CC
    // 0x800684C8: nop

        goto L_800684CC;
    // 0x800684C8: nop

L_800684CC:
    // 0x800684CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800684D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800684D4: jr          $ra
    // 0x800684D8: nop

    return;
    // 0x800684D8: nop

;}
RECOMP_FUNC void func_800684DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800684DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800684E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800684E4: nop

    // 0x800684E8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800684EC: nop

    // 0x800684F0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800684F4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800684F8: jr          $ra
    // 0x800684FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800684FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068500: jr          $ra
    // 0x80068504: nop

    return;
    // 0x80068504: nop

    // 0x80068508: jr          $ra
    // 0x8006850C: nop

    return;
    // 0x8006850C: nop

;}
RECOMP_FUNC void func_80068510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068510: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068514: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068518: nop

    // 0x8006851C: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x80068520: nop

    // 0x80068524: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80068528: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006852C: jr          $ra
    // 0x80068530: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068530: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068534: jr          $ra
    // 0x80068538: nop

    return;
    // 0x80068538: nop

    // 0x8006853C: jr          $ra
    // 0x80068540: nop

    return;
    // 0x80068540: nop

;}
RECOMP_FUNC void func_80068544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068544: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068548: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006854C: nop

    // 0x80068550: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068554: nop

    // 0x80068558: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006855C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068560: jr          $ra
    // 0x80068564: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068564: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068568: jr          $ra
    // 0x8006856C: nop

    return;
    // 0x8006856C: nop

    // 0x80068570: jr          $ra
    // 0x80068574: nop

    return;
    // 0x80068574: nop

;}
RECOMP_FUNC void func_80068578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068578: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006857C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068580: nop

    // 0x80068584: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068588: nop

    // 0x8006858C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068590: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068594: jr          $ra
    // 0x80068598: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068598: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006859C: jr          $ra
    // 0x800685A0: nop

    return;
    // 0x800685A0: nop

    // 0x800685A4: jr          $ra
    // 0x800685A8: nop

    return;
    // 0x800685A8: nop

;}
RECOMP_FUNC void func_800685AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800685B0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800685B4: nop

    // 0x800685B8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800685BC: nop

    // 0x800685C0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800685C4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800685C8: jr          $ra
    // 0x800685CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800685CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800685D0: jr          $ra
    // 0x800685D4: nop

    return;
    // 0x800685D4: nop

    // 0x800685D8: jr          $ra
    // 0x800685DC: nop

    return;
    // 0x800685DC: nop

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
RECOMP_FUNC void func_80068614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068614: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068618: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006861C: nop

    // 0x80068620: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80068624: nop

    // 0x80068628: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x8006862C: jr          $ra
    // 0x80068630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068634: jr          $ra
    // 0x80068638: nop

    return;
    // 0x80068638: nop

    // 0x8006863C: jr          $ra
    // 0x80068640: nop

    return;
    // 0x80068640: nop

;}
RECOMP_FUNC void func_80068644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068644: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068648: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006864C: nop

    // 0x80068650: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068654: nop

    // 0x80068658: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006865C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068660: jr          $ra
    // 0x80068664: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068664: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068668: jr          $ra
    // 0x8006866C: nop

    return;
    // 0x8006866C: nop

    // 0x80068670: jr          $ra
    // 0x80068674: nop

    return;
    // 0x80068674: nop

;}
RECOMP_FUNC void func_80068678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068678: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006867C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068680: nop

    // 0x80068684: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068688: nop

    // 0x8006868C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068690: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068694: jr          $ra
    // 0x80068698: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068698: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006869C: jr          $ra
    // 0x800686A0: nop

    return;
    // 0x800686A0: nop

    // 0x800686A4: jr          $ra
    // 0x800686A8: nop

    return;
    // 0x800686A8: nop

;}
RECOMP_FUNC void func_800686AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800686AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800686B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800686B4: jal         0x80061488
    // 0x800686B8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800686B8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_0:
    // 0x800686BC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800686C0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800686C4: b           L_800686D4
    // 0x800686C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800686D4;
    // 0x800686C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800686CC: b           L_800686D4
    // 0x800686D0: nop

        goto L_800686D4;
    // 0x800686D0: nop

L_800686D4:
    // 0x800686D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800686D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800686DC: jr          $ra
    // 0x800686E0: nop

    return;
    // 0x800686E0: nop

;}
RECOMP_FUNC void func_800686E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800686E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800686E8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800686EC: nop

    // 0x800686F0: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800686F4: nop

    // 0x800686F8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800686FC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068700: jr          $ra
    // 0x80068704: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068704: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068708: jr          $ra
    // 0x8006870C: nop

    return;
    // 0x8006870C: nop

    // 0x80068710: jr          $ra
    // 0x80068714: nop

    return;
    // 0x80068714: nop

;}
RECOMP_FUNC void func_80068718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068718: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006871C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068720: nop

    // 0x80068724: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068728: nop

    // 0x8006872C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068730: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068734: jr          $ra
    // 0x80068738: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068738: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006873C: jr          $ra
    // 0x80068740: nop

    return;
    // 0x80068740: nop

    // 0x80068744: jr          $ra
    // 0x80068748: nop

    return;
    // 0x80068748: nop

;}
RECOMP_FUNC void func_8006874C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006874C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068750: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068754: nop

    // 0x80068758: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x8006875C: nop

    // 0x80068760: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068764: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068768: jr          $ra
    // 0x8006876C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006876C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068770: jr          $ra
    // 0x80068774: nop

    return;
    // 0x80068774: nop

    // 0x80068778: jr          $ra
    // 0x8006877C: nop

    return;
    // 0x8006877C: nop

;}
