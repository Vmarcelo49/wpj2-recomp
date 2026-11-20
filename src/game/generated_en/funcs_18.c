#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80068780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068780: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068784: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068788: nop

    // 0x8006878C: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068790: nop

    // 0x80068794: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068798: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006879C: jr          $ra
    // 0x800687A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800687A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800687A4: jr          $ra
    // 0x800687A8: nop

    return;
    // 0x800687A8: nop

    // 0x800687AC: jr          $ra
    // 0x800687B0: nop

    return;
    // 0x800687B0: nop

;}
RECOMP_FUNC void func_800687B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687B4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800687B8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800687BC: nop

    // 0x800687C0: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x800687C4: nop

    // 0x800687C8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800687CC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800687D0: jr          $ra
    // 0x800687D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800687D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800687D8: jr          $ra
    // 0x800687DC: nop

    return;
    // 0x800687DC: nop

    // 0x800687E0: jr          $ra
    // 0x800687E4: nop

    return;
    // 0x800687E4: nop

;}
RECOMP_FUNC void func_800687E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800687EC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800687F0: nop

    // 0x800687F4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800687F8: nop

    // 0x800687FC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068800: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068804: jr          $ra
    // 0x80068808: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068808: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006880C: jr          $ra
    // 0x80068810: nop

    return;
    // 0x80068810: nop

    // 0x80068814: jr          $ra
    // 0x80068818: nop

    return;
    // 0x80068818: nop

;}
RECOMP_FUNC void func_8006881C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006881C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068824: jal         0x80061488
    // 0x80068828: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068828: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_0:
    // 0x8006882C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068830: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068834: b           L_80068844
    // 0x80068838: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068844;
    // 0x80068838: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006883C: b           L_80068844
    // 0x80068840: nop

        goto L_80068844;
    // 0x80068840: nop

L_80068844:
    // 0x80068844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006884C: jr          $ra
    // 0x80068850: nop

    return;
    // 0x80068850: nop

;}
RECOMP_FUNC void func_80068854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068854: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068858: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006885C: nop

    // 0x80068860: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80068864: nop

    // 0x80068868: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006886C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068870: jr          $ra
    // 0x80068874: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068874: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068878: jr          $ra
    // 0x8006887C: nop

    return;
    // 0x8006887C: nop

    // 0x80068880: jr          $ra
    // 0x80068884: nop

    return;
    // 0x80068884: nop

;}
RECOMP_FUNC void func_80068888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068888: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006888C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068890: nop

    // 0x80068894: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80068898: nop

    // 0x8006889C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800688A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800688A4: jr          $ra
    // 0x800688A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800688A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800688AC: jr          $ra
    // 0x800688B0: nop

    return;
    // 0x800688B0: nop

    // 0x800688B4: jr          $ra
    // 0x800688B8: nop

    return;
    // 0x800688B8: nop

;}
RECOMP_FUNC void func_800688BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800688C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800688C4: jal         0x80061488
    // 0x800688C8: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800688C8: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    after_0:
    // 0x800688CC: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800688D0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800688D4: b           L_800688E4
    // 0x800688D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800688E4;
    // 0x800688D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800688DC: b           L_800688E4
    // 0x800688E0: nop

        goto L_800688E4;
    // 0x800688E0: nop

L_800688E4:
    // 0x800688E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800688E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800688EC: jr          $ra
    // 0x800688F0: nop

    return;
    // 0x800688F0: nop

;}
RECOMP_FUNC void func_800688F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800688F8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800688FC: nop

    // 0x80068900: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x80068904: nop

    // 0x80068908: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006890C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068910: jr          $ra
    // 0x80068914: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068914: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068918: jr          $ra
    // 0x8006891C: nop

    return;
    // 0x8006891C: nop

    // 0x80068920: jr          $ra
    // 0x80068924: nop

    return;
    // 0x80068924: nop

;}
RECOMP_FUNC void func_80068928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006892C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068930: jal         0x80061488
    // 0x80068934: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068934: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    after_0:
    // 0x80068938: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006893C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068940: b           L_80068950
    // 0x80068944: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068950;
    // 0x80068944: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068948: b           L_80068950
    // 0x8006894C: nop

        goto L_80068950;
    // 0x8006894C: nop

L_80068950:
    // 0x80068950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068958: jr          $ra
    // 0x8006895C: nop

    return;
    // 0x8006895C: nop

;}
RECOMP_FUNC void func_80068960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068960: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068964: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068968: nop

    // 0x8006896C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80068970: nop

    // 0x80068974: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80068978: jr          $ra
    // 0x8006897C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006897C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068980: jr          $ra
    // 0x80068984: nop

    return;
    // 0x80068984: nop

    // 0x80068988: jr          $ra
    // 0x8006898C: nop

    return;
    // 0x8006898C: nop

;}
RECOMP_FUNC void func_80068990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068990: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068994: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068998: nop

    // 0x8006899C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x800689A0: nop

    // 0x800689A4: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x800689A8: jr          $ra
    // 0x800689AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800689AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800689B0: jr          $ra
    // 0x800689B4: nop

    return;
    // 0x800689B4: nop

    // 0x800689B8: jr          $ra
    // 0x800689BC: nop

    return;
    // 0x800689BC: nop

;}
RECOMP_FUNC void func_800689C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800689C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800689C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800689C8: nop

    // 0x800689CC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800689D0: nop

    // 0x800689D4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800689D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800689DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800689E0: bne         $v0, $zero, L_800689FC
    if (ctx->r2 != 0) {
        // 0x800689E4: nop

            goto L_800689FC;
    }
    // 0x800689E4: nop

    // 0x800689E8: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x800689EC: nop

    // 0x800689F0: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x800689F4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800689F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800689FC:
    // 0x800689FC: jr          $ra
    // 0x80068A00: nop

    return;
    // 0x80068A00: nop

    // 0x80068A04: jr          $ra
    // 0x80068A08: nop

    return;
    // 0x80068A08: nop

    // 0x80068A0C: jr          $ra
    // 0x80068A10: nop

    return;
    // 0x80068A10: nop

;}
RECOMP_FUNC void func_80068A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068A1C: jal         0x80061488
    // 0x80068A20: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068A20: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x80068A24: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068A28: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068A2C: b           L_80068A3C
    // 0x80068A30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068A3C;
    // 0x80068A30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068A34: b           L_80068A3C
    // 0x80068A38: nop

        goto L_80068A3C;
    // 0x80068A38: nop

L_80068A3C:
    // 0x80068A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068A44: jr          $ra
    // 0x80068A48: nop

    return;
    // 0x80068A48: nop

;}
RECOMP_FUNC void func_80068A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068A50: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068A54: nop

    // 0x80068A58: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80068A5C: nop

    // 0x80068A60: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80068A64: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068A68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068A6C: bne         $v0, $zero, L_80068A88
    if (ctx->r2 != 0) {
        // 0x80068A70: nop

            goto L_80068A88;
    }
    // 0x80068A70: nop

    // 0x80068A74: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80068A78: nop

    // 0x80068A7C: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80068A80: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80068A84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80068A88:
    // 0x80068A88: jr          $ra
    // 0x80068A8C: nop

    return;
    // 0x80068A8C: nop

    // 0x80068A90: jr          $ra
    // 0x80068A94: nop

    return;
    // 0x80068A94: nop

    // 0x80068A98: jr          $ra
    // 0x80068A9C: nop

    return;
    // 0x80068A9C: nop

