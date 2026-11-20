#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80063B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B20: jal         0x8005F064
    // 0x80063B24: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063B24: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063B28: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063B2C: b           L_80063B3C
    // 0x80063B30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063B3C;
    // 0x80063B30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063B34: b           L_80063B3C
    // 0x80063B38: nop

        goto L_80063B3C;
    // 0x80063B38: nop

L_80063B3C:
    // 0x80063B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063B44: jr          $ra
    // 0x80063B48: nop

    return;
    // 0x80063B48: nop

;}
RECOMP_FUNC void func_80063B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B54: jal         0x8005F064
    // 0x80063B58: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063B58: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063B5C: b           L_80063B6C
    // 0x80063B60: nop

        goto L_80063B6C;
    // 0x80063B60: nop

    // 0x80063B64: b           L_80063B6C
    // 0x80063B68: nop

        goto L_80063B6C;
    // 0x80063B68: nop

L_80063B6C:
    // 0x80063B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063B74: jr          $ra
    // 0x80063B78: nop

    return;
    // 0x80063B78: nop

;}
RECOMP_FUNC void func_80063B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B84: jal         0x8005F064
    // 0x80063B88: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063B88: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063B8C: b           L_80063B9C
    // 0x80063B90: nop

        goto L_80063B9C;
    // 0x80063B90: nop

    // 0x80063B94: b           L_80063B9C
    // 0x80063B98: nop

        goto L_80063B9C;
    // 0x80063B98: nop

L_80063B9C:
    // 0x80063B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063BA4: jr          $ra
    // 0x80063BA8: nop

    return;
    // 0x80063BA8: nop

;}
RECOMP_FUNC void func_80063BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063BAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063BB4: jal         0x8005F064
    // 0x80063BB8: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063BB8: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063BBC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063BC0: b           L_80063BD0
    // 0x80063BC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063BD0;
    // 0x80063BC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063BC8: b           L_80063BD0
    // 0x80063BCC: nop

        goto L_80063BD0;
    // 0x80063BCC: nop

L_80063BD0:
    // 0x80063BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063BD8: jr          $ra
    // 0x80063BDC: nop

    return;
    // 0x80063BDC: nop

;}
RECOMP_FUNC void func_80063BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063BE8: jal         0x8005F064
    // 0x80063BEC: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063BEC: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063BF0: b           L_80063C00
    // 0x80063BF4: nop

        goto L_80063C00;
    // 0x80063BF4: nop

    // 0x80063BF8: b           L_80063C00
    // 0x80063BFC: nop

        goto L_80063C00;
    // 0x80063BFC: nop

L_80063C00:
    // 0x80063C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063C08: jr          $ra
    // 0x80063C0C: nop

    return;
    // 0x80063C0C: nop

;}
RECOMP_FUNC void func_80063C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063C18: jal         0x8005F064
    // 0x80063C1C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063C1C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063C20: b           L_80063C30
    // 0x80063C24: nop

        goto L_80063C30;
    // 0x80063C24: nop

    // 0x80063C28: b           L_80063C30
    // 0x80063C2C: nop

        goto L_80063C30;
    // 0x80063C2C: nop

L_80063C30:
    // 0x80063C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063C38: jr          $ra
    // 0x80063C3C: nop

    return;
    // 0x80063C3C: nop

;}
RECOMP_FUNC void func_80063C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063C48: jal         0x8005F064
    // 0x80063C4C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063C4C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063C50: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063C54: b           L_80063C64
    // 0x80063C58: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063C64;
    // 0x80063C58: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063C5C: b           L_80063C64
    // 0x80063C60: nop

        goto L_80063C64;
    // 0x80063C60: nop

L_80063C64:
    // 0x80063C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063C6C: jr          $ra
    // 0x80063C70: nop

    return;
    // 0x80063C70: nop

;}
RECOMP_FUNC void func_80063C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063C7C: jal         0x8005F064
    // 0x80063C80: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063C80: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x80063C84: b           L_80063C94
    // 0x80063C88: nop

        goto L_80063C94;
    // 0x80063C88: nop

    // 0x80063C8C: b           L_80063C94
    // 0x80063C90: nop

        goto L_80063C94;
    // 0x80063C90: nop

L_80063C94:
    // 0x80063C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063C9C: jr          $ra
    // 0x80063CA0: nop

    return;
    // 0x80063CA0: nop

;}
RECOMP_FUNC void func_80063CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063CAC: jal         0x8005F064
    // 0x80063CB0: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063CB0: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x80063CB4: b           L_80063CC4
    // 0x80063CB8: nop

        goto L_80063CC4;
    // 0x80063CB8: nop

    // 0x80063CBC: b           L_80063CC4
    // 0x80063CC0: nop

        goto L_80063CC4;
    // 0x80063CC0: nop

L_80063CC4:
    // 0x80063CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063CC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063CCC: jr          $ra
    // 0x80063CD0: nop

    return;
    // 0x80063CD0: nop

