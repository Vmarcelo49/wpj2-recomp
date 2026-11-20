#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800715A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800715A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800715AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800715B0: nop

    // 0x800715B4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800715B8: nop

    // 0x800715BC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800715C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800715C4: jr          $ra
    // 0x800715C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800715C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800715CC: jr          $ra
    // 0x800715D0: nop

    return;
    // 0x800715D0: nop

    // 0x800715D4: jr          $ra
    // 0x800715D8: nop

    return;
    // 0x800715D8: nop

;}
RECOMP_FUNC void func_800715DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800715DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800715E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800715E4: jal         0x80061348
    // 0x800715E8: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800715E8: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x800715EC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800715F0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800715F4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800715F8: beq         $v0, $zero, L_8007164C
    if (ctx->r2 == 0) {
        // 0x800715FC: nop

            goto L_8007164C;
    }
    // 0x800715FC: nop

    // 0x80071600: jal         0x80061348
    // 0x80071604: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071604: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x80071608: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007160C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071610: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071614: beq         $v0, $zero, L_8007164C
    if (ctx->r2 == 0) {
        // 0x80071618: nop

            goto L_8007164C;
    }
    // 0x80071618: nop

    // 0x8007161C: jal         0x80061348
    // 0x80071620: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071620: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x80071624: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071628: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007162C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071630: beq         $v0, $zero, L_8007164C
    if (ctx->r2 == 0) {
        // 0x80071634: nop

            goto L_8007164C;
    }
    // 0x80071634: nop

    // 0x80071638: jal         0x80061348
    // 0x8007163C: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007163C: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x80071640: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071644: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80071648: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007164C:
    // 0x8007164C: b           L_8007165C
    // 0x80071650: nop

        goto L_8007165C;
    // 0x80071650: nop

    // 0x80071654: b           L_8007165C
    // 0x80071658: nop

        goto L_8007165C;
    // 0x80071658: nop

L_8007165C:
    // 0x8007165C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071664: jr          $ra
    // 0x80071668: nop

    return;
    // 0x80071668: nop

;}
RECOMP_FUNC void func_8007166C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007166C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071674: jal         0x80061348
    // 0x80071678: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071678: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x8007167C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071680: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071684: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071688: beq         $v0, $zero, L_800716DC
    if (ctx->r2 == 0) {
        // 0x8007168C: nop

            goto L_800716DC;
    }
    // 0x8007168C: nop

    // 0x80071690: jal         0x80061348
    // 0x80071694: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071694: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x80071698: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007169C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800716A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800716A4: beq         $v0, $zero, L_800716DC
    if (ctx->r2 == 0) {
        // 0x800716A8: nop

            goto L_800716DC;
    }
    // 0x800716A8: nop

    // 0x800716AC: jal         0x80061348
    // 0x800716B0: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800716B0: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x800716B4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800716B8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800716BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800716C0: beq         $v0, $zero, L_800716DC
    if (ctx->r2 == 0) {
        // 0x800716C4: nop

            goto L_800716DC;
    }
    // 0x800716C4: nop

    // 0x800716C8: jal         0x80061348
    // 0x800716CC: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800716CC: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x800716D0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800716D4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800716D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800716DC:
    // 0x800716DC: b           L_800716EC
    // 0x800716E0: nop

        goto L_800716EC;
    // 0x800716E0: nop

    // 0x800716E4: b           L_800716EC
    // 0x800716E8: nop

        goto L_800716EC;
    // 0x800716E8: nop

L_800716EC:
    // 0x800716EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800716F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800716F4: jr          $ra
    // 0x800716F8: nop

    return;
    // 0x800716F8: nop

;}
RECOMP_FUNC void func_800716FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800716FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071700: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071704: nop

    // 0x80071708: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8007170C: nop

    // 0x80071710: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071714: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80071718: jr          $ra
    // 0x8007171C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007171C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071720: jr          $ra
    // 0x80071724: nop

    return;
    // 0x80071724: nop

    // 0x80071728: jr          $ra
    // 0x8007172C: nop

    return;
    // 0x8007172C: nop

;}
RECOMP_FUNC void func_80071730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071730: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071734: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071738: nop

    // 0x8007173C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80071740: nop

    // 0x80071744: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071748: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007174C: jr          $ra
    // 0x80071750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071754: jr          $ra
    // 0x80071758: nop

    return;
    // 0x80071758: nop

    // 0x8007175C: jr          $ra
    // 0x80071760: nop

    return;
    // 0x80071760: nop

;}
RECOMP_FUNC void func_80071764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007176C: jal         0x80061348
    // 0x80071770: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071770: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071774: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071778: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007177C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071780: beq         $v0, $zero, L_800717D4
    if (ctx->r2 == 0) {
        // 0x80071784: nop

            goto L_800717D4;
    }
    // 0x80071784: nop

    // 0x80071788: jal         0x80061348
    // 0x8007178C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007178C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x80071790: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071794: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071798: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007179C: beq         $v0, $zero, L_800717D4
    if (ctx->r2 == 0) {
        // 0x800717A0: nop

            goto L_800717D4;
    }
    // 0x800717A0: nop

    // 0x800717A4: jal         0x80061348
    // 0x800717A8: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800717A8: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x800717AC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800717B0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800717B4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800717B8: beq         $v0, $zero, L_800717D4
    if (ctx->r2 == 0) {
        // 0x800717BC: nop

            goto L_800717D4;
    }
    // 0x800717BC: nop

    // 0x800717C0: jal         0x80061348
    // 0x800717C4: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800717C4: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x800717C8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800717CC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800717D0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800717D4:
    // 0x800717D4: b           L_800717E4
    // 0x800717D8: nop

        goto L_800717E4;
    // 0x800717D8: nop

    // 0x800717DC: b           L_800717E4
    // 0x800717E0: nop

        goto L_800717E4;
    // 0x800717E0: nop

