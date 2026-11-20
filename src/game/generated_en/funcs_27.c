#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800725E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800725E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800725EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800725F0: jal         0x80061488
    // 0x800725F4: addiu       $a0, $zero, 0x50D
    ctx->r4 = ADD32(0, 0X50D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800725F4: addiu       $a0, $zero, 0x50D
    ctx->r4 = ADD32(0, 0X50D);
    after_0:
    // 0x800725F8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800725FC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80072600: b           L_80072610
    // 0x80072604: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072610;
    // 0x80072604: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072608: b           L_80072610
    // 0x8007260C: nop

        goto L_80072610;
    // 0x8007260C: nop

L_80072610:
    // 0x80072610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072618: jr          $ra
    // 0x8007261C: nop

    return;
    // 0x8007261C: nop

;}
RECOMP_FUNC void func_80072620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072620: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072624: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072628: nop

    // 0x8007262C: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072630: nop

    // 0x80072634: slti        $t7, $v0, 0x14A
    ctx->r15 = SIGNED(ctx->r2) < 0X14A ? 1 : 0;
    // 0x80072638: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007263C: jr          $ra
    // 0x80072640: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072640: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072644: jr          $ra
    // 0x80072648: nop

    return;
    // 0x80072648: nop

    // 0x8007264C: jr          $ra
    // 0x80072650: nop

    return;
    // 0x80072650: nop

;}
RECOMP_FUNC void func_80072654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007265C: jal         0x80061488
    // 0x80072660: addiu       $a0, $zero, 0x519
    ctx->r4 = ADD32(0, 0X519);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072660: addiu       $a0, $zero, 0x519
    ctx->r4 = ADD32(0, 0X519);
    after_0:
    // 0x80072664: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80072668: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007266C: b           L_8007267C
    // 0x80072670: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007267C;
    // 0x80072670: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072674: b           L_8007267C
    // 0x80072678: nop

        goto L_8007267C;
    // 0x80072678: nop

L_8007267C:
    // 0x8007267C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072684: jr          $ra
    // 0x80072688: nop

    return;
    // 0x80072688: nop

;}
RECOMP_FUNC void func_8007268C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007268C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072694: jal         0x80061488
    // 0x80072698: addiu       $a0, $zero, 0x519
    ctx->r4 = ADD32(0, 0X519);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072698: addiu       $a0, $zero, 0x519
    ctx->r4 = ADD32(0, 0X519);
    after_0:
    // 0x8007269C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800726A0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800726A4: b           L_800726B4
    // 0x800726A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800726B4;
    // 0x800726A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800726AC: b           L_800726B4
    // 0x800726B0: nop

        goto L_800726B4;
    // 0x800726B0: nop

L_800726B4:
    // 0x800726B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800726B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800726BC: jr          $ra
    // 0x800726C0: nop

    return;
    // 0x800726C0: nop

;}
RECOMP_FUNC void func_800726C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800726C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800726C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800726CC: nop

    // 0x800726D0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800726D4: nop

    // 0x800726D8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800726DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800726E0: jr          $ra
    // 0x800726E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800726E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800726E8: jr          $ra
    // 0x800726EC: nop

    return;
    // 0x800726EC: nop

    // 0x800726F0: jr          $ra
    // 0x800726F4: nop

    return;
    // 0x800726F4: nop

;}
RECOMP_FUNC void func_800726F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800726F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800726FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072700: nop

    // 0x80072704: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072708: nop

    // 0x8007270C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072710: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072714: jr          $ra
    // 0x80072718: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072718: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007271C: jr          $ra
    // 0x80072720: nop

    return;
    // 0x80072720: nop

    // 0x80072724: jr          $ra
    // 0x80072728: nop

    return;
    // 0x80072728: nop

;}
RECOMP_FUNC void func_8007272C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007272C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072730: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072734: nop

    // 0x80072738: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8007273C: nop

    // 0x80072740: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072744: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072748: jr          $ra
    // 0x8007274C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007274C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072750: jr          $ra
    // 0x80072754: nop

    return;
    // 0x80072754: nop

    // 0x80072758: jr          $ra
    // 0x8007275C: nop

    return;
    // 0x8007275C: nop

