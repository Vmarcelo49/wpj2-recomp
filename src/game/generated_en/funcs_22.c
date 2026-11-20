#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006D054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D058: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D05C: nop

    // 0x8006D060: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D064: nop

    // 0x8006D068: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D06C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D070: jr          $ra
    // 0x8006D074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D078: jr          $ra
    // 0x8006D07C: nop

    return;
    // 0x8006D07C: nop

    // 0x8006D080: jr          $ra
    // 0x8006D084: nop

    return;
    // 0x8006D084: nop

;}
RECOMP_FUNC void func_8006D088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D088: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D08C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D090: nop

    // 0x8006D094: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D098: nop

    // 0x8006D09C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D0A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D0A4: jr          $ra
    // 0x8006D0A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D0A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D0AC: jr          $ra
    // 0x8006D0B0: nop

    return;
    // 0x8006D0B0: nop

    // 0x8006D0B4: jr          $ra
    // 0x8006D0B8: nop

    return;
    // 0x8006D0B8: nop

;}
RECOMP_FUNC void func_8006D0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D0C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D0C4: nop

    // 0x8006D0C8: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D0CC: nop

    // 0x8006D0D0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006D0D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D0D8: jr          $ra
    // 0x8006D0DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D0DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D0E0: jr          $ra
    // 0x8006D0E4: nop

    return;
    // 0x8006D0E4: nop

    // 0x8006D0E8: jr          $ra
    // 0x8006D0EC: nop

    return;
    // 0x8006D0EC: nop

;}
RECOMP_FUNC void func_8006D0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D0F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D0F8: nop

    // 0x8006D0FC: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D100: nop

    // 0x8006D104: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D108: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D10C: jr          $ra
    // 0x8006D110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D114: jr          $ra
    // 0x8006D118: nop

    return;
    // 0x8006D118: nop

    // 0x8006D11C: jr          $ra
    // 0x8006D120: nop

    return;
    // 0x8006D120: nop

;}
RECOMP_FUNC void func_8006D124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D124: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D128: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D12C: nop

    // 0x8006D130: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D134: nop

    // 0x8006D138: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D13C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D140: jr          $ra
    // 0x8006D144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D148: jr          $ra
    // 0x8006D14C: nop

    return;
    // 0x8006D14C: nop

    // 0x8006D150: jr          $ra
    // 0x8006D154: nop

    return;
    // 0x8006D154: nop

;}
RECOMP_FUNC void func_8006D158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D158: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D15C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D160: nop

    // 0x8006D164: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x8006D168: nop

    // 0x8006D16C: slti        $t7, $v0, 0x3E8
    ctx->r15 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    // 0x8006D170: jr          $ra
    // 0x8006D174: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D174: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D178: jr          $ra
    // 0x8006D17C: nop

    return;
    // 0x8006D17C: nop

    // 0x8006D180: jr          $ra
    // 0x8006D184: nop

    return;
    // 0x8006D184: nop

;}
RECOMP_FUNC void func_8006D188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D188: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D18C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D190: nop

    // 0x8006D194: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006D198: nop

    // 0x8006D19C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D1A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D1A4: jr          $ra
    // 0x8006D1A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D1A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D1AC: jr          $ra
    // 0x8006D1B0: nop

    return;
    // 0x8006D1B0: nop

    // 0x8006D1B4: jr          $ra
    // 0x8006D1B8: nop

    return;
    // 0x8006D1B8: nop

;}
RECOMP_FUNC void func_8006D1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D1C4: jal         0x8005F064
    // 0x8006D1C8: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D1C8: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x8006D1CC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D1D0: b           L_8006D1E0
    // 0x8006D1D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D1E0;
    // 0x8006D1D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D1D8: b           L_8006D1E0
    // 0x8006D1DC: nop

        goto L_8006D1E0;
    // 0x8006D1DC: nop

L_8006D1E0:
    // 0x8006D1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D1E8: jr          $ra
    // 0x8006D1EC: nop

    return;
    // 0x8006D1EC: nop

;}
RECOMP_FUNC void func_8006D1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D1F8: jal         0x80061348
    // 0x8006D1FC: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D1FC: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x8006D200: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D204: b           L_8006D214
    // 0x8006D208: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D214;
    // 0x8006D208: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D20C: b           L_8006D214
    // 0x8006D210: nop

        goto L_8006D214;
    // 0x8006D210: nop

L_8006D214:
    // 0x8006D214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D21C: jr          $ra
    // 0x8006D220: nop

    return;
    // 0x8006D220: nop