L_800717E4:
    // 0x800717E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800717E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800717EC: jr          $ra
    // 0x800717F0: nop

    return;
    // 0x800717F0: nop

;}
RECOMP_FUNC void func_800717F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800717F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800717F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800717FC: jal         0x80061348
    // 0x80071800: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071800: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071804: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071808: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007180C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071810: beq         $v0, $zero, L_80071864
    if (ctx->r2 == 0) {
        // 0x80071814: nop

            goto L_80071864;
    }
    // 0x80071814: nop

    // 0x80071818: jal         0x80061348
    // 0x8007181C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007181C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x80071820: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071824: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071828: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007182C: beq         $v0, $zero, L_80071864
    if (ctx->r2 == 0) {
        // 0x80071830: nop

            goto L_80071864;
    }
    // 0x80071830: nop

    // 0x80071834: jal         0x80061348
    // 0x80071838: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071838: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x8007183C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071840: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071844: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071848: beq         $v0, $zero, L_80071864
    if (ctx->r2 == 0) {
        // 0x8007184C: nop

            goto L_80071864;
    }
    // 0x8007184C: nop

    // 0x80071850: jal         0x80061348
    // 0x80071854: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071854: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x80071858: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007185C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80071860: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071864:
    // 0x80071864: b           L_80071874
    // 0x80071868: nop

        goto L_80071874;
    // 0x80071868: nop

    // 0x8007186C: b           L_80071874
    // 0x80071870: nop

        goto L_80071874;
    // 0x80071870: nop

L_80071874:
    // 0x80071874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007187C: jr          $ra
    // 0x80071880: nop

    return;
    // 0x80071880: nop

;}
RECOMP_FUNC void func_80071884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007188C: jal         0x80061348
    // 0x80071890: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071890: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071894: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071898: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007189C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800718A0: beq         $v0, $zero, L_800718F4
    if (ctx->r2 == 0) {
        // 0x800718A4: nop

            goto L_800718F4;
    }
    // 0x800718A4: nop

    // 0x800718A8: jal         0x80061348
    // 0x800718AC: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800718AC: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x800718B0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800718B4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800718B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800718BC: beq         $v0, $zero, L_800718F4
    if (ctx->r2 == 0) {
        // 0x800718C0: nop

            goto L_800718F4;
    }
    // 0x800718C0: nop

    // 0x800718C4: jal         0x80061348
    // 0x800718C8: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800718C8: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x800718CC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800718D0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800718D4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800718D8: beq         $v0, $zero, L_800718F4
    if (ctx->r2 == 0) {
        // 0x800718DC: nop

            goto L_800718F4;
    }
    // 0x800718DC: nop

    // 0x800718E0: jal         0x80061348
    // 0x800718E4: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800718E4: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x800718E8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800718EC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800718F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800718F4:
    // 0x800718F4: b           L_80071904
    // 0x800718F8: nop

        goto L_80071904;
    // 0x800718F8: nop

    // 0x800718FC: b           L_80071904
    // 0x80071900: nop

        goto L_80071904;
    // 0x80071900: nop

L_80071904:
    // 0x80071904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007190C: jr          $ra
    // 0x80071910: nop

    return;
    // 0x80071910: nop

;}
RECOMP_FUNC void func_80071914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007191C: jal         0x80061348
    // 0x80071920: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071920: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071924: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071928: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007192C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071930: beq         $v0, $zero, L_80071984
    if (ctx->r2 == 0) {
        // 0x80071934: nop

            goto L_80071984;
    }
    // 0x80071934: nop

    // 0x80071938: jal         0x80061348
    // 0x8007193C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007193C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x80071940: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071944: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071948: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007194C: beq         $v0, $zero, L_80071984
    if (ctx->r2 == 0) {
        // 0x80071950: nop

            goto L_80071984;
    }
    // 0x80071950: nop

    // 0x80071954: jal         0x80061348
    // 0x80071958: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071958: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x8007195C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071960: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071964: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071968: beq         $v0, $zero, L_80071984
    if (ctx->r2 == 0) {
        // 0x8007196C: nop

            goto L_80071984;
    }
    // 0x8007196C: nop

    // 0x80071970: jal         0x80061348
    // 0x80071974: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071974: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x80071978: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007197C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80071980: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071984:
    // 0x80071984: b           L_80071994
    // 0x80071988: nop

        goto L_80071994;
    // 0x80071988: nop

    // 0x8007198C: b           L_80071994
    // 0x80071990: nop

        goto L_80071994;
    // 0x80071990: nop

L_80071994:
    // 0x80071994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007199C: jr          $ra
    // 0x800719A0: nop

    return;
    // 0x800719A0: nop

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
RECOMP_FUNC void func_800719D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800719D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800719D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800719DC: jal         0x80061348
    // 0x800719E0: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800719E0: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    after_0:
    // 0x800719E4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800719E8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800719EC: b           L_800719FC
    // 0x800719F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800719FC;
    // 0x800719F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800719F4: b           L_800719FC
    // 0x800719F8: nop

        goto L_800719FC;
    // 0x800719F8: nop