;}
RECOMP_FUNC void func_80063CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063CDC: jal         0x8005F064
    // 0x80063CE0: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063CE0: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x80063CE4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063CE8: b           L_80063CF8
    // 0x80063CEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063CF8;
    // 0x80063CEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063CF0: b           L_80063CF8
    // 0x80063CF4: nop

        goto L_80063CF8;
    // 0x80063CF4: nop

L_80063CF8:
    // 0x80063CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063D00: jr          $ra
    // 0x80063D04: nop

    return;
    // 0x80063D04: nop

;}
RECOMP_FUNC void func_80063D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D10: jal         0x8005F064
    // 0x80063D14: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063D14: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x80063D18: b           L_80063D28
    // 0x80063D1C: nop

        goto L_80063D28;
    // 0x80063D1C: nop

    // 0x80063D20: b           L_80063D28
    // 0x80063D24: nop

        goto L_80063D28;
    // 0x80063D24: nop

L_80063D28:
    // 0x80063D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063D30: jr          $ra
    // 0x80063D34: nop

    return;
    // 0x80063D34: nop

;}
RECOMP_FUNC void func_80063D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D40: jal         0x80061488
    // 0x80063D44: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063D44: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    after_0:
    // 0x80063D48: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063D4C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063D50: b           L_80063D60
    // 0x80063D54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063D60;
    // 0x80063D54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063D58: b           L_80063D60
    // 0x80063D5C: nop

        goto L_80063D60;
    // 0x80063D5C: nop

L_80063D60:
    // 0x80063D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063D68: jr          $ra
    // 0x80063D6C: nop

    return;
    // 0x80063D6C: nop

;}
RECOMP_FUNC void func_80063D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D78: jal         0x80061488
    // 0x80063D7C: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063D7C: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    after_0:
    // 0x80063D80: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063D84: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063D88: b           L_80063D98
    // 0x80063D8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063D98;
    // 0x80063D8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063D90: b           L_80063D98
    // 0x80063D94: nop

        goto L_80063D98;
    // 0x80063D94: nop

L_80063D98:
    // 0x80063D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063DA0: jr          $ra
    // 0x80063DA4: nop

    return;
    // 0x80063DA4: nop

;}
RECOMP_FUNC void func_80063DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063DA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063DB0: jal         0x80061488
    // 0x80063DB4: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063DB4: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    after_0:
    // 0x80063DB8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063DBC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063DC0: b           L_80063DD0
    // 0x80063DC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063DD0;
    // 0x80063DC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063DC8: b           L_80063DD0
    // 0x80063DCC: nop

        goto L_80063DD0;
    // 0x80063DCC: nop

L_80063DD0:
    // 0x80063DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063DD8: jr          $ra
    // 0x80063DDC: nop

    return;
    // 0x80063DDC: nop

;}
RECOMP_FUNC void func_80063DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063DE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063DE4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063DE8: nop

    // 0x80063DEC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80063DF0: nop

    // 0x80063DF4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80063DF8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063DFC: jr          $ra
    // 0x80063E00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063E00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063E04: jr          $ra
    // 0x80063E08: nop

    return;
    // 0x80063E08: nop

    // 0x80063E0C: jr          $ra
    // 0x80063E10: nop

    return;
    // 0x80063E10: nop

;}
RECOMP_FUNC void func_80063E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063E1C: jal         0x80061348
    // 0x80063E20: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80063E20: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_0:
    // 0x80063E24: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063E28: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063E2C: bne         $v0, $zero, L_80063E44
    if (ctx->r2 != 0) {
        // 0x80063E30: nop

            goto L_80063E44;
    }
    // 0x80063E30: nop

    // 0x80063E34: jal         0x80061348
    // 0x80063E38: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80063E38: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_1:
    // 0x80063E3C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063E40: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80063E44:
    // 0x80063E44: b           L_80063E54
    // 0x80063E48: nop

        goto L_80063E54;
    // 0x80063E48: nop

    // 0x80063E4C: b           L_80063E54
    // 0x80063E50: nop

        goto L_80063E54;
    // 0x80063E50: nop

L_80063E54:
    // 0x80063E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063E5C: jr          $ra
    // 0x80063E60: nop

    return;
    // 0x80063E60: nop

;}
RECOMP_FUNC void func_80063E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063E6C: jal         0x80061488
    // 0x80063E70: addiu       $a0, $zero, 0x5DC
    ctx->r4 = ADD32(0, 0X5DC);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063E70: addiu       $a0, $zero, 0x5DC
    ctx->r4 = ADD32(0, 0X5DC);
    after_0:
    // 0x80063E74: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063E78: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063E7C: b           L_80063E8C
    // 0x80063E80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063E8C;
    // 0x80063E80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063E84: b           L_80063E8C
    // 0x80063E88: nop

        goto L_80063E8C;
    // 0x80063E88: nop

L_80063E8C:
    // 0x80063E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063E90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063E94: jr          $ra
    // 0x80063E98: nop

    return;
    // 0x80063E98: nop