;}
RECOMP_FUNC void func_8006D224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D22C: jal         0x80061348
    // 0x8006D230: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D230: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006D234: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D238: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D23C: beq         $v0, $zero, L_8006D254
    if (ctx->r2 == 0) {
        // 0x8006D240: nop

            goto L_8006D254;
    }
    // 0x8006D240: nop

    // 0x8006D244: jal         0x80061348
    // 0x8006D248: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006D248: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x8006D24C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D250: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006D254:
    // 0x8006D254: b           L_8006D264
    // 0x8006D258: nop

        goto L_8006D264;
    // 0x8006D258: nop

    // 0x8006D25C: b           L_8006D264
    // 0x8006D260: nop

        goto L_8006D264;
    // 0x8006D260: nop

L_8006D264:
    // 0x8006D264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D26C: jr          $ra
    // 0x8006D270: nop

    return;
    // 0x8006D270: nop

;}
RECOMP_FUNC void func_8006D274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D27C: jal         0x80061348
    // 0x8006D280: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D280: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006D284: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D288: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D28C: beq         $v0, $zero, L_8006D2A4
    if (ctx->r2 == 0) {
        // 0x8006D290: nop

            goto L_8006D2A4;
    }
    // 0x8006D290: nop

    // 0x8006D294: jal         0x80061348
    // 0x8006D298: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006D298: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x8006D29C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D2A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006D2A4:
    // 0x8006D2A4: b           L_8006D2B4
    // 0x8006D2A8: nop

        goto L_8006D2B4;
    // 0x8006D2A8: nop

    // 0x8006D2AC: b           L_8006D2B4
    // 0x8006D2B0: nop

        goto L_8006D2B4;
    // 0x8006D2B0: nop

L_8006D2B4:
    // 0x8006D2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D2B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D2BC: jr          $ra
    // 0x8006D2C0: nop

    return;
    // 0x8006D2C0: nop

;}
RECOMP_FUNC void func_8006D2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D2C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D2CC: jal         0x80061348
    // 0x8006D2D0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D2D0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006D2D4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D2D8: b           L_8006D2E8
    // 0x8006D2DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D2E8;
    // 0x8006D2DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D2E0: b           L_8006D2E8
    // 0x8006D2E4: nop

        goto L_8006D2E8;
    // 0x8006D2E4: nop

L_8006D2E8:
    // 0x8006D2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D2EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D2F0: jr          $ra
    // 0x8006D2F4: nop

    return;
    // 0x8006D2F4: nop

;}
RECOMP_FUNC void func_8006D2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D2F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D300: jal         0x80061348
    // 0x8006D304: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D304: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006D308: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D30C: b           L_8006D31C
    // 0x8006D310: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D31C;
    // 0x8006D310: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D314: b           L_8006D31C
    // 0x8006D318: nop

        goto L_8006D31C;
    // 0x8006D318: nop

L_8006D31C:
    // 0x8006D31C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D324: jr          $ra
    // 0x8006D328: nop

    return;
    // 0x8006D328: nop

;}
RECOMP_FUNC void func_8006D32C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D32C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D334: jal         0x80061348
    // 0x8006D338: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D338: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x8006D33C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D340: b           L_8006D350
    // 0x8006D344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D350;
    // 0x8006D344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D348: b           L_8006D350
    // 0x8006D34C: nop

        goto L_8006D350;
    // 0x8006D34C: nop

L_8006D350:
    // 0x8006D350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D358: jr          $ra
    // 0x8006D35C: nop

    return;
    // 0x8006D35C: nop

;}
RECOMP_FUNC void func_8006D360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D360: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D364: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D368: nop

    // 0x8006D36C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D370: nop

    // 0x8006D374: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006D378: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D37C: jr          $ra
    // 0x8006D380: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D380: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D384: jr          $ra
    // 0x8006D388: nop

    return;
    // 0x8006D388: nop

    // 0x8006D38C: jr          $ra
    // 0x8006D390: nop

    return;
    // 0x8006D390: nop

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
RECOMP_FUNC void func_8006D3CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D3CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D3D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D3D4: jal         0x80061488
    // 0x8006D3D8: addiu       $a0, $zero, 0x574
    ctx->r4 = ADD32(0, 0X574);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006D3D8: addiu       $a0, $zero, 0x574
    ctx->r4 = ADD32(0, 0X574);
    after_0:
    // 0x8006D3DC: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006D3E0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006D3E4: b           L_8006D3F4
    // 0x8006D3E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D3F4;
    // 0x8006D3E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D3EC: b           L_8006D3F4
    // 0x8006D3F0: nop

        goto L_8006D3F4;
    // 0x8006D3F0: nop

L_8006D3F4:
    // 0x8006D3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D3F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D3FC: jr          $ra
    // 0x8006D400: nop

    return;
    // 0x8006D400: nop

;}
RECOMP_FUNC void func_8006D404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D404: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D408: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D40C: nop

    // 0x8006D410: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D414: nop

    // 0x8006D418: slti        $t7, $v0, 0x97
    ctx->r15 = SIGNED(ctx->r2) < 0X97 ? 1 : 0;
    // 0x8006D41C: jr          $ra
    // 0x8006D420: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D420: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D424: jr          $ra
    // 0x8006D428: nop

    return;
    // 0x8006D428: nop

    // 0x8006D42C: jr          $ra
    // 0x8006D430: nop

    return;
    // 0x8006D430: nop