;}
RECOMP_FUNC void func_80068AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068AA8: jal         0x80061488
    // 0x80068AAC: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068AAC: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_0:
    // 0x80068AB0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068AB4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068AB8: b           L_80068AC8
    // 0x80068ABC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068AC8;
    // 0x80068ABC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068AC0: b           L_80068AC8
    // 0x80068AC4: nop

        goto L_80068AC8;
    // 0x80068AC4: nop

L_80068AC8:
    // 0x80068AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068AD0: jr          $ra
    // 0x80068AD4: nop

    return;
    // 0x80068AD4: nop

;}
RECOMP_FUNC void func_80068AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068ADC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068AE0: nop

    // 0x80068AE4: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068AE8: nop

    // 0x80068AEC: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80068AF0: jr          $ra
    // 0x80068AF4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068AF4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068AF8: jr          $ra
    // 0x80068AFC: nop

    return;
    // 0x80068AFC: nop

    // 0x80068B00: jr          $ra
    // 0x80068B04: nop

    return;
    // 0x80068B04: nop

;}
RECOMP_FUNC void func_80068B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B08: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068B0C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068B10: nop

    // 0x80068B14: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068B18: nop

    // 0x80068B1C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068B20: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068B24: jr          $ra
    // 0x80068B28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068B28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068B2C: jr          $ra
    // 0x80068B30: nop

    return;
    // 0x80068B30: nop

    // 0x80068B34: jr          $ra
    // 0x80068B38: nop

    return;
    // 0x80068B38: nop

;}
RECOMP_FUNC void func_80068B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068B40: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068B44: nop

    // 0x80068B48: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068B4C: nop

    // 0x80068B50: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068B54: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068B58: jr          $ra
    // 0x80068B5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068B5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068B60: jr          $ra
    // 0x80068B64: nop

    return;
    // 0x80068B64: nop

    // 0x80068B68: jr          $ra
    // 0x80068B6C: nop

    return;
    // 0x80068B6C: nop

;}
RECOMP_FUNC void func_80068B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068B78: jal         0x80061348
    // 0x80068B7C: addiu       $a0, $zero, 0x707
    ctx->r4 = ADD32(0, 0X707);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80068B7C: addiu       $a0, $zero, 0x707
    ctx->r4 = ADD32(0, 0X707);
    after_0:
    // 0x80068B80: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80068B84: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80068B88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068B8C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80068B90: beq         $v0, $zero, L_80068BB0
    if (ctx->r2 == 0) {
        // 0x80068B94: nop

            goto L_80068BB0;
    }
    // 0x80068B94: nop

    // 0x80068B98: jal         0x80061348
    // 0x80068B9C: addiu       $a0, $zero, 0x70B
    ctx->r4 = ADD32(0, 0X70B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80068B9C: addiu       $a0, $zero, 0x70B
    ctx->r4 = ADD32(0, 0X70B);
    after_1:
    // 0x80068BA0: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x80068BA4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80068BA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068BAC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80068BB0:
    // 0x80068BB0: b           L_80068BC0
    // 0x80068BB4: nop

        goto L_80068BC0;
    // 0x80068BB4: nop

    // 0x80068BB8: b           L_80068BC0
    // 0x80068BBC: nop

        goto L_80068BC0;
    // 0x80068BBC: nop

L_80068BC0:
    // 0x80068BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068BC8: jr          $ra
    // 0x80068BCC: nop

    return;
    // 0x80068BCC: nop

;}
RECOMP_FUNC void func_80068BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068BD0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068BD4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068BD8: nop

    // 0x80068BDC: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068BE0: nop

    // 0x80068BE4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068BE8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068BEC: jr          $ra
    // 0x80068BF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068BF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068BF4: jr          $ra
    // 0x80068BF8: nop

    return;
    // 0x80068BF8: nop

    // 0x80068BFC: jr          $ra
    // 0x80068C00: nop

    return;
    // 0x80068C00: nop

;}
RECOMP_FUNC void func_80068C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C04: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068C08: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068C0C: nop

    // 0x80068C10: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068C14: nop

    // 0x80068C18: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068C1C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068C20: jr          $ra
    // 0x80068C24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068C24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068C28: jr          $ra
    // 0x80068C2C: nop

    return;
    // 0x80068C2C: nop

    // 0x80068C30: jr          $ra
    // 0x80068C34: nop

    return;
    // 0x80068C34: nop

;}
RECOMP_FUNC void func_80068C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068C40: jal         0x80061488
    // 0x80068C44: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068C44: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    after_0:
    // 0x80068C48: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068C4C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068C50: b           L_80068C60
    // 0x80068C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068C60;
    // 0x80068C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068C58: b           L_80068C60
    // 0x80068C5C: nop

        goto L_80068C60;
    // 0x80068C5C: nop

L_80068C60:
    // 0x80068C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068C68: jr          $ra
    // 0x80068C6C: nop

    return;
    // 0x80068C6C: nop

;}
RECOMP_FUNC void func_80068C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068C78: jal         0x80061488
    // 0x80068C7C: addiu       $a0, $zero, 0x367
    ctx->r4 = ADD32(0, 0X367);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068C7C: addiu       $a0, $zero, 0x367
    ctx->r4 = ADD32(0, 0X367);
    after_0:
    // 0x80068C80: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068C84: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068C88: b           L_80068C98
    // 0x80068C8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068C98;
    // 0x80068C8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068C90: b           L_80068C98
    // 0x80068C94: nop

        goto L_80068C98;
    // 0x80068C94: nop

L_80068C98:
    // 0x80068C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068CA0: jr          $ra
    // 0x80068CA4: nop

    return;
    // 0x80068CA4: nop

;}
RECOMP_FUNC void func_80068CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068CA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068CAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068CB0: nop

    // 0x80068CB4: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x80068CB8: nop

    // 0x80068CBC: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80068CC0: jr          $ra
    // 0x80068CC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068CC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068CC8: jr          $ra
    // 0x80068CCC: nop

    return;
    // 0x80068CCC: nop

    // 0x80068CD0: jr          $ra
    // 0x80068CD4: nop

    return;
    // 0x80068CD4: nop

;}
RECOMP_FUNC void func_80068CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068CE0: jal         0x80061488
    // 0x80068CE4: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068CE4: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    after_0:
    // 0x80068CE8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068CEC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068CF0: b           L_80068D00
    // 0x80068CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068D00;
    // 0x80068CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068CF8: b           L_80068D00
    // 0x80068CFC: nop

        goto L_80068D00;
    // 0x80068CFC: nop

L_80068D00:
    // 0x80068D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068D08: jr          $ra
    // 0x80068D0C: nop

    return;
    // 0x80068D0C: nop