L_800719FC:
    // 0x800719FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071A04: jr          $ra
    // 0x80071A08: nop

    return;
    // 0x80071A08: nop

;}
RECOMP_FUNC void func_80071A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071A14: jal         0x80061348
    // 0x80071A18: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071A18: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    after_0:
    // 0x80071A1C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071A20: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071A24: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071A28: beq         $v0, $zero, L_80071A44
    if (ctx->r2 == 0) {
        // 0x80071A2C: nop

            goto L_80071A44;
    }
    // 0x80071A2C: nop

    // 0x80071A30: jal         0x80061348
    // 0x80071A34: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071A34: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    after_1:
    // 0x80071A38: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071A3C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071A40: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071A44:
    // 0x80071A44: b           L_80071A54
    // 0x80071A48: nop

        goto L_80071A54;
    // 0x80071A48: nop

    // 0x80071A4C: b           L_80071A54
    // 0x80071A50: nop

        goto L_80071A54;
    // 0x80071A50: nop

L_80071A54:
    // 0x80071A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071A5C: jr          $ra
    // 0x80071A60: nop

    return;
    // 0x80071A60: nop

;}
RECOMP_FUNC void func_80071A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071A6C: jal         0x80061348
    // 0x80071A70: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071A70: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    after_0:
    // 0x80071A74: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071A78: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071A7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071A80: beq         $v0, $zero, L_80071A9C
    if (ctx->r2 == 0) {
        // 0x80071A84: nop

            goto L_80071A9C;
    }
    // 0x80071A84: nop

    // 0x80071A88: jal         0x80061348
    // 0x80071A8C: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071A8C: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    after_1:
    // 0x80071A90: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071A94: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071A98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071A9C:
    // 0x80071A9C: b           L_80071AAC
    // 0x80071AA0: nop

        goto L_80071AAC;
    // 0x80071AA0: nop

    // 0x80071AA4: b           L_80071AAC
    // 0x80071AA8: nop

        goto L_80071AAC;
    // 0x80071AA8: nop

L_80071AAC:
    // 0x80071AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071AB4: jr          $ra
    // 0x80071AB8: nop

    return;
    // 0x80071AB8: nop

;}
RECOMP_FUNC void func_80071ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071ABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071AC4: jal         0x80061348
    // 0x80071AC8: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071AC8: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071ACC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071AD0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071AD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071AD8: beq         $v0, $zero, L_80071B10
    if (ctx->r2 == 0) {
        // 0x80071ADC: nop

            goto L_80071B10;
    }
    // 0x80071ADC: nop

    // 0x80071AE0: jal         0x80061348
    // 0x80071AE4: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071AE4: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071AE8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071AEC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071AF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071AF4: beq         $v0, $zero, L_80071B10
    if (ctx->r2 == 0) {
        // 0x80071AF8: nop

            goto L_80071B10;
    }
    // 0x80071AF8: nop

    // 0x80071AFC: jal         0x80061348
    // 0x80071B00: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071B00: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071B04: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071B08: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071B0C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071B10:
    // 0x80071B10: b           L_80071B20
    // 0x80071B14: nop

        goto L_80071B20;
    // 0x80071B14: nop

    // 0x80071B18: b           L_80071B20
    // 0x80071B1C: nop

        goto L_80071B20;
    // 0x80071B1C: nop

L_80071B20:
    // 0x80071B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071B28: jr          $ra
    // 0x80071B2C: nop

    return;
    // 0x80071B2C: nop

;}
RECOMP_FUNC void func_80071B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071B38: jal         0x80061348
    // 0x80071B3C: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071B3C: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071B40: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071B44: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071B48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071B4C: beq         $v0, $zero, L_80071B84
    if (ctx->r2 == 0) {
        // 0x80071B50: nop

            goto L_80071B84;
    }
    // 0x80071B50: nop

    // 0x80071B54: jal         0x80061348
    // 0x80071B58: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071B58: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071B5C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071B60: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071B64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071B68: beq         $v0, $zero, L_80071B84
    if (ctx->r2 == 0) {
        // 0x80071B6C: nop

            goto L_80071B84;
    }
    // 0x80071B6C: nop

    // 0x80071B70: jal         0x80061348
    // 0x80071B74: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071B74: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071B78: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071B7C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071B80: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071B84:
    // 0x80071B84: b           L_80071B94
    // 0x80071B88: nop

        goto L_80071B94;
    // 0x80071B88: nop

    // 0x80071B8C: b           L_80071B94
    // 0x80071B90: nop

        goto L_80071B94;
    // 0x80071B90: nop

L_80071B94:
    // 0x80071B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071B9C: jr          $ra
    // 0x80071BA0: nop

    return;
    // 0x80071BA0: nop

;}
RECOMP_FUNC void func_80071BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071BAC: jal         0x80061348
    // 0x80071BB0: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071BB0: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    after_0:
    // 0x80071BB4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071BB8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071BBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071BC0: beq         $v0, $zero, L_80071BDC
    if (ctx->r2 == 0) {
        // 0x80071BC4: nop

            goto L_80071BDC;
    }
    // 0x80071BC4: nop

    // 0x80071BC8: jal         0x80061348
    // 0x80071BCC: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071BCC: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    after_1:
    // 0x80071BD0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071BD4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071BD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071BDC:
    // 0x80071BDC: b           L_80071BEC
    // 0x80071BE0: nop

        goto L_80071BEC;
    // 0x80071BE0: nop

    // 0x80071BE4: b           L_80071BEC
    // 0x80071BE8: nop

        goto L_80071BEC;
    // 0x80071BE8: nop