;}
RECOMP_FUNC void func_8006D434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D434: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D438: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D43C: nop

    // 0x8006D440: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D444: nop

    // 0x8006D448: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006D44C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D450: jr          $ra
    // 0x8006D454: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D454: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D458: jr          $ra
    // 0x8006D45C: nop

    return;
    // 0x8006D45C: nop

    // 0x8006D460: jr          $ra
    // 0x8006D464: nop

    return;
    // 0x8006D464: nop

;}
RECOMP_FUNC void func_8006D468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D46C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D470: jal         0x8005F064
    // 0x8006D474: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D474: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    after_0:
    // 0x8006D478: b           L_8006D488
    // 0x8006D47C: nop

        goto L_8006D488;
    // 0x8006D47C: nop

    // 0x8006D480: b           L_8006D488
    // 0x8006D484: nop

        goto L_8006D488;
    // 0x8006D484: nop

L_8006D488:
    // 0x8006D488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D48C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D490: jr          $ra
    // 0x8006D494: nop

    return;
    // 0x8006D494: nop

;}
RECOMP_FUNC void func_8006D498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D49C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D4A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D4A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D4A8: nop

    // 0x8006D4AC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D4B0: nop

    // 0x8006D4B4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006D4B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D4BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D4C0: beq         $v0, $zero, L_8006D4F4
    if (ctx->r2 == 0) {
        // 0x8006D4C4: nop

            goto L_8006D4F4;
    }
    // 0x8006D4C4: nop

    // 0x8006D4C8: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x8006D4CC: nop

    // 0x8006D4D0: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006D4D4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006D4D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006D4DC: beq         $v0, $zero, L_8006D4F4
    if (ctx->r2 == 0) {
        // 0x8006D4E0: nop

            goto L_8006D4F4;
    }
    // 0x8006D4E0: nop

    // 0x8006D4E4: jal         0x8005F064
    // 0x8006D4E8: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D4E8: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    after_0:
    // 0x8006D4EC: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D4F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006D4F4:
    // 0x8006D4F4: b           L_8006D504
    // 0x8006D4F8: nop

        goto L_8006D504;
    // 0x8006D4F8: nop

    // 0x8006D4FC: b           L_8006D504
    // 0x8006D500: nop

        goto L_8006D504;
    // 0x8006D500: nop

L_8006D504:
    // 0x8006D504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D50C: jr          $ra
    // 0x8006D510: nop

    return;
    // 0x8006D510: nop

;}
RECOMP_FUNC void func_8006D514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D51C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D520: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D524: nop

    // 0x8006D528: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D52C: nop

    // 0x8006D530: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D534: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D538: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D53C: beq         $v0, $zero, L_8006D560
    if (ctx->r2 == 0) {
        // 0x8006D540: nop

            goto L_8006D560;
    }
    // 0x8006D540: nop

    // 0x8006D544: jal         0x80061348
    // 0x8006D548: addiu       $a0, $zero, 0x71B
    ctx->r4 = ADD32(0, 0X71B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D548: addiu       $a0, $zero, 0x71B
    ctx->r4 = ADD32(0, 0X71B);
    after_0:
    // 0x8006D54C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006D550: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006D554: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006D558: bne         $v0, $zero, L_8006D59C
    if (ctx->r2 != 0) {
        // 0x8006D55C: nop

            goto L_8006D59C;
    }
    // 0x8006D55C: nop

L_8006D560:
    // 0x8006D560: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8006D564: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8006D568: nop

    // 0x8006D56C: lh          $v0, 0x12($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X12);
    // 0x8006D570: nop

    // 0x8006D574: slti        $t0, $v0, 0x12C
    ctx->r8 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D578: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x8006D57C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006D580: beq         $v0, $zero, L_8006D59C
    if (ctx->r2 == 0) {
        // 0x8006D584: nop

            goto L_8006D59C;
    }
    // 0x8006D584: nop

    // 0x8006D588: jal         0x80061348
    // 0x8006D58C: addiu       $a0, $zero, 0x71C
    ctx->r4 = ADD32(0, 0X71C);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006D58C: addiu       $a0, $zero, 0x71C
    ctx->r4 = ADD32(0, 0X71C);
    after_1:
    // 0x8006D590: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006D594: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006D598: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8006D59C:
    // 0x8006D59C: b           L_8006D5AC
    // 0x8006D5A0: nop

        goto L_8006D5AC;
    // 0x8006D5A0: nop

    // 0x8006D5A4: b           L_8006D5AC
    // 0x8006D5A8: nop

        goto L_8006D5AC;
    // 0x8006D5A8: nop

L_8006D5AC:
    // 0x8006D5AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D5B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D5B4: jr          $ra
    // 0x8006D5B8: nop

    return;
    // 0x8006D5B8: nop

;}
RECOMP_FUNC void func_8006D5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D5BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D5C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D5C4: nop

    // 0x8006D5C8: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D5CC: nop

    // 0x8006D5D0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D5D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D5D8: jr          $ra
    // 0x8006D5DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D5DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D5E0: jr          $ra
    // 0x8006D5E4: nop

    return;
    // 0x8006D5E4: nop

    // 0x8006D5E8: jr          $ra
    // 0x8006D5EC: nop

    return;
    // 0x8006D5EC: nop