;}
RECOMP_FUNC void func_80072760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072760: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072764: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072768: nop

    // 0x8007276C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80072770: nop

    // 0x80072774: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072778: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007277C: jr          $ra
    // 0x80072780: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072780: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072784: jr          $ra
    // 0x80072788: nop

    return;
    // 0x80072788: nop

    // 0x8007278C: jr          $ra
    // 0x80072790: nop

    return;
    // 0x80072790: nop

;}
RECOMP_FUNC void func_80072794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007279C: jal         0x80061488
    // 0x800727A0: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800727A0: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    after_0:
    // 0x800727A4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800727A8: b           L_800727B8
    // 0x800727AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800727B8;
    // 0x800727AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800727B0: b           L_800727B8
    // 0x800727B4: nop

        goto L_800727B8;
    // 0x800727B4: nop

L_800727B8:
    // 0x800727B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800727BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800727C0: jr          $ra
    // 0x800727C4: nop

    return;
    // 0x800727C4: nop

;}
RECOMP_FUNC void func_800727C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800727C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800727CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800727D0: jal         0x80061488
    // 0x800727D4: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800727D4: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    after_0:
    // 0x800727D8: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800727DC: b           L_800727EC
    // 0x800727E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800727EC;
    // 0x800727E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800727E4: b           L_800727EC
    // 0x800727E8: nop

        goto L_800727EC;
    // 0x800727E8: nop

L_800727EC:
    // 0x800727EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800727F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800727F4: jr          $ra
    // 0x800727F8: nop

    return;
    // 0x800727F8: nop

;}
RECOMP_FUNC void func_800727FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800727FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072804: jal         0x80061348
    // 0x80072808: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80072808: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    after_0:
    // 0x8007280C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80072810: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072814: b           L_80072824
    // 0x80072818: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072824;
    // 0x80072818: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007281C: b           L_80072824
    // 0x80072820: nop

        goto L_80072824;
    // 0x80072820: nop

L_80072824:
    // 0x80072824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007282C: jr          $ra
    // 0x80072830: nop

    return;
    // 0x80072830: nop

;}
RECOMP_FUNC void func_80072834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072834: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072838: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007283C: nop

    // 0x80072840: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072844: nop

    // 0x80072848: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x8007284C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072850: jr          $ra
    // 0x80072854: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072854: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072858: jr          $ra
    // 0x8007285C: nop

    return;
    // 0x8007285C: nop

    // 0x80072860: jr          $ra
    // 0x80072864: nop

    return;
    // 0x80072864: nop

;}
RECOMP_FUNC void func_80072868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072868: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007286C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072870: nop

    // 0x80072874: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072878: nop

    // 0x8007287C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072880: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072884: jr          $ra
    // 0x80072888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007288C: jr          $ra
    // 0x80072890: nop

    return;
    // 0x80072890: nop

    // 0x80072894: jr          $ra
    // 0x80072898: nop

    return;
    // 0x80072898: nop

;}
RECOMP_FUNC void func_8007289C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007289C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800728A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800728A4: nop

    // 0x800728A8: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x800728AC: nop

    // 0x800728B0: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x800728B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800728B8: jr          $ra
    // 0x800728BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800728BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800728C0: jr          $ra
    // 0x800728C4: nop

    return;
    // 0x800728C4: nop

    // 0x800728C8: jr          $ra
    // 0x800728CC: nop

    return;
    // 0x800728CC: nop

;}
RECOMP_FUNC void func_800728D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800728D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800728D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800728D8: nop

    // 0x800728DC: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800728E0: nop

    // 0x800728E4: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x800728E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800728EC: jr          $ra
    // 0x800728F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800728F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800728F4: jr          $ra
    // 0x800728F8: nop

    return;
    // 0x800728F8: nop

    // 0x800728FC: jr          $ra
    // 0x80072900: nop

    return;
    // 0x80072900: nop