;}
RECOMP_FUNC void func_80063E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063EA4: jal         0x8005F064
    // 0x80063EA8: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063EA8: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_0:
    // 0x80063EAC: b           L_80063EBC
    // 0x80063EB0: nop

        goto L_80063EBC;
    // 0x80063EB0: nop

    // 0x80063EB4: b           L_80063EBC
    // 0x80063EB8: nop

        goto L_80063EBC;
    // 0x80063EB8: nop

L_80063EBC:
    // 0x80063EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063EC4: jr          $ra
    // 0x80063EC8: nop

    return;
    // 0x80063EC8: nop

;}
RECOMP_FUNC void func_80063ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063ECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063ED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063ED4: jal         0x80061488
    // 0x80063ED8: addiu       $a0, $zero, 0x5DE
    ctx->r4 = ADD32(0, 0X5DE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063ED8: addiu       $a0, $zero, 0x5DE
    ctx->r4 = ADD32(0, 0X5DE);
    after_0:
    // 0x80063EDC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80063EE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80063EE4: b           L_80063EF4
    // 0x80063EE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063EF4;
    // 0x80063EE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063EEC: b           L_80063EF4
    // 0x80063EF0: nop

        goto L_80063EF4;
    // 0x80063EF0: nop

L_80063EF4:
    // 0x80063EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063EFC: jr          $ra
    // 0x80063F00: nop

    return;
    // 0x80063F00: nop

;}
RECOMP_FUNC void func_80063F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063F0C: jal         0x8005F064
    // 0x80063F10: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063F10: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_0:
    // 0x80063F14: b           L_80063F24
    // 0x80063F18: nop

        goto L_80063F24;
    // 0x80063F18: nop

    // 0x80063F1C: b           L_80063F24
    // 0x80063F20: nop

        goto L_80063F24;
    // 0x80063F20: nop

L_80063F24:
    // 0x80063F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063F28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063F2C: jr          $ra
    // 0x80063F30: nop

    return;
    // 0x80063F30: nop

;}
RECOMP_FUNC void func_80063F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063F3C: jal         0x80061488
    // 0x80063F40: addiu       $a0, $zero, 0x5DE
    ctx->r4 = ADD32(0, 0X5DE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063F40: addiu       $a0, $zero, 0x5DE
    ctx->r4 = ADD32(0, 0X5DE);
    after_0:
    // 0x80063F44: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063F48: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063F4C: b           L_80063F5C
    // 0x80063F50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063F5C;
    // 0x80063F50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063F54: b           L_80063F5C
    // 0x80063F58: nop

        goto L_80063F5C;
    // 0x80063F58: nop

L_80063F5C:
    // 0x80063F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063F64: jr          $ra
    // 0x80063F68: nop

    return;
    // 0x80063F68: nop

;}
RECOMP_FUNC void func_80063F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063F74: jal         0x80061488
    // 0x80063F78: addiu       $a0, $zero, 0x5E1
    ctx->r4 = ADD32(0, 0X5E1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063F78: addiu       $a0, $zero, 0x5E1
    ctx->r4 = ADD32(0, 0X5E1);
    after_0:
    // 0x80063F7C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063F80: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063F84: b           L_80063F94
    // 0x80063F88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063F94;
    // 0x80063F88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063F8C: b           L_80063F94
    // 0x80063F90: nop

        goto L_80063F94;
    // 0x80063F90: nop

L_80063F94:
    // 0x80063F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063F9C: jr          $ra
    // 0x80063FA0: nop

    return;
    // 0x80063FA0: nop

;}
RECOMP_FUNC void func_80063FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063FAC: jal         0x8005F064
    // 0x80063FB0: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063FB0: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x80063FB4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063FB8: b           L_80063FC8
    // 0x80063FBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063FC8;
    // 0x80063FBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063FC0: b           L_80063FC8
    // 0x80063FC4: nop

        goto L_80063FC8;
    // 0x80063FC4: nop

L_80063FC8:
    // 0x80063FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063FCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063FD0: jr          $ra
    // 0x80063FD4: nop

    return;
    // 0x80063FD4: nop

;}
RECOMP_FUNC void func_80063FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063FE0: jal         0x80061488
    // 0x80063FE4: addiu       $a0, $zero, 0x5E3
    ctx->r4 = ADD32(0, 0X5E3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063FE4: addiu       $a0, $zero, 0x5E3
    ctx->r4 = ADD32(0, 0X5E3);
    after_0:
    // 0x80063FE8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063FEC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063FF0: b           L_80064000
    // 0x80063FF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80064000;
    // 0x80063FF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063FF8: b           L_80064000
    // 0x80063FFC: nop

        goto L_80064000;
    // 0x80063FFC: nop

L_80064000:
    // 0x80064000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064008: jr          $ra
    // 0x8006400C: nop

    return;
    // 0x8006400C: nop

;}
RECOMP_FUNC void func_80064010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064018: jal         0x8005F064
    // 0x8006401C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006401C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064020: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064024: b           L_80064034
    // 0x80064028: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80064034;
    // 0x80064028: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006402C: b           L_80064034
    // 0x80064030: nop

        goto L_80064034;
    // 0x80064030: nop