L_80071BEC:
    // 0x80071BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071BF4: jr          $ra
    // 0x80071BF8: nop

    return;
    // 0x80071BF8: nop

;}
RECOMP_FUNC void func_80071BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071C04: jal         0x80061348
    // 0x80071C08: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071C08: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    after_0:
    // 0x80071C0C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071C10: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071C14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071C18: beq         $v0, $zero, L_80071C34
    if (ctx->r2 == 0) {
        // 0x80071C1C: nop

            goto L_80071C34;
    }
    // 0x80071C1C: nop

    // 0x80071C20: jal         0x80061348
    // 0x80071C24: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071C24: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    after_1:
    // 0x80071C28: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071C2C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071C30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071C34:
    // 0x80071C34: b           L_80071C44
    // 0x80071C38: nop

        goto L_80071C44;
    // 0x80071C38: nop

    // 0x80071C3C: b           L_80071C44
    // 0x80071C40: nop

        goto L_80071C44;
    // 0x80071C40: nop

L_80071C44:
    // 0x80071C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071C48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071C4C: jr          $ra
    // 0x80071C50: nop

    return;
    // 0x80071C50: nop

;}
RECOMP_FUNC void func_80071C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C54: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071C58: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071C5C: nop

    // 0x80071C60: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80071C64: nop

    // 0x80071C68: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071C6C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80071C70: jr          $ra
    // 0x80071C74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071C74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071C78: jr          $ra
    // 0x80071C7C: nop

    return;
    // 0x80071C7C: nop

    // 0x80071C80: jr          $ra
    // 0x80071C84: nop

    return;
    // 0x80071C84: nop

;}
RECOMP_FUNC void func_80071C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071C8C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071C90: nop

    // 0x80071C94: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80071C98: nop

    // 0x80071C9C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071CA0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80071CA4: jr          $ra
    // 0x80071CA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071CA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071CAC: jr          $ra
    // 0x80071CB0: nop

    return;
    // 0x80071CB0: nop

    // 0x80071CB4: jr          $ra
    // 0x80071CB8: nop

    return;
    // 0x80071CB8: nop

;}
RECOMP_FUNC void func_80071CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071CC4: jal         0x80061348
    // 0x80071CC8: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071CC8: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071CCC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071CD0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071CD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071CD8: beq         $v0, $zero, L_80071D10
    if (ctx->r2 == 0) {
        // 0x80071CDC: nop

            goto L_80071D10;
    }
    // 0x80071CDC: nop

    // 0x80071CE0: jal         0x80061348
    // 0x80071CE4: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071CE4: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071CE8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071CEC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071CF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071CF4: beq         $v0, $zero, L_80071D10
    if (ctx->r2 == 0) {
        // 0x80071CF8: nop

            goto L_80071D10;
    }
    // 0x80071CF8: nop

    // 0x80071CFC: jal         0x80061348
    // 0x80071D00: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071D00: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071D04: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071D08: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071D0C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071D10:
    // 0x80071D10: b           L_80071D20
    // 0x80071D14: nop

        goto L_80071D20;
    // 0x80071D14: nop

    // 0x80071D18: b           L_80071D20
    // 0x80071D1C: nop

        goto L_80071D20;
    // 0x80071D1C: nop

L_80071D20:
    // 0x80071D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071D24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071D28: jr          $ra
    // 0x80071D2C: nop

    return;
    // 0x80071D2C: nop

;}
RECOMP_FUNC void func_80071D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071D38: jal         0x80061348
    // 0x80071D3C: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071D3C: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071D40: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071D44: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071D48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071D4C: beq         $v0, $zero, L_80071D84
    if (ctx->r2 == 0) {
        // 0x80071D50: nop

            goto L_80071D84;
    }
    // 0x80071D50: nop

    // 0x80071D54: jal         0x80061348
    // 0x80071D58: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071D58: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071D5C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071D60: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071D64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071D68: beq         $v0, $zero, L_80071D84
    if (ctx->r2 == 0) {
        // 0x80071D6C: nop

            goto L_80071D84;
    }
    // 0x80071D6C: nop

    // 0x80071D70: jal         0x80061348
    // 0x80071D74: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071D74: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071D78: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071D7C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071D80: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071D84:
    // 0x80071D84: b           L_80071D94
    // 0x80071D88: nop

        goto L_80071D94;
    // 0x80071D88: nop

    // 0x80071D8C: b           L_80071D94
    // 0x80071D90: nop

        goto L_80071D94;
    // 0x80071D90: nop

L_80071D94:
    // 0x80071D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071D9C: jr          $ra
    // 0x80071DA0: nop

    return;
    // 0x80071DA0: nop