;}
RECOMP_FUNC void func_80072904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072904: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072908: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007290C: nop

    // 0x80072910: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072914: nop

    // 0x80072918: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x8007291C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072920: jr          $ra
    // 0x80072924: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072924: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072928: jr          $ra
    // 0x8007292C: nop

    return;
    // 0x8007292C: nop

    // 0x80072930: jr          $ra
    // 0x80072934: nop

    return;
    // 0x80072934: nop

;}
RECOMP_FUNC void func_80072938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072938: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007293C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072940: nop

    // 0x80072944: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072948: nop

    // 0x8007294C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80072950: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072954: jr          $ra
    // 0x80072958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007295C: jr          $ra
    // 0x80072960: nop

    return;
    // 0x80072960: nop

    // 0x80072964: jr          $ra
    // 0x80072968: nop

    return;
    // 0x80072968: nop

;}
RECOMP_FUNC void func_8007296C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007296C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072970: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072974: nop

    // 0x80072978: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x8007297C: nop

    // 0x80072980: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072984: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072988: jr          $ra
    // 0x8007298C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007298C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072990: jr          $ra
    // 0x80072994: nop

    return;
    // 0x80072994: nop

    // 0x80072998: jr          $ra
    // 0x8007299C: nop

    return;
    // 0x8007299C: nop

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
RECOMP_FUNC void func_800729D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800729D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800729D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800729DC: jal         0x80061488
    // 0x800729E0: addiu       $a0, $zero, 0x523
    ctx->r4 = ADD32(0, 0X523);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800729E0: addiu       $a0, $zero, 0x523
    ctx->r4 = ADD32(0, 0X523);
    after_0:
    // 0x800729E4: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800729E8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800729EC: b           L_800729FC
    // 0x800729F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800729FC;
    // 0x800729F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800729F4: b           L_800729FC
    // 0x800729F8: nop

        goto L_800729FC;
    // 0x800729F8: nop

L_800729FC:
    // 0x800729FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072A04: jr          $ra
    // 0x80072A08: nop

    return;
    // 0x80072A08: nop

;}
RECOMP_FUNC void func_80072A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072A0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072A10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072A14: nop

    // 0x80072A18: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072A1C: nop

    // 0x80072A20: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072A24: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072A28: jr          $ra
    // 0x80072A2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072A2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072A30: jr          $ra
    // 0x80072A34: nop

    return;
    // 0x80072A34: nop

    // 0x80072A38: jr          $ra
    // 0x80072A3C: nop

    return;
    // 0x80072A3C: nop

;}
RECOMP_FUNC void func_80072A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072A40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072A44: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072A48: nop

    // 0x80072A4C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072A50: nop

    // 0x80072A54: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072A58: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072A5C: jr          $ra
    // 0x80072A60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072A60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072A64: jr          $ra
    // 0x80072A68: nop

    return;
    // 0x80072A68: nop

    // 0x80072A6C: jr          $ra
    // 0x80072A70: nop

    return;
    // 0x80072A70: nop

;}
RECOMP_FUNC void func_80072A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072A74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072A78: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072A7C: nop

    // 0x80072A80: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072A84: nop

    // 0x80072A88: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072A8C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072A90: jr          $ra
    // 0x80072A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072A98: jr          $ra
    // 0x80072A9C: nop

    return;
    // 0x80072A9C: nop

    // 0x80072AA0: jr          $ra
    // 0x80072AA4: nop

    return;
    // 0x80072AA4: nop

;}
RECOMP_FUNC void func_80072AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072AA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072AAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072AB0: nop

    // 0x80072AB4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072AB8: nop

    // 0x80072ABC: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80072AC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072AC4: jr          $ra
    // 0x80072AC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072AC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072ACC: jr          $ra
    // 0x80072AD0: nop

    return;
    // 0x80072AD0: nop

    // 0x80072AD4: jr          $ra
    // 0x80072AD8: nop

    return;
    // 0x80072AD8: nop

;}
RECOMP_FUNC void func_80072ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072ADC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072AE0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072AE4: nop

    // 0x80072AE8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072AEC: nop

    // 0x80072AF0: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80072AF4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072AF8: jr          $ra
    // 0x80072AFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072AFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072B00: jr          $ra
    // 0x80072B04: nop

    return;
    // 0x80072B04: nop

    // 0x80072B08: jr          $ra
    // 0x80072B0C: nop

    return;
    // 0x80072B0C: nop