;}
RECOMP_FUNC void func_8006D5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D5F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D5F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D5F8: nop

    // 0x8006D5FC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D600: nop

    // 0x8006D604: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8006D608: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D60C: jr          $ra
    // 0x8006D610: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D610: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D614: jr          $ra
    // 0x8006D618: nop

    return;
    // 0x8006D618: nop

    // 0x8006D61C: jr          $ra
    // 0x8006D620: nop

    return;
    // 0x8006D620: nop

;}
RECOMP_FUNC void func_8006D624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D62C: jal         0x80061348
    // 0x8006D630: addiu       $a0, $zero, 0x71D
    ctx->r4 = ADD32(0, 0X71D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D630: addiu       $a0, $zero, 0x71D
    ctx->r4 = ADD32(0, 0X71D);
    after_0:
    // 0x8006D634: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D638: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D63C: b           L_8006D64C
    // 0x8006D640: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_8006D64C;
    // 0x8006D640: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D644: b           L_8006D64C
    // 0x8006D648: nop

        goto L_8006D64C;
    // 0x8006D648: nop

L_8006D64C:
    // 0x8006D64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D654: jr          $ra
    // 0x8006D658: nop

    return;
    // 0x8006D658: nop

;}
RECOMP_FUNC void func_8006D65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D65C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D664: jal         0x80061348
    // 0x8006D668: addiu       $a0, $zero, 0x57D
    ctx->r4 = ADD32(0, 0X57D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D668: addiu       $a0, $zero, 0x57D
    ctx->r4 = ADD32(0, 0X57D);
    after_0:
    // 0x8006D66C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006D670: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006D674: b           L_8006D684
    // 0x8006D678: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D684;
    // 0x8006D678: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D67C: b           L_8006D684
    // 0x8006D680: nop

        goto L_8006D684;
    // 0x8006D680: nop

L_8006D684:
    // 0x8006D684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D68C: jr          $ra
    // 0x8006D690: nop

    return;
    // 0x8006D690: nop

;}
RECOMP_FUNC void func_8006D694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D694: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D698: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D69C: nop

    // 0x8006D6A0: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x8006D6A4: nop

    // 0x8006D6A8: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006D6AC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D6B0: jr          $ra
    // 0x8006D6B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D6B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D6B8: jr          $ra
    // 0x8006D6BC: nop

    return;
    // 0x8006D6BC: nop

    // 0x8006D6C0: jr          $ra
    // 0x8006D6C4: nop

    return;
    // 0x8006D6C4: nop

;}
RECOMP_FUNC void func_8006D6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D6C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D6CC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D6D0: nop

    // 0x8006D6D4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006D6D8: nop

    // 0x8006D6DC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D6E0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D6E4: jr          $ra
    // 0x8006D6E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D6E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D6EC: jr          $ra
    // 0x8006D6F0: nop

    return;
    // 0x8006D6F0: nop

    // 0x8006D6F4: jr          $ra
    // 0x8006D6F8: nop

    return;
    // 0x8006D6F8: nop

;}
RECOMP_FUNC void func_8006D6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D6FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D704: jal         0x80061488
    // 0x8006D708: addiu       $a0, $zero, 0x580
    ctx->r4 = ADD32(0, 0X580);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006D708: addiu       $a0, $zero, 0x580
    ctx->r4 = ADD32(0, 0X580);
    after_0:
    // 0x8006D70C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006D710: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006D714: b           L_8006D724
    // 0x8006D718: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D724;
    // 0x8006D718: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D71C: b           L_8006D724
    // 0x8006D720: nop

        goto L_8006D724;
    // 0x8006D720: nop

L_8006D724:
    // 0x8006D724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D72C: jr          $ra
    // 0x8006D730: nop

    return;
    // 0x8006D730: nop

;}
RECOMP_FUNC void func_8006D734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D73C: jal         0x8005F064
    // 0x8006D740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8006D744: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D748: b           L_8006D758
    // 0x8006D74C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D758;
    // 0x8006D74C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D750: b           L_8006D758
    // 0x8006D754: nop

        goto L_8006D758;
    // 0x8006D754: nop

L_8006D758:
    // 0x8006D758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D75C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D760: jr          $ra
    // 0x8006D764: nop

    return;
    // 0x8006D764: nop