;}
RECOMP_FUNC void func_80068D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068D14: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068D18: nop

    // 0x80068D1C: lh          $v0, 0x26($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X26);
    // 0x80068D20: nop

    // 0x80068D24: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80068D28: jr          $ra
    // 0x80068D2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068D2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068D30: jr          $ra
    // 0x80068D34: nop

    return;
    // 0x80068D34: nop

    // 0x80068D38: jr          $ra
    // 0x80068D3C: nop

    return;
    // 0x80068D3C: nop

;}
RECOMP_FUNC void func_80068D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068D48: jal         0x80061488
    // 0x80068D4C: addiu       $a0, $zero, 0xED
    ctx->r4 = ADD32(0, 0XED);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068D4C: addiu       $a0, $zero, 0xED
    ctx->r4 = ADD32(0, 0XED);
    after_0:
    // 0x80068D50: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068D54: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068D58: b           L_80068D68
    // 0x80068D5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068D68;
    // 0x80068D5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068D60: b           L_80068D68
    // 0x80068D64: nop

        goto L_80068D68;
    // 0x80068D64: nop

L_80068D68:
    // 0x80068D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068D70: jr          $ra
    // 0x80068D74: nop

    return;
    // 0x80068D74: nop

;}
RECOMP_FUNC void func_80068D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D78: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068D7C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068D80: nop

    // 0x80068D84: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80068D88: nop

    // 0x80068D8C: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80068D90: jr          $ra
    // 0x80068D94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068D94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068D98: jr          $ra
    // 0x80068D9C: nop

    return;
    // 0x80068D9C: nop

    // 0x80068DA0: jr          $ra
    // 0x80068DA4: nop

    return;
    // 0x80068DA4: nop

;}
RECOMP_FUNC void func_80068DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068DA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068DAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068DB0: nop

    // 0x80068DB4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068DB8: nop

    // 0x80068DBC: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80068DC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068DC4: jr          $ra
    // 0x80068DC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068DC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068DCC: jr          $ra
    // 0x80068DD0: nop

    return;
    // 0x80068DD0: nop

    // 0x80068DD4: jr          $ra
    // 0x80068DD8: nop

    return;
    // 0x80068DD8: nop

;}
RECOMP_FUNC void func_80068DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068DDC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068DE0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068DE4: nop

    // 0x80068DE8: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068DEC: nop

    // 0x80068DF0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068DF4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068DF8: jr          $ra
    // 0x80068DFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068DFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068E00: jr          $ra
    // 0x80068E04: nop

    return;
    // 0x80068E04: nop

    // 0x80068E08: jr          $ra
    // 0x80068E0C: nop

    return;
    // 0x80068E0C: nop

;}
RECOMP_FUNC void func_80068E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068E14: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068E18: nop

    // 0x80068E1C: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80068E20: nop

    // 0x80068E24: slti        $t7, $v0, 0x3E7
    ctx->r15 = SIGNED(ctx->r2) < 0X3E7 ? 1 : 0;
    // 0x80068E28: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068E2C: jr          $ra
    // 0x80068E30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068E30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068E34: jr          $ra
    // 0x80068E38: nop

    return;
    // 0x80068E38: nop

    // 0x80068E3C: jr          $ra
    // 0x80068E40: nop

    return;
    // 0x80068E40: nop

;}
RECOMP_FUNC void func_80068E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068E4C: jal         0x80061488
    // 0x80068E50: addiu       $a0, $zero, 0xF6
    ctx->r4 = ADD32(0, 0XF6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068E50: addiu       $a0, $zero, 0xF6
    ctx->r4 = ADD32(0, 0XF6);
    after_0:
    // 0x80068E54: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068E58: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068E5C: b           L_80068E6C
    // 0x80068E60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068E6C;
    // 0x80068E60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068E64: b           L_80068E6C
    // 0x80068E68: nop

        goto L_80068E6C;
    // 0x80068E68: nop

L_80068E6C:
    // 0x80068E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068E74: jr          $ra
    // 0x80068E78: nop

    return;
    // 0x80068E78: nop

;}
RECOMP_FUNC void func_80068E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068E84: jal         0x8005F064
    // 0x80068E88: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80068E88: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    after_0:
    // 0x80068E8C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80068E90: b           L_80068EA0
    // 0x80068E94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068EA0;
    // 0x80068E94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068E98: b           L_80068EA0
    // 0x80068E9C: nop

        goto L_80068EA0;
    // 0x80068E9C: nop

L_80068EA0:
    // 0x80068EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068EA8: jr          $ra
    // 0x80068EAC: nop

    return;
    // 0x80068EAC: nop

;}
RECOMP_FUNC void func_80068EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068EB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068EB4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068EB8: nop

    // 0x80068EBC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068EC0: nop

    // 0x80068EC4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068EC8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068ECC: jr          $ra
    // 0x80068ED0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068ED0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068ED4: jr          $ra
    // 0x80068ED8: nop

    return;
    // 0x80068ED8: nop

    // 0x80068EDC: jr          $ra
    // 0x80068EE0: nop

    return;
    // 0x80068EE0: nop

;}
RECOMP_FUNC void func_80068EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068EE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068EE8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068EEC: nop

    // 0x80068EF0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068EF4: nop

    // 0x80068EF8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068EFC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068F00: jr          $ra
    // 0x80068F04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068F04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068F08: jr          $ra
    // 0x80068F0C: nop

    return;
    // 0x80068F0C: nop

    // 0x80068F10: jr          $ra
    // 0x80068F14: nop

    return;
    // 0x80068F14: nop

;}
RECOMP_FUNC void func_80068F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068F1C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068F20: nop

    // 0x80068F24: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068F28: nop

    // 0x80068F2C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068F30: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068F34: jr          $ra
    // 0x80068F38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068F38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068F3C: jr          $ra
    // 0x80068F40: nop

    return;
    // 0x80068F40: nop

    // 0x80068F44: jr          $ra
    // 0x80068F48: nop

    return;
    // 0x80068F48: nop

;}
RECOMP_FUNC void func_80068F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068F50: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068F54: nop

    // 0x80068F58: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80068F5C: nop

    // 0x80068F60: slti        $t7, $v0, 0x385
    ctx->r15 = SIGNED(ctx->r2) < 0X385 ? 1 : 0;
    // 0x80068F64: jr          $ra
    // 0x80068F68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068F68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068F6C: jr          $ra
    // 0x80068F70: nop

    return;
    // 0x80068F70: nop

    // 0x80068F74: jr          $ra
    // 0x80068F78: nop

    return;
    // 0x80068F78: nop

;}
RECOMP_FUNC void func_80068F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068F80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068F84: nop

    // 0x80068F88: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80068F8C: nop

    // 0x80068F90: slti        $t7, $v0, 0x385
    ctx->r15 = SIGNED(ctx->r2) < 0X385 ? 1 : 0;
    // 0x80068F94: jr          $ra
    // 0x80068F98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068F98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068F9C: jr          $ra
    // 0x80068FA0: nop

    return;
    // 0x80068FA0: nop

    // 0x80068FA4: jr          $ra
    // 0x80068FA8: nop

    return;
    // 0x80068FA8: nop