;}
RECOMP_FUNC void func_80072B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072B10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072B14: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072B18: nop

    // 0x80072B1C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072B20: nop

    // 0x80072B24: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80072B28: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072B2C: jr          $ra
    // 0x80072B30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072B30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072B34: jr          $ra
    // 0x80072B38: nop

    return;
    // 0x80072B38: nop

    // 0x80072B3C: jr          $ra
    // 0x80072B40: nop

    return;
    // 0x80072B40: nop

;}
RECOMP_FUNC void func_80072B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072B44: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072B48: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072B4C: nop

    // 0x80072B50: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072B54: nop

    // 0x80072B58: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80072B5C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072B60: jr          $ra
    // 0x80072B64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072B64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072B68: jr          $ra
    // 0x80072B6C: nop

    return;
    // 0x80072B6C: nop

    // 0x80072B70: jr          $ra
    // 0x80072B74: nop

    return;
    // 0x80072B74: nop

;}
RECOMP_FUNC void func_80072B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072B78: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072B7C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072B80: nop

    // 0x80072B84: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072B88: nop

    // 0x80072B8C: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x80072B90: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072B94: jr          $ra
    // 0x80072B98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072B98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072B9C: jr          $ra
    // 0x80072BA0: nop

    return;
    // 0x80072BA0: nop

    // 0x80072BA4: jr          $ra
    // 0x80072BA8: nop

    return;
    // 0x80072BA8: nop

;}
RECOMP_FUNC void func_80072BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072BAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072BB0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072BB4: nop

    // 0x80072BB8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072BBC: nop

    // 0x80072BC0: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x80072BC4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072BC8: jr          $ra
    // 0x80072BCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072BCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072BD0: jr          $ra
    // 0x80072BD4: nop

    return;
    // 0x80072BD4: nop

    // 0x80072BD8: jr          $ra
    // 0x80072BDC: nop

    return;
    // 0x80072BDC: nop

;}
RECOMP_FUNC void func_80072BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072BE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072BE4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072BE8: nop

    // 0x80072BEC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072BF0: nop

    // 0x80072BF4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072BF8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072BFC: jr          $ra
    // 0x80072C00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072C00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072C04: jr          $ra
    // 0x80072C08: nop

    return;
    // 0x80072C08: nop

    // 0x80072C0C: jr          $ra
    // 0x80072C10: nop

    return;
    // 0x80072C10: nop

;}
RECOMP_FUNC void func_80072C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072C14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072C18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072C1C: nop

    // 0x80072C20: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072C24: nop

    // 0x80072C28: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072C2C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072C30: jr          $ra
    // 0x80072C34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072C34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072C38: jr          $ra
    // 0x80072C3C: nop

    return;
    // 0x80072C3C: nop

    // 0x80072C40: jr          $ra
    // 0x80072C44: nop

    return;
    // 0x80072C44: nop

;}
RECOMP_FUNC void func_80072C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072C48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072C4C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072C50: nop

    // 0x80072C54: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80072C58: nop

    // 0x80072C5C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072C60: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072C64: jr          $ra
    // 0x80072C68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072C68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072C6C: jr          $ra
    // 0x80072C70: nop

    return;
    // 0x80072C70: nop

    // 0x80072C74: jr          $ra
    // 0x80072C78: nop

    return;
    // 0x80072C78: nop

;}
RECOMP_FUNC void func_80072C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072C7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072C80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072C84: nop

    // 0x80072C88: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80072C8C: nop

    // 0x80072C90: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072C94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072C98: jr          $ra
    // 0x80072C9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072C9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072CA0: jr          $ra
    // 0x80072CA4: nop

    return;
    // 0x80072CA4: nop

    // 0x80072CA8: jr          $ra
    // 0x80072CAC: nop

    return;
    // 0x80072CAC: nop