L_80064034:
    // 0x80064034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006403C: jr          $ra
    // 0x80064040: nop

    return;
    // 0x80064040: nop

;}
RECOMP_FUNC void func_80064044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006404C: jal         0x80061488
    // 0x80064050: addiu       $a0, $zero, 0x5BE
    ctx->r4 = ADD32(0, 0X5BE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064050: addiu       $a0, $zero, 0x5BE
    ctx->r4 = ADD32(0, 0X5BE);
    after_0:
    // 0x80064054: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80064058: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006405C: b           L_8006406C
    // 0x80064060: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006406C;
    // 0x80064060: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064064: b           L_8006406C
    // 0x80064068: nop

        goto L_8006406C;
    // 0x80064068: nop

L_8006406C:
    // 0x8006406C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064074: jr          $ra
    // 0x80064078: nop

    return;
    // 0x80064078: nop

;}
RECOMP_FUNC void func_8006407C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006407C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064084: jal         0x8005F064
    // 0x80064088: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064088: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    after_0:
    // 0x8006408C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064094: beq         $v0, $zero, L_800640AC
    if (ctx->r2 == 0) {
        // 0x80064098: nop

            goto L_800640AC;
    }
    // 0x80064098: nop

    // 0x8006409C: jal         0x8005F064
    // 0x800640A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x800640A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x800640A4: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800640A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800640AC:
    // 0x800640AC: b           L_800640BC
    // 0x800640B0: nop

        goto L_800640BC;
    // 0x800640B0: nop

    // 0x800640B4: b           L_800640BC
    // 0x800640B8: nop

        goto L_800640BC;
    // 0x800640B8: nop

L_800640BC:
    // 0x800640BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800640C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800640C4: jr          $ra
    // 0x800640C8: nop

    return;
    // 0x800640C8: nop

;}
RECOMP_FUNC void func_800640CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800640CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800640D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800640D4: jal         0x8005F064
    // 0x800640D8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800640D8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x800640DC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800640E0: b           L_800640F0
    // 0x800640E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800640F0;
    // 0x800640E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800640E8: b           L_800640F0
    // 0x800640EC: nop

        goto L_800640F0;
    // 0x800640EC: nop

L_800640F0:
    // 0x800640F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800640F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800640F8: jr          $ra
    // 0x800640FC: nop

    return;
    // 0x800640FC: nop

;}
RECOMP_FUNC void func_80064100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064108: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006410C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064110: nop

    // 0x80064114: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064118: nop

    // 0x8006411C: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80064120: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064124: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064128: beq         $v0, $zero, L_80064140
    if (ctx->r2 == 0) {
        // 0x8006412C: nop

            goto L_80064140;
    }
    // 0x8006412C: nop

    // 0x80064130: jal         0x8005F064
    // 0x80064134: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064134: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064138: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006413C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80064140:
    // 0x80064140: b           L_80064150
    // 0x80064144: nop

        goto L_80064150;
    // 0x80064144: nop

    // 0x80064148: b           L_80064150
    // 0x8006414C: nop

        goto L_80064150;
    // 0x8006414C: nop

L_80064150:
    // 0x80064150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064158: jr          $ra
    // 0x8006415C: nop

    return;
    // 0x8006415C: nop

;}
RECOMP_FUNC void func_80064160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064168: jal         0x80061488
    // 0x8006416C: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006416C: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064170: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064174: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064178: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x8006417C: nop

            goto L_8006420C;
    }
    // 0x8006417C: nop

    // 0x80064180: jal         0x80061488
    // 0x80064184: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064184: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064188: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006418C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064190: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x80064194: nop

            goto L_8006420C;
    }
    // 0x80064194: nop

    // 0x80064198: jal         0x80061488
    // 0x8006419C: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x8006419C: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x800641A0: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800641A4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800641A8: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x800641AC: nop

            goto L_8006420C;
    }
    // 0x800641AC: nop

    // 0x800641B0: jal         0x80061488
    // 0x800641B4: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x800641B4: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x800641B8: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800641BC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800641C0: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x800641C4: nop

            goto L_8006420C;
    }
    // 0x800641C4: nop

    // 0x800641C8: jal         0x80061488
    // 0x800641CC: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x800641CC: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x800641D0: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800641D4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800641D8: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x800641DC: nop

            goto L_8006420C;
    }
    // 0x800641DC: nop

    // 0x800641E0: jal         0x8005F064
    // 0x800641E4: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x800641E4: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x800641E8: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x800641EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800641F0: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x800641F4: nop

            goto L_8006420C;
    }
    // 0x800641F4: nop

    // 0x800641F8: jal         0x80061348
    // 0x800641FC: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800641FC: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064200: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064204: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064208: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006420C:
    // 0x8006420C: b           L_8006421C
    // 0x80064210: nop

        goto L_8006421C;
    // 0x80064210: nop

    // 0x80064214: b           L_8006421C
    // 0x80064218: nop

        goto L_8006421C;
    // 0x80064218: nop

