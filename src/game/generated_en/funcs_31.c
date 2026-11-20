#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80076308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007630C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076310: jal         0x80061488
    // 0x80076314: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076314: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    after_0:
    // 0x80076318: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8007631C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076320: b           L_80076330
    // 0x80076324: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076330;
    // 0x80076324: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076328: b           L_80076330
    // 0x8007632C: nop

        goto L_80076330;
    // 0x8007632C: nop

L_80076330:
    // 0x80076330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076338: jr          $ra
    // 0x8007633C: nop

    return;
    // 0x8007633C: nop

;}
RECOMP_FUNC void func_80076340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076340: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076344: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076348: nop

    // 0x8007634C: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80076350: nop

    // 0x80076354: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80076358: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007635C: jr          $ra
    // 0x80076360: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076360: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076364: jr          $ra
    // 0x80076368: nop

    return;
    // 0x80076368: nop

    // 0x8007636C: jr          $ra
    // 0x80076370: nop

    return;
    // 0x80076370: nop

;}
RECOMP_FUNC void func_80076374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076374: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076378: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007637C: nop

    // 0x80076380: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076384: nop

    // 0x80076388: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007638C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076390: jr          $ra
    // 0x80076394: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076394: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076398: jr          $ra
    // 0x8007639C: nop

    return;
    // 0x8007639C: nop

    // 0x800763A0: jr          $ra
    // 0x800763A4: nop

    return;
    // 0x800763A4: nop

;}
RECOMP_FUNC void func_800763A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800763AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800763B0: nop

    // 0x800763B4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800763B8: nop

    // 0x800763BC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800763C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800763C4: jr          $ra
    // 0x800763C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800763C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800763CC: jr          $ra
    // 0x800763D0: nop

    return;
    // 0x800763D0: nop

    // 0x800763D4: jr          $ra
    // 0x800763D8: nop

    return;
    // 0x800763D8: nop

;}
RECOMP_FUNC void func_800763DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800763E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800763E4: nop

    // 0x800763E8: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800763EC: nop

    // 0x800763F0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800763F4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800763F8: jr          $ra
    // 0x800763FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800763FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076400: jr          $ra
    // 0x80076404: nop

    return;
    // 0x80076404: nop

    // 0x80076408: jr          $ra
    // 0x8007640C: nop

    return;
    // 0x8007640C: nop

;}
RECOMP_FUNC void func_80076410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076410: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076414: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076418: nop

    // 0x8007641C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80076420: nop

    // 0x80076424: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076428: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007642C: jr          $ra
    // 0x80076430: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076430: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076434: jr          $ra
    // 0x80076438: nop

    return;
    // 0x80076438: nop

    // 0x8007643C: jr          $ra
    // 0x80076440: nop

    return;
    // 0x80076440: nop

;}
RECOMP_FUNC void func_80076444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007644C: jal         0x80061488
    // 0x80076450: addiu       $a0, $zero, 0x515
    ctx->r4 = ADD32(0, 0X515);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076450: addiu       $a0, $zero, 0x515
    ctx->r4 = ADD32(0, 0X515);
    after_0:
    // 0x80076454: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076458: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007645C: b           L_8007646C
    // 0x80076460: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007646C;
    // 0x80076460: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076464: b           L_8007646C
    // 0x80076468: nop

        goto L_8007646C;
    // 0x80076468: nop

L_8007646C:
    // 0x8007646C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076474: jr          $ra
    // 0x80076478: nop

    return;
    // 0x80076478: nop

;}
RECOMP_FUNC void func_8007647C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007647C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076480: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076484: nop

    // 0x80076488: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x8007648C: nop

    // 0x80076490: slti        $t7, $v0, 0xE6
    ctx->r15 = SIGNED(ctx->r2) < 0XE6 ? 1 : 0;
    // 0x80076494: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076498: jr          $ra
    // 0x8007649C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007649C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800764A0: jr          $ra
    // 0x800764A4: nop

    return;
    // 0x800764A4: nop

    // 0x800764A8: jr          $ra
    // 0x800764AC: nop

    return;
    // 0x800764AC: nop