;}
RECOMP_FUNC void func_80072CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072CB8: jal         0x80061488
    // 0x80072CBC: addiu       $a0, $zero, 0x50F
    ctx->r4 = ADD32(0, 0X50F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072CBC: addiu       $a0, $zero, 0x50F
    ctx->r4 = ADD32(0, 0X50F);
    after_0:
    // 0x80072CC0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80072CC4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80072CC8: b           L_80072CD8
    // 0x80072CCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072CD8;
    // 0x80072CCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072CD0: b           L_80072CD8
    // 0x80072CD4: nop

        goto L_80072CD8;
    // 0x80072CD4: nop

L_80072CD8:
    // 0x80072CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072CE0: jr          $ra
    // 0x80072CE4: nop

    return;
    // 0x80072CE4: nop

;}
RECOMP_FUNC void func_80072CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072CE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072CEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072CF0: nop

    // 0x80072CF4: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072CF8: nop

    // 0x80072CFC: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072D00: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072D04: jr          $ra
    // 0x80072D08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072D08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072D0C: jr          $ra
    // 0x80072D10: nop

    return;
    // 0x80072D10: nop

    // 0x80072D14: jr          $ra
    // 0x80072D18: nop

    return;
    // 0x80072D18: nop

;}
RECOMP_FUNC void func_80072D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072D1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072D20: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072D24: nop

    // 0x80072D28: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072D2C: nop

    // 0x80072D30: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072D34: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072D38: jr          $ra
    // 0x80072D3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072D3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072D40: jr          $ra
    // 0x80072D44: nop

    return;
    // 0x80072D44: nop

    // 0x80072D48: jr          $ra
    // 0x80072D4C: nop

    return;
    // 0x80072D4C: nop

;}
RECOMP_FUNC void func_80072D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072D50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072D54: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072D58: nop

    // 0x80072D5C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072D60: nop

    // 0x80072D64: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072D68: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072D6C: jr          $ra
    // 0x80072D70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072D70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072D74: jr          $ra
    // 0x80072D78: nop

    return;
    // 0x80072D78: nop

    // 0x80072D7C: jr          $ra
    // 0x80072D80: nop

    return;
    // 0x80072D80: nop

;}
RECOMP_FUNC void func_80072D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072D84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072D88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072D8C: nop

    // 0x80072D90: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072D94: nop

    // 0x80072D98: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072D9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072DA0: jr          $ra
    // 0x80072DA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072DA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072DA8: jr          $ra
    // 0x80072DAC: nop

    return;
    // 0x80072DAC: nop

    // 0x80072DB0: jr          $ra
    // 0x80072DB4: nop

    return;
    // 0x80072DB4: nop

;}
RECOMP_FUNC void func_80072DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072DB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072DBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072DC0: nop

    // 0x80072DC4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072DC8: nop

    // 0x80072DCC: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80072DD0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072DD4: jr          $ra
    // 0x80072DD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072DD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072DDC: jr          $ra
    // 0x80072DE0: nop

    return;
    // 0x80072DE0: nop

    // 0x80072DE4: jr          $ra
    // 0x80072DE8: nop

    return;
    // 0x80072DE8: nop

;}
RECOMP_FUNC void func_80072DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072DEC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072DF0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072DF4: nop

    // 0x80072DF8: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072DFC: nop

    // 0x80072E00: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072E04: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072E08: jr          $ra
    // 0x80072E0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072E0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072E10: jr          $ra
    // 0x80072E14: nop

    return;
    // 0x80072E14: nop

    // 0x80072E18: jr          $ra
    // 0x80072E1C: nop

    return;
    // 0x80072E1C: nop

;}
RECOMP_FUNC void func_80072E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072E24: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072E28: nop

    // 0x80072E2C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072E30: nop

    // 0x80072E34: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80072E38: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072E3C: jr          $ra
    // 0x80072E40: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072E40: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072E44: jr          $ra
    // 0x80072E48: nop

    return;
    // 0x80072E48: nop

    // 0x80072E4C: jr          $ra
    // 0x80072E50: nop

    return;
    // 0x80072E50: nop

;}
RECOMP_FUNC void func_80072E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E54: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072E58: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072E5C: nop

    // 0x80072E60: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072E64: nop

    // 0x80072E68: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072E6C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072E70: jr          $ra
    // 0x80072E74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072E74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072E78: jr          $ra
    // 0x80072E7C: nop

    return;
    // 0x80072E7C: nop

    // 0x80072E80: jr          $ra
    // 0x80072E84: nop

    return;
    // 0x80072E84: nop