;}
RECOMP_FUNC void func_8006D768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D770: jal         0x80061348
    // 0x8006D774: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D774: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x8006D778: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D77C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D780: beq         $v0, $zero, L_8006D7B0
    if (ctx->r2 == 0) {
        // 0x8006D784: nop

            goto L_8006D7B0;
    }
    // 0x8006D784: nop

    // 0x8006D788: jal         0x80061348
    // 0x8006D78C: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006D78C: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_1:
    // 0x8006D790: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D794: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D798: beq         $v0, $zero, L_8006D7B0
    if (ctx->r2 == 0) {
        // 0x8006D79C: nop

            goto L_8006D7B0;
    }
    // 0x8006D79C: nop

    // 0x8006D7A0: jal         0x80061348
    // 0x8006D7A4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006D7A4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_2:
    // 0x8006D7A8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D7AC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006D7B0:
    // 0x8006D7B0: b           L_8006D7C0
    // 0x8006D7B4: nop

        goto L_8006D7C0;
    // 0x8006D7B4: nop

    // 0x8006D7B8: b           L_8006D7C0
    // 0x8006D7BC: nop

        goto L_8006D7C0;
    // 0x8006D7BC: nop

L_8006D7C0:
    // 0x8006D7C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D7C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D7C8: jr          $ra
    // 0x8006D7CC: nop

    return;
    // 0x8006D7CC: nop

;}
RECOMP_FUNC void func_8006D7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D7D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D7D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D7D8: jal         0x80061348
    // 0x8006D7DC: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D7DC: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    after_0:
    // 0x8006D7E0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D7E4: b           L_8006D7F4
    // 0x8006D7E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D7F4;
    // 0x8006D7E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D7EC: b           L_8006D7F4
    // 0x8006D7F0: nop

        goto L_8006D7F4;
    // 0x8006D7F0: nop

L_8006D7F4:
    // 0x8006D7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D7F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D7FC: jr          $ra
    // 0x8006D800: nop

    return;
    // 0x8006D800: nop

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
RECOMP_FUNC void func_8006D880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D888: jal         0x80061488
    // 0x8006D88C: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006D88C: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    after_0:
    // 0x8006D890: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006D894: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006D898: b           L_8006D8A8
    // 0x8006D89C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D8A8;
    // 0x8006D89C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D8A0: b           L_8006D8A8
    // 0x8006D8A4: nop

        goto L_8006D8A8;
    // 0x8006D8A4: nop

L_8006D8A8:
    // 0x8006D8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D8AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D8B0: jr          $ra
    // 0x8006D8B4: nop

    return;
    // 0x8006D8B4: nop

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
RECOMP_FUNC void func_8006D90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D90C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D910: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D914: nop

    // 0x8006D918: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006D91C: nop

    // 0x8006D920: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D924: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D928: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D92C: beq         $v0, $zero, L_8006D948
    if (ctx->r2 == 0) {
        // 0x8006D930: nop

            goto L_8006D948;
    }
    // 0x8006D930: nop

    // 0x8006D934: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x8006D938: nop

    // 0x8006D93C: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D940: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006D944: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006D948:
    // 0x8006D948: jr          $ra
    // 0x8006D94C: nop

    return;
    // 0x8006D94C: nop

    // 0x8006D950: jr          $ra
    // 0x8006D954: nop

    return;
    // 0x8006D954: nop

    // 0x8006D958: jr          $ra
    // 0x8006D95C: nop

    return;
    // 0x8006D95C: nop

;}
RECOMP_FUNC void func_8006D960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D968: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D96C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D970: nop

    // 0x8006D974: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006D978: nop

    // 0x8006D97C: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D980: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D984: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D988: beq         $v0, $zero, L_8006D9BC
    if (ctx->r2 == 0) {
        // 0x8006D98C: nop

            goto L_8006D9BC;
    }
    // 0x8006D98C: nop

    // 0x8006D990: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x8006D994: nop

    // 0x8006D998: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D99C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006D9A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006D9A4: beq         $v0, $zero, L_8006D9BC
    if (ctx->r2 == 0) {
        // 0x8006D9A8: nop

            goto L_8006D9BC;
    }
    // 0x8006D9A8: nop

    // 0x8006D9AC: jal         0x8005F064
    // 0x8006D9B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D9B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8006D9B4: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006D9B8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006D9BC:
    // 0x8006D9BC: b           L_8006D9CC
    // 0x8006D9C0: nop

        goto L_8006D9CC;
    // 0x8006D9C0: nop

    // 0x8006D9C4: b           L_8006D9CC
    // 0x8006D9C8: nop

        goto L_8006D9CC;
    // 0x8006D9C8: nop

L_8006D9CC:
    // 0x8006D9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D9D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D9D4: jr          $ra
    // 0x8006D9D8: nop

    return;
    // 0x8006D9D8: nop