;}
RECOMP_FUNC void func_800764B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800764B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800764B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800764B8: nop

    // 0x800764BC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800764C0: nop

    // 0x800764C4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800764C8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800764CC: jr          $ra
    // 0x800764D0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800764D0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800764D4: jr          $ra
    // 0x800764D8: nop

    return;
    // 0x800764D8: nop

    // 0x800764DC: jr          $ra
    // 0x800764E0: nop

    return;
    // 0x800764E0: nop

;}
RECOMP_FUNC void func_800764E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800764E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800764E8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800764EC: nop

    // 0x800764F0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800764F4: nop

    // 0x800764F8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800764FC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076500: jr          $ra
    // 0x80076504: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076504: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076508: jr          $ra
    // 0x8007650C: nop

    return;
    // 0x8007650C: nop

    // 0x80076510: jr          $ra
    // 0x80076514: nop

    return;
    // 0x80076514: nop

;}
RECOMP_FUNC void func_80076518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076518: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007651C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076520: nop

    // 0x80076524: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80076528: nop

    // 0x8007652C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076530: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076534: jr          $ra
    // 0x80076538: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076538: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007653C: jr          $ra
    // 0x80076540: nop

    return;
    // 0x80076540: nop

    // 0x80076544: jr          $ra
    // 0x80076548: nop

    return;
    // 0x80076548: nop

;}
RECOMP_FUNC void func_8007654C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007654C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076550: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076554: nop

    // 0x80076558: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8007655C: nop

    // 0x80076560: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076564: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076568: jr          $ra
    // 0x8007656C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007656C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076570: jr          $ra
    // 0x80076574: nop

    return;
    // 0x80076574: nop

    // 0x80076578: jr          $ra
    // 0x8007657C: nop

    return;
    // 0x8007657C: nop

;}
RECOMP_FUNC void func_80076580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076588: jal         0x80061488
    // 0x8007658C: addiu       $a0, $zero, 0x46F
    ctx->r4 = ADD32(0, 0X46F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007658C: addiu       $a0, $zero, 0x46F
    ctx->r4 = ADD32(0, 0X46F);
    after_0:
    // 0x80076590: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076594: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076598: b           L_800765A8
    // 0x8007659C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800765A8;
    // 0x8007659C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800765A0: b           L_800765A8
    // 0x800765A4: nop

        goto L_800765A8;
    // 0x800765A4: nop

L_800765A8:
    // 0x800765A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800765AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800765B0: jr          $ra
    // 0x800765B4: nop

    return;
    // 0x800765B4: nop

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
RECOMP_FUNC void func_800765E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800765E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800765EC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800765F0: nop

    // 0x800765F4: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x800765F8: nop

    // 0x800765FC: slti        $t7, $v0, 0xE6
    ctx->r15 = SIGNED(ctx->r2) < 0XE6 ? 1 : 0;
    // 0x80076600: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076604: jr          $ra
    // 0x80076608: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076608: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007660C: jr          $ra
    // 0x80076610: nop

    return;
    // 0x80076610: nop

    // 0x80076614: jr          $ra
    // 0x80076618: nop

    return;
    // 0x80076618: nop

;}
RECOMP_FUNC void func_8007661C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007661C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076620: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076624: nop

    // 0x80076628: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8007662C: nop

    // 0x80076630: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076634: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076638: jr          $ra
    // 0x8007663C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007663C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076640: jr          $ra
    // 0x80076644: nop

    return;
    // 0x80076644: nop

    // 0x80076648: jr          $ra
    // 0x8007664C: nop

    return;
    // 0x8007664C: nop