L_8006421C:
    // 0x8006421C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064224: jr          $ra
    // 0x80064228: nop

    return;
    // 0x80064228: nop

;}
RECOMP_FUNC void func_8006422C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006422C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064234: jal         0x80061488
    // 0x80064238: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064238: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x8006423C: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064240: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064244: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x80064248: nop

            goto L_800642D8;
    }
    // 0x80064248: nop

    // 0x8006424C: jal         0x80061488
    // 0x80064250: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064250: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064254: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064258: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006425C: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x80064260: nop

            goto L_800642D8;
    }
    // 0x80064260: nop

    // 0x80064264: jal         0x80061488
    // 0x80064268: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064268: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x8006426C: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064270: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064274: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x80064278: nop

            goto L_800642D8;
    }
    // 0x80064278: nop

    // 0x8006427C: jal         0x80061488
    // 0x80064280: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x80064280: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064284: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064288: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006428C: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x80064290: nop

            goto L_800642D8;
    }
    // 0x80064290: nop

    // 0x80064294: jal         0x80061488
    // 0x80064298: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064298: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x8006429C: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800642A0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800642A4: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x800642A8: nop

            goto L_800642D8;
    }
    // 0x800642A8: nop

    // 0x800642AC: jal         0x8005F064
    // 0x800642B0: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x800642B0: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x800642B4: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x800642B8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800642BC: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x800642C0: nop

            goto L_800642D8;
    }
    // 0x800642C0: nop

    // 0x800642C4: jal         0x80061348
    // 0x800642C8: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800642C8: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x800642CC: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800642D0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800642D4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800642D8:
    // 0x800642D8: b           L_800642E8
    // 0x800642DC: nop

        goto L_800642E8;
    // 0x800642DC: nop

    // 0x800642E0: b           L_800642E8
    // 0x800642E4: nop

        goto L_800642E8;
    // 0x800642E4: nop

L_800642E8:
    // 0x800642E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800642EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800642F0: jr          $ra
    // 0x800642F4: nop

    return;
    // 0x800642F4: nop

;}
RECOMP_FUNC void func_800642F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800642F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800642FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064300: jal         0x80061488
    // 0x80064304: addiu       $a0, $zero, 0x624
    ctx->r4 = ADD32(0, 0X624);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064304: addiu       $a0, $zero, 0x624
    ctx->r4 = ADD32(0, 0X624);
    after_0:
    // 0x80064308: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006430C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80064310: b           L_80064320
    // 0x80064314: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80064320;
    // 0x80064314: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064318: b           L_80064320
    // 0x8006431C: nop

        goto L_80064320;
    // 0x8006431C: nop

L_80064320:
    // 0x80064320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064328: jr          $ra
    // 0x8006432C: nop

    return;
    // 0x8006432C: nop

;}
RECOMP_FUNC void func_80064330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064330: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064334: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064338: nop

    // 0x8006433C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064340: nop

    // 0x80064344: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064348: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006434C: jr          $ra
    // 0x80064350: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064350: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064354: jr          $ra
    // 0x80064358: nop

    return;
    // 0x80064358: nop

    // 0x8006435C: jr          $ra
    // 0x80064360: nop

    return;
    // 0x80064360: nop

;}
RECOMP_FUNC void func_80064364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006436C: jal         0x80061488
    // 0x80064370: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064370: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    after_0:
    // 0x80064374: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80064378: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006437C: b           L_8006438C
    // 0x80064380: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006438C;
    // 0x80064380: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064384: b           L_8006438C
    // 0x80064388: nop

        goto L_8006438C;
    // 0x80064388: nop

L_8006438C:
    // 0x8006438C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064394: jr          $ra
    // 0x80064398: nop

    return;
    // 0x80064398: nop

;}
RECOMP_FUNC void func_8006439C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006439C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800643A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800643A4: jal         0x80061488
    // 0x800643A8: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800643A8: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    after_0:
    // 0x800643AC: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x800643B0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800643B4: b           L_800643C4
    // 0x800643B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800643C4;
    // 0x800643B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800643BC: b           L_800643C4
    // 0x800643C0: nop

        goto L_800643C4;
    // 0x800643C0: nop

L_800643C4:
    // 0x800643C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800643C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800643CC: jr          $ra
    // 0x800643D0: nop

    return;
    // 0x800643D0: nop

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
RECOMP_FUNC void func_8006440C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006440C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064414: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064418: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006441C: nop

    // 0x80064420: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064424: nop

    // 0x80064428: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006442C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064430: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064434: beq         $v0, $zero, L_8006444C
    if (ctx->r2 == 0) {
        // 0x80064438: nop

            goto L_8006444C;
    }
    // 0x80064438: nop

    // 0x8006443C: jal         0x8005F064
    // 0x80064440: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064440: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064444: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064448: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006444C:
    // 0x8006444C: b           L_8006445C
    // 0x80064450: nop

        goto L_8006445C;
    // 0x80064450: nop

    // 0x80064454: b           L_8006445C
    // 0x80064458: nop

        goto L_8006445C;
    // 0x80064458: nop