;}
RECOMP_FUNC void func_80068FAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068FB4: jal         0x80061488
    // 0x80068FB8: addiu       $a0, $zero, 0x390
    ctx->r4 = ADD32(0, 0X390);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068FB8: addiu       $a0, $zero, 0x390
    ctx->r4 = ADD32(0, 0X390);
    after_0:
    // 0x80068FBC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068FC0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068FC4: b           L_80068FD4
    // 0x80068FC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068FD4;
    // 0x80068FC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068FCC: b           L_80068FD4
    // 0x80068FD0: nop

        goto L_80068FD4;
    // 0x80068FD0: nop

L_80068FD4:
    // 0x80068FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068FDC: jr          $ra
    // 0x80068FE0: nop

    return;
    // 0x80068FE0: nop

;}
RECOMP_FUNC void func_80068FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068FEC: jal         0x80061348
    // 0x80068FF0: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80068FF0: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    after_0:
    // 0x80068FF4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80068FF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068FFC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069000: beq         $v0, $zero, L_8006901C
    if (ctx->r2 == 0) {
        // 0x80069004: nop

            goto L_8006901C;
    }
    // 0x80069004: nop

    // 0x80069008: jal         0x80061348
    // 0x8006900C: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006900C: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    after_1:
    // 0x80069010: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069014: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069018: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006901C:
    // 0x8006901C: b           L_8006902C
    // 0x80069020: nop

        goto L_8006902C;
    // 0x80069020: nop

    // 0x80069024: b           L_8006902C
    // 0x80069028: nop

        goto L_8006902C;
    // 0x80069028: nop

L_8006902C:
    // 0x8006902C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069034: jr          $ra
    // 0x80069038: nop

    return;
    // 0x80069038: nop

;}
RECOMP_FUNC void func_8006903C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006903C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069044: jal         0x80061348
    // 0x80069048: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069048: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    after_0:
    // 0x8006904C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069050: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069054: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069058: beq         $v0, $zero, L_80069074
    if (ctx->r2 == 0) {
        // 0x8006905C: nop

            goto L_80069074;
    }
    // 0x8006905C: nop

    // 0x80069060: jal         0x80061348
    // 0x80069064: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069064: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    after_1:
    // 0x80069068: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006906C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069070: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80069074:
    // 0x80069074: b           L_80069084
    // 0x80069078: nop

        goto L_80069084;
    // 0x80069078: nop

    // 0x8006907C: b           L_80069084
    // 0x80069080: nop

        goto L_80069084;
    // 0x80069080: nop

L_80069084:
    // 0x80069084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006908C: jr          $ra
    // 0x80069090: nop

    return;
    // 0x80069090: nop

;}
RECOMP_FUNC void func_80069094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006909C: jal         0x80061348
    // 0x800690A0: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800690A0: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x800690A4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800690A8: b           L_800690B8
    // 0x800690AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800690B8;
    // 0x800690AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800690B0: b           L_800690B8
    // 0x800690B4: nop

        goto L_800690B8;
    // 0x800690B4: nop

L_800690B8:
    // 0x800690B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800690BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800690C0: jr          $ra
    // 0x800690C4: nop

    return;
    // 0x800690C4: nop

;}
RECOMP_FUNC void func_800690C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800690C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800690CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800690D0: jal         0x80061348
    // 0x800690D4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800690D4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x800690D8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800690DC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800690E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800690E4: beq         $v0, $zero, L_80069124
    if (ctx->r2 == 0) {
        // 0x800690E8: nop

            goto L_80069124;
    }
    // 0x800690E8: nop

    // 0x800690EC: jal         0x80061348
    // 0x800690F0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800690F0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x800690F4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800690F8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800690FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069100: beq         $v0, $zero, L_80069124
    if (ctx->r2 == 0) {
        // 0x80069104: nop

            goto L_80069124;
    }
    // 0x80069104: nop

    // 0x80069108: jal         0x80061348
    // 0x8006910C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006910C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x80069110: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069114: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069118: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006911C: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x80069120: nop

            goto L_80069368;
    }
    // 0x80069120: nop

L_80069124:
    // 0x80069124: jal         0x80061348
    // 0x80069128: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80069128: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006912C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069130: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069134: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069138: beq         $v0, $zero, L_80069178
    if (ctx->r2 == 0) {
        // 0x8006913C: nop

            goto L_80069178;
    }
    // 0x8006913C: nop

    // 0x80069140: jal         0x80061348
    // 0x80069144: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x80069144: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x80069148: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006914C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069150: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069154: beq         $v0, $zero, L_80069178
    if (ctx->r2 == 0) {
        // 0x80069158: nop

            goto L_80069178;
    }
    // 0x80069158: nop

    // 0x8006915C: jal         0x80061348
    // 0x80069160: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x80069160: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x80069164: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069168: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006916C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069170: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x80069174: nop

            goto L_80069368;
    }
    // 0x80069174: nop

L_80069178:
    // 0x80069178: jal         0x80061348
    // 0x8006917C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006917C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x80069180: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069184: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069188: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006918C: beq         $v0, $zero, L_800691CC
    if (ctx->r2 == 0) {
        // 0x80069190: nop

            goto L_800691CC;
    }
    // 0x80069190: nop

    // 0x80069194: jal         0x80061348
    // 0x80069198: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x80069198: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006919C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x800691A0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800691A4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800691A8: beq         $v0, $zero, L_800691CC
    if (ctx->r2 == 0) {
        // 0x800691AC: nop

            goto L_800691CC;
    }
    // 0x800691AC: nop

    // 0x800691B0: jal         0x80061348
    // 0x800691B4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x800691B4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x800691B8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x800691BC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x800691C0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800691C4: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x800691C8: nop

            goto L_80069368;
    }
    // 0x800691C8: nop

L_800691CC:
    // 0x800691CC: jal         0x80061348
    // 0x800691D0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x800691D0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x800691D4: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x800691D8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x800691DC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800691E0: beq         $v0, $zero, L_80069220
    if (ctx->r2 == 0) {
        // 0x800691E4: nop

            goto L_80069220;
    }
    // 0x800691E4: nop

    // 0x800691E8: jal         0x80061348
    // 0x800691EC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x800691EC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x800691F0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800691F4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800691F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800691FC: beq         $v0, $zero, L_80069220
    if (ctx->r2 == 0) {
        // 0x80069200: nop

            goto L_80069220;
    }
    // 0x80069200: nop

    // 0x80069204: jal         0x80061348
    // 0x80069208: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x80069208: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006920C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069210: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069218: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x8006921C: nop

            goto L_80069368;
    }
    // 0x8006921C: nop