;}
RECOMP_FUNC void func_80072E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072E8C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072E90: nop

    // 0x80072E94: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072E98: nop

    // 0x80072E9C: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x80072EA0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072EA4: jr          $ra
    // 0x80072EA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072EA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072EAC: jr          $ra
    // 0x80072EB0: nop

    return;
    // 0x80072EB0: nop

    // 0x80072EB4: jr          $ra
    // 0x80072EB8: nop

    return;
    // 0x80072EB8: nop

;}
RECOMP_FUNC void func_80072EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072EBC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072EC0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072EC4: nop

    // 0x80072EC8: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072ECC: nop

    // 0x80072ED0: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072ED4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072ED8: jr          $ra
    // 0x80072EDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072EDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072EE0: jr          $ra
    // 0x80072EE4: nop

    return;
    // 0x80072EE4: nop

    // 0x80072EE8: jr          $ra
    // 0x80072EEC: nop

    return;
    // 0x80072EEC: nop

;}
RECOMP_FUNC void func_80072EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072EF8: jal         0x8005F064
    // 0x80072EFC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80072EFC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x80072F00: b           L_80072F10
    // 0x80072F04: nop

        goto L_80072F10;
    // 0x80072F04: nop

    // 0x80072F08: b           L_80072F10
    // 0x80072F0C: nop

        goto L_80072F10;
    // 0x80072F0C: nop

L_80072F10:
    // 0x80072F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072F18: jr          $ra
    // 0x80072F1C: nop

    return;
    // 0x80072F1C: nop

;}
RECOMP_FUNC void func_80072F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072F28: jal         0x8005F064
    // 0x80072F2C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80072F2C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x80072F30: b           L_80072F40
    // 0x80072F34: nop

        goto L_80072F40;
    // 0x80072F34: nop

    // 0x80072F38: b           L_80072F40
    // 0x80072F3C: nop

        goto L_80072F40;
    // 0x80072F3C: nop

L_80072F40:
    // 0x80072F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072F48: jr          $ra
    // 0x80072F4C: nop

    return;
    // 0x80072F4C: nop

;}
RECOMP_FUNC void func_80072F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072F50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072F54: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072F58: nop

    // 0x80072F5C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072F60: nop

    // 0x80072F64: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072F68: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072F6C: jr          $ra
    // 0x80072F70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072F70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072F74: jr          $ra
    // 0x80072F78: nop

    return;
    // 0x80072F78: nop

    // 0x80072F7C: jr          $ra
    // 0x80072F80: nop

    return;
    // 0x80072F80: nop

;}
RECOMP_FUNC void func_80072F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072F84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072F88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072F8C: nop

    // 0x80072F90: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072F94: nop

    // 0x80072F98: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072F9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072FA0: jr          $ra
    // 0x80072FA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072FA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072FA8: jr          $ra
    // 0x80072FAC: nop

    return;
    // 0x80072FAC: nop

    // 0x80072FB0: jr          $ra
    // 0x80072FB4: nop

    return;
    // 0x80072FB4: nop

;}
RECOMP_FUNC void func_80072FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072FB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072FBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072FC0: nop

    // 0x80072FC4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072FC8: nop

    // 0x80072FCC: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80072FD0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072FD4: jr          $ra
    // 0x80072FD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072FD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072FDC: jr          $ra
    // 0x80072FE0: nop

    return;
    // 0x80072FE0: nop

    // 0x80072FE4: jr          $ra
    // 0x80072FE8: nop

    return;
    // 0x80072FE8: nop

;}
RECOMP_FUNC void func_80072FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072FEC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072FF0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072FF4: nop

    // 0x80072FF8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072FFC: nop

    // 0x80073000: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80073004: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073008: jr          $ra
    // 0x8007300C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007300C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073010: jr          $ra
    // 0x80073014: nop

    return;
    // 0x80073014: nop

    // 0x80073018: jr          $ra
    // 0x8007301C: nop

    return;
    // 0x8007301C: nop

;}