;}
RECOMP_FUNC void func_80076650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076650: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076654: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076658: nop

    // 0x8007665C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076660: nop

    // 0x80076664: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076668: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007666C: jr          $ra
    // 0x80076670: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076670: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076674: jr          $ra
    // 0x80076678: nop

    return;
    // 0x80076678: nop

    // 0x8007667C: jr          $ra
    // 0x80076680: nop

    return;
    // 0x80076680: nop

;}
RECOMP_FUNC void func_80076684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076684: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076688: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007668C: nop

    // 0x80076690: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80076694: nop

    // 0x80076698: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007669C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800766A0: jr          $ra
    // 0x800766A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800766A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800766A8: jr          $ra
    // 0x800766AC: nop

    return;
    // 0x800766AC: nop

    // 0x800766B0: jr          $ra
    // 0x800766B4: nop

    return;
    // 0x800766B4: nop

;}
RECOMP_FUNC void func_800766B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800766B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800766BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800766C0: nop

    // 0x800766C4: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800766C8: nop

    // 0x800766CC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800766D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800766D4: jr          $ra
    // 0x800766D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800766D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800766DC: jr          $ra
    // 0x800766E0: nop

    return;
    // 0x800766E0: nop

    // 0x800766E4: jr          $ra
    // 0x800766E8: nop

    return;
    // 0x800766E8: nop

;}
RECOMP_FUNC void func_800766EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800766EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800766F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800766F4: jal         0x80061348
    // 0x800766F8: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800766F8: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x800766FC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076700: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076704: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076708: beq         $v0, $zero, L_80076740
    if (ctx->r2 == 0) {
        // 0x8007670C: nop

            goto L_80076740;
    }
    // 0x8007670C: nop

    // 0x80076710: jal         0x80061348
    // 0x80076714: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076714: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x80076718: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007671C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076720: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076724: beq         $v0, $zero, L_80076740
    if (ctx->r2 == 0) {
        // 0x80076728: nop

            goto L_80076740;
    }
    // 0x80076728: nop

    // 0x8007672C: jal         0x80061348
    // 0x80076730: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076730: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x80076734: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80076738: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007673C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80076740:
    // 0x80076740: b           L_80076750
    // 0x80076744: nop

        goto L_80076750;
    // 0x80076744: nop

    // 0x80076748: b           L_80076750
    // 0x8007674C: nop

        goto L_80076750;
    // 0x8007674C: nop

L_80076750:
    // 0x80076750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076758: jr          $ra
    // 0x8007675C: nop

    return;
    // 0x8007675C: nop

;}
RECOMP_FUNC void func_80076760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076768: jal         0x80061348
    // 0x8007676C: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007676C: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x80076770: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076774: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076778: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007677C: beq         $v0, $zero, L_800767B4
    if (ctx->r2 == 0) {
        // 0x80076780: nop

            goto L_800767B4;
    }
    // 0x80076780: nop

    // 0x80076784: jal         0x80061348
    // 0x80076788: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076788: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x8007678C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80076790: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076794: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076798: beq         $v0, $zero, L_800767B4
    if (ctx->r2 == 0) {
        // 0x8007679C: nop

            goto L_800767B4;
    }
    // 0x8007679C: nop

    // 0x800767A0: jal         0x80061348
    // 0x800767A4: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800767A4: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x800767A8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800767AC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800767B0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800767B4:
    // 0x800767B4: b           L_800767C4
    // 0x800767B8: nop

        goto L_800767C4;
    // 0x800767B8: nop

    // 0x800767BC: b           L_800767C4
    // 0x800767C0: nop

        goto L_800767C4;
    // 0x800767C0: nop

L_800767C4:
    // 0x800767C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800767C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800767CC: jr          $ra
    // 0x800767D0: nop

    return;
    // 0x800767D0: nop