;}
RECOMP_FUNC void func_8006D9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D9DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D9E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D9E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D9E8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D9EC: nop

    // 0x8006D9F0: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006D9F4: nop

    // 0x8006D9F8: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D9FC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006DA00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DA04: beq         $v0, $zero, L_8006DA38
    if (ctx->r2 == 0) {
        // 0x8006DA08: nop

            goto L_8006DA38;
    }
    // 0x8006DA08: nop

    // 0x8006DA0C: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x8006DA10: nop

    // 0x8006DA14: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006DA18: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006DA1C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006DA20: beq         $v0, $zero, L_8006DA38
    if (ctx->r2 == 0) {
        // 0x8006DA24: nop

            goto L_8006DA38;
    }
    // 0x8006DA24: nop

    // 0x8006DA28: jal         0x8005F064
    // 0x8006DA2C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006DA2C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    after_0:
    // 0x8006DA30: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006DA34: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006DA38:
    // 0x8006DA38: b           L_8006DA48
    // 0x8006DA3C: nop

        goto L_8006DA48;
    // 0x8006DA3C: nop

    // 0x8006DA40: b           L_8006DA48
    // 0x8006DA44: nop

        goto L_8006DA48;
    // 0x8006DA44: nop

L_8006DA48:
    // 0x8006DA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DA50: jr          $ra
    // 0x8006DA54: nop

    return;
    // 0x8006DA54: nop

;}
RECOMP_FUNC void func_8006DA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DA5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DA60: jal         0x8005F064
    // 0x8006DA64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006DA64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8006DA68: b           L_8006DA78
    // 0x8006DA6C: nop

        goto L_8006DA78;
    // 0x8006DA6C: nop

    // 0x8006DA70: b           L_8006DA78
    // 0x8006DA74: nop

        goto L_8006DA78;
    // 0x8006DA74: nop

L_8006DA78:
    // 0x8006DA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DA7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DA80: jr          $ra
    // 0x8006DA84: nop

    return;
    // 0x8006DA84: nop

;}
RECOMP_FUNC void func_8006DA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DA90: jal         0x80061348
    // 0x8006DA94: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DA94: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006DA98: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DA9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DAA0: beq         $v0, $zero, L_8006DAD0
    if (ctx->r2 == 0) {
        // 0x8006DAA4: nop

            goto L_8006DAD0;
    }
    // 0x8006DAA4: nop

    // 0x8006DAA8: jal         0x80061348
    // 0x8006DAAC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DAAC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006DAB0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DAB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DAB8: beq         $v0, $zero, L_8006DAD0
    if (ctx->r2 == 0) {
        // 0x8006DABC: nop

            goto L_8006DAD0;
    }
    // 0x8006DABC: nop

    // 0x8006DAC0: jal         0x80061348
    // 0x8006DAC4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006DAC4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_2:
    // 0x8006DAC8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DACC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006DAD0:
    // 0x8006DAD0: b           L_8006DAE0
    // 0x8006DAD4: nop

        goto L_8006DAE0;
    // 0x8006DAD4: nop

    // 0x8006DAD8: b           L_8006DAE0
    // 0x8006DADC: nop

        goto L_8006DAE0;
    // 0x8006DADC: nop

L_8006DAE0:
    // 0x8006DAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DAE8: jr          $ra
    // 0x8006DAEC: nop

    return;
    // 0x8006DAEC: nop

;}
RECOMP_FUNC void func_8006DAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DAF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DAF8: jal         0x80061348
    // 0x8006DAFC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DAFC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006DB00: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DB08: beq         $v0, $zero, L_8006DB38
    if (ctx->r2 == 0) {
        // 0x8006DB0C: nop

            goto L_8006DB38;
    }
    // 0x8006DB0C: nop

    // 0x8006DB10: jal         0x80061348
    // 0x8006DB14: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DB14: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006DB18: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DB20: beq         $v0, $zero, L_8006DB38
    if (ctx->r2 == 0) {
        // 0x8006DB24: nop

            goto L_8006DB38;
    }
    // 0x8006DB24: nop

    // 0x8006DB28: jal         0x80061348
    // 0x8006DB2C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006DB2C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_2:
    // 0x8006DB30: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006DB38:
    // 0x8006DB38: b           L_8006DB48
    // 0x8006DB3C: nop

        goto L_8006DB48;
    // 0x8006DB3C: nop

    // 0x8006DB40: b           L_8006DB48
    // 0x8006DB44: nop

        goto L_8006DB48;
    // 0x8006DB44: nop

L_8006DB48:
    // 0x8006DB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DB4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DB50: jr          $ra
    // 0x8006DB54: nop

    return;
    // 0x8006DB54: nop