;}
RECOMP_FUNC void func_80071DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071DAC: jal         0x80061348
    // 0x80071DB0: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071DB0: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071DB4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071DB8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071DBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071DC0: beq         $v0, $zero, L_80071DF8
    if (ctx->r2 == 0) {
        // 0x80071DC4: nop

            goto L_80071DF8;
    }
    // 0x80071DC4: nop

    // 0x80071DC8: jal         0x80061348
    // 0x80071DCC: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071DCC: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071DD0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071DD4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071DD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071DDC: beq         $v0, $zero, L_80071DF8
    if (ctx->r2 == 0) {
        // 0x80071DE0: nop

            goto L_80071DF8;
    }
    // 0x80071DE0: nop

    // 0x80071DE4: jal         0x80061348
    // 0x80071DE8: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071DE8: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071DEC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071DF0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071DF4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071DF8:
    // 0x80071DF8: b           L_80071E08
    // 0x80071DFC: nop

        goto L_80071E08;
    // 0x80071DFC: nop

    // 0x80071E00: b           L_80071E08
    // 0x80071E04: nop

        goto L_80071E08;
    // 0x80071E04: nop

L_80071E08:
    // 0x80071E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071E10: jr          $ra
    // 0x80071E14: nop

    return;
    // 0x80071E14: nop

;}
RECOMP_FUNC void func_80071E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071E20: jal         0x80061348
    // 0x80071E24: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071E24: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071E28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071E2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071E30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071E34: beq         $v0, $zero, L_80071E6C
    if (ctx->r2 == 0) {
        // 0x80071E38: nop

            goto L_80071E6C;
    }
    // 0x80071E38: nop

    // 0x80071E3C: jal         0x80061348
    // 0x80071E40: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071E40: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071E44: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071E48: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071E4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071E50: beq         $v0, $zero, L_80071E6C
    if (ctx->r2 == 0) {
        // 0x80071E54: nop

            goto L_80071E6C;
    }
    // 0x80071E54: nop

    // 0x80071E58: jal         0x80061348
    // 0x80071E5C: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071E5C: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071E60: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071E64: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071E68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071E6C:
    // 0x80071E6C: b           L_80071E7C
    // 0x80071E70: nop

        goto L_80071E7C;
    // 0x80071E70: nop

    // 0x80071E74: b           L_80071E7C
    // 0x80071E78: nop

        goto L_80071E7C;
    // 0x80071E78: nop

L_80071E7C:
    // 0x80071E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071E80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071E84: jr          $ra
    // 0x80071E88: nop

    return;
    // 0x80071E88: nop

;}
RECOMP_FUNC void func_80071E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071E8C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071E90: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071E94: nop

    // 0x80071E98: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80071E9C: nop

    // 0x80071EA0: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071EA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071EA8: beq         $v0, $zero, L_80071EC0
    if (ctx->r2 == 0) {
        // 0x80071EAC: nop

            goto L_80071EC0;
    }
    // 0x80071EAC: nop

    // 0x80071EB0: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80071EB4: nop

    // 0x80071EB8: slti        $t8, $v0, 0xC9
    ctx->r24 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071EBC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071EC0:
    // 0x80071EC0: jr          $ra
    // 0x80071EC4: nop

    return;
    // 0x80071EC4: nop

    // 0x80071EC8: jr          $ra
    // 0x80071ECC: nop

    return;
    // 0x80071ECC: nop

    // 0x80071ED0: jr          $ra
    // 0x80071ED4: nop

    return;
    // 0x80071ED4: nop

;}
RECOMP_FUNC void func_80071ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071EE0: jal         0x80061348
    // 0x80071EE4: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071EE4: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    after_0:
    // 0x80071EE8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071EEC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071EF0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071EF4: beq         $v0, $zero, L_80071F10
    if (ctx->r2 == 0) {
        // 0x80071EF8: nop

            goto L_80071F10;
    }
    // 0x80071EF8: nop

    // 0x80071EFC: jal         0x80061348
    // 0x80071F00: addiu       $a0, $zero, 0x447
    ctx->r4 = ADD32(0, 0X447);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071F00: addiu       $a0, $zero, 0x447
    ctx->r4 = ADD32(0, 0X447);
    after_1:
    // 0x80071F04: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071F08: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071F0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071F10:
    // 0x80071F10: b           L_80071F20
    // 0x80071F14: nop

        goto L_80071F20;
    // 0x80071F14: nop

    // 0x80071F18: b           L_80071F20
    // 0x80071F1C: nop

        goto L_80071F20;
    // 0x80071F1C: nop

L_80071F20:
    // 0x80071F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071F28: jr          $ra
    // 0x80071F2C: nop

    return;
    // 0x80071F2C: nop

;}
RECOMP_FUNC void func_80071F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071F30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071F34: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071F38: nop

    // 0x80071F3C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80071F40: nop

    // 0x80071F44: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071F48: jr          $ra
    // 0x80071F4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071F4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071F50: jr          $ra
    // 0x80071F54: nop

    return;
    // 0x80071F54: nop

    // 0x80071F58: jr          $ra
    // 0x80071F5C: nop

    return;
    // 0x80071F5C: nop

;}
RECOMP_FUNC void func_80071F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071F60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071F64: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071F68: nop

    // 0x80071F6C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80071F70: nop

    // 0x80071F74: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071F78: jr          $ra
    // 0x80071F7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071F7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071F80: jr          $ra
    // 0x80071F84: nop

    return;
    // 0x80071F84: nop

    // 0x80071F88: jr          $ra
    // 0x80071F8C: nop

    return;
    // 0x80071F8C: nop

;}
RECOMP_FUNC void func_80071F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071F90: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071F94: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071F98: nop

    // 0x80071F9C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80071FA0: nop

    // 0x80071FA4: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071FA8: jr          $ra
    // 0x80071FAC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071FAC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071FB0: jr          $ra
    // 0x80071FB4: nop

    return;
    // 0x80071FB4: nop

    // 0x80071FB8: jr          $ra
    // 0x80071FBC: nop

    return;
    // 0x80071FBC: nop