;}
RECOMP_FUNC void func_800767D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800767D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800767D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800767DC: nop

    // 0x800767E0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800767E4: nop

    // 0x800767E8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800767EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800767F0: jr          $ra
    // 0x800767F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800767F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800767F8: jr          $ra
    // 0x800767FC: nop

    return;
    // 0x800767FC: nop

    // 0x80076800: jr          $ra
    // 0x80076804: nop

    return;
    // 0x80076804: nop

;}
RECOMP_FUNC void func_80076808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076808: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007680C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076810: nop

    // 0x80076814: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076818: nop

    // 0x8007681C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076820: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076824: jr          $ra
    // 0x80076828: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076828: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007682C: jr          $ra
    // 0x80076830: nop

    return;
    // 0x80076830: nop

    // 0x80076834: jr          $ra
    // 0x80076838: nop

    return;
    // 0x80076838: nop

;}
RECOMP_FUNC void func_8007683C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007683C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076844: jal         0x80061348
    // 0x80076848: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076848: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x8007684C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076850: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076854: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076858: beq         $v0, $zero, L_80076890
    if (ctx->r2 == 0) {
        // 0x8007685C: nop

            goto L_80076890;
    }
    // 0x8007685C: nop

    // 0x80076860: jal         0x80061348
    // 0x80076864: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076864: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x80076868: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007686C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076870: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076874: beq         $v0, $zero, L_80076890
    if (ctx->r2 == 0) {
        // 0x80076878: nop

            goto L_80076890;
    }
    // 0x80076878: nop

    // 0x8007687C: jal         0x80061348
    // 0x80076880: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076880: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x80076884: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80076888: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007688C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80076890:
    // 0x80076890: b           L_800768A0
    // 0x80076894: nop

        goto L_800768A0;
    // 0x80076894: nop

    // 0x80076898: b           L_800768A0
    // 0x8007689C: nop

        goto L_800768A0;
    // 0x8007689C: nop

L_800768A0:
    // 0x800768A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800768A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800768A8: jr          $ra
    // 0x800768AC: nop

    return;
    // 0x800768AC: nop

;}
RECOMP_FUNC void func_800768B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800768B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800768B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800768B8: jal         0x80061348
    // 0x800768BC: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800768BC: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x800768C0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800768C4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800768C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800768CC: beq         $v0, $zero, L_80076904
    if (ctx->r2 == 0) {
        // 0x800768D0: nop

            goto L_80076904;
    }
    // 0x800768D0: nop

    // 0x800768D4: jal         0x80061348
    // 0x800768D8: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800768D8: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x800768DC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800768E0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800768E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800768E8: beq         $v0, $zero, L_80076904
    if (ctx->r2 == 0) {
        // 0x800768EC: nop

            goto L_80076904;
    }
    // 0x800768EC: nop

    // 0x800768F0: jal         0x80061348
    // 0x800768F4: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800768F4: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x800768F8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800768FC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80076900: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80076904:
    // 0x80076904: b           L_80076914
    // 0x80076908: nop

        goto L_80076914;
    // 0x80076908: nop

    // 0x8007690C: b           L_80076914
    // 0x80076910: nop

        goto L_80076914;
    // 0x80076910: nop

L_80076914:
    // 0x80076914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007691C: jr          $ra
    // 0x80076920: nop

    return;
    // 0x80076920: nop

;}
RECOMP_FUNC void func_80076924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007692C: jal         0x80061348
    // 0x80076930: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076930: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x80076934: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076938: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007693C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076940: beq         $v0, $zero, L_80076978
    if (ctx->r2 == 0) {
        // 0x80076944: nop

            goto L_80076978;
    }
    // 0x80076944: nop

    // 0x80076948: jal         0x80061348
    // 0x8007694C: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007694C: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x80076950: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80076954: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007695C: beq         $v0, $zero, L_80076978
    if (ctx->r2 == 0) {
        // 0x80076960: nop

            goto L_80076978;
    }
    // 0x80076960: nop

    // 0x80076964: jal         0x80061348
    // 0x80076968: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076968: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x8007696C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80076970: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80076974: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80076978:
    // 0x80076978: b           L_80076988
    // 0x8007697C: nop

        goto L_80076988;
    // 0x8007697C: nop

    // 0x80076980: b           L_80076988
    // 0x80076984: nop

        goto L_80076988;
    // 0x80076984: nop