L_80069220:
    // 0x80069220: jal         0x80061348
    // 0x80069224: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x80069224: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x80069228: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006922C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069230: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069234: beq         $v0, $zero, L_80069274
    if (ctx->r2 == 0) {
        // 0x80069238: nop

            goto L_80069274;
    }
    // 0x80069238: nop

    // 0x8006923C: jal         0x80061348
    // 0x80069240: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x80069240: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x80069244: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069248: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006924C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069250: beq         $v0, $zero, L_80069274
    if (ctx->r2 == 0) {
        // 0x80069254: nop

            goto L_80069274;
    }
    // 0x80069254: nop

    // 0x80069258: jal         0x80061348
    // 0x8006925C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006925C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x80069260: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80069264: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069268: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006926C: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x80069270: nop

            goto L_80069368;
    }
    // 0x80069270: nop

L_80069274:
    // 0x80069274: jal         0x80061348
    // 0x80069278: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x80069278: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006927C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069280: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069284: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069288: beq         $v0, $zero, L_800692C8
    if (ctx->r2 == 0) {
        // 0x8006928C: nop

            goto L_800692C8;
    }
    // 0x8006928C: nop

    // 0x80069290: jal         0x80061348
    // 0x80069294: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069294: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069298: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006929C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x800692A0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800692A4: beq         $v0, $zero, L_800692C8
    if (ctx->r2 == 0) {
        // 0x800692A8: nop

            goto L_800692C8;
    }
    // 0x800692A8: nop

    // 0x800692AC: jal         0x80061348
    // 0x800692B0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x800692B0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x800692B4: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x800692B8: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800692BC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800692C0: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x800692C4: nop

            goto L_80069368;
    }
    // 0x800692C4: nop

L_800692C8:
    // 0x800692C8: jal         0x80061348
    // 0x800692CC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x800692CC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x800692D0: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x800692D4: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x800692D8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800692DC: beq         $v0, $zero, L_8006931C
    if (ctx->r2 == 0) {
        // 0x800692E0: nop

            goto L_8006931C;
    }
    // 0x800692E0: nop

    // 0x800692E4: jal         0x80061348
    // 0x800692E8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x800692E8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x800692EC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x800692F0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x800692F4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800692F8: beq         $v0, $zero, L_8006931C
    if (ctx->r2 == 0) {
        // 0x800692FC: nop

            goto L_8006931C;
    }
    // 0x800692FC: nop

    // 0x80069300: jal         0x80061348
    // 0x80069304: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x80069304: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x80069308: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006930C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069310: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069314: bne         $v0, $zero, L_80069368
    if (ctx->r2 != 0) {
        // 0x80069318: nop

            goto L_80069368;
    }
    // 0x80069318: nop

L_8006931C:
    // 0x8006931C: jal         0x80061348
    // 0x80069320: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x80069320: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x80069324: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069328: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006932C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069330: beq         $v0, $zero, L_80069368
    if (ctx->r2 == 0) {
        // 0x80069334: nop

            goto L_80069368;
    }
    // 0x80069334: nop

    // 0x80069338: jal         0x80061348
    // 0x8006933C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006933C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x80069340: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069344: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069348: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006934C: beq         $v0, $zero, L_80069368
    if (ctx->r2 == 0) {
        // 0x80069350: nop

            goto L_80069368;
    }
    // 0x80069350: nop

    // 0x80069354: jal         0x80061348
    // 0x80069358: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x80069358: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006935C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069360: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069364: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80069368:
    // 0x80069368: b           L_80069378
    // 0x8006936C: nop

        goto L_80069378;
    // 0x8006936C: nop

    // 0x80069370: b           L_80069378
    // 0x80069374: nop

        goto L_80069378;
    // 0x80069374: nop

L_80069378:
    // 0x80069378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006937C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069380: jr          $ra
    // 0x80069384: nop

    return;
    // 0x80069384: nop

;}
RECOMP_FUNC void func_80069388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006938C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069390: jal         0x80061348
    // 0x80069394: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069394: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x80069398: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006939C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800693A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800693A4: beq         $v0, $zero, L_800693E4
    if (ctx->r2 == 0) {
        // 0x800693A8: nop

            goto L_800693E4;
    }
    // 0x800693A8: nop

    // 0x800693AC: jal         0x80061348
    // 0x800693B0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800693B0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x800693B4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800693B8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800693BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800693C0: beq         $v0, $zero, L_800693E4
    if (ctx->r2 == 0) {
        // 0x800693C4: nop

            goto L_800693E4;
    }
    // 0x800693C4: nop

    // 0x800693C8: jal         0x80061348
    // 0x800693CC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800693CC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x800693D0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800693D4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800693D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800693DC: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x800693E0: nop

            goto L_80069628;
    }
    // 0x800693E0: nop

L_800693E4:
    // 0x800693E4: jal         0x80061348
    // 0x800693E8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800693E8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x800693EC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800693F0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800693F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800693F8: beq         $v0, $zero, L_80069438
    if (ctx->r2 == 0) {
        // 0x800693FC: nop

            goto L_80069438;
    }
    // 0x800693FC: nop

    // 0x80069400: jal         0x80061348
    // 0x80069404: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x80069404: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x80069408: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006940C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069410: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069414: beq         $v0, $zero, L_80069438
    if (ctx->r2 == 0) {
        // 0x80069418: nop

            goto L_80069438;
    }
    // 0x80069418: nop

    // 0x8006941C: jal         0x80061348
    // 0x80069420: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x80069420: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x80069424: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069428: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006942C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069430: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x80069434: nop

            goto L_80069628;
    }
    // 0x80069434: nop

L_80069438:
    // 0x80069438: jal         0x80061348
    // 0x8006943C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006943C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x80069440: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069444: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069448: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006944C: beq         $v0, $zero, L_8006948C
    if (ctx->r2 == 0) {
        // 0x80069450: nop

            goto L_8006948C;
    }
    // 0x80069450: nop

    // 0x80069454: jal         0x80061348
    // 0x80069458: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x80069458: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006945C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069460: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80069464: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069468: beq         $v0, $zero, L_8006948C
    if (ctx->r2 == 0) {
        // 0x8006946C: nop

            goto L_8006948C;
    }
    // 0x8006946C: nop

    // 0x80069470: jal         0x80061348
    // 0x80069474: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x80069474: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x80069478: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006947C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069480: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069484: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x80069488: nop

            goto L_80069628;
    }
    // 0x80069488: nop

L_8006948C:
    // 0x8006948C: jal         0x80061348
    // 0x80069490: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x80069490: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x80069494: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069498: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006949C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800694A0: beq         $v0, $zero, L_800694E0
    if (ctx->r2 == 0) {
        // 0x800694A4: nop

            goto L_800694E0;
    }
    // 0x800694A4: nop

    // 0x800694A8: jal         0x80061348
    // 0x800694AC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x800694AC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x800694B0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800694B4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800694B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800694BC: beq         $v0, $zero, L_800694E0
    if (ctx->r2 == 0) {
        // 0x800694C0: nop

            goto L_800694E0;
    }
    // 0x800694C0: nop

    // 0x800694C4: jal         0x80061348
    // 0x800694C8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x800694C8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x800694CC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800694D0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800694D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800694D8: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x800694DC: nop

            goto L_80069628;
    }
    // 0x800694DC: nop