L_8006445C:
    // 0x8006445C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064464: jr          $ra
    // 0x80064468: nop

    return;
    // 0x80064468: nop

;}
RECOMP_FUNC void func_8006446C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006446C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064474: jal         0x80061488
    // 0x80064478: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064478: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x8006447C: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064480: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064484: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x80064488: nop

            goto L_80064518;
    }
    // 0x80064488: nop

    // 0x8006448C: jal         0x80061488
    // 0x80064490: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064490: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064494: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064498: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006449C: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x800644A0: nop

            goto L_80064518;
    }
    // 0x800644A0: nop

    // 0x800644A4: jal         0x80061488
    // 0x800644A8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x800644A8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x800644AC: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800644B0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800644B4: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x800644B8: nop

            goto L_80064518;
    }
    // 0x800644B8: nop

    // 0x800644BC: jal         0x80061488
    // 0x800644C0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x800644C0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x800644C4: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800644C8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800644CC: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x800644D0: nop

            goto L_80064518;
    }
    // 0x800644D0: nop

    // 0x800644D4: jal         0x80061488
    // 0x800644D8: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x800644D8: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x800644DC: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800644E0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800644E4: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x800644E8: nop

            goto L_80064518;
    }
    // 0x800644E8: nop

    // 0x800644EC: jal         0x8005F064
    // 0x800644F0: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x800644F0: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x800644F4: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x800644F8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800644FC: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x80064500: nop

            goto L_80064518;
    }
    // 0x80064500: nop

    // 0x80064504: jal         0x80061348
    // 0x80064508: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064508: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x8006450C: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064510: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064514: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064518:
    // 0x80064518: b           L_80064528
    // 0x8006451C: nop

        goto L_80064528;
    // 0x8006451C: nop

    // 0x80064520: b           L_80064528
    // 0x80064524: nop

        goto L_80064528;
    // 0x80064524: nop

L_80064528:
    // 0x80064528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006452C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064530: jr          $ra
    // 0x80064534: nop

    return;
    // 0x80064534: nop

;}
RECOMP_FUNC void func_80064538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006453C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064540: jal         0x80061488
    // 0x80064544: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064544: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064548: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006454C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064550: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x80064554: nop

            goto L_800645E4;
    }
    // 0x80064554: nop

    // 0x80064558: jal         0x80061488
    // 0x8006455C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x8006455C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064560: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064564: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064568: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x8006456C: nop

            goto L_800645E4;
    }
    // 0x8006456C: nop

    // 0x80064570: jal         0x80061488
    // 0x80064574: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064574: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x80064578: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006457C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064580: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x80064584: nop

            goto L_800645E4;
    }
    // 0x80064584: nop

    // 0x80064588: jal         0x80061488
    // 0x8006458C: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x8006458C: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064590: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064594: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80064598: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x8006459C: nop

            goto L_800645E4;
    }
    // 0x8006459C: nop

    // 0x800645A0: jal         0x80061488
    // 0x800645A4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x800645A4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x800645A8: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800645AC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800645B0: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x800645B4: nop

            goto L_800645E4;
    }
    // 0x800645B4: nop

    // 0x800645B8: jal         0x8005F064
    // 0x800645BC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x800645BC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x800645C0: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x800645C4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800645C8: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x800645CC: nop

            goto L_800645E4;
    }
    // 0x800645CC: nop

    // 0x800645D0: jal         0x80061348
    // 0x800645D4: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800645D4: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x800645D8: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800645DC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800645E0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800645E4:
    // 0x800645E4: b           L_800645F4
    // 0x800645E8: nop

        goto L_800645F4;
    // 0x800645E8: nop

    // 0x800645EC: b           L_800645F4
    // 0x800645F0: nop

        goto L_800645F4;
    // 0x800645F0: nop

L_800645F4:
    // 0x800645F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800645F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800645FC: jr          $ra
    // 0x80064600: nop

    return;
    // 0x80064600: nop

;}
RECOMP_FUNC void func_80064604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064604: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064608: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006460C: nop

    // 0x80064610: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064614: nop

    // 0x80064618: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006461C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064620: jr          $ra
    // 0x80064624: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064624: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064628: jr          $ra
    // 0x8006462C: nop

    return;
    // 0x8006462C: nop

    // 0x80064630: jr          $ra
    // 0x80064634: nop

    return;
    // 0x80064634: nop

;}
RECOMP_FUNC void func_80064638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006463C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064640: jal         0x80061488
    // 0x80064644: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064644: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    after_0:
    // 0x80064648: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006464C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80064650: b           L_80064660
    // 0x80064654: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80064660;
    // 0x80064654: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064658: b           L_80064660
    // 0x8006465C: nop

        goto L_80064660;
    // 0x8006465C: nop

L_80064660:
    // 0x80064660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064668: jr          $ra
    // 0x8006466C: nop

    return;
    // 0x8006466C: nop