L_80076988:
    // 0x80076988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007698C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076990: jr          $ra
    // 0x80076994: nop

    return;
    // 0x80076994: nop

;}
RECOMP_FUNC void func_80076998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007699C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800769A0: jal         0x80061348
    // 0x800769A4: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800769A4: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x800769A8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800769AC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800769B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800769B4: beq         $v0, $zero, L_800769EC
    if (ctx->r2 == 0) {
        // 0x800769B8: nop

            goto L_800769EC;
    }
    // 0x800769B8: nop

    // 0x800769BC: jal         0x80061348
    // 0x800769C0: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800769C0: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x800769C4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800769C8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800769CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800769D0: beq         $v0, $zero, L_800769EC
    if (ctx->r2 == 0) {
        // 0x800769D4: nop

            goto L_800769EC;
    }
    // 0x800769D4: nop

    // 0x800769D8: jal         0x80061348
    // 0x800769DC: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800769DC: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x800769E0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800769E4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800769E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800769EC:
    // 0x800769EC: b           L_800769FC
    // 0x800769F0: nop

        goto L_800769FC;
    // 0x800769F0: nop

    // 0x800769F4: b           L_800769FC
    // 0x800769F8: nop

        goto L_800769FC;
    // 0x800769F8: nop

L_800769FC:
    // 0x800769FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076A04: jr          $ra
    // 0x80076A08: nop

    return;
    // 0x80076A08: nop

;}
RECOMP_FUNC void func_80076A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076A0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076A10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076A14: nop

    // 0x80076A18: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076A1C: nop

    // 0x80076A20: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076A24: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076A28: jr          $ra
    // 0x80076A2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076A2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076A30: jr          $ra
    // 0x80076A34: nop

    return;
    // 0x80076A34: nop

    // 0x80076A38: jr          $ra
    // 0x80076A3C: nop

    return;
    // 0x80076A3C: nop

;}
RECOMP_FUNC void func_80076A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076A40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076A44: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076A48: nop

    // 0x80076A4C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076A50: nop

    // 0x80076A54: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076A58: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076A5C: jr          $ra
    // 0x80076A60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076A60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076A64: jr          $ra
    // 0x80076A68: nop

    return;
    // 0x80076A68: nop

    // 0x80076A6C: jr          $ra
    // 0x80076A70: nop

    return;
    // 0x80076A70: nop

;}
RECOMP_FUNC void func_80076A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076A74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076A78: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076A7C: nop

    // 0x80076A80: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076A84: nop

    // 0x80076A88: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076A8C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076A90: jr          $ra
    // 0x80076A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076A98: jr          $ra
    // 0x80076A9C: nop

    return;
    // 0x80076A9C: nop

    // 0x80076AA0: jr          $ra
    // 0x80076AA4: nop

    return;
    // 0x80076AA4: nop

;}
RECOMP_FUNC void func_80076AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076AA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076AAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076AB0: nop

    // 0x80076AB4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076AB8: nop

    // 0x80076ABC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076AC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076AC4: jr          $ra
    // 0x80076AC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076AC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076ACC: jr          $ra
    // 0x80076AD0: nop

    return;
    // 0x80076AD0: nop

    // 0x80076AD4: jr          $ra
    // 0x80076AD8: nop

    return;
    // 0x80076AD8: nop