;}
RECOMP_FUNC void func_80071FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071FC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071FC4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071FC8: nop

    // 0x80071FCC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80071FD0: nop

    // 0x80071FD4: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071FD8: jr          $ra
    // 0x80071FDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071FDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071FE0: jr          $ra
    // 0x80071FE4: nop

    return;
    // 0x80071FE4: nop

    // 0x80071FE8: jr          $ra
    // 0x80071FEC: nop

    return;
    // 0x80071FEC: nop

;}
RECOMP_FUNC void func_80071FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071FF0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071FF4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071FF8: nop

    // 0x80071FFC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80072000: nop

    // 0x80072004: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80072008: jr          $ra
    // 0x8007200C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007200C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072010: jr          $ra
    // 0x80072014: nop

    return;
    // 0x80072014: nop

    // 0x80072018: jr          $ra
    // 0x8007201C: nop

    return;
    // 0x8007201C: nop

;}
RECOMP_FUNC void func_80072020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072020: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072024: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072028: nop

    // 0x8007202C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072030: nop

    // 0x80072034: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072038: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007203C: jr          $ra
    // 0x80072040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072044: jr          $ra
    // 0x80072048: nop

    return;
    // 0x80072048: nop

    // 0x8007204C: jr          $ra
    // 0x80072050: nop

    return;
    // 0x80072050: nop

;}
RECOMP_FUNC void func_80072054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072058: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007205C: nop

    // 0x80072060: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072064: nop

    // 0x80072068: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007206C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072070: jr          $ra
    // 0x80072074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072078: jr          $ra
    // 0x8007207C: nop

    return;
    // 0x8007207C: nop

    // 0x80072080: jr          $ra
    // 0x80072084: nop

    return;
    // 0x80072084: nop

;}
RECOMP_FUNC void func_80072088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007208C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072090: jal         0x80061348
    // 0x80072094: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80072094: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x80072098: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007209C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800720A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800720A4: beq         $v0, $zero, L_800720DC
    if (ctx->r2 == 0) {
        // 0x800720A8: nop

            goto L_800720DC;
    }
    // 0x800720A8: nop

    // 0x800720AC: jal         0x80061348
    // 0x800720B0: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800720B0: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x800720B4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800720B8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800720BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800720C0: beq         $v0, $zero, L_800720DC
    if (ctx->r2 == 0) {
        // 0x800720C4: nop

            goto L_800720DC;
    }
    // 0x800720C4: nop

    // 0x800720C8: jal         0x80061348
    // 0x800720CC: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800720CC: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x800720D0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800720D4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800720D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800720DC:
    // 0x800720DC: b           L_800720EC
    // 0x800720E0: nop

        goto L_800720EC;
    // 0x800720E0: nop

    // 0x800720E4: b           L_800720EC
    // 0x800720E8: nop

        goto L_800720EC;
    // 0x800720E8: nop

L_800720EC:
    // 0x800720EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800720F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800720F4: jr          $ra
    // 0x800720F8: nop

    return;
    // 0x800720F8: nop

;}
RECOMP_FUNC void func_800720FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800720FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072104: jal         0x80061348
    // 0x80072108: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80072108: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x8007210C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80072110: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072114: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072118: beq         $v0, $zero, L_80072150
    if (ctx->r2 == 0) {
        // 0x8007211C: nop

            goto L_80072150;
    }
    // 0x8007211C: nop

    // 0x80072120: jal         0x80061348
    // 0x80072124: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80072124: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x80072128: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007212C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80072130: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072134: beq         $v0, $zero, L_80072150
    if (ctx->r2 == 0) {
        // 0x80072138: nop

            goto L_80072150;
    }
    // 0x80072138: nop

    // 0x8007213C: jal         0x80061348
    // 0x80072140: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80072140: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x80072144: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80072148: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007214C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80072150:
    // 0x80072150: b           L_80072160
    // 0x80072154: nop

        goto L_80072160;
    // 0x80072154: nop

    // 0x80072158: b           L_80072160
    // 0x8007215C: nop

        goto L_80072160;
    // 0x8007215C: nop

L_80072160:
    // 0x80072160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072168: jr          $ra
    // 0x8007216C: nop

    return;
    // 0x8007216C: nop

;}
RECOMP_FUNC void func_80072170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072178: jal         0x80061348
    // 0x8007217C: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007217C: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x80072180: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80072184: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072188: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007218C: beq         $v0, $zero, L_800721C4
    if (ctx->r2 == 0) {
        // 0x80072190: nop

            goto L_800721C4;
    }
    // 0x80072190: nop

    // 0x80072194: jal         0x80061348
    // 0x80072198: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80072198: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x8007219C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800721A0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800721A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800721A8: beq         $v0, $zero, L_800721C4
    if (ctx->r2 == 0) {
        // 0x800721AC: nop

            goto L_800721C4;
    }
    // 0x800721AC: nop

    // 0x800721B0: jal         0x80061348
    // 0x800721B4: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800721B4: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x800721B8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800721BC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800721C0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800721C4:
    // 0x800721C4: b           L_800721D4
    // 0x800721C8: nop

        goto L_800721D4;
    // 0x800721C8: nop

    // 0x800721CC: b           L_800721D4
    // 0x800721D0: nop

        goto L_800721D4;
    // 0x800721D0: nop