;}
RECOMP_FUNC void func_80064670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064678: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006467C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064680: nop

    // 0x80064684: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064688: nop

    // 0x8006468C: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80064690: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064694: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064698: beq         $v0, $zero, L_800646B0
    if (ctx->r2 == 0) {
        // 0x8006469C: nop

            goto L_800646B0;
    }
    // 0x8006469C: nop

    // 0x800646A0: jal         0x8005F064
    // 0x800646A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800646A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x800646A8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800646AC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800646B0:
    // 0x800646B0: b           L_800646C0
    // 0x800646B4: nop

        goto L_800646C0;
    // 0x800646B4: nop

    // 0x800646B8: b           L_800646C0
    // 0x800646BC: nop

        goto L_800646C0;
    // 0x800646BC: nop

L_800646C0:
    // 0x800646C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800646C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800646C8: jr          $ra
    // 0x800646CC: nop

    return;
    // 0x800646CC: nop

;}
RECOMP_FUNC void func_800646D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800646D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800646D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800646D8: jal         0x80061488
    // 0x800646DC: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800646DC: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x800646E0: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800646E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800646E8: beq         $v0, $zero, L_8006477C
    if (ctx->r2 == 0) {
        // 0x800646EC: nop

            goto L_8006477C;
    }
    // 0x800646EC: nop

    // 0x800646F0: jal         0x80061488
    // 0x800646F4: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x800646F4: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x800646F8: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800646FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064700: beq         $v0, $zero, L_8006477C
    if (ctx->r2 == 0) {
        // 0x80064704: nop

            goto L_8006477C;
    }
    // 0x80064704: nop

    // 0x80064708: jal         0x80061488
    // 0x8006470C: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x8006470C: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x80064710: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064714: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064718: beq         $v0, $zero, L_8006477C
    if (ctx->r2 == 0) {
        // 0x8006471C: nop

            goto L_8006477C;
    }
    // 0x8006471C: nop

    // 0x80064720: jal         0x80061488
    // 0x80064724: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x80064724: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064728: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006472C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80064730: beq         $v0, $zero, L_8006477C
    if (ctx->r2 == 0) {
        // 0x80064734: nop

            goto L_8006477C;
    }
    // 0x80064734: nop

    // 0x80064738: jal         0x80061488
    // 0x8006473C: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x8006473C: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x80064740: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064744: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064748: beq         $v0, $zero, L_8006477C
    if (ctx->r2 == 0) {
        // 0x8006474C: nop

            goto L_8006477C;
    }
    // 0x8006474C: nop

    // 0x80064750: jal         0x8005F064
    // 0x80064754: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064754: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064758: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006475C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064760: beq         $v0, $zero, L_8006477C
    if (ctx->r2 == 0) {
        // 0x80064764: nop

            goto L_8006477C;
    }
    // 0x80064764: nop

    // 0x80064768: jal         0x80061348
    // 0x8006476C: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006476C: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064770: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064774: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064778: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006477C:
    // 0x8006477C: b           L_8006478C
    // 0x80064780: nop

        goto L_8006478C;
    // 0x80064780: nop

    // 0x80064784: b           L_8006478C
    // 0x80064788: nop

        goto L_8006478C;
    // 0x80064788: nop

L_8006478C:
    // 0x8006478C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064790: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064794: jr          $ra
    // 0x80064798: nop

    return;
    // 0x80064798: nop

;}
RECOMP_FUNC void func_8006479C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006479C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800647A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800647A4: jal         0x80061488
    // 0x800647A8: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800647A8: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x800647AC: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800647B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800647B4: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x800647B8: nop

            goto L_80064848;
    }
    // 0x800647B8: nop

    // 0x800647BC: jal         0x80061488
    // 0x800647C0: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x800647C0: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x800647C4: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800647C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800647CC: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x800647D0: nop

            goto L_80064848;
    }
    // 0x800647D0: nop

    // 0x800647D4: jal         0x80061488
    // 0x800647D8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x800647D8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x800647DC: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800647E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800647E4: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x800647E8: nop

            goto L_80064848;
    }
    // 0x800647E8: nop

    // 0x800647EC: jal         0x80061488
    // 0x800647F0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x800647F0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x800647F4: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800647F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800647FC: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x80064800: nop

            goto L_80064848;
    }
    // 0x80064800: nop

    // 0x80064804: jal         0x80061488
    // 0x80064808: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064808: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x8006480C: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064810: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064814: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x80064818: nop

            goto L_80064848;
    }
    // 0x80064818: nop

    // 0x8006481C: jal         0x8005F064
    // 0x80064820: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064820: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064824: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064828: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006482C: beq         $v0, $zero, L_80064848
    if (ctx->r2 == 0) {
        // 0x80064830: nop

            goto L_80064848;
    }
    // 0x80064830: nop

    // 0x80064834: jal         0x80061348
    // 0x80064838: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064838: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x8006483C: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064840: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064844: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064848:
    // 0x80064848: b           L_80064858
    // 0x8006484C: nop

        goto L_80064858;
    // 0x8006484C: nop

    // 0x80064850: b           L_80064858
    // 0x80064854: nop

        goto L_80064858;
    // 0x80064854: nop