;}
RECOMP_FUNC void func_80076ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076AE4: jal         0x80061488
    // 0x80076AE8: addiu       $a0, $zero, 0x477
    ctx->r4 = ADD32(0, 0X477);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076AE8: addiu       $a0, $zero, 0x477
    ctx->r4 = ADD32(0, 0X477);
    after_0:
    // 0x80076AEC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076AF0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076AF4: b           L_80076B04
    // 0x80076AF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076B04;
    // 0x80076AF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076AFC: b           L_80076B04
    // 0x80076B00: nop

        goto L_80076B04;
    // 0x80076B00: nop

L_80076B04:
    // 0x80076B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076B0C: jr          $ra
    // 0x80076B10: nop

    return;
    // 0x80076B10: nop

;}
RECOMP_FUNC void func_80076B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076B18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076B1C: nop

    // 0x80076B20: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076B24: nop

    // 0x80076B28: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076B2C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076B30: jr          $ra
    // 0x80076B34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076B34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076B38: jr          $ra
    // 0x80076B3C: nop

    return;
    // 0x80076B3C: nop

    // 0x80076B40: jr          $ra
    // 0x80076B44: nop

    return;
    // 0x80076B44: nop

;}
RECOMP_FUNC void func_80076B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076B4C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076B50: nop

    // 0x80076B54: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076B58: nop

    // 0x80076B5C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076B60: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076B64: jr          $ra
    // 0x80076B68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076B68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076B6C: jr          $ra
    // 0x80076B70: nop

    return;
    // 0x80076B70: nop

    // 0x80076B74: jr          $ra
    // 0x80076B78: nop

    return;
    // 0x80076B78: nop

;}
RECOMP_FUNC void func_80076B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076B84: jal         0x80061488
    // 0x80076B88: addiu       $a0, $zero, 0x4F7
    ctx->r4 = ADD32(0, 0X4F7);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076B88: addiu       $a0, $zero, 0x4F7
    ctx->r4 = ADD32(0, 0X4F7);
    after_0:
    // 0x80076B8C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076B90: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076B94: b           L_80076BA4
    // 0x80076B98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076BA4;
    // 0x80076B98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076B9C: b           L_80076BA4
    // 0x80076BA0: nop

        goto L_80076BA4;
    // 0x80076BA0: nop

L_80076BA4:
    // 0x80076BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076BAC: jr          $ra
    // 0x80076BB0: nop

    return;
    // 0x80076BB0: nop

;}
RECOMP_FUNC void func_80076BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076BB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076BB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076BBC: nop

    // 0x80076BC0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076BC4: nop

    // 0x80076BC8: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80076BCC: jr          $ra
    // 0x80076BD0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076BD0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076BD4: jr          $ra
    // 0x80076BD8: nop

    return;
    // 0x80076BD8: nop

    // 0x80076BDC: jr          $ra
    // 0x80076BE0: nop

    return;
    // 0x80076BE0: nop

;}
RECOMP_FUNC void func_80076BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076BE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076BE8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076BEC: nop

    // 0x80076BF0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076BF4: nop

    // 0x80076BF8: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80076BFC: jr          $ra
    // 0x80076C00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076C00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076C04: jr          $ra
    // 0x80076C08: nop

    return;
    // 0x80076C08: nop

    // 0x80076C0C: jr          $ra
    // 0x80076C10: nop

    return;
    // 0x80076C10: nop

;}
RECOMP_FUNC void func_80076C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076C18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076C1C: nop

    // 0x80076C20: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076C24: nop

    // 0x80076C28: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80076C2C: jr          $ra
    // 0x80076C30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076C30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076C34: jr          $ra
    // 0x80076C38: nop

    return;
    // 0x80076C38: nop

    // 0x80076C3C: jr          $ra
    // 0x80076C40: nop

    return;
    // 0x80076C40: nop

;}
RECOMP_FUNC void func_80076C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C44: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076C48: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076C4C: nop

    // 0x80076C50: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076C54: nop

    // 0x80076C58: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80076C5C: jr          $ra
    // 0x80076C60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076C60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076C64: jr          $ra
    // 0x80076C68: nop

    return;
    // 0x80076C68: nop

    // 0x80076C6C: jr          $ra
    // 0x80076C70: nop

    return;
    // 0x80076C70: nop