;}
RECOMP_FUNC void func_8006DB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DB60: jal         0x80061348
    // 0x8006DB64: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DB64: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006DB68: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DB70: beq         $v0, $zero, L_8006DBA0
    if (ctx->r2 == 0) {
        // 0x8006DB74: nop

            goto L_8006DBA0;
    }
    // 0x8006DB74: nop

    // 0x8006DB78: jal         0x80061348
    // 0x8006DB7C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DB7C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x8006DB80: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DB88: beq         $v0, $zero, L_8006DBA0
    if (ctx->r2 == 0) {
        // 0x8006DB8C: nop

            goto L_8006DBA0;
    }
    // 0x8006DB8C: nop

    // 0x8006DB90: jal         0x80061348
    // 0x8006DB94: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006DB94: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_2:
    // 0x8006DB98: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB9C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006DBA0:
    // 0x8006DBA0: b           L_8006DBB0
    // 0x8006DBA4: nop

        goto L_8006DBB0;
    // 0x8006DBA4: nop

    // 0x8006DBA8: b           L_8006DBB0
    // 0x8006DBAC: nop

        goto L_8006DBB0;
    // 0x8006DBAC: nop

L_8006DBB0:
    // 0x8006DBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DBB8: jr          $ra
    // 0x8006DBBC: nop

    return;
    // 0x8006DBBC: nop

;}
RECOMP_FUNC void func_8006DBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DBC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DBC8: jal         0x80061348
    // 0x8006DBCC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DBCC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006DBD0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DBD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DBD8: beq         $v0, $zero, L_8006DC08
    if (ctx->r2 == 0) {
        // 0x8006DBDC: nop

            goto L_8006DC08;
    }
    // 0x8006DBDC: nop

    // 0x8006DBE0: jal         0x80061348
    // 0x8006DBE4: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DBE4: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x8006DBE8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DBEC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DBF0: beq         $v0, $zero, L_8006DC08
    if (ctx->r2 == 0) {
        // 0x8006DBF4: nop

            goto L_8006DC08;
    }
    // 0x8006DBF4: nop

    // 0x8006DBF8: jal         0x80061348
    // 0x8006DBFC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006DBFC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_2:
    // 0x8006DC00: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DC04: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006DC08:
    // 0x8006DC08: b           L_8006DC18
    // 0x8006DC0C: nop

        goto L_8006DC18;
    // 0x8006DC0C: nop

    // 0x8006DC10: b           L_8006DC18
    // 0x8006DC14: nop

        goto L_8006DC18;
    // 0x8006DC14: nop

L_8006DC18:
    // 0x8006DC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DC1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DC20: jr          $ra
    // 0x8006DC24: nop

    return;
    // 0x8006DC24: nop

;}
RECOMP_FUNC void func_8006DC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DC2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DC30: jal         0x80061348
    // 0x8006DC34: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DC34: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x8006DC38: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DC3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DC40: beq         $v0, $zero, L_8006DC58
    if (ctx->r2 == 0) {
        // 0x8006DC44: nop

            goto L_8006DC58;
    }
    // 0x8006DC44: nop

    // 0x8006DC48: jal         0x80061348
    // 0x8006DC4C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DC4C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_1:
    // 0x8006DC50: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DC54: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DC58:
    // 0x8006DC58: b           L_8006DC68
    // 0x8006DC5C: nop

        goto L_8006DC68;
    // 0x8006DC5C: nop

    // 0x8006DC60: b           L_8006DC68
    // 0x8006DC64: nop

        goto L_8006DC68;
    // 0x8006DC64: nop

L_8006DC68:
    // 0x8006DC68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DC6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DC70: jr          $ra
    // 0x8006DC74: nop

    return;
    // 0x8006DC74: nop

;}
RECOMP_FUNC void func_8006DC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DC7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DC80: jal         0x80061348
    // 0x8006DC84: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DC84: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x8006DC88: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DC8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DC90: beq         $v0, $zero, L_8006DCA8
    if (ctx->r2 == 0) {
        // 0x8006DC94: nop

            goto L_8006DCA8;
    }
    // 0x8006DC94: nop

    // 0x8006DC98: jal         0x80061348
    // 0x8006DC9C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DC9C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_1:
    // 0x8006DCA0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DCA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DCA8:
    // 0x8006DCA8: b           L_8006DCB8
    // 0x8006DCAC: nop

        goto L_8006DCB8;
    // 0x8006DCAC: nop

    // 0x8006DCB0: b           L_8006DCB8
    // 0x8006DCB4: nop

        goto L_8006DCB8;
    // 0x8006DCB4: nop

L_8006DCB8:
    // 0x8006DCB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DCBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DCC0: jr          $ra
    // 0x8006DCC4: nop

    return;
    // 0x8006DCC4: nop