L_800694E0:
    // 0x800694E0: jal         0x80061348
    // 0x800694E4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x800694E4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x800694E8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800694EC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800694F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800694F4: beq         $v0, $zero, L_80069534
    if (ctx->r2 == 0) {
        // 0x800694F8: nop

            goto L_80069534;
    }
    // 0x800694F8: nop

    // 0x800694FC: jal         0x80061348
    // 0x80069500: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x80069500: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x80069504: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069508: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006950C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069510: beq         $v0, $zero, L_80069534
    if (ctx->r2 == 0) {
        // 0x80069514: nop

            goto L_80069534;
    }
    // 0x80069514: nop

    // 0x80069518: jal         0x80061348
    // 0x8006951C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006951C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x80069520: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80069524: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069528: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006952C: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x80069530: nop

            goto L_80069628;
    }
    // 0x80069530: nop

L_80069534:
    // 0x80069534: jal         0x80061348
    // 0x80069538: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x80069538: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006953C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069540: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069544: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069548: beq         $v0, $zero, L_80069588
    if (ctx->r2 == 0) {
        // 0x8006954C: nop

            goto L_80069588;
    }
    // 0x8006954C: nop

    // 0x80069550: jal         0x80061348
    // 0x80069554: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069554: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069558: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006955C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069560: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80069564: beq         $v0, $zero, L_80069588
    if (ctx->r2 == 0) {
        // 0x80069568: nop

            goto L_80069588;
    }
    // 0x80069568: nop

    // 0x8006956C: jal         0x80061348
    // 0x80069570: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x80069570: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x80069574: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069578: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006957C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069580: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x80069584: nop

            goto L_80069628;
    }
    // 0x80069584: nop

L_80069588:
    // 0x80069588: jal         0x80061348
    // 0x8006958C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006958C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x80069590: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x80069594: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069598: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006959C: beq         $v0, $zero, L_800695DC
    if (ctx->r2 == 0) {
        // 0x800695A0: nop

            goto L_800695DC;
    }
    // 0x800695A0: nop

    // 0x800695A4: jal         0x80061348
    // 0x800695A8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x800695A8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x800695AC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x800695B0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x800695B4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800695B8: beq         $v0, $zero, L_800695DC
    if (ctx->r2 == 0) {
        // 0x800695BC: nop

            goto L_800695DC;
    }
    // 0x800695BC: nop

    // 0x800695C0: jal         0x80061348
    // 0x800695C4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x800695C4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x800695C8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800695CC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800695D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800695D4: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x800695D8: nop

            goto L_80069628;
    }
    // 0x800695D8: nop

L_800695DC:
    // 0x800695DC: jal         0x80061348
    // 0x800695E0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x800695E0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x800695E4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800695E8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800695EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800695F0: beq         $v0, $zero, L_80069628
    if (ctx->r2 == 0) {
        // 0x800695F4: nop

            goto L_80069628;
    }
    // 0x800695F4: nop

    // 0x800695F8: jal         0x80061348
    // 0x800695FC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x800695FC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x80069600: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069604: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069608: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006960C: beq         $v0, $zero, L_80069628
    if (ctx->r2 == 0) {
        // 0x80069610: nop

            goto L_80069628;
    }
    // 0x80069610: nop

    // 0x80069614: jal         0x80061348
    // 0x80069618: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x80069618: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006961C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069620: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069624: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80069628:
    // 0x80069628: b           L_80069638
    // 0x8006962C: nop

        goto L_80069638;
    // 0x8006962C: nop

    // 0x80069630: b           L_80069638
    // 0x80069634: nop

        goto L_80069638;
    // 0x80069634: nop

L_80069638:
    // 0x80069638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006963C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069640: jr          $ra
    // 0x80069644: nop

    return;
    // 0x80069644: nop

;}
RECOMP_FUNC void func_80069648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006964C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069650: jal         0x80061348
    // 0x80069654: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069654: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x80069658: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006965C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069660: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069664: beq         $v0, $zero, L_800696A4
    if (ctx->r2 == 0) {
        // 0x80069668: nop

            goto L_800696A4;
    }
    // 0x80069668: nop

    // 0x8006966C: jal         0x80061348
    // 0x80069670: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069670: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x80069674: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069678: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006967C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069680: beq         $v0, $zero, L_800696A4
    if (ctx->r2 == 0) {
        // 0x80069684: nop

            goto L_800696A4;
    }
    // 0x80069684: nop

    // 0x80069688: jal         0x80061348
    // 0x8006968C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006968C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x80069690: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069694: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069698: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006969C: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x800696A0: nop

            goto L_800698E8;
    }
    // 0x800696A0: nop

L_800696A4:
    // 0x800696A4: jal         0x80061348
    // 0x800696A8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800696A8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x800696AC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800696B0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800696B4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800696B8: beq         $v0, $zero, L_800696F8
    if (ctx->r2 == 0) {
        // 0x800696BC: nop

            goto L_800696F8;
    }
    // 0x800696BC: nop

    // 0x800696C0: jal         0x80061348
    // 0x800696C4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x800696C4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x800696C8: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x800696CC: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800696D0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800696D4: beq         $v0, $zero, L_800696F8
    if (ctx->r2 == 0) {
        // 0x800696D8: nop

            goto L_800696F8;
    }
    // 0x800696D8: nop

    // 0x800696DC: jal         0x80061348
    // 0x800696E0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x800696E0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x800696E4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x800696E8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x800696EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800696F0: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x800696F4: nop

            goto L_800698E8;
    }
    // 0x800696F4: nop

L_800696F8:
    // 0x800696F8: jal         0x80061348
    // 0x800696FC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800696FC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x80069700: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069704: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069708: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006970C: beq         $v0, $zero, L_8006974C
    if (ctx->r2 == 0) {
        // 0x80069710: nop

            goto L_8006974C;
    }
    // 0x80069710: nop

    // 0x80069714: jal         0x80061348
    // 0x80069718: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x80069718: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006971C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069720: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80069724: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069728: beq         $v0, $zero, L_8006974C
    if (ctx->r2 == 0) {
        // 0x8006972C: nop

            goto L_8006974C;
    }
    // 0x8006972C: nop

    // 0x80069730: jal         0x80061348
    // 0x80069734: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x80069734: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x80069738: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006973C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069740: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069744: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x80069748: nop

            goto L_800698E8;
    }
    // 0x80069748: nop

L_8006974C:
    // 0x8006974C: jal         0x80061348
    // 0x80069750: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x80069750: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x80069754: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069758: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006975C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069760: beq         $v0, $zero, L_800697A0
    if (ctx->r2 == 0) {
        // 0x80069764: nop

            goto L_800697A0;
    }
    // 0x80069764: nop

    // 0x80069768: jal         0x80061348
    // 0x8006976C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006976C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x80069770: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80069774: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069778: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006977C: beq         $v0, $zero, L_800697A0
    if (ctx->r2 == 0) {
        // 0x80069780: nop

            goto L_800697A0;
    }
    // 0x80069780: nop

    // 0x80069784: jal         0x80061348
    // 0x80069788: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x80069788: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006978C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069790: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069794: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069798: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x8006979C: nop

            goto L_800698E8;
    }
    // 0x8006979C: nop