;}
RECOMP_FUNC void func_80076C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076C78: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076C7C: nop

    // 0x80076C80: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80076C84: nop

    // 0x80076C88: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80076C8C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076C90: jr          $ra
    // 0x80076C94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076C94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076C98: jr          $ra
    // 0x80076C9C: nop

    return;
    // 0x80076C9C: nop

    // 0x80076CA0: jr          $ra
    // 0x80076CA4: nop

    return;
    // 0x80076CA4: nop

;}
RECOMP_FUNC void func_80076CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076CA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076CAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076CB0: nop

    // 0x80076CB4: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80076CB8: nop

    // 0x80076CBC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80076CC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076CC4: jr          $ra
    // 0x80076CC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076CC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076CCC: jr          $ra
    // 0x80076CD0: nop

    return;
    // 0x80076CD0: nop

    // 0x80076CD4: jr          $ra
    // 0x80076CD8: nop

    return;
    // 0x80076CD8: nop

;}
RECOMP_FUNC void func_80076CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076CE4: jal         0x80061488
    // 0x80076CE8: addiu       $a0, $zero, 0x551
    ctx->r4 = ADD32(0, 0X551);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076CE8: addiu       $a0, $zero, 0x551
    ctx->r4 = ADD32(0, 0X551);
    after_0:
    // 0x80076CEC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076CF0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076CF4: b           L_80076D04
    // 0x80076CF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076D04;
    // 0x80076CF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076CFC: b           L_80076D04
    // 0x80076D00: nop

        goto L_80076D04;
    // 0x80076D00: nop

L_80076D04:
    // 0x80076D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076D0C: jr          $ra
    // 0x80076D10: nop

    return;
    // 0x80076D10: nop

;}
RECOMP_FUNC void func_80076D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076D1C: jal         0x80061488
    // 0x80076D20: addiu       $a0, $zero, 0x54C
    ctx->r4 = ADD32(0, 0X54C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076D20: addiu       $a0, $zero, 0x54C
    ctx->r4 = ADD32(0, 0X54C);
    after_0:
    // 0x80076D24: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076D28: b           L_80076D38
    // 0x80076D2C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076D38;
    // 0x80076D2C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076D30: b           L_80076D38
    // 0x80076D34: nop

        goto L_80076D38;
    // 0x80076D34: nop

L_80076D38:
    // 0x80076D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076D40: jr          $ra
    // 0x80076D44: nop

    return;
    // 0x80076D44: nop

;}
RECOMP_FUNC void func_80076D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076D50: jal         0x80061348
    // 0x80076D54: addiu       $a0, $zero, 0x552
    ctx->r4 = ADD32(0, 0X552);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076D54: addiu       $a0, $zero, 0x552
    ctx->r4 = ADD32(0, 0X552);
    after_0:
    // 0x80076D58: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076D5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076D60: b           L_80076D70
    // 0x80076D64: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80076D70;
    // 0x80076D64: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076D68: b           L_80076D70
    // 0x80076D6C: nop

        goto L_80076D70;
    // 0x80076D6C: nop

L_80076D70:
    // 0x80076D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076D78: jr          $ra
    // 0x80076D7C: nop

    return;
    // 0x80076D7C: nop

;}
RECOMP_FUNC void func_80076D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076D88: jal         0x80061348
    // 0x80076D8C: addiu       $a0, $zero, 0x553
    ctx->r4 = ADD32(0, 0X553);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076D8C: addiu       $a0, $zero, 0x553
    ctx->r4 = ADD32(0, 0X553);
    after_0:
    // 0x80076D90: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076D94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076D98: b           L_80076DA8
    // 0x80076D9C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80076DA8;
    // 0x80076D9C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076DA0: b           L_80076DA8
    // 0x80076DA4: nop

        goto L_80076DA8;
    // 0x80076DA4: nop