;}
RECOMP_FUNC void func_8006DCC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DCC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DCCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DCD0: jal         0x80061348
    // 0x8006DCD4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DCD4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x8006DCD8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DCDC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DCE0: beq         $v0, $zero, L_8006DCF8
    if (ctx->r2 == 0) {
        // 0x8006DCE4: nop

            goto L_8006DCF8;
    }
    // 0x8006DCE4: nop

    // 0x8006DCE8: jal         0x80061348
    // 0x8006DCEC: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DCEC: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_1:
    // 0x8006DCF0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DCF4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DCF8:
    // 0x8006DCF8: b           L_8006DD08
    // 0x8006DCFC: nop

        goto L_8006DD08;
    // 0x8006DCFC: nop

    // 0x8006DD00: b           L_8006DD08
    // 0x8006DD04: nop

        goto L_8006DD08;
    // 0x8006DD04: nop

L_8006DD08:
    // 0x8006DD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DD0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DD10: jr          $ra
    // 0x8006DD14: nop

    return;
    // 0x8006DD14: nop

;}
RECOMP_FUNC void func_8006DD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DD1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DD20: jal         0x80061348
    // 0x8006DD24: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DD24: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_0:
    // 0x8006DD28: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DD2C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DD30: beq         $v0, $zero, L_8006DD48
    if (ctx->r2 == 0) {
        // 0x8006DD34: nop

            goto L_8006DD48;
    }
    // 0x8006DD34: nop

    // 0x8006DD38: jal         0x80061348
    // 0x8006DD3C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DD3C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_1:
    // 0x8006DD40: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DD44: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DD48:
    // 0x8006DD48: b           L_8006DD58
    // 0x8006DD4C: nop

        goto L_8006DD58;
    // 0x8006DD4C: nop

    // 0x8006DD50: b           L_8006DD58
    // 0x8006DD54: nop

        goto L_8006DD58;
    // 0x8006DD54: nop

L_8006DD58:
    // 0x8006DD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DD60: jr          $ra
    // 0x8006DD64: nop

    return;
    // 0x8006DD64: nop

;}
RECOMP_FUNC void func_8006DD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DD6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DD70: jal         0x80061348
    // 0x8006DD74: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DD74: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_0:
    // 0x8006DD78: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DD7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DD80: beq         $v0, $zero, L_8006DD98
    if (ctx->r2 == 0) {
        // 0x8006DD84: nop

            goto L_8006DD98;
    }
    // 0x8006DD84: nop

    // 0x8006DD88: jal         0x80061348
    // 0x8006DD8C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DD8C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_1:
    // 0x8006DD90: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DD94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DD98:
    // 0x8006DD98: b           L_8006DDA8
    // 0x8006DD9C: nop

        goto L_8006DDA8;
    // 0x8006DD9C: nop

    // 0x8006DDA0: b           L_8006DDA8
    // 0x8006DDA4: nop

        goto L_8006DDA8;
    // 0x8006DDA4: nop

L_8006DDA8:
    // 0x8006DDA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DDAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DDB0: jr          $ra
    // 0x8006DDB4: nop

    return;
    // 0x8006DDB4: nop

;}
RECOMP_FUNC void func_8006DDB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DDB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DDBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DDC0: jal         0x80061348
    // 0x8006DDC4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DDC4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x8006DDC8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DDCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DDD0: beq         $v0, $zero, L_8006DDE8
    if (ctx->r2 == 0) {
        // 0x8006DDD4: nop

            goto L_8006DDE8;
    }
    // 0x8006DDD4: nop

    // 0x8006DDD8: jal         0x80061348
    // 0x8006DDDC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DDDC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_1:
    // 0x8006DDE0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DDE4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DDE8:
    // 0x8006DDE8: b           L_8006DDF8
    // 0x8006DDEC: nop

        goto L_8006DDF8;
    // 0x8006DDEC: nop

    // 0x8006DDF0: b           L_8006DDF8
    // 0x8006DDF4: nop

        goto L_8006DDF8;
    // 0x8006DDF4: nop

L_8006DDF8:
    // 0x8006DDF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DDFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DE00: jr          $ra
    // 0x8006DE04: nop

    return;
    // 0x8006DE04: nop

;}
RECOMP_FUNC void func_8006DE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DE0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DE10: jal         0x80061348
    // 0x8006DE14: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DE14: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006DE18: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DE1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DE20: beq         $v0, $zero, L_8006DE38
    if (ctx->r2 == 0) {
        // 0x8006DE24: nop

            goto L_8006DE38;
    }
    // 0x8006DE24: nop

    // 0x8006DE28: jal         0x80061348
    // 0x8006DE2C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DE2C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006DE30: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DE34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DE38:
    // 0x8006DE38: b           L_8006DE48
    // 0x8006DE3C: nop

        goto L_8006DE48;
    // 0x8006DE3C: nop

    // 0x8006DE40: b           L_8006DE48
    // 0x8006DE44: nop

        goto L_8006DE48;
    // 0x8006DE44: nop

L_8006DE48:
    // 0x8006DE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DE50: jr          $ra
    // 0x8006DE54: nop

    return;
    // 0x8006DE54: nop

;}