L_80064858:
    // 0x80064858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006485C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064860: jr          $ra
    // 0x80064864: nop

    return;
    // 0x80064864: nop

;}
RECOMP_FUNC void func_80064868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064868: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006486C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064870: nop

    // 0x80064874: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064878: nop

    // 0x8006487C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064880: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064884: jr          $ra
    // 0x80064888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006488C: jr          $ra
    // 0x80064890: nop

    return;
    // 0x80064890: nop

    // 0x80064894: jr          $ra
    // 0x80064898: nop

    return;
    // 0x80064898: nop

;}
RECOMP_FUNC void func_8006489C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006489C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800648A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800648A4: jal         0x80061488
    // 0x800648A8: addiu       $a0, $zero, 0x632
    ctx->r4 = ADD32(0, 0X632);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800648A8: addiu       $a0, $zero, 0x632
    ctx->r4 = ADD32(0, 0X632);
    after_0:
    // 0x800648AC: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800648B0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800648B4: b           L_800648C4
    // 0x800648B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800648C4;
    // 0x800648B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800648BC: b           L_800648C4
    // 0x800648C0: nop

        goto L_800648C4;
    // 0x800648C0: nop

L_800648C4:
    // 0x800648C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800648C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800648CC: jr          $ra
    // 0x800648D0: nop

    return;
    // 0x800648D0: nop

;}
RECOMP_FUNC void func_800648D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800648D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800648D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800648DC: jal         0x80061488
    // 0x800648E0: addiu       $a0, $zero, 0x632
    ctx->r4 = ADD32(0, 0X632);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800648E0: addiu       $a0, $zero, 0x632
    ctx->r4 = ADD32(0, 0X632);
    after_0:
    // 0x800648E4: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x800648E8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800648EC: b           L_800648FC
    // 0x800648F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800648FC;
    // 0x800648F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800648F4: b           L_800648FC
    // 0x800648F8: nop

        goto L_800648FC;
    // 0x800648F8: nop

L_800648FC:
    // 0x800648FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064904: jr          $ra
    // 0x80064908: nop

    return;
    // 0x80064908: nop

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
RECOMP_FUNC void func_8006493C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006493C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064944: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064948: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006494C: nop

    // 0x80064950: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064954: nop

    // 0x80064958: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006495C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064960: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064964: beq         $v0, $zero, L_8006497C
    if (ctx->r2 == 0) {
        // 0x80064968: nop

            goto L_8006497C;
    }
    // 0x80064968: nop

    // 0x8006496C: jal         0x8005F064
    // 0x80064970: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064970: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064974: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064978: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006497C:
    // 0x8006497C: b           L_8006498C
    // 0x80064980: nop

        goto L_8006498C;
    // 0x80064980: nop

    // 0x80064984: b           L_8006498C
    // 0x80064988: nop

        goto L_8006498C;
    // 0x80064988: nop

L_8006498C:
    // 0x8006498C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064994: jr          $ra
    // 0x80064998: nop

    return;
    // 0x80064998: nop

;}
RECOMP_FUNC void func_8006499C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006499C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800649A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800649A4: jal         0x80061488
    // 0x800649A8: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800649A8: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x800649AC: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800649B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800649B4: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x800649B8: nop

            goto L_80064A48;
    }
    // 0x800649B8: nop

    // 0x800649BC: jal         0x80061488
    // 0x800649C0: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x800649C0: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x800649C4: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800649C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800649CC: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x800649D0: nop

            goto L_80064A48;
    }
    // 0x800649D0: nop

    // 0x800649D4: jal         0x80061488
    // 0x800649D8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x800649D8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x800649DC: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800649E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800649E4: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x800649E8: nop

            goto L_80064A48;
    }
    // 0x800649E8: nop

    // 0x800649EC: jal         0x80061488
    // 0x800649F0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x800649F0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x800649F4: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800649F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800649FC: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x80064A00: nop

            goto L_80064A48;
    }
    // 0x80064A00: nop

    // 0x80064A04: jal         0x80061488
    // 0x80064A08: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064A08: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x80064A0C: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064A10: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064A14: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x80064A18: nop

            goto L_80064A48;
    }
    // 0x80064A18: nop

    // 0x80064A1C: jal         0x8005F064
    // 0x80064A20: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064A20: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064A24: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064A28: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064A2C: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x80064A30: nop

            goto L_80064A48;
    }
    // 0x80064A30: nop

    // 0x80064A34: jal         0x80061348
    // 0x80064A38: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064A38: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064A3C: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064A40: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064A44: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064A48:
    // 0x80064A48: b           L_80064A58
    // 0x80064A4C: nop

        goto L_80064A58;
    // 0x80064A4C: nop

    // 0x80064A50: b           L_80064A58
    // 0x80064A54: nop

        goto L_80064A58;
    // 0x80064A54: nop

L_80064A58:
    // 0x80064A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064A5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064A60: jr          $ra
    // 0x80064A64: nop

    return;
    // 0x80064A64: nop

;}