L_800697A0:
    // 0x800697A0: jal         0x80061348
    // 0x800697A4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x800697A4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x800697A8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800697AC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800697B0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800697B4: beq         $v0, $zero, L_800697F4
    if (ctx->r2 == 0) {
        // 0x800697B8: nop

            goto L_800697F4;
    }
    // 0x800697B8: nop

    // 0x800697BC: jal         0x80061348
    // 0x800697C0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x800697C0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x800697C4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800697C8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800697CC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800697D0: beq         $v0, $zero, L_800697F4
    if (ctx->r2 == 0) {
        // 0x800697D4: nop

            goto L_800697F4;
    }
    // 0x800697D4: nop

    // 0x800697D8: jal         0x80061348
    // 0x800697DC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x800697DC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x800697E0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x800697E4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800697E8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800697EC: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x800697F0: nop

            goto L_800698E8;
    }
    // 0x800697F0: nop

L_800697F4:
    // 0x800697F4: jal         0x80061348
    // 0x800697F8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x800697F8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x800697FC: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069800: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069804: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069808: beq         $v0, $zero, L_80069848
    if (ctx->r2 == 0) {
        // 0x8006980C: nop

            goto L_80069848;
    }
    // 0x8006980C: nop

    // 0x80069810: jal         0x80061348
    // 0x80069814: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069814: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069818: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006981C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069820: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80069824: beq         $v0, $zero, L_80069848
    if (ctx->r2 == 0) {
        // 0x80069828: nop

            goto L_80069848;
    }
    // 0x80069828: nop

    // 0x8006982C: jal         0x80061348
    // 0x80069830: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x80069830: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x80069834: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069838: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006983C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069840: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x80069844: nop

            goto L_800698E8;
    }
    // 0x80069844: nop

L_80069848:
    // 0x80069848: jal         0x80061348
    // 0x8006984C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006984C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x80069850: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x80069854: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069858: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006985C: beq         $v0, $zero, L_8006989C
    if (ctx->r2 == 0) {
        // 0x80069860: nop

            goto L_8006989C;
    }
    // 0x80069860: nop

    // 0x80069864: jal         0x80061348
    // 0x80069868: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x80069868: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006986C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069870: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80069874: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069878: beq         $v0, $zero, L_8006989C
    if (ctx->r2 == 0) {
        // 0x8006987C: nop

            goto L_8006989C;
    }
    // 0x8006987C: nop

    // 0x80069880: jal         0x80061348
    // 0x80069884: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x80069884: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x80069888: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006988C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069890: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069894: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x80069898: nop

            goto L_800698E8;
    }
    // 0x80069898: nop

L_8006989C:
    // 0x8006989C: jal         0x80061348
    // 0x800698A0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x800698A0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x800698A4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800698A8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800698AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800698B0: beq         $v0, $zero, L_800698E8
    if (ctx->r2 == 0) {
        // 0x800698B4: nop

            goto L_800698E8;
    }
    // 0x800698B4: nop

    // 0x800698B8: jal         0x80061348
    // 0x800698BC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x800698BC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x800698C0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800698C4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800698C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800698CC: beq         $v0, $zero, L_800698E8
    if (ctx->r2 == 0) {
        // 0x800698D0: nop

            goto L_800698E8;
    }
    // 0x800698D0: nop

    // 0x800698D4: jal         0x80061348
    // 0x800698D8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x800698D8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x800698DC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800698E0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800698E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800698E8:
    // 0x800698E8: b           L_800698F8
    // 0x800698EC: nop

        goto L_800698F8;
    // 0x800698EC: nop

    // 0x800698F0: b           L_800698F8
    // 0x800698F4: nop

        goto L_800698F8;
    // 0x800698F4: nop

L_800698F8:
    // 0x800698F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800698FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069900: jr          $ra
    // 0x80069904: nop

    return;
    // 0x80069904: nop

;}
RECOMP_FUNC void func_80069908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006990C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069910: jal         0x80061348
    // 0x80069914: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069914: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x80069918: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006991C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069920: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069924: beq         $v0, $zero, L_80069964
    if (ctx->r2 == 0) {
        // 0x80069928: nop

            goto L_80069964;
    }
    // 0x80069928: nop

    // 0x8006992C: jal         0x80061348
    // 0x80069930: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069930: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x80069934: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069938: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006993C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069940: beq         $v0, $zero, L_80069964
    if (ctx->r2 == 0) {
        // 0x80069944: nop

            goto L_80069964;
    }
    // 0x80069944: nop

    // 0x80069948: jal         0x80061348
    // 0x8006994C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006994C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x80069950: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069954: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069958: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006995C: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069960: nop

            goto L_80069BA8;
    }
    // 0x80069960: nop

L_80069964:
    // 0x80069964: jal         0x80061348
    // 0x80069968: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80069968: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006996C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069970: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069974: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069978: beq         $v0, $zero, L_800699B8
    if (ctx->r2 == 0) {
        // 0x8006997C: nop

            goto L_800699B8;
    }
    // 0x8006997C: nop

    // 0x80069980: jal         0x80061348
    // 0x80069984: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x80069984: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x80069988: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006998C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069990: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069994: beq         $v0, $zero, L_800699B8
    if (ctx->r2 == 0) {
        // 0x80069998: nop

            goto L_800699B8;
    }
    // 0x80069998: nop

    // 0x8006999C: jal         0x80061348
    // 0x800699A0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x800699A0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x800699A4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x800699A8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x800699AC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800699B0: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x800699B4: nop

            goto L_80069BA8;
    }
    // 0x800699B4: nop

L_800699B8:
    // 0x800699B8: jal         0x80061348
    // 0x800699BC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800699BC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x800699C0: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x800699C4: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x800699C8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800699CC: beq         $v0, $zero, L_80069A0C
    if (ctx->r2 == 0) {
        // 0x800699D0: nop

            goto L_80069A0C;
    }
    // 0x800699D0: nop

    // 0x800699D4: jal         0x80061348
    // 0x800699D8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x800699D8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x800699DC: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x800699E0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800699E4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800699E8: beq         $v0, $zero, L_80069A0C
    if (ctx->r2 == 0) {
        // 0x800699EC: nop

            goto L_80069A0C;
    }
    // 0x800699EC: nop

    // 0x800699F0: jal         0x80061348
    // 0x800699F4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x800699F4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x800699F8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x800699FC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069A00: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069A04: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069A08: nop

            goto L_80069BA8;
    }
    // 0x80069A08: nop

L_80069A0C:
    // 0x80069A0C: jal         0x80061348
    // 0x80069A10: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x80069A10: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x80069A14: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069A18: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80069A1C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069A20: beq         $v0, $zero, L_80069A60
    if (ctx->r2 == 0) {
        // 0x80069A24: nop

            goto L_80069A60;
    }
    // 0x80069A24: nop

    // 0x80069A28: jal         0x80061348
    // 0x80069A2C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x80069A2C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x80069A30: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80069A34: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069A38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069A3C: beq         $v0, $zero, L_80069A60
    if (ctx->r2 == 0) {
        // 0x80069A40: nop

            goto L_80069A60;
    }
    // 0x80069A40: nop

    // 0x80069A44: jal         0x80061348
    // 0x80069A48: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x80069A48: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x80069A4C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069A50: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069A54: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069A58: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069A5C: nop

            goto L_80069BA8;
    }
    // 0x80069A5C: nop