L_80076DA8:
    // 0x80076DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076DB0: jr          $ra
    // 0x80076DB4: nop

    return;
    // 0x80076DB4: nop

;}
RECOMP_FUNC void func_80076DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076DB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076DC0: jal         0x80061488
    // 0x80076DC4: addiu       $a0, $zero, 0x54F
    ctx->r4 = ADD32(0, 0X54F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076DC4: addiu       $a0, $zero, 0x54F
    ctx->r4 = ADD32(0, 0X54F);
    after_0:
    // 0x80076DC8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076DCC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076DD0: b           L_80076DE0
    // 0x80076DD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076DE0;
    // 0x80076DD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076DD8: b           L_80076DE0
    // 0x80076DDC: nop

        goto L_80076DE0;
    // 0x80076DDC: nop

L_80076DE0:
    // 0x80076DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076DE8: jr          $ra
    // 0x80076DEC: nop

    return;
    // 0x80076DEC: nop

;}
RECOMP_FUNC void func_80076DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076DF8: jal         0x80061348
    // 0x80076DFC: addiu       $a0, $zero, 0x43F
    ctx->r4 = ADD32(0, 0X43F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076DFC: addiu       $a0, $zero, 0x43F
    ctx->r4 = ADD32(0, 0X43F);
    after_0:
    // 0x80076E00: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076E04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076E08: beq         $v0, $zero, L_80076E20
    if (ctx->r2 == 0) {
        // 0x80076E0C: nop

            goto L_80076E20;
    }
    // 0x80076E0C: nop

    // 0x80076E10: jal         0x8005F064
    // 0x80076E14: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80076E14: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_1:
    // 0x80076E18: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80076E1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80076E20:
    // 0x80076E20: b           L_80076E30
    // 0x80076E24: nop

        goto L_80076E30;
    // 0x80076E24: nop

    // 0x80076E28: b           L_80076E30
    // 0x80076E2C: nop

        goto L_80076E30;
    // 0x80076E2C: nop

L_80076E30:
    // 0x80076E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076E38: jr          $ra
    // 0x80076E3C: nop

    return;
    // 0x80076E3C: nop

;}
RECOMP_FUNC void func_80076E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076E48: jal         0x80061488
    // 0x80076E4C: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076E4C: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076E50: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076E54: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076E58: b           L_80076E68
    // 0x80076E5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076E68;
    // 0x80076E5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076E60: b           L_80076E68
    // 0x80076E64: nop

        goto L_80076E68;
    // 0x80076E64: nop

L_80076E68:
    // 0x80076E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076E6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076E70: jr          $ra
    // 0x80076E74: nop

    return;
    // 0x80076E74: nop

;}
RECOMP_FUNC void func_80076E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076E80: jal         0x80061488
    // 0x80076E84: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076E84: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076E88: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076E8C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076E90: b           L_80076EA0
    // 0x80076E94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076EA0;
    // 0x80076E94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076E98: b           L_80076EA0
    // 0x80076E9C: nop

        goto L_80076EA0;
    // 0x80076E9C: nop

L_80076EA0:
    // 0x80076EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076EA8: jr          $ra
    // 0x80076EAC: nop

    return;
    // 0x80076EAC: nop

;}
RECOMP_FUNC void func_80076EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076EB8: jal         0x80061488
    // 0x80076EBC: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076EBC: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076EC0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076EC4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076EC8: b           L_80076ED8
    // 0x80076ECC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076ED8;
    // 0x80076ECC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076ED0: b           L_80076ED8
    // 0x80076ED4: nop

        goto L_80076ED8;
    // 0x80076ED4: nop

L_80076ED8:
    // 0x80076ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076EDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076EE0: jr          $ra
    // 0x80076EE4: nop

    return;
    // 0x80076EE4: nop

;}