L_800721D4:
    // 0x800721D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800721D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800721DC: jr          $ra
    // 0x800721E0: nop

    return;
    // 0x800721E0: nop

;}
RECOMP_FUNC void func_800721E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800721E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800721E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800721EC: jal         0x80061348
    // 0x800721F0: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800721F0: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x800721F4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800721F8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800721FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072200: beq         $v0, $zero, L_80072238
    if (ctx->r2 == 0) {
        // 0x80072204: nop

            goto L_80072238;
    }
    // 0x80072204: nop

    // 0x80072208: jal         0x80061348
    // 0x8007220C: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007220C: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x80072210: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80072214: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80072218: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007221C: beq         $v0, $zero, L_80072238
    if (ctx->r2 == 0) {
        // 0x80072220: nop

            goto L_80072238;
    }
    // 0x80072220: nop

    // 0x80072224: jal         0x80061348
    // 0x80072228: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80072228: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x8007222C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80072230: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80072234: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80072238:
    // 0x80072238: b           L_80072248
    // 0x8007223C: nop

        goto L_80072248;
    // 0x8007223C: nop

    // 0x80072240: b           L_80072248
    // 0x80072244: nop

        goto L_80072248;
    // 0x80072244: nop

L_80072248:
    // 0x80072248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007224C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072250: jr          $ra
    // 0x80072254: nop

    return;
    // 0x80072254: nop

;}
RECOMP_FUNC void func_80072258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007225C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072260: jal         0x80061348
    // 0x80072264: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80072264: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x80072268: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007226C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072274: beq         $v0, $zero, L_800722AC
    if (ctx->r2 == 0) {
        // 0x80072278: nop

            goto L_800722AC;
    }
    // 0x80072278: nop

    // 0x8007227C: jal         0x80061348
    // 0x80072280: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80072280: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x80072284: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80072288: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007228C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072290: beq         $v0, $zero, L_800722AC
    if (ctx->r2 == 0) {
        // 0x80072294: nop

            goto L_800722AC;
    }
    // 0x80072294: nop

    // 0x80072298: jal         0x80061348
    // 0x8007229C: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007229C: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x800722A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800722A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800722A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800722AC:
    // 0x800722AC: b           L_800722BC
    // 0x800722B0: nop

        goto L_800722BC;
    // 0x800722B0: nop

    // 0x800722B4: b           L_800722BC
    // 0x800722B8: nop

        goto L_800722BC;
    // 0x800722B8: nop

L_800722BC:
    // 0x800722BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800722C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800722C4: jr          $ra
    // 0x800722C8: nop

    return;
    // 0x800722C8: nop

;}
RECOMP_FUNC void func_800722CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800722CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800722D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800722D4: jal         0x80061348
    // 0x800722D8: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800722D8: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x800722DC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800722E0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800722E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800722E8: beq         $v0, $zero, L_80072320
    if (ctx->r2 == 0) {
        // 0x800722EC: nop

            goto L_80072320;
    }
    // 0x800722EC: nop

    // 0x800722F0: jal         0x80061348
    // 0x800722F4: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800722F4: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x800722F8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800722FC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80072300: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072304: beq         $v0, $zero, L_80072320
    if (ctx->r2 == 0) {
        // 0x80072308: nop

            goto L_80072320;
    }
    // 0x80072308: nop

    // 0x8007230C: jal         0x80061348
    // 0x80072310: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80072310: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x80072314: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80072318: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007231C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80072320:
    // 0x80072320: b           L_80072330
    // 0x80072324: nop

        goto L_80072330;
    // 0x80072324: nop

    // 0x80072328: b           L_80072330
    // 0x8007232C: nop

        goto L_80072330;
    // 0x8007232C: nop

L_80072330:
    // 0x80072330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072338: jr          $ra
    // 0x8007233C: nop

    return;
    // 0x8007233C: nop

;}
RECOMP_FUNC void func_80072340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072348: jal         0x80061488
    // 0x8007234C: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007234C: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    after_0:
    // 0x80072350: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80072354: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072358: b           L_80072368
    // 0x8007235C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072368;
    // 0x8007235C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072360: b           L_80072368
    // 0x80072364: nop

        goto L_80072368;
    // 0x80072364: nop

L_80072368:
    // 0x80072368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007236C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072370: jr          $ra
    // 0x80072374: nop

    return;
    // 0x80072374: nop

;}
RECOMP_FUNC void func_80072378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007237C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072380: jal         0x80061488
    // 0x80072384: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072384: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    after_0:
    // 0x80072388: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8007238C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80072390: b           L_800723A0
    // 0x80072394: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800723A0;
    // 0x80072394: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072398: b           L_800723A0
    // 0x8007239C: nop

        goto L_800723A0;
    // 0x8007239C: nop

L_800723A0:
    // 0x800723A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800723A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800723A8: jr          $ra
    // 0x800723AC: nop

    return;
    // 0x800723AC: nop

;}
RECOMP_FUNC void func_800723B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800723B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800723B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800723B8: jal         0x80061488
    // 0x800723BC: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800723BC: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    after_0:
    // 0x800723C0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800723C4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800723C8: b           L_800723D8
    // 0x800723CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800723D8;
    // 0x800723CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800723D0: b           L_800723D8
    // 0x800723D4: nop

        goto L_800723D8;
    // 0x800723D4: nop