L_80069A60:
    // 0x80069A60: jal         0x80061348
    // 0x80069A64: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x80069A64: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x80069A68: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069A6C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069A70: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069A74: beq         $v0, $zero, L_80069AB4
    if (ctx->r2 == 0) {
        // 0x80069A78: nop

            goto L_80069AB4;
    }
    // 0x80069A78: nop

    // 0x80069A7C: jal         0x80061348
    // 0x80069A80: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x80069A80: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x80069A84: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069A88: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069A8C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069A90: beq         $v0, $zero, L_80069AB4
    if (ctx->r2 == 0) {
        // 0x80069A94: nop

            goto L_80069AB4;
    }
    // 0x80069A94: nop

    // 0x80069A98: jal         0x80061348
    // 0x80069A9C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x80069A9C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x80069AA0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80069AA4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069AA8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069AAC: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069AB0: nop

            goto L_80069BA8;
    }
    // 0x80069AB0: nop

L_80069AB4:
    // 0x80069AB4: jal         0x80061348
    // 0x80069AB8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x80069AB8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x80069ABC: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069AC0: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069AC4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069AC8: beq         $v0, $zero, L_80069B08
    if (ctx->r2 == 0) {
        // 0x80069ACC: nop

            goto L_80069B08;
    }
    // 0x80069ACC: nop

    // 0x80069AD0: jal         0x80061348
    // 0x80069AD4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069AD4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069AD8: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069ADC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069AE0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80069AE4: beq         $v0, $zero, L_80069B08
    if (ctx->r2 == 0) {
        // 0x80069AE8: nop

            goto L_80069B08;
    }
    // 0x80069AE8: nop

    // 0x80069AEC: jal         0x80061348
    // 0x80069AF0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x80069AF0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x80069AF4: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069AF8: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80069AFC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069B00: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069B04: nop

            goto L_80069BA8;
    }
    // 0x80069B04: nop

L_80069B08:
    // 0x80069B08: jal         0x80061348
    // 0x80069B0C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x80069B0C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x80069B10: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x80069B14: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069B18: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069B1C: beq         $v0, $zero, L_80069B5C
    if (ctx->r2 == 0) {
        // 0x80069B20: nop

            goto L_80069B5C;
    }
    // 0x80069B20: nop

    // 0x80069B24: jal         0x80061348
    // 0x80069B28: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x80069B28: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x80069B2C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069B30: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80069B34: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069B38: beq         $v0, $zero, L_80069B5C
    if (ctx->r2 == 0) {
        // 0x80069B3C: nop

            goto L_80069B5C;
    }
    // 0x80069B3C: nop

    // 0x80069B40: jal         0x80061348
    // 0x80069B44: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x80069B44: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x80069B48: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80069B4C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069B50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069B54: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069B58: nop

            goto L_80069BA8;
    }
    // 0x80069B58: nop

L_80069B5C:
    // 0x80069B5C: jal         0x80061348
    // 0x80069B60: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x80069B60: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x80069B64: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069B68: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069B6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069B70: beq         $v0, $zero, L_80069BA8
    if (ctx->r2 == 0) {
        // 0x80069B74: nop

            goto L_80069BA8;
    }
    // 0x80069B74: nop

    // 0x80069B78: jal         0x80061348
    // 0x80069B7C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x80069B7C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x80069B80: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069B84: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069B88: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069B8C: beq         $v0, $zero, L_80069BA8
    if (ctx->r2 == 0) {
        // 0x80069B90: nop

            goto L_80069BA8;
    }
    // 0x80069B90: nop

    // 0x80069B94: jal         0x80061348
    // 0x80069B98: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x80069B98: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x80069B9C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069BA0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069BA4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80069BA8:
    // 0x80069BA8: b           L_80069BB8
    // 0x80069BAC: nop

        goto L_80069BB8;
    // 0x80069BAC: nop

    // 0x80069BB0: b           L_80069BB8
    // 0x80069BB4: nop

        goto L_80069BB8;
    // 0x80069BB4: nop

L_80069BB8:
    // 0x80069BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069BC0: jr          $ra
    // 0x80069BC4: nop

    return;
    // 0x80069BC4: nop

;}
RECOMP_FUNC void func_80069BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069BD0: jal         0x80061488
    // 0x80069BD4: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80069BD4: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_0:
    // 0x80069BD8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80069BDC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80069BE0: b           L_80069BF0
    // 0x80069BE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80069BF0;
    // 0x80069BE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069BE8: b           L_80069BF0
    // 0x80069BEC: nop

        goto L_80069BF0;
    // 0x80069BEC: nop

L_80069BF0:
    // 0x80069BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069BF8: jr          $ra
    // 0x80069BFC: nop

    return;
    // 0x80069BFC: nop

;}
RECOMP_FUNC void func_80069C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069C08: jal         0x80061348
    // 0x80069C0C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069C0C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x80069C10: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069C14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069C18: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069C1C: beq         $v0, $zero, L_80069C38
    if (ctx->r2 == 0) {
        // 0x80069C20: nop

            goto L_80069C38;
    }
    // 0x80069C20: nop

    // 0x80069C24: jal         0x80061348
    // 0x80069C28: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069C28: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    after_1:
    // 0x80069C2C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069C30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069C34: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80069C38:
    // 0x80069C38: b           L_80069C48
    // 0x80069C3C: nop

        goto L_80069C48;
    // 0x80069C3C: nop

    // 0x80069C40: b           L_80069C48
    // 0x80069C44: nop

        goto L_80069C48;
    // 0x80069C44: nop

L_80069C48:
    // 0x80069C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069C50: jr          $ra
    // 0x80069C54: nop

    return;
    // 0x80069C54: nop

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
RECOMP_FUNC void func_80069C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069C98: jal         0x80061348
    // 0x80069C9C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069C9C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x80069CA0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069CA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069CA8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069CAC: beq         $v0, $zero, L_80069CC8
    if (ctx->r2 == 0) {
        // 0x80069CB0: nop

            goto L_80069CC8;
    }
    // 0x80069CB0: nop

    // 0x80069CB4: jal         0x80061348
    // 0x80069CB8: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069CB8: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    after_1:
    // 0x80069CBC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069CC0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069CC4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80069CC8:
    // 0x80069CC8: b           L_80069CD8
    // 0x80069CCC: nop

        goto L_80069CD8;
    // 0x80069CCC: nop

    // 0x80069CD0: b           L_80069CD8
    // 0x80069CD4: nop

        goto L_80069CD8;
    // 0x80069CD4: nop

L_80069CD8:
    // 0x80069CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069CE0: jr          $ra
    // 0x80069CE4: nop

    return;
    // 0x80069CE4: nop

;}