L_800723D8:
    // 0x800723D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800723DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800723E0: jr          $ra
    // 0x800723E4: nop

    return;
    // 0x800723E4: nop

;}
RECOMP_FUNC void func_800723E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800723E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800723EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800723F0: jal         0x80061488
    // 0x800723F4: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800723F4: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    after_0:
    // 0x800723F8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800723FC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80072400: b           L_80072410
    // 0x80072404: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072410;
    // 0x80072404: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072408: b           L_80072410
    // 0x8007240C: nop

        goto L_80072410;
    // 0x8007240C: nop

L_80072410:
    // 0x80072410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072418: jr          $ra
    // 0x8007241C: nop

    return;
    // 0x8007241C: nop

;}
RECOMP_FUNC void func_80072420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072420: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072424: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072428: nop

    // 0x8007242C: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072430: nop

    // 0x80072434: slti        $t7, $v0, 0xE6
    ctx->r15 = SIGNED(ctx->r2) < 0XE6 ? 1 : 0;
    // 0x80072438: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007243C: jr          $ra
    // 0x80072440: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072440: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072444: jr          $ra
    // 0x80072448: nop

    return;
    // 0x80072448: nop

    // 0x8007244C: jr          $ra
    // 0x80072450: nop

    return;
    // 0x80072450: nop

;}
RECOMP_FUNC void func_80072454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007245C: jal         0x80061488
    // 0x80072460: addiu       $a0, $zero, 0x51C
    ctx->r4 = ADD32(0, 0X51C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072460: addiu       $a0, $zero, 0x51C
    ctx->r4 = ADD32(0, 0X51C);
    after_0:
    // 0x80072464: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80072468: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007246C: b           L_8007247C
    // 0x80072470: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007247C;
    // 0x80072470: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072474: b           L_8007247C
    // 0x80072478: nop

        goto L_8007247C;
    // 0x80072478: nop

L_8007247C:
    // 0x8007247C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072484: jr          $ra
    // 0x80072488: nop

    return;
    // 0x80072488: nop

;}
RECOMP_FUNC void func_8007248C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007248C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072494: jal         0x80061488
    // 0x80072498: addiu       $a0, $zero, 0x51C
    ctx->r4 = ADD32(0, 0X51C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072498: addiu       $a0, $zero, 0x51C
    ctx->r4 = ADD32(0, 0X51C);
    after_0:
    // 0x8007249C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800724A0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800724A4: b           L_800724B4
    // 0x800724A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800724B4;
    // 0x800724A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800724AC: b           L_800724B4
    // 0x800724B0: nop

        goto L_800724B4;
    // 0x800724B0: nop

L_800724B4:
    // 0x800724B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800724B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800724BC: jr          $ra
    // 0x800724C0: nop

    return;
    // 0x800724C0: nop

;}
RECOMP_FUNC void func_800724C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800724C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800724CC: nop

    // 0x800724D0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800724D4: nop

    // 0x800724D8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800724DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800724E0: jr          $ra
    // 0x800724E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800724E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800724E8: jr          $ra
    // 0x800724EC: nop

    return;
    // 0x800724EC: nop

    // 0x800724F0: jr          $ra
    // 0x800724F4: nop

    return;
    // 0x800724F4: nop

;}
RECOMP_FUNC void func_800724F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800724FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072500: nop

    // 0x80072504: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80072508: nop

    // 0x8007250C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072510: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072514: jr          $ra
    // 0x80072518: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072518: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007251C: jr          $ra
    // 0x80072520: nop

    return;
    // 0x80072520: nop

    // 0x80072524: jr          $ra
    // 0x80072528: nop

    return;
    // 0x80072528: nop

;}
RECOMP_FUNC void func_8007252C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007252C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072530: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072534: nop

    // 0x80072538: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8007253C: nop

    // 0x80072540: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072544: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072548: jr          $ra
    // 0x8007254C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007254C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072550: jr          $ra
    // 0x80072554: nop

    return;
    // 0x80072554: nop

    // 0x80072558: jr          $ra
    // 0x8007255C: nop

    return;
    // 0x8007255C: nop

;}
RECOMP_FUNC void func_80072560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072560: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072564: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072568: nop

    // 0x8007256C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072570: nop

    // 0x80072574: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072578: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007257C: jr          $ra
    // 0x80072580: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072580: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072584: jr          $ra
    // 0x80072588: nop

    return;
    // 0x80072588: nop

    // 0x8007258C: jr          $ra
    // 0x80072590: nop

    return;
    // 0x80072590: nop

;}
RECOMP_FUNC void func_80072594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072594: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072598: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007259C: nop

    // 0x800725A0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800725A4: nop

    // 0x800725A8: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x800725AC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800725B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800725B4: beq         $v0, $zero, L_800725D0
    if (ctx->r2 == 0) {
        // 0x800725B8: nop

            goto L_800725D0;
    }
    // 0x800725B8: nop

    // 0x800725BC: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x800725C0: nop

    // 0x800725C4: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800725C8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800725CC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800725D0:
    // 0x800725D0: jr          $ra
    // 0x800725D4: nop

    return;
    // 0x800725D4: nop

    // 0x800725D8: jr          $ra
    // 0x800725DC: nop

    return;
    // 0x800725DC: nop

    // 0x800725E0: jr          $ra
    // 0x800725E4: nop

    return;
    // 0x800725E4: nop

;}
